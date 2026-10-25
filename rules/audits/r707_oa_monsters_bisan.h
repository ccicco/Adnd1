    // ---- R707 OA monsters Bisan audit ----
    // OA round ninety-four (capture pp. 255-256): the Chapter 12 monster
    // roster - the Bisan, the stat block and the description riding together,
    // single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (djuBisanNoAppearing() != 1
            || djuBisanAC() != 0
            || djuBisanMove() != 24
            || djuBisanHD() != 10
            || djuBisanLairPct() != 100
            || djuBisanTreasureTypes() != 2
            || djuBisanAttacks() != 1
            || djuBisanDmgMin() != 1
            || djuBisanDmgMax() != 10
            || djuBisanMRPct() != 40
            || djuBisanXPLevel() != 7
            || djuBisanXPBase() != 2100
            || djuBisanXPPerHP() != 14
            || djuBisanSpellsPerRound() != 1
            || djuBisanSpellBatteryCount() != 9
            || djuBisanOfferingsRequired() != 2
            || djuBisanLangCount() != 1
            || !djuBisanVeryRare()
            || !djuBisanIntHigh()
            || !djuBisanNeutral()
            || !djuBisanSizeM()
            || !djuBisanPsionicNil()
            || !djuBisanTreeHarvestSpirit()
            || !djuBisanCamphorMostCommon()
            || !djuBisanNaturalFormBeautifulWoman()
            || !djuBisanPrefersInsectForm()
            || !djuBisanProtectsSameTypeTrees()
            || !djuBisanOneTreePerBisan()
            || !djuBisanTreeDamageDamagesIt()
            || !djuBisanAllowsHarvest()
            || !djuBisanEndOfLifeFellingAllowed()
            || !djuBisanRequiresOffering()
            || !djuBisanAngeredWithoutOffering()
            || !djuBisanPolymorphSelfAtWill()
            || !djuBisanTurnInvisibleAtWill()
            || !djuBisanBecomeEtherealAtWill()
            || !djuBisanBlessReversible()
            || !djuBisanAvoidsCombatMischief()
            || !djuBisanFleesUnlessDefendingTree()
            || !djuBisanFormidableIfAngered()
            || !djuBisanWoodsKnownBySuperstition()
            || !djuBisanSpeaksOwnLanguageOnly()
        )
            ++bad;
        // the stat block - the very rare, the 1, the AC 0, the move 24, the
        // HD 10, the 100% lair, the Q T, the 1 attack of 1-10, the 40% MR,
        // the High, the Neutral, the M, the VII/2,100 + 14/hp
    if (djuBisanNoAppearing() != 1
            || djuBisanAC() != 0
            || djuBisanMove() != 24
            || djuBisanHD() != 10
            || djuBisanLairPct() != 100
            || djuBisanTreasureTypes() != 2
            || djuBisanAttacks() != 1
            || djuBisanDmgMin() != 1
            || djuBisanDmgMax() != 10
            || djuBisanMRPct() != 40
            || djuBisanXPLevel() != 7
            || djuBisanXPBase() != 2100
            || djuBisanXPPerHP() != 14
            || djuBisanVeryRare() != 1
            || djuBisanIntHigh() != 1
            || djuBisanNeutral() != 1
            || djuBisanSizeM() != 1
            || djuBisanPsionicNil() != 1
        )
            ++bad;
        // the tree and the harvest - the harvest spirit, the camphor most
        // common, the beautiful-woman natural form, the insect preference,
        // the same-type protection, the one tree per bisan, the tree damage,
        // the harvest allowance, the end-of-life felling, the two offerings,
        // the anger rule
    if (djuBisanTreeHarvestSpirit() != 1
            || djuBisanCamphorMostCommon() != 1
            || djuBisanNaturalFormBeautifulWoman() != 1
            || djuBisanPrefersInsectForm() != 1
            || djuBisanProtectsSameTypeTrees() != 1
            || djuBisanOneTreePerBisan() != 1
            || djuBisanTreeDamageDamagesIt() != 1
            || djuBisanAllowsHarvest() != 1
            || djuBisanEndOfLifeFellingAllowed() != 1
            || djuBisanRequiresOffering() != 1
            || djuBisanAngeredWithoutOffering() != 1
            || djuBisanOfferingsRequired() != 2
            || djuBisanLangCount() != 1
        )
            ++bad;
        // the powers - the polymorph self, the invisible, the ethereal, the
        // once per round, the nine-entry battery, the bless and its reverse
    if (djuBisanPolymorphSelfAtWill() != 1
            || djuBisanTurnInvisibleAtWill() != 1
            || djuBisanBecomeEtherealAtWill() != 1
            || djuBisanBlessReversible() != 1
            || djuBisanSpellsPerRound() != 1
            || djuBisanSpellBatteryCount() != 9
            || djuBisanBlessReversible() != 1
        )
            ++bad;
        // the nature - the mischief doctrine, the flees unless defending its
        // tree, the formidable if angered, the woods known by superstition,
        // the own-language-only speech
    if (djuBisanAvoidsCombatMischief() != 1
            || djuBisanFleesUnlessDefendingTree() != 1
            || djuBisanFormidableIfAngered() != 1
            || djuBisanWoodsKnownBySuperstition() != 1
            || djuBisanSpeaksOwnLanguageOnly() != 1
            || djuBisanVeryRare() != 1
            || djuBisanIntHigh() != 1
            || djuBisanNeutral() != 1
            || djuBisanSizeM() != 1
            || djuBisanPsionicNil() != 1
        )
            ++bad;
        printf("R707 OA monsters Bisan audit: bad %d\n", bad);
        if (bad) return 1;
    }
