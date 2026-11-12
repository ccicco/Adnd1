    // ---- R290: the III.E Special artifacts
    // explanation prose part 11 ----
    // The Orb of Dragonkind globes 6-8, the
    // notes and the Orb of Might, part2 lines
    // 1557-1624. No break absorbed - the
    // round closes on the standard blank at
    // 1624; no page seam claimed (no running
    // heads between lines 1450 and 1797).
    {
        Specart specart;
        Specart_axe_of_the_dwarvish_lords_to_codex specart_axe_of_the_dwarvish_lords_to_codex;
        int bad = 0;
        // the Firedrake scalars and powers
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbFiredrakeOldDragon() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbFiredrakeIntelligence() != 14 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbFiredrakeEgo() != 14 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbFiredrakePowerTotal() != 9) ++bad;
        static const int kO6[6] = {
            3, 3, 2, 0, 0, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbFiredrakePowerCount(i) != kO6[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbFiredrakePowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbFiredrakePowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbFiredrakePowerCount(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbFiredrakePowerCount(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbFiredrakePowerCount(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbFiredrakePowerCount(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbFiredrakePowerTotal()) ++bad;
        // the Elder Wyrm scalars and powers
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbElderWyrmVeryOldDragon() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbElderWyrmIntelligence() != 16 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbElderWyrmEgo() != 16 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbElderWyrmPowerTotal() != 12) ++bad;
        static const int kO7[6] = {
            4, 3, 2, 1, 1, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbElderWyrmPowerCount(i) != kO7[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbElderWyrmPowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbElderWyrmPowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbElderWyrmPowerCount(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbElderWyrmPowerCount(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbElderWyrmPowerCount(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbElderWyrmPowerCount(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbElderWyrmPowerTotal()) ++bad;
        // the Eternal Grand Dragon scalars and powers
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbEternalAncientDragon() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbEternalTiamatBahamutBonus() != 8 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbEternalIntelligence() != 18 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbEternalEgo() != 18 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbEternalPowerTotal() != 13) ++bad;
        static const int kO8[6] = {
            4, 3, 2, 1, 2, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbEternalPowerCount(i) != kO8[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbEternalPowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbEternalPowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbEternalPowerCount(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbEternalPowerCount(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbEternalPowerCount(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbEternalPowerCount(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbEternalPowerTotal()) ++bad;
        // the notes scalars
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbNotesEvilComponent() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbNotesNeutralGoodResist() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbNotesCharmRangeInches() != 5 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbNotesCharmRounds() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbNotesAwakeAndAware() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbNotesEvilAutoCharmed() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbNotesNeutralSavePenalty() != 4 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbNotesGoodSavePenalty() != 2 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbNotesCharmedWisdomPercent() != 50 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbNotesFeeblemindIntelligence() != 3 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbNotesInsanePercent() != 50 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbNotesAwakeMindOnly() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbNotesSacrificeDestruction() != 1) ++bad;
        // the Orb of Might scalars
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbMightOrbCount() != 3 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbMightCrownSource() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbMightEvilDieLo() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbMightEvilDieHi() != 6 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbMightGoodDieLo() != 7 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbMightGoodDieHi() != 14 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbMightNeutralDieLo() != 15 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbMightNeutralDieHi() != 20 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbMightTouchDeathSave() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbMightTouchDamageLo() != 4 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbMightTouchDamageHi() != 24 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbMightRegaliaTableFour() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbMightPlatinumGems() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbMightValueGp() != 100000 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbMightGemOfBrightness() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbMightPowerEthosCount() != 3 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbMightRegaliaPowers() != 1) ++bad;
        static const int kOM[6] = {
            2, 0, 1, 0, 0, 0,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbMightPowerCount(i) != kOM[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbMightPowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbMightPowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbMightPowerCount(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbMightPowerCount(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbMightPowerCount(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbMightPowerCount(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbMightPowerTotal()) ++bad;
        // the within-round intelligence ladder rises by two
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbElderWyrmIntelligence() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbFiredrakeIntelligence() + 2) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbEternalIntelligence() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbElderWyrmIntelligence() + 2) ++bad;
        // the ethos die bands partition 1 through 20
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbMightGoodDieLo() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbMightEvilDieHi() + 1) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrbMightNeutralDieLo() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrbMightGoodDieHi() + 1) ++bad;
        // the cross-pin: the R240 sale table row
        // (a fixed row, unlike the Dragonkind band)
        if (specart.saRowLo(19) != 48 ||
            specart.saRowHi(19) != 63 ||
            specart.saSaleGp(19) != 100000 ||
            specart.saSaleGpHi(19) != 0) ++bad;
        printf("R290 special artifacts prose part 11 pins audit: bad %d\n", bad);
    }
