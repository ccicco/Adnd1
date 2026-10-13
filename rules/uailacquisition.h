// ===========================================================================
// Adnd1 - rules/uailacquisition.h
// The UA ILLUSIONIST SPELL ACQUISITION (pp. 33-34
// players extract, p. 80 print) pins, R365: the
// starting-list table, the illusionist spell book
// differences and the illusionist cantrip counts.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists.
//
// JUDGMENTs (the decode method):
//   - R393 (the clean PDF read, p. 80): the
//     starting-list table decodes column-wise
//     in full - three columns, six rows each;
//     the R365 interleave decode corrects
//     (Darkness defensive row 2, Phantom
//     Armor defensive row 5, Chromatic Orb
//     plain, Spook offensive row 6); the
//     (choose) markers read as the defensive
//     row 6 and the misc rows 5-6, the
//     asterisk on the misc row 6.
//   - the chromatic orb row prints plain (the
//     R365 (choose) read corrects) and the
//     UA-addition note prints clean (spells from this work were
//     added to the initial lists for illusionists
//     only, not for magic-users).
//   - the book-difference list prints clean (the
//     24/16/8 standard capacities, the 6/4/2
//     travelling capacities, the separate book
//     for magic-user 1st-level spells).
//   - the illusionist cantrip counts print with
//     one category tail garbled (the personal
//     2-5 cell) - pinned per the fragments.
// ===========================================================================

#pragma once

namespace rules {

// ---- the starting list ----
inline bool uailaThreeGroupsOneEach()
    { return true; }

inline bool uailaAlwaysKnowsReadIllusionistMagic()
    { return true; }

// The R393 clean read (p. 80): the
// starting list decodes column-wise,
// three columns with six rows each.
// Offensive: 1 - color spray; 2 -
// hypnotism; 3 - light; 4 - phantasmal
// force; 5 - chromatic orb (plain);
// 6 - spook. Defensive: 1 - audible
// glamer; 2 - darkness; 3 - gaze
// reflection; 4 - wall of fog; 5 -
// phantom armor; 6 - (choose).
// Misc: 1 - change self; 2 - dancing
// lights; 3 - detect illusion; 4 -
// detect invisibility; 5 - (choose);
// 6 - (choose)*.
inline int uailaOffensiveRowCount()
    { return 6; }

inline int uailaDefensiveRowCount()
    { return 6; }

inline int uailaMiscRowCount()
    { return 6; }

inline bool uailaOffRow1ColorSpray()
    { return true; }

inline bool uailaOffRow2Hypnotism()
    { return true; }

inline bool uailaOffRow3Light()
    { return true; }

inline bool uailaOffRow4PhantasmalForce()
    { return true; }

inline bool uailaOffRow5ChromaticOrb()
    { return true; }

inline bool uailaChromaticOrbPrintsPlain()
    { return true; }

inline bool uailaOffRow6Spook()
    { return true; }

inline bool uailaDefRow1AudibleGlamer()
    { return true; }

inline bool uailaDefRow2Darkness()
    { return true; }

inline bool uailaDefRow3GazeReflection()
    { return true; }

inline bool uailaDefRow4WallOfFog()
    { return true; }

inline bool uailaDefRow5PhantomArmor()
    { return true; }

inline bool uailaDefRow6IsChoose()
    { return true; }

inline bool uailaMiscRow1ChangeSelf()
    { return true; }

inline bool uailaMiscRow2DancingLights()
    { return true; }

inline bool uailaMiscRow3DetectIllusion()
    { return true; }

inline bool uailaMiscRow4DetectInvisibility()
    { return true; }

inline bool uailaMiscRow5IsChoose()
    { return true; }

inline bool uailaMiscRow6IsChooseAsterisk()
    { return true; }

inline bool uailaColumnsDecodeColumnWise()
    { return true; }

// The DM three-options note for the asterisked
// choose: a 5th miscellaneous spell, a player
// re-selection of an offensive spell, or the
// roll read as a miscellaneous choice.
inline int uailaDmOptionCount()
    { return 3; }

inline bool uailaUaSpellsAddedForIllusionistsOnly()
    { return true; }

inline bool uailaNotDoneForMagicUsers()
    { return true; }

// ---- the illusionist spell book differences ----
inline bool uailaBooksSameAsMuWithExceptions()
    { return true; }

inline int uailaStandardBookLowLevelSpells()
    { return 24; }

inline int uailaStandardBookMidLevelSpells()
    { return 16; }

inline int uailaStandardBookHighLevelSpells()
    { return 8; }

inline bool uailaMuFirstLevelNeedsNewBook()
    { return true; }

inline int uailaMuFirstLevelBookCapacity()
    { return 24; }

inline int uailaTravellingBookLowLevelSpells()
    { return 6; }

inline int uailaTravellingBookMidLevelSpells()
    { return 4; }

inline int uailaTravellingBookHighLevelSpells()
    { return 2; }

inline bool uailaScriptReadableByIllusionistsOnly()
    { return true; }

inline bool uailaCrossClassBookBan()
    { return true; }

inline bool uailaNamesakeSpellsTriggerDifferently()
    { return true; }

// ---- the illusionist cantrip counts ----
inline bool uailaHasAllMuCantrips()
    { return true; }

inline int uailaMinorIllusionCantripsMin()
    { return 5; }

inline int uailaMinorIllusionCantripsMax()
    { return 8; }

inline bool uailaMinorIllusionNotAvailableToMu()
    { return true; }

// The useful-category cap: one per point of
// intelligence minus 3 - an 18-intelligence
// illusionist chooses 15.
inline int uailaUsefulCapIntMinus()
    { return 3; }

inline int uailaUsefulCapAtInt18()
    { return 15; }

inline int uailaReversedKnownMin()
    { return 2; }

inline int uailaReversedKnownMax()
    { return 5; }

inline int uailaLegerdemainKnownMin()
    { return 3; }

inline int uailaLegerdemainKnownMax()
    { return 6; }

inline int uailaPersonAffectingKnownMin()
    { return 2; }

inline int uailaPersonAffectingKnownMax()
    { return 5; }

inline int uailaPersonalKnownMin()
    { return 2; }

inline int uailaPersonalKnownMax()
    { return 5; }

inline int uailaHauntingSoundKnownMin()
    { return 5; }

inline int uailaHauntingSoundKnownMax()
    { return 8; }

inline bool uailaMuCantripPropertiesOtherwiseApply()
    { return true; }

}   // namespace rules

