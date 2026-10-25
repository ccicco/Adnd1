    // ---- R624 OA shukenja audit ----
    // OA round eleven (capture pp. 42-45): the shukenja - the Wisdom minima
    // and bonus, the training and ki, the ethos rules, and the advancement,
    // Wisdom and spell grids
    {
        using namespace rules;
        int bad = 0;
    if (dgkShukenjaMinWis() != 12
            || dgkShukenjaMinStr() != 9
            || dgkShukenjaMinCon() != 9
            || dgkShukenjaBonusStat() != 15
            || dgkShukenjaBonusPct() != 10
            || dgkShukenjaHitDie() != 6
            || dgkShukenjaSlots() != 6
            || dgkShukenjaWeaponSlots() != 2
            || dgkShukenjaCursePctPerLevel() != 5
            || dgkShukenjaSanctifyRadius() != 5
            || dgkShukenjaSanctifyArea() != 75
            || dgkShukenjaSanctifyBonus() != 1
            || dgkShukenjaMeditationDiv() != 2
            || dgkShukenjaKiSaveBonus() != 3
            || dgkShukenjaKiPerDayMult() != 1
            || dgkShukenjaDefeatedXpDiv() != 2
            || dgkShukenjaHealXpPerSpellLevel() != 100
            || dgkT26RowCount() != 12
            || dgkT26XpBeyond() != 250000
            || dgkT26HpBeyond() != 1
            || dgkT27RowCount() != 10
            || dgkT27FirstScore() != 9
            || dgkT27BonusNone() != 0
            || dgkT27BonusFirst() != 1
            || dgkT27BonusSecond() != 2
            || dgkT27BonusThird() != 3
            || dgkT27BonusFourth() != 4
            || dgkT27Spell6WisMin() != 17
            || dgkT27Spell7WisMin() != 18
            || dgkT28RowCount() != 29
            || dgkT28SpellLevels() != 7
            || dgkT28MaxCastable() != 9
            || !dgkShukenjaGoodOnly()
            || !dgkShukenjaOutsideCaste()
            || !dgkShukenjaClericTables()
            || !dgkShukenjaStuddedLeatherCap()
            || !dgkShukenjaReligionSlot()
            || !dgkShukenjaCalligraphySlot()
            || !dgkShukenjaRitualTraining()
            || !dgkShukenjaSanctifyWhilePresent()
            || !dgkShukenjaSanctifyNoStack()
            || !dgkShukenjaMeditationAware()
            || !dgkShukenjaFreeStyle()
            || !dgkShukenjaKiBeforeDieRolled()
            || !dgkShukenjaEvilSpiritFullXp()
            || !dgkShukenjaDonatedTreasureXp()
            || !dgkShukenjaNoMeat()
            || !dgkShukenjaRulePunishments()
            || !dgkShukenjaNoFamily()
            || !dgkShukenjaHonorLight()
            || !dgkShukenjaNoOrganizedChurch()
        )
            ++bad;
        // the Table 26 grid: the xp bounds and the accumulated dice plus
        // bonus (capture p. 42)
        int CT26[12][3] = {
            {1250,1,0},
            {3000,2,0},
            {5500,3,0},
            {11000,4,0},
            {22000,5,0},
            {44000,6,0},
            {90000,7,0},
            {150000,8,0},
            {300000,9,0},
            {600000,9,1},
            {900000,9,2},
            {1200000,9,3},
            };
        int nT26[3] = {0,0,0};
        int eT26[3] = {0,0,0};
        for (int b = 0;
             b < dgkT26RowCount();
             ++b) {
            int vals[3];
            vals[0] = dgkT26XpMax(b);
            vals[1] = dgkT26Dice(b);
            vals[2] = dgkT26HpBonus(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT26[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT26[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nT26[c] != eT26[c])
                ++bad;
        // the Table 27 grid: the spell-bonus codes and the failure ladder
        // (capture p. 43)
        int CT27[10][2] = {
            {0,20},
            {0,15},
            {0,10},
            {0,5},
            {1,0},
            {1,0},
            {2,0},
            {2,0},
            {3,0},
            {4,0},
            };
        int nT27[2] = {0,0};
        int eT27[2] = {0,0};
        for (int b = 0;
             b < dgkT27RowCount();
             ++b) {
            int vals[2];
            vals[0] = dgkT27Bonus(b);
            vals[1] = dgkT27Failure(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CT27[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT27[c];
            }
        }
        for (int c = 0; c < 2; ++c)
            if (nT27[c] != eT27[c])
                ++bad;
        // the Table 28 grid: the seven spell-level columns, levels 1-29
        // (capture pp. 43-44)
        int CT28[29][7] = {
            {1,0,0,0,0,0,0},
            {2,0,0,0,0,0,0},
            {3,0,0,0,0,0,0},
            {3,1,0,0,0,0,0},
            {3,2,0,0,0,0,0},
            {4,2,1,0,0,0,0},
            {4,3,2,0,0,0,0},
            {4,3,2,1,0,0,0},
            {5,3,2,2,0,0,0},
            {5,4,2,2,1,0,0},
            {5,4,3,2,2,0,0},
            {6,4,3,3,2,0,0},
            {6,5,4,3,2,0,0},
            {6,5,4,3,2,1,0},
            {7,5,4,3,2,2,0},
            {7,6,5,3,2,2,0},
            {7,6,5,4,3,2,0},
            {7,6,5,4,3,3,1},
            {8,6,5,4,4,3,1},
            {8,7,6,4,4,3,2},
            {8,7,6,5,4,4,2},
            {9,7,6,5,5,4,2},
            {9,8,7,5,5,4,3},
            {9,8,7,6,5,5,3},
            {9,9,7,6,6,5,3},
            {9,9,8,7,6,5,4},
            {9,9,8,7,7,6,4},
            {9,9,9,8,7,6,4},
            {9,9,9,9,8,7,5},
            };
        int nT28[7] = {0,0,0,0,0,0,0};
        int eT28[7] = {0,0,0,0,0,0,0};
        for (int b = 0;
             b < dgkT28RowCount();
             ++b) {
            int vals[7];
            vals[0] = dgkT28S1(b);
            vals[1] = dgkT28S2(b);
            vals[2] = dgkT28S3(b);
            vals[3] = dgkT28S4(b);
            vals[4] = dgkT28S5(b);
            vals[5] = dgkT28S6(b);
            vals[6] = dgkT28S7(b);
            for (int c = 0; c < 7;
                 ++c) {
                if (vals[c] != CT28[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT28[c];
            }
        }
        for (int c = 0; c < 7; ++c)
            if (nT28[c] != eT28[c])
                ++bad;
        // the dgkShukenjaMinWis pin
    if (dgkShukenjaMinWis() != 12
        )
            ++bad;
        // the dgkShukenjaMinStr pin
    if (dgkShukenjaMinStr() != 9
        )
            ++bad;
        // the dgkShukenjaMinCon pin
    if (dgkShukenjaMinCon() != 9
        )
            ++bad;
        // the dgkShukenjaBonusStat pin
    if (dgkShukenjaBonusStat() != 15
        )
            ++bad;
        // the dgkShukenjaBonusPct pin
    if (dgkShukenjaBonusPct() != 10
        )
            ++bad;
        // the dgkShukenjaHitDie pin
    if (dgkShukenjaHitDie() != 6
        )
            ++bad;
        // the dgkShukenjaSlots pin
    if (dgkShukenjaSlots() != 6
        )
            ++bad;
        // the dgkShukenjaWeaponSlots pin
    if (dgkShukenjaWeaponSlots() != 2
        )
            ++bad;
        // the dgkShukenjaCursePctPerLevel pin
    if (dgkShukenjaCursePctPerLevel() != 5
        )
            ++bad;
        // the dgkShukenjaSanctifyRadius pin
    if (dgkShukenjaSanctifyRadius() != 5
        )
            ++bad;
        // the dgkShukenjaSanctifyArea pin
    if (dgkShukenjaSanctifyArea() != 75
        )
            ++bad;
        // the dgkShukenjaSanctifyBonus pin
    if (dgkShukenjaSanctifyBonus() != 1
        )
            ++bad;
        // the dgkShukenjaMeditationDiv pin
    if (dgkShukenjaMeditationDiv() != 2
        )
            ++bad;
        // the dgkShukenjaKiSaveBonus pin
    if (dgkShukenjaKiSaveBonus() != 3
        )
            ++bad;
        // the dgkShukenjaKiPerDayMult pin
    if (dgkShukenjaKiPerDayMult() != 1
        )
            ++bad;
        // the dgkShukenjaDefeatedXpDiv pin
    if (dgkShukenjaDefeatedXpDiv() != 2
        )
            ++bad;
        // the dgkShukenjaHealXpPerSpellLevel pin
    if (dgkShukenjaHealXpPerSpellLevel() != 100
        )
            ++bad;
        // the dgkT26RowCount pin
    if (dgkT26RowCount() != 12
        )
            ++bad;
        // the dgkT26XpBeyond pin
    if (dgkT26XpBeyond() != 250000
        )
            ++bad;
        // the dgkT26HpBeyond pin
    if (dgkT26HpBeyond() != 1
        )
            ++bad;
        // the dgkT27RowCount pin
    if (dgkT27RowCount() != 10
        )
            ++bad;
        // the dgkT27FirstScore pin
    if (dgkT27FirstScore() != 9
        )
            ++bad;
        // the dgkT27BonusNone pin
    if (dgkT27BonusNone() != 0
        )
            ++bad;
        // the dgkT27BonusFirst pin
    if (dgkT27BonusFirst() != 1
        )
            ++bad;
        // the dgkT27BonusSecond pin
    if (dgkT27BonusSecond() != 2
        )
            ++bad;
        // the dgkT27BonusThird pin
    if (dgkT27BonusThird() != 3
        )
            ++bad;
        // the dgkT27BonusFourth pin
    if (dgkT27BonusFourth() != 4
        )
            ++bad;
        // the dgkT27Spell6WisMin pin
    if (dgkT27Spell6WisMin() != 17
        )
            ++bad;
        // the dgkT27Spell7WisMin pin
    if (dgkT27Spell7WisMin() != 18
        )
            ++bad;
        // the dgkT28RowCount pin
    if (dgkT28RowCount() != 29
        )
            ++bad;
        // the dgkT28SpellLevels pin
    if (dgkT28SpellLevels() != 7
        )
            ++bad;
        // the dgkT28MaxCastable pin
    if (dgkT28MaxCastable() != 9
        )
            ++bad;
        // the dgkShukenjaGoodOnly pin
    if (dgkShukenjaGoodOnly() != 1
        )
            ++bad;
        // the dgkShukenjaOutsideCaste pin
    if (dgkShukenjaOutsideCaste() != 1
        )
            ++bad;
        // the dgkShukenjaClericTables pin
    if (dgkShukenjaClericTables() != 1
        )
            ++bad;
        // the dgkShukenjaStuddedLeatherCap pin
    if (dgkShukenjaStuddedLeatherCap() != 1
        )
            ++bad;
        // the dgkShukenjaReligionSlot pin
    if (dgkShukenjaReligionSlot() != 1
        )
            ++bad;
        // the dgkShukenjaCalligraphySlot pin
    if (dgkShukenjaCalligraphySlot() != 1
        )
            ++bad;
        // the dgkShukenjaRitualTraining pin
    if (dgkShukenjaRitualTraining() != 1
        )
            ++bad;
        // the dgkShukenjaSanctifyWhilePresent pin
    if (dgkShukenjaSanctifyWhilePresent() != 1
        )
            ++bad;
        // the dgkShukenjaSanctifyNoStack pin
    if (dgkShukenjaSanctifyNoStack() != 1
        )
            ++bad;
        // the dgkShukenjaMeditationAware pin
    if (dgkShukenjaMeditationAware() != 1
        )
            ++bad;
        // the dgkShukenjaFreeStyle pin
    if (dgkShukenjaFreeStyle() != 1
        )
            ++bad;
        // the dgkShukenjaKiBeforeDieRolled pin
    if (dgkShukenjaKiBeforeDieRolled() != 1
        )
            ++bad;
        // the dgkShukenjaEvilSpiritFullXp pin
    if (dgkShukenjaEvilSpiritFullXp() != 1
        )
            ++bad;
        // the dgkShukenjaDonatedTreasureXp pin
    if (dgkShukenjaDonatedTreasureXp() != 1
        )
            ++bad;
        // the dgkShukenjaNoMeat pin
    if (dgkShukenjaNoMeat() != 1
        )
            ++bad;
        // the dgkShukenjaRulePunishments pin
    if (dgkShukenjaRulePunishments() != 1
        )
            ++bad;
        // the dgkShukenjaNoFamily pin
    if (dgkShukenjaNoFamily() != 1
        )
            ++bad;
        // the dgkShukenjaHonorLight pin
    if (dgkShukenjaHonorLight() != 1
        )
            ++bad;
        // the dgkShukenjaNoOrganizedChurch pin
    if (dgkShukenjaNoOrganizedChurch() != 1
        )
            ++bad;
        // the T26 first row - 1,250 xp, one die (settled against the 2018
        // print; capture p. 42)
    if (dgkT26XpMax(0) != 1250
            || dgkT26Dice(0) != 1
            || dgkT26HpBonus(0) != 0
        )
            ++bad;
        // the T26 capstone - 1,200,000 xp, nine dice plus three (settled;
        // capture p. 42)
    if (dgkT26XpMax(11) != 1200000
            || dgkT26Dice(11) != 9
            || dgkT26HpBonus(11) != 3
        )
            ++bad;
        // the T26 9-plus-N cells open on the 10th-level row (capture p. 42)
    if (dgkT26Dice(9) != 9
            || dgkT26HpBonus(9) != 1
        )
            ++bad;
        // the T27 failure ladder - 20 at Wis 9 down to 0 at 13 (capture p.
        // 43)
    if (dgkT27Failure(0) != 20
            || dgkT27Failure(3) != 5
            || dgkT27Failure(4) != 0
        )
            ++bad;
        // the T27 bonus tiers - none through 12, the 1st at 13, the 4th at 18
        // (capture p. 43)
    if (dgkT27Bonus(3) != 0
            || dgkT27Bonus(4) != 1
            || dgkT27Bonus(9) != 4
        )
            ++bad;
        // the T27 spell minima - Wis 17 for the 6th, 18 for the 7th (capture
        // p. 43)
    if (dgkT27Spell6WisMin() != 17
            || dgkT27Spell7WisMin() != 18
        )
            ++bad;
        // the T28 1st-level row - one 1st-level spell only (capture p. 43)
    if (dgkT28S1(0) != 1
            || dgkT28S2(0) != 0
            || dgkT28S7(0) != 0
        )
            ++bad;
        // the T28 capstone - the 29th-level row (capture p. 44)
    if (dgkT28S1(28) != 9
            || dgkT28S4(28) != 9
            || dgkT28S5(28) != 8
            || dgkT28S6(28) != 7
            || dgkT28S7(28) != 5
        )
            ++bad;
        // the T28 openings - the 2nd at 4th, the 3rd at 6th, the 7th at 18th
        // (capture pp. 43-44)
    if (dgkT28S2(3) != 1
            || dgkT28S3(5) != 1
            || dgkT28S7(17) != 1
        )
            ++bad;
        // the purification ladder - 5 percent per level, the 75-square-foot
        // circle (capture p. 44)
    if (dgkShukenjaCursePctPerLevel() != 5
            || dgkShukenjaSanctifyArea() != 75
        )
            ++bad;
        // the Wisdom-15 example - two bonus 1st and one bonus 2nd
        // cumulatively, the 2nd usable from 4th level (capture p. 43)
    if (dgkT27Bonus(6) != 2
            || dgkT28S2(3) != 1
        )
            ++bad;
        // the meditation and ki ladders - the 2-to-1 rest, the +3 save
        // (capture pp. 44-45)
    if (dgkShukenjaMeditationDiv() != 2
            || dgkShukenjaKiSaveBonus() != 3
        )
            ++bad;
        printf("R624 OA shukenja audit: bad %d\n", bad);
        if (bad) return 1;
    }
