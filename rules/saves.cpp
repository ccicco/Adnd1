// ============================================================================
// Adnd1 - rules/saves.cpp
// PHB class save tables + DMG monster save rule.
// ============================================================================

#include "saves.h"

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
// Class save matrices (DMG p.79-80, matrix I - the banded tables).
// The book bands levels per class; every level in a band shares the
// row, and the last band has no upper limit. Values are transcribed
// in the repo's SaveCategory order (Death, Wands, Petrify, Breath,
// Spells); the book prints Death, Petrify, Rod/Staff/Wand, Breath,
// Spell - transposed at transcription.
//   fighter (incl. paladins, rangers, 0 level): 0, 1-2, 3-4, 5-6,
//     7-8, 9-10, 11-12, 13-14, 15-16, 17+
//   cleric (incl. druids): 1-3, 4-6, 7-9, 10-12, 13-15, 16-18, 19+
//   magic-user (incl. illusionists): 1-5, 6-10, 11-15, 16-20, 21+
//   thief (incl. assassins, monks): 1-4, 5-8, 9-12, 13-16, 17-20, 21+
// ----------------------------------------------------------------------------

struct SaveBand { int upTo; int v[SAVE_COUNT]; };

static const SaveBand kFighterBands[] = {
    {  0, {16, 18, 17, 20, 19} },
    {  2, {14, 16, 15, 17, 17} },
    {  4, {13, 15, 14, 16, 16} },
    {  6, {11, 13, 12, 13, 14} },
    {  8, {10, 12, 11, 12, 13} },
    { 10, { 8, 10,  9,  9, 11} },
    { 12, { 7,  9,  8,  8, 10} },
    { 14, { 5,  7,  6,  5,  8} },
    { 16, { 4,  6,  5,  4,  7} },
    { 99, { 3,  5,  4,  4,  6} },
};
static const SaveBand kMagicUserBands[] = {
    {  5, {14, 11, 13, 15, 12} },
    { 10, {13,  9, 11, 13, 10} },
    { 15, {11,  7,  9, 11,  8} },
    { 20, {10,  5,  7,  9,  6} },
    { 99, { 8,  3,  5,  7,  4} },
};
static const SaveBand kClericBands[] = {
    {  3, {10, 14, 13, 16, 15} },
    {  6, { 9, 13, 12, 15, 14} },
    {  9, { 7, 11, 10, 13, 12} },
    { 12, { 6, 10,  9, 12, 11} },
    { 15, { 5,  9,  8, 11, 10} },
    { 18, { 4,  8,  7, 10,  9} },
    { 99, { 2,  6,  5,  8,  7} },
};
static const SaveBand kThiefBands[] = {
    {  4, {13, 14, 12, 16, 15} },
    {  8, {12, 12, 11, 15, 13} },
    { 12, {11, 10, 10, 14, 11} },
    { 16, {10,  8,  9, 13,  9} },
    { 20, { 9,  6,  8, 12,  7} },
    { 99, { 8,  4,  7, 11,  5} },
};

// classIndex order: 0 fighter, 1 magic-user, 2 cleric, 3 thief
// (CharClass order, see rules/classes.h)
static const SaveBand* const kClassBands[4] = {
    kFighterBands, kMagicUserBands, kClericBands, kThiefBands
};
static const int kClassBandCounts[4] = { 10, 5, 7, 6 };

int saveTarget(int classIndex, int level, SaveCategory cat) {
    if (classIndex < 0 || classIndex > 3) classIndex = 0;
    if (cat < 0 || cat >= SAVE_COUNT) cat = SAVE_DEATH_POISON;

    // fighters keep the book's separate 0-level row; the other
    // classes have no level 0 and clamp into their first band
    if (level < 1 && classIndex != 0) level = 1;
    if (level < 0) level = 0;

    const SaveBand* bands = kClassBands[classIndex];
    int n = kClassBandCounts[classIndex];
    for (int i = 0; i < n; ++i) {
        if (level <= bands[i].upTo)
            return bands[i].v[(int)cat];
    }
    return bands[n - 1].v[(int)cat];
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// R155: matrix II.C most-favorable matrix - a classed monster
// saves at the BEST score across its class matrices (each class at
// its own level) vs the base target; the II.B fighter matrix stays
// in the min (a classed foe never saves WORSE than the matrix II
// convention).
// ----------------------------------------------------------------------------

int mostFavorableSaveTarget(int classMask, const int* levels,
                            int baseClass, int baseLevel,
                            SaveCategory cat) {
    int best = saveTarget(baseClass, baseLevel, cat);
    for (int ci = 0; ci < 4; ++ci) {
        if (!(classMask & (1 << ci))) continue;
        if (!levels || levels[ci] < 1) continue;
        int t = saveTarget(ci, levels[ci], cat);
        if (t < best) best = t;
    }
    return best;
}

// ----------------------------------------------------------------------------
// Monster HD -> save level (DMG p.80 matrix II.B): hit dice equate to
// experience level, with hit-point pluses stepping the creature up one
// die level per 4 points (1+1..1+4 becomes 2, 1+5..1+8 becomes 3,
// 2+1..2+4 also becomes 3, ...). Capped at 21 (the matrices' last band).
// ----------------------------------------------------------------------------

int monsterSaveLevel(float hitDice) {
    if (hitDice <= 0) return 1;
    int base = (int)hitDice;
    int plus = (int)(((hitDice - (float)base) * 4.0f) + 0.5f);
    int lvl = base + (plus + 3) / 4;
    if (lvl < 1) lvl = 1;
    if (lvl > 21) lvl = 21;
    return lvl;
}

// ----------------------------------------------------------------------------
// Rolls
// ----------------------------------------------------------------------------

bool attemptSave(Dice& dice, int target, int modifier) {
    int roll = (int)dice.d20();
    if (roll == 1) return false;   // DMG p.80: a roll of 1 is ALWAYS failure
    return roll + modifier >= target;
}

bool attemptMonsterSave(Dice& dice, float hitDice, SaveCategory cat,
                        int modifier) {
    // DMG p.80 matrix II: most monsters save as fighters at their
    // HD-derived level (the II.B stepping in monsterSaveLevel).
    // Monsters with class abilities use their most favorable matrix -
    // the caller's job, not this helper's.
    int level = monsterSaveLevel(hitDice);
    int target = saveTarget(0, level, cat);
    return attemptSave(dice, target, modifier);
}

bool magicResistanceBlocks(Dice& dice, int magicResistPct) {
    if (magicResistPct <= 0) return false;
    if (magicResistPct >= 100) return true;
    return (int)dice.d100() <= magicResistPct;
}

} // namespace rules