    // ==== R1049: UA subrace level registry =================================
    // The R1049 de-wire: the 101 ladder arrays, the 47
    // RaceLevelColumn descriptors and the 19 gate
    // lists of rules/ua/subracelevels.h ride
    // items::MiscItemRegistry from content/tables/
    // ua_levels/ (the six sub-tables ua_table2_a..f plus
    // ua_level_gates). Six sections: load, counts, bands,
    // data, rows, edges. Census 1052 -> 1058. DO NOT
    // hand-edit: tools/r1049_splice.py is the only writer.
    {
        int bad = 0;
        // -- 1. load ---------------------------------
        {
            items::MiscItemRegistry reg;
            int n = reg.loadDirectory(
                "content/tables/ua_levels");
            if (n != 7) ++bad;
            if (!reg.errors().empty()) ++bad;
            for (const auto& kv : reg.all())
                if ((int)kv.second.sources
                    .size() != 1)
                    ++bad;
        }
        printf("R1049 subrace level registry load audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 2. counts ---------------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/ua_levels");
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_a");
                if (!d) { ++bad; } else {
                    for (const auto& r :
                             d->rows)
                        if (r.set != d->key)
                            ++bad;
                    if ((int)d->rows.size() != 41
                        || (int)d->pins.size() != 2
                        || d->pins[0].value != 41
                        || d->pins[1].value != 5
                        || (int)d->tables.size() != 0)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_b");
                if (!d) { ++bad; } else {
                    for (const auto& r :
                             d->rows)
                        if (r.set != d->key)
                            ++bad;
                    if ((int)d->rows.size() != 41
                        || (int)d->pins.size() != 2
                        || d->pins[0].value != 41
                        || d->pins[1].value != 5
                        || (int)d->tables.size() != 0)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    for (const auto& r :
                             d->rows)
                        if (r.set != d->key)
                            ++bad;
                    if ((int)d->rows.size() != 184
                        || (int)d->pins.size() != 2
                        || d->pins[0].value != 184
                        || d->pins[1].value != 20
                        || (int)d->tables.size() != 0)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_d");
                if (!d) { ++bad; } else {
                    for (const auto& r :
                             d->rows)
                        if (r.set != d->key)
                            ++bad;
                    if ((int)d->rows.size() != 51
                        || (int)d->pins.size() != 2
                        || d->pins[0].value != 51
                        || d->pins[1].value != 7
                        || (int)d->tables.size() != 0)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_e");
                if (!d) { ++bad; } else {
                    for (const auto& r :
                             d->rows)
                        if (r.set != d->key)
                            ++bad;
                    if ((int)d->rows.size() != 42
                        || (int)d->pins.size() != 2
                        || d->pins[0].value != 42
                        || d->pins[1].value != 6
                        || (int)d->tables.size() != 0)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_f");
                if (!d) { ++bad; } else {
                    for (const auto& r :
                             d->rows)
                        if (r.set != d->key)
                            ++bad;
                    if ((int)d->rows.size() != 34
                        || (int)d->pins.size() != 2
                        || d->pins[0].value != 34
                        || d->pins[1].value != 4
                        || (int)d->tables.size() != 0)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_level_gates");
                if (!d) { ++bad; } else {
                    for (const auto& r :
                             d->rows)
                        if (r.set != d->key)
                            ++bad;
                    if ((int)d->rows.size() != 33
                        || (int)d->pins.size() != 3
                        || d->pins[0].value != 33
                        || d->pins[1].value != 19
                        || d->pins[2].value != 2
                        || (int)d->tables.size() != 0)
                        ++bad;
                }
            }
        }
        printf("R1049 subrace level registry counts audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 3. bands ---------------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/ua_levels");
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_a");
                if (!d) { ++bad; } else {
                    int prevLo = 15000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iia_assassin") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 9
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_a");
                if (!d) { ++bad; } else {
                    int prevLo = 15000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iia_cleric") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 7
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_a");
                if (!d) { ++bad; } else {
                    int prevLo = 15000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iia_fighter_hill") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 9
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_a");
                if (!d) { ++bad; } else {
                    int prevLo = 15000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iia_fighter_m_g") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 9
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_a");
                if (!d) { ++bad; } else {
                    int prevLo = 15000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iia_thief") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 7
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_b");
                if (!d) { ++bad; } else {
                    int prevLo = 15000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iib_assassin") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 10
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_b");
                if (!d) { ++bad; } else {
                    int prevLo = 15000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iib_cleric") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 7
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_b");
                if (!d) { ++bad; } else {
                    int prevLo = 15000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iib_fighter") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 10
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_b");
                if (!d) { ++bad; } else {
                    int prevLo = 15000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iib_illusionist") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 7
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_b");
                if (!d) { ++bad; } else {
                    int prevLo = 15000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iib_thief") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 7
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int prevLo = 18000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iic_assassin") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 8
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int prevLo = 12000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iic_cleric_a_o") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 10
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int prevLo = 12000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iic_cleric_d_f") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 10
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int prevLo = 12000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iic_cleric_d_m") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 10
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int prevLo = 12000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iic_druid_a_o") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 10
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int prevLo = 12000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iic_druid_wild") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 10
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int prevLo = 12000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iic_fighter_d_f") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 13
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int prevLo = 12000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iic_fighter_d_m") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 13
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int prevLo = 12000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iic_fighter_g_h") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 13
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int prevLo = 12000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iic_fighter_va") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 13
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int prevLo = 12000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iic_fighter_wi") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 13
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int prevLo = 12000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iic_fighter_wo") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 13
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int prevLo = 17000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iic_mu_d_f") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 6
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int prevLo = 17000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iic_mu_d_m") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 6
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int prevLo = 17000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iic_mu_gray") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 6
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int prevLo = 17000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iic_mu_high") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 6
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int prevLo = 17000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iic_mu_val") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 6
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int prevLo = 17000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iic_mu_wood") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 6
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int prevLo = 18000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iic_ranger") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 8
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int prevLo = 17000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iic_thief") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 4
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_d");
                if (!d) { ++bad; } else {
                    int prevLo = 15000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iid_assassin") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 9
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_d");
                if (!d) { ++bad; } else {
                    int prevLo = 15000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iid_cleric") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 6
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_d");
                if (!d) { ++bad; } else {
                    int prevLo = 15000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iid_druid") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 6
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_d");
                if (!d) { ++bad; } else {
                    int prevLo = 15000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iid_fighter") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 9
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_d");
                if (!d) { ++bad; } else {
                    int prevLo = 15000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iid_m_u") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 6
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_d");
                if (!d) { ++bad; } else {
                    int prevLo = 15000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iid_ranger") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 9
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_d");
                if (!d) { ++bad; } else {
                    int prevLo = 15000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iid_thief") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 6
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_e");
                if (!d) { ++bad; } else {
                    int prevLo = 15000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iie_cleric") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 6
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_e");
                if (!d) { ++bad; } else {
                    int prevLo = 15000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iie_druid") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 6
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_e");
                if (!d) { ++bad; } else {
                    int prevLo = 15000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iie_fighter_h_f") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 8
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_e");
                if (!d) { ++bad; } else {
                    int prevLo = 15000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iie_fighter_st") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 8
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_e");
                if (!d) { ++bad; } else {
                    int prevLo = 15000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iie_fighter_t_f") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 8
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_e");
                if (!d) { ++bad; } else {
                    int prevLo = 15000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iie_thief") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 6
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_f");
                if (!d) { ++bad; } else {
                    int prevLo = 14000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iif_assassin") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 8
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_f");
                if (!d) { ++bad; } else {
                    int prevLo = 14000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iif_cleric") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 8
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_f");
                if (!d) { ++bad; } else {
                    int prevLo = 14000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iif_fighter") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 10
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_f");
                if (!d) { ++bad; } else {
                    int prevLo = 14000;
                    int lastHi = 0;
                    int count = 0;
                    for (const auto& r :
                             d->rows)
                        if (r.name == "iif_thief") {
                            ++count;
                            if (r.bandLo != prevLo
                                || r.gpHi != 0
                                || r.gp < 0
                                || r.gp > 29
                                || r.xp < 0
                                || r.xp > 6)
                                ++bad;
                            prevLo = r.bandHi + 1;
                            lastHi = r.bandHi;
                        }
                    if (count != 8
                        || lastHi != 999999)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_level_gates");
                if (!d) { ++bad; } else {
                    for (const auto& r : d->rows)
                        if (r.bandLo < 0
                            || r.bandLo >= 6
                            || r.bandHi < 15
                            || r.bandHi > 19
                            || (r.gp != 0
                                && r.gp != 1)
                            || r.xp != 0)
                            ++bad;
                    int orm = 0;
                    for (const auto& r : d->rows)
                        if (r.gp == 1) ++orm;
                    if (orm != 2) ++bad;
                }
            }
        }
        printf("R1049 subrace level registry bands audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 4. data ---------------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/ua_levels");
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_a");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        15000, 16000, 17000, 18000, 18990, 18999, 19000,
                        20000, 21000};
                    const int wantHi[] = {
                        15999, 16999, 17999, 18989, 18998, 18999, 19999,
                        20999, 999999};
                    const int wantLvl[] = {
                        9, 9, 9, 9, 11, 12, 12, 12, 12};
                    const int wantFn[] = {
                        0, 0, 0, 0, 1, 2, 2, 2, 2};
                    for (int i = 0; i < 9; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iia_assassin"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iia_assassin")
                            ++matches;
                    if (matches != 9) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_a");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        15000, 16000, 17000, 18000, 19000, 20000, 21000};
                    const int wantHi[] = {
                        15999, 16999, 17999, 18999, 19999, 20999, 999999};
                    const int wantLvl[] = {
                        8, 9, 10, 11, 13, 16, 16};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 7; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iia_cleric"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iia_cleric")
                            ++matches;
                    if (matches != 7) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_a");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        15000, 16000, 17000, 18000, 18990, 18999, 19000,
                        20000, 21000};
                    const int wantHi[] = {
                        15999, 16999, 17999, 18989, 18998, 18999, 19999,
                        20999, 999999};
                    const int wantLvl[] = {
                        6, 6, 7, 8, 8, 9, 10, 12, 15};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 9; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iia_fighter_hill"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iia_fighter_hill")
                            ++matches;
                    if (matches != 9) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_a");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        15000, 16000, 17000, 18000, 18990, 18999, 19000,
                        20000, 21000};
                    const int wantHi[] = {
                        15999, 16999, 17999, 18989, 18998, 18999, 19999,
                        20999, 999999};
                    const int wantLvl[] = {
                        7, 7, 8, 9, 9, 10, 11, 13, 16};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 9; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iia_fighter_m_g"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iia_fighter_m_g")
                            ++matches;
                    if (matches != 9) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_a");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        15000, 16000, 17000, 18000, 19000, 20000, 21000};
                    const int wantHi[] = {
                        15999, 16999, 17999, 18999, 19999, 20999, 999999};
                    const int wantLvl[] = {
                        0, 0, 0, 0, 0, 0, 0};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 7; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iia_thief"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iia_thief")
                            ++matches;
                    if (matches != 7) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_b");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        15000, 16000, 17000, 18000, 18500, 18750, 18990,
                        19000, 20000, 21000};
                    const int wantHi[] = {
                        15999, 16999, 17999, 18499, 18749, 18989, 18999,
                        19999, 20999, 999999};
                    const int wantLvl[] = {
                        8, 8, 8, 8, 9, 10, 10, 10, 10, 10};
                    const int wantFn[] = {
                        0, 0, 0, 0, 1, 2, 2, 2, 2, 2};
                    for (int i = 0; i < 10; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iib_assassin"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iib_assassin")
                            ++matches;
                    if (matches != 10) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_b");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        15000, 16000, 17000, 18000, 19000, 20000, 21000};
                    const int wantHi[] = {
                        15999, 16999, 17999, 18999, 19999, 20999, 999999};
                    const int wantLvl[] = {
                        7, 8, 9, 10, 12, 14, 14};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 7; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iib_cleric"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iib_cleric")
                            ++matches;
                    if (matches != 7) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_b");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        15000, 16000, 17000, 18000, 18500, 18750, 18990,
                        19000, 20000, 21000};
                    const int wantHi[] = {
                        15999, 16999, 17999, 18499, 18749, 18989, 18999,
                        19999, 20999, 999999};
                    const int wantLvl[] = {
                        5, 5, 5, 5, 6, 7, 8, 9, 9, 9};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 10; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iib_fighter"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iib_fighter")
                            ++matches;
                    if (matches != 10) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_b");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        15000, 16000, 17000, 18000, 19000, 20000, 21000};
                    const int wantHi[] = {
                        15999, 16999, 17999, 18999, 19999, 20999, 999999};
                    const int wantLvl[] = {
                        6, 6, 6, 7, 8, 10, 13};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 7; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iib_illusionist"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iib_illusionist")
                            ++matches;
                    if (matches != 7) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_b");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        15000, 16000, 17000, 18000, 19000, 20000, 21000};
                    const int wantHi[] = {
                        15999, 16999, 17999, 18999, 19999, 20999, 999999};
                    const int wantLvl[] = {
                        0, 0, 0, 0, 0, 0, 0};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 7; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iib_thief"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iib_thief")
                            ++matches;
                    if (matches != 7) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        18000, 18010, 18510, 18760, 18990, 18999, 19000,
                        20000};
                    const int wantHi[] = {
                        18009, 18509, 18759, 18989, 18998, 18999, 19999,
                        999999};
                    const int wantLvl[] = {
                        10, 10, 10, 10, 11, 12, 12, 12};
                    const int wantFn[] = {
                        0, 0, 0, 0, 3, 3, 4, 5};
                    for (int i = 0; i < 8; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iic_assassin"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iic_assassin")
                            ++matches;
                    if (matches != 8) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        12000, 13000, 14000, 15000, 16000, 17000, 18000,
                        19000, 20000, 21000};
                    const int wantHi[] = {
                        12999, 13999, 14999, 15999, 16999, 17999, 18999,
                        19999, 20999, 999999};
                    const int wantLvl[] = {
                        7, 7, 7, 7, 8, 9, 10, 11, 12, 12};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 10; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iic_cleric_a_o"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iic_cleric_a_o")
                            ++matches;
                    if (matches != 10) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        12000, 13000, 14000, 15000, 16000, 17000, 18000,
                        19000, 20000, 21000};
                    const int wantHi[] = {
                        12999, 13999, 14999, 15999, 16999, 17999, 18999,
                        19999, 20999, 999999};
                    const int wantLvl[] = {
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 10; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iic_cleric_d_f"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iic_cleric_d_f")
                            ++matches;
                    if (matches != 10) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        12000, 13000, 14000, 15000, 16000, 17000, 18000,
                        19000, 20000, 21000};
                    const int wantHi[] = {
                        12999, 13999, 14999, 15999, 16999, 17999, 18999,
                        19999, 20999, 999999};
                    const int wantLvl[] = {
                        4, 5, 6, 7, 7, 7, 7, 7, 7, 7};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 10; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iic_cleric_d_m"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iic_cleric_d_m")
                            ++matches;
                    if (matches != 10) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        12000, 13000, 14000, 15000, 16000, 17000, 18000,
                        19000, 20000, 21000};
                    const int wantHi[] = {
                        12999, 13999, 14999, 15999, 16999, 17999, 18999,
                        19999, 20999, 999999};
                    const int wantLvl[] = {
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 10; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iic_druid_a_o"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iic_druid_a_o")
                            ++matches;
                    if (matches != 10) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        12000, 13000, 14000, 15000, 16000, 17000, 18000,
                        19000, 20000, 21000};
                    const int wantHi[] = {
                        12999, 13999, 14999, 15999, 16999, 17999, 18999,
                        19999, 20999, 999999};
                    const int wantLvl[] = {
                        10, 10, 10, 10, 10, 10, 11, 12, 14, 17};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0, 1, 1, 1, 2};
                    for (int i = 0; i < 10; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iic_druid_wild"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iic_druid_wild")
                            ++matches;
                    if (matches != 10) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        12000, 13000, 14000, 15000, 16000, 17000, 18000,
                        18750, 18900, 18990, 18999, 19000, 20000};
                    const int wantHi[] = {
                        12999, 13999, 14999, 15999, 16999, 17999, 18749,
                        18899, 18989, 18998, 18999, 19999, 999999};
                    const int wantLvl[] = {
                        9, 10, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 13; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iic_fighter_d_f"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iic_fighter_d_f")
                            ++matches;
                    if (matches != 13) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        12000, 13000, 14000, 15000, 16000, 17000, 18000,
                        18750, 18900, 18990, 18999, 19000, 20000};
                    const int wantHi[] = {
                        12999, 13999, 14999, 15999, 16999, 17999, 18749,
                        18899, 18989, 18998, 18999, 19999, 999999};
                    const int wantLvl[] = {
                        7, 8, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 13; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iic_fighter_d_m"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iic_fighter_d_m")
                            ++matches;
                    if (matches != 13) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        12000, 13000, 14000, 15000, 16000, 17000, 18000,
                        18750, 18900, 18990, 18999, 19000, 20000};
                    const int wantHi[] = {
                        12999, 13999, 14999, 15999, 16999, 17999, 18749,
                        18899, 18989, 18998, 18999, 19999, 999999};
                    const int wantLvl[] = {
                        5, 5, 5, 5, 5, 5, 6, 7, 8, 9, 10, 11, 11};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 13; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iic_fighter_g_h"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iic_fighter_g_h")
                            ++matches;
                    if (matches != 13) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        12000, 13000, 14000, 15000, 16000, 17000, 18000,
                        18750, 18900, 18990, 18999, 19000, 20000};
                    const int wantHi[] = {
                        12999, 13999, 14999, 15999, 16999, 17999, 18749,
                        18899, 18989, 18998, 18999, 19999, 999999};
                    const int wantLvl[] = {
                        5, 5, 5, 5, 5, 5, 6, 6, 8, 9, 10, 11, 13};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 13; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iic_fighter_va"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iic_fighter_va")
                            ++matches;
                    if (matches != 13) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        12000, 13000, 14000, 15000, 16000, 17000, 18000,
                        18750, 18900, 18990, 18999, 19000, 20000};
                    const int wantHi[] = {
                        12999, 13999, 14999, 15999, 16999, 17999, 18749,
                        18899, 18989, 18998, 18999, 19999, 999999};
                    const int wantLvl[] = {
                        7, 7, 7, 7, 7, 7, 8, 8, 10, 11, 12, 13, 13};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 13; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iic_fighter_wi"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iic_fighter_wi")
                            ++matches;
                    if (matches != 13) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        12000, 13000, 14000, 15000, 16000, 17000, 18000,
                        18750, 18900, 18990, 18999, 19000, 20000};
                    const int wantHi[] = {
                        12999, 13999, 14999, 15999, 16999, 17999, 18749,
                        18899, 18989, 18998, 18999, 19999, 999999};
                    const int wantLvl[] = {
                        6, 6, 6, 6, 6, 6, 7, 8, 9, 10, 11, 11, 14};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 13; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iic_fighter_wo"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iic_fighter_wo")
                            ++matches;
                    if (matches != 13) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        17000, 18000, 19000, 20000, 21000, 22000};
                    const int wantHi[] = {
                        17999, 18999, 19999, 20999, 21999, 999999};
                    const int wantLvl[] = {
                        5, 5, 7, 9, 11, 11};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 6; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iic_mu_d_f"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iic_mu_d_f")
                            ++matches;
                    if (matches != 6) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        17000, 18000, 19000, 20000, 21000, 22000};
                    const int wantHi[] = {
                        17999, 18999, 19999, 20999, 21999, 999999};
                    const int wantLvl[] = {
                        12, 12, 13, 15, 18, 18};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 6; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iic_mu_d_m"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iic_mu_d_m")
                            ++matches;
                    if (matches != 6) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        17000, 18000, 19000, 20000, 21000, 22000};
                    const int wantHi[] = {
                        17999, 18999, 19999, 20999, 21999, 999999};
                    const int wantLvl[] = {
                        11, 11, 12, 13, 15, 18};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 6; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iic_mu_gray"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iic_mu_gray")
                            ++matches;
                    if (matches != 6) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        17000, 18000, 19000, 20000, 21000, 22000};
                    const int wantHi[] = {
                        17999, 18999, 19999, 20999, 21999, 999999};
                    const int wantLvl[] = {
                        10, 10, 11, 12, 14, 17};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 6; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iic_mu_high"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iic_mu_high")
                            ++matches;
                    if (matches != 6) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        17000, 18000, 19000, 20000, 21000, 22000};
                    const int wantHi[] = {
                        17999, 18999, 19999, 20999, 21999, 999999};
                    const int wantLvl[] = {
                        11, 11, 12, 13, 15, 15};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 6; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iic_mu_val"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iic_mu_val")
                            ++matches;
                    if (matches != 6) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        17000, 18000, 19000, 20000, 21000, 22000};
                    const int wantHi[] = {
                        17999, 18999, 19999, 20999, 21999, 999999};
                    const int wantLvl[] = {
                        9, 9, 10, 11, 13, 13};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 6; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iic_mu_wood"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iic_mu_wood")
                            ++matches;
                    if (matches != 6) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        18000, 18010, 18510, 18760, 18990, 18999, 19000,
                        20000};
                    const int wantHi[] = {
                        18009, 18509, 18759, 18989, 18998, 18999, 19999,
                        999999};
                    const int wantLvl[] = {
                        6, 7, 9, 10, 10, 10, 12, 14};
                    const int wantFn[] = {
                        0, 1, 2, 3, 3, 3, 4, 4};
                    for (int i = 0; i < 8; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iic_ranger"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iic_ranger")
                            ++matches;
                    if (matches != 8) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_c");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        17000, 18000, 19000, 20000};
                    const int wantHi[] = {
                        17999, 18999, 19999, 999999};
                    const int wantLvl[] = {
                        0, 0, 0, 0};
                    const int wantFn[] = {
                        0, 0, 0, 0};
                    for (int i = 0; i < 4; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iic_thief"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iic_thief")
                            ++matches;
                    if (matches != 4) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_d");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        15000, 16000, 17000, 18000, 18900, 18990, 18999,
                        19000, 20000};
                    const int wantHi[] = {
                        15999, 16999, 17999, 18899, 18989, 18998, 18999,
                        19999, 999999};
                    const int wantLvl[] = {
                        11, 11, 11, 11, 11, 11, 11, 11, 11};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 9; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iid_assassin"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iid_assassin")
                            ++matches;
                    if (matches != 9) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_d");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        15000, 16000, 17000, 18000, 19000, 20000};
                    const int wantHi[] = {
                        15999, 16999, 17999, 18999, 19999, 999999};
                    const int wantLvl[] = {
                        5, 6, 7, 8, 10, 12};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 6; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iid_cleric"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iid_cleric")
                            ++matches;
                    if (matches != 6) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_d");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        15000, 16000, 17000, 18000, 19000, 20000};
                    const int wantHi[] = {
                        15999, 16999, 17999, 18999, 19999, 999999};
                    const int wantLvl[] = {
                        0, 0, 0, 0, 0, 0};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 6; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iid_druid"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iid_druid")
                            ++matches;
                    if (matches != 6) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_d");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        15000, 16000, 17000, 18000, 18900, 18990, 18999,
                        19000, 20000};
                    const int wantHi[] = {
                        15999, 16999, 17999, 18899, 18989, 18998, 18999,
                        19999, 999999};
                    const int wantLvl[] = {
                        6, 6, 7, 7, 8, 9, 10, 11, 13};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 9; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iid_fighter"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iid_fighter")
                            ++matches;
                    if (matches != 9) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_d");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        15000, 16000, 17000, 18000, 19000, 20000};
                    const int wantHi[] = {
                        15999, 16999, 17999, 18999, 19999, 999999};
                    const int wantLvl[] = {
                        7, 7, 7, 8, 8, 8};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 6; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iid_m_u"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iid_m_u")
                            ++matches;
                    if (matches != 6) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_d");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        15000, 16000, 17000, 18000, 18900, 18990, 18999,
                        19000, 20000};
                    const int wantHi[] = {
                        15999, 16999, 17999, 18899, 18989, 18998, 18999,
                        19999, 999999};
                    const int wantLvl[] = {
                        6, 6, 7, 8, 9, 10, 11, 15, 15};
                    const int wantFn[] = {
                        0, 0, 0, 0, 1, 1, 2, 3, 3};
                    for (int i = 0; i < 9; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iid_ranger"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iid_ranger")
                            ++matches;
                    if (matches != 9) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_d");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        15000, 16000, 17000, 18000, 19000, 20000};
                    const int wantHi[] = {
                        15999, 16999, 17999, 18999, 19999, 999999};
                    const int wantLvl[] = {
                        0, 0, 0, 0, 0, 0};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 6; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iid_thief"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iid_thief")
                            ++matches;
                    if (matches != 6) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_e");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        15000, 16000, 17000, 18000, 19000, 20000};
                    const int wantHi[] = {
                        15999, 16999, 17999, 18999, 19999, 999999};
                    const int wantLvl[] = {
                        4, 4, 5, 6, 8, 10};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 6; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iie_cleric"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iie_cleric")
                            ++matches;
                    if (matches != 6) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_e");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        15000, 16000, 17000, 18000, 19000, 20000};
                    const int wantHi[] = {
                        15999, 16999, 17999, 18999, 19999, 999999};
                    const int wantLvl[] = {
                        6, 7, 9, 11, 13, 13};
                    const int wantFn[] = {
                        1, 2, 3, 4, 5, 5};
                    for (int i = 0; i < 6; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iie_druid"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iie_druid")
                            ++matches;
                    if (matches != 6) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_e");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        15000, 16000, 17000, 18000, 18500, 18900, 19000,
                        20000};
                    const int wantHi[] = {
                        15999, 16999, 17999, 18499, 18899, 18999, 19999,
                        999999};
                    const int wantLvl[] = {
                        4, 4, 5, 5, 6, 7, 8, 8};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 8; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iie_fighter_h_f"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iie_fighter_h_f")
                            ++matches;
                    if (matches != 8) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_e");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        15000, 16000, 17000, 18000, 18500, 18900, 19000,
                        20000};
                    const int wantHi[] = {
                        15999, 16999, 17999, 18499, 18899, 18999, 19999,
                        999999};
                    const int wantLvl[] = {
                        5, 5, 6, 6, 7, 8, 9, 9};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 8; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iie_fighter_st"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iie_fighter_st")
                            ++matches;
                    if (matches != 8) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_e");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        15000, 16000, 17000, 18000, 18500, 18900, 19000,
                        20000};
                    const int wantHi[] = {
                        15999, 16999, 17999, 18499, 18899, 18999, 19999,
                        999999};
                    const int wantLvl[] = {
                        6, 6, 7, 7, 8, 9, 10, 10};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 8; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iie_fighter_t_f"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iie_fighter_t_f")
                            ++matches;
                    if (matches != 8) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_e");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        15000, 16000, 17000, 18000, 19000, 20000};
                    const int wantHi[] = {
                        15999, 16999, 17999, 18999, 19999, 999999};
                    const int wantLvl[] = {
                        0, 0, 0, 0, 0, 0};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 6; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iie_thief"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iie_thief")
                            ++matches;
                    if (matches != 6) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_f");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        14000, 15000, 16000, 17000, 18000, 19000, 20000,
                        21000};
                    const int wantHi[] = {
                        14999, 15999, 16999, 17999, 18999, 19999, 20999,
                        999999};
                    const int wantLvl[] = {
                        0, 0, 0, 0, 0, 0, 0, 0};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 8; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iif_assassin"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iif_assassin")
                            ++matches;
                    if (matches != 8) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_f");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        14000, 15000, 16000, 17000, 18000, 19000, 20000,
                        21000};
                    const int wantHi[] = {
                        14999, 15999, 16999, 17999, 18999, 19999, 20999,
                        999999};
                    const int wantLvl[] = {
                        4, 5, 6, 7, 7, 7, 7, 7};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 8; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iif_cleric"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iif_cleric")
                            ++matches;
                    if (matches != 8) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_f");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        14000, 15000, 16000, 17000, 18000, 18990, 18999,
                        19000, 20000, 21000};
                    const int wantHi[] = {
                        14999, 15999, 16999, 17999, 18989, 18998, 18999,
                        19999, 20999, 999999};
                    const int wantLvl[] = {
                        10, 10, 10, 10, 10, 10, 11, 12, 14, 17};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 10; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iif_fighter"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iif_fighter")
                            ++matches;
                    if (matches != 10) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_table2_f");
                if (!d) { ++bad; } else {
                    int matches = 0;
                    const int wantLo[] = {
                        14000, 15000, 16000, 17000, 18000, 19000, 20000,
                        21000};
                    const int wantHi[] = {
                        14999, 15999, 16999, 17999, 18999, 19999, 20999,
                        999999};
                    const int wantLvl[] = {
                        8, 9, 10, 11, 11, 11, 11, 11};
                    const int wantFn[] = {
                        0, 0, 0, 0, 0, 0, 0, 0};
                    for (int i = 0; i < 8; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 d->rows)
                            if (r.name == "iif_thief"
                                && r.bandLo ==
                                   wantLo[i])
                                rr = &r;
                        if (!rr
                            || rr->bandHi !=
                               wantHi[i]
                            || rr->gp !=
                               wantLvl[i]
                            || rr->xp !=
                               wantFn[i])
                            ++bad;
                    }
                    for (const auto& r : d->rows)
                        if (r.name == "iif_thief")
                            ++matches;
                    if (matches != 8) ++bad;
                }
            }
            const items::MiscItemDef* dg =
                reg.find("ua_level_gates");
            if (!dg) { ++bad; } else {
                {
                    int matches = 0;
                    const int wantStat[] = {
                        1, 3};
                    const int wantMin[] = {
                        18, 19};
                    for (int i = 0; i < 2; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 dg->rows)
                            if (r.name == "iia_g1"
                                && r.bandLo ==
                                   wantStat[i]
                                && r.bandHi ==
                                   wantMin[i])
                                rr = &r;
                        if (!rr
                            || rr->gp != 0)
                            ++bad;
                    }
                    for (const auto& r : dg->rows)
                        if (r.name == "iia_g1")
                            ++matches;
                    if (matches != 2) ++bad;
                }
                {
                    int matches = 0;
                    const int wantStat[] = {
                        1, 3};
                    const int wantMin[] = {
                        19, 19};
                    for (int i = 0; i < 2; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 dg->rows)
                            if (r.name == "iia_g2"
                                && r.bandLo ==
                                   wantStat[i]
                                && r.bandHi ==
                                   wantMin[i])
                                rr = &r;
                        if (!rr
                            || rr->gp != 0)
                            ++bad;
                    }
                    for (const auto& r : dg->rows)
                        if (r.name == "iia_g2")
                            ++matches;
                    if (matches != 2) ++bad;
                }
                {
                    int matches = 0;
                    const int wantStat[] = {
                        1, 3};
                    const int wantMin[] = {
                        18, 18};
                    for (int i = 0; i < 2; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 dg->rows)
                            if (r.name == "iib_g1"
                                && r.bandLo ==
                                   wantStat[i]
                                && r.bandHi ==
                                   wantMin[i])
                                rr = &r;
                        if (!rr
                            || rr->gp != 0)
                            ++bad;
                    }
                    for (const auto& r : dg->rows)
                        if (r.name == "iib_g1")
                            ++matches;
                    if (matches != 2) ++bad;
                }
                {
                    int matches = 0;
                    const int wantStat[] = {
                        1, 3};
                    const int wantMin[] = {
                        19, 19};
                    for (int i = 0; i < 2; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 dg->rows)
                            if (r.name == "iib_g2"
                                && r.bandLo ==
                                   wantStat[i]
                                && r.bandHi ==
                                   wantMin[i])
                                rr = &r;
                        if (!rr
                            || rr->gp != 0)
                            ++bad;
                    }
                    for (const auto& r : dg->rows)
                        if (r.name == "iib_g2")
                            ++matches;
                    if (matches != 2) ++bad;
                }
                {
                    int matches = 0;
                    const int wantStat[] = {
                        1, 2};
                    const int wantMin[] = {
                        15, 15};
                    for (int i = 0; i < 2; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 dg->rows)
                            if (r.name == "iic_a_g1"
                                && r.bandLo ==
                                   wantStat[i]
                                && r.bandHi ==
                                   wantMin[i])
                                rr = &r;
                        if (!rr
                            || rr->gp != 0)
                            ++bad;
                    }
                    for (const auto& r : dg->rows)
                        if (r.name == "iic_a_g1")
                            ++matches;
                    if (matches != 2) ++bad;
                }
                {
                    int matches = 0;
                    const int wantStat[] = {
                        1, 2};
                    const int wantMin[] = {
                        16, 16};
                    for (int i = 0; i < 2; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 dg->rows)
                            if (r.name == "iic_a_g2"
                                && r.bandLo ==
                                   wantStat[i]
                                && r.bandHi ==
                                   wantMin[i])
                                rr = &r;
                        if (!rr
                            || rr->gp != 0)
                            ++bad;
                    }
                    for (const auto& r : dg->rows)
                        if (r.name == "iic_a_g2")
                            ++matches;
                    if (matches != 2) ++bad;
                }
                {
                    int matches = 0;
                    const int wantStat[] = {
                        1, 2};
                    const int wantMin[] = {
                        17, 17};
                    for (int i = 0; i < 2; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 dg->rows)
                            if (r.name == "iic_a_g3"
                                && r.bandLo ==
                                   wantStat[i]
                                && r.bandHi ==
                                   wantMin[i])
                                rr = &r;
                        if (!rr
                            || rr->gp != 0)
                            ++bad;
                    }
                    for (const auto& r : dg->rows)
                        if (r.name == "iic_a_g3")
                            ++matches;
                    if (matches != 2) ++bad;
                }
                {
                    int matches = 0;
                    const int wantStat[] = {
                        1, 2};
                    const int wantMin[] = {
                        18, 18};
                    for (int i = 0; i < 2; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 dg->rows)
                            if (r.name == "iic_a_g4"
                                && r.bandLo ==
                                   wantStat[i]
                                && r.bandHi ==
                                   wantMin[i])
                                rr = &r;
                        if (!rr
                            || rr->gp != 0)
                            ++bad;
                    }
                    for (const auto& r : dg->rows)
                        if (r.name == "iic_a_g4")
                            ++matches;
                    if (matches != 2) ++bad;
                }
                {
                    int matches = 0;
                    const int wantStat[] = {
                        1, 2};
                    const int wantMin[] = {
                        18, 19};
                    for (int i = 0; i < 2; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 dg->rows)
                            if (r.name == "iic_a_g5"
                                && r.bandLo ==
                                   wantStat[i]
                                && r.bandHi ==
                                   wantMin[i])
                                rr = &r;
                        if (!rr
                            || rr->gp != 0)
                            ++bad;
                    }
                    for (const auto& r : dg->rows)
                        if (r.name == "iic_a_g5")
                            ++matches;
                    if (matches != 2) ++bad;
                }
                {
                    int matches = 0;
                    const int wantStat[] = {
                        1, 2};
                    const int wantMin[] = {
                        19, 19};
                    for (int i = 0; i < 2; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 dg->rows)
                            if (r.name == "iic_a_g6"
                                && r.bandLo ==
                                   wantStat[i]
                                && r.bandHi ==
                                   wantMin[i])
                                rr = &r;
                        if (!rr
                            || rr->gp != 1)
                            ++bad;
                    }
                    for (const auto& r : dg->rows)
                        if (r.name == "iic_a_g6")
                            ++matches;
                    if (matches != 2) ++bad;
                }
                {
                    int matches = 0;
                    const int wantStat[] = {
                        5};
                    const int wantMin[] = {
                        18};
                    for (int i = 0; i < 1; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 dg->rows)
                            if (r.name == "iic_d_g1"
                                && r.bandLo ==
                                   wantStat[i]
                                && r.bandHi ==
                                   wantMin[i])
                                rr = &r;
                        if (!rr
                            || rr->gp != 0)
                            ++bad;
                    }
                    for (const auto& r : dg->rows)
                        if (r.name == "iic_d_g1")
                            ++matches;
                    if (matches != 1) ++bad;
                }
                {
                    int matches = 0;
                    const int wantStat[] = {
                        5};
                    const int wantMin[] = {
                        19};
                    for (int i = 0; i < 1; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 dg->rows)
                            if (r.name == "iic_d_g2"
                                && r.bandLo ==
                                   wantStat[i]
                                && r.bandHi ==
                                   wantMin[i])
                                rr = &r;
                        if (!rr
                            || rr->gp != 0)
                            ++bad;
                    }
                    for (const auto& r : dg->rows)
                        if (r.name == "iic_d_g2")
                            ++matches;
                    if (matches != 1) ++bad;
                }
                {
                    int matches = 0;
                    const int wantStat[] = {
                        1, 2, 4};
                    const int wantMin[] = {
                        18, 18, 18};
                    for (int i = 0; i < 3; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 dg->rows)
                            if (r.name == "iid_g1"
                                && r.bandLo ==
                                   wantStat[i]
                                && r.bandHi ==
                                   wantMin[i])
                                rr = &r;
                        if (!rr
                            || rr->gp != 0)
                            ++bad;
                    }
                    for (const auto& r : dg->rows)
                        if (r.name == "iid_g1")
                            ++matches;
                    if (matches != 3) ++bad;
                }
                {
                    int matches = 0;
                    const int wantStat[] = {
                        1, 2, 4};
                    const int wantMin[] = {
                        19, 19, 19};
                    for (int i = 0; i < 3; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 dg->rows)
                            if (r.name == "iid_g3"
                                && r.bandLo ==
                                   wantStat[i]
                                && r.bandHi ==
                                   wantMin[i])
                                rr = &r;
                        if (!rr
                            || rr->gp != 0)
                            ++bad;
                    }
                    for (const auto& r : dg->rows)
                        if (r.name == "iid_g3")
                            ++matches;
                    if (matches != 3) ++bad;
                }
                {
                    int matches = 0;
                    const int wantStat[] = {
                        5};
                    const int wantMin[] = {
                        15};
                    for (int i = 0; i < 1; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 dg->rows)
                            if (r.name == "iie_g1"
                                && r.bandLo ==
                                   wantStat[i]
                                && r.bandHi ==
                                   wantMin[i])
                                rr = &r;
                        if (!rr
                            || rr->gp != 0)
                            ++bad;
                    }
                    for (const auto& r : dg->rows)
                        if (r.name == "iie_g1")
                            ++matches;
                    if (matches != 1) ++bad;
                }
                {
                    int matches = 0;
                    const int wantStat[] = {
                        5};
                    const int wantMin[] = {
                        15};
                    for (int i = 0; i < 1; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 dg->rows)
                            if (r.name == "iie_g2"
                                && r.bandLo ==
                                   wantStat[i]
                                && r.bandHi ==
                                   wantMin[i])
                                rr = &r;
                        if (!rr
                            || rr->gp != 0)
                            ++bad;
                    }
                    for (const auto& r : dg->rows)
                        if (r.name == "iie_g2")
                            ++matches;
                    if (matches != 1) ++bad;
                }
                {
                    int matches = 0;
                    const int wantStat[] = {
                        5};
                    const int wantMin[] = {
                        16};
                    for (int i = 0; i < 1; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 dg->rows)
                            if (r.name == "iie_g3"
                                && r.bandLo ==
                                   wantStat[i]
                                && r.bandHi ==
                                   wantMin[i])
                                rr = &r;
                        if (!rr
                            || rr->gp != 0)
                            ++bad;
                    }
                    for (const auto& r : dg->rows)
                        if (r.name == "iie_g3")
                            ++matches;
                    if (matches != 1) ++bad;
                }
                {
                    int matches = 0;
                    const int wantStat[] = {
                        5};
                    const int wantMin[] = {
                        17};
                    for (int i = 0; i < 1; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 dg->rows)
                            if (r.name == "iie_g4"
                                && r.bandLo ==
                                   wantStat[i]
                                && r.bandHi ==
                                   wantMin[i])
                                rr = &r;
                        if (!rr
                            || rr->gp != 0)
                            ++bad;
                    }
                    for (const auto& r : dg->rows)
                        if (r.name == "iie_g4")
                            ++matches;
                    if (matches != 1) ++bad;
                }
                {
                    int matches = 0;
                    const int wantStat[] = {
                        5};
                    const int wantMin[] = {
                        19};
                    for (int i = 0; i < 1; ++i) {
                        const items::MiscItemRow* rr = 0;
                        for (const auto& r :
                                 dg->rows)
                            if (r.name == "iie_g5"
                                && r.bandLo ==
                                   wantStat[i]
                                && r.bandHi ==
                                   wantMin[i])
                                rr = &r;
                        if (!rr
                            || rr->gp != 0)
                            ++bad;
                    }
                    for (const auto& r : dg->rows)
                        if (r.name == "iie_g5")
                            ++matches;
                    if (matches != 1) ++bad;
                }
            }
        }
        printf("R1049 subrace level registry data audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 5. rows (the full cross-read) ---------
        {
            const char* colTags[] = {
                "iia_assassin", "iia_cleric", "iia_fighter_hill",
                "iia_fighter_m_g", "iia_thief", "iib_assassin",
                "iib_cleric", "iib_fighter", "iib_illusionist",
                "iib_thief", "iic_assassin", "iic_cleric_a_o",
                "iic_cleric_d_f", "iic_cleric_d_m", "iic_druid_a_o",
                "iic_druid_wild", "iic_fighter_d_f", "iic_fighter_d_m",
                "iic_fighter_g_h", "iic_fighter_va", "iic_fighter_wi",
                "iic_fighter_wo", "iic_mu_d_f", "iic_mu_d_m",
                "iic_mu_gray", "iic_mu_high", "iic_mu_val",
                "iic_mu_wood", "iic_ranger", "iic_thief",
                "iid_assassin", "iid_cleric", "iid_druid",
                "iid_fighter", "iid_m_u", "iid_ranger",
                "iid_thief", "iie_cleric", "iie_druid",
                "iie_fighter_h_f", "iie_fighter_st", "iie_fighter_t_f",
                "iie_thief", "iif_assassin", "iif_cleric",
                "iif_fighter", "iif_thief"
            };
            const int NCOLS = 47;
            const rules::RaceLevelColumn* colSet[NCOLS];
            for (int i = 0; i < NCOLS; ++i)
                colSet[i] = rules::uaLevelColumn(
                    colTags[i]);
            const char* gateTags[] = {
                "iia_g1", "iia_g2", "iib_g1",
                "iib_g2", "iic_a_g1", "iic_a_g2",
                "iic_a_g3", "iic_a_g4", "iic_a_g5",
                "iic_a_g6", "iic_d_g1", "iic_d_g2",
                "iid_g1", "iid_g3", "iie_g1",
                "iie_g2", "iie_g3", "iie_g4",
                "iie_g5"
            };
            const int NGATES = 19;
            const rules::LevelGate* gateSet[NGATES];
            int gateN[NGATES];
            for (int i = 0; i < NGATES; ++i) {
                gateSet[i] = 0;
                gateN[i] = 0;
                rules::uaLevelGateList(
                    gateTags[i],
                    gateSet[i], gateN[i]);
                if (!gateSet[i]
                    || gateN[i] == 0)
                    ++bad;
            }
            int seenCols[NCOLS];
            int seenGates[NGATES];
            for (int i = 0; i < NCOLS; ++i)
                seenCols[i] = 0;
            for (int i = 0; i < NGATES; ++i)
                seenGates[i] = 0;
            for (int s = 0;
                 s < rules::SUBRACE_COUNT; ++s)
                for (int c = 0;
                     c < rules::UACLASS_COUNT; ++c)
                    for (int f = 0; f <= 1; ++f) {
                        const rules::RaceLevelColumn* col =
                            rules::subraceLevelColumn(
                                (rules::CharSubRace)s,
                                (rules::UaClass)c, f);
                        if (!col) {
                            if (rules::subraceLevelLimit(
                                    (rules::CharSubRace)s,
                                    (rules::UaClass)c,
                                    1, f) != -1)
                                ++bad;
                            continue;
                        }
                        int idx = -1;
                        for (int i = 0; i < NCOLS; ++i)
                            if (colSet[i] == col)
                                idx = i;
                        if (idx < 0) ++bad;
                        else ++seenCols[idx];
                        for (int i = 0; i < col->n; ++i) {
                            int k = col->keys[i];
                            int want = col->levels[i];
                            if (rules::subraceLevelLimit(
                                    (rules::CharSubRace)s,
                                    (rules::UaClass)c,
                                    k, f) != want)
                                ++bad;
                            if (col->fns && rules::
                                subraceLevelFootnote(
                                    (rules::CharSubRace)s,
                                    (rules::UaClass)c,
                                    k, f) !=
                                col->fns[i])
                                ++bad;
                        }
                        int top = col->keys[col->n - 1];
                        if (rules::subraceLevelLimit(
                                (rules::CharSubRace)s,
                                (rules::UaClass)c,
                                top + 1, f) !=
                            col->levels[col->n - 1])
                            ++bad;
                        if (rules::subraceLevelLimit(
                                (rules::CharSubRace)s,
                                (rules::UaClass)c,
                                col->keys[0] - 1, f) !=
                            col->levels[0])
                            ++bad;
                        for (int fn = 0;
                             fn <= 6; ++fn) {
                            const rules::LevelGate* g = 0;
                            int n = 0;
                            int orMode = 0;
                            rules::subraceLevelGates(
                                (rules::CharSubRace)s,
                                (rules::UaClass)c, fn,
                                g, n, orMode);
                            if (fn == 0) {
                                if (g || n)
                                    ++bad;
                                continue;
                            }
                            if (!g) continue;
                            int gi = -1;
                            for (int i = 0; i < NGATES; ++i)
                                if (gateSet[i] == g)
                                    gi = i;
                            if (gi < 0) ++bad;
                            else ++seenGates[gi];
                            if (orMode != 0
                                && orMode != 1)
                                ++bad;
                        }
                    }
            for (int i = 0; i < NCOLS; ++i)
                if (seenCols[i] == 0)
                    ++bad;
            for (int i = 0; i < NGATES; ++i)
                if (seenGates[i] == 0)
                    ++bad;
        }
        printf("R1049 subrace level registry rows audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 6. edges ---------------------------------
        {
            if (rules::subraceStrengthLevelKey(
                    17, -1) != 17000)
                ++bad;
            if (rules::subraceStrengthLevelKey(
                    18, -1) != 18000 ||
                rules::subraceStrengthLevelKey(
                    18, 1) != 18010 ||
                rules::subraceStrengthLevelKey(
                    18, 99) != 18990 ||
                rules::subraceStrengthLevelKey(
                    18, 100) != 18999 ||
                rules::subraceStrengthLevelKey(
                    19, 50) != 19000)
                ++bad;
            if (rules::subraceLevelLimit(
                    rules::SUB_HUMAN, rules::UACLASS_FIGHTER, 18000, 0)
                != -1)
                ++bad;
            if (rules::subraceLevelLimit(
                    rules::SUB_NONE, rules::UACLASS_CLERIC, 18000, 0)
                != -1)
                ++bad;
            if (rules::singleClassLevelBonus() != 2)
                ++bad;
            if (rules::elfRangerAbove15Level() != 8 ||
                rules::halfElfRanger19Level() != 12 ||
                rules::halfElfRanger20Level() != 14 ||
                rules::halflingDruid16Level() != 8 ||
                rules::halflingDruid17Level() != 10 ||
                rules::halflingDruid18Level() != 12)
                ++bad;
            {
                const rules::LevelGate* g = 0;
                int n = 0;
                int orMode = 0;
                rules::subraceLevelGates(
                    rules::SUB_ELF_WILD, rules::UACLASS_ASSASSIN, 6,
                    g, n, orMode);
                if (!g || n != 2                    || orMode != 1)
                    ++bad;
            }
            {
                const rules::LevelGate* g = 0;
                int n = 0;
                int orMode = 0;
                rules::subraceLevelGates(
                    rules::SUB_DWARF_HILL, rules::UACLASS_DRUID, 1,
                    g, n, orMode);
                if (g || n) ++bad;
            }
        }
        printf("R1049 subrace level registry edges audit: bad %d\n", bad);
        if (bad) return 1;
    }
