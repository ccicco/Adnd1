    // ---- R242: the III.G swords pins audit ----
    // DMG p.131: the magic swords table - the 26
    // rows, the three cursed no-sale rows, the
    // size note and the tiered bonuses.
    {
        Swords swords;
        int bad = 0;
        // the row identity: the 26 die bands
        if (swords.swRowCount() != 26) ++bad;
        static const int kLo[26] = {
            1, 26, 31, 36, 41, 46, 50, 51, 59,
            63, 67, 68, 72, 75, 77, 78, 79, 80,
            81, 82, 83, 84, 85, 86, 91, 96,
        };
        static const int kHi[26] = {
            25, 30, 35, 40, 45, 49, 50, 58, 62,
            66, 67, 71, 74, 76, 77, 78, 79, 80,
            81, 82, 83, 84, 85, 90, 95, 100,
        };
        static const int kXp[26] = {
            400, 600, 700, 800, 800, 900, 1000, 800, 900,
            900, 1600, 1400, 1600, 2000, 3000, 3000, 3600, 4000,
            4400, 4400, 5000, 7000, 10000, 400, 600, 900,
        };
        static const int kGp[26] = {
            2000, 3000, 3500, 4000, 4000, 4500, 5000, 4000, 4500,
            4500, 8000, 7000, 8000, 10000, 15000, 15000, 18000, 20000,
            22000, 22000, 25000, 35000, 50000, 0, 0, 0,
        };
        for (int i = 0; i < 26; ++i)
            if (swords.swRowLo(i) != kLo[i] ||
                swords.swRowHi(i) != kHi[i] ||
                swords.swXpValue(i) != kXp[i] ||
                swords.swSaleGp(i) != kGp[i])
                ++bad;
        for (int i = 1; i < 26; ++i)
            if (swords.swRowLo(i) !=
                swords.swRowHi(i - 1) + 1) ++bad;
        if (swords.swRowLo(-5) != 1 ||
            swords.swRowHi(99) != 100) ++bad;
        // the printed values: Sword +1, Luck
        // Blade, Nine Lives Stealer, Holy
        // Avenger and the Vorpal Weapon
        if (swords.swXpValue(0) != 400 ||
            swords.swSaleGp(0) != 2000) ++bad;
        if (swords.swXpValue(6) != 1000 ||
            swords.swSaleGp(6) != 5000) ++bad;
        if (swords.swXpValue(10) != 1600 ||
            swords.swSaleGp(10) != 8000) ++bad;
        if (swords.swXpValue(17) != 4000 ||
            swords.swSaleGp(17) != 20000) ++bad;
        if (swords.swXpValue(22) != 10000 ||
            swords.swSaleGp(22) != 50000) ++bad;
        // the THREE cursed swords print --- g.p.
        // sale values: +1 Cursed, -2 Cursed and
        // the Berserking (rows 23, 24, 25)
        if (swords.swXpValue(23) != 400 ||
            swords.swSaleGp(23) != 0 ||
            swords.swXpValue(24) != 600 ||
            swords.swSaleGp(24) != 0 ||
            swords.swXpValue(25) != 900 ||
            swords.swSaleGp(25) != 0 ||
            swords.swNoSaleCount() != 3) ++bad;
        // the Berserking rides the 96-00 band -
        // pinned as 96 through 100
        if (swords.swRowLo(25) != 96 ||
            swords.swRowHi(25) != 100) ++bad;
        // the sword SIZE note: 70/20/5/4/1 sums
        // to 100
        if (swords.swLongswordPct() != 70 ||
            swords.swBroadswordPct() != 20 ||
            swords.swShortswordPct() != 5 ||
            swords.swBastardPct() != 4 ||
            swords.swTwoHandedPct() != 1) ++bad;
        if (swords.swLongswordPct() +
            swords.swBroadswordPct() +
            swords.swShortswordPct() +
            swords.swBastardPct() +
            swords.swTwoHandedPct() != 100) ++bad;
        // the tiered bonuses: the Flame Tongue
        // ladder 2/3/4 and the Frost Brand +6
        if (swords.swFlameVsRegenBonus() != 2 ||
            swords.swFlameVsColdAvianBonus() != 3 ||
            swords.swFlameVsUndeadBonus() != 4 ||
            swords.swFrostVsFireBonus() != 6) ++bad;
        if (swords.swFlameVsRegenBonus() *
            swords.swFlameVsColdAvianBonus() -
            swords.swFlameVsRegenBonus() !=
            swords.swFlameVsUndeadBonus()) ++bad;
        // clamped reads land on Sword +1 below
        // and the Cursed Berserking above
        if (swords.swSaleGp(-99) != 2000 ||
            swords.swSaleGp(99) != 0 ||
            swords.swXpValue(-99) != 400 ||
            swords.swXpValue(99) != 900) ++bad;
        printf("R242 swords pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
