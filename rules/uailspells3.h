// ===========================================================================
// Adnd1 - rules/uailspells3.h
// The UA NEW ILLUSIONIST SPELLS (pp. 68-69) pins, R364:
// the 3rd-level spell descriptions - delude,
// phantom steed, phantom wind and wraithform.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists.
//
// JUDGMENTs (the decode method):
//   - the delude and wraithform level cells print the
//     clean 3 under the Third Level Spells header - the
//     item list (the R322 index) carries both at 2nd;
//     the print wins (the R363 phantom-armor
//     precedent), the divergence flagged in the round
//     note pending the PDF.
//   - phantom steed and phantom wind appear under the
//     same printed header but nowhere in the item
//     list (its 3rd-level claim says nothing new per
//     the headers) - both pinned as printed; the R342
//     IL table seam carries a Phantom Wind fragment
//     among its lost-column holes, corroborating the
//     wind.
//   - the wraithform casting cell prints 7 segment -
//     the digit-garble family (the R343 precedent,
//     the R363 chromatic-orb reuse) decodes the 1
//     segment.
//   - the bare-7 duration cells (phantom wind 7
//     round/level) and the empty cells (the phantom
//     steed casting time, the saving throw, the
//     phantom wind range) read as holes pending the
//     PDF - no corroborating print exists to decode
//     them, so no numeric pin.
//   - the phantom steed components cell prints V, S
//     with a trailing comma - the tail is lost, a
//     hole; the phantom wind and wraithform section
//     garbles (the section sign for S, the lllusion
//     school tail) decode per the R363 convention.
//   - the R342 IL table seam: the 3rd-level column is
//     wholly lost - none of the new names
//     seam-checks, asserted in the audit.
// ===========================================================================

#pragma once

namespace rules {

// ---- delude ----
// The components cell prints a bare V with a trailing
// comma - the tail is lost, a hole pending the PDF.
inline const char* uail3DeludeName()
    { return "Delude (Alteration)"; }

inline bool uail3DeludeVerbalComponent()
    { return true; }

inline bool uail3DeludeComponentsTailLost()
    { return true; }

inline int uail3DeludeLevel()
    { return 3; }

inline int uail3DeludeRangeInches()
    { return 0; }

inline int uail3DeludeCastingTimeSegments()
    { return 3; }

inline bool uail3DeludeSaveNegates()
    { return true; }

inline int uail3DeludeDurationTurnsPerLevel()
    { return 1; }

inline bool uail3DeludeAoeTheIllusionist()
    { return true; }

// The aura exchange radius: 3 inches.
inline int uail3DeludeAuraRadiusInches()
    { return 3; }

inline bool uail3DeludeTargetMustExceedAnimalInt()
    { return true; }

inline bool uail3DeludeTargetRetainsAlignment()
    { return true; }

inline bool uail3DeludeKnowAlignmentSeesAuraOnly()
    { return true; }

inline bool uail3DeludeDetectSeesSubstitutedAura()
    { return true; }

inline bool uail3DeludeCopiedCreatureRadiatesMagic()
    { return true; }

inline bool uail3DeludeCasterRadiatesToSourceOnly()
    { return true; }

inline bool uail3DeludeWithChangeOrAlterSelfHides()
    { return true; }

inline bool uail3DeludeSaveOnlyOnAuraTransfer()
    { return true; }

// ---- phantom steed ----
// The casting-time cell garbles (a bare Casting Tim)
// and the saving-throw cell prints empty - holes
// pending the PDF.
inline const char* uail3SteedName()
    { return "Phantom Steed (Conjuration/Phantasm)"; }

inline int uail3SteedLevel()
    { return 3; }

inline bool uail3SteedComponentsVerbalSomatic()
    { return true; }

inline bool uail3SteedComponentsTailLost()
    { return true; }

inline bool uail3SteedRangeTouch()
    { return true; }

inline bool uail3SteedCastingTimeCellGarbled()
    { return true; }

inline int uail3SteedDurationTurnsPerLevel()
    { return 6; }

inline bool uail3SteedSaveCellEmpty()
    { return true; }

inline bool uail3SteedAoeSpecial()
    { return true; }

inline bool uail3SteedQuasiRealHorseLike()
    { return true; }

inline bool uail3SteedRiddenOnlyByCasterOrNamed()
    { return true; }

inline bool uail3SteedBlackHeadsAndBodies()
    { return true; }

inline bool uail3SteedGrayManesAndTails()
    { return true; }

inline bool uail3SteedSmokeColoredHooves()
    { return true; }

inline bool uail3SteedHoovesMakeNoSound()
    { return true; }

inline bool uail3SteedMilkyEyes()
    { return true; }

inline bool uail3SteedDoesNotFight()
    { return true; }

inline bool uail3SteedNormalAnimalsShun()
    { return true; }

inline bool uail3SteedOnlyMonstrousAnimalsAttack()
    { return true; }

// More than 12 points of damage dispels the steed.
inline int uail3SteedDamageToDispel()
    { return 12; }

inline int uail3SteedMaxRateInchesPerLevel()
    { return 4; }

inline bool uail3SteedSeemingSaddleAndBridle()
    { return true; }

inline bool uail3SteedCannotCarrySaddlebags()
    { return true; }

inline bool uail3SteedPower8thSoftGround()
    { return true; }

inline bool uail3SteedPower10thOverWater()
    { return true; }

inline bool uail3SteedPower12thAirTravel()
    { return true; }

inline bool uail3SteedPower12thNoCasualFlight()
    { return true; }

inline bool uail3SteedPower14thAsPegasus()
    { return true; }

// ---- phantom wind ----
// The components cell prints V with a section sign -
// the R363 convention decodes the somatic S; the range
// cell prints empty and the duration cell prints a
// bare 7 round/level - holes pending the PDF (no
// corroborating print exists to decode the 7).
inline const char* uail3PwindName()
    { return "Phantom Wind (Alteration/Phantasm)"; }

inline int uail3PwindLevel()
    { return 3; }

inline bool uail3PwindComponentsVerbalSomatic()
    { return true; }

inline int uail3PwindCastingTimeSegments()
    { return 3; }

inline bool uail3PwindRangeCellEmpty()
    { return true; }

inline bool uail3PwindSaveNone()
    { return true; }

inline bool uail3PwindDurationCellSuspectGarble()
    { return true; }

inline int uail3PwindAoeInchesBroadPath()
    { return 1; }

inline bool uail3PwindCannotBeSeenOrFelt()
    { return true; }

inline bool uail3PwindBlowsLightObjects()
    { return true; }

inline bool uail3PwindFluttersCurtainsAndDrapes()
    { return true; }

inline bool uail3PwindFlapsLooseClothing()
    { return true; }

inline bool uail3PwindFansFires()
    { return true; }

inline bool uail3PwindMovesGaseousClouds()
    { return true; }

inline bool uail3PwindMovesInPointedDirection()
    { return true; }

inline int uail3PwindPathGrowsInchesPerRound()
    { return 1; }

inline bool uail3PwindEffectsLastWholePath()
    { return true; }

// The vessel sentence interleaves as fragments (es
// the one iled to vessels) - a hole pending the PDF.
inline bool uail3PwindVesselSentenceGarbled()
    { return true; }

// ---- wraithform ----
// The stat tail prints displaced after the prose (the
// components and casting-time cells follow the
// description); the school tail garbles (lllusion)
// and decodes per the R363 convention; the casting
// cell prints 7 segment - the R343 digit-garble
// precedent decodes the 1 segment.
inline const char* uail3WraithName()
    { return "Wraithform (Alteration/Illusion)"; }

inline int uail3WraithLevel()
    { return 3; }

inline int uail3WraithRangeInches()
    { return 0; }

inline int uail3WraithDurationRoundsPerLevel()
    { return 2; }

inline bool uail3WraithAoeTheIllusionist()
    { return true; }

inline bool uail3WraithComponentsSomaticMaterial()
    { return true; }

inline int uail3WraithCastingTimeSegments()
    { return 1; }

inline bool uail3WraithSaveNone()
    { return true; }

inline bool uail3WraithInsubstantialWithGear()
    { return true; }

inline bool uail3WraithHitOnlyByPlusOneOrBetter()
    { return true; }

inline bool uail3WraithEtherealAbleCreaturesHit()
    { return true; }

inline bool uail3WraithMostUndeadIgnore()
    { return true; }

inline bool uail3WraithAppearsAsWraithOrSpectre()
    { return true; }

inline bool uail3WraithLichMayRecognize()
    { return true; }

// The lich save versus spell carries the -4 penalty.
inline int uail3WraithLichRecognizeSaveMod()
    { return -4; }

inline bool uail3WraithPassesThroughCracksWithGear()
    { return true; }

inline bool uail3WraithNoAttacksExceptVsEthereal()
    { return true; }

inline bool uail3WraithEtherealCombatNormalBothWays()
    { return true; }

inline bool uail3WraithDispelForcesNormalForm()
    { return true; }

inline bool uail3WraithReturnAtWillEndsSpell()
    { return true; }

// The material components: a bit of gauze and a wisp
// of smoke.
inline bool uail3WraithComponentsGauzeAndSmoke()
    { return true; }

}   // namespace rules

