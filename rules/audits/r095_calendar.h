    // ---- R95: calendar audit ----
    {
        int bad = 0;
        // the conversion: 144 turns to the day
        if (turnsPerDay() != 144) ++bad;
        if (dungeonDays(0)    != 0) ++bad;
        if (dungeonDays(143)  != 0) ++bad;   // not yet a day
        if (dungeonDays(144)  != 1) ++bad;
        if (dungeonDays(156)  != 1) ++bad;   // a deep delve's
        if (dungeonDays(288)  != 2) ++bad;   // remainder is
        if (dungeonDays(1000) != 6) ++bad;   // honest floors
        // the ledger bounds still hold with days: a full
        // delve day (36 descent + 60 march + 48 camp = 144)
        // is exactly one career day
        if (descentTurns() + 60 + restTurns(false)
            != turnsPerDay()) ++bad;
        // the calendar starts clean and only grows
        {
            Party p;
            if (p.careerDays != 0) ++bad;
            p.careerDays += dungeonDays(144);
            p.careerDays += 1;               // an overland day
            p.careerDays += 1;               // a sea day
            if (p.careerDays != 3) ++bad;
        }
        printf("R95 calendar audit: bad %d\n", bad);
        if (bad) return 1;
    }
