    // ---- R452 WSG diving and surfacing pin audit ----
    // The diving and surfacing slice pins the base downward swim rate (2
    // inches, 20 feet per round), the encumbrance multipliers (doubled for
    // moderate, tripled for heavy or severe - the same x2/x3/x3 the Table 24
    // dive column carries), the leap-height extra-depth ladder (at least
    // 5/15/25/35/40 feet -> 1/2/3/4/5 inches on the first round), the 5-inch
    // cap beyond 40 feet regardless of height, and the falling-damage risk on
    // a dive from 40 feet or more (rules/wsgdive.h, prefix wdv); census 376
    // -> 377.
    {
        using namespace rules;
        int bad = 0;
    if (wdvBaseDownRateIn() != 2
            || wdvBaseDownRateFt() != 20
            || wdvModEncMult() != 2
            || wdvHeavyEncMult() != 3
            || wdvLeapCapIn() != 5
            || wdvHighDiveMinFt() != 40
            || wdvLeapRowCount() != 5
            || !wdvModEncDoubled()
            || !wdvHeavyEncTripled()
            || !wdvLeapBoostsFirstRound()
            || !wdvLeapCappedBeyondForty()
            || !wdvHighDiveFallingDamage()
        )
            ++bad;
        // the leap-height extra-depth ladder: the five "at least" thresholds
        // (5, 15, 25, 35, 40 feet) each buying one more inch of first-round
        // depth (1, 2, 3, 4, 5) - the unnumbered printed-p. 42 table behind
        // the footnote
        int C42[5][2] = {
            {5,1},
            {15,2},
            {25,3},
            {35,4},
            {40,5},
            };
        for (int b = 0;
             b < wdvLeapRowCount();
             ++b) {
            int vals[2];
            vals[0] = wdvLeapFt(b);
            vals[1] = wdvExtraIn(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != C42[b][c])
                    ++bad;
            }
        }
        // the printed base rate: 2 inches downward, 20 feet per round, and
        // the feet are ten times the inches
    if (wdvBaseDownRateIn() != 2
            || wdvBaseDownRateFt() != 20
            || wdvBaseDownRateFt() != 10 * wdvBaseDownRateIn()
        )
            ++bad;
        // the encumbrance multipliers: doubled for moderate, tripled for
        // heavy or severe - one step up
    if (wdvModEncMult() != 2
            || wdvHeavyEncMult() != 3
            || wdvHeavyEncMult() != wdvModEncMult() + 1
        )
            ++bad;
        // the printed "at least" thresholds: 5, 15, 25, 35 and 40 feet of
        // leap height
    if (wdvLeapFt(0) != 5
            || wdvLeapFt(1) != 15
            || wdvLeapFt(2) != 25
            || wdvLeapFt(3) != 35
            || wdvLeapFt(4) != 40
        )
            ++bad;
        // the printed extra depths: one inch per rung of the ladder
    if (wdvExtraIn(0) != 1
            || wdvExtraIn(1) != 2
            || wdvExtraIn(2) != 3
            || wdvExtraIn(3) != 4
            || wdvExtraIn(4) != 5
        )
            ++bad;
        // the footnote anchors: the cap IS the top rung depth (5 inches at 40
        // feet), and the falling-damage threshold IS the top rung height
    if (wdvLeapCapIn() != wdvExtraIn(4)
            || wdvHighDiveMinFt() != wdvLeapFt(4)
        )
            ++bad;
        // the thresholds climb strictly: 5, 15, 25, 35, 40
    if (wdvLeapFt(0) >= wdvLeapFt(1)
            || wdvLeapFt(1) >= wdvLeapFt(2)
            || wdvLeapFt(2) >= wdvLeapFt(3)
            || wdvLeapFt(3) >= wdvLeapFt(4)
        )
            ++bad;
        // each rung buys exactly one more inch: the depths step 1, 2, 3, 4, 5
    if (wdvExtraIn(1) - wdvExtraIn(0) != 1
            || wdvExtraIn(2) - wdvExtraIn(1) != 1
            || wdvExtraIn(3) - wdvExtraIn(2) != 1
            || wdvExtraIn(4) - wdvExtraIn(3) != 1
        )
            ++bad;
        // the rung geometry: three 10-foot steps and the final 5-foot step to
        // 40
    if (wdvLeapFt(1) - wdvLeapFt(0) != 10
            || wdvLeapFt(2) - wdvLeapFt(1) != 10
            || wdvLeapFt(3) - wdvLeapFt(2) != 10
            || wdvLeapFt(4) - wdvLeapFt(3) != 5
        )
            ++bad;
        printf("R452 WSG diving and surfacing pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
