    // ---- R626 OA wu jen audit ----
    // OA round thirteen (capture pp. 47-51): the wu jen - the minima, the
    // spell-learning doctrine, the ki powers, the elemental mastery and the
    // taboo ladder
    {
        using namespace rules;
        int bad = 0;
    if (dgmWuJenMinInt() != 13
            || dgmWuJenBonusInt() != 15
            || dgmWuJenBonusPct() != 10
            || dgmWuJenHitDie() != 4
            || dgmWuJenHpBonusPerDie() != 1
            || dgmWuJenHpPerLevelMin() != 2
            || dgmWuJenHpPerLevelMax() != 5
            || dgmWuJenSlots() != 6
            || dgmWuJenFavoredBonus() != 1
            || dgmWuJenKiInitBonus() != 3
            || dgmWuJenKiInitRounds() != 1
            || dgmWuJenKiInitPerDay() != 1
            || dgmWuJenKiMaxEffectLevel() != 4
            || dgmWuJenKiMaxEffectGap() != 3
            || dgmWuJenElementCount() != 5
            || dgmWuJenMasterEnemySaveMod() != -1
            || dgmWuJenMasterDamageBonus() != 1
            || dgmWuJenMasterSaveBonus() != 1
            || dgmWuJenPupilLevel() != 10
            || dgmWuJenPupilDice() != 4
            || dgmWuJenPupilLeaveDiv() != 2
            || dgmWuJenTenguOniReaction() != 20
            || dgmWuJenTabooFirstLevel() != 1
            || dgmWuJenTabooStepLevels() != 5
            || dgmT31RowCount() != 11
            || dgmT31XpBeyond() != 300000
            || dgmT31HpBeyond() != 1
            || dgmT32RowCount() != 7
            || dgmT32MaxAll() != -1
            || dgmT33RowCount() != 29
            || dgmT33SpellLevels() != 9
            || !dgmWuJenNeverLawful()
            || !dgmWuJenRaces()
            || !dgmWuJenMagicUserTables()
            || !dgmWuJenNoArmor()
            || !dgmWuJenMeditates()
            || !dgmWuJenUnderstandKnowMemorize()
            || !dgmWuJenIntLossRecheck()
            || !dgmWuJenScrollDestroyed()
            || !dgmWuJenMasterLostOnNewLevel()
            || !dgmWuJenStrongholdWithLieutenant()
            || !dgmWuJenTenguOniLanguage()
            || !dgmWuJenNoFamily()
            || !dgmWuJenLightHonor()
            || !dgmWuJenTabooConsequences()
        )
            ++bad;
        // the Table 31 grid: the xp bounds and the accumulated dice plus
        // bonus (capture pp. 47-48)
        int CT31[11][3] = {
            {2000,1,0},
            {4000,2,0},
            {8000,3,0},
            {18000,4,0},
            {36000,5,0},
            {65000,6,0},
            {100000,7,0},
            {140000,8,0},
            {280000,9,0},
            {600000,9,1},
            {800000,9,2},
            };
        int nT31[3] = {0,0,0};
        int eT31[3] = {0,0,0};
        for (int b = 0;
             b < dgmT31RowCount();
             ++b) {
            int vals[3];
            vals[0] = dgmT31XpMax(b);
            vals[1] = dgmT31Dice(b);
            vals[2] = dgmT31HpBonus(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT31[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT31[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nT31[c] != eT31[c])
                ++bad;
        // the Table 32 grid: the know chance with the spell minima and maxima
        // (capture p. 48)
        int CT32[7][3] = {
            {35,4,6},
            {45,5,7},
            {55,6,9},
            {65,7,11},
            {75,8,14},
            {85,9,18},
            {95,10,-1},
            };
        int nT32[3] = {0,0,0};
        int eT32[3] = {0,0,0};
        for (int b = 0;
             b < dgmT32RowCount();
             ++b) {
            int vals[3];
            vals[0] = dgmT32KnowPct(b);
            vals[1] = dgmT32MinSpells(b);
            vals[2] = dgmT32MaxSpells(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT32[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT32[c];
            }
        }
        for (int c = 0; c < 3; ++c)
            if (nT32[c] != eT32[c])
                ++bad;
        // the Table 33 grid: the nine spell-level columns, levels 1-29
        // (capture p. 49)
        int CT33[29][9] = {
            {1,0,0,0,0,0,0,0,0},
            {2,0,0,0,0,0,0,0,0},
            {2,1,0,0,0,0,0,0,0},
            {3,2,0,0,0,0,0,0,0},
            {3,2,1,0,0,0,0,0,0},
            {4,2,2,0,0,0,0,0,0},
            {4,3,2,1,0,0,0,0,0},
            {4,3,3,2,0,0,0,0,0},
            {5,3,3,2,1,0,0,0,0},
            {5,4,3,2,2,0,0,0,0},
            {5,4,4,2,2,1,0,0,0},
            {5,5,4,2,2,2,0,0,0},
            {5,5,4,4,2,2,1,0,0},
            {6,5,4,4,2,2,2,0,0},
            {6,5,4,4,3,3,2,0,0},
            {6,6,5,4,4,3,2,0,0},
            {6,6,5,5,4,3,2,1,0},
            {6,6,5,5,4,4,2,2,0},
            {6,6,6,5,5,4,2,2,0},
            {6,6,6,5,5,4,3,3,0},
            {7,6,6,6,5,4,3,3,1},
            {7,7,6,6,5,5,3,3,1},
            {7,7,7,6,6,5,3,3,2},
            {7,7,7,6,6,5,4,4,2},
            {8,7,7,6,6,6,4,4,2},
            {8,8,7,7,6,6,5,4,3},
            {8,8,8,7,7,6,5,4,3},
            {9,8,8,7,7,7,5,5,3},
            {9,9,8,8,7,7,6,5,4},
            };
        int nT33[9] = {0,0,0,0,0,0,0,0,0};
        int eT33[9] = {0,0,0,0,0,0,0,0,0};
        for (int b = 0;
             b < dgmT33RowCount();
             ++b) {
            int vals[9];
            vals[0] = dgmT33S1(b);
            vals[1] = dgmT33S2(b);
            vals[2] = dgmT33S3(b);
            vals[3] = dgmT33S4(b);
            vals[4] = dgmT33S5(b);
            vals[5] = dgmT33S6(b);
            vals[6] = dgmT33S7(b);
            vals[7] = dgmT33S8(b);
            vals[8] = dgmT33S9(b);
            for (int c = 0; c < 9;
                 ++c) {
                if (vals[c] != CT33[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT33[c];
            }
        }
        for (int c = 0; c < 9; ++c)
            if (nT33[c] != eT33[c])
                ++bad;
        // the dgmWuJenMinInt pin
    if (dgmWuJenMinInt() != 13
        )
            ++bad;
        // the dgmWuJenBonusInt pin
    if (dgmWuJenBonusInt() != 15
        )
            ++bad;
        // the dgmWuJenBonusPct pin
    if (dgmWuJenBonusPct() != 10
        )
            ++bad;
        // the dgmWuJenHitDie pin
    if (dgmWuJenHitDie() != 4
        )
            ++bad;
        // the dgmWuJenHpBonusPerDie pin
    if (dgmWuJenHpBonusPerDie() != 1
        )
            ++bad;
        // the dgmWuJenHpPerLevelMin pin
    if (dgmWuJenHpPerLevelMin() != 2
        )
            ++bad;
        // the dgmWuJenHpPerLevelMax pin
    if (dgmWuJenHpPerLevelMax() != 5
        )
            ++bad;
        // the dgmWuJenSlots pin
    if (dgmWuJenSlots() != 6
        )
            ++bad;
        // the dgmWuJenFavoredBonus pin
    if (dgmWuJenFavoredBonus() != 1
        )
            ++bad;
        // the dgmWuJenKiInitBonus pin
    if (dgmWuJenKiInitBonus() != 3
        )
            ++bad;
        // the dgmWuJenKiInitRounds pin
    if (dgmWuJenKiInitRounds() != 1
        )
            ++bad;
        // the dgmWuJenKiInitPerDay pin
    if (dgmWuJenKiInitPerDay() != 1
        )
            ++bad;
        // the dgmWuJenKiMaxEffectLevel pin
    if (dgmWuJenKiMaxEffectLevel() != 4
        )
            ++bad;
        // the dgmWuJenKiMaxEffectGap pin
    if (dgmWuJenKiMaxEffectGap() != 3
        )
            ++bad;
        // the dgmWuJenElementCount pin
    if (dgmWuJenElementCount() != 5
        )
            ++bad;
        // the dgmWuJenMasterEnemySaveMod pin
    if (dgmWuJenMasterEnemySaveMod() != -1
        )
            ++bad;
        // the dgmWuJenMasterDamageBonus pin
    if (dgmWuJenMasterDamageBonus() != 1
        )
            ++bad;
        // the dgmWuJenMasterSaveBonus pin
    if (dgmWuJenMasterSaveBonus() != 1
        )
            ++bad;
        // the dgmWuJenPupilLevel pin
    if (dgmWuJenPupilLevel() != 10
        )
            ++bad;
        // the dgmWuJenPupilDice pin
    if (dgmWuJenPupilDice() != 4
        )
            ++bad;
        // the dgmWuJenPupilLeaveDiv pin
    if (dgmWuJenPupilLeaveDiv() != 2
        )
            ++bad;
        // the dgmWuJenTenguOniReaction pin
    if (dgmWuJenTenguOniReaction() != 20
        )
            ++bad;
        // the dgmWuJenTabooFirstLevel pin
    if (dgmWuJenTabooFirstLevel() != 1
        )
            ++bad;
        // the dgmWuJenTabooStepLevels pin
    if (dgmWuJenTabooStepLevels() != 5
        )
            ++bad;
        // the dgmT31RowCount pin
    if (dgmT31RowCount() != 11
        )
            ++bad;
        // the dgmT31XpBeyond pin
    if (dgmT31XpBeyond() != 300000
        )
            ++bad;
        // the dgmT31HpBeyond pin
    if (dgmT31HpBeyond() != 1
        )
            ++bad;
        // the dgmT32RowCount pin
    if (dgmT32RowCount() != 7
        )
            ++bad;
        // the dgmT32MaxAll pin
    if (dgmT32MaxAll() != -1
        )
            ++bad;
        // the dgmT33RowCount pin
    if (dgmT33RowCount() != 29
        )
            ++bad;
        // the dgmT33SpellLevels pin
    if (dgmT33SpellLevels() != 9
        )
            ++bad;
        // the dgmWuJenNeverLawful pin
    if (dgmWuJenNeverLawful() != 1
        )
            ++bad;
        // the dgmWuJenRaces pin
    if (dgmWuJenRaces() != 1
        )
            ++bad;
        // the dgmWuJenMagicUserTables pin
    if (dgmWuJenMagicUserTables() != 1
        )
            ++bad;
        // the dgmWuJenNoArmor pin
    if (dgmWuJenNoArmor() != 1
        )
            ++bad;
        // the dgmWuJenMeditates pin
    if (dgmWuJenMeditates() != 1
        )
            ++bad;
        // the dgmWuJenUnderstandKnowMemorize pin
    if (dgmWuJenUnderstandKnowMemorize() != 1
        )
            ++bad;
        // the dgmWuJenIntLossRecheck pin
    if (dgmWuJenIntLossRecheck() != 1
        )
            ++bad;
        // the dgmWuJenScrollDestroyed pin
    if (dgmWuJenScrollDestroyed() != 1
        )
            ++bad;
        // the dgmWuJenMasterLostOnNewLevel pin
    if (dgmWuJenMasterLostOnNewLevel() != 1
        )
            ++bad;
        // the dgmWuJenStrongholdWithLieutenant pin
    if (dgmWuJenStrongholdWithLieutenant() != 1
        )
            ++bad;
        // the dgmWuJenTenguOniLanguage pin
    if (dgmWuJenTenguOniLanguage() != 1
        )
            ++bad;
        // the dgmWuJenNoFamily pin
    if (dgmWuJenNoFamily() != 1
        )
            ++bad;
        // the dgmWuJenLightHonor pin
    if (dgmWuJenLightHonor() != 1
        )
            ++bad;
        // the dgmWuJenTabooConsequences pin
    if (dgmWuJenTabooConsequences() != 1
        )
            ++bad;
        // the T31 first row - 2,000 xp, one die (capture p. 47)
    if (dgmT31XpMax(0) != 2000
            || dgmT31Dice(0) != 1
            || dgmT31HpBonus(0) != 0
        )
            ++bad;
        // the T31 row-2 bound settled at 4,000 - the capture lost the comma
        // (capture pp. 47-48)
    if (dgmT31XpMax(1) != 4000
            || dgmT31XpMax(2) != 8000
        )
            ++bad;
        // the T31 capstone - 800,000 xp, nine dice plus two, eleven rows only
        // (capture p. 48)
    if (dgmT31XpMax(10) != 800000
            || dgmT31Dice(10) != 9
            || dgmT31HpBonus(10) != 2
        )
            ++bad;
        // the T32 ladder - 35 percent at Int 9, the 7-and-11 Hideyori tier
        // (capture pp. 48, 50)
    if (dgmT32KnowPct(0) != 35
            || dgmT32KnowPct(3) != 65
            || dgmT32MinSpells(3) != 7
            || dgmT32MaxSpells(3) != 11
        )
            ++bad;
        // the T32 All maximum - the 19-or-more row pins as the -1 code
        // (capture p. 48)
    if (dgmT32KnowPct(6) != 95
            || dgmT32MaxSpells(6) != dgmT32MaxAll()
        )
            ++bad;
        // the T33 row-5 cell settled - three 1st-level spells at 5th, the
        // capture printed 4 (capture p. 49)
    if (dgmT33S1(4) != 3
            || dgmT33S1(5) != 4
        )
            ++bad;
        // the T33 row-22 cell settled - one 9th-level spell at 22nd, the
        // capture printed 2 (capture p. 49)
    if (dgmT33S9(20) != 1
            || dgmT33S9(21) != 1
            || dgmT33S9(22) != 2
        )
            ++bad;
        // the T33 openings - the 3rd at 5th, the 5th at 9th, the 9th at 21st
        // (capture p. 49)
    if (dgmT33S3(4) != 1
            || dgmT33S5(8) != 1
            || dgmT33S9(20) != 1
        )
            ++bad;
        // the T33 capstone - the 29th-level row (capture p. 49)
    if (dgmT33S1(28) != 9
            || dgmT33S6(28) != 7
            || dgmT33S9(28) != 4
        )
            ++bad;
        // the maximum-effect ki - a 4th-level wu jen casts a 1st-level spell
        // at maximum effect, the gap is three levels (capture p. 50)
    if (dgmWuJenKiMaxEffectLevel() - dgmWuJenKiMaxEffectGap() != 1
        )
            ++bad;
        // the taboo ladder - one at 1st, another per five levels (capture p.
        // 51)
    if (dgmWuJenTabooFirstLevel() != 1
            || dgmWuJenTabooStepLevels() != 5
        )
            ++bad;
        printf("R626 OA wu jen audit: bad %d\n", bad);
        if (bad) return 1;
    }
