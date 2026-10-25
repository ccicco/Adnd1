    // ---- R692 OA special maneuvers audit ----
    // OA round seventy-nine (capture p. 227): Table 70 - the martial arts
    // special maneuvers grid, the thirty-six ranked maneuvers across the nine
    // method columns with the hard, soft and hard/soft form tags, single-pass
    // pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (djfOA70RowCount() != 36
            || djfOA70KickCount() != 3
            || djfOA70MoveCount() != 7
            || djfOA70StrikeCount() != 3
            || djfOA70WeaponCount() != 3
            || djfOA70LockCount() != 4
            || djfOA70ThrowCount() != 4
            || djfOA70TrainCount() != 6
            || djfOA70PushCount() != 3
            || djfOA70VitalCount() != 3
        )
            ++bad;
        // the Table 70 grid - the thirty-six maneuvers across three columns
        int COA70Data[36][3] = {
            {1,1,0},
            {1,2,0},
            {1,3,2},
            {2,1,2},
            {2,2,1},
            {2,3,1},
            {2,4,1},
            {2,5,1},
            {2,6,2},
            {2,7,2},
            {3,1,0},
            {3,2,0},
            {3,3,0},
            {4,1,2},
            {4,2,2},
            {4,3,1},
            {5,1,2},
            {5,2,1},
            {5,3,2},
            {5,4,2},
            {6,1,2},
            {6,2,2},
            {6,3,0},
            {6,4,1},
            {7,1,2},
            {7,2,1},
            {7,3,1},
            {7,4,1},
            {7,5,0},
            {7,6,1},
            {8,1,1},
            {8,2,1},
            {8,3,1},
            {9,1,1},
            {9,2,1},
            {9,3,1},
            };
        for (int b = 0;
             b < djfOA70RowCount();
             ++b) {
            int vals[3];
            vals[0] = djfOA70Method(b);
            vals[1] = djfOA70Rank(b);
            vals[2] = djfOA70Form(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != COA70Data[b][c])
                    ++bad;
            }
        }
        // the Kick column - Circle Kick 1 hard, Flying Kick 2 hard, Backward
        // Kick 3 hard/soft
    if (djfOA70Method(0) != 1
            || djfOA70Rank(0) != 1
            || djfOA70Form(0) != 0
            || djfOA70Rank(1) != 2
            || djfOA70Form(1) != 0
            || djfOA70Rank(2) != 3
            || djfOA70Form(2) != 2
        )
            ++bad;
        // the Movement column - seven deep, Feint 1 hard/soft through Slow
        // Resistance 7 hard/soft, the Missile Deflection 4 soft
    if (djfOA70Method(3) != 2
            || djfOA70Method(9) != 2
            || djfOA70Rank(3) != 1
            || djfOA70Rank(9) != 7
            || djfOA70Form(3) != 2
            || djfOA70Form(6) != 1
            || djfOA70Form(8) != 2
            || djfOA70Form(9) != 2
        )
            ++bad;
        // the Strike column - all three maneuvers hard
    if (djfOA70Method(10) != 3
            || djfOA70Form(10) != 0
            || djfOA70Form(11) != 0
            || djfOA70Form(12) != 0
            || djfOA70Rank(12) != 3
        )
            ++bad;
        // the Weapon column - Weapon Catch and Weapon Breaker hard/soft,
        // Steel Cloth soft
    if (djfOA70Method(13) != 4
            || djfOA70Form(13) != 2
            || djfOA70Form(14) != 2
            || djfOA70Rank(14) != 2
            || djfOA70Form(15) != 1
        )
            ++bad;
        // the Lock column - Choke Hold 1 through Immobilizing 4, Locking
        // Block the soft
    if (djfOA70Method(16) != 5
            || djfOA70Rank(16) != 1
            || djfOA70Rank(19) != 4
            || djfOA70Form(17) != 1
            || djfOA70Form(19) != 2
        )
            ++bad;
        // the Throw column - Fall 1 and Instant Stand 2 hard/soft, Hurl 3
        // hard, Great Throw 4 soft
    if (djfOA70Method(20) != 6
            || djfOA70Rank(21) != 2
            || djfOA70Form(22) != 0
            || djfOA70Form(23) != 1
            || djfOA70Rank(23) != 4
        )
            ++bad;
        // the Mental and Physical Training column - Meditation 1 through
        // Levitation 6, All-Around Sight 2 soft, Ironskin 5 the hard
    if (djfOA70Method(24) != 7
            || djfOA70Rank(24) != 1
            || djfOA70Rank(29) != 6
            || djfOA70Form(25) != 1
            || djfOA70Form(28) != 0
            || djfOA70Form(29) != 1
        )
            ++bad;
        // the Push and Vital Area columns - all six maneuvers soft, the Vital
        // ranks 1-3
    if (djfOA70Method(30) != 8
            || djfOA70Form(30) != 1
            || djfOA70Form(31) != 1
            || djfOA70Form(32) != 1
            || djfOA70Method(33) != 9
            || djfOA70Rank(35) != 3
            || djfOA70Form(35) != 1
        )
            ++bad;
        // the per-method counts - Kick 3, Movement 7, Throw 4, Training 6,
        // Vital Area 3, the grid the 36
    if (djfOA70KickCount() != 3
            || djfOA70MoveCount() != 7
            || djfOA70ThrowCount() != 4
            || djfOA70TrainCount() != 6
            || djfOA70VitalCount() != 3
            || djfOA70RowCount() != 36
        )
            ++bad;
        // the printed progression example - Circle Kick 1, Flying Kick 2,
        // All-Around Sight 2, Backward Kick 3
    if (djfOA70Rank(0) != 1
            || djfOA70Rank(1) != 2
            || djfOA70Rank(25) != 2
            || djfOA70Rank(2) != 3
        )
            ++bad;
        printf("R692 OA special maneuvers audit: bad %d\n", bad);
        if (bad) return 1;
    }
