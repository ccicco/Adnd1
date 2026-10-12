// ===========================================================================
// Adnd1 - rules/uailspells6.h
// The UA NEW ILLUSIONIST SPELLS (pp. 71-72) pins,
// R365: the 6th-level spell descriptions - death
// fog, mislead, phantasmagoria and the mirage
// arcane (printed at the 6th cell).
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists.
//
// JUDGMENTs (the decode method):
//   - the mirage arcane level cell prints the
//     clean 6 under the ILLUSIONIST SPELLS (7TH
//     LEVEL) header - the item list (the R322
//     index) names it at 7th; the print wins (the
//     R363 phantom-armor precedent), the
//     divergence flagged in the round note
//     pending the PDF; the R342 IL table seam
//     corroborates the print - the readable 7th
//     column carries only Shadow Walk.
//   - the phantasmagoria level cell does not
//     print - the level pins from the Sixth
//     Level Spells section header (the R364
//     solid-fog precedent).
//   - the suspect cells read as holes pending
//     the PDF, no numeric pin: the death fog
//     duration (7-4 rounds + 1/level - the
//     solid-fog parallel prints 2-8, no decode
//     exists), the mislead range (a bare 7),
//     the phantasmagoria duration (a bare 7)
//     and its area cell (4 square + 1 square
//     with the units lost).
//   - the mirage arcane casting time prints the
//     clean 3 or 6 segments - both forms pin,
//     corroborated by the prose (the basic form
//     3, the complex material-component form 6).
//   - the R342 IL table seam: the 6th-level
//     column is wholly lost - none of the new
//     names seam-checks, asserted in the audit.
// ===========================================================================

#pragma once

namespace rules {

// ---- death fog ----
inline const char* uail6DfogName()
    { return "Death Fog (Alteration - Evocation)"; }

inline int uail6DfogLevel()
    { return 6; }

inline bool uail6DfogComponentsVSM()
    { return true; }

inline int uail6DfogCastingTimeSegments()
    { return 6; }

inline int uail6DfogRangeInches()
    { return 3; }

inline bool uail6DfogSaveNone()
    { return true; }

inline bool uail6DfogDurationCellSuspectGarble()
    { return true; }

inline int uail6DfogAoeCubicPerLevel()
    { return 2; }

inline bool uail6DfogAoeUnitCellLost()
    { return true; }

inline bool uail6DfogCreatesSolidFogArea()
    { return true; }

inline bool uail6DfogHighlyAcidic()
    { return true; }

inline bool uail6DfogVaporsDeadlyToVegetation()
    { return true; }

// Plants exposed to the vapors die in 2 rounds.
inline int uail6DfogPlantsDieInRounds()
    { return 2; }

inline int uail6DfogBushesShrubsDieInRounds()
    { return 4; }

inline int uail6DfogSmallTreesDieInRounds()
    { return 8; }

inline int uail6DfogLargeTreesDieInRounds()
    { return 16; }

inline bool uail6DfogAnimalsNotImmuneSuffer()
    { return true; }

// The acid damage ladder by exposure round: 1,
// 2, 4, then 8 points every succeeding round.
inline int uail6DfogDamageRound1()
    { return 1; }

inline int uail6DfogDamageRound2()
    { return 2; }

inline int uail6DfogDamageRound3()
    { return 4; }

inline int uail6DfogDamageRound4On()
    { return 8; }

inline bool uail6DfogOtherwiseSameAsSolidFog()
    { return true; }

inline bool uail6DfogComponentsPeasHoofAcid()
    { return true; }

inline bool uail6DfogAcidIncludesVinegarCrystals()
    { return true; }

// ---- mislead ----
// The range cell prints a bare 7 - a hole
// pending the PDF (no corroborating print exists
// to decode it).
inline const char* uail6MisleadName()
    { return "Mislead (Illusion/Phantasm)"; }

inline int uail6MisleadLevel()
    { return 6; }

inline bool uail6MisleadSomaticOnly()
    { return true; }

inline int uail6MisleadCastingTimeSegments()
    { return 1; }

inline bool uail6MisleadRangeCellSuspectGarble()
    { return true; }

inline bool uail6MisleadSaveNone()
    { return true; }

inline int uail6MisleadDurationRoundsPerLevel()
    { return 1; }

inline bool uail6MisleadAoeSpecial()
    { return true; }

inline bool uail6MisleadCreatesPhantasmalDouble()
    { return true; }

inline bool uail6MisleadCloakedByImprovedInvis()
    { return true; }

inline bool uail6MisleadCasterFreeToGoElsewhere()
    { return true; }

inline bool uail6MisleadPhantasmSeeminglyMovesAway()
    { return true; }

inline bool uail6MisleadPhantasmSpeaksAndGestures()
    { return true; }

inline bool uail6MisleadSensorySentenceGarbled()
    { return true; }

inline bool uail6MisleadTrueSightRevealsIllusion()
    { return true; }

inline bool uail6MisleadGemOfSeeingRevealsIllusion()
    { return true; }

inline bool uail6MisleadDetectInvisDetectsCaster()
    { return true; }

inline bool uail6MisleadTrueSightDetectsCaster()
    { return true; }

inline bool uail6MisleadTrueSeeingDetectsCaster()
    { return true; }

inline bool uail6MisleadRobeOfEyesDetectsCaster()
    { return true; }

inline bool uail6MisleadShadowDoorCrossRef()
    { return true; }

// ---- phantasmagoria ----
// The level cell does not print - the level pins
// from the Sixth Level Spells section header (the
// R364 solid-fog precedent); the duration prints
// a bare 7 round/level and the area cell garbles
// (4 square + 1 square with the units lost) -
// holes pending the PDF.
inline const char* uail6PhantName()
    { return "Phantasmagoria (Illusion/Phantasm)"; }

inline int uail6PhantLevel()
    { return 6; }

inline bool uail6PhantLevelCellLost()
    { return true; }

inline bool uail6PhantComponentsVerbalSomatic()
    { return true; }

inline int uail6PhantCastingTimeSegments()
    { return 6; }

inline bool uail6PhantSaveNegates()
    { return true; }

inline bool uail6PhantDurationCellSuspectGarble()
    { return true; }

inline bool uail6PhantAoeCellGarbled()
    { return true; }

inline bool uail6PhantSpecialFormOfSpectralForces()
    { return true; }

inline bool uail6PhantTriggeredBySpecialAction()
    { return true; }

inline bool uail6PhantFullVisualAudialOlfactoryTouch()
    { return true; }

inline bool uail6PhantFallingSlidingMovingRapidly()
    { return true; }

inline bool uail6PhantTriggerOnPitFallOrDoorOpen()
    { return true; }

inline bool uail6PhantMustInvolveFallingRushing()
    { return true; }

inline bool uail6PhantDwindlingPerspectiveRead()
    { return true; }

inline bool uail6PhantUnlikeProgrammedIllusion()
    { return true; }

// ---- mirage arcane ----
// The level cell prints the clean 6 under the
// 7TH LEVEL header - the item list names it at
// 7th; the print wins, the divergence flagged in
// the round note pending the PDF.
inline const char* uail6MirageName()
    { return "Mirage Arcane (Illusion/Phantasm - Alteration)"; }

inline int uail6MirageLevel()
    { return 6; }

inline bool uail6MirageLevelDivergenceFlagged()
    { return true; }

inline bool uail6MirageComponentsVSOptionalM()
    { return true; }

inline int uail6MirageRangeInchesPerLevel()
    { return 1; }

inline int uail6MirageCastingTimeBasicSegments()
    { return 3; }

inline int uail6MirageCastingTimeComplexSegments()
    { return 6; }

inline bool uail6MirageSaveNone()
    { return true; }

inline bool uail6MirageDurationSpecial()
    { return true; }

inline int uail6MirageAoeRadiusInchesPerLevel()
    { return 1; }

inline bool uail6MirageSimilarToVacancyButStronger()
    { return true; }

inline bool uail6MirageSimilarToMirageCantrip()
    { return true; }

inline bool uail6MirageAreaAppearsOtherThanItIs()
    { return true; }

inline bool uail6MirageEnvisionedByCaster()
    { return true; }

inline bool uail6MirageHeldByFaintConcentration()
    { return true; }

inline int uail6MiragePersistsBaseTurns()
    { return 6; }

inline int uail6MiragePersistsTurnsPerLevel()
    { return 1; }

inline bool uail6MirageConcentrationOkInConversation()
    { return true; }

inline bool uail6MirageConcentrationNotInCombat()
    { return true; }

inline bool uail6MirageMustBePersonallySeen()
    { return true; }

inline bool uail6MirageMaterialBitGrantsReality()
    { return true; }

inline bool uail6MirageBasicForcefulContactNeeded()
    { return true; }

inline bool uail6MirageComplexDetectionOnlyMagical()
    { return true; }

inline bool uail6MirageSubjectToDispelIllusionOrMagic()
    { return true; }

inline bool uail6MirageMindCausesBodyEffects()
    { return true; }

inline bool uail6MirageBeliefCannotAffectLawsOfNature()
    { return true; }

inline bool uail6MirageHotCoalsExample()
    { return true; }

inline bool uail6MirageImaginaryFoodNourishes()
    { return true; }

inline bool uail6MirageFeatherbedExample()
    { return true; }

inline bool uail6MirageGravityUnaffected()
    { return true; }

inline bool uail6MirageEnvisionedBridgeWillNotHold()
    { return true; }

inline bool uail6MirageWitnessesSeeDisappearance()
    { return true; }

inline bool uail6MirageDisappearanceNotLinkedToIllusion()
    { return true; }

}   // namespace rules

