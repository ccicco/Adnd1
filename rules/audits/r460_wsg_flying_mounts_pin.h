    // ---- R460 WSG flying mounts pin audit ----
    // The flying-mounts slice pins Table 27, the characteristics of flying
    // mounts: the four category grids (A the 20 dragons and dragonlike, B the
    // 6 birds, C the 7 winged mammals, D the 8 other fantastic creatures - 41
    // mounts x 7 columns: normal and maximum load with the dash as max =
    // normal, the full and reduced move rates, the maneuverability class on
    // the A=1..E=5 scale, and the safe-turns/rest stamina pair), the column
    // definitions (the plummet rule over maximum, the single-rate 0 marker,
    // the MC one-class drop when ridden with E unreducible, the over-load
    // stamina cut of one turn or one-third whichever greater, inapplicable to
    // the dash creatures), the solid-form footnote for the cloud and mist
    // dragons, the listing criteria (Prime Material, wilderness, size M or L
    // air-carrier), the trained-mount scarcity and the untrained at-mercy
    // rule, the coerced-mount refusals, the triple-to-fifty rations feeding,
    // and the saddle/container even-distribution encumbrance rules with the
    // 2:1 doubling (rules/wsgflymounts.h, prefix wfm); census 384 -> 385.
    {
        using namespace rules;
        int bad = 0;
    if (wfmCatACount() != 20
            || wfmCatBCount() != 6
            || wfmCatCCount() != 7
            || wfmCatDCount() != 8
            || wfmTotalCreatures() != 41
            || wfmMcRiddenDrop() != 1
            || wfmMcFloor() != 5
            || wfmOverloadStaCutTurns() != 1
            || wfmOverloadStaThird() != 3
            || wfmRationsMultiple() != 3
            || wfmBigDragonRations() != 50
            || !wfmTrainedScarceAndDear()
            || !wfmUntrainedAtMercy()
            || !wfmOverMaxNeverLifts()
            || !wfmOverMaxPlummets()
            || !wfmDashMaxEqualsNormal()
            || !wfmDashCannotFlyOverNormal()
            || !wfmReducedRateWhenOverloaded()
            || !wfmZeroRateMeansSingleRate()
            || !wfmMcDropsWhenRidden()
            || !wfmMcEStaysE()
            || !wfmStaCutIsGreaterOf()
            || !wfmStaRestBetweenFlights()
            || !wfmCloudMistSolidFormOnly()
            || !wfmListedIfPrimeMaterial()
            || !wfmListedIfWildernessNative()
            || !wfmListedIfSizeMOrL()
            || !wfmDmAssignsUnlistedStats()
            || !wfmCoercedMaySkimp()
            || !wfmFullBenefitNeedsWillingness()
            || !wfmLoadsNeedContainers()
            || !wfmUnevenLoadRaisesEnc()
        )
            ++bad;
        // the Table 27A grid: the category A flying mounts (black dragon,
        // blue dragon, brass dragon, bronze dragon, celestial dragon, cloud
        // dragon, coiled dragon, copper dragon, dracolisk, dragonne,
        // dragonnel, earth dragon, gold dragon, green dragon, mist dragon,
        // red dragon, silver dragon, spirit dragon, white dragon, wyvern)
        // with the normal load, the maximum load (the dash encoded as max =
        // normal), the full and reduced move rates in miles per half-day, the
        // maneuver-ability class (3 = C, 4 = D, 5 = E) and the two stamina
        // figures - safe turns aloft and turns of rest
        int C27A[20][7] = {
            {9000,18000,24,12,5,24,6},
            {15000,30000,24,12,5,27,6},
            {9000,18000,24,12,5,24,6},
            {15000,30000,24,12,5,27,6},
            {5000,10000,48,24,5,12,6},
            {18000,36000,39,18,5,30,6},
            {3000,4500,12,6,5,9,3},
            {12000,24000,24,12,5,24,6},
            {3000,5000,15,6,5,2,1},
            {1500,1500,9,0,5,2,1},
            {6000,10000,18,9,4,12,3},
            {2000,3000,24,12,5,9,3},
            {21000,42000,30,15,5,30,6},
            {12000,18000,24,12,5,24,6},
            {18000,36000,33,15,5,30,6},
            {18000,36000,24,12,5,30,6},
            {18000,36000,24,12,5,30,6},
            {4000,6500,12,6,5,9,3},
            {6000,12000,30,15,5,18,6},
            {10000,20000,24,12,5,18,6},
            };
        for (int b = 0;
             b < wfmCatACount();
             ++b) {
            int vals[7];
            vals[0] = wfmANorm(b);
            vals[1] = wfmAMax(b);
            vals[2] = wfmAMove(b);
            vals[3] = wfmAMoveRed(b);
            vals[4] = wfmAMc(b);
            vals[5] = wfmASta(b);
            vals[6] = wfmARest(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != C27A[b][c])
                    ++bad;
            }
        }
        // the Table 27B grid: the category B flying mounts (boobrie, giant
        // eagle, pteranodon, giant pterosaur, roc, giant vulture) with the
        // normal load, the maximum load (the dash encoded as max = normal),
        // the full and reduced move rates in miles per half-day, the
        // maneuver-ability class (3 = C, 4 = D, 5 = E) and the two stamina
        // figures - safe turns aloft and turns of rest
        int C27B[6][7] = {
            {1000,1500,15,9,5,3,3},
            {1000,1500,48,18,5,9,3},
            {1500,1500,15,0,4,2,1},
            {2000,2000,12,0,5,3,1},
            {50000,100000,30,15,5,30,6},
            {1000,1500,24,12,5,3,2},
            };
        for (int b = 0;
             b < wfmCatBCount();
             ++b) {
            int vals[7];
            vals[0] = wfmBNorm(b);
            vals[1] = wfmBMax(b);
            vals[2] = wfmBMove(b);
            vals[3] = wfmBMoveRed(b);
            vals[4] = wfmBMc(b);
            vals[5] = wfmBSta(b);
            vals[6] = wfmBRest(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != C27B[b][c])
                    ++bad;
            }
        }
        // the Table 27C grid: the category C flying mounts (chimera, griffon,
        // gorgimera, hippogriff, manticore, opinicus, pegasus) with the
        // normal load, the maximum load (the dash encoded as max = normal),
        // the full and reduced move rates in miles per half-day, the
        // maneuver-ability class (3 = C, 4 = D, 5 = E) and the two stamina
        // figures - safe turns aloft and turns of rest
        int C27C[7][7] = {
            {4500,4500,18,0,5,12,3},
            {5500,8000,30,15,4,18,6},
            {5000,5000,15,0,5,9,3},
            {4000,6000,36,18,4,15,3},
            {3000,3000,18,0,5,6,3},
            {1000,1500,30,15,3,3,1},
            {4000,6500,48,24,4,12,3},
            };
        for (int b = 0;
             b < wfmCatCCount();
             ++b) {
            int vals[7];
            vals[0] = wfmCNorm(b);
            vals[1] = wfmCMax(b);
            vals[2] = wfmCMove(b);
            vals[3] = wfmCMoveRed(b);
            vals[4] = wfmCMc(b);
            vals[5] = wfmCSta(b);
            vals[6] = wfmCRest(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != C27C[b][c])
                    ++bad;
            }
        }
        // the Table 27D grid: the category D flying mounts (aarakocra,
        // androsphinx, criosphinx, dragon horse, gynosphinx, hieracosphinx,
        // giant mantis, yeth hound) with the normal load, the maximum load
        // (the dash encoded as max = normal), the full and reduced move rates
        // in miles per half-day, the maneuver-ability class (3 = C, 4 = D, 5
        // = E) and the two stamina figures - safe turns aloft and turns of
        // rest
        int C27D[8][7] = {
            {1500,1500,36,0,4,3,2},
            {7500,9500,30,15,5,18,6},
            {7000,9000,24,12,5,15,6},
            {3000,5000,48,24,3,12,3},
            {5000,8000,24,12,5,15,6},
            {7000,8500,36,18,5,18,6},
            {2000,3000,12,6,5,6,3},
            {2000,3000,27,12,3,9,3},
            };
        for (int b = 0;
             b < wfmCatDCount();
             ++b) {
            int vals[7];
            vals[0] = wfmDNorm(b);
            vals[1] = wfmDMax(b);
            vals[2] = wfmDMove(b);
            vals[3] = wfmDMoveRed(b);
            vals[4] = wfmDMc(b);
            vals[5] = wfmDSta(b);
            vals[6] = wfmDRest(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != C27D[b][c])
                    ++bad;
            }
        }
        // the four categories total 41 mounts: 20 dragons, 6 birds, 7 winged
        // mammals and 8 other fantastic creatures
    if (wfmCatACount() + wfmCatBCount() + wfmCatCCount() + wfmCatDCount() !=
        41
            || wfmTotalCreatures() != 41
        )
            ++bad;
        // the gold dragon, the strongest category A mount: 21000 normal,
        // 42000 maximum - double the normal
    if (wfmANorm(12) != 21000
            || wfmAMax(12) != 42000
            || wfmAMax(12) != 2 * wfmANorm(12)
        )
            ++bad;
        // the footnote pair: the cloud dragon flies 39/18 and the mist dragon
        // 33/15 - both ridden only in solid form (the 39 settled at high
        // resolution, both text layers agreeing)
    if (wfmAMove(5) != 39
            || wfmAMoveRed(5) != 18
            || wfmAMove(14) != 33
            || wfmAMoveRed(14) != 15
        )
            ++bad;
        // the roc, the greatest carrier in the table: 50000 normal, 100000
        // maximum, with the top stamina pattern 30 turns up and 6 resting
    if (wfmBNorm(4) != 50000
            || wfmBMax(4) != 100000
            || wfmBMax(4) != 2 * wfmBNorm(4)
            || wfmBSta(4) != 30
            || wfmBRest(4) != 6
        )
            ++bad;
        // the dash rule, one creature per category: the dragonne, the
        // pteranodon, the chimera and the aarakocra each have normal load =
        // maximum load
    if (wfmAMax(9) != 1500
            || wfmAMax(9) != wfmANorm(9)
            || wfmBMax(2) != wfmBNorm(2)
            || wfmCMax(0) != wfmCNorm(0)
            || wfmDMax(0) != wfmDNorm(0)
        )
            ++bad;
        // the single-rate creatures: the dragonne 9, the pteranodon 15, the
        // chimera 18 and the aarakocra 36 each have one move rate always
    if (wfmAMoveRed(9) != 0
            || wfmBMoveRed(2) != 0
            || wfmCMoveRed(0) != 0
            || wfmDMoveRed(0) != 0
            || wfmAMove(9) != 9
            || wfmCMove(0) != 18
        )
            ++bad;
        // the maneuverability classes: most mounts are E (5), the dragonnel D
        // (4), the opinicus and the dragon horse C (3) - E is the unreducible
        // floor
    if (wfmAMc(0) != 5
            || wfmAMc(19) != 5
            || wfmAMc(10) != 4
            || wfmCMc(5) != 3
            || wfmDMc(3) != 3
            || wfmMcFloor() != 5
        )
            ++bad;
        // the stamina spread: the blue and bronze dragons 27 up / 6 rest, the
        // boobrie the unusual 3/3, and the dracolisk the brief 2/1
    if (wfmASta(1) != 27
            || wfmARest(1) != 6
            || wfmBSta(0) != 3
            || wfmBRest(0) != 3
            || wfmASta(8) != 2
            || wfmARest(8) != 1
        )
            ++bad;
        // the over-load stamina cut: one turn or one-third of normal,
        // whichever greater - the black dragon 24 becomes 16 (a third beats a
        // single turn)
    if (wfmOverloadStaCutTurns() != 1
            || wfmOverloadStaThird() != 3
            || wfmASta(0) != 24
        )
            ++bad;
        // the feeding rules: at least triple rations for most mounts, up to
        // fifty rations a day for one of the biggest dragon types
    if (wfmRationsMultiple() != 3
            || wfmBigDragonRations() != 50
        )
            ++bad;
        // the pegasus, the fastest winged mammal: 48/24 carrying 4000 normal
        // and 6500 maximum
    if (wfmCMove(6) != 48
            || wfmCMoveRed(6) != 24
            || wfmCNorm(6) != 4000
            || wfmCMax(6) != 6500
        )
            ++bad;
        printf("R460 WSG flying mounts pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
