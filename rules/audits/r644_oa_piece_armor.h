    // ---- R644 OA piece armor audit ----
    // OA round thirty-one (capture p. 95): the Table 53 individual piece
    // armor class - the laced-armor piece steps and the backside star note
    {
        using namespace rules;
        int bad = 0;
    if (dheT53RowCount() != 9
            || dheT53AcBase() != 10
            || !dheT53StarBacksideNote()
        )
            ++bad;
        // the Table 53 grid: the piece armor class steps and the star set
        int CT53Data[9][2] = {
            {2,0},
            {1,0},
            {2,1},
            {1,1},
            {1,0},
            {2,0},
            {1,0},
            {1,0},
            {1,0},
            };
        int nT53Data[2] = {0,0};
        int eT53Data[2] = {0,0};
        for (int b = 0;
             b < dheT53RowCount();
             ++b) {
            int vals[2];
            vals[0] = dheT53Steps(b);
            vals[1] = dheT53Star(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CT53Data[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT53Data[c];
            }
        }
        for (int c = 0; c < 2; ++c)
            if (nT53Data[c] != eT53Data[c])
                ++bad;
        // the T53 row count pin
    if (dheT53RowCount() != 9
        )
            ++bad;
        // the AC-10 base pin
    if (dheT53AcBase() != 10
        )
            ++bad;
        // the backside star note pin
    if (dheT53StarBacksideNote() != 1
        )
            ++bad;
        // the do-maru row - the 2-step chest piece (capture p. 95)
    if (dheT53Steps(0) != 2
        )
            ++bad;
        // the hara-ate row - the 2 steps with the star, the backside pair
        // (capture p. 95)
    if (dheT53Steps(2) != 2
            || dheT53Star(2) != 1
        )
            ++bad;
        // the hara-ate-gawa row - the 1 step with the star, the backside pair
        // (capture p. 95)
    if (dheT53Steps(3) != 1
            || dheT53Star(3) != 1
        )
            ++bad;
        // the haramaki-do row - the 2-step do variant (capture p. 95)
    if (dheT53Steps(5) != 2
        )
            ++bad;
        // the kote row - the 1 step; the page worked example: kote alone
        // gives AC 9 from the AC-10 base (capture p. 95)
    if (dheT53Steps(6) != 1
            || dheT53AcBase() - dheT53Steps(6) != 9
        )
            ++bad;
        // the worked example sum - kote, do-maru and haidate give 4 steps, AC
        // 6 from the base (capture p. 95)
    if (dheT53Steps(0) + dheT53Steps(1) + dheT53Steps(6) != 4
        )
            ++bad;
        // the suneate tail row - the 1 step, no star; the star column is zero
        // off the backside pair (capture p. 95)
    if (dheT53Steps(8) != 1
            || dheT53Star(8) != 0
            || dheT53Star(0) != 0
        )
            ++bad;
        printf("R644 OA piece armor audit: bad %d\n", bad);
        if (bad) return 1;
    }
