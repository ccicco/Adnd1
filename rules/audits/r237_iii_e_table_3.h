    // ---- R237: the III.E table 3 pins audit ----
    // DMG p.129: the class marks and the
    // asterisk ladder of TABLE (III.E.) 3.
    {
        int bad = 0;
        // the row identity: the 33 die bands
        if (rules::m3RowCount() != 33) ++bad;
        static const int kLo[33] = {
            1, 16, 17, 19, 21, 23, 26, 27, 28, 29,
            30, 31, 36, 38, 40, 41, 46, 47, 49, 50,
            54, 61, 64, 66, 71, 72, 73, 79, 81, 86,
            91, 92, 93,
        };
        static const int kHi[33] = {
            15, 16, 18, 20, 22, 25, 26, 27, 28, 29,
            30, 35, 37, 39, 40, 45, 46, 48, 49, 53,
            60, 63, 65, 70, 71, 72, 78, 80, 85, 90,
            91, 92, 100,
        };
        static const int kC[33] = {
            0, 0, 0, 0, 1, 1, 0, 0, 1, 1,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            0, 0, 0, 1, 1, 0, 0, 0, 0, 0,
            0, 0, 0,
        };
        static const int kF[33] = {
            0, 0, 0, 0, 1, 1, 0, 0, 1, 1,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
            0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
            0, 0, 0,
        };
        static const int kT[33] = {
            0, 0, 0, 0, 1, 1, 0, 0, 1, 1,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0,
        };
        static const int kStar[33] = {
            1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            2, 0, 0, 0, 0, 3, 4, 0, 0, 0,
            0, 0, 0,
        };
        static const int kFacet[33] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 1, 0,
        };
        for (int i = 0; i < 33; ++i)
            if (rules::m3RowLo(i) != kLo[i] ||
                rules::m3RowHi(i) != kHi[i] ||
                rules::m3UsableByCleric(i) != kC[i] ||
                rules::m3UsableByFighter(i) != kF[i] ||
                rules::m3UsableByThief(i) != kT[i] ||
                rules::m3StarCount(i) != kStar[i] ||
                rules::m3IsPerFacetValued(i) != kFacet[i])
                ++bad;
        for (int i = 1; i < 33; ++i)
            if (rules::m3RowLo(i) !=
                rules::m3RowHi(i - 1) + 1) ++bad;
        if (rules::m3RowLo(-5) != 1 ||
            rules::m3RowHi(99) != 100) ++bad;
        // the class marks: the two Gauntlets and
        // two Girdles are (C, F, T); the Horn of
        // the Tritons is (C, F); the Incenses are
        // (C); the Javelins are (F); NO (M) rows
        // ride this table
        if (rules::m3ClericCount() != 7 ||
            rules::m3FighterCount() != 7 ||
            rules::m3ThiefCount() != 4) ++bad;
        if (!rules::m3UsableByCleric(4) ||
            !rules::m3UsableByFighter(4) ||
            !rules::m3UsableByThief(4)) ++bad;
        if (rules::m3UsableByCleric(3) ||
            rules::m3UsableByFighter(3) ||
            rules::m3UsableByThief(3)) ++bad;
        if (!rules::m3UsableByCleric(19) ||
            !rules::m3UsableByFighter(19) ||
            rules::m3UsableByThief(19)) ++bad;
        if (!rules::m3UsableByCleric(23) ||
            rules::m3UsableByFighter(23)) ++bad;
        if (!rules::m3UsableByFighter(28) ||
            !rules::m3UsableByFighter(29) ||
            rules::m3UsableByCleric(28)) ++bad;
        // the asterisk ladder: the Figurine
        // 01-15 (1 star, per hit die), the Horn
        // of Valhalla 54-60 (2 stars, double
        // bronze / triple iron), the Ioun Stones
        // 72 (3 stars, per stone), the
        // Instrument of the Bards 73-78 (4
        // stars, per level of instrument for
        // bards - the footnote the book upload
        // drops, restored from the compilation)
        if (rules::m3StarCount(0) != 1 ||
            rules::m3StarCount(20) != 2 ||
            rules::m3StarCount(25) != 3 ||
            rules::m3StarCount(26) != 4 ||
            rules::m3StarCount(1) != 0) ++bad;
        // a 4-hit-die figurine is 400 x.p. /
        // 4,000 g.p.
        if (rules::m3FigurinePerHitDieXp() != 100 ||
            rules::m3FigurinePerHitDieGp() != 1000 ||
            rules::m3FigurinePerHitDieXp() * 4 != 400 ||
            rules::m3FigurinePerHitDieGp() * 4 != 4000)
            ++bad;
        // the bronze horn doubles (2,000 /
        // 30,000), the iron horn triples
        // (3,000 / 45,000)
        if (rules::m3ValhallaBaseXp() != 1000 ||
            rules::m3ValhallaBaseGp() != 15000 ||
            rules::m3ValhallaBronzeMult() != 2 ||
            rules::m3ValhallaIronMult() != 3 ||
            rules::m3ValhallaBaseXp() *
            rules::m3ValhallaBronzeMult() != 2000 ||
            rules::m3ValhallaBaseGp() *
            rules::m3ValhallaBronzeMult() != 30000 ||
            rules::m3ValhallaBaseXp() *
            rules::m3ValhallaIronMult() != 3000 ||
            rules::m3ValhallaBaseGp() *
            rules::m3ValhallaIronMult() != 45000)
            ++bad;
        // per stone: five stones are 1,500 x.p.
        if (rules::m3IounPerStoneXp() != 300 ||
            rules::m3IounPerStoneGp() != 5000 ||
            rules::m3IounPerStoneXp() * 5 != 1500)
            ++bad;
        // the bardic instruments ride the
        // college ladder: the 3rd-college Doss
        // instrument is 3,000 x.p. / 15,000 g.p.
        if (rules::m3InstrumentBaseXp() != 1000 ||
            rules::m3InstrumentBaseGp() != 5000 ||
            rules::m3InstrumentBaseXp() * 3 != 3000 ||
            rules::m3InstrumentBaseGp() * 3 != 15000)
            ++bad;
        // the Jewel of Flawlessness 92: no x.p.,
        // 1,000 g.p. per facet
        if (!rules::m3IsPerFacetValued(31) ||
            rules::m3IsPerFacetValued(30) ||
            rules::m3JewelPerFacetGp() != 1000 ||
            rules::m3JewelPerFacetGp() * 3 != 3000)
            ++bad;
        // clamped reads land on the Figurine
        // (1 star) below and the unmarked
        // 93-00 Ointment above
        if (rules::m3StarCount(-99) != 1 ||
            rules::m3UsableByCleric(99) ||
            rules::m3IsPerFacetValued(99)) ++bad;
        printf("R237 misc table 3 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
