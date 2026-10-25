    // ---- R435 WSG climbing pin audit ----
    // The climbing slice pins Table 15 (the 13 surface rows x the three
    // condition rates in feet per round for a thief with the per-cell
    // thief-or-mountaineering restrictions), the climbing prose (the half
    // rate, the dex adjustment, the no-tools assumption), the encumbrance
    // modifications, the surface types and conditions and the
    // chance-of-falling rating (rules/wsgclimb.h, prefix wcs); census 359 ->
    // 360.
    {
        using namespace rules;
        int bad = 0;
    if (wcsSurfaceCount() != 13
            || wcsSlopeRowBase() != 0
            || wcsCliffRowBase() != 9
            || wcsGentleMinDeg() != 15
            || wcsGentleMaxDeg() != 30
            || wcsGentleRiseMin() != 2
            || wcsGentleRiseMax() != 5
            || wcsModerateMinDeg() != 31
            || wcsModerateMaxDeg() != 50
            || wcsModerateRiseMax() != 12
            || wcsSevereMinDeg() != 51
            || wcsSevereMaxDeg() != 70
            || wcsSevereRiseMax() != 35
            || wcsCliffMinDeg() != 71
            || wcsHorizontalDist() != 10
            || wcsNonThiefRating() != 40
            || wcsMountaineerRating() != 80
            || wcsFallBase() != 100
            || !wcsRateFeetPerRound()
            || !wcsAllCharactersCanClimb()
            || !wcsNonThievesHalfRate()
            || !wcsDexAdjustmentApplies()
            || !wcsNoSpecialToolsAssumed()
            || !wcsHandholdsAssumed()
            || !wcsGentleNonslipAidsOptional()
            || !wcsThievesOnlyDevoidSurfaces()
            || !wcsRestrictedThiefOrMountaineer()
            || !wcsSevereEncGentleOnlyHalf()
            || !wcsHeavyModerateEncGentleModerateHalf()
            || !wcsLightEncAnySlopeFull()
            || !wcsCliffRequiresUnencumbered()
            || !wcsUnderFifteenNotSlope()
            || !wcsOverhangSameRules()
            || !wcsFallIs100MinusRating()
            || !wcsThiefRatingIsClimbWalls()
            || !wcsMountaineer80RestrictedOnly()
            || !wcsCheckRollUnderOrEqual()
        )
            ++bad;
        // the Table 15 grid: the 13 surface rows (the rough, normal and
        // smooth slopes at the gentle, moderate and severe tilts, then the
        // cliff faces by roughness and ledges) x the three condition rates
        // and the three restricted flags
        int C15[13][6] = {
            {90,60,30,0,0,0},
            {80,50,25,0,0,0},
            {60,40,20,0,0,0},
            {80,45,25,0,0,0},
            {60,30,15,0,0,0},
            {50,20,5,0,0,1},
            {60,30,15,0,0,0},
            {40,20,10,0,1,1},
            {20,10,5,1,1,1},
            {25,15,5,1,1,1},
            {15,10,5,1,1,1},
            {15,10,5,1,1,1},
            {10,5,5,1,1,1},
            };
        for (int b = 0;
             b < wcsSurfaceCount();
             ++b) {
            int vals[6];
            vals[0] = wcsRateN(b);
            vals[1] = wcsRateS(b);
            vals[2] = wcsRateV(b);
            vals[3] = wcsResN(b);
            vals[4] = wcsResS(b);
            vals[5] = wcsResV(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != C15[b][c])
                    ++bad;
            }
        }
        // the rough gentle slope row: 90/60/30 feet per round - the fastest
        // climb in the table, all three cells unrestricted
    if (wcsRateN(0) != 90
            || wcsRateS(0) != 60
            || wcsRateV(0) != 30
        )
            ++bad;
        // the normal slope severe row: only the slippery 5 cell is asterisked
        // (a thief or a mountaineering-proficient character with tools)
    if (wcsResV(5) != 1
            || wcsResN(5) != 0
            || wcsResS(5) != 0
        )
            ++bad;
        // the cliff rows: the rough with-ledges 25 is the best cliff rate,
        // the smooth no-ledges row ends at 5, and every cliff cell is
        // restricted
    if (wcsRateN(9) != 25
            || wcsRateV(12) != 5
            || wcsResN(12) != 1
        )
            ++bad;
        // the unmodified non-thief falls 60 percent of the time (100 minus
        // the 40 percent rating)
    if (wcsFallBase() - wcsNonThiefRating() != 60
        )
            ++bad;
        // the degree bands: gentle 15 through 30, and the cliff begins past
        // 70 degrees
    if (wcsGentleMinDeg() != 15
            || wcsGentleMaxDeg() != 30
            || wcsCliffMinDeg() != 71
        )
            ++bad;
        // every Table 15 row is ordered: non-slippery >= slightly slippery >=
        // slippery
    if (wcsRateS(0) > wcsRateN(0)
            || wcsRateV(0) > wcsRateS(0)
            || wcsRateS(1) > wcsRateN(1)
            || wcsRateV(1) > wcsRateS(1)
            || wcsRateS(2) > wcsRateN(2)
            || wcsRateV(2) > wcsRateS(2)
            || wcsRateS(3) > wcsRateN(3)
            || wcsRateV(3) > wcsRateS(3)
            || wcsRateS(4) > wcsRateN(4)
            || wcsRateV(4) > wcsRateS(4)
            || wcsRateS(5) > wcsRateN(5)
            || wcsRateV(5) > wcsRateS(5)
            || wcsRateS(6) > wcsRateN(6)
            || wcsRateV(6) > wcsRateS(6)
            || wcsRateS(7) > wcsRateN(7)
            || wcsRateV(7) > wcsRateS(7)
            || wcsRateS(8) > wcsRateN(8)
            || wcsRateV(8) > wcsRateS(8)
            || wcsRateS(9) > wcsRateN(9)
            || wcsRateV(9) > wcsRateS(9)
            || wcsRateS(10) > wcsRateN(10)
            || wcsRateV(10) > wcsRateS(10)
            || wcsRateS(11) > wcsRateN(11)
            || wcsRateV(11) > wcsRateS(11)
            || wcsRateS(12) > wcsRateN(12)
            || wcsRateV(12) > wcsRateS(12)
        )
            ++bad;
        // the restricted flags are monotone: a restricted non-slippery cell
        // implies the restricted slightly slippery cell implies the
        // restricted slippery cell
    if (wcsResS(0) < wcsResN(0)
            || wcsResV(0) < wcsResS(0)
            || wcsResS(1) < wcsResN(1)
            || wcsResV(1) < wcsResS(1)
            || wcsResS(2) < wcsResN(2)
            || wcsResV(2) < wcsResS(2)
            || wcsResS(3) < wcsResN(3)
            || wcsResV(3) < wcsResS(3)
            || wcsResS(4) < wcsResN(4)
            || wcsResV(4) < wcsResS(4)
            || wcsResS(5) < wcsResN(5)
            || wcsResV(5) < wcsResS(5)
            || wcsResS(6) < wcsResN(6)
            || wcsResV(6) < wcsResS(6)
            || wcsResS(7) < wcsResN(7)
            || wcsResV(7) < wcsResS(7)
            || wcsResS(8) < wcsResN(8)
            || wcsResV(8) < wcsResS(8)
            || wcsResS(9) < wcsResN(9)
            || wcsResV(9) < wcsResS(9)
            || wcsResS(10) < wcsResN(10)
            || wcsResV(10) < wcsResS(10)
            || wcsResS(11) < wcsResN(11)
            || wcsResV(11) < wcsResS(11)
            || wcsResS(12) < wcsResN(12)
            || wcsResV(12) < wcsResS(12)
        )
            ++bad;
        printf("R435 WSG climbing pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
