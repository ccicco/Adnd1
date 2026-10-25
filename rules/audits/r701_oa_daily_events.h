    // ---- R701 OA daily events audit ----
    // OA round eighty-eight (capture pp. 247-248): Table 73 - the daily
    // events grid, the twenty-eight die-range rows across the five location
    // columns with the twenty-nine event names, plus the frequency chart,
    // single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (djoOA73RowCount() != 28
            || djoOA73NameCount() != 29
            || djoOA73NoEventId() != 18
            || djoOA73NoEventMinRoll() != 51
            || djoOA73CourtMaxPerDay() != 1
            || djoOA73CityMaxPerDay() != 1
            || djoOA73RuralMaxPerDay() != 2
            || djoOA73WildernessMaxPerDay() != 3
            || djoOA73OceanMaxPerDay() != 2
            || !djoOA73ColumnByLocation()
            || !djoOA73RollTheMax()
            || !djoOA73ManyRollsNoEvent()
        )
            ++bad;
        // the Table 73 grid - the twenty-eight die-range rows across the five
        // location columns
        int COA73Data[28][7] = {
            {1,50,18,18,18,18,18},
            {51,51,4,6,2,1,3},
            {52,53,4,6,2,16,3},
            {54,55,4,6,2,16,16},
            {56,60,4,7,2,16,16},
            {61,63,6,8,5,16,16},
            {64,65,6,11,5,16,16},
            {66,69,7,11,9,16,16},
            {70,70,10,11,9,16,16},
            {71,72,10,12,16,16,16},
            {73,77,12,12,16,16,16},
            {78,79,12,13,16,16,20},
            {80,80,15,15,16,16,20},
            {81,81,15,15,27,16,20},
            {82,82,15,16,27,19,20},
            {83,83,16,16,27,22,20},
            {84,84,21,16,24,22,20},
            {85,86,21,29,24,22,20},
            {87,87,25,29,24,22,20},
            {88,88,25,29,24,22,23},
            {89,90,25,29,17,24,23},
            {91,91,25,29,29,24,23},
            {92,92,29,29,29,26,23},
            {93,93,29,29,29,26,26},
            {94,94,29,29,29,27,26},
            {95,95,29,18,29,28,26},
            {96,98,29,18,18,28,26},
            {99,100,29,18,18,28,14},
            };
        for (int b = 0;
             b < djoOA73RowCount();
             ++b) {
            int vals[7];
            vals[0] = djoOA73MinRoll(b);
            vals[1] = djoOA73MaxRoll(b);
            vals[2] = djoOA73CourtEvent(b);
            vals[3] = djoOA73CityEvent(b);
            vals[4] = djoOA73RuralEvent(b);
            vals[5] = djoOA73WildEvent(b);
            vals[6] = djoOA73OceanEvent(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != COA73Data[b][c])
                    ++bad;
            }
        }
        // the open - the rows 01-50 No Event ordinal 18 in all five columns,
        // the first event at 51
    if (djoOA73MinRoll(0) != 1
            || djoOA73MaxRoll(0) != 50
            || djoOA73CourtEvent(0) != 18
            || djoOA73CityEvent(0) != 18
            || djoOA73RuralEvent(0) != 18
            || djoOA73WildEvent(0) != 18
            || djoOA73OceanEvent(0) != 18
            || djoOA73MinRoll(1) != 51
            || djoOA73CourtEvent(1) != 4
            || djoOA73CityEvent(1) != 6
            || djoOA73RuralEvent(1) != 2
            || djoOA73WildEvent(1) != 1
            || djoOA73OceanEvent(1) != 3
        )
            ++bad;
        // the close - VIP 92-100 ordinal 29 in court, the city dashes No
        // Event from 95, the Traveler 95-100, Land the 99-100
    if (djoOA73CourtEvent(22) != 29
            || djoOA73CourtEvent(27) != 29
            || djoOA73CityEvent(25) != 18
            || djoOA73WildEvent(25) != 28
            || djoOA73WildEvent(27) != 28
            || djoOA73OceanEvent(27) != 14
            || djoOA73MaxRoll(27) != 100
        )
            ++bad;
        // the ocean bands - Becalmed 51-53 ordinal 3, Monster 54-77, Pirates
        // 78-87 ordinal 20, Ship 88-92 ordinal 23, Storm 93-98, Land the lone
        // close
    if (djoOA73OceanEvent(2) != 3
            || djoOA73OceanEvent(4) != 16
            || djoOA73OceanEvent(11) != 20
            || djoOA73OceanEvent(19) != 23
            || djoOA73OceanEvent(22) != 23
            || djoOA73OceanEvent(23) != 26
            || djoOA73OceanEvent(26) != 26
            || djoOA73OceanEvent(27) != 14
        )
            ++bad;
        // the wilderness bands - Bandit Camp the lone 51 ordinal 1, Monster
        // 52-81, Nobles the lone 82 ordinal 19, Ruins 83-88 ordinal 22,
        // Shrine 89-91 ordinal 24, Storm 92-93, Stranger the lone 94 ordinal
        // 27
    if (djoOA73WildEvent(1) != 1
            || djoOA73WildEvent(2) != 16
            || djoOA73WildEvent(13) != 16
            || djoOA73WildEvent(14) != 19
            || djoOA73WildEvent(15) != 22
            || djoOA73WildEvent(19) != 22
            || djoOA73WildEvent(20) != 24
            || djoOA73WildEvent(21) != 24
            || djoOA73WildEvent(22) != 26
            || djoOA73WildEvent(24) != 27
        )
            ++bad;
        // the court bands - Contest 51-60 ordinal 4, Duel 61-65 ordinal 6,
        // Entreaty 66-69 ordinal 7, Illness 70-72 ordinal 10, Invitation
        // 73-79 ordinal 12, Maiden 80-83 ordinal 15, Plot 84-86 ordinal 21,
        // Special 87-91 ordinal 25
    if (djoOA73CourtEvent(1) != 4
            || djoOA73CourtEvent(4) != 4
            || djoOA73CourtEvent(5) != 6
            || djoOA73CourtEvent(7) != 7
            || djoOA73CourtEvent(8) != 10
            || djoOA73CourtEvent(10) != 12
            || djoOA73CourtEvent(12) != 15
            || djoOA73CourtEvent(16) != 21
            || djoOA73CourtEvent(18) != 25
        )
            ++bad;
        // the rural bands - Bandits 51-60 ordinal 2, Crime 61-65 ordinal 5,
        // Haunting 66-70 ordinal 9, Monster 71-80 ordinal 16, Stranger 81-83
        // ordinal 27, Shrine 84-88 ordinal 24, Mystery 89-90 ordinal 17, VIP
        // 91-94 ordinal 29
    if (djoOA73RuralEvent(1) != 2
            || djoOA73RuralEvent(4) != 2
            || djoOA73RuralEvent(6) != 5
            || djoOA73RuralEvent(8) != 9
            || djoOA73RuralEvent(9) != 16
            || djoOA73RuralEvent(15) != 27
            || djoOA73RuralEvent(16) != 24
            || djoOA73RuralEvent(19) != 24
            || djoOA73RuralEvent(20) != 17
            || djoOA73RuralEvent(24) != 29
        )
            ++bad;
        // the city bands - Duel 51-55 ordinal 6, Entreaty 56-60 ordinal 7,
        // Fire Small 61-63 ordinal 8, Insult 64-70 ordinal 11, Invitation
        // 71-79 ordinal 12, Kidnapping 78-79 ordinal 13
    if (djoOA73CityEvent(1) != 6
            || djoOA73CityEvent(3) != 6
            || djoOA73CityEvent(4) != 7
            || djoOA73CityEvent(5) != 8
            || djoOA73CityEvent(6) != 11
            || djoOA73CityEvent(8) != 11
            || djoOA73CityEvent(9) != 12
            || djoOA73CityEvent(11) != 13
        )
            ++bad;
        // the row 88 OCR repair - Special 25 / VIP 29 / Shrine 24 / Ruins 22
        // / Ship 23 read from the column bands
    if (djoOA73CourtEvent(19) != 25
            || djoOA73CityEvent(19) != 29
            || djoOA73RuralEvent(19) != 24
            || djoOA73WildEvent(19) != 22
            || djoOA73OceanEvent(19) != 23
        )
            ++bad;
        // the frequency chart - the 1/1/2/3/2 events per day, the column by
        // location, the max rolled, the common no-event
    if (djoOA73CourtMaxPerDay() != 1
            || djoOA73CityMaxPerDay() != 1
            || djoOA73RuralMaxPerDay() != 2
            || djoOA73WildernessMaxPerDay() != 3
            || djoOA73OceanMaxPerDay() != 2
            || djoOA73ColumnByLocation() != 1
            || djoOA73RollTheMax() != 1
            || djoOA73ManyRollsNoEvent() != 1
        )
            ++bad;
        // the contiguity - each row beginning where the last ended, the 100
        // the close
    if (djoOA73MinRoll(1) != djoOA73MaxRoll(0) + 1
            || djoOA73MinRoll(5) != djoOA73MaxRoll(4) + 1
            || djoOA73MinRoll(12) != djoOA73MaxRoll(11) + 1
            || djoOA73MinRoll(18) != djoOA73MaxRoll(17) + 1
            || djoOA73MinRoll(27) != djoOA73MaxRoll(26) + 1
            || djoOA73MaxRoll(27) != 100
        )
            ++bad;
        printf("R701 OA daily events audit: bad %d\n", bad);
        if (bad) return 1;
    }
