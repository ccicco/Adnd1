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