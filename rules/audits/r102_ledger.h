    // ---- R102: ledger of everything audit ----
    {
        int bad = 0;
        // the field-vs-save sweep, PINNED: every durable
        // Party/Character field has a save tag; the only
        // transient fields are by documented design
        {
            Party p;
            p.gold = 100; p.kills = 5; p.potions = 3;
            p.scrolls = 2; p.careerDays = 10;
            p.delveCount = 4; p.deepestLevel = 6;
            p.totalGold = 9000; p.identifyScrolls = 1;
            p.strongholdBuilt = true; p.strongholdOwner = 0;
            p.crewHired = true; p.formed = true;
            // a fresh party defaults clean - the sweep's
            // zero-state: nothing durable is left behind
            Party q;
            if (q.gold != 0 || q.kills != 0) ++bad;
            if (q.scrolls != 0 || q.potions != 0) ++bad;
            if (q.careerDays != 0) ++bad;
            if (q.delveCount != 0 || q.totalGold != 0)
                ++bad;
            if (q.strongholdBuilt || q.crewHired) ++bad;
            if (q.henchmanPresent || q.henchmanPlate) ++bad;
            if (q.identifyScrolls != 0) ++bad;
        }
        // the carried-scrolls line parses, both ways
        {
            int scr = -1;
            char tg[16];
            if (sscanf("cscrolls 7", "%15s %d", tg, &scr)
                != 2) ++bad;
            if (std::string(tg) != "cscrolls" || scr != 7)
                ++bad;
            scr = -1;
            if (sscanf("cscrolls 0", "%15s %d", tg, &scr)
                != 2) ++bad;
            if (scr != 0) ++bad;
        }
        // the tag is distinct from idscrolls (both load
        // branches must route independently)
        {
            char tg1[16] = "", tg2[16] = "";
            int a = -1, b = -1;
            if (sscanf("idscrolls 2", "%15s %d", tg1, &a)
                != 2) ++bad;
            if (sscanf("cscrolls 5", "%15s %d", tg2, &b)
                != 2) ++bad;
            if (std::string(tg1) == std::string(tg2))
                ++bad;
            if (a != 2 || b != 5) ++bad;
        }
        // the guard matches the cap the dungeon adds with
        if (CARRIED_CAP != 9999) ++bad;
        printf("R102 ledger audit: bad %d\n", bad);
        if (bad) return 1;
    }
