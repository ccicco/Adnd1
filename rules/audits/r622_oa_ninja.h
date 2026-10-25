    // ---- R622 OA ninja audit ----
    // OA round nine (capture pp. 35-39): the ninja - the dual-class doctrine,
    // the capability ladders of Tables 22, 23 and 24, the ki powers, the
    // honor mechanics and the nukenin
    {
        using namespace rules;
        int bad = 0;
    if (dgiNinjaMinDex() != 14
            || dgiNinjaMinCha() != 14
            || dgiNinjaMinInt() != 15
            || dgiNinjaXpSplitDiv() != 2
            || dgiNinjaHpMin() != 1
            || dgiNinjaHpMax() != 2
            || dgiNinjaOtherHpDiv() != 2
            || dgiNinjaExampleHpMin() != 2
            || dgiNinjaExampleHpMax() != 7
            || dgiNinjaSlots() != 2
            || dgiNinjaNightingaleDiv() != 2
            || dgiNinjaTightropeAngle() != 45
            || dgiNinjaTightropeCheckFeet() != 60
            || dgiNinjaTightropeMove() != 60
            || dgiNinjaTightropeBalanceBonus() != 10
            || dgiNinjaTightropeModerateWind() != -10
            || dgiNinjaTightropeStrongWind() != -20
            || dgiNinjaTightropeGustingWind() != -30
            || dgiNinjaTightropeFightPenalty() != -5
            || dgiNinjaVaultRunFeet() != 30
            || dgiNinjaVaultPoleExtraFeet() != 4
            || dgiNinjaVaultObstacleReduction() != 1
            || dgiNinjaVaultDistanceMult() != 2
            || dgiNinjaEscapeRoundsDie() != 10
            || dgiNinjaOpenLocksPerLevel() != 1
            || dgiNinjaDisguiseSexDiv() != 2
            || dgiNinjaDisguisePersonDiv() != 2
            || dgiNinjaDisguiseObserveDays() != 30
            || dgiNinjaKiBreathLevel() != 1
            || dgiNinjaKiWaterLevel() != 5
            || dgiNinjaKiWaterFeetPerLevel() != 5
            || dgiNinjaKiWaterMove() != 30
            || dgiNinjaKiWaterPerDayMult() != 1
            || dgiNinjaKiWallLevel() != 12
            || dgiNinjaKiWallPrepRounds() != 3
            || dgiNinjaKiWallDurationRounds() != 1
            || dgiNinjaKiWallFeetPerLevel() != 1
            || dgiNinjaNukeXpMult() != 2
            || dgiT22RowCount() != 12
            || dgiT22XpBeyond() != 300000
            || dgiT22HpBeyond() != 1
            || dgiT23RowCount() != 10
            || dgiT23FirstScore() != 9
            || dgiT24RowCount() != 20
            || dgiT24VaultHalfFoot() != 2
            || !dgiNinjaHumanOnly()
            || !dgiNinjaSplitClassOnly()
            || !dgiNinjaNoPrimeBonus()
            || !dgiNinjaNoConBonusHp()
            || !dgiNinjaOtherHpRoundedUp()
            || !dgiNinjaThiefSaves()
            || !dgiNinjaOtherCombatTable()
            || !dgiNinjaWeaponsNoHonorLoss()
            || !dgiNinjaCrossSlotHonorLoss()
            || !dgiNinjaOtherClassArmor()
            || !dgiNinjaMagicItemsUnion()
            || !dgiNinjaSilentNoMetal()
            || !dgiNinjaHideWatched()
            || !dgiNinjaHideInfravision()
            || !dgiNinjaTrapsSmallOnly()
            || !dgiNinjaTrapsOneAttempt()
            || !dgiNinjaClimbChainMail()
            || !dgiNinjaClimbMidpointCheck()
            || !dgiNinjaDisguiseClassOnly()
            || !dgiNinjaDisguiseFailForever()
            || !dgiNinjaAssassinatePlanned()
            || !dgiNinjaVaultNoMetal()
            || !dgiNinjaFallChainMail()
            || !dgiNinjaFallVerticalSurface()
            || !dgiNinjaEscapeOneAttempt()
            || !dgiNinjaOpenLocksLockedForever()
            || !dgiNinjaBackstabUnnoticed()
            || !dgiNinjaKiBreathOnceDaily()
            || !dgiNinjaKiWaterBrokenByInjury()
            || !dgiNinjaKiWallCostsAllKi()
            || !dgiNinjaFamilyRule()
            || !dgiNinjaIdentityCost()
            || !dgiNinjaMissionRetryable()
            || !dgiNinjaMissionRefusalAllHonor()
            || !dgiNinjaHonorAboveFamily()
            || !dgiNinjaNukeDeathOrNukenin()
            || !dgiNinjaMissionsFromHead()
        )
            ++bad;
        // the Table 22 grid: the xp bounds and the hit points per level
        // (capture pp. 35-36)
        int CT22[12][2] = {
            {4000,2},
            {8000,2},
            {15000,2},
            {30000,2},
            {60000,2},
            {120000,2},
            {240000,2},
            {500000,2},
            {1000000,2},
            {1300000,1},
            {1600000,1},
            {1900000,1},
            };
        int nT22[2] = {0,0};
        int eT22[2] = {0,0};
        for (int b = 0;
             b < dgiT22RowCount();
             ++b) {
            int vals[2];
            vals[0] = dgiT22XpMax(b);
            vals[1] = dgiT22HpMax(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CT22[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT22[c];
            }
        }
        for (int c = 0; c < 2; ++c)
            if (nT22[c] != eT22[c])
                ++bad;
        // the Table 23 grid: the five thief-skill Dexterity adjustments
        // (capture p. 36)
        int CT23[10][5] = {
            {-15,-10,-20,-10,-15},
            {-10,-10,-15,-5,-10},
            {-5,-5,-10,0,-5},
            {0,0,-5,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {5,0,5,5,5},
            {10,5,10,10,10},
            };
        int nT23[5] = {0,0,0,0,0};
        int eT23[5] = {0,0,0,0,0};
        for (int b = 0;
             b < dgiT23RowCount();
             ++b) {
            int vals[5];
            vals[0] = dgiT23Pockets(b);
            vals[1] = dgiT23Traps(b);
            vals[2] = dgiT23Silent(b);
            vals[3] = dgiT23Hide(b);
            vals[4] = dgiT23Locks(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CT23[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT23[c];
            }
        }
        for (int c = 0; c < 5; ++c)
            if (nT23[c] != eT23[c])
                ++bad;
        // the Table 24 grid: the eleven capability columns, levels 1-20
        // (capture pp. 38-39)
        int CT24[20][11] = {
            {10,15,20,85,20,25,20,16,0,10,2},
            {15,21,25,86,24,29,25,18,0,14,2},
            {20,27,30,87,28,33,30,19,10,18,2},
            {25,33,35,88,32,37,35,20,15,22,2},
            {31,40,40,89,36,42,40,21,20,26,3},
            {37,47,45,90,40,47,45,22,25,30,3},
            {43,55,50,91,44,52,50,23,30,34,3},
            {49,62,55,92,48,57,55,24,35,38,3},
            {56,70,60,93,52,62,60,25,40,42,3},
            {63,78,65,94,56,67,65,26,45,46,4},
            {70,86,70,95,60,72,70,27,50,50,4},
            {77,94,75,96,64,77,75,28,55,54,4},
            {85,95,80,97,68,82,80,29,60,58,4},
            {93,96,85,98,72,87,85,30,65,62,4},
            {94,97,90,99,76,92,90,31,70,66,4},
            {95,98,95,99,80,97,95,32,75,70,4},
            {96,99,95,99,84,99,96,33,80,74,4},
            {97,99,95,99,88,99,97,34,85,78,4},
            {98,99,95,99,92,99,98,35,90,82,4},
            {99,99,95,99,96,99,99,36,95,86,5},
            };
        int nT24[11] = {0,0,0,0,0,0,0,0,0,0,0};
        int eT24[11] = {0,0,0,0,0,0,0,0,0,0,0};
        for (int b = 0;
             b < dgiT24RowCount();
             ++b) {
            int vals[11];
            vals[0] = dgiT24Hide(b);
            vals[1] = dgiT24Silent(b);
            vals[2] = dgiT24Traps(b);
            vals[3] = dgiT24Climb(b);
            vals[4] = dgiT24Disguise(b);
            vals[5] = dgiT24Locks(b);
            vals[6] = dgiT24Tightrope(b);
            vals[7] = dgiT24Vault(b);
            vals[8] = dgiT24Fall(b);
            vals[9] = dgiT24Escape(b);
            vals[10] = dgiT24Backstab(b);
            for (int c = 0; c < 11;
                 ++c) {
                if (vals[c] != CT24[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT24[c];
            }
        }
        for (int c = 0; c < 11; ++c)
            if (nT24[c] != eT24[c])
                ++bad;
        // the dgiNinjaMinDex pin
    if (dgiNinjaMinDex() != 14
        )
            ++bad;
        // the dgiNinjaMinCha pin
    if (dgiNinjaMinCha() != 14
        )
            ++bad;
        // the dgiNinjaMinInt pin
    if (dgiNinjaMinInt() != 15
        )
            ++bad;
        // the dgiNinjaXpSplitDiv pin
    if (dgiNinjaXpSplitDiv() != 2
        )
            ++bad;
        // the dgiNinjaHpMin pin
    if (dgiNinjaHpMin() != 1
        )
            ++bad;
        // the dgiNinjaHpMax pin
    if (dgiNinjaHpMax() != 2
        )
            ++bad;
        // the dgiNinjaOtherHpDiv pin
    if (dgiNinjaOtherHpDiv() != 2
        )
            ++bad;
        // the dgiNinjaExampleHpMin pin
    if (dgiNinjaExampleHpMin() != 2
        )
            ++bad;
        // the dgiNinjaExampleHpMax pin
    if (dgiNinjaExampleHpMax() != 7
        )
            ++bad;
        // the dgiNinjaSlots pin
    if (dgiNinjaSlots() != 2
        )
            ++bad;
        // the dgiNinjaNightingaleDiv pin
    if (dgiNinjaNightingaleDiv() != 2
        )
            ++bad;
        // the dgiNinjaTightropeAngle pin
    if (dgiNinjaTightropeAngle() != 45
        )
            ++bad;
        // the dgiNinjaTightropeCheckFeet pin
    if (dgiNinjaTightropeCheckFeet() != 60
        )
            ++bad;
        // the dgiNinjaTightropeMove pin
    if (dgiNinjaTightropeMove() != 60
        )
            ++bad;
        // the dgiNinjaTightropeBalanceBonus pin
    if (dgiNinjaTightropeBalanceBonus() != 10
        )
            ++bad;
        // the dgiNinjaTightropeModerateWind pin
    if (dgiNinjaTightropeModerateWind() != -10
        )
            ++bad;
        // the dgiNinjaTightropeStrongWind pin
    if (dgiNinjaTightropeStrongWind() != -20
        )
            ++bad;
        // the dgiNinjaTightropeGustingWind pin
    if (dgiNinjaTightropeGustingWind() != -30
        )
            ++bad;
        // the dgiNinjaTightropeFightPenalty pin
    if (dgiNinjaTightropeFightPenalty() != -5
        )
            ++bad;
        // the dgiNinjaVaultRunFeet pin
    if (dgiNinjaVaultRunFeet() != 30
        )
            ++bad;
        // the dgiNinjaVaultPoleExtraFeet pin
    if (dgiNinjaVaultPoleExtraFeet() != 4
        )
            ++bad;
        // the dgiNinjaVaultObstacleReduction pin
    if (dgiNinjaVaultObstacleReduction() != 1
        )
            ++bad;
        // the dgiNinjaVaultDistanceMult pin
    if (dgiNinjaVaultDistanceMult() != 2
        )
            ++bad;
        // the dgiNinjaEscapeRoundsDie pin
    if (dgiNinjaEscapeRoundsDie() != 10
        )
            ++bad;
        // the dgiNinjaOpenLocksPerLevel pin
    if (dgiNinjaOpenLocksPerLevel() != 1
        )
            ++bad;
        // the dgiNinjaDisguiseSexDiv pin
    if (dgiNinjaDisguiseSexDiv() != 2
        )
            ++bad;
        // the dgiNinjaDisguisePersonDiv pin
    if (dgiNinjaDisguisePersonDiv() != 2
        )
            ++bad;
        // the dgiNinjaDisguiseObserveDays pin
    if (dgiNinjaDisguiseObserveDays() != 30
        )
            ++bad;
        // the dgiNinjaKiBreathLevel pin
    if (dgiNinjaKiBreathLevel() != 1
        )
            ++bad;
        // the dgiNinjaKiWaterLevel pin
    if (dgiNinjaKiWaterLevel() != 5
        )
            ++bad;
        // the dgiNinjaKiWaterFeetPerLevel pin
    if (dgiNinjaKiWaterFeetPerLevel() != 5
        )
            ++bad;
        // the dgiNinjaKiWaterMove pin
    if (dgiNinjaKiWaterMove() != 30
        )
            ++bad;
        // the dgiNinjaKiWaterPerDayMult pin
    if (dgiNinjaKiWaterPerDayMult() != 1
        )
            ++bad;
        // the dgiNinjaKiWallLevel pin
    if (dgiNinjaKiWallLevel() != 12
        )
            ++bad;
        // the dgiNinjaKiWallPrepRounds pin
    if (dgiNinjaKiWallPrepRounds() != 3
        )
            ++bad;
        // the dgiNinjaKiWallDurationRounds pin
    if (dgiNinjaKiWallDurationRounds() != 1
        )
            ++bad;
        // the dgiNinjaKiWallFeetPerLevel pin
    if (dgiNinjaKiWallFeetPerLevel() != 1
        )
            ++bad;
        // the dgiNinjaNukeXpMult pin
    if (dgiNinjaNukeXpMult() != 2
        )
            ++bad;
        // the dgiT22RowCount pin
    if (dgiT22RowCount() != 12
        )
            ++bad;
        // the dgiT22XpBeyond pin
    if (dgiT22XpBeyond() != 300000
        )
            ++bad;
        // the dgiT22HpBeyond pin
    if (dgiT22HpBeyond() != 1
        )
            ++bad;
        // the dgiT23RowCount pin
    if (dgiT23RowCount() != 10
        )
            ++bad;
        // the dgiT23FirstScore pin
    if (dgiT23FirstScore() != 9
        )
            ++bad;
        // the dgiT24RowCount pin
    if (dgiT24RowCount() != 20
        )
            ++bad;
        // the dgiT24VaultHalfFoot pin
    if (dgiT24VaultHalfFoot() != 2
        )
            ++bad;
        // the dgiNinjaHumanOnly pin
    if (dgiNinjaHumanOnly() != 1
        )
            ++bad;
        // the dgiNinjaSplitClassOnly pin
    if (dgiNinjaSplitClassOnly() != 1
        )
            ++bad;
        // the dgiNinjaNoPrimeBonus pin
    if (dgiNinjaNoPrimeBonus() != 1
        )
            ++bad;
        // the dgiNinjaNoConBonusHp pin
    if (dgiNinjaNoConBonusHp() != 1
        )
            ++bad;
        // the dgiNinjaOtherHpRoundedUp pin
    if (dgiNinjaOtherHpRoundedUp() != 1
        )
            ++bad;
        // the dgiNinjaThiefSaves pin
    if (dgiNinjaThiefSaves() != 1
        )
            ++bad;
        // the dgiNinjaOtherCombatTable pin
    if (dgiNinjaOtherCombatTable() != 1
        )
            ++bad;
        // the dgiNinjaWeaponsNoHonorLoss pin
    if (dgiNinjaWeaponsNoHonorLoss() != 1
        )
            ++bad;
        // the dgiNinjaCrossSlotHonorLoss pin
    if (dgiNinjaCrossSlotHonorLoss() != 1
        )
            ++bad;
        // the dgiNinjaOtherClassArmor pin
    if (dgiNinjaOtherClassArmor() != 1
        )
            ++bad;
        // the dgiNinjaMagicItemsUnion pin
    if (dgiNinjaMagicItemsUnion() != 1
        )
            ++bad;
        // the dgiNinjaSilentNoMetal pin
    if (dgiNinjaSilentNoMetal() != 1
        )
            ++bad;
        // the dgiNinjaHideWatched pin
    if (dgiNinjaHideWatched() != 1
        )
            ++bad;
        // the dgiNinjaHideInfravision pin
    if (dgiNinjaHideInfravision() != 1
        )
            ++bad;
        // the dgiNinjaTrapsSmallOnly pin
    if (dgiNinjaTrapsSmallOnly() != 1
        )
            ++bad;
        // the dgiNinjaTrapsOneAttempt pin
    if (dgiNinjaTrapsOneAttempt() != 1
        )
            ++bad;
        // the dgiNinjaClimbChainMail pin
    if (dgiNinjaClimbChainMail() != 1
        )
            ++bad;
        // the dgiNinjaClimbMidpointCheck pin
    if (dgiNinjaClimbMidpointCheck() != 1
        )
            ++bad;
        // the dgiNinjaDisguiseClassOnly pin
    if (dgiNinjaDisguiseClassOnly() != 1
        )
            ++bad;
        // the dgiNinjaDisguiseFailForever pin
    if (dgiNinjaDisguiseFailForever() != 1
        )
            ++bad;
        // the dgiNinjaAssassinatePlanned pin
    if (dgiNinjaAssassinatePlanned() != 1
        )
            ++bad;
        // the dgiNinjaVaultNoMetal pin
    if (dgiNinjaVaultNoMetal() != 1
        )
            ++bad;
        // the dgiNinjaFallChainMail pin
    if (dgiNinjaFallChainMail() != 1
        )
            ++bad;
        // the dgiNinjaFallVerticalSurface pin
    if (dgiNinjaFallVerticalSurface() != 1
        )
            ++bad;
        // the dgiNinjaEscapeOneAttempt pin
    if (dgiNinjaEscapeOneAttempt() != 1
        )
            ++bad;
        // the dgiNinjaOpenLocksLockedForever pin
    if (dgiNinjaOpenLocksLockedForever() != 1
        )
            ++bad;
        // the dgiNinjaBackstabUnnoticed pin
    if (dgiNinjaBackstabUnnoticed() != 1
        )
            ++bad;
        // the dgiNinjaKiBreathOnceDaily pin
    if (dgiNinjaKiBreathOnceDaily() != 1
        )
            ++bad;
        // the dgiNinjaKiWaterBrokenByInjury pin
    if (dgiNinjaKiWaterBrokenByInjury() != 1
        )
            ++bad;
        // the dgiNinjaKiWallCostsAllKi pin
    if (dgiNinjaKiWallCostsAllKi() != 1
        )
            ++bad;
        // the dgiNinjaFamilyRule pin
    if (dgiNinjaFamilyRule() != 1
        )
            ++bad;
        // the dgiNinjaIdentityCost pin
    if (dgiNinjaIdentityCost() != 1
        )
            ++bad;
        // the dgiNinjaMissionRetryable pin
    if (dgiNinjaMissionRetryable() != 1
        )
            ++bad;
        // the dgiNinjaMissionRefusalAllHonor pin
    if (dgiNinjaMissionRefusalAllHonor() != 1
        )
            ++bad;
        // the dgiNinjaHonorAboveFamily pin
    if (dgiNinjaHonorAboveFamily() != 1
        )
            ++bad;
        // the dgiNinjaNukeDeathOrNukenin pin
    if (dgiNinjaNukeDeathOrNukenin() != 1
        )
            ++bad;
        // the dgiNinjaMissionsFromHead pin
    if (dgiNinjaMissionsFromHead() != 1
        )
            ++bad;
        // the T22 first row - 4,000 xp, the 1-2 hp range (capture p. 35)
    if (dgiT22XpMax(0) != 4000
            || dgiT22HpMax(0) != 2
        )
            ++bad;
        // the T22 level-2 bound settled at 8,000 - the 2018 print 8,001 cell
        // contradicts the next-row floor (capture p. 35)
    if (dgiT22XpMax(1) != 8000
            || dgiT22XpMax(2) != 15000
        )
            ++bad;
        // the T22 beyond-9th rows - hp 1 and the 1,900,000 cap (capture p.
        // 36)
    if (dgiT22HpMax(9) != 1
            || dgiT22HpMax(11) != 1
            || dgiT22XpMax(11) != 1900000
            || dgiT22HpBeyond() != 1
        )
            ++bad;
        // the T23 Dex-9 row - the five penalties (capture p. 36)
    if (dgiT23Pockets(0) != -15
            || dgiT23Silent(0) != -20
            || dgiT23Locks(0) != -15
        )
            ++bad;
        // the T23 Dex-11 pockets cell settled at -5 - the 2018 print 05
        // reading lost the minus (capture p. 36)
    if (dgiT23Pockets(2) != -5
            || dgiT23Pockets(3) != 0
        )
            ++bad;
        // the T23 Dex-18 row - the five bonuses (capture p. 36)
    if (dgiT23Pockets(9) != 10
            || dgiT23Traps(9) != 5
            || dgiT23Silent(9) != 10
            || dgiT23Hide(9) != 10
            || dgiT23Locks(9) != 10
        )
            ++bad;
        // the T24 1st-level row - the eleven capabilities (capture p. 38)
    if (dgiT24Hide(0) != 10
            || dgiT24Climb(0) != 85
            || dgiT24Vault(0) != 16
            || dgiT24Fall(0) != 0
            || dgiT24Backstab(0) != 2
        )
            ++bad;
        // the T24 capstone - the 20th-level row with the x5 backstab (capture
        // p. 39)
    if (dgiT24Hide(19) != 99
            || dgiT24Disguise(19) != 96
            || dgiT24Vault(19) != 36
            || dgiT24Fall(19) != 95
            || dgiT24Escape(19) != 86
            || dgiT24Backstab(19) != 5
        )
            ++bad;
        // the T24 backstab ladder - x3 at 5th, x4 at 10th (capture pp. 38-39)
    if (dgiT24Backstab(4) != 3
            || dgiT24Backstab(9) != 4
        )
            ++bad;
        // the T24 pole-vault ladder - the 9.5 prime cell at 3rd is 19 half
        // feet (capture p. 38)
    if (dgiT24Vault(2) != 19
            || dgiT24VaultHalfFoot() != 2
        )
            ++bad;
        // the T24 fall ladder opens at 10 feet on the 3rd-level row (capture
        // p. 38)
    if (dgiT24Fall(1) != 0
            || dgiT24Fall(2) != 10
        )
            ++bad;
        // the bushi/ninja example - 2 to 7 hit points, the 1-5 halved die
        // plus 1-2 (capture p. 36)
    if (dgiNinjaExampleHpMin() != 2
            || dgiNinjaExampleHpMax() != 7
            || dgiNinjaOtherHpDiv() != 2
        )
            ++bad;
        printf("R622 OA ninja audit: bad %d\n", bad);
        if (bad) return 1;
    }
