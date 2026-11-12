    // ---- R277: the III.E misc magic explanation
    // prose part 21 ----
    // The Robe of the Archmagi, the Robe of Blending,
    // the Robe of Eyes, the Robe of Powerlessness, the
    // Robe of Scintillating Colors and the Robe of
    // Useful Items, part2 lines 1002-1052 - the slice
    // pinning the kMisc5 rows 0-5 of the 35-row III.E.5
    // table (and opening it).
    {
        Miscmagic_robes miscmagic;
        Miscmagic_table5_footnotes miscmagic_table5_footnotes;
        int bad = 0;
        // the robe of the archmagi scalars
        if (miscmagic.mmpArchmagiWhitePct() != 45 ||
            miscmagic.mmpArchmagiGrayPct() != 30 ||
            miscmagic.mmpArchmagiBlackPct() != 25 ||
            miscmagic.mmpArchmagiAcClass() != 5 ||
            miscmagic.mmpArchmagiMagicResistPct() != 5 ||
            miscmagic.mmpArchmagiSaveBonus() != 1 ||
            miscmagic.mmpArchmagiPenaltyPct() != 20 ||
            miscmagic.mmpArchmagiPenaltyMinus() != 4 ||
            miscmagic.mmpArchmagiCharmFamilyCount() != 7) ++bad;
        // the archmagi clash scalars
        if (miscmagic.mmpArchmagiClashDmgMin() != 18 ||
            miscmagic.mmpArchmagiClashDmgMax() != 51 ||
            miscmagic.mmpArchmagiClashDiceCount() != 11 ||
            miscmagic.mmpArchmagiClashDiceBonus() != 7 ||
            miscmagic.mmpArchmagiClashXpMin() != 18000 ||
            miscmagic.mmpArchmagiClashXpMax() != 51000 ||
            miscmagic.mmpArchmagiGrayDmgMin() != 6 ||
            miscmagic.mmpArchmagiGrayDmgMax() != 24 ||
            miscmagic.mmpArchmagiGrayXpMin() != 6000 ||
            miscmagic.mmpArchmagiGrayXpMax() != 24000) ++bad;
        // the color split sums to 100 percent
        if (miscmagic.mmpArchmagiWhitePct() +
            miscmagic.mmpArchmagiGrayPct() +
            miscmagic.mmpArchmagiBlackPct() != 100) ++bad;
        // the clash dice reproduce the printed damage
        if (miscmagic.mmpArchmagiClashDiceCount() +
            miscmagic.mmpArchmagiClashDiceBonus() !=
            miscmagic.mmpArchmagiClashDmgMin() ||
            4 * miscmagic.mmpArchmagiClashDiceCount() +
            miscmagic.mmpArchmagiClashDiceBonus() !=
            miscmagic.mmpArchmagiClashDmgMax()) ++bad;
        // the robe of blending scalars
        if (miscmagic.mmpBlendDetectRangeInches() != 3 ||
            miscmagic.mmpBlendDetectPerIntPct() != 1 ||
            miscmagic.mmpBlendDetectIntMin() != 15 ||
            miscmagic.mmpBlendLevelDetectIntMin() != 5 ||
            miscmagic.mmpBlendLevelDetectLevelMin() != 10 ||
            miscmagic.mmpBlendDetectPerLevelPct() != 1 ||
            miscmagic.mmpBlendExamplePct() != 30) ++bad;
        // the example is the two chances summed
        if (18 * miscmagic.mmpBlendDetectPerIntPct() +
            12 * miscmagic.mmpBlendDetectPerLevelPct() !=
            miscmagic.mmpBlendExamplePct()) ++bad;
        // the robe of eyes scalars
        if (miscmagic.mmpEyesInfravisionInches() != 12 ||
            miscmagic.mmpEyesSeeInvisibleInches() != 24 ||
            miscmagic.mmpEyesSeeInfraredInches() != 12 ||
            miscmagic.mmpEyesTrackRangerLevel() != 12 ||
            miscmagic.mmpEyesBlindLightMin() != 1 ||
            miscmagic.mmpEyesBlindLightMax() != 3 ||
            miscmagic.mmpEyesBlindContinualMin() != 2 ||
            miscmagic.mmpEyesBlindContinualMax() != 8) ++bad;
        // the robe of powerlessness scalars
        if (miscmagic.mmpPowerlessIntelligence() != 3 ||
            miscmagic.mmpPowerlessStrength() != 3) ++bad;
        // the robe of scintillating colors scalars
        if (miscmagic.mmpScintIntMin() != 15 ||
            miscmagic.mmpScintWisMin() != 13 ||
            miscmagic.mmpScintLightFeet() != 40 ||
            miscmagic.mmpScintStartRounds() != 1 ||
            miscmagic.mmpScintTransfixMin() != 2 ||
            miscmagic.mmpScintTransfixMax() != 5 ||
            miscmagic.mmpScintHitPctPerRound() != 5 ||
            miscmagic.mmpScintHitPctMax() != 25 ||
            miscmagic.mmpScintHitMaxRounds() != 5 ||
            miscmagic.mmpScintCastRangeInches() != 1 ||
            miscmagic.mmpScintHypnotizeMin() != 2 ||
            miscmagic.mmpScintHypnotizeMax() != 5) ++bad;
        // the hit ladder reaches the max at the max rounds
        if (miscmagic.mmpScintHitPctPerRound() *
            miscmagic.mmpScintHitMaxRounds() !=
            miscmagic.mmpScintHitPctMax()) ++bad;
        // the robe of useful items scalars
        if (miscmagic.mmpUsefulDetachRounds() != 1 ||
            miscmagic.mmpUsefulBaseEach() != 2 ||
            miscmagic.mmpUsefulBaseCount() != 6 ||
            miscmagic.mmpUsefulExtraMin() != 4 ||
            miscmagic.mmpUsefulExtraMax() != 16 ||
            miscmagic.mmpUsefulGpBag() != 100 ||
            miscmagic.mmpUsefulCofferGp() != 500 ||
            miscmagic.mmpUsefulGemsCount() != 10 ||
            miscmagic.mmpUsefulGemValueGp() != 100 ||
            miscmagic.mmpUsefulLadderFeet() != 24 ||
            miscmagic.mmpUsefulPitCubicFeet() != 10 ||
            miscmagic.mmpUsefulRowboatFeet() != 12 ||
            miscmagic.mmpUsefulWindowWidthFeet() != 2 ||
            miscmagic.mmpUsefulWindowHeightFeet() != 4 ||
            miscmagic.mmpUsefulWindowDepthFeet() != 2 ||
            miscmagic.mmpUsefulScrollSpells() != 1 ||
            miscmagic.mmpUsefulWarDogsPair() != 2) ++bad;
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
            if (miscmagic.mmpUsefulRowLo(i) != kUlo[i] ||
                miscmagic.mmpUsefulRowHi(i) != kUhi[i]) ++bad;
        // the bands run 01 through 00 with no gaps
        if (miscmagic.mmpUsefulRowLo(0) != 1 ||
            miscmagic.mmpUsefulRowHi(12) != 100) ++bad;
        for (int i = 0; i < 12; ++i)
            if (miscmagic.mmpUsefulRowLo(i + 1) !=
                miscmagic.mmpUsefulRowHi(i) + 1) ++bad;
        for (int i = 0; i < 13; ++i)
            if (miscmagic.mmpUsefulRowLo(i) >
                miscmagic.mmpUsefulRowHi(i)) ++bad;
        // the kMisc5 table opening cross-check
        static const int kRlo[6] = {
            1, 2, 9, 10, 11, 12,
        };
        static const int kRhi[6] = {
            1, 8, 9, 10, 11, 19,
        };
        for (int i = 0; i < 6; ++i)
            if (miscmagic_table5_footnotes.m5RowLo(i) != kRlo[i] ||
                miscmagic_table5_footnotes.m5RowHi(i) != kRhi[i]) ++bad;
        // the marks: only the scintillating robe is (C)
        for (int i = 0; i < 6; ++i)
            if (i != 4 &&
                miscmagic_table5_footnotes.m5UsableByCleric(i) != 0) ++bad;
        // no fighter or thief marks on the robes
        for (int i = 0; i < 6; ++i)
            if (miscmagic_table5_footnotes.m5UsableByFighter(i) != 0) ++bad;
        for (int i = 0; i < 6; ++i)
            if (miscmagic_table5_footnotes.m5UsableByThief(i) != 0) ++bad;
        // the magic-user marks: all robes but the blending
        for (int i = 0; i < 6; ++i)
            if (i != 1 &&
                miscmagic_table5_footnotes.m5UsableByMagicUser(i) != 1) ++bad;
        // the whole-table counts and row census
        if (miscmagic_table5_footnotes.m5ClericCount() != 5 ||
            miscmagic_table5_footnotes.m5FighterCount() != 5 ||
            miscmagic_table5_footnotes.m5MagicUserCount() != 8 ||
            miscmagic_table5_footnotes.m5ThiefCount() != 2 ||
            miscmagic_table5_footnotes.m5RowCount() != 35) ++bad;
        printf("R277 misc magic prose part 21 pins audit: bad %d\n", bad);
    }
