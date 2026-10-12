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
//   - the starting-list table interleaves: the
//     defensive rows print legibly (the five
//     numbered rows with the multi-name cells);
//     the offensive and misc columns merge into
//     one garbled block (Change Self through
//     Phantom Armor with two choose markers) -
//     the row boundaries are lost, holes pending
//     the PDF; the fragment names pin.
//   - the chromatic orb row prints with the
//     (choose) marker and the UA-addition note
//     prints clean (spells from this work were
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

// The defensive rows: 1 - color spray, audible
// glamer, darkness; 2 - hypnotism; 3 - light,
// gaze reflection; 4 - phantasmal force, wall of
// fog; 5 - chromatic orb (choose).
inline int uailaDefensiveRowCount()
    { return 5; }

inline bool uailaRow1ColorSpray()
    { return true; }

inline bool uailaRow1AudibleGlamer()
    { return true; }

inline bool uailaRow1Darkness()
    { return true; }

inline bool uailaRow2Hypnotism()
    { return true; }

inline bool uailaRow3Light()
    { return true; }

inline bool uailaRow3GazeReflection()
    { return true; }

inline bool uailaRow4PhantasmalForce()
    { return true; }

inline bool uailaRow4WallOfFog()
    { return true; }

inline bool uailaRow5ChromaticOrb()
    { return true; }

inline bool uailaRow5ChromaticOrbIsChoose()
    { return true; }

inline bool uailaOffensiveMiscColumnsMerged()
    { return true; }

inline bool uailaMiscChangeSelf()
    { return true; }

inline bool uailaMiscDancingLights()
    { return true; }

inline bool uailaMiscDetect()
    { return true; }

inline bool uailaMiscDetectInvisibility()
    { return true; }

inline bool uailaMiscPhantomArmor()
    { return true; }

inline bool uailaRowBoundariesLost()
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

