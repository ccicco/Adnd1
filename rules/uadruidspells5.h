// ===========================================================================
// Adnd1 - rules/uadruidspells5.h
// The UA NEW DRUID SPELLS (p. 45) pins, R353: the 5th-level
// spell descriptions - moonbeam and spike stones.
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
//
// JUDGMENTs (the decode method):
//   - the digit-garble family (the R343 precedent): the moonbeam
//     casting time prints "7 segments" - the family decodes
//     1 segment (moonbeam prints a clean "Level: 5" cell).
//   - the moonbeam name header prints "Moonbeam (Evocation -
//     Alteration)" without the "## " marker - a formatting loss,
//     not a content loss; the name and school pin clean.
//   - the moonbeam range cell prints "Range: 1" - the unit mark
//     is lost; position-decoded as 1 inch (the R346 interleave
//     precedent), pinned with doubt pending the PDF.
//   - the spike stones school cell prints "Alteration/
//     Enhancement" while the R347 clerical pin (rules/
//     uaclericspells5.h) reads "Alteration/Enchantment" - the
//     druid cell is pinned verbatim with the discrepancy
//     flagged; pending the PDF.
//   - the spike stones casting time cell prints empty - a hole;
//     the clerical R347 pin reads 6 segments (noted, not
//     re-pinned here).
//   - the spike stones prose: "This spell is the same as the
//     5th-level clerical spell of the same name." - the druid
//     version pins as identical; every stat cell seam-checks
//     against the R347 clerical pin (range 3", save none,
//     duration 3-12 turns + 1/level, area 1" square per level
//     with 1 spike per square foot).
//   - the druid spike stones area cell prints "1" square per
//     level, 1 spike per 1' sq." - corroborating the R347
//     decode of the clerical area cell.
//
// OCR holes (the item stays open - the 6th and 7th levels pin
// in later rounds; these stay pending the PDF): the moonbeam
// range unit mark; the spike stones casting time cell; the
// spike stones school discrepancy (Enhancement vs the R347
// clerical Enchantment).
// ===========================================================================

#pragma once

namespace rules {

// ---- moonbeam (Evocation - Alteration), p. 45 ----
inline const char* uad5MoonbeamName()
    { return "Moonbeam (Evocation - Alteration)"; }

// The name header prints without the "## " marker - a
// formatting loss; the name and school pin clean.
inline bool uad5MoonbeamHeaderMarkerLost()
    { return true; }

inline bool uad5MoonbeamComponentsVSM()
    { return true; }

inline int uad5MoonbeamLevel()
    { return 5; }

// The casting time prints "7 segments" - the digit-garble
// family decodes 1 segment.
inline int uad5MoonbeamCastingTimeSegments()
    { return 1; }

// The range cell prints "Range: 1" - the unit mark is lost;
// position-decoded as 1 inch, with doubt.
inline int uad5MoonbeamRangeInches()
    { return 1; }

inline bool uad5MoonbeamRangeUnitLost()
    { return true; }

inline bool uad5MoonbeamSaveNone()
    { return true; }

inline int uad5MoonbeamDurationRoundsPerLevel()
    { return 1; }

inline bool uad5MoonbeamAoeOneInchSpherePlusSpecial()
    { return true; }

// A beam of soft, pale light strikes downward from overhead and
// illuminates whatever area the caster is pointing at.
inline bool uad5MoonbeamDownwardBeamOnPointedArea()
    { return true; }

// The light is exactly the same as moonlight - colors other
// than shades of black, gray, or white are not determinable.
inline bool uad5MoonbeamExactMoonlight()
    { return true; }

inline bool uad5MoonbeamColorsNotDeterminable()
    { return true; }

// The caster can easily cause the moonbeam to move to any area
// he or she can see and point to - an effective spotlight, for
// example upon an opponent.
inline bool uad5MoonbeamMovesToSeenPointedAreas()
    { return true; }

inline bool uad5MoonbeamEffectiveSpotlight()
    { return true; }

// The moonbeam allows shadows; a creature centered in it is
// most certainly under observation.
inline bool uad5MoonbeamAllowsShadows()
    { return true; }

inline bool uad5MoonbeamCenteredCreatureObserved()
    { return true; }

// The reflected light allows dim visual perception 1 inch
// beyond the area of effect.
inline int uad5MoonbeamDimPerceptionInchesBeyond()
    { return 1; }

// The light does not adversely affect infravision, and
// enhances ultravision to its greatest potential.
inline bool uad5MoonbeamNoInfravisionAdverseEffect()
    { return true; }

inline bool uad5MoonbeamEnhancesUltravision()
    { return true; }

// The material: several seeds of any moonseed plant and a
// piece of opalescent feldspar (moonstone).
inline bool uad5MoonbeamMaterialMoonseedSeeds()
    { return true; }

inline bool uad5MoonbeamMaterialMoonstoneFeldspar()
    { return true; }

// ---- spike stones (Alteration/Enhancement), p. 45 ----
// The druid school cell prints "Alteration/Enhancement" - the
// R347 clerical pin reads "Alteration/Enchantment"; the druid
// cell is pinned verbatim with the discrepancy flagged.
inline const char* uad5SpikeStonesName()
    { return "Spike Stones (Alteration/Enhancement)"; }

inline bool uad5SpikeStonesSchoolDiscrepancyFlagged()
    { return true; }

inline bool uad5SpikeStonesComponentsVSM()
    { return true; }

inline int uad5SpikeStonesLevel()
    { return 5; }

// The casting time cell prints empty - a hole; the R347
// clerical pin reads 6 segments (noted, not re-pinned).
inline bool uad5SpikeStonesCastingTimeCellLost()
    { return true; }

inline int uad5SpikeStonesRangeInches()
    { return 3; }

inline bool uad5SpikeStonesSaveNone()
    { return true; }

inline int uad5SpikeStonesDurationTurnsMin()
    { return 3; }

inline int uad5SpikeStonesDurationTurnsMax()
    { return 12; }

inline int uad5SpikeStonesDurationTurnsPerLevel()
    { return 1; }

inline int uad5SpikeStonesAoeSquareInchesPerLevel()
    { return 1; }

inline int uad5SpikeStonesSpikesPerSquareFoot()
    { return 1; }

// The prose: this spell is the same as the 5th-level clerical
// spell of the same name.
inline bool uad5SpikeStonesIdenticalToClerical()
    { return true; }

}   // namespace rules
