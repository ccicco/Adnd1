    // ---- R216: the magical research pins audit ----
    // DMG pp.114-119: the holy/unholy water
    // receptacles, the spell research
    // economics and chance, the manufacture
    // gates, and the potion rules.
    {
        Magic_research magic_research;
        int bad = 0;
        // the receptacles: 5 metals
        static const int kCap[5] = { 6, 10, 18, 32, 50 };
        static const int kBMin[5] = { 130, 1900, 8000, 19000, 110000 };
        static const int kBMax[5] = { 180, 2400, 12000, 22000, 200000 };
        static const int kFont[5] = { 200, 500, 1000, 1500, 2000 };
        for (int m = 0; m < 5; ++m)
            if (magic_research.receptVialCapacity(m) != kCap[m] ||
                magic_research.receptBasinCostMin(m) != kBMin[m] ||
                magic_research.receptBasinCostMax(m) != kBMax[m] ||
                magic_research.receptFontCost(m) != kFont[m]) ++bad;
        if (magic_research.receptVialCapacity(-3) != 6 ||
            magic_research.receptVialCapacity(9) != 50 ||
            magic_research.receptBasinCostMin(4) != 110000 ||
            magic_research.receptBasinCostMax(4) != 200000 ||
            magic_research.receptFontCost(4) != 2000) ++bad;
        // mixed metals interpolate capacity
        if (magic_research.receptMixedCapacity(0, 1, 50) != 8 ||
            magic_research.receptMixedCapacity(0, 1, 100) != 6 ||
            magic_research.receptMixedCapacity(0, 1, 0) != 10 ||
            magic_research.receptMixedCapacity(2, 3, 50) != 25) ++bad;
        // the vials, weeks and limits
        if (magic_research.receptVialCostMin() != 2 ||
            magic_research.receptVialCostMax() != 5 ||
            magic_research.receptFontWeeksMin() != 4 ||
            magic_research.receptFontWeeksMax() != 10) ++bad;
        if (magic_research.receptCreationsPerWeek() != 1 ||
            magic_research.receptRitualHoursRest() != 8 ||
            magic_research.receptFontsPerEdifice() != 1) ++bad;
        if (magic_research.receptDefilementMinPct() != 20 ||
            magic_research.receptDefilementMaxPct() != 50 ||
            magic_research.receptDefilementWeeksMin() != 4 ||
            magic_research.receptDefilementWeeksMax() != 6) ++bad;
        if (magic_research.receptLycanthropyDelayMin() != 1 ||
            magic_research.receptLycanthropyDelayMax() != 4) ++bad;
        // the spell research economics
        if (magic_research.researchBaseCostPerLevelWeek() != 200 ||
            magic_research.researchVarCostMin() != 100 ||
            magic_research.researchVarCostMax() != 400 ||
            magic_research.researchNoLibraryFactor() != 10) ++bad;
        if (magic_research.researchWeeklyCost(3, 100, 1) != 900 ||
            magic_research.researchWeeklyCost(1, 400, 1) != 600 ||
            magic_research.researchWeeklyCost(2, 100, 0) != 4200) ++bad;
        if (magic_research.researchMinWeeks(1) != 2 ||
            magic_research.researchMinWeeks(9) != 10) ++bad;
        // the research chance: base 10-50 by
        // extra gp, + INT + level - 2 x SL
        if (magic_research.researchChancePct(12, 5, 3, 0) != 21 ||
            magic_research.researchChancePct(12, 5, 3, 2000) != 31 ||
            magic_research.researchChancePct(12, 5, 3, 8000) != 61 ||
            magic_research.researchChancePct(12, 5, 3, 20000) != 61 ||
            magic_research.researchChancePct(16, 9, 9, 8000) != 57) ++bad;
        if (magic_research.researchInterruptionWeeksLost(3) != 3 ||
            magic_research.researchInterruptionWeeksLost(-4) != 0 ||
            magic_research.researchHoursPerDay() != 8) ++bad;
        if (magic_research.researchImpossibleBeyondMuLevel() != 9 ||
            magic_research.researchImpossibleBeyondClericLevel() != 7) ++bad;
        if (magic_research.researchComboSpellLevel(2, 3) != 6 ||
            magic_research.researchLibraryGatherWeeks(4) != 4) ++bad;
        // the manufacture gates
        if (magic_research.manufactureClericLevel() != 11 ||
            magic_research.manufactureWizardLevel() != 12 ||
            magic_research.manufactureIllusionistLevel() != 11) ++bad;
        if (magic_research.playersMakeBooksArtifactsRelics() != 0 ||
            magic_research.playersMakeDwarvenElvenSpecials() != 0) ++bad;
        // the potion rules
        if (magic_research.potionMinLevelWithAlchemist() != 7 ||
            magic_research.potionAlchemistOptionalLevel() != 11 ||
            magic_research.potionAlchemistReductionPct() != 50 ||
            magic_research.potionsAtATime() != 1) ++bad;
        if (magic_research.potionLabCostMin() != 200 ||
            magic_research.potionLabCostMax() != 1000 ||
            magic_research.potionLabUpkeepPctMonthly() != 10) ++bad;
        if (magic_research.potionCostGp(250) != 250 ||
            magic_research.potionDays(250) != 3 ||
            magic_research.potionCostGp(0) != 200 ||
            magic_research.potionDays(0) != 2 ||
            magic_research.potionDays(101) != 2 ||
            magic_research.potionDays(100) != 1) ++bad;
        if (magic_research.potionAssassinPoisonLevel() != 9 ||
            magic_research.potionDelusionFailureMinPct() != 5 ||
            magic_research.potionDelusionFailureMaxPct() != 20) ++bad;
        printf("R216 magical research pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
