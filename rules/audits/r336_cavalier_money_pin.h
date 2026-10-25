    // ---- R336: the cavalier money pin audit ----
    // The UA Starting Money and Equipment for Cavaliers
    // (p. 25) - the six stations in social-ladder order,
    // the gold ranges, the printed dice formulas (the
    // times-ten convention verified against the printed
    // ranges and the R190 seam), the equipment lists
    // pinned item-by-item as printed (the UMC row prints
    // no shield or dagger), the tack and esquire prose;
    // the paladin exception noted but not detailed - a
    // documented hole pending the PDF. The R328/R190
    // seams cross-checked.
    {
        using namespace rules;
        int bad = 0;
        // U1: the stations
        {
            if (cavMoneyStationCount() != 6) ++bad;
            if (strcmp(cavMoneyStationName(0),
                "Lower Middle Class or less") != 0)
                ++bad;
            if (strcmp(cavMoneyStationName(2),
                "Upper Middle Class") != 0) ++bad;
            if (strcmp(cavMoneyStationName(5),
                "Upper Upper Class") != 0) ++bad;
            if (strcmp(cavMoneyStationEntry(0),
                "Horseman") != 0) ++bad;
            if (strcmp(cavMoneyStationEntry(2),
                "Horseman") != 0) ++bad;
            if (strcmp(cavMoneyStationEntry(3),
                "Cavalier") != 0) ++bad;
            if (strcmp(cavMoneyStationEntry(5),
                "Cavalier") != 0) ++bad;
        }
        // U2: the gold ranges and the
        // times-ten decode
        {
            static const int lo[6] = {
                20, 20, 20, 70, 70, 130
            };
            static const int hi[6] = {
                80, 80, 80, 180, 180, 180
            };
            for (int i = 0; i < 6; ++i) {
                if (cavMoneyGoldLow(i) != lo[i])
                    ++bad;
                if (cavMoneyGoldHigh(i) != hi[i])
                    ++bad;
            }
            // the printed formulas times ten
            // reproduce the printed ranges
            if (!cavMoneyGoldRollTimesTen())
                ++bad;
            if ((1 + cavMoneyDiceBonus(3)) * 10
                != cavMoneyGoldLow(3)) ++bad;
            if ((12 + cavMoneyDiceBonus(3)) * 10
                != cavMoneyGoldHigh(3)) ++bad;
            if ((1 + cavMoneyDiceBonus(5)) * 10
                != cavMoneyGoldLow(5)) ++bad;
            if ((6 + cavMoneyDiceBonus(5)) * 10
                != cavMoneyGoldHigh(5)) ++bad;
            // the formula rows
            if (cavMoneyDiceCount(3) != 1) ++bad;
            if (cavMoneyDiceFaces(3) != 12) ++bad;
            if (cavMoneyDiceFaces(4) != 6) ++bad;
            if (cavMoneyDiceBonus(4) != 6) ++bad;
            if (cavMoneyDiceBonus(5) != 12) ++bad;
            // the Horseman rows print no
            // formula - all three read 0
            for (int i = 0; i < 3; ++i) {
                if (cavMoneyDiceCount(i) != 0)
                    ++bad;
                if (cavMoneyDiceFaces(i) != 0)
                    ++bad;
                if (cavMoneyDiceBonus(i) != 0)
                    ++bad;
            }
        }
        // U3: the item counts
        {
            static const int k[6] = {3, 4, 4, 6, 6, 7};
            for (int i = 0; i < 6; ++i)
                if (cavMoneyItemCount(i) != k[i])
                    ++bad;
        }
        // U4: the item names (spot reads)
        {
            if (strcmp(cavMoneyItemName(0, 1),
                "sword (any type)") != 0) ++bad;
            if (strcmp(cavMoneyItemName(0, 2),
                "riding horse") != 0) ++bad;
            if (strcmp(cavMoneyItemName(1, 2),
                "sword (broad or long)") != 0)
                ++bad;
            if (strcmp(cavMoneyItemName(2, 0),
                "chain mail") != 0) ++bad;
            if (strcmp(cavMoneyItemName(3, 1),
                "plate mail") != 0) ++bad;
            if (strcmp(cavMoneyItemName(4, 1),
                "field plate armor") != 0) ++bad;
            if (strcmp(cavMoneyItemName(5, 1),
                "full plate armor") != 0) ++bad;
            if (strcmp(cavMoneyItemName(5, 4),
                "mace") != 0) ++bad;
            if (strcmp(cavMoneyItemName(5, 6),
                "heavy warhorse with leather"
                " barding") != 0) ++bad;
        }
        // U5: the armor ladder and the
        // shieldless UMC row
        {
            // chain mail UMC -> plate mail LUC
            // -> field plate MUC -> full plate UUC
            if (strcmp(cavMoneyItemName(2, 0),
                "chain mail") != 0) ++bad;
            if (strcmp(cavMoneyItemName(3, 1),
                "plate mail") != 0) ++bad;
            if (strcmp(cavMoneyItemName(4, 1),
                "field plate armor") != 0)
                ++bad;
            if (strcmp(cavMoneyItemName(5, 1),
                "full plate armor") != 0) ++bad;
            // the UMC row prints no shield
            bool shield = false;
            for (int j = 0; j < cavMoneyItemCount(2);
                 ++j)
                if (strcmp(cavMoneyItemName(2, j),
                    "shield") == 0) shield = true;
            if (shield) ++bad;
        }
        // U6: the horses
        {
            if (strcmp(cavMoneyItemName(0, 2),
                "riding horse") != 0) ++bad;
            if (strcmp(cavMoneyItemName(1, 3),
                "light warhorse") != 0) ++bad;
            if (strcmp(cavMoneyItemName(2, 3),
                "light warhorse") != 0) ++bad;
            if (strcmp(cavMoneyItemName(3, 5),
                "medium warhorse") != 0) ++bad;
            if (strcmp(cavMoneyItemName(4, 5),
                "heavy warhorse") != 0) ++bad;
            if (strcmp(cavMoneyItemName(5, 6),
                "heavy warhorse with leather"
                " barding") != 0) ++bad;
        }
        // U7: the prose pins
        {
            if (!cavMoneyHorsesCompleteWithTack())
                ++bad;
            if (!cavMoneyBelowUpperStartHorseman())
                ++bad;
            if (!cavMoneyBelowUpperEsquired())
                ++bad;
            if (!cavMoneyPaladinExceptionNoted())
                ++bad;
        }
        // U8: the seams - the R328 horseman
        // track and the R190 times-ten
        // convention
        {
            if (cavalierHorsemanXp() != -1500)
                ++bad;
            if (cavalierLancerXp() != -500) ++bad;
            if (startingMoneyMultiplier(0) != 10)
                ++bad;
        }
        printf("R336 cavalier money pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
