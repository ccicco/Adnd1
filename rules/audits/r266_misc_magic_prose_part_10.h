    // ---- R266: the III.E misc magic explanation
    // prose part 10 ----
    // Figurines of Wondrous Power, part2 lines
    // 433-479 - the slice that opens the kMisc3 rows
    // (row 0, the figurine band 01-15).
    {
        Miscmagic_figurines_of_wondrous_power miscmagic;
        Miscmagic_table3_footnotes miscmagic_table3_footnotes;
        int bad = 0;
        if (miscmagic.mmpFigTypeCount() != 7 ||
            miscmagic.mmpFigStatuetteInchesHigh() != 1) ++bad;
        if (miscmagic.mmpFlyAc() != 4 ||
            miscmagic.mmpFlyHitDiceBase() != 4 ||
            miscmagic.mmpFlyHitDiceExtra() != 4 ||
            miscmagic.mmpFlyAirManeuverClass() != 3 ||
            miscmagic.mmpFlySpeedUnladenInches() != 48 ||
            miscmagic.mmpFlySpeedLadenInches() != 36 ||
            miscmagic.mmpFlySpeedMaxLoadInches() != 24 ||
            miscmagic.mmpFlyLadenMaxPounds() != 210 ||
            miscmagic.mmpFlyMaxLoadPounds() != 350 ||
            miscmagic.mmpFlyUsesPerWeek() != 3 ||
            miscmagic.mmpFlyHoursPerDay() != 12) ++bad;
        if (miscmagic.mmpLionCount() != 2 ||
            miscmagic.mmpLionAcFront() != 5 ||
            miscmagic.mmpLionAcRear() != 6 ||
            miscmagic.mmpLionHitDiceBase() != 5 ||
            miscmagic.mmpLionHitDiceExtra() != 2 ||
            miscmagic.mmpLionSlainReturnWeeks() != 1 ||
            miscmagic.mmpLionUseDays() != 1) ++bad;
        if (miscmagic.mmpGoatCount() != 3 ||
            miscmagic.mmpGoatUsesBeforeBurnout() != 3 ||
            miscmagic.mmpGoatTravelAc() != 6 ||
            miscmagic.mmpGoatTravelHp() != 24 ||
            miscmagic.mmpGoatTravelAttacks() != 2 ||
            miscmagic.mmpGoatTravelHornDmgMin() != 1 ||
            miscmagic.mmpGoatTravelHornDmgMax() != 8 ||
            miscmagic.mmpGoatTravelHitDice() != 4) ++bad;
        if (miscmagic.mmpGoatTravelMoveInches() != 48 ||
            miscmagic.mmpGoatTravelMaxLoadPounds() != 280 ||
            miscmagic.mmpGoatTravelPoundsPerMoveLoss() != 14 ||
            miscmagic.mmpGoatTravelHoursPerWeek() != 24 ||
            miscmagic.mmpGoatTravelRestDays() != 1) ++bad;
        if (miscmagic.mmpGoatTravailHoofDmgMin() != 4 ||
            miscmagic.mmpGoatTravailHoofDmgMax() != 10 ||
            miscmagic.mmpGoatTravailBiteDmgMin() != 2 ||
            miscmagic.mmpGoatTravailBiteDmgMax() != 8 ||
            miscmagic.mmpGoatTravailHornDmgMin() != 2 ||
            miscmagic.mmpGoatTravailHornDmgMax() != 12 ||
            miscmagic.mmpGoatTravailChargeBonus() != 6 ||
            miscmagic.mmpGoatTravailChargeHornMin() != 8 ||
            miscmagic.mmpGoatTravailChargeHornMax() != 18) ++bad;
        if (miscmagic.mmpGoatTravailAc() != 0 ||
            miscmagic.mmpGoatTravailHp() != 96 ||
            miscmagic.mmpGoatTravailHitDice() != 16 ||
            miscmagic.mmpGoatTravailUsesPerMonth() != 1 ||
            miscmagic.mmpGoatTravailMoveInches() != 24 ||
            miscmagic.mmpGoatTerrorMoveInches() != 36 ||
            miscmagic.mmpGoatTerrorAc() != 2 ||
            miscmagic.mmpGoatTerrorHp() != 48) ++bad;
        if (miscmagic.mmpGoatTerrorHornSpearBonus() != 3 ||
            miscmagic.mmpGoatTerrorHornSwordBonus() != 6 ||
            miscmagic.mmpGoatTerrorRadiusInches() != 3 ||
            miscmagic.mmpGoatTerrorStrengthLossPct() != 50 ||
            miscmagic.mmpGoatTerrorHitPenalty() != -3 ||
            miscmagic.mmpGoatTerrorIntervalWeeks() != 2 ||
            miscmagic.mmpElephantHoursPerUse() != 24 ||
            miscmagic.mmpElephantUsesPerMonth() != 4) ++bad;
        if (miscmagic.mmpSteadGoodRiderPct() != 10 ||
            miscmagic.mmpSteadHoursPerUse() != 24 ||
            miscmagic.mmpSteadUsesPerWeek() != 1 ||
            miscmagic.mmpDogIntMin() != 8 ||
            miscmagic.mmpDogIntMax() != 10 ||
            miscmagic.mmpDogScentFreshPct() != 100 ||
            miscmagic.mmpDogScentFreshHours() != 1 ||
            miscmagic.mmpDogScentDecayPctPerHour() != 10) ++bad;
        if (miscmagic.mmpDogInfravisionFeet() != 90 ||
            miscmagic.mmpDogSpotHiddenPct() != 80 ||
            miscmagic.mmpDogSpotInvisiblePct() != 65 ||
            miscmagic.mmpDogSpotPhasedPct() != 50 ||
            miscmagic.mmpDogHoursPerUse() != 6 ||
            miscmagic.mmpDogUsesPerWeek() != 1 ||
            miscmagic.mmpOwlAc() != 7 ||
            miscmagic.mmpOwlMoveInches() != 24) ++bad;
        if (miscmagic.mmpOwlHpMin() != 2 ||
            miscmagic.mmpOwlHpMax() != 4 ||
            miscmagic.mmpOwlDmgMin() != 1 ||
            miscmagic.mmpOwlDmgMax() != 2 ||
            miscmagic.mmpOwlGiantUses() != 3 ||
            miscmagic.mmpOwlSilencePct() != 95 ||
            miscmagic.mmpOwlInfravisionFeet() != 90 ||
            miscmagic.mmpOwlDarkVisionFactor() != 2) ++bad;
        if (miscmagic.mmpOwlHearMouseFeet() != 60 ||
            miscmagic.mmpOwlCounterStealthPct() != 50 ||
            miscmagic.mmpOwlIntMin() != 2 ||
            miscmagic.mmpOwlIntMax() != 4) ++bad;
        // the arithmetic: the travail charge horn
        // equals the horn plus the charge bonus
        if (miscmagic.mmpGoatTravailHornDmgMin() +
            miscmagic.mmpGoatTravailChargeBonus() !=
            miscmagic.mmpGoatTravailChargeHornMin() ||
            miscmagic.mmpGoatTravailHornDmgMax() +
            miscmagic.mmpGoatTravailChargeBonus() !=
            miscmagic.mmpGoatTravailChargeHornMax()) ++bad;
        // the figurine type table bands, static
        static const int kFigLo[7] = {
            1, 16, 31, 41, 56, 66, 86,
        };
        static const int kFigHi[7] = {
            15, 30, 40, 55, 65, 85, 100,
        };
        for (int i = 0; i < 7; ++i)
            if (miscmagic.mmpFigTypeLo(i) != kFigLo[i] ||
                miscmagic.mmpFigTypeHi(i) != kFigHi[i]) ++bad;
        for (int i = 0; i < 6; ++i)
            if (miscmagic.mmpFigTypeLo(i + 1) !=
                miscmagic.mmpFigTypeHi(i) + 1) ++bad;
        // the marble elephant type table bands
        static const int kEleLo[4] = {
            1, 51, 91, 94,
        };
        static const int kEleHi[4] = {
            50, 90, 93, 100,
        };
        for (int i = 0; i < 4; ++i)
            if (miscmagic.mmpElephantTypeLo(i) != kEleLo[i] ||
                miscmagic.mmpElephantTypeHi(i) != kEleHi[i]) ++bad;
        for (int i = 0; i < 3; ++i)
            if (miscmagic.mmpElephantTypeLo(i + 1) !=
                miscmagic.mmpElephantTypeHi(i) + 1) ++bad;
        // the kMisc3 row this slice pins: row 0,
        // the Figurine band 01-15, no class marks
        if (miscmagic_table3_footnotes.m3RowLo(0) != 1 ||
            miscmagic_table3_footnotes.m3RowHi(0) != 15 ||
            miscmagic_table3_footnotes.m3UsableByCleric(0) ||
            miscmagic_table3_footnotes.m3UsableByFighter(0) ||
            miscmagic_table3_footnotes.m3UsableByThief(0) ||
            miscmagic_table3_footnotes.m3StarCount(0) != 1 ||
            miscmagic_table3_footnotes.m3IsPerFacetValued(0)) ++bad;
        // the per-hit-die values and the row 4
        // (C, F, T) positive control
        if (miscmagic_table3_footnotes.m3FigurinePerHitDieXp() != 100 ||
            miscmagic_table3_footnotes.m3FigurinePerHitDieGp() != 1000 ||
            !miscmagic_table3_footnotes.m3UsableByCleric(4) ||
            !miscmagic_table3_footnotes.m3UsableByFighter(4) ||
            !miscmagic_table3_footnotes.m3UsableByThief(4)) ++bad;
        printf("R266 misc magic prose part 10 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
