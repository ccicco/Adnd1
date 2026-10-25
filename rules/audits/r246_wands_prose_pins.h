    // ---- R246: the III.D wands explanation prose pins audit ----
    // DMG pp.143-144: the conventions and the
    // first five wands of the RODS, et al.
    // explanation prose.
    {
        int bad = 0;
        // the conventions: 6th level, the 1%
        // backfire trap
        if (rules::wdLevelOfUse() != 6 ||
            rules::wdBackfirePercent() != 1) ++bad;
        // the five wands are the engine III.D
        // table wand rows 1-5 - bands 34-47,
        // illumination from 48 (the R224 pins)
        if (rules::rswRowLo(14) != 34 ||
            rules::rswRowHi(18) != 47 ||
            rules::rswRowLo(19) != 48) ++bad;
        // Wand of Conjuration
        if (rules::wdConjRecognizedCount() != 11 ||
            rules::wdConjSummonMaxCharges() != 6 ||
            rules::wdConjSummonSegments() != 5 ||
            rules::wdConjCurtainSqFeet() != 600 ||
            rules::wdConjCurtainCharges() != 2 ||
            rules::wdConjPrismaticChargesPerColor() != 1 ||
            rules::wdConjFunctionSegments() != 5 ||
            rules::wdConjFunctionsPerRound() != 1 ||
            rules::wdConjRechargeable() != 1) ++bad;
        // Wand of Enemy Detection
        if (rules::wdEnemyRadiusInches() != 6 ||
            rules::wdEnemyChargesPerTurn() != 1 ||
            rules::wdEnemyRechargeable() != 1) ++bad;
        // Wand of Fear
        if (rules::wdFearConeLengthInches() != 6 ||
            rules::wdFearConeWidthInches() != 2 ||
            rules::wdFearSegments() != 1 ||
            rules::wdFearFleeRounds() != 6 ||
            rules::wdFearChargesPerUse() != 1 ||
            rules::wdFearUsesPerRound() != 1 ||
            rules::wdFearRechargeable() != 1) ++bad;
        // Wand of Fire - the four functions
        if (rules::wdFireFunctionCount() != 4 ||
            rules::wdFireHandsWidthFeet() != 10 ||
            rules::wdFireHandsLengthFeet() != 12 ||
            rules::wdFireHandsHp() != 6 ||
            rules::wdFireHandsSegments() != 1 ||
            rules::wdFireHandsCharges() != 1 ||
            rules::wdFirePyroSegments() != 2 ||
            rules::wdFirePyroCharges() != 1 ||
            rules::wdFireBallRangeInches() != 16 ||
            rules::wdFireBallSegments() != 2 ||
            rules::wdFireBallCharges() != 2 ||
            rules::wdFireBallDice() != 6 ||
            rules::wdFireBallFaces() != 6 ||
            rules::wdFireBallDamageLo() != 12 ||
            rules::wdFireBallDamageHi() != 36) ++bad;
        // the wall of fire bands and the ring
        if (rules::wdFireWallAreaSqInches() != 12 ||
            rules::wdFireWallRounds() != 6 ||
            rules::wdFireWallTouchLo() != 8 ||
            rules::wdFireWallTouchHi() != 18 ||
            rules::wdFireWallNearLo() != 2 ||
            rules::wdFireWallNearHi() != 8 ||
            rules::wdFireWallFarLo() != 1 ||
            rules::wdFireWallFarHi() != 4 ||
            rules::wdFireWallRingQuarterInches() != 9 ||
            rules::wdFireUsesPerRound() != 1 ||
            rules::wdFireRechargeable() != 1) ++bad;
        // Wand of Frost - the three functions
        if (rules::wdFrostFunctionCount() != 3 ||
            rules::wdFrostStormRangeInches() != 6 ||
            rules::wdFrostStormSegments() != 1 ||
            rules::wdFrostStormCharges() != 1 ||
            rules::wdFrostWallThicknessInches() != 6 ||
            rules::wdFrostWallAreaInches() != 6 ||
            rules::wdFrostWallSegments() != 2 ||
            rules::wdFrostWallCharges() != 1 ||
            rules::wdFrostConeLengthInches() != 6 ||
            rules::wdFrostConeWidthInches() != 2 ||
            rules::wdFrostConeSegments() != 2 ||
            rules::wdFrostConeTempF() != -100 ||
            rules::wdFrostConeDice() != 6 ||
            rules::wdFrostConeDamageLo() != 12 ||
            rules::wdFrostConeDamageHi() != 36 ||
            rules::wdFrostConeCharges() != 2 ||
            rules::wdFrostUsesPerRound() != 1 ||
            rules::wdFrostRechargeable() != 1) ++bad;
        printf("R246 wands prose pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
