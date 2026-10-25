    // ---- R720 OA monsters Hu Hsien audit ----
    // OA round one hundred seven (capture pp. 269-272): the Chapter 12
    // monster roster - the hu hsien box, the fox spirit, the ikiryo, and the
    // jishin mushi riding one flip, single-pass pins per the Chapter 9
    // provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dkhHuAC() != 7
            || dkhHuMove() != 15
            || dkhHuHD() != 6
            || dkhHuLairPct() != 10
            || dkhHuAttackCount() != 1
            || dkhHuDmgMin() != 1
            || dkhHuDmgMax() != 6
            || dkhHuMRPct() != 50
            || dkhHuXPBase() != 1150
            || dkhHuXPPerHP() != 6
            || dkhHuFormsCount() != 2
            || dkhHuCharisma() != 18
            || dkhHuComeliness() != 25
            || dkhHuWeaponPlusRequired() != 3
            || dkhHuRegenPerHour() != 2
            || dkhHuAtWillCount() != 12
            || dkhHuAtWillPerRound() != 1
            || dkhHuDailyCount() != 3
            || dkhHuWeeklyUses() != 3
            || dkhHuWeeklyPowersCount() != 2
            || dkhHuDrainLevelsPerDay() != 1
            || dkhIkAppear() != 1
            || dkhIkAttackCount() != 1
            || dkhIkPsionicMin() != 200
            || dkhIkPsionicMax() != 260
            || dkhIkAttackModesCount() != 4
            || dkhIkDefenseModesCount() != 3
            || dkhIkXPBase() != 3500
            || dkhIkDispelEvilHours() != 24
            || dkhIkDrainPerDay() != 1
            || dkhIkRecoveryPerDay() != 1
            || dkhIkAbilityScoreCount() != 6
            || dkhJmAppearMin() != 1
            || dkhJmAppearMax() != 3
            || dkhJmAC() != 3
            || dkhJmMoveWalk() != 9
            || dkhJmMoveFly() != 13
            || dkhJmHD() != 5
            || dkhJmHDPlus() != 4
            || dkhJmAttackCount() != 1
            || dkhJmDmgMin() != 2
            || dkhJmDmgMax() != 16
            || dkhJmXPBase() != 275
            || dkhJmXPPerHP() != 6
            || dkhJmSizeMinFeet() != 8
            || dkhJmSizeMaxFeet() != 10
            || dkhJmTremorRoundOneRadius() != 5
            || dkhJmTremorRoundTwoRadius() != 10
            || dkhJmTremorRoundThreeRadius() != 15
            || dkhJmTremorRoundThreeDamageRadius() != 5
            || dkhJmTremorRoundThreeDmgDice() != 1
            || dkhJmTremorRoundThreeDmgSides() != 6
            || dkhJmTremorRoundFourRadius() != 20
            || dkhJmTremorRoundFourDamageRadius() != 10
            || dkhJmTremorRoundFiveRadius() != 25
            || dkhJmTremorRoundFiveDamageRadius() != 15
            || dkhJmTremorRoundFiveCrackRadius() != 5
            || dkhJmTremorRoundSixRadius() != 30
            || dkhJmTremorRoundSixDamageRadius() != 20
            || dkhJmTremorRoundSixEarthquakeRadius() != 10
            || dkhJmIchorTaelPerFlask() != 2
            || !dkhHuFrequencyRare()
            || !dkhHuTreasureIST()
            || !dkhHuDamageByWeaponType()
            || !dkhHuSpecialAttacksSeeBelow()
            || !dkhHuSpecialDefensesSeeBelow()
            || !dkhHuIntelligenceGenius()
            || !dkhHuAlignmentChaoticEvil()
            || !dkhHuSizeMedium()
            || !dkhHuPsionicNil()
            || !dkhHuLevelVII()
            || !dkhHuShapeshiftingFoxes()
            || !dkhHuSupernaturalOrigin()
            || !dkhHuHengeyokaiKin()
            || !dkhHuFoxFormUpright()
            || !dkhHuHumanMaidenForm()
            || !dkhHuTailNeverChanges()
            || !dkhHuConcealsTailUnderRobes()
            || !dkhHuInvisible()
            || !dkhHuPolymorphSelf()
            || !dkhHuDisguise()
            || !dkhHuChameleon()
            || !dkhHuKnowHistory()
            || !dkhHuHypnotism()
            || !dkhHuReadMagic()
            || !dkhHuComprehendLanguages()
            || !dkhHuVentriloquism()
            || !dkhHuApparition()
            || !dkhHuESP()
            || !dkhHuHypnoticPattern()
            || !dkhHuPossess()
            || !dkhHuServantHorde()
            || !dkhHuMajorCreation()
            || !dkhHuReward()
            || !dkhHuAncientCurse()
            || !dkhHuComelinessFascination()
            || !dkhHuImmuneToFire()
            || !dkhHuHalfColdDamage()
            || !dkhHuDoubleElectricalDamage()
            || !dkhHuFearsThunderstorms()
            || !dkhHuThunderGodPunishment()
            || !dkhHuDrainsLifeForce()
            || !dkhHuHumanFormSnare()
            || !dkhHuVictimUnaware()
            || !dkhHuSavedOnlyByOthers()
            || !dkhHuNotTotallyCruel()
            || !dkhHuRewardsHelpers()
            || !dkhHuAttractedToScholars()
            || !dkhHuDeviousTricks()
            || !dkhHuFondOfWine()
            || !dkhHuRevertsWhenIntoxicated()
            || !dkhHuLairOnVillageEdge()
            || !dkhHuAbandonedHouseIllusion()
            || !dkhHuFoxDenMansion()
            || !dkhHuGrandHallFloorboards()
            || !dkhIkFrequencyVeryRare()
            || !dkhIkACNil()
            || !dkhIkMoveNil()
            || !dkhIkHDNil()
            || !dkhIkLairNil()
            || !dkhIkTreasureNil()
            || !dkhIkDamageNil()
            || !dkhIkSpecialAttackAbilityDrain()
            || !dkhIkSpecialDefensesSeeBelow()
            || !dkhIkMRSeeBelow()
            || !dkhIkIntelligenceVery()
            || !dkhIkAlignmentChaoticEvil()
            || !dkhIkSizeNil()
            || !dkhIkLevelVIII()
            || !dkhIkAttackModesBCDE()
            || !dkhIkDefenseModesFGH()
            || !dkhIkProjectionOfEvilThoughts()
            || !dkhIkBornOfHateOrJealousy()
            || !dkhIkSourceUnaware()
            || !dkhIkWillOfItsOwn()
            || !dkhIkPsychicPresence()
            || !dkhIkHiddenFromDetection()
            || !dkhIkRevealedByDetectEvil()
            || !dkhIkRevealedByDetectHarmony()
            || !dkhIkRevealedByTrueSight()
            || !dkhIkHedgedByProtection()
            || !dkhIkBlindedByInvisibilityToSpirits()
            || !dkhIkDrivenOffByDispelEvil()
            || !dkhIkFormedBySummonSpirit()
            || !dkhIkBanishedByExorcism()
            || !dkhIkVanishesOnConfrontation()
            || !dkhIkStaysUntilDestroyed()
            || !dkhIkDrainsEveryAbilityScore()
            || !dkhIkDisturbedAndRestless()
            || !dkhIkDiesAtZeroAbility()
            || !dkhIkNoRecoveryUntilDestroyed()
            || !dkhIkRecoversOnePerDay()
            || !dkhIkMayAttackOrSpring()
            || !dkhIkSpringsFromResentment()
            || !dkhIkNeverConsciouslySummoned()
            || !dkhIkNeverForTheGood()
            || !dkhJmFrequencyVeryRare()
            || !dkhJmLairNil()
            || !dkhJmTreasureNil()
            || !dkhJmSpecialAttackTremor()
            || !dkhJmSpecialDefensesNil()
            || !dkhJmMRStandard()
            || !dkhJmIntelligenceAnimal()
            || !dkhJmAlignmentNeutral()
            || !dkhJmSizeLarge()
            || !dkhJmPsionicNil()
            || !dkhJmLevelV()
            || !dkhJmEarthquakeBeetleName()
            || !dkhJmGiantBeetleSpecies()
            || !dkhJmBlueGreenColor()
            || !dkhJmHardCarapaceSmallWings()
            || !dkhJmTemperateForests()
            || !dkhJmMeatDiet()
            || !dkhJmOxenScentAttraction()
            || !dkhJmAttacksOxenInFields()
            || !dkhJmMandiblesGraspAndDrag()
            || !dkhJmSlipFreeEasily()
            || !dkhJmKnockdownSaveVsBreath()
            || !dkhJmThrownViolentlyLoseAttack()
            || !dkhJmCracksAppear()
            || !dkhJmEarthquakeAtRoundSix()
            || !dkhJmTakesToAir()
            || !dkhJmTremorGrowsWithBlows()
            || !dkhJmIchorPrizedByIncenseMakers()
        )
            ++bad;
        // the hu hsien stat block - healthy values, each condition false
    if (dkhHuAC() != 7
            || dkhHuMove() != 15
            || dkhHuHD() != 6
            || dkhHuLairPct() != 10
            || dkhHuFrequencyRare() != 1
            || dkhHuTreasureIST() != 1
            || dkhHuAttackCount() != 1
            || dkhHuDmgMin() != 1
            || dkhHuDmgMax() != 6
            || dkhHuDamageByWeaponType() != 1
            || dkhHuSpecialAttacksSeeBelow() != 1
            || dkhHuSpecialDefensesSeeBelow() != 1
            || dkhHuMRPct() != 50
            || dkhHuIntelligenceGenius() != 1
            || dkhHuAlignmentChaoticEvil() != 1
            || dkhHuSizeMedium() != 1
            || dkhHuPsionicNil() != 1
            || dkhHuLevelVII() != 1
            || dkhHuXPBase() != 1150
            || dkhHuXPPerHP() != 6
        )
            ++bad;
        // the hu hsien fox forms - healthy values, each condition false
    if (dkhHuShapeshiftingFoxes() != 1
            || dkhHuSupernaturalOrigin() != 1
            || dkhHuHengeyokaiKin() != 1
            || dkhHuFormsCount() != 2
            || dkhHuFoxFormUpright() != 1
            || dkhHuHumanMaidenForm() != 1
            || dkhHuCharisma() != 18
            || dkhHuComeliness() != 25
            || dkhHuTailNeverChanges() != 1
            || dkhHuConcealsTailUnderRobes() != 1
            || dkhHuWeaponPlusRequired() != 3
            || dkhHuRegenPerHour() != 2
        )
            ++bad;
        // the hu hsien power roster - healthy values, each condition false
    if (dkhHuAtWillCount() != 12
            || dkhHuAtWillPerRound() != 1
            || dkhHuInvisible() != 1
            || dkhHuPolymorphSelf() != 1
            || dkhHuDisguise() != 1
            || dkhHuChameleon() != 1
            || dkhHuKnowHistory() != 1
            || dkhHuHypnotism() != 1
            || dkhHuReadMagic() != 1
            || dkhHuComprehendLanguages() != 1
            || dkhHuVentriloquism() != 1
            || dkhHuApparition() != 1
            || dkhHuESP() != 1
            || dkhHuHypnoticPattern() != 1
            || dkhHuDailyCount() != 3
            || dkhHuPossess() != 1
            || dkhHuServantHorde() != 1
            || dkhHuMajorCreation() != 1
            || dkhHuWeeklyUses() != 3
            || dkhHuWeeklyPowersCount() != 2
            || dkhHuReward() != 1
            || dkhHuAncientCurse() != 1
            || dkhHuComelinessFascination() != 1
        )
            ++bad;
        // the hu hsien defenses - healthy values, each condition false
    if (dkhHuImmuneToFire() != 1
            || dkhHuHalfColdDamage() != 1
            || dkhHuDoubleElectricalDamage() != 1
            || dkhHuFearsThunderstorms() != 1
            || dkhHuThunderGodPunishment() != 1
        )
            ++bad;
        // the hu hsien life drain - healthy values, each condition false
    if (dkhHuDrainsLifeForce() != 1
            || dkhHuHumanFormSnare() != 1
            || dkhHuDrainLevelsPerDay() != 1
            || dkhHuVictimUnaware() != 1
            || dkhHuSavedOnlyByOthers() != 1
        )
            ++bad;
        // the hu hsien character and lair - healthy values, each condition
        // false
    if (dkhHuNotTotallyCruel() != 1
            || dkhHuRewardsHelpers() != 1
            || dkhHuAttractedToScholars() != 1
            || dkhHuDeviousTricks() != 1
            || dkhHuFondOfWine() != 1
            || dkhHuRevertsWhenIntoxicated() != 1
            || dkhHuLairOnVillageEdge() != 1
            || dkhHuAbandonedHouseIllusion() != 1
            || dkhHuFoxDenMansion() != 1
            || dkhHuGrandHallFloorboards() != 1
        )
            ++bad;
        // the ikiryo stat block - healthy values, each condition false
    if (dkhIkFrequencyVeryRare() != 1
            || dkhIkAppear() != 1
            || dkhIkACNil() != 1
            || dkhIkMoveNil() != 1
            || dkhIkHDNil() != 1
            || dkhIkLairNil() != 1
            || dkhIkTreasureNil() != 1
            || dkhIkAttackCount() != 1
            || dkhIkDamageNil() != 1
            || dkhIkSpecialAttackAbilityDrain() != 1
            || dkhIkSpecialDefensesSeeBelow() != 1
            || dkhIkMRSeeBelow() != 1
            || dkhIkIntelligenceVery() != 1
            || dkhIkAlignmentChaoticEvil() != 1
            || dkhIkSizeNil() != 1
            || dkhIkPsionicMin() != 200
            || dkhIkPsionicMax() != 260
            || dkhIkAttackModesBCDE() != 1
            || dkhIkAttackModesCount() != 4
            || dkhIkDefenseModesFGH() != 1
            || dkhIkDefenseModesCount() != 3
            || dkhIkLevelVIII() != 1
            || dkhIkXPBase() != 3500
        )
            ++bad;
        // the ikiryo nature - healthy values, each condition false
    if (dkhIkProjectionOfEvilThoughts() != 1
            || dkhIkBornOfHateOrJealousy() != 1
            || dkhIkSourceUnaware() != 1
            || dkhIkWillOfItsOwn() != 1
            || dkhIkPsychicPresence() != 1
            || dkhIkHiddenFromDetection() != 1
            || dkhIkRevealedByDetectEvil() != 1
            || dkhIkRevealedByDetectHarmony() != 1
            || dkhIkRevealedByTrueSight() != 1
            || dkhIkHedgedByProtection() != 1
            || dkhIkBlindedByInvisibilityToSpirits() != 1
            || dkhIkDrivenOffByDispelEvil() != 1
            || dkhIkDispelEvilHours() != 24
            || dkhIkFormedBySummonSpirit() != 1
            || dkhIkBanishedByExorcism() != 1
            || dkhIkVanishesOnConfrontation() != 1
        )
            ++bad;
        // the ikiryo drain - healthy values, each condition false
    if (dkhIkStaysUntilDestroyed() != 1
            || dkhIkDrainsEveryAbilityScore() != 1
            || dkhIkAbilityScoreCount() != 6
            || dkhIkDrainPerDay() != 1
            || dkhIkDisturbedAndRestless() != 1
            || dkhIkDiesAtZeroAbility() != 1
            || dkhIkNoRecoveryUntilDestroyed() != 1
            || dkhIkRecoveryPerDay() != 1
            || dkhIkRecoversOnePerDay() != 1
        )
            ++bad;
        // the ikiryo dm guidance - healthy values, each condition false
    if (dkhIkMayAttackOrSpring() != 1
            || dkhIkSpringsFromResentment() != 1
            || dkhIkNeverConsciouslySummoned() != 1
            || dkhIkNeverForTheGood() != 1
        )
            ++bad;
        // the jishin mushi stat block - healthy values, each condition false
    if (dkhJmFrequencyVeryRare() != 1
            || dkhJmAppearMin() != 1
            || dkhJmAppearMax() != 3
            || dkhJmAC() != 3
            || dkhJmMoveWalk() != 9
            || dkhJmMoveFly() != 13
            || dkhJmHD() != 5
            || dkhJmHDPlus() != 4
            || dkhJmLairNil() != 1
            || dkhJmTreasureNil() != 1
            || dkhJmAttackCount() != 1
            || dkhJmDmgMin() != 2
            || dkhJmDmgMax() != 16
            || dkhJmSpecialAttackTremor() != 1
            || dkhJmSpecialDefensesNil() != 1
            || dkhJmMRStandard() != 1
            || dkhJmIntelligenceAnimal() != 1
            || dkhJmAlignmentNeutral() != 1
            || dkhJmSizeLarge() != 1
            || dkhJmSizeMinFeet() != 8
            || dkhJmSizeMaxFeet() != 10
            || dkhJmPsionicNil() != 1
            || dkhJmLevelV() != 1
            || dkhJmXPBase() != 275
            || dkhJmXPPerHP() != 6
        )
            ++bad;
        // the earthquake beetle - healthy values, each condition false
    if (dkhJmEarthquakeBeetleName() != 1
            || dkhJmGiantBeetleSpecies() != 1
            || dkhJmBlueGreenColor() != 1
            || dkhJmHardCarapaceSmallWings() != 1
            || dkhJmTemperateForests() != 1
            || dkhJmMeatDiet() != 1
            || dkhJmOxenScentAttraction() != 1
            || dkhJmAttacksOxenInFields() != 1
            || dkhJmMandiblesGraspAndDrag() != 1
            || dkhJmSlipFreeEasily() != 1
        )
            ++bad;
        // the tremor rounds - healthy values, each condition false
    if (dkhJmTremorGrowsWithBlows() != 1
            || dkhJmKnockdownSaveVsBreath() != 1
            || dkhJmTremorRoundOneRadius() != 5
            || dkhJmTremorRoundTwoRadius() != 10
            || dkhJmTremorRoundThreeRadius() != 15
            || dkhJmThrownViolentlyLoseAttack() != 1
            || dkhJmTremorRoundThreeDamageRadius() != 5
            || dkhJmTremorRoundThreeDmgDice() != 1
            || dkhJmTremorRoundThreeDmgSides() != 6
            || dkhJmTremorRoundFourRadius() != 20
            || dkhJmTremorRoundFourDamageRadius() != 10
            || dkhJmTremorRoundFiveRadius() != 25
            || dkhJmTremorRoundFiveDamageRadius() != 15
            || dkhJmCracksAppear() != 1
            || dkhJmTremorRoundFiveCrackRadius() != 5
            || dkhJmTremorRoundSixRadius() != 30
            || dkhJmTremorRoundSixDamageRadius() != 20
            || dkhJmEarthquakeAtRoundSix() != 1
            || dkhJmTremorRoundSixEarthquakeRadius() != 10
            || dkhJmTakesToAir() != 1
        )
            ++bad;
        // the ichor - healthy values, each condition false
    if (dkhJmIchorPrizedByIncenseMakers() != 1
            || dkhJmIchorTaelPerFlask() != 2
        )
            ++bad;
        printf("R720 OA monsters Hu Hsien audit: bad %d\n", bad);
        if (bad) return 1;
    }
