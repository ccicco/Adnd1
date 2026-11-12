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
        Specart specart;
        Specart_axe_of_the_dwarvish_lords_to_codex specart_axe_of_the_dwarvish_lords_to_codex;
        int bad = 0;
        // the Nightingale scalars and powers
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapNightingaleMadeByXagy() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapNightingaleJoramyCoMaker() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapNightingaleMadeCenturiesAgo() != 17 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapNightingaleEhlissaBentAll() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapNightingaleNeverEscaped() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapNightingaleGoldenWireCage() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapNightingaleWingsPerchPerform() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapNightingaleEyeRays() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapNightingaleSongWonders() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapNightingaleRaySongSpells() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapNightingaleSphereRadiusFeet() != 30 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapNightingaleSphereBlocksScrying() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapNightingaleNoHungerThirst() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapNightingalePowerTotal() != 8) ++bad;
        static const int kN[6] = {
            4, 0, 1, 1, 1, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapNightingalePowerCount(i) != kN[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapNightingalePowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapNightingalePowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapNightingalePowerCount(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapNightingalePowerCount(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapNightingalePowerCount(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapNightingalePowerCount(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapNightingalePowerTotal()) ++bad;
        // the Recorder scalars and powers
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapRecorderNeedsNoMusician() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRecorderPlaysOnCommand() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRecorderAlarmRadiusFeet() != 30 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRecorderAlarmIncludesSelf() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRecorderClueWordSongs() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRecorderRumoredSpells() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapRecorderPowerTotal() != 11) ++bad;
        static const int kR[6] = {
            5, 2, 1, 1, 1, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapRecorderPowerCount(i) != kR[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapRecorderPowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapRecorderPowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapRecorderPowerCount(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapRecorderPowerCount(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapRecorderPowerCount(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapRecorderPowerCount(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapRecorderPowerTotal()) ++bad;
        // the Ring of Gaxx scalars and powers
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapGaxxAlienOrigin() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapGaxxPlatinumLoopSpinel() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapGaxxUnknownGemType() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapGaxxFingerDiscovery() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapGaxxFacetCount() != 9 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapGaxxFacingToTop() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapGaxxTurnsItself() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapGaxxDailyRandomFacet() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapGaxxFacetOrderKnown() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapGaxxCannotBeMarked() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapGaxxPowerTotal() != 9) ++bad;
        static const int kG[6] = {
            3, 2, 1, 1, 1, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapGaxxPowerCount(i) != kG[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapGaxxPowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapGaxxPowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapGaxxPowerCount(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapGaxxPowerCount(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapGaxxPowerCount(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapGaxxPowerCount(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapGaxxPowerTotal()) ++bad;
        // the Nightingale and the Recorder agree on 30 feet
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapNightingaleSphereRadiusFeet() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapRecorderAlarmRadiusFeet()) ++bad;
        // the Gaxx power total equals its facet count
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapGaxxPowerTotal() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapGaxxFacetCount()) ++bad;
        // the cross-pins: the R240 sale table rows
        // (three fixed rows, 20, 21 and 22)
        if (specart.saRowLo(20) != 64 ||
            specart.saRowHi(20) != 64 ||
            specart.saSaleGp(20) != 112500 ||
            specart.saSaleGpHi(20) != 0) ++bad;
        if (specart.saRowLo(21) != 65 ||
            specart.saRowHi(21) != 66 ||
            specart.saSaleGp(21) != 80000 ||
            specart.saSaleGpHi(21) != 0) ++bad;
        if (specart.saRowLo(22) != 67 ||
            specart.saRowHi(22) != 68 ||
            specart.saSaleGp(22) != 17500 ||
            specart.saSaleGpHi(22) != 0) ++bad;
        printf("R291 special artifacts prose part 12 pins audit: bad %d\n", bad);
    }
