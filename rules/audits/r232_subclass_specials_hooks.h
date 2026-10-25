    // ---- R232: the subclass specials hooks audit ----
    // The specials the engine reads: the toActor subclass
    // propagation and the monk attack rate, the monk
    // open-hand ladder cells and attack slashes, the
    // backstab ladder and hit bonus, the ranger
    // giant-class roster and bonus, and the lay-hands
    // career-day field contract (an engine audit - the
    // R174 convention; the C++ battery is the gate).
    {
        int bad = 0;
        // the toActor propagation + the monk attack rate
        {
            Character c;
            c.subclass = rules::SUB_MONK;
            c.level = 12;
            ai::Actor a = c.toActor();
            if (a.subclass != rules::SUB_MONK) ++bad;
            if (a.attacksPerRound() != 2) ++bad;   // 12th: 5/2
            c.level = 1;
            a = c.toActor();
            if (a.attacksPerRound() != 1) ++bad;   // 1st: 1/1
            c.subclass = -1;
            a = c.toActor();
            if (a.subclass != -1) ++bad;
            if (a.attacksPerRound() != 1) ++bad;   // fighter L1
        }
        // the monk open-hand ladder cells (Monks Table II)
        if (rules::monkLadderRow(1).dmgLo != 1 ||
            rules::monkLadderRow(1).dmgHi != 3) ++bad;
        if (rules::monkLadderRow(13).dmgLo != 5 ||
            rules::monkLadderRow(13).dmgHi != 17) ++bad;
        if (rules::monkLadderRow(17).dmgLo != 8 ||
            rules::monkLadderRow(17).dmgHi != 32) ++bad;
        // the monk attack slashes (the printed cycle)
        if (rules::monkOpenHandAttacks(4).attacks != 5 ||
            rules::monkOpenHandAttacks(4).rounds != 4) ++bad;
        if (rules::monkOpenHandAttacks(12).attacks != 5 ||
            rules::monkOpenHandAttacks(12).rounds != 2) ++bad;
        // the backstab ladder (double 1-4 ... quintuple
        // 13-16, clamped at quintuple)
        static const int kMult[16] = {
            2, 2, 2, 2, 3, 3, 3, 3,
            4, 4, 4, 4, 5, 5, 5, 5
        };
        for (int l = 1; l <= 16; ++l)
            if (rules::backstabMultiplier(l)
                != kMult[l - 1]) ++bad;
        if (rules::backstabMultiplier(17) != 5) ++bad;
        if (rules::backstabHitBonusDie() != 4) ++bad;
        if (rules::backstabHitBonusPercent() != 20) ++bad;
        // the assassin reads full level backstabbing
        if (rules::assassinBackstabLevel(7) != 7) ++bad;
        if (rules::assassinThiefSkillLevel(7) != 5) ++bad;
        // the ranger giant-class roster (the R184 data
        // the hook reads)
        if (rules::rangerGiantClassCount() != 11) ++bad;
        if (!rules::rangerIsGiantClass("ogre mage")) ++bad;
        if (!rules::rangerIsGiantClass("ogre")) ++bad;
        if (rules::rangerIsGiantClass("purple worm")) ++bad;
        if (rules::rangerIsGiantClass("ogre ish")) ++bad;
        if (rules::rangerGiantClassBonus(7) != 7) ++bad;
        if (rules::rangerGiantClassBonus(0) != 0) ++bad;
        // the lay-hands field contract: -1 = never used
        {
            Character c;
            if (c.layHandsDay != -1) ++bad;
            c.layHandsDay = 100;
            if (c.layHandsDay == -1) ++bad;
        }
        printf("R232 subclass specials hooks audit: bad %d\n", bad);
        if (bad) return 1;
    }
