    // ---- R576 Astral Plane audit ----
    // the Astral Plane, printed pp. 60-72, the whole chapter in one round:
    // the barren-vault doctrine (the transit plane between Primes and outers,
    // the wormholes, Anubis the sole resident Power), the reaching split (the
    // astral-spell projection with the silver cords vs. the plane-shift
    // physical travel), the cord rules (the 1d10-turn dissolution clock, the
    // 1d4+1-day coma with the system-shock and half-hp restrictions, the 1%
    // possession, the three severing forces), the color pools (the 10-60 foot
    // disks, the blind side, the d20 color table, the 1d4x100-yard viewing
    // altitude, the percentile location roll, the 10-times-Intelligence
    // viewpoint, the 15% two-way and 5% fixed portals), the survival (no
    // breath, no food, the 365,000-to-1 time, the potion permanence, the dead
    // infravision), the movement (the 10-yards-per-minute-per-Int mental
    // move, the push-off fallback, the encumbrance), the
    // 1d10-every-four-hours encounter check with the 1-75/76-85/86-95/96-00
    // type split, the psychic wind (the 1d20 group roll with the wake, the
    // 2d10-day stranding, the cross-current, the cord-snapping storm), the
    // combat (the AC 8 astral base, the Intelligence and Wisdom modifier
    // swap, the above/below rules, the doubled missile ranges, the suspended
    // healing, the liquid films and suspended poison), the magic (the
    // conjuration caps at 4th/3rd/5th, the sphere areas, the extradimensional
    // void, the Bigby-hand Intelligence contests, the illusion and necromancy
    // rules, the searcher chance at 5 times level), the PC adjustments (the
    // thief noise split, the ranger tracking, the monk AC 7), and the
    // features (the githyanki silver swords at AC 0 and 20%, the lich-queen,
    // the astral searchers, the fixed portals, Yggdrasil and Mount Olympus).
    {
        using namespace rules;
        int bad = 0;
    if (ddeTimeRatio() != 365000
            || ddeCordDissolveTurns() != 10
            || ddeAstralComaDays() != 5
            || ddePossessionPct() != 1
            || ddeMentalMoveBase() != 10
            || ddeEncounterCheckHours() != 4
            || ddeConduitBothEndsPct() != 80
            || ddeConduitPullYards() != 120
            || ddeWindDelayHours() != 6
            || ddePoolTwoWayPct() != 15
            || ddeSearcherLevelMult() != 5
            || ddeTrueSightStunBase() != 100
            || ddeClericConjLevelCap() != 4
            || ddeDruidConjLevelCap() != 3
            || ddeMuConjLevelCap() != 5
            || !ddeSilverCordRule()
            || !ddeColorPoolDoctrine()
            || !ddePoolAttackRule()
            || !ddeSurvivalDoctrine()
            || !ddeWeightlessCombat()
            || !ddeLiquidAndPoisonRule()
            || !ddeExtradimensionalVoid()
            || !ddeIllusionNecromancyRule()
            || !ddeBigbyHandRule()
            || !ddeThiefAdjustments()
            || !ddeGithyankiSilverSwords()
            || !ddeYggdrasilOlympus()
        )
            ++bad;
        // the TimeRatio pin
    if (ddeTimeRatio() != 365000
        )
            ++bad;
        // the CordDissolveTurns pin
    if (ddeCordDissolveTurns() != 10
        )
            ++bad;
        // the AstralComaDays pin
    if (ddeAstralComaDays() != 5
        )
            ++bad;
        // the PossessionPct pin
    if (ddePossessionPct() != 1
        )
            ++bad;
        // the MentalMoveBase pin
    if (ddeMentalMoveBase() != 10
        )
            ++bad;
        // the EncounterCheckHours pin
    if (ddeEncounterCheckHours() != 4
        )
            ++bad;
        // the ConduitBothEndsPct pin
    if (ddeConduitBothEndsPct() != 80
        )
            ++bad;
        // the ConduitPullYards pin
    if (ddeConduitPullYards() != 120
        )
            ++bad;
        // the WindDelayHours pin
    if (ddeWindDelayHours() != 6
        )
            ++bad;
        // the PoolTwoWayPct pin
    if (ddePoolTwoWayPct() != 15
        )
            ++bad;
        // the SearcherLevelMult pin
    if (ddeSearcherLevelMult() != 5
        )
            ++bad;
        // the TrueSightStunBase pin
    if (ddeTrueSightStunBase() != 100
        )
            ++bad;
        // the ClericConjLevelCap pin
    if (ddeClericConjLevelCap() != 4
        )
            ++bad;
        // the DruidConjLevelCap pin
    if (ddeDruidConjLevelCap() != 3
        )
            ++bad;
        // the MuConjLevelCap pin
    if (ddeMuConjLevelCap() != 5
        )
            ++bad;
        // the SilverCordRule pin
    if (ddeSilverCordRule() != 1
        )
            ++bad;
        // the ColorPoolDoctrine pin
    if (ddeColorPoolDoctrine() != 1
        )
            ++bad;
        // the PoolAttackRule pin
    if (ddePoolAttackRule() != 1
        )
            ++bad;
        // the SurvivalDoctrine pin
    if (ddeSurvivalDoctrine() != 1
        )
            ++bad;
        // the WeightlessCombat pin
    if (ddeWeightlessCombat() != 1
        )
            ++bad;
        // the LiquidAndPoisonRule pin
    if (ddeLiquidAndPoisonRule() != 1
        )
            ++bad;
        // the ExtradimensionalVoid pin
    if (ddeExtradimensionalVoid() != 1
        )
            ++bad;
        // the IllusionNecromancyRule pin
    if (ddeIllusionNecromancyRule() != 1
        )
            ++bad;
        // the BigbyHandRule pin
    if (ddeBigbyHandRule() != 1
        )
            ++bad;
        // the ThiefAdjustments pin
    if (ddeThiefAdjustments() != 1
        )
            ++bad;
        // the GithyankiSilverSwords pin
    if (ddeGithyankiSilverSwords() != 1
        )
            ++bad;
        // the YggdrasilOlympus pin
    if (ddeYggdrasilOlympus() != 1
        )
            ++bad;
        printf("R576 Astral Plane audit: bad %d\n", bad);
        if (bad) return 1;
    }
