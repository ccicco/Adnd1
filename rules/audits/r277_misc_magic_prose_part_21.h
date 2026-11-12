    // ---- R277: the III.E misc magic explanation
    // prose part 21 ----
    // The Robe of the Archmagi, the Robe of Blending,
    // the Robe of Eyes, the Robe of Powerlessness, the
    // Robe of Scintillating Colors and the Robe of
    // Useful Items, part2 lines 1002-1052 - the slice
    // pinning the kMisc5 rows 0-5 of the 35-row III.E.5
    // table (and opening it).
    {
        Miscmagic_robes miscmagic_robes;
        Miscmagic_table5_footnotes miscmagic_table5_footnotes;
        int bad = 0;
        // the robe of the archmagi scalars
        if (miscmagic_robes.mmpArchmagiWhitePct() != 45 ||
            miscmagic_robes.mmpArchmagiGrayPct() != 30 ||
            miscmagic_robes.mmpArchmagiBlackPct() != 25 ||
            miscmagic_robes.mmpArchmagiAcClass() != 5 ||
            miscmagic_robes.mmpArchmagiMagicResistPct() != 5 ||
            miscmagic_robes.mmpArchmagiSaveBonus() != 1 ||
            miscmagic_robes.mmpArchmagiPenaltyPct() != 20 ||
            miscmagic_robes.mmpArchmagiPenaltyMinus() != 4 ||
            miscmagic_robes.mmpArchmagiCharmFamilyCount() != 7) ++bad;
        // the archmagi clash scalars
        if (miscmagic_robes.mmpArchmagiClashDmgMin() != 18 ||
            miscmagic_robes.mmpArchmagiClashDmgMax() != 51 ||
            miscmagic_robes.mmpArchmagiClashDiceCount() != 11 ||
            miscmagic_robes.mmpArchmagiClashDiceBonus() != 7 ||
            miscmagic_robes.mmpArchmagiClashXpMin() != 18000 ||
            miscmagic_robes.mmpArchmagiClashXpMax() != 51000 ||
            miscmagic_robes.mmpArchmagiGrayDmgMin() != 6 ||
            miscmagic_robes.mmpArchmagiGrayDmgMax() != 24 ||
            miscmagic_robes.mmpArchmagiGrayXpMin() != 6000 ||
            miscmagic_robes.mmpArchmagiGrayXpMax() != 24000) ++bad;
        // the color split sums to 100 percent
        if (miscmagic_robes.mmpArchmagiWhitePct() +
            miscmagic_robes.mmpArchmagiGrayPct() +
            miscmagic_robes.mmpArchmagiBlackPct() != 100) ++bad;
        // the clash dice reproduce the printed damage
        if (miscmagic_robes.mmpArchmagiClashDiceCount() +
            miscmagic_robes.mmpArchmagiClashDiceBonus() !=
            miscmagic_robes.mmpArchmagiClashDmgMin() ||
            4 * miscmagic_robes.mmpArchmagiClashDiceCount() +
            miscmagic_robes.mmpArchmagiClashDiceBonus() !=
            miscmagic_robes.mmpArchmagiClashDmgMax()) ++bad;
        // the robe of blending scalars
        if (miscmagic_robes.mmpBlendDetectRangeInches() != 3 ||
            miscmagic_robes.mmpBlendDetectPerIntPct() != 1 ||
            miscmagic_robes.mmpBlendDetectIntMin() != 15 ||
            miscmagic_robes.mmpBlendLevelDetectIntMin() != 5 ||
            miscmagic_robes.mmpBlendLevelDetectLevelMin() != 10 ||
            miscmagic_robes.mmpBlendDetectPerLevelPct() != 1 ||
            miscmagic_robes.mmpBlendExamplePct() != 30) ++bad;
        // the example is the two chances summed
        if (18 * miscmagic_robes.mmpBlendDetectPerIntPct() +
            12 * miscmagic_robes.mmpBlendDetectPerLevelPct() !=
            miscmagic_robes.mmpBlendExamplePct()) ++bad;
        // the robe of eyes scalars
        if (miscmagic_robes.mmpEyesInfravisionInches() != 12 ||
            miscmagic_robes.mmpEyesSeeInvisibleInches() != 24 ||
            miscmagic_robes.mmpEyesSeeInfraredInches() != 12 ||
            miscmagic_robes.mmpEyesTrackRangerLevel() != 12 ||
            miscmagic_robes.mmpEyesBlindLightMin() != 1 ||
            miscmagic_robes.mmpEyesBlindLightMax() != 3 ||
            miscmagic_robes.mmpEyesBlindContinualMin() != 2 ||
            miscmagic_robes.mmpEyesBlindContinualMax() != 8) ++bad;
        // the robe of powerlessness scalars
        if (miscmagic_robes.mmpPowerlessIntelligence() != 3 ||
            miscmagic_robes.mmpPowerlessStrength() != 3) ++bad;
        // the robe of scintillating colors scalars
        if (miscmagic_robes.mmpScintIntMin() != 15 ||
            miscmagic_robes.mmpScintWisMin() != 13 ||
            miscmagic_robes.mmpScintLightFeet() != 40 ||
            miscmagic_robes.mmpScintStartRounds() != 1 ||
            miscmagic_robes.mmpScintTransfixMin() != 2 ||
            miscmagic_robes.mmpScintTransfixMax() != 5 ||
            miscmagic_robes.mmpScintHitPctPerRound() != 5 ||
            miscmagic_robes.mmpScintHitPctMax() != 25 ||
            miscmagic_robes.mmpScintHitMaxRounds() != 5 ||
            miscmagic_robes.mmpScintCastRangeInches() != 1 ||
            miscmagic_robes.mmpScintHypnotizeMin() != 2 ||
            miscmagic_robes.mmpScintHypnotizeMax() != 5) ++bad;
        // the hit ladder reaches the max at the max rounds
        if (miscmagic_robes.mmpScintHitPctPerRound() *
            miscmagic_robes.mmpScintHitMaxRounds() !=
            miscmagic_robes.mmpScintHitPctMax()) ++bad;
        // the robe of useful items scalars
        if (miscmagic_robes.mmpUsefulDetachRounds() != 1 ||
            miscmagic_robes.mmpUsefulBaseEach() != 2 ||
            miscmagic_robes.mmpUsefulBaseCount() != 6 ||
            miscmagic_robes.mmpUsefulExtraMin() != 4 ||
            miscmagic_robes.mmpUsefulExtraMax() != 16 ||
            miscmagic_robes.mmpUsefulGpBag() != 100 ||
            miscmagic_robes.mmpUsefulCofferGp() != 500 ||
            miscmagic_robes.mmpUsefulGemsCount() != 10 ||
            miscmagic_robes.mmpUsefulGemValueGp() != 100 ||
            miscmagic_robes.mmpUsefulLadderFeet() != 24 ||
            miscmagic_robes.mmpUsefulPitCubicFeet() != 10 ||
            miscmagic_robes.mmpUsefulRowboatFeet() != 12 ||
            miscmagic_robes.mmpUsefulWindowWidthFeet() != 2 ||
            miscmagic_robes.mmpUsefulWindowHeightFeet() != 4 ||
            miscmagic_robes.mmpUsefulWindowDepthFeet() != 2 ||
            miscmagic_robes.mmpUsefulScrollSpells() != 1 ||
            miscmagic_robes.mmpUsefulWarDogsPair() != 2) ++bad;
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
            if (miscmagic_robes.mmpUsefulRowLo(i) != kUlo[i] ||
                miscmagic_robes.mmpUsefulRowHi(i) != kUhi[i]) ++bad;
        // the bands run 01 through 00 with no gaps
        if (miscmagic_robes.mmpUsefulRowLo(0) != 1 ||
            miscmagic_robes.mmpUsefulRowHi(12) != 100) ++bad;
        for (int i = 0; i < 12; ++i)
            if (miscmagic_robes.mmpUsefulRowLo(i + 1) !=
                miscmagic_robes.mmpUsefulRowHi(i) + 1) ++bad;
        for (int i = 0; i < 13; ++i)
            if (miscmagic_robes.mmpUsefulRowLo(i) >
                miscmagic_robes.mmpUsefulRowHi(i)) ++bad;
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
