    // ---- R353: the UA new druid 5th level spells pin audit ----
    // The UA NEW DRUID SPELLS (p. 45), the
    // 5th level - moonbeam (the movable
    // spotlight beam with the color and
    // vision effects) and spike stones
    // (the school discrepancy vs the R347
    // clerical pin flagged; the stat cells
    // seam-check). The digit-garble family
    // decodes the "7 segments" as 1. The
    // item stays open (the 6th-7th levels).
    {
        using namespace rules;
        int bad = 0;
        // U1: moonbeam
        {
            if (strcmp(uad5MoonbeamName(),
                "Moonbeam (Evocation - Alteration)")
                != 0) ++bad;
            // the "## " marker lost - a
            // formatting hole
            if (!uad5MoonbeamHeaderMarkerLost()) ++bad;
            if (!uad5MoonbeamComponentsVSM()) ++bad;
            if (uad5MoonbeamLevel() != 5) ++bad;
            // the "7 segments" family decode
            if (uad5MoonbeamCastingTimeSegments() != 1)
                ++bad;
            // the unit-less range cell - with
            // doubt
            if (uad5MoonbeamRangeInches() != 1) ++bad;
            if (!uad5MoonbeamRangeUnitLost()) ++bad;
            if (!uad5MoonbeamSaveNone()) ++bad;
            if (uad5MoonbeamDurationRoundsPerLevel()
                != 1) ++bad;
            if (!uad5MoonbeamAoeOneInchSpherePlusSpecial())
                ++bad;
            if (!uad5MoonbeamDownwardBeamOnPointedArea())
                ++bad;
            if (!uad5MoonbeamExactMoonlight()) ++bad;
            if (!uad5MoonbeamColorsNotDeterminable())
                ++bad;
            if (!uad5MoonbeamMovesToSeenPointedAreas())
                ++bad;
            if (!uad5MoonbeamEffectiveSpotlight()) ++bad;
            if (!uad5MoonbeamAllowsShadows()) ++bad;
            if (!uad5MoonbeamCenteredCreatureObserved())
                ++bad;
            // the 1 inch dim perception
            if (uad5MoonbeamDimPerceptionInchesBeyond()
                != 1) ++bad;
            if (!uad5MoonbeamNoInfravisionAdverseEffect())
                ++bad;
            if (!uad5MoonbeamEnhancesUltravision()) ++bad;
            // the moonseed and moonstone
            if (!uad5MoonbeamMaterialMoonseedSeeds())
                ++bad;
            if (!uad5MoonbeamMaterialMoonstoneFeldspar())
                ++bad;
        }
        // U2: spike stones
        {
            // the druid school cell prints
            // Enhancement; the R347 clerical
            // pin reads Enchantment
            if (strcmp(uad5SpikeStonesName(),
                "Spike Stones (Alteration/Enhancement)")
                != 0) ++bad;
            if (!uad5SpikeStonesSchoolDiscrepancyFlagged())
                ++bad;
            if (!uad5SpikeStonesComponentsVSM()) ++bad;
            if (uad5SpikeStonesLevel() != 5) ++bad;
            // the empty casting time cell - a
            // hole
            if (!uad5SpikeStonesCastingTimeCellLost())
                ++bad;
            if (uad5SpikeStonesRangeInches() != 3) ++bad;
            if (!uad5SpikeStonesSaveNone()) ++bad;
            if (uad5SpikeStonesDurationTurnsMin() != 3)
                ++bad;
            if (uad5SpikeStonesDurationTurnsMax() != 12)
                ++bad;
            if (uad5SpikeStonesDurationTurnsPerLevel()
                != 1) ++bad;
            if (uad5SpikeStonesAoeSquareInchesPerLevel()
                != 1) ++bad;
            if (uad5SpikeStonesSpikesPerSquareFoot() != 1)
                ++bad;
            if (!uad5SpikeStonesIdenticalToClerical())
                ++bad;
        }
        // U3: the R347 clerical seam
        {
            // The druid spike stones pin
            // seam-checks against the R347
            // clerical pin cell by cell.
            if (uad5SpikeStonesRangeInches()
                != uac5SpikeStonesRangeInches()) ++bad;
            if (uad5SpikeStonesDurationTurnsMin()
                != uac5SpikeStonesDurationTurnsMin())
                ++bad;
            if (uad5SpikeStonesDurationTurnsMax()
                != uac5SpikeStonesDurationTurnsMax())
                ++bad;
            if (uad5SpikeStonesDurationTurnsPerLevel()
                != uac5SpikeStonesDurationTurnsPerLevel())
                ++bad;
            if (uad5SpikeStonesAoeSquareInchesPerLevel()
                != uac5SpikeStonesAoeSquareInchesPerLevel())
                ++bad;
            if (uad5SpikeStonesSpikesPerSquareFoot()
                != uac5SpikeStonesSpikesPerSquareFoot())
                ++bad;
            if (!uac5SpikeStonesSaveNone()) ++bad;
            // the R341 druid 5th-level table
            // prints six PHB names - neither
            // new name seam-checks there; both
            // pin from the prose
            if (uastDruid5thCount() != 6) ++bad;
            if (strcmp(uastDruid5thName(0),
                "Commune With Nature") != 0) ++bad;
            if (strcmp(uastDruid5thName(5),
                "Wall Of Fire") != 0) ++bad;
        }
        printf("R353 UA druid 5th level spells pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
