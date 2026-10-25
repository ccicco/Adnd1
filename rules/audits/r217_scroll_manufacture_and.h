    // ---- R217: the scroll manufacture and fabrication pins audit ----
    // DMG pp.118-121: the scroll inscription
    // rules and failure chance, and the
    // fabrication of other magic items.
    {
        int bad = 0;
        // the inscription gates
        if (rules::scrollMinInscribeLevel() != 7 ||
            rules::inscriberClassCount() != 4 ||
            rules::spellMustBeEmployable() != 1) ++bad;
        // the protection scroll split
        if (rules::PS_COUNT != 8 ||
            rules::PS_UNDEAD != 2 ||
            rules::PS_DEMONS != 3 ||
            rules::PS_PETRIFICATION != 7) ++bad;
        if (rules::protectionClericalCount() != 3 ||
            rules::protectionMuCount() != 5 ||
            rules::curseScrollsAnySpellUser() != 1) ++bad;
        for (int k = -1; k < 9; ++k)
            if (rules::protectionScrollIsClerical(k)
                    != ((k > 2) ? 0 : 1)) ++bad;
        // the materials
        if (rules::SCM_COUNT != 3) ++bad;
        static const int kMatCost[3] = { 2, 4, 8 };
        static const int kMatMod[3] = { 5, 0, -5 };
        for (int m = 0; m < 3; ++m)
            if (rules::scrollSheetCostMin(m) != kMatCost[m] ||
                rules::scrollMaterialFailMod(m) != kMatMod[m]) ++bad;
        if (rules::scrollSheetCostMin(-2) != 2 ||
            rules::scrollSheetCostMin(9) != 8) ++bad;
        if (rules::quillPerSpell() != 1 ||
            rules::quillNamedCreatures() != 6 ||
            rules::inkBaseCount() != 2 ||
            rules::inkPerSpellDistinct() != 1) ++bad;
        // the preparation and failure rules
        if (rules::scrollPrepDays(1) != 1 ||
            rules::scrollPrepDays(2) != 2 ||
            rules::scrollPrepDays(7) != 7 ||
            rules::prepMustBeContinuous() != 1) ++bad;
        if (rules::scrollFailurePct(7, 14, 1) != 13 ||
            rules::scrollFailurePct(1, 1, 1) != 20 ||
            rules::scrollFailurePct(1, 7, 1) != 14 ||
            rules::scrollFailurePct(9, 7, 1) != 22 ||
            rules::scrollFailurePct(1, 7, 0) != 19 ||
            rules::scrollFailurePct(1, 7, 2) != 9) ++bad;
        if (rules::scrollSuccessRollIsGreaterThan() != 1 ||
            rules::scrollMaxSpells() != 7 ||
            rules::oneFailureBlocksFurther() != 1) ++bad;
        // transcribing an unknown spell
        if (rules::transcribeNeedsReadMagic() != 1 ||
            rules::transcribeDays(4) != 4 ||
            rules::transcribeEraseFromScroll() != 1 ||
            rules::ownScrollsNeedNoReadMagic() != 1) ++bad;
        // the fabrication of other magic items
        if (rules::fabricateNeedsEnchantAnItem() != 1 ||
            rules::fabricateClericalUsesEnchant() != 0) ++bad;
        if (rules::fabRestDays(2000) != 20 ||
            rules::fabRestDays(100) != 1 ||
            rules::fabRestDays(101) != 2 ||
            rules::fabRestDays(250) != 3 ||
            rules::fabRestDays(-5) != 0 ||
            rules::fabRestNoAdventuringOrSpells() != 1) ++bad;
        if (rules::permanentDweomerNeedsPermanency() != 1 ||
            rules::chargedItemsNeedPermanency() != 0) ++bad;
        // the cleric and druid retreat
        if (rules::clericRetreatDays() != 14 ||
            rules::clericFastDays() != 7 ||
            rules::clericPurifyDays() != 1 ||
            rules::clericEmpowerPctPerDay() != 1 ||
            rules::clericChargedSpellWindowHours() != 24) ++bad;
        // the illusionist gates
        if (rules::illusionistScrollLevel() != 7 ||
            rules::illusionistOneShotChargedLevel() != 11 ||
            rules::illusionistPermanentDweomerLevel() != 14 ||
            rules::illusionistMajorCreationInstillHours() != 16 ||
            rules::illusionistPermanentGemCost() != 10000) ++bad;
        // the charmed or enslaved maker rule
        if (rules::enslavedMakerCanFabricate() != 0) ++bad;
        printf("R217 scroll manufacture and fabrication pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
