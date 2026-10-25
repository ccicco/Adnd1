    // ---- R516 DSG structural decay audit ----
    // The DSG structural decay pins the wooden-structure aging rules (the
    // relatively swift decay of the underground environment, the
    // very-humid-air assumption of the typical location, the
    // almost-completely-dry areas at a mere 2 or 3% of the given rate, the
    // 1d6-year rot onset for anything made of wood and kept underground, the
    // creosote-or-sealant doubling of the period, the 5% chance of collapse
    // per multiple of the onset roll that passes, the roll-1 example at 5%
    // per year with the 20-year maximum and 100% collapse, the roll-6 example
    // lasting as much as 120 years, the check whenever any activity puts
    // unusual stress upon the structure, and the d100 roll against the
    // percentage chance of collapse).
    {
        using namespace rules;
        int bad = 0;
    if (dnsDryRateLowPct() != 2
            || dnsDryRateHighPct() != 3
            || dnsRotOnsetYearsDice() != 1
            || dnsRotOnsetYearsSides() != 6
            || dnsCreosotePeriodMultiplier() != 2
            || dnsCollapseChancePerMultiplePct() != 5
            || dnsRollOneMaxYears() != 20
            || dnsRollSixMaxYears() != 120
            || !dnsHumidAirAssumed()
            || !dnsDryAreasMereFractionOfRate()
            || !dnsCreosoteOrSealantDoubles()
            || !dnsCollapseChancePerMultipleOfOnset()
            || !dnsCheckOnUnusualStress()
            || !dnsStressCheckIsD100()
        )
            ++bad;
        // the dry-area band: almost completely dry areas decay at a mere 2 or
        // 3% of the typical humid rate.
    if (dnsDryRateLowPct() != 2
            || dnsDryRateHighPct() != 3
        )
            ++bad;
        // the rot onset: wooden things underground show rot after 1d6 years,
        // doubled to 2d6 by creosote or another sealing substance (the djvu
        // garble 146 = 1d6).
    if (dnsRotOnsetYearsDice() != 1
            || dnsRotOnsetYearsSides() != 6
            || dnsCreosotePeriodMultiplier() != 2
        )
            ++bad;
        // the collapse ladder: 5% per multiple of the onset roll - the roll-1
        // structure reaches 100% at 20 years, the roll-6 structure might last
        // 120 years.
    if (dnsCollapseChancePerMultiplePct() != 5
            || dnsRollOneMaxYears() != 20
            || dnsRollSixMaxYears() != 120
        )
            ++bad;
        printf("R516 DSG structural decay audit: bad %d\n", bad);
        if (bad) return 1;
    }
