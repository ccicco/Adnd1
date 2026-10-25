    // ---- R438 WSG tumbling damage pin audit ----
    // The tumbling-damage slice pins Table 18 (the six moderate-or-gentle
    // slope rows x the three condition cells, each split into the
    // abrasion-free feet, the abrasion die and the impact distance) with the
    // entry format rules, the worst-case and gradual-stop impact rules, the
    // flat-terrain extra-abrasion rule and the tumble rates
    // (rules/wsgtumble.h, prefix wdt); census 362 -> 363.
    {
        using namespace rules;
        int bad = 0;
    if (wdtRowCount() != 6
            || wdtGentleRowBase() != 0
            || wdtModerateRowBase() != 3
            || wdtAbrasionPerFt() != 10
            || wdtGentleRateMin() != 100
            || wdtGentleRateMax() != 300
            || wdtModerateRateMin() != 300
            || wdtModerateRateMax() != 500
            || !wdtFirstNumberFreeFeet()
            || !wdtSecondNumberDie()
            || !wdtThirdNumberImpactDist()
            || !wdtImpactPerIncrement()
            || !wdtImpactWorstCase()
            || !wdtGradualStopDecrease()
            || !wdtFlatTumbleExtraAbrasion()
            || !wdtTumbleIsSlipOrRelease()
            || !wdtRatesSlowestNonslippery()
        )
            ++bad;
        // the Table 18 grid: the six slope rows (the rough, normal and smooth
        // surfaces at the gentle and moderate tilts) x the three conditions,
        // each cell split into the abrasion-free feet, the abrasion die and
        // the impact distance
        int C18[6][9] = {
            {20,30,40,3,3,3,50,40,30},
            {10,20,30,6,6,6,40,30,20},
            {30,40,50,3,3,3,50,40,30},
            {20,30,40,6,6,6,40,30,20},
            {40,50,60,3,3,3,40,30,30},
            {30,40,50,3,3,3,30,20,20},
            };
        for (int b = 0;
             b < wdtRowCount();
             ++b) {
            int vals[9];
            vals[0] = wdtAbrN(b);
            vals[1] = wdtAbrS(b);
            vals[2] = wdtAbrV(b);
            vals[3] = wdtDieN(b);
            vals[4] = wdtDieS(b);
            vals[5] = wdtDieV(b);
            vals[6] = wdtImpN(b);
            vals[7] = wdtImpS(b);
            vals[8] = wdtImpV(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != C18[b][c])
                    ++bad;
            }
        }
        // the rough gentle non-slippery cell: 20 feet free of abrasion, a 1d3
        // die, a 50-foot impact threshold
    if (wdtAbrN(0) != 20
            || wdtDieN(0) != 3
            || wdtImpN(0) != 50
        )
            ++bad;
        // the book's own worked example: the smooth moderate
        // slightly-slippery 40/3/20 cell - a 100-foot tumble suffers 6d3
        // abrasion over the last 60 feet (written division-free - 100 minus
        // 40 equals six 10-foot increments)
    if ((100 - wdtAbrS(5)) != wdtAbrasionPerFt() * 6
            || wdtDieS(5) != 3
        )
            ++bad;
        // the same example, the impact half: five 20-foot increments in 100
        // feet means 5d6 impact damage at the bottom (written division-free)
    if (wdtImpS(5) * 5 != 100
            || wdtImpS(5) != 20
        )
            ++bad;
        // the unimpeded tumble rates: 100-300 feet per round down a gentle
        // slope, 300-500 feet per round down a moderate slope
    if (wdtGentleRateMin() != 100
            || wdtModerateRateMax() != 500
        )
            ++bad;
        // the die split: the rough moderate row rolls 1d6 abrasion, the
        // smooth moderate row rolls 1d3 (the book itself uses the 3 there)
    if (wdtDieN(1) != 6
            || wdtDieN(5) != 3
        )
            ++bad;
        // every Table 18 row: the abrasion-free distance grows with
        // slipperiness (non-slippery <= slightly slippery <= slippery)
    if (wdtAbrS(0) < wdtAbrN(0)
            || wdtAbrV(0) < wdtAbrS(0)
            || wdtAbrS(1) < wdtAbrN(1)
            || wdtAbrV(1) < wdtAbrS(1)
            || wdtAbrS(2) < wdtAbrN(2)
            || wdtAbrV(2) < wdtAbrS(2)
            || wdtAbrS(3) < wdtAbrN(3)
            || wdtAbrV(3) < wdtAbrS(3)
            || wdtAbrS(4) < wdtAbrN(4)
            || wdtAbrV(4) < wdtAbrS(4)
            || wdtAbrS(5) < wdtAbrN(5)
            || wdtAbrV(5) < wdtAbrS(5)
        )
            ++bad;
        // every Table 18 row: the impact threshold shrinks with slipperiness
        // (non-slippery >= slightly slippery >= slippery)
    if (wdtImpS(0) > wdtImpN(0)
            || wdtImpV(0) > wdtImpS(0)
            || wdtImpS(1) > wdtImpN(1)
            || wdtImpV(1) > wdtImpS(1)
            || wdtImpS(2) > wdtImpN(2)
            || wdtImpV(2) > wdtImpS(2)
            || wdtImpS(3) > wdtImpN(3)
            || wdtImpV(3) > wdtImpS(3)
            || wdtImpS(4) > wdtImpN(4)
            || wdtImpV(4) > wdtImpS(4)
            || wdtImpS(5) > wdtImpN(5)
            || wdtImpV(5) > wdtImpS(5)
        )
            ++bad;
        printf("R438 WSG tumbling damage pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
