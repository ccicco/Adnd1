#!/usr/bin/env python3
# R110 splice: SAVING THROWS - the book's matrix I (DMG p.79-80),
# banded per class, plus the natural-1-always-fails rule and the
# monster matrix II HD-to-level stepping. The per-level linear rows
# (PHB-derived, off by up to 4: cleric L1 death save was 14, the book
# says 10) are replaced wholesale. The battery gains the R110 saves
# audit; the gap report flips its box in this same commit.

import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def read(rel):
    with open(os.path.join(ROOT, rel), "r", encoding="ascii") as f:
        return f.read()


def write(rel, text):
    with open(os.path.join(ROOT, rel), "w", encoding="ascii",
              newline="\n") as f:
        f.write(text)


def replace_exact(old_text, anchor, replacement, what):
    if replacement == "":
        # deletion: applied means the anchor is already gone
        if anchor not in old_text:
            print("already applied: " + what)
            return old_text, False
        if old_text.count(anchor) != 1:
            print("REFUSED " + what + ": anchor not unique")
            sys.exit(1)
        print("patched: " + what)
        return old_text.replace(anchor, replacement), True
    if replacement in old_text:
        print("already applied: " + what)
        return old_text, False
    if old_text.count(anchor) != 1:
        print("REFUSED " + what + ": anchor not unique or missing")
        sys.exit(1)
    print("patched: " + what)
    return old_text.replace(anchor, replacement), True


def main():
    changed = False

    c = read("rules/saves.cpp")
    c, did = replace_exact(c, SAVES_OLD, SAVES_NEW, "saves.cpp banded matrices")
    changed = changed or did
    c, did = replace_exact(c, INC_OLD, "", "saves.cpp include prune")
    changed = changed or did
    c, did = replace_exact(c, ASAVE_OLD, ASAVE_NEW, "saves.cpp natural-1 rule")
    changed = changed or did
    c, did = replace_exact(c, MSAVE_OLD, MSAVE_NEW, "saves.cpp monster stepping")
    changed = changed or did
    write("rules/saves.cpp", c)

    h = read("rules/saves.h")
    h, did = replace_exact(h, HSRC_OLD, HSRC_NEW, "saves.h source note")
    changed = changed or did
    h, did = replace_exact(h, HATT_OLD, HATT_NEW, "saves.h attemptSave note")
    changed = changed or did
    h, did = replace_exact(h, HMON_OLD, HMON_NEW, "saves.h monster decl")
    changed = changed or did
    write("rules/saves.h", h)

    r = read("regtest.cpp")
    r, did = replace_exact(r, RINC_OLD, RINC_NEW, "regtest saves include")
    changed = changed or did
    r, did = replace_exact(r, RT_OLD, RT_NEW, "regtest R110 audit")
    changed = changed or did
    write("regtest.cpp", r)

    g = read("tools/dmg_gap_report.md")
    g, did = replace_exact(g, GHEAD_OLD, GHEAD_NEW, "gap report header note")
    changed = changed or did
    g, did = replace_exact(g, GMON_OLD, GMON_NEW, "gap report monster bullet")
    changed = changed or did
    g, did = replace_exact(g, GSAV_OLD, GSAV_NEW, "gap report saves box")
    changed = changed or did
    write("tools/dmg_gap_report.md", g)

    print("R110 splice: " +
          ("ALL OK" if changed else "nothing to do (already applied)"))


SAVES_OLD = """// ----------------------------------------------------------------------------
// Class save tables (PHB pp. 22-36).
//
// The PHB prints five-column tables per class. Encoded rows are levels
// 1-12 (the "prime line" levels); beyond 12, each level improves each
// category by 1 (floor 2) until the class's minimum column value.
// NOTE (rebuild): values follow the standard 1e table shape as recorded
// in the project notes. When the PHB PDF is re-uploaded, verify row by
// row - the printed table wins on any disagreement (verification debt,
// see knowledge file).
//
// fighter (PHB p.22):
//   L1: 15 16 17 17 18
//   L2: 14 15 16 16 17
//   L3: 13 14 15 15 16
//   L4: 12 13 14 14 15
//   L5: 11 12 13 13 14
//   L6: 10 11 12 12 13
//   L7:  9 10 11 11 12
//   L8:  8  9 10 10 11
//   L9:  7  8  9  9 10   (name level row)
//   L10-12 continue -1/level; min 2/3/4/4/5 per category convention.
//
// magic-user (PHB p.26), cleric (PHB p.31), thief (PHB p.28) follow the
// same structure with class-specific starting values:
//   MU L1:    14 15 13 16 12  (MUs save better vs spells, worse vs
//                              breath)
//   cleric L1: 14 15 13 16 15
//   thief L1:  13 14 12 16 15
// ----------------------------------------------------------------------------

static const int kSaveRows = 12;

static const int kSaves[4][kSaveRows][SAVE_COUNT] = {
    /* fighter */
    { {15,16,17,17,18},{14,15,16,16,17},{13,14,15,15,16},
      {12,13,14,14,15},{11,12,13,13,14},{10,11,12,12,13},
      { 9,10,11,11,12},{ 8, 9,10,10,11},{ 7, 8, 9, 9,10},
      { 6, 7, 8, 8, 9},{ 5, 6, 7, 7, 8},{ 4, 5, 6, 6, 7} },
    /* magic-user */
    { {14,15,13,16,12},{13,14,12,15,11},{12,13,11,14,10},
      {11,12,10,13, 9},{10,11, 9,12, 8},{ 9,10, 8,11, 7},
      { 8, 9, 7,10, 6},{ 7, 8, 6, 9, 5},{ 6, 7, 5, 8, 4},
      { 5, 6, 4, 7, 3},{ 4, 5, 3, 6, 2},{ 3, 4, 2, 5, 2} },
    /* cleric */
    { {14,15,13,16,15},{13,14,12,15,14},{12,13,11,14,13},
      {11,12,10,13,12},{10,11, 9,12,11},{ 9,10, 8,11,10},
      { 8, 9, 7,10, 9},{ 7, 8, 6, 9, 8},{ 6, 7, 5, 8, 7},
      { 5, 6, 4, 7, 6},{ 4, 5, 3, 6, 5},{ 3, 4, 2, 5, 4} },
    /* thief */
    { {13,14,12,16,15},{12,13,11,15,14},{11,12,10,14,13},
      {10,11, 9,13,12},{ 9,10, 8,12,11},{ 8, 9, 7,11,10},
      { 7, 8, 6,10, 9},{ 6, 7, 5, 9, 8},{ 5, 6, 4, 8, 7},
      { 4, 5, 3, 7, 6},{ 3, 4, 2, 6, 5},{ 2, 3, 2, 5, 4} },
};

// Per-class minimum target per category (never improves below this).
static const int kSaveMin[4][SAVE_COUNT] = {
    { 2, 3, 4, 4, 5 },   // fighter
    { 3, 4, 2, 5, 2 },   // MU (best spells saves)
    { 3, 4, 2, 5, 4 },
    { 2, 3, 2, 5, 4 },
};

int saveTarget(int classIndex, int level, SaveCategory cat) {
    if (classIndex < 0 || classIndex > 3) classIndex = 0;
    if (cat < 0 || cat >= SAVE_COUNT) cat = SAVE_DEATH_POISON;
    if (level < 1) level = 1;

    int row = level - 1;
    if (row < kSaveRows) return kSaves[classIndex][row][cat];

    // beyond encoded rows: -1 per level, floored at the class minimum
    int v = kSaves[classIndex][kSaveRows - 1][cat];
    v -= (level - kSaveRows);
    int minv = kSaveMin[classIndex][cat];
    return v < minv ? minv : v;
}
"""
SAVES_NEW = """// ----------------------------------------------------------------------------
// Class save matrices (DMG p.79-80, matrix I - the banded tables).
// The book bands levels per class; every level in a band shares the
// row, and the last band has no upper limit. Values are transcribed
// in the repo's SaveCategory order (Death, Wands, Petrify, Breath,
// Spells); the book prints Death, Petrify, Rod/Staff/Wand, Breath,
// Spell - transposed at transcription.
//   fighter (incl. paladins, rangers, 0 level): 0, 1-2, 3-4, 5-6,
//     7-8, 9-10, 11-12, 13-14, 15-16, 17+
//   cleric (incl. druids): 1-3, 4-6, 7-9, 10-12, 13-15, 16-18, 19+
//   magic-user (incl. illusionists): 1-5, 6-10, 11-15, 16-20, 21+
//   thief (incl. assassins, monks): 1-4, 5-8, 9-12, 13-16, 17-20, 21+
// ----------------------------------------------------------------------------

struct SaveBand { int upTo; int v[SAVE_COUNT]; };

static const SaveBand kFighterBands[] = {
    {  0, {16, 18, 17, 20, 19} },
    {  2, {14, 16, 15, 17, 17} },
    {  4, {13, 15, 14, 16, 16} },
    {  6, {11, 13, 12, 13, 14} },
    {  8, {10, 12, 11, 12, 13} },
    { 10, { 8, 10,  9,  9, 11} },
    { 12, { 7,  9,  8,  8, 10} },
    { 14, { 5,  7,  6,  5,  8} },
    { 16, { 4,  6,  5,  4,  7} },
    { 99, { 3,  5,  4,  4,  6} },
};
static const SaveBand kMagicUserBands[] = {
    {  5, {14, 11, 13, 15, 12} },
    { 10, {13,  9, 11, 13, 10} },
    { 15, {11,  7,  9, 11,  8} },
    { 20, {10,  5,  7,  9,  6} },
    { 99, { 8,  3,  5,  7,  4} },
};
static const SaveBand kClericBands[] = {
    {  3, {10, 14, 13, 16, 15} },
    {  6, { 9, 13, 12, 15, 14} },
    {  9, { 7, 11, 10, 13, 12} },
    { 12, { 6, 10,  9, 12, 11} },
    { 15, { 5,  9,  8, 11, 10} },
    { 18, { 4,  8,  7, 10,  9} },
    { 99, { 2,  6,  5,  8,  7} },
};
static const SaveBand kThiefBands[] = {
    {  4, {13, 14, 12, 16, 15} },
    {  8, {12, 12, 11, 15, 13} },
    { 12, {11, 10, 10, 14, 11} },
    { 16, {10,  8,  9, 13,  9} },
    { 20, { 9,  6,  8, 12,  7} },
    { 99, { 8,  4,  7, 11,  5} },
};

// classIndex order: 0 fighter, 1 magic-user, 2 cleric, 3 thief
// (CharClass order, see rules/classes.h)
static const SaveBand* const kClassBands[4] = {
    kFighterBands, kMagicUserBands, kClericBands, kThiefBands
};
static const int kClassBandCounts[4] = { 10, 5, 7, 6 };

int saveTarget(int classIndex, int level, SaveCategory cat) {
    if (classIndex < 0 || classIndex > 3) classIndex = 0;
    if (cat < 0 || cat >= SAVE_COUNT) cat = SAVE_DEATH_POISON;

    // fighters keep the book's separate 0-level row; the other
    // classes have no level 0 and clamp into their first band
    if (level < 1 && classIndex != 0) level = 1;
    if (level < 0) level = 0;

    const SaveBand* bands = kClassBands[classIndex];
    int n = kClassBandCounts[classIndex];
    for (int i = 0; i < n; ++i) {
        if (level <= bands[i].upTo)
            return bands[i].v[(int)cat];
    }
    return bands[n - 1].v[(int)cat];
}

// ----------------------------------------------------------------------------
// Monster HD -> save level (DMG p.80 matrix II.B): hit dice equate to
// experience level, with hit-point pluses stepping the creature up one
// die level per 4 points (1+1..1+4 becomes 2, 1+5..1+8 becomes 3,
// 2+1..2+4 also becomes 3, ...). Capped at 21 (the matrices' last band).
// ----------------------------------------------------------------------------

int monsterSaveLevel(float hitDice) {
    if (hitDice <= 0) return 1;
    int base = (int)hitDice;
    int plus = (int)(((hitDice - (float)base) * 4.0f) + 0.5f);
    int lvl = base + (plus + 3) / 4;
    if (lvl < 1) lvl = 1;
    if (lvl > 21) lvl = 21;
    return lvl;
}
"""
INC_OLD = """#include "combat.h"   // monsterEffectiveLevel
"""
ASAVE_OLD = """bool attemptSave(Dice& dice, int target, int modifier) {
    int roll = (int)dice.d20();
    return roll + modifier >= target;
}
"""
ASAVE_NEW = """bool attemptSave(Dice& dice, int target, int modifier) {
    int roll = (int)dice.d20();
    if (roll == 1) return false;   // DMG p.80: a roll of 1 is ALWAYS failure
    return roll + modifier >= target;
}
"""
MSAVE_OLD = """bool attemptMonsterSave(Dice& dice, float hitDice, SaveCategory cat,
                        int modifier) {
    int level = monsterEffectiveLevel(hitDice);
    // monsters use the fighter matrix
    int target = saveTarget(0, level, cat);
    return attemptSave(dice, target, modifier);
}
"""
MSAVE_NEW = """bool attemptMonsterSave(Dice& dice, float hitDice, SaveCategory cat,
                        int modifier) {
    // DMG p.80 matrix II: most monsters save as fighters at their
    // HD-derived level (the II.B stepping in monsterSaveLevel).
    // Monsters with class abilities use their most favorable matrix -
    // the caller's job, not this helper's.
    int level = monsterSaveLevel(hitDice);
    int target = saveTarget(0, level, cat);
    return attemptSave(dice, target, modifier);
}
"""
HSRC_OLD = """// Source: Players Handbook (2012 Premium reprint), class save tables
// (pp. 22-36) and Dungeon Masters Guide saving-throw rules (p. 80).
// Cross-checked against the 1979 TSR scan."""
HSRC_NEW = """// Source: Dungeon Masters Guide (Premium reprint) pp.79-80, saving
// throw matrices I and II - the banded per-class tables, the natural-1
// rule, and the monster HD-to-level rule. (The earlier PHB-derived
// linear rows were replaced by R110; the printed DMG table wins.)"""
HATT_OLD = """// attemptSave rolls d20 + modifier >= target.
"""
HATT_NEW = """// attemptSave rolls d20 + modifier >= target. A natural 1 is ALWAYS
// failure (DMG p.80), regardless of magical protections or modifiers.
"""
HMON_OLD = """// ----------------------------------------------------------------------------
// Monster saves (DMG p.80): monsters save on the fighter (men) save
// matrix at their effective level derived from hit dice. The DMG
// converts HD to a fighter level for saving throws the same way as
// for attacks.
// ----------------------------------------------------------------------------
bool attemptMonsterSave(Dice& dice, float hitDice, SaveCategory cat,
                        int modifier = 0);"""
HMON_NEW = """// ----------------------------------------------------------------------------
// Monster saves (DMG p.80 matrix II): monsters save on the character
// matrices - most as fighters. Hit dice equate to experience level,
// with hit-point pluses stepping the creature up one die level per
// 4 points (1+1..1+4 -> 2, 2+1..2+4 -> 3, ...).
// ----------------------------------------------------------------------------
int monsterSaveLevel(float hitDice);

bool attemptMonsterSave(Dice& dice, float hitDice, SaveCategory cat,
                        int modifier = 0);"""
RINC_OLD = "#include \"rules/combat.h\"\n#include \"spells/spells.h\""
RINC_NEW = "#include \"rules/combat.h\"\n#include \"rules/saves.h\"\n#include \"spells/spells.h\""
RT_OLD = """        printf("R109 turn audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;
            }
"""
RT_NEW = """        printf("R109 turn audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R110: saving throws audit (DMG p.79-80 matrix I) ----
    {
        int bad = 0;
        // the banded tables, pinned band by band (repo category
        // order: Death, Wands, Petrify, Breath, Spells)
        {
            struct SC { int cls, lvl, cat, want; };
            const SC sc[] = {
                // fighter 1-2 band
                {0, 1, rules::SAVE_DEATH_POISON,  14},
                {0, 1, rules::SAVE_WANDS,         16},
                {0, 1, rules::SAVE_PETRIFY_POLY,  15},
                {0, 1, rules::SAVE_BREATH,        17},
                {0, 1, rules::SAVE_SPELLS,        17},
                {0, 2, rules::SAVE_DEATH_POISON,  14},  // band mate
                {0, 0, rules::SAVE_DEATH_POISON,  16},  // 0-level row
                {0, 3, rules::SAVE_DEATH_POISON,  13},  // 3-4 band
                {0, 9, rules::SAVE_SPELLS,        11},  // 9-10 band
                {0, 9, rules::SAVE_BREATH,         9},  // dips below wands
                {0, 17, rules::SAVE_DEATH_POISON,  3},  // 17+ band
                {0, 25, rules::SAVE_DEATH_POISON,  3},  // beyond: last band
                // cleric - the big fix: L1 death save is 10, not 14
                {2, 1, rules::SAVE_DEATH_POISON,  10},
                {2, 1, rules::SAVE_WANDS,         14},
                {2, 3, rules::SAVE_DEATH_POISON,  10},  // band 1-3
                {2, 4, rules::SAVE_DEATH_POISON,   9},  // band 4-6
                {2, 12, rules::SAVE_SPELLS,        11}, // band 10-12
                {2, 19, rules::SAVE_DEATH_POISON,   2}, // 19+ band
                // magic-user
                {1, 1, rules::SAVE_DEATH_POISON,  14},
                {1, 1, rules::SAVE_WANDS,         11},
                {1, 5, rules::SAVE_SPELLS,        12},  // band 1-5
                {1, 6, rules::SAVE_SPELLS,        10},  // band 6-10
                {1, 21, rules::SAVE_SPELLS,         4}, // 21+ band
                {1, 25, rules::SAVE_SPELLS,         4},
                // thief (1-4 happens to match the old linear row)
                {3, 1, rules::SAVE_DEATH_POISON,  13},
                {3, 1, rules::SAVE_WANDS,         14},
                {3, 4, rules::SAVE_DEATH_POISON,  13},  // band 1-4
                {3, 5, rules::SAVE_DEATH_POISON,  12},  // band 5-8
                {3, 21, rules::SAVE_SPELLS,         5},  // 21+ band
            };
            for (const SC& s : sc) {
                if (rules::saveTarget(s.cls, s.lvl,
                                       (rules::SaveCategory)s.cat)
                    != s.want) ++bad;
            }
        }
        // the tables never worsen with level and stay in bounds
        for (int cls = 0; cls < 4; ++cls) {
            for (int cat = 0; cat < rules::SAVE_COUNT; ++cat) {
                int prev = 99;
                for (int lvl = 1; lvl <= 25; ++lvl) {
                    int v = rules::saveTarget(cls, lvl,
                                              (rules::SaveCategory)cat);
                    if (v < 2 || v > 20) ++bad;
                    if (v > prev) ++bad;
                    prev = v;
                }
            }
        }
        // monster HD -> save level (matrix II.B stepping)
        {
            const float hds[]  = { 0.5f, 1.0f, 1.25f, 1.5f, 1.75f,
                                  2.25f, 2.5f, 4.8f, 16.0f, 40.0f };
            const int   want[] = { 1, 1, 2, 2, 2, 3, 3, 5, 16, 21 };
            for (int i = 0; i < 10; ++i)
                if (rules::monsterSaveLevel(hds[i]) != want[i]) ++bad;
        }
        // a natural 1 is ALWAYS failure, whatever the modifier
        {
            rules::Rng rng(110);
            rules::Dice dice(rng);
            int fails = 0;
            for (int i = 0; i < 20000; ++i) {
                // target 1, modifier +19: only a natural 1 fails
                if (!rules::attemptSave(dice, 1, 19)) ++fails;
            }
            if (fails == 0 || fails == 20000) ++bad;
        }
        printf("R110 saves audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;
            }
"""
GHEAD_OLD = """R109 CLOSED divergence 1 of 6 (turning undead);
the remaining five stay ranked below."""
GHEAD_NEW = """R109 CLOSED divergence 1 of 6 (turning undead).
R110 CLOSED divergence 2 of 6 (saving throws);
the remaining four stay ranked below."""
GMON_OLD = """- [x] **Monster saves use character matrices
      (p.79-80, matrix II)** - the book's rule
      that all monsters save as characters, HD
      equating to level with +hp stepping, is
      the repo's approach; the per-class value
      divergence is logged below under saves."""
GMON_NEW = """- [x] **Monster saves use character matrices
      (p.79-80, matrix II)** - the book's rule
      that all monsters save as characters, with
      HD equating to level and +hp stepping by
      4, is the repo's approach; R110 aligned
      the character matrices and added the
      book's own HD-to-level stepping
      (monsterSaveLevel)."""
GSAV_OLD = """- [~] 2. **Saving throws (p.79-80, matrix I)** -
      the book bands levels per class; the repo
      uses per-level linear rows. Book fighter
      1-2: PPDM 14, Petrify 15, Rod/Wand 16,
      Breath 17, Spell 17 - the repo's level-1
      fighter row is off by one in three
      categories. Book cleric 1-3 PPDM is 10;
      the repo's level-1 cleric death save is
      14, four points harsher - the biggest
      single-value miss. Book MU 1-5 PPDM 14,
      Petrify 13, Rod/Wand 11; thief 1-4
      13/12/14/16/15 - the thief happens to be
      exact, the MU is wrong in two of five.
      Divergence grows with level (book bands
      improve in steps; the repo subtracts one
      per level). Also: book rule "a roll of 1
      is ALWAYS failure". Second fix candidate."""
GSAV_NEW = """- [x] 2. **Saving throws (p.79-80, matrix I)** -
      CLOSED R110. The repo now carries the
      book's BANDED matrices per class
      (fighter 0/1-2/.../17+ incl. the 0-level
      row; cleric 1-3/.../19+; MU 1-5/.../21+;
      thief 1-4/.../21+), replacing the
      per-level linear rows. The headline fix:
      the cleric level-1 death save is now the
      book's 10 (was 14). Also landed: the
      book's rule that a natural 1 is ALWAYS
      failure, and the monster matrix II rule -
      HD equates to level with +hp stepping by
      4 (monsterSaveLevel). Pinned by the R110
      battery audit."""


main()
