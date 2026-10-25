    // ---- R510 DSG odor detection audit ----
    // The DSG odor detection pins the procedure (a Wisdom Check at first
    // encounter, made secretly by the DM, rechecked only when the scent grows
    // very strong or the wind carries it with increased force, not repeated
    // once missed, the full Wisdom score only for easily-noticed odors, the
    // Table 15 cross-reference as the Wisdom modifier, the dash meaning no
    // detection), the dog rules (the check only when the scent would alert
    // them, Wisdom 16 for this check only, the described growl or cringe, the
    // trained reaction, the doubled distance before the negative modifiers),
    // the row definitions (small fires at one foot or less, large fires at
    // 6-8 feet, the oil fires of oil, creosote and coal, the
    // boat-bridge-building conflagration, the sulphur and methane odorous
    // gases, the strong-odor creatures with the 50% lair-scent roll, the
    // mild-odor pigs and herd animals and casually hygienic orcs, the no-odor
    // humans, birds and reptiles, and cooking food), the Table 15 grid (nine
    // sources across the 1-120, 121-360, 361-1000 and 1000-5000 foot bands
    // with the -99 sentinel for the printed dash), the Table 16 wind factors
    // (the strong, medium and light winds against upwind, crosswind and
    // downwind sources in the percent encoding) and the wind definitions
    // (upwind from the source, downwind away, crosswind perpendicular, strong
    // winds extinguishing torches and raising dust, medium flickering torches
    // and extinguishing candles, light almost unnoticeable).
    {
        using namespace rules;
        int bad = 0;
    if (dnvDogWisScore() != 16
            || dnvOdorDogDistanceMult() != 2
            || dnvFireSmallMaxDiameterFt() != 1
            || dnvFireLargeMinDiameterFt() != 6
            || dnvFireLargeMaxDiameterFt() != 8
            || dnvStrongOdorLairPct() != 50
            || dnvOdorBand1MaxFt() != 120
            || dnvOdorBand2MinFt() != 121
            || dnvOdorBand2MaxFt() != 360
            || dnvOdorBand3MinFt() != 361
            || dnvOdorBand3MaxFt() != 1000
            || dnvOdorBand4MinFt() != 1000
            || dnvOdorBand4MaxFt() != 5000
            || dnvT15RowCount() != 9
            || dnvT16RowCount() != 3
            || !dnvOdorWisCheckOnFirstEncounter()
            || !dnvOdorRecheckOnStrongerScent()
            || !dnvOdorRecheckOnWindShift()
            || !dnvOdorOnlyWithoutOverpoweringScent()
            || !dnvOdorCheckMadeByDm()
            || !dnvOdorNotRepeatedIfMissed()
            || !dnvOdorFullWisOnlyIfEasilyNoticed()
            || !dnvOdorCrossRefIsWisMod()
            || !dnvOdorDashMeansNoDetection()
            || !dnvDogCheckWhenAlerted()
            || !dnvDogReactionDescribed()
            || !dnvDogTrainedReactionUsed()
            || !dnvOilFireCategory()
            || !dnvConflagrationCategory()
            || !dnvOdorousGasCategory()
            || !dnvStrongOdorCreatureCategory()
            || !dnvMildOdorCreatureCategory()
            || !dnvNoOdorCreatureCategory()
            || !dnvCookingFoodCategory()
            || !dnvWindForceModifierWhenCurrents()
            || !dnvWindHalfMeansHalfDistance()
            || !dnvUpwindDefinition()
            || !dnvDownwindDefinition()
            || !dnvCrosswindDefinition()
            || !dnvStrongWindExtinguishesTorches()
            || !dnvMediumWindFlickersTorches()
            || !dnvLightWindUnnoticeable()
        )
            ++bad;
        // the Table 15 odor detection grid
        int C15[9][5] = {
            {0,0,-4,-8,-99},
            {1,2,0,-4,-8},
            {2,4,2,0,-4},
            {3,8,4,2,0},
            {4,4,2,0,-4},
            {5,0,-2,-6,-10},
            {6,-2,-6,-10,-99},
            {7,-6,-10,-99,-99},
            {8,2,0,-2,-6},
            };
        int n15[5] = {0,0,0,0,0};
        int e15[5] = {0,0,0,1,3};
        for (int b = 0;
             b < dnvT15RowCount();
             ++b) {
            int vals[5];
            vals[0] = dnvT15Src(b);
            vals[1] = dnvT15Mod1(b);
            vals[2] = dnvT15Mod2(b);
            vals[3] = dnvT15Mod3(b);
            vals[4] = dnvT15Mod4(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != C15[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++n15[c];
            }
        }
        for (int c = 0; c < 5; ++c)
            if (n15[c] != e15[c])
                ++bad;
        // the Table 16 wind effects grid
        int C16[3][4] = {
            {0,100,50,0},
            {1,200,50,10},
            {2,200,100,25},
            };
        for (int b = 0;
             b < dnvT16RowCount();
             ++b) {
            int vals[4];
            vals[0] = dnvT16Force(b);
            vals[1] = dnvT16Upwind(b);
            vals[2] = dnvT16Crosswind(b);
            vals[3] = dnvT16Downwind(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != C16[b][c])
                    ++bad;
            }
        }
        // the procedure: a Wisdom Check at first encounter, secret and
        // unannounced, rechecked only when the scent grows very strong or the
        // wind carries it harder.
    if (dnvOdorWisCheckOnFirstEncounter() != 1
            || dnvOdorRecheckOnStrongerScent() != 1
            || dnvOdorRecheckOnWindShift() != 1
            || dnvOdorCheckMadeByDm() != 1
            || dnvOdorNotRepeatedIfMissed() != 1
        )
            ++bad;
        // the dog rules: Wisdom 16 for this check only, and the distance
        // doubled before the negative modifiers apply, with the check made
        // only when the scent would alert them.
    if (dnvDogWisScore() != 16
            || dnvOdorDogDistanceMult() != 2
            || dnvDogCheckWhenAlerted() != 1
        )
            ++bad;
        // the distance bands: 1-120, 121-360, 361-1000 and 1000-5000 feet
        // from the source.
    if (dnvOdorBand1MaxFt() != 120
            || dnvOdorBand2MinFt() != 121
            || dnvOdorBand2MaxFt() != 360
            || dnvOdorBand3MinFt() != 361
            || dnvOdorBand3MaxFt() != 1000
            || dnvOdorBand4MinFt() != 1000
            || dnvOdorBand4MaxFt() != 5000
        )
            ++bad;
        // the row definitions: small fires one foot or less, large fires 6-8
        // feet, and the strong-odor lair scent only 50% likely to be
        // encountered outside the lair.
    if (dnvFireSmallMaxDiameterFt() != 1
            || dnvFireLargeMinDiameterFt() != 6
            || dnvFireLargeMaxDiameterFt() != 8
            || dnvStrongOdorLairPct() != 50
        )
            ++bad;
        // the small-fires row (the disputed cells, settled three-way by the
        // chapter read, the compiled-tables appendix reprint and the design
        // ladder): 0, -4, -8, and no detection at 1000-5000 feet.
    if (dnvT15Mod1(0) != 0
            || dnvT15Mod2(0) != -4
            || dnvT15Mod3(0) != -8
            || dnvT15Mod4(0) != -99
        )
            ++bad;
        // the conflagration row (+8/+4/+2/0, the best detection in the grid)
        // and the cooking-food row (+2/0/-2/-6).
    if (dnvT15Mod1(3) != 8
            || dnvT15Mod2(3) != 4
            || dnvT15Mod3(3) != 2
            || dnvT15Mod4(3) != 0
            || dnvT15Mod1(8) != 2
            || dnvT15Mod2(8) != 0
            || dnvT15Mod3(8) != -2
            || dnvT15Mod4(8) != -6
        )
            ++bad;
        // the dash cells: mild-odor creatures undetectable at 1000-5000 feet,
        // no-odor creatures undetectable past 360 feet.
    if (dnvT15Mod4(6) != -99
            || dnvT15Mod3(7) != -99
            || dnvT15Mod4(7) != -99
        )
            ++bad;
        // the Table 16 strong-wind row: upwind Normal, crosswind 1/2,
        // downwind no detection at all.
    if (dnvT16Upwind(0) != 100
            || dnvT16Crosswind(0) != 50
            || dnvT16Downwind(0) != 0
        )
            ++bad;
        // the Table 16 medium-wind row: upwind Double, crosswind 1/2,
        // downwind 1/10.
    if (dnvT16Upwind(1) != 200
            || dnvT16Crosswind(1) != 50
            || dnvT16Downwind(1) != 10
        )
            ++bad;
        // the Table 16 light-wind row: upwind Double, crosswind Normal,
        // downwind 1/4.
    if (dnvT16Upwind(2) != 200
            || dnvT16Crosswind(2) != 100
            || dnvT16Downwind(2) != 25
        )
            ++bad;
        // the wind-force scale: strong winds extinguish torches and raise
        // dust, medium winds flicker torches and put out candles, light winds
        // almost unnoticeable, with the upwind/crosswind/downwind direction
        // definitions.
    if (dnvStrongWindExtinguishesTorches() != 1
            || dnvMediumWindFlickersTorches() != 1
            || dnvLightWindUnnoticeable() != 1
            || dnvUpwindDefinition() != 1
            || dnvDownwindDefinition() != 1
            || dnvCrosswindDefinition() != 1
        )
            ++bad;
        // the Table 15 carries nine odor sources.
    if (dnvT15RowCount() != 9
        )
            ++bad;
        // the Table 15 grid cell-for-cell, rows 0-3: the four fire sources
        // small, large, oil and conflagration.
    if (dnvT15Src(0) != 0
            || dnvT15Mod1(0) != 0
            || dnvT15Mod2(0) != -4
            || dnvT15Mod3(0) != -8
            || dnvT15Mod4(0) != -99
            || dnvT15Src(1) != 1
            || dnvT15Mod1(1) != 2
            || dnvT15Mod2(1) != 0
            || dnvT15Mod3(1) != -4
            || dnvT15Mod4(1) != -8
            || dnvT15Src(2) != 2
            || dnvT15Mod1(2) != 4
            || dnvT15Mod2(2) != 2
            || dnvT15Mod3(2) != 0
            || dnvT15Mod4(2) != -4
            || dnvT15Src(3) != 3
            || dnvT15Mod1(3) != 8
            || dnvT15Mod2(3) != 4
            || dnvT15Mod3(3) != 2
            || dnvT15Mod4(3) != 0
        )
            ++bad;
        // the Table 15 grid cell-for-cell, rows 4-8: odorous gas, the three
        // creature strengths and cooking food.
    if (dnvT15Src(4) != 4
            || dnvT15Mod1(4) != 4
            || dnvT15Mod2(4) != 2
            || dnvT15Mod3(4) != 0
            || dnvT15Mod4(4) != -4
            || dnvT15Src(5) != 5
            || dnvT15Mod1(5) != 0
            || dnvT15Mod2(5) != -2
            || dnvT15Mod3(5) != -6
            || dnvT15Mod4(5) != -10
            || dnvT15Src(6) != 6
            || dnvT15Mod1(6) != -2
            || dnvT15Mod2(6) != -6
            || dnvT15Mod3(6) != -10
            || dnvT15Mod4(6) != -99
            || dnvT15Src(7) != 7
            || dnvT15Mod1(7) != -6
            || dnvT15Mod2(7) != -10
            || dnvT15Mod3(7) != -99
            || dnvT15Mod4(7) != -99
            || dnvT15Src(8) != 8
            || dnvT15Mod1(8) != 2
            || dnvT15Mod2(8) != 0
            || dnvT15Mod3(8) != -2
            || dnvT15Mod4(8) != -6
        )
            ++bad;
        // the Table 16 carries three wind forces.
    if (dnvT16RowCount() != 3
        )
            ++bad;
        // the Table 16 grid cell-for-cell: the strong/medium/light wind rows
        // in the percent-of-distance encoding.
    if (dnvT16Upwind(0) != 100
            || dnvT16Crosswind(0) != 50
            || dnvT16Downwind(0) != 0
            || dnvT16Upwind(1) != 200
            || dnvT16Crosswind(1) != 50
            || dnvT16Downwind(1) != 10
            || dnvT16Upwind(2) != 200
            || dnvT16Crosswind(2) != 100
            || dnvT16Downwind(2) != 25
        )
            ++bad;
        printf("R510 DSG odor detection audit: bad %d\n", bad);
        if (bad) return 1;
    }
