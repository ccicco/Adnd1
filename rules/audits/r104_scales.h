    // ---- R104: scales audit ----
    {
        int bad = 0;
        Party p;
        MessageLog log;
        // a short purse refuses, moves no gold, and the
        // refusal is the shop's own words
        p.gold = 49;
        if (spendGold(p, log, 50,
                      "The priest shakes his head - 50 gp."))
            ++bad;
        if (p.gold != 49) ++bad;
        if (log.get(0) !=
            "The priest shakes his head - 50 gp.") ++bad;
        // exact coin spends to zero
        p.gold = 50;
        if (!spendGold(p, log, 50, "The fletcher wants 30 gp."))
            ++bad;
        if (p.gold != 0) ++bad;
        // a fat purse pays and keeps the change
        p.gold = 200;
        if (!spendGold(p, log, 75, "The armorer wants 75 gp."))
            ++bad;
        if (p.gold != 125) ++bad;
        // and refuses at 125 what it afforded at 200
        if (spendGold(p, log, 126, "The scribe wants 200 gp."))
            ++bad;
        if (p.gold != 125) ++bad;
        if (log.get(0) != "The scribe wants 200 gp.") ++bad;
        printf("R104 scales audit: bad %d\n", bad);
        if (bad) return 1;
    }
