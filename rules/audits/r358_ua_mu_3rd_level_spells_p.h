    // ---- R358: the UA new magic-user 3rd level spells pin audit ----
    // The UA NEW MAGIC-USER SPELLS (pp.
    // 51-66), the 3rd level - cloudburst
    // (the R352 druid seam minus the
    // holy symbol, the 3 diam. print
    // flagged against the druid 4),
    // detect illusion behind the lost
    // name tail, item, material
    // behind the degree range, the
    // Melf minute meteors behind the
    // empty range, secret page
    // behind the 4th-heading
    // interleave, the sepia snake
    // sigil behind the lost
    // casting-time head, wind wall.
    // The family decodes the 7s as 1.
    // The R342 table seam pins 4 of 8;
    // the item stays open (the
    // 4th-9th levels).
    {
        using namespace rules;
        int bad = 0;
        // U1: cloudburst
            if (strcmp(uam3CloudburstName(),
                "Cloudburst (Alteration)") != 0) ++bad;
            if (uam3CloudburstLevel() != 3) ++bad;
            if (!uam3CloudburstComponentsVSM()) ++bad;
            if (uam3CloudburstRangeInchesPerLevel() != 1) ++bad;
            if (!uam3CloudburstCastingTimeNumberLost()) ++bad;
            if (!uam3CloudburstCastingTimeUnitSegments()) ++bad;
            if (!uam3CloudburstStatBlockScrambled()) ++bad;
            if (!uam3CloudburstSaveNoneAndSpecial()) ++bad;
            if (!uam3CloudburstSaveCellTruncated()) ++bad;
            if (uam3CloudburstDurationRoundsPerLevel() != 1) ++bad;
            if (uam3CloudburstCylinderDiameterInches() != 3) ++bad;
            if (!uam3CloudburstDiameterDisagreesWithDruidSeam()) ++bad;
            if (uam3CloudburstCylinderHeightInches() != 6) ++bad;
            if (!uam3CloudburstIdenticalToClerical3rd()) ++bad;
            if (!uam3CloudburstNoHolySymbolComponent()) ++bad;
            // the R352 druid seam, cell by cell
            if (uad3CloudburstDurationRoundsPerLevel()
                != uam3CloudburstDurationRoundsPerLevel())
                ++bad;
            if (uad3CloudburstCylinderHeightInches()
                != uam3CloudburstCylinderHeightInches())
                ++bad;
            if (uad3CloudburstComponentsVSM()
                != uam3CloudburstComponentsVSM()) ++bad;
            if (uad3CloudburstSaveNoneAndSpecial()
                != uam3CloudburstSaveNoneAndSpecial())
                ++bad;
            // the range cell the druid block lost
            if (!uad3CloudburstRangeLost()) ++bad;
            if (uad3CloudburstCastingTimeSegments() != 5)
                ++bad;
            // the 3 vs 4 diameter disagreement
            if (uad3CloudburstCylinderDiameterInches()
                != 4) ++bad;
        // U2: detect illusion
            if (strcmp(uam3DetectName(),
                "Detect Illusion (Divination)") != 0) ++bad;
            if (!uam3DetectNameHeaderTailLost()) ++bad;
            if (uam3DetectLevel() != 3) ++bad;
            if (!uam3DetectComponentsVSM()) ++bad;
            if (uam3DetectCastingTimeSegments() != 3) ++bad;
            if (!uam3DetectRangeTouch()) ++bad;
            if (!uam3DetectSaveNone()) ++bad;
            if (uam3DetectDurationRoundsMin() != 2) ++bad;
            if (uam3DetectDurationRoundsPerLevel() != 1) ++bad;
            if (!uam3DetectAoeLineOfSightOneInchWide()) ++bad;
            if (!uam3DetectAoeLengthLost()) ++bad;
            if (!uam3DetectSameAsIllusionist1st()) ++bad;
            if (!uam3DetectExceptAsNotedTruncated()) ++bad;
        // U3: item
            if (strcmp(uam3ItemName(), "Item (Alteration)") != 0) ++bad;
            if (uam3ItemLevel() != 3) ++bad;
            if (!uam3ItemRangeTouch()) ++bad;
            if (uam3ItemDurationTurnsPerLevel() != 6) ++bad;
            if (!uam3ItemDurationQuadrupledNonLiving()) ++bad;
            if (uam3ItemAoeCuFtPerLevel() != 2) ++bad;
            if (!uam3ItemShrinksToOneTwelfth()) ++bad;
            if (!uam3ItemClothCompositionOption()) ++bad;
            if (!uam3ItemLivingEntitledToSave()) ++bad;
            if (uam3ItemLivingSavePlus4() != 4) ++bad;
            if (!uam3ItemClothSavesNormally()) ++bad;
            if (!uam3ItemReturnsOnTossOrCommand()) ++bad;
            if (!uam3ItemCanAffectFireAndFuel()) ++bad;
            if (!uam3ItemComponentsV()) ++bad;
            if (!uam3ItemComponentsM()) ++bad;
            if (!uam3ItemComponentsCellSplit()) ++bad;
            if (uam3ItemCastingTimeSegments() != 3) ++bad;
            if (!uam3ItemSaveSpecial()) ++bad;
        // U4: material
            if (strcmp(uam3MaterialName(),
                "Material (Evocation-Conjuration)") != 0) ++bad;
            if (uam3MaterialLevel() != 3) ++bad;
            if (!uam3MaterialComponentsV()) ++bad;
            if (!uam3MaterialComponentsCellGarbled()) ++bad;
            if (uam3MaterialCastingTimeRounds() != 1) ++bad;
            if (!uam3MaterialRangePrintsDegrees()) ++bad;
            if (uam3MaterialRangeDecodedOne() != 1) ++bad;
            if (!uam3MaterialSaveNone()) ++bad;
            if (!uam3MaterialDurationPermanent()) ++bad;
            if (uam3MaterialAoeCuFtPerLevel() != 7) ++bad;
            if (!uam3MaterialProseHeadScrambled()) ++bad;
            if (!uam3MaterialCommonStoneEarthWood()) ++bad;
            if (!uam3MaterialInorganicNonLivingEtc()) ++bad;
            if (uam3MaterialGrassBaseFailurePct() != 100) ++bad;
            if (!uam3MaterialGrassFailureMinusOnePctPerLevel()) ++bad;
            if (!uam3MaterialAnimalLifeNever()) ++bad;
            if (!uam3MaterialNoWorkedRefinedFabricated()) ++bad;
            if (!uam3MaterialNoRoughGemsOrPreciousMetals()) ++bad;
            if (!uam3MaterialCreatesCommonBasicThings()) ++bad;
        // U5: the Melf minute meteors
            if (strcmp(uam3MeteorsName(),
                "Melf's Minute Meteors (Evocation/Alteration)") != 0) ++bad;
            if (uam3MeteorsLevel() != 3) ++bad;
            if (!uam3MeteorsComponentsVSM()) ++bad;
            if (uam3MeteorsCastingTimeSegments() != 5) ++bad;
            if (!uam3MeteorsRangeCellEmpty()) ++bad;
            if (!uam3MeteorsDurationSpecial()) ++bad;
            if (!uam3MeteorsSaveNone()) ++bad;
            if (!uam3MeteorsAoeOneTargetPerMissile()) ++bad;
            if (uam3MeteorsBurstDiameterFeet() != 1) ++bad;
            if (uam3MeteorsDamageMin() != 1) ++bad;
            if (uam3MeteorsDamageMax() != 4) ++bad;
            if (!uam3MeteorsIgnitesCombustibles()) ++bad;
            if (!uam3MeteorsMissileWeapons()) ++bad;
            if (!uam3MeteorsMissesGrenadeLike()) ++bad;
            if (!uam3MeteorsOnePerLevelOfExperience()) ++bad;
            if (!uam3MeteorsDispelMagicEnds()) ++bad;
            if (!uam3MeteorsFireRateSentenceScrambled()) ++bad;
            if (!uam3MeteorsTwoRateOptions()) ++bad;
            if (!uam3MeteorsRateOneEvery2Segments()) ++bad;
            if (!uam3MeteorsRateOneEveryRound()) ++bad;
            if (!uam3MeteorsRateChoiceCannotSwitch()) ++bad;
            if (!uam3MeteorsRateOnePointEvery2Segments()) ++bad;
            if (!uam3MeteorsCarriesIntoFollowingRound()) ++bad;
            if (!uam3MeteorsRateTwoWithholdPerRound()) ++bad;
            if (!uam3MeteorsRateTwoSpellSameRound()) ++bad;
            if (!uam3MeteorsRateTwoNoConcentration()) ++bad;
            if (!uam3MeteorsLoseRemainderOnLostCount()) ++bad;
            if (!uam3MeteorsMaterialNitreSulphurPineTarBead()) ++bad;
            if (!uam3MeteorsMaterialGoldTube()) ++bad;
            if (uam3MeteorsTubeCostGpMin() != 1000) ++bad;
            if (!uam3MeteorsTubeReusableUnlessDamaged()) ++bad;
            if (!uam3MeteorsSepiaTailInterleaved()) ++bad;
        // U6: secret page
            if (strcmp(uam3SecretPageName(),
                "Secret Page (Alteration)") != 0) ++bad;
            if (!uam3SecretPageUnderFourthHeading()) ++bad;
            if (!uam3SecretPageStatInterleavedWithDispelIllusion()) ++bad;
            if (uam3SecretPageLevel() != 3) ++bad;
            if (!uam3SecretPageComponentsVSM()) ++bad;
            if (uam3SecretPageCastingTimeTurns() != 1) ++bad;
            if (!uam3SecretPageRangeTouch()) ++bad;
            if (!uam3SecretPageDurationUntilDispelled()) ++bad;
            if (!uam3SecretPageSaveNone()) ++bad;
            if (uam3SecretPageAoeMaxFt() != 2) ++bad;
            if (!uam3SecretPageAoeOnePageUpTo2FtSquare()) ++bad;
            if (!uam3SecretPageAltersContents()) ++bad;
            if (!uam3SecretPageMapToTreatiseExample()) ++bad;
            if (!uam3SecretPageRunesAllowed()) ++bad;
            if (!uam3SecretPageComprehendLanguagesFails()) ++bad;
            if (!uam3SecretPageReversedByCommandWord()) ++bad;
            if (!uam3SecretPageRemovedByDoubleCommand()) ++bad;
            if (!uam3SecretPageFailedDispelDestroysPage()) ++bad;
            if (!uam3SecretPageEssenceReveals()) ++bad;
            if (!uam3SecretPageMaterialHerringScales()) ++bad;
        // U7: the sepia snake sigil
            if (strcmp(uam3SepiaName(),
                "Sepia Snake Sigil (Conjuration/Summoning)") != 0) ++bad;
            if (!uam3SepiaBodyPrintsInFourthRegion()) ++bad;
            if (uam3SepiaLevel() != 3) ++bad;
            if (!uam3SepiaComponentsVSM()) ++bad;
            if (uam3SepiaRangeInches() != 2) ++bad;
            if (!uam3SepiaRangePrintsQuotedTwo()) ++bad;
            if (!uam3SepiaDurationSpecial()) ++bad;
            if (!uam3SepiaAoeOneSigil()) ++bad;
            if (!uam3SepiaCastingTimeHeadLost()) ++bad;
            if (uam3SepiaCastingTimeSegments() != 3) ++bad;
            if (!uam3SepiaSaveNone()) ++bad;
            if (!uam3SepiaThreeForms()) ++bad;
            if (!uam3SepiaStrikesNearestLiving()) ++bad;
            if (!uam3SepiaNeverAttacksCaster()) ++bad;
            if (!uam3SepiaAttackHdPerLevel()) ++bad;
            if (!uam3SepiaEngulfsOnStrike()) ++bad;
            if (!uam3SepiaAmberFieldOfForce()) ++bad;
            if (!uam3SepiaFrozenUntilReleaseOrDispel()) ++bad;
            if (!uam3SepiaNothingCanAffect()) ++bad;
            if (!uam3SepiaNoAgeHungerSleepOrSpells()) ++bad;
            if (!uam3SepiaMissDissipatesBrownFlash()) ++bad;
            if (uam3SepiaMissSmokeInches() != 1) ++bad;
            if (uam3SepiaMissSmokeRounds() != 1) ++bad;
            if (!uam3SepiaApplicationAirSigil()) ++bad;
            if (!uam3SepiaApplicationGlyphUmber()) ++bad;
            if (!uam3SepiaApplicationWrittenIntoWork()) ++bad;
            if (uam3SepiaMaterialAmberGp() != 100) ++bad;
            if (!uam3SepiaMaterialSnakeScale()) ++bad;
            if (!uam3SepiaMaterialMushroomSpores()) ++bad;
        // U8: wind wall
            if (strcmp(uam3WindWallName(),
                "Wind Wall (Alteration)") != 0) ++bad;
            if (uam3WindWallLevel() != 3) ++bad;
            if (!uam3WindWallComponentsCellTruncated()) ++bad;
            if (!uam3WindWallMaterialTinyFanAndExoticFeather()) ++bad;
            if (uam3WindWallRangeInchesPerLevel() != 1) ++bad;
            if (uam3WindWallCastingTimeSegments() != 3) ++bad;
            if (!uam3WindWallCastingTimeUnitLost()) ++bad;
            if (!uam3WindWallSaveSpecial()) ++bad;
            if (uam3WindWallDurationRoundsPerLevel() != 1) ++bad;
            if (uam3WindWallAoeInchesPerLevel() != 1) ++bad;
            if (!uam3WindWallAoeWideAndHigh()) ++bad;
            if (!uam3WindWallInvisibleCurtain()) ++bad;
            if (!uam3WindWallBlowsBirdsUpToCrows()) ++bad;
            if (!uam3WindWallTearsPapersFromHands()) ++bad;
            if (!uam3WindWallSaveToMaintainGrasp()) ++bad;
            if (!uam3WindWallNormalInsectsCannotPass()) ++bad;
            if (!uam3WindWallLooseMaterialFliesUpward()) ++bad;
        // the R342 table seam (4 of 8 names)
        if (uas2Mu3rdCount() != 28) ++bad;
        if (strcmp(uas2Mu3rdName(16),
                "Melf's Minute Meteor") != 0) ++bad;
        if (strcmp(uas2Mu3rdName(21),
                "Secret Page") != 0) ++bad;
        if (strcmp(uas2Mu3rdName(22),
                "Sepia Snake Sigil") != 0) ++bad;
        if (strcmp(uas2Mu3rdName(27),
                "Wind Wall") != 0) ++bad;
        // the four names absent from the seam
        for (int i = 0; i < 28; ++i) {
            const char* n = uas2Mu3rdName(i);
            if (strcmp(n, "Cloudburst") == 0) ++bad;
            if (strcmp(n, "Detect Illusion") == 0)
                ++bad;
            if (strcmp(n, "Item") == 0) ++bad;
            if (strcmp(n, "Material") == 0) ++bad;
        }
        printf("R358 UA MU 3rd level spells pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
