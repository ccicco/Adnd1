    // ---- R193: the charisma table audit ----
    // The printed CHARISMA TABLE, all three columns,
    // all 16 scores - the reaction percent ladder,
    // the henchmen column, the loyalty percents.
    {
        int bad = 0;
        // the reaction adjustment: the printed percent
        // ladder (-25 at 3 through +35 at 18)
        static const int kReact[16] = {
            -25, -20, -15, -10, -5,
              0,   0,   0,   0,   0,
              5,  10,  15,  25,  30,  35
        };
        static const int kHench[16] = {
             1,  1,  2,  2,  3,  3,  4,  4,
             4,  5,  5,  6,  7,  8, 10, 15
        };
        static const int kLoyal[16] = {
            -30, -25, -20, -15, -10, -5,
             0,   0,   0,   0,   0,
             5,  15,  20,  30,  40
        };
        for (int c = 3; c <= 18; ++c) {
            if (rules::chaReactionAdj((uint8_t)c)
                != kReact[c - 3]) ++bad;
            if (rules::chaHenchmenMax((uint8_t)c)
                != kHench[c - 3]) ++bad;
            if (rules::chaLoyaltyBase((uint8_t)c)
                != kLoyal[c - 3]) ++bad;
        }
        // the cha 18 tail cells
        if (rules::chaReactionAdj(18) != 35) ++bad;
        if (rules::chaHenchmenMax(18) != 15) ++bad;
        if (rules::chaLoyaltyBase(18) != 40) ++bad;
        // the two historically divergent henchmen cells:
        // cha 4 reads 1, cha 12 reads 5 (the R177 founding read)
        if (rules::chaHenchmenMax(4) != 1) ++bad;
        if (rules::chaHenchmenMax(12) != 5) ++bad;
        // the clamps read the edge rows
        if (rules::chaReactionAdj(0) != -25) ++bad;
        if (rules::chaReactionAdj(99) != 35) ++bad;
        if (rules::chaHenchmenMax(0) != 1) ++bad;
        if (rules::chaHenchmenMax(99) != 15) ++bad;
        if (rules::chaLoyaltyBase(0) != -30) ++bad;
        if (rules::chaLoyaltyBase(99) != 40) ++bad;
        // the reaction bands consume the percent scale:
        // a cha-18 leader adds +35 to the d100 reaction
        // roll, a cha-3 leader -25
        if (rules::chaReactionAdj(18) + 50 != 85) ++bad;
        if (rules::chaReactionAdj(3) + 50 != 25) ++bad;
        printf("R193 charisma table audit: bad %d\n", bad);
        if (bad) return 1;
    }
