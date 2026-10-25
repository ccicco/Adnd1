    // ---- R728 OA monsters Oni audit ----
    // OA round one hundred fifteen (capture pp. 280-281): the Chapter 12
    // monster roster - the oni, the three-column stat grid of the common, the
    // go-zu, and the me-zu riding together with the fearsome spirit
    // descriptions, the capture misreads pinned against the print,
    // single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dkpOniCount() != 3
            || dkpCommonRegenPerRound() != 3
            || dkpCommonSummonDice() != 10
            || dkpCommonSummonChancePct() != 10
            || dkpLairGuardDice() != 10
            || dkpGoZuHeightMinFt() != 8
            || dkpGoZuHeightMaxFt() != 9
            || dkpPolymorphSelfPerDay() != 3
            || dkpFlyPerDay() != 3
            || dkpInvisiblePerDay() != 2
            || dkpCloudTrapezePerDay() != 1
            || !dkpCommonOniCommon()
            || !dkpGoZuVeryRare()
            || !dkpMeZuVeryRare()
            || !dkpCommonChaoticEvil()
            || !dkpGoZuMeZuLawfulNeutral()
            || !dkpCommonIntAverage()
            || !dkpGoZuMeZuIntHigh()
            || !dkpSizeLarge()
            || !dkpPsionicNil()
            || !dkpModesNil()
            || !dkpCommonSpecialAttacksSpells()
            || !dkpGoZuMeZuSpecialSeeBelow()
            || !dkpCommonDefensesNil()
            || !dkpGoZuMeZuRegeneration()
            || !dkpCommonMRStandard()
            || !dkpFearsomeSpirits()
            || !dkpSevenToEightFeet()
            || !dkpOneToThreeEyes()
            || !dkpOneOrTwoHorns()
            || !dkpCoarseHairLimbs()
            || !dkpDirtyThickTalons()
            || !dkpSkinNormallyRed()
            || !dkpBlueSkinnedOgreMagi()
            || !dkpDressImitatesHumans()
            || !dkpCommonHaunts()
            || !dkpHighwayShrineTerror()
            || !dkpBloodthirstyCruel()
            || !dkpTwoHandedSwordOrClaws()
            || !dkpCauseFearAtWill()
            || !dkpCommandsLesserCreatures()
            || !dkpLairCourt()
            || !dkpCommonSpeaksFive()
            || !dkpGoZuBullHeads()
            || !dkpGoZuCelestialSoldiers()
            || !dkpGoZuMeZuEmperorsArmy()
            || !dkpGoZuOverseeLandsOfDead()
            || !dkpGoZuSoldierDress()
            || !dkpGoZuWeaponRoster()
            || !dkpGoZuTwoAttacksAndGore()
            || !dkpGoZuAtWillPowers()
            || !dkpGoZuCloudTrapezeTwicePerDay()
            || !dkpGoZuAutoDetectInvisible()
            || !dkpGoZuHillGiantStrength()
            || !dkpGoZuLanguages()
            || !dkpMeZuMostImportant()
            || !dkpMeZuHorseHeads()
            || !dkpMeZuHigherRank()
            || !dkpMeZuWhipsAndLassos()
            || !dkpMeZuAtWillPowers()
            || !dkpMeZuEtherealAstralTwicePerDay()
            || !dkpMeZuCloudTrapezeThricePerDay()
            || !dkpMeZuWuJenSpellcasting()
            || !dkpMeZuTrueSeeingAlways()
            || !dkpMeZuAnyLanguage()
            || !dkpMeZuStoneGiantStrength()
            || !dkpMeZuOnCelestialMission()
        )
            ++bad;
        // the dkpOni grid
        int COni[3][10] = {
            {1,100,4,9,8,0,2,0,650,10},
            {1,20,0,9,12,8,3,20,5250,16},
            {1,20,2,12,10,5,2,40,3150,14},
            };
        int nOni[10] = {0,0,0,0,0,0,0,0,0,0};
        int eOni[10] = {0,0,1,0,0,1,0,1,0,0};
        for (int b = 0;
             b < dkpOniCount();
             ++b) {
            int vals[10];
            vals[0] = dkpOniAppearMin(b);
            vals[1] = dkpOniAppearMax(b);
            vals[2] = dkpOniAC(b);
            vals[3] = dkpOniMove(b);
            vals[4] = dkpOniHD(b);
            vals[5] = dkpOniHDBonus(b);
            vals[6] = dkpOniAttacks(b);
            vals[7] = dkpOniMRPct(b);
            vals[8] = dkpOniXPBase(b);
            vals[9] = dkpOniXPPerHP(b);
            for (int c = 0; c < 10;
                 ++c) {
                if (vals[c] != COni[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nOni[c];
            }
        }
        for (int c = 0; c < 10; ++c)
            if (nOni[c] != eOni[c])
                ++bad;
        // the stat grid - the per-type lines, healthy values, each condition
        // false
    if (dkpCommonOniCommon() != 1
            || dkpGoZuVeryRare() != 1
            || dkpMeZuVeryRare() != 1
            || dkpCommonChaoticEvil() != 1
            || dkpGoZuMeZuLawfulNeutral() != 1
            || dkpCommonIntAverage() != 1
            || dkpGoZuMeZuIntHigh() != 1
            || dkpSizeLarge() != 1
            || dkpPsionicNil() != 1
            || dkpModesNil() != 1
            || dkpCommonSpecialAttacksSpells() != 1
            || dkpGoZuMeZuSpecialSeeBelow() != 1
            || dkpCommonDefensesNil() != 1
            || dkpGoZuMeZuRegeneration() != 1
            || dkpCommonMRStandard() != 1
        )
            ++bad;
        // the oni grid - the three-column stat table, audited cell by cell by
        // the table audit
    if (dkpOniCount() != 3
        )
            ++bad;
        // the fearsome spirit - the look and the dress, healthy values, each
        // condition false
    if (dkpFearsomeSpirits() != 1
            || dkpSevenToEightFeet() != 1
            || dkpOneToThreeEyes() != 1
            || dkpOneOrTwoHorns() != 1
            || dkpCoarseHairLimbs() != 1
            || dkpDirtyThickTalons() != 1
            || dkpSkinNormallyRed() != 1
            || dkpBlueSkinnedOgreMagi() != 1
            || dkpDressImitatesHumans() != 1
        )
            ++bad;
        // the common oni - the haunts, the powers, and the court, healthy
        // values, each condition false
    if (dkpCommonHaunts() != 1
            || dkpHighwayShrineTerror() != 1
            || dkpBloodthirstyCruel() != 1
            || dkpTwoHandedSwordOrClaws() != 1
            || dkpPolymorphSelfPerDay() != 3
            || dkpFlyPerDay() != 3
            || dkpInvisiblePerDay() != 2
            || dkpCloudTrapezePerDay() != 1
            || dkpCauseFearAtWill() != 1
            || dkpCommandsLesserCreatures() != 1
            || dkpCommonSummonChancePct() != 10
            || dkpCommonSummonDice() != 10
            || dkpLairCourt() != 1
            || dkpLairGuardDice() != 10
            || dkpCommonSpeaksFive() != 1
        )
            ++bad;
        // the go-zu oni - the bull-headed soldiers of the Celestial Empire,
        // healthy values, each condition false
    if (dkpGoZuBullHeads() != 1
            || dkpGoZuHeightMinFt() != 8
            || dkpGoZuHeightMaxFt() != 9
            || dkpGoZuCelestialSoldiers() != 1
            || dkpGoZuMeZuEmperorsArmy() != 1
            || dkpGoZuOverseeLandsOfDead() != 1
            || dkpGoZuSoldierDress() != 1
            || dkpGoZuWeaponRoster() != 1
            || dkpGoZuTwoAttacksAndGore() != 1
            || dkpGoZuAtWillPowers() != 1
            || dkpGoZuCloudTrapezeTwicePerDay() != 1
            || dkpGoZuAutoDetectInvisible() != 1
            || dkpCommonRegenPerRound() != 3
            || dkpGoZuHillGiantStrength() != 1
            || dkpGoZuLanguages() != 1
        )
            ++bad;
        // the me-zu oni - the horse-headed officers, healthy values, each
        // condition false
    if (dkpMeZuMostImportant() != 1
            || dkpMeZuHorseHeads() != 1
            || dkpMeZuHigherRank() != 1
            || dkpMeZuWhipsAndLassos() != 1
            || dkpMeZuAtWillPowers() != 1
            || dkpMeZuEtherealAstralTwicePerDay() != 1
            || dkpMeZuCloudTrapezeThricePerDay() != 1
            || dkpMeZuWuJenSpellcasting() != 1
            || dkpMeZuTrueSeeingAlways() != 1
            || dkpMeZuAnyLanguage() != 1
            || dkpMeZuStoneGiantStrength() != 1
            || dkpMeZuOnCelestialMission() != 1
        )
            ++bad;
        printf("R728 OA monsters Oni audit: bad %d\n", bad);
        if (bad) return 1;
    }
