    // ---- R627 OA yakuza audit ----
    // OA round fourteen (capture pp. 51-54): the yakuza - the minima, the
    // investigate tiers, the ki power and the brethren
    {
        using namespace rules;
        int bad = 0;
    if (dgnYakuzaMinStr() != 11
            || dgnYakuzaMinInt() != 15
            || dgnYakuzaMinDex() != 15
            || dgnYakuzaMinCha() != 16
            || dgnYakuzaHitDie() != 6
            || dgnYakuzaSlots() != 3
            || dgnYakuzaFamilyBirthMod() != -5
            || dgnYakuzaStipendPerLevel() != 2
            || dgnYakuzaContactLevelDiv() != 2
            || dgnYakuzaContactMaxAbove() != 4
            || dgnYakuzaKiDamageDiv() != 2
            || dgnYakuzaKiPerRound() != 1
            || dgnYakuzaKiPerDayPerLevel() != 1
            || dgnYakuzaReactionBonusPct() != 10
            || dgnYakuzaInfoCommonDays() != 1
            || dgnYakuzaInfoCommonCostCount() != 2
            || dgnYakuzaInfoCommonCostDice() != 6
            || dgnYakuzaInfoUncommonDaysMin() != 1
            || dgnYakuzaInfoUncommonDaysMax() != 3
            || dgnYakuzaInfoUncommonCostDice() != 4
            || dgnYakuzaInfoUncommonInacc() != 10
            || dgnYakuzaInfoConfDaysMin() != 2
            || dgnYakuzaInfoConfDaysMax() != 12
            || dgnYakuzaInfoConfCostDice() != 10
            || dgnYakuzaInfoConfInacc() != 25
            || dgnYakuzaInfoSecretDaysMin() != 3
            || dgnYakuzaInfoSecretDaysMax() != 18
            || dgnYakuzaInfoSecretCostDice() != 10
            || dgnYakuzaInfoSecretInacc() != 40
            || dgnYakuzaBrethrenMinLevel() != 2
            || dgnYakuzaBrethrenPerLevel() != 1
            || dgnYakuzaBrethrenMaxLevel() != 8
            || dgnT34RowCount() != 12
            || dgnYakuzaXpBeyond12th() != 300000
            || dgnYakuzaHpPerLevelBeyond9() != 1
            || dgnT35RowCount() != 21
            || !dgnYakuzaAlwaysLawful()
            || !dgnYakuzaNoPrimeReq()
            || !dgnYakuzaThiefTables()
            || !dgnYakuzaAnyWeapon()
            || !dgnYakuzaArmorFromTable13()
            || !dgnYakuzaNoShields()
            || !dgnYakuzaFamilyClanRequired()
            || !dgnYakuzaFreeGamingProf()
            || !dgnYakuzaThiefSkillsAtNinja()
            || !dgnYakuzaHearNoiseAsMonk()
            || !dgnYakuzaInfoNeverMagical()
            || !dgnYakuzaInfoNeverLegendary()
            || !dgnYakuzaInfoCommonAlwaysAccurate()
            || !dgnYakuzaKiHalvesRoundUp()
            || !dgnYakuzaReactionExcludesStatus()
            || !dgnYakuzaAdoptedNoRolls()
            || !dgnYakuzaEnterpriseNeedsOyabun()
            || !dgnYakuzaTattoosNeverFaceHandsFeet()
            || !dgnYakuzaCastOutNonPerson()
            || !dgnYakuzaMembershipRegainable()
            || !dgnYakuzaWaryOfLaw()
        )
            ++bad;
        // the Table 34 grid: the xp bounds and the accumulated dice plus
        // bonus (capture p. 51)
        int CT34[12][3] = {
            {2000,1,0},
            {4000,2,0},
            {8000,3,0},
            {16000,4,0},
            {30000,5,0},
            {60000,6,0},
            {130000,7,0},
            {260000,8,0},
            {520000,9,0},
            {800000,9,1},
            {1100000,9,2},
            {1400000,9,3},
            };
        int nT34[3] = {0,0,0};
        int eT34[3] = {0,0,0};
        for (int b = 0;
             b < dgnT34RowCount();
             ++b) {
            int vals[3];
            vals[0] = dgnT34XpMax(b);
            vals[1] = dgnT34Dice(b);
            vals[2] = dgnT34HpBonus(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT34[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT34[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nT34[c] != eT34[c])
                ++bad;
        // the Table 35 grid: the investigate ladder and the coded area column
        // (capture p. 53)
        int CT35[21][2] = {
            {20,1},
            {24,1},
            {28,2},
            {32,2},
            {36,3},
            {40,3},
            {44,4},
            {48,4},
            {52,4},
            {56,5},
            {60,5},
            {64,5},
            {68,6},
            {72,6},
            {76,6},
            {80,7},
            {84,7},
            {88,7},
            {92,8},
            {95,8},
            {95,9},
            };
        int nT35[2] = {0,0};
        int eT35[2] = {0,0};
        for (int b = 0;
             b < dgnT35RowCount();
             ++b) {
            int vals[2];
            vals[0] = dgnT35InvestigatePct(b);
            vals[1] = dgnT35AreaCode(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CT35[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT35[c];
            }
        }
        for (int c = 0; c < 2; ++c)
            if (nT35[c] != eT35[c])
                ++bad;
        // the dgnYakuzaMinStr pin
    if (dgnYakuzaMinStr() != 11
        )
            ++bad;
        // the dgnYakuzaMinInt pin
    if (dgnYakuzaMinInt() != 15
        )
            ++bad;
        // the dgnYakuzaMinDex pin
    if (dgnYakuzaMinDex() != 15
        )
            ++bad;
        // the dgnYakuzaMinCha pin
    if (dgnYakuzaMinCha() != 16
        )
            ++bad;
        // the dgnYakuzaHitDie pin
    if (dgnYakuzaHitDie() != 6
        )
            ++bad;
        // the dgnYakuzaSlots pin
    if (dgnYakuzaSlots() != 3
        )
            ++bad;
        // the dgnYakuzaFamilyBirthMod pin
    if (dgnYakuzaFamilyBirthMod() != -5
        )
            ++bad;
        // the dgnYakuzaStipendPerLevel pin
    if (dgnYakuzaStipendPerLevel() != 2
        )
            ++bad;
        // the dgnYakuzaContactLevelDiv pin
    if (dgnYakuzaContactLevelDiv() != 2
        )
            ++bad;
        // the dgnYakuzaContactMaxAbove pin
    if (dgnYakuzaContactMaxAbove() != 4
        )
            ++bad;
        // the dgnYakuzaKiDamageDiv pin
    if (dgnYakuzaKiDamageDiv() != 2
        )
            ++bad;
        // the dgnYakuzaKiPerRound pin
    if (dgnYakuzaKiPerRound() != 1
        )
            ++bad;
        // the dgnYakuzaKiPerDayPerLevel pin
    if (dgnYakuzaKiPerDayPerLevel() != 1
        )
            ++bad;
        // the dgnYakuzaReactionBonusPct pin
    if (dgnYakuzaReactionBonusPct() != 10
        )
            ++bad;
        // the dgnYakuzaInfoCommonDays pin
    if (dgnYakuzaInfoCommonDays() != 1
        )
            ++bad;
        // the dgnYakuzaInfoCommonCostCount pin
    if (dgnYakuzaInfoCommonCostCount() != 2
        )
            ++bad;
        // the dgnYakuzaInfoCommonCostDice pin
    if (dgnYakuzaInfoCommonCostDice() != 6
        )
            ++bad;
        // the dgnYakuzaInfoUncommonDaysMin pin
    if (dgnYakuzaInfoUncommonDaysMin() != 1
        )
            ++bad;
        // the dgnYakuzaInfoUncommonDaysMax pin
    if (dgnYakuzaInfoUncommonDaysMax() != 3
        )
            ++bad;
        // the dgnYakuzaInfoUncommonCostDice pin
    if (dgnYakuzaInfoUncommonCostDice() != 4
        )
            ++bad;
        // the dgnYakuzaInfoUncommonInacc pin
    if (dgnYakuzaInfoUncommonInacc() != 10
        )
            ++bad;
        // the dgnYakuzaInfoConfDaysMin pin
    if (dgnYakuzaInfoConfDaysMin() != 2
        )
            ++bad;
        // the dgnYakuzaInfoConfDaysMax pin
    if (dgnYakuzaInfoConfDaysMax() != 12
        )
            ++bad;
        // the dgnYakuzaInfoConfCostDice pin
    if (dgnYakuzaInfoConfCostDice() != 10
        )
            ++bad;
        // the dgnYakuzaInfoConfInacc pin
    if (dgnYakuzaInfoConfInacc() != 25
        )
            ++bad;
        // the dgnYakuzaInfoSecretDaysMin pin
    if (dgnYakuzaInfoSecretDaysMin() != 3
        )
            ++bad;
        // the dgnYakuzaInfoSecretDaysMax pin
    if (dgnYakuzaInfoSecretDaysMax() != 18
        )
            ++bad;
        // the dgnYakuzaInfoSecretCostDice pin
    if (dgnYakuzaInfoSecretCostDice() != 10
        )
            ++bad;
        // the dgnYakuzaInfoSecretInacc pin
    if (dgnYakuzaInfoSecretInacc() != 40
        )
            ++bad;
        // the dgnYakuzaBrethrenMinLevel pin
    if (dgnYakuzaBrethrenMinLevel() != 2
        )
            ++bad;
        // the dgnYakuzaBrethrenPerLevel pin
    if (dgnYakuzaBrethrenPerLevel() != 1
        )
            ++bad;
        // the dgnYakuzaBrethrenMaxLevel pin
    if (dgnYakuzaBrethrenMaxLevel() != 8
        )
            ++bad;
        // the dgnT34RowCount pin
    if (dgnT34RowCount() != 12
        )
            ++bad;
        // the dgnYakuzaXpBeyond12th pin
    if (dgnYakuzaXpBeyond12th() != 300000
        )
            ++bad;
        // the dgnYakuzaHpPerLevelBeyond9 pin
    if (dgnYakuzaHpPerLevelBeyond9() != 1
        )
            ++bad;
        // the dgnT35RowCount pin
    if (dgnT35RowCount() != 21
        )
            ++bad;
        // the dgnYakuzaAlwaysLawful pin
    if (dgnYakuzaAlwaysLawful() != 1
        )
            ++bad;
        // the dgnYakuzaNoPrimeReq pin
    if (dgnYakuzaNoPrimeReq() != 1
        )
            ++bad;
        // the dgnYakuzaThiefTables pin
    if (dgnYakuzaThiefTables() != 1
        )
            ++bad;
        // the dgnYakuzaAnyWeapon pin
    if (dgnYakuzaAnyWeapon() != 1
        )
            ++bad;
        // the dgnYakuzaArmorFromTable13 pin
    if (dgnYakuzaArmorFromTable13() != 1
        )
            ++bad;
        // the dgnYakuzaNoShields pin
    if (dgnYakuzaNoShields() != 1
        )
            ++bad;
        // the dgnYakuzaFamilyClanRequired pin
    if (dgnYakuzaFamilyClanRequired() != 1
        )
            ++bad;
        // the dgnYakuzaFreeGamingProf pin
    if (dgnYakuzaFreeGamingProf() != 1
        )
            ++bad;
        // the dgnYakuzaThiefSkillsAtNinja pin
    if (dgnYakuzaThiefSkillsAtNinja() != 1
        )
            ++bad;
        // the dgnYakuzaHearNoiseAsMonk pin
    if (dgnYakuzaHearNoiseAsMonk() != 1
        )
            ++bad;
        // the dgnYakuzaInfoNeverMagical pin
    if (dgnYakuzaInfoNeverMagical() != 1
        )
            ++bad;
        // the dgnYakuzaInfoNeverLegendary pin
    if (dgnYakuzaInfoNeverLegendary() != 1
        )
            ++bad;
        // the dgnYakuzaInfoCommonAlwaysAccurate pin
    if (dgnYakuzaInfoCommonAlwaysAccurate() != 1
        )
            ++bad;
        // the dgnYakuzaKiHalvesRoundUp pin
    if (dgnYakuzaKiHalvesRoundUp() != 1
        )
            ++bad;
        // the dgnYakuzaReactionExcludesStatus pin
    if (dgnYakuzaReactionExcludesStatus() != 1
        )
            ++bad;
        // the dgnYakuzaAdoptedNoRolls pin
    if (dgnYakuzaAdoptedNoRolls() != 1
        )
            ++bad;
        // the dgnYakuzaEnterpriseNeedsOyabun pin
    if (dgnYakuzaEnterpriseNeedsOyabun() != 1
        )
            ++bad;
        // the dgnYakuzaTattoosNeverFaceHandsFeet pin
    if (dgnYakuzaTattoosNeverFaceHandsFeet() != 1
        )
            ++bad;
        // the dgnYakuzaCastOutNonPerson pin
    if (dgnYakuzaCastOutNonPerson() != 1
        )
            ++bad;
        // the dgnYakuzaMembershipRegainable pin
    if (dgnYakuzaMembershipRegainable() != 1
        )
            ++bad;
        // the dgnYakuzaWaryOfLaw pin
    if (dgnYakuzaWaryOfLaw() != 1
        )
            ++bad;
        // the T34 first row - 2,000 xp, one die (capture p. 51)
    if (dgnT34XpMax(0) != 2000
            || dgnT34Dice(0) != 1
            || dgnT34HpBonus(0) != 0
        )
            ++bad;
        // the T34 9th-level row - nine dice, no bonus (capture p. 51)
    if (dgnT34XpMax(8) != 520000
            || dgnT34Dice(8) != 9
            || dgnT34HpBonus(8) != 0
        )
            ++bad;
        // the T34 10th-level row - nine dice plus one (capture p. 51)
    if (dgnT34XpMax(9) != 800000
            || dgnT34Dice(9) != 9
            || dgnT34HpBonus(9) != 1
        )
            ++bad;
        // the T34 capstone - 1,400,000 xp, nine dice plus three, twelve rows
        // only (capture p. 51)
    if (dgnT34XpMax(11) != 1400000
            || dgnT34Dice(11) != 9
            || dgnT34HpBonus(11) != 3
            || dgnT34RowCount() != 12
        )
            ++bad;
        // the T34 note pair - 300,000 xp beyond 12th, 1 hp per level beyond
        // 9th (capture p. 51)
    if (dgnYakuzaXpBeyond12th() != 300000
            || dgnYakuzaHpPerLevelBeyond9() != 1
        )
            ++bad;
        // the T35 first row - 20 percent, one block (capture p. 53)
    if (dgnT35InvestigatePct(0) != 20
            || dgnT35AreaCode(0) != 1
        )
            ++bad;
        // the T35 7th-level row - the first ward row, code 4 (capture p. 53)
    if (dgnT35InvestigatePct(6) != 44
            || dgnT35AreaCode(6) != 4
        )
            ++bad;
        // the T35 13th-level row - the first district row, code 6 (capture p.
        // 53)
    if (dgnT35InvestigatePct(12) != 68
            || dgnT35AreaCode(12) != 6
        )
            ++bad;
        // the T35 19th-level row - 92 percent, the 3-district code 8 (capture
        // p. 53)
    if (dgnT35InvestigatePct(18) != 92
            || dgnT35AreaCode(18) != 8
        )
            ++bad;
        // the T35 capstone - 95 percent, the province code 9, twenty-one rows
        // only (capture p. 53)
    if (dgnT35InvestigatePct(20) != 95
            || dgnT35AreaCode(20) != 9
            || dgnT35RowCount() != 21
        )
            ++bad;
        // the T35 ladder shape - the by-4 rise through 19th, then 95 twice
        // (capture p. 53)
    if (dgnT35InvestigatePct(1) - dgnT35InvestigatePct(0) != 4
            || dgnT35InvestigatePct(19) != 95
            || dgnT35InvestigatePct(20) - dgnT35InvestigatePct(19) != 0
        )
            ++bad;
        printf("R627 OA yakuza audit: bad %d\n", bad);
        if (bad) return 1;
    }
