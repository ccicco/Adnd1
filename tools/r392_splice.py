# R392: the UA players tables
# manifest sweep - the 20-item
# stretch: the equipment and
# supplies costs table and the
# hand-held weapons table pin
# NEW (rules/uaequip26.h,
# rules/uahandheld.h), the
# weight/damage, missile and
# proficiency tables AMEND (the
# clean PDF read: every hole
# fills, three misdecodes
# reconcile - the garrot L
# damage, the barbarian initial,
# the ranger initial - plus the
# 68th weight/damage row, the
# missile rate/range columns and
# the AC 7-10 ladders, the
# facing-page notes in full); the
# seventeen covered rides close
# the manifest; the census
# 318 -> 319. Pin-era pattern
# (R322). Idempotent; run twice.
import io
import os


NL = '\n'
applied = []
already = []


def rd(p):
    with io.open(p, 'r', encoding='utf-8') as f:
        return f.read()


def wr(p, s):
    with io.open(p, 'w', encoding='utf-8') as f:
        f.write(s)


def clean(block, w):
    for ln in block.split(NL):
        assert len(ln) <= w, 'wide %d: %s' % (
            len(ln), ln)


# ---- (a) the seed entry ----
SEED_ENTRY = r"""
- R391 landed 2026-10-12: commit
  3b87a93 plus the R391b fix,
  census 318, the UA
  Appendix T pole-arm
  nomenclature pin round
  (rules/uaappendt.h): the pp.
  123-129 stretch, seven
  items - two fully clean (the
  spear family, the axe family)
  plus five mechanics-clean with
  flagged holes; nothing fully
  garbles; the R391b lesson: the
  audit cross-checks must
  fail-on-wrong, not fire-on-
  correct - the inverted
  family-coverage check flipped
  >= to <; RED until the fix,
  GREEN after; every audit
  check gets a Python
  simulation pass before
  publish.
"""
SEED_ENTRY = SEED_ENTRY[1:-1]

# ---- (b) rules/uaequip26.h ----
HDR_EC = r"""// ===========================================================================
// ===========================================================================
// Adnd1 - rules/uaequip26.h
// The UA BASIC EQUIPMENT AND SUPPLIES COSTS table (p. 26) pins
// (R392).
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
//
// JUDGMENTs:
//   - the armor roster: four rows in the printed order; the
//     print runs two columns (Bronze Plate 100 gp beside Full
//     Plate 4000 gp), the pairs split in printed order.
//   - the arms roster: 19 rows; "Quarrels for same" pins as
//     printed (the hand-crossbow quarrels); the falchion entry
//     prints across two lines (Sword, falchion, and scabbard) -
//     the split row merges.
//   - the units pin as printed (gp, sp, ep) - uaecArmsUnit
//     names the row unit, the IsSilver/IsElectrum flags carry
//     the same reading.
//
// No holes: the R392 clean PDF read - every cell legible.
// ===========================================================================

#pragma once

namespace rules {

// The armor row count (4).
inline int uaecArmorCount()
    { return 4; }

// The armor row name (printed).
inline const char* uaecArmorName(int i) {
    static const char* const k[4] = {
        "Bronze Plate",
        "Full Plate",
        "Field Plate",
        "Shield, buckler",
    };
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    return k[i];
}

// The armor cost (printed).
inline int uaecArmorCost(int i) {
    static const int k[4] = {
        100, 4000, 2000, 5,
    };
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    return k[i];
}

// The armor cost unit (gp, printed).
inline const char* uaecArmorUnit(int i)
    { (void)i; return "gp"; }

// The arms row count (19 = the 16 new weapons plus the
// quarrels, the scabbard knife and the two swords).
inline int uaecArmsCount()
    { return 19; }

// The arms row name (printed; the falchion two-line entry
// merges).
inline const char* uaecArmsName(int i) {
    static const char* const k[19] = {
        "Aklys", "Atlatl", "Blowgun", "Blowgun Needle", "Caltrop",
        "Crossbow, hand", "Quarrels for same", "Garrot", "Harpoon",
        "Hook Fauchard", "Knife & scabbard", "Lasso", "Man Catcher",
        "Sap", "Spiked Buckler", "Staff Sling",
        "Sword, falchion, and scabbard", "Sword, khopesh", "Whip",
    };
    if (i < 0) i = 0;
    if (i > 18) i = 18;
    return k[i];
}

// The arms cost (printed number).
inline int uaecArmsCost(int i) {
    static const int k[19] = {
        2, 1, 20, 1, 2, 300, 100, 1, 5, 6, 1, 5,
        25, 1, 10, 2, 10, 10, 3,
    };
    if (i < 0) i = 0;
    if (i > 18) i = 18;
    return k[i];
}

// The arms cost unit ("gp", "sp" or "ep", printed).
inline const char* uaecArmsUnit(int i) {
    static const char* const k[19] = {
        "gp", "gp", "gp", "sp", "sp", "gp", "gp",
        "ep", "gp", "gp", "gp", "sp", "gp", "gp",
        "gp", "gp", "gp", "gp", "gp",
    };
    if (i < 0) i = 0;
    if (i > 18) i = 18;
    return k[i];
}

// True when the row price prints in silver pieces (the
// blowgun needle, the caltrop, the lasso).
inline bool uaecArmsPriceIsSilver(int i) {
    static const bool k[19] = {
        0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    };
    if (i < 0) i = 0;
    if (i > 18) i = 18;
    return k[i];
}

// True when the row price prints in electrum pieces (the
// garrot).
inline bool uaecArmsPriceIsElectrum(int i) {
    static const bool k[19] = {
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    if (i < 0) i = 0;
    if (i > 18) i = 18;
    return k[i];
}

}   // namespace rules
"""
HDR_EC = HDR_EC[1:-1]

# ---- (c) rules/uahandheld.h ----
HDR_HH = r"""
// ===========================================================================
// Adnd1 - rules/uahandheld.h
// The UA HAND HELD WEAPON TYPES, GENERAL DATA, AND "TO HIT"
// ADJUSTMENTS table (p. 27) pins (R392).
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
//
// JUDGMENTs:
//   - the roster: 60 rows in the printed order - the R392 clean
//     PDF read, every cell legible, no holes, no attributions.
//   - the n/a cells (the atlatl, blowgun and caltrop rows) pin
//     -1 in the numeric columns, "n/a" in the string columns.
//   - the half-foot glyphs (c. 1 1/2' and the like) normalize to
//     ASCII; the foot and inch marks print straight.
//   - the aklys speed factor prints "4 (+ 1)" - the 4 pins, the
//     +1 bonus rides uahhAklysSpeedBonus.
//   - the Spear and Trident speed factors print the range 6-8,
//     the Whip 5-8 - the min/max accessors carry the ranges.
//   - the footnotes: * = the set-double note (the spetum, the
//     bastard sword), ** = the dismount note (eight rows) -
//     uahhSetDoubleFlag/uahhDismountFlag; the general note: +2
//     vs the back, +4 vs stunned, prone and motionless.
// ===========================================================================

#pragma once

namespace rules {

// The row count (60).
inline int uahhRowCount()
    { return 60; }

// The row name (printed).
inline const char* uahhName(int i) {
    static const char* const k[60] = {
        "Aklys", "Atlatl", "Axe, Battle", "Axe, Hand", "Bardiche",
        "Bec de Corbin", "Bill-Guisarme", "Blowgun", "Bo Stick",
        "Caltrop", "Club", "Dagger", "Fauchard", "Fauchard-Fork",
        "Fist or Open Hand", "Flail, Footman's", "Flail, Horseman's",
        "Fork, Military", "Garrot", "Glaive", "Glaive-Guisarme",
        "Guisarme", "Guisarme-Voulge", "Halberd", "Harpoon",
        "Hammer, Lucern", "Hammer", "Hook Fauchard", "Jo Stick",
        "Knife", "Lance (light horse)", "Lance (medium horse)",
        "Lance (heavy horse)", "Lasso", "Mace, Footman's",
        "Mace, Horseman's", "Man Catcher", "Morning Star", "Partisan",
        "Pick, Military, Footman's", "Pick, Military, Horseman's",
        "Pike, Awl", "Ranseur", "Sap", "Scimitar", "Spear", "Spetum",
        "Spiked Buckler", "Staff, Quarter", "Staff Sling",
        "Sword, Bastard", "Sword, Broad", "Sword, Falchion",
        "Sword, Khopesh", "Sword, Long", "Sword, Short",
        "Sword, Two-handed", "Trident", "Voulge", "Whip",
    };
    if (i < 0) i = 0;
    if (i > 59) i = 59;
    return k[i];
}

// The length (printed; "n/a" = the not-applicable rows).
inline const char* uahhLength(int i) {
    static const char* const k[60] = {
        "c. 2'", "c. 3'", "c. 4'", "c. 1 1/2'", "c. 5'", "c. 6'",
        "8' +", "4'-7'", "c. 5'", "n/a", "c. 3'", "c. 15"", "8' +",
        "8'", "2' +", "c. 4'", "c. 2'", "7' +", "c. 3'", "8' +",
        "8' +", "6' +", "7' +", "5' +", "6'-8'", "5' +", "c. 1 1/2'",
        "8' +", "c. 3'", "c. 1'", "10'", "12'", "c. 14'", "(10'-20')",
        "c. 2 1/2'", "c. 1 1/2'", "8' +", "c. 4'", "7' +", "c. 4'",
        "c. 2'", "18'", "8' +", "1/2'", "c. 3'", "5'-13' +", "8' +",
        "1'", "6'-8'", "5'", "c. 4 1/2'", "c. 3 1/2'", "c. 3 1/2'",
        "c. 3 1/2'", "c. 3 1/2'", "c. 2'", "c. 6'", "4'-8' +", "8' +",
        "8'-20'",
    };
    if (i < 0) i = 0;
    if (i > 59) i = 59;
    return k[i];
}

// The space required (printed; "n/a" = the caltrop).
inline const char* uahhSpaceRequired(int i) {
    static const char* const k[60] = {
        "2'", "1'", "4'", "1'", "5'", "6'", "2'", "1'", "3'", "n/a",
        "1'-3'", "1'", "2'", "2'", "n/a", "6'", "4'", "1'", "1 1/2'",
        "1'", "1'", "2'", "2'", "5'", "1 1/2'", "5'", "2'", "2 1/2'",
        "2'", "1'", "1'", "1'", "1'", "8' +", "4'", "2'", "2 1/2'",
        "5'", "3'", "4'", "2'", "1'", "1'", "1'", "2'", "1'", "1'",
        "2'", "3'", "6'", "4' +", "4'", "3 1/2'", "4'", "3'", "1'",
        "6'", "1'", "2'", "8'-20'",
    };
    if (i < 0) i = 0;
    if (i > 59) i = 59;
    return k[i];
}

// The speed factor minimum; -1 = the n/a rows (the atlatl,
// the blowgun, the caltrop).
inline int uahhSpeedFactorMin(int i) {
    static const int k[60] = {
        4, -1, 7, 4, 9, 9, 10, -1, 3, -1, 4, 2, 8, 8, 1, 7, 6, 7, 2,
        8, 9, 8, 10, 9, 6, 9, 4, 9, 2, 2, 7, 6, 8, 10, 7, 6, 7, 7, 9,
        7, 5, 13, 8, 2, 4, 6, 8, 4, 4, 11, 6, 5, 5, 9, 5, 3, 10, 6,
        10, 5,
    };
    if (i < 0) i = 0;
    if (i > 59) i = 59;
    return k[i];
}

// The speed factor maximum (the Spear and Trident print the
// range 6-8, the Whip 5-8).
inline int uahhSpeedFactorMax(int i) {
    static const int k[60] = {
        4, -1, 7, 4, 9, 9, 10, -1, 3, -1, 4, 2, 8, 8, 1, 7, 6, 7, 2,
        8, 9, 8, 10, 9, 6, 9, 4, 9, 2, 2, 7, 6, 8, 10, 7, 6, 7, 7, 9,
        7, 5, 13, 8, 2, 4, 8, 8, 4, 4, 11, 6, 5, 5, 9, 5, 3, 10, 8,
        10, 8,
    };
    if (i < 0) i = 0;
    if (i > 59) i = 59;
    return k[i];
}

// The aklys speed-factor bonus (the print "4 (+ 1)").
inline int uahhAklysSpeedBonus()
    { return 1; }

// The AC adjustment by AC 0..10 (the full printed ladder).
inline int uahhAcAdjustment(int i, int ac) {
    static const int k[60][11] = {
        { -7, -6, -5, -4, -3, -2, -1, -1, 0, 0, 1 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { -5, -4, -3, -2, -1, -1, 0, 0, 1, 1, 2 },
        { -5, -4, -3, -2, -2, -1, 0, 0, 1, 1, 1 },
        { -3, -2, -2, -1, 0, 0, 1, 1, 2, 2, 3 },
        { 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, -1 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { -13, -11, -9, -7, -5, -3, -1, 0, 1, 0, 3 },
        { -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2 },
        { -7, -6, -5, -4, -3, -2, -1, -1, 0, 0, 1 },
        { -4, -4, -3, -3, -2, -2, 0, 0, 1, 1, 3 },
        { -3, -3, -2, -2, -1, -1, 0, 0, 0, -1, -1 },
        { -2, -2, -1, -1, -1, 0, 0, 0, 1, 0, 1 },
        { -9, -8, -7, -5, -3, -1, 0, 0, 2, 0, 4 },
        { 3, 3, 2, 2, 1, 2, 1, 1, 1, 1, -1 },
        { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0 },
        { -3, -3, -2, -2, -1, 0, 0, 1, 1, 0, 1 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { -2, -2, -1, -1, 0, 0, 0, 0, 0, 0, 0 },
        { -2, -2, -1, -1, 0, 0, 0, 0, 0, 0, 0 },
        { -3, -3, -2, -2, -1, -1, 0, 0, 0, -1, -1 },
        { -2, -2, -1, -1, 0, 1, 1, 1, 0, 0, 0 },
        { 0, 1, 1, 1, 1, 2, 2, 2, 1, 1, 0 },
        { -3, -2, -2, -1, -1, -1, 0, 0, 0, 0, 0 },
        { 0, 1, 1, 1, 2, 2, 2, 1, 1, 0, 0 },
        { 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
        { -3, -3, -2, -2, -1, -1, 0, 0, 0, 0, -1 },
        { -10, -9, -8, -6, -4, -2, -1, 0, 1, 0, 2 },
        { -6, -5, -5, -4, -3, -2, -1, 0, 1, 1, 3 },
        { -3, -3, -2, -2, -1, 0, 0, 0, 0, 0, 0 },
        { -1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
        { 4, 4, 3, 3, 2, 2, 2, 1, 1, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 2, 2, 1, 1, 0, 0, 0, 0, 0, 1, -1 },
        { 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, -1, -2, -3 },
        { 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 3, 3, 2, 2, 1, 1, 0, -1, -1, -1, -2 },
        { 2, 2, 1, 1, 1, 1, 0, 0, -1, -1, -1 },
        { -1, -1, -1, 0, 0, 0, 0, 0, 0, -1, -2 },
        { -3, -3, -2, -1, -1, 0, 0, 0, 0, 0, 1 },
        { -14, -13, -12, -10, -8, -6, -5, -4, -3, -2, 0 },
        { -4, -3, -3, -2, -2, -1, 0, 0, 1, 1, 3 },
        { -2, -2, -2, -1, -1, -1, 0, 0, 0, 0, 0 },
        { -2, -2, -2, -1, 0, 0, 0, 0, 0, 1, 2 },
        { -7, -6, -5, -4, -3, -2, -1, 0, 0, 0, 2 },
        { -9, -8, -7, -5, -3, -1, 0, 0, 1, 1, 1 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0 },
        { -5, -4, -3, -2, -1, 0, 0, 1, 1, 1, 2 },
        { -3, -2, -2, -1, 0, 1, 1, 1, 1, 0, 0 },
        { -7, -6, -5, -4, -2, -1, 0, 0, 1, 1, 2 },
        { -4, -3, -2, -1, 0, 0, 0, 0, 0, 1, 2 },
        { -5, -4, -3, -2, -1, 0, 0, 0, 1, 0, 2 },
        { 2, 2, 2, 2, 2, 2, 3, 3, 3, 1, 0 },
        { -4, -3, -3, -2, -1, -1, 0, 0, 1, 0, 1 },
        { -2, -2, -1, -1, 0, 1, 1, 1, 0, 0, 0 },
        { -14, -12, -10, -8, -6, -4, -2, -1, 1, 0, 3 },
    };
    if (i < 0) i = 0;
    if (i > 59) i = 59;
    if (ac < 0) ac = 0;
    if (ac > 10) ac = 10;
    return k[i][ac];
}

// True when the row carries the * footnote (set to receive
// a charge: double damage - the spetum, the bastard sword).
inline bool uahhSetDoubleFlag(int i) {
    static const bool k[60] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    if (i < 0) i = 0;
    if (i > 59) i = 59;
    return k[i];
}

// True when the row carries the ** footnote (the dismount
// capability - eight rows).
inline bool uahhDismountFlag(int i) {
    static const bool k[60] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1,
        1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    if (i < 0) i = 0;
    if (i > 59) i = 59;
    return k[i];
}

// The general note: any weapon strikes at +2 vs the back.
inline int uahhRearAttackBonus()
    { return 2; }

// The general note: +4 vs stunned, prone and motionless.
inline int uahhStunnedProneBonus()
    { return 4; }

// The * footnote: these weapons do twice the damage
// indicated to size L creatures when set (firmly grounded)
// to receive a charging opponent.
inline bool uahhNoteSetDoubleVsCharge()
    { return true; }

// The ** footnote: these weapons are capable of dismounting
// a rider on a score equal to or greater than the "to hit"
// score.
inline bool uahhNoteDismountOnHit()
    { return true; }

}   // namespace rules
"""
HDR_HH = HDR_HH[1:-1]

# ---- the R392 audit block ----
AUDIT392 = r"""
    // ---- R392: the UA players tables pin audit ----
    // The players tables manifest sweep (20 items): the
    // equipment and supplies costs table and the
    // hand-held weapons table pin NEW (rules/uaequip26.h,
    // rules/uahandheld.h); the weight/damage, missile and
    // proficiency tables AMEND (the clean PDF read: every
    // hole fills, three misdecodes reconcile - the garrot
    // L damage, the barbarian initial, the ranger initial);
    // the seventeen covered rides close the manifest.
    {
        using namespace rules;
        int bad = 0;
        // U1: the equipment and supplies costs
        {
            if (uaecArmorCount() != 4) ++bad;
            if (uaecArmsCount() != 19) ++bad;
            if (strcmp(uaecArmorName(0),
                "Bronze Plate") != 0) ++bad;
            if (uaecArmorCost(0) != 100) ++bad;
            if (strcmp(uaecArmorName(1),
                "Full Plate") != 0) ++bad;
            if (uaecArmorCost(1) != 4000) ++bad;
            if (strcmp(uaecArmorName(2),
                "Field Plate") != 0) ++bad;
            if (uaecArmorCost(2) != 2000) ++bad;
            if (uaecArmorCost(3) != 5) ++bad;
            if (strcmp(uaecArmsName(0), "Aklys")
                != 0) ++bad;
            if (uaecArmsCost(0) != 2) ++bad;
            if (strcmp(uaecArmsName(5),
                "Crossbow, hand") != 0) ++bad;
            if (uaecArmsCost(5) != 300) ++bad;
            if (strcmp(uaecArmsName(6),
                "Quarrels for same") != 0) ++bad;
            if (uaecArmsCost(6) != 100) ++bad;
            if (uaecArmsCost(18) != 3) ++bad;
            if (!uaecArmsPriceIsSilver(3)) ++bad;
            if (!uaecArmsPriceIsSilver(4)) ++bad;
            if (!uaecArmsPriceIsSilver(11)) ++bad;
            if (uaecArmsPriceIsSilver(0)) ++bad;
            if (!uaecArmsPriceIsElectrum(7)) ++bad;
            if (uaecArmsPriceIsElectrum(0)) ++bad;
            int gp = 0;
            for (int i = 0; i < 19; ++i) {
                if (uaecArmsPriceIsSilver(i)) continue;
                if (uaecArmsPriceIsElectrum(i))
                    continue;
                ++gp;
            }
            if (gp != 15) ++bad;
        }
        // U2: the hand-held weapons table
        {
            if (uahhRowCount() != 60) ++bad;
            if (strcmp(uahhName(0), "Aklys") != 0)
                ++bad;
            if (strcmp(uahhName(59), "Whip") != 0)
                ++bad;
            if (strcmp(uahhName(46), "Spetum")
                != 0) ++bad;
            if (strcmp(uahhLength(0), "c. 2'")
                != 0) ++bad;
            if (strcmp(uahhSpaceRequired(0), "2'")
                != 0) ++bad;
            if (uahhSpeedFactorMin(0) != 4) ++bad;
            if (uahhSpeedFactorMax(0) != 4) ++bad;
            if (uahhAklysSpeedBonus() != 1) ++bad;
            // the n/a rows: the atlatl, the blowgun,
            // the caltrop
            if (uahhSpeedFactorMin(1) != -1) ++bad;
            if (uahhSpeedFactorMin(7) != -1) ++bad;
            if (uahhSpeedFactorMin(9) != -1) ++bad;
            // the speed-factor ranges: the spear,
            // the trident, the whip
            if (uahhSpeedFactorMin(45) != 6) ++bad;
            if (uahhSpeedFactorMax(45) != 8) ++bad;
            if (uahhSpeedFactorMin(59) != 5) ++bad;
            if (uahhSpeedFactorMax(59) != 8) ++bad;
            // the aklys AC ladder (AC 0..6)
            for (int ac = 0; ac < 7; ++ac)
                if (uahhAcAdjustment(0, ac)
                    != ac - 7) ++bad;
            if (uahhAcAdjustment(5, 0) != 2) ++bad;
            if (uahhAcAdjustment(5, 4) != 2) ++bad;
            if (uahhAcAdjustment(5, 5) != 0) ++bad;
            if (uahhAcAdjustment(5, 10) != -1) ++bad;
            if (uahhAcAdjustment(59, 10) != 3) ++bad;
            // the general note and the footnotes
            if (uahhRearAttackBonus() != 2) ++bad;
            if (uahhStunnedProneBonus() != 4) ++bad;
            if (!uahhNoteSetDoubleVsCharge()) ++bad;
            if (!uahhNoteDismountOnHit()) ++bad;
            if (!uahhSetDoubleFlag(46)) ++bad;
            if (!uahhSetDoubleFlag(50)) ++bad;
            if (uahhSetDoubleFlag(0)) ++bad;
            if (!uahhDismountFlag(12)) ++bad;
            if (!uahhDismountFlag(42)) ++bad;
            if (uahhDismountFlag(0)) ++bad;
            int sd = 0, dm = 0;
            for (int i = 0; i < 60; ++i) {
                if (uahhSetDoubleFlag(i)) ++sd;
                if (uahhDismountFlag(i)) ++dm;
            }
            if (sd != 2) ++bad;
            if (dm != 8) ++bad;
        }
        // U3: the amended tables (the reconcile
        // cross-checks)
        {
            if (uawtRowCount() != 68) ++bad;
            if (uawtNewWeaponCount() != 18) ++bad;
            if (strcmp(uawtName(67),
                "Quarrel (or Bolt), hand") != 0)
                ++bad;
            if (!uawtIsNewWeapon(67)) ++bad;
            if (uawtPhbSeamIndex(67) != -1) ++bad;
            if (uawtWeightMin(67) != 1) ++bad;
            if (uawtDamageSMMin(67) != 1) ++bad;
            if (uawtDamageSMMax(67) != 3) ++bad;
            if (uawtDamageLMin(67) != 1) ++bad;
            if (uawtDamageLMax(67) != 2) ++bad;
            if (uawtDamageLMax(19) != 6) ++bad;
            if (!uawtDamagePrintsDash(35)) ++bad;
            if (uawtDamagePrintsDash(0)) ++bad;
            if (!uawtNote1ChargingMountDouble())
                ++bad;
            if (!uawtNote2SetDoubleVsCharge())
                ++bad;
            if (uawtNote3BladeClassLowInches()
                != 15) ++bad;
            if (uawtNote3BladeClassHighInches()
                != 24) ++bad;
            if (uawtNote4DisarmOnAcEightHit()
                != 8) ++bad;
            if (!uawtNote5BastardAsLongSword())
                ++bad;
            if (!uawtNote6VariantsSeePhb()) ++bad;
            if (uapfInitialSlots(5) != 6) ++bad;
            if (uapfInitialSlots(6) != 3) ++bad;
            if (uapfNonProfPenalty(0) != 3) ++bad;
            if (uapfFacingPageNotesLost()) ++bad;
            if (strcmp(uamtRateOfFire(18), "1/2")
                != 0) ++bad;
            if (strcmp(uamtRangeShort(0), "1*")
                != 0) ++bad;
            if (!uamtAklysTenFootOnly()) ++bad;
        }
        printf("R392 UA players tables pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
"""
AUDIT392 = AUDIT392[1:-1]

# ---- the amendment pair data ----

O_PF_0 = r"""
// OCR holes (the item closes; these stay on the PDF ledger): the
// cavalier penalty cell (prints empty), the paladin initial cell
// (prints empty - the stacked-group reading would share the
// cavalier's 3, not pinned), the assassin initial cell (prints
// empty), and the ENTIRE facing-page notes (the print points at
// them: "(Notes to this table on facing page)" - the notes
// themselves are OCR-lost).
"""[1:-1]
N_PF_0 = r"""
// R392 (the clean PDF read): every hole closes. The cavalier
// penalty prints 3 (magnitude 3, the R297 convention); the
// paladin and assassin initial cells print 3; the facing-page
// notes read in full: the 0-level Horsemen 1 proficiency, the
// 0-level Lancers 2, the 1st-level Armigers 3, and the
// cavalier/ranger weapon-choice restriction. Two misdecodes
// reconcile: the barbarian initial reads 6 (the pinned 8 was
// an echo), the ranger initial 3 (the asterisk row) - the
// deviations from the PHB resolve, the R297 seam now agrees
// cell for cell on every shared row except the paladin
// penalty/cadence pair, which rides the cavalier group as
// printed.
"""[1:-1]

O_PF_1 = r"""
// The initial number of weapons; -1 = the cell prints empty
// (a hole): the paladin and the assassin.
inline int uapfInitialSlots(int i) {
    static const int k[14] = {
        3, -1, 2, 2, 4, 8, 8, 1, 1, 2, 2, -1, 1, 5
    };
"""[1:-1]
N_PF_1 = r"""
// The initial number of weapons (the R392 clean read: the
// paladin and assassin cells print 3, the barbarian 6,
// the ranger 3 - the asterisk rows carry the choice
// restriction).
inline int uapfInitialSlots(int i) {
    static const int k[14] = {
        3, 3, 2, 2, 4, 6, 3, 1, 1, 2, 2, 3, 1, 5
    };
"""[1:-1]

O_PF_2 = r"""
// The non-proficiency to-hit penalty MAGNITUDE (the R297
// convention; the adjustment is negative). The cavalier cell
// prints empty - a hole, -1.
inline int uapfNonProfPenalty(int i) {
    static const int k[14] = {
        -1, 3, 3, 4, 2, 1, 2, 5, 5, 3, 3, 2, 3, 2
    };
"""[1:-1]
N_PF_2 = r"""
// The non-proficiency to-hit penalty MAGNITUDE (the R297
// convention; the adjustment is negative). The R392 clean
// read: the cavalier cell prints 3.
inline int uapfNonProfPenalty(int i) {
    static const int k[14] = {
        3, 3, 3, 4, 2, 1, 2, 5, 5, 3, 3, 2, 3, 2
    };
"""[1:-1]

O_PF_3 = r"""
// The facing-page notes are wholly OCR-lost (the table's own
// caption points at them); their existence pins, their
// content does not.
inline bool uapfFacingPageNotesLost()
    { return true; }
"""[1:-1]
N_PF_3 = r"""
// The facing-page notes: the R392 clean read - the lost
// flag flips false, the notes read in full below.
inline bool uapfFacingPageNotesLost()
    { return false; }

// The 0-level Horsemen (cavaliers) have 1 weapon of
// proficiency.
inline int uapfHorsemenInitialSlots()
    { return 1; }

// The 0-level Lancers (cavaliers): 2 weapons.
inline int uapfLancersInitialSlots()
    { return 2; }

// The 1st-level Armigers (cavaliers): 3 weapons.
inline int uapfArmigersInitialSlots()
    { return 3; }

// Cavaliers and rangers are restricted in which weapons
// they can choose to take proficiency in (see the class
// descriptions).
inline bool uapfRestrictedWeaponChoice()
    { return true; }

// True when the row's initial cell prints the restriction
// asterisk (the cavalier, paladin and ranger rows).
inline bool uapfInitialAsterisk(int i) {
    static const bool k[14] = {
        1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0
    };
    if (i < 0) i = 0;
    if (i > 13) i = 13;
    return k[i];
}
"""[1:-1]

PF_PAIRS = [
    (O_PF_0, N_PF_0),
    (O_PF_1, N_PF_1),
    (O_PF_2, N_PF_2),
    (O_PF_3, N_PF_3),
]

O_UM_0 = r"""
// OCR holes (the item stays open pending the PDF read): the
// ENTIRE rate-of-fire column (every row prints empty or
// garbage - "ODN", "||"), the two leading range cells of every
// row (the S/M ranges), the aklys and dart range cells, and
// the tail AC cells of the short rows (the hole sentinel is
// 100): the club AC2, the hammer AC0/AC5, the atlatl AC5/AC6
// (the merged "0 4"), the hand crossbow AC6 (the "0 i Wf"),
// the heavy crossbow AC1 (the printed dash), the light
// crossbow AC6 (the PHB row reads +1 - noted, not pinned),
// the sling stone AC0 (the "=r") and the bow long AC4-AC6.
"""[1:-1]
N_UM_0 = r"""
// R392 (the clean PDF read): every hole closes. The rate
// column and the S/M/L ranges read in full (the strings pin
// as printed: "1/2" for the half-rate rows, "1*" for the
// aklys, the dash for the staff slings' short range, the
// "1 1/2" and "4 1/2" dart cells, the "3-6" staff-sling
// medium). Every 100 sentinel fills (the light crossbow
// AC6 reads +1, the PHB-seam value the R338 pin could not
// confirm); the AC 7..10 columns pin - the R392
// uamtAcAdjustmentHigh accessor. The aklys range footnote
// reads: 10-foot only, not 10 yards. The composite long
// bow's 21 stays the printed value (the PHB reads 24 - the
// deviation noted, pinned as printed).
"""[1:-1]

O_UM_1 = r"""
// The AC adjustment by AC 0..6, applied at
// short range; 100 = the cell is OCR-lost.
"""[1:-1]
N_UM_1 = r"""
// The AC adjustment by AC 0..6, applied at
// short range (the R392 clean read: every
// cell recovers; no sentinel remains).
"""[1:-1]

O_UM_2 = r"""
    static const int k[24][7] = {
        { -8, -7, -6, -5, -4, -3, -2 },
        { -6, -5, -4, -3, -2, 100, 100 },
        { -6, -5, -4, -3, -2, -1, -1 },
        { -14, -12, -10, -8, -6, -4, -2 },
        { -4, -3, -2, -1, 0, 0, 1 },
        { -4, -4, -3, -3, -1, 0, 1 },
        { -2, -1, -1, 0, 100, 100, 100 },
        { -7, -6, -5, -4, -1, 0, 0 },
        { -9, -8, 100, -5, -3, -2, -1 },
        { -6, -4, -2, -1, 0, 0, 100 },
        { -2, 100, -1, 0, 1, 2, 3 },
        { -3, -2, -2, -1, 0, 0, 100 },
        { -7, -6, -5, -4, -3, -2, -1 },
        { -7, -6, -5, -4, -3, -2, -1 },
        { 100, -3, -2, -1, 0, 100, 0 },
        { -6, -5, -4, 100, 100, 100, 100 },
        { -7, -6, -5, 100, 100, 100, 100 },
        { -8, -7, -6, 100, 100, 100, 100 },
        { 9, 8, 7, 100, 100, 100, 100 },
        { -3, -3, -2, 100, 100, 100, 100 },
        { 100, -6, -5, 100, 100, 100, 100 },
        { -4, -4, -3, 100, 100, 100, 100 },
        { -5, -4, -3, 100, 100, 100, 100 },
        { -6, -5, -4, 100, 100, 100, 100 },
    };
"""[1:-1]
N_UM_2 = r"""
    static const int k[24][7] = {
        { -8, -7, -6, -5, -4, -3, -2 },
        { -6, -5, -4, -3, -2, -1, 0 },
        { -6, -5, -4, -3, -2, -1, -1 },
        { -14, -12, -10, -8, -6, -4, -2 },
        { -4, -3, -2, -1, 0, 0, 1 },
        { -4, -4, -3, -3, -1, 0, 1 },
        { -2, -1, -1, 0, 0, 1, 2 },
        { -7, -6, -5, -4, -1, 0, 0 },
        { -9, -8, -7, -5, -3, -2, -1 },
        { -6, -4, -2, -1, 0, 0, 0 },
        { -2, -1, -1, 0, 1, 2, 3 },
        { -3, -2, -2, -1, 0, 0, 1 },
        { -7, -6, -5, -4, -3, -2, -1 },
        { -7, -6, -5, -4, -3, -2, -1 },
        { -4, -3, -2, -1, 0, 0, 0 },
        { -6, -5, -4, -3, -2, -1, 0 },
        { -7, -6, -5, -4, -3, -2, -1 },
        { -8, -7, -6, -5, -4, -3, -2 },
        { 9, 8, 7, 6, 5, 4, 3 },
        { -3, -3, -2, -2, -1, 0, 0 },
        { -7, -6, -5, -4, -2, -1, 0 },
        { -4, -4, -3, -3, -2, -2, -1 },
        { -5, -4, -3, -2, -1, 0, 0 },
        { -6, -5, -4, -3, -2, -1, 0 },
    };
"""[1:-1]

O_UM_3 = r"""
}   // namespace rules
"""[1:-1]
N_UM_3 = r"""
// The AC adjustment by AC 7..10 (the R392 clean read; the
// short-range ladders extend past AC 6).
inline int uamtAcAdjustmentHigh(int i, int ac) {
    static const int k[24][4] = {
        { -1, 0, 0, 0 },
        { 0, 1, 1, 2 },
        { 0, 0, 0, 1 },
        { -1, -1, 1, 2 },
        { 2, 2, 3, 3 },
        { 2, 2, 2, 3 },
        { 3, 3, 3, 3 },
        { 1, 2, 2, 2 },
        { -1, -1, 0, 0 },
        { 1, 2, 2, 3 },
        { 3, 4, 4, 4 },
        { 2, 3, 3, 3 },
        { -1, 0, 0, 1 },
        { 0, 1, 0, 1 },
        { 0, 0, 0, 1 },
        { 0, 0, 0, 1 },
        { 0, 1, 0, 1 },
        { -1, 0, 0, 1 },
        { 2, 1, 0, -1 },
        { 0, 2, 1, 3 },
        { 0, 2, 1, 3 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
    };
    if (i < 0) i = 0;
    if (i > 23) i = 23;
    if (ac < 0) ac = 0;
    if (ac > 3) ac = 3;
    return k[i][ac];
}

// The rate of fire (printed; "1/2" = the half-rate rows:
// the heavy crossbow, the lasso, the two staff slings).
inline const char* uamtRateOfFire(int i) {
    static const char* const k[24] = {
        "1", "1", "1", "2", "2", "2", "2", "2", "1", "1", "1/2",
        "1", "2", "3", "1", "1", "1", "2", "1/2", "1", "1", "1",
        "1/2", "1/2",
    };
    if (i < 0) i = 0;
    if (i > 23) i = 23;
    return k[i];
}

// The short range (printed; "-" = the dash, "1*" = the
// aklys footnote, "1 1/2" = the dart).
inline const char* uamtRangeShort(int i) {
    static const char* const k[24] = {
        "1*", "3", "1", "1", "6", "5", "7", "5", "1", "2", "8",
        "6", "1", "1 1/2", "1", "1", "2", "1", "1", "5", "4", "1",
        "-", "-",
    };
    if (i < 0) i = 0;
    if (i > 23) i = 23;
    return k[i];
}

// The medium range (printed; "3-6" = the staff slings).
inline const char* uamtRangeMedium(int i) {
    static const char* const k[24] = {
        "-", "6", "2", "2", "12", "10", "14", "10", "2", "4", "16",
        "12", "2", "3", "2", "2", "4", "2", "2", "10", "8", "2",
        "3-6", "3-6",
    };
    if (i < 0) i = 0;
    if (i > 23) i = 23;
    return k[i];
}

// The long range (printed).
inline const char* uamtRangeLong(int i) {
    static const char* const k[24] = {
        "-", "9", "3", "3", "21", "18", "21", "15", "3", "6", "24",
        "18", "3", "4 1/2", "3", "3", "6", "3", "3", "20", "16",
        "3", "9", "9",
    };
    if (i < 0) i = 0;
    if (i > 23) i = 23;
    return k[i];
}

// The aklys range footnote: the "1*" reads 10-foot only,
// not 10 yards (the R392 clean read).
inline bool uamtAklysTenFootOnly()
    { return true; }

}   // namespace rules
"""[1:-1]

UM_PAIRS = [
    (O_UM_0, N_UM_0),
    (O_UM_1, N_UM_1),
    (O_UM_2, N_UM_2),
    (O_UM_3, N_UM_3),
]

O_WT_0 = r"""
// The row count (67 = the 50 PHB rows
// plus 17 new-weapon rows).
inline int uawtRowCount()
    { return 67; }
"""[1:-1]
N_WT_0 = r"""
// The row count (68 = the 50 PHB rows
// plus 18 new-weapon rows; the R392
// clean read adds the hand-crossbow
// quarrel row the garbled extract
// dropped).
inline int uawtRowCount()
    { return 68; }
"""[1:-1]

O_WT_1 = r"""
// The UA-new weapon rows (not in the
// PHB chart): the aklys, atlatl,
// blowgun, caltrop, garrot, harpoon,
// hook fauchard, knife, lasso, man
// catcher, sap, spiked buckler, staff
// sling (two rows), falchion, khopesh
// and whip.
inline int uawtNewWeaponCount()
    { return 17; }
"""[1:-1]
N_WT_1 = r"""
// The UA-new weapon rows (not in the
// PHB chart): the aklys, atlatl,
// blowgun, caltrop, garrot, harpoon,
// hook fauchard, knife, lasso, man
// catcher, sap, spiked buckler, staff
// sling (two rows), falchion, khopesh,
// whip and the hand-crossbow quarrels
// (the R392 clean read).
inline int uawtNewWeaponCount()
    { return 18; }
"""[1:-1]

O_WT_2 = r"""
// OCR holes (the item stays open pending the PDF read): the
// atlatl, harpoon and falchion weights, the lasso damage
// cells, the stray 30 beside the aklys row, and the
// unattributable garbled quarrel row (Quarrel (or Bolt),
// hand - 13/12 matches no seam row; not pinned).
"""[1:-1]
N_WT_2 = r"""
// R392 (the clean PDF read): every hole closes. The atlatl
// weight reads 30, the harpoon 50-60, the falchion 60-80,
// the lasso damage cells print the dash (0 damage, the
// print flagged uawtDamagePrintsDash), and the garbled
// quarrel row reads in full (Quarrel (or Bolt), hand - 1
// gp, 1-3, 1-2 - the 68th row, appended at the roster
// end, its printed position between the pike and the
// light quarrel). One misdecode reconciles: the garrot
// L damage reads 1-6, not the hyphen-loss 1-8. The p.
// 26 footnotes read in full (the six numbered notes -
// uawtNote1 through uawtNote6).
"""[1:-1]

O_WT_3 = r"""
inline const char* uawtName(int i) {
    static const char* const k[67] = {
        "Aklys", "Atlatl and javelin", "Arrow", "Axe, Battle",
        "Axe, Hand or Throwing", "Bardiche", "Bec de Corbin",
        "Bill-Guisarme", "Blowgun and needle", "Bo Stick",
        "Caltrop", "Club", "Dagger", "Dart", "Fauchard",
        "Fauchard-Fork", "Flail, Footman's", "Flail, Horseman's",
        "Military Fork", "Garrot", "Glaive", "Glaive-Guisarme",
        "Guisarme", "Guisarme-Voulge", "Halberd", "Harpoon",
        "Hammer, Lucern", "Hammer", "Hook Fauchard", "Javelin",
        "Jo Stick", "Knife", "Lance (light horse)",
        "Lance (medium horse)", "Lance (heavy horse)", "Lasso",
        "Mace, Footman's", "Mace, Horseman's", "Man Catcher",
        "Morning Star", "Partisan", "Pick, Footman's",
        "Pick, Horseman's", "Pike, Awl",
        "Quarrel (or Bolt), light", "Quarrel (or Bolt), heavy",
        "Ranseur", "Sap", "Scimitar", "Sling Bullet",
        "Sling Stone", "Spear", "Spetum", "Spiked Buckler",
        "Staff, Quarter", "Staff Sling Bullet",
        "Staff Sling Stone", "Sword, Bastard", "Sword, Broad",
        "Sword, Falchion", "Sword, Khopesh", "Long Sword",
        "Sword, Short", "Sword, Two-handed", "Trident", "Voulge",
        "Whip",
    };
    if (i < 0) i = 0;
    if (i > 66) i = 66;
    return k[i];
}
"""[1:-1]
N_WT_3 = r"""
inline int uawtName(int i) {
    static const char* const k[68] = {
        "Aklys", "Atlatl and javelin", "Arrow", "Axe, Battle",
        "Axe, Hand or Throwing", "Bardiche", "Bec de Corbin",
        "Bill-Guisarme", "Blowgun and needle", "Bo Stick", "Caltrop",
        "Club", "Dagger", "Dart", "Fauchard", "Fauchard-Fork",
        "Flail, Footman's", "Flail, Horseman's", "Military Fork",
        "Garrot", "Glaive", "Glaive-Guisarme", "Guisarme",
        "Guisarme-Voulge", "Halberd", "Harpoon", "Hammer, Lucern",
        "Hammer", "Hook Fauchard", "Javelin", "Jo Stick", "Knife",
        "Lance (light horse)", "Lance (medium horse)",
        "Lance (heavy horse)", "Lasso", "Mace, Footman's",
        "Mace, Horseman's", "Man Catcher", "Morning Star", "Partisan",
        "Pick, Footman's", "Pick, Horseman's", "Pike, Awl",
        "Quarrel (or Bolt), light", "Quarrel (or Bolt), heavy",
        "Ranseur", "Sap", "Scimitar", "Sling Bullet", "Sling Stone",
        "Spear", "Spetum", "Spiked Buckler", "Staff, Quarter",
        "Staff Sling Bullet", "Staff Sling Stone", "Sword, Bastard",
        "Sword, Broad", "Sword, Falchion", "Sword, Khopesh",
        "Long Sword", "Sword, Short", "Sword, Two-handed", "Trident",
        "Voulge", "Whip", "Quarrel (or Bolt), hand",
    };
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    return k[i];
}
"""[1:-1]

O_WT_4 = r"""
inline bool uawtIsNewWeapon(int i) {
    static const bool k[67] = {
        1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0,
        1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1,
        0, 0, 1, 1, 0, 0, 0, 0, 0, 1,
    };
    if (i < 0) i = 0;
    if (i > 66) i = 66;
    return k[i];
}
"""[1:-1]
N_WT_4 = r"""
inline int uawtIsNewWeapon(int i) {
    static const bool k[68] = {
        1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0,
        0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 1, 1,
    };
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    return k[i];
}
"""[1:-1]

O_WT_5 = r"""
inline int uawtPhbSeamIndex(int i) {
    static const int k[67] = {
        -1, -1, 0, 1, 2, 3, 4, 5, -1, 6, -1, 7, 8, 9, 10, 11, 12,
        13, 14, -1, 15, 16, 17, 18, 19, -1, 20, 21, -1, 22, 23,
        -1, 24, 25, 26, -1, 27, 28, -1, 29, 30, 31, 32, 33, 34,
        35, 36, -1, 37, 38, 39, 40, 41, -1, 42, -1, -1, 43, 44,
        -1, -1, 45, 46, 47, 48, 49, -1,
    };
    if (i < 0) i = 0;
    if (i > 66) i = 66;
    return k[i];
}
"""[1:-1]
N_WT_5 = r"""
inline int uawtPhbSeamIndex(int i) {
    static const int k[68] = {
        -1, -1, 0, 1, 2, 3, 4, 5, -1, 6, -1, 7, 8, 9, 10, 11, 12,
        13, 14, -1, 15, 16, 17, 18, 19, -1, 20, 21, -1, 22, 23, -1,
        24, 25, 26, -1, 27, 28, -1, 29, 30, 31, 32, 33, 34, 35, 36,
        -1, 37, 38, 39, 40, 41, -1, 42, -1, -1, 43, 44, -1, -1, 45,
        46, 47, 48, 49, -1, -1,
    };
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    return k[i];
}
"""[1:-1]

O_WT_6 = r"""
inline int uawtWeightMin(int i) {
    static const int k[67] = {
        35, -1, 2, 75, 50, 125, 100, 150, 15, 15, 2, 30, 10, 5,
        60, 80, 150, 35, 75, 1, 75, 100, 80, 150, 175, -1, 150,
        50, 80, 20, 40, 6, 50, 100, 150, 20, 100, 50, 80, 125, 80,
        60, 40, 80, 1, 2, 50, 10, 40, 2, 1, 40, 50, 35, 50, 5, 4,
        100, 75, -1, 75, 60, 35, 250, 50, 125, 25,
    };
    if (i < 0) i = 0;
    if (i > 66) i = 66;
    return k[i];
}
"""[1:-1]
N_WT_6 = r"""
inline int uawtWeightMin(int i) {
    static const int k[68] = {
        35, 30, 2, 75, 50, 125, 100, 150, 15, 15, 2, 30, 10, 5, 60,
        80, 150, 35, 75, 1, 75, 100, 80, 150, 175, 50, 150, 50, 80,
        20, 40, 6, 50, 100, 150, 20, 100, 50, 80, 125, 80, 60, 40,
        80, 1, 2, 50, 10, 40, 2, 1, 40, 50, 35, 50, 5, 4, 100, 75,
        60, 75, 60, 35, 250, 50, 125, 25, 1,
    };
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    return k[i];
}
"""[1:-1]

O_WT_7 = r"""
inline int uawtWeightMax(int i) {
    static const int k[67] = {
        35, -1, 2, 75, 50, 125, 100, 150, 15, 15, 4, 30, 10, 5,
        60, 80, 150, 35, 75, 1, 75, 100, 80, 150, 175, -1, 150,
        50, 80, 20, 40, 6, 50, 100, 150, 20, 100, 50, 80, 125, 80,
        60, 40, 80, 1, 2, 50, 10, 40, 2, 1, 60, 50, 35, 50, 5, 4,
        100, 75, -1, 75, 60, 35, 250, 50, 125, 35,
    };
    if (i < 0) i = 0;
    if (i > 66) i = 66;
    return k[i];
}
"""[1:-1]
N_WT_7 = r"""
inline int uawtWeightMax(int i) {
    static const int k[68] = {
        35, 30, 2, 75, 50, 125, 100, 150, 15, 15, 4, 30, 10, 5, 60,
        80, 150, 35, 75, 1, 75, 100, 80, 150, 175, 60, 150, 50, 80,
        20, 40, 6, 50, 100, 150, 20, 100, 50, 80, 125, 80, 60, 40,
        80, 1, 2, 50, 10, 40, 2, 1, 60, 50, 35, 50, 5, 4, 100, 75,
        80, 75, 60, 35, 250, 50, 125, 35, 1,
    };
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    return k[i];
}
"""[1:-1]

O_WT_8 = r"""
inline int uawtDamageSMMin(int i) {
    static const int k[67] = {
        1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1,
        1, 1, 2, 2, 2, 1, 2, 2, 2, 1, 1, 1, 1, 1, 2, 3, -1, 2, 1,
        1, 2, 1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1,
        2, 2, 2, 2, 1, 1, 1, 2, 2, 1,
    };
    if (i < 0) i = 0;
    if (i > 66) i = 66;
    return k[i];
}
"""[1:-1]
N_WT_8 = r"""
inline int uawtDamageSMMin(int i) {
    static const int k[68] = {
        1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1,
        1, 2, 2, 2, 1, 2, 2, 2, 1, 1, 1, 1, 1, 2, 3, 0, 2, 1, 1, 2,
        1, 2, 2, 1, 1, 2, 2, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 2, 2, 2,
        2, 1, 1, 1, 2, 2, 1, 1,
    };
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    return k[i];
}
"""[1:-1]

O_WT_9 = r"""
inline int uawtDamageSMMax(int i) {
    static const int k[67] = {
        6, 6, 6, 8, 6, 8, 8, 8, 1, 6, 1, 6, 4, 3, 6, 8, 7, 5, 8,
        4, 6, 8, 8, 8, 10, 8, 8, 5, 4, 6, 6, 3, 6, 7, 9, -1, 7, 6,
        2, 8, 6, 7, 5, 6, 4, 5, 8, 2, 8, 5, 4, 6, 7, 4, 6, 8, 8,
        8, 8, 7, 8, 8, 6, 10, 7, 8, 2,
    };
    if (i < 0) i = 0;
    if (i > 66) i = 66;
    return k[i];
}
"""[1:-1]
N_WT_9 = r"""
inline int uawtDamageSMMax(int i) {
    static const int k[68] = {
        6, 6, 6, 8, 6, 8, 8, 8, 1, 6, 1, 6, 4, 3, 6, 8, 7, 5, 8, 4,
        6, 8, 8, 8, 10, 8, 8, 5, 4, 6, 6, 3, 6, 7, 9, 0, 7, 6, 2,
        8, 6, 7, 5, 6, 4, 5, 8, 2, 8, 5, 4, 6, 7, 4, 6, 8, 8, 8, 8,
        7, 8, 8, 6, 10, 7, 8, 2, 3,
    };
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    return k[i];
}
"""[1:-1]

O_WT_10 = r"""
inline int uawtDamageLMin(int i) {
    static const int k[67] = {
        1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2,
        1, 1, 2, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 2, 3, -1, 1, 1,
        1, 2, 2, 2, 1, 1, 1, 2, 2, 1, 1, 2, 1, 1, 2, 1, 1, 3, 2,
        2, 2, 2, 1, 1, 1, 3, 3, 2, 1,
    };
    if (i < 0) i = 0;
    if (i > 66) i = 66;
    return k[i];
}
"""[1:-1]
N_WT_10 = r"""
inline int uawtDamageLMin(int i) {
    static const int k[68] = {
        1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 1,
        1, 2, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 2, 3, 0, 1, 1, 1, 2,
        2, 2, 1, 1, 1, 2, 2, 1, 1, 2, 1, 1, 2, 1, 1, 3, 2, 2, 2, 2,
        1, 1, 1, 3, 3, 2, 1, 1,
    };
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    return k[i];
}
"""[1:-1]

O_WT_11 = r"""
inline int uawtDamageLMax(int i) {
    static const int k[67] = {
        3, 6, 6, 8, 4, 12, 6, 10, 1, 3, 2, 3, 3, 2, 8, 10, 8, 5,
        8, 8, 10, 12, 8, 8, 12, 12, 6, 4, 4, 6, 4, 2, 8, 12, 18,
        -1, 6, 4, 2, 7, 7, 8, 4, 12, 4, 7, 8, 2, 8, 7, 4, 8, 12,
        3, 6, 9, 8, 16, 7, 8, 6, 12, 8, 18, 12, 8, 1,
    };
    if (i < 0) i = 0;
    if (i > 66) i = 66;
    return k[i];
}
"""[1:-1]
N_WT_11 = r"""
inline int uawtDamageLMax(int i) {
    static const int k[68] = {
        3, 6, 6, 8, 4, 12, 6, 10, 1, 3, 2, 3, 3, 2, 8, 10, 8, 5, 8,
        6, 10, 12, 8, 8, 12, 12, 6, 4, 4, 6, 4, 2, 8, 12, 18, 0, 6,
        4, 2, 7, 7, 8, 4, 12, 4, 7, 8, 2, 8, 7, 4, 8, 12, 3, 6, 9,
        8, 16, 7, 8, 6, 12, 8, 18, 12, 8, 1, 2,
    };
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    return k[i];
}
"""[1:-1]

O_WT_12 = r"""
}   // namespace rules
"""[1:-1]
N_WT_12 = r"""
// True when the row's damage cells print the dash (the
// lasso - the dash reads 0 damage).
inline bool uawtDamagePrintsDash(int i)
    { return i == 35; }

// ---- the printed notes (the p. 26 facing page) ----
// Note 1: these weapons do twice the indicated damage
// against creatures of any size when employed by an
// attacker riding a charging mount (the lance rows).
inline bool uawtNote1ChargingMountDouble()
    { return true; }

// Note 2: this weapon does twice the damage indicated
// to any opponent when the weapon is set to receive
// their charge.
inline bool uawtNote2SetDoubleVsCharge()
    { return true; }

// Note 3: this weapon class includes all pointed
// cutting and thrusting weapons with blade length
// between 15 and 24 inches.
inline int uawtNote3BladeClassLowInches()
    { return 15; }

inline int uawtNote3BladeClassHighInches()
    { return 24; }

// Note 4: these weapons are capable of disarming an
// opponent on a score required to hit AC 8.
inline int uawtNote4DisarmOnAcEightHit()
    { return 8; }

// Note 5: treat this weapon as a long sword if it is
// used one-handed.
inline bool uawtNote5BastardAsLongSword()
    { return true; }

// Note 6: minor variations of these weapons, with
// different names, may exist in the campaign. See
// Players Handbook for particulars.
inline bool uawtNote6VariantsSeePhb()
    { return true; }

}   // namespace rules
"""[1:-1]

WT_PAIRS = [
    (O_WT_0, N_WT_0),
    (O_WT_1, N_WT_1),
    (O_WT_2, N_WT_2),
    (O_WT_3, N_WT_3),
    (O_WT_4, N_WT_4),
    (O_WT_5, N_WT_5),
    (O_WT_6, N_WT_6),
    (O_WT_7, N_WT_7),
    (O_WT_8, N_WT_8),
    (O_WT_9, N_WT_9),
    (O_WT_10, N_WT_10),
    (O_WT_11, N_WT_11),
    (O_WT_12, N_WT_12),
]

O_RT_0 = r"""
#include "rules/uaappendt.h"  // R391: the UA pole-arm nomenclature
"""[1:-1]
N_RT_0 = r"""
#include "rules/uaappendt.h"  // R391: the UA pole-arm nomenclature
#include "rules/uaequip26.h"  // R392: the UA equipment costs
#include "rules/uahandheld.h"  // R392: the UA hand-held data
"""[1:-1]

O_RT_1 = r"""
    // ---- R337: the UA weight and damage pin audit ----
    // The UA WEIGHT AND DAMAGE BY WEAPON TYPE table (p. 26) -
    // the 67-row roster: all 50 PHB rows verified cell for
    // cell against the R189 chart seam (the hyphen-loss
    // pattern proven row by row), the 17 new-weapon rows
    // pinned where printed or pattern-decoded; the holes
    // (the atlatl/harpoon/falchion weights, the lasso
    // damage) and the attributed rows (military fork,
    // glaive-guisarme, the picks, the sap) are documented
    // in the header. The item stays open pending the PDF.
"""[1:-1]
N_RT_1 = r"""
    // ---- R337: the UA weight and damage pin audit ----
    // The UA WEIGHT AND DAMAGE BY WEAPON TYPE table (p. 26) -
    // the 68-row roster: all 50 PHB rows verified cell for
    // cell against the R189 chart seam (the hyphen-loss
    // pattern proven row by row), the 17 new-weapon rows
    // pinned where printed or pattern-decoded; the R392
    // clean PDF read fills every hole (the atlatl 30, the
    // harpoon 50-60, the falchion 60-80, the lasso dash)
    // and adds the 68th row (the hand-crossbow quarrels),
    // one misdecode reconciles (the garrot L 1-6) - the
    // item AMENDED, closes.
"""[1:-1]

O_RT_2 = r"""
            if (uawtRowCount() != 67) ++bad;
"""[1:-1]
N_RT_2 = r"""
            if (uawtRowCount() != 68) ++bad;
"""[1:-1]

O_RT_3 = r"""
            if (uawtNewWeaponCount() != 17) ++bad;
"""[1:-1]
N_RT_3 = r"""
            if (uawtNewWeaponCount() != 18) ++bad;
"""[1:-1]

O_RT_4 = r"""
            if (strcmp(uawtName(66), "Whip") != 0)
                ++bad;
"""[1:-1]
N_RT_4 = r"""
            if (strcmp(uawtName(66), "Whip") != 0)
                ++bad;
            if (strcmp(uawtName(67),
                "Quarrel (or Bolt), hand") != 0)
                ++bad;
"""[1:-1]

O_RT_5 = r"""
            // the garrot: 1 / 1-4 / 1-8
            if (uawtWeightMin(19) != 1) ++bad;
            if (uawtDamageSMMin(19) != 1) ++bad;
            if (uawtDamageSMMax(19) != 4) ++bad;
            if (uawtDamageLMin(19) != 1) ++bad;
            if (uawtDamageLMax(19) != 8) ++bad;
"""[1:-1]
N_RT_5 = r"""
            // the garrot: 1 / 1-4 / 1-6 (the R392
            // clean read; the 1-8 was hyphen-loss)
            if (uawtWeightMin(19) != 1) ++bad;
            if (uawtDamageSMMin(19) != 1) ++bad;
            if (uawtDamageSMMax(19) != 4) ++bad;
            if (uawtDamageLMin(19) != 1) ++bad;
            if (uawtDamageLMax(19) != 6) ++bad;
"""[1:-1]

O_RT_6 = r"""
            // the atlatl: weight hole,
            // damage 1-6 / 1-6
            if (uawtWeightMin(1) != -1) ++bad;
"""[1:-1]
N_RT_6 = r"""
            // the atlatl: weight 30,
            // damage 1-6 / 1-6
            if (uawtWeightMin(1) != 30) ++bad;
"""[1:-1]

O_RT_7 = r"""
            // the harpoon weight and the
            // falchion weight: holes
            if (uawtWeightMin(25) != -1) ++bad;
            if (uawtWeightMin(59) != -1) ++bad;
"""[1:-1]
N_RT_7 = r"""
            // the harpoon weight 50-60, the
            // falchion weight 60-80 (the
            // R392 clean read)
            if (uawtWeightMin(25) != 50) ++bad;
            if (uawtWeightMin(59) != 60) ++bad;
"""[1:-1]

O_RT_8 = r"""
            // the lasso: weight 20 pinned,
            // the damage cells are holes
            if (uawtWeightMin(35) != 20) ++bad;
            if (uawtDamageSMMin(35) != -1) ++bad;
            if (uawtDamageSMMax(35) != -1) ++bad;
            if (uawtDamageLMin(35) != -1) ++bad;
            if (uawtDamageLMax(35) != -1) ++bad;
"""[1:-1]
N_RT_8 = r"""
            // the lasso: weight 20 pinned,
            // the damage cells print the dash
            // (0 damage, the R392 clean read)
            if (uawtWeightMin(35) != 20) ++bad;
            if (uawtDamageSMMin(35) != 0) ++bad;
            if (uawtDamageSMMax(35) != 0) ++bad;
            if (uawtDamageLMin(35) != 0) ++bad;
            if (uawtDamageLMax(35) != 0) ++bad;
"""[1:-1]

O_RT_9 = r"""
            static const int rng[3][3] = {
                {10, 2, 4},
                {51, 40, 60},
                {66, 25, 35}
            };
            for (int r = 0; r < 3; ++r) {
"""[1:-1]
N_RT_9 = r"""
            static const int rng[5][3] = {
                {10, 2, 4},
                {51, 40, 60},
                {66, 25, 35},
                {25, 50, 60},
                {59, 60, 80}
            };
            for (int r = 0; r < 5; ++r) {
"""[1:-1]

O_RT_10 = r"""
                bool ranged = i == 10 || i == 51
                    || i == 66;
"""[1:-1]
N_RT_10 = r"""
                bool ranged = i == 10 || i == 51
                    || i == 66 || i == 25
                    || i == 59;
"""[1:-1]

O_RT_11 = r"""
            for (int i = 0; i < 67; ++i) {
                if (uawtWeightMin(i) < 0) continue;
"""[1:-1]
N_RT_11 = r"""
            for (int i = 0; i < 68; ++i) {
                if (uawtWeightMin(i) < 0) continue;
"""[1:-1]

O_RT_12 = r"""
            for (int i = 0; i < 67; ++i) {
                if (uawtIsNewWeapon(i)) ++newc;
"""[1:-1]
N_RT_12 = r"""
            for (int i = 0; i < 68; ++i) {
                if (uawtIsNewWeapon(i)) ++newc;
"""[1:-1]

O_RT_13 = r"""
            if (newc != 17) ++bad;
"""[1:-1]
N_RT_13 = r"""
            if (newc != 18) ++bad;
"""[1:-1]

O_RT_14 = r"""
    // ---- R338: the UA missile data pin audit ----
    // The UA HURLED WEAPON AND MISSILE TYPES table
    // (p. 28) - the 24-row roster: the range column
    // (the long range in tens of feet, PHB-seam
    // verified), the AC-adjustment ladders minus-loss
    // decoded (the pattern seam-proven on the bow,
    // crossbow and sling rows against the R145
    // engine rows); the rate column and the S/M
    // ranges are OCR-lost - the item stays open
    // pending the PDF. The R116 seam cross-checked.
"""[1:-1]
N_RT_14 = r"""
    // ---- R338: the UA missile data pin audit ----
    // The UA HURLED WEAPON AND MISSILE TYPES table
    // (p. 28) - the 24-row roster: the range column
    // (the long range in tens of feet, PHB-seam
    // verified), the AC-adjustment ladders minus-loss
    // decoded (the pattern seam-proven on the bow,
    // crossbow and sling rows against the R145
    // engine rows); the R392 clean PDF read fills
    // the rate column, the S/M/L range strings and
    // every lost AC cell, and adds the AC 7..10
    // columns - the item AMENDED, closes.
"""[1:-1]

O_RT_15 = r"""
        // U4: the OCR holes (the 100 sentinel)
        {
            if (uamtAcAdjustment(0, 0) == 100) ++bad;
            if (uamtAcAdjustment(8, 2) != 100) ++bad;
            if (uamtAcAdjustment(14, 0) != 100) ++bad;
            if (uamtAcAdjustment(14, 5) != 100) ++bad;
            if (uamtAcAdjustment(1, 5) != 100) ++bad;
            if (uamtAcAdjustment(1, 6) != 100) ++bad;
            if (uamtAcAdjustment(9, 6) != 100) ++bad;
            if (uamtAcAdjustment(10, 1) != 100) ++bad;
            if (uamtAcAdjustment(11, 6) != 100) ++bad;
            if (uamtAcAdjustment(20, 0) != 100) ++bad;
            if (uamtAcAdjustment(6, 4) != 100) ++bad;
            // the hole census: 24 rows x 7 = 168
            // cells; count the non-holes
            int pinned = 0;
            for (int i = 0; i < 24; ++i)
                for (int ac = 0; ac < 7; ++ac)
                    if (uamtAcAdjustment(i, ac)
                        != 100) ++pinned;
            if (pinned != 120) ++bad;
        }
"""[1:-1]
N_RT_15 = r"""
        // U4: the recovered cells (the R392 clean
        // read; every 100 sentinel fills)
        {
            if (uamtAcAdjustment(0, 0) == 100) ++bad;
            if (uamtAcAdjustment(8, 2) != -7) ++bad;
            if (uamtAcAdjustment(14, 0) != -4) ++bad;
            if (uamtAcAdjustment(14, 5) != 0) ++bad;
            if (uamtAcAdjustment(1, 5) != -1) ++bad;
            if (uamtAcAdjustment(1, 6) != 0) ++bad;
            if (uamtAcAdjustment(9, 6) != 0) ++bad;
            if (uamtAcAdjustment(10, 1) != -1) ++bad;
            if (uamtAcAdjustment(11, 6) != 1) ++bad;
            if (uamtAcAdjustment(20, 0) != -7) ++bad;
            if (uamtAcAdjustment(6, 4) != 0) ++bad;
            if (uamtAcAdjustment(6, 5) != 1) ++bad;
            if (uamtAcAdjustment(6, 6) != 2) ++bad;
            // the recovered census: every one of the
            // 24 x 7 cells pins (no sentinel remains)
            int pinned = 0;
            for (int i = 0; i < 24; ++i)
                for (int ac = 0; ac < 7; ++ac)
                    if (uamtAcAdjustment(i, ac)
                        != 100) ++pinned;
            if (pinned != 168) ++bad;
            // the rate column and the S/M/L ranges
            // (the printed strings)
            if (strcmp(uamtRateOfFire(0), "1") != 0)
                ++bad;
            if (strcmp(uamtRateOfFire(10), "1/2")
                != 0) ++bad;
            if (strcmp(uamtRateOfFire(13), "3")
                != 0) ++bad;
            if (strcmp(uamtRangeShort(0), "1*")
                != 0) ++bad;
            if (uamtRangeShort(22)[0] != '-') ++bad;
            if (strcmp(uamtRangeMedium(22), "3-6")
                != 0) ++bad;
            if (strcmp(uamtRangeLong(1), "9") != 0)
                ++bad;
            if (strcmp(uamtRangeShort(13),
                "1 1/2") != 0) ++bad;
            if (strcmp(uamtRangeLong(13),
                "4 1/2") != 0) ++bad;
            if (!uamtAklysTenFootOnly()) ++bad;
            // the AC 7..10 columns (the R392
            // accessor)
            if (uamtAcAdjustmentHigh(18, 0) != 2)
                ++bad;
            if (uamtAcAdjustmentHigh(18, 3) != -1)
                ++bad;
            if (uamtAcAdjustmentHigh(0, 0) != -1)
                ++bad;
            if (uamtAcAdjustmentHigh(0, 3) != 0)
                ++bad;
            if (uamtAcAdjustmentHigh(3, 0) != -1)
                ++bad;
            if (uamtAcAdjustmentHigh(3, 1) != -1)
                ++bad;
            if (uamtAcAdjustmentHigh(3, 2) != 1) ++bad;
            if (uamtAcAdjustmentHigh(3, 3) != 2) ++bad;
        }
"""[1:-1]

O_RT_16 = r"""
    // ---- R339: the UA proficiency pin audit ----
    // The UA WEAPON PROFICIENCY TABLE (p. 26) - the 14-row
    // roster: seven rows match the PHB rows cell for cell
    // (the R297 seam, verified live), the UA-new rows
    // (cavalier, barbarian, acrobat, bard), the attributed
    // fragment rows (illusionist, thief, assassin -
    // documented JUDGMENTs), the paladin/ranger deviations
    // from the PHB pinned as printed; the holes (cavalier
    // penalty, paladin and assassin initials, the
    // facing-page notes) documented. The item closes.
"""[1:-1]
N_RT_16 = r"""
    // ---- R339: the UA proficiency pin audit ----
    // The UA WEAPON PROFICIENCY TABLE (p. 26) - the 14-row
    // roster: seven rows match the PHB rows cell for cell
    // (the R297 seam, verified live), the UA-new rows
    // (cavalier, barbarian, acrobat, bard), the attributed
    // fragment rows (illusionist, thief, assassin -
    // documented JUDGMENTs); the R392 clean PDF read
    // fills every hole (the cavalier penalty 3, the
    // paladin and assassin initials 3) and reconciles
    // the misdecodes (the barbarian 6, the ranger 3),
    // the facing-page notes read in full - the item
    // AMENDED, closes.
"""[1:-1]

O_RT_17 = r"""
            static const int k[14] = {
                3, -1, 2, 2, 4, 8, 8, 1,
                1, 2, 2, -1, 1, 5
            };
            for (int i = 0; i < 14; ++i)
                if (uapfInitialSlots(i) != k[i])
                    ++bad;
            // the holes: the paladin, the assassin
            if (uapfInitialSlots(1) != -1) ++bad;
            if (uapfInitialSlots(11) != -1) ++bad;
"""[1:-1]
N_RT_17 = r"""
            static const int k[14] = {
                3, 3, 2, 2, 4, 6, 3, 1,
                1, 2, 2, 3, 1, 5
            };
            for (int i = 0; i < 14; ++i)
                if (uapfInitialSlots(i) != k[i])
                    ++bad;
            // the recovered cells: the paladin, the
            // assassin (the R392 clean read)
            if (uapfInitialSlots(1) != 3) ++bad;
            if (uapfInitialSlots(11) != 3) ++bad;
"""[1:-1]

O_RT_18 = r"""
            static const int k[14] = {
                -1, 3, 3, 4, 2, 1, 2, 5,
                5, 3, 3, 2, 3, 2
            };
            for (int i = 0; i < 14; ++i)
                if (uapfNonProfPenalty(i) != k[i])
                    ++bad;
            // the hole: the cavalier
            if (uapfNonProfPenalty(0) != -1) ++bad;
"""[1:-1]
N_RT_18 = r"""
            static const int k[14] = {
                3, 3, 3, 4, 2, 1, 2, 5,
                5, 3, 3, 2, 3, 2
            };
            for (int i = 0; i < 14; ++i)
                if (uapfNonProfPenalty(i) != k[i])
                    ++bad;
            // the recovered cell: the cavalier
            // prints 3 (the R392 clean read)
            if (uapfNonProfPenalty(0) != 3) ++bad;
"""[1:-1]

O_RT_19 = r"""
        // U6: the deviations pinned as printed
        {
            // the ranger initial 8 where the PHB
            // (R297) reads 3 - the echo doubt noted
            if (uapfInitialSlots(6) != 8) ++bad;
"""[1:-1]
N_RT_19 = r"""
        // U6: the deviations reconciled (the R392
        // clean read)
        {
            // the ranger initial 3: the asterisk row,
            // the PHB (R297) agreement restored
            if (uapfInitialSlots(6) != 3) ++bad;
"""[1:-1]

O_RT_20 = r"""
            // the UA barbarian: 8 at 1st, 9 at 3rd
            if (uapfInitialSlots(5)
                    + (3 - 1) / uapfAddedCadence(5)
                != 9) ++bad;
"""[1:-1]
N_RT_20 = r"""
            // the UA barbarian: 6 at 1st, 7 at 3rd
            // (the R392 clean read)
            if (uapfInitialSlots(5)
                    + (3 - 1) / uapfAddedCadence(5)
                != 7) ++bad;
"""[1:-1]

O_RT_21 = r"""
        // U8: the hole ledger
        {
            if (!uapfFacingPageNotesLost()) ++bad;
        }
"""[1:-1]
N_RT_21 = r"""
        // U8: the facing-page notes (the R392
        // clean read: the notes recover in full)
        {
            if (uapfFacingPageNotesLost()) ++bad;
            if (uapfHorsemenInitialSlots() != 1)
                ++bad;
            if (uapfLancersInitialSlots() != 2)
                ++bad;
            if (uapfArmigersInitialSlots() != 3)
                ++bad;
            if (!uapfRestrictedWeaponChoice())
                ++bad;
            if (!uapfInitialAsterisk(0)) ++bad;
            if (!uapfInitialAsterisk(1)) ++bad;
            if (!uapfInitialAsterisk(6)) ++bad;
            if (uapfInitialAsterisk(5)) ++bad;
            if (uapfInitialAsterisk(13)) ++bad;
        }
"""[1:-1]

RT_PAIRS = [
    (O_RT_0, N_RT_0),
    (O_RT_1, N_RT_1),
    (O_RT_2, N_RT_2),
    (O_RT_3, N_RT_3),
    (O_RT_4, N_RT_4),
    (O_RT_5, N_RT_5),
    (O_RT_6, N_RT_6),
    (O_RT_7, N_RT_7),
    (O_RT_8, N_RT_8),
    (O_RT_9, N_RT_9),
    (O_RT_10, N_RT_10),
    (O_RT_11, N_RT_11),
    (O_RT_12, N_RT_12),
    (O_RT_13, N_RT_13),
    (O_RT_14, N_RT_14),
    (O_RT_15, N_RT_15),
    (O_RT_16, N_RT_16),
    (O_RT_17, N_RT_17),
    (O_RT_18, N_RT_18),
    (O_RT_19, N_RT_19),
    (O_RT_20, N_RT_20),
    (O_RT_21, N_RT_21),
]

O_GP_0 = r"""
- [ ] Armor Class Table (p. 26).
"""[1:-1]
N_GP_0 = r"""
- [x] Armor Class Table (p. 26).
      - AMENDED R392: closed - the R371 pin (pp. 75-76) plus the R191
        seam; the R392 clean p. 26 print agrees row for row
"""[1:-1]

O_GP_1 = r"""
- [ ] Attacks Per Melee Round Table (p.
      22).
"""[1:-1]
N_GP_1 = r"""
- [x] Attacks Per Melee Round Table (p.
      22).
      - AMENDED R392: closed - the R334 bands (rules/thiefarmor.h);
        the R392 clean print confirms
"""[1:-1]

O_GP_2 = r"""
- [ ] Barbarians (Fighters) Table I (p.
      19).
"""[1:-1]
N_GP_2 = r"""
- [x] Barbarians (Fighters) Table I (p.
      19).
      - AMENDED R392: closed - the R332 pin (rules/barbarian.h)
"""[1:-1]

O_GP_3 = r"""
- [ ] Cavaliers Table I (p. 15).
"""[1:-1]
N_GP_3 = r"""
- [x] Cavaliers Table I (p. 15).
      - AMENDED R392: closed - the R368 pin (rules/uacavtable.h)
"""[1:-1]

O_GP_4 = r"""
- [ ] Character Class Limitations
      (Character Race Table I) (p. 7).
"""[1:-1]
N_GP_4 = r"""
- [x] Character Class Limitations
      (Character Race Table I) (p. 7).
      - AMENDED R392: closed - the R323 pin (rules/subraces.h)
"""[1:-1]

O_GP_5 = r"""
- [ ] Character Level Limitations
      (Character Race Table II) (pp.
      8-9, the six sub-tables).
"""[1:-1]
N_GP_5 = r"""
- [x] Character Level Limitations
      (Character Race Table II) (pp.
      8-9, the six sub-tables).
      - AMENDED R392: closed - the R324 pin (rules/subracelevels.h)
"""[1:-1]

O_GP_6 = r"""
- [ ] Character Hit Dice, Spell Ability,
      Class Level Limit (Character
      Classes Table I) (p. 12).
"""[1:-1]
N_GP_6 = r"""
- [x] Character Hit Dice, Spell Ability,
      Class Level Limit (Character
      Classes Table I) (p. 12).
      - AMENDED R392: closed - the R327 pin (rules/classtables.h)
"""[1:-1]

O_GP_7 = r"""
- [ ] Character Armor and Weapons
      Permitted (Character Classes Table
      II) (p. 13).
"""[1:-1]
N_GP_7 = r"""
- [x] Character Armor and Weapons
      Permitted (Character Classes Table
      II) (p. 13).
      - AMENDED R392: closed - the R327 pin (rules/classtables.h)
"""[1:-1]

O_GP_8 = r"""
- [ ] Druids (Clerics) Table I (p. 17).
"""[1:-1]
N_GP_8 = r"""
- [x] Druids (Clerics) Table I (p. 17).
      - AMENDED R392: closed - the R330 pin (rules/hierophant.h)
"""[1:-1]

O_GP_9 = r"""
- [ ] Equipment and Supplies Costs (p.
      26).
"""[1:-1]
N_GP_9 = r"""
- [x] Equipment and Supplies Costs (p.
      26).
      - AMENDED R392: PINNED R392 (rules/uaequip26.h) - the clean p.
        26 print, four armor rows plus 19 arms rows, no holes
"""[1:-1]

O_GP_10 = r"""
- [ ] Racial Preferences Table (p. 12).
"""[1:-1]
N_GP_10 = r"""
- [x] Racial Preferences Table (p. 12).
      - AMENDED R392: closed - the R323 pin (rules/subraces.h)
"""[1:-1]

O_GP_11 = r"""
- [ ] Spell Tables (pp. 28-31): clerics
      28-29, druids 29, magic-users
      30-31, illusionists 31.
"""[1:-1]
N_GP_11 = r"""
- [x] Spell Tables (pp. 28-31): clerics
      28-29, druids 29, magic-users
      30-31, illusionists 31.
      - AMENDED R392: closed - the R341-R366 pins (the four
        spell-table rounds)
"""[1:-1]

O_GP_12 = r"""
- [ ] Thief-Acrobat Function Table (p.
      24).
"""[1:-1]
N_GP_12 = r"""
- [x] Thief-Acrobat Function Table (p.
      24).
      - AMENDED R392: closed - the R335 pin (rules/acrobat.h)
"""[1:-1]

O_GP_13 = r"""
- [ ] Thief-Acrobat Table I (p. 23),
      Table II (p. 25), Table III (p.
      25), Table IV (p. 25).
"""[1:-1]
N_GP_13 = r"""
- [x] Thief-Acrobat Table I (p. 23),
      Table II (p. 25), Table III (p.
      25), Table IV (p. 25).
      - AMENDED R392: closed - the R335 pin (rules/acrobat.h)
"""[1:-1]

O_GP_14 = r"""
- [ ] Thieves Table II (p. 22).
"""[1:-1]
N_GP_14 = r"""
- [x] Thieves Table II (p. 22).
      - AMENDED R392: closed - the R334 pin (rules/thiefarmor.h)
"""[1:-1]

O_GP_15 = r"""
- [ ] Weapon Proficiency Table (p. 26).
"""[1:-1]
N_GP_15 = r"""
- [x] Weapon Proficiency Table (p. 26).
      - AMENDED R392: closed - the R339 pin (rules/uaprof.h); the R392
        clean read fills every hole (the cavalier penalty 3, the
        paladin and assassin initials 3, the barbarian 6, the ranger
        3) and recovers the facing-page notes in full
"""[1:-1]

O_GP_16 = r"""
- [ ] Weapon Specialization Table for
      Fighters and Rangers (p. 18).
"""[1:-1]
N_GP_16 = r"""
- [x] Weapon Specialization Table for
      Fighters and Rangers (p. 18).
      - AMENDED R392: closed - the R331 pin (rules/weaponspec.h)
"""[1:-1]

O_GP_17 = r"""
- [ ] Weapons, Weight and Damage by
      Type (p. 26).
"""[1:-1]
N_GP_17 = r"""
- [x] Weapons, Weight and Damage by
      Type (p. 26).
      - AMENDED R392: closed - the R337 pin (rules/uaweapontable.h);
        the R392 clean read fills every hole (the atlatl 30, the
        harpoon 50-60, the falchion 60-80, the lasso dash), adds the
        68th row (the hand-crossbow quarrels) and reconciles the
        garrot L misdecode (1-6)
"""[1:-1]

O_GP_18 = r"""
- [ ] Weapons, Hand-held, General Data
      and To-Hit Adjustments (p. 27).
"""[1:-1]
N_GP_18 = r"""
- [x] Weapons, Hand-held, General Data
      and To-Hit Adjustments (p. 27).
      - AMENDED R392: PINNED R392 (rules/uahandheld.h) - the clean p.
        27 print, 60 rows, the footnotes and the general note, no
        holes
"""[1:-1]

O_GP_19 = r"""
- [ ] Weapons, Hurled and Missile,
      General Data and To-Hit
      Adjustments (p. 28).
"""[1:-1]
N_GP_19 = r"""
- [x] Weapons, Hurled and Missile,
      General Data and To-Hit
      Adjustments (p. 28).
      - AMENDED R392: closed - the R338 pin (rules/uamissile.h); the
        R392 clean read fills every hole (the rate column, the S/M/L
        ranges, the lost AC cells, the AC 7-10 columns) and the aklys
        10-foot footnote
"""[1:-1]

GP_PAIRS = [
    (O_GP_0, N_GP_0),
    (O_GP_1, N_GP_1),
    (O_GP_2, N_GP_2),
    (O_GP_3, N_GP_3),
    (O_GP_4, N_GP_4),
    (O_GP_5, N_GP_5),
    (O_GP_6, N_GP_6),
    (O_GP_7, N_GP_7),
    (O_GP_8, N_GP_8),
    (O_GP_9, N_GP_9),
    (O_GP_10, N_GP_10),
    (O_GP_11, N_GP_11),
    (O_GP_12, N_GP_12),
    (O_GP_13, N_GP_13),
    (O_GP_14, N_GP_14),
    (O_GP_15, N_GP_15),
    (O_GP_16, N_GP_16),
    (O_GP_17, N_GP_17),
    (O_GP_18, N_GP_18),
    (O_GP_19, N_GP_19),
]


# ---- (a) the seed: the R391
# record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
s = rd(SD)
if 'R391 landed 2026-10-12' in s:
    already.append('seed: the R391 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R391 record')
s = rd(SD)
assert s.count(
    'R391 landed 2026-10-12'
) == 1, 'a entry'
for r, d in (
    (390, '2026-10-12'),
    (389, '2026-10-12'),
    (388, '2026-10-12'),
    (387, '2026-10-12'),
    (386, '2026-10-12'),
    (385, '2026-10-12'),
    (384, '2026-10-12'),
    (383, '2026-10-12'),
    (382, '2026-10-12'),
    (381, '2026-10-12'),
    (380, '2026-10-12'),
    (379, '2026-10-12'),
    (378, '2026-10-12'),
    (377, '2026-10-12'),
    (376, '2026-10-12'),
    (375, '2026-10-12'),
    (374, '2026-10-12'),
    (373, '2026-10-12'),
    (372, '2026-10-12'),
    (371, '2026-10-12'),
    (370, '2026-10-12'),
    (369, '2026-10-12'),
    (368, '2026-10-12'),
    (367, '2026-10-12'),
    (366, '2026-10-12'),
    (365, '2026-10-12'),
    (364, '2026-10-11'),
    (363, '2026-10-11'),
    (362, '2026-10-11'),
    (361, '2026-10-11'),
    (360, '2026-10-11'),
    (359, '2026-10-11'),
    (358, '2026-10-11'),
    (357, '2026-10-11'),
    (356, '2026-10-11'),
    (355, '2026-10-11'),
    (354, '2026-10-11'),
    (353, '2026-10-11'),
    (352, '2026-10-11'),
    (351, '2026-10-11'),
    (350, '2026-10-11'),
    (349, '2026-10-11'),
    (348, '2026-10-11'),
    (347, '2026-10-11'),
    (346, '2026-10-11'),
    (345, '2026-10-11'),
    (344, '2026-10-11'),
    (343, '2026-10-11'),
):
    t = 'R%d landed %s' % (r, d)
    lab = 'a kept R%d' % r
    assert s.count(t) == 1, lab
assert s.count(
    '## Knowledge maintenance'
) == 1, 'a maint'


# ---- (b) NEW rules/uaequip26.h ----
P = 'rules/uaequip26.h'
if os.path.exists(P) and 'R392' in rd(P):
    already.append('uaequip26.h: the pins')
else:
    clean(HDR_EC, 78)
    wr(P, HDR_EC)
    applied.append('uaequip26.h: the pins')
assert rd(P).count(
    'uaecArmsPriceIsElectrum'
    ) == 1, 'b electrum'


# ---- (c) NEW rules/uahandheld.h ----
P = 'rules/uahandheld.h'
if os.path.exists(P) and 'R392' in rd(P):
    already.append('uahandheld.h: the pins')
else:
    clean(HDR_HH, 78)
    wr(P, HDR_HH)
    applied.append('uahandheld.h: the pins')
assert rd(P).count(
    'uahhAcAdjustment'
    ) == 1, 'c ac'
assert rd(P).count(
    'uahhDismountFlag'
    ) >= 1, 'c dm'


# ---- (d) rules/uaprof.h: the
# R392 reconcile ----
P = 'rules/uaprof.h'
s = rd(P)
if 'uapfHorsemenInitialSlots' in s:
    already.append('uaprof.h: the reconcile')
else:
    for old, new in PF_PAIRS:
        assert s.count(old) == 1, 'd pair'
        clean(new, 78)
        s = s.replace(old, new)
    wr(P, s)
    applied.append('uaprof.h: the reconcile')


# ---- (e) rules/uamissile.h: the
# R392 fills ----
P = 'rules/uamissile.h'
s = rd(P)
if 'uamtAklysTenFootOnly' in s:
    already.append('uamissile.h: the fills')
else:
    for old, new in UM_PAIRS:
        assert s.count(old) == 1, 'e pair'
        clean(new, 78)
        s = s.replace(old, new)
    wr(P, s)
    applied.append('uamissile.h: the fills')


# ---- (f) rules/uaweapontable.h:
# the R392 fills ----
P = 'rules/uaweapontable.h'
s = rd(P)
if 'uawtDamagePrintsDash' in s:
    already.append('uaweapontable.h: the fills')
else:
    for old, new in WT_PAIRS:
        assert s.count(old) == 1, 'f pair'
        clean(new, 78)
        s = s.replace(old, new)
    wr(P, s)
    applied.append('uaweapontable.h: the fills')


# ---- (g) the gap report: the
# 20-item manifest flip ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'AMENDED R392' in s:
    already.append('gap: the manifest amendments')
else:
    for old, new in GP_PAIRS:
        assert s.count(old) == 1, 'g pair'
        clean(new, 70)
        s = s.replace(old, new)
    assert s.count(
        'AMENDED R392') == 20, 'g count'
    wr(GP, s)
    applied.append('gap: the manifest amendments')


# ---- (h) regtest.cpp: the
# includes, the amendments, the
# R392 audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R392 UA players tables pin audit' in s:
    already.append('regtest.cpp: the R392 audit')
else:
    for old, new in RT_PAIRS:
        assert s.count(old) == 1, 'h pair'
        clean(new, 76)
        s = s.replace(old, new)
    AUD_ANCH = (
        '    // ---- R227: the wis mental save'
        ' wiring audit ----'
    )
    assert s.count(AUD_ANCH) == 1, 'h anchor'
    s = s.replace(AUD_ANCH, AUDIT392 + NL +
                  AUD_ANCH)
    wr(RT, s)
    applied.append('regtest.cpp: the R392 audit')

# the final asserts
s = rd(RT)
assert s.count('audit: bad ') == 319, 'd census'
assert s.count(
    'R392 UA players tables pin audit: bad '
) == 1, 'd label'
assert s.count(
    'R391 UA pole-arm nomenclature pin audit: bad '
) == 1, 'd kept label'
assert s.count(
    'R390 UA non-lethal combat pin audit: bad '
) == 1, 'd kept label'
assert s.count(
    'R389 UA weaponless combat pin audit: bad '
) == 1, 'd kept label'
assert s.count(
    'R388 UA misc weapons prose pin audit: bad '
) == 1, 'd kept label'
assert s.count(
    'R387 UA armor and swords prose pin audit: bad '
) == 1, 'd kept label'
assert s.count(
    'R386 UA misc magic prose part 6 pin audit: bad '
) == 1, 'd kept label'
assert s.count(
    'R385 UA misc magic prose part 5 pin audit: bad '
) == 1, 'd kept label'
for h in (
    'rules/uaequip26.h',
    'rules/uahandheld.h',
    'rules/uaappendt.h',
    'rules/uaweapontable.h',
    'rules/uamissile.h',
    'rules/uaprof.h',
):
    assert s.count(
        '#include "' + h + '"') == 1, 'd kept include'
assert s.count(
    'R227: the wis mental save'
) == 1, 'd r227 kept'
s = rd(GP)
assert s.count(
    'AMENDED R391'
    ) >= 1, 'g r391 kept'
assert s.count('AMENDED R392') == 20, 'g notes'
for r in range(375, 392):
    assert s.count(
        'AMENDED R%d' % r
        ) == 1, 'g kept R%d' % r
assert len(applied) + len(already) == 8, 'count'


# ---- the summary ----
print(
    'R392 splice: ALL OK (applied %d, already %d)'
    % (len(applied), len(already)))
NOTE = NL.join([
    'R392 note: the players',
    'tables manifest sweep - the',
    'equipment costs table and the',
    'hand-held table pin NEW; the',
    'weight/damage, missile and',
    'proficiency tables amend (the',
    'clean PDF read: every hole',
    'fills, the garrot L, the',
    'barbarian and ranger initials',
    'reconcile, the 68th row, the',
    'rate/range columns, the AC',
    '7-10 ladders, the facing-page',
    'notes); the manifest closes;',
    'the census 318 -> 319',
])
print(NOTE)
print('commit: R392: the players')
print('tables manifest sweep')
print('(census 319)')

