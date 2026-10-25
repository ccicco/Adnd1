    // ---- R447 WSG slippery surface movement pin audit ----
    // The slippery surface slice pins the full-rate straight-line rule (no
    // fall risk in a straight line at the full normal movement rate), the
    // Dexterity Check on anything other than a very gradual turn or an abrupt
    // stop or speed-up, the running rule (a Dexterity Check after every five
    // segments of running, even in a straight line), the half-rate exemption
    // (turns need no check at half the full normal movement rate), the
    // full-round speed-change exemption (a full round to slow down or speed
    // up, full movement to standstill or vice versa, needs no check), and the
    // fall consequence (no direct damage, only an indirect cause of greater
    // problems) (rules/wsgslip.h, prefix wsl); census 371 -> 372.
    {
        using namespace rules;
        int bad = 0;
    if (wslRunCheckSegs() != 5
            || wslCautiousRateDiv() != 2
            || !wslCautionRisksFall()
            || !wslStraightFullRateSafe()
            || !wslAbruptChangeNeedsDexCheck()
            || !wslRunCheckEvenStraight()
            || !wslFullRoundSpeedChangeFree()
            || !wslFallNoDirectDamage()
        )
            ++bad;
        // the printed pair: the five-segment running check cadence, and the
        // cautious rate that halves the movement
    if (wslRunCheckSegs() != 5
            || wslCautiousRateDiv() != 2
        )
            ++bad;
        // the slippery arithmetic anchor: two five-segment running checks
        // span ten segments, and ten is the cadence times the halving divisor
    if (wslRunCheckSegs() * wslCautiousRateDiv() != 10
        )
            ++bad;
        // a real cadence (positive segments) and a divisor that actually
        // halves the rate
    if (wslRunCheckSegs() <= 0
            || wslCautiousRateDiv() <= 1
        )
            ++bad;
        // the printed pair again - both digits exactly as the book prints
        // them
    if (wslRunCheckSegs() != 5
            || wslCautiousRateDiv() != 2
        )
            ++bad;
        printf("R447 WSG slippery surface movement pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
