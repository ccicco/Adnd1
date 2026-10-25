    // ---- R498 WSG proficiencies prose audit ----
    // The wilderness proficiencies prose, printed pp. 11-17 (pdf 12-18): the
    // DSG-system frame with the dual-environment ruling, the choosing-skills
    // rules (the player chooses, the background logic, the DM approval) and
    // all twenty-five descriptions - alertness (1-in-6 surprise), animal
    // handling (20 percent nonproficient), animal lore (the
    // 4-or-less/5-or-more failure split), blind-fighting (the halved
    // penalties), boating, charioteering, direction sense (+4/+2 darkness,
    // the 90-degree error), endurance, fire-building, fishing, foraging,
    // healing (the emergency 1d3, the poison +2 package, the disease
    // step-down), hunting (the party ladder 1/3/6/10/15), mountaineering,
    // plant lore, the riding feats (airborne and land-based), rope use (+3/+6
    // escape), running (the sprint and distance packages), the survival trio
    // (the 20-degree shifts), swimming, tracking (5 per level plus 5, capped
    // 55) and weather sense (the six-hour read).
    {
        using namespace rules;
        int bad = 0;
    if (wpdPrintedLo() != 11
            || wpdPrintedHi() != 17
            || wpdPdfLo() != 12
            || wpdPdfHi() != 18
            || wpdDescriptionCount() != 25
            || wpdAlertSurpriseReductionIn6() != 1
            || wpdAnimalHandlingNonprofPct() != 20
            || wpdAnimalLoreNoInfoFailBy() != 4
            || wpdAnimalLoreWrongInfoFailBy() != 5
            || wpdBlindTotalDarkPen() != 2
            || wpdBlindTotalDarkBasePen() != 4
            || wpdBlindNaturalDarkPen() != 1
            || wpdBlindNaturalDarkBasePen() != 3
            || wpdDirSenseTotalDarkMod() != 4
            || wpdDirSensePartialDarkMod() != 2
            || wpdDirSenseErrorDeg() != 90
            || wpdEnduranceStrenuousMult() != 2
            || wpdHealingEmergencyDie() != 3
            || wpdHealingWindowRounds() != 1
            || wpdHealingTravelHpPerDay() != 1
            || wpdHealingRestHpPerDay() != 2
            || wpdHealingPoisonSaveBonus() != 2
            || wpdHealingPoisonRestTurns() != 1
            || wpdHealingPoisonAidRounds() != 5
            || wpdHealingDiseaseWindowTurns() != 3
            || wpdHealingAidPerDay() != 2
            || wpdHealingMissRevertConsecutive() != 2
            || wpdHealingMissRevertTotal() != 3
            || wpdHuntPartyMod1() != 1
            || wpdHuntPartyMod2() != 3
            || wpdHuntPartyMod3() != 6
            || wpdHuntPartyMod4() != 10
            || wpdHuntPartyMod5() != 15
            || wpdHuntAutoFailPartySize() != 6
            || wpdAirborneDropMaxFt() != 10
            || wpdAirborneSpurRateIn() != 1
            || wpdAirborneSpurMaxTurns() != 4
            || wpdAirborneSpurFailWaitTurns() != 3
            || wpdAirborneSpurFatigueNum() != 2
            || wpdAirborneSpurFatigueDen() != 3
            || wpdAirborneSpurRestTurns() != 2
            || wpdAirborneMCFatigueDrop() != 1
            || wpdDropMeleeFt() != 10
            || wpdDropMod() != 4
            || wpdDropFailDmgDie() != 3
            || wpdDropFailACPen() != 4
            || wpdLandJumpNoCheckObstacleFt() != 3
            || wpdLandJumpNoCheckGapFt() != 12
            || wpdLandJumpMaxObstacleFt() != 7
            || wpdLandJumpMaxGapFt() != 30
            || wpdLandSpurRateIn() != 1
            || wpdLandSpurMaxTurns() != 4
            || wpdLandSpurFailWaitTurns() != 3
            || wpdLandSpurFailWalkTurns() != 1
            || wpdLandKneesFailExtraDie() != 6
            || wpdLandShieldACSteps() != 6
            || wpdLandDropRiseSegsLo() != 1
            || wpdLandDropRiseSegsHi() != 3
            || wpdLandDropVulnerableHitMod() != 2
            || wpdRopeEscapeFrontMod() != 3
            || wpdRopeEscapeBehindMod() != 6
            || wpdRopeLassoHitMod() != 2
            || wpdRopeClimbBonusPct() != 10
            || wpdRunSprintMult() != 2
            || wpdRunSprintRounds() != 5
            || wpdRunSprintAltNum() != 3
            || wpdRunSprintAltDen() != 2
            || wpdRunSprintAltTurns() != 1
            || wpdRunSprintExtModPerRound() != 3
            || wpdRunStopFreshAgainTurns() != 2
            || wpdRunHalfSpeedAgainTurns() != 1
            || wpdRunRestExampleExertTurns() != 8
            || wpdRunCheckEveryTurns() != 12
            || wpdRunCheckNextAfterTurns() != 10
            || wpdSurvColdEffShift() != 20
            || wpdSurvColdAppliesAtOrBelow() != 30
            || wpdSurvHeatEffShift() != 20
            || wpdSurvHeatAppliesAtOrAbove() != 80
            || wpdTrackBasePctPerLevel() != 5
            || wpdTrackBaseBonusPct() != 5
            || wpdTrackMaxPct() != 55
            || wpdWeatherSenseHours() != 6
            || wpdWeatherSenseFreePerDay() != 1
            || wpdWeatherSenseRepeatMod() != 2
            || wpdWeatherSenseFailLockoutHours() != 12
            || !wpdSystemMatchesDSG()
            || !wpdDualEnvironmentShared()
            || !wpdUndergroundOnlyExists()
            || !wpdPlantLoreWildernessOnly()
            || !wpdSelectionPlayerChooses()
            || !wpdBackgroundLogicRule()
            || !wpdLevelingStillLogical()
            || !wpdDirectionSenseEasyJustify()
            || !wpdDMApprovalRequired()
            || !wpdDelayAllowedNotDuringAdventure()
            || !wpdAnimalHandlingCalmsOnCheck()
            || !wpdBlindNoACPenalty()
            || !wpdBlindRetainsAbilities()
            || !wpdBlindAdverseChanceHalf()
            || !wpdBlindShortRangeOnly()
            || !wpdBoatingFastestRate()
            || !wpdBoatingReducesCapsize()
            || !wpdCharioteerFasterRate()
            || !wpdCharioteerNoImpossibleTerrain()
            || !wpdDirSenseSecretRoll()
            || !wpdDirSenseNatural20Opposite()
            || !wpdDirSenseMultiChecker()
            || !wpdEnduranceNoFoodWaterExtension()
            || !wpdFireBuildNoFlintOnCheck()
            || !wpdFireBuildHalfTimeWithKit()
            || !wpdFishingBetterCatch()
            || !wpdForagingTwiceOrHalfTime()
            || !wpdHealingCapAtWound()
            || !wpdHealingOnePatientPerDay()
            || !wpdHealingContinuousNoCheck()
            || !wpdHealingPoisonNoCheckNeeded()
            || !wpdHealingPoisonMissResaves()
            || !wpdHealingDiseaseStepDown()
            || !wpdHealingMildHalfDuration()
            || !wpdHuntPenaltyEvenWithProficients()
            || !wpdMountaineerUsesSpikes()
            || !wpdPlantLoreNoMisidentify()
            || !wpdAirbornePerCategorySelection()
            || !wpdAirborneDropArmorBar()
            || !wpdAirborneSameSegmentAirborneCheck()
            || !wpdAirborneHoverDropCheck()
            || !wpdAirborneSpurCheckEachTurn()
            || !wpdAirborneSpurFourTurnsFatigue()
            || !wpdAirborneKneesHandsFree()
            || !wpdLandVaultStillNoCheck()
            || !wpdLandVaultMovingCheck()
            || !wpdLandJumpBalkOnFail()
            || !wpdLandSpurCheckEachTurn()
            || !wpdLandSpurAfterRaceWalk()
            || !wpdLandKneesDamageCheck()
            || !wpdLandShieldLeatherOnly()
            || !wpdLandShieldNoAttacks()
            || !wpdLandShieldMountTakesHits()
            || !wpdLandShieldFullSpeed()
            || !wpdRopeShelterHalfTime()
            || !wpdRopeShelterHalfWeather()
            || !wpdRopeClimbBonusIncludesBelay()
            || !wpdRunSprintEncumbranceBar()
            || !wpdRunSprintOneFailedIsFatigue()
            || !wpdRunStopFatigueStays()
            || !wpdRunDistanceFatigueFavors()
            || !wpdRunDistanceNoMidRunStrenuous()
            || !wpdSurvDesertWaterHoleDoubled()
            || !wpdSurvDesertForageHalfTime()
            || !wpdSurvDesertConserveSupply()
            || !wpdSwimCannotWithoutProf()
            || !wpdSwimHoldBreathStillWorks()
            || !wpdTrackNonprofZeroBase()
            || !wpdWeatherSenseSecretRoll()
            || !wpdWeatherSenseGeneralFact()
            || !wpdWeatherSenseFailQuietOrWrong()
            || !wpdWeatherSenseObviousNoCheck()
        )
            ++bad;
        // the chapter spans
    if (wpdPrintedLo() != 11
            || wpdPrintedHi() != 17
            || wpdPdfLo() != 12
            || wpdPdfHi() != 18
        )
            ++bad;
        // twenty-five descriptions matching the twenty-five pinned Table 2
        // rows
    if (wpdDescriptionCount() != 25
        )
            ++bad;
        // the blind-fighting penalties are exactly half the base penalties
    if (wpdBlindTotalDarkPen() != 2
            || wpdBlindTotalDarkBasePen() != 4
            || wpdBlindTotalDarkBasePen() != wpdBlindTotalDarkPen() * 2
            || wpdBlindNaturalDarkBasePen() != wpdBlindNaturalDarkPen() * 3
        )
            ++bad;
        // the direction sense darkness ladder: +4 total, +2 partial
    if (wpdDirSenseTotalDarkMod() != 4
            || wpdDirSensePartialDarkMod() != 2
            || wpdDirSenseTotalDarkMod() != wpdDirSensePartialDarkMod() * 2
        )
            ++bad;
        // the rope escape ladder: +3 front, +6 behind
    if (wpdRopeEscapeFrontMod() != 3
            || wpdRopeEscapeBehindMod() != 6
            || wpdRopeEscapeBehindMod() != wpdRopeEscapeFrontMod() * 2
        )
            ++bad;
        // the hunting party ladder climbs 1, 3, 6, 10, 15
    if (wpdHuntPartyMod1() != 1
            || wpdHuntPartyMod2() != 3
            || wpdHuntPartyMod3() != 6
            || wpdHuntPartyMod4() != 10
            || wpdHuntPartyMod5() != 15
        )
            ++bad;
        // six or more companions auto-fail the hunt
    if (wpdHuntAutoFailPartySize() != 6
        )
            ++bad;
        // the survival temperature bands: cold at or below 30, heat at or
        // above 80, both shifting 20 degrees
    if (wpdSurvColdEffShift() != 20
            || wpdSurvHeatEffShift() != 20
            || wpdSurvColdAppliesAtOrBelow() != 30
            || wpdSurvHeatAppliesAtOrAbove() != 80
        )
            ++bad;
        // the tracking ladder: 5 per level plus 5, capped at 55 - half a
        // ranger
    if (wpdTrackBasePctPerLevel() != 5
            || wpdTrackBaseBonusPct() != 5
            || wpdTrackMaxPct() != 55
            || wpdTrackMaxPct() != wpdTrackBasePctPerLevel() * 11
        )
            ++bad;
        // the weather sense day: one free try, +2 per extra try, 12-hour
        // lockout on failure
    if (wpdWeatherSenseHours() != 6
            || wpdWeatherSenseFreePerDay() != 1
            || wpdWeatherSenseRepeatMod() != 2
            || wpdWeatherSenseFailLockoutHours() != 12
            || wpdWeatherSenseFailLockoutHours() != wpdWeatherSenseHours() * 2
        )
            ++bad;
        // the healing recovery ladder: 1 traveling, 2 resting
    if (wpdHealingTravelHpPerDay() != 1
            || wpdHealingRestHpPerDay() != 2
            || wpdHealingRestHpPerDay() != wpdHealingTravelHpPerDay() * 2
        )
            ++bad;
        // the healing revert rule: 2 consecutive or 3 total missed sessions
    if (wpdHealingMissRevertConsecutive() != 2
            || wpdHealingMissRevertTotal() != 3
        )
            ++bad;
        // the emergency healing window and die
    if (wpdHealingWindowRounds() != 1
            || wpdHealingEmergencyDie() != 3
        )
            ++bad;
        // the poison aid package: +2 save, 1 turn rest, 5 rounds of aid
    if (wpdHealingPoisonSaveBonus() != 2
            || wpdHealingPoisonRestTurns() != 1
            || wpdHealingPoisonAidRounds() != 5
        )
            ++bad;
        // the disease window: 3 turns, aid twice per day
    if (wpdHealingDiseaseWindowTurns() != 3
            || wpdHealingAidPerDay() != 2
        )
            ++bad;
        // the sprint package: 2x for 5 rounds or 3/2 for 1 turn
    if (wpdRunSprintMult() != 2
            || wpdRunSprintRounds() != 5
            || wpdRunSprintAltNum() != 3
            || wpdRunSprintAltDen() != 2
            || wpdRunSprintAltTurns() != 1
        )
            ++bad;
        // the extended sprint climbs +3 per round
    if (wpdRunSprintExtModPerRound() != 3
            || wpdRunStopFreshAgainTurns() != 2
            || wpdRunHalfSpeedAgainTurns() != 1
        )
            ++bad;
        // the distance running example: 8 exerted vs 1 rest, a check every 12
        // then 10 turns
    if (wpdRunRestExampleExertTurns() != 8
            || wpdRunCheckEveryTurns() != 12
            || wpdRunCheckNextAfterTurns() != 10
        )
            ++bad;
        // the airborne spur: 1 inch, 4 turns, 3-turn retry wait, 2/3 fatigue,
        // 1 MC drop, 2 turns rest
    if (wpdAirborneSpurRateIn() != 1
            || wpdAirborneSpurMaxTurns() != 4
            || wpdAirborneSpurFailWaitTurns() != 3
            || wpdAirborneSpurFatigueNum() != 2
            || wpdAirborneSpurFatigueDen() != 3
            || wpdAirborneMCFatigueDrop() != 1
            || wpdAirborneSpurRestTurns() != 2
        )
            ++bad;
        // the hover-drop feat: 10 feet, +4, 1d3 damage, -4 AC
    if (wpdDropMeleeFt() != 10
            || wpdDropMod() != 4
            || wpdDropFailDmgDie() != 3
            || wpdDropFailACPen() != 4
        )
            ++bad;
        // the land jump bands: free below 3/12, maximum 7/30
    if (wpdLandJumpNoCheckObstacleFt() != 3
            || wpdLandJumpNoCheckGapFt() != 12
            || wpdLandJumpMaxObstacleFt() != 7
            || wpdLandJumpMaxGapFt() != 30
        )
            ++bad;
        // the land spur: 1 inch, 4 turns, 3-turn retry, 1 turn walk
    if (wpdLandSpurRateIn() != 1
            || wpdLandSpurMaxTurns() != 4
            || wpdLandSpurFailWaitTurns() != 3
            || wpdLandSpurFailWalkTurns() != 1
        )
            ++bad;
        // the shielded position: 6 AC steps
    if (wpdLandShieldACSteps() != 6
        )
            ++bad;
        // the failed land drop: 1-3 segments down, attacker at +2
    if (wpdLandDropRiseSegsLo() != 1
            || wpdLandDropRiseSegsHi() != 3
            || wpdLandDropVulnerableHitMod() != 2
        )
            ++bad;
        // the knees failure costs 1d6 extra
    if (wpdLandKneesFailExtraDie() != 6
        )
            ++bad;
        // the rope bonuses: +2 lasso, +10 percent climbing
    if (wpdRopeLassoHitMod() != 2
            || wpdRopeClimbBonusPct() != 10
        )
            ++bad;
        // the animal lore failure split: 4 or less silent, 5 or more wrong
    if (wpdAnimalLoreNoInfoFailBy() != 4
            || wpdAnimalLoreWrongInfoFailBy() != 5
            || wpdAnimalLoreWrongInfoFailBy() != wpdAnimalLoreNoInfoFailBy() +
            1
        )
            ++bad;
        // the alertness reduction: 1 in 6
    if (wpdAlertSurpriseReductionIn6() != 1
        )
            ++bad;
        // the animal handling nonproficient chance: 20 percent
    if (wpdAnimalHandlingNonprofPct() != 20
        )
            ++bad;
        // endurance doubles the strenuous clock only
    if (wpdEnduranceStrenuousMult() != 2
        )
            ++bad;
        // the airborne drop ceiling: 10 feet
    if (wpdAirborneDropMaxFt() != 10
        )
            ++bad;
        // wpdSystemMatchesDSG
    if (wpdSystemMatchesDSG() != 1
        )
            ++bad;
        // wpdDualEnvironmentShared
    if (wpdDualEnvironmentShared() != 1
        )
            ++bad;
        // wpdUndergroundOnlyExists
    if (wpdUndergroundOnlyExists() != 1
        )
            ++bad;
        // wpdPlantLoreWildernessOnly
    if (wpdPlantLoreWildernessOnly() != 1
        )
            ++bad;
        // wpdSelectionPlayerChooses
    if (wpdSelectionPlayerChooses() != 1
        )
            ++bad;
        // wpdBackgroundLogicRule
    if (wpdBackgroundLogicRule() != 1
        )
            ++bad;
        // wpdLevelingStillLogical
    if (wpdLevelingStillLogical() != 1
        )
            ++bad;
        // wpdDirectionSenseEasyJustify
    if (wpdDirectionSenseEasyJustify() != 1
        )
            ++bad;
        // wpdDMApprovalRequired
    if (wpdDMApprovalRequired() != 1
        )
            ++bad;
        // wpdDelayAllowedNotDuringAdventure
    if (wpdDelayAllowedNotDuringAdventure() != 1
        )
            ++bad;
        // wpdAnimalHandlingCalmsOnCheck
    if (wpdAnimalHandlingCalmsOnCheck() != 1
        )
            ++bad;
        // wpdBlindNoACPenalty
    if (wpdBlindNoACPenalty() != 1
        )
            ++bad;
        // wpdBlindRetainsAbilities
    if (wpdBlindRetainsAbilities() != 1
        )
            ++bad;
        // wpdBlindAdverseChanceHalf
    if (wpdBlindAdverseChanceHalf() != 1
        )
            ++bad;
        // wpdBlindShortRangeOnly
    if (wpdBlindShortRangeOnly() != 1
        )
            ++bad;
        // wpdBoatingFastestRate
    if (wpdBoatingFastestRate() != 1
        )
            ++bad;
        // wpdBoatingReducesCapsize
    if (wpdBoatingReducesCapsize() != 1
        )
            ++bad;
        // wpdCharioteerFasterRate
    if (wpdCharioteerFasterRate() != 1
        )
            ++bad;
        // wpdCharioteerNoImpossibleTerrain
    if (wpdCharioteerNoImpossibleTerrain() != 1
        )
            ++bad;
        // wpdDirSenseSecretRoll
    if (wpdDirSenseSecretRoll() != 1
        )
            ++bad;
        // wpdDirSenseNatural20Opposite
    if (wpdDirSenseNatural20Opposite() != 1
        )
            ++bad;
        // wpdDirSenseMultiChecker
    if (wpdDirSenseMultiChecker() != 1
        )
            ++bad;
        // wpdEnduranceNoFoodWaterExtension
    if (wpdEnduranceNoFoodWaterExtension() != 1
        )
            ++bad;
        // wpdFireBuildNoFlintOnCheck
    if (wpdFireBuildNoFlintOnCheck() != 1
        )
            ++bad;
        // wpdFireBuildHalfTimeWithKit
    if (wpdFireBuildHalfTimeWithKit() != 1
        )
            ++bad;
        // wpdFishingBetterCatch
    if (wpdFishingBetterCatch() != 1
        )
            ++bad;
        // wpdForagingTwiceOrHalfTime
    if (wpdForagingTwiceOrHalfTime() != 1
        )
            ++bad;
        // wpdHealingCapAtWound
    if (wpdHealingCapAtWound() != 1
        )
            ++bad;
        // wpdHealingOnePatientPerDay
    if (wpdHealingOnePatientPerDay() != 1
        )
            ++bad;
        // wpdHealingContinuousNoCheck
    if (wpdHealingContinuousNoCheck() != 1
        )
            ++bad;
        // wpdHealingPoisonNoCheckNeeded
    if (wpdHealingPoisonNoCheckNeeded() != 1
        )
            ++bad;
        // wpdHealingPoisonMissResaves
    if (wpdHealingPoisonMissResaves() != 1
        )
            ++bad;
        // wpdHealingDiseaseStepDown
    if (wpdHealingDiseaseStepDown() != 1
        )
            ++bad;
        // wpdHealingMildHalfDuration
    if (wpdHealingMildHalfDuration() != 1
        )
            ++bad;
        // wpdHuntPenaltyEvenWithProficients
    if (wpdHuntPenaltyEvenWithProficients() != 1
        )
            ++bad;
        // wpdMountaineerUsesSpikes
    if (wpdMountaineerUsesSpikes() != 1
        )
            ++bad;
        // wpdPlantLoreNoMisidentify
    if (wpdPlantLoreNoMisidentify() != 1
        )
            ++bad;
        // wpdAirbornePerCategorySelection
    if (wpdAirbornePerCategorySelection() != 1
        )
            ++bad;
        // wpdAirborneDropArmorBar
    if (wpdAirborneDropArmorBar() != 1
        )
            ++bad;
        // wpdAirborneSameSegmentAirborneCheck
    if (wpdAirborneSameSegmentAirborneCheck() != 1
        )
            ++bad;
        // wpdAirborneHoverDropCheck
    if (wpdAirborneHoverDropCheck() != 1
        )
            ++bad;
        // wpdAirborneSpurCheckEachTurn
    if (wpdAirborneSpurCheckEachTurn() != 1
        )
            ++bad;
        // wpdAirborneSpurFourTurnsFatigue
    if (wpdAirborneSpurFourTurnsFatigue() != 1
        )
            ++bad;
        // wpdAirborneKneesHandsFree
    if (wpdAirborneKneesHandsFree() != 1
        )
            ++bad;
        // wpdLandVaultStillNoCheck
    if (wpdLandVaultStillNoCheck() != 1
        )
            ++bad;
        // wpdLandVaultMovingCheck
    if (wpdLandVaultMovingCheck() != 1
        )
            ++bad;
        // wpdLandJumpBalkOnFail
    if (wpdLandJumpBalkOnFail() != 1
        )
            ++bad;
        // wpdLandSpurCheckEachTurn
    if (wpdLandSpurCheckEachTurn() != 1
        )
            ++bad;
        // wpdLandSpurAfterRaceWalk
    if (wpdLandSpurAfterRaceWalk() != 1
        )
            ++bad;
        // wpdLandKneesDamageCheck
    if (wpdLandKneesDamageCheck() != 1
        )
            ++bad;
        // wpdLandShieldLeatherOnly
    if (wpdLandShieldLeatherOnly() != 1
        )
            ++bad;
        // wpdLandShieldNoAttacks
    if (wpdLandShieldNoAttacks() != 1
        )
            ++bad;
        // wpdLandShieldMountTakesHits
    if (wpdLandShieldMountTakesHits() != 1
        )
            ++bad;
        // wpdLandShieldFullSpeed
    if (wpdLandShieldFullSpeed() != 1
        )
            ++bad;
        // wpdRopeShelterHalfTime
    if (wpdRopeShelterHalfTime() != 1
        )
            ++bad;
        // wpdRopeShelterHalfWeather
    if (wpdRopeShelterHalfWeather() != 1
        )
            ++bad;
        // wpdRopeClimbBonusIncludesBelay
    if (wpdRopeClimbBonusIncludesBelay() != 1
        )
            ++bad;
        // wpdRunSprintEncumbranceBar
    if (wpdRunSprintEncumbranceBar() != 1
        )
            ++bad;
        // wpdRunSprintOneFailedIsFatigue
    if (wpdRunSprintOneFailedIsFatigue() != 1
        )
            ++bad;
        // wpdRunStopFatigueStays
    if (wpdRunStopFatigueStays() != 1
        )
            ++bad;
        // wpdRunDistanceFatigueFavors
    if (wpdRunDistanceFatigueFavors() != 1
        )
            ++bad;
        // wpdRunDistanceNoMidRunStrenuous
    if (wpdRunDistanceNoMidRunStrenuous() != 1
        )
            ++bad;
        // wpdSurvDesertWaterHoleDoubled
    if (wpdSurvDesertWaterHoleDoubled() != 1
        )
            ++bad;
        // wpdSurvDesertForageHalfTime
    if (wpdSurvDesertForageHalfTime() != 1
        )
            ++bad;
        // wpdSurvDesertConserveSupply
    if (wpdSurvDesertConserveSupply() != 1
        )
            ++bad;
        // wpdSwimCannotWithoutProf
    if (wpdSwimCannotWithoutProf() != 1
        )
            ++bad;
        // wpdSwimHoldBreathStillWorks
    if (wpdSwimHoldBreathStillWorks() != 1
        )
            ++bad;
        // wpdTrackNonprofZeroBase
    if (wpdTrackNonprofZeroBase() != 1
        )
            ++bad;
        // wpdWeatherSenseSecretRoll
    if (wpdWeatherSenseSecretRoll() != 1
        )
            ++bad;
        // wpdWeatherSenseGeneralFact
    if (wpdWeatherSenseGeneralFact() != 1
        )
            ++bad;
        // wpdWeatherSenseFailQuietOrWrong
    if (wpdWeatherSenseFailQuietOrWrong() != 1
        )
            ++bad;
        // wpdWeatherSenseObviousNoCheck
    if (wpdWeatherSenseObviousNoCheck() != 1
        )
            ++bad;
        printf("R498 WSG proficiencies prose audit: bad %d\n", bad);
        if (bad) return 1;
    }
