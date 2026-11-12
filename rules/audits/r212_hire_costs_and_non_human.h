    // ---- R212: the hire costs and non-human troops audit ----
    // DMG pp.116-118: the cleric spell
    // hire prices, the travel and risk
    // multipliers, the charm-opposite
    // rule, and the non-human troop
    // control percents.
    {
        Hirecost hirecost;
        int bad = 0;
        // the spell price table, every cell
        if (hirecost.hireSpellCount() != 40
            || HS_COUNT != 40
            || HS_GATE != 20
            || HS_TRUE_SEEING != 39
            || HU_FLAT != 0
            || HU_PER_PERSON != 1
            || HU_PER_CASTER_LEVEL != 2
            || HU_PER_RECIPIENT_LEVEL != 3
            || HU_PER_PERSON_PER_CASTER_LEVEL != 4
            || HU_PER_POINT_HEALED != 5
            || HU_BASE_PLUS_PER_QUESTION != 6
            || HU_BASE_PLUS_PER_CASTER_LEVEL != 7
            || HU_BASE_PLUS_PER_RECIPIENT_LEVEL != 8) ++bad;
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
            if (hirecost.hireSpellBase(s) != kBase[s] ||
                hirecost.hireSpellUnit(s) != kUnit[s] ||
                hirecost.hireSpellRate(s) != kRate[s]) ++bad;
        // the unit semantics, one pin per
        // unit code
        if (hirecost.hireSpellUnit(HS_AUGURY)
                != HU_FLAT ||
            hirecost.hireSpellUnit(HS_ASTRAL_SPELL)
                != HU_PER_PERSON ||
            hirecost.hireSpellUnit(HS_DISPEL_MAGIC)
                != HU_PER_CASTER_LEVEL ||
            hirecost.hireSpellUnit(HS_ATONEMENT)
                != HU_PER_RECIPIENT_LEVEL ||
            hirecost.hireSpellUnit(HS_BLESS)
                != HU_PER_PERSON_PER_CASTER_LEVEL ||
            hirecost.hireSpellUnit(HS_HEAL)
                != HU_PER_POINT_HEALED ||
            hirecost.hireSpellUnit(HS_COMMUNE)
                != HU_BASE_PLUS_PER_QUESTION ||
            hirecost.hireSpellUnit(HS_RAISE_DEAD)
                != HU_BASE_PLUS_PER_CASTER_LEVEL ||
            hirecost.hireSpellUnit(HS_RESTORATION)
                != HU_BASE_PLUS_PER_RECIPIENT_LEVEL) ++bad;
        // the sample prices, worked from
        // the print clauses
        if (hirecost.hireSpellCost(HS_ASTRAL_SPELL,
                0, 1, 0, 0, 0) != 5000 ||
            hirecost.hireSpellCost(HS_ASTRAL_SPELL,
                0, 4, 0, 0, 0) != 20000 ||
            hirecost.hireSpellCost(HS_ATONEMENT,
                0, 0, 7, 0, 0) != 3500 ||
            hirecost.hireSpellCost(HS_AUGURY,
                12, 3, 5, 2, 4) != 300 ||
            hirecost.hireSpellCost(HS_BLESS,
                5, 6, 0, 0, 0) != 150 ||
            hirecost.hireSpellCost(HS_COMMUNE,
                0, 0, 0, 3, 0) != 2500 ||
            hirecost.hireSpellCost(HS_COMMUNE,
                0, 0, 0, 0, 0) != 1000 ||
            hirecost.hireSpellCost(HS_DISPEL_MAGIC,
                11, 0, 0, 0, 0) != 1100 ||
            hirecost.hireSpellCost(HS_EXORCISE,
                3, 0, 0, 0, 0) != 3000 ||
            hirecost.hireSpellCost(HS_GATE,
                17, 9, 9, 9, 9) != 50000 ||
            hirecost.hireSpellCost(HS_HEAL,
                0, 0, 0, 0, 15) != 3000 ||
            hirecost.hireSpellCost(HS_HEAL,
                0, 0, 0, 0, 0) != 0 ||
            hirecost.hireSpellCost(HS_RAISE_DEAD,
                9, 0, 0, 0, 0) != 5500 ||
            hirecost.hireSpellCost(HS_RESTORATION,
                0, 0, 8, 0, 0) != 18000 ||
            hirecost.hireSpellCost(HS_SLOW_POISON,
                12, 0, 0, 0, 0) != 2400 ||
            hirecost.hireSpellCost(HS_TONGUES,
                9, 5, 5, 5, 5) != 500 ||
            hirecost.hireSpellCost(HS_TRUE_SEEING,
                7, 0, 0, 0, 0) != 2800) ++bad;
        // the clamps: no input produces
        // negative gold, and the spell
        // index clamps to the first and
        // last rows
        if (hirecost.hireSpellCost(HS_ASTRAL_SPELL,
                -3, -4, -5, -6, -7) != 0 ||
            hirecost.hireSpellCost(-9, 5, 5, 5, 5, 5)
                != hirecost.hireSpellCost(0, 5, 5, 5, 5, 5) ||
            hirecost.hireSpellCost(99, 5, 5, 5, 5, 5)
                != hirecost.hireSpellCost(39, 5, 5, 5, 5, 5)) ++bad;
        // the hiring clauses
        if (hirecost.hireTravelNotAtRiskFactor() != 2 ||
            hirecost.hireAtRiskFactor() != 5 ||
            hirecost.hireRiskRefusalPossible() != 1 ||
            hirecost.hireCharmOppositePercent() != 25 ||
            hirecost.hireAttackSpellEntriesPriced() != 0 ||
            hirecost.hireHiredCastersAccompanyParty() != 0 ||
            hirecost.hireInterruptRaisesRates() != 1) ++bad;
        // the troop control table, every cell
        if (hirecost.troopRaceCount() != 7
            || TR_TROOP_COUNT != 7
            || TR_BUGBEAR != 0
            || TR_ORC != 6) ++bad;
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
                if (hirecost.troopControlPercent(r, c)
                        != kCtrl[r * 3 + c]) ++bad;
        // the troop clamps and edge cases
        if (hirecost.troopControlPercent(
                TR_LIZARDMAN, 2) != 100 ||
            hirecost.troopControlPercent(
                TR_BUGBEAR, 0) != 30 ||
            hirecost.troopControlPercent(
                TR_KOBOLD, 2) != 95 ||
            hirecost.troopControlPercent(
                TR_GNOLL, 1) != 40 ||
            hirecost.troopControlPercent(
                TR_HOBGOBLIN, 0) != 20 ||
            hirecost.troopControlPercent(
                TR_GOBLIN, 2) != 90 ||
            hirecost.troopControlPercent(
                TR_ORC, 1) != 50 ||
            hirecost.troopControlPercent(-1, 1)
                != hirecost.troopControlPercent(0, 1) ||
            hirecost.troopControlPercent(7, 1)
                != hirecost.troopControlPercent(6, 1) ||
            hirecost.troopControlPercent(3, -2)
                != hirecost.troopControlPercent(3, 0) ||
            hirecost.troopControlPercent(3, 9)
                != hirecost.troopControlPercent(3, 2)) ++bad;
        // the troop clauses
        if (hirecost.troopFightsFriendlyHumansPercent() != 25 ||
            hirecost.troopWeakLeaderWithOfficersPossible() != 0 ||
            hirecost.troopHighPayViewedAsWeakness() != 1 ||
            hirecost.demiHumanTroopsServeHumanMaster() != 0) ++bad;
        printf("R212 hire costs and non-human troops audit: bad %d\n", bad);
        if (bad) return 1;
    }
