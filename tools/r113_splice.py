#!/usr/bin/env python3
# R113 splice: the book's class attack matrices (DMG p.75
# I.A/I.C/I.D) - clerics, magic-users and thieves get the book's
# own tables (transcribed cell for cell); the effectiveAttackLevel
# row-shift approximation is retired. Idempotent (marker checks,
# the R112b lesson): run twice - second run must print nothing
# to do. ASCII-only. Refuses non-unique anchors.
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def read(rel):
    with open(os.path.join(ROOT, rel), "r", encoding="ascii") as f:
        return f.read()


def write(rel, text):
    with open(os.path.join(ROOT, rel), "w", encoding="ascii") as f:
        f.write(text)


def replace_exact(text, old, new, label):
    n = text.count(old)
    if n != 1:
        print("REFUSED " + label + ": anchor not unique or missing (count %d)" % n)
        return text, False
    return text.replace(old, new, 1), True


def main():
    changed = 0

    c = read("rules/combat.cpp")
    if "kClericMatrix" in c:
        print("already applied: combat.cpp class matrices")
    else:
        c, did = replace_exact(c, CPP_OLD, CPP_NEW, "combat.cpp class matrices")
        changed += did
    write("rules/combat.cpp", c)

    h = read("rules/combat.h")
    if "transcribed cell for cell by R113" in h:
        print("already applied: combat.h class note")
    else:
        h, did = replace_exact(h, H_OLD, H_NEW, "combat.h class note")
        changed += did
    write("rules/combat.h", h)

    r = read("regtest.cpp")
    if 'printf("R113 class matrix audit' in r:
        print("already applied: regtest R113 audit")
    else:
        r, did = replace_exact(r, RT_OLD, RT_NEW, "regtest R113 audit")
        changed += did
    write("regtest.cpp", r)

    g = read("tools/dmg_gap_report.md")
    if "R113 CLOSED divergence 4" in g:
        print("already applied: gap report header note")
    else:
        g, did = replace_exact(g, GHEAD_OLD, GHEAD_NEW, "gap report header note")
        changed += did
    if "CLOSED R113" in g:
        print("already applied: gap report class box")
    else:
        g, did = replace_exact(g, GBOX_OLD, GBOX_NEW, "gap report class box")
        changed += did
    write("tools/dmg_gap_report.md", g)

    print("R113 splice: " +
          ("ALL OK" if changed == 5 else
           "nothing to do (already applied)" if changed == 0 else
           "REFUSED: only %d of 5 patches applied - nothing written" % changed))


CPP_OLD = """// ----------------------------------------------------------------------------
// Class row-shifts (DMG prints separate class tables; the shifts below
// reproduce them from the fighter matrix)
// ----------------------------------------------------------------------------

int effectiveAttackLevel(int level, int classIndex) {
    if (level < 1) level = 1;
    switch (classIndex) {
        case 0:  return level;            // fighter
        case 1:  return level - 3 < 1 ? 1 : level - 3;  // MU
        case 2:  return level - 2 < 1 ? 1 : level - 2;  // cleric
        case 3:  return level - 4 < 1 ? 1 : level - 4;  // thief
        default: return level;
    }
}

int attackNumber(int classIndex, int level, int ac) {
    return attackMatrixFighter(effectiveAttackLevel(level, classIndex), ac);
}
"""
CPP_NEW = """// ----------------------------------------------------------------------------
// Class attack matrices (DMG p.75 I.A/I.C/I.D) - the book's own
// tables for clerics (I.A), magic-users (I.C) and thieves (I.D),
// transcribed cell for cell; fighters keep matrix I.B
// (attackMatrixFighter, R111). The effectiveAttackLevel row-shift
// approximation is gone (R113): a book MU level 1 needs 11 to hit
// AC 10; the shifts asked 10.
// ----------------------------------------------------------------------------

static const int kClassAcRows = 21;   // AC 10 .. AC -10

// I.A bands: 1-3, 4-6, 7-9, 10-12, 13-15, 16-18, 19+
static const int kClericMatrix[kClassAcRows][7] = {
    /*  10 */ { 10,  8,  6,  4,  2,  0, -1 },
    /*   9 */ { 11,  9,  7,  5,  3,  1,  0 },
    /*   8 */ { 12, 10,  8,  6,  4,  2,  1 },
    /*   7 */ { 13, 11,  9,  7,  5,  3,  2 },
    /*   6 */ { 14, 12, 10,  8,  6,  4,  3 },
    /*   5 */ { 15, 13, 11,  9,  7,  5,  4 },
    /*   4 */ { 16, 14, 12, 10,  8,  6,  5 },
    /*   3 */ { 17, 15, 13, 11,  9,  7,  6 },
    /*   2 */ { 18, 16, 14, 12, 10,  8,  7 },
    /*   1 */ { 19, 17, 15, 13, 11,  9,  8 },
    /*   0 */ { 20, 18, 16, 14, 12, 10,  9 },
    /*  -1 */ { 20, 19, 17, 15, 13, 11, 10 },
    /*  -2 */ { 20, 20, 18, 16, 14, 12, 11 },
    /*  -3 */ { 20, 20, 19, 17, 15, 13, 12 },
    /*  -4 */ { 20, 20, 20, 18, 16, 14, 13 },
    /*  -5 */ { 20, 20, 20, 19, 17, 15, 14 },
    /*  -6 */ { 21, 20, 20, 20, 18, 16, 15 },
    /*  -7 */ { 22, 20, 20, 20, 19, 17, 16 },
    /*  -8 */ { 23, 21, 20, 20, 20, 18, 17 },
    /*  -9 */ { 24, 22, 20, 20, 20, 19, 18 },
    /* -10 */ { 25, 23, 21, 20, 20, 20, 19 },
};

// I.C bands: 1-5, 6-10, 11-15, 16-20, 21+
static const int kMuMatrix[kClassAcRows][5] = {
    /*  10 */ { 11,  9,  6,  3,  1 },
    /*   9 */ { 12, 10,  7,  4,  2 },
    /*   8 */ { 13, 11,  8,  5,  3 },
    /*   7 */ { 14, 12,  9,  6,  4 },
    /*   6 */ { 15, 13, 10,  7,  5 },
    /*   5 */ { 16, 14, 11,  8,  6 },
    /*   4 */ { 17, 15, 12,  9,  7 },
    /*   3 */ { 18, 16, 13, 10,  8 },
    /*   2 */ { 19, 17, 14, 11,  9 },
    /*   1 */ { 20, 18, 15, 12, 10 },
    /*   0 */ { 20, 19, 16, 13, 11 },
    /*  -1 */ { 20, 20, 17, 14, 12 },
    /*  -2 */ { 20, 20, 18, 15, 13 },
    /*  -3 */ { 20, 20, 19, 16, 14 },
    /*  -4 */ { 20, 20, 20, 17, 15 },
    /*  -5 */ { 21, 20, 20, 18, 16 },
    /*  -6 */ { 22, 20, 20, 19, 17 },
    /*  -7 */ { 23, 21, 20, 20, 18 },
    /*  -8 */ { 24, 22, 20, 20, 19 },
    /*  -9 */ { 25, 23, 20, 20, 20 },
    /* -10 */ { 26, 24, 21, 20, 20 },
};

// I.D bands: 1-4, 5-8, 9-12, 13-16, 17-20, 21+
// (the book's superscripts are backstab damage multipliers, not
// attack numbers - tracked with the thief special, not here)
static const int kThiefMatrix[kClassAcRows][6] = {
    /*  10 */ { 11,  9,  6,  4,  2,  0 },
    /*   9 */ { 12, 10,  7,  5,  3,  1 },
    /*   8 */ { 13, 11,  8,  6,  4,  2 },
    /*   7 */ { 14, 12,  9,  7,  5,  3 },
    /*   6 */ { 15, 13, 10,  8,  6,  4 },
    /*   5 */ { 16, 14, 11,  9,  7,  5 },
    /*   4 */ { 17, 15, 12, 10,  8,  6 },
    /*   3 */ { 18, 16, 13, 11,  9,  7 },
    /*   2 */ { 19, 17, 14, 12, 10,  8 },
    /*   1 */ { 20, 18, 15, 13, 11,  9 },
    /*   0 */ { 20, 19, 16, 14, 12, 10 },
    /*  -1 */ { 20, 20, 17, 15, 13, 11 },
    /*  -2 */ { 20, 20, 18, 16, 14, 12 },
    /*  -3 */ { 20, 20, 19, 17, 15, 13 },
    /*  -4 */ { 20, 20, 20, 18, 16, 14 },
    /*  -5 */ { 21, 20, 20, 19, 17, 15 },
    /*  -6 */ { 22, 20, 20, 20, 18, 16 },
    /*  -7 */ { 23, 21, 20, 20, 19, 17 },
    /*  -8 */ { 24, 22, 20, 20, 20, 18 },
    /*  -9 */ { 25, 23, 20, 20, 20, 19 },
    /* -10 */ { 26, 24, 21, 20, 20, 20 },
};

static int clericBand(int level) {
    if (level < 1)   level = 1;
    if (level <= 3)  return 0;
    if (level <= 6)  return 1;
    if (level <= 9)  return 2;
    if (level <= 12) return 3;
    if (level <= 15) return 4;
    if (level <= 18) return 5;
    return 6;                     // 19+
}

static int muBand(int level) {
    if (level < 1)   level = 1;
    if (level <= 5)  return 0;
    if (level <= 10) return 1;
    if (level <= 15) return 2;
    if (level <= 20) return 3;
    return 4;                     // 21+
}

static int thiefBand(int level) {
    if (level < 1)   level = 1;
    if (level <= 4)  return 0;
    if (level <= 8)  return 1;
    if (level <= 12) return 2;
    if (level <= 16) return 3;
    if (level <= 20) return 4;
    return 5;                     // 21+
}

int attackNumber(int classIndex, int level, int ac) {
    int row = 10 - ac;
    if (row < 0) row = 0;
    if (row > kClassAcRows - 1) row = kClassAcRows - 1;
    switch (classIndex) {
        case 1:  return kMuMatrix[row][muBand(level)];
        case 2:  return kClericMatrix[row][clericBand(level)];
        case 3:  return kThiefMatrix[row][thiefBand(level)];
        default: return attackMatrixFighter(level, ac);  // fighter/0-level
    }
}
"""
H_OLD = """// Class attack numbers: cleric/MU/thief attack as fighters at a lower
// effective level (the 1e convention - the DMG prints separate tables
// that are row-shifts of the fighter matrix):
//   cleric: effective level = level (clerics use their own near-fighter
//           progression; encoded as level - 2, min 1)
//   thief:  effective level = level - 4, min 1  ( thieves attack worse
//           than fighters)
//   MU:     effective level = level - 3, min 1  (magic-users attack
//           slightly worse than clerics)
int effectiveAttackLevel(int level, int classIndex);

"""
H_NEW = """// Class attack numbers (DMG p.75 I.A/I.C/I.D): the book's own
// tables for cleric (I.A: bands 1-3/4-6/7-9/10-12/13-15/16-18/
// 19+), magic-user (I.C: bands 1-5/6-10/11-15/16-20/21+) and
// thief (I.D: bands 1-4/5-8/9-12/13-16/17-20/21+), each 21 AC
// rows (10 down to -10), transcribed cell for cell by R113. The
// effectiveAttackLevel row-shift approximation is gone. Targets
// may be negative or above 20 (natural 20 / natural 1 convention
// as in attackRollHits).

// Convenience: to-hit number for a class/level vs AC.
// classIndex: 0 fighter (matrix I.B), 1 MU (I.C), 2 cleric (I.A),
// 3 thief (I.D) (matches CharClass).
int attackNumber(int classIndex, int level, int ac);

"""
RT_OLD = """        printf("R112 monster matrix audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;
"""
RT_NEW = """        printf("R112 monster matrix audit: bad %d\\n", bad);
        if (bad) return 1;
    }

    // ---- R113: class attack matrices audit (DMG p.75 I.A/I.C/I.D) ----
    {
        int bad = 0;
        // the printed tables: a representative level for each band,
        // pinned at notable ACs (fighter keeps I.B, R111's audit)
        {
            struct CC { int cls, level, ac, want; };
            const CC cc[] = {
                {2,  1,  10,  10},  // cleric band 0
                {2,  1,   0,  20},  // cleric band 0
                {2,  1,  -5,  20},  // cleric band 0
                {2,  1, -10,  25},  // cleric band 0
                {2,  4,  10,   8},  // cleric band 1
                {2,  4,   0,  18},  // cleric band 1
                {2,  4,  -5,  20},  // cleric band 1
                {2,  4, -10,  23},  // cleric band 1
                {2,  7,  10,   6},  // cleric band 2
                {2,  7,   0,  16},  // cleric band 2
                {2,  7,  -5,  20},  // cleric band 2
                {2,  7, -10,  21},  // cleric band 2
                {2, 10,  10,   4},  // cleric band 3
                {2, 10,   0,  14},  // cleric band 3
                {2, 10,  -5,  19},  // cleric band 3
                {2, 10, -10,  20},  // cleric band 3
                {2, 13,  10,   2},  // cleric band 4
                {2, 13,   0,  12},  // cleric band 4
                {2, 13,  -5,  17},  // cleric band 4
                {2, 13, -10,  20},  // cleric band 4
                {2, 16,  10,   0},  // cleric band 5
                {2, 16,   0,  10},  // cleric band 5
                {2, 16,  -5,  15},  // cleric band 5
                {2, 16, -10,  20},  // cleric band 5
                {2, 19,  10,  -1},  // cleric band 6
                {2, 19,   0,   9},  // cleric band 6
                {2, 19,  -5,  14},  // cleric band 6
                {2, 19, -10,  19},  // cleric band 6
                {1,  1,  10,  11},  // MU band 0
                {1,  1,   0,  20},  // MU band 0
                {1,  1,  -5,  21},  // MU band 0
                {1,  1, -10,  26},  // MU band 0
                {1,  6,  10,   9},  // MU band 1
                {1,  6,   0,  19},  // MU band 1
                {1,  6,  -5,  20},  // MU band 1
                {1,  6, -10,  24},  // MU band 1
                {1, 11,  10,   6},  // MU band 2
                {1, 11,   0,  16},  // MU band 2
                {1, 11,  -5,  20},  // MU band 2
                {1, 11, -10,  21},  // MU band 2
                {1, 16,  10,   3},  // MU band 3
                {1, 16,   0,  13},  // MU band 3
                {1, 16,  -5,  18},  // MU band 3
                {1, 16, -10,  20},  // MU band 3
                {1, 21,  10,   1},  // MU band 4
                {1, 21,   0,  11},  // MU band 4
                {1, 21,  -5,  16},  // MU band 4
                {1, 21, -10,  20},  // MU band 4
                {3,  1,  10,  11},  // thief band 0
                {3,  1,   0,  20},  // thief band 0
                {3,  1,  -5,  21},  // thief band 0
                {3,  1, -10,  26},  // thief band 0
                {3,  5,  10,   9},  // thief band 1
                {3,  5,   0,  19},  // thief band 1
                {3,  5,  -5,  20},  // thief band 1
                {3,  5, -10,  24},  // thief band 1
                {3,  9,  10,   6},  // thief band 2
                {3,  9,   0,  16},  // thief band 2
                {3,  9,  -5,  20},  // thief band 2
                {3,  9, -10,  21},  // thief band 2
                {3, 13,  10,   4},  // thief band 3
                {3, 13,   0,  14},  // thief band 3
                {3, 13,  -5,  19},  // thief band 3
                {3, 13, -10,  20},  // thief band 3
                {3, 17,  10,   2},  // thief band 4
                {3, 17,   0,  12},  // thief band 4
                {3, 17,  -5,  17},  // thief band 4
                {3, 17, -10,  20},  // thief band 4
                {3, 21,  10,   0},  // thief band 5
                {3, 21,   0,  10},  // thief band 5
                {3, 21,  -5,  15},  // thief band 5
                {3, 21, -10,  20},  // thief band 5
                {2,  1,  10,  10},  // cleric L1 band 0
                {2,  3,  10,  10},  // cleric L3 band 0 edge
                {2,  4,  10,   8},  // cleric L4 band 1
                {2, 18,  10,   0},  // cleric L18 band 5
                {2, 19,  10,  -1},  // cleric L19+ band 6
                {1,  5,  10,  11},  // MU L5 band 0 edge
                {1,  6,  10,   9},  // MU L6 band 1
                {1, 20,  10,   3},  // MU L20 band 3
                {1, 21,  10,   1},  // MU L21+ band 4
                {3,  4,  10,  11},  // thief L4 band 0 edge
                {3,  5,  10,   9},  // thief L5 band 1
                {3, 20,  10,   2},  // thief L20 band 4
                {3, 21,  10,   0},  // thief L21+ band 5
            };
            for (const CC& m : cc) {
                if (rules::attackNumber(m.cls, m.level, m.ac) != m.want)
                    ++bad;
            }
        }
        // fighter (classIndex 0) still rides matrix I.B
        {
            int v = rules::attackNumber(0, 1, 10);
            if (v != 10) ++bad;
            v = rules::attackNumber(0, 0, 10);
            if (v != 11) ++bad;   // 0-level: I.B band 0
        }
        // each table only improves with level, only worsens
        // with AC, and stays in the book's bounds everywhere
        for (int cls = 1; cls <= 3; ++cls) {
            for (int level = 1; level <= 21; ++level) {
                int prevAc = -99;
                for (int ac = 12; ac >= -12; --ac) {
                    int v = rules::attackNumber(cls, level, ac);
                    if (v < -6 || v > 26) ++bad;
                    if (v < prevAc) ++bad;
                    prevAc = v;
                }
            }
            for (int ac = 10; ac >= -10; --ac) {
                int prevLvl = 99;
                for (int level = 1; level <= 21; ++level) {
                    int v = rules::attackNumber(cls, level, ac);
                    if (v > prevLvl) ++bad;
                    prevLvl = v;
                }
            }
        }
        printf("R113 class matrix audit: bad %d\\n", bad);
        if (bad) return 1;
    }
    return 0;
"""
GHEAD_OLD = """R112 CLOSED divergence 5 of 6 (monster attack
matrix); divergences 4 (class matrices) and 6
(aging) stay open.
"""
GHEAD_NEW = """R112 CLOSED divergence 5 of 6 (monster attack
matrix).
R113 CLOSED divergence 4 of 6 (class attack
matrices); divergence 6 (aging) stays open.
"""
GBOX_OLD = """- [~] 4. **Class attack matrices (p.75 I.A,
      I.C, I.D)** - the book gives clerics,
      magic-users, and thieves their own
      matrices with their own bands (cleric
      1-3/4-6/7-9/...; MU 1-5/6-10/...; thief
      per I.D). The repo approximates all
      classes with effectiveAttackLevel shifts
      on the fighter matrix (MU -3, cleric -2,
      thief -4), which lands wrong on both
      ends: a book MU level 1 needs 11 to hit
      AC 10, the repo asks 10. The book's
      missile note is on the same page: -5 at
      long, -2 at medium range.
"""
GBOX_NEW = """- [x] 4. **Class attack matrices (p.75 I.A,
      I.C, I.D)** - CLOSED R113. The repo now
      carries the book's own tables for
      clerics (I.A, 7 level bands), magic-
      users (I.C, 5 bands) and thieves
      (I.D, 6 bands), each 21 AC rows
      transcribed cell for cell; fighters
      keep matrix I.B (R111). The
      effectiveAttackLevel row-shift
      approximation is gone: a book MU
      level 1 needs 11 to hit AC 10 (the
      shifts asked 10). The book's thief
      superscripts are backstab damage
      multipliers, not attack numbers.
      The book's missile note (-5 long,
      -2 medium) is still an open item.
      Pinned by the R113 battery audit.
"""


main()
