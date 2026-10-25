    // ---- R101: plate kit audit ----
    {
        int bad = 0;
        // the extended contract, PINNED: seven trailing
        // ints now - the seventh is the plate kit
        {
            char line[128];
            snprintf(line, sizeof line,
                     "henchman 1 %d %d %d %d %s %d %d %d %d %d %d %d",
                     8, 8, 1, 50, "Bors", 2000, 300, 500,
                     1, 1, 17, 1);
            char tg[16] = "";
            int present = 0, hp = 0, mx = 0, lv = 0, loy = 0;
            int pos = 0;
            char nm[17] = "";
            if (sscanf(line, "%15s %d %d %d %d %d %16s%n",
                       tg, &present, &hp, &mx, &lv, &loy, nm,
                       &pos) != 7) ++bad;
            if (std::string(nm) != "Bors") ++bad;
            int hxp = 0, hpu = 0, dgv = 0, wpl = 0, spl = 0,
                hge = 0, hpl = 0;
            int got = sscanf(line + pos, "%d %d %d %d %d %d %d",
                             &hxp, &hpu, &dgv, &wpl, &spl,
                             &hge, &hpl);
            if (got != 7) ++bad;
            if (hpl != 1) ++bad;
        }
        // the plate off - the trailing 0 parses too
        {
            char line[128];
            snprintf(line, sizeof line,
                     "henchman 1 %d %d %d %d %s %d %d %d %d %d %d %d",
                     8, 8, 1, 50, "Bors", 2000, 300, 500,
                     1, 1, 17, 0);
            char tg[16];
            int present = 0, hp = 0, mx = 0, lv = 0, loy = 0;
            int pos = 0;
            char nm[17] = "";
            if (sscanf(line, "%15s %d %d %d %d %d %16s%n",
                       tg, &present, &hp, &mx, &lv, &loy, nm,
                       &pos) != 7) ++bad;
            int hxp = 0, hpu = 0, dgv = 0, wpl = 0, spl = 0,
                hge = 0, hpl = 1;
            if (sscanf(line + pos, "%d %d %d %d %d %d %d",
                       &hxp, &hpu, &dgv, &wpl, &spl,
                       &hge, &hpl) != 7) ++bad;
            if (hpl != 0) ++bad;
        }
        // the crew line parses both ways
        {
            int cw = -1;
            char tg[16];
            if (sscanf("crew 1", "%15s %d", tg, &cw) != 2)
                ++bad;
            if (cw != 1) ++bad;
            cw = -1;
            if (sscanf("crew 0", "%15s %d", tg, &cw) != 2)
                ++bad;
            if (cw != 0) ++bad;
        }
        // the plate buys plate: the R46 ladder top
        {
            Party p;
            if (p.henchmanPlate) ++bad;
            if (p.party_plate_kit() != items::ARMOR_CHAIN_MAIL)
                ++bad;
            p.henchmanPlate = true;
            if (p.party_plate_kit() != items::ARMOR_PLATE)
                ++bad;
        }
        // a fresh crew is not hired (the save default)
        {
            Party p;
            if (p.crewHired) ++bad;
        }
        printf("R101 plate kit audit: bad %d\n", bad);
        if (bad) return 1;
    }
