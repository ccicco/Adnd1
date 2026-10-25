    // ---- R359: the UA new magic-user 4th level spells pin audit ----
    // The UA NEW MAGIC-USER SPELLS (pp.
    // 51-66), the 4th level - dispel
    // illusion behind the lost name tail
    // and the garbled half-inch range, the
    // Evard black tentacles behind the lost
    // level and range cells, the Leomund
    // secure shelter, magic mirror, the
    // Otiluke resilient sphere, shout with
    // the scrambled area tail, stoneskin
    // behind the lost level and range cells,
    // ultravision. The family decodes the
    // 7s as 1. The R342 table seam pins
    // 7 of 8; the item stays open (the
    // 5th-9th levels).
    {
        using namespace rules;
        int bad = 0;
        // U1: dispel illusion
            if (strcmp(uam4DispelName(),
                "Dispel Illusion (Abjuration)") != 0) ++bad;
            if (!uam4DispelNameHeaderTailLost()) ++bad;
            if (uam4DispelLevel() != 4) ++bad;
            if (!uam4DispelStatInterleavedWithSecretPage()) ++bad;
            if (!uam4DispelComponentsVS()) ++bad;
            if (uam4DispelCastingTimeSegments() != 4) ++bad;
            if (uam4DispelRangeHalfInchesPerLevel() != 1) ++bad;
            if (!uam4DispelRangeFractionGarbled()) ++bad;
            if (!uam4DispelDurationPermanent()) ++bad;
            if (!uam4DispelSaveNone()) ++bad;
            if (!uam4DispelAoeSpecial()) ++bad;
            if (!uam4DispelSameAsIllusionist3rd()) ++bad;
            if (uam4DispelLevelPenaltyVsIllusionist() != 2) ++bad;
        // U2: the Evard black tentacles
            if (strcmp(uam4EvardName(),
                "Evard's Black Tentacles (Conjuration/Summoni"
                "ng)") != 0) ++bad;
            if (uam4EvardLevel() != 4) ++bad;
            if (!uam4EvardLevelCellLost()) ++bad;
            if (!uam4EvardRangeCellLost()) ++bad;
            if (!uam4EvardStrayGfLine()) ++bad;
            if (!uam4EvardComponentsVSM()) ++bad;
            if (uam4EvardCastingTimeSegments() != 8) ++bad;
            if (!uam4EvardSaveNone()) ++bad;
            if (uam4EvardDurationRoundsPerLevel() != 1) ++bad;
            if (uam4EvardAoeSqFtPerLevel() != 30) ++bad;
            if (!uam4EvardSpringsFromAnySurface()) ++bad;
            if (uam4EvardTentacleFeet() != 10) ++bad;
            if (uam4EvardTentacleAc() != 4) ++bad;
            if (!uam4EvardTentacleHpPerCasterLevel()) ++bad;
            if (!uam4EvardOneTentaclePerLevel()) ++bad;
            if (!uam4EvardMultiTargetDieRoll()) ++bad;
            if (uam4EvardDamageOnSaveMin() != 1) ++bad;
            if (uam4EvardDamageOnSaveMax() != 4) ++bad;
            if (uam4EvardDamageOnFailMin() != 2) ++bad;
            if (uam4EvardDamageOnFailMax() != 8) ++bad;
            if (uam4EvardDamageWrappedMin() != 3) ++bad;
            if (uam4EvardDamageWrappedMax() != 12) ++bad;
            if (!uam4EvardMayEntwineObjects()) ++bad;
            if (!uam4EvardContinuesSqueezingDead()) ++bad;
            if (!uam4EvardMaterialOctopusOrSquidTentacle()) ++bad;
        // U3: the Leomund secure shelter
            if (strcmp(uam4ShelterName(),
                "Leomund's Secure Shelter (Alteration - Encha"
                "ntment)") != 0) ++bad;
            if (uam4ShelterLevel() != 4) ++bad;
            if (!uam4ShelterComponentsVSM()) ++bad;
            if (uam4ShelterCastingTimeTurns() != 4) ++bad;
            if (uam4ShelterRangeInches() != 2) ++bad;
            if (!uam4ShelterSaveNone()) ++bad;
            if (uam4ShelterDurationTurnsPerLevel() != 6) ++bad;
            if (uam4ShelterAoeSqFtPerLevel() != 30) ++bad;
            if (!uam4ShelterCottageOfLocalMaterial()) ++bad;
            if (!uam4ShelterFloorLevelCleanDry()) ++bad;
            if (!uam4ShelterDoorWindowsFireplace()) ++bad;
            if (uam4ShelterWindResistanceMph() != 70) ++bad;
            if (!uam4ShelterWindSentenceScrambled()) ++bad;
            if (!uam4ShelterNoHeatingQualities()) ++bad;
            if (!uam4ShelterStrongAsStone()) ++bad;
            if (!uam4ShelterResistsFlamesAsStone()) ++bad;
            if (!uam4ShelterImperviousToNormalMissiles()) ++bad;
            if (!uam4ShelterDoorShuttersWizardLocked()) ++bad;
            if (!uam4ShelterChimneyGrateAndFlue()) ++bad;
            if (!uam4ShelterAlarmProtected()) ++bad;
            if (!uam4ShelterUnseenServant()) ++bad;
            if (uam4ShelterBunksMax() != 8) ++bad;
            if (uam4ShelterChairsMax() != 4) ++bad;
            if (uam4ShelterStoolsMax() != 8) ++bad;
            if (!uam4ShelterTrestleTableAndDesk()) ++bad;
            if (!uam4ShelterMaterialStoneLimeSandWaterWood()) ++bad;
            if (!uam4ShelterMaterialAugmentedByAlarmServant()) ++bad;
        // U4: magic mirror
            if (strcmp(uam4MirrorName(),
                "Magic Mirror (Enchantment - Divination)") != 0) ++bad;
            if (uam4MirrorLevel() != 4) ++bad;
            if (!uam4MirrorComponentsVSM()) ++bad;
            if (uam4MirrorCastingTimeHours() != 1) ++bad;
            if (!uam4MirrorRangeTouch()) ++bad;
            if (!uam4MirrorSaveNone()) ++bad;
            if (uam4MirrorDurationRoundsPerLevel() != 1) ++bad;
            if (!uam4MirrorAoeSpecial()) ++bad;
            if (!uam4MirrorMirrorBecomesScryingDevice()) ++bad;
            if (uam4MirrorSilverCostGpMin() != 1000) ++bad;
            if (!uam4MirrorNotHarmedByCasting()) ++bad;
            if (!uam4MirrorMaterialEyeOfHawkEagleRoc()) ++bad;
            if (!uam4MirrorMaterialZincCopperNitricAcid()) ++bad;
            if (!uam4MirrorComponentListScrambled()) ++bad;
            if (!uam4MirrorCastsThroughComprehend()) ++bad;
            if (!uam4MirrorCastsThroughTonguesInfravisionUltravision())
                ++bad;
            if (uam4MirrorPctPerLevel() != 5) ++bad;
            if (!uam4MirrorDetectSpellsByChance()) ++bad;
            if (!uam4MirrorTargetMayDetectScrying()) ++bad;
            if (uam4MirrorCavalierDetectPct() != 5) ++bad;
            if (uam4MirrorBarbarianDetectPct() != 1) ++bad;
        // U5: the Otiluke resilient sphere
            if (strcmp(uam4OtilukeName(),
                "Otiluke's Resilient Sphere (Alteration - Evo"
                "cation)") != 0) ++bad;
            if (uam4OtilukeLevel() != 4) ++bad;
            if (!uam4OtilukeComponentsVSM()) ++bad;
            if (uam4OtilukeCastingTimeSegments() != 4) ++bad;
            if (uam4OtilukeRangeInches() != 2) ++bad;
            if (!uam4OtilukeSaveNeg()) ++bad;
            if (uam4OtilukeDurationRoundsPerLevel() != 1) ++bad;
            if (uam4OtilukeSphereFeetPerLevel() != 1) ++bad;
            if (!uam4OtilukeProseHeadScrambled()) ++bad;
            if (!uam4OtilukeSubjectFitsWithin()) ++bad;
            if (!uam4OtilukeNotDamagedNormally()) ++bad;
            if (!uam4OtilukeDestroyedByNegationOrDispel()) ++bad;
            if (!uam4OtilukeDestroyedWithoutHarm()) ++bad;
            if (!uam4OtilukeNothingPassesThrough()) ++bad;
            if (!uam4OtilukeSubjectBreathes()) ++bad;
            if (!uam4OtilukeStruggleMovesSphereOnly()) ++bad;
            if (!uam4OtilukeMovableFromOutsideOrWithin()) ++bad;
            if (!uam4OtilukeMaterialDiamondHemisphere()) ++bad;
            if (!uam4OtilukeMaterialGumArabicHemisphere()) ++bad;
        // U6: shout
            if (strcmp(uam4ShoutName(), "Shout (Evocation)") != 0) ++bad;
            if (uam4ShoutLevel() != 4) ++bad;
            if (!uam4ShoutRangeZero()) ++bad;
            if (!uam4ShoutDurationInstantaneous()) ++bad;
            if (uam4ShoutAoeTerminusInches() != 3) ++bad;
            if (!uam4ShoutAoeCellScrambled()) ++bad;
            if (!uam4ShoutConeFromTheMouth()) ++bad;
            if (!uam4ShoutComponentsVM()) ++bad;
            if (!uam4ShoutStatTailInterleaved()) ++bad;
            if (uam4ShoutCastingTimeSegments() != 1) ++bad;
            if (!uam4ShoutSaveNeg()) ++bad;
            if (uam4ShoutDeafenRoundsMin() != 2) ++bad;
            if (uam4ShoutDeafenRoundsMax() != 12) ++bad;
            if (uam4ShoutDamageMin() != 2) ++bad;
            if (uam4ShoutDamageMax() != 12) ++bad;
            if (!uam4ShoutShattersBrittleSubstances()) ++bad;
            if (!uam4ShoutWallOfIceExample()) ++bad;
            if (!uam4ShoutOncePerDay()) ++bad;
            if (!uam4ShoutMaterialHoneyAcidHornCone()) ++bad;
        // U7: stoneskin
            if (strcmp(uam4StoneskinName(),
                "Stoneskin (Alteration)") != 0) ++bad;
            if (uam4StoneskinLevel() != 4) ++bad;
            if (!uam4StoneskinLevelCellLost()) ++bad;
            if (!uam4StoneskinRangeCellLost()) ++bad;
            if (!uam4StoneskinStatTailInterleaved()) ++bad;
            if (!uam4StoneskinComponentsVSM()) ++bad;
            if (uam4StoneskinCastingTimeSegments() != 1) ++bad;
            if (!uam4StoneskinDurationSpecial()) ++bad;
            if (!uam4StoneskinSaveNone()) ++bad;
            if (!uam4StoneskinAoeOneCreature()) ++bad;
            if (!uam4StoneskinImmuneToPhysicalAttacks()) ++bad;
            if (!uam4StoneskinSwordOfSharpnessIneffective()) ++bad;
            if (!uam4StoneskinMagicAttacksNormal()) ++bad;
            if (!uam4StoneskinOneOpponentDispels()) ++bad;
            if (!uam4StoneskinImmuneToThatAttack()) ++bad;
            if (uam4StoneskinSoftWeaponDamageMin() != 1) ++bad;
            if (uam4StoneskinSoftWeaponDamageMax() != 2) ++bad;
            if (!uam4StoneskinSoftWeaponsDoNotDispels()) ++bad;
            if (!uam4StoneskinMaterialGraniteDiamondDust()) ++bad;
        // U8: ultravision
            if (strcmp(uam4UltravisionName(),
                "Ultravision (Alteration)") != 0) ++bad;
            if (uam4UltravisionLevel() != 4) ++bad;
            if (!uam4UltravisionComponentsVSM()) ++bad;
            if (!uam4UltravisionRangeTouch()) ++bad;
            if (uam4UltravisionCastingTimeSegments() != 4) ++bad;
            if (!uam4UltravisionSaveNone()) ++bad;
            if (uam4UltravisionDurationTurnsMin() != 6) ++bad;
            if (uam4UltravisionDurationTurnsPerLevel() != 6) ++bad;
            if (!uam4UltravisionAoeOneCreature()) ++bad;
            if (!uam4UltravisionSeesUltraviolet()) ++bad;
            if (uam4UltravisionClearYards() != 100) ++bad;
            if (uam4UltravisionShadowyYards() != 300) ++bad;
            if (uam4UltravisionDarkNightReductionPct() != 50) ++bad;
            if (uam4UltravisionEarthFeet() != 6) ++bad;
            if (uam4UltravisionStoneFeet() != 3) ++bad;
            if (uam4UltravisionUndergroundRadiusFeet() != 3) ++bad;
            if (!uam4UltravisionUndergroundDimOnly()) ++bad;
            if (!uam4UltravisionEmissionSourceImproves()) ++bad;
            if (!uam4UltravisionNearbyLightSpoils()) ++bad;
            if (uam4UltravisionMaterialAmethystGp() != 500) ++bad;
            if (!uam4UltravisionTailPastFifthHeading()) ++bad;
        // the R342 table seam (7 of 8 names;
        // the Dispel fragment cell is a hole)
        if (uas2Mu4thCount() != 28) ++bad;
        if (strcmp(uas2Mu4thName(5),
                "Evard's Black Tentacles") != 0)
            ++bad;
        if (strcmp(uas2Mu4thName(12),
                "Leomund's Secure Shelter") != 0)
            ++bad;
        if (strcmp(uas2Mu4thName(13),
                "Magic Mirror") != 0) ++bad;
        if (strcmp(uas2Mu4thName(16),
                "Otiluke's Resilient Sphere") != 0)
            ++bad;
        if (strcmp(uas2Mu4thName(22),
                "Shout") != 0) ++bad;
        if (strcmp(uas2Mu4thName(23),
                "Stoneskin") != 0) ++bad;
        if (strcmp(uas2Mu4thName(24),
                "Ultravision") != 0) ++bad;
        // the absent name (the Dispel hole)
        for (int i = 0; i < 28; ++i) {
            const char* n = uas2Mu4thName(i);
            if (strcmp(n, "Dispel Illusion") == 0)
                ++bad;
        }
        printf("R359 UA MU 4th level spells pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
