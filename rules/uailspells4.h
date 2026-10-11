// ===========================================================================
// Adnd1 - rules/uailspells4.h
// The UA NEW ILLUSIONIST SPELLS (pp. 69-70) pins,
// R364: the 4th-level spell descriptions - dispel
// magic, rainbow pattern, solid fog and vacancy.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists.
//
// JUDGMENTs (the decode method):
//   - the vacancy level cell prints the clean 4 - it
//     matches the item list; the print sits between a
//     stray 5TH LEVEL header and the Fifth Level
//     Spells header - the level cell wins, the header
//     noise noted.
//   - the solid fog level cell does not print - the
//     level pins from the Fourth Level Spells section
//     header (the R363 read-magic precedent); its
//     area cell prints 2 cubic with the unit lost and
//     its component cell garbles (a peas/hoof fragment
//     pile) - holes pending the PDF.
//   - the dispel magic area cell interleaves with the
//     prose (the 3 inch cube fragments) - the cell
//     decodes from the fragments; the two-levels-below
//     cast read and the clerical cross-reference pin
//     from the prose.
//   - the rainbow pattern casting-time cell prints a
//     bare Casting Time - the value is lost, a hole.
//   - the section sign components cells (dispel
//     magic) decode to the somatic S per the R363
//     convention.
//   - the bare-7 duration cell (vacancy 7 turn/level)
//     reads as a hole pending the PDF - no
//     corroborating print exists to decode it, so no
//     numeric pin.
//   - the R342 IL table seam: the 4th-level column is
//     wholly lost - none of the new names
//     seam-checks, asserted in the audit.
// ===========================================================================

#pragma once

namespace rules {

// ---- dispel magic ----
// The area cell interleaves with the prose; the
// fragments (3 inch cube, identical to the 3rd-level
// clerical spell) decode the cell.
inline const char* uail4DispelName()
    { return "Dispel Magic (Abjuration)"; }

inline int uail4DispelLevel()
    { return 4; }

inline int uail4DispelRangeInches()
    { return 9; }

inline bool uail4DispelDurationPermanent()
    { return true; }

inline int uail4DispelAoeInchesCube()
    { return 3; }

inline bool uail4DispelAoeCellInterleaved()
    { return true; }

inline bool uail4DispelComponentsVerbalSomatic()
    { return true; }

inline int uail4DispelCastingTimeSegments()
    { return 4; }

inline bool uail4DispelSaveNone()
    { return true; }

inline bool uail4DispelSameAsClericalThirdLevel()
    { return true; }

inline bool uail4DispelCastsTwoLevelsBelow()
    { return true; }

inline bool uail4DispelExampleNinthCastsAsSeventh()
    { return true; }

// ---- rainbow pattern ----
// The casting-time cell prints a bare Casting Time -
// the value is lost, a hole pending the PDF.
inline const char* uail4RainbowName()
    { return "Rainbow Pattern (Alteration/Phantasm)"; }

inline int uail4RainbowLevel()
    { return 4; }

inline bool uail4RainbowComponentsSomaticMaterial()
    { return true; }

inline bool uail4RainbowCastingTimeCellLost()
    { return true; }

inline int uail4RainbowRangeInches()
    { return 1; }

inline bool uail4RainbowSaveNegates()
    { return true; }

inline bool uail4RainbowDurationSpecial()
    { return true; }

inline int uail4RainbowAoeInchesSquare()
    { return 3; }

inline bool uail4RainbowPastelGlowingBand()
    { return true; }

inline bool uail4RainbowSameEffectAsHypnoticPattern()
    { return true; }

inline bool uail4RainbowMovesInGesturedDirection()
    { return true; }

inline int uail4RainbowSpeedInchesPerRound()
    { return 3; }

inline int uail4RainbowPersistsRoundsMin()
    { return 1; }

inline int uail4RainbowPersistsRoundsMax()
    { return 3; }

inline int uail4RainbowFollowerLevelsOrHdCap()
    { return 24; }

inline bool uail4RainbowDangerAllowsSecondSave()
    { return true; }

inline bool uail4RainbowBlockedViewNegates()
    { return true; }

inline bool uail4RainbowObscurementExample()
    { return true; }

// The material components: a crystal prism and a
// piece of phosphor.
inline bool uail4RainbowComponentsPrismPhosphor()
    { return true; }

// ---- solid fog ----
// The level cell does not print - the level pins from
// the Fourth Level Spells section header (the R363
// read-magic precedent); the area cell prints 2 cubic
// with the unit lost and the component cell garbles -
// holes pending the PDF.
inline const char* uail4FogName()
    { return "Solid Fog (Alteration)"; }

inline int uail4FogLevel()
    { return 4; }

inline bool uail4FogLevelCellLost()
    { return true; }

inline int uail4FogDurationRoundsBaseMin()
    { return 2; }

inline int uail4FogDurationRoundsBaseMax()
    { return 8; }

inline int uail4FogDurationPlusPerLevel()
    { return 1; }

inline int uail4FogAoeCubicPerLevel()
    { return 2; }

inline bool uail4FogAoeUnitCellLost()
    { return true; }

inline bool uail4FogComponentsVSM()
    { return true; }

inline int uail4FogCastingTimeSegments()
    { return 4; }

inline bool uail4FogSaveNone()
    { return true; }

inline bool uail4FogRollingBillowingWallOfFog()
    { return true; }

inline bool uail4FogOnlyVeryStrongWindMoves()
    { return true; }

inline bool uail4FogGustOfWindCannotAffect()
    { return true; }

// Movement through the fog: 1 inch of normal rate
// per inch of fog per round.
inline int uail4FogMoveInchesPerRound()
    { return 1; }

inline bool uail4FogFireballBurnsAwayOneRound()
    { return true; }

inline bool uail4FogFlameStrikeBurnsAway()
    { return true; }

inline bool uail4FogWallOfFireBurnsAway()
    { return true; }

inline bool uail4FogComponentCellGarbled()
    { return true; }

// ---- vacancy ----
// The duration cell prints a bare 7 turn/level - a
// hole pending the PDF (no corroborating print
// exists to decode the 7); the area cell interleaves
// (the 1 inch radius per level fragments).
inline const char* uail4VacancyName()
    { return "Vacancy (Alteration/Phantasm)"; }

inline int uail4VacancyLevel()
    { return 4; }

inline bool uail4VacancyComponentsVSM()
    { return true; }

inline int uail4VacancyCastingTimeSegments()
    { return 4; }

inline int uail4VacancyRangeInchesPerLevel()
    { return 1; }

inline bool uail4VacancySaveNone()
    { return true; }

inline bool uail4VacancyDurationCellSuspectGarble()
    { return true; }

inline int uail4VacancyAoeRadiusInchesPerLevel()
    { return 1; }

inline bool uail4VacancyAreaSeemsVacantNeglected()
    { return true; }

inline bool uail4VacancyDustCobwebsDirtTypical()
    { return true; }

inline bool uail4VacancyPassageSeemsToLeaveTracks()
    { return true; }

inline bool uail4VacancyPassageTearsCobwebs()
    { return true; }

inline bool uail4VacancyOnlyForcefulContactDisturbs()
    { return true; }

inline bool uail4VacancyCloaksOnlyNonLivingThings()
    { return true; }

inline bool uail4VacancyLivingThingsNotInvisible()
    { return true; }

inline bool uail4VacancyForcefulContactGrantsSaves()
    { return true; }

inline bool uail4VacancyFailedSaveBelievesInvisible()
    { return true; }

inline bool uail4VacancyDispelRemovesDweomer()
    { return true; }

inline bool uail4VacancyTrueSeeingPenetrates()
    { return true; }

inline bool uail4VacancyGemOfSeeingPenetrates()
    { return true; }

inline bool uail4VacancyDetectInvisibilityCannot()
    { return true; }

// The material component: a square of finest black
// silk of not less than 100 gp value.
inline int uail4VacancySilkMinGpValue()
    { return 100; }

}   // namespace rules

