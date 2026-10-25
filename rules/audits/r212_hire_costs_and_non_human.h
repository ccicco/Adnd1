    // ---- R212: the hire costs and non-human troops audit ----
    // DMG pp.116-118: the cleric spell
    // hire prices, the travel and risk
    // multipliers, the charm-opposite
    // rule, and the non-human troop
    // control percents.
    {
        int bad = 0;
        // the spell price table, every cell
        if (rules::hireSpellCount() != 40
            || rules::HS_COUNT != 40
            || rules::HS_GATE != 20
            || rules::HS_TRUE_SEEING != 39
            || rules::HU_FLAT != 0
            || rules::HU_PER_PERSON != 1
            || rules::HU_PER_CASTER_LEVEL != 2
            || rules::HU_PER_RECIPIENT_LEVEL != 3
            || rules::HU_PER_PERSON_PER_CASTER_LEVEL != 4
            || rules::HU_PER_POINT_HEALED != 5
            || rules::HU_BASE_PLUS_PER_QUESTION != 6
            || rules::HU_BASE_PLUS_PER_CASTER_LEVEL != 7
            || rules::HU_BASE_PLUS_PER_RECIPIENT_LEVEL != 8) ++bad;
        static const int kBase[40] = {
            0, 0, 300, 0, 1000, 500, 10000,
            1000, 1000, 100, 350, 600, 100,
            150, 1000, 0, 1000, 10000,
            0, 0, 50000, 0, 0, 1000, 0,
            4000, 0, 0, 100, 1000, 15000,
            0, 0, 0, 10000, 0, 0, 0, 500, 0,
        };
        static const int kUnit[40] = {
            1, 3, 0, 4, 6, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 2, 0, 0,
            2, 2, 0, 2, 5, 0, 2, 0, 2, 2,
            0, 7, 0, 2, 2, 2, 8, 2, 2, 2,
            0, 2,
        };
        static const int kRate[40] = {
            5000, 500, 0, 5, 500, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 100,
            0, 0,
            1000, 500, 0, 100, 200, 0,
            1000, 0, 50, 50, 0, 500, 0,
            500, 50, 100, 1000, 100, 200,
            100, 0, 400,
        };
        for (int s = 0; s < 40; ++s)
            if (rules::hireSpellBase(s) != kBase[s] ||
                rules::hireSpellUnit(s) != kUnit[s] ||
                rules::hireSpellRate(s) != kRate[s]) ++bad;
        // the unit semantics, one pin per
        // unit code
        if (rules::hireSpellUnit(rules::HS_AUGURY)
                != rules::HU_FLAT ||
            rules::hireSpellUnit(rules::HS_ASTRAL_SPELL)
                != rules::HU_PER_PERSON ||
            rules::hireSpellUnit(rules::HS_DISPEL_MAGIC)
                != rules::HU_PER_CASTER_LEVEL ||
            rules::hireSpellUnit(rules::HS_ATONEMENT)
                != rules::HU_PER_RECIPIENT_LEVEL ||
            rules::hireSpellUnit(rules::HS_BLESS)
                != rules::HU_PER_PERSON_PER_CASTER_LEVEL ||
            rules::hireSpellUnit(rules::HS_HEAL)
                != rules::HU_PER_POINT_HEALED ||
            rules::hireSpellUnit(rules::HS_COMMUNE)
                != rules::HU_BASE_PLUS_PER_QUESTION ||
            rules::hireSpellUnit(rules::HS_RAISE_DEAD)
                != rules::HU_BASE_PLUS_PER_CASTER_LEVEL ||
            rules::hireSpellUnit(rules::HS_RESTORATION)
                != rules::HU_BASE_PLUS_PER_RECIPIENT_LEVEL) ++bad;
        // the sample prices, worked from
        // the print clauses
        if (rules::hireSpellCost(rules::HS_ASTRAL_SPELL,
                0, 1, 0, 0, 0) != 5000 ||
            rules::hireSpellCost(rules::HS_ASTRAL_SPELL,
                0, 4, 0, 0, 0) != 20000 ||
            rules::hireSpellCost(rules::HS_ATONEMENT,
                0, 0, 7, 0, 0) != 3500 ||
            rules::hireSpellCost(rules::HS_AUGURY,
                12, 3, 5, 2, 4) != 300 ||
            rules::hireSpellCost(rules::HS_BLESS,
                5, 6, 0, 0, 0) != 150 ||
            rules::hireSpellCost(rules::HS_COMMUNE,
                0, 0, 0, 3, 0) != 2500 ||
            rules::hireSpellCost(rules::HS_COMMUNE,
                0, 0, 0, 0, 0) != 1000 ||
            rules::hireSpellCost(rules::HS_DISPEL_MAGIC,
                11, 0, 0, 0, 0) != 1100 ||
            rules::hireSpellCost(rules::HS_EXORCISE,
                3, 0, 0, 0, 0) != 3000 ||
            rules::hireSpellCost(rules::HS_GATE,
                17, 9, 9, 9, 9) != 50000 ||
            rules::hireSpellCost(rules::HS_HEAL,
                0, 0, 0, 0, 15) != 3000 ||
            rules::hireSpellCost(rules::HS_HEAL,
                0, 0, 0, 0, 0) != 0 ||
            rules::hireSpellCost(rules::HS_RAISE_DEAD,
                9, 0, 0, 0, 0) != 5500 ||
            rules::hireSpellCost(rules::HS_RESTORATION,
                0, 0, 8, 0, 0) != 18000 ||
            rules::hireSpellCost(rules::HS_SLOW_POISON,
                12, 0, 0, 0, 0) != 2400 ||
            rules::hireSpellCost(rules::HS_TONGUES,
                9, 5, 5, 5, 5) != 500 ||
            rules::hireSpellCost(rules::HS_TRUE_SEEING,
                7, 0, 0, 0, 0) != 2800) ++bad;
        // the clamps: no input produces
        // negative gold, and the spell
        // index clamps to the first and
        // last rows
        if (rules::hireSpellCost(rules::HS_ASTRAL_SPELL,
                -3, -4, -5, -6, -7) != 0 ||
            rules::hireSpellCost(-9, 5, 5, 5, 5, 5)
                != rules::hireSpellCost(0, 5, 5, 5, 5, 5) ||
            rules::hireSpellCost(99, 5, 5, 5, 5, 5)
                != rules::hireSpellCost(39, 5, 5, 5, 5, 5)) ++bad;
        // the hiring clauses
        if (rules::hireTravelNotAtRiskFactor() != 2 ||
            rules::hireAtRiskFactor() != 5 ||
            rules::hireRiskRefusalPossible() != 1 ||
            rules::hireCharmOppositePercent() != 25 ||
            rules::hireAttackSpellEntriesPriced() != 0 ||
            rules::hireHiredCastersAccompanyParty() != 0 ||
            rules::hireInterruptRaisesRates() != 1) ++bad;
        // the troop control table, every cell
        if (rules::troopRaceCount() != 7
            || rules::TR_TROOP_COUNT != 7
            || rules::TR_BUGBEAR != 0
            || rules::TR_ORC != 6) ++bad;
        static const int kCtrl[21] = {
            30, 50, 80,
            30, 40, 80,
            40, 50, 90,
            20, 40, 90,
            25, 50, 95,
            10, 60, 100,
            20, 50, 90,
        };
        for (int r = 0; r < 7; ++r)
            for (int c = 0; c < 3; ++c)
                if (rules::troopControlPercent(r, c)
                        != kCtrl[r * 3 + c]) ++bad;
        // the troop clamps and edge cases
        if (rules::troopControlPercent(
                rules::TR_LIZARDMAN, 2) != 100 ||
            rules::troopControlPercent(
                rules::TR_BUGBEAR, 0) != 30 ||
            rules::troopControlPercent(
                rules::TR_KOBOLD, 2) != 95 ||
            rules::troopControlPercent(
                rules::TR_GNOLL, 1) != 40 ||
            rules::troopControlPercent(
                rules::TR_HOBGOBLIN, 0) != 20 ||
            rules::troopControlPercent(
                rules::TR_GOBLIN, 2) != 90 ||
            rules::troopControlPercent(
                rules::TR_ORC, 1) != 50 ||
            rules::troopControlPercent(-1, 1)
                != rules::troopControlPercent(0, 1) ||
            rules::troopControlPercent(7, 1)
                != rules::troopControlPercent(6, 1) ||
            rules::troopControlPercent(3, -2)
                != rules::troopControlPercent(3, 0) ||
            rules::troopControlPercent(3, 9)
                != rules::troopControlPercent(3, 2)) ++bad;
        // the troop clauses
        if (rules::troopFightsFriendlyHumansPercent() != 25 ||
            rules::troopWeakLeaderWithOfficersPossible() != 0 ||
            rules::troopHighPayViewedAsWeakness() != 1 ||
            rules::demiHumanTroopsServeHumanMaster() != 0) ++bad;
        printf("R212 hire costs and non-human troops audit: bad %d\n", bad);
        if (bad) return 1;
    }
