// ====================================================================
// Adnd1 - rules/dmg/potions.h
// R221: the III.A potions prose pins
// (DMG pp.125-126) - the three footnotes
// that frame the III.A POTIONS table:
//   - the * control potions: effectiveness
//     on the type of creature controlled
//     must be determined by die roll;
//     consult the item explanation.
//   - the ** potions: the DM must mislead
//     the holder so as to convince him the
//     potion is not harmful (Delusion and
//     Poison - see the item descriptions).
//   - the (F) potions: fighters only may
//     use.
// The row identity is the 35 die bands of
// the engine III.A table (dm/treasure.cpp
// kPotions order, Animal Control 01-03
// through Water Breathing 98-00). The row
// VALUES were pinned by the R122 line-diff
// audit; this header pins the footnote
// flags and the band edges.
// JUDGMENTS, named in place:
//   - Plant Control prints with NO star
//     (unlike every other control potion);
//     pinned as printed.
//   - Giant Strength prints BOTH * and (F);
//     both flags are set.
// Pure data + helpers, header-only (the
// grenade.h pattern).
// ====================================================================

#pragma once

// R-refactor: namespace rules -> class Potions (instance methods)
class Potions {
public:


// -----------------------------------------------------------------------
// The row count and the die band edges.
// -----------------------------------------------------------------------
    int potionRowCount();
    int potionRowLo(int i);
    int potionRowHi(int i);


// -----------------------------------------------------------------------
// The * control potions: Animal Control,
// Dragon Control, Giant Control, Giant
// Strength, Human Control, Undead Control.
// -----------------------------------------------------------------------
    int potionIsControl(int i);
    int potionControlCount();


// -----------------------------------------------------------------------
// The ** DM-misleading potions: Delusion
// and Poison.
// -----------------------------------------------------------------------
    int potionIsMislead(int i);
    int potionMisleadCount();


// -----------------------------------------------------------------------
// The (F) fighter-only potions: Giant
// Strength, Heroism, Invulnerability,
// Super-Heroism.
// -----------------------------------------------------------------------
    int potionIsFighterOnly(int i);
    int potionFighterOnlyCount();
};
