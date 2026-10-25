    // ---- R301a: the thief percentile seam audit ----
    // The R298 seam gains its first callers this
    // round; this walk pins the boundary convention
    // (a score equal to or less than the chance
    // succeeds - the strict less-than keeps a
    // whole-percent chance owning its exact
    // thousandth of the band, and the printed 99.1
    // climb walls decimal reads true) and the fold
    // against the R298 tables (the grenade.h
    // pattern - verified by audit_eval). The race
    // is a plain int: the parser reads no
    // underlying-type enums (0 human, 1 dwarf,
    // 1 elf, 4 half-elf, 5 halfling).
    {
        int bad = 0;
        // the printed percentile convention on the
        // 0-999 tenths band
        if (!rules::thfPercentileSucceeds(199, 200) ||
            rules::thfPercentileSucceeds(200, 200) ||
            !rules::thfPercentileSucceeds(990, 991) ||
            rules::thfPercentileSucceeds(991, 991) ||
            rules::thfPercentileSucceeds(0, 0) ||
            !rules::thfPercentileSucceeds(999, 1000)) ++bad;
        // find/remove traps level 1 human dex 9
        // prints 10 percent (100 tenths)
        if (!rules::thfAttemptSucceeds(99,
                rules::THF_TRAPS, 1, 0, 9) ||
            rules::thfAttemptSucceeds(100,
                rules::THF_TRAPS, 1, 0, 9)) ++bad;
        // find/remove traps level 4 dwarf dex 13
        // prints 50 percent (500 tenths)
        if (!rules::thfAttemptSucceeds(499,
                rules::THF_TRAPS, 4, 1, 13) ||
            rules::thfAttemptSucceeds(500,
                rules::THF_TRAPS, 4, 1, 13)) ++bad;
        // pick pockets level 1 halfling dex 13
        // prints 35 percent (350 tenths)
        if (!rules::thfAttemptSucceeds(349,
                rules::THF_PICK_POCKETS, 1, 5, 13) ||
            rules::thfAttemptSucceeds(350,
                rules::THF_PICK_POCKETS, 1, 5, 13)) ++bad;
        // pick pockets level 12 half-elf dex 16
        // prints 110 percent (1100 - every draw of
        // the band succeeds)
        if (!rules::thfAttemptSucceeds(999,
                rules::THF_PICK_POCKETS, 12, 4, 16)) ++bad;
        // climb walls level 11 human dex 18 prints
        // 99.1 percent (991 tenths)
        if (!rules::thfAttemptSucceeds(990,
                rules::THF_CLIMB_WALLS, 11, 0, 18) ||
            rules::thfAttemptSucceeds(991,
                rules::THF_CLIMB_WALLS, 11, 0, 18)) ++bad;
        // hear noise level 1 human dex 18 prints
        // 10 percent (the no-DEX column reads 0)
        if (!rules::thfAttemptSucceeds(99,
                rules::THF_HEAR_NOISE, 1, 0, 18) ||
            rules::thfAttemptSucceeds(100,
                rules::THF_HEAR_NOISE, 1, 0, 18)) ++bad;
        // read languages level 2 elf dex 18 prints
        // the dash (0 - no roll succeeds)
        if (rules::thfAttemptSucceeds(0,
                rules::THF_READ_LANGUAGES, 2, 1, 18)) ++bad;
        printf("R301a thief percentile seam audit: bad %d\n", bad);
        if (bad) return 1;
    }
