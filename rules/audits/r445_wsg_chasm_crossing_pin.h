    // ---- R445 WSG chasm crossing pin audit ----
    // The chasm-crossing slice pins the two anchor factors (a protrusion to
    // anchor on, an anchor that holds - the grappling hook answers both via
    // Table 20), the thrown-loop tactic (thief or rope-use proficient only,
    // target directly across or slightly above/below, never on a vertical
    // climb), Table 21 THROWN LOOP RANGES (40/50/60/75/90 feet by level
    // band), the 10-foot whirl-radius assumption with the halved range
    // otherwise, the 20% base hit chance with the +1% closeness bonus per
    // foot below maximum range, the halving conditions (moderate to heavy
    // precipitation, wind over 20 mph, hampered visibility), the
    // both-ends-anchored rule with the near-side protrusion requirement, and
    // the 30-feet-per-round hand-over-hand crossing rate with the +2
    // Dexterity check for multiple simultaneous hangers (rules/wsgchasm.h,
    // prefix wcx); census 369 -> 370.
    {
        using namespace rules;
        int bad = 0;
    if (wcxBaseHitPct() != 20
            || wcxClosenessBonusPerFt() != 1
            || wcxWhirlRadiusFt() != 10
            || wcxWindMphLimit() != 20
            || wcxCrossRateFtPerRound() != 30
            || wcxMultipleHangerDexMod() != 2
            || wcxLoopBandCount() != 5
            || !wcxTwoFactorsProtrusionAndHold()
            || !wcxGrapplingHookViaTable20()
            || !wcxLoopTargetAcrossOrSlightly()
            || !wcxLoopNeverOnVerticalClimb()
            || !wcxThiefOrRopeUseOnly()
            || !wcxNoWhirlRadiusHalvesRange()
            || !wcxBadConditionsHalveHit()
            || !wcxBothEndsMustBeAnchored()
            || !wcxOneAtATimePrudent()
            || !wcxMultiHangerDexCheck()
        )
            ++bad;
        // the Table 21 grid: the five level bands (1-4, 5-8, 9-12, 13-16,
        // 17+) x the maximum thrown-loop range in feet - 40/50/60/75/90, with
        // the 17+ band continuing beyond the table
        int C21[5][1] = {
            {40},
            {50},
            {60},
            {75},
            {90},
            };
        for (int b = 0;
             b < wcxLoopBandCount();
             ++b) {
            int vals[1];
            vals[0] = wcxMaxRangeFt(b);
            for (int c = 0; c < 1;
                 ++c) {
                if (vals[c] != C21[b][c])
                    ++bad;
            }
        }
        // the Table 21 ladder: 40/50/60/75/90 feet of maximum range across
        // the five level bands
    if (wcxMaxRangeFt(0) != 40
            || wcxMaxRangeFt(1) != 50
            || wcxMaxRangeFt(2) != 60
            || wcxMaxRangeFt(3) != 75
            || wcxMaxRangeFt(4) != 90
        )
            ++bad;
        // the hit formula: a 20% base chance with a +1% bonus per foot below
        // the maximum range
    if (wcxBaseHitPct() != 20
            || wcxClosenessBonusPerFt() != 1
        )
            ++bad;
        // the fog example, cross-multiplied: a 17th-level character (range
        // 90) at 50 feet has 20 + 40 = 60, halved by the fog to 30%
    if (wcxBaseHitPct() + (wcxMaxRangeFt(4) - 50) * wcxClosenessBonusPerFt()
        != 2 * 30
        )
            ++bad;
        // the whirl-radius halving: without the 10-foot radius the range is
        // half the given figure - the 1-4 band drops from 40 to 20 feet
    if (wcxMaxRangeFt(0) != 2 * 20
        )
            ++bad;
        // the crossing numbers: 30 feet per round hand-over-hand, the +2
        // Dexterity modifier for multiple hangers, the 20 mph wind limit and
        // the 10-foot whirling radius
    if (wcxCrossRateFtPerRound() != 30
            || wcxMultipleHangerDexMod() != 2
            || wcxWindMphLimit() != 20
            || wcxWhirlRadiusFt() != 10
        )
            ++bad;
        // the thrown-loop range is strictly increasing by level band -
        // experience extends the reach
    if (wcxMaxRangeFt(0) >= wcxMaxRangeFt(1)
            || wcxMaxRangeFt(1) >= wcxMaxRangeFt(2)
            || wcxMaxRangeFt(2) >= wcxMaxRangeFt(3)
            || wcxMaxRangeFt(3) >= wcxMaxRangeFt(4)
        )
            ++bad;
        // the top-band step: the range gains exactly 15 feet at each of the
        // top two bands (60 -> 75 -> 90)
    if (wcxMaxRangeFt(4) - wcxMaxRangeFt(3) != 15
            || wcxMaxRangeFt(3) - wcxMaxRangeFt(2) != 15
        )
            ++bad;
        // the 17+ band bound: 90 feet of thrown range - exactly three rounds
        // of the 30-feet-per-round hand-over-hand crossing
    if (wcxMaxRangeFt(4) != 3 * wcxCrossRateFtPerRound()
        )
            ++bad;
        printf("R445 WSG chasm crossing pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
