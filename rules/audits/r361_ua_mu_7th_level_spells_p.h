    // ---- R361: the UA new magic-user 7th level
    // spells pin audit ----
    // The UA NEW MAGIC-USER SPELLS (pp.
    // 66-71), the 7th level - banishment
    // behind the scrambled stat head,
    // forcecage with the stat tail
    // interleaved, the Mordenkainen
    // magnificent mansion behind the
    // garbled name header, sequester
    // behind the lost name header,
    // teleport without error with the
    // stat cells scrambled, torment
    // with the range cell lost,
    // truename with the save fragment
    // unattributed, volley with the
    // Explanation line lost; the
    // volley and truename sections
    // print past the 8th-level table
    // page. The family decodes the
    // casting and duration 7s as 1.
    // The R342 table seam prints
    // only PHB fragments - none of
    // the new names seam-checks. The
    // item stays open (the 8th-9th
    // levels).
    {
        using namespace rules;
        int bad = 0;
        // U1: banishment
            if (strcmp(uam7BanName(),
                "Banishment (Abjuration - Evocation)") != 0) ++bad;
            if (uam7BanLevel() != 7) ++bad;
            if (!uam7BanStatHeadScrambled()) ++bad;
            if (!uam7BanComponentsVSM()) ++bad;
            if (uam7BanRangeInches() != 2) ++bad;
            if (!uam7BanRangeCellInterleaved()) ++bad;
            if (uam7BanCastingTimeSegments() != 1) ++bad;
            if (!uam7BanSaveSpecial()) ++bad;
            if (!uam7BanDurationPermanent()) ++bad;
            if (uam7BanAoeLevelsPerCasterLevel() != 2) ++bad;
            if (!uam7BanForcesPlanarCreatureHome()) ++bad;
            if (!uam7BanEffectInstantaneous()) ++bad;
            if (!uam7BanCannotReturnWithoutSummoning()) ++bad;
            if (!uam7BanMultipleCreaturesIfStrength()) ++bad;
            if (!uam7BanMustNameTypeAndTrueName()) ++bad;
            if (!uam7BanCallsOpposedPowers()) ++bad;
            if (!uam7BanMagicResistanceMustBeDefeated()) ++bad;
            if (uam7BanMaterialSaveAdjPerSubstance() != 2) ++bad;
            if (uam7BanExampleSubstanceCount() != 4) ++bad;
            if (uam7BanExampleSaveAdj() != 8) ++bad;
            if (uam7BanSpecialItemAdjMin() != 3) ++bad;
            if (uam7BanSpecialItemAdjMax() != 4) ++bad;
            if (uam7BanContrarySubstanceLowersTo() != 1) ++bad;
            if (uam7BanBacklashDamageMin() != 2) ++bad;
            if (uam7BanBacklashDamageMax() != 12) ++bad;
            if (uam7BanBacklashStunSegmentsMin() != 2) ++bad;
            if (uam7BanBacklashStunSegmentsMax() != 12) ++bad;
            if (uam7BanPowerAugmentMin() != 1) ++bad;
            if (uam7BanPowerAugmentMax() != 6) ++bad;

        // U2: forcecage
            if (strcmp(uam7ForceName(),
                "Forcecage (Evocation)") != 0) ++bad;
            if (uam7ForceLevel() != 7) ++bad;
            if (uam7ForceRangeInchesPerTwoLevels() != 1) ++bad;
            if (uam7ForceDurationBaseTurns() != 6) ++bad;
            if (uam7ForceDurationTurnsPerLevel() != 1) ++bad;
            if (uam7ForceAoeCubeInches() != 2) ++bad;
            if (!uam7ForceStatTailInterleaved()) ++bad;
            if (!uam7ForceComponentsVSPlusSpecial()) ++bad;
            if (uam7ForceCastingTimeSegmentsMin() != 3) ++bad;
            if (uam7ForceCastingTimeSegmentsMax() != 4) ++bad;
            if (!uam7ForceSaveNone()) ++bad;
            if (!uam7ForceHalfInchGaps()) ++bad;
            if (!uam7ForceGapCellGarbled()) ++bad;
            if (!uam7ForceContainedUnlessPassesOpenings()) ++bad;
            if (!uam7ForceSpellsAndBreathPassGaps()) ++bad;
            if (!uam7ForceMagicResistanceSingleAttempt()) ++bad;
            if (!uam7ForceOthersTrappedUnlessResistant()) ++bad;
            if (!uam7ForceRemovedByDispelMagic()) ++bad;
            if (!uam7ForcecubeVariant()) ++bad;
            if (uam7ForcecubeAreaFactor() != 8) ++bad;
            if (uam7ForcecubeAoeCubeInches() != 1) ++bad;
            if (!uam7ForcecubeResemblesCubeOfForce()) ++bad;
            if (!uam7ForceNoMaterialOnCasting()) ++bad;
            if (uam7ForceDiamondDustGpMin() != 1000) ++bad;
            if (!uam7ForceDiamondDustTailScrambled()) ++bad;

        // U3: the Mordenkainen magnificent mansion
            if (strcmp(uam7MansionName(),
                "Mordenkainen's Magnificent Mansion") != 0) ++bad;
            if (!uam7MansionNameHeaderGarbled()) ++bad;
            if (!uam7MansionSchoolLost()) ++bad;
            if (!uam7MansionLevelCellLost()) ++bad;
            if (uam7MansionLevel() != 7) ++bad;
            if (!uam7MansionComponentsVSM()) ++bad;
            if (uam7MansionCastingTimeRounds() != 1) ++bad;
            if (!uam7MansionSaveNone()) ++bad;
            if (uam7MansionDurationHoursPerLevel() != 1) ++bad;
            if (!uam7MansionDurationCellTailGarbled()) ++bad;
            if (uam7MansionAoeSqFtPerLevel() != 300) ++bad;
            if (!uam7MansionExtraDimensionalDwelling()) ++bad;
            if (!uam7MansionSingleEntryPoint()) ++bad;
            if (uam7MansionPortalFeetWide() != 4) ++bad;
            if (uam7MansionPortalFeetHigh() != 8) ++bad;
            if (!uam7MansionPortalDegreeGarble()) ++bad;
            if (!uam7MansionCasterControlsEntry()) ++bad;
            if (!uam7MansionPortalInvisibleBehindCaster()) ++bad;
            if (uam7MansionBanquetCourses() != 9) ++bad;
            if (!uam7MansionDozensPerCasterLevel()) ++bad;
            if (!uam7MansionServantStaff()) ++bad;
            if (!uam7MansionAtmosphereCleanFreshWarm()) ++bad;
            if (!uam7MansionOutsideConditionsExcluded()) ++bad;
            if (!uam7MansionFoodNotRealNourishment()) ++bad;
            if (uam7MansionRecoveryHoursPerImaginaryMeal() != 1) ++bad;
            if (!uam7MansionStrengthLossPerMeal()) ++bad;
            if (uam7MansionLossPermanentAfterHours() != 6) ++bad;
            if (!uam7MansionMaterialIvoryPortal()) ++bad;
            if (!uam7MansionMaterialPolishedMarble()) ++bad;
            if (!uam7MansionMaterialSilverSpoon()) ++bad;
            if (!uam7MansionMaterialsDestroyed()) ++bad;
            if (!uam7MansionDesignAlterable()) ++bad;

        // U4: sequester
            if (strcmp(uam7SequesterName(),
                "Sequester") != 0) ++bad;
            if (!uam7SequesterNameHeaderLost()) ++bad;
            if (!uam7SequesterSchoolLost()) ++bad;
            if (!uam7SequesterComponentsVSM()) ++bad;
            if (uam7SequesterLevel() != 7) ++bad;
            if (!uam7SequesterRangeTouch()) ++bad;
            if (uam7SequesterCastingTimeRounds() != 1) ++bad;
            if (!uam7SequesterSaveSpecial()) ++bad;
            if (uam7SequesterDurationBaseWeeks() != 1) ++bad;
            if (uam7SequesterDurationDaysPerLevel() != 1) ++bad;
            if (uam7SequesterAoeCubeFeetPerLevel() != 2) ++bad;
            if (!uam7SequesterBlocksDetectionAndLocation()) ++bad;
            if (!uam7SequesterInvisibleToAllSight()) ++bad;
            if (!uam7SequesterNotProofFromTactileOrDevices()) ++bad;
            if (!uam7SequesterUnwillingCreatureSave()) ++bad;
            if (!uam7SequesterComatoseUntilWearsOff()) ++bad;
            if (!uam7SequesterProseScrambled()) ++bad;
            if (!uam7SequesterMaterialBasiliskEyelash()) ++bad;
            if (!uam7SequesterMaterialGumArabic()) ++bad;
            if (!uam7SequesterMaterialWhitewashDram()) ++bad;

        // U5: teleport without error
            if (strcmp(uam7TeleportName(),
                "Teleport Without Error (Alteration)") != 0) ++bad;
            if (uam7TeleportLevel() != 7) ++bad;
            if (!uam7TeleportRangeTouch()) ++bad;
            if (!uam7TeleportDurationInstantaneous()) ++bad;
            if (!uam7TeleportAoeSpecial()) ++bad;
            if (!uam7TeleportStatCellsScrambled()) ++bad;
            if (!uam7TeleportComponentsV()) ++bad;
            if (uam7TeleportCastingTimeSegments() != 1) ++bad;
            if (!uam7TeleportSaveNone()) ++bad;
            if (!uam7TeleportHomePlaneNoError()) ++bad;
            if (!uam7TeleportWeightAsTeleport()) ++bad;
            if (!uam7TeleportOtherPlanesStudiedCarefully()) ++bad;
            if (!uam7TeleportUsesTeleportTableOffPlane()) ++bad;
            if (!uam7TeleportSuccorException()) ++bad;
            if (!uam7TeleportNothingElseThatRound()) ++bad;

        // U6: torment
            if (strcmp(uam7TormentName(),
                "Torment (Evocation - Alteration)") != 0) ++bad;
            if (!uam7TormentComponentsVSM()) ++bad;
            if (uam7TormentLevel() != 7) ++bad;
            if (!uam7TormentRangeCellLost()) ++bad;
            if (uam7TormentCastingTimeRounds() != 1) ++bad;
            if (!uam7TormentSaveSpecial()) ++bad;
            if (!uam7TormentDurationSpecial()) ++bad;
            if (!uam7TormentDurationCellDisplaced()) ++bad;
            if (!uam7TormentAoeOneCreature()) ++bad;
            if (!uam7TormentForcesSubmissionForService()) ++bad;
            if (!uam7TormentCfDolorAndEnsnarement()) ++bad;
            if (!uam7TormentLinkToCaptiveInCircle()) ++bad;
            if (!uam7TormentMagicResistanceMustFail()) ++bad;
            if (!uam7TormentReadingRoundsLadder()) ++bad;
            if (uam7TormentTwingesRounds() != 2) ++bad;
            if (uam7TormentShootingPainsStartRound() != 3) ++bad;
            if (uam7TormentAchesCrampsStartRound() != 5) ++bad;
            if (uam7TormentSaveAdjR1() != -1) ++bad;
            if (uam7TormentSaveAdjR2() != -2) ++bad;
            if (uam7TormentSaveAdjR3() != -3) ++bad;
            if (uam7TormentSaveAdjR4() != -4) ++bad;
            if (uam7TormentSaveAdjR5() != -6) ++bad;
            if (uam7TormentSaveAdjR6() != -8) ++bad;
            if (!uam7TormentFailingSaveMeansAgreement()) ++bad;
            if (uam7TormentNoPenaltyAfterRound() != 8) ++bad;
            if (!uam7TormentRoundEightWordingFlagged()) ++bad;
            if (uam7TormentInitiativePenaltyPerTwoRounds() != 1) ++bad;
            if (uam7TormentInitiativePenaltyMax() != 4) ++bad;
            if (uam7TormentInitiativeMaxAtRound() != 8) ++bad;
            if (uam7TormentHitDamagePenaltyAfterRound() != 3) ++bad;
            if (uam7TormentHitDamagePenaltyMin() != 1) ++bad;
            if (uam7TormentHitDamagePenaltyMax() != 4) ++bad;
            if (uam7TormentHitDamageMaxAtRound() != 6) ++bad;
            if (uam7TormentHitDamageMinAgainAtRound() != 9) ++bad;
            if (!uam7TormentIntelligentSubmits()) ++bad;
            if (!uam7TormentServiceToTheLetter()) ++bad;
            if (!uam7TormentRevengeSought()) ++bad;
            if (!uam7TormentRequiresNameInscribed()) ++bad;
            if (!uam7TormentCasterSelfIdentification()) ++bad;
            if (!uam7TormentIntelligenceClauseScrambled()) ++bad;

        // U7: truename
            if (strcmp(uam7TruenameName(),
                "Truename (Enchantment/Alteration)") != 0) ++bad;
            if (uam7TruenameLevel() != 7) ++bad;
            if (uam7TruenameRangeInches() != 3) ++bad;
            if (!uam7TruenameDurationSpecial()) ++bad;
            if (!uam7TruenameAoeThingNamed()) ++bad;
            if (!uam7TruenameStatTailInterleaved()) ++bad;
            if (!uam7TruenameComponentsVSM()) ++bad;
            if (uam7TruenameCastingTimeSegments() != 1) ++bad;
            if (!uam7TruenameSaveCellLost()) ++bad;
            if (!uam7TruenameTrueNamesHardToLearn()) ++bad;
            if (uam7TruenameRecitationSegments() != 3) ++bad;
            if (uam7TruenameSuggestionMin() != 1) ++bad;
            if (uam7TruenameSuggestionMax() != 4) ++bad;
            if (uam7TruenameSuggestionSecondsPerEach() != 1) ++bad;
            if (!uam7TruenameSuggestionAsSuggestionSpell()) ++bad;
            if (uam7TruenameWeaknessPerSegment() != 1) ++bad;
            if (!uam7TruenameWeaknessSaveParalyzation()) ++bad;
            if (uam7TruenameStrengthRecoveryRoundsMin() != 2) ++bad;
            if (uam7TruenameStrengthRecoveryRoundsMax() != 8) ++bad;
            if (!uam7TruenamePolymorphAsAnyObject()) ++bad;
            if (!uam7TruenamePolymorphNoSystemShock()) ++bad;
            if (uam7TruenamePolyVersesMineralToAnimal() != 10) ++bad;
            if (uam7TruenamePolyVersesMineralToVegetable() != 9) ++bad;
            if (uam7TruenamePolyVersesVegetableToAnimal() != 8) ++bad;
            if (uam7TruenamePolyVersesMonsterToNormal() != 7) ++bad;
            if (uam7TruenamePolyVersesMonsterToMonster() != 6) ++bad;
            if (uam7TruenamePolyVersesOtherToHuman() != 5) ++bad;
            if (uam7TruenamePolyVersesAnimalToAnimal() != 4) ++bad;
            if (uam7TruenamePolyVersesVegetableToVegetable() != 3) ++bad;
            if (uam7TruenamePolyVersesMineralToMineral() != 2) ++bad;
            if (!uam7TruenamePolyReverseHolds()) ++bad;
            if (!uam7TruenamePolyDmClosestCase()) ++bad;
            if (uam7TruenamePolyDurationTurnsPerLevel() != 6) ++bad;
            if (uam7TruenamePolyTurnsOffPerVerse() != 1) ++bad;
            if (!uam7TruenamePolyKeepsOriginalHp()) ++bad;
            if (!uam7TruenameTransportTeleportsWithoutError()) ++bad;
            if (uam7TruenameTransportVerses100Miles() != 4) ++bad;
            if (uam7TruenameTransportVerses500Miles() != 5) ++bad;
            if (uam7TruenameTransportVerses2000Miles() != 6) ++bad;
            if (!uam7TruenameTransportListTruncated()) ++bad;

        // U8: volley
            if (strcmp(uam7VolleyName(),
                "Volley (Abjuration)") != 0) ++bad;
            if (uam7VolleyLevel() != 7) ++bad;
            if (!uam7VolleyRangeSpecial()) ++bad;
            if (!uam7VolleyDurationSpecial()) ++bad;
            if (!uam7VolleyAoeSpecial()) ++bad;
            if (!uam7VolleyExplanationLineLost()) ++bad;
            if (!uam7VolleyStatTailScrambled()) ++bad;
            if (!uam7VolleyComponentsCellLost()) ++bad;
            if (!uam7VolleyCastingTimeCellLost()) ++bad;
            if (!uam7VolleySaveCellLost()) ++bad;
            if (!uam7VolleyTurnsCastingBackOnSender()) ++bad;
            if (!uam7VolleyStatsDependOnCircumstance()) ++bad;
            if (!uam7VolleyPowerWordKillExample()) ++bad;
            if (!uam7VolleyBounceRequiresSaveVsSpell()) ++bad;
            if (!uam7VolleySentBackUntilSaveFails()) ++bad;
            if (!uam7VolleyCountsHalfExchangePerVolley()) ++bad;
            if (!uam7VolleyFirstLevelDissipatesExample()) ++bad;
            if (!uam7VolleySecondLevelFourPortions()) ++bad;
            if (!uam7VolleyProseTailScrambled()) ++bad;
            if (!uam7VolleyMaterialWillowWood()) ++bad;
            if (!uam7VolleyMaterialGutStrands()) ++bad;
            if (!uam7VolleyPrintsPastEighthTablePage()) ++bad;

        // the R785 seam repair (the table now
        // carries the R361 names; the absent-name
        // loop reverses)
        if (uas2Mu7thCount() != 16) ++bad;
        if (strcmp(uas2Mu7thName(0),
                "Banishment") != 0)
            ++bad;
        if (strcmp(uas2Mu7thName(4),
                "Forcecage") != 0)
            ++bad;
        if (strcmp(uas2Mu7thName(8),
                "Mordenkainen's Magnificent Mansion")
                != 0)
            ++bad;
        if (strcmp(uas2Mu7thName(10),
                "Sequester") != 0)
            ++bad;
        if (strcmp(uas2Mu7thName(11),
                "Teleport Without Error") != 0)
            ++bad;
        if (strcmp(uas2Mu7thName(12),
                "Torment") != 0) ++bad;
        if (strcmp(uas2Mu7thName(13),
                "Truename") != 0) ++bad;
        if (strcmp(uas2Mu7thName(15),
                "Volley") != 0) ++bad;
        // the R342 fragment reads re-seat
        if (strcmp(uas2Mu7thName(1),
                "Charm Plants") != 0)
            ++bad;
        // the Invisible Stalker fragment re-seats
        // down a column (a 6th-level cell)
        if (strcmp(uas2Mu6thName(8),
                "Invisible Stalker") != 0)
            ++bad;
        if (strcmp(uas2Mu7thName(3),
                "Drawmij's Instant Summons") != 0)
            ++bad;
        if (strcmp(uas2Mu7thName(5),
                "Legend Lore") != 0) ++bad;
        if (strcmp(uas2Mu7thName(6),
                "Limited Wish") != 0)
            ++bad;
        if (strcmp(uas2Mu7thName(7),
                "Monster Summoning V") != 0)
            ++bad;
        if (strcmp(uas2Mu7thName(9),
                "Reverse Gravity") != 0)
            ++bad;
        printf("R361 UA MU 7th level spells pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
