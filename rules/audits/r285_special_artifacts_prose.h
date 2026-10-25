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
        int bad = 0;
        // the Organ scalars
        if (rules::sapOrganPipeCount() != 77 ||
            rules::sapOrganStopCount() != 13 ||
            rules::sapOrganPedalCount() != 3 ||
            rules::sapOrganBellowsElemental() != 1 ||
            rules::sapOrganStopsVaryVoice() != 1 ||
            rules::sapOrganKeysVaryNotes() != 1 ||
            rules::sapOrganPedalPurposeUnknown() != 1 ||
            rules::sapOrganStillWorksDespiteTime() != 1) ++bad;
        if (rules::sapOrganWrongStopsSummon() != 1 ||
            rules::sapOrganWrongKeysBackfire() != 1 ||
            rules::sapOrganMisplayAlignment() != 1 ||
            rules::sapOrganDmAssignsStopsKeys() != 1 ||
            rules::sapOrganPowerTotal() != 34 ||
            rules::sapOrganMisplayNegates() != 1) ++bad;
        // the Organ powers per table I-VI
        static const int kOrg[6] = {
            7, 7, 3, 7, 7, 3,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapOrganPowerCount(i) != kOrg[i]) ++bad;
        if (rules::sapOrganPowerCount(0) +
            rules::sapOrganPowerCount(1) +
            rules::sapOrganPowerCount(2) +
            rules::sapOrganPowerCount(3) +
            rules::sapOrganPowerCount(4) +
            rules::sapOrganPowerCount(5) !=
            rules::sapOrganPowerTotal()) ++bad;
        // the Horn scalars
        if (rules::sapHornResemblesCommonHorns() != 1 ||
            rules::sapHornSuggestedPowerPct() != 75 ||
            rules::sapHornSuggestedEffectPct() != 25 ||
            rules::sapHornIgnoresInappropriate() != 1) ++bad;
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
            if (rules::sapHornBlastPowerTable(i) != kHbp[i]) ++bad;
        for (int i = 0; i < 3; ++i)
            if (rules::sapHornBlastEffectTable(i) != kHbe[i]) ++bad;
        // the suggested split sums to 100
        if (rules::sapHornSuggestedPowerPct() +
            rules::sapHornSuggestedEffectPct() != 100) ++bad;
        // the Coat scalars
        if (rules::sapCoatArndOfTdon() != 1 ||
            rules::sapCoatChainLinksWeightless() != 1 ||
            rules::sapCoatCoveredAreaCount() != 3 ||
            rules::sapCoatMinWearerHeightFt() != 3 ||
            rules::sapCoatMaxWearerHeightFt() != 8 ||
            rules::sapCoatInvulnerableCovered() != 1 ||
            rules::sapCoatUncoveredAc() != 5) ++bad;
        if (rules::sapCoatSaveBonus() != 5 ||
            rules::sapCoatFireResistance() != 1 ||
            rules::sapCoatElementalImmunityCount() != 3 ||
            rules::sapCoatPowerTotal() != 10) ++bad;
        // the Coat powers per table I-VI
        static const int kCoat[6] = {
            3, 2, 2, 1, 1, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapCoatPowerCount(i) != kCoat[i]) ++bad;
        if (rules::sapCoatPowerCount(0) +
            rules::sapCoatPowerCount(1) +
            rules::sapCoatPowerCount(2) +
            rules::sapCoatPowerCount(3) +
            rules::sapCoatPowerCount(4) +
            rules::sapCoatPowerCount(5) !=
            rules::sapCoatPowerTotal()) ++bad;
        // the AC 5 and the save +5 mirror
        if (rules::sapCoatUncoveredAc() !=
            rules::sapCoatSaveBonus()) ++bad;
        // the wearer height range 3 to 8
        if (rules::sapCoatMaxWearerHeightFt() -
            rules::sapCoatMinWearerHeightFt() != 5) ++bad;
        // the cross-pins: the R240 sale table rows
        if (rules::saRowLo(8) != 26 ||
            rules::saRowHi(8) != 26 ||
            rules::saSaleGp(8) != 25000 ||
            rules::saRowLo(9) != 27 ||
            rules::saRowHi(9) != 27 ||
            rules::saSaleGp(9) != 20000 ||
            rules::saRowLo(10) != 28 ||
            rules::saRowHi(10) != 29 ||
            rules::saSaleGp(10) != 47500) ++bad;
        printf("R285 special artifacts prose part 6 pins audit: bad %d\n", bad);
    }
