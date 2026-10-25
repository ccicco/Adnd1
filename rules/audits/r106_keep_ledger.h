    // ---- R106: keep ledger audit ----
    {
        int bad = 0;
        // the month clock: 30 career days to the month
        if (keepUpkeepPerMonth() != 200) ++bad;
        if (keepMonthsElapsed(0, 90, 0) != 3)  ++bad;
        if (keepMonthsElapsed(0, 90, 3) != 0)  ++bad;
        if (keepMonthsElapsed(0, 90, 4) != 0)  ++bad;
        if (keepMonthsElapsed(0, 29, 0) != 0)  ++bad;
        if (keepMonthsElapsed(40, 100, 0) != 2) ++bad;
        // an unknown build day bills nothing (the billing
        // site stamps it first)
        if (keepMonthsElapsed(-1, 500, 0) != 0) ++bad;
        // a fresh party owes the keep nothing
        {
            Party p;
            if (p.strongholdBuilt) ++bad;
            if (p.strongholdBuiltDay != -1) ++bad;
            if (p.strongholdMonthsBilled != 0) ++bad;
            if (p.strongholdDebt != 0) ++bad;
        }
        // the garnish arithmetic: rents vs a standing debt
        {
            Party p;
            p.strongholdDebt = 500;
            int g = (p.strongholdDebt < 200)
                        ? p.strongholdDebt : 200;
            p.strongholdDebt -= g;
            if (g != 200 || p.strongholdDebt != 300) ++bad;
            g = (p.strongholdDebt < 200)
                    ? p.strongholdDebt : 200;
            p.strongholdDebt -= g;
            if (g != 200 || p.strongholdDebt != 100) ++bad;
            g = (p.strongholdDebt < 200)
                    ? p.strongholdDebt : 200;
            p.strongholdDebt -= g;
            if (g != 100 || p.strongholdDebt != 0) ++bad;
        }
        // a half-year idle keep bills six months
        {
            Party p;
            p.strongholdBuilt = true;
            p.strongholdBuiltDay = 0;
            p.careerDays = 185;
            int months = keepMonthsElapsed(
                p.strongholdBuiltDay, p.careerDays,
                p.strongholdMonthsBilled);
            if (months != 6) ++bad;
            if (months * keepUpkeepPerMonth() != 1200)
                ++bad;
        }
        // the stronghold line contract: the legacy two-int
        // form and the five-int form both parse
        {
            char tg[16];
            int b = -1, ow = -1, bd = -9, mb = -9, dt = -9;
            if (sscanf("stronghold 1 0 40 2 150",
                       "%15s %d %d %d %d %d",
                       tg, &b, &ow, &bd, &mb, &dt) != 6)
                ++bad;
            if (b != 1 || ow != 0 || bd != 40 ||
                mb != 2 || dt != 150) ++bad;
            b = -1; ow = -1;
            if (sscanf("stronghold 1 0", "%15s %d %d",
                       tg, &b, &ow) != 3) ++bad;
            if (b != 1 || ow != 0) ++bad;
        }
        printf("R106 keep ledger audit: bad %d\n", bad);
        if (bad) return 1;
    }
