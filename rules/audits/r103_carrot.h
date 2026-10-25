    // ---- R103: carrot audit ----
    {
        int bad = 0;
        // the upkeep ladder: 100/level, +100 for the raise
        if (henchmanUpkeep(1, false) != 100) ++bad;
        if (henchmanUpkeep(1, true)  != 200) ++bad;
        if (henchmanUpkeep(3, false) != 300) ++bad;
        if (henchmanUpkeep(3, true)  != 400) ++bad;
        // the carrot weights
        if (loyaltyGift() != 5)  ++bad;
        if (loyaltyRaise() != 10) ++bad;
        // the gift cannot farm past contentment: the gate
        // is the PRE-gift loyalty, the drift clamps at 125
        if (loyaltyDrift(99, loyaltyGift()) != 104) ++bad;
        if (loyaltyDrift(125, loyaltyGift()) != 125) ++bad;
        // a fresh hire has taken no raise
        {
            Party p;
            if (p.henchmanRaise) ++bad;
            if (henchmanUpkeep(p.henchmanLevel,
                               p.henchmanRaise) != 100) ++bad;
        }
        // the contract, PINNED at eight trailing ints (the
        // eighth is the raise; older saves stop at seven)
        {
            char line[144];
            snprintf(line, sizeof line,
                     "henchman 1 %d %d %d %d %s %d %d %d %d %d %d %d %d",
                     8, 8, 1, 50, "Bors", 2000, 300, 500,
                     1, 1, 17, 1, 1);
            char tg[16];
            int present = 0, hp = 0, mx = 0, lv = 0, loy = 0;
            int pos = 0;
            char nm[17] = "";
            if (sscanf(line, "%15s %d %d %d %d %d %16s%n",
                       tg, &present, &hp, &mx, &lv, &loy, nm,
                       &pos) != 7) ++bad;
            if (std::string(nm) != "Bors") ++bad;
            int hxp = 0, hpu = 0, dgv = 0, wpl = 0, spl = 0,
                hge = 0, hpl = 0, hrr = 0;
            int got = sscanf(line + pos,
                             "%d %d %d %d %d %d %d %d",
                             &hxp, &hpu, &dgv, &wpl, &spl,
                             &hge, &hpl, &hrr);
            if (got != 8) ++bad;
            if (hpl != 1 || hrr != 1) ++bad;
        }
        // raise off parses too
        {
            char line[144];
            snprintf(line, sizeof line,
                     "henchman 1 %d %d %d %d %s %d %d %d %d %d %d %d %d",
                     8, 8, 1, 50, "Bors", 2000, 300, 500,
                     1, 1, 17, 0, 0);
            int pos = 0;
            char tg[16];
            int present, hp, mx, lv, loy;
            char nm[17] = "";
            if (sscanf(line, "%15s %d %d %d %d %d %16s%n",
                       tg, &present, &hp, &mx, &lv, &loy, nm,
                       &pos) != 7) ++bad;
            int hxp, hpu, dgv, wpl, spl, hge, hpl = 1, hrr = 1;
            hxp = hpu = dgv = wpl = spl = hge = 0;
            if (sscanf(line + pos, "%d %d %d %d %d %d %d %d",
                       &hxp, &hpu, &dgv, &wpl, &spl,
                       &hge, &hpl, &hrr) != 8) ++bad;
            if (hpl != 0 || hrr != 0) ++bad;
        }
        printf("R103 carrot audit: bad %d\n", bad);
        if (bad) return 1;
    }
