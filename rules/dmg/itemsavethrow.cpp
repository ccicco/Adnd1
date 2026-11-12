// R-refactor: split from itemsavethrow.h - definitions
#include "rules/dmg/itemsavethrow.h"

const char* Itemsavethrow::itemSaveFormName(ItemSaveForm f) {
    static const char* const n[ISF_COUNT] = {
        "acid", "blow, crushing", "blow, normal",
        "disintegrate", "fall",
        "fireball (or breath)", "fire, magical",
        "fire, normal (oil)", "frost, magical",
        "lightning bolt", "electrical discharge/current"
    };
    if (f < ISF_ACID) f = ISF_ACID;
    if (f >= ISF_COUNT) f = ISF_ELECTRICAL;
    return n[f];
}

const char* Itemsavethrow::itemSaveMaterialName(ItemSaveMaterial m) {
    static const char* const n[ISM_COUNT] = {
        "bone or ivory", "ceramic", "cloth",
        "crystal or vial", "glass", "leather or book",
        "liquid", "metal, hard",
        "metal, soft or jewelry", "mirror",
        "parchment or paper", "stone, small or gem",
        "wood or rope, thin", "wood or rope, thick"
    };
    if (m < ISM_BONE_IVORY) m = ISM_BONE_IVORY;
    if (m >= ISM_COUNT) m = ISM_WOOD_ROPE_THICK;
    return n[m];
}

int Itemsavethrow::itemSaveTarget(ItemSaveMaterial m, ItemSaveForm f) {
    static const int k[ISM_COUNT][ISF_COUNT] = {
        { 11, 16, 10, 20,  6, 17,  9,  3,  2,  8, 1 },
        {  4, 18, 12, 19, 11,  5,  3,  2,  4,  2, 1 },
        { 12,  6,  3, 20,  2, 20, 16, 13,  1, 18, 1 },
        {  6, 19, 14, 20, 13, 10,  6,  3,  7, 15, 5 },
        {  5, 20, 15, 20, 14, 11,  7,  4,  6, 17, 1 },
        { 10,  4,  2, 20,  1, 13,  6,  4,  3, 13, 1 },
        { 15,  0,  0, 20,  0, 15, 14, 13, 12, 18, 15 },
        {  7,  6,  2, 17,  2,  6,  2,  1,  1,  1, 1 },
        { 13, 14,  9, 19,  4, 18, 13,  5,  1,  6, 1 },
        { 12, 20, 15, 20, 13, 14,  9,  5,  6, 18, 1 },
        { 16, 11,  6, 20,  0, 25, 21, 18,  2, 20, 1 },
        {  3, 17,  7, 18,  4,  7,  3,  2,  1, 14, 2 },
        {  9, 13,  6, 20,  2, 15, 11,  9,  1, 10, 1 },
        {  8, 10,  3, 19,  1, 11,  7,  5,  1, 12, 1 },
    };
    if (m < ISM_BONE_IVORY) m = ISM_BONE_IVORY;
    if (m >= ISM_COUNT) m = ISM_WOOD_ROPE_THICK;
    if (f < ISF_ACID) f = ISF_ACID;
    if (f >= ISF_COUNT) f = ISF_ELECTRICAL;
    return k[m][f];
}

int Itemsavethrow::itemSaveMagicalBonus(int plus) {
    if (plus < 1) return 0;
    return 2 + (plus - 1);
}

int Itemsavethrow::itemSaveOwnModeBonus() { return 5; }

int Itemsavethrow::itemSaveFallSurfaceAdj(ItemSaveFallSurface s) {
    static const int a[3] = { 0, 1, 5 };
    if (s < ISFS_HARD) s = ISFS_HARD;
    if (s > ISFS_FLESHY) s = ISFS_FLESHY;
    return a[s];
}

int Itemsavethrow::itemSaveFallDistanceAdj(int feet) {
    int extra = feet - 5;
    if (extra < 0) extra = 0;
    return -(extra / 5);
}

int Itemsavethrow::itemSaveHardMetalColdStrikePenalty() { return 10; }

int Itemsavethrow::itemSaveNormalFireRoundsToAffect(ItemSaveMaterial m) {
    if (m == ISM_PARCHMENT_PAPER) return 1;
    if (m == ISM_CLOTH) return 2;
    if (m == ISM_BONE_IVORY) return 3;
    return 0;
}

bool Itemsavethrow::itemSavesOn(int roll, int target, int adj) {
    return roll + adj >= target;
}

bool Itemsavethrow::rollItemSave(rules::Dice& dice, ItemSaveMaterial m, ItemSaveForm f, int adj) {
    return itemSavesOn((int)dice.d20(), itemSaveTarget(m, f), adj);
}
