    // ---- R628 OA character abilities audit ----
    // OA round fifteen (capture pp. 55-59): the character abilities chapter
    // opener - the multiple attacks, the dual-class doctrine, the alignment
    // doctrine and the languages
    {
        using namespace rules;
        int bad = 0;
    if (dgoT36RowCount() != 19
            || dgoDualOldClassReqMin() != 15
            || dgoDualNewClassReqMin() != 17
            || dgoAlignCount() != 9
            || dgoLangSlotHome() != 1
            || dgoLangSlotTrade() != 2
            || dgoLangSlotAlignment() != 3
            || dgoLangDialectComprehension() != 75
            || dgoLangWildComprehension() != 50
            || dgoLangStudyMonthsBase() != 20
            || !dgoT36ExtendsBeyondFighters()
            || !dgoT36NinjaNinjaWeaponsOnly()
            || !dgoT36NinjaOtherClassNoCarry()
            || !dgoT36MeleeOnly()
            || !dgoT36ProficiencyIncreases()
            || !dgoT36OnePerLevelVsWeak()
            || !dgoT36SplitBetweenTargets()
            || !dgoDualHumanOnly()
            || !dgoDualAnyLevel()
            || !dgoDualKeepsOldAbilities()
            || !dgoDualNewClassFirstLevel()
            || !dgoDualXpToNewClass()
            || !dgoDualNeverAdvanceOld()
            || !dgoDualNoHpUntilSurpass()
            || !dgoDualRestrictionsUntilSurpass()
            || !dgoDualOldUseForfeitsXp()
            || !dgoDualBestTables()
            || !dgoDualFreeMixAfterSurpass()
            || !dgoDualWeaponsException()
            || !dgoAlignNotReligion()
            || !dgoAlignLawMostCommon()
            || !dgoAlignEncourageComplement()
            || !dgoLangPotentialOnly()
            || !dgoLangHomeCounts()
            || !dgoLangSecondIsTrade()
            || !dgoLangThirdIsAlignment()
            || !dgoLangTradeBusinessOnly()
            || !dgoLangNonHumanSpecial()
            || !dgoLangEveryOtherDayDoubles()
            || !dgoLangNativeSpeakersHalve()
            || !dgoLangAlwaysAccent()
            || !dgoLangNuancesNativeOnly()
        )
            ++bad;
        // the Table 36 grid: the class codes, level bands and the attack
        // rates (capture p. 55)
        int CT36[19][5] = {
            {1,1,5,1,1},
            {1,6,10,3,2},
            {1,11,-1,2,1},
            {2,1,3,1,1},
            {2,4,7,3,2},
            {2,8,14,2,1},
            {2,15,-1,5,2},
            {3,1,6,1,1},
            {3,7,14,3,2},
            {3,15,-1,2,1},
            {4,1,6,1,1},
            {4,7,12,3,2},
            {4,13,-1,2,1},
            {5,1,4,1,1},
            {5,5,8,3,2},
            {5,9,-1,2,1},
            {6,1,6,1,1},
            {6,7,12,3,2},
            {6,13,-1,2,1},
            };
        int nT36[5] = {0,0,0,0,0};
        int eT36[5] = {0,0,0,0,0};
        for (int b = 0;
             b < dgoT36RowCount();
             ++b) {
            int vals[5];
            vals[0] = dgoT36Class(b);
            vals[1] = dgoT36LevelLo(b);
            vals[2] = dgoT36LevelHi(b);
            vals[3] = dgoT36AtkNum(b);
            vals[4] = dgoT36AtkDen(b);
            for (int c = 0; c < 5;
                 ++c) {
                if (vals[c] != CT36[b][c])
                    ++bad;
                if (vals[c] == -99)
                    ++nT36[c];
            }
        }
        for (int c = 0; c < 5; ++c)
            if (nT36[c] != eT36[c])
                ++bad;
        // the dgoT36RowCount pin
    if (dgoT36RowCount() != 19
        )
            ++bad;
        // the dgoDualOldClassReqMin pin
    if (dgoDualOldClassReqMin() != 15
        )
            ++bad;
        // the dgoDualNewClassReqMin pin
    if (dgoDualNewClassReqMin() != 17
        )
            ++bad;
        // the dgoAlignCount pin
    if (dgoAlignCount() != 9
        )
            ++bad;
        // the dgoLangSlotHome pin
    if (dgoLangSlotHome() != 1
        )
            ++bad;
        // the dgoLangSlotTrade pin
    if (dgoLangSlotTrade() != 2
        )
            ++bad;
        // the dgoLangSlotAlignment pin
    if (dgoLangSlotAlignment() != 3
        )
            ++bad;
        // the dgoLangDialectComprehension pin
    if (dgoLangDialectComprehension() != 75
        )
            ++bad;
        // the dgoLangWildComprehension pin
    if (dgoLangWildComprehension() != 50
        )
            ++bad;
        // the dgoLangStudyMonthsBase pin
    if (dgoLangStudyMonthsBase() != 20
        )
            ++bad;
        // the dgoT36ExtendsBeyondFighters pin
    if (dgoT36ExtendsBeyondFighters() != 1
        )
            ++bad;
        // the dgoT36NinjaNinjaWeaponsOnly pin
    if (dgoT36NinjaNinjaWeaponsOnly() != 1
        )
            ++bad;
        // the dgoT36NinjaOtherClassNoCarry pin
    if (dgoT36NinjaOtherClassNoCarry() != 1
        )
            ++bad;
        // the dgoT36MeleeOnly pin
    if (dgoT36MeleeOnly() != 1
        )
            ++bad;
        // the dgoT36ProficiencyIncreases pin
    if (dgoT36ProficiencyIncreases() != 1
        )
            ++bad;
        // the dgoT36OnePerLevelVsWeak pin
    if (dgoT36OnePerLevelVsWeak() != 1
        )
            ++bad;
        // the dgoT36SplitBetweenTargets pin
    if (dgoT36SplitBetweenTargets() != 1
        )
            ++bad;
        // the dgoDualHumanOnly pin
    if (dgoDualHumanOnly() != 1
        )
            ++bad;
        // the dgoDualAnyLevel pin
    if (dgoDualAnyLevel() != 1
        )
            ++bad;
        // the dgoDualKeepsOldAbilities pin
    if (dgoDualKeepsOldAbilities() != 1
        )
            ++bad;
        // the dgoDualNewClassFirstLevel pin
    if (dgoDualNewClassFirstLevel() != 1
        )
            ++bad;
        // the dgoDualXpToNewClass pin
    if (dgoDualXpToNewClass() != 1
        )
            ++bad;
        // the dgoDualNeverAdvanceOld pin
    if (dgoDualNeverAdvanceOld() != 1
        )
            ++bad;
        // the dgoDualNoHpUntilSurpass pin
    if (dgoDualNoHpUntilSurpass() != 1
        )
            ++bad;
        // the dgoDualRestrictionsUntilSurpass pin
    if (dgoDualRestrictionsUntilSurpass() != 1
        )
            ++bad;
        // the dgoDualOldUseForfeitsXp pin
    if (dgoDualOldUseForfeitsXp() != 1
        )
            ++bad;
        // the dgoDualBestTables pin
    if (dgoDualBestTables() != 1
        )
            ++bad;
        // the dgoDualFreeMixAfterSurpass pin
    if (dgoDualFreeMixAfterSurpass() != 1
        )
            ++bad;
        // the dgoDualWeaponsException pin
    if (dgoDualWeaponsException() != 1
        )
            ++bad;
        // the dgoAlignNotReligion pin
    if (dgoAlignNotReligion() != 1
        )
            ++bad;
        // the dgoAlignLawMostCommon pin
    if (dgoAlignLawMostCommon() != 1
        )
            ++bad;
        // the dgoAlignEncourageComplement pin
    if (dgoAlignEncourageComplement() != 1
        )
            ++bad;
        // the dgoLangPotentialOnly pin
    if (dgoLangPotentialOnly() != 1
        )
            ++bad;
        // the dgoLangHomeCounts pin
    if (dgoLangHomeCounts() != 1
        )
            ++bad;
        // the dgoLangSecondIsTrade pin
    if (dgoLangSecondIsTrade() != 1
        )
            ++bad;
        // the dgoLangThirdIsAlignment pin
    if (dgoLangThirdIsAlignment() != 1
        )
            ++bad;
        // the dgoLangTradeBusinessOnly pin
    if (dgoLangTradeBusinessOnly() != 1
        )
            ++bad;
        // the dgoLangNonHumanSpecial pin
    if (dgoLangNonHumanSpecial() != 1
        )
            ++bad;
        // the dgoLangEveryOtherDayDoubles pin
    if (dgoLangEveryOtherDayDoubles() != 1
        )
            ++bad;
        // the dgoLangNativeSpeakersHalve pin
    if (dgoLangNativeSpeakersHalve() != 1
        )
            ++bad;
        // the dgoLangAlwaysAccent pin
    if (dgoLangAlwaysAccent() != 1
        )
            ++bad;
        // the dgoLangNuancesNativeOnly pin
    if (dgoLangNuancesNativeOnly() != 1
        )
            ++bad;
        // the T36 first row - bushi 1-5, one attack per round (capture p. 55)
    if (dgoT36Class(0) != 1
            || dgoT36LevelLo(0) != 1
            || dgoT36LevelHi(0) != 5
            || dgoT36AtkNum(0) != 1
            || dgoT36AtkDen(0) != 1
        )
            ++bad;
        // the T36 bushi capstone - 11 and up, 2/1, the -1 unbounded code
        // (capture p. 55)
    if (dgoT36Class(2) != 1
            || dgoT36LevelHi(2) != -1
            || dgoT36AtkNum(2) != 2
            || dgoT36AtkDen(2) != 1
        )
            ++bad;
        // the T36 kensai ladder - 1-3 at 1/1, 4-7 at 3/2, 8-14 at 2/1
        // (capture p. 55)
    if (dgoT36AtkNum(3) != 1
            || dgoT36AtkNum(4) != 3
            || dgoT36AtkDen(4) != 2
            || dgoT36AtkNum(5) != 2
        )
            ++bad;
        // the T36 kensai capstone - 15 and up, the printed 5/2 (capture p.
        // 55)
    if (dgoT36Class(6) != 2
            || dgoT36LevelHi(6) != -1
            || dgoT36AtkNum(6) != 5
            || dgoT36AtkDen(6) != 2
        )
            ++bad;
        // the T36 ninja bands - 1-6 at 1/1, 7-14 at 3/2, 15 and up at 2/1
        // (capture p. 55)
    if (dgoT36Class(7) != 3
            || dgoT36LevelHi(7) != 6
            || dgoT36AtkNum(8) != 3
            || dgoT36LevelLo(9) != 15
            || dgoT36AtkDen(9) != 1
        )
            ++bad;
        // the T36 barbarian bands - 1-6, 7-12, 13 and up (capture p. 55)
    if (dgoT36Class(10) != 4
            || dgoT36LevelHi(11) != 12
            || dgoT36LevelLo(12) != 13
            || dgoT36AtkNum(12) != 2
        )
            ++bad;
        // the T36 samurai bands - 1-4, 5-8, 9 and up (capture p. 55)
    if (dgoT36Class(13) != 5
            || dgoT36LevelHi(13) != 4
            || dgoT36LevelLo(14) != 5
            || dgoT36LevelHi(15) != -1
        )
            ++bad;
        // the T36 sohei bands - 1-6, 7-12, 13 and up, nineteen rows only
        // (capture p. 55)
    if (dgoT36Class(16) != 6
            || dgoT36LevelHi(17) != 12
            || dgoT36LevelHi(18) != -1
            || dgoT36AtkNum(18) != 2
            || dgoT36RowCount() != 19
        )
            ++bad;
        // the dual-class minima pair - 15 in the old requisites, 17 or 18 in
        // the new (capture p. 56)
    if (dgoDualOldClassReqMin() != 15
            || dgoDualNewClassReqMin() != 17
        )
            ++bad;
        // the alignment count - nine alignments (capture p. 56)
    if (dgoAlignCount() != 9
        )
            ++bad;
        // the language slot ladder - home, trade, alignment (capture p. 59)
    if (dgoLangSlotHome() != 1
            || dgoLangSlotTrade() != 2
            || dgoLangSlotAlignment() != 3
        )
            ++bad;
        // the comprehension pair - 75 percent between dialects, 50 in the
        // wild lands (capture p. 59)
    if (dgoLangDialectComprehension() != 75
            || dgoLangWildComprehension() != 50
        )
            ++bad;
        // the study doctrine - 20 minus Intelligence months, Int 15 means
        // five months (capture p. 59)
    if (dgoLangStudyMonthsBase() != 20
            || dgoLangStudyMonthsBase() - 15 != 5
        )
            ++bad;
        printf("R628 OA character abilities audit: bad %d\n", bad);
        if (bad) return 1;
    }
