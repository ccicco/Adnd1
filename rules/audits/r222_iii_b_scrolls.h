    // ---- R222: the III.B scrolls prose pins audit ----
    // DMG pp.126-127: the spell-scroll
    // structure (with the illusionist
    // alternative ranges), the
    // protection scroll values, the
    // curse sub-table and the sale/
    // x.p. prose.
    {
        int bad = 0;
        // the spell-scroll rows
        if (rules::scrollSpellRowCount() != 16) ++bad;
        static const int kSLo[16] = {
            1, 11, 17, 20, 25, 28, 33, 36, 40, 43,
            47, 50, 53, 55, 58, 60,
        };
        static const int kSHi[16] = {
            10, 16, 19, 24, 27, 32, 35, 39, 42, 46,
            49, 52, 54, 57, 59, 60,
        };
        static const int kN[16] = {
            1, 1, 1, 2, 2, 3, 3, 4, 4, 5,
            5, 6, 6, 7, 7, 7,
        };
        static const int kLvLo[16] = {
            1, 1, 2, 1, 1, 1, 2, 1, 1, 1,
            1, 1, 3, 1, 2, 4,
        };
        static const int kLvHi[16] = {
            4, 6, 9, 4, 8, 4, 9, 6, 8, 6,
            8, 6, 8, 8, 9, 9,
        };
        static const int kAlt[16] = {
            0, 0, 1, 0, 1, 0, 1, 0, 1, 0,
            1, 0, 1, 0, 0, 1,
        };
        static const int kALo[16] = {
            0, 0, 2, 0, 1, 0, 2, 0, 1, 0,
            1, 0, 3, 0, 0, 4,
        };
        static const int kAHi[16] = {
            0, 0, 7, 0, 6, 0, 7, 0, 6, 0,
            6, 0, 6, 0, 0, 7,
        };
        for (int i = 0; i < 16; ++i)
            if (rules::scrollSpellRowLo(i) != kSLo[i] ||
                rules::scrollSpellRowHi(i) != kSHi[i] ||
                rules::scrollSpellRowN(i) != kN[i]) ++bad;
        for (int i = 0; i < 16; ++i)
            if (rules::scrollSpellRowLvLo(i) != kLvLo[i] ||
                rules::scrollSpellRowLvHi(i) != kLvHi[i] ||
                rules::scrollSpellRowHasAlt(i) != kAlt[i] ||
                rules::scrollSpellRowAltLvLo(i) != kALo[i] ||
                rules::scrollSpellRowAltLvHi(i) != kAHi[i])
                ++bad;
        for (int i = 1; i < 16; ++i)
            if (rules::scrollSpellRowLo(i) !=
                rules::scrollSpellRowHi(i - 1) + 1) ++bad;
        if (rules::scrollSpellRowLo(-5) != 1 ||
            rules::scrollSpellRowHi(99) != 60) ++bad;
        // the alt rows are the 2, 4, 6, 8,
        // 10, 12 and 15 indices; alt lo =
        // main lo, alt hi < main hi
        if (rules::scrollSpellAltRangeCount() != 7) ++bad;
        if (!rules::scrollSpellRowHasAlt(2) ||
            !rules::scrollSpellRowHasAlt(4) ||
            !rules::scrollSpellRowHasAlt(6) ||
            !rules::scrollSpellRowHasAlt(8) ||
            !rules::scrollSpellRowHasAlt(10) ||
            !rules::scrollSpellRowHasAlt(12) ||
            !rules::scrollSpellRowHasAlt(15)) ++bad;
        if (rules::scrollSpellRowHasAlt(0) ||
            rules::scrollSpellRowHasAlt(13)) ++bad;
        if (rules::scrollSpellRowAltLvLo(2) != 2 ||
            rules::scrollSpellRowAltLvHi(2) != 7 ||
            rules::scrollSpellRowAltLvHi(15) != 7 ||
            rules::scrollSpellRowAltLvLo(12) != 3) ++bad;
        // the protection scroll rows
        if (rules::scrollProtRowCount() != 8) ++bad;
        static const int kPLo[8] = {
            61, 63, 65, 71, 77, 83, 88, 93,
        };
        static const int kPHi[8] = {
            62, 64, 70, 76, 82, 87, 92, 97,
        };
        static const int kPxp[8] = {
            2500, 2500, 1500, 1000, 1500, 2000, 2000, 1500,
        };
        for (int i = 0; i < 8; ++i)
            if (rules::scrollProtRowLo(i) != kPLo[i] ||
                rules::scrollProtRowHi(i) != kPHi[i] ||
                rules::scrollProtRowXp(i) != kPxp[i]) ++bad;
        if (rules::scrollProtRowLo(0) != 61 ||
            rules::scrollProtRowHi(7) != 97 ||
            rules::scrollProtRowXp(0) != 2500 ||
            rules::scrollProtRowXp(3) != 1000) ++bad;
        for (int i = 1; i < 8; ++i)
            if (rules::scrollProtRowLo(i) !=
                rules::scrollProtRowHi(i - 1) + 1) ++bad;
        // the curse sub-table rows
        if (rules::scrollCurseRowCount() != 8) ++bad;
        static const int kCLo[8] = {
            1, 26, 31, 41, 51, 76, 91, 100,
        };
        static const int kCHi[8] = {
            25, 30, 40, 50, 75, 90, 99, 100,
        };
        for (int i = 0; i < 8; ++i)
            if (rules::scrollCurseRowLo(i) != kCLo[i] ||
                rules::scrollCurseRowHi(i) != kCHi[i]) ++bad;
        for (int i = 1; i < 8; ++i)
            if (rules::scrollCurseRowLo(i) !=
                rules::scrollCurseRowHi(i - 1) + 1) ++bad;
        // row 00 is the 100 singleton
        if (rules::scrollCurseRowLo(7) != 100 ||
            rules::scrollCurseRowHi(7) != 100 ||
            rules::scrollCurseRowLo(-9) != 1 ||
            rules::scrollCurseRowHi(99) != 100) ++bad;
        // the prose constants
        if (rules::scrollSpellXpPerLevel() != 100 ||
            rules::scrollSpellSaleMultiplier() != 3 ||
            rules::scrollProtectionSaleMultiplier() != 5)
            ++bad;
        if (!rules::scrollDmMustConvinceRead() ||
            !rules::scrollUnreadMayFade() ||
            !rules::scrollCurseTakesEffectImmediately())
            ++bad;
        if (rules::scrollCurseDiseaseOnsetMin() != 2 ||
            rules::scrollCurseDiseaseOnsetMax() != 8 ||
            rules::scrollCurseTransportMinMiles() != 200 ||
            rules::scrollCurseTransportMaxMiles() != 1200 ||
            rules::scrollCurseTransportRadius() != 20 ||
            rules::scrollCurseRandomSpellLevel() != 12)
            ++bad;
        printf("R222 scrolls prose pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
