    // ---- R356: the UA new magic-user 1st level spells pin audit ----
    // The UA NEW MAGIC-USER SPELLS (p. 51),
    // the 1st level - alarm (the lost
    // range cell and the door-value
    // hole), armor, firewater, grease,
    // melt (the run interleave), mount
    // (the level ladder), precipitation
    // (the clerical seam minus the holy
    // symbol), run, taunt (the scrambled
    // opener) and wizard mark. The
    // family decodes the 7s as 1. The
    // item stays open (the 2nd-9th
    // levels).
    {
        using namespace rules;
        int bad = 0;
        // U1: alarm
        {
            if (strcmp(uam1AlarmName(),
                "Alarm (Evocation)") != 0) ++bad;
            // the 7 level-cell family decode
            if (uam1AlarmLevel() != 1) ++bad;
            if (!uam1AlarmLevelGarbleDecoded()) ++bad;
            // the lost range cell
            if (!uam1AlarmRangeCellLost()) ++bad;
            if (uam1AlarmDurationTurnsMin() != 2) ++bad;
            if (uam1AlarmDurationTurnsMax() != 8) ++bad;
            if (uam1AlarmDurationTurnsPerLevel() != 1)
                ++bad;
            if (uam1AlarmAoeSqFtPerLevel() != 20) ++bad;
            if (!uam1AlarmComponentsCellScrambled())
                ++bad;
            if (uam1AlarmCastingTimeRounds() != 1) ++bad;
            if (!uam1AlarmSaveNone()) ++bad;
            // the rat-size trigger gate
            if (!uam1AlarmTriggerLargerThanRat()) ++bad;
            if (uam1AlarmTriggerVolumeHalfCuFt() != 1)
                ++bad;
            if (uam1AlarmTriggerWeightPounds() != 3)
                ++bad;
            if (!uam1AlarmPortalFloorStairsArea()) ++bad;
            // the 60 inch radius
            if (uam1AlarmRadiusInches() != 60) ++bad;
            if (!uam1AlarmDoorValueLost()) ++bad;
            if (uam1AlarmWallReductionDegrees() != 20)
                ++bad;
            if (uam1AlarmSoundSegments() != 1) ++bad;
            // the trigger matrix
            if (!uam1AlarmUndeadNeverTrigger()) ++bad;
            if (!uam1AlarmInvisibleAndPlanarTrigger())
                ++bad;
            if (!uam1AlarmFlyingLevitatingTrigger())
                ++bad;
            // the bell and the silver wire
            if (!uam1AlarmMaterialTinyBell()) ++bad;
            if (!uam1AlarmMaterialFineSilverWire()) ++bad;
        }
        // U2: armor
        {
            if (strcmp(uam1ArmorName(),
                "Armor (Conjuration)") != 0) ++bad;
            if (uam1ArmorLevel() != 1) ++bad;
            if (!uam1ArmorRangeTouch()) ++bad;
            if (!uam1ArmorDurationSpecial()) ++bad;
            if (!uam1ArmorAoeOneCreature()) ++bad;
            if (!uam1ArmorSaveNone()) ++bad;
            // the AC 8 force field
            if (!uam1ArmorCreatesForceFieldAc8()) ++bad;
            if (!uam1ArmorNoEffectIfAlreadyArmored())
                ++bad;
            if (!uam1ArmorBetterThanNineGainsOneStep())
                ++bad;
            if (!uam1ArmorNoWeightOrEncumbrance()) ++bad;
            if (!uam1ArmorDoesNotPreventCasting()) ++bad;
            // the cumulative-damage gate
            if (uam1ArmorDamageThresholdBase() != 8)
                ++bad;
            if (uam1ArmorDamageThresholdPerLevel() != 1)
                ++bad;
            if (uam1ArmorExampleCasterLevelForExceed()
                != 2) ++bad;
            if (!uam1ArmorNoteWordsLost()) ++bad;
            if (!uam1ArmorMaterialBlessedLeather())
                ++bad;
        }
        // U3: mount
        {
            if (strcmp(uam1MountName(),
                "Mount (Conjuration/Summoning)")
                != 0) ++bad;
            // the clean 1 level cell
            if (uam1MountLevel() != 1) ++bad;
            if (uam1MountCastingTimeRounds() != 1) ++bad;
            if (uam1MountDurationTurnsBase() != 12)
                ++bad;
            if (uam1MountDurationTurnsPerLevel() != 6)
                ++bad;
            if (!uam1MountAoeOneCreature()) ++bad;
            if (!uam1MountSaveNone()) ++bad;
            if (!uam1MountServesThenReturns()) ++bad;
            // the mount ladder
            if (uam1MountMuleLightHorseMaxLevel() != 3)
                ++bad;
            if (uam1MountDraftWarhorseMinLevel() != 4)
                ++bad;
            if (uam1MountDraftWarhorseMaxLevel() != 7)
                ++bad;
            if (uam1MountCamelMinLevel() != 8) ++bad;
            if (uam1MountCamelMaxLevel() != 12) ++bad;
            if (uam1MountElephantMinLevel() != 13)
                ++bad;
            if (uam1MountHoudaAtLevel() != 18) ++bad;
            if (!uam1MountLowerLevelChoiceAllowed())
                ++bad;
            if (!uam1MountNoRidingGearUnlessLowerClass())
                ++bad;
            if (!uam1MountStatsTypicalOfClass()) ++bad;
            if (!uam1MountMaterialHairOrDung()) ++bad;
        }
        // U4: firewater
        {
            if (strcmp(uam1FirewaterName(),
                "Firewater (Alteration)") != 0) ++bad;
            if (uam1FirewaterLevel() != 1) ++bad;
            // the clean 1 segment
            if (uam1FirewaterCastingTimeSegments() != 1)
                ++bad;
            if (!uam1FirewaterRangeCellLost()) ++bad;
            if (!uam1FirewaterSaveNone()) ++bad;
            if (!uam1FirewaterVolatileAlcoholLike())
                ++bad;
            if (!uam1FirewaterLighterThanWater()) ++bad;
            if (!uam1FirewaterIgnitesOnSpark()) ++bad;
            if (uam1FirewaterDamageMin() != 2) ++bad;
            if (uam1FirewaterDamageMax() != 12) ++bad;
            // the evaporation clock
            if (uam1FirewaterEvaporatesInRounds() != 1)
                ++bad;
            if (uam1FirewaterIgniteWithinSegments()
                != 10) ++bad;
            if (!uam1FirewaterMaterialSugarGrains())
                ++bad;
            if (!uam1FirewaterMaterialRaisin()) ++bad;
        }
        // U5: grease
        {
            if (strcmp(uam1GreaseName(),
                "Grease (Evocation)") != 0) ++bad;
            if (uam1GreaseLevel() != 1) ++bad;
            if (uam1GreaseCastingTimeSegments() != 1)
                ++bad;
            // the "7"" range family decode
            if (uam1GreaseRangeInches() != 1) ++bad;
            if (!uam1GreaseDurationPermanent()) ++bad;
            if (uam1GreaseAoeSqFtPerLevel() != 1) ++bad;
            if (!uam1GreaseSaveSpecial()) ++bad;
            if (!uam1GreaseSaveVsPetrificationOrFall())
                ++bad;
            if (!uam1GreaseAwareCreatureCanAvoid()) ++bad;
            if (!uam1GreaseCoatsOtherSurfaces()) ++bad;
            if (!uam1GreaseLoneObjectsAlwaysSubject())
                ++bad;
            if (!uam1GreaseWieldedNeedsFailedSave())
                ++bad;
            if (!uam1GreaseSingleSaveNegates()) ++bad;
            if (!uam1GreaseMaterialPorkRindEtc()) ++bad;
        }
        // U6: precipitation - the clerical seam
        {
            if (strcmp(uam1PrecipName(),
                "Precipitation (Alteration)") != 0)
                ++bad;
            if (uam1PrecipLevel() != 1) ++bad;
            if (uam1PrecipCastingTimeSegments() != 1)
                ++bad;
            if (uam1PrecipDurationSegmentsPerLevel()
                != 1) ++bad;
            if (uam1PrecipCylinderDiameterInches() != 3)
                ++bad;
            if (uam1PrecipCylinderHeightInches() != 12)
                ++bad;
            if (!uam1PrecipSaveNoneAndSpecial()) ++bad;
            // the components cell the clerical
            // block lost
            if (!uam1PrecipComponentsVSM()) ++bad;
            if (!uam1PrecipIdenticalToClericalMinusHolySymbol())
                ++bad;
            if (!uam1PrecipNoHolySymbolComponent()) ++bad;
            // the R343 clerical seam, cell by cell
            if (uam1PrecipDurationSegmentsPerLevel()
                != uac1PrecipDurationSegmentsPerLevel())
                ++bad;
            if (uam1PrecipCylinderDiameterInches()
                != uac1PrecipCylinderDiameterInches())
                ++bad;
            if (uam1PrecipCylinderHeightInches()
                != uac1PrecipCylinderHeightInches())
                ++bad;
        }
        // U7: melt
        {
            if (strcmp(uam1MeltName(),
                "Melt (Alteration)") != 0) ++bad;
            if (uam1MeltLevel() != 1) ++bad;
            // the run-interleave range doubt
            if (uam1MeltRangeInches() != 3) ++bad;
            if (!uam1MeltRangeDecodedWithDoubt()) ++bad;
            if (!uam1MeltComponentsPeriodGarble()) ++bad;
            // the 7 cu yd family decode
            if (uam1MeltAoeIceCuYdPerLevel() != 1) ++bad;
            if (uam1MeltAoeSnowCuYdPerLevel() != 2)
                ++bad;
            if (uam1MeltIceInRounds() != 1) ++bad;
            if (!uam1MeltSnowToWaterOneRound()) ++bad;
            if (!uam1MeltAffectsColdCreatures()) ++bad;
            if (uam1MeltDamagePerLevel() != 2) ++bad;
            if (uam1MeltDamagePerLevelOnSave() != 1)
                ++bad;
            if (!uam1MeltIneffectiveAgainstOthers()) ++bad;
            if (!uam1MeltMaterialRockSalt()) ++bad;
            if (!uam1MeltMaterialSootPinch()) ++bad;
        }
        // U8: run
        {
            if (strcmp(uam1RunName(),
                "Run (Enchantment)") != 0) ++bad;
            // the clean 1 level cell
            if (uam1RunLevel() != 1) ++bad;
            if (!uam1RunRangeTouch()) ++bad;
            if (uam1RunDurationHoursMin() != 5) ++bad;
            if (uam1RunDurationHoursMax() != 8) ++bad;
            if (!uam1RunSaveNone()) ++bad;
            if (!uam1RunAoeHumansDemiHumansOnly()) ++bad;
            if (!uam1RunTwiceNormalSpeed()) ++bad;
            if (!uam1RunLikeRestHours()) ++bad;
            if (uam1RunExtraRecipientPer2Levels() != 1)
                ++bad;
            if (!uam1RunNaturalFormsOnly()) ++bad;
            if (!uam1RunBarbariansImmune()) ++bad;
            // the elixir
            if (!uam1RunMaterialPlumElixir()) ++bad;
            if (uam1RunMaterialCastorBeansMin() != 5)
                ++bad;
            if (uam1RunMaterialCastorBeansMax() != 8)
                ++bad;
        }
        // U9: taunt
        {
            if (strcmp(uam1TauntName(),
                "Taunt (Enchantment)") != 0) ++bad;
            // the clean 1 level cell
            if (uam1TauntLevel() != 1) ++bad;
            if (uam1TauntRangeInches() != 3) ++bad;
            if (uam1TauntCastingTimeRounds() != 1) ++bad;
            if (!uam1TauntDurationInstantaneous()) ++bad;
            if (!uam1TauntSaveNegates()) ++bad;
            if (uam1TauntAoeLevelsPerLevel() != 2) ++bad;
            // the scrambled opener
            if (!uam1TauntOpenerGarbleDecoded()) ++bad;
            if (!uam1TauntChallengesAndInsults()) ++bad;
            if (!uam1TauntRushForthInFury()) ++bad;
            if (!uam1TauntAttackMeleePreferred()) ++bad;
            if (!uam1TauntBoundaryBreaksSpell()) ++bad;
            if (!uam1TauntOneSortPerCasting()) ++bad;
            if (!uam1TauntNearestFirst()) ++bad;
            if (uam1TauntLeaderBonusMin() != 1) ++bad;
            if (uam1TauntLeaderBonusMax() != 4) ++bad;
        }
        // U10: wizard mark
        {
            if (strcmp(uam1WizardMarkName(),
                "Wizard Mark (Alteration)") != 0) ++bad;
            if (uam1WizardMarkLevel() != 1) ++bad;
            // the clean 1 segment
            if (uam1WizardMarkCastingTimeSegments() != 1)
                ++bad;
            if (!uam1WizardMarkRangeTouch()) ++bad;
            if (!uam1WizardMarkDurationPermanent()) ++bad;
            if (uam1WizardMarkAoeSqFt() != 1) ++bad;
            if (!uam1WizardMarkSaveNone()) ++bad;
            if (uam1WizardMarkExtraCharacters() != 6)
                ++bad;
            if (!uam1WizardMarkEtchesStoneMetalSofter())
                ++bad;
            if (!uam1WizardMarkDetectMagicGlows()) ++bad;
            if (!uam1WizardMarkDetectionSuiteReveals())
                ++bad;
            if (!uam1WizardMarkReadMagicRevealsIntent())
                ++bad;
            if (!uam1WizardMarkEraseWipes()) ++bad;
            // the diamond dust and pigments
            if (uam1WizardMarkDiamondDustGp() != 50)
                ++bad;
            if (!uam1WizardMarkMaterialPigments()) ++bad;
            if (!uam1WizardMarkInvisibleUsesStylus())
                ++bad;
        }
        printf("R356 UA MU 1st level spells pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
