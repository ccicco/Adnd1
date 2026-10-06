// ====================================================================
// Adnd1 - rules/potions.h
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

namespace rules {

// -----------------------------------------------------------------------
// The row count and the die band edges.
// -----------------------------------------------------------------------
inline int potionRowCount() {
    // Animal Control through Water Breathing
    return 35;
}

inline int potionRowLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 34) i = 34;
    static const int t[35] = {
        1, 4, 7, 10, 13, 16, 19, 21, 24, 27,
        30, 33, 35, 37, 40, 42, 48, 50, 52, 55,
        58, 61, 64, 67, 70, 73, 76, 79, 82, 85,
        88, 91, 94, 97, 98,
    };
    return t[i];
}

inline int potionRowHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 34) i = 34;
    static const int t[35] = {
        3, 6, 9, 12, 15, 18, 20, 23, 26, 29,
        32, 34, 36, 39, 41, 47, 49, 51, 54, 57,
        60, 63, 66, 69, 72, 75, 78, 81, 84, 87,
        90, 93, 96, 97, 100,
    };
    return t[i];
}

// -----------------------------------------------------------------------
// The * control potions: Animal Control,
// Dragon Control, Giant Control, Giant
// Strength, Human Control, Undead Control.
// -----------------------------------------------------------------------
inline int potionIsControl(int i) {
    // effectiveness on the type of creature
    // controlled must be determined by die
    // roll; consult the item explanation
    if (i < 0) i = 0;
    if (i > 34) i = 34;
    static const int t[35] = {
        1, 0, 0, 0, 0, 0, 1, 0, 0, 0,
        0, 0, 1, 1, 0, 0, 0, 1, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 1, 0,
    };
    return t[i];
}

inline int potionControlCount() {
    return 6;
}

// -----------------------------------------------------------------------
// The ** DM-misleading potions: Delusion
// and Poison.
// -----------------------------------------------------------------------
inline int potionIsMislead(int i) {
    // the DM must mislead the holder so as
    // to convince him the potion is not
    // harmful; see the item descriptions
    if (i < 0) i = 0;
    if (i > 34) i = 34;
    static const int t[35] = {
        0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
        0, 0, 0, 0, 0,
    };
    return t[i];
}

inline int potionMisleadCount() {
    return 2;
}

// -----------------------------------------------------------------------
// The (F) fighter-only potions: Giant
// Strength, Heroism, Invulnerability,
// Super-Heroism.
// -----------------------------------------------------------------------
inline int potionIsFighterOnly(int i) {
    // fighters only may use
    if (i < 0) i = 0;
    if (i > 34) i = 34;
    static const int t[35] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 1, 0, 0, 1, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        1, 0, 0, 0, 0,
    };
    return t[i];
}

inline int potionFighterOnlyCount() {
    return 4;
}

}  // namespace rules

