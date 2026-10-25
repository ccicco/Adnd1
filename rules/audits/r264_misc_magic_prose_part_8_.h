    // ---- R264: the III.E misc magic explanation
    // prose part 8 ----
    // Deck of Many Things, part2 lines 324-400 -
    // the 22-plaque table and the per-plaque
    // explanations, pinning the kMisc2 row 18.
    {
        int bad = 0;
        if (rules::mmpDeckPlaqueMaterialCount() != 2 ||
            rules::mmpDeckMinDraws() != 1 ||
            rules::mmpDeckMaxDraws() != 4 ||
            rules::mmpDeckJesterBonusDraws() != 2 ||
            rules::mmpDeckBasePlaqueCount() != 13 ||
            rules::mmpDeckFullPlaqueCount() != 22 ||
            rules::mmpDeckBaseChancePct() != 75 ||
            rules::mmpDeckFullChancePct() != 25 ||
            rules::mmpDeckAsteriskPlaqueCount() != 9 ||
            rules::mmpDeckDiscardPlaqueCount() != 2 ||
            rules::mmpDeckBoldFaceStopCount() != 2 ||
            rules::mmpDeckTablePlaqueCount() != 22) ++bad;
        if (rules::mmpDeckSunXp() != 50000 ||
            rules::mmpDeckMoonWishesMin() != 1 ||
            rules::mmpDeckMoonWishesMax() != 4 ||
            rules::mmpDeckMoonSpellLevel() != 9 ||
            rules::mmpDeckStarPoints() != 2 ||
            rules::mmpDeckStarMaxScore() != 19 ||
            rules::mmpDeckStarFallbackOrderCount() != 6 ||
            rules::mmpDeckCometMidpointProgress() != 1) ++bad;
        if (rules::mmpDeckThroneCharisma() != 18 ||
            rules::mmpDeckThroneReactionBonusPct() != 25 ||
            rules::mmpDeckKeyMapBonusPct() != 20 ||
            rules::mmpDeckKeyWeaponCount() != 1 ||
            rules::mmpDeckKnightLevel() != 4 ||
            rules::mmpDeckKnightBonusPerDie() != 1 ||
            rules::mmpDeckKnightAbilityMax() != 18 ||
            rules::mmpDeckGemJewelryCount() != 20 ||
            rules::mmpDeckGemGemCount() != 50 ||
            rules::mmpDeckGemGemBaseGp() != 1000 ||
            rules::mmpDeckGemXpLevelCap() != 1) ++bad;
        if (rules::mmpDeckEuryaleSavePenalty() != 3 ||
            rules::mmpDeckRogueHenchmenAlienated() != 1 ||
            rules::mmpDeckJesterXp() != 10000 ||
            rules::mmpDeckJesterExtraDraws() != 2 ||
            rules::mmpDeckFoolXp() != 10000 ||
            rules::mmpDeckIdiotIntLossMin() != 1 ||
            rules::mmpDeckIdiotIntLossMax() != 4) ++bad;
        if (rules::mmpDeckSkullDeathAc() != -4 ||
            rules::mmpDeckSkullDeathHp() != 33 ||
            rules::mmpDeckSkullScytheDmgMin() != 2 ||
            rules::mmpDeckSkullScytheDmgMax() != 16 ||
            rules::mmpDeckSkullUndeadForSpells() != 1 ||
            rules::mmpDeckFatesPartyEndures() != 1 ||
            rules::mmpDeckDonjonGearStripped() != 1) ++bad;
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
            if (rules::mmpDeckPlaqueAsterisk(i) !=
                kAsterisk[i] ||
                rules::mmpDeckPlaqueBoldFace(i) !=
                kBoldFace[i] ||
                rules::mmpDeckPlaqueDiscarded(i) !=
                kDiscard[i]) ++bad;
        if (rules::mmpDeckBasePlaqueCount() +
            rules::mmpDeckAsteriskPlaqueCount() !=
            rules::mmpDeckFullPlaqueCount()) ++bad;
        // the kMisc2 row this slice pins: the Deck
        // of Many Things, 73-76, no class marks
        if (rules::m2RowLo(18) != 73 ||
            rules::m2RowHi(18) != 76 ||
            rules::m2UsableByCleric(18) ||
            rules::m2UsableByMagicUser(18) ||
            rules::m2IsPerPlusValued(18) ||
            rules::m2HasFeatureAsterisk(18) ||
            rules::m2IsTripleStar(18)) ++bad;
        // the row 26 (M) positive control
        if (!rules::m2UsableByMagicUser(26)) ++bad;
        printf("R264 misc magic prose part 8 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
