    // ---- R457 WSG boating pin audit ----
    // The boating-proficiency slice pins the nonproficient penalties - the
    // movement-rate reductions (kayak, small canoe and coracle at one-half,
    // small rowboat, large canoe, large rowboat and small barge at
    // two-thirds, large barge at three-quarters, applied before the wind and
    // current alterations), the +25% capsize penalty where the base chance
    // exceeds zero, capped at 100%; the proficient-crew benefits - the -20%
    // capsize reduction per proficient character after the first, the -20%
    // mast/sail damage reduction with the rigging-brace assumption, the
    // all-proficient waiver of the movement penalties, and the two-character
    // sail crews for the large rowboat, the small barge and the large barge
    // (rules/wsgboat.h, prefix wbp); census 381 -> 382.
    {
        using namespace rules;
        int bad = 0;
    if (wbpVesselCount() != 8
            || wbpCapsizeNonprofAdd() != 25
            || wbpCapsizeCeiling() != 100
            || wbpCapsizeExtraProfCut() != 20
            || wbpMastDamageProfCut() != 20
            || wbpTwoHandedSailCrew() != 2
            || !wbpPenaltyIfNoneProficient()
            || !wbpPenaltyIfAnyNonprofWorking()
            || !wbpReductionBeforeWindCurrent()
            || !wbpCapsizeAddOnlyIfBasePositive()
            || !wbpCapsizeCappedAtCeiling()
            || !wbpExtraProfsReduceCapsize()
            || !wbpMastCutNeedsRiggingBrace()
            || !wbpAllProficientWaivesMovePenalty()
            || !wbpSailCrewIsTwoHanded()
        )
            ++bad;
        // the movement-and-crew grid: the eight vessels (kayak, small canoe,
        // small rowboat, coracle, large canoe, large rowboat, small barge,
        // large barge) with the movement-fraction numerator and denominator
        // of the nonproficient penalty and the minimum sail crew
        int C27[8][3] = {
            {1,2,1},
            {1,2,1},
            {2,3,1},
            {1,2,1},
            {2,3,1},
            {2,3,2},
            {2,3,2},
            {3,4,2},
            };
        for (int b = 0;
             b < wbpVesselCount();
             ++b) {
            int vals[3];
            vals[0] = wbpMoveNum(b);
            vals[1] = wbpMoveDen(b);
            vals[2] = wbpSailCrew(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != C27[b][c])
                    ++bad;
            }
        }
        // the half-rate group: the kayak, the small canoe and the coracle all
        // move at one-half of normal when no proficient character is aboard
    if (wbpMoveNum(0) != 1
            || wbpMoveDen(0) != 2
            || wbpMoveNum(1) != 1
            || wbpMoveDen(1) != 2
            || wbpMoveNum(3) != 1
            || wbpMoveDen(3) != 2
        )
            ++bad;
        // the two-thirds group: the small rowboat, the large canoe, the large
        // rowboat and the small barge all move at two-thirds of normal
    if (wbpMoveNum(2) != 2
            || wbpMoveDen(2) != 3
            || wbpMoveNum(4) != 2
            || wbpMoveDen(4) != 3
            || wbpMoveNum(5) != 2
            || wbpMoveDen(5) != 3
            || wbpMoveNum(6) != 2
            || wbpMoveDen(6) != 3
        )
            ++bad;
        // the large barge alone moves at three-quarters of normal under the
        // penalty - the sturdiest vessel takes the smallest cut
    if (wbpMoveNum(7) != 3
            || wbpMoveDen(7) != 4
        )
            ++bad;
        // the four percentage pins: the +25% nonproficient capsize penalty
        // with its 100% ceiling, the -20% per extra proficient character, and
        // the -20% mast/sail damage reduction
    if (wbpCapsizeNonprofAdd() != 25
            || wbpCapsizeCeiling() != 100
            || wbpCapsizeExtraProfCut() != 20
            || wbpMastDamageProfCut() != 20
        )
            ++bad;
        // the one-handed vessels: the kayak, the small canoe, the small
        // rowboat, the coracle and the large canoe each sail with a single
        // character
    if (wbpSailCrew(0) != 1
            || wbpSailCrew(1) != 1
            || wbpSailCrew(2) != 1
            || wbpSailCrew(3) != 1
            || wbpSailCrew(4) != 1
        )
            ++bad;
        // the two-handed vessels: the large rowboat, the small barge and the
        // large barge each need a sail crew of two, three vessels summing to
        // six crew
    if (wbpSailCrew(5) != 2
            || wbpSailCrew(6) != 2
            || wbpSailCrew(7) != 2
            || wbpSailCrew(5) + wbpSailCrew(6) + wbpSailCrew(7) != 6
            || wbpTwoHandedSailCrew() != 2
        )
            ++bad;
        // the fraction sanity: the denominators carry the names - halves on a
        // 2, thirds on a 3, quarters on a 4
    if (wbpMoveDen(7) != 4
            || wbpMoveNum(7) != 3
            || wbpMoveDen(2) != 3
            || wbpMoveDen(0) != 2
            || wbpMoveNum(0) != 1
        )
            ++bad;
        printf("R457 WSG boating pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
