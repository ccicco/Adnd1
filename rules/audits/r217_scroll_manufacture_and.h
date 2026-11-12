    // ---- R217: the scroll manufacture and fabrication pins audit ----
    // DMG pp.118-121: the scroll inscription
    // rules and failure chance, and the
    // fabrication of other magic items.
    {
        Scroll_manufacture scroll_manufacture;
        int bad = 0;
        // the inscription gates
        if (scroll_manufacture.scrollMinInscribeLevel() != 7 ||
            scroll_manufacture.inscriberClassCount() != 4 ||
            scroll_manufacture.spellMustBeEmployable() != 1) ++bad;
        // the protection scroll split
        if (PS_COUNT != 8 ||
            PS_UNDEAD != 2 ||
            PS_DEMONS != 3 ||
            PS_PETRIFICATION != 7) ++bad;
        if (scroll_manufacture.protectionClericalCount() != 3 ||
            scroll_manufacture.protectionMuCount() != 5 ||
            scroll_manufacture.curseScrollsAnySpellUser() != 1) ++bad;
        for (int k = -1; k < 9; ++k)
            if (scroll_manufacture.protectionScrollIsClerical(k)
                    != ((k > 2) ? 0 : 1)) ++bad;
        // the materials
        if (SCM_COUNT != 3) ++bad;
        static const int kMatCost[3] = { 2, 4, 8 };
        static const int kMatMod[3] = { 5, 0, -5 };
        for (int m = 0; m < 3; ++m)
            if (scroll_manufacture.scrollSheetCostMin(m) != kMatCost[m] ||
                scroll_manufacture.scrollMaterialFailMod(m) != kMatMod[m]) ++bad;
        if (scroll_manufacture.scrollSheetCostMin(-2) != 2 ||
            scroll_manufacture.scrollSheetCostMin(9) != 8) ++bad;
        if (scroll_manufacture.quillPerSpell() != 1 ||
            scroll_manufacture.quillNamedCreatures() != 6 ||
            scroll_manufacture.inkBaseCount() != 2 ||
            scroll_manufacture.inkPerSpellDistinct() != 1) ++bad;
        // the preparation and failure rules
        if (scroll_manufacture.scrollPrepDays(1) != 1 ||
            scroll_manufacture.scrollPrepDays(2) != 2 ||
            scroll_manufacture.scrollPrepDays(7) != 7 ||
            scroll_manufacture.prepMustBeContinuous() != 1) ++bad;
        if (scroll_manufacture.scrollFailurePct(7, 14, 1) != 13 ||
            scroll_manufacture.scrollFailurePct(1, 1, 1) != 20 ||
            scroll_manufacture.scrollFailurePct(1, 7, 1) != 14 ||
            scroll_manufacture.scrollFailurePct(9, 7, 1) != 22 ||
            scroll_manufacture.scrollFailurePct(1, 7, 0) != 19 ||
            scroll_manufacture.scrollFailurePct(1, 7, 2) != 9) ++bad;
        if (scroll_manufacture.scrollSuccessRollIsGreaterThan() != 1 ||
            scroll_manufacture.scrollMaxSpells() != 7 ||
            scroll_manufacture.oneFailureBlocksFurther() != 1) ++bad;
        // transcribing an unknown spell
        if (scroll_manufacture.transcribeNeedsReadMagic() != 1 ||
            scroll_manufacture.transcribeDays(4) != 4 ||
            scroll_manufacture.transcribeEraseFromScroll() != 1 ||
            scroll_manufacture.ownScrollsNeedNoReadMagic() != 1) ++bad;
        // the fabrication of other magic items
        if (scroll_manufacture.fabricateNeedsEnchantAnItem() != 1 ||
            scroll_manufacture.fabricateClericalUsesEnchant() != 0) ++bad;
        if (scroll_manufacture.fabRestDays(2000) != 20 ||
            scroll_manufacture.fabRestDays(100) != 1 ||
            scroll_manufacture.fabRestDays(101) != 2 ||
            scroll_manufacture.fabRestDays(250) != 3 ||
            scroll_manufacture.fabRestDays(-5) != 0 ||
            scroll_manufacture.fabRestNoAdventuringOrSpells() != 1) ++bad;
        if (scroll_manufacture.permanentDweomerNeedsPermanency() != 1 ||
            scroll_manufacture.chargedItemsNeedPermanency() != 0) ++bad;
        // the cleric and druid retreat
        if (scroll_manufacture.clericRetreatDays() != 14 ||
            scroll_manufacture.clericFastDays() != 7 ||
            scroll_manufacture.clericPurifyDays() != 1 ||
            scroll_manufacture.clericEmpowerPctPerDay() != 1 ||
            scroll_manufacture.clericChargedSpellWindowHours() != 24) ++bad;
        // the illusionist gates
        if (scroll_manufacture.illusionistScrollLevel() != 7 ||
            scroll_manufacture.illusionistOneShotChargedLevel() != 11 ||
            scroll_manufacture.illusionistPermanentDweomerLevel() != 14 ||
            scroll_manufacture.illusionistMajorCreationInstillHours() != 16 ||
            scroll_manufacture.illusionistPermanentGemCost() != 10000) ++bad;
        // the charmed or enslaved maker rule
        if (scroll_manufacture.enslavedMakerCanFabricate() != 0) ++bad;
        printf("R217 scroll manufacture and fabrication pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
