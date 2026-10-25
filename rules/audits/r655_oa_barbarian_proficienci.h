    // ---- R655 OA barbarian proficiencies audit ----
    // OA round forty-two (capture p. 104): Table 59 - the barbarian
    // proficiencies grid, the slot costs, the base chances and the
    // always-roll markers
    {
        using namespace rules;
        int bad = 0;
    if (dhpT59RowCount() != 8
        )
            ++bad;
        // the Table 59 grid: the barbarian slot costs, base chances and
        // always-roll markers
        int CT59Data[8][3] = {
            {1,15,0},
            {1,8,1},
            {1,16,1},
            {1,12,1},
            {1,14,1},
            {2,16,1},
            {2,15,0},
            {3,17,1},
            };
        int nT59Data[3] = {0,0,0};
        int eT59Data[3] = {0,0,0};
        for (int b = 0;
             b < dhpT59RowCount();
             ++b) {
            int vals[3];
            vals[0] = dhpT59Slots(b);
            vals[1] = dhpT59Base(b);
            vals[2] = dhpT59AlwaysRoll(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT59Data[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT59Data[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nT59Data[c] != eT59Data[c])
                ++bad;
        // the slot-cost pins - chanting through snare building one slot,
        // sound imitation and survival two, tracking three
    if (dhpT59Slots(0) != 1
            || dhpT59Slots(4) != 1
            || dhpT59Slots(5) != 2
            || dhpT59Slots(6) != 2
            || dhpT59Slots(7) != 3
        )
            ++bad;
        // the base-chance pins - fire building 8, signaling 12, snare
        // building 14, chanting and survival 15, running and sound imitation
        // 16, tracking 17
    if (dhpT59Base(1) != 8
            || dhpT59Base(3) != 12
            || dhpT59Base(4) != 14
            || dhpT59Base(0) != 15
            || dhpT59Base(6) != 15
            || dhpT59Base(2) != 16
            || dhpT59Base(5) != 16
            || dhpT59Base(7) != 17
        )
            ++bad;
        // the always-roll pins - fire building, running, signaling, snare
        // building, sound imitation and tracking roll, chanting and survival
        // never do
    if (dhpT59AlwaysRoll(1) != 1
            || dhpT59AlwaysRoll(2) != 1
            || dhpT59AlwaysRoll(3) != 1
            || dhpT59AlwaysRoll(4) != 1
            || dhpT59AlwaysRoll(5) != 1
            || dhpT59AlwaysRoll(7) != 1
            || dhpT59AlwaysRoll(0) != 0
            || dhpT59AlwaysRoll(6) != 0
        )
            ++bad;
        // the row-count pin - eight barbarian proficiencies
    if (dhpT59RowCount() != 8
        )
            ++bad;
        printf("R655 OA barbarian proficiencies audit: bad %d\n", bad);
        if (bad) return 1;
    }
