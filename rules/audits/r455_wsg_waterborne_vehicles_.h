    // ---- R455 WSG waterborne vehicles pin audit ----
    // The waterborne vehicles slice pins Table 25 (the eight inland vessels -
    // kayak through large barge - across length, width, the
    // passenger-plus-gold capacity, the four large-scale miles-per-half-day
    // and four small-scale feet-per-round rates, the encumbrance ranges with
    // the large barge open 10000+, the startup and hull ranges, and the
    // draughts) and the modifications to movement (the downstream add and
    // upstream subtract of the current, the 20-to-30 wind band with the
    // minus-1 and plus-2 steps per 10 mph, the 5 mph no-sail floor, the
    // right-angle maximum sail, the into-wind 3-inch reduction to the 1-inch
    // minimum, the two-turns-on one-turn-off max-oar exertion with the
    // fatigued half speed and the forced one-turn exhaustion, and the
    // shorthanded proportionate rowing per the 3-rowers large-rowboat
    // example) (rules/wsgvessels.h, prefix wvb); census 379 -> 380.
    {
        using namespace rules;
        int bad = 0;
    if (wvbVesselCount() != 8
            || wvbWindBandMin() != 20
            || wvbWindBandMax() != 30
            || wvbWindLowStep() != 1
            || wvbWindHighStep() != 2
            || wvbInchPerHalfDayMiles() != 1
            || wvbInchPerRoundFt() != 10
            || wvbMinSailWind() != 5
            || wvbIntoWindStep() != 3
            || wvbIntoWindMinIn() != 1
            || wvbMaxOarEffortTurns() != 2
            || wvbMaxOarRestTurns() != 1
            || wvbFatiguedSpeedDiv() != 2
            || wvbFatiguedExhaustTurns() != 1
            || wvbExRowers() != 3
            || wvbExNormalOarMiles() != 6
            || wvbExMaxOarFt() != 45
            || !wvbInlandVesselsOnly()
            || !wvbLoadDistributedEvenly()
            || !wvbMaxOarLowGainRationale()
            || !wvbDraughtHullDamageRisk()
            || !wvbProficiencyAssumed()
            || !wvbCurrentDrift()
            || !wvbCurrentAddsDownstream()
            || !wvbCurrentSubtractsUpstream()
            || !wvbSailAssumesWindDirection()
            || !wvbNoSailBelowMinWind()
            || !wvbMaxSailRightAngles()
            || !wvbIntoWindReduced()
            || !wvbMaxOarStrenuous()
            || !wvbFatiguedHalfSpeed()
            || !wvbFatiguedForcedExhaust()
            || !wvbShorthandedProportional()
        )
            ++bad;
        // the Table 25a grid, the static characteristics: the eight inland
        // vessels (kayak, small canoe, small rowboat, coracle, large canoe,
        // large rowboat, small barge, large barge) x the fourteen columns -
        // the length and width ranges, the passenger and gold-piece capacity,
        // the encumbrance range (a 0 maximum marks the large barge open-ended
        // 10000+), the startup and hull-value ranges, and the draught split
        // into numerator and denominator
        int C25a[8][14] = {
            {8,12,2,3,1,1000,600,800,1,2,1,2,1,4},
            {10,15,2,3,2,2500,700,900,1,2,1,2,1,4},
            {8,12,2,4,2,2000,700,1000,1,3,1,3,1,2},
            {10,15,3,5,2,2000,900,1200,1,3,1,2,1,2},
            {15,20,2,3,2,4000,1000,1200,1,3,2,3,1,3},
            {15,20,3,4,4,4000,1200,1600,2,5,2,4,3,4},
            {15,20,8,12,4,6000,4000,6000,2,6,1,6,3,4},
            {25,45,12,20,6,7500,10000,0,5,10,2,8,1,1},
            };
        for (int b = 0;
             b < wvbVesselCount();
             ++b) {
            int vals[14];
            vals[0] = wvbLenMin(b);
            vals[1] = wvbLenMax(b);
            vals[2] = wvbWidMin(b);
            vals[3] = wvbWidMax(b);
            vals[4] = wvbCapPax(b);
            vals[5] = wvbCapGp(b);
            vals[6] = wvbEncMin(b);
            vals[7] = wvbEncMax(b);
            vals[8] = wvbSuMin(b);
            vals[9] = wvbSuMax(b);
            vals[10] = wvbHullMin(b);
            vals[11] = wvbHullMax(b);
            vals[12] = wvbDrNum(b);
            vals[13] = wvbDrDen(b);
            for (int c = 0; c < 14;
                 ++c) {
                if (vals[c] != C25a[b][c])
                    ++bad;
            }
        }
        // the Table 25b grid, the movement rates: the same eight vessels x
        // the eight rate columns - the four large-scale miles-per-half-day
        // figures (normal sail, maximum sail, normal oar, maximum oar) and
        // the four small-scale feet-per-round figures under the same four
        // propulsions
        int C25b[8][8] = {
            {18,24,12,14,160,200,120,180},
            {20,30,10,12,160,200,120,180},
            {16,24,12,14,120,180,90,120},
            {12,18,6,8,45,60,30,45},
            {20,30,10,12,120,180,90,120},
            {16,24,8,10,45,90,45,60},
            {16,24,8,9,45,60,30,45},
            {8,16,4,5,30,60,20,30},
            };
        for (int b = 0;
             b < wvbVesselCount();
             ++b) {
            int vals[8];
            vals[0] = wvbLgSailN(b);
            vals[1] = wvbLgSailM(b);
            vals[2] = wvbLgOarN(b);
            vals[3] = wvbLgOarM(b);
            vals[4] = wvbSmSailN(b);
            vals[5] = wvbSmSailM(b);
            vals[6] = wvbSmOarN(b);
            vals[7] = wvbSmOarM(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != C25b[b][c])
                    ++bad;
            }
        }
        // the wind band and steps: 20 to 30 mph assumed, minus 1 inch per 10
        // mph below, plus 2 inches per 10 mph above
    if (wvbWindBandMin() != 20
            || wvbWindBandMax() != 30
            || wvbWindLowStep() != 1
            || wvbWindHighStep() != 2
            || wvbWindHighStep() != 2 * wvbWindLowStep()
        )
            ++bad;
        // the sail floors and conversions: no sailing under 5 mph, the
        // 3-inch-per-10-mph into-wind reduction to the 1-inch minimum, and
        // the inch as 1 mile per half-day or 10 feet per round
    if (wvbMinSailWind() != 5
            || wvbIntoWindStep() != 3
            || wvbIntoWindMinIn() != 1
            || wvbInchPerHalfDayMiles() != 1
            || wvbInchPerRoundFt() != 10
        )
            ++bad;
        // the printed shorthanded example: three of the large rowboat four,
        // cross-multiplied - 6 miles is three-quarters of the 8-mile
        // normal-oar figure and 45 feet is three-quarters of the 60-foot
        // maximum-oar figure
    if (wvbExRowers() != 3
            || wvbExNormalOarMiles() != 6
            || wvbExMaxOarFt() != 45
            || wvbExNormalOarMiles() * wvbCapPax(5) != wvbExRowers() *
            wvbLgOarN(5)
            || wvbExMaxOarFt() * wvbCapPax(5) != wvbExRowers() * wvbSmOarM(5)
        )
            ++bad;
        // the exertion ladder: two turns of maximum oar, one turn of rest,
        // the fatigued half speed, the one-turn forced exhaustion
    if (wvbMaxOarEffortTurns() != 2
            || wvbMaxOarRestTurns() != 1
            || wvbFatiguedSpeedDiv() != 2
            || wvbFatiguedExhaustTurns() != 1
        )
            ++bad;
        // the maximum-rate spot checks: the kayak 24, the small canoe 30, the
        // coracle 18, the large barge 16 large-scale and 5 large-oar / 30
        // small-oar
    if (wvbLgSailM(0) != 24
            || wvbLgSailM(1) != 30
            || wvbLgSailM(3) != 18
            || wvbLgSailM(7) != 16
            || wvbLgOarM(7) != 5
            || wvbSmOarM(7) != 30
        )
            ++bad;
        // the kayak and the small canoe share the same small-scale movement
        // rates: 160/200/120/180
    if (wvbSmSailN(0) != wvbSmSailN(1)
            || wvbSmSailM(0) != wvbSmSailM(1)
            || wvbSmOarN(0) != wvbSmOarN(1)
            || wvbSmOarM(0) != wvbSmOarM(1)
        )
            ++bad;
        // the small rowboat and the large canoe share the same small-scale
        // movement rates: 120/180/90/120
    if (wvbSmSailN(2) != wvbSmSailN(4)
            || wvbSmSailM(2) != wvbSmSailM(4)
            || wvbSmOarN(2) != wvbSmOarN(4)
            || wvbSmOarM(2) != wvbSmOarM(4)
        )
            ++bad;
        // the maximum rates always strictly beat the normal rates, in both
        // scales
    if (wvbLgSailM(0) <= wvbLgSailN(0)
            || wvbLgSailM(7) <= wvbLgSailN(7)
            || wvbSmSailM(4) <= wvbSmSailN(4)
            || wvbSmOarM(5) <= wvbSmOarN(5)
        )
            ++bad;
        // the large barge encumbrance is open-ended: a 0 maximum sentinel
        // over the 10000 minimum, and the minimum clears every bounded vessel
        // maximum
    if (wvbEncMax(7) != 0
            || wvbEncMin(7) != 10000
            || wvbEncMin(7) <= wvbEncMax(6)
        )
            ++bad;
        // the draughts: the kayak quarter-foot, the small rowboat half, the
        // large rowboat and small barge three-quarters, the large canoe
        // third, and the large barge the whole foot
    if (wvbDrNum(0) != 1
            || wvbDrDen(0) != 4
            || wvbDrNum(5) != 3
            || wvbDrDen(5) != 4
            || wvbDrNum(7) != 1
            || wvbDrDen(7) != 1
            || wvbDrNum(4) != 1
            || wvbDrDen(4) != 3
            || wvbDrNum(2) != 1
            || wvbDrDen(2) != 2
        )
            ++bad;
        printf("R455 WSG waterborne vehicles pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
