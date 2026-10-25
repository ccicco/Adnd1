    // ---- R289: the III.E Special artifacts
    // explanation prose part 10 ----
    // The Orb of Dragonkind, part2 lines
    // 1518-1556 - the intro and the 1st
    // through the 5th of its 8 globes, the
    // first half of the 19th of the 29
    // descriptions. One break absorbed: the
    // extra blank pair at 1555-1556.
    {
        int bad = 0;
        // the Orb intro scalars
        if (rules::sapOrbGoodDeitiesOrigin() != 1 ||
            rules::sapOrbDemonsCorrupted() != 1 ||
            rules::sapOrbGlobeCount() != 8 ||
            rules::sapOrbOnePerAge() != 1 ||
            rules::sapOrbSmallestInches() != 3 ||
            rules::sapOrbLargestInches() != 10 ||
            rules::sapOrbBasReliefCovered() != 1 ||
            rules::sapOrbDragonEssence() != 1) ++bad;
        // the Hatchling scalars and powers
        if (rules::sapOrbHatchlingIntelligence() != 9 ||
            rules::sapOrbHatchlingEgo() != 9 ||
            rules::sapOrbHatchlingPowerTotal() != 3) ++bad;
        static const int kO1[6] = {
            3, 0, 0, 0, 0, 0,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapOrbHatchlingPowerCount(i) != kO1[i]) ++bad;
        if (rules::sapOrbHatchlingPowerCount(0) +
            rules::sapOrbHatchlingPowerCount(1) +
            rules::sapOrbHatchlingPowerCount(2) +
            rules::sapOrbHatchlingPowerCount(3) +
            rules::sapOrbHatchlingPowerCount(4) +
            rules::sapOrbHatchlingPowerCount(5) !=
            rules::sapOrbHatchlingPowerTotal()) ++bad;
        // the Wyrmkin scalars and powers
        if (rules::sapOrbWyrmkinIntelligence() != 10 ||
            rules::sapOrbWyrmkinEgo() != 10 ||
            rules::sapOrbWyrmkinPowerTotal() != 3) ++bad;
        static const int kO2[6] = {
            2, 1, 0, 0, 0, 0,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapOrbWyrmkinPowerCount(i) != kO2[i]) ++bad;
        if (rules::sapOrbWyrmkinPowerCount(0) +
            rules::sapOrbWyrmkinPowerCount(1) +
            rules::sapOrbWyrmkinPowerCount(2) +
            rules::sapOrbWyrmkinPowerCount(3) +
            rules::sapOrbWyrmkinPowerCount(4) +
            rules::sapOrbWyrmkinPowerCount(5) !=
            rules::sapOrbWyrmkinPowerTotal()) ++bad;
        // the Dragonette scalars and powers
        if (rules::sapOrbDragonetteIntelligence() != 11 ||
            rules::sapOrbDragonetteEgo() != 11 ||
            rules::sapOrbDragonettePowerTotal() != 5) ++bad;
        static const int kO3[6] = {
            3, 1, 1, 0, 0, 0,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapOrbDragonettePowerCount(i) != kO3[i]) ++bad;
        if (rules::sapOrbDragonettePowerCount(0) +
            rules::sapOrbDragonettePowerCount(1) +
            rules::sapOrbDragonettePowerCount(2) +
            rules::sapOrbDragonettePowerCount(3) +
            rules::sapOrbDragonettePowerCount(4) +
            rules::sapOrbDragonettePowerCount(5) !=
            rules::sapOrbDragonettePowerTotal()) ++bad;
        // the Dragon scalars and powers
        if (rules::sapOrbDragonIntelligence() != 12 ||
            rules::sapOrbDragonEgo() != 12 ||
            rules::sapOrbDragonPowerTotal() != 6) ++bad;
        static const int kO4[6] = {
            4, 1, 1, 0, 0, 0,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapOrbDragonPowerCount(i) != kO4[i]) ++bad;
        if (rules::sapOrbDragonPowerCount(0) +
            rules::sapOrbDragonPowerCount(1) +
            rules::sapOrbDragonPowerCount(2) +
            rules::sapOrbDragonPowerCount(3) +
            rules::sapOrbDragonPowerCount(4) +
            rules::sapOrbDragonPowerCount(5) !=
            rules::sapOrbDragonPowerTotal()) ++bad;
        // the Great Serpent scalars and powers
        if (rules::sapOrbGreatSerpentIntelligence() != 13 ||
            rules::sapOrbGreatSerpentEgo() != 13 ||
            rules::sapOrbGreatSerpentPowerTotal() != 7) ++bad;
        static const int kO5[6] = {
            3, 2, 1, 0, 0, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapOrbGreatSerpentPowerCount(i) != kO5[i]) ++bad;
        if (rules::sapOrbGreatSerpentPowerCount(0) +
            rules::sapOrbGreatSerpentPowerCount(1) +
            rules::sapOrbGreatSerpentPowerCount(2) +
            rules::sapOrbGreatSerpentPowerCount(3) +
            rules::sapOrbGreatSerpentPowerCount(4) +
            rules::sapOrbGreatSerpentPowerCount(5) !=
            rules::sapOrbGreatSerpentPowerTotal()) ++bad;
        // the intelligence ladder rises by one
        if (rules::sapOrbWyrmkinIntelligence() !=
            rules::sapOrbHatchlingIntelligence() + 1) ++bad;
        if (rules::sapOrbDragonetteIntelligence() !=
            rules::sapOrbWyrmkinIntelligence() + 1) ++bad;
        if (rules::sapOrbDragonIntelligence() !=
            rules::sapOrbDragonetteIntelligence() + 1) ++bad;
        if (rules::sapOrbGreatSerpentIntelligence() !=
            rules::sapOrbDragonIntelligence() + 1) ++bad;
        // the Hatchling and Wyrmkin totals agree
        if (rules::sapOrbHatchlingPowerTotal() !=
            rules::sapOrbWyrmkinPowerTotal()) ++bad;
        // the cross-pin: the R240 sale table row
        // (the only range row in the table)
        if (rules::saRowLo(18) != 41 ||
            rules::saRowHi(18) != 47 ||
            rules::saSaleGp(18) != 10000 ||
            rules::saSaleGpHi(18) != 80000) ++bad;
        printf("R289 special artifacts prose part 10 pins audit: bad %d\n", bad);
    }
