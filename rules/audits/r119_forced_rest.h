    // ---- R119: forced rest audit ----
    {
        int bad = 0;
        // the book (DMG p.38): rest at least one turn
        // in six - turns 1-5 may be activity, the
        // sixth is owed
        if (forcedRestDue(0)) ++bad;
        if (forcedRestDue(1)) ++bad;
        if (forcedRestDue(4)) ++bad;
        if (!forcedRestDue(5)) ++bad;
        if (!forcedRestDue(6)) ++bad;
        if (!forcedRestDue(30)) ++bad;
        // combat or any other strenuous activity owes
        // a turn of rest (DMG p.38)
        if (strenuousRestTurns() != 1) ++bad;
        printf("R119 forced rest audit: bad %d\n", bad);
        if (bad) return 1;
    }
