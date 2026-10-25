    // ---- R290: the III.E Special artifacts
    // explanation prose part 11 ----
    // The Orb of Dragonkind globes 6-8, the
    // notes and the Orb of Might, part2 lines
    // 1557-1624. No break absorbed - the
    // round closes on the standard blank at
    // 1624; no page seam claimed (no running
    // heads between lines 1450 and 1797).
    {
        int bad = 0;
        // the Firedrake scalars and powers
        if (rules::sapOrbFiredrakeOldDragon() != 1 ||
            rules::sapOrbFiredrakeIntelligence() != 14 ||
            rules::sapOrbFiredrakeEgo() != 14 ||
            rules::sapOrbFiredrakePowerTotal() != 9) ++bad;
        static const int kO6[6] = {
            3, 3, 2, 0, 0, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapOrbFiredrakePowerCount(i) != kO6[i]) ++bad;
        if (rules::sapOrbFiredrakePowerCount(0) +
            rules::sapOrbFiredrakePowerCount(1) +
            rules::sapOrbFiredrakePowerCount(2) +
            rules::sapOrbFiredrakePowerCount(3) +
            rules::sapOrbFiredrakePowerCount(4) +
            rules::sapOrbFiredrakePowerCount(5) !=
            rules::sapOrbFiredrakePowerTotal()) ++bad;
        // the Elder Wyrm scalars and powers
        if (rules::sapOrbElderWyrmVeryOldDragon() != 1 ||
            rules::sapOrbElderWyrmIntelligence() != 16 ||
            rules::sapOrbElderWyrmEgo() != 16 ||
            rules::sapOrbElderWyrmPowerTotal() != 12) ++bad;
        static const int kO7[6] = {
            4, 3, 2, 1, 1, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapOrbElderWyrmPowerCount(i) != kO7[i]) ++bad;
        if (rules::sapOrbElderWyrmPowerCount(0) +
            rules::sapOrbElderWyrmPowerCount(1) +
            rules::sapOrbElderWyrmPowerCount(2) +
            rules::sapOrbElderWyrmPowerCount(3) +
            rules::sapOrbElderWyrmPowerCount(4) +
            rules::sapOrbElderWyrmPowerCount(5) !=
            rules::sapOrbElderWyrmPowerTotal()) ++bad;
        // the Eternal Grand Dragon scalars and powers
        if (rules::sapOrbEternalAncientDragon() != 1 ||
            rules::sapOrbEternalTiamatBahamutBonus() != 8 ||
            rules::sapOrbEternalIntelligence() != 18 ||
            rules::sapOrbEternalEgo() != 18 ||
            rules::sapOrbEternalPowerTotal() != 13) ++bad;
        static const int kO8[6] = {
            4, 3, 2, 1, 2, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapOrbEternalPowerCount(i) != kO8[i]) ++bad;
        if (rules::sapOrbEternalPowerCount(0) +
            rules::sapOrbEternalPowerCount(1) +
            rules::sapOrbEternalPowerCount(2) +
            rules::sapOrbEternalPowerCount(3) +
            rules::sapOrbEternalPowerCount(4) +
            rules::sapOrbEternalPowerCount(5) !=
            rules::sapOrbEternalPowerTotal()) ++bad;
        // the notes scalars
        if (rules::sapOrbNotesEvilComponent() != 1 ||
            rules::sapOrbNotesNeutralGoodResist() != 1 ||
            rules::sapOrbNotesCharmRangeInches() != 5 ||
            rules::sapOrbNotesCharmRounds() != 1 ||
            rules::sapOrbNotesAwakeAndAware() != 1 ||
            rules::sapOrbNotesEvilAutoCharmed() != 1 ||
            rules::sapOrbNotesNeutralSavePenalty() != 4 ||
            rules::sapOrbNotesGoodSavePenalty() != 2 ||
            rules::sapOrbNotesCharmedWisdomPercent() != 50 ||
            rules::sapOrbNotesFeeblemindIntelligence() != 3 ||
            rules::sapOrbNotesInsanePercent() != 50 ||
            rules::sapOrbNotesAwakeMindOnly() != 1 ||
            rules::sapOrbNotesSacrificeDestruction() != 1) ++bad;
        // the Orb of Might scalars
        if (rules::sapOrbMightOrbCount() != 3 ||
            rules::sapOrbMightCrownSource() != 1 ||
            rules::sapOrbMightEvilDieLo() != 1 ||
            rules::sapOrbMightEvilDieHi() != 6 ||
            rules::sapOrbMightGoodDieLo() != 7 ||
            rules::sapOrbMightGoodDieHi() != 14 ||
            rules::sapOrbMightNeutralDieLo() != 15 ||
            rules::sapOrbMightNeutralDieHi() != 20 ||
            rules::sapOrbMightTouchDeathSave() != 1 ||
            rules::sapOrbMightTouchDamageLo() != 4 ||
            rules::sapOrbMightTouchDamageHi() != 24 ||
            rules::sapOrbMightRegaliaTableFour() != 1 ||
            rules::sapOrbMightPlatinumGems() != 1 ||
            rules::sapOrbMightValueGp() != 100000 ||
            rules::sapOrbMightGemOfBrightness() != 1 ||
            rules::sapOrbMightPowerEthosCount() != 3 ||
            rules::sapOrbMightRegaliaPowers() != 1) ++bad;
        static const int kOM[6] = {
            2, 0, 1, 0, 0, 0,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapOrbMightPowerCount(i) != kOM[i]) ++bad;
        if (rules::sapOrbMightPowerCount(0) +
            rules::sapOrbMightPowerCount(1) +
            rules::sapOrbMightPowerCount(2) +
            rules::sapOrbMightPowerCount(3) +
            rules::sapOrbMightPowerCount(4) +
            rules::sapOrbMightPowerCount(5) !=
            rules::sapOrbMightPowerTotal()) ++bad;
        // the within-round intelligence ladder rises by two
        if (rules::sapOrbElderWyrmIntelligence() !=
            rules::sapOrbFiredrakeIntelligence() + 2) ++bad;
        if (rules::sapOrbEternalIntelligence() !=
            rules::sapOrbElderWyrmIntelligence() + 2) ++bad;
        // the ethos die bands partition 1 through 20
        if (rules::sapOrbMightGoodDieLo() !=
            rules::sapOrbMightEvilDieHi() + 1) ++bad;
        if (rules::sapOrbMightNeutralDieLo() !=
            rules::sapOrbMightGoodDieHi() + 1) ++bad;
        // the cross-pin: the R240 sale table row
        // (a fixed row, unlike the Dragonkind band)
        if (rules::saRowLo(19) != 48 ||
            rules::saRowHi(19) != 63 ||
            rules::saSaleGp(19) != 100000 ||
            rules::saSaleGpHi(19) != 0) ++bad;
        printf("R290 special artifacts prose part 11 pins audit: bad %d\n", bad);
    }
