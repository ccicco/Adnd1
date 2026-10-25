    // ---- R100: hire's years audit ----
    {
        int bad = 0;
        // the hire rides the same clock, from an unknown
        // youth default
        {
            Party p;
            if (p.henchmanStartAge != 0) ++bad;
            p.henchmanStartAge = 17;
            if (hireAgeYears(p) != 17) ++bad;
            p.careerDays = 364;
            if (hireAgeYears(p) != 17) ++bad;
            p.careerDays = 365;
            if (hireAgeYears(p) != 18) ++bad;
            p.careerDays = 3650;
            if (hireAgeYears(p) != 27) ++bad;
        }
        // the save/load contract, PINNED: a present flag,
        // four ints, the NAME, then six trailing ints (the
        // pre-R100 save put the name last and never loaded)
        {
            char line[128];
            snprintf(line, sizeof line,
                     "henchman 1 %d %d %d %d %s %d %d %d %d %d %d",
                     8, 8, 1, 50, "Bors", 2000, 300, 500,
                     1, 1, 17);
            char tg[16] = "";
            int present = 0, hp = 0, mx = 0, lv = 0, loy = 0;
            int pos = 0;
            char nm[17] = "";
            if (sscanf(line, "%15s %d %d %d %d %d %16s%n",
                       tg, &present, &hp, &mx, &lv, &loy, nm,
                       &pos) != 7) ++bad;
            if (present != 1) ++bad;
            if (hp != 8 || mx != 8 || lv != 1 || loy != 50)
                ++bad;
            if (std::string(nm) != "Bors") ++bad;
            int hxp = 0, hpu = 0, dgv = 0, wpl = 0, spl = 0,
                hge = 0;
            int got = sscanf(line + pos, "%d %d %d %d %d %d",
                             &hxp, &hpu, &dgv, &wpl, &spl,
                             &hge);
            if (got != 6) ++bad;
            if (hxp != 2000 || hpu != 300 || dgv != 500)
                ++bad;
            if (wpl != 1 || spl != 1) ++bad;
            if (hge != 17) ++bad;
        }
        printf("R100 hire's years audit: bad %d\n", bad);
        if (bad) return 1;
    }
