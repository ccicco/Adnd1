    // ---- R159: striking to subdue audit ---------------
    // DMG p.67: the 75/25 accounting, applicability, the
    // knockout threshold; the MM dragon capture: the kind
    // table, the int gate, the percent ratio (the example
    // rounds), the automatic subdual, the sale price.
    {
        Subdue subdue;
        int bad = 0;
        // the 75/25 accounting
        if (subdue.subdualTemporaryPct() != 75 ||
            subdue.subdualRealPct() != 25) ++bad;
        if (subdue.subdualRealDamage(40) != 10) ++bad;
        if (subdue.subdualRealDamage(8) != 2 ||
            subdue.subdualRealDamage(4) != 1 ||
            subdue.subdualRealDamage(1) != 0 ||
            subdue.subdualRealDamage(0) != 0 ||
            subdue.subdualRealDamage(-5) != 0) ++bad;
        // applicability: MM-stated or humanoid, never PCs
        if (!subdue.subdualEffectiveAgainst(true, false) ||
            subdue.subdualEffectiveAgainst(false, false) ||
            subdue.subdualEffectiveAgainst(true, true))
            ++bad;
        // the knockout threshold
        if (!subdue.subdualKnockout(10, 10) ||
            !subdue.subdualKnockout(11, 10) ||
            subdue.subdualKnockout(9, 10) ||
            !subdue.subdualKnockout(3, 0)) ++bad;
        // the dragon kind table
        if (!subdue.dragonSubduable(DRAGON_BRASS) ||
            !subdue.dragonSubduable(DRAGON_BRONZE) ||
            !subdue.dragonSubduable(DRAGON_COPPER) ||
            subdue.dragonSubduable(DRAGON_WHITE) ||
            subdue.dragonSubduable(DRAGON_BLACK) ||
            subdue.dragonSubduable(DRAGON_GREEN) ||
            subdue.dragonSubduable(DRAGON_BLUE) ||
            subdue.dragonSubduable(DRAGON_RED) ||
            subdue.dragonSubduable(DRAGON_SILVER) ||
            subdue.dragonSubduable(DRAGON_GOLD) ||
            subdue.dragonSubduable(DRAGON_PLATINUM))
            ++bad;
        // the attacker int gate (average = 9)
        if (subdue.subduableByAttackerInt(8) ||
            !subdue.subduableByAttackerInt(9) ||
            !subdue.subduableByAttackerInt(12)) ++bad;
        // the announce-before-combat convention
        if (!subdue.subdualFormIsKilling(false) ||
            subdue.subdualFormIsKilling(true)) ++bad;
        // the percent ratio: the MM example rounds
        if (subdue.dragonSubdualPercent(44, 88) != 50 ||
            subdue.dragonSubdualPercent(67, 88) != 76 ||
            subdue.dragonSubdualPercent(77, 88) != 88 ||
            subdue.dragonSubdualPercent(0, 88) != 0 ||
            subdue.dragonSubdualPercent(1, 8) != 13 ||
            subdue.dragonSubdualPercent(88, 88) != 100 ||
            subdue.dragonSubdualPercent(176, 88) != 200) ++bad;
        // percentile sweep + the automatic subdual
        {
            Subdue subdue;
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
                if (!subdue.dragonSubdued(diceS, 88, 88)) ++bad;
            // the MM example states: automatic at 1:1
            if (!subdue.dragonSubdued(diceS, 88, 88)) ++bad;
            // a 0% ratio: only a rolled 1 edge (roll 1 <= 0
            // is false; nothing subdues)
            for (int t = 0; t < 50; ++t)
                if (subdue.dragonSubdued(diceS, 0, 88)) ++bad;
            // price sweep: 100-800 gp per hit point
            for (int t = 0; t < 200; ++t) {
                Subdue subdue;
                int p = subdue.subduedDragonPricePerHp(diceS);
                if (p < 100 || p > 800 || p % 100 != 0) ++bad;
            }
            (void)hi; (void)loSeen; (void)hiSeen;
        }
        if (!subdue.subduedDragonRideable()) ++bad;
        printf("R159 striking to subdue audit: bad %d\n", bad);
        if (bad) return 1;
    }
