    // ---- R248: the III.D wand of wonder effect table pins audit ----
    // DMG p.145: the 19 die bands and the
    // effect numeric facts - the round that
    // closes the III.D wands arc.
    {
        Rodswands rodswands;
        Wonder wonder;
        int bad = 0;
        // the table identity: the 19 bands tile 01-100
        if (wonder.wonderRowCount() != 19) ++bad;
        static const int kLo[19] = {
            1, 11, 19, 26, 31, 34, 37, 47, 50, 54,
            59, 63, 66, 70, 80, 85, 88, 91, 98,
        };
        static const int kHi[19] = {
            10, 18, 25, 30, 33, 36, 46, 49, 53, 58,
            62, 65, 69, 79, 84, 87, 90, 97, 100,
        };
        for (int i = 0; i < 19; ++i)
            if (wonder.wonderRowLo(i) != kLo[i] ||
                wonder.wonderRowHi(i) != kHi[i]) ++bad;
        for (int i = 1; i < 19; ++i)
            if (wonder.wonderRowLo(i) !=
                wonder.wonderRowHi(i - 1) + 1) ++bad;
        if (wonder.wonderRowLo(-5) != 1 ||
            wonder.wonderRowHi(99) != 100) ++bad;
        // the engine cross-check: the wonder is
        // kRods row 30, bands 95-100 (the R224 pins)
        if (rodswands.rswRowLo(29) != 95 ||
            rodswands.rswRowHi(29) != 100) ++bad;
        // the global facts
        if (wonder.wonderChargesPerFunction() != 1 ||
            wonder.wonderRechargeable() != 0) ++bad;
        // bands 01-25: slow, delude, gust
        if (wonder.wonderSlowTurns() != 1 ||
            wonder.wonderDeludeRounds() != 1 ||
            wonder.wonderGustForceMultiplier() != 2) ++bad;
        // bands 26-33: stinking cloud, heavy rain
        if (wonder.wonderStinkingRangeInches() != 3 ||
            wonder.wonderRainRounds() != 1 ||
            wonder.wonderRainRadiusInches() != 6) ++bad;
        // band 34-36: the summon subtable
        if (wonder.wonderSummonRhinoLo() != 1 ||
            wonder.wonderSummonRhinoHi() != 25 ||
            wonder.wonderSummonElephantLo() != 26 ||
            wonder.wonderSummonElephantHi() != 50 ||
            wonder.wonderSummonMouseLo() != 51 ||
            wonder.wonderSummonMouseHi() != 100) ++bad;
        // bands 37-49: the bolt, the butterflies
        if (wonder.wonderBoltLengthInches() != 7 ||
            wonder.wonderBoltWidthHalfInches() != 1 ||
            wonder.wonderButterflyCount() != 600 ||
            wonder.wonderButterflyRounds() != 2) ++bad;
        // bands 50-58: enlarge, darkness
        if (wonder.wonderEnlargeRangeInches() != 6 ||
            wonder.wonderDarknessDiameterInches() != 3 ||
            wonder.wonderDarknessCenterDistanceInches() != 3) ++bad;
        // bands 59-65: grass, vanish
        if (wonder.wonderGrassAreaInches() != 16 ||
            wonder.wonderGrassGrowthFactor() != 10 ||
            wonder.wonderVanishMassPounds() != 1000 ||
            wonder.wonderVanishVolumeCubicFeet() != 30) ++bad;
        // band 66-69: diminish
        if (wonder.wonderDiminishHeightInches() != 1) ++bad;
        // bands 70-84: fireball as wand, invisibility
        // band 85-87: leaves
        if (wonder.wonderLeavesRangeInches() != 6) ++bad;
        // band 88-90: the gem stream
        if (wonder.wonderGemCountLo() != 10 ||
            wonder.wonderGemCountHi() != 40 ||
            wonder.wonderGemBaseValueGp() != 1 ||
            wonder.wonderGemStreamLengthInches() != 3 ||
            wonder.wonderGemDamageHp() != 1 ||
            wonder.wonderGemHitDice() != 5 ||
            wonder.wonderGemHitFaces() != 4) ++bad;
        // band 91-97: shimmering colors
        if (wonder.wonderColorAreaWidthInches() != 4 ||
            wonder.wonderColorAreaHeightInches() != 3 ||
            wonder.wonderColorBlindLo() != 1 ||
            wonder.wonderColorBlindHi() != 6) ++bad;
        // band 98-00: flesh to stone
        if (wonder.wonderFleshRangeInches() != 6) ++bad;
        printf("R248 wand of wonder effect table pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
