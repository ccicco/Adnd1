    // ---- R621 OA monk audit ----
    // OA round eight (capture pp. 31-35): the monk - the ability minima, the
    // discipline ladders of Tables 20 and 21, the ki power, the level powers,
    // the monastery duel and the material restrictions
    {
        using namespace rules;
        int bad = 0;
    if (dghMonkMinStr() != 15
            || dghMonkMinWis() != 15
            || dghMonkMinDex() != 15
            || dghMonkMinCon() != 11
            || dghMonkMaxLevel() != 17
            || dghMonkStartDice() != 2
            || dghMonkHitDie() != 4
            || dghMonkWeaponDmgStep() != 2
            || dghMonkBaseMove() != 15
            || dghMonkSlots() != 5
            || dghMonkStyleManeuvers() != 2
            || dghMonkKiPerDayMult() != 1
            || dghMonkSpeakAnimalsLevel() != 3
            || dghMonkFall20Level() != 4
            || dghMonkFall20Feet() != 20
            || dghMonkFall20WallFeet() != 1
            || dghMonkEspBasePct() != 30
            || dghMonkEspStepPct() != 2
            || dghMonkDiseaseLevel() != 5
            || dghMonkFall30Level() != 6
            || dghMonkFall30Feet() != 30
            || dghMonkFall30WallFeet() != 4
            || dghMonkCatalepticMult() != 2
            || dghMonkHealLevel() != 7
            || dghMonkHealMin() != 2
            || dghMonkHealMax() != 5
            || dghMonkHealStep() != 1
            || dghMonkSpeakPlantsLevel() != 8
            || dghMonkFollowerMin() != 2
            || dghMonkFollowerMax() != 5
            || dghMonkFollowerExtraMin() != 1
            || dghMonkFollowerExtraMax() != 2
            || dghMonkFollowerLeaveLevel() != 7
            || dghMonkKiHalfFailLevel() != 9
            || dghMonkCharmBasePct() != 50
            || dghMonkCharmStepPct() != 5
            || dghMonkMindShieldLevel() != 10
            || dghMonkPoisonImmuneLevel() != 11
            || dghMonkGeasImmuneLevel() != 12
            || dghMonkFreeManeuverLevel() != 13
            || dghMonkHenchLevel() != 6
            || dghMonkHenchBase() != 2
            || dghMonkHenchStep() != 1
            || dghMonkMagicWeaponCap() != 2
            || dghMonkMagicItemCap() != 3
            || dghMonkMonasteryEights() != 3
            || dghMonkMonasteryBeyond() != 1
            || dghMonkResetXpExample() != 98001
            || dghT20RowCount() != 17
            || dghT20TitleNovice() != 1
            || dghT20TitleGrandMaster() != 17
            || dghT21RowCount() != 17
            || dghT21AtNone() != 0
            || dghT21AtFirst() != 14
            || dghT21AtLast() != 31
            || dghT21DmgNone() != 0
            || dghT21DmgFirstDice() != 100
            || dghT21DmgCap() != 400
            || dghT21SurpriseNormal() != 0
            || !dghMonkLawfulOnly()
            || !dghMonkNoPrimeBonus()
            || !dghMonkNoStrAdjust()
            || !dghMonkNoDexAc()
            || !dghMonkThiefTables()
            || !dghMonkNoArmor()
            || !dghMonkNoFlamingOil()
            || !dghMonkMissileDeflection()
            || !dghMonkKiSaveNegates()
            || !dghMonkKiDeclaredLate()
            || !dghMonkHasteSlowImmune()
            || !dghMonkDiseaseImmune()
            || !dghMonkCatalepticStated()
            || !dghMonkMonasteryDuel()
            || !dghMonkDuelNoIntervention()
            || !dghMonkNoFamilyHonor()
            || !dghMonkMonasteryName()
            || !dghMonkNoProperty()
            || !dghMonkDmgItemGate()
            || !dghMonkNoItemTrading()
        )
            ++bad;
        // the Table 20 grid: the xp bounds, the accumulated d4 dice and the
        // title codes (capture pp. 31-32)
        int CT20[17][3] = {
            {2250,2,1},
            {4750,3,2},
            {10000,4,3},
            {22500,5,4},
            {47500,6,5},
            {98000,7,6},
            {200000,8,7},
            {350000,9,8},
            {500000,10,9},
            {700000,11,10},
            {950000,12,11},
            {1250000,13,12},
            {1750000,14,13},
            {2250000,15,14},
            {2750000,16,15},
            {3250000,17,16},
            {3250001,18,17},
            };
        int nT20[3] = {0,0,0};
        int eT20[3] = {0,0,0};
        for (int b = 0;
             b < dghT20RowCount();
             ++b) {
            int vals[3];
            vals[0] = dghT20XpMax(b);
            vals[1] = dghT20Dice(b);
            vals[2] = dghT20Title(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT20[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT20[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nT20[c] != eT20[c])
                ++bad;
        // the Table 21 grid: the AC, movement, attack and damage codes, the
        // six thief skills and the surprise ladder (capture p. 33)
        int CT21[17][11] = {
            {10,15,0,0,25,20,15,10,10,85,0},
            {9,16,0,0,29,25,21,15,10,86,32},
            {8,17,0,0,33,30,27,20,15,87,30},
            {7,18,14,0,37,35,33,25,15,88,28},
            {7,19,14,1,42,40,40,31,20,89,26},
            {6,20,12,2,47,45,47,37,20,90,24},
            {5,21,12,2,52,50,55,43,25,91,22},
            {4,22,12,100,57,55,62,49,25,92,20},
            {3,23,11,101,62,60,70,56,30,93,18},
            {3,24,11,102,67,65,78,63,30,94,16},
            {2,25,32,102,72,70,86,70,35,95,14},
            {1,26,32,200,77,75,94,77,35,96,12},
            {0,27,32,200,82,80,99,85,40,97,10},
            {-1,28,21,201,87,85,99,93,40,98,8},
            {-1,29,21,300,92,90,99,99,50,99,6},
            {-2,30,31,301,97,95,99,99,50,99,4},
            {-3,32,31,400,99,99,99,99,55,99,2},
            };
        int nT21[11] = {0,0,0,0,0,0,0,0,0,0,0};
        int eT21[11] = {0,0,0,0,0,0,0,0,0,0,0};
        for (int b = 0;
             b < dghT21RowCount();
             ++b) {
            int vals[11];
            vals[0] = dghT21Ac(b);
            vals[1] = dghT21Move(b);
            vals[2] = dghT21At(b);
            vals[3] = dghT21Dmg(b);
            vals[4] = dghT21OpenLocks(b);
            vals[5] = dghT21Traps(b);
            vals[6] = dghT21Silent(b);
            vals[7] = dghT21Hide(b);
            vals[8] = dghT21Hear(b);
            vals[9] = dghT21Climb(b);
            vals[10] = dghT21Surprise(b);
            for (int c = 0; c < 11;
                 ++c) {
                if (vals[c] != CT21[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT21[c];
            }
        }
        for (int c = 0; c < 11; ++c)
            if (nT21[c] != eT21[c])
                ++bad;
        // the dghMonkMinStr pin
    if (dghMonkMinStr() != 15
        )
            ++bad;
        // the dghMonkMinWis pin
    if (dghMonkMinWis() != 15
        )
            ++bad;
        // the dghMonkMinDex pin
    if (dghMonkMinDex() != 15
        )
            ++bad;
        // the dghMonkMinCon pin
    if (dghMonkMinCon() != 11
        )
            ++bad;
        // the dghMonkMaxLevel pin
    if (dghMonkMaxLevel() != 17
        )
            ++bad;
        // the dghMonkStartDice pin
    if (dghMonkStartDice() != 2
        )
            ++bad;
        // the dghMonkHitDie pin
    if (dghMonkHitDie() != 4
        )
            ++bad;
        // the dghMonkWeaponDmgStep pin
    if (dghMonkWeaponDmgStep() != 2
        )
            ++bad;
        // the dghMonkBaseMove pin
    if (dghMonkBaseMove() != 15
        )
            ++bad;
        // the dghMonkSlots pin
    if (dghMonkSlots() != 5
        )
            ++bad;
        // the dghMonkStyleManeuvers pin
    if (dghMonkStyleManeuvers() != 2
        )
            ++bad;
        // the dghMonkKiPerDayMult pin
    if (dghMonkKiPerDayMult() != 1
        )
            ++bad;
        // the dghMonkSpeakAnimalsLevel pin
    if (dghMonkSpeakAnimalsLevel() != 3
        )
            ++bad;
        // the dghMonkFall20Level pin
    if (dghMonkFall20Level() != 4
        )
            ++bad;
        // the dghMonkFall20Feet pin
    if (dghMonkFall20Feet() != 20
        )
            ++bad;
        // the dghMonkFall20WallFeet pin
    if (dghMonkFall20WallFeet() != 1
        )
            ++bad;
        // the dghMonkEspBasePct pin
    if (dghMonkEspBasePct() != 30
        )
            ++bad;
        // the dghMonkEspStepPct pin
    if (dghMonkEspStepPct() != 2
        )
            ++bad;
        // the dghMonkDiseaseLevel pin
    if (dghMonkDiseaseLevel() != 5
        )
            ++bad;
        // the dghMonkFall30Level pin
    if (dghMonkFall30Level() != 6
        )
            ++bad;
        // the dghMonkFall30Feet pin
    if (dghMonkFall30Feet() != 30
        )
            ++bad;
        // the dghMonkFall30WallFeet pin
    if (dghMonkFall30WallFeet() != 4
        )
            ++bad;
        // the dghMonkCatalepticMult pin
    if (dghMonkCatalepticMult() != 2
        )
            ++bad;
        // the dghMonkHealLevel pin
    if (dghMonkHealLevel() != 7
        )
            ++bad;
        // the dghMonkHealMin pin
    if (dghMonkHealMin() != 2
        )
            ++bad;
        // the dghMonkHealMax pin
    if (dghMonkHealMax() != 5
        )
            ++bad;
        // the dghMonkHealStep pin
    if (dghMonkHealStep() != 1
        )
            ++bad;
        // the dghMonkSpeakPlantsLevel pin
    if (dghMonkSpeakPlantsLevel() != 8
        )
            ++bad;
        // the dghMonkFollowerMin pin
    if (dghMonkFollowerMin() != 2
        )
            ++bad;
        // the dghMonkFollowerMax pin
    if (dghMonkFollowerMax() != 5
        )
            ++bad;
        // the dghMonkFollowerExtraMin pin
    if (dghMonkFollowerExtraMin() != 1
        )
            ++bad;
        // the dghMonkFollowerExtraMax pin
    if (dghMonkFollowerExtraMax() != 2
        )
            ++bad;
        // the dghMonkFollowerLeaveLevel pin
    if (dghMonkFollowerLeaveLevel() != 7
        )
            ++bad;
        // the dghMonkKiHalfFailLevel pin
    if (dghMonkKiHalfFailLevel() != 9
        )
            ++bad;
        // the dghMonkCharmBasePct pin
    if (dghMonkCharmBasePct() != 50
        )
            ++bad;
        // the dghMonkCharmStepPct pin
    if (dghMonkCharmStepPct() != 5
        )
            ++bad;
        // the dghMonkMindShieldLevel pin
    if (dghMonkMindShieldLevel() != 10
        )
            ++bad;
        // the dghMonkPoisonImmuneLevel pin
    if (dghMonkPoisonImmuneLevel() != 11
        )
            ++bad;
        // the dghMonkGeasImmuneLevel pin
    if (dghMonkGeasImmuneLevel() != 12
        )
            ++bad;
        // the dghMonkFreeManeuverLevel pin
    if (dghMonkFreeManeuverLevel() != 13
        )
            ++bad;
        // the dghMonkHenchLevel pin
    if (dghMonkHenchLevel() != 6
        )
            ++bad;
        // the dghMonkHenchBase pin
    if (dghMonkHenchBase() != 2
        )
            ++bad;
        // the dghMonkHenchStep pin
    if (dghMonkHenchStep() != 1
        )
            ++bad;
        // the dghMonkMagicWeaponCap pin
    if (dghMonkMagicWeaponCap() != 2
        )
            ++bad;
        // the dghMonkMagicItemCap pin
    if (dghMonkMagicItemCap() != 3
        )
            ++bad;
        // the dghMonkMonasteryEights pin
    if (dghMonkMonasteryEights() != 3
        )
            ++bad;
        // the dghMonkMonasteryBeyond pin
    if (dghMonkMonasteryBeyond() != 1
        )
            ++bad;
        // the dghMonkResetXpExample pin
    if (dghMonkResetXpExample() != 98001
        )
            ++bad;
        // the dghT20RowCount pin
    if (dghT20RowCount() != 17
        )
            ++bad;
        // the dghT20TitleNovice pin
    if (dghT20TitleNovice() != 1
        )
            ++bad;
        // the dghT20TitleGrandMaster pin
    if (dghT20TitleGrandMaster() != 17
        )
            ++bad;
        // the dghT21RowCount pin
    if (dghT21RowCount() != 17
        )
            ++bad;
        // the dghT21AtNone pin
    if (dghT21AtNone() != 0
        )
            ++bad;
        // the dghT21AtFirst pin
    if (dghT21AtFirst() != 14
        )
            ++bad;
        // the dghT21AtLast pin
    if (dghT21AtLast() != 31
        )
            ++bad;
        // the dghT21DmgNone pin
    if (dghT21DmgNone() != 0
        )
            ++bad;
        // the dghT21DmgFirstDice pin
    if (dghT21DmgFirstDice() != 100
        )
            ++bad;
        // the dghT21DmgCap pin
    if (dghT21DmgCap() != 400
        )
            ++bad;
        // the dghT21SurpriseNormal pin
    if (dghT21SurpriseNormal() != 0
        )
            ++bad;
        // the dghMonkLawfulOnly pin
    if (dghMonkLawfulOnly() != 1
        )
            ++bad;
        // the dghMonkNoPrimeBonus pin
    if (dghMonkNoPrimeBonus() != 1
        )
            ++bad;
        // the dghMonkNoStrAdjust pin
    if (dghMonkNoStrAdjust() != 1
        )
            ++bad;
        // the dghMonkNoDexAc pin
    if (dghMonkNoDexAc() != 1
        )
            ++bad;
        // the dghMonkThiefTables pin
    if (dghMonkThiefTables() != 1
        )
            ++bad;
        // the dghMonkNoArmor pin
    if (dghMonkNoArmor() != 1
        )
            ++bad;
        // the dghMonkNoFlamingOil pin
    if (dghMonkNoFlamingOil() != 1
        )
            ++bad;
        // the dghMonkMissileDeflection pin
    if (dghMonkMissileDeflection() != 1
        )
            ++bad;
        // the dghMonkKiSaveNegates pin
    if (dghMonkKiSaveNegates() != 1
        )
            ++bad;
        // the dghMonkKiDeclaredLate pin
    if (dghMonkKiDeclaredLate() != 1
        )
            ++bad;
        // the dghMonkHasteSlowImmune pin
    if (dghMonkHasteSlowImmune() != 1
        )
            ++bad;
        // the dghMonkDiseaseImmune pin
    if (dghMonkDiseaseImmune() != 1
        )
            ++bad;
        // the dghMonkCatalepticStated pin
    if (dghMonkCatalepticStated() != 1
        )
            ++bad;
        // the dghMonkMonasteryDuel pin
    if (dghMonkMonasteryDuel() != 1
        )
            ++bad;
        // the dghMonkDuelNoIntervention pin
    if (dghMonkDuelNoIntervention() != 1
        )
            ++bad;
        // the dghMonkNoFamilyHonor pin
    if (dghMonkNoFamilyHonor() != 1
        )
            ++bad;
        // the dghMonkMonasteryName pin
    if (dghMonkMonasteryName() != 1
        )
            ++bad;
        // the dghMonkNoProperty pin
    if (dghMonkNoProperty() != 1
        )
            ++bad;
        // the dghMonkDmgItemGate pin
    if (dghMonkDmgItemGate() != 1
        )
            ++bad;
        // the dghMonkNoItemTrading pin
    if (dghMonkNoItemTrading() != 1
        )
            ++bad;
        // the T20 first row - 2,250 xp, two dice, Novice (capture p. 31)
    if (dghT20XpMax(0) != 2250
            || dghT20Dice(0) != 2
            || dghT20Title(0) != 1
        )
            ++bad;
        // the T20 capstone - 3,250,001 xp, eighteen dice, Grand Master of
        // Flowers (capture p. 32)
    if (dghT20XpMax(16) != 3250001
            || dghT20Dice(16) != 18
            || dghT20Title(16) != 17
        )
            ++bad;
        // the T21 first row - AC 10, move 15, normal surprise (capture p. 33)
    if (dghT21Ac(0) != 10
            || dghT21Move(0) != 15
            || dghT21Surprise(0) != 0
        )
            ++bad;
        // the T21 capstone - AC -3, move 32, the 3/1 and +4D codes, 2 percent
        // surprise (capture p. 33)
    if (dghT21Ac(16) != -3
            || dghT21Move(16) != 32
            || dghT21At(16) != 31
            || dghT21Dmg(16) != 400
            || dghT21Surprise(16) != 2
        )
            ++bad;
        // the T21 attack codes open at 1/4 on the 4th-level row (capture p.
        // 33)
    if (dghT21At(3) != 14
        )
            ++bad;
        // the T21 damage codes open at +1D on the 8th-level row (capture p.
        // 33)
    if (dghT21Dmg(7) != 100
        )
            ++bad;
        // the T21 thief-skill ladder - open locks 25 to 99, climb walls 85 to
        // 99 (capture p. 33)
    if (dghT21OpenLocks(0) != 25
            || dghT21OpenLocks(16) != 99
            || dghT21Climb(0) != 85
        )
            ++bad;
        // the ESP ladder - 30 at 4th minus 2 per level beyond, so 28 at 5th
        // (capture p. 33)
    if (dghMonkEspBasePct() - dghMonkEspStepPct() != 28
        )
            ++bad;
        // the weapon damage step - one extra point per two levels (capture p.
        // 32)
    if (dghMonkWeaponDmgStep() != 2
        )
            ++bad;
        // the heal ladder - 2-5 at 7th, one more per level beyond (capture p.
        // 34)
    if (dghMonkHealMin() != 2
            || dghMonkHealMax() != 5
            || dghMonkHealStep() != 1
        )
            ++bad;
        // the monastery supports three 8th-level monks and one of each level
        // beyond (capture p. 35)
    if (dghMonkMonasteryEights() != 3
            || dghMonkMonasteryBeyond() != 1
        )
            ++bad;
        printf("R621 OA monk audit: bad %d\n", bad);
        if (bad) return 1;
    }
