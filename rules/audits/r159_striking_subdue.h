    // ---- R159: striking to subdue audit ---------------
    // DMG p.67: the 75/25 accounting, applicability, the
    // knockout threshold; the MM dragon capture: the kind
    // table, the int gate, the percent ratio (the example
    // rounds), the automatic subdual, the sale price.
    {
        int bad = 0;
        // the 75/25 accounting
        if (rules::subdualTemporaryPct() != 75 ||
            rules::subdualRealPct() != 25) ++bad;
        if (rules::subdualRealDamage(40) != 10) ++bad;
        if (rules::subdualRealDamage(8) != 2 ||
            rules::subdualRealDamage(4) != 1 ||
            rules::subdualRealDamage(1) != 0 ||
            rules::subdualRealDamage(0) != 0 ||
            rules::subdualRealDamage(-5) != 0) ++bad;
        // applicability: MM-stated or humanoid, never PCs
        if (!rules::subdualEffectiveAgainst(true, false) ||
            rules::subdualEffectiveAgainst(false, false) ||
            rules::subdualEffectiveAgainst(true, true))
            ++bad;
        // the knockout threshold
        if (!rules::subdualKnockout(10, 10) ||
            !rules::subdualKnockout(11, 10) ||
            rules::subdualKnockout(9, 10) ||
            !rules::subdualKnockout(3, 0)) ++bad;
        // the dragon kind table
        if (!rules::dragonSubduable(rules::DRAGON_BRASS) ||
            !rules::dragonSubduable(rules::DRAGON_BRONZE) ||
            !rules::dragonSubduable(rules::DRAGON_COPPER) ||
            rules::dragonSubduable(rules::DRAGON_WHITE) ||
            rules::dragonSubduable(rules::DRAGON_BLACK) ||
            rules::dragonSubduable(rules::DRAGON_GREEN) ||
            rules::dragonSubduable(rules::DRAGON_BLUE) ||
            rules::dragonSubduable(rules::DRAGON_RED) ||
            rules::dragonSubduable(rules::DRAGON_SILVER) ||
            rules::dragonSubduable(rules::DRAGON_GOLD) ||
            rules::dragonSubduable(rules::DRAGON_PLATINUM))
            ++bad;
        // the attacker int gate (average = 9)
        if (rules::subduableByAttackerInt(8) ||
            !rules::subduableByAttackerInt(9) ||
            !rules::subduableByAttackerInt(12)) ++bad;
        // the announce-before-combat convention
        if (!rules::subdualFormIsKilling(false) ||
            rules::subdualFormIsKilling(true)) ++bad;
        // the percent ratio: the MM example rounds
        if (rules::dragonSubdualPercent(44, 88) != 50 ||
            rules::dragonSubdualPercent(67, 88) != 76 ||
            rules::dragonSubdualPercent(77, 88) != 88 ||
            rules::dragonSubdualPercent(0, 88) != 0 ||
            rules::dragonSubdualPercent(1, 8) != 13 ||
            rules::dragonSubdualPercent(88, 88) != 100 ||
            rules::dragonSubdualPercent(176, 88) != 200) ++bad;
        // percentile sweep + the automatic subdual
        {
            rules::Rng rngS(20261006);
            rules::Dice diceS(rngS);
            int hi = 0, loSeen = false, hiSeen = false;
            for (int t = 0; t < 600; ++t) {
                int roll = (int)diceS.roll(1, 100, 0);
                if (roll < 1 || roll > 100) ++bad;
                if (roll > hi) hi = roll;
            }
            // a 100% ratio: every roll subdues
            for (int t = 0; t < 50; ++t)
                if (!rules::dragonSubdued(diceS, 88, 88)) ++bad;
            // the MM example states: automatic at 1:1
            if (!rules::dragonSubdued(diceS, 88, 88)) ++bad;
            // a 0% ratio: only a rolled 1 edge (roll 1 <= 0
            // is false; nothing subdues)
            for (int t = 0; t < 50; ++t)
                if (rules::dragonSubdued(diceS, 0, 88)) ++bad;
            // price sweep: 100-800 gp per hit point
            for (int t = 0; t < 200; ++t) {
                int p = rules::subduedDragonPricePerHp(diceS);
                if (p < 100 || p > 800 || p % 100 != 0) ++bad;
            }
            (void)hi; (void)loSeen; (void)hiSeen;
        }
        if (!rules::subduedDragonRideable()) ++bad;
        printf("R159 striking to subdue audit: bad %d\n", bad);
        if (bad) return 1;
    }
