    // ---- R291: the III.E Special artifacts
    // explanation prose part 12 ----
    // The Nightingale, the Recorder of
    // YeCind and the Ring of Gaxx, part2
    // lines 1625-1676. No break absorbed -
    // the round closes on the standard
    // blank at 1676; no page seam claimed
    // (no running heads between lines 1450
    // and 1797).
    {
        int bad = 0;
        // the Nightingale scalars and powers
        if (rules::sapNightingaleMadeByXagy() != 1 ||
            rules::sapNightingaleJoramyCoMaker() != 1 ||
            rules::sapNightingaleMadeCenturiesAgo() != 17 ||
            rules::sapNightingaleEhlissaBentAll() != 1 ||
            rules::sapNightingaleNeverEscaped() != 1 ||
            rules::sapNightingaleGoldenWireCage() != 1 ||
            rules::sapNightingaleWingsPerchPerform() != 1 ||
            rules::sapNightingaleEyeRays() != 1 ||
            rules::sapNightingaleSongWonders() != 1 ||
            rules::sapNightingaleRaySongSpells() != 1 ||
            rules::sapNightingaleSphereRadiusFeet() != 30 ||
            rules::sapNightingaleSphereBlocksScrying() != 1 ||
            rules::sapNightingaleNoHungerThirst() != 1 ||
            rules::sapNightingalePowerTotal() != 8) ++bad;
        static const int kN[6] = {
            4, 0, 1, 1, 1, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapNightingalePowerCount(i) != kN[i]) ++bad;
        if (rules::sapNightingalePowerCount(0) +
            rules::sapNightingalePowerCount(1) +
            rules::sapNightingalePowerCount(2) +
            rules::sapNightingalePowerCount(3) +
            rules::sapNightingalePowerCount(4) +
            rules::sapNightingalePowerCount(5) !=
            rules::sapNightingalePowerTotal()) ++bad;
        // the Recorder scalars and powers
        if (rules::sapRecorderNeedsNoMusician() != 1 ||
            rules::sapRecorderPlaysOnCommand() != 1 ||
            rules::sapRecorderAlarmRadiusFeet() != 30 ||
            rules::sapRecorderAlarmIncludesSelf() != 1 ||
            rules::sapRecorderClueWordSongs() != 1 ||
            rules::sapRecorderRumoredSpells() != 1 ||
            rules::sapRecorderPowerTotal() != 11) ++bad;
        static const int kR[6] = {
            5, 2, 1, 1, 1, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapRecorderPowerCount(i) != kR[i]) ++bad;
        if (rules::sapRecorderPowerCount(0) +
            rules::sapRecorderPowerCount(1) +
            rules::sapRecorderPowerCount(2) +
            rules::sapRecorderPowerCount(3) +
            rules::sapRecorderPowerCount(4) +
            rules::sapRecorderPowerCount(5) !=
            rules::sapRecorderPowerTotal()) ++bad;
        // the Ring of Gaxx scalars and powers
        if (rules::sapGaxxAlienOrigin() != 1 ||
            rules::sapGaxxPlatinumLoopSpinel() != 1 ||
            rules::sapGaxxUnknownGemType() != 1 ||
            rules::sapGaxxFingerDiscovery() != 1 ||
            rules::sapGaxxFacetCount() != 9 ||
            rules::sapGaxxFacingToTop() != 1 ||
            rules::sapGaxxTurnsItself() != 1 ||
            rules::sapGaxxDailyRandomFacet() != 1 ||
            rules::sapGaxxFacetOrderKnown() != 1 ||
            rules::sapGaxxCannotBeMarked() != 1 ||
            rules::sapGaxxPowerTotal() != 9) ++bad;
        static const int kG[6] = {
            3, 2, 1, 1, 1, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapGaxxPowerCount(i) != kG[i]) ++bad;
        if (rules::sapGaxxPowerCount(0) +
            rules::sapGaxxPowerCount(1) +
            rules::sapGaxxPowerCount(2) +
            rules::sapGaxxPowerCount(3) +
            rules::sapGaxxPowerCount(4) +
            rules::sapGaxxPowerCount(5) !=
            rules::sapGaxxPowerTotal()) ++bad;
        // the Nightingale and the Recorder agree on 30 feet
        if (rules::sapNightingaleSphereRadiusFeet() !=
            rules::sapRecorderAlarmRadiusFeet()) ++bad;
        // the Gaxx power total equals its facet count
        if (rules::sapGaxxPowerTotal() !=
            rules::sapGaxxFacetCount()) ++bad;
        // the cross-pins: the R240 sale table rows
        // (three fixed rows, 20, 21 and 22)
        if (rules::saRowLo(20) != 64 ||
            rules::saRowHi(20) != 64 ||
            rules::saSaleGp(20) != 112500 ||
            rules::saSaleGpHi(20) != 0) ++bad;
        if (rules::saRowLo(21) != 65 ||
            rules::saRowHi(21) != 66 ||
            rules::saSaleGp(21) != 80000 ||
            rules::saSaleGpHi(21) != 0) ++bad;
        if (rules::saRowLo(22) != 67 ||
            rules::saRowHi(22) != 68 ||
            rules::saSaleGp(22) != 17500 ||
            rules::saSaleGpHi(22) != 0) ++bad;
        printf("R291 special artifacts prose part 12 pins audit: bad %d\n", bad);
    }
