    // ---- R165: potion miscibility audit ------------
    // DMG p.119: the miscibility d100 bands, the
    // trigger conditions, the explosion and poison
    // numbers, the boost, and the named campaign
    // options.
    {
        Miscibility miscibility;
        int bad = 0;
        // the band boundaries: probe every d100 face
        for (int r = 1; r <= 100; ++r) {
            Miscibility miscibility;
            MiscibilityResult want;
            if (r == 1) want = MISC_EXPLOSION;
            else if (r <= 3) want = MISC_LETHAL_POISON;
            else if (r <= 8) want = MISC_MILD_POISON;
            else if (r <= 15) want = MISC_BOTH_DESTROYED;
            else if (r <= 25) want = MISC_ONE_CANCELLED;
            else if (r <= 35) want = MISC_BOTH_HALF;
            else if (r <= 90) want = MISC_COMPATIBLE;
            else if (r <= 99) want = MISC_ONE_BOOSTED;
            else want = MISC_DISCOVERY;
            if (miscibility.miscibilityRoll(r) != want) ++bad;
        }
        // the clamps
        if (miscibility.miscibilityRoll(0) != MISC_EXPLOSION ||
            miscibility.miscibilityRoll(-7) != MISC_EXPLOSION ||
            miscibility.miscibilityRoll(101) != MISC_DISCOVERY ||
            miscibility.miscibilityRoll(999) != MISC_DISCOVERY)
            ++bad;
        // the trigger conditions
        if (!miscibility.miscibilityTestNeeded(true, false) ||
            !miscibility.miscibilityTestNeeded(false, true) ||
            miscibility.miscibilityTestNeeded(false, false)) ++bad;
        // the explosion numbers
        if (miscibility.miscibilityExplosionInternalMin() != 6 ||
            miscibility.miscibilityExplosionInternalMax() != 60 ||
            miscibility.miscibilityExplosionBlastNearMin() != 1 ||
            miscibility.miscibilityExplosionBlastNearMax() != 10 ||
            miscibility.miscibilityExplosionBlastNearRadius() != 5 ||
            miscibility.miscibilityExplosionBlastFarMin() != 4 ||
            miscibility.miscibilityExplosionBlastFarMax() != 24 ||
            miscibility.miscibilityExplosionBlastFarRadius() != 10)
            ++bad;
        // the mild poison duration and the gas cloud
        if (miscibility.miscibilityMildPoisonDurationMin() != 5 ||
            miscibility.miscibilityMildPoisonDurationMax() != 20 ||
            miscibility.miscibilityGasCloudRadius() != 10) ++bad;
        // the boost
        if (miscibility.miscibilityBoostPercent() != 150) ++bad;
        // the named campaign options
        if (!miscibility.miscibilityOptionDelusionMixes() ||
            !miscibility.miscibilityOptionTreasureFindingLethal() ||
            miscibility.miscibilityOptionEtherealLostPercent() != 50 ||
            miscibility.miscibilityOptionEtherealLostMinDays() != 5 ||
            miscibility.miscibilityOptionEtherealLostMaxDays() != 30)
            ++bad;
        printf("R165 potion miscibility audit: bad %d\n", bad);
        if (bad) return 1;
    }
