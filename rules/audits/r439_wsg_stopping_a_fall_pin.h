    // ---- R439 WSG stopping a fall pin audit ----
    // The stopping-a-fall slice pins Table 19 (the four surface rows x the
    // three condition stop fractions, the cliff slippery dash as the 0/0
    // no-chance sentinel) with the fraction-of-rating reading, the
    // one-attempt-only rule, the 50/75/100-foot attempt windows, the
    // protrusion requirement on cliff and severe, the slope-self-halt rule on
    // moderate and gentle, the damage-still-applies rule and the
    // halt-before-damage possibility (rules/wsgstop.h, prefix wsf); census
    // 363 -> 364.
    {
        using namespace rules;
        int bad = 0;
    if (wsfSurfaceCount() != 4
            || wsfAttemptCliffSevereFt() != 50
            || wsfAttemptModerateFt() != 75
            || wsfAttemptGentleFt() != 100
            || !wsfChanceIsFractionOfRating()
            || !wsfOneAttemptOnly()
            || !wsfProtrusionRequired()
            || !wsfSlopeSelfHalt()
            || !wsfTooLateAfterWindow()
            || !wsfStopStillTakesDamage()
            || !wsfCanHaltBeforeDamage()
            || !wsfAnnounceOrAutomatic()
            || !wsfHandsMustBeFree()
            || !wsfGentleEasierThanFreeFall()
        )
            ++bad;
        // the Table 19 grid: the four surface rows (the gentle, moderate and
        // severe slopes and the cliff face) x the three condition stop
        // fractions, each encoded as its numerator and denominator (the cliff
        // slippery dash = 0/0, no chance at all)
        int C19[4][6] = {
            {7,3,2,8,4,3},
            {3,2,1,4,3,2},
            {2,1,1,3,2,4},
            {1,1,0,2,4,0},
            };
        for (int b = 0;
             b < wsfSurfaceCount();
             ++b) {
            int vals[6];
            vals[0] = wsfNumN(b);
            vals[1] = wsfNumS(b);
            vals[2] = wsfNumV(b);
            vals[3] = wsfDenN(b);
            vals[4] = wsfDenS(b);
            vals[5] = wsfDenV(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != C19[b][c])
                    ++bad;
            }
        }
        // the range of Table 19: the gentle non-slippery 7/8 chance at the
        // top, the cliff non-slippery 1/2 at the bottom
    if (wsfNumN(0) != 7
            || wsfDenN(0) != 8
            || wsfNumN(3) != 1
            || wsfDenN(3) != 2
        )
            ++bad;
        // the cliff face slippery cell is the printed dash - no chance of
        // stopping at all, encoded as the 0/0 sentinel
    if (wsfNumV(3) != 0
            || wsfDenV(3) != 0
        )
            ++bad;
        // the attempt windows: within the first 50 feet from a cliff or
        // severe slope, 75 feet down a moderate slope, 100 feet down a gentle
        // slope (the two steps are 25 feet each)
    if (wsfAttemptCliffSevereFt() != 50
            || wsfAttemptModerateFt() - wsfAttemptCliffSevereFt() != 25
            || wsfAttemptGentleFt() - wsfAttemptModerateFt() != 25
        )
            ++bad;
        // the fraction-of-rating reading, written cross-multiplied: a 60
        // percent Climbing Rating on a moderate non-slippery slope stops 3/4
        // of 60 = 45 percent of the time
    if (wsfNumN(1) * 60 != 45 * wsfDenN(1)
        )
            ++bad;
        // every Table 19 row: the stop chance shrinks with slipperiness
        // (written as cross-multiplied comparisons, division-free)
    if (wsfNumN(0) * wsfDenS(0) < wsfNumS(0) * wsfDenN(0)
            || wsfNumS(0) * wsfDenV(0) < wsfNumV(0) * wsfDenS(0)
            || wsfNumN(1) * wsfDenS(1) < wsfNumS(1) * wsfDenN(1)
            || wsfNumS(1) * wsfDenV(1) < wsfNumV(1) * wsfDenS(1)
            || wsfNumN(2) * wsfDenS(2) < wsfNumS(2) * wsfDenN(2)
            || wsfNumS(2) * wsfDenV(2) < wsfNumV(2) * wsfDenS(2)
            || wsfNumN(3) * wsfDenS(3) < wsfNumS(3) * wsfDenN(3)
            || wsfNumS(3) * wsfDenV(3) < wsfNumV(3) * wsfDenS(3)
        )
            ++bad;
        // the four Table 19 rows: the stop chance shrinks from the gentle
        // slope down to the cliff face in every condition (cross-multiplied,
        // division-free)
    if (wsfNumN(0) * wsfDenN(1) < wsfNumN(1) * wsfDenN(0)
            || wsfNumS(0) * wsfDenS(1) < wsfNumS(1) * wsfDenS(0)
            || wsfNumN(1) * wsfDenN(2) < wsfNumN(2) * wsfDenN(1)
            || wsfNumS(1) * wsfDenS(2) < wsfNumS(2) * wsfDenS(1)
            || wsfNumN(2) * wsfDenN(3) < wsfNumN(3) * wsfDenN(2)
            || wsfNumS(2) * wsfDenS(3) < wsfNumS(3) * wsfDenS(2)
        )
            ++bad;
        printf("R439 WSG stopping a fall pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
