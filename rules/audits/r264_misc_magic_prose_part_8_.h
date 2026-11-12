    // ---- R264: the III.E misc magic explanation
    // prose part 8 ----
    // Deck of Many Things, part2 lines 324-400 -
    // the 22-plaque table and the per-plaque
    // explanations, pinning the kMisc2 row 18.
    {
        Miscmagic_alchemy_jug_to_wings_of_flying miscmagic;
        Miscmagic_table2_footnotes miscmagic_table2_footnotes;
        int bad = 0;
        if (miscmagic.mmpDeckPlaqueMaterialCount() != 2 ||
            miscmagic.mmpDeckMinDraws() != 1 ||
            miscmagic.mmpDeckMaxDraws() != 4 ||
            miscmagic.mmpDeckJesterBonusDraws() != 2 ||
            miscmagic.mmpDeckBasePlaqueCount() != 13 ||
            miscmagic.mmpDeckFullPlaqueCount() != 22 ||
            miscmagic.mmpDeckBaseChancePct() != 75 ||
            miscmagic.mmpDeckFullChancePct() != 25 ||
            miscmagic.mmpDeckAsteriskPlaqueCount() != 9 ||
            miscmagic.mmpDeckDiscardPlaqueCount() != 2 ||
            miscmagic.mmpDeckBoldFaceStopCount() != 2 ||
            miscmagic.mmpDeckTablePlaqueCount() != 22) ++bad;
        if (miscmagic.mmpDeckSunXp() != 50000 ||
            miscmagic.mmpDeckMoonWishesMin() != 1 ||
            miscmagic.mmpDeckMoonWishesMax() != 4 ||
            miscmagic.mmpDeckMoonSpellLevel() != 9 ||
            miscmagic.mmpDeckStarPoints() != 2 ||
            miscmagic.mmpDeckStarMaxScore() != 19 ||
            miscmagic.mmpDeckStarFallbackOrderCount() != 6 ||
            miscmagic.mmpDeckCometMidpointProgress() != 1) ++bad;
        if (miscmagic.mmpDeckThroneCharisma() != 18 ||
            miscmagic.mmpDeckThroneReactionBonusPct() != 25 ||
            miscmagic.mmpDeckKeyMapBonusPct() != 20 ||
            miscmagic.mmpDeckKeyWeaponCount() != 1 ||
            miscmagic.mmpDeckKnightLevel() != 4 ||
            miscmagic.mmpDeckKnightBonusPerDie() != 1 ||
            miscmagic.mmpDeckKnightAbilityMax() != 18 ||
            miscmagic.mmpDeckGemJewelryCount() != 20 ||
            miscmagic.mmpDeckGemGemCount() != 50 ||
            miscmagic.mmpDeckGemGemBaseGp() != 1000 ||
            miscmagic.mmpDeckGemXpLevelCap() != 1) ++bad;
        if (miscmagic.mmpDeckEuryaleSavePenalty() != 3 ||
            miscmagic.mmpDeckRogueHenchmenAlienated() != 1 ||
            miscmagic.mmpDeckJesterXp() != 10000 ||
            miscmagic.mmpDeckJesterExtraDraws() != 2 ||
            miscmagic.mmpDeckFoolXp() != 10000 ||
            miscmagic.mmpDeckIdiotIntLossMin() != 1 ||
            miscmagic.mmpDeckIdiotIntLossMax() != 4) ++bad;
        if (miscmagic.mmpDeckSkullDeathAc() != -4 ||
            miscmagic.mmpDeckSkullDeathHp() != 33 ||
            miscmagic.mmpDeckSkullScytheDmgMin() != 2 ||
            miscmagic.mmpDeckSkullScytheDmgMax() != 16 ||
            miscmagic.mmpDeckSkullUndeadForSpells() != 1 ||
            miscmagic.mmpDeckFatesPartyEndures() != 1 ||
            miscmagic.mmpDeckDonjonGearStripped() != 1) ++bad;
        static const int kAsterisk[22] = {
            0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1,
            0, 0, 0, 1, 0, 1, 1, 1, 1, 1,
        };
        static const int kBoldFace[22] = {
            0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        };
        static const int kDiscard[22] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
        };
        for (int i = 0; i < 22; ++i)
            if (miscmagic.mmpDeckPlaqueAsterisk(i) !=
                kAsterisk[i] ||
                miscmagic.mmpDeckPlaqueBoldFace(i) !=
                kBoldFace[i] ||
                miscmagic.mmpDeckPlaqueDiscarded(i) !=
                kDiscard[i]) ++bad;
        if (miscmagic.mmpDeckBasePlaqueCount() +
            miscmagic.mmpDeckAsteriskPlaqueCount() !=
            miscmagic.mmpDeckFullPlaqueCount()) ++bad;
        // the kMisc2 row this slice pins: the Deck
        // of Many Things, 73-76, no class marks
        if (miscmagic_table2_footnotes.m2RowLo(18) != 73 ||
            miscmagic_table2_footnotes.m2RowHi(18) != 76 ||
            miscmagic_table2_footnotes.m2UsableByCleric(18) ||
            miscmagic_table2_footnotes.m2UsableByMagicUser(18) ||
            miscmagic_table2_footnotes.m2IsPerPlusValued(18) ||
            miscmagic_table2_footnotes.m2HasFeatureAsterisk(18) ||
            miscmagic_table2_footnotes.m2IsTripleStar(18)) ++bad;
        // the row 26 (M) positive control
        if (!miscmagic_table2_footnotes.m2UsableByMagicUser(26)) ++bad;
        printf("R264 misc magic prose part 8 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
