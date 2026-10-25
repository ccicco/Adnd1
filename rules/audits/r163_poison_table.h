    // ---- R163: the poison table audit -------------
    // DMG p.20: the purchased-poison table - ingestive
    // A-E and insinuative A-D, each with cost, onset
    // (and unit), the damage classes, the footnote save
    // bonuses and detection chances - plus the class
    // rules and the blade-venom decay.
    {
        int bad = 0;
        // the ingestive column: A-E
        static const int kInCost[5] = { 5, 30, 200, 500, 1000 };
        static const int kInSaveDmg[5] = { 10, 15, 20, 25, 30 };
        static const int kInNoSaveDmg[5] = { 20, 30, 40, -1, -1 };
        static const int kInOnMin[5] = { 2, 2, 1, 1, 1 };
        static const int kInOnMax[5] = { 8, 5, 2, 1, 4 };
        for (int g = 0; g < 5; ++g) {
            if (rules::poisonCostPerDose(
                    rules::POISON_INGESTIVE, g) != kInCost[g])
                ++bad;
            if (rules::poisonDamageIfSave(
                    rules::POISON_INGESTIVE, g) != kInSaveDmg[g])
                ++bad;
            int nsd = rules::poisonDamageIfNoSave(
                rules::POISON_INGESTIVE, g);
            if (kInNoSaveDmg[g] == -1) {
                if (!rules::poisonKillsIfNoSave(
                        rules::POISON_INGESTIVE, g) || nsd != -1)
                    ++bad;
            } else if (nsd != kInNoSaveDmg[g]) ++bad;
            if (rules::poisonOnsetMin(
                    rules::POISON_INGESTIVE, g) != kInOnMin[g] ||
                rules::poisonOnsetMax(
                    rules::POISON_INGESTIVE, g) != kInOnMax[g])
                ++bad;
            if (rules::poisonOnsetUnit(
                    rules::POISON_INGESTIVE, g)
                    != rules::POISON_UNIT_ROUND && g <= 2) ++bad;
        }
        // ingestive D reads segments, E turns
        if (rules::poisonOnsetUnit(
                rules::POISON_INGESTIVE, 3)
                != rules::POISON_UNIT_SEGMENT ||
            rules::poisonOnsetUnit(
                rules::POISON_INGESTIVE, 4)
                != rules::POISON_UNIT_TURN) ++bad;
        // the insinuative column: A-D
        static const int kInsCost[4] = { 10, 75, 600, 1500 };
        static const int kInsNoSaveDmg[4] = { 15, 25, 35, -1 };
        static const int kInsOnMin[4] = { 2, 1, 1, 1 };
        static const int kInsOnMax[4] = { 5, 3, 1, 1 };
        for (int g = 0; g < 4; ++g) {
            if (rules::poisonCostPerDose(
                    rules::POISON_INSINUATIVE, g) != kInsCost[g])
                ++bad;
            if (rules::poisonDamageIfSave(
                    rules::POISON_INSINUATIVE, g) != 0) ++bad;
            int nsd = rules::poisonDamageIfNoSave(
                rules::POISON_INSINUATIVE, g);
            if (kInsNoSaveDmg[g] == -1) {
                if (!rules::poisonKillsIfNoSave(
                        rules::POISON_INSINUATIVE, g) || nsd != -1)
                    ++bad;
            } else if (nsd != kInsNoSaveDmg[g]) ++bad;
            if (rules::poisonOnsetMin(
                    rules::POISON_INSINUATIVE, g) != kInsOnMin[g] ||
                rules::poisonOnsetMax(
                    rules::POISON_INSINUATIVE, g) != kInsOnMax[g])
                ++bad;
            if (rules::poisonOnsetUnit(
                    rules::POISON_INSINUATIVE, g)
                != rules::POISON_UNIT_ROUND) ++bad;
        }
        // grade E is ingestive only
        if (rules::poisonGradeExists(
                rules::POISON_INSINUATIVE, 4) ||
            !rules::poisonGradeExists(
                rules::POISON_INSINUATIVE, 3) ||
            !rules::poisonGradeExists(
                rules::POISON_INGESTIVE, 4) ||
            rules::poisonGradeExists(
                rules::POISON_INGESTIVE, 5) ||
            rules::poisonGradeExists(
                rules::POISON_INGESTIVE, -1)) ++bad;
        // the footnotes: +4/+3/+2/+1 save, E none;
        // detection 80/65/40/15, E none
        static const int kBonus[5] = { 4, 3, 2, 1, 0 };
        static const int kDetect[5] = { 80, 65, 40, 15, 0 };
        for (int g = 0; g < 5; ++g) {
            if (rules::poisonVictimSaveBonus(
                    rules::POISON_INGESTIVE, g) != kBonus[g])
                ++bad;
            if (rules::poisonDetectChance(
                    rules::POISON_INGESTIVE, g) != kDetect[g])
                ++bad;
        }
        for (int g = 0; g < 4; ++g) {
            if (rules::poisonVictimSaveBonus(
                    rules::POISON_INSINUATIVE, g) != kBonus[g])
                ++bad;
            if (rules::poisonDetectChance(
                    rules::POISON_INSINUATIVE, g) != kDetect[g])
                ++bad;
        }
        // the user efficiency ladder
        if (rules::poisonUserEfficiencyAdj(true, true) != 0 ||
            rules::poisonUserEfficiencyAdj(true, false) != 1 ||
            rules::poisonUserEfficiencyAdj(false, true) != 2 ||
            rules::poisonUserEfficiencyAdj(false, false) != 2)
            ++bad;
        // monster poison: all-or-nothing, dual-use
        if (!rules::poisonMonsterAllOrNothing() ||
            !rules::poisonMonsterDualUse()) ++bad;
        // blade venom decay: full, half, gone
        if (rules::poisonBladeVenomPotencyPercent(0) != 100 ||
            rules::poisonBladeVenomPotencyPercent(1) != 50 ||
            rules::poisonBladeVenomPotencyPercent(2) != 0 ||
            rules::poisonBladeVenomPotencyPercent(3) != 0 ||
            !rules::poisonBladeVenomDecayedGivesSaveBonus(1) ||
            rules::poisonBladeVenomDecayedGivesSaveBonus(0))
            ++bad;
        printf("R163 poison table audit: bad %d\n", bad);
        if (bad) return 1;
    }
