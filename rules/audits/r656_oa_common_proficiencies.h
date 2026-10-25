    // ---- R656 OA common proficiencies audit ----
    // OA round forty-three (capture p. 106): Table 60 - the common
    // proficiencies grid, the slot costs, the base chances and the
    // always-roll markers
    {
        using namespace rules;
        int bad = 0;
    if (dhqT60RowCount() != 17
        )
            ++bad;
        // the Table 60 grid: the common slot costs, base chances and
        // always-roll markers
        int CT60Data[17][3] = {
            {1,15,0},
            {2,14,1},
            {1,16,0},
            {1,17,0},
            {1,17,0},
            {1,16,1},
            {1,18,1},
            {1,16,1},
            {1,14,0},
            {1,-99,0},
            {1,16,1},
            {1,17,0},
            {1,10,0},
            {1,15,0},
            {1,17,0},
            {1,16,0},
            {1,10,1},
            };
        int nT60Data[3] = {0,0,0};
        int eT60Data[3] = {0,1,0};
        for (int b = 0;
             b < dhqT60RowCount();
             ++b) {
            int vals[3];
            vals[0] = dhqT60Slots(b);
            vals[1] = dhqT60Base(b);
            vals[2] = dhqT60AlwaysRoll(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT60Data[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT60Data[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nT60Data[c] != eT60Data[c])
                ++bad;
        // the slot-cost pins - animal handling two slots, the other sixteen
        // one slot
    if (dhqT60Slots(1) != 2
            || dhqT60Slots(0) != 1
            || dhqT60Slots(9) != 1
            || dhqT60Slots(16) != 1
        )
            ++bad;
        // the base-chance pins - reading/writing and swimming 10,
        // horsemanship 18, fishing and juggling and small water craft 16 per
        // the print read, the iaijutsu dash as the sentinel
    if (dhqT60Base(12) != 10
            || dhqT60Base(16) != 10
            || dhqT60Base(6) != 18
            || dhqT60Base(4) != 17
            || dhqT60Base(10) != 16
            || dhqT60Base(15) != 16
            || dhqT60Base(9) != -99
        )
            ++bad;
        // the base-chance ladder pins - the uncontested cells (agriculture
        // 15, animal handling and husbandry 14, cooking 16, dance and music
        // and singing 17, gaming 16, sailing craft 15)
    if (dhqT60Base(0) != 15
            || dhqT60Base(1) != 14
            || dhqT60Base(8) != 14
            || dhqT60Base(2) != 16
            || dhqT60Base(3) != 17
            || dhqT60Base(5) != 16
            || dhqT60Base(11) != 17
            || dhqT60Base(13) != 15
            || dhqT60Base(14) != 17
        )
            ++bad;
        // the always-roll pins - animal handling, gaming, horsemanship,
        // hunting, juggling and swimming roll, the others never do
    if (dhqT60AlwaysRoll(1) != 1
            || dhqT60AlwaysRoll(5) != 1
            || dhqT60AlwaysRoll(6) != 1
            || dhqT60AlwaysRoll(7) != 1
            || dhqT60AlwaysRoll(10) != 1
            || dhqT60AlwaysRoll(16) != 1
            || dhqT60AlwaysRoll(0) != 0
            || dhqT60AlwaysRoll(9) != 0
            || dhqT60AlwaysRoll(12) != 0
            || dhqT60AlwaysRoll(15) != 0
        )
            ++bad;
        // the row-count pin - seventeen common proficiencies
    if (dhqT60RowCount() != 17
        )
            ++bad;
        printf("R656 OA common proficiencies audit: bad %d\n", bad);
        if (bad) return 1;
    }
