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
            if (miscibility.roll(r) != want) ++bad;
        }
        // the clamps
        if (miscibility.roll(0) != MISC_EXPLOSION ||
            miscibility.roll(-7) != MISC_EXPLOSION ||
            miscibility.roll(101) != MISC_DISCOVERY ||
            miscibility.roll(999) != MISC_DISCOVERY)
            ++bad;
        // the trigger conditions
        if (!miscibility.testNeeded(true, false) ||
            !miscibility.testNeeded(false, true) ||
            miscibility.testNeeded(false, false)) ++bad;
        // the explosion numbers
        if (miscibility.explosionInternalMin() != 6 ||
            miscibility.explosionInternalMax() != 60 ||
            miscibility.explosionBlastNearMin() != 1 ||
            miscibility.explosionBlastNearMax() != 10 ||
            miscibility.explosionBlastNearRadius() != 5 ||
            miscibility.explosionBlastFarMin() != 4 ||
            miscibility.explosionBlastFarMax() != 24 ||
            miscibility.explosionBlastFarRadius() != 10)
            ++bad;
        // the mild poison duration and the gas cloud
        if (miscibility.mildPoisonDurationMin() != 5 ||
            miscibility.mildPoisonDurationMax() != 20 ||
            miscibility.gasCloudRadius() != 10) ++bad;
        // the boost
        if (miscibility.boostPercent() != 150) ++bad;
        // the named campaign options
        if (!miscibility.optionDelusionMixes() ||
            !miscibility.optionTreasureFindingLethal() ||
            miscibility.optionEtherealLostPercent() != 50 ||
            miscibility.optionEtherealLostMinDays() != 5 ||
            miscibility.optionEtherealLostMaxDays() != 30)
            ++bad;
        printf("R165 potion miscibility audit: bad %d\n", bad);
        if (bad) return 1;
    }
