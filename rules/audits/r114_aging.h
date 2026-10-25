    // ---- R114: aging audit ----
    {
        int bad = 0;
        // the book's five human brackets (DMG p.13-14):
        // young adult <= 20, mature <= 40, middle aged
        // <= 60, old <= 90, venerable 91+
        if (ageBracket(20) != 0) ++bad;
        if (ageBracket(21) != 1) ++bad;
        if (ageBracket(40) != 1) ++bad;
        if (ageBracket(41) != 2) ++bad;
        if (ageBracket(60) != 2) ++bad;
        if (ageBracket(61) != 3) ++bad;
        if (ageBracket(90) != 3) ++bad;
        if (ageBracket(91) != 4) ++bad;
        // the book's per-bracket adjustments (DMG p.14)
        if (ageAbilityDelta(0, rules::ABILITY_STR) != 0)
            ++bad;
        if (ageAbilityDelta(1, rules::ABILITY_STR) != 1)
            ++bad;
        if (ageAbilityDelta(1, rules::ABILITY_WIS) != 1)
            ++bad;
        if (ageAbilityDelta(1, rules::ABILITY_CHA) != 0)
            ++bad;
        if (ageAbilityDelta(2, rules::ABILITY_STR) != -1)
            ++bad;
        if (ageAbilityDelta(2, rules::ABILITY_CON) != -1)
            ++bad;
        if (ageAbilityDelta(2, rules::ABILITY_INT) != 1)
            ++bad;
        if (ageAbilityDelta(2, rules::ABILITY_WIS) != 1)
            ++bad;
        if (ageAbilityDelta(3, rules::ABILITY_STR) != -2)
            ++bad;
        if (ageAbilityDelta(3, rules::ABILITY_DEX) != -2)
            ++bad;
        if (ageAbilityDelta(3, rules::ABILITY_CON) != -1)
            ++bad;
        if (ageAbilityDelta(3, rules::ABILITY_WIS) != 1)
            ++bad;
        if (ageAbilityDelta(4, rules::ABILITY_STR) != -1)
            ++bad;
        if (ageAbilityDelta(4, rules::ABILITY_DEX) != -1)
            ++bad;
        if (ageAbilityDelta(4, rules::ABILITY_CON) != -1)
            ++bad;
        if (ageAbilityDelta(4, rules::ABILITY_INT) != 1)
            ++bad;
        if (ageAbilityDelta(4, rules::ABILITY_WIS) != 1)
            ++bad;
        if (ageAbilityDelta(4, rules::ABILITY_CHA) != 0)
            ++bad;
        // CHA is never touched at any bracket
        if (ageAbilityDelta(0, rules::ABILITY_CHA) != 0)
            ++bad;
        for (int b = 1; b <= 4; ++b)
            if (ageAbilityDelta(b, rules::ABILITY_CHA) != 0)
                ++bad;
        // mature applies once and clamps at the ceiling
        {
            Character c;
            c.abilities.set(rules::ABILITY_STR, 18);
            c.abilities.set(rules::ABILITY_CON,  3);
            c.abilities.set(rules::ABILITY_INT, 17);
            c.abilities.set(rules::ABILITY_WIS, 10);
            c.abilities.set(rules::ABILITY_DEX,  9);
            c.abilities.set(rules::ABILITY_CHA, 10);
            applyAgeBracket(c, 1);   // mature
            if (c.abilities.get(rules::ABILITY_STR) != 18)
                ++bad;                // 18+1 clipped at ceiling
            if (c.abilities.get(rules::ABILITY_CON) != 3)
                ++bad;                // no CON bend at mature
            if (c.abilities.get(rules::ABILITY_INT) != 17)
                ++bad;
            if (c.abilities.get(rules::ABILITY_WIS) != 11)
                ++bad;
            if (c.abilities.get(rules::ABILITY_DEX) != 9)
                ++bad;
            if (c.abilities.get(rules::ABILITY_CHA) != 10)
                ++bad;                // untouched
        }
        // a full life: STR 17, CON 9, INT 17, WIS 16,
        // DEX 9 through the four bends (cumulative)
        {
            Character c;
            c.abilities.set(rules::ABILITY_STR, 17);
            c.abilities.set(rules::ABILITY_CON,  9);
            c.abilities.set(rules::ABILITY_INT, 17);
            c.abilities.set(rules::ABILITY_WIS, 16);
            c.abilities.set(rules::ABILITY_DEX,  9);
            c.abilities.set(rules::ABILITY_CHA, 10);
            applyAgeBracket(c, 1);
            applyAgeBracket(c, 2);
            applyAgeBracket(c, 3);
            applyAgeBracket(c, 4);
            // STR 17+1-1-2-1=14, CON 9-1-1-1=6,
            // INT 17+1+1=19 -> 18 (clipped; the book
            // would let WIS pass 18 - WIS 16+4=20
            // -> 18 too, documented), DEX 9-2-1=6
            if (c.abilities.get(rules::ABILITY_STR) != 14)
                ++bad;
            if (c.abilities.get(rules::ABILITY_CON) != 6)
                ++bad;
            if (c.abilities.get(rules::ABILITY_INT) != 18)
                ++bad;
            if (c.abilities.get(rules::ABILITY_WIS) != 18)
                ++bad;
            if (c.abilities.get(rules::ABILITY_DEX) != 6)
                ++bad;
            if (c.abilities.get(rules::ABILITY_CHA) != 10)
                ++bad;
        }
        printf("R114 aging audit: bad %d\n", bad);
        if (bad) return 1;
    }
