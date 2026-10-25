    // ---- R192: the wisdom tables audit ----
    // Wisdom Tables I and II cell for cell, the
    // gates, the wiring composites, a seeded roll.
    {
        int bad = 0;
        // Wisdom Table I: the magical attack ladder
        static const int kAdj[16] = {
            -3, -2, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0,
             1,  2,  3,  4
        };
        for (int w = 3; w <= 18; ++w) {
            if (rules::wisMagicalAttackAdj((uint8_t)w)
                != kAdj[w - 3]) ++bad;
        }
        // the clamps read the edge rows
        if (rules::wisMagicalAttackAdj(0) != -3) ++bad;
        if (rules::wisMagicalAttackAdj(99) != 4) ++bad;
        // the Table I high-circle gates
        if (rules::wisSpellLevelMin(6) != 17) ++bad;
        if (rules::wisSpellLevelMin(7) != 18) ++bad;
        if (rules::wisSpellLevelMin(5) != 0) ++bad;
        if (rules::wisSpellLevelMin(1) != 0) ++bad;
        // Wisdom Table II: the bonus ladder (rows 9-18,
        // spell levels 1-4)
        static const int kBon[10][4] = {
            { 0, 0, 0, 0 },   // 9
            { 0, 0, 0, 0 },   // 10
            { 0, 0, 0, 0 },   // 11
            { 0, 0, 0, 0 },   // 12
            { 1, 0, 0, 0 },   // 13
            { 2, 0, 0, 0 },   // 14
            { 2, 1, 0, 0 },   // 15
            { 2, 2, 0, 0 },   // 16
            { 2, 2, 1, 0 },   // 17
            { 2, 2, 1, 1 }    // 18
        };
        for (int w = 9; w <= 18; ++w) {
            for (int sl = 1; sl <= 4; ++sl) {
                if (rules::wisBonusSpells((uint8_t)w, sl)
                    != kBon[w - 9][sl - 1]) ++bad;
            }
        }
        // out-of-range spell levels read 0; wis clamps
        if (rules::wisBonusSpells(18, 5) != 0) ++bad;
        if (rules::wisBonusSpells(18, 0) != 0) ++bad;
        if (rules::wisBonusSpells(8, 1) != 0) ++bad;
        if (rules::wisBonusSpells(25, 1) != 2) ++bad;
        // the failure ladder
        static const int kFail[10] = {
            20, 15, 10, 5, 0, 0, 0, 0, 0, 0
        };
        for (int w = 9; w <= 18; ++w) {
            if (rules::wisSpellFailurePct((uint8_t)w)
                != kFail[w - 9]) ++bad;
        }
        if (rules::wisSpellFailurePct(3) != 20) ++bad;
        if (rules::wisSpellFailurePct(25) != 0) ++bad;
        // the wiring: cleric slots with wisdom
        // (L1 base 1 + wis-13 bonus 1 = 2)
        if (spells::clericSpellSlotsWithWis(1, 1, 13) != 2) ++bad;
        // wis 9: no bonus, no failure escape
        if (spells::clericSpellSlotsWithWis(1, 1, 9) != 1) ++bad;
        // L3 2nd base 1 + wis-15 bonus 1 = 2
        if (spells::clericSpellSlotsWithWis(3, 2, 15) != 2) ++bad;
        // L2 2nd base 0: the bonus is NOT granted (the
        // printed entitlement note)
        if (spells::clericSpellSlotsWithWis(2, 2, 18) != 0) ++bad;
        // L12 1st base 6 + wis-18 bonus 2 = 8
        if (spells::clericSpellSlotsWithWis(12, 1, 18) != 8) ++bad;
        // the high-circle gates: L11 6th is 1 in the
        // table, but wis 16 fails the Wis-17 gate
        if (spells::clericSpellSlotsWithWis(11, 6, 16) != 0) ++bad;
        if (spells::clericSpellSlotsWithWis(11, 6, 17) != 1) ++bad;
        // L16 7th is 1 in the table (the printed ** row),
        // wis 17 fails the Wis-18 gate, wis 18 reads it
        if (spells::clericSpellSlotsWithWis(16, 7, 17) != 0) ++bad;
        if (spells::clericSpellSlotsWithWis(16, 7, 18) != 1) ++bad;
        // the failure roll, seeded: equal-or-less fails
        {
            rules::Rng r192(2026);
            rules::Dice d(r192);
            int first = (int)d.d100();
            rules::Rng r192b(2026);
            rules::Dice db(r192b);
            bool failed = spells::rollClericSpellFailure(db, 12);
            if (failed != (first <= 5)) ++bad;
            // wis 13+: pct 0, never fails, no roll
            rules::Rng r192c(2026);
            rules::Dice dc(r192c);
            if (spells::rollClericSpellFailure(dc, 13)) ++bad;
        }
        printf("R192 wisdom tables audit: bad %d\n", bad);
        if (bad) return 1;
    }
