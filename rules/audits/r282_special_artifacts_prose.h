    // ---- R282: the III.E Special artifacts
    // explanation prose part 3 ----
    // The Crown of Might, part2 lines 1237-1268
    // (DMG p.160) - the fourth of the 29 artifact
    // descriptions, the first item of the regalia
    // sets of Might. No seam this round: the slice
    // lies wholly on p.160.
    {
        int bad = 0;
        // the Crown scalars
        if (rules::sapCrownRegaliaSetCount() != 3 ||
            rules::sapCrownItemsPerSet() != 3 ||
            rules::sapCrownChampionEthosCount() != 3 ||
            rules::sapCrownPossessionBenefits() != 1 ||
            rules::sapCrownWrongEthosDamageMin() != 5 ||
            rules::sapCrownWrongEthosDamageMax() != 30 ||
            rules::sapCrownWrongEthosSaveOrDeath() != 1 ||
            rules::sapCrownWearerLevelBonus() != 1 ||
            rules::sapCrownWornPowerTotal() != 4 ||
            rules::sapCrownOffEthosMalevolentCount() != 1 ||
            rules::sapCrownOffEthosMalevolentTable() != 4 ||
            rules::sapCrownSet2ndPowerTotal() != 2 ||
            rules::sapCrownSet3rdPowerTotal() != 5 ||
            rules::sapCrownDetectionRevealsAlignment() != 0 ||
            rules::sapCrownGemCount() != 3 ||
            rules::sapCrownSaleGpMin() != 50000) ++bad;
        // the alignment bands per ethos
        static const int kCrl[3] = {
            1, 7, 15,
        };
        for (int i = 0; i < 3; ++i)
            if (rules::sapCrownAlignBandLo(i) != kCrl[i]) ++bad;
        static const int kCrh[3] = {
            6, 14, 20,
        };
        for (int i = 0; i < 3; ++i)
            if (rules::sapCrownAlignBandHi(i) != kCrh[i]) ++bad;
        // the bands are contiguous and span the d20
        if (rules::sapCrownAlignBandLo(0) != 1) ++bad;
        if (rules::sapCrownAlignBandHi(2) != 20) ++bad;
        if (rules::sapCrownAlignBandHi(0) + 1 !=
            rules::sapCrownAlignBandLo(1)) ++bad;
        if (rules::sapCrownAlignBandHi(1) + 1 !=
            rules::sapCrownAlignBandLo(2)) ++bad;
        // the worn powers per tables I-III
        static const int kCrw[3] = {
            2, 1, 1,
        };
        for (int i = 0; i < 3; ++i)
            if (rules::sapCrownWornPowerCount(i) != kCrw[i]) ++bad;
        if (rules::sapCrownWornPowerCount(0) +
            rules::sapCrownWornPowerCount(1) +
            rules::sapCrownWornPowerCount(2) !=
            rules::sapCrownWornPowerTotal()) ++bad;
        // the same-ethos 2nd item powers per I-II
        static const int kCs2[2] = {
            1, 1,
        };
        for (int i = 0; i < 2; ++i)
            if (rules::sapCrownSet2ndPowerCount(i) != kCs2[i]) ++bad;
        if (rules::sapCrownSet2ndPowerCount(0) +
            rules::sapCrownSet2ndPowerCount(1) !=
            rules::sapCrownSet2ndPowerTotal()) ++bad;
        // the same-ethos 3rd item powers
        static const int kCs3[5] = {
            1, 1, 1, 1, 1,
        };
        for (int i = 0; i < 5; ++i)
            if (rules::sapCrownSet3rdPowerCount(i) != kCs3[i]) ++bad;
        if (rules::sapCrownSet3rdPowerCount(0) +
            rules::sapCrownSet3rdPowerCount(1) +
            rules::sapCrownSet3rdPowerCount(2) +
            rules::sapCrownSet3rdPowerCount(3) +
            rules::sapCrownSet3rdPowerCount(4) !=
            rules::sapCrownSet3rdPowerTotal()) ++bad;
        // the complete regalia set of one ethos
        if (rules::sapCrownWornPowerTotal() +
            rules::sapCrownSet2ndPowerTotal() +
            rules::sapCrownSet3rdPowerTotal() != 11) ++bad;
        // the sets and the champions pair one to one
        if (rules::sapCrownRegaliaSetCount() !=
            rules::sapCrownChampionEthosCount()) ++bad;
        // the wrong-ethos damage spread reads 5d6
        if (rules::sapCrownWrongEthosDamageMin() * 6 !=
            rules::sapCrownWrongEthosDamageMax()) ++bad;
        // the cross-pin: the R240 sale table row
        if (rules::saRowLo(3) != 5 ||
            rules::saRowHi(3) != 20 ||
            rules::saSaleGp(3) != 50000) ++bad;
        if (rules::sapCrownSaleGpMin() !=
            rules::saSaleGp(3)) ++bad;
        printf("R282 special artifacts prose part 3 pins audit: bad %d\n", bad);
    }
