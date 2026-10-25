    // ---- R523 DSG mining tail audit ----
    // The DSG mining tail pins the placer value (gold, silver or platinum
    // only, the normal quality determination then the 1d4-times-10 percent of
    // full value), the smelting (the one-smelter rule, the bellows and
    // unmeltable containers over a coal fire, the impossible concealment, the
    // underground ventilation), the finishing (the gem cutter at 2d20 stones
    // per day with the weekly 1d100 exceptional-stone check worth 1d100 times
    // the week's average value), the duration (the secret d100 man-weeks, the
    // doubles ladder adding months then years until a non-doubles roll, the
    // 4-week month, the 48-week year, the man-week definition, the placer
    // 1-100 cap), and the claim (the 25-or-30/50 charter shares with the
    // ruler enforcement and the usually-death cheating penalty, the
    // wilderness war, denizens, claim-jumpers, the concealment set with the
    // 25% tailings rate, and the wealth-disposal risk).
    {
        using namespace rules;
        int bad = 0;
    if (dnrvPlacerDice() != 1
            || dnrvPlacerSides() != 4
            || dnrvPlacerPctMult() != 10
            || dnrvFinishDice() != 2
            || dnrvFinishSides() != 20
            || dnrvDurationDice() != 1
            || dnrvDurationSides() != 100
            || dnrvMonthWeeks() != 4
            || dnrvYearWeeks() != 48
            || dnrvCharterLowPct() != 25
            || dnrvCharterCommonPct() != 50
            || dnrvTailingsMiningPct() != 25
            || dnrvPlacerMinWeeks() != 1
            || dnrvPlacerMaxWeeks() != 100
            || dnrvExcepStoneDice() != 1
            || dnrvExcepStoneSides() != 100
            || !dnrvPlacerGoldSilverPlatinumOnly()
            || !dnrvPlacerUsesQualityThenPercent()
            || !dnrvOneSmelterSuffices()
            || !dnrvSmelterNeedsHotFire()
            || !dnrvMostMineralsNeedCoal()
            || !dnrvSmeltingImpossibleToConceal()
            || !dnrvUndergroundSmeltingVentilation()
            || !dnrvStonesRarelyNeedSmelting()
            || !dnrvGemCutterFinishes()
            || !dnrvExcavationExceedsFinishing()
            || !dnrvMineWealthFinite()
            || !dnrvDoublesAddMonths()
            || !dnrvDoublesAgainAddYears()
            || !dnrvManWeekPerMiner()
            || !dnrvPlacerDisregardsDoubles()
            || !dnrvHazardsInherent()
            || !dnrvClaimIsRightToWealth()
            || !dnrvTitleUsuallyARuler()
            || !dnrvCharterPossible()
            || !dnrvRulerEnforcesShare()
            || !dnrvCheatingUsuallyDeath()
            || !dnrvWildernessClaimFreeButHazardous()
            || !dnrvLandWarOvernight()
            || !dnrvSavageDenizensRaid()
            || !dnrvNoLegalProtection()
            || !dnrvClaimJumpersProportional()
            || !dnrvConcealmentRarelyWorks()
            || !dnrvConcealmentProblems()
            || !dnrvSmelterKillsConcealment()
            || !dnrvWealthDisposalRisky()
            || !dnrvExcepStoneWeeklyCheck()
            || !dnrvExcepStoneValueRoll()
        )
            ++bad;
        // the placer and finishing rolls: the 1d4-times-10 percent of full
        // value, and the 2d20 stones finished per day.
    if (dnrvPlacerDice() != 1
            || dnrvPlacerSides() != 4
            || dnrvPlacerPctMult() != 10
            || dnrvFinishDice() != 2
            || dnrvFinishSides() != 20
        )
            ++bad;
        // the duration rolls: the secret d100 in man-weeks, the 4-week month
        // and 48-week year conveniences, and the placer 1-100 man-week cap.
    if (dnrvDurationDice() != 1
            || dnrvDurationSides() != 100
            || dnrvMonthWeeks() != 4
            || dnrvYearWeeks() != 48
            || dnrvPlacerMinWeeks() != 1
            || dnrvPlacerMaxWeeks() != 100
        )
            ++bad;
        // the percentages and catch-up: the 25-or-30/50 charter shares, the
        // 25% tailings-scattering mining rate, and the weekly 1d100
        // exceptional-stone check.
    if (dnrvCharterLowPct() != 25
            || dnrvCharterCommonPct() != 50
            || dnrvTailingsMiningPct() != 25
            || dnrvExcepStoneDice() != 1
            || dnrvExcepStoneSides() != 100
        )
            ++bad;
        // the tail prose: the placer metal restrictions, the one-smelter
        // rule, the gem-cutter finishing, the doubles duration ladder with
        // the placer exception, and the cheating penalty.
    if (dnrvPlacerGoldSilverPlatinumOnly() != 1
            || dnrvOneSmelterSuffices() != 1
            || dnrvGemCutterFinishes() != 1
            || dnrvDoublesAddMonths() != 1
            || dnrvDoublesAgainAddYears() != 1
            || dnrvPlacerDisregardsDoubles() != 1
            || dnrvCheatingUsuallyDeath() != 1
        )
            ++bad;
        printf("R523 DSG mining tail audit: bad %d\n", bad);
        if (bad) return 1;
    }
