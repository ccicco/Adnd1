    // ---- R374: the UA treasure
    // dial pin audit ----
    // THE DECISION round: the UA
    // random determination tables
    // III.A through III.H REPLACE
    // the DMG tables; the engine
    // carries both as switchable
    // alternatives behind a dial
    // (DMG / UA / MERGED) and
    // playtesting picks. The DMG
    // mode stays the default - the
    // seventy landed audits remain
    // authoritative until the UA
    // pin rounds land. The R219
    // seam cross-checks the map
    // table bands; the R220 seam
    // the hoard bands; no item
    // flips this round - the
    // decision record lands; the
    // census 300 -> 301.
    {
        using namespace rules;
        int bad = 0;
        // ---- the dial pins ----
            if (uatdModeDmg() != 0) ++bad;
            if (uatdModeUa() != 1) ++bad;
            if (uatdModeMerged() != 2) ++bad;
            if (uatdModeCount() != 3) ++bad;
            if (uatdDefaultMode()
                    != uatdModeDmg()) ++bad;
            if (!uatdRunBothDecided()) ++bad;
            if (!uatdUaTablesReplaceDmg())
                ++bad;
            if (!uatdDmgAuditsAuthoritative())
                ++bad;
            if (uatdDmgAuditRoundFirst()
                    != 219) ++bad;
            if (uatdDmgAuditRoundLast()
                    != 287) ++bad;
            if (!uatdMonsterFileTracksSource())
                ++bad;
            if (!uatdPlaytestingPicks()) ++bad;
            // R402: the pin rounds
            // landed - the pending
            // pin flips
            if (uatdUaPinRoundsPending())
                ++bad;
            if (uatdTableSetCount() != 2) ++bad;
            if (!uatdMergedCarriesBoth()) ++bad;
        // ---- the R219 seam ----
            // the map-or-magic roll:
            // 01-10 the Map Table,
            // 11-00 the Magic Items
            // Table
            if (mapOrMagicIsMap(1) != 1) ++bad;
            if (mapOrMagicIsMap(10) != 1) ++bad;
            if (mapOrMagicIsMap(11) != 0) ++bad;
            if (mapOrMagicIsMap(100) != 0)
                ++bad;
        // ---- the R220 seam ----
            // the combined hoard: ten
            // bands, 01-20 b0 through
            // 97-00 b9; the hoard must
            // be hidden, trapped and
            // guarded, in distant
            // places
            if (hoardBandCount() != 10) ++bad;
            if (hoardBandOfRoll(1) != 0) ++bad;
            if (hoardBandOfRoll(20) != 0) ++bad;
            if (hoardBandOfRoll(21) != 1) ++bad;
            if (hoardBandOfRoll(55) != 2) ++bad;
            if (hoardBandOfRoll(100) != 9)
                ++bad;
            if (!hoardMustBeHiddenTrappedGuarded())
                ++bad;
            if (!hoardDistantPlaces()) ++bad;
        printf("R374 UA treasure dial pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
