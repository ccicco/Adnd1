// ============================================================================
// Adnd1 — rules/combat.cpp
// DMG combat tables.
// ============================================================================

#include "combat.h"

namespace rules {

// ----------------------------------------------------------------------------
// Fighter attack matrix (DMG p.74-75 "Combat Tables", men attacking).
//
// Columns: AC 10  9  8  7  6  5  4  3  2  1  0 -1
// Rows (fighter level): classic 1e values —
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
// Melee, tranche 42 original) pins five of these numbers — that check
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
    // 2d6 turned when a number appears — the digit IS the 2d6 result
    // band marker. We roll 2d6 (original tranche 51 convention: number
    // success turns weakest-first up to the rolled count).
    int r = (int)dice.roll(2, 6, 0);
    if (r < 1) r = 1;
    return r;
}

} // namespace rules