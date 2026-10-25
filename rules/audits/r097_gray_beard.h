    // ---- R97: gray beard audit ----
    {
        int bad = 0;
        // starting age bases: fighter youngest, MU latest
        if (startAgeBase(rules::CLASS_FIGHTER)    != 15) ++bad;
        if (startAgeBase(rules::CLASS_MAGIC_USER) != 24) ++bad;
        if (startAgeBase(rules::CLASS_CLERIC)     != 18) ++bad;
        if (startAgeBase(rules::CLASS_THIEF)      != 18) ++bad;
        // rolled bounds: fighter 16..19, MU 26..40
        {
            rules::Rng r{1};
            rules::Dice d(r);
            for (int i = 0; i < 200; ++i) {
                int f = rollStartingAge(rules::CLASS_FIGHTER, d);
                int m = rollStartingAge(rules::CLASS_MAGIC_USER, d);
                if (f < 16 || f > 19) ++bad;
                if (m < 26 || m > 40) ++bad;
            }
        }
        // the clock turns years only at whole 365s
        {
            Character c;
            c.startAge = 20;
            if (ageYears(c, 0)   != 20) ++bad;
            if (ageYears(c, 364) != 20) ++bad;
            if (ageYears(c, 365) != 21) ++bad;
            if (ageYears(c, 730) != 22) ++bad;
        }
        // an unknown youth (v1 save) stays 0 until the
        // clock grows years of its own
        {
            Character c;
            if (c.startAge != 0) ++bad;
            if (ageYears(c, 364) != 0) ++bad;
            if (ageYears(c, 365) != 1) ++bad;
        }
        printf("R97 gray beard audit: bad %d\n", bad);
        if (bad) return 1;
    }
