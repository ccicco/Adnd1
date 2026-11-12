    // ---- R248: the III.D wand of wonder effect table pins audit ----
    // DMG p.145: the 19 die bands and the
    // effect numeric facts - the round that
    // closes the III.D wands arc.
    {
        Rodswands rodswands;
        Wonder wonder;
        int bad = 0;
        // the table identity: the 19 bands tile 01-100
        if (wonder.rowCount() != 19) ++bad;
        static const int kLo[19] = {
            1, 11, 19, 26, 31, 34, 37, 47, 50, 54,
            59, 63, 66, 70, 80, 85, 88, 91, 98,
        };
        static const int kHi[19] = {
            10, 18, 25, 30, 33, 36, 46, 49, 53, 58,
            62, 65, 69, 79, 84, 87, 90, 97, 100,
        };
        for (int i = 0; i < 19; ++i)
            if (wonder.rowLo(i) != kLo[i] ||
                wonder.rowHi(i) != kHi[i]) ++bad;
        for (int i = 1; i < 19; ++i)
            if (wonder.rowLo(i) !=
                wonder.rowHi(i - 1) + 1) ++bad;
        if (wonder.rowLo(-5) != 1 ||
            wonder.rowHi(99) != 100) ++bad;
        // the engine cross-check: the wonder is
        // kRods row 30, bands 95-100 (the R224 pins)
        if (rodswands.rswRowLo(29) != 95 ||
            rodswands.rswRowHi(29) != 100) ++bad;
        // the global facts
        if (wonder.chargesPerFunction() != 1 ||
            wonder.rechargeable() != 0) ++bad;
        // bands 01-25: slow, delude, gust
        if (wonder.slowTurns() != 1 ||
            wonder.deludeRounds() != 1 ||
            wonder.gustForceMultiplier() != 2) ++bad;
        // bands 26-33: stinking cloud, heavy rain
        if (wonder.stinkingRangeInches() != 3 ||
            wonder.rainRounds() != 1 ||
            wonder.rainRadiusInches() != 6) ++bad;
        // band 34-36: the summon subtable
        if (wonder.summonRhinoLo() != 1 ||
            wonder.summonRhinoHi() != 25 ||
            wonder.summonElephantLo() != 26 ||
            wonder.summonElephantHi() != 50 ||
            wonder.summonMouseLo() != 51 ||
            wonder.summonMouseHi() != 100) ++bad;
        // bands 37-49: the bolt, the butterflies
        if (wonder.boltLengthInches() != 7 ||
            wonder.boltWidthHalfInches() != 1 ||
            wonder.butterflyCount() != 600 ||
            wonder.butterflyRounds() != 2) ++bad;
        // bands 50-58: enlarge, darkness
        if (wonder.enlargeRangeInches() != 6 ||
            wonder.darknessDiameterInches() != 3 ||
            wonder.darknessCenterDistanceInches() != 3) ++bad;
        // bands 59-65: grass, vanish
        if (wonder.grassAreaInches() != 16 ||
            wonder.grassGrowthFactor() != 10 ||
            wonder.vanishMassPounds() != 1000 ||
            wonder.vanishVolumeCubicFeet() != 30) ++bad;
        // band 66-69: diminish
        if (wonder.diminishHeightInches() != 1) ++bad;
        // bands 70-84: fireball as wand, invisibility
        // band 85-87: leaves
        if (wonder.leavesRangeInches() != 6) ++bad;
        // band 88-90: the gem stream
        if (wonder.gemCountLo() != 10 ||
            wonder.gemCountHi() != 40 ||
            wonder.gemBaseValueGp() != 1 ||
            wonder.gemStreamLengthInches() != 3 ||
            wonder.gemDamageHp() != 1 ||
            wonder.gemHitDice() != 5 ||
            wonder.gemHitFaces() != 4) ++bad;
        // band 91-97: shimmering colors
        if (wonder.colorAreaWidthInches() != 4 ||
            wonder.colorAreaHeightInches() != 3 ||
            wonder.colorBlindLo() != 1 ||
            wonder.colorBlindHi() != 6) ++bad;
        // band 98-00: flesh to stone
        if (wonder.fleshRangeInches() != 6) ++bad;
        printf("R248 wand of wonder effect table pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
