#include "dummy.h"
#include <stdio.h>
#include <math.h>

void DivPlatformDummy::acquire(short* bufL, short* bufR, size_t start, size_t len) {
  for (size_t i=start; i<start+len; i++) {
    bufL[i]=0;
    for (unsigned char j=0; j<chans; j++) {
      if (chan[j].active) {
        if (!isMuted[j]) bufL[i]+=(((signed short)chan[j].pos)*chan[j].amp*chan[j].vol)>>13;
        chan[j].pos+=chan[j].freq;
      }
    }
  }
}

void DivPlatformDummy::muteChannel(int ch, bool mute) {
  isMuted[ch]=mute;
}

void DivPlatformDummy::tick() {
  for (unsigned char i=0; i<chans; i++) {
    chan[i].amp-=3;
    if (chan[i].amp<16) chan[i].amp=16;

    if (chan[i].freqChanged) {
      chan[i].freqChanged=false;
      chan[i].freq=(chan[i].baseFreq*pow(2,(double)chan[i].pitch/(12.0*128.0)));
    }
  }
}

int DivPlatformDummy::dispatch(DivCommand c) {
  switch (c.cmd) {
    case DIV_CMD_NOTE_ON:
      chan[c.chan].baseFreq=65.6f*pow(2.0f,((float)c.value/12.0f));
      chan[c.chan].freqChanged=true;
      chan[c.chan].active=true;
      chan[c.chan].amp=64;
      break;
    case DIV_CMD_NOTE_OFF:
      chan[c.chan].active=false;
      break;
    case DIV_CMD_VOLUME:
      chan[c.chan].vol=c.value;
      if (chan[c.chan].vol>15) chan[c.chan].vol=15;
      break;
    case DIV_CMD_GET_VOLUME:
      return chan[c.chan].vol;
      break;
    case DIV_CMD_PITCH:
      chan[c.chan].pitch=c.value;
      chan[c.chan].freqChanged=true;
      break;
    case DIV_CMD_LEGATO:
      chan[c.chan].baseFreq=65.6f*pow(2.0f,((float)c.value/12.0f));
      chan[c.chan].freqChanged=true;
      break;
    case DIV_CMD_GET_VOLMAX:
      return 15;
      break;
    default:
      break;
  }
  return 1;
}

void DivPlatformDummy::reset() {
  for (int i=0; i<chans; i++) {
    chan[i]=DivPlatformDummy::Channel();
    chan[i].vol=0x0f;
  }
}

int DivPlatformDummy::init(DivEngine* p, int channels, int sugRate, bool pal) {
  parent=p;
  skipRegisterWrites=false;
  for (int i=0; i<17; i++) {
    isMuted[i]=false;
  }
  rate=65536;
  chans=channels;
  reset();
  return channels;
}

void DivPlatformDummy::quit() {
}

DivPlatformDummy::~DivPlatformDummy() {
}