    // ---- R657 OA court proficiencies audit ----
    // OA round forty-four (capture p. 108): Table 61 - the court
    // proficiencies grid, the slot costs, the base chances and the
    // always-roll markers
    {
        using namespace rules;
        int bad = 0;
    if (dhrT61RowCount() != 12
        )
            ++bad;
        // the Table 61 grid: the court slot costs, base chances and
        // always-roll markers
        int CT61Data[12][3] = {
            {2,18,0},
            {1,16,1},
            {2,17,1},
            {1,15,0},
            {1,12,1},
            {1,16,0},
            {1,17,0},
            {1,14,0},
            {1,19,0},
            {1,19,0},
            {1,12,0},
            {2,15,0},
            };
        int nT61Data[3] = {0,0,0};
        int eT61Data[3] = {0,0,0};
        for (int b = 0;
             b < dhrT61RowCount();
             ++b) {
            int vals[3];
            vals[0] = dhrT61Slots(b);
            vals[1] = dhrT61Base(b);
            vals[2] = dhrT61AlwaysRoll(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT61Data[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT61Data[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nT61Data[c] != eT61Data[c])
                ++bad;
        // the slot-cost pins - calligraphy, falconry and tea ceremony two
        // slots, the other nine one slot
    if (dhrT61Slots(0) != 2
            || dhrT61Slots(2) != 2
            || dhrT61Slots(11) != 2
            || dhrT61Slots(1) != 1
            || dhrT61Slots(9) != 1
        )
            ++bad;
        // the base-chance pins - painting and poetry 19, calligraphy 18, noh
        // 17, falconry 17, etiquette and landscape gardening 16, flower
        // arranging and tea ceremony 15, origami 14, heraldry and religion 12
    if (dhrT61Base(8) != 19
            || dhrT61Base(9) != 19
            || dhrT61Base(0) != 18
            || dhrT61Base(6) != 17
            || dhrT61Base(2) != 17
            || dhrT61Base(1) != 16
            || dhrT61Base(5) != 16
            || dhrT61Base(3) != 15
            || dhrT61Base(11) != 15
            || dhrT61Base(7) != 14
            || dhrT61Base(4) != 12
            || dhrT61Base(10) != 12
        )
            ++bad;
        // the always-roll pins - etiquette, falconry and heraldry roll, the
        // other nine never do
    if (dhrT61AlwaysRoll(1) != 1
            || dhrT61AlwaysRoll(2) != 1
            || dhrT61AlwaysRoll(4) != 1
            || dhrT61AlwaysRoll(0) != 0
            || dhrT61AlwaysRoll(6) != 0
            || dhrT61AlwaysRoll(10) != 0
            || dhrT61AlwaysRoll(11) != 0
        )
            ++bad;
        // the row-count pin - twelve court proficiencies
    if (dhrT61RowCount() != 12
        )
            ++bad;
        printf("R657 OA court proficiencies audit: bad %d\n", bad);
        if (bad) return 1;
    }
