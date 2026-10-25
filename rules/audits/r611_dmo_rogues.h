    // ---- R611 DMO rogues audit ----
    // DMO Chapter 7 round four of five (printed pp. 167-177): the rogue
    // doctrine with the 95 percent cap and the Jobare worked examples, the
    // Table 47r advancement grid (the 220K steps with the printed 120K final
    // step, the proficiency columns, the 10+N d6 hit points), the Table 48
    // base scores, the Table 49 racial grid, the Table 50 Dexterity-aim grid
    // and the Table 51 armor grid, the five thief skills with the bribe
    // status table and the Jobare 30-cp example, the tunneling earth table,
    // the thief and bard scroll ladders, the Table 52 bard spell progression,
    // and the eleven rogue skills - adaptation, classify traps, evasion, the
    // fall/jump safe-fall ladder with the Jobare shaft example, featherfoot,
    // improvised attack with its save-modifier ladder and the trick hat
    // example, inner focus, nondetection, sense danger with its subskill
    // ladder, shadow flight and shadow travel.
    {
        using namespace rules;
        int bad = 0;
    if (dfaRogueSkillStartLevel() != 11
            || dfaRogueAdvLimit() != 30
            || dfaRogueExtraAbilityLevel() != 21
            || dfaThiefScoreCap() != 95
            || dfaThiefCapLiftLevel() != 11
            || dfaThiefAutoFailRoll() != 96
            || dfaJobareTrapScore() != 120
            || dfaJobareMagicalTrapChance() != 60
            || dfaJobareLockScore() != 100
            || dfaJobareMasterfulPenalty() != 60
            || dfaJobareMasterfulChance() != 40
            || dfaT47RowCount() != 11
            || dfaT47XpBase() != 2200000
            || dfaT47XpStep() != 220000
            || dfaT47Xp30() != 4300000
            || dfaT47HpBase() != 10
            || dfaT47HpStep() != 2
            || dfaNewThiefSkillCount() != 5
            || dfaBribeBase() != 5
            || dfaDetectIllusionBase() != 10
            || dfaDetectMagicBase() != 5
            || dfaEscapeBondsBase() != 10
            || dfaTunnelingBase() != 15
            || dfaT49RowCount() != 5
            || dfaT50RowCount() != 2
            || dfaT51RowCount() != 3
            || dfaBribeRowCount() != 4
            || dfaJobareReactionRoll() != 13
            || dfaJobareFriendlyMax() != 7
            || dfaJobareBribeDiff() != 6
            || dfaJobareBaseBribeCp() != 5
            || dfaJobarePaidCp() != 30
            || dfaDetectIllusionRange() != 90
            || dfaDetectMagicRange() != 60
            || dfaDetectMagicIntensityCount() != 5
            || dfaEscapeBondsRounds() != 5
            || dfaEscapeBondsHurryPenalty() != 5
            || dfaTunnelChunkFeet() != 10
            || dfaTunnelRowCount() != 3
            || dfaThiefSkillBonusCp() != 50
            || dfaThiefSpSkillThreshold() != 9
            || dfaThiefScrollLevel() != 24
            || dfaThiefScrollFailPct() != 25
            || dfaBardNewSkillCount() != 2
            || dfaBardNewSkillLevel() != 21
            || dfaBardSkillBonusCp() != 20
            || dfaBardScrollLevel() != 21
            || dfaBardScrollFailPct() != 15
            || dfaBardIdentifyLevel() != 21
            || dfaBardIdentifyChance() != 55
            || dfaBardItemUseLevel() != 24
            || dfaBardItemCreationLevel() != 27
            || dfaT52RowCount() != 11
            || dfaAdaptInitPenaltyAvoided() != 6
            || dfaAdaptCheckBonus() != 3
            || dfaAdaptBlindCheckPenalty() != 4
            || dfaAdaptPracticeHours() != 8
            || dfaAdaptPermanentCp() != 3
            || dfaClassifyExamTurns() != 1
            || dfaClassifyFalseRoll() != 20
            || dfaClassifyEvasionSaveBonus() != 2
            || dfaFallSafeBase() != 30
            || dfaFallSurfaceRowCount() != 7
            || dfaJobareFallLevel() != 20
            || dfaJobareShaftFeet() != 150
            || dfaJobareChamberFeet() != 30
            || dfaJobareBreakFeet() != 120
            || dfaJobareFinalFeet() != 60
            || dfaJobareFallDice() != 6
            || dfaJobareFallSides() != 6
            || dfaJobare30thDice() != 3
            || dfaJobare30thFeet() != 30
            || dfaFeatherRowCount() != 3
            || dfaImprovisedDailyPerLearning() != 1
            || dfaImprovisedBlindPenalty() != 4
            || dfaImprovisedBlindClearRoll() != 9
            || dfaImprovisedImmobFreeRoll() != 9
            || dfaImprovisedKillHpOffset() != 10
            || dfaImprovisedStunDice() != 2
            || dfaImprovisedStunSides() != 4
            || dfaImprovisedStunPenalty() != 2
            || dfaImprovisedTripLowSides() != 3
            || dfaImprovisedTripHighSides() != 6
            || dfaImprovisedSaveNoRoleplay() != 6
            || dfaImprovisedSaveFeeble() != 4
            || dfaImprovisedSaveTrickAdventure() != 2
            || dfaImprovisedSaveTrickEncounter() != 4
            || dfaImprovisedSaveSameCreatureAdventure() != 6
            || dfaImprovisedSaveSameCreatureEncounter() != 8
            || dfaImprovisedSaveSurprised() != 2
            || dfaImprovisedSaveAppropriate() != 4
            || dfaJobareSurpriseRoll() != 2
            || dfaFocusBoostBase() != 18
            || dfaFocusOtherPenalty() != 2
            || dfaFocusDurationPerLevel() != 1
            || dfaFocusAttemptCost() != 2
            || dfaNondetectionSpellLevel() != 3
            || dfaSenseSubskillCount() != 4
            || dfaSenseAmbushYards() != 200
            || dfaSenseImpendingSurpriseBonus() != 2
            || dfaSenseImpendingInitBonus() != 1
            || dfaSenseFalseRoll() != 20
            || dfaSenseAlertnessBonus() != 1
            || dfaFlightWeakRate() != 15
            || dfaFlightStrongRate() != 18
            || dfaFlightVeryRate() != 24
            || dfaFlightLeapYards() != 360
            || dfaFlightLeapPerHour() != 1
            || dfaShadowWeakRate() != 15
            || dfaShadowStrongRate() != 18
            || dfaShadowVeryRate() != 24
            || !dfaThief95CapSpendElsewhere()
            || !dfaThiefAll95PointsLost()
            || !dfaThiefLostPointsNotRegained()
            || !dfaThiefPenaltiesFromBase()
            || !dfaT47FinalStepShort()
            || !dfaT47ConBonusStopsAfter10()
            || !dfaT47CaptionSharesPrintedNumber()
            || !dfaNewSkillsApplyPointsImmediately()
            || !dfaT49HalflingDetectMagicNoPercent()
            || !dfaT50TunnelingDashAt17()
            || !dfaBribeOneAttemptPerTarget()
            || !dfaBribeFailReactionRoll()
            || !dfaBribeNotEveryoneSusceptible()
            || !dfaBribeNotOutsideStation()
            || !dfaBribeNeverDangerousOrLong()
            || !dfaBribeNeverAgainstBeliefs()
            || !dfaBribeSecretReactionRoll()
            || !dfaBribeFriendlyNeedsNoBribe()
            || !dfaBribeMultiplyByDifference()
            || !dfaBribePlayerNeverToldValues()
            || !dfaDetectIllusionNeedsRound()
            || !dfaDetectIllusionTranslucent()
            || !dfaDetectIllusionNotVsNonvisible()
            || !dfaDetectIllusionNotFailSafe()
            || !dfaDetectMagicBlockedLikeSpell()
            || !dfaEscapeBondsRollPerDevice()
            || !dfaEscapeBondsLockedNeedPicks()
            || !dfaEscapeBondsFailCantRetryThatBond()
            || !dfaTunnelCollapseOnFail()
            || !dfaTunnelRedugAtLooseRate()
            || !dfaThiefSpOverflowToProficiencies()
            || !dfaThiefExtraSkillsOnlyAt21st()
            || !dfaThiefScrollNoFailAtOrBelow()
            || !dfaBardScrollWizardNoFailIfCastable()
            || !dfaBardIdentifyNoBonusesCharges()
            || !dfaBardIdentifyNoHandling()
            || !dfaAdaptLikeWarriorSkill()
            || !dfaAdaptNoSituationalOrNoncombat()
            || !dfaAdaptNoMagicalOrVisionPenalties()
            || !dfaAdaptCheckEachRound()
            || !dfaAdaptLastsBattlePlusDays()
            || !dfaAdaptPermanentBeforeFade()
            || !dfaClassifyNeedsFindTraps()
            || !dfaClassifyRevealsExactNature()
            || !dfaClassifyMagicalHalvedRoundUp()
            || !dfaClassifyFailUnder20LearnsNothing()
            || !dfaClassifySecretRoll()
            || !dfaClassifyTwoRemoveRollsBest()
            || !dfaClassifyBypassSaveVsBreath()
            || !dfaClassifyCompanionsMaySave()
            || !dfaClassifyNoHalfEffectRuling()
            || !dfaEvasionAutomatic()
            || !dfaEvasionNoDamageOnSave()
            || !dfaEvasionNotVsNonDamage()
            || !dfaEvasionFixedMissilesOnly()
            || !dfaEvasionNeedsNotSurprised()
            || !dfaFallAlwaysWithinOneFoot()
            || !dfaFallFrictionSurfacesOk()
            || !dfaFallDamageOnExcess()
            || !dfaFeatherNeedsMoveSilently()
            || !dfaFeatherMustStopAtDistance()
            || !dfaFeatherSilentNoTracks()
            || !dfaFeatherNoWeightTriggers()
            || !dfaImprovisedLearnMultipleTimes()
            || !dfaImprovisedBlindfightingNoHelp()
            || !dfaImprovisedDisarmStuckNeedsOpenDoors()
            || !dfaImprovisedKillHigherHdImmune()
            || !dfaImprovisedStunNoSpellsAttack()
            || !dfaImprovisedAnnounceDeclareDescribe()
            || !dfaImprovisedNormalAttackRoll()
            || !dfaImprovisedSuccessNoDamage()
            || !dfaImprovisedSaveUnlikelyRange()
            || !dfaImprovisedSaveAutoIfInadequate()
            || !dfaImprovisedTable3638Optional()
            || !dfaImprovisedTrickThreeAdventures()
            || !dfaImprovisedTrickOncePerEncounter()
            || !dfaImprovisedTrickNotDailyAllotment()
            || !dfaImprovisedTrickPreparedPlus6()
            || !dfaJobareHatBlindExample()
            || !dfaFocusLikeWarriorSkill()
            || !dfaFocusAlreadyHigherNoEffect()
            || !dfaFocusEndAtWill()
            || !dfaFocusSubabilitiesRaisedEqual()
            || !dfaFocusOneBoostAtATime()
            || !dfaFocusNoOtherActions()
            || !dfaFocusBonusesImmediate()
            || !dfaNondetectionBeatsDivinations()
            || !dfaNondetectionSavesEvenOnFail()
            || !dfaNondetectionBeatsSenseDanger()
            || !dfaNondetectionBeatsDetectDeception()
            || !dfaNondetectionOpposedWillpower()
            || !dfaNondetectionNotVsFourSpells()
            || !dfaNondetectionNotVsLegendaryOrDeities()
            || !dfaSenseSecondPurchaseExtra()
            || !dfaSenseImprovesAllSubskills()
            || !dfaSenseAmbushOncePerTurn()
            || !dfaSenseAmbushRevealsCountAndSize()
            || !dfaSenseConcealedRevealsSizeLocationType()
            || !dfaSenseUnknownCreatureAttackModes()
            || !dfaSenseMagicalConcealmentDetected()
            || !dfaSenseHostilityNotPreparedness()
            || !dfaSenseImpendingDirectionAndDistance()
            || !dfaSenseImpendingMustFace()
            || !dfaSenseSecretRolls()
            || !dfaSenseFalseNotImpending()
            || !dfaFlightLikeShadowTravel()
            || !dfaFlightNeedsHideInShadows()
            || !dfaFlightNoFlightWithoutShadow()
            || !dfaFlightLeapNeedsAsShadowy()
            || !dfaFlightLightEncumbranceOnly()
            || !dfaFlightCarryWithinLimit()
            || !dfaShadowNeedsHideInShadows()
            || !dfaShadowNoShadowsNormal()
            || !dfaShadowVisibleBetweenShadows()
            || !dfaShadowEndsOnAttack()
            || !dfaShadowNotSilent()
            || !dfaShadowTerrainAndEncumbranceApply()
        )
            ++bad;
        // the dfaT47Grid grid
        int CT47r[11][5] = {
            {2200000,7,8,10,20},
            {2420000,7,8,10,22},
            {2640000,7,8,10,24},
            {2860000,7,8,10,26},
            {3080000,8,9,10,28},
            {3300000,8,9,10,30},
            {3520000,8,9,10,32},
            {3740000,8,9,10,34},
            {3960000,9,10,10,36},
            {4180000,9,10,10,38},
            {4300000,9,10,10,40},
            };
        for (int b = 0;
             b < dfaT47RowCount();
             ++b) {
            int vals[5];
            vals[0] = dfaT47Xp(b);
            vals[1] = dfaT47WeaponProf(b);
            vals[2] = dfaT47NonweaponProf(b);
            vals[3] = dfaT47HpBaseCol(b);
            vals[4] = dfaT47HpBonus(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CT47r[b][c])
                    ++bad;
            }
        }
        // the dfaT49Grid grid
        int CT49[5][6] = {
            {-5,15,5,5,0,0},
            {5,0,10,5,0,0},
            {5,10,5,5,5,0},
            {0,0,0,0,10,0},
            {10,-10,5,-5,5,0},
            };
        for (int b = 0;
             b < dfaT49RowCount();
             ++b) {
            int vals[6];
            vals[0] = dfaT49Dwarf(b);
            vals[1] = dfaT49Elf(b);
            vals[2] = dfaT49Gnome(b);
            vals[3] = dfaT49Halfelf(b);
            vals[4] = dfaT49Halfling(b);
            vals[5] = dfaT49Human(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CT49[b][c])
                    ++bad;
            }
        }
        // the dfaT50Grid grid
        int CT50[2][10] = {
            {-15,-10,-5,0,5,10,15,20,25,30},
            {-10,-5,0,0,0,5,10,15,20,30},
            };
        for (int b = 0;
             b < dfaT50RowCount();
             ++b) {
            int vals[10];
            vals[0] = dfaT50Dex9(b);
            vals[1] = dfaT50Dex10(b);
            vals[2] = dfaT50Dex11(b);
            vals[3] = dfaT50Dex1216(b);
            vals[4] = dfaT50Dex17(b);
            vals[5] = dfaT50Dex18(b);
            vals[6] = dfaT50Dex19(b);
            vals[7] = dfaT50Dex20(b);
            vals[8] = dfaT50Dex21(b);
            vals[9] = dfaT50Dex22(b);
            for (int c = 0; c < 10;
                 ++c) {
                if (vals[c] != CT50[b][c])
                    ++bad;
            }
        }
        // the dfaT51Grid grid
        int CT51[3][3] = {
            {-10,5,-5},
            {5,-5,-5},
            {10,-5,-10},
            };
        for (int b = 0;
             b < dfaT51RowCount();
             ++b) {
            int vals[3];
            vals[0] = dfaT51NoArmor(b);
            vals[1] = dfaT51ElvenChain(b);
            vals[2] = dfaT51Leather(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT51[b][c])
                    ++bad;
            }
        }
        // the dfaBribeGrid grid
        int Cbribe[4][2] = {
            {2,4},
            {3,8},
            {5,10},
            {5,100},
            };
        for (int b = 0;
             b < dfaBribeRowCount();
             ++b) {
            int vals[2];
            vals[0] = dfaBribeDice(b);
            vals[1] = dfaBribeSides(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != Cbribe[b][c])
                    ++bad;
            }
        }
        // the dfaTunnelGrid grid
        int Ctunnel[3][2] = {
            {-10,5},
            {0,10},
            {10,30},
            };
        for (int b = 0;
             b < dfaTunnelRowCount();
             ++b) {
            int vals[2];
            vals[0] = dfaTunnelMod(b);
            vals[1] = dfaTunnelHours(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != Ctunnel[b][c])
                    ++bad;
            }
        }
        // the dfaT52Grid grid
        int CT52[11][8] = {
            {4,4,4,4,4,3,0,0},
            {4,4,4,4,4,4,1,0},
            {4,4,4,4,4,4,2,0},
            {4,4,4,4,4,4,3,0},
            {4,4,4,4,4,4,4,0},
            {5,5,4,4,4,4,4,0},
            {5,5,5,5,4,4,4,0},
            {5,5,5,5,5,5,4,0},
            {6,5,5,5,5,5,5,0},
            {6,6,5,5,5,5,5,1},
            {6,6,6,6,5,5,5,1},
            };
        for (int b = 0;
             b < dfaT52RowCount();
             ++b) {
            int vals[8];
            vals[0] = dfaT52L1(b);
            vals[1] = dfaT52L2(b);
            vals[2] = dfaT52L3(b);
            vals[3] = dfaT52L4(b);
            vals[4] = dfaT52L5(b);
            vals[5] = dfaT52L6(b);
            vals[6] = dfaT52L7(b);
            vals[7] = dfaT52L8(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != CT52[b][c])
                    ++bad;
            }
        }
        // the dfaFallSurfaceGrid grid
        int Cfallsurf[7][1] = {
            {1},
            {2},
            {3},
            {5},
            {7},
            {9},
            {11},
            };
        for (int b = 0;
             b < dfaFallSurfaceRowCount();
             ++b) {
            int vals[1];
            vals[0] = dfaFallSurface(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != Cfallsurf[b][c])
                    ++bad;
            }
        }
        // the dfaFeatherGrid grid
        int Cfeather[3][2] = {
            {30,12},
            {60,15},
            {120,18},
            };
        for (int b = 0;
             b < dfaFeatherRowCount();
             ++b) {
            int vals[2];
            vals[0] = dfaFeatherDistance(b);
            vals[1] = dfaFeatherMove(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != Cfeather[b][c])
                    ++bad;
            }
        }
        // the dfaThiefScrollBand band-for boundaries
    if (dfaThiefScrollBand(22) != 0
            || dfaThiefScrollBand(23) != 0
            || dfaThiefScrollBand(26) != 1
            || dfaThiefScrollBand(24) != 1
            || dfaThiefScrollBand(28) != 2
            || dfaThiefScrollBand(27) != 2
            || dfaThiefScrollBand(29) != 3
        )
            ++bad;
        // the dfaBardScrollBand band-for boundaries
    if (dfaBardScrollBand(19) != 0
            || dfaBardScrollBand(20) != 0
            || dfaBardScrollBand(23) != 1
            || dfaBardScrollBand(21) != 1
            || dfaBardScrollBand(26) != 2
            || dfaBardScrollBand(24) != 2
            || dfaBardScrollBand(29) != 3
            || dfaBardScrollBand(27) != 3
            || dfaBardScrollBand(30) != 4
        )
            ++bad;
        // the dfaFallBand band-for boundaries
    if (dfaFallBand(12) != 0
            || dfaFallBand(13) != 0
            || dfaFallBand(16) != 1
            || dfaFallBand(14) != 1
            || dfaFallBand(19) != 2
            || dfaFallBand(17) != 2
            || dfaFallBand(21) != 3
            || dfaFallBand(20) != 3
            || dfaFallBand(24) != 4
            || dfaFallBand(22) != 4
            || dfaFallBand(27) != 5
            || dfaFallBand(25) != 5
            || dfaFallBand(28) != 6
        )
            ++bad;
        // the dfaFeatherBand band-for boundaries
    if (dfaFeatherBand(12) != 0
            || dfaFeatherBand(13) != 0
            || dfaFeatherBand(16) != 1
            || dfaFeatherBand(14) != 1
            || dfaFeatherBand(17) != 2
        )
            ++bad;
        // the dfaFocusBand band-for boundaries
    if (dfaFocusBand(14) != 0
            || dfaFocusBand(15) != 0
            || dfaFocusBand(20) != 1
            || dfaFocusBand(16) != 1
            || dfaFocusBand(25) != 2
            || dfaFocusBand(21) != 2
            || dfaFocusBand(26) != 3
        )
            ++bad;
        // the dfaSenseBand band-for boundaries
    if (dfaSenseBand(14) != 0
            || dfaSenseBand(15) != 0
            || dfaSenseBand(20) != 1
            || dfaSenseBand(16) != 1
            || dfaSenseBand(25) != 2
            || dfaSenseBand(21) != 2
            || dfaSenseBand(26) != 3
        )
            ++bad;
        // the dfaRogueSkillStartLevel pin
    if (dfaRogueSkillStartLevel() != 11
        )
            ++bad;
        // the dfaRogueAdvLimit pin
    if (dfaRogueAdvLimit() != 30
        )
            ++bad;
        // the dfaRogueExtraAbilityLevel pin
    if (dfaRogueExtraAbilityLevel() != 21
        )
            ++bad;
        // the dfaThiefScoreCap pin
    if (dfaThiefScoreCap() != 95
        )
            ++bad;
        // the dfaThiefCapLiftLevel pin
    if (dfaThiefCapLiftLevel() != 11
        )
            ++bad;
        // the dfaThiefAutoFailRoll pin
    if (dfaThiefAutoFailRoll() != 96
        )
            ++bad;
        // the dfaJobareTrapScore pin
    if (dfaJobareTrapScore() != 120
        )
            ++bad;
        // the dfaJobareMagicalTrapChance pin
    if (dfaJobareMagicalTrapChance() != 60
        )
            ++bad;
        // the dfaJobareLockScore pin
    if (dfaJobareLockScore() != 100
        )
            ++bad;
        // the dfaJobareMasterfulPenalty pin
    if (dfaJobareMasterfulPenalty() != 60
        )
            ++bad;
        // the dfaJobareMasterfulChance pin
    if (dfaJobareMasterfulChance() != 40
        )
            ++bad;
        // the dfaT47RowCount pin
    if (dfaT47RowCount() != 11
        )
            ++bad;
        // the dfaT47XpBase pin
    if (dfaT47XpBase() != 2200000
        )
            ++bad;
        // the dfaT47XpStep pin
    if (dfaT47XpStep() != 220000
        )
            ++bad;
        // the dfaT47Xp30 pin
    if (dfaT47Xp30() != 4300000
        )
            ++bad;
        // the dfaT47HpBase pin
    if (dfaT47HpBase() != 10
        )
            ++bad;
        // the dfaT47HpStep pin
    if (dfaT47HpStep() != 2
        )
            ++bad;
        // the dfaNewThiefSkillCount pin
    if (dfaNewThiefSkillCount() != 5
        )
            ++bad;
        // the dfaBribeBase pin
    if (dfaBribeBase() != 5
        )
            ++bad;
        // the dfaDetectIllusionBase pin
    if (dfaDetectIllusionBase() != 10
        )
            ++bad;
        // the dfaDetectMagicBase pin
    if (dfaDetectMagicBase() != 5
        )
            ++bad;
        // the dfaEscapeBondsBase pin
    if (dfaEscapeBondsBase() != 10
        )
            ++bad;
        // the dfaTunnelingBase pin
    if (dfaTunnelingBase() != 15
        )
            ++bad;
        // the dfaT49RowCount pin
    if (dfaT49RowCount() != 5
        )
            ++bad;
        // the dfaT50RowCount pin
    if (dfaT50RowCount() != 2
        )
            ++bad;
        // the dfaT51RowCount pin
    if (dfaT51RowCount() != 3
        )
            ++bad;
        // the dfaBribeRowCount pin
    if (dfaBribeRowCount() != 4
        )
            ++bad;
        // the dfaJobareReactionRoll pin
    if (dfaJobareReactionRoll() != 13
        )
            ++bad;
        // the dfaJobareFriendlyMax pin
    if (dfaJobareFriendlyMax() != 7
        )
            ++bad;
        // the dfaJobareBribeDiff pin
    if (dfaJobareBribeDiff() != 6
        )
            ++bad;
        // the dfaJobareBaseBribeCp pin
    if (dfaJobareBaseBribeCp() != 5
        )
            ++bad;
        // the dfaJobarePaidCp pin
    if (dfaJobarePaidCp() != 30
        )
            ++bad;
        // the dfaDetectIllusionRange pin
    if (dfaDetectIllusionRange() != 90
        )
            ++bad;
        // the dfaDetectMagicRange pin
    if (dfaDetectMagicRange() != 60
        )
            ++bad;
        // the dfaDetectMagicIntensityCount pin
    if (dfaDetectMagicIntensityCount() != 5
        )
            ++bad;
        // the dfaEscapeBondsRounds pin
    if (dfaEscapeBondsRounds() != 5
        )
            ++bad;
        // the dfaEscapeBondsHurryPenalty pin
    if (dfaEscapeBondsHurryPenalty() != 5
        )
            ++bad;
        // the dfaTunnelChunkFeet pin
    if (dfaTunnelChunkFeet() != 10
        )
            ++bad;
        // the dfaTunnelRowCount pin
    if (dfaTunnelRowCount() != 3
        )
            ++bad;
        // the dfaThiefSkillBonusCp pin
    if (dfaThiefSkillBonusCp() != 50
        )
            ++bad;
        // the dfaThiefSpSkillThreshold pin
    if (dfaThiefSpSkillThreshold() != 9
        )
            ++bad;
        // the dfaThiefScrollLevel pin
    if (dfaThiefScrollLevel() != 24
        )
            ++bad;
        // the dfaThiefScrollFailPct pin
    if (dfaThiefScrollFailPct() != 25
        )
            ++bad;
        // the dfaBardNewSkillCount pin
    if (dfaBardNewSkillCount() != 2
        )
            ++bad;
        // the dfaBardNewSkillLevel pin
    if (dfaBardNewSkillLevel() != 21
        )
            ++bad;
        // the dfaBardSkillBonusCp pin
    if (dfaBardSkillBonusCp() != 20
        )
            ++bad;
        // the dfaBardScrollLevel pin
    if (dfaBardScrollLevel() != 21
        )
            ++bad;
        // the dfaBardScrollFailPct pin
    if (dfaBardScrollFailPct() != 15
        )
            ++bad;
        // the dfaBardIdentifyLevel pin
    if (dfaBardIdentifyLevel() != 21
        )
            ++bad;
        // the dfaBardIdentifyChance pin
    if (dfaBardIdentifyChance() != 55
        )
            ++bad;
        // the dfaBardItemUseLevel pin
    if (dfaBardItemUseLevel() != 24
        )
            ++bad;
        // the dfaBardItemCreationLevel pin
    if (dfaBardItemCreationLevel() != 27
        )
            ++bad;
        // the dfaT52RowCount pin
    if (dfaT52RowCount() != 11
        )
            ++bad;
        // the dfaAdaptInitPenaltyAvoided pin
    if (dfaAdaptInitPenaltyAvoided() != 6
        )
            ++bad;
        // the dfaAdaptCheckBonus pin
    if (dfaAdaptCheckBonus() != 3
        )
            ++bad;
        // the dfaAdaptBlindCheckPenalty pin
    if (dfaAdaptBlindCheckPenalty() != 4
        )
            ++bad;
        // the dfaAdaptPracticeHours pin
    if (dfaAdaptPracticeHours() != 8
        )
            ++bad;
        // the dfaAdaptPermanentCp pin
    if (dfaAdaptPermanentCp() != 3
        )
            ++bad;
        // the dfaClassifyExamTurns pin
    if (dfaClassifyExamTurns() != 1
        )
            ++bad;
        // the dfaClassifyFalseRoll pin
    if (dfaClassifyFalseRoll() != 20
        )
            ++bad;
        // the dfaClassifyEvasionSaveBonus pin
    if (dfaClassifyEvasionSaveBonus() != 2
        )
            ++bad;
        // the dfaFallSafeBase pin
    if (dfaFallSafeBase() != 30
        )
            ++bad;
        // the dfaFallSurfaceRowCount pin
    if (dfaFallSurfaceRowCount() != 7
        )
            ++bad;
        // the dfaJobareFallLevel pin
    if (dfaJobareFallLevel() != 20
        )
            ++bad;
        // the dfaJobareShaftFeet pin
    if (dfaJobareShaftFeet() != 150
        )
            ++bad;
        // the dfaJobareChamberFeet pin
    if (dfaJobareChamberFeet() != 30
        )
            ++bad;
        // the dfaJobareBreakFeet pin
    if (dfaJobareBreakFeet() != 120
        )
            ++bad;
        // the dfaJobareFinalFeet pin
    if (dfaJobareFinalFeet() != 60
        )
            ++bad;
        // the dfaJobareFallDice pin
    if (dfaJobareFallDice() != 6
        )
            ++bad;
        // the dfaJobareFallSides pin
    if (dfaJobareFallSides() != 6
        )
            ++bad;
        // the dfaJobare30thDice pin
    if (dfaJobare30thDice() != 3
        )
            ++bad;
        // the dfaJobare30thFeet pin
    if (dfaJobare30thFeet() != 30
        )
            ++bad;
        // the dfaFeatherRowCount pin
    if (dfaFeatherRowCount() != 3
        )
            ++bad;
        // the dfaImprovisedDailyPerLearning pin
    if (dfaImprovisedDailyPerLearning() != 1
        )
            ++bad;
        // the dfaImprovisedBlindPenalty pin
    if (dfaImprovisedBlindPenalty() != 4
        )
            ++bad;
        // the dfaImprovisedBlindClearRoll pin
    if (dfaImprovisedBlindClearRoll() != 9
        )
            ++bad;
        // the dfaImprovisedImmobFreeRoll pin
    if (dfaImprovisedImmobFreeRoll() != 9
        )
            ++bad;
        // the dfaImprovisedKillHpOffset pin
    if (dfaImprovisedKillHpOffset() != 10
        )
            ++bad;
        // the dfaImprovisedStunDice pin
    if (dfaImprovisedStunDice() != 2
        )
            ++bad;
        // the dfaImprovisedStunSides pin
    if (dfaImprovisedStunSides() != 4
        )
            ++bad;
        // the dfaImprovisedStunPenalty pin
    if (dfaImprovisedStunPenalty() != 2
        )
            ++bad;
        // the dfaImprovisedTripLowSides pin
    if (dfaImprovisedTripLowSides() != 3
        )
            ++bad;
        // the dfaImprovisedTripHighSides pin
    if (dfaImprovisedTripHighSides() != 6
        )
            ++bad;
        // the dfaImprovisedSaveNoRoleplay pin
    if (dfaImprovisedSaveNoRoleplay() != 6
        )
            ++bad;
        // the dfaImprovisedSaveFeeble pin
    if (dfaImprovisedSaveFeeble() != 4
        )
            ++bad;
        // the dfaImprovisedSaveTrickAdventure pin
    if (dfaImprovisedSaveTrickAdventure() != 2
        )
            ++bad;
        // the dfaImprovisedSaveTrickEncounter pin
    if (dfaImprovisedSaveTrickEncounter() != 4
        )
            ++bad;
        // the dfaImprovisedSaveSameCreatureAdventure pin
    if (dfaImprovisedSaveSameCreatureAdventure() != 6
        )
            ++bad;
        // the dfaImprovisedSaveSameCreatureEncounter pin
    if (dfaImprovisedSaveSameCreatureEncounter() != 8
        )
            ++bad;
        // the dfaImprovisedSaveSurprised pin
    if (dfaImprovisedSaveSurprised() != 2
        )
            ++bad;
        // the dfaImprovisedSaveAppropriate pin
    if (dfaImprovisedSaveAppropriate() != 4
        )
            ++bad;
        // the dfaJobareSurpriseRoll pin
    if (dfaJobareSurpriseRoll() != 2
        )
            ++bad;
        // the dfaFocusBoostBase pin
    if (dfaFocusBoostBase() != 18
        )
            ++bad;
        // the dfaFocusOtherPenalty pin
    if (dfaFocusOtherPenalty() != 2
        )
            ++bad;
        // the dfaFocusDurationPerLevel pin
    if (dfaFocusDurationPerLevel() != 1
        )
            ++bad;
        // the dfaFocusAttemptCost pin
    if (dfaFocusAttemptCost() != 2
        )
            ++bad;
        // the dfaNondetectionSpellLevel pin
    if (dfaNondetectionSpellLevel() != 3
        )
            ++bad;
        // the dfaSenseSubskillCount pin
    if (dfaSenseSubskillCount() != 4
        )
            ++bad;
        // the dfaSenseAmbushYards pin
    if (dfaSenseAmbushYards() != 200
        )
            ++bad;
        // the dfaSenseImpendingSurpriseBonus pin
    if (dfaSenseImpendingSurpriseBonus() != 2
        )
            ++bad;
        // the dfaSenseImpendingInitBonus pin
    if (dfaSenseImpendingInitBonus() != 1
        )
            ++bad;
        // the dfaSenseFalseRoll pin
    if (dfaSenseFalseRoll() != 20
        )
            ++bad;
        // the dfaSenseAlertnessBonus pin
    if (dfaSenseAlertnessBonus() != 1
        )
            ++bad;
        // the dfaFlightWeakRate pin
    if (dfaFlightWeakRate() != 15
        )
            ++bad;
        // the dfaFlightStrongRate pin
    if (dfaFlightStrongRate() != 18
        )
            ++bad;
        // the dfaFlightVeryRate pin
    if (dfaFlightVeryRate() != 24
        )
            ++bad;
        // the dfaFlightLeapYards pin
    if (dfaFlightLeapYards() != 360
        )
            ++bad;
        // the dfaFlightLeapPerHour pin
    if (dfaFlightLeapPerHour() != 1
        )
            ++bad;
        // the dfaShadowWeakRate pin
    if (dfaShadowWeakRate() != 15
        )
            ++bad;
        // the dfaShadowStrongRate pin
    if (dfaShadowStrongRate() != 18
        )
            ++bad;
        // the dfaShadowVeryRate pin
    if (dfaShadowVeryRate() != 24
        )
            ++bad;
        // the dfaThief95CapSpendElsewhere pin
    if (dfaThief95CapSpendElsewhere() != 1
        )
            ++bad;
        // the dfaThiefAll95PointsLost pin
    if (dfaThiefAll95PointsLost() != 1
        )
            ++bad;
        // the dfaThiefLostPointsNotRegained pin
    if (dfaThiefLostPointsNotRegained() != 1
        )
            ++bad;
        // the dfaThiefPenaltiesFromBase pin
    if (dfaThiefPenaltiesFromBase() != 1
        )
            ++bad;
        // the dfaT47FinalStepShort pin
    if (dfaT47FinalStepShort() != 1
        )
            ++bad;
        // the dfaT47ConBonusStopsAfter10 pin
    if (dfaT47ConBonusStopsAfter10() != 1
        )
            ++bad;
        // the dfaT47CaptionSharesPrintedNumber pin
    if (dfaT47CaptionSharesPrintedNumber() != 1
        )
            ++bad;
        // the dfaNewSkillsApplyPointsImmediately pin
    if (dfaNewSkillsApplyPointsImmediately() != 1
        )
            ++bad;
        // the dfaT49HalflingDetectMagicNoPercent pin
    if (dfaT49HalflingDetectMagicNoPercent() != 1
        )
            ++bad;
        // the dfaT50TunnelingDashAt17 pin
    if (dfaT50TunnelingDashAt17() != 1
        )
            ++bad;
        // the dfaBribeOneAttemptPerTarget pin
    if (dfaBribeOneAttemptPerTarget() != 1
        )
            ++bad;
        // the dfaBribeFailReactionRoll pin
    if (dfaBribeFailReactionRoll() != 1
        )
            ++bad;
        // the dfaBribeNotEveryoneSusceptible pin
    if (dfaBribeNotEveryoneSusceptible() != 1
        )
            ++bad;
        // the dfaBribeNotOutsideStation pin
    if (dfaBribeNotOutsideStation() != 1
        )
            ++bad;
        // the dfaBribeNeverDangerousOrLong pin
    if (dfaBribeNeverDangerousOrLong() != 1
        )
            ++bad;
        // the dfaBribeNeverAgainstBeliefs pin
    if (dfaBribeNeverAgainstBeliefs() != 1
        )
            ++bad;
        // the dfaBribeSecretReactionRoll pin
    if (dfaBribeSecretReactionRoll() != 1
        )
            ++bad;
        // the dfaBribeFriendlyNeedsNoBribe pin
    if (dfaBribeFriendlyNeedsNoBribe() != 1
        )
            ++bad;
        // the dfaBribeMultiplyByDifference pin
    if (dfaBribeMultiplyByDifference() != 1
        )
            ++bad;
        // the dfaBribePlayerNeverToldValues pin
    if (dfaBribePlayerNeverToldValues() != 1
        )
            ++bad;
        // the dfaDetectIllusionNeedsRound pin
    if (dfaDetectIllusionNeedsRound() != 1
        )
            ++bad;
        // the dfaDetectIllusionTranslucent pin
    if (dfaDetectIllusionTranslucent() != 1
        )
            ++bad;
        // the dfaDetectIllusionNotVsNonvisible pin
    if (dfaDetectIllusionNotVsNonvisible() != 1
        )
            ++bad;
        // the dfaDetectIllusionNotFailSafe pin
    if (dfaDetectIllusionNotFailSafe() != 1
        )
            ++bad;
        // the dfaDetectMagicBlockedLikeSpell pin
    if (dfaDetectMagicBlockedLikeSpell() != 1
        )
            ++bad;
        // the dfaEscapeBondsRollPerDevice pin
    if (dfaEscapeBondsRollPerDevice() != 1
        )
            ++bad;
        // the dfaEscapeBondsLockedNeedPicks pin
    if (dfaEscapeBondsLockedNeedPicks() != 1
        )
            ++bad;
        // the dfaEscapeBondsFailCantRetryThatBond pin
    if (dfaEscapeBondsFailCantRetryThatBond() != 1
        )
            ++bad;
        // the dfaTunnelCollapseOnFail pin
    if (dfaTunnelCollapseOnFail() != 1
        )
            ++bad;
        // the dfaTunnelRedugAtLooseRate pin
    if (dfaTunnelRedugAtLooseRate() != 1
        )
            ++bad;
        // the dfaThiefSpOverflowToProficiencies pin
    if (dfaThiefSpOverflowToProficiencies() != 1
        )
            ++bad;
        // the dfaThiefExtraSkillsOnlyAt21st pin
    if (dfaThiefExtraSkillsOnlyAt21st() != 1
        )
            ++bad;
        // the dfaThiefScrollNoFailAtOrBelow pin
    if (dfaThiefScrollNoFailAtOrBelow() != 1
        )
            ++bad;
        // the dfaBardScrollWizardNoFailIfCastable pin
    if (dfaBardScrollWizardNoFailIfCastable() != 1
        )
            ++bad;
        // the dfaBardIdentifyNoBonusesCharges pin
    if (dfaBardIdentifyNoBonusesCharges() != 1
        )
            ++bad;
        // the dfaBardIdentifyNoHandling pin
    if (dfaBardIdentifyNoHandling() != 1
        )
            ++bad;
        // the dfaAdaptLikeWarriorSkill pin
    if (dfaAdaptLikeWarriorSkill() != 1
        )
            ++bad;
        // the dfaAdaptNoSituationalOrNoncombat pin
    if (dfaAdaptNoSituationalOrNoncombat() != 1
        )
            ++bad;
        // the dfaAdaptNoMagicalOrVisionPenalties pin
    if (dfaAdaptNoMagicalOrVisionPenalties() != 1
        )
            ++bad;
        // the dfaAdaptCheckEachRound pin
    if (dfaAdaptCheckEachRound() != 1
        )
            ++bad;
        // the dfaAdaptLastsBattlePlusDays pin
    if (dfaAdaptLastsBattlePlusDays() != 1
        )
            ++bad;
        // the dfaAdaptPermanentBeforeFade pin
    if (dfaAdaptPermanentBeforeFade() != 1
        )
            ++bad;
        // the dfaClassifyNeedsFindTraps pin
    if (dfaClassifyNeedsFindTraps() != 1
        )
            ++bad;
        // the dfaClassifyRevealsExactNature pin
    if (dfaClassifyRevealsExactNature() != 1
        )
            ++bad;
        // the dfaClassifyMagicalHalvedRoundUp pin
    if (dfaClassifyMagicalHalvedRoundUp() != 1
        )
            ++bad;
        // the dfaClassifyFailUnder20LearnsNothing pin
    if (dfaClassifyFailUnder20LearnsNothing() != 1
        )
            ++bad;
        // the dfaClassifySecretRoll pin
    if (dfaClassifySecretRoll() != 1
        )
            ++bad;
        // the dfaClassifyTwoRemoveRollsBest pin
    if (dfaClassifyTwoRemoveRollsBest() != 1
        )
            ++bad;
        // the dfaClassifyBypassSaveVsBreath pin
    if (dfaClassifyBypassSaveVsBreath() != 1
        )
            ++bad;
        // the dfaClassifyCompanionsMaySave pin
    if (dfaClassifyCompanionsMaySave() != 1
        )
            ++bad;
        // the dfaClassifyNoHalfEffectRuling pin
    if (dfaClassifyNoHalfEffectRuling() != 1
        )
            ++bad;
        // the dfaEvasionAutomatic pin
    if (dfaEvasionAutomatic() != 1
        )
            ++bad;
        // the dfaEvasionNoDamageOnSave pin
    if (dfaEvasionNoDamageOnSave() != 1
        )
            ++bad;
        // the dfaEvasionNotVsNonDamage pin
    if (dfaEvasionNotVsNonDamage() != 1
        )
            ++bad;
        // the dfaEvasionFixedMissilesOnly pin
    if (dfaEvasionFixedMissilesOnly() != 1
        )
            ++bad;
        // the dfaEvasionNeedsNotSurprised pin
    if (dfaEvasionNeedsNotSurprised() != 1
        )
            ++bad;
        // the dfaFallAlwaysWithinOneFoot pin
    if (dfaFallAlwaysWithinOneFoot() != 1
        )
            ++bad;
        // the dfaFallFrictionSurfacesOk pin
    if (dfaFallFrictionSurfacesOk() != 1
        )
            ++bad;
        // the dfaFallDamageOnExcess pin
    if (dfaFallDamageOnExcess() != 1
        )
            ++bad;
        // the dfaFeatherNeedsMoveSilently pin
    if (dfaFeatherNeedsMoveSilently() != 1
        )
            ++bad;
        // the dfaFeatherMustStopAtDistance pin
    if (dfaFeatherMustStopAtDistance() != 1
        )
            ++bad;
        // the dfaFeatherSilentNoTracks pin
    if (dfaFeatherSilentNoTracks() != 1
        )
            ++bad;
        // the dfaFeatherNoWeightTriggers pin
    if (dfaFeatherNoWeightTriggers() != 1
        )
            ++bad;
        // the dfaImprovisedLearnMultipleTimes pin
    if (dfaImprovisedLearnMultipleTimes() != 1
        )
            ++bad;
        // the dfaImprovisedBlindfightingNoHelp pin
    if (dfaImprovisedBlindfightingNoHelp() != 1
        )
            ++bad;
        // the dfaImprovisedDisarmStuckNeedsOpenDoors pin
    if (dfaImprovisedDisarmStuckNeedsOpenDoors() != 1
        )
            ++bad;
        // the dfaImprovisedKillHigherHdImmune pin
    if (dfaImprovisedKillHigherHdImmune() != 1
        )
            ++bad;
        // the dfaImprovisedStunNoSpellsAttack pin
    if (dfaImprovisedStunNoSpellsAttack() != 1
        )
            ++bad;
        // the dfaImprovisedAnnounceDeclareDescribe pin
    if (dfaImprovisedAnnounceDeclareDescribe() != 1
        )
            ++bad;
        // the dfaImprovisedNormalAttackRoll pin
    if (dfaImprovisedNormalAttackRoll() != 1
        )
            ++bad;
        // the dfaImprovisedSuccessNoDamage pin
    if (dfaImprovisedSuccessNoDamage() != 1
        )
            ++bad;
        // the dfaImprovisedSaveUnlikelyRange pin
    if (dfaImprovisedSaveUnlikelyRange() != 1
        )
            ++bad;
        // the dfaImprovisedSaveAutoIfInadequate pin
    if (dfaImprovisedSaveAutoIfInadequate() != 1
        )
            ++bad;
        // the dfaImprovisedTable3638Optional pin
    if (dfaImprovisedTable3638Optional() != 1
        )
            ++bad;
        // the dfaImprovisedTrickThreeAdventures pin
    if (dfaImprovisedTrickThreeAdventures() != 1
        )
            ++bad;
        // the dfaImprovisedTrickOncePerEncounter pin
    if (dfaImprovisedTrickOncePerEncounter() != 1
        )
            ++bad;
        // the dfaImprovisedTrickNotDailyAllotment pin
    if (dfaImprovisedTrickNotDailyAllotment() != 1
        )
            ++bad;
        // the dfaImprovisedTrickPreparedPlus6 pin
    if (dfaImprovisedTrickPreparedPlus6() != 1
        )
            ++bad;
        // the dfaJobareHatBlindExample pin
    if (dfaJobareHatBlindExample() != 1
        )
            ++bad;
        // the dfaFocusLikeWarriorSkill pin
    if (dfaFocusLikeWarriorSkill() != 1
        )
            ++bad;
        // the dfaFocusAlreadyHigherNoEffect pin
    if (dfaFocusAlreadyHigherNoEffect() != 1
        )
            ++bad;
        // the dfaFocusEndAtWill pin
    if (dfaFocusEndAtWill() != 1
        )
            ++bad;
        // the dfaFocusSubabilitiesRaisedEqual pin
    if (dfaFocusSubabilitiesRaisedEqual() != 1
        )
            ++bad;
        // the dfaFocusOneBoostAtATime pin
    if (dfaFocusOneBoostAtATime() != 1
        )
            ++bad;
        // the dfaFocusNoOtherActions pin
    if (dfaFocusNoOtherActions() != 1
        )
            ++bad;
        // the dfaFocusBonusesImmediate pin
    if (dfaFocusBonusesImmediate() != 1
        )
            ++bad;
        // the dfaNondetectionBeatsDivinations pin
    if (dfaNondetectionBeatsDivinations() != 1
        )
            ++bad;
        // the dfaNondetectionSavesEvenOnFail pin
    if (dfaNondetectionSavesEvenOnFail() != 1
        )
            ++bad;
        // the dfaNondetectionBeatsSenseDanger pin
    if (dfaNondetectionBeatsSenseDanger() != 1
        )
            ++bad;
        // the dfaNondetectionBeatsDetectDeception pin
    if (dfaNondetectionBeatsDetectDeception() != 1
        )
            ++bad;
        // the dfaNondetectionOpposedWillpower pin
    if (dfaNondetectionOpposedWillpower() != 1
        )
            ++bad;
        // the dfaNondetectionNotVsFourSpells pin
    if (dfaNondetectionNotVsFourSpells() != 1
        )
            ++bad;
        // the dfaNondetectionNotVsLegendaryOrDeities pin
    if (dfaNondetectionNotVsLegendaryOrDeities() != 1
        )
            ++bad;
        // the dfaSenseSecondPurchaseExtra pin
    if (dfaSenseSecondPurchaseExtra() != 1
        )
            ++bad;
        // the dfaSenseImprovesAllSubskills pin
    if (dfaSenseImprovesAllSubskills() != 1
        )
            ++bad;
        // the dfaSenseAmbushOncePerTurn pin
    if (dfaSenseAmbushOncePerTurn() != 1
        )
            ++bad;
        // the dfaSenseAmbushRevealsCountAndSize pin
    if (dfaSenseAmbushRevealsCountAndSize() != 1
        )
            ++bad;
        // the dfaSenseConcealedRevealsSizeLocationType pin
    if (dfaSenseConcealedRevealsSizeLocationType() != 1
        )
            ++bad;
        // the dfaSenseUnknownCreatureAttackModes pin
    if (dfaSenseUnknownCreatureAttackModes() != 1
        )
            ++bad;
        // the dfaSenseMagicalConcealmentDetected pin
    if (dfaSenseMagicalConcealmentDetected() != 1
        )
            ++bad;
        // the dfaSenseHostilityNotPreparedness pin
    if (dfaSenseHostilityNotPreparedness() != 1
        )
            ++bad;
        // the dfaSenseImpendingDirectionAndDistance pin
    if (dfaSenseImpendingDirectionAndDistance() != 1
        )
            ++bad;
        // the dfaSenseImpendingMustFace pin
    if (dfaSenseImpendingMustFace() != 1
        )
            ++bad;
        // the dfaSenseSecretRolls pin
    if (dfaSenseSecretRolls() != 1
        )
            ++bad;
        // the dfaSenseFalseNotImpending pin
    if (dfaSenseFalseNotImpending() != 1
        )
            ++bad;
        // the dfaFlightLikeShadowTravel pin
    if (dfaFlightLikeShadowTravel() != 1
        )
            ++bad;
        // the dfaFlightNeedsHideInShadows pin
    if (dfaFlightNeedsHideInShadows() != 1
        )
            ++bad;
        // the dfaFlightNoFlightWithoutShadow pin
    if (dfaFlightNoFlightWithoutShadow() != 1
        )
            ++bad;
        // the dfaFlightLeapNeedsAsShadowy pin
    if (dfaFlightLeapNeedsAsShadowy() != 1
        )
            ++bad;
        // the dfaFlightLightEncumbranceOnly pin
    if (dfaFlightLightEncumbranceOnly() != 1
        )
            ++bad;
        // the dfaFlightCarryWithinLimit pin
    if (dfaFlightCarryWithinLimit() != 1
        )
            ++bad;
        // the dfaShadowNeedsHideInShadows pin
    if (dfaShadowNeedsHideInShadows() != 1
        )
            ++bad;
        // the dfaShadowNoShadowsNormal pin
    if (dfaShadowNoShadowsNormal() != 1
        )
            ++bad;
        // the dfaShadowVisibleBetweenShadows pin
    if (dfaShadowVisibleBetweenShadows() != 1
        )
            ++bad;
        // the dfaShadowEndsOnAttack pin
    if (dfaShadowEndsOnAttack() != 1
        )
            ++bad;
        // the dfaShadowNotSilent pin
    if (dfaShadowNotSilent() != 1
        )
            ++bad;
        // the dfaShadowTerrainAndEncumbranceApply pin
    if (dfaShadowTerrainAndEncumbranceApply() != 1
        )
            ++bad;
        // the Jobare doctrine examples (printed p. 167)
    if (dfaJobareTrapScore() / 2 != dfaJobareMagicalTrapChance()
            || dfaJobareLockScore() - dfaJobareMasterfulPenalty() !=
            dfaJobareMasterfulChance()
        )
            ++bad;
        // the Table 47r experience steps (printed p. 168)
    if (dfaT47Xp(1) - dfaT47Xp(0) != 220000
            || dfaT47Xp(5) - dfaT47Xp(4) != 220000
        )
            ++bad;
        // the Table 47r printed final step (printed p. 168)
    if (dfaT47Xp(10) - dfaT47Xp(9) != 120000
            || dfaT47Xp(10) != 4300000
            || dfaT47Xp(9) != 4180000
        )
            ++bad;
        // the Table 47r hit-point columns (printed p. 168)
    if (dfaT47HpBonus(1) - dfaT47HpBonus(0) != 2
            || dfaT47HpBonus(10) != 40
            || dfaT47HpBaseCol(10) != 10
        )
            ++bad;
        // the Table 47r weapon column steps (printed p. 168)
    if (dfaT47WeaponProf(3) != 7
            || dfaT47WeaponProf(4) != 8
            || dfaT47WeaponProf(8) != 9
            || dfaT47WeaponProf(10) != 9
        )
            ++bad;
        // the Table 47r nonweapon column steps (printed p. 168)
    if (dfaT47NonweaponProf(3) != 8
            || dfaT47NonweaponProf(4) != 9
            || dfaT47NonweaponProf(8) != 10
        )
            ++bad;
        // the Table 49 bribe and detect illusion rows (printed p. 169)
    if (dfaT49Dwarf(0) + 5 != 0
            || dfaT49Elf(0) != 15
            || dfaT49Dwarf(1) != 5
            || dfaT49Gnome(1) != 10
            || dfaT49Human(1) != 0
        )
            ++bad;
        // the Table 49 detect magic row (printed p. 169)
    if (dfaT49Elf(2) != 10
            || dfaT49Halfling(2) != 5
            || dfaT49Human(2) != 0
            || dfaT49Gnome(2) != 5
        )
            ++bad;
        // the Table 49 escape bonds and tunneling rows (printed p. 169)
    if (dfaT49Halfling(3) != 10
            || dfaT49Human(3) != 0
            || dfaT49Dwarf(4) != 10
            || dfaT49Elf(4) + 10 != 0
            || dfaT49Halfelf(4) + 5 != 0
            || dfaT49Halfling(4) != 5
        )
            ++bad;
        // the Table 50 escape bonds ladder (printed p. 170)
    if (dfaT50Dex9(0) + 15 != 0
            || dfaT50Dex11(0) + 5 != 0
            || dfaT50Dex17(0) != 5
            || dfaT50Dex21(0) != 25
            || dfaT50Dex22(0) != 30
        )
            ++bad;
        // the Table 50 tunneling row with its printed dash (printed p. 170)
    if (dfaT50Dex9(1) + 10 != 0
            || dfaT50Dex17(1) != 0
            || dfaT50Dex18(1) != 5
            || dfaT50Dex21(1) != 20
            || dfaT50Dex22(1) != 30
        )
            ++bad;
        // the Table 51 armor grid (printed p. 170)
    if (dfaT51NoArmor(0) + 10 != 0
            || dfaT51ElvenChain(0) != 5
            || dfaT51NoArmor(2) != 10
            || dfaT51Leather(2) + 10 != 0
            || dfaT51ElvenChain(1) + 5 != 0
        )
            ++bad;
        // the Table 48 base scores (printed p. 169)
    if (dfaBribeBase() != 5
            || dfaDetectIllusionBase() != 10
            || dfaDetectMagicBase() != 5
            || dfaEscapeBondsBase() != 10
            || dfaTunnelingBase() != 15
        )
            ++bad;
        // the bribe status grid (printed pp. 168-169)
    if (dfaBribeDice(0) != 2
            || dfaBribeSides(0) != 4
            || dfaBribeDice(1) != 3
            || dfaBribeSides(1) != 8
            || dfaBribeDice(2) != 5
            || dfaBribeSides(2) != 10
            || dfaBribeSides(3) != 100
        )
            ++bad;
        // the Jobare bribe worked example (printed p. 169)
    if (dfaJobareReactionRoll() - dfaJobareFriendlyMax() !=
        dfaJobareBribeDiff()
            || dfaJobareBaseBribeCp() * dfaJobareBribeDiff() !=
            dfaJobarePaidCp()
        )
            ++bad;
        // the tunneling earth grid (printed p. 169)
    if (dfaTunnelMod(0) + 10 != 0
            || dfaTunnelHours(0) != 5
            || dfaTunnelMod(1) != 0
            || dfaTunnelHours(1) != 10
            || dfaTunnelMod(2) != 10
            || dfaTunnelHours(2) != 30
        )
            ++bad;
        // the detect skill ranges (printed p. 169)
    if (dfaDetectIllusionRange() != 90
            || dfaDetectMagicRange() != 60
            || dfaDetectMagicIntensityCount() != 5
        )
            ++bad;
        // the thief scroll ladder (printed p. 170)
    if (dfaThiefScrollBand(23) != 0
            || dfaThiefScrollBand(24) != 1
            || dfaThiefScrollBand(26) != 1
            || dfaThiefScrollBand(27) != 2
            || dfaThiefScrollBand(28) != 2
            || dfaThiefScrollBand(29) != 3
            || dfaThiefScrollBand(30) != 3
        )
            ++bad;
        // the bard scroll ladder (printed pp. 170-171)
    if (dfaBardScrollBand(20) != 0
            || dfaBardScrollBand(21) != 1
            || dfaBardScrollBand(23) != 1
            || dfaBardScrollBand(24) != 2
            || dfaBardScrollBand(27) != 3
            || dfaBardScrollBand(30) != 4
        )
            ++bad;
        // the Table 52 low columns (printed p. 171)
    if (dfaT52L1(0) != 4
            || dfaT52L1(10) != 6
            || dfaT52L2(10) != 6
            || dfaT52L3(10) != 6
            || dfaT52L4(10) != 6
        )
            ++bad;
        // the Table 52 sixth and seventh columns (printed p. 171)
    if (dfaT52L6(0) != 3
            || dfaT52L7(0) != 0
            || dfaT52L7(1) != 1
            || dfaT52L7(4) != 4
            || dfaT52L7(8) != 5
        )
            ++bad;
        // the Table 52 eighth column (printed p. 171)
    if (dfaT52L8(8) != 0
            || dfaT52L8(9) != 1
            || dfaT52L8(10) != 1
        )
            ++bad;
        // the Table 52 26th-level row (printed p. 171)
    if (dfaT52L1(6) != 5
            || dfaT52L2(6) != 5
            || dfaT52L3(6) != 5
            || dfaT52L4(6) != 5
            || dfaT52L5(6) != 4
            || dfaT52L6(6) != 4
            || dfaT52L7(6) != 4
            || dfaT52L8(6) != 0
        )
            ++bad;
        // the bard power gates (printed pp. 170-171)
    if (dfaBardItemUseLevel() != 24
            || dfaBardItemCreationLevel() != 27
            || dfaBardIdentifyChance() != 55
            || dfaBardIdentifyLevel() != 21
            || dfaThiefScrollLevel() != 24
        )
            ++bad;
        // the thief and bard S&P bonuses (printed pp. 170-171)
    if (dfaThiefSkillBonusCp() != 50
            || dfaBardSkillBonusCp() != 20
            || dfaThiefSpSkillThreshold() != 9
            || dfaBardNewSkillCount() != 2
            || dfaNewThiefSkillCount() != 5
        )
            ++bad;
        // the scroll failure percentages (printed pp. 170-171)
    if (dfaThiefScrollFailPct() != 25
            || dfaBardScrollFailPct() != 15
        )
            ++bad;
        // the adaptation bonuses (printed pp. 171-172)
    if (dfaAdaptInitPenaltyAvoided() != 6
            || dfaAdaptCheckBonus() != 3
            || dfaAdaptBlindCheckPenalty() != 4
            || dfaAdaptPracticeHours() != 8
            || dfaAdaptPermanentCp() != 3
        )
            ++bad;
        // the classify traps numbers (printed p. 172)
    if (dfaClassifyExamTurns() != 1
            || dfaClassifyFalseRoll() != 20
            || dfaClassifyEvasionSaveBonus() != 2
        )
            ++bad;
        // the fall/jump band boundaries (printed pp. 172-173)
    if (dfaFallBand(12) != 0
            || dfaFallBand(13) != 0
            || dfaFallBand(14) != 1
            || dfaFallBand(16) != 1
            || dfaFallBand(17) != 2
            || dfaFallBand(20) != 3
        )
            ++bad;
        // the fall/jump safe distance ladder (printed pp. 172-173)
    if (dfaFallSafeBase() + 30 * dfaFallBand(20) != 120
            || dfaFallSafeBase() + 30 * dfaFallBand(26) != 180
            || dfaFallSafeBase() + 30 * dfaFallBand(29) != 210
        )
            ++bad;
        // the fall/jump surface distance column (printed pp. 172-173)
    if (dfaFallSurface(0) != 1
            || dfaFallSurface(2) != 3
            || dfaFallSurface(3) != 5
            || dfaFallSurface(6) != 11
        )
            ++bad;
        // the Jobare shaft worked example (printed p. 173)
    if (dfaJobareShaftFeet() + dfaJobareChamberFeet() - dfaJobareBreakFeet()
        != dfaJobareFinalFeet()
            || dfaJobareFinalFeet() / 10 != dfaJobareFallDice()
            || dfaJobare30thFeet() / 10 != dfaJobare30thDice()
            || dfaJobareFallSides() != 6
        )
            ++bad;
        // the featherfoot band and grid (printed p. 173)
    if (dfaFeatherBand(13) != 0
            || dfaFeatherBand(14) != 1
            || dfaFeatherBand(17) != 2
            || dfaFeatherDistance(2) != 120
            || dfaFeatherMove(0) != 12
            || dfaFeatherMove(2) != 18
        )
            ++bad;
        // the improvised attack save modifier ladder (printed p. 174)
    if (dfaImprovisedSaveTrickEncounter() != 2 *
        dfaImprovisedSaveTrickAdventure()
            || dfaImprovisedSaveSameCreatureEncounter() !=
            dfaImprovisedSaveSameCreatureAdventure() + 2
            || dfaImprovisedSaveNoRoleplay() != 6
            || dfaImprovisedSaveFeeble() != 4
        )
            ++bad;
        // the improvised attack effect numbers (printed p. 174)
    if (dfaImprovisedBlindClearRoll() != 9
            || dfaImprovisedImmobFreeRoll() != 9
            || dfaImprovisedBlindPenalty() != 4
            || dfaImprovisedStunPenalty() != 2
            || dfaImprovisedKillHpOffset() != 10
        )
            ++bad;
        // the improvised attack dice (printed p. 174)
    if (dfaImprovisedStunDice() != 2
            || dfaImprovisedStunSides() != 4
            || dfaImprovisedTripLowSides() != 3
            || dfaImprovisedTripHighSides() != 6
            || dfaJobareSurpriseRoll() != 2
        )
            ++bad;
        // the inner focus band boundaries (printed p. 175)
    if (dfaFocusBand(14) != 0
            || dfaFocusBand(15) != 0
            || dfaFocusBand(16) != 1
            || dfaFocusBand(20) != 1
            || dfaFocusBand(21) != 2
            || dfaFocusBand(25) != 2
        )
            ++bad;
        // the inner focus boost ceiling (printed p. 175)
    if (dfaFocusBand(26) != 3
            || dfaFocusBoostBase() + dfaFocusBand(26) != 21
            || dfaFocusBoostBase() + dfaFocusBand(16) != 19
            || dfaFocusBoostBase() + dfaFocusBand(13) != 18
        )
            ++bad;
        // the inner focus drain and duration (printed p. 175)
    if (dfaFocusOtherPenalty() != 2
            || dfaFocusDurationPerLevel() != 1
            || dfaFocusAttemptCost() != 2
            || dfaNondetectionSpellLevel() != 3
        )
            ++bad;
        // the sense danger subskill ladder (printed pp. 176-177)
    if (dfaSenseBand(15) != 0
            || dfaSenseBand(16) != 1
            || dfaSenseBand(20) != 1
            || dfaSenseBand(21) != 2
            || dfaSenseBand(26) != 3
            || dfaSenseBand(30) != 3
            || dfaSenseSubskillCount() != 4
        )
            ++bad;
        // the sense danger bonuses (printed pp. 176-177)
    if (dfaSenseImpendingSurpriseBonus() != 2
            || dfaSenseImpendingInitBonus() != 1
            || dfaSenseAmbushYards() != 200
            || dfaSenseAlertnessBonus() != 1
            || dfaSenseFalseRoll() != 20
        )
            ++bad;
        // the shadow rate ladders (printed p. 177)
    if (dfaShadowWeakRate() != 15
            || dfaShadowStrongRate() != 18
            || dfaShadowVeryRate() != 24
            || dfaFlightWeakRate() != 15
            || dfaFlightStrongRate() != 18
            || dfaFlightVeryRate() != 24
            || dfaFlightLeapYards() != 360
            || dfaFlightLeapPerHour() != 1
        )
            ++bad;
        printf("R611 DMO rogues audit: bad %d\n", bad);
        if (bad) return 1;
    }
    #include "rules/audits/r612_dmo_ascension.h"  // R831: migrated
