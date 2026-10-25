    // ---- R201: the NPC monk alignment split audit ----
    // The monk prose: NPC monks align 50% lawful good,
    // 35% lawful neutral, 15% lawful evil - the split sums
    // to 100 and the d100 bands tile the die.
    {
        int bad = 0;
        // the three percents
        if (rules::monkNpcAlignLawfulGoodPercent() != 50) ++bad;
        if (rules::monkNpcAlignLawfulNeutralPercent() != 35) ++bad;
        if (rules::monkNpcAlignLawfulEvilPercent() != 15) ++bad;
        // the census sums to 100
        int sum = rules::monkNpcAlignLawfulGoodPercent()
                  + rules::monkNpcAlignLawfulNeutralPercent()
                  + rules::monkNpcAlignLawfulEvilPercent();
        if (sum != 100) ++bad;
        // the d100 bands: contiguous, in order, cover the die
        static const int kLo[3]  = { 1, 51, 86 };
        static const int kHi[3]  = { 50, 85, 100 };
        for (int i = 0; i < 3; ++i) {
            int lo, hi;
            rules::monkNpcAlignRollRange(i, lo, hi);
            if (lo != kLo[i]) ++bad;
            if (hi != kHi[i]) ++bad;
        }
        // the contiguity: each band starts at the prior plus one
        for (int i = 1; i < 3; ++i) {
            int lo, hi, plo, phi;
            rules::monkNpcAlignRollRange(i, lo, hi);
            rules::monkNpcAlignRollRange(i - 1, plo, phi);
            if (lo != phi + 1) ++bad;
            if (lo > hi) ++bad;
        }
        // the bands match the percents: LG 50 wide, LN 35, LE 15
        int lo, hi;
        rules::monkNpcAlignRollRange(0, lo, hi);
        if (hi - lo + 1
            != rules::monkNpcAlignLawfulGoodPercent()) ++bad;
        rules::monkNpcAlignRollRange(1, lo, hi);
        if (hi - lo + 1
            != rules::monkNpcAlignLawfulNeutralPercent()) ++bad;
        rules::monkNpcAlignRollRange(2, lo, hi);
        if (hi - lo + 1
            != rules::monkNpcAlignLawfulEvilPercent()) ++bad;
        // the out-of-range miss band
        rules::monkNpcAlignRollRange(3, lo, hi);
        if (lo != 0 || hi != 100) ++bad;
        printf("R201 NPC monk alignment audit: bad %d\n", bad);
        if (bad) return 1;
    }
