    // ---- R282: the III.E Special artifacts
    // explanation prose part 3 ----
    // The Crown of Might, part2 lines 1237-1268
    // (DMG p.160) - the fourth of the 29 artifact
    // descriptions, the first item of the regalia
    // sets of Might. No seam this round: the slice
    // lies wholly on p.160.
    {
        Specart specart;
        Specart_axe_of_the_dwarvish_lords_to_codex specart_axe_of_the_dwarvish_lords_to_codex;
        int bad = 0;
        // the Crown scalars
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCrownRegaliaSetCount() != 3 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownItemsPerSet() != 3 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownChampionEthosCount() != 3 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownPossessionBenefits() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownWrongEthosDamageMin() != 5 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownWrongEthosDamageMax() != 30 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownWrongEthosSaveOrDeath() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownWearerLevelBonus() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownWornPowerTotal() != 4 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownOffEthosMalevolentCount() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownOffEthosMalevolentTable() != 4 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownSet2ndPowerTotal() != 2 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownSet3rdPowerTotal() != 5 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownDetectionRevealsAlignment() != 0 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownGemCount() != 3 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownSaleGpMin() != 50000) ++bad;
        // the alignment bands per ethos
        static const int kCrl[3] = {
            1, 7, 15,
        };
        for (int i = 0; i < 3; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapCrownAlignBandLo(i) != kCrl[i]) ++bad;
        static const int kCrh[3] = {
            6, 14, 20,
        };
        for (int i = 0; i < 3; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapCrownAlignBandHi(i) != kCrh[i]) ++bad;
        // the bands are contiguous and span the d20
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCrownAlignBandLo(0) != 1) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCrownAlignBandHi(2) != 20) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCrownAlignBandHi(0) + 1 !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownAlignBandLo(1)) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCrownAlignBandHi(1) + 1 !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownAlignBandLo(2)) ++bad;
        // the worn powers per tables I-III
        static const int kCrw[3] = {
            2, 1, 1,
        };
        for (int i = 0; i < 3; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapCrownWornPowerCount(i) != kCrw[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCrownWornPowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownWornPowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownWornPowerCount(2) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownWornPowerTotal()) ++bad;
        // the same-ethos 2nd item powers per I-II
        static const int kCs2[2] = {
            1, 1,
        };
        for (int i = 0; i < 2; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapCrownSet2ndPowerCount(i) != kCs2[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCrownSet2ndPowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownSet2ndPowerCount(1) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownSet2ndPowerTotal()) ++bad;
        // the same-ethos 3rd item powers
        static const int kCs3[5] = {
            1, 1, 1, 1, 1,
        };
        for (int i = 0; i < 5; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapCrownSet3rdPowerCount(i) != kCs3[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCrownSet3rdPowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownSet3rdPowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownSet3rdPowerCount(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownSet3rdPowerCount(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownSet3rdPowerCount(4) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownSet3rdPowerTotal()) ++bad;
        // the complete regalia set of one ethos
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCrownWornPowerTotal() +
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownSet2ndPowerTotal() +
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownSet3rdPowerTotal() != 11) ++bad;
        // the sets and the champions pair one to one
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCrownRegaliaSetCount() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownChampionEthosCount()) ++bad;
        // the wrong-ethos damage spread reads 5d6
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCrownWrongEthosDamageMin() * 6 !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrownWrongEthosDamageMax()) ++bad;
        // the cross-pin: the R240 sale table row
        if (specart.saRowLo(3) != 5 ||
            specart.saRowHi(3) != 20 ||
            specart.saSaleGp(3) != 50000) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCrownSaleGpMin() !=
            specart.saSaleGp(3)) ++bad;
        printf("R282 special artifacts prose part 3 pins audit: bad %d\n", bad);
    }
