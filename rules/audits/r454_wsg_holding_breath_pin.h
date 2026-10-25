    // ---- R454 WSG holding breath pin audit ----
    // The holding one breath slice pins the surfacing rate (2 inches, doubled
    // unencumbered, needing active work - the inert body rising by natural
    // buoyancy at one-half inch, 5 feet per round), the non-cumulative
    // diving-bonus note (the extra depth added after encumbrance, per the
    // 6-inch moderately-encumbered 15-foot example), the breath formula
    // (one-third of constitution in rounds, rounded up, assuming a deep
    // breath and no strenuous activity), the halved penalties for being
    // unprepared or fighting (cumulative to one-fourth, with the one-round
    // floor), the expiration rules (a Constitution Check once per round,
    // cumulative +2 after the first, per the con-12/4-round example), the
    // out-of-air unconsciousness with the pulled-to-surface requirement, the
    // not-underwater one-round addition with the penalties applied after, and
    // the hold-before-affected gas rules (rules/wsgbreath.h, prefix whb);
    // census 378 -> 379.
    {
        using namespace rules;
        int bad = 0;
    if (whbBaseSurfRateIn() != 2
            || whbInertRiseNum() != 1
            || whbInertRiseDen() != 2
            || whbInertRiseFt() != 5
            || whbBreathConDiv() != 3
            || whbPenaltyDiv() != 2
            || whbBothPenaltyDiv() != 4
            || whbMinBreathRounds() != 1
            || whbConCheckStep() != 2
            || whbExampleCon() != 12
            || whbExampleRounds() != 4
            || whbExampleFirstCheckRound() != 5
            || whbNotUwBonusRounds() != 1
            || !whbSurfaceRateNeedsWork()
            || !whbInertBuoyancyRise()
            || !whbDeliberateEncumbranceTrick()
            || !whbLeapBonusNotCumulative()
            || !whbDeepBreathAssumed()
            || !whbNormalMovementAllowed()
            || !whbUnpreparedHalved()
            || !whbStrenuousHalved()
            || !whbPenaltiesCumulative()
            || !whbAtLeastOneRound()
            || !whbConCheckOncePerRound()
            || !whbChecksCumulativePlusTwo()
            || !whbNonswimmerBuoyancyOnly()
            || !whbOutOfAirUnconscious()
            || !whbNotUwOneRoundAdded()
            || !whbNotUwPenaltiesAfterBonus()
            || !whbGasHoldBeforeAffected()
            || !whbSmallDoseFullHarm()
        )
            ++bad;
        // the printed formula numbers: the one-third constitution base, the
        // halved penalties, and the cumulative one-fourth when both apply
    if (whbBreathConDiv() != 3
            || whbPenaltyDiv() != 2
            || whbBothPenaltyDiv() != 4
            || whbBothPenaltyDiv() != whbPenaltyDiv() * whbPenaltyDiv()
        )
            ++bad;
        // the printed example: constitution 12 holds breath 4 rounds -
        // one-third exactly - and the first Constitution Check comes at the
        // end of the 5th round, one round past the limit
    if (whbExampleCon() != 12
            || whbExampleRounds() != 4
            || whbExampleRounds() * whbBreathConDiv() != whbExampleCon()
            || whbExampleFirstCheckRound() != whbExampleRounds() + 1
        )
            ++bad;
        // the floors and steps: the one-round breath floor, the cumulative +2
        // check step, the one-round not-underwater addition
    if (whbMinBreathRounds() != 1
            || whbConCheckStep() != 2
            || whbNotUwBonusRounds() != 1
            || whbConCheckStep() != 2 * whbNotUwBonusRounds()
        )
            ++bad;
        // the surfacing numbers: the 2-inch base rate, the half-inch
        // (numerator 1 over denominator 2) inert buoyancy carrying 5 feet per
        // round, and the inert feet-denominator product matching the 10 feet
        // a full base rate covers
    if (whbBaseSurfRateIn() != 2
            || whbInertRiseNum() != 1
            || whbInertRiseDen() != 2
            || whbInertRiseFt() != 5
            || whbInertRiseDen() * whbInertRiseFt() != 10
            || whbBaseSurfRateIn() != whbInertRiseDen() * whbInertRiseNum()
        )
            ++bad;
        printf("R454 WSG holding breath pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
