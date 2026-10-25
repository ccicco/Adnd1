    // ---- R683 OA horseback bowfire modifiers audit ----
    // OA round seventy (capture p. 220): Table 67 - the horseback bowfire
    // modifiers - the three speed bands of the animal with the -1, -3 and -5
    // to-hit penalties, the cumulative clause, the 30-degree slight-turning
    // limit and the horse-like creatures clause, single-pass pins per the
    // Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (diwOA67TurnDegrees() != 30
            || diwOA67BandCount() != 3
            || !diwOA67CumulativeModifiers()
            || !diwOA67SharperTurnsPreventFire()
            || !diwOA67HorseLikeCreaturesApply()
        )
            ++bad;
        // the Table 67 grid - the three speed bands and their modifiers
        int COA67Data[3][3] = {
            {0,3,-1},
            {4,5,-3},
            {6,8,-5},
            };
        for (int b = 0;
             b < diwOA67BandCount();
             ++b) {
            int vals[3];
            vals[0] = diwOA67MinEighths(b);
            vals[1] = diwOA67MaxEighths(b);
            vals[2] = diwOA67Modifier(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != COA67Data[b][c])
                    ++bad;
            }
        }
        // the modifier column - the -1, -3 and -5 of the three speed bands
    if (diwOA67Modifier(0) != -1
            || diwOA67Modifier(1) != -3
            || diwOA67Modifier(2) != -5
        )
            ++bad;
        // the band floors - 0, 4 and 6 eighths of normal movement
    if (diwOA67MinEighths(0) != 0
            || diwOA67MinEighths(1) != 4
            || diwOA67MinEighths(2) != 6
        )
            ++bad;
        // the band ceilings - 3, 5 and 8 eighths of normal movement
    if (diwOA67MaxEighths(0) != 3
            || diwOA67MaxEighths(1) != 5
            || diwOA67MaxEighths(2) != 8
        )
            ++bad;
        // the band contiguity - each ceiling abutting the next floor
    if (diwOA67MaxEighths(0) != diwOA67MinEighths(1) - 1
            || diwOA67MaxEighths(1) != diwOA67MinEighths(2) - 1
        )
            ++bad;
        // the turn pin - the 30 degrees of slight turning
    if (diwOA67TurnDegrees() != 30
        )
            ++bad;
        printf("R683 OA horseback bowfire modifiers audit: bad %d\n", bad);
        if (bad) return 1;
    }
