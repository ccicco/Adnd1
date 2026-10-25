    // ---- R609 DMO high-level skills audit ----
    // DMO Chapter 7 round two of five (printed pp. 145-156): the skills
    // doctrine - the number-or-less 1d20 success roll, the Table 41 ability
    // bands (-5 at 3 or less to +5 at 18 plus), the fixed per-use drop of
    // limited-use skills, the zero-or-less lockout with unavailable
    // dependents and no ability rescue, the opposed-roll cases, the
    // slot/point cost reading, the 16 mortal ceiling no wish can lift; the
    // Table 40 roster - 33 skills in four class bands with the two blank
    // priest cost cells pinned as printed blanks; the Table 42 advancement
    // grid with its XP ladders, proficiency columns and 9+N hit points; the
    // fighter breech ladder (+1 at 21st to +4 at 30th) and intimidation (the
    // 4+1 auto-retreat, the 4+2 save, the -2 penalty, the -2 step per three
    // levels); the ranger follower/scroll/scrying powers and the paladin
    // powers including the 27th-level disease immunity; and the eleven
    // warrior skills with their ladders - the all-around 1d8-to-5d8 damage,
    // the bravery drains (-2 for captivate and hardiness, -1 for
    // frighten/challenge), the hardiness delay bands (5/10/15/20 rounds) with
    // the nine-week vampire-and-lich example, the inner focus 18-to-22 boost
    // ladder, and the sense danger subskill ladder (one at 15th to four at
    // 30th).
    {
        using namespace rules;
        int bad = 0;
    if (deySkillDieSides() != 20
            || deyMaxSkillBase() != 16
            || deyT41RowCount() != 11
            || deyT40RowCount() != 33
            || deyT40WarriorBase() != 0
            || deyT40WizardBase() != 11
            || deyT40PriestBase() != 14
            || deyT40RogueBase() != 22
            || deyWarriorThacoStopLevel() != 20
            || deyWarriorAdvLimit() != 30
            || deyWarriorPowerLevel() != 21
            || deyWarriorSkillLevel() != 10
            || deyT42RowCount() != 11
            || deyBreechStartLevel() != 21
            || deyIntimidationStartLevel() != 21
            || deyIntimidationSightYards() != 10
            || deyIntimidationAutoRetreatHd() != 4
            || deyIntimidationSaveHd() != 4
            || deyIntimidationStayPenalty() != 2
            || deyIntimidationRange() != 60
            || deyIntimidationPenaltyStep() != 3
            || deyIntimidationPenaltyIncrement() != 2
            || deyRangerFollowerLevel1() != 21
            || deyRangerFollowerLevel2() != 26
            || deyRangerFollowerDiceCount() != 2
            || deyRangerFollowerDieSides() != 6
            || deyRangerScrollLevel() != 21
            || deyRangerEffectiveLevel() != 9
            || deyRangerScrollWriteLevel() != 24
            || deyRangerScryingLevel() != 27
            || deyPaladinScrollLevel() != 21
            || deyPaladinEffectiveLevel() != 9
            || deyPaladinScrollWriteLevel() != 24
            || deyPaladinDiseaseImmunityLevel() != 27
            || deyAdaptForeignInitPenalty() != 6
            || deyAdaptCheckBonus() != 3
            || deyAdaptUnseenPenalty() != 4
            || deyAdaptBonusDaysPerLevel() != 1
            || deyAdaptPracticeHours() != 8
            || deyAdaptPermanentSlotCost() != 1
            || deyAdaptPermanentCpCost() != 3
            || deyAAARadius() != 5
            || deyAAADamageDie() != 8
            || deyAAAInvisibilityAcBonus() != 4
            || deyBraveryDerivedCost() != 2
            || deyCapSuggestionWizardLevel() != 3
            || deyCapGiftSavePenalty() != 4
            || deyCapHdImmune() != 8
            || deyCapBraveryCost() != 2
            || deyFrightAuraHd() != 4
            || deyFrightFleeRoundsDie() != 10
            || deyFrightImmuneFriendRange() != 30
            || deyChallengeMinHd() != 10
            || deyChallengeSightYards() != 100
            || deyChallengeNoRoleplayPenalty() != 6
            || deyChallengeFeeblePenalty() != 4
            || deyChallengeCompanionBonus() != 1
            || deyChallengeDamageBonusStep() != 10
            || deyChallengeWeakBonus() != 10
            || deyChallengeWeakThaco() != 14
            || deyChallengeWeakAc() != 2
            || deyChallengeWeakMaxDamage() != 6
            || deyChallengeRetreatRoundsDie() != 4
            || deyChallengeBraveryCost() != 1
            || deyChallengeMoraleRoundsDie() != 10
            || deyHardMinorDays() != 1
            || deyHardSevereWeeks() != 1
            || deyHardExtremeMonths() != 1
            || deyHardHeroicFloor() != -20
            || deyHardConsciousAt() != -19
            || deyHardBraveryCost() != 2
            || deyHardExampleLevel() != 17
            || deyHardExampleHpLeft() != 34
            || deyHardExampleHpTotal() != 115
            || deyHardExampleDelay() != 5
            || deyHardExampleImmuneHp() != 60
            || deyHardVampireLevels() != 2
            || deyHardParalysisWeeks() != 1
            || deyHardExampleWeeks() != 9
            || deyFocusBoostDurationPerLevel() != 1
            || deyFocusOtherScoresPenalty() != 2
            || deyFocusExtraordinaryFloor() != 16
            || deyFocusAttemptCost() != 2
            || deySenseAmbushScanYards() != 200
            || deySenseReadinessCube() != 30
            || deySenseHiddenRadius() != 30
            || deySenseHiddenInitPenalty() != 1
            || deySenseAlertnessBonus() != 1
            || deySenseLowHpPct() != 20
            || deySenseLowThacoDiff() != 15
            || deySenseModerateHpPct() != 50
            || deySenseModerateThacoDiff() != 10
            || deySenseSignificantHpPctLow() != 51
            || deySenseSignificantHpPctHigh() != 70
            || deySenseSignificantThacoDiff() != 5
            || deySenseDangerousHpPctLow() != 71
            || deySenseDangerousHpPctHigh() != 100
            || deySenseFailThreshold() != 19
            || deySigItemOwnLevels() != 1
            || deySigItemReplacementMonths() != 1
            || deySigItemMagicXpMultiple() != 5
            || deySigItemEnchantMonths() != 1
            || deySigItemCategories() != 4
            || deySigItemVisionChecksPerDay() != 1
            || deySigMountMaxHd() != 10
            || deySigMountMinHpPerHd() != 4
            || deySigMountHeavyWarHorseMinHp() != 25
            || deySigMountHpPerLevel() != 1
            || deySigMountSmartInt() != 5
            || deySigMountVisionChecksPerDay() != 1
            || !deySkillsNoCrossGroup()
            || !deySkillAbilityAdjustApplies()
            || !deySkillCostFirstIsSlots()
            || !deySkillCostParensIsPoints()
            || !deySkillBaseImprovableWithSlots()
            || !deySkillLimitedUseDropsFixed()
            || !deySkillZeroUnavailableADay()
            || !deySkillDependentsUnavailable()
            || !deySkillAbilityCantRestore()
            || !deySkillBaseRecoversAfterPeriod()
            || !deyOpposedOneFailsOtherWins()
            || !deyOpposedBothMakeHigherWins()
            || !deyOpposedBothFailUnusual()
            || !deyOpposedTiesRerolled()
            || !deyWishesNoEffectOnLimit()
            || !deySkillsMoreDramaticThanProficiencies()
            || !deyCaptivateNeedsBravery()
            || !deyFrightenNeedsBravery()
            || !deyHardinessNeedsBravery()
            || !deyDivineStrengthNeedsEminence()
            || !deyDivineVoiceNeedsEminence()
            || !deyDetectDeceptionNeedsEminence()
            || !deyInvincibilityNeedsEminence()
            || !deySmiteNeedsEminence()
            || !deyShadowFlightNeedsShadowTravel()
            || !deyT42ConBonusStopsAfter9()
            || !deyBreechAnyWeaponIncludingBareHands()
            || !deyBreechNoAttackBonus()
            || !deyBreechNotMagical()
            || !deyBreechUndiminishedByPlanarOrAntimagic()
            || !deyIntimidationNotAnAttack()
            || !deyIntimidationNoInitModifier()
            || !deyIntimidationCautiousRetreat()
            || !deyIntimidationAvoidsRestOfDay()
            || !deyIntimidationFreeToCounterattack()
            || !deyIntimidationMustBeInPlainSight()
            || !deyRangerUsePriestItems()
            || !deyPaladinImmuneCursedDisease()
            || !deyPaladinNotImmuneTrueDweomers()
            || !deyPaladinNotImmuneHigherPriestPowers()
            || !deyPaladinCureCursedAfflictions()
            || !deyPaladinCureLowerLevelCurses()
            || !deyPaladinCureCursedItems()
            || !deyAdaptNegatesCombatPenalties()
            || !deyAdaptCheckEachRound()
            || !deyAdaptNoSituationalMovement()
            || !deyAdaptNoMagicalOrVisionPenalties()
            || !deyAdaptIndefiniteWithPractice()
            || !deyAdaptPermanentOption()
            || !deyAdaptNoOtherActionCost()
            || !deyAAAAnnouncedInDeterminationStep()
            || !deyAAAKillTriggersBlast()
            || !deyAAALargerOrBetterAcExcluded()
            || !deyAAAWeaponImmuneExcluded()
            || !deyAAAInitialMissFails()
            || !deyAAANoKillNoRadius()
            || !deyAAANoMoveOrOtherAction()
            || !deyAAAMeleeProficientWeaponsOnly()
            || !deyAAACombatBonusesIrrelevant()
            || !deyBraveryNegatesUnnaturalFear()
            || !deyBraverySaveStillAllowedOnFail()
            || !deyBraveryPaladinVsEvilTurning()
            || !deyBraveryPrereqForCaptivateFrightenInvulnerability()
            || !deyBraveryZeroBlocksAllFour()
            || !deyCapSameRaceFriendly()
            || !deyCapSimilarAlignmentOneElement()
            || !deyCapSuggestionAutoIfNoRisk()
            || !deyCapSuccessfulSaveFlees()
            || !deyCapHostileActBreaks()
            || !deyCapExtendedContactAttachment()
            || !deyDeathBlowAnnounced()
            || !deyDeathBlowSaveVsDeathMagic()
            || !deyDeathBlowProtectiveDevicesApply()
            || !deyDeathBlowOptionalT36T38Modifiers()
            || !deyDeathBlowMoreHdImmune()
            || !deyDeathBlowWeaponImmuneImmune()
            || !deyDeathBlowOnlyAttackThatRound()
            || !deyDeathBlowAooAllowed()
            || !deyDeathBlowCombinesAllAround()
            || !deyDeathBlowOnlyInitialTargetDies()
            || !deyFrightShoutAndCharge()
            || !deyFrightMustSeeAndHear()
            || !deyFrightUndeadImmune()
            || !deyFrightNoMoraleImmune()
            || !deyFrightCloakOfBraveryNegates()
            || !deyFrightNatural20Attacks()
            || !deyFrightWarriorFleesTheyPursue()
            || !deyChallengeOpposedChaVsWis()
            || !deyChallengeWinnerMustCloseToMelee()
            || !deyChallengeRestraintTakesFullRound()
            || !deyChallengeUnwillingSaveEachRound()
            || !deyChallengeSpellsMissilesAfterClosing()
            || !deyChallengeNatural20AlwaysFails()
            || !deyChallengeBothFailWarriorRetreats()
            || !deyChallengeBraveryAvoidsRetreat()
            || !deyChallengeGazeCombosInRange()
            || !deyHardSaveFirst()
            || !deyHardNoSimpleOrContinuingDamage()
            || !deyHardNoCharmsEntangleImprison()
            || !deyHardCureWithinDelayNoHarm()
            || !deyHardShorterDurationNoEffect()
            || !deyHardSystemShockAtEnd()
            || !deyHardShockSuccessHeals()
            || !deyHardShockFailFullForce()
            || !deyHardMultipleEffectsSequential()
            || !deyHardUnconsciousRecoversInstantly()
            || !deyHardHeroicDelayRounds()
            || !deyHardHeroicDeathAtDelayEnd()
            || !deyHardRaiseDuringDelaySaves()
            || !deyHardRegenNoShock()
            || !deyHardAmuletNoShock()
            || !deyHardIneffectiveAtZeroBravery()
            || !deyFocusOneBoostAtATime()
            || !deyFocusConcentrationRoundOnlyAction()
            || !deyFocusBoostEndsAtWill()
            || !deyFocusNoEffectIfAlreadyHigher()
            || !deyFocusSubabilitiesRaisedEqual()
            || !deySenseFiveSubskills()
            || !deySenseDoublePurchaseExtraSubskill()
            || !deySenseImprovementAllSubskills()
            || !deySenseAmbushOncePerTurn()
            || !deySenseAmbushRevealsCountAndSize()
            || !deySenseBackNegatesSurpriseAndBonuses()
            || !deySenseBackDexBonusApplies()
            || !deySenseBackShieldOnlyIfTurns()
            || !deySenseNoFreeCounterattack()
            || !deySenseHiddenOncePerRound()
            || !deySenseHiddenNoDisguiseOrIntent()
            || !deySenseDmSecretRoll()
            || !deySenseFail19DetectsNothing()
            || !deySenseNatural20FalseIndication()
            || !deySenseFalseNoBackAttackEffect()
            || !deySenseDmChoosesCategory()
            || !deySenseDeadlyMoreHpLowerThaco()
            || !deySenseNoMagicOrSpellPowers()
            || !deySigItemNamedAndDistinctive()
            || !deySigItemNoCheckToDesignate()
            || !deySigItemEmpathicLinkOnNaming()
            || !deySigItemMustOwnAndUseRegularly()
            || !deySigItemNonconsumableOnly()
            || !deySigItemItemSavesAutoSucceed()
            || !deySigItemOwnerMustSurvive()
            || !deySigItemDeliberateActsCanDestroy()
            || !deySigItemDeadOwnerNormalRoll()
            || !deySigItemOtherPlanePlaneOnly()
            || !deySigItemMagicallyHiddenFactAndArea()
            || !deySigItemNonmagicalReplacementByName()
            || !deySigItemMagicalNeedsQualityAndCheck()
            || !deySigItemXpLossOrBrokenLink()
            || !deySigItemArtifactsExcluded()
            || !deySigItemOnePerCategory()
            || !deySigItemPairsAtDmOption()
            || !deySigItemImprovementAllItems()
            || !deySigItemNeglectBreaksLink()
            || !deySigMountMustBeTamed()
            || !deySigMountMustBeNamedAndRecognizable()
            || !deySigMountAreaNoDamageIfRiderSaves()
            || !deySigMountHalfOrNoneOnRiderFail()
            || !deySigMountDirectAttacksUseRiderSave()
            || !deySigMountPowerWordMustOvercomeRider()
            || !deySigMountAloneOwnSave()
            || !deySigMountKilledSameTypeReplacement()
            || !deySigMountOnePerTerrain()
            || !deySigMountWillinglyServesIfFound()
        )
            ++bad;
        // the deyT40Grid grid
        int CT40[33][5] = {
            {10,9,1,2,6},
            {10,-99,-99,1,3},
            {10,4,2,1,3},
            {15,4,3,1,3},
            {15,-99,-99,2,6},
            {10,4,6,1,3},
            {15,4,4,2,6},
            {10,4,2,1,3},
            {10,10,5,2,6},
            {10,9,5,1,3},
            {15,6,5,2,6},
            {12,4,2,1,3},
            {12,10,5,2,6},
            {12,8,7,1,3},
            {10,4,2,1,3},
            {15,4,6,-99,-99},
            {10,4,2,1,3},
            {15,6,5,-99,-99},
            {10,6,6,1,3},
            {21,4,2,2,6},
            {15,4,5,1,3},
            {15,-99,-99,2,6},
            {11,10,1,2,6},
            {11,4,7,2,6},
            {16,-99,-99,1,3},
            {11,11,8,1,3},
            {11,-99,-99,1,3},
            {16,-99,-99,2,6},
            {11,5,2,1,3},
            {16,4,2,2,6},
            {16,6,1,2,6},
            {21,-99,-99,1,3},
            {16,-99,-99,1,3},
            };
        int nT40[5] = {0,0,0,0,0};
        int eT40[5] = {0,8,8,2,2};
        for (int b = 0;
             b < deyT40RowCount();
             ++b) {
            int vals[5];
            vals[0] = deyT40ReqLevel(b);
            vals[1] = deyT40Base(b);
            vals[2] = deyT40Ability(b);
            vals[3] = deyT40CostSlots(b);
            vals[4] = deyT40CostCP(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CT40[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT40[c];
            }
        }
        for (int c = 0; c < 5; ++c)
            if (nT40[c] != eT40[c])
                ++bad;
        // the deyT41Grid grid
        int CT41[11][1] = {
            {-5},
            {-4},
            {-3},
            {-2},
            {-1},
            {0},
            {1},
            {2},
            {3},
            {4},
            {5},
            };
        for (int b = 0;
             b < deyT41RowCount();
             ++b) {
            int vals[1];
            vals[0] = deyT41Mod(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != CT41[b][c])
                    ++bad;
            }
        }
        // the deyT42Grid grid
        int CT42[11][6] = {
            {3000000,3600000,10,9,9,33},
            {3250000,3900000,11,10,9,36},
            {3500000,4200000,11,10,9,39},
            {3750000,4500000,11,10,9,42},
            {4000000,4800000,12,11,9,45},
            {4250000,5100000,12,11,9,48},
            {4500000,5400000,12,11,9,51},
            {4750000,5700000,13,12,9,54},
            {5000000,6000000,13,12,9,57},
            {5250000,6300000,13,12,9,60},
            {5500000,6600000,14,13,9,63},
            };
        for (int b = 0;
             b < deyT42RowCount();
             ++b) {
            int vals[6];
            vals[0] = deyT42FighterXP(b);
            vals[1] = deyT42PalRangerXP(b);
            vals[2] = deyT42WeaponProf(b);
            vals[3] = deyT42NonweaponProf(b);
            vals[4] = deyT42HpBase(b);
            vals[5] = deyT42HpBonus(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CT42[b][c])
                    ++bad;
            }
        }
        // the deyT41Band band-for boundaries
    if (deyT41Band(2) != 0
            || deyT41Band(3) != 0
            || deyT41Band(4) != 1
            || deyT41Band(4) != 1
            || deyT41Band(5) != 2
            || deyT41Band(5) != 2
            || deyT41Band(6) != 3
            || deyT41Band(6) != 3
            || deyT41Band(7) != 4
            || deyT41Band(7) != 4
            || deyT41Band(13) != 5
            || deyT41Band(8) != 5
            || deyT41Band(14) != 6
            || deyT41Band(14) != 6
            || deyT41Band(15) != 7
            || deyT41Band(15) != 7
            || deyT41Band(16) != 8
            || deyT41Band(16) != 8
            || deyT41Band(17) != 9
            || deyT41Band(17) != 9
            || deyT41Band(18) != 10
        )
            ++bad;
        // the deyBreechBand band-for boundaries
    if (deyBreechBand(19) != 0
            || deyBreechBand(20) != 0
            || deyBreechBand(23) != 1
            || deyBreechBand(21) != 1
            || deyBreechBand(26) != 2
            || deyBreechBand(24) != 2
            || deyBreechBand(29) != 3
            || deyBreechBand(27) != 3
            || deyBreechBand(30) != 4
        )
            ++bad;
        // the deyIntimidationPenaltyBand band-for boundaries
    if (deyIntimidationPenaltyBand(22) != 0
            || deyIntimidationPenaltyBand(23) != 0
            || deyIntimidationPenaltyBand(26) != 1
            || deyIntimidationPenaltyBand(24) != 1
            || deyIntimidationPenaltyBand(29) != 2
            || deyIntimidationPenaltyBand(27) != 2
            || deyIntimidationPenaltyBand(30) != 3
        )
            ++bad;
        // the deyAAADamageBand band-for boundaries
    if (deyAAADamageBand(13) != 0
            || deyAAADamageBand(14) != 0
            || deyAAADamageBand(19) != 1
            || deyAAADamageBand(15) != 1
            || deyAAADamageBand(24) != 2
            || deyAAADamageBand(20) != 2
            || deyAAADamageBand(29) != 3
            || deyAAADamageBand(25) != 3
            || deyAAADamageBand(30) != 4
        )
            ++bad;
        // the deyHardDelayBand band-for boundaries
    if (deyHardDelayBand(18) != 0
            || deyHardDelayBand(19) != 0
            || deyHardDelayBand(24) != 1
            || deyHardDelayBand(20) != 1
            || deyHardDelayBand(29) != 2
            || deyHardDelayBand(25) != 2
            || deyHardDelayBand(30) != 3
        )
            ++bad;
        // the deyFocusBand band-for boundaries
    if (deyFocusBand(13) != 0
            || deyFocusBand(14) != 0
            || deyFocusBand(19) != 1
            || deyFocusBand(15) != 1
            || deyFocusBand(24) != 2
            || deyFocusBand(20) != 2
            || deyFocusBand(29) != 3
            || deyFocusBand(25) != 3
            || deyFocusBand(30) != 4
        )
            ++bad;
        // the deySenseKnownBand band-for boundaries
    if (deySenseKnownBand(18) != 0
            || deySenseKnownBand(19) != 0
            || deySenseKnownBand(24) != 1
            || deySenseKnownBand(20) != 1
            || deySenseKnownBand(29) != 2
            || deySenseKnownBand(25) != 2
            || deySenseKnownBand(30) != 3
        )
            ++bad;
        // the deySkillDieSides pin
    if (deySkillDieSides() != 20
        )
            ++bad;
        // the deyMaxSkillBase pin
    if (deyMaxSkillBase() != 16
        )
            ++bad;
        // the deyT41RowCount pin
    if (deyT41RowCount() != 11
        )
            ++bad;
        // the deyT40RowCount pin
    if (deyT40RowCount() != 33
        )
            ++bad;
        // the deyT40WarriorBase pin
    if (deyT40WarriorBase() != 0
        )
            ++bad;
        // the deyT40WizardBase pin
    if (deyT40WizardBase() != 11
        )
            ++bad;
        // the deyT40PriestBase pin
    if (deyT40PriestBase() != 14
        )
            ++bad;
        // the deyT40RogueBase pin
    if (deyT40RogueBase() != 22
        )
            ++bad;
        // the deyWarriorThacoStopLevel pin
    if (deyWarriorThacoStopLevel() != 20
        )
            ++bad;
        // the deyWarriorAdvLimit pin
    if (deyWarriorAdvLimit() != 30
        )
            ++bad;
        // the deyWarriorPowerLevel pin
    if (deyWarriorPowerLevel() != 21
        )
            ++bad;
        // the deyWarriorSkillLevel pin
    if (deyWarriorSkillLevel() != 10
        )
            ++bad;
        // the deyT42RowCount pin
    if (deyT42RowCount() != 11
        )
            ++bad;
        // the deyBreechStartLevel pin
    if (deyBreechStartLevel() != 21
        )
            ++bad;
        // the deyIntimidationStartLevel pin
    if (deyIntimidationStartLevel() != 21
        )
            ++bad;
        // the deyIntimidationSightYards pin
    if (deyIntimidationSightYards() != 10
        )
            ++bad;
        // the deyIntimidationAutoRetreatHd pin
    if (deyIntimidationAutoRetreatHd() != 4
        )
            ++bad;
        // the deyIntimidationSaveHd pin
    if (deyIntimidationSaveHd() != 4
        )
            ++bad;
        // the deyIntimidationStayPenalty pin
    if (deyIntimidationStayPenalty() != 2
        )
            ++bad;
        // the deyIntimidationRange pin
    if (deyIntimidationRange() != 60
        )
            ++bad;
        // the deyIntimidationPenaltyStep pin
    if (deyIntimidationPenaltyStep() != 3
        )
            ++bad;
        // the deyIntimidationPenaltyIncrement pin
    if (deyIntimidationPenaltyIncrement() != 2
        )
            ++bad;
        // the deyRangerFollowerLevel1 pin
    if (deyRangerFollowerLevel1() != 21
        )
            ++bad;
        // the deyRangerFollowerLevel2 pin
    if (deyRangerFollowerLevel2() != 26
        )
            ++bad;
        // the deyRangerFollowerDiceCount pin
    if (deyRangerFollowerDiceCount() != 2
        )
            ++bad;
        // the deyRangerFollowerDieSides pin
    if (deyRangerFollowerDieSides() != 6
        )
            ++bad;
        // the deyRangerScrollLevel pin
    if (deyRangerScrollLevel() != 21
        )
            ++bad;
        // the deyRangerEffectiveLevel pin
    if (deyRangerEffectiveLevel() != 9
        )
            ++bad;
        // the deyRangerScrollWriteLevel pin
    if (deyRangerScrollWriteLevel() != 24
        )
            ++bad;
        // the deyRangerScryingLevel pin
    if (deyRangerScryingLevel() != 27
        )
            ++bad;
        // the deyPaladinScrollLevel pin
    if (deyPaladinScrollLevel() != 21
        )
            ++bad;
        // the deyPaladinEffectiveLevel pin
    if (deyPaladinEffectiveLevel() != 9
        )
            ++bad;
        // the deyPaladinScrollWriteLevel pin
    if (deyPaladinScrollWriteLevel() != 24
        )
            ++bad;
        // the deyPaladinDiseaseImmunityLevel pin
    if (deyPaladinDiseaseImmunityLevel() != 27
        )
            ++bad;
        // the deyAdaptForeignInitPenalty pin
    if (deyAdaptForeignInitPenalty() != 6
        )
            ++bad;
        // the deyAdaptCheckBonus pin
    if (deyAdaptCheckBonus() != 3
        )
            ++bad;
        // the deyAdaptUnseenPenalty pin
    if (deyAdaptUnseenPenalty() != 4
        )
            ++bad;
        // the deyAdaptBonusDaysPerLevel pin
    if (deyAdaptBonusDaysPerLevel() != 1
        )
            ++bad;
        // the deyAdaptPracticeHours pin
    if (deyAdaptPracticeHours() != 8
        )
            ++bad;
        // the deyAdaptPermanentSlotCost pin
    if (deyAdaptPermanentSlotCost() != 1
        )
            ++bad;
        // the deyAdaptPermanentCpCost pin
    if (deyAdaptPermanentCpCost() != 3
        )
            ++bad;
        // the deyAAARadius pin
    if (deyAAARadius() != 5
        )
            ++bad;
        // the deyAAADamageDie pin
    if (deyAAADamageDie() != 8
        )
            ++bad;
        // the deyAAAInvisibilityAcBonus pin
    if (deyAAAInvisibilityAcBonus() != 4
        )
            ++bad;
        // the deyBraveryDerivedCost pin
    if (deyBraveryDerivedCost() != 2
        )
            ++bad;
        // the deyCapSuggestionWizardLevel pin
    if (deyCapSuggestionWizardLevel() != 3
        )
            ++bad;
        // the deyCapGiftSavePenalty pin
    if (deyCapGiftSavePenalty() != 4
        )
            ++bad;
        // the deyCapHdImmune pin
    if (deyCapHdImmune() != 8
        )
            ++bad;
        // the deyCapBraveryCost pin
    if (deyCapBraveryCost() != 2
        )
            ++bad;
        // the deyFrightAuraHd pin
    if (deyFrightAuraHd() != 4
        )
            ++bad;
        // the deyFrightFleeRoundsDie pin
    if (deyFrightFleeRoundsDie() != 10
        )
            ++bad;
        // the deyFrightImmuneFriendRange pin
    if (deyFrightImmuneFriendRange() != 30
        )
            ++bad;
        // the deyChallengeMinHd pin
    if (deyChallengeMinHd() != 10
        )
            ++bad;
        // the deyChallengeSightYards pin
    if (deyChallengeSightYards() != 100
        )
            ++bad;
        // the deyChallengeNoRoleplayPenalty pin
    if (deyChallengeNoRoleplayPenalty() != 6
        )
            ++bad;
        // the deyChallengeFeeblePenalty pin
    if (deyChallengeFeeblePenalty() != 4
        )
            ++bad;
        // the deyChallengeCompanionBonus pin
    if (deyChallengeCompanionBonus() != 1
        )
            ++bad;
        // the deyChallengeDamageBonusStep pin
    if (deyChallengeDamageBonusStep() != 10
        )
            ++bad;
        // the deyChallengeWeakBonus pin
    if (deyChallengeWeakBonus() != 10
        )
            ++bad;
        // the deyChallengeWeakThaco pin
    if (deyChallengeWeakThaco() != 14
        )
            ++bad;
        // the deyChallengeWeakAc pin
    if (deyChallengeWeakAc() != 2
        )
            ++bad;
        // the deyChallengeWeakMaxDamage pin
    if (deyChallengeWeakMaxDamage() != 6
        )
            ++bad;
        // the deyChallengeRetreatRoundsDie pin
    if (deyChallengeRetreatRoundsDie() != 4
        )
            ++bad;
        // the deyChallengeBraveryCost pin
    if (deyChallengeBraveryCost() != 1
        )
            ++bad;
        // the deyChallengeMoraleRoundsDie pin
    if (deyChallengeMoraleRoundsDie() != 10
        )
            ++bad;
        // the deyHardMinorDays pin
    if (deyHardMinorDays() != 1
        )
            ++bad;
        // the deyHardSevereWeeks pin
    if (deyHardSevereWeeks() != 1
        )
            ++bad;
        // the deyHardExtremeMonths pin
    if (deyHardExtremeMonths() != 1
        )
            ++bad;
        // the deyHardHeroicFloor pin
    if (deyHardHeroicFloor() != -20
        )
            ++bad;
        // the deyHardConsciousAt pin
    if (deyHardConsciousAt() != -19
        )
            ++bad;
        // the deyHardBraveryCost pin
    if (deyHardBraveryCost() != 2
        )
            ++bad;
        // the deyHardExampleLevel pin
    if (deyHardExampleLevel() != 17
        )
            ++bad;
        // the deyHardExampleHpLeft pin
    if (deyHardExampleHpLeft() != 34
        )
            ++bad;
        // the deyHardExampleHpTotal pin
    if (deyHardExampleHpTotal() != 115
        )
            ++bad;
        // the deyHardExampleDelay pin
    if (deyHardExampleDelay() != 5
        )
            ++bad;
        // the deyHardExampleImmuneHp pin
    if (deyHardExampleImmuneHp() != 60
        )
            ++bad;
        // the deyHardVampireLevels pin
    if (deyHardVampireLevels() != 2
        )
            ++bad;
        // the deyHardParalysisWeeks pin
    if (deyHardParalysisWeeks() != 1
        )
            ++bad;
        // the deyHardExampleWeeks pin
    if (deyHardExampleWeeks() != 9
        )
            ++bad;
        // the deyFocusBoostDurationPerLevel pin
    if (deyFocusBoostDurationPerLevel() != 1
        )
            ++bad;
        // the deyFocusOtherScoresPenalty pin
    if (deyFocusOtherScoresPenalty() != 2
        )
            ++bad;
        // the deyFocusExtraordinaryFloor pin
    if (deyFocusExtraordinaryFloor() != 16
        )
            ++bad;
        // the deyFocusAttemptCost pin
    if (deyFocusAttemptCost() != 2
        )
            ++bad;
        // the deySenseAmbushScanYards pin
    if (deySenseAmbushScanYards() != 200
        )
            ++bad;
        // the deySenseReadinessCube pin
    if (deySenseReadinessCube() != 30
        )
            ++bad;
        // the deySenseHiddenRadius pin
    if (deySenseHiddenRadius() != 30
        )
            ++bad;
        // the deySenseHiddenInitPenalty pin
    if (deySenseHiddenInitPenalty() != 1
        )
            ++bad;
        // the deySenseAlertnessBonus pin
    if (deySenseAlertnessBonus() != 1
        )
            ++bad;
        // the deySenseLowHpPct pin
    if (deySenseLowHpPct() != 20
        )
            ++bad;
        // the deySenseLowThacoDiff pin
    if (deySenseLowThacoDiff() != 15
        )
            ++bad;
        // the deySenseModerateHpPct pin
    if (deySenseModerateHpPct() != 50
        )
            ++bad;
        // the deySenseModerateThacoDiff pin
    if (deySenseModerateThacoDiff() != 10
        )
            ++bad;
        // the deySenseSignificantHpPctLow pin
    if (deySenseSignificantHpPctLow() != 51
        )
            ++bad;
        // the deySenseSignificantHpPctHigh pin
    if (deySenseSignificantHpPctHigh() != 70
        )
            ++bad;
        // the deySenseSignificantThacoDiff pin
    if (deySenseSignificantThacoDiff() != 5
        )
            ++bad;
        // the deySenseDangerousHpPctLow pin
    if (deySenseDangerousHpPctLow() != 71
        )
            ++bad;
        // the deySenseDangerousHpPctHigh pin
    if (deySenseDangerousHpPctHigh() != 100
        )
            ++bad;
        // the deySenseFailThreshold pin
    if (deySenseFailThreshold() != 19
        )
            ++bad;
        // the deySigItemOwnLevels pin
    if (deySigItemOwnLevels() != 1
        )
            ++bad;
        // the deySigItemReplacementMonths pin
    if (deySigItemReplacementMonths() != 1
        )
            ++bad;
        // the deySigItemMagicXpMultiple pin
    if (deySigItemMagicXpMultiple() != 5
        )
            ++bad;
        // the deySigItemEnchantMonths pin
    if (deySigItemEnchantMonths() != 1
        )
            ++bad;
        // the deySigItemCategories pin
    if (deySigItemCategories() != 4
        )
            ++bad;
        // the deySigItemVisionChecksPerDay pin
    if (deySigItemVisionChecksPerDay() != 1
        )
            ++bad;
        // the deySigMountMaxHd pin
    if (deySigMountMaxHd() != 10
        )
            ++bad;
        // the deySigMountMinHpPerHd pin
    if (deySigMountMinHpPerHd() != 4
        )
            ++bad;
        // the deySigMountHeavyWarHorseMinHp pin
    if (deySigMountHeavyWarHorseMinHp() != 25
        )
            ++bad;
        // the deySigMountHpPerLevel pin
    if (deySigMountHpPerLevel() != 1
        )
            ++bad;
        // the deySigMountSmartInt pin
    if (deySigMountSmartInt() != 5
        )
            ++bad;
        // the deySigMountVisionChecksPerDay pin
    if (deySigMountVisionChecksPerDay() != 1
        )
            ++bad;
        // the deySkillsNoCrossGroup pin
    if (deySkillsNoCrossGroup() != 1
        )
            ++bad;
        // the deySkillAbilityAdjustApplies pin
    if (deySkillAbilityAdjustApplies() != 1
        )
            ++bad;
        // the deySkillCostFirstIsSlots pin
    if (deySkillCostFirstIsSlots() != 1
        )
            ++bad;
        // the deySkillCostParensIsPoints pin
    if (deySkillCostParensIsPoints() != 1
        )
            ++bad;
        // the deySkillBaseImprovableWithSlots pin
    if (deySkillBaseImprovableWithSlots() != 1
        )
            ++bad;
        // the deySkillLimitedUseDropsFixed pin
    if (deySkillLimitedUseDropsFixed() != 1
        )
            ++bad;
        // the deySkillZeroUnavailableADay pin
    if (deySkillZeroUnavailableADay() != 1
        )
            ++bad;
        // the deySkillDependentsUnavailable pin
    if (deySkillDependentsUnavailable() != 1
        )
            ++bad;
        // the deySkillAbilityCantRestore pin
    if (deySkillAbilityCantRestore() != 1
        )
            ++bad;
        // the deySkillBaseRecoversAfterPeriod pin
    if (deySkillBaseRecoversAfterPeriod() != 1
        )
            ++bad;
        // the deyOpposedOneFailsOtherWins pin
    if (deyOpposedOneFailsOtherWins() != 1
        )
            ++bad;
        // the deyOpposedBothMakeHigherWins pin
    if (deyOpposedBothMakeHigherWins() != 1
        )
            ++bad;
        // the deyOpposedBothFailUnusual pin
    if (deyOpposedBothFailUnusual() != 1
        )
            ++bad;
        // the deyOpposedTiesRerolled pin
    if (deyOpposedTiesRerolled() != 1
        )
            ++bad;
        // the deyWishesNoEffectOnLimit pin
    if (deyWishesNoEffectOnLimit() != 1
        )
            ++bad;
        // the deySkillsMoreDramaticThanProficiencies pin
    if (deySkillsMoreDramaticThanProficiencies() != 1
        )
            ++bad;
        // the deyCaptivateNeedsBravery pin
    if (deyCaptivateNeedsBravery() != 1
        )
            ++bad;
        // the deyFrightenNeedsBravery pin
    if (deyFrightenNeedsBravery() != 1
        )
            ++bad;
        // the deyHardinessNeedsBravery pin
    if (deyHardinessNeedsBravery() != 1
        )
            ++bad;
        // the deyDivineStrengthNeedsEminence pin
    if (deyDivineStrengthNeedsEminence() != 1
        )
            ++bad;
        // the deyDivineVoiceNeedsEminence pin
    if (deyDivineVoiceNeedsEminence() != 1
        )
            ++bad;
        // the deyDetectDeceptionNeedsEminence pin
    if (deyDetectDeceptionNeedsEminence() != 1
        )
            ++bad;
        // the deyInvincibilityNeedsEminence pin
    if (deyInvincibilityNeedsEminence() != 1
        )
            ++bad;
        // the deySmiteNeedsEminence pin
    if (deySmiteNeedsEminence() != 1
        )
            ++bad;
        // the deyShadowFlightNeedsShadowTravel pin
    if (deyShadowFlightNeedsShadowTravel() != 1
        )
            ++bad;
        // the deyT42ConBonusStopsAfter9 pin
    if (deyT42ConBonusStopsAfter9() != 1
        )
            ++bad;
        // the deyBreechAnyWeaponIncludingBareHands pin
    if (deyBreechAnyWeaponIncludingBareHands() != 1
        )
            ++bad;
        // the deyBreechNoAttackBonus pin
    if (deyBreechNoAttackBonus() != 1
        )
            ++bad;
        // the deyBreechNotMagical pin
    if (deyBreechNotMagical() != 1
        )
            ++bad;
        // the deyBreechUndiminishedByPlanarOrAntimagic pin
    if (deyBreechUndiminishedByPlanarOrAntimagic() != 1
        )
            ++bad;
        // the deyIntimidationNotAnAttack pin
    if (deyIntimidationNotAnAttack() != 1
        )
            ++bad;
        // the deyIntimidationNoInitModifier pin
    if (deyIntimidationNoInitModifier() != 1
        )
            ++bad;
        // the deyIntimidationCautiousRetreat pin
    if (deyIntimidationCautiousRetreat() != 1
        )
            ++bad;
        // the deyIntimidationAvoidsRestOfDay pin
    if (deyIntimidationAvoidsRestOfDay() != 1
        )
            ++bad;
        // the deyIntimidationFreeToCounterattack pin
    if (deyIntimidationFreeToCounterattack() != 1
        )
            ++bad;
        // the deyIntimidationMustBeInPlainSight pin
    if (deyIntimidationMustBeInPlainSight() != 1
        )
            ++bad;
        // the deyRangerUsePriestItems pin
    if (deyRangerUsePriestItems() != 1
        )
            ++bad;
        // the deyPaladinImmuneCursedDisease pin
    if (deyPaladinImmuneCursedDisease() != 1
        )
            ++bad;
        // the deyPaladinNotImmuneTrueDweomers pin
    if (deyPaladinNotImmuneTrueDweomers() != 1
        )
            ++bad;
        // the deyPaladinNotImmuneHigherPriestPowers pin
    if (deyPaladinNotImmuneHigherPriestPowers() != 1
        )
            ++bad;
        // the deyPaladinCureCursedAfflictions pin
    if (deyPaladinCureCursedAfflictions() != 1
        )
            ++bad;
        // the deyPaladinCureLowerLevelCurses pin
    if (deyPaladinCureLowerLevelCurses() != 1
        )
            ++bad;
        // the deyPaladinCureCursedItems pin
    if (deyPaladinCureCursedItems() != 1
        )
            ++bad;
        // the deyAdaptNegatesCombatPenalties pin
    if (deyAdaptNegatesCombatPenalties() != 1
        )
            ++bad;
        // the deyAdaptCheckEachRound pin
    if (deyAdaptCheckEachRound() != 1
        )
            ++bad;
        // the deyAdaptNoSituationalMovement pin
    if (deyAdaptNoSituationalMovement() != 1
        )
            ++bad;
        // the deyAdaptNoMagicalOrVisionPenalties pin
    if (deyAdaptNoMagicalOrVisionPenalties() != 1
        )
            ++bad;
        // the deyAdaptIndefiniteWithPractice pin
    if (deyAdaptIndefiniteWithPractice() != 1
        )
            ++bad;
        // the deyAdaptPermanentOption pin
    if (deyAdaptPermanentOption() != 1
        )
            ++bad;
        // the deyAdaptNoOtherActionCost pin
    if (deyAdaptNoOtherActionCost() != 1
        )
            ++bad;
        // the deyAAAAnnouncedInDeterminationStep pin
    if (deyAAAAnnouncedInDeterminationStep() != 1
        )
            ++bad;
        // the deyAAAKillTriggersBlast pin
    if (deyAAAKillTriggersBlast() != 1
        )
            ++bad;
        // the deyAAALargerOrBetterAcExcluded pin
    if (deyAAALargerOrBetterAcExcluded() != 1
        )
            ++bad;
        // the deyAAAWeaponImmuneExcluded pin
    if (deyAAAWeaponImmuneExcluded() != 1
        )
            ++bad;
        // the deyAAAInitialMissFails pin
    if (deyAAAInitialMissFails() != 1
        )
            ++bad;
        // the deyAAANoKillNoRadius pin
    if (deyAAANoKillNoRadius() != 1
        )
            ++bad;
        // the deyAAANoMoveOrOtherAction pin
    if (deyAAANoMoveOrOtherAction() != 1
        )
            ++bad;
        // the deyAAAMeleeProficientWeaponsOnly pin
    if (deyAAAMeleeProficientWeaponsOnly() != 1
        )
            ++bad;
        // the deyAAACombatBonusesIrrelevant pin
    if (deyAAACombatBonusesIrrelevant() != 1
        )
            ++bad;
        // the deyBraveryNegatesUnnaturalFear pin
    if (deyBraveryNegatesUnnaturalFear() != 1
        )
            ++bad;
        // the deyBraverySaveStillAllowedOnFail pin
    if (deyBraverySaveStillAllowedOnFail() != 1
        )
            ++bad;
        // the deyBraveryPaladinVsEvilTurning pin
    if (deyBraveryPaladinVsEvilTurning() != 1
        )
            ++bad;
        // the deyBraveryPrereqForCaptivateFrightenInvulnerability pin
    if (deyBraveryPrereqForCaptivateFrightenInvulnerability() != 1
        )
            ++bad;
        // the deyBraveryZeroBlocksAllFour pin
    if (deyBraveryZeroBlocksAllFour() != 1
        )
            ++bad;
        // the deyCapSameRaceFriendly pin
    if (deyCapSameRaceFriendly() != 1
        )
            ++bad;
        // the deyCapSimilarAlignmentOneElement pin
    if (deyCapSimilarAlignmentOneElement() != 1
        )
            ++bad;
        // the deyCapSuggestionAutoIfNoRisk pin
    if (deyCapSuggestionAutoIfNoRisk() != 1
        )
            ++bad;
        // the deyCapSuccessfulSaveFlees pin
    if (deyCapSuccessfulSaveFlees() != 1
        )
            ++bad;
        // the deyCapHostileActBreaks pin
    if (deyCapHostileActBreaks() != 1
        )
            ++bad;
        // the deyCapExtendedContactAttachment pin
    if (deyCapExtendedContactAttachment() != 1
        )
            ++bad;
        // the deyDeathBlowAnnounced pin
    if (deyDeathBlowAnnounced() != 1
        )
            ++bad;
        // the deyDeathBlowSaveVsDeathMagic pin
    if (deyDeathBlowSaveVsDeathMagic() != 1
        )
            ++bad;
        // the deyDeathBlowProtectiveDevicesApply pin
    if (deyDeathBlowProtectiveDevicesApply() != 1
        )
            ++bad;
        // the deyDeathBlowOptionalT36T38Modifiers pin
    if (deyDeathBlowOptionalT36T38Modifiers() != 1
        )
            ++bad;
        // the deyDeathBlowMoreHdImmune pin
    if (deyDeathBlowMoreHdImmune() != 1
        )
            ++bad;
        // the deyDeathBlowWeaponImmuneImmune pin
    if (deyDeathBlowWeaponImmuneImmune() != 1
        )
            ++bad;
        // the deyDeathBlowOnlyAttackThatRound pin
    if (deyDeathBlowOnlyAttackThatRound() != 1
        )
            ++bad;
        // the deyDeathBlowAooAllowed pin
    if (deyDeathBlowAooAllowed() != 1
        )
            ++bad;
        // the deyDeathBlowCombinesAllAround pin
    if (deyDeathBlowCombinesAllAround() != 1
        )
            ++bad;
        // the deyDeathBlowOnlyInitialTargetDies pin
    if (deyDeathBlowOnlyInitialTargetDies() != 1
        )
            ++bad;
        // the deyFrightShoutAndCharge pin
    if (deyFrightShoutAndCharge() != 1
        )
            ++bad;
        // the deyFrightMustSeeAndHear pin
    if (deyFrightMustSeeAndHear() != 1
        )
            ++bad;
        // the deyFrightUndeadImmune pin
    if (deyFrightUndeadImmune() != 1
        )
            ++bad;
        // the deyFrightNoMoraleImmune pin
    if (deyFrightNoMoraleImmune() != 1
        )
            ++bad;
        // the deyFrightCloakOfBraveryNegates pin
    if (deyFrightCloakOfBraveryNegates() != 1
        )
            ++bad;
        // the deyFrightNatural20Attacks pin
    if (deyFrightNatural20Attacks() != 1
        )
            ++bad;
        // the deyFrightWarriorFleesTheyPursue pin
    if (deyFrightWarriorFleesTheyPursue() != 1
        )
            ++bad;
        // the deyChallengeOpposedChaVsWis pin
    if (deyChallengeOpposedChaVsWis() != 1
        )
            ++bad;
        // the deyChallengeWinnerMustCloseToMelee pin
    if (deyChallengeWinnerMustCloseToMelee() != 1
        )
            ++bad;
        // the deyChallengeRestraintTakesFullRound pin
    if (deyChallengeRestraintTakesFullRound() != 1
        )
            ++bad;
        // the deyChallengeUnwillingSaveEachRound pin
    if (deyChallengeUnwillingSaveEachRound() != 1
        )
            ++bad;
        // the deyChallengeSpellsMissilesAfterClosing pin
    if (deyChallengeSpellsMissilesAfterClosing() != 1
        )
            ++bad;
        // the deyChallengeNatural20AlwaysFails pin
    if (deyChallengeNatural20AlwaysFails() != 1
        )
            ++bad;
        // the deyChallengeBothFailWarriorRetreats pin
    if (deyChallengeBothFailWarriorRetreats() != 1
        )
            ++bad;
        // the deyChallengeBraveryAvoidsRetreat pin
    if (deyChallengeBraveryAvoidsRetreat() != 1
        )
            ++bad;
        // the deyChallengeGazeCombosInRange pin
    if (deyChallengeGazeCombosInRange() != 1
        )
            ++bad;
        // the deyHardSaveFirst pin
    if (deyHardSaveFirst() != 1
        )
            ++bad;
        // the deyHardNoSimpleOrContinuingDamage pin
    if (deyHardNoSimpleOrContinuingDamage() != 1
        )
            ++bad;
        // the deyHardNoCharmsEntangleImprison pin
    if (deyHardNoCharmsEntangleImprison() != 1
        )
            ++bad;
        // the deyHardCureWithinDelayNoHarm pin
    if (deyHardCureWithinDelayNoHarm() != 1
        )
            ++bad;
        // the deyHardShorterDurationNoEffect pin
    if (deyHardShorterDurationNoEffect() != 1
        )
            ++bad;
        // the deyHardSystemShockAtEnd pin
    if (deyHardSystemShockAtEnd() != 1
        )
            ++bad;
        // the deyHardShockSuccessHeals pin
    if (deyHardShockSuccessHeals() != 1
        )
            ++bad;
        // the deyHardShockFailFullForce pin
    if (deyHardShockFailFullForce() != 1
        )
            ++bad;
        // the deyHardMultipleEffectsSequential pin
    if (deyHardMultipleEffectsSequential() != 1
        )
            ++bad;
        // the deyHardUnconsciousRecoversInstantly pin
    if (deyHardUnconsciousRecoversInstantly() != 1
        )
            ++bad;
        // the deyHardHeroicDelayRounds pin
    if (deyHardHeroicDelayRounds() != 1
        )
            ++bad;
        // the deyHardHeroicDeathAtDelayEnd pin
    if (deyHardHeroicDeathAtDelayEnd() != 1
        )
            ++bad;
        // the deyHardRaiseDuringDelaySaves pin
    if (deyHardRaiseDuringDelaySaves() != 1
        )
            ++bad;
        // the deyHardRegenNoShock pin
    if (deyHardRegenNoShock() != 1
        )
            ++bad;
        // the deyHardAmuletNoShock pin
    if (deyHardAmuletNoShock() != 1
        )
            ++bad;
        // the deyHardIneffectiveAtZeroBravery pin
    if (deyHardIneffectiveAtZeroBravery() != 1
        )
            ++bad;
        // the deyFocusOneBoostAtATime pin
    if (deyFocusOneBoostAtATime() != 1
        )
            ++bad;
        // the deyFocusConcentrationRoundOnlyAction pin
    if (deyFocusConcentrationRoundOnlyAction() != 1
        )
            ++bad;
        // the deyFocusBoostEndsAtWill pin
    if (deyFocusBoostEndsAtWill() != 1
        )
            ++bad;
        // the deyFocusNoEffectIfAlreadyHigher pin
    if (deyFocusNoEffectIfAlreadyHigher() != 1
        )
            ++bad;
        // the deyFocusSubabilitiesRaisedEqual pin
    if (deyFocusSubabilitiesRaisedEqual() != 1
        )
            ++bad;
        // the deySenseFiveSubskills pin
    if (deySenseFiveSubskills() != 1
        )
            ++bad;
        // the deySenseDoublePurchaseExtraSubskill pin
    if (deySenseDoublePurchaseExtraSubskill() != 1
        )
            ++bad;
        // the deySenseImprovementAllSubskills pin
    if (deySenseImprovementAllSubskills() != 1
        )
            ++bad;
        // the deySenseAmbushOncePerTurn pin
    if (deySenseAmbushOncePerTurn() != 1
        )
            ++bad;
        // the deySenseAmbushRevealsCountAndSize pin
    if (deySenseAmbushRevealsCountAndSize() != 1
        )
            ++bad;
        // the deySenseBackNegatesSurpriseAndBonuses pin
    if (deySenseBackNegatesSurpriseAndBonuses() != 1
        )
            ++bad;
        // the deySenseBackDexBonusApplies pin
    if (deySenseBackDexBonusApplies() != 1
        )
            ++bad;
        // the deySenseBackShieldOnlyIfTurns pin
    if (deySenseBackShieldOnlyIfTurns() != 1
        )
            ++bad;
        // the deySenseNoFreeCounterattack pin
    if (deySenseNoFreeCounterattack() != 1
        )
            ++bad;
        // the deySenseHiddenOncePerRound pin
    if (deySenseHiddenOncePerRound() != 1
        )
            ++bad;
        // the deySenseHiddenNoDisguiseOrIntent pin
    if (deySenseHiddenNoDisguiseOrIntent() != 1
        )
            ++bad;
        // the deySenseDmSecretRoll pin
    if (deySenseDmSecretRoll() != 1
        )
            ++bad;
        // the deySenseFail19DetectsNothing pin
    if (deySenseFail19DetectsNothing() != 1
        )
            ++bad;
        // the deySenseNatural20FalseIndication pin
    if (deySenseNatural20FalseIndication() != 1
        )
            ++bad;
        // the deySenseFalseNoBackAttackEffect pin
    if (deySenseFalseNoBackAttackEffect() != 1
        )
            ++bad;
        // the deySenseDmChoosesCategory pin
    if (deySenseDmChoosesCategory() != 1
        )
            ++bad;
        // the deySenseDeadlyMoreHpLowerThaco pin
    if (deySenseDeadlyMoreHpLowerThaco() != 1
        )
            ++bad;
        // the deySenseNoMagicOrSpellPowers pin
    if (deySenseNoMagicOrSpellPowers() != 1
        )
            ++bad;
        // the deySigItemNamedAndDistinctive pin
    if (deySigItemNamedAndDistinctive() != 1
        )
            ++bad;
        // the deySigItemNoCheckToDesignate pin
    if (deySigItemNoCheckToDesignate() != 1
        )
            ++bad;
        // the deySigItemEmpathicLinkOnNaming pin
    if (deySigItemEmpathicLinkOnNaming() != 1
        )
            ++bad;
        // the deySigItemMustOwnAndUseRegularly pin
    if (deySigItemMustOwnAndUseRegularly() != 1
        )
            ++bad;
        // the deySigItemNonconsumableOnly pin
    if (deySigItemNonconsumableOnly() != 1
        )
            ++bad;
        // the deySigItemItemSavesAutoSucceed pin
    if (deySigItemItemSavesAutoSucceed() != 1
        )
            ++bad;
        // the deySigItemOwnerMustSurvive pin
    if (deySigItemOwnerMustSurvive() != 1
        )
            ++bad;
        // the deySigItemDeliberateActsCanDestroy pin
    if (deySigItemDeliberateActsCanDestroy() != 1
        )
            ++bad;
        // the deySigItemDeadOwnerNormalRoll pin
    if (deySigItemDeadOwnerNormalRoll() != 1
        )
            ++bad;
        // the deySigItemOtherPlanePlaneOnly pin
    if (deySigItemOtherPlanePlaneOnly() != 1
        )
            ++bad;
        // the deySigItemMagicallyHiddenFactAndArea pin
    if (deySigItemMagicallyHiddenFactAndArea() != 1
        )
            ++bad;
        // the deySigItemNonmagicalReplacementByName pin
    if (deySigItemNonmagicalReplacementByName() != 1
        )
            ++bad;
        // the deySigItemMagicalNeedsQualityAndCheck pin
    if (deySigItemMagicalNeedsQualityAndCheck() != 1
        )
            ++bad;
        // the deySigItemXpLossOrBrokenLink pin
    if (deySigItemXpLossOrBrokenLink() != 1
        )
            ++bad;
        // the deySigItemArtifactsExcluded pin
    if (deySigItemArtifactsExcluded() != 1
        )
            ++bad;
        // the deySigItemOnePerCategory pin
    if (deySigItemOnePerCategory() != 1
        )
            ++bad;
        // the deySigItemPairsAtDmOption pin
    if (deySigItemPairsAtDmOption() != 1
        )
            ++bad;
        // the deySigItemImprovementAllItems pin
    if (deySigItemImprovementAllItems() != 1
        )
            ++bad;
        // the deySigItemNeglectBreaksLink pin
    if (deySigItemNeglectBreaksLink() != 1
        )
            ++bad;
        // the deySigMountMustBeTamed pin
    if (deySigMountMustBeTamed() != 1
        )
            ++bad;
        // the deySigMountMustBeNamedAndRecognizable pin
    if (deySigMountMustBeNamedAndRecognizable() != 1
        )
            ++bad;
        // the deySigMountAreaNoDamageIfRiderSaves pin
    if (deySigMountAreaNoDamageIfRiderSaves() != 1
        )
            ++bad;
        // the deySigMountHalfOrNoneOnRiderFail pin
    if (deySigMountHalfOrNoneOnRiderFail() != 1
        )
            ++bad;
        // the deySigMountDirectAttacksUseRiderSave pin
    if (deySigMountDirectAttacksUseRiderSave() != 1
        )
            ++bad;
        // the deySigMountPowerWordMustOvercomeRider pin
    if (deySigMountPowerWordMustOvercomeRider() != 1
        )
            ++bad;
        // the deySigMountAloneOwnSave pin
    if (deySigMountAloneOwnSave() != 1
        )
            ++bad;
        // the deySigMountKilledSameTypeReplacement pin
    if (deySigMountKilledSameTypeReplacement() != 1
        )
            ++bad;
        // the deySigMountOnePerTerrain pin
    if (deySigMountOnePerTerrain() != 1
        )
            ++bad;
        // the deySigMountWillinglyServesIfFound pin
    if (deySigMountWillinglyServesIfFound() != 1
        )
            ++bad;
        // the Table 40 point cost is triple the slot cost - adaptation 2(6)
        // (printed p. 145)
    if (deyT40CostCP(0) != 3 * deyT40CostSlots(0)
        )
            ++bad;
        // the Table 40 point cost is triple the slot cost - bravery 1(3)
        // (printed p. 145)
    if (deyT40CostCP(2) != 3 * deyT40CostSlots(2)
        )
            ++bad;
        // the Table 40 point cost is triple the slot cost - invincibility
        // 2(6) (printed p. 146)
    if (deyT40CostCP(19) != 3 * deyT40CostSlots(19)
        )
            ++bad;
        // the Table 40 point cost is triple the slot cost - rogue adaptation
        // 2(6) (printed p. 146)
    if (deyT40CostCP(22) != 3 * deyT40CostSlots(22)
        )
            ++bad;
        // the Table 40 blank priest cost cells pin as printed blanks (Divine
        // Voice row 15, printed p. 146)
    if (deyT40CostSlots(15) != -99
            || deyT40CostCP(15) != -99
        )
            ++bad;
        // the Table 40 blank priest cost cells pin as printed blanks (Detect
        // Deception row 17, printed p. 146)
    if (deyT40CostSlots(17) != -99
            || deyT40CostCP(17) != -99
        )
            ++bad;
        // the Table 41 middle band reads 0: an 8 reads 0 and a 13 reads 0
        // (printed p. 146)
    if (deyT41Mod(deyT41Band(8)) != 0
            || deyT41Mod(deyT41Band(13)) != 0
        )
            ++bad;
        // the Table 41 edges: a 3 reads -5, an 18 reads +5 (printed p. 146)
    if (deyT41Mod(deyT41Band(3)) != -5
            || deyT41Mod(deyT41Band(18)) != 5
        )
            ++bad;
        // the Table 42 fighter steps: 250,000 per level (printed p. 147)
    if (deyT42FighterXP(1) - deyT42FighterXP(0) != 250000
        )
            ++bad;
        // the Table 42 paladin/ranger steps: 300,000 per level (printed p.
        // 147)
    if (deyT42PalRangerXP(1) - deyT42PalRangerXP(0) != 300000
        )
            ++bad;
        // the Table 42 hit-point bonus steps: +3 per level (printed p. 147)
    if (deyT42HpBonus(1) - deyT42HpBonus(0) != 3
        )
            ++bad;
        // the Table 42 proficiency columns track one apart (printed p. 147)
    if (deyT42WeaponProf(5) != deyT42NonweaponProf(5) + 1
        )
            ++bad;
        // the Table 42 row 20 reads weapon 10, nonweapon 9 (printed p. 147)
    if (deyT42WeaponProf(0) != 10
            || deyT42NonweaponProf(0) != 9
        )
            ++bad;
        // the Table 42 level 30 tail: weapon 14, nonweapon 13, 9+63 hit
        // points (printed p. 147)
    if (deyT42WeaponProf(10) != 14
            || deyT42NonweaponProf(10) != 13
            || deyT42HpBonus(10) != 63
        )
            ++bad;
        // the breech ladder head: 21st harms +1-or-better creatures (printed
        // p. 147)
    if (deyBreechBand(21) != 1
            || deyBreechBand(20) != 0
        )
            ++bad;
        // the breech ladder tail: 30th reaches +4 (printed p. 148)
    if (deyBreechBand(30) != 4
        )
            ++bad;
        // the intimidation save ladder: 30th inflicts the -6 adjustment
        // (printed p. 149)
    if (deyIntimidationPenaltyIncrement() * deyIntimidationPenaltyBand(30) - 6
        != 0
        )
            ++bad;
        // the intimidation save ladder: 21st through 23rd carry no penalty,
        // 24th starts -2 (printed p. 149)
    if (deyIntimidationPenaltyBand(21) != 0
            || deyIntimidationPenaltyBand(24) != 1
        )
            ++bad;
        // the all-around damage ladder: 10th deals 1d8, 30th deals 5d8
        // (printed pp. 149-150)
    if (deyAAADamageBand(10) + 1 != 1
            || deyAAADamageBand(30) + 1 != 5
        )
            ++bad;
        // the hardiness delay ladder: a 17th-level warrior delays five rounds
        // (printed p. 152)
    if ((deyHardDelayBand(17) + 1) * 5 != 5
        )
            ++bad;
        // the hardiness delay ladder tail: 30th delays twenty rounds (printed
        // p. 152)
    if ((deyHardDelayBand(30) + 1) * 5 != 20
        )
            ++bad;
        // the hardiness worked example: five rounds of delay matches the
        // 17th-level band (printed p. 152)
    if (deyHardExampleDelay() != (deyHardDelayBand(deyHardExampleLevel()) + 1)
        * 5
        )
            ++bad;
        // the hardiness vampire-and-lich sum: two months plus the paralysis
        // week is nine weeks (printed p. 153)
    if (deyHardVampireLevels() * 4 + deyHardParalysisWeeks() !=
        deyHardExampleWeeks()
        )
            ++bad;
        // the inner focus ladder: 10th boosts to 18, 30th to 22 (printed p.
        // 154)
    if (deyFocusBand(10) + 18 != 18
            || deyFocusBand(30) + 18 != 22
        )
            ++bad;
        // the sense danger subskills: 15th knows one, 30th knows four
        // (printed p. 154)
    if (deySenseKnownBand(15) + 1 != 1
            || deySenseKnownBand(30) + 1 != 4
        )
            ++bad;
        // the bravery drain matches the captivate and hardiness drains
        // (printed pp. 150-153)
    if (deyBraveryDerivedCost() != deyCapBraveryCost()
            || deyBraveryDerivedCost() != deyHardBraveryCost()
        )
            ++bad;
        // the frighten drain is one, half the other bravery-derived drains
        // (printed p. 152)
    if (deyChallengeBraveryCost() * 2 != deyBraveryDerivedCost()
        )
            ++bad;
        // the signature mount example: the heavy war horse floor of 25 hit
        // points (printed p. 156)
    if (deySigMountHeavyWarHorseMinHp() < 25
        )
            ++bad;
        // the warrior advancement spans 20th through 30th (printed pp.
        // 146-147)
    if (deyT42RowCount() != deyWarriorAdvLimit() - deyWarriorThacoStopLevel()
        + 1
        )
            ++bad;
        printf("R609 DMO high-level skills audit: bad %d\n", bad);
        if (bad) return 1;
    }
