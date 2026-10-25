    // ---- R437 WSG falling damage pin audit ----
    // The damage-from-falling slice pins Table 17 (the six fall-distance
    // bands x the band-minimum distances and the cumulative damage dice) with
    // the falling-vs-tumbling prose (the vertical-drop definition, the
    // 1d6-cumulative-per-10-feet basis, the recurring-impact rule on severe
    // slopes, the smooth/slippery abrasion note and the 1000 and 600-800
    // feet-per-round rates) (rules/wsgfall.h, prefix wdf); census 361 -> 362.
    {
        using namespace rules;
        int bad = 0;
    if (wdfFallBandCount() != 6
            || wdfFreeFallRate() != 1000
            || wdfSevereRateMin() != 600
            || wdfSevereRateMax() != 800
            || wdfMaxFallDice() != 20
            || !wdfFallingVsTumbling()
            || !wdfFallingIsVerticalDrop()
            || !wdfDiceCumulativePer10Ft()
            || !wdfAppliesFreeFallOrSevere()
            || !wdfSevereTumbleRecurringImpact()
            || !wdfSmoothSlipperyAbrasionNote()
            || !wdfTumbleModerateGentleNext()
        )
            ++bad;
        // the Table 17 grid: the six fall-distance bands (the 10, 11-20,
        // 21-30, 31-40, 41-50 and 51-or-more-feet bands) x the band-minimum
        // distances and the cumulative damage dice
        int C17[6][2] = {
            {10,1},
            {11,3},
            {21,6},
            {31,10},
            {41,15},
            {51,20},
            };
        for (int b = 0;
             b < wdfFallBandCount();
             ++b) {
            int vals[2];
            vals[0] = wdfFallMinFt(b);
            vals[1] = wdfFallDice(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != C17[b][c])
                    ++bad;
            }
        }
        // the 11-20 feet band: 3d6 cumulative - the cell MISSING from the
        // djvu text layer, settled by two full-res eye-reads
    if (wdfFallMinFt(1) != 11
            || wdfFallDice(1) != 3
        )
            ++bad;
        // the 51-feet-or-more band is capped at the 20d6 maximum
    if (wdfFallDice(5) != 20
            || wdfFallDice(5) != wdfMaxFallDice()
        )
            ++bad;
        // the unimpeded rates: 1000 feet per round in free fall, 600 through
        // 800 feet per round down a severe slope (the 600 plus the 800 span
        // 1400)
    if (wdfFreeFallRate() != 1000
            || wdfSevereRateMin() + wdfSevereRateMax() != 1400
        )
            ++bad;
        // the first two bands: 3d6 at 20 feet is three times the 1d6 at 10
        // feet
    if (wdfFallDice(1) - wdfFallDice(0) * 3 != 0
        )
            ++bad;
        // the Table 17 dice are strictly increasing band by band
    if (wdfFallDice(0) >= wdfFallDice(1)
            || wdfFallDice(1) >= wdfFallDice(2)
            || wdfFallDice(2) >= wdfFallDice(3)
            || wdfFallDice(3) >= wdfFallDice(4)
            || wdfFallDice(4) >= wdfFallDice(5)
        )
            ++bad;
        // the Table 17 bands are contiguous 10-foot bands: each minimum sits
        // one foot above the previous multiple of 10
    if (wdfFallMinFt(1) != 11
            || wdfFallMinFt(2) != 21
            || wdfFallMinFt(3) != 31
            || wdfFallMinFt(4) != 41
            || wdfFallMinFt(5) != 51
        )
            ++bad;
        printf("R437 WSG falling damage pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
