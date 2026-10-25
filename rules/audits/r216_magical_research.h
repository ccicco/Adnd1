    // ---- R216: the magical research pins audit ----
    // DMG pp.114-119: the holy/unholy water
    // receptacles, the spell research
    // economics and chance, the manufacture
    // gates, and the potion rules.
    {
        int bad = 0;
        // the receptacles: 5 metals
        static const int kCap[5] = { 6, 10, 18, 32, 50 };
        static const int kBMin[5] = { 130, 1900, 8000, 19000, 110000 };
        static const int kBMax[5] = { 180, 2400, 12000, 22000, 200000 };
        static const int kFont[5] = { 200, 500, 1000, 1500, 2000 };
        for (int m = 0; m < 5; ++m)
            if (rules::receptVialCapacity(m) != kCap[m] ||
                rules::receptBasinCostMin(m) != kBMin[m] ||
                rules::receptBasinCostMax(m) != kBMax[m] ||
                rules::receptFontCost(m) != kFont[m]) ++bad;
        if (rules::receptVialCapacity(-3) != 6 ||
            rules::receptVialCapacity(9) != 50 ||
            rules::receptBasinCostMin(4) != 110000 ||
            rules::receptBasinCostMax(4) != 200000 ||
            rules::receptFontCost(4) != 2000) ++bad;
        // mixed metals interpolate capacity
        if (rules::receptMixedCapacity(0, 1, 50) != 8 ||
            rules::receptMixedCapacity(0, 1, 100) != 6 ||
            rules::receptMixedCapacity(0, 1, 0) != 10 ||
            rules::receptMixedCapacity(2, 3, 50) != 25) ++bad;
        // the vials, weeks and limits
        if (rules::receptVialCostMin() != 2 ||
            rules::receptVialCostMax() != 5 ||
            rules::receptFontWeeksMin() != 4 ||
            rules::receptFontWeeksMax() != 10) ++bad;
        if (rules::receptCreationsPerWeek() != 1 ||
            rules::receptRitualHoursRest() != 8 ||
            rules::receptFontsPerEdifice() != 1) ++bad;
        if (rules::receptDefilementMinPct() != 20 ||
            rules::receptDefilementMaxPct() != 50 ||
            rules::receptDefilementWeeksMin() != 4 ||
            rules::receptDefilementWeeksMax() != 6) ++bad;
        if (rules::receptLycanthropyDelayMin() != 1 ||
            rules::receptLycanthropyDelayMax() != 4) ++bad;
        // the spell research economics
        if (rules::researchBaseCostPerLevelWeek() != 200 ||
            rules::researchVarCostMin() != 100 ||
            rules::researchVarCostMax() != 400 ||
            rules::researchNoLibraryFactor() != 10) ++bad;
        if (rules::researchWeeklyCost(3, 100, 1) != 900 ||
            rules::researchWeeklyCost(1, 400, 1) != 600 ||
            rules::researchWeeklyCost(2, 100, 0) != 4200) ++bad;
        if (rules::researchMinWeeks(1) != 2 ||
            rules::researchMinWeeks(9) != 10) ++bad;
        // the research chance: base 10-50 by
        // extra gp, + INT + level - 2 x SL
        if (rules::researchChancePct(12, 5, 3, 0) != 21 ||
            rules::researchChancePct(12, 5, 3, 2000) != 31 ||
            rules::researchChancePct(12, 5, 3, 8000) != 61 ||
            rules::researchChancePct(12, 5, 3, 20000) != 61 ||
            rules::researchChancePct(16, 9, 9, 8000) != 57) ++bad;
        if (rules::researchInterruptionWeeksLost(3) != 3 ||
            rules::researchInterruptionWeeksLost(-4) != 0 ||
            rules::researchHoursPerDay() != 8) ++bad;
        if (rules::researchImpossibleBeyondMuLevel() != 9 ||
            rules::researchImpossibleBeyondClericLevel() != 7) ++bad;
        if (rules::researchComboSpellLevel(2, 3) != 6 ||
            rules::researchLibraryGatherWeeks(4) != 4) ++bad;
        // the manufacture gates
        if (rules::manufactureClericLevel() != 11 ||
            rules::manufactureWizardLevel() != 12 ||
            rules::manufactureIllusionistLevel() != 11) ++bad;
        if (rules::playersMakeBooksArtifactsRelics() != 0 ||
            rules::playersMakeDwarvenElvenSpecials() != 0) ++bad;
        // the potion rules
        if (rules::potionMinLevelWithAlchemist() != 7 ||
            rules::potionAlchemistOptionalLevel() != 11 ||
            rules::potionAlchemistReductionPct() != 50 ||
            rules::potionsAtATime() != 1) ++bad;
        if (rules::potionLabCostMin() != 200 ||
            rules::potionLabCostMax() != 1000 ||
            rules::potionLabUpkeepPctMonthly() != 10) ++bad;
        if (rules::potionCostGp(250) != 250 ||
            rules::potionDays(250) != 3 ||
            rules::potionCostGp(0) != 200 ||
            rules::potionDays(0) != 2 ||
            rules::potionDays(101) != 2 ||
            rules::potionDays(100) != 1) ++bad;
        if (rules::potionAssassinPoisonLevel() != 9 ||
            rules::potionDelusionFailureMinPct() != 5 ||
            rules::potionDelusionFailureMaxPct() != 20) ++bad;
        printf("R216 magical research pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
