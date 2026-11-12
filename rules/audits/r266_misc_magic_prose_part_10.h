    // ---- R266: the III.E misc magic explanation
    // prose part 10 ----
    // Figurines of Wondrous Power, part2 lines
    // 433-479 - the slice that opens the kMisc3 rows
    // (row 0, the figurine band 01-15).
    {
        Miscmagic_figurines_of_wondrous_power miscmagic_figurines_of_wondrous_power;
        Miscmagic_table3_footnotes miscmagic_table3_footnotes;
        int bad = 0;
        if (miscmagic_figurines_of_wondrous_power.mmpFigTypeCount() != 7 ||
            miscmagic_figurines_of_wondrous_power.mmpFigStatuetteInchesHigh() != 1) ++bad;
        if (miscmagic_figurines_of_wondrous_power.mmpFlyAc() != 4 ||
            miscmagic_figurines_of_wondrous_power.mmpFlyHitDiceBase() != 4 ||
            miscmagic_figurines_of_wondrous_power.mmpFlyHitDiceExtra() != 4 ||
            miscmagic_figurines_of_wondrous_power.mmpFlyAirManeuverClass() != 3 ||
            miscmagic_figurines_of_wondrous_power.mmpFlySpeedUnladenInches() != 48 ||
            miscmagic_figurines_of_wondrous_power.mmpFlySpeedLadenInches() != 36 ||
            miscmagic_figurines_of_wondrous_power.mmpFlySpeedMaxLoadInches() != 24 ||
            miscmagic_figurines_of_wondrous_power.mmpFlyLadenMaxPounds() != 210 ||
            miscmagic_figurines_of_wondrous_power.mmpFlyMaxLoadPounds() != 350 ||
            miscmagic_figurines_of_wondrous_power.mmpFlyUsesPerWeek() != 3 ||
            miscmagic_figurines_of_wondrous_power.mmpFlyHoursPerDay() != 12) ++bad;
        if (miscmagic_figurines_of_wondrous_power.mmpLionCount() != 2 ||
            miscmagic_figurines_of_wondrous_power.mmpLionAcFront() != 5 ||
            miscmagic_figurines_of_wondrous_power.mmpLionAcRear() != 6 ||
            miscmagic_figurines_of_wondrous_power.mmpLionHitDiceBase() != 5 ||
            miscmagic_figurines_of_wondrous_power.mmpLionHitDiceExtra() != 2 ||
            miscmagic_figurines_of_wondrous_power.mmpLionSlainReturnWeeks() != 1 ||
            miscmagic_figurines_of_wondrous_power.mmpLionUseDays() != 1) ++bad;
        if (miscmagic_figurines_of_wondrous_power.mmpGoatCount() != 3 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatUsesBeforeBurnout() != 3 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTravelAc() != 6 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTravelHp() != 24 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTravelAttacks() != 2 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTravelHornDmgMin() != 1 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTravelHornDmgMax() != 8 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTravelHitDice() != 4) ++bad;
        if (miscmagic_figurines_of_wondrous_power.mmpGoatTravelMoveInches() != 48 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTravelMaxLoadPounds() != 280 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTravelPoundsPerMoveLoss() != 14 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTravelHoursPerWeek() != 24 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTravelRestDays() != 1) ++bad;
        if (miscmagic_figurines_of_wondrous_power.mmpGoatTravailHoofDmgMin() != 4 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTravailHoofDmgMax() != 10 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTravailBiteDmgMin() != 2 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTravailBiteDmgMax() != 8 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTravailHornDmgMin() != 2 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTravailHornDmgMax() != 12 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTravailChargeBonus() != 6 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTravailChargeHornMin() != 8 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTravailChargeHornMax() != 18) ++bad;
        if (miscmagic_figurines_of_wondrous_power.mmpGoatTravailAc() != 0 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTravailHp() != 96 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTravailHitDice() != 16 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTravailUsesPerMonth() != 1 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTravailMoveInches() != 24 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTerrorMoveInches() != 36 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTerrorAc() != 2 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTerrorHp() != 48) ++bad;
        if (miscmagic_figurines_of_wondrous_power.mmpGoatTerrorHornSpearBonus() != 3 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTerrorHornSwordBonus() != 6 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTerrorRadiusInches() != 3 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTerrorStrengthLossPct() != 50 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTerrorHitPenalty() != -3 ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTerrorIntervalWeeks() != 2 ||
            miscmagic_figurines_of_wondrous_power.mmpElephantHoursPerUse() != 24 ||
            miscmagic_figurines_of_wondrous_power.mmpElephantUsesPerMonth() != 4) ++bad;
        if (miscmagic_figurines_of_wondrous_power.mmpSteadGoodRiderPct() != 10 ||
            miscmagic_figurines_of_wondrous_power.mmpSteadHoursPerUse() != 24 ||
            miscmagic_figurines_of_wondrous_power.mmpSteadUsesPerWeek() != 1 ||
            miscmagic_figurines_of_wondrous_power.mmpDogIntMin() != 8 ||
            miscmagic_figurines_of_wondrous_power.mmpDogIntMax() != 10 ||
            miscmagic_figurines_of_wondrous_power.mmpDogScentFreshPct() != 100 ||
            miscmagic_figurines_of_wondrous_power.mmpDogScentFreshHours() != 1 ||
            miscmagic_figurines_of_wondrous_power.mmpDogScentDecayPctPerHour() != 10) ++bad;
        if (miscmagic_figurines_of_wondrous_power.mmpDogInfravisionFeet() != 90 ||
            miscmagic_figurines_of_wondrous_power.mmpDogSpotHiddenPct() != 80 ||
            miscmagic_figurines_of_wondrous_power.mmpDogSpotInvisiblePct() != 65 ||
            miscmagic_figurines_of_wondrous_power.mmpDogSpotPhasedPct() != 50 ||
            miscmagic_figurines_of_wondrous_power.mmpDogHoursPerUse() != 6 ||
            miscmagic_figurines_of_wondrous_power.mmpDogUsesPerWeek() != 1 ||
            miscmagic_figurines_of_wondrous_power.mmpOwlAc() != 7 ||
            miscmagic_figurines_of_wondrous_power.mmpOwlMoveInches() != 24) ++bad;
        if (miscmagic_figurines_of_wondrous_power.mmpOwlHpMin() != 2 ||
            miscmagic_figurines_of_wondrous_power.mmpOwlHpMax() != 4 ||
            miscmagic_figurines_of_wondrous_power.mmpOwlDmgMin() != 1 ||
            miscmagic_figurines_of_wondrous_power.mmpOwlDmgMax() != 2 ||
            miscmagic_figurines_of_wondrous_power.mmpOwlGiantUses() != 3 ||
            miscmagic_figurines_of_wondrous_power.mmpOwlSilencePct() != 95 ||
            miscmagic_figurines_of_wondrous_power.mmpOwlInfravisionFeet() != 90 ||
            miscmagic_figurines_of_wondrous_power.mmpOwlDarkVisionFactor() != 2) ++bad;
        if (miscmagic_figurines_of_wondrous_power.mmpOwlHearMouseFeet() != 60 ||
            miscmagic_figurines_of_wondrous_power.mmpOwlCounterStealthPct() != 50 ||
            miscmagic_figurines_of_wondrous_power.mmpOwlIntMin() != 2 ||
            miscmagic_figurines_of_wondrous_power.mmpOwlIntMax() != 4) ++bad;
        // the arithmetic: the travail charge horn
        // equals the horn plus the charge bonus
        if (miscmagic_figurines_of_wondrous_power.mmpGoatTravailHornDmgMin() +
            miscmagic_figurines_of_wondrous_power.mmpGoatTravailChargeBonus() !=
            miscmagic_figurines_of_wondrous_power.mmpGoatTravailChargeHornMin() ||
            miscmagic_figurines_of_wondrous_power.mmpGoatTravailHornDmgMax() +
            miscmagic_figurines_of_wondrous_power.mmpGoatTravailChargeBonus() !=
            miscmagic_figurines_of_wondrous_power.mmpGoatTravailChargeHornMax()) ++bad;
        // the figurine type table bands, static
        static const int kFigLo[7] = {
            1, 16, 31, 41, 56, 66, 86,
        };
        static const int kFigHi[7] = {
            15, 30, 40, 55, 65, 85, 100,
        };
        for (int i = 0; i < 7; ++i)
            if (miscmagic_figurines_of_wondrous_power.mmpFigTypeLo(i) != kFigLo[i] ||
                miscmagic_figurines_of_wondrous_power.mmpFigTypeHi(i) != kFigHi[i]) ++bad;
        for (int i = 0; i < 6; ++i)
            if (miscmagic_figurines_of_wondrous_power.mmpFigTypeLo(i + 1) !=
                miscmagic_figurines_of_wondrous_power.mmpFigTypeHi(i) + 1) ++bad;
        // the marble elephant type table bands
        static const int kEleLo[4] = {
            1, 51, 91, 94,
        };
        static const int kEleHi[4] = {
            50, 90, 93, 100,
        };
        for (int i = 0; i < 4; ++i)
            if (miscmagic_figurines_of_wondrous_power.mmpElephantTypeLo(i) != kEleLo[i] ||
                miscmagic_figurines_of_wondrous_power.mmpElephantTypeHi(i) != kEleHi[i]) ++bad;
        for (int i = 0; i < 3; ++i)
            if (miscmagic_figurines_of_wondrous_power.mmpElephantTypeLo(i + 1) !=
                miscmagic_figurines_of_wondrous_power.mmpElephantTypeHi(i) + 1) ++bad;
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
