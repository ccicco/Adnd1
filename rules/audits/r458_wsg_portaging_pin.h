    // ---- R458 WSG portaging pin audit ----
    // The portaging slice pins the solo-portage gate (a vessel smaller than a
    // large rowboat carried by one character able to support its encumbrance
    // without becoming severely encumbered), the severe-encumbrance bar on
    // portaging or helping, the portage-crew minimums (two for the large
    // rowboat and the small barge, four for the large barge) with the maximum
    // of twice the minimum, the beyond-max futility (the third small-canoe
    // carrier), and the 3-inch portage move rate - 3 miles in eight hours, 30
    // feet per round, regardless of terrain or overall encumbrance status
    // (rules/wsgportage.h, prefix wpg); census 382 -> 383.
    {
        using namespace rules;
        int bad = 0;
    if (wpgVesselCount() != 8
            || wpgMaxCrewMultiplier() != 2
            || wpgLargeBargeMinCrew() != 4
            || wpgPortageMoveInches() != 3
            || wpgPortageMilesPerHalfDay() != 3
            || wpgPortageFeetPerRound() != 30
            || !wpgSoloBelowLargeRowboat()
            || !wpgSoloNeedsNoSevereEncumbrance()
            || !wpgSevereBlocksPortageAndHelp()
            || !wpgCrewSharesEncumbrance()
            || !wpgCrewCappedAtTwiceMin()
            || !wpgBeyondMaxIsUseless()
            || !wpgMoveCapIgnoresTerrain()
            || !wpgMoveCapIgnoresEncumbrance()
        )
            ++bad;
        // the portage-crew grid: the eight vessels (kayak, small canoe, small
        // rowboat, coracle, large canoe, large rowboat, small barge, large
        // barge) with the minimum portage crew and the maximum (twice the
        // minimum)
        int C28[8][2] = {
            {1,2},
            {1,2},
            {1,2},
            {1,2},
            {1,2},
            {2,4},
            {2,4},
            {4,8},
            };
        for (int b = 0;
             b < wpgVesselCount();
             ++b) {
            int vals[2];
            vals[0] = wpgMinCrew(b);
            vals[1] = wpgMaxCrew(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != C28[b][c])
                    ++bad;
            }
        }
        // the solo group: the kayak, the small canoe, the small rowboat, the
        // coracle and the large canoe are all smaller than a large rowboat
        // and portage with a single character
    if (wpgMinCrew(0) != 1
            || wpgMinCrew(1) != 1
            || wpgMinCrew(2) != 1
            || wpgMinCrew(3) != 1
            || wpgMinCrew(4) != 1
        )
            ++bad;
        // the crew minimums: the large rowboat and the small barge need two
        // porters, the large barge four - twice the large-rowboat minimum
    if (wpgMinCrew(5) != 2
            || wpgMinCrew(6) != 2
            || wpgMinCrew(7) != 4
            || wpgMinCrew(7) != 2 * wpgMinCrew(5)
        )
            ++bad;
        // the crew maximums: twice the minimum throughout - two carriers for
        // a small canoe, four for a large rowboat or small barge, eight for a
        // large barge
    if (wpgMaxCrew(0) != 2
            || wpgMaxCrew(5) != 4
            || wpgMaxCrew(6) != 4
            || wpgMaxCrew(7) != 8
        )
            ++bad;
        // the twice-minimum law holds row by row - the maximum crew is
        // exactly the minimum times the multiplier constant
    if (wpgMaxCrew(0) != 2 * wpgMinCrew(0)
            || wpgMaxCrew(2) != 2 * wpgMinCrew(2)
            || wpgMaxCrew(7) != 2 * wpgMinCrew(7)
            || wpgMaxCrewMultiplier() != 2
        )
            ++bad;
        // the portage move rate: 3 inches of movement, 3 miles in eight
        // hours, 30 feet per round - the feet figure is ten times the inches
    if (wpgPortageMoveInches() != 3
            || wpgPortageMilesPerHalfDay() != 3
            || wpgPortageFeetPerRound() != 30
            || wpgPortageFeetPerRound() != 10 * wpgPortageMoveInches()
        )
            ++bad;
        // the large barge cross-tie: its grid minimum matches the
        // four-character crew constant and its maximum is twice that
    if (wpgMinCrew(7) != wpgLargeBargeMinCrew()
            || wpgMaxCrew(7) != wpgLargeBargeMinCrew() * 2
        )
            ++bad;
        printf("R458 WSG portaging pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
