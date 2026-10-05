// ====================================================================
// Adnd1 - rules/itemsavethrow.h
// R204: the Item Saving Throw Matrix (DMG p.80,
// matrix III - saving throw matrix for magical and
// non-magical items): the 14 material rows x 11
// attack forms, cell for cell, plus the printed
// modifiers.
//
// Pure data + helpers, header-only (the grenade.h
// pattern: the caller decides exposure and mode, then
// rolls; the save itself reads this matrix).
// Conventions, named in place:
//   - The item SAVES on d20 + adjustments >= the cell
//     value (the R157 break-roll convention).
//   - The Liquid row applies while the container
//     remains intact (the printed footnote); the 0
//     cells are printed 0s - no save window (liquid vs
//     blow, fall and normal fire; parchment vs fall).
//   - The Mirror row is silvered glass: a silver mirror
//     reads Metal, soft and steel reads Metal, hard
//     (the printed footnote). Metal, soft or Jewelry
//     includes pearls of any sort.
//   - Hard metal exposed to extreme cold then struck
//     against a very hard surface with force saves at
//     -10 on the die (the printed footnote a).
//   - JUDGMENTs: items that do not match a row
//     interpolate (the printed rule) - the caller picks
//     the row; the normal-fire exposure tail past the
//     three printed rounds (paper 1, cloth 2, bone 3)
//     is the caller (the print trails with "etc.").
// ====================================================================

#pragma once

#include "dice.h"

namespace rules {

// -----------------------------------------------------------------------
// The 11 attack forms (the print order)
// -----------------------------------------------------------------------

enum ItemSaveForm {
    ISF_ACID = 0,
    ISF_BLOW_CRUSHING,
    ISF_BLOW_NORMAL,
    ISF_DISINTEGRATE,
    ISF_FALL,
    ISF_FIREBALL,
    ISF_FIRE_MAGICAL,
    ISF_FIRE_NORMAL,
    ISF_FROST_MAGICAL,
    ISF_LIGHTNING_BOLT,
    ISF_ELECTRICAL,
    ISF_COUNT
};

// -----------------------------------------------------------------------
// The 14 materials (the print row order)
// -----------------------------------------------------------------------

enum ItemSaveMaterial {
    ISM_BONE_IVORY = 0,
    ISM_CERAMIC,
    ISM_CLOTH,
    ISM_CRYSTAL_VIAL,
    ISM_GLASS,
    ISM_LEATHER_BOOK,
    ISM_LIQUID,
    ISM_METAL_HARD,
    ISM_METAL_SOFT_JEWELRY,
    ISM_MIRROR,
    ISM_PARCHMENT_PAPER,
    ISM_STONE_GEM,
    ISM_WOOD_ROPE_THIN,
    ISM_WOOD_ROPE_THICK,
    ISM_COUNT
};

inline const char* itemSaveFormName(ItemSaveForm f) {
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

inline const char* itemSaveMaterialName(ItemSaveMaterial m) {
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

// -----------------------------------------------------------------------
// The matrix: the 154 printed cells. The R157 grenade
// break saves (ceramic 18/12, crystal 19/14) read exactly
// the BLOW columns of these rows - the cross-check pins.
// -----------------------------------------------------------------------
inline int itemSaveTarget(ItemSaveMaterial m, ItemSaveForm f) {
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

// -----------------------------------------------------------------------
// Magical items: +2 on all rolls plus +1 for each plus
// above +1 (+1 saves at +2, +2 at +3, +3 at +4); a
// non-magical item reads 0. Every item, magical or not,
// gains +5 versus attack forms in its own mode.
// -----------------------------------------------------------------------
inline int itemSaveMagicalBonus(int plus) {
    if (plus < 1) return 0;
    return 2 + (plus - 1);
}

inline int itemSaveOwnModeBonus() { return 5; }

// -----------------------------------------------------------------------
// Fall (form 5): the printed cell assumes about 5 feet
// onto a stone-like surface; a wood-like surface gives
// +1 and a fleshy-soft surface +5; each 5 feet past the
// first 5 subtracts 1 from the die roll to save.
// -----------------------------------------------------------------------
enum ItemSaveFallSurface { ISFS_HARD = 0, ISFS_WOODLIKE,
                            ISFS_FLESHY };

inline int itemSaveFallSurfaceAdj(ItemSaveFallSurface s) {
    static const int a[3] = { 0, 1, 5 };
    if (s < ISFS_HARD) s = ISFS_HARD;
    if (s > ISFS_FLESHY) s = ISFS_FLESHY;
    return a[s];
}

inline int itemSaveFallDistanceAdj(int feet) {
    int extra = feet - 5;
    if (extra < 0) extra = 0;
    return -(extra / 5);
}

// -----------------------------------------------------------------------
// The hard-metal cold-strike footnote: exposed to
// extreme cold then struck against a very hard surface
// with force, the saving throw is -10 on the die.
// -----------------------------------------------------------------------
inline int itemSaveHardMetalColdStrikePenalty() { return 10; }

// -----------------------------------------------------------------------
// Normal fire (form 8) exposure: paper or parchment for
// but 1 melee round, cloth for 2, bone or ivory for 3 -
// the print trails with "etc."; the caller rules the
// rest. 0 = not printed (caller-side).
// -----------------------------------------------------------------------
inline int itemSaveNormalFireRoundsToAffect(ItemSaveMaterial m) {
    if (m == ISM_PARCHMENT_PAPER) return 1;
    if (m == ISM_CLOTH) return 2;
    if (m == ISM_BONE_IVORY) return 3;
    return 0;
}

// -----------------------------------------------------------------------
// The save itself: the item SAVES on roll + adj >= the
// cell value (the R157 convention).
// -----------------------------------------------------------------------
inline bool itemSavesOn(int roll, int target, int adj) {
    return roll + adj >= target;
}

inline bool rollItemSave(rules::Dice& dice, ItemSaveMaterial m,
                         ItemSaveForm f, int adj) {
    return itemSavesOn((int)dice.d20(), itemSaveTarget(m, f), adj);
}

} // namespace rules
