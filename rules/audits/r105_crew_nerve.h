    // ---- R105: crew nerve audit ----
    {
        int bad = 0;
        // the drift weights and the floor
        if (crewDriftPaid()   !=  2)   ++bad;
        if (crewDriftUnpaid() != -10)  ++bad;
        if (crewDriftShare()  !=  3)   ++bad;
        if (crewHireMorale()  !=  60)  ++bad;
        if (crewDesertBelow() !=  25)  ++bad;
        // the clamp bounds
        if (clampCrewMorale(-1) != 0)     ++bad;
        if (clampCrewMorale(101) != 100)  ++bad;
        if (clampCrewMorale(60)  != 60)   ++bad;
        // the desertion arithmetic: three unpaid wages
        // from a fresh signing, then the floor
        {
            Party p;
            p.crewHired = true;
            p.crewMorale = crewHireMorale();
            for (int i = 0; i < 3; ++i)
                p.crewMorale = clampCrewMorale(
                    p.crewMorale + crewDriftUnpaid());
            // 60 - 30 = 30, still aboard
            if (p.crewMorale != 30) ++bad;
            p.crewMorale = clampCrewMorale(
                p.crewMorale + crewDriftUnpaid());
            // 20, below the 25 floor - desertion
            if (p.crewMorale >= crewDesertBelow()) ++bad;
        }
        // the recovery path: two paid wages + a share
        // from 30
        {
            Party p;
            p.crewMorale = 30;
            p.crewMorale = clampCrewMorale(
                p.crewMorale + crewDriftPaid());
            p.crewMorale = clampCrewMorale(
                p.crewMorale + crewDriftPaid());
            p.crewMorale = clampCrewMorale(
                p.crewMorale + crewDriftShare());
            if (p.crewMorale != 37) ++bad;
        }
        // the crew line contract: flag then morale, and
        // the older one-int form still parses
        {
            int cw = -1, cm = -1;
            char tg[16];
            if (sscanf("crew 1 60", "%15s %d %d",
                       tg, &cw, &cm) != 3) ++bad;
            if (cw != 1 || cm != 60) ++bad;
            cw = -1;
            if (sscanf("crew 1", "%15s %d", tg, &cw) != 2)
                ++bad;
            if (cw != 1) ++bad;
            cw = -1; cm = -1;
            if (sscanf("crew 0 0", "%15s %d %d",
                       tg, &cw, &cm) != 3) ++bad;
            if (cw != 0 || cm != 0) ++bad;
        }
        printf("R105 crew nerve audit: bad %d\n", bad);
        if (bad) return 1;
    }
