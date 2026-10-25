    // ---- R654 OA artisan proficiencies audit ----
    // OA round forty-one (capture p. 103): Table 58 - the artisan
    // proficiencies grid, the slot costs, the base chances and the
    // always-roll markers
    {
        using namespace rules;
        int bad = 0;
    if (dhoT58RowCount() != 18
        )
            ++bad;
        // the Table 58 grid: the artisan slot costs, base chances and
        // always-roll markers
        int CT58Data[18][3] = {
            {2,16,1},
            {1,14,0},
            {1,15,1},
            {1,16,0},
            {1,15,0},
            {2,18,0},
            {2,17,1},
            {2,16,0},
            {1,14,0},
            {1,12,1},
            {1,18,0},
            {1,16,0},
            {1,17,0},
            {1,19,0},
            {1,16,0},
            {1,15,0},
            {3,17,1},
            {1,15,0},
            };
        int nT58Data[3] = {0,0,0};
        int eT58Data[3] = {0,0,0};
        for (int b = 0;
             b < dhoT58RowCount();
             ++b) {
            int vals[3];
            vals[0] = dhoT58Slots(b);
            vals[1] = dhoT58Base(b);
            vals[2] = dhoT58AlwaysRoll(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT58Data[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT58Data[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nT58Data[c] != eT58Data[c])
                ++bad;
        // the slot-cost pins - armorer 2, weaponsmith 3, the single-slot
        // artisans 1, the double-slot civil engineer, herbalist and jeweler 2
    if (dhoT58Slots(0) != 2
            || dhoT58Slots(16) != 3
            || dhoT58Slots(1) != 1
            || dhoT58Slots(5) != 2
            || dhoT58Slots(6) != 2
            || dhoT58Slots(7) != 2
        )
            ++bad;
        // the base-chance pins - navigator 12, silk maker 19, paper-maker 18,
        // civil engineer 18, masseur and blacksmith 14
    if (dhoT58Base(9) != 12
            || dhoT58Base(13) != 19
            || dhoT58Base(10) != 18
            || dhoT58Base(5) != 18
            || dhoT58Base(8) != 14
            || dhoT58Base(1) != 14
        )
            ++bad;
        // the always-roll pins - armorer, bowyer, herbalist, navigator and
        // weaponsmith roll, the other thirteen never do
    if (dhoT58AlwaysRoll(0) != 1
            || dhoT58AlwaysRoll(2) != 1
            || dhoT58AlwaysRoll(6) != 1
            || dhoT58AlwaysRoll(9) != 1
            || dhoT58AlwaysRoll(16) != 1
            || dhoT58AlwaysRoll(1) != 0
            || dhoT58AlwaysRoll(3) != 0
            || dhoT58AlwaysRoll(13) != 0
            || dhoT58AlwaysRoll(17) != 0
        )
            ++bad;
        // the row-count pin - eighteen artisan proficiencies
    if (dhoT58RowCount() != 18
        )
            ++bad;
        printf("R654 OA artisan proficiencies audit: bad %d\n", bad);
        if (bad) return 1;
    }
