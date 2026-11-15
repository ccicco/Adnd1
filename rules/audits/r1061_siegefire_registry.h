    // ==== R1061: siegefire registry ==========
    // The R1061 de-wire: the 19 retiring static
    // arrays of rules/dmg/siegefire.h ride
    // items::MiscItemRegistry from
    // content/tables/siegefire/ - 4 rowless defs,
    // 19 tables, one pin per def; the KEPT
    // zero-arg scalars stay C++, probed by the
    // R214 pin fragment and the edges here. Eight
    // sections: load, counts, defs-A/B/C/D, seam,
    // edges. Census 1127 -> 1135. DO NOT hand-edit:
    // tools/r1061_splice.py is the only writer.
    {
        int bad = 0;
        // -- 1. load ------------------------------
        {
            items::MiscItemRegistry reg;
            int n = reg.loadDirectory(
                "content/tables/siegefire");
            if (n != 4) ++bad;
            if (!reg.errors().empty()) ++bad;
            for (const auto& kv : reg.all())
                if ((int)kv.second.sources.size() != 1
                    || kv.second.sources[0].first != 0
                    || kv.second.sources[0].second != 1061)
                    ++bad;
            if (!reg.find("siege_fire")) ++bad;
            if (!reg.find("siege_attack")) ++bad;
            if (!reg.find("siege_defensive")) ++bad;
            if (!reg.find("siege_mhp")) ++bad;
        }
        printf("R1061 siegefire registry load audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 2. counts ----------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/siegefire");
            {
                const items::MiscItemDef* d =
                    reg.find("siege_fire");
                if (!d) { ++bad; } else {
                    if ((int)d->pins.size() != 1
                        || d->pins[0].name
                            != "siege_fireTableCount"
                        || d->pins[0].value != 11)
                        ++bad;
                    if ((int)d->tables.size() != 11) ++bad;
                    if (d->tables[0].name
                        != "field_of_fire"
                        || (int)d->tables[0]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[1].name
                        != "range_min_qi"
                        || (int)d->tables[1]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[2].name
                        != "range_max_qi"
                        || (int)d->tables[2]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[3].name
                        != "damage_sm_min"
                        || (int)d->tables[3]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[4].name
                        != "damage_sm_max"
                        || (int)d->tables[4]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[5].name
                        != "damage_l_min"
                        || (int)d->tables[5]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[6].name
                        != "damage_l_max"
                        || (int)d->tables[6]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[7].name
                        != "rate_of_fire_min_h"
                        || (int)d->tables[7]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[8].name
                        != "rate_of_fire_max_h"
                        || (int)d->tables[8]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[9].name
                        != "crew_min"
                        || (int)d->tables[9]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[10].name
                        != "crew_max"
                        || (int)d->tables[10]
                            .values.size() != 6)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("siege_attack");
                if (!d) { ++bad; } else {
                    if ((int)d->pins.size() != 1
                        || d->pins[0].name
                            != "siege_attackTableCount"
                        || d->pins[0].value != 5)
                        ++bad;
                    if ((int)d->tables.size() != 5) ++bad;
                    if (d->tables[0].name
                        != "quarter_points"
                        || (int)d->tables[0]
                            .values.size() != 88)
                        ++bad;
                    if (d->tables[1].name
                        != "per_round"
                        || (int)d->tables[1]
                            .values.size() != 22)
                        ++bad;
                    if (d->tables[2].name
                        != "per_caster_level"
                        || (int)d->tables[2]
                            .values.size() != 22)
                        ++bad;
                    if (d->tables[3].name
                        != "quake_min"
                        || (int)d->tables[3]
                            .values.size() != 4)
                        ++bad;
                    if (d->tables[4].name
                        != "quake_max"
                        || (int)d->tables[4]
                            .values.size() != 4)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("siege_defensive");
                if (!d) { ++bad; } else {
                    if ((int)d->pins.size() != 1
                        || d->pins[0].name
                            != "siege_defensiveTableCount"
                        || d->pins[0].value != 2)
                        ++bad;
                    if ((int)d->tables.size() != 2) ++bad;
                    if (d->tables[0].name
                        != "defensive_min"
                        || (int)d->tables[0]
                            .values.size() != 26)
                        ++bad;
                    if (d->tables[1].name
                        != "defensive_max"
                        || (int)d->tables[1]
                            .values.size() != 26)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("siege_mhp");
                if (!d) { ++bad; } else {
                    if ((int)d->pins.size() != 1
                        || d->pins[0].name
                            != "siege_mhpTableCount"
                        || d->pins[0].value != 1)
                        ++bad;
                    if ((int)d->tables.size() != 1) ++bad;
                    if (d->tables[0].name
                        != "mhp"
                        || (int)d->tables[0]
                            .values.size() != 12)
                        ++bad;
                }
            }
        }
        printf("R1061 siegefire registry counts audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 3. defs-A: the fire columns ----------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/siegefire");
            const items::MiscItemDef* d =
                reg.find("siege_fire");
            if (!d) { ++bad; } else {
                // siegeFieldOfFireDegrees (field_of_fire)
            static const int ksiegeFieldOfFireDegrees[6] = {
                45, 15, 30, 0, 0, 10,
            };
                if (d->tables[0].name
                    != "field_of_fire") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[0]
                            .values[i] != ksiegeFieldOfFireDegrees[i])
                        ++bad;
                // siegeRangeMinQuarterInches (range_min_qi)
            static const int ksiegeRangeMinQuarterInches[6] = {
                1, 72, 60, 0, 0, 96,
            };
                if (d->tables[1].name
                    != "range_min_qi") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[1]
                            .values[i] != ksiegeRangeMinQuarterInches[i])
                        ++bad;
                // siegeRangeMaxQuarterInches (range_max_qi)
            static const int ksiegeRangeMaxQuarterInches[6] = {
                128, 144, 120, 1, 1, 192,
            };
                if (d->tables[2].name
                    != "range_max_qi") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[2]
                            .values[i] != ksiegeRangeMaxQuarterInches[i])
                        ++bad;
                // siegeDamageSMMin (damage_sm_min)
            static const int ksiegeDamageSMMin[6] = {
                2, 2, 2, 9, 9, 3,
            };
                if (d->tables[3].name
                    != "damage_sm_min") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[3]
                            .values[i] != ksiegeDamageSMMin[i])
                        ++bad;
                // siegeDamageSMMax (damage_sm_max)
            static const int ksiegeDamageSMMax[6] = {
                12, 24, 20, 16, 16, 30,
            };
                if (d->tables[4].name
                    != "damage_sm_max") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[4]
                            .values[i] != ksiegeDamageSMMax[i])
                        ++bad;
                // siegeDamageLMin (damage_l_min)
            static const int ksiegeDamageLMin[6] = {
                3, 4, 3, 7, 13, 5,
            };
                if (d->tables[5].name
                    != "damage_l_min") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[5]
                            .values[i] != ksiegeDamageLMin[i])
                        ++bad;
                // siegeDamageLMax (damage_l_max)
            static const int ksiegeDamageLMax[6] = {
                18, 16, 12, 12, 24, 20,
            };
                if (d->tables[6].name
                    != "damage_l_max") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[6]
                            .values[i] != ksiegeDamageLMax[i])
                        ++bad;
                // siegeRateOfFireMinHundredths (rate_of_fire_min_h)
            static const int ksiegeRateOfFireMinHundredths[6] = {
                25, 25, 25, 50, 50, 25,
            };
                if (d->tables[7].name
                    != "rate_of_fire_min_h") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[7]
                            .values[i] != ksiegeRateOfFireMinHundredths[i])
                        ++bad;
                // siegeRateOfFireMaxHundredths (rate_of_fire_max_h)
            static const int ksiegeRateOfFireMaxHundredths[6] = {
                50, 25, 25, 50, 50, 25,
            };
                if (d->tables[8].name
                    != "rate_of_fire_max_h") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[8]
                            .values[i] != ksiegeRateOfFireMaxHundredths[i])
                        ++bad;
                // siegeCrewMin (crew_min)
            static const int ksiegeCrewMin[6] = {
                2, 6, 4, 10, 10, 8,
            };
                if (d->tables[9].name
                    != "crew_min") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[9]
                            .values[i] != ksiegeCrewMin[i])
                        ++bad;
                // siegeCrewMax (crew_max)
            static const int ksiegeCrewMax[6] = {
                4, 10, 6, 20, 20, 12,
            };
                if (d->tables[10].name
                    != "crew_max") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[10]
                            .values[i] != ksiegeCrewMax[i])
                        ++bad;
            }
        }
        printf("R1061 siegefire registry defs-A audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 4. defs-B: the attack columns --------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/siegefire");
            const items::MiscItemDef* d =
                reg.find("siege_attack");
            if (!d) { ++bad; } else {
                // siegeAttackQuarterPoints (quarter_points)
            static const int ksiegeAttackQuarterPoints[88] = {
                4, 0, 2, 1,
                24, 0, 16, 8,
                16, 0, 8, 4,
                0, 40, 0, 0,
                8, 8, 8, 8,
                8, 40, 8, 4,
                0, 0, 0, 0,
                2, 0, 0, 0,
                12, 0, 4, 2,
                8, 0, 4, 2,
                4, 0, 2, 1,
                16, 0, 8, 4,
                24, 0, 16, 8,
                12, 4, 8, 4,
                12, 4, 4, 2,
                72, 24, 32, 16,
                2, 0, 0, 0,
                0, 80, 0, 0,
                4, 0, 1, 0,
                2, 2, 2, 1,
                32, 8, 8, 4,
                32, 0, 20, 12,
            };
                if (d->tables[0].name
                    != "quarter_points") ++bad;
                else for (int i = 0; i < 88; ++i)
                    if ((int)d->tables[0]
                            .values[i] != ksiegeAttackQuarterPoints[i])
                        ++bad;
                // siegeAttackPerRound (per_round)
            static const int ksiegeAttackPerRound[22] = {
                1, 0, 0, 0,
                0, 1, 0, 0,
                1, 1, 1, 0,
                0, 1, 1, 0,
                0, 0, 1, 1,
                1, 0,
            };
                if (d->tables[1].name
                    != "per_round") ++bad;
                else for (int i = 0; i < 22; ++i)
                    if ((int)d->tables[1]
                            .values[i] != ksiegeAttackPerRound[i])
                        ++bad;
                // siegeAttackPerCasterLevel (per_caster_level)
            static const int ksiegeAttackPerCasterLevel[22] = {
                0, 0, 0, 0,
                0, 0, 0, 1,
                0, 0, 0, 0,
                0, 0, 0, 0,
                1, 0, 0, 0,
                0, 0,
            };
                if (d->tables[2].name
                    != "per_caster_level") ++bad;
                else for (int i = 0; i < 22; ++i)
                    if ((int)d->tables[2]
                            .values[i] != ksiegeAttackPerCasterLevel[i])
                        ++bad;
                // siegeAttackQuakeMin (quake_min)
            static const int ksiegeAttackQuakeMin[4] = {
                5, 5, 5, 5,
            };
                if (d->tables[3].name
                    != "quake_min") ++bad;
                else for (int i = 0; i < 4; ++i)
                    if ((int)d->tables[3]
                            .values[i] != ksiegeAttackQuakeMin[i])
                        ++bad;
                // siegeAttackQuakeMax (quake_max)
            static const int ksiegeAttackQuakeMax[4] = {
                60, 30, 60, 30,
            };
                if (d->tables[4].name
                    != "quake_max") ++bad;
                else for (int i = 0; i < 4; ++i)
                    if ((int)d->tables[4]
                            .values[i] != ksiegeAttackQuakeMax[i])
                        ++bad;
            }
        }
        printf("R1061 siegefire registry defs-B audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 5. defs-C: quake, defensive, mhp -----
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/siegefire");
            {
            const items::MiscItemDef* d =
                reg.find("siege_defensive");
            if (!d) { ++bad; } else {
                // constructionDefensiveMin (defensive_min)
            static const int kconstructionDefensiveMin[26] = {
                150, 25, 20, 12, 10, 8, 20, 10,
                1, 3, 10, 8, 120, 2, 10, 6,
                20, 15, 12, 20, 40, 30, 40, 20,
                4, 12,
            };
                if (d->tables[0].name
                    != "defensive_min") ++bad;
                else for (int i = 0; i < 26; ++i)
                    if ((int)d->tables[0]
                            .values[i] != kconstructionDefensiveMin[i])
                        ++bad;
                // constructionDefensiveMax (defensive_max)
            static const int kconstructionDefensiveMax[26] = {
                150, 25, 20, 12, 10, 16, 20, 10,
                1, 3, 15, 12, 120, 2, 10, 12,
                20, 15, 12, 20, 80, 50, 40, 20,
                4, 12,
            };
                if (d->tables[1].name
                    != "defensive_max") ++bad;
                else for (int i = 0; i < 26; ++i)
                    if ((int)d->tables[1]
                            .values[i] != kconstructionDefensiveMax[i])
                        ++bad;
            }
            }
            {
            const items::MiscItemDef* d =
                reg.find("siege_mhp");
            if (!d) { ++bad; } else {
                // siegeDeviceMhp (mhp)
            static const int ksiegeDeviceMhp[12] = {
                2, 6, 4, 2, 10, 4, 3, 12,
                0, 16, 12, 8,
            };
                if (d->tables[0].name
                    != "mhp") ++bad;
                else for (int i = 0; i < 12; ++i)
                    if ((int)d->tables[0]
                            .values[i] != ksiegeDeviceMhp[i])
                        ++bad;
            }
            }
        }
        printf("R1061 siegefire registry defs-C audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 6. defs-D: accessor parity sweep -----
        // every accessor, every index, against
        // the registry seam (the R214 caller
        // stays byte-identical; this label
        // carries the parity it used to carry)
        {
            {
                const auto* g = rules::sfTable(
                    "siege_fire", "field_of_fire");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::siegeFieldOfFireDegrees(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::sfTable(
                    "siege_fire", "range_min_qi");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::siegeRangeMinQuarterInches(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::sfTable(
                    "siege_fire", "range_max_qi");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::siegeRangeMaxQuarterInches(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::sfTable(
                    "siege_fire", "damage_sm_min");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::siegeDamageSMMin(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::sfTable(
                    "siege_fire", "damage_sm_max");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::siegeDamageSMMax(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::sfTable(
                    "siege_fire", "damage_l_min");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::siegeDamageLMin(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::sfTable(
                    "siege_fire", "damage_l_max");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::siegeDamageLMax(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::sfTable(
                    "siege_fire", "rate_of_fire_min_h");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::siegeRateOfFireMinHundredths(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::sfTable(
                    "siege_fire", "rate_of_fire_max_h");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::siegeRateOfFireMaxHundredths(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::sfTable(
                    "siege_fire", "crew_min");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::siegeCrewMin(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::sfTable(
                    "siege_fire", "crew_max");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::siegeCrewMax(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::sfTable(
                    "siege_attack", "quarter_points");
                if (!g) { ++bad; }
                else for (int i = 0; i < 88; ++i)
                    if (rules::siegeAttackQuarterPoints(
                            i / 4, i % 4)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::sfTable(
                    "siege_attack", "per_round");
                if (!g) { ++bad; }
                else for (int i = 0; i < 22; ++i)
                    if (rules::siegeAttackPerRound(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::sfTable(
                    "siege_attack", "per_caster_level");
                if (!g) { ++bad; }
                else for (int i = 0; i < 22; ++i)
                    if (rules::siegeAttackPerCasterLevel(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::sfTable(
                    "siege_attack", "quake_min");
                if (!g) { ++bad; }
                else for (int i = 0; i < 4; ++i)
                    if (rules::siegeAttackQuakeMin(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::sfTable(
                    "siege_attack", "quake_max");
                if (!g) { ++bad; }
                else for (int i = 0; i < 4; ++i)
                    if (rules::siegeAttackQuakeMax(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::sfTable(
                    "siege_defensive", "defensive_min");
                if (!g) { ++bad; }
                else for (int i = 0; i < 26; ++i)
                    if (rules::constructionDefensiveMin(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::sfTable(
                    "siege_defensive", "defensive_max");
                if (!g) { ++bad; }
                else for (int i = 0; i < 26; ++i)
                    if (rules::constructionDefensiveMax(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::sfTable(
                    "siege_mhp", "mhp");
                if (!g) { ++bad; }
                else for (int i = 0; i < 12; ++i)
                    if (rules::siegeDeviceMhp(i)
                        != (int)(*g)[i]) ++bad;
            }
        }
        printf("R1061 siegefire registry defs-D audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 7. seam -------------------------------
        // all 19 (key, tag) pairs resolve; wrong
        // tag and wrong key read null; two calls
        // share the cached table (stability)
        {
            if (!rules::sfTable("siege_fire", "field_of_fire")) ++bad;
            if (!rules::sfTable("siege_fire", "range_min_qi")) ++bad;
            if (!rules::sfTable("siege_fire", "range_max_qi")) ++bad;
            if (!rules::sfTable("siege_fire", "damage_sm_min")) ++bad;
            if (!rules::sfTable("siege_fire", "damage_sm_max")) ++bad;
            if (!rules::sfTable("siege_fire", "damage_l_min")) ++bad;
            if (!rules::sfTable("siege_fire", "damage_l_max")) ++bad;
            if (!rules::sfTable("siege_fire", "rate_of_fire_min_h")) ++bad;
            if (!rules::sfTable("siege_fire", "rate_of_fire_max_h")) ++bad;
            if (!rules::sfTable("siege_fire", "crew_min")) ++bad;
            if (!rules::sfTable("siege_fire", "crew_max")) ++bad;
            if (!rules::sfTable("siege_attack", "quarter_points")) ++bad;
            if (!rules::sfTable("siege_attack", "per_round")) ++bad;
            if (!rules::sfTable("siege_attack", "per_caster_level")) ++bad;
            if (!rules::sfTable("siege_attack", "quake_min")) ++bad;
            if (!rules::sfTable("siege_attack", "quake_max")) ++bad;
            if (!rules::sfTable("siege_defensive", "defensive_min")) ++bad;
            if (!rules::sfTable("siege_defensive", "defensive_max")) ++bad;
            if (!rules::sfTable("siege_mhp", "mhp")) ++bad;
            if (rules::sfTable("siege_fire", "no_such_tag")) ++bad;
            if (rules::sfTable("no_such_def", "field_of_fire")) ++bad;
            {
                const auto* p1 = rules::sfTable("siege_fire",
                                     "field_of_fire");
                const auto* p2 = rules::sfTable("siege_fire",
                                     "field_of_fire");
                if (p1 != p2) ++bad;
            }
        }
        printf("R1061 siegefire registry seam audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 8. edges -------------------------------
        // accessor clamps and KEPT scalar spots
        {
            if (rules::siegeFieldOfFireDegrees(-9)
                != rules::siegeFieldOfFireDegrees(0)) ++bad;
            if (rules::siegeFieldOfFireDegrees(99)
                != rules::siegeFieldOfFireDegrees(5)) ++bad;
            if (rules::siegeRangeMinQuarterInches(99)
                != rules::siegeRangeMinQuarterInches(5)) ++bad;
            if (rules::siegeAttackQuarterPoints(-9, 0)
                != rules::siegeAttackQuarterPoints(0, 0)) ++bad;
            if (rules::siegeAttackQuarterPoints(99, 3)
                != rules::siegeAttackQuarterPoints(21, 3)) ++bad;
            if (rules::siegeAttackQuarterPoints(0, 99)
                != rules::siegeAttackQuarterPoints(0, 3)) ++bad;
            if (rules::siegeAttackPerRound(99)
                != rules::siegeAttackPerRound(21)) ++bad;
            if (rules::siegeAttackQuakeMin(9)
                != rules::siegeAttackQuakeMin(3)) ++bad;
            if (rules::siegeAttackQuakeMax(-3)
                != rules::siegeAttackQuakeMax(0)) ++bad;
            if (rules::constructionDefensiveMin(99)
                != rules::constructionDefensiveMin(25)) ++bad;
            if (rules::constructionDefensiveMax(-3)
                != rules::constructionDefensiveMax(0)) ++bad;
            if (rules::siegeDeviceMhp(99)
                != rules::siegeDeviceMhp(11)) ++bad;
            if (rules::fireDeviceCount() != 6) ++bad;
            if (rules::siegeAttackKindCount() != 22) ++bad;
            if (rules::defensiveKindCount() != 26) ++bad;
            if (rules::wmDirectFireBonus() != 4) ++bad;
            if (rules::siegeBelowMinCrewRatePct() != 50) ++bad;
        }
        printf("R1061 siegefire registry edges audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
    }
