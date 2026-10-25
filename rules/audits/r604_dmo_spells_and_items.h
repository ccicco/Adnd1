    // ---- R604 DMO spells-and-items audit ----
    // CHAPTER 3 of the DMO (printed pp. 68-85), the magic-management chapter
    // closing in one round: the daily recovery doctrine (the eight-hour rest
    // minimum, the 10 minutes per spell level, the eight-hour study cap, the
    // no-sleep once-a-day rule, the restart on distraction), the wizard
    // clarifications (the damage caps of horrid wilting, cone of cold and
    // delayed blast fireball, the antimagic-shell scope, the ESP save ladder,
    // the feather-fall bands, the fly maneuvering, the haste aging, the
    // identify cost, the limited-wish and wish aging grids and scopes, the
    // permanency and dispel doctrines, the teleport firm-surface rule and the
    // permanent dimensions, the astral projection economics, the stoneskin
    // limits), the priest clarifications (the holy-might cap, the know-time
    // estimator, the plane-shift companions and the planar-research grid with
    // the pocket-dimension modifiers, the nap and sentinel windows, the
    // speak-with-dead range), and the item doctrines (the amulet seven days,
    // the bag-of-holding air and water grid, the extradimensional seam, the
    // potion 12th-level bar, the rod and staff rules, the sphere 92-percent
    // control cap, the withering limb ladders, the stone of luck).
    {
        using namespace rules;
        int bad = 0;
    if (deqRaceCount() != 5
            || deqPlaneTypeCount() != 4
            || deqBagTypeCount() != 4
            || deqMemorizeMinutesPerLevel() != 10
            || deqRestHoursMin() != 8
            || deqStudyHoursMax() != 8
            || deqHorridWiltingDice() != 16
            || deqHorridWiltingDieSize() != 8
            || deqConeOfColdDice() != 10
            || deqConeOfColdDieSize() != 4
            || deqConeOfColdBonus() != 10
            || deqDelayedBlastDice() != 15
            || deqDelayedBlastDieSize() != 6
            || deqDelayedBlastBonus() != 15
            || deqColorSprayHandWidthFt() != 5
            || deqColorSprayLengthFt() != 20
            || deqColorSprayFarWidthFt() != 20
            || deqDispelItemInertDie() != 4
            || deqPotionDispelLevel() != 12
            || deqEspBonusMinor() != 1
            || deqEspBonusDamaging() != 2
            || deqEspBonusSerious() != 3
            || deqEspBonusDeep() != 4
            || deqFeatherFallAutoFt() != 10
            || deqFeatherFallFtPerLevel() != 120
            || deqFeatherFallInitPerBand() != 1
            || deqFlyManeuverClass() != 2
            || deqFlyTurnDegrees() != 180
            || deqFearConeInitMod() != 3
            || deqHasteAgingYears() != 1
            || deqIdentifyPurifyHours() != 8
            || deqIdentifyConLoss() != 8
            || deqReinvisibilityInitMod() != 3
            || deqLimitedWishMimicMax() != 7
            || deqWishDuplicateMax() != 9
            || deqWishStrLoss() != 3
            || deqWishBedRestDie() != 4
            || deqWishBedRestCount() != 2
            || deqWishWealthDiceCount() != 5
            || deqWishWealthDieSize() != 8
            || deqWishWealthMult() != 1000
            || deqWishItemLoanHours() != 1
            || deqWishLevelPerWish() != 1
            || deqMagicStaffMinRating() != 4
            || deqPwsMoveDivisor() != 3
            || deqPwsMoveMax() != 3
            || deqPwsAttackBonus() != 4
            || deqRopeTrickLbs() != 1000
            || deqStoneskinHours() != 24
            || deqTeleportPermanentCuFt() != 1000
            || deqTeleportPermanentSqFt() != 400
            || deqTeleportLowYardsDie() != 100
            || deqUnseenServantHoverFt() != 30
            || deqUnseenServantReformDie() != 10
            || deqUnseenServantReformCount() != 2
            || deqAstralMovePerInt() != 30
            || deqAstralReturnHp() != 1
            || deqAstralPenalty() != 4
            || deqHolyMightCap() != 25
            || deqKnowTimePctPerLevel() != 2
            || deqPlaneShiftCompanions() != 7
            || deqPocketDimExtraCost() != 2000
            || deqPocketDimExtraWeeks() != 4
            || deqNapWindowHours() != 18
            || deqSentinelRestTurns() != 48
            || deqSpeakWithDeadRangeYds() != 1
            || deqAmuletPsycheDays() != 7
            || deqFortressDamageRounds() != 3
            || deqExtradimensionalGateFt() != 10
            || deqFlightDailyMult() != 2
            || deqFlightNormalHours() != 10
            || deqFlightHurriedMinHours() != 18
            || deqFlightHurriedMaxHours() != 20
            || deqFlightAllDayMultHalf() != 5
            || deqGirdlePouchGallons() != 1
            || deqGirdlePouchAirMin() != 4
            || deqHaversackSideGallons() != 2
            || deqHaversackCentralGallons() != 8
            || deqHaversackAirMin() != 4
            || deqPouchGallons() != 1
            || deqPouchAirMin() != 4
            || deqFlatboxGallons() != 60
            || deqFlatboxAirMin() != 6
            || deqJavelinRangeYds() != 90
            || deqJavelinMinTargetFt() != 30
            || deqPortableHoleCuFt() != 280
            || deqPortableHoleGallons() != 2100
            || deqPortableHoleCoins() != 100000
            || deqPortableHoleAirMin() != 10
            || deqVitalityHealHours() != 4
            || deqBeguilingRadiusFt() != 20
            || deqBeguilingDurationTurns() != 1
            || deqRulershipRadiusFt() != 150
            || deqResurrectionSpecialtyCharges() != 2
            || deqEntangleAreaSqFt() != 200
            || deqEntangleSaveMoveFt() != 10
            || deqEntangleInitPenalty() != 2
            || deqEntangleImmobileBonus() != 4
            || deqSphereControlMax() != 92
            || deqSphereControlLevel() != 21
            || deqSphereControlInt() != 18
            || deqTalismanIntMult() != 2
            || deqWitherCharges() != 3
            || deqWitherLimbDie() != 4
            || deqWitherArmDexPenalty() != 2
            || deqWitherLegDexPenalty() != 6
            || deqWitherQuadMoveNum() != 2
            || deqWitherQuadMoveDen() != 3
            || deqWitherQuadLimbDie() != 6
            || deqWitherRegenPoints() != 20
            || deqNegationInitMod() != 1
            || deqScrollMinMagicRating() != 2
            || deqStoneLuckBonus() != 1
            || deqStoneLuckPctBonus() != 5
            || !deqNoSleepOnceDaily()
            || !deqDistractionRestarts()
            || !deqShellNoDestroy()
            || !deqShellBlocksRangedOnly()
            || !deqAstralDiesWithBody()
            || !deqHasteNeverStacks()
            || !deqStoneskinNonCumulative()
            || !deqPermanentDispelledOnlyByGreater()
            || !deqIdentifyWearItem()
            || !deqWishLetterAndLeastResistance()
            || !deqWishNoGainNoRest()
            || !deqTeleportNeedsFirmSurface()
            || !deqPolymorphNoMagicAbilities()
            || !deqPolymorphSeenFormsOnly()
            || !deqShapeChangeNonmagicalOnly()
            || !deqStinkingCloudPermanent()
            || !deqPermanentWebReforms()
            || !deqAgeCreatureNegatesMagicalAging()
            || !deqExtradimensionalRift()
            || !deqPotionsSelfOnlyDispelled()
            || !deqPotionShellDelayed()
            || !deqRingRegenOnlyPostDonning()
            || !deqRodAbsorbTargetOnly()
            || !deqDeckWishProof()
            || !deqGemInsightOnce()
            || !deqQuiverNoCreatures()
            || !deqIronBandsEscapable()
            || !deqWeightyChestNoWeapon()
            || !deqBooksTriggerOnPerusal()
            || !deqDisplacementFirstAttackOnly()
            || !deqFlightForcedMarch()
            || !deqScrollsCrossClass()
            || !deqSphereAutoAbove100()
        )
            ++bad;
        // the deqWishAging grid
        int CT31[5][2] = {
            {1,5},
            {2,10},
            {3,15},
            {4,20},
            {5,25},
            };
        for (int b = 0;
             b < deqRaceCount();
             ++b) {
            int vals[2];
            vals[0] = deqLimitedWishAgingYears(b);
            vals[1] = deqWishAgingYears(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CT31[b][c])
                    ++bad;
            }
        }
        // the deqPlanarResearch grid
        int CT32[4][5] = {
            {500,1500,1,6,100},
            {1000,3000,2,12,300},
            {5000,15000,8,52,400},
            {750,3000,3,9,250},
            };
        for (int b = 0;
             b < deqPlaneTypeCount();
             ++b) {
            int vals[5];
            vals[0] = deqResearchKnownCost(b);
            vals[1] = deqResearchUnknownCost(b);
            vals[2] = deqResearchKnownWeeks(b);
            vals[3] = deqResearchUnknownWeeks(b);
            vals[4] = deqRodCost(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CT32[b][c])
                    ++bad;
            }
        }
        // the deqBagHolding grid
        int CT33[4][3] = {
            {250,4,30},
            {500,6,60},
            {1000,8,120},
            {1500,10,180},
            };
        for (int b = 0;
             b < deqBagTypeCount();
             ++b) {
            int vals[3];
            vals[0] = deqBagCapacityLbs(b);
            vals[1] = deqBagAirMinutes(b);
            vals[2] = deqBagWaterGallons(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT33[b][c])
                    ++bad;
            }
        }
        // the deqRaceCount pin
    if (deqRaceCount() != 5
        )
            ++bad;
        // the deqPlaneTypeCount pin
    if (deqPlaneTypeCount() != 4
        )
            ++bad;
        // the deqBagTypeCount pin
    if (deqBagTypeCount() != 4
        )
            ++bad;
        // the deqMemorizeMinutesPerLevel pin
    if (deqMemorizeMinutesPerLevel() != 10
        )
            ++bad;
        // the deqRestHoursMin pin
    if (deqRestHoursMin() != 8
        )
            ++bad;
        // the deqStudyHoursMax pin
    if (deqStudyHoursMax() != 8
        )
            ++bad;
        // the deqHorridWiltingDice pin
    if (deqHorridWiltingDice() != 16
        )
            ++bad;
        // the deqHorridWiltingDieSize pin
    if (deqHorridWiltingDieSize() != 8
        )
            ++bad;
        // the deqConeOfColdDice pin
    if (deqConeOfColdDice() != 10
        )
            ++bad;
        // the deqConeOfColdDieSize pin
    if (deqConeOfColdDieSize() != 4
        )
            ++bad;
        // the deqConeOfColdBonus pin
    if (deqConeOfColdBonus() != 10
        )
            ++bad;
        // the deqDelayedBlastDice pin
    if (deqDelayedBlastDice() != 15
        )
            ++bad;
        // the deqDelayedBlastDieSize pin
    if (deqDelayedBlastDieSize() != 6
        )
            ++bad;
        // the deqDelayedBlastBonus pin
    if (deqDelayedBlastBonus() != 15
        )
            ++bad;
        // the deqColorSprayHandWidthFt pin
    if (deqColorSprayHandWidthFt() != 5
        )
            ++bad;
        // the deqColorSprayLengthFt pin
    if (deqColorSprayLengthFt() != 20
        )
            ++bad;
        // the deqColorSprayFarWidthFt pin
    if (deqColorSprayFarWidthFt() != 20
        )
            ++bad;
        // the deqDispelItemInertDie pin
    if (deqDispelItemInertDie() != 4
        )
            ++bad;
        // the deqPotionDispelLevel pin
    if (deqPotionDispelLevel() != 12
        )
            ++bad;
        // the deqEspBonusMinor pin
    if (deqEspBonusMinor() != 1
        )
            ++bad;
        // the deqEspBonusDamaging pin
    if (deqEspBonusDamaging() != 2
        )
            ++bad;
        // the deqEspBonusSerious pin
    if (deqEspBonusSerious() != 3
        )
            ++bad;
        // the deqEspBonusDeep pin
    if (deqEspBonusDeep() != 4
        )
            ++bad;
        // the deqFeatherFallAutoFt pin
    if (deqFeatherFallAutoFt() != 10
        )
            ++bad;
        // the deqFeatherFallFtPerLevel pin
    if (deqFeatherFallFtPerLevel() != 120
        )
            ++bad;
        // the deqFeatherFallInitPerBand pin
    if (deqFeatherFallInitPerBand() != 1
        )
            ++bad;
        // the deqFlyManeuverClass pin
    if (deqFlyManeuverClass() != 2
        )
            ++bad;
        // the deqFlyTurnDegrees pin
    if (deqFlyTurnDegrees() != 180
        )
            ++bad;
        // the deqFearConeInitMod pin
    if (deqFearConeInitMod() != 3
        )
            ++bad;
        // the deqHasteAgingYears pin
    if (deqHasteAgingYears() != 1
        )
            ++bad;
        // the deqIdentifyPurifyHours pin
    if (deqIdentifyPurifyHours() != 8
        )
            ++bad;
        // the deqIdentifyConLoss pin
    if (deqIdentifyConLoss() != 8
        )
            ++bad;
        // the deqReinvisibilityInitMod pin
    if (deqReinvisibilityInitMod() != 3
        )
            ++bad;
        // the deqLimitedWishMimicMax pin
    if (deqLimitedWishMimicMax() != 7
        )
            ++bad;
        // the deqWishDuplicateMax pin
    if (deqWishDuplicateMax() != 9
        )
            ++bad;
        // the deqWishStrLoss pin
    if (deqWishStrLoss() != 3
        )
            ++bad;
        // the deqWishBedRestDie pin
    if (deqWishBedRestDie() != 4
        )
            ++bad;
        // the deqWishBedRestCount pin
    if (deqWishBedRestCount() != 2
        )
            ++bad;
        // the deqWishWealthDiceCount pin
    if (deqWishWealthDiceCount() != 5
        )
            ++bad;
        // the deqWishWealthDieSize pin
    if (deqWishWealthDieSize() != 8
        )
            ++bad;
        // the deqWishWealthMult pin
    if (deqWishWealthMult() != 1000
        )
            ++bad;
        // the deqWishItemLoanHours pin
    if (deqWishItemLoanHours() != 1
        )
            ++bad;
        // the deqWishLevelPerWish pin
    if (deqWishLevelPerWish() != 1
        )
            ++bad;
        // the deqMagicStaffMinRating pin
    if (deqMagicStaffMinRating() != 4
        )
            ++bad;
        // the deqPwsMoveDivisor pin
    if (deqPwsMoveDivisor() != 3
        )
            ++bad;
        // the deqPwsMoveMax pin
    if (deqPwsMoveMax() != 3
        )
            ++bad;
        // the deqPwsAttackBonus pin
    if (deqPwsAttackBonus() != 4
        )
            ++bad;
        // the deqRopeTrickLbs pin
    if (deqRopeTrickLbs() != 1000
        )
            ++bad;
        // the deqStoneskinHours pin
    if (deqStoneskinHours() != 24
        )
            ++bad;
        // the deqTeleportPermanentCuFt pin
    if (deqTeleportPermanentCuFt() != 1000
        )
            ++bad;
        // the deqTeleportPermanentSqFt pin
    if (deqTeleportPermanentSqFt() != 400
        )
            ++bad;
        // the deqTeleportLowYardsDie pin
    if (deqTeleportLowYardsDie() != 100
        )
            ++bad;
        // the deqUnseenServantHoverFt pin
    if (deqUnseenServantHoverFt() != 30
        )
            ++bad;
        // the deqUnseenServantReformDie pin
    if (deqUnseenServantReformDie() != 10
        )
            ++bad;
        // the deqUnseenServantReformCount pin
    if (deqUnseenServantReformCount() != 2
        )
            ++bad;
        // the deqAstralMovePerInt pin
    if (deqAstralMovePerInt() != 30
        )
            ++bad;
        // the deqAstralReturnHp pin
    if (deqAstralReturnHp() != 1
        )
            ++bad;
        // the deqAstralPenalty pin
    if (deqAstralPenalty() != 4
        )
            ++bad;
        // the deqHolyMightCap pin
    if (deqHolyMightCap() != 25
        )
            ++bad;
        // the deqKnowTimePctPerLevel pin
    if (deqKnowTimePctPerLevel() != 2
        )
            ++bad;
        // the deqPlaneShiftCompanions pin
    if (deqPlaneShiftCompanions() != 7
        )
            ++bad;
        // the deqPocketDimExtraCost pin
    if (deqPocketDimExtraCost() != 2000
        )
            ++bad;
        // the deqPocketDimExtraWeeks pin
    if (deqPocketDimExtraWeeks() != 4
        )
            ++bad;
        // the deqNapWindowHours pin
    if (deqNapWindowHours() != 18
        )
            ++bad;
        // the deqSentinelRestTurns pin
    if (deqSentinelRestTurns() != 48
        )
            ++bad;
        // the deqSpeakWithDeadRangeYds pin
    if (deqSpeakWithDeadRangeYds() != 1
        )
            ++bad;
        // the deqAmuletPsycheDays pin
    if (deqAmuletPsycheDays() != 7
        )
            ++bad;
        // the deqFortressDamageRounds pin
    if (deqFortressDamageRounds() != 3
        )
            ++bad;
        // the deqExtradimensionalGateFt pin
    if (deqExtradimensionalGateFt() != 10
        )
            ++bad;
        // the deqFlightDailyMult pin
    if (deqFlightDailyMult() != 2
        )
            ++bad;
        // the deqFlightNormalHours pin
    if (deqFlightNormalHours() != 10
        )
            ++bad;
        // the deqFlightHurriedMinHours pin
    if (deqFlightHurriedMinHours() != 18
        )
            ++bad;
        // the deqFlightHurriedMaxHours pin
    if (deqFlightHurriedMaxHours() != 20
        )
            ++bad;
        // the deqFlightAllDayMultHalf pin
    if (deqFlightAllDayMultHalf() != 5
        )
            ++bad;
        // the deqGirdlePouchGallons pin
    if (deqGirdlePouchGallons() != 1
        )
            ++bad;
        // the deqGirdlePouchAirMin pin
    if (deqGirdlePouchAirMin() != 4
        )
            ++bad;
        // the deqHaversackSideGallons pin
    if (deqHaversackSideGallons() != 2
        )
            ++bad;
        // the deqHaversackCentralGallons pin
    if (deqHaversackCentralGallons() != 8
        )
            ++bad;
        // the deqHaversackAirMin pin
    if (deqHaversackAirMin() != 4
        )
            ++bad;
        // the deqPouchGallons pin
    if (deqPouchGallons() != 1
        )
            ++bad;
        // the deqPouchAirMin pin
    if (deqPouchAirMin() != 4
        )
            ++bad;
        // the deqFlatboxGallons pin
    if (deqFlatboxGallons() != 60
        )
            ++bad;
        // the deqFlatboxAirMin pin
    if (deqFlatboxAirMin() != 6
        )
            ++bad;
        // the deqJavelinRangeYds pin
    if (deqJavelinRangeYds() != 90
        )
            ++bad;
        // the deqJavelinMinTargetFt pin
    if (deqJavelinMinTargetFt() != 30
        )
            ++bad;
        // the deqPortableHoleCuFt pin
    if (deqPortableHoleCuFt() != 280
        )
            ++bad;
        // the deqPortableHoleGallons pin
    if (deqPortableHoleGallons() != 2100
        )
            ++bad;
        // the deqPortableHoleCoins pin
    if (deqPortableHoleCoins() != 100000
        )
            ++bad;
        // the deqPortableHoleAirMin pin
    if (deqPortableHoleAirMin() != 10
        )
            ++bad;
        // the deqVitalityHealHours pin
    if (deqVitalityHealHours() != 4
        )
            ++bad;
        // the deqBeguilingRadiusFt pin
    if (deqBeguilingRadiusFt() != 20
        )
            ++bad;
        // the deqBeguilingDurationTurns pin
    if (deqBeguilingDurationTurns() != 1
        )
            ++bad;
        // the deqRulershipRadiusFt pin
    if (deqRulershipRadiusFt() != 150
        )
            ++bad;
        // the deqResurrectionSpecialtyCharges pin
    if (deqResurrectionSpecialtyCharges() != 2
        )
            ++bad;
        // the deqEntangleAreaSqFt pin
    if (deqEntangleAreaSqFt() != 200
        )
            ++bad;
        // the deqEntangleSaveMoveFt pin
    if (deqEntangleSaveMoveFt() != 10
        )
            ++bad;
        // the deqEntangleInitPenalty pin
    if (deqEntangleInitPenalty() != 2
        )
            ++bad;
        // the deqEntangleImmobileBonus pin
    if (deqEntangleImmobileBonus() != 4
        )
            ++bad;
        // the deqSphereControlMax pin
    if (deqSphereControlMax() != 92
        )
            ++bad;
        // the deqSphereControlLevel pin
    if (deqSphereControlLevel() != 21
        )
            ++bad;
        // the deqSphereControlInt pin
    if (deqSphereControlInt() != 18
        )
            ++bad;
        // the deqTalismanIntMult pin
    if (deqTalismanIntMult() != 2
        )
            ++bad;
        // the deqWitherCharges pin
    if (deqWitherCharges() != 3
        )
            ++bad;
        // the deqWitherLimbDie pin
    if (deqWitherLimbDie() != 4
        )
            ++bad;
        // the deqWitherArmDexPenalty pin
    if (deqWitherArmDexPenalty() != 2
        )
            ++bad;
        // the deqWitherLegDexPenalty pin
    if (deqWitherLegDexPenalty() != 6
        )
            ++bad;
        // the deqWitherQuadMoveNum pin
    if (deqWitherQuadMoveNum() != 2
        )
            ++bad;
        // the deqWitherQuadMoveDen pin
    if (deqWitherQuadMoveDen() != 3
        )
            ++bad;
        // the deqWitherQuadLimbDie pin
    if (deqWitherQuadLimbDie() != 6
        )
            ++bad;
        // the deqWitherRegenPoints pin
    if (deqWitherRegenPoints() != 20
        )
            ++bad;
        // the deqNegationInitMod pin
    if (deqNegationInitMod() != 1
        )
            ++bad;
        // the deqScrollMinMagicRating pin
    if (deqScrollMinMagicRating() != 2
        )
            ++bad;
        // the deqStoneLuckBonus pin
    if (deqStoneLuckBonus() != 1
        )
            ++bad;
        // the deqStoneLuckPctBonus pin
    if (deqStoneLuckPctBonus() != 5
        )
            ++bad;
        // the deqNoSleepOnceDaily pin
    if (deqNoSleepOnceDaily() != 1
        )
            ++bad;
        // the deqDistractionRestarts pin
    if (deqDistractionRestarts() != 1
        )
            ++bad;
        // the deqShellNoDestroy pin
    if (deqShellNoDestroy() != 1
        )
            ++bad;
        // the deqShellBlocksRangedOnly pin
    if (deqShellBlocksRangedOnly() != 1
        )
            ++bad;
        // the deqAstralDiesWithBody pin
    if (deqAstralDiesWithBody() != 1
        )
            ++bad;
        // the deqHasteNeverStacks pin
    if (deqHasteNeverStacks() != 1
        )
            ++bad;
        // the deqStoneskinNonCumulative pin
    if (deqStoneskinNonCumulative() != 1
        )
            ++bad;
        // the deqPermanentDispelledOnlyByGreater pin
    if (deqPermanentDispelledOnlyByGreater() != 1
        )
            ++bad;
        // the deqIdentifyWearItem pin
    if (deqIdentifyWearItem() != 1
        )
            ++bad;
        // the deqWishLetterAndLeastResistance pin
    if (deqWishLetterAndLeastResistance() != 1
        )
            ++bad;
        // the deqWishNoGainNoRest pin
    if (deqWishNoGainNoRest() != 1
        )
            ++bad;
        // the deqTeleportNeedsFirmSurface pin
    if (deqTeleportNeedsFirmSurface() != 1
        )
            ++bad;
        // the deqPolymorphNoMagicAbilities pin
    if (deqPolymorphNoMagicAbilities() != 1
        )
            ++bad;
        // the deqPolymorphSeenFormsOnly pin
    if (deqPolymorphSeenFormsOnly() != 1
        )
            ++bad;
        // the deqShapeChangeNonmagicalOnly pin
    if (deqShapeChangeNonmagicalOnly() != 1
        )
            ++bad;
        // the deqStinkingCloudPermanent pin
    if (deqStinkingCloudPermanent() != 1
        )
            ++bad;
        // the deqPermanentWebReforms pin
    if (deqPermanentWebReforms() != 1
        )
            ++bad;
        // the deqAgeCreatureNegatesMagicalAging pin
    if (deqAgeCreatureNegatesMagicalAging() != 1
        )
            ++bad;
        // the deqExtradimensionalRift pin
    if (deqExtradimensionalRift() != 1
        )
            ++bad;
        // the deqPotionsSelfOnlyDispelled pin
    if (deqPotionsSelfOnlyDispelled() != 1
        )
            ++bad;
        // the deqPotionShellDelayed pin
    if (deqPotionShellDelayed() != 1
        )
            ++bad;
        // the deqRingRegenOnlyPostDonning pin
    if (deqRingRegenOnlyPostDonning() != 1
        )
            ++bad;
        // the deqRodAbsorbTargetOnly pin
    if (deqRodAbsorbTargetOnly() != 1
        )
            ++bad;
        // the deqDeckWishProof pin
    if (deqDeckWishProof() != 1
        )
            ++bad;
        // the deqGemInsightOnce pin
    if (deqGemInsightOnce() != 1
        )
            ++bad;
        // the deqQuiverNoCreatures pin
    if (deqQuiverNoCreatures() != 1
        )
            ++bad;
        // the deqIronBandsEscapable pin
    if (deqIronBandsEscapable() != 1
        )
            ++bad;
        // the deqWeightyChestNoWeapon pin
    if (deqWeightyChestNoWeapon() != 1
        )
            ++bad;
        // the deqBooksTriggerOnPerusal pin
    if (deqBooksTriggerOnPerusal() != 1
        )
            ++bad;
        // the deqDisplacementFirstAttackOnly pin
    if (deqDisplacementFirstAttackOnly() != 1
        )
            ++bad;
        // the deqFlightForcedMarch pin
    if (deqFlightForcedMarch() != 1
        )
            ++bad;
        // the deqScrollsCrossClass pin
    if (deqScrollsCrossClass() != 1
        )
            ++bad;
        // the deqSphereAutoAbove100 pin
    if (deqSphereAutoAbove100() != 1
        )
            ++bad;
        // the Rozmare fly read: a 3rd-level spell takes 30 minutes at 10
        // minutes a level (printed pp. 68-69)
    if (deqMemorizeMinutesPerLevel() != 10
        )
            ++bad;
        // the limited-wish read: a gnome ages four years from a limited wish
        // and twenty from a wish (printed pp. 72, 76)
    if (deqLimitedWishAgingYears(3) != 4
            || deqWishAgingYears(3) != 20
        )
            ++bad;
        // the demiplane research: 5,000 gp known and 15,000 unknown, eight
        // weeks known and a year - 52 weeks - unknown, the rod at 400 gp
        // (printed p. 79)
    if (deqResearchKnownCost(2) != 5000
            || deqResearchUnknownCost(2) != 15000
            || deqResearchUnknownWeeks(2) != 52
            || deqRodCost(2) != 400
        )
            ++bad;
        // the Ethereal-attached pocket dimension: the inner-plane known cost
        // 500 plus the 2,000 modifier = 2,500 gp, one week plus the four-week
        // modifier = five weeks (printed p. 79)
    if (deqResearchKnownCost(0) != 500
            || deqPocketDimExtraCost() != 2000
            || deqResearchKnownWeeks(0) != 1
            || deqPocketDimExtraWeeks() != 4
        )
            ++bad;
        // the 1,000-pound bag: eight minutes of air and 120 gallons of water
        // (printed p. 80)
    if (deqBagCapacityLbs(2) != 1000
            || deqBagAirMinutes(2) != 8
            || deqBagWaterGallons(2) != 120
        )
            ++bad;
        // the horrid-wilting cap: 16 dice of d8 (printed p. 69, the OCR B
        // misread)
    if (deqHorridWiltingDice() != 16
            || deqHorridWiltingDieSize() != 8
        )
            ++bad;
        // the cone of cold: 10d4+10 (printed p. 70)
    if (deqConeOfColdDice() != 10
            || deqConeOfColdDieSize() != 4
            || deqConeOfColdBonus() != 10
        )
            ++bad;
        // the troll wither-recovery: 20 points of regeneration - seven rounds
        // for a troll regenerating three a round, 20 turns for the ring
        // wearer (printed p. 85)
    if (deqWitherRegenPoints() != 20
        )
            ++bad;
        // the sphere cap: 92 percent at 21st level and 18 Intelligence, the
        // talisman doubling the bonus (printed p. 85)
    if (deqSphereControlMax() != 92
            || deqSphereControlLevel() != 21
            || deqSphereControlInt() != 18
            || deqTalismanIntMult() != 2
        )
            ++bad;
        // the wish wealth: 5d8 x 1,000 - 5,000 to 40,000 gold pieces (printed
        // p. 76)
    if (deqWishWealthDiceCount() != 5
            || deqWishWealthDieSize() != 8
            || deqWishWealthMult() != 1000
        )
            ++bad;
        // the permanent teleport: a 10-foot cube - 1,000 cubic feet - or 20
        // feet square - 400 square feet (printed p. 75)
    if (deqTeleportPermanentCuFt() != 1000
            || deqTeleportPermanentSqFt() != 400
        )
            ++bad;
        // the astral return: one hit point, the -4 penalty, movement 30 times
        // Intelligence (printed p. 70)
    if (deqAstralReturnHp() != 1
            || deqAstralPenalty() != 4
            || deqAstralMovePerInt() != 30
        )
            ++bad;
        printf("R604 DMO spells-and-items audit: bad %d\n", bad);
        if (bad) return 1;
    }
