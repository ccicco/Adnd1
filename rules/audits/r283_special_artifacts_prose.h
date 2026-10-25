    // ---- R283: the III.E Special artifacts
    // explanation prose part 4 ----
    // The Crystal of the Ebon Flame and the Cup
    // and Talisman of Al Akbar, part2 lines
    // 1270-1316 (DMG p.160) - the fifth and
    // sixth of the 29 artifact descriptions.
    // No seam this round either: both lie
    // wholly on p.160.
    {
        int bad = 0;
        // the Crystal scalars
        if (rules::sapCrystalOriginUnknown() != 1 ||
            rules::sapCrystalDiamondHard() != 1 ||
            rules::sapCrystalTouchRaysBlackFlame() != 1 ||
            rules::sapCrystalCharmRadiusFeet() != 30 ||
            rules::sapCrystalCharmIsFireCharm() != 1 ||
            rules::sapCrystalPowersByGazing() != 1 ||
            rules::sapCrystalPowerTotal() != 10) ++bad;
        // the Cup and Talisman scalars
        if (rules::sapCupTalismanRelicCount() != 2 ||
            rules::sapCupTalismanPaynimGift() != 1 ||
            rules::sapCupTalismanInvokedDevastationEra() != 1 ||
            rules::sapCupTalismanLostToRaiders() != 1 ||
            rules::sapCupTalismanPotionClassCount() != 4 ||
            rules::sapCupTalismanPotionPerWeek() != 1 ||
            rules::sapCupGemCount() != 12 ||
            rules::sapCupJewelryGpMin() != 75000 ||
            rules::sapCupRadiatesMagic() != 0 ||
            rules::sapCupPowerTotal() != 5 ||
            rules::sapTalismanPointCount() != 8 ||
            rules::sapTalismanPointGemCount() != 8 ||
            rules::sapTalismanBeadSetCount() != 8 ||
            rules::sapTalismanBeadsPerSet() != 3 ||
            rules::sapTalismanJewelryGpMin() != 10000 ||
            rules::sapTalismanRadiatesMagic() != 0 ||
            rules::sapTalismanPowerTotal() != 3 ||
            rules::sapCupTalismanBothPowerTotal() != 2 ||
            rules::sapCupTalismanPotionBandCount() != 6) ++bad;
        // the crystal powers per table I-VI
        static const int kCry[6] = {
            4, 2, 1, 1, 1, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapCrystalPowerCount(i) != kCry[i]) ++bad;
        if (rules::sapCrystalPowerCount(0) +
            rules::sapCrystalPowerCount(1) +
            rules::sapCrystalPowerCount(2) +
            rules::sapCrystalPowerCount(3) +
            rules::sapCrystalPowerCount(4) +
            rules::sapCrystalPowerCount(5) !=
            rules::sapCrystalPowerTotal()) ++bad;
        // the cup powers per tables I-III
        static const int kCup[3] = {
            4, 0, 1,
        };
        for (int i = 0; i < 3; ++i)
            if (rules::sapCupPowerCount(i) != kCup[i]) ++bad;
        if (rules::sapCupPowerCount(1) != 0) ++bad;
        if (rules::sapCupPowerCount(0) +
            rules::sapCupPowerCount(1) +
            rules::sapCupPowerCount(2) !=
            rules::sapCupPowerTotal()) ++bad;
        // the talisman powers per tables I-IV
        static const int kTal[4] = {
            0, 2, 0, 1,
        };
        for (int i = 0; i < 4; ++i)
            if (rules::sapTalismanPowerCount(i) != kTal[i]) ++bad;
        if (rules::sapTalismanPowerCount(0) != 0 ||
            rules::sapTalismanPowerCount(2) != 0) ++bad;
        if (rules::sapTalismanPowerCount(0) +
            rules::sapTalismanPowerCount(1) +
            rules::sapTalismanPowerCount(2) +
            rules::sapTalismanPowerCount(3) !=
            rules::sapTalismanPowerTotal()) ++bad;
        // the both powers per tables V-VI
        static const int kBot[2] = {
            1, 1,
        };
        for (int i = 0; i < 2; ++i)
            if (rules::sapCupTalismanBothPowerCount(i) != kBot[i]) ++bad;
        if (rules::sapCupTalismanBothPowerCount(0) +
            rules::sapCupTalismanBothPowerCount(1) !=
            rules::sapCupTalismanBothPowerTotal()) ++bad;
        // the potion table bands, contiguous over the d20
        static const int kPlo[6] = {
            1, 6, 11, 16, 18, 20,
        };
        static const int kPhi[6] = {
            5, 10, 15, 17, 19, 20,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::sapCupTalismanPotionBandLo(i) != kPlo[i]) ++bad;
        for (int i = 0; i < 6; ++i)
            if (rules::sapCupTalismanPotionBandHi(i) != kPhi[i]) ++bad;
        if (rules::sapCupTalismanPotionBandLo(0) != 1) ++bad;
        if (rules::sapCupTalismanPotionBandHi(5) != 20) ++bad;
        if (rules::sapCupTalismanPotionBandHi(0) + 1 !=
            rules::sapCupTalismanPotionBandLo(1)) ++bad;
        if (rules::sapCupTalismanPotionBandHi(1) + 1 !=
            rules::sapCupTalismanPotionBandLo(2)) ++bad;
        if (rules::sapCupTalismanPotionBandHi(2) + 1 !=
            rules::sapCupTalismanPotionBandLo(3)) ++bad;
        if (rules::sapCupTalismanPotionBandHi(3) + 1 !=
            rules::sapCupTalismanPotionBandLo(4)) ++bad;
        if (rules::sapCupTalismanPotionBandHi(4) + 1 !=
            rules::sapCupTalismanPotionBandLo(5)) ++bad;
        // the talisman beads: 8 sets of 3 beads each
        if (rules::sapTalismanBeadSetCount() *
            rules::sapTalismanBeadsPerSet() != 24) ++bad;
        // a gem tips each of the 8 star points
        if (rules::sapTalismanPointGemCount() !=
            rules::sapTalismanPointCount()) ++bad;
        // the same era the Axe was lost in
        if (rules::sapAxeInvokedDevastationLost() !=
            rules::sapCupTalismanInvokedDevastationEra()) ++bad;
        // the cup jewelry value is NOT its sale value
        if (rules::sapCupJewelryGpMin() ==
            rules::saSaleGp(5)) ++bad;
        // the cross-pins: the R240 sale table rows
        if (rules::saRowLo(4) != 21 ||
            rules::saRowHi(4) != 21 ||
            rules::saSaleGp(4) != 75000 ||
            rules::saRowLo(5) != 22 ||
            rules::saRowHi(5) != 22 ||
            rules::saSaleGp(5) != 85000) ++bad;
        printf("R283 special artifacts prose part 4 pins audit: bad %d\n", bad);
    }
