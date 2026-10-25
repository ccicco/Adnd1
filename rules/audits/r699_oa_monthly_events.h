    // ---- R699 OA monthly events audit ----
    // OA round eighty-six (capture p. 238): Table 72 - the monthly events
    // grid, the forty die-range rows across the three columns with the thirty
    // event names and the contiguous ranges, single-pass pins per the Chapter
    // 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (djmOA72RowCount() != 40
            || djmOA72NameCount() != 30
            || djmOA72NoEventId() != 23
            || djmOA72AccidentId() != 1
            || djmOA72WarNoEventMin() != 81
            || djmOA72WarNoEventMax() != 100
            || djmOA72DisasterNoEventMin() != 95
            || djmOA72OtherNoEventMin() != 93
            || !djmOA72OneEventPerMonth()
            || !djmOA72YearlyEventSteersColumn()
            || !djmOA72DMMaySubstitute()
        )
            ++bad;
        // the Table 72 grid - the forty die-range rows across the three
        // columns
        int COA72Data[40][5] = {
            {1,5,1,1,1},
            {6,7,2,3,3},
            {8,10,2,3,4},
            {11,15,5,3,2},
            {16,20,6,4,5},
            {21,22,8,4,5},
            {23,25,8,2,5},
            {26,27,9,2,5},
            {28,28,10,2,6},
            {29,30,13,2,6},
            {31,32,14,2,9},
            {33,33,14,5,9},
            {34,35,15,5,9},
            {36,37,15,5,11},
            {38,40,15,6,11},
            {41,41,15,6,13},
            {42,43,16,6,13},
            {44,44,16,6,17},
            {45,49,16,7,17},
            {50,50,16,8,17},
            {51,51,16,8,19},
            {52,54,17,8,19},
            {55,55,20,11,19},
            {56,60,20,11,21},
            {61,61,24,12,22},
            {62,65,26,12,22},
            {66,66,26,12,22},
            {67,68,27,13,22},
            {69,69,27,13,24},
            {70,71,27,14,24},
            {72,73,28,14,24},
            {74,78,28,17,24},
            {79,80,29,18,29},
            {81,82,23,18,29},
            {83,83,23,21,29},
            {84,87,23,21,30},
            {88,92,23,25,30},
            {93,93,23,28,23},
            {94,94,23,30,23},
            {95,100,23,23,23},
            };
        for (int b = 0;
             b < djmOA72RowCount();
             ++b) {
            int vals[5];
            vals[0] = djmOA72MinRoll(b);
            vals[1] = djmOA72MaxRoll(b);
            vals[2] = djmOA72WarEvent(b);
            vals[3] = djmOA72DisasterEvent(b);
            vals[4] = djmOA72OtherEvent(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != COA72Data[b][c])
                    ++bad;
            }
        }
        // the open rows - Accident 01-05 in all three columns, No Event
        // 95-100 in all three
    if (djmOA72MinRoll(0) != 1
            || djmOA72MaxRoll(0) != 5
            || djmOA72WarEvent(0) != 1
            || djmOA72DisasterEvent(0) != 1
            || djmOA72OtherEvent(0) != 1
            || djmOA72MinRoll(39) != 95
            || djmOA72MaxRoll(39) != 100
            || djmOA72WarEvent(39) != 23
            || djmOA72DisasterEvent(39) != 23
            || djmOA72OtherEvent(39) != 23
        )
            ++bad;
        // the war column mid - Incursion Major 34-41 ordinal 15, Incursion
        // Minor 42-51 ordinal 16
    if (djmOA72WarEvent(12) != 15
            || djmOA72WarEvent(15) != 15
            || djmOA72MaxRoll(15) != 41
            || djmOA72WarEvent(16) != 16
            || djmOA72WarEvent(20) != 16
            || djmOA72MaxRoll(20) != 51
            || djmOA72MinRoll(16) != 42
        )
            ++bad;
        // the disaster column - Bad Harvest 06-15 ordinal 3, Earthquake Minor
        // 45-49 ordinal 7, Plague 88-92 ordinal 25
    if (djmOA72DisasterEvent(1) != 3
            || djmOA72DisasterEvent(3) != 3
            || djmOA72DisasterEvent(18) != 7
            || djmOA72DisasterEvent(36) != 25
            || djmOA72MinRoll(36) != 88
            || djmOA72MaxRoll(18) != 49
        )
            ++bad;
        // the other column - Maiden of Virtue 51-55 ordinal 19, Maneater
        // 56-60 ordinal 21, Marriage 61-68 ordinal 22, VIP Visit 84-92
        // ordinal 30
    if (djmOA72OtherEvent(20) != 19
            || djmOA72OtherEvent(22) != 19
            || djmOA72OtherEvent(23) != 21
            || djmOA72OtherEvent(24) != 22
            || djmOA72OtherEvent(27) != 22
            || djmOA72OtherEvent(35) != 30
            || djmOA72OtherEvent(36) != 30
        )
            ++bad;
        // the duplicate rows - 62-65 and 66 both Recruiting, Flooding,
        // Marriage in the print
    if (djmOA72MinRoll(25) != 62
            || djmOA72MaxRoll(25) != 65
            || djmOA72MinRoll(26) != 66
            || djmOA72MaxRoll(26) != 66
            || djmOA72WarEvent(25) != 26
            || djmOA72WarEvent(26) != 26
            || djmOA72DisasterEvent(26) != 12
            || djmOA72OtherEvent(26) != 22
        )
            ++bad;
        // the No Event thresholds - war 81, disaster 95, other 93; Vengeful
        // Stranger 79-80 ordinal 29 in war and other
    if (djmOA72WarEvent(33) != 23
            || djmOA72WarEvent(32) != 29
            || djmOA72OtherEvent(32) != 29
            || djmOA72MinRoll(33) != 81
            || djmOA72OtherEvent(37) != 23
            || djmOA72MinRoll(37) != 93
            || djmOA72DisasterEvent(39) != 23
        )
            ++bad;
        // the contiguity - each row beginning where the last ended, the 100
        // the close
    if (djmOA72MinRoll(1) != djmOA72MaxRoll(0) + 1
            || djmOA72MinRoll(2) != djmOA72MaxRoll(1) + 1
            || djmOA72MinRoll(8) != djmOA72MaxRoll(7) + 1
            || djmOA72MinRoll(18) != djmOA72MaxRoll(17) + 1
            || djmOA72MinRoll(30) != djmOA72MaxRoll(29) + 1
            || djmOA72MinRoll(39) != djmOA72MaxRoll(38) + 1
            || djmOA72MaxRoll(39) != 100
        )
            ++bad;
        printf("R699 OA monthly events audit: bad %d\n", bad);
        if (bad) return 1;
    }
