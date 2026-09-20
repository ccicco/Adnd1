// ============================================================================
// Adnd1 — rules/saves.cpp
// PHB class save tables + DMG monster save rule.
// ============================================================================

#include "saves.h"
#include "combat.h"   // monsterEffectiveLevel

namespace rules {

// ----------------------------------------------------------------------------
// Names
// ----------------------------------------------------------------------------

static const char* const kSaveNames[SAVE_COUNT] = {
    "Death/Poison", "Wands", "Petrify/Poly", "Breath Weapon", "Spells"
};

const char* saveCategoryName(SaveCategory s) {
    return kSaveNames[(int)s];
}

// ----------------------------------------------------------------------------
// Class save tables (PHB pp. 22-36).
//
// The PHB prints five-column tables per class. Encoded rows are levels
// 1-12 (the "prime line" levels); beyond 12, each level improves each
// category by 1 (floor 2) until the class's minimum column value.
// NOTE (rebuild): values follow the standard 1e table shape as recorded
// in the project notes. When the PHB PDF is re-uploaded, verify row by
// row — the printed table wins on any disagreement (verification debt,
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

// ----------------------------------------------------------------------------
// Rolls
// ----------------------------------------------------------------------------

bool attemptSave(Dice& dice, int target, int modifier) {
    int roll = (int)dice.d20();
    return roll + modifier >= target;
}

bool attemptMonsterSave(Dice& dice, float hitDice, SaveCategory cat,
                        int modifier) {
    int level = monsterEffectiveLevel(hitDice);
    // monsters use the fighter matrix
    int target = saveTarget(0, level, cat);
    return attemptSave(dice, target, modifier);
}

bool magicResistanceBlocks(Dice& dice, int magicResistPct) {
    if (magicResistPct <= 0) return false;
    if (magicResistPct >= 100) return true;
    return (int)dice.d100() <= magicResistPct;
}

} // namespace rules