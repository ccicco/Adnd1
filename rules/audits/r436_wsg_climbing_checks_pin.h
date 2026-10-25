    // ---- R436 WSG climbing checks pin audit ----
    // The climbing-checks slice pins Table 16 (the 13 surface rows x the
    // three condition modifiers to the non-thief Climbing Rating) with the
    // 100 percent no-fall and 5 percent floor rules, the other modifiers (the
    // encumbrance, race, armor, strength and hands rules), the thief
    // modifiers (the +30 auto rule, the double and quadruple falling chances)
    // and the initial, intermediate and final check rules (rules/wsgcheck.h,
    // prefix wck); census 360 -> 361.
    {
        using namespace rules;
        int bad = 0;
    if (wckSurfaceCount() != 13
            || wckNoFallRating() != 100
            || wckMinRatingFloor() != 5
            || wckThiefAutoThreshold() != 30
            || wckThiefFallMultSlightly() != 2
            || wckThiefFallMultSlippery() != 4
            || wckThiefScoreFloor() != 5
            || wckEncModeratePenalty() != 5
            || wckEncHeavyPenalty() != 10
            || wckEncSeverePenalty() != 20
            || wckDwarfPenalty() != 5
            || wckGnomePenalty() != 10
            || wckHalflingPenalty() != 5
            || wckHalfOrcBonus() != 5
            || wckChainArmorPenalty() != 15
            || wckStuddedArmorPenalty() != 5
            || wckHeavierThanChainPenalty() != 20
            || wckStrengthBonus() != 5
            || wckStrengthBase() != 15
            || wckOneHandPenalty() != 5
            || wckCheckMinDistance() != 10
            || wckInitialCheckDistance() != 10
            || wckIntermediateDistance() != 100
            || wckFinalCheckBonus() != 20
            || !wckModifierAddedToRating()
            || !wckEncLightNoPenalty()
            || !wckRaceHumanNoAdjust()
            || !wckHeavierThanChainNoSevereCliff()
            || !wckStrengthSevereCliffOnly()
            || !wckStrengthExceptionalAs18()
            || !wckBothHandsFreeSevereCliff()
            || !wckOneHandModeratePenalized()
            || !wckGentleHandsFreeNotPenalized()
            || !wckThiefAutoAboveThreshold()
            || !wckThiefCheckBelowThreshold()
            || !wckThiefScoreFloorApplies()
            || !wckInitialCheckRequired()
            || !wckInitialFailBackToStart()
            || !wckIntermediateOptional()
            || !wckIntermediateOver100Feet()
            || !wckIntermediateSmoothSlipperySevere()
            || !wckLateralAlwaysCheck()
            || !wckLateralBriefIgnored()
            || !wckFinalCheckAlways()
            || !wckFinalFailFallsToBottom()
            || !wckFinalSameRoundInitialOnly()
        )
            ++bad;
        // the Table 16 grid: the 13 surface rows (the rough, normal and
        // smooth slopes at the gentle, moderate and severe tilts, then the
        // cliff faces by roughness and ledges) x the three condition
        // modifiers to the non-thief Climbing Rating
        int C16[13][3] = {
            {70,55,35},
            {60,40,20},
            {40,20,10},
            {60,40,20},
            {50,25,10},
            {30,15,0},
            {50,25,10},
            {30,10,0},
            {10,0,-10},
            {0,-10,-20},
            {-10,-20,-30},
            {-10,-25,-40},
            {-20,-35,-50},
            };
        for (int b = 0;
             b < wckSurfaceCount();
             ++b) {
            int vals[3];
            vals[0] = wckModN(b);
            vals[1] = wckModS(b);
            vals[2] = wckModV(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != C16[b][c])
                    ++bad;
            }
        }
        // the extremes of Table 16: the rough gentle non-slippery +70 bonus
        // and the cliff smooth no-ledges slippery -50 penalty
    if (wckModN(0) != 70
            || wckModS(11) != -25
            || wckModV(12) != -50
        )
            ++bad;
        // the worked no-fall case: the base 40 percent non-thief rating plus
        // the +70 rough gentle modifier reaches 110, at or above the 100
        // percent no-fall rating
    if ((wckModN(0) + 40) < wckNoFallRating()
        )
            ++bad;
        // the thief auto rule: the +70 rough gentle non-slippery value is at
        // or above the +30 threshold, so no Climbing Check is needed
    if (wckModN(0) < wckThiefAutoThreshold()
        )
            ++bad;
        // the thief falling multipliers (twice on slightly slippery, four
        // times on slippery) and the shared 5 percent floor
    if (wckThiefFallMultSlippery() != 4
            || wckThiefFallMultSlightly() * 2 != 4
            || wckThiefScoreFloor() != 5
        )
            ++bad;
        // the final check +20 bonus equals four one-hand penalties (20) -
        // both book values pinned in one expression
    if (wckFinalCheckBonus() - wckOneHandPenalty() * 4 != 0
        )
            ++bad;
        // every Table 16 row is ordered: non-slippery >= slightly slippery >=
        // slippery
    if (wckModS(0) > wckModN(0)
            || wckModV(0) > wckModS(0)
            || wckModS(1) > wckModN(1)
            || wckModV(1) > wckModS(1)
            || wckModS(2) > wckModN(2)
            || wckModV(2) > wckModS(2)
            || wckModS(3) > wckModN(3)
            || wckModV(3) > wckModS(3)
            || wckModS(4) > wckModN(4)
            || wckModV(4) > wckModS(4)
            || wckModS(5) > wckModN(5)
            || wckModV(5) > wckModS(5)
            || wckModS(6) > wckModN(6)
            || wckModV(6) > wckModS(6)
            || wckModS(7) > wckModN(7)
            || wckModV(7) > wckModS(7)
            || wckModS(8) > wckModN(8)
            || wckModV(8) > wckModS(8)
            || wckModS(9) > wckModN(9)
            || wckModV(9) > wckModS(9)
            || wckModS(10) > wckModN(10)
            || wckModV(10) > wckModS(10)
            || wckModS(11) > wckModN(11)
            || wckModV(11) > wckModS(11)
            || wckModS(12) > wckModN(12)
            || wckModV(12) > wckModS(12)
        )
            ++bad;
        printf("R436 WSG climbing checks pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
