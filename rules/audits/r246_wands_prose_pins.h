    // ---- R246: the III.D wands explanation prose pins audit ----
    // DMG pp.143-144: the conventions and the
    // first five wands of the RODS, et al.
    // explanation prose.
    {
        Rodswands rodswands;
        Wands_conventions_conjuration_to_fear wands_conventions_conjuration_to_fear;
        int bad = 0;
        // the conventions: 6th level, the 1%
        // backfire trap
        if (wands_conventions_conjuration_to_fear.wdLevelOfUse() != 6 ||
            wands_conventions_conjuration_to_fear.wdBackfirePercent() != 1) ++bad;
        // the five wands are the engine III.D
        // table wand rows 1-5 - bands 34-47,
        // illumination from 48 (the R224 pins)
        if (rodswands.rswRowLo(14) != 34 ||
            rodswands.rswRowHi(18) != 47 ||
            rodswands.rswRowLo(19) != 48) ++bad;
        // Wand of Conjuration
        if (wands_conventions_conjuration_to_fear.wdConjRecognizedCount() != 11 ||
            wands_conventions_conjuration_to_fear.wdConjSummonMaxCharges() != 6 ||
            wands_conventions_conjuration_to_fear.wdConjSummonSegments() != 5 ||
            wands_conventions_conjuration_to_fear.wdConjCurtainSqFeet() != 600 ||
            wands_conventions_conjuration_to_fear.wdConjCurtainCharges() != 2 ||
            wands_conventions_conjuration_to_fear.wdConjPrismaticChargesPerColor() != 1 ||
            wands_conventions_conjuration_to_fear.wdConjFunctionSegments() != 5 ||
            wands_conventions_conjuration_to_fear.wdConjFunctionsPerRound() != 1 ||
            wands_conventions_conjuration_to_fear.wdConjRechargeable() != 1) ++bad;
        // Wand of Enemy Detection
        if (wands_conventions_conjuration_to_fear.wdEnemyRadiusInches() != 6 ||
            wands_conventions_conjuration_to_fear.wdEnemyChargesPerTurn() != 1 ||
            wands_conventions_conjuration_to_fear.wdEnemyRechargeable() != 1) ++bad;
        // Wand of Fear
        if (wands_conventions_conjuration_to_fear.wdFearConeLengthInches() != 6 ||
            wands_conventions_conjuration_to_fear.wdFearConeWidthInches() != 2 ||
            wands_conventions_conjuration_to_fear.wdFearSegments() != 1 ||
            wands_conventions_conjuration_to_fear.wdFearFleeRounds() != 6 ||
            wands_conventions_conjuration_to_fear.wdFearChargesPerUse() != 1 ||
            wands_conventions_conjuration_to_fear.wdFearUsesPerRound() != 1 ||
            wands_conventions_conjuration_to_fear.wdFearRechargeable() != 1) ++bad;
        // Wand of Fire - the four functions
        if (wands_conventions_conjuration_to_fear.wdFireFunctionCount() != 4 ||
            wands_conventions_conjuration_to_fear.wdFireHandsWidthFeet() != 10 ||
            wands_conventions_conjuration_to_fear.wdFireHandsLengthFeet() != 12 ||
            wands_conventions_conjuration_to_fear.wdFireHandsHp() != 6 ||
            wands_conventions_conjuration_to_fear.wdFireHandsSegments() != 1 ||
            wands_conventions_conjuration_to_fear.wdFireHandsCharges() != 1 ||
            wands_conventions_conjuration_to_fear.wdFirePyroSegments() != 2 ||
            wands_conventions_conjuration_to_fear.wdFirePyroCharges() != 1 ||
            wands_conventions_conjuration_to_fear.wdFireBallRangeInches() != 16 ||
            wands_conventions_conjuration_to_fear.wdFireBallSegments() != 2 ||
            wands_conventions_conjuration_to_fear.wdFireBallCharges() != 2 ||
            wands_conventions_conjuration_to_fear.wdFireBallDice() != 6 ||
            wands_conventions_conjuration_to_fear.wdFireBallFaces() != 6 ||
            wands_conventions_conjuration_to_fear.wdFireBallDamageLo() != 12 ||
            wands_conventions_conjuration_to_fear.wdFireBallDamageHi() != 36) ++bad;
        // the wall of fire bands and the ring
        if (wands_conventions_conjuration_to_fear.wdFireWallAreaSqInches() != 12 ||
            wands_conventions_conjuration_to_fear.wdFireWallRounds() != 6 ||
            wands_conventions_conjuration_to_fear.wdFireWallTouchLo() != 8 ||
            wands_conventions_conjuration_to_fear.wdFireWallTouchHi() != 18 ||
            wands_conventions_conjuration_to_fear.wdFireWallNearLo() != 2 ||
            wands_conventions_conjuration_to_fear.wdFireWallNearHi() != 8 ||
            wands_conventions_conjuration_to_fear.wdFireWallFarLo() != 1 ||
            wands_conventions_conjuration_to_fear.wdFireWallFarHi() != 4 ||
            wands_conventions_conjuration_to_fear.wdFireWallRingQuarterInches() != 9 ||
            wands_conventions_conjuration_to_fear.wdFireUsesPerRound() != 1 ||
            wands_conventions_conjuration_to_fear.wdFireRechargeable() != 1) ++bad;
        // Wand of Frost - the three functions
        if (wands_conventions_conjuration_to_fear.wdFrostFunctionCount() != 3 ||
            wands_conventions_conjuration_to_fear.wdFrostStormRangeInches() != 6 ||
            wands_conventions_conjuration_to_fear.wdFrostStormSegments() != 1 ||
            wands_conventions_conjuration_to_fear.wdFrostStormCharges() != 1 ||
            wands_conventions_conjuration_to_fear.wdFrostWallThicknessInches() != 6 ||
            wands_conventions_conjuration_to_fear.wdFrostWallAreaInches() != 6 ||
            wands_conventions_conjuration_to_fear.wdFrostWallSegments() != 2 ||
            wands_conventions_conjuration_to_fear.wdFrostWallCharges() != 1 ||
            wands_conventions_conjuration_to_fear.wdFrostConeLengthInches() != 6 ||
            wands_conventions_conjuration_to_fear.wdFrostConeWidthInches() != 2 ||
            wands_conventions_conjuration_to_fear.wdFrostConeSegments() != 2 ||
            wands_conventions_conjuration_to_fear.wdFrostConeTempF() != -100 ||
            wands_conventions_conjuration_to_fear.wdFrostConeDice() != 6 ||
            wands_conventions_conjuration_to_fear.wdFrostConeDamageLo() != 12 ||
            wands_conventions_conjuration_to_fear.wdFrostConeDamageHi() != 36 ||
            wands_conventions_conjuration_to_fear.wdFrostConeCharges() != 2 ||
            wands_conventions_conjuration_to_fear.wdFrostUsesPerRound() != 1 ||
            wands_conventions_conjuration_to_fear.wdFrostRechargeable() != 1) ++bad;
        printf("R246 wands prose pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
