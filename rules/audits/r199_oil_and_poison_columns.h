    // ---- R199: the oil and poison columns audit ----
    // The CHARACTER CLASSES TABLE II oil and poison
    // columns, cell for cell - the three-valued
    // allowance encoding: 1 yes, 0 never, -1 referee.
    {
        int bad = 0;
        // the encoding
        if (rules::classAllowanceYes() != 1) ++bad;
        if (rules::classAllowanceNever() != 0) ++bad;
        if (rules::classAllowanceReferee() != -1) ++bad;
        // the Oil column: yes for every class but the monk
        static const int kOil[10] = {
             1,  1,  1,  1,  1,  1,  1,  1,  1,  0
        };
        for (int c = 0; c < 10; ++c) {
            if (rules::classOilUse(c) != kOil[c]) ++bad;
        }
        // the Poison column: cleric and paladin never,
        // assassin yes, the rest the question mark
        static const int kPoison[10] = {
             0, -1, -1,  0, -1, -1, -1, -1,  1, -1
        };
        for (int c = 0; c < 10; ++c) {
            if (rules::classPoisonUse(c) != kPoison[c]) ++bad;
        }
        // the cleric footnote: the prohibition is strictly
        // for clerics not of evil alignment - an evil cleric
        // reads the referee discretion
        if (rules::classPoisonUseForAlignment(0, false) != 0) ++bad;
        if (rules::classPoisonUseForAlignment(0, true) != -1) ++bad;
        // the paladin never is unconditional - no footnote
        if (rules::classPoisonUseForAlignment(3, true) != 0) ++bad;
        if (rules::classPoisonUseForAlignment(3, false) != 0) ++bad;
        // the other rows pass through untouched
        if (rules::classPoisonUseForAlignment(8, false) != 1) ++bad;
        if (rules::classPoisonUseForAlignment(9, true) != -1) ++bad;
        printf("R199 oil and poison columns audit: bad %d\n", bad);
        if (bad) return 1;
    }
