// ============================================================================
// Adnd1 - rules/combat.cpp
// DMG combat tables.
// ============================================================================

#include "combat.h"

namespace rules {

// ----------------------------------------------------------------------------
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

// ----------------------------------------------------------------------------
// Monster effective level (DMG p.80 II)
// ----------------------------------------------------------------------------

int monsterEffectiveLevel(float hitDice) {
    if (hitDice <= 0) hitDice = 0;
    // 1 HD or less -> level 1; otherwise level ~= HD, capped at 20
    int lvl = (int)hitDice;
    if (hitDice > 0 && hitDice < 1) lvl = 1;
    if (lvl < 1) lvl = 1;
    if (lvl > 20) lvl = 20;
    return lvl;
}

// ----------------------------------------------------------------------------
// Attack roll resolution
// ----------------------------------------------------------------------------

bool attackRollHits(Dice& dice, int toHitNumber, int hitAdj) {
    int roll = (int)dice.d20();
    if (roll == 20) return true;    // natural 20 always hits
    if (roll == 1)  return false;   // natural 1 always misses
    return roll + hitAdj >= toHitNumber;
}

// ----------------------------------------------------------------------------
// Weapon vs AC (DMG p.38)
// ----------------------------------------------------------------------------

static const int kWeaponVsAc[WCLASS_COUNT][AC_TYPE_COUNT] = {
    //              none  leather  chain  plate
    /* bludgeoning */ { -1,   0,     0,    +1 },
    /* piercing    */ {  0,   0,    +1,    -1 },
    /* slashing    */ {  0,   0,     0,     0 },
};

int weaponVsAcAdjustment(WeaponClass wc, AcType ac) {
    if (wc < 0 || wc >= WCLASS_COUNT) return 0;
    if (ac < 0 || ac >= AC_TYPE_COUNT) return 0;
    return kWeaponVsAc[wc][ac];
}

AcType acTypeForAc(int ac) {
    if (ac >= 8) return AC_TYPE_NONE;     // 8-10+: no/light armor
    if (ac >= 5) return AC_TYPE_LEATHER;  // 5-7: leather/studded
    if (ac >= 2) return AC_TYPE_CHAIN;    // 2-4: chain/scale/splint
    return AC_TYPE_PLATE;                 // <=1: plate/field plate
}

// ----------------------------------------------------------------------------
// Magic weapon gating
// ----------------------------------------------------------------------------

bool weaponSufficient(int requiredPlus, int weaponBonus) {
    return weaponBonus >= requiredPlus;
}

// ----------------------------------------------------------------------------
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

} // namespace rules