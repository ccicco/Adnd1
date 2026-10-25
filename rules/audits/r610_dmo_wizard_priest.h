    // ---- R610 DMO wizard-priest audit ----
    // DMO Chapter 7 round three of five (printed pp. 156-167): the Table 43
    // wizard advancement grid (375K XP steps, the proficiency columns, the
    // 10+N d4 hit points), the Table 44 wizard spell progression with its
    // true dweomer column, the sage ability thresholds and its 1d3+1-weeks
    // research example, the wizard skills - mental focus with the 18-to-22
    // boost ladder, the six signature item categories, spell sculpting with
    // its fireball/burning hands/magic missile worked examples and the shared
    // 1st-to-7th cap chain; the priest true dweomer doctrine, the Table 45
    // advancement grid (cleric and druid XP ladders, the 9+N d8 hit points),
    // the priest spell progression grid (body caption Table 47, contents
    // Table 46), the quest spell, improved turning with the Wulf example,
    // spell selection at 21/25/27, the holy army with its halving officer
    // chain; and the nine priest skills - divine strength (18-to-22 ladder),
    // divine voice (180 feet, rock and lead penetration, the enthrall and
    // mass suggestion rules), divine will, detect deception (the one-to-five
    // turn duration ladder), eminence (the 30-foot fear, the +4 reaction
    // bonus, the five-skill prerequisite list with its printed divine will
    // tension), invincibility (the 5/10/15-round delay ladder, the 96-percent
    // system shock example, the nine-week vampire-and-lich sum), loan (the
    // 1d8+2 to 4d6+8 grid), smite (the 30-to-110-foot cone ladder, all nine
    // deific effects, the Marissa example) and the spell talisman (the Wulf
    // storage example).
    {
        using namespace rules;
        int bad = 0;
    if (dezWizAdvLimit() != 30
            || dezWizSkillPauseLevel() != 20
            || dezT43RowCount() != 11
            || dezT43XpStep() != 375000
            || dezT43HpBase() != 10
            || dezT44RowCount() != 11
            || dezSageStartLevel() != 21
            || dezSageCategoryCount() != 2
            || dezSageBaseChance() != 6
            || dezSageSpecificLevel() != 24
            || dezSageExactingLevel() != 27
            || dezSageBookDieSides() != 6
            || dezSageBookCost() != 1000
            || dezSageResearchWeeksDieSides() != 3
            || dezSageResearchWeeksBonus() != 1
            || dezSageResearchCostPerWeek() != 100
            || dezSageEsotericSpellMinLevel() != 6
            || dezSageEsotericSpellMaxLevel() != 7
            || dezWizFocusBoostBase() != 18
            || dezWizFocusDurationPerLevel() != 1
            || dezWizFocusOtherScoresPenalty() != 2
            || dezWizFocusAttemptCost() != 2
            || dezWizSigItemCategoryCount() != 6
            || dezSculptFocusCostPerLevel() != 500
            || dezSculptDamageDice() != 2
            || dezSculptDurationMultiple() != 2
            || dezSculptRangeMultiple() != 2
            || dezSculptMinCastingTime() != 1
            || dezSculptFailDestroysRoll() != 20
            || dezSculptFireballBaseDice() != 10
            || dezSculptFireballSculptedDice() != 12
            || dezSculptBurningHandsBaseDice() != 1
            || dezSculptMagicMissileBaseDice() != 5
            || dezPriestAdvLimit() != 30
            || dezPriestSkillLevel() != 10
            || dezPriestTdStartLevel() != 20
            || dezT45RowCount() != 11
            || dezT45ClericXpStep() != 225000
            || dezT45DruidXpStep() != 500000
            || dezT45HpBase() != 9
            || dezT45HpStep() != 2
            || dezT47RowCount() != 11
            || dezQuestSpellLevel() != 20
            || dezImprovedTurningLevel() != 21
            || dezSpellSelectLevel1() != 21
            || dezSpellSelectLevel2() != 25
            || dezSpellSelectLevel3() != 27
            || dezWulfTurnLevel() != 21
            || dezWulfTurnRoll() != 7
            || dezWulfDestroyDiceCount() != 2
            || dezWulfDestroyMajorSides() != 6
            || dezWulfDestroyMinorSides() != 4
            || dezWulfVampireRollSides() != 6
            || dezWulfVampireRollResult() != 5
            || dezWulfVampires() != 6
            || dezWulfVampiresUnaffected() != 1
            || dezArmyMinLevel() != 21
            || dezArmyTroopsPerXp() != 1000
            || dezArmyExampleTroops() != 2925
            || dezArmyExamplePriestLevel() != 21
            || dezArmyExampleCommander() != 10
            || dezArmyExampleSubcommander() != 5
            || dezArmyExampleLieutenant() != 2
            || dezArmyExampleSergeant() != 1
            || dezArmyPaladinChance() != 10
            || dezArmyRangerChance() != 10
            || dezArmyGatherWeeksPer500() != 2
            || dezArmyDurationMonthsPerLevel() != 1
            || dezArmyTroopPayLow() != 2
            || dezArmyTroopPayHigh() != 4
            || dezArmyOfficerPayPerLevel() != 100
            || dezArmyExtensionDice() != 2
            || dezArmyExtensionDieSides() != 4
            || dezPriestFocusBoostBase() != 18
            || dezPriestFocusDurationPerLevel() != 1
            || dezPriestFocusOtherScoresPenalty() != 2
            || dezPriestFocusAttemptCost() != 2
            || dezVoiceRangeFeet() != 180
            || dezVoiceRockFeet() != 10
            || dezVoiceLeadInches() != 3
            || dezVoiceAutoEnthralHd() != 5
            || dezVoiceEnthralSpellLevel() != 2
            || dezVoiceHoldHours() != 1
            || dezVoiceMassSuggestionLevel() != 6
            || dezVoiceEminenceCost() != 2
            || dezVoiceEminenceDays() != 7
            || dezWillEminenceCost() != 2
            || dezWillEminenceDays() != 1
            || dezDeceiveRetryTurns() != 1
            || dezDeceiveEminenceCost() != 2
            || dezDeceiveEminenceDays() != 7
            || dezEminenceDurationPerLevel() != 1
            || dezEminenceReactionBonus() != 4
            || dezEminenceFearRadius() != 30
            || dezEminenceFleeLevel() != 4
            || dezEminenceCost() != 2
            || dezEminenceDays() != 7
            || dezInvDelayBase() != 5
            || dezInvHeroicFloor() != -20
            || dezInvConsciousAt() != -19
            || dezInvEminenceCost() != 2
            || dezInvMinorDays() != 1
            || dezInvSevereWeeks() != 1
            || dezInvExtremeMonths() != 1
            || dezInvExampleLevel() != 25
            || dezInvExampleHpLeft() != 52
            || dezInvExampleHpTotal() != 107
            || dezInvExampleDelay() != 10
            || dezInvExampleImmuneHp() != 60
            || dezInvExampleHealRound() != 4
            || dezInvExampleCon() != 15
            || dezInvExampleShockRoll() != 96
            || dezInvExampleShockMargin() != 6
            || dezInvVampireLevels() != 2
            || dezInvParalysisWeeks() != 1
            || dezInvNineWeeks() != 9
            || dezLoanHours() != 24
            || dezLoanBandCount() != 4
            || dezLoanCost() != 2
            || dezLoanDays() != 7
            || dezSmiteBodyDiameter() != 5
            || dezSmiteFarDiameter() != 30
            || dezSmiteLengthBase() != 30
            || dezSmiteLengthStep() != 20
            || dezSmiteAweSaveHd() != 10
            || dezSmiteAweExtraDieSides() != 8
            || dezSmiteBlindSaveHd() != 12
            || dezSmiteBlindMoveNum() != 2
            || dezSmiteBlindMoveDen() != 3
            || dezSmiteBlindPenalty() != 4
            || dezSmiteDeafMoveNum() != 3
            || dezSmiteDeafMoveDen() != 4
            || dezSmiteDeafPenalty() != 2
            || dezSmiteDeafSpellFailPct() != 50
            || dezSmiteBurnDice() != 6
            || dezSmiteBurnSides() != 8
            || dezSmiteDeathDice() != 12
            || dezSmiteDeathDustHd() != 4
            || dezSmiteImmobHd() != 6
            || dezSmiteImmobTurnsDice() != 1
            || dezSmiteImmobTurnsSides() != 4
            || dezSmiteImmobTurnsBonus() != 2
            || dezSmiteSlowHd() != 8
            || dezSmiteSlowSpellLevel() != 3
            || dezSmiteSlowTurnsDice() != 1
            || dezSmiteSlowTurnsSides() != 4
            || dezSmiteSlowTurnsBonus() != 2
            || dezSmiteEminenceCost() != 2
            || dezSmiteDays() != 7
            || dezSmiteMarissaEminence() != 4
            || dezSmiteMarissaBonus() != 4
            || dezSmiteMarissaRoll1() != 3
            || dezSmiteMarissaRoll2() != 18
            || dezSmiteMarissaAfterFirst() != -2
            || dezSmiteMarissaAfterSecond() != -4
            || dezTalReqLevel() != 12
            || dezTalBase() != 4
            || dezTalCostSlots() != 1
            || dezTalCostCp() != 3
            || dezTalCostPerLevel() != 100
            || dezTalHours() != 24
            || dezTalSeparateHours() != 1
            || dezTalInitBonus() != 2
            || dezWulfStoredTotal() != 21
            || dezWulfStored4th() != 2
            || dezWulfStored3rd() != 2
            || dezWulfStored1st() != 7
            || !dezT43ConBonusStopsAfter9()
            || !dezWizTenthLevelSpellsCount()
            || !dezWizIntroPhysicallyWeak()
            || !dezSageOneCategoryAlchemyOrChemistry()
            || !dezSageOtherCategoryPlayerOrDm()
            || !dezSageDifficultAnswersOtherRoutes()
            || !dezWizFocusIntWisDex()
            || !dezWizFocusOneBoostAtATime()
            || !dezWizFocusConcentrationRoundOnlyAction()
            || !dezWizFocusBoostEndsAtWill()
            || !dezWizFocusNoEffectIfEqualOrHigher()
            || !dezWizFocusSubabilitiesRaisedEqual()
            || !dezWizFocusBonusesImmediate()
            || !dezWizSigItemLikeWarriorSkill()
            || !dezWizSigItemOnePerType()
            || !dezSculptRequiresFocusItem()
            || !dezSculptFocusNotConsumed()
            || !dezSculptFailCastsNormally()
            || !dezSculptOnceOnly()
            || !dezSculptNoTouchOrZeroRange()
            || !dezSculptNoInstantaneousDuration()
            || !dezSculptLocalMultiplierFirst()
            || !dezSculptNoDicelessDamage()
            || !dezSculptIndividualDiceNotIncreased()
            || !dezSculptMetamagicAllowedIfNoDuplication()
            || !dezSculptFullCostPerSpell()
            || !dezSculptImprovementAllSpells()
            || !dezSculstRequirementsStillMet()
            || !dezAllPriestsCastTrueDweomers()
            || !dezPriestTdMightBeCalled8th()
            || !dezPriestTdUsesDivinePower()
            || !dezPriestTdMustPromoteDeityInterests()
            || !dezPriestTdRequiresGoodStanding()
            || !dezPriestTdSpherePortfolioLikelyGranted()
            || !dezPriestTdCheckSpheresWhenInDoubt()
            || !dezPriestsFormidableInCombat()
            || !dezT45ConBonusStopsAfter9()
            || !dezQuestSpellNoSacrifice()
            || !dezQuestSpellOtherRequirementsNormal()
            || !dezTurningRepeatWhileSuccessful()
            || !dezTurningStopsAfterFail()
            || !dezTurningMixedGroupUselessOnUnaffected()
            || !dezTurningWeakerContinueIfSucceed()
            || !dezWulfLichUnaffected()
            || !dezSpellSelectMinorOrLevelEitherWay()
            || !dezSpellSelectDmOrPlayerChooses()
            || !dezArmySingleTask()
            || !dezArmyTaskWithinAlignment()
            || !dezArmyOneAtATime()
            || !dezArmyOncePerYear()
            || !dezArmyOfficersHavePriests()
            || !dezArmyOpenWorshipRequired()
            || !dezArmyGatherDoubledIfUncommon()
            || !dezArmySmallerAllowed()
            || !dezArmyPayOrCharismaCheck()
            || !dezArmyGoalWithinReach()
            || !dezArmyDisbandIndependenceRisk()
            || !dezPriestFocusWisStrCha()
            || !dezPriestFocusNoBonusSpells()
            || !dezPriestFocusWis19Immunity()
            || !dezPriestFocusOneBoostAtATime()
            || !dezPriestFocusConcentrationRoundOnlyAction()
            || !dezPriestFocusBoostEndsAtWill()
            || !dezPriestFocusNoEffectIfHigher()
            || !dezPriestFocusSubabilitiesRaisedEqual()
            || !dezVoiceFullRoundSpeech()
            || !dezVoicePenetratesSilence()
            || !dezVoiceAntimagicShields()
            || !dezVoiceMagicalDeafnessBlocks()
            || !dezVoiceSaveVsSpellOthers()
            || !dezVoiceHearingOnlyRequired()
            || !dezVoiceUndeadAndCharmImmuneUnaffected()
            || !dezVoiceWis19Immune()
            || !dezVoiceJeeringBreaks()
            || !dezVoiceOneMassSuggestionPerUse()
            || !dezVoiceNoSaveIfBeforeEnthralEnds()
            || !dezVoiceAffectsAllEnthralled()
            || !dezVoiceIneffectiveAtZeroEminence()
            || !dezWillNegatesCompulsion()
            || !dezWillSaveOnFail()
            || !dezWillCoversAllCompulsions()
            || !dezWillEjectsMagicJarPsyche()
            || !dezWillIneffectiveAtZero()
            || !dezDeceiveSeesFalsehoods()
            || !dezDeceiveAutoSpokenFalsehoods()
            || !dezDeceiveKnowsEvasionVsLie()
            || !dezDeceiveNoTruthRevealed()
            || !dezDeceiveMagicSpeechUnheard()
            || !dezDeceiveImmediateSaveVsIllusion()
            || !dezDeceiveDmSecretRoll()
            || !dezDeceiveSeesMist()
            || !dezDeceiveWorksVsVisualSpells()
            || !dezDeceiveNotVsInvisibility()
            || !dezDeceiveDefeatsDisplacementBlending()
            || !dezDeceiveNotVsPhysicalChanges()
            || !dezDeceiveIneffectiveAtZero()
            || !dezEminenceAuraUndetectable()
            || !dezEminenceHaloByAlignment()
            || !dezEminenceFearAtWill()
            || !dezEminenceSaveForStronger()
            || !dezEminenceWorksVsFearImmune()
            || !dezEminenceCloakOrRemoveFearBreaks()
            || !dezEminenceSkillBreaks()
            || !dezEminenceOnceResistedImmuneRestOfDay()
            || !dezEminenceOpposingPriestShields()
            || !dezEminenceIneffectiveAtZero()
            || !dezEminencePrereqFiveSkills()
            || !dezEminenceDrainsBySkill()
            || !dezEminenceZeroBlocksAll()
            || !dezSmiteConnectedButUsableAtZero()
            || !dezInvLikeWarriorHardiness()
            || !dezInvSaveFirst()
            || !dezInvNoSimpleOrContinuingDamage()
            || !dezInvNoCharmsEntangleImprison()
            || !dezInvCureWithinDelayNoHarm()
            || !dezInvShorterDurationNoEffect()
            || !dezInvSystemShockAtEnd()
            || !dezInvShockSuccessHeals()
            || !dezInvShockFailFullForce()
            || !dezInvMultipleEffectsSequential()
            || !dezInvUnconsciousRecoversInstantly()
            || !dezInvHeroicRoundsEqualDelay()
            || !dezInvHeroicDeathAtDelayEnd()
            || !dezInvRaiseDuringDelaySaves()
            || !dezInvRegenNoShock()
            || !dezInvAmuletNoShock()
            || !dezInvIneffectiveAtZero()
            || !dezInvDrainRestOfDay()
            || !dezLoanTransfersVitality()
            || !dezLoanUnwillingNeedsAttackRoll()
            || !dezLoanLostLikeDamage()
            || !dezLoanDonorDiesIfInsufficient()
            || !dezLoanUselessAtZero()
            || !dezSmiteConeAnyDirection()
            || !dezSmiteDmChoosesEffect()
            || !dezSmiteOnlyEnemiesHarmed()
            || !dezSmiteAweDefault()
            || !dezSmiteAweDepiction()
            || !dezSmiteAweOneRoundEvenOnSave()
            || !dezSmiteAweRequiresMotionless()
            || !dezSmiteAweLatecomersSubject()
            || !dezSmiteAweMotionBreaks()
            || !dezSmiteAweDistractionBreaks()
            || !dezSmiteBlindTouchCastingOnly()
            || !dezSmiteBlindUntilHealed()
            || !dezSmiteBurnAshNoRegen()
            || !dezSmiteBurnEquipmentSaves()
            || !dezSmiteBurnHeatless()
            || !dezSmiteDeafUntilHealed()
            || !dezSmiteDeathDoubledBurn()
            || !dezSmiteImmobCrystalline()
            || !dezSmiteImmobSaveVsPetrification()
            || !dezSmiteImmobFreeActionUseless()
            || !dezSmiteImmobShatterKill()
            || !dezSmitePlagueDebilitating()
            || !dezSmitePlagueNotContagiousOrFatal()
            || !dezSmitePlagueHigherLevelCure()
            || !dezSmitePlagueWhenOffensive()
            || !dezSmiteSlowWhenNoImmediateThreat()
            || !dezSmiteNoRollWithPositiveEminence()
            || !dezSmiteCheckAtZeroOrLess()
            || !dezSmiteFailDispleasesDeity()
            || !dezSmiteFailMaySmitePriest()
            || !dezSmiteMarissaAweBrokenByAttack()
            || !dezTalCastAtDayStart()
            || !dezTalSmallObject()
            || !dezTalRollToPlace()
            || !dezTalFailWastesSpell()
            || !dezTalComponentsRequired()
            || !dezTalCastingEffectsOnFail()
            || !dezTalTotalCappedAtLevel()
            || !dezTalCapSharedLadder()
            || !dezTalReleaseRequiresContact()
            || !dezTalReleaseUndisruptable()
            || !dezTalGaggedOrSilencedBlocks()
            || !dezTalDestroysTalisman()
            || !dezTalOnlyStorerReleases()
            || !dezTalNoRememorizeBefore24h()
            || !dezTalNoTransferBack()
            || !dezTalDestroyedSpellLost()
            || !dezTalFadesOnReleaseOrLoss()
            || !dezTalCastsWhereFactorDisallows()
            || !dezTalStoreNeedsLocalConditions()
            || !dezTalInitUnaffectedByFactor()
        )
            ++bad;
        // the dezT43Grid grid
        int CT43[11][5] = {
            {3750000,4,10,10,10},
            {4125000,4,11,10,11},
            {4500000,5,11,10,12},
            {4875000,5,11,10,13},
            {5250000,5,12,10,14},
            {5625000,5,12,10,15},
            {6000000,5,12,10,16},
            {6375000,6,13,10,17},
            {6750000,6,13,10,18},
            {7125000,6,13,10,19},
            {7500000,6,14,10,20},
            };
        for (int b = 0;
             b < dezT43RowCount();
             ++b) {
            int vals[5];
            vals[0] = dezT43Xp(b);
            vals[1] = dezT43WeaponProf(b);
            vals[2] = dezT43NonweaponProf(b);
            vals[3] = dezT43HpBaseCol(b);
            vals[4] = dezT43HpBonus(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CT43[b][c])
                    ++bad;
            }
        }
        // the dezT44Grid grid
        int CT44[11][10] = {
            {5,5,5,5,5,4,3,3,2,1},
            {5,5,5,5,5,4,4,4,2,1},
            {5,5,5,5,5,5,4,4,3,1},
            {5,5,5,5,5,5,5,5,3,2},
            {5,5,5,5,5,5,5,5,4,2},
            {5,5,5,5,5,5,5,5,5,2},
            {6,6,6,6,5,5,5,5,5,3},
            {6,6,6,6,6,6,6,5,5,3},
            {6,6,6,6,6,6,6,6,6,3},
            {7,7,7,7,6,6,6,6,6,4},
            {7,7,7,7,7,7,7,6,6,4},
            };
        for (int b = 0;
             b < dezT44RowCount();
             ++b) {
            int vals[10];
            vals[0] = dezT44L1(b);
            vals[1] = dezT44L2(b);
            vals[2] = dezT44L3(b);
            vals[3] = dezT44L4(b);
            vals[4] = dezT44L5(b);
            vals[5] = dezT44L6(b);
            vals[6] = dezT44L7(b);
            vals[7] = dezT44L8(b);
            vals[8] = dezT44L9(b);
            vals[9] = dezT44L10(b);
            for (int c = 0; c < 10;
                 ++c) {
                if (vals[c] != CT44[b][c])
                    ++bad;
            }
        }
        // the dezT45Grid grid
        int CT45[11][6] = {
            {2700000,2000000,7,10,9,22},
            {2925000,2500000,7,11,9,24},
            {3150000,3000000,7,11,9,26},
            {3375000,3500000,7,11,9,28},
            {3600000,4000000,8,12,9,30},
            {3825000,4500000,8,12,9,32},
            {4050000,5000000,8,12,9,34},
            {4275000,5500000,8,13,9,36},
            {4500000,6000000,9,13,9,38},
            {4725000,6500000,9,13,9,40},
            {4950000,7000000,9,14,9,42},
            };
        for (int b = 0;
             b < dezT45RowCount();
             ++b) {
            int vals[6];
            vals[0] = dezT45ClericXp(b);
            vals[1] = dezT45DruidXp(b);
            vals[2] = dezT45WeaponProf(b);
            vals[3] = dezT45NonweaponProf(b);
            vals[4] = dezT45HpBaseCol(b);
            vals[5] = dezT45HpBonus(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CT45[b][c])
                    ++bad;
            }
        }
        // the dezT47Grid grid
        int CT47[11][8] = {
            {9,9,9,8,7,5,2,1},
            {9,9,9,9,8,6,2,1},
            {9,9,9,9,9,6,3,2},
            {9,9,9,9,9,7,3,2},
            {9,9,9,9,9,8,3,2},
            {9,9,9,9,9,8,4,3},
            {9,9,9,9,9,9,4,3},
            {9,9,9,9,9,9,5,4},
            {9,9,9,9,9,9,6,4},
            {9,9,9,9,9,9,7,4},
            {9,9,9,9,9,9,8,4},
            };
        for (int b = 0;
             b < dezT47RowCount();
             ++b) {
            int vals[8];
            vals[0] = dezT47L1(b);
            vals[1] = dezT47L2(b);
            vals[2] = dezT47L3(b);
            vals[3] = dezT47L4(b);
            vals[4] = dezT47L5(b);
            vals[5] = dezT47L6(b);
            vals[6] = dezT47L7(b);
            vals[7] = dezT47Td(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != CT47[b][c])
                    ++bad;
            }
        }
        // the dezLoanGrid grid
        int CTLN[4][3] = {
            {1,8,2},
            {2,6,4},
            {3,6,6},
            {4,6,8},
            };
        for (int b = 0;
             b < dezLoanBandCount();
             ++b) {
            int vals[3];
            vals[0] = dezLoanDice(b);
            vals[1] = dezLoanSides(b);
            vals[2] = dezLoanBonus(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CTLN[b][c])
                    ++bad;
            }
        }
        // the dezWizFocusBand band-for boundaries
    if (dezWizFocusBand(15) != 0
            || dezWizFocusBand(16) != 0
            || dezWizFocusBand(20) != 1
            || dezWizFocusBand(17) != 1
            || dezWizFocusBand(25) != 2
            || dezWizFocusBand(21) != 2
            || dezWizFocusBand(29) != 3
            || dezWizFocusBand(26) != 3
            || dezWizFocusBand(30) != 4
        )
            ++bad;
        // the dezSpellCapBand band-for boundaries
    if (dezSpellCapBand(13) != 0
            || dezSpellCapBand(14) != 0
            || dezSpellCapBand(17) != 1
            || dezSpellCapBand(15) != 1
            || dezSpellCapBand(20) != 2
            || dezSpellCapBand(18) != 2
            || dezSpellCapBand(23) != 3
            || dezSpellCapBand(21) != 3
            || dezSpellCapBand(26) != 4
            || dezSpellCapBand(24) != 4
            || dezSpellCapBand(29) != 5
            || dezSpellCapBand(27) != 5
            || dezSpellCapBand(30) != 6
        )
            ++bad;
        // the dezPriestFocusBand band-for boundaries
    if (dezPriestFocusBand(13) != 0
            || dezPriestFocusBand(14) != 0
            || dezPriestFocusBand(19) != 1
            || dezPriestFocusBand(15) != 1
            || dezPriestFocusBand(24) != 2
            || dezPriestFocusBand(20) != 2
            || dezPriestFocusBand(29) != 3
            || dezPriestFocusBand(25) != 3
            || dezPriestFocusBand(30) != 4
        )
            ++bad;
        // the dezDeceiveDurationBand band-for boundaries
    if (dezDeceiveDurationBand(16) != 0
            || dezDeceiveDurationBand(17) != 0
            || dezDeceiveDurationBand(20) != 1
            || dezDeceiveDurationBand(18) != 1
            || dezDeceiveDurationBand(23) != 2
            || dezDeceiveDurationBand(21) != 2
            || dezDeceiveDurationBand(26) != 3
            || dezDeceiveDurationBand(24) != 3
            || dezDeceiveDurationBand(27) != 4
        )
            ++bad;
        // the dezInvDelayBand band-for boundaries
    if (dezInvDelayBand(22) != 0
            || dezInvDelayBand(23) != 0
            || dezInvDelayBand(26) != 1
            || dezInvDelayBand(24) != 1
            || dezInvDelayBand(27) != 2
        )
            ++bad;
        // the dezLoanBand band-for boundaries
    if (dezLoanBand(18) != 0
            || dezLoanBand(19) != 0
            || dezLoanBand(24) != 1
            || dezLoanBand(20) != 1
            || dezLoanBand(29) != 2
            || dezLoanBand(25) != 2
            || dezLoanBand(30) != 3
        )
            ++bad;
        // the dezSmiteConeBand band-for boundaries
    if (dezSmiteConeBand(19) != 0
            || dezSmiteConeBand(20) != 0
            || dezSmiteConeBand(23) != 1
            || dezSmiteConeBand(21) != 1
            || dezSmiteConeBand(26) != 2
            || dezSmiteConeBand(24) != 2
            || dezSmiteConeBand(29) != 3
            || dezSmiteConeBand(27) != 3
            || dezSmiteConeBand(30) != 4
        )
            ++bad;
        // the dezWizAdvLimit pin
    if (dezWizAdvLimit() != 30
        )
            ++bad;
        // the dezWizSkillPauseLevel pin
    if (dezWizSkillPauseLevel() != 20
        )
            ++bad;
        // the dezT43RowCount pin
    if (dezT43RowCount() != 11
        )
            ++bad;
        // the dezT43XpStep pin
    if (dezT43XpStep() != 375000
        )
            ++bad;
        // the dezT43HpBase pin
    if (dezT43HpBase() != 10
        )
            ++bad;
        // the dezT44RowCount pin
    if (dezT44RowCount() != 11
        )
            ++bad;
        // the dezSageStartLevel pin
    if (dezSageStartLevel() != 21
        )
            ++bad;
        // the dezSageCategoryCount pin
    if (dezSageCategoryCount() != 2
        )
            ++bad;
        // the dezSageBaseChance pin
    if (dezSageBaseChance() != 6
        )
            ++bad;
        // the dezSageSpecificLevel pin
    if (dezSageSpecificLevel() != 24
        )
            ++bad;
        // the dezSageExactingLevel pin
    if (dezSageExactingLevel() != 27
        )
            ++bad;
        // the dezSageBookDieSides pin
    if (dezSageBookDieSides() != 6
        )
            ++bad;
        // the dezSageBookCost pin
    if (dezSageBookCost() != 1000
        )
            ++bad;
        // the dezSageResearchWeeksDieSides pin
    if (dezSageResearchWeeksDieSides() != 3
        )
            ++bad;
        // the dezSageResearchWeeksBonus pin
    if (dezSageResearchWeeksBonus() != 1
        )
            ++bad;
        // the dezSageResearchCostPerWeek pin
    if (dezSageResearchCostPerWeek() != 100
        )
            ++bad;
        // the dezSageEsotericSpellMinLevel pin
    if (dezSageEsotericSpellMinLevel() != 6
        )
            ++bad;
        // the dezSageEsotericSpellMaxLevel pin
    if (dezSageEsotericSpellMaxLevel() != 7
        )
            ++bad;
        // the dezWizFocusBoostBase pin
    if (dezWizFocusBoostBase() != 18
        )
            ++bad;
        // the dezWizFocusDurationPerLevel pin
    if (dezWizFocusDurationPerLevel() != 1
        )
            ++bad;
        // the dezWizFocusOtherScoresPenalty pin
    if (dezWizFocusOtherScoresPenalty() != 2
        )
            ++bad;
        // the dezWizFocusAttemptCost pin
    if (dezWizFocusAttemptCost() != 2
        )
            ++bad;
        // the dezWizSigItemCategoryCount pin
    if (dezWizSigItemCategoryCount() != 6
        )
            ++bad;
        // the dezSculptFocusCostPerLevel pin
    if (dezSculptFocusCostPerLevel() != 500
        )
            ++bad;
        // the dezSculptDamageDice pin
    if (dezSculptDamageDice() != 2
        )
            ++bad;
        // the dezSculptDurationMultiple pin
    if (dezSculptDurationMultiple() != 2
        )
            ++bad;
        // the dezSculptRangeMultiple pin
    if (dezSculptRangeMultiple() != 2
        )
            ++bad;
        // the dezSculptMinCastingTime pin
    if (dezSculptMinCastingTime() != 1
        )
            ++bad;
        // the dezSculptFailDestroysRoll pin
    if (dezSculptFailDestroysRoll() != 20
        )
            ++bad;
        // the dezSculptFireballBaseDice pin
    if (dezSculptFireballBaseDice() != 10
        )
            ++bad;
        // the dezSculptFireballSculptedDice pin
    if (dezSculptFireballSculptedDice() != 12
        )
            ++bad;
        // the dezSculptBurningHandsBaseDice pin
    if (dezSculptBurningHandsBaseDice() != 1
        )
            ++bad;
        // the dezSculptMagicMissileBaseDice pin
    if (dezSculptMagicMissileBaseDice() != 5
        )
            ++bad;
        // the dezPriestAdvLimit pin
    if (dezPriestAdvLimit() != 30
        )
            ++bad;
        // the dezPriestSkillLevel pin
    if (dezPriestSkillLevel() != 10
        )
            ++bad;
        // the dezPriestTdStartLevel pin
    if (dezPriestTdStartLevel() != 20
        )
            ++bad;
        // the dezT45RowCount pin
    if (dezT45RowCount() != 11
        )
            ++bad;
        // the dezT45ClericXpStep pin
    if (dezT45ClericXpStep() != 225000
        )
            ++bad;
        // the dezT45DruidXpStep pin
    if (dezT45DruidXpStep() != 500000
        )
            ++bad;
        // the dezT45HpBase pin
    if (dezT45HpBase() != 9
        )
            ++bad;
        // the dezT45HpStep pin
    if (dezT45HpStep() != 2
        )
            ++bad;
        // the dezT47RowCount pin
    if (dezT47RowCount() != 11
        )
            ++bad;
        // the dezQuestSpellLevel pin
    if (dezQuestSpellLevel() != 20
        )
            ++bad;
        // the dezImprovedTurningLevel pin
    if (dezImprovedTurningLevel() != 21
        )
            ++bad;
        // the dezSpellSelectLevel1 pin
    if (dezSpellSelectLevel1() != 21
        )
            ++bad;
        // the dezSpellSelectLevel2 pin
    if (dezSpellSelectLevel2() != 25
        )
            ++bad;
        // the dezSpellSelectLevel3 pin
    if (dezSpellSelectLevel3() != 27
        )
            ++bad;
        // the dezWulfTurnLevel pin
    if (dezWulfTurnLevel() != 21
        )
            ++bad;
        // the dezWulfTurnRoll pin
    if (dezWulfTurnRoll() != 7
        )
            ++bad;
        // the dezWulfDestroyDiceCount pin
    if (dezWulfDestroyDiceCount() != 2
        )
            ++bad;
        // the dezWulfDestroyMajorSides pin
    if (dezWulfDestroyMajorSides() != 6
        )
            ++bad;
        // the dezWulfDestroyMinorSides pin
    if (dezWulfDestroyMinorSides() != 4
        )
            ++bad;
        // the dezWulfVampireRollSides pin
    if (dezWulfVampireRollSides() != 6
        )
            ++bad;
        // the dezWulfVampireRollResult pin
    if (dezWulfVampireRollResult() != 5
        )
            ++bad;
        // the dezWulfVampires pin
    if (dezWulfVampires() != 6
        )
            ++bad;
        // the dezWulfVampiresUnaffected pin
    if (dezWulfVampiresUnaffected() != 1
        )
            ++bad;
        // the dezArmyMinLevel pin
    if (dezArmyMinLevel() != 21
        )
            ++bad;
        // the dezArmyTroopsPerXp pin
    if (dezArmyTroopsPerXp() != 1000
        )
            ++bad;
        // the dezArmyExampleTroops pin
    if (dezArmyExampleTroops() != 2925
        )
            ++bad;
        // the dezArmyExamplePriestLevel pin
    if (dezArmyExamplePriestLevel() != 21
        )
            ++bad;
        // the dezArmyExampleCommander pin
    if (dezArmyExampleCommander() != 10
        )
            ++bad;
        // the dezArmyExampleSubcommander pin
    if (dezArmyExampleSubcommander() != 5
        )
            ++bad;
        // the dezArmyExampleLieutenant pin
    if (dezArmyExampleLieutenant() != 2
        )
            ++bad;
        // the dezArmyExampleSergeant pin
    if (dezArmyExampleSergeant() != 1
        )
            ++bad;
        // the dezArmyPaladinChance pin
    if (dezArmyPaladinChance() != 10
        )
            ++bad;
        // the dezArmyRangerChance pin
    if (dezArmyRangerChance() != 10
        )
            ++bad;
        // the dezArmyGatherWeeksPer500 pin
    if (dezArmyGatherWeeksPer500() != 2
        )
            ++bad;
        // the dezArmyDurationMonthsPerLevel pin
    if (dezArmyDurationMonthsPerLevel() != 1
        )
            ++bad;
        // the dezArmyTroopPayLow pin
    if (dezArmyTroopPayLow() != 2
        )
            ++bad;
        // the dezArmyTroopPayHigh pin
    if (dezArmyTroopPayHigh() != 4
        )
            ++bad;
        // the dezArmyOfficerPayPerLevel pin
    if (dezArmyOfficerPayPerLevel() != 100
        )
            ++bad;
        // the dezArmyExtensionDice pin
    if (dezArmyExtensionDice() != 2
        )
            ++bad;
        // the dezArmyExtensionDieSides pin
    if (dezArmyExtensionDieSides() != 4
        )
            ++bad;
        // the dezPriestFocusBoostBase pin
    if (dezPriestFocusBoostBase() != 18
        )
            ++bad;
        // the dezPriestFocusDurationPerLevel pin
    if (dezPriestFocusDurationPerLevel() != 1
        )
            ++bad;
        // the dezPriestFocusOtherScoresPenalty pin
    if (dezPriestFocusOtherScoresPenalty() != 2
        )
            ++bad;
        // the dezPriestFocusAttemptCost pin
    if (dezPriestFocusAttemptCost() != 2
        )
            ++bad;
        // the dezVoiceRangeFeet pin
    if (dezVoiceRangeFeet() != 180
        )
            ++bad;
        // the dezVoiceRockFeet pin
    if (dezVoiceRockFeet() != 10
        )
            ++bad;
        // the dezVoiceLeadInches pin
    if (dezVoiceLeadInches() != 3
        )
            ++bad;
        // the dezVoiceAutoEnthralHd pin
    if (dezVoiceAutoEnthralHd() != 5
        )
            ++bad;
        // the dezVoiceEnthralSpellLevel pin
    if (dezVoiceEnthralSpellLevel() != 2
        )
            ++bad;
        // the dezVoiceHoldHours pin
    if (dezVoiceHoldHours() != 1
        )
            ++bad;
        // the dezVoiceMassSuggestionLevel pin
    if (dezVoiceMassSuggestionLevel() != 6
        )
            ++bad;
        // the dezVoiceEminenceCost pin
    if (dezVoiceEminenceCost() != 2
        )
            ++bad;
        // the dezVoiceEminenceDays pin
    if (dezVoiceEminenceDays() != 7
        )
            ++bad;
        // the dezWillEminenceCost pin
    if (dezWillEminenceCost() != 2
        )
            ++bad;
        // the dezWillEminenceDays pin
    if (dezWillEminenceDays() != 1
        )
            ++bad;
        // the dezDeceiveRetryTurns pin
    if (dezDeceiveRetryTurns() != 1
        )
            ++bad;
        // the dezDeceiveEminenceCost pin
    if (dezDeceiveEminenceCost() != 2
        )
            ++bad;
        // the dezDeceiveEminenceDays pin
    if (dezDeceiveEminenceDays() != 7
        )
            ++bad;
        // the dezEminenceDurationPerLevel pin
    if (dezEminenceDurationPerLevel() != 1
        )
            ++bad;
        // the dezEminenceReactionBonus pin
    if (dezEminenceReactionBonus() != 4
        )
            ++bad;
        // the dezEminenceFearRadius pin
    if (dezEminenceFearRadius() != 30
        )
            ++bad;
        // the dezEminenceFleeLevel pin
    if (dezEminenceFleeLevel() != 4
        )
            ++bad;
        // the dezEminenceCost pin
    if (dezEminenceCost() != 2
        )
            ++bad;
        // the dezEminenceDays pin
    if (dezEminenceDays() != 7
        )
            ++bad;
        // the dezInvDelayBase pin
    if (dezInvDelayBase() != 5
        )
            ++bad;
        // the dezInvHeroicFloor pin
    if (dezInvHeroicFloor() != -20
        )
            ++bad;
        // the dezInvConsciousAt pin
    if (dezInvConsciousAt() != -19
        )
            ++bad;
        // the dezInvEminenceCost pin
    if (dezInvEminenceCost() != 2
        )
            ++bad;
        // the dezInvMinorDays pin
    if (dezInvMinorDays() != 1
        )
            ++bad;
        // the dezInvSevereWeeks pin
    if (dezInvSevereWeeks() != 1
        )
            ++bad;
        // the dezInvExtremeMonths pin
    if (dezInvExtremeMonths() != 1
        )
            ++bad;
        // the dezInvExampleLevel pin
    if (dezInvExampleLevel() != 25
        )
            ++bad;
        // the dezInvExampleHpLeft pin
    if (dezInvExampleHpLeft() != 52
        )
            ++bad;
        // the dezInvExampleHpTotal pin
    if (dezInvExampleHpTotal() != 107
        )
            ++bad;
        // the dezInvExampleDelay pin
    if (dezInvExampleDelay() != 10
        )
            ++bad;
        // the dezInvExampleImmuneHp pin
    if (dezInvExampleImmuneHp() != 60
        )
            ++bad;
        // the dezInvExampleHealRound pin
    if (dezInvExampleHealRound() != 4
        )
            ++bad;
        // the dezInvExampleCon pin
    if (dezInvExampleCon() != 15
        )
            ++bad;
        // the dezInvExampleShockRoll pin
    if (dezInvExampleShockRoll() != 96
        )
            ++bad;
        // the dezInvExampleShockMargin pin
    if (dezInvExampleShockMargin() != 6
        )
            ++bad;
        // the dezInvVampireLevels pin
    if (dezInvVampireLevels() != 2
        )
            ++bad;
        // the dezInvParalysisWeeks pin
    if (dezInvParalysisWeeks() != 1
        )
            ++bad;
        // the dezInvNineWeeks pin
    if (dezInvNineWeeks() != 9
        )
            ++bad;
        // the dezLoanHours pin
    if (dezLoanHours() != 24
        )
            ++bad;
        // the dezLoanBandCount pin
    if (dezLoanBandCount() != 4
        )
            ++bad;
        // the dezLoanCost pin
    if (dezLoanCost() != 2
        )
            ++bad;
        // the dezLoanDays pin
    if (dezLoanDays() != 7
        )
            ++bad;
        // the dezSmiteBodyDiameter pin
    if (dezSmiteBodyDiameter() != 5
        )
            ++bad;
        // the dezSmiteFarDiameter pin
    if (dezSmiteFarDiameter() != 30
        )
            ++bad;
        // the dezSmiteLengthBase pin
    if (dezSmiteLengthBase() != 30
        )
            ++bad;
        // the dezSmiteLengthStep pin
    if (dezSmiteLengthStep() != 20
        )
            ++bad;
        // the dezSmiteAweSaveHd pin
    if (dezSmiteAweSaveHd() != 10
        )
            ++bad;
        // the dezSmiteAweExtraDieSides pin
    if (dezSmiteAweExtraDieSides() != 8
        )
            ++bad;
        // the dezSmiteBlindSaveHd pin
    if (dezSmiteBlindSaveHd() != 12
        )
            ++bad;
        // the dezSmiteBlindMoveNum pin
    if (dezSmiteBlindMoveNum() != 2
        )
            ++bad;
        // the dezSmiteBlindMoveDen pin
    if (dezSmiteBlindMoveDen() != 3
        )
            ++bad;
        // the dezSmiteBlindPenalty pin
    if (dezSmiteBlindPenalty() != 4
        )
            ++bad;
        // the dezSmiteDeafMoveNum pin
    if (dezSmiteDeafMoveNum() != 3
        )
            ++bad;
        // the dezSmiteDeafMoveDen pin
    if (dezSmiteDeafMoveDen() != 4
        )
            ++bad;
        // the dezSmiteDeafPenalty pin
    if (dezSmiteDeafPenalty() != 2
        )
            ++bad;
        // the dezSmiteDeafSpellFailPct pin
    if (dezSmiteDeafSpellFailPct() != 50
        )
            ++bad;
        // the dezSmiteBurnDice pin
    if (dezSmiteBurnDice() != 6
        )
            ++bad;
        // the dezSmiteBurnSides pin
    if (dezSmiteBurnSides() != 8
        )
            ++bad;
        // the dezSmiteDeathDice pin
    if (dezSmiteDeathDice() != 12
        )
            ++bad;
        // the dezSmiteDeathDustHd pin
    if (dezSmiteDeathDustHd() != 4
        )
            ++bad;
        // the dezSmiteImmobHd pin
    if (dezSmiteImmobHd() != 6
        )
            ++bad;
        // the dezSmiteImmobTurnsDice pin
    if (dezSmiteImmobTurnsDice() != 1
        )
            ++bad;
        // the dezSmiteImmobTurnsSides pin
    if (dezSmiteImmobTurnsSides() != 4
        )
            ++bad;
        // the dezSmiteImmobTurnsBonus pin
    if (dezSmiteImmobTurnsBonus() != 2
        )
            ++bad;
        // the dezSmiteSlowHd pin
    if (dezSmiteSlowHd() != 8
        )
            ++bad;
        // the dezSmiteSlowSpellLevel pin
    if (dezSmiteSlowSpellLevel() != 3
        )
            ++bad;
        // the dezSmiteSlowTurnsDice pin
    if (dezSmiteSlowTurnsDice() != 1
        )
            ++bad;
        // the dezSmiteSlowTurnsSides pin
    if (dezSmiteSlowTurnsSides() != 4
        )
            ++bad;
        // the dezSmiteSlowTurnsBonus pin
    if (dezSmiteSlowTurnsBonus() != 2
        )
            ++bad;
        // the dezSmiteEminenceCost pin
    if (dezSmiteEminenceCost() != 2
        )
            ++bad;
        // the dezSmiteDays pin
    if (dezSmiteDays() != 7
        )
            ++bad;
        // the dezSmiteMarissaEminence pin
    if (dezSmiteMarissaEminence() != 4
        )
            ++bad;
        // the dezSmiteMarissaBonus pin
    if (dezSmiteMarissaBonus() != 4
        )
            ++bad;
        // the dezSmiteMarissaRoll1 pin
    if (dezSmiteMarissaRoll1() != 3
        )
            ++bad;
        // the dezSmiteMarissaRoll2 pin
    if (dezSmiteMarissaRoll2() != 18
        )
            ++bad;
        // the dezSmiteMarissaAfterFirst pin
    if (dezSmiteMarissaAfterFirst() != -2
        )
            ++bad;
        // the dezSmiteMarissaAfterSecond pin
    if (dezSmiteMarissaAfterSecond() != -4
        )
            ++bad;
        // the dezTalReqLevel pin
    if (dezTalReqLevel() != 12
        )
            ++bad;
        // the dezTalBase pin
    if (dezTalBase() != 4
        )
            ++bad;
        // the dezTalCostSlots pin
    if (dezTalCostSlots() != 1
        )
            ++bad;
        // the dezTalCostCp pin
    if (dezTalCostCp() != 3
        )
            ++bad;
        // the dezTalCostPerLevel pin
    if (dezTalCostPerLevel() != 100
        )
            ++bad;
        // the dezTalHours pin
    if (dezTalHours() != 24
        )
            ++bad;
        // the dezTalSeparateHours pin
    if (dezTalSeparateHours() != 1
        )
            ++bad;
        // the dezTalInitBonus pin
    if (dezTalInitBonus() != 2
        )
            ++bad;
        // the dezWulfStoredTotal pin
    if (dezWulfStoredTotal() != 21
        )
            ++bad;
        // the dezWulfStored4th pin
    if (dezWulfStored4th() != 2
        )
            ++bad;
        // the dezWulfStored3rd pin
    if (dezWulfStored3rd() != 2
        )
            ++bad;
        // the dezWulfStored1st pin
    if (dezWulfStored1st() != 7
        )
            ++bad;
        // the dezT43ConBonusStopsAfter9 pin
    if (dezT43ConBonusStopsAfter9() != 1
        )
            ++bad;
        // the dezWizTenthLevelSpellsCount pin
    if (dezWizTenthLevelSpellsCount() != 1
        )
            ++bad;
        // the dezWizIntroPhysicallyWeak pin
    if (dezWizIntroPhysicallyWeak() != 1
        )
            ++bad;
        // the dezSageOneCategoryAlchemyOrChemistry pin
    if (dezSageOneCategoryAlchemyOrChemistry() != 1
        )
            ++bad;
        // the dezSageOtherCategoryPlayerOrDm pin
    if (dezSageOtherCategoryPlayerOrDm() != 1
        )
            ++bad;
        // the dezSageDifficultAnswersOtherRoutes pin
    if (dezSageDifficultAnswersOtherRoutes() != 1
        )
            ++bad;
        // the dezWizFocusIntWisDex pin
    if (dezWizFocusIntWisDex() != 1
        )
            ++bad;
        // the dezWizFocusOneBoostAtATime pin
    if (dezWizFocusOneBoostAtATime() != 1
        )
            ++bad;
        // the dezWizFocusConcentrationRoundOnlyAction pin
    if (dezWizFocusConcentrationRoundOnlyAction() != 1
        )
            ++bad;
        // the dezWizFocusBoostEndsAtWill pin
    if (dezWizFocusBoostEndsAtWill() != 1
        )
            ++bad;
        // the dezWizFocusNoEffectIfEqualOrHigher pin
    if (dezWizFocusNoEffectIfEqualOrHigher() != 1
        )
            ++bad;
        // the dezWizFocusSubabilitiesRaisedEqual pin
    if (dezWizFocusSubabilitiesRaisedEqual() != 1
        )
            ++bad;
        // the dezWizFocusBonusesImmediate pin
    if (dezWizFocusBonusesImmediate() != 1
        )
            ++bad;
        // the dezWizSigItemLikeWarriorSkill pin
    if (dezWizSigItemLikeWarriorSkill() != 1
        )
            ++bad;
        // the dezWizSigItemOnePerType pin
    if (dezWizSigItemOnePerType() != 1
        )
            ++bad;
        // the dezSculptRequiresFocusItem pin
    if (dezSculptRequiresFocusItem() != 1
        )
            ++bad;
        // the dezSculptFocusNotConsumed pin
    if (dezSculptFocusNotConsumed() != 1
        )
            ++bad;
        // the dezSculptFailCastsNormally pin
    if (dezSculptFailCastsNormally() != 1
        )
            ++bad;
        // the dezSculptOnceOnly pin
    if (dezSculptOnceOnly() != 1
        )
            ++bad;
        // the dezSculptNoTouchOrZeroRange pin
    if (dezSculptNoTouchOrZeroRange() != 1
        )
            ++bad;
        // the dezSculptNoInstantaneousDuration pin
    if (dezSculptNoInstantaneousDuration() != 1
        )
            ++bad;
        // the dezSculptLocalMultiplierFirst pin
    if (dezSculptLocalMultiplierFirst() != 1
        )
            ++bad;
        // the dezSculptNoDicelessDamage pin
    if (dezSculptNoDicelessDamage() != 1
        )
            ++bad;
        // the dezSculptIndividualDiceNotIncreased pin
    if (dezSculptIndividualDiceNotIncreased() != 1
        )
            ++bad;
        // the dezSculptMetamagicAllowedIfNoDuplication pin
    if (dezSculptMetamagicAllowedIfNoDuplication() != 1
        )
            ++bad;
        // the dezSculptFullCostPerSpell pin
    if (dezSculptFullCostPerSpell() != 1
        )
            ++bad;
        // the dezSculptImprovementAllSpells pin
    if (dezSculptImprovementAllSpells() != 1
        )
            ++bad;
        // the dezSculstRequirementsStillMet pin
    if (dezSculstRequirementsStillMet() != 1
        )
            ++bad;
        // the dezAllPriestsCastTrueDweomers pin
    if (dezAllPriestsCastTrueDweomers() != 1
        )
            ++bad;
        // the dezPriestTdMightBeCalled8th pin
    if (dezPriestTdMightBeCalled8th() != 1
        )
            ++bad;
        // the dezPriestTdUsesDivinePower pin
    if (dezPriestTdUsesDivinePower() != 1
        )
            ++bad;
        // the dezPriestTdMustPromoteDeityInterests pin
    if (dezPriestTdMustPromoteDeityInterests() != 1
        )
            ++bad;
        // the dezPriestTdRequiresGoodStanding pin
    if (dezPriestTdRequiresGoodStanding() != 1
        )
            ++bad;
        // the dezPriestTdSpherePortfolioLikelyGranted pin
    if (dezPriestTdSpherePortfolioLikelyGranted() != 1
        )
            ++bad;
        // the dezPriestTdCheckSpheresWhenInDoubt pin
    if (dezPriestTdCheckSpheresWhenInDoubt() != 1
        )
            ++bad;
        // the dezPriestsFormidableInCombat pin
    if (dezPriestsFormidableInCombat() != 1
        )
            ++bad;
        // the dezT45ConBonusStopsAfter9 pin
    if (dezT45ConBonusStopsAfter9() != 1
        )
            ++bad;
        // the dezQuestSpellNoSacrifice pin
    if (dezQuestSpellNoSacrifice() != 1
        )
            ++bad;
        // the dezQuestSpellOtherRequirementsNormal pin
    if (dezQuestSpellOtherRequirementsNormal() != 1
        )
            ++bad;
        // the dezTurningRepeatWhileSuccessful pin
    if (dezTurningRepeatWhileSuccessful() != 1
        )
            ++bad;
        // the dezTurningStopsAfterFail pin
    if (dezTurningStopsAfterFail() != 1
        )
            ++bad;
        // the dezTurningMixedGroupUselessOnUnaffected pin
    if (dezTurningMixedGroupUselessOnUnaffected() != 1
        )
            ++bad;
        // the dezTurningWeakerContinueIfSucceed pin
    if (dezTurningWeakerContinueIfSucceed() != 1
        )
            ++bad;
        // the dezWulfLichUnaffected pin
    if (dezWulfLichUnaffected() != 1
        )
            ++bad;
        // the dezSpellSelectMinorOrLevelEitherWay pin
    if (dezSpellSelectMinorOrLevelEitherWay() != 1
        )
            ++bad;
        // the dezSpellSelectDmOrPlayerChooses pin
    if (dezSpellSelectDmOrPlayerChooses() != 1
        )
            ++bad;
        // the dezArmySingleTask pin
    if (dezArmySingleTask() != 1
        )
            ++bad;
        // the dezArmyTaskWithinAlignment pin
    if (dezArmyTaskWithinAlignment() != 1
        )
            ++bad;
        // the dezArmyOneAtATime pin
    if (dezArmyOneAtATime() != 1
        )
            ++bad;
        // the dezArmyOncePerYear pin
    if (dezArmyOncePerYear() != 1
        )
            ++bad;
        // the dezArmyOfficersHavePriests pin
    if (dezArmyOfficersHavePriests() != 1
        )
            ++bad;
        // the dezArmyOpenWorshipRequired pin
    if (dezArmyOpenWorshipRequired() != 1
        )
            ++bad;
        // the dezArmyGatherDoubledIfUncommon pin
    if (dezArmyGatherDoubledIfUncommon() != 1
        )
            ++bad;
        // the dezArmySmallerAllowed pin
    if (dezArmySmallerAllowed() != 1
        )
            ++bad;
        // the dezArmyPayOrCharismaCheck pin
    if (dezArmyPayOrCharismaCheck() != 1
        )
            ++bad;
        // the dezArmyGoalWithinReach pin
    if (dezArmyGoalWithinReach() != 1
        )
            ++bad;
        // the dezArmyDisbandIndependenceRisk pin
    if (dezArmyDisbandIndependenceRisk() != 1
        )
            ++bad;
        // the dezPriestFocusWisStrCha pin
    if (dezPriestFocusWisStrCha() != 1
        )
            ++bad;
        // the dezPriestFocusNoBonusSpells pin
    if (dezPriestFocusNoBonusSpells() != 1
        )
            ++bad;
        // the dezPriestFocusWis19Immunity pin
    if (dezPriestFocusWis19Immunity() != 1
        )
            ++bad;
        // the dezPriestFocusOneBoostAtATime pin
    if (dezPriestFocusOneBoostAtATime() != 1
        )
            ++bad;
        // the dezPriestFocusConcentrationRoundOnlyAction pin
    if (dezPriestFocusConcentrationRoundOnlyAction() != 1
        )
            ++bad;
        // the dezPriestFocusBoostEndsAtWill pin
    if (dezPriestFocusBoostEndsAtWill() != 1
        )
            ++bad;
        // the dezPriestFocusNoEffectIfHigher pin
    if (dezPriestFocusNoEffectIfHigher() != 1
        )
            ++bad;
        // the dezPriestFocusSubabilitiesRaisedEqual pin
    if (dezPriestFocusSubabilitiesRaisedEqual() != 1
        )
            ++bad;
        // the dezVoiceFullRoundSpeech pin
    if (dezVoiceFullRoundSpeech() != 1
        )
            ++bad;
        // the dezVoicePenetratesSilence pin
    if (dezVoicePenetratesSilence() != 1
        )
            ++bad;
        // the dezVoiceAntimagicShields pin
    if (dezVoiceAntimagicShields() != 1
        )
            ++bad;
        // the dezVoiceMagicalDeafnessBlocks pin
    if (dezVoiceMagicalDeafnessBlocks() != 1
        )
            ++bad;
        // the dezVoiceSaveVsSpellOthers pin
    if (dezVoiceSaveVsSpellOthers() != 1
        )
            ++bad;
        // the dezVoiceHearingOnlyRequired pin
    if (dezVoiceHearingOnlyRequired() != 1
        )
            ++bad;
        // the dezVoiceUndeadAndCharmImmuneUnaffected pin
    if (dezVoiceUndeadAndCharmImmuneUnaffected() != 1
        )
            ++bad;
        // the dezVoiceWis19Immune pin
    if (dezVoiceWis19Immune() != 1
        )
            ++bad;
        // the dezVoiceJeeringBreaks pin
    if (dezVoiceJeeringBreaks() != 1
        )
            ++bad;
        // the dezVoiceOneMassSuggestionPerUse pin
    if (dezVoiceOneMassSuggestionPerUse() != 1
        )
            ++bad;
        // the dezVoiceNoSaveIfBeforeEnthralEnds pin
    if (dezVoiceNoSaveIfBeforeEnthralEnds() != 1
        )
            ++bad;
        // the dezVoiceAffectsAllEnthralled pin
    if (dezVoiceAffectsAllEnthralled() != 1
        )
            ++bad;
        // the dezVoiceIneffectiveAtZeroEminence pin
    if (dezVoiceIneffectiveAtZeroEminence() != 1
        )
            ++bad;
        // the dezWillNegatesCompulsion pin
    if (dezWillNegatesCompulsion() != 1
        )
            ++bad;
        // the dezWillSaveOnFail pin
    if (dezWillSaveOnFail() != 1
        )
            ++bad;
        // the dezWillCoversAllCompulsions pin
    if (dezWillCoversAllCompulsions() != 1
        )
            ++bad;
        // the dezWillEjectsMagicJarPsyche pin
    if (dezWillEjectsMagicJarPsyche() != 1
        )
            ++bad;
        // the dezWillIneffectiveAtZero pin
    if (dezWillIneffectiveAtZero() != 1
        )
            ++bad;
        // the dezDeceiveSeesFalsehoods pin
    if (dezDeceiveSeesFalsehoods() != 1
        )
            ++bad;
        // the dezDeceiveAutoSpokenFalsehoods pin
    if (dezDeceiveAutoSpokenFalsehoods() != 1
        )
            ++bad;
        // the dezDeceiveKnowsEvasionVsLie pin
    if (dezDeceiveKnowsEvasionVsLie() != 1
        )
            ++bad;
        // the dezDeceiveNoTruthRevealed pin
    if (dezDeceiveNoTruthRevealed() != 1
        )
            ++bad;
        // the dezDeceiveMagicSpeechUnheard pin
    if (dezDeceiveMagicSpeechUnheard() != 1
        )
            ++bad;
        // the dezDeceiveImmediateSaveVsIllusion pin
    if (dezDeceiveImmediateSaveVsIllusion() != 1
        )
            ++bad;
        // the dezDeceiveDmSecretRoll pin
    if (dezDeceiveDmSecretRoll() != 1
        )
            ++bad;
        // the dezDeceiveSeesMist pin
    if (dezDeceiveSeesMist() != 1
        )
            ++bad;
        // the dezDeceiveWorksVsVisualSpells pin
    if (dezDeceiveWorksVsVisualSpells() != 1
        )
            ++bad;
        // the dezDeceiveNotVsInvisibility pin
    if (dezDeceiveNotVsInvisibility() != 1
        )
            ++bad;
        // the dezDeceiveDefeatsDisplacementBlending pin
    if (dezDeceiveDefeatsDisplacementBlending() != 1
        )
            ++bad;
        // the dezDeceiveNotVsPhysicalChanges pin
    if (dezDeceiveNotVsPhysicalChanges() != 1
        )
            ++bad;
        // the dezDeceiveIneffectiveAtZero pin
    if (dezDeceiveIneffectiveAtZero() != 1
        )
            ++bad;
        // the dezEminenceAuraUndetectable pin
    if (dezEminenceAuraUndetectable() != 1
        )
            ++bad;
        // the dezEminenceHaloByAlignment pin
    if (dezEminenceHaloByAlignment() != 1
        )
            ++bad;
        // the dezEminenceFearAtWill pin
    if (dezEminenceFearAtWill() != 1
        )
            ++bad;
        // the dezEminenceSaveForStronger pin
    if (dezEminenceSaveForStronger() != 1
        )
            ++bad;
        // the dezEminenceWorksVsFearImmune pin
    if (dezEminenceWorksVsFearImmune() != 1
        )
            ++bad;
        // the dezEminenceCloakOrRemoveFearBreaks pin
    if (dezEminenceCloakOrRemoveFearBreaks() != 1
        )
            ++bad;
        // the dezEminenceSkillBreaks pin
    if (dezEminenceSkillBreaks() != 1
        )
            ++bad;
        // the dezEminenceOnceResistedImmuneRestOfDay pin
    if (dezEminenceOnceResistedImmuneRestOfDay() != 1
        )
            ++bad;
        // the dezEminenceOpposingPriestShields pin
    if (dezEminenceOpposingPriestShields() != 1
        )
            ++bad;
        // the dezEminenceIneffectiveAtZero pin
    if (dezEminenceIneffectiveAtZero() != 1
        )
            ++bad;
        // the dezEminencePrereqFiveSkills pin
    if (dezEminencePrereqFiveSkills() != 1
        )
            ++bad;
        // the dezEminenceDrainsBySkill pin
    if (dezEminenceDrainsBySkill() != 1
        )
            ++bad;
        // the dezEminenceZeroBlocksAll pin
    if (dezEminenceZeroBlocksAll() != 1
        )
            ++bad;
        // the dezSmiteConnectedButUsableAtZero pin
    if (dezSmiteConnectedButUsableAtZero() != 1
        )
            ++bad;
        // the dezInvLikeWarriorHardiness pin
    if (dezInvLikeWarriorHardiness() != 1
        )
            ++bad;
        // the dezInvSaveFirst pin
    if (dezInvSaveFirst() != 1
        )
            ++bad;
        // the dezInvNoSimpleOrContinuingDamage pin
    if (dezInvNoSimpleOrContinuingDamage() != 1
        )
            ++bad;
        // the dezInvNoCharmsEntangleImprison pin
    if (dezInvNoCharmsEntangleImprison() != 1
        )
            ++bad;
        // the dezInvCureWithinDelayNoHarm pin
    if (dezInvCureWithinDelayNoHarm() != 1
        )
            ++bad;
        // the dezInvShorterDurationNoEffect pin
    if (dezInvShorterDurationNoEffect() != 1
        )
            ++bad;
        // the dezInvSystemShockAtEnd pin
    if (dezInvSystemShockAtEnd() != 1
        )
            ++bad;
        // the dezInvShockSuccessHeals pin
    if (dezInvShockSuccessHeals() != 1
        )
            ++bad;
        // the dezInvShockFailFullForce pin
    if (dezInvShockFailFullForce() != 1
        )
            ++bad;
        // the dezInvMultipleEffectsSequential pin
    if (dezInvMultipleEffectsSequential() != 1
        )
            ++bad;
        // the dezInvUnconsciousRecoversInstantly pin
    if (dezInvUnconsciousRecoversInstantly() != 1
        )
            ++bad;
        // the dezInvHeroicRoundsEqualDelay pin
    if (dezInvHeroicRoundsEqualDelay() != 1
        )
            ++bad;
        // the dezInvHeroicDeathAtDelayEnd pin
    if (dezInvHeroicDeathAtDelayEnd() != 1
        )
            ++bad;
        // the dezInvRaiseDuringDelaySaves pin
    if (dezInvRaiseDuringDelaySaves() != 1
        )
            ++bad;
        // the dezInvRegenNoShock pin
    if (dezInvRegenNoShock() != 1
        )
            ++bad;
        // the dezInvAmuletNoShock pin
    if (dezInvAmuletNoShock() != 1
        )
            ++bad;
        // the dezInvIneffectiveAtZero pin
    if (dezInvIneffectiveAtZero() != 1
        )
            ++bad;
        // the dezInvDrainRestOfDay pin
    if (dezInvDrainRestOfDay() != 1
        )
            ++bad;
        // the dezLoanTransfersVitality pin
    if (dezLoanTransfersVitality() != 1
        )
            ++bad;
        // the dezLoanUnwillingNeedsAttackRoll pin
    if (dezLoanUnwillingNeedsAttackRoll() != 1
        )
            ++bad;
        // the dezLoanLostLikeDamage pin
    if (dezLoanLostLikeDamage() != 1
        )
            ++bad;
        // the dezLoanDonorDiesIfInsufficient pin
    if (dezLoanDonorDiesIfInsufficient() != 1
        )
            ++bad;
        // the dezLoanUselessAtZero pin
    if (dezLoanUselessAtZero() != 1
        )
            ++bad;
        // the dezSmiteConeAnyDirection pin
    if (dezSmiteConeAnyDirection() != 1
        )
            ++bad;
        // the dezSmiteDmChoosesEffect pin
    if (dezSmiteDmChoosesEffect() != 1
        )
            ++bad;
        // the dezSmiteOnlyEnemiesHarmed pin
    if (dezSmiteOnlyEnemiesHarmed() != 1
        )
            ++bad;
        // the dezSmiteAweDefault pin
    if (dezSmiteAweDefault() != 1
        )
            ++bad;
        // the dezSmiteAweDepiction pin
    if (dezSmiteAweDepiction() != 1
        )
            ++bad;
        // the dezSmiteAweOneRoundEvenOnSave pin
    if (dezSmiteAweOneRoundEvenOnSave() != 1
        )
            ++bad;
        // the dezSmiteAweRequiresMotionless pin
    if (dezSmiteAweRequiresMotionless() != 1
        )
            ++bad;
        // the dezSmiteAweLatecomersSubject pin
    if (dezSmiteAweLatecomersSubject() != 1
        )
            ++bad;
        // the dezSmiteAweMotionBreaks pin
    if (dezSmiteAweMotionBreaks() != 1
        )
            ++bad;
        // the dezSmiteAweDistractionBreaks pin
    if (dezSmiteAweDistractionBreaks() != 1
        )
            ++bad;
        // the dezSmiteBlindTouchCastingOnly pin
    if (dezSmiteBlindTouchCastingOnly() != 1
        )
            ++bad;
        // the dezSmiteBlindUntilHealed pin
    if (dezSmiteBlindUntilHealed() != 1
        )
            ++bad;
        // the dezSmiteBurnAshNoRegen pin
    if (dezSmiteBurnAshNoRegen() != 1
        )
            ++bad;
        // the dezSmiteBurnEquipmentSaves pin
    if (dezSmiteBurnEquipmentSaves() != 1
        )
            ++bad;
        // the dezSmiteBurnHeatless pin
    if (dezSmiteBurnHeatless() != 1
        )
            ++bad;
        // the dezSmiteDeafUntilHealed pin
    if (dezSmiteDeafUntilHealed() != 1
        )
            ++bad;
        // the dezSmiteDeathDoubledBurn pin
    if (dezSmiteDeathDoubledBurn() != 1
        )
            ++bad;
        // the dezSmiteImmobCrystalline pin
    if (dezSmiteImmobCrystalline() != 1
        )
            ++bad;
        // the dezSmiteImmobSaveVsPetrification pin
    if (dezSmiteImmobSaveVsPetrification() != 1
        )
            ++bad;
        // the dezSmiteImmobFreeActionUseless pin
    if (dezSmiteImmobFreeActionUseless() != 1
        )
            ++bad;
        // the dezSmiteImmobShatterKill pin
    if (dezSmiteImmobShatterKill() != 1
        )
            ++bad;
        // the dezSmitePlagueDebilitating pin
    if (dezSmitePlagueDebilitating() != 1
        )
            ++bad;
        // the dezSmitePlagueNotContagiousOrFatal pin
    if (dezSmitePlagueNotContagiousOrFatal() != 1
        )
            ++bad;
        // the dezSmitePlagueHigherLevelCure pin
    if (dezSmitePlagueHigherLevelCure() != 1
        )
            ++bad;
        // the dezSmitePlagueWhenOffensive pin
    if (dezSmitePlagueWhenOffensive() != 1
        )
            ++bad;
        // the dezSmiteSlowWhenNoImmediateThreat pin
    if (dezSmiteSlowWhenNoImmediateThreat() != 1
        )
            ++bad;
        // the dezSmiteNoRollWithPositiveEminence pin
    if (dezSmiteNoRollWithPositiveEminence() != 1
        )
            ++bad;
        // the dezSmiteCheckAtZeroOrLess pin
    if (dezSmiteCheckAtZeroOrLess() != 1
        )
            ++bad;
        // the dezSmiteFailDispleasesDeity pin
    if (dezSmiteFailDispleasesDeity() != 1
        )
            ++bad;
        // the dezSmiteFailMaySmitePriest pin
    if (dezSmiteFailMaySmitePriest() != 1
        )
            ++bad;
        // the dezSmiteMarissaAweBrokenByAttack pin
    if (dezSmiteMarissaAweBrokenByAttack() != 1
        )
            ++bad;
        // the dezTalCastAtDayStart pin
    if (dezTalCastAtDayStart() != 1
        )
            ++bad;
        // the dezTalSmallObject pin
    if (dezTalSmallObject() != 1
        )
            ++bad;
        // the dezTalRollToPlace pin
    if (dezTalRollToPlace() != 1
        )
            ++bad;
        // the dezTalFailWastesSpell pin
    if (dezTalFailWastesSpell() != 1
        )
            ++bad;
        // the dezTalComponentsRequired pin
    if (dezTalComponentsRequired() != 1
        )
            ++bad;
        // the dezTalCastingEffectsOnFail pin
    if (dezTalCastingEffectsOnFail() != 1
        )
            ++bad;
        // the dezTalTotalCappedAtLevel pin
    if (dezTalTotalCappedAtLevel() != 1
        )
            ++bad;
        // the dezTalCapSharedLadder pin
    if (dezTalCapSharedLadder() != 1
        )
            ++bad;
        // the dezTalReleaseRequiresContact pin
    if (dezTalReleaseRequiresContact() != 1
        )
            ++bad;
        // the dezTalReleaseUndisruptable pin
    if (dezTalReleaseUndisruptable() != 1
        )
            ++bad;
        // the dezTalGaggedOrSilencedBlocks pin
    if (dezTalGaggedOrSilencedBlocks() != 1
        )
            ++bad;
        // the dezTalDestroysTalisman pin
    if (dezTalDestroysTalisman() != 1
        )
            ++bad;
        // the dezTalOnlyStorerReleases pin
    if (dezTalOnlyStorerReleases() != 1
        )
            ++bad;
        // the dezTalNoRememorizeBefore24h pin
    if (dezTalNoRememorizeBefore24h() != 1
        )
            ++bad;
        // the dezTalNoTransferBack pin
    if (dezTalNoTransferBack() != 1
        )
            ++bad;
        // the dezTalDestroyedSpellLost pin
    if (dezTalDestroyedSpellLost() != 1
        )
            ++bad;
        // the dezTalFadesOnReleaseOrLoss pin
    if (dezTalFadesOnReleaseOrLoss() != 1
        )
            ++bad;
        // the dezTalCastsWhereFactorDisallows pin
    if (dezTalCastsWhereFactorDisallows() != 1
        )
            ++bad;
        // the dezTalStoreNeedsLocalConditions pin
    if (dezTalStoreNeedsLocalConditions() != 1
        )
            ++bad;
        // the dezTalInitUnaffectedByFactor pin
    if (dezTalInitUnaffectedByFactor() != 1
        )
            ++bad;
        // the Table 43 experience steps: 375,000 per level (printed p. 156)
    if (dezT43Xp(1) - dezT43Xp(0) != 375000
        )
            ++bad;
        // the Table 43 hit-point steps: +1 per level (printed p. 156)
    if (dezT43HpBonus(1) - dezT43HpBonus(0) != 1
        )
            ++bad;
        // the Table 43 level 30 tail: 7,500,000 XP, 10+20 hit points (printed
        // p. 156)
    if (dezT43Xp(10) != 7500000
            || dezT43HpBonus(10) != 20
            || dezT43HpBaseCol(10) != 10
        )
            ++bad;
        // the Table 43 level 30 proficiencies: weapon 6, nonweapon 14
        // (printed p. 156)
    if (dezT43WeaponProf(10) != 6
            || dezT43NonweaponProf(10) != 14
        )
            ++bad;
        // the Table 44 row 20 head: 5,5,5,5,5,4,3,3,2,1 (printed p. 157)
    if (dezT44L6(0) != 4
            || dezT44L10(0) != 1
            || dezT44L1(0) != 5
        )
            ++bad;
        // the Table 44 row 30 tail: seven 1st- through 7th-level spells, four
        // true dweomers (printed p. 157)
    if (dezT44L1(10) != 7
            || dezT44L7(10) != 7
            || dezT44L10(10) != 4
        )
            ++bad;
        // the Table 44 true dweomer column climbs 1, 2, 3, 4 in three-level
        // steps (printed p. 157)
    if (dezT44L10(3) != 2
            || dezT44L10(6) != 3
            || dezT44L10(9) != 4
        )
            ++bad;
        // the Table 44 low columns hold 5 through 25th, reach 6 at 26th and 7
        // at 29th (printed p. 157)
    if (dezT44L1(5) != 5
            || dezT44L1(6) != 6
            || dezT44L1(9) != 7
        )
            ++bad;
        // the sage ladder: specific at 24th, exacting at 27th (printed pp.
        // 157-158)
    if (dezSageSpecificLevel() + 3 != dezSageExactingLevel()
        )
            ++bad;
        // the mental focus ladder: 12th boosts to 18, 30th to 22 (printed p.
        // 158)
    if (dezWizFocusBand(12) + 18 != 18
            || dezWizFocusBand(30) + 18 != 22
        )
            ++bad;
        // the sculpting cap ladder: 12th sculpts 1st, 21st 4th, 30th 7th
        // (printed pp. 158-159)
    if (dezSpellCapBand(12) + 1 != 1
            || dezSpellCapBand(21) + 1 != 4
            || dezSpellCapBand(30) + 1 != 7
        )
            ++bad;
        // the sculpting fireball example: 10d6 base plus two dice is 12d6
        // (printed pp. 158-159)
    if (dezSculptFireballBaseDice() + dezSculptDamageDice() !=
        dezSculptFireballSculptedDice()
        )
            ++bad;
        // the sculpting burning hands example: 1d3 base plus two dice is the
        // printed 3d3 (printed pp. 158-159)
    if (dezSculptBurningHandsBaseDice() + dezSculptDamageDice() != 3
        )
            ++bad;
        // the sculpting magic missile example: five missiles plus two dice is
        // the printed 7d4 (printed pp. 158-159)
    if (dezSculptMagicMissileBaseDice() + dezSculptDamageDice() != 7
        )
            ++bad;
        // the Table 45 cleric steps: 225,000 per level (printed p. 160)
    if (dezT45ClericXp(1) - dezT45ClericXp(0) != 225000
        )
            ++bad;
        // the Table 45 druid steps: 500,000 per level (printed p. 160)
    if (dezT45DruidXp(1) - dezT45DruidXp(0) != 500000
        )
            ++bad;
        // the Table 45 hit-point steps: +2 per level (printed p. 160)
    if (dezT45HpBonus(1) - dezT45HpBonus(0) != 2
        )
            ++bad;
        // the Table 45 level 30 tail: cleric 4,950,000, druid 7,000,000, 9+42
        // hit points (printed p. 160)
    if (dezT45ClericXp(10) != 4950000
            || dezT45DruidXp(10) != 7000000
            || dezT45HpBonus(10) != 42
        )
            ++bad;
        // the Table 45 level 30 proficiencies: weapon 9, nonweapon 14
        // (printed p. 160)
    if (dezT45WeaponProf(10) != 9
            || dezT45NonweaponProf(10) != 14
        )
            ++bad;
        // the priest spell progression row 20 head: 9,9,9,8 spells and
        // 7,5,2,1 with one true dweomer (printed p. 161)
    if (dezT47L4(0) != 8
            || dezT47L5(0) != 7
            || dezT47L6(0) != 5
            || dezT47Td(0) != 1
        )
            ++bad;
        // the priest spell progression row 30 tail: 9,9,9,9,9,9,8 and four
        // true dweomers (printed p. 161)
    if (dezT47L7(10) != 8
            || dezT47Td(10) != 4
            || dezT47L1(10) != 9
        )
            ++bad;
        // the priest true dweomer column climbs 1, 2, 3, 4 (printed p. 161)
    if (dezT47Td(2) != 2
            || dezT47Td(4) != 2
            || dezT47Td(5) != 3
            || dezT47Td(7) != 4
        )
            ++bad;
        // the priest 6th-level column reaches 9 at 26th and holds through
        // 30th (printed p. 161)
    if (dezT47L6(6) != 9
            || dezT47L6(10) != 9
        )
            ++bad;
        // the Wulf turning example: six vampires, a 2d6 roll of 5 leaves one
        // unaffected (printed p. 160)
    if (dezWulfVampires() - dezWulfVampireRollResult() !=
        dezWulfVampiresUnaffected()
        )
            ++bad;
        // the Wulf turning example: the destroy dice read 2d6+2d4 (printed p.
        // 160)
    if (dezWulfDestroyDiceCount() * 2 != 4
            || dezWulfDestroyMajorSides() != 6
            || dezWulfDestroyMinorSides() != 4
        )
            ++bad;
        // the holy army example chain halves with round down: 21st to 10th
        // (printed pp. 161-162)
    if (dezArmyExampleCommander() * 2 + 1 != dezArmyExamplePriestLevel()
            || dezArmyExampleCommander() * 2 > dezArmyExamplePriestLevel()
        )
            ++bad;
        // the holy army example chain: subcommanders half of 10, lieutenants
        // half of 5, sergeants half of 2 (printed pp. 161-162)
    if (dezArmyExampleSubcommander() * 2 != dezArmyExampleCommander()
            || dezArmyExampleLieutenant() * 2 + 1 !=
            dezArmyExampleSubcommander()
            || dezArmyExampleSergeant() * 2 != dezArmyExampleLieutenant()
        )
            ++bad;
        // the holy army example size: 2,925,000 XP over 1,000 is the printed
        // 2,925 troops (printed pp. 161-162)
    if (dezT45ClericXp(1) / dezArmyTroopsPerXp() != dezArmyExampleTroops()
        )
            ++bad;
        // the divine strength ladder: 10th boosts to 18, 30th to 22 (printed
        // p. 161)
    if (dezPriestFocusBand(10) + 18 != 18
            || dezPriestFocusBand(30) + 18 != 22
        )
            ++bad;
        // the detect deception duration ladder: 15th gets one turn, 27th gets
        // five (printed pp. 162-163)
    if (dezDeceiveDurationBand(15) + 1 != 1
            || dezDeceiveDurationBand(27) + 1 != 5
        )
            ++bad;
        // the invincibility example: a 25th-level priest delays ten rounds
        // (printed pp. 163-165)
    if (dezInvExampleDelay() != dezInvDelayBase() *
        (dezInvDelayBand(dezInvExampleLevel()) + 1)
        )
            ++bad;
        // the invincibility delay ladder tail: 27th through 30th delay
        // fifteen rounds (printed pp. 163-165)
    if (dezInvDelayBase() * (dezInvDelayBand(27) + 1) != 15
        )
            ++bad;
        // the invincibility example system shock: 96 percent is 6 over the
        // needed 90 (printed pp. 163-165)
    if (dezInvExampleShockRoll() - dezInvExampleShockMargin() != 90
        )
            ++bad;
        // the invincibility vampire-and-lich sum: two months plus the
        // paralysis week is nine weeks (printed pp. 163-165)
    if (dezInvVampireLevels() * 4 + dezInvParalysisWeeks() !=
        dezInvNineWeeks()
        )
            ++bad;
        // the loan ladder bands: 15-19 reads 1d8+2, 30 or more reads 4d6+8
        // (printed p. 165)
    if (dezLoanDice(dezLoanBand(15)) != 1
            || dezLoanSides(dezLoanBand(15)) != 8
            || dezLoanBonus(dezLoanBand(15)) != 2
            || dezLoanDice(dezLoanBand(30)) != 4
            || dezLoanSides(dezLoanBand(30)) != 6
            || dezLoanBonus(dezLoanBand(30)) != 8
        )
            ++bad;
        // the smite cone ladder: 18th through 20th reaches 30 feet, 30th
        // reaches 110 (printed pp. 165-166)
    if (dezSmiteLengthBase() + dezSmiteLengthStep() * dezSmiteConeBand(18) !=
        30
            || dezSmiteConeBand(30) != 4
        )
            ++bad;
        // the smite death effect doubles the burn: 6d8 becomes 12d8 (printed
        // pp. 165-166)
    if (dezSmiteBurnDice() * 2 != dezSmiteDeathDice()
        )
            ++bad;
        // the Marissa example: after the second smite the -2 base plus the +4
        // bonus reads 2 (printed pp. 165-166)
    if (dezSmiteMarissaAfterFirst() + dezSmiteMarissaBonus() != 2
        )
            ++bad;
        // the Marissa example: after the failed third attempt the -4 base
        // plus the +4 bonus leaves zero (printed pp. 165-166)
    if (dezSmiteMarissaAfterSecond() + dezSmiteMarissaBonus() != 0
        )
            ++bad;
        // the Marissa example: the eminence 4 equals her Charisma/Leadership
        // bonus (printed pp. 165-166)
    if (dezSmiteMarissaEminence() != dezSmiteMarissaBonus()
        )
            ++bad;
        // the Wulf talisman example: two 4th plus two 3rd plus seven 1st is
        // 21 stored levels (printed pp. 166-167)
    if (dezWulfStored4th() * 4 + dezWulfStored3rd() * 3 + dezWulfStored1st()
        != dezWulfStoredTotal()
        )
            ++bad;
        // the Wulf talisman example: a 21st-level priest caps at 4th-level
        // spells (printed pp. 166-167)
    if (dezSpellCapBand(21) + 1 != 4
        )
            ++bad;
        printf("R610 DMO wizard-priest audit: bad %d\n", bad);
        if (bad) return 1;
    }
