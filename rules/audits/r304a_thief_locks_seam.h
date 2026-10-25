    // ---- R304a: the thief locks seam audit ----
    // The DMG THIEF ABILITIES time pins and
    // the doors prose (rules/locktime.h, the
    // grenade.h pattern) plus the open locks
    // percentile boundary walk against the
    // R298 tables - verified by audit_eval.
    // The race reads a plain int (0 human,
    // 5 halfling, 1 dwarf, 2 elf).
    {
        int bad = 0;
        // the printed time band: picking takes
        // 1-10 rounds (most locks 1-4); the
        // traps roll rides the locks time
        if (rules::thfLocksPickRoundsMin() != 1 ||
            rules::thfLocksPickRoundsMax() != 10 ||
            rules::thfLocksPickRoundsTypicalMax() != 4 ||
            rules::thfTrapsTimeRidesLocks() != 1) ++bad;
        // the doors prose pins
        if (rules::doorWoodAlwaysMetalBound() != 1 ||
            rules::doorMetalUsuallyLocked() != 1) ++bad;
        // the per-delve count judgment
        if (rules::doorLockedPerDelveCount() != 1) ++bad;
        // the time draw band folds the
        // helpers: min + below(max - min + 1)
        // covers the printed 1-10
        if (rules::thfLocksPickRoundsMax() -
                rules::thfLocksPickRoundsMin() + 1 != 10)
            ++bad;
        // open locks level 1 human dex 9
        // prints 15 percent (150 tenths)
        if (!rules::thfAttemptSucceeds(149,
                rules::THF_OPEN_LOCKS, 1, 0, 9) ||
            rules::thfAttemptSucceeds(150,
                rules::THF_OPEN_LOCKS, 1, 0, 9)) ++bad;
        // open locks level 10 halfling dex 13
        // prints 72 percent (720 tenths)
        if (!rules::thfAttemptSucceeds(719,
                rules::THF_OPEN_LOCKS, 10, 5, 13) ||
            rules::thfAttemptSucceeds(720,
                rules::THF_OPEN_LOCKS, 10, 5, 13)) ++bad;
        // open locks level 12 dwarf dex 18
        // prints 102 percent (1020 - every
        // draw of the band succeeds)
        if (!rules::thfAttemptSucceeds(999,
                rules::THF_OPEN_LOCKS, 12, 1, 18)) ++bad;
        // open locks level 1 elf dex 18 prints
        // 35 percent (350 tenths)
        if (!rules::thfAttemptSucceeds(349,
                rules::THF_OPEN_LOCKS, 1, 2, 18) ||
            rules::thfAttemptSucceeds(350,
                rules::THF_OPEN_LOCKS, 1, 2, 18)) ++bad;
        printf("R304a thief locks seam audit: bad %d\n", bad);
        if (bad) return 1;
    }
