    // ---- R163: the poison table audit -------------
    // DMG p.20: the purchased-poison table - ingestive
    // A-E and insinuative A-D, each with cost, onset
    // (and unit), the damage classes, the footnote save
    // bonuses and detection chances - plus the class
    // rules and the blade-venom decay.
    {
        Poison poison;
        int bad = 0;
        // the ingestive column: A-E
        static const int kInCost[5] = { 5, 30, 200, 500, 1000 };
        static const int kInSaveDmg[5] = { 10, 15, 20, 25, 30 };
        static const int kInNoSaveDmg[5] = { 20, 30, 40, -1, -1 };
        static const int kInOnMin[5] = { 2, 2, 1, 1, 1 };
        static const int kInOnMax[5] = { 8, 5, 2, 1, 4 };
        for (int g = 0; g < 5; ++g) {
            Poison poison;
            if (poison.costPerDose(
                    POISON_INGESTIVE, g) != kInCost[g])
                ++bad;
            if (poison.damageIfSave(
                    POISON_INGESTIVE, g) != kInSaveDmg[g])
                ++bad;
            int nsd = poison.damageIfNoSave(
                POISON_INGESTIVE, g);
            if (kInNoSaveDmg[g] == -1) {
                Poison poison;
                if (!poison.killsIfNoSave(
                        POISON_INGESTIVE, g) || nsd != -1)
                    ++bad;
            } else if (nsd != kInNoSaveDmg[g]) ++bad;
            if (poison.onsetMin(
                    POISON_INGESTIVE, g) != kInOnMin[g] ||
                poison.onsetMax(
                    POISON_INGESTIVE, g) != kInOnMax[g])
                ++bad;
            if (poison.onsetUnit(
                    POISON_INGESTIVE, g)
                    != POISON_UNIT_ROUND && g <= 2) ++bad;
        }
        // ingestive D reads segments, E turns
        if (poison.onsetUnit(
                POISON_INGESTIVE, 3)
                != POISON_UNIT_SEGMENT ||
            poison.onsetUnit(
                POISON_INGESTIVE, 4)
                != POISON_UNIT_TURN) ++bad;
        // the insinuative column: A-D
        static const int kInsCost[4] = { 10, 75, 600, 1500 };
        static const int kInsNoSaveDmg[4] = { 15, 25, 35, -1 };
        static const int kInsOnMin[4] = { 2, 1, 1, 1 };
        static const int kInsOnMax[4] = { 5, 3, 1, 1 };
        for (int g = 0; g < 4; ++g) {
            Poison poison;
            if (poison.costPerDose(
                    POISON_INSINUATIVE, g) != kInsCost[g])
                ++bad;
            if (poison.damageIfSave(
                    POISON_INSINUATIVE, g) != 0) ++bad;
            int nsd = poison.damageIfNoSave(
                POISON_INSINUATIVE, g);
            if (kInsNoSaveDmg[g] == -1) {
                Poison poison;
                if (!poison.killsIfNoSave(
                        POISON_INSINUATIVE, g) || nsd != -1)
                    ++bad;
            } else if (nsd != kInsNoSaveDmg[g]) ++bad;
            if (poison.onsetMin(
                    POISON_INSINUATIVE, g) != kInsOnMin[g] ||
                poison.onsetMax(
                    POISON_INSINUATIVE, g) != kInsOnMax[g])
                ++bad;
            if (poison.onsetUnit(
                    POISON_INSINUATIVE, g)
                != POISON_UNIT_ROUND) ++bad;
        }
        // grade E is ingestive only
        if (poison.gradeExists(
                POISON_INSINUATIVE, 4) ||
            !poison.gradeExists(
                POISON_INSINUATIVE, 3) ||
            !poison.gradeExists(
                POISON_INGESTIVE, 4) ||
            poison.gradeExists(
                POISON_INGESTIVE, 5) ||
            poison.gradeExists(
                POISON_INGESTIVE, -1)) ++bad;
        // the footnotes: +4/+3/+2/+1 save, E none;
        // detection 80/65/40/15, E none
        static const int kBonus[5] = { 4, 3, 2, 1, 0 };
        static const int kDetect[5] = { 80, 65, 40, 15, 0 };
        for (int g = 0; g < 5; ++g) {
            Poison poison;
            if (poison.victimSaveBonus(
                    POISON_INGESTIVE, g) != kBonus[g])
                ++bad;
            if (poison.detectChance(
                    POISON_INGESTIVE, g) != kDetect[g])
                ++bad;
        }
        for (int g = 0; g < 4; ++g) {
            Poison poison;
            if (poison.victimSaveBonus(
                    POISON_INSINUATIVE, g) != kBonus[g])
                ++bad;
            if (poison.detectChance(
                    POISON_INSINUATIVE, g) != kDetect[g])
                ++bad;
        }
        // the user efficiency ladder
        if (poison.userEfficiencyAdj(true, true) != 0 ||
            poison.userEfficiencyAdj(true, false) != 1 ||
            poison.userEfficiencyAdj(false, true) != 2 ||
            poison.userEfficiencyAdj(false, false) != 2)
            ++bad;
        // monster poison: all-or-nothing, dual-use
        if (!poison.monsterAllOrNothing() ||
            !poison.monsterDualUse()) ++bad;
        // blade venom decay: full, half, gone
        if (poison.bladeVenomPotencyPercent(0) != 100 ||
            poison.bladeVenomPotencyPercent(1) != 50 ||
            poison.bladeVenomPotencyPercent(2) != 0 ||
            poison.bladeVenomPotencyPercent(3) != 0 ||
            !poison.bladeVenomDecayedGivesSaveBonus(1) ||
            poison.bladeVenomDecayedGivesSaveBonus(0))
            ++bad;
        printf("R163 poison table audit: bad %d\n", bad);
        if (bad) return 1;
    }
