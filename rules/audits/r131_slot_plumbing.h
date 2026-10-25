    // ---- R131: slot plumbing audit ----
    // The R130 tables made levels 7-9 real; this pins the
    // per-day plumbing that carries them (the named R130
    // debt): both arrays nine deep and zero-defaulted,
    // and toActor carries the 7th-9th columns to the
    // encounter party (the fill/copy loops are app-side -
    // pinned by the R130 table values they draw from).
    {
        int bad = 0;
        Character c;
        // the Character pool is nine deep and zeroed
        if (sizeof(c.slotsByLevel) != 9 * sizeof(int)) ++bad;
        for (int lv = 0; lv < 9; ++lv)
            if (c.slotsByLevel[lv] != 0) ++bad;
        // the Actor pool likewise
        ai::Actor a0;
        if (sizeof(a0.slotsByLevel) != 9 * sizeof(int)) ++bad;
        for (int lv = 0; lv < 9; ++lv)
            if (a0.slotsByLevel[lv] != 0) ++bad;
        // toActor carries the high columns (index 6-8 =
        // spell levels 7-9)
        c.classIndex = 1;   // MU
        c.level = 18;
        c.slotsByLevel[6] = 1;   // a 7th-circle slot
        c.slotsByLevel[7] = 2;   // 8th
        c.slotsByLevel[8] = 1;   // 9th (the Wish circle)
        ai::Actor a = c.toActor();
        if (a.slotsByLevel[6] != 1) ++bad;
        if (a.slotsByLevel[7] != 2) ++bad;
        if (a.slotsByLevel[8] != 1) ++bad;
        printf("R131 slot plumbing audit: bad %d\n", bad);
        if (bad) return 1;
    }
