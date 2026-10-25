    // ---- R429 WSG special weather pin audit ----
    // The special weather data slice pins Tables 6, 7 and 8
    // (rules/wsgsplwx.h, prefix wsw): the hurricane half-point grid, the
    // tornado none/damaged/destroyed codes and the hailstorm dice, verified
    // cell for cell with the dash censuses and the printed prose; census 353
    // -> 354.
    {
        using namespace rules;
        int bad = 0;
    if (wswHurrIntensityCount() != 3
            || wswTornadoStructCount() != 6
            || wswHailArmorCount() != 4
            || wswHurrDashCensus() != 3
            || wswTornadoNoneCensus() != 12
            || wswHailNoneCensus() != 1
            || wswHurrCheckEveryTurns() != 3
            || wswHurrCheckChancePct() != 50
            || wswHurrLightWindMin() != 80
            || wswHurrNormalWindMin() != 100
            || wswHurrNormalWindMax() != 140
            || wswHurrHeavyWindMax() != 200
            || wswHurrUnshelteredDie() != 3
            || wswHurrThrownDie() != 6
            || wswGaleWindMin() != 46
            || wswGaleWindMax() != 79
            || wswTornadoDebrisDice() != 4
            || wswTornadoDebrisDie() != 20
            || wswTornadoLiftDie() != 6
            || wswTornadoLiftMult() != 10
            || wswTornadoCarryMult() != 100
            || wswTornadoOccDice() != 3
            || wswTornadoStructDestroyedDie() != 10
            || wswTornadoStructDamagedDie() != 6
            || wswTornadoLiftChanceDen() != 10
            || wswTornadoUnnoticedDayNum() != 1
            || wswTornadoUnnoticedNightNum() != 2
            || wswTornadoUnnoticedDen() != 6
            || wswSandBlindDie() != 6
            || wswSandCheckEveryRounds() != 3
            || wswSandPartialWindow() != 3
            || wswSandBlindMeleeBonus() != 4
            || wswSandPartialHitBonus() != 2
            || wswSandChokeDen() != 6
            || wswSandChokeWorsenNum() != 3
            || wswSandChokeWorsenDie() != 3
            || wswSandChokeThirdNum() != 4
            || wswSandWashedDice() != 2
            || wswSandWashedDie() != 4
            || wswSandPartialRecoverHours() != 12
            || wswSandBlindRecoverHours() != 24
            || wswHailChancePct() != 50
            || wswHailArmorAcMax() != 4
            || wswHailUnprotectedDie() != 2
            || wswHailShieldFloor() != 1
            || !wswTornadoFlimsyAutoDestroys()
            || !wswGaleAsLightHurr()
            || !wswHurrStructCollapseAtDpv()
            || !wswHailAcSquatAvoids()
            || !wswHailEasierTarget()
            || !wswHailShieldHalves()
            || !wswSandBlindCannotAttack()
            || !wswSandPartialNoDamageBonus()
            || !wswSandEyesMustStayCovered()
            || !wswSnowNonmagicNoHasten()
            || !wswIceSleetNoDamageMoving()
        )
            ++bad;
        // the Table 6 grid in half-points, 0 = the dash, with the dash census
        int C6[3][4] = {
            {2,1,0,0},
            {4,2,1,0},
            {6,4,2,2},
            };
        int n6[4] = {0,0,0,0};
        int e6[4] = {0,0,1,2};
        for (int b = 0;
             b < wswHurrIntensityCount();
             ++b) {
            int vals[4];
            vals[0] = wswHurrWood(b);
            vals[1] = wswHurrEarth(b);
            vals[2] = wswHurrSoftStone(b);
            vals[3] = wswHurrHardRock(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != C6[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++n6[c];
            }
        }
        for (int c = 0; c < 4; ++c)
            if (n6[c] != e6[c])
                ++bad;
        // the Table 7 letter-code grid, 0/1/2 = none/damaged/destroyed, with
        // the dash census
        int C7[6][6] = {
            {1,1,2,2,2,2},
            {0,1,1,2,2,2},
            {0,0,1,1,2,2},
            {0,0,1,1,1,2},
            {0,0,0,1,1,1},
            {0,0,0,0,1,1},
            };
        int n7[6] = {0,0,0,0,0,0};
        int e7[6] = {5,4,2,1,0,0};
        for (int b = 0;
             b < wswTornadoStructCount();
             ++b) {
            int vals[6];
            vals[0] = wswTornadoRoll1(b);
            vals[1] = wswTornadoRoll2(b);
            vals[2] = wswTornadoRoll3(b);
            vals[3] = wswTornadoRoll4(b);
            vals[4] = wswTornadoRoll5(b);
            vals[5] = wswTornadoRoll6(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != C7[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++n7[c];
            }
        }
        for (int c = 0; c < 6; ++c)
            if (n7[c] != e7[c])
                ++bad;
        // the Table 8 dice grid, the cell = the 1dN size, 0 = the dash
        int C8[4][3] = {
            {4,6,8},
            {3,4,4},
            {2,3,3},
            {0,2,3},
            };
        int n8[3] = {0,0,0};
        int e8[3] = {1,0,0};
        for (int b = 0;
             b < wswHailArmorCount();
             ++b) {
            int vals[3];
            vals[0] = wswHailDieSmall(b);
            vals[1] = wswHailDieMedium(b);
            vals[2] = wswHailDieLarge(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != C8[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++n8[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (n8[c] != e8[c])
                ++bad;
        // the wswHailSizeBandFor band-for boundaries
    if (wswHailSizeBandFor(0) != 0
            || wswHailSizeBandFor(1) != 0
            || wswHailSizeBandFor(3) != 1
            || wswHailSizeBandFor(2) != 1
            || wswHailSizeBandFor(4) != 2
        )
            ++bad;
        // the Table 6 doubling: light wood 1 point = 2 half-points, light
        // earth and normal soft stone are both 1/2 = 1
    if (wswHurrWood(0) != 2
            || wswHurrEarth(0) != 1
            || wswHurrSoftStone(1) != 1
        )
            ++bad;
        // the heavy row: wood 3 points = 6, earth 2 = 4, hard rock 1 = 2
    if (wswHurrWood(2) != 6
            || wswHurrEarth(2) != 4
            || wswHurrHardRock(2) != 2
        )
            ++bad;
        // the Table 7 ladder: light wooden damaged on 1-2, destroyed on 3-6;
        // wood and stone dash-dash-D-D-D-X
    if (wswTornadoRoll1(0) != 1
            || wswTornadoRoll3(0) != 2
            || wswTornadoRoll2(3) != 0
            || wswTornadoRoll6(3) != 2
        )
            ++bad;
        // heavy stone: dashes on 1-4, damaged on 5-6
    if (wswTornadoRoll4(5) != 0
            || wswTornadoRoll5(5) + wswTornadoRoll6(5) != 2
        )
            ++bad;
        // the Table 8 dice: no armor takes 1d4/1d6/1d8, scale or chain mail
        // is safe in small hail
    if (wswHailDieSmall(0) != 4
            || wswHailDieLarge(0) != 8
            || wswHailDieSmall(3) != 0
        )
            ++bad;
        // the hailstone dispatch: a 1/2 inch stone is small, a 1 1/2 inch
        // stone is medium, a 2 inch stone is large
    if (wswHailSizeBandFor(1) != 0
            || wswHailSizeBandFor(3) != 1
            || wswHailSizeBandFor(4) != 2
        )
            ++bad;
        // the hurricane wind stages: light 80+, normal 100-140, heavy up to
        // 200; the gale tops out below at 79
    if (wswHurrLightWindMin() != 80
            || wswHurrNormalWindMin() != 100
            || wswHurrNormalWindMax() != 140
            || wswHurrHeavyWindMax() != 200
            || wswGaleWindMax() != 79
        )
            ++bad;
        // the tornado grid never softens as the roll rises (the light wooden
        // and heavy wooden rows)
    if (wswTornadoRoll2(0) > wswTornadoRoll3(0)
            || wswTornadoRoll3(1) > wswTornadoRoll4(1)
        )
            ++bad;
        // the hail dice never shrink as the stones grow (the padded row)
    if (wswHailDieSmall(2) > wswHailDieMedium(2)
            || wswHailDieMedium(2) > wswHailDieLarge(2)
        )
            ++bad;
        printf("R429 WSG special weather pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
