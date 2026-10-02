// ============================================================================
// Adnd1 - rules/combat.cpp
// DMG combat tables.
// ============================================================================

#include "combat.h"

namespace rules {

// ----------------------------------------------------------------------------
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