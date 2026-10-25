    // ---- R444 WSG grappling hooks pin audit ----
    // The grappling-hooks slice pins the 1/3-of-strength rounded-up
    // times-10-feet throw (Str 8 = 30 feet), the horizontal throw (same as
    // vertical on a 30-degree-or-less incline, doubled from a secure position
    // with a 10-foot whirling radius), the one-round throw with the 1d4-round
    // re-coil on a miss, the 01-05 self-hit for 1d6 damage on a missed throw
    // directly above, the 3-foot climb bonus for the unencumbered, Table 20
    // GRAPPLING SUCCESS (10 terrain rows x the protrusion pair and the
    // non-slippery/slightly slippery/slippery catch chances), the solid vs
    // not-solid protrusion procedure (solid holds indefinitely, not-solid
    // gives way after 1d6 rounds of climbing) and the recheck-after-10-feet
    // rule (rules/wsggrap.h, prefix wgh); census 368 -> 369.
    {
        using namespace rules;
        int bad = 0;
    if (wghStrengthDivisor() != 3
            || wghFeetPerStrengthUnit() != 10
            || wghStr8ThrowFt() != 30
            || wghHorizontalInclineDeg() != 30
            || wghSecureWhirlRadiusFt() != 10
            || wghSecureHorizontalMult() != 2
            || wghThrowRounds() != 1
            || wghRecoilRoundsDice() != 4
            || wghSelfHitRollMax() != 5
            || wghSelfHitDamageDice() != 6
            || wghClimbBonusFt() != 3
            || wghNonSolidGiveWayDice() != 6
            || wghTerrainCount() != 10
            || wghRecheckDistanceFt() != 10
            || !wghAnyClimberCanUse()
            || !wghThreeOrFourProngs()
            || !wghNeededSevereHandyModerate()
            || !wghHorizontalSameAsVertical()
            || !wghSecurePositionDoubles()
            || !wghAboveSelfDangerous()
            || !wghClimbBonusLightOnly()
            || !wghNoMovementBenefitOtherwise()
            || !wghSolidHoldsIndefinitely()
            || !wghNotSolidGivesWay()
            || !wghSecondRollCatches()
            || !wghRecheckAfter10Ft()
        )
            ++bad;
        // the Table 20 grid: the ten terrain rows (the three moderate slopes,
        // the three severe slopes and the four cliff types) x the Chance of
        // Protrusion pair and the three condition catch chances - the last
        // row (cliff, smooth, no ledges) is the eye-read row, protrusion
        // 80/90 with 92/99/99
        int C20[10][5] = {
            {30,50,50,60,70},
            {50,70,60,72,84},
            {70,85,64,76,86},
            {30,40,68,80,88},
            {50,60,72,84,90},
            {70,80,76,88,92},
            {20,40,80,92,94},
            {40,60,84,96,96},
            {60,80,88,98,98},
            {80,90,92,99,99},
            };
        for (int b = 0;
             b < wghTerrainCount();
             ++b) {
            int vals[5];
            vals[0] = wghProtrusionFirst(b);
            vals[1] = wghProtrusionSecond(b);
            vals[2] = wghCatchNonSlippery(b);
            vals[3] = wghCatchSlightlySlippery(b);
            vals[4] = wghCatchSlippery(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != C20[b][c])
                    ++bad;
            }
        }
        // the throw formula: 1/3 of strength (8 -> 3 rounded up) times 10
        // feet = 30 feet for a strength of 8
    if (wghStr8ThrowFt() != 30
            || wghStrengthDivisor() != 3
            || wghFeetPerStrengthUnit() != 10
        )
            ++bad;
        // the throw economy: one round per attempt, 1d4 rounds to re-coil a
        // miss, 01-05 self-hit for 1d6 damage
    if (wghThrowRounds() != 1
            || wghRecoilRoundsDice() != 4
            || wghSelfHitRollMax() != 5
            || wghSelfHitDamageDice() != 6
        )
            ++bad;
        // the small numbers: the 3-foot climb bonus, the 10-foot recheck
        // distance, the 10-foot whirling radius and the 30-degree horizontal
        // incline
    if (wghClimbBonusFt() != 3
            || wghRecheckDistanceFt() != 10
            || wghSecureWhirlRadiusFt() != 10
            || wghHorizontalInclineDeg() != 30
        )
            ++bad;
        // the Table 20 first row (moderate slope, rough): protrusion 30/50,
        // catching at 50/60/70
    if (wghProtrusionFirst(0) != 30
            || wghProtrusionSecond(0) != 50
            || wghCatchNonSlippery(0) != 50
            || wghCatchSlippery(0) != 70
        )
            ++bad;
        // the Table 20 last row (cliff, smooth, no ledges - the eye-read
        // row): protrusion 80/90, catching at 92/99/99
    if (wghProtrusionFirst(9) != 80
            || wghProtrusionSecond(9) != 90
            || wghCatchNonSlippery(9) != 92
            || wghCatchSlightlySlippery(9) != 99
            || wghCatchSlippery(9) != 99
        )
            ++bad;
        // the secure horizontal throw: twice the vertical - a strength-8
        // thrower reaches 60 feet horizontally (30 x 2)
    if (wghSecureHorizontalMult() != 2
            || wghStr8ThrowFt() != wghSecureHorizontalMult() * 15
        )
            ++bad;
        // in every terrain row the first Chance of Protrusion number is below
        // the second - the solid threshold exceeds the existence threshold
    if (wghProtrusionFirst(0) >= wghProtrusionSecond(0)
            || wghProtrusionFirst(1) >= wghProtrusionSecond(1)
            || wghProtrusionFirst(2) >= wghProtrusionSecond(2)
            || wghProtrusionFirst(3) >= wghProtrusionSecond(3)
            || wghProtrusionFirst(4) >= wghProtrusionSecond(4)
            || wghProtrusionFirst(5) >= wghProtrusionSecond(5)
            || wghProtrusionFirst(6) >= wghProtrusionSecond(6)
            || wghProtrusionFirst(7) >= wghProtrusionSecond(7)
            || wghProtrusionFirst(8) >= wghProtrusionSecond(8)
            || wghProtrusionFirst(9) >= wghProtrusionSecond(9)
        )
            ++bad;
        // the catch chance is non-decreasing as the terrain gets more
        // slippery - the slipperier the surface, the better the hook holds
        // (checked on the first, severe-smooth and last rows)
    if (wghCatchNonSlippery(0) > wghCatchSlightlySlippery(0)
            || wghCatchSlightlySlippery(0) > wghCatchSlippery(0)
            || wghCatchNonSlippery(5) > wghCatchSlightlySlippery(5)
            || wghCatchSlightlySlippery(5) > wghCatchSlippery(5)
            || wghCatchNonSlippery(9) > wghCatchSlightlySlippery(9)
            || wghCatchSlightlySlippery(9) > wghCatchSlippery(9)
        )
            ++bad;
        // the existence thresholds read down the table 30/50/70 (moderate),
        // 30/50/70 (severe), 20/40/60/80 (cliff) - rough terrain offers fewer
        // protrusions, smooth terrain more
    if (wghProtrusionFirst(0) != 30
            || wghProtrusionFirst(1) != 50
            || wghProtrusionFirst(2) != 70
            || wghProtrusionFirst(3) != 30
            || wghProtrusionFirst(4) != 50
            || wghProtrusionFirst(5) != 70
            || wghProtrusionFirst(6) != 20
            || wghProtrusionFirst(7) != 40
            || wghProtrusionFirst(8) != 60
            || wghProtrusionFirst(9) != 80
        )
            ++bad;
        printf("R444 WSG grappling hooks pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
