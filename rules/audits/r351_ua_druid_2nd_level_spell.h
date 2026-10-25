    // ---- R351: the UA new druid 2nd level spells pin audit ----
    // The UA NEW DRUID SPELLS (pp. 43-44),
    // the 2nd level - flame blade (the
    // undead/fire damage modifiers), goodberry
    // (the name header lost), reflecting pool
    // (the "Pool ion -" garble, the scrying
    // mechanics) and slow poison (the herbal
    // antidote chance). The digit-garble family
    // decodes the "7 round" and the two
    // "7 round/level" cells as 1 (flame blade
    // prints the clean 2). The item stays open
    // (the 3rd-7th levels).
    {
        using namespace rules;
        int bad = 0;
        // U1: flame blade
        {
            if (strcmp(uad2FlameBladeName(),
                "Flame Blade (Evocation)") != 0) ++bad;
            if (!uad2FlameBladeComponentsVSM()) ++bad;
            if (uad2FlameBladeLevel() != 2) ++bad;
            if (uad2FlameBladeCastingTimeSegments() != 3)
                ++bad;
            if (uad2FlameBladeRangeInches() != 0) ++bad;
            if (!uad2FlameBladeSaveNone()) ++bad;
            // the "7 round/level" family decode
            if (uad2FlameBladeDurationRoundsPerLevel()
                != 1) ++bad;
            // the "3 long" area cell - the unit
            // lost, position-decoded
            if (uad2FlameBladeBladeLengthFeet() != 3)
                ++bad;
            if (!uad2FlameBladeBladeUnitLost()) ++bad;
            if (!uad2FlameBladeWieldedAsScimitar()) ++bad;
            // the damage 5-8 and the modifiers
            if (uad2FlameBladeDamageMin() != 5) ++bad;
            if (uad2FlameBladeDamageMax() != 8) ++bad;
            if (uad2FlameBladeUndeadOrFireVulnerableBonus()
                != 2) ++bad;
            if (uad2FlameBladeFireDwellerPenalty() != -2)
                ++bad;
            // the interleave decode
            if (!uad2FlameBladeNoDamageOnFireProtected())
                ++bad;
            if (!uad2FlameBladeIgnitesDryMaterials()) ++bad;
            if (!uad2FlameBladeNotMagicalExceptVsUndead())
                ++bad;
            if (!uad2FlameBladeMagicOnlyCreaturesImmuneUnlessUndead())
                ++bad;
            // the material: mistletoe plus the
            // sumac leaf
            if (!uad2FlameBladeMaterialMistletoe()) ++bad;
            if (!uad2FlameBladeMaterialSumacLeaf()) ++bad;
            if (!uad2FlameBladeMaterialInterleaveDecoded())
                ++bad;
        }
        // U2: goodberry
        {
            if (strcmp(uad2GoodberryName(),
                "Goodberry") != 0) ++bad;
            // the name header and school never
            // print - holes
            if (!uad2GoodberryNameHeaderLost()) ++bad;
            if (!uad2GoodberrySchoolLost()) ++bad;
            if (!uad2GoodberryComponentsVSM()) ++bad;
            if (uad2GoodberryLevel() != 2) ++bad;
            // the "7 round" family decode
            if (uad2GoodberryCastingTimeRounds() != 1)
                ++bad;
            if (!uad2GoodberryRangeTouch()) ++bad;
            if (!uad2GoodberrySaveNone()) ++bad;
            // the "1 day + 1/level" duration - the
            // unit lost
            if (uad2GoodberryDurationDaysBase() != 1)
                ++bad;
            if (uad2GoodberryDurationPerLevelAddend() != 1)
                ++bad;
            if (!uad2GoodberryDurationUnitLost()) ++bad;
            if (uad2GoodberryBerriesMin() != 2) ++bad;
            if (uad2GoodberryBerriesMax() != 8) ++bad;
            if (!uad2GoodberryDiscernedByDruid3rdPlus())
                ++bad;
            if (!uad2GoodberryDetectMagicReveals()) ++bad;
            if (!uad2GoodberryNourishAsFullMeal()) ++bad;
            if (uad2GoodberryCurePerBerry() != 1) ++bad;
            if (uad2GoodberryCureMaxPer24h() != 8) ++bad;
            // the badberry reverse
            if (!uad2GoodberryReverseBadberry()) ++bad;
            if (uad2GoodberryBadberryPoisonPoints() != 1)
                ++bad;
            if (!uad2GoodberryBadberryNoSave()) ++bad;
            if (!uad2GoodberryMaterialMistletoe()) ++bad;
            // the example list first item lost
            if (!uad2GoodberryExampleListFirstItemLost())
                ++bad;
        }
        // U3: reflecting pool
        {
            if (strcmp(uad2ReflectingPoolName(),
                "Reflecting Pool") != 0) ++bad;
            // the "Pool ion -" garble
            if (!uad2ReflectingPoolNameHeaderGarbled())
                ++bad;
            if (!uad2ReflectingPoolSchoolLost()) ++bad;
            if (!uad2ReflectingPoolComponentsVSM()) ++bad;
            if (uad2ReflectingPoolLevel() != 2) ++bad;
            if (uad2ReflectingPoolCastingTimeHours() != 2)
                ++bad;
            if (uad2ReflectingPoolRangeInches() != 1) ++bad;
            if (!uad2ReflectingPoolSaveNone()) ++bad;
            // the "7 round/level" family decode
            if (uad2ReflectingPoolDurationRoundsPerLevel()
                != 1) ++bad;
            if (!uad2ReflectingPoolAoeSpecial()) ++bad;
            if (!uad2ReflectingPoolNaturalWaterOnly())
                ++bad;
            if (uad2ReflectingPoolDiameterFeetPerLevel()
                != 2) ++bad;
            if (!uad2ReflectingPoolCrystalBallLike()) ++bad;
            if (!uad2ReflectingPoolMagicMirrorAndFontRef())
                ++bad;
            if (!uad2ReflectingPoolCoexistentPlanesOnly())
                ++bad;
            if (!uad2ReflectingPoolIncludesParaElementalAndShadow())
                ++bad;
            if (!uad2ReflectingPoolCrystalBallPenaltiesApply())
                ++bad;
            // the cast-through mechanics
            if (uad2ReflectingPoolCastThroughChancePctPerLevel()
                != 5) ++bad;
            if (uad2ReflectingPoolCastThroughCount() != 3)
                ++bad;
            if (strcmp(uad2ReflectingPoolCastThroughName(0),
                "Detect Magic") != 0) ++bad;
            if (strcmp(uad2ReflectingPoolCastThroughName(1),
                "Detect Snares and Pits") != 0) ++bad;
            if (strcmp(uad2ReflectingPoolCastThroughName(2),
                "Detect Poison") != 0) ++bad;
            if (!uad2ReflectingPoolInfraAndUltravisionNormal())
                ++bad;
            if (!uad2ReflectingPoolStarshineOperates()) ++bad;
            // the companion spell name lost
            if (!uad2ReflectingPoolCompanionSpellNameLost())
                ++bad;
            // the material: mistletoe plus the
            // nut oil; the measure lost
            if (!uad2ReflectingPoolMaterialMistletoe())
                ++bad;
            if (!uad2ReflectingPoolMaterialNutOil()) ++bad;
            if (!uad2ReflectingPoolMaterialMeasureLost())
                ++bad;
        }
        // U4: slow poison
        {
            if (strcmp(uad2SlowPoisonName(),
                "Slow Poison (Necromantic)") != 0) ++bad;
            if (!uad2SlowPoisonComponentsVSM()) ++bad;
            // the level cell lost - section-
            // certain 2
            if (uad2SlowPoisonLevel() != 2) ++bad;
            // the "ge: Touch" head-lost range
            if (!uad2SlowPoisonRangeTouch()) ++bad;
            if (!uad2SlowPoisonRangeCellHeadLost()) ++bad;
            if (!uad2SlowPoisonSaveNone()) ++bad;
            if (uad2SlowPoisonDurationHoursPerLevel() != 1)
                ++bad;
            if (!uad2SlowPoisonAoeCreatureTouched()) ++bad;
            if (uad2SlowPoisonCastingTimeSegments() != 1)
                ++bad;
            // the clerical identity and the
            // herbal antidote chance
            if (!uad2SlowPoisonIdenticalToClerical())
                ++bad;
            if (uad2SlowPoisonAntidoteChancePctPerLevel()
                != 5) ++bad;
            if (!uad2SlowPoisonPlantPoisonCondition())
                ++bad;
            if (!uad2SlowPoisonDetectPoisonIndicatesOrganic())
                ++bad;
            if (!uad2SlowPoisonRollEqualOrLessNeutralizes())
                ++bad;
            if (!uad2SlowPoisonMaterialMistletoe()) ++bad;
            if (!uad2SlowPoisonMaterialGarlicOnFeet()) ++bad;
            if (!uad2SlowPoisonAntidoteOutdoorOrHerbalist())
                ++bad;
        }
        // U5: the R341 table seam
        {
            // The druid table (p. 29) prints no
            // 2nd-level roster - the 2nd and 3rd
            // columns are OCR-lost in R341; the
            // readable neighbors prove the pin
            // kept. All four 2nd-level names pin
            // from the prose alone.
            if (uastDruid1stCount() != 4) ++bad;
            if (strcmp(uastDruid1stName(0),
                "Locate Animals") != 0) ++bad;
            if (uastDruid4thCount() != 6) ++bad;
            if (strcmp(uastDruid4thName(0),
                "Cure Serious Wounds") != 0) ++bad;
            if (uastDruid5thCount() != 6) ++bad;
            if (strcmp(uastDruid5thName(0),
                "Commune With Nature") != 0) ++bad;
        }
        printf("R351 UA druid 2nd level spells pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
