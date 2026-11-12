// ====================================================================
// Adnd1 - rules/dmg/itemsavethrow.h
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

#include "../engine/dice.h"
using rules::Dice;  // R-refactor: engine type, was namespace-implicit




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



// -----------------------------------------------------------------------
// Fall (form 5): the printed cell assumes about 5 feet
// onto a stone-like surface; a wood-like surface gives
// +1 and a fleshy-soft surface +5; each 5 feet past the
// first 5 subtracts 1 from the die roll to save.
// -----------------------------------------------------------------------
enum ItemSaveFallSurface { ISFS_HARD = 0, ISFS_WOODLIKE,
                            ISFS_FLESHY };

// R-refactor: namespace rules -> class Itemsavethrow (instance methods)
class Itemsavethrow {
public:
    const char* itemSaveFormName(ItemSaveForm f);
    const char* itemSaveMaterialName(ItemSaveMaterial m);


// -----------------------------------------------------------------------
// The matrix: the 154 printed cells. The R157 grenade
// break saves (ceramic 18/12, crystal 19/14) read exactly
// the BLOW columns of these rows - the cross-check pins.
// -----------------------------------------------------------------------
    int itemSaveTarget(ItemSaveMaterial m, ItemSaveForm f);


// -----------------------------------------------------------------------
// Magical items: +2 on all rolls plus +1 for each plus
// above +1 (+1 saves at +2, +2 at +3, +3 at +4); a
// non-magical item reads 0. Every item, magical or not,
// gains +5 versus attack forms in its own mode.
// -----------------------------------------------------------------------
    int itemSaveMagicalBonus(int plus);
    int itemSaveOwnModeBonus();
    int itemSaveFallSurfaceAdj(ItemSaveFallSurface s);
    int itemSaveFallDistanceAdj(int feet);


// -----------------------------------------------------------------------
// The hard-metal cold-strike footnote: exposed to
// extreme cold then struck against a very hard surface
// with force, the saving throw is -10 on the die.
// -----------------------------------------------------------------------
    int itemSaveHardMetalColdStrikePenalty();


// -----------------------------------------------------------------------
// Normal fire (form 8) exposure: paper or parchment for
// but 1 melee round, cloth for 2, bone or ivory for 3 -
// the print trails with "etc."; the caller rules the
// rest. 0 = not printed (caller-side).
// -----------------------------------------------------------------------
    int itemSaveNormalFireRoundsToAffect(ItemSaveMaterial m);


// -----------------------------------------------------------------------
// The save itself: the item SAVES on roll + adj >= the
// cell value (the R157 convention).
// -----------------------------------------------------------------------
    bool itemSavesOn(int roll, int target, int adj);
    bool rollItemSave(rules::Dice& dice, ItemSaveMaterial m, ItemSaveForm f, int adj);
};
