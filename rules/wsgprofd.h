// =========================================================================================
// Adnd1 - rules/wsgprofd.h
// The WSG PROFICIENCIES PROSE, R498: the chapter frame and the twenty-five
// descriptions, printed pp. 11-17 (pdf 12-18). The Table 1/2 grids and the
// check/improving/expanding system stay with R425 (rules/wsgprof.h) as seams;
// this round pins the prose around and between them - every description
// mechanic from the 1-in-6 alertness surprise to the weather sense lockout.
// census 422 -> 423.
//
// WSG printed pp. 11-17, pdf 12-18, extracted at r497-extraction sha 0d5f109
// (tesseract full-text and tsv, x12-x18, 300 dpi) - the same pass as R497.
// The tesseract Table 2 read dropped rows but the grid is already pinned by
// R425 from the IIIF image; the descriptions prose read whole and clean.
//
// THE SETTLE: the last four WSG boxes flip in the same commit; the gap report
// lands at 186 closed / 0 open - THE ENTIRE WILDERNESS SURVIVAL GUIDE IS
// PINNED; census 422 -> 423.
//
namespace rules {

// ---- the chapter opener ----

// the proficiencies chapter starts at printed p. 11.
inline int wpdPrintedLo()
    { return 11; }

// the proficiencies chapter ends at printed p. 17.
inline int wpdPrintedHi()
    { return 17; }

// the chapter starts at pdf page 12.
inline int wpdPdfLo()
    { return 12; }

// the chapter ends at pdf page 18.
inline int wpdPdfHi()
    { return 18; }

// twenty-five proficiency descriptions, alertness through weather sense -
// matching the twenty-five Table 2 rows pinned by R425.
inline int wpdDescriptionCount()
    { return 25; }

// ---- the system frame and choosing skills ----

// the wilderness proficiency system is essentially the same as the Dungeoneer
// Survival Guide nonweapon system (the R425 seam).
inline bool wpdSystemMatchesDSG()
    { return true; }

// proficiencies shared with DSG (fire-building, land-based riding) work in
// both underground and above-ground environments.
inline bool wpdDualEnvironmentShared()
    { return true; }

// some proficiencies are underground-only by nature: fungus identification is
// the DSG example.
inline bool wpdUndergroundOnlyExists()
    { return true; }

// plant lore is useful only in the wilderness.
inline bool wpdPlantLoreWildernessOnly()
    { return true; }

// the selection of nonweapon proficiencies is basically up to the player.
inline bool wpdSelectionPlayerChooses()
    { return true; }

// players should respect character background: no desert survival without
// desert time, no swimming skill for a desert-raised character.
inline bool wpdBackgroundLogicRule()
    { return true; }

// advancement selections follow the same logic: no desert survival until
// sizable desert time.
inline bool wpdLevelingStillLogical()
    { return true; }

// direction sense is justifiable for practically any character at any time -
// an inborn knack or between-levels training.
inline bool wpdDirectionSenseEasyJustify()
    { return true; }

// all selections are subject to DM approval; an illogical pick may - must -
// be disallowed.
inline bool wpdDMApprovalRequired()
    { return true; }

// a delayed slot fill is allowed but should never be filled during an
// adventure - no sudden swimming in a lake.
inline bool wpdDelayAllowedNotDuringAdventure()
    { return true; }

// ---- the alertness, animal handling and animal lore group ----

// a successful alertness check reduces the surprise chance by 1 in 6, for the
// character and for any party members he can communicate with.
inline int wpdAlertSurpriseReductionIn6()
    { return 1; }

// a character without animal handling has only a 20 percent chance of calming
// an excited animal (the R490 seam).
inline int wpdAnimalHandlingNonprofPct()
    { return 20; }

// an animal lore check failed by 4 or less yields no information.
inline int wpdAnimalLoreNoInfoFailBy()
    { return 4; }

// an animal lore check failed by 5 or more yields incorrect information.
inline int wpdAnimalLoreWrongInfoFailBy()
    { return 5; }

// a successful animal handling check calms an excited or agitated animal.
inline bool wpdAnimalHandlingCalmsOnCheck()
    { return true; }

// ---- the blind-fighting group ----

// blind-fighting: the total-darkness attack and damage penalty is only -2
// (instead of -4).
inline int wpdBlindTotalDarkPen()
    { return 2; }

// the total-darkness penalty without blind-fighting.
inline int wpdBlindTotalDarkBasePen()
    { return 4; }

// blind-fighting: the natural-darkness penalty is only -1 (instead of -3).
inline int wpdBlindNaturalDarkPen()
    { return 1; }

// the natural-darkness penalty without blind-fighting.
inline int wpdBlindNaturalDarkBasePen()
    { return 3; }

// blind-fighting grants no armor class penalty from darkness.
inline bool wpdBlindNoACPenalty()
    { return true; }

// blind-fighting keeps special abilities and other proficiencies usable in
// darkness.
inline bool wpdBlindRetainsAbilities()
    { return true; }

// blind-fighting halves the chance of stumbling, tumbling into pits or over
// cliffs, and slipping while climbing.
inline bool wpdBlindAdverseChanceHalf()
    { return true; }

// blind-fighting is short-range only: no long-distance vision, tracking-scale
// sight excluded.
inline bool wpdBlindShortRangeOnly()
    { return true; }

// ---- the boating and charioteering group ----

// a boating-proficient pilot moves the vessel at its fastest possible rate
// (the R457 seam).
inline bool wpdBoatingFastestRate()
    { return true; }

// the boating proficiency reduces the capsize chance in rough water or high
// winds.
inline bool wpdBoatingReducesCapsize()
    { return true; }

// charioteering moves a chariot at one-third faster than the normal rate over
// negotiable terrain.
inline bool wpdCharioteerFasterRate()
    { return true; }

// charioteering never moves a chariot over terrain it cannot traverse - no
// chariots into the mountains.
inline bool wpdCharioteerNoImpossibleTerrain()
    { return true; }

// ---- the direction sense group ----

// a direction sense check in total darkness takes a +4 modifier.
inline int wpdDirSenseTotalDarkMod()
    { return 4; }

// a direction sense check in partial darkness takes a +2 modifier.
inline int wpdDirSensePartialDarkMod()
    { return 2; }

// a failed direction sense check (under 20) errs by 90 degrees left or right,
// at the DM decision.
inline int wpdDirSenseErrorDeg()
    { return 90; }

// the direction sense check is always rolled by the DM in secret.
inline bool wpdDirSenseSecretRoll()
    { return true; }

// a direction sense roll of 20 means the exact opposite direction.
inline bool wpdDirSenseNatural20Opposite()
    { return true; }

// with multiple direction-sense characters the DM checks for each; agreeing
// characters may both be right - or both wrong the same way.
inline bool wpdDirSenseMultiChecker()
    { return true; }

// ---- the endurance, fire-building and foraging group ----

// endurance doubles the time of continual strenuous activity before fatigue
// and exhaustion apply.
inline int wpdEnduranceStrenuousMult()
    { return 2; }

// endurance never extends the time a character can go without food or water.
inline bool wpdEnduranceNoFoodWaterExtension()
    { return true; }

// a successful fire-building check starts a fire without flint, steel or a
// tinderbox.
inline bool wpdFireBuildNoFlintOnCheck()
    { return true; }

// with proper equipment the fire-building proficient character takes half the
// normal time.
inline bool wpdFireBuildHalfTimeWithKit()
    { return true; }

// the fishing proficiency improves the catch - the R465 seam.
inline bool wpdFishingBetterCatch()
    { return true; }

// foraging yields twice the food in the same time, or the same food in half
// the time (the R463 seam).
inline bool wpdForagingTwiceOrHalfTime()
    { return true; }

// ---- the healing group ----

// emergency healing restores 1d3 hit points.
inline int wpdHealingEmergencyDie()
    { return 3; }

// emergency healing must begin within one round of the wound.
inline int wpdHealingWindowRounds()
    { return 1; }

// continuous care restores 1 hit point per day even while traveling.
inline int wpdHealingTravelHpPerDay()
    { return 1; }

// continuous care with rest restores 2 hit points per day.
inline int wpdHealingRestHpPerDay()
    { return 2; }

// healing aid in the poison round grants a +2 saving throw bonus versus
// poison.
inline int wpdHealingPoisonSaveBonus()
    { return 2; }

// the poison victim must rest one full turn to keep the saving throw bonus.
inline int wpdHealingPoisonRestTurns()
    { return 1; }

// the healer must aid the poison victim for at least five rounds after the
// poisoning round.
inline int wpdHealingPoisonAidRounds()
    { return 5; }

// disease aid must begin within three turns of the onset of symptoms.
inline int wpdHealingDiseaseWindowTurns()
    { return 3; }

// the diseased character needs aid from the healer twice per day at regular
// intervals.
inline int wpdHealingAidPerDay()
    { return 2; }

// two consecutive missed medicine sessions revert the disease to its original
// severity.
inline int wpdHealingMissRevertConsecutive()
    { return 2; }

// three total missed medicine sessions also revert the disease.
inline int wpdHealingMissRevertTotal()
    { return 3; }

// emergency healing never restores more than the wound caused in the
// preceding round.
inline bool wpdHealingCapAtWound()
    { return true; }

// the continuous-care benefit applies to only one character per day.
inline bool wpdHealingOnePatientPerDay()
    { return true; }

// the continuous-care recovery needs no Proficiency Check, only that healer
// and patient share a group.
inline bool wpdHealingContinuousNoCheck()
    { return true; }

// the poison saving throw bonus needs no check, only the same-round start,
// the one-turn rest and the five rounds of aid.
inline bool wpdHealingPoisonNoCheckNeeded()
    { return true; }

// missing either time requirement forces a fresh poison saving throw with no
// bonus.
inline bool wpdHealingPoisonMissResaves()
    { return true; }

// a successful disease check lowers the severity one step: terminal to
// severe, severe to mild.
inline bool wpdHealingDiseaseStepDown()
    { return true; }

// an already-mild disease runs its course in half the time under healing
// care.
inline bool wpdHealingMildHalfDuration()
    { return true; }

// ---- the hunting, mountaineering and plant lore group ----

// hunting with one extra character: +1 to the check.
inline int wpdHuntPartyMod1()
    { return 1; }

// hunting with two extra characters: +3.
inline int wpdHuntPartyMod2()
    { return 3; }

// hunting with three extra characters: +6.
inline int wpdHuntPartyMod3()
    { return 6; }

// hunting with four extra characters: +10.
inline int wpdHuntPartyMod4()
    { return 10; }

// hunting with five extra characters: +15.
inline int wpdHuntPartyMod5()
    { return 15; }

// a hunting party of six or more besides the hunter fails the check
// automatically - no roll needed.
inline int wpdHuntAutoFailPartySize()
    { return 6; }

// the hunting party penalty applies even when the extra characters have
// hunting proficiency themselves.
inline bool wpdHuntPenaltyEvenWithProficients()
    { return true; }

// mountaineering ascends unclimbable rock by driving spikes into cracks (the
// R446 seam).
inline bool wpdMountaineerUsesSpikes()
    { return true; }

// a successful plant lore check guarantees the medicinal plant is the correct
// sort (the R479 seam).
inline bool wpdPlantLoreNoMisidentify()
    { return true; }

// ---- the riding airborne group ----

// airborne riding: a rider can drop onto his mount from no more than 10 feet
// above it.
inline int wpdAirborneDropMaxFt()
    { return 10; }

// airborne riding: spurring adds 1 inch to the flying movement rate.
inline int wpdAirborneSpurRateIn()
    { return 1; }

// the spur lasts at most four consecutive turns.
inline int wpdAirborneSpurMaxTurns()
    { return 4; }

// after a failed initial spur check, no retry for at least three turns.
inline int wpdAirborneSpurFailWaitTurns()
    { return 3; }

// a fatigued mount slows to 2/3 of its normal maximum rate (numerator).
inline int wpdAirborneSpurFatigueNum()
    { return 2; }

// the fatigued mount fraction denominator.
inline int wpdAirborneSpurFatigueDen()
    { return 3; }

// the fatigued mount must land and rest at least two turns.
inline int wpdAirborneSpurRestTurns()
    { return 2; }

// the fatigued mount performs as if one Maneuverability Class worse.
inline int wpdAirborneMCFatigueDrop()
    { return 1; }

// airborne riding is selected per flying-mount category and may be taken more
// than once.
inline bool wpdAirbornePerCategorySelection()
    { return true; }

// the airborne drop feat fails in armor heavier than leather - falling damage
// and a panicked mount.
inline bool wpdAirborneDropArmorBar()
    { return true; }

// getting the mount airborne in the same segment as the landing requires a
// successful check.
inline bool wpdAirborneSameSegmentAirborneCheck()
    { return true; }

// dropping onto a hovering mount requires a successful check.
inline bool wpdAirborneHoverDropCheck()
    { return true; }

// the spur requires a check at the beginning of each turn.
inline bool wpdAirborneSpurCheckEachTurn()
    { return true; }

// four consecutive successful spur turns also slow and degrade the mount
// until it lands and rests.
inline bool wpdAirborneSpurFourTurnsFatigue()
    { return true; }

// the knees-guidance feat leaves the hands free; damage forces a check.
inline bool wpdAirborneKneesHandsFree()
    { return true; }

// ---- the riding land-based group ----

// land-based riding: no check needed below a 3-foot obstacle.
inline int wpdLandJumpNoCheckObstacleFt()
    { return 3; }

// no check needed below a 12-foot gap.
inline int wpdLandJumpNoCheckGapFt()
    { return 12; }

// a successful check urges the mount up to 7-foot obstacles.
inline int wpdLandJumpMaxObstacleFt()
    { return 7; }

// a successful check clears gaps up to 30 feet wide.
inline int wpdLandJumpMaxGapFt()
    { return 30; }

// land-based spurring adds 1 inch per round.
inline int wpdLandSpurRateIn()
    { return 1; }

// land-based spurring lasts up to four turns.
inline int wpdLandSpurMaxTurns()
    { return 4; }

// after a failed initial land spur check, no retry for three turns.
inline int wpdLandSpurFailWaitTurns()
    { return 3; }

// a failed second land spur check: the rider must dismount and lead the
// animal for a turn.
inline int wpdLandSpurFailWalkTurns()
    { return 1; }

// failing the knees-guidance damage check causes a fall with 1d6 extra points
// of damage.
inline int wpdLandKneesFailExtraDie()
    { return 6; }

// the shielded position grants 6 armor class steps (10 becomes 4, 8 becomes
// 2).
inline int wpdLandShieldACSteps()
    { return 6; }

// a failed land hover-drop leaves the rider on the ground for 1-3 segments
// (low).
inline int wpdLandDropRiseSegsLo()
    { return 1; }

// the rise-segment high bound.
inline int wpdLandDropRiseSegsHi()
    { return 3; }

// an attack on the still-grounded rider is made at +2 to hit.
inline int wpdLandDropVulnerableHitMod()
    { return 2; }

// vaulting onto a still mount needs no check, even in armor.
inline bool wpdLandVaultStillNoCheck()
    { return true; }

// vaulting onto a moving mount requires a check; failure is a harmless fall.
inline bool wpdLandVaultMovingCheck()
    { return true; }

// a failed jump check balks the mount, forcing a keep-your-seat check.
inline bool wpdLandJumpBalkOnFail()
    { return true; }

// the land spur requires a check at the beginning of each turn.
inline bool wpdLandSpurCheckEachTurn()
    { return true; }

// after four turns of racing the steed must be walked by its dismounted rider
// for a turn.
inline bool wpdLandSpurAfterRaceWalk()
    { return true; }

// knees-guidance needs a check only on taking damage; failure means a fall.
inline bool wpdLandKneesDamageCheck()
    { return true; }

// the shielded position requires armor no heavier than leather.
inline bool wpdLandShieldLeatherOnly()
    { return true; }

// the shielded position allows no attacks while it lasts.
inline bool wpdLandShieldNoAttacks()
    { return true; }

// attacks that would have struck the shielded rider hit the mount instead.
inline bool wpdLandShieldMountTakesHits()
    { return true; }

// the shielded position works even at full mount speed, with no check.
inline bool wpdLandShieldFullSpeed()
    { return true; }

// ---- the riding shared hover-drop group ----

// the hover-drop feat: leap from 10 feet or less and melee anyone within 10
// feet of the landing.
inline int wpdDropMeleeFt()
    { return 10; }

// the hover-drop check takes a +4 modifier.
inline int wpdDropMod()
    { return 4; }

// a failed hover-drop causes 1d3 points of damage.
inline int wpdDropFailDmgDie()
    { return 3; }

// a failed hover-drop leaves a -4 armor class penalty for the round.
inline int wpdDropFailACPen()
    { return 4; }

// ---- the rope use group ----

// escaping rope bonds with hands tied in front: +3 to the check.
inline int wpdRopeEscapeFrontMod()
    { return 3; }

// hands tied behind the back: +6 to the check.
inline int wpdRopeEscapeBehindMod()
    { return 6; }

// rope use grants +2 to hit with a lasso.
inline int wpdRopeLassoHitMod()
    { return 2; }

// rope use grants a 10 percent bonus on climbing checks with a rope.
inline int wpdRopeClimbBonusPct()
    { return 10; }

// rope use erects or takes down a rope shelter in half the time.
inline bool wpdRopeShelterHalfTime()
    { return true; }

// a rope-user shelter is half as likely to suffer from inclement weather.
inline bool wpdRopeShelterHalfWeather()
    { return true; }

// the climbing bonus includes belaying companions (the R440/R443 seam).
inline bool wpdRopeClimbBonusIncludesBelay()
    { return true; }

// ---- the running group ----

// sprinting: twice the normal maximum movement rate.
inline int wpdRunSprintMult()
    { return 2; }

// the sprint lasts five rounds.
inline int wpdRunSprintRounds()
    { return 5; }

// the alternative sprint: one and one-half times normal (3/2, rounded up).
inline int wpdRunSprintAltNum()
    { return 3; }

// the alternative sprint denominator.
inline int wpdRunSprintAltDen()
    { return 2; }

// the alternative sprint lasts one turn.
inline int wpdRunSprintAltTurns()
    { return 1; }

// extended sprinting: each check after the first takes a cumulative +3 (+3,
// +6, +9...).
inline int wpdRunSprintExtModPerRound()
    { return 3; }

// stopping a sprint before fatigue: normal rate for two turns, then sprint
// again.
inline int wpdRunStopFreshAgainTurns()
    { return 2; }

// at half the normal rate, sprint again after one turn.
inline int wpdRunHalfSpeedAgainTurns()
    { return 1; }

// distance running: eight turns of exertion are offset by one turn of rest.
inline int wpdRunRestExampleExertTurns()
    { return 8; }

// twelve turns of long-distance running require a Constitution check.
inline int wpdRunCheckEveryTurns()
    { return 12; }

// a successful check covers ten more turns before the next one.
inline int wpdRunCheckNextAfterTurns()
    { return 10; }

// sprinting requires no encumbrance and armor no heavier than leather.
inline bool wpdRunSprintEncumbranceBar()
    { return true; }

// one failed extended-sprint check fatigues the character; a second failure
// exhausts.
inline bool wpdRunSprintOneFailedIsFatigue()
    { return true; }

// stopping a sprint while fatigued keeps the fatigue; exhaustion forces an
// immediate stop.
inline bool wpdRunStopFatigueStays()
    { return true; }

// distance running doubles or halves every fatigue time limit in favor of the
// character.
inline bool wpdRunDistanceFatigueFavors()
    { return true; }

// any other strenuous activity mid-run negates the distance benefits and
// restarts the standard clock.
inline bool wpdRunDistanceNoMidRunStrenuous()
    { return true; }

// ---- the survival group ----

// cold survival: the effective temperature reads 20 degrees warmer.
inline int wpdSurvColdEffShift()
    { return 20; }

// cold survival applies only at effective temperatures of 30 degrees or
// lower.
inline int wpdSurvColdAppliesAtOrBelow()
    { return 30; }

// heat survival: the effective temperature reads 20 degrees cooler.
inline int wpdSurvHeatEffShift()
    { return 20; }

// heat survival applies only at effective temperatures of 80 degrees or
// higher.
inline int wpdSurvHeatAppliesAtOrAbove()
    { return 80; }

// desert survival doubles the daily water-hole location chance.
inline bool wpdSurvDesertWaterHoleDoubled()
    { return true; }

// desert survival locates a quantity of edible plants in half the normal
// time.
inline bool wpdSurvDesertForageHalfTime()
    { return true; }

// desert survival conserves the water supply - longer stretchs between finds,
// not longer without water.
inline bool wpdSurvDesertConserveSupply()
    { return true; }

// a character without swimming proficiency cannot swim at all - the R450
// seam.
inline bool wpdSwimCannotWithoutProf()
    { return true; }

// the nonproficient can still hold breath and float in the right
// circumstances.
inline bool wpdSwimHoldBreathStillWorks()
    { return true; }

// ---- the tracking and weather sense group ----

// tracking: 5 percent per level of the character.
inline int wpdTrackBasePctPerLevel()
    { return 5; }

// tracking: plus an additional 5 percent.
inline int wpdTrackBaseBonusPct()
    { return 5; }

// the tracking chance caps at 55 percent - half the ranger base (the UA p. 21
// seam).
inline int wpdTrackMaxPct()
    { return 55; }

// weather sense reads the coming six hours.
inline int wpdWeatherSenseHours()
    { return 6; }

// the first weather sense attempt each day is free.
inline int wpdWeatherSenseFreePerDay()
    { return 1; }

// each attempt beyond the first takes a cumulative +2.
inline int wpdWeatherSenseRepeatMod()
    { return 2; }

// a failed weather sense check auto-fails every check in the next 12 hours.
inline int wpdWeatherSenseFailLockoutHours()
    { return 12; }

// a nonproficient tracker has a 0 percent base chance, salvageable only by
// positive modifiers.
inline bool wpdTrackNonprofZeroBase()
    { return true; }

// the DM always rolls weather sense checks and need not reveal the result.
inline bool wpdWeatherSenseSecretRoll()
    { return true; }

// a successful weather sense check yields at least one generally true fact
// about the coming six hours.
inline bool wpdWeatherSenseGeneralFact()
    { return true; }

// a failed weather sense check yields nothing, or at the DM discretion
// something incorrect.
inline bool wpdWeatherSenseFailQuietOrWrong()
    { return true; }

// obvious impending weather gets no check - the DM just describes what anyone
// can see.
inline bool wpdWeatherSenseObviousNoCheck()
    { return true; }

}   // namespace rules
