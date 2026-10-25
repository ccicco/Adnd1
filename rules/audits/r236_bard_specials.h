    // ---- R236: the bard specials audit ----
    // The poetics seam (the R236 helpers), the
    // Table II lore and charm percents, the
    // language ladder, and the Table I dice.
    {
        int bad = 0;
        // the poetics seam: the +1 ferocity, the
        // 2 rounds required, the round and alive gates
        if (rules::bardPoeticsHitBonus() != 1) ++bad;
        if (rules::bardPoeticsRoundsRequired() != 2) ++bad;
        if (rules::bardPoeticsActive(0, 1) != 0) ++bad;
        if (rules::bardPoeticsActive(1, 1) != 0) ++bad;
        if (rules::bardPoeticsActive(2, 1) != 0) ++bad;
        if (rules::bardPoeticsActive(3, 1) != 1) ++bad;
        if (rules::bardPoeticsActive(9, 1) != 1) ++bad;
        if (rules::bardPoeticsActive(9, 0) != 0) ++bad;
        if (rules::bardPoeticsActive(1, 2) != 0) ++bad;
        // Table II legend lore (the 14th-level 55
        // IS as printed - the R186 pin)
        if (rules::bardLegendLorePercent(0) != 0) ++bad;
        if (rules::bardLegendLorePercent(1) != 0) ++bad;
        if (rules::bardLegendLorePercent(5) != 13) ++bad;
        if (rules::bardLegendLorePercent(13) != 56) ++bad;
        if (rules::bardLegendLorePercent(14) != 55) ++bad;
        if (rules::bardLegendLorePercent(23) != 99) ++bad;
        if (rules::bardLegendLorePercent(99) != 99) ++bad;
        // Table II charm (a miss at 0th - the clamp)
        if (rules::bardCharmPercent(1) != 15) ++bad;
        if (rules::bardCharmPercent(5) != 30) ++bad;
        if (rules::bardCharmPercent(14) != 60) ++bad;
        if (rules::bardCharmPercent(23) != 95) ++bad;
        // the language ladder (a new tongue at the
        // printed levels, none at 1st-3rd)
        if (rules::bardLanguages(1) != 0) ++bad;
        if (rules::bardLanguages(3) != 0) ++bad;
        if (rules::bardLanguages(4) != 1) ++bad;
        if (rules::bardLanguages(23) != 1) ++bad;
        // the Table I dice (d6 through 11, then +1)
        if (rules::bardHitDice(1) != 0) ++bad;
        if (rules::bardHitDice(11) != 10) ++bad;
        if (rules::bardHitDice(12) != 11) ++bad;
        if (rules::bardHitDice(23) != 22) ++bad;
        printf("R236 bard specials audit: bad %d\n", bad);
        if (bad) return 1;
    }
