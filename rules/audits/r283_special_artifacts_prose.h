    // ---- R283: the III.E Special artifacts
    // explanation prose part 4 ----
    // The Crystal of the Ebon Flame and the Cup
    // and Talisman of Al Akbar, part2 lines
    // 1270-1316 (DMG p.160) - the fifth and
    // sixth of the 29 artifact descriptions.
    // No seam this round either: both lie
    // wholly on p.160.
    {
        Specart specart;
        Specart_axe_of_the_dwarvish_lords_to_codex specart_axe_of_the_dwarvish_lords_to_codex;
        int bad = 0;
        // the Crystal scalars
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCrystalOriginUnknown() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrystalDiamondHard() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrystalTouchRaysBlackFlame() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrystalCharmRadiusFeet() != 30 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrystalCharmIsFireCharm() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrystalPowersByGazing() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrystalPowerTotal() != 10) ++bad;
        // the Cup and Talisman scalars
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCupTalismanRelicCount() != 2 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCupTalismanPaynimGift() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCupTalismanInvokedDevastationEra() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCupTalismanLostToRaiders() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCupTalismanPotionClassCount() != 4 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCupTalismanPotionPerWeek() != 1 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCupGemCount() != 12 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCupJewelryGpMin() != 75000 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCupRadiatesMagic() != 0 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCupPowerTotal() != 5 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapTalismanPointCount() != 8 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapTalismanPointGemCount() != 8 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapTalismanBeadSetCount() != 8 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapTalismanBeadsPerSet() != 3 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapTalismanJewelryGpMin() != 10000 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapTalismanRadiatesMagic() != 0 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapTalismanPowerTotal() != 3 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCupTalismanBothPowerTotal() != 2 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapCupTalismanPotionBandCount() != 6) ++bad;
        // the crystal powers per table I-VI
        static const int kCry[6] = {
            4, 2, 1, 1, 1, 1,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapCrystalPowerCount(i) != kCry[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCrystalPowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrystalPowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrystalPowerCount(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrystalPowerCount(3) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrystalPowerCount(4) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrystalPowerCount(5) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapCrystalPowerTotal()) ++bad;
        // the cup powers per tables I-III
        static const int kCup[3] = {
            4, 0, 1,
        };
        for (int i = 0; i < 3; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapCupPowerCount(i) != kCup[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCupPowerCount(1) != 0) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCupPowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapCupPowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapCupPowerCount(2) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapCupPowerTotal()) ++bad;
        // the talisman powers per tables I-IV
        static const int kTal[4] = {
            0, 2, 0, 1,
        };
        for (int i = 0; i < 4; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapTalismanPowerCount(i) != kTal[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapTalismanPowerCount(0) != 0 ||
            specart_axe_of_the_dwarvish_lords_to_codex.sapTalismanPowerCount(2) != 0) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapTalismanPowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapTalismanPowerCount(1) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapTalismanPowerCount(2) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapTalismanPowerCount(3) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapTalismanPowerTotal()) ++bad;
        // the both powers per tables V-VI
        static const int kBot[2] = {
            1, 1,
        };
        for (int i = 0; i < 2; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapCupTalismanBothPowerCount(i) != kBot[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCupTalismanBothPowerCount(0) +
            specart_axe_of_the_dwarvish_lords_to_codex.sapCupTalismanBothPowerCount(1) !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapCupTalismanBothPowerTotal()) ++bad;
        // the potion table bands, contiguous over the d20
        static const int kPlo[6] = {
            1, 6, 11, 16, 18, 20,
        };
        static const int kPhi[6] = {
            5, 10, 15, 17, 19, 20,
        };
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapCupTalismanPotionBandLo(i) != kPlo[i]) ++bad;
        for (int i = 0; i < 6; ++i)
            if (specart_axe_of_the_dwarvish_lords_to_codex.sapCupTalismanPotionBandHi(i) != kPhi[i]) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCupTalismanPotionBandLo(0) != 1) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCupTalismanPotionBandHi(5) != 20) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCupTalismanPotionBandHi(0) + 1 !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapCupTalismanPotionBandLo(1)) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCupTalismanPotionBandHi(1) + 1 !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapCupTalismanPotionBandLo(2)) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCupTalismanPotionBandHi(2) + 1 !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapCupTalismanPotionBandLo(3)) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCupTalismanPotionBandHi(3) + 1 !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapCupTalismanPotionBandLo(4)) ++bad;
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCupTalismanPotionBandHi(4) + 1 !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapCupTalismanPotionBandLo(5)) ++bad;
        // the talisman beads: 8 sets of 3 beads each
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapTalismanBeadSetCount() *
            specart_axe_of_the_dwarvish_lords_to_codex.sapTalismanBeadsPerSet() != 24) ++bad;
        // a gem tips each of the 8 star points
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapTalismanPointGemCount() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapTalismanPointCount()) ++bad;
        // the same era the Axe was lost in
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapAxeInvokedDevastationLost() !=
            specart_axe_of_the_dwarvish_lords_to_codex.sapCupTalismanInvokedDevastationEra()) ++bad;
        // the cup jewelry value is NOT its sale value
        if (specart_axe_of_the_dwarvish_lords_to_codex.sapCupJewelryGpMin() ==
            specart.saSaleGp(5)) ++bad;
        // the cross-pins: the R240 sale table rows
        if (specart.saRowLo(4) != 21 ||
            specart.saRowHi(4) != 21 ||
            specart.saSaleGp(4) != 75000 ||
            specart.saRowLo(5) != 22 ||
            specart.saRowHi(5) != 22 ||
            specart.saSaleGp(5) != 85000) ++bad;
        printf("R283 special artifacts prose part 4 pins audit: bad %d\n", bad);
    }
