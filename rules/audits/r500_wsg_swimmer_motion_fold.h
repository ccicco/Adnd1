    // ---- R500 WSG swimmer motion fold audit ----
    // The WSG swimmer's motion-chain fold, the second seam round after gap
    // closure: no new book pages, the R499 pattern applied to the water
    // chapter. One swimmer state flows through five landed headers: the
    // swimming rates (rules/wsgswim.h R450: 40 feet base, the 2/3 subsurface
    // cut, the 2x high speed with the 1/10 endurance cut, the 3-per-turn rest
    // regain, the 1-3/4-6 inch current ranges), the dive leg (rules/wsgdive.h
    // R452: the 2 inch or 20 foot base, doubled moderate and tripled heavy),
    // the surfacing leg (rules/wsgbreath.h R454: the same 2 inch base, the 5
    // foot inert buoyancy rise), the moving-water hazards (rules/wsgmwater.h
    // R451: the 1-10 stream rating, the two-round hold cadence, the 40/100
    // foot waterfall thresholds, the half and tenth damage divisors) and the
    // treading economy (rules/wsgtread.h R453: 2 turns per endurance point, 1
    // round per strength point, the +1 check ladder). The findings: the
    // vertical rates equal each other and are half the horizontal base; the
    // Table 24 dive column matches the dive prose exactly; the encumbrance
    // paradox (the same weight that halves speed doubles the sink rate); the
    // forty-foot agreement between the dive falling-damage threshold and the
    // waterfall save threshold; and the two different cumulative check
    // ladders (+2 breath, +1 treading).
    {
        using namespace rules;
        int bad = 0;
    if (wmfSwimRateFt() != 40
            || wmfOtherRateFt() != 30
            || wmfSubsurfNum() != 2
            || wmfSubsurfDen() != 3
            || wmfHighSpeedMult() != 2
            || wmfHighSpeedEndDiv() != 10
            || wmfRestRegainPerTurn() != 3
            || wmfLightCurMaxIn() != 3
            || wmfStrongCurMinIn() != 4
            || wmfStrongCurMaxIn() != 6
            || wmfMercyDriftMaxIn() != 3
            || wmfDownRateIn() != 2
            || wmfDownRateFt() != 20
            || wmfDiveEncModMult() != 2
            || wmfDiveEncHeavyMult() != 3
            || wmfSurfRateIn() != 2
            || wmfInertRiseFt() != 5
            || wmfLeapCapIn() != 5
            || wmfStreamRateMin() != 1
            || wmfStreamRateMax() != 10
            || wmfHoldCheckPeriod() != 2
            || wmfWaterfallMinFt() != 40
            || wmfWaterfallMaxFt() != 100
            || wmfHighDiveMinFt() != 40
            || wmfFallDmgDiv() != 2
            || wmfLongFallDiv() != 10
            || wmfBreathConDiv() != 3
            || wmfMinBreathRounds() != 1
            || wmfPenaltyDiv() != 2
            || wmfBothPenaltyDiv() != 4
            || wmfConCheckStep() != 2
            || wmfBreathExampleRounds() != 4
            || wmfTreadTurnsPerEndPt() != 2
            || wmfTreadRoundsPerStrPt() != 1
            || wmfTreadCheckStep() != 1
            || wmfTreadExampleRounds() != 12
            || wmfEncMultUnenc() != 2
            || wmfSpdDenMod() != 2
            || wmfSpdDenHeavy() != 4
            || !wmfVerticalRatesEqual()
            || !wmfVerticalHalfHorizontal()
            || !wmfDiveGridMatchesProse()
            || !wmfEncumbranceParadox()
            || !wmfFortyFootAgreement()
            || !wmfMercyMatchesLightCur()
            || !wmfCheckStepsDiffer()
            || !wmfEconomiesDiffer()
            || !wmfSubsurfaceBeforeHighSpeed()
            || !wmfInertQuarterOfDeliberate()
        )
            ++bad;
        // the horizontal base rates
    if (wmfSwimRateFt() != 40
            || wmfOtherRateFt() != 30
            || wmfHighSpeedMult() != 2
            || wmfHighSpeedEndDiv() != 10
            || wmfRestRegainPerTurn() != 3
        )
            ++bad;
        // the vertical rates are equal - the first true alignment
    if (wmfDownRateIn() != wmfSurfRateIn()
        )
            ++bad;
        // the vertical base is half the horizontal base
    if (wmfSwimRateFt() / wmfDownRateFt() != 2
        )
            ++bad;
        // the Table 24 dive column matches the dive prose - doubled at
        // moderate, tripled at heavy and severe
    if (wmfDiveEncModMult() != 2
            || wmfDiveEncHeavyMult() != 3
        )
            ++bad;
        // the encumbrance paradox: the moderate speed denominator equals the
        // moderate dive multiplier
    if (wmfSpdDenMod() != wmfDiveEncModMult()
        )
            ++bad;
        // at heavy the grids diverge: quarter speed, triple sink
    if (wmfSpdDenHeavy() == wmfDiveEncHeavyMult()
        )
            ++bad;
        // the forty-foot agreement - the dive and waterfall thresholds are
        // the same value
    if (wmfHighDiveMinFt() != wmfWaterfallMinFt()
        )
            ++bad;
        // the save window spans sixty feet
    if (wmfWaterfallMaxFt() - wmfWaterfallMinFt() != 60
        )
            ++bad;
        // the mercy drift cap equals the light-current range
    if (wmfMercyDriftMaxIn() != wmfLightCurMaxIn()
        )
            ++bad;
        // the breath formula and penalties
    if (wmfBreathConDiv() * wmfBreathExampleRounds() != 12
            || wmfBothPenaltyDiv() != wmfPenaltyDiv() * 2
            || wmfMinBreathRounds() != 1
        )
            ++bad;
        // the check steps differ by one - the treading ladder is gentler than
        // the breath ladder
    if (wmfConCheckStep() - wmfTreadCheckStep() != 1
        )
            ++bad;
        // the treading example: strength 6 doubled by the unencumbered
        // endurance modifier
    if (wmfTreadExampleRounds() != 6 * wmfEncMultUnenc()
        )
            ++bad;
        // the stream rating and the hold cadence
    if (wmfStreamRateMax() - wmfStreamRateMin() != 9
            || wmfHoldCheckPeriod() != 2
        )
            ++bad;
        // the inert rise is one quarter of the deliberate rate
    if (wmfDownRateFt() / wmfInertRiseFt() != 4
        )
            ++bad;
        // the subsurface cut is two thirds
    if (wmfSubsurfDen() * 2 != wmfSubsurfNum() * 3
        )
            ++bad;
        // the leap cap matches the vertical base in inches
    if (wmfLeapCapIn() != wmfDownRateIn() + 3
        )
            ++bad;
        printf("R500 WSG swimmer motion fold audit: bad %d\n", bad);
        if (bad) return 1;
    }
