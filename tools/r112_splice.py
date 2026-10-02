#!/usr/bin/env python3
# R112 splice: the book's monster attack matrix (DMG p.75-76, matrix II).
# Idempotent: run twice - second run must print "nothing to do".
# ASCII-only. Refuses non-unique anchors. Never pastes around a REFUSED line.
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def read(rel):
    with open(os.path.join(ROOT, rel), "r", encoding="ascii") as f:
        return f.read()


def write(rel, text):
    with open(os.path.join(ROOT, rel), "w", encoding="ascii") as f:
        f.write(text)


def replace_exact(text, old, new, label):
    if new in text and old not in text:
        print("already applied: " + label)
        return text, False
    n = text.count(old)
    if n != 1:
        print("REFUSED " + label + ": anchor not unique or missing (count %d)" % n)
        return text, False
    return text.replace(old, new, 1), True


def main():
    changed = False

    c = read("rules/combat.cpp")
    if "int attackMatrixMonster(" in c:
        print("already applied: combat.cpp matrix II")
    else:
        c, did = replace_exact(c, CPP_OLD, CPP_NEW, "combat.cpp matrix II")
        changed = changed or did
    write("rules/combat.cpp", c)

    h = read("rules/combat.h")
    h, did = replace_exact(h, HMON_OLD, HMON_NEW, "combat.h source note")
    changed = changed or did
    h, did = replace_exact(h, HDECL_OLD, HDECL_NEW, "combat.h monster decl")
    changed = changed or did
    write("rules/combat.h", h)

    a = read("ai/actor.cpp")
    a, did = replace_exact(a, AHIT_OLD, AHIT_NEW, "actor.cpp monster toHit")
    changed = changed or did
    a, did = replace_exact(a, ASV1_OLD, ASV1_NEW, "actor.cpp asTarget save level")
    changed = changed or did
    a, did = replace_exact(a, ASV2_OLD, ASV2_NEW, "actor.cpp resolveSpecial save level")
    changed = changed or did
    write("ai/actor.cpp", a)

    r = read("regtest.cpp")
    if 'printf("R112 monster matrix audit: bad %d' in r:
        print("already applied: regtest R112 audit")
    else:
        r, did = replace_exact(r, RT_OLD, RT_NEW, "regtest R112 audit")
        changed = changed or did
    write("regtest.cpp", r)

    g = read("tools/dmg_gap_report.md")
    g, did = replace_exact(g, GHEAD_OLD, GHEAD_NEW, "gap report header note")
    changed = changed or did
    g, did = replace_exact(g, GBOX_OLD, GBOX_NEW, "gap report monster box")
    changed = changed or did
    write("tools/dmg_gap_report.md", g)

    print("R112 splice: " +
          ("ALL OK" if changed else "nothing to do (already applied)"))


CPP_OLD = """}

// ----------------------------------------------------------------------------
// Class row-shifts (DMG prints separate class tables; the shifts below
"""
CPP_NEW = """}

// ----------------------------------------------------------------------------
// Monster attack matrix (DMG p.75-76, matrix II - "Attack Matrix for
// Monsters", including goblins, hobgoblins, kobolds, and orcs). The
// book's own table, transcribed cell for cell: rows AC 10 down to
// AC -10 (21 rows), columns the monster's hit-dice category (12
// bands): up to 1-1, 1-1, 1, 1+, 2-3+, 4-5+, 6-7+, 8-9+, 10-11+,
// 12-13+, 14-15+, 16+. Monsters do NOT attack as fighters - the
// book gives them their own targets (a 16+ HD monster hits AC 10 on
// any roll: target -3; a sub-1-1 HD creature needs 11). Replaces the
// monsterEffectiveLevel-onto-fighter-matrix approximation (R112).
// ----------------------------------------------------------------------------

static const int kMonsterBands  = 12;
static const int kMonsterAcRows = 21;   // AC 10 .. AC -10

static const int kMonsterMatrix[kMonsterAcRows][kMonsterBands] = {
    // cols: <=1-1, 1-1, 1, 1+, 2-3+, 4-5+, 6-7+, 8-9+, 10-11+,
    //       12-13+, 14-15+, 16+
    /*  10 */ { 11, 10,  9,  8,  6,  5,  3,  2,  0, -1, -2, -3 },
    /*   9 */ { 12, 11, 10,  9,  7,  6,  4,  3,  1,  0, -1, -2 },
    /*   8 */ { 13, 12, 11, 10,  8,  7,  5,  4,  2,  1,  0, -1 },
    /*   7 */ { 14, 13, 12, 11,  9,  8,  6,  5,  3,  2,  1,  0 },
    /*   6 */ { 15, 14, 13, 12, 10,  9,  7,  6,  4,  3,  2,  1 },
    /*   5 */ { 16, 15, 14, 13, 11, 10,  8,  7,  5,  4,  3,  2 },
    /*   4 */ { 17, 16, 15, 14, 12, 11,  9,  8,  6,  5,  4,  3 },
    /*   3 */ { 18, 17, 16, 15, 13, 12, 10,  9,  7,  6,  5,  4 },
    /*   2 */ { 19, 18, 17, 16, 14, 13, 11, 10,  8,  7,  6,  5 },
    /*   1 */ { 20, 19, 18, 17, 15, 14, 12, 11,  9,  8,  7,  6 },
    /*   0 */ { 20, 20, 19, 18, 16, 15, 13, 12, 10,  9,  8,  7 },
    /*  -1 */ { 20, 20, 20, 19, 17, 16, 14, 13, 11, 10,  9,  8 },
    /*  -2 */ { 20, 20, 20, 20, 18, 17, 15, 14, 12, 11, 10,  9 },
    /*  -3 */ { 20, 20, 20, 20, 19, 18, 16, 15, 13, 12, 11, 10 },
    /*  -4 */ { 20, 20, 20, 20, 20, 19, 17, 16, 14, 13, 12, 11 },
    /*  -5 */ { 21, 20, 20, 20, 20, 20, 18, 17, 15, 14, 13, 12 },
    /*  -6 */ { 22, 21, 20, 20, 20, 20, 19, 18, 16, 15, 14, 13 },
    /*  -7 */ { 23, 22, 21, 20, 20, 20, 20, 19, 17, 16, 15, 14 },
    /*  -8 */ { 24, 23, 22, 21, 20, 20, 20, 20, 18, 17, 16, 15 },
    /*  -9 */ { 25, 24, 23, 22, 20, 20, 20, 20, 19, 18, 17, 16 },
    /* -10 */ { 26, 25, 24, 23, 21, 20, 20, 20, 20, 19, 18, 17 },
};

// Float hit dice -> book column. The book's fine low columns (1-1
// vs 1) cannot be split by the repo's float HD (both store 1.0), so
// hd 1.0 uses the "1-1" column - goblin, the repo's 1.0-HD monster,
// is book 1-1; true-1-HD orcs share it, one harsh step (documented
// interpretation of the garbled header banding). 1+1..1+3 land in
// the "1" column, 1+4..1+9 in "1+", then the pair bands from 2 up.
static int monsterAttackBand(float hd) {
    if (hd < 1.0f)  return 0;   // up to 1-1
    if (hd < 1.25f) return 1;   // 1-1
    if (hd < 1.5f)  return 2;   // 1
    if (hd < 2.0f)  return 3;   // 1+
    if (hd < 4.0f)  return 4;   // 2-3+
    if (hd < 6.0f)  return 5;   // 4-5+
    if (hd < 8.0f)  return 6;   // 6-7+
    if (hd < 10.0f) return 7;   // 8-9+
    if (hd < 12.0f) return 8;   // 10-11+
    if (hd < 14.0f) return 9;   // 12-13+
    if (hd < 16.0f) return 10;  // 14-15+
    return 11;                  // 16+
}

int attackMatrixMonster(float hitDice, int ac) {
    int band = monsterAttackBand(hitDice);
    int row = 10 - ac;
    if (row < 0) row = 0;
    if (row > kMonsterAcRows - 1) row = kMonsterAcRows - 1;
    return kMonsterMatrix[row][band];
}

// ----------------------------------------------------------------------------
// Class row-shifts (DMG prints separate class tables; the shifts below
"""

HMON_OLD = """//   - Monster attacks: DMG p.80 "Monsters attacking" - attack as
//     fighters at a level derived from hit dice (section II; the
//     book's own monster matrix is an open gap-report item)
"""
HMON_NEW = """//   - Monster attacks: DMG p.75-76 matrix II - the book's own HD-banded
//     monster table, transcribed cell for cell by R112 (monsters do
//     NOT attack as fighters)
"""

HDECL_OLD = """// Monster attack: attack as fighter at effective level per DMG p.80 II.
// HD  up to 1   -> level 1;  then roughly 1 level per HD, capped by the
// matrix (rows to 20+).
"""
HDECL_NEW = """// Monster attack (DMG p.75-76 matrix II): to-hit number by the
// monster's hit-dice band (12 bands, up to 1-1 through 16+) vs AC
// 10 down to -10, clamped at either end. Targets may be negative or
// above 20 (natural 20 / natural 1 convention as in attackRollHits).
int attackMatrixMonster(float hitDice, int ac);

// Monster effective level (DMG p.86 guard rule): hit dice to a level
// for guard strength and similar non-combat uses. NOT used for
// attacks (matrix II) or saves (monsterSaveLevel, rules/saves.h).
"""

AHIT_OLD = """    return rules::attackMatrixFighter(
        rules::monsterEffectiveLevel(hitDice), ac);
"""
AHIT_NEW = """    return rules::attackMatrixMonster(hitDice, ac);
"""
ASV1_OLD = """                              : rules::monsterEffectiveLevel(hitDice);
"""
ASV1_NEW = """                              : rules::monsterSaveLevel(hitDice);
"""
ASV2_OLD = """            defender.isCharacter ? defender.level
                                 : rules::monsterEffectiveLevel(defender.hitDice),
"""
ASV2_NEW = """            defender.isCharacter ? defender.level
                                 : rules::monsterSaveLevel(defender.hitDice),
"""
RT_OLD = """        printf("R111 attack matrix audit: bad %d\\n", bad);
"""
RT_NEW = """        printf("R111 attack matrix audit: bad %d\\n", bad);
    }

    // ---- R112: monster attack matrix audit (DMG p.75-76 II) ----
    {
        int bad = 0;
        // the printed table: a representative hit dice for each
        // of the 12 bands, pinned at notable ACs
        {
            struct MC { float hd; int ac, want; };
            const MC mc[] = {
                {0.50f,  10,  11},  // band 0
                {0.50f,   0,  20},  // band 0
                {0.50f,  -5,  21},  // band 0
                {0.50f, -10,  26},  // band 0
                {1.00f,  10,  10},  // band 1
                {1.00f,   0,  20},  // band 1
                {1.00f,  -5,  20},  // band 1
                {1.00f, -10,  25},  // band 1
                {1.30f,  10,   9},  // band 2
                {1.30f,   0,  19},  // band 2
                {1.30f,  -5,  20},  // band 2
                {1.30f, -10,  24},  // band 2
                {1.60f,  10,   8},  // band 3
                {1.60f,   0,  18},  // band 3
                {1.60f,  -5,  20},  // band 3
                {1.60f, -10,  23},  // band 3
                {2.00f,  10,   6},  // band 4
                {2.00f,   0,  16},  // band 4
                {2.00f,  -5,  20},  // band 4
                {2.00f, -10,  21},  // band 4
                {4.00f,  10,   5},  // band 5
                {4.00f,   0,  15},  // band 5
                {4.00f,  -5,  20},  // band 5
                {4.00f, -10,  20},  // band 5
                {6.00f,  10,   3},  // band 6
                {6.00f,   0,  13},  // band 6
                {6.00f,  -5,  18},  // band 6
                {6.00f, -10,  20},  // band 6
                {8.00f,  10,   2},  // band 7
                {8.00f,   0,  12},  // band 7
                {8.00f,  -5,  17},  // band 7
                {8.00f, -10,  20},  // band 7
                {10.00f, 10,   0},  // band 8
                {10.00f,  0,  10},  // band 8
                {10.00f, -5,  15},  // band 8
                {10.00f, -10, 20},  // band 8
                {12.00f, 10,  -1},  // band 9
                {12.00f,  0,   9},  // band 9
                {12.00f, -5,  14},  // band 9
                {12.00f, -10, 19},  // band 9
                {14.00f, 10,  -2},  // band 10
                {14.00f,  0,   8},  // band 10
                {14.00f, -5,  13},  // band 10
                {14.00f, -10, 18},  // band 10
                {16.00f, 10,  -3},  // band 11
                {16.00f,  0,   7},  // band 11
                {16.00f, -5,  12},  // band 11
                {16.00f, -10, 17},  // band 11
                {0.99f,  10,  11},  // band 0
                {1.00f,  10,  10},  // band 1
                {1.25f,  10,   9},  // band 2
                {1.50f,  10,   8},  // band 3
                {2.00f,  10,   6},  // band 4
                {3.99f,  10,   6},  // band 4
                {4.00f,  10,   5},  // band 5
                {15.99f, 10,  -2},  // band 10
                {16.00f, 10,  -3},  // band 11
                {40.00f, 10,  -3},  // band 11
            };
            for (const MC& m : mc) {
                if (rules::attackMatrixMonster(m.hd, m.ac) != m.want)
                    ++bad;
            }
        }
        // the table only improves with hit dice, only worsens
        // with AC, and stays in the book's bounds everywhere
        for (float hd = 0.25f; hd < 40.0f; hd += 0.25f) {
            int prevAc = -99;
            for (int ac = 12; ac >= -12; --ac) {
                int v = rules::attackMatrixMonster(hd, ac);
                if (v < -3 || v > 26) ++bad;
                if (v < prevAc) ++bad;
                prevAc = v;
            }
        }
        for (int ac = 10; ac >= -10; --ac) {
            int prevHd = 99;
            for (float hd = 0.25f; hd < 40.0f; hd += 0.25f) {
                int v = rules::attackMatrixMonster(hd, ac);
                if (v > prevHd) ++bad;
                prevHd = v;
            }
        }
        printf("R112 monster matrix audit: bad %d\\n", bad);
"""

GHEAD_OLD = """R109 CLOSED divergence 1 of 6 (turning undead).
R110 CLOSED divergence 2 of 6 (saving throws).
R111 CLOSED divergence 3 of 6 (fighter attack
matrix); the remaining three stay ranked below.
"""
GHEAD_NEW = """R109 CLOSED divergence 1 of 6 (turning undead).
R110 CLOSED divergence 2 of 6 (saving throws).
R111 CLOSED divergence 3 of 6 (fighter attack
matrix).
R112 CLOSED divergence 5 of 6 (monster attack
matrix); divergences 4 (class matrices) and 6
(aging) stay open.
"""
GBOX_OLD = """- [~] 5. **Monster attack matrix (p.75-76
      II)** - the book gives monsters their own
      HD-banded matrix (AC-10 row 11/10/9/8/6/
      5/3/2/0/-1/-2/-3 for bands 1/1+1-2/.../
      16+). The repo derives monster attacks by
      mapping HD onto the fighter matrix - a
      close approximation, not the book's
      table.
"""
GBOX_NEW = """- [x] 5. **Monster attack matrix (p.75-76
      II)** - CLOSED R112. The repo now carries
      the book's own HD-banded monster table:
      12 hit-dice bands (up to 1-1 through
      16+) vs AC 10 down to AC -10, transcribed
      cell for cell (monsters do NOT attack as
      fighters; a 16+ HD monster hits AC 10 on
      any roll, target -3). The repo's float HD
      cannot split the book's 1-1 vs 1 columns
      (both store 1.0; goblin, the battery's
      1.0 monster, is book 1-1 - documented
      interpretation). Monster saves also now
      step by monsterSaveLevel (matrix II.B,
      from R110). Pinned by the R112 battery
      audit.
"""


main()
