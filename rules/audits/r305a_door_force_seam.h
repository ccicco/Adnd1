    // ---- R305a: the door force seam audit ----
    // The DMG FIRST DUNGEON ADVENTURE doors
    // prose (rules/doorforce.h, the grenade.h
    // pattern) - the forcing pins and their
    // folds - verified by audit_eval.
    {
        int bad = 0;
        // the typical band: a roll of 1 or 2
        // indicates success
        if (rules::doorForceTypicalMin() != 1 ||
            rules::doorForceTypicalMax() != 2) ++bad;
        // very heavy doors halve the chances
        if (rules::doorVeryHeavyHalvesChances() != 1)
            ++bad;
        // locked doors need simultaneous 1s
        // (JUDGMENT: the print reads two or even
        // three - the band pins at two)
        if (rules::doorLockedSimultaneousOnes() != 2)
            ++bad;
        // the width caps: three shoulders at the
        // standard door, one at a narrow
        if (rules::doorWidthStandardAttempts() != 3 ||
            rules::doorNarrowWidthAttempts() != 1)
            ++bad;
        // the wood-break lane: a full turn and
        // at least 3 noise checks
        if (rules::doorWoodBreakFullTurn() != 1 ||
            rules::doorWoodBreakMonsterChecks() != 3)
            ++bad;
        // metal doors need the knock spell
        if (rules::doorMetalNeedsKnock() != 1) ++bad;
        // folds: the typical band spans the
        // printed 1-2; the width band orders;
        // the simultaneous band rides inside
        // the printed two-to-three
        if (rules::doorForceTypicalMax() -
                rules::doorForceTypicalMin() + 1 != 2)
            ++bad;
        if (rules::doorNarrowWidthAttempts() >
                rules::doorWidthStandardAttempts()) ++bad;
        if (rules::doorLockedSimultaneousOnes() < 2 ||
            rules::doorLockedSimultaneousOnes() > 3)
            ++bad;
        printf("R305a door force seam audit: bad %d\n", bad);
        if (bad) return 1;
    }
