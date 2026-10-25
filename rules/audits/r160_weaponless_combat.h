    // ---- R160: weaponless combat audit --------------------
    // DMG pp.72-73: pummel, grapple, overbear - the three
    // tables, the base scores, the modifier lists, the
    // damage accounting, the initiative priority, the
    // hold ladder and the general notes.
    {
        int bad = 0;
        // the tier tables: boundary sweeps + damage bases
        static const int kPumScores[14] = {
            -5, 0, 1, 20, 21, 40, 41, 60, 61, 80, 81, 100,
            101, 250
        };
        static const int kPumIdx[14] = {
            0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6
        };
        static const int kPumDmg[7] = { 0, 0, 2, 4, 6, 8, 10 };
        for (int i = 0; i < 14; ++i) {
            int idx = rules::weaponlessTierIndex(
                rules::WL_PUMMEL, kPumScores[i]);
            if (idx != kPumIdx[i]) ++bad;
        }
        for (int i = 0; i < 7; ++i)
            if (rules::weaponlessTierDamage(
                    rules::WL_PUMMEL, i) != kPumDmg[i]) ++bad;
        static const int kGraScores[14] = {
            -5, 20, 21, 40, 41, 55, 56, 70, 71, 85, 86, 95,
            96, 300
        };
        static const int kGraIdx[14] = {
            0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6
        };
        static const int kGraDmg[7] = { 0, 1, 2, 3, 5, 6, 8 };
        for (int i = 0; i < 14; ++i) {
            int idx = rules::weaponlessTierIndex(
                rules::WL_GRAPPLE, kGraScores[i]);
            if (idx != kGraIdx[i]) ++bad;
        }
        for (int i = 0; i < 7; ++i)
            if (rules::weaponlessTierDamage(
                    rules::WL_GRAPPLE, i) != kGraDmg[i]) ++bad;
        static const int kOvbScores[12] = {
            -5, 20, 21, 40, 41, 60, 61, 80, 81, 100, 101, 400
        };
        static const int kOvbIdx[12] = {
            0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5
        };
        static const int kOvbDmg[6] = { 0, 0, 1, 2, 3, 4 };
        for (int i = 0; i < 12; ++i) {
            int idx = rules::weaponlessTierIndex(
                rules::WL_OVERBEAR, kOvbScores[i]);
            if (idx != kOvbIdx[i]) ++bad;
        }
        for (int i = 0; i < 6; ++i)
            if (rules::weaponlessTierDamage(
                    rules::WL_OVERBEAR, i) != kOvbDmg[i]) ++bad;
        // tier names non-empty
        for (int k = 0; k < 3; ++k) {
            int n = 0;
            const rules::WeaponlessTier* t =
                rules::weaponlessTiers(
                    (rules::WeaponlessKind)k, n);
            for (int i = 0; i < n; ++i)
                if (!t[i].name || !*t[i].name) ++bad;
        }
        // base scores
        if (rules::pummelBaseChance(10) != 100 ||
            rules::pummelBaseChance(9) != 90 ||
            rules::pummelBaseChance(0) != 0 ||
            rules::pummelBaseChance(-1) != -10 ||
            rules::pummelBaseChance(3) != 30) ++bad;
        if (rules::grappleBaseChance(5, 2) != 52 ||
            rules::grappleBaseChance(10, 0) != 100 ||
            rules::grappleBaseChance(0, 3) != 3) ++bad;
        // pummel base-chance modifiers
        if (rules::pummelHitAdj(15, 0, 0, false, false,
                               12, false) != 15 ||
            rules::pummelHitAdj(0, 1, 0, false, false,
                               12, false) != 1 ||
            rules::pummelHitAdj(0, 0, -2, false, false,
                               12, false) != 2 ||
            rules::pummelHitAdj(0, 0, 9, false, false,
                               12, false) != 9 ||
            rules::pummelHitAdj(0, 0, 0, true, false,
                               12, false) != 10 ||
            rules::pummelHitAdj(0, 0, 0, false, true,
                               12, false) != 20 ||
            rules::pummelHitAdj(0, 0, 0, true, true,
                               12, false) != 30 ||
            rules::pummelHitAdj(0, 0, 0, false, false,
                               15, false) != -5 ||
            rules::pummelHitAdj(0, 0, 0, false, false,
                               12, true) != -10 ||
            rules::pummelHitAdj(0, 0, 0, false, false,
                               15, true) != -15) ++bad;
        if (!rules::pummelAutomaticHit(true) ||
            rules::pummelAutomaticHit(false)) ++bad;
        // pummel strike modifiers
        if (rules::pummelStrikeAdj(3, 0, rules::WLP_FISTS,
                false, false, false, 0, false,
                rules::WLA_NONE, false,
                rules::WLH_NONE) != 3 ||
            rules::pummelStrikeAdj(0, 10, rules::WLP_FISTS,
                false, false, false, 0, false,
                rules::WLA_NONE, false,
                rules::WLH_NONE) != 2 ||
            rules::pummelStrikeAdj(0, 20, rules::WLP_FISTS,
                false, false, false, 0, false,
                rules::WLA_NONE, false,
                rules::WLH_NONE) != 4 ||
            rules::pummelStrikeAdj(0, 0,
                rules::WLP_WOODEN_MAILED,
                false, false, false, 0, false,
                rules::WLA_NONE, false,
                rules::WLH_NONE) != 5 ||
            rules::pummelStrikeAdj(0, 0,
                rules::WLP_METAL_POMMEL,
                false, false, false, 0, false,
                rules::WLA_NONE, false,
                rules::WLH_NONE) != 10 ||
            rules::pummelStrikeAdj(0, 0, rules::WLP_FISTS,
                false, true, true, 0, false,
                rules::WLA_NONE, false,
                rules::WLH_NONE) != 50 ||
            rules::pummelStrikeAdj(0, 0, rules::WLP_FISTS,
                false, false, false, 2, false,
                rules::WLA_NONE, false,
                rules::WLH_NONE) != -4 ||
            rules::pummelStrikeAdj(0, 0, rules::WLP_FISTS,
                false, false, false, 0, true,
                rules::WLA_NONE, false,
                rules::WLH_NONE) != -10 ||
            rules::pummelStrikeAdj(0, 0, rules::WLP_FISTS,
                false, false, false, 0, false,
                rules::WLA_LEATHER_PADDED, false,
                rules::WLH_NONE) != -10 ||
            rules::pummelStrikeAdj(0, 0, rules::WLP_FISTS,
                false, false, false, 0, false,
                rules::WLA_CHAIN_RING_SCALE, false,
                rules::WLH_NONE) != -20 ||
            rules::pummelStrikeAdj(0, 0, rules::WLP_FISTS,
                false, false, false, 0, false,
                rules::WLA_NONE, true,
                rules::WLH_NONE) != -30 ||
            rules::pummelStrikeAdj(0, 0, rules::WLP_FISTS,
                false, false, false, 0, false,
                rules::WLA_BANDED_PLATE_SPLINT, true,
                rules::WLH_NONE) != -70 ||
            rules::pummelStrikeAdj(0, 0, rules::WLP_FISTS,
                false, false, false, 0, false,
                rules::WLA_NONE, false,
                rules::WLH_OPEN) != -5 ||
            rules::pummelStrikeAdj(0, 0, rules::WLP_FISTS,
                false, false, false, 0, false,
                rules::WLA_NONE, false,
                rules::WLH_NASALED) != -10 ||
            rules::pummelStrikeAdj(0, 0, rules::WLP_FISTS,
                false, false, false, 0, false,
                rules::WLA_NONE, false,
                rules::WLH_VISORED) != -20) ++bad;
        // grapple base modifiers
        if (rules::grappleBaseAdj(14, rules::WLA_NONE,
                false, 0, false) != 14 ||
            rules::grappleBaseAdj(0,
                rules::WLA_LEATHER_PADDED, false, 0,
                false) != 10 ||
            rules::grappleBaseAdj(0,
                rules::WLA_CHAIN_RING_SCALE, false, 0,
                false) != 20 ||
            rules::grappleBaseAdj(0,
                rules::WLA_BANDED_PLATE_SPLINT, false, 0,
                false) != 30 ||
            rules::grappleBaseAdj(0, rules::WLA_NONE,
                true, 0, false) != 20 ||
            rules::grappleBaseAdj(0, rules::WLA_NONE,
                false, 2, false) != -20 ||
            rules::grappleBaseAdj(0, rules::WLA_NONE,
                false, 0, true) != -20) ++bad;
        // grapple hold modifiers
        if (rules::grappleHoldAdj(5, 5, 0, false, false,
                false, 0, 0, 0, 0, 0, false, false,
                false) != 10 ||
            rules::grappleHoldAdj(0, 0, 10, false, false,
                false, 0, 0, 0, 0, 0, false, false,
                false) != 1 ||
            rules::grappleHoldAdj(0, 0, 0, true, true,
                true, 0, 0, 0, 0, 0, false, false,
                false) != 60 ||
            rules::grappleHoldAdj(0, 0, 0, false, false,
                false, 20, 0, 0, 0, 0, false, false,
                false) != 10 ||
            rules::grappleHoldAdj(0, 0, 0, false, false,
                false, -10, 0, 0, 0, 0, false, false,
                false) != -5 ||
            rules::grappleHoldAdj(0, 0, 0, false, false,
                false, 0, 20, 0, 0, 0, false, false,
                false) != 10 ||
            rules::grappleHoldAdj(0, 0, 0, false, false,
                false, 0, 0, 3, 0, 0, false, false,
                false) != -6 ||
            rules::grappleHoldAdj(0, 0, 0, false, false,
                false, 0, 0, 0, 2, 0, false, false,
                false) != -2 ||
            rules::grappleHoldAdj(0, 0, 0, false, false,
                false, 0, 0, 0, 0, 10, false, false,
                false) != -1 ||
            rules::grappleHoldAdj(0, 0, 0, false, false,
                false, 0, 0, 0, 0, 0, true, true,
                true) != -30) ++bad;
        // overbear modifiers
        if (rules::overbearAdj(3, 0, false, false, false,
                0, 0, 0, 0, 0, false) != 3 ||
            rules::overbearAdj(0, 10, false, false, false,
                0, 0, 0, 0, 0, false) != 2 ||
            rules::overbearAdj(0, 0, true, false, false,
                0, 0, 0, 0, 0, false) != 10 ||
            rules::overbearAdj(0, 0, false, true, false,
                0, 0, 0, 0, 0, false) != 15 ||
            rules::overbearAdj(0, 0, false, false, true,
                0, 0, 0, 0, 0, false) != 20 ||
            rules::overbearAdj(0, 0, false, false, false,
                10, 0, 0, 0, 0, false) != 10 ||
            rules::overbearAdj(0, 0, false, false, false,
                0, 20, 0, 0, 0, false) != 10 ||
            rules::overbearAdj(0, 0, false, false, false,
                0, 0, 2, 0, 0, false) != -2 ||
            rules::overbearAdj(0, 0, false, false, false,
                0, 0, 0, 10, 0, false) != -2 ||
            rules::overbearAdj(0, 0, false, false, false,
                0, 0, 0, 0, 1, false) != -2 ||
            rules::overbearAdj(0, 0, false, false, false,
                0, 0, 0, 0, 0, true) != -10) ++bad;
        // the damage accounting
        if (rules::weaponlessActualPct(rules::WL_PUMMEL) != 25
            || rules::weaponlessActualPct(
                   rules::WL_GRAPPLE) != 25
            || rules::weaponlessActualPct(
                   rules::WL_OVERBEAR) != 50) ++bad;
        if (rules::weaponlessHealPerRound() != 1) ++bad;
        if (rules::weaponlessUnconsciousRounds(0) != 1 ||
            rules::weaponlessUnconsciousRounds(4) != 5 ||
            rules::weaponlessUnconsciousRounds(7) != 8 ||
            rules::weaponlessUnconsciousRounds(-3) != 1)
            ++bad;
        if (rules::weaponlessTrussRounds() != 1) ++bad;
        if (rules::weaponlessPummelAttacksPerRound() != 2)
            ++bad;
        if (!rules::grappleAttackAndCounterPerRound() ||
            !rules::grappleHoldActsFirst()) ++bad;
        if (rules::grappleHandsFree(true) ||
            !rules::grappleHandsFree(false)) ++bad;
        if (!rules::overbearAllowsOccupiedHands() ||
            !rules::overbearRequiresFollowUp()) ++bad;
        // the shared variable: bounds sweeps
        {
            rules::Rng rngW(20261007);
            rules::Dice diceW(rngW);
            for (int t = 0; t < 500; ++t) {
                int av = rules::weaponlessVariable(
                    diceW, 1, true);
                int dv = rules::weaponlessVariable(
                    diceW, 2, false);
                if (av < 2 || av > 7) ++bad;
                if (dv < 3 || dv > 6) ++bad;
            }
        }
        if (rules::weaponlessUnconsciousGetsVariable())
            ++bad;
        // initiative priority: surprise, charge, dex, roll
        if (rules::weaponlessInitiativeFirst(
                true, false, false, true, 10, 18, 1, 6) != -1 ||
            rules::weaponlessInitiativeFirst(
                false, true, true, false, 18, 10, 6, 1) != 1 ||
            rules::weaponlessInitiativeFirst(
                false, false, true, false, 10, 18, 1, 6) != -1 ||
            rules::weaponlessInitiativeFirst(
                false, false, false, false, 16, 12, 1, 6) != -1 ||
            rules::weaponlessInitiativeFirst(
                false, false, false, false, 12, 16, 1, 6) != 1 ||
            rules::weaponlessInitiativeFirst(
                false, false, false, false, 12, 12, 5, 3) != -1 ||
            rules::weaponlessInitiativeFirst(
                false, false, false, false, 12, 12, 3, 5) != 1 ||
            rules::weaponlessInitiativeFirst(
                false, false, false, false, 12, 12, 4, 4) != 0)
            ++bad;
        // the hold ladder + the stunned counter rule
        if (!rules::grappleHoldBreaks(1, 0) ||
            rules::grappleHoldBreaks(0, 1) ||
            rules::grappleHoldBreaks(2, 2) ||
            !rules::grappleStunnedAllowsImmediateSecond())
            ++bad;
        // the general notes
        if (!rules::weaponlessWeaponWielderFirst(false) ||
            rules::weaponlessWeaponWielderFirst(true))
            ++bad;
        if (!rules::weaponlessBehindNegatesShieldAndDex())
            ++bad;
        if (!rules::bearLikeHuggerGrappples() ||
            !rules::weaponlessMonsterOverbears()) ++bad;
        if (!rules::monkOpenHandUnimpeded()) ++bad;
        printf("R160 weaponless combat audit: bad %d\n", bad);
        if (bad) return 1;
    }
