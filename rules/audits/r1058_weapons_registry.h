    // ==== R1058: weapons registry ==========
    // The R1058 de-wire: the 49 retiring static
    // arrays of the eleven cross-book WEAPONS-family
    // headers ride items::MiscItemRegistry from
    // content/tables/weapondata/ - 17 defs, 35 tables, 14 rows readers;
    // the six KEPT struct/logic seams and the count fns stay C++,
    // probed by the older pin fragments and the model here. Eight sections: load, counts,
    // defs-A/B/C/D, seam, edges. Census 1111 -> 1119. DO NOT hand-edit:
    // tools/r1058_splice.py is the only writer.
    {
        int bad = 0;
        // -- 1. load ------------------------------
        {
            items::MiscItemRegistry reg;
            int n = reg.loadDirectory(
                "content/tables/weapondata");
            if (n != 17) ++bad;
            if (!reg.errors().empty()) ++bad;
            for (const auto& kv : reg.all())
                if ((int)kv.second.sources.size() != 1
                    || kv.second.sources[0].second != 1058)
                    ++bad;
            if (!reg.find("wt")) ++bad;
            if (!reg.find("uamt")) ++bad;
            if (!reg.find("uamt_rof")) ++bad;
            if (!reg.find("uamt_range_s")) ++bad;
            if (!reg.find("uamt_range_m")) ++bad;
            if (!reg.find("uamt_range_l")) ++bad;
            if (!reg.find("uahh")) ++bad;
            if (!reg.find("uahh_length")) ++bad;
            if (!reg.find("uahh_space")) ++bad;
            if (!reg.find("uanw")) ++bad;
            if (!reg.find("wspec_cols")) ++bad;
            if (!reg.find("wspec")) ++bad;
            if (!reg.find("wspec_cells")) ++bad;
            if (!reg.find("uapf")) ++bad;
            if (!reg.find("mw")) ++bad;
            if (!reg.find("wspeed")) ++bad;
            if (!reg.find("wpf")) ++bad;
        }
        printf("R1058 weapons registry load audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 2. counts --------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/weapondata");
            {
                const items::MiscItemDef* d =
                    reg.find("wt");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 68
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "wtRowCount"
                        || d->pins[0].value != 68)
                        ++bad;
                    if ((int)d->tables.size() != 8) ++bad;
                    if (d->tables[0].name
                        != "is_new"
                        || (int)d->tables[0]
                            .values.size() != 68)
                        ++bad;
                    if (d->tables[1].name
                        != "l_max"
                        || (int)d->tables[1]
                            .values.size() != 68)
                        ++bad;
                    if (d->tables[2].name
                        != "l_min"
                        || (int)d->tables[2]
                            .values.size() != 68)
                        ++bad;
                    if (d->tables[3].name
                        != "phb_seam"
                        || (int)d->tables[3]
                            .values.size() != 68)
                        ++bad;
                    if (d->tables[4].name
                        != "sm_max"
                        || (int)d->tables[4]
                            .values.size() != 68)
                        ++bad;
                    if (d->tables[5].name
                        != "sm_min"
                        || (int)d->tables[5]
                            .values.size() != 68)
                        ++bad;
                    if (d->tables[6].name
                        != "weight_max"
                        || (int)d->tables[6]
                            .values.size() != 68)
                        ++bad;
                    if (d->tables[7].name
                        != "weight_min"
                        || (int)d->tables[7]
                            .values.size() != 68)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("uamt");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 24
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "uamtRowCount"
                        || d->pins[0].value != 24)
                        ++bad;
                    if ((int)d->tables.size() != 4) ++bad;
                    if (d->tables[0].name
                        != "ac_adjustment"
                        || (int)d->tables[0]
                            .values.size() != 168)
                        ++bad;
                    if (d->tables[1].name
                        != "ac_adjustment_high"
                        || (int)d->tables[1]
                            .values.size() != 96)
                        ++bad;
                    if (d->tables[2].name
                        != "is_new"
                        || (int)d->tables[2]
                            .values.size() != 24)
                        ++bad;
                    if (d->tables[3].name
                        != "range_printed"
                        || (int)d->tables[3]
                            .values.size() != 24)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("uamt_rof");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 24
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "uamt_rofRowCount"
                        || d->pins[0].value != 24)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("uamt_range_s");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 24
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "uamt_range_sRowCount"
                        || d->pins[0].value != 24)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("uamt_range_m");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 24
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "uamt_range_mRowCount"
                        || d->pins[0].value != 24)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("uamt_range_l");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 24
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "uamt_range_lRowCount"
                        || d->pins[0].value != 24)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("uahh");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 60
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "uahhRowCount"
                        || d->pins[0].value != 60)
                        ++bad;
                    if ((int)d->tables.size() != 5) ++bad;
                    if (d->tables[0].name
                        != "ac_adjustment"
                        || (int)d->tables[0]
                            .values.size() != 660)
                        ++bad;
                    if (d->tables[1].name
                        != "dismount"
                        || (int)d->tables[1]
                            .values.size() != 60)
                        ++bad;
                    if (d->tables[2].name
                        != "set_double"
                        || (int)d->tables[2]
                            .values.size() != 60)
                        ++bad;
                    if (d->tables[3].name
                        != "speed_max"
                        || (int)d->tables[3]
                            .values.size() != 60)
                        ++bad;
                    if (d->tables[4].name
                        != "speed_min"
                        || (int)d->tables[4]
                            .values.size() != 60)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("uahh_length");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 60
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "uahh_lengthRowCount"
                        || d->pins[0].value != 60)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("uahh_space");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 60
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "uahh_spaceRowCount"
                        || d->pins[0].value != 60)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("uanw");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 16
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "uanwRowCount"
                        || d->pins[0].value != 16)
                        ++bad;
                    if ((int)d->tables.size() != 1) ++bad;
                    if (d->tables[0].name
                        != "in_gap"
                        || (int)d->tables[0]
                            .values.size() != 16)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("wspec_cols");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 8
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "wspec_colsRowCount"
                        || d->pins[0].value != 8)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("wspec");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 3
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "wspecRowCount"
                        || d->pins[0].value != 3)
                        ++bad;
                    if ((int)d->tables.size() != 2) ++bad;
                    if (d->tables[0].name
                        != "band_high"
                        || (int)d->tables[0]
                            .values.size() != 3)
                        ++bad;
                    if (d->tables[1].name
                        != "band_low"
                        || (int)d->tables[1]
                            .values.size() != 3)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("wspec_cells");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 24
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "wspec_cellsRowCount"
                        || d->pins[0].value != 24)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("uapf");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 14
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "uapfRowCount"
                        || d->pins[0].value != 14)
                        ++bad;
                    if ((int)d->tables.size() != 6) ++bad;
                    if (d->tables[0].name
                        != "added_cadence"
                        || (int)d->tables[0]
                            .values.size() != 14)
                        ++bad;
                    if (d->tables[1].name
                        != "attributed"
                        || (int)d->tables[1]
                            .values.size() != 14)
                        ++bad;
                    if (d->tables[2].name
                        != "initial_asterisk"
                        || (int)d->tables[2]
                            .values.size() != 14)
                        ++bad;
                    if (d->tables[3].name
                        != "initial_slots"
                        || (int)d->tables[3]
                            .values.size() != 14)
                        ++bad;
                    if (d->tables[4].name
                        != "nonprof_penalty"
                        || (int)d->tables[4]
                            .values.size() != 14)
                        ++bad;
                    if (d->tables[5].name
                        != "phb_seam"
                        || (int)d->tables[5]
                            .values.size() != 14)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("mw");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 36
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "mwRowCount"
                        || d->pins[0].value != 36)
                        ++bad;
                    if ((int)d->tables.size() != 6) ++bad;
                    if (d->tables[0].name
                        != "qty_hi"
                        || (int)d->tables[0]
                            .values.size() != 36)
                        ++bad;
                    if (d->tables[1].name
                        != "qty_lo"
                        || (int)d->tables[1]
                            .values.size() != 36)
                        ++bad;
                    if (d->tables[2].name
                        != "row_hi"
                        || (int)d->tables[2]
                            .values.size() != 36)
                        ++bad;
                    if (d->tables[3].name
                        != "row_lo"
                        || (int)d->tables[3]
                            .values.size() != 36)
                        ++bad;
                    if (d->tables[4].name
                        != "sale_gp"
                        || (int)d->tables[4]
                            .values.size() != 36)
                        ++bad;
                    if (d->tables[5].name
                        != "xp_value"
                        || (int)d->tables[5]
                            .values.size() != 36)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("wspeed");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 22
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "wspeedRowCount"
                        || d->pins[0].value != 22)
                        ++bad;
                    if ((int)d->tables.size() != 1) ++bad;
                    if (d->tables[0].name
                        != "sf"
                        || (int)d->tables[0]
                            .values.size() != 22)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("wpf");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 10
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "wpfRowCount"
                        || d->pins[0].value != 10)
                        ++bad;
                    if ((int)d->tables.size() != 3) ++bad;
                    if (d->tables[0].name
                        != "added_cadence"
                        || (int)d->tables[0]
                            .values.size() != 10)
                        ++bad;
                    if (d->tables[1].name
                        != "initial_slots"
                        || (int)d->tables[1]
                            .values.size() != 10)
                        ++bad;
                    if (d->tables[2].name
                        != "nonprof_penalty"
                        || (int)d->tables[2]
                            .values.size() != 10)
                        ++bad;
                }
            }
        }
        printf("R1058 weapons registry counts audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 3. A -----------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/weapondata");
            {
                const items::MiscItemDef* d =
                    reg.find("wt");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 1) ++bad;
                    if (d->tables[0]
                        .values[1] != 1) ++bad;
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
                        .values[8] != 1) ++bad;
                    if (d->tables[0]
                        .values[9] != 0) ++bad;
                    if (d->tables[0]
                        .values[10] != 1) ++bad;
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
                        .values[19] != 1) ++bad;
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
                        .values[25] != 1) ++bad;
                    if (d->tables[0]
                        .values[26] != 0) ++bad;
                    if (d->tables[0]
                        .values[27] != 0) ++bad;
                    if (d->tables[0]
                        .values[28] != 1) ++bad;
                    if (d->tables[0]
                        .values[29] != 0) ++bad;
                    if (d->tables[0]
                        .values[30] != 0) ++bad;
                    if (d->tables[0]
                        .values[31] != 1) ++bad;
                    if (d->tables[0]
                        .values[32] != 0) ++bad;
                    if (d->tables[0]
                        .values[33] != 0) ++bad;
                    if (d->tables[0]
                        .values[34] != 0) ++bad;
                    if (d->tables[0]
                        .values[35] != 1) ++bad;
                    if (d->tables[0]
                        .values[36] != 0) ++bad;
                    if (d->tables[0]
                        .values[37] != 0) ++bad;
                    if (d->tables[0]
                        .values[38] != 1) ++bad;
                    if (d->tables[0]
                        .values[39] != 0) ++bad;
                    if (d->tables[0]
                        .values[40] != 0) ++bad;
                    if (d->tables[0]
                        .values[41] != 0) ++bad;
                    if (d->tables[0]
                        .values[42] != 0) ++bad;
                    if (d->tables[0]
                        .values[43] != 0) ++bad;
                    if (d->tables[0]
                        .values[44] != 0) ++bad;
                    if (d->tables[0]
                        .values[45] != 0) ++bad;
                    if (d->tables[0]
                        .values[46] != 0) ++bad;
                    if (d->tables[0]
                        .values[47] != 1) ++bad;
                    if (d->tables[0]
                        .values[48] != 0) ++bad;
                    if (d->tables[0]
                        .values[49] != 0) ++bad;
                    if (d->tables[0]
                        .values[50] != 0) ++bad;
                    if (d->tables[0]
                        .values[51] != 0) ++bad;
                    if (d->tables[0]
                        .values[52] != 0) ++bad;
                    if (d->tables[0]
                        .values[53] != 1) ++bad;
                    if (d->tables[0]
                        .values[54] != 0) ++bad;
                    if (d->tables[0]
                        .values[55] != 1) ++bad;
                    if (d->tables[0]
                        .values[56] != 1) ++bad;
                    if (d->tables[0]
                        .values[57] != 0) ++bad;
                    if (d->tables[0]
                        .values[58] != 0) ++bad;
                    if (d->tables[0]
                        .values[59] != 1) ++bad;
                    if (d->tables[0]
                        .values[60] != 1) ++bad;
                    if (d->tables[0]
                        .values[61] != 0) ++bad;
                    if (d->tables[0]
                        .values[62] != 0) ++bad;
                    if (d->tables[0]
                        .values[63] != 0) ++bad;
                    if (d->tables[0]
                        .values[64] != 0) ++bad;
                    if (d->tables[0]
                        .values[65] != 0) ++bad;
                    if (d->tables[0]
                        .values[66] != 1) ++bad;
                    if (d->tables[0]
                        .values[67] != 1) ++bad;
                    if (d->tables[1]
                        .values[0] != 3) ++bad;
                    if (d->tables[1]
                        .values[1] != 6) ++bad;
                    if (d->tables[1]
                        .values[2] != 6) ++bad;
                    if (d->tables[1]
                        .values[3] != 8) ++bad;
                    if (d->tables[1]
                        .values[4] != 4) ++bad;
                    if (d->tables[1]
                        .values[5] != 12) ++bad;
                    if (d->tables[1]
                        .values[6] != 6) ++bad;
                    if (d->tables[1]
                        .values[7] != 10) ++bad;
                    if (d->tables[1]
                        .values[8] != 1) ++bad;
                    if (d->tables[1]
                        .values[9] != 3) ++bad;
                    if (d->tables[1]
                        .values[10] != 2) ++bad;
                    if (d->tables[1]
                        .values[11] != 3) ++bad;
                    if (d->tables[1]
                        .values[12] != 3) ++bad;
                    if (d->tables[1]
                        .values[13] != 2) ++bad;
                    if (d->tables[1]
                        .values[14] != 8) ++bad;
                    if (d->tables[1]
                        .values[15] != 10) ++bad;
                    if (d->tables[1]
                        .values[16] != 8) ++bad;
                    if (d->tables[1]
                        .values[17] != 5) ++bad;
                    if (d->tables[1]
                        .values[18] != 8) ++bad;
                    if (d->tables[1]
                        .values[19] != 6) ++bad;
                    if (d->tables[1]
                        .values[20] != 10) ++bad;
                    if (d->tables[1]
                        .values[21] != 12) ++bad;
                    if (d->tables[1]
                        .values[22] != 8) ++bad;
                    if (d->tables[1]
                        .values[23] != 8) ++bad;
                    if (d->tables[1]
                        .values[24] != 12) ++bad;
                    if (d->tables[1]
                        .values[25] != 12) ++bad;
                    if (d->tables[1]
                        .values[26] != 6) ++bad;
                    if (d->tables[1]
                        .values[27] != 4) ++bad;
                    if (d->tables[1]
                        .values[28] != 4) ++bad;
                    if (d->tables[1]
                        .values[29] != 6) ++bad;
                    if (d->tables[1]
                        .values[30] != 4) ++bad;
                    if (d->tables[1]
                        .values[31] != 2) ++bad;
                    if (d->tables[1]
                        .values[32] != 8) ++bad;
                    if (d->tables[1]
                        .values[33] != 12) ++bad;
                    if (d->tables[1]
                        .values[34] != 18) ++bad;
                    if (d->tables[1]
                        .values[35] != 0) ++bad;
                    if (d->tables[1]
                        .values[36] != 6) ++bad;
                    if (d->tables[1]
                        .values[37] != 4) ++bad;
                    if (d->tables[1]
                        .values[38] != 2) ++bad;
                    if (d->tables[1]
                        .values[39] != 7) ++bad;
                    if (d->tables[1]
                        .values[40] != 7) ++bad;
                    if (d->tables[1]
                        .values[41] != 8) ++bad;
                    if (d->tables[1]
                        .values[42] != 4) ++bad;
                    if (d->tables[1]
                        .values[43] != 12) ++bad;
                    if (d->tables[1]
                        .values[44] != 4) ++bad;
                    if (d->tables[1]
                        .values[45] != 7) ++bad;
                    if (d->tables[1]
                        .values[46] != 8) ++bad;
                    if (d->tables[1]
                        .values[47] != 2) ++bad;
                    if (d->tables[1]
                        .values[48] != 8) ++bad;
                    if (d->tables[1]
                        .values[49] != 7) ++bad;
                    if (d->tables[1]
                        .values[50] != 4) ++bad;
                    if (d->tables[1]
                        .values[51] != 8) ++bad;
                    if (d->tables[1]
                        .values[52] != 12) ++bad;
                    if (d->tables[1]
                        .values[53] != 3) ++bad;
                    if (d->tables[1]
                        .values[54] != 6) ++bad;
                    if (d->tables[1]
                        .values[55] != 9) ++bad;
                    if (d->tables[1]
                        .values[56] != 8) ++bad;
                    if (d->tables[1]
                        .values[57] != 16) ++bad;
                    if (d->tables[1]
                        .values[58] != 7) ++bad;
                    if (d->tables[1]
                        .values[59] != 8) ++bad;
                    if (d->tables[1]
                        .values[60] != 6) ++bad;
                    if (d->tables[1]
                        .values[61] != 12) ++bad;
                    if (d->tables[1]
                        .values[62] != 8) ++bad;
                    if (d->tables[1]
                        .values[63] != 18) ++bad;
                    if (d->tables[1]
                        .values[64] != 12) ++bad;
                    if (d->tables[1]
                        .values[65] != 8) ++bad;
                    if (d->tables[1]
                        .values[66] != 1) ++bad;
                    if (d->tables[1]
                        .values[67] != 2) ++bad;
                    if (d->tables[2]
                        .values[0] != 1) ++bad;
                    if (d->tables[2]
                        .values[1] != 1) ++bad;
                    if (d->tables[2]
                        .values[2] != 1) ++bad;
                    if (d->tables[2]
                        .values[3] != 1) ++bad;
                    if (d->tables[2]
                        .values[4] != 1) ++bad;
                    if (d->tables[2]
                        .values[5] != 3) ++bad;
                    if (d->tables[2]
                        .values[6] != 1) ++bad;
                    if (d->tables[2]
                        .values[7] != 1) ++bad;
                    if (d->tables[2]
                        .values[8] != 1) ++bad;
                    if (d->tables[2]
                        .values[9] != 1) ++bad;
                    if (d->tables[2]
                        .values[10] != 1) ++bad;
                    if (d->tables[2]
                        .values[11] != 1) ++bad;
                    if (d->tables[2]
                        .values[12] != 1) ++bad;
                    if (d->tables[2]
                        .values[13] != 1) ++bad;
                    if (d->tables[2]
                        .values[14] != 1) ++bad;
                    if (d->tables[2]
                        .values[15] != 1) ++bad;
                    if (d->tables[2]
                        .values[16] != 2) ++bad;
                    if (d->tables[2]
                        .values[17] != 2) ++bad;
                    if (d->tables[2]
                        .values[18] != 2) ++bad;
                    if (d->tables[2]
                        .values[19] != 1) ++bad;
                    if (d->tables[2]
                        .values[20] != 1) ++bad;
                    if (d->tables[2]
                        .values[21] != 2) ++bad;
                    if (d->tables[2]
                        .values[22] != 1) ++bad;
                    if (d->tables[2]
                        .values[23] != 2) ++bad;
                    if (d->tables[2]
                        .values[24] != 2) ++bad;
                    if (d->tables[2]
                        .values[25] != 2) ++bad;
                    if (d->tables[2]
                        .values[26] != 1) ++bad;
                    if (d->tables[2]
                        .values[27] != 1) ++bad;
                    if (d->tables[2]
                        .values[28] != 1) ++bad;
                    if (d->tables[2]
                        .values[29] != 1) ++bad;
                    if (d->tables[2]
                        .values[30] != 1) ++bad;
                    if (d->tables[2]
                        .values[31] != 1) ++bad;
                    if (d->tables[2]
                        .values[32] != 1) ++bad;
                    if (d->tables[2]
                        .values[33] != 2) ++bad;
                    if (d->tables[2]
                        .values[34] != 3) ++bad;
                    if (d->tables[2]
                        .values[35] != 0) ++bad;
                    if (d->tables[2]
                        .values[36] != 1) ++bad;
                    if (d->tables[2]
                        .values[37] != 1) ++bad;
                    if (d->tables[2]
                        .values[38] != 1) ++bad;
                    if (d->tables[2]
                        .values[39] != 2) ++bad;
                    if (d->tables[2]
                        .values[40] != 2) ++bad;
                    if (d->tables[2]
                        .values[41] != 2) ++bad;
                    if (d->tables[2]
                        .values[42] != 1) ++bad;
                    if (d->tables[2]
                        .values[43] != 1) ++bad;
                    if (d->tables[2]
                        .values[44] != 1) ++bad;
                    if (d->tables[2]
                        .values[45] != 2) ++bad;
                    if (d->tables[2]
                        .values[46] != 2) ++bad;
                    if (d->tables[2]
                        .values[47] != 1) ++bad;
                    if (d->tables[2]
                        .values[48] != 1) ++bad;
                    if (d->tables[2]
                        .values[49] != 2) ++bad;
                    if (d->tables[2]
                        .values[50] != 1) ++bad;
                    if (d->tables[2]
                        .values[51] != 1) ++bad;
                    if (d->tables[2]
                        .values[52] != 2) ++bad;
                    if (d->tables[2]
                        .values[53] != 1) ++bad;
                    if (d->tables[2]
                        .values[54] != 1) ++bad;
                    if (d->tables[2]
                        .values[55] != 3) ++bad;
                    if (d->tables[2]
                        .values[56] != 2) ++bad;
                    if (d->tables[2]
                        .values[57] != 2) ++bad;
                    if (d->tables[2]
                        .values[58] != 2) ++bad;
                    if (d->tables[2]
                        .values[59] != 2) ++bad;
                    if (d->tables[2]
                        .values[60] != 1) ++bad;
                    if (d->tables[2]
                        .values[61] != 1) ++bad;
                    if (d->tables[2]
                        .values[62] != 1) ++bad;
                    if (d->tables[2]
                        .values[63] != 3) ++bad;
                    if (d->tables[2]
                        .values[64] != 3) ++bad;
                    if (d->tables[2]
                        .values[65] != 2) ++bad;
                    if (d->tables[2]
                        .values[66] != 1) ++bad;
                    if (d->tables[2]
                        .values[67] != 1) ++bad;
                    if (d->tables[3]
                        .values[0] != -1) ++bad;
                    if (d->tables[3]
                        .values[1] != -1) ++bad;
                    if (d->tables[3]
                        .values[2] != 0) ++bad;
                    if (d->tables[3]
                        .values[3] != 1) ++bad;
                    if (d->tables[3]
                        .values[4] != 2) ++bad;
                    if (d->tables[3]
                        .values[5] != 3) ++bad;
                    if (d->tables[3]
                        .values[6] != 4) ++bad;
                    if (d->tables[3]
                        .values[7] != 5) ++bad;
                    if (d->tables[3]
                        .values[8] != -1) ++bad;
                    if (d->tables[3]
                        .values[9] != 6) ++bad;
                    if (d->tables[3]
                        .values[10] != -1) ++bad;
                    if (d->tables[3]
                        .values[11] != 7) ++bad;
                    if (d->tables[3]
                        .values[12] != 8) ++bad;
                    if (d->tables[3]
                        .values[13] != 9) ++bad;
                    if (d->tables[3]
                        .values[14] != 10) ++bad;
                    if (d->tables[3]
                        .values[15] != 11) ++bad;
                    if (d->tables[3]
                        .values[16] != 12) ++bad;
                    if (d->tables[3]
                        .values[17] != 13) ++bad;
                    if (d->tables[3]
                        .values[18] != 14) ++bad;
                    if (d->tables[3]
                        .values[19] != -1) ++bad;
                    if (d->tables[3]
                        .values[20] != 15) ++bad;
                    if (d->tables[3]
                        .values[21] != 16) ++bad;
                    if (d->tables[3]
                        .values[22] != 17) ++bad;
                    if (d->tables[3]
                        .values[23] != 18) ++bad;
                    if (d->tables[3]
                        .values[24] != 19) ++bad;
                    if (d->tables[3]
                        .values[25] != -1) ++bad;
                    if (d->tables[3]
                        .values[26] != 20) ++bad;
                    if (d->tables[3]
                        .values[27] != 21) ++bad;
                    if (d->tables[3]
                        .values[28] != -1) ++bad;
                    if (d->tables[3]
                        .values[29] != 22) ++bad;
                    if (d->tables[3]
                        .values[30] != 23) ++bad;
                    if (d->tables[3]
                        .values[31] != -1) ++bad;
                    if (d->tables[3]
                        .values[32] != 24) ++bad;
                    if (d->tables[3]
                        .values[33] != 25) ++bad;
                    if (d->tables[3]
                        .values[34] != 26) ++bad;
                    if (d->tables[3]
                        .values[35] != -1) ++bad;
                    if (d->tables[3]
                        .values[36] != 27) ++bad;
                    if (d->tables[3]
                        .values[37] != 28) ++bad;
                    if (d->tables[3]
                        .values[38] != -1) ++bad;
                    if (d->tables[3]
                        .values[39] != 29) ++bad;
                    if (d->tables[3]
                        .values[40] != 30) ++bad;
                    if (d->tables[3]
                        .values[41] != 31) ++bad;
                    if (d->tables[3]
                        .values[42] != 32) ++bad;
                    if (d->tables[3]
                        .values[43] != 33) ++bad;
                    if (d->tables[3]
                        .values[44] != 34) ++bad;
                    if (d->tables[3]
                        .values[45] != 35) ++bad;
                    if (d->tables[3]
                        .values[46] != 36) ++bad;
                    if (d->tables[3]
                        .values[47] != -1) ++bad;
                    if (d->tables[3]
                        .values[48] != 37) ++bad;
                    if (d->tables[3]
                        .values[49] != 38) ++bad;
                    if (d->tables[3]
                        .values[50] != 39) ++bad;
                    if (d->tables[3]
                        .values[51] != 40) ++bad;
                    if (d->tables[3]
                        .values[52] != 41) ++bad;
                    if (d->tables[3]
                        .values[53] != -1) ++bad;
                    if (d->tables[3]
                        .values[54] != 42) ++bad;
                    if (d->tables[3]
                        .values[55] != -1) ++bad;
                    if (d->tables[3]
                        .values[56] != -1) ++bad;
                    if (d->tables[3]
                        .values[57] != 43) ++bad;
                    if (d->tables[3]
                        .values[58] != 44) ++bad;
                    if (d->tables[3]
                        .values[59] != -1) ++bad;
                    if (d->tables[3]
                        .values[60] != -1) ++bad;
                    if (d->tables[3]
                        .values[61] != 45) ++bad;
                    if (d->tables[3]
                        .values[62] != 46) ++bad;
                    if (d->tables[3]
                        .values[63] != 47) ++bad;
                    if (d->tables[3]
                        .values[64] != 48) ++bad;
                    if (d->tables[3]
                        .values[65] != 49) ++bad;
                    if (d->tables[3]
                        .values[66] != -1) ++bad;
                    if (d->tables[3]
                        .values[67] != -1) ++bad;
                    if (d->tables[4]
                        .values[0] != 6) ++bad;
                    if (d->tables[4]
                        .values[1] != 6) ++bad;
                    if (d->tables[4]
                        .values[2] != 6) ++bad;
                    if (d->tables[4]
                        .values[3] != 8) ++bad;
                    if (d->tables[4]
                        .values[4] != 6) ++bad;
                    if (d->tables[4]
                        .values[5] != 8) ++bad;
                    if (d->tables[4]
                        .values[6] != 8) ++bad;
                    if (d->tables[4]
                        .values[7] != 8) ++bad;
                    if (d->tables[4]
                        .values[8] != 1) ++bad;
                    if (d->tables[4]
                        .values[9] != 6) ++bad;
                    if (d->tables[4]
                        .values[10] != 1) ++bad;
                    if (d->tables[4]
                        .values[11] != 6) ++bad;
                    if (d->tables[4]
                        .values[12] != 4) ++bad;
                    if (d->tables[4]
                        .values[13] != 3) ++bad;
                    if (d->tables[4]
                        .values[14] != 6) ++bad;
                    if (d->tables[4]
                        .values[15] != 8) ++bad;
                    if (d->tables[4]
                        .values[16] != 7) ++bad;
                    if (d->tables[4]
                        .values[17] != 5) ++bad;
                    if (d->tables[4]
                        .values[18] != 8) ++bad;
                    if (d->tables[4]
                        .values[19] != 4) ++bad;
                    if (d->tables[4]
                        .values[20] != 6) ++bad;
                    if (d->tables[4]
                        .values[21] != 8) ++bad;
                    if (d->tables[4]
                        .values[22] != 8) ++bad;
                    if (d->tables[4]
                        .values[23] != 8) ++bad;
                    if (d->tables[4]
                        .values[24] != 10) ++bad;
                    if (d->tables[4]
                        .values[25] != 8) ++bad;
                    if (d->tables[4]
                        .values[26] != 8) ++bad;
                    if (d->tables[4]
                        .values[27] != 5) ++bad;
                    if (d->tables[4]
                        .values[28] != 4) ++bad;
                    if (d->tables[4]
                        .values[29] != 6) ++bad;
                    if (d->tables[4]
                        .values[30] != 6) ++bad;
                    if (d->tables[4]
                        .values[31] != 3) ++bad;
                    if (d->tables[4]
                        .values[32] != 6) ++bad;
                    if (d->tables[4]
                        .values[33] != 7) ++bad;
                    if (d->tables[4]
                        .values[34] != 9) ++bad;
                    if (d->tables[4]
                        .values[35] != 0) ++bad;
                    if (d->tables[4]
                        .values[36] != 7) ++bad;
                    if (d->tables[4]
                        .values[37] != 6) ++bad;
                    if (d->tables[4]
                        .values[38] != 2) ++bad;
                    if (d->tables[4]
                        .values[39] != 8) ++bad;
                    if (d->tables[4]
                        .values[40] != 6) ++bad;
                    if (d->tables[4]
                        .values[41] != 7) ++bad;
                    if (d->tables[4]
                        .values[42] != 5) ++bad;
                    if (d->tables[4]
                        .values[43] != 6) ++bad;
                    if (d->tables[4]
                        .values[44] != 4) ++bad;
                    if (d->tables[4]
                        .values[45] != 5) ++bad;
                    if (d->tables[4]
                        .values[46] != 8) ++bad;
                    if (d->tables[4]
                        .values[47] != 2) ++bad;
                    if (d->tables[4]
                        .values[48] != 8) ++bad;
                    if (d->tables[4]
                        .values[49] != 5) ++bad;
                    if (d->tables[4]
                        .values[50] != 4) ++bad;
                    if (d->tables[4]
                        .values[51] != 6) ++bad;
                    if (d->tables[4]
                        .values[52] != 7) ++bad;
                    if (d->tables[4]
                        .values[53] != 4) ++bad;
                    if (d->tables[4]
                        .values[54] != 6) ++bad;
                    if (d->tables[4]
                        .values[55] != 8) ++bad;
                    if (d->tables[4]
                        .values[56] != 8) ++bad;
                    if (d->tables[4]
                        .values[57] != 8) ++bad;
                    if (d->tables[4]
                        .values[58] != 8) ++bad;
                    if (d->tables[4]
                        .values[59] != 7) ++bad;
                    if (d->tables[4]
                        .values[60] != 8) ++bad;
                    if (d->tables[4]
                        .values[61] != 8) ++bad;
                    if (d->tables[4]
                        .values[62] != 6) ++bad;
                    if (d->tables[4]
                        .values[63] != 10) ++bad;
                    if (d->tables[4]
                        .values[64] != 7) ++bad;
                    if (d->tables[4]
                        .values[65] != 8) ++bad;
                    if (d->tables[4]
                        .values[66] != 2) ++bad;
                    if (d->tables[4]
                        .values[67] != 3) ++bad;
                    if (d->tables[5]
                        .values[0] != 1) ++bad;
                    if (d->tables[5]
                        .values[1] != 1) ++bad;
                    if (d->tables[5]
                        .values[2] != 1) ++bad;
                    if (d->tables[5]
                        .values[3] != 1) ++bad;
                    if (d->tables[5]
                        .values[4] != 1) ++bad;
                    if (d->tables[5]
                        .values[5] != 2) ++bad;
                    if (d->tables[5]
                        .values[6] != 1) ++bad;
                    if (d->tables[5]
                        .values[7] != 2) ++bad;
                    if (d->tables[5]
                        .values[8] != 1) ++bad;
                    if (d->tables[5]
                        .values[9] != 1) ++bad;
                    if (d->tables[5]
                        .values[10] != 1) ++bad;
                    if (d->tables[5]
                        .values[11] != 1) ++bad;
                    if (d->tables[5]
                        .values[12] != 1) ++bad;
                    if (d->tables[5]
                        .values[13] != 1) ++bad;
                    if (d->tables[5]
                        .values[14] != 1) ++bad;
                    if (d->tables[5]
                        .values[15] != 1) ++bad;
                    if (d->tables[5]
                        .values[16] != 2) ++bad;
                    if (d->tables[5]
                        .values[17] != 2) ++bad;
                    if (d->tables[5]
                        .values[18] != 1) ++bad;
                    if (d->tables[5]
                        .values[19] != 1) ++bad;
                    if (d->tables[5]
                        .values[20] != 1) ++bad;
                    if (d->tables[5]
                        .values[21] != 2) ++bad;
                    if (d->tables[5]
                        .values[22] != 2) ++bad;
                    if (d->tables[5]
                        .values[23] != 2) ++bad;
                    if (d->tables[5]
                        .values[24] != 1) ++bad;
                    if (d->tables[5]
                        .values[25] != 2) ++bad;
                    if (d->tables[5]
                        .values[26] != 2) ++bad;
                    if (d->tables[5]
                        .values[27] != 2) ++bad;
                    if (d->tables[5]
                        .values[28] != 1) ++bad;
                    if (d->tables[5]
                        .values[29] != 1) ++bad;
                    if (d->tables[5]
                        .values[30] != 1) ++bad;
                    if (d->tables[5]
                        .values[31] != 1) ++bad;
                    if (d->tables[5]
                        .values[32] != 1) ++bad;
                    if (d->tables[5]
                        .values[33] != 2) ++bad;
                    if (d->tables[5]
                        .values[34] != 3) ++bad;
                    if (d->tables[5]
                        .values[35] != 0) ++bad;
                    if (d->tables[5]
                        .values[36] != 2) ++bad;
                    if (d->tables[5]
                        .values[37] != 1) ++bad;
                    if (d->tables[5]
                        .values[38] != 1) ++bad;
                    if (d->tables[5]
                        .values[39] != 2) ++bad;
                    if (d->tables[5]
                        .values[40] != 1) ++bad;
                    if (d->tables[5]
                        .values[41] != 2) ++bad;
                    if (d->tables[5]
                        .values[42] != 2) ++bad;
                    if (d->tables[5]
                        .values[43] != 1) ++bad;
                    if (d->tables[5]
                        .values[44] != 1) ++bad;
                    if (d->tables[5]
                        .values[45] != 2) ++bad;
                    if (d->tables[5]
                        .values[46] != 2) ++bad;
                    if (d->tables[5]
                        .values[47] != 1) ++bad;
                    if (d->tables[5]
                        .values[48] != 1) ++bad;
                    if (d->tables[5]
                        .values[49] != 2) ++bad;
                    if (d->tables[5]
                        .values[50] != 1) ++bad;
                    if (d->tables[5]
                        .values[51] != 1) ++bad;
                    if (d->tables[5]
                        .values[52] != 2) ++bad;
                    if (d->tables[5]
                        .values[53] != 1) ++bad;
                    if (d->tables[5]
                        .values[54] != 1) ++bad;
                    if (d->tables[5]
                        .values[55] != 2) ++bad;
                    if (d->tables[5]
                        .values[56] != 1) ++bad;
                    if (d->tables[5]
                        .values[57] != 2) ++bad;
                    if (d->tables[5]
                        .values[58] != 2) ++bad;
                    if (d->tables[5]
                        .values[59] != 2) ++bad;
                    if (d->tables[5]
                        .values[60] != 2) ++bad;
                    if (d->tables[5]
                        .values[61] != 1) ++bad;
                    if (d->tables[5]
                        .values[62] != 1) ++bad;
                    if (d->tables[5]
                        .values[63] != 1) ++bad;
                    if (d->tables[5]
                        .values[64] != 2) ++bad;
                    if (d->tables[5]
                        .values[65] != 2) ++bad;
                    if (d->tables[5]
                        .values[66] != 1) ++bad;
                    if (d->tables[5]
                        .values[67] != 1) ++bad;
                    if (d->tables[6]
                        .values[0] != 35) ++bad;
                    if (d->tables[6]
                        .values[1] != 30) ++bad;
                    if (d->tables[6]
                        .values[2] != 2) ++bad;
                    if (d->tables[6]
                        .values[3] != 75) ++bad;
                    if (d->tables[6]
                        .values[4] != 50) ++bad;
                    if (d->tables[6]
                        .values[5] != 125) ++bad;
                    if (d->tables[6]
                        .values[6] != 100) ++bad;
                    if (d->tables[6]
                        .values[7] != 150) ++bad;
                    if (d->tables[6]
                        .values[8] != 15) ++bad;
                    if (d->tables[6]
                        .values[9] != 15) ++bad;
                    if (d->tables[6]
                        .values[10] != 4) ++bad;
                    if (d->tables[6]
                        .values[11] != 30) ++bad;
                    if (d->tables[6]
                        .values[12] != 10) ++bad;
                    if (d->tables[6]
                        .values[13] != 5) ++bad;
                    if (d->tables[6]
                        .values[14] != 60) ++bad;
                    if (d->tables[6]
                        .values[15] != 80) ++bad;
                    if (d->tables[6]
                        .values[16] != 150) ++bad;
                    if (d->tables[6]
                        .values[17] != 35) ++bad;
                    if (d->tables[6]
                        .values[18] != 75) ++bad;
                    if (d->tables[6]
                        .values[19] != 1) ++bad;
                    if (d->tables[6]
                        .values[20] != 75) ++bad;
                    if (d->tables[6]
                        .values[21] != 100) ++bad;
                    if (d->tables[6]
                        .values[22] != 80) ++bad;
                    if (d->tables[6]
                        .values[23] != 150) ++bad;
                    if (d->tables[6]
                        .values[24] != 175) ++bad;
                    if (d->tables[6]
                        .values[25] != 60) ++bad;
                    if (d->tables[6]
                        .values[26] != 150) ++bad;
                    if (d->tables[6]
                        .values[27] != 50) ++bad;
                    if (d->tables[6]
                        .values[28] != 80) ++bad;
                    if (d->tables[6]
                        .values[29] != 20) ++bad;
                    if (d->tables[6]
                        .values[30] != 40) ++bad;
                    if (d->tables[6]
                        .values[31] != 6) ++bad;
                    if (d->tables[6]
                        .values[32] != 50) ++bad;
                    if (d->tables[6]
                        .values[33] != 100) ++bad;
                    if (d->tables[6]
                        .values[34] != 150) ++bad;
                    if (d->tables[6]
                        .values[35] != 20) ++bad;
                    if (d->tables[6]
                        .values[36] != 100) ++bad;
                    if (d->tables[6]
                        .values[37] != 50) ++bad;
                    if (d->tables[6]
                        .values[38] != 80) ++bad;
                    if (d->tables[6]
                        .values[39] != 125) ++bad;
                    if (d->tables[6]
                        .values[40] != 80) ++bad;
                    if (d->tables[6]
                        .values[41] != 60) ++bad;
                    if (d->tables[6]
                        .values[42] != 40) ++bad;
                    if (d->tables[6]
                        .values[43] != 80) ++bad;
                    if (d->tables[6]
                        .values[44] != 1) ++bad;
                    if (d->tables[6]
                        .values[45] != 2) ++bad;
                    if (d->tables[6]
                        .values[46] != 50) ++bad;
                    if (d->tables[6]
                        .values[47] != 10) ++bad;
                    if (d->tables[6]
                        .values[48] != 40) ++bad;
                    if (d->tables[6]
                        .values[49] != 2) ++bad;
                    if (d->tables[6]
                        .values[50] != 1) ++bad;
                    if (d->tables[6]
                        .values[51] != 60) ++bad;
                    if (d->tables[6]
                        .values[52] != 50) ++bad;
                    if (d->tables[6]
                        .values[53] != 35) ++bad;
                    if (d->tables[6]
                        .values[54] != 50) ++bad;
                    if (d->tables[6]
                        .values[55] != 5) ++bad;
                    if (d->tables[6]
                        .values[56] != 4) ++bad;
                    if (d->tables[6]
                        .values[57] != 100) ++bad;
                    if (d->tables[6]
                        .values[58] != 75) ++bad;
                    if (d->tables[6]
                        .values[59] != 80) ++bad;
                    if (d->tables[6]
                        .values[60] != 75) ++bad;
                    if (d->tables[6]
                        .values[61] != 60) ++bad;
                    if (d->tables[6]
                        .values[62] != 35) ++bad;
                    if (d->tables[6]
                        .values[63] != 250) ++bad;
                    if (d->tables[6]
                        .values[64] != 50) ++bad;
                    if (d->tables[6]
                        .values[65] != 125) ++bad;
                    if (d->tables[6]
                        .values[66] != 35) ++bad;
                    if (d->tables[6]
                        .values[67] != 1) ++bad;
                    if (d->tables[7]
                        .values[0] != 35) ++bad;
                    if (d->tables[7]
                        .values[1] != 30) ++bad;
                    if (d->tables[7]
                        .values[2] != 2) ++bad;
                    if (d->tables[7]
                        .values[3] != 75) ++bad;
                    if (d->tables[7]
                        .values[4] != 50) ++bad;
                    if (d->tables[7]
                        .values[5] != 125) ++bad;
                    if (d->tables[7]
                        .values[6] != 100) ++bad;
                    if (d->tables[7]
                        .values[7] != 150) ++bad;
                    if (d->tables[7]
                        .values[8] != 15) ++bad;
                    if (d->tables[7]
                        .values[9] != 15) ++bad;
                    if (d->tables[7]
                        .values[10] != 2) ++bad;
                    if (d->tables[7]
                        .values[11] != 30) ++bad;
                    if (d->tables[7]
                        .values[12] != 10) ++bad;
                    if (d->tables[7]
                        .values[13] != 5) ++bad;
                    if (d->tables[7]
                        .values[14] != 60) ++bad;
                    if (d->tables[7]
                        .values[15] != 80) ++bad;
                    if (d->tables[7]
                        .values[16] != 150) ++bad;
                    if (d->tables[7]
                        .values[17] != 35) ++bad;
                    if (d->tables[7]
                        .values[18] != 75) ++bad;
                    if (d->tables[7]
                        .values[19] != 1) ++bad;
                    if (d->tables[7]
                        .values[20] != 75) ++bad;
                    if (d->tables[7]
                        .values[21] != 100) ++bad;
                    if (d->tables[7]
                        .values[22] != 80) ++bad;
                    if (d->tables[7]
                        .values[23] != 150) ++bad;
                    if (d->tables[7]
                        .values[24] != 175) ++bad;
                    if (d->tables[7]
                        .values[25] != 50) ++bad;
                    if (d->tables[7]
                        .values[26] != 150) ++bad;
                    if (d->tables[7]
                        .values[27] != 50) ++bad;
                    if (d->tables[7]
                        .values[28] != 80) ++bad;
                    if (d->tables[7]
                        .values[29] != 20) ++bad;
                    if (d->tables[7]
                        .values[30] != 40) ++bad;
                    if (d->tables[7]
                        .values[31] != 6) ++bad;
                    if (d->tables[7]
                        .values[32] != 50) ++bad;
                    if (d->tables[7]
                        .values[33] != 100) ++bad;
                    if (d->tables[7]
                        .values[34] != 150) ++bad;
                    if (d->tables[7]
                        .values[35] != 20) ++bad;
                    if (d->tables[7]
                        .values[36] != 100) ++bad;
                    if (d->tables[7]
                        .values[37] != 50) ++bad;
                    if (d->tables[7]
                        .values[38] != 80) ++bad;
                    if (d->tables[7]
                        .values[39] != 125) ++bad;
                    if (d->tables[7]
                        .values[40] != 80) ++bad;
                    if (d->tables[7]
                        .values[41] != 60) ++bad;
                    if (d->tables[7]
                        .values[42] != 40) ++bad;
                    if (d->tables[7]
                        .values[43] != 80) ++bad;
                    if (d->tables[7]
                        .values[44] != 1) ++bad;
                    if (d->tables[7]
                        .values[45] != 2) ++bad;
                    if (d->tables[7]
                        .values[46] != 50) ++bad;
                    if (d->tables[7]
                        .values[47] != 10) ++bad;
                    if (d->tables[7]
                        .values[48] != 40) ++bad;
                    if (d->tables[7]
                        .values[49] != 2) ++bad;
                    if (d->tables[7]
                        .values[50] != 1) ++bad;
                    if (d->tables[7]
                        .values[51] != 40) ++bad;
                    if (d->tables[7]
                        .values[52] != 50) ++bad;
                    if (d->tables[7]
                        .values[53] != 35) ++bad;
                    if (d->tables[7]
                        .values[54] != 50) ++bad;
                    if (d->tables[7]
                        .values[55] != 5) ++bad;
                    if (d->tables[7]
                        .values[56] != 4) ++bad;
                    if (d->tables[7]
                        .values[57] != 100) ++bad;
                    if (d->tables[7]
                        .values[58] != 75) ++bad;
                    if (d->tables[7]
                        .values[59] != 60) ++bad;
                    if (d->tables[7]
                        .values[60] != 75) ++bad;
                    if (d->tables[7]
                        .values[61] != 60) ++bad;
                    if (d->tables[7]
                        .values[62] != 35) ++bad;
                    if (d->tables[7]
                        .values[63] != 250) ++bad;
                    if (d->tables[7]
                        .values[64] != 50) ++bad;
                    if (d->tables[7]
                        .values[65] != 125) ++bad;
                    if (d->tables[7]
                        .values[66] != 25) ++bad;
                    if (d->tables[7]
                        .values[67] != 1) ++bad;
                    if (std::string(rules::uawtName(0))
                        != "Aklys") ++bad;
                    if (std::string(rules::uawtName(1))
                        != "Atlatl and javelin") ++bad;
                    if (std::string(rules::uawtName(2))
                        != "Arrow") ++bad;
                    if (std::string(rules::uawtName(3))
                        != "Axe, Battle") ++bad;
                    if (std::string(rules::uawtName(4))
                        != "Axe, Hand or Throwing") ++bad;
                    if (std::string(rules::uawtName(5))
                        != "Bardiche") ++bad;
                    if (std::string(rules::uawtName(6))
                        != "Bec de Corbin") ++bad;
                    if (std::string(rules::uawtName(7))
                        != "Bill-Guisarme") ++bad;
                    if (std::string(rules::uawtName(8))
                        != "Blowgun and needle") ++bad;
                    if (std::string(rules::uawtName(9))
                        != "Bo Stick") ++bad;
                    if (std::string(rules::uawtName(10))
                        != "Caltrop") ++bad;
                    if (std::string(rules::uawtName(11))
                        != "Club") ++bad;
                    if (std::string(rules::uawtName(12))
                        != "Dagger") ++bad;
                    if (std::string(rules::uawtName(13))
                        != "Dart") ++bad;
                    if (std::string(rules::uawtName(14))
                        != "Fauchard") ++bad;
                    if (std::string(rules::uawtName(15))
                        != "Fauchard-Fork") ++bad;
                    if (std::string(rules::uawtName(16))
                        != "Flail, Footman's") ++bad;
                    if (std::string(rules::uawtName(17))
                        != "Flail, Horseman's") ++bad;
                    if (std::string(rules::uawtName(18))
                        != "Military Fork") ++bad;
                    if (std::string(rules::uawtName(19))
                        != "Garrot") ++bad;
                    if (std::string(rules::uawtName(20))
                        != "Glaive") ++bad;
                    if (std::string(rules::uawtName(21))
                        != "Glaive-Guisarme") ++bad;
                    if (std::string(rules::uawtName(22))
                        != "Guisarme") ++bad;
                    if (std::string(rules::uawtName(23))
                        != "Guisarme-Voulge") ++bad;
                    if (std::string(rules::uawtName(24))
                        != "Halberd") ++bad;
                    if (std::string(rules::uawtName(25))
                        != "Harpoon") ++bad;
                    if (std::string(rules::uawtName(26))
                        != "Hammer, Lucern") ++bad;
                    if (std::string(rules::uawtName(27))
                        != "Hammer") ++bad;
                    if (std::string(rules::uawtName(28))
                        != "Hook Fauchard") ++bad;
                    if (std::string(rules::uawtName(29))
                        != "Javelin") ++bad;
                    if (std::string(rules::uawtName(30))
                        != "Jo Stick") ++bad;
                    if (std::string(rules::uawtName(31))
                        != "Knife") ++bad;
                    if (std::string(rules::uawtName(32))
                        != "Lance (light horse)") ++bad;
                    if (std::string(rules::uawtName(33))
                        != "Lance (medium horse)") ++bad;
                    if (std::string(rules::uawtName(34))
                        != "Lance (heavy horse)") ++bad;
                    if (std::string(rules::uawtName(35))
                        != "Lasso") ++bad;
                    if (std::string(rules::uawtName(36))
                        != "Mace, Footman's") ++bad;
                    if (std::string(rules::uawtName(37))
                        != "Mace, Horseman's") ++bad;
                    if (std::string(rules::uawtName(38))
                        != "Man Catcher") ++bad;
                    if (std::string(rules::uawtName(39))
                        != "Morning Star") ++bad;
                    if (std::string(rules::uawtName(40))
                        != "Partisan") ++bad;
                    if (std::string(rules::uawtName(41))
                        != "Pick, Footman's") ++bad;
                    if (std::string(rules::uawtName(42))
                        != "Pick, Horseman's") ++bad;
                    if (std::string(rules::uawtName(43))
                        != "Pike, Awl") ++bad;
                    if (std::string(rules::uawtName(44))
                        != "Quarrel (or Bolt), light") ++bad;
                    if (std::string(rules::uawtName(45))
                        != "Quarrel (or Bolt), heavy") ++bad;
                    if (std::string(rules::uawtName(46))
                        != "Ranseur") ++bad;
                    if (std::string(rules::uawtName(47))
                        != "Sap") ++bad;
                    if (std::string(rules::uawtName(48))
                        != "Scimitar") ++bad;
                    if (std::string(rules::uawtName(49))
                        != "Sling Bullet") ++bad;
                    if (std::string(rules::uawtName(50))
                        != "Sling Stone") ++bad;
                    if (std::string(rules::uawtName(51))
                        != "Spear") ++bad;
                    if (std::string(rules::uawtName(52))
                        != "Spetum") ++bad;
                    if (std::string(rules::uawtName(53))
                        != "Spiked Buckler") ++bad;
                    if (std::string(rules::uawtName(54))
                        != "Staff, Quarter") ++bad;
                    if (std::string(rules::uawtName(55))
                        != "Staff Sling Bullet") ++bad;
                    if (std::string(rules::uawtName(56))
                        != "Staff Sling Stone") ++bad;
                    if (std::string(rules::uawtName(57))
                        != "Sword, Bastard") ++bad;
                    if (std::string(rules::uawtName(58))
                        != "Sword, Broad") ++bad;
                    if (std::string(rules::uawtName(59))
                        != "Sword, Falchion") ++bad;
                    if (std::string(rules::uawtName(60))
                        != "Sword, Khopesh") ++bad;
                    if (std::string(rules::uawtName(61))
                        != "Long Sword") ++bad;
                    if (std::string(rules::uawtName(62))
                        != "Sword, Short") ++bad;
                    if (std::string(rules::uawtName(63))
                        != "Sword, Two-handed") ++bad;
                    if (std::string(rules::uawtName(64))
                        != "Trident") ++bad;
                    if (std::string(rules::uawtName(65))
                        != "Voulge") ++bad;
                    if (std::string(rules::uawtName(66))
                        != "Whip") ++bad;
                    if (std::string(rules::uawtName(67))
                        != "Quarrel (or Bolt), hand") ++bad;
                    if (rules::uawtIsNewWeapon(0) != 1) ++bad;
                    if (rules::uawtIsNewWeapon(1) != 1) ++bad;
                    if (rules::uawtIsNewWeapon(2) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(3) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(4) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(5) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(6) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(7) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(8) != 1) ++bad;
                    if (rules::uawtIsNewWeapon(9) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(10) != 1) ++bad;
                    if (rules::uawtIsNewWeapon(11) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(12) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(13) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(14) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(15) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(16) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(17) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(18) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(19) != 1) ++bad;
                    if (rules::uawtIsNewWeapon(20) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(21) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(22) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(23) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(24) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(25) != 1) ++bad;
                    if (rules::uawtIsNewWeapon(26) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(27) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(28) != 1) ++bad;
                    if (rules::uawtIsNewWeapon(29) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(30) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(31) != 1) ++bad;
                    if (rules::uawtIsNewWeapon(32) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(33) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(34) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(35) != 1) ++bad;
                    if (rules::uawtIsNewWeapon(36) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(37) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(38) != 1) ++bad;
                    if (rules::uawtIsNewWeapon(39) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(40) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(41) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(42) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(43) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(44) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(45) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(46) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(47) != 1) ++bad;
                    if (rules::uawtIsNewWeapon(48) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(49) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(50) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(51) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(52) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(53) != 1) ++bad;
                    if (rules::uawtIsNewWeapon(54) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(55) != 1) ++bad;
                    if (rules::uawtIsNewWeapon(56) != 1) ++bad;
                    if (rules::uawtIsNewWeapon(57) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(58) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(59) != 1) ++bad;
                    if (rules::uawtIsNewWeapon(60) != 1) ++bad;
                    if (rules::uawtIsNewWeapon(61) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(62) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(63) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(64) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(65) != 0) ++bad;
                    if (rules::uawtIsNewWeapon(66) != 1) ++bad;
                    if (rules::uawtIsNewWeapon(67) != 1) ++bad;
                    if (rules::uawtPhbSeamIndex(0) != -1) ++bad;
                    if (rules::uawtPhbSeamIndex(1) != -1) ++bad;
                    if (rules::uawtPhbSeamIndex(2) != 0) ++bad;
                    if (rules::uawtPhbSeamIndex(3) != 1) ++bad;
                    if (rules::uawtPhbSeamIndex(4) != 2) ++bad;
                    if (rules::uawtPhbSeamIndex(5) != 3) ++bad;
                    if (rules::uawtPhbSeamIndex(6) != 4) ++bad;
                    if (rules::uawtPhbSeamIndex(7) != 5) ++bad;
                    if (rules::uawtPhbSeamIndex(8) != -1) ++bad;
                    if (rules::uawtPhbSeamIndex(9) != 6) ++bad;
                    if (rules::uawtPhbSeamIndex(10) != -1) ++bad;
                    if (rules::uawtPhbSeamIndex(11) != 7) ++bad;
                    if (rules::uawtPhbSeamIndex(12) != 8) ++bad;
                    if (rules::uawtPhbSeamIndex(13) != 9) ++bad;
                    if (rules::uawtPhbSeamIndex(14) != 10) ++bad;
                    if (rules::uawtPhbSeamIndex(15) != 11) ++bad;
                    if (rules::uawtPhbSeamIndex(16) != 12) ++bad;
                    if (rules::uawtPhbSeamIndex(17) != 13) ++bad;
                    if (rules::uawtPhbSeamIndex(18) != 14) ++bad;
                    if (rules::uawtPhbSeamIndex(19) != -1) ++bad;
                    if (rules::uawtPhbSeamIndex(20) != 15) ++bad;
                    if (rules::uawtPhbSeamIndex(21) != 16) ++bad;
                    if (rules::uawtPhbSeamIndex(22) != 17) ++bad;
                    if (rules::uawtPhbSeamIndex(23) != 18) ++bad;
                    if (rules::uawtPhbSeamIndex(24) != 19) ++bad;
                    if (rules::uawtPhbSeamIndex(25) != -1) ++bad;
                    if (rules::uawtPhbSeamIndex(26) != 20) ++bad;
                    if (rules::uawtPhbSeamIndex(27) != 21) ++bad;
                    if (rules::uawtPhbSeamIndex(28) != -1) ++bad;
                    if (rules::uawtPhbSeamIndex(29) != 22) ++bad;
                    if (rules::uawtPhbSeamIndex(30) != 23) ++bad;
                    if (rules::uawtPhbSeamIndex(31) != -1) ++bad;
                    if (rules::uawtPhbSeamIndex(32) != 24) ++bad;
                    if (rules::uawtPhbSeamIndex(33) != 25) ++bad;
                    if (rules::uawtPhbSeamIndex(34) != 26) ++bad;
                    if (rules::uawtPhbSeamIndex(35) != -1) ++bad;
                    if (rules::uawtPhbSeamIndex(36) != 27) ++bad;
                    if (rules::uawtPhbSeamIndex(37) != 28) ++bad;
                    if (rules::uawtPhbSeamIndex(38) != -1) ++bad;
                    if (rules::uawtPhbSeamIndex(39) != 29) ++bad;
                    if (rules::uawtPhbSeamIndex(40) != 30) ++bad;
                    if (rules::uawtPhbSeamIndex(41) != 31) ++bad;
                    if (rules::uawtPhbSeamIndex(42) != 32) ++bad;
                    if (rules::uawtPhbSeamIndex(43) != 33) ++bad;
                    if (rules::uawtPhbSeamIndex(44) != 34) ++bad;
                    if (rules::uawtPhbSeamIndex(45) != 35) ++bad;
                    if (rules::uawtPhbSeamIndex(46) != 36) ++bad;
                    if (rules::uawtPhbSeamIndex(47) != -1) ++bad;
                    if (rules::uawtPhbSeamIndex(48) != 37) ++bad;
                    if (rules::uawtPhbSeamIndex(49) != 38) ++bad;
                    if (rules::uawtPhbSeamIndex(50) != 39) ++bad;
                    if (rules::uawtPhbSeamIndex(51) != 40) ++bad;
                    if (rules::uawtPhbSeamIndex(52) != 41) ++bad;
                    if (rules::uawtPhbSeamIndex(53) != -1) ++bad;
                    if (rules::uawtPhbSeamIndex(54) != 42) ++bad;
                    if (rules::uawtPhbSeamIndex(55) != -1) ++bad;
                    if (rules::uawtPhbSeamIndex(56) != -1) ++bad;
                    if (rules::uawtPhbSeamIndex(57) != 43) ++bad;
                    if (rules::uawtPhbSeamIndex(58) != 44) ++bad;
                    if (rules::uawtPhbSeamIndex(59) != -1) ++bad;
                    if (rules::uawtPhbSeamIndex(60) != -1) ++bad;
                    if (rules::uawtPhbSeamIndex(61) != 45) ++bad;
                    if (rules::uawtPhbSeamIndex(62) != 46) ++bad;
                    if (rules::uawtPhbSeamIndex(63) != 47) ++bad;
                    if (rules::uawtPhbSeamIndex(64) != 48) ++bad;
                    if (rules::uawtPhbSeamIndex(65) != 49) ++bad;
                    if (rules::uawtPhbSeamIndex(66) != -1) ++bad;
                    if (rules::uawtPhbSeamIndex(67) != -1) ++bad;
                    if (rules::uawtWeightMin(0) != 35) ++bad;
                    if (rules::uawtWeightMin(1) != 30) ++bad;
                    if (rules::uawtWeightMin(2) != 2) ++bad;
                    if (rules::uawtWeightMin(3) != 75) ++bad;
                    if (rules::uawtWeightMin(4) != 50) ++bad;
                    if (rules::uawtWeightMin(5) != 125) ++bad;
                    if (rules::uawtWeightMin(6) != 100) ++bad;
                    if (rules::uawtWeightMin(7) != 150) ++bad;
                    if (rules::uawtWeightMin(8) != 15) ++bad;
                    if (rules::uawtWeightMin(9) != 15) ++bad;
                    if (rules::uawtWeightMin(10) != 2) ++bad;
                    if (rules::uawtWeightMin(11) != 30) ++bad;
                    if (rules::uawtWeightMin(12) != 10) ++bad;
                    if (rules::uawtWeightMin(13) != 5) ++bad;
                    if (rules::uawtWeightMin(14) != 60) ++bad;
                    if (rules::uawtWeightMin(15) != 80) ++bad;
                    if (rules::uawtWeightMin(16) != 150) ++bad;
                    if (rules::uawtWeightMin(17) != 35) ++bad;
                    if (rules::uawtWeightMin(18) != 75) ++bad;
                    if (rules::uawtWeightMin(19) != 1) ++bad;
                    if (rules::uawtWeightMin(20) != 75) ++bad;
                    if (rules::uawtWeightMin(21) != 100) ++bad;
                    if (rules::uawtWeightMin(22) != 80) ++bad;
                    if (rules::uawtWeightMin(23) != 150) ++bad;
                    if (rules::uawtWeightMin(24) != 175) ++bad;
                    if (rules::uawtWeightMin(25) != 50) ++bad;
                    if (rules::uawtWeightMin(26) != 150) ++bad;
                    if (rules::uawtWeightMin(27) != 50) ++bad;
                    if (rules::uawtWeightMin(28) != 80) ++bad;
                    if (rules::uawtWeightMin(29) != 20) ++bad;
                    if (rules::uawtWeightMin(30) != 40) ++bad;
                    if (rules::uawtWeightMin(31) != 6) ++bad;
                    if (rules::uawtWeightMin(32) != 50) ++bad;
                    if (rules::uawtWeightMin(33) != 100) ++bad;
                    if (rules::uawtWeightMin(34) != 150) ++bad;
                    if (rules::uawtWeightMin(35) != 20) ++bad;
                    if (rules::uawtWeightMin(36) != 100) ++bad;
                    if (rules::uawtWeightMin(37) != 50) ++bad;
                    if (rules::uawtWeightMin(38) != 80) ++bad;
                    if (rules::uawtWeightMin(39) != 125) ++bad;
                    if (rules::uawtWeightMin(40) != 80) ++bad;
                    if (rules::uawtWeightMin(41) != 60) ++bad;
                    if (rules::uawtWeightMin(42) != 40) ++bad;
                    if (rules::uawtWeightMin(43) != 80) ++bad;
                    if (rules::uawtWeightMin(44) != 1) ++bad;
                    if (rules::uawtWeightMin(45) != 2) ++bad;
                    if (rules::uawtWeightMin(46) != 50) ++bad;
                    if (rules::uawtWeightMin(47) != 10) ++bad;
                    if (rules::uawtWeightMin(48) != 40) ++bad;
                    if (rules::uawtWeightMin(49) != 2) ++bad;
                    if (rules::uawtWeightMin(50) != 1) ++bad;
                    if (rules::uawtWeightMin(51) != 40) ++bad;
                    if (rules::uawtWeightMin(52) != 50) ++bad;
                    if (rules::uawtWeightMin(53) != 35) ++bad;
                    if (rules::uawtWeightMin(54) != 50) ++bad;
                    if (rules::uawtWeightMin(55) != 5) ++bad;
                    if (rules::uawtWeightMin(56) != 4) ++bad;
                    if (rules::uawtWeightMin(57) != 100) ++bad;
                    if (rules::uawtWeightMin(58) != 75) ++bad;
                    if (rules::uawtWeightMin(59) != 60) ++bad;
                    if (rules::uawtWeightMin(60) != 75) ++bad;
                    if (rules::uawtWeightMin(61) != 60) ++bad;
                    if (rules::uawtWeightMin(62) != 35) ++bad;
                    if (rules::uawtWeightMin(63) != 250) ++bad;
                    if (rules::uawtWeightMin(64) != 50) ++bad;
                    if (rules::uawtWeightMin(65) != 125) ++bad;
                    if (rules::uawtWeightMin(66) != 25) ++bad;
                    if (rules::uawtWeightMin(67) != 1) ++bad;
                    if (rules::uawtWeightMax(0) != 35) ++bad;
                    if (rules::uawtWeightMax(1) != 30) ++bad;
                    if (rules::uawtWeightMax(2) != 2) ++bad;
                    if (rules::uawtWeightMax(3) != 75) ++bad;
                    if (rules::uawtWeightMax(4) != 50) ++bad;
                    if (rules::uawtWeightMax(5) != 125) ++bad;
                    if (rules::uawtWeightMax(6) != 100) ++bad;
                    if (rules::uawtWeightMax(7) != 150) ++bad;
                    if (rules::uawtWeightMax(8) != 15) ++bad;
                    if (rules::uawtWeightMax(9) != 15) ++bad;
                    if (rules::uawtWeightMax(10) != 4) ++bad;
                    if (rules::uawtWeightMax(11) != 30) ++bad;
                    if (rules::uawtWeightMax(12) != 10) ++bad;
                    if (rules::uawtWeightMax(13) != 5) ++bad;
                    if (rules::uawtWeightMax(14) != 60) ++bad;
                    if (rules::uawtWeightMax(15) != 80) ++bad;
                    if (rules::uawtWeightMax(16) != 150) ++bad;
                    if (rules::uawtWeightMax(17) != 35) ++bad;
                    if (rules::uawtWeightMax(18) != 75) ++bad;
                    if (rules::uawtWeightMax(19) != 1) ++bad;
                    if (rules::uawtWeightMax(20) != 75) ++bad;
                    if (rules::uawtWeightMax(21) != 100) ++bad;
                    if (rules::uawtWeightMax(22) != 80) ++bad;
                    if (rules::uawtWeightMax(23) != 150) ++bad;
                    if (rules::uawtWeightMax(24) != 175) ++bad;
                    if (rules::uawtWeightMax(25) != 60) ++bad;
                    if (rules::uawtWeightMax(26) != 150) ++bad;
                    if (rules::uawtWeightMax(27) != 50) ++bad;
                    if (rules::uawtWeightMax(28) != 80) ++bad;
                    if (rules::uawtWeightMax(29) != 20) ++bad;
                    if (rules::uawtWeightMax(30) != 40) ++bad;
                    if (rules::uawtWeightMax(31) != 6) ++bad;
                    if (rules::uawtWeightMax(32) != 50) ++bad;
                    if (rules::uawtWeightMax(33) != 100) ++bad;
                    if (rules::uawtWeightMax(34) != 150) ++bad;
                    if (rules::uawtWeightMax(35) != 20) ++bad;
                    if (rules::uawtWeightMax(36) != 100) ++bad;
                    if (rules::uawtWeightMax(37) != 50) ++bad;
                    if (rules::uawtWeightMax(38) != 80) ++bad;
                    if (rules::uawtWeightMax(39) != 125) ++bad;
                    if (rules::uawtWeightMax(40) != 80) ++bad;
                    if (rules::uawtWeightMax(41) != 60) ++bad;
                    if (rules::uawtWeightMax(42) != 40) ++bad;
                    if (rules::uawtWeightMax(43) != 80) ++bad;
                    if (rules::uawtWeightMax(44) != 1) ++bad;
                    if (rules::uawtWeightMax(45) != 2) ++bad;
                    if (rules::uawtWeightMax(46) != 50) ++bad;
                    if (rules::uawtWeightMax(47) != 10) ++bad;
                    if (rules::uawtWeightMax(48) != 40) ++bad;
                    if (rules::uawtWeightMax(49) != 2) ++bad;
                    if (rules::uawtWeightMax(50) != 1) ++bad;
                    if (rules::uawtWeightMax(51) != 60) ++bad;
                    if (rules::uawtWeightMax(52) != 50) ++bad;
                    if (rules::uawtWeightMax(53) != 35) ++bad;
                    if (rules::uawtWeightMax(54) != 50) ++bad;
                    if (rules::uawtWeightMax(55) != 5) ++bad;
                    if (rules::uawtWeightMax(56) != 4) ++bad;
                    if (rules::uawtWeightMax(57) != 100) ++bad;
                    if (rules::uawtWeightMax(58) != 75) ++bad;
                    if (rules::uawtWeightMax(59) != 80) ++bad;
                    if (rules::uawtWeightMax(60) != 75) ++bad;
                    if (rules::uawtWeightMax(61) != 60) ++bad;
                    if (rules::uawtWeightMax(62) != 35) ++bad;
                    if (rules::uawtWeightMax(63) != 250) ++bad;
                    if (rules::uawtWeightMax(64) != 50) ++bad;
                    if (rules::uawtWeightMax(65) != 125) ++bad;
                    if (rules::uawtWeightMax(66) != 35) ++bad;
                    if (rules::uawtWeightMax(67) != 1) ++bad;
                    if (rules::uawtDamageSMMin(0) != 1) ++bad;
                    if (rules::uawtDamageSMMin(1) != 1) ++bad;
                    if (rules::uawtDamageSMMin(2) != 1) ++bad;
                    if (rules::uawtDamageSMMin(3) != 1) ++bad;
                    if (rules::uawtDamageSMMin(4) != 1) ++bad;
                    if (rules::uawtDamageSMMin(5) != 2) ++bad;
                    if (rules::uawtDamageSMMin(6) != 1) ++bad;
                    if (rules::uawtDamageSMMin(7) != 2) ++bad;
                    if (rules::uawtDamageSMMin(8) != 1) ++bad;
                    if (rules::uawtDamageSMMin(9) != 1) ++bad;
                    if (rules::uawtDamageSMMin(10) != 1) ++bad;
                    if (rules::uawtDamageSMMin(11) != 1) ++bad;
                    if (rules::uawtDamageSMMin(12) != 1) ++bad;
                    if (rules::uawtDamageSMMin(13) != 1) ++bad;
                    if (rules::uawtDamageSMMin(14) != 1) ++bad;
                    if (rules::uawtDamageSMMin(15) != 1) ++bad;
                    if (rules::uawtDamageSMMin(16) != 2) ++bad;
                    if (rules::uawtDamageSMMin(17) != 2) ++bad;
                    if (rules::uawtDamageSMMin(18) != 1) ++bad;
                    if (rules::uawtDamageSMMin(19) != 1) ++bad;
                    if (rules::uawtDamageSMMin(20) != 1) ++bad;
                    if (rules::uawtDamageSMMin(21) != 2) ++bad;
                    if (rules::uawtDamageSMMin(22) != 2) ++bad;
                    if (rules::uawtDamageSMMin(23) != 2) ++bad;
                    if (rules::uawtDamageSMMin(24) != 1) ++bad;
                    if (rules::uawtDamageSMMin(25) != 2) ++bad;
                    if (rules::uawtDamageSMMin(26) != 2) ++bad;
                    if (rules::uawtDamageSMMin(27) != 2) ++bad;
                    if (rules::uawtDamageSMMin(28) != 1) ++bad;
                    if (rules::uawtDamageSMMin(29) != 1) ++bad;
                    if (rules::uawtDamageSMMin(30) != 1) ++bad;
                    if (rules::uawtDamageSMMin(31) != 1) ++bad;
                    if (rules::uawtDamageSMMin(32) != 1) ++bad;
                    if (rules::uawtDamageSMMin(33) != 2) ++bad;
                    if (rules::uawtDamageSMMin(34) != 3) ++bad;
                    if (rules::uawtDamageSMMin(35) != 0) ++bad;
                    if (rules::uawtDamageSMMin(36) != 2) ++bad;
                    if (rules::uawtDamageSMMin(37) != 1) ++bad;
                    if (rules::uawtDamageSMMin(38) != 1) ++bad;
                    if (rules::uawtDamageSMMin(39) != 2) ++bad;
                    if (rules::uawtDamageSMMin(40) != 1) ++bad;
                    if (rules::uawtDamageSMMin(41) != 2) ++bad;
                    if (rules::uawtDamageSMMin(42) != 2) ++bad;
                    if (rules::uawtDamageSMMin(43) != 1) ++bad;
                    if (rules::uawtDamageSMMin(44) != 1) ++bad;
                    if (rules::uawtDamageSMMin(45) != 2) ++bad;
                    if (rules::uawtDamageSMMin(46) != 2) ++bad;
                    if (rules::uawtDamageSMMin(47) != 1) ++bad;
                    if (rules::uawtDamageSMMin(48) != 1) ++bad;
                    if (rules::uawtDamageSMMin(49) != 2) ++bad;
                    if (rules::uawtDamageSMMin(50) != 1) ++bad;
                    if (rules::uawtDamageSMMin(51) != 1) ++bad;
                    if (rules::uawtDamageSMMin(52) != 2) ++bad;
                    if (rules::uawtDamageSMMin(53) != 1) ++bad;
                    if (rules::uawtDamageSMMin(54) != 1) ++bad;
                    if (rules::uawtDamageSMMin(55) != 2) ++bad;
                    if (rules::uawtDamageSMMin(56) != 1) ++bad;
                    if (rules::uawtDamageSMMin(57) != 2) ++bad;
                    if (rules::uawtDamageSMMin(58) != 2) ++bad;
                    if (rules::uawtDamageSMMin(59) != 2) ++bad;
                    if (rules::uawtDamageSMMin(60) != 2) ++bad;
                    if (rules::uawtDamageSMMin(61) != 1) ++bad;
                    if (rules::uawtDamageSMMin(62) != 1) ++bad;
                    if (rules::uawtDamageSMMin(63) != 1) ++bad;
                    if (rules::uawtDamageSMMin(64) != 2) ++bad;
                    if (rules::uawtDamageSMMin(65) != 2) ++bad;
                    if (rules::uawtDamageSMMin(66) != 1) ++bad;
                    if (rules::uawtDamageSMMin(67) != 1) ++bad;
                    if (rules::uawtDamageSMMax(0) != 6) ++bad;
                    if (rules::uawtDamageSMMax(1) != 6) ++bad;
                    if (rules::uawtDamageSMMax(2) != 6) ++bad;
                    if (rules::uawtDamageSMMax(3) != 8) ++bad;
                    if (rules::uawtDamageSMMax(4) != 6) ++bad;
                    if (rules::uawtDamageSMMax(5) != 8) ++bad;
                    if (rules::uawtDamageSMMax(6) != 8) ++bad;
                    if (rules::uawtDamageSMMax(7) != 8) ++bad;
                    if (rules::uawtDamageSMMax(8) != 1) ++bad;
                    if (rules::uawtDamageSMMax(9) != 6) ++bad;
                    if (rules::uawtDamageSMMax(10) != 1) ++bad;
                    if (rules::uawtDamageSMMax(11) != 6) ++bad;
                    if (rules::uawtDamageSMMax(12) != 4) ++bad;
                    if (rules::uawtDamageSMMax(13) != 3) ++bad;
                    if (rules::uawtDamageSMMax(14) != 6) ++bad;
                    if (rules::uawtDamageSMMax(15) != 8) ++bad;
                    if (rules::uawtDamageSMMax(16) != 7) ++bad;
                    if (rules::uawtDamageSMMax(17) != 5) ++bad;
                    if (rules::uawtDamageSMMax(18) != 8) ++bad;
                    if (rules::uawtDamageSMMax(19) != 4) ++bad;
                    if (rules::uawtDamageSMMax(20) != 6) ++bad;
                    if (rules::uawtDamageSMMax(21) != 8) ++bad;
                    if (rules::uawtDamageSMMax(22) != 8) ++bad;
                    if (rules::uawtDamageSMMax(23) != 8) ++bad;
                    if (rules::uawtDamageSMMax(24) != 10) ++bad;
                    if (rules::uawtDamageSMMax(25) != 8) ++bad;
                    if (rules::uawtDamageSMMax(26) != 8) ++bad;
                    if (rules::uawtDamageSMMax(27) != 5) ++bad;
                    if (rules::uawtDamageSMMax(28) != 4) ++bad;
                    if (rules::uawtDamageSMMax(29) != 6) ++bad;
                    if (rules::uawtDamageSMMax(30) != 6) ++bad;
                    if (rules::uawtDamageSMMax(31) != 3) ++bad;
                    if (rules::uawtDamageSMMax(32) != 6) ++bad;
                    if (rules::uawtDamageSMMax(33) != 7) ++bad;
                    if (rules::uawtDamageSMMax(34) != 9) ++bad;
                    if (rules::uawtDamageSMMax(35) != 0) ++bad;
                    if (rules::uawtDamageSMMax(36) != 7) ++bad;
                    if (rules::uawtDamageSMMax(37) != 6) ++bad;
                    if (rules::uawtDamageSMMax(38) != 2) ++bad;
                    if (rules::uawtDamageSMMax(39) != 8) ++bad;
                    if (rules::uawtDamageSMMax(40) != 6) ++bad;
                    if (rules::uawtDamageSMMax(41) != 7) ++bad;
                    if (rules::uawtDamageSMMax(42) != 5) ++bad;
                    if (rules::uawtDamageSMMax(43) != 6) ++bad;
                    if (rules::uawtDamageSMMax(44) != 4) ++bad;
                    if (rules::uawtDamageSMMax(45) != 5) ++bad;
                    if (rules::uawtDamageSMMax(46) != 8) ++bad;
                    if (rules::uawtDamageSMMax(47) != 2) ++bad;
                    if (rules::uawtDamageSMMax(48) != 8) ++bad;
                    if (rules::uawtDamageSMMax(49) != 5) ++bad;
                    if (rules::uawtDamageSMMax(50) != 4) ++bad;
                    if (rules::uawtDamageSMMax(51) != 6) ++bad;
                    if (rules::uawtDamageSMMax(52) != 7) ++bad;
                    if (rules::uawtDamageSMMax(53) != 4) ++bad;
                    if (rules::uawtDamageSMMax(54) != 6) ++bad;
                    if (rules::uawtDamageSMMax(55) != 8) ++bad;
                    if (rules::uawtDamageSMMax(56) != 8) ++bad;
                    if (rules::uawtDamageSMMax(57) != 8) ++bad;
                    if (rules::uawtDamageSMMax(58) != 8) ++bad;
                    if (rules::uawtDamageSMMax(59) != 7) ++bad;
                    if (rules::uawtDamageSMMax(60) != 8) ++bad;
                    if (rules::uawtDamageSMMax(61) != 8) ++bad;
                    if (rules::uawtDamageSMMax(62) != 6) ++bad;
                    if (rules::uawtDamageSMMax(63) != 10) ++bad;
                    if (rules::uawtDamageSMMax(64) != 7) ++bad;
                    if (rules::uawtDamageSMMax(65) != 8) ++bad;
                    if (rules::uawtDamageSMMax(66) != 2) ++bad;
                    if (rules::uawtDamageSMMax(67) != 3) ++bad;
                    if (rules::uawtDamageLMin(0) != 1) ++bad;
                    if (rules::uawtDamageLMin(1) != 1) ++bad;
                    if (rules::uawtDamageLMin(2) != 1) ++bad;
                    if (rules::uawtDamageLMin(3) != 1) ++bad;
                    if (rules::uawtDamageLMin(4) != 1) ++bad;
                    if (rules::uawtDamageLMin(5) != 3) ++bad;
                    if (rules::uawtDamageLMin(6) != 1) ++bad;
                    if (rules::uawtDamageLMin(7) != 1) ++bad;
                    if (rules::uawtDamageLMin(8) != 1) ++bad;
                    if (rules::uawtDamageLMin(9) != 1) ++bad;
                    if (rules::uawtDamageLMin(10) != 1) ++bad;
                    if (rules::uawtDamageLMin(11) != 1) ++bad;
                    if (rules::uawtDamageLMin(12) != 1) ++bad;
                    if (rules::uawtDamageLMin(13) != 1) ++bad;
                    if (rules::uawtDamageLMin(14) != 1) ++bad;
                    if (rules::uawtDamageLMin(15) != 1) ++bad;
                    if (rules::uawtDamageLMin(16) != 2) ++bad;
                    if (rules::uawtDamageLMin(17) != 2) ++bad;
                    if (rules::uawtDamageLMin(18) != 2) ++bad;
                    if (rules::uawtDamageLMin(19) != 1) ++bad;
                    if (rules::uawtDamageLMin(20) != 1) ++bad;
                    if (rules::uawtDamageLMin(21) != 2) ++bad;
                    if (rules::uawtDamageLMin(22) != 1) ++bad;
                    if (rules::uawtDamageLMin(23) != 2) ++bad;
                    if (rules::uawtDamageLMin(24) != 2) ++bad;
                    if (rules::uawtDamageLMin(25) != 2) ++bad;
                    if (rules::uawtDamageLMin(26) != 1) ++bad;
                    if (rules::uawtDamageLMin(27) != 1) ++bad;
                    if (rules::uawtDamageLMin(28) != 1) ++bad;
                    if (rules::uawtDamageLMin(29) != 1) ++bad;
                    if (rules::uawtDamageLMin(30) != 1) ++bad;
                    if (rules::uawtDamageLMin(31) != 1) ++bad;
                    if (rules::uawtDamageLMin(32) != 1) ++bad;
                    if (rules::uawtDamageLMin(33) != 2) ++bad;
                    if (rules::uawtDamageLMin(34) != 3) ++bad;
                    if (rules::uawtDamageLMin(35) != 0) ++bad;
                    if (rules::uawtDamageLMin(36) != 1) ++bad;
                    if (rules::uawtDamageLMin(37) != 1) ++bad;
                    if (rules::uawtDamageLMin(38) != 1) ++bad;
                    if (rules::uawtDamageLMin(39) != 2) ++bad;
                    if (rules::uawtDamageLMin(40) != 2) ++bad;
                    if (rules::uawtDamageLMin(41) != 2) ++bad;
                    if (rules::uawtDamageLMin(42) != 1) ++bad;
                    if (rules::uawtDamageLMin(43) != 1) ++bad;
                    if (rules::uawtDamageLMin(44) != 1) ++bad;
                    if (rules::uawtDamageLMin(45) != 2) ++bad;
                    if (rules::uawtDamageLMin(46) != 2) ++bad;
                    if (rules::uawtDamageLMin(47) != 1) ++bad;
                    if (rules::uawtDamageLMin(48) != 1) ++bad;
                    if (rules::uawtDamageLMin(49) != 2) ++bad;
                    if (rules::uawtDamageLMin(50) != 1) ++bad;
                    if (rules::uawtDamageLMin(51) != 1) ++bad;
                    if (rules::uawtDamageLMin(52) != 2) ++bad;
                    if (rules::uawtDamageLMin(53) != 1) ++bad;
                    if (rules::uawtDamageLMin(54) != 1) ++bad;
                    if (rules::uawtDamageLMin(55) != 3) ++bad;
                    if (rules::uawtDamageLMin(56) != 2) ++bad;
                    if (rules::uawtDamageLMin(57) != 2) ++bad;
                    if (rules::uawtDamageLMin(58) != 2) ++bad;
                    if (rules::uawtDamageLMin(59) != 2) ++bad;
                    if (rules::uawtDamageLMin(60) != 1) ++bad;
                    if (rules::uawtDamageLMin(61) != 1) ++bad;
                    if (rules::uawtDamageLMin(62) != 1) ++bad;
                    if (rules::uawtDamageLMin(63) != 3) ++bad;
                    if (rules::uawtDamageLMin(64) != 3) ++bad;
                    if (rules::uawtDamageLMin(65) != 2) ++bad;
                    if (rules::uawtDamageLMin(66) != 1) ++bad;
                    if (rules::uawtDamageLMin(67) != 1) ++bad;
                    if (rules::uawtDamageLMax(0) != 3) ++bad;
                    if (rules::uawtDamageLMax(1) != 6) ++bad;
                    if (rules::uawtDamageLMax(2) != 6) ++bad;
                    if (rules::uawtDamageLMax(3) != 8) ++bad;
                    if (rules::uawtDamageLMax(4) != 4) ++bad;
                    if (rules::uawtDamageLMax(5) != 12) ++bad;
                    if (rules::uawtDamageLMax(6) != 6) ++bad;
                    if (rules::uawtDamageLMax(7) != 10) ++bad;
                    if (rules::uawtDamageLMax(8) != 1) ++bad;
                    if (rules::uawtDamageLMax(9) != 3) ++bad;
                    if (rules::uawtDamageLMax(10) != 2) ++bad;
                    if (rules::uawtDamageLMax(11) != 3) ++bad;
                    if (rules::uawtDamageLMax(12) != 3) ++bad;
                    if (rules::uawtDamageLMax(13) != 2) ++bad;
                    if (rules::uawtDamageLMax(14) != 8) ++bad;
                    if (rules::uawtDamageLMax(15) != 10) ++bad;
                    if (rules::uawtDamageLMax(16) != 8) ++bad;
                    if (rules::uawtDamageLMax(17) != 5) ++bad;
                    if (rules::uawtDamageLMax(18) != 8) ++bad;
                    if (rules::uawtDamageLMax(19) != 6) ++bad;
                    if (rules::uawtDamageLMax(20) != 10) ++bad;
                    if (rules::uawtDamageLMax(21) != 12) ++bad;
                    if (rules::uawtDamageLMax(22) != 8) ++bad;
                    if (rules::uawtDamageLMax(23) != 8) ++bad;
                    if (rules::uawtDamageLMax(24) != 12) ++bad;
                    if (rules::uawtDamageLMax(25) != 12) ++bad;
                    if (rules::uawtDamageLMax(26) != 6) ++bad;
                    if (rules::uawtDamageLMax(27) != 4) ++bad;
                    if (rules::uawtDamageLMax(28) != 4) ++bad;
                    if (rules::uawtDamageLMax(29) != 6) ++bad;
                    if (rules::uawtDamageLMax(30) != 4) ++bad;
                    if (rules::uawtDamageLMax(31) != 2) ++bad;
                    if (rules::uawtDamageLMax(32) != 8) ++bad;
                    if (rules::uawtDamageLMax(33) != 12) ++bad;
                    if (rules::uawtDamageLMax(34) != 18) ++bad;
                    if (rules::uawtDamageLMax(35) != 0) ++bad;
                    if (rules::uawtDamageLMax(36) != 6) ++bad;
                    if (rules::uawtDamageLMax(37) != 4) ++bad;
                    if (rules::uawtDamageLMax(38) != 2) ++bad;
                    if (rules::uawtDamageLMax(39) != 7) ++bad;
                    if (rules::uawtDamageLMax(40) != 7) ++bad;
                    if (rules::uawtDamageLMax(41) != 8) ++bad;
                    if (rules::uawtDamageLMax(42) != 4) ++bad;
                    if (rules::uawtDamageLMax(43) != 12) ++bad;
                    if (rules::uawtDamageLMax(44) != 4) ++bad;
                    if (rules::uawtDamageLMax(45) != 7) ++bad;
                    if (rules::uawtDamageLMax(46) != 8) ++bad;
                    if (rules::uawtDamageLMax(47) != 2) ++bad;
                    if (rules::uawtDamageLMax(48) != 8) ++bad;
                    if (rules::uawtDamageLMax(49) != 7) ++bad;
                    if (rules::uawtDamageLMax(50) != 4) ++bad;
                    if (rules::uawtDamageLMax(51) != 8) ++bad;
                    if (rules::uawtDamageLMax(52) != 12) ++bad;
                    if (rules::uawtDamageLMax(53) != 3) ++bad;
                    if (rules::uawtDamageLMax(54) != 6) ++bad;
                    if (rules::uawtDamageLMax(55) != 9) ++bad;
                    if (rules::uawtDamageLMax(56) != 8) ++bad;
                    if (rules::uawtDamageLMax(57) != 16) ++bad;
                    if (rules::uawtDamageLMax(58) != 7) ++bad;
                    if (rules::uawtDamageLMax(59) != 8) ++bad;
                    if (rules::uawtDamageLMax(60) != 6) ++bad;
                    if (rules::uawtDamageLMax(61) != 12) ++bad;
                    if (rules::uawtDamageLMax(62) != 8) ++bad;
                    if (rules::uawtDamageLMax(63) != 18) ++bad;
                    if (rules::uawtDamageLMax(64) != 12) ++bad;
                    if (rules::uawtDamageLMax(65) != 8) ++bad;
                    if (rules::uawtDamageLMax(66) != 1) ++bad;
                    if (rules::uawtDamageLMax(67) != 2) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("uamt");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != -8) ++bad;
                    if (d->tables[0]
                        .values[1] != -7) ++bad;
                    if (d->tables[0]
                        .values[2] != -6) ++bad;
                    if (d->tables[0]
                        .values[3] != -5) ++bad;
                    if (d->tables[0]
                        .values[4] != -4) ++bad;
                    if (d->tables[0]
                        .values[5] != -3) ++bad;
                    if (d->tables[0]
                        .values[6] != -2) ++bad;
                    if (d->tables[0]
                        .values[7] != -6) ++bad;
                    if (d->tables[0]
                        .values[8] != -5) ++bad;
                    if (d->tables[0]
                        .values[9] != -4) ++bad;
                    if (d->tables[0]
                        .values[10] != -3) ++bad;
                    if (d->tables[0]
                        .values[11] != -2) ++bad;
                    if (d->tables[0]
                        .values[12] != -1) ++bad;
                    if (d->tables[0]
                        .values[13] != 0) ++bad;
                    if (d->tables[0]
                        .values[14] != -6) ++bad;
                    if (d->tables[0]
                        .values[15] != -5) ++bad;
                    if (d->tables[0]
                        .values[16] != -4) ++bad;
                    if (d->tables[0]
                        .values[17] != -3) ++bad;
                    if (d->tables[0]
                        .values[18] != -2) ++bad;
                    if (d->tables[0]
                        .values[19] != -1) ++bad;
                    if (d->tables[0]
                        .values[20] != -1) ++bad;
                    if (d->tables[0]
                        .values[21] != -14) ++bad;
                    if (d->tables[0]
                        .values[22] != -12) ++bad;
                    if (d->tables[0]
                        .values[23] != -10) ++bad;
                    if (d->tables[0]
                        .values[24] != -8) ++bad;
                    if (d->tables[0]
                        .values[25] != -6) ++bad;
                    if (d->tables[0]
                        .values[26] != -4) ++bad;
                    if (d->tables[0]
                        .values[27] != -2) ++bad;
                    if (d->tables[0]
                        .values[28] != -4) ++bad;
                    if (d->tables[0]
                        .values[29] != -3) ++bad;
                    if (d->tables[0]
                        .values[30] != -2) ++bad;
                    if (d->tables[0]
                        .values[31] != -1) ++bad;
                    if (d->tables[0]
                        .values[32] != 0) ++bad;
                    if (d->tables[0]
                        .values[33] != 0) ++bad;
                    if (d->tables[0]
                        .values[34] != 1) ++bad;
                    if (d->tables[0]
                        .values[35] != -4) ++bad;
                    if (d->tables[0]
                        .values[36] != -4) ++bad;
                    if (d->tables[0]
                        .values[37] != -3) ++bad;
                    if (d->tables[0]
                        .values[38] != -3) ++bad;
                    if (d->tables[0]
                        .values[39] != -1) ++bad;
                    if (d->tables[0]
                        .values[40] != 0) ++bad;
                    if (d->tables[0]
                        .values[41] != 1) ++bad;
                    if (d->tables[0]
                        .values[42] != -2) ++bad;
                    if (d->tables[0]
                        .values[43] != -1) ++bad;
                    if (d->tables[0]
                        .values[44] != -1) ++bad;
                    if (d->tables[0]
                        .values[45] != 0) ++bad;
                    if (d->tables[0]
                        .values[46] != 0) ++bad;
                    if (d->tables[0]
                        .values[47] != 1) ++bad;
                    if (d->tables[0]
                        .values[48] != 2) ++bad;
                    if (d->tables[0]
                        .values[49] != -7) ++bad;
                    if (d->tables[0]
                        .values[50] != -6) ++bad;
                    if (d->tables[0]
                        .values[51] != -5) ++bad;
                    if (d->tables[0]
                        .values[52] != -4) ++bad;
                    if (d->tables[0]
                        .values[53] != -1) ++bad;
                    if (d->tables[0]
                        .values[54] != 0) ++bad;
                    if (d->tables[0]
                        .values[55] != 0) ++bad;
                    if (d->tables[0]
                        .values[56] != -9) ++bad;
                    if (d->tables[0]
                        .values[57] != -8) ++bad;
                    if (d->tables[0]
                        .values[58] != -7) ++bad;
                    if (d->tables[0]
                        .values[59] != -5) ++bad;
                    if (d->tables[0]
                        .values[60] != -3) ++bad;
                    if (d->tables[0]
                        .values[61] != -2) ++bad;
                    if (d->tables[0]
                        .values[62] != -1) ++bad;
                    if (d->tables[0]
                        .values[63] != -6) ++bad;
                    if (d->tables[0]
                        .values[64] != -4) ++bad;
                    if (d->tables[0]
                        .values[65] != -2) ++bad;
                    if (d->tables[0]
                        .values[66] != -1) ++bad;
                    if (d->tables[0]
                        .values[67] != 0) ++bad;
                    if (d->tables[0]
                        .values[68] != 0) ++bad;
                    if (d->tables[0]
                        .values[69] != 0) ++bad;
                    if (d->tables[0]
                        .values[70] != -2) ++bad;
                    if (d->tables[0]
                        .values[71] != -1) ++bad;
                    if (d->tables[0]
                        .values[72] != -1) ++bad;
                    if (d->tables[0]
                        .values[73] != 0) ++bad;
                    if (d->tables[0]
                        .values[74] != 1) ++bad;
                    if (d->tables[0]
                        .values[75] != 2) ++bad;
                    if (d->tables[0]
                        .values[76] != 3) ++bad;
                    if (d->tables[0]
                        .values[77] != -3) ++bad;
                    if (d->tables[0]
                        .values[78] != -2) ++bad;
                    if (d->tables[0]
                        .values[79] != -2) ++bad;
                    if (d->tables[0]
                        .values[80] != -1) ++bad;
                    if (d->tables[0]
                        .values[81] != 0) ++bad;
                    if (d->tables[0]
                        .values[82] != 0) ++bad;
                    if (d->tables[0]
                        .values[83] != 1) ++bad;
                    if (d->tables[0]
                        .values[84] != -7) ++bad;
                    if (d->tables[0]
                        .values[85] != -6) ++bad;
                    if (d->tables[0]
                        .values[86] != -5) ++bad;
                    if (d->tables[0]
                        .values[87] != -4) ++bad;
                    if (d->tables[0]
                        .values[88] != -3) ++bad;
                    if (d->tables[0]
                        .values[89] != -2) ++bad;
                    if (d->tables[0]
                        .values[90] != -1) ++bad;
                    if (d->tables[0]
                        .values[91] != -7) ++bad;
                    if (d->tables[0]
                        .values[92] != -6) ++bad;
                    if (d->tables[0]
                        .values[93] != -5) ++bad;
                    if (d->tables[0]
                        .values[94] != -4) ++bad;
                    if (d->tables[0]
                        .values[95] != -3) ++bad;
                    if (d->tables[0]
                        .values[96] != -2) ++bad;
                    if (d->tables[0]
                        .values[97] != -1) ++bad;
                    if (d->tables[0]
                        .values[98] != -4) ++bad;
                    if (d->tables[0]
                        .values[99] != -3) ++bad;
                    if (d->tables[0]
                        .values[100] != -2) ++bad;
                    if (d->tables[0]
                        .values[101] != -1) ++bad;
                    if (d->tables[0]
                        .values[102] != 0) ++bad;
                    if (d->tables[0]
                        .values[103] != 0) ++bad;
                    if (d->tables[0]
                        .values[104] != 0) ++bad;
                    if (d->tables[0]
                        .values[105] != -6) ++bad;
                    if (d->tables[0]
                        .values[106] != -5) ++bad;
                    if (d->tables[0]
                        .values[107] != -4) ++bad;
                    if (d->tables[0]
                        .values[108] != -3) ++bad;
                    if (d->tables[0]
                        .values[109] != -2) ++bad;
                    if (d->tables[0]
                        .values[110] != -1) ++bad;
                    if (d->tables[0]
                        .values[111] != 0) ++bad;
                    if (d->tables[0]
                        .values[112] != -7) ++bad;
                    if (d->tables[0]
                        .values[113] != -6) ++bad;
                    if (d->tables[0]
                        .values[114] != -5) ++bad;
                    if (d->tables[0]
                        .values[115] != -4) ++bad;
                    if (d->tables[0]
                        .values[116] != -3) ++bad;
                    if (d->tables[0]
                        .values[117] != -2) ++bad;
                    if (d->tables[0]
                        .values[118] != -1) ++bad;
                    if (d->tables[0]
                        .values[119] != -8) ++bad;
                    if (d->tables[0]
                        .values[120] != -7) ++bad;
                    if (d->tables[0]
                        .values[121] != -6) ++bad;
                    if (d->tables[0]
                        .values[122] != -5) ++bad;
                    if (d->tables[0]
                        .values[123] != -4) ++bad;
                    if (d->tables[0]
                        .values[124] != -3) ++bad;
                    if (d->tables[0]
                        .values[125] != -2) ++bad;
                    if (d->tables[0]
                        .values[126] != 9) ++bad;
                    if (d->tables[0]
                        .values[127] != 8) ++bad;
                    if (d->tables[0]
                        .values[128] != 7) ++bad;
                    if (d->tables[0]
                        .values[129] != 6) ++bad;
                    if (d->tables[0]
                        .values[130] != 5) ++bad;
                    if (d->tables[0]
                        .values[131] != 4) ++bad;
                    if (d->tables[0]
                        .values[132] != 3) ++bad;
                    if (d->tables[0]
                        .values[133] != -3) ++bad;
                    if (d->tables[0]
                        .values[134] != -3) ++bad;
                    if (d->tables[0]
                        .values[135] != -2) ++bad;
                    if (d->tables[0]
                        .values[136] != -2) ++bad;
                    if (d->tables[0]
                        .values[137] != -1) ++bad;
                    if (d->tables[0]
                        .values[138] != 0) ++bad;
                    if (d->tables[0]
                        .values[139] != 0) ++bad;
                    if (d->tables[0]
                        .values[140] != -7) ++bad;
                    if (d->tables[0]
                        .values[141] != -6) ++bad;
                    if (d->tables[0]
                        .values[142] != -5) ++bad;
                    if (d->tables[0]
                        .values[143] != -4) ++bad;
                    if (d->tables[0]
                        .values[144] != -2) ++bad;
                    if (d->tables[0]
                        .values[145] != -1) ++bad;
                    if (d->tables[0]
                        .values[146] != 0) ++bad;
                    if (d->tables[0]
                        .values[147] != -4) ++bad;
                    if (d->tables[0]
                        .values[148] != -4) ++bad;
                    if (d->tables[0]
                        .values[149] != -3) ++bad;
                    if (d->tables[0]
                        .values[150] != -3) ++bad;
                    if (d->tables[0]
                        .values[151] != -2) ++bad;
                    if (d->tables[0]
                        .values[152] != -2) ++bad;
                    if (d->tables[0]
                        .values[153] != -1) ++bad;
                    if (d->tables[0]
                        .values[154] != -5) ++bad;
                    if (d->tables[0]
                        .values[155] != -4) ++bad;
                    if (d->tables[0]
                        .values[156] != -3) ++bad;
                    if (d->tables[0]
                        .values[157] != -2) ++bad;
                    if (d->tables[0]
                        .values[158] != -1) ++bad;
                    if (d->tables[0]
                        .values[159] != 0) ++bad;
                    if (d->tables[0]
                        .values[160] != 0) ++bad;
                    if (d->tables[0]
                        .values[161] != -6) ++bad;
                    if (d->tables[0]
                        .values[162] != -5) ++bad;
                    if (d->tables[0]
                        .values[163] != -4) ++bad;
                    if (d->tables[0]
                        .values[164] != -3) ++bad;
                    if (d->tables[0]
                        .values[165] != -2) ++bad;
                    if (d->tables[0]
                        .values[166] != -1) ++bad;
                    if (d->tables[0]
                        .values[167] != 0) ++bad;
                    if (d->tables[1]
                        .values[0] != -1) ++bad;
                    if (d->tables[1]
                        .values[1] != 0) ++bad;
                    if (d->tables[1]
                        .values[2] != 0) ++bad;
                    if (d->tables[1]
                        .values[3] != 0) ++bad;
                    if (d->tables[1]
                        .values[4] != 0) ++bad;
                    if (d->tables[1]
                        .values[5] != 1) ++bad;
                    if (d->tables[1]
                        .values[6] != 1) ++bad;
                    if (d->tables[1]
                        .values[7] != 2) ++bad;
                    if (d->tables[1]
                        .values[8] != 0) ++bad;
                    if (d->tables[1]
                        .values[9] != 0) ++bad;
                    if (d->tables[1]
                        .values[10] != 0) ++bad;
                    if (d->tables[1]
                        .values[11] != 1) ++bad;
                    if (d->tables[1]
                        .values[12] != -1) ++bad;
                    if (d->tables[1]
                        .values[13] != -1) ++bad;
                    if (d->tables[1]
                        .values[14] != 1) ++bad;
                    if (d->tables[1]
                        .values[15] != 2) ++bad;
                    if (d->tables[1]
                        .values[16] != 2) ++bad;
                    if (d->tables[1]
                        .values[17] != 2) ++bad;
                    if (d->tables[1]
                        .values[18] != 3) ++bad;
                    if (d->tables[1]
                        .values[19] != 3) ++bad;
                    if (d->tables[1]
                        .values[20] != 2) ++bad;
                    if (d->tables[1]
                        .values[21] != 2) ++bad;
                    if (d->tables[1]
                        .values[22] != 2) ++bad;
                    if (d->tables[1]
                        .values[23] != 3) ++bad;
                    if (d->tables[1]
                        .values[24] != 3) ++bad;
                    if (d->tables[1]
                        .values[25] != 3) ++bad;
                    if (d->tables[1]
                        .values[26] != 3) ++bad;
                    if (d->tables[1]
                        .values[27] != 3) ++bad;
                    if (d->tables[1]
                        .values[28] != 1) ++bad;
                    if (d->tables[1]
                        .values[29] != 2) ++bad;
                    if (d->tables[1]
                        .values[30] != 2) ++bad;
                    if (d->tables[1]
                        .values[31] != 2) ++bad;
                    if (d->tables[1]
                        .values[32] != -1) ++bad;
                    if (d->tables[1]
                        .values[33] != -1) ++bad;
                    if (d->tables[1]
                        .values[34] != 0) ++bad;
                    if (d->tables[1]
                        .values[35] != 0) ++bad;
                    if (d->tables[1]
                        .values[36] != 1) ++bad;
                    if (d->tables[1]
                        .values[37] != 2) ++bad;
                    if (d->tables[1]
                        .values[38] != 2) ++bad;
                    if (d->tables[1]
                        .values[39] != 3) ++bad;
                    if (d->tables[1]
                        .values[40] != 3) ++bad;
                    if (d->tables[1]
                        .values[41] != 4) ++bad;
                    if (d->tables[1]
                        .values[42] != 4) ++bad;
                    if (d->tables[1]
                        .values[43] != 4) ++bad;
                    if (d->tables[1]
                        .values[44] != 2) ++bad;
                    if (d->tables[1]
                        .values[45] != 3) ++bad;
                    if (d->tables[1]
                        .values[46] != 3) ++bad;
                    if (d->tables[1]
                        .values[47] != 3) ++bad;
                    if (d->tables[1]
                        .values[48] != -1) ++bad;
                    if (d->tables[1]
                        .values[49] != 0) ++bad;
                    if (d->tables[1]
                        .values[50] != 0) ++bad;
                    if (d->tables[1]
                        .values[51] != 1) ++bad;
                    if (d->tables[1]
                        .values[52] != 0) ++bad;
                    if (d->tables[1]
                        .values[53] != 1) ++bad;
                    if (d->tables[1]
                        .values[54] != 0) ++bad;
                    if (d->tables[1]
                        .values[55] != 1) ++bad;
                    if (d->tables[1]
                        .values[56] != 0) ++bad;
                    if (d->tables[1]
                        .values[57] != 0) ++bad;
                    if (d->tables[1]
                        .values[58] != 0) ++bad;
                    if (d->tables[1]
                        .values[59] != 1) ++bad;
                    if (d->tables[1]
                        .values[60] != 0) ++bad;
                    if (d->tables[1]
                        .values[61] != 0) ++bad;
                    if (d->tables[1]
                        .values[62] != 0) ++bad;
                    if (d->tables[1]
                        .values[63] != 1) ++bad;
                    if (d->tables[1]
                        .values[64] != 0) ++bad;
                    if (d->tables[1]
                        .values[65] != 1) ++bad;
                    if (d->tables[1]
                        .values[66] != 0) ++bad;
                    if (d->tables[1]
                        .values[67] != 1) ++bad;
                    if (d->tables[1]
                        .values[68] != -1) ++bad;
                    if (d->tables[1]
                        .values[69] != 0) ++bad;
                    if (d->tables[1]
                        .values[70] != 0) ++bad;
                    if (d->tables[1]
                        .values[71] != 1) ++bad;
                    if (d->tables[1]
                        .values[72] != 2) ++bad;
                    if (d->tables[1]
                        .values[73] != 1) ++bad;
                    if (d->tables[1]
                        .values[74] != 0) ++bad;
                    if (d->tables[1]
                        .values[75] != -1) ++bad;
                    if (d->tables[1]
                        .values[76] != 0) ++bad;
                    if (d->tables[1]
                        .values[77] != 2) ++bad;
                    if (d->tables[1]
                        .values[78] != 1) ++bad;
                    if (d->tables[1]
                        .values[79] != 3) ++bad;
                    if (d->tables[1]
                        .values[80] != 0) ++bad;
                    if (d->tables[1]
                        .values[81] != 2) ++bad;
                    if (d->tables[1]
                        .values[82] != 1) ++bad;
                    if (d->tables[1]
                        .values[83] != 3) ++bad;
                    if (d->tables[1]
                        .values[84] != 0) ++bad;
                    if (d->tables[1]
                        .values[85] != 0) ++bad;
                    if (d->tables[1]
                        .values[86] != 0) ++bad;
                    if (d->tables[1]
                        .values[87] != 0) ++bad;
                    if (d->tables[1]
                        .values[88] != 0) ++bad;
                    if (d->tables[1]
                        .values[89] != 0) ++bad;
                    if (d->tables[1]
                        .values[90] != 0) ++bad;
                    if (d->tables[1]
                        .values[91] != 0) ++bad;
                    if (d->tables[1]
                        .values[92] != 0) ++bad;
                    if (d->tables[1]
                        .values[93] != 0) ++bad;
                    if (d->tables[1]
                        .values[94] != 0) ++bad;
                    if (d->tables[1]
                        .values[95] != 0) ++bad;
                    if (d->tables[2]
                        .values[0] != 1) ++bad;
                    if (d->tables[2]
                        .values[1] != 1) ++bad;
                    if (d->tables[2]
                        .values[2] != 0) ++bad;
                    if (d->tables[2]
                        .values[3] != 1) ++bad;
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
                        .values[15] != 1) ++bad;
                    if (d->tables[2]
                        .values[16] != 0) ++bad;
                    if (d->tables[2]
                        .values[17] != 1) ++bad;
                    if (d->tables[2]
                        .values[18] != 1) ++bad;
                    if (d->tables[2]
                        .values[19] != 0) ++bad;
                    if (d->tables[2]
                        .values[20] != 0) ++bad;
                    if (d->tables[2]
                        .values[21] != 0) ++bad;
                    if (d->tables[2]
                        .values[22] != 1) ++bad;
                    if (d->tables[2]
                        .values[23] != 1) ++bad;
                    if (d->tables[3]
                        .values[0] != -1) ++bad;
                    if (d->tables[3]
                        .values[1] != 9) ++bad;
                    if (d->tables[3]
                        .values[2] != 3) ++bad;
                    if (d->tables[3]
                        .values[3] != 3) ++bad;
                    if (d->tables[3]
                        .values[4] != 21) ++bad;
                    if (d->tables[3]
                        .values[5] != 18) ++bad;
                    if (d->tables[3]
                        .values[6] != 21) ++bad;
                    if (d->tables[3]
                        .values[7] != 15) ++bad;
                    if (d->tables[3]
                        .values[8] != 3) ++bad;
                    if (d->tables[3]
                        .values[9] != 6) ++bad;
                    if (d->tables[3]
                        .values[10] != 24) ++bad;
                    if (d->tables[3]
                        .values[11] != 18) ++bad;
                    if (d->tables[3]
                        .values[12] != 3) ++bad;
                    if (d->tables[3]
                        .values[13] != -1) ++bad;
                    if (d->tables[3]
                        .values[14] != 3) ++bad;
                    if (d->tables[3]
                        .values[15] != 3) ++bad;
                    if (d->tables[3]
                        .values[16] != 6) ++bad;
                    if (d->tables[3]
                        .values[17] != 3) ++bad;
                    if (d->tables[3]
                        .values[18] != 3) ++bad;
                    if (d->tables[3]
                        .values[19] != 20) ++bad;
                    if (d->tables[3]
                        .values[20] != 16) ++bad;
                    if (d->tables[3]
                        .values[21] != 3) ++bad;
                    if (d->tables[3]
                        .values[22] != 9) ++bad;
                    if (d->tables[3]
                        .values[23] != 9) ++bad;
                    if (std::string(rules::uamtName(0))
                        != "Aklys (hurled)") ++bad;
                    if (std::string(rules::uamtName(1))
                        != "Atlatl (javelin)") ++bad;
                    if (std::string(rules::uamtName(2))
                        != "Axe, Hand") ++bad;
                    if (std::string(rules::uamtName(3))
                        != "Blowgun Needle") ++bad;
                    if (std::string(rules::uamtName(4))
                        != "Bow, Composite, Long") ++bad;
                    if (std::string(rules::uamtName(5))
                        != "Bow, Composite, Short") ++bad;
                    if (std::string(rules::uamtName(6))
                        != "Bow, Long") ++bad;
                    if (std::string(rules::uamtName(7))
                        != "Bow, Short") ++bad;
                    if (std::string(rules::uamtName(8))
                        != "Club") ++bad;
                    if (std::string(rules::uamtName(9))
                        != "Crossbow, Hand") ++bad;
                    if (std::string(rules::uamtName(10))
                        != "Crossbow, Heavy") ++bad;
                    if (std::string(rules::uamtName(11))
                        != "Crossbow, Light") ++bad;
                    if (std::string(rules::uamtName(12))
                        != "Dagger") ++bad;
                    if (std::string(rules::uamtName(13))
                        != "Dart") ++bad;
                    if (std::string(rules::uamtName(14))
                        != "Hammer") ++bad;
                    if (std::string(rules::uamtName(15))
                        != "Harpoon") ++bad;
                    if (std::string(rules::uamtName(16))
                        != "Javelin") ++bad;
                    if (std::string(rules::uamtName(17))
                        != "Knife") ++bad;
                    if (std::string(rules::uamtName(18))
                        != "Lasso") ++bad;
                    if (std::string(rules::uamtName(19))
                        != "Sling (bullet)") ++bad;
                    if (std::string(rules::uamtName(20))
                        != "Sling (stone)") ++bad;
                    if (std::string(rules::uamtName(21))
                        != "Spear") ++bad;
                    if (std::string(rules::uamtName(22))
                        != "Staff Sling (bullet)") ++bad;
                    if (std::string(rules::uamtName(23))
                        != "Staff Sling (stone)") ++bad;
                    if (rules::uamtIsNewWeapon(0) != 1) ++bad;
                    if (rules::uamtIsNewWeapon(1) != 1) ++bad;
                    if (rules::uamtIsNewWeapon(2) != 0) ++bad;
                    if (rules::uamtIsNewWeapon(3) != 1) ++bad;
                    if (rules::uamtIsNewWeapon(4) != 0) ++bad;
                    if (rules::uamtIsNewWeapon(5) != 0) ++bad;
                    if (rules::uamtIsNewWeapon(6) != 0) ++bad;
                    if (rules::uamtIsNewWeapon(7) != 0) ++bad;
                    if (rules::uamtIsNewWeapon(8) != 0) ++bad;
                    if (rules::uamtIsNewWeapon(9) != 0) ++bad;
                    if (rules::uamtIsNewWeapon(10) != 0) ++bad;
                    if (rules::uamtIsNewWeapon(11) != 0) ++bad;
                    if (rules::uamtIsNewWeapon(12) != 0) ++bad;
                    if (rules::uamtIsNewWeapon(13) != 0) ++bad;
                    if (rules::uamtIsNewWeapon(14) != 0) ++bad;
                    if (rules::uamtIsNewWeapon(15) != 1) ++bad;
                    if (rules::uamtIsNewWeapon(16) != 0) ++bad;
                    if (rules::uamtIsNewWeapon(17) != 1) ++bad;
                    if (rules::uamtIsNewWeapon(18) != 1) ++bad;
                    if (rules::uamtIsNewWeapon(19) != 0) ++bad;
                    if (rules::uamtIsNewWeapon(20) != 0) ++bad;
                    if (rules::uamtIsNewWeapon(21) != 0) ++bad;
                    if (rules::uamtIsNewWeapon(22) != 1) ++bad;
                    if (rules::uamtIsNewWeapon(23) != 1) ++bad;
                    if (rules::uamtRangePrinted(0) != -1) ++bad;
                    if (rules::uamtRangePrinted(1) != 9) ++bad;
                    if (rules::uamtRangePrinted(2) != 3) ++bad;
                    if (rules::uamtRangePrinted(3) != 3) ++bad;
                    if (rules::uamtRangePrinted(4) != 21) ++bad;
                    if (rules::uamtRangePrinted(5) != 18) ++bad;
                    if (rules::uamtRangePrinted(6) != 21) ++bad;
                    if (rules::uamtRangePrinted(7) != 15) ++bad;
                    if (rules::uamtRangePrinted(8) != 3) ++bad;
                    if (rules::uamtRangePrinted(9) != 6) ++bad;
                    if (rules::uamtRangePrinted(10) != 24) ++bad;
                    if (rules::uamtRangePrinted(11) != 18) ++bad;
                    if (rules::uamtRangePrinted(12) != 3) ++bad;
                    if (rules::uamtRangePrinted(13) != -1) ++bad;
                    if (rules::uamtRangePrinted(14) != 3) ++bad;
                    if (rules::uamtRangePrinted(15) != 3) ++bad;
                    if (rules::uamtRangePrinted(16) != 6) ++bad;
                    if (rules::uamtRangePrinted(17) != 3) ++bad;
                    if (rules::uamtRangePrinted(18) != 3) ++bad;
                    if (rules::uamtRangePrinted(19) != 20) ++bad;
                    if (rules::uamtRangePrinted(20) != 16) ++bad;
                    if (rules::uamtRangePrinted(21) != 3) ++bad;
                    if (rules::uamtRangePrinted(22) != 9) ++bad;
                    if (rules::uamtRangePrinted(23) != 9) ++bad;
                    if (rules::uamtAcAdjustment(0, 0) != -8)
                        ++bad;
                    if (rules::uamtAcAdjustment(0, 6) != -2)
                        ++bad;
                    if (rules::uamtAcAdjustment(23, 0) != -6)
                        ++bad;
                    if (rules::uamtAcAdjustment(23, 6) != 0)
                        ++bad;
                    if (rules::uamtAcAdjustmentHigh(0, 0) != -1)
                        ++bad;
                    if (rules::uamtAcAdjustmentHigh(0, 3) != 0)
                        ++bad;
                    if (rules::uamtAcAdjustmentHigh(23, 0) != 0)
                        ++bad;
                    if (rules::uamtAcAdjustmentHigh(23, 3) != 0)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("uamt_rof");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uamtRateOfFire(0))
                        != "1") ++bad;
                    if (std::string(rules::uamtRateOfFire(1))
                        != "1") ++bad;
                    if (std::string(rules::uamtRateOfFire(2))
                        != "1") ++bad;
                    if (std::string(rules::uamtRateOfFire(3))
                        != "2") ++bad;
                    if (std::string(rules::uamtRateOfFire(4))
                        != "2") ++bad;
                    if (std::string(rules::uamtRateOfFire(5))
                        != "2") ++bad;
                    if (std::string(rules::uamtRateOfFire(6))
                        != "2") ++bad;
                    if (std::string(rules::uamtRateOfFire(7))
                        != "2") ++bad;
                    if (std::string(rules::uamtRateOfFire(8))
                        != "1") ++bad;
                    if (std::string(rules::uamtRateOfFire(9))
                        != "1") ++bad;
                    if (std::string(rules::uamtRateOfFire(10))
                        != "1/2") ++bad;
                    if (std::string(rules::uamtRateOfFire(11))
                        != "1") ++bad;
                    if (std::string(rules::uamtRateOfFire(12))
                        != "2") ++bad;
                    if (std::string(rules::uamtRateOfFire(13))
                        != "3") ++bad;
                    if (std::string(rules::uamtRateOfFire(14))
                        != "1") ++bad;
                    if (std::string(rules::uamtRateOfFire(15))
                        != "1") ++bad;
                    if (std::string(rules::uamtRateOfFire(16))
                        != "1") ++bad;
                    if (std::string(rules::uamtRateOfFire(17))
                        != "2") ++bad;
                    if (std::string(rules::uamtRateOfFire(18))
                        != "1/2") ++bad;
                    if (std::string(rules::uamtRateOfFire(19))
                        != "1") ++bad;
                    if (std::string(rules::uamtRateOfFire(20))
                        != "1") ++bad;
                    if (std::string(rules::uamtRateOfFire(21))
                        != "1") ++bad;
                    if (std::string(rules::uamtRateOfFire(22))
                        != "1/2") ++bad;
                    if (std::string(rules::uamtRateOfFire(23))
                        != "1/2") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("uamt_range_s");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uamtRangeShort(0))
                        != "1*") ++bad;
                    if (std::string(rules::uamtRangeShort(1))
                        != "3") ++bad;
                    if (std::string(rules::uamtRangeShort(2))
                        != "1") ++bad;
                    if (std::string(rules::uamtRangeShort(3))
                        != "1") ++bad;
                    if (std::string(rules::uamtRangeShort(4))
                        != "6") ++bad;
                    if (std::string(rules::uamtRangeShort(5))
                        != "5") ++bad;
                    if (std::string(rules::uamtRangeShort(6))
                        != "7") ++bad;
                    if (std::string(rules::uamtRangeShort(7))
                        != "5") ++bad;
                    if (std::string(rules::uamtRangeShort(8))
                        != "1") ++bad;
                    if (std::string(rules::uamtRangeShort(9))
                        != "2") ++bad;
                    if (std::string(rules::uamtRangeShort(10))
                        != "8") ++bad;
                    if (std::string(rules::uamtRangeShort(11))
                        != "6") ++bad;
                    if (std::string(rules::uamtRangeShort(12))
                        != "1") ++bad;
                    if (std::string(rules::uamtRangeShort(13))
                        != "1 1/2") ++bad;
                    if (std::string(rules::uamtRangeShort(14))
                        != "1") ++bad;
                    if (std::string(rules::uamtRangeShort(15))
                        != "1") ++bad;
                    if (std::string(rules::uamtRangeShort(16))
                        != "2") ++bad;
                    if (std::string(rules::uamtRangeShort(17))
                        != "1") ++bad;
                    if (std::string(rules::uamtRangeShort(18))
                        != "1") ++bad;
                    if (std::string(rules::uamtRangeShort(19))
                        != "5") ++bad;
                    if (std::string(rules::uamtRangeShort(20))
                        != "4") ++bad;
                    if (std::string(rules::uamtRangeShort(21))
                        != "1") ++bad;
                    if (std::string(rules::uamtRangeShort(22))
                        != "-") ++bad;
                    if (std::string(rules::uamtRangeShort(23))
                        != "-") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("uamt_range_m");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uamtRangeMedium(0))
                        != "-") ++bad;
                    if (std::string(rules::uamtRangeMedium(1))
                        != "6") ++bad;
                    if (std::string(rules::uamtRangeMedium(2))
                        != "2") ++bad;
                    if (std::string(rules::uamtRangeMedium(3))
                        != "2") ++bad;
                    if (std::string(rules::uamtRangeMedium(4))
                        != "12") ++bad;
                    if (std::string(rules::uamtRangeMedium(5))
                        != "10") ++bad;
                    if (std::string(rules::uamtRangeMedium(6))
                        != "14") ++bad;
                    if (std::string(rules::uamtRangeMedium(7))
                        != "10") ++bad;
                    if (std::string(rules::uamtRangeMedium(8))
                        != "2") ++bad;
                    if (std::string(rules::uamtRangeMedium(9))
                        != "4") ++bad;
                    if (std::string(rules::uamtRangeMedium(10))
                        != "16") ++bad;
                    if (std::string(rules::uamtRangeMedium(11))
                        != "12") ++bad;
                    if (std::string(rules::uamtRangeMedium(12))
                        != "2") ++bad;
                    if (std::string(rules::uamtRangeMedium(13))
                        != "3") ++bad;
                    if (std::string(rules::uamtRangeMedium(14))
                        != "2") ++bad;
                    if (std::string(rules::uamtRangeMedium(15))
                        != "2") ++bad;
                    if (std::string(rules::uamtRangeMedium(16))
                        != "4") ++bad;
                    if (std::string(rules::uamtRangeMedium(17))
                        != "2") ++bad;
                    if (std::string(rules::uamtRangeMedium(18))
                        != "2") ++bad;
                    if (std::string(rules::uamtRangeMedium(19))
                        != "10") ++bad;
                    if (std::string(rules::uamtRangeMedium(20))
                        != "8") ++bad;
                    if (std::string(rules::uamtRangeMedium(21))
                        != "2") ++bad;
                    if (std::string(rules::uamtRangeMedium(22))
                        != "3-6") ++bad;
                    if (std::string(rules::uamtRangeMedium(23))
                        != "3-6") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("uamt_range_l");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uamtRangeLong(0))
                        != "-") ++bad;
                    if (std::string(rules::uamtRangeLong(1))
                        != "9") ++bad;
                    if (std::string(rules::uamtRangeLong(2))
                        != "3") ++bad;
                    if (std::string(rules::uamtRangeLong(3))
                        != "3") ++bad;
                    if (std::string(rules::uamtRangeLong(4))
                        != "21") ++bad;
                    if (std::string(rules::uamtRangeLong(5))
                        != "18") ++bad;
                    if (std::string(rules::uamtRangeLong(6))
                        != "21") ++bad;
                    if (std::string(rules::uamtRangeLong(7))
                        != "15") ++bad;
                    if (std::string(rules::uamtRangeLong(8))
                        != "3") ++bad;
                    if (std::string(rules::uamtRangeLong(9))
                        != "6") ++bad;
                    if (std::string(rules::uamtRangeLong(10))
                        != "24") ++bad;
                    if (std::string(rules::uamtRangeLong(11))
                        != "18") ++bad;
                    if (std::string(rules::uamtRangeLong(12))
                        != "3") ++bad;
                    if (std::string(rules::uamtRangeLong(13))
                        != "4 1/2") ++bad;
                    if (std::string(rules::uamtRangeLong(14))
                        != "3") ++bad;
                    if (std::string(rules::uamtRangeLong(15))
                        != "3") ++bad;
                    if (std::string(rules::uamtRangeLong(16))
                        != "6") ++bad;
                    if (std::string(rules::uamtRangeLong(17))
                        != "3") ++bad;
                    if (std::string(rules::uamtRangeLong(18))
                        != "3") ++bad;
                    if (std::string(rules::uamtRangeLong(19))
                        != "20") ++bad;
                    if (std::string(rules::uamtRangeLong(20))
                        != "16") ++bad;
                    if (std::string(rules::uamtRangeLong(21))
                        != "3") ++bad;
                    if (std::string(rules::uamtRangeLong(22))
                        != "9") ++bad;
                    if (std::string(rules::uamtRangeLong(23))
                        != "9") ++bad;
                }
            }
        }
        printf("R1058 weapons registry defs-A audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 4. B -----------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/weapondata");
            {
                const items::MiscItemDef* d =
                    reg.find("uahh");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != -7) ++bad;
                    if (d->tables[0]
                        .values[1] != -6) ++bad;
                    if (d->tables[0]
                        .values[2] != -5) ++bad;
                    if (d->tables[0]
                        .values[3] != -4) ++bad;
                    if (d->tables[0]
                        .values[4] != -3) ++bad;
                    if (d->tables[0]
                        .values[5] != -2) ++bad;
                    if (d->tables[0]
                        .values[6] != -1) ++bad;
                    if (d->tables[0]
                        .values[7] != -1) ++bad;
                    if (d->tables[0]
                        .values[8] != 0) ++bad;
                    if (d->tables[0]
                        .values[9] != 0) ++bad;
                    if (d->tables[0]
                        .values[10] != 1) ++bad;
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
                        .values[22] != -5) ++bad;
                    if (d->tables[0]
                        .values[23] != -4) ++bad;
                    if (d->tables[0]
                        .values[24] != -3) ++bad;
                    if (d->tables[0]
                        .values[25] != -2) ++bad;
                    if (d->tables[0]
                        .values[26] != -1) ++bad;
                    if (d->tables[0]
                        .values[27] != -1) ++bad;
                    if (d->tables[0]
                        .values[28] != 0) ++bad;
                    if (d->tables[0]
                        .values[29] != 0) ++bad;
                    if (d->tables[0]
                        .values[30] != 1) ++bad;
                    if (d->tables[0]
                        .values[31] != 1) ++bad;
                    if (d->tables[0]
                        .values[32] != 2) ++bad;
                    if (d->tables[0]
                        .values[33] != -5) ++bad;
                    if (d->tables[0]
                        .values[34] != -4) ++bad;
                    if (d->tables[0]
                        .values[35] != -3) ++bad;
                    if (d->tables[0]
                        .values[36] != -2) ++bad;
                    if (d->tables[0]
                        .values[37] != -2) ++bad;
                    if (d->tables[0]
                        .values[38] != -1) ++bad;
                    if (d->tables[0]
                        .values[39] != 0) ++bad;
                    if (d->tables[0]
                        .values[40] != 0) ++bad;
                    if (d->tables[0]
                        .values[41] != 1) ++bad;
                    if (d->tables[0]
                        .values[42] != 1) ++bad;
                    if (d->tables[0]
                        .values[43] != 1) ++bad;
                    if (d->tables[0]
                        .values[44] != -3) ++bad;
                    if (d->tables[0]
                        .values[45] != -2) ++bad;
                    if (d->tables[0]
                        .values[46] != -2) ++bad;
                    if (d->tables[0]
                        .values[47] != -1) ++bad;
                    if (d->tables[0]
                        .values[48] != 0) ++bad;
                    if (d->tables[0]
                        .values[49] != 0) ++bad;
                    if (d->tables[0]
                        .values[50] != 1) ++bad;
                    if (d->tables[0]
                        .values[51] != 1) ++bad;
                    if (d->tables[0]
                        .values[52] != 2) ++bad;
                    if (d->tables[0]
                        .values[53] != 2) ++bad;
                    if (d->tables[0]
                        .values[54] != 3) ++bad;
                    if (d->tables[0]
                        .values[55] != 2) ++bad;
                    if (d->tables[0]
                        .values[56] != 2) ++bad;
                    if (d->tables[0]
                        .values[57] != 2) ++bad;
                    if (d->tables[0]
                        .values[58] != 2) ++bad;
                    if (d->tables[0]
                        .values[59] != 2) ++bad;
                    if (d->tables[0]
                        .values[60] != 0) ++bad;
                    if (d->tables[0]
                        .values[61] != 0) ++bad;
                    if (d->tables[0]
                        .values[62] != 0) ++bad;
                    if (d->tables[0]
                        .values[63] != 0) ++bad;
                    if (d->tables[0]
                        .values[64] != 0) ++bad;
                    if (d->tables[0]
                        .values[65] != -1) ++bad;
                    if (d->tables[0]
                        .values[66] != 0) ++bad;
                    if (d->tables[0]
                        .values[67] != 0) ++bad;
                    if (d->tables[0]
                        .values[68] != 0) ++bad;
                    if (d->tables[0]
                        .values[69] != 0) ++bad;
                    if (d->tables[0]
                        .values[70] != 0) ++bad;
                    if (d->tables[0]
                        .values[71] != 0) ++bad;
                    if (d->tables[0]
                        .values[72] != 0) ++bad;
                    if (d->tables[0]
                        .values[73] != 0) ++bad;
                    if (d->tables[0]
                        .values[74] != 1) ++bad;
                    if (d->tables[0]
                        .values[75] != 0) ++bad;
                    if (d->tables[0]
                        .values[76] != 0) ++bad;
                    if (d->tables[0]
                        .values[77] != 0) ++bad;
                    if (d->tables[0]
                        .values[78] != 0) ++bad;
                    if (d->tables[0]
                        .values[79] != 0) ++bad;
                    if (d->tables[0]
                        .values[80] != 0) ++bad;
                    if (d->tables[0]
                        .values[81] != 0) ++bad;
                    if (d->tables[0]
                        .values[82] != 0) ++bad;
                    if (d->tables[0]
                        .values[83] != 0) ++bad;
                    if (d->tables[0]
                        .values[84] != 0) ++bad;
                    if (d->tables[0]
                        .values[85] != 0) ++bad;
                    if (d->tables[0]
                        .values[86] != 0) ++bad;
                    if (d->tables[0]
                        .values[87] != 0) ++bad;
                    if (d->tables[0]
                        .values[88] != -13) ++bad;
                    if (d->tables[0]
                        .values[89] != -11) ++bad;
                    if (d->tables[0]
                        .values[90] != -9) ++bad;
                    if (d->tables[0]
                        .values[91] != -7) ++bad;
                    if (d->tables[0]
                        .values[92] != -5) ++bad;
                    if (d->tables[0]
                        .values[93] != -3) ++bad;
                    if (d->tables[0]
                        .values[94] != -1) ++bad;
                    if (d->tables[0]
                        .values[95] != 0) ++bad;
                    if (d->tables[0]
                        .values[96] != 1) ++bad;
                    if (d->tables[0]
                        .values[97] != 0) ++bad;
                    if (d->tables[0]
                        .values[98] != 3) ++bad;
                    if (d->tables[0]
                        .values[99] != -8) ++bad;
                    if (d->tables[0]
                        .values[100] != -7) ++bad;
                    if (d->tables[0]
                        .values[101] != -6) ++bad;
                    if (d->tables[0]
                        .values[102] != -5) ++bad;
                    if (d->tables[0]
                        .values[103] != -4) ++bad;
                    if (d->tables[0]
                        .values[104] != -3) ++bad;
                    if (d->tables[0]
                        .values[105] != -2) ++bad;
                    if (d->tables[0]
                        .values[106] != -1) ++bad;
                    if (d->tables[0]
                        .values[107] != 0) ++bad;
                    if (d->tables[0]
                        .values[108] != 1) ++bad;
                    if (d->tables[0]
                        .values[109] != 2) ++bad;
                    if (d->tables[0]
                        .values[110] != -7) ++bad;
                    if (d->tables[0]
                        .values[111] != -6) ++bad;
                    if (d->tables[0]
                        .values[112] != -5) ++bad;
                    if (d->tables[0]
                        .values[113] != -4) ++bad;
                    if (d->tables[0]
                        .values[114] != -3) ++bad;
                    if (d->tables[0]
                        .values[115] != -2) ++bad;
                    if (d->tables[0]
                        .values[116] != -1) ++bad;
                    if (d->tables[0]
                        .values[117] != -1) ++bad;
                    if (d->tables[0]
                        .values[118] != 0) ++bad;
                    if (d->tables[0]
                        .values[119] != 0) ++bad;
                    if (d->tables[0]
                        .values[120] != 1) ++bad;
                    if (d->tables[0]
                        .values[121] != -4) ++bad;
                    if (d->tables[0]
                        .values[122] != -4) ++bad;
                    if (d->tables[0]
                        .values[123] != -3) ++bad;
                    if (d->tables[0]
                        .values[124] != -3) ++bad;
                    if (d->tables[0]
                        .values[125] != -2) ++bad;
                    if (d->tables[0]
                        .values[126] != -2) ++bad;
                    if (d->tables[0]
                        .values[127] != 0) ++bad;
                    if (d->tables[0]
                        .values[128] != 0) ++bad;
                    if (d->tables[0]
                        .values[129] != 1) ++bad;
                    if (d->tables[0]
                        .values[130] != 1) ++bad;
                    if (d->tables[0]
                        .values[131] != 3) ++bad;
                    if (d->tables[0]
                        .values[132] != -3) ++bad;
                    if (d->tables[0]
                        .values[133] != -3) ++bad;
                    if (d->tables[0]
                        .values[134] != -2) ++bad;
                    if (d->tables[0]
                        .values[135] != -2) ++bad;
                    if (d->tables[0]
                        .values[136] != -1) ++bad;
                    if (d->tables[0]
                        .values[137] != -1) ++bad;
                    if (d->tables[0]
                        .values[138] != 0) ++bad;
                    if (d->tables[0]
                        .values[139] != 0) ++bad;
                    if (d->tables[0]
                        .values[140] != 0) ++bad;
                    if (d->tables[0]
                        .values[141] != -1) ++bad;
                    if (d->tables[0]
                        .values[142] != -1) ++bad;
                    if (d->tables[0]
                        .values[143] != -2) ++bad;
                    if (d->tables[0]
                        .values[144] != -2) ++bad;
                    if (d->tables[0]
                        .values[145] != -1) ++bad;
                    if (d->tables[0]
                        .values[146] != -1) ++bad;
                    if (d->tables[0]
                        .values[147] != -1) ++bad;
                    if (d->tables[0]
                        .values[148] != 0) ++bad;
                    if (d->tables[0]
                        .values[149] != 0) ++bad;
                    if (d->tables[0]
                        .values[150] != 0) ++bad;
                    if (d->tables[0]
                        .values[151] != 1) ++bad;
                    if (d->tables[0]
                        .values[152] != 0) ++bad;
                    if (d->tables[0]
                        .values[153] != 1) ++bad;
                    if (d->tables[0]
                        .values[154] != -9) ++bad;
                    if (d->tables[0]
                        .values[155] != -8) ++bad;
                    if (d->tables[0]
                        .values[156] != -7) ++bad;
                    if (d->tables[0]
                        .values[157] != -5) ++bad;
                    if (d->tables[0]
                        .values[158] != -3) ++bad;
                    if (d->tables[0]
                        .values[159] != -1) ++bad;
                    if (d->tables[0]
                        .values[160] != 0) ++bad;
                    if (d->tables[0]
                        .values[161] != 0) ++bad;
                    if (d->tables[0]
                        .values[162] != 2) ++bad;
                    if (d->tables[0]
                        .values[163] != 0) ++bad;
                    if (d->tables[0]
                        .values[164] != 4) ++bad;
                    if (d->tables[0]
                        .values[165] != 3) ++bad;
                    if (d->tables[0]
                        .values[166] != 3) ++bad;
                    if (d->tables[0]
                        .values[167] != 2) ++bad;
                    if (d->tables[0]
                        .values[168] != 2) ++bad;
                    if (d->tables[0]
                        .values[169] != 1) ++bad;
                    if (d->tables[0]
                        .values[170] != 2) ++bad;
                    if (d->tables[0]
                        .values[171] != 1) ++bad;
                    if (d->tables[0]
                        .values[172] != 1) ++bad;
                    if (d->tables[0]
                        .values[173] != 1) ++bad;
                    if (d->tables[0]
                        .values[174] != 1) ++bad;
                    if (d->tables[0]
                        .values[175] != -1) ++bad;
                    if (d->tables[0]
                        .values[176] != 0) ++bad;
                    if (d->tables[0]
                        .values[177] != 0) ++bad;
                    if (d->tables[0]
                        .values[178] != 0) ++bad;
                    if (d->tables[0]
                        .values[179] != 0) ++bad;
                    if (d->tables[0]
                        .values[180] != 0) ++bad;
                    if (d->tables[0]
                        .values[181] != 0) ++bad;
                    if (d->tables[0]
                        .values[182] != 0) ++bad;
                    if (d->tables[0]
                        .values[183] != 1) ++bad;
                    if (d->tables[0]
                        .values[184] != 1) ++bad;
                    if (d->tables[0]
                        .values[185] != 1) ++bad;
                    if (d->tables[0]
                        .values[186] != 0) ++bad;
                    if (d->tables[0]
                        .values[187] != -3) ++bad;
                    if (d->tables[0]
                        .values[188] != -3) ++bad;
                    if (d->tables[0]
                        .values[189] != -2) ++bad;
                    if (d->tables[0]
                        .values[190] != -2) ++bad;
                    if (d->tables[0]
                        .values[191] != -1) ++bad;
                    if (d->tables[0]
                        .values[192] != 0) ++bad;
                    if (d->tables[0]
                        .values[193] != 0) ++bad;
                    if (d->tables[0]
                        .values[194] != 1) ++bad;
                    if (d->tables[0]
                        .values[195] != 1) ++bad;
                    if (d->tables[0]
                        .values[196] != 0) ++bad;
                    if (d->tables[0]
                        .values[197] != 1) ++bad;
                    if (d->tables[0]
                        .values[198] != 0) ++bad;
                    if (d->tables[0]
                        .values[199] != 0) ++bad;
                    if (d->tables[0]
                        .values[200] != 0) ++bad;
                    if (d->tables[0]
                        .values[201] != 0) ++bad;
                    if (d->tables[0]
                        .values[202] != 0) ++bad;
                    if (d->tables[0]
                        .values[203] != 0) ++bad;
                    if (d->tables[0]
                        .values[204] != 0) ++bad;
                    if (d->tables[0]
                        .values[205] != 0) ++bad;
                    if (d->tables[0]
                        .values[206] != 0) ++bad;
                    if (d->tables[0]
                        .values[207] != 0) ++bad;
                    if (d->tables[0]
                        .values[208] != 0) ++bad;
                    if (d->tables[0]
                        .values[209] != -2) ++bad;
                    if (d->tables[0]
                        .values[210] != -2) ++bad;
                    if (d->tables[0]
                        .values[211] != -1) ++bad;
                    if (d->tables[0]
                        .values[212] != -1) ++bad;
                    if (d->tables[0]
                        .values[213] != 0) ++bad;
                    if (d->tables[0]
                        .values[214] != 0) ++bad;
                    if (d->tables[0]
                        .values[215] != 0) ++bad;
                    if (d->tables[0]
                        .values[216] != 0) ++bad;
                    if (d->tables[0]
                        .values[217] != 0) ++bad;
                    if (d->tables[0]
                        .values[218] != 0) ++bad;
                    if (d->tables[0]
                        .values[219] != 0) ++bad;
                    if (d->tables[0]
                        .values[220] != -2) ++bad;
                    if (d->tables[0]
                        .values[221] != -2) ++bad;
                    if (d->tables[0]
                        .values[222] != -1) ++bad;
                    if (d->tables[0]
                        .values[223] != -1) ++bad;
                    if (d->tables[0]
                        .values[224] != 0) ++bad;
                    if (d->tables[0]
                        .values[225] != 0) ++bad;
                    if (d->tables[0]
                        .values[226] != 0) ++bad;
                    if (d->tables[0]
                        .values[227] != 0) ++bad;
                    if (d->tables[0]
                        .values[228] != 0) ++bad;
                    if (d->tables[0]
                        .values[229] != 0) ++bad;
                    if (d->tables[0]
                        .values[230] != 0) ++bad;
                    if (d->tables[0]
                        .values[231] != -3) ++bad;
                    if (d->tables[0]
                        .values[232] != -3) ++bad;
                    if (d->tables[0]
                        .values[233] != -2) ++bad;
                    if (d->tables[0]
                        .values[234] != -2) ++bad;
                    if (d->tables[0]
                        .values[235] != -1) ++bad;
                    if (d->tables[0]
                        .values[236] != -1) ++bad;
                    if (d->tables[0]
                        .values[237] != 0) ++bad;
                    if (d->tables[0]
                        .values[238] != 0) ++bad;
                    if (d->tables[0]
                        .values[239] != 0) ++bad;
                    if (d->tables[0]
                        .values[240] != -1) ++bad;
                    if (d->tables[0]
                        .values[241] != -1) ++bad;
                    if (d->tables[0]
                        .values[242] != -2) ++bad;
                    if (d->tables[0]
                        .values[243] != -2) ++bad;
                    if (d->tables[0]
                        .values[244] != -1) ++bad;
                    if (d->tables[0]
                        .values[245] != -1) ++bad;
                    if (d->tables[0]
                        .values[246] != 0) ++bad;
                    if (d->tables[0]
                        .values[247] != 1) ++bad;
                    if (d->tables[0]
                        .values[248] != 1) ++bad;
                    if (d->tables[0]
                        .values[249] != 1) ++bad;
                    if (d->tables[0]
                        .values[250] != 0) ++bad;
                    if (d->tables[0]
                        .values[251] != 0) ++bad;
                    if (d->tables[0]
                        .values[252] != 0) ++bad;
                    if (d->tables[0]
                        .values[253] != 0) ++bad;
                    if (d->tables[0]
                        .values[254] != 1) ++bad;
                    if (d->tables[0]
                        .values[255] != 1) ++bad;
                    if (d->tables[0]
                        .values[256] != 1) ++bad;
                    if (d->tables[0]
                        .values[257] != 1) ++bad;
                    if (d->tables[0]
                        .values[258] != 2) ++bad;
                    if (d->tables[0]
                        .values[259] != 2) ++bad;
                    if (d->tables[0]
                        .values[260] != 2) ++bad;
                    if (d->tables[0]
                        .values[261] != 1) ++bad;
                    if (d->tables[0]
                        .values[262] != 1) ++bad;
                    if (d->tables[0]
                        .values[263] != 0) ++bad;
                    if (d->tables[0]
                        .values[264] != -3) ++bad;
                    if (d->tables[0]
                        .values[265] != -2) ++bad;
                    if (d->tables[0]
                        .values[266] != -2) ++bad;
                    if (d->tables[0]
                        .values[267] != -1) ++bad;
                    if (d->tables[0]
                        .values[268] != -1) ++bad;
                    if (d->tables[0]
                        .values[269] != -1) ++bad;
                    if (d->tables[0]
                        .values[270] != 0) ++bad;
                    if (d->tables[0]
                        .values[271] != 0) ++bad;
                    if (d->tables[0]
                        .values[272] != 0) ++bad;
                    if (d->tables[0]
                        .values[273] != 0) ++bad;
                    if (d->tables[0]
                        .values[274] != 0) ++bad;
                    if (d->tables[0]
                        .values[275] != 0) ++bad;
                    if (d->tables[0]
                        .values[276] != 1) ++bad;
                    if (d->tables[0]
                        .values[277] != 1) ++bad;
                    if (d->tables[0]
                        .values[278] != 1) ++bad;
                    if (d->tables[0]
                        .values[279] != 2) ++bad;
                    if (d->tables[0]
                        .values[280] != 2) ++bad;
                    if (d->tables[0]
                        .values[281] != 2) ++bad;
                    if (d->tables[0]
                        .values[282] != 1) ++bad;
                    if (d->tables[0]
                        .values[283] != 1) ++bad;
                    if (d->tables[0]
                        .values[284] != 0) ++bad;
                    if (d->tables[0]
                        .values[285] != 0) ++bad;
                    if (d->tables[0]
                        .values[286] != 0) ++bad;
                    if (d->tables[0]
                        .values[287] != 0) ++bad;
                    if (d->tables[0]
                        .values[288] != 0) ++bad;
                    if (d->tables[0]
                        .values[289] != 1) ++bad;
                    if (d->tables[0]
                        .values[290] != 0) ++bad;
                    if (d->tables[0]
                        .values[291] != 1) ++bad;
                    if (d->tables[0]
                        .values[292] != 0) ++bad;
                    if (d->tables[0]
                        .values[293] != 0) ++bad;
                    if (d->tables[0]
                        .values[294] != 0) ++bad;
                    if (d->tables[0]
                        .values[295] != 0) ++bad;
                    if (d->tables[0]
                        .values[296] != 0) ++bad;
                    if (d->tables[0]
                        .values[297] != -3) ++bad;
                    if (d->tables[0]
                        .values[298] != -3) ++bad;
                    if (d->tables[0]
                        .values[299] != -2) ++bad;
                    if (d->tables[0]
                        .values[300] != -2) ++bad;
                    if (d->tables[0]
                        .values[301] != -1) ++bad;
                    if (d->tables[0]
                        .values[302] != -1) ++bad;
                    if (d->tables[0]
                        .values[303] != 0) ++bad;
                    if (d->tables[0]
                        .values[304] != 0) ++bad;
                    if (d->tables[0]
                        .values[305] != 0) ++bad;
                    if (d->tables[0]
                        .values[306] != 0) ++bad;
                    if (d->tables[0]
                        .values[307] != -1) ++bad;
                    if (d->tables[0]
                        .values[308] != -10) ++bad;
                    if (d->tables[0]
                        .values[309] != -9) ++bad;
                    if (d->tables[0]
                        .values[310] != -8) ++bad;
                    if (d->tables[0]
                        .values[311] != -6) ++bad;
                    if (d->tables[0]
                        .values[312] != -4) ++bad;
                    if (d->tables[0]
                        .values[313] != -2) ++bad;
                    if (d->tables[0]
                        .values[314] != -1) ++bad;
                    if (d->tables[0]
                        .values[315] != 0) ++bad;
                    if (d->tables[0]
                        .values[316] != 1) ++bad;
                    if (d->tables[0]
                        .values[317] != 0) ++bad;
                    if (d->tables[0]
                        .values[318] != 2) ++bad;
                    if (d->tables[0]
                        .values[319] != -6) ++bad;
                    if (d->tables[0]
                        .values[320] != -5) ++bad;
                    if (d->tables[0]
                        .values[321] != -5) ++bad;
                    if (d->tables[0]
                        .values[322] != -4) ++bad;
                    if (d->tables[0]
                        .values[323] != -3) ++bad;
                    if (d->tables[0]
                        .values[324] != -2) ++bad;
                    if (d->tables[0]
                        .values[325] != -1) ++bad;
                    if (d->tables[0]
                        .values[326] != 0) ++bad;
                    if (d->tables[0]
                        .values[327] != 1) ++bad;
                    if (d->tables[0]
                        .values[328] != 1) ++bad;
                    if (d->tables[0]
                        .values[329] != 3) ++bad;
                    if (d->tables[0]
                        .values[330] != -3) ++bad;
                    if (d->tables[0]
                        .values[331] != -3) ++bad;
                    if (d->tables[0]
                        .values[332] != -2) ++bad;
                    if (d->tables[0]
                        .values[333] != -2) ++bad;
                    if (d->tables[0]
                        .values[334] != -1) ++bad;
                    if (d->tables[0]
                        .values[335] != 0) ++bad;
                    if (d->tables[0]
                        .values[336] != 0) ++bad;
                    if (d->tables[0]
                        .values[337] != 0) ++bad;
                    if (d->tables[0]
                        .values[338] != 0) ++bad;
                    if (d->tables[0]
                        .values[339] != 0) ++bad;
                    if (d->tables[0]
                        .values[340] != 0) ++bad;
                    if (d->tables[0]
                        .values[341] != -1) ++bad;
                    if (d->tables[0]
                        .values[342] != 0) ++bad;
                    if (d->tables[0]
                        .values[343] != 0) ++bad;
                    if (d->tables[0]
                        .values[344] != 1) ++bad;
                    if (d->tables[0]
                        .values[345] != 1) ++bad;
                    if (d->tables[0]
                        .values[346] != 1) ++bad;
                    if (d->tables[0]
                        .values[347] != 1) ++bad;
                    if (d->tables[0]
                        .values[348] != 0) ++bad;
                    if (d->tables[0]
                        .values[349] != 0) ++bad;
                    if (d->tables[0]
                        .values[350] != 0) ++bad;
                    if (d->tables[0]
                        .values[351] != 0) ++bad;
                    if (d->tables[0]
                        .values[352] != 4) ++bad;
                    if (d->tables[0]
                        .values[353] != 4) ++bad;
                    if (d->tables[0]
                        .values[354] != 3) ++bad;
                    if (d->tables[0]
                        .values[355] != 3) ++bad;
                    if (d->tables[0]
                        .values[356] != 2) ++bad;
                    if (d->tables[0]
                        .values[357] != 2) ++bad;
                    if (d->tables[0]
                        .values[358] != 2) ++bad;
                    if (d->tables[0]
                        .values[359] != 1) ++bad;
                    if (d->tables[0]
                        .values[360] != 1) ++bad;
                    if (d->tables[0]
                        .values[361] != 0) ++bad;
                    if (d->tables[0]
                        .values[362] != 0) ++bad;
                    if (d->tables[0]
                        .values[363] != 0) ++bad;
                    if (d->tables[0]
                        .values[364] != 0) ++bad;
                    if (d->tables[0]
                        .values[365] != 0) ++bad;
                    if (d->tables[0]
                        .values[366] != 0) ++bad;
                    if (d->tables[0]
                        .values[367] != 0) ++bad;
                    if (d->tables[0]
                        .values[368] != 0) ++bad;
                    if (d->tables[0]
                        .values[369] != 0) ++bad;
                    if (d->tables[0]
                        .values[370] != 0) ++bad;
                    if (d->tables[0]
                        .values[371] != 0) ++bad;
                    if (d->tables[0]
                        .values[372] != 0) ++bad;
                    if (d->tables[0]
                        .values[373] != 0) ++bad;
                    if (d->tables[0]
                        .values[374] != 2) ++bad;
                    if (d->tables[0]
                        .values[375] != 2) ++bad;
                    if (d->tables[0]
                        .values[376] != 1) ++bad;
                    if (d->tables[0]
                        .values[377] != 1) ++bad;
                    if (d->tables[0]
                        .values[378] != 0) ++bad;
                    if (d->tables[0]
                        .values[379] != 0) ++bad;
                    if (d->tables[0]
                        .values[380] != 0) ++bad;
                    if (d->tables[0]
                        .values[381] != 0) ++bad;
                    if (d->tables[0]
                        .values[382] != 0) ++bad;
                    if (d->tables[0]
                        .values[383] != 1) ++bad;
                    if (d->tables[0]
                        .values[384] != -1) ++bad;
                    if (d->tables[0]
                        .values[385] != 2) ++bad;
                    if (d->tables[0]
                        .values[386] != 2) ++bad;
                    if (d->tables[0]
                        .values[387] != 1) ++bad;
                    if (d->tables[0]
                        .values[388] != 1) ++bad;
                    if (d->tables[0]
                        .values[389] != 0) ++bad;
                    if (d->tables[0]
                        .values[390] != 0) ++bad;
                    if (d->tables[0]
                        .values[391] != 0) ++bad;
                    if (d->tables[0]
                        .values[392] != 0) ++bad;
                    if (d->tables[0]
                        .values[393] != 0) ++bad;
                    if (d->tables[0]
                        .values[394] != 0) ++bad;
                    if (d->tables[0]
                        .values[395] != 0) ++bad;
                    if (d->tables[0]
                        .values[396] != 0) ++bad;
                    if (d->tables[0]
                        .values[397] != 0) ++bad;
                    if (d->tables[0]
                        .values[398] != 0) ++bad;
                    if (d->tables[0]
                        .values[399] != 0) ++bad;
                    if (d->tables[0]
                        .values[400] != 0) ++bad;
                    if (d->tables[0]
                        .values[401] != 0) ++bad;
                    if (d->tables[0]
                        .values[402] != 0) ++bad;
                    if (d->tables[0]
                        .values[403] != 0) ++bad;
                    if (d->tables[0]
                        .values[404] != -1) ++bad;
                    if (d->tables[0]
                        .values[405] != -2) ++bad;
                    if (d->tables[0]
                        .values[406] != -3) ++bad;
                    if (d->tables[0]
                        .values[407] != 0) ++bad;
                    if (d->tables[0]
                        .values[408] != 0) ++bad;
                    if (d->tables[0]
                        .values[409] != 0) ++bad;
                    if (d->tables[0]
                        .values[410] != 1) ++bad;
                    if (d->tables[0]
                        .values[411] != 1) ++bad;
                    if (d->tables[0]
                        .values[412] != 1) ++bad;
                    if (d->tables[0]
                        .values[413] != 1) ++bad;
                    if (d->tables[0]
                        .values[414] != 1) ++bad;
                    if (d->tables[0]
                        .values[415] != 1) ++bad;
                    if (d->tables[0]
                        .values[416] != 2) ++bad;
                    if (d->tables[0]
                        .values[417] != 2) ++bad;
                    if (d->tables[0]
                        .values[418] != 0) ++bad;
                    if (d->tables[0]
                        .values[419] != 0) ++bad;
                    if (d->tables[0]
                        .values[420] != 0) ++bad;
                    if (d->tables[0]
                        .values[421] != 0) ++bad;
                    if (d->tables[0]
                        .values[422] != 0) ++bad;
                    if (d->tables[0]
                        .values[423] != 0) ++bad;
                    if (d->tables[0]
                        .values[424] != 0) ++bad;
                    if (d->tables[0]
                        .values[425] != 0) ++bad;
                    if (d->tables[0]
                        .values[426] != 0) ++bad;
                    if (d->tables[0]
                        .values[427] != 0) ++bad;
                    if (d->tables[0]
                        .values[428] != 0) ++bad;
                    if (d->tables[0]
                        .values[429] != 3) ++bad;
                    if (d->tables[0]
                        .values[430] != 3) ++bad;
                    if (d->tables[0]
                        .values[431] != 2) ++bad;
                    if (d->tables[0]
                        .values[432] != 2) ++bad;
                    if (d->tables[0]
                        .values[433] != 1) ++bad;
                    if (d->tables[0]
                        .values[434] != 1) ++bad;
                    if (d->tables[0]
                        .values[435] != 0) ++bad;
                    if (d->tables[0]
                        .values[436] != -1) ++bad;
                    if (d->tables[0]
                        .values[437] != -1) ++bad;
                    if (d->tables[0]
                        .values[438] != -1) ++bad;
                    if (d->tables[0]
                        .values[439] != -2) ++bad;
                    if (d->tables[0]
                        .values[440] != 2) ++bad;
                    if (d->tables[0]
                        .values[441] != 2) ++bad;
                    if (d->tables[0]
                        .values[442] != 1) ++bad;
                    if (d->tables[0]
                        .values[443] != 1) ++bad;
                    if (d->tables[0]
                        .values[444] != 1) ++bad;
                    if (d->tables[0]
                        .values[445] != 1) ++bad;
                    if (d->tables[0]
                        .values[446] != 0) ++bad;
                    if (d->tables[0]
                        .values[447] != 0) ++bad;
                    if (d->tables[0]
                        .values[448] != -1) ++bad;
                    if (d->tables[0]
                        .values[449] != -1) ++bad;
                    if (d->tables[0]
                        .values[450] != -1) ++bad;
                    if (d->tables[0]
                        .values[451] != -1) ++bad;
                    if (d->tables[0]
                        .values[452] != -1) ++bad;
                    if (d->tables[0]
                        .values[453] != -1) ++bad;
                    if (d->tables[0]
                        .values[454] != 0) ++bad;
                    if (d->tables[0]
                        .values[455] != 0) ++bad;
                    if (d->tables[0]
                        .values[456] != 0) ++bad;
                    if (d->tables[0]
                        .values[457] != 0) ++bad;
                    if (d->tables[0]
                        .values[458] != 0) ++bad;
                    if (d->tables[0]
                        .values[459] != 0) ++bad;
                    if (d->tables[0]
                        .values[460] != -1) ++bad;
                    if (d->tables[0]
                        .values[461] != -2) ++bad;
                    if (d->tables[0]
                        .values[462] != -3) ++bad;
                    if (d->tables[0]
                        .values[463] != -3) ++bad;
                    if (d->tables[0]
                        .values[464] != -2) ++bad;
                    if (d->tables[0]
                        .values[465] != -1) ++bad;
                    if (d->tables[0]
                        .values[466] != -1) ++bad;
                    if (d->tables[0]
                        .values[467] != 0) ++bad;
                    if (d->tables[0]
                        .values[468] != 0) ++bad;
                    if (d->tables[0]
                        .values[469] != 0) ++bad;
                    if (d->tables[0]
                        .values[470] != 0) ++bad;
                    if (d->tables[0]
                        .values[471] != 0) ++bad;
                    if (d->tables[0]
                        .values[472] != 1) ++bad;
                    if (d->tables[0]
                        .values[473] != -14) ++bad;
                    if (d->tables[0]
                        .values[474] != -13) ++bad;
                    if (d->tables[0]
                        .values[475] != -12) ++bad;
                    if (d->tables[0]
                        .values[476] != -10) ++bad;
                    if (d->tables[0]
                        .values[477] != -8) ++bad;
                    if (d->tables[0]
                        .values[478] != -6) ++bad;
                    if (d->tables[0]
                        .values[479] != -5) ++bad;
                    if (d->tables[0]
                        .values[480] != -4) ++bad;
                    if (d->tables[0]
                        .values[481] != -3) ++bad;
                    if (d->tables[0]
                        .values[482] != -2) ++bad;
                    if (d->tables[0]
                        .values[483] != 0) ++bad;
                    if (d->tables[0]
                        .values[484] != -4) ++bad;
                    if (d->tables[0]
                        .values[485] != -3) ++bad;
                    if (d->tables[0]
                        .values[486] != -3) ++bad;
                    if (d->tables[0]
                        .values[487] != -2) ++bad;
                    if (d->tables[0]
                        .values[488] != -2) ++bad;
                    if (d->tables[0]
                        .values[489] != -1) ++bad;
                    if (d->tables[0]
                        .values[490] != 0) ++bad;
                    if (d->tables[0]
                        .values[491] != 0) ++bad;
                    if (d->tables[0]
                        .values[492] != 1) ++bad;
                    if (d->tables[0]
                        .values[493] != 1) ++bad;
                    if (d->tables[0]
                        .values[494] != 3) ++bad;
                    if (d->tables[0]
                        .values[495] != -2) ++bad;
                    if (d->tables[0]
                        .values[496] != -2) ++bad;
                    if (d->tables[0]
                        .values[497] != -2) ++bad;
                    if (d->tables[0]
                        .values[498] != -1) ++bad;
                    if (d->tables[0]
                        .values[499] != -1) ++bad;
                    if (d->tables[0]
                        .values[500] != -1) ++bad;
                    if (d->tables[0]
                        .values[501] != 0) ++bad;
                    if (d->tables[0]
                        .values[502] != 0) ++bad;
                    if (d->tables[0]
                        .values[503] != 0) ++bad;
                    if (d->tables[0]
                        .values[504] != 0) ++bad;
                    if (d->tables[0]
                        .values[505] != 0) ++bad;
                    if (d->tables[0]
                        .values[506] != -2) ++bad;
                    if (d->tables[0]
                        .values[507] != -2) ++bad;
                    if (d->tables[0]
                        .values[508] != -2) ++bad;
                    if (d->tables[0]
                        .values[509] != -1) ++bad;
                    if (d->tables[0]
                        .values[510] != 0) ++bad;
                    if (d->tables[0]
                        .values[511] != 0) ++bad;
                    if (d->tables[0]
                        .values[512] != 0) ++bad;
                    if (d->tables[0]
                        .values[513] != 0) ++bad;
                    if (d->tables[0]
                        .values[514] != 0) ++bad;
                    if (d->tables[0]
                        .values[515] != 1) ++bad;
                    if (d->tables[0]
                        .values[516] != 2) ++bad;
                    if (d->tables[0]
                        .values[517] != -7) ++bad;
                    if (d->tables[0]
                        .values[518] != -6) ++bad;
                    if (d->tables[0]
                        .values[519] != -5) ++bad;
                    if (d->tables[0]
                        .values[520] != -4) ++bad;
                    if (d->tables[0]
                        .values[521] != -3) ++bad;
                    if (d->tables[0]
                        .values[522] != -2) ++bad;
                    if (d->tables[0]
                        .values[523] != -1) ++bad;
                    if (d->tables[0]
                        .values[524] != 0) ++bad;
                    if (d->tables[0]
                        .values[525] != 0) ++bad;
                    if (d->tables[0]
                        .values[526] != 0) ++bad;
                    if (d->tables[0]
                        .values[527] != 2) ++bad;
                    if (d->tables[0]
                        .values[528] != -9) ++bad;
                    if (d->tables[0]
                        .values[529] != -8) ++bad;
                    if (d->tables[0]
                        .values[530] != -7) ++bad;
                    if (d->tables[0]
                        .values[531] != -5) ++bad;
                    if (d->tables[0]
                        .values[532] != -3) ++bad;
                    if (d->tables[0]
                        .values[533] != -1) ++bad;
                    if (d->tables[0]
                        .values[534] != 0) ++bad;
                    if (d->tables[0]
                        .values[535] != 0) ++bad;
                    if (d->tables[0]
                        .values[536] != 1) ++bad;
                    if (d->tables[0]
                        .values[537] != 1) ++bad;
                    if (d->tables[0]
                        .values[538] != 1) ++bad;
                    if (d->tables[0]
                        .values[539] != 0) ++bad;
                    if (d->tables[0]
                        .values[540] != 0) ++bad;
                    if (d->tables[0]
                        .values[541] != 0) ++bad;
                    if (d->tables[0]
                        .values[542] != 0) ++bad;
                    if (d->tables[0]
                        .values[543] != 0) ++bad;
                    if (d->tables[0]
                        .values[544] != 0) ++bad;
                    if (d->tables[0]
                        .values[545] != 0) ++bad;
                    if (d->tables[0]
                        .values[546] != 0) ++bad;
                    if (d->tables[0]
                        .values[547] != 0) ++bad;
                    if (d->tables[0]
                        .values[548] != 0) ++bad;
                    if (d->tables[0]
                        .values[549] != 0) ++bad;
                    if (d->tables[0]
                        .values[550] != 0) ++bad;
                    if (d->tables[0]
                        .values[551] != 0) ++bad;
                    if (d->tables[0]
                        .values[552] != 0) ++bad;
                    if (d->tables[0]
                        .values[553] != 0) ++bad;
                    if (d->tables[0]
                        .values[554] != 1) ++bad;
                    if (d->tables[0]
                        .values[555] != 1) ++bad;
                    if (d->tables[0]
                        .values[556] != 1) ++bad;
                    if (d->tables[0]
                        .values[557] != 1) ++bad;
                    if (d->tables[0]
                        .values[558] != 1) ++bad;
                    if (d->tables[0]
                        .values[559] != 1) ++bad;
                    if (d->tables[0]
                        .values[560] != 0) ++bad;
                    if (d->tables[0]
                        .values[561] != -5) ++bad;
                    if (d->tables[0]
                        .values[562] != -4) ++bad;
                    if (d->tables[0]
                        .values[563] != -3) ++bad;
                    if (d->tables[0]
                        .values[564] != -2) ++bad;
                    if (d->tables[0]
                        .values[565] != -1) ++bad;
                    if (d->tables[0]
                        .values[566] != 0) ++bad;
                    if (d->tables[0]
                        .values[567] != 0) ++bad;
                    if (d->tables[0]
                        .values[568] != 1) ++bad;
                    if (d->tables[0]
                        .values[569] != 1) ++bad;
                    if (d->tables[0]
                        .values[570] != 1) ++bad;
                    if (d->tables[0]
                        .values[571] != 2) ++bad;
                    if (d->tables[0]
                        .values[572] != -3) ++bad;
                    if (d->tables[0]
                        .values[573] != -2) ++bad;
                    if (d->tables[0]
                        .values[574] != -2) ++bad;
                    if (d->tables[0]
                        .values[575] != -1) ++bad;
                    if (d->tables[0]
                        .values[576] != 0) ++bad;
                    if (d->tables[0]
                        .values[577] != 1) ++bad;
                    if (d->tables[0]
                        .values[578] != 1) ++bad;
                    if (d->tables[0]
                        .values[579] != 1) ++bad;
                    if (d->tables[0]
                        .values[580] != 1) ++bad;
                    if (d->tables[0]
                        .values[581] != 0) ++bad;
                    if (d->tables[0]
                        .values[582] != 0) ++bad;
                    if (d->tables[0]
                        .values[583] != -7) ++bad;
                    if (d->tables[0]
                        .values[584] != -6) ++bad;
                    if (d->tables[0]
                        .values[585] != -5) ++bad;
                    if (d->tables[0]
                        .values[586] != -4) ++bad;
                    if (d->tables[0]
                        .values[587] != -2) ++bad;
                    if (d->tables[0]
                        .values[588] != -1) ++bad;
                    if (d->tables[0]
                        .values[589] != 0) ++bad;
                    if (d->tables[0]
                        .values[590] != 0) ++bad;
                    if (d->tables[0]
                        .values[591] != 1) ++bad;
                    if (d->tables[0]
                        .values[592] != 1) ++bad;
                    if (d->tables[0]
                        .values[593] != 2) ++bad;
                    if (d->tables[0]
                        .values[594] != -4) ++bad;
                    if (d->tables[0]
                        .values[595] != -3) ++bad;
                    if (d->tables[0]
                        .values[596] != -2) ++bad;
                    if (d->tables[0]
                        .values[597] != -1) ++bad;
                    if (d->tables[0]
                        .values[598] != 0) ++bad;
                    if (d->tables[0]
                        .values[599] != 0) ++bad;
                    if (d->tables[0]
                        .values[600] != 0) ++bad;
                    if (d->tables[0]
                        .values[601] != 0) ++bad;
                    if (d->tables[0]
                        .values[602] != 0) ++bad;
                    if (d->tables[0]
                        .values[603] != 1) ++bad;
                    if (d->tables[0]
                        .values[604] != 2) ++bad;
                    if (d->tables[0]
                        .values[605] != -5) ++bad;
                    if (d->tables[0]
                        .values[606] != -4) ++bad;
                    if (d->tables[0]
                        .values[607] != -3) ++bad;
                    if (d->tables[0]
                        .values[608] != -2) ++bad;
                    if (d->tables[0]
                        .values[609] != -1) ++bad;
                    if (d->tables[0]
                        .values[610] != 0) ++bad;
                    if (d->tables[0]
                        .values[611] != 0) ++bad;
                    if (d->tables[0]
                        .values[612] != 0) ++bad;
                    if (d->tables[0]
                        .values[613] != 1) ++bad;
                    if (d->tables[0]
                        .values[614] != 0) ++bad;
                    if (d->tables[0]
                        .values[615] != 2) ++bad;
                    if (d->tables[0]
                        .values[616] != 2) ++bad;
                    if (d->tables[0]
                        .values[617] != 2) ++bad;
                    if (d->tables[0]
                        .values[618] != 2) ++bad;
                    if (d->tables[0]
                        .values[619] != 2) ++bad;
                    if (d->tables[0]
                        .values[620] != 2) ++bad;
                    if (d->tables[0]
                        .values[621] != 2) ++bad;
                    if (d->tables[0]
                        .values[622] != 3) ++bad;
                    if (d->tables[0]
                        .values[623] != 3) ++bad;
                    if (d->tables[0]
                        .values[624] != 3) ++bad;
                    if (d->tables[0]
                        .values[625] != 1) ++bad;
                    if (d->tables[0]
                        .values[626] != 0) ++bad;
                    if (d->tables[0]
                        .values[627] != -4) ++bad;
                    if (d->tables[0]
                        .values[628] != -3) ++bad;
                    if (d->tables[0]
                        .values[629] != -3) ++bad;
                    if (d->tables[0]
                        .values[630] != -2) ++bad;
                    if (d->tables[0]
                        .values[631] != -1) ++bad;
                    if (d->tables[0]
                        .values[632] != -1) ++bad;
                    if (d->tables[0]
                        .values[633] != 0) ++bad;
                    if (d->tables[0]
                        .values[634] != 0) ++bad;
                    if (d->tables[0]
                        .values[635] != 1) ++bad;
                    if (d->tables[0]
                        .values[636] != 0) ++bad;
                    if (d->tables[0]
                        .values[637] != 1) ++bad;
                    if (d->tables[0]
                        .values[638] != -2) ++bad;
                    if (d->tables[0]
                        .values[639] != -2) ++bad;
                    if (d->tables[0]
                        .values[640] != -1) ++bad;
                    if (d->tables[0]
                        .values[641] != -1) ++bad;
                    if (d->tables[0]
                        .values[642] != 0) ++bad;
                    if (d->tables[0]
                        .values[643] != 1) ++bad;
                    if (d->tables[0]
                        .values[644] != 1) ++bad;
                    if (d->tables[0]
                        .values[645] != 1) ++bad;
                    if (d->tables[0]
                        .values[646] != 0) ++bad;
                    if (d->tables[0]
                        .values[647] != 0) ++bad;
                    if (d->tables[0]
                        .values[648] != 0) ++bad;
                    if (d->tables[0]
                        .values[649] != -14) ++bad;
                    if (d->tables[0]
                        .values[650] != -12) ++bad;
                    if (d->tables[0]
                        .values[651] != -10) ++bad;
                    if (d->tables[0]
                        .values[652] != -8) ++bad;
                    if (d->tables[0]
                        .values[653] != -6) ++bad;
                    if (d->tables[0]
                        .values[654] != -4) ++bad;
                    if (d->tables[0]
                        .values[655] != -2) ++bad;
                    if (d->tables[0]
                        .values[656] != -1) ++bad;
                    if (d->tables[0]
                        .values[657] != 1) ++bad;
                    if (d->tables[0]
                        .values[658] != 0) ++bad;
                    if (d->tables[0]
                        .values[659] != 3) ++bad;
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
                        .values[12] != 1) ++bad;
                    if (d->tables[1]
                        .values[13] != 1) ++bad;
                    if (d->tables[1]
                        .values[14] != 0) ++bad;
                    if (d->tables[1]
                        .values[15] != 0) ++bad;
                    if (d->tables[1]
                        .values[16] != 0) ++bad;
                    if (d->tables[1]
                        .values[17] != 1) ++bad;
                    if (d->tables[1]
                        .values[18] != 0) ++bad;
                    if (d->tables[1]
                        .values[19] != 0) ++bad;
                    if (d->tables[1]
                        .values[20] != 1) ++bad;
                    if (d->tables[1]
                        .values[21] != 1) ++bad;
                    if (d->tables[1]
                        .values[22] != 1) ++bad;
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
                    if (d->tables[1]
                        .values[33] != 0) ++bad;
                    if (d->tables[1]
                        .values[34] != 0) ++bad;
                    if (d->tables[1]
                        .values[35] != 0) ++bad;
                    if (d->tables[1]
                        .values[36] != 0) ++bad;
                    if (d->tables[1]
                        .values[37] != 0) ++bad;
                    if (d->tables[1]
                        .values[38] != 0) ++bad;
                    if (d->tables[1]
                        .values[39] != 0) ++bad;
                    if (d->tables[1]
                        .values[40] != 0) ++bad;
                    if (d->tables[1]
                        .values[41] != 0) ++bad;
                    if (d->tables[1]
                        .values[42] != 1) ++bad;
                    if (d->tables[1]
                        .values[43] != 0) ++bad;
                    if (d->tables[1]
                        .values[44] != 0) ++bad;
                    if (d->tables[1]
                        .values[45] != 0) ++bad;
                    if (d->tables[1]
                        .values[46] != 0) ++bad;
                    if (d->tables[1]
                        .values[47] != 0) ++bad;
                    if (d->tables[1]
                        .values[48] != 0) ++bad;
                    if (d->tables[1]
                        .values[49] != 0) ++bad;
                    if (d->tables[1]
                        .values[50] != 0) ++bad;
                    if (d->tables[1]
                        .values[51] != 0) ++bad;
                    if (d->tables[1]
                        .values[52] != 0) ++bad;
                    if (d->tables[1]
                        .values[53] != 0) ++bad;
                    if (d->tables[1]
                        .values[54] != 0) ++bad;
                    if (d->tables[1]
                        .values[55] != 0) ++bad;
                    if (d->tables[1]
                        .values[56] != 0) ++bad;
                    if (d->tables[1]
                        .values[57] != 0) ++bad;
                    if (d->tables[1]
                        .values[58] != 0) ++bad;
                    if (d->tables[1]
                        .values[59] != 0) ++bad;
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
                        .values[32] != 0) ++bad;
                    if (d->tables[2]
                        .values[33] != 0) ++bad;
                    if (d->tables[2]
                        .values[34] != 0) ++bad;
                    if (d->tables[2]
                        .values[35] != 0) ++bad;
                    if (d->tables[2]
                        .values[36] != 0) ++bad;
                    if (d->tables[2]
                        .values[37] != 0) ++bad;
                    if (d->tables[2]
                        .values[38] != 0) ++bad;
                    if (d->tables[2]
                        .values[39] != 0) ++bad;
                    if (d->tables[2]
                        .values[40] != 0) ++bad;
                    if (d->tables[2]
                        .values[41] != 0) ++bad;
                    if (d->tables[2]
                        .values[42] != 0) ++bad;
                    if (d->tables[2]
                        .values[43] != 0) ++bad;
                    if (d->tables[2]
                        .values[44] != 0) ++bad;
                    if (d->tables[2]
                        .values[45] != 0) ++bad;
                    if (d->tables[2]
                        .values[46] != 1) ++bad;
                    if (d->tables[2]
                        .values[47] != 0) ++bad;
                    if (d->tables[2]
                        .values[48] != 0) ++bad;
                    if (d->tables[2]
                        .values[49] != 0) ++bad;
                    if (d->tables[2]
                        .values[50] != 1) ++bad;
                    if (d->tables[2]
                        .values[51] != 0) ++bad;
                    if (d->tables[2]
                        .values[52] != 0) ++bad;
                    if (d->tables[2]
                        .values[53] != 0) ++bad;
                    if (d->tables[2]
                        .values[54] != 0) ++bad;
                    if (d->tables[2]
                        .values[55] != 0) ++bad;
                    if (d->tables[2]
                        .values[56] != 0) ++bad;
                    if (d->tables[2]
                        .values[57] != 0) ++bad;
                    if (d->tables[2]
                        .values[58] != 0) ++bad;
                    if (d->tables[2]
                        .values[59] != 0) ++bad;
                    if (d->tables[3]
                        .values[0] != 4) ++bad;
                    if (d->tables[3]
                        .values[1] != -1) ++bad;
                    if (d->tables[3]
                        .values[2] != 7) ++bad;
                    if (d->tables[3]
                        .values[3] != 4) ++bad;
                    if (d->tables[3]
                        .values[4] != 9) ++bad;
                    if (d->tables[3]
                        .values[5] != 9) ++bad;
                    if (d->tables[3]
                        .values[6] != 10) ++bad;
                    if (d->tables[3]
                        .values[7] != -1) ++bad;
                    if (d->tables[3]
                        .values[8] != 3) ++bad;
                    if (d->tables[3]
                        .values[9] != -1) ++bad;
                    if (d->tables[3]
                        .values[10] != 4) ++bad;
                    if (d->tables[3]
                        .values[11] != 2) ++bad;
                    if (d->tables[3]
                        .values[12] != 8) ++bad;
                    if (d->tables[3]
                        .values[13] != 8) ++bad;
                    if (d->tables[3]
                        .values[14] != 1) ++bad;
                    if (d->tables[3]
                        .values[15] != 7) ++bad;
                    if (d->tables[3]
                        .values[16] != 6) ++bad;
                    if (d->tables[3]
                        .values[17] != 7) ++bad;
                    if (d->tables[3]
                        .values[18] != 2) ++bad;
                    if (d->tables[3]
                        .values[19] != 8) ++bad;
                    if (d->tables[3]
                        .values[20] != 9) ++bad;
                    if (d->tables[3]
                        .values[21] != 8) ++bad;
                    if (d->tables[3]
                        .values[22] != 10) ++bad;
                    if (d->tables[3]
                        .values[23] != 9) ++bad;
                    if (d->tables[3]
                        .values[24] != 6) ++bad;
                    if (d->tables[3]
                        .values[25] != 9) ++bad;
                    if (d->tables[3]
                        .values[26] != 4) ++bad;
                    if (d->tables[3]
                        .values[27] != 9) ++bad;
                    if (d->tables[3]
                        .values[28] != 2) ++bad;
                    if (d->tables[3]
                        .values[29] != 2) ++bad;
                    if (d->tables[3]
                        .values[30] != 7) ++bad;
                    if (d->tables[3]
                        .values[31] != 6) ++bad;
                    if (d->tables[3]
                        .values[32] != 8) ++bad;
                    if (d->tables[3]
                        .values[33] != 10) ++bad;
                    if (d->tables[3]
                        .values[34] != 7) ++bad;
                    if (d->tables[3]
                        .values[35] != 6) ++bad;
                    if (d->tables[3]
                        .values[36] != 7) ++bad;
                    if (d->tables[3]
                        .values[37] != 7) ++bad;
                    if (d->tables[3]
                        .values[38] != 9) ++bad;
                    if (d->tables[3]
                        .values[39] != 7) ++bad;
                    if (d->tables[3]
                        .values[40] != 5) ++bad;
                    if (d->tables[3]
                        .values[41] != 13) ++bad;
                    if (d->tables[3]
                        .values[42] != 8) ++bad;
                    if (d->tables[3]
                        .values[43] != 2) ++bad;
                    if (d->tables[3]
                        .values[44] != 4) ++bad;
                    if (d->tables[3]
                        .values[45] != 8) ++bad;
                    if (d->tables[3]
                        .values[46] != 8) ++bad;
                    if (d->tables[3]
                        .values[47] != 4) ++bad;
                    if (d->tables[3]
                        .values[48] != 4) ++bad;
                    if (d->tables[3]
                        .values[49] != 11) ++bad;
                    if (d->tables[3]
                        .values[50] != 6) ++bad;
                    if (d->tables[3]
                        .values[51] != 5) ++bad;
                    if (d->tables[3]
                        .values[52] != 5) ++bad;
                    if (d->tables[3]
                        .values[53] != 9) ++bad;
                    if (d->tables[3]
                        .values[54] != 5) ++bad;
                    if (d->tables[3]
                        .values[55] != 3) ++bad;
                    if (d->tables[3]
                        .values[56] != 10) ++bad;
                    if (d->tables[3]
                        .values[57] != 8) ++bad;
                    if (d->tables[3]
                        .values[58] != 10) ++bad;
                    if (d->tables[3]
                        .values[59] != 8) ++bad;
                    if (d->tables[4]
                        .values[0] != 4) ++bad;
                    if (d->tables[4]
                        .values[1] != -1) ++bad;
                    if (d->tables[4]
                        .values[2] != 7) ++bad;
                    if (d->tables[4]
                        .values[3] != 4) ++bad;
                    if (d->tables[4]
                        .values[4] != 9) ++bad;
                    if (d->tables[4]
                        .values[5] != 9) ++bad;
                    if (d->tables[4]
                        .values[6] != 10) ++bad;
                    if (d->tables[4]
                        .values[7] != -1) ++bad;
                    if (d->tables[4]
                        .values[8] != 3) ++bad;
                    if (d->tables[4]
                        .values[9] != -1) ++bad;
                    if (d->tables[4]
                        .values[10] != 4) ++bad;
                    if (d->tables[4]
                        .values[11] != 2) ++bad;
                    if (d->tables[4]
                        .values[12] != 8) ++bad;
                    if (d->tables[4]
                        .values[13] != 8) ++bad;
                    if (d->tables[4]
                        .values[14] != 1) ++bad;
                    if (d->tables[4]
                        .values[15] != 7) ++bad;
                    if (d->tables[4]
                        .values[16] != 6) ++bad;
                    if (d->tables[4]
                        .values[17] != 7) ++bad;
                    if (d->tables[4]
                        .values[18] != 2) ++bad;
                    if (d->tables[4]
                        .values[19] != 8) ++bad;
                    if (d->tables[4]
                        .values[20] != 9) ++bad;
                    if (d->tables[4]
                        .values[21] != 8) ++bad;
                    if (d->tables[4]
                        .values[22] != 10) ++bad;
                    if (d->tables[4]
                        .values[23] != 9) ++bad;
                    if (d->tables[4]
                        .values[24] != 6) ++bad;
                    if (d->tables[4]
                        .values[25] != 9) ++bad;
                    if (d->tables[4]
                        .values[26] != 4) ++bad;
                    if (d->tables[4]
                        .values[27] != 9) ++bad;
                    if (d->tables[4]
                        .values[28] != 2) ++bad;
                    if (d->tables[4]
                        .values[29] != 2) ++bad;
                    if (d->tables[4]
                        .values[30] != 7) ++bad;
                    if (d->tables[4]
                        .values[31] != 6) ++bad;
                    if (d->tables[4]
                        .values[32] != 8) ++bad;
                    if (d->tables[4]
                        .values[33] != 10) ++bad;
                    if (d->tables[4]
                        .values[34] != 7) ++bad;
                    if (d->tables[4]
                        .values[35] != 6) ++bad;
                    if (d->tables[4]
                        .values[36] != 7) ++bad;
                    if (d->tables[4]
                        .values[37] != 7) ++bad;
                    if (d->tables[4]
                        .values[38] != 9) ++bad;
                    if (d->tables[4]
                        .values[39] != 7) ++bad;
                    if (d->tables[4]
                        .values[40] != 5) ++bad;
                    if (d->tables[4]
                        .values[41] != 13) ++bad;
                    if (d->tables[4]
                        .values[42] != 8) ++bad;
                    if (d->tables[4]
                        .values[43] != 2) ++bad;
                    if (d->tables[4]
                        .values[44] != 4) ++bad;
                    if (d->tables[4]
                        .values[45] != 6) ++bad;
                    if (d->tables[4]
                        .values[46] != 8) ++bad;
                    if (d->tables[4]
                        .values[47] != 4) ++bad;
                    if (d->tables[4]
                        .values[48] != 4) ++bad;
                    if (d->tables[4]
                        .values[49] != 11) ++bad;
                    if (d->tables[4]
                        .values[50] != 6) ++bad;
                    if (d->tables[4]
                        .values[51] != 5) ++bad;
                    if (d->tables[4]
                        .values[52] != 5) ++bad;
                    if (d->tables[4]
                        .values[53] != 9) ++bad;
                    if (d->tables[4]
                        .values[54] != 5) ++bad;
                    if (d->tables[4]
                        .values[55] != 3) ++bad;
                    if (d->tables[4]
                        .values[56] != 10) ++bad;
                    if (d->tables[4]
                        .values[57] != 6) ++bad;
                    if (d->tables[4]
                        .values[58] != 10) ++bad;
                    if (d->tables[4]
                        .values[59] != 5) ++bad;
                    if (std::string(rules::uahhName(0))
                        != "Aklys") ++bad;
                    if (std::string(rules::uahhName(1))
                        != "Atlatl") ++bad;
                    if (std::string(rules::uahhName(2))
                        != "Axe, Battle") ++bad;
                    if (std::string(rules::uahhName(3))
                        != "Axe, Hand") ++bad;
                    if (std::string(rules::uahhName(4))
                        != "Bardiche") ++bad;
                    if (std::string(rules::uahhName(5))
                        != "Bec de Corbin") ++bad;
                    if (std::string(rules::uahhName(6))
                        != "Bill-Guisarme") ++bad;
                    if (std::string(rules::uahhName(7))
                        != "Blowgun") ++bad;
                    if (std::string(rules::uahhName(8))
                        != "Bo Stick") ++bad;
                    if (std::string(rules::uahhName(9))
                        != "Caltrop") ++bad;
                    if (std::string(rules::uahhName(10))
                        != "Club") ++bad;
                    if (std::string(rules::uahhName(11))
                        != "Dagger") ++bad;
                    if (std::string(rules::uahhName(12))
                        != "Fauchard") ++bad;
                    if (std::string(rules::uahhName(13))
                        != "Fauchard-Fork") ++bad;
                    if (std::string(rules::uahhName(14))
                        != "Fist or Open Hand") ++bad;
                    if (std::string(rules::uahhName(15))
                        != "Flail, Footman's") ++bad;
                    if (std::string(rules::uahhName(16))
                        != "Flail, Horseman's") ++bad;
                    if (std::string(rules::uahhName(17))
                        != "Fork, Military") ++bad;
                    if (std::string(rules::uahhName(18))
                        != "Garrot") ++bad;
                    if (std::string(rules::uahhName(19))
                        != "Glaive") ++bad;
                    if (std::string(rules::uahhName(20))
                        != "Glaive-Guisarme") ++bad;
                    if (std::string(rules::uahhName(21))
                        != "Guisarme") ++bad;
                    if (std::string(rules::uahhName(22))
                        != "Guisarme-Voulge") ++bad;
                    if (std::string(rules::uahhName(23))
                        != "Halberd") ++bad;
                    if (std::string(rules::uahhName(24))
                        != "Harpoon") ++bad;
                    if (std::string(rules::uahhName(25))
                        != "Hammer, Lucern") ++bad;
                    if (std::string(rules::uahhName(26))
                        != "Hammer") ++bad;
                    if (std::string(rules::uahhName(27))
                        != "Hook Fauchard") ++bad;
                    if (std::string(rules::uahhName(28))
                        != "Jo Stick") ++bad;
                    if (std::string(rules::uahhName(29))
                        != "Knife") ++bad;
                    if (std::string(rules::uahhName(30))
                        != "Lance (light horse)") ++bad;
                    if (std::string(rules::uahhName(31))
                        != "Lance (medium horse)") ++bad;
                    if (std::string(rules::uahhName(32))
                        != "Lance (heavy horse)") ++bad;
                    if (std::string(rules::uahhName(33))
                        != "Lasso") ++bad;
                    if (std::string(rules::uahhName(34))
                        != "Mace, Footman's") ++bad;
                    if (std::string(rules::uahhName(35))
                        != "Mace, Horseman's") ++bad;
                    if (std::string(rules::uahhName(36))
                        != "Man Catcher") ++bad;
                    if (std::string(rules::uahhName(37))
                        != "Morning Star") ++bad;
                    if (std::string(rules::uahhName(38))
                        != "Partisan") ++bad;
                    if (std::string(rules::uahhName(39))
                        != "Pick, Military, Footman's") ++bad;
                    if (std::string(rules::uahhName(40))
                        != "Pick, Military, Horseman's") ++bad;
                    if (std::string(rules::uahhName(41))
                        != "Pike, Awl") ++bad;
                    if (std::string(rules::uahhName(42))
                        != "Ranseur") ++bad;
                    if (std::string(rules::uahhName(43))
                        != "Sap") ++bad;
                    if (std::string(rules::uahhName(44))
                        != "Scimitar") ++bad;
                    if (std::string(rules::uahhName(45))
                        != "Spear") ++bad;
                    if (std::string(rules::uahhName(46))
                        != "Spetum") ++bad;
                    if (std::string(rules::uahhName(47))
                        != "Spiked Buckler") ++bad;
                    if (std::string(rules::uahhName(48))
                        != "Staff, Quarter") ++bad;
                    if (std::string(rules::uahhName(49))
                        != "Staff Sling") ++bad;
                    if (std::string(rules::uahhName(50))
                        != "Sword, Bastard") ++bad;
                    if (std::string(rules::uahhName(51))
                        != "Sword, Broad") ++bad;
                    if (std::string(rules::uahhName(52))
                        != "Sword, Falchion") ++bad;
                    if (std::string(rules::uahhName(53))
                        != "Sword, Khopesh") ++bad;
                    if (std::string(rules::uahhName(54))
                        != "Sword, Long") ++bad;
                    if (std::string(rules::uahhName(55))
                        != "Sword, Short") ++bad;
                    if (std::string(rules::uahhName(56))
                        != "Sword, Two-handed") ++bad;
                    if (std::string(rules::uahhName(57))
                        != "Trident") ++bad;
                    if (std::string(rules::uahhName(58))
                        != "Voulge") ++bad;
                    if (std::string(rules::uahhName(59))
                        != "Whip") ++bad;
                    if (rules::uahhSpeedFactorMin(0) != 4) ++bad;
                    if (rules::uahhSpeedFactorMin(1) != -1) ++bad;
                    if (rules::uahhSpeedFactorMin(2) != 7) ++bad;
                    if (rules::uahhSpeedFactorMin(3) != 4) ++bad;
                    if (rules::uahhSpeedFactorMin(4) != 9) ++bad;
                    if (rules::uahhSpeedFactorMin(5) != 9) ++bad;
                    if (rules::uahhSpeedFactorMin(6) != 10) ++bad;
                    if (rules::uahhSpeedFactorMin(7) != -1) ++bad;
                    if (rules::uahhSpeedFactorMin(8) != 3) ++bad;
                    if (rules::uahhSpeedFactorMin(9) != -1) ++bad;
                    if (rules::uahhSpeedFactorMin(10) != 4) ++bad;
                    if (rules::uahhSpeedFactorMin(11) != 2) ++bad;
                    if (rules::uahhSpeedFactorMin(12) != 8) ++bad;
                    if (rules::uahhSpeedFactorMin(13) != 8) ++bad;
                    if (rules::uahhSpeedFactorMin(14) != 1) ++bad;
                    if (rules::uahhSpeedFactorMin(15) != 7) ++bad;
                    if (rules::uahhSpeedFactorMin(16) != 6) ++bad;
                    if (rules::uahhSpeedFactorMin(17) != 7) ++bad;
                    if (rules::uahhSpeedFactorMin(18) != 2) ++bad;
                    if (rules::uahhSpeedFactorMin(19) != 8) ++bad;
                    if (rules::uahhSpeedFactorMin(20) != 9) ++bad;
                    if (rules::uahhSpeedFactorMin(21) != 8) ++bad;
                    if (rules::uahhSpeedFactorMin(22) != 10) ++bad;
                    if (rules::uahhSpeedFactorMin(23) != 9) ++bad;
                    if (rules::uahhSpeedFactorMin(24) != 6) ++bad;
                    if (rules::uahhSpeedFactorMin(25) != 9) ++bad;
                    if (rules::uahhSpeedFactorMin(26) != 4) ++bad;
                    if (rules::uahhSpeedFactorMin(27) != 9) ++bad;
                    if (rules::uahhSpeedFactorMin(28) != 2) ++bad;
                    if (rules::uahhSpeedFactorMin(29) != 2) ++bad;
                    if (rules::uahhSpeedFactorMin(30) != 7) ++bad;
                    if (rules::uahhSpeedFactorMin(31) != 6) ++bad;
                    if (rules::uahhSpeedFactorMin(32) != 8) ++bad;
                    if (rules::uahhSpeedFactorMin(33) != 10) ++bad;
                    if (rules::uahhSpeedFactorMin(34) != 7) ++bad;
                    if (rules::uahhSpeedFactorMin(35) != 6) ++bad;
                    if (rules::uahhSpeedFactorMin(36) != 7) ++bad;
                    if (rules::uahhSpeedFactorMin(37) != 7) ++bad;
                    if (rules::uahhSpeedFactorMin(38) != 9) ++bad;
                    if (rules::uahhSpeedFactorMin(39) != 7) ++bad;
                    if (rules::uahhSpeedFactorMin(40) != 5) ++bad;
                    if (rules::uahhSpeedFactorMin(41) != 13) ++bad;
                    if (rules::uahhSpeedFactorMin(42) != 8) ++bad;
                    if (rules::uahhSpeedFactorMin(43) != 2) ++bad;
                    if (rules::uahhSpeedFactorMin(44) != 4) ++bad;
                    if (rules::uahhSpeedFactorMin(45) != 6) ++bad;
                    if (rules::uahhSpeedFactorMin(46) != 8) ++bad;
                    if (rules::uahhSpeedFactorMin(47) != 4) ++bad;
                    if (rules::uahhSpeedFactorMin(48) != 4) ++bad;
                    if (rules::uahhSpeedFactorMin(49) != 11) ++bad;
                    if (rules::uahhSpeedFactorMin(50) != 6) ++bad;
                    if (rules::uahhSpeedFactorMin(51) != 5) ++bad;
                    if (rules::uahhSpeedFactorMin(52) != 5) ++bad;
                    if (rules::uahhSpeedFactorMin(53) != 9) ++bad;
                    if (rules::uahhSpeedFactorMin(54) != 5) ++bad;
                    if (rules::uahhSpeedFactorMin(55) != 3) ++bad;
                    if (rules::uahhSpeedFactorMin(56) != 10) ++bad;
                    if (rules::uahhSpeedFactorMin(57) != 6) ++bad;
                    if (rules::uahhSpeedFactorMin(58) != 10) ++bad;
                    if (rules::uahhSpeedFactorMin(59) != 5) ++bad;
                    if (rules::uahhSpeedFactorMax(0) != 4) ++bad;
                    if (rules::uahhSpeedFactorMax(1) != -1) ++bad;
                    if (rules::uahhSpeedFactorMax(2) != 7) ++bad;
                    if (rules::uahhSpeedFactorMax(3) != 4) ++bad;
                    if (rules::uahhSpeedFactorMax(4) != 9) ++bad;
                    if (rules::uahhSpeedFactorMax(5) != 9) ++bad;
                    if (rules::uahhSpeedFactorMax(6) != 10) ++bad;
                    if (rules::uahhSpeedFactorMax(7) != -1) ++bad;
                    if (rules::uahhSpeedFactorMax(8) != 3) ++bad;
                    if (rules::uahhSpeedFactorMax(9) != -1) ++bad;
                    if (rules::uahhSpeedFactorMax(10) != 4) ++bad;
                    if (rules::uahhSpeedFactorMax(11) != 2) ++bad;
                    if (rules::uahhSpeedFactorMax(12) != 8) ++bad;
                    if (rules::uahhSpeedFactorMax(13) != 8) ++bad;
                    if (rules::uahhSpeedFactorMax(14) != 1) ++bad;
                    if (rules::uahhSpeedFactorMax(15) != 7) ++bad;
                    if (rules::uahhSpeedFactorMax(16) != 6) ++bad;
                    if (rules::uahhSpeedFactorMax(17) != 7) ++bad;
                    if (rules::uahhSpeedFactorMax(18) != 2) ++bad;
                    if (rules::uahhSpeedFactorMax(19) != 8) ++bad;
                    if (rules::uahhSpeedFactorMax(20) != 9) ++bad;
                    if (rules::uahhSpeedFactorMax(21) != 8) ++bad;
                    if (rules::uahhSpeedFactorMax(22) != 10) ++bad;
                    if (rules::uahhSpeedFactorMax(23) != 9) ++bad;
                    if (rules::uahhSpeedFactorMax(24) != 6) ++bad;
                    if (rules::uahhSpeedFactorMax(25) != 9) ++bad;
                    if (rules::uahhSpeedFactorMax(26) != 4) ++bad;
                    if (rules::uahhSpeedFactorMax(27) != 9) ++bad;
                    if (rules::uahhSpeedFactorMax(28) != 2) ++bad;
                    if (rules::uahhSpeedFactorMax(29) != 2) ++bad;
                    if (rules::uahhSpeedFactorMax(30) != 7) ++bad;
                    if (rules::uahhSpeedFactorMax(31) != 6) ++bad;
                    if (rules::uahhSpeedFactorMax(32) != 8) ++bad;
                    if (rules::uahhSpeedFactorMax(33) != 10) ++bad;
                    if (rules::uahhSpeedFactorMax(34) != 7) ++bad;
                    if (rules::uahhSpeedFactorMax(35) != 6) ++bad;
                    if (rules::uahhSpeedFactorMax(36) != 7) ++bad;
                    if (rules::uahhSpeedFactorMax(37) != 7) ++bad;
                    if (rules::uahhSpeedFactorMax(38) != 9) ++bad;
                    if (rules::uahhSpeedFactorMax(39) != 7) ++bad;
                    if (rules::uahhSpeedFactorMax(40) != 5) ++bad;
                    if (rules::uahhSpeedFactorMax(41) != 13) ++bad;
                    if (rules::uahhSpeedFactorMax(42) != 8) ++bad;
                    if (rules::uahhSpeedFactorMax(43) != 2) ++bad;
                    if (rules::uahhSpeedFactorMax(44) != 4) ++bad;
                    if (rules::uahhSpeedFactorMax(45) != 8) ++bad;
                    if (rules::uahhSpeedFactorMax(46) != 8) ++bad;
                    if (rules::uahhSpeedFactorMax(47) != 4) ++bad;
                    if (rules::uahhSpeedFactorMax(48) != 4) ++bad;
                    if (rules::uahhSpeedFactorMax(49) != 11) ++bad;
                    if (rules::uahhSpeedFactorMax(50) != 6) ++bad;
                    if (rules::uahhSpeedFactorMax(51) != 5) ++bad;
                    if (rules::uahhSpeedFactorMax(52) != 5) ++bad;
                    if (rules::uahhSpeedFactorMax(53) != 9) ++bad;
                    if (rules::uahhSpeedFactorMax(54) != 5) ++bad;
                    if (rules::uahhSpeedFactorMax(55) != 3) ++bad;
                    if (rules::uahhSpeedFactorMax(56) != 10) ++bad;
                    if (rules::uahhSpeedFactorMax(57) != 8) ++bad;
                    if (rules::uahhSpeedFactorMax(58) != 10) ++bad;
                    if (rules::uahhSpeedFactorMax(59) != 8) ++bad;
                    if (rules::uahhSetDoubleFlag(0) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(1) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(2) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(3) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(4) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(5) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(6) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(7) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(8) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(9) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(10) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(11) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(12) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(13) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(14) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(15) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(16) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(17) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(18) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(19) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(20) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(21) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(22) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(23) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(24) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(25) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(26) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(27) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(28) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(29) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(30) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(31) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(32) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(33) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(34) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(35) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(36) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(37) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(38) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(39) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(40) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(41) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(42) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(43) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(44) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(45) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(46) != 1) ++bad;
                    if (rules::uahhSetDoubleFlag(47) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(48) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(49) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(50) != 1) ++bad;
                    if (rules::uahhSetDoubleFlag(51) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(52) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(53) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(54) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(55) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(56) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(57) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(58) != 0) ++bad;
                    if (rules::uahhSetDoubleFlag(59) != 0) ++bad;
                    if (rules::uahhDismountFlag(0) != 0) ++bad;
                    if (rules::uahhDismountFlag(1) != 0) ++bad;
                    if (rules::uahhDismountFlag(2) != 0) ++bad;
                    if (rules::uahhDismountFlag(3) != 0) ++bad;
                    if (rules::uahhDismountFlag(4) != 0) ++bad;
                    if (rules::uahhDismountFlag(5) != 0) ++bad;
                    if (rules::uahhDismountFlag(6) != 0) ++bad;
                    if (rules::uahhDismountFlag(7) != 0) ++bad;
                    if (rules::uahhDismountFlag(8) != 0) ++bad;
                    if (rules::uahhDismountFlag(9) != 0) ++bad;
                    if (rules::uahhDismountFlag(10) != 0) ++bad;
                    if (rules::uahhDismountFlag(11) != 0) ++bad;
                    if (rules::uahhDismountFlag(12) != 1) ++bad;
                    if (rules::uahhDismountFlag(13) != 1) ++bad;
                    if (rules::uahhDismountFlag(14) != 0) ++bad;
                    if (rules::uahhDismountFlag(15) != 0) ++bad;
                    if (rules::uahhDismountFlag(16) != 0) ++bad;
                    if (rules::uahhDismountFlag(17) != 1) ++bad;
                    if (rules::uahhDismountFlag(18) != 0) ++bad;
                    if (rules::uahhDismountFlag(19) != 0) ++bad;
                    if (rules::uahhDismountFlag(20) != 1) ++bad;
                    if (rules::uahhDismountFlag(21) != 1) ++bad;
                    if (rules::uahhDismountFlag(22) != 1) ++bad;
                    if (rules::uahhDismountFlag(23) != 0) ++bad;
                    if (rules::uahhDismountFlag(24) != 0) ++bad;
                    if (rules::uahhDismountFlag(25) != 1) ++bad;
                    if (rules::uahhDismountFlag(26) != 0) ++bad;
                    if (rules::uahhDismountFlag(27) != 0) ++bad;
                    if (rules::uahhDismountFlag(28) != 0) ++bad;
                    if (rules::uahhDismountFlag(29) != 0) ++bad;
                    if (rules::uahhDismountFlag(30) != 0) ++bad;
                    if (rules::uahhDismountFlag(31) != 0) ++bad;
                    if (rules::uahhDismountFlag(32) != 0) ++bad;
                    if (rules::uahhDismountFlag(33) != 0) ++bad;
                    if (rules::uahhDismountFlag(34) != 0) ++bad;
                    if (rules::uahhDismountFlag(35) != 0) ++bad;
                    if (rules::uahhDismountFlag(36) != 0) ++bad;
                    if (rules::uahhDismountFlag(37) != 0) ++bad;
                    if (rules::uahhDismountFlag(38) != 0) ++bad;
                    if (rules::uahhDismountFlag(39) != 0) ++bad;
                    if (rules::uahhDismountFlag(40) != 0) ++bad;
                    if (rules::uahhDismountFlag(41) != 0) ++bad;
                    if (rules::uahhDismountFlag(42) != 1) ++bad;
                    if (rules::uahhDismountFlag(43) != 0) ++bad;
                    if (rules::uahhDismountFlag(44) != 0) ++bad;
                    if (rules::uahhDismountFlag(45) != 0) ++bad;
                    if (rules::uahhDismountFlag(46) != 0) ++bad;
                    if (rules::uahhDismountFlag(47) != 0) ++bad;
                    if (rules::uahhDismountFlag(48) != 0) ++bad;
                    if (rules::uahhDismountFlag(49) != 0) ++bad;
                    if (rules::uahhDismountFlag(50) != 0) ++bad;
                    if (rules::uahhDismountFlag(51) != 0) ++bad;
                    if (rules::uahhDismountFlag(52) != 0) ++bad;
                    if (rules::uahhDismountFlag(53) != 0) ++bad;
                    if (rules::uahhDismountFlag(54) != 0) ++bad;
                    if (rules::uahhDismountFlag(55) != 0) ++bad;
                    if (rules::uahhDismountFlag(56) != 0) ++bad;
                    if (rules::uahhDismountFlag(57) != 0) ++bad;
                    if (rules::uahhDismountFlag(58) != 0) ++bad;
                    if (rules::uahhDismountFlag(59) != 0) ++bad;
                    if (rules::uahhAcAdjustment(0, 0) != -7)
                        ++bad;
                    if (rules::uahhAcAdjustment(0, 10) != 1)
                        ++bad;
                    if (rules::uahhAcAdjustment(59, 0) != -14)
                        ++bad;
                    if (rules::uahhAcAdjustment(59, 10) != 3)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("uahh_length");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uahhLength(0))
                        != "c. 2'") ++bad;
                    if (std::string(rules::uahhLength(1))
                        != "c. 3'") ++bad;
                    if (std::string(rules::uahhLength(2))
                        != "c. 4'") ++bad;
                    if (std::string(rules::uahhLength(3))
                        != "c. 1 1/2'") ++bad;
                    if (std::string(rules::uahhLength(4))
                        != "c. 5'") ++bad;
                    if (std::string(rules::uahhLength(5))
                        != "c. 6'") ++bad;
                    if (std::string(rules::uahhLength(6))
                        != "8' +") ++bad;
                    if (std::string(rules::uahhLength(7))
                        != "4'-7'") ++bad;
                    if (std::string(rules::uahhLength(8))
                        != "c. 5'") ++bad;
                    if (std::string(rules::uahhLength(9))
                        != "n/a") ++bad;
                    if (std::string(rules::uahhLength(10))
                        != "c. 3'") ++bad;
                    if (std::string(rules::uahhLength(11))
                        != "c. 15\"") ++bad;
                    if (std::string(rules::uahhLength(12))
                        != "8' +") ++bad;
                    if (std::string(rules::uahhLength(13))
                        != "8'") ++bad;
                    if (std::string(rules::uahhLength(14))
                        != "2' +") ++bad;
                    if (std::string(rules::uahhLength(15))
                        != "c. 4'") ++bad;
                    if (std::string(rules::uahhLength(16))
                        != "c. 2'") ++bad;
                    if (std::string(rules::uahhLength(17))
                        != "7' +") ++bad;
                    if (std::string(rules::uahhLength(18))
                        != "c. 3'") ++bad;
                    if (std::string(rules::uahhLength(19))
                        != "8' +") ++bad;
                    if (std::string(rules::uahhLength(20))
                        != "8' +") ++bad;
                    if (std::string(rules::uahhLength(21))
                        != "6' +") ++bad;
                    if (std::string(rules::uahhLength(22))
                        != "7' +") ++bad;
                    if (std::string(rules::uahhLength(23))
                        != "5' +") ++bad;
                    if (std::string(rules::uahhLength(24))
                        != "6'-8'") ++bad;
                    if (std::string(rules::uahhLength(25))
                        != "5' +") ++bad;
                    if (std::string(rules::uahhLength(26))
                        != "c. 1 1/2'") ++bad;
                    if (std::string(rules::uahhLength(27))
                        != "8' +") ++bad;
                    if (std::string(rules::uahhLength(28))
                        != "c. 3'") ++bad;
                    if (std::string(rules::uahhLength(29))
                        != "c. 1'") ++bad;
                    if (std::string(rules::uahhLength(30))
                        != "10'") ++bad;
                    if (std::string(rules::uahhLength(31))
                        != "12'") ++bad;
                    if (std::string(rules::uahhLength(32))
                        != "c. 14'") ++bad;
                    if (std::string(rules::uahhLength(33))
                        != "(10'-20')") ++bad;
                    if (std::string(rules::uahhLength(34))
                        != "c. 2 1/2'") ++bad;
                    if (std::string(rules::uahhLength(35))
                        != "c. 1 1/2'") ++bad;
                    if (std::string(rules::uahhLength(36))
                        != "8' +") ++bad;
                    if (std::string(rules::uahhLength(37))
                        != "c. 4'") ++bad;
                    if (std::string(rules::uahhLength(38))
                        != "7' +") ++bad;
                    if (std::string(rules::uahhLength(39))
                        != "c. 4'") ++bad;
                    if (std::string(rules::uahhLength(40))
                        != "c. 2'") ++bad;
                    if (std::string(rules::uahhLength(41))
                        != "18'") ++bad;
                    if (std::string(rules::uahhLength(42))
                        != "8' +") ++bad;
                    if (std::string(rules::uahhLength(43))
                        != "1/2'") ++bad;
                    if (std::string(rules::uahhLength(44))
                        != "c. 3'") ++bad;
                    if (std::string(rules::uahhLength(45))
                        != "5'-13' +") ++bad;
                    if (std::string(rules::uahhLength(46))
                        != "8' +") ++bad;
                    if (std::string(rules::uahhLength(47))
                        != "1'") ++bad;
                    if (std::string(rules::uahhLength(48))
                        != "6'-8'") ++bad;
                    if (std::string(rules::uahhLength(49))
                        != "5'") ++bad;
                    if (std::string(rules::uahhLength(50))
                        != "c. 4 1/2'") ++bad;
                    if (std::string(rules::uahhLength(51))
                        != "c. 3 1/2'") ++bad;
                    if (std::string(rules::uahhLength(52))
                        != "c. 3 1/2'") ++bad;
                    if (std::string(rules::uahhLength(53))
                        != "c. 3 1/2'") ++bad;
                    if (std::string(rules::uahhLength(54))
                        != "c. 3 1/2'") ++bad;
                    if (std::string(rules::uahhLength(55))
                        != "c. 2'") ++bad;
                    if (std::string(rules::uahhLength(56))
                        != "c. 6'") ++bad;
                    if (std::string(rules::uahhLength(57))
                        != "4'-8' +") ++bad;
                    if (std::string(rules::uahhLength(58))
                        != "8' +") ++bad;
                    if (std::string(rules::uahhLength(59))
                        != "8'-20'") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("uahh_space");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uahhSpaceRequired(0))
                        != "2'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(1))
                        != "1'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(2))
                        != "4'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(3))
                        != "1'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(4))
                        != "5'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(5))
                        != "6'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(6))
                        != "2'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(7))
                        != "1'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(8))
                        != "3'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(9))
                        != "n/a") ++bad;
                    if (std::string(rules::uahhSpaceRequired(10))
                        != "1'-3'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(11))
                        != "1'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(12))
                        != "2'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(13))
                        != "2'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(14))
                        != "n/a") ++bad;
                    if (std::string(rules::uahhSpaceRequired(15))
                        != "6'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(16))
                        != "4'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(17))
                        != "1'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(18))
                        != "1 1/2'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(19))
                        != "1'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(20))
                        != "1'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(21))
                        != "2'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(22))
                        != "2'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(23))
                        != "5'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(24))
                        != "1 1/2'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(25))
                        != "5'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(26))
                        != "2'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(27))
                        != "2 1/2'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(28))
                        != "2'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(29))
                        != "1'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(30))
                        != "1'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(31))
                        != "1'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(32))
                        != "1'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(33))
                        != "8' +") ++bad;
                    if (std::string(rules::uahhSpaceRequired(34))
                        != "4'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(35))
                        != "2'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(36))
                        != "2 1/2'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(37))
                        != "5'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(38))
                        != "3'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(39))
                        != "4'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(40))
                        != "2'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(41))
                        != "1'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(42))
                        != "1'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(43))
                        != "1'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(44))
                        != "2'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(45))
                        != "1'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(46))
                        != "1'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(47))
                        != "2'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(48))
                        != "3'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(49))
                        != "6'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(50))
                        != "4' +") ++bad;
                    if (std::string(rules::uahhSpaceRequired(51))
                        != "4'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(52))
                        != "3 1/2'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(53))
                        != "4'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(54))
                        != "3'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(55))
                        != "1'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(56))
                        != "6'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(57))
                        != "1'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(58))
                        != "2'") ++bad;
                    if (std::string(rules::uahhSpaceRequired(59))
                        != "8'-20'") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("uanw");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 1) ++bad;
                    if (d->tables[0]
                        .values[1] != 1) ++bad;
                    if (d->tables[0]
                        .values[2] != 1) ++bad;
                    if (d->tables[0]
                        .values[3] != 1) ++bad;
                    if (d->tables[0]
                        .values[4] != 0) ++bad;
                    if (d->tables[0]
                        .values[5] != 1) ++bad;
                    if (d->tables[0]
                        .values[6] != 1) ++bad;
                    if (d->tables[0]
                        .values[7] != 1) ++bad;
                    if (d->tables[0]
                        .values[8] != 1) ++bad;
                    if (d->tables[0]
                        .values[9] != 1) ++bad;
                    if (d->tables[0]
                        .values[10] != 1) ++bad;
                    if (d->tables[0]
                        .values[11] != 1) ++bad;
                    if (d->tables[0]
                        .values[12] != 1) ++bad;
                    if (d->tables[0]
                        .values[13] != 0) ++bad;
                    if (d->tables[0]
                        .values[14] != 1) ++bad;
                    if (d->tables[0]
                        .values[15] != 1) ++bad;
                    if (std::string(rules::uanwName(0))
                        != "Aklys") ++bad;
                    if (std::string(rules::uanwName(1))
                        != "Atlatl") ++bad;
                    if (std::string(rules::uanwName(2))
                        != "Blowgun") ++bad;
                    if (std::string(rules::uanwName(3))
                        != "Caltrop") ++bad;
                    if (std::string(rules::uanwName(4))
                        != "Crossbow, Hand-held") ++bad;
                    if (std::string(rules::uanwName(5))
                        != "Garrot") ++bad;
                    if (std::string(rules::uanwName(6))
                        != "Harpoon") ++bad;
                    if (std::string(rules::uanwName(7))
                        != "Hook Fauchard") ++bad;
                    if (std::string(rules::uanwName(8))
                        != "Lasso") ++bad;
                    if (std::string(rules::uanwName(9))
                        != "Man Catcher") ++bad;
                    if (std::string(rules::uanwName(10))
                        != "Sap") ++bad;
                    if (std::string(rules::uanwName(11))
                        != "Spiked Buckler") ++bad;
                    if (std::string(rules::uanwName(12))
                        != "Staff Sling") ++bad;
                    if (std::string(rules::uanwName(13))
                        != "Sword, Falchion") ++bad;
                    if (std::string(rules::uanwName(14))
                        != "Sword, Khopesh") ++bad;
                    if (std::string(rules::uanwName(15))
                        != "Whip") ++bad;
                    if (rules::uanwInGapItemList(0) != 1) ++bad;
                    if (rules::uanwInGapItemList(1) != 1) ++bad;
                    if (rules::uanwInGapItemList(2) != 1) ++bad;
                    if (rules::uanwInGapItemList(3) != 1) ++bad;
                    if (rules::uanwInGapItemList(4) != 0) ++bad;
                    if (rules::uanwInGapItemList(5) != 1) ++bad;
                    if (rules::uanwInGapItemList(6) != 1) ++bad;
                    if (rules::uanwInGapItemList(7) != 1) ++bad;
                    if (rules::uanwInGapItemList(8) != 1) ++bad;
                    if (rules::uanwInGapItemList(9) != 1) ++bad;
                    if (rules::uanwInGapItemList(10) != 1) ++bad;
                    if (rules::uanwInGapItemList(11) != 1) ++bad;
                    if (rules::uanwInGapItemList(12) != 1) ++bad;
                    if (rules::uanwInGapItemList(13) != 0) ++bad;
                    if (rules::uanwInGapItemList(14) != 1) ++bad;
                    if (rules::uanwInGapItemList(15) != 1) ++bad;
                }
            }
        }
        printf("R1058 weapons registry defs-B audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 5. C -----------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/weapondata");
            {
                const items::MiscItemDef* d =
                    reg.find("wspec_cols");
                if (!d) { ++bad; } else {
                    if (std::string(rules::weaponSpecTableColumnName(0))
                        != "Melee Weapon") ++bad;
                    if (std::string(rules::weaponSpecTableColumnName(1))
                        != "Bow") ++bad;
                    if (std::string(rules::weaponSpecTableColumnName(2))
                        != "Light Crossbow") ++bad;
                    if (std::string(rules::weaponSpecTableColumnName(3))
                        != "Heavy Crossbow") ++bad;
                    if (std::string(rules::weaponSpecTableColumnName(4))
                        != "Lasso and Staff Sling") ++bad;
                    if (std::string(rules::weaponSpecTableColumnName(5))
                        != "Thrown Dagger") ++bad;
                    if (std::string(rules::weaponSpecTableColumnName(6))
                        != "Thrown Dart") ++bad;
                    if (std::string(rules::weaponSpecTableColumnName(7))
                        != "Other Missiles and Hurled Weapons") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("wspec");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 6) ++bad;
                    if (d->tables[0]
                        .values[1] != 12) ++bad;
                    if (d->tables[0]
                        .values[2] != 0) ++bad;
                    if (d->tables[1]
                        .values[0] != 1) ++bad;
                    if (d->tables[1]
                        .values[1] != 7) ++bad;
                    if (d->tables[1]
                        .values[2] != 13) ++bad;
                    if (rules::weaponSpecTableBandLow(0) != 1) ++bad;
                    if (rules::weaponSpecTableBandLow(1) != 7) ++bad;
                    if (rules::weaponSpecTableBandLow(2) != 13) ++bad;
                    if (rules::weaponSpecTableBandHigh(0) != 6) ++bad;
                    if (rules::weaponSpecTableBandHigh(1) != 12) ++bad;
                    if (rules::weaponSpecTableBandHigh(2) != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("wspec_cells");
                if (!d) { ++bad; } else {
                    if (std::string(rules::weaponSpecTableCellKnown(0, 0))
                        != "3/2") ++bad;
                    if (std::string(rules::weaponSpecTableCellKnown(0, 1))
                        != "2/1") ++bad;
                    if (std::string(rules::weaponSpecTableCellKnown(0, 2))
                        != "1/1") ++bad;
                    if (std::string(rules::weaponSpecTableCellKnown(0, 3))
                        != "1/2") ++bad;
                    if (std::string(rules::weaponSpecTableCellKnown(0, 4))
                        != "1/1") ++bad;
                    if (std::string(rules::weaponSpecTableCellKnown(0, 5))
                        != "3/1") ++bad;
                    if (std::string(rules::weaponSpecTableCellKnown(0, 6))
                        != "4/1") ++bad;
                    if (std::string(rules::weaponSpecTableCellKnown(0, 7))
                        != "3/2") ++bad;
                    if (std::string(rules::weaponSpecTableCellKnown(1, 0))
                        != "2/1") ++bad;
                    if (std::string(rules::weaponSpecTableCellKnown(1, 1))
                        != "3/1") ++bad;
                    if (std::string(rules::weaponSpecTableCellKnown(1, 2))
                        != "3/2") ++bad;
                    if (std::string(rules::weaponSpecTableCellKnown(1, 3))
                        != "1/1") ++bad;
                    if (std::string(rules::weaponSpecTableCellKnown(1, 4))
                        != "3/2") ++bad;
                    if (std::string(rules::weaponSpecTableCellKnown(1, 5))
                        != "4/1") ++bad;
                    if (std::string(rules::weaponSpecTableCellKnown(1, 6))
                        != "5/1") ++bad;
                    if (std::string(rules::weaponSpecTableCellKnown(1, 7))
                        != "2/1") ++bad;
                    if (std::string(rules::weaponSpecTableCellKnown(2, 0))
                        != "5/2") ++bad;
                    if (std::string(rules::weaponSpecTableCellKnown(2, 1))
                        != "4/1") ++bad;
                    if (std::string(rules::weaponSpecTableCellKnown(2, 2))
                        != "2/1") ++bad;
                    if (std::string(rules::weaponSpecTableCellKnown(2, 3))
                        != "3/2") ++bad;
                    if (std::string(rules::weaponSpecTableCellKnown(2, 4))
                        != "2/1") ++bad;
                    if (std::string(rules::weaponSpecTableCellKnown(2, 5))
                        != "5/1") ++bad;
                    if (std::string(rules::weaponSpecTableCellKnown(2, 6))
                        != "6/1") ++bad;
                    if (std::string(rules::weaponSpecTableCellKnown(2, 7))
                        != "5/2") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("uapf");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 2) ++bad;
                    if (d->tables[0]
                        .values[1] != 2) ++bad;
                    if (d->tables[0]
                        .values[2] != 4) ++bad;
                    if (d->tables[0]
                        .values[3] != 5) ++bad;
                    if (d->tables[0]
                        .values[4] != 3) ++bad;
                    if (d->tables[0]
                        .values[5] != 2) ++bad;
                    if (d->tables[0]
                        .values[6] != 3) ++bad;
                    if (d->tables[0]
                        .values[7] != 6) ++bad;
                    if (d->tables[0]
                        .values[8] != 6) ++bad;
                    if (d->tables[0]
                        .values[9] != 4) ++bad;
                    if (d->tables[0]
                        .values[10] != 4) ++bad;
                    if (d->tables[0]
                        .values[11] != 4) ++bad;
                    if (d->tables[0]
                        .values[12] != 2) ++bad;
                    if (d->tables[0]
                        .values[13] != 4) ++bad;
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
                        .values[8] != 1) ++bad;
                    if (d->tables[1]
                        .values[9] != 1) ++bad;
                    if (d->tables[1]
                        .values[10] != 0) ++bad;
                    if (d->tables[1]
                        .values[11] != 1) ++bad;
                    if (d->tables[1]
                        .values[12] != 0) ++bad;
                    if (d->tables[1]
                        .values[13] != 0) ++bad;
                    if (d->tables[2]
                        .values[0] != 1) ++bad;
                    if (d->tables[2]
                        .values[1] != 1) ++bad;
                    if (d->tables[2]
                        .values[2] != 0) ++bad;
                    if (d->tables[2]
                        .values[3] != 0) ++bad;
                    if (d->tables[2]
                        .values[4] != 0) ++bad;
                    if (d->tables[2]
                        .values[5] != 0) ++bad;
                    if (d->tables[2]
                        .values[6] != 1) ++bad;
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
                    if (d->tables[3]
                        .values[0] != 3) ++bad;
                    if (d->tables[3]
                        .values[1] != 3) ++bad;
                    if (d->tables[3]
                        .values[2] != 2) ++bad;
                    if (d->tables[3]
                        .values[3] != 2) ++bad;
                    if (d->tables[3]
                        .values[4] != 4) ++bad;
                    if (d->tables[3]
                        .values[5] != 6) ++bad;
                    if (d->tables[3]
                        .values[6] != 3) ++bad;
                    if (d->tables[3]
                        .values[7] != 1) ++bad;
                    if (d->tables[3]
                        .values[8] != 1) ++bad;
                    if (d->tables[3]
                        .values[9] != 2) ++bad;
                    if (d->tables[3]
                        .values[10] != 2) ++bad;
                    if (d->tables[3]
                        .values[11] != 3) ++bad;
                    if (d->tables[3]
                        .values[12] != 1) ++bad;
                    if (d->tables[3]
                        .values[13] != 5) ++bad;
                    if (d->tables[4]
                        .values[0] != 3) ++bad;
                    if (d->tables[4]
                        .values[1] != 3) ++bad;
                    if (d->tables[4]
                        .values[2] != 3) ++bad;
                    if (d->tables[4]
                        .values[3] != 4) ++bad;
                    if (d->tables[4]
                        .values[4] != 2) ++bad;
                    if (d->tables[4]
                        .values[5] != 1) ++bad;
                    if (d->tables[4]
                        .values[6] != 2) ++bad;
                    if (d->tables[4]
                        .values[7] != 5) ++bad;
                    if (d->tables[4]
                        .values[8] != 5) ++bad;
                    if (d->tables[4]
                        .values[9] != 3) ++bad;
                    if (d->tables[4]
                        .values[10] != 3) ++bad;
                    if (d->tables[4]
                        .values[11] != 2) ++bad;
                    if (d->tables[4]
                        .values[12] != 3) ++bad;
                    if (d->tables[4]
                        .values[13] != 2) ++bad;
                    if (d->tables[5]
                        .values[0] != -1) ++bad;
                    if (d->tables[5]
                        .values[1] != 3) ++bad;
                    if (d->tables[5]
                        .values[2] != 0) ++bad;
                    if (d->tables[5]
                        .values[3] != 1) ++bad;
                    if (d->tables[5]
                        .values[4] != 2) ++bad;
                    if (d->tables[5]
                        .values[5] != -1) ++bad;
                    if (d->tables[5]
                        .values[6] != 4) ++bad;
                    if (d->tables[5]
                        .values[7] != 5) ++bad;
                    if (d->tables[5]
                        .values[8] != 6) ++bad;
                    if (d->tables[5]
                        .values[9] != 7) ++bad;
                    if (d->tables[5]
                        .values[10] != 7) ++bad;
                    if (d->tables[5]
                        .values[11] != 8) ++bad;
                    if (d->tables[5]
                        .values[12] != 9) ++bad;
                    if (d->tables[5]
                        .values[13] != -1) ++bad;
                    if (std::string(rules::uapfName(0))
                        != "Cavalier") ++bad;
                    if (std::string(rules::uapfName(1))
                        != "Paladin") ++bad;
                    if (std::string(rules::uapfName(2))
                        != "Cleric") ++bad;
                    if (std::string(rules::uapfName(3))
                        != "Druid") ++bad;
                    if (std::string(rules::uapfName(4))
                        != "Fighter") ++bad;
                    if (std::string(rules::uapfName(5))
                        != "Barbarian") ++bad;
                    if (std::string(rules::uapfName(6))
                        != "Ranger") ++bad;
                    if (std::string(rules::uapfName(7))
                        != "Magic-User") ++bad;
                    if (std::string(rules::uapfName(8))
                        != "Illusionist") ++bad;
                    if (std::string(rules::uapfName(9))
                        != "Thief") ++bad;
                    if (std::string(rules::uapfName(10))
                        != "Acrobat") ++bad;
                    if (std::string(rules::uapfName(11))
                        != "Assassin") ++bad;
                    if (std::string(rules::uapfName(12))
                        != "Monk") ++bad;
                    if (std::string(rules::uapfName(13))
                        != "Bard") ++bad;
                    if (rules::uapfPhbSeamRow(0) != -1) ++bad;
                    if (rules::uapfPhbSeamRow(1) != 3) ++bad;
                    if (rules::uapfPhbSeamRow(2) != 0) ++bad;
                    if (rules::uapfPhbSeamRow(3) != 1) ++bad;
                    if (rules::uapfPhbSeamRow(4) != 2) ++bad;
                    if (rules::uapfPhbSeamRow(5) != -1) ++bad;
                    if (rules::uapfPhbSeamRow(6) != 4) ++bad;
                    if (rules::uapfPhbSeamRow(7) != 5) ++bad;
                    if (rules::uapfPhbSeamRow(8) != 6) ++bad;
                    if (rules::uapfPhbSeamRow(9) != 7) ++bad;
                    if (rules::uapfPhbSeamRow(10) != 7) ++bad;
                    if (rules::uapfPhbSeamRow(11) != 8) ++bad;
                    if (rules::uapfPhbSeamRow(12) != 9) ++bad;
                    if (rules::uapfPhbSeamRow(13) != -1) ++bad;
                    if (rules::uapfNameIsAttributed(0) != 0) ++bad;
                    if (rules::uapfNameIsAttributed(1) != 0) ++bad;
                    if (rules::uapfNameIsAttributed(2) != 0) ++bad;
                    if (rules::uapfNameIsAttributed(3) != 0) ++bad;
                    if (rules::uapfNameIsAttributed(4) != 0) ++bad;
                    if (rules::uapfNameIsAttributed(5) != 0) ++bad;
                    if (rules::uapfNameIsAttributed(6) != 0) ++bad;
                    if (rules::uapfNameIsAttributed(7) != 0) ++bad;
                    if (rules::uapfNameIsAttributed(8) != 1) ++bad;
                    if (rules::uapfNameIsAttributed(9) != 1) ++bad;
                    if (rules::uapfNameIsAttributed(10) != 0) ++bad;
                    if (rules::uapfNameIsAttributed(11) != 1) ++bad;
                    if (rules::uapfNameIsAttributed(12) != 0) ++bad;
                    if (rules::uapfNameIsAttributed(13) != 0) ++bad;
                    if (rules::uapfInitialSlots(0) != 3) ++bad;
                    if (rules::uapfInitialSlots(1) != 3) ++bad;
                    if (rules::uapfInitialSlots(2) != 2) ++bad;
                    if (rules::uapfInitialSlots(3) != 2) ++bad;
                    if (rules::uapfInitialSlots(4) != 4) ++bad;
                    if (rules::uapfInitialSlots(5) != 6) ++bad;
                    if (rules::uapfInitialSlots(6) != 3) ++bad;
                    if (rules::uapfInitialSlots(7) != 1) ++bad;
                    if (rules::uapfInitialSlots(8) != 1) ++bad;
                    if (rules::uapfInitialSlots(9) != 2) ++bad;
                    if (rules::uapfInitialSlots(10) != 2) ++bad;
                    if (rules::uapfInitialSlots(11) != 3) ++bad;
                    if (rules::uapfInitialSlots(12) != 1) ++bad;
                    if (rules::uapfInitialSlots(13) != 5) ++bad;
                    if (rules::uapfNonProfPenalty(0) != 3) ++bad;
                    if (rules::uapfNonProfPenalty(1) != 3) ++bad;
                    if (rules::uapfNonProfPenalty(2) != 3) ++bad;
                    if (rules::uapfNonProfPenalty(3) != 4) ++bad;
                    if (rules::uapfNonProfPenalty(4) != 2) ++bad;
                    if (rules::uapfNonProfPenalty(5) != 1) ++bad;
                    if (rules::uapfNonProfPenalty(6) != 2) ++bad;
                    if (rules::uapfNonProfPenalty(7) != 5) ++bad;
                    if (rules::uapfNonProfPenalty(8) != 5) ++bad;
                    if (rules::uapfNonProfPenalty(9) != 3) ++bad;
                    if (rules::uapfNonProfPenalty(10) != 3) ++bad;
                    if (rules::uapfNonProfPenalty(11) != 2) ++bad;
                    if (rules::uapfNonProfPenalty(12) != 3) ++bad;
                    if (rules::uapfNonProfPenalty(13) != 2) ++bad;
                    if (rules::uapfAddedCadence(0) != 2) ++bad;
                    if (rules::uapfAddedCadence(1) != 2) ++bad;
                    if (rules::uapfAddedCadence(2) != 4) ++bad;
                    if (rules::uapfAddedCadence(3) != 5) ++bad;
                    if (rules::uapfAddedCadence(4) != 3) ++bad;
                    if (rules::uapfAddedCadence(5) != 2) ++bad;
                    if (rules::uapfAddedCadence(6) != 3) ++bad;
                    if (rules::uapfAddedCadence(7) != 6) ++bad;
                    if (rules::uapfAddedCadence(8) != 6) ++bad;
                    if (rules::uapfAddedCadence(9) != 4) ++bad;
                    if (rules::uapfAddedCadence(10) != 4) ++bad;
                    if (rules::uapfAddedCadence(11) != 4) ++bad;
                    if (rules::uapfAddedCadence(12) != 2) ++bad;
                    if (rules::uapfAddedCadence(13) != 4) ++bad;
                    if (rules::uapfInitialAsterisk(0) != 1) ++bad;
                    if (rules::uapfInitialAsterisk(1) != 1) ++bad;
                    if (rules::uapfInitialAsterisk(2) != 0) ++bad;
                    if (rules::uapfInitialAsterisk(3) != 0) ++bad;
                    if (rules::uapfInitialAsterisk(4) != 0) ++bad;
                    if (rules::uapfInitialAsterisk(5) != 0) ++bad;
                    if (rules::uapfInitialAsterisk(6) != 1) ++bad;
                    if (rules::uapfInitialAsterisk(7) != 0) ++bad;
                    if (rules::uapfInitialAsterisk(8) != 0) ++bad;
                    if (rules::uapfInitialAsterisk(9) != 0) ++bad;
                    if (rules::uapfInitialAsterisk(10) != 0) ++bad;
                    if (rules::uapfInitialAsterisk(11) != 0) ++bad;
                    if (rules::uapfInitialAsterisk(12) != 0) ++bad;
                    if (rules::uapfInitialAsterisk(13) != 0) ++bad;
                }
            }
        }
        printf("R1058 weapons registry defs-C audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 6. D -----------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/weapondata");
            {
                const items::MiscItemDef* d =
                    reg.find("mw");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 24) ++bad;
                    if (d->tables[0]
                        .values[1] != 16) ++bad;
                    if (d->tables[0]
                        .values[2] != 12) ++bad;
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
                        .values[9] != 20) ++bad;
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
                    if (d->tables[0]
                        .values[33] != 0) ++bad;
                    if (d->tables[0]
                        .values[34] != 0) ++bad;
                    if (d->tables[0]
                        .values[35] != 0) ++bad;
                    if (d->tables[1]
                        .values[0] != 2) ++bad;
                    if (d->tables[1]
                        .values[1] != 2) ++bad;
                    if (d->tables[1]
                        .values[2] != 2) ++bad;
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
                        .values[9] != 2) ++bad;
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
                        .values[25] != 0) ++bad;
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
                    if (d->tables[1]
                        .values[33] != 0) ++bad;
                    if (d->tables[1]
                        .values[34] != 0) ++bad;
                    if (d->tables[1]
                        .values[35] != 0) ++bad;
                    if (d->tables[2]
                        .values[0] != 8) ++bad;
                    if (d->tables[2]
                        .values[1] != 12) ++bad;
                    if (d->tables[2]
                        .values[2] != 14) ++bad;
                    if (d->tables[2]
                        .values[3] != 15) ++bad;
                    if (d->tables[2]
                        .values[4] != 20) ++bad;
                    if (d->tables[2]
                        .values[5] != 22) ++bad;
                    if (d->tables[2]
                        .values[6] != 23) ++bad;
                    if (d->tables[2]
                        .values[7] != 24) ++bad;
                    if (d->tables[2]
                        .values[8] != 27) ++bad;
                    if (d->tables[2]
                        .values[9] != 32) ++bad;
                    if (d->tables[2]
                        .values[10] != 35) ++bad;
                    if (d->tables[2]
                        .values[11] != 36) ++bad;
                    if (d->tables[2]
                        .values[12] != 37) ++bad;
                    if (d->tables[2]
                        .values[13] != 38) ++bad;
                    if (d->tables[2]
                        .values[14] != 46) ++bad;
                    if (d->tables[2]
                        .values[15] != 50) ++bad;
                    if (d->tables[2]
                        .values[16] != 51) ++bad;
                    if (d->tables[2]
                        .values[17] != 56) ++bad;
                    if (d->tables[2]
                        .values[18] != 60) ++bad;
                    if (d->tables[2]
                        .values[19] != 62) ++bad;
                    if (d->tables[2]
                        .values[20] != 63) ++bad;
                    if (d->tables[2]
                        .values[21] != 64) ++bad;
                    if (d->tables[2]
                        .values[22] != 67) ++bad;
                    if (d->tables[2]
                        .values[23] != 72) ++bad;
                    if (d->tables[2]
                        .values[24] != 75) ++bad;
                    if (d->tables[2]
                        .values[25] != 76) ++bad;
                    if (d->tables[2]
                        .values[26] != 77) ++bad;
                    if (d->tables[2]
                        .values[27] != 80) ++bad;
                    if (d->tables[2]
                        .values[28] != 83) ++bad;
                    if (d->tables[2]
                        .values[29] != 88) ++bad;
                    if (d->tables[2]
                        .values[30] != 89) ++bad;
                    if (d->tables[2]
                        .values[31] != 94) ++bad;
                    if (d->tables[2]
                        .values[32] != 96) ++bad;
                    if (d->tables[2]
                        .values[33] != 97) ++bad;
                    if (d->tables[2]
                        .values[34] != 99) ++bad;
                    if (d->tables[2]
                        .values[35] != 100) ++bad;
                    if (d->tables[3]
                        .values[0] != 1) ++bad;
                    if (d->tables[3]
                        .values[1] != 9) ++bad;
                    if (d->tables[3]
                        .values[2] != 13) ++bad;
                    if (d->tables[3]
                        .values[3] != 15) ++bad;
                    if (d->tables[3]
                        .values[4] != 16) ++bad;
                    if (d->tables[3]
                        .values[5] != 21) ++bad;
                    if (d->tables[3]
                        .values[6] != 23) ++bad;
                    if (d->tables[3]
                        .values[7] != 24) ++bad;
                    if (d->tables[3]
                        .values[8] != 25) ++bad;
                    if (d->tables[3]
                        .values[9] != 28) ++bad;
                    if (d->tables[3]
                        .values[10] != 33) ++bad;
                    if (d->tables[3]
                        .values[11] != 36) ++bad;
                    if (d->tables[3]
                        .values[12] != 37) ++bad;
                    if (d->tables[3]
                        .values[13] != 38) ++bad;
                    if (d->tables[3]
                        .values[14] != 39) ++bad;
                    if (d->tables[3]
                        .values[15] != 47) ++bad;
                    if (d->tables[3]
                        .values[16] != 51) ++bad;
                    if (d->tables[3]
                        .values[17] != 52) ++bad;
                    if (d->tables[3]
                        .values[18] != 57) ++bad;
                    if (d->tables[3]
                        .values[19] != 61) ++bad;
                    if (d->tables[3]
                        .values[20] != 63) ++bad;
                    if (d->tables[3]
                        .values[21] != 64) ++bad;
                    if (d->tables[3]
                        .values[22] != 65) ++bad;
                    if (d->tables[3]
                        .values[23] != 68) ++bad;
                    if (d->tables[3]
                        .values[24] != 73) ++bad;
                    if (d->tables[3]
                        .values[25] != 76) ++bad;
                    if (d->tables[3]
                        .values[26] != 77) ++bad;
                    if (d->tables[3]
                        .values[27] != 78) ++bad;
                    if (d->tables[3]
                        .values[28] != 81) ++bad;
                    if (d->tables[3]
                        .values[29] != 84) ++bad;
                    if (d->tables[3]
                        .values[30] != 89) ++bad;
                    if (d->tables[3]
                        .values[31] != 90) ++bad;
                    if (d->tables[3]
                        .values[32] != 95) ++bad;
                    if (d->tables[3]
                        .values[33] != 97) ++bad;
                    if (d->tables[3]
                        .values[34] != 98) ++bad;
                    if (d->tables[3]
                        .values[35] != 100) ++bad;
                    if (d->tables[4]
                        .values[0] != 120) ++bad;
                    if (d->tables[4]
                        .values[1] != 300) ++bad;
                    if (d->tables[4]
                        .values[2] != 450) ++bad;
                    if (d->tables[4]
                        .values[3] != 2500) ++bad;
                    if (d->tables[4]
                        .values[4] != 1750) ++bad;
                    if (d->tables[4]
                        .values[5] != 3750) ++bad;
                    if (d->tables[4]
                        .values[6] != 4500) ++bad;
                    if (d->tables[4]
                        .values[7] != 7000) ++bad;
                    if (d->tables[4]
                        .values[8] != 2500) ++bad;
                    if (d->tables[4]
                        .values[9] != 300) ++bad;
                    if (d->tables[4]
                        .values[10] != 3500) ++bad;
                    if (d->tables[4]
                        .values[11] != 12000) ++bad;
                    if (d->tables[4]
                        .values[12] != 7500) ++bad;
                    if (d->tables[4]
                        .values[13] != 7500) ++bad;
                    if (d->tables[4]
                        .values[14] != 750) ++bad;
                    if (d->tables[4]
                        .values[15] != 2000) ++bad;
                    if (d->tables[4]
                        .values[16] != 3000) ++bad;
                    if (d->tables[4]
                        .values[17] != 4000) ++bad;
                    if (d->tables[4]
                        .values[18] != 2500) ++bad;
                    if (d->tables[4]
                        .values[19] != 6000) ++bad;
                    if (d->tables[4]
                        .values[20] != 15000) ++bad;
                    if (d->tables[4]
                        .values[21] != 25000) ++bad;
                    if (d->tables[4]
                        .values[22] != 5000) ++bad;
                    if (d->tables[4]
                        .values[23] != 3000) ++bad;
                    if (d->tables[4]
                        .values[24] != 4500) ++bad;
                    if (d->tables[4]
                        .values[25] != 17500) ++bad;
                    if (d->tables[4]
                        .values[26] != 15000) ++bad;
                    if (d->tables[4]
                        .values[27] != 2500) ++bad;
                    if (d->tables[4]
                        .values[28] != 3000) ++bad;
                    if (d->tables[4]
                        .values[29] != 6000) ++bad;
                    if (d->tables[4]
                        .values[30] != 7000) ++bad;
                    if (d->tables[4]
                        .values[31] != 3000) ++bad;
                    if (d->tables[4]
                        .values[32] != 6500) ++bad;
                    if (d->tables[4]
                        .values[33] != 15000) ++bad;
                    if (d->tables[4]
                        .values[34] != 1000) ++bad;
                    if (d->tables[4]
                        .values[35] != 12500) ++bad;
                    if (d->tables[5]
                        .values[0] != 20) ++bad;
                    if (d->tables[5]
                        .values[1] != 50) ++bad;
                    if (d->tables[5]
                        .values[2] != 75) ++bad;
                    if (d->tables[5]
                        .values[3] != 250) ++bad;
                    if (d->tables[5]
                        .values[4] != 300) ++bad;
                    if (d->tables[5]
                        .values[5] != 600) ++bad;
                    if (d->tables[5]
                        .values[6] != 750) ++bad;
                    if (d->tables[5]
                        .values[7] != 1000) ++bad;
                    if (d->tables[5]
                        .values[8] != 400) ++bad;
                    if (d->tables[5]
                        .values[9] != 50) ++bad;
                    if (d->tables[5]
                        .values[10] != 500) ++bad;
                    if (d->tables[5]
                        .values[11] != 2000) ++bad;
                    if (d->tables[5]
                        .values[12] != 1500) ++bad;
                    if (d->tables[5]
                        .values[13] != 1500) ++bad;
                    if (d->tables[5]
                        .values[14] != 100) ++bad;
                    if (d->tables[5]
                        .values[15] != 250) ++bad;
                    if (d->tables[5]
                        .values[16] != 350) ++bad;
                    if (d->tables[5]
                        .values[17] != 450) ++bad;
                    if (d->tables[5]
                        .values[18] != 300) ++bad;
                    if (d->tables[5]
                        .values[19] != 650) ++bad;
                    if (d->tables[5]
                        .values[20] != 1500) ++bad;
                    if (d->tables[5]
                        .values[21] != 2500) ++bad;
                    if (d->tables[5]
                        .values[22] != 750) ++bad;
                    if (d->tables[5]
                        .values[23] != 350) ++bad;
                    if (d->tables[5]
                        .values[24] != 700) ++bad;
                    if (d->tables[5]
                        .values[25] != 1750) ++bad;
                    if (d->tables[5]
                        .values[26] != 1500) ++bad;
                    if (d->tables[5]
                        .values[27] != 350) ++bad;
                    if (d->tables[5]
                        .values[28] != 400) ++bad;
                    if (d->tables[5]
                        .values[29] != 750) ++bad;
                    if (d->tables[5]
                        .values[30] != 700) ++bad;
                    if (d->tables[5]
                        .values[31] != 500) ++bad;
                    if (d->tables[5]
                        .values[32] != 1000) ++bad;
                    if (d->tables[5]
                        .values[33] != 1750) ++bad;
                    if (d->tables[5]
                        .values[34] != 0) ++bad;
                    if (d->tables[5]
                        .values[35] != 1500) ++bad;
                    if (rules::mwRowLo(0) != 1) ++bad;
                    if (rules::mwRowLo(1) != 9) ++bad;
                    if (rules::mwRowLo(2) != 13) ++bad;
                    if (rules::mwRowLo(3) != 15) ++bad;
                    if (rules::mwRowLo(4) != 16) ++bad;
                    if (rules::mwRowLo(5) != 21) ++bad;
                    if (rules::mwRowLo(6) != 23) ++bad;
                    if (rules::mwRowLo(7) != 24) ++bad;
                    if (rules::mwRowLo(8) != 25) ++bad;
                    if (rules::mwRowLo(9) != 28) ++bad;
                    if (rules::mwRowLo(10) != 33) ++bad;
                    if (rules::mwRowLo(11) != 36) ++bad;
                    if (rules::mwRowLo(12) != 37) ++bad;
                    if (rules::mwRowLo(13) != 38) ++bad;
                    if (rules::mwRowLo(14) != 39) ++bad;
                    if (rules::mwRowLo(15) != 47) ++bad;
                    if (rules::mwRowLo(16) != 51) ++bad;
                    if (rules::mwRowLo(17) != 52) ++bad;
                    if (rules::mwRowLo(18) != 57) ++bad;
                    if (rules::mwRowLo(19) != 61) ++bad;
                    if (rules::mwRowLo(20) != 63) ++bad;
                    if (rules::mwRowLo(21) != 64) ++bad;
                    if (rules::mwRowLo(22) != 65) ++bad;
                    if (rules::mwRowLo(23) != 68) ++bad;
                    if (rules::mwRowLo(24) != 73) ++bad;
                    if (rules::mwRowLo(25) != 76) ++bad;
                    if (rules::mwRowLo(26) != 77) ++bad;
                    if (rules::mwRowLo(27) != 78) ++bad;
                    if (rules::mwRowLo(28) != 81) ++bad;
                    if (rules::mwRowLo(29) != 84) ++bad;
                    if (rules::mwRowLo(30) != 89) ++bad;
                    if (rules::mwRowLo(31) != 90) ++bad;
                    if (rules::mwRowLo(32) != 95) ++bad;
                    if (rules::mwRowLo(33) != 97) ++bad;
                    if (rules::mwRowLo(34) != 98) ++bad;
                    if (rules::mwRowLo(35) != 100) ++bad;
                    if (rules::mwRowHi(0) != 8) ++bad;
                    if (rules::mwRowHi(1) != 12) ++bad;
                    if (rules::mwRowHi(2) != 14) ++bad;
                    if (rules::mwRowHi(3) != 15) ++bad;
                    if (rules::mwRowHi(4) != 20) ++bad;
                    if (rules::mwRowHi(5) != 22) ++bad;
                    if (rules::mwRowHi(6) != 23) ++bad;
                    if (rules::mwRowHi(7) != 24) ++bad;
                    if (rules::mwRowHi(8) != 27) ++bad;
                    if (rules::mwRowHi(9) != 32) ++bad;
                    if (rules::mwRowHi(10) != 35) ++bad;
                    if (rules::mwRowHi(11) != 36) ++bad;
                    if (rules::mwRowHi(12) != 37) ++bad;
                    if (rules::mwRowHi(13) != 38) ++bad;
                    if (rules::mwRowHi(14) != 46) ++bad;
                    if (rules::mwRowHi(15) != 50) ++bad;
                    if (rules::mwRowHi(16) != 51) ++bad;
                    if (rules::mwRowHi(17) != 56) ++bad;
                    if (rules::mwRowHi(18) != 60) ++bad;
                    if (rules::mwRowHi(19) != 62) ++bad;
                    if (rules::mwRowHi(20) != 63) ++bad;
                    if (rules::mwRowHi(21) != 64) ++bad;
                    if (rules::mwRowHi(22) != 67) ++bad;
                    if (rules::mwRowHi(23) != 72) ++bad;
                    if (rules::mwRowHi(24) != 75) ++bad;
                    if (rules::mwRowHi(25) != 76) ++bad;
                    if (rules::mwRowHi(26) != 77) ++bad;
                    if (rules::mwRowHi(27) != 80) ++bad;
                    if (rules::mwRowHi(28) != 83) ++bad;
                    if (rules::mwRowHi(29) != 88) ++bad;
                    if (rules::mwRowHi(30) != 89) ++bad;
                    if (rules::mwRowHi(31) != 94) ++bad;
                    if (rules::mwRowHi(32) != 96) ++bad;
                    if (rules::mwRowHi(33) != 97) ++bad;
                    if (rules::mwRowHi(34) != 99) ++bad;
                    if (rules::mwRowHi(35) != 100) ++bad;
                    if (rules::mwXpValue(0) != 20) ++bad;
                    if (rules::mwXpValue(1) != 50) ++bad;
                    if (rules::mwXpValue(2) != 75) ++bad;
                    if (rules::mwXpValue(3) != 250) ++bad;
                    if (rules::mwXpValue(4) != 300) ++bad;
                    if (rules::mwXpValue(5) != 600) ++bad;
                    if (rules::mwXpValue(6) != 750) ++bad;
                    if (rules::mwXpValue(7) != 1000) ++bad;
                    if (rules::mwXpValue(8) != 400) ++bad;
                    if (rules::mwXpValue(9) != 50) ++bad;
                    if (rules::mwXpValue(10) != 500) ++bad;
                    if (rules::mwXpValue(11) != 2000) ++bad;
                    if (rules::mwXpValue(12) != 1500) ++bad;
                    if (rules::mwXpValue(13) != 1500) ++bad;
                    if (rules::mwXpValue(14) != 100) ++bad;
                    if (rules::mwXpValue(15) != 250) ++bad;
                    if (rules::mwXpValue(16) != 350) ++bad;
                    if (rules::mwXpValue(17) != 450) ++bad;
                    if (rules::mwXpValue(18) != 300) ++bad;
                    if (rules::mwXpValue(19) != 650) ++bad;
                    if (rules::mwXpValue(20) != 1500) ++bad;
                    if (rules::mwXpValue(21) != 2500) ++bad;
                    if (rules::mwXpValue(22) != 750) ++bad;
                    if (rules::mwXpValue(23) != 350) ++bad;
                    if (rules::mwXpValue(24) != 700) ++bad;
                    if (rules::mwXpValue(25) != 1750) ++bad;
                    if (rules::mwXpValue(26) != 1500) ++bad;
                    if (rules::mwXpValue(27) != 350) ++bad;
                    if (rules::mwXpValue(28) != 400) ++bad;
                    if (rules::mwXpValue(29) != 750) ++bad;
                    if (rules::mwXpValue(30) != 700) ++bad;
                    if (rules::mwXpValue(31) != 500) ++bad;
                    if (rules::mwXpValue(32) != 1000) ++bad;
                    if (rules::mwXpValue(33) != 1750) ++bad;
                    if (rules::mwXpValue(34) != 0) ++bad;
                    if (rules::mwXpValue(35) != 1500) ++bad;
                    if (rules::mwSaleGp(0) != 120) ++bad;
                    if (rules::mwSaleGp(1) != 300) ++bad;
                    if (rules::mwSaleGp(2) != 450) ++bad;
                    if (rules::mwSaleGp(3) != 2500) ++bad;
                    if (rules::mwSaleGp(4) != 1750) ++bad;
                    if (rules::mwSaleGp(5) != 3750) ++bad;
                    if (rules::mwSaleGp(6) != 4500) ++bad;
                    if (rules::mwSaleGp(7) != 7000) ++bad;
                    if (rules::mwSaleGp(8) != 2500) ++bad;
                    if (rules::mwSaleGp(9) != 300) ++bad;
                    if (rules::mwSaleGp(10) != 3500) ++bad;
                    if (rules::mwSaleGp(11) != 12000) ++bad;
                    if (rules::mwSaleGp(12) != 7500) ++bad;
                    if (rules::mwSaleGp(13) != 7500) ++bad;
                    if (rules::mwSaleGp(14) != 750) ++bad;
                    if (rules::mwSaleGp(15) != 2000) ++bad;
                    if (rules::mwSaleGp(16) != 3000) ++bad;
                    if (rules::mwSaleGp(17) != 4000) ++bad;
                    if (rules::mwSaleGp(18) != 2500) ++bad;
                    if (rules::mwSaleGp(19) != 6000) ++bad;
                    if (rules::mwSaleGp(20) != 15000) ++bad;
                    if (rules::mwSaleGp(21) != 25000) ++bad;
                    if (rules::mwSaleGp(22) != 5000) ++bad;
                    if (rules::mwSaleGp(23) != 3000) ++bad;
                    if (rules::mwSaleGp(24) != 4500) ++bad;
                    if (rules::mwSaleGp(25) != 17500) ++bad;
                    if (rules::mwSaleGp(26) != 15000) ++bad;
                    if (rules::mwSaleGp(27) != 2500) ++bad;
                    if (rules::mwSaleGp(28) != 3000) ++bad;
                    if (rules::mwSaleGp(29) != 6000) ++bad;
                    if (rules::mwSaleGp(30) != 7000) ++bad;
                    if (rules::mwSaleGp(31) != 3000) ++bad;
                    if (rules::mwSaleGp(32) != 6500) ++bad;
                    if (rules::mwSaleGp(33) != 15000) ++bad;
                    if (rules::mwSaleGp(34) != 1000) ++bad;
                    if (rules::mwSaleGp(35) != 12500) ++bad;
                    if (rules::mwQtyLo(0) != 2) ++bad;
                    if (rules::mwQtyLo(1) != 2) ++bad;
                    if (rules::mwQtyLo(2) != 2) ++bad;
                    if (rules::mwQtyLo(3) != 0) ++bad;
                    if (rules::mwQtyLo(4) != 0) ++bad;
                    if (rules::mwQtyLo(5) != 0) ++bad;
                    if (rules::mwQtyLo(6) != 0) ++bad;
                    if (rules::mwQtyLo(7) != 0) ++bad;
                    if (rules::mwQtyLo(8) != 0) ++bad;
                    if (rules::mwQtyLo(9) != 2) ++bad;
                    if (rules::mwQtyLo(10) != 0) ++bad;
                    if (rules::mwQtyLo(11) != 0) ++bad;
                    if (rules::mwQtyLo(12) != 0) ++bad;
                    if (rules::mwQtyLo(13) != 0) ++bad;
                    if (rules::mwQtyLo(14) != 0) ++bad;
                    if (rules::mwQtyLo(15) != 0) ++bad;
                    if (rules::mwQtyLo(16) != 0) ++bad;
                    if (rules::mwQtyLo(17) != 0) ++bad;
                    if (rules::mwQtyLo(18) != 0) ++bad;
                    if (rules::mwQtyLo(19) != 0) ++bad;
                    if (rules::mwQtyLo(20) != 0) ++bad;
                    if (rules::mwQtyLo(21) != 0) ++bad;
                    if (rules::mwQtyLo(22) != 0) ++bad;
                    if (rules::mwQtyLo(23) != 0) ++bad;
                    if (rules::mwQtyLo(24) != 0) ++bad;
                    if (rules::mwQtyLo(25) != 0) ++bad;
                    if (rules::mwQtyLo(26) != 0) ++bad;
                    if (rules::mwQtyLo(27) != 0) ++bad;
                    if (rules::mwQtyLo(28) != 0) ++bad;
                    if (rules::mwQtyLo(29) != 0) ++bad;
                    if (rules::mwQtyLo(30) != 0) ++bad;
                    if (rules::mwQtyLo(31) != 0) ++bad;
                    if (rules::mwQtyLo(32) != 0) ++bad;
                    if (rules::mwQtyLo(33) != 0) ++bad;
                    if (rules::mwQtyLo(34) != 0) ++bad;
                    if (rules::mwQtyLo(35) != 0) ++bad;
                    if (rules::mwQtyHi(0) != 24) ++bad;
                    if (rules::mwQtyHi(1) != 16) ++bad;
                    if (rules::mwQtyHi(2) != 12) ++bad;
                    if (rules::mwQtyHi(3) != 0) ++bad;
                    if (rules::mwQtyHi(4) != 0) ++bad;
                    if (rules::mwQtyHi(5) != 0) ++bad;
                    if (rules::mwQtyHi(6) != 0) ++bad;
                    if (rules::mwQtyHi(7) != 0) ++bad;
                    if (rules::mwQtyHi(8) != 0) ++bad;
                    if (rules::mwQtyHi(9) != 20) ++bad;
                    if (rules::mwQtyHi(10) != 0) ++bad;
                    if (rules::mwQtyHi(11) != 0) ++bad;
                    if (rules::mwQtyHi(12) != 0) ++bad;
                    if (rules::mwQtyHi(13) != 0) ++bad;
                    if (rules::mwQtyHi(14) != 0) ++bad;
                    if (rules::mwQtyHi(15) != 0) ++bad;
                    if (rules::mwQtyHi(16) != 0) ++bad;
                    if (rules::mwQtyHi(17) != 0) ++bad;
                    if (rules::mwQtyHi(18) != 0) ++bad;
                    if (rules::mwQtyHi(19) != 0) ++bad;
                    if (rules::mwQtyHi(20) != 0) ++bad;
                    if (rules::mwQtyHi(21) != 0) ++bad;
                    if (rules::mwQtyHi(22) != 0) ++bad;
                    if (rules::mwQtyHi(23) != 0) ++bad;
                    if (rules::mwQtyHi(24) != 0) ++bad;
                    if (rules::mwQtyHi(25) != 0) ++bad;
                    if (rules::mwQtyHi(26) != 0) ++bad;
                    if (rules::mwQtyHi(27) != 0) ++bad;
                    if (rules::mwQtyHi(28) != 0) ++bad;
                    if (rules::mwQtyHi(29) != 0) ++bad;
                    if (rules::mwQtyHi(30) != 0) ++bad;
                    if (rules::mwQtyHi(31) != 0) ++bad;
                    if (rules::mwQtyHi(32) != 0) ++bad;
                    if (rules::mwQtyHi(33) != 0) ++bad;
                    if (rules::mwQtyHi(34) != 0) ++bad;
                    if (rules::mwQtyHi(35) != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("wspeed");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 1) ++bad;
                    if (d->tables[0]
                        .values[1] != 2) ++bad;
                    if (d->tables[0]
                        .values[2] != 3) ++bad;
                    if (d->tables[0]
                        .values[3] != 4) ++bad;
                    if (d->tables[0]
                        .values[4] != 4) ++bad;
                    if (d->tables[0]
                        .values[5] != 4) ++bad;
                    if (d->tables[0]
                        .values[6] != 4) ++bad;
                    if (d->tables[0]
                        .values[7] != 4) ++bad;
                    if (d->tables[0]
                        .values[8] != 5) ++bad;
                    if (d->tables[0]
                        .values[9] != 5) ++bad;
                    if (d->tables[0]
                        .values[10] != 6) ++bad;
                    if (d->tables[0]
                        .values[11] != 6) ++bad;
                    if (d->tables[0]
                        .values[12] != 7) ++bad;
                    if (d->tables[0]
                        .values[13] != 7) ++bad;
                    if (d->tables[0]
                        .values[14] != 7) ++bad;
                    if (d->tables[0]
                        .values[15] != 7) ++bad;
                    if (d->tables[0]
                        .values[16] != 7) ++bad;
                    if (d->tables[0]
                        .values[17] != 10) ++bad;
                    if (d->tables[0]
                        .values[18] != 13) ++bad;
                    if (d->tables[0]
                        .values[19] != 6) ++bad;
                    if (d->tables[0]
                        .values[20] != 7) ++bad;
                    if (d->tables[0]
                        .values[21] != 8) ++bad;
                    // 22 pairs + 1 unknown
                    if (rules::weaponSpeedFactor("fist")
                        != 1) ++bad;
                    if (rules::weaponSpeedFactor("dagger")
                        != 2) ++bad;
                    if (rules::weaponSpeedFactor("short sword")
                        != 3) ++bad;
                    if (rules::weaponSpeedFactor("hammer")
                        != 4) ++bad;
                    if (rules::weaponSpeedFactor("club")
                        != 4) ++bad;
                    if (rules::weaponSpeedFactor("hand axe")
                        != 4) ++bad;
                    if (rules::weaponSpeedFactor("quarterstaff")
                        != 4) ++bad;
                    if (rules::weaponSpeedFactor("scimitar")
                        != 4) ++bad;
                    if (rules::weaponSpeedFactor("long sword")
                        != 5) ++bad;
                    if (rules::weaponSpeedFactor("broad sword")
                        != 5) ++bad;
                    if (rules::weaponSpeedFactor("horseman mace")
                        != 6) ++bad;
                    if (rules::weaponSpeedFactor("horseman flail")
                        != 6) ++bad;
                    if (rules::weaponSpeedFactor("spear")
                        != 7) ++bad;
                    if (rules::weaponSpeedFactor("footman mace")
                        != 7) ++bad;
                    if (rules::weaponSpeedFactor("footman flail")
                        != 7) ++bad;
                    if (rules::weaponSpeedFactor("morning star")
                        != 7) ++bad;
                    if (rules::weaponSpeedFactor("battle axe")
                        != 7) ++bad;
                    if (rules::weaponSpeedFactor("two-handed sword")
                        != 10) ++bad;
                    if (rules::weaponSpeedFactor("pike")
                        != 13) ++bad;
                    if (rules::weaponSpeedFactor("lance, medium horse")
                        != 6) ++bad;
                    if (rules::weaponSpeedFactor("lance, light horse")
                        != 7) ++bad;
                    if (rules::weaponSpeedFactor("lance, heavy horse")
                        != 8) ++bad;
                    if (rules::weaponSpeedFactor("no such weapon")
                        != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("wpf");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 4) ++bad;
                    if (d->tables[0]
                        .values[1] != 5) ++bad;
                    if (d->tables[0]
                        .values[2] != 3) ++bad;
                    if (d->tables[0]
                        .values[3] != 3) ++bad;
                    if (d->tables[0]
                        .values[4] != 3) ++bad;
                    if (d->tables[0]
                        .values[5] != 6) ++bad;
                    if (d->tables[0]
                        .values[6] != 6) ++bad;
                    if (d->tables[0]
                        .values[7] != 4) ++bad;
                    if (d->tables[0]
                        .values[8] != 4) ++bad;
                    if (d->tables[0]
                        .values[9] != 2) ++bad;
                    if (d->tables[1]
                        .values[0] != 2) ++bad;
                    if (d->tables[1]
                        .values[1] != 2) ++bad;
                    if (d->tables[1]
                        .values[2] != 4) ++bad;
                    if (d->tables[1]
                        .values[3] != 3) ++bad;
                    if (d->tables[1]
                        .values[4] != 3) ++bad;
                    if (d->tables[1]
                        .values[5] != 1) ++bad;
                    if (d->tables[1]
                        .values[6] != 1) ++bad;
                    if (d->tables[1]
                        .values[7] != 2) ++bad;
                    if (d->tables[1]
                        .values[8] != 3) ++bad;
                    if (d->tables[1]
                        .values[9] != 1) ++bad;
                    if (d->tables[2]
                        .values[0] != 3) ++bad;
                    if (d->tables[2]
                        .values[1] != 4) ++bad;
                    if (d->tables[2]
                        .values[2] != 2) ++bad;
                    if (d->tables[2]
                        .values[3] != 2) ++bad;
                    if (d->tables[2]
                        .values[4] != 2) ++bad;
                    if (d->tables[2]
                        .values[5] != 5) ++bad;
                    if (d->tables[2]
                        .values[6] != 5) ++bad;
                    if (d->tables[2]
                        .values[7] != 3) ++bad;
                    if (d->tables[2]
                        .values[8] != 2) ++bad;
                    if (d->tables[2]
                        .values[9] != 3) ++bad;
                    if (rules::wpfInitialSlots(0) != 2) ++bad;
                    if (rules::wpfInitialSlots(1) != 2) ++bad;
                    if (rules::wpfInitialSlots(2) != 4) ++bad;
                    if (rules::wpfInitialSlots(3) != 3) ++bad;
                    if (rules::wpfInitialSlots(4) != 3) ++bad;
                    if (rules::wpfInitialSlots(5) != 1) ++bad;
                    if (rules::wpfInitialSlots(6) != 1) ++bad;
                    if (rules::wpfInitialSlots(7) != 2) ++bad;
                    if (rules::wpfInitialSlots(8) != 3) ++bad;
                    if (rules::wpfInitialSlots(9) != 1) ++bad;
                    if (rules::wpfNonProfPenalty(0) != 3) ++bad;
                    if (rules::wpfNonProfPenalty(1) != 4) ++bad;
                    if (rules::wpfNonProfPenalty(2) != 2) ++bad;
                    if (rules::wpfNonProfPenalty(3) != 2) ++bad;
                    if (rules::wpfNonProfPenalty(4) != 2) ++bad;
                    if (rules::wpfNonProfPenalty(5) != 5) ++bad;
                    if (rules::wpfNonProfPenalty(6) != 5) ++bad;
                    if (rules::wpfNonProfPenalty(7) != 3) ++bad;
                    if (rules::wpfNonProfPenalty(8) != 2) ++bad;
                    if (rules::wpfNonProfPenalty(9) != 3) ++bad;
                    if (rules::wpfAddedCadence(0) != 4) ++bad;
                    if (rules::wpfAddedCadence(1) != 5) ++bad;
                    if (rules::wpfAddedCadence(2) != 3) ++bad;
                    if (rules::wpfAddedCadence(3) != 3) ++bad;
                    if (rules::wpfAddedCadence(4) != 3) ++bad;
                    if (rules::wpfAddedCadence(5) != 6) ++bad;
                    if (rules::wpfAddedCadence(6) != 6) ++bad;
                    if (rules::wpfAddedCadence(7) != 4) ++bad;
                    if (rules::wpfAddedCadence(8) != 4) ++bad;
                    if (rules::wpfAddedCadence(9) != 2) ++bad;
                }
            }
        }
        printf("R1058 weapons registry defs-D audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 7. seam ----------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/weapondata");
            {
                const items::MiscItemDef* d =
                    reg.find("wt");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < 68; ++i)
                        if (rules::uawtIsNewWeapon(0 + i)
                            != (int)d->tables[0].values[i])
                            ++bad;
                    for (int i = 0; i < 68; ++i)
                        if (rules::uawtPhbSeamIndex(0 + i)
                            != (int)d->tables[3].values[i])
                            ++bad;
                    for (int i = 0; i < 68; ++i)
                        if (rules::uawtWeightMin(0 + i)
                            != (int)d->tables[7].values[i])
                            ++bad;
                    for (int i = 0; i < 68; ++i)
                        if (rules::uawtWeightMax(0 + i)
                            != (int)d->tables[6].values[i])
                            ++bad;
                    for (int i = 0; i < 68; ++i)
                        if (rules::uawtDamageSMMin(0 + i)
                            != (int)d->tables[5].values[i])
                            ++bad;
                    for (int i = 0; i < 68; ++i)
                        if (rules::uawtDamageSMMax(0 + i)
                            != (int)d->tables[4].values[i])
                            ++bad;
                    for (int i = 0; i < 68; ++i)
                        if (rules::uawtDamageLMin(0 + i)
                            != (int)d->tables[2].values[i])
                            ++bad;
                    for (int i = 0; i < 68; ++i)
                        if (rules::uawtDamageLMax(0 + i)
                            != (int)d->tables[1].values[i])
                            ++bad;
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uawtName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("uamt");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < 24; ++i)
                        if (rules::uamtIsNewWeapon(0 + i)
                            != (int)d->tables[2].values[i])
                            ++bad;
                    for (int i = 0; i < 24; ++i)
                        if (rules::uamtRangePrinted(0 + i)
                            != (int)d->tables[3].values[i])
                            ++bad;
                    for (int i = 0; i < 24; ++i)
                        for (int j = 0; j < 7; ++j)
                            if (rules::uamtAcAdjustment(0 + i, 0 + j)
                                != (int)d->tables[0].values[(i + 0) * 7 + (j + 0)])
                                ++bad;
                    for (int i = 0; i < 24; ++i)
                        for (int j = 0; j < 4; ++j)
                            if (rules::uamtAcAdjustmentHigh(0 + i, 0 + j)
                                != (int)d->tables[1].values[(i + 0) * 4 + (j + 0)])
                                ++bad;
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uamtName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("uamt_rof");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uamtRateOfFire(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("uamt_range_s");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uamtRangeShort(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("uamt_range_m");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uamtRangeMedium(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("uamt_range_l");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uamtRangeLong(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("uahh");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < 60; ++i)
                        if (rules::uahhSpeedFactorMin(0 + i)
                            != (int)d->tables[4].values[i])
                            ++bad;
                    for (int i = 0; i < 60; ++i)
                        if (rules::uahhSpeedFactorMax(0 + i)
                            != (int)d->tables[3].values[i])
                            ++bad;
                    for (int i = 0; i < 60; ++i)
                        if (rules::uahhSetDoubleFlag(0 + i)
                            != (int)d->tables[2].values[i])
                            ++bad;
                    for (int i = 0; i < 60; ++i)
                        if (rules::uahhDismountFlag(0 + i)
                            != (int)d->tables[1].values[i])
                            ++bad;
                    for (int i = 0; i < 60; ++i)
                        for (int j = 0; j < 11; ++j)
                            if (rules::uahhAcAdjustment(0 + i, 0 + j)
                                != (int)d->tables[0].values[(i + 0) * 11 + (j + 0)])
                                ++bad;
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uahhName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("uahh_length");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uahhLength(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("uahh_space");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uahhSpaceRequired(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("uanw");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < 16; ++i)
                        if (rules::uanwInGapItemList(0 + i)
                            != (int)d->tables[0].values[i])
                            ++bad;
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uanwName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("wspec_cols");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::weaponSpecTableColumnName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("wspec");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < 3; ++i)
                        if (rules::weaponSpecTableBandLow(0 + i)
                            != (int)d->tables[1].values[i])
                            ++bad;
                    for (int i = 0; i < 3; ++i)
                        if (rules::weaponSpecTableBandHigh(0 + i)
                            != (int)d->tables[0].values[i])
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("wspec_cells");
                if (!d) { ++bad; } else {
                    for (int a = 0; a < 3; ++a)
                        for (int b = 0; b < 8; ++b)
                            if (std::string(rules::weaponSpecTableCellKnown(0 + a, 0 + b))
                                != d->rows[a * 8 + b].name)
                                ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("uapf");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < 14; ++i)
                        if (rules::uapfPhbSeamRow(0 + i)
                            != (int)d->tables[5].values[i])
                            ++bad;
                    for (int i = 0; i < 14; ++i)
                        if (rules::uapfNameIsAttributed(0 + i)
                            != (int)d->tables[1].values[i])
                            ++bad;
                    for (int i = 0; i < 14; ++i)
                        if (rules::uapfInitialSlots(0 + i)
                            != (int)d->tables[3].values[i])
                            ++bad;
                    for (int i = 0; i < 14; ++i)
                        if (rules::uapfNonProfPenalty(0 + i)
                            != (int)d->tables[4].values[i])
                            ++bad;
                    for (int i = 0; i < 14; ++i)
                        if (rules::uapfAddedCadence(0 + i)
                            != (int)d->tables[0].values[i])
                            ++bad;
                    for (int i = 0; i < 14; ++i)
                        if (rules::uapfInitialAsterisk(0 + i)
                            != (int)d->tables[2].values[i])
                            ++bad;
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uapfName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("mw");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < 36; ++i)
                        if (rules::mwRowLo(0 + i)
                            != (int)d->tables[3].values[i])
                            ++bad;
                    for (int i = 0; i < 36; ++i)
                        if (rules::mwRowHi(0 + i)
                            != (int)d->tables[2].values[i])
                            ++bad;
                    for (int i = 0; i < 36; ++i)
                        if (rules::mwXpValue(0 + i)
                            != (int)d->tables[5].values[i])
                            ++bad;
                    for (int i = 0; i < 36; ++i)
                        if (rules::mwSaleGp(0 + i)
                            != (int)d->tables[4].values[i])
                            ++bad;
                    for (int i = 0; i < 36; ++i)
                        if (rules::mwQtyLo(0 + i)
                            != (int)d->tables[1].values[i])
                            ++bad;
                    for (int i = 0; i < 36; ++i)
                        if (rules::mwQtyHi(0 + i)
                            != (int)d->tables[0].values[i])
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("wspeed");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (rules::weaponSpeedFactor(d->rows[i].name.c_str())
                            != (int)d->tables[0].values[i])
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("wpf");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < 10; ++i)
                        if (rules::wpfInitialSlots(0 + i)
                            != (int)d->tables[1].values[i])
                            ++bad;
                    for (int i = 0; i < 10; ++i)
                        if (rules::wpfNonProfPenalty(0 + i)
                            != (int)d->tables[2].values[i])
                            ++bad;
                    for (int i = 0; i < 10; ++i)
                        if (rules::wpfAddedCadence(0 + i)
                            != (int)d->tables[0].values[i])
                            ++bad;
                }
            }
        }
        printf("R1058 weapons registry seam audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 8. edges ------------------------------
        {
            if (rules::uawtIsNewWeapon(-1) != 1)
                ++bad;
            if (rules::uawtIsNewWeapon(0) != 1)
                ++bad;
            if (rules::uawtIsNewWeapon(68) != 1)
                ++bad;
            if (rules::uawtPhbSeamIndex(-1) != -1)
                ++bad;
            if (rules::uawtPhbSeamIndex(0) != -1)
                ++bad;
            if (rules::uawtPhbSeamIndex(68) != -1)
                ++bad;
            if (rules::uawtWeightMin(-1) != 35)
                ++bad;
            if (rules::uawtWeightMin(0) != 35)
                ++bad;
            if (rules::uawtWeightMin(68) != 1)
                ++bad;
            if (rules::uawtWeightMax(-1) != 35)
                ++bad;
            if (rules::uawtWeightMax(0) != 35)
                ++bad;
            if (rules::uawtWeightMax(68) != 1)
                ++bad;
            if (rules::uawtDamageSMMin(-1) != 1)
                ++bad;
            if (rules::uawtDamageSMMin(0) != 1)
                ++bad;
            if (rules::uawtDamageSMMin(68) != 1)
                ++bad;
            if (rules::uawtDamageSMMax(-1) != 6)
                ++bad;
            if (rules::uawtDamageSMMax(0) != 6)
                ++bad;
            if (rules::uawtDamageSMMax(68) != 3)
                ++bad;
            if (rules::uawtDamageLMin(-1) != 1)
                ++bad;
            if (rules::uawtDamageLMin(0) != 1)
                ++bad;
            if (rules::uawtDamageLMin(68) != 1)
                ++bad;
            if (rules::uawtDamageLMax(-1) != 3)
                ++bad;
            if (rules::uawtDamageLMax(0) != 3)
                ++bad;
            if (rules::uawtDamageLMax(68) != 2)
                ++bad;
            if (rules::uamtIsNewWeapon(-1) != 1)
                ++bad;
            if (rules::uamtIsNewWeapon(0) != 1)
                ++bad;
            if (rules::uamtIsNewWeapon(24) != 1)
                ++bad;
            if (rules::uamtRangePrinted(-1) != -1)
                ++bad;
            if (rules::uamtRangePrinted(0) != -1)
                ++bad;
            if (rules::uamtRangePrinted(24) != 9)
                ++bad;
            if (rules::uamtAcAdjustment(-1, 0) != -8)
                ++bad;
            if (rules::uamtAcAdjustment(24, 6) != 0)
                ++bad;
            if (rules::uamtAcAdjustmentHigh(-1, 0) != -1)
                ++bad;
            if (rules::uamtAcAdjustmentHigh(24, 3) != 0)
                ++bad;
            if (rules::uahhSpeedFactorMin(-1) != 4)
                ++bad;
            if (rules::uahhSpeedFactorMin(0) != 4)
                ++bad;
            if (rules::uahhSpeedFactorMin(60) != 5)
                ++bad;
            if (rules::uahhSpeedFactorMax(-1) != 4)
                ++bad;
            if (rules::uahhSpeedFactorMax(0) != 4)
                ++bad;
            if (rules::uahhSpeedFactorMax(60) != 8)
                ++bad;
            if (rules::uahhSetDoubleFlag(-1) != 0)
                ++bad;
            if (rules::uahhSetDoubleFlag(0) != 0)
                ++bad;
            if (rules::uahhSetDoubleFlag(60) != 0)
                ++bad;
            if (rules::uahhDismountFlag(-1) != 0)
                ++bad;
            if (rules::uahhDismountFlag(0) != 0)
                ++bad;
            if (rules::uahhDismountFlag(60) != 0)
                ++bad;
            if (rules::uahhAcAdjustment(-1, 0) != -7)
                ++bad;
            if (rules::uahhAcAdjustment(60, 10) != 3)
                ++bad;
            if (rules::uanwInGapItemList(-1) != 1)
                ++bad;
            if (rules::uanwInGapItemList(0) != 1)
                ++bad;
            if (rules::uanwInGapItemList(16) != 1)
                ++bad;
            if (rules::weaponSpecTableBandLow(-1) != 1)
                ++bad;
            if (rules::weaponSpecTableBandLow(0) != 1)
                ++bad;
            if (rules::weaponSpecTableBandLow(3) != 13)
                ++bad;
            if (rules::weaponSpecTableBandHigh(-1) != 6)
                ++bad;
            if (rules::weaponSpecTableBandHigh(0) != 6)
                ++bad;
            if (rules::weaponSpecTableBandHigh(3) != 0)
                ++bad;
            if (rules::uapfPhbSeamRow(-1) != -1)
                ++bad;
            if (rules::uapfPhbSeamRow(0) != -1)
                ++bad;
            if (rules::uapfPhbSeamRow(14) != -1)
                ++bad;
            if (rules::uapfNameIsAttributed(-1) != 0)
                ++bad;
            if (rules::uapfNameIsAttributed(0) != 0)
                ++bad;
            if (rules::uapfNameIsAttributed(14) != 0)
                ++bad;
            if (rules::uapfInitialSlots(-1) != 3)
                ++bad;
            if (rules::uapfInitialSlots(0) != 3)
                ++bad;
            if (rules::uapfInitialSlots(14) != 5)
                ++bad;
            if (rules::uapfNonProfPenalty(-1) != 3)
                ++bad;
            if (rules::uapfNonProfPenalty(0) != 3)
                ++bad;
            if (rules::uapfNonProfPenalty(14) != 2)
                ++bad;
            if (rules::uapfAddedCadence(-1) != 2)
                ++bad;
            if (rules::uapfAddedCadence(0) != 2)
                ++bad;
            if (rules::uapfAddedCadence(14) != 4)
                ++bad;
            if (rules::uapfInitialAsterisk(-1) != 1)
                ++bad;
            if (rules::uapfInitialAsterisk(0) != 1)
                ++bad;
            if (rules::uapfInitialAsterisk(14) != 0)
                ++bad;
            if (rules::mwRowLo(-1) != 1)
                ++bad;
            if (rules::mwRowLo(0) != 1)
                ++bad;
            if (rules::mwRowLo(36) != 100)
                ++bad;
            if (rules::mwRowHi(-1) != 8)
                ++bad;
            if (rules::mwRowHi(0) != 8)
                ++bad;
            if (rules::mwRowHi(36) != 100)
                ++bad;
            if (rules::mwXpValue(-1) != 20)
                ++bad;
            if (rules::mwXpValue(0) != 20)
                ++bad;
            if (rules::mwXpValue(36) != 1500)
                ++bad;
            if (rules::mwSaleGp(-1) != 120)
                ++bad;
            if (rules::mwSaleGp(0) != 120)
                ++bad;
            if (rules::mwSaleGp(36) != 12500)
                ++bad;
            if (rules::mwQtyLo(-1) != 2)
                ++bad;
            if (rules::mwQtyLo(0) != 2)
                ++bad;
            if (rules::mwQtyLo(36) != 0)
                ++bad;
            if (rules::mwQtyHi(-1) != 24)
                ++bad;
            if (rules::mwQtyHi(0) != 24)
                ++bad;
            if (rules::mwQtyHi(36) != 0)
                ++bad;
            if (rules::wpfInitialSlots(-1) != 2)
                ++bad;
            if (rules::wpfInitialSlots(0) != 2)
                ++bad;
            if (rules::wpfInitialSlots(10) != 1)
                ++bad;
            if (rules::wpfNonProfPenalty(-1) != 3)
                ++bad;
            if (rules::wpfNonProfPenalty(0) != 3)
                ++bad;
            if (rules::wpfNonProfPenalty(10) != 3)
                ++bad;
            if (rules::wpfAddedCadence(-1) != 4)
                ++bad;
            if (rules::wpfAddedCadence(0) != 4)
                ++bad;
            if (rules::wpfAddedCadence(10) != 2)
                ++bad;
            if (std::string(rules::uawtName(-1))
                != "Aklys") ++bad;
            if (std::string(rules::uawtName(68))
                != "Quarrel (or Bolt), hand") ++bad;
            if (std::string(rules::uamtName(-1))
                != "Aklys (hurled)") ++bad;
            if (std::string(rules::uamtName(24))
                != "Staff Sling (stone)") ++bad;
            if (std::string(rules::uamtRateOfFire(-1))
                != "1") ++bad;
            if (std::string(rules::uamtRateOfFire(24))
                != "1/2") ++bad;
            if (std::string(rules::uamtRangeShort(-1))
                != "1*") ++bad;
            if (std::string(rules::uamtRangeShort(24))
                != "-") ++bad;
            if (std::string(rules::uamtRangeMedium(-1))
                != "-") ++bad;
            if (std::string(rules::uamtRangeMedium(24))
                != "3-6") ++bad;
            if (std::string(rules::uamtRangeLong(-1))
                != "-") ++bad;
            if (std::string(rules::uamtRangeLong(24))
                != "9") ++bad;
            if (std::string(rules::uahhName(-1))
                != "Aklys") ++bad;
            if (std::string(rules::uahhName(60))
                != "Whip") ++bad;
            if (std::string(rules::uahhLength(-1))
                != "c. 2'") ++bad;
            if (std::string(rules::uahhLength(60))
                != "8'-20'") ++bad;
            if (std::string(rules::uahhSpaceRequired(-1))
                != "2'") ++bad;
            if (std::string(rules::uahhSpaceRequired(60))
                != "8'-20'") ++bad;
            if (std::string(rules::uanwName(-1))
                != "Aklys") ++bad;
            if (std::string(rules::uanwName(16))
                != "Whip") ++bad;
            if (std::string(rules::weaponSpecTableColumnName(-1))
                != "Melee Weapon") ++bad;
            if (std::string(rules::weaponSpecTableColumnName(8))
                != "Other Missiles and Hurled Weapons") ++bad;
            if (std::string(rules::weaponSpecTableCellKnown(-1, 0))
                != "3/2") ++bad;
            if (std::string(rules::weaponSpecTableCellKnown(3, 8))
                != "5/2") ++bad;
            if (std::string(rules::uapfName(-1))
                != "Cavalier") ++bad;
            if (std::string(rules::uapfName(14))
                != "Bard") ++bad;
            if (rules::weaponSpeedFactor("fist")
                != 1) ++bad;
            if (rules::weaponSpeedFactor("no such weapon")
                != 0) ++bad;
            if (rules::bearLikeHuggerGrappples() != true)
                ++bad;
            if (rules::grappleAttackAndCounterPerRound() != true)
                ++bad;
            if (rules::grappleHoldActsFirst() != true)
                ++bad;
            if (rules::grappleStunnedAllowsImmediateSecond() != true)
                ++bad;
            if (rules::monkLadderRowCount() != 17)
                ++bad;
            if (rules::monkOpenHandUnimpeded() != true)
                ++bad;
            if (rules::mwDuplicateNameCount() != 2)
                ++bad;
            if (rules::mwNoXpCount() != 1)
                ++bad;
            if (rules::mwQtyRangeCount() != 4)
                ++bad;
            if (rules::mwRowCount() != 36)
                ++bad;
            if (rules::overbearAllowsOccupiedHands() != true)
                ++bad;
            if (rules::overbearRequiresFollowUp() != true)
                ++bad;
            if (rules::speedFactorModifiedWhenSimultaneous() != false)
                ++bad;
            if (rules::uahhAklysSpeedBonus() != 1)
                ++bad;
            if (rules::uahhNoteDismountOnHit() != true)
                ++bad;
            if (rules::uahhNoteSetDoubleVsCharge() != true)
                ++bad;
            if (rules::uahhRearAttackBonus() != 2)
                ++bad;
            if (rules::uahhRowCount() != 60)
                ++bad;
            if (rules::uahhStunnedProneBonus() != 4)
                ++bad;
            if (rules::uamtAcAdjustmentAtShortRange() != true)
                ++bad;
            if (rules::uamtAklysTenFootOnly() != true)
                ++bad;
            if (rules::uamtLongRangeAdjustment() != -5)
                ++bad;
            if (rules::uamtMediumRangeAdjustment() != -2)
                ++bad;
            if (rules::uamtNewWeaponCount() != 8)
                ++bad;
            if (rules::uamtRateOfFireTurnOrRound() != true)
                ++bad;
            if (rules::uamtRowCount() != 24)
                ++bad;
            if (rules::uamtStandardWeaponCount() != 16)
                ++bad;
            if (rules::uanwAklysDisentangleRounds() != 1)
                ++bad;
            if (rules::uanwAklysEntangleHitPct() != 5)
                ++bad;
            if (rules::uanwAklysEntangleRollOf20() != true)
                ++bad;
            if (rules::uanwAklysThongFeet() != 10)
                ++bad;
            if (rules::uanwAklysThongSeverCuttingDmg() != 2)
                ++bad;
            if (rules::uanwAtlatlJavelinDamageSame() != true)
                ++bad;
            if (rules::uanwBlowgunBattlefieldImpossible() != true)
                ++bad;
            if (rules::uanwBlowgunPoisonNeedles() != true)
                ++bad;
            if (rules::uanwCaltropAwareMoveFactorPct() != 50)
                ++bad;
            if (rules::uanwCaltropCheckHdDice() != 1)
                ++bad;
            if (rules::uanwCaltropCheckHdPlus() != 1)
                ++bad;
            if (rules::uanwCaltropDiameterInches() != 6)
                ++bad;
            if (rules::uanwCaltropHitSlowDays() != 4)
                ++bad;
            if (rules::uanwCaltropHitSlowMovePct() != 25)
                ++bad;
            if (rules::uanwCaltropHitSlowPct() != 25)
                ++bad;
            if (rules::uanwCaltropMinProngInches() != 2)
                ++bad;
            if (rules::uanwCaltropNoProficiencyNeeded() != true)
                ++bad;
            if (rules::uanwCaltropPointAngleHigh() != 90)
                ++bad;
            if (rules::uanwCaltropPointAngleLow() != 70)
                ++bad;
            if (rules::uanwCaltropPointInches() != 3)
                ++bad;
            if (rules::uanwCaltropProngCountHigh() != 6)
                ++bad;
            if (rules::uanwCaltropProngCountLow() != 4)
                ++bad;
            if (rules::uanwCaltropTwoHitNoMoveDays() != 8)
                ++bad;
            if (rules::uanwCount() != 16)
                ++bad;
            if (rules::uanwFalchionMagicBroadswordPct() != 25)
                ++bad;
            if (rules::uanwGarrotBendBarsBreaks() != true)
                ++bad;
            if (rules::uanwGarrotDeflectDmg() != 1)
                ++bad;
            if (rules::uanwGarrotNeckMaxFeetAboveShoulder() != 1)
                ++bad;
            if (rules::uanwGarrotSlayAtEndOfRounds() != 1)
                ++bad;
            if (rules::uanwGarrotStrikeFromBehind() != true)
                ++bad;
            if (rules::uanwGarrotVictimAttackMod() != -2)
                ++bad;
            if (rules::uanwHandXbowDrowCostGp() != 30)
                ++bad;
            if (rules::uanwHandXbowDrowQuarrelGp() != 10)
                ++bad;
            if (rules::uanwHandXbowOneHandFire() != true)
                ++bad;
            if (rules::uanwHandXbowPoisonSaveMod() != -4)
                ++bad;
            if (rules::uanwHandXbowSurfaceCostGp() != 300)
                ++bad;
            if (rules::uanwHarpoonDragInches() != 1)
                ++bad;
            if (rules::uanwHarpoonSaveMinInt() != 2)
                ++bad;
            if (rules::uanwHarpoonSaveVsPoison() != true)
                ++bad;
            if (rules::uanwHookFauchardDismountPct() != 20)
                ++bad;
            if (rules::uanwHookFauchardSizeReqPct() != 50)
                ++bad;
            if (rules::uanwKhopeshDruidicalIdeal() != true)
                ++bad;
            if (rules::uanwKhopeshEffectiveExtendsTenthsFeet() != 15)
                ++bad;
            if (rules::uanwKhopeshHandleInches() != 6)
                ++bad;
            if (rules::uanwKhopeshMagicScimitarPct() != 10)
                ++bad;
            if (rules::uanwKhopeshOpponentSnagOnHitPct() != 5)
                ++bad;
            if (rules::uanwKhopeshSickleBladeFeet() != 2)
                ++bad;
            if (rules::uanwKhopeshSnagNoAttackSegments() != 10)
                ++bad;
            if (rules::uanwKhopeshSnagSizePct() != 50)
                ++bad;
            if (rules::uanwKhopeshSnaggedGroundPct() != 25)
                ++bad;
            if (rules::uanwKhopeshSnaggedImpededPct() != 75)
                ++bad;
            if (rules::uanwKhopeshStraightBladeFeet() != 2)
                ++bad;
            if (rules::uanwKhopeshWeaponSnagOnMissPct() != 5)
                ++bad;
            if (rules::uanwKhopeshWeaponTornPct() != 10)
                ++bad;
            if (rules::uanwLassoDamageless() != true)
                ++bad;
            if (rules::uanwLassoDismountPct() != 75)
                ++bad;
            if (rules::uanwLassoPullOffFeetPct() != 25)
                ++bad;
            if (rules::uanwLassoTargetMaxPct() != 50)
                ++bad;
            if (rules::uanwManCatcherAttemptDmgMax() != 4)
                ++bad;
            if (rules::uanwManCatcherAttemptDmgMin() != 1)
                ++bad;
            if (rules::uanwManCatcherBreakoutBendBars() != true)
                ++bad;
            if (rules::uanwManCatcherLosesShieldAndDex() != true)
                ++bad;
            if (rules::uanwManCatcherPoleCuttingDmg() != 6)
                ++bad;
            if (rules::uanwManCatcherPullOffFeetPct() != 25)
                ++bad;
            if (rules::uanwManCatcherPushPullDmgMax() != 2)
                ++bad;
            if (rules::uanwManCatcherPushPullDmgMin() != 1)
                ++bad;
            if (rules::uanwManCatcherSizeBandPct() != 50)
                ++bad;
            if (rules::uanwSapHeadUncoveredRequired() != true)
                ++bad;
            if (rules::uanwSapNonHeadDamageFactorPct() != 50)
                ++bad;
            if (rules::uanwSapUnconsciousPctPerStr() != 5)
                ++bad;
            if (rules::uanwSpikedBucklerExtraAttacksPerRound() != 1)
                ++bad;
            if (rules::uanwSpikedBucklerSecondModeMod() != -2)
                ++bad;
            if (rules::uanwStaffSlingMediumOrLongOnly() != true)
                ++bad;
            if (rules::uanwStaffSlingPoleMinFeet() != 4)
                ++bad;
            if (rules::uanwStaffSlingUsesGrenadeTable() != true)
                ++bad;
            if (rules::uanwWhipDisentangle3d6Minus() != 2)
                ++bad;
            if (rules::uanwWhipEdgedSeveredPct() != 50)
                ++bad;
            if (rules::uanwWhipEntangleHeadNoWeaponPct() != 40)
                ++bad;
            if (rules::uanwWhipEntangleHeadPct() != 20)
                ++bad;
            if (rules::uanwWhipEntangleNonProfPct() != 5)
                ++bad;
            if (rules::uanwWhipEntangleOneLimbPct() != 50)
                ++bad;
            if (rules::uanwWhipEntangleProfPctPerLevel() != 5)
                ++bad;
            if (rules::uanwWhipEntangleTwoLimbsPct() != 10)
                ++bad;
            if (rules::uanwWhipEntangleWeaponArmPct() != 20)
                ++bad;
            if (rules::uanwWhipNoAttackSegments() != 10)
                ++bad;
            if (rules::uanwWhipTwoLimbPronePct() != 25)
                ++bad;
            if (rules::uanwWhipVictimPullPct() != 5)
                ++bad;
            if (rules::uanwWhipVictimPullPctPerStr() != 1)
                ++bad;
            if (rules::uanwWhipWeaponLostPct() != 10)
                ++bad;
            if (rules::uapfArmigersInitialSlots() != 3)
                ++bad;
            if (rules::uapfFacingPageNotesLost() != false)
                ++bad;
            if (rules::uapfHorsemenInitialSlots() != 1)
                ++bad;
            if (rules::uapfLancersInitialSlots() != 2)
                ++bad;
            if (rules::uapfRestrictedWeaponChoice() != true)
                ++bad;
            if (rules::uapfRowCount() != 14)
                ++bad;
            if (rules::uawtNewWeaponCount() != 18)
                ++bad;
            if (rules::uawtNote1ChargingMountDouble() != true)
                ++bad;
            if (rules::uawtNote2SetDoubleVsCharge() != true)
                ++bad;
            if (rules::uawtNote3BladeClassHighInches() != 24)
                ++bad;
            if (rules::uawtNote3BladeClassLowInches() != 15)
                ++bad;
            if (rules::uawtNote4DisarmOnAcEightHit() != 8)
                ++bad;
            if (rules::uawtNote5BastardAsLongSword() != true)
                ++bad;
            if (rules::uawtNote6VariantsSeePhb() != true)
                ++bad;
            if (rules::uawtRowCount() != 68)
                ++bad;
            if (rules::uawtSeamVerifiedCount() != 50)
                ++bad;
            if (rules::weaponSpecArrowDamageHigh() != 16)
                ++bad;
            if (rules::weaponSpecArrowDamageLow() != 6)
                ++bad;
            if (rules::weaponSpecAtCreationOnly() != true)
                ++bad;
            if (rules::weaponSpecBonusesNotMagical() != true)
                ++bad;
            if (rules::weaponSpecBowDoubleDamage() != true)
                ++bad;
            if (rules::weaponSpecBowExtraSlot() != 1)
                ++bad;
            if (rules::weaponSpecBowPointBlankBonus() != 2)
                ++bad;
            if (rules::weaponSpecBowPointBlankMax() != 30)
                ++bad;
            if (rules::weaponSpecBowPointBlankMin() != 6)
                ++bad;
            if (rules::weaponSpecBowShortRangeBonus() != 1)
                ++bad;
            if (rules::weaponSpecBowShortRangeFrom() != 30)
                ++bad;
            if (rules::weaponSpecCrossbowFreeShot() != true)
                ++bad;
            if (rules::weaponSpecCrossbowPointBlankMax() != 60)
                ++bad;
            if (rules::weaponSpecCrossbowPointBlankMin() != 6)
                ++bad;
            if (rules::weaponSpecCrossbowShortBonus() != 1)
                ++bad;
            if (rules::weaponSpecDoubleAllowed() != true)
                ++bad;
            if (rules::weaponSpecDoubleDamageBonus() != 3)
                ++bad;
            if (rules::weaponSpecDoubleMeleeOnly() != true)
                ++bad;
            if (rules::weaponSpecDoubleToHitBonus() != 3)
                ++bad;
            if (rules::weaponSpecExtraAttacks() != true)
                ++bad;
            if (rules::weaponSpecFighterBowOthers() != 1)
                ++bad;
            if (rules::weaponSpecFighterOtherProficiencies() != 2)
                ++bad;
            if (rules::weaponSpecLightBoltDamageHigh() != 12)
                ++bad;
            if (rules::weaponSpecLightBoltDamageLow() != 6)
                ++bad;
            if (rules::weaponSpecMagicStacks() != true)
                ++bad;
            if (rules::weaponSpecMeleeDamageBonus() != 2)
                ++bad;
            if (rules::weaponSpecMeleeToHitBonus() != 1)
                ++bad;
            if (rules::weaponSpecRangerBowOthers() != 0)
                ++bad;
            if (rules::weaponSpecRangerProficiencies() != 1)
                ++bad;
            if (rules::weaponSpecSlots() != 2)
                ++bad;
            if (rules::weaponSpecSpecificTypeRequired() != true)
                ++bad;
            if (rules::weaponSpecTableColumnCount() != 8)
                ++bad;
            if (rules::weaponSpecTableSupersedes() != true)
                ++bad;
            if (rules::weaponlessBehindNegatesShieldAndDex() != true)
                ++bad;
            if (rules::weaponlessHealPerRound() != 1)
                ++bad;
            if (rules::weaponlessMonsterOverbears() != true)
                ++bad;
            if (rules::weaponlessPummelAttacksPerRound() != 2)
                ++bad;
            if (rules::weaponlessTrussRounds() != 1)
                ++bad;
            if (rules::weaponlessUnconsciousGetsVariable() != false)
                ++bad;
            if (rules::wpfKitRecordsMelee() != 1)
                ++bad;
            if (rules::wpfNoteAddedAboveFirst() != 1)
                ++bad;
            if (rules::wpfNoteMeleeMissile() != 1)
                ++bad;
            if (rules::wpfNoteSubsumption() != 1)
                ++bad;
            if (rules::wpfRowCount() != 10)
                ++bad;
            if (rules::fighterAttacksVsSubOneHitDice(0) != 1)
                ++bad;
            if (rules::fighterAttacksVsSubOneHitDice(1) != 1)
                ++bad;
            if (rules::fighterAttacksVsSubOneHitDice(2) != 2)
                ++bad;
            if (rules::grappleHandsFree(0) != true)
                ++bad;
            if (rules::grappleHandsFree(1) != false)
                ++bad;
            if (rules::pummelAutomaticHit(0) != 0)
                ++bad;
            if (rules::pummelAutomaticHit(1) != 1)
                ++bad;
            if (rules::pummelBaseChance(0) != 0)
                ++bad;
            if (rules::pummelBaseChance(1) != 10)
                ++bad;
            if (rules::spearSpeedFactorByLengthFt(0) != 6)
                ++bad;
            if (rules::spearSpeedFactorByLengthFt(1) != 6)
                ++bad;
            if (rules::spearSpeedFactorByLengthFt(4) != 6)
                ++bad;
            if (rules::spearSpeedFactorByLengthFt(5) != 6)
                ++bad;
            if (rules::spearSpeedFactorByLengthFt(6) != 7)
                ++bad;
            if (rules::spearSpeedFactorByLengthFt(12) != 7)
                ++bad;
            if (rules::spearSpeedFactorByLengthFt(13) != 8)
                ++bad;
            if (rules::spearSpeedFactorByLengthFt(14) != 8)
                ++bad;
            if (rules::speedFactorApplies(0) != true)
                ++bad;
            if (rules::speedFactorApplies(1) != false)
                ++bad;
            if (rules::uawtDamagePrintsDash(0) != false)
                ++bad;
            if (rules::uawtDamagePrintsDash(1) != false)
                ++bad;
            if (rules::uawtDamagePrintsDash(34) != false)
                ++bad;
            if (rules::uawtDamagePrintsDash(35) != true)
                ++bad;
            if (rules::uawtDamagePrintsDash(36) != false)
                ++bad;
            if (rules::weaponlessWeaponWielderFirst(0) != true)
                ++bad;
            if (rules::weaponlessWeaponWielderFirst(1) != false)
                ++bad;
            if (rules::wpfRowForBase(0) != 2)
                ++bad;
            if (rules::wpfRowForBase(1) != 5)
                ++bad;
            if (rules::wpfRowForBase(2) != 0)
                ++bad;
            if (rules::wpfRowForBase(3) != 7)
                ++bad;
            if (rules::wpfRowForBase(4) != 2)
                ++bad;
            if (rules::wpfRowForSubclass(-1) != -1)
                ++bad;
            if (rules::wpfRowForSubclass(0) != 3)
                ++bad;
            if (rules::wpfRowForSubclass(1) != 4)
                ++bad;
            if (rules::wpfRowForSubclass(2) != 1)
                ++bad;
            if (rules::wpfRowForSubclass(3) != 6)
                ++bad;
            if (rules::wpfRowForSubclass(4) != 8)
                ++bad;
            if (rules::wpfRowForSubclass(5) != 9)
                ++bad;
            if (rules::wpfRowForSubclass(6) != -1)
                ++bad;
        }
        printf("R1058 weapons registry edges audit: bad %d\n", bad);
    }
