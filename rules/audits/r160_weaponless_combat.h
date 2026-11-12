    // ---- R160: weaponless combat audit --------------------
    // DMG pp.72-73: pummel, grapple, overbear - the three
    // tables, the base scores, the modifier lists, the
    // damage accounting, the initiative priority, the
    // hold ladder and the general notes.
    {
        Weaponless weaponless;
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
            Weaponless weaponless;
            int idx = weaponless.weaponlessTierIndex(
                WL_PUMMEL, kPumScores[i]);
            if (idx != kPumIdx[i]) ++bad;
        }
        for (int i = 0; i < 7; ++i)
            if (weaponless.weaponlessTierDamage(
                    WL_PUMMEL, i) != kPumDmg[i]) ++bad;
        static const int kGraScores[14] = {
            -5, 20, 21, 40, 41, 55, 56, 70, 71, 85, 86, 95,
            96, 300
        };
        static const int kGraIdx[14] = {
            0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6
        };
        static const int kGraDmg[7] = { 0, 1, 2, 3, 5, 6, 8 };
        for (int i = 0; i < 14; ++i) {
            Weaponless weaponless;
            int idx = weaponless.weaponlessTierIndex(
                WL_GRAPPLE, kGraScores[i]);
            if (idx != kGraIdx[i]) ++bad;
        }
        for (int i = 0; i < 7; ++i)
            if (weaponless.weaponlessTierDamage(
                    WL_GRAPPLE, i) != kGraDmg[i]) ++bad;
        static const int kOvbScores[12] = {
            -5, 20, 21, 40, 41, 60, 61, 80, 81, 100, 101, 400
        };
        static const int kOvbIdx[12] = {
            0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5
        };
        static const int kOvbDmg[6] = { 0, 0, 1, 2, 3, 4 };
        for (int i = 0; i < 12; ++i) {
            Weaponless weaponless;
            int idx = weaponless.weaponlessTierIndex(
                WL_OVERBEAR, kOvbScores[i]);
            if (idx != kOvbIdx[i]) ++bad;
        }
        for (int i = 0; i < 6; ++i)
            if (weaponless.weaponlessTierDamage(
                    WL_OVERBEAR, i) != kOvbDmg[i]) ++bad;
        // tier names non-empty
        for (int k = 0; k < 3; ++k) {
            Weaponless weaponless;
            int n = 0;
            const WeaponlessTier* t =
                weaponless.weaponlessTiers(
                    (WeaponlessKind)k, n);
            for (int i = 0; i < n; ++i)
                if (!t[i].name || !*t[i].name) ++bad;
        }
        // base scores
        if (weaponless.pummelBaseChance(10) != 100 ||
            weaponless.pummelBaseChance(9) != 90 ||
            weaponless.pummelBaseChance(0) != 0 ||
            weaponless.pummelBaseChance(-1) != -10 ||
            weaponless.pummelBaseChance(3) != 30) ++bad;
        if (weaponless.grappleBaseChance(5, 2) != 52 ||
            weaponless.grappleBaseChance(10, 0) != 100 ||
            weaponless.grappleBaseChance(0, 3) != 3) ++bad;
        // pummel base-chance modifiers
        if (weaponless.pummelHitAdj(15, 0, 0, false, false,
                               12, false) != 15 ||
            weaponless.pummelHitAdj(0, 1, 0, false, false,
                               12, false) != 1 ||
            weaponless.pummelHitAdj(0, 0, -2, false, false,
                               12, false) != 2 ||
            weaponless.pummelHitAdj(0, 0, 9, false, false,
                               12, false) != 9 ||
            weaponless.pummelHitAdj(0, 0, 0, true, false,
                               12, false) != 10 ||
            weaponless.pummelHitAdj(0, 0, 0, false, true,
                               12, false) != 20 ||
            weaponless.pummelHitAdj(0, 0, 0, true, true,
                               12, false) != 30 ||
            weaponless.pummelHitAdj(0, 0, 0, false, false,
                               15, false) != -5 ||
            weaponless.pummelHitAdj(0, 0, 0, false, false,
                               12, true) != -10 ||
            weaponless.pummelHitAdj(0, 0, 0, false, false,
                               15, true) != -15) ++bad;
        if (!weaponless.pummelAutomaticHit(true) ||
            weaponless.pummelAutomaticHit(false)) ++bad;
        // pummel strike modifiers
        if (weaponless.pummelStrikeAdj(3, 0, WLP_FISTS,
                false, false, false, 0, false,
                WLA_NONE, false,
                WLH_NONE) != 3 ||
            weaponless.pummelStrikeAdj(0, 10, WLP_FISTS,
                false, false, false, 0, false,
                WLA_NONE, false,
                WLH_NONE) != 2 ||
            weaponless.pummelStrikeAdj(0, 20, WLP_FISTS,
                false, false, false, 0, false,
                WLA_NONE, false,
                WLH_NONE) != 4 ||
            weaponless.pummelStrikeAdj(0, 0,
                WLP_WOODEN_MAILED,
                false, false, false, 0, false,
                WLA_NONE, false,
                WLH_NONE) != 5 ||
            weaponless.pummelStrikeAdj(0, 0,
                WLP_METAL_POMMEL,
                false, false, false, 0, false,
                WLA_NONE, false,
                WLH_NONE) != 10 ||
            weaponless.pummelStrikeAdj(0, 0, WLP_FISTS,
                false, true, true, 0, false,
                WLA_NONE, false,
                WLH_NONE) != 50 ||
            weaponless.pummelStrikeAdj(0, 0, WLP_FISTS,
                false, false, false, 2, false,
                WLA_NONE, false,
                WLH_NONE) != -4 ||
            weaponless.pummelStrikeAdj(0, 0, WLP_FISTS,
                false, false, false, 0, true,
                WLA_NONE, false,
                WLH_NONE) != -10 ||
            weaponless.pummelStrikeAdj(0, 0, WLP_FISTS,
                false, false, false, 0, false,
                WLA_LEATHER_PADDED, false,
                WLH_NONE) != -10 ||
            weaponless.pummelStrikeAdj(0, 0, WLP_FISTS,
                false, false, false, 0, false,
                WLA_CHAIN_RING_SCALE, false,
                WLH_NONE) != -20 ||
            weaponless.pummelStrikeAdj(0, 0, WLP_FISTS,
                false, false, false, 0, false,
                WLA_NONE, true,
                WLH_NONE) != -30 ||
            weaponless.pummelStrikeAdj(0, 0, WLP_FISTS,
                false, false, false, 0, false,
                WLA_BANDED_PLATE_SPLINT, true,
                WLH_NONE) != -70 ||
            weaponless.pummelStrikeAdj(0, 0, WLP_FISTS,
                false, false, false, 0, false,
                WLA_NONE, false,
                WLH_OPEN) != -5 ||
            weaponless.pummelStrikeAdj(0, 0, WLP_FISTS,
                false, false, false, 0, false,
                WLA_NONE, false,
                WLH_NASALED) != -10 ||
            weaponless.pummelStrikeAdj(0, 0, WLP_FISTS,
                false, false, false, 0, false,
                WLA_NONE, false,
                WLH_VISORED) != -20) ++bad;
        // grapple base modifiers
        if (weaponless.grappleBaseAdj(14, WLA_NONE,
                false, 0, false) != 14 ||
            weaponless.grappleBaseAdj(0,
                WLA_LEATHER_PADDED, false, 0,
                false) != 10 ||
            weaponless.grappleBaseAdj(0,
                WLA_CHAIN_RING_SCALE, false, 0,
                false) != 20 ||
            weaponless.grappleBaseAdj(0,
                WLA_BANDED_PLATE_SPLINT, false, 0,
                false) != 30 ||
            weaponless.grappleBaseAdj(0, WLA_NONE,
                true, 0, false) != 20 ||
            weaponless.grappleBaseAdj(0, WLA_NONE,
                false, 2, false) != -20 ||
            weaponless.grappleBaseAdj(0, WLA_NONE,
                false, 0, true) != -20) ++bad;
        // grapple hold modifiers
        if (weaponless.grappleHoldAdj(5, 5, 0, false, false,
                false, 0, 0, 0, 0, 0, false, false,
                false) != 10 ||
            weaponless.grappleHoldAdj(0, 0, 10, false, false,
                false, 0, 0, 0, 0, 0, false, false,
                false) != 1 ||
            weaponless.grappleHoldAdj(0, 0, 0, true, true,
                true, 0, 0, 0, 0, 0, false, false,
                false) != 60 ||
            weaponless.grappleHoldAdj(0, 0, 0, false, false,
                false, 20, 0, 0, 0, 0, false, false,
                false) != 10 ||
            weaponless.grappleHoldAdj(0, 0, 0, false, false,
                false, -10, 0, 0, 0, 0, false, false,
                false) != -5 ||
            weaponless.grappleHoldAdj(0, 0, 0, false, false,
                false, 0, 20, 0, 0, 0, false, false,
                false) != 10 ||
            weaponless.grappleHoldAdj(0, 0, 0, false, false,
                false, 0, 0, 3, 0, 0, false, false,
                false) != -6 ||
            weaponless.grappleHoldAdj(0, 0, 0, false, false,
                false, 0, 0, 0, 2, 0, false, false,
                false) != -2 ||
            weaponless.grappleHoldAdj(0, 0, 0, false, false,
                false, 0, 0, 0, 0, 10, false, false,
                false) != -1 ||
            weaponless.grappleHoldAdj(0, 0, 0, false, false,
                false, 0, 0, 0, 0, 0, true, true,
                true) != -30) ++bad;
        // overbear modifiers
        if (weaponless.overbearAdj(3, 0, false, false, false,
                0, 0, 0, 0, 0, false) != 3 ||
            weaponless.overbearAdj(0, 10, false, false, false,
                0, 0, 0, 0, 0, false) != 2 ||
            weaponless.overbearAdj(0, 0, true, false, false,
                0, 0, 0, 0, 0, false) != 10 ||
            weaponless.overbearAdj(0, 0, false, true, false,
                0, 0, 0, 0, 0, false) != 15 ||
            weaponless.overbearAdj(0, 0, false, false, true,
                0, 0, 0, 0, 0, false) != 20 ||
            weaponless.overbearAdj(0, 0, false, false, false,
                10, 0, 0, 0, 0, false) != 10 ||
            weaponless.overbearAdj(0, 0, false, false, false,
                0, 20, 0, 0, 0, false) != 10 ||
            weaponless.overbearAdj(0, 0, false, false, false,
                0, 0, 2, 0, 0, false) != -2 ||
            weaponless.overbearAdj(0, 0, false, false, false,
                0, 0, 0, 10, 0, false) != -2 ||
            weaponless.overbearAdj(0, 0, false, false, false,
                0, 0, 0, 0, 1, false) != -2 ||
            weaponless.overbearAdj(0, 0, false, false, false,
                0, 0, 0, 0, 0, true) != -10) ++bad;
        // the damage accounting
        if (weaponless.weaponlessActualPct(WL_PUMMEL) != 25
            || weaponless.weaponlessActualPct(
                   WL_GRAPPLE) != 25
            || weaponless.weaponlessActualPct(
                   WL_OVERBEAR) != 50) ++bad;
        if (weaponless.weaponlessHealPerRound() != 1) ++bad;
        if (weaponless.weaponlessUnconsciousRounds(0) != 1 ||
            weaponless.weaponlessUnconsciousRounds(4) != 5 ||
            weaponless.weaponlessUnconsciousRounds(7) != 8 ||
            weaponless.weaponlessUnconsciousRounds(-3) != 1)
            ++bad;
        if (weaponless.weaponlessTrussRounds() != 1) ++bad;
        if (weaponless.weaponlessPummelAttacksPerRound() != 2)
            ++bad;
        if (!weaponless.grappleAttackAndCounterPerRound() ||
            !weaponless.grappleHoldActsFirst()) ++bad;
        if (weaponless.grappleHandsFree(true) ||
            !weaponless.grappleHandsFree(false)) ++bad;
        if (!weaponless.overbearAllowsOccupiedHands() ||
            !weaponless.overbearRequiresFollowUp()) ++bad;
        // the shared variable: bounds sweeps
        {
            rules::Rng rngW(20261007);
            rules::Dice diceW(rngW);
            for (int t = 0; t < 500; ++t) {
                Weaponless weaponless;
                int av = weaponless.weaponlessVariable(
                    diceW, 1, true);
                int dv = weaponless.weaponlessVariable(
                    diceW, 2, false);
                if (av < 2 || av > 7) ++bad;
                if (dv < 3 || dv > 6) ++bad;
            }
        }
        if (weaponless.weaponlessUnconsciousGetsVariable())
            ++bad;
        // initiative priority: surprise, charge, dex, roll
        if (weaponless.weaponlessInitiativeFirst(
                true, false, false, true, 10, 18, 1, 6) != -1 ||
            weaponless.weaponlessInitiativeFirst(
                false, true, true, false, 18, 10, 6, 1) != 1 ||
            weaponless.weaponlessInitiativeFirst(
                false, false, true, false, 10, 18, 1, 6) != -1 ||
            weaponless.weaponlessInitiativeFirst(
                false, false, false, false, 16, 12, 1, 6) != -1 ||
            weaponless.weaponlessInitiativeFirst(
                false, false, false, false, 12, 16, 1, 6) != 1 ||
            weaponless.weaponlessInitiativeFirst(
                false, false, false, false, 12, 12, 5, 3) != -1 ||
            weaponless.weaponlessInitiativeFirst(
                false, false, false, false, 12, 12, 3, 5) != 1 ||
            weaponless.weaponlessInitiativeFirst(
                false, false, false, false, 12, 12, 4, 4) != 0)
            ++bad;
        // the hold ladder + the stunned counter rule
        if (!weaponless.grappleHoldBreaks(1, 0) ||
            weaponless.grappleHoldBreaks(0, 1) ||
            weaponless.grappleHoldBreaks(2, 2) ||
            !weaponless.grappleStunnedAllowsImmediateSecond())
            ++bad;
        // the general notes
        if (!weaponless.weaponlessWeaponWielderFirst(false) ||
            weaponless.weaponlessWeaponWielderFirst(true))
            ++bad;
        if (!weaponless.weaponlessBehindNegatesShieldAndDex())
            ++bad;
        if (!weaponless.bearLikeHuggerGrappples() ||
            !weaponless.weaponlessMonsterOverbears()) ++bad;
        if (!weaponless.monkOpenHandUnimpeded()) ++bad;
        printf("R160 weaponless combat audit: bad %d\n", bad);
        if (bad) return 1;
    }
