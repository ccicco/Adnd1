    // ---- R471 WSG natural shelters pin audit ----
    // The Table 35 grid (the six-terrain by four-season chance of finding
    // natural shelter), the check discipline (the DM checks whenever
    // characters look, further checks at three-turn intervals), the forest
    // construction ladder (the 3-8 turn material time with the helper
    // reduction, the 6-turn lashing, the rope use halving), the plains ladder
    // (7-12 turns), the terrain notes (the desert surface irregularities, the
    // hills windbreak, the mountains-as-features reading, the plains gully,
    // the swamp debris) and the shelter-quality guidelines - every const,
    // bool and table cell verified against the model.
    {
        using namespace rules;
        int bad = 0;
    if (wnsTerrainCount() != 6
            || wnsForestMatsMinTurns() != 3
            || wnsForestMatsMaxTurns() != 8
            || wnsHelperMatsReduction() != 2
            || wnsMatsTimeFloor() != 3
            || wnsLashBaseTurns() != 6
            || wnsHelperLashReduction() != 1
            || wnsMaxLashHelpers() != 2
            || wnsPlainsMatsMinTurns() != 7
            || wnsPlainsMatsMaxTurns() != 12
            || wnsRecheckIntervalTurns() != 3
            || !wnsTerrainSeasonMajor()
            || !wnsCheckOnLooking()
            || !wnsForestEasyMaterials()
            || !wnsPlainMtnImpossible()
            || !wnsBoughRoofShelter()
            || !wnsPackAnimalsNeedPath()
            || !wnsRopeUseHalvesTime()
            || !wnsDesertSurfaceIrregularities()
            || !wnsHillsWindbreak()
            || !wnsMountainVegetationReading()
            || !wnsPlainsGully()
            || !wnsPlainsScavengeWindbreak()
            || !wnsSwampDebrisShelter()
            || !wnsQualityManySmallPoor()
            || !wnsQualityFewLargeGood()
            || !wnsRockSideWindGood()
        )
            ++bad;
        // Table 35: chance of finding natural shelter, the six-terrain by
        // four-season percentage grid, printed p. 61
        int C35[6][4] = {
            {20,20,20,20},
            {90,100,100,100},
            {40,60,70,60},
            {40,40,40,40},
            {30,40,40,30},
            {40,50,50,40},
            };
        int n35[4] = {0,0,0,0};
        int e35[4] = {0,1,1,1};
        for (int b = 0;
             b < wnsTerrainCount();
             ++b) {
            int vals[4];
            vals[0] = wnsWinter(b);
            vals[1] = wnsSpring(b);
            vals[2] = wnsSummer(b);
            vals[3] = wnsAutumn(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != C35[b][c])
                    ++bad;
                if (vals[c] == 100)
                    ++n35[c];
            }
        }
        for (int c = 0; c < 4; ++c)
            if (n35[c] != e35[c])
                ++bad;
        // the forest material ladder: 3-8 turns (1d6+2)
    if (wnsForestMatsMinTurns() != 3
            || wnsForestMatsMaxTurns() != 8
            || wnsForestMatsMinTurns() >= wnsForestMatsMaxTurns()
        )
            ++bad;
        // the helper economics: the 2-turn material reduction with the 3-turn
        // floor, the 1-turn lash reduction with the two-helper cap
    if (wnsHelperMatsReduction() != 2
            || wnsMatsTimeFloor() != 3
            || wnsHelperLashReduction() != 1
            || wnsMaxLashHelpers() != 2
        )
            ++bad;
        // the plains ladder: 7-12 turns, above the forest band on both ends
    if (wnsPlainsMatsMinTurns() != 7
            || wnsPlainsMatsMaxTurns() != 12
            || wnsPlainsMatsMinTurns() <= wnsForestMatsMinTurns()
            || wnsPlainsMatsMaxTurns() <= wnsForestMatsMaxTurns()
        )
            ++bad;
        // the check discipline: rechecks every 3 turns
    if (wnsRecheckIntervalTurns() != 3
        )
            ++bad;
        // the construction mechanics: the bough-roof shelter, the pack-animal
        // path requirement and the rope-use halving
    if (wnsBoughRoofShelter() != 1
            || wnsPackAnimalsNeedPath() != 1
            || wnsRopeUseHalvesTime() != 1
        )
            ++bad;
        // the terrain notes: the desert irregularities, the hills windbreak,
        // the mountain reading and the swamp debris
    if (wnsDesertSurfaceIrregularities() != 1
            || wnsHillsWindbreak() != 1
            || wnsMountainVegetationReading() != 1
            || wnsSwampDebrisShelter() != 1
        )
            ++bad;
        // the plains gully and the scavenge windbreak
    if (wnsPlainsGully() != 1
            || wnsPlainsScavengeWindbreak() != 1
            || wnsPlainMtnImpossible() != 1
        )
            ++bad;
        // the shelter-quality guidelines: many-small poor, few-large good,
        // the rock-side wind split
    if (wnsQualityManySmallPoor() != 1
            || wnsQualityFewLargeGood() != 1
            || wnsRockSideWindGood() != 1
        )
            ++bad;
        // the desert row is constant 20 across all four seasons
    if (wnsWinter(0) != 20
            || wnsSpring(0) != 20
            || wnsSummer(0) != 20
            || wnsAutumn(0) != 20
        )
            ++bad;
        // the mountains row is constant 40 across all four seasons
    if (wnsWinter(3) != 40
            || wnsSpring(3) != 40
            || wnsSummer(3) != 40
            || wnsAutumn(3) != 40
        )
            ++bad;
        // the forest row tops the grid: 90 winter and 100 in the other three
        // seasons
    if (wnsWinter(1) != 90
            || wnsSpring(1) != 100
            || wnsSummer(1) != 100
            || wnsAutumn(1) != 100
        )
            ++bad;
        // the hills row peaks in summer at 70, above its own 40 winter floor
    if (wnsWinter(2) != 40
            || wnsSpring(2) != 60
            || wnsSummer(2) != 70
            || wnsAutumn(2) != 60
            || wnsSummer(2) <= wnsWinter(2)
        )
            ++bad;
        // the plains row dips to 30 in the winter and autumn shoulders
    if (wnsWinter(4) != 30
            || wnsSpring(4) != 40
            || wnsSummer(4) != 40
            || wnsAutumn(4) != 30
        )
            ++bad;
        // the swamp row: 40 shoulders with the 50 spring/summer middle
    if (wnsWinter(5) != 40
            || wnsSpring(5) != 50
            || wnsSummer(5) != 50
            || wnsAutumn(5) != 40
        )
            ++bad;
        // every cell in bounds: each terrain find chance at least 20
    if (wnsWinter(0) < 20
            || wnsSpring(0) < 20
            || wnsSummer(0) < 20
            || wnsAutumn(0) < 20
            || wnsWinter(1) < 20
            || wnsSpring(1) < 20
            || wnsSummer(1) < 20
            || wnsAutumn(1) < 20
            || wnsWinter(2) < 20
            || wnsSpring(2) < 20
            || wnsSummer(2) < 20
            || wnsAutumn(2) < 20
            || wnsWinter(3) < 20
            || wnsSpring(3) < 20
            || wnsSummer(3) < 20
            || wnsAutumn(3) < 20
            || wnsWinter(4) < 20
            || wnsSpring(4) < 20
            || wnsSummer(4) < 20
            || wnsAutumn(4) < 20
            || wnsWinter(5) < 20
            || wnsSpring(5) < 20
            || wnsSummer(5) < 20
            || wnsAutumn(5) < 20
        )
            ++bad;
        // the forest row beats every other terrain in every season
    if (wnsWinter(1) <= wnsWinter(0)
            || wnsWinter(1) <= wnsWinter(2)
            || wnsWinter(1) <= wnsWinter(3)
            || wnsWinter(1) <= wnsWinter(4)
            || wnsWinter(1) <= wnsWinter(5)
            || wnsSpring(1) <= wnsSpring(0)
            || wnsSpring(1) <= wnsSpring(2)
            || wnsSpring(1) <= wnsSpring(3)
            || wnsSpring(1) <= wnsSpring(4)
            || wnsSpring(1) <= wnsSpring(5)
            || wnsSummer(1) <= wnsSummer(0)
            || wnsSummer(1) <= wnsSummer(2)
            || wnsSummer(1) <= wnsSummer(3)
            || wnsSummer(1) <= wnsSummer(4)
            || wnsSummer(1) <= wnsSummer(5)
            || wnsAutumn(1) <= wnsAutumn(0)
            || wnsAutumn(1) <= wnsAutumn(2)
            || wnsAutumn(1) <= wnsAutumn(3)
            || wnsAutumn(1) <= wnsAutumn(4)
            || wnsAutumn(1) <= wnsAutumn(5)
        )
            ++bad;
        printf("R471 WSG natural shelters pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
