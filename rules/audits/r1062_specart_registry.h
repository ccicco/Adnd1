    // ==== R1062: special-artifact registry =========
    // The R1062 de-wire: the 54 retiring static
    // arrays of rules/dmg/specart.h (5) and
    // rules/dmg/specart_prose_part2.h (49) ride
    // items::MiscItemRegistry from
    // content/tables/specart/ - 2 rowless defs,
    // 54 tables, one pin per def; the 499 KEPT
    // zero-arg scalars stay C++, probed at the
    // edges here (the r280-r29x pin fragments keep
    // their value-level pins untouched). Eight
    // sections: load, counts, defs-A/B/C/D, seam,
    // edges. Census 1135 -> 1143. DO NOT hand-edit:
    // tools/r1062_splice.py is the only writer.
    {
        int bad = 0;
        // -- 1. load ------------------------------
        {
            items::MiscItemRegistry reg;
            int n = reg.loadDirectory(
                "content/tables/specart");
            if (n != 2) ++bad;
            if (!reg.errors().empty()) ++bad;
            for (const auto& kv : reg.all())
                if ((int)kv.second.sources.size() != 1
                    || kv.second.sources[0].first != 0
                    || kv.second.sources[0].second != 1062)
                    ++bad;
            if (!reg.find("specart")) ++bad;
            if (!reg.find("specart_prose")) ++bad;
        }
        printf("R1062 specart registry load audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 2. counts ----------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/specart");
            {
                const items::MiscItemDef* d =
                    reg.find("specart");
                if (!d) { ++bad; } else {
                    if ((int)d->pins.size() != 1
                        || d->pins[0].name
                            != "specartTableCount"
                        || d->pins[0].value != 5)
                        ++bad;
                    if ((int)d->tables.size() != 5) ++bad;
                    if (d->tables[0].name
                        != "row_lo"
                        || (int)d->tables[0]
                            .values.size() != 29)
                        ++bad;
                    if (d->tables[1].name
                        != "row_hi"
                        || (int)d->tables[1]
                            .values.size() != 29)
                        ++bad;
                    if (d->tables[2].name
                        != "sale_gp"
                        || (int)d->tables[2]
                            .values.size() != 29)
                        ++bad;
                    if (d->tables[3].name
                        != "sale_gp_hi"
                        || (int)d->tables[3]
                            .values.size() != 29)
                        ++bad;
                    if (d->tables[4].name
                        != "xp_value"
                        || (int)d->tables[4]
                            .values.size() != 29)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("specart_prose");
                if (!d) { ++bad; } else {
                    if ((int)d->pins.size() != 1
                        || d->pins[0].name
                            != "specart_proseTableCount"
                        || d->pins[0].value != 49)
                        ++bad;
                    if ((int)d->tables.size() != 49) ++bad;
                    if (d->tables[0].name
                        != "axe_power_count"
                        || (int)d->tables[0]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[1].name
                        != "hut_move_inches"
                        || (int)d->tables[1]
                            .values.size() != 3)
                        ++bad;
                    if (d->tables[2].name
                        != "hut_power_count"
                        || (int)d->tables[2]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[3].name
                        != "codex_power_count"
                        || (int)d->tables[3]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[4].name
                        != "crown_align_band_lo"
                        || (int)d->tables[4]
                            .values.size() != 3)
                        ++bad;
                    if (d->tables[5].name
                        != "crown_align_band_hi"
                        || (int)d->tables[5]
                            .values.size() != 3)
                        ++bad;
                    if (d->tables[6].name
                        != "crown_worn_power_count"
                        || (int)d->tables[6]
                            .values.size() != 3)
                        ++bad;
                    if (d->tables[7].name
                        != "crown_set2nd_power_count"
                        || (int)d->tables[7]
                            .values.size() != 2)
                        ++bad;
                    if (d->tables[8].name
                        != "crown_set3rd_power_count"
                        || (int)d->tables[8]
                            .values.size() != 5)
                        ++bad;
                    if (d->tables[9].name
                        != "crystal_power_count"
                        || (int)d->tables[9]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[10].name
                        != "cup_power_count"
                        || (int)d->tables[10]
                            .values.size() != 3)
                        ++bad;
                    if (d->tables[11].name
                        != "talisman_power_count"
                        || (int)d->tables[11]
                            .values.size() != 4)
                        ++bad;
                    if (d->tables[12].name
                        != "cup_talisman_both_power_count"
                        || (int)d->tables[12]
                            .values.size() != 2)
                        ++bad;
                    if (d->tables[13].name
                        != "cup_talisman_potion_band_lo"
                        || (int)d->tables[13]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[14].name
                        != "cup_talisman_potion_band_hi"
                        || (int)d->tables[14]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[15].name
                        != "eye_power_count"
                        || (int)d->tables[15]
                            .values.size() != 5)
                        ++bad;
                    if (d->tables[16].name
                        != "hand_power_count"
                        || (int)d->tables[16]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[17].name
                        != "organ_power_count"
                        || (int)d->tables[17]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[18].name
                        != "horn_blast_power_table"
                        || (int)d->tables[18]
                            .values.size() != 3)
                        ++bad;
                    if (d->tables[19].name
                        != "horn_blast_effect_table"
                        || (int)d->tables[19]
                            .values.size() != 3)
                        ++bad;
                    if (d->tables[20].name
                        != "coat_power_count"
                        || (int)d->tables[20]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[21].name
                        != "flask_power_count"
                        || (int)d->tables[21]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[22].name
                        != "jacinth_power_count"
                        || (int)d->tables[22]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[23].name
                        != "mask_power_count"
                        || (int)d->tables[23]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[24].name
                        != "quill_power_count"
                        || (int)d->tables[24]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[25].name
                        != "mace_power_count"
                        || (int)d->tables[25]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[26].name
                        != "machine_power_count"
                        || (int)d->tables[26]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[27].name
                        != "servant_power_count"
                        || (int)d->tables[27]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[28].name
                        != "orb_hatchling_power_count"
                        || (int)d->tables[28]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[29].name
                        != "orb_wyrmkin_power_count"
                        || (int)d->tables[29]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[30].name
                        != "orb_dragonette_power_count"
                        || (int)d->tables[30]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[31].name
                        != "orb_dragon_power_count"
                        || (int)d->tables[31]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[32].name
                        != "orb_great_serpent_power_count"
                        || (int)d->tables[32]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[33].name
                        != "orb_firedrake_power_count"
                        || (int)d->tables[33]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[34].name
                        != "orb_elder_wyrm_power_count"
                        || (int)d->tables[34]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[35].name
                        != "orb_eternal_power_count"
                        || (int)d->tables[35]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[36].name
                        != "orb_might_power_count"
                        || (int)d->tables[36]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[37].name
                        != "nightingale_power_count"
                        || (int)d->tables[37]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[38].name
                        != "recorder_power_count"
                        || (int)d->tables[38]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[39].name
                        != "gaxx_power_count"
                        || (int)d->tables[39]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[40].name
                        != "rod_joint_table"
                        || (int)d->tables[40]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[41].name
                        != "rod_joint_use_count"
                        || (int)d->tables[41]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[42].name
                        != "rod_complete_table_use"
                        || (int)d->tables[42]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[43].name
                        != "sceptre_table_use"
                        || (int)d->tables[43]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[44].name
                        != "kas_table_use"
                        || (int)d->tables[44]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[45].name
                        != "tooth_table_use"
                        || (int)d->tables[45]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[46].name
                        != "tooth_set_right_use"
                        || (int)d->tables[46]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[47].name
                        != "throne_table_use"
                        || (int)d->tables[47]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[48].name
                        != "wand_table_use"
                        || (int)d->tables[48]
                            .values.size() != 6)
                        ++bad;
                }
            }
        }
        printf("R1062 specart registry counts audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 3. defs-A: the band columns ----------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/specart");
            const items::MiscItemDef* d =
                reg.find("specart");
            if (!d) { ++bad; } else {
                // saRowLo (row_lo)
            static const int ksaRowLo[29] = {
                1, 2, 3, 5, 21, 22, 23, 25, 26, 27,
                28, 30, 32, 33, 34, 36, 38, 39, 41, 48,
                64, 65, 67, 69, 75, 92, 93, 99, 100,
            };
                if (d->tables[0].name
                    != "row_lo") ++bad;
                else for (int i = 0; i < 29; ++i)
                    if ((int)d->tables[0]
                            .values[i] != ksaRowLo[i])
                        ++bad;
                // saRowHi (row_hi)
            static const int ksaRowHi[29] = {
                1, 2, 4, 20, 21, 22, 24, 25, 26, 27,
                29, 31, 32, 33, 35, 37, 38, 40, 47, 63,
                64, 66, 68, 74, 91, 92, 98, 99, 100,
            };
                if (d->tables[1].name
                    != "row_hi") ++bad;
                else for (int i = 0; i < 29; ++i)
                    if ((int)d->tables[1]
                            .values[i] != ksaRowHi[i])
                        ++bad;
                // saSaleGp (sale_gp)
            static const int ksaSaleGp[29] = {
                55000, 90000, 62500, 50000, 75000, 85000, 35000, 60000, 25000, 20000,
                47500, 50000, 100000, 40000, 27500, 35000, 72500, 185000, 10000, 100000,
                112500, 80000, 17500, 25000, 150000, 97000, 5000, 0, 10000,
            };
                if (d->tables[2].name
                    != "sale_gp") ++bad;
                else for (int i = 0; i < 29; ++i)
                    if ((int)d->tables[2]
                            .values[i] != ksaSaleGp[i])
                        ++bad;
                // saSaleGpHi (sale_gp_hi)
            static const int ksaSaleGpHi[29] = {
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 80000, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0,
            };
                if (d->tables[3].name
                    != "sale_gp_hi") ++bad;
                else for (int i = 0; i < 29; ++i)
                    if ((int)d->tables[3]
                            .values[i] != ksaSaleGpHi[i])
                        ++bad;
                // saXpValue (xp_value)
            static const int ksaXpValue[29] = {
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0, 0,
            };
                if (d->tables[4].name
                    != "xp_value") ++bad;
                else for (int i = 0; i < 29; ++i)
                    if ((int)d->tables[4]
                            .values[i] != ksaXpValue[i])
                        ++bad;
            }
        }
        printf("R1062 specart registry defs-A audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 4. defs-B: prose columns 1-25 -
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/specart");
            const items::MiscItemDef* d =
                reg.find("specart_prose");
            if (!d) { ++bad; } else {
                // sapAxePowerCount (axe_power_count)
            static const int ksapAxePowerCount[6] = {
                2, 1, 1, 1, 1, 1,
            };
                if (d->tables[0].name
                    != "axe_power_count") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[0]
                            .values[i] != ksapAxePowerCount[i])
                        ++bad;
                // sapHutMoveInches (hut_move_inches)
            static const int ksapHutMoveInches[3] = {
                48, 36, 12,
            };
                if (d->tables[1].name
                    != "hut_move_inches") ++bad;
                else for (int i = 0; i < 3; ++i)
                    if ((int)d->tables[1]
                            .values[i] != ksapHutMoveInches[i])
                        ++bad;
                // sapHutPowerCount (hut_power_count)
            static const int ksapHutPowerCount[6] = {
                4, 2, 1, 1, 1, 1,
            };
                if (d->tables[2].name
                    != "hut_power_count") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[2]
                            .values[i] != ksapHutPowerCount[i])
                        ++bad;
                // sapCodexPowerCount (codex_power_count)
            static const int ksapCodexPowerCount[6] = {
                4, 4, 2, 2, 2, 2,
            };
                if (d->tables[3].name
                    != "codex_power_count") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[3]
                            .values[i] != ksapCodexPowerCount[i])
                        ++bad;
                // sapCrownAlignBandLo (crown_align_band_lo)
            static const int ksapCrownAlignBandLo[3] = {
                1, 7, 15,
            };
                if (d->tables[4].name
                    != "crown_align_band_lo") ++bad;
                else for (int i = 0; i < 3; ++i)
                    if ((int)d->tables[4]
                            .values[i] != ksapCrownAlignBandLo[i])
                        ++bad;
                // sapCrownAlignBandHi (crown_align_band_hi)
            static const int ksapCrownAlignBandHi[3] = {
                6, 14, 20,
            };
                if (d->tables[5].name
                    != "crown_align_band_hi") ++bad;
                else for (int i = 0; i < 3; ++i)
                    if ((int)d->tables[5]
                            .values[i] != ksapCrownAlignBandHi[i])
                        ++bad;
                // sapCrownWornPowerCount (crown_worn_power_count)
            static const int ksapCrownWornPowerCount[3] = {
                2, 1, 1,
            };
                if (d->tables[6].name
                    != "crown_worn_power_count") ++bad;
                else for (int i = 0; i < 3; ++i)
                    if ((int)d->tables[6]
                            .values[i] != ksapCrownWornPowerCount[i])
                        ++bad;
                // sapCrownSet2ndPowerCount (crown_set2nd_power_count)
            static const int ksapCrownSet2ndPowerCount[2] = {
                1, 1,
            };
                if (d->tables[7].name
                    != "crown_set2nd_power_count") ++bad;
                else for (int i = 0; i < 2; ++i)
                    if ((int)d->tables[7]
                            .values[i] != ksapCrownSet2ndPowerCount[i])
                        ++bad;
                // sapCrownSet3rdPowerCount (crown_set3rd_power_count)
            static const int ksapCrownSet3rdPowerCount[5] = {
                1, 1, 1, 1, 1,
            };
                if (d->tables[8].name
                    != "crown_set3rd_power_count") ++bad;
                else for (int i = 0; i < 5; ++i)
                    if ((int)d->tables[8]
                            .values[i] != ksapCrownSet3rdPowerCount[i])
                        ++bad;
                // sapCrystalPowerCount (crystal_power_count)
            static const int ksapCrystalPowerCount[6] = {
                4, 2, 1, 1, 1, 1,
            };
                if (d->tables[9].name
                    != "crystal_power_count") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[9]
                            .values[i] != ksapCrystalPowerCount[i])
                        ++bad;
                // sapCupPowerCount (cup_power_count)
            static const int ksapCupPowerCount[3] = {
                4, 0, 1,
            };
                if (d->tables[10].name
                    != "cup_power_count") ++bad;
                else for (int i = 0; i < 3; ++i)
                    if ((int)d->tables[10]
                            .values[i] != ksapCupPowerCount[i])
                        ++bad;
                // sapTalismanPowerCount (talisman_power_count)
            static const int ksapTalismanPowerCount[4] = {
                0, 2, 0, 1,
            };
                if (d->tables[11].name
                    != "talisman_power_count") ++bad;
                else for (int i = 0; i < 4; ++i)
                    if ((int)d->tables[11]
                            .values[i] != ksapTalismanPowerCount[i])
                        ++bad;
                // sapCupTalismanBothPowerCount (cup_talisman_both_power_count)
            static const int ksapCupTalismanBothPowerCount[2] = {
                1, 1,
            };
                if (d->tables[12].name
                    != "cup_talisman_both_power_count") ++bad;
                else for (int i = 0; i < 2; ++i)
                    if ((int)d->tables[12]
                            .values[i] != ksapCupTalismanBothPowerCount[i])
                        ++bad;
                // sapCupTalismanPotionBandLo (cup_talisman_potion_band_lo)
            static const int ksapCupTalismanPotionBandLo[6] = {
                1, 6, 11, 16, 18, 20,
            };
                if (d->tables[13].name
                    != "cup_talisman_potion_band_lo") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[13]
                            .values[i] != ksapCupTalismanPotionBandLo[i])
                        ++bad;
                // sapCupTalismanPotionBandHi (cup_talisman_potion_band_hi)
            static const int ksapCupTalismanPotionBandHi[6] = {
                5, 10, 15, 17, 19, 20,
            };
                if (d->tables[14].name
                    != "cup_talisman_potion_band_hi") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[14]
                            .values[i] != ksapCupTalismanPotionBandHi[i])
                        ++bad;
                // sapEyePowerCount (eye_power_count)
            static const int ksapEyePowerCount[5] = {
                2, 2, 0, 1, 1,
            };
                if (d->tables[15].name
                    != "eye_power_count") ++bad;
                else for (int i = 0; i < 5; ++i)
                    if ((int)d->tables[15]
                            .values[i] != ksapEyePowerCount[i])
                        ++bad;
                // sapHandPowerCount (hand_power_count)
            static const int ksapHandPowerCount[6] = {
                10, 5, 2, 2, 2, 1,
            };
                if (d->tables[16].name
                    != "hand_power_count") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[16]
                            .values[i] != ksapHandPowerCount[i])
                        ++bad;
                // sapOrganPowerCount (organ_power_count)
            static const int ksapOrganPowerCount[6] = {
                7, 7, 3, 7, 7, 3,
            };
                if (d->tables[17].name
                    != "organ_power_count") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[17]
                            .values[i] != ksapOrganPowerCount[i])
                        ++bad;
                // sapHornBlastPowerTable (horn_blast_power_table)
            static const int ksapHornBlastPowerTable[3] = {
                1, 2, 5,
            };
                if (d->tables[18].name
                    != "horn_blast_power_table") ++bad;
                else for (int i = 0; i < 3; ++i)
                    if ((int)d->tables[18]
                            .values[i] != ksapHornBlastPowerTable[i])
                        ++bad;
                // sapHornBlastEffectTable (horn_blast_effect_table)
            static const int ksapHornBlastEffectTable[3] = {
                3, 6, 4,
            };
                if (d->tables[19].name
                    != "horn_blast_effect_table") ++bad;
                else for (int i = 0; i < 3; ++i)
                    if ((int)d->tables[19]
                            .values[i] != ksapHornBlastEffectTable[i])
                        ++bad;
                // sapCoatPowerCount (coat_power_count)
            static const int ksapCoatPowerCount[6] = {
                3, 2, 2, 1, 1, 1,
            };
                if (d->tables[20].name
                    != "coat_power_count") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[20]
                            .values[i] != ksapCoatPowerCount[i])
                        ++bad;
                // sapFlaskPowerCount (flask_power_count)
            static const int ksapFlaskPowerCount[6] = {
                3, 0, 1, 0, 1, 1,
            };
                if (d->tables[21].name
                    != "flask_power_count") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[21]
                            .values[i] != ksapFlaskPowerCount[i])
                        ++bad;
                // sapJacinthPowerCount (jacinth_power_count)
            static const int ksapJacinthPowerCount[6] = {
                2, 2, 1, 1, 1, 1,
            };
                if (d->tables[22].name
                    != "jacinth_power_count") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[22]
                            .values[i] != ksapJacinthPowerCount[i])
                        ++bad;
                // sapMaskPowerCount (mask_power_count)
            static const int ksapMaskPowerCount[6] = {
                2, 1, 0, 0, 0, 1,
            };
                if (d->tables[23].name
                    != "mask_power_count") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[23]
                            .values[i] != ksapMaskPowerCount[i])
                        ++bad;
                // sapQuillPowerCount (quill_power_count)
            static const int ksapQuillPowerCount[6] = {
                2, 0, 1, 1, 0, 1,
            };
                if (d->tables[24].name
                    != "quill_power_count") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[24]
                            .values[i] != ksapQuillPowerCount[i])
                        ++bad;
            }
        }
        printf("R1062 specart registry defs-B audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 5. defs-C: prose columns 26-49 -
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/specart");
            const items::MiscItemDef* d =
                reg.find("specart_prose");
            if (!d) { ++bad; } else {
                // sapMacePowerCount (mace_power_count)
            static const int ksapMacePowerCount[6] = {
                3, 2, 0, 0, 0, 1,
            };
                if (d->tables[25].name
                    != "mace_power_count") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[25]
                            .values[i] != ksapMacePowerCount[i])
                        ++bad;
                // sapMachinePowerCount (machine_power_count)
            static const int ksapMachinePowerCount[6] = {
                15, 15, 10, 10, 15, 5,
            };
                if (d->tables[26].name
                    != "machine_power_count") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[26]
                            .values[i] != ksapMachinePowerCount[i])
                        ++bad;
                // sapServantPowerCount (servant_power_count)
            static const int ksapServantPowerCount[6] = {
                6, 6, 1, 2, 0, 2,
            };
                if (d->tables[27].name
                    != "servant_power_count") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[27]
                            .values[i] != ksapServantPowerCount[i])
                        ++bad;
                // sapOrbHatchlingPowerCount (orb_hatchling_power_count)
            static const int ksapOrbHatchlingPowerCount[6] = {
                3, 0, 0, 0, 0, 0,
            };
                if (d->tables[28].name
                    != "orb_hatchling_power_count") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[28]
                            .values[i] != ksapOrbHatchlingPowerCount[i])
                        ++bad;
                // sapOrbWyrmkinPowerCount (orb_wyrmkin_power_count)
            static const int ksapOrbWyrmkinPowerCount[6] = {
                2, 1, 0, 0, 0, 0,
            };
                if (d->tables[29].name
                    != "orb_wyrmkin_power_count") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[29]
                            .values[i] != ksapOrbWyrmkinPowerCount[i])
                        ++bad;
                // sapOrbDragonettePowerCount (orb_dragonette_power_count)
            static const int ksapOrbDragonettePowerCount[6] = {
                3, 1, 1, 0, 0, 0,
            };
                if (d->tables[30].name
                    != "orb_dragonette_power_count") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[30]
                            .values[i] != ksapOrbDragonettePowerCount[i])
                        ++bad;
                // sapOrbDragonPowerCount (orb_dragon_power_count)
            static const int ksapOrbDragonPowerCount[6] = {
                4, 1, 1, 0, 0, 0,
            };
                if (d->tables[31].name
                    != "orb_dragon_power_count") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[31]
                            .values[i] != ksapOrbDragonPowerCount[i])
                        ++bad;
                // sapOrbGreatSerpentPowerCount (orb_great_serpent_power_count)
            static const int ksapOrbGreatSerpentPowerCount[6] = {
                3, 2, 1, 0, 0, 1,
            };
                if (d->tables[32].name
                    != "orb_great_serpent_power_count") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[32]
                            .values[i] != ksapOrbGreatSerpentPowerCount[i])
                        ++bad;
                // sapOrbFiredrakePowerCount (orb_firedrake_power_count)
            static const int ksapOrbFiredrakePowerCount[6] = {
                3, 3, 2, 0, 0, 1,
            };
                if (d->tables[33].name
                    != "orb_firedrake_power_count") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[33]
                            .values[i] != ksapOrbFiredrakePowerCount[i])
                        ++bad;
                // sapOrbElderWyrmPowerCount (orb_elder_wyrm_power_count)
            static const int ksapOrbElderWyrmPowerCount[6] = {
                4, 3, 2, 1, 1, 1,
            };
                if (d->tables[34].name
                    != "orb_elder_wyrm_power_count") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[34]
                            .values[i] != ksapOrbElderWyrmPowerCount[i])
                        ++bad;
                // sapOrbEternalPowerCount (orb_eternal_power_count)
            static const int ksapOrbEternalPowerCount[6] = {
                4, 3, 2, 1, 2, 1,
            };
                if (d->tables[35].name
                    != "orb_eternal_power_count") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[35]
                            .values[i] != ksapOrbEternalPowerCount[i])
                        ++bad;
                // sapOrbMightPowerCount (orb_might_power_count)
            static const int ksapOrbMightPowerCount[6] = {
                2, 0, 1, 0, 0, 0,
            };
                if (d->tables[36].name
                    != "orb_might_power_count") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[36]
                            .values[i] != ksapOrbMightPowerCount[i])
                        ++bad;
                // sapNightingalePowerCount (nightingale_power_count)
            static const int ksapNightingalePowerCount[6] = {
                4, 0, 1, 1, 1, 1,
            };
                if (d->tables[37].name
                    != "nightingale_power_count") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[37]
                            .values[i] != ksapNightingalePowerCount[i])
                        ++bad;
                // sapRecorderPowerCount (recorder_power_count)
            static const int ksapRecorderPowerCount[6] = {
                5, 2, 1, 1, 1, 1,
            };
                if (d->tables[38].name
                    != "recorder_power_count") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[38]
                            .values[i] != ksapRecorderPowerCount[i])
                        ++bad;
                // sapGaxxPowerCount (gaxx_power_count)
            static const int ksapGaxxPowerCount[6] = {
                3, 2, 1, 1, 1, 1,
            };
                if (d->tables[39].name
                    != "gaxx_power_count") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[39]
                            .values[i] != ksapGaxxPowerCount[i])
                        ++bad;
                // sapRodJointTable (rod_joint_table)
            static const int ksapRodJointTable[6] = {
                3, 1, 1, 4, 2, 6,
            };
                if (d->tables[40].name
                    != "rod_joint_table") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[40]
                            .values[i] != ksapRodJointTable[i])
                        ++bad;
                // sapRodJointUseCount (rod_joint_use_count)
            static const int ksapRodJointUseCount[6] = {
                1, 1, 1, 1, 1, 1,
            };
                if (d->tables[41].name
                    != "rod_joint_use_count") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[41]
                            .values[i] != ksapRodJointUseCount[i])
                        ++bad;
                // sapRodCompleteTableUse (rod_complete_table_use)
            static const int ksapRodCompleteTableUse[6] = {
                1, 1, 2, 1, 2, 0,
            };
                if (d->tables[42].name
                    != "rod_complete_table_use") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[42]
                            .values[i] != ksapRodCompleteTableUse[i])
                        ++bad;
                // sapSceptreTableUse (sceptre_table_use)
            static const int ksapSceptreTableUse[6] = {
                1, 1, 0, 0, 0, 1,
            };
                if (d->tables[43].name
                    != "sceptre_table_use") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[43]
                            .values[i] != ksapSceptreTableUse[i])
                        ++bad;
                // sapKasTableUse (kas_table_use)
            static const int ksapKasTableUse[6] = {
                5, 2, 1, 2, 2, 1,
            };
                if (d->tables[44].name
                    != "kas_table_use") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[44]
                            .values[i] != ksapKasTableUse[i])
                        ++bad;
                // sapToothTableUse (tooth_table_use)
            static const int ksapToothTableUse[6] = {
                21, 4, 4, 1, 0, 2,
            };
                if (d->tables[45].name
                    != "tooth_table_use") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[45]
                            .values[i] != ksapToothTableUse[i])
                        ++bad;
                // sapToothSetRightUse (tooth_set_right_use)
            static const int ksapToothSetRightUse[6] = {
                0, 0, 4, 2, 0, 2,
            };
                if (d->tables[46].name
                    != "tooth_set_right_use") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[46]
                            .values[i] != ksapToothSetRightUse[i])
                        ++bad;
                // sapThroneTableUse (throne_table_use)
            static const int ksapThroneTableUse[6] = {
                3, 3, 2, 2, 2, 2,
            };
                if (d->tables[47].name
                    != "throne_table_use") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[47]
                            .values[i] != ksapThroneTableUse[i])
                        ++bad;
                // sapWandTableUse (wand_table_use)
            static const int ksapWandTableUse[6] = {
                4, 2, 2, 1, 0, 1,
            };
                if (d->tables[48].name
                    != "wand_table_use") ++bad;
                else for (int i = 0; i < 6; ++i)
                    if ((int)d->tables[48]
                            .values[i] != ksapWandTableUse[i])
                        ++bad;
            }
        }
        printf("R1062 specart registry defs-C audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 6. defs-D: accessor parity sweep -----
        // every accessor, every index, against the
        // registry seam (the r280-r29x callers stay
        // byte-identical; this label carries the
        // parity they used to carry)
        {
            {
                const auto* g = rules::saTable(
                    "specart", "row_lo");
                if (!g) { ++bad; }
                else for (int i = 0; i < 29; ++i)
                    if (rules::saRowLo(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart", "row_hi");
                if (!g) { ++bad; }
                else for (int i = 0; i < 29; ++i)
                    if (rules::saRowHi(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart", "sale_gp");
                if (!g) { ++bad; }
                else for (int i = 0; i < 29; ++i)
                    if (rules::saSaleGp(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart", "sale_gp_hi");
                if (!g) { ++bad; }
                else for (int i = 0; i < 29; ++i)
                    if (rules::saSaleGpHi(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart", "xp_value");
                if (!g) { ++bad; }
                else for (int i = 0; i < 29; ++i)
                    if (rules::saXpValue(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "axe_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapAxePowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "hut_move_inches");
                if (!g) { ++bad; }
                else for (int i = 0; i < 3; ++i)
                    if (rules::sapHutMoveInches(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "hut_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapHutPowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "codex_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapCodexPowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "crown_align_band_lo");
                if (!g) { ++bad; }
                else for (int i = 0; i < 3; ++i)
                    if (rules::sapCrownAlignBandLo(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "crown_align_band_hi");
                if (!g) { ++bad; }
                else for (int i = 0; i < 3; ++i)
                    if (rules::sapCrownAlignBandHi(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "crown_worn_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 3; ++i)
                    if (rules::sapCrownWornPowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "crown_set2nd_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 2; ++i)
                    if (rules::sapCrownSet2ndPowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "crown_set3rd_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 5; ++i)
                    if (rules::sapCrownSet3rdPowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "crystal_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapCrystalPowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "cup_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 3; ++i)
                    if (rules::sapCupPowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "talisman_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 4; ++i)
                    if (rules::sapTalismanPowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "cup_talisman_both_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 2; ++i)
                    if (rules::sapCupTalismanBothPowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "cup_talisman_potion_band_lo");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapCupTalismanPotionBandLo(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "cup_talisman_potion_band_hi");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapCupTalismanPotionBandHi(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "eye_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 5; ++i)
                    if (rules::sapEyePowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "hand_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapHandPowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "organ_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapOrganPowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "horn_blast_power_table");
                if (!g) { ++bad; }
                else for (int i = 0; i < 3; ++i)
                    if (rules::sapHornBlastPowerTable(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "horn_blast_effect_table");
                if (!g) { ++bad; }
                else for (int i = 0; i < 3; ++i)
                    if (rules::sapHornBlastEffectTable(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "coat_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapCoatPowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "flask_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapFlaskPowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "jacinth_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapJacinthPowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "mask_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapMaskPowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "quill_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapQuillPowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "mace_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapMacePowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "machine_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapMachinePowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "servant_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapServantPowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "orb_hatchling_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapOrbHatchlingPowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "orb_wyrmkin_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapOrbWyrmkinPowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "orb_dragonette_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapOrbDragonettePowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "orb_dragon_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapOrbDragonPowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "orb_great_serpent_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapOrbGreatSerpentPowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "orb_firedrake_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapOrbFiredrakePowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "orb_elder_wyrm_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapOrbElderWyrmPowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "orb_eternal_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapOrbEternalPowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "orb_might_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapOrbMightPowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "nightingale_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapNightingalePowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "recorder_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapRecorderPowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "gaxx_power_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapGaxxPowerCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "rod_joint_table");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapRodJointTable(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "rod_joint_use_count");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapRodJointUseCount(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "rod_complete_table_use");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapRodCompleteTableUse(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "sceptre_table_use");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapSceptreTableUse(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "kas_table_use");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapKasTableUse(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "tooth_table_use");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapToothTableUse(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "tooth_set_right_use");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapToothSetRightUse(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "throne_table_use");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapThroneTableUse(i)
                        != (int)(*g)[i]) ++bad;
            }
            {
                const auto* g = rules::saTable(
                    "specart_prose", "wand_table_use");
                if (!g) { ++bad; }
                else for (int i = 0; i < 6; ++i)
                    if (rules::sapWandTableUse(i)
                        != (int)(*g)[i]) ++bad;
            }
        }
        printf("R1062 specart registry defs-D audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 7. seam -------------------------------
        // all 54 (key, tag) pairs resolve; wrong tag
        // and wrong key read null; two calls share
        // the cached table (stability)
        {
            if (!rules::saTable("specart", "row_lo")) ++bad;
            if (!rules::saTable("specart", "row_hi")) ++bad;
            if (!rules::saTable("specart", "sale_gp")) ++bad;
            if (!rules::saTable("specart", "sale_gp_hi")) ++bad;
            if (!rules::saTable("specart", "xp_value")) ++bad;
            if (!rules::saTable("specart_prose", "axe_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "hut_move_inches")) ++bad;
            if (!rules::saTable("specart_prose", "hut_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "codex_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "crown_align_band_lo")) ++bad;
            if (!rules::saTable("specart_prose", "crown_align_band_hi")) ++bad;
            if (!rules::saTable("specart_prose", "crown_worn_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "crown_set2nd_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "crown_set3rd_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "crystal_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "cup_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "talisman_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "cup_talisman_both_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "cup_talisman_potion_band_lo")) ++bad;
            if (!rules::saTable("specart_prose", "cup_talisman_potion_band_hi")) ++bad;
            if (!rules::saTable("specart_prose", "eye_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "hand_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "organ_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "horn_blast_power_table")) ++bad;
            if (!rules::saTable("specart_prose", "horn_blast_effect_table")) ++bad;
            if (!rules::saTable("specart_prose", "coat_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "flask_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "jacinth_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "mask_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "quill_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "mace_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "machine_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "servant_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "orb_hatchling_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "orb_wyrmkin_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "orb_dragonette_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "orb_dragon_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "orb_great_serpent_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "orb_firedrake_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "orb_elder_wyrm_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "orb_eternal_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "orb_might_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "nightingale_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "recorder_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "gaxx_power_count")) ++bad;
            if (!rules::saTable("specart_prose", "rod_joint_table")) ++bad;
            if (!rules::saTable("specart_prose", "rod_joint_use_count")) ++bad;
            if (!rules::saTable("specart_prose", "rod_complete_table_use")) ++bad;
            if (!rules::saTable("specart_prose", "sceptre_table_use")) ++bad;
            if (!rules::saTable("specart_prose", "kas_table_use")) ++bad;
            if (!rules::saTable("specart_prose", "tooth_table_use")) ++bad;
            if (!rules::saTable("specart_prose", "tooth_set_right_use")) ++bad;
            if (!rules::saTable("specart_prose", "throne_table_use")) ++bad;
            if (!rules::saTable("specart_prose", "wand_table_use")) ++bad;
            if (rules::saTable("specart", "no_such_tag")) ++bad;
            if (rules::saTable("no_such_def", "row_lo")) ++bad;
            {
                const auto* p1 = rules::saTable("specart",
                                     "row_lo");
                const auto* p2 = rules::saTable("specart",
                                     "row_lo");
                if (p1 != p2) ++bad;
            }
        }
        printf("R1062 specart registry seam audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 8. edges -------------------------------
        // accessor clamps, then all 499 KEPT
        // zero-arg scalars against their parsed
        // pristine literals
        {
            if (rules::saRowLo(-9)
                != rules::saRowLo(0)) ++bad;
            if (rules::saRowLo(99)
                != rules::saRowLo(28)) ++bad;
            if (rules::saRowHi(-9)
                != rules::saRowHi(0)) ++bad;
            if (rules::saRowHi(99)
                != rules::saRowHi(28)) ++bad;
            if (rules::saSaleGp(-9)
                != rules::saSaleGp(0)) ++bad;
            if (rules::saSaleGp(99)
                != rules::saSaleGp(28)) ++bad;
            if (rules::saSaleGpHi(-9)
                != rules::saSaleGpHi(0)) ++bad;
            if (rules::saSaleGpHi(99)
                != rules::saSaleGpHi(28)) ++bad;
            if (rules::saXpValue(-9)
                != rules::saXpValue(0)) ++bad;
            if (rules::saXpValue(99)
                != rules::saXpValue(28)) ++bad;
            if (rules::sapAxePowerCount(-9)
                != rules::sapAxePowerCount(0)) ++bad;
            if (rules::sapAxePowerCount(99)
                != rules::sapAxePowerCount(5)) ++bad;
            if (rules::sapHutMoveInches(-9)
                != rules::sapHutMoveInches(0)) ++bad;
            if (rules::sapHutMoveInches(99)
                != rules::sapHutMoveInches(2)) ++bad;
            if (rules::sapHutPowerCount(-9)
                != rules::sapHutPowerCount(0)) ++bad;
            if (rules::sapHutPowerCount(99)
                != rules::sapHutPowerCount(5)) ++bad;
            if (rules::sapCodexPowerCount(-9)
                != rules::sapCodexPowerCount(0)) ++bad;
            if (rules::sapCodexPowerCount(99)
                != rules::sapCodexPowerCount(5)) ++bad;
            if (rules::sapCrownAlignBandLo(-9)
                != rules::sapCrownAlignBandLo(0)) ++bad;
            if (rules::sapCrownAlignBandLo(99)
                != rules::sapCrownAlignBandLo(2)) ++bad;
            if (rules::sapCrownAlignBandHi(-9)
                != rules::sapCrownAlignBandHi(0)) ++bad;
            if (rules::sapCrownAlignBandHi(99)
                != rules::sapCrownAlignBandHi(2)) ++bad;
            if (rules::sapCrownWornPowerCount(-9)
                != rules::sapCrownWornPowerCount(0)) ++bad;
            if (rules::sapCrownWornPowerCount(99)
                != rules::sapCrownWornPowerCount(2)) ++bad;
            if (rules::sapCrownSet2ndPowerCount(-9)
                != rules::sapCrownSet2ndPowerCount(0)) ++bad;
            if (rules::sapCrownSet2ndPowerCount(99)
                != rules::sapCrownSet2ndPowerCount(1)) ++bad;
            if (rules::sapCrownSet3rdPowerCount(-9)
                != rules::sapCrownSet3rdPowerCount(0)) ++bad;
            if (rules::sapCrownSet3rdPowerCount(99)
                != rules::sapCrownSet3rdPowerCount(4)) ++bad;
            if (rules::sapCrystalPowerCount(-9)
                != rules::sapCrystalPowerCount(0)) ++bad;
            if (rules::sapCrystalPowerCount(99)
                != rules::sapCrystalPowerCount(5)) ++bad;
            if (rules::sapCupPowerCount(-9)
                != rules::sapCupPowerCount(0)) ++bad;
            if (rules::sapCupPowerCount(99)
                != rules::sapCupPowerCount(2)) ++bad;
            if (rules::sapTalismanPowerCount(-9)
                != rules::sapTalismanPowerCount(0)) ++bad;
            if (rules::sapTalismanPowerCount(99)
                != rules::sapTalismanPowerCount(3)) ++bad;
            if (rules::sapCupTalismanBothPowerCount(-9)
                != rules::sapCupTalismanBothPowerCount(0)) ++bad;
            if (rules::sapCupTalismanBothPowerCount(99)
                != rules::sapCupTalismanBothPowerCount(1)) ++bad;
            if (rules::sapCupTalismanPotionBandLo(-9)
                != rules::sapCupTalismanPotionBandLo(0)) ++bad;
            if (rules::sapCupTalismanPotionBandLo(99)
                != rules::sapCupTalismanPotionBandLo(5)) ++bad;
            if (rules::sapCupTalismanPotionBandHi(-9)
                != rules::sapCupTalismanPotionBandHi(0)) ++bad;
            if (rules::sapCupTalismanPotionBandHi(99)
                != rules::sapCupTalismanPotionBandHi(5)) ++bad;
            if (rules::sapEyePowerCount(-9)
                != rules::sapEyePowerCount(0)) ++bad;
            if (rules::sapEyePowerCount(99)
                != rules::sapEyePowerCount(4)) ++bad;
            if (rules::sapHandPowerCount(-9)
                != rules::sapHandPowerCount(0)) ++bad;
            if (rules::sapHandPowerCount(99)
                != rules::sapHandPowerCount(5)) ++bad;
            if (rules::sapOrganPowerCount(-9)
                != rules::sapOrganPowerCount(0)) ++bad;
            if (rules::sapOrganPowerCount(99)
                != rules::sapOrganPowerCount(5)) ++bad;
            if (rules::sapHornBlastPowerTable(-9)
                != rules::sapHornBlastPowerTable(0)) ++bad;
            if (rules::sapHornBlastPowerTable(99)
                != rules::sapHornBlastPowerTable(2)) ++bad;
            if (rules::sapHornBlastEffectTable(-9)
                != rules::sapHornBlastEffectTable(0)) ++bad;
            if (rules::sapHornBlastEffectTable(99)
                != rules::sapHornBlastEffectTable(2)) ++bad;
            if (rules::sapCoatPowerCount(-9)
                != rules::sapCoatPowerCount(0)) ++bad;
            if (rules::sapCoatPowerCount(99)
                != rules::sapCoatPowerCount(5)) ++bad;
            if (rules::sapFlaskPowerCount(-9)
                != rules::sapFlaskPowerCount(0)) ++bad;
            if (rules::sapFlaskPowerCount(99)
                != rules::sapFlaskPowerCount(5)) ++bad;
            if (rules::sapJacinthPowerCount(-9)
                != rules::sapJacinthPowerCount(0)) ++bad;
            if (rules::sapJacinthPowerCount(99)
                != rules::sapJacinthPowerCount(5)) ++bad;
            if (rules::sapMaskPowerCount(-9)
                != rules::sapMaskPowerCount(0)) ++bad;
            if (rules::sapMaskPowerCount(99)
                != rules::sapMaskPowerCount(5)) ++bad;
            if (rules::sapQuillPowerCount(-9)
                != rules::sapQuillPowerCount(0)) ++bad;
            if (rules::sapQuillPowerCount(99)
                != rules::sapQuillPowerCount(5)) ++bad;
            if (rules::sapMacePowerCount(-9)
                != rules::sapMacePowerCount(0)) ++bad;
            if (rules::sapMacePowerCount(99)
                != rules::sapMacePowerCount(5)) ++bad;
            if (rules::sapMachinePowerCount(-9)
                != rules::sapMachinePowerCount(0)) ++bad;
            if (rules::sapMachinePowerCount(99)
                != rules::sapMachinePowerCount(5)) ++bad;
            if (rules::sapServantPowerCount(-9)
                != rules::sapServantPowerCount(0)) ++bad;
            if (rules::sapServantPowerCount(99)
                != rules::sapServantPowerCount(5)) ++bad;
            if (rules::sapOrbHatchlingPowerCount(-9)
                != rules::sapOrbHatchlingPowerCount(0)) ++bad;
            if (rules::sapOrbHatchlingPowerCount(99)
                != rules::sapOrbHatchlingPowerCount(5)) ++bad;
            if (rules::sapOrbWyrmkinPowerCount(-9)
                != rules::sapOrbWyrmkinPowerCount(0)) ++bad;
            if (rules::sapOrbWyrmkinPowerCount(99)
                != rules::sapOrbWyrmkinPowerCount(5)) ++bad;
            if (rules::sapOrbDragonettePowerCount(-9)
                != rules::sapOrbDragonettePowerCount(0)) ++bad;
            if (rules::sapOrbDragonettePowerCount(99)
                != rules::sapOrbDragonettePowerCount(5)) ++bad;
            if (rules::sapOrbDragonPowerCount(-9)
                != rules::sapOrbDragonPowerCount(0)) ++bad;
            if (rules::sapOrbDragonPowerCount(99)
                != rules::sapOrbDragonPowerCount(5)) ++bad;
            if (rules::sapOrbGreatSerpentPowerCount(-9)
                != rules::sapOrbGreatSerpentPowerCount(0)) ++bad;
            if (rules::sapOrbGreatSerpentPowerCount(99)
                != rules::sapOrbGreatSerpentPowerCount(5)) ++bad;
            if (rules::sapOrbFiredrakePowerCount(-9)
                != rules::sapOrbFiredrakePowerCount(0)) ++bad;
            if (rules::sapOrbFiredrakePowerCount(99)
                != rules::sapOrbFiredrakePowerCount(5)) ++bad;
            if (rules::sapOrbElderWyrmPowerCount(-9)
                != rules::sapOrbElderWyrmPowerCount(0)) ++bad;
            if (rules::sapOrbElderWyrmPowerCount(99)
                != rules::sapOrbElderWyrmPowerCount(5)) ++bad;
            if (rules::sapOrbEternalPowerCount(-9)
                != rules::sapOrbEternalPowerCount(0)) ++bad;
            if (rules::sapOrbEternalPowerCount(99)
                != rules::sapOrbEternalPowerCount(5)) ++bad;
            if (rules::sapOrbMightPowerCount(-9)
                != rules::sapOrbMightPowerCount(0)) ++bad;
            if (rules::sapOrbMightPowerCount(99)
                != rules::sapOrbMightPowerCount(5)) ++bad;
            if (rules::sapNightingalePowerCount(-9)
                != rules::sapNightingalePowerCount(0)) ++bad;
            if (rules::sapNightingalePowerCount(99)
                != rules::sapNightingalePowerCount(5)) ++bad;
            if (rules::sapRecorderPowerCount(-9)
                != rules::sapRecorderPowerCount(0)) ++bad;
            if (rules::sapRecorderPowerCount(99)
                != rules::sapRecorderPowerCount(5)) ++bad;
            if (rules::sapGaxxPowerCount(-9)
                != rules::sapGaxxPowerCount(0)) ++bad;
            if (rules::sapGaxxPowerCount(99)
                != rules::sapGaxxPowerCount(5)) ++bad;
            if (rules::sapRodJointTable(-9)
                != rules::sapRodJointTable(0)) ++bad;
            if (rules::sapRodJointTable(99)
                != rules::sapRodJointTable(5)) ++bad;
            if (rules::sapRodJointUseCount(-9)
                != rules::sapRodJointUseCount(0)) ++bad;
            if (rules::sapRodJointUseCount(99)
                != rules::sapRodJointUseCount(5)) ++bad;
            if (rules::sapRodCompleteTableUse(-9)
                != rules::sapRodCompleteTableUse(0)) ++bad;
            if (rules::sapRodCompleteTableUse(99)
                != rules::sapRodCompleteTableUse(5)) ++bad;
            if (rules::sapSceptreTableUse(-9)
                != rules::sapSceptreTableUse(0)) ++bad;
            if (rules::sapSceptreTableUse(99)
                != rules::sapSceptreTableUse(5)) ++bad;
            if (rules::sapKasTableUse(-9)
                != rules::sapKasTableUse(0)) ++bad;
            if (rules::sapKasTableUse(99)
                != rules::sapKasTableUse(5)) ++bad;
            if (rules::sapToothTableUse(-9)
                != rules::sapToothTableUse(0)) ++bad;
            if (rules::sapToothTableUse(99)
                != rules::sapToothTableUse(5)) ++bad;
            if (rules::sapToothSetRightUse(-9)
                != rules::sapToothSetRightUse(0)) ++bad;
            if (rules::sapToothSetRightUse(99)
                != rules::sapToothSetRightUse(5)) ++bad;
            if (rules::sapThroneTableUse(-9)
                != rules::sapThroneTableUse(0)) ++bad;
            if (rules::sapThroneTableUse(99)
                != rules::sapThroneTableUse(5)) ++bad;
            if (rules::sapWandTableUse(-9)
                != rules::sapWandTableUse(0)) ++bad;
            if (rules::sapWandTableUse(99)
                != rules::sapWandTableUse(5)) ++bad;
            if (rules::saRowCount() != 29) ++bad;
            if (rules::saNoXpRowCount() != 29) ++bad;
            if (rules::saDualRangeCount() != 1) ++bad;
            if (rules::saNoSaleRowCount() != 1) ++bad;
            if (rules::saPerToothRowCount() != 1) ++bad;
            if (rules::sapOneOfEachExists() != 1) ++bad;
            if (rules::sapListingCrossedWhenPlaced() != 1) ++bad;
            if (rules::sapUnavailableOptionCount() != 2) ++bad;
            if (rules::sapPowersPartiallyDescribed() != 1) ++bad;
            if (rules::sapDmAssignsMajorPowers() != 1) ++bad;
            if (rules::sapLoreFoundByChance() != 0) ++bad;
            if (rules::sapNemesisSometimesNeeded() != 1) ++bad;
            if (rules::sapPowerTableCount() != 5) ++bad;
            if (rules::sapHenchBehaviorCount() != 3) ++bad;
            if (rules::sapBehaviorEvilDestroysOrEscapes() != 1) ++bad;
            if (rules::sapBehaviorNeutralDominates() != 1) ++bad;
            if (rules::sapBehaviorGoodDefectsWithItem() != 1) ++bad;
            if (rules::sapLoyaltyDropMinPct() != 10) ++bad;
            if (rules::sapLoyaltyDropMaxPct() != 30) ++bad;
            if (rules::sapDestroyedBySingleMeans() != 1) ++bad;
            if (rules::sapDefaceSavePenalty() != -5) ++bad;
            if (rules::sapDefaceFailureIsDeath() != 1) ++bad;
            if (rules::sapCorruptionTraitCount() != 4) ++bad;
            if (rules::sapEffectsArePermanent() != 1) ++bad;
            if (rules::sapDeityMayReverseSome() != 1) ++bad;
            if (rules::sapAxeBladeSharpness() != 1) ++bad;
            if (rules::sapAxeHammerBonus() != 3) ++bad;
            if (rules::sapAxeHandleForms() != 2) ++bad;
            if (rules::sapAxeReturnFeet() != 30) ++bad;
            if (rules::sapAxeDwarfAbilityMultiplier() != 2) ++bad;
            if (rules::sapAxeLifespanBonusPct() != 50) ++bad;
            if (rules::sapAxeBearsCurse() != 1) ++bad;
            if (rules::sapAxeInvokedDevastationLost() != 1) ++bad;
            if (rules::sapAxePowerTotal() != 7) ++bad;
            if (rules::sapHutDiameterFeet() != 15) ++bad;
            if (rules::sapHutHeightFeet() != 10) ++bad;
            if (rules::sapHutLegCount() != 2) ++bad;
            if (rules::sapHutLegLengthFeet() != 12) ++bad;
            if (rules::sapHutInfravisionFeet() != 120) ++bad;
            if (rules::sapHutRoomCount() != 30) ++bad;
            if (rules::sapHutFloorCount() != 3) ++bad;
            if (rules::sapHutMoveTerrainCount() != 3) ++bad;
            if (rules::sapHutCommanderCount() != 1) ++bad;
            if (rules::sapHutCallRangeLeagues() != 1) ++bad;
            if (rules::sapHutLegAttacksPerRound() != 2) ++bad;
            if (rules::sapHutLegArmorClass() != 2) ++bad;
            if (rules::sapHutLegHpEach() != 48) ++bad;
            if (rules::sapHutLegRegenPerRound() != 1) ++bad;
            if (rules::sapHutWallGraniteFeet() != 5) ++bad;
            if (rules::sapHutLegsHillGiantBlows() != 1) ++bad;
            if (rules::sapHutPowerTotal() != 10) ++bad;
            if (rules::sapCodexDamnedPages() != 99) ++bad;
            if (rules::sapCodexDoomChancePct() != 99) ++bad;
            if (rules::sapCodexPerilPerPagePct() != 1) ++bad;
            if (rules::sapCodexTouchKillBelowLevel() != 11) ++bad;
            if (rules::sapCodexCommandMinLevel() != 11) ++bad;
            if (rules::sapCodexPerusalActivation() != 1) ++bad;
            if (rules::sapCodexPowerTotal() != 16) ++bad;
            if (rules::sapCrownRegaliaSetCount() != 3) ++bad;
            if (rules::sapCrownItemsPerSet() != 3) ++bad;
            if (rules::sapCrownChampionEthosCount() != 3) ++bad;
            if (rules::sapCrownPossessionBenefits() != 1) ++bad;
            if (rules::sapCrownWrongEthosDamageMin() != 5) ++bad;
            if (rules::sapCrownWrongEthosDamageMax() != 30) ++bad;
            if (rules::sapCrownWrongEthosSaveOrDeath() != 1) ++bad;
            if (rules::sapCrownWearerLevelBonus() != 1) ++bad;
            if (rules::sapCrownWornPowerTotal() != 4) ++bad;
            if (rules::sapCrownOffEthosMalevolentCount() != 1) ++bad;
            if (rules::sapCrownOffEthosMalevolentTable() != 4) ++bad;
            if (rules::sapCrownSet2ndPowerTotal() != 2) ++bad;
            if (rules::sapCrownSet3rdPowerTotal() != 5) ++bad;
            if (rules::sapCrownDetectionRevealsAlignment() != 0) ++bad;
            if (rules::sapCrownGemCount() != 3) ++bad;
            if (rules::sapCrownSaleGpMin() != 50000) ++bad;
            if (rules::sapCrystalOriginUnknown() != 1) ++bad;
            if (rules::sapCrystalDiamondHard() != 1) ++bad;
            if (rules::sapCrystalTouchRaysBlackFlame() != 1) ++bad;
            if (rules::sapCrystalCharmRadiusFeet() != 30) ++bad;
            if (rules::sapCrystalCharmIsFireCharm() != 1) ++bad;
            if (rules::sapCrystalPowersByGazing() != 1) ++bad;
            if (rules::sapCrystalPowerTotal() != 10) ++bad;
            if (rules::sapCupTalismanRelicCount() != 2) ++bad;
            if (rules::sapCupTalismanPaynimGift() != 1) ++bad;
            if (rules::sapCupTalismanInvokedDevastationEra() != 1) ++bad;
            if (rules::sapCupTalismanLostToRaiders() != 1) ++bad;
            if (rules::sapCupTalismanPotionClassCount() != 4) ++bad;
            if (rules::sapCupTalismanPotionPerWeek() != 1) ++bad;
            if (rules::sapCupGemCount() != 12) ++bad;
            if (rules::sapCupJewelryGpMin() != 75000) ++bad;
            if (rules::sapCupRadiatesMagic() != 0) ++bad;
            if (rules::sapCupPowerTotal() != 5) ++bad;
            if (rules::sapTalismanPointCount() != 8) ++bad;
            if (rules::sapTalismanPointGemCount() != 8) ++bad;
            if (rules::sapTalismanBeadSetCount() != 8) ++bad;
            if (rules::sapTalismanBeadsPerSet() != 3) ++bad;
            if (rules::sapTalismanJewelryGpMin() != 10000) ++bad;
            if (rules::sapTalismanRadiatesMagic() != 0) ++bad;
            if (rules::sapTalismanPowerTotal() != 3) ++bad;
            if (rules::sapCupTalismanBothPowerTotal() != 2) ++bad;
            if (rules::sapCupTalismanPotionBandCount() != 6) ++bad;
            if (rules::sapEyeVecnaPhantomRoams() != 1) ++bad;
            if (rules::sapEyeDoomSurvivors() != 2) ++bad;
            if (rules::sapEyeFeralGlow() != 1) ++bad;
            if (rules::sapEyeAppearsAgate() != 1) ++bad;
            if (rules::sapEyeGraftIrrevocable() != 1) ++bad;
            if (rules::sapEyeHostNeutralEvil() != 1) ++bad;
            if (rules::sapEyeGrantsInfravision() != 1) ++bad;
            if (rules::sapEyeGrantsUltravision() != 1) ++bad;
            if (rules::sapEyePowerTotal() != 6) ++bad;
            if (rules::sapEyePrimaryPowerMalevolent() != 1) ++bad;
            if (rules::sapHandVecnaLeftHand() != 1) ++bad;
            if (rules::sapHandMummifiedExtremity() != 1) ++bad;
            if (rules::sapHandGripStrength() != 18) ++bad;
            if (rules::sapHandGripStrengthRating() != 0) ++bad;
            if (rules::sapHandGripHitOrDamageBonus() != 0) ++bad;
            if (rules::sapHandHostTurnsNeutralEvil() != 1) ++bad;
            if (rules::sapHandMajorPowerWakesSpirit() != 1) ++bad;
            if (rules::sapHandPrimaryPowerInstantEvil() != 1) ++bad;
            if (rules::sapHandSeverBaseChancePct() != 100) ++bad;
            if (rules::sapHandSeverMajorPenaltyPct() != 1) ++bad;
            if (rules::sapHandSeverPrimaryPenaltyPct() != 10) ++bad;
            if (rules::sapHandNoRemovalAtLimit() != 1) ++bad;
            if (rules::sapHandFingerCombinations() != 1) ++bad;
            if (rules::sapHandPowerTotal() != 22) ++bad;
            if (rules::sapHandGodsOnlyAlteration() != 1) ++bad;
            if (rules::sapHandRecordCombinations() != 1) ++bad;
            if (rules::sapOrganPipeCount() != 77) ++bad;
            if (rules::sapOrganStopCount() != 13) ++bad;
            if (rules::sapOrganPedalCount() != 3) ++bad;
            if (rules::sapOrganBellowsElemental() != 1) ++bad;
            if (rules::sapOrganStopsVaryVoice() != 1) ++bad;
            if (rules::sapOrganKeysVaryNotes() != 1) ++bad;
            if (rules::sapOrganPedalPurposeUnknown() != 1) ++bad;
            if (rules::sapOrganStillWorksDespiteTime() != 1) ++bad;
            if (rules::sapOrganWrongStopsSummon() != 1) ++bad;
            if (rules::sapOrganWrongKeysBackfire() != 1) ++bad;
            if (rules::sapOrganMisplayAlignment() != 1) ++bad;
            if (rules::sapOrganDmAssignsStopsKeys() != 1) ++bad;
            if (rules::sapOrganPowerTotal() != 34) ++bad;
            if (rules::sapOrganMisplayNegates() != 1) ++bad;
            if (rules::sapHornResemblesCommonHorns() != 1) ++bad;
            if (rules::sapHornSuggestedPowerPct() != 75) ++bad;
            if (rules::sapHornSuggestedEffectPct() != 25) ++bad;
            if (rules::sapHornIgnoresInappropriate() != 1) ++bad;
            if (rules::sapCoatArndOfTdon() != 1) ++bad;
            if (rules::sapCoatChainLinksWeightless() != 1) ++bad;
            if (rules::sapCoatCoveredAreaCount() != 3) ++bad;
            if (rules::sapCoatMinWearerHeightFt() != 3) ++bad;
            if (rules::sapCoatMaxWearerHeightFt() != 8) ++bad;
            if (rules::sapCoatInvulnerableCovered() != 1) ++bad;
            if (rules::sapCoatUncoveredAc() != 5) ++bad;
            if (rules::sapCoatSaveBonus() != 5) ++bad;
            if (rules::sapCoatFireResistance() != 1) ++bad;
            if (rules::sapCoatElementalImmunityCount() != 3) ++bad;
            if (rules::sapCoatPowerTotal() != 10) ++bad;
            if (rules::sapFlaskHeavyUrn() != 1) ++bad;
            if (rules::sapFlaskTurnipPlug() != 1) ++bad;
            if (rules::sapFlaskSigilRunes() != 1) ++bad;
            if (rules::sapFlaskWordCount() != 3) ++bad;
            if (rules::sapFlaskPrisonerCount() != 5) ++bad;
            if (rules::sapFlaskServantEvilOnly() != 1) ++bad;
            if (rules::sapFlaskKillBeforeReturn() != 1) ++bad;
            if (rules::sapFlaskPowerTotal() != 6) ++bad;
            if (rules::sapJacinthGodFashioned() != 1) ++bad;
            if (rules::sapJacinthMountainHeart() != 1) ++bad;
            if (rules::sapJacinthFacetedBeams() != 1) ++bad;
            if (rules::sapJacinthCharmRangeFt() != 20) ++bad;
            if (rules::sapJacinthSultanPossessed() != 1) ++bad;
            if (rules::sapJacinthKeolandTrailLost() != 1) ++bad;
            if (rules::sapJacinthGraspPowers() != 1) ++bad;
            if (rules::sapJacinthPowerTotal() != 8) ++bad;
            if (rules::sapMaskJohydeeTrickedEvil() != 1) ++bad;
            if (rules::sapMaskOverthrewNation() != 1) ++bad;
            if (rules::sapMaskCoversFace() != 1) ++bad;
            if (rules::sapMaskAssumeLikeness() != 1) ++bad;
            if (rules::sapMaskBlocksMindContact() != 1) ++bad;
            if (rules::sapMaskGazeImmunity() != 1) ++bad;
            if (rules::sapMaskGazeCreatureCount() != 3) ++bad;
            if (rules::sapMaskPowerTotal() != 4) ++bad;
            if (rules::sapQuillMasterThiefBest() != 1) ++bad;
            if (rules::sapQuillUnknownAntiquity() != 1) ++bad;
            if (rules::sapQuillBearsKurothName() != 1) ++bad;
            if (rules::sapQuillInfallibleScribe() != 1) ++bad;
            if (rules::sapQuillDepictsSeenSpoken() != 1) ++bad;
            if (rules::sapQuillPotionTreasureFinding() != 1) ++bad;
            if (rules::sapQuillTreasureFindPerMonth() != 1) ++bad;
            if (rules::sapQuillPowerTotal() != 5) ++bad;
            if (rules::sapMaceSaintCuthbertWeapon() != 1) ++bad;
            if (rules::sapMaceFollyOfError() != 1) ++bad;
            if (rules::sapMaceRelicsEncased() != 1) ++bad;
            if (rules::sapMaceHitDamageBonus() != 5) ++bad;
            if (rules::sapMaceDisruptionEffects() != 1) ++bad;
            if (rules::sapMaceClericStrReq() != 18) ++bad;
            if (rules::sapMaceLawfulGoodOnly() != 1) ++bad;
            if (rules::sapMacePowerTotal() != 6) ++bad;
            if (rules::sapMachineGodsForgotten() != 1) ++bad;
            if (rules::sapMachineWorkmanshipUnknown() != 1) ++bad;
            if (rules::sapMachineBaronLumEmpire() != 1) ++bad;
            if (rules::sapMachineLeverCount() != 60) ++bad;
            if (rules::sapMachineDialCount() != 40) ++bad;
            if (rules::sapMachineSwitchCount() != 20) ++bad;
            if (rules::sapMachineControlsTotal() != 120) ++bad;
            if (rules::sapMachineHalfFunction() != 60) ++bad;
            if (rules::sapMachineWeightLb() != 5500) ++bad;
            if (rules::sapMachineJoltDestroyMax() != 4) ++bad;
            if (rules::sapMachineBoothCreatures() != 4) ++bad;
            if (rules::sapMachinePowerTotal() != 70) ++bad;
            if (rules::sapServantLumSameMake() != 1) ++bad;
            if (rules::sapServantAutomatonHeightFt() != 9) ++bad;
            if (rules::sapServantDepthFt() != 6) ++bad;
            if (rules::sapServantWidthFt() != 4) ++bad;
            if (rules::sapServantInsideRiders() != 2) ++bad;
            if (rules::sapServantOutsideSittersMin() != 4) ++bad;
            if (rules::sapServantCommandPhrases() != 1) ++bad;
            if (rules::sapServantUseCount() != 3) ++bad;
            if (rules::sapServantArmorClass() != 1) ++bad;
            if (rules::sapServantHitPoints() != 60) ++bad;
            if (rules::sapServantWeaponDamagePct() != 50) ++bad;
            if (rules::sapServantRegenPerRound() != 2) ++bad;
            if (rules::sapServantMagicResistPct() != 100) ++bad;
            if (rules::sapServantElementImmuneCount() != 6) ++bad;
            if (rules::sapServantElectricalDamagePct() != 20) ++bad;
            if (rules::sapServantSpeedInches() != 3) ++bad;
            if (rules::sapServantOperationHours() != 12) ++bad;
            if (rules::sapServantRestHours() != 1) ++bad;
            if (rules::sapServantPanicRangeInches() != 12) ++bad;
            if (rules::sapServantPanicSaveBonus() != 2) ++bad;
            if (rules::sapServantAttacksPerRound() != 1) ++bad;
            if (rules::sapServantBaseHitPct() != 15) ++bad;
            if (rules::sapServantDexReduceFloor() != 14) ++bad;
            if (rules::sapServantDexReducePct() != 2) ++bad;
            if (rules::sapServantDamageLowHp() != 10) ++bad;
            if (rules::sapServantDamageHighHp() != 100) ++bad;
            if (rules::sapServantObeysSecretLearners() != 1) ++bad;
            if (rules::sapServantPowerTotal() != 17) ++bad;
            if (rules::sapOrbGoodDeitiesOrigin() != 1) ++bad;
            if (rules::sapOrbDemonsCorrupted() != 1) ++bad;
            if (rules::sapOrbGlobeCount() != 8) ++bad;
            if (rules::sapOrbOnePerAge() != 1) ++bad;
            if (rules::sapOrbSmallestInches() != 3) ++bad;
            if (rules::sapOrbLargestInches() != 10) ++bad;
            if (rules::sapOrbBasReliefCovered() != 1) ++bad;
            if (rules::sapOrbDragonEssence() != 1) ++bad;
            if (rules::sapOrbHatchlingIntelligence() != 9) ++bad;
            if (rules::sapOrbHatchlingEgo() != 9) ++bad;
            if (rules::sapOrbHatchlingPowerTotal() != 3) ++bad;
            if (rules::sapOrbWyrmkinIntelligence() != 10) ++bad;
            if (rules::sapOrbWyrmkinEgo() != 10) ++bad;
            if (rules::sapOrbWyrmkinPowerTotal() != 3) ++bad;
            if (rules::sapOrbDragonetteIntelligence() != 11) ++bad;
            if (rules::sapOrbDragonetteEgo() != 11) ++bad;
            if (rules::sapOrbDragonettePowerTotal() != 5) ++bad;
            if (rules::sapOrbDragonIntelligence() != 12) ++bad;
            if (rules::sapOrbDragonEgo() != 12) ++bad;
            if (rules::sapOrbDragonPowerTotal() != 6) ++bad;
            if (rules::sapOrbGreatSerpentIntelligence() != 13) ++bad;
            if (rules::sapOrbGreatSerpentEgo() != 13) ++bad;
            if (rules::sapOrbGreatSerpentPowerTotal() != 7) ++bad;
            if (rules::sapOrbFiredrakeOldDragon() != 1) ++bad;
            if (rules::sapOrbFiredrakeIntelligence() != 14) ++bad;
            if (rules::sapOrbFiredrakeEgo() != 14) ++bad;
            if (rules::sapOrbFiredrakePowerTotal() != 9) ++bad;
            if (rules::sapOrbElderWyrmVeryOldDragon() != 1) ++bad;
            if (rules::sapOrbElderWyrmIntelligence() != 16) ++bad;
            if (rules::sapOrbElderWyrmEgo() != 16) ++bad;
            if (rules::sapOrbElderWyrmPowerTotal() != 12) ++bad;
            if (rules::sapOrbEternalAncientDragon() != 1) ++bad;
            if (rules::sapOrbEternalTiamatBahamutBonus() != 8) ++bad;
            if (rules::sapOrbEternalIntelligence() != 18) ++bad;
            if (rules::sapOrbEternalEgo() != 18) ++bad;
            if (rules::sapOrbEternalPowerTotal() != 13) ++bad;
            if (rules::sapOrbNotesEvilComponent() != 1) ++bad;
            if (rules::sapOrbNotesNeutralGoodResist() != 1) ++bad;
            if (rules::sapOrbNotesCharmRangeInches() != 5) ++bad;
            if (rules::sapOrbNotesCharmRounds() != 1) ++bad;
            if (rules::sapOrbNotesAwakeAndAware() != 1) ++bad;
            if (rules::sapOrbNotesEvilAutoCharmed() != 1) ++bad;
            if (rules::sapOrbNotesNeutralSavePenalty() != 4) ++bad;
            if (rules::sapOrbNotesGoodSavePenalty() != 2) ++bad;
            if (rules::sapOrbNotesCharmedWisdomPercent() != 50) ++bad;
            if (rules::sapOrbNotesFeeblemindIntelligence() != 3) ++bad;
            if (rules::sapOrbNotesInsanePercent() != 50) ++bad;
            if (rules::sapOrbNotesAwakeMindOnly() != 1) ++bad;
            if (rules::sapOrbNotesSacrificeDestruction() != 1) ++bad;
            if (rules::sapOrbMightOrbCount() != 3) ++bad;
            if (rules::sapOrbMightCrownSource() != 1) ++bad;
            if (rules::sapOrbMightEvilDieLo() != 1) ++bad;
            if (rules::sapOrbMightEvilDieHi() != 6) ++bad;
            if (rules::sapOrbMightGoodDieLo() != 7) ++bad;
            if (rules::sapOrbMightGoodDieHi() != 14) ++bad;
            if (rules::sapOrbMightNeutralDieLo() != 15) ++bad;
            if (rules::sapOrbMightNeutralDieHi() != 20) ++bad;
            if (rules::sapOrbMightTouchDeathSave() != 1) ++bad;
            if (rules::sapOrbMightTouchDamageLo() != 4) ++bad;
            if (rules::sapOrbMightTouchDamageHi() != 24) ++bad;
            if (rules::sapOrbMightRegaliaTableFour() != 1) ++bad;
            if (rules::sapOrbMightPlatinumGems() != 1) ++bad;
            if (rules::sapOrbMightValueGp() != 100000) ++bad;
            if (rules::sapOrbMightGemOfBrightness() != 1) ++bad;
            if (rules::sapOrbMightPowerEthosCount() != 3) ++bad;
            if (rules::sapOrbMightPowerTotal() != 3) ++bad;
            if (rules::sapOrbMightRegaliaPowers() != 1) ++bad;
            if (rules::sapNightingaleMadeByXagy() != 1) ++bad;
            if (rules::sapNightingaleJoramyCoMaker() != 1) ++bad;
            if (rules::sapNightingaleMadeCenturiesAgo() != 17) ++bad;
            if (rules::sapNightingaleEhlissaBentAll() != 1) ++bad;
            if (rules::sapNightingaleNeverEscaped() != 1) ++bad;
            if (rules::sapNightingaleGoldenWireCage() != 1) ++bad;
            if (rules::sapNightingaleWingsPerchPerform() != 1) ++bad;
            if (rules::sapNightingaleEyeRays() != 1) ++bad;
            if (rules::sapNightingaleSongWonders() != 1) ++bad;
            if (rules::sapNightingaleRaySongSpells() != 1) ++bad;
            if (rules::sapNightingaleSphereRadiusFeet() != 30) ++bad;
            if (rules::sapNightingaleSphereBlocksScrying() != 1) ++bad;
            if (rules::sapNightingaleNoHungerThirst() != 1) ++bad;
            if (rules::sapNightingalePowerTotal() != 8) ++bad;
            if (rules::sapRecorderNeedsNoMusician() != 1) ++bad;
            if (rules::sapRecorderPlaysOnCommand() != 1) ++bad;
            if (rules::sapRecorderAlarmRadiusFeet() != 30) ++bad;
            if (rules::sapRecorderAlarmIncludesSelf() != 1) ++bad;
            if (rules::sapRecorderClueWordSongs() != 1) ++bad;
            if (rules::sapRecorderRumoredSpells() != 1) ++bad;
            if (rules::sapRecorderPowerTotal() != 11) ++bad;
            if (rules::sapGaxxAlienOrigin() != 1) ++bad;
            if (rules::sapGaxxPlatinumLoopSpinel() != 1) ++bad;
            if (rules::sapGaxxUnknownGemType() != 1) ++bad;
            if (rules::sapGaxxFingerDiscovery() != 1) ++bad;
            if (rules::sapGaxxFacetCount() != 9) ++bad;
            if (rules::sapGaxxFacingToTop() != 1) ++bad;
            if (rules::sapGaxxTurnsItself() != 1) ++bad;
            if (rules::sapGaxxDailyRandomFacet() != 1) ++bad;
            if (rules::sapGaxxFacetOrderKnown() != 1) ++bad;
            if (rules::sapGaxxCannotBeMarked() != 1) ++bad;
            if (rules::sapGaxxPowerTotal() != 9) ++bad;
            if (rules::sapRodWindDukesMadeIt() != 1) ++bad;
            if (rules::sapRodMadeForBattleOfPesh() != 1) ++bad;
            if (rules::sapRodPeshChaosVersusLaw() != 1) ++bad;
            if (rules::sapRodShatteredAtPesh() != 1) ++bad;
            if (rules::sapRodNothingDestroysIt() != 1) ++bad;
            if (rules::sapRodCorrectOrderSurpassingPower() != 1) ++bad;
            if (rules::sapRodPartCount() != 7) ++bad;
            if (rules::sapRodPartsSlightlyDifferent() != 1) ++bad;
            if (rules::sapRodFirstLargestLengthDiameter() != 1) ++bad;
            if (rules::sapRodSeventhSmallest() != 1) ++bad;
            if (rules::sapRodNoAlonePower() != 1) ++bad;
            if (rules::sapRodPartsLookLikeBatons() != 1) ++bad;
            if (rules::sapRodSeventhLooksLikeWand() != 1) ++bad;
            if (rules::sapRodFirstSensesSecond() != 1) ++bad;
            if (rules::sapRodSensingNeedsWholeThought() != 1) ++bad;
            if (rules::sapRodLeadsOnlyUpward() != 1) ++bad;
            if (rules::sapRodOutOfOrderTouchTeleports() != 1) ++bad;
            if (rules::sapRodTeleportMinMiles() != 100) ++bad;
            if (rules::sapRodTeleportMaxMiles() != 1000) ++bad;
            if (rules::sapRodAssembledLengthFeet() != 5) ++bad;
            if (rules::sapRodThreeSectionsGripLock() != 1) ++bad;
            if (rules::sapRodPartPowersCumulative() != 1) ++bad;
            if (rules::sapRodFullPowersNeedAllParts() != 1) ++bad;
            if (rules::sapRodCannotBeDisassembled() != 1) ++bad;
            if (rules::sapRodPrimeRiskDenominator() != 20) ++bad;
            if (rules::sapRodPrimeRiskPercent() != 5) ++bad;
            if (rules::sapRodBreakupTeleportMinMiles() != 100) ++bad;
            if (rules::sapRodBreakupTeleportMaxMiles() != 1200) ++bad;
            if (rules::sapRodOutOfOrderNotCumulative() != 1) ++bad;
            if (rules::sapRodLastPieceJoinedActive() != 1) ++bad;
            if (rules::sapRodInOrderCumulative() != 1) ++bad;
            if (rules::sapRodAssemblyRowCount() != 6) ++bad;
            if (rules::sapRodAssemblyUseTotal() != 6) ++bad;
            if (rules::sapRodCompleteUseTotal() != 7) ++bad;
            if (rules::sapRodCompleteOrderQuirk() != 1) ++bad;
            if (rules::sapRodCompleteLacksTableVI() != 1) ++bad;
            if (rules::sapRodBlankSlotCount() != 13) ++bad;
            if (rules::sapRodBlankSlotUnderscores() != 11) ++bad;
            if (rules::sapSceptreCount() != 3) ++bad;
            if (rules::sapSceptreSourceCrownOfMight() != 1) ++bad;
            if (rules::sapSceptreEvilBandLo() != 1) ++bad;
            if (rules::sapSceptreEvilBandHi() != 6) ++bad;
            if (rules::sapSceptreGoodBandLo() != 7) ++bad;
            if (rules::sapSceptreGoodBandHi() != 14) ++bad;
            if (rules::sapSceptreNeutralBandLo() != 15) ++bad;
            if (rules::sapSceptreNeutralBandHi() != 20) ++bad;
            if (rules::sapSceptreForeignEthosCrownEffects() != 1) ++bad;
            if (rules::sapSceptreBronzeInlaidSilver() != 1) ++bad;
            if (rules::sapSceptreHugeStoneTipping() != 1) ++bad;
            if (rules::sapSceptreLengthFeet() != 2) ++bad;
            if (rules::sapSceptreValueGp() != 150000) ++bad;
            if (rules::sapSceptreRodOfBeguiling() != 1) ++bad;
            if (rules::sapSceptreUseTotal() != 3) ++bad;
            if (rules::sapSceptreCrownOrbComboNote() != 1) ++bad;
            if (rules::sapSceptreBlankSlotCount() != 9) ++bad;
            if (rules::sapKasOfVecnaTheLich() != 1) ++bad;
            if (rules::sapKasBodyguardRightHand() != 1) ++bad;
            if (rules::sapKasFlatchetDullGrayMetal() != 1) ++bad;
            if (rules::sapKasSharpPointKeenEdges() != 1) ++bad;
            if (rules::sapKasServedFaithfully() != 1) ++bad;
            if (rules::sapKasHubrisGrew() != 1) ++bad;
            if (rules::sapKasSwordUrgedHimOn() != 1) ++bad;
            if (rules::sapKasGreaterThanVecna() != 1) ++bad;
            if (rules::sapKasCouldRuleInVecnaStead() != 1) ++bad;
            if (rules::sapKasDestroyedVecna() != 1) ++bad;
            if (rules::sapKasDoomWroughtTogether() != 1) ++bad;
            if (rules::sapKasWorldBrighter() != 1) ++bad;
            if (rules::sapKasPowersOnlyHinted() != 1) ++bad;
            if (rules::sapKasRenownedSwordsman() != 1) ++bad;
            if (rules::sapKasPlusBonus() != 6) ++bad;
            if (rules::sapKasDefender() != 1) ++bad;
            if (rules::sapKasDoubleDamageOffPlane() != 1) ++bad;
            if (rules::sapKasNormalDamageOnOtherPlanes() != 1) ++bad;
            if (rules::sapKasShortSword() != 1) ++bad;
            if (rules::sapKasEvilChaoticAlignment() != 1) ++bad;
            if (rules::sapKasIntelligence() != 15) ++bad;
            if (rules::sapKasEgo() != 19) ++bad;
            if (rules::sapKasTriesToControl() != 1) ++bad;
            if (rules::sapKasUseTotal() != 13) ++bad;
            if (rules::sapKasBlankSlotCount() != 13) ++bad;
            if (rules::sapKasPrintsInOrder() != 1) ++bad;
            if (rules::sapToothHistoriesSilent() != 1) ++bad;
            if (rules::sapToothGodsGavePowers() != 1) ++bad;
            if (rules::sapToothRelicsAreTeeth() != 1) ++bad;
            if (rules::sapToothEachToothHasPower() != 1) ++bad;
            if (rules::sapToothCount() != 32) ++bad;
            if (rules::sapToothBenefitLevels() != 3) ++bad;
            if (rules::sapToothQuarterCount() != 8) ++bad;
            if (rules::sapToothHalfCount() != 16) ++bad;
            if (rules::sapToothGraftsInMouth() != 1) ++bad;
            if (rules::sapToothLikeMissingTooth() != 1) ++bad;
            if (rules::sapToothNeverRemoved() != 1) ++bad;
            if (rules::sapToothRemovalOnlyByDemise() != 1) ++bad;
            if (rules::sapToothPowersCumulative() != 1) ++bad;
            if (rules::sapToothUseTotal() != 32) ++bad;
            if (rules::sapToothTableOneCount() != 21) ++bad;
            if (rules::sapToothTableTwoCount() != 4) ++bad;
            if (rules::sapToothTableThreeCount() != 4) ++bad;
            if (rules::sapToothTableFourCount() != 1) ++bad;
            if (rules::sapToothTableFiveCount() != 0) ++bad;
            if (rules::sapToothTableSixCount() != 2) ++bad;
            if (rules::sapToothLoneFourTooth() != 21) ++bad;
            if (rules::sapToothFirstSixTooth() != 7) ++bad;
            if (rules::sapToothSecondSixTooth() != 14) ++bad;
            if (rules::sapToothUnderscoreRunLen() != 14) ++bad;
            if (rules::sapToothBlankSlotCount() != 51) ++bad;
            if (rules::sapToothXSignCount() != 51) ++bad;
            if (rules::sapToothSetPairRows() != 8) ++bad;
            if (rules::sapToothSetQuarterRows() != 4) ++bad;
            if (rules::sapToothSetHalfRepeatQuarters() != 1) ++bad;
            if (rules::sapToothSetFiveRows() != 3) ++bad;
            if (rules::sapToothSetLeftTwoCount() != 8) ++bad;
            if (rules::sapToothSetLeftFiveCount() != 3) ++bad;
            if (rules::sapToothSetRightThreeCount() != 4) ++bad;
            if (rules::sapToothSetRightFourCount() != 2) ++bad;
            if (rules::sapToothSetRightSixCount() != 2) ++bad;
            if (rules::sapThroneCarvenMountainHeart() != 1) ++bad;
            if (rules::sapThroneMassiveStoneChair() != 1) ++bad;
            if (rules::sapThroneMosaicsIvoryMetals() != 1) ++bad;
            if (rules::sapThroneSetAboutGems() != 1) ++bad;
            if (rules::sapThroneGodsActuallySat() != 1) ++bad;
            if (rules::sapThroneWithinGreatCavern() != 1) ++bad;
            if (rules::sapThroneImmobileImmovable() != 1) ++bad;
            if (rules::sapThroneAffectsAnyoneSeated() != 1) ++bad;
            if (rules::sapThroneCertainMagicItem() != 1) ++bad;
            if (rules::sapThroneMalevolentEffectToo() != 1) ++bad;
            if (rules::sapThroneItemGainOnlyOnce() != 1) ++bad;
            if (rules::sapThroneProperWordsGestures() != 1) ++bad;
            if (rules::sapThroneGraspOptions() != 3) ++bad;
            if (rules::sapThroneUseTotal() != 14) ++bad;
            if (rules::sapThroneTableOneCount() != 3) ++bad;
            if (rules::sapThroneTableTwoCount() != 3) ++bad;
            if (rules::sapThroneTableThreeCount() != 2) ++bad;
            if (rules::sapThroneTableFourCount() != 2) ++bad;
            if (rules::sapThroneTableFiveCount() != 2) ++bad;
            if (rules::sapThroneTableSixCount() != 2) ++bad;
            if (rules::sapThroneBlankSlotCount() != 14) ++bad;
            if (rules::sapThroneXSignCount() != 6) ++bad;
            if (rules::sapThroneBulletLineCount() != 0) ++bad;
            if (rules::sapWandDemonPrinceProperty() != 1) ++bad;
            if (rules::sapWandPassesToPrimeMaterial() != 1) ++bad;
            if (rules::sapWandWreakChaosEvil() != 1) ++bad;
            if (rules::sapWandMonsterManualRef() != 1) ++bad;
            if (rules::sapWandSavingThrowVersusMagic() != 1) ++bad;
            if (rules::sapWandAvoidsDeathAnnihilation() != 1) ++bad;
            if (rules::sapWandImmuneCount() != 6) ++bad;
            if (rules::sapWandUseTotal() != 10) ++bad;
            if (rules::sapWandTableOneCount() != 4) ++bad;
            if (rules::sapWandTableTwoCount() != 2) ++bad;
            if (rules::sapWandTableThreeCount() != 2) ++bad;
            if (rules::sapWandTableFourCount() != 1) ++bad;
            if (rules::sapWandTableFiveCount() != 0) ++bad;
            if (rules::sapWandTableSixCount() != 1) ++bad;
            if (rules::sapWandBlankSlotCount() != 10) ++bad;
            if (rules::sapWandXSignCount() != 5) ++bad;
            if (rules::sapWandBulletLineCount() != 5) ++bad;
            if (rules::sapWandFourOneSpaceSeparator() != 1) ++bad;
            if (rules::sapWandFourOneCommaCount() != 2) ++bad;
            if (rules::sapFinalXSignCount() != 11) ++bad;
            if (rules::sapFinalBlankRunCount() != 24) ++bad;
            if (rules::sapFinalUnderscoreRunLen() != 14) ++bad;
            if (rules::sapFinalCurlyApostropheCount() != 2) ++bad;
            if (rules::sapFinalEmDashCount() != 0) ++bad;
            if (rules::sapFinalPageSeamLine() != 1797) ++bad;
            if (rules::sapFinalSpecialDescriptionCount() != 29) ++bad;
        }
        printf("R1062 specart registry edges audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
    }
