/**
 * Furnace Tracker - multi-system chiptune tracker
 * Copyright (C) 2021-2022 tildearrow and contributors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "gui.h"
#include "../baseutils.h"
#include <fmt/printf.h>

// add system configurations here.
// every entry is written in the following format:
//   ENTRY(
//     "System Name", {
//      CH(DIV_SYSTEM_???, Volume, Panning, Flags),
//      CH(DIV_SYSTEM_???, Volume, Panning, Flags),
//      ...
//     }
//   );
// flags are a string of new line-separated values.

#define CH FurnaceGUISysDefChip
#define CATEGORY_BEGIN(x,y) cat=FurnaceGUISysCategory(x,y);
#define CATEGORY_END sysCategories.push_back(cat);
#define ENTRY(...) cat.systems.push_back(FurnaceGUISysDef(__VA_ARGS__));

void FurnaceGUI::initSystemPresets() {
  sysCategories.clear();

  FurnaceGUISysCategory cat;

  CATEGORY_BEGIN("Game consoles","let's play some chiptune making games!");
  ENTRY(
    "Sega Genesis", {
      CH(DIV_SYSTEM_YM2612, 64, 0, ""),
      CH(DIV_SYSTEM_SMS, 32, 0, "")
    }
  );
  ENTRY(
    "Sega Genesis (extended channel 3)", {
      CH(DIV_SYSTEM_YM2612_EXT, 64, 0, ""),
      CH(DIV_SYSTEM_SMS, 32, 0, "")
    }
  );
  ENTRY(
    "Sega Genesis (DualPCM)", {
      CH(DIV_SYSTEM_YM2612_FRAC, 64, 0, ""),
      CH(DIV_SYSTEM_SMS, 32, 0, "")
    }
  );
  ENTRY(
    "Sega Genesis (DualPCM, extended channel 3)", {
      CH(DIV_SYSTEM_YM2612_FRAC_EXT, 64, 0, ""),
      CH(DIV_SYSTEM_SMS, 32, 0, "")
    }
  );
  ENTRY(
    "Sega Genesis (with Sega CD)", {
      CH(DIV_SYSTEM_YM2612, 64, 0, ""),
      CH(DIV_SYSTEM_SMS, 32, 0, ""),
      CH(DIV_SYSTEM_RF5C68, 64, 0,
        "clockSel=2\n"
        "chipType=1\n"
      )
    }
  );
  ENTRY(
    "Sega Genesis (extended channel 3 with Sega CD)", {
      CH(DIV_SYSTEM_YM2612_EXT, 64, 0, ""),
      CH(DIV_SYSTEM_SMS, 32, 0, ""),
      CH(DIV_SYSTEM_RF5C68, 64, 0,
        "clockSel=2\n"
        "chipType=1\n"
      )
    }
  );
  ENTRY(
    "Sega Master System", {
      CH(DIV_SYSTEM_SMS, 64, 0, "")
    }
  );
  ENTRY(
    "Sega Master System (with FM expansion)", {
      CH(DIV_SYSTEM_SMS, 64, 0, ""),
      CH(DIV_SYSTEM_OPLL, 64, 0, "")
    }
  );
  ENTRY(
    "Sega Master System (with FM expansion in drums mode)", {
      CH(DIV_SYSTEM_SMS, 64, 0, ""),
      CH(DIV_SYSTEM_OPLL_DRUMS, 64, 0, "")
    }
  );
  ENTRY(
    "Sega Game Gear", {
      CH(DIV_SYSTEM_SMS, 64, 0, "chipType=3")
    }
  );
  ENTRY(
    "Game Boy", {
      CH(DIV_SYSTEM_GB, 64, 0, "")
    }
  );
  ENTRY(
    "NEC PC Engine/TurboGrafx-16", {
      CH(DIV_SYSTEM_PCE, 64, 0, "")
    }
  );
  ENTRY(
    "NES", {
      CH(DIV_SYSTEM_NES, 64, 0, "")
    }
  );
  ENTRY(
    "Famicom with Konami VRC6", {
      CH(DIV_SYSTEM_NES, 64, 0, ""),
      CH(DIV_SYSTEM_VRC6, 64, 0, "")
    }
  );
  ENTRY(
    "Famicom with Konami VRC7", {
      CH(DIV_SYSTEM_NES, 64, 0, ""),
      CH(DIV_SYSTEM_VRC7, 64, 0, "")
    }
  );
  ENTRY(
    "Famicom with MMC5", {
      CH(DIV_SYSTEM_NES, 64, 0, ""),
      CH(DIV_SYSTEM_MMC5, 64, 0, "")
    }
  );
  ENTRY(
    "Famicom with Sunsoft 5B", {
      CH(DIV_SYSTEM_NES, 64, 0, ""),
      CH(DIV_SYSTEM_AY8910, 64, 0, "chipType=2")
    }
  );
  ENTRY(
    "Famicom with Namco 163", {
      CH(DIV_SYSTEM_NES, 64, 0, ""),
      CH(DIV_SYSTEM_N163, 64, 0, "channels=7")
    }
  );
  ENTRY(
    "Famicom Disk System", {
      CH(DIV_SYSTEM_NES, 64, 0, ""),
      CH(DIV_SYSTEM_FDS, 64, 0, "")
    }
  );
  ENTRY(
    "SNES", {
      CH(DIV_SYSTEM_SNES, 64, 0, "")
    }
  );
  ENTRY(
    "Mattel Intellivision", {
      CH(DIV_SYSTEM_AY8910, 64, 0, "chipType=3")
    }
  );
  ENTRY(
    "Vectrex", {
      CH(DIV_SYSTEM_AY8910, 64, 0, "clockSel=4")
    }
  );
  ENTRY(
    "Neo Geo AES", {
      CH(DIV_SYSTEM_YM2610_FULL, 64, 0, "clockSel=1")
    }
  );
  ENTRY(
    "Neo Geo AES (extended channel 2)", {
      CH(DIV_SYSTEM_YM2610_FULL_EXT, 64, 0, "clockSel=1")
    }
  );
  ENTRY(
    "Atari 2600/7800", {
      CH(DIV_SYSTEM_TIA, 64, 0, "")
    }
  );
  ENTRY(
    "Atari Lynx", {
      CH(DIV_SYSTEM_LYNX, 64, 0, "")
    }
  );
  ENTRY(
    "WonderSwan", {
      CH(DIV_SYSTEM_SWAN, 64, 0, "")
    }
  );
  ENTRY(
    "Virtual Boy", {
      CH(DIV_SYSTEM_VBOY, 64, 0, "")
    }
  );
  ENTRY(
    "Gamate", {
      CH(DIV_SYSTEM_AY8910, 64, 0,
        "clockSel=9\n"
        "chipType=0\n"
        "stereo=true\n"
      )
    }
  );
  CATEGORY_END;

  CATEGORY_BEGIN("Computers","let's get to work on chiptune today.");
  ENTRY(
    "Commodore PET", {
      CH(DIV_SYSTEM_PET, 64, 0, "")
    }
  );
  ENTRY(
    "Commodore VIC-20", {
      CH(DIV_SYSTEM_VIC20, 64, 0, "clockSel=1")
    }
  );
  ENTRY(
    "Commodore 64 (6581 SID)", {
      CH(DIV_SYSTEM_C64_6581, 64, 0, "clockSel=1")
    }
  );
  ENTRY(
    "Commodore 64 (8580 SID)", {
      CH(DIV_SYSTEM_C64_8580, 64, 0, "clockSel=1")
    }
  );
  ENTRY(
    "Commodore 64 (6581 SID + Sound Expander)", {
      CH(DIV_SYSTEM_C64_6581, 64, 0, "clockSel=1"),
      CH(DIV_SYSTEM_OPL, 64, 0, "")
    }
  );
  ENTRY(
    "Commodore 64 (6581 SID + Sound Expander in drums mode)", {
      CH(DIV_SYSTEM_C64_6581, 64, 0, "clockSel=1"),
      CH(DIV_SYSTEM_OPL_DRUMS, 64, 0, "")
    }
  );
  ENTRY(
    "Commodore 64 (8580 SID + Sound Expander)", {
      CH(DIV_SYSTEM_C64_8580, 64, 0, "clockSel=1"),
      CH(DIV_SYSTEM_OPL, 64, 0, "")
    }
  );
  ENTRY(
    "Commodore 64 (8580 SID + Sound Expander in drums mode)", {
      CH(DIV_SYSTEM_C64_8580, 64, 0, "clockSel=1"),
      CH(DIV_SYSTEM_OPL_DRUMS, 64, 0, "")
    }
  );
  ENTRY(
    "Commodore 64 (6581 SID + FM-YAM)", {
      CH(DIV_SYSTEM_C64_6581, 64, 0, "clockSel=1"),
      CH(DIV_SYSTEM_OPL2, 64, 0, "")
    }
  );
  ENTRY(
    "Commodore 64 (6581 SID + FM-YAM in drums mode)", {
      CH(DIV_SYSTEM_C64_6581, 64, 0, "clockSel=1"),
      CH(DIV_SYSTEM_OPL2_DRUMS, 64, 0, "")
    }
  );
  ENTRY(
    "Commodore 64 (8580 SID + FM-YAM)", {
      CH(DIV_SYSTEM_C64_8580, 64, 0, "clockSel=1"),
      CH(DIV_SYSTEM_OPL2, 64, 0, "")
    }
  );
  ENTRY(
    "Commodore 64 (8580 SID + FM-YAM in drums mode)", {
      CH(DIV_SYSTEM_C64_8580, 64, 0, "clockSel=1"),
      CH(DIV_SYSTEM_OPL2_DRUMS, 64, 0, "")
    }
  );
  ENTRY(
    "Amiga", {
      CH(DIV_SYSTEM_AMIGA, 64, 0, "")
    }
  );
  ENTRY(
    "MSX", {
      CH(DIV_SYSTEM_AY8910, 64, 0, "chipType=1")
    }
  );
  ENTRY(
    "MSX + SFG-01", {
      CH(DIV_SYSTEM_AY8910, 64, 0, "chipType=1"),
      CH(DIV_SYSTEM_YM2151, 64, 0, "")
    }
  );
  ENTRY(
    "MSX + MSX-AUDIO", {
      CH(DIV_SYSTEM_AY8910, 64, 0, "chipType=1"),
      CH(DIV_SYSTEM_Y8950, 64, 0, "")
    }
  );
  ENTRY(
    "MSX + MSX-AUDIO (drums mode)", {
      CH(DIV_SYSTEM_AY8910, 64, 0, "chipType=1"),
      CH(DIV_SYSTEM_Y8950_DRUMS, 64, 0, "")
    }
  );
  ENTRY(
    "MSX + MSX-MUSIC", {
      CH(DIV_SYSTEM_AY8910, 64, 0, "chipType=1"),
      CH(DIV_SYSTEM_OPLL, 64, 0, "")
    }
  );
  ENTRY(
    "MSX + MSX-MUSIC (drums mode)", {
      CH(DIV_SYSTEM_AY8910, 64, 0, "chipType=1"),
      CH(DIV_SYSTEM_OPLL_DRUMS, 64, 0, "")
    }
  );
  ENTRY(
    "MSX + Darky", {
      CH(DIV_SYSTEM_AY8910, 64, 0, "chipType=1"),
      CH(DIV_SYSTEM_AY8930, 64, 0,
        "clockSel=11\n"
        "halfClock=true\n"
      ), // 3.58MHz
      CH(DIV_SYSTEM_AY8930, 64, 0,
        "clockSel=11\n"
        "halfClock=true\n"
      ) // 3.58MHz or 3.6MHz selectable via register
      // per-channel mixer (soft panning, post processing) isn't emulated at all
    }
  );
    ENTRY(
    "MSX + Playsoniq", {
      CH(DIV_SYSTEM_AY8910, 64, 0, "chipType=1"),
      CH(DIV_SYSTEM_SMS, 64, 0, ""), // Sega VDP
      CH(DIV_SYSTEM_C64_8580, 64, 0, ""),
      CH(DIV_SYSTEM_SCC_PLUS, 64, 0, "")
    }
  );
  ENTRY(
    "MSX + SCC", {
      CH(DIV_SYSTEM_AY8910, 64, 0, "chipType=1"),
      CH(DIV_SYSTEM_SCC, 64, 0, "")
    }
  );
  ENTRY(
    "MSX + SCC+", {
      CH(DIV_SYSTEM_AY8910, 64, 0, "chipType=1"),
      CH(DIV_SYSTEM_SCC_PLUS, 64, 0, "")
    }
  );
  ENTRY(
    "MSX + Neotron", {
      CH(DIV_SYSTEM_AY8910, 64, 0, "chipType=1"),
      CH(DIV_SYSTEM_YM2610_FULL, 64, 0, "")
    }
  );
  ENTRY(
    "MSX + Neotron (extended channel 2)", {
      CH(DIV_SYSTEM_AY8910, 64, 0, "chipType=1"),
      CH(DIV_SYSTEM_YM2610_FULL_EXT, 64, 0, "")
    }
  );
  ENTRY(
    "MSX + Neotron (with YM2610B)", {
      CH(DIV_SYSTEM_AY8910, 64, 0, "chipType=1"),
      CH(DIV_SYSTEM_YM2610B, 64, 0, "")
    }
  );
  ENTRY(
    "MSX + Neotron (with YM2610B; extended channel 3)", {
      CH(DIV_SYSTEM_AY8910, 64, 0, "chipType=1"),
      CH(DIV_SYSTEM_YM2610B_EXT, 64, 0, "")
    }
  );
  ENTRY(
    "MSX + SIMPL", {
      CH(DIV_SYSTEM_AY8910, 64, 0, "chipType=1"),
      CH(DIV_SYSTEM_PCM_DAC, 64, 0,
        "rate=55930\n"
        "outDepth=8\n"
      ) // variable rate, Mono DAC
    }
  );
  ENTRY(
    "NEC PC-98 (with PC-9801-26/K)", {
      CH(DIV_SYSTEM_OPN, 64, 0, "clockSel=4"), // 3.9936MHz but some compatible card has 4MHz
      CH(DIV_SYSTEM_PCSPKR, 64, 0, "clockSel=1")
    }
  );
  ENTRY(
    "NEC PC-98 (with PC-9801-26/K; extended channel 3)", {
      CH(DIV_SYSTEM_OPN_EXT, 64, 0, "clockSel=4"), // 3.9936MHz but some compatible card has 4MHz
      CH(DIV_SYSTEM_PCSPKR, 64, 0, "clockSel=1")
    }
  );
  /* TODO: everything here
  ENTRY(
    "NEC PC-98 (with Sound Orchestra)", {
      DIV_SYSTEM_OPN, 64, 0, 4,
      DIV_SYSTEM_OPL2, 64, 0, 4,
      CH(DIV_SYSTEM_PCSPKR, 64, 0, "clockSel=1"),
    }
  );
  ENTRY(
    "NEC PC-98 (with Sound Orchestra; extended channel 3)", {
      DIV_SYSTEM_OPN_EXT, 64, 0, 4,
      DIV_SYSTEM_OPL2, 64, 0, 4,
      CH(DIV_SYSTEM_PCSPKR, 64, 0, "clockSel=1"),
    }
  );
  ENTRY(
    "NEC PC-98 (with Sound Orchestra in drums mode)", {
      DIV_SYSTEM_OPN, 64, 0, 4,
      DIV_SYSTEM_OPL2_DRUMS, 64, 0, 4,
      CH(DIV_SYSTEM_PCSPKR, 64, 0, "clockSel=1"),
    }
  );
  ENTRY(
    "NEC PC-98 (with Sound Orchestra in drums mode; extended channel 3)", {
      DIV_SYSTEM_OPN_EXT, 64, 0, 4,
      DIV_SYSTEM_OPL2_DRUMS, 64, 0, 4,
      CH(DIV_SYSTEM_PCSPKR, 64, 0, "clockSel=1"),
    }
  );
  ENTRY(
    "NEC PC-98 (with Sound Orchestra V)", {
      DIV_SYSTEM_OPN, 64, 0, 4,
      DIV_SYSTEM_Y8950, 64, 0, 4,
      CH(DIV_SYSTEM_PCSPKR, 64, 0, "clockSel=1"),
    }
  );
  ENTRY(
    "NEC PC-98 (with Sound Orchestra V; extended channel 3)", {
      DIV_SYSTEM_OPN_EXT, 64, 0, 4,
      DIV_SYSTEM_Y8950, 64, 0, 4,
      CH(DIV_SYSTEM_PCSPKR, 64, 0, "clockSel=1"),
    }
  );
  ENTRY(
    "NEC PC-98 (with Sound Orchestra V in drums mode)", {
      DIV_SYSTEM_OPN, 64, 0, 4,
      DIV_SYSTEM_Y8950_DRUMS, 64, 0, 4,
      CH(DIV_SYSTEM_PCSPKR, 64, 0, "clockSel=1"),
    }
  );
  ENTRY(
    "NEC PC-98 (with Sound Orchestra V in drums mode; extended channel 3)", {
      DIV_SYSTEM_OPN_EXT, 64, 0, 4,
      DIV_SYSTEM_Y8950_DRUMS, 64, 0, 4,
      CH(DIV_SYSTEM_PCSPKR, 64, 0, "clockSel=1"),
    }
  );
  ENTRY(
    "NEC PC-98 (with PC-9801-86)", { // -73 also has OPNA
      DIV_SYSTEM_PC98, 64, 0, 1,
      DIV_SYSTEM_PCM_DAC, 64, 0, 44099|(15<<16), // 2x 16-bit Burr Brown DAC
      DIV_SYSTEM_PCM_DAC, 64, 0, 44099|(15<<16),
      CH(DIV_SYSTEM_PCSPKR, 64, 0, "clockSel=1"),
    }
  );
  ENTRY(
    "NEC PC-98 (with PC-9801-86; extended channel 3)", { // -73 also has OPNA
      DIV_SYSTEM_PC98_EXT, 64, 0, 1,
      DIV_SYSTEM_PCM_DAC, 64, 0, 44099|(15<<16),
      DIV_SYSTEM_PCM_DAC, 64, 0, 44099|(15<<16),
      CH(DIV_SYSTEM_PCSPKR, 64, 0, "clockSel=1"),
    }
  );
    ENTRY(
    "NEC PC-98 (with PC-9801-73)", {
      DIV_SYSTEM_PC98, 64, 0, 1,
      CH(DIV_SYSTEM_PCSPKR, 64, 0, "clockSel=1"),
    }
  );
    ENTRY(
    "NEC PC-98 (with PC-9801-73; extended channel 3)", {
      DIV_SYSTEM_PC98_EXT, 64, 0, 1,
      CH(DIV_SYSTEM_PCSPKR, 64, 0, "clockSel=1"),
    }
  );
  ENTRY(
    "NEC PC-98 (with Sound Blaster 16 for PC-9800 w/PC-9801-26/K compatible)", {
      DIV_SYSTEM_OPN, 64, 0, 2, // 4MHz
      DIV_SYSTEM_PCM_DAC, 64, 0, 44099|(15<<16)|(1<<20),
      CH(DIV_SYSTEM_OPL3, 64, 0, ""),
      CH(DIV_SYSTEM_PCSPKR, 64, 0, "clockSel=1"),
    }
  );
  ENTRY(
    "NEC PC-98 (with Sound Blaster 16 for PC-9800 w/PC-9801-26/K compatible; extended channel 3)", {
      DIV_SYSTEM_OPN_EXT, 64, 0, 2, // 4MHz
      DIV_SYSTEM_PCM_DAC, 64, 0, 44099|(15<<16)|(1<<20),
      CH(DIV_SYSTEM_OPL3, 64, 0, ""),
      CH(DIV_SYSTEM_PCSPKR, 64, 0, "clockSel=1"),
    }
  );
  ENTRY(
    "NEC PC-98 (with Sound Blaster 16 for PC-9800 w/PC-9801-26/K compatible in drums mode)", {
      DIV_SYSTEM_OPN, 64, 0, 2, // 4MHz
      DIV_SYSTEM_PCM_DAC, 64, 0, 44099|(15<<16)|(1<<20),
      DIV_SYSTEM_OPL3_DRUMS, 64, 0, 2,
      CH(DIV_SYSTEM_PCSPKR, 64, 0, "clockSel=1"),
    }
  );
  ENTRY(
    "NEC PC-98 (with Sound Blaster 16 for PC-9800 w/PC-9801-26/K compatible in drums mode; extended channel 3)", {
      DIV_SYSTEM_OPN_EXT, 64, 0, 2, // 4MHz
      DIV_SYSTEM_PCM_DAC, 64, 0, 44099|(15<<16)|(1<<20),
      DIV_SYSTEM_OPL3_DRUMS, 64, 0, 2,
      CH(DIV_SYSTEM_PCSPKR, 64, 0, "clockSel=1"),
    }
  );
  ENTRY(
    "ZX Spectrum (48K)", {
      CH(DIV_SYSTEM_SFX_BEEPER, 64, 0, ""),
    }
  );
  ENTRY(
    "ZX Spectrum (128K)", {
      DIV_SYSTEM_AY8910, 64, 0, 1, //beeper was also included
    }
  );
  ENTRY(
    "ZX Spectrum (128K) with TurboSound FM", {
      DIV_SYSTEM_AY8910, 64, 0, 1,
      DIV_SYSTEM_OPN, 64, 0, 1,
      DIV_SYSTEM_OPN, 64, 0, 1,
    }
  );
  ENTRY(
    "ZX Spectrum (128K) with TurboSound FM (extended channel 3 on first OPN)", {
      DIV_SYSTEM_AY8910, 64, 0, 1,
      DIV_SYSTEM_OPN_EXT, 64, 0, 1,
      DIV_SYSTEM_OPN, 64, 0, 1,
    }
  );
  ENTRY(
    "ZX Spectrum (128K) with TurboSound FM (extended channel 3 on second OPN)", {
      DIV_SYSTEM_AY8910, 64, 0, 1,
      DIV_SYSTEM_OPN, 64, 0, 1,
      DIV_SYSTEM_OPN_EXT, 64, 0, 1,
    }
  );
  ENTRY(
    "ZX Spectrum (128K) with TurboSound FM (extended channel 3 on both OPNs)", {
      DIV_SYSTEM_AY8910, 64, 0, 1,
      DIV_SYSTEM_OPN_EXT, 64, 0, 1,
      DIV_SYSTEM_OPN_EXT, 64, 0, 1,
    }
  );
  ENTRY(
    "ZX Spectrum (128K) with TurboSound", {
      DIV_SYSTEM_AY8910, 64, 0, 1,
      DIV_SYSTEM_AY8910, 64, 0, 1, // or YM2149
      DIV_SYSTEM_AY8910, 64, 0, 1, // or YM2149
    }
  );
  ENTRY(
    "Amstrad CPC", {
      DIV_SYSTEM_AY8910, 64, 0, 5,
    }
  );
  ENTRY(
    "Atari ST", {
      DIV_SYSTEM_AY8910, 64, 0, 19,
    }
  );
    ENTRY(
    "Atari STE", {
      DIV_SYSTEM_AY8910, 64, 0, 19,
      DIV_SYSTEM_PCM_DAC, 64, 0, 50667|(7<<16),
      DIV_SYSTEM_PCM_DAC, 64, 0, 50667|(7<<16),
    }
  );
  ENTRY(
    "SAM Coupé", {
      CH(DIV_SYSTEM_SAA1099, 64, 0, ""),
    }
  );
  ENTRY(
    "BBC Micro", {
      DIV_SYSTEM_SMS, 64, 0, 0x42, // SN76489A 4MHz
    }
  );
  ENTRY(
    "PC (barebones)", {
      CH(DIV_SYSTEM_PCSPKR, 64, 0, ""),
    }
  );
  ENTRY(
    "IBM PCjr", {
      // it can be enable sound output at once
      DIV_SYSTEM_SMS, 64, 0, 0x44, // SN76496
    }
  );
  ENTRY(
    "Tandy 1000", {
      DIV_SYSTEM_SMS, 64, 0, 0x44, // NCR 8496 or SN76496 or Tandy PSSJ(with 8 bit DAC)
      CH(DIV_SYSTEM_PCSPKR, 64, 0, ""),
    }
  );
  ENTRY(
    "PC + Covox Sound Master", {
      DIV_SYSTEM_AY8930, 64, 0, 3,
      CH(DIV_SYSTEM_PCSPKR, 64, 0, ""),
    }
  );
  ENTRY(
    "PC + SSI 2001", {
      DIV_SYSTEM_C64_6581, 64, 0, 2,
      CH(DIV_SYSTEM_PCSPKR, 64, 0, ""),
    }
  );
  ENTRY(
    "PC + Game Blaster", {
      DIV_SYSTEM_SAA1099, 64, 0, 1,
      DIV_SYSTEM_SAA1099, 64, 0, 1,
      CH(DIV_SYSTEM_PCSPKR, 64, 0, ""),
    }
  );
    ENTRY(
    "PC + AdLib", {
      CH(DIV_SYSTEM_OPL2, 64, 0, ""),
      CH(DIV_SYSTEM_PCSPKR, 64, 0, ""),
    }
  );
      ENTRY(
    "PC + AdLib (drums mode)", {
      CH(DIV_SYSTEM_OPL2, 64, 0, ""),
      CH(DIV_SYSTEM_PCSPKR, 64, 0, ""),
    }
  );
  ENTRY(
    "PC + Sound Blaster", {
      CH(DIV_SYSTEM_OPL2, 64, 0, ""),
      CH(DIV_SYSTEM_PCSPKR, 64, 0, ""),
      DIV_SYSTEM_PCM_DAC, 64, 0, 22049|(7<<16),
    }
  );
  ENTRY(
    "PC + AdLib/Sound Blaster (drums mode)", {
      CH(DIV_SYSTEM_OPL2_DRUMS, 64, 0, ""),
      CH(DIV_SYSTEM_PCSPKR, 64, 0, ""),
      DIV_SYSTEM_PCM_DAC, 64, 0, 22049|(7<<16),
    }
  );
  ENTRY(
    "PC + Sound Blaster w/Game Blaster Compatible", {
      CH(DIV_SYSTEM_OPL2, 64, 0, ""),
      DIV_SYSTEM_SAA1099, 64, 0, 1,
      DIV_SYSTEM_SAA1099, 64, 0, 1,
      DIV_SYSTEM_PCM_DAC, 64, 0, 22049|(7<<16),
      CH(DIV_SYSTEM_PCSPKR, 64, 0, ""),
    }
  );
  ENTRY(
    "PC + Sound Blaster w/Game Blaster Compatible (drums mode)", {
      CH(DIV_SYSTEM_OPL2_DRUMS, 64, 0, ""),
      DIV_SYSTEM_SAA1099, 64, 0, 1,
      DIV_SYSTEM_SAA1099, 64, 0, 1,
      DIV_SYSTEM_PCM_DAC, 64, 0, 22049|(7<<16),
      CH(DIV_SYSTEM_PCSPKR, 64, 0, ""),
    }
  );
  ENTRY(
    "PC + Sound Blaster Pro", {
      DIV_SYSTEM_OPL2, 64, -127, 0,
      DIV_SYSTEM_OPL2, 64, 127, 0,
      DIV_SYSTEM_PCM_DAC, 64, 0, 22049|(7<<16)|(1<<20), //alternatively 44.1 khz mono
      CH(DIV_SYSTEM_PCSPKR, 64, 0, ""),
    }
  );
  ENTRY(
    "PC + Sound Blaster Pro (drums mode)", {
      DIV_SYSTEM_OPL2_DRUMS, 64, -127, 0,
      DIV_SYSTEM_OPL2_DRUMS, 64, 127, 0,
      DIV_SYSTEM_PCM_DAC, 64, 0, 22049|(7<<16)|(1<<20), //alternatively 44.1 khz mono
      CH(DIV_SYSTEM_PCSPKR, 64, 0, ""),
    }
  );
  ENTRY(
    "PC + Sound Blaster Pro 2", {
      CH(DIV_SYSTEM_OPL3, 64, 0, ""),
      DIV_SYSTEM_PCM_DAC, 64, 0, 44099|(15<<16)|(1<<20),
      CH(DIV_SYSTEM_PCSPKR, 64, 0, ""),
    }
  );
  ENTRY(
    "PC + Sound Blaster Pro 2 (drums mode)", {
      CH(DIV_SYSTEM_OPL3_DRUMS, 64, 0, ""),
      DIV_SYSTEM_PCM_DAC, 64, 0, 44099|(15<<16)|(1<<20),
      CH(DIV_SYSTEM_PCSPKR, 64, 0, ""),
    }
  );
  ENTRY(
    "PC + PC-FXGA", {
      DIV_SYSTEM_PCE, 64, 0, 0, // HuC6230 (WSG from HuC6280 but with built in 2 OKI ADPCM playback engines)
      CH(DIV_SYSTEM_PCSPKR, 64, 0, ""),
    }
  );
  ENTRY(
    "PC + SAAYM", {
      DIV_SYSTEM_YM2151, 64, 0, 0, // 3.58MHz or 4MHz selectable via jumper
      DIV_SYSTEM_SAA1099, 64, 0, 1, // 7.16MHz or 8MHz selectable via jumper
      DIV_SYSTEM_SAA1099, 64, 0, 1, // ""
      CH(DIV_SYSTEM_PCSPKR, 64, 0, ""),
    }
  );
  ENTRY(
    "Sharp X1", {
      DIV_SYSTEM_AY8910, 64, 0, 3,
    }
  );
  ENTRY(
    "Sharp X1 + FM Addon", {
      DIV_SYSTEM_AY8910, 64, 0, 3,
      DIV_SYSTEM_YM2151, 64, 0, 2,
    }
  );
  ENTRY(
    "Sharp X68000", {
      DIV_SYSTEM_YM2151, 64, 0, 2,
      CH(DIV_SYSTEM_MSM6258, 64, 0, ""),
    }
  );
  ENTRY(
    "FM Towns", {
      DIV_SYSTEM_YM2612, 64, 0, 2, // YM3438
      CH(DIV_SYSTEM_RF5C68, 64, 0, ""),
    }
  );
  ENTRY(
    "Commander X16", {
      CH(DIV_SYSTEM_VERA, 64, 0, ""),
      CH(DIV_SYSTEM_YM2151, 32, 0, ""),
    }
  );
  ENTRY(
    "TI-99/4A", {
      DIV_SYSTEM_SMS, 64, 0, 0x182, // SN94624 447KHz
    }
  );
  */
  CATEGORY_END;

  /* TODO: everything here
  CATEGORY_BEGIN("FM","chips which use frequency modulation (FM) to generate sound.\nsome of these also pack more (like square and sample channels).");
  ENTRY(
    "Yamaha YM2151 (OPM)", {
      CH(DIV_SYSTEM_YM2151, 64, 0, ""),
    }
  );
  ENTRY(
    "Yamaha YM2203 (OPN)", {
      DIV_SYSTEM_OPN, 64, 0, 3,
    }
  );
  ENTRY(
    "Yamaha YM2203 (extended channel 3)", {
      DIV_SYSTEM_OPN_EXT, 64, 0, 3,
    }
  );
  ENTRY(
    "Yamaha YM2608 (OPNA)", {
      CH(DIV_SYSTEM_PC98, 64, 0, ""),
    }
  );
  ENTRY(
    "Yamaha YM2608 (extended channel 3)", {
      CH(DIV_SYSTEM_PC98_EXT, 64, 0, ""),
    }
  );
  ENTRY(
    "Yamaha YM2610 (OPNB)", {
      CH(DIV_SYSTEM_YM2610_FULL, 64, 0, ""),
    }
  );
  ENTRY(
    "Yamaha YM2610 (extended channel 2)", {
      CH(DIV_SYSTEM_YM2610_FULL_EXT, 64, 0, ""),
    }
  );
  ENTRY(
    "Yamaha YM2610B (OPNB2)", {
      CH(DIV_SYSTEM_YM2610B, 64, 0, ""),
    }
  );
  ENTRY(
    "Yamaha YM2610B (extended channel 3)", {
      CH(DIV_SYSTEM_YM2610B_EXT, 64, 0, ""),
    }
  );
  ENTRY(
    "Yamaha YM2612 (OPN2)", {
      DIV_SYSTEM_YM2612, 64, 0, (int)0x80000000,
    }
  );
  ENTRY(
    "Yamaha YM2612 (extended channel 3)", {
      DIV_SYSTEM_YM2612_EXT, 64, 0, (int)0x80000000,
    }
  );
  ENTRY(
    "Yamaha YM2612 (OPN2) with DualPCM", {
      DIV_SYSTEM_YM2612_FRAC, 64, 0, (int)0x80000000,
    }
  );
  ENTRY(
    "Yamaha YM2612 (extended channel 3) with DualPCM", {
      DIV_SYSTEM_YM2612_FRAC_EXT, 64, 0, (int)0x80000000,
    }
  );
  ENTRY(
    "Yamaha YM2413 (OPLL)", {
      CH(DIV_SYSTEM_OPLL, 64, 0, ""),
    }
  );
  ENTRY(
    "Yamaha YM2413 (drums mode)", {
      CH(DIV_SYSTEM_OPLL_DRUMS, 64, 0, ""),
    }
  );
  ENTRY(
    "Yamaha YM2414 (OPZ)", {
      CH(DIV_SYSTEM_OPZ, 64, 0, ""),
    }
  );
  ENTRY(
    "Yamaha YM3438 (OPN2C)", {
      CH(DIV_SYSTEM_YM2612, 64, 0, ""),
    }
  );
  ENTRY(
    "Yamaha YM3438 (extended channel 3)", {
      CH(DIV_SYSTEM_YM2612_EXT, 64, 0, ""),
    }
  );
  ENTRY(
    "Yamaha YM3438 (OPN2C) with DualPCM", {
      CH(DIV_SYSTEM_YM2612_FRAC, 64, 0, ""),
    }
  );
  ENTRY(
    "Yamaha YM3438 (extended channel 3) with DualPCM", {
      CH(DIV_SYSTEM_YM2612_FRAC_EXT, 64, 0, ""),
    }
  );
  ENTRY(
    "Yamaha YM3526 (OPL)", {
      CH(DIV_SYSTEM_OPL, 64, 0, ""),
    }
  );
  ENTRY(
    "Yamaha YM3526 (drums mode)", {
      CH(DIV_SYSTEM_OPL_DRUMS, 64, 0, ""),
    }
  );
  ENTRY(
    "Yamaha Y8950", {
      CH(DIV_SYSTEM_Y8950, 64, 0, ""),
    }
  );
  ENTRY(
    "Yamaha Y8950 (drums mode)", {
      CH(DIV_SYSTEM_Y8950_DRUMS, 64, 0, ""),
    }
  );
  ENTRY(
    "Yamaha YM3812 (OPL2)", {
      CH(DIV_SYSTEM_OPL2, 64, 0, ""),
    }
  );
  ENTRY(
    "Yamaha YM3812 (drums mode)", {
      CH(DIV_SYSTEM_OPL2_DRUMS, 64, 0, ""),
    }
  );
  ENTRY(
    "Yamaha YMF262 (OPL3)", {
      CH(DIV_SYSTEM_OPL3, 64, 0, ""),
    }
  );
  ENTRY(
    "Yamaha YMF262 (drums mode)", {
      CH(DIV_SYSTEM_OPL3_DRUMS, 64, 0, ""),
    }
  );
  if (settings.hiddenSystems) {
    ENTRY(
      "Yamaha YMU759 (MA-2)", {
        CH(DIV_SYSTEM_YMU759, 64, 0, ""),
        0
      }
    );
  }
  CATEGORY_END;

  CATEGORY_BEGIN("Square","these chips generate square/pulse tones only (but may include noise).");
  ENTRY(
    "TI SN76489", {
      DIV_SYSTEM_SMS, 64, 0, 4,
    }
  );
  ENTRY(
    "TI SN76489A", {
      DIV_SYSTEM_SMS, 64, 0, 0x40,
    }
  );
  ENTRY(
    "TI SN76496", {
      DIV_SYSTEM_SMS, 64, 0, 0x44,
    }
  );
  ENTRY(
    "NCR 8496", {
      DIV_SYSTEM_SMS, 64, 0, 0x48,
    }
  );
  ENTRY(
    "Tandy PSSJ 3-voice sound", {
      DIV_SYSTEM_SMS, 64, 0, 0x4c,
      // 8 bit DAC
    }
  );
  ENTRY(
    "Sega PSG (SN76489-like)", {
      CH(DIV_SYSTEM_SMS, 64, 0, ""),
    }
  );
  ENTRY(
    "Sega PSG (SN76489-like, Stereo)", {
      DIV_SYSTEM_SMS, 64, 0, 0xc,
    }
  );
  ENTRY(
    "TI SN94624", {
      DIV_SYSTEM_SMS, 64, 0, 0x182,
    }
  );
  ENTRY(
    "TI SN76494", {
      DIV_SYSTEM_SMS, 64, 0, 0x186,
    }
  );
  ENTRY(
    "Toshiba T6W28", {
      CH(DIV_SYSTEM_T6W28, 64, 0, ""),
    }
  );
  ENTRY(
    "AY-3-8910", {
      CH(DIV_SYSTEM_AY8910, 64, 0, ""),
    }
  );
  ENTRY(
    "AY-3-8914", {
      DIV_SYSTEM_AY8910, 64, 0, 48,
    }
  );
  ENTRY(
    "Yamaha YM2149(F)", {
      DIV_SYSTEM_AY8910, 64, 0, 16,
    }
  );
  ENTRY(
    "Philips SAA1099", {
      CH(DIV_SYSTEM_SAA1099, 64, 0, ""),
    }
  );
  ENTRY(
    "PC Speaker", {
      CH(DIV_SYSTEM_PCSPKR, 32, 0, ""),
    }
  );
  ENTRY(
    "Commodore VIC", {
      DIV_SYSTEM_VIC20, 64, 0, 1,
    }
  );
  ENTRY(
    "OKI MSM5232", {
      CH(DIV_SYSTEM_MSM5232, 64, 0, ""),
    }
  );
  ENTRY(
    "Pong", {
      CH(DIV_SYSTEM_PONG, 64, 0, ""),
    }
  );
  CATEGORY_END;

  CATEGORY_BEGIN("Sample","chips/systems which use PCM or ADPCM samples for sound synthesis.");
  ENTRY(
    "Amiga", {
      CH(DIV_SYSTEM_AMIGA, 64, 0, ""),
    }
  );
  ENTRY(
    "SegaPCM", {
      CH(DIV_SYSTEM_SEGAPCM, 64, 0, ""),
    }
  );
  ENTRY(
    "Capcom QSound", {
      CH(DIV_SYSTEM_QSOUND, 64, 0, ""),
    }
  );
  ENTRY(
    "Seta/Allumer X1-010", {
      CH(DIV_SYSTEM_X1_010, 64, 0, ""),
    }
  );
  ENTRY(
    "Yamaha YMZ280B (PCMD8)", {
      CH(DIV_SYSTEM_YMZ280B, 64, 0, ""),
    }
  );
  ENTRY(
    "Ricoh RF5C68", {
      CH(DIV_SYSTEM_RF5C68, 64, 0, ""),
    }
  ); 
  ENTRY(
    "OKI MSM6258", {
      CH(DIV_SYSTEM_MSM6258, 64, 0, ""),
    }
  );
  ENTRY(
    "OKI MSM6295", {
      CH(DIV_SYSTEM_MSM6295, 64, 0, ""),
    }
  );
  ENTRY(
    "SNES", {
      CH(DIV_SYSTEM_SNES, 64, 0, ""),
    }
  );
  ENTRY(
    "Generic PCM DAC", {
      CH(DIV_SYSTEM_PCM_DAC, 64, 0, ""),
    }
  );
  ENTRY(
    "Ensoniq ES5506 (OTTO)", {
      CH(DIV_SYSTEM_ES5506, 64, 0, "channels=31")
    }
  );
  CATEGORY_END;

  CATEGORY_BEGIN("Wavetable","chips which use user-specified waveforms to generate sound.");
  ENTRY(
    "PC Engine", {
      CH(DIV_SYSTEM_PCE, 64, 0, ""),
    }
  );
  ENTRY(
    "Commodore PET (pseudo-wavetable)", {
      CH(DIV_SYSTEM_PET, 64, 0, ""),
    }
  );
  ENTRY(
    "Konami Bubble System WSG", {
      CH(DIV_SYSTEM_BUBSYS_WSG, 64, 0, ""),
    }
  );
  ENTRY(
    "Konami SCC", {
      CH(DIV_SYSTEM_SCC, 64, 0, ""),
    }
  );
  ENTRY(
    "Konami SCC+", {
      CH(DIV_SYSTEM_SCC_PLUS, 64, 0, ""),
    }
  );
  ENTRY(
    "Namco WSG", {
      CH(DIV_SYSTEM_NAMCO, 64, 0, ""),
    }
  );
  ENTRY(
    "Namco C15 (8-channel mono)", {
      CH(DIV_SYSTEM_NAMCO_15XX, 64, 0, ""),
    }
  );
  ENTRY(
    "Namco C30 (8-channel stereo)", {
      CH(DIV_SYSTEM_NAMCO_CUS30, 64, 0, ""),
    }
  );
  ENTRY(
    "Namco 163", {
      CH(DIV_SYSTEM_N163, 64, 0, ""),
    }
  );
  ENTRY(
    "Famicom Disk System (chip)", {
      CH(DIV_SYSTEM_FDS, 64, 0, ""),
    }
  );
  ENTRY(
    "WonderSwan", {
      CH(DIV_SYSTEM_SWAN, 64, 0, ""),
    }
  );
  ENTRY(
    "Virtual Boy", {
      CH(DIV_SYSTEM_VBOY, 64, 0, ""),
    }
  );
  ENTRY(
    "Seta/Allumer X1-010", {
      CH(DIV_SYSTEM_X1_010, 64, 0, ""),
    }
  );
  CATEGORY_END;

  CATEGORY_BEGIN("Specialized","chips/systems with unique sound synthesis methods.");
  ENTRY(
    "MOS Technology SID (6581)", {
      DIV_SYSTEM_C64_6581, 64, 0, 1,
    }
  );
  ENTRY(
    "MOS Technology SID (8580)", {
      DIV_SYSTEM_C64_8580, 64, 0, 1,
    }
  );
  ENTRY(
    "Microchip AY8930", {
      CH(DIV_SYSTEM_AY8930, 64, 0, ""),
    }
  );
  ENTRY(
    "Game Boy", {
      CH(DIV_SYSTEM_GB, 64, 0, ""),
    }
  );
  ENTRY(
    "Atari Lynx", {
      CH(DIV_SYSTEM_LYNX, 64, 0, ""),
    }
  );
  ENTRY(
    "Atari TIA", {
      CH(DIV_SYSTEM_TIA, 64, 0, ""),
    }
  );
  ENTRY(
    "NES (Ricoh 2A03)", {
      CH(DIV_SYSTEM_NES, 64, 0, ""),
    }
  );
  ENTRY(
    "Commander X16 (VERA only)", {
      CH(DIV_SYSTEM_VERA, 64, 0, ""),
    }
  );
  ENTRY(
    "ZX Spectrum (beeper only)", {
      CH(DIV_SYSTEM_SFX_BEEPER, 64, 0, ""),
    }
  );
  if (settings.hiddenSystems) {
    ENTRY(
      "Dummy System", {
        CH(DIV_SYSTEM_DUMMY, 64, 0, ""),
        0
      }
    );
  }
  ENTRY(
    "tildearrow Sound Unit", {
      CH(DIV_SYSTEM_SOUND_UNIT, 64, 0, ""),
    }
  );
  CATEGORY_END;

  CATEGORY_BEGIN("Arcade systems","INSERT COIN");
  ENTRY(
    "Pong", {
      CH(DIV_SYSTEM_PONG, 64, 0, ""),
    }
  );
  ENTRY(
    "Bally Midway MCR", {
      // SSIO sound board
      DIV_SYSTEM_AY8910, 64, 0, 3, // 2MHz
      DIV_SYSTEM_AY8910, 64, 0, 3, // 2MHz
      // additional sound boards, mostly software controlled DAC
    }
  );
  ENTRY(
    "Williams/Midway Y/T unit w/ADPCM sound board", {
      // ADPCM sound board
      CH(DIV_SYSTEM_YM2151, 64, 0, ""),
      DIV_SYSTEM_PCM_DAC, 64, 0, 15624|(7<<16), // variable via OPM timer?
      CH(DIV_SYSTEM_MSM6295, 64, 0, ""),
    }
  );
  ENTRY(
    "Konami Gyruss", {
      CH(DIV_SYSTEM_AY8910, 64, 0, ""),
      CH(DIV_SYSTEM_AY8910, 64, 0, ""),
      CH(DIV_SYSTEM_AY8910, 64, 0, ""),
      CH(DIV_SYSTEM_AY8910, 64, 0, ""),
      CH(DIV_SYSTEM_AY8910, 64, 0, ""),
      // additional discrete sound logics
    }
  );
  ENTRY(
    "Konami Bubble System", {
      CH(DIV_SYSTEM_AY8910, 64, 0, ""),
      CH(DIV_SYSTEM_AY8910, 64, 0, ""),
      CH(DIV_SYSTEM_BUBSYS_WSG, 64, 0, ""),
      // VLM5030 exists but not used for music at all
    }
  );
  ENTRY(
    "Konami Battlantis", {
      DIV_SYSTEM_OPL2, 64, 0, 3, // 3MHz
      DIV_SYSTEM_OPL2, 64, 0, 3, // ""
    }
  );
  ENTRY(
    "Konami Battlantis (drums mode on first OPL2)", {
      DIV_SYSTEM_OPL2_DRUMS, 64, 0, 3, // 3MHz
      DIV_SYSTEM_OPL2, 64, 0, 3, // ""
    }
  );
  ENTRY(
    "Konami Battlantis (drums mode on second OPL2)", {
      DIV_SYSTEM_OPL2, 64, 0, 3, // 3MHz
      DIV_SYSTEM_OPL2_DRUMS, 64, 0, 3, // ""
    }
  );
  ENTRY(
    "Konami Battlantis (drums mode on both OPL2s)", {
      DIV_SYSTEM_OPL2_DRUMS, 64, 0, 3, // 3MHz
      DIV_SYSTEM_OPL2_DRUMS, 64, 0, 3, // ""
    }
  );
  ENTRY(
    "Konami Hexion", {
      DIV_SYSTEM_SCC, 64, 0, 2, // 1.5MHz (3MHz input)
      DIV_SYSTEM_MSM6295, 64, 0, 1,
    }
  );
  ENTRY(
    "Sega Kyugo", {
      DIV_SYSTEM_AY8910, 64, 0, 14,
      DIV_SYSTEM_AY8910, 64, 0, 14,
    }
  );
  ENTRY(
    "Sega System 1", {
      DIV_SYSTEM_SMS, 64, 0, 0x42, // SN76489A 4MHz
      DIV_SYSTEM_SMS, 64, 0, 0x0141, // SN76489A 2MHz
    }
  );
  ENTRY(
    "Sega System E", {
      CH(DIV_SYSTEM_SMS, 64, 0, ""),
      CH(DIV_SYSTEM_SMS, 64, 0, ""),
    }
  );
  ENTRY(
    "Sega System E (with FM expansion)", {
      CH(DIV_SYSTEM_SMS, 64, 0, ""),
      CH(DIV_SYSTEM_SMS, 64, 0, ""),
      CH(DIV_SYSTEM_OPLL, 64, 0, ""),
    }
  );
  ENTRY(
    "Sega System E (with FM expansion in drums mode)", {
      CH(DIV_SYSTEM_SMS, 64, 0, ""),
      CH(DIV_SYSTEM_SMS, 64, 0, ""),
      CH(DIV_SYSTEM_OPLL_DRUMS, 64, 0, ""),
    }
  );
  ENTRY(
    "Sega Hang-On", {
      DIV_SYSTEM_OPN, 64, 0, 2, // 4MHz
      DIV_SYSTEM_SEGAPCM, 64, 0, 0, // discrete logics, 62.5KHz output rate
    }
  );
  ENTRY(
    "Sega Hang-On (extended channel 3)", {
      DIV_SYSTEM_OPN_EXT, 64, 0, 2, // 4MHz
      DIV_SYSTEM_SEGAPCM, 64, 0, 0, // discrete logics, 62.5KHz output rate
    }
  );
  ENTRY(
    "Sega OutRun/X Board", {
      DIV_SYSTEM_YM2151, 64, 0, 2, // 4MHz
      DIV_SYSTEM_SEGAPCM, 64, 0, 0, // ASIC, 31.25KHz output rate
    }
  );
  ENTRY(
    "Sega System 24", {
      DIV_SYSTEM_YM2151, 64, 0, 2, // 4MHz
      DIV_SYSTEM_PCM_DAC, 64, 0, 61499|(7<<16), // software controlled, variable rate via configurable timers
    }
  );
  ENTRY(
    "Sega System 18", {
      DIV_SYSTEM_YM2612, 64, 0, 2, // discrete 8MHz YM3438
      DIV_SYSTEM_YM2612, 64, 0, 2, // ^^
      DIV_SYSTEM_RF5C68, 64, 0, 1, // 10MHz
    }
  );
  ENTRY(
    "Sega System 18 (extended channel 3 on first OPN2C)", {
      DIV_SYSTEM_YM2612_EXT, 64, 0, 2, // discrete 8MHz YM3438
      DIV_SYSTEM_YM2612, 64, 0, 2, // ^^
      DIV_SYSTEM_RF5C68, 64, 0, 1, // 10MHz
    }
  );
  ENTRY(
    "Sega System 18 (extended channel 3 on second OPN2C)", {
      DIV_SYSTEM_YM2612, 64, 0, 2, // discrete 8MHz YM3438
      DIV_SYSTEM_YM2612_EXT, 64, 0, 2, // ^^
      DIV_SYSTEM_RF5C68, 64, 0, 1, // 10MHz
    }
  );
  ENTRY(
    "Sega System 18 (extended channel 3 on both OPN2Cs)", {
      DIV_SYSTEM_YM2612_EXT, 64, 0, 2, // discrete 8MHz YM3438
      DIV_SYSTEM_YM2612_EXT, 64, 0, 2, // ^^
      DIV_SYSTEM_RF5C68, 64, 0, 1, // 10MHz
    }
  );
  ENTRY(
    "Sega System 32", {
      DIV_SYSTEM_YM2612, 64, 0, 4, // discrete 8.05MHz YM3438
      DIV_SYSTEM_YM2612, 64, 0, 4, // ^^
      DIV_SYSTEM_RF5C68, 64, 0, 2, // 12.5MHz
    }
  );
  ENTRY(
    "Sega System 32 (extended channel 3 on first OPN2C)", {
      DIV_SYSTEM_YM2612_EXT, 64, 0, 4, // discrete 8.05MHz YM3438
      DIV_SYSTEM_YM2612, 64, 0, 4, // ^^
      DIV_SYSTEM_RF5C68, 64, 0, 2, // 12.5MHz
    }
  );
  ENTRY(
    "Sega System 32 (extended channel 3 on second OPN2C)", {
      DIV_SYSTEM_YM2612, 64, 0, 4, // discrete 8.05MHz YM3438
      DIV_SYSTEM_YM2612_EXT, 64, 0, 4, // ^^
      DIV_SYSTEM_RF5C68, 64, 0, 2, // 12.5MHz
    }
  );
  ENTRY(
    "Sega System 32 (extended channel 3 on both OPN2Cs)", {
      DIV_SYSTEM_YM2612_EXT, 64, 0, 4, // discrete 8.05MHz YM3438
      DIV_SYSTEM_YM2612_EXT, 64, 0, 4, // ^^
      DIV_SYSTEM_RF5C68, 64, 0, 2, // 12.5MHz
    }
  );
  ENTRY(
    "Capcom Exed Eyes", {
      DIV_SYSTEM_AY8910, 64, 0, 4, // 1.5MHz
      DIV_SYSTEM_SMS, 64, 0, 0x0104, // SN76489 3MHz
      DIV_SYSTEM_SMS, 64, 0, 0x0104, // SN76489 3MHz
    }
  );
  ENTRY(
    "Capcom Arcade", { // 1943, Side arms, etc
      DIV_SYSTEM_OPN, 64, 0, 5, // 4 or 1.5MHz; various per games
      DIV_SYSTEM_OPN, 64, 0, 5,
    }
  );
  ENTRY(
    "Capcom Arcade (extended channel 3 on first OPN)", {
      DIV_SYSTEM_OPN_EXT, 64, 0, 5,
      DIV_SYSTEM_OPN, 64, 0, 5,
    }
  );
  ENTRY(
    "Capcom Arcade (extended channel 3 on second OPN)", {
      DIV_SYSTEM_OPN, 64, 0, 5,
      DIV_SYSTEM_OPN_EXT, 64, 0, 5,
    }
  );
  ENTRY(
    "Capcom Arcade (extended channel 3 on both OPNs)", {
      DIV_SYSTEM_OPN_EXT, 64, 0, 5,
      DIV_SYSTEM_OPN_EXT, 64, 0, 5,
    }
  );
  ENTRY(
    "Capcom CPS-1", { 
      DIV_SYSTEM_YM2151, 64, 0, 0, // 3.58MHz
      CH(DIV_SYSTEM_MSM6295, 64, 0, ""),
    }
  );
  ENTRY(
    "Capcom CPS-2 (QSound)", {
      CH(DIV_SYSTEM_QSOUND, 64, 0, ""),
    }
  );
  ENTRY(
    "Jaleco Ginga NinkyouDen", {
      DIV_SYSTEM_AY8910, 64, 0, 16, // 1.79MHz
      DIV_SYSTEM_Y8950, 64, 0, 0, // 3.58MHz
    }
  );
  ENTRY(
    "Jaleco Ginga NinkyouDen (drums mode)", {
      DIV_SYSTEM_AY8910, 64, 0, 16, // 1.79MHz
      DIV_SYSTEM_Y8950_DRUMS, 64, 0, 0, // 3.58MHz
    }
  );
  ENTRY(
    "Jaleco Mega System 1", {
      DIV_SYSTEM_YM2151, 64, 0, 1, // 3.5MHz (7MHz / 2)
      DIV_SYSTEM_MSM6295, 64, 0, 2, // 4MHz
      DIV_SYSTEM_MSM6295, 64, 0, 2, // 4MHz
    }
  );
  ENTRY(
    "NMK 16-bit Arcade", {
      DIV_SYSTEM_OPN, 64, 0, 5, // 1.5MHz; optional
      DIV_SYSTEM_MSM6295, 64, 0, 130, // 4MHz
      DIV_SYSTEM_MSM6295, 64, 0, 130, // ^^
    }
  );
  ENTRY(
    "NMK 16-bit Arcade (extended channel 3)", {
      DIV_SYSTEM_OPN_EXT, 64, 0, 5, // 1.5MHz; optional
      DIV_SYSTEM_MSM6295, 64, 0, 130, // 4MHz
      DIV_SYSTEM_MSM6295, 64, 0, 130, // ^^
    }
  );
  ENTRY(
    "Kaneko DJ Boy", {
      DIV_SYSTEM_OPN, 64, 0, 3, // 3MHz
      DIV_SYSTEM_MSM6295, 64, -127, 12, // 1.5MHz, Left output
      DIV_SYSTEM_MSM6295, 64, 127, 12, // 1.5MHz, Right output
    }
  );
  ENTRY(
    "Kaneko DJ Boy (extended channel 3)", {
      DIV_SYSTEM_OPN_EXT, 64, 0, 3, // 3MHz
      DIV_SYSTEM_MSM6295, 64, -127, 12, // 1.5MHz, Left output
      DIV_SYSTEM_MSM6295, 64, 127, 12, // 1.5MHz, Right output
    }
  );
  ENTRY(
    "Kaneko Air Buster", {
      DIV_SYSTEM_OPN, 64, 0, 3, // 3MHz
      DIV_SYSTEM_MSM6295, 64, 0, 141, // 3MHz
    }
  );
  ENTRY(
    "Kaneko Air Buster (extended channel 3)", {
      DIV_SYSTEM_OPN_EXT, 64, 0, 3, // 3MHz
      DIV_SYSTEM_MSM6295, 64, 0, 141, // 3MHz
    }
  );
  ENTRY(
    "Kaneko Toybox System", {
      DIV_SYSTEM_AY8910, 64, 0, 19, // YM2149 2MHz
      DIV_SYSTEM_AY8910, 64, 0, 19, // ^^
      DIV_SYSTEM_MSM6295, 64, 0, 8, // 2MHz
    }
  );
  ENTRY(
    "Kaneko Jackie Chan", {
      DIV_SYSTEM_YMZ280B, 64, 0, 3, // 16MHz
    }
  );
  ENTRY(
    "Super Kaneko Nova System", {
      DIV_SYSTEM_YMZ280B, 64, 0, 4, // 16.67MHz (33.33MHz / 2)
    }
  );
  ENTRY(
    "Tecmo Ninja Gaiden", { // Ninja Gaiden, Raiga, etc
      DIV_SYSTEM_OPN, 64, 0, 2, // 4MHz
      DIV_SYSTEM_OPN, 64, 0, 2, // 4MHz
      DIV_SYSTEM_MSM6295, 64, 0, 0, // 1MHz
    }
  );
  ENTRY(
    "Tecmo Ninja Gaiden (extended channel 3 on first OPN)", { // Ninja Gaiden, Raiga, etc
      DIV_SYSTEM_OPN_EXT, 64, 0, 2, // 4MHz
      DIV_SYSTEM_OPN, 64, 0, 2, // 4MHz
      DIV_SYSTEM_MSM6295, 64, 0, 0, // 1MHz
    }
  );
  ENTRY(
    "Tecmo Ninja Gaiden (extended channel 3 on second OPN)", { // Ninja Gaiden, Raiga, etc
      DIV_SYSTEM_OPN, 64, 0, 2, // 4MHz
      DIV_SYSTEM_OPN_EXT, 64, 0, 2, // 4MHz
      DIV_SYSTEM_MSM6295, 64, 0, 0, // 1MHz
    }
  );
  ENTRY(
    "Tecmo Ninja Gaiden (extended channel 3 on both OPNs)", { // Ninja Gaiden, Raiga, etc
      DIV_SYSTEM_OPN_EXT, 64, 0, 2, // 4MHz
      DIV_SYSTEM_OPN_EXT, 64, 0, 2, // 4MHz
      DIV_SYSTEM_MSM6295, 64, 0, 0, // 1MHz
    }
  );
  ENTRY(
    "Tecmo System", {
      CH(DIV_SYSTEM_OPL3, 64, 0, ""),
      CH(DIV_SYSTEM_YMZ280B, 64, 0, ""),
      DIV_SYSTEM_MSM6295, 64, 0, 8, // 2MHz
    }
  );
  ENTRY(
    "Tecmo System (drums mode)", {
      CH(DIV_SYSTEM_OPL3_DRUMS, 64, 0, ""),
      CH(DIV_SYSTEM_YMZ280B, 64, 0, ""),
      DIV_SYSTEM_MSM6295, 64, 0, 8, // 2MHz
    }
  );
  ENTRY(
    "Seibu Kaihatsu Raiden", { // Raiden, Seibu cup soccer, Zero team, etc
      DIV_SYSTEM_OPL2, 64, 0, 0, // YM3812 3.58MHz
      DIV_SYSTEM_MSM6295, 64, 0, 0, // 1 or 1.023MHz (28.636363MHz / 28); various per games
    }
  );
  ENTRY(
    "Seibu Kaihatsu Raiden (drums mode)", { // Raiden, Seibu cup soccer, Zero team, etc
      DIV_SYSTEM_OPL2_DRUMS, 64, 0, 0, // YM3812 3.58MHz
      DIV_SYSTEM_MSM6295, 64, 0, 0, // 1 or 1.023MHz (28.636363MHz / 28); various per games
    }
  );
  ENTRY(
    "Sunsoft Shanghai 3", {
      DIV_SYSTEM_AY8910, 64, 0, 20, // YM2149 1.5MHz
      DIV_SYSTEM_MSM6295, 64, 0, 1, // 1.056MHz
    }
  );
  ENTRY(
    "Sunsoft Arcade", {
      DIV_SYSTEM_YM2612, 64, 0, 2, // discrete YM3438 8MHz
      DIV_SYSTEM_MSM6295, 64, 0, 1, // 1.056MHz
    }
  );
  ENTRY(
    "Sunsoft Arcade (extended channel 3)", {
      DIV_SYSTEM_YM2612_EXT, 64, 0, 2, // discrete YM3438 8MHz
      DIV_SYSTEM_MSM6295, 64, 0, 1, // 1.056MHz
    }
  );
  ENTRY(
    "Atari Klax", { 
      DIV_SYSTEM_MSM6295, 64, 0, 7, // 0.895MHz (3.579545MHz / 4)
    }
  );
  ENTRY(
    "Atari Rampart", { 
      DIV_SYSTEM_OPLL, 64, 0, 0, // 3.579545MHz
      DIV_SYSTEM_MSM6295, 64, 0, 14, // 1.193MHz (3.579545MHz / 3)
    }
  );
  ENTRY(
    "Atari Rampart (drums mode)", { 
      DIV_SYSTEM_OPLL_DRUMS, 64, 0, 0, // 3.579545MHz
      DIV_SYSTEM_MSM6295, 64, 0, 14, // 1.193MHz (3.579545MHz / 3)
    }
  );
  ENTRY(
    "Atari JSA IIIs", { 
      DIV_SYSTEM_YM2151, 64, 0, 0, // 3.579545MHz
      DIV_SYSTEM_MSM6295, 64, -127, 14, // 1.193MHz (3.579545MHz / 3), Left output
      DIV_SYSTEM_MSM6295, 64, 127, 14, // 1.193MHz (3.579545MHz / 3), Right output
    }
  );
  ENTRY(
    "Data East Karnov", {
      DIV_SYSTEM_OPN, 64, 0, 5, // 1.5MHz
      DIV_SYSTEM_OPL, 64, 0, 3, // 3MHz
    }
  );
  ENTRY(
    "Data East Karnov (extended channel 3)", {
      DIV_SYSTEM_OPN_EXT, 64, 0, 5, // 1.5MHz
      DIV_SYSTEM_OPL, 64, 0, 3, // 3MHz
    }
  );
  ENTRY(
    "Data East Karnov (drums mode)", {
      DIV_SYSTEM_OPN, 64, 0, 5, // 1.5MHz
      DIV_SYSTEM_OPL_DRUMS, 64, 0, 3, // 3MHz
    }
  );
  ENTRY(
    "Data East Karnov (extended channel 3; drums mode)", {
      DIV_SYSTEM_OPN_EXT, 64, 0, 5, // 1.5MHz
      DIV_SYSTEM_OPL_DRUMS, 64, 0, 3, // 3MHz
    }
  );
  ENTRY(
    "Data East Arcade", { // Bad dudes, Robocop, etc
      DIV_SYSTEM_OPN, 64, 0, 5, // 1.5MHz
      DIV_SYSTEM_OPL2, 64, 0, 3, // 3MHz
      DIV_SYSTEM_MSM6295, 64, 0, 0, // 1 to 1.056MHz; various per games or optional
    }
  );
  ENTRY(
    "Data East Arcade (extended channel 3)", { // Bad dudes, Robocop, etc
      DIV_SYSTEM_OPN_EXT, 64, 0, 5, // 1.5MHz
      DIV_SYSTEM_OPL2, 64, 0, 3, // 3MHz
      DIV_SYSTEM_MSM6295, 64, 0, 0, // 1 to 1.056MHz; various per games or optional
    }
  );
  ENTRY(
    "Data East Arcade (drums mode)", { // Bad dudes, Robocop, etc
      DIV_SYSTEM_OPN, 64, 0, 5, // 1.5MHz
      DIV_SYSTEM_OPL2_DRUMS, 64, 0, 3, // 3MHz
      DIV_SYSTEM_MSM6295, 64, 0, 0, // 1 to 1.056MHz; various per games or optional
    }
  );
  ENTRY(
    "Data East Arcade (extended channel 3; drums mode)", { // Bad dudes, Robocop, etc
      DIV_SYSTEM_OPN_EXT, 64, 0, 5, // 1.5MHz
      DIV_SYSTEM_OPL2_DRUMS, 64, 0, 3, // 3MHz
      DIV_SYSTEM_MSM6295, 64, 0, 0, // 1 to 1.056MHz; various per games or optional
    }
  );
  ENTRY(
    "Data East PCX", {
      DIV_SYSTEM_OPN, 64, 0, 5, // 1.5MHz
      CH(DIV_SYSTEM_PCE, 64, 0, ""),
      // software controlled MSM5205
    }
  );
  ENTRY(
    "Data East PCX (extended channel 3)", {
      DIV_SYSTEM_OPN_EXT, 64, 0, 5, // 1.5MHz
      CH(DIV_SYSTEM_PCE, 64, 0, ""),
      // software controlled MSM5205
    }
  );
  ENTRY(
    "Data East Dark Seal", { // Dark Seal, Crude Buster, Vapor Trail, etc
      DIV_SYSTEM_YM2151, 64, 0, 0, // 3.580MHz (32.22MHz / 9)
      DIV_SYSTEM_OPN, 64, 0, 2, // 4.0275MHz (32.22MHz / 8); optional
      DIV_SYSTEM_MSM6295, 64, 0, 0, // 1.007MHz (32.22MHz / 32)
      DIV_SYSTEM_MSM6295, 64, 0, 8, // 2.014MHz (32.22MHz / 16); optional
      // HuC6280 is for control them, internal sound isn't used
    }
  );
  ENTRY(
    "Data East Dark Seal (extended channel 3)", { // Dark Seal, Crude Buster, Vapor Trail, etc
      DIV_SYSTEM_YM2151, 64, 0, 0, // 3.580MHz (32.22MHz / 9)
      DIV_SYSTEM_OPN_EXT, 64, 0, 2, // 4.0275MHz (32.22MHz / 8); optional
      DIV_SYSTEM_MSM6295, 64, 0, 0, // 1.007MHz (32.22MHz / 32)
      DIV_SYSTEM_MSM6295, 64, 0, 8, // 2.014MHz (32.22MHz / 16); optional
      // HuC6280 is for control them, internal sound isn't used
    }
  );
  ENTRY(
    "Data East Deco 156", {
      DIV_SYSTEM_MSM6295, 64, 0, 0, // 1 or 1.007MHz (32.22MHz / 32); various per games
      DIV_SYSTEM_MSM6295, 64, 0, 8, // 1 or 2 or 2.014MHz (32.22MHz / 16); various per games
    }
  );
  ENTRY(
    "Data East MLC", {
      DIV_SYSTEM_YMZ280B, 64, 0, 5, // 14MHz
    }
  );
  ENTRY(
    "SNK Ikari Warriors", {
      DIV_SYSTEM_OPL, 64, 0, 2,
      DIV_SYSTEM_OPL, 64, 0, 2,
    }
  );
  ENTRY(
    "SNK Ikari Warriors (drums mode on first OPL)", {
      DIV_SYSTEM_OPL_DRUMS, 64, 0, 2,
      DIV_SYSTEM_OPL, 64, 0, 2,
    }
  );
  ENTRY(
    "SNK Ikari Warriors (drums mode on second OPL)", {
      DIV_SYSTEM_OPL, 64, 0, 2,
      DIV_SYSTEM_OPL_DRUMS, 64, 0, 2,
    }
  );
  ENTRY(
    "SNK Ikari Warriors (drums mode on both OPLs)", {
      DIV_SYSTEM_OPL_DRUMS, 64, 0, 2,
      DIV_SYSTEM_OPL_DRUMS, 64, 0, 2,
    }
  );
  ENTRY(
    "SNK Triple Z80", {
      DIV_SYSTEM_Y8950, 64, 0, 2,
      DIV_SYSTEM_OPL, 64, 0, 2,
    }
  );
  ENTRY(
    "SNK Triple Z80 (drums mode on Y8950)", {
      DIV_SYSTEM_Y8950_DRUMS, 64, 0, 2,
      DIV_SYSTEM_OPL, 64, 0, 2,
    }
  );
  ENTRY(
    "SNK Triple Z80 (drums mode on OPL)", {
      DIV_SYSTEM_Y8950, 64, 0, 2,
      DIV_SYSTEM_OPL_DRUMS, 64, 0, 2,
    }
  );
  ENTRY(
    "SNK Triple Z80 (drums mode on Y8950 and OPL)", {
      DIV_SYSTEM_Y8950_DRUMS, 64, 0, 2,
      DIV_SYSTEM_OPL_DRUMS, 64, 0, 2,
    }
  );
  ENTRY(
    "SNK Chopper I", {
      DIV_SYSTEM_Y8950, 64, 0, 2,
      DIV_SYSTEM_OPL2, 64, 0, 2,
    }
  );
  ENTRY(
    "SNK Chopper I (drums mode on Y8950)", {
      DIV_SYSTEM_Y8950_DRUMS, 64, 0, 2,
      DIV_SYSTEM_OPL2, 64, 0, 2,
    }
  );
  ENTRY(
    "SNK Chopper I (drums mode on OPL2)", {
      DIV_SYSTEM_Y8950, 64, 0, 2,
      DIV_SYSTEM_OPL2_DRUMS, 64, 0, 2,
    }
  );
  ENTRY(
    "SNK Chopper I (drums mode on Y8950 and OPL2)", {
      DIV_SYSTEM_Y8950_DRUMS, 64, 0, 2,
      DIV_SYSTEM_OPL2_DRUMS, 64, 0, 2,
    }
  );
  ENTRY(
    "SNK Touchdown Fever", {
      DIV_SYSTEM_OPL, 64, 0, 2,
      DIV_SYSTEM_Y8950, 64, 0, 2,
    }
  );
  ENTRY(
    "SNK Touchdown Fever (drums mode on OPL)", {
      DIV_SYSTEM_OPL_DRUMS, 64, 0, 2,
      DIV_SYSTEM_Y8950, 64, 0, 2,
    }
  );
  ENTRY(
    "SNK Touchdown Fever (drums mode on Y8950)", {
      DIV_SYSTEM_OPL, 64, 0, 2,
      DIV_SYSTEM_Y8950_DRUMS, 64, 0, 2,
    }
  );
  ENTRY(
    "SNK Touchdown Fever (drums mode on OPL and Y8950)", {
      DIV_SYSTEM_OPL_DRUMS, 64, 0, 2,
      DIV_SYSTEM_Y8950_DRUMS, 64, 0, 2,
    }
  );
  ENTRY(
    "Alpha denshi Alpha-68K", {
      DIV_SYSTEM_OPN, 64, 0, 3, // 3MHz
      DIV_SYSTEM_OPLL, 64, 0, 0, // 3.58MHz
      DIV_SYSTEM_PCM_DAC, 64, 0, 7613|(7<<16), // software controlled 8 bit DAC
    }
  );
  ENTRY(
    "Alpha denshi Alpha-68K (extended channel 3)", {
      DIV_SYSTEM_OPN_EXT, 64, 0, 3, // 3MHz
      DIV_SYSTEM_OPLL, 64, 0, 0, // 3.58MHz
      DIV_SYSTEM_PCM_DAC, 64, 0, 7613|(7<<16), // software controlled 8 bit DAC
    }
  );
  ENTRY(
    "Alpha denshi Alpha-68K (drums mode)", {
      DIV_SYSTEM_OPN, 64, 0, 3, // 3MHz
      DIV_SYSTEM_OPLL_DRUMS, 64, 0, 0, // 3.58MHz
      DIV_SYSTEM_PCM_DAC, 64, 0, 7613|(7<<16), // software controlled 8 bit DAC
    }
  );
  ENTRY(
    "Alpha denshi Alpha-68K (extended channel 3; drums mode)", {
      DIV_SYSTEM_OPN_EXT, 64, 0, 3, // 3MHz
      DIV_SYSTEM_OPLL_DRUMS, 64, 0, 0, // 3.58MHz
      DIV_SYSTEM_PCM_DAC, 64, 0, 7613|(7<<16), // software controlled 8 bit DAC
    }
  );
  ENTRY(
    "Neo Geo MVS", {
      CH(DIV_SYSTEM_YM2610_FULL, 64, 0, ""),
    }
  );
  ENTRY(
    "Neo Geo MVS (extended channel 2)", {
      CH(DIV_SYSTEM_YM2610_FULL_EXT, 64, 0, ""),
    }
  );
  ENTRY(
    "Nichibutsu Mag Max", {
      DIV_SYSTEM_AY8910, 64, 0, 13,
      DIV_SYSTEM_AY8910, 64, 0, 13,
      DIV_SYSTEM_AY8910, 64, 0, 13,
    }
  );
  ENTRY(
    "Namco (3-channel WSG)", { // Pac-Man, Galaga, Xevious, etc
      CH(DIV_SYSTEM_NAMCO, 64, 0, ""),
    }
  );
  ENTRY(
    "Namco Mappy", { // Mappy, Super Pac-Man, Libble Rabble, etc
      CH(DIV_SYSTEM_NAMCO_15XX, 64, 0, ""),
    }
  );
  ENTRY(
    "Namco Pac-Land", { // Pac-Land, Baraduke, Sky kid, etc
      CH(DIV_SYSTEM_NAMCO_CUS30, 64, 0, ""),
    }
  );
  ENTRY(
    "Namco System 86", { // without expansion board case; Hopping Mappy, etc
      CH(DIV_SYSTEM_YM2151, 64, 0, ""),
      CH(DIV_SYSTEM_NAMCO_CUS30, 64, 0, ""),
    }
  );
  ENTRY(
    "Namco Thunder Ceptor", {
      CH(DIV_SYSTEM_YM2151, 64, 0, ""),
      CH(DIV_SYSTEM_NAMCO_CUS30, 64, 0, ""),
      DIV_SYSTEM_PCM_DAC, 64, 0, 7999|(7<<16), // M65C02 software driven, correct sample rate?
    }
  );
  ENTRY(
    "Namco System 1", {
      CH(DIV_SYSTEM_YM2151, 64, 0, ""),
      CH(DIV_SYSTEM_NAMCO_CUS30, 64, 0, ""),
      DIV_SYSTEM_PCM_DAC, 64, 0, 5999|(7<<16), // sample rate verified from https://github.com/mamedev/mame/blob/master/src/devices/sound/n63701x.cpp
      DIV_SYSTEM_PCM_DAC, 64, 0, 5999|(7<<16), // ""
    }
  );
  ENTRY(
    "Taito Arcade", {
      CH(DIV_SYSTEM_YM2610B, 64, 0, ""),
    }
  );
  ENTRY(
    "Taito Arcade (extended channel 3)", {
      CH(DIV_SYSTEM_YM2610B_EXT, 64, 0, ""),
    }
  );
  ENTRY(
    "Seta 1", {
      CH(DIV_SYSTEM_X1_010, 64, 0, ""),
    }
  );
  ENTRY(
    "Seta 1 + FM addon", {
      CH(DIV_SYSTEM_X1_010, 64, 0, ""),
      DIV_SYSTEM_YM2612, 64, 0, 2, // Discrete YM3438
    }
  );
  ENTRY(
    "Seta 1 + FM addon (extended channel 3)", {
      CH(DIV_SYSTEM_X1_010, 64, 0, ""),
      DIV_SYSTEM_YM2612_EXT, 64, 0, 2, // Discrete YM3438
    }
  );
  ENTRY(
    "Seta 2", {
      DIV_SYSTEM_X1_010, 64, 0, 1,
    }
  );
  ENTRY(
    "Sammy/Seta/Visco SSV", {
      CH(DIV_SYSTEM_ES5506, 64, 0, "channels=31")
    }
  );
  ENTRY(
    "Cave 68000", {
      CH(DIV_SYSTEM_YMZ280B, 64, 0, ""),
    }
  );
  ENTRY(
    "Coreland Cyber Tank", {
      DIV_SYSTEM_Y8950, 64, -127, 0, // 3.58MHz, Left output
      DIV_SYSTEM_Y8950, 64, 127, 0, // 3.58MHz, Right output
    }
  );
  ENTRY(
    "Coreland Cyber Tank (drums mode)", {
      DIV_SYSTEM_Y8950, 64, -127, 0, // 3.58MHz, Left output
      DIV_SYSTEM_Y8950, 64, 127, 0, // 3.58MHz, Right output
    }
  );
  ENTRY(
    "ICE Skimaxx", {
      DIV_SYSTEM_MSM6295, 64, -127, 130, // 4MHz, Left output
      DIV_SYSTEM_MSM6295, 64, 127, 130, // 4MHz, Right output
      DIV_SYSTEM_MSM6295, 64, -127, 8, // 2MHz, Left output
      DIV_SYSTEM_MSM6295, 64, 127, 8, // 2MHz, Right output
    }
  );
  ENTRY(
    "Toaplan 1", {
      DIV_SYSTEM_OPL2, 64, 0, 5, // 3.5MHz
    }
  );
  ENTRY(
    "Toaplan 1 (drums mode)", {
      DIV_SYSTEM_OPL2_DRUMS, 64, 0, 5, // 3.5MHz
    }
  );
  ENTRY(
    "Dynax/Nakanihon 3rd generation hardware", {
      DIV_SYSTEM_AY8910, 64, 0, 0, // AY or YM, optional - 1.79MHz or 3.58MHz; various per game
      CH(DIV_SYSTEM_OPLL, 64, 0, ""),
      DIV_SYSTEM_MSM6295, 64, 0, 6, // 1.023MHz mostly
    }
  );
  ENTRY(
    "Dynax/Nakanihon 3rd generation hardware (drums mode)", {
      DIV_SYSTEM_AY8910, 64, 0, 0, // AY or YM, optional - 1.79MHz or 3.58MHz; various per game
      CH(DIV_SYSTEM_OPLL_DRUMS, 64, 0, ""),
      DIV_SYSTEM_MSM6295, 64, 0, 6, // 1.023MHz mostly
    }
  );
  ENTRY(
    "Dynax/Nakanihon Real Break", {
      CH(DIV_SYSTEM_OPLL, 64, 0, ""),
      CH(DIV_SYSTEM_YMZ280B, 64, 0, ""),
    }
  );
  ENTRY(
    "Dynax/Nakanihon Real Break (drums mode)", {
      CH(DIV_SYSTEM_OPLL_DRUMS, 64, 0, ""),
      CH(DIV_SYSTEM_YMZ280B, 64, 0, ""),
    }
  );
  ENTRY(
    "Irem M72", {
      CH(DIV_SYSTEM_YM2151, 64, 0, ""),
      DIV_SYSTEM_PCM_DAC, 64, 0, 7811|(7<<16),
    }
  );
  CATEGORY_END;

  CATEGORY_BEGIN("DefleMask-compatible","these configurations are compatible with DefleMask.\nselect this if you need to save as .dmf or work with that program.");
  ENTRY(
    "Sega Genesis", {
      CH(DIV_SYSTEM_YM2612, 64, 0, ""),
      CH(DIV_SYSTEM_SMS, 32, 0, ""),
    }
  );
  ENTRY(
    "Sega Genesis (extended channel 3)", {
      CH(DIV_SYSTEM_YM2612_EXT, 64, 0, ""),
      CH(DIV_SYSTEM_SMS, 32, 0, ""),
    }
  );
  ENTRY(
    "Sega Master System", {
      CH(DIV_SYSTEM_SMS, 64, 0, ""),
    }
  );
  ENTRY(
    "Sega Master System (with FM expansion)", {
      CH(DIV_SYSTEM_SMS, 64, 0, ""),
      CH(DIV_SYSTEM_OPLL, 64, 0, ""),
    }
  );
  ENTRY(
    "Game Boy", {
      CH(DIV_SYSTEM_GB, 64, 0, ""),
    }
  );
  ENTRY(
    "NEC PC Engine/TurboGrafx-16", {
      CH(DIV_SYSTEM_PCE, 64, 0, ""),
    }
  );
  ENTRY(
    "NES", {
      CH(DIV_SYSTEM_NES, 64, 0, ""),
    }
  );
  ENTRY(
    "Famicom with Konami VRC7", {
      CH(DIV_SYSTEM_NES, 64, 0, ""),
      CH(DIV_SYSTEM_VRC7, 64, 0, ""),
    }
  );
  ENTRY(
    "Famicom Disk System", {
      CH(DIV_SYSTEM_NES, 64, 0, ""),
      CH(DIV_SYSTEM_FDS, 64, 0, ""),
    }
  );
  ENTRY(
    "Commodore 64 (6581 SID)", {
      DIV_SYSTEM_C64_6581, 64, 0, 1,
    }
  );
  ENTRY(
    "Commodore 64 (8580 SID)", {
      DIV_SYSTEM_C64_8580, 64, 0, 1,
    }
  );
  ENTRY(
    "Arcade (YM2151 and SegaPCM)", {
      CH(DIV_SYSTEM_YM2151, 64, 0, ""),
      CH(DIV_SYSTEM_SEGAPCM_COMPAT, 64, 0, ""),
    }
  );
  ENTRY(
    "Neo Geo CD", {
      CH(DIV_SYSTEM_YM2610, 64, 0, ""),
    }
  );
  ENTRY(
    "Neo Geo CD (extended channel 2)", {
      CH(DIV_SYSTEM_YM2610_EXT, 64, 0, ""),
    }
  );
  CATEGORY_END;
  */
}

FurnaceGUISysDef::FurnaceGUISysDef(const char* n, std::initializer_list<int> def):
  name(n) {
  std::vector<int> uncompiled=def;
  int index=0;

  for (size_t i=0; i<uncompiled.size(); i+=4) {
    if (uncompiled[i]==0) break;

    DivConfig oldFlags;
    DivEngine::convertOldFlags(uncompiled[i+3],oldFlags,(DivSystem)uncompiled[i]);

    definition+=fmt::sprintf(
      "id%d=%d\nvol%d=%d\npan%d=%d\nflags%d=%s\n",
      index,
      DivEngine::systemToFileFur((DivSystem)uncompiled[i]),
      index,
      uncompiled[i+1],
      index,
      uncompiled[i+2],
      index,
      oldFlags.toBase64()
    );
    index++;
  }
}

FurnaceGUISysDef::FurnaceGUISysDef(const char* n, std::initializer_list<FurnaceGUISysDefChip> def):
  name(n) {
  std::vector<FurnaceGUISysDefChip> uncompiled=def;
  int index=0;
  for (FurnaceGUISysDefChip& i: uncompiled) {
    definition+=fmt::sprintf(
      "id%d=%d\nvol%d=%d\npan%d=%d\nflags%d=%s\n",
      index,
      DivEngine::systemToFileFur(i.sys),
      index,
      i.vol,
      index,
      i.pan,
      index,
      taEncodeBase64(i.flags)
    );
    index++;
  }
}
