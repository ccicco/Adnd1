    // ---- R277: the III.E misc magic explanation
    // prose part 21 ----
    // The Robe of the Archmagi, the Robe of Blending,
    // the Robe of Eyes, the Robe of Powerlessness, the
    // Robe of Scintillating Colors and the Robe of
    // Useful Items, part2 lines 1002-1052 - the slice
    // pinning the kMisc5 rows 0-5 of the 35-row III.E.5
    // table (and opening it).
    {
        int bad = 0;
        // the robe of the archmagi scalars
        if (rules::mmpArchmagiWhitePct() != 45 ||
            rules::mmpArchmagiGrayPct() != 30 ||
            rules::mmpArchmagiBlackPct() != 25 ||
            rules::mmpArchmagiAcClass() != 5 ||
            rules::mmpArchmagiMagicResistPct() != 5 ||
            rules::mmpArchmagiSaveBonus() != 1 ||
            rules::mmpArchmagiPenaltyPct() != 20 ||
            rules::mmpArchmagiPenaltyMinus() != 4 ||
            rules::mmpArchmagiCharmFamilyCount() != 7) ++bad;
        // the archmagi clash scalars
        if (rules::mmpArchmagiClashDmgMin() != 18 ||
            rules::mmpArchmagiClashDmgMax() != 51 ||
            rules::mmpArchmagiClashDiceCount() != 11 ||
            rules::mmpArchmagiClashDiceBonus() != 7 ||
            rules::mmpArchmagiClashXpMin() != 18000 ||
            rules::mmpArchmagiClashXpMax() != 51000 ||
            rules::mmpArchmagiGrayDmgMin() != 6 ||
            rules::mmpArchmagiGrayDmgMax() != 24 ||
            rules::mmpArchmagiGrayXpMin() != 6000 ||
            rules::mmpArchmagiGrayXpMax() != 24000) ++bad;
        // the color split sums to 100 percent
        if (rules::mmpArchmagiWhitePct() +
            rules::mmpArchmagiGrayPct() +
            rules::mmpArchmagiBlackPct() != 100) ++bad;
        // the clash dice reproduce the printed damage
        if (rules::mmpArchmagiClashDiceCount() +
            rules::mmpArchmagiClashDiceBonus() !=
            rules::mmpArchmagiClashDmgMin() ||
            4 * rules::mmpArchmagiClashDiceCount() +
            rules::mmpArchmagiClashDiceBonus() !=
            rules::mmpArchmagiClashDmgMax()) ++bad;
        // the robe of blending scalars
        if (rules::mmpBlendDetectRangeInches() != 3 ||
            rules::mmpBlendDetectPerIntPct() != 1 ||
            rules::mmpBlendDetectIntMin() != 15 ||
            rules::mmpBlendLevelDetectIntMin() != 5 ||
            rules::mmpBlendLevelDetectLevelMin() != 10 ||
            rules::mmpBlendDetectPerLevelPct() != 1 ||
            rules::mmpBlendExamplePct() != 30) ++bad;
        // the example is the two chances summed
        if (18 * rules::mmpBlendDetectPerIntPct() +
            12 * rules::mmpBlendDetectPerLevelPct() !=
            rules::mmpBlendExamplePct()) ++bad;
        // the robe of eyes scalars
        if (rules::mmpEyesInfravisionInches() != 12 ||
            rules::mmpEyesSeeInvisibleInches() != 24 ||
            rules::mmpEyesSeeInfraredInches() != 12 ||
            rules::mmpEyesTrackRangerLevel() != 12 ||
            rules::mmpEyesBlindLightMin() != 1 ||
            rules::mmpEyesBlindLightMax() != 3 ||
            rules::mmpEyesBlindContinualMin() != 2 ||
            rules::mmpEyesBlindContinualMax() != 8) ++bad;
        // the robe of powerlessness scalars
        if (rules::mmpPowerlessIntelligence() != 3 ||
            rules::mmpPowerlessStrength() != 3) ++bad;
        // the robe of scintillating colors scalars
        if (rules::mmpScintIntMin() != 15 ||
            rules::mmpScintWisMin() != 13 ||
            rules::mmpScintLightFeet() != 40 ||
            rules::mmpScintStartRounds() != 1 ||
            rules::mmpScintTransfixMin() != 2 ||
            rules::mmpScintTransfixMax() != 5 ||
            rules::mmpScintHitPctPerRound() != 5 ||
            rules::mmpScintHitPctMax() != 25 ||
            rules::mmpScintHitMaxRounds() != 5 ||
            rules::mmpScintCastRangeInches() != 1 ||
            rules::mmpScintHypnotizeMin() != 2 ||
            rules::mmpScintHypnotizeMax() != 5) ++bad;
        // the hit ladder reaches the max at the max rounds
        if (rules::mmpScintHitPctPerRound() *
            rules::mmpScintHitMaxRounds() !=
            rules::mmpScintHitPctMax()) ++bad;
        // the robe of useful items scalars
        if (rules::mmpUsefulDetachRounds() != 1 ||
            rules::mmpUsefulBaseEach() != 2 ||
            rules::mmpUsefulBaseCount() != 6 ||
            rules::mmpUsefulExtraMin() != 4 ||
            rules::mmpUsefulExtraMax() != 16 ||
            rules::mmpUsefulGpBag() != 100 ||
            rules::mmpUsefulCofferGp() != 500 ||
            rules::mmpUsefulGemsCount() != 10 ||
            rules::mmpUsefulGemValueGp() != 100 ||
            rules::mmpUsefulLadderFeet() != 24 ||
            rules::mmpUsefulPitCubicFeet() != 10 ||
            rules::mmpUsefulRowboatFeet() != 12 ||
            rules::mmpUsefulWindowWidthFeet() != 2 ||
            rules::mmpUsefulWindowHeightFeet() != 4 ||
            rules::mmpUsefulWindowDepthFeet() != 2 ||
            rules::mmpUsefulScrollSpells() != 1 ||
            rules::mmpUsefulWarDogsPair() != 2) ++bad;
        // the extra items dice table against static twins
        static const int kUlo[13] = {
            1, 9, 16, 23, 31, 45, 52,
            60, 69, 76, 84, 91, 97,
        };
        static const int kUhi[13] = {
            8, 15, 22, 30, 44, 51, 59,
            68, 75, 83, 90, 96, 100,
        };
        for (int i = 0; i < 13; ++i)
            if (rules::mmpUsefulRowLo(i) != kUlo[i] ||
                rules::mmpUsefulRowHi(i) != kUhi[i]) ++bad;
        // the bands run 01 through 00 with no gaps
        if (rules::mmpUsefulRowLo(0) != 1 ||
            rules::mmpUsefulRowHi(12) != 100) ++bad;
        for (int i = 0; i < 12; ++i)
            if (rules::mmpUsefulRowLo(i + 1) !=
                rules::mmpUsefulRowHi(i) + 1) ++bad;
        for (int i = 0; i < 13; ++i)
            if (rules::mmpUsefulRowLo(i) >
                rules::mmpUsefulRowHi(i)) ++bad;
        // the kMisc5 table opening cross-check
        static const int kRlo[6] = {
            1, 2, 9, 10, 11, 12,
        };
        static const int kRhi[6] = {
            1, 8, 9, 10, 11, 19,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::m5RowLo(i) != kRlo[i] ||
                rules::m5RowHi(i) != kRhi[i]) ++bad;
        // the marks: only the scintillating robe is (C)
        for (int i = 0; i < 6; ++i)
            if (i != 4 &&
                rules::m5UsableByCleric(i) != 0) ++bad;
        // no fighter or thief marks on the robes
        for (int i = 0; i < 6; ++i)
            if (rules::m5UsableByFighter(i) != 0) ++bad;
        for (int i = 0; i < 6; ++i)
            if (rules::m5UsableByThief(i) != 0) ++bad;
        // the magic-user marks: all robes but the blending
        for (int i = 0; i < 6; ++i)
            if (i != 1 &&
                rules::m5UsableByMagicUser(i) != 1) ++bad;
        // the whole-table counts and row census
        if (rules::m5ClericCount() != 5 ||
            rules::m5FighterCount() != 5 ||
            rules::m5MagicUserCount() != 8 ||
            rules::m5ThiefCount() != 2 ||
            rules::m5RowCount() != 35) ++bad;
        printf("R277 misc magic prose part 21 pins audit: bad %d\n", bad);
    }
