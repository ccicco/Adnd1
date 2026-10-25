    // ---- R362: the UA new magic-user 8th and 9th
    // level spells pin audit ----
    // The UA NEW MAGIC-USER SPELLS (pp.
    // 71-77), the 8th and 9th levels -
    // binding behind the lost range and
    // duration cells, demand behind the
    // garbled components cell, the
    // Otiluke telekinetic sphere behind
    // the garbled name header, sink
    // behind the lost level cell;
    // crystalbrittle with the item save
    // ladder, succor with the
    // interleaved stat tail, energy
    // drain with the displaced casting
    // cell, the Mordenkainen
    // disjunction behind the garbled
    // name header. The R342 seam
    // checks demand at index 0 and
    // sink at index 8; only the two
    // PHB 9th names print. The item
    // CLOSES with this round.
    {
        using namespace rules;
        int bad = 0;
        // U1: binding
            if (strcmp(uam8BindName(),
                "Binding (Enchantment - Evocation)") != 0) ++bad;
            if (!uam8BindComponentsVSM()) ++bad;
            if (!uam8BindLevelCellLost()) ++bad;
            if (uam8BindLevel() != 8) ++bad;
            if (!uam8BindRangeCellLost()) ++bad;
            if (!uam8BindCastingTimeSpecial()) ++bad;
            if (!uam8BindDurationCellLost()) ++bad;
            if (!uam8BindSaveSpecial()) ++bad;
            if (!uam8BindAoeOneCreature()) ++bad;
            if (!uam8BindCapturesLowerPlanesCreature()) ++bad;
            if (!uam8BindRequiresRestrainingDiagram()) ++bad;
            if (!uam8BindContinuousChantFromScroll()) ++bad;
            if (!uam8BindGesturesMatchTheForm()) ++bad;
            if (!uam8BindChainIronSilverNickel()) ++bad;
            if (!uam8BindMaterialSoporificHerbs()) ++bad;
            if (uam8BindGemGpPerHitDie() != 1000) ++bad;
            if (!uam8BindMaterialVellumOrStatuette()) ++bad;
            if (uam8BindNoSaveCasterLevelMultiple() != 2) ++bad;
            if (!uam8BindSaveModifiedByFormAndRatio()) ++bad;
            if (!uam8BindAssistantNinthPlusThird()) ++bad;
            if (!uam8BindAssistantFourthToEighthOne()) ++bad;
            if (uam8BindAssistantMax() != 6) ++bad;
            if (uam8BindChainingYearsPerLevel() != 1) ++bad;
            if (!uam8BindChainingAntipathy()) ++bad;
            if (!uam8BindChainingStaysInDiagram()) ++bad;
            if (uam8BindSlumberYearsPerLevel() != 1) ++bad;
            if (uam8BindBoundSlumberMonthsPerLevel() != 1) ++bad;
            if (!uam8BindHedgedPrisonUntilBroken()) ++bad;
            if (!uam8BindMetamorphosisNoncorporeal()) ++bad;
            if (!uam8BindMetamorphosisUntilPrescribedAct()) ++bad;
            if (uam8BindMinimusHeightInches() != 1) ++bad;
            if (!uam8BindMinimusHeldInGem()) ++bad;
            if (!uam8BindFormsRadiateFaintAura()) ++bad;
            if (uam8BindSaveAdjChaining() != 0) ++bad;
            if (uam8BindSaveAdjSlumber() != 1) ++bad;
            if (uam8BindSaveAdjBoundSlumber() != 2) ++bad;
            if (uam8BindSaveAdjHedgedPrison() != 3) ++bad;
            if (uam8BindSaveAdjMetamorphosis() != 4) ++bad;
            if (uam8BindSaveAdjMinimus() != 5) ++bad;
            if (uam8BindAdjDolor() != -1) ++bad;
            if (uam8BindAdjTorment() != -2) ++bad;
            if (uam8BindAdjBoth() != -4) ++bad;
            if (!uam8BindSaveSuccessBurstsBonds()) ++bad;
            if (!uam8BindFirstThreeRenewable()) ++bad;
            if (uam8BindRenewalSaveAfterYears() != 1) ++bad;
            if (!uam8BindWeakenedRenewalNormalSave()) ++bad;

        // U2: demand
            if (strcmp(uam8DemandName(),
                "Demand (Evocation - Enchantment/Charm)") != 0) ++bad;
            if (!uam8DemandComponentsCellGarbled()) ++bad;
            if (!uam8DemandComponentsVSM()) ++bad;
            if (uam8DemandLevel() != 8) ++bad;
            if (!uam8DemandRangeSpecial()) ++bad;
            if (uam8DemandCastingTimeTurns() != 1) ++bad;
            if (!uam8DemandDurationSpecial()) ++bad;
            if (!uam8DemandSaveSpecial()) ++bad;
            if (!uam8DemandAoeOneCreature()) ++bad;
            if (!uam8DemandSameAsSending()) ++bad;
            if (!uam8DemandCarriesSuggestion()) ++bad;
            if (!uam8DemandFailedSaveCarriesOut()) ++bad;
            if (!uam8DemandImpossibleNoSave()) ++bad;
            if (!uam8DemandMaterialCopperWire()) ++bad;
            if (!uam8DemandMaterialSubjectPart()) ++bad;
            if (!uam8DemandMaterialListScrambled()) ++bad;

        // U3: the Otiluke telekinetic sphere
            if (strcmp(uam8OtilukeName(),
                "Otiluke's Telekinetic Sphere") != 0) ++bad;
            if (!uam8OtilukeNameHeaderGarbled()) ++bad;
            if (!uam8OtilukeSchoolLost()) ++bad;
            if (uam8OtilukeLevel() != 8) ++bad;
            if (!uam8OtilukeRangeCellLost()) ++bad;
            if (uam8OtilukeCastingTimeSegments() != 4) ++bad;
            if (!uam8OtilukeSaveNeg()) ++bad;
            if (uam8OtilukeDurationRoundsPerLevel() != 1) ++bad;
            if (!uam8OtilukeAoeFeetPerLevel()) ++bad;
            if (!uam8OtilukeSameAsResilientSphere()) ++bad;
            if (!uam8OtilukeInteriorWeightless()) ++bad;
            if (!uam8OtilukeWeightFractionGarbled()) ++bad;
            if (uam8OtilukeLiftPoundsMax() != 5000) ++bad;
            if (!uam8OtilukeRolledWithoutEffort()) ++bad;
            if (!uam8OtilukeControlRangeNumberLost()) ++bad;
            if (!uam8OtilukeControlPerLevel()) ++bad;
            if (!uam8OtilukeFallingHarmless()) ++bad;
            if (!uam8OtilukeVanishHighDangerous()) ++bad;
            if (!uam8OtilukeMaterialBarMagnets()) ++bad;

        // U4: sink
            if (strcmp(uam8SinkName(),
                "Sink (Enchantment - Alteration)") != 0) ++bad;
            if (!uam8SinkLevelCellLost()) ++bad;
            if (uam8SinkLevel() != 8) ++bad;
            if (uam8SinkChantSegments() != 4) ++bad;
            if (uam8SinkCastingTimeSegments() != 8) ++bad;
            if (!uam8SinkDurationSpecial()) ++bad;
            if (!uam8SinkSaveSpecial()) ++bad;
            if (!uam8SinkAoeOneCreatureOrObject()) ++bad;
            if (uam8SinkAoeCuFtPerLevel() != 1) ++bad;
            if (!uam8SinkAoeUnitGarbled()) ++bad;
            if (!uam8SinkRootsUnlessSave()) ++bad;
            if (!uam8SinkCreatureSaveVsSpell()) ++bad;
            if (!uam8SinkMagicObjectSaveVsDisintegration()) ++bad;
            if (!uam8SinkMagicalPropertiesDefined()) ++bad;
            if (!uam8SinkNonMagicNoSave()) ++bad;
            if (!uam8SinkSameDensityAsSurface()) ++bad;
            if (uam8SinkCeaseTurns() != 4) ++bad;
            if (uam8SinkSinkingStartSegment() != 5) ++bad;
            if (uam8SinkSinkingQuarterPerSegment() != 1) ++bad;
            if (uam8SinkTotallySunkenSegment() != 8) ++bad;
            if (!uam8SinkLivingStasisUnharmed()) ++bad;
            if (!uam8SinkNonLivingUndamaged()) ++bad;
            if (!uam8SinkDepthEqualsHeight()) ++bad;
            if (!uam8SinkGroundRemovalBreaks()) ++bad;
            if (!uam8SinkRecoverySpellsHelpful()) ++bad;
            if (!uam8SinkDetectMagicFaintDweomer()) ++bad;
            if (!uam8SinkDetectNotesEnchantAlteration()) ++bad;

        // U5: crystalbrittle
            if (strcmp(uam9CrystalName(),
                "Crystalbrittle (Alteration)") != 0) ++bad;
            if (!uam9CrystalComponentsVSM()) ++bad;
            if (!uam9CrystalComponentsCellGarbled()) ++bad;
            if (uam9CrystalLevel() != 9) ++bad;
            if (uam9CrystalCastingTimeSegments() != 9) ++bad;
            if (!uam9CrystalCastingHeadLost()) ++bad;
            if (!uam9CrystalRangeTouch()) ++bad;
            if (!uam9CrystalDurationPermanent()) ++bad;
            if (!uam9CrystalSaveSpecial()) ++bad;
            if (uam9CrystalAoeCuFtPerLevel() != 2) ++bad;
            if (!uam9CrystalTurnsMetalToCrystal()) ++bad;
            if (!uam9CrystalShattersByBlow()) ++bad;
            if (!uam9CrystalReversibleOnlyByWish()) ++bad;
            if (!uam9CrystalTouchRequiresHit()) ++bad;
            if (!uam9CrystalSingleItemPerCasting()) ++bad;
            if (uam9CrystalSwordSavePct() != 10) ++bad;
            if (uam9CrystalArmorSavePct() != 25) ++bad;
            if (uam9CrystalGolemSavePct() != 15) ++bad;
            if (uam9CrystalArtifactSavePct() != 95) ++bad;
            if (!uam9CrystalDestroyedByWeightyBlow()) ++bad;

        // U6: succor
            if (strcmp(uam9SuccorName(),
                "Succor (Alteration - Enchantment)") != 0) ++bad;
            if (!uam9SuccorReversible()) ++bad;
            if (!uam9SuccorLevelCellLost()) ++bad;
            if (uam9SuccorLevel() != 9) ++bad;
            if (!uam9SuccorStatTailInterleaved()) ++bad;
            if (!uam9SuccorComponentsVSM()) ++bad;
            if (uam9SuccorCastingTimeDaysMin() != 1) ++bad;
            if (uam9SuccorCastingTimeDaysMax() != 4) ++bad;
            if (!uam9SuccorCastingPrintGarbled()) ++bad;
            if (!uam9SuccorDurationSpecial()) ++bad;
            if (!uam9SuccorSaveNone()) ++bad;
            if (!uam9SuccorAoeOneIndividual()) ++bad;
            if (!uam9SuccorSameAsClericSeventh()) ++bad;
            if (!uam9SuccorTeleportsWithoutError()) ++bad;
            if (!uam9SuccorReverseBringsArchmage()) ++bad;
            if (!uam9SuccorArchmageHasNoChoice()) ++bad;
            if (!uam9SuccorInterferenceIrrevocableLoss()) ++bad;
            if (!uam9SuccorInterferenceSentenceScrambled()) ++bad;
            if (uam9SuccorGemGpMin() != 5000) ++bad;
            if (!uam9SuccorEnchantedOncePerMonth()) ++bad;
            if (!uam9SuccorSetOnFullMoonNight()) ++bad;
            if (!uam9SuccorSetForTypeAndDestination()) ++bad;

        // U7: energy drain
            if (strcmp(uam9EnergyName(),
                "Energy Drain (Evocation)") != 0) ++bad;
            if (!uam9EnergyComponentsVSM()) ++bad;
            if (uam9EnergyLevel() != 9) ++bad;
            if (uam9EnergyCastingTimeSegments() != 3) ++bad;
            if (!uam9EnergyCastingCellDisplaced()) ++bad;
            if (!uam9EnergyRangeTouch()) ++bad;
            if (!uam9EnergyDurationCellLost()) ++bad;
            if (!uam9EnergySaveCellLost()) ++bad;
            if (!uam9EnergyAoeOneCreature()) ++bad;
            if (!uam9EnergyNegativePlaneChannel()) ++bad;
            if (!uam9EnergyCasterIsConductor()) ++bad;
            if (uam9EnergyLevelsDrained() != 2) ++bad;
            if (!uam9EnergyAsSpectre()) ++bad;
            if (uam9EnergyHitDiceDrained() != 2) ++bad;
            if (!uam9EnergyCharacterLossPermanent()) ++bad;
            if (!uam9EnergyMaterialSpectreOrVampireDust()) ++bad;
            if (!uam9EnergyMaterialWordLost()) ++bad;
            if (!uam9EnergyMaterialSentenceScrambled()) ++bad;
            if (!uam9EnergyTriggeringWord()) ++bad;
            if (uam9EnergyCasterRiskPct() != 5) ++bad;
            if (uam9EnergyCasterRiskLevels() != 1) ++bad;
            if (!uam9EnergyZeroLevelJujuZombies()) ++bad;

        // U8: the Mordenkainen disjunction
            if (strcmp(uam9DisjunctionName(),
                "Mordenkainen's Disjunction") != 0) ++bad;
            if (!uam9DisjunctionNameHeaderGarbled()) ++bad;
            if (!uam9DisjunctionSchoolLost()) ++bad;
            if (!uam9DisjunctionComponentsCellLost()) ++bad;
            if (uam9DisjunctionLevel() != 9) ++bad;
            if (uam9DisjunctionRangeZero() != 0) ++bad;
            if (uam9DisjunctionCastingTimeSegments() != 9) ++bad;
            if (!uam9DisjunctionDurationPermanent()) ++bad;
            if (!uam9DisjunctionSaveSpecial()) ++bad;
            if (uam9DisjunctionAoeRadiusInches() != 3) ++bad;
            if (!uam9DisjunctionDisjoinsAllMagic()) ++bad;
            if (!uam9DisjunctionCasterPersonExempt()) ++bad;
            if (!uam9DisjunctionSpoilsSpellsBeingCast()) ++bad;
            if (!uam9DisjunctionItemsSaveOrBecomeNormal()) ++bad;
            if (!uam9DisjunctionItemSaveVsSpellIfCreature()) ++bad;
            if (uam9DisjunctionArtifactPctPerLevel() != 1) ++bad;
            if (!uam9DisjunctionAffectsAllItemClasses()) ++bad;
            if (uam9DisjunctionArtifactAttentionPct() != 95) ++bad;
            if (uam9DisjunctionArtifactDestroySaveAdj() != -4) ++bad;
            if (!uam9DisjunctionCasterMayLoseCasting()) ++bad;

        // the R785 seam repair (the table now
        // carries binding and the telekinetic
        // sphere; the 9th roster repairs; the
        // absent-name loops reverse)
        if (uas2Mu8thCount() != 10) ++bad;
        if (strcmp(uas2Mu8thName(0),
                "Binding") != 0) ++bad;
        if (strcmp(uas2Mu8thName(1),
                "Clone") != 0) ++bad;
        if (strcmp(uas2Mu8thName(2),
                "Demand") != 0) ++bad;
        if (strcmp(uas2Mu8thName(6),
                "Otiluke's Telekinetic Sphere") != 0)
            ++bad;
        if (strcmp(uas2Mu8thName(9),
                "Sink") != 0) ++bad;
        if (uas2Mu9thCount() != 8) ++bad;
        if (strcmp(uas2Mu9thName(0),
                "Crystalbrittle") != 0)
            ++bad;
        if (strcmp(uas2Mu9thName(1),
                "Energy Drain") != 0)
            ++bad;
        if (strcmp(uas2Mu9thName(2), "Gate")
                != 0) ++bad;
        if (strcmp(uas2Mu9thName(3),
                "Mordenkainen's Disjunction") != 0)
            ++bad;
        if (strcmp(uas2Mu9thName(4),
                "Prismatic Sphere") != 0)
            ++bad;
        if (strcmp(uas2Mu9thName(5),
                "Shape Change") != 0) ++bad;
        if (strcmp(uas2Mu9thName(6),
                "Succor") != 0) ++bad;
        if (strcmp(uas2Mu9thName(7), "Wish")
                != 0) ++bad;
        // the R361 teleport exception names
        // this succor - the cross-level link
        if (!uam7TeleportSuccorException() ||
            strcmp(uam9SuccorName(),
                "Succor (Alteration - Enchantment)")
                != 0) ++bad;
        printf("R362 UA MU 8th/9th level spells pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
