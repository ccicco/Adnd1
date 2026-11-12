    // ---- R264: the III.E misc magic explanation
    // prose part 8 ----
    // Deck of Many Things, part2 lines 324-400 -
    // the 22-plaque table and the per-plaque
    // explanations, pinning the kMisc2 row 18.
    {
        Miscmagic_deck_of_many_things miscmagic_deck_of_many_things;
        Miscmagic_table2_footnotes miscmagic_table2_footnotes;
        int bad = 0;
        if (miscmagic_deck_of_many_things.mmpDeckPlaqueMaterialCount() != 2 ||
            miscmagic_deck_of_many_things.mmpDeckMinDraws() != 1 ||
            miscmagic_deck_of_many_things.mmpDeckMaxDraws() != 4 ||
            miscmagic_deck_of_many_things.mmpDeckJesterBonusDraws() != 2 ||
            miscmagic_deck_of_many_things.mmpDeckBasePlaqueCount() != 13 ||
            miscmagic_deck_of_many_things.mmpDeckFullPlaqueCount() != 22 ||
            miscmagic_deck_of_many_things.mmpDeckBaseChancePct() != 75 ||
            miscmagic_deck_of_many_things.mmpDeckFullChancePct() != 25 ||
            miscmagic_deck_of_many_things.mmpDeckAsteriskPlaqueCount() != 9 ||
            miscmagic_deck_of_many_things.mmpDeckDiscardPlaqueCount() != 2 ||
            miscmagic_deck_of_many_things.mmpDeckBoldFaceStopCount() != 2 ||
            miscmagic_deck_of_many_things.mmpDeckTablePlaqueCount() != 22) ++bad;
        if (miscmagic_deck_of_many_things.mmpDeckSunXp() != 50000 ||
            miscmagic_deck_of_many_things.mmpDeckMoonWishesMin() != 1 ||
            miscmagic_deck_of_many_things.mmpDeckMoonWishesMax() != 4 ||
            miscmagic_deck_of_many_things.mmpDeckMoonSpellLevel() != 9 ||
            miscmagic_deck_of_many_things.mmpDeckStarPoints() != 2 ||
            miscmagic_deck_of_many_things.mmpDeckStarMaxScore() != 19 ||
            miscmagic_deck_of_many_things.mmpDeckStarFallbackOrderCount() != 6 ||
            miscmagic_deck_of_many_things.mmpDeckCometMidpointProgress() != 1) ++bad;
        if (miscmagic_deck_of_many_things.mmpDeckThroneCharisma() != 18 ||
            miscmagic_deck_of_many_things.mmpDeckThroneReactionBonusPct() != 25 ||
            miscmagic_deck_of_many_things.mmpDeckKeyMapBonusPct() != 20 ||
            miscmagic_deck_of_many_things.mmpDeckKeyWeaponCount() != 1 ||
            miscmagic_deck_of_many_things.mmpDeckKnightLevel() != 4 ||
            miscmagic_deck_of_many_things.mmpDeckKnightBonusPerDie() != 1 ||
            miscmagic_deck_of_many_things.mmpDeckKnightAbilityMax() != 18 ||
            miscmagic_deck_of_many_things.mmpDeckGemJewelryCount() != 20 ||
            miscmagic_deck_of_many_things.mmpDeckGemGemCount() != 50 ||
            miscmagic_deck_of_many_things.mmpDeckGemGemBaseGp() != 1000 ||
            miscmagic_deck_of_many_things.mmpDeckGemXpLevelCap() != 1) ++bad;
        if (miscmagic_deck_of_many_things.mmpDeckEuryaleSavePenalty() != 3 ||
            miscmagic_deck_of_many_things.mmpDeckRogueHenchmenAlienated() != 1 ||
            miscmagic_deck_of_many_things.mmpDeckJesterXp() != 10000 ||
            miscmagic_deck_of_many_things.mmpDeckJesterExtraDraws() != 2 ||
            miscmagic_deck_of_many_things.mmpDeckFoolXp() != 10000 ||
            miscmagic_deck_of_many_things.mmpDeckIdiotIntLossMin() != 1 ||
            miscmagic_deck_of_many_things.mmpDeckIdiotIntLossMax() != 4) ++bad;
        if (miscmagic_deck_of_many_things.mmpDeckSkullDeathAc() != -4 ||
            miscmagic_deck_of_many_things.mmpDeckSkullDeathHp() != 33 ||
            miscmagic_deck_of_many_things.mmpDeckSkullScytheDmgMin() != 2 ||
            miscmagic_deck_of_many_things.mmpDeckSkullScytheDmgMax() != 16 ||
            miscmagic_deck_of_many_things.mmpDeckSkullUndeadForSpells() != 1 ||
            miscmagic_deck_of_many_things.mmpDeckFatesPartyEndures() != 1 ||
            miscmagic_deck_of_many_things.mmpDeckDonjonGearStripped() != 1) ++bad;
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
            if (miscmagic_deck_of_many_things.mmpDeckPlaqueAsterisk(i) !=
                kAsterisk[i] ||
                miscmagic_deck_of_many_things.mmpDeckPlaqueBoldFace(i) !=
                kBoldFace[i] ||
                miscmagic_deck_of_many_things.mmpDeckPlaqueDiscarded(i) !=
                kDiscard[i]) ++bad;
        if (miscmagic_deck_of_many_things.mmpDeckBasePlaqueCount() +
            miscmagic_deck_of_many_things.mmpDeckAsteriskPlaqueCount() !=
            miscmagic_deck_of_many_things.mmpDeckFullPlaqueCount()) ++bad;
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
