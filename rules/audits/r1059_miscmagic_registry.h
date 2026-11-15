    // ==== R1059: misc-magic registry ==========
    // The R1059 de-wire: the 37 retiring static
    // arrays of the six DMG MISC-MAGIC-family
    // headers ride items::MiscItemRegistry from
    // content/tables/miscmagic/ - 6 defs, 37 tables, 0 rows readers;
    // the KEPT zero-arg scalar and count fns stay C++,
    // probed by the older pin fragments and the model here. Eight sections: load, counts,
    // defs-A/B/C/D, seam, edges. Census 1119 -> 1127. DO NOT hand-edit:
    // tools/r1059_splice.py is the only writer.
    {
        int bad = 0;
        // -- 1. load ------------------------------
        {
            items::MiscItemRegistry reg;
            int n = reg.loadDirectory(
                "content/tables/miscmagic");
            if (n != 6) ++bad;
            if (!reg.errors().empty()) ++bad;
            for (const auto& kv : reg.all())
                if ((int)kv.second.sources.size() != 1
                    || kv.second.sources[0].second != 1059)
                    ++bad;
            if (!reg.find("misc_m1")) ++bad;
            if (!reg.find("misc_m2")) ++bad;
            if (!reg.find("misc_m3")) ++bad;
            if (!reg.find("misc_m4")) ++bad;
            if (!reg.find("misc_m5")) ++bad;
            if (!reg.find("wonder")) ++bad;
        }
        printf("R1059 misc-magic registry load audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 2. counts --------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/miscmagic");
            {
                const items::MiscItemDef* d =
                    reg.find("misc_m1");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 33
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "misc_m1RowCount"
                        || d->pins[0].value != 33)
                        ++bad;
                    if ((int)d->tables.size() != 7) ++bad;
                    if (d->tables[0].name
                        != "is_artifact_relic"
                        || (int)d->tables[0]
                            .values.size() != 33)
                        ++bad;
                    if (d->tables[1].name
                        != "is_per_ac_point"
                        || (int)d->tables[1]
                            .values.size() != 33)
                        ++bad;
                    if (d->tables[2].name
                        != "is_tiered_purse"
                        || (int)d->tables[2]
                            .values.size() != 33)
                        ++bad;
                    if (d->tables[3].name
                        != "row_hi"
                        || (int)d->tables[3]
                            .values.size() != 33)
                        ++bad;
                    if (d->tables[4].name
                        != "row_lo"
                        || (int)d->tables[4]
                            .values.size() != 33)
                        ++bad;
                    if (d->tables[5].name
                        != "usable_by_cleric"
                        || (int)d->tables[5]
                            .values.size() != 33)
                        ++bad;
                    if (d->tables[6].name
                        != "usable_by_mu"
                        || (int)d->tables[6]
                            .values.size() != 33)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("misc_m2");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 30
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "misc_m2RowCount"
                        || d->pins[0].value != 30)
                        ++bad;
                    if ((int)d->tables.size() != 7) ++bad;
                    if (d->tables[0].name
                        != "has_feature_asterisk"
                        || (int)d->tables[0]
                            .values.size() != 30)
                        ++bad;
                    if (d->tables[1].name
                        != "is_per_plus_valued"
                        || (int)d->tables[1]
                            .values.size() != 30)
                        ++bad;
                    if (d->tables[2].name
                        != "is_triple_star"
                        || (int)d->tables[2]
                            .values.size() != 30)
                        ++bad;
                    if (d->tables[3].name
                        != "row_hi"
                        || (int)d->tables[3]
                            .values.size() != 30)
                        ++bad;
                    if (d->tables[4].name
                        != "row_lo"
                        || (int)d->tables[4]
                            .values.size() != 30)
                        ++bad;
                    if (d->tables[5].name
                        != "usable_by_cleric"
                        || (int)d->tables[5]
                            .values.size() != 30)
                        ++bad;
                    if (d->tables[6].name
                        != "usable_by_mu"
                        || (int)d->tables[6]
                            .values.size() != 30)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("misc_m3");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 33
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "misc_m3RowCount"
                        || d->pins[0].value != 33)
                        ++bad;
                    if ((int)d->tables.size() != 7) ++bad;
                    if (d->tables[0].name
                        != "is_per_facet"
                        || (int)d->tables[0]
                            .values.size() != 33)
                        ++bad;
                    if (d->tables[1].name
                        != "row_hi"
                        || (int)d->tables[1]
                            .values.size() != 33)
                        ++bad;
                    if (d->tables[2].name
                        != "row_lo"
                        || (int)d->tables[2]
                            .values.size() != 33)
                        ++bad;
                    if (d->tables[3].name
                        != "star_count"
                        || (int)d->tables[3]
                            .values.size() != 33)
                        ++bad;
                    if (d->tables[4].name
                        != "usable_by_cleric"
                        || (int)d->tables[4]
                            .values.size() != 33)
                        ++bad;
                    if (d->tables[5].name
                        != "usable_by_fighter"
                        || (int)d->tables[5]
                            .values.size() != 33)
                        ++bad;
                    if (d->tables[6].name
                        != "usable_by_thief"
                        || (int)d->tables[6]
                            .values.size() != 33)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("misc_m4");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 36
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "misc_m4RowCount"
                        || d->pins[0].value != 36)
                        ++bad;
                    if ((int)d->tables.size() != 8) ++bad;
                    if (d->tables[0].name
                        != "is_dual_valued"
                        || (int)d->tables[0]
                            .values.size() != 36)
                        ++bad;
                    if (d->tables[1].name
                        != "row_hi"
                        || (int)d->tables[1]
                            .values.size() != 36)
                        ++bad;
                    if (d->tables[2].name
                        != "row_lo"
                        || (int)d->tables[2]
                            .values.size() != 36)
                        ++bad;
                    if (d->tables[3].name
                        != "star_count"
                        || (int)d->tables[3]
                            .values.size() != 36)
                        ++bad;
                    if (d->tables[4].name
                        != "usable_by_cleric"
                        || (int)d->tables[4]
                            .values.size() != 36)
                        ++bad;
                    if (d->tables[5].name
                        != "usable_by_fighter"
                        || (int)d->tables[5]
                            .values.size() != 36)
                        ++bad;
                    if (d->tables[6].name
                        != "usable_by_mu"
                        || (int)d->tables[6]
                            .values.size() != 36)
                        ++bad;
                    if (d->tables[7].name
                        != "usable_by_thief"
                        || (int)d->tables[7]
                            .values.size() != 36)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("misc_m5");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 35
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "misc_m5RowCount"
                        || d->pins[0].value != 35)
                        ++bad;
                    if ((int)d->tables.size() != 6) ++bad;
                    if (d->tables[0].name
                        != "row_hi"
                        || (int)d->tables[0]
                            .values.size() != 35)
                        ++bad;
                    if (d->tables[1].name
                        != "row_lo"
                        || (int)d->tables[1]
                            .values.size() != 35)
                        ++bad;
                    if (d->tables[2].name
                        != "usable_by_cleric"
                        || (int)d->tables[2]
                            .values.size() != 35)
                        ++bad;
                    if (d->tables[3].name
                        != "usable_by_fighter"
                        || (int)d->tables[3]
                            .values.size() != 35)
                        ++bad;
                    if (d->tables[4].name
                        != "usable_by_mu"
                        || (int)d->tables[4]
                            .values.size() != 35)
                        ++bad;
                    if (d->tables[5].name
                        != "usable_by_thief"
                        || (int)d->tables[5]
                            .values.size() != 35)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("wonder");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 19
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "wonderRowCount"
                        || d->pins[0].value != 19)
                        ++bad;
                    if ((int)d->tables.size() != 2) ++bad;
                    if (d->tables[0].name
                        != "row_hi"
                        || (int)d->tables[0]
                            .values.size() != 19)
                        ++bad;
                    if (d->tables[1].name
                        != "row_lo"
                        || (int)d->tables[1]
                            .values.size() != 19)
                        ++bad;
                }
            }
        }
        printf("R1059 misc-magic registry counts audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 3. A -----------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/miscmagic");
            {
                const items::MiscItemDef* d =
                    reg.find("misc_m1");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 0) ++bad;
                    if (d->tables[0]
                        .values[1] != 0) ++bad;
                    if (d->tables[0]
                        .values[2] != 0) ++bad;
                    if (d->tables[0]
                        .values[3] != 0) ++bad;
                    if (d->tables[0]
                        .values[4] != 0) ++bad;
                    if (d->tables[0]
                        .values[5] != 0) ++bad;
                    if (d->tables[0]
                        .values[6] != 0) ++bad;
                    if (d->tables[0]
                        .values[7] != 1) ++bad;
                    if (d->tables[0]
                        .values[8] != 0) ++bad;
                    if (d->tables[0]
                        .values[9] != 0) ++bad;
                    if (d->tables[0]
                        .values[10] != 0) ++bad;
                    if (d->tables[0]
                        .values[11] != 0) ++bad;
                    if (d->tables[0]
                        .values[12] != 0) ++bad;
                    if (d->tables[0]
                        .values[13] != 0) ++bad;
                    if (d->tables[0]
                        .values[14] != 0) ++bad;
                    if (d->tables[0]
                        .values[15] != 0) ++bad;
                    if (d->tables[0]
                        .values[16] != 0) ++bad;
                    if (d->tables[0]
                        .values[17] != 0) ++bad;
                    if (d->tables[0]
                        .values[18] != 0) ++bad;
                    if (d->tables[0]
                        .values[19] != 0) ++bad;
                    if (d->tables[0]
                        .values[20] != 0) ++bad;
                    if (d->tables[0]
                        .values[21] != 0) ++bad;
                    if (d->tables[0]
                        .values[22] != 0) ++bad;
                    if (d->tables[0]
                        .values[23] != 0) ++bad;
                    if (d->tables[0]
                        .values[24] != 0) ++bad;
                    if (d->tables[0]
                        .values[25] != 0) ++bad;
                    if (d->tables[0]
                        .values[26] != 0) ++bad;
                    if (d->tables[0]
                        .values[27] != 0) ++bad;
                    if (d->tables[0]
                        .values[28] != 0) ++bad;
                    if (d->tables[0]
                        .values[29] != 0) ++bad;
                    if (d->tables[0]
                        .values[30] != 0) ++bad;
                    if (d->tables[0]
                        .values[31] != 0) ++bad;
                    if (d->tables[0]
                        .values[32] != 0) ++bad;
                    if (d->tables[1]
                        .values[0] != 0) ++bad;
                    if (d->tables[1]
                        .values[1] != 0) ++bad;
                    if (d->tables[1]
                        .values[2] != 0) ++bad;
                    if (d->tables[1]
                        .values[3] != 0) ++bad;
                    if (d->tables[1]
                        .values[4] != 0) ++bad;
                    if (d->tables[1]
                        .values[5] != 0) ++bad;
                    if (d->tables[1]
                        .values[6] != 0) ++bad;
                    if (d->tables[1]
                        .values[7] != 0) ++bad;
                    if (d->tables[1]
                        .values[8] != 0) ++bad;
                    if (d->tables[1]
                        .values[9] != 0) ++bad;
                    if (d->tables[1]
                        .values[10] != 0) ++bad;
                    if (d->tables[1]
                        .values[11] != 0) ++bad;
                    if (d->tables[1]
                        .values[12] != 0) ++bad;
                    if (d->tables[1]
                        .values[13] != 0) ++bad;
                    if (d->tables[1]
                        .values[14] != 0) ++bad;
                    if (d->tables[1]
                        .values[15] != 0) ++bad;
                    if (d->tables[1]
                        .values[16] != 0) ++bad;
                    if (d->tables[1]
                        .values[17] != 0) ++bad;
                    if (d->tables[1]
                        .values[18] != 0) ++bad;
                    if (d->tables[1]
                        .values[19] != 0) ++bad;
                    if (d->tables[1]
                        .values[20] != 0) ++bad;
                    if (d->tables[1]
                        .values[21] != 0) ++bad;
                    if (d->tables[1]
                        .values[22] != 0) ++bad;
                    if (d->tables[1]
                        .values[23] != 0) ++bad;
                    if (d->tables[1]
                        .values[24] != 0) ++bad;
                    if (d->tables[1]
                        .values[25] != 1) ++bad;
                    if (d->tables[1]
                        .values[26] != 0) ++bad;
                    if (d->tables[1]
                        .values[27] != 0) ++bad;
                    if (d->tables[1]
                        .values[28] != 0) ++bad;
                    if (d->tables[1]
                        .values[29] != 0) ++bad;
                    if (d->tables[1]
                        .values[30] != 0) ++bad;
                    if (d->tables[1]
                        .values[31] != 0) ++bad;
                    if (d->tables[1]
                        .values[32] != 0) ++bad;
                    if (d->tables[2]
                        .values[0] != 0) ++bad;
                    if (d->tables[2]
                        .values[1] != 0) ++bad;
                    if (d->tables[2]
                        .values[2] != 0) ++bad;
                    if (d->tables[2]
                        .values[3] != 0) ++bad;
                    if (d->tables[2]
                        .values[4] != 0) ++bad;
                    if (d->tables[2]
                        .values[5] != 0) ++bad;
                    if (d->tables[2]
                        .values[6] != 0) ++bad;
                    if (d->tables[2]
                        .values[7] != 0) ++bad;
                    if (d->tables[2]
                        .values[8] != 0) ++bad;
                    if (d->tables[2]
                        .values[9] != 0) ++bad;
                    if (d->tables[2]
                        .values[10] != 0) ++bad;
                    if (d->tables[2]
                        .values[11] != 0) ++bad;
                    if (d->tables[2]
                        .values[12] != 0) ++bad;
                    if (d->tables[2]
                        .values[13] != 0) ++bad;
                    if (d->tables[2]
                        .values[14] != 0) ++bad;
                    if (d->tables[2]
                        .values[15] != 0) ++bad;
                    if (d->tables[2]
                        .values[16] != 0) ++bad;
                    if (d->tables[2]
                        .values[17] != 0) ++bad;
                    if (d->tables[2]
                        .values[18] != 0) ++bad;
                    if (d->tables[2]
                        .values[19] != 0) ++bad;
                    if (d->tables[2]
                        .values[20] != 0) ++bad;
                    if (d->tables[2]
                        .values[21] != 0) ++bad;
                    if (d->tables[2]
                        .values[22] != 0) ++bad;
                    if (d->tables[2]
                        .values[23] != 0) ++bad;
                    if (d->tables[2]
                        .values[24] != 0) ++bad;
                    if (d->tables[2]
                        .values[25] != 0) ++bad;
                    if (d->tables[2]
                        .values[26] != 0) ++bad;
                    if (d->tables[2]
                        .values[27] != 0) ++bad;
                    if (d->tables[2]
                        .values[28] != 0) ++bad;
                    if (d->tables[2]
                        .values[29] != 0) ++bad;
                    if (d->tables[2]
                        .values[30] != 0) ++bad;
                    if (d->tables[2]
                        .values[31] != 0) ++bad;
                    if (d->tables[2]
                        .values[32] != 1) ++bad;
                    if (d->tables[3]
                        .values[0] != 2) ++bad;
                    if (d->tables[3]
                        .values[1] != 4) ++bad;
                    if (d->tables[3]
                        .values[2] != 5) ++bad;
                    if (d->tables[3]
                        .values[3] != 7) ++bad;
                    if (d->tables[3]
                        .values[4] != 11) ++bad;
                    if (d->tables[3]
                        .values[5] != 13) ++bad;
                    if (d->tables[3]
                        .values[6] != 16) ++bad;
                    if (d->tables[3]
                        .values[7] != 17) ++bad;
                    if (d->tables[3]
                        .values[8] != 20) ++bad;
                    if (d->tables[3]
                        .values[9] != 21) ++bad;
                    if (d->tables[3]
                        .values[10] != 26) ++bad;
                    if (d->tables[3]
                        .values[11] != 27) ++bad;
                    if (d->tables[3]
                        .values[12] != 29) ++bad;
                    if (d->tables[3]
                        .values[13] != 31) ++bad;
                    if (d->tables[3]
                        .values[14] != 32) ++bad;
                    if (d->tables[3]
                        .values[15] != 33) ++bad;
                    if (d->tables[3]
                        .values[16] != 34) ++bad;
                    if (d->tables[3]
                        .values[17] != 35) ++bad;
                    if (d->tables[3]
                        .values[18] != 36) ++bad;
                    if (d->tables[3]
                        .values[19] != 42) ++bad;
                    if (d->tables[3]
                        .values[20] != 47) ++bad;
                    if (d->tables[3]
                        .values[21] != 51) ++bad;
                    if (d->tables[3]
                        .values[22] != 55) ++bad;
                    if (d->tables[3]
                        .values[23] != 58) ++bad;
                    if (d->tables[3]
                        .values[24] != 59) ++bad;
                    if (d->tables[3]
                        .values[25] != 79) ++bad;
                    if (d->tables[3]
                        .values[26] != 81) ++bad;
                    if (d->tables[3]
                        .values[27] != 84) ++bad;
                    if (d->tables[3]
                        .values[28] != 85) ++bad;
                    if (d->tables[3]
                        .values[29] != 92) ++bad;
                    if (d->tables[3]
                        .values[30] != 93) ++bad;
                    if (d->tables[3]
                        .values[31] != 98) ++bad;
                    if (d->tables[3]
                        .values[32] != 100) ++bad;
                    if (d->tables[4]
                        .values[0] != 1) ++bad;
                    if (d->tables[4]
                        .values[1] != 3) ++bad;
                    if (d->tables[4]
                        .values[2] != 5) ++bad;
                    if (d->tables[4]
                        .values[3] != 6) ++bad;
                    if (d->tables[4]
                        .values[4] != 8) ++bad;
                    if (d->tables[4]
                        .values[5] != 12) ++bad;
                    if (d->tables[4]
                        .values[6] != 14) ++bad;
                    if (d->tables[4]
                        .values[7] != 17) ++bad;
                    if (d->tables[4]
                        .values[8] != 18) ++bad;
                    if (d->tables[4]
                        .values[9] != 21) ++bad;
                    if (d->tables[4]
                        .values[10] != 22) ++bad;
                    if (d->tables[4]
                        .values[11] != 27) ++bad;
                    if (d->tables[4]
                        .values[12] != 28) ++bad;
                    if (d->tables[4]
                        .values[13] != 30) ++bad;
                    if (d->tables[4]
                        .values[14] != 32) ++bad;
                    if (d->tables[4]
                        .values[15] != 33) ++bad;
                    if (d->tables[4]
                        .values[16] != 34) ++bad;
                    if (d->tables[4]
                        .values[17] != 35) ++bad;
                    if (d->tables[4]
                        .values[18] != 36) ++bad;
                    if (d->tables[4]
                        .values[19] != 37) ++bad;
                    if (d->tables[4]
                        .values[20] != 43) ++bad;
                    if (d->tables[4]
                        .values[21] != 48) ++bad;
                    if (d->tables[4]
                        .values[22] != 52) ++bad;
                    if (d->tables[4]
                        .values[23] != 56) ++bad;
                    if (d->tables[4]
                        .values[24] != 59) ++bad;
                    if (d->tables[4]
                        .values[25] != 60) ++bad;
                    if (d->tables[4]
                        .values[26] != 80) ++bad;
                    if (d->tables[4]
                        .values[27] != 82) ++bad;
                    if (d->tables[4]
                        .values[28] != 85) ++bad;
                    if (d->tables[4]
                        .values[29] != 86) ++bad;
                    if (d->tables[4]
                        .values[30] != 93) ++bad;
                    if (d->tables[4]
                        .values[31] != 94) ++bad;
                    if (d->tables[4]
                        .values[32] != 99) ++bad;
                    if (d->tables[5]
                        .values[0] != 0) ++bad;
                    if (d->tables[5]
                        .values[1] != 0) ++bad;
                    if (d->tables[5]
                        .values[2] != 0) ++bad;
                    if (d->tables[5]
                        .values[3] != 0) ++bad;
                    if (d->tables[5]
                        .values[4] != 0) ++bad;
                    if (d->tables[5]
                        .values[5] != 0) ++bad;
                    if (d->tables[5]
                        .values[6] != 0) ++bad;
                    if (d->tables[5]
                        .values[7] != 0) ++bad;
                    if (d->tables[5]
                        .values[8] != 0) ++bad;
                    if (d->tables[5]
                        .values[9] != 0) ++bad;
                    if (d->tables[5]
                        .values[10] != 0) ++bad;
                    if (d->tables[5]
                        .values[11] != 0) ++bad;
                    if (d->tables[5]
                        .values[12] != 0) ++bad;
                    if (d->tables[5]
                        .values[13] != 0) ++bad;
                    if (d->tables[5]
                        .values[14] != 0) ++bad;
                    if (d->tables[5]
                        .values[15] != 1) ++bad;
                    if (d->tables[5]
                        .values[16] != 0) ++bad;
                    if (d->tables[5]
                        .values[17] != 1) ++bad;
                    if (d->tables[5]
                        .values[18] != 0) ++bad;
                    if (d->tables[5]
                        .values[19] != 0) ++bad;
                    if (d->tables[5]
                        .values[20] != 0) ++bad;
                    if (d->tables[5]
                        .values[21] != 0) ++bad;
                    if (d->tables[5]
                        .values[22] != 0) ++bad;
                    if (d->tables[5]
                        .values[23] != 0) ++bad;
                    if (d->tables[5]
                        .values[24] != 0) ++bad;
                    if (d->tables[5]
                        .values[25] != 0) ++bad;
                    if (d->tables[5]
                        .values[26] != 0) ++bad;
                    if (d->tables[5]
                        .values[27] != 0) ++bad;
                    if (d->tables[5]
                        .values[28] != 0) ++bad;
                    if (d->tables[5]
                        .values[29] != 0) ++bad;
                    if (d->tables[5]
                        .values[30] != 0) ++bad;
                    if (d->tables[5]
                        .values[31] != 0) ++bad;
                    if (d->tables[5]
                        .values[32] != 0) ++bad;
                    if (d->tables[6]
                        .values[0] != 0) ++bad;
                    if (d->tables[6]
                        .values[1] != 0) ++bad;
                    if (d->tables[6]
                        .values[2] != 0) ++bad;
                    if (d->tables[6]
                        .values[3] != 0) ++bad;
                    if (d->tables[6]
                        .values[4] != 0) ++bad;
                    if (d->tables[6]
                        .values[5] != 0) ++bad;
                    if (d->tables[6]
                        .values[6] != 0) ++bad;
                    if (d->tables[6]
                        .values[7] != 0) ++bad;
                    if (d->tables[6]
                        .values[8] != 0) ++bad;
                    if (d->tables[6]
                        .values[9] != 0) ++bad;
                    if (d->tables[6]
                        .values[10] != 0) ++bad;
                    if (d->tables[6]
                        .values[11] != 0) ++bad;
                    if (d->tables[6]
                        .values[12] != 0) ++bad;
                    if (d->tables[6]
                        .values[13] != 0) ++bad;
                    if (d->tables[6]
                        .values[14] != 0) ++bad;
                    if (d->tables[6]
                        .values[15] != 0) ++bad;
                    if (d->tables[6]
                        .values[16] != 0) ++bad;
                    if (d->tables[6]
                        .values[17] != 0) ++bad;
                    if (d->tables[6]
                        .values[18] != 0) ++bad;
                    if (d->tables[6]
                        .values[19] != 0) ++bad;
                    if (d->tables[6]
                        .values[20] != 0) ++bad;
                    if (d->tables[6]
                        .values[21] != 0) ++bad;
                    if (d->tables[6]
                        .values[22] != 0) ++bad;
                    if (d->tables[6]
                        .values[23] != 1) ++bad;
                    if (d->tables[6]
                        .values[24] != 1) ++bad;
                    if (d->tables[6]
                        .values[25] != 0) ++bad;
                    if (d->tables[6]
                        .values[26] != 0) ++bad;
                    if (d->tables[6]
                        .values[27] != 1) ++bad;
                    if (d->tables[6]
                        .values[28] != 1) ++bad;
                    if (d->tables[6]
                        .values[29] != 0) ++bad;
                    if (d->tables[6]
                        .values[30] != 0) ++bad;
                    if (d->tables[6]
                        .values[31] != 0) ++bad;
                    if (d->tables[6]
                        .values[32] != 0) ++bad;
                    if (rules::m1RowLo(0) != 1) ++bad;
                    if (rules::m1RowLo(1) != 3) ++bad;
                    if (rules::m1RowLo(2) != 5) ++bad;
                    if (rules::m1RowLo(3) != 6) ++bad;
                    if (rules::m1RowLo(4) != 8) ++bad;
                    if (rules::m1RowLo(5) != 12) ++bad;
                    if (rules::m1RowLo(6) != 14) ++bad;
                    if (rules::m1RowLo(7) != 17) ++bad;
                    if (rules::m1RowLo(8) != 18) ++bad;
                    if (rules::m1RowLo(9) != 21) ++bad;
                    if (rules::m1RowLo(10) != 22) ++bad;
                    if (rules::m1RowLo(11) != 27) ++bad;
                    if (rules::m1RowLo(12) != 28) ++bad;
                    if (rules::m1RowLo(13) != 30) ++bad;
                    if (rules::m1RowLo(14) != 32) ++bad;
                    if (rules::m1RowLo(15) != 33) ++bad;
                    if (rules::m1RowLo(16) != 34) ++bad;
                    if (rules::m1RowLo(17) != 35) ++bad;
                    if (rules::m1RowLo(18) != 36) ++bad;
                    if (rules::m1RowLo(19) != 37) ++bad;
                    if (rules::m1RowLo(20) != 43) ++bad;
                    if (rules::m1RowLo(21) != 48) ++bad;
                    if (rules::m1RowLo(22) != 52) ++bad;
                    if (rules::m1RowLo(23) != 56) ++bad;
                    if (rules::m1RowLo(24) != 59) ++bad;
                    if (rules::m1RowLo(25) != 60) ++bad;
                    if (rules::m1RowLo(26) != 80) ++bad;
                    if (rules::m1RowLo(27) != 82) ++bad;
                    if (rules::m1RowLo(28) != 85) ++bad;
                    if (rules::m1RowLo(29) != 86) ++bad;
                    if (rules::m1RowLo(30) != 93) ++bad;
                    if (rules::m1RowLo(31) != 94) ++bad;
                    if (rules::m1RowLo(32) != 99) ++bad;
                    if (rules::m1RowHi(0) != 2) ++bad;
                    if (rules::m1RowHi(1) != 4) ++bad;
                    if (rules::m1RowHi(2) != 5) ++bad;
                    if (rules::m1RowHi(3) != 7) ++bad;
                    if (rules::m1RowHi(4) != 11) ++bad;
                    if (rules::m1RowHi(5) != 13) ++bad;
                    if (rules::m1RowHi(6) != 16) ++bad;
                    if (rules::m1RowHi(7) != 17) ++bad;
                    if (rules::m1RowHi(8) != 20) ++bad;
                    if (rules::m1RowHi(9) != 21) ++bad;
                    if (rules::m1RowHi(10) != 26) ++bad;
                    if (rules::m1RowHi(11) != 27) ++bad;
                    if (rules::m1RowHi(12) != 29) ++bad;
                    if (rules::m1RowHi(13) != 31) ++bad;
                    if (rules::m1RowHi(14) != 32) ++bad;
                    if (rules::m1RowHi(15) != 33) ++bad;
                    if (rules::m1RowHi(16) != 34) ++bad;
                    if (rules::m1RowHi(17) != 35) ++bad;
                    if (rules::m1RowHi(18) != 36) ++bad;
                    if (rules::m1RowHi(19) != 42) ++bad;
                    if (rules::m1RowHi(20) != 47) ++bad;
                    if (rules::m1RowHi(21) != 51) ++bad;
                    if (rules::m1RowHi(22) != 55) ++bad;
                    if (rules::m1RowHi(23) != 58) ++bad;
                    if (rules::m1RowHi(24) != 59) ++bad;
                    if (rules::m1RowHi(25) != 79) ++bad;
                    if (rules::m1RowHi(26) != 81) ++bad;
                    if (rules::m1RowHi(27) != 84) ++bad;
                    if (rules::m1RowHi(28) != 85) ++bad;
                    if (rules::m1RowHi(29) != 92) ++bad;
                    if (rules::m1RowHi(30) != 93) ++bad;
                    if (rules::m1RowHi(31) != 98) ++bad;
                    if (rules::m1RowHi(32) != 100) ++bad;
                    if (rules::m1UsableByMagicUser(0) != 0) ++bad;
                    if (rules::m1UsableByMagicUser(1) != 0) ++bad;
                    if (rules::m1UsableByMagicUser(2) != 0) ++bad;
                    if (rules::m1UsableByMagicUser(3) != 0) ++bad;
                    if (rules::m1UsableByMagicUser(4) != 0) ++bad;
                    if (rules::m1UsableByMagicUser(5) != 0) ++bad;
                    if (rules::m1UsableByMagicUser(6) != 0) ++bad;
                    if (rules::m1UsableByMagicUser(7) != 0) ++bad;
                    if (rules::m1UsableByMagicUser(8) != 0) ++bad;
                    if (rules::m1UsableByMagicUser(9) != 0) ++bad;
                    if (rules::m1UsableByMagicUser(10) != 0) ++bad;
                    if (rules::m1UsableByMagicUser(11) != 0) ++bad;
                    if (rules::m1UsableByMagicUser(12) != 0) ++bad;
                    if (rules::m1UsableByMagicUser(13) != 0) ++bad;
                    if (rules::m1UsableByMagicUser(14) != 0) ++bad;
                    if (rules::m1UsableByMagicUser(15) != 0) ++bad;
                    if (rules::m1UsableByMagicUser(16) != 0) ++bad;
                    if (rules::m1UsableByMagicUser(17) != 0) ++bad;
                    if (rules::m1UsableByMagicUser(18) != 0) ++bad;
                    if (rules::m1UsableByMagicUser(19) != 0) ++bad;
                    if (rules::m1UsableByMagicUser(20) != 0) ++bad;
                    if (rules::m1UsableByMagicUser(21) != 0) ++bad;
                    if (rules::m1UsableByMagicUser(22) != 0) ++bad;
                    if (rules::m1UsableByMagicUser(23) != 1) ++bad;
                    if (rules::m1UsableByMagicUser(24) != 1) ++bad;
                    if (rules::m1UsableByMagicUser(25) != 0) ++bad;
                    if (rules::m1UsableByMagicUser(26) != 0) ++bad;
                    if (rules::m1UsableByMagicUser(27) != 1) ++bad;
                    if (rules::m1UsableByMagicUser(28) != 1) ++bad;
                    if (rules::m1UsableByMagicUser(29) != 0) ++bad;
                    if (rules::m1UsableByMagicUser(30) != 0) ++bad;
                    if (rules::m1UsableByMagicUser(31) != 0) ++bad;
                    if (rules::m1UsableByMagicUser(32) != 0) ++bad;
                    if (rules::m1UsableByCleric(0) != 0) ++bad;
                    if (rules::m1UsableByCleric(1) != 0) ++bad;
                    if (rules::m1UsableByCleric(2) != 0) ++bad;
                    if (rules::m1UsableByCleric(3) != 0) ++bad;
                    if (rules::m1UsableByCleric(4) != 0) ++bad;
                    if (rules::m1UsableByCleric(5) != 0) ++bad;
                    if (rules::m1UsableByCleric(6) != 0) ++bad;
                    if (rules::m1UsableByCleric(7) != 0) ++bad;
                    if (rules::m1UsableByCleric(8) != 0) ++bad;
                    if (rules::m1UsableByCleric(9) != 0) ++bad;
                    if (rules::m1UsableByCleric(10) != 0) ++bad;
                    if (rules::m1UsableByCleric(11) != 0) ++bad;
                    if (rules::m1UsableByCleric(12) != 0) ++bad;
                    if (rules::m1UsableByCleric(13) != 0) ++bad;
                    if (rules::m1UsableByCleric(14) != 0) ++bad;
                    if (rules::m1UsableByCleric(15) != 1) ++bad;
                    if (rules::m1UsableByCleric(16) != 0) ++bad;
                    if (rules::m1UsableByCleric(17) != 1) ++bad;
                    if (rules::m1UsableByCleric(18) != 0) ++bad;
                    if (rules::m1UsableByCleric(19) != 0) ++bad;
                    if (rules::m1UsableByCleric(20) != 0) ++bad;
                    if (rules::m1UsableByCleric(21) != 0) ++bad;
                    if (rules::m1UsableByCleric(22) != 0) ++bad;
                    if (rules::m1UsableByCleric(23) != 0) ++bad;
                    if (rules::m1UsableByCleric(24) != 0) ++bad;
                    if (rules::m1UsableByCleric(25) != 0) ++bad;
                    if (rules::m1UsableByCleric(26) != 0) ++bad;
                    if (rules::m1UsableByCleric(27) != 0) ++bad;
                    if (rules::m1UsableByCleric(28) != 0) ++bad;
                    if (rules::m1UsableByCleric(29) != 0) ++bad;
                    if (rules::m1UsableByCleric(30) != 0) ++bad;
                    if (rules::m1UsableByCleric(31) != 0) ++bad;
                    if (rules::m1UsableByCleric(32) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(0) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(1) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(2) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(3) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(4) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(5) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(6) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(7) != 1) ++bad;
                    if (rules::m1IsArtifactRelicRow(8) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(9) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(10) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(11) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(12) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(13) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(14) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(15) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(16) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(17) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(18) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(19) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(20) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(21) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(22) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(23) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(24) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(25) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(26) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(27) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(28) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(29) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(30) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(31) != 0) ++bad;
                    if (rules::m1IsArtifactRelicRow(32) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(0) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(1) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(2) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(3) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(4) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(5) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(6) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(7) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(8) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(9) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(10) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(11) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(12) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(13) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(14) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(15) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(16) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(17) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(18) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(19) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(20) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(21) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(22) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(23) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(24) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(25) != 1) ++bad;
                    if (rules::m1IsPerAcPointValued(26) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(27) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(28) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(29) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(30) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(31) != 0) ++bad;
                    if (rules::m1IsPerAcPointValued(32) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(0) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(1) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(2) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(3) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(4) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(5) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(6) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(7) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(8) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(9) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(10) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(11) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(12) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(13) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(14) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(15) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(16) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(17) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(18) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(19) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(20) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(21) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(22) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(23) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(24) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(25) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(26) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(27) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(28) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(29) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(30) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(31) != 0) ++bad;
                    if (rules::m1IsTieredPurseRow(32) != 1) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("misc_m2");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 0) ++bad;
                    if (d->tables[0]
                        .values[1] != 0) ++bad;
                    if (d->tables[0]
                        .values[2] != 0) ++bad;
                    if (d->tables[0]
                        .values[3] != 0) ++bad;
                    if (d->tables[0]
                        .values[4] != 0) ++bad;
                    if (d->tables[0]
                        .values[5] != 0) ++bad;
                    if (d->tables[0]
                        .values[6] != 0) ++bad;
                    if (d->tables[0]
                        .values[7] != 0) ++bad;
                    if (d->tables[0]
                        .values[8] != 0) ++bad;
                    if (d->tables[0]
                        .values[9] != 0) ++bad;
                    if (d->tables[0]
                        .values[10] != 0) ++bad;
                    if (d->tables[0]
                        .values[11] != 1) ++bad;
                    if (d->tables[0]
                        .values[12] != 0) ++bad;
                    if (d->tables[0]
                        .values[13] != 0) ++bad;
                    if (d->tables[0]
                        .values[14] != 0) ++bad;
                    if (d->tables[0]
                        .values[15] != 0) ++bad;
                    if (d->tables[0]
                        .values[16] != 0) ++bad;
                    if (d->tables[0]
                        .values[17] != 0) ++bad;
                    if (d->tables[0]
                        .values[18] != 0) ++bad;
                    if (d->tables[0]
                        .values[19] != 0) ++bad;
                    if (d->tables[0]
                        .values[20] != 0) ++bad;
                    if (d->tables[0]
                        .values[21] != 0) ++bad;
                    if (d->tables[0]
                        .values[22] != 0) ++bad;
                    if (d->tables[0]
                        .values[23] != 0) ++bad;
                    if (d->tables[0]
                        .values[24] != 0) ++bad;
                    if (d->tables[0]
                        .values[25] != 0) ++bad;
                    if (d->tables[0]
                        .values[26] != 0) ++bad;
                    if (d->tables[0]
                        .values[27] != 0) ++bad;
                    if (d->tables[0]
                        .values[28] != 0) ++bad;
                    if (d->tables[0]
                        .values[29] != 0) ++bad;
                    if (d->tables[1]
                        .values[0] != 0) ++bad;
                    if (d->tables[1]
                        .values[1] != 0) ++bad;
                    if (d->tables[1]
                        .values[2] != 0) ++bad;
                    if (d->tables[1]
                        .values[3] != 0) ++bad;
                    if (d->tables[1]
                        .values[4] != 0) ++bad;
                    if (d->tables[1]
                        .values[5] != 0) ++bad;
                    if (d->tables[1]
                        .values[6] != 0) ++bad;
                    if (d->tables[1]
                        .values[7] != 0) ++bad;
                    if (d->tables[1]
                        .values[8] != 0) ++bad;
                    if (d->tables[1]
                        .values[9] != 0) ++bad;
                    if (d->tables[1]
                        .values[10] != 1) ++bad;
                    if (d->tables[1]
                        .values[11] != 0) ++bad;
                    if (d->tables[1]
                        .values[12] != 0) ++bad;
                    if (d->tables[1]
                        .values[13] != 0) ++bad;
                    if (d->tables[1]
                        .values[14] != 0) ++bad;
                    if (d->tables[1]
                        .values[15] != 0) ++bad;
                    if (d->tables[1]
                        .values[16] != 0) ++bad;
                    if (d->tables[1]
                        .values[17] != 0) ++bad;
                    if (d->tables[1]
                        .values[18] != 0) ++bad;
                    if (d->tables[1]
                        .values[19] != 0) ++bad;
                    if (d->tables[1]
                        .values[20] != 0) ++bad;
                    if (d->tables[1]
                        .values[21] != 0) ++bad;
                    if (d->tables[1]
                        .values[22] != 0) ++bad;
                    if (d->tables[1]
                        .values[23] != 0) ++bad;
                    if (d->tables[1]
                        .values[24] != 0) ++bad;
                    if (d->tables[1]
                        .values[25] != 0) ++bad;
                    if (d->tables[1]
                        .values[26] != 0) ++bad;
                    if (d->tables[1]
                        .values[27] != 0) ++bad;
                    if (d->tables[1]
                        .values[28] != 0) ++bad;
                    if (d->tables[1]
                        .values[29] != 0) ++bad;
                    if (d->tables[2]
                        .values[0] != 0) ++bad;
                    if (d->tables[2]
                        .values[1] != 0) ++bad;
                    if (d->tables[2]
                        .values[2] != 0) ++bad;
                    if (d->tables[2]
                        .values[3] != 0) ++bad;
                    if (d->tables[2]
                        .values[4] != 0) ++bad;
                    if (d->tables[2]
                        .values[5] != 0) ++bad;
                    if (d->tables[2]
                        .values[6] != 0) ++bad;
                    if (d->tables[2]
                        .values[7] != 0) ++bad;
                    if (d->tables[2]
                        .values[8] != 0) ++bad;
                    if (d->tables[2]
                        .values[9] != 0) ++bad;
                    if (d->tables[2]
                        .values[10] != 0) ++bad;
                    if (d->tables[2]
                        .values[11] != 0) ++bad;
                    if (d->tables[2]
                        .values[12] != 0) ++bad;
                    if (d->tables[2]
                        .values[13] != 0) ++bad;
                    if (d->tables[2]
                        .values[14] != 0) ++bad;
                    if (d->tables[2]
                        .values[15] != 0) ++bad;
                    if (d->tables[2]
                        .values[16] != 0) ++bad;
                    if (d->tables[2]
                        .values[17] != 0) ++bad;
                    if (d->tables[2]
                        .values[18] != 0) ++bad;
                    if (d->tables[2]
                        .values[19] != 0) ++bad;
                    if (d->tables[2]
                        .values[20] != 0) ++bad;
                    if (d->tables[2]
                        .values[21] != 0) ++bad;
                    if (d->tables[2]
                        .values[22] != 0) ++bad;
                    if (d->tables[2]
                        .values[23] != 0) ++bad;
                    if (d->tables[2]
                        .values[24] != 0) ++bad;
                    if (d->tables[2]
                        .values[25] != 0) ++bad;
                    if (d->tables[2]
                        .values[26] != 0) ++bad;
                    if (d->tables[2]
                        .values[27] != 0) ++bad;
                    if (d->tables[2]
                        .values[28] != 0) ++bad;
                    if (d->tables[2]
                        .values[29] != 1) ++bad;
                    if (d->tables[3]
                        .values[0] != 6) ++bad;
                    if (d->tables[3]
                        .values[1] != 8) ++bad;
                    if (d->tables[3]
                        .values[2] != 10) ++bad;
                    if (d->tables[3]
                        .values[3] != 11) ++bad;
                    if (d->tables[3]
                        .values[4] != 13) ++bad;
                    if (d->tables[3]
                        .values[5] != 14) ++bad;
                    if (d->tables[3]
                        .values[6] != 18) ++bad;
                    if (d->tables[3]
                        .values[7] != 27) ++bad;
                    if (d->tables[3]
                        .values[8] != 30) ++bad;
                    if (d->tables[3]
                        .values[9] != 32) ++bad;
                    if (d->tables[3]
                        .values[10] != 55) ++bad;
                    if (d->tables[3]
                        .values[11] != 60) ++bad;
                    if (d->tables[3]
                        .values[12] != 61) ++bad;
                    if (d->tables[3]
                        .values[13] != 63) ++bad;
                    if (d->tables[3]
                        .values[14] != 65) ++bad;
                    if (d->tables[3]
                        .values[15] != 67) ++bad;
                    if (d->tables[3]
                        .values[16] != 69) ++bad;
                    if (d->tables[3]
                        .values[17] != 72) ++bad;
                    if (d->tables[3]
                        .values[18] != 76) ++bad;
                    if (d->tables[3]
                        .values[19] != 77) ++bad;
                    if (d->tables[3]
                        .values[20] != 79) ++bad;
                    if (d->tables[3]
                        .values[21] != 85) ++bad;
                    if (d->tables[3]
                        .values[22] != 91) ++bad;
                    if (d->tables[3]
                        .values[23] != 92) ++bad;
                    if (d->tables[3]
                        .values[24] != 93) ++bad;
                    if (d->tables[3]
                        .values[25] != 94) ++bad;
                    if (d->tables[3]
                        .values[26] != 95) ++bad;
                    if (d->tables[3]
                        .values[27] != 97) ++bad;
                    if (d->tables[3]
                        .values[28] != 99) ++bad;
                    if (d->tables[3]
                        .values[29] != 100) ++bad;
                    if (d->tables[4]
                        .values[0] != 1) ++bad;
                    if (d->tables[4]
                        .values[1] != 7) ++bad;
                    if (d->tables[4]
                        .values[2] != 9) ++bad;
                    if (d->tables[4]
                        .values[3] != 11) ++bad;
                    if (d->tables[4]
                        .values[4] != 12) ++bad;
                    if (d->tables[4]
                        .values[5] != 14) ++bad;
                    if (d->tables[4]
                        .values[6] != 15) ++bad;
                    if (d->tables[4]
                        .values[7] != 19) ++bad;
                    if (d->tables[4]
                        .values[8] != 28) ++bad;
                    if (d->tables[4]
                        .values[9] != 31) ++bad;
                    if (d->tables[4]
                        .values[10] != 33) ++bad;
                    if (d->tables[4]
                        .values[11] != 56) ++bad;
                    if (d->tables[4]
                        .values[12] != 61) ++bad;
                    if (d->tables[4]
                        .values[13] != 62) ++bad;
                    if (d->tables[4]
                        .values[14] != 64) ++bad;
                    if (d->tables[4]
                        .values[15] != 66) ++bad;
                    if (d->tables[4]
                        .values[16] != 68) ++bad;
                    if (d->tables[4]
                        .values[17] != 70) ++bad;
                    if (d->tables[4]
                        .values[18] != 73) ++bad;
                    if (d->tables[4]
                        .values[19] != 77) ++bad;
                    if (d->tables[4]
                        .values[20] != 78) ++bad;
                    if (d->tables[4]
                        .values[21] != 80) ++bad;
                    if (d->tables[4]
                        .values[22] != 86) ++bad;
                    if (d->tables[4]
                        .values[23] != 92) ++bad;
                    if (d->tables[4]
                        .values[24] != 93) ++bad;
                    if (d->tables[4]
                        .values[25] != 94) ++bad;
                    if (d->tables[4]
                        .values[26] != 95) ++bad;
                    if (d->tables[4]
                        .values[27] != 96) ++bad;
                    if (d->tables[4]
                        .values[28] != 98) ++bad;
                    if (d->tables[4]
                        .values[29] != 100) ++bad;
                    if (d->tables[5]
                        .values[0] != 1) ++bad;
                    if (d->tables[5]
                        .values[1] != 0) ++bad;
                    if (d->tables[5]
                        .values[2] != 0) ++bad;
                    if (d->tables[5]
                        .values[3] != 0) ++bad;
                    if (d->tables[5]
                        .values[4] != 0) ++bad;
                    if (d->tables[5]
                        .values[5] != 0) ++bad;
                    if (d->tables[5]
                        .values[6] != 0) ++bad;
                    if (d->tables[5]
                        .values[7] != 0) ++bad;
                    if (d->tables[5]
                        .values[8] != 0) ++bad;
                    if (d->tables[5]
                        .values[9] != 0) ++bad;
                    if (d->tables[5]
                        .values[10] != 0) ++bad;
                    if (d->tables[5]
                        .values[11] != 0) ++bad;
                    if (d->tables[5]
                        .values[12] != 0) ++bad;
                    if (d->tables[5]
                        .values[13] != 0) ++bad;
                    if (d->tables[5]
                        .values[14] != 0) ++bad;
                    if (d->tables[5]
                        .values[15] != 0) ++bad;
                    if (d->tables[5]
                        .values[16] != 0) ++bad;
                    if (d->tables[5]
                        .values[17] != 0) ++bad;
                    if (d->tables[5]
                        .values[18] != 0) ++bad;
                    if (d->tables[5]
                        .values[19] != 0) ++bad;
                    if (d->tables[5]
                        .values[20] != 0) ++bad;
                    if (d->tables[5]
                        .values[21] != 0) ++bad;
                    if (d->tables[5]
                        .values[22] != 0) ++bad;
                    if (d->tables[5]
                        .values[23] != 0) ++bad;
                    if (d->tables[5]
                        .values[24] != 0) ++bad;
                    if (d->tables[5]
                        .values[25] != 0) ++bad;
                    if (d->tables[5]
                        .values[26] != 0) ++bad;
                    if (d->tables[5]
                        .values[27] != 0) ++bad;
                    if (d->tables[5]
                        .values[28] != 0) ++bad;
                    if (d->tables[5]
                        .values[29] != 0) ++bad;
                    if (d->tables[6]
                        .values[0] != 0) ++bad;
                    if (d->tables[6]
                        .values[1] != 0) ++bad;
                    if (d->tables[6]
                        .values[2] != 1) ++bad;
                    if (d->tables[6]
                        .values[3] != 1) ++bad;
                    if (d->tables[6]
                        .values[4] != 0) ++bad;
                    if (d->tables[6]
                        .values[5] != 0) ++bad;
                    if (d->tables[6]
                        .values[6] != 0) ++bad;
                    if (d->tables[6]
                        .values[7] != 0) ++bad;
                    if (d->tables[6]
                        .values[8] != 0) ++bad;
                    if (d->tables[6]
                        .values[9] != 0) ++bad;
                    if (d->tables[6]
                        .values[10] != 0) ++bad;
                    if (d->tables[6]
                        .values[11] != 1) ++bad;
                    if (d->tables[6]
                        .values[12] != 1) ++bad;
                    if (d->tables[6]
                        .values[13] != 0) ++bad;
                    if (d->tables[6]
                        .values[14] != 0) ++bad;
                    if (d->tables[6]
                        .values[15] != 0) ++bad;
                    if (d->tables[6]
                        .values[16] != 0) ++bad;
                    if (d->tables[6]
                        .values[17] != 0) ++bad;
                    if (d->tables[6]
                        .values[18] != 0) ++bad;
                    if (d->tables[6]
                        .values[19] != 0) ++bad;
                    if (d->tables[6]
                        .values[20] != 0) ++bad;
                    if (d->tables[6]
                        .values[21] != 0) ++bad;
                    if (d->tables[6]
                        .values[22] != 0) ++bad;
                    if (d->tables[6]
                        .values[23] != 0) ++bad;
                    if (d->tables[6]
                        .values[24] != 0) ++bad;
                    if (d->tables[6]
                        .values[25] != 0) ++bad;
                    if (d->tables[6]
                        .values[26] != 1) ++bad;
                    if (d->tables[6]
                        .values[27] != 0) ++bad;
                    if (d->tables[6]
                        .values[28] != 0) ++bad;
                    if (d->tables[6]
                        .values[29] != 0) ++bad;
                    if (rules::m2RowLo(0) != 1) ++bad;
                    if (rules::m2RowLo(1) != 7) ++bad;
                    if (rules::m2RowLo(2) != 9) ++bad;
                    if (rules::m2RowLo(3) != 11) ++bad;
                    if (rules::m2RowLo(4) != 12) ++bad;
                    if (rules::m2RowLo(5) != 14) ++bad;
                    if (rules::m2RowLo(6) != 15) ++bad;
                    if (rules::m2RowLo(7) != 19) ++bad;
                    if (rules::m2RowLo(8) != 28) ++bad;
                    if (rules::m2RowLo(9) != 31) ++bad;
                    if (rules::m2RowLo(10) != 33) ++bad;
                    if (rules::m2RowLo(11) != 56) ++bad;
                    if (rules::m2RowLo(12) != 61) ++bad;
                    if (rules::m2RowLo(13) != 62) ++bad;
                    if (rules::m2RowLo(14) != 64) ++bad;
                    if (rules::m2RowLo(15) != 66) ++bad;
                    if (rules::m2RowLo(16) != 68) ++bad;
                    if (rules::m2RowLo(17) != 70) ++bad;
                    if (rules::m2RowLo(18) != 73) ++bad;
                    if (rules::m2RowLo(19) != 77) ++bad;
                    if (rules::m2RowLo(20) != 78) ++bad;
                    if (rules::m2RowLo(21) != 80) ++bad;
                    if (rules::m2RowLo(22) != 86) ++bad;
                    if (rules::m2RowLo(23) != 92) ++bad;
                    if (rules::m2RowLo(24) != 93) ++bad;
                    if (rules::m2RowLo(25) != 94) ++bad;
                    if (rules::m2RowLo(26) != 95) ++bad;
                    if (rules::m2RowLo(27) != 96) ++bad;
                    if (rules::m2RowLo(28) != 98) ++bad;
                    if (rules::m2RowLo(29) != 100) ++bad;
                    if (rules::m2RowHi(0) != 6) ++bad;
                    if (rules::m2RowHi(1) != 8) ++bad;
                    if (rules::m2RowHi(2) != 10) ++bad;
                    if (rules::m2RowHi(3) != 11) ++bad;
                    if (rules::m2RowHi(4) != 13) ++bad;
                    if (rules::m2RowHi(5) != 14) ++bad;
                    if (rules::m2RowHi(6) != 18) ++bad;
                    if (rules::m2RowHi(7) != 27) ++bad;
                    if (rules::m2RowHi(8) != 30) ++bad;
                    if (rules::m2RowHi(9) != 32) ++bad;
                    if (rules::m2RowHi(10) != 55) ++bad;
                    if (rules::m2RowHi(11) != 60) ++bad;
                    if (rules::m2RowHi(12) != 61) ++bad;
                    if (rules::m2RowHi(13) != 63) ++bad;
                    if (rules::m2RowHi(14) != 65) ++bad;
                    if (rules::m2RowHi(15) != 67) ++bad;
                    if (rules::m2RowHi(16) != 69) ++bad;
                    if (rules::m2RowHi(17) != 72) ++bad;
                    if (rules::m2RowHi(18) != 76) ++bad;
                    if (rules::m2RowHi(19) != 77) ++bad;
                    if (rules::m2RowHi(20) != 79) ++bad;
                    if (rules::m2RowHi(21) != 85) ++bad;
                    if (rules::m2RowHi(22) != 91) ++bad;
                    if (rules::m2RowHi(23) != 92) ++bad;
                    if (rules::m2RowHi(24) != 93) ++bad;
                    if (rules::m2RowHi(25) != 94) ++bad;
                    if (rules::m2RowHi(26) != 95) ++bad;
                    if (rules::m2RowHi(27) != 97) ++bad;
                    if (rules::m2RowHi(28) != 99) ++bad;
                    if (rules::m2RowHi(29) != 100) ++bad;
                    if (rules::m2UsableByCleric(0) != 1) ++bad;
                    if (rules::m2UsableByCleric(1) != 0) ++bad;
                    if (rules::m2UsableByCleric(2) != 0) ++bad;
                    if (rules::m2UsableByCleric(3) != 0) ++bad;
                    if (rules::m2UsableByCleric(4) != 0) ++bad;
                    if (rules::m2UsableByCleric(5) != 0) ++bad;
                    if (rules::m2UsableByCleric(6) != 0) ++bad;
                    if (rules::m2UsableByCleric(7) != 0) ++bad;
                    if (rules::m2UsableByCleric(8) != 0) ++bad;
                    if (rules::m2UsableByCleric(9) != 0) ++bad;
                    if (rules::m2UsableByCleric(10) != 0) ++bad;
                    if (rules::m2UsableByCleric(11) != 0) ++bad;
                    if (rules::m2UsableByCleric(12) != 0) ++bad;
                    if (rules::m2UsableByCleric(13) != 0) ++bad;
                    if (rules::m2UsableByCleric(14) != 0) ++bad;
                    if (rules::m2UsableByCleric(15) != 0) ++bad;
                    if (rules::m2UsableByCleric(16) != 0) ++bad;
                    if (rules::m2UsableByCleric(17) != 0) ++bad;
                    if (rules::m2UsableByCleric(18) != 0) ++bad;
                    if (rules::m2UsableByCleric(19) != 0) ++bad;
                    if (rules::m2UsableByCleric(20) != 0) ++bad;
                    if (rules::m2UsableByCleric(21) != 0) ++bad;
                    if (rules::m2UsableByCleric(22) != 0) ++bad;
                    if (rules::m2UsableByCleric(23) != 0) ++bad;
                    if (rules::m2UsableByCleric(24) != 0) ++bad;
                    if (rules::m2UsableByCleric(25) != 0) ++bad;
                    if (rules::m2UsableByCleric(26) != 0) ++bad;
                    if (rules::m2UsableByCleric(27) != 0) ++bad;
                    if (rules::m2UsableByCleric(28) != 0) ++bad;
                    if (rules::m2UsableByCleric(29) != 0) ++bad;
                    if (rules::m2UsableByMagicUser(0) != 0) ++bad;
                    if (rules::m2UsableByMagicUser(1) != 0) ++bad;
                    if (rules::m2UsableByMagicUser(2) != 1) ++bad;
                    if (rules::m2UsableByMagicUser(3) != 1) ++bad;
                    if (rules::m2UsableByMagicUser(4) != 0) ++bad;
                    if (rules::m2UsableByMagicUser(5) != 0) ++bad;
                    if (rules::m2UsableByMagicUser(6) != 0) ++bad;
                    if (rules::m2UsableByMagicUser(7) != 0) ++bad;
                    if (rules::m2UsableByMagicUser(8) != 0) ++bad;
                    if (rules::m2UsableByMagicUser(9) != 0) ++bad;
                    if (rules::m2UsableByMagicUser(10) != 0) ++bad;
                    if (rules::m2UsableByMagicUser(11) != 1) ++bad;
                    if (rules::m2UsableByMagicUser(12) != 1) ++bad;
                    if (rules::m2UsableByMagicUser(13) != 0) ++bad;
                    if (rules::m2UsableByMagicUser(14) != 0) ++bad;
                    if (rules::m2UsableByMagicUser(15) != 0) ++bad;
                    if (rules::m2UsableByMagicUser(16) != 0) ++bad;
                    if (rules::m2UsableByMagicUser(17) != 0) ++bad;
                    if (rules::m2UsableByMagicUser(18) != 0) ++bad;
                    if (rules::m2UsableByMagicUser(19) != 0) ++bad;
                    if (rules::m2UsableByMagicUser(20) != 0) ++bad;
                    if (rules::m2UsableByMagicUser(21) != 0) ++bad;
                    if (rules::m2UsableByMagicUser(22) != 0) ++bad;
                    if (rules::m2UsableByMagicUser(23) != 0) ++bad;
                    if (rules::m2UsableByMagicUser(24) != 0) ++bad;
                    if (rules::m2UsableByMagicUser(25) != 0) ++bad;
                    if (rules::m2UsableByMagicUser(26) != 1) ++bad;
                    if (rules::m2UsableByMagicUser(27) != 0) ++bad;
                    if (rules::m2UsableByMagicUser(28) != 0) ++bad;
                    if (rules::m2UsableByMagicUser(29) != 0) ++bad;
                    if (rules::m2IsPerPlusValued(0) != 0) ++bad;
                    if (rules::m2IsPerPlusValued(1) != 0) ++bad;
                    if (rules::m2IsPerPlusValued(2) != 0) ++bad;
                    if (rules::m2IsPerPlusValued(3) != 0) ++bad;
                    if (rules::m2IsPerPlusValued(4) != 0) ++bad;
                    if (rules::m2IsPerPlusValued(5) != 0) ++bad;
                    if (rules::m2IsPerPlusValued(6) != 0) ++bad;
                    if (rules::m2IsPerPlusValued(7) != 0) ++bad;
                    if (rules::m2IsPerPlusValued(8) != 0) ++bad;
                    if (rules::m2IsPerPlusValued(9) != 0) ++bad;
                    if (rules::m2IsPerPlusValued(10) != 1) ++bad;
                    if (rules::m2IsPerPlusValued(11) != 0) ++bad;
                    if (rules::m2IsPerPlusValued(12) != 0) ++bad;
                    if (rules::m2IsPerPlusValued(13) != 0) ++bad;
                    if (rules::m2IsPerPlusValued(14) != 0) ++bad;
                    if (rules::m2IsPerPlusValued(15) != 0) ++bad;
                    if (rules::m2IsPerPlusValued(16) != 0) ++bad;
                    if (rules::m2IsPerPlusValued(17) != 0) ++bad;
                    if (rules::m2IsPerPlusValued(18) != 0) ++bad;
                    if (rules::m2IsPerPlusValued(19) != 0) ++bad;
                    if (rules::m2IsPerPlusValued(20) != 0) ++bad;
                    if (rules::m2IsPerPlusValued(21) != 0) ++bad;
                    if (rules::m2IsPerPlusValued(22) != 0) ++bad;
                    if (rules::m2IsPerPlusValued(23) != 0) ++bad;
                    if (rules::m2IsPerPlusValued(24) != 0) ++bad;
                    if (rules::m2IsPerPlusValued(25) != 0) ++bad;
                    if (rules::m2IsPerPlusValued(26) != 0) ++bad;
                    if (rules::m2IsPerPlusValued(27) != 0) ++bad;
                    if (rules::m2IsPerPlusValued(28) != 0) ++bad;
                    if (rules::m2IsPerPlusValued(29) != 0) ++bad;
                    if (rules::m2HasFeatureAsterisk(0) != 0) ++bad;
                    if (rules::m2HasFeatureAsterisk(1) != 0) ++bad;
                    if (rules::m2HasFeatureAsterisk(2) != 0) ++bad;
                    if (rules::m2HasFeatureAsterisk(3) != 0) ++bad;
                    if (rules::m2HasFeatureAsterisk(4) != 0) ++bad;
                    if (rules::m2HasFeatureAsterisk(5) != 0) ++bad;
                    if (rules::m2HasFeatureAsterisk(6) != 0) ++bad;
                    if (rules::m2HasFeatureAsterisk(7) != 0) ++bad;
                    if (rules::m2HasFeatureAsterisk(8) != 0) ++bad;
                    if (rules::m2HasFeatureAsterisk(9) != 0) ++bad;
                    if (rules::m2HasFeatureAsterisk(10) != 0) ++bad;
                    if (rules::m2HasFeatureAsterisk(11) != 1) ++bad;
                    if (rules::m2HasFeatureAsterisk(12) != 0) ++bad;
                    if (rules::m2HasFeatureAsterisk(13) != 0) ++bad;
                    if (rules::m2HasFeatureAsterisk(14) != 0) ++bad;
                    if (rules::m2HasFeatureAsterisk(15) != 0) ++bad;
                    if (rules::m2HasFeatureAsterisk(16) != 0) ++bad;
                    if (rules::m2HasFeatureAsterisk(17) != 0) ++bad;
                    if (rules::m2HasFeatureAsterisk(18) != 0) ++bad;
                    if (rules::m2HasFeatureAsterisk(19) != 0) ++bad;
                    if (rules::m2HasFeatureAsterisk(20) != 0) ++bad;
                    if (rules::m2HasFeatureAsterisk(21) != 0) ++bad;
                    if (rules::m2HasFeatureAsterisk(22) != 0) ++bad;
                    if (rules::m2HasFeatureAsterisk(23) != 0) ++bad;
                    if (rules::m2HasFeatureAsterisk(24) != 0) ++bad;
                    if (rules::m2HasFeatureAsterisk(25) != 0) ++bad;
                    if (rules::m2HasFeatureAsterisk(26) != 0) ++bad;
                    if (rules::m2HasFeatureAsterisk(27) != 0) ++bad;
                    if (rules::m2HasFeatureAsterisk(28) != 0) ++bad;
                    if (rules::m2HasFeatureAsterisk(29) != 0) ++bad;
                    if (rules::m2IsTripleStar(0) != 0) ++bad;
                    if (rules::m2IsTripleStar(1) != 0) ++bad;
                    if (rules::m2IsTripleStar(2) != 0) ++bad;
                    if (rules::m2IsTripleStar(3) != 0) ++bad;
                    if (rules::m2IsTripleStar(4) != 0) ++bad;
                    if (rules::m2IsTripleStar(5) != 0) ++bad;
                    if (rules::m2IsTripleStar(6) != 0) ++bad;
                    if (rules::m2IsTripleStar(7) != 0) ++bad;
                    if (rules::m2IsTripleStar(8) != 0) ++bad;
                    if (rules::m2IsTripleStar(9) != 0) ++bad;
                    if (rules::m2IsTripleStar(10) != 0) ++bad;
                    if (rules::m2IsTripleStar(11) != 0) ++bad;
                    if (rules::m2IsTripleStar(12) != 0) ++bad;
                    if (rules::m2IsTripleStar(13) != 0) ++bad;
                    if (rules::m2IsTripleStar(14) != 0) ++bad;
                    if (rules::m2IsTripleStar(15) != 0) ++bad;
                    if (rules::m2IsTripleStar(16) != 0) ++bad;
                    if (rules::m2IsTripleStar(17) != 0) ++bad;
                    if (rules::m2IsTripleStar(18) != 0) ++bad;
                    if (rules::m2IsTripleStar(19) != 0) ++bad;
                    if (rules::m2IsTripleStar(20) != 0) ++bad;
                    if (rules::m2IsTripleStar(21) != 0) ++bad;
                    if (rules::m2IsTripleStar(22) != 0) ++bad;
                    if (rules::m2IsTripleStar(23) != 0) ++bad;
                    if (rules::m2IsTripleStar(24) != 0) ++bad;
                    if (rules::m2IsTripleStar(25) != 0) ++bad;
                    if (rules::m2IsTripleStar(26) != 0) ++bad;
                    if (rules::m2IsTripleStar(27) != 0) ++bad;
                    if (rules::m2IsTripleStar(28) != 0) ++bad;
                    if (rules::m2IsTripleStar(29) != 1) ++bad;
                }
            }
        }
        printf("R1059 misc-magic registry defs-A audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 4. B -----------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/miscmagic");
            {
                const items::MiscItemDef* d =
                    reg.find("misc_m3");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 0) ++bad;
                    if (d->tables[0]
                        .values[1] != 0) ++bad;
                    if (d->tables[0]
                        .values[2] != 0) ++bad;
                    if (d->tables[0]
                        .values[3] != 0) ++bad;
                    if (d->tables[0]
                        .values[4] != 0) ++bad;
                    if (d->tables[0]
                        .values[5] != 0) ++bad;
                    if (d->tables[0]
                        .values[6] != 0) ++bad;
                    if (d->tables[0]
                        .values[7] != 0) ++bad;
                    if (d->tables[0]
                        .values[8] != 0) ++bad;
                    if (d->tables[0]
                        .values[9] != 0) ++bad;
                    if (d->tables[0]
                        .values[10] != 0) ++bad;
                    if (d->tables[0]
                        .values[11] != 0) ++bad;
                    if (d->tables[0]
                        .values[12] != 0) ++bad;
                    if (d->tables[0]
                        .values[13] != 0) ++bad;
                    if (d->tables[0]
                        .values[14] != 0) ++bad;
                    if (d->tables[0]
                        .values[15] != 0) ++bad;
                    if (d->tables[0]
                        .values[16] != 0) ++bad;
                    if (d->tables[0]
                        .values[17] != 0) ++bad;
                    if (d->tables[0]
                        .values[18] != 0) ++bad;
                    if (d->tables[0]
                        .values[19] != 0) ++bad;
                    if (d->tables[0]
                        .values[20] != 0) ++bad;
                    if (d->tables[0]
                        .values[21] != 0) ++bad;
                    if (d->tables[0]
                        .values[22] != 0) ++bad;
                    if (d->tables[0]
                        .values[23] != 0) ++bad;
                    if (d->tables[0]
                        .values[24] != 0) ++bad;
                    if (d->tables[0]
                        .values[25] != 0) ++bad;
                    if (d->tables[0]
                        .values[26] != 0) ++bad;
                    if (d->tables[0]
                        .values[27] != 0) ++bad;
                    if (d->tables[0]
                        .values[28] != 0) ++bad;
                    if (d->tables[0]
                        .values[29] != 0) ++bad;
                    if (d->tables[0]
                        .values[30] != 0) ++bad;
                    if (d->tables[0]
                        .values[31] != 1) ++bad;
                    if (d->tables[0]
                        .values[32] != 0) ++bad;
                    if (d->tables[1]
                        .values[0] != 15) ++bad;
                    if (d->tables[1]
                        .values[1] != 16) ++bad;
                    if (d->tables[1]
                        .values[2] != 18) ++bad;
                    if (d->tables[1]
                        .values[3] != 20) ++bad;
                    if (d->tables[1]
                        .values[4] != 22) ++bad;
                    if (d->tables[1]
                        .values[5] != 25) ++bad;
                    if (d->tables[1]
                        .values[6] != 26) ++bad;
                    if (d->tables[1]
                        .values[7] != 27) ++bad;
                    if (d->tables[1]
                        .values[8] != 28) ++bad;
                    if (d->tables[1]
                        .values[9] != 29) ++bad;
                    if (d->tables[1]
                        .values[10] != 30) ++bad;
                    if (d->tables[1]
                        .values[11] != 35) ++bad;
                    if (d->tables[1]
                        .values[12] != 37) ++bad;
                    if (d->tables[1]
                        .values[13] != 39) ++bad;
                    if (d->tables[1]
                        .values[14] != 40) ++bad;
                    if (d->tables[1]
                        .values[15] != 45) ++bad;
                    if (d->tables[1]
                        .values[16] != 46) ++bad;
                    if (d->tables[1]
                        .values[17] != 48) ++bad;
                    if (d->tables[1]
                        .values[18] != 49) ++bad;
                    if (d->tables[1]
                        .values[19] != 53) ++bad;
                    if (d->tables[1]
                        .values[20] != 60) ++bad;
                    if (d->tables[1]
                        .values[21] != 63) ++bad;
                    if (d->tables[1]
                        .values[22] != 65) ++bad;
                    if (d->tables[1]
                        .values[23] != 70) ++bad;
                    if (d->tables[1]
                        .values[24] != 71) ++bad;
                    if (d->tables[1]
                        .values[25] != 72) ++bad;
                    if (d->tables[1]
                        .values[26] != 78) ++bad;
                    if (d->tables[1]
                        .values[27] != 80) ++bad;
                    if (d->tables[1]
                        .values[28] != 85) ++bad;
                    if (d->tables[1]
                        .values[29] != 90) ++bad;
                    if (d->tables[1]
                        .values[30] != 91) ++bad;
                    if (d->tables[1]
                        .values[31] != 92) ++bad;
                    if (d->tables[1]
                        .values[32] != 100) ++bad;
                    if (d->tables[2]
                        .values[0] != 1) ++bad;
                    if (d->tables[2]
                        .values[1] != 16) ++bad;
                    if (d->tables[2]
                        .values[2] != 17) ++bad;
                    if (d->tables[2]
                        .values[3] != 19) ++bad;
                    if (d->tables[2]
                        .values[4] != 21) ++bad;
                    if (d->tables[2]
                        .values[5] != 23) ++bad;
                    if (d->tables[2]
                        .values[6] != 26) ++bad;
                    if (d->tables[2]
                        .values[7] != 27) ++bad;
                    if (d->tables[2]
                        .values[8] != 28) ++bad;
                    if (d->tables[2]
                        .values[9] != 29) ++bad;
                    if (d->tables[2]
                        .values[10] != 30) ++bad;
                    if (d->tables[2]
                        .values[11] != 31) ++bad;
                    if (d->tables[2]
                        .values[12] != 36) ++bad;
                    if (d->tables[2]
                        .values[13] != 38) ++bad;
                    if (d->tables[2]
                        .values[14] != 40) ++bad;
                    if (d->tables[2]
                        .values[15] != 41) ++bad;
                    if (d->tables[2]
                        .values[16] != 46) ++bad;
                    if (d->tables[2]
                        .values[17] != 47) ++bad;
                    if (d->tables[2]
                        .values[18] != 49) ++bad;
                    if (d->tables[2]
                        .values[19] != 50) ++bad;
                    if (d->tables[2]
                        .values[20] != 54) ++bad;
                    if (d->tables[2]
                        .values[21] != 61) ++bad;
                    if (d->tables[2]
                        .values[22] != 64) ++bad;
                    if (d->tables[2]
                        .values[23] != 66) ++bad;
                    if (d->tables[2]
                        .values[24] != 71) ++bad;
                    if (d->tables[2]
                        .values[25] != 72) ++bad;
                    if (d->tables[2]
                        .values[26] != 73) ++bad;
                    if (d->tables[2]
                        .values[27] != 79) ++bad;
                    if (d->tables[2]
                        .values[28] != 81) ++bad;
                    if (d->tables[2]
                        .values[29] != 86) ++bad;
                    if (d->tables[2]
                        .values[30] != 91) ++bad;
                    if (d->tables[2]
                        .values[31] != 92) ++bad;
                    if (d->tables[2]
                        .values[32] != 93) ++bad;
                    if (d->tables[3]
                        .values[0] != 1) ++bad;
                    if (d->tables[3]
                        .values[1] != 0) ++bad;
                    if (d->tables[3]
                        .values[2] != 0) ++bad;
                    if (d->tables[3]
                        .values[3] != 0) ++bad;
                    if (d->tables[3]
                        .values[4] != 0) ++bad;
                    if (d->tables[3]
                        .values[5] != 0) ++bad;
                    if (d->tables[3]
                        .values[6] != 0) ++bad;
                    if (d->tables[3]
                        .values[7] != 0) ++bad;
                    if (d->tables[3]
                        .values[8] != 0) ++bad;
                    if (d->tables[3]
                        .values[9] != 0) ++bad;
                    if (d->tables[3]
                        .values[10] != 0) ++bad;
                    if (d->tables[3]
                        .values[11] != 0) ++bad;
                    if (d->tables[3]
                        .values[12] != 0) ++bad;
                    if (d->tables[3]
                        .values[13] != 0) ++bad;
                    if (d->tables[3]
                        .values[14] != 0) ++bad;
                    if (d->tables[3]
                        .values[15] != 0) ++bad;
                    if (d->tables[3]
                        .values[16] != 0) ++bad;
                    if (d->tables[3]
                        .values[17] != 0) ++bad;
                    if (d->tables[3]
                        .values[18] != 0) ++bad;
                    if (d->tables[3]
                        .values[19] != 0) ++bad;
                    if (d->tables[3]
                        .values[20] != 2) ++bad;
                    if (d->tables[3]
                        .values[21] != 0) ++bad;
                    if (d->tables[3]
                        .values[22] != 0) ++bad;
                    if (d->tables[3]
                        .values[23] != 0) ++bad;
                    if (d->tables[3]
                        .values[24] != 0) ++bad;
                    if (d->tables[3]
                        .values[25] != 3) ++bad;
                    if (d->tables[3]
                        .values[26] != 4) ++bad;
                    if (d->tables[3]
                        .values[27] != 0) ++bad;
                    if (d->tables[3]
                        .values[28] != 0) ++bad;
                    if (d->tables[3]
                        .values[29] != 0) ++bad;
                    if (d->tables[3]
                        .values[30] != 0) ++bad;
                    if (d->tables[3]
                        .values[31] != 0) ++bad;
                    if (d->tables[3]
                        .values[32] != 0) ++bad;
                    if (d->tables[4]
                        .values[0] != 0) ++bad;
                    if (d->tables[4]
                        .values[1] != 0) ++bad;
                    if (d->tables[4]
                        .values[2] != 0) ++bad;
                    if (d->tables[4]
                        .values[3] != 0) ++bad;
                    if (d->tables[4]
                        .values[4] != 1) ++bad;
                    if (d->tables[4]
                        .values[5] != 1) ++bad;
                    if (d->tables[4]
                        .values[6] != 0) ++bad;
                    if (d->tables[4]
                        .values[7] != 0) ++bad;
                    if (d->tables[4]
                        .values[8] != 1) ++bad;
                    if (d->tables[4]
                        .values[9] != 1) ++bad;
                    if (d->tables[4]
                        .values[10] != 0) ++bad;
                    if (d->tables[4]
                        .values[11] != 0) ++bad;
                    if (d->tables[4]
                        .values[12] != 0) ++bad;
                    if (d->tables[4]
                        .values[13] != 0) ++bad;
                    if (d->tables[4]
                        .values[14] != 0) ++bad;
                    if (d->tables[4]
                        .values[15] != 0) ++bad;
                    if (d->tables[4]
                        .values[16] != 0) ++bad;
                    if (d->tables[4]
                        .values[17] != 0) ++bad;
                    if (d->tables[4]
                        .values[18] != 0) ++bad;
                    if (d->tables[4]
                        .values[19] != 1) ++bad;
                    if (d->tables[4]
                        .values[20] != 0) ++bad;
                    if (d->tables[4]
                        .values[21] != 0) ++bad;
                    if (d->tables[4]
                        .values[22] != 0) ++bad;
                    if (d->tables[4]
                        .values[23] != 1) ++bad;
                    if (d->tables[4]
                        .values[24] != 1) ++bad;
                    if (d->tables[4]
                        .values[25] != 0) ++bad;
                    if (d->tables[4]
                        .values[26] != 0) ++bad;
                    if (d->tables[4]
                        .values[27] != 0) ++bad;
                    if (d->tables[4]
                        .values[28] != 0) ++bad;
                    if (d->tables[4]
                        .values[29] != 0) ++bad;
                    if (d->tables[4]
                        .values[30] != 0) ++bad;
                    if (d->tables[4]
                        .values[31] != 0) ++bad;
                    if (d->tables[4]
                        .values[32] != 0) ++bad;
                    if (d->tables[5]
                        .values[0] != 0) ++bad;
                    if (d->tables[5]
                        .values[1] != 0) ++bad;
                    if (d->tables[5]
                        .values[2] != 0) ++bad;
                    if (d->tables[5]
                        .values[3] != 0) ++bad;
                    if (d->tables[5]
                        .values[4] != 1) ++bad;
                    if (d->tables[5]
                        .values[5] != 1) ++bad;
                    if (d->tables[5]
                        .values[6] != 0) ++bad;
                    if (d->tables[5]
                        .values[7] != 0) ++bad;
                    if (d->tables[5]
                        .values[8] != 1) ++bad;
                    if (d->tables[5]
                        .values[9] != 1) ++bad;
                    if (d->tables[5]
                        .values[10] != 0) ++bad;
                    if (d->tables[5]
                        .values[11] != 0) ++bad;
                    if (d->tables[5]
                        .values[12] != 0) ++bad;
                    if (d->tables[5]
                        .values[13] != 0) ++bad;
                    if (d->tables[5]
                        .values[14] != 0) ++bad;
                    if (d->tables[5]
                        .values[15] != 0) ++bad;
                    if (d->tables[5]
                        .values[16] != 0) ++bad;
                    if (d->tables[5]
                        .values[17] != 0) ++bad;
                    if (d->tables[5]
                        .values[18] != 0) ++bad;
                    if (d->tables[5]
                        .values[19] != 1) ++bad;
                    if (d->tables[5]
                        .values[20] != 0) ++bad;
                    if (d->tables[5]
                        .values[21] != 0) ++bad;
                    if (d->tables[5]
                        .values[22] != 0) ++bad;
                    if (d->tables[5]
                        .values[23] != 0) ++bad;
                    if (d->tables[5]
                        .values[24] != 0) ++bad;
                    if (d->tables[5]
                        .values[25] != 0) ++bad;
                    if (d->tables[5]
                        .values[26] != 0) ++bad;
                    if (d->tables[5]
                        .values[27] != 0) ++bad;
                    if (d->tables[5]
                        .values[28] != 1) ++bad;
                    if (d->tables[5]
                        .values[29] != 1) ++bad;
                    if (d->tables[5]
                        .values[30] != 0) ++bad;
                    if (d->tables[5]
                        .values[31] != 0) ++bad;
                    if (d->tables[5]
                        .values[32] != 0) ++bad;
                    if (d->tables[6]
                        .values[0] != 0) ++bad;
                    if (d->tables[6]
                        .values[1] != 0) ++bad;
                    if (d->tables[6]
                        .values[2] != 0) ++bad;
                    if (d->tables[6]
                        .values[3] != 0) ++bad;
                    if (d->tables[6]
                        .values[4] != 1) ++bad;
                    if (d->tables[6]
                        .values[5] != 1) ++bad;
                    if (d->tables[6]
                        .values[6] != 0) ++bad;
                    if (d->tables[6]
                        .values[7] != 0) ++bad;
                    if (d->tables[6]
                        .values[8] != 1) ++bad;
                    if (d->tables[6]
                        .values[9] != 1) ++bad;
                    if (d->tables[6]
                        .values[10] != 0) ++bad;
                    if (d->tables[6]
                        .values[11] != 0) ++bad;
                    if (d->tables[6]
                        .values[12] != 0) ++bad;
                    if (d->tables[6]
                        .values[13] != 0) ++bad;
                    if (d->tables[6]
                        .values[14] != 0) ++bad;
                    if (d->tables[6]
                        .values[15] != 0) ++bad;
                    if (d->tables[6]
                        .values[16] != 0) ++bad;
                    if (d->tables[6]
                        .values[17] != 0) ++bad;
                    if (d->tables[6]
                        .values[18] != 0) ++bad;
                    if (d->tables[6]
                        .values[19] != 0) ++bad;
                    if (d->tables[6]
                        .values[20] != 0) ++bad;
                    if (d->tables[6]
                        .values[21] != 0) ++bad;
                    if (d->tables[6]
                        .values[22] != 0) ++bad;
                    if (d->tables[6]
                        .values[23] != 0) ++bad;
                    if (d->tables[6]
                        .values[24] != 0) ++bad;
                    if (d->tables[6]
                        .values[25] != 0) ++bad;
                    if (d->tables[6]
                        .values[26] != 0) ++bad;
                    if (d->tables[6]
                        .values[27] != 0) ++bad;
                    if (d->tables[6]
                        .values[28] != 0) ++bad;
                    if (d->tables[6]
                        .values[29] != 0) ++bad;
                    if (d->tables[6]
                        .values[30] != 0) ++bad;
                    if (d->tables[6]
                        .values[31] != 0) ++bad;
                    if (d->tables[6]
                        .values[32] != 0) ++bad;
                    if (rules::m3RowLo(0) != 1) ++bad;
                    if (rules::m3RowLo(1) != 16) ++bad;
                    if (rules::m3RowLo(2) != 17) ++bad;
                    if (rules::m3RowLo(3) != 19) ++bad;
                    if (rules::m3RowLo(4) != 21) ++bad;
                    if (rules::m3RowLo(5) != 23) ++bad;
                    if (rules::m3RowLo(6) != 26) ++bad;
                    if (rules::m3RowLo(7) != 27) ++bad;
                    if (rules::m3RowLo(8) != 28) ++bad;
                    if (rules::m3RowLo(9) != 29) ++bad;
                    if (rules::m3RowLo(10) != 30) ++bad;
                    if (rules::m3RowLo(11) != 31) ++bad;
                    if (rules::m3RowLo(12) != 36) ++bad;
                    if (rules::m3RowLo(13) != 38) ++bad;
                    if (rules::m3RowLo(14) != 40) ++bad;
                    if (rules::m3RowLo(15) != 41) ++bad;
                    if (rules::m3RowLo(16) != 46) ++bad;
                    if (rules::m3RowLo(17) != 47) ++bad;
                    if (rules::m3RowLo(18) != 49) ++bad;
                    if (rules::m3RowLo(19) != 50) ++bad;
                    if (rules::m3RowLo(20) != 54) ++bad;
                    if (rules::m3RowLo(21) != 61) ++bad;
                    if (rules::m3RowLo(22) != 64) ++bad;
                    if (rules::m3RowLo(23) != 66) ++bad;
                    if (rules::m3RowLo(24) != 71) ++bad;
                    if (rules::m3RowLo(25) != 72) ++bad;
                    if (rules::m3RowLo(26) != 73) ++bad;
                    if (rules::m3RowLo(27) != 79) ++bad;
                    if (rules::m3RowLo(28) != 81) ++bad;
                    if (rules::m3RowLo(29) != 86) ++bad;
                    if (rules::m3RowLo(30) != 91) ++bad;
                    if (rules::m3RowLo(31) != 92) ++bad;
                    if (rules::m3RowLo(32) != 93) ++bad;
                    if (rules::m3RowHi(0) != 15) ++bad;
                    if (rules::m3RowHi(1) != 16) ++bad;
                    if (rules::m3RowHi(2) != 18) ++bad;
                    if (rules::m3RowHi(3) != 20) ++bad;
                    if (rules::m3RowHi(4) != 22) ++bad;
                    if (rules::m3RowHi(5) != 25) ++bad;
                    if (rules::m3RowHi(6) != 26) ++bad;
                    if (rules::m3RowHi(7) != 27) ++bad;
                    if (rules::m3RowHi(8) != 28) ++bad;
                    if (rules::m3RowHi(9) != 29) ++bad;
                    if (rules::m3RowHi(10) != 30) ++bad;
                    if (rules::m3RowHi(11) != 35) ++bad;
                    if (rules::m3RowHi(12) != 37) ++bad;
                    if (rules::m3RowHi(13) != 39) ++bad;
                    if (rules::m3RowHi(14) != 40) ++bad;
                    if (rules::m3RowHi(15) != 45) ++bad;
                    if (rules::m3RowHi(16) != 46) ++bad;
                    if (rules::m3RowHi(17) != 48) ++bad;
                    if (rules::m3RowHi(18) != 49) ++bad;
                    if (rules::m3RowHi(19) != 53) ++bad;
                    if (rules::m3RowHi(20) != 60) ++bad;
                    if (rules::m3RowHi(21) != 63) ++bad;
                    if (rules::m3RowHi(22) != 65) ++bad;
                    if (rules::m3RowHi(23) != 70) ++bad;
                    if (rules::m3RowHi(24) != 71) ++bad;
                    if (rules::m3RowHi(25) != 72) ++bad;
                    if (rules::m3RowHi(26) != 78) ++bad;
                    if (rules::m3RowHi(27) != 80) ++bad;
                    if (rules::m3RowHi(28) != 85) ++bad;
                    if (rules::m3RowHi(29) != 90) ++bad;
                    if (rules::m3RowHi(30) != 91) ++bad;
                    if (rules::m3RowHi(31) != 92) ++bad;
                    if (rules::m3RowHi(32) != 100) ++bad;
                    if (rules::m3UsableByCleric(0) != 0) ++bad;
                    if (rules::m3UsableByCleric(1) != 0) ++bad;
                    if (rules::m3UsableByCleric(2) != 0) ++bad;
                    if (rules::m3UsableByCleric(3) != 0) ++bad;
                    if (rules::m3UsableByCleric(4) != 1) ++bad;
                    if (rules::m3UsableByCleric(5) != 1) ++bad;
                    if (rules::m3UsableByCleric(6) != 0) ++bad;
                    if (rules::m3UsableByCleric(7) != 0) ++bad;
                    if (rules::m3UsableByCleric(8) != 1) ++bad;
                    if (rules::m3UsableByCleric(9) != 1) ++bad;
                    if (rules::m3UsableByCleric(10) != 0) ++bad;
                    if (rules::m3UsableByCleric(11) != 0) ++bad;
                    if (rules::m3UsableByCleric(12) != 0) ++bad;
                    if (rules::m3UsableByCleric(13) != 0) ++bad;
                    if (rules::m3UsableByCleric(14) != 0) ++bad;
                    if (rules::m3UsableByCleric(15) != 0) ++bad;
                    if (rules::m3UsableByCleric(16) != 0) ++bad;
                    if (rules::m3UsableByCleric(17) != 0) ++bad;
                    if (rules::m3UsableByCleric(18) != 0) ++bad;
                    if (rules::m3UsableByCleric(19) != 1) ++bad;
                    if (rules::m3UsableByCleric(20) != 0) ++bad;
                    if (rules::m3UsableByCleric(21) != 0) ++bad;
                    if (rules::m3UsableByCleric(22) != 0) ++bad;
                    if (rules::m3UsableByCleric(23) != 1) ++bad;
                    if (rules::m3UsableByCleric(24) != 1) ++bad;
                    if (rules::m3UsableByCleric(25) != 0) ++bad;
                    if (rules::m3UsableByCleric(26) != 0) ++bad;
                    if (rules::m3UsableByCleric(27) != 0) ++bad;
                    if (rules::m3UsableByCleric(28) != 0) ++bad;
                    if (rules::m3UsableByCleric(29) != 0) ++bad;
                    if (rules::m3UsableByCleric(30) != 0) ++bad;
                    if (rules::m3UsableByCleric(31) != 0) ++bad;
                    if (rules::m3UsableByCleric(32) != 0) ++bad;
                    if (rules::m3UsableByFighter(0) != 0) ++bad;
                    if (rules::m3UsableByFighter(1) != 0) ++bad;
                    if (rules::m3UsableByFighter(2) != 0) ++bad;
                    if (rules::m3UsableByFighter(3) != 0) ++bad;
                    if (rules::m3UsableByFighter(4) != 1) ++bad;
                    if (rules::m3UsableByFighter(5) != 1) ++bad;
                    if (rules::m3UsableByFighter(6) != 0) ++bad;
                    if (rules::m3UsableByFighter(7) != 0) ++bad;
                    if (rules::m3UsableByFighter(8) != 1) ++bad;
                    if (rules::m3UsableByFighter(9) != 1) ++bad;
                    if (rules::m3UsableByFighter(10) != 0) ++bad;
                    if (rules::m3UsableByFighter(11) != 0) ++bad;
                    if (rules::m3UsableByFighter(12) != 0) ++bad;
                    if (rules::m3UsableByFighter(13) != 0) ++bad;
                    if (rules::m3UsableByFighter(14) != 0) ++bad;
                    if (rules::m3UsableByFighter(15) != 0) ++bad;
                    if (rules::m3UsableByFighter(16) != 0) ++bad;
                    if (rules::m3UsableByFighter(17) != 0) ++bad;
                    if (rules::m3UsableByFighter(18) != 0) ++bad;
                    if (rules::m3UsableByFighter(19) != 1) ++bad;
                    if (rules::m3UsableByFighter(20) != 0) ++bad;
                    if (rules::m3UsableByFighter(21) != 0) ++bad;
                    if (rules::m3UsableByFighter(22) != 0) ++bad;
                    if (rules::m3UsableByFighter(23) != 0) ++bad;
                    if (rules::m3UsableByFighter(24) != 0) ++bad;
                    if (rules::m3UsableByFighter(25) != 0) ++bad;
                    if (rules::m3UsableByFighter(26) != 0) ++bad;
                    if (rules::m3UsableByFighter(27) != 0) ++bad;
                    if (rules::m3UsableByFighter(28) != 1) ++bad;
                    if (rules::m3UsableByFighter(29) != 1) ++bad;
                    if (rules::m3UsableByFighter(30) != 0) ++bad;
                    if (rules::m3UsableByFighter(31) != 0) ++bad;
                    if (rules::m3UsableByFighter(32) != 0) ++bad;
                    if (rules::m3UsableByThief(0) != 0) ++bad;
                    if (rules::m3UsableByThief(1) != 0) ++bad;
                    if (rules::m3UsableByThief(2) != 0) ++bad;
                    if (rules::m3UsableByThief(3) != 0) ++bad;
                    if (rules::m3UsableByThief(4) != 1) ++bad;
                    if (rules::m3UsableByThief(5) != 1) ++bad;
                    if (rules::m3UsableByThief(6) != 0) ++bad;
                    if (rules::m3UsableByThief(7) != 0) ++bad;
                    if (rules::m3UsableByThief(8) != 1) ++bad;
                    if (rules::m3UsableByThief(9) != 1) ++bad;
                    if (rules::m3UsableByThief(10) != 0) ++bad;
                    if (rules::m3UsableByThief(11) != 0) ++bad;
                    if (rules::m3UsableByThief(12) != 0) ++bad;
                    if (rules::m3UsableByThief(13) != 0) ++bad;
                    if (rules::m3UsableByThief(14) != 0) ++bad;
                    if (rules::m3UsableByThief(15) != 0) ++bad;
                    if (rules::m3UsableByThief(16) != 0) ++bad;
                    if (rules::m3UsableByThief(17) != 0) ++bad;
                    if (rules::m3UsableByThief(18) != 0) ++bad;
                    if (rules::m3UsableByThief(19) != 0) ++bad;
                    if (rules::m3UsableByThief(20) != 0) ++bad;
                    if (rules::m3UsableByThief(21) != 0) ++bad;
                    if (rules::m3UsableByThief(22) != 0) ++bad;
                    if (rules::m3UsableByThief(23) != 0) ++bad;
                    if (rules::m3UsableByThief(24) != 0) ++bad;
                    if (rules::m3UsableByThief(25) != 0) ++bad;
                    if (rules::m3UsableByThief(26) != 0) ++bad;
                    if (rules::m3UsableByThief(27) != 0) ++bad;
                    if (rules::m3UsableByThief(28) != 0) ++bad;
                    if (rules::m3UsableByThief(29) != 0) ++bad;
                    if (rules::m3UsableByThief(30) != 0) ++bad;
                    if (rules::m3UsableByThief(31) != 0) ++bad;
                    if (rules::m3UsableByThief(32) != 0) ++bad;
                    if (rules::m3StarCount(0) != 1) ++bad;
                    if (rules::m3StarCount(1) != 0) ++bad;
                    if (rules::m3StarCount(2) != 0) ++bad;
                    if (rules::m3StarCount(3) != 0) ++bad;
                    if (rules::m3StarCount(4) != 0) ++bad;
                    if (rules::m3StarCount(5) != 0) ++bad;
                    if (rules::m3StarCount(6) != 0) ++bad;
                    if (rules::m3StarCount(7) != 0) ++bad;
                    if (rules::m3StarCount(8) != 0) ++bad;
                    if (rules::m3StarCount(9) != 0) ++bad;
                    if (rules::m3StarCount(10) != 0) ++bad;
                    if (rules::m3StarCount(11) != 0) ++bad;
                    if (rules::m3StarCount(12) != 0) ++bad;
                    if (rules::m3StarCount(13) != 0) ++bad;
                    if (rules::m3StarCount(14) != 0) ++bad;
                    if (rules::m3StarCount(15) != 0) ++bad;
                    if (rules::m3StarCount(16) != 0) ++bad;
                    if (rules::m3StarCount(17) != 0) ++bad;
                    if (rules::m3StarCount(18) != 0) ++bad;
                    if (rules::m3StarCount(19) != 0) ++bad;
                    if (rules::m3StarCount(20) != 2) ++bad;
                    if (rules::m3StarCount(21) != 0) ++bad;
                    if (rules::m3StarCount(22) != 0) ++bad;
                    if (rules::m3StarCount(23) != 0) ++bad;
                    if (rules::m3StarCount(24) != 0) ++bad;
                    if (rules::m3StarCount(25) != 3) ++bad;
                    if (rules::m3StarCount(26) != 4) ++bad;
                    if (rules::m3StarCount(27) != 0) ++bad;
                    if (rules::m3StarCount(28) != 0) ++bad;
                    if (rules::m3StarCount(29) != 0) ++bad;
                    if (rules::m3StarCount(30) != 0) ++bad;
                    if (rules::m3StarCount(31) != 0) ++bad;
                    if (rules::m3StarCount(32) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(0) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(1) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(2) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(3) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(4) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(5) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(6) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(7) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(8) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(9) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(10) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(11) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(12) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(13) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(14) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(15) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(16) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(17) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(18) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(19) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(20) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(21) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(22) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(23) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(24) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(25) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(26) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(27) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(28) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(29) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(30) != 0) ++bad;
                    if (rules::m3IsPerFacetValued(31) != 1) ++bad;
                    if (rules::m3IsPerFacetValued(32) != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("misc_m4");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 0) ++bad;
                    if (d->tables[0]
                        .values[1] != 0) ++bad;
                    if (d->tables[0]
                        .values[2] != 0) ++bad;
                    if (d->tables[0]
                        .values[3] != 0) ++bad;
                    if (d->tables[0]
                        .values[4] != 0) ++bad;
                    if (d->tables[0]
                        .values[5] != 0) ++bad;
                    if (d->tables[0]
                        .values[6] != 0) ++bad;
                    if (d->tables[0]
                        .values[7] != 0) ++bad;
                    if (d->tables[0]
                        .values[8] != 0) ++bad;
                    if (d->tables[0]
                        .values[9] != 0) ++bad;
                    if (d->tables[0]
                        .values[10] != 0) ++bad;
                    if (d->tables[0]
                        .values[11] != 0) ++bad;
                    if (d->tables[0]
                        .values[12] != 1) ++bad;
                    if (d->tables[0]
                        .values[13] != 0) ++bad;
                    if (d->tables[0]
                        .values[14] != 0) ++bad;
                    if (d->tables[0]
                        .values[15] != 0) ++bad;
                    if (d->tables[0]
                        .values[16] != 0) ++bad;
                    if (d->tables[0]
                        .values[17] != 0) ++bad;
                    if (d->tables[0]
                        .values[18] != 0) ++bad;
                    if (d->tables[0]
                        .values[19] != 0) ++bad;
                    if (d->tables[0]
                        .values[20] != 0) ++bad;
                    if (d->tables[0]
                        .values[21] != 0) ++bad;
                    if (d->tables[0]
                        .values[22] != 0) ++bad;
                    if (d->tables[0]
                        .values[23] != 0) ++bad;
                    if (d->tables[0]
                        .values[24] != 0) ++bad;
                    if (d->tables[0]
                        .values[25] != 0) ++bad;
                    if (d->tables[0]
                        .values[26] != 0) ++bad;
                    if (d->tables[0]
                        .values[27] != 0) ++bad;
                    if (d->tables[0]
                        .values[28] != 0) ++bad;
                    if (d->tables[0]
                        .values[29] != 0) ++bad;
                    if (d->tables[0]
                        .values[30] != 0) ++bad;
                    if (d->tables[0]
                        .values[31] != 0) ++bad;
                    if (d->tables[0]
                        .values[32] != 0) ++bad;
                    if (d->tables[0]
                        .values[33] != 0) ++bad;
                    if (d->tables[0]
                        .values[34] != 0) ++bad;
                    if (d->tables[0]
                        .values[35] != 1) ++bad;
                    if (d->tables[1]
                        .values[0] != 1) ++bad;
                    if (d->tables[1]
                        .values[1] != 2) ++bad;
                    if (d->tables[1]
                        .values[2] != 3) ++bad;
                    if (d->tables[1]
                        .values[3] != 4) ++bad;
                    if (d->tables[1]
                        .values[4] != 5) ++bad;
                    if (d->tables[1]
                        .values[5] != 6) ++bad;
                    if (d->tables[1]
                        .values[6] != 7) ++bad;
                    if (d->tables[1]
                        .values[7] != 8) ++bad;
                    if (d->tables[1]
                        .values[8] != 9) ++bad;
                    if (d->tables[1]
                        .values[9] != 10) ++bad;
                    if (d->tables[1]
                        .values[10] != 11) ++bad;
                    if (d->tables[1]
                        .values[11] != 12) ++bad;
                    if (d->tables[1]
                        .values[12] != 15) ++bad;
                    if (d->tables[1]
                        .values[13] != 17) ++bad;
                    if (d->tables[1]
                        .values[14] != 18) ++bad;
                    if (d->tables[1]
                        .values[15] != 19) ++bad;
                    if (d->tables[1]
                        .values[16] != 20) ++bad;
                    if (d->tables[1]
                        .values[17] != 23) ++bad;
                    if (d->tables[1]
                        .values[18] != 27) ++bad;
                    if (d->tables[1]
                        .values[19] != 33) ++bad;
                    if (d->tables[1]
                        .values[20] != 35) ++bad;
                    if (d->tables[1]
                        .values[21] != 38) ++bad;
                    if (d->tables[1]
                        .values[22] != 42) ++bad;
                    if (d->tables[1]
                        .values[23] != 44) ++bad;
                    if (d->tables[1]
                        .values[24] != 46) ++bad;
                    if (d->tables[1]
                        .values[25] != 48) ++bad;
                    if (d->tables[1]
                        .values[26] != 50) ++bad;
                    if (d->tables[1]
                        .values[27] != 53) ++bad;
                    if (d->tables[1]
                        .values[28] != 60) ++bad;
                    if (d->tables[1]
                        .values[29] != 64) ++bad;
                    if (d->tables[1]
                        .values[30] != 70) ++bad;
                    if (d->tables[1]
                        .values[31] != 74) ++bad;
                    if (d->tables[1]
                        .values[32] != 76) ++bad;
                    if (d->tables[1]
                        .values[33] != 84) ++bad;
                    if (d->tables[1]
                        .values[34] != 85) ++bad;
                    if (d->tables[1]
                        .values[35] != 100) ++bad;
                    if (d->tables[2]
                        .values[0] != 1) ++bad;
                    if (d->tables[2]
                        .values[1] != 2) ++bad;
                    if (d->tables[2]
                        .values[2] != 3) ++bad;
                    if (d->tables[2]
                        .values[3] != 4) ++bad;
                    if (d->tables[2]
                        .values[4] != 5) ++bad;
                    if (d->tables[2]
                        .values[5] != 6) ++bad;
                    if (d->tables[2]
                        .values[6] != 7) ++bad;
                    if (d->tables[2]
                        .values[7] != 8) ++bad;
                    if (d->tables[2]
                        .values[8] != 9) ++bad;
                    if (d->tables[2]
                        .values[9] != 10) ++bad;
                    if (d->tables[2]
                        .values[10] != 11) ++bad;
                    if (d->tables[2]
                        .values[11] != 12) ++bad;
                    if (d->tables[2]
                        .values[12] != 13) ++bad;
                    if (d->tables[2]
                        .values[13] != 16) ++bad;
                    if (d->tables[2]
                        .values[14] != 18) ++bad;
                    if (d->tables[2]
                        .values[15] != 19) ++bad;
                    if (d->tables[2]
                        .values[16] != 20) ++bad;
                    if (d->tables[2]
                        .values[17] != 21) ++bad;
                    if (d->tables[2]
                        .values[18] != 24) ++bad;
                    if (d->tables[2]
                        .values[19] != 28) ++bad;
                    if (d->tables[2]
                        .values[20] != 34) ++bad;
                    if (d->tables[2]
                        .values[21] != 36) ++bad;
                    if (d->tables[2]
                        .values[22] != 39) ++bad;
                    if (d->tables[2]
                        .values[23] != 43) ++bad;
                    if (d->tables[2]
                        .values[24] != 45) ++bad;
                    if (d->tables[2]
                        .values[25] != 47) ++bad;
                    if (d->tables[2]
                        .values[26] != 49) ++bad;
                    if (d->tables[2]
                        .values[27] != 51) ++bad;
                    if (d->tables[2]
                        .values[28] != 54) ++bad;
                    if (d->tables[2]
                        .values[29] != 61) ++bad;
                    if (d->tables[2]
                        .values[30] != 65) ++bad;
                    if (d->tables[2]
                        .values[31] != 71) ++bad;
                    if (d->tables[2]
                        .values[32] != 75) ++bad;
                    if (d->tables[2]
                        .values[33] != 77) ++bad;
                    if (d->tables[2]
                        .values[34] != 85) ++bad;
                    if (d->tables[2]
                        .values[35] != 86) ++bad;
                    if (d->tables[3]
                        .values[0] != 0) ++bad;
                    if (d->tables[3]
                        .values[1] != 0) ++bad;
                    if (d->tables[3]
                        .values[2] != 0) ++bad;
                    if (d->tables[3]
                        .values[3] != 0) ++bad;
                    if (d->tables[3]
                        .values[4] != 0) ++bad;
                    if (d->tables[3]
                        .values[5] != 0) ++bad;
                    if (d->tables[3]
                        .values[6] != 0) ++bad;
                    if (d->tables[3]
                        .values[7] != 0) ++bad;
                    if (d->tables[3]
                        .values[8] != 0) ++bad;
                    if (d->tables[3]
                        .values[9] != 0) ++bad;
                    if (d->tables[3]
                        .values[10] != 0) ++bad;
                    if (d->tables[3]
                        .values[11] != 0) ++bad;
                    if (d->tables[3]
                        .values[12] != 0) ++bad;
                    if (d->tables[3]
                        .values[13] != 0) ++bad;
                    if (d->tables[3]
                        .values[14] != 0) ++bad;
                    if (d->tables[3]
                        .values[15] != 0) ++bad;
                    if (d->tables[3]
                        .values[16] != 0) ++bad;
                    if (d->tables[3]
                        .values[17] != 0) ++bad;
                    if (d->tables[3]
                        .values[18] != 1) ++bad;
                    if (d->tables[3]
                        .values[19] != 2) ++bad;
                    if (d->tables[3]
                        .values[20] != 0) ++bad;
                    if (d->tables[3]
                        .values[21] != 0) ++bad;
                    if (d->tables[3]
                        .values[22] != 0) ++bad;
                    if (d->tables[3]
                        .values[23] != 3) ++bad;
                    if (d->tables[3]
                        .values[24] != 4) ++bad;
                    if (d->tables[3]
                        .values[25] != 0) ++bad;
                    if (d->tables[3]
                        .values[26] != 0) ++bad;
                    if (d->tables[3]
                        .values[27] != 0) ++bad;
                    if (d->tables[3]
                        .values[28] != 0) ++bad;
                    if (d->tables[3]
                        .values[29] != 0) ++bad;
                    if (d->tables[3]
                        .values[30] != 0) ++bad;
                    if (d->tables[3]
                        .values[31] != 0) ++bad;
                    if (d->tables[3]
                        .values[32] != 0) ++bad;
                    if (d->tables[3]
                        .values[33] != 0) ++bad;
                    if (d->tables[3]
                        .values[34] != 0) ++bad;
                    if (d->tables[3]
                        .values[35] != 0) ++bad;
                    if (d->tables[4]
                        .values[0] != 0) ++bad;
                    if (d->tables[4]
                        .values[1] != 0) ++bad;
                    if (d->tables[4]
                        .values[2] != 0) ++bad;
                    if (d->tables[4]
                        .values[3] != 0) ++bad;
                    if (d->tables[4]
                        .values[4] != 0) ++bad;
                    if (d->tables[4]
                        .values[5] != 0) ++bad;
                    if (d->tables[4]
                        .values[6] != 1) ++bad;
                    if (d->tables[4]
                        .values[7] != 0) ++bad;
                    if (d->tables[4]
                        .values[8] != 0) ++bad;
                    if (d->tables[4]
                        .values[9] != 0) ++bad;
                    if (d->tables[4]
                        .values[10] != 0) ++bad;
                    if (d->tables[4]
                        .values[11] != 0) ++bad;
                    if (d->tables[4]
                        .values[12] != 0) ++bad;
                    if (d->tables[4]
                        .values[13] != 0) ++bad;
                    if (d->tables[4]
                        .values[14] != 0) ++bad;
                    if (d->tables[4]
                        .values[15] != 0) ++bad;
                    if (d->tables[4]
                        .values[16] != 0) ++bad;
                    if (d->tables[4]
                        .values[17] != 0) ++bad;
                    if (d->tables[4]
                        .values[18] != 0) ++bad;
                    if (d->tables[4]
                        .values[19] != 1) ++bad;
                    if (d->tables[4]
                        .values[20] != 0) ++bad;
                    if (d->tables[4]
                        .values[21] != 1) ++bad;
                    if (d->tables[4]
                        .values[22] != 1) ++bad;
                    if (d->tables[4]
                        .values[23] != 0) ++bad;
                    if (d->tables[4]
                        .values[24] != 0) ++bad;
                    if (d->tables[4]
                        .values[25] != 1) ++bad;
                    if (d->tables[4]
                        .values[26] != 0) ++bad;
                    if (d->tables[4]
                        .values[27] != 0) ++bad;
                    if (d->tables[4]
                        .values[28] != 0) ++bad;
                    if (d->tables[4]
                        .values[29] != 0) ++bad;
                    if (d->tables[4]
                        .values[30] != 1) ++bad;
                    if (d->tables[4]
                        .values[31] != 1) ++bad;
                    if (d->tables[4]
                        .values[32] != 1) ++bad;
                    if (d->tables[4]
                        .values[33] != 0) ++bad;
                    if (d->tables[4]
                        .values[34] != 0) ++bad;
                    if (d->tables[4]
                        .values[35] != 0) ++bad;
                    if (d->tables[5]
                        .values[0] != 0) ++bad;
                    if (d->tables[5]
                        .values[1] != 0) ++bad;
                    if (d->tables[5]
                        .values[2] != 0) ++bad;
                    if (d->tables[5]
                        .values[3] != 0) ++bad;
                    if (d->tables[5]
                        .values[4] != 0) ++bad;
                    if (d->tables[5]
                        .values[5] != 0) ++bad;
                    if (d->tables[5]
                        .values[6] != 0) ++bad;
                    if (d->tables[5]
                        .values[7] != 1) ++bad;
                    if (d->tables[5]
                        .values[8] != 0) ++bad;
                    if (d->tables[5]
                        .values[9] != 0) ++bad;
                    if (d->tables[5]
                        .values[10] != 1) ++bad;
                    if (d->tables[5]
                        .values[11] != 0) ++bad;
                    if (d->tables[5]
                        .values[12] != 0) ++bad;
                    if (d->tables[5]
                        .values[13] != 0) ++bad;
                    if (d->tables[5]
                        .values[14] != 0) ++bad;
                    if (d->tables[5]
                        .values[15] != 0) ++bad;
                    if (d->tables[5]
                        .values[16] != 0) ++bad;
                    if (d->tables[5]
                        .values[17] != 0) ++bad;
                    if (d->tables[5]
                        .values[18] != 0) ++bad;
                    if (d->tables[5]
                        .values[19] != 0) ++bad;
                    if (d->tables[5]
                        .values[20] != 0) ++bad;
                    if (d->tables[5]
                        .values[21] != 1) ++bad;
                    if (d->tables[5]
                        .values[22] != 1) ++bad;
                    if (d->tables[5]
                        .values[23] != 0) ++bad;
                    if (d->tables[5]
                        .values[24] != 0) ++bad;
                    if (d->tables[5]
                        .values[25] != 0) ++bad;
                    if (d->tables[5]
                        .values[26] != 0) ++bad;
                    if (d->tables[5]
                        .values[27] != 0) ++bad;
                    if (d->tables[5]
                        .values[28] != 0) ++bad;
                    if (d->tables[5]
                        .values[29] != 0) ++bad;
                    if (d->tables[5]
                        .values[30] != 0) ++bad;
                    if (d->tables[5]
                        .values[31] != 0) ++bad;
                    if (d->tables[5]
                        .values[32] != 0) ++bad;
                    if (d->tables[5]
                        .values[33] != 0) ++bad;
                    if (d->tables[5]
                        .values[34] != 0) ++bad;
                    if (d->tables[5]
                        .values[35] != 0) ++bad;
                    if (d->tables[6]
                        .values[0] != 1) ++bad;
                    if (d->tables[6]
                        .values[1] != 1) ++bad;
                    if (d->tables[6]
                        .values[2] != 1) ++bad;
                    if (d->tables[6]
                        .values[3] != 0) ++bad;
                    if (d->tables[6]
                        .values[4] != 0) ++bad;
                    if (d->tables[6]
                        .values[5] != 0) ++bad;
                    if (d->tables[6]
                        .values[6] != 1) ++bad;
                    if (d->tables[6]
                        .values[7] != 0) ++bad;
                    if (d->tables[6]
                        .values[8] != 0) ++bad;
                    if (d->tables[6]
                        .values[9] != 0) ++bad;
                    if (d->tables[6]
                        .values[10] != 0) ++bad;
                    if (d->tables[6]
                        .values[11] != 0) ++bad;
                    if (d->tables[6]
                        .values[12] != 0) ++bad;
                    if (d->tables[6]
                        .values[13] != 0) ++bad;
                    if (d->tables[6]
                        .values[14] != 1) ++bad;
                    if (d->tables[6]
                        .values[15] != 0) ++bad;
                    if (d->tables[6]
                        .values[16] != 0) ++bad;
                    if (d->tables[6]
                        .values[17] != 0) ++bad;
                    if (d->tables[6]
                        .values[18] != 0) ++bad;
                    if (d->tables[6]
                        .values[19] != 0) ++bad;
                    if (d->tables[6]
                        .values[20] != 0) ++bad;
                    if (d->tables[6]
                        .values[21] != 0) ++bad;
                    if (d->tables[6]
                        .values[22] != 0) ++bad;
                    if (d->tables[6]
                        .values[23] != 0) ++bad;
                    if (d->tables[6]
                        .values[24] != 1) ++bad;
                    if (d->tables[6]
                        .values[25] != 0) ++bad;
                    if (d->tables[6]
                        .values[26] != 0) ++bad;
                    if (d->tables[6]
                        .values[27] != 0) ++bad;
                    if (d->tables[6]
                        .values[28] != 0) ++bad;
                    if (d->tables[6]
                        .values[29] != 0) ++bad;
                    if (d->tables[6]
                        .values[30] != 0) ++bad;
                    if (d->tables[6]
                        .values[31] != 0) ++bad;
                    if (d->tables[6]
                        .values[32] != 0) ++bad;
                    if (d->tables[6]
                        .values[33] != 0) ++bad;
                    if (d->tables[6]
                        .values[34] != 0) ++bad;
                    if (d->tables[6]
                        .values[35] != 0) ++bad;
                    if (d->tables[7]
                        .values[0] != 0) ++bad;
                    if (d->tables[7]
                        .values[1] != 0) ++bad;
                    if (d->tables[7]
                        .values[2] != 0) ++bad;
                    if (d->tables[7]
                        .values[3] != 0) ++bad;
                    if (d->tables[7]
                        .values[4] != 0) ++bad;
                    if (d->tables[7]
                        .values[5] != 0) ++bad;
                    if (d->tables[7]
                        .values[6] != 0) ++bad;
                    if (d->tables[7]
                        .values[7] != 0) ++bad;
                    if (d->tables[7]
                        .values[8] != 0) ++bad;
                    if (d->tables[7]
                        .values[9] != 1) ++bad;
                    if (d->tables[7]
                        .values[10] != 0) ++bad;
                    if (d->tables[7]
                        .values[11] != 0) ++bad;
                    if (d->tables[7]
                        .values[12] != 0) ++bad;
                    if (d->tables[7]
                        .values[13] != 0) ++bad;
                    if (d->tables[7]
                        .values[14] != 0) ++bad;
                    if (d->tables[7]
                        .values[15] != 0) ++bad;
                    if (d->tables[7]
                        .values[16] != 0) ++bad;
                    if (d->tables[7]
                        .values[17] != 0) ++bad;
                    if (d->tables[7]
                        .values[18] != 0) ++bad;
                    if (d->tables[7]
                        .values[19] != 0) ++bad;
                    if (d->tables[7]
                        .values[20] != 0) ++bad;
                    if (d->tables[7]
                        .values[21] != 1) ++bad;
                    if (d->tables[7]
                        .values[22] != 1) ++bad;
                    if (d->tables[7]
                        .values[23] != 0) ++bad;
                    if (d->tables[7]
                        .values[24] != 0) ++bad;
                    if (d->tables[7]
                        .values[25] != 0) ++bad;
                    if (d->tables[7]
                        .values[26] != 0) ++bad;
                    if (d->tables[7]
                        .values[27] != 0) ++bad;
                    if (d->tables[7]
                        .values[28] != 0) ++bad;
                    if (d->tables[7]
                        .values[29] != 0) ++bad;
                    if (d->tables[7]
                        .values[30] != 0) ++bad;
                    if (d->tables[7]
                        .values[31] != 0) ++bad;
                    if (d->tables[7]
                        .values[32] != 0) ++bad;
                    if (d->tables[7]
                        .values[33] != 0) ++bad;
                    if (d->tables[7]
                        .values[34] != 0) ++bad;
                    if (d->tables[7]
                        .values[35] != 0) ++bad;
                    if (rules::m4RowLo(0) != 1) ++bad;
                    if (rules::m4RowLo(1) != 2) ++bad;
                    if (rules::m4RowLo(2) != 3) ++bad;
                    if (rules::m4RowLo(3) != 4) ++bad;
                    if (rules::m4RowLo(4) != 5) ++bad;
                    if (rules::m4RowLo(5) != 6) ++bad;
                    if (rules::m4RowLo(6) != 7) ++bad;
                    if (rules::m4RowLo(7) != 8) ++bad;
                    if (rules::m4RowLo(8) != 9) ++bad;
                    if (rules::m4RowLo(9) != 10) ++bad;
                    if (rules::m4RowLo(10) != 11) ++bad;
                    if (rules::m4RowLo(11) != 12) ++bad;
                    if (rules::m4RowLo(12) != 13) ++bad;
                    if (rules::m4RowLo(13) != 16) ++bad;
                    if (rules::m4RowLo(14) != 18) ++bad;
                    if (rules::m4RowLo(15) != 19) ++bad;
                    if (rules::m4RowLo(16) != 20) ++bad;
                    if (rules::m4RowLo(17) != 21) ++bad;
                    if (rules::m4RowLo(18) != 24) ++bad;
                    if (rules::m4RowLo(19) != 28) ++bad;
                    if (rules::m4RowLo(20) != 34) ++bad;
                    if (rules::m4RowLo(21) != 36) ++bad;
                    if (rules::m4RowLo(22) != 39) ++bad;
                    if (rules::m4RowLo(23) != 43) ++bad;
                    if (rules::m4RowLo(24) != 45) ++bad;
                    if (rules::m4RowLo(25) != 47) ++bad;
                    if (rules::m4RowLo(26) != 49) ++bad;
                    if (rules::m4RowLo(27) != 51) ++bad;
                    if (rules::m4RowLo(28) != 54) ++bad;
                    if (rules::m4RowLo(29) != 61) ++bad;
                    if (rules::m4RowLo(30) != 65) ++bad;
                    if (rules::m4RowLo(31) != 71) ++bad;
                    if (rules::m4RowLo(32) != 75) ++bad;
                    if (rules::m4RowLo(33) != 77) ++bad;
                    if (rules::m4RowLo(34) != 85) ++bad;
                    if (rules::m4RowLo(35) != 86) ++bad;
                    if (rules::m4RowHi(0) != 1) ++bad;
                    if (rules::m4RowHi(1) != 2) ++bad;
                    if (rules::m4RowHi(2) != 3) ++bad;
                    if (rules::m4RowHi(3) != 4) ++bad;
                    if (rules::m4RowHi(4) != 5) ++bad;
                    if (rules::m4RowHi(5) != 6) ++bad;
                    if (rules::m4RowHi(6) != 7) ++bad;
                    if (rules::m4RowHi(7) != 8) ++bad;
                    if (rules::m4RowHi(8) != 9) ++bad;
                    if (rules::m4RowHi(9) != 10) ++bad;
                    if (rules::m4RowHi(10) != 11) ++bad;
                    if (rules::m4RowHi(11) != 12) ++bad;
                    if (rules::m4RowHi(12) != 15) ++bad;
                    if (rules::m4RowHi(13) != 17) ++bad;
                    if (rules::m4RowHi(14) != 18) ++bad;
                    if (rules::m4RowHi(15) != 19) ++bad;
                    if (rules::m4RowHi(16) != 20) ++bad;
                    if (rules::m4RowHi(17) != 23) ++bad;
                    if (rules::m4RowHi(18) != 27) ++bad;
                    if (rules::m4RowHi(19) != 33) ++bad;
                    if (rules::m4RowHi(20) != 35) ++bad;
                    if (rules::m4RowHi(21) != 38) ++bad;
                    if (rules::m4RowHi(22) != 42) ++bad;
                    if (rules::m4RowHi(23) != 44) ++bad;
                    if (rules::m4RowHi(24) != 46) ++bad;
                    if (rules::m4RowHi(25) != 48) ++bad;
                    if (rules::m4RowHi(26) != 50) ++bad;
                    if (rules::m4RowHi(27) != 53) ++bad;
                    if (rules::m4RowHi(28) != 60) ++bad;
                    if (rules::m4RowHi(29) != 64) ++bad;
                    if (rules::m4RowHi(30) != 70) ++bad;
                    if (rules::m4RowHi(31) != 74) ++bad;
                    if (rules::m4RowHi(32) != 76) ++bad;
                    if (rules::m4RowHi(33) != 84) ++bad;
                    if (rules::m4RowHi(34) != 85) ++bad;
                    if (rules::m4RowHi(35) != 100) ++bad;
                    if (rules::m4UsableByCleric(0) != 0) ++bad;
                    if (rules::m4UsableByCleric(1) != 0) ++bad;
                    if (rules::m4UsableByCleric(2) != 0) ++bad;
                    if (rules::m4UsableByCleric(3) != 0) ++bad;
                    if (rules::m4UsableByCleric(4) != 0) ++bad;
                    if (rules::m4UsableByCleric(5) != 0) ++bad;
                    if (rules::m4UsableByCleric(6) != 1) ++bad;
                    if (rules::m4UsableByCleric(7) != 0) ++bad;
                    if (rules::m4UsableByCleric(8) != 0) ++bad;
                    if (rules::m4UsableByCleric(9) != 0) ++bad;
                    if (rules::m4UsableByCleric(10) != 0) ++bad;
                    if (rules::m4UsableByCleric(11) != 0) ++bad;
                    if (rules::m4UsableByCleric(12) != 0) ++bad;
                    if (rules::m4UsableByCleric(13) != 0) ++bad;
                    if (rules::m4UsableByCleric(14) != 0) ++bad;
                    if (rules::m4UsableByCleric(15) != 0) ++bad;
                    if (rules::m4UsableByCleric(16) != 0) ++bad;
                    if (rules::m4UsableByCleric(17) != 0) ++bad;
                    if (rules::m4UsableByCleric(18) != 0) ++bad;
                    if (rules::m4UsableByCleric(19) != 1) ++bad;
                    if (rules::m4UsableByCleric(20) != 0) ++bad;
                    if (rules::m4UsableByCleric(21) != 1) ++bad;
                    if (rules::m4UsableByCleric(22) != 1) ++bad;
                    if (rules::m4UsableByCleric(23) != 0) ++bad;
                    if (rules::m4UsableByCleric(24) != 0) ++bad;
                    if (rules::m4UsableByCleric(25) != 1) ++bad;
                    if (rules::m4UsableByCleric(26) != 0) ++bad;
                    if (rules::m4UsableByCleric(27) != 0) ++bad;
                    if (rules::m4UsableByCleric(28) != 0) ++bad;
                    if (rules::m4UsableByCleric(29) != 0) ++bad;
                    if (rules::m4UsableByCleric(30) != 1) ++bad;
                    if (rules::m4UsableByCleric(31) != 1) ++bad;
                    if (rules::m4UsableByCleric(32) != 1) ++bad;
                    if (rules::m4UsableByCleric(33) != 0) ++bad;
                    if (rules::m4UsableByCleric(34) != 0) ++bad;
                    if (rules::m4UsableByCleric(35) != 0) ++bad;
                    if (rules::m4UsableByFighter(0) != 0) ++bad;
                    if (rules::m4UsableByFighter(1) != 0) ++bad;
                    if (rules::m4UsableByFighter(2) != 0) ++bad;
                    if (rules::m4UsableByFighter(3) != 0) ++bad;
                    if (rules::m4UsableByFighter(4) != 0) ++bad;
                    if (rules::m4UsableByFighter(5) != 0) ++bad;
                    if (rules::m4UsableByFighter(6) != 0) ++bad;
                    if (rules::m4UsableByFighter(7) != 1) ++bad;
                    if (rules::m4UsableByFighter(8) != 0) ++bad;
                    if (rules::m4UsableByFighter(9) != 0) ++bad;
                    if (rules::m4UsableByFighter(10) != 1) ++bad;
                    if (rules::m4UsableByFighter(11) != 0) ++bad;
                    if (rules::m4UsableByFighter(12) != 0) ++bad;
                    if (rules::m4UsableByFighter(13) != 0) ++bad;
                    if (rules::m4UsableByFighter(14) != 0) ++bad;
                    if (rules::m4UsableByFighter(15) != 0) ++bad;
                    if (rules::m4UsableByFighter(16) != 0) ++bad;
                    if (rules::m4UsableByFighter(17) != 0) ++bad;
                    if (rules::m4UsableByFighter(18) != 0) ++bad;
                    if (rules::m4UsableByFighter(19) != 0) ++bad;
                    if (rules::m4UsableByFighter(20) != 0) ++bad;
                    if (rules::m4UsableByFighter(21) != 1) ++bad;
                    if (rules::m4UsableByFighter(22) != 1) ++bad;
                    if (rules::m4UsableByFighter(23) != 0) ++bad;
                    if (rules::m4UsableByFighter(24) != 0) ++bad;
                    if (rules::m4UsableByFighter(25) != 0) ++bad;
                    if (rules::m4UsableByFighter(26) != 0) ++bad;
                    if (rules::m4UsableByFighter(27) != 0) ++bad;
                    if (rules::m4UsableByFighter(28) != 0) ++bad;
                    if (rules::m4UsableByFighter(29) != 0) ++bad;
                    if (rules::m4UsableByFighter(30) != 0) ++bad;
                    if (rules::m4UsableByFighter(31) != 0) ++bad;
                    if (rules::m4UsableByFighter(32) != 0) ++bad;
                    if (rules::m4UsableByFighter(33) != 0) ++bad;
                    if (rules::m4UsableByFighter(34) != 0) ++bad;
                    if (rules::m4UsableByFighter(35) != 0) ++bad;
                    if (rules::m4UsableByMagicUser(0) != 1) ++bad;
                    if (rules::m4UsableByMagicUser(1) != 1) ++bad;
                    if (rules::m4UsableByMagicUser(2) != 1) ++bad;
                    if (rules::m4UsableByMagicUser(3) != 0) ++bad;
                    if (rules::m4UsableByMagicUser(4) != 0) ++bad;
                    if (rules::m4UsableByMagicUser(5) != 0) ++bad;
                    if (rules::m4UsableByMagicUser(6) != 1) ++bad;
                    if (rules::m4UsableByMagicUser(7) != 0) ++bad;
                    if (rules::m4UsableByMagicUser(8) != 0) ++bad;
                    if (rules::m4UsableByMagicUser(9) != 0) ++bad;
                    if (rules::m4UsableByMagicUser(10) != 0) ++bad;
                    if (rules::m4UsableByMagicUser(11) != 0) ++bad;
                    if (rules::m4UsableByMagicUser(12) != 0) ++bad;
                    if (rules::m4UsableByMagicUser(13) != 0) ++bad;
                    if (rules::m4UsableByMagicUser(14) != 1) ++bad;
                    if (rules::m4UsableByMagicUser(15) != 0) ++bad;
                    if (rules::m4UsableByMagicUser(16) != 0) ++bad;
                    if (rules::m4UsableByMagicUser(17) != 0) ++bad;
                    if (rules::m4UsableByMagicUser(18) != 0) ++bad;
                    if (rules::m4UsableByMagicUser(19) != 0) ++bad;
                    if (rules::m4UsableByMagicUser(20) != 0) ++bad;
                    if (rules::m4UsableByMagicUser(21) != 0) ++bad;
                    if (rules::m4UsableByMagicUser(22) != 0) ++bad;
                    if (rules::m4UsableByMagicUser(23) != 0) ++bad;
                    if (rules::m4UsableByMagicUser(24) != 1) ++bad;
                    if (rules::m4UsableByMagicUser(25) != 0) ++bad;
                    if (rules::m4UsableByMagicUser(26) != 0) ++bad;
                    if (rules::m4UsableByMagicUser(27) != 0) ++bad;
                    if (rules::m4UsableByMagicUser(28) != 0) ++bad;
                    if (rules::m4UsableByMagicUser(29) != 0) ++bad;
                    if (rules::m4UsableByMagicUser(30) != 0) ++bad;
                    if (rules::m4UsableByMagicUser(31) != 0) ++bad;
                    if (rules::m4UsableByMagicUser(32) != 0) ++bad;
                    if (rules::m4UsableByMagicUser(33) != 0) ++bad;
                    if (rules::m4UsableByMagicUser(34) != 0) ++bad;
                    if (rules::m4UsableByMagicUser(35) != 0) ++bad;
                    if (rules::m4UsableByThief(0) != 0) ++bad;
                    if (rules::m4UsableByThief(1) != 0) ++bad;
                    if (rules::m4UsableByThief(2) != 0) ++bad;
                    if (rules::m4UsableByThief(3) != 0) ++bad;
                    if (rules::m4UsableByThief(4) != 0) ++bad;
                    if (rules::m4UsableByThief(5) != 0) ++bad;
                    if (rules::m4UsableByThief(6) != 0) ++bad;
                    if (rules::m4UsableByThief(7) != 0) ++bad;
                    if (rules::m4UsableByThief(8) != 0) ++bad;
                    if (rules::m4UsableByThief(9) != 1) ++bad;
                    if (rules::m4UsableByThief(10) != 0) ++bad;
                    if (rules::m4UsableByThief(11) != 0) ++bad;
                    if (rules::m4UsableByThief(12) != 0) ++bad;
                    if (rules::m4UsableByThief(13) != 0) ++bad;
                    if (rules::m4UsableByThief(14) != 0) ++bad;
                    if (rules::m4UsableByThief(15) != 0) ++bad;
                    if (rules::m4UsableByThief(16) != 0) ++bad;
                    if (rules::m4UsableByThief(17) != 0) ++bad;
                    if (rules::m4UsableByThief(18) != 0) ++bad;
                    if (rules::m4UsableByThief(19) != 0) ++bad;
                    if (rules::m4UsableByThief(20) != 0) ++bad;
                    if (rules::m4UsableByThief(21) != 1) ++bad;
                    if (rules::m4UsableByThief(22) != 1) ++bad;
                    if (rules::m4UsableByThief(23) != 0) ++bad;
                    if (rules::m4UsableByThief(24) != 0) ++bad;
                    if (rules::m4UsableByThief(25) != 0) ++bad;
                    if (rules::m4UsableByThief(26) != 0) ++bad;
                    if (rules::m4UsableByThief(27) != 0) ++bad;
                    if (rules::m4UsableByThief(28) != 0) ++bad;
                    if (rules::m4UsableByThief(29) != 0) ++bad;
                    if (rules::m4UsableByThief(30) != 0) ++bad;
                    if (rules::m4UsableByThief(31) != 0) ++bad;
                    if (rules::m4UsableByThief(32) != 0) ++bad;
                    if (rules::m4UsableByThief(33) != 0) ++bad;
                    if (rules::m4UsableByThief(34) != 0) ++bad;
                    if (rules::m4UsableByThief(35) != 0) ++bad;
                    if (rules::m4StarCount(0) != 0) ++bad;
                    if (rules::m4StarCount(1) != 0) ++bad;
                    if (rules::m4StarCount(2) != 0) ++bad;
                    if (rules::m4StarCount(3) != 0) ++bad;
                    if (rules::m4StarCount(4) != 0) ++bad;
                    if (rules::m4StarCount(5) != 0) ++bad;
                    if (rules::m4StarCount(6) != 0) ++bad;
                    if (rules::m4StarCount(7) != 0) ++bad;
                    if (rules::m4StarCount(8) != 0) ++bad;
                    if (rules::m4StarCount(9) != 0) ++bad;
                    if (rules::m4StarCount(10) != 0) ++bad;
                    if (rules::m4StarCount(11) != 0) ++bad;
                    if (rules::m4StarCount(12) != 0) ++bad;
                    if (rules::m4StarCount(13) != 0) ++bad;
                    if (rules::m4StarCount(14) != 0) ++bad;
                    if (rules::m4StarCount(15) != 0) ++bad;
                    if (rules::m4StarCount(16) != 0) ++bad;
                    if (rules::m4StarCount(17) != 0) ++bad;
                    if (rules::m4StarCount(18) != 1) ++bad;
                    if (rules::m4StarCount(19) != 2) ++bad;
                    if (rules::m4StarCount(20) != 0) ++bad;
                    if (rules::m4StarCount(21) != 0) ++bad;
                    if (rules::m4StarCount(22) != 0) ++bad;
                    if (rules::m4StarCount(23) != 3) ++bad;
                    if (rules::m4StarCount(24) != 4) ++bad;
                    if (rules::m4StarCount(25) != 0) ++bad;
                    if (rules::m4StarCount(26) != 0) ++bad;
                    if (rules::m4StarCount(27) != 0) ++bad;
                    if (rules::m4StarCount(28) != 0) ++bad;
                    if (rules::m4StarCount(29) != 0) ++bad;
                    if (rules::m4StarCount(30) != 0) ++bad;
                    if (rules::m4StarCount(31) != 0) ++bad;
                    if (rules::m4StarCount(32) != 0) ++bad;
                    if (rules::m4StarCount(33) != 0) ++bad;
                    if (rules::m4StarCount(34) != 0) ++bad;
                    if (rules::m4StarCount(35) != 0) ++bad;
                    if (rules::m4IsDualValued(0) != 0) ++bad;
                    if (rules::m4IsDualValued(1) != 0) ++bad;
                    if (rules::m4IsDualValued(2) != 0) ++bad;
                    if (rules::m4IsDualValued(3) != 0) ++bad;
                    if (rules::m4IsDualValued(4) != 0) ++bad;
                    if (rules::m4IsDualValued(5) != 0) ++bad;
                    if (rules::m4IsDualValued(6) != 0) ++bad;
                    if (rules::m4IsDualValued(7) != 0) ++bad;
                    if (rules::m4IsDualValued(8) != 0) ++bad;
                    if (rules::m4IsDualValued(9) != 0) ++bad;
                    if (rules::m4IsDualValued(10) != 0) ++bad;
                    if (rules::m4IsDualValued(11) != 0) ++bad;
                    if (rules::m4IsDualValued(12) != 1) ++bad;
                    if (rules::m4IsDualValued(13) != 0) ++bad;
                    if (rules::m4IsDualValued(14) != 0) ++bad;
                    if (rules::m4IsDualValued(15) != 0) ++bad;
                    if (rules::m4IsDualValued(16) != 0) ++bad;
                    if (rules::m4IsDualValued(17) != 0) ++bad;
                    if (rules::m4IsDualValued(18) != 0) ++bad;
                    if (rules::m4IsDualValued(19) != 0) ++bad;
                    if (rules::m4IsDualValued(20) != 0) ++bad;
                    if (rules::m4IsDualValued(21) != 0) ++bad;
                    if (rules::m4IsDualValued(22) != 0) ++bad;
                    if (rules::m4IsDualValued(23) != 0) ++bad;
                    if (rules::m4IsDualValued(24) != 0) ++bad;
                    if (rules::m4IsDualValued(25) != 0) ++bad;
                    if (rules::m4IsDualValued(26) != 0) ++bad;
                    if (rules::m4IsDualValued(27) != 0) ++bad;
                    if (rules::m4IsDualValued(28) != 0) ++bad;
                    if (rules::m4IsDualValued(29) != 0) ++bad;
                    if (rules::m4IsDualValued(30) != 0) ++bad;
                    if (rules::m4IsDualValued(31) != 0) ++bad;
                    if (rules::m4IsDualValued(32) != 0) ++bad;
                    if (rules::m4IsDualValued(33) != 0) ++bad;
                    if (rules::m4IsDualValued(34) != 0) ++bad;
                    if (rules::m4IsDualValued(35) != 1) ++bad;
                }
            }
        }
        printf("R1059 misc-magic registry defs-B audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 5. C -----------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/miscmagic");
            {
                const items::MiscItemDef* d =
                    reg.find("misc_m5");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 1) ++bad;
                    if (d->tables[0]
                        .values[1] != 8) ++bad;
                    if (d->tables[0]
                        .values[2] != 9) ++bad;
                    if (d->tables[0]
                        .values[3] != 10) ++bad;
                    if (d->tables[0]
                        .values[4] != 11) ++bad;
                    if (d->tables[0]
                        .values[5] != 19) ++bad;
                    if (d->tables[0]
                        .values[6] != 25) ++bad;
                    if (d->tables[0]
                        .values[7] != 27) ++bad;
                    if (d->tables[0]
                        .values[8] != 31) ++bad;
                    if (d->tables[0]
                        .values[9] != 32) ++bad;
                    if (d->tables[0]
                        .values[10] != 33) ++bad;
                    if (d->tables[0]
                        .values[11] != 34) ++bad;
                    if (d->tables[0]
                        .values[12] != 35) ++bad;
                    if (d->tables[0]
                        .values[13] != 38) ++bad;
                    if (d->tables[0]
                        .values[14] != 40) ++bad;
                    if (d->tables[0]
                        .values[15] != 46) ++bad;
                    if (d->tables[0]
                        .values[16] != 47) ++bad;
                    if (d->tables[0]
                        .values[17] != 48) ++bad;
                    if (d->tables[0]
                        .values[18] != 50) ++bad;
                    if (d->tables[0]
                        .values[19] != 52) ++bad;
                    if (d->tables[0]
                        .values[20] != 54) ++bad;
                    if (d->tables[0]
                        .values[21] != 57) ++bad;
                    if (d->tables[0]
                        .values[22] != 58) ++bad;
                    if (d->tables[0]
                        .values[23] != 60) ++bad;
                    if (d->tables[0]
                        .values[24] != 66) ++bad;
                    if (d->tables[0]
                        .values[25] != 67) ++bad;
                    if (d->tables[0]
                        .values[26] != 68) ++bad;
                    if (d->tables[0]
                        .values[27] != 69) ++bad;
                    if (d->tables[0]
                        .values[28] != 76) ++bad;
                    if (d->tables[0]
                        .values[29] != 78) ++bad;
                    if (d->tables[0]
                        .values[30] != 83) ++bad;
                    if (d->tables[0]
                        .values[31] != 85) ++bad;
                    if (d->tables[0]
                        .values[32] != 87) ++bad;
                    if (d->tables[0]
                        .values[33] != 90) ++bad;
                    if (d->tables[0]
                        .values[34] != 100) ++bad;
                    if (d->tables[1]
                        .values[0] != 1) ++bad;
                    if (d->tables[1]
                        .values[1] != 2) ++bad;
                    if (d->tables[1]
                        .values[2] != 9) ++bad;
                    if (d->tables[1]
                        .values[3] != 10) ++bad;
                    if (d->tables[1]
                        .values[4] != 11) ++bad;
                    if (d->tables[1]
                        .values[5] != 12) ++bad;
                    if (d->tables[1]
                        .values[6] != 20) ++bad;
                    if (d->tables[1]
                        .values[7] != 26) ++bad;
                    if (d->tables[1]
                        .values[8] != 28) ++bad;
                    if (d->tables[1]
                        .values[9] != 32) ++bad;
                    if (d->tables[1]
                        .values[10] != 33) ++bad;
                    if (d->tables[1]
                        .values[11] != 34) ++bad;
                    if (d->tables[1]
                        .values[12] != 35) ++bad;
                    if (d->tables[1]
                        .values[13] != 36) ++bad;
                    if (d->tables[1]
                        .values[14] != 39) ++bad;
                    if (d->tables[1]
                        .values[15] != 41) ++bad;
                    if (d->tables[1]
                        .values[16] != 47) ++bad;
                    if (d->tables[1]
                        .values[17] != 48) ++bad;
                    if (d->tables[1]
                        .values[18] != 49) ++bad;
                    if (d->tables[1]
                        .values[19] != 51) ++bad;
                    if (d->tables[1]
                        .values[20] != 53) ++bad;
                    if (d->tables[1]
                        .values[21] != 55) ++bad;
                    if (d->tables[1]
                        .values[22] != 58) ++bad;
                    if (d->tables[1]
                        .values[23] != 59) ++bad;
                    if (d->tables[1]
                        .values[24] != 61) ++bad;
                    if (d->tables[1]
                        .values[25] != 67) ++bad;
                    if (d->tables[1]
                        .values[26] != 68) ++bad;
                    if (d->tables[1]
                        .values[27] != 69) ++bad;
                    if (d->tables[1]
                        .values[28] != 70) ++bad;
                    if (d->tables[1]
                        .values[29] != 77) ++bad;
                    if (d->tables[1]
                        .values[30] != 79) ++bad;
                    if (d->tables[1]
                        .values[31] != 84) ++bad;
                    if (d->tables[1]
                        .values[32] != 86) ++bad;
                    if (d->tables[1]
                        .values[33] != 88) ++bad;
                    if (d->tables[1]
                        .values[34] != 91) ++bad;
                    if (d->tables[2]
                        .values[0] != 0) ++bad;
                    if (d->tables[2]
                        .values[1] != 0) ++bad;
                    if (d->tables[2]
                        .values[2] != 0) ++bad;
                    if (d->tables[2]
                        .values[3] != 0) ++bad;
                    if (d->tables[2]
                        .values[4] != 1) ++bad;
                    if (d->tables[2]
                        .values[5] != 0) ++bad;
                    if (d->tables[2]
                        .values[6] != 0) ++bad;
                    if (d->tables[2]
                        .values[7] != 0) ++bad;
                    if (d->tables[2]
                        .values[8] != 0) ++bad;
                    if (d->tables[2]
                        .values[9] != 0) ++bad;
                    if (d->tables[2]
                        .values[10] != 0) ++bad;
                    if (d->tables[2]
                        .values[11] != 0) ++bad;
                    if (d->tables[2]
                        .values[12] != 0) ++bad;
                    if (d->tables[2]
                        .values[13] != 0) ++bad;
                    if (d->tables[2]
                        .values[14] != 0) ++bad;
                    if (d->tables[2]
                        .values[15] != 0) ++bad;
                    if (d->tables[2]
                        .values[16] != 0) ++bad;
                    if (d->tables[2]
                        .values[17] != 0) ++bad;
                    if (d->tables[2]
                        .values[18] != 0) ++bad;
                    if (d->tables[2]
                        .values[19] != 0) ++bad;
                    if (d->tables[2]
                        .values[20] != 0) ++bad;
                    if (d->tables[2]
                        .values[21] != 1) ++bad;
                    if (d->tables[2]
                        .values[22] != 0) ++bad;
                    if (d->tables[2]
                        .values[23] != 1) ++bad;
                    if (d->tables[2]
                        .values[24] != 0) ++bad;
                    if (d->tables[2]
                        .values[25] != 0) ++bad;
                    if (d->tables[2]
                        .values[26] != 0) ++bad;
                    if (d->tables[2]
                        .values[27] != 0) ++bad;
                    if (d->tables[2]
                        .values[28] != 1) ++bad;
                    if (d->tables[2]
                        .values[29] != 0) ++bad;
                    if (d->tables[2]
                        .values[30] != 1) ++bad;
                    if (d->tables[2]
                        .values[31] != 0) ++bad;
                    if (d->tables[2]
                        .values[32] != 0) ++bad;
                    if (d->tables[2]
                        .values[33] != 0) ++bad;
                    if (d->tables[2]
                        .values[34] != 0) ++bad;
                    if (d->tables[3]
                        .values[0] != 0) ++bad;
                    if (d->tables[3]
                        .values[1] != 0) ++bad;
                    if (d->tables[3]
                        .values[2] != 0) ++bad;
                    if (d->tables[3]
                        .values[3] != 0) ++bad;
                    if (d->tables[3]
                        .values[4] != 0) ++bad;
                    if (d->tables[3]
                        .values[5] != 0) ++bad;
                    if (d->tables[3]
                        .values[6] != 0) ++bad;
                    if (d->tables[3]
                        .values[7] != 0) ++bad;
                    if (d->tables[3]
                        .values[8] != 0) ++bad;
                    if (d->tables[3]
                        .values[9] != 0) ++bad;
                    if (d->tables[3]
                        .values[10] != 0) ++bad;
                    if (d->tables[3]
                        .values[11] != 1) ++bad;
                    if (d->tables[3]
                        .values[12] != 0) ++bad;
                    if (d->tables[3]
                        .values[13] != 0) ++bad;
                    if (d->tables[3]
                        .values[14] != 0) ++bad;
                    if (d->tables[3]
                        .values[15] != 0) ++bad;
                    if (d->tables[3]
                        .values[16] != 1) ++bad;
                    if (d->tables[3]
                        .values[17] != 0) ++bad;
                    if (d->tables[3]
                        .values[18] != 0) ++bad;
                    if (d->tables[3]
                        .values[19] != 0) ++bad;
                    if (d->tables[3]
                        .values[20] != 0) ++bad;
                    if (d->tables[3]
                        .values[21] != 0) ++bad;
                    if (d->tables[3]
                        .values[22] != 0) ++bad;
                    if (d->tables[3]
                        .values[23] != 0) ++bad;
                    if (d->tables[3]
                        .values[24] != 0) ++bad;
                    if (d->tables[3]
                        .values[25] != 0) ++bad;
                    if (d->tables[3]
                        .values[26] != 0) ++bad;
                    if (d->tables[3]
                        .values[27] != 0) ++bad;
                    if (d->tables[3]
                        .values[28] != 1) ++bad;
                    if (d->tables[3]
                        .values[29] != 1) ++bad;
                    if (d->tables[3]
                        .values[30] != 1) ++bad;
                    if (d->tables[3]
                        .values[31] != 0) ++bad;
                    if (d->tables[3]
                        .values[32] != 0) ++bad;
                    if (d->tables[3]
                        .values[33] != 0) ++bad;
                    if (d->tables[3]
                        .values[34] != 0) ++bad;
                    if (d->tables[4]
                        .values[0] != 1) ++bad;
                    if (d->tables[4]
                        .values[1] != 0) ++bad;
                    if (d->tables[4]
                        .values[2] != 1) ++bad;
                    if (d->tables[4]
                        .values[3] != 1) ++bad;
                    if (d->tables[4]
                        .values[4] != 1) ++bad;
                    if (d->tables[4]
                        .values[5] != 1) ++bad;
                    if (d->tables[4]
                        .values[6] != 0) ++bad;
                    if (d->tables[4]
                        .values[7] != 0) ++bad;
                    if (d->tables[4]
                        .values[8] != 0) ++bad;
                    if (d->tables[4]
                        .values[9] != 0) ++bad;
                    if (d->tables[4]
                        .values[10] != 1) ++bad;
                    if (d->tables[4]
                        .values[11] != 0) ++bad;
                    if (d->tables[4]
                        .values[12] != 0) ++bad;
                    if (d->tables[4]
                        .values[13] != 0) ++bad;
                    if (d->tables[4]
                        .values[14] != 0) ++bad;
                    if (d->tables[4]
                        .values[15] != 0) ++bad;
                    if (d->tables[4]
                        .values[16] != 0) ++bad;
                    if (d->tables[4]
                        .values[17] != 1) ++bad;
                    if (d->tables[4]
                        .values[18] != 0) ++bad;
                    if (d->tables[4]
                        .values[19] != 0) ++bad;
                    if (d->tables[4]
                        .values[20] != 0) ++bad;
                    if (d->tables[4]
                        .values[21] != 0) ++bad;
                    if (d->tables[4]
                        .values[22] != 1) ++bad;
                    if (d->tables[4]
                        .values[23] != 0) ++bad;
                    if (d->tables[4]
                        .values[24] != 0) ++bad;
                    if (d->tables[4]
                        .values[25] != 0) ++bad;
                    if (d->tables[4]
                        .values[26] != 0) ++bad;
                    if (d->tables[4]
                        .values[27] != 0) ++bad;
                    if (d->tables[4]
                        .values[28] != 0) ++bad;
                    if (d->tables[4]
                        .values[29] != 0) ++bad;
                    if (d->tables[4]
                        .values[30] != 0) ++bad;
                    if (d->tables[4]
                        .values[31] != 0) ++bad;
                    if (d->tables[4]
                        .values[32] != 0) ++bad;
                    if (d->tables[4]
                        .values[33] != 0) ++bad;
                    if (d->tables[4]
                        .values[34] != 0) ++bad;
                    if (d->tables[5]
                        .values[0] != 0) ++bad;
                    if (d->tables[5]
                        .values[1] != 0) ++bad;
                    if (d->tables[5]
                        .values[2] != 0) ++bad;
                    if (d->tables[5]
                        .values[3] != 0) ++bad;
                    if (d->tables[5]
                        .values[4] != 0) ++bad;
                    if (d->tables[5]
                        .values[5] != 0) ++bad;
                    if (d->tables[5]
                        .values[6] != 0) ++bad;
                    if (d->tables[5]
                        .values[7] != 0) ++bad;
                    if (d->tables[5]
                        .values[8] != 0) ++bad;
                    if (d->tables[5]
                        .values[9] != 0) ++bad;
                    if (d->tables[5]
                        .values[10] != 0) ++bad;
                    if (d->tables[5]
                        .values[11] != 0) ++bad;
                    if (d->tables[5]
                        .values[12] != 0) ++bad;
                    if (d->tables[5]
                        .values[13] != 0) ++bad;
                    if (d->tables[5]
                        .values[14] != 0) ++bad;
                    if (d->tables[5]
                        .values[15] != 0) ++bad;
                    if (d->tables[5]
                        .values[16] != 0) ++bad;
                    if (d->tables[5]
                        .values[17] != 0) ++bad;
                    if (d->tables[5]
                        .values[18] != 0) ++bad;
                    if (d->tables[5]
                        .values[19] != 0) ++bad;
                    if (d->tables[5]
                        .values[20] != 0) ++bad;
                    if (d->tables[5]
                        .values[21] != 0) ++bad;
                    if (d->tables[5]
                        .values[22] != 0) ++bad;
                    if (d->tables[5]
                        .values[23] != 0) ++bad;
                    if (d->tables[5]
                        .values[24] != 0) ++bad;
                    if (d->tables[5]
                        .values[25] != 0) ++bad;
                    if (d->tables[5]
                        .values[26] != 0) ++bad;
                    if (d->tables[5]
                        .values[27] != 0) ++bad;
                    if (d->tables[5]
                        .values[28] != 1) ++bad;
                    if (d->tables[5]
                        .values[29] != 0) ++bad;
                    if (d->tables[5]
                        .values[30] != 1) ++bad;
                    if (d->tables[5]
                        .values[31] != 0) ++bad;
                    if (d->tables[5]
                        .values[32] != 0) ++bad;
                    if (d->tables[5]
                        .values[33] != 0) ++bad;
                    if (d->tables[5]
                        .values[34] != 0) ++bad;
                    if (rules::m5RowLo(0) != 1) ++bad;
                    if (rules::m5RowLo(1) != 2) ++bad;
                    if (rules::m5RowLo(2) != 9) ++bad;
                    if (rules::m5RowLo(3) != 10) ++bad;
                    if (rules::m5RowLo(4) != 11) ++bad;
                    if (rules::m5RowLo(5) != 12) ++bad;
                    if (rules::m5RowLo(6) != 20) ++bad;
                    if (rules::m5RowLo(7) != 26) ++bad;
                    if (rules::m5RowLo(8) != 28) ++bad;
                    if (rules::m5RowLo(9) != 32) ++bad;
                    if (rules::m5RowLo(10) != 33) ++bad;
                    if (rules::m5RowLo(11) != 34) ++bad;
                    if (rules::m5RowLo(12) != 35) ++bad;
                    if (rules::m5RowLo(13) != 36) ++bad;
                    if (rules::m5RowLo(14) != 39) ++bad;
                    if (rules::m5RowLo(15) != 41) ++bad;
                    if (rules::m5RowLo(16) != 47) ++bad;
                    if (rules::m5RowLo(17) != 48) ++bad;
                    if (rules::m5RowLo(18) != 49) ++bad;
                    if (rules::m5RowLo(19) != 51) ++bad;
                    if (rules::m5RowLo(20) != 53) ++bad;
                    if (rules::m5RowLo(21) != 55) ++bad;
                    if (rules::m5RowLo(22) != 58) ++bad;
                    if (rules::m5RowLo(23) != 59) ++bad;
                    if (rules::m5RowLo(24) != 61) ++bad;
                    if (rules::m5RowLo(25) != 67) ++bad;
                    if (rules::m5RowLo(26) != 68) ++bad;
                    if (rules::m5RowLo(27) != 69) ++bad;
                    if (rules::m5RowLo(28) != 70) ++bad;
                    if (rules::m5RowLo(29) != 77) ++bad;
                    if (rules::m5RowLo(30) != 79) ++bad;
                    if (rules::m5RowLo(31) != 84) ++bad;
                    if (rules::m5RowLo(32) != 86) ++bad;
                    if (rules::m5RowLo(33) != 88) ++bad;
                    if (rules::m5RowLo(34) != 91) ++bad;
                    if (rules::m5RowHi(0) != 1) ++bad;
                    if (rules::m5RowHi(1) != 8) ++bad;
                    if (rules::m5RowHi(2) != 9) ++bad;
                    if (rules::m5RowHi(3) != 10) ++bad;
                    if (rules::m5RowHi(4) != 11) ++bad;
                    if (rules::m5RowHi(5) != 19) ++bad;
                    if (rules::m5RowHi(6) != 25) ++bad;
                    if (rules::m5RowHi(7) != 27) ++bad;
                    if (rules::m5RowHi(8) != 31) ++bad;
                    if (rules::m5RowHi(9) != 32) ++bad;
                    if (rules::m5RowHi(10) != 33) ++bad;
                    if (rules::m5RowHi(11) != 34) ++bad;
                    if (rules::m5RowHi(12) != 35) ++bad;
                    if (rules::m5RowHi(13) != 38) ++bad;
                    if (rules::m5RowHi(14) != 40) ++bad;
                    if (rules::m5RowHi(15) != 46) ++bad;
                    if (rules::m5RowHi(16) != 47) ++bad;
                    if (rules::m5RowHi(17) != 48) ++bad;
                    if (rules::m5RowHi(18) != 50) ++bad;
                    if (rules::m5RowHi(19) != 52) ++bad;
                    if (rules::m5RowHi(20) != 54) ++bad;
                    if (rules::m5RowHi(21) != 57) ++bad;
                    if (rules::m5RowHi(22) != 58) ++bad;
                    if (rules::m5RowHi(23) != 60) ++bad;
                    if (rules::m5RowHi(24) != 66) ++bad;
                    if (rules::m5RowHi(25) != 67) ++bad;
                    if (rules::m5RowHi(26) != 68) ++bad;
                    if (rules::m5RowHi(27) != 69) ++bad;
                    if (rules::m5RowHi(28) != 76) ++bad;
                    if (rules::m5RowHi(29) != 78) ++bad;
                    if (rules::m5RowHi(30) != 83) ++bad;
                    if (rules::m5RowHi(31) != 85) ++bad;
                    if (rules::m5RowHi(32) != 87) ++bad;
                    if (rules::m5RowHi(33) != 90) ++bad;
                    if (rules::m5RowHi(34) != 100) ++bad;
                    if (rules::m5UsableByCleric(0) != 0) ++bad;
                    if (rules::m5UsableByCleric(1) != 0) ++bad;
                    if (rules::m5UsableByCleric(2) != 0) ++bad;
                    if (rules::m5UsableByCleric(3) != 0) ++bad;
                    if (rules::m5UsableByCleric(4) != 1) ++bad;
                    if (rules::m5UsableByCleric(5) != 0) ++bad;
                    if (rules::m5UsableByCleric(6) != 0) ++bad;
                    if (rules::m5UsableByCleric(7) != 0) ++bad;
                    if (rules::m5UsableByCleric(8) != 0) ++bad;
                    if (rules::m5UsableByCleric(9) != 0) ++bad;
                    if (rules::m5UsableByCleric(10) != 0) ++bad;
                    if (rules::m5UsableByCleric(11) != 0) ++bad;
                    if (rules::m5UsableByCleric(12) != 0) ++bad;
                    if (rules::m5UsableByCleric(13) != 0) ++bad;
                    if (rules::m5UsableByCleric(14) != 0) ++bad;
                    if (rules::m5UsableByCleric(15) != 0) ++bad;
                    if (rules::m5UsableByCleric(16) != 0) ++bad;
                    if (rules::m5UsableByCleric(17) != 0) ++bad;
                    if (rules::m5UsableByCleric(18) != 0) ++bad;
                    if (rules::m5UsableByCleric(19) != 0) ++bad;
                    if (rules::m5UsableByCleric(20) != 0) ++bad;
                    if (rules::m5UsableByCleric(21) != 1) ++bad;
                    if (rules::m5UsableByCleric(22) != 0) ++bad;
                    if (rules::m5UsableByCleric(23) != 1) ++bad;
                    if (rules::m5UsableByCleric(24) != 0) ++bad;
                    if (rules::m5UsableByCleric(25) != 0) ++bad;
                    if (rules::m5UsableByCleric(26) != 0) ++bad;
                    if (rules::m5UsableByCleric(27) != 0) ++bad;
                    if (rules::m5UsableByCleric(28) != 1) ++bad;
                    if (rules::m5UsableByCleric(29) != 0) ++bad;
                    if (rules::m5UsableByCleric(30) != 1) ++bad;
                    if (rules::m5UsableByCleric(31) != 0) ++bad;
                    if (rules::m5UsableByCleric(32) != 0) ++bad;
                    if (rules::m5UsableByCleric(33) != 0) ++bad;
                    if (rules::m5UsableByCleric(34) != 0) ++bad;
                    if (rules::m5UsableByFighter(0) != 0) ++bad;
                    if (rules::m5UsableByFighter(1) != 0) ++bad;
                    if (rules::m5UsableByFighter(2) != 0) ++bad;
                    if (rules::m5UsableByFighter(3) != 0) ++bad;
                    if (rules::m5UsableByFighter(4) != 0) ++bad;
                    if (rules::m5UsableByFighter(5) != 0) ++bad;
                    if (rules::m5UsableByFighter(6) != 0) ++bad;
                    if (rules::m5UsableByFighter(7) != 0) ++bad;
                    if (rules::m5UsableByFighter(8) != 0) ++bad;
                    if (rules::m5UsableByFighter(9) != 0) ++bad;
                    if (rules::m5UsableByFighter(10) != 0) ++bad;
                    if (rules::m5UsableByFighter(11) != 1) ++bad;
                    if (rules::m5UsableByFighter(12) != 0) ++bad;
                    if (rules::m5UsableByFighter(13) != 0) ++bad;
                    if (rules::m5UsableByFighter(14) != 0) ++bad;
                    if (rules::m5UsableByFighter(15) != 0) ++bad;
                    if (rules::m5UsableByFighter(16) != 1) ++bad;
                    if (rules::m5UsableByFighter(17) != 0) ++bad;
                    if (rules::m5UsableByFighter(18) != 0) ++bad;
                    if (rules::m5UsableByFighter(19) != 0) ++bad;
                    if (rules::m5UsableByFighter(20) != 0) ++bad;
                    if (rules::m5UsableByFighter(21) != 0) ++bad;
                    if (rules::m5UsableByFighter(22) != 0) ++bad;
                    if (rules::m5UsableByFighter(23) != 0) ++bad;
                    if (rules::m5UsableByFighter(24) != 0) ++bad;
                    if (rules::m5UsableByFighter(25) != 0) ++bad;
                    if (rules::m5UsableByFighter(26) != 0) ++bad;
                    if (rules::m5UsableByFighter(27) != 0) ++bad;
                    if (rules::m5UsableByFighter(28) != 1) ++bad;
                    if (rules::m5UsableByFighter(29) != 1) ++bad;
                    if (rules::m5UsableByFighter(30) != 1) ++bad;
                    if (rules::m5UsableByFighter(31) != 0) ++bad;
                    if (rules::m5UsableByFighter(32) != 0) ++bad;
                    if (rules::m5UsableByFighter(33) != 0) ++bad;
                    if (rules::m5UsableByFighter(34) != 0) ++bad;
                    if (rules::m5UsableByMagicUser(0) != 1) ++bad;
                    if (rules::m5UsableByMagicUser(1) != 0) ++bad;
                    if (rules::m5UsableByMagicUser(2) != 1) ++bad;
                    if (rules::m5UsableByMagicUser(3) != 1) ++bad;
                    if (rules::m5UsableByMagicUser(4) != 1) ++bad;
                    if (rules::m5UsableByMagicUser(5) != 1) ++bad;
                    if (rules::m5UsableByMagicUser(6) != 0) ++bad;
                    if (rules::m5UsableByMagicUser(7) != 0) ++bad;
                    if (rules::m5UsableByMagicUser(8) != 0) ++bad;
                    if (rules::m5UsableByMagicUser(9) != 0) ++bad;
                    if (rules::m5UsableByMagicUser(10) != 1) ++bad;
                    if (rules::m5UsableByMagicUser(11) != 0) ++bad;
                    if (rules::m5UsableByMagicUser(12) != 0) ++bad;
                    if (rules::m5UsableByMagicUser(13) != 0) ++bad;
                    if (rules::m5UsableByMagicUser(14) != 0) ++bad;
                    if (rules::m5UsableByMagicUser(15) != 0) ++bad;
                    if (rules::m5UsableByMagicUser(16) != 0) ++bad;
                    if (rules::m5UsableByMagicUser(17) != 1) ++bad;
                    if (rules::m5UsableByMagicUser(18) != 0) ++bad;
                    if (rules::m5UsableByMagicUser(19) != 0) ++bad;
                    if (rules::m5UsableByMagicUser(20) != 0) ++bad;
                    if (rules::m5UsableByMagicUser(21) != 0) ++bad;
                    if (rules::m5UsableByMagicUser(22) != 1) ++bad;
                    if (rules::m5UsableByMagicUser(23) != 0) ++bad;
                    if (rules::m5UsableByMagicUser(24) != 0) ++bad;
                    if (rules::m5UsableByMagicUser(25) != 0) ++bad;
                    if (rules::m5UsableByMagicUser(26) != 0) ++bad;
                    if (rules::m5UsableByMagicUser(27) != 0) ++bad;
                    if (rules::m5UsableByMagicUser(28) != 0) ++bad;
                    if (rules::m5UsableByMagicUser(29) != 0) ++bad;
                    if (rules::m5UsableByMagicUser(30) != 0) ++bad;
                    if (rules::m5UsableByMagicUser(31) != 0) ++bad;
                    if (rules::m5UsableByMagicUser(32) != 0) ++bad;
                    if (rules::m5UsableByMagicUser(33) != 0) ++bad;
                    if (rules::m5UsableByMagicUser(34) != 0) ++bad;
                    if (rules::m5UsableByThief(0) != 0) ++bad;
                    if (rules::m5UsableByThief(1) != 0) ++bad;
                    if (rules::m5UsableByThief(2) != 0) ++bad;
                    if (rules::m5UsableByThief(3) != 0) ++bad;
                    if (rules::m5UsableByThief(4) != 0) ++bad;
                    if (rules::m5UsableByThief(5) != 0) ++bad;
                    if (rules::m5UsableByThief(6) != 0) ++bad;
                    if (rules::m5UsableByThief(7) != 0) ++bad;
                    if (rules::m5UsableByThief(8) != 0) ++bad;
                    if (rules::m5UsableByThief(9) != 0) ++bad;
                    if (rules::m5UsableByThief(10) != 0) ++bad;
                    if (rules::m5UsableByThief(11) != 0) ++bad;
                    if (rules::m5UsableByThief(12) != 0) ++bad;
                    if (rules::m5UsableByThief(13) != 0) ++bad;
                    if (rules::m5UsableByThief(14) != 0) ++bad;
                    if (rules::m5UsableByThief(15) != 0) ++bad;
                    if (rules::m5UsableByThief(16) != 0) ++bad;
                    if (rules::m5UsableByThief(17) != 0) ++bad;
                    if (rules::m5UsableByThief(18) != 0) ++bad;
                    if (rules::m5UsableByThief(19) != 0) ++bad;
                    if (rules::m5UsableByThief(20) != 0) ++bad;
                    if (rules::m5UsableByThief(21) != 0) ++bad;
                    if (rules::m5UsableByThief(22) != 0) ++bad;
                    if (rules::m5UsableByThief(23) != 0) ++bad;
                    if (rules::m5UsableByThief(24) != 0) ++bad;
                    if (rules::m5UsableByThief(25) != 0) ++bad;
                    if (rules::m5UsableByThief(26) != 0) ++bad;
                    if (rules::m5UsableByThief(27) != 0) ++bad;
                    if (rules::m5UsableByThief(28) != 1) ++bad;
                    if (rules::m5UsableByThief(29) != 0) ++bad;
                    if (rules::m5UsableByThief(30) != 1) ++bad;
                    if (rules::m5UsableByThief(31) != 0) ++bad;
                    if (rules::m5UsableByThief(32) != 0) ++bad;
                    if (rules::m5UsableByThief(33) != 0) ++bad;
                    if (rules::m5UsableByThief(34) != 0) ++bad;
                }
            }
        }
        printf("R1059 misc-magic registry defs-C audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 6. D -----------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/miscmagic");
            {
                const items::MiscItemDef* d =
                    reg.find("wonder");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 10) ++bad;
                    if (d->tables[0]
                        .values[1] != 18) ++bad;
                    if (d->tables[0]
                        .values[2] != 25) ++bad;
                    if (d->tables[0]
                        .values[3] != 30) ++bad;
                    if (d->tables[0]
                        .values[4] != 33) ++bad;
                    if (d->tables[0]
                        .values[5] != 36) ++bad;
                    if (d->tables[0]
                        .values[6] != 46) ++bad;
                    if (d->tables[0]
                        .values[7] != 49) ++bad;
                    if (d->tables[0]
                        .values[8] != 53) ++bad;
                    if (d->tables[0]
                        .values[9] != 58) ++bad;
                    if (d->tables[0]
                        .values[10] != 62) ++bad;
                    if (d->tables[0]
                        .values[11] != 65) ++bad;
                    if (d->tables[0]
                        .values[12] != 69) ++bad;
                    if (d->tables[0]
                        .values[13] != 79) ++bad;
                    if (d->tables[0]
                        .values[14] != 84) ++bad;
                    if (d->tables[0]
                        .values[15] != 87) ++bad;
                    if (d->tables[0]
                        .values[16] != 90) ++bad;
                    if (d->tables[0]
                        .values[17] != 97) ++bad;
                    if (d->tables[0]
                        .values[18] != 100) ++bad;
                    if (d->tables[1]
                        .values[0] != 1) ++bad;
                    if (d->tables[1]
                        .values[1] != 11) ++bad;
                    if (d->tables[1]
                        .values[2] != 19) ++bad;
                    if (d->tables[1]
                        .values[3] != 26) ++bad;
                    if (d->tables[1]
                        .values[4] != 31) ++bad;
                    if (d->tables[1]
                        .values[5] != 34) ++bad;
                    if (d->tables[1]
                        .values[6] != 37) ++bad;
                    if (d->tables[1]
                        .values[7] != 47) ++bad;
                    if (d->tables[1]
                        .values[8] != 50) ++bad;
                    if (d->tables[1]
                        .values[9] != 54) ++bad;
                    if (d->tables[1]
                        .values[10] != 59) ++bad;
                    if (d->tables[1]
                        .values[11] != 63) ++bad;
                    if (d->tables[1]
                        .values[12] != 66) ++bad;
                    if (d->tables[1]
                        .values[13] != 70) ++bad;
                    if (d->tables[1]
                        .values[14] != 80) ++bad;
                    if (d->tables[1]
                        .values[15] != 85) ++bad;
                    if (d->tables[1]
                        .values[16] != 88) ++bad;
                    if (d->tables[1]
                        .values[17] != 91) ++bad;
                    if (d->tables[1]
                        .values[18] != 98) ++bad;
                    if (rules::wonderRowLo(0) != 1) ++bad;
                    if (rules::wonderRowLo(1) != 11) ++bad;
                    if (rules::wonderRowLo(2) != 19) ++bad;
                    if (rules::wonderRowLo(3) != 26) ++bad;
                    if (rules::wonderRowLo(4) != 31) ++bad;
                    if (rules::wonderRowLo(5) != 34) ++bad;
                    if (rules::wonderRowLo(6) != 37) ++bad;
                    if (rules::wonderRowLo(7) != 47) ++bad;
                    if (rules::wonderRowLo(8) != 50) ++bad;
                    if (rules::wonderRowLo(9) != 54) ++bad;
                    if (rules::wonderRowLo(10) != 59) ++bad;
                    if (rules::wonderRowLo(11) != 63) ++bad;
                    if (rules::wonderRowLo(12) != 66) ++bad;
                    if (rules::wonderRowLo(13) != 70) ++bad;
                    if (rules::wonderRowLo(14) != 80) ++bad;
                    if (rules::wonderRowLo(15) != 85) ++bad;
                    if (rules::wonderRowLo(16) != 88) ++bad;
                    if (rules::wonderRowLo(17) != 91) ++bad;
                    if (rules::wonderRowLo(18) != 98) ++bad;
                    if (rules::wonderRowHi(0) != 10) ++bad;
                    if (rules::wonderRowHi(1) != 18) ++bad;
                    if (rules::wonderRowHi(2) != 25) ++bad;
                    if (rules::wonderRowHi(3) != 30) ++bad;
                    if (rules::wonderRowHi(4) != 33) ++bad;
                    if (rules::wonderRowHi(5) != 36) ++bad;
                    if (rules::wonderRowHi(6) != 46) ++bad;
                    if (rules::wonderRowHi(7) != 49) ++bad;
                    if (rules::wonderRowHi(8) != 53) ++bad;
                    if (rules::wonderRowHi(9) != 58) ++bad;
                    if (rules::wonderRowHi(10) != 62) ++bad;
                    if (rules::wonderRowHi(11) != 65) ++bad;
                    if (rules::wonderRowHi(12) != 69) ++bad;
                    if (rules::wonderRowHi(13) != 79) ++bad;
                    if (rules::wonderRowHi(14) != 84) ++bad;
                    if (rules::wonderRowHi(15) != 87) ++bad;
                    if (rules::wonderRowHi(16) != 90) ++bad;
                    if (rules::wonderRowHi(17) != 97) ++bad;
                    if (rules::wonderRowHi(18) != 100) ++bad;
                }
            }
        }
        printf("R1059 misc-magic registry defs-D audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 7. seam ----------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/miscmagic");
            {
                const items::MiscItemDef* d =
                    reg.find("misc_m1");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < 33; ++i)
                        if (rules::m1RowLo(0 + i)
                            != (int)d->tables[4].values[i])
                            ++bad;
                    for (int i = 0; i < 33; ++i)
                        if (rules::m1RowHi(0 + i)
                            != (int)d->tables[3].values[i])
                            ++bad;
                    for (int i = 0; i < 33; ++i)
                        if (rules::m1UsableByMagicUser(0 + i)
                            != (int)d->tables[6].values[i])
                            ++bad;
                    for (int i = 0; i < 33; ++i)
                        if (rules::m1UsableByCleric(0 + i)
                            != (int)d->tables[5].values[i])
                            ++bad;
                    for (int i = 0; i < 33; ++i)
                        if (rules::m1IsArtifactRelicRow(0 + i)
                            != (int)d->tables[0].values[i])
                            ++bad;
                    for (int i = 0; i < 33; ++i)
                        if (rules::m1IsPerAcPointValued(0 + i)
                            != (int)d->tables[1].values[i])
                            ++bad;
                    for (int i = 0; i < 33; ++i)
                        if (rules::m1IsTieredPurseRow(0 + i)
                            != (int)d->tables[2].values[i])
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("misc_m2");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < 30; ++i)
                        if (rules::m2RowLo(0 + i)
                            != (int)d->tables[4].values[i])
                            ++bad;
                    for (int i = 0; i < 30; ++i)
                        if (rules::m2RowHi(0 + i)
                            != (int)d->tables[3].values[i])
                            ++bad;
                    for (int i = 0; i < 30; ++i)
                        if (rules::m2UsableByCleric(0 + i)
                            != (int)d->tables[5].values[i])
                            ++bad;
                    for (int i = 0; i < 30; ++i)
                        if (rules::m2UsableByMagicUser(0 + i)
                            != (int)d->tables[6].values[i])
                            ++bad;
                    for (int i = 0; i < 30; ++i)
                        if (rules::m2IsPerPlusValued(0 + i)
                            != (int)d->tables[1].values[i])
                            ++bad;
                    for (int i = 0; i < 30; ++i)
                        if (rules::m2HasFeatureAsterisk(0 + i)
                            != (int)d->tables[0].values[i])
                            ++bad;
                    for (int i = 0; i < 30; ++i)
                        if (rules::m2IsTripleStar(0 + i)
                            != (int)d->tables[2].values[i])
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("misc_m3");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < 33; ++i)
                        if (rules::m3RowLo(0 + i)
                            != (int)d->tables[2].values[i])
                            ++bad;
                    for (int i = 0; i < 33; ++i)
                        if (rules::m3RowHi(0 + i)
                            != (int)d->tables[1].values[i])
                            ++bad;
                    for (int i = 0; i < 33; ++i)
                        if (rules::m3UsableByCleric(0 + i)
                            != (int)d->tables[4].values[i])
                            ++bad;
                    for (int i = 0; i < 33; ++i)
                        if (rules::m3UsableByFighter(0 + i)
                            != (int)d->tables[5].values[i])
                            ++bad;
                    for (int i = 0; i < 33; ++i)
                        if (rules::m3UsableByThief(0 + i)
                            != (int)d->tables[6].values[i])
                            ++bad;
                    for (int i = 0; i < 33; ++i)
                        if (rules::m3StarCount(0 + i)
                            != (int)d->tables[3].values[i])
                            ++bad;
                    for (int i = 0; i < 33; ++i)
                        if (rules::m3IsPerFacetValued(0 + i)
                            != (int)d->tables[0].values[i])
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("misc_m4");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < 36; ++i)
                        if (rules::m4RowLo(0 + i)
                            != (int)d->tables[2].values[i])
                            ++bad;
                    for (int i = 0; i < 36; ++i)
                        if (rules::m4RowHi(0 + i)
                            != (int)d->tables[1].values[i])
                            ++bad;
                    for (int i = 0; i < 36; ++i)
                        if (rules::m4UsableByCleric(0 + i)
                            != (int)d->tables[4].values[i])
                            ++bad;
                    for (int i = 0; i < 36; ++i)
                        if (rules::m4UsableByFighter(0 + i)
                            != (int)d->tables[5].values[i])
                            ++bad;
                    for (int i = 0; i < 36; ++i)
                        if (rules::m4UsableByMagicUser(0 + i)
                            != (int)d->tables[6].values[i])
                            ++bad;
                    for (int i = 0; i < 36; ++i)
                        if (rules::m4UsableByThief(0 + i)
                            != (int)d->tables[7].values[i])
                            ++bad;
                    for (int i = 0; i < 36; ++i)
                        if (rules::m4StarCount(0 + i)
                            != (int)d->tables[3].values[i])
                            ++bad;
                    for (int i = 0; i < 36; ++i)
                        if (rules::m4IsDualValued(0 + i)
                            != (int)d->tables[0].values[i])
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("misc_m5");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < 35; ++i)
                        if (rules::m5RowLo(0 + i)
                            != (int)d->tables[1].values[i])
                            ++bad;
                    for (int i = 0; i < 35; ++i)
                        if (rules::m5RowHi(0 + i)
                            != (int)d->tables[0].values[i])
                            ++bad;
                    for (int i = 0; i < 35; ++i)
                        if (rules::m5UsableByCleric(0 + i)
                            != (int)d->tables[2].values[i])
                            ++bad;
                    for (int i = 0; i < 35; ++i)
                        if (rules::m5UsableByFighter(0 + i)
                            != (int)d->tables[3].values[i])
                            ++bad;
                    for (int i = 0; i < 35; ++i)
                        if (rules::m5UsableByMagicUser(0 + i)
                            != (int)d->tables[4].values[i])
                            ++bad;
                    for (int i = 0; i < 35; ++i)
                        if (rules::m5UsableByThief(0 + i)
                            != (int)d->tables[5].values[i])
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("wonder");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < 19; ++i)
                        if (rules::wonderRowLo(0 + i)
                            != (int)d->tables[1].values[i])
                            ++bad;
                    for (int i = 0; i < 19; ++i)
                        if (rules::wonderRowHi(0 + i)
                            != (int)d->tables[0].values[i])
                            ++bad;
                }
            }
        }
        printf("R1059 misc-magic registry seam audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 8. edges ------------------------------
        {
            if (rules::m1RowLo(-1) != 1)
                ++bad;
            if (rules::m1RowLo(0) != 1)
                ++bad;
            if (rules::m1RowLo(33) != 99)
                ++bad;
            if (rules::m1RowHi(-1) != 2)
                ++bad;
            if (rules::m1RowHi(0) != 2)
                ++bad;
            if (rules::m1RowHi(33) != 100)
                ++bad;
            if (rules::m1UsableByMagicUser(-1) != 0)
                ++bad;
            if (rules::m1UsableByMagicUser(0) != 0)
                ++bad;
            if (rules::m1UsableByMagicUser(33) != 0)
                ++bad;
            if (rules::m1UsableByCleric(-1) != 0)
                ++bad;
            if (rules::m1UsableByCleric(0) != 0)
                ++bad;
            if (rules::m1UsableByCleric(33) != 0)
                ++bad;
            if (rules::m1IsArtifactRelicRow(-1) != 0)
                ++bad;
            if (rules::m1IsArtifactRelicRow(0) != 0)
                ++bad;
            if (rules::m1IsArtifactRelicRow(33) != 0)
                ++bad;
            if (rules::m1IsPerAcPointValued(-1) != 0)
                ++bad;
            if (rules::m1IsPerAcPointValued(0) != 0)
                ++bad;
            if (rules::m1IsPerAcPointValued(33) != 0)
                ++bad;
            if (rules::m1IsTieredPurseRow(-1) != 0)
                ++bad;
            if (rules::m1IsTieredPurseRow(0) != 0)
                ++bad;
            if (rules::m1IsTieredPurseRow(33) != 1)
                ++bad;
            if (rules::m2RowLo(-1) != 1)
                ++bad;
            if (rules::m2RowLo(0) != 1)
                ++bad;
            if (rules::m2RowLo(30) != 100)
                ++bad;
            if (rules::m2RowHi(-1) != 6)
                ++bad;
            if (rules::m2RowHi(0) != 6)
                ++bad;
            if (rules::m2RowHi(30) != 100)
                ++bad;
            if (rules::m2UsableByCleric(-1) != 1)
                ++bad;
            if (rules::m2UsableByCleric(0) != 1)
                ++bad;
            if (rules::m2UsableByCleric(30) != 0)
                ++bad;
            if (rules::m2UsableByMagicUser(-1) != 0)
                ++bad;
            if (rules::m2UsableByMagicUser(0) != 0)
                ++bad;
            if (rules::m2UsableByMagicUser(30) != 0)
                ++bad;
            if (rules::m2IsPerPlusValued(-1) != 0)
                ++bad;
            if (rules::m2IsPerPlusValued(0) != 0)
                ++bad;
            if (rules::m2IsPerPlusValued(30) != 0)
                ++bad;
            if (rules::m2HasFeatureAsterisk(-1) != 0)
                ++bad;
            if (rules::m2HasFeatureAsterisk(0) != 0)
                ++bad;
            if (rules::m2HasFeatureAsterisk(30) != 0)
                ++bad;
            if (rules::m2IsTripleStar(-1) != 0)
                ++bad;
            if (rules::m2IsTripleStar(0) != 0)
                ++bad;
            if (rules::m2IsTripleStar(30) != 1)
                ++bad;
            if (rules::m3RowLo(-1) != 1)
                ++bad;
            if (rules::m3RowLo(0) != 1)
                ++bad;
            if (rules::m3RowLo(33) != 93)
                ++bad;
            if (rules::m3RowHi(-1) != 15)
                ++bad;
            if (rules::m3RowHi(0) != 15)
                ++bad;
            if (rules::m3RowHi(33) != 100)
                ++bad;
            if (rules::m3UsableByCleric(-1) != 0)
                ++bad;
            if (rules::m3UsableByCleric(0) != 0)
                ++bad;
            if (rules::m3UsableByCleric(33) != 0)
                ++bad;
            if (rules::m3UsableByFighter(-1) != 0)
                ++bad;
            if (rules::m3UsableByFighter(0) != 0)
                ++bad;
            if (rules::m3UsableByFighter(33) != 0)
                ++bad;
            if (rules::m3UsableByThief(-1) != 0)
                ++bad;
            if (rules::m3UsableByThief(0) != 0)
                ++bad;
            if (rules::m3UsableByThief(33) != 0)
                ++bad;
            if (rules::m3StarCount(-1) != 1)
                ++bad;
            if (rules::m3StarCount(0) != 1)
                ++bad;
            if (rules::m3StarCount(33) != 0)
                ++bad;
            if (rules::m3IsPerFacetValued(-1) != 0)
                ++bad;
            if (rules::m3IsPerFacetValued(0) != 0)
                ++bad;
            if (rules::m3IsPerFacetValued(33) != 0)
                ++bad;
            if (rules::m4RowLo(-1) != 1)
                ++bad;
            if (rules::m4RowLo(0) != 1)
                ++bad;
            if (rules::m4RowLo(36) != 86)
                ++bad;
            if (rules::m4RowHi(-1) != 1)
                ++bad;
            if (rules::m4RowHi(0) != 1)
                ++bad;
            if (rules::m4RowHi(36) != 100)
                ++bad;
            if (rules::m4UsableByCleric(-1) != 0)
                ++bad;
            if (rules::m4UsableByCleric(0) != 0)
                ++bad;
            if (rules::m4UsableByCleric(36) != 0)
                ++bad;
            if (rules::m4UsableByFighter(-1) != 0)
                ++bad;
            if (rules::m4UsableByFighter(0) != 0)
                ++bad;
            if (rules::m4UsableByFighter(36) != 0)
                ++bad;
            if (rules::m4UsableByMagicUser(-1) != 1)
                ++bad;
            if (rules::m4UsableByMagicUser(0) != 1)
                ++bad;
            if (rules::m4UsableByMagicUser(36) != 0)
                ++bad;
            if (rules::m4UsableByThief(-1) != 0)
                ++bad;
            if (rules::m4UsableByThief(0) != 0)
                ++bad;
            if (rules::m4UsableByThief(36) != 0)
                ++bad;
            if (rules::m4StarCount(-1) != 0)
                ++bad;
            if (rules::m4StarCount(0) != 0)
                ++bad;
            if (rules::m4StarCount(36) != 0)
                ++bad;
            if (rules::m4IsDualValued(-1) != 0)
                ++bad;
            if (rules::m4IsDualValued(0) != 0)
                ++bad;
            if (rules::m4IsDualValued(36) != 1)
                ++bad;
            if (rules::m5RowLo(-1) != 1)
                ++bad;
            if (rules::m5RowLo(0) != 1)
                ++bad;
            if (rules::m5RowLo(35) != 91)
                ++bad;
            if (rules::m5RowHi(-1) != 1)
                ++bad;
            if (rules::m5RowHi(0) != 1)
                ++bad;
            if (rules::m5RowHi(35) != 100)
                ++bad;
            if (rules::m5UsableByCleric(-1) != 0)
                ++bad;
            if (rules::m5UsableByCleric(0) != 0)
                ++bad;
            if (rules::m5UsableByCleric(35) != 0)
                ++bad;
            if (rules::m5UsableByFighter(-1) != 0)
                ++bad;
            if (rules::m5UsableByFighter(0) != 0)
                ++bad;
            if (rules::m5UsableByFighter(35) != 0)
                ++bad;
            if (rules::m5UsableByMagicUser(-1) != 1)
                ++bad;
            if (rules::m5UsableByMagicUser(0) != 1)
                ++bad;
            if (rules::m5UsableByMagicUser(35) != 0)
                ++bad;
            if (rules::m5UsableByThief(-1) != 0)
                ++bad;
            if (rules::m5UsableByThief(0) != 0)
                ++bad;
            if (rules::m5UsableByThief(35) != 0)
                ++bad;
            if (rules::wonderRowLo(-1) != 1)
                ++bad;
            if (rules::wonderRowLo(0) != 1)
                ++bad;
            if (rules::wonderRowLo(19) != 98)
                ++bad;
            if (rules::wonderRowHi(-1) != 10)
                ++bad;
            if (rules::wonderRowHi(0) != 10)
                ++bad;
            if (rules::wonderRowHi(19) != 100)
                ++bad;
            if (rules::m1BracersPerAcGp() != 3000)
                ++bad;
            if (rules::m1BracersPerAcXp() != 500)
                ++bad;
            if (rules::m1ClericCount() != 2)
                ++bad;
            if (rules::m1MagicUserCount() != 4)
                ++bad;
            if (rules::m1RowCount() != 33)
                ++bad;
            if (rules::m2ClericCount() != 1)
                ++bad;
            if (rules::m2CloakPerPlusGp() != 10000)
                ++bad;
            if (rules::m2CloakPerPlusXp() != 1000)
                ++bad;
            if (rules::m2CrystalBallBaseGp() != 5000)
                ++bad;
            if (rules::m2CrystalBallBaseXp() != 1000)
                ++bad;
            if (rules::m2CrystalBallFeatureBonusPct() != 100)
                ++bad;
            if (rules::m2MagicUserCount() != 5)
                ++bad;
            if (rules::m2RowCount() != 30)
                ++bad;
            if (rules::m3ClericCount() != 7)
                ++bad;
            if (rules::m3FighterCount() != 7)
                ++bad;
            if (rules::m3FigurinePerHitDieGp() != 1000)
                ++bad;
            if (rules::m3FigurinePerHitDieXp() != 100)
                ++bad;
            if (rules::m3InstrumentBaseGp() != 5000)
                ++bad;
            if (rules::m3InstrumentBaseXp() != 1000)
                ++bad;
            if (rules::m3IounPerStoneGp() != 5000)
                ++bad;
            if (rules::m3IounPerStoneXp() != 300)
                ++bad;
            if (rules::m3JewelPerFacetGp() != 1000)
                ++bad;
            if (rules::m3RowCount() != 33)
                ++bad;
            if (rules::m3ThiefCount() != 4)
                ++bad;
            if (rules::m3ValhallaBaseGp() != 15000)
                ++bad;
            if (rules::m3ValhallaBaseXp() != 1000)
                ++bad;
            if (rules::m3ValhallaBronzeMult() != 2)
                ++bad;
            if (rules::m3ValhallaIronMult() != 3)
                ++bad;
            if (rules::m4BeadPerSpecialGp() != 3000)
                ++bad;
            if (rules::m4BeadPerSpecialXp() != 500)
                ++bad;
            if (rules::m4ClericCount() != 8)
                ++bad;
            if (rules::m4FeatherTokenGpHigh() != 7000)
                ++bad;
            if (rules::m4FeatherTokenGpLow() != 2000)
                ++bad;
            if (rules::m4FeatherTokenXpHigh() != 1000)
                ++bad;
            if (rules::m4FeatherTokenXpLow() != 500)
                ++bad;
            if (rules::m4FighterCount() != 4)
                ++bad;
            if (rules::m4MagicUserCount() != 6)
                ++bad;
            if (rules::m4MedallionEspGpHigh() != 30000)
                ++bad;
            if (rules::m4MedallionEspGpLow() != 10000)
                ++bad;
            if (rules::m4MedallionEspXpHigh() != 3000)
                ++bad;
            if (rules::m4MedallionEspXpLow() != 1000)
                ++bad;
            if (rules::m4MissilePerHitDieGp() != 200)
                ++bad;
            if (rules::m4MissilePerHitDieXp() != 50)
                ++bad;
            if (rules::m4PearlPerSpellLevelGp() != 2000)
                ++bad;
            if (rules::m4PearlPerSpellLevelXp() != 200)
                ++bad;
            if (rules::m4PigmentsPerPotGp() != 3000)
                ++bad;
            if (rules::m4PigmentsPerPotXp() != 500)
                ++bad;
            if (rules::m4RowCount() != 36)
                ++bad;
            if (rules::m4ThiefCount() != 3)
                ++bad;
            if (rules::m5ClericCount() != 5)
                ++bad;
            if (rules::m5FighterCount() != 5)
                ++bad;
            if (rules::m5MagicUserCount() != 8)
                ++bad;
            if (rules::m5RowCount() != 35)
                ++bad;
            if (rules::m5ThiefCount() != 2)
                ++bad;
            if (rules::wonderBoltLengthInches() != 7)
                ++bad;
            if (rules::wonderBoltWidthHalfInches() != 1)
                ++bad;
            if (rules::wonderButterflyCount() != 600)
                ++bad;
            if (rules::wonderButterflyRounds() != 2)
                ++bad;
            if (rules::wonderChargesPerFunction() != 1)
                ++bad;
            if (rules::wonderColorAreaHeightInches() != 3)
                ++bad;
            if (rules::wonderColorAreaWidthInches() != 4)
                ++bad;
            if (rules::wonderColorBlindHi() != 6)
                ++bad;
            if (rules::wonderColorBlindLo() != 1)
                ++bad;
            if (rules::wonderDarknessCenterDistanceInches() != 3)
                ++bad;
            if (rules::wonderDarknessDiameterInches() != 3)
                ++bad;
            if (rules::wonderDeludeRounds() != 1)
                ++bad;
            if (rules::wonderDiminishHeightInches() != 1)
                ++bad;
            if (rules::wonderEnlargeRangeInches() != 6)
                ++bad;
            if (rules::wonderFleshRangeInches() != 6)
                ++bad;
            if (rules::wonderGemBaseValueGp() != 1)
                ++bad;
            if (rules::wonderGemCountHi() != 40)
                ++bad;
            if (rules::wonderGemCountLo() != 10)
                ++bad;
            if (rules::wonderGemDamageHp() != 1)
                ++bad;
            if (rules::wonderGemHitDice() != 5)
                ++bad;
            if (rules::wonderGemHitFaces() != 4)
                ++bad;
            if (rules::wonderGemStreamLengthInches() != 3)
                ++bad;
            if (rules::wonderGrassAreaInches() != 16)
                ++bad;
            if (rules::wonderGrassGrowthFactor() != 10)
                ++bad;
            if (rules::wonderGustForceMultiplier() != 2)
                ++bad;
            if (rules::wonderLeavesRangeInches() != 6)
                ++bad;
            if (rules::wonderRainRadiusInches() != 6)
                ++bad;
            if (rules::wonderRainRounds() != 1)
                ++bad;
            if (rules::wonderRechargeable() != 0)
                ++bad;
            if (rules::wonderRowCount() != 19)
                ++bad;
            if (rules::wonderSlowTurns() != 1)
                ++bad;
            if (rules::wonderStinkingRangeInches() != 3)
                ++bad;
            if (rules::wonderSummonElephantHi() != 50)
                ++bad;
            if (rules::wonderSummonElephantLo() != 26)
                ++bad;
            if (rules::wonderSummonMouseHi() != 100)
                ++bad;
            if (rules::wonderSummonMouseLo() != 51)
                ++bad;
            if (rules::wonderSummonRhinoHi() != 25)
                ++bad;
            if (rules::wonderSummonRhinoLo() != 1)
                ++bad;
            if (rules::wonderVanishMassPounds() != 1000)
                ++bad;
            if (rules::wonderVanishVolumeCubicFeet() != 30)
                ++bad;
        }
        printf("R1059 misc-magic registry edges audit: bad %d\n", bad);
    }
