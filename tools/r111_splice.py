#!/usr/bin/env python3
# R111 splice: FIGHTER ATTACK MATRIX - the book's matrix I.B (DMG
# p.75), banded: 10 level bands (0, 1-2, ..., 17+) vs AC 10..-10,
# transcribed cell for cell with the book's negative targets intact.
# The per-level approximation and its floor-2 clamp are replaced. The
# battery gains the R111 attack matrix audit; the gap report flips its
# box in this same commit. Class row-shifts and the monster mapping
# still ride the fighter matrix (separate gap-report items).

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

    c = read("rules/combat.cpp")
    c, did = replace_exact(c, CPP_OLD, CPP_NEW, "combat.cpp matrix I.B")
    changed = changed or did
    write("rules/combat.cpp", c)

    h = read("rules/combat.h")
    h, did = replace_exact(h, HHDR_OLD, HHDR_NEW, "combat.h source note")
    changed = changed or did
    h, did = replace_exact(h, HFTR_OLD, HFTR_NEW, "combat.h fighter decl note")
    changed = changed or did
    write("rules/combat.h", h)

    r = read("regtest.cpp")
    r, did = replace_exact(r, RT_OLD, RT_NEW, "regtest R111 audit")
    changed = changed or did
    write("regtest.cpp", r)

    g = read("tools/dmg_gap_report.md")
    g, did = replace_exact(g, GHEAD_OLD, GHEAD_NEW, "gap report header note")
    changed = changed or did
    g, did = replace_exact(g, GBOX_OLD, GBOX_NEW, "gap report fighter box")
    changed = changed or did
    write("tools/dmg_gap_report.md", g)

    print("R111 splice: " +
          ("ALL OK" if changed else "nothing to do (already applied)"))


CPP_OLD = """// ----------------------------------------------------------------------------
// Fighter attack matrix (DMG p.74-75 "Combat Tables", men attacking).
//
// Columns: AC 10  9  8  7  6  5  4  3  2  1  0 -1
// Rows (fighter level): classic 1e values -
//    L1: 10 11 12 13 14 15 16 17 18 19 20 20
//    L2:  9 10 11 12 13 14 15 16 17 18 19 20
//    L3:  8  9 10 11 12 13 14 15 16 17 18 19
//    L4:  6  8  9 10 11 12 13 14 15 16 17 18
//    L5:  4  6  8  9 10 11 12 13 14 15 16 17
//    L6:  2  4  6  8  9 10 11 12 13 14 15 16
//    L7:  2  2  4  6  8  9 10 11 12 13 14 15
//    L8:  2  2  2  4  6  8  9 10 11 12 13 14
//    L9:  2  2  2  2  4  6  8  9 10 11 12 13
//   L10+: each further level steps the whole row one column better.
//
// NOTE (rebuild): rows 1-9 above are transcribed from the DMG table as
// recorded in the project notes; the golden test (DMG p.71 Example of
// Melee, tranche 42 original) pins five of these numbers - that check
// lands when rules/turn exists. Values follow the well-known 1e matrix
// where level bands shift by armor group; if any CHECK disagrees with
// the printed DMG table, the printed table wins and the row is fixed.
// ----------------------------------------------------------------------------

static const int kFighterMatrix[9][12] = {
    // AC: 10  9  8  7  6  5  4  3  2  1  0 -1
    { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 20 },  // L1
    {  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 },  // L2
    {  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 },  // L3
    {  6,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18 },  // L4
    {  4,  6,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17 },  // L5
    {  2,  4,  6,  8,  9, 10, 11, 12, 13, 14, 15, 16 },  // L6
    {  2,  2,  4,  6,  8,  9, 10, 11, 12, 13, 14, 15 },  // L7
    {  2,  2,  2,  4,  6,  8,  9, 10, 11, 12, 13, 14 },  // L8
    {  2,  2,  2,  2,  4,  6,  8,  9, 10, 11, 12, 13 },  // L9
};

static int acColumn(int ac) {
    // AC 10 -> col 0 ... AC -1 -> col 11
    int col = 10 - ac;
    if (col < 0)  col = 0;
    if (col > 11) col = 11;
    return col;
}

int attackMatrixFighter(int level, int ac) {
    if (level < 1) level = 1;
    int col = acColumn(ac);
    if (level <= 9) return kFighterMatrix[level - 1][col];
    // beyond L9: each level shifts one column better
    int shift = level - 9;
    int col2 = col - shift;
    if (col2 < 0) return 2;   // floor: 2 always hits at high level
    return kFighterMatrix[8][col2];
}
"""
CPP_NEW = """// ----------------------------------------------------------------------------
// Fighter attack matrix (DMG p.75, matrix I.B - fighters, paladins,
// rangers, bards, and 0-level humans and halflings). The book's own
// banded table, transcribed cell for cell: rows AC 10 down to AC -10
// (21 rows), columns the level bands 0, 1-2, 3-4, 5-6, 7-8, 9-10,
// 11-12, 13-14, 15-16, 17+ (10 bands). Targets are the book's own,
// INCLUDING NEGATIVES (a 17+ fighter hits AC 10 on any d20 roll:
// the printed target is -6; the 0-level human needs 11). The book's
// optional 5%-per-level variant (p.75 special note) is NOT adopted -
// the printed two-level bands are. The old per-level approximation
// and its floor-2 clamp were replaced by R111.
// ----------------------------------------------------------------------------

static const int kFighterBands  = 10;   // 0, 1-2, 3-4, ..., 17+
static const int kFighterAcRows = 21;  // AC 10 .. AC -10

static const int kFighterMatrix[kFighterAcRows][kFighterBands] = {
    // columns: band 0, 1-2, 3-4, 5-6, 7-8, 9-10, 11-12, 13-14, 15-16, 17+
    /*  10 */ { 11, 10,  8,  6,  4,  2,  0, -2, -4, -6 },
    /*   9 */ { 12, 11,  9,  7,  5,  3,  1, -1, -3, -5 },
    /*   8 */ { 13, 12, 10,  8,  6,  4,  2,  0, -2, -4 },
    /*   7 */ { 14, 13, 11,  9,  7,  5,  3,  1, -1, -3 },
    /*   6 */ { 15, 14, 12, 10,  8,  6,  4,  2,  0, -2 },
    /*   5 */ { 16, 15, 13, 11,  9,  7,  5,  3,  1, -1 },
    /*   4 */ { 17, 16, 14, 12, 10,  8,  6,  4,  2,  0 },
    /*   3 */ { 18, 17, 15, 13, 11,  9,  7,  5,  3,  1 },
    /*   2 */ { 19, 18, 16, 14, 12, 10,  8,  6,  4,  2 },
    /*   1 */ { 20, 19, 17, 15, 13, 11,  9,  7,  5,  3 },
    /*   0 */ { 20, 20, 18, 16, 14, 12, 10,  8,  6,  4 },
    /*  -1 */ { 20, 20, 19, 17, 15, 13, 11,  9,  7,  5 },
    /*  -2 */ { 20, 20, 20, 18, 16, 14, 12, 10,  8,  6 },
    /*  -3 */ { 20, 20, 20, 19, 17, 15, 13, 11,  9,  7 },
    /*  -4 */ { 20, 20, 20, 20, 18, 16, 14, 12, 10,  8 },
    /*  -5 */ { 21, 20, 20, 20, 19, 17, 15, 13, 11,  9 },
    /*  -6 */ { 22, 21, 20, 20, 20, 18, 16, 14, 12, 10 },
    /*  -7 */ { 23, 22, 20, 20, 20, 19, 17, 15, 13, 11 },
    /*  -8 */ { 24, 23, 21, 20, 20, 20, 18, 16, 14, 12 },
    /*  -9 */ { 25, 24, 22, 20, 20, 20, 19, 17, 15, 13 },
    /* -10 */ { 26, 25, 23, 21, 20, 20, 20, 18, 16, 14 },
};

int attackMatrixFighter(int level, int ac) {
    // level band: 0 level is its own column; then 1-2, 3-4, ... 17+
    int band;
    if (level <= 0) band = 0;
    else {
        band = (level + 1) / 2;
        if (band > kFighterBands - 1) band = kFighterBands - 1;
    }
    // AC row: AC 10 is row 0, AC -10 is row 20; clamp past either end
    int row = 10 - ac;
    if (row < 0) row = 0;
    if (row > kFighterAcRows - 1) row = kFighterAcRows - 1;
    return kFighterMatrix[row][band];
}
"""
HHDR_OLD = """// Source: Dungeon Masters Guide (2012 Premium reprint).
//   - Attack matrices: DMG p.74-75 (combat tables; fighter matrix is the
//     master, other classes row-shift into it)
//   - Monster attacks: DMG p.80 "Monsters attacking" - attack as fighters
//     at a level derived from hit dice (section II)
//   - Weapon vs AC adjustments: DMG p.38 table (weapon type vs armor class
//     type: better/worse by 1-2)
//   - Turning undead: DMG p.75 cleric turn matrix (rows 1-8+, columns
//     skeleton..vampire; T=turn, D=destroy, number=2d6 turned, dash=no
//     effect, *=auto within 60')"""
HHDR_NEW = """// Source: Dungeon Masters Guide (2012 Premium reprint).
//   - Fighter attack matrix: DMG p.75 matrix I.B, the book's own
//     banded table (level bands 0, 1-2, ..., 17+ vs AC 10..-10) -
//     transcribed cell for cell by R111, negatives included
//   - Other classes still row-shift into the fighter matrix (an
//     approximation; the book prints separate matrices I.A/I.C/I.D -
//     an open gap-report item)
//   - Monster attacks: DMG p.80 "Monsters attacking" - attack as
//     fighters at a level derived from hit dice (section II; the
//     book's own monster matrix is an open gap-report item)
//   - Weapon vs AC adjustments: DMG p.38 table (weapon type vs armor
//     class type: better/worse by 1-2)
//   - Turning undead: DMG p.75-76 matrix III, 13 undead rows, cleric
//     level columns 1-8/9-13/14+; d20 match-or-exceed, T/D/D*/dash,
//     counts 1-12 (7-12 starred, 1-2 Special)"""
HFTR_OLD = """// Fighter attack matrix: to-hit number by level (rows) vs AC (columns).
// AC columns run 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1 (12 columns),
// level rows 1..20 (index 0 = level 1).
int attackMatrixFighter(int level, int ac);"""
HFTR_NEW = """// Fighter attack matrix (DMG p.75 I.B): to-hit number by level band
// vs AC. Bands: 0, 1-2, 3-4, 5-6, 7-8, 9-10, 11-12, 13-14, 15-16,
// 17+; AC runs 10 down to -10, clamped at either end. Targets may be
// negative (high band vs low AC) or above 20 (low band vs very low
// AC - only a natural 20 can hit, per the attackRollHits convention).
int attackMatrixFighter(int level, int ac);"""
RT_OLD = """        printf("R110 saves audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;
            }
"""
RT_NEW = """        printf("R110 saves audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R111: fighter attack matrix audit (DMG p.75 I.B) ----
    {
        int bad = 0;
        // the printed table, pinned band by band
        {
            struct TC { int lvl, ac, want; };
            const TC tc[] = {
                // AC 10 row across the bands (the negatives are the
                // book's own: a 17+ fighter hits AC 10 on any roll)
                { 1, 10, 10}, { 2, 10, 10},   // band 1-2 mates
                { 3, 10,  8}, { 4, 10,  8},   // band 3-4
                { 5, 10,  6}, { 9, 10,  2},   // bands 5-6, 9-10
                {11, 10,  0}, {15, 10, -4}, {17, 10, -6},
                {20, 10, -6},                // 17+ is the last band
                // 0-level column (0-level humans and halflings)
                { 0, 10, 11}, { 0,  0, 20}, { 0, -5, 21}, { 0, -10, 26},
                // AC 0 row down the bands
                { 1,  0, 20}, { 3,  0, 18}, { 5,  0, 16},
                { 7,  0, 14}, { 9,  0, 12}, {11,  0, 10},
                {13,  0,  8}, {15,  0,  6}, {17,  0,  4},
                // the deep-AC rows
                { 1, -1, 20}, { 1, -5, 20}, { 1, -10, 25},
                {17, -10, 14},
                // negatives mid-table
                {13,  7,  1}, {15,  6,  0}, {17,  5, -1},
                // AC clamps: past 10 uses the AC 10 row,
                // past -10 the AC -10 row
                { 1, 12, 10}, { 1, -12, 25},
            };
            for (const TC& t : tc) {
                if (rules::attackMatrixFighter(t.lvl, t.ac) != t.want)
                    ++bad;
            }
        }
        // the table only improves with level, only worsens with AC,
        // and stays in the book's bounds at every cell
        for (int lvl = 0; lvl <= 20; ++lvl) {
            int prevAc = -99;
            for (int ac = 12; ac >= -12; --ac) {
                int v = rules::attackMatrixFighter(lvl, ac);
                if (v < -6 || v > 26) ++bad;
                if (v < prevAc) ++bad;   // better AC never easier
                prevAc = v;
            }
        }
        for (int ac = 10; ac >= -10; --ac) {
            int prevLvl = 99;
            for (int lvl = 0; lvl <= 20; ++lvl) {
                int v = rules::attackMatrixFighter(lvl, ac);
                if (v > prevLvl) ++bad;  // level never worsens
                prevLvl = v;
            }
        }
        // a negative target hits on everything but a natural 1
        {
            rules::Rng rng(111);
            rules::Dice dice(rng);
            int hits = 0;
            for (int i = 0; i < 20000; ++i) {
                if (rules::attackRollHits(dice, -6, 0)) ++hits;
            }
            if (hits == 0 || hits == 20000) ++bad;
        }
        printf("R111 attack matrix audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;
            }
"""
GHEAD_OLD = """R109 CLOSED divergence 1 of 6 (turning undead).
R110 CLOSED divergence 2 of 6 (saving throws);
the remaining four stay ranked below."""
GHEAD_NEW = """R109 CLOSED divergence 1 of 6 (turning undead).
R110 CLOSED divergence 2 of 6 (saving throws).
R111 CLOSED divergence 3 of 6 (fighter attack
matrix); the remaining three stay ranked below."""
GBOX_OLD = """- [~] 3. **Fighter attack matrix (p.75 I.B)** -
      the book is level-BANDED: 0, 1-2, 3-4,
      5-6, 7-8, 9-10, 11-12, 13-14, 15-16,
      17+; the AC-10 row reads 10/8/6/4/2/0/
      -2/-4/-6 continuing to AC -10. The repo
      matches at levels 1-3 but diverges from
      level 4 up (its per-level rows shift one
      column per level; the book shifts per
      two-level band), and the repo clamps at
      20 / floor 2 where the book has genuine
      negative targets down to -6 at AC 10."""
GBOX_NEW = """- [x] 3. **Fighter attack matrix (p.75 I.B)** -
      CLOSED R111. The repo now carries the
      book's own banded table: level bands
      0, 1-2, 3-4, 5-6, 7-8, 9-10, 11-12,
      13-14, 15-16, 17+ vs AC 10 down to
      AC -10, transcribed cell for cell with
      the book's negative targets intact (the
      17+ band hits AC 10 on any roll; the
      0-level human needs 11). The per-level
      approximation and its floor-2 clamp are
      gone. The book's optional 5%-per-level
      variant is not adopted. Pinned by the
      R111 battery audit."""


main()
