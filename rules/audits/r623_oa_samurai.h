    // ---- R623 OA samurai audit ----
    // OA round ten (capture pp. 39-42): the samurai - the minima, the caste
    // birth doctrine, the ki powers, the stewardships with the follower
    // doctrines, the bushido precepts and the ronin
    {
        using namespace rules;
        int bad = 0;
    if (dgjSamuraiMinStr() != 13
            || dgjSamuraiMinWis() != 13
            || dgjSamuraiMinCon() != 13
            || dgjSamuraiMinInt() != 14
            || dgjSamuraiHitDie() != 10
            || dgjSamuraiSlots() != 5
            || dgjSamuraiBirthBonus() != 10
            || dgjSamuraiHorseLevel() != 2
            || dgjSamuraiBowLevel() != 3
            || dgjSamuraiArtsLevel() != 6
            || dgjSamuraiArtsCount() != 3
            || dgjSamuraiKiLevel() != 1
            || dgjSamuraiKiRounds() != 1
            || dgjSamuraiKiPerDayMult() != 1
            || dgjSamuraiDmgBaseLevel() != 2
            || dgjSamuraiDmgBase() != 1
            || dgjSamuraiDmgStepLevels() != 3
            || dgjSamuraiSurpriseLevel() != 3
            || dgjSamuraiSurpriseRoll() != 1
            || dgjSamuraiFearImmuneLevel() != 5
            || dgjSamuraiAppFearLevel() != 6
            || dgjSamuraiAppFearHdMax() != 1
            || dgjSamuraiJitoLevel() != 7
            || dgjSamuraiJitoTaxShareDiv() != 4
            || dgjSamuraiJitoBushi() != 10
            || dgjSamuraiJitoSamuraiMin() != 1
            || dgjSamuraiJitoSamuraiMax() != 4
            || dgjSamuraiJitoFollowerLevelMin() != 1
            || dgjSamuraiJitoFollowerLevelMax() != 3
            || dgjSamuraiShugoLevel() != 8
            || dgjSamuraiShugoBushiDice() != 10
            || dgjSamuraiShugoNinjaPct() != 20
            || dgjSamuraiSamuraiLevel() != 9
            || dgjSamuraiSamuraiDice() != 10
            || dgjSamuraiSpecialistMin() != 2
            || dgjSamuraiSpecialistMax() != 7
            || dgjSamuraiSpecialistNinjaPct() != 10
            || dgjSamuraiGreatKiaiLevel() != 9
            || dgjSamuraiGreatKiaiRounds() != 2
            || dgjSamuraiGreatKiaiRadius() != 10
            || dgjSamuraiGreatKiaiStunRounds() != 1
            || dgjSamuraiRoninXpMult() != 2
            || dgjT25RowCount() != 12
            || dgjT25XpBeyond() != 300000
            || dgjT25HpBeyond() != 2
            || !dgjSamuraiLawfulOnly()
            || !dgjSamuraiFighterTables()
            || !dgjSamuraiNoPrimeBonus()
            || !dgjSamuraiKatanaRequired()
            || !dgjSamuraiTwoWeaponOnly()
            || !dgjSamuraiAnyArmorNoShield()
            || !dgjSamuraiNinjaWeaponsHonorLoss()
            || !dgjSamuraiHighestCaste()
            || !dgjSamuraiKorobokuruSponsor()
            || !dgjSamuraiKorobokuruBushi()
            || !dgjSamuraiKiStrength1800()
            || !dgjSamuraiAppFearControllable()
            || !dgjSamuraiAppFearSaveAllowed()
            || !dgjSamuraiJitoOptional()
            || !dgjSamuraiJitoDaimyoLoyal()
            || !dgjSamuraiJitoRetained()
            || !dgjSamuraiJitoDaimyoProperty()
            || !dgjSamuraiOneNinjaPerHousehold()
            || !dgjSamuraiShugoLoyalWhilePaid()
            || !dgjSamuraiFollowersAbsoluteLoyal()
            || !dgjSamuraiGreatKiaiOnceDaily()
            || !dgjSamuraiGreatKiaiExcludesKi()
            || !dgjSamuraiGreatKiaiStunEffects()
            || !dgjSamuraiBushidoPrecepts()
            || !dgjSamuraiRoninDemotion()
            || !dgjSamuraiRoninRetainsAbilities()
            || !dgjSamuraiRoninReturnable()
        )
            ++bad;
        // the Table 25 grid: the xp bounds, the accumulated dice plus bonus
        // and the damage ladder (capture pp. 39-40)
        int CT25[12][4] = {
            {2500,1,0,0},
            {5000,2,0,1},
            {10000,3,0,1},
            {18000,4,0,1},
            {36500,5,0,2},
            {75000,6,0,2},
            {135000,7,0,2},
            {235000,8,0,3},
            {400000,9,0,3},
            {650000,9,2,3},
            {1000000,9,4,4},
            {1300000,9,6,4},
            };
        int nT25[4] = {0,0,0,0};
        int eT25[4] = {0,0,0,0};
        for (int b = 0;
             b < dgjT25RowCount();
             ++b) {
            int vals[4];
            vals[0] = dgjT25XpMax(b);
            vals[1] = dgjT25Dice(b);
            vals[2] = dgjT25HpBonus(b);
            vals[3] = dgjT25Dmg(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CT25[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT25[c];
            }
        }
        for (int c = 0; c < 4; ++c)
            if (nT25[c] != eT25[c])
                ++bad;
        // the dgjSamuraiMinStr pin
    if (dgjSamuraiMinStr() != 13
        )
            ++bad;
        // the dgjSamuraiMinWis pin
    if (dgjSamuraiMinWis() != 13
        )
            ++bad;
        // the dgjSamuraiMinCon pin
    if (dgjSamuraiMinCon() != 13
        )
            ++bad;
        // the dgjSamuraiMinInt pin
    if (dgjSamuraiMinInt() != 14
        )
            ++bad;
        // the dgjSamuraiHitDie pin
    if (dgjSamuraiHitDie() != 10
        )
            ++bad;
        // the dgjSamuraiSlots pin
    if (dgjSamuraiSlots() != 5
        )
            ++bad;
        // the dgjSamuraiBirthBonus pin
    if (dgjSamuraiBirthBonus() != 10
        )
            ++bad;
        // the dgjSamuraiHorseLevel pin
    if (dgjSamuraiHorseLevel() != 2
        )
            ++bad;
        // the dgjSamuraiBowLevel pin
    if (dgjSamuraiBowLevel() != 3
        )
            ++bad;
        // the dgjSamuraiArtsLevel pin
    if (dgjSamuraiArtsLevel() != 6
        )
            ++bad;
        // the dgjSamuraiArtsCount pin
    if (dgjSamuraiArtsCount() != 3
        )
            ++bad;
        // the dgjSamuraiKiLevel pin
    if (dgjSamuraiKiLevel() != 1
        )
            ++bad;
        // the dgjSamuraiKiRounds pin
    if (dgjSamuraiKiRounds() != 1
        )
            ++bad;
        // the dgjSamuraiKiPerDayMult pin
    if (dgjSamuraiKiPerDayMult() != 1
        )
            ++bad;
        // the dgjSamuraiDmgBaseLevel pin
    if (dgjSamuraiDmgBaseLevel() != 2
        )
            ++bad;
        // the dgjSamuraiDmgBase pin
    if (dgjSamuraiDmgBase() != 1
        )
            ++bad;
        // the dgjSamuraiDmgStepLevels pin
    if (dgjSamuraiDmgStepLevels() != 3
        )
            ++bad;
        // the dgjSamuraiSurpriseLevel pin
    if (dgjSamuraiSurpriseLevel() != 3
        )
            ++bad;
        // the dgjSamuraiSurpriseRoll pin
    if (dgjSamuraiSurpriseRoll() != 1
        )
            ++bad;
        // the dgjSamuraiFearImmuneLevel pin
    if (dgjSamuraiFearImmuneLevel() != 5
        )
            ++bad;
        // the dgjSamuraiAppFearLevel pin
    if (dgjSamuraiAppFearLevel() != 6
        )
            ++bad;
        // the dgjSamuraiAppFearHdMax pin
    if (dgjSamuraiAppFearHdMax() != 1
        )
            ++bad;
        // the dgjSamuraiJitoLevel pin
    if (dgjSamuraiJitoLevel() != 7
        )
            ++bad;
        // the dgjSamuraiJitoTaxShareDiv pin
    if (dgjSamuraiJitoTaxShareDiv() != 4
        )
            ++bad;
        // the dgjSamuraiJitoBushi pin
    if (dgjSamuraiJitoBushi() != 10
        )
            ++bad;
        // the dgjSamuraiJitoSamuraiMin pin
    if (dgjSamuraiJitoSamuraiMin() != 1
        )
            ++bad;
        // the dgjSamuraiJitoSamuraiMax pin
    if (dgjSamuraiJitoSamuraiMax() != 4
        )
            ++bad;
        // the dgjSamuraiJitoFollowerLevelMin pin
    if (dgjSamuraiJitoFollowerLevelMin() != 1
        )
            ++bad;
        // the dgjSamuraiJitoFollowerLevelMax pin
    if (dgjSamuraiJitoFollowerLevelMax() != 3
        )
            ++bad;
        // the dgjSamuraiShugoLevel pin
    if (dgjSamuraiShugoLevel() != 8
        )
            ++bad;
        // the dgjSamuraiShugoBushiDice pin
    if (dgjSamuraiShugoBushiDice() != 10
        )
            ++bad;
        // the dgjSamuraiShugoNinjaPct pin
    if (dgjSamuraiShugoNinjaPct() != 20
        )
            ++bad;
        // the dgjSamuraiSamuraiLevel pin
    if (dgjSamuraiSamuraiLevel() != 9
        )
            ++bad;
        // the dgjSamuraiSamuraiDice pin
    if (dgjSamuraiSamuraiDice() != 10
        )
            ++bad;
        // the dgjSamuraiSpecialistMin pin
    if (dgjSamuraiSpecialistMin() != 2
        )
            ++bad;
        // the dgjSamuraiSpecialistMax pin
    if (dgjSamuraiSpecialistMax() != 7
        )
            ++bad;
        // the dgjSamuraiSpecialistNinjaPct pin
    if (dgjSamuraiSpecialistNinjaPct() != 10
        )
            ++bad;
        // the dgjSamuraiGreatKiaiLevel pin
    if (dgjSamuraiGreatKiaiLevel() != 9
        )
            ++bad;
        // the dgjSamuraiGreatKiaiRounds pin
    if (dgjSamuraiGreatKiaiRounds() != 2
        )
            ++bad;
        // the dgjSamuraiGreatKiaiRadius pin
    if (dgjSamuraiGreatKiaiRadius() != 10
        )
            ++bad;
        // the dgjSamuraiGreatKiaiStunRounds pin
    if (dgjSamuraiGreatKiaiStunRounds() != 1
        )
            ++bad;
        // the dgjSamuraiRoninXpMult pin
    if (dgjSamuraiRoninXpMult() != 2
        )
            ++bad;
        // the dgjT25RowCount pin
    if (dgjT25RowCount() != 12
        )
            ++bad;
        // the dgjT25XpBeyond pin
    if (dgjT25XpBeyond() != 300000
        )
            ++bad;
        // the dgjT25HpBeyond pin
    if (dgjT25HpBeyond() != 2
        )
            ++bad;
        // the dgjSamuraiLawfulOnly pin
    if (dgjSamuraiLawfulOnly() != 1
        )
            ++bad;
        // the dgjSamuraiFighterTables pin
    if (dgjSamuraiFighterTables() != 1
        )
            ++bad;
        // the dgjSamuraiNoPrimeBonus pin
    if (dgjSamuraiNoPrimeBonus() != 1
        )
            ++bad;
        // the dgjSamuraiKatanaRequired pin
    if (dgjSamuraiKatanaRequired() != 1
        )
            ++bad;
        // the dgjSamuraiTwoWeaponOnly pin
    if (dgjSamuraiTwoWeaponOnly() != 1
        )
            ++bad;
        // the dgjSamuraiAnyArmorNoShield pin
    if (dgjSamuraiAnyArmorNoShield() != 1
        )
            ++bad;
        // the dgjSamuraiNinjaWeaponsHonorLoss pin
    if (dgjSamuraiNinjaWeaponsHonorLoss() != 1
        )
            ++bad;
        // the dgjSamuraiHighestCaste pin
    if (dgjSamuraiHighestCaste() != 1
        )
            ++bad;
        // the dgjSamuraiKorobokuruSponsor pin
    if (dgjSamuraiKorobokuruSponsor() != 1
        )
            ++bad;
        // the dgjSamuraiKorobokuruBushi pin
    if (dgjSamuraiKorobokuruBushi() != 1
        )
            ++bad;
        // the dgjSamuraiKiStrength1800 pin
    if (dgjSamuraiKiStrength1800() != 1
        )
            ++bad;
        // the dgjSamuraiAppFearControllable pin
    if (dgjSamuraiAppFearControllable() != 1
        )
            ++bad;
        // the dgjSamuraiAppFearSaveAllowed pin
    if (dgjSamuraiAppFearSaveAllowed() != 1
        )
            ++bad;
        // the dgjSamuraiJitoOptional pin
    if (dgjSamuraiJitoOptional() != 1
        )
            ++bad;
        // the dgjSamuraiJitoDaimyoLoyal pin
    if (dgjSamuraiJitoDaimyoLoyal() != 1
        )
            ++bad;
        // the dgjSamuraiJitoRetained pin
    if (dgjSamuraiJitoRetained() != 1
        )
            ++bad;
        // the dgjSamuraiJitoDaimyoProperty pin
    if (dgjSamuraiJitoDaimyoProperty() != 1
        )
            ++bad;
        // the dgjSamuraiOneNinjaPerHousehold pin
    if (dgjSamuraiOneNinjaPerHousehold() != 1
        )
            ++bad;
        // the dgjSamuraiShugoLoyalWhilePaid pin
    if (dgjSamuraiShugoLoyalWhilePaid() != 1
        )
            ++bad;
        // the dgjSamuraiFollowersAbsoluteLoyal pin
    if (dgjSamuraiFollowersAbsoluteLoyal() != 1
        )
            ++bad;
        // the dgjSamuraiGreatKiaiOnceDaily pin
    if (dgjSamuraiGreatKiaiOnceDaily() != 1
        )
            ++bad;
        // the dgjSamuraiGreatKiaiExcludesKi pin
    if (dgjSamuraiGreatKiaiExcludesKi() != 1
        )
            ++bad;
        // the dgjSamuraiGreatKiaiStunEffects pin
    if (dgjSamuraiGreatKiaiStunEffects() != 1
        )
            ++bad;
        // the dgjSamuraiBushidoPrecepts pin
    if (dgjSamuraiBushidoPrecepts() != 1
        )
            ++bad;
        // the dgjSamuraiRoninDemotion pin
    if (dgjSamuraiRoninDemotion() != 1
        )
            ++bad;
        // the dgjSamuraiRoninRetainsAbilities pin
    if (dgjSamuraiRoninRetainsAbilities() != 1
        )
            ++bad;
        // the dgjSamuraiRoninReturnable pin
    if (dgjSamuraiRoninReturnable() != 1
        )
            ++bad;
        // the T25 first row - 2,500 xp, one die, no bonuses (capture p. 40)
    if (dgjT25XpMax(0) != 2500
            || dgjT25Dice(0) != 1
            || dgjT25HpBonus(0) != 0
            || dgjT25Dmg(0) != 0
        )
            ++bad;
        // the T25 capstone - 1,300,000 xp, nine dice plus six, +4 damage
        // (capture p. 40)
    if (dgjT25XpMax(11) != 1300000
            || dgjT25Dice(11) != 9
            || dgjT25HpBonus(11) != 6
            || dgjT25Dmg(11) != 4
        )
            ++bad;
        // the T25 9-plus-N cells open on the 10th-level row (capture p. 40)
    if (dgjT25Dice(9) != 9
            || dgjT25HpBonus(9) != 2
        )
            ++bad;
        // the T25 damage ladder agrees with the prose - +2 at 5th, +3 at 8th
        // (capture pp. 39-41)
    if (dgjT25Dmg(4) != 2
            || dgjT25Dmg(7) != 3
            || dgjSamuraiDmgStepLevels() != 3
        )
            ++bad;
        // the T25 beyond-10th hp step and the beyond-12th xp step (capture p.
        // 40)
    if (dgjT25HpBeyond() != 2
            || dgjT25XpBeyond() != 300000
        )
            ++bad;
        // the ki ladder - the printed 7th-level example uses the ki seven
        // times in a day (capture p. 41)
    if (dgjSamuraiKiPerDayMult() * 7 != 7
        )
            ++bad;
        // the jito grant - 10 bushi plus one to four samurai of 1st to 3rd
        // (capture p. 41)
    if (dgjSamuraiJitoBushi() != 10
            || dgjSamuraiJitoSamuraiMin() != 1
            || dgjSamuraiJitoSamuraiMax() != 4
        )
            ++bad;
        // the 9th-level followers - 2d10 samurai and the 2-7 specialists
        // (capture p. 41)
    if (dgjSamuraiSamuraiDice() != 10
            || dgjSamuraiSpecialistMin() != 2
            || dgjSamuraiSpecialistMax() != 7
        )
            ++bad;
        printf("R623 OA samurai audit: bad %d\n", bad);
        if (bad) return 1;
    }
