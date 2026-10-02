

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
