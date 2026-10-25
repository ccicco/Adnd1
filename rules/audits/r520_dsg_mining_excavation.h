    // ---- R520 DSG mining excavation audit ----
    // The DSG mining excavation pins the tunneling rates (the Table 27
    // eight-race grid from 75/50/25 to 500/350/175 cubic feet per miner per
    // eight hours reprinted from DMG page 106, the per-race 10-foot-tunnel
    // maxima of 16, 12, 8, 6 and 4 miners), the vein rules (the 10x10 tunnel
    // following the shifting vein, the 1d6-times-10-feet depth to intersect,
    // the 1d4 direction faces, the at-least-20-foot runs, the secret 1d8
    // alterations - steep and shallow descent, the 10-60 degree curves right
    // and left, the 5-6 straight, the shallow and steep ascent - the
    // must-follow rule with the impossible-course run-out and other-direction
    // freedom, the both-ends stop over the duration rules, and the gorge
    // pickup), and the shoring rules (the wooden or stone pillars against the
    // cave-in, the carpenter, stonemason and miner proficiencies, the two
    // side braces and one ceiling brace per 10-foot section, the 30 feet of
    // one-foot-diameter bracing, the four man-hours per set, and the
    // 18/50-strength solo-moving threshold).
    {
        using namespace rules;
        int bad = 0;
    if (dnfT27RowCount() != 8
            || dnfT28RowCount() != 4
            || dnfT29RowCount() != 7
            || dnfMaxMinersSmall() != 16
            || dnfMaxMinersMan() != 12
            || dnfMaxMinersGnoll() != 8
            || dnfMaxMinersOgre() != 6
            || dnfMaxMinersGiant() != 4
            || dnfTunnelWidthFt() != 10
            || dnfTunnelHeightFt() != 10
            || dnfVeinDepthDice() != 1
            || dnfVeinDepthSides() != 6
            || dnfVeinDepthMultFt() != 10
            || dnfVeinSectionFt() != 20
            || dnfVeinAlterationDice() != 1
            || dnfVeinAlterationSides() != 8
            || dnfShoringSideBraces() != 2
            || dnfShoringCeilingBraces() != 1
            || dnfShoringBracingFt() != 30
            || dnfShoringDiameterFt() != 1
            || dnfShoringManHours() != 4
            || !dnfRatesReprintedFromDmg106()
            || !dnfRatesPerMinerPerEightHours()
            || !dnfExcavatingHardAndSlow()
            || !dnfMaxMinersDependsOnRace()
            || !dnfTunnelFollowsShiftingVein()
            || !dnfDirectionRollIsD4()
            || !dnfVeinRunsAtLeastSection()
            || !dnfAlterationRollIsSecret()
            || !dnfMustFollowUnwantedDirection()
            || !dnfImpossibleCourseRunsOut()
            || !dnfBothEndsStopsMine()
            || !dnfGorgePickupAtDiscretion()
            || !dnfShoringOrCaveIn()
            || !dnfShoringProficiencies()
            || !dnfStrongSoloMoving()
        )
            ++bad;
        // the Table 27 mining rates grid, reprinted from DMG page 106
        int C27[8][3] = {
            {75,50,25},
            {80,60,30},
            {85,65,30},
            {90,70,35},
            {150,100,50},
            {250,150,75},
            {300,200,100},
            {500,350,175},
            };
        for (int b = 0;
             b < dnfT27RowCount();
             ++b) {
            int vals[3];
            vals[0] = dnfT27VerySoft(b);
            vals[1] = dnfT27Soft(b);
            vals[2] = dnfT27Hard(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != C27[b][c])
                    ++bad;
            }
        }
        // the Table 28 vein direction grid
        int C28[4][2] = {
            {1,1},
            {2,2},
            {3,3},
            {4,4},
            };
        for (int b = 0;
             b < dnfT28RowCount();
             ++b) {
            int vals[2];
            vals[0] = dnfT28Lo(b);
            vals[1] = dnfT28Hi(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != C28[b][c])
                    ++bad;
            }
        }
        // the Table 29 vein path alterations grid (a d8 table; the djvu D6
        // header is a garble settled by the appendix reprint)
        int C29[7][2] = {
            {1,1},
            {2,2},
            {3,3},
            {4,4},
            {5,6},
            {7,7},
            {8,8},
            };
        for (int b = 0;
             b < dnfT29RowCount();
             ++b) {
            int vals[2];
            vals[0] = dnfT29Lo(b);
            vals[1] = dnfT29Hi(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != C29[b][c])
                    ++bad;
            }
        }
        // the 10-foot-tunnel miner maxima: 16 for the small races, 12 for
        // man-sized, 8 gnoll, 6 ogre, 4 giant.
    if (dnfMaxMinersSmall() != 16
            || dnfMaxMinersMan() != 12
            || dnfMaxMinersGnoll() != 8
            || dnfMaxMinersOgre() != 6
            || dnfMaxMinersGiant() != 4
        )
            ++bad;
        // the vein rolls: the 1d6 x 10-feet depth to intersect the vein, and
        // the secret 1d8 alteration roll after each 20-foot section.
    if (dnfVeinDepthDice() != 1
            || dnfVeinDepthSides() != 6
            || dnfVeinDepthMultFt() != 10
            || dnfVeinSectionFt() != 20
            || dnfVeinAlterationDice() != 1
            || dnfVeinAlterationSides() != 8
        )
            ++bad;
        // the tunnel and shoring: the 10x10 tunnel, two side braces plus a
        // ceiling brace, 30 feet of one-foot-diameter bracing, four man-hours
        // per set.
    if (dnfTunnelWidthFt() != 10
            || dnfTunnelHeightFt() != 10
            || dnfShoringSideBraces() != 2
            || dnfShoringCeilingBraces() != 1
            || dnfShoringBracingFt() != 30
            || dnfShoringDiameterFt() != 1
            || dnfShoringManHours() != 4
        )
            ++bad;
        // Table 27 anchor rows: the gnoll/halfling/human 75/50/25, the
        // dwarf/hobgoblin 90/70/35, and the stone giant 500/350/175.
    if (dnfT27VerySoft(0) != 75
            || dnfT27Soft(0) != 50
            || dnfT27Hard(0) != 25
            || dnfT27VerySoft(3) != 90
            || dnfT27Soft(3) != 70
            || dnfT27Hard(3) != 35
            || dnfT27VerySoft(7) != 500
            || dnfT27Soft(7) != 350
            || dnfT27Hard(7) != 175
        )
            ++bad;
        // Table 28 anchors: the 1 north-south and the 4 northwest-southeast
        // faces.
    if (dnfT28Lo(0) != 1
            || dnfT28Hi(0) != 1
            || dnfT28Lo(3) != 4
            || dnfT28Hi(3) != 4
        )
            ++bad;
        // Table 29 anchors: the 5-6 continues-straight band and the 8 steep
        // ascent.
    if (dnfT29Lo(4) != 5
            || dnfT29Hi(4) != 6
            || dnfT29Lo(6) != 8
            || dnfT29Hi(6) != 8
        )
            ++bad;
        printf("R520 DSG mining excavation audit: bad %d\n", bad);
        if (bad) return 1;
    }
