    // ---- R181: the attacks per melee round audit ----
    // The fighter-group bands, the under-one-hit-die
    // note, every monk ladder cell, the monk weapon
    // damage ladder, and the turn.cpp repin.
    {
        int bad = 0;
        // the fighter-group bands: level probes around every
        // printed edge (fighter/paladin 6,7,12,13; ranger
        // 7,8,14,15)
        const int kMid[3]  = { 7, 7, 8 };
        const int kHigh[3] = { 13, 13, 15 };
        for (int k = 0; k < 3; ++k) {
            for (int lv = 1; lv <= 20; ++lv) {
                rules::AtkRate r =
                    rules::fighterGroupAttacks(k, lv);
                int att = 1, rds = 1;
                if (lv >= kHigh[k]) { att = 2; rds = 1; }
                else if (lv >= kMid[k]) { att = 3; rds = 2; }
                if (r.attacks != att || r.rounds != rds) ++bad;
            }
        }
        // the under-one-hit-die note: one attack per
        // fighter experience level
        if (rules::fighterAttacksVsSubOneHitDice(1) != 1) ++bad;
        if (rules::fighterAttacksVsSubOneHitDice(7) != 7) ++bad;
        if (rules::fighterAttacksVsSubOneHitDice(13) != 13) ++bad;
        if (rules::fighterAttacksVsSubOneHitDice(0) != 1) ++bad;
        // every monk ladder cell (Monks Table II)
        const int kMnkAc[17] = {
            10, 9, 8, 7, 7, 6, 5, 4, 3, 3, 2, 1, 0,
            -1, -1, -2, -3
        };
        const int kMnkMove[17] = {
            15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
            26, 27, 28, 29, 30, 32
        };
        const int kMnkAtt[17] = {
            1, 1, 1, 5, 5, 3, 3, 3, 2, 2, 5, 5, 5,
            3, 3, 4, 4
        };
        const int kMnkRds[17] = {
            1, 1, 1, 4, 4, 2, 2, 2, 1, 1, 2, 2, 2,
            1, 1, 1, 1
        };
        const int kMnkLo[17] = {
            1, 1, 1, 1, 2, 2, 3, 2, 3, 3, 4, 4, 5,
            5, 6, 5, 8
        };
        const int kMnkHi[17] = {
            3, 4, 6, 6, 7, 8, 9, 12, 12, 13, 13, 16,
            17, 20, 24, 30, 32
        };
        if (rules::monkLadderRowCount() != 17) ++bad;
        for (int lv = 1; lv <= 17; ++lv) {
            const rules::MonkLadderRow& r =
                rules::monkLadderRow(lv);
            if (r.level != lv) ++bad;
            if (r.acClass != kMnkAc[lv-1]) ++bad;
            if (r.moveInches != kMnkMove[lv-1]) ++bad;
            if (r.atkAttacks != kMnkAtt[lv-1]) ++bad;
            if (r.atkRounds != kMnkRds[lv-1]) ++bad;
            if (r.dmgLo != kMnkLo[lv-1]) ++bad;
            if (r.dmgHi != kMnkHi[lv-1]) ++bad;
        }
        // clamps: level 0 and 99 read level 1 and 17
        if (rules::monkLadderRow(0).level != 1) ++bad;
        if (rules::monkLadderRow(99).level != 17) ++bad;
        if (rules::monkOpenHandAttacks(4).attacks != 5
            || rules::monkOpenHandAttacks(4).rounds != 4) ++bad;
        // the monk weapon damage ladder (doubled form:
        // +1/2 per level, Grand Master +8 1/2)
        if (rules::monkWeaponDamageBonus2x(1) != 1) ++bad;
        if (rules::monkWeaponDamageBonus2x(2) != 2) ++bad;
        if (rules::monkWeaponDamageBonus2x(17) != 17) ++bad;
        if (rules::monkWeaponDamageBonus2x(99) != 17) ++bad;
        // the turn.cpp repin: the base-class function uses the
        // fighter bands (the heavy round of the printed cycle)
        if (rules::meleeAttacksPerRound(0, 6) != 1) ++bad;
        if (rules::meleeAttacksPerRound(0, 7) != 2) ++bad;
        if (rules::meleeAttacksPerRound(0, 12) != 2) ++bad;
        if (rules::meleeAttacksPerRound(0, 13) != 2) ++bad;
        if (rules::meleeAttacksPerRound(0, 20) != 2) ++bad;
        if (rules::meleeAttacksPerRound(1, 20) != 1) ++bad;
        if (rules::meleeAttacksPerRound(2, 20) != 1) ++bad;
        if (rules::meleeAttacksPerRound(3, 20) != 1) ++bad;
        printf("R181 attacks per melee round audit: bad %d\n", bad);
        if (bad) return 1;
    }
