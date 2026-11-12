    // ---- R285: the III.E Special artifacts
    // explanation prose part 6 ----
    // The Mystical Organ of Heward,
    // The Horn of Change and
    // The Invulnerable Coat of Arnd,
    // part2 lines 1359-1403 (DMG
    // p.161-162), the ninth through
    // the 11th of the 29 artifact
    // descriptions. No page break
    // inside the slice this round.
    {
        Specart specart;
        Specart_axe_of_the_dwarvish_lords_to_codex specart_axe_of_the_dwarvish_lords_to_codex;
        int bad = 0;
        // the Organ scalars
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrganPipeCount() != 77 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrganStopCount() != 13 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrganPedalCount() != 3 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrganBellowsElemental() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrganStopsVaryVoice() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrganKeysVaryNotes() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrganPedalPurposeUnknown() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrganStillWorksDespiteTime() != 1) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrganWrongStopsSummon() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrganWrongKeysBackfire() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrganMisplayAlignment() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrganDmAssignsStopsKeys() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrganPowerTotal() != 34 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrganMisplayNegates() != 1) ++bad;
        // the Organ powers per table I-VI
        static const int kOrg[6] = {
            7, 7, 3, 7, 7, 3,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrganPowerCount(i) != kOrg[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapOrganPowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrganPowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrganPowerCount(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrganPowerCount(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrganPowerCount(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrganPowerCount(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapOrganPowerTotal()) ++bad;
        // the Horn scalars
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapHornResemblesCommonHorns() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHornSuggestedPowerPct() != 75 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHornSuggestedEffectPct() != 25 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapHornIgnoresInappropriate() != 1) ++bad;
        // the Horn blast mappings: 1 wind
        // gives I or III, 2 give II or VI,
        // 3 give V or IV
        static const int kHbp[3] = {
            1, 2, 5,
        };
        static const int kHbe[3] = {
            3, 6, 4,
        };
        for (int i = 0; i < 3; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapHornBlastPowerTable(i) != kHbp[i]) ++bad;
        for (int i = 0; i < 3; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapHornBlastEffectTable(i) != kHbe[i]) ++bad;
        // the suggested split sums to 100
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapHornSuggestedPowerPct() +
            specart_axe_of_the_dwarvish_lords_to_codex.sapHornSuggestedEffectPct() != 100) ++bad;
        // the Coat scalars
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCoatArndOfTdon() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCoatChainLinksWeightless() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCoatCoveredAreaCount() != 3 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCoatMinWearerHeightFt() != 3 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCoatMaxWearerHeightFt() != 8 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCoatInvulnerableCovered() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCoatUncoveredAc() != 5) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCoatSaveBonus() != 5 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCoatFireResistance() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCoatElementalImmunityCount() != 3 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCoatPowerTotal() != 10) ++bad;
        // the Coat powers per table I-VI
        static const int kCoat[6] = {
            3, 2, 2, 1, 1, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapCoatPowerCount(i) != kCoat[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCoatPowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapCoatPowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapCoatPowerCount(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapCoatPowerCount(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapCoatPowerCount(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapCoatPowerCount(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapCoatPowerTotal()) ++bad;
        // the AC 5 and the save +5 mirror
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCoatUncoveredAc() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapCoatSaveBonus()) ++bad;
        // the wearer height range 3 to 8
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCoatMaxWearerHeightFt() -
            specart_axe_of_the_dwarvish_lords_to_codex.sapCoatMinWearerHeightFt() != 5) ++bad;
        // the cross-pins: the R240 sale table rows
        if (specart.saRowLo(8) != 26 ||
            specart.saRowHi(8) != 26 ||
            specart.saSaleGp(8) != 25000 ||
            specart.saRowLo(9) != 27 ||
            specart.saRowHi(9) != 27 ||
            specart.saSaleGp(9) != 20000 ||
            specart.saRowLo(10) != 28 ||
            specart.saRowHi(10) != 29 ||
            specart.saSaleGp(10) != 47500) ++bad;
        printf("R285 special artifacts prose part 6 pins audit: bad %d\n", bad);
    }
