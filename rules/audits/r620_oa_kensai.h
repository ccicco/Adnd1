    // ---- R620 OA kensai audit ----
    // OA round seven (capture pp. 28-31): the kensai - the dual prime
    // requisites, the natural AC formula and step, the initiative and ki
    // powers, the damage and to-hit ladders, the pupil and whirlwind powers,
    // the restrictions and practice, and the duel doctrine with the honor
    // demotion.
    {
        using namespace rules;
        int bad = 0;
    if (dggKensaiMinStr() != 12
            || dggKensaiMinWis() != 12
            || dggKensaiMinDex() != 14
            || dggKensaiHitDie() != 10
            || dggKensaiSlots() != 3
            || dggKensaiNaturalAcBase() != 23
            || dggKensaiAcStepLevels() != 3
            || dggKensaiInitBase() != 1
            || dggKensaiSaveBonus() != 1
            || dggKensaiDuelBonusVsOthers() != 2
            || dggKensaiDmgLevels() != 5
            || dggKensaiHitLevels() != 5
            || dggKensaiInitTwo() != 2
            || dggKensaiInitThree() != 3
            || dggKensaiMeditateLevel() != 4
            || dggKensaiSurpriseLevel() != 6
            || dggKensaiTwoWeaponsLevel() != 7
            || dggKensaiPupilDie() != 6
            || dggKensaiPupilDepartPct() != 5
            || dggKensaiPupilLossPct() != 50
            || dggKensaiWhirlwindLevel() != 11
            || dggKensaiWhirlwindRange() != 10
            || dggKensaiDuelXpMultiplier() != 2
            || dggKensaiPracticeHours() != 2
            || dggT18RowCount() != 12
            || dggT18XpBeyond() != 250000
            || dggT18HpBeyond() != 2
            || dggT19RowCount() != 12
            || dggT19SpecNone() != 0
            || dggT19SpecMeditate() != 1
            || dggT19SpecSurprise() != 2
            || dggT19SpecTwoWeapons() != 3
            || dggT19SpecPupils() != 4
            || dggT19SpecWhirlwind() != 5
            || !dggKensaiDualPrime()
            || !dggKensaiLawfulOnly()
            || !dggKensaiFighterTables()
            || !dggKensaiNinjaHonorUnless()
            || !dggKensaiNoDexAdjustments()
            || !dggKensaiKiMaxDamage()
            || !dggKensaiImmuneFear()
            || !dggKensaiPupilGain()
            || !dggKensaiWhirlwindCostsAllKi()
            || !dggKensaiNoMagicSpecialty()
            || !dggKensaiHalfXpOtherWeapon()
            || !dggKensaiDuelChallenge()
            || !dggKensaiDuelRefuseCost()
            || !dggKensaiDuelConditions()
            || !dggKensaiHonorDemotion()
            || !dggKensaiBirthRequired()
        )
            ++bad;
        // the Table 18 grid: the level xp bounds and the accumulated dice
        // plus bonus (capture pp. 28-29)
        int CT18[12][3] = {
            {3000,1,0},
            {5500,2,0},
            {10000,3,0},
            {22000,4,0},
            {44000,5,0},
            {88000,6,0},
            {150000,7,0},
            {250000,8,0},
            {500000,9,0},
            {750000,9,2},
            {1000000,9,4},
            {1250000,9,6},
            };
        for (int b = 0;
             b < dggT18RowCount();
             ++b) {
            int vals[3];
            vals[0] = dggT18XpMax(b);
            vals[1] = dggT18Dice(b);
            vals[2] = dggT18HpBonus(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CT18[b][c])
                    ++bad;
            }
        }
        // the Table 19 grid: the initiative, AC, damage and to-hit ladders
        // with the special power codes across levels 1-12+ (capture p. 30)
        int CT19[12][5] = {
            {1,0,0,0,0},
            {1,0,1,0,0},
            {1,1,1,1,0},
            {1,1,1,1,1},
            {2,1,2,2,0},
            {2,2,2,2,2},
            {2,2,2,2,3},
            {2,3,3,3,0},
            {3,3,3,3,4},
            {3,4,4,4,0},
            {3,4,4,4,5},
            {3,4,5,5,0},
            };
        for (int b = 0;
             b < dggT19RowCount();
             ++b) {
            int vals[5];
            vals[0] = dggT19Init(b);
            vals[1] = dggT19Ac(b);
            vals[2] = dggT19Dmg(b);
            vals[3] = dggT19Hit(b);
            vals[4] = dggT19Special(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CT19[b][c])
                    ++bad;
            }
        }
        // the dggKensaiDualPrime pin
    if (dggKensaiDualPrime() != 1
        )
            ++bad;
        // the dggKensaiMinStr pin
    if (dggKensaiMinStr() != 12
        )
            ++bad;
        // the dggKensaiMinWis pin
    if (dggKensaiMinWis() != 12
        )
            ++bad;
        // the dggKensaiMinDex pin
    if (dggKensaiMinDex() != 14
        )
            ++bad;
        // the dggKensaiLawfulOnly pin
    if (dggKensaiLawfulOnly() != 1
        )
            ++bad;
        // the dggKensaiHitDie pin
    if (dggKensaiHitDie() != 10
        )
            ++bad;
        // the dggKensaiFighterTables pin
    if (dggKensaiFighterTables() != 1
        )
            ++bad;
        // the dggKensaiNinjaHonorUnless pin
    if (dggKensaiNinjaHonorUnless() != 1
        )
            ++bad;
        // the dggKensaiSlots pin
    if (dggKensaiSlots() != 3
        )
            ++bad;
        // the dggKensaiNoDexAdjustments pin
    if (dggKensaiNoDexAdjustments() != 1
        )
            ++bad;
        // the dggKensaiNaturalAcBase pin
    if (dggKensaiNaturalAcBase() != 23
        )
            ++bad;
        // the dggKensaiAcStepLevels pin
    if (dggKensaiAcStepLevels() != 3
        )
            ++bad;
        // the dggKensaiInitBase pin
    if (dggKensaiInitBase() != 1
        )
            ++bad;
        // the dggKensaiSaveBonus pin
    if (dggKensaiSaveBonus() != 1
        )
            ++bad;
        // the dggKensaiKiMaxDamage pin
    if (dggKensaiKiMaxDamage() != 1
        )
            ++bad;
        // the dggKensaiDuelBonusVsOthers pin
    if (dggKensaiDuelBonusVsOthers() != 2
        )
            ++bad;
        // the dggKensaiImmuneFear pin
    if (dggKensaiImmuneFear() != 1
        )
            ++bad;
        // the dggKensaiDmgLevels pin
    if (dggKensaiDmgLevels() != 5
        )
            ++bad;
        // the dggKensaiHitLevels pin
    if (dggKensaiHitLevels() != 5
        )
            ++bad;
        // the dggKensaiInitTwo pin
    if (dggKensaiInitTwo() != 2
        )
            ++bad;
        // the dggKensaiInitThree pin
    if (dggKensaiInitThree() != 3
        )
            ++bad;
        // the dggKensaiMeditateLevel pin
    if (dggKensaiMeditateLevel() != 4
        )
            ++bad;
        // the dggKensaiSurpriseLevel pin
    if (dggKensaiSurpriseLevel() != 6
        )
            ++bad;
        // the dggKensaiTwoWeaponsLevel pin
    if (dggKensaiTwoWeaponsLevel() != 7
        )
            ++bad;
        // the dggKensaiPupilDie pin
    if (dggKensaiPupilDie() != 6
        )
            ++bad;
        // the dggKensaiPupilDepartPct pin
    if (dggKensaiPupilDepartPct() != 5
        )
            ++bad;
        // the dggKensaiPupilLossPct pin
    if (dggKensaiPupilLossPct() != 50
        )
            ++bad;
        // the dggKensaiPupilGain pin
    if (dggKensaiPupilGain() != 1
        )
            ++bad;
        // the dggKensaiWhirlwindLevel pin
    if (dggKensaiWhirlwindLevel() != 11
        )
            ++bad;
        // the dggKensaiWhirlwindRange pin
    if (dggKensaiWhirlwindRange() != 10
        )
            ++bad;
        // the dggKensaiWhirlwindCostsAllKi pin
    if (dggKensaiWhirlwindCostsAllKi() != 1
        )
            ++bad;
        // the dggKensaiNoMagicSpecialty pin
    if (dggKensaiNoMagicSpecialty() != 1
        )
            ++bad;
        // the dggKensaiHalfXpOtherWeapon pin
    if (dggKensaiHalfXpOtherWeapon() != 1
        )
            ++bad;
        // the dggKensaiDuelXpMultiplier pin
    if (dggKensaiDuelXpMultiplier() != 2
        )
            ++bad;
        // the dggKensaiPracticeHours pin
    if (dggKensaiPracticeHours() != 2
        )
            ++bad;
        // the dggKensaiDuelChallenge pin
    if (dggKensaiDuelChallenge() != 1
        )
            ++bad;
        // the dggKensaiDuelRefuseCost pin
    if (dggKensaiDuelRefuseCost() != 1
        )
            ++bad;
        // the dggKensaiDuelConditions pin
    if (dggKensaiDuelConditions() != 1
        )
            ++bad;
        // the dggKensaiHonorDemotion pin
    if (dggKensaiHonorDemotion() != 1
        )
            ++bad;
        // the dggKensaiBirthRequired pin
    if (dggKensaiBirthRequired() != 1
        )
            ++bad;
        // the dggT18RowCount pin
    if (dggT18RowCount() != 12
        )
            ++bad;
        // the dggT18XpBeyond pin
    if (dggT18XpBeyond() != 250000
        )
            ++bad;
        // the dggT18HpBeyond pin
    if (dggT18HpBeyond() != 2
        )
            ++bad;
        // the dggT19RowCount pin
    if (dggT19RowCount() != 12
        )
            ++bad;
        // the dggT19SpecNone pin
    if (dggT19SpecNone() != 0
        )
            ++bad;
        // the dggT19SpecMeditate pin
    if (dggT19SpecMeditate() != 1
        )
            ++bad;
        // the dggT19SpecSurprise pin
    if (dggT19SpecSurprise() != 2
        )
            ++bad;
        // the dggT19SpecTwoWeapons pin
    if (dggT19SpecTwoWeapons() != 3
        )
            ++bad;
        // the dggT19SpecPupils pin
    if (dggT19SpecPupils() != 4
        )
            ++bad;
        // the dggT19SpecWhirlwind pin
    if (dggT19SpecWhirlwind() != 5
        )
            ++bad;
        // the natural AC formula - Dex 16 gives AC 7 (capture p. 29)
    if (dggKensaiNaturalAcBase() - 16 != 7
        )
            ++bad;
        // the T19 capstones - initiative +3, AC +4, damage and hit +5
        // (capture p. 30)
    if (dggT19Init(11) != 3
            || dggT19Ac(11) != 4
            || dggT19Dmg(11) != 5
            || dggT19Hit(11) != 5
        )
            ++bad;
        // the T18 level-10 row - nine dice plus the 2 bonus (capture p. 29)
    if (dggT18Dice(9) != 9
            || dggT18HpBonus(9) != 2
        )
            ++bad;
        // the whirlwind special sits at level 11 (capture p. 30)
    if (dggT19Special(10) != 5
        )
            ++bad;
        // the kensai and bushi beyond-9th hp steps agree (capture pp. 27, 29)
    if (dggT18HpBeyond() != 2
        )
            ++bad;
        // the duel multiplier doubles (capture p. 31)
    if (dggKensaiDuelXpMultiplier() != 2
        )
            ++bad;
        printf("R620 OA kensai audit: bad %d\n", bad);
        if (bad) return 1;
    }
