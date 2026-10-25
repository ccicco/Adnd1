    // ---- R115: magic aging audit ----
    {
        int bad = 0;
        // the book's table (DMG p.14): haste costs its
        // recipient 1 year; the caster-aged causes await
        // their spells
        if (spells::magicalAgingYears(spells::MU_HASTE) != 1)
            ++bad;
        if (spells::magicalAgingYears(spells::MU_FIREBALL) != 0)
            ++bad;
        if (spells::magicalAgingYears(spells::CL_HEAL) != 0)
            ++bad;
        if (spells::magicalAgingYears(spells::MU_TELEPORT) != 0)
            ++bad;
        // the stolen years ride the age clock: 20 -> 21
        // crosses into mature (+1 STR, +1 WIS)
        {
            Character c;
            c.startAge = 20;
            c.abilities.set(rules::ABILITY_STR, 10);
            c.abilities.set(rules::ABILITY_WIS, 10);
            c.abilities.set(rules::ABILITY_CON, 10);
            if (ageYears(c, 0) != 20) ++bad;
            applyMagicalAging(c, 0, 1);
            if (c.magicAgeYears != 1) ++bad;
            if (ageYears(c, 0) != 21) ++bad;
            if (ageYears(c, 3650) != 31) ++bad;  // +10 career
            if (c.abilities.get(rules::ABILITY_STR) != 11)
                ++bad;
            if (c.abilities.get(rules::ABILITY_WIS) != 11)
                ++bad;
            if (c.abilities.get(rules::ABILITY_CON) != 10)
                ++bad;    // no CON bend at mature
        }
        // zero years is a no-op
        {
            Character c;
            c.startAge = 30;
            applyMagicalAging(c, 0, 0);
            if (c.magicAgeYears != 0) ++bad;
            if (ageYears(c, 0) != 30) ++bad;
        }
        // one crossing: 39 -> 44 enters middle aged
        {
            Character c;
            c.startAge = 39;
            c.abilities.set(rules::ABILITY_STR, 15);
            c.abilities.set(rules::ABILITY_CON, 15);
            c.abilities.set(rules::ABILITY_INT, 10);
            c.abilities.set(rules::ABILITY_WIS, 10);
            applyMagicalAging(c, 364, 5);   // 39 -> 44
            if (c.magicAgeYears != 5) ++bad;
            if (ageYears(c, 364) != 44) ++bad;
            if (c.abilities.get(rules::ABILITY_STR) != 14)
                ++bad;
            if (c.abilities.get(rules::ABILITY_CON) != 14)
                ++bad;
            if (c.abilities.get(rules::ABILITY_INT) != 11)
                ++bad;
            if (c.abilities.get(rules::ABILITY_WIS) != 11)
                ++bad;
        }
        // two crossings at once: 39 -> 61 enters old,
        // middle aged's bend then old's, progressively
        {
            Character c;
            c.startAge = 39;
            c.abilities.set(rules::ABILITY_STR, 15);
            c.abilities.set(rules::ABILITY_CON, 15);
            c.abilities.set(rules::ABILITY_INT, 10);
            c.abilities.set(rules::ABILITY_WIS, 10);
            c.abilities.set(rules::ABILITY_DEX, 15);
            applyMagicalAging(c, 0, 22);   // 39 -> 61
            // STR 15-1-2=12, CON 15-1-1=13, INT 10+1=11,
            // WIS 10+1+1=12, DEX 15-2=13
            if (ageYears(c, 0) != 61) ++bad;
            if (c.abilities.get(rules::ABILITY_STR) != 12)
                ++bad;
            if (c.abilities.get(rules::ABILITY_CON) != 13)
                ++bad;
            if (c.abilities.get(rules::ABILITY_INT) != 11)
                ++bad;
            if (c.abilities.get(rules::ABILITY_WIS) != 12)
                ++bad;
            if (c.abilities.get(rules::ABILITY_DEX) != 13)
                ++bad;
        }
        printf("R115 magic aging audit: bad %d\n", bad);
        if (bad) return 1;
    }
