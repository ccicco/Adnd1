    // ---- R704 OA climate groupings audit ----
    // OA round ninety-one (capture pp. 252-253): the Climate Groupings with
    // Creatures from Previous Books - the seven climate groupings, the game
    // creature lists, the doctrine, and the earlier-books cross-reference,
    // single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (djrOA75GroupCount() != 7
            || djrOA75CreatureCount() != 61
            || djrOA75SubArcticCount() != 18
            || djrOA75TemperateCount() != 20
            || djrOA75SteppelandsCount() != 13
            || djrOA75SubTropicalCount() != 18
            || djrOA75TropicalCount() != 18
            || djrOA75ColdCount() != 6
            || djrOA75WarmCount() != 4
            || djrOA75CrossCount() != 124
            || djrOA75CrossMMICount() != 59
            || djrOA75CrossFFCount() != 18
            || djrOA75CrossMMIICount() != 46
            || djrOA75CrossLLCount() != 1
            || !djrOA75UniqueCreaturesExist()
            || !djrOA75HeldAtBayByGeography()
            || !djrOA75GroupedByClimate()
            || !djrOA75GameCreaturesNotOnTables()
            || !djrOA75CrossListAidsDM()
            || !djrOA75CrossNotExclusive()
            || !djrOA75CelestialBureaucracy()
            || !djrOA75OfficialsReplaceable()
        )
            ++bad;
        // the seven groupings and the doctrine - the group count, the
        // creature count, the unique creatures, the held-at-bay, the
        // grouped-by-climate, the game creatures off the tables
    if (djrOA75GroupCount() != 7
            || djrOA75CreatureCount() != 61
            || djrOA75UniqueCreaturesExist() != 1
            || djrOA75HeldAtBayByGeography() != 1
            || djrOA75GroupedByClimate() != 1
            || djrOA75GameCreaturesNotOnTables() != 1
        )
            ++bad;
        // the grouping sizes - the Sub-Arctic Forests 18, the Temperate
        // Plain/Forest 20, the Steppelands 13, the Sub-Tropical Forest 18
    if (djrOA75SubArcticCount() != 18
            || djrOA75TemperateCount() != 20
            || djrOA75SteppelandsCount() != 13
            || djrOA75SubTropicalCount() != 18
            || djrOA75TropicalCount() != 18
            || djrOA75ColdCount() != 6
            || djrOA75WarmCount() != 4
            || djrOA75CrossMMICount() != 59
            || djrOA75CrossFFCount() != 18
            || djrOA75CrossMMIICount() != 46
            || djrOA75CrossLLCount() != 1
            || djrOA75GroupCount() != 7
        )
            ++bad;
        // the cross-reference - the count, the four sources, the aids the DM,
        // the not-exclusive, the celestial bureaucracy, the replaceable
        // officials
    if (djrOA75CrossCount() != 124
            || djrOA75CrossMMICount() != 59
            || djrOA75CrossFFCount() != 18
            || djrOA75CrossMMIICount() != 46
            || djrOA75CrossLLCount() != 1
            || djrOA75CrossListAidsDM() != 1
            || djrOA75CrossNotExclusive() != 1
            || djrOA75CelestialBureaucracy() != 1
            || djrOA75OfficialsReplaceable() != 1
        )
            ++bad;
        printf("R704 OA climate groupings audit: bad %d\n", bad);
        if (bad) return 1;
    }
