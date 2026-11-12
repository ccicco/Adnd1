    // ---- R222: the III.B scrolls prose pins audit ----
    // DMG pp.126-127: the spell-scroll
    // structure (with the illusionist
    // alternative ranges), the
    // protection scroll values, the
    // curse sub-table and the sale/
    // x.p. prose.
    {
        Scrollpins scrollpins;
        int bad = 0;
        // the spell-scroll rows
        if (scrollpins.scrollSpellRowCount() != 16) ++bad;
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
            if (scrollpins.scrollSpellRowLo(i) != kSLo[i] ||
                scrollpins.scrollSpellRowHi(i) != kSHi[i] ||
                scrollpins.scrollSpellRowN(i) != kN[i]) ++bad;
        for (int i = 0; i < 16; ++i)
            if (scrollpins.scrollSpellRowLvLo(i) != kLvLo[i] ||
                scrollpins.scrollSpellRowLvHi(i) != kLvHi[i] ||
                scrollpins.scrollSpellRowHasAlt(i) != kAlt[i] ||
                scrollpins.scrollSpellRowAltLvLo(i) != kALo[i] ||
                scrollpins.scrollSpellRowAltLvHi(i) != kAHi[i])
                ++bad;
        for (int i = 1; i < 16; ++i)
            if (scrollpins.scrollSpellRowLo(i) !=
                scrollpins.scrollSpellRowHi(i - 1) + 1) ++bad;
        if (scrollpins.scrollSpellRowLo(-5) != 1 ||
            scrollpins.scrollSpellRowHi(99) != 60) ++bad;
        // the alt rows are the 2, 4, 6, 8,
        // 10, 12 and 15 indices; alt lo =
        // main lo, alt hi < main hi
        if (scrollpins.scrollSpellAltRangeCount() != 7) ++bad;
        if (!scrollpins.scrollSpellRowHasAlt(2) ||
            !scrollpins.scrollSpellRowHasAlt(4) ||
            !scrollpins.scrollSpellRowHasAlt(6) ||
            !scrollpins.scrollSpellRowHasAlt(8) ||
            !scrollpins.scrollSpellRowHasAlt(10) ||
            !scrollpins.scrollSpellRowHasAlt(12) ||
            !scrollpins.scrollSpellRowHasAlt(15)) ++bad;
        if (scrollpins.scrollSpellRowHasAlt(0) ||
            scrollpins.scrollSpellRowHasAlt(13)) ++bad;
        if (scrollpins.scrollSpellRowAltLvLo(2) != 2 ||
            scrollpins.scrollSpellRowAltLvHi(2) != 7 ||
            scrollpins.scrollSpellRowAltLvHi(15) != 7 ||
            scrollpins.scrollSpellRowAltLvLo(12) != 3) ++bad;
        // the protection scroll rows
        if (scrollpins.scrollProtRowCount() != 8) ++bad;
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
            if (scrollpins.scrollProtRowLo(i) != kPLo[i] ||
                scrollpins.scrollProtRowHi(i) != kPHi[i] ||
                scrollpins.scrollProtRowXp(i) != kPxp[i]) ++bad;
        if (scrollpins.scrollProtRowLo(0) != 61 ||
            scrollpins.scrollProtRowHi(7) != 97 ||
            scrollpins.scrollProtRowXp(0) != 2500 ||
            scrollpins.scrollProtRowXp(3) != 1000) ++bad;
        for (int i = 1; i < 8; ++i)
            if (scrollpins.scrollProtRowLo(i) !=
                scrollpins.scrollProtRowHi(i - 1) + 1) ++bad;
        // the curse sub-table rows
        if (scrollpins.scrollCurseRowCount() != 8) ++bad;
        static const int kCLo[8] = {
            1, 26, 31, 41, 51, 76, 91, 100,
        };
        static const int kCHi[8] = {
            25, 30, 40, 50, 75, 90, 99, 100,
        };
        for (int i = 0; i < 8; ++i)
            if (scrollpins.scrollCurseRowLo(i) != kCLo[i] ||
                scrollpins.scrollCurseRowHi(i) != kCHi[i]) ++bad;
        for (int i = 1; i < 8; ++i)
            if (scrollpins.scrollCurseRowLo(i) !=
                scrollpins.scrollCurseRowHi(i - 1) + 1) ++bad;
        // row 00 is the 100 singleton
        if (scrollpins.scrollCurseRowLo(7) != 100 ||
            scrollpins.scrollCurseRowHi(7) != 100 ||
            scrollpins.scrollCurseRowLo(-9) != 1 ||
            scrollpins.scrollCurseRowHi(99) != 100) ++bad;
        // the prose constants
        if (scrollpins.scrollSpellXpPerLevel() != 100 ||
            scrollpins.scrollSpellSaleMultiplier() != 3 ||
            scrollpins.scrollProtectionSaleMultiplier() != 5)
            ++bad;
        if (!scrollpins.scrollDmMustConvinceRead() ||
            !scrollpins.scrollUnreadMayFade() ||
            !scrollpins.scrollCurseTakesEffectImmediately())
            ++bad;
        if (scrollpins.scrollCurseDiseaseOnsetMin() != 2 ||
            scrollpins.scrollCurseDiseaseOnsetMax() != 8 ||
            scrollpins.scrollCurseTransportMinMiles() != 200 ||
            scrollpins.scrollCurseTransportMaxMiles() != 1200 ||
            scrollpins.scrollCurseTransportRadius() != 20 ||
            scrollpins.scrollCurseRandomSpellLevel() != 12)
            ++bad;
        printf("R222 scrolls prose pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
