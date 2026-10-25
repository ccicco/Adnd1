    // ---- R354: the UA new druid 6th level spells pin audit ----
    // The UA NEW DRUID SPELLS (p. 45), the
    // 6th level - liveoak (the triggered
    // treant with the 3-inch movement
    // decode) and water to dust (the
    // scrambled stat block with the muddy
    // multipliers and the water-native
    // save gate). The digit-garble family
    // decodes the "7 turn" as 1. The item
    // stays open (the 7th level).
    {
        using namespace rules;
        int bad = 0;
        // U1: liveoak
        {
            if (strcmp(uad6LiveoakName(),
                "Liveoak (Enchantment)") != 0) ++bad;
            if (!uad6LiveoakComponentsVSM()) ++bad;
            if (uad6LiveoakLevel() != 6) ++bad;
            if (!uad6LiveoakRangeTouch()) ++bad;
            if (uad6LiveoakDurationDaysPerLevel() != 1)
                ++bad;
            if (!uad6LiveoakAoeOneOakTree()) ++bad;
            // the "7 turn" family decode
            if (uad6LiveoakCastingTimeTurns() != 1) ++bad;
            if (!uad6LiveoakSaveNone()) ++bad;
            if (!uad6LiveoakSingleTreeAtATime()) ++bad;
            if (!uad6LiveoakOnlyOnePerDruid()) ++bad;
            // the three placement bounds
            if (uad6LiveoakDwellingFeet() != 10) ++bad;
            if (!uad6LiveoakWithinSacredPlace()) ++bad;
            if (uad6LiveoakGuardedInches() != 10) ++bad;
            if (!uad6LiveoakSizePerDesireAndAvailability())
                ++bad;
            // the trigger phrase ladder
            if (uad6LiveoakTriggerWordsPerLevel() != 1)
                ++bad;
            if (uad6LiveoakExampleTriggerWords() != 11)
                ++bad;
            if (uad6LiveoakExampleCasterLevel() != 11)
                ++bad;
            if (!uad6LiveoakBecomesTreantMmSpec()) ++bad;
            // the 3-inch movement decode
            if (uad6LiveoakTreantMovementRateInches() != 3)
                ++bad;
            if (!uad6LiveoakMovementWordDecoded()) ++bad;
            if (!uad6LiveoakRadiatesMagicAura()) ++bad;
            if (!uad6LiveoakDispelOrDesireReturns()) ++bad;
            if (!uad6LiveoakMaterialMistletoe()) ++bad;
        }
        // U2: water to dust
        {
            if (strcmp(uad6WaterToDustName(),
                "Water To Dust") != 0) ++bad;
            // the "Water To Dust (," [sic])
            // garble
            if (!uad6WaterToDustNameHeaderGarbled()) ++bad;
            if (!uad6WaterToDustSchoolLost()) ++bad;
            if (!uad6WaterToDustGapItemSaysTransmute())
                ++bad;
            // the components cell prints only
            // "V," - a hole
            if (!uad6WaterToDustComponentsCellLost()) ++bad;
            if (uad6WaterToDustLevel() != 6) ++bad;
            if (uad6WaterToDustRangeInches() != 6) ++bad;
            if (uad6WaterToDustCastingTimeSegments() != 8)
                ++bad;
            if (!uad6WaterToDustSaveNoneAndSpecial()) ++bad;
            if (!uad6WaterToDustDurationPermanent()) ++bad;
            if (uad6WaterToDustAoeCubicInchesPerLevel() != 1)
                ++bad;
            if (!uad6WaterToDustStatBlockInterleaveDecoded())
                ++bad;
            if (!uad6WaterToDustLiquidToPowderyDust())
                ++bad;
            // the muddy multipliers
            if (uad6WaterToDustMuddyAreaMultiplier() != 2)
                ++bad;
            if (uad6WaterToDustWetMudAreaMultiplier() != 4)
                ++bad;
            if (!uad6WaterToDustContactFormsSiltyMud())
                ++bad;
            if (!uad6WaterToDustOnlyLiquidAtCasting()) ++bad;
            if (!uad6WaterToDustPartialWaterAffected()) ++bad;
            if (!uad6WaterToDustPotionsRenderedUseless())
                ++bad;
            // the water-native save gate
            if (!uad6WaterToDustLivingUnaffectedExceptWaterNatives())
                ++bad;
            if (!uad6WaterToDustWaterNativeSaveVsSpell())
                ++bad;
            if (!uad6WaterToDustOneCreaturePerCasting())
                ++bad;
            // the create water reverse
            if (!uad6WaterToDustReverseCreateWater()) ++bad;
            if (!uad6WaterToDustReverseAddsDustPinch()) ++bad;
            // the components
            if (uad6WaterToDustDiamondDustMinGp() != 500)
                ++bad;
            if (!uad6WaterToDustMaterialSeashell()) ++bad;
            if (!uad6WaterToDustMaterialMistletoe()) ++bad;
        }
        // U3: the R341 table seam
        {
            // The druid 6th-level table prints
            // five PHB names - neither new
            // name seam-checks there; both pin
            // from the prose.
            if (uastDruid6thCount() != 5) ++bad;
            if (strcmp(uastDruid6thName(0),
                "Cure Critical Wounds") != 0) ++bad;
            if (strcmp(uastDruid6thName(4),
                "Weather Summoning") != 0) ++bad;
        }
        printf("R354 UA druid 6th level spells pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
