    // ---- R147: dwarf CON magic-save bonus audit ----
    // PHB p.16: dwarves add their constitution to saves
    // vs. wands/staves/rods, spells, and poison. The
    // formula con*2/7 clamped 0..5 matches every printed
    // band (4-6 +1, 7-10 +2, 11-13 +3, 14-17 +4, 18+ +5).
    {
        int bad = 0;
        static const int kPins[][2] = {
            { 3, 0 }, { 4, 1 }, { 6, 1 }, { 7, 2 },
            { 10, 2 }, { 11, 3 }, { 13, 3 }, { 14, 4 },
            { 17, 4 }, { 18, 5 }, { 21, 5 },
        };
        for (int i = 0; i < 11; ++i)
            if (rules::dwarfConSaveBonus(
                    (uint8_t)kPins[i][0]) != kPins[i][1]) ++bad;
        int prev = -1;
        for (int c = 1; c <= 30; ++c) {
            int b = rules::dwarfConSaveBonus((uint8_t)c);
            if (b < 0 || b > 5) ++bad;
            if (b < prev) ++bad;
            prev = b;
        }
        printf("R147 dwarf CON save bonus audit: bad %d\n", bad);
        if (bad) return 1;
    }
