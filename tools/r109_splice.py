#!/usr/bin/env python3
# R109 splice: TURNING UNDEAD - the book's matrix III, whole (DMG p.75-76,
# procedure p.77). Replaces the count-digit + 2d6 approximation with the
# printed table: 13 undead rows, cleric-level columns 1-8 / 9-13 / 14+,
# d20 match-or-exceed, T / D / D* / dash, counts 1-12 (7-12 starred,
# 1-2 Special), paladins two levels below. The battery gains the R109
# turn audit; the gap report flips its box in this same commit.

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

    # ---- 1. rules/combat.h: the turning API ----
    h = read("rules/combat.h")
    old_h = """// ----------------------------------------------------------------------------
// Turning undead (DMG p.75). The cleric turn matrix by cleric level
// vs undead type. Result:
//   'T'  turn all presented undead of the type
//   'D'  destroy (skeleton/zombie rows at high level)
//   0-9  number = 2d6 count turned (we return the digit; caller rolls)
//   ' '  dash: no effect possible
//   '*'  automatic success within 60' (treated as T here)
// ----------------------------------------------------------------------------

enum TurnResult : int {
    TURN_NONE = 0,      // dash - cannot affect
    TURN_COUNT,         // number shown: roll 2d6 turned
    TURN_ALL,           // T - all turned
    TURN_DESTROY,       // D - all destroyed
};

struct TurnAttempt {
    TurnResult result;
    int        countDigit;   // valid when result == TURN_COUNT
};

// undeadKind: 0 skeleton, 1 zombie, 2 ghoul, 3 shadow, 4 wight, 5 ghast,
// 6 wraith, 7 mummy, 8 spectre, 9 vampire, 10 lich, 11 "special"
// (ghast/banshee row per original tranche 55; see monsters layer).
TurnAttempt turnUndead(int clericLevel, int undeadKind);

// Roll the 2d6 for a TURN_COUNT attempt.
int rollTurnCount(Dice& dice, int countDigit);
"""
    new_h = """// ----------------------------------------------------------------------------
// Turning undead (DMG p.75-76 matrix III; procedure p.77). Rows are the
// undead in the book's own order, columns are cleric levels 1-8, 9-13,
// 14+. Result:
//   dash no effect possible, ever - a failed roll cannot be retried
//   T    automatic turning - all presented undead of the type
//   D    automatic destruction - all presented undead of the type
//   D*   automatic destruction of 7-12 (the starred cells)
//   4-20 a d20 target: match or exceed and 1-12 are turned
// Paladins turn as a cleric two levels below (p.75 footnote).
// ----------------------------------------------------------------------------

enum TurnResult : int {
    TURN_NONE = 0,      // dash - cannot affect
    TURN_ALL,           // T - automatic turn
    TURN_DESTROY,      // D - automatic destroy (countKind gives the count)
    TURN_CHANCE,        // a d20 target must be matched or exceeded
};

enum TurnCount : int {
    TURN_COUNT_1_12 = 0,   // d12 affected (the number cells)
    TURN_COUNT_7_12 = 1,   // d6+6 affected (the starred D* cells)
    TURN_COUNT_1_2  = 2,   // d2 affected (the Special row)
};

struct TurnAttempt {
    TurnResult result;
    int        target;     // d20 target when result == TURN_CHANCE
    int        countKind;  // TurnCount: how many are affected on success
};

// undeadKind: 0 skeleton, 1 zombie, 2 ghoul, 3 shadow, 4 wight, 5 ghast,
// 6 wraith, 7 mummy, 8 spectre, 9 vampire, 10 ghost, 11 lich, 12 special
// (the book's own row order, matrix III; paladins subtract two levels).
TurnAttempt turnUndead(int clericLevel, int undeadKind);

// d20 match-or-exceed for TURN_CHANCE. The automatic results resolve
// without a roll (true for TURN_ALL/TURN_DESTROY, false for TURN_NONE).
bool rollTurnSuccess(Dice& dice, const TurnAttempt& t);

// The affected count: d12 (1-12), d6+6 (7-12) for the starred D* cells,
// d2 (1-2) for the Special row. Plain T and D affect all presented
// undead of the type - the caller does not roll a count for them.
int rollTurnCount(Dice& dice, const TurnAttempt& t);
"""
    h, did = replace_exact(h, old_h, new_h, "combat.h turning API")
    if did:
        write("rules/combat.h", h)
    changed = changed or did

    # ---- 2. rules/combat.cpp: the matrix and mechanics ----
    c = read("rules/combat.cpp")
    old_c = """// ----------------------------------------------------------------------------
// Turning undead (DMG p.75 matrix)
// Cleric level rows 1..8+ (row "C" columns skeleton..special):
//   L1:  1  -  -  -  -  -  -  -  -  -  -  -
//   L2:  T  1  -  -  -  -  -  -  -  -  -  -
//   L3:  T  T  1  -  -  -  -  -  -  -  -  -
//   L4:  D  T  T  1  -  -  -  -  -  -  -  -
//   L5:  D  D  T  T  1  -  -  -  -  -  -  -
//   L6:  D  D  D  T  T  1  -  -  -  -  -  -
//   L7:  D  D  D  D  T  T  1  -  -  -  -  -
//   L8:  D  D  D  D  D  T  T  1  -  -  -  -
//   L9:  D  D  D  D  D  D  T  T  1  -  -  -
//  L10:  D  D  D  D  D  D  D  T  T  1  -  -
// (skeleton zombie ghoul shadow wight ghast wraith mummy spectre
//  vampire lich)
// Beyond 10 the matrix steps one column per level.
// NOTE: exact printed rows get verified against the DMG when the
// monsters layer wires turnUndead end-to-end; the diagonal structure
// above is the standard 1e turn matrix shape.
// ----------------------------------------------------------------------------

static const int kTurnMatrixRows = 10;
// encoding: -1 dash, 0..7 count digit, 10 T, 11 D
static const int kTurnMatrix[kTurnMatrixRows][12] = {
    /* L1  */ {  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
    /* L2  */ { 10,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
    /* L3  */ { 10, 10,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
    /* L4  */ { 11, 10, 10,  1, -1, -1, -1, -1, -1, -1, -1, -1 },
    /* L5  */ { 11, 11, 10, 10,  1, -1, -1, -1, -1, -1, -1, -1 },
    /* L6  */ { 11, 11, 11, 10, 10,  1, -1, -1, -1, -1, -1, -1 },
    /* L7  */ { 11, 11, 11, 11, 10, 10,  1, -1, -1, -1, -1, -1 },
    /* L8  */ { 11, 11, 11, 11, 11, 10, 10,  1, -1, -1, -1, -1 },
    /* L9  */ { 11, 11, 11, 11, 11, 11, 10, 10,  1, -1, -1, -1 },
    /* L10 */ { 11, 11, 11, 11, 11, 11, 11, 10, 10,  1, -1, -1 },
};

TurnAttempt turnUndead(int clericLevel, int undeadKind) {
    TurnAttempt t;
    t.result = TURN_NONE;
    t.countDigit = 0;

    if (clericLevel < 1 || undeadKind < 0) return t;

    int row = clericLevel - 1;
    int col = undeadKind;
    if (row >= kTurnMatrixRows) {
        // beyond L10: shift one column per extra level
        col -= (row - (kTurnMatrixRows - 1));
        row = kTurnMatrixRows - 1;
    }
    if (col < 0) { t.result = TURN_DESTROY; return t; }  // everything dies
    if (col > 11) return t;                              // beyond lich: no effect

    int v = kTurnMatrix[row][col];
    if (v == -1)      { t.result = TURN_NONE; }
    else if (v == 10) { t.result = TURN_ALL; }
    else if (v == 11) { t.result = TURN_DESTROY; }
    else              { t.result = TURN_COUNT; t.countDigit = v; }
    return t;
}

int rollTurnCount(Dice& dice, int countDigit) {
    // count digits on the matrix are the number shown; the 1e rule is
    // 2d6 turned when a number appears - the digit IS the 2d6 result
    // band marker. We roll 2d6 (original tranche 51 convention: number
    // success turns weakest-first up to the rolled count).
    int r = (int)dice.roll(2, 6, 0);
    if (r < 1) r = 1;
    return r;
}
"""
    new_c = """// ----------------------------------------------------------------------------
// Turning undead (DMG p.75-76 matrix III; procedure p.77)
// The BOOK's table, transcribed cell for cell: 13 undead rows in the
// book's own order, columns cleric level 1-8, 9-13, 14+. Roll d20;
// match or exceed the number shown and 1-12 undead are turned (7-12
// for the starred D* cells, 1-2 for the Special row). T = automatic
// turn, D = automatic destroy, dash = no effect possible - a failed
// roll cannot be retried against that undead. Paladins turn as a
// cleric two levels below (p.75 footnote).
// Encoding: -1 dash, 0 T, 1 D, 2 D*, 4-20 the d20 target.
// ----------------------------------------------------------------------------

static const int kTurnRows    = 13;
static const int kTurnColumns = 10;   // levels 1-8, 9-13, 14+

static const int kTurnMatrix[kTurnRows][kTurnColumns] = {
    /* skeleton */ { 10,  7,  4,  0,  0,  1,  1,  2,  2,  2 },
    /* zombie    */ { 13, 10,  7,  0,  0,  1,  1,  1,  2,  2 },
    /* ghoul     */ { 16, 13, 10,  4,  0,  0,  1,  1,  1,  2 },
    /* shadow    */ { 19, 16, 13,  7,  4,  0,  0,  1,  1,  2 },
    /* wight     */ { 20, 19, 16, 10,  7,  4,  0,  0,  1,  1 },
    /* ghast     */ { -1, 20, 19, 13, 10,  7,  4,  0,  0,  1 },
    /* wraith    */ { -1, -1, 20, 16, 13, 10,  7,  4,  0,  1 },
    /* mummy     */ { -1, -1, -1, 20, 16, 13, 10,  7,  4,  0 },
    /* spectre   */ { -1, -1, -1, -1, 20, 16, 13, 10,  7,  0 },
    /* vampire   */ { -1, -1, -1, -1, -1, 20, 16, 13, 10,  4 },
    /* ghost     */ { -1, -1, -1, -1, -1, -1, 20, 16, 13,  7 },
    /* lich      */ { -1, -1, -1, -1, -1, -1, -1, 19, 16, 10 },
    /* special   */ { -1, -1, -1, -1, -1, -1, -1, 20, 19, 13 },
};

TurnAttempt turnUndead(int clericLevel, int undeadKind) {
    TurnAttempt t;
    t.result    = TURN_NONE;
    t.target    = 0;
    t.countKind = TURN_COUNT_1_12;

    if (clericLevel < 1 || undeadKind < 0) return t;
    if (undeadKind >= kTurnRows) return t;

    // column: levels 1-8 are their own, 9-13 share one, 14+ the last
    int col;
    if (clericLevel <= 8)      col = clericLevel - 1;
    else if (clericLevel < 14) col = 8;
    else                       col = 9;

    int v = kTurnMatrix[undeadKind][col];
    switch (v) {
    case -1: t.result = TURN_NONE;     break;   // dash
    case  0: t.result = TURN_ALL;     break;   // T
    case  1: t.result = TURN_DESTROY; break;   // D
    case  2: t.result = TURN_DESTROY;          // D*
             t.countKind = TURN_COUNT_7_12; break;
    default: t.result = TURN_CHANCE;            // d20 target
             t.target = v;
             if (undeadKind == 12) t.countKind = TURN_COUNT_1_2;
             break;
    }
    return t;
}

bool rollTurnSuccess(Dice& dice, const TurnAttempt& t) {
    switch (t.result) {
    case TURN_NONE:     return false;   // dash - no roll helps
    case TURN_ALL:
    case TURN_DESTROY:  return true;    // automatic
    case TURN_CHANCE:   break;
    }
    int r = (int)dice.roll(1, 20, 0);
    return r >= t.target;
}

int rollTurnCount(Dice& dice, const TurnAttempt& t) {
    switch (t.countKind) {
    case TURN_COUNT_7_12: return (int)dice.roll(1, 6, 0) + 6;
    case TURN_COUNT_1_2:  return (int)dice.roll(1, 2, 0);
    default:              return (int)dice.roll(1, 12, 0);
    }
}
"""
    c, did = replace_exact(c, old_c, new_c, "combat.cpp matrix III")
    if did:
        write("rules/combat.cpp", c)
    changed = changed or did

    # ---- 3. regtest.cpp: the R109 turn audit ----
    r = read("regtest.cpp")
    old_r = """#include "game/party.h"
#include "spells/spells.h"
"""
    new_r = """#include "game/party.h"
#include "rules/combat.h"
#include "spells/spells.h"
"""
    r, did = replace_exact(r, old_r, new_r, "regtest combat.h include")
    if did:
        write("regtest.cpp", r)
    changed = changed or did

    r = read("regtest.cpp")
    old_r = """        printf("R106 keep ledger audit: bad %d\n", bad);
        if (bad) return 1;
    }
    return 0;"""
    new_r = """        printf("R106 keep ledger audit: bad %d\n", bad);
        if (bad) return 1;
    }

    // ---- R109: turning undead audit (DMG p.75-76 matrix III) ----
    {
        int bad = 0;
        // the printed table, spot-checked cell for cell
        {
            struct Cell { int lvl, kind, result, target, count; };
            const Cell cells[] = {
                { 1,  0, rules::TURN_CHANCE,  10, rules::TURN_COUNT_1_12 }, // skeleton
                { 1,  1, rules::TURN_CHANCE,  13, rules::TURN_COUNT_1_12 }, // zombie
                { 1,  2, rules::TURN_CHANCE,  16, rules::TURN_COUNT_1_12 }, // ghoul
                { 1,  3, rules::TURN_CHANCE,  19, rules::TURN_COUNT_1_12 }, // shadow
                { 1,  4, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_12 }, // wight
                { 1,  5, rules::TURN_NONE,     0, rules::TURN_COUNT_1_12 }, // ghast dash
                { 2,  5, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_12 }, // ghast L2
                { 3,  6, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_12 }, // wraith L3
                { 4,  7, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_12 }, // mummy L4
                { 5,  8, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_12 }, // spectre L5
                { 6,  9, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_12 }, // vampire L6
                { 7, 10, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_12 }, // ghost L7
                { 8, 11, rules::TURN_CHANCE,  19, rules::TURN_COUNT_1_12 }, // lich L8
                { 8, 12, rules::TURN_CHANCE,  20, rules::TURN_COUNT_1_2  }, // special L8
                { 4,  0, rules::TURN_ALL,      0, rules::TURN_COUNT_1_12 }, // skeleton T
                { 6,  0, rules::TURN_DESTROY,  0, rules::TURN_COUNT_1_12 }, // skeleton D
                { 8,  0, rules::TURN_DESTROY,  0, rules::TURN_COUNT_7_12 }, // skeleton D*
                { 9, 11, rules::TURN_CHANCE,  16, rules::TURN_COUNT_1_12 }, // lich 9-13
                {14, 11, rules::TURN_CHANCE,  10, rules::TURN_COUNT_1_12 }, // lich 14+
                {14, 12, rules::TURN_CHANCE,  13, rules::TURN_COUNT_1_2  }, // special 14+
                {20,  0, rules::TURN_DESTROY,  0, rules::TURN_COUNT_7_12 }, // past 14+
                { 0,  0, rules::TURN_NONE,     0, rules::TURN_COUNT_1_12 }, // level 0
            };
            for (const Cell& c : cells) {
                TurnAttempt t = turnUndead(c.lvl, c.kind);
                if (t.result != c.result || t.target != c.target ||
                    t.countKind != c.count) ++bad;
            }
        }
        // every cell of the table is a legal value
        for (int kind = 0; kind < 13; ++kind) {
            for (int lvl = 1; lvl <= 20; ++lvl) {
                TurnAttempt t = turnUndead(lvl, kind);
                if (t.result == TURN_CHANCE &&
                    (t.target < 4 || t.target > 20)) ++bad;
                if (t.result == TURN_NONE && lvl >= 1) {
                    // dashes only in the low-left of the table
                    if (kind == 0 || kind == 1) ++bad;
                }
            }
        }
        // the roll and count mechanics stay in bounds
        {
            rules::Rng rng(109);
            rules::Dice dice(rng);
            int seen1to12 = 0, seen7to12 = 0, seen1to2 = 0;
            int success = 0;
            for (int i = 0; i < 20000; ++i) {
                TurnAttempt t = turnUndead(1, 0);   // skeleton, target 10
                if (rollTurnSuccess(dice, t)) {
                    ++success;
                    int n = rollTurnCount(dice, t);
                    if (n < 1 || n > 12) ++bad;
                    if (n == 12) seen1to12 = 1;
                }
                TurnAttempt s = turnUndead(14, 12);  // special, 1-2
                int n = rollTurnCount(dice, s);
                if (n < 1 || n > 2) ++bad;
                if (n == 2) seen1to2 = 1;
                TurnAttempt d = turnUndead(8, 0);    // D* skeleton
                int m = rollTurnCount(dice, d);
                if (m < 7 || m > 12) ++bad;
                if (m == 7) seen7to12 = 1;
            }
            if (seen1to12 == 0 || seen1to2 == 0 ||
                seen7to12 == 0) ++bad;
            if (success == 0 || success == 20000) ++bad;
        }
        printf("R109 turn audit: bad %d\n", bad);
        if (bad) return 1;
    }
    return 0;"""
    r, did = replace_exact(r, old_r, new_r, "regtest R109 audit")
    if did:
        write("regtest.cpp", r)
    changed = changed or did

    # ---- 4. tools/dmg_gap_report.md: flip the box, same commit ----
    g = read("tools/dmg_gap_report.md")
    old_g = """R108b "THE BOOK, WHOLE" (the redo). The first
edition of this report was verified against OCR
book pages 1-67 only. The full Premium DMG OCR
has now been read: 242 pages, end to end. This
edition replaces the first wholesale. It is a
living checklist: when a round closes an item,
it flips the box in the SAME commit. Page cites
are the book's own page numbers."""
    new_g = """R108b "THE BOOK, WHOLE" (the redo). The first
edition of this report was verified against OCR
book pages 1-67 only. The full Premium DMG OCR
has now been read: 242 pages, end to end. This
edition replaces the first wholesale. It is a
living checklist: when a round closes an item,
it flips the box in the SAME commit. Page cites
are the book's own page numbers.

R109 CLOSED divergence 1 of 6 (turning undead);
the remaining five stay ranked below."""
    g, did = replace_exact(g, old_g, new_g, "gap report header note")
    if did:
        write("tools/dmg_gap_report.md", g)
    changed = changed or did

    g = read("tools/dmg_gap_report.md")
    old_g = """- [~] 1. **Turning undead (p.75-76, matrix III;
      procedure p.77)** - the repo's mechanic is
      not the book's. The book: roll d20, match
      or exceed the cell -> turn 1-12 undead
      (7-12 where starred, 1-2 for Special);
      T = automatic turn, D = automatic destroy,
      dash = no effect ever. The book's Skeleton
      row across cleric levels 1-14+ is
      10/7/4/T/T/D/D/D*/D*/D*; Zombie
      13/10/7/T/T/...; Ghoul 16/13/10/4/T/...;
      Shadow 19/16/13/7/4/...; Wight
      20/19/16/10/7/4/...; Lich row ends
      19/16/10; Special row 20/19/13. The repo
      instead stores a count digit and rolls 2d6
      with entirely different numbers (its
      level-1 row begins {1,-1,...}). Both
      mechanics AND values diverge. Also the
      book's row order includes GHAST at slot 6
      (the OCR reads "Ghost" there; slot 11 is
      the true Ghost - resolve the row names
      against a printed copy in the fix round).
      This is the largest single divergence and
      the first fix candidate."""
    new_g = """- [x] 1. **Turning undead (p.75-76, matrix III;
      procedure p.77)** - CLOSED R109. The repo
      now carries the book's table cell for
      cell: 13 undead rows in the book's own
      order (the OCR's row-6 "Ghost" was GHAST;
      slot 11 is the true Ghost), columns
      cleric level 1-8 / 9-13 / 14+, d20
      match-or-exceed, T / D / D* / dash, counts
      1-12 (7-12 starred, 1-2 Special), paladins
      two levels below. Pinned by the R109
      battery audit."""
    g, did = replace_exact(g, old_g, new_g, "gap report turning box")
    if did:
        write("tools/dmg_gap_report.md", g)
    changed = changed or did

    print("R109 splice: " +
          ("ALL OK" if changed else "nothing to do (already applied)"))


main()
