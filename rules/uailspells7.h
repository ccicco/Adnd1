// ===========================================================================
// Adnd1 - rules/uailspells7.h
// The UA NEW ILLUSIONIST SPELLS (pp. 72-73) pins,
// R365: the 7th-level spell descriptions - shadow
// walk and weird.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists.
//
// JUDGMENTs (the decode method):
//   - the shadow walk components cell garbles (a
//     dollar sign) - the symbol does not decode
//     (the R364 magic-mirror S$ cell carried its
//     S; a bare $ is ambiguous), a hole pending
//     the PDF; the school tail garbles (lllusion)
//     and decodes per the R363 convention.
//   - the shadow walk casting cell prints 7
//     segment - the digit-garble family (the R343
//     precedent) decodes the 1 segment; the weird
//     casting cell prints 7 segments (the plural)
//     and pins clean at 7.
//   - the weird description is largely OCR-lost -
//     the interleaved mirage arcane tail (the mind
//     of the beholder sentence) belongs to the
//     mirage arcane pin, not the weird; only the
//     stat block and a caster-must fragment pin,
//     the prose hole documented.
//   - the R342 IL table seam: the readable 7th
//     column prints only Shadow Walk (asserted);
//     the 7th names beyond it are lost-column.
// ===========================================================================

#pragma once

namespace rules {

// ---- shadow walk ----
inline const char* uail7ShadowName()
    { return "Shadow Walk (Illusion - Enchantment)"; }

inline int uail7ShadowLevel()
    { return 7; }

inline bool uail7ShadowComponentsCellGarbled()
    { return true; }

inline bool uail7ShadowRangeTouch()
    { return true; }

inline int uail7ShadowCastingTimeSegments()
    { return 1; }

inline bool uail7ShadowSaveNone()
    { return true; }

inline int uail7ShadowDurationTurnsPerLevel()
    { return 6; }

inline bool uail7ShadowAoeSpecial()
    { return true; }

inline bool uail7ShadowRequiresHeavyShadows()
    { return true; }

inline bool uail7ShadowEdgeOfPrimeMaterial()
    { return true; }

inline bool uail7ShadowAwareOfPrimePosition()
    { return true; }

inline int uail7ShadowLeaguesPerTurn()
    { return 7; }

inline bool uail7ShadowRapidTravelByStepping()
    { return true; }

inline bool uail7ShadowDestinationControlled()
    { return true; }

inline bool uail7ShadowOtherPlanesPerilousTransit()
    { return true; }

inline bool uail7ShadowTouchedAlsoTransition()
    { return true; }

inline bool uail7ShadowMayFollowWanderOrStumble()
    { return true; }

inline bool uail7ShadowLostOrAbandonedFiftyFifty()
    { return true; }

inline bool uail7ShadowUnwillingSaveNegates()
    { return true; }

// ---- weird ----
// The description is largely OCR-lost - the
// interleaved belief-effect prose belongs to the
// mirage arcane pin; only the stat block and a
// caster-must fragment print for the weird.
inline const char* uail7WeirdName()
    { return "Weird (Evocation - Illusion/Phantasm)"; }

inline int uail7WeirdLevel()
    { return 7; }

inline bool uail7WeirdComponentsVerbalSomatic()
    { return true; }

inline int uail7WeirdCastingTimeSegments()
    { return 7; }

inline int uail7WeirdRangeInches()
    { return 3; }

inline bool uail7WeirdSaveSpecial()
    { return true; }

inline bool uail7WeirdDurationSpecial()
    { return true; }

inline int uail7WeirdAoeRadiusInches()
    { return 2; }

inline bool uail7WeirdProseLargelyLost()
    { return true; }

inline bool uail7WeirdCasterMustFragmentPrints()
    { return true; }

}   // namespace rules

