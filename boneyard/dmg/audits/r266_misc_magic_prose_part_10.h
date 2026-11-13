    // ---- R266: the III.E misc magic explanation
    // prose part 10 ----
    // Figurines of Wondrous Power, part2 lines
    // 433-479 - the slice that opens the kMisc3 rows
    // (row 0, the figurine band 01-15).
    {
        int bad = 0;
        if (rules::mmpFigTypeCount() != 7 ||
            rules::mmpFigStatuetteInchesHigh() != 1) ++bad;
        if (rules::mmpFlyAc() != 4 ||
            rules::mmpFlyHitDiceBase() != 4 ||
            rules::mmpFlyHitDiceExtra() != 4 ||
            rules::mmpFlyAirManeuverClass() != 3 ||
            rules::mmpFlySpeedUnladenInches() != 48 ||
            rules::mmpFlySpeedLadenInches() != 36 ||
            rules::mmpFlySpeedMaxLoadInches() != 24 ||
            rules::mmpFlyLadenMaxPounds() != 210 ||
            rules::mmpFlyMaxLoadPounds() != 350 ||
            rules::mmpFlyUsesPerWeek() != 3 ||
            rules::mmpFlyHoursPerDay() != 12) ++bad;
        if (rules::mmpLionCount() != 2 ||
            rules::mmpLionAcFront() != 5 ||
            rules::mmpLionAcRear() != 6 ||
            rules::mmpLionHitDiceBase() != 5 ||
            rules::mmpLionHitDiceExtra() != 2 ||
            rules::mmpLionSlainReturnWeeks() != 1 ||
            rules::mmpLionUseDays() != 1) ++bad;
        if (rules::mmpGoatCount() != 3 ||
            rules::mmpGoatUsesBeforeBurnout() != 3 ||
            rules::mmpGoatTravelAc() != 6 ||
            rules::mmpGoatTravelHp() != 24 ||
            rules::mmpGoatTravelAttacks() != 2 ||
            rules::mmpGoatTravelHornDmgMin() != 1 ||
            rules::mmpGoatTravelHornDmgMax() != 8 ||
            rules::mmpGoatTravelHitDice() != 4) ++bad;
        if (rules::mmpGoatTravelMoveInches() != 48 ||
            rules::mmpGoatTravelMaxLoadPounds() != 280 ||
            rules::mmpGoatTravelPoundsPerMoveLoss() != 14 ||
            rules::mmpGoatTravelHoursPerWeek() != 24 ||
            rules::mmpGoatTravelRestDays() != 1) ++bad;
        if (rules::mmpGoatTravailHoofDmgMin() != 4 ||
            rules::mmpGoatTravailHoofDmgMax() != 10 ||
            rules::mmpGoatTravailBiteDmgMin() != 2 ||
            rules::mmpGoatTravailBiteDmgMax() != 8 ||
            rules::mmpGoatTravailHornDmgMin() != 2 ||
            rules::mmpGoatTravailHornDmgMax() != 12 ||
            rules::mmpGoatTravailChargeBonus() != 6 ||
            rules::mmpGoatTravailChargeHornMin() != 8 ||
            rules::mmpGoatTravailChargeHornMax() != 18) ++bad;
        if (rules::mmpGoatTravailAc() != 0 ||
            rules::mmpGoatTravailHp() != 96 ||
            rules::mmpGoatTravailHitDice() != 16 ||
            rules::mmpGoatTravailUsesPerMonth() != 1 ||
            rules::mmpGoatTravailMoveInches() != 24 ||
            rules::mmpGoatTerrorMoveInches() != 36 ||
            rules::mmpGoatTerrorAc() != 2 ||
            rules::mmpGoatTerrorHp() != 48) ++bad;
        if (rules::mmpGoatTerrorHornSpearBonus() != 3 ||
            rules::mmpGoatTerrorHornSwordBonus() != 6 ||
            rules::mmpGoatTerrorRadiusInches() != 3 ||
            rules::mmpGoatTerrorStrengthLossPct() != 50 ||
            rules::mmpGoatTerrorHitPenalty() != -3 ||
            rules::mmpGoatTerrorIntervalWeeks() != 2 ||
            rules::mmpElephantHoursPerUse() != 24 ||
            rules::mmpElephantUsesPerMonth() != 4) ++bad;
        if (rules::mmpSteadGoodRiderPct() != 10 ||
            rules::mmpSteadHoursPerUse() != 24 ||
            rules::mmpSteadUsesPerWeek() != 1 ||
            rules::mmpDogIntMin() != 8 ||
            rules::mmpDogIntMax() != 10 ||
            rules::mmpDogScentFreshPct() != 100 ||
            rules::mmpDogScentFreshHours() != 1 ||
            rules::mmpDogScentDecayPctPerHour() != 10) ++bad;
        if (rules::mmpDogInfravisionFeet() != 90 ||
            rules::mmpDogSpotHiddenPct() != 80 ||
            rules::mmpDogSpotInvisiblePct() != 65 ||
            rules::mmpDogSpotPhasedPct() != 50 ||
            rules::mmpDogHoursPerUse() != 6 ||
            rules::mmpDogUsesPerWeek() != 1 ||
            rules::mmpOwlAc() != 7 ||
            rules::mmpOwlMoveInches() != 24) ++bad;
        if (rules::mmpOwlHpMin() != 2 ||
            rules::mmpOwlHpMax() != 4 ||
            rules::mmpOwlDmgMin() != 1 ||
            rules::mmpOwlDmgMax() != 2 ||
            rules::mmpOwlGiantUses() != 3 ||
            rules::mmpOwlSilencePct() != 95 ||
            rules::mmpOwlInfravisionFeet() != 90 ||
            rules::mmpOwlDarkVisionFactor() != 2) ++bad;
        if (rules::mmpOwlHearMouseFeet() != 60 ||
            rules::mmpOwlCounterStealthPct() != 50 ||
            rules::mmpOwlIntMin() != 2 ||
            rules::mmpOwlIntMax() != 4) ++bad;
        // the arithmetic: the travail charge horn
        // equals the horn plus the charge bonus
        if (rules::mmpGoatTravailHornDmgMin() +
            rules::mmpGoatTravailChargeBonus() !=
            rules::mmpGoatTravailChargeHornMin() ||
            rules::mmpGoatTravailHornDmgMax() +
            rules::mmpGoatTravailChargeBonus() !=
            rules::mmpGoatTravailChargeHornMax()) ++bad;
        // the figurine type table bands, static
        static const int kFigLo[7] = {
            1, 16, 31, 41, 56, 66, 86,
        };
        static const int kFigHi[7] = {
            15, 30, 40, 55, 65, 85, 100,
        };
        for (int i = 0; i < 7; ++i)
            if (rules::mmpFigTypeLo(i) != kFigLo[i] ||
                rules::mmpFigTypeHi(i) != kFigHi[i]) ++bad;
        for (int i = 0; i < 6; ++i)
            if (rules::mmpFigTypeLo(i + 1) !=
                rules::mmpFigTypeHi(i) + 1) ++bad;
        // the marble elephant type table bands
        static const int kEleLo[4] = {
            1, 51, 91, 94,
        };
        static const int kEleHi[4] = {
            50, 90, 93, 100,
        };
        for (int i = 0; i < 4; ++i)
            if (rules::mmpElephantTypeLo(i) != kEleLo[i] ||
                rules::mmpElephantTypeHi(i) != kEleHi[i]) ++bad;
        for (int i = 0; i < 3; ++i)
            if (rules::mmpElephantTypeLo(i + 1) !=
                rules::mmpElephantTypeHi(i) + 1) ++bad;
        // the kMisc3 row this slice pins: row 0,
        // the Figurine band 01-15, no class marks
        if (rules::m3RowLo(0) != 1 ||
            rules::m3RowHi(0) != 15 ||
            rules::m3UsableByCleric(0) ||
            rules::m3UsableByFighter(0) ||
            rules::m3UsableByThief(0) ||
            rules::m3StarCount(0) != 1 ||
            rules::m3IsPerFacetValued(0)) ++bad;
        // the per-hit-die values and the row 4
        // (C, F, T) positive control
        if (rules::m3FigurinePerHitDieXp() != 100 ||
            rules::m3FigurinePerHitDieGp() != 1000 ||
            !rules::m3UsableByCleric(4) ||
            !rules::m3UsableByFighter(4) ||
            !rules::m3UsableByThief(4)) ++bad;
        printf("R266 misc magic prose part 10 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
