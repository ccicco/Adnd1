    // ---- R691 OA style combinations audit ----
    // OA round seventy-eight (capture p. 226): Table 69 - the martial style
    // combinations grid, the three forms and eight methods across four
    // columns with the derived-style examples, single-pass pins per the
    // Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (djeOA69RowCount() != 11
        )
            ++bad;
        // the Table 69 grid - the eleven rows across four columns
        int COA69Data[11][4] = {
            {1,1,4,0},
            {3,0,2,0},
            {2,1,3,0},
            {1,1,4,1},
            {1,1,2,2},
            {2,1,2,3},
            {2,1,1,4},
            {1,1,1,4},
            {1,1,2,2},
            {2,1,1,5},
            {1,1,0,6},
            };
        for (int b = 0;
             b < djeOA69RowCount();
             ++b) {
            int vals[4];
            vals[0] = djeOA69ACMod(b);
            vals[1] = djeOA69AtMod(b);
            vals[2] = djeOA69DamageMod(b);
            vals[3] = djeOA69BodyPart(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != COA69Data[b][c])
                    ++bad;
            }
        }
        // the form rows - Hard 1/1/4, Soft 3/0/2, Hard/Soft 2/1/3
    if (djeOA69ACMod(0) != 1
            || djeOA69AtMod(0) != 1
            || djeOA69DamageMod(0) != 4
            || djeOA69ACMod(1) != 3
            || djeOA69AtMod(1) != 0
            || djeOA69DamageMod(1) != 2
            || djeOA69ACMod(2) != 2
            || djeOA69DamageMod(2) != 3
        )
            ++bad;
        // the method AC mods - Kick, Lock and Throw at 1, Movement, Push and
        // Vital Area at 2
    if (djeOA69ACMod(3) != 1
            || djeOA69ACMod(4) != 1
            || djeOA69ACMod(5) != 2
            || djeOA69ACMod(6) != 2
            || djeOA69ACMod(9) != 2
            || djeOA69ACMod(10) != 1
        )
            ++bad;
        // the damage mods - the Kick 4 the highest method, Push, Strike and
        // Vital Area the 1s, Weapon the by-weapon 0
    if (djeOA69DamageMod(3) != 4
            || djeOA69DamageMod(6) != 1
            || djeOA69DamageMod(7) != 1
            || djeOA69DamageMod(9) != 1
            || djeOA69DamageMod(10) != 0
        )
            ++bad;
        // the body parts - Foot, Body, Legs, Hand, Hand, Body, Hand-and-Foot,
        // Hand-and-Arm
    if (djeOA69BodyPart(3) != 1
            || djeOA69BodyPart(4) != 2
            || djeOA69BodyPart(5) != 3
            || djeOA69BodyPart(6) != 4
            || djeOA69BodyPart(8) != 2
            || djeOA69BodyPart(9) != 5
            || djeOA69BodyPart(10) != 6
        )
            ++bad;
        // the derived style - Hard plus Kick: the AC 10-1-1, the attacks 1+1
    if (10 - djeOA69ACMod(0) - djeOA69ACMod(3) != 8
            || djeOA69AtMod(0) + djeOA69AtMod(3) != 2
        )
            ++bad;
        // the derived damage - Hard plus Kick the 8, Soft plus Movement the 4
    if (djeOA69DamageMod(0) + djeOA69DamageMod(3) != 8
            || djeOA69DamageMod(1) + djeOA69DamageMod(5) != 4
        )
            ++bad;
        printf("R691 OA style combinations audit: bad %d\n", bad);
        if (bad) return 1;
    }
