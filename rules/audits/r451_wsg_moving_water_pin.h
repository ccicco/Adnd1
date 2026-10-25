    // ---- R451 WSG moving water pin audit ----
    // The moving water slice pins the 1-10 stream hazard rating as the
    // proficiency-check cadence (rating 1 = every round, rating 5 = rounds 1,
    // 6, 11...), the 1d6 buffeting damage on a failed check, the virtually
    // helpless nonproficient swimmer at 1d3 damage per round, the
    // grab-a-protrusion halt (a Dex check, retried every round, then a
    // Strength check every two rounds to stay attached), and the waterfall
    // rules (half falling damage at 40 feet or more, the breath-weapon save
    // with no damage at 40-100 feet and one-tenth rounded up beyond 100, the
    // under-40 fall treated as a normal dive, and rocks at the base assessed
    // as a fall through the air) (rules/wsgmwater.h, prefix wmw); census 375
    // -> 376.
    {
        using namespace rules;
        int bad = 0;
    if (wmwStreamRateMin() != 1
            || wmwStreamRateMax() != 10
            || wmwBuffetDmgDie() != 6
            || wmwNonprofDmgDie() != 3
            || wmwHoldCheckPeriod() != 2
            || wmwFallDamageDiv() != 2
            || wmwFallSaveMinFt() != 40
            || wmwFallSaveMaxFt() != 100
            || wmwLongFallDiv() != 10
            || !wmwRatingIsCheckCadence()
            || !wmwBuffetingMechanism()
            || !wmwNonproficientHelpless()
            || !wmwGrabDexCheck()
            || !wmwGrabRetryEveryRound()
            || !wmwHoldStrengthCheck()
            || !wmwWaterfallSaveVsBreath()
            || !wmwSaveShortFallNoDamage()
            || !wmwSaveLongFallTenth()
            || !wmwShortFallTreatedAsDive()
            || !wmwRocksVoidMercy()
        )
            ++bad;
        // the printed hazard numbers: the 1-10 rating, the 1d6 buffeting
        // damage, the 1d3 nonproficient damage
    if (wmwStreamRateMin() != 1
            || wmwStreamRateMax() != 10
            || wmwBuffetDmgDie() != 6
            || wmwNonprofDmgDie() != 3
        )
            ++bad;
        // the waterfall numbers: the 40/100 foot thresholds, the one-half
        // base damage, the one-tenth saved damage beyond 100 feet
    if (wmwFallSaveMinFt() != 40
            || wmwFallSaveMaxFt() != 100
            || wmwFallDamageDiv() != 2
            || wmwLongFallDiv() != 10
        )
            ++bad;
        // the waterfall arithmetic anchor: the long threshold is twice the
        // short plus twenty, and the saved long divisor is five times the
        // unsaved short divisor
    if (wmwFallSaveMaxFt() != 2 * wmwFallSaveMinFt() + 20
            || wmwLongFallDiv() != 5 * wmwFallDamageDiv()
        )
            ++bad;
        // the two-round strength cadence, and the buffeting die is twice the
        // nonproficient die
    if (wmwHoldCheckPeriod() != 2
            || wmwBuffetDmgDie() != 2 * wmwNonprofDmgDie()
        )
            ++bad;
        // a real rating range, real damage dice and a real hold cadence - all
        // positive
    if (wmwStreamRateMax() <= wmwStreamRateMin()
            || wmwBuffetDmgDie() <= 0
            || wmwNonprofDmgDie() <= 0
            || wmwHoldCheckPeriod() <= 0
        )
            ++bad;
        // the ladder is sane: the saved long fall takes a smaller fraction
        // (one-tenth) than the unsaved short fall (one-half), over a higher
        // threshold
    if (wmwFallSaveMaxFt() <= wmwFallSaveMinFt()
            || wmwLongFallDiv() <= wmwFallDamageDiv()
        )
            ++bad;
        printf("R451 WSG moving water pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
