    // ---- R165: potion miscibility audit ------------
    // DMG p.119: the miscibility d100 bands, the
    // trigger conditions, the explosion and poison
    // numbers, the boost, and the named campaign
    // options.
    {
        int bad = 0;
        // the band boundaries: probe every d100 face
        for (int r = 1; r <= 100; ++r) {
            rules::MiscibilityResult want;
            if (r == 1) want = rules::MISC_EXPLOSION;
            else if (r <= 3) want = rules::MISC_LETHAL_POISON;
            else if (r <= 8) want = rules::MISC_MILD_POISON;
            else if (r <= 15) want = rules::MISC_BOTH_DESTROYED;
            else if (r <= 25) want = rules::MISC_ONE_CANCELLED;
            else if (r <= 35) want = rules::MISC_BOTH_HALF;
            else if (r <= 90) want = rules::MISC_COMPATIBLE;
            else if (r <= 99) want = rules::MISC_ONE_BOOSTED;
            else want = rules::MISC_DISCOVERY;
            if (rules::miscibilityRoll(r) != want) ++bad;
        }
        // the clamps
        if (rules::miscibilityRoll(0) != rules::MISC_EXPLOSION ||
            rules::miscibilityRoll(-7) != rules::MISC_EXPLOSION ||
            rules::miscibilityRoll(101) != rules::MISC_DISCOVERY ||
            rules::miscibilityRoll(999) != rules::MISC_DISCOVERY)
            ++bad;
        // the trigger conditions
        if (!rules::miscibilityTestNeeded(true, false) ||
            !rules::miscibilityTestNeeded(false, true) ||
            rules::miscibilityTestNeeded(false, false)) ++bad;
        // the explosion numbers
        if (rules::miscibilityExplosionInternalMin() != 6 ||
            rules::miscibilityExplosionInternalMax() != 60 ||
            rules::miscibilityExplosionBlastNearMin() != 1 ||
            rules::miscibilityExplosionBlastNearMax() != 10 ||
            rules::miscibilityExplosionBlastNearRadius() != 5 ||
            rules::miscibilityExplosionBlastFarMin() != 4 ||
            rules::miscibilityExplosionBlastFarMax() != 24 ||
            rules::miscibilityExplosionBlastFarRadius() != 10)
            ++bad;
        // the mild poison duration and the gas cloud
        if (rules::miscibilityMildPoisonDurationMin() != 5 ||
            rules::miscibilityMildPoisonDurationMax() != 20 ||
            rules::miscibilityGasCloudRadius() != 10) ++bad;
        // the boost
        if (rules::miscibilityBoostPercent() != 150) ++bad;
        // the named campaign options
        if (!rules::miscibilityOptionDelusionMixes() ||
            !rules::miscibilityOptionTreasureFindingLethal() ||
            rules::miscibilityOptionEtherealLostPercent() != 50 ||
            rules::miscibilityOptionEtherealLostMinDays() != 5 ||
            rules::miscibilityOptionEtherealLostMaxDays() != 30)
            ++bad;
        printf("R165 potion miscibility audit: bad %d\n", bad);
        if (bad) return 1;
    }
