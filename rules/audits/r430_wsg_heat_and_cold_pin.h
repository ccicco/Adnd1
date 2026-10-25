    // ---- R430 WSG heat and cold pin audit ----
    // The heat-and-cold data slice pins Tables 9 and 10 (rules/wsgheat.h,
    // prefix wsh): the 25 temperature damage bands, the frostbite shares and
    // thresholds, the damage and check adjustments, the hypothermia and
    // heatstroke rules; census 354 -> 355.
    {
        using namespace rules;
        int bad = 0;
    if (wshDmgBandCount() != 25
            || wshFrostRowCount() != 7
            || wshT9DashUnprotCensus() != 2
            || wshT9DashProtCensus() != 14
            || wshT10BlankCensus() != 4
            || wshConCheckEveryTurns() != 3
            || wshDmgHpPct() != 10
            || wshDmgRerollDie() != 8
            || wshAdjTurnsMin() != 1
            || wshStatColdMin() != 1
            || wshStatColdMax() != 3
            || wshStatHotMin() != -3
            || wshStatHotMax() != -1
            || wshStrenColdMin() != 1
            || wshStrenColdMax() != 2
            || wshStrenHotMin() != 1
            || wshStrenHotMax() != 4
            || wshFatigMin() != 1
            || wshFatigMax() != 6
            || wshConAdjL46() != -1
            || wshConAdjL79() != -2
            || wshConAdjL1012() != -3
            || wshConAdjL1315() != -4
            || wshConAdjL16() != -5
            || wshRecoverHpPerHour() != 1
            || wshHypoUnprotFails() != 3
            || wshHypoProtFails() != 6
            || wshHypoPhysPerTurn() != 1
            || wshHypoWisPerTurns() != 2
            || wshHypoScoreFloor() != 3
            || wshHypoIncapScores() != 2
            || wshHypoUnconcDie() != 3
            || wshHypoDeathDie() != 4
            || wshHypoRecoverPerHour() != 1
            || wshHypoRelapsePct() != 50
            || wshFrostbiteTempMax() != 0
            || wshSevereFrostPlus() != 4
            || wshFrostEarInitPenalty() != -1
            || wshFrostEarSurpriseDen() != 6
            || wshFrostEarTreatTurns() != 2
            || wshFrostFeetMoveNum() != 1
            || wshFrostFeetMoveDen() != 2
            || wshFrostFeetAcPenalty() != 2
            || wshFrostFeetTreatTurns() != 1
            || wshFrostHandsMissile() != -6
            || wshFrostHandsMelee() != -4
            || wshFrostHandsSevereMelee() != -2
            || wshFrostHandsTreatTurns() != 2
            || wshHeatstrokeUnconcPct() != 50
            || wshHeatstrokeOnsetTurns() != 3
            || wshHeatstrokeConPerTurn() != 1
            || wshHeatstrokeRegainNum() != 2
            || wshHeatstrokeRegainDen() != 3
            || !wshLeastFavorableAdj()
            || !wshRecoverNeedsTolerable()
            || !wshHypoDeathRegardlessHp()
            || !wshFrostComboNoThreshold()
            || !wshFrostRidingNoMovePenalty()
            || !wshFrostSevereEarsNoPenalty()
            || !wshFrostSevereFeetNormalMove()
            || !wshHeatstrokeAutoFail()
            || !wshHeatstrokeMaxDamage()
            || !wshHeatstrokeConZeroDies()
        )
            ++bad;
        // the Table 9 grid, 99 = the dash, with the dash censuses
        int C9[25][4] = {
            {14,8,9,4},
            {13,8,8,4},
            {12,7,7,3},
            {11,7,6,3},
            {10,6,5,3},
            {10,6,5,2},
            {9,5,4,2},
            {8,5,3,2},
            {7,4,2,1},
            {6,4,1,1},
            {5,3,0,1},
            {4,3,99,99},
            {3,2,99,99},
            {2,2,99,99},
            {1,1,99,99},
            {0,1,99,99},
            {99,99,99,99},
            {0,1,99,99},
            {0,1,0,1},
            {1,2,0,1},
            {2,3,0,2},
            {3,3,0,2},
            {3,4,0,3},
            {5,5,0,3},
            {6,6,1,4},
            };
        int n9[4] = {0,0,0,0};
        int e9[4] = {1,1,7,7};
        for (int b = 0;
             b < wshDmgBandCount();
             ++b) {
            int vals[4];
            vals[0] = wshHeatConUnprot(b);
            vals[1] = wshHeatDmgUnprot(b);
            vals[2] = wshHeatConProt(b);
            vals[3] = wshHeatDmgProt(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != C9[b][c])
                    ++bad;
                if (vals[c] == 99)
                    ++n9[c];
            }
        }
        for (int c = 0; c < 4; ++c)
            if (n9[c] != e9[c])
                ++bad;
        // the Table 10 shares grid (sixths) and the blank threshold census
        int C10[7][4] = {
            {6,0,0,4},
            {0,6,0,6},
            {0,0,6,8},
            {0,3,3,0},
            {4,2,0,0},
            {3,0,3,0},
            {2,2,2,0},
            };
        int n10[4] = {0,0,0,0};
        int e10[4] = {3,3,3,4};
        for (int b = 0;
             b < wshFrostRowCount();
             ++b) {
            int vals[4];
            vals[0] = wshFrostFeetShare(b);
            vals[1] = wshFrostEarsShare(b);
            vals[2] = wshFrostHandsShare(b);
            vals[3] = wshFrostPts(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != C10[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++n10[c];
            }
        }
        for (int c = 0; c < 4; ++c)
            if (n10[c] != e10[c])
                ++bad;
        // the wshHeatBandFor band-for boundaries
    if (wshHeatBandFor(-61) != 0
            || wshHeatBandFor(-60) != 0
            || wshHeatBandFor(-50) != 1
            || wshHeatBandFor(-59) != 1
            || wshHeatBandFor(-40) != 2
            || wshHeatBandFor(-49) != 2
            || wshHeatBandFor(-30) != 3
            || wshHeatBandFor(-39) != 3
            || wshHeatBandFor(-25) != 4
            || wshHeatBandFor(-29) != 4
            || wshHeatBandFor(-20) != 5
            || wshHeatBandFor(-24) != 5
            || wshHeatBandFor(-15) != 6
            || wshHeatBandFor(-19) != 6
            || wshHeatBandFor(-10) != 7
            || wshHeatBandFor(-14) != 7
            || wshHeatBandFor(-5) != 8
            || wshHeatBandFor(-9) != 8
            || wshHeatBandFor(0) != 9
            || wshHeatBandFor(-4) != 9
            || wshHeatBandFor(5) != 10
            || wshHeatBandFor(1) != 10
            || wshHeatBandFor(10) != 11
            || wshHeatBandFor(6) != 11
            || wshHeatBandFor(15) != 12
            || wshHeatBandFor(11) != 12
            || wshHeatBandFor(20) != 13
            || wshHeatBandFor(16) != 13
            || wshHeatBandFor(25) != 14
            || wshHeatBandFor(21) != 14
            || wshHeatBandFor(30) != 15
            || wshHeatBandFor(26) != 15
            || wshHeatBandFor(84) != 16
            || wshHeatBandFor(31) != 16
            || wshHeatBandFor(89) != 17
            || wshHeatBandFor(85) != 17
            || wshHeatBandFor(94) != 18
            || wshHeatBandFor(90) != 18
            || wshHeatBandFor(99) != 19
            || wshHeatBandFor(95) != 19
            || wshHeatBandFor(104) != 20
            || wshHeatBandFor(100) != 20
            || wshHeatBandFor(109) != 21
            || wshHeatBandFor(105) != 21
            || wshHeatBandFor(114) != 22
            || wshHeatBandFor(110) != 22
            || wshHeatBandFor(119) != 23
            || wshHeatBandFor(115) != 23
            || wshHeatBandFor(120) != 24
        )
            ++bad;
        // the book heatstroke example, part one: protected at 105 degrees
        // takes the max 2 plus the fatigued max 6 = 8
    if (wshHeatBandFor(105) != 21
            || wshHeatDmgProt(21) != 2
            || wshHeatDmgProt(21) + wshFatigMax() != 8
        )
            ++bad;
        // the book example, part two: inactive in the heat subtracts, max 2
        // minus 1 = 1
    if (wshHeatDmgProt(21) + wshStatHotMax() != 1
        )
            ++bad;
        // the book example, part three: the treatment regains 2/3 of 10 Con
        // points rounded up = 7
    if (wshHeatstrokeRegainNum() * 10 > 3 * 7
            || 3 * 7 - 3 >= wshHeatstrokeRegainNum() * 10
            || wshHeatstrokeRegainNum() != 2
            || wshHeatstrokeRegainDen() != 3
        )
            ++bad;
        // the band edges: -60 or lower is band 0 (+14 Con), the tolerable
        // 31-84 is band 16 (all dashes), 120 or higher is band 24
    if (wshHeatBandFor(-60) != 0
            || wshHeatConUnprot(0) != 14
            || wshHeatBandFor(31) != 16
            || wshHeatConUnprot(16) != 99
            || wshHeatBandFor(120) != 24
            || wshHeatDmgProt(24) != 4
        )
            ++bad;
        // the frostbite thresholds: feet 4, ears 6, hands 8; the combination
        // rows are blank
    if (wshFrostPts(0) != 4
            || wshFrostPts(1) != 6
            || wshFrostPts(2) != 8
            || wshFrostPts(3) != 0
            || wshFrostPts(6) != 0
        )
            ++bad;
        // the book own distribution examples: hands and ears with 3 damage
        // splits 2 ears 1 hands (the ears share listed first carries the
        // leftover)
    if (wshFrostEarsShare(3) != 3
            || wshFrostHandsShare(3) != 3
        )
            ++bad;
        // the Con Check adjustments by level: -1 at 4-6 up to -5 at 16+, no
        // adjustment below 4th
    if (wshConAdjL46() != -1
            || wshConAdjL79() != -2
            || wshConAdjL1012() != -3
            || wshConAdjL1315() != -4
            || wshConAdjL16() != -5
        )
            ++bad;
        // every Table 10 row shares all six sixths among the vulnerable parts
    if (wshFrostFeetShare(0) + wshFrostEarsShare(0) + wshFrostHandsShare(0) !=
        6
            || wshFrostFeetShare(4) + wshFrostEarsShare(4) +
            wshFrostHandsShare(4) != 6
            || wshFrostFeetShare(6) + wshFrostEarsShare(6) +
            wshFrostHandsShare(6) != 6
        )
            ++bad;
        // a threshold only on the single-part rows: a nonzero threshold means
        // an all-share of 6 (0 whenever the shares sum to 6)
    if (wshFrostPts(0) * (6 - wshFrostFeetShare(0) - wshFrostEarsShare(0) -
        wshFrostHandsShare(0)) + wshFrostPts(2) * (6 - wshFrostFeetShare(2) -
        wshFrostEarsShare(2) - wshFrostHandsShare(2)) + wshFrostPts(3) * (6 -
        wshFrostFeetShare(3) - wshFrostEarsShare(3) - wshFrostHandsShare(3))
        != 0
        )
            ++bad;
        printf("R430 WSG heat and cold pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
