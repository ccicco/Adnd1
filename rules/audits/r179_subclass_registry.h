    // ---- R179: the subclass registry audit -------
    // The six pinned subclass defs from the printed
    // PHB class tables: the XP attain rows cell by
    // cell, the title ladders, the caps, the hit
    // dice, the two-dice first levels (ranger,
    // monk), the adders, the base-class map, and
    // the clamps (the R176 attain convention).
    {
        int bad = 0;
        if (rules::subclassCount() != 6) ++bad;
        // the base-class map: paladin fighter,
        // ranger fighter, druid cleric,
        // illusionist MU, assassin thief, monk none
        static const int kBase[6] = { 0, 0, 2, 1, 3, -1 };
        static const int kCap[6]  = { 9, 10, 14, 10, 10, 17 };
        static const int kHpB[6]  = { 3, 2, 2, 1, 2, 0 };
        static const int kDie[6]  = { 10, 8, 8, 4, 6, 4 };
        static const int kTwo[6]  = { 0, 1, 0, 0, 0, 1 };
        static const int kRows[6] = { 11, 12, 14, 12, 15, 17 };
        static const int kAdder[6] = { 350000, 325000, 0,
                                     220000, 0, 0 };
        static const int kXpPal[11] = {
            0, 2750, 5500, 12000, 24000,
            45000, 95000, 175000, 350000, 700000, 1050000
        };
        static const int kXpRng[12] = {
            0, 2250, 4500, 10000, 20000,
            40000, 90000, 150000, 225000, 325000,
            650000, 975000
        };
        static const int kXpDru[14] = {
            0, 2000, 4000, 7500, 12500,
            20000, 35000, 60000, 90000, 125000,
            200000, 300000, 750000, 1500000
        };
        static const int kXpIll[12] = {
            0, 2250, 4500, 9000, 18000,
            35000, 60000, 95000, 145000, 220000,
            440000, 660000
        };
        static const int kXpAsn[15] = {
            0, 1500, 3000, 6000, 12000,
            25000, 50000, 100000, 200000, 300000,
            425000, 575000, 750000, 1000000, 1500000
        };
        static const int kXpMnk[17] = {
            0, 2250, 4750, 10000, 22500,
            47500, 98000, 200000, 350000, 500000,
            700000, 950000, 1250000, 1750000,
            2250000, 2750000, 3250000
        };
        for (int i = 0; i < 6; ++i) {
            const rules::SubclassDef& d =
                rules::subclassDef(i);
            if (d.base != kBase[i]) ++bad;
            if (d.levelCap != kCap[i]) ++bad;
            if (d.hpBeyondCap != kHpB[i]) ++bad;
            if (d.hitDie != kDie[i]) ++bad;
            if (d.twoDiceFirstLevel != kTwo[i]) ++bad;
            if (d.xpRowCount != kRows[i]) ++bad;
            if (d.xpAdder != kAdder[i]) ++bad;
            if (d.titleCount != d.xpRowCount) ++bad;
        }
        for (int l = 1; l <= 11; ++l)
            if (rules::subclassXpFor(0, l) != kXpPal[l-1]) ++bad;
        for (int l = 1; l <= 12; ++l)
            if (rules::subclassXpFor(1, l) != kXpRng[l-1]) ++bad;
        for (int l = 1; l <= 14; ++l)
            if (rules::subclassXpFor(2, l) != kXpDru[l-1]) ++bad;
        for (int l = 1; l <= 12; ++l)
            if (rules::subclassXpFor(3, l) != kXpIll[l-1]) ++bad;
        for (int l = 1; l <= 15; ++l)
            if (rules::subclassXpFor(4, l) != kXpAsn[l-1]) ++bad;
        for (int l = 1; l <= 17; ++l)
            if (rules::subclassXpFor(5, l) != kXpMnk[l-1]) ++bad;
        // the adder probes: paladin, ranger,
        // illusionist; the ceiling rows repeat for
        // the adder-0 defs
        if (rules::subclassXpFor(0, 12) != 1400000 ||
            rules::subclassXpFor(0, 13) != 1750000) ++bad;
        if (rules::subclassXpFor(1, 13) != 1300000 ||
            rules::subclassXpFor(1, 14) != 1625000) ++bad;
        if (rules::subclassXpFor(3, 13) != 880000 ||
            rules::subclassXpFor(3, 14) != 1100000) ++bad;
        if (rules::subclassXpFor(2, 15) != 1500000 ||
            rules::subclassXpFor(4, 16) != 1500000 ||
            rules::subclassXpFor(5, 18) != 3250000) ++bad;
        // title spot rows and clamps
        if (std::string(rules::subclassTitle(0, 9))
            != "Paladin") ++bad;
        if (std::string(rules::subclassTitle(1, 8))
            != "Ranger") ++bad;
        if (std::string(rules::subclassTitle(2, 14))
            != "The Great Druid") ++bad;
        if (std::string(rules::subclassTitle(3, 10))
            != "Illusionist") ++bad;
        if (std::string(rules::subclassTitle(4, 15))
            != "Grandfather of Assassins") ++bad;
        if (std::string(rules::subclassTitle(5, 17))
            != "Grand Master of Flowers") ++bad;
        if (std::string(rules::subclassTitle(5, 1))
            != "Novice") ++bad;
        if (std::string(rules::subclassTitle(0, 0))
            != "Gallant") ++bad;
        if (std::string(rules::subclassTitle(0, 99))
            != "Paladin (11th level)") ++bad;
        if (rules::subclassXpFor(0, 0) != 0 ||
            rules::subclassXpFor(5, -3) != 0) ++bad;
        printf("R179 subclass registry audit: bad %d\n", bad);
        if (bad) return 1;
    }
