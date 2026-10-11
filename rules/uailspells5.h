// ===========================================================================
// Adnd1 - rules/uailspells5.h
// The UA NEW ILLUSIONIST SPELLS (pp. 70-71) pins,
// R364: the 5th-level spell descriptions - the
// advanced illusion, dream, magic mirror and tempus
// fugit.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists.
//
// JUDGMENTs (the decode method):
//   - the first name header garbles to a bare (lllusi )
//     parenthesis fragment - the name pins from the
//     gap item list (the R363 chromatic-orb
//     precedent): advanced illusion; the prose
//     program spell cross-reference garbles and its
//     components (a bit of fleece and several grains
//     of sand) corroborate the identification.
//   - the bare-7 cells (the advanced illusion and
//     magic mirror durations, both 7 round/level; the
//     dream casting time, 7 day) read as holes pending
//     the PDF - the R343 digit-garble precedent
//     decoded only the 7 segment form with its
//     corroborated 1, and no corroborating print
//     exists here, so no numeric pin.
//   - the magic mirror is a cross-reference reprint
//     (virtually the same as the 4th-level magic-user
//     spell); its dollar-sign components cell decodes
//     to V, S, M per the R363 symbol-garble
//     convention.
//   - the tempus fugit area cell prints 7 radius -
//     unlike the per-level duration cells an area
//     radius has no corroborating print either way;
//     pinned as printed, the doubt noted pending the
//     PDF.
//   - the R342 IL table seam: the 5th-level column is
//     wholly lost - none of the new names
//     seam-checks, asserted in the audit.
// ===========================================================================

#pragma once

namespace rules {

// ---- advanced illusion ----
// The name header garbles to a bare (lllusi )
// fragment - the name pins from the gap item list;
// the prose cross-reference garbles (the similar-to
// fragment), a hole pending the PDF.
inline const char* uail5AdvilName()
    { return "Advanced Illusion (Illusion/Phantasm)"; }

inline bool uail5AdvilNameHeaderGarbled()
    { return true; }

inline int uail5AdvilLevel()
    { return 5; }

inline bool uail5AdvilComponentsVSM()
    { return true; }

inline int uail5AdvilCastingTimeSegments()
    { return 5; }

inline int uail5AdvilRangeInches()
    { return 6; }

inline int uail5AdvilRangeInchesPerLevel()
    { return 1; }

inline bool uail5AdvilSaveSpecial()
    { return true; }

inline bool uail5AdvilDurationCellSuspectGarble()
    { return true; }

inline int uail5AdvilAoeSquares()
    { return 4; }

inline int uail5AdvilAoeSquaresPerLevel()
    { return 1; }

inline bool uail5AdvilAoeCellInterleaved()
    { return true; }

inline bool uail5AdvilProgramSpell()
    { return true; }

inline bool uail5AdvilCrossRefCellGarbled()
    { return true; }

// The caster need only concentrate 5 segments after
// casting; the program then runs alone.
inline int uail5AdvilConcentrationSegments()
    { return 5; }

inline bool uail5AdvilProgramRunsAlone()
    { return true; }

inline bool uail5AdvilVisualComponent()
    { return true; }

inline bool uail5AdvilFullAudialComponent()
    { return true; }

inline bool uail5AdvilOlfactoryComponent()
    { return true; }

inline bool uail5AdvilThermalComponent()
    { return true; }

inline bool uail5AdvilActiveDisbelieveGrantsSave()
    { return true; }

inline int uail5AdvilCommunicatedDisbeliefBonus()
    { return 4; }

// The material components: a bit of fleece and
// several grains of sand - they corroborate the
// name decode.
inline bool uail5AdvilComponentsFleeceAndSand()
    { return true; }

// ---- dream ----
// The casting-time cell prints a bare 7 day - a hole
// pending the PDF (no corroborating print exists to
// decode the 7).
inline const char* uail5DreamName()
    { return "Dream (Alteration - Illusion/Phantasm)"; }

inline int uail5DreamLevel()
    { return 5; }

inline bool uail5DreamRangeSpecial()
    { return true; }

inline bool uail5DreamDurationSpecial()
    { return true; }

inline bool uail5DreamAoeSpecial()
    { return true; }

inline bool uail5DreamComponentsSpecial()
    { return true; }

inline bool uail5DreamCastingTimeCellSuspectGarble()
    { return true; }

inline bool uail5DreamSaveNegates()
    { return true; }

inline bool uail5DreamLimitedWishForm()
    { return true; }

inline bool uail5DreamMoreLimitedScope()
    { return true; }

inline bool uail5DreamMustLieProneAndSleep()
    { return true; }

inline int uail5DreamUndisturbedSleepHours()
    { return 8; }

inline int uail5DreamEffectuatedHoursMin()
    { return 1; }

inline int uail5DreamEffectuatedHoursMax()
    { return 12; }

inline bool uail5DreamResultRecoverLostHp()
    { return true; }

inline bool uail5DreamResultRestoreBodyMember()
    { return true; }

inline bool uail5DreamResultLocateUnguardedObject()
    { return true; }

inline bool uail5DreamResultDiscoverIngressEgress()
    { return true; }

inline bool uail5DreamResultSafeWildernessPath()
    { return true; }

inline bool uail5DreamResultImproveTreasureChances()
    { return true; }

// A scried creature of the printed hit-dice threshold
// may save; the threshold prints the clean 7 in the
// prose (unlike the stat-cell garbles), pinned as
// printed pending the PDF.
inline int uail5DreamScriedSaveHdThreshold()
    { return 7; }

inline bool uail5DreamScriedSaveHidesFromDream()
    { return true; }

inline bool uail5DreamScriedMaySenseCaster()
    { return true; }

inline bool uail5DreamResultsStrictlyLimited()
    { return true; }

inline bool uail5DreamNeverExceedsOnPermanentBasis()
    { return true; }

inline int uail5DreamCompanionTurnsPerLevel()
    { return 1; }

inline bool uail5DreamUnaffectedByExtensionOrPermanency()
    { return true; }

inline bool uail5DreamOncePerWeek()
    { return true; }

inline bool uail5DreamSecondCastInWeekFails()
    { return true; }

inline int uail5DreamSecondCastAgesYearsMin()
    { return 1; }

inline int uail5DreamSecondCastAgesYearsMax()
    { return 10; }

// ---- magic mirror ----
// A cross-reference reprint: virtually the same as
// the 4th-level magic-user spell of the same name;
// the dollar-sign components cell decodes to V, S, M
// per the R363 symbol-garble convention; the
// duration cell prints a bare 7 round/level - a hole
// pending the PDF.
inline const char* uail5MirrorName()
    { return "Magic Mirror (Enchantment - Divination)"; }

inline int uail5MirrorLevel()
    { return 5; }

inline bool uail5MirrorComponentsVSM()
    { return true; }

inline int uail5MirrorCastingTimeHours()
    { return 1; }

inline bool uail5MirrorRangeTouch()
    { return true; }

inline bool uail5MirrorSaveNone()
    { return true; }

inline bool uail5MirrorDurationCellSuspectGarble()
    { return true; }

inline bool uail5MirrorAoeSpecial()
    { return true; }

inline bool uail5MirrorSameAsFourthLevelMuSpell()
    { return true; }

inline bool uail5MirrorSameMaterialComponents()
    { return true; }

inline bool uail5MirrorVisionSpellReplacesComponents()
    { return true; }

inline bool uail5MirrorStillScrysWithVision()
    { return true; }

inline bool uail5MirrorVisionDoesNotFunctionNormally()
    { return true; }

// ---- tempus fugit ----
// The area cell prints 7 radius - pinned as printed
// (an area radius has no corroborating print either
// way), the doubt noted pending the PDF.
inline const char* uail5TempusName()
    { return "Tempus Fugit (Illusion/Phantasm)"; }

inline bool uail5TempusReversible()
    { return true; }

inline int uail5TempusLevel()
    { return 5; }

inline bool uail5TempusComponentsVerbalSomatic()
    { return true; }

inline int uail5TempusCastingTimeSegments()
    { return 5; }

inline int uail5TempusRangeInches()
    { return 0; }

inline bool uail5TempusSaveNone()
    { return true; }

inline int uail5TempusDurationTurnsPerLevel()
    { return 5; }

inline int uail5TempusAoeRadiusInches()
    { return 7; }

inline bool uail5TempusAffectsMindsAndBodies()
    { return true; }

inline bool uail5TempusLatecomersAlsoAffected()
    { return true; }

inline bool uail5TempusTurnSeemsLikeAnHour()
    { return true; }

inline bool uail5TempusFunctionsSpedUp()
    { return true; }

inline bool uail5TempusOtherSpellDurationsSped()
    { return true; }

inline bool uail5TempusOneHourIsAsSix()
    { return true; }

inline bool uail5TempusFourHoursAFullDay()
    { return true; }

inline bool uail5TempusAllowsRestRenewalRecovery()
    { return true; }

inline bool uail5TempusReversalSlowsTime()
    { return true; }

inline bool uail5TempusReverseHourSeemsATurn()
    { return true; }

inline bool uail5TempusReverseDayMereFourHours()
    { return true; }

inline bool uail5TempusReversalNeedsNoPreparation()
    { return true; }

inline bool uail5TempusCasterAlsoAffected()
    { return true; }

// Under the reverse the effects last at least 1 turn
// after the caster desires the dispelling (the
// slowed-reactions read).
inline int uail5TempusReverseLingersTurnsMin()
    { return 1; }

inline bool uail5TempusReverseLingersBySlowReactions()
    { return true; }

}   // namespace rules

