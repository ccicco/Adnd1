    // ---- R653 OA character proficiencies audit ----
    // OA round forty (capture p. 99): Table 56 - the character proficiencies
    // grid, the initial proficiencies, the levels per added proficiency and
    // the non-proficiency penalties by class, with the ninja weapon-only rule
    {
        using namespace rules;
        int bad = 0;
    if (dhnT56ClassCount() != 8
            || !dhnNinjaNinjaWeaponsOnly()
        )
            ++bad;
        // the Table 56 grid: the initial proficiencies, the levels per added
        // proficiency and the non-proficiency penalties by class
        int CT56Data[8][3] = {
            {5,1,2},
            {6,2,4},
            {4,3,2},
            {3,2,3},
            {9,3,2},
            {4,2,2},
            {6,2,5},
            {2,3,4},
            };
        int nT56Data[3] = {0,0,0};
        int eT56Data[3] = {0,0,0};
        for (int b = 0;
             b < dhnT56ClassCount();
             ++b) {
            int vals[3];
            vals[0] = dhnT56InitialProf(b);
            vals[1] = dhnT56LevelsPerProf(b);
            vals[2] = dhnT56NonprofPenalty(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT56Data[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT56Data[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nT56Data[c] != eT56Data[c])
                ++bad;
        // the Table 56 initial-proficiency pins - samurai 5, shukenja 6,
        // sohei 4, kensai 3, o. barbarian 9, bushi 4, wu jen 6, ninja 2
    if (dhnT56InitialProf(0) != 5
            || dhnT56InitialProf(1) != 6
            || dhnT56InitialProf(2) != 4
            || dhnT56InitialProf(3) != 3
            || dhnT56InitialProf(4) != 9
            || dhnT56InitialProf(5) != 4
            || dhnT56InitialProf(6) != 6
            || dhnT56InitialProf(7) != 2
        )
            ++bad;
        // the levels-per-added-proficiency pins - 1/1 samurai, 1/2 shukenja
        // kensai bushi wu jen, 1/3 sohei o. barbarian ninja
    if (dhnT56LevelsPerProf(0) != 1
            || dhnT56LevelsPerProf(1) != 2
            || dhnT56LevelsPerProf(2) != 3
            || dhnT56LevelsPerProf(3) != 2
            || dhnT56LevelsPerProf(4) != 3
            || dhnT56LevelsPerProf(5) != 2
            || dhnT56LevelsPerProf(6) != 2
            || dhnT56LevelsPerProf(7) != 3
        )
            ++bad;
        // the non-proficiency penalty pins - samurai -2, shukenja -4, sohei
        // -2, kensai -3, o. barbarian -2, bushi -2, wu jen -5, ninja -4
    if (dhnT56NonprofPenalty(0) != 2
            || dhnT56NonprofPenalty(1) != 4
            || dhnT56NonprofPenalty(2) != 2
            || dhnT56NonprofPenalty(3) != 3
            || dhnT56NonprofPenalty(4) != 2
            || dhnT56NonprofPenalty(5) != 2
            || dhnT56NonprofPenalty(6) != 5
            || dhnT56NonprofPenalty(7) != 4
        )
            ++bad;
        // the ninja pin - the ninja weapon-only rule with the other-class
        // penalty for all other weapons
    if (dhnNinjaNinjaWeaponsOnly() != 1
        )
            ++bad;
        printf("R653 OA character proficiencies audit: bad %d\n", bad);
        if (bad) return 1;
    }
