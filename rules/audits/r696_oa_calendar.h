    // ---- R696 OA calendar audit ----
    // OA round eighty-three (capture p. 236): the Calendar - the twelve
    // months of the Shou Lung emperor's calendar with their days and the
    // festivals, feasts and holy days counted, single-pass pins per the
    // Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (djjOACalendarRowCount() != 12
            || djjOAYearDays() != 356
            || !djjOACalendarEmperorOrigin()
            || !djjOACalendarCommonUse()
            || !djjOANewYearFebMar()
            || !djjOAFestivalsLong()
            || !djjOAFeastsBanquets()
            || !djjOAHolyDaysOptional()
            || !djjOAObservancesSimple()
        )
            ++bad;
        // the calendar grid - the twelve months across two columns
        int COACalendarData[12][2] = {
            {30,8},
            {30,2},
            {30,3},
            {30,2},
            {29,3},
            {30,0},
            {29,2},
            {30,4},
            {30,4},
            {29,1},
            {30,0},
            {29,1},
            };
        for (int b = 0;
             b < djjOACalendarRowCount();
             ++b) {
            int vals[2];
            vals[0] = djjOAMonthDays(b);
            vals[1] = djjOAMonthFestivals(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != COACalendarData[b][c])
                    ++bad;
            }
        }
        // the 30-day months - Tsou, Ju, Yu, Kao, Chu, Chuang, Hsuan, Ku
    if (djjOAMonthDays(0) != 30
            || djjOAMonthDays(1) != 30
            || djjOAMonthDays(3) != 30
            || djjOAMonthDays(5) != 30
            || djjOAMonthDays(7) != 30
            || djjOAMonthDays(8) != 30
            || djjOAMonthDays(10) != 30
        )
            ++bad;
        // the 29-day months - Kao II, Hsiang, Yang, Tu
    if (djjOAMonthDays(4) != 29
            || djjOAMonthDays(6) != 29
            || djjOAMonthDays(9) != 29
            || djjOAMonthDays(11) != 29
        )
            ++bad;
        // the festival counts - Tsou the eight, Chuang and Hsuan the four
    if (djjOAMonthFestivals(0) != 8
            || djjOAMonthFestivals(7) != 4
            || djjOAMonthFestivals(8) != 4
        )
            ++bad;
        // the bare months - Chu and Ku with none printed, Tu the single
        // Kings' Festival
    if (djjOAMonthFestivals(5) != 0
            || djjOAMonthFestivals(10) != 0
            || djjOAMonthFestivals(11) != 1
        )
            ++bad;
        // the year length - the eight 30s plus the four 29s the 356
    if (djjOAYearDays() != 356
            || djjOAMonthDays(0) + djjOAMonthDays(4) + djjOAMonthDays(9) != 88
        )
            ++bad;
        printf("R696 OA calendar audit: bad %d\n", bad);
        if (bad) return 1;
    }
