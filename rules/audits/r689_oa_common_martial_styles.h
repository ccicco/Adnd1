    // ---- R689 OA common martial styles audit ----
    // OA round seventy-six (capture pp. 224-225): Table 68 - the common
    // martial styles grid, the four styles across six columns with the
    // explanatory prose, single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (djcOA68StyleCount() != 4
            || !djcOA68AttacksStyleDependent()
            || !djcOA68DamageDefensiveLow()
            || !djcOA68ACFromTraining()
            || !djcOA68PrincipalBodyPartFree()
            || !djcOA68ManeuversSecrets()
        )
            ++bad;
        // the Table 68 grid - the four common styles across six columns
        int COA68Data[4][6] = {
            {3,1,6,8,1,6},
            {2,1,6,6,1,8},
            {1,1,8,8,2,6},
            {2,1,6,7,1,11},
            };
        for (int b = 0;
             b < djcOA68StyleCount();
             ++b) {
            int vals[6];
            vals[0] = djcOA68AtkNum(b);
            vals[1] = djcOA68AtkDen(b);
            vals[2] = djcOA68DmgDie(b);
            vals[3] = djcOA68AC(b);
            vals[4] = djcOA68Principal(b);
            vals[5] = djcOA68ManeuverRanks(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != COA68Data[b][c])
                    ++bad;
            }
        }
        // the attack rates - the 3/1, 2/1, 1/1 and 2/1 of the four styles
    if (djcOA68AtkNum(0) != 3
            || djcOA68AtkNum(1) != 2
            || djcOA68AtkNum(2) != 1
            || djcOA68AtkNum(3) != 2
        )
            ++bad;
        // the damage column - the d6, d6, d8 and d6
    if (djcOA68DmgDie(0) != 6
            || djcOA68DmgDie(1) != 6
            || djcOA68DmgDie(2) != 8
            || djcOA68DmgDie(3) != 6
        )
            ++bad;
        // the armor classes - the 8, 6, 8 and 7 with Kung-fu the best
    if (djcOA68AC(0) != 8
            || djcOA68AC(1) != 6
            || djcOA68AC(2) != 8
            || djcOA68AC(3) != 7
        )
            ++bad;
        // the principal forms - Hand, Hand, Foot, Hand with Tae Kwon Do the
        // only Foot
    if (djcOA68Principal(0) != 1
            || djcOA68Principal(2) != 2
            || djcOA68Principal(3) != 1
        )
            ++bad;
        // the maneuver rank counts - the 6, 8, 6 and 11 with Jujutsu the
        // richest
    if (djcOA68ManeuverRanks(0) != 6
            || djcOA68ManeuverRanks(1) != 8
            || djcOA68ManeuverRanks(2) != 6
            || djcOA68ManeuverRanks(3) != 11
        )
            ++bad;
        // the Kung-fu shape - the 2/1 rate with the best AC 6 and the
        // second-rank maneuver load
    if (djcOA68AtkNum(1) != djcOA68AtkDen(1) * 2
            || djcOA68ManeuverRanks(1) != djcOA68ManeuverRanks(0) + 2
        )
            ++bad;
        printf("R689 OA common martial styles audit: bad %d\n", bad);
        if (bad) return 1;
    }
