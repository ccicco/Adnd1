    // ---- R121: crew officers audit ----
    {
        int bad = 0;
        // the book (DMG p.35): for every 20 crewmen,
        // 1 lieutenant and 2 mates
        if (crewLieutenantsFor(20) != 1) ++bad;
        if (crewMatesFor(20) != 2)       ++bad;
        if (crewLieutenantsFor(40) != 2) ++bad;
        if (crewMatesFor(40) != 4)       ++bad;
        // a short company still ships one lieutenant
        if (crewLieutenantsFor(19) != 1) ++bad;
        if (crewMatesFor(19) != 2)       ++bad;
        // no crew, no officers
        if (crewLieutenantsFor(0) != 0)  ++bad;
        if (crewMatesFor(0) != 0)        ++bad;
        if (crewOfficerWages(0) != 0)   ++bad;
        // wages: captain 100 + lieutenant 100 + mates 60
        // (100 gp/level, L1 hires - documented; mates are
        // serjeants at 30 gp, p.34)
        if (crewOfficerWages(20) != 260) ++bad;
        if (crewOfficerWages(40) != 420) ++bad;
        // shares (DMG p.35): captain 25, each lieutenant 5,
        // each mate 1, crew 5 - and the PC keeps the rest
        if (crewCaptainSharePct()    != 25) ++bad;
        if (crewLieutenantSharePct() !=  5) ++bad;
        if (crewMateSharePct()       !=  1) ++bad;
        if (crewCrewSharePct()       !=  5) ++bad;
        if (crewOfficerSharePct(20)  != 32) ++bad;
        if (crewTotalSharePct(20)    != 37) ++bad;
        if (crewOfficerSharePct(40)  != 39) ++bad;
        if (crewTotalSharePct(40)    != 44) ++bad;
        if (100 - crewTotalSharePct(20) != 63) ++bad;
        printf("R121 crew officers audit: bad %d\n", bad);
        if (bad) return 1;
    }
