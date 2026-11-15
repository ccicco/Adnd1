    // ==== R1057: uaspells registry ==========
    // The R1057 de-wire: the 68 retiring static
    // arrays of the eighteen rules/ua SPELLS-family
    // headers ride items::MiscItemRegistry from
    // content/tables/ua_spells/ - 49 defs, 28 tables, 40 rows readers;
    // the seven KEPT struct seams and the count fns stay C++,
    // probed here. Eight sections: load, counts,
    // defs-A/B/C/D, seam, edges. Census 1103 -> 1111. DO NOT hand-edit:
    // tools/r1057_splice.py is the only writer.
    {
        int bad = 0;
        // -- 1. load ------------------------------
        {
            items::MiscItemRegistry reg;
            int n = reg.loadDirectory(
                "content/tables/ua_spells");
            if (n != 49) ++bad;
            if (!reg.errors().empty()) ++bad;
            for (const auto& kv : reg.all())
                if ((int)kv.second.sources.size() != 1
                    || kv.second.sources[0].second != 1057)
                    ++bad;
            if (!reg.find("ua_pc_serten")) ++bad;
            if (!reg.find("ua_ast_cleric")) ++bad;
            if (!reg.find("ua_ast_frag")) ++bad;
            if (!reg.find("ua_ast_druid1")) ++bad;
            if (!reg.find("ua_ast_druid4")) ++bad;
            if (!reg.find("ua_ast_druid5")) ++bad;
            if (!reg.find("ua_ast_druid6")) ++bad;
            if (!reg.find("ua_ast_cantrip_cat")) ++bad;
            if (!reg.find("ua_ast_cantrip_names")) ++bad;
            if (!reg.find("ua_s2_mu1")) ++bad;
            if (!reg.find("ua_s2_mu2")) ++bad;
            if (!reg.find("ua_s2_mu3")) ++bad;
            if (!reg.find("ua_s2_mu4")) ++bad;
            if (!reg.find("ua_s2_mu5")) ++bad;
            if (!reg.find("ua_s2_mu6")) ++bad;
            if (!reg.find("ua_s2_mu7")) ++bad;
            if (!reg.find("ua_s2_mu8")) ++bad;
            if (!reg.find("ua_s2_mu9")) ++bad;
            if (!reg.find("ua_s2_il1")) ++bad;
            if (!reg.find("ua_s2_il2")) ++bad;
            if (!reg.find("ua_s2_il7")) ++bad;
            if (!reg.find("ua_s2_ilcantrip")) ++bad;
            if (!reg.find("ua_usc_animal")) ++bad;
            if (!reg.find("ua_usc_site")) ++bad;
            if (!reg.find("ua_ucn")) ++bad;
            if (!reg.find("ua_ucr")) ++bad;
            if (!reg.find("ua_ucl")) ++bad;
            if (!reg.find("ua_ucp")) ++bad;
            if (!reg.find("ua_uco")) ++bad;
            if (!reg.find("ua_uch")) ++bad;
            if (!reg.find("ua_uailc")) ++bad;
            if (!reg.find("ua_uac1")) ++bad;
            if (!reg.find("ua_uac5_animate")) ++bad;
            if (!reg.find("ua_uac5_golem")) ++bad;
            if (!reg.find("ua_uac5_golem_damage")) ++bad;
            if (!reg.find("ua_uac5_golem_sd")) ++bad;
            if (!reg.find("ua_uac5_golem_spells")) ++bad;
            if (!reg.find("ua_uac5_rainbow")) ++bad;
            if (!reg.find("ua_uac5_rainbow_bow")) ++bad;
            if (!reg.find("ua_uac5_rainbow_bow_targets")) ++bad;
            if (!reg.find("ua_uac5_rainbow_flagon")) ++bad;
            if (!reg.find("ua_uac5_rainbow_flagon_effects")) ++bad;
            if (!reg.find("ua_uac7")) ++bad;
            if (!reg.find("ua_uad1")) ++bad;
            if (!reg.find("ua_uad1_poison")) ++bad;
            if (!reg.find("ua_uad2")) ++bad;
            if (!reg.find("ua_uail1_orb")) ++bad;
            if (!reg.find("ua_uasm1")) ++bad;
            if (!reg.find("ua_uasm1_dice")) ++bad;
        }
        printf("R1057 uaspells registry load audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 2. counts --------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/ua_spells");
            {
                const items::MiscItemDef* d =
                    reg.find("ua_pc_serten");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 24
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_pc_sertenRowCount"
                        || d->pins[0].value != 24)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ast_cleric");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 60
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_ast_clericRowCount"
                        || d->pins[0].value != 60)
                        ++bad;
                    if ((int)d->tables.size() != 2) ++bad;
                    if (d->tables[0].name
                        != "frag_count"
                        || (int)d->tables[0]
                            .values.size() != 4)
                        ++bad;
                    if (d->tables[1].name
                        != "readable_count"
                        || (int)d->tables[1]
                            .values.size() != 3)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ast_frag");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 32
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_ast_fragRowCount"
                        || d->pins[0].value != 32)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ast_druid1");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 4
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_ast_druid1RowCount"
                        || d->pins[0].value != 4)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ast_druid4");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 6
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_ast_druid4RowCount"
                        || d->pins[0].value != 6)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ast_druid5");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 6
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_ast_druid5RowCount"
                        || d->pins[0].value != 6)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ast_druid6");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 5
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_ast_druid6RowCount"
                        || d->pins[0].value != 5)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ast_cantrip_cat");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 6
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_ast_cantrip_catRowCount"
                        || d->pins[0].value != 6)
                        ++bad;
                    if ((int)d->tables.size() != 1) ++bad;
                    if (d->tables[0].name
                        != "cantrip_count"
                        || (int)d->tables[0]
                            .values.size() != 6)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ast_cantrip_names");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 120
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_ast_cantrip_namesRowCount"
                        || d->pins[0].value != 120)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_mu1");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 35
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_s2_mu1RowCount"
                        || d->pins[0].value != 35)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_mu2");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 30
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_s2_mu2RowCount"
                        || d->pins[0].value != 30)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_mu3");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 28
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_s2_mu3RowCount"
                        || d->pins[0].value != 28)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_mu4");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 28
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_s2_mu4RowCount"
                        || d->pins[0].value != 28)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_mu5");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 28
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_s2_mu5RowCount"
                        || d->pins[0].value != 28)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_mu6");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 17
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_s2_mu6RowCount"
                        || d->pins[0].value != 17)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_mu7");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 16
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_s2_mu7RowCount"
                        || d->pins[0].value != 16)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_mu8");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 10
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_s2_mu8RowCount"
                        || d->pins[0].value != 10)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_mu9");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 8
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_s2_mu9RowCount"
                        || d->pins[0].value != 8)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_il1");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 5
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_s2_il1RowCount"
                        || d->pins[0].value != 5)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_il2");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 4
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_s2_il2RowCount"
                        || d->pins[0].value != 4)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_il7");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 1
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_s2_il7RowCount"
                        || d->pins[0].value != 1)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_ilcantrip");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 8
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_s2_ilcantripRowCount"
                        || d->pins[0].value != 8)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_usc_animal");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 23
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_usc_animalRowCount"
                        || d->pins[0].value != 23)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_usc_site");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 23
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_usc_siteRowCount"
                        || d->pins[0].value != 23)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ucn");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 20
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_ucnRowCount"
                        || d->pins[0].value != 20)
                        ++bad;
                    if ((int)d->tables.size() != 1) ++bad;
                    if (d->tables[0].name
                        != "cast_den"
                        || (int)d->tables[0]
                            .values.size() != 20)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ucr");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 12
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_ucrRowCount"
                        || d->pins[0].value != 12)
                        ++bad;
                    if ((int)d->tables.size() != 1) ++bad;
                    if (d->tables[0].name
                        != "cast_den"
                        || (int)d->tables[0]
                            .values.size() != 12)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ucl");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 6
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_uclRowCount"
                        || d->pins[0].value != 6)
                        ++bad;
                    if ((int)d->tables.size() != 1) ++bad;
                    if (d->tables[0].name
                        != "cast_den"
                        || (int)d->tables[0]
                            .values.size() != 6)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ucp");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 10
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_ucpRowCount"
                        || d->pins[0].value != 10)
                        ++bad;
                    if ((int)d->tables.size() != 1) ++bad;
                    if (d->tables[0].name
                        != "cast_den"
                        || (int)d->tables[0]
                            .values.size() != 10)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uco");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 10
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_ucoRowCount"
                        || d->pins[0].value != 10)
                        ++bad;
                    if ((int)d->tables.size() != 1) ++bad;
                    if (d->tables[0].name
                        != "cast_den"
                        || (int)d->tables[0]
                            .values.size() != 10)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uch");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 8
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_uchRowCount"
                        || d->pins[0].value != 8)
                        ++bad;
                    if ((int)d->tables.size() != 1) ++bad;
                    if (d->tables[0].name
                        != "cast_den"
                        || (int)d->tables[0]
                            .values.size() != 8)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uailc");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 8
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_uailcRowCount"
                        || d->pins[0].value != 8)
                        ++bad;
                    if ((int)d->tables.size() != 1) ++bad;
                    if (d->tables[0].name
                        != "cast_den"
                        || (int)d->tables[0]
                            .values.size() != 8)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac1");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 10
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_uac1RowCount"
                        || d->pins[0].value != 10)
                        ++bad;
                    if ((int)d->tables.size() != 2) ++bad;
                    if (d->tables[0].name
                        != "portent_mod"
                        || (int)d->tables[0]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[1].name
                        != "variety_level"
                        || (int)d->tables[1]
                            .values.size() != 10)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac5_animate");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 6
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_uac5_animateRowCount"
                        || d->pins[0].value != 6)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac5_golem");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 4
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_uac5_golemRowCount"
                        || d->pins[0].value != 4)
                        ++bad;
                    if ((int)d->tables.size() != 10) ++bad;
                    if (d->tables[0].name
                        != "ac"
                        || (int)d->tables[0]
                            .values.size() != 4)
                        ++bad;
                    if (d->tables[1].name
                        != "at"
                        || (int)d->tables[1]
                            .values.size() != 4)
                        ++bad;
                    if (d->tables[2].name
                        != "build_hours"
                        || (int)d->tables[2]
                            .values.size() != 4)
                        ++bad;
                    if (d->tables[3].name
                        != "carry_pounds"
                        || (int)d->tables[3]
                            .values.size() != 4)
                        ++bad;
                    if (d->tables[4].name
                        != "dur_hours"
                        || (int)d->tables[4]
                            .values.size() != 4)
                        ++bad;
                    if (d->tables[5].name
                        != "hd_base"
                        || (int)d->tables[5]
                            .values.size() != 4)
                        ++bad;
                    if (d->tables[6].name
                        != "hd_bonus"
                        || (int)d->tables[6]
                            .values.size() != 4)
                        ++bad;
                    if (d->tables[7].name
                        != "hp"
                        || (int)d->tables[7]
                            .values.size() != 4)
                        ++bad;
                    if (d->tables[8].name
                        != "min_level"
                        || (int)d->tables[8]
                            .values.size() != 4)
                        ++bad;
                    if (d->tables[9].name
                        != "mv"
                        || (int)d->tables[9]
                            .values.size() != 4)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac5_golem_damage");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 4
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_uac5_golem_damageRowCount"
                        || d->pins[0].value != 4)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac5_golem_sd");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 4
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_uac5_golem_sdRowCount"
                        || d->pins[0].value != 4)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac5_golem_spells");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 4
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_uac5_golem_spellsRowCount"
                        || d->pins[0].value != 4)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac5_rainbow");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 4
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_uac5_rainbowRowCount"
                        || d->pins[0].value != 4)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac5_rainbow_bow");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 7
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_uac5_rainbow_bowRowCount"
                        || d->pins[0].value != 7)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac5_rainbow_bow_targets");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 7
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_uac5_rainbow_bow_targetsRowCount"
                        || d->pins[0].value != 7)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac5_rainbow_flagon");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 7
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_uac5_rainbow_flagonRowCount"
                        || d->pins[0].value != 7)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac5_rainbow_flagon_effects");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 7
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_uac5_rainbow_flagon_effectsRowCount"
                        || d->pins[0].value != 7)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac7");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 3
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_uac7RowCount"
                        || d->pins[0].value != 3)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uad1");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 9
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_uad1RowCount"
                        || d->pins[0].value != 9)
                        ++bad;
                    if ((int)d->tables.size() != 1) ++bad;
                    if (d->tables[0].name
                        != "variety_level"
                        || (int)d->tables[0]
                            .values.size() != 9)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uad1_poison");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 3
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_uad1_poisonRowCount"
                        || d->pins[0].value != 3)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uad2");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 3
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_uad2RowCount"
                        || d->pins[0].value != 3)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uail1_orb");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 9
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_uail1_orbRowCount"
                        || d->pins[0].value != 9)
                        ++bad;
                    if ((int)d->tables.size() != 3) ++bad;
                    if (d->tables[0].name
                        != "orb_damage_max"
                        || (int)d->tables[0]
                            .values.size() != 9)
                        ++bad;
                    if (d->tables[1].name
                        != "orb_damage_min"
                        || (int)d->tables[1]
                            .values.size() != 9)
                        ++bad;
                    if (d->tables[2].name
                        != "orb_level"
                        || (int)d->tables[2]
                            .values.size() != 9)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uasm1");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 12
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_uasm1RowCount"
                        || d->pins[0].value != 12)
                        ++bad;
                    if ((int)d->tables.size() != 1) ++bad;
                    if (d->tables[0].name
                        != "start_hp_min"
                        || (int)d->tables[0]
                            .values.size() != 12)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uasm1_dice");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 12
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_uasm1_diceRowCount"
                        || d->pins[0].value != 12)
                        ++bad;
                    if ((int)d->tables.size() != 1) ++bad;
                    if (d->tables[0].name
                        != "methodv_dice"
                        || (int)d->tables[0]
                            .values.size() != 84)
                        ++bad;
                }
            }
        }
        printf("R1057 uaspells registry counts audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 3. A -----------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/ua_spells");
            {
                const items::MiscItemDef* d =
                    reg.find("ua_pc_serten");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uapcSertenName(0))
                        != "beguiling") ++bad;
                    if (std::string(rules::uapcSertenName(1))
                        != "charm") ++bad;
                    if (std::string(rules::uapcSertenName(2))
                        != "suggestion") ++bad;
                    if (std::string(rules::uapcSertenName(3))
                        != "forget") ++bad;
                    if (std::string(rules::uapcSertenName(4))
                        != "hypnotism") ++bad;
                    if (std::string(rules::uapcSertenName(5))
                        != "ray of enfeeblement") ++bad;
                    if (std::string(rules::uapcSertenName(6))
                        != "person-affecting cantrips") ++bad;
                    if (std::string(rules::uapcSertenName(7))
                        != "command") ++bad;
                    if (std::string(rules::uapcSertenName(8))
                        != "domination") ++bad;
                    if (std::string(rules::uapcSertenName(9))
                        != "fear") ++bad;
                    if (std::string(rules::uapcSertenName(10))
                        != "hold") ++bad;
                    if (std::string(rules::uapcSertenName(11))
                        != "scare") ++bad;
                    if (std::string(rules::uapcSertenName(12))
                        != "spook") ++bad;
                    if (std::string(rules::uapcSertenName(13))
                        != "eyebite") ++bad;
                    if (std::string(rules::uapcSertenName(14))
                        != "cloak of fear") ++bad;
                    if (std::string(rules::uapcSertenName(15))
                        != "geas") ++bad;
                    if (std::string(rules::uapcSertenName(16))
                        != "quest") ++bad;
                    if (std::string(rules::uapcSertenName(17))
                        != "chaos") ++bad;
                    if (std::string(rules::uapcSertenName(18))
                        != "feeblemind") ++bad;
                    if (std::string(rules::uapcSertenName(19))
                        != "Otto's irresistible dance") ++bad;
                    if (std::string(rules::uapcSertenName(20))
                        != "dolor") ++bad;
                    if (std::string(rules::uapcSertenName(21))
                        != "demand") ++bad;
                    if (std::string(rules::uapcSertenName(22))
                        != "torment") ++bad;
                    if (std::string(rules::uapcSertenName(23))
                        != "Leomund's lamentable belabourment") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ast_cleric");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 2) ++bad;
                    if (d->tables[0]
                        .values[1] != 7) ++bad;
                    if (d->tables[0]
                        .values[2] != 4) ++bad;
                    if (d->tables[0]
                        .values[3] != 0) ++bad;
                    if (d->tables[1]
                        .values[0] != 18) ++bad;
                    if (d->tables[1]
                        .values[1] != 16) ++bad;
                    if (d->tables[1]
                        .values[2] != 20) ++bad;
                    if (std::string(rules::uastClericName(1, 0))
                        != "Bless") ++bad;
                    if (std::string(rules::uastClericName(1, 1))
                        != "Ceremony") ++bad;
                    if (std::string(rules::uastClericName(1, 2))
                        != "Combine") ++bad;
                    if (std::string(rules::uastClericName(1, 3))
                        != "Command") ++bad;
                    if (std::string(rules::uastClericName(1, 4))
                        != "Create Water") ++bad;
                    if (std::string(rules::uastClericName(1, 5))
                        != "Cure Light Wounds") ++bad;
                    if (std::string(rules::uastClericName(1, 6))
                        != "") ++bad;
                    if (std::string(rules::uastClericName(1, 7))
                        != "Detect Magic") ++bad;
                    if (std::string(rules::uastClericName(1, 8))
                        != "Endure Cold/Heat") ++bad;
                    if (std::string(rules::uastClericName(1, 9))
                        != "Invisibility to Undead") ++bad;
                    if (std::string(rules::uastClericName(1, 10))
                        != "Light") ++bad;
                    if (std::string(rules::uastClericName(1, 11))
                        != "Magic Stone") ++bad;
                    if (std::string(rules::uastClericName(1, 12))
                        != "Penetrate Disguise") ++bad;
                    if (std::string(rules::uastClericName(1, 13))
                        != "") ++bad;
                    if (std::string(rules::uastClericName(1, 14))
                        != "Precipitation") ++bad;
                    if (std::string(rules::uastClericName(1, 15))
                        != "Protection From Evil") ++bad;
                    if (std::string(rules::uastClericName(1, 16))
                        != "Purify Food & Drink") ++bad;
                    if (std::string(rules::uastClericName(1, 17))
                        != "Remove Fear") ++bad;
                    if (std::string(rules::uastClericName(1, 18))
                        != "Resist Cold") ++bad;
                    if (std::string(rules::uastClericName(1, 19))
                        != "Sanctuary") ++bad;
                    if (std::string(rules::uastClericName(2, 0))
                        != "") ++bad;
                    if (std::string(rules::uastClericName(2, 1))
                        != "") ++bad;
                    if (std::string(rules::uastClericName(2, 2))
                        != "") ++bad;
                    if (std::string(rules::uastClericName(2, 3))
                        != "Detect Charm") ++bad;
                    if (std::string(rules::uastClericName(2, 4))
                        != "Detect Life") ++bad;
                    if (std::string(rules::uastClericName(2, 5))
                        != "Dust Devil") ++bad;
                    if (std::string(rules::uastClericName(2, 6))
                        != "Enthrall") ++bad;
                    if (std::string(rules::uastClericName(2, 7))
                        != "Find Traps") ++bad;
                    if (std::string(rules::uastClericName(2, 8))
                        != "Hold Person") ++bad;
                    if (std::string(rules::uastClericName(2, 9))
                        != "Holy Symbol") ++bad;
                    if (std::string(rules::uastClericName(2, 10))
                        != "Know Alignment") ++bad;
                    if (std::string(rules::uastClericName(2, 11))
                        != "Messenger") ++bad;
                    if (std::string(rules::uastClericName(2, 12))
                        != "Resist Fire") ++bad;
                    if (std::string(rules::uastClericName(2, 13))
                        != "Silence 15 Radius") ++bad;
                    if (std::string(rules::uastClericName(2, 14))
                        != "Slow Poison") ++bad;
                    if (std::string(rules::uastClericName(2, 15))
                        != "Snake Charm") ++bad;
                    if (std::string(rules::uastClericName(2, 16))
                        != "Speak With Animals") ++bad;
                    if (std::string(rules::uastClericName(2, 17))
                        != "Spiritual Hammer") ++bad;
                    if (std::string(rules::uastClericName(2, 18))
                        != "") ++bad;
                    if (std::string(rules::uastClericName(2, 19))
                        != "Wyvern Watch") ++bad;
                    if (std::string(rules::uastClericName(3, 0))
                        != "Animate Dead") ++bad;
                    if (std::string(rules::uastClericName(3, 1))
                        != "Cloudburst") ++bad;
                    if (std::string(rules::uastClericName(3, 2))
                        != "Continual Light") ++bad;
                    if (std::string(rules::uastClericName(3, 3))
                        != "Create Food & Water") ++bad;
                    if (std::string(rules::uastClericName(3, 4))
                        != "Cure Blindness") ++bad;
                    if (std::string(rules::uastClericName(3, 5))
                        != "Cure Disease") ++bad;
                    if (std::string(rules::uastClericName(3, 6))
                        != "Death's Door") ++bad;
                    if (std::string(rules::uastClericName(3, 7))
                        != "Dispel Magic") ++bad;
                    if (std::string(rules::uastClericName(3, 8))
                        != "Feign Death") ++bad;
                    if (std::string(rules::uastClericName(3, 9))
                        != "Flame Walk") ++bad;
                    if (std::string(rules::uastClericName(3, 10))
                        != "Glyph of Warding") ++bad;
                    if (std::string(rules::uastClericName(3, 11))
                        != "Locate Object") ++bad;
                    if (std::string(rules::uastClericName(3, 12))
                        != "Magical Vestment") ++bad;
                    if (std::string(rules::uastClericName(3, 13))
                        != "Meld Into Stone") ++bad;
                    if (std::string(rules::uastClericName(3, 14))
                        != "Negative Plane Protection") ++bad;
                    if (std::string(rules::uastClericName(3, 15))
                        != "Prayer") ++bad;
                    if (std::string(rules::uastClericName(3, 16))
                        != "Remove Curse") ++bad;
                    if (std::string(rules::uastClericName(3, 17))
                        != "Remove Paralysis") ++bad;
                    if (std::string(rules::uastClericName(3, 18))
                        != "Speak With Dead") ++bad;
                    if (std::string(rules::uastClericName(3, 19))
                        != "Water Walk") ++bad;
                    if (rules::uastClericReadableCount(1) != 18) ++bad;
                    if (rules::uastClericReadableCount(2) != 16) ++bad;
                    if (rules::uastClericReadableCount(3) != 20) ++bad;
                    if (rules::uastClericFragCount(4) != 2) ++bad;
                    if (rules::uastClericFragCount(5) != 7) ++bad;
                    if (rules::uastClericFragCount(6) != 4) ++bad;
                    if (rules::uastClericFragCount(7) != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ast_frag");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uastClericFragName(4, 0))
                        != "Sticks to Snakes") ++bad;
                    if (std::string(rules::uastClericFragName(4, 1))
                        != "Tongues") ++bad;
                    if (std::string(rules::uastClericFragName(4, 2))
                        != "") ++bad;
                    if (std::string(rules::uastClericFragName(4, 3))
                        != "") ++bad;
                    if (std::string(rules::uastClericFragName(4, 4))
                        != "") ++bad;
                    if (std::string(rules::uastClericFragName(4, 5))
                        != "") ++bad;
                    if (std::string(rules::uastClericFragName(4, 6))
                        != "") ++bad;
                    if (std::string(rules::uastClericFragName(4, 7))
                        != "") ++bad;
                    if (std::string(rules::uastClericFragName(5, 0))
                        != "Commune") ++bad;
                    if (std::string(rules::uastClericFragName(5, 1))
                        != "Cure Critical Wounds") ++bad;
                    if (std::string(rules::uastClericFragName(5, 2))
                        != "Dispel Evil") ++bad;
                    if (std::string(rules::uastClericFragName(5, 3))
                        != "Magic Font") ++bad;
                    if (std::string(rules::uastClericFragName(5, 4))
                        != "Plane Shift") ++bad;
                    if (std::string(rules::uastClericFragName(5, 5))
                        != "Spike Growth") ++bad;
                    if (std::string(rules::uastClericFragName(5, 6))
                        != "True Seeing") ++bad;
                    if (std::string(rules::uastClericFragName(5, 7))
                        != "") ++bad;
                    if (std::string(rules::uastClericFragName(6, 0))
                        != "Conjure Animals") ++bad;
                    if (std::string(rules::uastClericFragName(6, 1))
                        != "Find The Path") ++bad;
                    if (std::string(rules::uastClericFragName(6, 2))
                        != "Speak With Monsters") ++bad;
                    if (std::string(rules::uastClericFragName(6, 3))
                        != "Stone Tell") ++bad;
                    if (std::string(rules::uastClericFragName(6, 4))
                        != "") ++bad;
                    if (std::string(rules::uastClericFragName(6, 5))
                        != "") ++bad;
                    if (std::string(rules::uastClericFragName(6, 6))
                        != "") ++bad;
                    if (std::string(rules::uastClericFragName(6, 7))
                        != "") ++bad;
                    if (std::string(rules::uastClericFragName(7, 0))
                        != "") ++bad;
                    if (std::string(rules::uastClericFragName(7, 1))
                        != "") ++bad;
                    if (std::string(rules::uastClericFragName(7, 2))
                        != "") ++bad;
                    if (std::string(rules::uastClericFragName(7, 3))
                        != "") ++bad;
                    if (std::string(rules::uastClericFragName(7, 4))
                        != "") ++bad;
                    if (std::string(rules::uastClericFragName(7, 5))
                        != "") ++bad;
                    if (std::string(rules::uastClericFragName(7, 6))
                        != "") ++bad;
                    if (std::string(rules::uastClericFragName(7, 7))
                        != "") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ast_druid1");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uastDruid1stName(0))
                        != "Locate Animals") ++bad;
                    if (std::string(rules::uastDruid1stName(1))
                        != "Invisibility to Animals") ++bad;
                    if (std::string(rules::uastDruid1stName(2))
                        != "Shillelagh") ++bad;
                    if (std::string(rules::uastDruid1stName(3))
                        != "Speak With Animals") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ast_druid4");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uastDruid4thName(0))
                        != "Cure Serious Wounds") ++bad;
                    if (std::string(rules::uastDruid4thName(1))
                        != "Dispel Magic") ++bad;
                    if (std::string(rules::uastDruid4thName(2))
                        != "Hallucinatory Forest") ++bad;
                    if (std::string(rules::uastDruid4thName(3))
                        != "Protection From Lightning") ++bad;
                    if (std::string(rules::uastDruid4thName(4))
                        != "Repel Insects") ++bad;
                    if (std::string(rules::uastDruid4thName(5))
                        != "Speak With Plants") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ast_druid5");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uastDruid5thName(0))
                        != "Commune With Nature") ++bad;
                    if (std::string(rules::uastDruid5thName(1))
                        != "Control Winds") ++bad;
                    if (std::string(rules::uastDruid5thName(2))
                        != "Insect Plague") ++bad;
                    if (std::string(rules::uastDruid5thName(3))
                        != "Sticks To Snakes") ++bad;
                    if (std::string(rules::uastDruid5thName(4))
                        != "Transmute Rock To Mud") ++bad;
                    if (std::string(rules::uastDruid5thName(5))
                        != "Wall Of Fire") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ast_druid6");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uastDruid6thName(0))
                        != "Cure Critical Wounds") ++bad;
                    if (std::string(rules::uastDruid6thName(1))
                        != "Fire Seeds") ++bad;
                    if (std::string(rules::uastDruid6thName(2))
                        != "Turn Wood") ++bad;
                    if (std::string(rules::uastDruid6thName(3))
                        != "Wall Of Thorns") ++bad;
                    if (std::string(rules::uastDruid6thName(4))
                        != "Weather Summoning") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ast_cantrip_cat");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 20) ++bad;
                    if (d->tables[0]
                        .values[1] != 12) ++bad;
                    if (d->tables[0]
                        .values[2] != 6) ++bad;
                    if (d->tables[0]
                        .values[3] != 10) ++bad;
                    if (d->tables[0]
                        .values[4] != 10) ++bad;
                    if (d->tables[0]
                        .values[5] != 8) ++bad;
                    if (std::string(rules::uastCantripCategoryName(0))
                        != "Useful") ++bad;
                    if (std::string(rules::uastCantripCategoryName(1))
                        != "Reversed") ++bad;
                    if (std::string(rules::uastCantripCategoryName(2))
                        != "Legerdemain") ++bad;
                    if (std::string(rules::uastCantripCategoryName(3))
                        != "Person-Affecting") ++bad;
                    if (std::string(rules::uastCantripCategoryName(4))
                        != "Personal") ++bad;
                    if (std::string(rules::uastCantripCategoryName(5))
                        != "Haunting") ++bad;
                    if (rules::uastCantripCount(0) != 20) ++bad;
                    if (rules::uastCantripCount(1) != 12) ++bad;
                    if (rules::uastCantripCount(2) != 6) ++bad;
                    if (rules::uastCantripCount(3) != 10) ++bad;
                    if (rules::uastCantripCount(4) != 10) ++bad;
                    if (rules::uastCantripCount(5) != 8) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ast_cantrip_names");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uastCantripName(0, 0))
                        != "Chill") ++bad;
                    if (std::string(rules::uastCantripName(0, 1))
                        != "Clean") ++bad;
                    if (std::string(rules::uastCantripName(0, 2))
                        != "Color") ++bad;
                    if (std::string(rules::uastCantripName(0, 3))
                        != "Dampen") ++bad;
                    if (std::string(rules::uastCantripName(0, 4))
                        != "Dry") ++bad;
                    if (std::string(rules::uastCantripName(0, 5))
                        != "Dust") ++bad;
                    if (std::string(rules::uastCantripName(0, 6))
                        != "Exterminate") ++bad;
                    if (std::string(rules::uastCantripName(0, 7))
                        != "Flavor") ++bad;
                    if (std::string(rules::uastCantripName(0, 8))
                        != "Freshen") ++bad;
                    if (std::string(rules::uastCantripName(0, 9))
                        != "Gather") ++bad;
                    if (std::string(rules::uastCantripName(0, 10))
                        != "Polish") ++bad;
                    if (std::string(rules::uastCantripName(0, 11))
                        != "Salt") ++bad;
                    if (std::string(rules::uastCantripName(0, 12))
                        != "Shine") ++bad;
                    if (std::string(rules::uastCantripName(0, 13))
                        != "Spice") ++bad;
                    if (std::string(rules::uastCantripName(0, 14))
                        != "Sprout") ++bad;
                    if (std::string(rules::uastCantripName(0, 15))
                        != "Stitch") ++bad;
                    if (std::string(rules::uastCantripName(0, 16))
                        != "Sweeten") ++bad;
                    if (std::string(rules::uastCantripName(0, 17))
                        != "Tie") ++bad;
                    if (std::string(rules::uastCantripName(0, 18))
                        != "Warm") ++bad;
                    if (std::string(rules::uastCantripName(0, 19))
                        != "Wrap") ++bad;
                    if (std::string(rules::uastCantripName(1, 0))
                        != "Curdle") ++bad;
                    if (std::string(rules::uastCantripName(1, 1))
                        != "Dirty") ++bad;
                    if (std::string(rules::uastCantripName(1, 2))
                        != "Dusty") ++bad;
                    if (std::string(rules::uastCantripName(1, 3))
                        != "Hairy") ++bad;
                    if (std::string(rules::uastCantripName(1, 4))
                        != "Knot") ++bad;
                    if (std::string(rules::uastCantripName(1, 5))
                        != "Ravel") ++bad;
                    if (std::string(rules::uastCantripName(1, 6))
                        != "Sour") ++bad;
                    if (std::string(rules::uastCantripName(1, 7))
                        != "Spill") ++bad;
                    if (std::string(rules::uastCantripName(1, 8))
                        != "Tangle") ++bad;
                    if (std::string(rules::uastCantripName(1, 9))
                        != "Tarnish") ++bad;
                    if (std::string(rules::uastCantripName(1, 10))
                        != "Untie") ++bad;
                    if (std::string(rules::uastCantripName(1, 11))
                        != "Wilt") ++bad;
                    if (std::string(rules::uastCantripName(1, 12))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(1, 13))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(1, 14))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(1, 15))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(1, 16))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(1, 17))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(1, 18))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(1, 19))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(2, 0))
                        != "Change") ++bad;
                    if (std::string(rules::uastCantripName(2, 1))
                        != "Distract") ++bad;
                    if (std::string(rules::uastCantripName(2, 2))
                        != "Hide") ++bad;
                    if (std::string(rules::uastCantripName(2, 3))
                        != "Mute") ++bad;
                    if (std::string(rules::uastCantripName(2, 4))
                        != "Palm") ++bad;
                    if (std::string(rules::uastCantripName(2, 5))
                        != "Present") ++bad;
                    if (std::string(rules::uastCantripName(2, 6))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(2, 7))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(2, 8))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(2, 9))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(2, 10))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(2, 11))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(2, 12))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(2, 13))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(2, 14))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(2, 15))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(2, 16))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(2, 17))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(2, 18))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(2, 19))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(3, 0))
                        != "Belch") ++bad;
                    if (std::string(rules::uastCantripName(3, 1))
                        != "Blink") ++bad;
                    if (std::string(rules::uastCantripName(3, 2))
                        != "Cough") ++bad;
                    if (std::string(rules::uastCantripName(3, 3))
                        != "Giggle") ++bad;
                    if (std::string(rules::uastCantripName(3, 4))
                        != "Nod") ++bad;
                    if (std::string(rules::uastCantripName(3, 5))
                        != "Scratch") ++bad;
                    if (std::string(rules::uastCantripName(3, 6))
                        != "Sneeze") ++bad;
                    if (std::string(rules::uastCantripName(3, 7))
                        != "Twitch") ++bad;
                    if (std::string(rules::uastCantripName(3, 8))
                        != "Wink") ++bad;
                    if (std::string(rules::uastCantripName(3, 9))
                        != "Yawn") ++bad;
                    if (std::string(rules::uastCantripName(3, 10))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(3, 11))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(3, 12))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(3, 13))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(3, 14))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(3, 15))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(3, 16))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(3, 17))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(3, 18))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(3, 19))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(4, 0))
                        != "Bee") ++bad;
                    if (std::string(rules::uastCantripName(4, 1))
                        != "Bluelight") ++bad;
                    if (std::string(rules::uastCantripName(4, 2))
                        != "Bug") ++bad;
                    if (std::string(rules::uastCantripName(4, 3))
                        != "Firefinger") ++bad;
                    if (std::string(rules::uastCantripName(4, 4))
                        != "Gnats") ++bad;
                    if (std::string(rules::uastCantripName(4, 5))
                        != "Mouse") ++bad;
                    if (std::string(rules::uastCantripName(4, 6))
                        != "Smokepuff") ++bad;
                    if (std::string(rules::uastCantripName(4, 7))
                        != "Spider") ++bad;
                    if (std::string(rules::uastCantripName(4, 8))
                        != "Tweak") ++bad;
                    if (std::string(rules::uastCantripName(4, 9))
                        != "Unlock") ++bad;
                    if (std::string(rules::uastCantripName(4, 10))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(4, 11))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(4, 12))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(4, 13))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(4, 14))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(4, 15))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(4, 16))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(4, 17))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(4, 18))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(4, 19))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(5, 0))
                        != "Creak") ++bad;
                    if (std::string(rules::uastCantripName(5, 1))
                        != "Footfall") ++bad;
                    if (std::string(rules::uastCantripName(5, 2))
                        != "Groan") ++bad;
                    if (std::string(rules::uastCantripName(5, 3))
                        != "Moan") ++bad;
                    if (std::string(rules::uastCantripName(5, 4))
                        != "Rattle") ++bad;
                    if (std::string(rules::uastCantripName(5, 5))
                        != "Tap") ++bad;
                    if (std::string(rules::uastCantripName(5, 6))
                        != "Thump") ++bad;
                    if (std::string(rules::uastCantripName(5, 7))
                        != "Whistle") ++bad;
                    if (std::string(rules::uastCantripName(5, 8))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(5, 9))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(5, 10))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(5, 11))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(5, 12))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(5, 13))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(5, 14))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(5, 15))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(5, 16))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(5, 17))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(5, 18))
                        != "") ++bad;
                    if (std::string(rules::uastCantripName(5, 19))
                        != "") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_mu1");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uas2Mu1stName(0))
                        != "Affect Normal Fires") ++bad;
                    if (std::string(rules::uas2Mu1stName(1))
                        != "Alarm") ++bad;
                    if (std::string(rules::uas2Mu1stName(2))
                        != "Armor") ++bad;
                    if (std::string(rules::uas2Mu1stName(3))
                        != "Burning Hands") ++bad;
                    if (std::string(rules::uas2Mu1stName(4))
                        != "Charm Person") ++bad;
                    if (std::string(rules::uas2Mu1stName(5))
                        != "Comprehend Languages") ++bad;
                    if (std::string(rules::uas2Mu1stName(6))
                        != "Dancing Lights") ++bad;
                    if (std::string(rules::uas2Mu1stName(7))
                        != "Detect Magic") ++bad;
                    if (std::string(rules::uas2Mu1stName(8))
                        != "Enlarge") ++bad;
                    if (std::string(rules::uas2Mu1stName(9))
                        != "Erase") ++bad;
                    if (std::string(rules::uas2Mu1stName(10))
                        != "Feather Fall") ++bad;
                    if (std::string(rules::uas2Mu1stName(11))
                        != "Find Familiar") ++bad;
                    if (std::string(rules::uas2Mu1stName(12))
                        != "Firewater") ++bad;
                    if (std::string(rules::uas2Mu1stName(13))
                        != "Friends") ++bad;
                    if (std::string(rules::uas2Mu1stName(14))
                        != "Grease") ++bad;
                    if (std::string(rules::uas2Mu1stName(15))
                        != "Hold Portal") ++bad;
                    if (std::string(rules::uas2Mu1stName(16))
                        != "Identify") ++bad;
                    if (std::string(rules::uas2Mu1stName(17))
                        != "Jump") ++bad;
                    if (std::string(rules::uas2Mu1stName(18))
                        != "Light") ++bad;
                    if (std::string(rules::uas2Mu1stName(19))
                        != "Magic Missile") ++bad;
                    if (std::string(rules::uas2Mu1stName(20))
                        != "Melt") ++bad;
                    if (std::string(rules::uas2Mu1stName(21))
                        != "Mending") ++bad;
                    if (std::string(rules::uas2Mu1stName(22))
                        != "Message") ++bad;
                    if (std::string(rules::uas2Mu1stName(23))
                        != "Mount") ++bad;
                    if (std::string(rules::uas2Mu1stName(24))
                        != "Nystul's Magic Aura") ++bad;
                    if (std::string(rules::uas2Mu1stName(25))
                        != "Precipitation") ++bad;
                    if (std::string(rules::uas2Mu1stName(26))
                        != "Protection From Evil") ++bad;
                    if (std::string(rules::uas2Mu1stName(27))
                        != "Read Magic") ++bad;
                    if (std::string(rules::uas2Mu1stName(28))
                        != "Shocking Grasp") ++bad;
                    if (std::string(rules::uas2Mu1stName(29))
                        != "Spider Climb") ++bad;
                    if (std::string(rules::uas2Mu1stName(30))
                        != "Taunt") ++bad;
                    if (std::string(rules::uas2Mu1stName(31))
                        != "Tenser's Floating Disc") ++bad;
                    if (std::string(rules::uas2Mu1stName(32))
                        != "Unseen Servant") ++bad;
                    if (std::string(rules::uas2Mu1stName(33))
                        != "Ventriloquism") ++bad;
                    if (std::string(rules::uas2Mu1stName(34))
                        != "Wizard Mark") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_mu2");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uas2Mu2ndName(0))
                        != "Audible Glamer") ++bad;
                    if (std::string(rules::uas2Mu2ndName(1))
                        != "Bind") ++bad;
                    if (std::string(rules::uas2Mu2ndName(2))
                        != "Continual Light") ++bad;
                    if (std::string(rules::uas2Mu2ndName(3))
                        != "Darkness 15' Radius") ++bad;
                    if (std::string(rules::uas2Mu2ndName(4))
                        != "Detect Evil") ++bad;
                    if (std::string(rules::uas2Mu2ndName(5))
                        != "Detect Invisibility") ++bad;
                    if (std::string(rules::uas2Mu2ndName(6))
                        != "Fool's Gold") ++bad;
                    if (std::string(rules::uas2Mu2ndName(7))
                        != "Forget") ++bad;
                    if (std::string(rules::uas2Mu2ndName(8))
                        != "Invisibility") ++bad;
                    if (std::string(rules::uas2Mu2ndName(9))
                        != "Irritation") ++bad;
                    if (std::string(rules::uas2Mu2ndName(10))
                        != "Knock") ++bad;
                    if (std::string(rules::uas2Mu2ndName(11))
                        != "Know Alignment") ++bad;
                    if (std::string(rules::uas2Mu2ndName(12))
                        != "Leomund's Trap") ++bad;
                    if (std::string(rules::uas2Mu2ndName(13))
                        != "Levitate") ++bad;
                    if (std::string(rules::uas2Mu2ndName(14))
                        != "Locate Object") ++bad;
                    if (std::string(rules::uas2Mu2ndName(15))
                        != "Magic Mouth") ++bad;
                    if (std::string(rules::uas2Mu2ndName(16))
                        != "Melf's Acid Arrow") ++bad;
                    if (std::string(rules::uas2Mu2ndName(17))
                        != "Mirror Image") ++bad;
                    if (std::string(rules::uas2Mu2ndName(18))
                        != "Preserve") ++bad;
                    if (std::string(rules::uas2Mu2ndName(19))
                        != "Pyrotechnics") ++bad;
                    if (std::string(rules::uas2Mu2ndName(20))
                        != "Ray of Enfeeblement") ++bad;
                    if (std::string(rules::uas2Mu2ndName(21))
                        != "Rope Trick") ++bad;
                    if (std::string(rules::uas2Mu2ndName(22))
                        != "Scare") ++bad;
                    if (std::string(rules::uas2Mu2ndName(23))
                        != "Shatter") ++bad;
                    if (std::string(rules::uas2Mu2ndName(24))
                        != "Stinking Cloud") ++bad;
                    if (std::string(rules::uas2Mu2ndName(25))
                        != "Strength") ++bad;
                    if (std::string(rules::uas2Mu2ndName(26))
                        != "Tasha's Uncontrollable Hideous Laughter") ++bad;
                    if (std::string(rules::uas2Mu2ndName(27))
                        != "Whip") ++bad;
                    if (std::string(rules::uas2Mu2ndName(28))
                        != "Wizard Lock") ++bad;
                    if (std::string(rules::uas2Mu2ndName(29))
                        != "Zephyr") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_mu3");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uas2Mu3rdName(0))
                        != "Blink") ++bad;
                    if (std::string(rules::uas2Mu3rdName(1))
                        != "Clairaudience") ++bad;
                    if (std::string(rules::uas2Mu3rdName(2))
                        != "Clairvoyance") ++bad;
                    if (std::string(rules::uas2Mu3rdName(3))
                        != "Dispel Magic") ++bad;
                    if (std::string(rules::uas2Mu3rdName(4))
                        != "Explosive Runes") ++bad;
                    if (std::string(rules::uas2Mu3rdName(5))
                        != "Feign Death") ++bad;
                    if (std::string(rules::uas2Mu3rdName(6))
                        != "Fireball") ++bad;
                    if (std::string(rules::uas2Mu3rdName(7))
                        != "Flame Arrow") ++bad;
                    if (std::string(rules::uas2Mu3rdName(8))
                        != "Fly") ++bad;
                    if (std::string(rules::uas2Mu3rdName(9))
                        != "Gust of Wind") ++bad;
                    if (std::string(rules::uas2Mu3rdName(10))
                        != "Haste") ++bad;
                    if (std::string(rules::uas2Mu3rdName(11))
                        != "Hold Person") ++bad;
                    if (std::string(rules::uas2Mu3rdName(12))
                        != "Infravision") ++bad;
                    if (std::string(rules::uas2Mu3rdName(13))
                        != "Invisibility 10'' Radius") ++bad;
                    if (std::string(rules::uas2Mu3rdName(14))
                        != "Leomund's Tiny Hut") ++bad;
                    if (std::string(rules::uas2Mu3rdName(15))
                        != "Lightning Bolt") ++bad;
                    if (std::string(rules::uas2Mu3rdName(16))
                        != "Melf's Minute Meteor") ++bad;
                    if (std::string(rules::uas2Mu3rdName(17))
                        != "Monster Summoning") ++bad;
                    if (std::string(rules::uas2Mu3rdName(18))
                        != "Phantasmal Force") ++bad;
                    if (std::string(rules::uas2Mu3rdName(19))
                        != "Protection From Evil 10' Radius") ++bad;
                    if (std::string(rules::uas2Mu3rdName(20))
                        != "Protection From Normal Missiles") ++bad;
                    if (std::string(rules::uas2Mu3rdName(21))
                        != "Secret Page") ++bad;
                    if (std::string(rules::uas2Mu3rdName(22))
                        != "Sepia Snake Sigil") ++bad;
                    if (std::string(rules::uas2Mu3rdName(23))
                        != "Slow") ++bad;
                    if (std::string(rules::uas2Mu3rdName(24))
                        != "Suggestion") ++bad;
                    if (std::string(rules::uas2Mu3rdName(25))
                        != "Tongues") ++bad;
                    if (std::string(rules::uas2Mu3rdName(26))
                        != "Water Breathing") ++bad;
                    if (std::string(rules::uas2Mu3rdName(27))
                        != "Wind Wall") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_mu4");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uas2Mu4thName(0))
                        != "Charm Monster") ++bad;
                    if (std::string(rules::uas2Mu4thName(1))
                        != "Confusion") ++bad;
                    if (std::string(rules::uas2Mu4thName(2))
                        != "Dig") ++bad;
                    if (std::string(rules::uas2Mu4thName(3))
                        != "Dimension Door") ++bad;
                    if (std::string(rules::uas2Mu4thName(4))
                        != "Enchanted Weapon") ++bad;
                    if (std::string(rules::uas2Mu4thName(5))
                        != "Evard's Black Tentacles") ++bad;
                    if (std::string(rules::uas2Mu4thName(6))
                        != "Extension I") ++bad;
                    if (std::string(rules::uas2Mu4thName(7))
                        != "Fear") ++bad;
                    if (std::string(rules::uas2Mu4thName(8))
                        != "Fire Charm") ++bad;
                    if (std::string(rules::uas2Mu4thName(9))
                        != "Fire Shield") ++bad;
                    if (std::string(rules::uas2Mu4thName(10))
                        != "Hallucinatory Terrain") ++bad;
                    if (std::string(rules::uas2Mu4thName(11))
                        != "Ice Storm") ++bad;
                    if (std::string(rules::uas2Mu4thName(12))
                        != "Leomund's Secure Shelter") ++bad;
                    if (std::string(rules::uas2Mu4thName(13))
                        != "Magic Mirror") ++bad;
                    if (std::string(rules::uas2Mu4thName(14))
                        != "Massmorph") ++bad;
                    if (std::string(rules::uas2Mu4thName(15))
                        != "Minor Globe of Invulnerability") ++bad;
                    if (std::string(rules::uas2Mu4thName(16))
                        != "Otiluke's Resilient Sphere") ++bad;
                    if (std::string(rules::uas2Mu4thName(17))
                        != "Plant Growth") ++bad;
                    if (std::string(rules::uas2Mu4thName(18))
                        != "Polymorph Other") ++bad;
                    if (std::string(rules::uas2Mu4thName(19))
                        != "Polymorph Self") ++bad;
                    if (std::string(rules::uas2Mu4thName(20))
                        != "Rary's Mnemonic Enhancer") ++bad;
                    if (std::string(rules::uas2Mu4thName(21))
                        != "Remove Curse") ++bad;
                    if (std::string(rules::uas2Mu4thName(22))
                        != "Shout") ++bad;
                    if (std::string(rules::uas2Mu4thName(23))
                        != "Stoneskin") ++bad;
                    if (std::string(rules::uas2Mu4thName(24))
                        != "Ultravision") ++bad;
                    if (std::string(rules::uas2Mu4thName(25))
                        != "Wall of Fire") ++bad;
                    if (std::string(rules::uas2Mu4thName(26))
                        != "Wall of Ice") ++bad;
                    if (std::string(rules::uas2Mu4thName(27))
                        != "Wizard Eye") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_mu5");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uas2Mu5thName(0))
                        != "Airy Water") ++bad;
                    if (std::string(rules::uas2Mu5thName(1))
                        != "Animal Growth") ++bad;
                    if (std::string(rules::uas2Mu5thName(2))
                        != "Animate Dead") ++bad;
                    if (std::string(rules::uas2Mu5thName(3))
                        != "Bigby's Interposing Hand") ++bad;
                    if (std::string(rules::uas2Mu5thName(4))
                        != "Cloudkill") ++bad;
                    if (std::string(rules::uas2Mu5thName(5))
                        != "Conjure Elemental") ++bad;
                    if (std::string(rules::uas2Mu5thName(6))
                        != "Cone of Cold") ++bad;
                    if (std::string(rules::uas2Mu5thName(7))
                        != "Contact Other Plane") ++bad;
                    if (std::string(rules::uas2Mu5thName(8))
                        != "Dismissal") ++bad;
                    if (std::string(rules::uas2Mu5thName(9))
                        != "Distance Distortion") ++bad;
                    if (std::string(rules::uas2Mu5thName(10))
                        != "Extension II") ++bad;
                    if (std::string(rules::uas2Mu5thName(11))
                        != "Fabricate") ++bad;
                    if (std::string(rules::uas2Mu5thName(12))
                        != "Feeblemind") ++bad;
                    if (std::string(rules::uas2Mu5thName(13))
                        != "Hold Monster") ++bad;
                    if (std::string(rules::uas2Mu5thName(14))
                        != "Leomund's Lamentable Belabourment") ++bad;
                    if (std::string(rules::uas2Mu5thName(15))
                        != "Leomund's Secret Chest") ++bad;
                    if (std::string(rules::uas2Mu5thName(16))
                        != "Magic Jar") ++bad;
                    if (std::string(rules::uas2Mu5thName(17))
                        != "Monster Summoning III") ++bad;
                    if (std::string(rules::uas2Mu5thName(18))
                        != "Mordenkainen's Faithful Hound") ++bad;
                    if (std::string(rules::uas2Mu5thName(19))
                        != "Passwall") ++bad;
                    if (std::string(rules::uas2Mu5thName(20))
                        != "Sending") ++bad;
                    if (std::string(rules::uas2Mu5thName(21))
                        != "Stone Shape") ++bad;
                    if (std::string(rules::uas2Mu5thName(22))
                        != "Telekinesis") ++bad;
                    if (std::string(rules::uas2Mu5thName(23))
                        != "Teleport") ++bad;
                    if (std::string(rules::uas2Mu5thName(24))
                        != "Transmute Rock To Mud") ++bad;
                    if (std::string(rules::uas2Mu5thName(25))
                        != "Wall of Force") ++bad;
                    if (std::string(rules::uas2Mu5thName(26))
                        != "Wall of Iron") ++bad;
                    if (std::string(rules::uas2Mu5thName(27))
                        != "Wall of Stone") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_mu6");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uas2Mu6thName(0))
                        != "Chain Lightning") ++bad;
                    if (std::string(rules::uas2Mu6thName(1))
                        != "Contingency") ++bad;
                    if (std::string(rules::uas2Mu6thName(2))
                        != "Control Weather") ++bad;
                    if (std::string(rules::uas2Mu6thName(3))
                        != "Death Spell") ++bad;
                    if (std::string(rules::uas2Mu6thName(4))
                        != "Disintegrate") ++bad;
                    if (std::string(rules::uas2Mu6thName(5))
                        != "Ensnarement") ++bad;
                    if (std::string(rules::uas2Mu6thName(6))
                        != "Eyebite") ++bad;
                    if (std::string(rules::uas2Mu6thName(7))
                        != "Geas") ++bad;
                    if (std::string(rules::uas2Mu6thName(8))
                        != "Invisible Stalker") ++bad;
                    if (std::string(rules::uas2Mu6thName(9))
                        != "Lower Water") ++bad;
                    if (std::string(rules::uas2Mu6thName(10))
                        != "Mordenkainen's Lucubration") ++bad;
                    if (std::string(rules::uas2Mu6thName(11))
                        != "Otiluke's Freezing Sphere") ++bad;
                    if (std::string(rules::uas2Mu6thName(12))
                        != "Part Water") ++bad;
                    if (std::string(rules::uas2Mu6thName(13))
                        != "Project Image") ++bad;
                    if (std::string(rules::uas2Mu6thName(14))
                        != "Stone To Flesh") ++bad;
                    if (std::string(rules::uas2Mu6thName(15))
                        != "Tenser's Transformation") ++bad;
                    if (std::string(rules::uas2Mu6thName(16))
                        != "Transmute Water To Dust") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_mu7");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uas2Mu7thName(0))
                        != "Banishment") ++bad;
                    if (std::string(rules::uas2Mu7thName(1))
                        != "Charm Plants") ++bad;
                    if (std::string(rules::uas2Mu7thName(2))
                        != "Delayed Blast Fireball") ++bad;
                    if (std::string(rules::uas2Mu7thName(3))
                        != "Drawmij's Instant Summons") ++bad;
                    if (std::string(rules::uas2Mu7thName(4))
                        != "Forcecage") ++bad;
                    if (std::string(rules::uas2Mu7thName(5))
                        != "Legend Lore") ++bad;
                    if (std::string(rules::uas2Mu7thName(6))
                        != "Limited Wish") ++bad;
                    if (std::string(rules::uas2Mu7thName(7))
                        != "Monster Summoning V") ++bad;
                    if (std::string(rules::uas2Mu7thName(8))
                        != "Mordenkainen's Magnificent Mansion") ++bad;
                    if (std::string(rules::uas2Mu7thName(9))
                        != "Reverse Gravity") ++bad;
                    if (std::string(rules::uas2Mu7thName(10))
                        != "Sequester") ++bad;
                    if (std::string(rules::uas2Mu7thName(11))
                        != "Teleport Without Error") ++bad;
                    if (std::string(rules::uas2Mu7thName(12))
                        != "Torment") ++bad;
                    if (std::string(rules::uas2Mu7thName(13))
                        != "Truename") ++bad;
                    if (std::string(rules::uas2Mu7thName(14))
                        != "Vanish") ++bad;
                    if (std::string(rules::uas2Mu7thName(15))
                        != "Volley") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_mu8");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uas2Mu8thName(0))
                        != "Binding") ++bad;
                    if (std::string(rules::uas2Mu8thName(1))
                        != "Clone") ++bad;
                    if (std::string(rules::uas2Mu8thName(2))
                        != "Demand") ++bad;
                    if (std::string(rules::uas2Mu8thName(3))
                        != "Mass Invisibility") ++bad;
                    if (std::string(rules::uas2Mu8thName(4))
                        != "Mind Blank") ++bad;
                    if (std::string(rules::uas2Mu8thName(5))
                        != "Monster Summoning VI") ++bad;
                    if (std::string(rules::uas2Mu8thName(6))
                        != "Otiluke's Telekinetic Sphere") ++bad;
                    if (std::string(rules::uas2Mu8thName(7))
                        != "Power Word Blind") ++bad;
                    if (std::string(rules::uas2Mu8thName(8))
                        != "Serten's Spell Immunity") ++bad;
                    if (std::string(rules::uas2Mu8thName(9))
                        != "Sink") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_mu9");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uas2Mu9thName(0))
                        != "Crystalbrittle") ++bad;
                    if (std::string(rules::uas2Mu9thName(1))
                        != "Energy Drain") ++bad;
                    if (std::string(rules::uas2Mu9thName(2))
                        != "Gate") ++bad;
                    if (std::string(rules::uas2Mu9thName(3))
                        != "Mordenkainen's Disjunction") ++bad;
                    if (std::string(rules::uas2Mu9thName(4))
                        != "Prismatic Sphere") ++bad;
                    if (std::string(rules::uas2Mu9thName(5))
                        != "Shape Change") ++bad;
                    if (std::string(rules::uas2Mu9thName(6))
                        != "Succor") ++bad;
                    if (std::string(rules::uas2Mu9thName(7))
                        != "Wish") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_il1");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uas2Il1stName(0))
                        != "Color Spray") ++bad;
                    if (std::string(rules::uas2Il1stName(1))
                        != "Dancing Lights") ++bad;
                    if (std::string(rules::uas2Il1stName(2))
                        != "Darkness") ++bad;
                    if (std::string(rules::uas2Il1stName(3))
                        != "Hypnotism") ++bad;
                    if (std::string(rules::uas2Il1stName(4))
                        != "Phantasmal Force") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_il2");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uas2Il2ndName(0))
                        != "Dispel Illusion") ++bad;
                    if (std::string(rules::uas2Il2ndName(1))
                        != "Hallucinatory Terrain") ++bad;
                    if (std::string(rules::uas2Il2ndName(2))
                        != "Magic Mouth") ++bad;
                    if (std::string(rules::uas2Il2ndName(3))
                        != "Mirror Image") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_il7");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uas2Il7thName(0))
                        != "Shadow Walk") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_ilcantrip");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uas2IlCantripName(0))
                        != "Colored Lights") ++bad;
                    if (std::string(rules::uas2IlCantripName(1))
                        != "Dim") ++bad;
                    if (std::string(rules::uas2IlCantripName(2))
                        != "Haze") ++bad;
                    if (std::string(rules::uas2IlCantripName(3))
                        != "Mask") ++bad;
                    if (std::string(rules::uas2IlCantripName(4))
                        != "Mirage") ++bad;
                    if (std::string(rules::uas2IlCantripName(5))
                        != "Noise") ++bad;
                    if (std::string(rules::uas2IlCantripName(6))
                        != "Rainbow") ++bad;
                    if (std::string(rules::uas2IlCantripName(7))
                        != "Two-D'lusion") ++bad;
                }
            }
        }
        printf("R1057 uaspells registry defs-A audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 4. B -----------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/ua_spells");
            {
                const items::MiscItemDef* d =
                    reg.find("ua_usc_animal");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uscSacredAnimal(0))
                        != "") ++bad;
                    if (std::string(rules::uscSacredAnimal(1))
                        != "") ++bad;
                    if (std::string(rules::uscSacredAnimal(2))
                        != "") ++bad;
                    if (std::string(rules::uscSacredAnimal(3))
                        != "") ++bad;
                    if (std::string(rules::uscSacredAnimal(4))
                        != "") ++bad;
                    if (std::string(rules::uscSacredAnimal(5))
                        != "any bird") ++bad;
                    if (std::string(rules::uscSacredAnimal(6))
                        != "") ++bad;
                    if (std::string(rules::uscSacredAnimal(7))
                        != "stag") ++bad;
                    if (std::string(rules::uscSacredAnimal(8))
                        != "") ++bad;
                    if (std::string(rules::uscSacredAnimal(9))
                        != "") ++bad;
                    if (std::string(rules::uscSacredAnimal(10))
                        != "butterfly") ++bad;
                    if (std::string(rules::uscSacredAnimal(11))
                        != "war dog") ++bad;
                    if (std::string(rules::uscSacredAnimal(12))
                        != "squirrel") ++bad;
                    if (std::string(rules::uscSacredAnimal(13))
                        != "mouse") ++bad;
                    if (std::string(rules::uscSacredAnimal(14))
                        != "raccoon") ++bad;
                    if (std::string(rules::uscSacredAnimal(15))
                        != "white mole") ++bad;
                    if (std::string(rules::uscSacredAnimal(16))
                        != "badger") ++bad;
                    if (std::string(rules::uscSacredAnimal(17))
                        != "") ++bad;
                    if (std::string(rules::uscSacredAnimal(18))
                        != "ox") ++bad;
                    if (std::string(rules::uscSacredAnimal(19))
                        != "bat") ++bad;
                    if (std::string(rules::uscSacredAnimal(20))
                        != "") ++bad;
                    if (std::string(rules::uscSacredAnimal(21))
                        != "skeleton") ++bad;
                    if (std::string(rules::uscSacredAnimal(22))
                        != "cave bear") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_usc_site");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uscWorshipSite(0))
                        != "battlefield") ++bad;
                    if (std::string(rules::uscWorshipSite(1))
                        != "underground temple") ++bad;
                    if (std::string(rules::uscWorshipSite(2))
                        != "underground temple") ++bad;
                    if (std::string(rules::uscWorshipSite(3))
                        != "underground temple") ++bad;
                    if (std::string(rules::uscWorshipSite(4))
                        != "underground temple") ++bad;
                    if (std::string(rules::uscWorshipSite(5))
                        != "open hilltops") ++bad;
                    if (std::string(rules::uscWorshipSite(6))
                        != "never the same place twice") ++bad;
                    if (std::string(rules::uscWorshipSite(7))
                        != "deep forest") ++bad;
                    if (std::string(rules::uscWorshipSite(8))
                        != "by a fountain or spring") ++bad;
                    if (std::string(rules::uscWorshipSite(9))
                        != "small grove") ++bad;
                    if (std::string(rules::uscWorshipSite(10))
                        != "open field") ++bad;
                    if (std::string(rules::uscWorshipSite(11))
                        != "anywhere") ++bad;
                    if (std::string(rules::uscWorshipSite(12))
                        != "the home") ++bad;
                    if (std::string(rules::uscWorshipSite(13))
                        != "anywhere") ++bad;
                    if (std::string(rules::uscWorshipSite(14))
                        != "forest clearing") ++bad;
                    if (std::string(rules::uscWorshipSite(15))
                        != "underground cavern") ++bad;
                    if (std::string(rules::uscWorshipSite(16))
                        != "subterranean temple") ++bad;
                    if (std::string(rules::uscWorshipSite(17))
                        != "underground forge") ++bad;
                    if (std::string(rules::uscWorshipSite(18))
                        != "battlefield") ++bad;
                    if (std::string(rules::uscWorshipSite(19))
                        != "anywhere") ++bad;
                    if (std::string(rules::uscWorshipSite(20))
                        != "anywhere") ++bad;
                    if (std::string(rules::uscWorshipSite(21))
                        != "underground crypt") ++bad;
                    if (std::string(rules::uscWorshipSite(22))
                        != "in a temple within a cave") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ucn");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 2) ++bad;
                    if (d->tables[0]
                        .values[1] != 2) ++bad;
                    if (d->tables[0]
                        .values[2] != 2) ++bad;
                    if (d->tables[0]
                        .values[3] != 2) ++bad;
                    if (d->tables[0]
                        .values[4] != 2) ++bad;
                    if (d->tables[0]
                        .values[5] != 2) ++bad;
                    if (d->tables[0]
                        .values[6] != 10) ++bad;
                    if (d->tables[0]
                        .values[7] != 2) ++bad;
                    if (d->tables[0]
                        .values[8] != 2) ++bad;
                    if (d->tables[0]
                        .values[9] != 8) ++bad;
                    if (d->tables[0]
                        .values[10] != 2) ++bad;
                    if (d->tables[0]
                        .values[11] != 8) ++bad;
                    if (d->tables[0]
                        .values[12] != 2) ++bad;
                    if (d->tables[0]
                        .values[13] != 2) ++bad;
                    if (d->tables[0]
                        .values[14] != 2) ++bad;
                    if (d->tables[0]
                        .values[15] != 2) ++bad;
                    if (d->tables[0]
                        .values[16] != 2) ++bad;
                    if (d->tables[0]
                        .values[17] != 2) ++bad;
                    if (d->tables[0]
                        .values[18] != 2) ++bad;
                    if (d->tables[0]
                        .values[19] != 2) ++bad;
                    if (rules::ucnCastTimeDen(0) != 2) ++bad;
                    if (rules::ucnCastTimeDen(1) != 2) ++bad;
                    if (rules::ucnCastTimeDen(2) != 2) ++bad;
                    if (rules::ucnCastTimeDen(3) != 2) ++bad;
                    if (rules::ucnCastTimeDen(4) != 2) ++bad;
                    if (rules::ucnCastTimeDen(5) != 2) ++bad;
                    if (rules::ucnCastTimeDen(6) != 10) ++bad;
                    if (rules::ucnCastTimeDen(7) != 2) ++bad;
                    if (rules::ucnCastTimeDen(8) != 2) ++bad;
                    if (rules::ucnCastTimeDen(9) != 8) ++bad;
                    if (rules::ucnCastTimeDen(10) != 2) ++bad;
                    if (rules::ucnCastTimeDen(11) != 8) ++bad;
                    if (rules::ucnCastTimeDen(12) != 2) ++bad;
                    if (rules::ucnCastTimeDen(13) != 2) ++bad;
                    if (rules::ucnCastTimeDen(14) != 2) ++bad;
                    if (rules::ucnCastTimeDen(15) != 2) ++bad;
                    if (rules::ucnCastTimeDen(16) != 2) ++bad;
                    if (rules::ucnCastTimeDen(17) != 2) ++bad;
                    if (rules::ucnCastTimeDen(18) != 2) ++bad;
                    if (rules::ucnCastTimeDen(19) != 2) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ucr");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 8) ++bad;
                    if (d->tables[0]
                        .values[1] != 8) ++bad;
                    if (d->tables[0]
                        .values[2] != 8) ++bad;
                    if (d->tables[0]
                        .values[3] != 10) ++bad;
                    if (d->tables[0]
                        .values[4] != 2) ++bad;
                    if (d->tables[0]
                        .values[5] != 10) ++bad;
                    if (d->tables[0]
                        .values[6] != 2) ++bad;
                    if (d->tables[0]
                        .values[7] != 8) ++bad;
                    if (d->tables[0]
                        .values[8] != 8) ++bad;
                    if (d->tables[0]
                        .values[9] != 2) ++bad;
                    if (d->tables[0]
                        .values[10] != 3) ++bad;
                    if (d->tables[0]
                        .values[11] != 2) ++bad;
                    if (rules::ucrCastTimeDen(0) != 8) ++bad;
                    if (rules::ucrCastTimeDen(1) != 8) ++bad;
                    if (rules::ucrCastTimeDen(2) != 8) ++bad;
                    if (rules::ucrCastTimeDen(3) != 10) ++bad;
                    if (rules::ucrCastTimeDen(4) != 2) ++bad;
                    if (rules::ucrCastTimeDen(5) != 10) ++bad;
                    if (rules::ucrCastTimeDen(6) != 2) ++bad;
                    if (rules::ucrCastTimeDen(7) != 8) ++bad;
                    if (rules::ucrCastTimeDen(8) != 8) ++bad;
                    if (rules::ucrCastTimeDen(9) != 2) ++bad;
                    if (rules::ucrCastTimeDen(10) != 3) ++bad;
                    if (rules::ucrCastTimeDen(11) != 2) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ucl");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 10) ++bad;
                    if (d->tables[0]
                        .values[1] != 3) ++bad;
                    if (d->tables[0]
                        .values[2] != 10) ++bad;
                    if (d->tables[0]
                        .values[3] != 10) ++bad;
                    if (d->tables[0]
                        .values[4] != 10) ++bad;
                    if (d->tables[0]
                        .values[5] != 8) ++bad;
                    if (rules::uclCastTimeDen(0) != 10) ++bad;
                    if (rules::uclCastTimeDen(1) != 3) ++bad;
                    if (rules::uclCastTimeDen(2) != 10) ++bad;
                    if (rules::uclCastTimeDen(3) != 10) ++bad;
                    if (rules::uclCastTimeDen(4) != 10) ++bad;
                    if (rules::uclCastTimeDen(5) != 8) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ucp");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 10) ++bad;
                    if (d->tables[0]
                        .values[1] != 10) ++bad;
                    if (d->tables[0]
                        .values[2] != 3) ++bad;
                    if (d->tables[0]
                        .values[3] != 3) ++bad;
                    if (d->tables[0]
                        .values[4] != 10) ++bad;
                    if (d->tables[0]
                        .values[5] != 8) ++bad;
                    if (d->tables[0]
                        .values[6] != 2) ++bad;
                    if (d->tables[0]
                        .values[7] != 3) ++bad;
                    if (d->tables[0]
                        .values[8] != 10) ++bad;
                    if (d->tables[0]
                        .values[9] != 8) ++bad;
                    if (rules::ucpCastTimeDen(0) != 10) ++bad;
                    if (rules::ucpCastTimeDen(1) != 10) ++bad;
                    if (rules::ucpCastTimeDen(2) != 3) ++bad;
                    if (rules::ucpCastTimeDen(3) != 3) ++bad;
                    if (rules::ucpCastTimeDen(4) != 10) ++bad;
                    if (rules::ucpCastTimeDen(5) != 8) ++bad;
                    if (rules::ucpCastTimeDen(6) != 2) ++bad;
                    if (rules::ucpCastTimeDen(7) != 3) ++bad;
                    if (rules::ucpCastTimeDen(8) != 10) ++bad;
                    if (rules::ucpCastTimeDen(9) != 8) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uco");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 2) ++bad;
                    if (d->tables[0]
                        .values[1] != 2) ++bad;
                    if (d->tables[0]
                        .values[2] != 2) ++bad;
                    if (d->tables[0]
                        .values[3] != 3) ++bad;
                    if (d->tables[0]
                        .values[4] != 2) ++bad;
                    if (d->tables[0]
                        .values[5] != 2) ++bad;
                    if (d->tables[0]
                        .values[6] != 3) ++bad;
                    if (d->tables[0]
                        .values[7] != 2) ++bad;
                    if (d->tables[0]
                        .values[8] != 3) ++bad;
                    if (d->tables[0]
                        .values[9] != 2) ++bad;
                    if (rules::ucoCastTimeDen(0) != 2) ++bad;
                    if (rules::ucoCastTimeDen(1) != 2) ++bad;
                    if (rules::ucoCastTimeDen(2) != 2) ++bad;
                    if (rules::ucoCastTimeDen(3) != 3) ++bad;
                    if (rules::ucoCastTimeDen(4) != 2) ++bad;
                    if (rules::ucoCastTimeDen(5) != 2) ++bad;
                    if (rules::ucoCastTimeDen(6) != 3) ++bad;
                    if (rules::ucoCastTimeDen(7) != 2) ++bad;
                    if (rules::ucoCastTimeDen(8) != 3) ++bad;
                    if (rules::ucoCastTimeDen(9) != 2) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uch");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 6) ++bad;
                    if (d->tables[0]
                        .values[1] != 6) ++bad;
                    if (d->tables[0]
                        .values[2] != 6) ++bad;
                    if (d->tables[0]
                        .values[3] != 10) ++bad;
                    if (d->tables[0]
                        .values[4] != 10) ++bad;
                    if (d->tables[0]
                        .values[5] != 6) ++bad;
                    if (d->tables[0]
                        .values[6] != 10) ++bad;
                    if (d->tables[0]
                        .values[7] != 6) ++bad;
                    if (rules::uchCastTimeDen(0) != 6) ++bad;
                    if (rules::uchCastTimeDen(1) != 6) ++bad;
                    if (rules::uchCastTimeDen(2) != 6) ++bad;
                    if (rules::uchCastTimeDen(3) != 10) ++bad;
                    if (rules::uchCastTimeDen(4) != 10) ++bad;
                    if (rules::uchCastTimeDen(5) != 6) ++bad;
                    if (rules::uchCastTimeDen(6) != 10) ++bad;
                    if (rules::uchCastTimeDen(7) != 6) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uailc");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 2) ++bad;
                    if (d->tables[0]
                        .values[1] != 2) ++bad;
                    if (d->tables[0]
                        .values[2] != 2) ++bad;
                    if (d->tables[0]
                        .values[3] != 8) ++bad;
                    if (d->tables[0]
                        .values[4] != 2) ++bad;
                    if (d->tables[0]
                        .values[5] != 8) ++bad;
                    if (d->tables[0]
                        .values[6] != 3) ++bad;
                    if (d->tables[0]
                        .values[7] != 8) ++bad;
                    if (rules::uailcCastTimeDen(0) != 2) ++bad;
                    if (rules::uailcCastTimeDen(1) != 2) ++bad;
                    if (rules::uailcCastTimeDen(2) != 2) ++bad;
                    if (rules::uailcCastTimeDen(3) != 8) ++bad;
                    if (rules::uailcCastTimeDen(4) != 2) ++bad;
                    if (rules::uailcCastTimeDen(5) != 8) ++bad;
                    if (rules::uailcCastTimeDen(6) != 3) ++bad;
                    if (rules::uailcCastTimeDen(7) != 8) ++bad;
                }
            }
        }
        printf("R1057 uaspells registry defs-B audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 5. C -----------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/ua_spells");
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac1");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != -3) ++bad;
                    if (d->tables[0]
                        .values[1] != -2) ++bad;
                    if (d->tables[0]
                        .values[2] != -1) ++bad;
                    if (d->tables[0]
                        .values[3] != 1) ++bad;
                    if (d->tables[0]
                        .values[4] != 2) ++bad;
                    if (d->tables[0]
                        .values[5] != 3) ++bad;
                    if (d->tables[1]
                        .values[0] != 1) ++bad;
                    if (d->tables[1]
                        .values[1] != 1) ++bad;
                    if (d->tables[1]
                        .values[2] != 1) ++bad;
                    if (d->tables[1]
                        .values[3] != 3) ++bad;
                    if (d->tables[1]
                        .values[4] != 3) ++bad;
                    if (d->tables[1]
                        .values[5] != 3) ++bad;
                    if (d->tables[1]
                        .values[6] != 5) ++bad;
                    if (d->tables[1]
                        .values[7] != 5) ++bad;
                    if (d->tables[1]
                        .values[8] != 5) ++bad;
                    if (d->tables[1]
                        .values[9] != 7) ++bad;
                    if (std::string(rules::uac1CeremonyVarietyName(0))
                        != "Coming of Age") ++bad;
                    if (std::string(rules::uac1CeremonyVarietyName(1))
                        != "Burial") ++bad;
                    if (std::string(rules::uac1CeremonyVarietyName(2))
                        != "Marriage") ++bad;
                    if (std::string(rules::uac1CeremonyVarietyName(3))
                        != "Dedication") ++bad;
                    if (std::string(rules::uac1CeremonyVarietyName(4))
                        != "Investiture") ++bad;
                    if (std::string(rules::uac1CeremonyVarietyName(5))
                        != "Consecrate Item") ++bad;
                    if (std::string(rules::uac1CeremonyVarietyName(6))
                        != "Ordination") ++bad;
                    if (std::string(rules::uac1CeremonyVarietyName(7))
                        != "Special Vows") ++bad;
                    if (std::string(rules::uac1CeremonyVarietyName(8))
                        != "Consecrate Ground") ++bad;
                    if (std::string(rules::uac1CeremonyVarietyName(9))
                        != "Anathematize") ++bad;
                    if (rules::uac1CeremonyVarietyLevel(0) != 1) ++bad;
                    if (rules::uac1CeremonyVarietyLevel(1) != 1) ++bad;
                    if (rules::uac1CeremonyVarietyLevel(2) != 1) ++bad;
                    if (rules::uac1CeremonyVarietyLevel(3) != 3) ++bad;
                    if (rules::uac1CeremonyVarietyLevel(4) != 3) ++bad;
                    if (rules::uac1CeremonyVarietyLevel(5) != 3) ++bad;
                    if (rules::uac1CeremonyVarietyLevel(6) != 5) ++bad;
                    if (rules::uac1CeremonyVarietyLevel(7) != 5) ++bad;
                    if (rules::uac1CeremonyVarietyLevel(8) != 5) ++bad;
                    if (rules::uac1CeremonyVarietyLevel(9) != 7) ++bad;
                    if (rules::uac1PortentEffectModifier(1) != -3) ++bad;
                    if (rules::uac1PortentEffectModifier(2) != -2) ++bad;
                    if (rules::uac1PortentEffectModifier(3) != -1) ++bad;
                    if (rules::uac1PortentEffectModifier(4) != 1) ++bad;
                    if (rules::uac1PortentEffectModifier(5) != 2) ++bad;
                    if (rules::uac1PortentEffectModifier(6) != 3) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac5_animate");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uac5AnimateExampleTypeName(0))
                        != "apes (carnivorous and giant)") ++bad;
                    if (std::string(rules::uac5AnimateExampleTypeName(1))
                        != "bugbears") ++bad;
                    if (std::string(rules::uac5AnimateExampleTypeName(2))
                        != "ettins") ++bad;
                    if (std::string(rules::uac5AnimateExampleTypeName(3))
                        != "giants (all varieties)") ++bad;
                    if (std::string(rules::uac5AnimateExampleTypeName(4))
                        != "ogres") ++bad;
                    if (std::string(rules::uac5AnimateExampleTypeName(5))
                        != "trolls") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac5_golem");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 10) ++bad;
                    if (d->tables[0]
                        .values[1] != 8) ++bad;
                    if (d->tables[0]
                        .values[2] != 6) ++bad;
                    if (d->tables[0]
                        .values[3] != 4) ++bad;
                    if (d->tables[1]
                        .values[0] != 2) ++bad;
                    if (d->tables[1]
                        .values[1] != 1) ++bad;
                    if (d->tables[1]
                        .values[2] != 2) ++bad;
                    if (d->tables[1]
                        .values[3] != 1) ++bad;
                    if (d->tables[2]
                        .values[0] != 1) ++bad;
                    if (d->tables[2]
                        .values[1] != 3) ++bad;
                    if (d->tables[2]
                        .values[2] != 9) ++bad;
                    if (d->tables[2]
                        .values[3] != 27) ++bad;
                    if (d->tables[3]
                        .values[0] != 30) ++bad;
                    if (d->tables[3]
                        .values[1] != 40) ++bad;
                    if (d->tables[3]
                        .values[2] != 50) ++bad;
                    if (d->tables[3]
                        .values[3] != 60) ++bad;
                    if (d->tables[4]
                        .values[0] != 1) ++bad;
                    if (d->tables[4]
                        .values[1] != 3) ++bad;
                    if (d->tables[4]
                        .values[2] != 6) ++bad;
                    if (d->tables[4]
                        .values[3] != 12) ++bad;
                    if (d->tables[5]
                        .values[0] != 2) ++bad;
                    if (d->tables[5]
                        .values[1] != 3) ++bad;
                    if (d->tables[5]
                        .values[2] != 4) ++bad;
                    if (d->tables[5]
                        .values[3] != 5) ++bad;
                    if (d->tables[6]
                        .values[0] != 4) ++bad;
                    if (d->tables[6]
                        .values[1] != 6) ++bad;
                    if (d->tables[6]
                        .values[2] != 8) ++bad;
                    if (d->tables[6]
                        .values[3] != 10) ++bad;
                    if (d->tables[7]
                        .values[0] != 20) ++bad;
                    if (d->tables[7]
                        .values[1] != 30) ++bad;
                    if (d->tables[7]
                        .values[2] != 40) ++bad;
                    if (d->tables[7]
                        .values[3] != 50) ++bad;
                    if (d->tables[8]
                        .values[0] != 9) ++bad;
                    if (d->tables[8]
                        .values[1] != 11) ++bad;
                    if (d->tables[8]
                        .values[2] != 13) ++bad;
                    if (d->tables[8]
                        .values[3] != 15) ++bad;
                    if (d->tables[9]
                        .values[0] != 12) ++bad;
                    if (d->tables[9]
                        .values[1] != 9) ++bad;
                    if (d->tables[9]
                        .values[2] != 6) ++bad;
                    if (d->tables[9]
                        .values[3] != 3) ++bad;
                    if (std::string(rules::uac5GolemMaterialName(0))
                        != "straw") ++bad;
                    if (std::string(rules::uac5GolemMaterialName(1))
                        != "rope") ++bad;
                    if (std::string(rules::uac5GolemMaterialName(2))
                        != "leather") ++bad;
                    if (std::string(rules::uac5GolemMaterialName(3))
                        != "wood") ++bad;
                    if (rules::uac5GolemMinLevel(0) != 9) ++bad;
                    if (rules::uac5GolemMinLevel(1) != 11) ++bad;
                    if (rules::uac5GolemMinLevel(2) != 13) ++bad;
                    if (rules::uac5GolemMinLevel(3) != 15) ++bad;
                    if (rules::uac5GolemBuildHours(0) != 1) ++bad;
                    if (rules::uac5GolemBuildHours(1) != 3) ++bad;
                    if (rules::uac5GolemBuildHours(2) != 9) ++bad;
                    if (rules::uac5GolemBuildHours(3) != 27) ++bad;
                    if (rules::uac5GolemDurationHoursPerLevel(0) != 1) ++bad;
                    if (rules::uac5GolemDurationHoursPerLevel(1) != 3) ++bad;
                    if (rules::uac5GolemDurationHoursPerLevel(2) != 6) ++bad;
                    if (rules::uac5GolemDurationHoursPerLevel(3) != 12) ++bad;
                    if (rules::uac5GolemAC(0) != 10) ++bad;
                    if (rules::uac5GolemAC(1) != 8) ++bad;
                    if (rules::uac5GolemAC(2) != 6) ++bad;
                    if (rules::uac5GolemAC(3) != 4) ++bad;
                    if (rules::uac5GolemMV(0) != 12) ++bad;
                    if (rules::uac5GolemMV(1) != 9) ++bad;
                    if (rules::uac5GolemMV(2) != 6) ++bad;
                    if (rules::uac5GolemMV(3) != 3) ++bad;
                    if (rules::uac5GolemHDBase(0) != 2) ++bad;
                    if (rules::uac5GolemHDBase(1) != 3) ++bad;
                    if (rules::uac5GolemHDBase(2) != 4) ++bad;
                    if (rules::uac5GolemHDBase(3) != 5) ++bad;
                    if (rules::uac5GolemHDBonus(0) != 4) ++bad;
                    if (rules::uac5GolemHDBonus(1) != 6) ++bad;
                    if (rules::uac5GolemHDBonus(2) != 8) ++bad;
                    if (rules::uac5GolemHDBonus(3) != 10) ++bad;
                    if (rules::uac5GolemHP(0) != 20) ++bad;
                    if (rules::uac5GolemHP(1) != 30) ++bad;
                    if (rules::uac5GolemHP(2) != 40) ++bad;
                    if (rules::uac5GolemHP(3) != 50) ++bad;
                    if (rules::uac5GolemAT(0) != 2) ++bad;
                    if (rules::uac5GolemAT(1) != 1) ++bad;
                    if (rules::uac5GolemAT(2) != 2) ++bad;
                    if (rules::uac5GolemAT(3) != 1) ++bad;
                    if (rules::uac5GolemCarryPounds(0) != 30) ++bad;
                    if (rules::uac5GolemCarryPounds(1) != 40) ++bad;
                    if (rules::uac5GolemCarryPounds(2) != 50) ++bad;
                    if (rules::uac5GolemCarryPounds(3) != 60) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac5_golem_damage");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uac5GolemDamage(0))
                        != "1-2/1-2") ++bad;
                    if (std::string(rules::uac5GolemDamage(1))
                        != "1-6 plus strangulation") ++bad;
                    if (std::string(rules::uac5GolemDamage(2))
                        != "1-6/1-6") ++bad;
                    if (std::string(rules::uac5GolemDamage(3))
                        != "3-12") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac5_golem_sd");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uac5GolemSD(0))
                        != "immune to piercing, half from blunt") ++bad;
                    if (std::string(rules::uac5GolemSD(1))
                        != "immune to blunt, half from piercing") ++bad;
                    if (std::string(rules::uac5GolemSD(2))
                        != "+1 or better weapon, half from blunt") ++bad;
                    if (std::string(rules::uac5GolemSD(3))
                        != "+1 or better weapon, immune to blunt and piercing") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac5_golem_spells");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uac5GolemMindlessSpellName(0))
                        != "charm") ++bad;
                    if (std::string(rules::uac5GolemMindlessSpellName(1))
                        != "fear") ++bad;
                    if (std::string(rules::uac5GolemMindlessSpellName(2))
                        != "hold") ++bad;
                    if (std::string(rules::uac5GolemMindlessSpellName(3))
                        != "sleep") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac5_rainbow");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uac5RainbowApplicationName(0))
                        != "bow") ++bad;
                    if (std::string(rules::uac5RainbowApplicationName(1))
                        != "bridge") ++bad;
                    if (std::string(rules::uac5RainbowApplicationName(2))
                        != "elevator") ++bad;
                    if (std::string(rules::uac5RainbowApplicationName(3))
                        != "flagon") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac5_rainbow_bow");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uac5RainbowBowColorName(0))
                        != "red") ++bad;
                    if (std::string(rules::uac5RainbowBowColorName(1))
                        != "orange") ++bad;
                    if (std::string(rules::uac5RainbowBowColorName(2))
                        != "yellow") ++bad;
                    if (std::string(rules::uac5RainbowBowColorName(3))
                        != "green") ++bad;
                    if (std::string(rules::uac5RainbowBowColorName(4))
                        != "blue") ++bad;
                    if (std::string(rules::uac5RainbowBowColorName(5))
                        != "indigo") ++bad;
                    if (std::string(rules::uac5RainbowBowColorName(6))
                        != "violet") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac5_rainbow_bow_targets");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uac5RainbowBowColorTarget(0))
                        != "fire dwellers/users") ++bad;
                    if (std::string(rules::uac5RainbowBowColorTarget(1))
                        != "earth elementals") ++bad;
                    if (std::string(rules::uac5RainbowBowColorTarget(2))
                        != "vegetable targets (incl. fungus creatures, shambling mounds, treants)") ++bad;
                    if (std::string(rules::uac5RainbowBowColorTarget(3))
                        != "aquatic creatures and water elementals") ++bad;
                    if (std::string(rules::uac5RainbowBowColorTarget(4))
                        != "aerial creatures, electricity-using creatures, and air elementals") ++bad;
                    if (std::string(rules::uac5RainbowBowColorTarget(5))
                        != "acid-using or poison-using creatures") ++bad;
                    if (std::string(rules::uac5RainbowBowColorTarget(6))
                        != "metallic or regenerating creatures") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac5_rainbow_flagon");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uac5RainbowFlagonDraughtColor(0))
                        != "red") ++bad;
                    if (std::string(rules::uac5RainbowFlagonDraughtColor(1))
                        != "orange") ++bad;
                    if (std::string(rules::uac5RainbowFlagonDraughtColor(2))
                        != "yellow") ++bad;
                    if (std::string(rules::uac5RainbowFlagonDraughtColor(3))
                        != "green") ++bad;
                    if (std::string(rules::uac5RainbowFlagonDraughtColor(4))
                        != "blue") ++bad;
                    if (std::string(rules::uac5RainbowFlagonDraughtColor(5))
                        != "indigo") ++bad;
                    if (std::string(rules::uac5RainbowFlagonDraughtColor(6))
                        != "violet") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac5_rainbow_flagon_effects");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uac5RainbowFlagonDraughtEffect(0))
                        != "cure light wounds") ++bad;
                    if (std::string(rules::uac5RainbowFlagonDraughtEffect(1))
                        != "resist fire") ++bad;
                    if (std::string(rules::uac5RainbowFlagonDraughtEffect(2))
                        != "cure blindness") ++bad;
                    if (std::string(rules::uac5RainbowFlagonDraughtEffect(3))
                        != "slow poison") ++bad;
                    if (std::string(rules::uac5RainbowFlagonDraughtEffect(4))
                        != "cure disease") ++bad;
                    if (std::string(rules::uac5RainbowFlagonDraughtEffect(5))
                        != "resist cold") ++bad;
                    if (std::string(rules::uac5RainbowFlagonDraughtEffect(6))
                        != "remove paralysis") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac7");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uac7SuccorObjectExampleName(0))
                        != "a string of prayer beads") ++bad;
                    if (std::string(rules::uac7SuccorObjectExampleName(1))
                        != "a small clay tablet") ++bad;
                    if (std::string(rules::uac7SuccorObjectExampleName(2))
                        != "an ivory baton") ++bad;
                }
            }
        }
        printf("R1057 uaspells registry defs-C audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 6. D -----------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/ua_spells");
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uad1");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 1) ++bad;
                    if (d->tables[0]
                        .values[1] != 1) ++bad;
                    if (d->tables[0]
                        .values[2] != 1) ++bad;
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
                        .values[8] != 12) ++bad;
                    if (std::string(rules::uad1CeremonyVarietyName(0))
                        != "Coming of Age") ++bad;
                    if (std::string(rules::uad1CeremonyVarietyName(1))
                        != "Rest Eternal") ++bad;
                    if (std::string(rules::uad1CeremonyVarietyName(2))
                        != "Marriage") ++bad;
                    if (std::string(rules::uad1CeremonyVarietyName(3))
                        != "Dedication") ++bad;
                    if (std::string(rules::uad1CeremonyVarietyName(4))
                        != "Investiture") ++bad;
                    if (std::string(rules::uad1CeremonyVarietyName(5))
                        != "Initiation") ++bad;
                    if (std::string(rules::uad1CeremonyVarietyName(6))
                        != "Special Vows") ++bad;
                    if (std::string(rules::uad1CeremonyVarietyName(7))
                        != "Hallowed Ground") ++bad;
                    if (std::string(rules::uad1CeremonyVarietyName(8))
                        != "Cast Out") ++bad;
                    if (rules::uad1CeremonyVarietyCasterLevel(0) != 1) ++bad;
                    if (rules::uad1CeremonyVarietyCasterLevel(1) != 1) ++bad;
                    if (rules::uad1CeremonyVarietyCasterLevel(2) != 1) ++bad;
                    if (rules::uad1CeremonyVarietyCasterLevel(3) != 0) ++bad;
                    if (rules::uad1CeremonyVarietyCasterLevel(4) != 0) ++bad;
                    if (rules::uad1CeremonyVarietyCasterLevel(5) != 0) ++bad;
                    if (rules::uad1CeremonyVarietyCasterLevel(6) != 0) ++bad;
                    if (rules::uad1CeremonyVarietyCasterLevel(7) != 0) ++bad;
                    if (rules::uad1CeremonyVarietyCasterLevel(8) != 12) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uad1_poison");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uad1DetectPoisonTypeName(0))
                        != "Contact (Insinuative)") ++bad;
                    if (std::string(rules::uad1DetectPoisonTypeName(1))
                        != "Ingestive") ++bad;
                    if (std::string(rules::uad1DetectPoisonTypeName(2))
                        != "Respirative (Gas)") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uad2");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uad2ReflectingPoolCastThroughName(0))
                        != "Detect Magic") ++bad;
                    if (std::string(rules::uad2ReflectingPoolCastThroughName(1))
                        != "Detect Snares and Pits") ++bad;
                    if (std::string(rules::uad2ReflectingPoolCastThroughName(2))
                        != "Detect Poison") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uail1_orb");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 4) ++bad;
                    if (d->tables[0]
                        .values[1] != 6) ++bad;
                    if (d->tables[0]
                        .values[2] != 8) ++bad;
                    if (d->tables[0]
                        .values[3] != 10) ++bad;
                    if (d->tables[0]
                        .values[4] != 12) ++bad;
                    if (d->tables[0]
                        .values[5] != 16) ++bad;
                    if (d->tables[0]
                        .values[6] != 8) ++bad;
                    if (d->tables[0]
                        .values[7] != 0) ++bad;
                    if (d->tables[0]
                        .values[8] != 0) ++bad;
                    if (d->tables[1]
                        .values[0] != 1) ++bad;
                    if (d->tables[1]
                        .values[1] != 1) ++bad;
                    if (d->tables[1]
                        .values[2] != 1) ++bad;
                    if (d->tables[1]
                        .values[3] != 1) ++bad;
                    if (d->tables[1]
                        .values[4] != 1) ++bad;
                    if (d->tables[1]
                        .values[5] != 2) ++bad;
                    if (d->tables[1]
                        .values[6] != 2) ++bad;
                    if (d->tables[1]
                        .values[7] != 0) ++bad;
                    if (d->tables[1]
                        .values[8] != 0) ++bad;
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
                        .values[7] != 10) ++bad;
                    if (d->tables[2]
                        .values[8] != 12) ++bad;
                    if (std::string(rules::uail1OrbRowName(0))
                        != "Pearly") ++bad;
                    if (std::string(rules::uail1OrbRowName(1))
                        != "Ruby") ++bad;
                    if (std::string(rules::uail1OrbRowName(2))
                        != "Flame") ++bad;
                    if (std::string(rules::uail1OrbRowName(3))
                        != "Amber") ++bad;
                    if (std::string(rules::uail1OrbRowName(4))
                        != "Emerald") ++bad;
                    if (std::string(rules::uail1OrbRowName(5))
                        != "Turquoise") ++bad;
                    if (std::string(rules::uail1OrbRowName(6))
                        != "Sapphire") ++bad;
                    if (std::string(rules::uail1OrbRowName(7))
                        != "Amethyst") ++bad;
                    if (std::string(rules::uail1OrbRowName(8))
                        != "Ashen") ++bad;
                    if (rules::uail1OrbRowLevel(0) != 1) ++bad;
                    if (rules::uail1OrbRowLevel(1) != 2) ++bad;
                    if (rules::uail1OrbRowLevel(2) != 3) ++bad;
                    if (rules::uail1OrbRowLevel(3) != 4) ++bad;
                    if (rules::uail1OrbRowLevel(4) != 5) ++bad;
                    if (rules::uail1OrbRowLevel(5) != 6) ++bad;
                    if (rules::uail1OrbRowLevel(6) != 7) ++bad;
                    if (rules::uail1OrbRowLevel(7) != 10) ++bad;
                    if (rules::uail1OrbRowLevel(8) != 12) ++bad;
                    if (rules::uail1OrbRowDamageMin(0) != 1) ++bad;
                    if (rules::uail1OrbRowDamageMin(1) != 1) ++bad;
                    if (rules::uail1OrbRowDamageMin(2) != 1) ++bad;
                    if (rules::uail1OrbRowDamageMin(3) != 1) ++bad;
                    if (rules::uail1OrbRowDamageMin(4) != 1) ++bad;
                    if (rules::uail1OrbRowDamageMin(5) != 2) ++bad;
                    if (rules::uail1OrbRowDamageMin(6) != 2) ++bad;
                    if (rules::uail1OrbRowDamageMin(7) != 0) ++bad;
                    if (rules::uail1OrbRowDamageMin(8) != 0) ++bad;
                    if (rules::uail1OrbRowDamageMax(0) != 4) ++bad;
                    if (rules::uail1OrbRowDamageMax(1) != 6) ++bad;
                    if (rules::uail1OrbRowDamageMax(2) != 8) ++bad;
                    if (rules::uail1OrbRowDamageMax(3) != 10) ++bad;
                    if (rules::uail1OrbRowDamageMax(4) != 12) ++bad;
                    if (rules::uail1OrbRowDamageMax(5) != 16) ++bad;
                    if (rules::uail1OrbRowDamageMax(6) != 8) ++bad;
                    if (rules::uail1OrbRowDamageMax(7) != 0) ++bad;
                    if (rules::uail1OrbRowDamageMax(8) != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uasm1");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 6) ++bad;
                    if (d->tables[0]
                        .values[1] != 6) ++bad;
                    if (d->tables[0]
                        .values[2] != 5) ++bad;
                    if (d->tables[0]
                        .values[3] != 5) ++bad;
                    if (d->tables[0]
                        .values[4] != 6) ++bad;
                    if (d->tables[0]
                        .values[5] != 7) ++bad;
                    if (d->tables[0]
                        .values[6] != 9) ++bad;
                    if (d->tables[0]
                        .values[7] != 3) ++bad;
                    if (d->tables[0]
                        .values[8] != 3) ++bad;
                    if (d->tables[0]
                        .values[9] != 4) ++bad;
                    if (d->tables[0]
                        .values[10] != 4) ++bad;
                    if (d->tables[0]
                        .values[11] != 5) ++bad;
                    if (rules::uasm1StartHpMin(0) != 6) ++bad;
                    if (rules::uasm1StartHpMin(1) != 6) ++bad;
                    if (rules::uasm1StartHpMin(2) != 5) ++bad;
                    if (rules::uasm1StartHpMin(3) != 5) ++bad;
                    if (rules::uasm1StartHpMin(4) != 6) ++bad;
                    if (rules::uasm1StartHpMin(5) != 7) ++bad;
                    if (rules::uasm1StartHpMin(6) != 9) ++bad;
                    if (rules::uasm1StartHpMin(7) != 3) ++bad;
                    if (rules::uasm1StartHpMin(8) != 3) ++bad;
                    if (rules::uasm1StartHpMin(9) != 4) ++bad;
                    if (rules::uasm1StartHpMin(10) != 4) ++bad;
                    if (rules::uasm1StartHpMin(11) != 5) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uasm1_dice");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 8) ++bad;
                    if (d->tables[0]
                        .values[1] != 6) ++bad;
                    if (d->tables[0]
                        .values[2] != 4) ++bad;
                    if (d->tables[0]
                        .values[3] != 7) ++bad;
                    if (d->tables[0]
                        .values[4] != 9) ++bad;
                    if (d->tables[0]
                        .values[5] != 3) ++bad;
                    if (d->tables[0]
                        .values[6] != 5) ++bad;
                    if (d->tables[0]
                        .values[7] != 7) ++bad;
                    if (d->tables[0]
                        .values[8] != 5) ++bad;
                    if (d->tables[0]
                        .values[9] != 8) ++bad;
                    if (d->tables[0]
                        .values[10] != 3) ++bad;
                    if (d->tables[0]
                        .values[11] != 6) ++bad;
                    if (d->tables[0]
                        .values[12] != 9) ++bad;
                    if (d->tables[0]
                        .values[13] != 4) ++bad;
                    if (d->tables[0]
                        .values[14] != 7) ++bad;
                    if (d->tables[0]
                        .values[15] != 4) ++bad;
                    if (d->tables[0]
                        .values[16] != 9) ++bad;
                    if (d->tables[0]
                        .values[17] != 5) ++bad;
                    if (d->tables[0]
                        .values[18] != 8) ++bad;
                    if (d->tables[0]
                        .values[19] != 6) ++bad;
                    if (d->tables[0]
                        .values[20] != 3) ++bad;
                    if (d->tables[0]
                        .values[21] != 7) ++bad;
                    if (d->tables[0]
                        .values[22] != 4) ++bad;
                    if (d->tables[0]
                        .values[23] != 8) ++bad;
                    if (d->tables[0]
                        .values[24] != 5) ++bad;
                    if (d->tables[0]
                        .values[25] != 6) ++bad;
                    if (d->tables[0]
                        .values[26] != 9) ++bad;
                    if (d->tables[0]
                        .values[27] != 3) ++bad;
                    if (d->tables[0]
                        .values[28] != 9) ++bad;
                    if (d->tables[0]
                        .values[29] != 3) ++bad;
                    if (d->tables[0]
                        .values[30] != 5) ++bad;
                    if (d->tables[0]
                        .values[31] != 7) ++bad;
                    if (d->tables[0]
                        .values[32] != 8) ++bad;
                    if (d->tables[0]
                        .values[33] != 6) ++bad;
                    if (d->tables[0]
                        .values[34] != 4) ++bad;
                    if (d->tables[0]
                        .values[35] != 9) ++bad;
                    if (d->tables[0]
                        .values[36] != 3) ++bad;
                    if (d->tables[0]
                        .values[37] != 5) ++bad;
                    if (d->tables[0]
                        .values[38] != 7) ++bad;
                    if (d->tables[0]
                        .values[39] != 8) ++bad;
                    if (d->tables[0]
                        .values[40] != 6) ++bad;
                    if (d->tables[0]
                        .values[41] != 4) ++bad;
                    if (d->tables[0]
                        .values[42] != 7) ++bad;
                    if (d->tables[0]
                        .values[43] != 6) ++bad;
                    if (d->tables[0]
                        .values[44] != 8) ++bad;
                    if (d->tables[0]
                        .values[45] != 5) ++bad;
                    if (d->tables[0]
                        .values[46] != 9) ++bad;
                    if (d->tables[0]
                        .values[47] != 4) ++bad;
                    if (d->tables[0]
                        .values[48] != 3) ++bad;
                    if (d->tables[0]
                        .values[49] != 4) ++bad;
                    if (d->tables[0]
                        .values[50] != 9) ++bad;
                    if (d->tables[0]
                        .values[51] != 7) ++bad;
                    if (d->tables[0]
                        .values[52] != 8) ++bad;
                    if (d->tables[0]
                        .values[53] != 6) ++bad;
                    if (d->tables[0]
                        .values[54] != 5) ++bad;
                    if (d->tables[0]
                        .values[55] != 3) ++bad;
                    if (d->tables[0]
                        .values[56] != 3) ++bad;
                    if (d->tables[0]
                        .values[57] != 8) ++bad;
                    if (d->tables[0]
                        .values[58] != 7) ++bad;
                    if (d->tables[0]
                        .values[59] != 9) ++bad;
                    if (d->tables[0]
                        .values[60] != 5) ++bad;
                    if (d->tables[0]
                        .values[61] != 6) ++bad;
                    if (d->tables[0]
                        .values[62] != 4) ++bad;
                    if (d->tables[0]
                        .values[63] != 6) ++bad;
                    if (d->tables[0]
                        .values[64] != 5) ++bad;
                    if (d->tables[0]
                        .values[65] != 3) ++bad;
                    if (d->tables[0]
                        .values[66] != 9) ++bad;
                    if (d->tables[0]
                        .values[67] != 7) ++bad;
                    if (d->tables[0]
                        .values[68] != 4) ++bad;
                    if (d->tables[0]
                        .values[69] != 8) ++bad;
                    if (d->tables[0]
                        .values[70] != 6) ++bad;
                    if (d->tables[0]
                        .values[71] != 7) ++bad;
                    if (d->tables[0]
                        .values[72] != 4) ++bad;
                    if (d->tables[0]
                        .values[73] != 9) ++bad;
                    if (d->tables[0]
                        .values[74] != 8) ++bad;
                    if (d->tables[0]
                        .values[75] != 3) ++bad;
                    if (d->tables[0]
                        .values[76] != 5) ++bad;
                    if (d->tables[0]
                        .values[77] != 7) ++bad;
                    if (d->tables[0]
                        .values[78] != 5) ++bad;
                    if (d->tables[0]
                        .values[79] != 9) ++bad;
                    if (d->tables[0]
                        .values[80] != 8) ++bad;
                    if (d->tables[0]
                        .values[81] != 6) ++bad;
                    if (d->tables[0]
                        .values[82] != 4) ++bad;
                    if (d->tables[0]
                        .values[83] != 3) ++bad;
                    if (rules::uasm1MethodVDice(0, 0) != 8)
                        ++bad;
                    if (rules::uasm1MethodVDice(0, 6) != 5)
                        ++bad;
                    if (rules::uasm1MethodVDice(11, 0) != 7)
                        ++bad;
                    if (rules::uasm1MethodVDice(11, 6) != 3)
                        ++bad;
                }
            }
        }
        printf("R1057 uaspells registry defs-D audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 7. seam ----------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/ua_spells");
            {
                const items::MiscItemDef* d =
                    reg.find("ua_pc_serten");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uapcSertenName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ast_cleric");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < 3; ++i)
                        if (rules::uastClericReadableCount(1 + i)
                            != (int)d->tables[1].values[i])
                            ++bad;
                    for (int i = 0; i < 4; ++i)
                        if (rules::uastClericFragCount(4 + i)
                            != (int)d->tables[0].values[i])
                            ++bad;
                    for (int a = 0; a < 3; ++a)
                        for (int b = 0; b < 20; ++b)
                            if (std::string(rules::uastClericName(1 + a, 0 + b))
                                != d->rows[a * 20 + b].name)
                                ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ast_frag");
                if (!d) { ++bad; } else {
                    for (int a = 0; a < 4; ++a)
                        for (int b = 0; b < 8; ++b)
                            if (std::string(rules::uastClericFragName(4 + a, 0 + b))
                                != d->rows[a * 8 + b].name)
                                ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ast_druid1");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uastDruid1stName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ast_druid4");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uastDruid4thName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ast_druid5");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uastDruid5thName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ast_druid6");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uastDruid6thName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ast_cantrip_cat");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < 6; ++i)
                        if (rules::uastCantripCount(0 + i)
                            != (int)d->tables[0].values[i])
                            ++bad;
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uastCantripCategoryName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ast_cantrip_names");
                if (!d) { ++bad; } else {
                    for (int a = 0; a < 6; ++a)
                        for (int b = 0; b < 20; ++b)
                            if (std::string(rules::uastCantripName(0 + a, 0 + b))
                                != d->rows[a * 20 + b].name)
                                ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_mu1");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uas2Mu1stName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_mu2");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uas2Mu2ndName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_mu3");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uas2Mu3rdName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_mu4");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uas2Mu4thName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_mu5");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uas2Mu5thName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_mu6");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uas2Mu6thName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_mu7");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uas2Mu7thName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_mu8");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uas2Mu8thName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_mu9");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uas2Mu9thName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_il1");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uas2Il1stName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_il2");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uas2Il2ndName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_il7");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uas2Il7thName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_s2_ilcantrip");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uas2IlCantripName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_usc_animal");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uscSacredAnimal(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_usc_site");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uscWorshipSite(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ucn");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < 20; ++i)
                        if (rules::ucnCastTimeDen(0 + i)
                            != (int)d->tables[0].values[i])
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ucr");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < 12; ++i)
                        if (rules::ucrCastTimeDen(0 + i)
                            != (int)d->tables[0].values[i])
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ucl");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < 6; ++i)
                        if (rules::uclCastTimeDen(0 + i)
                            != (int)d->tables[0].values[i])
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ucp");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < 10; ++i)
                        if (rules::ucpCastTimeDen(0 + i)
                            != (int)d->tables[0].values[i])
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uco");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < 10; ++i)
                        if (rules::ucoCastTimeDen(0 + i)
                            != (int)d->tables[0].values[i])
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uch");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < 8; ++i)
                        if (rules::uchCastTimeDen(0 + i)
                            != (int)d->tables[0].values[i])
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uailc");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < 8; ++i)
                        if (rules::uailcCastTimeDen(0 + i)
                            != (int)d->tables[0].values[i])
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac1");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < 10; ++i)
                        if (rules::uac1CeremonyVarietyLevel(0 + i)
                            != (int)d->tables[1].values[i])
                            ++bad;
                    for (int i = 0; i < 6; ++i)
                        if (rules::uac1PortentEffectModifier(1 + i)
                            != (int)d->tables[0].values[i])
                            ++bad;
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uac1CeremonyVarietyName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac5_animate");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uac5AnimateExampleTypeName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac5_golem");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < 4; ++i)
                        if (rules::uac5GolemMinLevel(0 + i)
                            != (int)d->tables[8].values[i])
                            ++bad;
                    for (int i = 0; i < 4; ++i)
                        if (rules::uac5GolemBuildHours(0 + i)
                            != (int)d->tables[2].values[i])
                            ++bad;
                    for (int i = 0; i < 4; ++i)
                        if (rules::uac5GolemDurationHoursPerLevel(0 + i)
                            != (int)d->tables[4].values[i])
                            ++bad;
                    for (int i = 0; i < 4; ++i)
                        if (rules::uac5GolemAC(0 + i)
                            != (int)d->tables[0].values[i])
                            ++bad;
                    for (int i = 0; i < 4; ++i)
                        if (rules::uac5GolemMV(0 + i)
                            != (int)d->tables[9].values[i])
                            ++bad;
                    for (int i = 0; i < 4; ++i)
                        if (rules::uac5GolemHDBase(0 + i)
                            != (int)d->tables[5].values[i])
                            ++bad;
                    for (int i = 0; i < 4; ++i)
                        if (rules::uac5GolemHDBonus(0 + i)
                            != (int)d->tables[6].values[i])
                            ++bad;
                    for (int i = 0; i < 4; ++i)
                        if (rules::uac5GolemHP(0 + i)
                            != (int)d->tables[7].values[i])
                            ++bad;
                    for (int i = 0; i < 4; ++i)
                        if (rules::uac5GolemAT(0 + i)
                            != (int)d->tables[1].values[i])
                            ++bad;
                    for (int i = 0; i < 4; ++i)
                        if (rules::uac5GolemCarryPounds(0 + i)
                            != (int)d->tables[3].values[i])
                            ++bad;
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uac5GolemMaterialName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac5_golem_damage");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uac5GolemDamage(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac5_golem_sd");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uac5GolemSD(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac5_golem_spells");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uac5GolemMindlessSpellName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac5_rainbow");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uac5RainbowApplicationName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac5_rainbow_bow");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uac5RainbowBowColorName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac5_rainbow_bow_targets");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uac5RainbowBowColorTarget(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac5_rainbow_flagon");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uac5RainbowFlagonDraughtColor(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac5_rainbow_flagon_effects");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uac5RainbowFlagonDraughtEffect(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uac7");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uac7SuccorObjectExampleName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uad1");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < 9; ++i)
                        if (rules::uad1CeremonyVarietyCasterLevel(0 + i)
                            != (int)d->tables[0].values[i])
                            ++bad;
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uad1CeremonyVarietyName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uad1_poison");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uad1DetectPoisonTypeName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uad2");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uad2ReflectingPoolCastThroughName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uail1_orb");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < 9; ++i)
                        if (rules::uail1OrbRowLevel(0 + i)
                            != (int)d->tables[2].values[i])
                            ++bad;
                    for (int i = 0; i < 9; ++i)
                        if (rules::uail1OrbRowDamageMin(0 + i)
                            != (int)d->tables[1].values[i])
                            ++bad;
                    for (int i = 0; i < 9; ++i)
                        if (rules::uail1OrbRowDamageMax(0 + i)
                            != (int)d->tables[0].values[i])
                            ++bad;
                    for (int i = 0; i < (int)d->rows.size(); ++i)
                        if (std::string(rules::uail1OrbRowName(0 + i))
                            != d->rows[i].name)
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uasm1");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < 12; ++i)
                        if (rules::uasm1StartHpMin(0 + i)
                            != (int)d->tables[0].values[i])
                            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_uasm1_dice");
                if (!d) { ++bad; } else {
                    for (int i = 0; i < 12; ++i)
                        for (int j = 0; j < 7; ++j)
                            if (rules::uasm1MethodVDice(0 + i, 0 + j)
                                != (int)d->tables[0].values[(i + 0) * 7 + (j + 0)])
                                ++bad;
                }
            }
        }
        printf("R1057 uaspells registry seam audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 8. edges ------------------------------
        {
            if (rules::uastClericReadableCount(0) != 18)
                ++bad;
            if (rules::uastClericReadableCount(1) != 18)
                ++bad;
            if (rules::uastClericReadableCount(3) != 20)
                ++bad;
            if (rules::uastClericReadableCount(4) != 20)
                ++bad;
            if (rules::uastClericFragCount(3) != 2)
                ++bad;
            if (rules::uastClericFragCount(4) != 2)
                ++bad;
            if (rules::uastClericFragCount(7) != 0)
                ++bad;
            if (rules::uastClericFragCount(8) != 0)
                ++bad;
            if (rules::uastCantripCount(-1) != 20)
                ++bad;
            if (rules::uastCantripCount(0) != 20)
                ++bad;
            if (rules::uastCantripCount(5) != 8)
                ++bad;
            if (rules::uastCantripCount(6) != 8)
                ++bad;
            if (rules::ucnCastTimeDen(-1) != 2)
                ++bad;
            if (rules::ucnCastTimeDen(0) != 2)
                ++bad;
            if (rules::ucnCastTimeDen(20) != 2)
                ++bad;
            if (rules::ucrCastTimeDen(-1) != 8)
                ++bad;
            if (rules::ucrCastTimeDen(0) != 8)
                ++bad;
            if (rules::ucrCastTimeDen(12) != 2)
                ++bad;
            if (rules::uclCastTimeDen(-1) != 10)
                ++bad;
            if (rules::uclCastTimeDen(0) != 10)
                ++bad;
            if (rules::uclCastTimeDen(6) != 8)
                ++bad;
            if (rules::ucpCastTimeDen(-1) != 10)
                ++bad;
            if (rules::ucpCastTimeDen(0) != 10)
                ++bad;
            if (rules::ucpCastTimeDen(10) != 8)
                ++bad;
            if (rules::ucoCastTimeDen(-1) != 2)
                ++bad;
            if (rules::ucoCastTimeDen(0) != 2)
                ++bad;
            if (rules::ucoCastTimeDen(10) != 2)
                ++bad;
            if (rules::uchCastTimeDen(-1) != 6)
                ++bad;
            if (rules::uchCastTimeDen(0) != 6)
                ++bad;
            if (rules::uchCastTimeDen(8) != 6)
                ++bad;
            if (rules::uailcCastTimeDen(-1) != 2)
                ++bad;
            if (rules::uailcCastTimeDen(0) != 2)
                ++bad;
            if (rules::uailcCastTimeDen(8) != 8)
                ++bad;
            if (rules::uac1CeremonyVarietyLevel(-1) != 1)
                ++bad;
            if (rules::uac1CeremonyVarietyLevel(0) != 1)
                ++bad;
            if (rules::uac1CeremonyVarietyLevel(10) != 7)
                ++bad;
            if (rules::uac1PortentEffectModifier(0) != -3)
                ++bad;
            if (rules::uac1PortentEffectModifier(1) != -3)
                ++bad;
            if (rules::uac1PortentEffectModifier(6) != 3)
                ++bad;
            if (rules::uac1PortentEffectModifier(7) != 3)
                ++bad;
            if (rules::uac5GolemMinLevel(-1) != 9)
                ++bad;
            if (rules::uac5GolemMinLevel(0) != 9)
                ++bad;
            if (rules::uac5GolemMinLevel(4) != 15)
                ++bad;
            if (rules::uac5GolemBuildHours(-1) != 1)
                ++bad;
            if (rules::uac5GolemBuildHours(0) != 1)
                ++bad;
            if (rules::uac5GolemBuildHours(4) != 27)
                ++bad;
            if (rules::uac5GolemDurationHoursPerLevel(-1) != 1)
                ++bad;
            if (rules::uac5GolemDurationHoursPerLevel(0) != 1)
                ++bad;
            if (rules::uac5GolemDurationHoursPerLevel(4) != 12)
                ++bad;
            if (rules::uac5GolemAC(-1) != 10)
                ++bad;
            if (rules::uac5GolemAC(0) != 10)
                ++bad;
            if (rules::uac5GolemAC(4) != 4)
                ++bad;
            if (rules::uac5GolemMV(-1) != 12)
                ++bad;
            if (rules::uac5GolemMV(0) != 12)
                ++bad;
            if (rules::uac5GolemMV(4) != 3)
                ++bad;
            if (rules::uac5GolemHDBase(-1) != 2)
                ++bad;
            if (rules::uac5GolemHDBase(0) != 2)
                ++bad;
            if (rules::uac5GolemHDBase(4) != 5)
                ++bad;
            if (rules::uac5GolemHDBonus(-1) != 4)
                ++bad;
            if (rules::uac5GolemHDBonus(0) != 4)
                ++bad;
            if (rules::uac5GolemHDBonus(4) != 10)
                ++bad;
            if (rules::uac5GolemHP(-1) != 20)
                ++bad;
            if (rules::uac5GolemHP(0) != 20)
                ++bad;
            if (rules::uac5GolemHP(4) != 50)
                ++bad;
            if (rules::uac5GolemAT(-1) != 2)
                ++bad;
            if (rules::uac5GolemAT(0) != 2)
                ++bad;
            if (rules::uac5GolemAT(4) != 1)
                ++bad;
            if (rules::uac5GolemCarryPounds(-1) != 30)
                ++bad;
            if (rules::uac5GolemCarryPounds(0) != 30)
                ++bad;
            if (rules::uac5GolemCarryPounds(4) != 60)
                ++bad;
            if (rules::uad1CeremonyVarietyCasterLevel(-1) != 1)
                ++bad;
            if (rules::uad1CeremonyVarietyCasterLevel(0) != 1)
                ++bad;
            if (rules::uad1CeremonyVarietyCasterLevel(9) != 12)
                ++bad;
            if (rules::uail1OrbRowLevel(-1) != 1)
                ++bad;
            if (rules::uail1OrbRowLevel(0) != 1)
                ++bad;
            if (rules::uail1OrbRowLevel(9) != 12)
                ++bad;
            if (rules::uail1OrbRowDamageMin(-1) != 1)
                ++bad;
            if (rules::uail1OrbRowDamageMin(0) != 1)
                ++bad;
            if (rules::uail1OrbRowDamageMin(9) != 0)
                ++bad;
            if (rules::uail1OrbRowDamageMax(-1) != 4)
                ++bad;
            if (rules::uail1OrbRowDamageMax(0) != 4)
                ++bad;
            if (rules::uail1OrbRowDamageMax(9) != 0)
                ++bad;
            if (rules::uasm1StartHpMin(-1) != 6)
                ++bad;
            if (rules::uasm1StartHpMin(0) != 6)
                ++bad;
            if (rules::uasm1StartHpMin(12) != 5)
                ++bad;
            if (rules::uasm1MethodVDice(-1, 0) != 8)
                ++bad;
            if (rules::uasm1MethodVDice(12, 6) != 3)
                ++bad;
            if (std::string(rules::uapcSertenName(-1))
                != "") ++bad;
            if (std::string(rules::uapcSertenName(24))
                != "") ++bad;
            if (std::string(rules::uastClericName(0, 0))
                != "Bless") ++bad;
            if (std::string(rules::uastClericName(4, 20))
                != "Water Walk") ++bad;
            if (std::string(rules::uastClericFragName(3, 0))
                != "Sticks to Snakes") ++bad;
            if (std::string(rules::uastClericFragName(8, 8))
                != "") ++bad;
            if (std::string(rules::uastDruid1stName(-1))
                != "Locate Animals") ++bad;
            if (std::string(rules::uastDruid1stName(4))
                != "Speak With Animals") ++bad;
            if (std::string(rules::uastDruid4thName(-1))
                != "Cure Serious Wounds") ++bad;
            if (std::string(rules::uastDruid4thName(6))
                != "Speak With Plants") ++bad;
            if (std::string(rules::uastDruid5thName(-1))
                != "Commune With Nature") ++bad;
            if (std::string(rules::uastDruid5thName(6))
                != "Wall Of Fire") ++bad;
            if (std::string(rules::uastDruid6thName(-1))
                != "Cure Critical Wounds") ++bad;
            if (std::string(rules::uastDruid6thName(5))
                != "Weather Summoning") ++bad;
            if (std::string(rules::uastCantripCategoryName(-1))
                != "Useful") ++bad;
            if (std::string(rules::uastCantripCategoryName(6))
                != "Haunting") ++bad;
            if (std::string(rules::uastCantripName(-1, 0))
                != "Chill") ++bad;
            if (std::string(rules::uastCantripName(6, 20))
                != "") ++bad;
            if (std::string(rules::uas2Mu1stName(-1))
                != "Affect Normal Fires") ++bad;
            if (std::string(rules::uas2Mu1stName(35))
                != "Wizard Mark") ++bad;
            if (std::string(rules::uas2Mu2ndName(-1))
                != "Audible Glamer") ++bad;
            if (std::string(rules::uas2Mu2ndName(30))
                != "Zephyr") ++bad;
            if (std::string(rules::uas2Mu3rdName(-1))
                != "Blink") ++bad;
            if (std::string(rules::uas2Mu3rdName(28))
                != "Wind Wall") ++bad;
            if (std::string(rules::uas2Mu4thName(-1))
                != "Charm Monster") ++bad;
            if (std::string(rules::uas2Mu4thName(28))
                != "Wizard Eye") ++bad;
            if (std::string(rules::uas2Mu5thName(-1))
                != "Airy Water") ++bad;
            if (std::string(rules::uas2Mu5thName(28))
                != "Wall of Stone") ++bad;
            if (std::string(rules::uas2Mu6thName(-1))
                != "Chain Lightning") ++bad;
            if (std::string(rules::uas2Mu6thName(17))
                != "Transmute Water To Dust") ++bad;
            if (std::string(rules::uas2Mu7thName(-1))
                != "Banishment") ++bad;
            if (std::string(rules::uas2Mu7thName(16))
                != "Volley") ++bad;
            if (std::string(rules::uas2Mu8thName(-1))
                != "Binding") ++bad;
            if (std::string(rules::uas2Mu8thName(10))
                != "Sink") ++bad;
            if (std::string(rules::uas2Mu9thName(-1))
                != "Crystalbrittle") ++bad;
            if (std::string(rules::uas2Mu9thName(8))
                != "Wish") ++bad;
            if (std::string(rules::uas2Il1stName(-1))
                != "Color Spray") ++bad;
            if (std::string(rules::uas2Il1stName(5))
                != "Phantasmal Force") ++bad;
            if (std::string(rules::uas2Il2ndName(-1))
                != "Dispel Illusion") ++bad;
            if (std::string(rules::uas2Il2ndName(4))
                != "Mirror Image") ++bad;
            if (std::string(rules::uas2Il7thName(-1))
                != "Shadow Walk") ++bad;
            if (std::string(rules::uas2Il7thName(1))
                != "") ++bad;
            if (std::string(rules::uas2IlCantripName(-1))
                != "Colored Lights") ++bad;
            if (std::string(rules::uas2IlCantripName(8))
                != "Two-D'lusion") ++bad;
            if (std::string(rules::uscSacredAnimal(-1))
                != "") ++bad;
            if (std::string(rules::uscSacredAnimal(23))
                != "cave bear") ++bad;
            if (std::string(rules::uscWorshipSite(-1))
                != "battlefield") ++bad;
            if (std::string(rules::uscWorshipSite(23))
                != "in a temple within a cave") ++bad;
            if (std::string(rules::uac1CeremonyVarietyName(-1))
                != "Coming of Age") ++bad;
            if (std::string(rules::uac1CeremonyVarietyName(10))
                != "Anathematize") ++bad;
            if (std::string(rules::uac5AnimateExampleTypeName(-1))
                != "apes (carnivorous and giant)") ++bad;
            if (std::string(rules::uac5AnimateExampleTypeName(6))
                != "trolls") ++bad;
            if (std::string(rules::uac5GolemMaterialName(-1))
                != "straw") ++bad;
            if (std::string(rules::uac5GolemMaterialName(4))
                != "wood") ++bad;
            if (std::string(rules::uac5GolemDamage(-1))
                != "1-2/1-2") ++bad;
            if (std::string(rules::uac5GolemDamage(4))
                != "3-12") ++bad;
            if (std::string(rules::uac5GolemSD(-1))
                != "immune to piercing, half from blunt") ++bad;
            if (std::string(rules::uac5GolemSD(4))
                != "+1 or better weapon, immune to blunt and piercing") ++bad;
            if (std::string(rules::uac5GolemMindlessSpellName(-1))
                != "charm") ++bad;
            if (std::string(rules::uac5GolemMindlessSpellName(4))
                != "sleep") ++bad;
            if (std::string(rules::uac5RainbowApplicationName(-1))
                != "bow") ++bad;
            if (std::string(rules::uac5RainbowApplicationName(4))
                != "flagon") ++bad;
            if (std::string(rules::uac5RainbowBowColorName(-1))
                != "red") ++bad;
            if (std::string(rules::uac5RainbowBowColorName(7))
                != "violet") ++bad;
            if (std::string(rules::uac5RainbowBowColorTarget(-1))
                != "fire dwellers/users") ++bad;
            if (std::string(rules::uac5RainbowBowColorTarget(7))
                != "metallic or regenerating creatures") ++bad;
            if (std::string(rules::uac5RainbowFlagonDraughtColor(-1))
                != "red") ++bad;
            if (std::string(rules::uac5RainbowFlagonDraughtColor(7))
                != "violet") ++bad;
            if (std::string(rules::uac5RainbowFlagonDraughtEffect(-1))
                != "cure light wounds") ++bad;
            if (std::string(rules::uac5RainbowFlagonDraughtEffect(7))
                != "remove paralysis") ++bad;
            if (std::string(rules::uac7SuccorObjectExampleName(-1))
                != "a string of prayer beads") ++bad;
            if (std::string(rules::uac7SuccorObjectExampleName(3))
                != "an ivory baton") ++bad;
            if (std::string(rules::uad1CeremonyVarietyName(-1))
                != "Coming of Age") ++bad;
            if (std::string(rules::uad1CeremonyVarietyName(9))
                != "Cast Out") ++bad;
            if (std::string(rules::uad1DetectPoisonTypeName(-1))
                != "Contact (Insinuative)") ++bad;
            if (std::string(rules::uad1DetectPoisonTypeName(3))
                != "Respirative (Gas)") ++bad;
            if (std::string(rules::uad2ReflectingPoolCastThroughName(-1))
                != "Detect Magic") ++bad;
            if (std::string(rules::uad2ReflectingPoolCastThroughName(3))
                != "Detect Poison") ++bad;
            if (std::string(rules::uail1OrbRowName(-1))
                != "Pearly") ++bad;
            if (std::string(rules::uail1OrbRowName(9))
                != "Ashen") ++bad;
            if (rules::uac1BurialDisintererFleeTurns() != 1)
                ++bad;
            if (rules::uac1BurialProtectionWeeks() != 1)
                ++bad;
            if (rules::uac1CentralClericNoExtraSpells() != true)
                ++bad;
            if (rules::uac1CeremonyCastingTimeHours() != 1)
                ++bad;
            if (rules::uac1CeremonyNoSaveExceptAnathematize() != true)
                ++bad;
            if (rules::uac1CeremonyVarietyCount() != 10)
                ++bad;
            if (rules::uac1CombineAttackerToHitBonus() != 4)
                ++bad;
            if (rules::uac1CombineClericsMax() != 5)
                ++bad;
            if (rules::uac1CombineClericsMin() != 3)
                ++bad;
            if (rules::uac1CombineComponentsLost() != true)
                ++bad;
            if (rules::uac1CombineEncirclingNoShieldOrDexAc() != true)
                ++bad;
            if (rules::uac1CombineLevelGainPerEncircling() != 1)
                ++bad;
            if (rules::uac1CombineMaxDurationTurns() != 3)
                ++bad;
            if (rules::uac1CombineMaxGainLevels() != 4)
                ++bad;
            if (rules::uac1ComingOfAgeSaveBonus() != 1)
                ++bad;
            if (rules::uac1ComingOfAgeUsualAge() != 12)
                ++bad;
            if (rules::uac1ConsecrateGroundEvilClericLevel() != 3)
                ++bad;
            if (rules::uac1CostAnathematizeNoCharge() != true)
                ++bad;
            if (rules::uac1CostComingOfAgeMaxSp() != 15)
                ++bad;
            if (rules::uac1CostComingOfAgeMinSp() != 5)
                ++bad;
            if (rules::uac1CostConsecrateGroundMaxGp() != 600)
                ++bad;
            if (rules::uac1CostConsecrateGroundMinGp() != 100)
                ++bad;
            if (rules::uac1CostSpecialVowsMaxGp() != 100)
                ++bad;
            if (rules::uac1CostSpecialVowsMinGp() != 1)
                ++bad;
            if (rules::uac1CostSpecialVowsSometimesFree() != true)
                ++bad;
            if (rules::uac1EndureCancelledByMagicalColdOrHeat() != true)
                ++bad;
            if (rules::uac1EndureColdLowFLimit() != -30)
                ++bad;
            if (rules::uac1EndureDurationTurnsPerLevel() != 9)
                ++bad;
            if (rules::uac1EndureExposureDamagePerHourPerDegree() != 1)
                ++bad;
            if (rules::uac1EndureHeatHighFLimit() != 130)
                ++bad;
            if (rules::uac1EndureNoDamageInBreakingRound() != true)
                ++bad;
            if (rules::uac1EndureResistFireOrColdCancels() != true)
                ++bad;
            if (rules::uac1EndureReversible() != true)
                ++bad;
            if (rules::uac1ItuCastingTimeSegments() != 4)
                ++bad;
            if (rules::uac1ItuDurationRounds() != 6)
                ++bad;
            if (rules::uac1ItuEndsIfCasterActs() != true)
                ++bad;
            if (rules::uac1ItuMaterialHolySymbol() != true)
                ++bad;
            if (rules::uac1ItuMaxHitDice() != 4)
                ++bad;
            if (rules::uac1ItuNegatesOwnTurning() != true)
                ++bad;
            if (rules::uac1ItuNeutralCasterSaveMod() != -2)
                ++bad;
            if (rules::uac1ItuRadiusFeet() != 30)
                ++bad;
            if (rules::uac1ItuSavePerType() != true)
                ++bad;
            if (rules::uac1MagicStoneComponentsLost() != true)
                ++bad;
            if (rules::uac1MagicStoneDamagePoints() != 1)
                ++bad;
            if (rules::uac1MagicStoneDurationRounds() != 6)
                ++bad;
            if (rules::uac1MagicStoneDweomerWindowRounds() != 6)
                ++bad;
            if (rules::uac1MagicStoneGiveToAnother() != true)
                ++bad;
            if (rules::uac1MagicStoneInnateResistImmune() != true)
                ++bad;
            if (rules::uac1MagicStoneRangeInches() != 2)
                ++bad;
            if (rules::uac1MagicStoneShieldBlocks() != true)
                ++bad;
            if (rules::uac1MagicStoneSomeReligionsForbid() != true)
                ++bad;
            if (rules::uac1MagicStoneThrowRangeInches() != 4)
                ++bad;
            if (rules::uac1MagicStoneToHitBonus() != 1)
                ++bad;
            if (rules::uac1PenetrateCannotDetectAlignmentDeception() != true)
                ++bad;
            if (rules::uac1PenetrateCannotIdClassOrStatus() != true)
                ++bad;
            if (rules::uac1PenetrateCannotRevealIllusion() != true)
                ++bad;
            if (rules::uac1PenetrateCastingTimeRounds() != 2)
                ++bad;
            if (rules::uac1PenetrateDetectsFriendsSpellObject() != true)
                ++bad;
            if (rules::uac1PenetrateDurationRounds() != 1)
                ++bad;
            if (rules::uac1PenetrateProtectionGrantsSaveBonus() != true)
                ++bad;
            if (rules::uac1PenetrateRangeLost() != true)
                ++bad;
            if (rules::uac1PenetrateSeesNonMagicalDisguise() != true)
                ++bad;
            if (rules::uac1PenetrateTargetSaveEnhancesDisguise() != true)
                ++bad;
            if (rules::uac1PortentCastingTimeTurns() != 1)
                ++bad;
            if (rules::uac1PortentContrivedRollsSuspended() != true)
                ++bad;
            if (rules::uac1PortentEffectDieSides() != 6)
                ++bad;
            if (rules::uac1PortentMaterialLost() != true)
                ++bad;
            if (rules::uac1PortentOnlyLifeOrDeathRolls() != true)
                ++bad;
            if (rules::uac1PortentTableHoleDecoded() != true)
                ++bad;
            if (rules::uac1PortentTimingDieSides() != 12)
                ++bad;
            if (rules::uac1PrecipCandleOutSegments() != 1)
                ++bad;
            if (rules::uac1PrecipComponentsLost() != true)
                ++bad;
            if (rules::uac1PrecipCylinderDiameterInches() != 3)
                ++bad;
            if (rules::uac1PrecipCylinderHeightInches() != 12)
                ++bad;
            if (rules::uac1PrecipDurationSegmentsPerLevel() != 1)
                ++bad;
            if (rules::uac1PrecipFlatSurfaceDampSegments() != 1)
                ++bad;
            if (rules::uac1PrecipHeavyMaterialDampSegments() != 2)
                ++bad;
            if (rules::uac1PrecipHotTempDoublesAboveF() != 90)
                ++bad;
            if (rules::uac1PrecipLargeFiresUnaffected() != true)
                ++bad;
            if (rules::uac1PrecipMagicalColdFormsIce() != true)
                ++bad;
            if (rules::uac1PrecipMagicalHeatFogAreaMultiplier() != 2)
                ++bad;
            if (rules::uac1PrecipMaterialSilverDust() != true)
                ++bad;
            if (rules::uac1PrecipPorousAbsorbs() != true)
                ++bad;
            if (rules::uac1PrecipSemiPorousWetAfterSegments() != 5)
                ++bad;
            if (rules::uac1PrecipSleetHighF() != 33)
                ++bad;
            if (rules::uac1PrecipSleetLowF() != 31)
                ++bad;
            if (rules::uac1PrecipSmallFireSmokyRounds() != 1)
                ++bad;
            if (rules::uac1PrecipSnowAtOrBelowF() != 30)
                ++bad;
            if (rules::uac1PrecipThinMaterialDampSegments() != 1)
                ++bad;
            if (rules::uac1SpecialVowsBestowCurseImmunity() != true)
                ++bad;
            if (rules::uac1SpecialVowsQuestSaveMod() != -4)
                ++bad;
            if (rules::uac1UnconsecratedCollapsePctPerYear() != 1)
                ++bad;
            if (rules::uac1UnprotectedExposureDamagePerTurnPerDegree() != 1)
                ++bad;
            if (rules::uac5AirwalkAlwaysInControl() != true)
                ++bad;
            if (rules::uac5AirwalkAoeOneCreature() != true)
                ++bad;
            if (rules::uac5AirwalkAscent45Divisor() != 2)
                ++bad;
            if (rules::uac5AirwalkAscent60Divisor() != 4)
                ++bad;
            if (rules::uac5AirwalkAscentStraightDivisor() != 8)
                ++bad;
            if (rules::uac5AirwalkBeastNeedsTraining() != true)
                ++bad;
            if (rules::uac5AirwalkCastingTimeSegments() != 1)
                ++bad;
            if (rules::uac5AirwalkComponentsVSM() != true)
                ++bad;
            if (rules::uac5AirwalkDescentStraightMultiple() != 8)
                ++bad;
            if (rules::uac5AirwalkDurationTurnsBase() != 6)
                ++bad;
            if (rules::uac5AirwalkDurationTurnsPerLevel() != 1)
                ++bad;
            if (rules::uac5AirwalkGustInterplay() != true)
                ++bad;
            if (rules::uac5AirwalkGustIntoDivisor() != 2)
                ++bad;
            if (rules::uac5AirwalkGustWithMultiple() != 2)
                ++bad;
            if (rules::uac5AirwalkMaterialSymbolThistledown() != true)
                ++bad;
            if (rules::uac5AirwalkRangeTouch() != true)
                ++bad;
            if (rules::uac5AirwalkSaveNone() != true)
                ++bad;
            if (rules::uac5AirwalkStopOnCopperPiece() != true)
                ++bad;
            if (rules::uac5AirwalkTargetUpToGiantSize() != true)
                ++bad;
            if (rules::uac5AirwalkTrainedHorseExample() != true)
                ++bad;
            if (rules::uac5AirwalkTreadsOnAir() != true)
                ++bad;
            if (rules::uac5AnimateAnimatedPerTwoLevels() != 1)
                ++bad;
            if (rules::uac5AnimateAoeSpecial() != true)
                ++bad;
            if (rules::uac5AnimateBipedalManLike() != true)
                ++bad;
            if (rules::uac5AnimateCastingTimeSegments() != 1)
                ++bad;
            if (rules::uac5AnimateCfAnimateDead() != true)
                ++bad;
            if (rules::uac5AnimateCommandWordsMax() != 12)
                ++bad;
            if (rules::uac5AnimateComponentsVSM() != true)
                ++bad;
            if (rules::uac5AnimateCorpseMonsterZombieMM2() != true)
                ++bad;
            if (rules::uac5AnimateDurationPermanent() != true)
                ++bad;
            if (rules::uac5AnimateExampleTypeCount() != 6)
                ++bad;
            if (rules::uac5AnimateListNotExclusive() != true)
                ++bad;
            if (rules::uac5AnimateLowHDThreshold() != 6)
                ++bad;
            if (rules::uac5AnimateMaterialSymbolSpecimen() != true)
                ++bad;
            if (rules::uac5AnimateNormalAttacksOnly() != true)
                ++bad;
            if (rules::uac5AnimateRangeLost() != true)
                ++bad;
            if (rules::uac5AnimateSaveNone() != true)
                ++bad;
            if (rules::uac5AnimateSkeletonHalfHDRoundedUp() != true)
                ++bad;
            if (rules::uac5AnimateSpecimenRuleFragmentLost() != true)
                ++bad;
            if (rules::uac5FontAoeSpecial() != true)
                ++bad;
            if (rules::uac5FontCapacityRuleFragmentLost() != true)
                ++bad;
            if (rules::uac5FontCastingTimeTurns() != 5)
                ++bad;
            if (rules::uac5FontComponentsDecoded() != true)
                ++bad;
            if (rules::uac5FontComponentsVSM() != true)
                ++bad;
            if (rules::uac5FontDetectionSeeMagicMirror() != true)
                ++bad;
            if (rules::uac5FontDurationSpecial() != true)
                ++bad;
            if (rules::uac5FontDurationTiedToCapacity() != true)
                ++bad;
            if (rules::uac5FontLikeCrystalBall() != true)
                ++bad;
            if (rules::uac5FontMaterialNotExhausted() != true)
                ++bad;
            if (rules::uac5FontRangeTouch() != true)
                ++bad;
            if (rules::uac5FontRequiresGoodStanding() != true)
                ++bad;
            if (rules::uac5FontRoundsPerVial() != 1)
                ++bad;
            if (rules::uac5FontSaveNone() != true)
                ++bad;
            if (rules::uac5FontScryingDevice() != true)
                ++bad;
            if (rules::uac5GolemAoeSpecial() != true)
                ++bad;
            if (rules::uac5GolemCannotSpeak() != true)
                ++bad;
            if (rules::uac5GolemCastingTimeSegments() != 1)
                ++bad;
            if (rules::uac5GolemComponentsVSM() != true)
                ++bad;
            if (rules::uac5GolemDurationSpecial() != true)
                ++bad;
            if (rules::uac5GolemInstructionWordsMax() != 12)
                ++bad;
            if (rules::uac5GolemLeatherHalfFromBlunt() != true)
                ++bad;
            if (rules::uac5GolemLesserGolemsName() != true)
                ++bad;
            if (rules::uac5GolemManShapedManSized() != true)
                ++bad;
            if (rules::uac5GolemMaterialCount() != 4)
                ++bad;
            if (rules::uac5GolemMaxHeightFeet() != 7)
                ++bad;
            if (rules::uac5GolemMinHeightFeet() != 3)
                ++bad;
            if (rules::uac5GolemMindlessSpellExamples() != 4)
                ++bad;
            if (rules::uac5GolemNoMinds() != true)
                ++bad;
            if (rules::uac5GolemRangeInches() != 1)
                ++bad;
            if (rules::uac5GolemRequiresPersonalConstruction() != true)
                ++bad;
            if (rules::uac5GolemRequiresPrayerSpell() != true)
                ++bad;
            if (rules::uac5GolemRopeStranglePerRound() != 6)
                ++bad;
            if (rules::uac5GolemRopeStrangleUntilRelease() != true)
                ++bad;
            if (rules::uac5GolemSaveNone() != true)
                ++bad;
            if (rules::uac5GolemSavesAsCreatorLevel() != true)
                ++bad;
            if (rules::uac5GolemStrawSDDecoded() != true)
                ++bad;
            if (rules::uac5GolemWoodImmuneBluntPiercing() != true)
                ++bad;
            if (rules::uac5MagicFontSeamChecks() != true)
                ++bad;
            if (rules::uac5RainbowAoeSpecial() != true)
                ++bad;
            if (rules::uac5RainbowApplicationCount() != 4)
                ++bad;
            if (rules::uac5RainbowBowArrowAppearsNocked() != true)
                ++bad;
            if (rules::uac5RainbowBowBowClassOnly() != true)
                ++bad;
            if (rules::uac5RainbowBowColorCount() != 7)
                ++bad;
            if (rules::uac5RainbowBowHueLeavesPerShot() != true)
                ++bad;
            if (rules::uac5RainbowBowMaxShotsPerRound() != 2)
                ++bad;
            if (rules::uac5RainbowBowMissilePlus() != 3)
                ++bad;
            if (rules::uac5RainbowBowMissiles() != 7)
                ++bad;
            if (rules::uac5RainbowBowNoNonproficiencyPenalty() != true)
                ++bad;
            if (rules::uac5RainbowBowShimmering() != true)
                ++bad;
            if (rules::uac5RainbowBowSpectrumFallback() != true)
                ++bad;
            if (rules::uac5RainbowBowStrengthMin() != 6)
                ++bad;
            if (rules::uac5RainbowBridgeLastsSpellLength() != true)
                ++bad;
            if (rules::uac5RainbowBridgeLoadHundredsPerLevel() != true)
                ++bad;
            if (rules::uac5RainbowBridgeMaxLengthFeet() != 120)
                ++bad;
            if (rules::uac5RainbowBridgeMinLengthFeet() != 20)
                ++bad;
            if (rules::uac5RainbowBridgeOrderedOutOfExistence() != true)
                ++bad;
            if (rules::uac5RainbowBridgeSevenHued() != true)
                ++bad;
            if (rules::uac5RainbowBridgeTailFragmentLost() != true)
                ++bad;
            if (rules::uac5RainbowBridgeWidthFeetPerLevel() != true)
                ++bad;
            if (rules::uac5RainbowCastingTimeSegments() != 8)
                ++bad;
            if (rules::uac5RainbowComponentsVSM() != true)
                ++bad;
            if (rules::uac5RainbowDiamondMinValueGP() != 1000)
                ++bad;
            if (rules::uac5RainbowDiamondNeedsBlessPrayer() != true)
                ++bad;
            if (rules::uac5RainbowDurationRoundsPerLevel() != 1)
                ++bad;
            if (rules::uac5RainbowElevatorArcPath() != true)
                ++bad;
            if (rules::uac5RainbowElevatorDangerOnExpiry() != true)
                ++bad;
            if (rules::uac5RainbowElevatorRadiusFeet() != 10)
                ++bad;
            if (rules::uac5RainbowElevatorRateInches() != 12)
                ++bad;
            if (rules::uac5RainbowElevatorTrailInches() != 12)
                ++bad;
            if (rules::uac5RainbowFlagonCasterLevel() != 12)
                ++bad;
            if (rules::uac5RainbowFlagonDraughtCount() != 7)
                ++bad;
            if (rules::uac5RainbowFlagonEffectsPersist() != true)
                ++bad;
            if (rules::uac5RainbowFlagonMeasures() != 7)
                ++bad;
            if (rules::uac5RainbowFlagonSevenColored() != true)
                ++bad;
            if (rules::uac5RainbowFlagonUnusedDisappear() != true)
                ++bad;
            if (rules::uac5RainbowMaterialSymbolAndVial() != true)
                ++bad;
            if (rules::uac5RainbowNeedsRainbowSight() != true)
                ++bad;
            if (rules::uac5RainbowOnlySymbolRemains() != true)
                ++bad;
            if (rules::uac5RainbowRangeLost() != true)
                ++bad;
            if (rules::uac5RainbowSaveNone() != true)
                ++bad;
            if (rules::uac5RainbowSpecialComponentFallback() != true)
                ++bad;
            if (rules::uac5SpellsPinFromProse() != true)
                ++bad;
            if (rules::uac5SpikeStonesAoeSquareInchesPerLevel() != 1)
                ++bad;
            if (rules::uac5SpikeStonesAttackAsCaster() != true)
                ++bad;
            if (rules::uac5SpikeStonesAttackOnEntryAndSteps() != true)
                ++bad;
            if (rules::uac5SpikeStonesCastingTimeSegments() != 6)
                ++bad;
            if (rules::uac5SpikeStonesChargeAttacksPerInch() != 2)
                ++bad;
            if (rules::uac5SpikeStonesComponentsVSM() != true)
                ++bad;
            if (rules::uac5SpikeStonesDamageInAdditionToFalling() != true)
                ++bad;
            if (rules::uac5SpikeStonesDamageMax() != 4)
                ++bad;
            if (rules::uac5SpikeStonesDamageMin() != 1)
                ++bad;
            if (rules::uac5SpikeStonesDurationTurnsMax() != 12)
                ++bad;
            if (rules::uac5SpikeStonesDurationTurnsMin() != 3)
                ++bad;
            if (rules::uac5SpikeStonesDurationTurnsPerLevel() != 1)
                ++bad;
            if (rules::uac5SpikeStonesImpedesOrDamages() != true)
                ++bad;
            if (rules::uac5SpikeStonesInitialStepAlertsOnlyOnHit() != true)
                ++bad;
            if (rules::uac5SpikeStonesMaterialStalactites() != true)
                ++bad;
            if (rules::uac5SpikeStonesNaturalAndWorked() != true)
                ++bad;
            if (rules::uac5SpikeStonesNoticeChancePct() != 25)
                ++bad;
            if (rules::uac5SpikeStonesOthersExtraChecks() != 1)
                ++bad;
            if (rules::uac5SpikeStonesPitChecks() != 6)
                ++bad;
            if (rules::uac5SpikeStonesPitDamageBonusPer10ft() != 2)
                ++bad;
            if (rules::uac5SpikeStonesPitToHitBonusPer10ft() != 2)
                ++bad;
            if (rules::uac5SpikeStonesRangeInches() != 3)
                ++bad;
            if (rules::uac5SpikeStonesSaveNone() != true)
                ++bad;
            if (rules::uac5SpikeStonesSpikesPerSquareFoot() != 1)
                ++bad;
            if (rules::uac5SpikeStonesStalactiteCount() != 4)
                ++bad;
            if (rules::uac7ExactionActsAsQuest() != true)
                ++bad;
            if (rules::uac7ExactionAoeOneCreature() != true)
                ++bad;
            if (rules::uac7ExactionCastingTimeRounds() != 1)
                ++bad;
            if (rules::uac7ExactionCompletionFragmentLost() != true)
                ++bad;
            if (rules::uac7ExactionComponentsVSM() != true)
                ++bad;
            if (rules::uac7ExactionConfrontsExtraplanar() != true)
                ++bad;
            if (rules::uac7ExactionCreatureFreedOnReward() != true)
                ++bad;
            if (rules::uac7ExactionDurationSpecial() != true)
                ++bad;
            if (rules::uac7ExactionExampleFragmentLost() != true)
                ++bad;
            if (rules::uac7ExactionExamplesIncludeDevasDemons() != true)
                ++bad;
            if (rules::uac7ExactionFailureGrantsSpellImmunity() != true)
                ++bad;
            if (rules::uac7ExactionFailureInvitesCounterExaction() != true)
                ++bad;
            if (rules::uac7ExactionLevel() != 7)
                ++bad;
            if (rules::uac7ExactionMaterialSymbolPlaneMatterScroll() != true)
                ++bad;
            if (rules::uac7ExactionMustKnowOrFairTrade() != true)
                ++bad;
            if (rules::uac7ExactionNoEthicalMoralOpposition() != true)
                ++bad;
            if (rules::uac7ExactionNotOnDeities() != true)
                ++bad;
            if (rules::uac7ExactionOpenerFragmentLost() != true)
                ++bad;
            if (rules::uac7ExactionPastFavorAsCause() != true)
                ++bad;
            if (rules::uac7ExactionPledgeIfNoReason() != true)
                ++bad;
            if (rules::uac7ExactionRangeInches() != 1)
                ++bad;
            if (rules::uac7ExactionRequiresDutyOrQuest() != true)
                ++bad;
            if (rules::uac7ExactionRewardReturnRequired() != true)
                ++bad;
            if (rules::uac7ExactionSaveSpecial() != true)
                ++bad;
            if (rules::uac7ExactionSeamFragmentsOnly() != true)
                ++bad;
            if (rules::uac7ExactionServiceMustBeReasonable() != true)
                ++bad;
            if (rules::uac7ExactionTransportedOnCompletion() != true)
                ++bad;
            if (rules::uac7ExactionTrueNeutralOpposed() != true)
                ++bad;
            if (rules::uac7ExactionWhenCastOpenerDecoded() != true)
                ++bad;
            if (rules::uac7SpellsPinFromProse() != true)
                ++bad;
            if (rules::uac7SuccorAoeOneIndividual() != true)
                ++bad;
            if (rules::uac7SuccorBreakItemWithCommandWord() != true)
                ++bad;
            if (rules::uac7SuccorCastingTimeDays() != 1)
                ++bad;
            if (rules::uac7SuccorClericMayDeclineSummons() != true)
                ++bad;
            if (rules::uac7SuccorComponentsVSM() != true)
                ++bad;
            if (rules::uac7SuccorDeclineWastesSpell() != true)
                ++bad;
            if (rules::uac7SuccorDurationSpecial() != true)
                ++bad;
            if (rules::uac7SuccorDweomerInPreparedObject() != true)
                ++bad;
            if (rules::uac7SuccorEitherVersionCosts() != true)
                ++bad;
            if (rules::uac7SuccorGivenWillinglyWithCommandWord() != true)
                ++bad;
            if (rules::uac7SuccorLevel() != 7)
                ++bad;
            if (rules::uac7SuccorNoOtherCreatures() != true)
                ++bad;
            if (rules::uac7SuccorObjectExampleCount() != 3)
                ++bad;
            if (rules::uac7SuccorPreparationCostMaxGP() != 5000)
                ++bad;
            if (rules::uac7SuccorPreparationCostMinGP() != 2000)
                ++bad;
            if (rules::uac7SuccorRadiatesMagic() != true)
                ++bad;
            if (rules::uac7SuccorRangeTouch() != true)
                ++bad;
            if (rules::uac7SuccorReverseSummons() != true)
                ++bad;
            if (rules::uac7SuccorReverseVicinityFragmentLost() != true)
                ++bad;
            if (rules::uac7SuccorReversible() != true)
                ++bad;
            if (rules::uac7SuccorSaveNone() != true)
                ++bad;
            if (rules::uac7SuccorTransportsPossessorToSanctuary() != true)
                ++bad;
            if (rules::uac7SuccorWordOfRecallEquivalent() != true)
                ++bad;
            if (rules::uad1ArchdruidNeedsGreatDruidPermission() != true)
                ++bad;
            if (rules::uad1CastOutAuraAffectsNaturalCreatures() != true)
                ++bad;
            if (rules::uad1CastOutAuraIncludesDomesticAndDruids() != true)
                ++bad;
            if (rules::uad1CastOutDeniedOrOffsetPunishable() != true)
                ++bad;
            if (rules::uad1CastOutExcommunicationForSacrilege() != true)
                ++bad;
            if (rules::uad1CastOutLessenedByReversedVersion() != true)
                ++bad;
            if (rules::uad1CastOutNeedsArchdruidPermission() != true)
                ++bad;
            if (rules::uad1CastOutOnlyHierophantNeutralizes() != true)
                ++bad;
            if (rules::uad1CastOutReactAdverbLost() != true)
                ++bad;
            if (rules::uad1CastOutReverserAtLeastEqualLevel() != true)
                ++bad;
            if (rules::uad1CastOutUnwillingSaveMod() != -4)
                ++bad;
            if (rules::uad1CeremonyAoeOneCreatureItemOrArea() != true)
                ++bad;
            if (rules::uad1CeremonyAtDawnOrDusk() != true)
                ++bad;
            if (rules::uad1CeremonyCastingTimeCellLost() != true)
                ++bad;
            if (rules::uad1CeremonyComponentsCellLost() != true)
                ++bad;
            if (rules::uad1CeremonyComponentsIncludeMistletoe() != true)
                ++bad;
            if (rules::uad1CeremonyDurationPermanent() != true)
                ++bad;
            if (rules::uad1CeremonyIndicatedOrLowerLevel() != true)
                ++bad;
            if (rules::uad1CeremonyKnowAlignmentRevealsNeutrality() != true)
                ++bad;
            if (rules::uad1CeremonyLevel() != 1)
                ++bad;
            if (rules::uad1CeremonyNoAuraOfMagic() != true)
                ++bad;
            if (rules::uad1CeremonyRangeTouch() != true)
                ++bad;
            if (rules::uad1CeremonyRiteInGroveOrHealthyForest() != true)
                ++bad;
            if (rules::uad1CeremonySaveSpecial() != true)
                ++bad;
            if (rules::uad1CeremonySimilarToClerical() != true)
                ++bad;
            if (rules::uad1CeremonyVarietyCount() != 9)
                ++bad;
            if (rules::uad1ComingOfAgeSaveBonus() != 1)
                ++bad;
            if (rules::uad1ComingOfAgeUsualAge() != 14)
                ++bad;
            if (rules::uad1DedicationChargesBalanceKeeping() != true)
                ++bad;
            if (rules::uad1DedicationRequiresTrueNeutral() != true)
                ++bad;
            if (rules::uad1DetectBalanceAoeOnePerRound() != true)
                ++bad;
            if (rules::uad1DetectBalanceCastingTimeSegments() != 1)
                ++bad;
            if (rules::uad1DetectBalanceComponentsVSM() != true)
                ++bad;
            if (rules::uad1DetectBalanceDetectsNonNeutralForces() != true)
                ++bad;
            if (rules::uad1DetectBalanceDurationRoundsPerLevel() != 1)
                ++bad;
            if (rules::uad1DetectBalanceLevel() != 1)
                ++bad;
            if (rules::uad1DetectBalanceNoAuraOnPlainItems() != true)
                ++bad;
            if (rules::uad1DetectBalanceNoNeutralPartStrongAura() != true)
                ++bad;
            if (rules::uad1DetectBalanceNotExactAlignment() != true)
                ++bad;
            if (rules::uad1DetectBalancePartlyNeutralMildAura() != true)
                ++bad;
            if (rules::uad1DetectBalanceRangeLost() != true)
                ++bad;
            if (rules::uad1DetectBalanceSameStrengthForSameNeutrality() != true)
                ++bad;
            if (rules::uad1DetectBalanceSaveNone() != true)
                ++bad;
            if (rules::uad1DetectBalanceTrueNeutralSmoothAura() != true)
                ++bad;
            if (rules::uad1DetectBalanceUnknowableAlignmentBlocks() != true)
                ++bad;
            if (rules::uad1DetectBalanceWorksOnAlignedMagicItem() != true)
                ++bad;
            if (rules::uad1DetectPoisonAoeSpecial() != true)
                ++bad;
            if (rules::uad1DetectPoisonCastingTimeRounds() != 1)
                ++bad;
            if (rules::uad1DetectPoisonComponentsVSM() != true)
                ++bad;
            if (rules::uad1DetectPoisonDurationRoundsPerLevel() != 1)
                ++bad;
            if (rules::uad1DetectPoisonLevel() != 1)
                ++bad;
            if (rules::uad1DetectPoisonMaterialMistletoe() != true)
                ++bad;
            if (rules::uad1DetectPoisonMaterialYewLeaf() != true)
                ++bad;
            if (rules::uad1DetectPoisonOneFailureEndsTypeDetection() != true)
                ++bad;
            if (rules::uad1DetectPoisonOpenerScrambleDecoded() != true)
                ++bad;
            if (rules::uad1DetectPoisonPortionNotWholePond() != true)
                ++bad;
            if (rules::uad1DetectPoisonRangeZero() != true)
                ++bad;
            if (rules::uad1DetectPoisonSaveNone() != true)
                ++bad;
            if (rules::uad1DetectPoisonScanVolumeCubicYards() != 1)
                ++bad;
            if (rules::uad1DetectPoisonSeveralLeavesNeeded() != true)
                ++bad;
            if (rules::uad1DetectPoisonTypeChancePctPerLevel() != 5)
                ++bad;
            if (rules::uad1DetectPoisonTypeCount() != 3)
                ++bad;
            if (rules::uad1DetectPoisonYewLeafTurnsBrown() != true)
                ++bad;
            if (rules::uad1GrandDruidNeedsNoPermission() != true)
                ++bad;
            if (rules::uad1GrandDruidReversibleByHierophant() != true)
                ++bad;
            if (rules::uad1GreatDruidNeedsGrandDruidPermission() != true)
                ++bad;
            if (rules::uad1HallowedGroundLastsWhilePermanentBase() != true)
                ++bad;
            if (rules::uad1HallowedGroundOwnGrove() != true)
                ++bad;
            if (rules::uad1HallowedGroundTreesNeverDiseased() != true)
                ++bad;
            if (rules::uad1InitiationGrantsShapechangeAndWoodlandImmunity() != true)
                ++bad;
            if (rules::uad1InitiationMustFollowSeventhLevelStart() != true)
                ++bad;
            if (rules::uad1InitiationSelfCastUnusual() != true)
                ++bad;
            if (rules::uad1InitiationUsuallyBySeventhPlusDruid() != true)
                ++bad;
            if (rules::uad1InvestitureBeforeAspirant() != true)
                ++bad;
            if (rules::uad1InvestitureNoOtherBenefit() != true)
                ++bad;
            if (rules::uad1MarriageIdenticalToClerical() != true)
                ++bad;
            if (rules::uad1PrecipAddsMistletoeToClerical() != true)
                ++bad;
            if (rules::uad1PrecipCastingTimeSegments() != 3)
                ++bad;
            if (rules::uad1PrecipComponentsVSM() != true)
                ++bad;
            if (rules::uad1PrecipCylinderDiameterInches() != 3)
                ++bad;
            if (rules::uad1PrecipCylinderHeightInches() != 12)
                ++bad;
            if (rules::uad1PrecipDurationSegmentsPerLevel() != 1)
                ++bad;
            if (rules::uad1PrecipIdenticalToClerical() != true)
                ++bad;
            if (rules::uad1PrecipLevel() != 1)
                ++bad;
            if (rules::uad1PrecipNameHeaderLost() != true)
                ++bad;
            if (rules::uad1PrecipRangeLost() != true)
                ++bad;
            if (rules::uad1PrecipSaveNoneAndSpecial() != true)
                ++bad;
            if (rules::uad1PrecipSchoolLost() != true)
                ++bad;
            if (rules::uad1RestEternalBlocksRaiseDeadAndResurrection() != true)
                ++bad;
            if (rules::uad1RestEternalWishWorks() != true)
                ++bad;
            if (rules::uad1SpecialVowsNotOnPaladins() != true)
                ++bad;
            if (rules::uad1SpecialVowsWorksOnCavaliersAnyAlignment() != true)
                ++bad;
            if (rules::uad2FlameBladeBladeLengthFeet() != 3)
                ++bad;
            if (rules::uad2FlameBladeBladeUnitLost() != true)
                ++bad;
            if (rules::uad2FlameBladeCastingTimeSegments() != 3)
                ++bad;
            if (rules::uad2FlameBladeComponentsVSM() != true)
                ++bad;
            if (rules::uad2FlameBladeDamageMax() != 8)
                ++bad;
            if (rules::uad2FlameBladeDamageMin() != 5)
                ++bad;
            if (rules::uad2FlameBladeDurationRoundsPerLevel() != 1)
                ++bad;
            if (rules::uad2FlameBladeFireDwellerPenalty() != -2)
                ++bad;
            if (rules::uad2FlameBladeIgnitesDryMaterials() != true)
                ++bad;
            if (rules::uad2FlameBladeLevel() != 2)
                ++bad;
            if (rules::uad2FlameBladeMagicOnlyCreaturesImmuneUnlessUndead() != true)
                ++bad;
            if (rules::uad2FlameBladeMaterialInterleaveDecoded() != true)
                ++bad;
            if (rules::uad2FlameBladeMaterialMistletoe() != true)
                ++bad;
            if (rules::uad2FlameBladeMaterialSumacLeaf() != true)
                ++bad;
            if (rules::uad2FlameBladeNoDamageOnFireProtected() != true)
                ++bad;
            if (rules::uad2FlameBladeNotMagicalExceptVsUndead() != true)
                ++bad;
            if (rules::uad2FlameBladeRangeInches() != 0)
                ++bad;
            if (rules::uad2FlameBladeSaveNone() != true)
                ++bad;
            if (rules::uad2FlameBladeUndeadOrFireVulnerableBonus() != 2)
                ++bad;
            if (rules::uad2FlameBladeWieldedAsScimitar() != true)
                ++bad;
            if (rules::uad2GoodberryBadberryNoSave() != true)
                ++bad;
            if (rules::uad2GoodberryBadberryPoisonPoints() != 1)
                ++bad;
            if (rules::uad2GoodberryBerriesMax() != 8)
                ++bad;
            if (rules::uad2GoodberryBerriesMin() != 2)
                ++bad;
            if (rules::uad2GoodberryCastingTimeRounds() != 1)
                ++bad;
            if (rules::uad2GoodberryComponentsVSM() != true)
                ++bad;
            if (rules::uad2GoodberryCureMaxPer24h() != 8)
                ++bad;
            if (rules::uad2GoodberryCurePerBerry() != 1)
                ++bad;
            if (rules::uad2GoodberryDetectMagicReveals() != true)
                ++bad;
            if (rules::uad2GoodberryDiscernedByDruid3rdPlus() != true)
                ++bad;
            if (rules::uad2GoodberryDurationDaysBase() != 1)
                ++bad;
            if (rules::uad2GoodberryDurationPerLevelAddend() != 1)
                ++bad;
            if (rules::uad2GoodberryDurationUnitLost() != true)
                ++bad;
            if (rules::uad2GoodberryExampleListFirstItemLost() != true)
                ++bad;
            if (rules::uad2GoodberryLevel() != 2)
                ++bad;
            if (rules::uad2GoodberryMaterialMistletoe() != true)
                ++bad;
            if (rules::uad2GoodberryNameHeaderLost() != true)
                ++bad;
            if (rules::uad2GoodberryNourishAsFullMeal() != true)
                ++bad;
            if (rules::uad2GoodberryRangeTouch() != true)
                ++bad;
            if (rules::uad2GoodberryReverseBadberry() != true)
                ++bad;
            if (rules::uad2GoodberrySaveNone() != true)
                ++bad;
            if (rules::uad2GoodberrySchoolLost() != true)
                ++bad;
            if (rules::uad2ReflectingPoolAoeSpecial() != true)
                ++bad;
            if (rules::uad2ReflectingPoolCastThroughChancePctPerLevel() != 5)
                ++bad;
            if (rules::uad2ReflectingPoolCastThroughCount() != 3)
                ++bad;
            if (rules::uad2ReflectingPoolCastingTimeHours() != 2)
                ++bad;
            if (rules::uad2ReflectingPoolCoexistentPlanesOnly() != true)
                ++bad;
            if (rules::uad2ReflectingPoolCompanionSpellNameLost() != true)
                ++bad;
            if (rules::uad2ReflectingPoolComponentsVSM() != true)
                ++bad;
            if (rules::uad2ReflectingPoolCrystalBallLike() != true)
                ++bad;
            if (rules::uad2ReflectingPoolCrystalBallPenaltiesApply() != true)
                ++bad;
            if (rules::uad2ReflectingPoolDiameterFeetPerLevel() != 2)
                ++bad;
            if (rules::uad2ReflectingPoolDurationRoundsPerLevel() != 1)
                ++bad;
            if (rules::uad2ReflectingPoolIncludesParaElementalAndShadow() != true)
                ++bad;
            if (rules::uad2ReflectingPoolInfraAndUltravisionNormal() != true)
                ++bad;
            if (rules::uad2ReflectingPoolLevel() != 2)
                ++bad;
            if (rules::uad2ReflectingPoolMagicMirrorAndFontRef() != true)
                ++bad;
            if (rules::uad2ReflectingPoolMaterialMeasureLost() != true)
                ++bad;
            if (rules::uad2ReflectingPoolMaterialMistletoe() != true)
                ++bad;
            if (rules::uad2ReflectingPoolMaterialNutOil() != true)
                ++bad;
            if (rules::uad2ReflectingPoolNameHeaderGarbled() != true)
                ++bad;
            if (rules::uad2ReflectingPoolNaturalWaterOnly() != true)
                ++bad;
            if (rules::uad2ReflectingPoolRangeInches() != 1)
                ++bad;
            if (rules::uad2ReflectingPoolSaveNone() != true)
                ++bad;
            if (rules::uad2ReflectingPoolSchoolLost() != true)
                ++bad;
            if (rules::uad2ReflectingPoolStarshineOperates() != true)
                ++bad;
            if (rules::uad2SlowPoisonAntidoteChancePctPerLevel() != 5)
                ++bad;
            if (rules::uad2SlowPoisonAntidoteOutdoorOrHerbalist() != true)
                ++bad;
            if (rules::uad2SlowPoisonAoeCreatureTouched() != true)
                ++bad;
            if (rules::uad2SlowPoisonCastingTimeSegments() != 1)
                ++bad;
            if (rules::uad2SlowPoisonComponentsVSM() != true)
                ++bad;
            if (rules::uad2SlowPoisonDetectPoisonIndicatesOrganic() != true)
                ++bad;
            if (rules::uad2SlowPoisonDurationHoursPerLevel() != 1)
                ++bad;
            if (rules::uad2SlowPoisonIdenticalToClerical() != true)
                ++bad;
            if (rules::uad2SlowPoisonLevel() != 2)
                ++bad;
            if (rules::uad2SlowPoisonMaterialGarlicOnFeet() != true)
                ++bad;
            if (rules::uad2SlowPoisonMaterialMistletoe() != true)
                ++bad;
            if (rules::uad2SlowPoisonPlantPoisonCondition() != true)
                ++bad;
            if (rules::uad2SlowPoisonRangeCellHeadLost() != true)
                ++bad;
            if (rules::uad2SlowPoisonRangeTouch() != true)
                ++bad;
            if (rules::uad2SlowPoisonRollEqualOrLessNeutralizes() != true)
                ++bad;
            if (rules::uad2SlowPoisonSaveNone() != true)
                ++bad;
            if (rules::uail1OrbAmberBlindRoundsMax() != 8)
                ++bad;
            if (rules::uail1OrbAmberBlindRoundsMin() != 5)
                ++bad;
            if (rules::uail1OrbAmethystSlowRoundsMax() != 8)
                ++bad;
            if (rules::uail1OrbAmethystSlowRoundsMin() != 2)
                ++bad;
            if (rules::uail1OrbAmethystStoneOnFailedSave() != true)
                ++bad;
            if (rules::uail1OrbAoeOneCreature() != true)
                ++bad;
            if (rules::uail1OrbAshenDeathOnFailedSave() != true)
                ++bad;
            if (rules::uail1OrbAshenParalysisRoundsMax() != 5)
                ++bad;
            if (rules::uail1OrbAshenParalysisRoundsMin() != 2)
                ++bad;
            if (rules::uail1OrbCastingGarbleDecoded() != true)
                ++bad;
            if (rules::uail1OrbCastingTimeSegments() != 1)
                ++bad;
            if (rules::uail1OrbClearCrystalSubstitute() != true)
                ++bad;
            if (rules::uail1OrbColorDeterminesEffect() != true)
                ++bad;
            if (rules::uail1OrbColorRestrictedByLevel() != true)
                ++bad;
            if (rules::uail1OrbComponentsVSM() != true)
                ++bad;
            if (rules::uail1OrbDurationSpecial() != true)
                ++bad;
            if (rules::uail1OrbEmeraldCloudRadiusFeet() != 5)
                ++bad;
            if (rules::uail1OrbFlameCombustiblesRadiusInches() != 1)
                ++bad;
            if (rules::uail1OrbFlameExtraDamage() != 2)
                ++bad;
            if (rules::uail1OrbGemGpMin() != 50)
                ++bad;
            if (rules::uail1OrbHitAdjAtMaxRange() != 1)
                ++bad;
            if (rules::uail1OrbHitAdjAtOneInch() != 3)
                ++bad;
            if (rules::uail1OrbHitAdjAtTwoInches() != 2)
                ++bad;
            if (rules::uail1OrbLevel() != 1)
                ++bad;
            if (rules::uail1OrbLowerHuesAlwaysAvailable() != true)
                ++bad;
            if (rules::uail1OrbMagicResistanceWithstands() != true)
                ++bad;
            if (rules::uail1OrbMagicalVsHighPlus() != true)
                ++bad;
            if (rules::uail1OrbMaxHurlInches() != 3)
                ++bad;
            if (rules::uail1OrbNameHeaderGarbled() != true)
                ++bad;
            if (rules::uail1OrbNoBarriers() != true)
                ++bad;
            if (rules::uail1OrbPearlyBlindsOnFailedSave() != true)
                ++bad;
            if (rules::uail1OrbPearlyLightRoundsPerLevel() != 1)
                ++bad;
            if (rules::uail1OrbRangeZero() != true)
                ++bad;
            if (rules::uail1OrbRowCount() != 9)
                ++bad;
            if (rules::uail1OrbRubyMeltsIceCuYd() != 1)
                ++bad;
            if (rules::uail1OrbRubyStatLossPerStat() != 1)
                ++bad;
            if (rules::uail1OrbRubyStatLossRounds() != 1)
                ++bad;
            if (rules::uail1OrbSapphireParalysisRoundsMax() != 20)
                ++bad;
            if (rules::uail1OrbSapphireParalysisRoundsMin() != 5)
                ++bad;
            if (rules::uail1OrbSaveSpecial() != true)
                ++bad;
            if (rules::uail1OrbSchoolTailLost() != true)
                ++bad;
            if (rules::uail1OrbToHitSentenceInterleaved() != true)
                ++bad;
            if (rules::uail1OrbTurquoiseMagnetizeRoundsMax() != 12)
                ++bad;
            if (rules::uail1OrbTurquoiseMagnetizeRoundsMin() != 3)
                ++bad;
            if (rules::uail1PhantomAbsorbPerLevel() != 1)
                ++bad;
            if (rules::uail1PhantomAc() != 3)
                ++bad;
            if (rules::uail1PhantomAoeOnePerson() != true)
                ++bad;
            if (rules::uail1PhantomArmorType() != 3)
                ++bad;
            if (rules::uail1PhantomCastingGarbleDecoded() != true)
                ++bad;
            if (rules::uail1PhantomCastingTimeRounds() != 1)
                ++bad;
            if (rules::uail1PhantomComponentsVSM() != true)
                ++bad;
            if (rules::uail1PhantomDisappearsOnCast() != true)
                ++bad;
            if (rules::uail1PhantomDisbeliefBreaks() != true)
                ++bad;
            if (rules::uail1PhantomDispelBreaks() != true)
                ++bad;
            if (rules::uail1PhantomDurationSpecial() != true)
                ++bad;
            if (rules::uail1PhantomLevel() != 1)
                ++bad;
            if (rules::uail1PhantomLevelDivergenceFlagged() != true)
                ++bad;
            if (rules::uail1PhantomMithralGp() != 10)
                ++bad;
            if (rules::uail1PhantomNoMovementOrCastingHindrance() != true)
                ++bad;
            if (rules::uail1PhantomNoOtherProtection() != true)
                ++bad;
            if (rules::uail1PhantomQuasiRealPlateMail() != true)
                ++bad;
            if (rules::uail1PhantomRangeTouch() != true)
                ++bad;
            if (rules::uail1PhantomRemainderAccrues() != true)
                ++bad;
            if (rules::uail1PhantomRustMonsterImmune() != true)
                ++bad;
            if (rules::uail1PhantomSaveBonusCellLost() != true)
                ++bad;
            if (rules::uail1PhantomSaveNone() != true)
                ++bad;
            if (rules::uail1PhantomVanishesAtLevelsAbsorbed() != true)
                ++bad;
            if (rules::uail1PhantomWandOfNegationBreaks() != true)
                ++bad;
            if (rules::uailcDimAffectsLightSpells() != true)
                ++bad;
            if (rules::uailcDimAoeSpecial() != true)
                ++bad;
            if (rules::uailcDimCandles() != 72)
                ++bad;
            if (rules::uailcDimDurationRounds() != 1)
                ++bad;
            if (rules::uailcDimFireBecomesTorchlike() != true)
                ++bad;
            if (rules::uailcDimHalfRadiance() != true)
                ++bad;
            if (rules::uailcDimLightSpellsDimToHalf() != true)
                ++bad;
            if (rules::uailcDimPhraseAndDownwardMotion() != true)
                ++bad;
            if (rules::uailcDimRangeInches() != 1)
                ++bad;
            if (rules::uailcDimTorchAsCandle() != true)
                ++bad;
            if (rules::uailcDimTorches() != 6)
                ++bad;
            if (rules::uailcDimWeakensLightOrAir() != true)
                ++bad;
            if (rules::uailcHazeAoeCubeInches() != 1)
                ++bad;
            if (rules::uailcHazeDurationRounds() != 1)
                ++bad;
            if (rules::uailcHazeGustOfWindDisperses() != true)
                ++bad;
            if (rules::uailcHazeHarderToHitPct() != 5)
                ++bad;
            if (rules::uailcHazeHideInShadowsBonusPct() != 5)
                ++bad;
            if (rules::uailcHazeHumAndHandPasses() != true)
                ++bad;
            if (rules::uailcHazeMissileToHitAdj() != -1)
                ++bad;
            if (rules::uailcHazeRangeInches() != 1)
                ++bad;
            if (rules::uailcHazeSaveBonus() != 1)
                ++bad;
            if (rules::uailcHazeSaveWhenOtherwiseNonePct() != 5)
                ++bad;
            if (rules::uailcHazeSmokeOrDust() != true)
                ++bad;
            if (rules::uailcHazeWeatherDestroys() != true)
                ++bad;
            if (rules::uailcLightsAnyPastelColor() != true)
                ++bad;
            if (rules::uailcLightsAoeSpecial() != true)
                ++bad;
            if (rules::uailcLightsCfBluelight() != true)
                ++bad;
            if (rules::uailcLightsConcentrationMaintained() != true)
                ++bad;
            if (rules::uailcLightsDetectedBeyondInches() != 3)
                ++bad;
            if (rules::uailcLightsDirectsWithFingers() != true)
                ++bad;
            if (rules::uailcLightsFootGlobeRadiusFeet() != 5)
                ++bad;
            if (rules::uailcLightsFourGlobesInches() != 3)
                ++bad;
            if (rules::uailcLightsMagicWord() != true)
                ++bad;
            if (rules::uailcLightsMovedAsDesired() != true)
                ++bad;
            if (rules::uailcLightsPairGlobesInches() != 6)
                ++bad;
            if (rules::uailcLightsPaleBluePinkSparesVision() != true)
                ++bad;
            if (rules::uailcLightsRadiusInDiameters() != 5)
                ++bad;
            if (rules::uailcLightsRangeInches() != 1)
                ++bad;
            if (rules::uailcLightsReflectionBeyondInches() != 1)
                ++bad;
            if (rules::uailcLightsSingleGlobeFeet() != 1)
                ++bad;
            if (rules::uailcLightsSpeakColorAndNumber() != true)
                ++bad;
            if (rules::uailcLightsThreeGlobesInches() != 4)
                ++bad;
            if (rules::uailcLightsThreeInchGlobeRadiusInches() != 15)
                ++bad;
            if (rules::uailcMaskAlterOwnOrSubjectVisage() != true)
                ++bad;
            if (rules::uailcMaskAoeOnePerson() != true)
                ++bad;
            if (rules::uailcMaskDetectedOnlyCloseUp() != true)
                ++bad;
            if (rules::uailcMaskDurationRoundsMax() != 6)
                ++bad;
            if (rules::uailcMaskDurationRoundsMin() != 3)
                ++bad;
            if (rules::uailcMaskFeaturesAffected() != true)
                ++bad;
            if (rules::uailcMaskSubjectHumanDemiHumanHumanoid() != true)
                ++bad;
            if (rules::uailcMaskTouchThinkSpeak() != true)
                ++bad;
            if (rules::uailcMirageActualBeheldPlace() != true)
                ++bad;
            if (rules::uailcMirageAoeSquareInches() != 2)
                ++bad;
            if (rules::uailcMirageAreaAppearsOther() != true)
                ++bad;
            if (rules::uailcMirageConcentrationMaintained() != true)
                ++bad;
            if (rules::uailcMirageDispelIllusionOrMagic() != true)
                ++bad;
            if (rules::uailcMirageFlatFeatureless() != true)
                ++bad;
            if (rules::uailcMirageKeptByConcentrationAlone() != true)
                ++bad;
            if (rules::uailcMirageSaveApplicable() != true)
                ++bad;
            if (rules::uailcMirageSchoolIsIllusion() != true)
                ++bad;
            if (rules::uailcMirageTouchDispel() != true)
                ++bad;
            if (rules::uailcMirageWaverCumulativePct() != 5)
                ++bad;
            if (rules::uailcMirageWordOrTwoThenSinglePass() != true)
                ++bad;
            if (rules::uailcNoiseEachCreatureSaves() != true)
                ++bad;
            if (rules::uailcNoiseIndistinctConfusing() != true)
                ++bad;
            if (rules::uailcNoiseMurmurRushShuffleExamples() != true)
                ++bad;
            if (rules::uailcNoisePointAndImitate() != true)
                ++bad;
            if (rules::uailcNoiseRadiusInches() != 1)
                ++bad;
            if (rules::uailcNoiseRangeInches() != 1)
                ++bad;
            if (rules::uailcNoiseSaveNegatesPerIndividual() != true)
                ++bad;
            if (rules::uailcRainbowAoeSpecial() != true)
                ++bad;
            if (rules::uailcRainbowDurationRounds() != 1)
                ++bad;
            if (rules::uailcRainbowEndWithinInches() != 1)
                ++bad;
            if (rules::uailcRainbowGazeMovingMax() != 5)
                ++bad;
            if (rules::uailcRainbowGazeMovingMin() != 2)
                ++bad;
            if (rules::uailcRainbowGazeSegmentsMax() != 4)
                ++bad;
            if (rules::uailcRainbowGazeSegmentsMin() != 1)
                ++bad;
            if (rules::uailcRainbowGlowsInDarkness() != true)
                ++bad;
            if (rules::uailcRainbowLengthFeet() != 30)
                ++bad;
            if (rules::uailcRainbowMotionStayWithinInches() != 1)
                ++bad;
            if (rules::uailcRainbowNameOfPowerPyramid() != true)
                ++bad;
            if (rules::uailcRainbowNoMotionMayLeave() != true)
                ++bad;
            if (rules::uailcRainbowWidthFeet() != 1)
                ++bad;
            if (rules::uailcTwodAoeSquareInches() != 4)
                ++bad;
            if (rules::uailcTwodConcentrationMaintained() != true)
                ++bad;
            if (rules::uailcTwodDispelByTouchOrMagic() != true)
                ++bad;
            if (rules::uailcTwodInvisibleFromSideOrRear() != true)
                ++bad;
            if (rules::uailcTwodPhraseAndCircularMotion() != true)
                ++bad;
            if (rules::uailcTwodSameAsPhantasmalForce() != true)
                ++bad;
            if (rules::uailcTwodSchoolIsIllusion() != true)
                ++bad;
            if (rules::uailcTwodTellAngleDegrees() != 45)
                ++bad;
            if (rules::uapcConLossPctDeviceCharge() != 100)
                ++bad;
            if (rules::uapcConLossPctNonLiving() != 5)
                ++bad;
            if (rules::uapcDeviceExampleRingOfSpellStoring() != true)
                ++bad;
            if (rules::uapcObjectListInterleavedWithNote() != true)
                ++bad;
            if (rules::uapcPermObjectAlarm() != true)
                ++bad;
            if (rules::uapcPermObjectCount() != 22)
                ++bad;
            if (rules::uapcPermObjectDeeppockets() != true)
                ++bad;
            if (rules::uapcPermObjectDispelMagic() != true)
                ++bad;
            if (rules::uapcPermObjectEnlarge() != true)
                ++bad;
            if (rules::uapcPermObjectFear() != true)
                ++bad;
            if (rules::uapcPermObjectForcecage() != true)
                ++bad;
            if (rules::uapcPermObjectGustOfWind() != true)
                ++bad;
            if (rules::uapcPermObjectInvisibility() != true)
                ++bad;
            if (rules::uapcPermObjectMagicMouth() != true)
                ++bad;
            if (rules::uapcPermObjectMissiles() != true)
                ++bad;
            if (rules::uapcPermObjectPreserve() != true)
                ++bad;
            if (rules::uapcPermObjectPrismaticSphere() != true)
                ++bad;
            if (rules::uapcPermObjectReadMagic() != true)
                ++bad;
            if (rules::uapcPermObjectRun() != true)
                ++bad;
            if (rules::uapcPermObjectStinkingCloud() != true)
                ++bad;
            if (rules::uapcPermObjectTongues() != true)
                ++bad;
            if (rules::uapcPermObjectUltravision() != true)
                ++bad;
            if (rules::uapcPermObjectUnseenServant() != true)
                ++bad;
            if (rules::uapcPermObjectWallOfFire() != true)
                ++bad;
            if (rules::uapcPermObjectWallOfForce() != true)
                ++bad;
            if (rules::uapcPermObjectWeb() != true)
                ++bad;
            if (rules::uapcPermObjectWindWall() != true)
                ++bad;
            if (rules::uapcPermPersonalCount() != 6)
                ++bad;
            if (rules::uapcPermPersonalDetectEvil() != true)
                ++bad;
            if (rules::uapcPermPersonalDetectIllusion() != true)
                ++bad;
            if (rules::uapcPermPersonalDetectInvisibility() != true)
                ++bad;
            if (rules::uapcPermPersonalDetectMagic() != true)
                ++bad;
            if (rules::uapcPermPersonalInfravision() != true)
                ++bad;
            if (rules::uapcPermPersonalProtectionFromEvil() != true)
                ++bad;
            if (rules::uapcPersonalListFromNormalFragment() != true)
                ++bad;
            if (rules::uapcSertenBandAssignmentGarbled() != true)
                ++bad;
            if (rules::uapcSertenBonusHigh() != 9)
                ++bad;
            if (rules::uapcSertenBonusLow() != 5)
                ++bad;
            if (rules::uapcSertenBonusMid() != 7)
                ++bad;
            if (rules::uapcSertenNotVsComelinessFascination() != true)
                ++bad;
            if (rules::uapcSertenSaveEvenIfNoneAllowed() != true)
                ++bad;
            if (rules::uapcSertenSpellCount() != 24)
                ++bad;
            if (rules::uas2Il1stCount() != 5)
                ++bad;
            if (rules::uas2Il2ndCount() != 4)
                ++bad;
            if (rules::uas2Il7thCount() != 1)
                ++bad;
            if (rules::uas2IlCantripCount() != 8)
                ++bad;
            if (rules::uas2Mu1stCount() != 35)
                ++bad;
            if (rules::uas2Mu2ndCount() != 30)
                ++bad;
            if (rules::uas2Mu3rdCount() != 28)
                ++bad;
            if (rules::uas2Mu4thCount() != 28)
                ++bad;
            if (rules::uas2Mu5thCount() != 28)
                ++bad;
            if (rules::uas2Mu6thCount() != 17)
                ++bad;
            if (rules::uas2Mu7thCount() != 16)
                ++bad;
            if (rules::uas2Mu8thCount() != 10)
                ++bad;
            if (rules::uas2Mu9thCount() != 8)
                ++bad;
            if (rules::uas2MuHighTableNineLost() != true)
                ++bad;
            if (rules::uas2MuSixthLevelColumnLost() != false)
                ++bad;
            if (rules::uasm1AquaticSteedsNotBarded() != true)
                ++bad;
            if (rules::uasm1BardEnduranceFromBaseRate() != true)
                ++bad;
            if (rules::uasm1BardHeavyChain() != 13)
                ++bad;
            if (rules::uasm1BardHeavyLeather() != 15)
                ++bad;
            if (rules::uasm1BardHeavyLeatherCellLost() != false)
                ++bad;
            if (rules::uasm1BardHeavyPlate() != 12)
                ++bad;
            if (rules::uasm1BardHeavyScale() != 14)
                ++bad;
            if (rules::uasm1BardLightChain() != 0)
                ++bad;
            if (rules::uasm1BardLightChainNa() != true)
                ++bad;
            if (rules::uasm1BardLightLeather() != 21)
                ++bad;
            if (rules::uasm1BardLightPlateNa() != true)
                ++bad;
            if (rules::uasm1BardLightScale() != 15)
                ++bad;
            if (rules::uasm1BardLightScaleNa() != false)
                ++bad;
            if (rules::uasm1BardMediumChain() != 12)
                ++bad;
            if (rules::uasm1BardMediumLeather() != 17)
                ++bad;
            if (rules::uasm1BardMediumPlateNa() != true)
                ++bad;
            if (rules::uasm1BardMediumScale() != 15)
                ++bad;
            if (rules::uasm1BardMediumScaleCellLost() != false)
                ++bad;
            if (rules::uasm1FlyingSteedsLeatherOrElfinOnly() != true)
                ++bad;
            if (rules::uasm1FlyingSteedsReductionEighth() != true)
                ++bad;
            if (rules::uasm1MagBardingChainPct() != 25)
                ++bad;
            if (rules::uasm1MagBardingCostMultiple() != 5)
                ++bad;
            if (rules::uasm1MagBardingLeatherPct() != 10)
                ++bad;
            if (rules::uasm1MagBardingPlatePct() != 50)
                ++bad;
            if (rules::uasm1MagBardingPlus1Pct() != 65)
                ++bad;
            if (rules::uasm1MagBardingPlus2Pct() != 25)
                ++bad;
            if (rules::uasm1MagBardingPlus3Pct() != 10)
                ++bad;
            if (rules::uasm1MagBardingPlusCap() != 3)
                ++bad;
            if (rules::uasm1MagBardingScalePct() != 15)
                ++bad;
            if (rules::uasm1MethodVAbilityCount() != 7)
                ++bad;
            if (rules::uasm1MethodVBestThreeOfN() != true)
                ++bad;
            if (rules::uasm1MethodVClassCount() != 12)
                ++bad;
            if (rules::uasm1MethodVClassFirst() != true)
                ++bad;
            if (rules::uasm1MethodVFighterStrengthDice() != 9)
                ++bad;
            if (rules::uasm1MethodVHumansOnly() != true)
                ++bad;
            if (rules::uasm1MethodVMaxClampApplies() != true)
                ++bad;
            if (rules::uasm1MethodVMinClampApplies() != true)
                ++bad;
            if (rules::uasm1MethodVRequiresDmApproval() != true)
                ++bad;
            if (rules::uasm1MethodVTableCellsLost() != false)
                ++bad;
            if (rules::uasm1StartHpClassCount() != 12)
                ++bad;
            if (rules::uasm1StartHpConAdjustApplies() != true)
                ++bad;
            if (rules::uasm1StartHpExampleCon17Fighter() != 9)
                ++bad;
            if (rules::uasm1StartHpExampleFighterMage() != 5)
                ++bad;
            if (rules::uasm1StartHpMultiClassAverageRoundedUp() != true)
                ++bad;
            if (rules::uasm1StrongMountPlateReductionMax() != 8)
                ++bad;
            if (rules::uasm1StrongMountPlateReductionMin() != 5)
                ++bad;
            if (rules::uasm1UnicornGriffonElfinWeightAsLeather() != true)
                ++bad;
            if (rules::uastCantripCategoryCount() != 6)
                ++bad;
            if (rules::uastClericTableRowCount() != 20)
                ++bad;
            if (rules::uastDruid1stCount() != 4)
                ++bad;
            if (rules::uastDruid4thCount() != 6)
                ++bad;
            if (rules::uastDruid5thCount() != 6)
                ++bad;
            if (rules::uastDruid6thCount() != 5)
                ++bad;
            if (rules::uastIlHauntingMax() != 8)
                ++bad;
            if (rules::uastIlHauntingMin() != 5)
                ++bad;
            if (rules::uastIlLegerdemainMax() != 6)
                ++bad;
            if (rules::uastIlLegerdemainMin() != 3)
                ++bad;
            if (rules::uastIlMinorIllusionMax() != 8)
                ++bad;
            if (rules::uastIlMinorIllusionMin() != 5)
                ++bad;
            if (rules::uastIlPersonAffectingMax() != 5)
                ++bad;
            if (rules::uastIlPersonAffectingMin() != 2)
                ++bad;
            if (rules::uastIlPersonalMax() != 5)
                ++bad;
            if (rules::uastIlPersonalMin() != 2)
                ++bad;
            if (rules::uastIlReversedMax() != 5)
                ++bad;
            if (rules::uastIlReversedMin() != 2)
                ++bad;
            if (rules::uastIlUsefulAtInt18() != 15)
                ++bad;
            if (rules::uastIlUsefulIntMinus() != 3)
                ++bad;
            if (rules::uastMuCantripMaxNewCount() != 3)
                ++bad;
            if (rules::uastMuHauntingMax() != 5)
                ++bad;
            if (rules::uastMuHauntingMin() != 2)
                ++bad;
            if (rules::uastMuLegerdemainMax() != 5)
                ++bad;
            if (rules::uastMuLegerdemainMin() != 2)
                ++bad;
            if (rules::uastMuPersonAffectingMax() != 8)
                ++bad;
            if (rules::uastMuPersonAffectingMin() != 2)
                ++bad;
            if (rules::uastMuPersonalMax() != 8)
                ++bad;
            if (rules::uastMuPersonalMin() != 2)
                ++bad;
            if (rules::uastMuReversedMax() != 8)
                ++bad;
            if (rules::uastMuReversedMin() != 2)
                ++bad;
            if (rules::uastMuUsefulOnePerIntPoint() != true)
                ++bad;
            if (rules::uastNoteAllCantripsDescribedHere() != true)
                ++bad;
            if (rules::uchCreakFormerDen() != 3)
                ++bad;
            if (rules::uchCreakLatterHalfSegs() != 1)
                ++bad;
            if (rules::uchCreakTraverseFeet() != 10)
                ++bad;
            if (rules::uchFootfallFarVal() != 2)
                ++bad;
            if (rules::uchHauntingSoundCount() != 8)
                ++bad;
            if (rules::uchMoanFlavors() != 2)
                ++bad;
            if (rules::uchRangeNearVal() != 1)
                ++bad;
            if (rules::uchRangeUnitIsInch() != true)
                ++bad;
            if (rules::uchRattleSeconds() != 2)
                ++bad;
            if (rules::uchTapCountMax() != 3)
                ++bad;
            if (rules::uchTapCountMin() != 1)
                ++bad;
            if (rules::uchWhistleFaintFeet() != 10)
                ++bad;
            if (rules::uchWhistleLoudFeet() != 30)
                ++bad;
            if (rules::uclChangeBaseTurns() != 1)
                ++bad;
            if (rules::uclChangeRadicalRounds() != 1)
                ++bad;
            if (rules::uclChangeSizePctMax() != 50)
                ++bad;
            if (rules::uclChangeSlightDays() != 1)
                ++bad;
            if (rules::uclDistractDurationSegments() != 1)
                ++bad;
            if (rules::uclDistractRangeFt() != 10)
                ++bad;
            if (rules::uclHideBaseCubicYds() != 2)
                ++bad;
            if (rules::uclHideBaseTurns() != 1)
                ++bad;
            if (rules::uclHideMinCubicYds() != 38)
                ++bad;
            if (rules::uclHideMinSegments() != 1)
                ++bad;
            if (rules::uclHideRoundCubicYds() != 20)
                ++bad;
            if (rules::uclHideSegStartCubicYds() != 22)
                ++bad;
            if (rules::uclHideSegStartSegments() != 9)
                ++bad;
            if (rules::uclHideSegStepCubicYds() != 2)
                ++bad;
            if (rules::uclLegerdemainCount() != 6)
                ++bad;
            if (rules::uclMuteDurationRounds() != 1)
                ++bad;
            if (rules::uclPalmDurationSegments() != 1)
                ++bad;
            if (rules::uclPresentMaxCoins() != 12)
                ++bad;
            if (rules::uclPresentRadiusFt() != 2)
                ++bad;
            if (rules::ucnColorRenewDays() != 30)
                ++bad;
            if (rules::ucnFreshenDmgMax() != 4)
                ++bad;
            if (rules::ucnPolishFloorSqFt() != 1000)
                ++bad;
            if (rules::ucnSaltDmgMax() != 4)
                ++bad;
            if (rules::ucnSaltGallons() != 30)
                ++bad;
            if (rules::ucnSaltObjectSqYds() != 4)
                ++bad;
            if (rules::ucnShineMaxCubicYds() != 1)
                ++bad;
            if (rules::ucnShineRevalueDieMod() != -1)
                ++bad;
            if (rules::ucnShineRevalueOnceOnly() != true)
                ++bad;
            if (rules::ucnTempDeltaF() != 40)
                ++bad;
            if (rules::ucnTieRangeFt() != 1)
                ++bad;
            if (rules::ucnUsefulCount() != 20)
                ++bad;
            if (rules::ucoBeeStingPct() != 90)
                ++bad;
            if (rules::ucoBluelightRadiusFeet() != 5)
                ++bad;
            if (rules::ucoBluelightSphereInches() != 3)
                ++bad;
            if (rules::ucoFirefingerJetInches() != 6)
                ++bad;
            if (rules::ucoFirefingerSegments() != 1)
                ++bad;
            if (rules::ucoGnatsDistractMaxSegments() != 4)
                ++bad;
            if (rules::ucoGnatsDistractMinSegments() != 1)
                ++bad;
            if (rules::ucoPersonalCount() != 10)
                ++bad;
            if (rules::ucoRangeUnitIsInch() != true)
                ++bad;
            if (rules::ucoRangeVal() != 1)
                ++bad;
            if (rules::ucoSlowPoisonDeferDays() != 1)
                ++bad;
            if (rules::ucoSmokepuffColors() != 6)
                ++bad;
            if (rules::ucoSpiderBiteDistractSegments() != 1)
                ++bad;
            if (rules::ucoSpiderHitHeavy() != 2)
                ++bad;
            if (rules::ucoSpiderHitLight() != 1)
                ++bad;
            if (rules::ucoSpiderPoisonPct() != 5)
                ++bad;
            if (rules::ucoSpiderPoisonSaveBonus() != 4)
                ++bad;
            if (rules::ucoSpiderSickMaxDays() != 4)
                ++bad;
            if (rules::ucoSpiderSickMinDays() != 1)
                ++bad;
            if (rules::ucoSpiderSizeMaxInches() != 2)
                ++bad;
            if (rules::ucoTweakDice() != 3)
                ++bad;
            if (rules::ucoTweakDistractSegments() != 1)
                ++bad;
            if (rules::ucoTweakIntThreshold() != 7)
                ++bad;
            if (rules::ucoTweakPortions() != 7)
                ++bad;
            if (rules::ucpBlinkDurationHalfSecs() != 1)
                ++bad;
            if (rules::ucpCoughMaxSeconds() != 3)
                ++bad;
            if (rules::ucpCoughMinSeconds() != 1)
                ++bad;
            if (rules::ucpGiggleMaxSeconds() != 3)
                ++bad;
            if (rules::ucpGiggleMinSeconds() != 2)
                ++bad;
            if (rules::ucpPersonAffectingCount() != 10)
                ++bad;
            if (rules::ucpScratchSeconds() != 1)
                ++bad;
            if (rules::ucpYawnExtraVulnerable() != 1)
                ++bad;
            if (rules::ucpYawnSleepBandHi() != 44)
                ++bad;
            if (rules::ucpYawnSleepBandLo() != 41)
                ++bad;
            if (rules::ucpYawnSleepHdLow() != 4)
                ++bad;
            if (rules::ucpYawnSleepHdMax() != 52)
                ++bad;
            if (rules::ucpYawnUnaffectedPct() != 50)
                ++bad;
            if (rules::ucpYawnWindowRounds() != 2)
                ++bad;
            if (rules::ucrHairyAbsenceMaxDays() != 12)
                ++bad;
            if (rules::ucrHairyAbsenceMinDays() != 2)
                ++bad;
            if (rules::ucrHairyGrowthMaxIn() != 12)
                ++bad;
            if (rules::ucrHairyGrowthMinIn() != 2)
                ++bad;
            if (rules::ucrHairyShortUnderIn() != 1)
                ++bad;
            if (rules::ucrKnotUntieMaxRounds() != 8)
                ++bad;
            if (rules::ucrKnotUntieMinRounds() != 2)
                ++bad;
            if (rules::ucrReversedCount() != 12)
                ++bad;
            if (rules::ucrSourMaxPints() != 1)
                ++bad;
            if (rules::ucrSpillMaxGallons() != 1)
                ++bad;
            if (rules::ucrTangleUntangleMaxRounds() != 12)
                ++bad;
            if (rules::ucrTangleUntangleMinRounds() != 3)
                ++bad;
            if (rules::ucrTarnishMaxCubicYds() != 1)
                ++bad;
            if (rules::uscChartCount() != 5)
                ++bad;
            if (rules::uscChartRowCount() != 23)
                ++bad;
            if (rules::uscDwarfClericGenderSplit() != true)
                ++bad;
            if (rules::uscElfClericsEitherGender() != true)
                ++bad;
            if (rules::uscGnomeClericsNeverDruids() != true)
                ++bad;
            if (rules::uscGnomishClericsAllMale() != true)
                ++bad;
            if (std::string(rules::uac1CeremonyComponents())
                != "V, S, M") ++bad;
            if (std::string(rules::uac1CeremonyName())
                != "Ceremony (Invocation)") ++bad;
            if (std::string(rules::uac1CombineName())
                != "Combine (Evocation)") ++bad;
            if (std::string(rules::uac1EndureName())
                != "Endure Cold / Endure Heat") ++bad;
            if (std::string(rules::uac1ItuName())
                != "Invisibility to Undead") ++bad;
            if (std::string(rules::uac1MagicStoneName())
                != "Magic Stone (Alteration)") ++bad;
            if (std::string(rules::uac1PenetrateName())
                != "Penetrate Disguise (Divination)") ++bad;
            if (std::string(rules::uac1PortentName())
                != "Portent (Divination)") ++bad;
            if (std::string(rules::uac1PrecipName())
                != "Precipitation (Alteration)") ++bad;
            if (std::string(rules::uac5AirwalkName())
                != "Air Walk (Alteration)") ++bad;
            if (std::string(rules::uac5AnimateName())
                != "Animate Dead Monsters (Necromantic)") ++bad;
            if (std::string(rules::uac5FontName())
                != "Magic Font (Divination)") ++bad;
            if (std::string(rules::uac5GolemName())
                != "Golem (Enchantment/Charm)") ++bad;
            if (std::string(rules::uac5RainbowName())
                != "Rainbow (Evocation/Alteration)") ++bad;
            if (std::string(rules::uac5SpikeStonesName())
                != "Spike Stones (Alteration/Enchantment)") ++bad;
            if (std::string(rules::uac7ExactionName())
                != "Exaction (Evocation - Alteration)") ++bad;
            if (std::string(rules::uac7SuccorName())
                != "Succor (Alteration - Enchantment) Reversible") ++bad;
            if (std::string(rules::uad1CeremonyName())
                != "Ceremony (Invocation)") ++bad;
            if (std::string(rules::uad1DetectBalanceName())
                != "Detect Balance (Divination)") ++bad;
            if (std::string(rules::uad1DetectPoisonName())
                != "Detect Poison (Divination)") ++bad;
            if (std::string(rules::uad1PrecipName())
                != "Precipitation") ++bad;
            if (std::string(rules::uad2FlameBladeName())
                != "Flame Blade (Evocation)") ++bad;
            if (std::string(rules::uad2GoodberryName())
                != "Goodberry") ++bad;
            if (std::string(rules::uad2ReflectingPoolName())
                != "Reflecting Pool") ++bad;
            if (std::string(rules::uad2SlowPoisonName())
                != "Slow Poison (Necromantic)") ++bad;
            if (std::string(rules::uail1OrbName())
                != "Chromatic Orb") ++bad;
            if (std::string(rules::uail1PhantomName())
                != "Phantom Armor (Alteration/Illusion)") ++bad;
            if (std::string(rules::uailcDimName())
                != "Dim (Alteration)") ++bad;
            if (std::string(rules::uailcHazeName())
                != "Haze (Alteration)") ++bad;
            if (std::string(rules::uailcLightsName())
                != "Colored Lights (Alteration)") ++bad;
            if (std::string(rules::uailcMaskName())
                != "Mask (Illusion)") ++bad;
            if (std::string(rules::uailcMirageName())
                != "Mirage") ++bad;
            if (std::string(rules::uailcNoiseName())
                != "Noise (Illusion)") ++bad;
            if (std::string(rules::uailcRainbowName())
                != "Rainbow (Alteration)") ++bad;
            if (std::string(rules::uailcTwodName())
                != "Two-D'lusion") ++bad;
            if (rules::uail1OrbRowDamageCellLost(0) != false)
                ++bad;
            if (rules::uail1OrbRowDamageCellLost(1) != false)
                ++bad;
            if (rules::uail1OrbRowDamageCellLost(6) != false)
                ++bad;
            if (rules::uail1OrbRowDamageCellLost(7) != true)
                ++bad;
            if (rules::uail1OrbRowDamageCellLost(8) != true)
                ++bad;
            if (rules::uail1OrbRowDamageCellLost(9) != false)
                ++bad;
            if (rules::ucnSchoolCount(0) != 7)
                ++bad;
            if (rules::ucnSchoolCount(1) != 4)
                ++bad;
            if (rules::ucnSchoolCount(2) != 7)
                ++bad;
            if (rules::ucnSchoolCount(3) != 2)
                ++bad;
            if (rules::ucnSchoolCount(999) != 0)
                ++bad;
            if (rules::ucnAreaKindCount(-1) != 6)
                ++bad;
            if (rules::ucnAreaKindCount(0) != 8)
                ++bad;
            if (rules::ucnAreaKindCount(1) != 2)
                ++bad;
            if (rules::ucnAreaKindCount(2) != 2)
                ++bad;
            if (rules::ucnAreaKindCount(3) != 1)
                ++bad;
            if (rules::ucnAreaKindCount(4) != 1)
                ++bad;
            if (rules::ucnAreaKindCount(999) != 0)
                ++bad;
            if (rules::ucrSchoolCount(0) != 3)
                ++bad;
            if (rules::ucrSchoolCount(2) != 7)
                ++bad;
            if (rules::ucrSchoolCount(3) != 2)
                ++bad;
            if (rules::ucrSchoolCount(999) != 0)
                ++bad;
            if (rules::ucrAreaKindCount(0) != 8)
                ++bad;
            if (rules::ucrAreaKindCount(3) != 1)
                ++bad;
            if (rules::ucrAreaKindCount(4) != 1)
                ++bad;
            if (rules::ucrAreaKindCount(5) != 1)
                ++bad;
            if (rules::ucrAreaKindCount(6) != 1)
                ++bad;
            if (rules::ucrAreaKindCount(999) != 0)
                ++bad;
            if (rules::uclSchoolCount(2) != 3)
                ++bad;
            if (rules::uclSchoolCount(3) != 1)
                ++bad;
            if (rules::uclSchoolCount(4) != 2)
                ++bad;
            if (rules::uclSchoolCount(999) != 0)
                ++bad;
            if (rules::uclAreaKindCount(0) != 3)
                ++bad;
            if (rules::uclAreaKindCount(3) != 1)
                ++bad;
            if (rules::uclAreaKindCount(7) != 2)
                ++bad;
            if (rules::uclAreaKindCount(999) != 0)
                ++bad;
            if (rules::ucpSchoolCount(0) != 8)
                ++bad;
            if (rules::ucpSchoolCount(3) != 1)
                ++bad;
            if (rules::ucpSchoolCount(5) != 1)
                ++bad;
            if (rules::ucpSchoolCount(999) != 0)
                ++bad;
            if (rules::ucpAreaKindCount(8) != 6)
                ++bad;
            if (rules::ucpAreaKindCount(9) != 4)
                ++bad;
            if (rules::ucpAreaKindCount(999) != 0)
                ++bad;
            if (rules::ucoSchoolCount(0) != 1)
                ++bad;
            if (rules::ucoSchoolCount(2) != 1)
                ++bad;
            if (rules::ucoSchoolCount(6) != 5)
                ++bad;
            if (rules::ucoSchoolCount(7) != 3)
                ++bad;
            if (rules::ucoSchoolCount(999) != 0)
                ++bad;
            if (rules::ucoAreaKindCount(1) != 1)
                ++bad;
            if (rules::ucoAreaKindCount(9) != 1)
                ++bad;
            if (rules::ucoAreaKindCount(10) != 4)
                ++bad;
            if (rules::ucoAreaKindCount(11) != 1)
                ++bad;
            if (rules::ucoAreaKindCount(12) != 1)
                ++bad;
            if (rules::ucoAreaKindCount(13) != 1)
                ++bad;
            if (rules::ucoAreaKindCount(14) != 1)
                ++bad;
            if (rules::ucoAreaKindCount(999) != 0)
                ++bad;
            if (rules::uchSchoolCount(0) != 3)
                ++bad;
            if (rules::uchSchoolCount(4) != 5)
                ++bad;
            if (rules::uchSchoolCount(999) != 0)
                ++bad;
            if (rules::uchAreaKindCount(3) != 7)
                ++bad;
            if (rules::uchAreaKindCount(13) != 1)
                ++bad;
            if (rules::uchAreaKindCount(999) != 0)
                ++bad;
            if (rules::ucnCastTimeDenCount(2) != 17)
                ++bad;
            if (rules::ucnCastTimeDenCount(8) != 2)
                ++bad;
            if (rules::ucnCastTimeDenCount(10) != 1)
                ++bad;
            if (rules::ucnCastTimeDenCount(999) != 0)
                ++bad;
            if (rules::ucrCastTimeDenCount(2) != 4)
                ++bad;
            if (rules::ucrCastTimeDenCount(3) != 1)
                ++bad;
            if (rules::ucrCastTimeDenCount(8) != 5)
                ++bad;
            if (rules::ucrCastTimeDenCount(10) != 2)
                ++bad;
            if (rules::ucrCastTimeDenCount(999) != 0)
                ++bad;
            if (rules::uclCastTimeDenCount(3) != 1)
                ++bad;
            if (rules::uclCastTimeDenCount(8) != 1)
                ++bad;
            if (rules::uclCastTimeDenCount(10) != 4)
                ++bad;
            if (rules::uclCastTimeDenCount(999) != 0)
                ++bad;
            if (rules::ucpCastTimeDenCount(2) != 1)
                ++bad;
            if (rules::ucpCastTimeDenCount(3) != 3)
                ++bad;
            if (rules::ucpCastTimeDenCount(8) != 2)
                ++bad;
            if (rules::ucpCastTimeDenCount(10) != 4)
                ++bad;
            if (rules::ucpCastTimeDenCount(999) != 0)
                ++bad;
            if (rules::ucoCastTimeDenCount(2) != 7)
                ++bad;
            if (rules::ucoCastTimeDenCount(3) != 3)
                ++bad;
            if (rules::ucoCastTimeDenCount(999) != 0)
                ++bad;
            if (rules::uchCastTimeDenCount(6) != 5)
                ++bad;
            if (rules::uchCastTimeDenCount(10) != 3)
                ++bad;
            if (rules::uchCastTimeDenCount(999) != 0)
                ++bad;
            if (rules::uailcCastTimeDenCount(2) != 4)
                ++bad;
            if (rules::uailcCastTimeDenCount(3) != 1)
                ++bad;
            if (rules::uailcCastTimeDenCount(8) != 3)
                ++bad;
            if (rules::uailcCastTimeDenCount(999) != 0)
                ++bad;
            if (rules::uscNamedSacredAnimalCount() != 13) ++bad;
            if (rules::uscFrequencyCount("annually") != 4)
                ++bad;
            if (rules::uscFrequencyCount("before & after battle") != 1)
                ++bad;
            if (rules::uscFrequencyCount("before battle") != 2)
                ++bad;
            if (rules::uscFrequencyCount("daily") != 1)
                ++bad;
            if (rules::uscFrequencyCount("monthly") != 10)
                ++bad;
            if (rules::uscFrequencyCount("quarterly") != 1)
                ++bad;
            if (rules::uscFrequencyCount("semi-annual") != 1)
                ++bad;
            if (rules::uscFrequencyCount("varies") != 2)
                ++bad;
            if (rules::uscFrequencyCount("yearly") != 1)
                ++bad;
            if (rules::uscFrequencyCount("never") != 0)
                ++bad;
            if (std::string(rules::uscChartRow(0).name)
                != "Clanggedin") ++bad;
            if (std::string(rules::uscChartRow(0).sphere)
                != "war, battle") ++bad;
            if (std::string(rules::uscChartRow(0).head)
                != "war helm") ++bad;
            if (std::string(rules::uscChartRow(0).body)
                != "chain mail") ++bad;
            if (std::string(rules::uscChartRow(0).color)
                != "silver") ++bad;
            if (std::string(rules::uscChartRow(0).days)
                != "before battle") ++bad;
            if (std::string(rules::uscChartRow(0).freq)
                != "before battle") ++bad;
            if (std::string(rules::uscChartRow(0).form)
                != "weapons") ++bad;
            if (std::string(rules::uscChartRow(1).name)
                != "Vergadain") ++bad;
            if (std::string(rules::uscChartRow(1).sphere)
                != "suspicion, trickery") ++bad;
            if (std::string(rules::uscChartRow(1).head)
                != "helmet") ++bad;
            if (std::string(rules::uscChartRow(1).body)
                != "chain mail") ++bad;
            if (std::string(rules::uscChartRow(1).color)
                != "gold") ++bad;
            if (std::string(rules::uscChartRow(1).days)
                != "full moon") ++bad;
            if (std::string(rules::uscChartRow(1).freq)
                != "monthly") ++bad;
            if (std::string(rules::uscChartRow(1).form)
                != "gold") ++bad;
            if (std::string(rules::uscChartRow(2).name)
                != "Dumathoin") ++bad;
            if (std::string(rules::uscChartRow(2).sphere)
                != "secrets, earth") ++bad;
            if (std::string(rules::uscChartRow(2).head)
                != "bare") ++bad;
            if (std::string(rules::uscChartRow(2).body)
                != "leather") ++bad;
            if (std::string(rules::uscChartRow(2).color)
                != "brown") ++bad;
            if (std::string(rules::uscChartRow(2).days)
                != "new moon") ++bad;
            if (std::string(rules::uscChartRow(2).freq)
                != "monthly") ++bad;
            if (std::string(rules::uscChartRow(2).form)
                != "gems & jewels") ++bad;
            if (std::string(rules::uscChartRow(3).name)
                != "Abbathor") ++bad;
            if (std::string(rules::uscChartRow(3).sphere)
                != "evil, greed") ++bad;
            if (std::string(rules::uscChartRow(3).head)
                != "leather cap") ++bad;
            if (std::string(rules::uscChartRow(3).body)
                != "leather") ++bad;
            if (std::string(rules::uscChartRow(3).color)
                != "red") ++bad;
            if (std::string(rules::uscChartRow(3).days)
                != "solar eclipses") ++bad;
            if (std::string(rules::uscChartRow(3).freq)
                != "annually") ++bad;
            if (std::string(rules::uscChartRow(3).form)
                != "blood & gems") ++bad;
            if (std::string(rules::uscChartRow(4).name)
                != "Berronar") ++bad;
            if (std::string(rules::uscChartRow(4).sphere)
                != "safety, truth") ++bad;
            if (std::string(rules::uscChartRow(4).head)
                != "silvered helm") ++bad;
            if (std::string(rules::uscChartRow(4).body)
                != "chain mail") ++bad;
            if (std::string(rules::uscChartRow(4).color)
                != "silver") ++bad;
            if (std::string(rules::uscChartRow(4).days)
                != "new year's day") ++bad;
            if (std::string(rules::uscChartRow(4).freq)
                != "annually") ++bad;
            if (std::string(rules::uscChartRow(4).form)
                != "silver") ++bad;
            if (std::string(rules::uscChartRow(5).name)
                != "Aerdrie") ++bad;
            if (std::string(rules::uscChartRow(5).sphere)
                != "air, weather, birds") ++bad;
            if (std::string(rules::uscChartRow(5).head)
                != "one feather") ++bad;
            if (std::string(rules::uscChartRow(5).body)
                != "sky-blue robes") ++bad;
            if (std::string(rules::uscChartRow(5).color)
                != "sky blue") ++bad;
            if (std::string(rules::uscChartRow(5).days)
                != "spring & fall equinoxes") ++bad;
            if (std::string(rules::uscChartRow(5).freq)
                != "semi-annual") ++bad;
            if (std::string(rules::uscChartRow(5).form)
                != "beautiful feathers") ++bad;
            if (std::string(rules::uscChartRow(6).name)
                != "Erevan") ++bad;
            if (std::string(rules::uscChartRow(6).sphere)
                != "mischief, change, thieves") ++bad;
            if (std::string(rules::uscChartRow(6).head)
                != "leather cap") ++bad;
            if (std::string(rules::uscChartRow(6).body)
                != "leather armor") ++bad;
            if (std::string(rules::uscChartRow(6).color)
                != "black") ++bad;
            if (std::string(rules::uscChartRow(6).days)
                != "eclipses") ++bad;
            if (std::string(rules::uscChartRow(6).freq)
                != "varies") ++bad;
            if (std::string(rules::uscChartRow(6).form)
                != "stolen treasures") ++bad;
            if (std::string(rules::uscChartRow(7).name)
                != "Solonor") ++bad;
            if (std::string(rules::uscChartRow(7).sphere)
                != "archery, hunting") ++bad;
            if (std::string(rules::uscChartRow(7).head)
                != "green hood") ++bad;
            if (std::string(rules::uscChartRow(7).body)
                != "elfin chain & silver") ++bad;
            if (std::string(rules::uscChartRow(7).color)
                != "leaf green") ++bad;
            if (std::string(rules::uscChartRow(7).days)
                != "full moon") ++bad;
            if (std::string(rules::uscChartRow(7).freq)
                != "monthly") ++bad;
            if (std::string(rules::uscChartRow(7).form)
                != "hunting trophies") ++bad;
            if (std::string(rules::uscChartRow(8).name)
                != "Hanali") ++bad;
            if (std::string(rules::uscChartRow(8).sphere)
                != "romance, beauty") ++bad;
            if (std::string(rules::uscChartRow(8).head)
                != "bare") ++bad;
            if (std::string(rules::uscChartRow(8).body)
                != "gold robes") ++bad;
            if (std::string(rules::uscChartRow(8).color)
                != "gold") ++bad;
            if (std::string(rules::uscChartRow(8).days)
                != "full moon") ++bad;
            if (std::string(rules::uscChartRow(8).freq)
                != "monthly") ++bad;
            if (std::string(rules::uscChartRow(8).form)
                != "beautiful objects") ++bad;
            if (std::string(rules::uscChartRow(9).name)
                != "Labelas") ++bad;
            if (std::string(rules::uscChartRow(9).sphere)
                != "longevity, time") ++bad;
            if (std::string(rules::uscChartRow(9).head)
                != "bare") ++bad;
            if (std::string(rules::uscChartRow(9).body)
                != "gray robes") ++bad;
            if (std::string(rules::uscChartRow(9).color)
                != "light gray") ++bad;
            if (std::string(rules::uscChartRow(9).days)
                != "sunset") ++bad;
            if (std::string(rules::uscChartRow(9).freq)
                != "daily") ++bad;
            if (std::string(rules::uscChartRow(9).form)
                != "prayers & knowledge") ++bad;
            if (std::string(rules::uscChartRow(10).name)
                != "Sheela") ++bad;
            if (std::string(rules::uscChartRow(10).sphere)
                != "agriculture, weather") ++bad;
            if (std::string(rules::uscChartRow(10).head)
                != "bare") ++bad;
            if (std::string(rules::uscChartRow(10).body)
                != "green robes") ++bad;
            if (std::string(rules::uscChartRow(10).color)
                != "green") ++bad;
            if (std::string(rules::uscChartRow(10).days)
                != "full moon") ++bad;
            if (std::string(rules::uscChartRow(10).freq)
                != "monthly") ++bad;
            if (std::string(rules::uscChartRow(10).form)
                != "seeds") ++bad;
            if (std::string(rules::uscChartRow(11).name)
                != "Arvoreen") ++bad;
            if (std::string(rules::uscChartRow(11).sphere)
                != "defense, warriors") ++bad;
            if (std::string(rules::uscChartRow(11).head)
                != "helmet") ++bad;
            if (std::string(rules::uscChartRow(11).body)
                != "chainmail") ++bad;
            if (std::string(rules::uscChartRow(11).color)
                != "silver") ++bad;
            if (std::string(rules::uscChartRow(11).days)
                != "before battle") ++bad;
            if (std::string(rules::uscChartRow(11).freq)
                != "varies") ++bad;
            if (std::string(rules::uscChartRow(11).form)
                != "silvered weapons") ++bad;
            if (std::string(rules::uscChartRow(12).name)
                != "Cyrrollalee") ++bad;
            if (std::string(rules::uscChartRow(12).sphere)
                != "trust, protection") ++bad;
            if (std::string(rules::uscChartRow(12).head)
                != "bare") ++bad;
            if (std::string(rules::uscChartRow(12).body)
                != "brown robes") ++bad;
            if (std::string(rules::uscChartRow(12).color)
                != "brown") ++bad;
            if (std::string(rules::uscChartRow(12).days)
                != "first day of month") ++bad;
            if (std::string(rules::uscChartRow(12).freq)
                != "monthly") ++bad;
            if (std::string(rules::uscChartRow(12).form)
                != "prayers") ++bad;
            if (std::string(rules::uscChartRow(13).name)
                != "Brandobaris") ++bad;
            if (std::string(rules::uscChartRow(13).sphere)
                != "thieves") ++bad;
            if (std::string(rules::uscChartRow(13).head)
                != "feathered cap") ++bad;
            if (std::string(rules::uscChartRow(13).body)
                != "leather armor") ++bad;
            if (std::string(rules::uscChartRow(13).color)
                != "gray") ++bad;
            if (std::string(rules::uscChartRow(13).days)
                != "new moon") ++bad;
            if (std::string(rules::uscChartRow(13).freq)
                != "monthly") ++bad;
            if (std::string(rules::uscChartRow(13).form)
                != "stolen items") ++bad;
            if (std::string(rules::uscChartRow(14).name)
                != "Baervan") ++bad;
            if (std::string(rules::uscChartRow(14).sphere)
                != "adventure, thieves") ++bad;
            if (std::string(rules::uscChartRow(14).head)
                != "green cap") ++bad;
            if (std::string(rules::uscChartRow(14).body)
                != "brown clothes") ++bad;
            if (std::string(rules::uscChartRow(14).color)
                != "wood brown") ++bad;
            if (std::string(rules::uscChartRow(14).days)
                != "full moon") ++bad;
            if (std::string(rules::uscChartRow(14).freq)
                != "monthly") ++bad;
            if (std::string(rules::uscChartRow(14).form)
                != "treasure items") ++bad;
            if (std::string(rules::uscChartRow(15).name)
                != "Urdlen") ++bad;
            if (std::string(rules::uscChartRow(15).sphere)
                != "evil") ++bad;
            if (std::string(rules::uscChartRow(15).head)
                != "bare") ++bad;
            if (std::string(rules::uscChartRow(15).body)
                != "white cloak") ++bad;
            if (std::string(rules::uscChartRow(15).color)
                != "white") ++bad;
            if (std::string(rules::uscChartRow(15).days)
                != "winter solstice") ++bad;
            if (std::string(rules::uscChartRow(15).freq)
                != "annually") ++bad;
            if (std::string(rules::uscChartRow(15).form)
                != "blood & jewels") ++bad;
            if (std::string(rules::uscChartRow(16).name)
                != "Segojan") ++bad;
            if (std::string(rules::uscChartRow(16).sphere)
                != "earth, nature") ++bad;
            if (std::string(rules::uscChartRow(16).head)
                != "fur cap") ++bad;
            if (std::string(rules::uscChartRow(16).body)
                != "leather armor") ++bad;
            if (std::string(rules::uscChartRow(16).color)
                != "gray & dark brown") ++bad;
            if (std::string(rules::uscChartRow(16).days)
                != "first day of each season") ++bad;
            if (std::string(rules::uscChartRow(16).freq)
                != "quarterly") ++bad;
            if (std::string(rules::uscChartRow(16).form)
                != "gemstones") ++bad;
            if (std::string(rules::uscChartRow(17).name)
                != "Flandal") ++bad;
            if (std::string(rules::uscChartRow(17).sphere)
                != "metalworking") ++bad;
            if (std::string(rules::uscChartRow(17).head)
                != "steel helm") ++bad;
            if (std::string(rules::uscChartRow(17).body)
                != "leather armor") ++bad;
            if (std::string(rules::uscChartRow(17).color)
                != "red") ++bad;
            if (std::string(rules::uscChartRow(17).days)
                != "midsummer's day") ++bad;
            if (std::string(rules::uscChartRow(17).freq)
                != "annually") ++bad;
            if (std::string(rules::uscChartRow(17).form)
                != "forged weapons") ++bad;
            if (std::string(rules::uscChartRow(18).name)
                != "Bahgtru") ++bad;
            if (std::string(rules::uscChartRow(18).sphere)
                != "strength") ++bad;
            if (std::string(rules::uscChartRow(18).head)
                != "bare") ++bad;
            if (std::string(rules::uscChartRow(18).body)
                != "loincloth") ++bad;
            if (std::string(rules::uscChartRow(18).color)
                != "n/a") ++bad;
            if (std::string(rules::uscChartRow(18).days)
                != "battle days") ++bad;
            if (std::string(rules::uscChartRow(18).freq)
                != "before battle") ++bad;
            if (std::string(rules::uscChartRow(18).form)
                != "bones of enemies") ++bad;
            if (std::string(rules::uscChartRow(19).name)
                != "Shargaas") ++bad;
            if (std::string(rules::uscChartRow(19).sphere)
                != "night, thieves") ++bad;
            if (std::string(rules::uscChartRow(19).head)
                != "leather cap") ++bad;
            if (std::string(rules::uscChartRow(19).body)
                != "leather armor") ++bad;
            if (std::string(rules::uscChartRow(19).color)
                != "red & black") ++bad;
            if (std::string(rules::uscChartRow(19).days)
                != "new moon") ++bad;
            if (std::string(rules::uscChartRow(19).freq)
                != "monthly") ++bad;
            if (std::string(rules::uscChartRow(19).form)
                != "stolen items") ++bad;
            if (std::string(rules::uscChartRow(20).name)
                != "Ilneval") ++bad;
            if (std::string(rules::uscChartRow(20).sphere)
                != "warriors") ++bad;
            if (std::string(rules::uscChartRow(20).head)
                != "red metal helmet") ++bad;
            if (std::string(rules::uscChartRow(20).body)
                != "red metal armor") ++bad;
            if (std::string(rules::uscChartRow(20).color)
                != "red") ++bad;
            if (std::string(rules::uscChartRow(20).days)
                != "battle days") ++bad;
            if (std::string(rules::uscChartRow(20).freq)
                != "before & after battle") ++bad;
            if (std::string(rules::uscChartRow(20).form)
                != "blood & weapons") ++bad;
            if (std::string(rules::uscChartRow(21).name)
                != "Yurtrus") ++bad;
            if (std::string(rules::uscChartRow(21).sphere)
                != "death, plague") ++bad;
            if (std::string(rules::uscChartRow(21).head)
                != "bare") ++bad;
            if (std::string(rules::uscChartRow(21).body)
                != "skins") ++bad;
            if (std::string(rules::uscChartRow(21).color)
                != "white") ++bad;
            if (std::string(rules::uscChartRow(21).days)
                != "full moon") ++bad;
            if (std::string(rules::uscChartRow(21).freq)
                != "monthly") ++bad;
            if (std::string(rules::uscChartRow(21).form)
                != "sacrifices") ++bad;
            if (std::string(rules::uscChartRow(22).name)
                != "Luthic") ++bad;
            if (std::string(rules::uscChartRow(22).sphere)
                != "caves, healing, females") ++bad;
            if (std::string(rules::uscChartRow(22).head)
                != "fur cap") ++bad;
            if (std::string(rules::uscChartRow(22).body)
                != "leather armor") ++bad;
            if (std::string(rules::uscChartRow(22).color)
                != "brown & black") ++bad;
            if (std::string(rules::uscChartRow(22).days)
                != "midwinter's day") ++bad;
            if (std::string(rules::uscChartRow(22).freq)
                != "yearly") ++bad;
            if (std::string(rules::uscChartRow(22).form)
                != "treasures") ++bad;
            if (std::string(rules::ucnUseful(0).name)
                != "Chill") ++bad;
            if (rules::ucnUseful(0).school != 0)
                ++bad;
            if (rules::ucnUseful(0).areaKind != 1)
                ++bad;
            if (rules::ucnUseful(0).areaVal != 1)
                ++bad;
            if (std::string(rules::ucnUseful(1).name)
                != "Clean") ++bad;
            if (rules::ucnUseful(1).school != 1)
                ++bad;
            if (rules::ucnUseful(1).areaKind != 4)
                ++bad;
            if (rules::ucnUseful(1).areaVal != 4)
                ++bad;
            if (std::string(rules::ucnUseful(2).name)
                != "Color") ++bad;
            if (rules::ucnUseful(2).school != 0)
                ++bad;
            if (rules::ucnUseful(2).areaKind != 2)
                ++bad;
            if (rules::ucnUseful(2).areaVal != 1)
                ++bad;
            if (std::string(rules::ucnUseful(3).name)
                != "Dampen") ++bad;
            if (rules::ucnUseful(3).school != 0)
                ++bad;
            if (rules::ucnUseful(3).areaKind != -1)
                ++bad;
            if (rules::ucnUseful(3).areaVal != 0)
                ++bad;
            if (std::string(rules::ucnUseful(4).name)
                != "Dry") ++bad;
            if (rules::ucnUseful(4).school != 1)
                ++bad;
            if (rules::ucnUseful(4).areaKind != -1)
                ++bad;
            if (rules::ucnUseful(4).areaVal != 0)
                ++bad;
            if (std::string(rules::ucnUseful(5).name)
                != "Dust") ++bad;
            if (rules::ucnUseful(5).school != 1)
                ++bad;
            if (rules::ucnUseful(5).areaKind != -1)
                ++bad;
            if (rules::ucnUseful(5).areaVal != 0)
                ++bad;
            if (std::string(rules::ucnUseful(6).name)
                != "Exterminate") ++bad;
            if (rules::ucnUseful(6).school != 1)
                ++bad;
            if (rules::ucnUseful(6).areaKind != -1)
                ++bad;
            if (rules::ucnUseful(6).areaVal != 0)
                ++bad;
            if (std::string(rules::ucnUseful(7).name)
                != "Flavor") ++bad;
            if (rules::ucnUseful(7).school != 3)
                ++bad;
            if (rules::ucnUseful(7).areaKind != 0)
                ++bad;
            if (rules::ucnUseful(7).areaVal != 0)
                ++bad;
            if (std::string(rules::ucnUseful(8).name)
                != "Freshen") ++bad;
            if (rules::ucnUseful(8).school != 3)
                ++bad;
            if (rules::ucnUseful(8).areaKind != 0)
                ++bad;
            if (rules::ucnUseful(8).areaVal != 0)
                ++bad;
            if (std::string(rules::ucnUseful(9).name)
                != "Gather") ++bad;
            if (rules::ucnUseful(9).school != 2)
                ++bad;
            if (rules::ucnUseful(9).areaKind != -1)
                ++bad;
            if (rules::ucnUseful(9).areaVal != 0)
                ++bad;
            if (std::string(rules::ucnUseful(10).name)
                != "Polish") ++bad;
            if (rules::ucnUseful(10).school != 2)
                ++bad;
            if (rules::ucnUseful(10).areaKind != 0)
                ++bad;
            if (rules::ucnUseful(10).areaVal != 0)
                ++bad;
            if (std::string(rules::ucnUseful(11).name)
                != "Salt") ++bad;
            if (rules::ucnUseful(11).school != 0)
                ++bad;
            if (rules::ucnUseful(11).areaKind != 0)
                ++bad;
            if (rules::ucnUseful(11).areaVal != 0)
                ++bad;
            if (std::string(rules::ucnUseful(12).name)
                != "Shine") ++bad;
            if (rules::ucnUseful(12).school != 2)
                ++bad;
            if (rules::ucnUseful(12).areaKind != 0)
                ++bad;
            if (rules::ucnUseful(12).areaVal != 0)
                ++bad;
            if (std::string(rules::ucnUseful(13).name)
                != "Spice") ++bad;
            if (rules::ucnUseful(13).school != 0)
                ++bad;
            if (rules::ucnUseful(13).areaKind != 0)
                ++bad;
            if (rules::ucnUseful(13).areaVal != 0)
                ++bad;
            if (std::string(rules::ucnUseful(14).name)
                != "Sprout") ++bad;
            if (rules::ucnUseful(14).school != 2)
                ++bad;
            if (rules::ucnUseful(14).areaKind != -1)
                ++bad;
            if (rules::ucnUseful(14).areaVal != 0)
                ++bad;
            if (std::string(rules::ucnUseful(15).name)
                != "Stitch") ++bad;
            if (rules::ucnUseful(15).school != 2)
                ++bad;
            if (rules::ucnUseful(15).areaKind != 3)
                ++bad;
            if (rules::ucnUseful(15).areaVal != 0)
                ++bad;
            if (std::string(rules::ucnUseful(16).name)
                != "Sweeten") ++bad;
            if (rules::ucnUseful(16).school != 0)
                ++bad;
            if (rules::ucnUseful(16).areaKind != 0)
                ++bad;
            if (rules::ucnUseful(16).areaVal != 0)
                ++bad;
            if (std::string(rules::ucnUseful(17).name)
                != "Tie") ++bad;
            if (rules::ucnUseful(17).school != 2)
                ++bad;
            if (rules::ucnUseful(17).areaKind != 0)
                ++bad;
            if (rules::ucnUseful(17).areaVal != 0)
                ++bad;
            if (std::string(rules::ucnUseful(18).name)
                != "Warm") ++bad;
            if (rules::ucnUseful(18).school != 0)
                ++bad;
            if (rules::ucnUseful(18).areaKind != 1)
                ++bad;
            if (rules::ucnUseful(18).areaVal != 1)
                ++bad;
            if (std::string(rules::ucnUseful(19).name)
                != "Wrap") ++bad;
            if (rules::ucnUseful(19).school != 2)
                ++bad;
            if (rules::ucnUseful(19).areaKind != 2)
                ++bad;
            if (rules::ucnUseful(19).areaVal != 1)
                ++bad;
            if (std::string(rules::ucrReversed(0).name)
                != "Curdle") ++bad;
            if (rules::ucrReversed(0).school != 3)
                ++bad;
            if (rules::ucrReversed(0).areaKind != 0)
                ++bad;
            if (rules::ucrReversed(0).areaVal != 0)
                ++bad;
            if (std::string(rules::ucrReversed(1).name)
                != "Dirty") ++bad;
            if (rules::ucrReversed(1).school != 0)
                ++bad;
            if (rules::ucrReversed(1).areaKind != 4)
                ++bad;
            if (rules::ucrReversed(1).areaVal != 4)
                ++bad;
            if (std::string(rules::ucrReversed(2).name)
                != "Dusty") ++bad;
            if (rules::ucrReversed(2).school != 0)
                ++bad;
            if (rules::ucrReversed(2).areaKind != 5)
                ++bad;
            if (rules::ucrReversed(2).areaVal != 10)
                ++bad;
            if (std::string(rules::ucrReversed(3).name)
                != "Hairy") ++bad;
            if (rules::ucrReversed(3).school != 2)
                ++bad;
            if (rules::ucrReversed(3).areaKind != 0)
                ++bad;
            if (rules::ucrReversed(3).areaVal != 0)
                ++bad;
            if (std::string(rules::ucrReversed(4).name)
                != "Knot") ++bad;
            if (rules::ucrReversed(4).school != 2)
                ++bad;
            if (rules::ucrReversed(4).areaKind != 0)
                ++bad;
            if (rules::ucrReversed(4).areaVal != 0)
                ++bad;
            if (std::string(rules::ucrReversed(5).name)
                != "Ravel") ++bad;
            if (rules::ucrReversed(5).school != 2)
                ++bad;
            if (rules::ucrReversed(5).areaKind != 3)
                ++bad;
            if (rules::ucrReversed(5).areaVal != 0)
                ++bad;
            if (std::string(rules::ucrReversed(6).name)
                != "Sour") ++bad;
            if (rules::ucrReversed(6).school != 0)
                ++bad;
            if (rules::ucrReversed(6).areaKind != 0)
                ++bad;
            if (rules::ucrReversed(6).areaVal != 0)
                ++bad;
            if (std::string(rules::ucrReversed(7).name)
                != "Spill") ++bad;
            if (rules::ucrReversed(7).school != 2)
                ++bad;
            if (rules::ucrReversed(7).areaKind != 6)
                ++bad;
            if (rules::ucrReversed(7).areaVal != 0)
                ++bad;
            if (std::string(rules::ucrReversed(8).name)
                != "Tangle") ++bad;
            if (rules::ucrReversed(8).school != 2)
                ++bad;
            if (rules::ucrReversed(8).areaKind != 0)
                ++bad;
            if (rules::ucrReversed(8).areaVal != 0)
                ++bad;
            if (std::string(rules::ucrReversed(9).name)
                != "Tarnish") ++bad;
            if (rules::ucrReversed(9).school != 2)
                ++bad;
            if (rules::ucrReversed(9).areaKind != 0)
                ++bad;
            if (rules::ucrReversed(9).areaVal != 0)
                ++bad;
            if (std::string(rules::ucrReversed(10).name)
                != "Untie") ++bad;
            if (rules::ucrReversed(10).school != 2)
                ++bad;
            if (rules::ucrReversed(10).areaKind != 0)
                ++bad;
            if (rules::ucrReversed(10).areaVal != 0)
                ++bad;
            if (std::string(rules::ucrReversed(11).name)
                != "Wilt") ++bad;
            if (rules::ucrReversed(11).school != 3)
                ++bad;
            if (rules::ucrReversed(11).areaKind != 0)
                ++bad;
            if (rules::ucrReversed(11).areaVal != 0)
                ++bad;
            if (std::string(rules::uclLegerdemain(0).name)
                != "Change") ++bad;
            if (rules::uclLegerdemain(0).school != 2)
                ++bad;
            if (rules::uclLegerdemain(0).areaKind != 0)
                ++bad;
            if (rules::uclLegerdemain(0).areaVal != 0)
                ++bad;
            if (std::string(rules::uclLegerdemain(1).name)
                != "Distract") ++bad;
            if (rules::uclLegerdemain(1).school != 3)
                ++bad;
            if (rules::uclLegerdemain(1).areaKind != 3)
                ++bad;
            if (rules::uclLegerdemain(1).areaVal != 0)
                ++bad;
            if (std::string(rules::uclLegerdemain(2).name)
                != "Hide") ++bad;
            if (rules::uclLegerdemain(2).school != 4)
                ++bad;
            if (rules::uclLegerdemain(2).areaKind != 0)
                ++bad;
            if (rules::uclLegerdemain(2).areaVal != 0)
                ++bad;
            if (std::string(rules::uclLegerdemain(3).name)
                != "Mute") ++bad;
            if (rules::uclLegerdemain(3).school != 2)
                ++bad;
            if (rules::uclLegerdemain(3).areaKind != 0)
                ++bad;
            if (rules::uclLegerdemain(3).areaVal != 0)
                ++bad;
            if (std::string(rules::uclLegerdemain(4).name)
                != "Palm") ++bad;
            if (rules::uclLegerdemain(4).school != 4)
                ++bad;
            if (rules::uclLegerdemain(4).areaKind != 7)
                ++bad;
            if (rules::uclLegerdemain(4).areaVal != 0)
                ++bad;
            if (std::string(rules::uclLegerdemain(5).name)
                != "Present") ++bad;
            if (rules::uclLegerdemain(5).school != 2)
                ++bad;
            if (rules::uclLegerdemain(5).areaKind != 7)
                ++bad;
            if (rules::uclLegerdemain(5).areaVal != 0)
                ++bad;
            if (std::string(rules::ucpPersonAffecting(0).name)
                != "Belch") ++bad;
            if (rules::ucpPersonAffecting(0).school != 0)
                ++bad;
            if (rules::ucpPersonAffecting(0).areaKind != 8)
                ++bad;
            if (rules::ucpPersonAffecting(0).areaVal != 0)
                ++bad;
            if (std::string(rules::ucpPersonAffecting(1).name)
                != "Blink") ++bad;
            if (rules::ucpPersonAffecting(1).school != 0)
                ++bad;
            if (rules::ucpPersonAffecting(1).areaKind != 8)
                ++bad;
            if (rules::ucpPersonAffecting(1).areaVal != 0)
                ++bad;
            if (std::string(rules::ucpPersonAffecting(2).name)
                != "Cough") ++bad;
            if (rules::ucpPersonAffecting(2).school != 0)
                ++bad;
            if (rules::ucpPersonAffecting(2).areaKind != 8)
                ++bad;
            if (rules::ucpPersonAffecting(2).areaVal != 0)
                ++bad;
            if (std::string(rules::ucpPersonAffecting(3).name)
                != "Giggle") ++bad;
            if (rules::ucpPersonAffecting(3).school != 5)
                ++bad;
            if (rules::ucpPersonAffecting(3).areaKind != 8)
                ++bad;
            if (rules::ucpPersonAffecting(3).areaVal != 0)
                ++bad;
            if (std::string(rules::ucpPersonAffecting(4).name)
                != "Nod") ++bad;
            if (rules::ucpPersonAffecting(4).school != 0)
                ++bad;
            if (rules::ucpPersonAffecting(4).areaKind != 8)
                ++bad;
            if (rules::ucpPersonAffecting(4).areaVal != 0)
                ++bad;
            if (std::string(rules::ucpPersonAffecting(5).name)
                != "Scratch") ++bad;
            if (rules::ucpPersonAffecting(5).school != 0)
                ++bad;
            if (rules::ucpPersonAffecting(5).areaKind != 9)
                ++bad;
            if (rules::ucpPersonAffecting(5).areaVal != 0)
                ++bad;
            if (std::string(rules::ucpPersonAffecting(6).name)
                != "Sneeze") ++bad;
            if (rules::ucpPersonAffecting(6).school != 0)
                ++bad;
            if (rules::ucpPersonAffecting(6).areaKind != 9)
                ++bad;
            if (rules::ucpPersonAffecting(6).areaVal != 0)
                ++bad;
            if (std::string(rules::ucpPersonAffecting(7).name)
                != "Twitch") ++bad;
            if (rules::ucpPersonAffecting(7).school != 0)
                ++bad;
            if (rules::ucpPersonAffecting(7).areaKind != 9)
                ++bad;
            if (rules::ucpPersonAffecting(7).areaVal != 0)
                ++bad;
            if (std::string(rules::ucpPersonAffecting(8).name)
                != "Wink") ++bad;
            if (rules::ucpPersonAffecting(8).school != 3)
                ++bad;
            if (rules::ucpPersonAffecting(8).areaKind != 8)
                ++bad;
            if (rules::ucpPersonAffecting(8).areaVal != 0)
                ++bad;
            if (std::string(rules::ucpPersonAffecting(9).name)
                != "Yawn") ++bad;
            if (rules::ucpPersonAffecting(9).school != 0)
                ++bad;
            if (rules::ucpPersonAffecting(9).areaKind != 9)
                ++bad;
            if (rules::ucpPersonAffecting(9).areaVal != 0)
                ++bad;
            if (std::string(rules::ucoPersonal(0).name)
                != "Bee") ++bad;
            if (rules::ucoPersonal(0).school != 6)
                ++bad;
            if (rules::ucoPersonal(0).areaKind != 10)
                ++bad;
            if (rules::ucoPersonal(0).areaVal != 0)
                ++bad;
            if (std::string(rules::ucoPersonal(1).name)
                != "Bluelight") ++bad;
            if (rules::ucoPersonal(1).school != 7)
                ++bad;
            if (rules::ucoPersonal(1).areaKind != 13)
                ++bad;
            if (rules::ucoPersonal(1).areaVal != 3)
                ++bad;
            if (std::string(rules::ucoPersonal(2).name)
                != "Bug") ++bad;
            if (rules::ucoPersonal(2).school != 6)
                ++bad;
            if (rules::ucoPersonal(2).areaKind != 10)
                ++bad;
            if (rules::ucoPersonal(2).areaVal != 0)
                ++bad;
            if (std::string(rules::ucoPersonal(3).name)
                != "Firefinger") ++bad;
            if (rules::ucoPersonal(3).school != 2)
                ++bad;
            if (rules::ucoPersonal(3).areaKind != 14)
                ++bad;
            if (rules::ucoPersonal(3).areaVal != 6)
                ++bad;
            if (std::string(rules::ucoPersonal(4).name)
                != "Gnats") ++bad;
            if (rules::ucoPersonal(4).school != 6)
                ++bad;
            if (rules::ucoPersonal(4).areaKind != 1)
                ++bad;
            if (rules::ucoPersonal(4).areaVal != 1)
                ++bad;
            if (std::string(rules::ucoPersonal(5).name)
                != "Mouse") ++bad;
            if (rules::ucoPersonal(5).school != 6)
                ++bad;
            if (rules::ucoPersonal(5).areaKind != 10)
                ++bad;
            if (rules::ucoPersonal(5).areaVal != 0)
                ++bad;
            if (std::string(rules::ucoPersonal(6).name)
                != "Smokepuff") ++bad;
            if (rules::ucoPersonal(6).school != 0)
                ++bad;
            if (rules::ucoPersonal(6).areaKind != 11)
                ++bad;
            if (rules::ucoPersonal(6).areaVal != 1)
                ++bad;
            if (std::string(rules::ucoPersonal(7).name)
                != "Spider") ++bad;
            if (rules::ucoPersonal(7).school != 6)
                ++bad;
            if (rules::ucoPersonal(7).areaKind != 10)
                ++bad;
            if (rules::ucoPersonal(7).areaVal != 0)
                ++bad;
            if (std::string(rules::ucoPersonal(8).name)
                != "Tweak") ++bad;
            if (rules::ucoPersonal(8).school != 7)
                ++bad;
            if (rules::ucoPersonal(8).areaKind != 9)
                ++bad;
            if (rules::ucoPersonal(8).areaVal != 0)
                ++bad;
            if (std::string(rules::ucoPersonal(9).name)
                != "Unlock") ++bad;
            if (rules::ucoPersonal(9).school != 7)
                ++bad;
            if (rules::ucoPersonal(9).areaKind != 12)
                ++bad;
            if (rules::ucoPersonal(9).areaVal != 0)
                ++bad;
            if (std::string(rules::uchHauntingSound(0).name)
                != "Creak") ++bad;
            if (rules::uchHauntingSound(0).school != 0)
                ++bad;
            if (rules::uchHauntingSound(0).areaKind != 3)
                ++bad;
            if (rules::uchHauntingSound(0).areaVal != 0)
                ++bad;
            if (std::string(rules::uchHauntingSound(1).name)
                != "Footfall") ++bad;
            if (rules::uchHauntingSound(1).school != 4)
                ++bad;
            if (rules::uchHauntingSound(1).areaKind != 3)
                ++bad;
            if (rules::uchHauntingSound(1).areaVal != 0)
                ++bad;
            if (std::string(rules::uchHauntingSound(2).name)
                != "Groan") ++bad;
            if (rules::uchHauntingSound(2).school != 4)
                ++bad;
            if (rules::uchHauntingSound(2).areaKind != 3)
                ++bad;
            if (rules::uchHauntingSound(2).areaVal != 0)
                ++bad;
            if (std::string(rules::uchHauntingSound(3).name)
                != "Moan") ++bad;
            if (rules::uchHauntingSound(3).school != 4)
                ++bad;
            if (rules::uchHauntingSound(3).areaKind != 3)
                ++bad;
            if (rules::uchHauntingSound(3).areaVal != 0)
                ++bad;
            if (std::string(rules::uchHauntingSound(4).name)
                != "Rattle") ++bad;
            if (rules::uchHauntingSound(4).school != 4)
                ++bad;
            if (rules::uchHauntingSound(4).areaKind != 3)
                ++bad;
            if (rules::uchHauntingSound(4).areaVal != 0)
                ++bad;
            if (std::string(rules::uchHauntingSound(5).name)
                != "Tap") ++bad;
            if (rules::uchHauntingSound(5).school != 0)
                ++bad;
            if (rules::uchHauntingSound(5).areaKind != 13)
                ++bad;
            if (rules::uchHauntingSound(5).areaVal != 1)
                ++bad;
            if (std::string(rules::uchHauntingSound(6).name)
                != "Thump") ++bad;
            if (rules::uchHauntingSound(6).school != 4)
                ++bad;
            if (rules::uchHauntingSound(6).areaKind != 3)
                ++bad;
            if (rules::uchHauntingSound(6).areaVal != 0)
                ++bad;
            if (std::string(rules::uchHauntingSound(7).name)
                != "Whistle") ++bad;
            if (rules::uchHauntingSound(7).school != 0)
                ++bad;
            if (rules::uchHauntingSound(7).areaKind != 3)
                ++bad;
            if (rules::uchHauntingSound(7).areaVal != 0)
                ++bad;
        }
        printf("R1057 uaspells registry edges audit: bad %d\n", bad);
    }
