// ===========================================================================
// Adnd1 - rules/subracelevels.h
// The UA Character Race Table II
// (R324) - the class level limits
// per sub-race, keyed by the vital
// ability score. Header-only pins,
// the subraces.h pattern: pure data
// plus accessors, no engine
// callers yet (the leveling site
// reads these; the wiring rounds
// follow).
//
// UNEARTHED ARCANA pp. 8-9: the six
// sub-tables - II.A dwarves, II.B
// gnomes, II.C elves (the two
// printed blocks), II.D half-elves,
// II.E halflings, II.F half-orcs -
// 47 columns in all, the U entries,
// the footnoted ability gates and
// their escalation riders, and the
// single-class +2 rule. Humans have
// no sub-table (the print lists no
// limits); a null column means the
// caller reads no limit - the
// unlimited-by-omission classes
// (elven cavaliers, half-elf bards)
// ride the same null.
//
// THE KEY: the vital ability score
// as score*1000 (15000 = STR 15);
// exceptional strength 18/01-18/99
// as 18010-18990 and 18/00 (the
// top of the range) as 18999, so
// the ladder sorts exactly as the
// print rows it: 18 < 18/01 < ...
// < 18/99 < 18/00 < 19.
//
// THE READS: level 0 = U (the
// print unlimited: effectively
// unlimited for thieves and
// clerics, up to the class ceiling
// for druids and assassins - the
// caller concern). A score below
// the first row reads the first row
// (the print floor rule: a dwarven
// assassin with STR 14 or less
// attains 9th). A score between
// rows reads the lower row. The
// vital ability is class-dependent
// (STR: fighter/ranger/assassin,
// INT: magic-user/illusionist,
// WIS: cleric/druid, DEX: thief) -
// the caller passes the key.
// ===========================================================================

#pragma once

#include "subraces.h"

namespace rules {

// One print column: the ladder rows
// (ascending keys) with the level
// (0 = U) and the footnote id (0 =
// none) per row.
struct RaceLevelColumn {
    int n;
    const int* keys;
    const int* levels;
    const int* fns;   // may be null:
                       // no footnotes
};

// The strength-key encoder: score
// != 18 -> score*1000; pct < 0 ->
// 18000 (no exceptional roll);
// pct 1-99 -> 18000+pct*10;
// pct 100 (printed 18/00) ->
// 18999.
inline int subraceStrengthLevelKey(
        int score, int pct) {
    if (score != 18) return score*1000;
    if (pct < 0) return 18000;
    if (pct >= 100) return 18999;
    return 18000 + pct*10;
}

// The print columns, per sub-table.
// Every array is a literal of the
// printed rows; the audit re-reads
// them against the OCR.

// ---- II.A: dwarves (UA p.8) ----
static const int kIiaClericK[] = {
    15000, 16000, 17000, 18000, 19000, 20000, 21000
};
static const int kIiaClericL[] = { 8, 9, 10, 11, 13, 16, 16 };
static const RaceLevelColumn kIiaCleric = {
    7, kIiaClericK, kIiaClericL, 0 };
static const int kIiaFighterHillK[] = {
    15000, 16000, 17000, 18000, 18990, 18999, 19000, 20000, 21000
};
static const int kIiaFighterHillL[] = { 6, 6, 7, 8, 8, 9, 10, 12, 15 };
static const RaceLevelColumn kIiaFighterHill = {
    9, kIiaFighterHillK, kIiaFighterHillL, 0 };
static const int kIiaFighterMGK[] = {
    15000, 16000, 17000, 18000, 18990, 18999, 19000, 20000, 21000
};
static const int kIiaFighterMGL[] = { 7, 7, 8, 9, 9, 10, 11, 13, 16 };
static const RaceLevelColumn kIiaFighterMG = {
    9, kIiaFighterMGK, kIiaFighterMGL, 0 };
static const int kIiaThiefK[] = {
    15000, 16000, 17000, 18000, 19000, 20000, 21000
};
static const int kIiaThiefL[] = { 0, 0, 0, 0, 0, 0, 0 };
static const RaceLevelColumn kIiaThief = {
    7, kIiaThiefK, kIiaThiefL, 0 };
static const int kIiaAssassinK[] = {
    15000, 16000, 17000, 18000, 18990, 18999, 19000, 20000, 21000
};
static const int kIiaAssassinL[] = { 9, 9, 9, 9, 11, 12, 12, 12, 12 };
static const int kIiaAssassinF[] = { 0, 0, 0, 0, 1, 2, 2, 2, 2 };
static const RaceLevelColumn kIiaAssassin = {
    9, kIiaAssassinK, kIiaAssassinL, kIiaAssassinF };

// ---- II.B: gnomes (UA p.8) ----
static const int kIibClericK[] = {
    15000, 16000, 17000, 18000, 19000, 20000, 21000
};
static const int kIibClericL[] = { 7, 8, 9, 10, 12, 14, 14 };
static const RaceLevelColumn kIibCleric = {
    7, kIibClericK, kIibClericL, 0 };
static const int kIibFighterK[] = {
    15000, 16000, 17000, 18000, 18500, 18750, 18990, 19000, 20000, 21000
};
static const int kIibFighterL[] = { 5, 5, 5, 5, 6, 7, 8, 9, 9, 9 };
static const RaceLevelColumn kIibFighter = {
    10, kIibFighterK, kIibFighterL, 0 };
static const int kIibIllusionistK[] = {
    15000, 16000, 17000, 18000, 19000, 20000, 21000
};
static const int kIibIllusionistL[] = { 6, 6, 6, 7, 8, 10, 13 };
static const RaceLevelColumn kIibIllusionist = {
    7, kIibIllusionistK, kIibIllusionistL, 0 };
static const int kIibThiefK[] = {
    15000, 16000, 17000, 18000, 19000, 20000, 21000
};
static const int kIibThiefL[] = { 0, 0, 0, 0, 0, 0, 0 };
static const RaceLevelColumn kIibThief = {
    7, kIibThiefK, kIibThiefL, 0 };
static const int kIibAssassinK[] = {
    15000, 16000, 17000, 18000, 18500, 18750, 18990, 19000, 20000, 21000
};
static const int kIibAssassinL[] = { 8, 8, 8, 8, 9, 10, 10, 10, 10, 10 };
static const int kIibAssassinF[] = { 0, 0, 0, 0, 1, 2, 2, 2, 2, 2 };
static const RaceLevelColumn kIibAssassin = {
    10, kIibAssassinK, kIibAssassinL, kIibAssassinF };

// ---- II.C: elves, block 1 (UA p.8) ----
static const int kIicClericDMK[] = {
    12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000, 20000, 21000
};
static const int kIicClericDML[] = { 4, 5, 6, 7, 7, 7, 7, 7, 7, 7 };
static const RaceLevelColumn kIicClericDM = {
    10, kIicClericDMK, kIicClericDML, 0 };
static const int kIicClericDFK[] = {
    12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000, 20000, 21000
};
static const int kIicClericDFL[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static const RaceLevelColumn kIicClericDF = {
    10, kIicClericDFK, kIicClericDFL, 0 };
static const int kIicClericAOK[] = {
    12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000, 20000, 21000
};
static const int kIicClericAOL[] = { 7, 7, 7, 7, 8, 9, 10, 11, 12, 12 };
static const RaceLevelColumn kIicClericAO = {
    10, kIicClericAOK, kIicClericAOL, 0 };
static const int kIicDruidWildK[] = {
    12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000, 20000, 21000
};
static const int kIicDruidWildL[] = {
    10, 10, 10, 10, 10, 10, 11, 12, 14, 17
};
static const int kIicDruidWildF[] = { 0, 0, 0, 0, 0, 0, 1, 1, 1, 2 };
static const RaceLevelColumn kIicDruidWild = {
    10, kIicDruidWildK, kIicDruidWildL, kIicDruidWildF };
static const int kIicDruidAOK[] = {
    12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000, 20000, 21000
};
static const int kIicDruidAOL[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static const RaceLevelColumn kIicDruidAO = {
    10, kIicDruidAOK, kIicDruidAOL, 0 };
static const int kIicFighterDMK[] = {
    12000, 13000, 14000, 15000, 16000, 17000, 18000, 18750, 18900, 18990,
    18999, 19000, 20000
};
static const int kIicFighterDML[] = {
    7, 8, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10
};
static const RaceLevelColumn kIicFighterDM = {
    13, kIicFighterDMK, kIicFighterDML, 0 };
static const int kIicFighterDFK[] = {
    12000, 13000, 14000, 15000, 16000, 17000, 18000, 18750, 18900, 18990,
    18999, 19000, 20000
};
static const int kIicFighterDFL[] = {
    9, 10, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12
};
static const RaceLevelColumn kIicFighterDF = {
    13, kIicFighterDFK, kIicFighterDFL, 0 };
static const int kIicFighterGHK[] = {
    12000, 13000, 14000, 15000, 16000, 17000, 18000, 18750, 18900, 18990,
    18999, 19000, 20000
};
static const int kIicFighterGHL[] = {
    5, 5, 5, 5, 5, 5, 6, 7, 8, 9, 10, 11, 11
};
static const RaceLevelColumn kIicFighterGH = {
    13, kIicFighterGHK, kIicFighterGHL, 0 };
static const int kIicFighterVaK[] = {
    12000, 13000, 14000, 15000, 16000, 17000, 18000, 18750, 18900, 18990,
    18999, 19000, 20000
};
static const int kIicFighterVaL[] = {
    5, 5, 5, 5, 5, 5, 6, 6, 8, 9, 10, 11, 13
};
static const RaceLevelColumn kIicFighterVa = {
    13, kIicFighterVaK, kIicFighterVaL, 0 };
static const int kIicFighterWiK[] = {
    12000, 13000, 14000, 15000, 16000, 17000, 18000, 18750, 18900, 18990,
    18999, 19000, 20000
};
static const int kIicFighterWiL[] = {
    7, 7, 7, 7, 7, 7, 8, 8, 10, 11, 12, 13, 13
};
static const RaceLevelColumn kIicFighterWi = {
    13, kIicFighterWiK, kIicFighterWiL, 0 };
static const int kIicFighterWoK[] = {
    12000, 13000, 14000, 15000, 16000, 17000, 18000, 18750, 18900, 18990,
    18999, 19000, 20000
};
static const int kIicFighterWoL[] = {
    6, 6, 6, 6, 6, 6, 7, 8, 9, 10, 11, 11, 14
};
static const RaceLevelColumn kIicFighterWo = {
    13, kIicFighterWoK, kIicFighterWoL, 0 };

// ---- II.C: elves, block 2 (UA p.9) ----
static const int kIicMuDMK[] = { 17000, 18000, 19000, 20000, 21000, 22000 };
static const int kIicMuDML[] = { 12, 12, 13, 15, 18, 18 };
static const RaceLevelColumn kIicMuDM = {
    6, kIicMuDMK, kIicMuDML, 0 };
static const int kIicMuDFK[] = { 17000, 18000, 19000, 20000, 21000, 22000 };
static const int kIicMuDFL[] = { 5, 5, 7, 9, 11, 11 };
static const RaceLevelColumn kIicMuDF = {
    6, kIicMuDFK, kIicMuDFL, 0 };
static const int kIicMuGrayK[] = { 17000, 18000, 19000, 20000, 21000, 22000 };
static const int kIicMuGrayL[] = { 11, 11, 12, 13, 15, 18 };
static const RaceLevelColumn kIicMuGray = {
    6, kIicMuGrayK, kIicMuGrayL, 0 };
static const int kIicMuHighK[] = { 17000, 18000, 19000, 20000, 21000, 22000 };
static const int kIicMuHighL[] = { 10, 10, 11, 12, 14, 17 };
static const RaceLevelColumn kIicMuHigh = {
    6, kIicMuHighK, kIicMuHighL, 0 };
static const int kIicMuValK[] = { 17000, 18000, 19000, 20000, 21000, 22000 };
static const int kIicMuValL[] = { 11, 11, 12, 13, 15, 15 };
static const RaceLevelColumn kIicMuVal = {
    6, kIicMuValK, kIicMuValL, 0 };
static const int kIicMuWoodK[] = { 17000, 18000, 19000, 20000, 21000, 22000 };
static const int kIicMuWoodL[] = { 9, 9, 10, 11, 13, 13 };
static const RaceLevelColumn kIicMuWood = {
    6, kIicMuWoodK, kIicMuWoodL, 0 };
static const int kIicThiefK[] = { 17000, 18000, 19000, 20000 };
static const int kIicThiefL[] = { 0, 0, 0, 0 };
static const RaceLevelColumn kIicThief = {
    4, kIicThiefK, kIicThiefL, 0 };
static const int kIicAssassinK[] = {
    18000, 18010, 18510, 18760, 18990, 18999, 19000, 20000
};
static const int kIicAssassinL[] = { 10, 10, 10, 10, 11, 12, 12, 12 };
static const int kIicAssassinF[] = { 0, 0, 0, 0, 3, 3, 4, 5 };
static const RaceLevelColumn kIicAssassin = {
    8, kIicAssassinK, kIicAssassinL, kIicAssassinF };
static const int kIicRangerK[] = {
    18000, 18010, 18510, 18760, 18990, 18999, 19000, 20000
};
static const int kIicRangerL[] = { 6, 7, 9, 10, 10, 10, 12, 14 };
static const int kIicRangerF[] = { 0, 1, 2, 3, 3, 3, 4, 4 };
static const RaceLevelColumn kIicRanger = {
    8, kIicRangerK, kIicRangerL, kIicRangerF };

// ---- II.D: half-elves (UA p.9) ----
static const int kIidClericK[] = { 15000, 16000, 17000, 18000, 19000, 20000 };
static const int kIidClericL[] = { 5, 6, 7, 8, 10, 12 };
static const RaceLevelColumn kIidCleric = {
    6, kIidClericK, kIidClericL, 0 };
static const int kIidDruidK[] = { 15000, 16000, 17000, 18000, 19000, 20000 };
static const int kIidDruidL[] = { 0, 0, 0, 0, 0, 0 };
static const RaceLevelColumn kIidDruid = {
    6, kIidDruidK, kIidDruidL, 0 };
static const int kIidFighterK[] = {
    15000, 16000, 17000, 18000, 18900, 18990, 18999, 19000, 20000
};
static const int kIidFighterL[] = { 6, 6, 7, 7, 8, 9, 10, 11, 13 };
static const RaceLevelColumn kIidFighter = {
    9, kIidFighterK, kIidFighterL, 0 };
static const int kIidRangerK[] = {
    15000, 16000, 17000, 18000, 18900, 18990, 18999, 19000, 20000
};
static const int kIidRangerL[] = { 6, 6, 7, 8, 9, 10, 11, 15, 15 };
static const int kIidRangerF[] = { 0, 0, 0, 0, 1, 1, 2, 3, 3 };
static const RaceLevelColumn kIidRanger = {
    9, kIidRangerK, kIidRangerL, kIidRangerF };
static const int kIidMUK[] = { 15000, 16000, 17000, 18000, 19000, 20000 };
static const int kIidMUL[] = { 7, 7, 7, 8, 8, 8 };
static const RaceLevelColumn kIidMU = {
    6, kIidMUK, kIidMUL, 0 };
static const int kIidThiefK[] = { 15000, 16000, 17000, 18000, 19000, 20000 };
static const int kIidThiefL[] = { 0, 0, 0, 0, 0, 0 };
static const RaceLevelColumn kIidThief = {
    6, kIidThiefK, kIidThiefL, 0 };
static const int kIidAssassinK[] = {
    15000, 16000, 17000, 18000, 18900, 18990, 18999, 19000, 20000
};
static const int kIidAssassinL[] = { 11, 11, 11, 11, 11, 11, 11, 11, 11 };
static const RaceLevelColumn kIidAssassin = {
    9, kIidAssassinK, kIidAssassinL, 0 };

// ---- II.E: halflings (UA p.9) ----
static const int kIieClericK[] = { 15000, 16000, 17000, 18000, 19000, 20000 };
static const int kIieClericL[] = { 4, 4, 5, 6, 8, 10 };
static const RaceLevelColumn kIieCleric = {
    6, kIieClericK, kIieClericL, 0 };
static const int kIieDruidK[] = { 15000, 16000, 17000, 18000, 19000, 20000 };
static const int kIieDruidL[] = { 6, 7, 9, 11, 13, 13 };
static const int kIieDruidF[] = { 1, 2, 3, 4, 5, 5 };
static const RaceLevelColumn kIieDruid = {
    6, kIieDruidK, kIieDruidL, kIieDruidF };
static const int kIieFighterHFK[] = {
    15000, 16000, 17000, 18000, 18500, 18900, 19000, 20000
};
static const int kIieFighterHFL[] = { 4, 4, 5, 5, 6, 7, 8, 8 };
static const RaceLevelColumn kIieFighterHF = {
    8, kIieFighterHFK, kIieFighterHFL, 0 };
static const int kIieFighterStK[] = {
    15000, 16000, 17000, 18000, 18500, 18900, 19000, 20000
};
static const int kIieFighterStL[] = { 5, 5, 6, 6, 7, 8, 9, 9 };
static const RaceLevelColumn kIieFighterSt = {
    8, kIieFighterStK, kIieFighterStL, 0 };
static const int kIieFighterTFK[] = {
    15000, 16000, 17000, 18000, 18500, 18900, 19000, 20000
};
static const int kIieFighterTFL[] = { 6, 6, 7, 7, 8, 9, 10, 10 };
static const RaceLevelColumn kIieFighterTF = {
    8, kIieFighterTFK, kIieFighterTFL, 0 };
static const int kIieThiefK[] = { 15000, 16000, 17000, 18000, 19000, 20000 };
static const int kIieThiefL[] = { 0, 0, 0, 0, 0, 0 };
static const RaceLevelColumn kIieThief = {
    6, kIieThiefK, kIieThiefL, 0 };

// ---- II.F: half-orcs (UA p.9) ----
static const int kIifClericK[] = {
    14000, 15000, 16000, 17000, 18000, 19000, 20000, 21000
};
static const int kIifClericL[] = { 4, 5, 6, 7, 7, 7, 7, 7 };
static const RaceLevelColumn kIifCleric = {
    8, kIifClericK, kIifClericL, 0 };
static const int kIifFighterK[] = {
    14000, 15000, 16000, 17000, 18000, 18990, 18999, 19000, 20000, 21000
};
static const int kIifFighterL[] = { 10, 10, 10, 10, 10, 10, 11, 12, 14, 17 };
static const RaceLevelColumn kIifFighter = {
    10, kIifFighterK, kIifFighterL, 0 };
static const int kIifThiefK[] = {
    14000, 15000, 16000, 17000, 18000, 19000, 20000, 21000
};
static const int kIifThiefL[] = { 8, 9, 10, 11, 11, 11, 11, 11 };
static const RaceLevelColumn kIifThief = {
    8, kIifThiefK, kIifThiefL, 0 };
static const int kIifAssassinK[] = {
    14000, 15000, 16000, 17000, 18000, 19000, 20000, 21000
};
static const int kIifAssassinL[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
static const RaceLevelColumn kIifAssassin = {
    8, kIifAssassinK, kIifAssassinL, 0 };
// ---------------------------------------------------------------------------
// The footnoted ability gates. Each
// gate list holds the extra ability
// minimums a row demands beyond the
// ladder score. orMode 0 = every
// gate must pass; orMode 1 = any one
// (the II.C footnote 6 read:
// intelligence 19 OR wisdom 19).
// ---------------------------------------------------------------------------

struct LevelGate {
    int stat;   // ABILITY_*
    int min;
};

// II.A assassin: fn1 INT 18 DEX 19;
// fn2 INT 19 DEX 19
static const LevelGate kIiaG1[] = {
    { ABILITY_INT, 18 },
    { ABILITY_DEX, 19 } };
static const LevelGate kIiaG2[] = {
    { ABILITY_INT, 19 },
    { ABILITY_DEX, 19 } };
// II.B assassin: fn1 INT 18 DEX 18;
// fn2 INT 19 DEX 19
static const LevelGate kIibG1[] = {
    { ABILITY_INT, 18 },
    { ABILITY_DEX, 18 } };
static const LevelGate kIibG2[] = {
    { ABILITY_INT, 19 },
    { ABILITY_DEX, 19 } };
// II.C druid (the wild-elf column):
// fn1 CHA 18; fn2 CHA 19
static const LevelGate kIicDG1[] = {
    { ABILITY_CHA, 18 } };
static const LevelGate kIicDG2[] = {
    { ABILITY_CHA, 19 } };
// II.C assassin/ranger: fn1-fn5 all
// INT/WIS pairs, fn6 INT 19 or
// WIS 19
static const LevelGate kIicAG1[] = {
    { ABILITY_INT, 15 },
    { ABILITY_WIS, 15 } };
static const LevelGate kIicAG2[] = {
    { ABILITY_INT, 16 },
    { ABILITY_WIS, 16 } };
static const LevelGate kIicAG3[] = {
    { ABILITY_INT, 17 },
    { ABILITY_WIS, 17 } };
static const LevelGate kIicAG4[] = {
    { ABILITY_INT, 18 },
    { ABILITY_WIS, 18 } };
static const LevelGate kIicAG5[] = {
    { ABILITY_INT, 18 },
    { ABILITY_WIS, 19 } };
static const LevelGate kIicAG6[] = {
    { ABILITY_INT, 19 },
    { ABILITY_WIS, 19 } };
// II.D ranger: fn1/fn2 the INT/WIS/
// CON 18 trio, fn3 the 19 trio
static const LevelGate kIidG1[] = {
    { ABILITY_INT, 18 },
    { ABILITY_WIS, 18 },
    { ABILITY_CON, 18 } };
static const LevelGate kIidG3[] = {
    { ABILITY_INT, 19 },
    { ABILITY_WIS, 19 },
    { ABILITY_CON, 19 } };
// II.E druid: the CHA riders
static const LevelGate kIieG1[] = {
    { ABILITY_CHA, 15 } };
static const LevelGate kIieG2[] = {
    { ABILITY_CHA, 15 } };
static const LevelGate kIieG3[] = {
    { ABILITY_CHA, 16 } };
static const LevelGate kIieG4[] = {
    { ABILITY_CHA, 17 } };
static const LevelGate kIieG5[] = {
    { ABILITY_CHA, 19 } };

// The escalation riders (the prose
// reads that lift a limit when a
// second score climbs higher than
// the gate demands).

// II.C ranger fn1: if both INT and
// WIS are greater than 15, 8th
// level.
inline int elfRangerAbove15Level()
    { return 8; }

// II.D ranger fn2 (the 18/00 row):
// if WIS and CON are both greater
// than 18, 12th level; if both are
// greater than 19, 14th.
inline int halfElfRanger19Level()
    { return 12; }
inline int halfElfRanger20Level()
    { return 14; }

// II.E druid fn2-fn4: charisma 16+
// reads 8th, 17+ reads 10th, 18+
// reads 12th.
inline int halflingDruid16Level()
    { return 8; }
inline int halflingDruid17Level()
    { return 10; }
inline int halflingDruid18Level()
    { return 12; }

// ---------------------------------------------------------------------------
// The accessors
// ---------------------------------------------------------------------------

// The column for a sub-race/class
// pair (female splits the dark-elf
// columns). Null = no print column:
// humans, the unlimited-by-omission
// classes, and pairs Table I bars.
inline const RaceLevelColumn*
subraceLevelColumn(CharSubRace s,
                    UaClass c,
                    int female) {
    switch (s) {
        case SUB_DWARF_GRAY:
        case SUB_DWARF_MOUNTAIN:
            switch (c) {
                case UACLASS_CLERIC:
                    return &kIiaCleric;
                case UACLASS_FIGHTER:
                    return
                        &kIiaFighterMG;
                case UACLASS_THIEF:
                    return &kIiaThief;
                case UACLASS_ASSASSIN:
                    return &kIiaAssassin;
                default: return 0;
            }
        case SUB_DWARF_HILL:
            switch (c) {
                case UACLASS_CLERIC:
                    return &kIiaCleric;
                case UACLASS_FIGHTER:
                    return
                        &kIiaFighterHill;
                case UACLASS_THIEF:
                    return &kIiaThief;
                case UACLASS_ASSASSIN:
                    return &kIiaAssassin;
                default: return 0;
            }
        case SUB_GNOME_DEEP:
        case SUB_GNOME_SURFACE:
            switch (c) {
                case UACLASS_CLERIC:
                    return &kIibCleric;
                case UACLASS_FIGHTER:
                    return &kIibFighter;
                case UACLASS_ILLUSIONIST:
                    return
                        &kIibIllusionist;
                case UACLASS_THIEF:
                    return &kIibThief;
                case UACLASS_ASSASSIN:
                    return &kIibAssassin;
                default: return 0;
            }
        case SUB_ELF_DARK:
            switch (c) {
                case UACLASS_CLERIC:
                    return female
                        ? &kIicClericDF
                        : &kIicClericDM;
                case UACLASS_DRUID:
                    return &kIicDruidAO;
                case UACLASS_FIGHTER:
                    return female
                        ? &kIicFighterDF
                        : &kIicFighterDM;
                case UACLASS_MAGIC_USER:
                    return female
                        ? &kIicMuDF
                        : &kIicMuDM;
                case UACLASS_THIEF:
                    return &kIicThief;
                case UACLASS_ASSASSIN:
                    return &kIicAssassin;
                case UACLASS_RANGER:
                    return &kIicRanger;
                default: return 0;
            }
        case SUB_ELF_GRAY:
        case SUB_ELF_HIGH:
            switch (c) {
                case UACLASS_CLERIC:
                    return &kIicClericAO;
                case UACLASS_DRUID:
                    return &kIicDruidAO;
                case UACLASS_FIGHTER:
                    return &kIicFighterGH;
                case UACLASS_MAGIC_USER:
                    return (s == SUB_ELF_GRAY)
                        ? &kIicMuGray
                        : &kIicMuHigh;
                case UACLASS_THIEF:
                    return &kIicThief;
                case UACLASS_ASSASSIN:
                    return &kIicAssassin;
                case UACLASS_RANGER:
                    return &kIicRanger;
                default: return 0;
            }
        case SUB_ELF_VALLEY:
            switch (c) {
                case UACLASS_CLERIC:
                    return &kIicClericAO;
                case UACLASS_DRUID:
                    return &kIicDruidAO;
                case UACLASS_FIGHTER:
                    return &kIicFighterVa;
                case UACLASS_MAGIC_USER:
                    return &kIicMuVal;
                case UACLASS_THIEF:
                    return &kIicThief;
                case UACLASS_ASSASSIN:
                    return &kIicAssassin;
                default: return 0;
            }
        case SUB_ELF_WILD:
            switch (c) {
                case UACLASS_CLERIC:
                    return &kIicClericAO;
                case UACLASS_DRUID:
                    return &kIicDruidWild;
                case UACLASS_FIGHTER:
                    return &kIicFighterWi;
                case UACLASS_THIEF:
                    return &kIicThief;
                case UACLASS_ASSASSIN:
                    return &kIicAssassin;
                default: return 0;
            }
        case SUB_ELF_WOOD:
            switch (c) {
                case UACLASS_CLERIC:
                    return &kIicClericAO;
                case UACLASS_DRUID:
                    return &kIicDruidAO;
                case UACLASS_FIGHTER:
                    return &kIicFighterWo;
                case UACLASS_MAGIC_USER:
                    return &kIicMuWood;
                case UACLASS_THIEF:
                    return &kIicThief;
                case UACLASS_ASSASSIN:
                    return &kIicAssassin;
                case UACLASS_RANGER:
                    return &kIicRanger;
                default: return 0;
            }
        case SUB_HALFELF:
            switch (c) {
                case UACLASS_CLERIC:
                    return &kIidCleric;
                case UACLASS_DRUID:
                    return &kIidDruid;
                case UACLASS_FIGHTER:
                    return &kIidFighter;
                case UACLASS_RANGER:
                    return &kIidRanger;
                case UACLASS_MAGIC_USER:
                    return &kIidMU;
                case UACLASS_THIEF:
                    return &kIidThief;
                case UACLASS_ASSASSIN:
                    return &kIidAssassin;
                default: return 0;
            }
        case SUB_HALFLING_HAIRFOOT:
        case SUB_HALFLING_STOUT:
        case SUB_HALFLING_TALLFELLOW:
            switch (c) {
                case UACLASS_CLERIC:
                    return &kIieCleric;
                case UACLASS_DRUID:
                    return &kIieDruid;
                case UACLASS_FIGHTER:
                    return
                        (s ==
                         SUB_HALFLING_HAIRFOOT)
                        ? &kIieFighterHF
                        : (s ==
                          SUB_HALFLING_STOUT)
                        ? &kIieFighterSt
                        : &kIieFighterTF;
                case UACLASS_THIEF:
                    return &kIieThief;
                default: return 0;
            }
        case SUB_HALF_ORC:
            switch (c) {
                case UACLASS_CLERIC:
                    return &kIifCleric;
                case UACLASS_FIGHTER:
                    return &kIifFighter;
                case UACLASS_THIEF:
                    return &kIifThief;
                case UACLASS_ASSASSIN:
                    return &kIifAssassin;
                default: return 0;
            }
        case SUB_HUMAN:
        case SUB_NONE:
        default:
            return 0;
    }
}

// The level limit: -1 = no print
// column (no limit pinned); 0 = U.
// The floor rule and the between-
// rows rule both read the lower
// row.
inline int subraceLevelLimit(
        CharSubRace s, UaClass c,
        int key, int female) {
    const RaceLevelColumn* col =
        subraceLevelColumn(s, c, female);
    if (!col) return -1;
    int best = 0;
    for (int i = 0; i < col->n; ++i)
        if (col->keys[i] <= key)
            best = i;
    return col->levels[best];
}

// The footnote id of the row the
// lookup landed on (0 = none).
inline int subraceLevelFootnote(
        CharSubRace s, UaClass c,
        int key, int female) {
    const RaceLevelColumn* col =
        subraceLevelColumn(s, c, female);
    if (!col || !col->fns) return 0;
    int best = 0;
    for (int i = 0; i < col->n; ++i)
        if (col->keys[i] <= key)
            best = i;
    return col->fns[best];
}

// The gate list for a footnote id.
// fn ids are sub-table-local; the
// caller resolves them against the
// same (s, c) pair.
inline void subraceLevelGates(
        CharSubRace s, UaClass c,
        int fn,
        const LevelGate*& g,
        int& n, int& orMode) {
    g = 0; n = 0; orMode = 0;
    switch (s) {
        case SUB_DWARF_GRAY:
        case SUB_DWARF_HILL:
        case SUB_DWARF_MOUNTAIN:
            if (c != UACLASS_ASSASSIN)
                return;
            if (fn == 1) {
                g = kIiaG1; n = 2;
            } else if (fn == 2) {
                g = kIiaG2; n = 2; }
            return;
        case SUB_GNOME_DEEP:
        case SUB_GNOME_SURFACE:
            if (c != UACLASS_ASSASSIN)
                return;
            if (fn == 1) {
                g = kIibG1; n = 2;
            } else if (fn == 2) {
                g = kIibG2; n = 2; }
            return;
        case SUB_ELF_DARK:
        case SUB_ELF_GRAY:
        case SUB_ELF_HIGH:
        case SUB_ELF_VALLEY:
        case SUB_ELF_WILD:
        case SUB_ELF_WOOD:
            if (c == UACLASS_DRUID) {
                if (s != SUB_ELF_WILD)
                    return;
                if (fn == 1) {
                    g = kIicDG1; n = 1;
                } else if (fn == 2) {
                    g = kIicDG2; n = 1;
                }
                return;
            }
            if (c != UACLASS_ASSASSIN
                && c != UACLASS_RANGER)
                return;
            switch (fn) {
                case 1: g = kIicAG1; n = 2;
                    return;
                case 2: g = kIicAG2; n = 2;
                    return;
                case 3: g = kIicAG3; n = 2;
                    return;
                case 4: g = kIicAG4; n = 2;
                    return;
                case 5: g = kIicAG5; n = 2;
                    return;
                case 6: g = kIicAG6; n = 2;
                    orMode = 1; return;
            }
            return;
        case SUB_HALFELF:
            if (c != UACLASS_RANGER)
                return;
            if (fn == 1 || fn == 2) {
                g = kIidG1; n = 3;
            } else if (fn == 3) {
                g = kIidG3; n = 3; }
            return;
        case SUB_HALFLING_HAIRFOOT:
        case SUB_HALFLING_STOUT:
        case SUB_HALFLING_TALLFELLOW:
            if (c != UACLASS_DRUID)
                return;
            switch (fn) {
                case 1: g = kIieG1; n = 1;
                    return;
                case 2: g = kIieG2; n = 1;
                    return;
                case 3: g = kIieG3; n = 1;
                    return;
                case 4: g = kIieG4; n = 1;
                    return;
                case 5: g = kIieG5; n = 1;
                    return;
            }
            return;
        default:
            return;
    }
}

// The single-class +2 rule (the
// Important paragraph): a
// single-classed character whose
// class could have been a
// multi-class choice for the race
// may exceed the table limit by 2.
// The print examples: the hill
// dwarf fighter 18 STR (8 multi,
// 10 single); the 14-STR hill dwarf
// fighter (6 multi, 8 single); the
// half-elf ranger 18s (9 multi, 11
// single); the dwarven assassin
// (no bonus - a dwarf cannot
// multi-class as an assassin). The
// multi-class availability read
// lives with the engine multi-class
// layer (R185/R233) - the caller
// concern.
inline int singleClassLevelBonus()
    { return 2; }

} // namespace rules