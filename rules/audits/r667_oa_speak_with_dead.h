    // ---- R667 OA speak with dead audit ----
    // OA round fifty-four (capture p. 132): Table 64 - the speak with dead
    // ladder by shukenja level, the maximum dead time, questioning time and
    // question counts per band, cross-checked between the passes
    {
        using namespace rules;
        int bad = 0;
    if (dibT64BandCount() != 6
            || dibT64QuestionsBase() != 2
            || dibT64MaxQuestions() != 7
            || dibT64DeadWeekDays() != 7
            || dibT64DeadMonthDays() != 30
            || dibT64DeadYearDays() != 365
            || dibT64LongestDeadDays() != 365000
            || dibT64ShortestQuestionSegments() != 10
            || dibT64LongestQuestionSegments() != 360
        )
            ++bad;
        // the speak with dead grid: the maximum dead time, questioning time
        // and question counts by level band
        int CT64Data[6][3] = {
            {7,10,2},
            {30,30,3},
            {365,60,4},
            {3650,120,5},
            {36500,180,6},
            {365000,360,7},
            };
        for (int b = 0;
             b < dibT64BandCount();
             ++b) {
            int vals[3];
            vals[0] = dibT64DeadDays(b);
            vals[1] = dibT64QuestionSegments(b);
            vals[2] = dibT64Questions(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT64Data[b][c])
                    ++bad;
            }
        }
        // the dibT64LevelBand band-for boundaries
    if (dibT64LevelBand(5) != 0
            || dibT64LevelBand(6) != 0
            || dibT64LevelBand(8) != 1
            || dibT64LevelBand(7) != 1
            || dibT64LevelBand(12) != 2
            || dibT64LevelBand(9) != 2
            || dibT64LevelBand(15) != 3
            || dibT64LevelBand(13) != 3
            || dibT64LevelBand(20) != 4
            || dibT64LevelBand(16) != 4
            || dibT64LevelBand(21) != 5
        )
            ++bad;
        // the count pins - six bands, the question ladder base two and
        // maximum seven, the week, month and year day conventions, the
        // longest dead time and the shortest and longest questioning times
    if (dibT64BandCount() != 6
            || dibT64QuestionsBase() != 2
            || dibT64MaxQuestions() != 7
            || dibT64DeadWeekDays() != 7
            || dibT64DeadMonthDays() != 30
            || dibT64DeadYearDays() != 365
            || dibT64LongestDeadDays() != 365000
            || dibT64ShortestQuestionSegments() != 10
            || dibT64LongestQuestionSegments() != 360
        )
            ++bad;
        // the chain pins - the shukenja's level mapped to its band: level 1
        // and level 6 the least band 0, 7 and 8 band 1, 9 and 12 band 2, 13
        // and 15 band 3, 16 and 20 band 4, 21 the tail band 5
    if (dibT64LevelBand(1) != 0
            || dibT64LevelBand(6) != 0
            || dibT64LevelBand(7) != 1
            || dibT64LevelBand(8) != 1
            || dibT64LevelBand(9) != 2
            || dibT64LevelBand(12) != 2
            || dibT64LevelBand(13) != 3
            || dibT64LevelBand(15) != 3
            || dibT64LevelBand(16) != 4
            || dibT64LevelBand(20) != 4
            || dibT64LevelBand(21) != 5
        )
            ++bad;
        // the dead time pins - the week, month and year bands, then the
        // decade climb: 10 years, 100 years and the 1000-year greatest band
    if (dibT64DeadDays(0) != 7
            || dibT64DeadDays(1) != 30
            || dibT64DeadDays(2) != 365
            || dibT64DeadDays(3) != 3650
            || dibT64DeadDays(4) != 36500
            || dibT64DeadDays(5) != 365000
        )
            ++bad;
        // the decade ladder pins - each band from the one-year band climbs
        // exactly a decade
    if (dibT64DeadDays(3) != 10 * dibT64DeadDays(2)
            || dibT64DeadDays(4) != 10 * dibT64DeadDays(3)
            || dibT64DeadDays(5) != 10 * dibT64DeadDays(4)
        )
            ++bad;
        // the questioning time pins - one round, three rounds, one turn, two
        // turns, three turns and the six-turn greatest band (the compressed
        // reads 2 turn on the two-turn row - the print settles 2 turns)
    if (dibT64QuestionSegments(0) != 10
            || dibT64QuestionSegments(1) != 30
            || dibT64QuestionSegments(2) != 60
            || dibT64QuestionSegments(3) != 120
            || dibT64QuestionSegments(4) != 180
            || dibT64QuestionSegments(5) != 360
        )
            ++bad;
        // the question count pins - the ladder climbing one per band from two
        // to seven
    if (dibT64Questions(0) != 2
            || dibT64Questions(1) != 3
            || dibT64Questions(2) != 4
            || dibT64Questions(3) != 5
            || dibT64Questions(4) != 6
            || dibT64Questions(5) != 7
        )
            ++bad;
        // the question ladder identity pins - each band's question count is
        // its band ordinal plus the base two, checked at both ladder ends and
        // the middle
    if (dibT64Questions(0) != 0 + dibT64QuestionsBase()
            || dibT64Questions(3) != 3 + dibT64QuestionsBase()
            || dibT64Questions(5) != 5 + dibT64QuestionsBase()
        )
            ++bad;
        printf("R667 OA speak with dead audit: bad %d\n", bad);
        if (bad) return 1;
    }
