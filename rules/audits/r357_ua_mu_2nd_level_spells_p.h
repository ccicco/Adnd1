    // ---- R357: the UA new magic-user 2nd level spells pin audit ----
    // The UA NEW MAGIC-USER SPELLS (pp.
    // 51-52), the 2nd level - bind,
    // deeppockets (the lost name header),
    // flaming sphere, irritation, know
    // alignment, the Melf acid arrow,
    // preserve, protection from
    // cantrips, the Tasha laughter,
    // vocalize, whip and zephyr. The
    // family decodes the 7s as 1. The
    // R342 table seam pins 8 of 12;
    // the item stays open (the 3rd-9th
    // levels).
    {
        using namespace rules;
        int bad = 0;
        // U1: bind
            if (strcmp(uam2BindName(),
                "Bind (Alteration/Enchantment)") != 0) ++bad;
            if (uam2BindLevel() != 2) ++bad;
            if (uam2BindRangeInches() != 3) ++bad;
            if (uam2BindDurationRoundsPerLevel() != 1) ++bad;
            if (!uam2BindAoeSpecial()) ++bad;
            if (!uam2BindComponentsVSM()) ++bad;
            if (uam2BindCastingTimeSegments() != 2) ++bad;
            if (!uam2BindSaveNone()) ++bad;
            if (!uam2BindRopelikeNonLiving()) ++bad;
            if (!uam2BindBehavesAsOrdered()) ++bad;
            if (uam2BindBaseFeet() != 50) ++bad;
            if (uam2BindFeetPerLevel() != 5) ++bad;
            if (!uam2BindReduceWithDiameter()) ++bad;
            if (uam2BindHalvingBonusPct() != 50) ++bad;
            if (!uam2BindCommandsCoilLoopTie()) ++bad;
            if (!uam2BindReversesAvailable()) ++bad;
            if (uam2BindRespondWithinFeet() != 1) ++bad;
            if (!uam2BindUsuallyThrown()) ++bad;
            if (!uam2BindCreatureHoldOverrides()) ++bad;
            if (uam2BindSlashingDamageToBreak() != 2) ++bad;
            if (!uam2BindNoGarrotUse()) ++bad;
            if (!uam2BindTripLineOrEntangle()) ++bad;
            if (!uam2BindNoMagicBeyondCommands()) ++bad;
        // U2: deeppockets
            if (strcmp(uam2DeeppocketsName(), "Deeppockets") != 0) ++bad;
            if (!uam2DeeppocketsNameHeaderLost()) ++bad;
            if (!uam2DeeppocketsComponentsGarbled()) ++bad;
            if (uam2DeeppocketsLevel() != 2) ++bad;
            if (uam2DeeppocketsCastingTimeTurns() != 1) ++bad;
            if (!uam2DeeppocketsRangeTouch()) ++bad;
            if (!uam2DeeppocketsSaveNone()) ++bad;
            if (uam2DeeppocketsDurationTurnsBase() != 24) ++bad;
            if (uam2DeeppocketsDurationTurnsPerLevel() != 6) ++bad;
            if (!uam2DeeppocketsAoeOneGarment()) ++bad;
            if (uam2DeeppocketsGarmentMinGp() != 300) ++bad;
            if (uam2DeeppocketsMinPockets() != 12) ++bad;
            if (uam2DeeppocketsSpecialPocketGp() != 1000) ++bad;
            if (uam2DeeppocketsSpecialPocketCuFt() != 5) ++bad;
            if (uam2DeeppocketsAsIfGp() != 100) ++bad;
            if (!uam2DeeppocketsNoBulge()) ++bad;
            if (uam2DeeppocketsAltPocketCount() != 10) ++bad;
            if (uam2DeeppocketsAltPocketGp() != 100) ++bad;
            if (!uam2DeeppocketsAltVolumeNumberLost()) ++bad;
            if (uam2DeeppocketsHundredPocketGarmentGp() != 1000) ++bad;
            if (uam2DeeppocketsHundredPocketCount() != 100) ++bad;
            if (uam2DeeppocketsHundredPocketGp() != 10) ++bad;
            if (!uam2DeeppocketsHundredPocketFractionGarbled()) ++bad;
            if (!uam2DeeppocketsExpirySaveVsSpell()) ++bad;
            if (!uam2DeeppocketsFailAstralLostForever()) ++bad;
            if (!uam2DeeppocketsSuccessAppearsAndFalls()) ++bad;
            if (!uam2DeeppocketsMaterialGoldenNeedle()) ++bad;
            if (!uam2DeeppocketsMaterialClothHalfTwist()) ++bad;
        // U3: flaming sphere
            if (strcmp(uam2FlamingSphereName(),
                "Flaming Sphere (Alteration/Evocation)") != 0) ++bad;
            if (uam2FlamingSphereLevel() != 2) ++bad;
            if (uam2FlamingSphereRangeInches() != 1) ++bad;
            if (!uam2FlamingSphereRangeGarbleDecoded()) ++bad;
            if (uam2FlamingSphereCastingTimeSegments() != 2) ++bad;
            if (!uam2FlamingSphereSaveNegates()) ++bad;
            if (uam2FlamingSphereDurationRoundsPerLevel() != 1) ++bad;
            if (uam2FlamingSphereDiameterFeet() != 6) ++bad;
            if (!uam2FlamingSphereComponentsVSM()) ++bad;
            if (uam2FlamingSphereAppearsWithinInches() != 1) ++bad;
            if (!uam2FlamingSphereRollsAsPointed()) ++bad;
            if (uam2FlamingSphereBarrierMaxFeet() != 4) ++bad;
            if (!uam2FlamingSphereSetsFlammablesAfire()) ++bad;
            if (uam2FlamingSphereDamageMin() != 2) ++bad;
            if (uam2FlamingSphereDamageMax() != 8) ++bad;
            if (uam2FlamingSphereMoveInchesPerRound() != 1) ++bad;
            if (!uam2FlamingSphereInterleaveGarbleDecoded()) ++bad;
            if (uam2FlamingSphereBlastRadiusFeet() != 5) ++bad;
            if (!uam2FlamingSphereRestsUnpointed()) ++bad;
            if (!uam2FlamingSphereExtinguishedAsNormalFire()) ++bad;
            if (!uam2FlamingSphereMaterialTallow()) ++bad;
            if (!uam2FlamingSphereMaterialSulphur()) ++bad;
            if (!uam2FlamingSphereMaterialPowderedIron()) ++bad;
        // U4: irritation
            if (strcmp(uam2IrritationName(),
                "Irritation (Alteration)") != 0) ++bad;
            if (uam2IrritationLevel() != 2) ++bad;
            if (uam2IrritationRangeInchesPerLevel() != 1) ++bad;
            if (uam2IrritationCastingTimeSegments() != 2) ++bad;
            if (!uam2IrritationSaveNegates()) ++bad;
            if (!uam2IrritationDurationSpecial()) ++bad;
            if (!uam2IrritationAoeOneCreature()) ++bad;
            if (!uam2IrritationComponentsVSM()) ++bad;
            if (!uam2IrritationAffectsEpidermis()) ++bad;
            if (!uam2IrritationThickSkinnedUnaffected()) ++bad;
            if (!uam2IrritationTwoVersions()) ++bad;
            if (uam2IrritationScratchSegmentsMin() != 5) ++bad;
            if (uam2IrritationScratchSegmentsMax() != 8) ++bad;
            if (uam2IrritationSquirmRounds() != 3) ++bad;
            if (uam2IrritationAcWorseBy() != 4) ++bad;
            if (uam2IrritationToHitWorseBy() != 2) ++bad;
            if (!uam2IrritationSpellsRuinedFirstRoundOnly()) ++bad;
            if (uam2IrritationRashLatencyMinRounds() != 1) ++bad;
            if (uam2IrritationRashLatencyMaxRounds() != 4) ++bad;
            if (!uam2IrritationRashPersistsUntilCureOrDispel()) ++bad;
            if (uam2IrritationRashComelinessPerDay() != 1) ++bad;
            if (uam2IrritationRashComelinessMaxLoss() != 4) ++bad;
            if (uam2IrritationRashDexLossAfterWeek() != 1) ++bad;
            if (!uam2IrritationRashVanishesOnRemoval()) ++bad;
            if (!uam2IrritationMaterialPoisonLeaf()) ++bad;
        // U5: know alignment
            if (strcmp(uam2KnowAlignmentName(),
                "Know Alignment (Divination)") != 0) ++bad;
            if (uam2KnowAlignmentLevel() != 2) ++bad;
            if (!uam2KnowAlignmentReversible()) ++bad;
            if (!uam2KnowAlignmentComponentsCellLost()) ++bad;
            if (uam2KnowAlignmentCastingTimeRounds() != 1) ++bad;
            if (!uam2KnowAlignmentRangeCellLost()) ++bad;
            if (!uam2KnowAlignmentSaveNone()) ++bad;
            if (uam2KnowAlignmentDurationRoundsPerLevel() != 1) ++bad;
            if (uam2KnowAlignmentAoeCreaturesPer2Rounds() != 1) ++bad;
            if (!uam2KnowAlignmentSameAsClerical()) ++bad;
            if (!uam2KnowAlignmentOneRoundEthicOnly()) ++bad;
        // U6: the Melf acid arrow
            if (strcmp(uam2AcidArrowName(),
                "Melf's Acid Arrow (Evocation)") != 0) ++bad;
            if (uam2AcidArrowLevel() != 2) ++bad;
            if (uam2AcidArrowRangeInches() != 3) ++bad;
            if (!uam2AcidArrowDurationSpecial()) ++bad;
            if (!uam2AcidArrowAoeOneTarget()) ++bad;
            if (!uam2AcidArrowComponentsVSM()) ++bad;
            if (uam2AcidArrowCastingTimeSegments() != 4) ++bad;
            if (!uam2AcidArrowSaveSpecial()) ++bad;
            if (!uam2AcidArrowSpeedsAsFighterBow()) ++bad;
            if (uam2AcidArrowPlusForHit() != 1) ++bad;
            if (!uam2AcidArrowAcidBypassesPlusOneImmunity()) ++bad;
            if (uam2AcidArrowDamageMin() != 2) ++bad;
            if (uam2AcidArrowDamageMax() != 5) ++bad;
            if (uam2AcidArrowAcidVolumeOunces() != 8) ++bad;
            if (uam2AcidArrowAcidDamageMin() != 2) ++bad;
            if (uam2AcidArrowAcidDamageMax() != 8) ++bad;
            if (!uam2AcidArrowItemSavingThrowApplies()) ++bad;
            if (!uam2AcidArrowNoSplash()) ++bad;
            if (uam2AcidArrowExtraRoundsPer3Levels() != 1) ++bad;
            if (uam2AcidArrowExtraRoundsFromLevel() != 4) ++bad;
            if (!uam2AcidArrowNeutralizationStops()) ++bad;
            if (!uam2AcidArrowMaterialDart()) ++bad;
            if (!uam2AcidArrowMaterialRhubarbLeaf()) ++bad;
            if (!uam2AcidArrowMaterialAdderStomach()) ++bad;
        // U7: preserve
            if (strcmp(uam2PreserveName(),
                "Preserve (Abjuration)") != 0) ++bad;
            if (uam2PreserveLevel() != 2) ++bad;
            if (uam2PreserveCastingTimeRounds() != 2) ++bad;
            if (!uam2PreserveRangeTouch()) ++bad;
            if (!uam2PreserveSaveNone()) ++bad;
            if (!uam2PreserveDurationPermanent()) ++bad;
            if (!uam2PreserveAoeNumberLost()) ++bad;
            if (!uam2PreserveAoeCuFtPerLevel()) ++bad;
            if (!uam2PreserveComponentsVSM()) ++bad;
            if (!uam2PreserveRetainsItemFresh()) ++bad;
            if (!uam2PreserveIneffectiveForFreshGather()) ++bad;
            if (!uam2PreserveOpenerGarbleDecoded()) ++bad;
            if (uam2PreserveHardDryMinLevel() != 2) ++bad;
            if (uam2PreserveHardDryMaxLevel() != 4) ++bad;
            if (uam2PreserveSoftWetMinLevel() != 5) ++bad;
            if (uam2PreserveSoftWetMaxLevel() != 7) ++bad;
            if (uam2PreserveLiquidMinLevel() != 8) ++bad;
            if (!uam2PreserveContainerOnlyForMoisture()) ++bad;
            if (!uam2PreserveMaterialDust()) ++bad;
            if (!uam2PreserveMaterialResinOrAmber()) ++bad;
            if (!uam2PreserveMaterialBrandy()) ++bad;
        // U8: protection from cantrips
            if (strcmp(uam2PfcName(),
                "Protection From Cantrips") != 0) ++bad;
            if (!uam2PfcNameHeaderGarbled()) ++bad;
            if (uam2PfcLevel() != 2) ++bad;
            if (!uam2PfcRangeTouch()) ++bad;
            if (uam2PfcCastingTimeSegments() != 2) ++bad;
            if (!uam2PfcSaveNoneOrNegates()) ++bad;
            if (uam2PfcDurationDaysPerLevel() != 1) ++bad;
            if (!uam2PfcAoeOneCreatureOrObject()) ++bad;
            if (!uam2PfcComponentsCellLost()) ++bad;
            if (!uam2PfcImmunityToCantrips()) ++bad;
            if (!uam2PfcProseInterleaveDecoded()) ++bad;
            if (!uam2PfcProtectsCasterOrItem()) ++bad;
            if (!uam2PfcCantripDissipatesWithPop()) ++bad;
            if (!uam2PfcMischievousApprenticesUse()) ++bad;
            if (!uam2PfcUnwillingToHitAndSave()) ++bad;
        // U9: the Tasha laughter
            if (strcmp(uam2TashaName(),
                "Tasha's Uncontrollable Hideous Laughter (Evo"
                "cation)") != 0) ++bad;
            if (uam2TashaLevel() != 2) ++bad;
            if (uam2TashaCastingTimeSegments() != 2) ++bad;
            if (uam2TashaRangeInches() != 5) ++bad;
            if (!uam2TashaSaveSpecial()) ++bad;
            if (uam2TashaDurationRounds() != 1) ++bad;
            if (!uam2TashaAoeOneCreature()) ++bad;
            if (!uam2TashaComponentsVSM()) ++bad;
            if (!uam2TashaEverythingHilarious()) ++bad;
            if (!uam2TashaTinglingFirstRound()) ++bad;
            if (!uam2TashaLaughterSequenceDecoded()) ++bad;
            if (!uam2TashaNextRoundRegainFeet()) ++bad;
            if (uam2TashaMinusTwoRounds() != 2) ++bad;
            if (uam2TashaPenaltyRounds() != 2) ++bad;
            if (!uam2TashaSaveNegates()) ++bad;
            if (uam2TashaUnaffectedIntMax() != 3) ++bad;
            if (uam2TashaInt4to8SaveMod() != -6) ++bad;
            if (uam2TashaInt9to12SaveMod() != -4) ++bad;
            if (uam2TashaInt13to15SaveMod() != -2) ++bad;
            if (!uam2TashaInt16PlusNormalSave()) ++bad;
            if (!uam2TashaMaterialFeather()) ++bad;
            if (!uam2TashaMaterialPaddle()) ++bad;
            if (!uam2TashaMaterialTort()) ++bad;
        // U10: vocalize
            if (strcmp(uam2VocalizeName(),
                "Vocalize (Alteration)") != 0) ++bad;
            if (!uam2VocalizeComponentsSM()) ++bad;
            if (uam2VocalizeLevel() != 2) ++bad;
            if (!uam2VocalizeRangeTouch()) ++bad;
            if (uam2VocalizeCastingTimeRounds() != 1) ++bad;
            if (!uam2VocalizeSaveNone()) ++bad;
            if (uam2VocalizeDurationRounds() != 5) ++bad;
            if (!uam2VocalizeAoeOneSpellCastingCreature()) ++bad;
            if (!uam2VocalizeCastsSilently()) ++bad;
            if (!uam2VocalizeWithinDurationOnly()) ++bad;
            if (!uam2VocalizeSpeliGarble()) ++bad;
            if (!uam2VocalizeUsefulUnderSilence()) ++bad;
            if (!uam2VocalizeOffsetsNotNegates()) ++bad;
            if (!uam2VocalizeMasksAudibleEffects()) ++bad;
            if (!uam2VocalizeNoInfoBackToCaster()) ++bad;
            if (!uam2VocalizeMaterialBellNoClapper()) ++bad;
            if (!uam2VocalizeMaterialJailbirdsTongue()) ++bad;
        // U11: whip
            if (strcmp(uam2WhipName(), "Whip (Evocation)") != 0) ++bad;
            if (uam2WhipLevel() != 2) ++bad;
            if (!uam2WhipLevelCellLost()) ++bad;
            if (uam2WhipDurationRoundsPerLevel() != 1) ++bad;
            if (!uam2WhipAoeSpecial()) ++bad;
            if (!uam2WhipComponentsVSM()) ++bad;
            if (uam2WhipCastingTimeSegments() != 2) ++bad;
            if (!uam2WhipCastingCellSplitDecoded()) ++bad;
            if (!uam2WhipSaveSpecial()) ++bad;
            if (uam2WhipReachInches() != 1) ++bad;
            if (!uam2WhipWieldedByHandMovement()) ++bad;
            if (!uam2WhipCrackAndStrikeEachTurn()) ++bad;
            if (!uam2WhipSoundKeepsAnimalsAtBay()) ++bad;
            if (uam2WhipAnimalSaveModMin() != -1) ++bad;
            if (uam2WhipAnimalSaveModMax() != -4) ++bad;
            if (uam2WhipSlinkAwayHours() != 1) ++bad;
            if (!uam2WhipNoActualDamage()) ++bad;
            if (uam2WhipUnaffectedIntAbove() != 3) ++bad;
            if (!uam2WhipGiantAboveBearSizeUnaffected()) ++bad;
            if (!uam2WhipMonstersUnaffected()) ++bad;
            if (!uam2WhipMeleeWrapsWeapon()) ++bad;
            if (uam2WhipEdgedSaveVsCrushingBlow() != 13) ++bad;
            if (uam2WhipNonEdgedSaveVsNormalBlow() != 6) ++bad;
            if (!uam2WhipSuccessTearsFromHand()) ++bad;
            if (!uam2WhipOpponentSaveKeepsWeapon()) ++bad;
            if (uam2WhipWeaponRecoverRounds() != 1) ++bad;
            if (!uam2WhipMagicBonusPenalizesSave()) ++bad;
            if (!uam2WhipMagicResistanceMustFail()) ++bad;
            if (!uam2WhipMaterialSilkBraided()) ++bad;
        // U12: zephyr
            if (strcmp(uam2ZephyrName(), "Zephyr (Evocation)") != 0) ++bad;
            if (!uam2ZephyrComponentsVSM()) ++bad;
            if (!uam2ZephyrComponentsCellSplit()) ++bad;
            if (uam2ZephyrLevel() != 2) ++bad;
            if (uam2ZephyrRangeZero() != 0) ++bad;
            if (uam2ZephyrCastingTimeSegments() != 2) ++bad;
            if (!uam2ZephyrCastingUnitLost()) ++bad;
            if (!uam2ZephyrSaveNone()) ++bad;
            if (uam2ZephyrDurationSegments() != 1) ++bad;
            if (!uam2ZephyrAoeOnePath()) ++bad;
            if (!uam2ZephyrPathFractionGarbled()) ++bad;
            if (!uam2ZephyrDraftInFacedDirection()) ++bad;
            if (!uam2ZephyrSmallFlamesWaver()) ++bad;
            if (uam2ZephyrFanDamageBonus() != 1) ++bad;
            if (uam2ZephyrHoldVaporsRounds() != 1) ++bad;
            if (!uam2ZephyrHalvesFogDuration()) ++bad;
            if (uam2ZephyrMoveGasesBackInches() != 1) ++bad;
            if (!uam2ZephyrHalvesGasDurationAndPotency()) ++bad;
            if (!uam2ZephyrUnlessRenewed()) ++bad;
            if (!uam2ZephyrMaterialParchmentFolded()) ++bad;
            if (!uam2ZephyrMaterialPinIvorySilver()) ++bad;
        // the R342 table seam (8 of 12 names)
        if (uas2Mu2ndCount() != 30) ++bad;
        if (strcmp(uas2Mu2ndName(1),
                "Bind") != 0) ++bad;
        if (strcmp(uas2Mu2ndName(9),
                "Irritation") != 0) ++bad;
        if (strcmp(uas2Mu2ndName(11),
                "Know Alignment") != 0) ++bad;
        if (strcmp(uas2Mu2ndName(16),
                "Melf's Acid Arrow") != 0) ++bad;
        if (strcmp(uas2Mu2ndName(18),
                "Preserve") != 0) ++bad;
        if (strcmp(uas2Mu2ndName(26),
                "Tasha's Uncontrollable "
                "Hideous Laughter") != 0) ++bad;
        if (strcmp(uas2Mu2ndName(27),
                "Whip") != 0) ++bad;
        if (strcmp(uas2Mu2ndName(29),
                "Zephyr") != 0) ++bad;
        // the four names absent from the seam
        for (int i = 0; i < 30; ++i) {
            const char* n = uas2Mu2ndName(i);
            if (strcmp(n, "Deeppockets") == 0) ++bad;
            if (strcmp(n, "Flaming Sphere") == 0)
                ++bad;
            if (strcmp(n, "Protection From "
                "Cantrips") == 0)
                ++bad;
            if (strcmp(n, "Vocalize") == 0) ++bad;
        }
        printf("R357 UA MU 2nd level spells pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
