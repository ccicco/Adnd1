    // ---- R467 WSG finding water pin audit ----
    // The Table 34 grid value by value (the find% and the taint% per climate
    // band per terrain per season, including the constant arctic rows and the
    // human-verified tropical swamp spring cell), the two-checks-per-day rule
    // with the auto-fail gate, the obvious-water exceptions (the snow and ice
    // rules, the seacoast dig with its tide-line and depth gates) and the
    // water-quality guidelines - every cell, const and bool verified against
    // the model.
    {
        using namespace rules;
        int bad = 0;
    if (wfwRowCount() != 28
            || wfwChecksPerDay() != 2
            || wfwSeacoastDigPct() != 100
            || wfwSeacoastDigMaxFt() != 2
            || wfwIceTempGate() != 30
            || !wfwExtraSearchAutoFail()
            || !wfwNotUsedWhenObvious()
            || !wfwNearbyFreshWaterTaintCheck()
            || !wfwSeaWaterDehydrates()
            || !wfwSeacoastDigAboveTide()
            || !wfwDigDeeperSaltier()
            || !wfwRiverPurerUpstream()
            || !wfwLakePurerAtInflow()
            || !wfwFastFlowPurer()
            || !wfwGroundWaterPurer()
            || !wfwSnowIceCoverFreeWater()
            || !wfwTableAssumesNoSnowIce()
            || !wfwIceTaintPerTable()
            || !wfwFreshSnowPurest()
        )
            ++bad;
        // the Table 34 chance-of-finding-water grid (the find% and the taint%
        // per climate band per terrain per season; arctic
        // desert/hills/mountains/plains, subarctic through tropical
        // desert/forest/hills/mountains/plains/swamp)
        int C34[28][8] = {
            {5,50,5,50,5,50,5,50},
            {10,50,10,50,10,50,10,50},
            {5,30,5,30,5,30,5,30},
            {10,50,10,50,10,50,10,50},
            {5,60,10,60,10,60,5,60},
            {10,40,20,40,20,50,10,40},
            {5,40,10,40,15,50,10,40},
            {5,30,20,30,15,30,10,30},
            {10,50,20,50,20,50,15,50},
            {40,60,60,60,50,60,50,60},
            {5,70,5,70,5,70,5,80},
            {30,30,40,30,30,30,30,30},
            {30,40,40,40,40,50,30,40},
            {20,30,20,30,15,30,20,30},
            {20,50,40,50,40,50,30,50},
            {60,70,70,70,80,80,60,70},
            {5,70,5,70,5,80,5,80},
            {60,40,70,50,70,60,60,50},
            {30,40,50,40,50,40,40,40},
            {40,30,60,40,50,50,40,40},
            {20,50,40,40,30,40,20,50},
            {70,70,80,70,90,80,70,80},
            {5,70,10,70,5,80,5,80},
            {80,50,80,60,80,70,80,60},
            {15,40,20,40,30,50,15,40},
            {40,30,70,30,60,40,70,40},
            {20,50,50,50,60,60,50,50},
            {70,70,90,75,90,80,80,80},
            };
        for (int b = 0;
             b < wfwRowCount();
             ++b) {
            int vals[8];
            vals[0] = wfwWinFind(b);
            vals[1] = wfwWinTaint(b);
            vals[2] = wfwSprFind(b);
            vals[3] = wfwSprTaint(b);
            vals[4] = wfwSumFind(b);
            vals[5] = wfwSumTaint(b);
            vals[6] = wfwAutFind(b);
            vals[7] = wfwAutTaint(b);
            for (int c = 0; c < 8;
                 ++c) {
                if (vals[c] != C34[b][c])
                    ++bad;
            }
        }
        // the arctic desert row: 5/50 in all four seasons (the constant
        // arctic rows)
    if (wfwWinFind(0) != 5
            || wfwWinTaint(0) != 50
            || wfwSprFind(0) != 5
            || wfwSprTaint(0) != 50
            || wfwSumFind(0) != 5
            || wfwSumTaint(0) != 50
            || wfwAutFind(0) != 5
            || wfwAutTaint(0) != 50
        )
            ++bad;
        // the arctic hills and plains rows: 10/50 constant; the arctic
        // mountains row: 5/30 constant
    if (wfwWinFind(1) != 10
            || wfwSprTaint(1) != 50
            || wfwSumFind(1) != 10
            || wfwAutTaint(1) != 50
            || wfwWinFind(3) != 10
            || wfwAutFind(3) != 10
            || wfwWinFind(2) != 5
            || wfwWinTaint(2) != 30
            || wfwAutTaint(2) != 30
        )
            ++bad;
        // the subarctic swamp row: 40/60, 60/60, 50/60, 50/60
    if (wfwWinFind(9) != 40
            || wfwWinTaint(9) != 60
            || wfwSprFind(9) != 60
            || wfwSprTaint(9) != 60
            || wfwSumFind(9) != 50
            || wfwSumTaint(9) != 60
            || wfwAutFind(9) != 50
            || wfwAutTaint(9) != 60
        )
            ++bad;
        // the temperate swamp row: 60/70, 70/70, 80/80, 60/70
    if (wfwWinFind(15) != 60
            || wfwWinTaint(15) != 70
            || wfwSprFind(15) != 70
            || wfwSprTaint(15) != 70
            || wfwSumFind(15) != 80
            || wfwSumTaint(15) != 80
            || wfwAutFind(15) != 60
            || wfwAutTaint(15) != 70
        )
            ++bad;
        // the subtropical swamp row: 70/70, 80/70, 90/80, 70/80
    if (wfwWinFind(21) != 70
            || wfwWinTaint(21) != 70
            || wfwSprFind(21) != 80
            || wfwSprTaint(21) != 70
            || wfwSumFind(21) != 90
            || wfwSumTaint(21) != 80
            || wfwAutFind(21) != 70
            || wfwAutTaint(21) != 80
        )
            ++bad;
        // the tropical swamp row: 70/70, 90/75 (the human-verified odd cell),
        // 90/80, 80/80
    if (wfwWinFind(27) != 70
            || wfwWinTaint(27) != 70
            || wfwSprFind(27) != 90
            || wfwSprTaint(27) != 75
            || wfwSumFind(27) != 90
            || wfwSumTaint(27) != 80
            || wfwAutFind(27) != 80
            || wfwAutTaint(27) != 80
        )
            ++bad;
        // the tropical forest row: 80/50, 80/60, 80/70, 80/60
    if (wfwWinFind(23) != 80
            || wfwWinTaint(23) != 50
            || wfwSprFind(23) != 80
            || wfwSprTaint(23) != 60
            || wfwSumFind(23) != 80
            || wfwSumTaint(23) != 70
            || wfwAutFind(23) != 80
            || wfwAutTaint(23) != 60
        )
            ++bad;
        // the temperate desert row: 5/70 x3 then the autumn 5/80; the
        // subtropical and tropical desert rows
    if (wfwWinFind(10) != 5
            || wfwWinTaint(10) != 70
            || wfwSprFind(10) != 5
            || wfwSprTaint(10) != 70
            || wfwSumFind(10) != 5
            || wfwSumTaint(10) != 70
            || wfwAutFind(10) != 5
            || wfwAutTaint(10) != 80
            || wfwWinFind(16) != 5
            || wfwWinTaint(16) != 70
            || wfwSprFind(16) != 5
            || wfwSprTaint(16) != 70
            || wfwSumFind(16) != 5
            || wfwSumTaint(16) != 80
            || wfwAutFind(16) != 5
            || wfwAutTaint(16) != 80
            || wfwWinFind(22) != 5
            || wfwWinTaint(22) != 70
            || wfwSprFind(22) != 10
            || wfwSprTaint(22) != 70
            || wfwSumFind(22) != 5
            || wfwSumTaint(22) != 80
            || wfwAutFind(22) != 5
            || wfwAutTaint(22) != 80
        )
            ++bad;
        // the subarctic desert row: 5/60, 10/60, 10/60, 5/60
    if (wfwWinFind(4) != 5
            || wfwWinTaint(4) != 60
            || wfwSprFind(4) != 10
            || wfwSprTaint(4) != 60
            || wfwSumFind(4) != 10
            || wfwSumTaint(4) != 60
            || wfwAutFind(4) != 5
            || wfwAutTaint(4) != 60
        )
            ++bad;
        // the two-checks-per-day rule and the auto-fail gate
    if (wfwChecksPerDay() != 2
        )
            ++bad;
        // the seacoast dig: 100% if above the high tide line and no more than
        // two feet deep
    if (wfwSeacoastDigPct() != 100
            || wfwSeacoastDigMaxFt() != 2
        )
            ++bad;
        // the ice temperature gate: 30 degrees or lower
    if (wfwIceTempGate() != 30
        )
            ++bad;
        // the arctic band is constant across all four seasons in every row
        // (the printed grid repeats the same cell)
    if (wfwWinFind(0) != wfwSprFind(0)
            || wfwSprFind(0) != wfwSumFind(0)
            || wfwSumFind(0) != wfwAutFind(0)
            || wfwWinTaint(0) != wfwAutTaint(0)
            || wfwWinFind(1) != wfwSprFind(1)
            || wfwSprFind(1) != wfwSumFind(1)
            || wfwSumFind(1) != wfwAutFind(1)
            || wfwWinTaint(1) != wfwAutTaint(1)
            || wfwWinFind(2) != wfwSprFind(2)
            || wfwSprFind(2) != wfwSumFind(2)
            || wfwSumFind(2) != wfwAutFind(2)
            || wfwWinTaint(2) != wfwAutTaint(2)
            || wfwWinFind(3) != wfwSprFind(3)
            || wfwSprFind(3) != wfwSumFind(3)
            || wfwSumFind(3) != wfwAutFind(3)
            || wfwWinTaint(3) != wfwAutTaint(3)
        )
            ++bad;
        // the desert find chance never exceeds 10 in any climate in any
        // season
    if (wfwWinFind(0) > 10
            || wfwSprFind(0) > 10
            || wfwSumFind(0) > 10
            || wfwAutFind(0) > 10
            || wfwWinFind(4) > 10
            || wfwSprFind(4) > 10
            || wfwSumFind(4) > 10
            || wfwAutFind(4) > 10
            || wfwWinFind(10) > 10
            || wfwSprFind(10) > 10
            || wfwSumFind(10) > 10
            || wfwAutFind(10) > 10
            || wfwWinFind(16) > 10
            || wfwSprFind(16) > 10
            || wfwSumFind(16) > 10
            || wfwAutFind(16) > 10
            || wfwWinFind(22) > 10
            || wfwSprFind(22) > 10
            || wfwSumFind(22) > 10
            || wfwAutFind(22) > 10
        )
            ++bad;
        // the swamp find chance beats the desert find chance in every
        // non-arctic climate in every season
    if (wfwWinFind(9) <= wfwWinFind(4)
            || wfwSprFind(9) <= wfwSprFind(4)
            || wfwSumFind(9) <= wfwSumFind(4)
            || wfwAutFind(9) <= wfwAutFind(4)
            || wfwWinFind(15) <= wfwWinFind(10)
            || wfwSprFind(15) <= wfwSprFind(10)
            || wfwSumFind(15) <= wfwSumFind(10)
            || wfwAutFind(15) <= wfwAutFind(10)
            || wfwWinFind(21) <= wfwWinFind(16)
            || wfwSprFind(21) <= wfwSprFind(16)
            || wfwSumFind(21) <= wfwSumFind(16)
            || wfwAutFind(21) <= wfwAutFind(16)
            || wfwWinFind(27) <= wfwWinFind(22)
            || wfwSprFind(27) <= wfwSprFind(22)
            || wfwSumFind(27) <= wfwSumFind(22)
            || wfwAutFind(27) <= wfwAutFind(22)
        )
            ++bad;
        // every find chance and every taint chance stays within 0 to 100
    if (wfwWinFind(0) < 0
            || wfwWinFind(0) > 100
            || wfwWinTaint(0) < 0
            || wfwWinTaint(0) > 100
            || wfwSprFind(0) < 0
            || wfwSprFind(0) > 100
            || wfwSprTaint(0) < 0
            || wfwSprTaint(0) > 100
            || wfwSumFind(0) < 0
            || wfwSumFind(0) > 100
            || wfwSumTaint(0) < 0
            || wfwSumTaint(0) > 100
            || wfwAutFind(0) < 0
            || wfwAutFind(0) > 100
            || wfwAutTaint(0) < 0
            || wfwAutTaint(0) > 100
            || wfwWinFind(1) < 0
            || wfwWinFind(1) > 100
            || wfwWinTaint(1) < 0
            || wfwWinTaint(1) > 100
            || wfwSprFind(1) < 0
            || wfwSprFind(1) > 100
            || wfwSprTaint(1) < 0
            || wfwSprTaint(1) > 100
            || wfwSumFind(1) < 0
            || wfwSumFind(1) > 100
            || wfwSumTaint(1) < 0
            || wfwSumTaint(1) > 100
            || wfwAutFind(1) < 0
            || wfwAutFind(1) > 100
            || wfwAutTaint(1) < 0
            || wfwAutTaint(1) > 100
            || wfwWinFind(2) < 0
            || wfwWinFind(2) > 100
            || wfwWinTaint(2) < 0
            || wfwWinTaint(2) > 100
            || wfwSprFind(2) < 0
            || wfwSprFind(2) > 100
            || wfwSprTaint(2) < 0
            || wfwSprTaint(2) > 100
            || wfwSumFind(2) < 0
            || wfwSumFind(2) > 100
            || wfwSumTaint(2) < 0
            || wfwSumTaint(2) > 100
            || wfwAutFind(2) < 0
            || wfwAutFind(2) > 100
            || wfwAutTaint(2) < 0
            || wfwAutTaint(2) > 100
            || wfwWinFind(3) < 0
            || wfwWinFind(3) > 100
            || wfwWinTaint(3) < 0
            || wfwWinTaint(3) > 100
            || wfwSprFind(3) < 0
            || wfwSprFind(3) > 100
            || wfwSprTaint(3) < 0
            || wfwSprTaint(3) > 100
            || wfwSumFind(3) < 0
            || wfwSumFind(3) > 100
            || wfwSumTaint(3) < 0
            || wfwSumTaint(3) > 100
            || wfwAutFind(3) < 0
            || wfwAutFind(3) > 100
            || wfwAutTaint(3) < 0
            || wfwAutTaint(3) > 100
            || wfwWinFind(4) < 0
            || wfwWinFind(4) > 100
            || wfwWinTaint(4) < 0
            || wfwWinTaint(4) > 100
            || wfwSprFind(4) < 0
            || wfwSprFind(4) > 100
            || wfwSprTaint(4) < 0
            || wfwSprTaint(4) > 100
            || wfwSumFind(4) < 0
            || wfwSumFind(4) > 100
            || wfwSumTaint(4) < 0
            || wfwSumTaint(4) > 100
            || wfwAutFind(4) < 0
            || wfwAutFind(4) > 100
            || wfwAutTaint(4) < 0
            || wfwAutTaint(4) > 100
            || wfwWinFind(5) < 0
            || wfwWinFind(5) > 100
            || wfwWinTaint(5) < 0
            || wfwWinTaint(5) > 100
            || wfwSprFind(5) < 0
            || wfwSprFind(5) > 100
            || wfwSprTaint(5) < 0
            || wfwSprTaint(5) > 100
            || wfwSumFind(5) < 0
            || wfwSumFind(5) > 100
            || wfwSumTaint(5) < 0
            || wfwSumTaint(5) > 100
            || wfwAutFind(5) < 0
            || wfwAutFind(5) > 100
            || wfwAutTaint(5) < 0
            || wfwAutTaint(5) > 100
            || wfwWinFind(6) < 0
            || wfwWinFind(6) > 100
            || wfwWinTaint(6) < 0
            || wfwWinTaint(6) > 100
            || wfwSprFind(6) < 0
            || wfwSprFind(6) > 100
            || wfwSprTaint(6) < 0
            || wfwSprTaint(6) > 100
            || wfwSumFind(6) < 0
            || wfwSumFind(6) > 100
            || wfwSumTaint(6) < 0
            || wfwSumTaint(6) > 100
            || wfwAutFind(6) < 0
            || wfwAutFind(6) > 100
            || wfwAutTaint(6) < 0
            || wfwAutTaint(6) > 100
            || wfwWinFind(7) < 0
            || wfwWinFind(7) > 100
            || wfwWinTaint(7) < 0
            || wfwWinTaint(7) > 100
            || wfwSprFind(7) < 0
            || wfwSprFind(7) > 100
            || wfwSprTaint(7) < 0
            || wfwSprTaint(7) > 100
            || wfwSumFind(7) < 0
            || wfwSumFind(7) > 100
            || wfwSumTaint(7) < 0
            || wfwSumTaint(7) > 100
            || wfwAutFind(7) < 0
            || wfwAutFind(7) > 100
            || wfwAutTaint(7) < 0
            || wfwAutTaint(7) > 100
            || wfwWinFind(8) < 0
            || wfwWinFind(8) > 100
            || wfwWinTaint(8) < 0
            || wfwWinTaint(8) > 100
            || wfwSprFind(8) < 0
            || wfwSprFind(8) > 100
            || wfwSprTaint(8) < 0
            || wfwSprTaint(8) > 100
            || wfwSumFind(8) < 0
            || wfwSumFind(8) > 100
            || wfwSumTaint(8) < 0
            || wfwSumTaint(8) > 100
            || wfwAutFind(8) < 0
            || wfwAutFind(8) > 100
            || wfwAutTaint(8) < 0
            || wfwAutTaint(8) > 100
            || wfwWinFind(9) < 0
            || wfwWinFind(9) > 100
            || wfwWinTaint(9) < 0
            || wfwWinTaint(9) > 100
            || wfwSprFind(9) < 0
            || wfwSprFind(9) > 100
            || wfwSprTaint(9) < 0
            || wfwSprTaint(9) > 100
            || wfwSumFind(9) < 0
            || wfwSumFind(9) > 100
            || wfwSumTaint(9) < 0
            || wfwSumTaint(9) > 100
            || wfwAutFind(9) < 0
            || wfwAutFind(9) > 100
            || wfwAutTaint(9) < 0
            || wfwAutTaint(9) > 100
            || wfwWinFind(10) < 0
            || wfwWinFind(10) > 100
            || wfwWinTaint(10) < 0
            || wfwWinTaint(10) > 100
            || wfwSprFind(10) < 0
            || wfwSprFind(10) > 100
            || wfwSprTaint(10) < 0
            || wfwSprTaint(10) > 100
            || wfwSumFind(10) < 0
            || wfwSumFind(10) > 100
            || wfwSumTaint(10) < 0
            || wfwSumTaint(10) > 100
            || wfwAutFind(10) < 0
            || wfwAutFind(10) > 100
            || wfwAutTaint(10) < 0
            || wfwAutTaint(10) > 100
            || wfwWinFind(11) < 0
            || wfwWinFind(11) > 100
            || wfwWinTaint(11) < 0
            || wfwWinTaint(11) > 100
            || wfwSprFind(11) < 0
            || wfwSprFind(11) > 100
            || wfwSprTaint(11) < 0
            || wfwSprTaint(11) > 100
            || wfwSumFind(11) < 0
            || wfwSumFind(11) > 100
            || wfwSumTaint(11) < 0
            || wfwSumTaint(11) > 100
            || wfwAutFind(11) < 0
            || wfwAutFind(11) > 100
            || wfwAutTaint(11) < 0
            || wfwAutTaint(11) > 100
            || wfwWinFind(12) < 0
            || wfwWinFind(12) > 100
            || wfwWinTaint(12) < 0
            || wfwWinTaint(12) > 100
            || wfwSprFind(12) < 0
            || wfwSprFind(12) > 100
            || wfwSprTaint(12) < 0
            || wfwSprTaint(12) > 100
            || wfwSumFind(12) < 0
            || wfwSumFind(12) > 100
            || wfwSumTaint(12) < 0
            || wfwSumTaint(12) > 100
            || wfwAutFind(12) < 0
            || wfwAutFind(12) > 100
            || wfwAutTaint(12) < 0
            || wfwAutTaint(12) > 100
            || wfwWinFind(13) < 0
            || wfwWinFind(13) > 100
            || wfwWinTaint(13) < 0
            || wfwWinTaint(13) > 100
            || wfwSprFind(13) < 0
            || wfwSprFind(13) > 100
            || wfwSprTaint(13) < 0
            || wfwSprTaint(13) > 100
            || wfwSumFind(13) < 0
            || wfwSumFind(13) > 100
            || wfwSumTaint(13) < 0
            || wfwSumTaint(13) > 100
            || wfwAutFind(13) < 0
            || wfwAutFind(13) > 100
            || wfwAutTaint(13) < 0
            || wfwAutTaint(13) > 100
            || wfwWinFind(14) < 0
            || wfwWinFind(14) > 100
            || wfwWinTaint(14) < 0
            || wfwWinTaint(14) > 100
            || wfwSprFind(14) < 0
            || wfwSprFind(14) > 100
            || wfwSprTaint(14) < 0
            || wfwSprTaint(14) > 100
            || wfwSumFind(14) < 0
            || wfwSumFind(14) > 100
            || wfwSumTaint(14) < 0
            || wfwSumTaint(14) > 100
            || wfwAutFind(14) < 0
            || wfwAutFind(14) > 100
            || wfwAutTaint(14) < 0
            || wfwAutTaint(14) > 100
            || wfwWinFind(15) < 0
            || wfwWinFind(15) > 100
            || wfwWinTaint(15) < 0
            || wfwWinTaint(15) > 100
            || wfwSprFind(15) < 0
            || wfwSprFind(15) > 100
            || wfwSprTaint(15) < 0
            || wfwSprTaint(15) > 100
            || wfwSumFind(15) < 0
            || wfwSumFind(15) > 100
            || wfwSumTaint(15) < 0
            || wfwSumTaint(15) > 100
            || wfwAutFind(15) < 0
            || wfwAutFind(15) > 100
            || wfwAutTaint(15) < 0
            || wfwAutTaint(15) > 100
            || wfwWinFind(16) < 0
            || wfwWinFind(16) > 100
            || wfwWinTaint(16) < 0
            || wfwWinTaint(16) > 100
            || wfwSprFind(16) < 0
            || wfwSprFind(16) > 100
            || wfwSprTaint(16) < 0
            || wfwSprTaint(16) > 100
            || wfwSumFind(16) < 0
            || wfwSumFind(16) > 100
            || wfwSumTaint(16) < 0
            || wfwSumTaint(16) > 100
            || wfwAutFind(16) < 0
            || wfwAutFind(16) > 100
            || wfwAutTaint(16) < 0
            || wfwAutTaint(16) > 100
            || wfwWinFind(17) < 0
            || wfwWinFind(17) > 100
            || wfwWinTaint(17) < 0
            || wfwWinTaint(17) > 100
            || wfwSprFind(17) < 0
            || wfwSprFind(17) > 100
            || wfwSprTaint(17) < 0
            || wfwSprTaint(17) > 100
            || wfwSumFind(17) < 0
            || wfwSumFind(17) > 100
            || wfwSumTaint(17) < 0
            || wfwSumTaint(17) > 100
            || wfwAutFind(17) < 0
            || wfwAutFind(17) > 100
            || wfwAutTaint(17) < 0
            || wfwAutTaint(17) > 100
            || wfwWinFind(18) < 0
            || wfwWinFind(18) > 100
            || wfwWinTaint(18) < 0
            || wfwWinTaint(18) > 100
            || wfwSprFind(18) < 0
            || wfwSprFind(18) > 100
            || wfwSprTaint(18) < 0
            || wfwSprTaint(18) > 100
            || wfwSumFind(18) < 0
            || wfwSumFind(18) > 100
            || wfwSumTaint(18) < 0
            || wfwSumTaint(18) > 100
            || wfwAutFind(18) < 0
            || wfwAutFind(18) > 100
            || wfwAutTaint(18) < 0
            || wfwAutTaint(18) > 100
            || wfwWinFind(19) < 0
            || wfwWinFind(19) > 100
            || wfwWinTaint(19) < 0
            || wfwWinTaint(19) > 100
            || wfwSprFind(19) < 0
            || wfwSprFind(19) > 100
            || wfwSprTaint(19) < 0
            || wfwSprTaint(19) > 100
            || wfwSumFind(19) < 0
            || wfwSumFind(19) > 100
            || wfwSumTaint(19) < 0
            || wfwSumTaint(19) > 100
            || wfwAutFind(19) < 0
            || wfwAutFind(19) > 100
            || wfwAutTaint(19) < 0
            || wfwAutTaint(19) > 100
            || wfwWinFind(20) < 0
            || wfwWinFind(20) > 100
            || wfwWinTaint(20) < 0
            || wfwWinTaint(20) > 100
            || wfwSprFind(20) < 0
            || wfwSprFind(20) > 100
            || wfwSprTaint(20) < 0
            || wfwSprTaint(20) > 100
            || wfwSumFind(20) < 0
            || wfwSumFind(20) > 100
            || wfwSumTaint(20) < 0
            || wfwSumTaint(20) > 100
            || wfwAutFind(20) < 0
            || wfwAutFind(20) > 100
            || wfwAutTaint(20) < 0
            || wfwAutTaint(20) > 100
            || wfwWinFind(21) < 0
            || wfwWinFind(21) > 100
            || wfwWinTaint(21) < 0
            || wfwWinTaint(21) > 100
            || wfwSprFind(21) < 0
            || wfwSprFind(21) > 100
            || wfwSprTaint(21) < 0
            || wfwSprTaint(21) > 100
            || wfwSumFind(21) < 0
            || wfwSumFind(21) > 100
            || wfwSumTaint(21) < 0
            || wfwSumTaint(21) > 100
            || wfwAutFind(21) < 0
            || wfwAutFind(21) > 100
            || wfwAutTaint(21) < 0
            || wfwAutTaint(21) > 100
            || wfwWinFind(22) < 0
            || wfwWinFind(22) > 100
            || wfwWinTaint(22) < 0
            || wfwWinTaint(22) > 100
            || wfwSprFind(22) < 0
            || wfwSprFind(22) > 100
            || wfwSprTaint(22) < 0
            || wfwSprTaint(22) > 100
            || wfwSumFind(22) < 0
            || wfwSumFind(22) > 100
            || wfwSumTaint(22) < 0
            || wfwSumTaint(22) > 100
            || wfwAutFind(22) < 0
            || wfwAutFind(22) > 100
            || wfwAutTaint(22) < 0
            || wfwAutTaint(22) > 100
            || wfwWinFind(23) < 0
            || wfwWinFind(23) > 100
            || wfwWinTaint(23) < 0
            || wfwWinTaint(23) > 100
            || wfwSprFind(23) < 0
            || wfwSprFind(23) > 100
            || wfwSprTaint(23) < 0
            || wfwSprTaint(23) > 100
            || wfwSumFind(23) < 0
            || wfwSumFind(23) > 100
            || wfwSumTaint(23) < 0
            || wfwSumTaint(23) > 100
            || wfwAutFind(23) < 0
            || wfwAutFind(23) > 100
            || wfwAutTaint(23) < 0
            || wfwAutTaint(23) > 100
            || wfwWinFind(24) < 0
            || wfwWinFind(24) > 100
            || wfwWinTaint(24) < 0
            || wfwWinTaint(24) > 100
            || wfwSprFind(24) < 0
            || wfwSprFind(24) > 100
            || wfwSprTaint(24) < 0
            || wfwSprTaint(24) > 100
            || wfwSumFind(24) < 0
            || wfwSumFind(24) > 100
            || wfwSumTaint(24) < 0
            || wfwSumTaint(24) > 100
            || wfwAutFind(24) < 0
            || wfwAutFind(24) > 100
            || wfwAutTaint(24) < 0
            || wfwAutTaint(24) > 100
            || wfwWinFind(25) < 0
            || wfwWinFind(25) > 100
            || wfwWinTaint(25) < 0
            || wfwWinTaint(25) > 100
            || wfwSprFind(25) < 0
            || wfwSprFind(25) > 100
            || wfwSprTaint(25) < 0
            || wfwSprTaint(25) > 100
            || wfwSumFind(25) < 0
            || wfwSumFind(25) > 100
            || wfwSumTaint(25) < 0
            || wfwSumTaint(25) > 100
            || wfwAutFind(25) < 0
            || wfwAutFind(25) > 100
            || wfwAutTaint(25) < 0
            || wfwAutTaint(25) > 100
            || wfwWinFind(26) < 0
            || wfwWinFind(26) > 100
            || wfwWinTaint(26) < 0
            || wfwWinTaint(26) > 100
            || wfwSprFind(26) < 0
            || wfwSprFind(26) > 100
            || wfwSprTaint(26) < 0
            || wfwSprTaint(26) > 100
            || wfwSumFind(26) < 0
            || wfwSumFind(26) > 100
            || wfwSumTaint(26) < 0
            || wfwSumTaint(26) > 100
            || wfwAutFind(26) < 0
            || wfwAutFind(26) > 100
            || wfwAutTaint(26) < 0
            || wfwAutTaint(26) > 100
            || wfwWinFind(27) < 0
            || wfwWinFind(27) > 100
            || wfwWinTaint(27) < 0
            || wfwWinTaint(27) > 100
            || wfwSprFind(27) < 0
            || wfwSprFind(27) > 100
            || wfwSprTaint(27) < 0
            || wfwSprTaint(27) > 100
            || wfwSumFind(27) < 0
            || wfwSumFind(27) > 100
            || wfwSumTaint(27) < 0
            || wfwSumTaint(27) > 100
            || wfwAutFind(27) < 0
            || wfwAutFind(27) > 100
            || wfwAutTaint(27) < 0
            || wfwAutTaint(27) > 100
        )
            ++bad;
        printf("R467 WSG finding water pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
