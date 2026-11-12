// ====================================================================
// Adnd1 - rules/dmg/misc_magic/miscmagic_table5_footnotes.h
// R239: the III.E table 5 footnote pins
// (DMG p.130) - the class marks that frame
// TABLE (III.E.) 5 of the miscellaneous
// magic tables (the last sub-table):
//   - the (M) marks: the Robe of the
//     Archmagi, Robe of Eyes, Robe of
//     Powerlessness, Robe of Scintillating
//     Colors (with C), Robe of Useful
//     Items, Rug of Welcome, Sphere of
//     Annihilation and Talisman of the
//     Sphere.
//   - the (C) marks: the Robe of
//     Scintillating Colors (with M), the
//     Talisman of Pure Good, the Talisman
//     of Ultimate Evil and the two
//     command/warning Tridents (with F
//     and T).
//   - the (F) marks: the Saw of Mighty
//     Cutting, the Spade of Colossal
//     Excavation, the Trident of Submission
//     and the two command/warning Tridents.
//   - the (T) marks: the Tridents of Fish
//     Command and Warning.
// NO asterisk rows, dual-value rows or
// footnotes ride this table (verified: the
// print runs straight from the 91-00 Wings
// of Flying row to the TABLE (III.E.)
// Special artifacts table).
// The row identity is the 35 die bands of
// the engine III.E.5 table (dm/treasure.cpp
// kMisc5 order, the Robe of the Archmagi
// 01 through the Wings of Flying 91-00).
// The row VALUES were pinned by the R122
// line-diff audit; this header pins the
// class marks and the band edges.
// Pure data + helpers, header-only (the
// grenade.h pattern).
// ====================================================================

#pragma once

// R-refactor: namespace rules -> class Miscmagic_table5_footnotes (instance methods)
class Miscmagic_table5_footnotes {
public:
    int m5RowCount();
    int m5RowLo(int i);
    int m5RowHi(int i);
    int m5UsableByCleric(int i);
    int m5UsableByFighter(int i);
    int m5UsableByMagicUser(int i);
    int m5UsableByThief(int i);
    int m5ClericCount();
    int m5FighterCount();
    int m5MagicUserCount();
    int m5ThiefCount();
};
