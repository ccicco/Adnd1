    // ---- R352: the UA new druid 3rd level spells pin audit ----
    // The UA NEW DRUID SPELLS (pp. 44-45),
    // the 3rd level - cloudburst (the
    // stat-block interleave with the call
    // lightning exclusion), know alignment
    // (the five-creature cap, not
    // reversible), spike growth (the
    // mistletoe-plus-twigs material
    // interleave) and starshine (the school
    // tail lost). The digit-garble family
    // decodes the "7 turn/level" as 1; the
    // cloudburst duration decodes from the
    // "1 ro" + "vol" fragments. The item
    // stays open (the 5th-7th levels; the UA
    // prints no 4th-level druid section).
    {
        using namespace rules;
        int bad = 0;
        // U1: cloudburst
        {
            if (strcmp(uad3CloudburstName(),
                "Cloudburst (Alteration)") != 0) ++bad;
            if (!uad3CloudburstComponentsVSM()) ++bad;
            if (uad3CloudburstLevel() != 3) ++bad;
            if (uad3CloudburstCastingTimeSegments() != 5)
                ++bad;
            if (!uad3CloudburstSaveNoneAndSpecial()) ++bad;
            // the "1 ro" + "vol" duration decode
            if (uad3CloudburstDurationRoundsPerLevel()
                != 1) ++bad;
            if (uad3CloudburstCylinderDiameterInches()
                != 4) ++bad;
            if (uad3CloudburstCylinderHeightInches() != 6)
                ++bad;
            if (!uad3CloudburstStatBlockInterleaveDecoded())
                ++bad;
            // the "pid pve;" fragment and the
            // missing range cell - holes
            if (!uad3CloudburstHeadFragmentLost()) ++bad;
            if (!uad3CloudburstRangeLost()) ++bad;
            if (!uad3CloudburstIdenticalToClerical3rd())
                ++bad;
            // the call lightning exclusion
            if (!uad3CloudburstCallLightningExclusion())
                ++bad;
            if (!uad3CloudburstProseHeadScrambleDecoded())
                ++bad;
            if (!uad3CloudburstMaterialMistletoe()) ++bad;
        }
        // U2: know alignment
        {
            if (strcmp(uad3KnowAlignmentName(),
                "Know Alignment (Divination)") != 0) ++bad;
            // the "V, S$" S-garble family
            if (!uad3KnowAlignmentComponentsVSGarble())
                ++bad;
            if (uad3KnowAlignmentLevel() != 3) ++bad;
            if (uad3KnowAlignmentRangeInches() != 1) ++bad;
            if (uad3KnowAlignmentDurationRounds() != 5)
                ++bad;
            if (!uad3KnowAlignmentAoeOnePerRound()) ++bad;
            if (uad3KnowAlignmentCastingTimeSegments() != 5)
                ++bad;
            if (!uad3KnowAlignmentSaveNone()) ++bad;
            if (!uad3KnowAlignmentIdenticalToClerical2nd())
                ++bad;
            // the five-creature cap
            if (uad3KnowAlignmentMaxCreaturesExamined()
                != 5) ++bad;
            if (!uad3KnowAlignmentCannotBeReversed()) ++bad;
        }
        // U3: spike growth
        {
            if (strcmp(uad3SpikeGrowthName(),
                "Spike Growth (Alteration/Enchantment)")
                != 0) ++bad;
            if (!uad3SpikeGrowthComponentsVSM()) ++bad;
            if (uad3SpikeGrowthLevel() != 3) ++bad;
            if (uad3SpikeGrowthCastingTimeSegments() != 5)
                ++bad;
            if (uad3SpikeGrowthRangeInches() != 6) ++bad;
            if (!uad3SpikeGrowthSaveNone()) ++bad;
            // the 3-12 turns + 1/level duration
            if (uad3SpikeGrowthDurationTurnsMin() != 3)
                ++bad;
            if (uad3SpikeGrowthDurationTurnsMax() != 12)
                ++bad;
            if (uad3SpikeGrowthDurationTurnsPerLevel()
                != 1) ++bad;
            if (uad3SpikeGrowthAoeSquaresPerLevel() != 10)
                ++bad;
            // the "is essentially" head decode
            if (!uad3SpikeGrowthIdenticalToClerical4th())
                ++bad;
            if (!uad3SpikeGrowthHeadDecodeEssentially())
                ++bad;
            if (!uad3SpikeGrowthRadiatesAura()) ++bad;
            if (!uad3SpikeGrowthDetectMagicRevealsPitsAndSnares())
                ++bad;
            // the material interleave
            if (!uad3SpikeGrowthMaterialMistletoe()) ++bad;
            if (!uad3SpikeGrowthMaterialInPlaceOfHolySymbol())
                ++bad;
            if (uad3SpikeGrowthMaterialTwigsOrThorns()
                != 7) ++bad;
            if (!uad3SpikeGrowthMaterialInterleaveDecoded())
                ++bad;
        }
        // U4: starshine
        {
            if (strcmp(uad3StarshineName(),
                "Starshine") != 0) ++bad;
            // the school prints "Evocation -"
            // with the tail lost
            if (!uad3StarshineSchoolEvocation()) ++bad;
            if (!uad3StarshineSchoolTailLost()) ++bad;
            if (!uad3StarshineComponentsVSM()) ++bad;
            if (uad3StarshineLevel() != 3) ++bad;
            if (uad3StarshineCastingTimeSegments() != 5)
                ++bad;
            if (uad3StarshineRangeInchesPerLevel() != 1)
                ++bad;
            if (!uad3StarshineSaveNone()) ++bad;
            // the "7 turn/level" family decode
            if (uad3StarshineDurationTurnsPerLevel()
                != 1) ++bad;
            if (uad3StarshineAoeSquaresPerLevel() != 10)
                ++bad;
            if (!uad3StarshineNightSkyIllumination()) ++bad;
            if (!uad3StarshineRegardlessOfHeight()) ++bad;
            // the vision bands
            if (uad3StarshineVisionClearFeet() != 30) ++bad;
            if (uad3StarshineVisionIndistinctFeet() != 60)
                ++bad;
            if (!uad3StarshineGleamsBeyond()) ++bad;
            if (!uad3StarshineAllowsShadows()) ++bad;
            if (!uad3StarshineEnhancesUltravision()) ++bad;
            if (!uad3StarshineNoInfravisionEffect()) ++bad;
            if (!uad3StarshineDisbeliefRevealsEvokedLights())
                ++bad;
            // the amaryllis and holly berries
            if (!uad3StarshineMaterialAmaryllisStalks())
                ++bad;
            if (!uad3StarshineMaterialHollyBerries()) ++bad;
            if (!uad3StarshineWorksThroughReflectingPool())
                ++bad;
        }
        // U5: the cross-round and R341 seams
        {
            // the R351 reflecting pool pin named
            // starshine as operating through the
            // pool - both ends now pin
            if (!uad2ReflectingPoolStarshineOperates())
                ++bad;
            if (!uad3StarshineWorksThroughReflectingPool())
                ++bad;
            // the R341 druid table prints no
            // 3rd-level roster - all four names
            // pin from the prose
            if (uastDruid1stCount() != 4) ++bad;
            if (strcmp(uastDruid1stName(2),
                "Shillelagh") != 0) ++bad;
            if (uastDruid4thCount() != 6) ++bad;
            if (strcmp(uastDruid4thName(2),
                "Hallucinatory Forest") != 0) ++bad;
            if (uastDruid6thCount() != 5) ++bad;
            if (strcmp(uastDruid6thName(4),
                "Weather Summoning") != 0) ++bad;
        }
        printf("R352 UA druid 3rd level spells pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
