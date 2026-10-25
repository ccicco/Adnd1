    // ---- R235a: the bard career seam audit ----
    // The career windows, the Table I ladders and
    // the gates (an evaluable block - verified by
    // audit_eval).
    {
        int bad = 0;
        // the career gate: fighter 5th-7th, then
        // thief 5th-9th
        if (!rules::bardCareerGate(5, 5)) ++bad;
        if (!rules::bardCareerGate(7, 9)) ++bad;
        if (rules::bardCareerGate(4, 5)) ++bad;
        if (rules::bardCareerGate(8, 5)) ++bad;
        if (rules::bardCareerGate(5, 4)) ++bad;
        if (rules::bardCareerGate(5, 10)) ++bad;
        // the Table I d6 column: 0 at 1st, 1-10 at
        // 2nd-11th, then 10+1 through 10+12
        if (rules::bardHitDice(1) != 0) ++bad;
        if (rules::bardHitDice(2) != 1) ++bad;
        if (rules::bardHitDice(11) != 10) ++bad;
        if (rules::bardHitDice(12) != 11) ++bad;
        if (rules::bardHitDice(23) != 22) ++bad;
        if (rules::bardHitDice(0) != 0) ++bad;
        if (rules::bardHitDice(24) != 22) ++bad;
        // the Table I XP ladder (bard XP only)
        if (rules::bardXpForLevel(1) != 0) ++bad;
        if (rules::bardXpForLevel(2) != 2001) ++bad;
        if (rules::bardXpForLevel(11) != 150001) ++bad;
        if (rules::bardXpForLevel(12) != 200001) ++bad;
        if (rules::bardXpForLevel(13) != 400001) ++bad;
        if (rules::bardXpForLevel(20) != 1800001) ++bad;
        if (rules::bardXpForLevel(23) != 3000001) ++bad;
        // the Table I druid slots
        if (rules::bardDruidSlots(1, 1) != 1) ++bad;
        if (rules::bardDruidSlots(1, 2) != 0) ++bad;
        if (rules::bardDruidSlots(4, 2) != 1) ++bad;
        if (rules::bardDruidSlots(14, 5) != 2) ++bad;
        if (rules::bardDruidSlots(15, 1) != 3) ++bad;
        if (rules::bardDruidSlots(16, 1) != 4) ++bad;
        if (rules::bardDruidSlots(19, 1) != 5) ++bad;
        if (rules::bardDruidSlots(23, 5) != 5) ++bad;
        // the druid ability cap: 12th until the 23rd
        if (rules::bardDruidCastLevel(1) != 1) ++bad;
        if (rules::bardDruidCastLevel(12) != 12) ++bad;
        if (rules::bardDruidCastLevel(13) != 12) ++bad;
        if (rules::bardDruidCastLevel(22) != 12) ++bad;
        if (rules::bardDruidCastLevel(23) != 13) ++bad;
        // the henchmen ladder
        if (rules::bardHenchmen(4) != 0) ++bad;
        if (rules::bardHenchmen(5) != 1) ++bad;
        if (rules::bardHenchmen(8) != 2) ++bad;
        if (rules::bardHenchmen(23) != 999) ++bad;
        // the ability and race gates, Table III
        if (!rules::bardAbilityGate(15, 15, 15, 15,
                                12, 10)) ++bad;
        if (rules::bardAbilityGate(14, 15, 15, 15,
                                12, 10)) ++bad;
        if (rules::bardAbilityGate(15, 15, 15, 15,
                                11, 10)) ++bad;
        if (!rules::bardRaceAllowed(0)) ++bad;
        if (!rules::bardRaceAllowed(4)) ++bad;
        if (rules::bardRaceAllowed(1)) ++bad;
        if (rules::bardShieldAllowed()) ++bad;
        if (!rules::bardOilAllowed()) ++bad;
        printf("R235a bard career seam audit: bad %d\n", bad);
        if (bad) return 1;
    }
