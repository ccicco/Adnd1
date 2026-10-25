    // ---- R360: the UA new magic-user 5th and
    // 6th level spells pin audit ----
    // The UA NEW MAGIC-USER SPELLS (pp.
    // 51-71), the 5th and 6th levels -
    // avoidance behind the lost name
    // header, dismissal behind the
    // belabourment interleave, dolor with
    // the range as printed, fabricate,
    // the Leomund belabourment, sending;
    // chain lightning behind the
    // truncated range tail, contingency
    // behind the lost casting cells,
    // ensnarement behind the lost name
    // header, eyebite behind the garbled
    // school tail, the Mordenkainen
    // lucubration behind the lost name
    // header, transmute water to dust
    // seam-checking the druid pin minus
    // the mistletoe with the 6-segment
    // print flagged against the druid 8.
    // The family decodes the casting and
    // duration 7s as 1; the range 7s stay
    // as printed. The R342 table seam
    // prints 4 of the 5th-level names
    // (avoidance and dolor absent); the
    // 6th-level column is wholly lost -
    // no seam exists. The item stays open
    // (the 7th-9th levels).
    {
        using namespace rules;
        int bad = 0;
        // U1: avoidance
            if (strcmp(uam5AvoidanceName(),
                "Avoidance") != 0) ++bad;
            if (!uam5AvoidanceNameHeaderLost()) ++bad;
            if (uam5AvoidanceLevel() != 5) ++bad;
            if (!uam5AvoidanceRangeCellEmpty()) ++bad;
            if (!uam5AvoidanceDurationUntilDispelled()) ++bad;
            if (!uam5AvoidanceAoeCellTruncated()) ++bad;
            if (!uam5AvoidanceComponentsCellLost()) ++bad;
            if (!uam5AvoidanceNaturalRepulsion()) ++bad;
            if (uam5AvoidanceRepulsionFeet() != 1) ++bad;
            if (!uam5AvoidanceDependsOnRelativeMass()) ++bad;
            if (!uam5AvoidanceLoneHalflingThrownBack()) ++bad;
            if (!uam5AvoidanceDozenHalflingsKeptOff()) ++bad;
            if (!uam5AvoidanceObjectSkittersFromGiant()) ++bad;
            if (!uam5AvoidanceNotOnLivingThings()) ++bad;
            if (!uam5AvoidancePossessionsEntitleSave()) ++bad;
            if (!uam5AvoidanceMaterialMagnetizedNeedle()) ++bad;
            if (!uam5AvoidanceReverseAttraction()) ++bad;
            if (!uam5AvoidanceReverseMassBehavior()) ++bad;
            if (!uam5AvoidanceReverseBendBarsRemoves()) ++bad;

        // U2: dismissal
            if (strcmp(uam5DismissalName(),
                "Dismissal") != 0) ++bad;
            if (!uam5DismissalNameHeaderLost()) ++bad;
            if (uam5DismissalLevel() != 5) ++bad;
            if (!uam5DismissalStatAfterAvoidanceProse()) ++bad;
            if (!uam5DismissalComponentsVM()) ++bad;
            if (uam5DismissalCastingTimeSegments() != 3) ++bad;
            if (!uam5DismissalSaveSpecial()) ++bad;
            if (!uam5DismissalCubeFragmentGarbled()) ++bad;
            if (!uam5DismissalProseInBelabourmentBlock()) ++bad;
            if (!uam5DismissalReturnsToProperPlane()) ++bad;
            if (!uam5DismissalCfAbjure()) ++bad;
            if (!uam5DismissalNameMustBeKnown()) ++bad;
            if (!uam5DismissalMagicResistanceImmediate()) ++bad;
            if (!uam5DismissalLevelCompareAdjustsSave()) ++bad;
            if (!uam5DismissalDesireMeansSaveOnly()) ++bad;
            if (!uam5DismissalArcaneWorksEnhance()) ++bad;
            if (!uam5DismissalInstantWhisk()) ++bad;
            if (uam5DismissalWrongPlanePct() != 20) ++bad;
            if (!uam5DismissalReverseBeckon()) ++bad;
            if (!uam5DismissalBeckonResistanceOnlyUnnamed()) ++bad;
            if (!uam5DismissalBeckonTransportedToCaster()) ++bad;
            if (!uam5DismissalBeckonNotKindlyDisposal()) ++bad;
            if (!uam5DismissalMaterialsVaryWithCreature()) ++bad;
            if (!uam5DismissalMaterialInimical()) ++bad;
            if (!uam5DismissalBeckonMaterialPleasing()) ++bad;
            if (!uam5DismissalTailAtRegionHead()) ++bad;
            if (!uam5DismissalNotOnPrimeNatives()) ++bad;
            if (!uam5DismissalNotOnPrimeAncestry()) ++bad;

        // U3: dolor
            if (strcmp(uam5DolorName(),
                "Dolor (Enchantment/Charm)") != 0) ++bad;
            if (uam5DolorLevel() != 5) ++bad;
            if (uam5DolorRangeInches() != 7) ++bad;
            if (!uam5DolorRangeAsPrintedPendingPdf()) ++bad;
            if (uam5DolorDurationRounds() != 2) ++bad;
            if (!uam5DolorAoeOneCreature()) ++bad;
            if (!uam5DolorComponentsVS()) ++bad;
            if (uam5DolorCastingTimeSegments() != 5) ++bad;
            if (!uam5DolorSaveSpecial()) ++bad;
            if (!uam5DolorProseHeadScrambled()) ++bad;
            if (!uam5DolorUneaseDuringCasting()) ++bad;
            if (!uam5DolorNervousSecondRound()) ++bad;
            if (!uam5DolorDullDolorLastRound()) ++bad;
            if (uam5DolorSaveAdjustInitial() != 1) ++bad;
            if (uam5DolorSaveAdjustSecond() != 2) ++bad;
            if (uam5DolorSaveAdjustTertiary() != 3) ++bad;
            if (!uam5DolorAdjustsAllSaves()) ++bad;
            if (!uam5DolorUnaffectedAfterLastRound()) ++bad;
            if (!uam5DolorVerbalDealsWithCreatureClass()) ++bad;

        // U4: fabricate
            if (strcmp(uam5FabricateName(),
                "Fabricate (Enchantment - Alteration)") != 0) ++bad;
            if (uam5FabricateLevel() != 5) ++bad;
            if (!uam5FabricateDurationPermanent()) ++bad;
            if (!uam5FabricateComponentsVSM()) ++bad;
            if (!uam5FabricateCastingTimeSpecial()) ++bad;
            if (!uam5FabricateSaveNone()) ++bad;
            if (uam5FabricateAoeCuYdPerLevel() != 1) ++bad;
            if (!uam5FabricateSameMaterialProducts()) ++bad;
            if (!uam5FabricateBridgeRopeClothesExamples()) ++bad;
            if (!uam5FabricateNoMagicalOrLiving()) ++bad;
            if (!uam5FabricateQualityCommensurate()) ++bad;
            if (uam5FabricateMineralFactor() != 9) ++bad;
            if (!uam5FabricateMineralYdToFoot()) ++bad;
            if (!uam5FabricateCraftsmanshipNeedsSkill()) ++bad;
            if (!uam5FabricateCraftArticlesExamples()) ++bad;
            if (uam5FabricateRoundsPerCuUnit() != 1) ++bad;

        // U5: the Leomund belabourment
            if (strcmp(uam5BelabourmentName(),
                "Leomund's Lamentable Belabourment") != 0) ++bad;
            if (!uam5BelabourmentNameHeaderLost()) ++bad;
            if (!uam5BelabourmentSchoolLost()) ++bad;
            if (uam5BelabourmentLevel() != 5) ++bad;
            if (!uam5BelabourmentComponentsCellLost()) ++bad;
            if (!uam5BelabourmentEntirelyVerbal()) ++bad;
            if (uam5BelabourmentCastingTimeSegments() != 5) ++bad;
            if (uam5BelabourmentRangeInches() != 1) ++bad;
            if (!uam5BelabourmentSaveSpecial()) ++bad;
            if (!uam5BelabourmentDurationSpecial()) ++bad;
            if (!uam5BelabourmentAoeOneOrMoreIn1InchRadius()) ++bad;
            if (!uam5BelabourmentHeadFragmentsUncertain()) ++bad;
            if (!uam5BelabourmentGermaneDiscussion()) ++bad;
            if (!uam5BelabourmentConversePolitely()) ++bad;
            if (!uam5BelabourmentMaintainedByConversing()) ++bad;
            if (!uam5BelabourmentSubjectsIgnoreAllElse()) ++bad;
            if (uam5BelabourmentIntUnaffectedMax() != 2) ++bad;
            if (uam5BelabourmentIntLowSaveMinus() != 1) ++bad;
            if (!uam5BelabourmentIntLadder()) ++bad;
            if (uam5BelabourmentConfusionAfterRounds() != 3) ++bad;
            if (uam5BelabourmentConfusionRoundsMin() != 3) ++bad;
            if (uam5BelabourmentConfusionRoundsMax() != 12) ++bad;
            if (!uam5BelabourmentFascinationResave456()) ++bad;
            if (uam5BelabourmentRageAfterRounds() != 6) ++bad;
            if (uam5BelabourmentRageRoundsMin() != 2) ++bad;
            if (uam5BelabourmentRageRoundsMax() != 5) ++bad;
            if (!uam5BelabourmentRageAtSelfOrOthers()) ++bad;
            if (uam5BelabourmentLamentRoundsMin() != 1) ++bad;
            if (uam5BelabourmentLamentRoundsMax() != 4) ++bad;
            if (!uam5BelabourmentCasterProtectedIfAttacked()) ++bad;
            if (!uam5BelabourmentCasterCanLeave()) ++bad;
            if (uam5BelabourmentContinuesAfterLeavingRounds() != 1) ++bad;
            if (!uam5BelabourmentNoSavesAfterLeaving()) ++bad;

        // U6: sending
            if (strcmp(uam5SendingName(),
                "Sending (Evocation)") != 0) ++bad;
            if (uam5SendingLevel() != 5) ++bad;
            if (!uam5SendingRangeSpecial()) ++bad;
            if (!uam5SendingDurationSpecial()) ++bad;
            if (!uam5SendingAoeOneCreature()) ++bad;
            if (!uam5SendingComponentsVSM()) ++bad;
            if (uam5SendingCastingTimeTurns() != 1) ++bad;
            if (!uam5SendingSaveNone()) ++bad;
            if (!uam5SendingContactFamiliarNamed()) ++bad;
            if (uam5SendingFailPctPerPlane() != 5) ++bad;
            if (!uam5SendingTwoPlanesTenPctExample()) ++bad;
            if (!uam5SendingOneWordPerLevel()) ++bad;
            if (!uam5SendingArticlesNotCounted()) ++bad;
            if (!uam5SendingNotObligated()) ++bad;
            if (!uam5SendingUnderstoodAtIntOne()) ++bad;
            if (!uam5SendingMaterialTwoCylindersCopperWire()) ++bad;

        // U7: chain lightning
            if (strcmp(uam6ChainName(),
                "Chain Lightning (Evocation)") != 0) ++bad;
            if (uam6ChainLevel() != 6) ++bad;
            if (!uam6ChainComponentsVSM()) ++bad;
            if (uam6ChainCastingTimeSegments() != 6) ++bad;
            if (uam6ChainRangeBaseInches() != 4) ++bad;
            if (!uam6ChainRangePerLevelTailLost()) ++bad;
            if (!uam6ChainSaveCellFractionGarbled()) ++bad;
            if (!uam6ChainSaveAvoidsSecondaryHit()) ++bad;
            if (!uam6ChainHalfDamageSavePerStrike()) ++bad;
            if (!uam6ChainDurationInstantaneous()) ++bad;
            if (!uam6ChainAoeSpecial()) ++bad;
            if (!uam6ChainStrokeQuarterInchWide()) ++bad;
            if (!uam6ChainPrimaryWithinRangeLimit()) ++bad;
            if (uam6ChainPrimaryDicePerLevel() != 1) ++bad;
            if (uam6ChainPrimaryDiceSides() != 6) ++bad;
            if (uam6ChainDiceStepDownPerTarget() != 1) ++bad;
            if (!uam6ChainLinksEqualCasterLevels()) ++bad;
            if (uam6ChainExampleLevel() != 12) ++bad;
            if (uam6ChainExampleTargets() != 12) ++bad;
            if (!uam6ChainTiebreakMetalThenFluid()) ++bad;
            if (!uam6ChainOscillationPossible()) ++bad;
            if (!uam6ChainArcBoundedByRange()) ++bad;
            if (!uam6ChainGroundedByTreeOrMetal()) ++bad;
            if (!uam6ChainCasterCanBeStruck()) ++bad;
            if (!uam6ChainMaterialFurRodPins()) ++bad;
            if (!uam6ChainSilverPinsPerLevel()) ++bad;

        // U8: contingency
            if (strcmp(uam6ContName(),
                "Contingency (Evocation)") != 0) ++bad;
            if (uam6ContLevel() != 6) ++bad;
            if (!uam6ContCastingCellsLost()) ++bad;
            if (uam6ContCastingTimeTurns() != 1) ++bad;
            if (!uam6ContCastingCoversBothSpells()) ++bad;
            if (uam6ContRangeZero() != 0) ++bad;
            if (uam6ContDurationDaysPerLevel() != 1) ++bad;
            if (!uam6ContSaveNone()) ++bad;
            if (!uam6ContAoeTheMagicUser()) ++bad;
            if (!uam6ContCompanionAffectsCaster()) ++bad;
            if (uam6ContCompanionLevelDivisor() != 3) ++bad;
            if (!uam6ContCompanionLevelCap()) ++bad;
            if (uam6ContMax4thAtLevel() != 12) ++bad;
            if (uam6ContMax5thAtLevel() != 15) ++bad;
            if (uam6ContMax6thAtLevel() != 18) ++bad;
            if (!uam6ContOneAtATime()) ++bad;
            if (!uam6ContSecondCancelsFirst()) ++bad;
            if (!uam6ContSituationClearThoughGeneral()) ++bad;
            if (!uam6ContCompanionInstantaneous()) ++bad;
            if (!uam6ContComplexSituationsLikelyFail()) ++bad;
            if (uam6ContQuicksilverGp() != 100) ++bad;
            if (!uam6ContMaterialIvoryStatuette()) ++bad;
            if (!uam6ContMaterialEyelashSpellUser()) ++bad;
            if (!uam6ContStatuetteNotConsumed()) ++bad;
            if (!uam6ContStatuetteMustBeCarried()) ++bad;

        // U9: ensnarement
            if (strcmp(uam6EnsnareName(),
                "Ensnarement (Conjuration/Summoning)") != 0) ++bad;
            if (!uam6EnsnareNameHeaderLost()) ++bad;
            if (!uam6EnsnareSchoolCellLost()) ++bad;
            if (!uam6EnsnareComponentsVSM()) ++bad;
            if (uam6EnsnareLevel() != 6) ++bad;
            if (uam6EnsnareCastingTimeTurns() != 1) ++bad;
            if (uam6EnsnareRangeInches() != 7) ++bad;
            if (!uam6EnsnareRangePendingPdf()) ++bad;
            if (!uam6EnsnareDurationSpecial()) ++bad;
            if (!uam6EnsnareAoeSpecial()) ++bad;
            if (!uam6EnsnareSaveNeg()) ++bad;
            if (!uam6EnsnareOneServiceForFreedom()) ++bad;
            if (uam6EnsnareSaveDice() != 3) ++bad;
            if (uam6EnsnareSaveDieSides() != 6) ++bad;
            if (!uam6EnsnareSaveModifiedByIntDiff()) ++bad;
            if (!uam6EnsnareSaveIgnoresOpening()) ++bad;
            if (!uam6EnsnareCreatureMustBeNamed()) ++bad;
            if (!uam6EnsnareCircleForEtherealAstral()) ++bad;
            if (!uam6EnsnarePentagramForInfernal()) ++bad;
            if (uam6EnsnareBreakBaseHandPct() != 20) ++bad;
            if (uam6EnsnareBreakBaseInlaidPct() != 10) ++bad;
            if (!uam6EnsnareBaseFirstTimeOnly()) ++bad;
            if (!uam6EnsnareBreakModifiedByTotals()) ++bad;
            if (!uam6EnsnareBreakDiffSubtractedOrAdded()) ++bad;
            if (uam6EnsnarePigmentGpPerTurn() != 1000) ++bad;
            if (uam6EnsnarePigmentPctPerTurn() != 1) ++bad;
            if (!uam6EnsnarePigmentCannotNegateMods()) ++bad;
            if (uam6EnsnareInlayMonths() != 1) ++bad;
            if (uam6EnsnareInlayGp() != 50000) ++bad;
            if (!uam6EnsnareStrawSpoilsBarrier()) ++bad;
            if (!uam6EnsnareCreatureCannotSpoil()) ++bad;
            if (uam6EnsnareOfferRatingMin() != 0) ++bad;
            if (uam6EnsnareOfferRatingMax() != 6) ++bad;
            if (!uam6EnsnareSaveRefusesService()) ++bad;
            if (uam6EnsnareReofferHours() != 24) ++bad;
            if (uam6EnsnareIntDropPerDay() != 1) ++bad;
            if (!uam6EnsnareRepeatUntilService()) ++bad;
            if (!uam6EnsnareTeleportAfterService()) ++bad;
            if (!uam6EnsnareRevengeRisk()) ++bad;

        // U10: eyebite
            if (strcmp(uam6EyeName(),
                "Eyebite") != 0) ++bad;
            if (!uam6EyeSchoolHeaderGarbled()) ++bad;
            if (!uam6EyeSchoolPendingPdf()) ++bad;
            if (!uam6EyeComponentsV()) ++bad;
            if (!uam6EyeComponentsCellGarbled()) ++bad;
            if (uam6EyeLevel() != 6) ++bad;
            if (uam6EyeRangeInches() != 20) ++bad;
            if (uam6EyeCastingTimeSegments() != 1) ++bad;
            if (!uam6EyeDurationSpecial()) ++bad;
            if (!uam6EyeSaveSpecial()) ++bad;
            if (!uam6EyeAoeOneCreature()) ++bad;
            if (!uam6EyeGazePlusSingleWord()) ++bad;
            if (uam6EyeEffectCount() != 4) ++bad;
            if (!uam6EyeDissipatesAfterOneEffect()) ++bad;
            if (!uam6EyeSavePlusFourNoteGarbled()) ++bad;
            if (!uam6EyeCharmLoyalDocile()) ++bad;
            if (!uam6EyeCharmSameAsCharmSpells()) ++bad;
            if (!uam6EyeCharmSaveNegates()) ++bad;
            if (!uam6EyeFearAsFearSpell()) ++bad;
            if (!uam6EyeFearSaveNegates()) ++bad;
            if (!uam6EyeSickenHalfAbilities()) ++bad;
            if (!uam6EyeSickenHalfMovement()) ++bad;
            if (!uam6EyeSickenRestHalfTurn()) ++bad;
            if (!uam6EyeSickenSkipsNoScoreCreatures()) ++bad;
            if (!uam6EyeSickenSaveNegates()) ++bad;
            if (uam6EyeSickenConLossPerDay() != 1) ++bad;
            if (!uam6EyeSickenCuredByDispelOrHeal()) ++bad;
            if (!uam6EyeSickenCuredByWishFamily()) ++bad;
            if (!uam6EyeSickenNotCuredByCureDisease()) ++bad;
            if (!uam6EyeSleepComatose()) ++bad;
            if (!uam6EyeSleepSaveNegates()) ++bad;
            if (uam6EyeSleepSaveAdj() != -2) ++bad;
            if (!uam6EyeSleepUndeadImmune()) ++bad;
            if (!uam6EyeSleepNeedsShaking()) ++bad;

        // U11: the Mordenkainen lucubration
            if (strcmp(uam6LucName(),
                "Mordenkainen's Lucubration") != 0) ++bad;
            if (!uam6LucNameHeaderLost()) ++bad;
            if (!uam6LucComponentsVS()) ++bad;
            if (uam6LucCastingTimeSegments() != 1) ++bad;
            if (!uam6LucSaveNone()) ++bad;
            if (!uam6LucDurationCellLost()) ++bad;
            if (!uam6LucDurationInstantaneous()) ++bad;
            if (uam6LucLevel() != 6) ++bad;
            if (!uam6LucAoeTheMagicUser()) ++bad;
            if (uam6LucRecallWindowHours() != 24) ++bad;
            if (!uam6LucRecallMustHaveBeenCast()) ++bad;
            if (uam6LucRecallMaxLevel() != 5) ++bad;
            if (!uam6LucOneSpellPerCasting()) ++bad;
            if (!uam6LucRecastOnSucceedingRound()) ++bad;
            if (!uam6LucComponentsMustBeAvailable()) ++bad;

        // U12: transmute water to dust
            if (strcmp(uam6WaterName(),
                "Transmute Water To Dust") != 0) ++bad;
            if (!uam6WaterHeaderPrintsShortName()) ++bad;
            if (!uam6WaterComponentsVSM()) ++bad;
            if (!uam6WaterComponentsCellGarbled()) ++bad;
            if (!uam6WaterNoMistletoe()) ++bad;
            if (uam6WaterLevel() != 6) ++bad;
            if (uam6WaterRangeInches() != 6) ++bad;
            if (uam6WaterCastingTimeSegments() != 6) ++bad;
            if (uam6WaterDruidSeamCastingTimeSegments() != 8) ++bad;
            if (!uam6WaterCastingDiscrepancyFlagged()) ++bad;
            if (!uam6WaterSaveNoneAndSpecial()) ++bad;
            if (!uam6WaterDurationPermanent()) ++bad;
            if (uam6WaterCubicInchesPerLevel() != 1) ++bad;
            if (!uam6WaterAoeGarbleCorroborated()) ++bad;
            if (!uam6WaterSameAsDruid6th()) ++bad;

        // the R342 table seam (4 of the 6 5th-level
        // names; avoidance and dolor absent; the
        // 6th-level column is wholly lost)
        if (uas2Mu5thCount() != 28) ++bad;
        if (strcmp(uas2Mu5thName(8),
                "Dismissal") != 0) ++bad;
        if (strcmp(uas2Mu5thName(11),
                "Fabricate") != 0) ++bad;
        if (strcmp(uas2Mu5thName(14),
                "Leomund's Lamentable Belabourment")
                != 0) ++bad;
        if (strcmp(uas2Mu5thName(20),
                "Sending") != 0) ++bad;
        // the absent names (the avoidance and
        // dolor holes)
        for (int i = 0; i < 28; ++i) {
            const char* n = uas2Mu5thName(i);
            if (strcmp(n, "Avoidance") == 0)
                ++bad;
            if (strcmp(n, "Dolor") == 0) ++bad;
        }
        // the water-to-dust seam against the R352
        // druid pin - identical data except the
        // mistletoe and the flagged casting time
        if (uam6WaterLevel()
                != uad6WaterToDustLevel()) ++bad;
        if (uam6WaterRangeInches()
                != uad6WaterToDustRangeInches()) ++bad;
        if (uam6WaterCastingTimeSegments() != 6)
            ++bad;
        if (uad6WaterToDustCastingTimeSegments()
                != 8) ++bad;
        if (uam6WaterCastingTimeSegments()
                == uad6WaterToDustCastingTimeSegments())
            ++bad;
        if (!uam6WaterCastingDiscrepancyFlagged())
            ++bad;
        if (uam6WaterCubicInchesPerLevel()
                != uad6WaterToDustAoeCubicInchesPerLevel())
            ++bad;
        if (!uam6WaterAoeGarbleCorroborated())
            ++bad;
        if (strcmp(uam6WaterName(),
                "Transmute Water To Dust") != 0)
            ++bad;
        if (uad6WaterToDustMaterialMistletoe()
                && uam6WaterNoMistletoe()) { /* ok */ }
        else ++bad;
        if (!uad6WaterToDustMaterialMistletoe())
            ++bad;
        if (!uam6WaterSameAsDruid6th()) ++bad;
        printf("R360 UA MU 5th/6th level spells pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
