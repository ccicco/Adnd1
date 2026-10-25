    // ---- R248: the III.D wand of wonder effect table pins audit ----
    // DMG p.145: the 19 die bands and the
    // effect numeric facts - the round that
    // closes the III.D wands arc.
    {
        int bad = 0;
        // the table identity: the 19 bands tile 01-100
        if (rules::wonderRowCount() != 19) ++bad;
        static const int kLo[19] = {
            1, 11, 19, 26, 31, 34, 37, 47, 50, 54,
            59, 63, 66, 70, 80, 85, 88, 91, 98,
        };
        static const int kHi[19] = {
            10, 18, 25, 30, 33, 36, 46, 49, 53, 58,
            62, 65, 69, 79, 84, 87, 90, 97, 100,
        };
        for (int i = 0; i < 19; ++i)
            if (rules::wonderRowLo(i) != kLo[i] ||
                rules::wonderRowHi(i) != kHi[i]) ++bad;
        for (int i = 1; i < 19; ++i)
            if (rules::wonderRowLo(i) !=
                rules::wonderRowHi(i - 1) + 1) ++bad;
        if (rules::wonderRowLo(-5) != 1 ||
            rules::wonderRowHi(99) != 100) ++bad;
        // the engine cross-check: the wonder is
        // kRods row 30, bands 95-100 (the R224 pins)
        if (rules::rswRowLo(29) != 95 ||
            rules::rswRowHi(29) != 100) ++bad;
        // the global facts
        if (rules::wonderChargesPerFunction() != 1 ||
            rules::wonderRechargeable() != 0) ++bad;
        // bands 01-25: slow, delude, gust
        if (rules::wonderSlowTurns() != 1 ||
            rules::wonderDeludeRounds() != 1 ||
            rules::wonderGustForceMultiplier() != 2) ++bad;
        // bands 26-33: stinking cloud, heavy rain
        if (rules::wonderStinkingRangeInches() != 3 ||
            rules::wonderRainRounds() != 1 ||
            rules::wonderRainRadiusInches() != 6) ++bad;
        // band 34-36: the summon subtable
        if (rules::wonderSummonRhinoLo() != 1 ||
            rules::wonderSummonRhinoHi() != 25 ||
            rules::wonderSummonElephantLo() != 26 ||
            rules::wonderSummonElephantHi() != 50 ||
            rules::wonderSummonMouseLo() != 51 ||
            rules::wonderSummonMouseHi() != 100) ++bad;
        // bands 37-49: the bolt, the butterflies
        if (rules::wonderBoltLengthInches() != 7 ||
            rules::wonderBoltWidthHalfInches() != 1 ||
            rules::wonderButterflyCount() != 600 ||
            rules::wonderButterflyRounds() != 2) ++bad;
        // bands 50-58: enlarge, darkness
        if (rules::wonderEnlargeRangeInches() != 6 ||
            rules::wonderDarknessDiameterInches() != 3 ||
            rules::wonderDarknessCenterDistanceInches() != 3) ++bad;
        // bands 59-65: grass, vanish
        if (rules::wonderGrassAreaInches() != 16 ||
            rules::wonderGrassGrowthFactor() != 10 ||
            rules::wonderVanishMassPounds() != 1000 ||
            rules::wonderVanishVolumeCubicFeet() != 30) ++bad;
        // band 66-69: diminish
        if (rules::wonderDiminishHeightInches() != 1) ++bad;
        // bands 70-84: fireball as wand, invisibility
        // band 85-87: leaves
        if (rules::wonderLeavesRangeInches() != 6) ++bad;
        // band 88-90: the gem stream
        if (rules::wonderGemCountLo() != 10 ||
            rules::wonderGemCountHi() != 40 ||
            rules::wonderGemBaseValueGp() != 1 ||
            rules::wonderGemStreamLengthInches() != 3 ||
            rules::wonderGemDamageHp() != 1 ||
            rules::wonderGemHitDice() != 5 ||
            rules::wonderGemHitFaces() != 4) ++bad;
        // band 91-97: shimmering colors
        if (rules::wonderColorAreaWidthInches() != 4 ||
            rules::wonderColorAreaHeightInches() != 3 ||
            rules::wonderColorBlindLo() != 1 ||
            rules::wonderColorBlindHi() != 6) ++bad;
        // band 98-00: flesh to stone
        if (rules::wonderFleshRangeInches() != 6) ++bad;
        printf("R248 wand of wonder effect table pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
