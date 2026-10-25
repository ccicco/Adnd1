    // ---- R441 WSG roping-together pin audit ----
    // The roping-together slice pins the adjacent-recheck rule (even after a
    // successful check earlier in the same round), the end/middle faller
    // rules, the -10%-per-extra-faller cascade penalty ladder
    // (0/10/20/30/40), the last-pair extra check and the
    // 50-feet-per-character tie capacity (rules/wsgtog.h, prefix wrp); census
    // 365 -> 366.
    {
        using namespace rules;
        int bad = 0;
    if (wrpTieTwoCharFt() != 50
            || wrpExtraCharPerFt() != 50
            || wrpCascadeStepPct() != 10
            || wrpExamplePartySize() != 5
            || wrpExampleRopeFt() != 200
            || !wrpAdjacentMustRecheck()
            || !wrpEndFallerOneAdjacent()
            || !wrpMiddleFallerBothSides()
            || !wrpCascadeUntilHaltOrAll()
            || !wrpLastPairSingleSuccessExtra()
        )
            ++bad;
        // the tie capacity: a 50-foot rope ties two characters, one more per
        // additional 50 feet
    if (wrpTieTwoCharFt() != 50
            || wrpExtraCharPerFt() != 50
        )
            ++bad;
        // the example party: five roped characters need (5-1) x 50 = 200 feet
        // of rope - the 200-foot rope of the example
    if ((wrpExamplePartySize() - 1) * wrpExtraCharPerFt() !=
        wrpExampleRopeFt()
        )
            ++bad;
        // the cascade ladder: one fallen 0, two fallen -10%, three -20%, four
        // -30%, five -40%
    if (wrpCascadePenaltyPct(0) != 0
            || wrpCascadePenaltyPct(1) != 10
            || wrpCascadePenaltyPct(2) != 20
            || wrpCascadePenaltyPct(3) != 30
            || wrpCascadePenaltyPct(4) != 40
        )
            ++bad;
        // the example first step: with two fallen (one beyond the first) the
        // third character checks at the -10% step
    if (wrpCascadePenaltyPct(1) != wrpCascadeStepPct()
        )
            ++bad;
        // the example deep cells: three fallen - the -20% checks of the first
        // and fifth characters; four fallen - the -30% final check
    if (wrpCascadePenaltyPct(2) != 2 * wrpCascadeStepPct()
            || wrpCascadePenaltyPct(3) != 3 * wrpCascadeStepPct()
        )
            ++bad;
        // the cascade penalty is strictly increasing, one step per fallen
        // character
    if (wrpCascadePenaltyPct(0) >= wrpCascadePenaltyPct(1)
            || wrpCascadePenaltyPct(1) >= wrpCascadePenaltyPct(2)
            || wrpCascadePenaltyPct(2) >= wrpCascadePenaltyPct(3)
            || wrpCascadePenaltyPct(3) >= wrpCascadePenaltyPct(4)
        )
            ++bad;
        // the cascade steps are constant: every extra fallen character adds
        // exactly one -10% step
    if (wrpCascadePenaltyPct(2) - wrpCascadePenaltyPct(1) !=
        wrpCascadePenaltyPct(1) - wrpCascadePenaltyPct(0)
            || wrpCascadePenaltyPct(3) - wrpCascadePenaltyPct(2) !=
            wrpCascadeStepPct()
        )
            ++bad;
        printf("R441 WSG roping-together pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
