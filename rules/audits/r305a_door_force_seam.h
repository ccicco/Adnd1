    // ---- R305a: the door force seam audit ----
    // The DMG FIRST DUNGEON ADVENTURE doors
    // prose (rules/dmg/doorforce.h, the grenade.h
    // pattern) - the forcing pins and their
    // folds - verified by audit_eval.
    {
        Doorforce doorforce;
        int bad = 0;
        // the typical band: a roll of 1 or 2
        // indicates success
        if (doorforce.doorForceTypicalMin() != 1 ||
            doorforce.doorForceTypicalMax() != 2) ++bad;
        // very heavy doors halve the chances
        if (doorforce.doorVeryHeavyHalvesChances() != 1)
            ++bad;
        // locked doors need simultaneous 1s
        // (JUDGMENT: the print reads two or even
        // three - the band pins at two)
        if (doorforce.doorLockedSimultaneousOnes() != 2)
            ++bad;
        // the width caps: three shoulders at the
        // standard door, one at a narrow
        if (doorforce.doorWidthStandardAttempts() != 3 ||
            doorforce.doorNarrowWidthAttempts() != 1)
            ++bad;
        // the wood-break lane: a full turn and
        // at least 3 noise checks
        if (doorforce.doorWoodBreakFullTurn() != 1 ||
            doorforce.doorWoodBreakMonsterChecks() != 3)
            ++bad;
        // metal doors need the knock spell
        if (doorforce.doorMetalNeedsKnock() != 1) ++bad;
        // folds: the typical band spans the
        // printed 1-2; the width band orders;
        // the simultaneous band rides inside
        // the printed two-to-three
        if (doorforce.doorForceTypicalMax() -
                doorforce.doorForceTypicalMin() + 1 != 2)
            ++bad;
        if (doorforce.doorNarrowWidthAttempts() >
                doorforce.doorWidthStandardAttempts()) ++bad;
        if (doorforce.doorLockedSimultaneousOnes() < 2 ||
            doorforce.doorLockedSimultaneousOnes() > 3)
            ++bad;
        printf("R305a door force seam audit: bad %d\n", bad);
        if (bad) return 1;
    }
