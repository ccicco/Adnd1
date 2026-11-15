    // ==== R1052: poison registry ========================
    // The R1052 de-wire: the 10 arrays of
    // rules/dmg/poison.h ride items::
    // MiscItemRegistry from content/tables/
    // dm_poison/ (2 defs: grade rows + the
    // p.20 columns; damage_if_no_save is
    // pre-kill, the accessor folds the
    // kills model back in). Six sections: 
    // load, counts, ingestive, insinuative,
    // seam, edges. Census 1070 -> 1076. DO NOT
    // hand-edit: tools/r1052_splice.py is the
    // only writer.
    {
        int bad = 0;
        // -- 1. load ---------------------------------
        {
            items::MiscItemRegistry reg;
            int n = reg.loadDirectory(
                "content/tables/dm_poison");
            if (n != 2) ++bad;
            if (!reg.errors().empty()) ++bad;
            for (const auto& kv : reg.all())
                if ((int)kv.second.sources.size() != 1
                    || kv.second.sources[0].second != 1052)
                    ++bad;
            if (!reg.find("dm_poison_ingestive")) ++bad;
            if (!reg.find("dm_poison_insinuative")) ++bad;
        }
        printf("R1052 poison registry load audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 2. counts --------------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/dm_poison");
            {
                const items::MiscItemDef* d =
                    reg.find("dm_poison_ingestive");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 5
                        || (int)d->pins.size() != 1
                        || d->pins[0].name != "dm_poison_ingestiveRowCount"
                        || d->pins[0].value != 5
                        || (int)d->tables.size() != 6)
                        ++bad;
                    if (d->tables[0].name
                        != "cost_per_dose"
                        || (int)d->tables[0]
                            .values.size() != 5)
                        ++bad;
                    if (d->tables[1].name
                        != "onset_min"
                        || (int)d->tables[1]
                            .values.size() != 5)
                        ++bad;
                    if (d->tables[2].name
                        != "onset_max"
                        || (int)d->tables[2]
                            .values.size() != 5)
                        ++bad;
                    if (d->tables[3].name
                        != "detect_chance"
                        || (int)d->tables[3]
                            .values.size() != 5)
                        ++bad;
                    if (d->tables[4].name
                        != "damage_if_save"
                        || (int)d->tables[4]
                            .values.size() != 5)
                        ++bad;
                    if (d->tables[5].name
                        != "damage_if_no_save"
                        || (int)d->tables[5]
                            .values.size() != 5)
                        ++bad;
                    if (d->rows[0].set !=
                        "dm_poison_ingestive" || d->rows[0]
                        .bandLo != 0 || d->rows[0]
                        .bandHi != 0 || std::string(
                        d->rows[0].name)
                        != "A")
                        ++bad;
                    if (d->rows[1].set !=
                        "dm_poison_ingestive" || d->rows[1]
                        .bandLo != 1 || d->rows[1]
                        .bandHi != 1 || std::string(
                        d->rows[1].name)
                        != "B")
                        ++bad;
                    if (d->rows[2].set !=
                        "dm_poison_ingestive" || d->rows[2]
                        .bandLo != 2 || d->rows[2]
                        .bandHi != 2 || std::string(
                        d->rows[2].name)
                        != "C")
                        ++bad;
                    if (d->rows[3].set !=
                        "dm_poison_ingestive" || d->rows[3]
                        .bandLo != 3 || d->rows[3]
                        .bandHi != 3 || std::string(
                        d->rows[3].name)
                        != "D")
                        ++bad;
                    if (d->rows[4].set !=
                        "dm_poison_ingestive" || d->rows[4]
                        .bandLo != 4 || d->rows[4]
                        .bandHi != 4 || std::string(
                        d->rows[4].name)
                        != "E")
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("dm_poison_insinuative");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 4
                        || (int)d->pins.size() != 1
                        || d->pins[0].name != "dm_poison_insinuativeRowCount"
                        || d->pins[0].value != 4
                        || (int)d->tables.size() != 4)
                        ++bad;
                    if (d->tables[0].name
                        != "cost_per_dose"
                        || (int)d->tables[0]
                            .values.size() != 4)
                        ++bad;
                    if (d->tables[1].name
                        != "onset_min"
                        || (int)d->tables[1]
                            .values.size() != 4)
                        ++bad;
                    if (d->tables[2].name
                        != "onset_max"
                        || (int)d->tables[2]
                            .values.size() != 4)
                        ++bad;
                    if (d->tables[3].name
                        != "damage_if_no_save"
                        || (int)d->tables[3]
                            .values.size() != 4)
                        ++bad;
                    if (d->rows[0].set !=
                        "dm_poison_insinuative" || d->rows[0]
                        .bandLo != 0 || d->rows[0]
                        .bandHi != 0 || std::string(
                        d->rows[0].name)
                        != "A")
                        ++bad;
                    if (d->rows[1].set !=
                        "dm_poison_insinuative" || d->rows[1]
                        .bandLo != 1 || d->rows[1]
                        .bandHi != 1 || std::string(
                        d->rows[1].name)
                        != "B")
                        ++bad;
                    if (d->rows[2].set !=
                        "dm_poison_insinuative" || d->rows[2]
                        .bandLo != 2 || d->rows[2]
                        .bandHi != 2 || std::string(
                        d->rows[2].name)
                        != "C")
                        ++bad;
                    if (d->rows[3].set !=
                        "dm_poison_insinuative" || d->rows[3]
                        .bandLo != 3 || d->rows[3]
                        .bandHi != 3 || std::string(
                        d->rows[3].name)
                        != "D")
                        ++bad;
                }
            }
        }
        printf("R1052 poison registry counts audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 3. the dm_poison_ingestive ----
        {
            const int wantPiCostPerDose[] = {
                5, 30, 200, 500, 1000,
            };
            for (int i = 0; i < 5; ++i)
                if (rules::poisonCostPerDose(0, i)
                    != wantPiCostPerDose[i])
                    ++bad;
            const int wantPiOnsetMin[] = {
                2, 2, 1, 1, 1,
            };
            for (int i = 0; i < 5; ++i)
                if (rules::poisonOnsetMin(0, i)
                    != wantPiOnsetMin[i])
                    ++bad;
            const int wantPiOnsetMax[] = {
                8, 5, 2, 1, 4,
            };
            for (int i = 0; i < 5; ++i)
                if (rules::poisonOnsetMax(0, i)
                    != wantPiOnsetMax[i])
                    ++bad;
            const int wantPiDetectChance[] = {
                80, 65, 40, 15, 0,
            };
            for (int i = 0; i < 5; ++i)
                if (rules::poisonDetectChance(0, i)
                    != wantPiDetectChance[i])
                    ++bad;
            const int wantPiDamageIfSave[] = {
                10, 15, 20, 25, 30,
            };
            for (int i = 0; i < 5; ++i)
                if (rules::poisonDamageIfSave(0, i)
                    != wantPiDamageIfSave[i])
                    ++bad;
            const int wantPiDamageIfNoSave[] = {
                20, 30, 40, -1, -1,
            };
            for (int i = 0; i < 5; ++i)
                if (rules::poisonDamageIfNoSave(0, i)
                    != wantPiDamageIfNoSave[i])
                    ++bad;
        }
        printf("R1052 ingestive poisons audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 4. the dm_poison_insinuative ----
        {
            const int wantPsCostPerDose[] = {
                10, 75, 600, 1500,
            };
            for (int i = 0; i < 4; ++i)
                if (rules::poisonCostPerDose(1, i)
                    != wantPsCostPerDose[i])
                    ++bad;
            const int wantPsOnsetMin[] = {
                2, 1, 1, 1,
            };
            for (int i = 0; i < 4; ++i)
                if (rules::poisonOnsetMin(1, i)
                    != wantPsOnsetMin[i])
                    ++bad;
            const int wantPsOnsetMax[] = {
                5, 3, 1, 1,
            };
            for (int i = 0; i < 4; ++i)
                if (rules::poisonOnsetMax(1, i)
                    != wantPsOnsetMax[i])
                    ++bad;
            const int wantPsDamageIfNoSave[] = {
                15, 25, 35, -1,
            };
            for (int i = 0; i < 4; ++i)
                if (rules::poisonDamageIfNoSave(1, i)
                    != wantPsDamageIfNoSave[i])
                    ++bad;
            const int wantPsDetectChance[] = {
                80, 65, 40, 15,
            };
            for (int i = 0; i < 4; ++i)
                if (rules::poisonDetectChance(1, i)
                    != wantPsDetectChance[i])
                    ++bad;
            if (rules::poisonDamageIfSave(1, 0) != 0)
                ++bad;
            if (rules::poisonDamageIfSave(1, 1) != 0)
                ++bad;
            if (rules::poisonDamageIfSave(1, 2) != 0)
                ++bad;
            if (rules::poisonDamageIfSave(1, 3) != 0)
                ++bad;
        }
        printf("R1052 insinuative poisons audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 5. seam ---------------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/dm_poison");
            {
                const items::MiscItemDef* d =
                    reg.find("dm_poison_ingestive");
                if (!d) ++bad;
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "cost_per_dose")
                            continue;
                        got = 1;
                        for (int i = 0; i < 5;
                             ++i)
                            if ((int)t.values[i] !=
                                rules::poisonCostPerDose(0, i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "onset_min")
                            continue;
                        got = 1;
                        for (int i = 0; i < 5;
                             ++i)
                            if ((int)t.values[i] != rules::poisonOnsetMin(0,
                                i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "onset_max")
                            continue;
                        got = 1;
                        for (int i = 0; i < 5;
                             ++i)
                            if ((int)t.values[i] != rules::poisonOnsetMax(0,
                                i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "detect_chance")
                            continue;
                        got = 1;
                        for (int i = 0; i < 5;
                             ++i)
                            if ((int)t.values[i] !=
                                rules::poisonDetectChance(0, i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "damage_if_save")
                            continue;
                        got = 1;
                        for (int i = 0; i < 5;
                             ++i)
                            if ((int)t.values[i] !=
                                rules::poisonDamageIfSave(0, i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "damage_if_no_save")
                            continue;
                        got = 1;
                        for (int i = 0; i < 5;
                             ++i)
                            if (rules::poisonKillsIfNoSave(0, i)) {
                                if (rules::poisonDamageIfNoSave(0, i) != -1)
                                    ++bad;
                            } else {
                                if ((int)t.values[i] !=
                                    rules::poisonDamageIfNoSave(0, i))
                                    ++bad;
                            }
                    }
                    if (!got) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("dm_poison_insinuative");
                if (!d) ++bad;
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "cost_per_dose")
                            continue;
                        got = 1;
                        for (int i = 0; i < 4;
                             ++i)
                            if ((int)t.values[i] !=
                                rules::poisonCostPerDose(1, i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "onset_min")
                            continue;
                        got = 1;
                        for (int i = 0; i < 4;
                             ++i)
                            if ((int)t.values[i] != rules::poisonOnsetMin(1,
                                i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "onset_max")
                            continue;
                        got = 1;
                        for (int i = 0; i < 4;
                             ++i)
                            if ((int)t.values[i] != rules::poisonOnsetMax(1,
                                i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "damage_if_no_save")
                            continue;
                        got = 1;
                        for (int i = 0; i < 4;
                             ++i)
                            if (rules::poisonKillsIfNoSave(1, i)) {
                                if (rules::poisonDamageIfNoSave(1, i) != -1)
                                    ++bad;
                            } else {
                                if ((int)t.values[i] !=
                                    rules::poisonDamageIfNoSave(1, i))
                                    ++bad;
                            }
                    }
                    if (!got) ++bad;
                }
            }
        }
        printf("R1052 poison registry seam audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 6. edges --------------------------------
        {
            if (rules::poisonGradeExists(0, -1))
                ++bad;
            if (rules::poisonGradeExists(0, 5))
                ++bad;
            if (!rules::poisonGradeExists(0, 3))
                ++bad;
            if (rules::poisonGradeExists(1, -1))
                ++bad;
            if (rules::poisonGradeExists(1, 5))
                ++bad;
            if (rules::poisonGradeExists(1, 4))
                ++bad;
            if (!rules::poisonGradeExists(0, 0))
                ++bad;
            if (!rules::poisonGradeExists(1, 0))
                ++bad;
            if (rules::poisonOnsetUnit(0, 0)
                != rules::POISON_UNIT_ROUND) ++bad;
            if (rules::poisonOnsetUnit(0, 1)
                != rules::POISON_UNIT_ROUND) ++bad;
            if (rules::poisonOnsetUnit(0, 2)
                != rules::POISON_UNIT_ROUND) ++bad;
            if (rules::poisonOnsetUnit(0, 3)
                != rules::POISON_UNIT_SEGMENT) ++bad;
            if (rules::poisonOnsetUnit(0, 4)
                != rules::POISON_UNIT_TURN) ++bad;
            if (rules::poisonOnsetUnit(1, 0)
                != rules::POISON_UNIT_ROUND) ++bad;
            if (rules::poisonOnsetUnit(1, 1)
                != rules::POISON_UNIT_ROUND) ++bad;
            if (rules::poisonOnsetUnit(1, 2)
                != rules::POISON_UNIT_ROUND) ++bad;
            if (rules::poisonOnsetUnit(1, 3)
                != rules::POISON_UNIT_ROUND) ++bad;
            if (rules::poisonVictimSaveBonus(0, 0) != 4)
                ++bad;
            if (rules::poisonVictimSaveBonus(0, 1) != 3)
                ++bad;
            if (rules::poisonVictimSaveBonus(0, 2) != 2)
                ++bad;
            if (rules::poisonVictimSaveBonus(0, 3) != 1)
                ++bad;
            if (rules::poisonVictimSaveBonus(0, 4) != 0)
                ++bad;
            if (rules::poisonVictimSaveBonus(1, 0) != 4)
                ++bad;
            if (rules::poisonVictimSaveBonus(1, 1) != 3)
                ++bad;
            if (rules::poisonVictimSaveBonus(1, 2) != 2)
                ++bad;
            if (rules::poisonVictimSaveBonus(1, 3) != 1)
                ++bad;
            if (rules::poisonKillsIfNoSave(0, 0))
                ++bad;
            if (rules::poisonKillsIfNoSave(0, 1))
                ++bad;
            if (rules::poisonKillsIfNoSave(0, 2))
                ++bad;
            if (!rules::poisonKillsIfNoSave(0, 3))
                ++bad;
            if (!rules::poisonKillsIfNoSave(0, 4))
                ++bad;
            if (rules::poisonKillsIfNoSave(1, 0))
                ++bad;
            if (rules::poisonKillsIfNoSave(1, 1))
                ++bad;
            if (rules::poisonKillsIfNoSave(1, 2))
                ++bad;
            if (!rules::poisonKillsIfNoSave(1, 3))
                ++bad;
            if (rules::poisonUserEfficiencyAdj(true, true) != 0)
                ++bad;
            if (rules::poisonUserEfficiencyAdj(true, false) != 1)
                ++bad;
            if (rules::poisonUserEfficiencyAdj(false, false) != 2)
                ++bad;
            if (!rules::poisonMonsterAllOrNothing()) ++bad;
            if (!rules::poisonMonsterDualUse()) ++bad;
            if (rules::poisonBladeVenomPotencyPercent(0) != 100)
                ++bad;
            if (rules::poisonBladeVenomPotencyPercent(1) != 50)
                ++bad;
            if (rules::poisonBladeVenomPotencyPercent(2) != 0)
                ++bad;
            if (rules::poisonBladeVenomDecayedGivesSaveBonus(0)) ++bad;
            if (!rules::poisonBladeVenomDecayedGivesSaveBonus(1)) ++bad;
        }
        printf("R1052 poison registry edges audit: bad %d\n", bad);
    }
