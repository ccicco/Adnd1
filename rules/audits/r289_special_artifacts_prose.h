    // ---- R289: the III.E Special artifacts
    // explanation prose part 10 ----
    // The Orb of Dragonkind, part2 lines
    // 1518-1556 - the intro and the 1st
    // through the 5th of its 8 globes, the
    // first half of the 19th of the 29
    // descriptions. One break absorbed: the
    // extra blank pair at 1555-1556.
    {
        Specart specart;
        Specart_axe_of_the_dwarvish_lords_to_codex specart_axe_of_the_dwarvish_lords_to_codex;
        int bad = 0;
        // the Orb intro scalars
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbGoodDeitiesOrigin() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbDemonsCorrupted() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbGlobeCount() != 8 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbOnePerAge() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbSmallestInches() != 3 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbLargestInches() != 10 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbBasReliefCovered() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbDragonEssence() != 1) ++bad;
        // the Hatchling scalars and powers
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbHatchlingIntelligence() != 9 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbHatchlingEgo() != 9 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbHatchlingPowerTotal() != 3) ++bad;
        static const int kO1[6] = {
            3, 0, 0, 0, 0, 0,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbHatchlingPowerCount(i) != kO1[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbHatchlingPowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbHatchlingPowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbHatchlingPowerCount(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbHatchlingPowerCount(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbHatchlingPowerCount(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbHatchlingPowerCount(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbHatchlingPowerTotal()) ++bad;
        // the Wyrmkin scalars and powers
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbWyrmkinIntelligence() != 10 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbWyrmkinEgo() != 10 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbWyrmkinPowerTotal() != 3) ++bad;
        static const int kO2[6] = {
            2, 1, 0, 0, 0, 0,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbWyrmkinPowerCount(i) != kO2[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbWyrmkinPowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbWyrmkinPowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbWyrmkinPowerCount(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbWyrmkinPowerCount(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbWyrmkinPowerCount(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbWyrmkinPowerCount(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbWyrmkinPowerTotal()) ++bad;
        // the Dragonette scalars and powers
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbDragonetteIntelligence() != 11 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbDragonetteEgo() != 11 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbDragonettePowerTotal() != 5) ++bad;
        static const int kO3[6] = {
            3, 1, 1, 0, 0, 0,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbDragonettePowerCount(i) != kO3[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbDragonettePowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbDragonettePowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbDragonettePowerCount(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbDragonettePowerCount(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbDragonettePowerCount(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbDragonettePowerCount(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbDragonettePowerTotal()) ++bad;
        // the Dragon scalars and powers
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbDragonIntelligence() != 12 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbDragonEgo() != 12 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbDragonPowerTotal() != 6) ++bad;
        static const int kO4[6] = {
            4, 1, 1, 0, 0, 0,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbDragonPowerCount(i) != kO4[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbDragonPowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbDragonPowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbDragonPowerCount(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbDragonPowerCount(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbDragonPowerCount(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbDragonPowerCount(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbDragonPowerTotal()) ++bad;
        // the Great Serpent scalars and powers
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbGreatSerpentIntelligence() != 13 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbGreatSerpentEgo() != 13 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbGreatSerpentPowerTotal() != 7) ++bad;
        static const int kO5[6] = {
            3, 2, 1, 0, 0, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbGreatSerpentPowerCount(i) != kO5[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbGreatSerpentPowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbGreatSerpentPowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbGreatSerpentPowerCount(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbGreatSerpentPowerCount(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbGreatSerpentPowerCount(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbGreatSerpentPowerCount(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbGreatSerpentPowerTotal()) ++bad;
        // the intelligence ladder rises by one
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbWyrmkinIntelligence() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbHatchlingIntelligence() + 1) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbDragonetteIntelligence() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbWyrmkinIntelligence() + 1) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbDragonIntelligence() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbDragonetteIntelligence() + 1) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbGreatSerpentIntelligence() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbDragonIntelligence() + 1) ++bad;
        // the Hatchling and Wyrmkin totals agree
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbHatchlingPowerTotal() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbWyrmkinPowerTotal()) ++bad;
        // the cross-pin: the R240 sale table row
        // (the only range row in the table)
        if (specart.saRowLo(18) != 41 ||
            specart.saRowHi(18) != 47 ||
            specart.saSaleGp(18) != 10000 ||
            specart.saSaleGpHi(18) != 80000) ++bad;
        printf("R289 special artifacts prose part 10 pins audit: bad %d\n", bad);
    }
