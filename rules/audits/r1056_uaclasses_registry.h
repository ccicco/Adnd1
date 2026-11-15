    // ==== R1056: uaclasses registry ==========
    // The R1056 de-wire: the 68 retiring static
    // arrays of the thirteen rules/ua CLASSES-family
    // headers ride items::MiscItemRegistry from
    // content/tables/ua_classes/ - 24 defs, 37 tables, 20
    // rows readers; the six subraces.h struct/pointer
    // seams stay C++, probed here. Seven
    // sections: load, counts, defs-A/B/C, seam,
    // edges. Census 1096 -> 1103. DO NOT hand-edit:
    // tools/r1056_splice.py is the only writer.
    {
        int bad = 0;
        // -- 1. load ------------------------------
        {
            items::MiscItemRegistry reg;
            int n = reg.loadDirectory(
                "content/tables/ua_classes");
            if (n != 24) ++bad;
            if (!reg.errors().empty()) ++bad;
            for (const auto& kv : reg.all())
                if ((int)kv.second.sources.size() != 1
                    || kv.second.sources[0].second != 1056)
                    ++bad;
            if (!reg.find("ua_acrobat")) ++bad;
            if (!reg.find("ua_acrobat_retained")) ++bad;
            if (!reg.find("ua_barbarian")) ++bad;
            if (!reg.find("ua_barbarian_weapons")) ++bad;
            if (!reg.find("ua_cavalier")) ++bad;
            if (!reg.find("ua_cavalier_mind")) ++bad;
            if (!reg.find("ua_cavmoney")) ++bad;
            if (!reg.find("ua_cavmoney_entry")) ++bad;
            if (!reg.find("ua_cavmoney_items")) ++bad;
            if (!reg.find("ua_hierophant")) ++bad;
            if (!reg.find("ua_hierophant_conjure")) ++bad;
            if (!reg.find("ua_hierophant_special")) ++bad;
            if (!reg.find("ua_paladin")) ++bad;
            if (!reg.find("ua_classtables")) ++bad;
            if (!reg.find("ua_cavtable")) ++bad;
            if (!reg.find("ua_followers")) ++bad;
            if (!reg.find("ua_ranger")) ++bad;
            if (!reg.find("ua_ranger_identify")) ++bad;
            if (!reg.find("ua_socialclass")) ++bad;
            if (!reg.find("ua_socialclass_abbr")) ++bad;
            if (!reg.find("ua_socialclass_roster")) ++bad;
            if (!reg.find("ua_birth")) ++bad;
            if (!reg.find("ua_subrace_prefs")) ++bad;
            if (!reg.find("ua_subrace_letters")) ++bad;
        }
        printf("R1056 uaclasses registry load audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 2. counts --------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/ua_classes");
            {
                const items::MiscItemDef* d =
                    reg.find("ua_acrobat");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 4
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_acrobatRowCount"
                        || d->pins[0].value != 4)
                        ++bad;
                    if ((int)d->tables.size() != 10) ++bad;
                    if (d->tables[0].name
                        != "carry_gp"
                        || (int)d->tables[0]
                            .values.size() != 15)
                        ++bad;
                    if (d->tables[1].name
                        != "dex_attack"
                        || (int)d->tables[1]
                            .values.size() != 4)
                        ++bad;
                    if (d->tables[2].name
                        != "dex_evasion"
                        || (int)d->tables[2]
                            .values.size() != 4)
                        ++bad;
                    if (d->tables[3].name
                        != "dex_falling"
                        || (int)d->tables[3]
                            .values.size() != 4)
                        ++bad;
                    if (d->tables[4].name
                        != "dex_tightrope"
                        || (int)d->tables[4]
                            .values.size() != 4)
                        ++bad;
                    if (d->tables[5].name
                        != "dex_vault"
                        || (int)d->tables[5]
                            .values.size() != 4)
                        ++bad;
                    if (d->tables[6].name
                        != "ext_fail"
                        || (int)d->tables[6]
                            .values.size() != 4)
                        ++bad;
                    if (d->tables[7].name
                        != "ext_recover"
                        || (int)d->tables[7]
                            .values.size() != 4)
                        ++bad;
                    if (d->tables[8].name
                        != "fall_known"
                        || (int)d->tables[8]
                            .values.size() != 51)
                        ++bad;
                    if (d->tables[9].name
                        != "split_xp"
                        || (int)d->tables[9]
                            .values.size() != 7)
                        ++bad;
                    if (d->rows[0].name
                        != "Find Traps") ++bad;
                    if (d->rows[1].name
                        != "Pick Pockets") ++bad;
                    if (d->rows[2].name
                        != "Open Locks") ++bad;
                    if (d->rows[3].name
                        != "Remove Traps") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_acrobat_retained");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 4
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_acrobat_retainedRowCount"
                        || d->pins[0].value != 4)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                    if (d->rows[0].name
                        != "Move Silently") ++bad;
                    if (d->rows[1].name
                        != "Hide in Shadows") ++bad;
                    if (d->rows[2].name
                        != "Hear Noise") ++bad;
                    if (d->rows[3].name
                        != "Read Languages") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_barbarian");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 7
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_barbarianRowCount"
                        || d->pins[0].value != 7)
                        ++bad;
                    if ((int)d->tables.size() != 2) ++bad;
                    if (d->tables[0].name
                        != "strike_level"
                        || (int)d->tables[0]
                            .values.size() != 5)
                        ++bad;
                    if (d->tables[1].name
                        != "xp_attain"
                        || (int)d->tables[1]
                            .values.size() != 11)
                        ++bad;
                    if (d->rows[0].name
                        != "Animal Handling") ++bad;
                    if (d->rows[1].name
                        != "Horsemanship") ++bad;
                    if (d->rows[2].name
                        != "Long-Distance Signaling") ++bad;
                    if (d->rows[3].name
                        != "Running") ++bad;
                    if (d->rows[4].name
                        != "Small Craft (Paddled and Rowed)") ++bad;
                    if (d->rows[5].name
                        != "Sound Imitation") ++bad;
                    if (d->rows[6].name
                        != "Snare Building") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_barbarian_weapons");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 3
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_barbarian_weaponsRowCount"
                        || d->pins[0].value != 3)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                    if (d->rows[0].name
                        != "Hand Axe") ++bad;
                    if (d->rows[1].name
                        != "Knife") ++bad;
                    if (d->rows[2].name
                        != "Spear") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_cavalier");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 11
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_cavalierRowCount"
                        || d->pins[0].value != 11)
                        ++bad;
                    if ((int)d->tables.size() != 2) ++bad;
                    if (d->tables[0].name
                        != "horsemanship"
                        || (int)d->tables[0]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[1].name
                        != "xp_attain"
                        || (int)d->tables[1]
                            .values.size() != 12)
                        ++bad;
                    if (d->rows[0].name
                        != "lance") ++bad;
                    if (d->rows[1].name
                        != "long sword") ++bad;
                    if (d->rows[2].name
                        != "broad sword") ++bad;
                    if (d->rows[3].name
                        != "bastard sword") ++bad;
                    if (d->rows[4].name
                        != "short sword") ++bad;
                    if (d->rows[5].name
                        != "horseman's mace") ++bad;
                    if (d->rows[6].name
                        != "horseman's flail") ++bad;
                    if (d->rows[7].name
                        != "horseman's military pick") ++bad;
                    if (d->rows[8].name
                        != "dagger") ++bad;
                    if (d->rows[9].name
                        != "scimitar") ++bad;
                    if (d->rows[10].name
                        != "javelin") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_cavalier_mind");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 10
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_cavalier_mindRowCount"
                        || d->pins[0].value != 10)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                    if (d->rows[0].name
                        != "beguiling") ++bad;
                    if (d->rows[1].name
                        != "charm") ++bad;
                    if (d->rows[2].name
                        != "domination") ++bad;
                    if (d->rows[3].name
                        != "hold") ++bad;
                    if (d->rows[4].name
                        != "hypnosis") ++bad;
                    if (d->rows[5].name
                        != "magic jar") ++bad;
                    if (d->rows[6].name
                        != "possession") ++bad;
                    if (d->rows[7].name
                        != "sleep") ++bad;
                    if (d->rows[8].name
                        != "suggestion") ++bad;
                    if (d->rows[9].name
                        != "psionic mind blast") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_cavmoney");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 6
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_cavmoneyRowCount"
                        || d->pins[0].value != 6)
                        ++bad;
                    if ((int)d->tables.size() != 7) ++bad;
                    if (d->tables[0].name
                        != "dice_bonus"
                        || (int)d->tables[0]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[1].name
                        != "dice_count"
                        || (int)d->tables[1]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[2].name
                        != "dice_faces"
                        || (int)d->tables[2]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[3].name
                        != "gold_high"
                        || (int)d->tables[3]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[4].name
                        != "gold_low"
                        || (int)d->tables[4]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[5].name
                        != "item_count"
                        || (int)d->tables[5]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[6].name
                        != "item_offset"
                        || (int)d->tables[6]
                            .values.size() != 6)
                        ++bad;
                    if (d->rows[0].name
                        != "Lower Middle Class or less") ++bad;
                    if (d->rows[1].name
                        != "Middle Middle Class") ++bad;
                    if (d->rows[2].name
                        != "Upper Middle Class") ++bad;
                    if (d->rows[3].name
                        != "Lower Upper Class") ++bad;
                    if (d->rows[4].name
                        != "Middle Upper Class") ++bad;
                    if (d->rows[5].name
                        != "Upper Upper Class") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_cavmoney_entry");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 6
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_cavmoney_entryRowCount"
                        || d->pins[0].value != 6)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                    if (d->rows[0].name
                        != "Horseman") ++bad;
                    if (d->rows[1].name
                        != "Horseman") ++bad;
                    if (d->rows[2].name
                        != "Horseman") ++bad;
                    if (d->rows[3].name
                        != "Cavalier") ++bad;
                    if (d->rows[4].name
                        != "Cavalier") ++bad;
                    if (d->rows[5].name
                        != "Cavalier") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_cavmoney_items");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 30
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_cavmoney_itemsRowCount"
                        || d->pins[0].value != 30)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                    if (d->rows[0].name
                        != "shield") ++bad;
                    if (d->rows[1].name
                        != "sword (any type)") ++bad;
                    if (d->rows[2].name
                        != "riding horse") ++bad;
                    if (d->rows[3].name
                        != "shield") ++bad;
                    if (d->rows[4].name
                        != "dagger") ++bad;
                    if (d->rows[5].name
                        != "sword (broad or long)") ++bad;
                    if (d->rows[6].name
                        != "light warhorse") ++bad;
                    if (d->rows[7].name
                        != "chain mail") ++bad;
                    if (d->rows[8].name
                        != "sword (broad or long)") ++bad;
                    if (d->rows[9].name
                        != "lance") ++bad;
                    if (d->rows[10].name
                        != "light warhorse") ++bad;
                    if (d->rows[11].name
                        != "shield") ++bad;
                    if (d->rows[12].name
                        != "plate mail") ++bad;
                    if (d->rows[13].name
                        != "dagger") ++bad;
                    if (d->rows[14].name
                        != "sword (long or broad)") ++bad;
                    if (d->rows[15].name
                        != "lance") ++bad;
                    if (d->rows[16].name
                        != "medium warhorse") ++bad;
                    if (d->rows[17].name
                        != "shield") ++bad;
                    if (d->rows[18].name
                        != "field plate armor") ++bad;
                    if (d->rows[19].name
                        != "dagger") ++bad;
                    if (d->rows[20].name
                        != "sword (long or broad)") ++bad;
                    if (d->rows[21].name
                        != "lance") ++bad;
                    if (d->rows[22].name
                        != "heavy warhorse") ++bad;
                    if (d->rows[23].name
                        != "shield") ++bad;
                    if (d->rows[24].name
                        != "full plate armor") ++bad;
                    if (d->rows[25].name
                        != "dagger") ++bad;
                    if (d->rows[26].name
                        != "sword (long or broad)") ++bad;
                    if (d->rows[27].name
                        != "mace") ++bad;
                    if (d->rows[28].name
                        != "lance") ++bad;
                    if (d->rows[29].name
                        != "heavy warhorse with leather barding") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_hierophant");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 8
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_hierophantRowCount"
                        || d->pins[0].value != 8)
                        ++bad;
                    if ((int)d->tables.size() != 3) ++bad;
                    if (d->tables[0].name
                        != "conjure_high"
                        || (int)d->tables[0]
                            .values.size() != 20)
                        ++bad;
                    if (d->tables[1].name
                        != "conjure_low"
                        || (int)d->tables[1]
                            .values.size() != 20)
                        ++bad;
                    if (d->tables[2].name
                        != "xp_band_low"
                        || (int)d->tables[2]
                            .values.size() != 8)
                        ++bad;
                    if (d->rows[0].name
                        != "band_16") ++bad;
                    if (d->rows[1].name
                        != "band_17") ++bad;
                    if (d->rows[2].name
                        != "band_18") ++bad;
                    if (d->rows[3].name
                        != "band_19") ++bad;
                    if (d->rows[4].name
                        != "band_20") ++bad;
                    if (d->rows[5].name
                        != "band_21") ++bad;
                    if (d->rows[6].name
                        != "band_22") ++bad;
                    if (d->rows[7].name
                        != "band_23") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_hierophant_conjure");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 20
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_hierophant_conjureRowCount"
                        || d->pins[0].value != 20)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                    if (d->rows[0].name
                        != "16 HD fire elemental") ++bad;
                    if (d->rows[1].name
                        != "2-4 salamanders") ++bad;
                    if (d->rows[2].name
                        != "1 efreeti") ++bad;
                    if (d->rows[3].name
                        != "21-24 HD fire elemental") ++bad;
                    if (d->rows[4].name
                        != "earth elemental") ++bad;
                    if (d->rows[5].name
                        != "2-4 xorn") ++bad;
                    if (d->rows[6].name
                        != "1 dao") ++bad;
                    if (d->rows[7].name
                        != "21-24 HD earth elemental") ++bad;
                    if (d->rows[8].name
                        != "16 HD water elemental") ++bad;
                    if (d->rows[9].name
                        != "7-12 tritons on hippocampi") ++bad;
                    if (d->rows[10].name
                        != "1 marid") ++bad;
                    if (d->rows[11].name
                        != "21-24 HD water elemental") ++bad;
                    if (d->rows[12].name
                        != "16 HD air elemental") ++bad;
                    if (d->rows[13].name
                        != "2-4 invisible stalkers") ++bad;
                    if (d->rows[14].name
                        != "1 djinni") ++bad;
                    if (d->rows[15].name
                        != "21-24 HD air elemental") ++bad;
                    if (d->rows[16].name
                        != "16 HD para-elemental") ++bad;
                    if (d->rows[17].name
                        != "special") ++bad;
                    if (d->rows[18].name
                        != "21-24 HD para-elemental") ++bad;
                    if (d->rows[19].name
                        != "") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_hierophant_special");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 4
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_hierophant_specialRowCount"
                        || d->pins[0].value != 4)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                    if (d->rows[0].name
                        != "5-8 lava children") ++bad;
                    if (d->rows[1].name
                        != "5-8 winter wolves") ++bad;
                    if (d->rows[2].name
                        != "21-24 mudmen") ++bad;
                    if (d->rows[3].name
                        != "21-24 vapor rats") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_paladin");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 5
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_paladinRowCount"
                        || d->pins[0].value != 5)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                    if (d->rows[0].name
                        != "weapons of choice") ++bad;
                    if (d->rows[1].name
                        != "parrying ability") ++bad;
                    if (d->rows[2].name
                        != "horsemanship") ++bad;
                    if (d->rows[3].name
                        != "saving throw bonuses") ++bad;
                    if (d->rows[4].name
                        != "immunity to fear") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_classtables");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 2
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_classtablesRowCount"
                        || d->pins[0].value != 2)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                    if (d->rows[0].name
                        != "lasso") ++bad;
                    if (d->rows[1].name
                        != "staff") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_cavtable");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 12
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_cavtableRowCount"
                        || d->pins[0].value != 12)
                        ++bad;
                    if ((int)d->tables.size() != 2) ++bad;
                    if (d->tables[0].name
                        != "xp_high"
                        || (int)d->tables[0]
                            .values.size() != 12)
                        ++bad;
                    if (d->tables[1].name
                        != "xp_low"
                        || (int)d->tables[1]
                            .values.size() != 12)
                        ++bad;
                    if (d->rows[0].name
                        != "level_1") ++bad;
                    if (d->rows[1].name
                        != "level_2") ++bad;
                    if (d->rows[2].name
                        != "level_3") ++bad;
                    if (d->rows[3].name
                        != "level_4") ++bad;
                    if (d->rows[4].name
                        != "level_5") ++bad;
                    if (d->rows[5].name
                        != "level_6") ++bad;
                    if (d->rows[6].name
                        != "level_7") ++bad;
                    if (d->rows[7].name
                        != "level_8") ++bad;
                    if (d->rows[8].name
                        != "level_9") ++bad;
                    if (d->rows[9].name
                        != "level_10") ++bad;
                    if (d->rows[10].name
                        != "level_11") ++bad;
                    if (d->rows[11].name
                        != "level_12") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_followers");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 7
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_followersRowCount"
                        || d->pins[0].value != 7)
                        ++bad;
                    if ((int)d->tables.size() != 3) ++bad;
                    if (d->tables[0].name
                        != "dice_count"
                        || (int)d->tables[0]
                            .values.size() != 7)
                        ++bad;
                    if (d->tables[1].name
                        != "equip_hi"
                        || (int)d->tables[1]
                            .values.size() != 4)
                        ++bad;
                    if (d->tables[2].name
                        != "equip_lo"
                        || (int)d->tables[2]
                            .values.size() != 4)
                        ++bad;
                    if (d->rows[0].name
                        != "level_4") ++bad;
                    if (d->rows[1].name
                        != "level_5") ++bad;
                    if (d->rows[2].name
                        != "level_6") ++bad;
                    if (d->rows[3].name
                        != "level_7") ++bad;
                    if (d->rows[4].name
                        != "level_8") ++bad;
                    if (d->rows[5].name
                        != "level_9") ++bad;
                    if (d->rows[6].name
                        != "level_10") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ranger");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 22
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_rangerRowCount"
                        || d->pins[0].value != 22)
                        ++bad;
                    if ((int)d->tables.size() != 1) ++bad;
                    if (d->tables[0].name
                        != "terrain_mod"
                        || (int)d->tables[0]
                            .values.size() != 4)
                        ++bad;
                    if (d->rows[0].name
                        != "bugbear") ++bad;
                    if (d->rows[1].name
                        != "cyclopskin") ++bad;
                    if (d->rows[2].name
                        != "dune stalker") ++bad;
                    if (d->rows[3].name
                        != "ettin") ++bad;
                    if (d->rows[4].name
                        != "flind") ++bad;
                    if (d->rows[5].name
                        != "gibberling") ++bad;
                    if (d->rows[6].name
                        != "giant") ++bad;
                    if (d->rows[7].name
                        != "gnoll") ++bad;
                    if (d->rows[8].name
                        != "goblin") ++bad;
                    if (d->rows[9].name
                        != "grimlock") ++bad;
                    if (d->rows[10].name
                        != "hobgoblin") ++bad;
                    if (d->rows[11].name
                        != "kobold") ++bad;
                    if (d->rows[12].name
                        != "meazel") ++bad;
                    if (d->rows[13].name
                        != "norker") ++bad;
                    if (d->rows[14].name
                        != "ogre") ++bad;
                    if (d->rows[15].name
                        != "ogre mage") ++bad;
                    if (d->rows[16].name
                        != "ogrillon") ++bad;
                    if (d->rows[17].name
                        != "orc") ++bad;
                    if (d->rows[18].name
                        != "quaggoth") ++bad;
                    if (d->rows[19].name
                        != "tasloi") ++bad;
                    if (d->rows[20].name
                        != "troll") ++bad;
                    if (d->rows[21].name
                        != "xvart") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ranger_identify");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 10
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_ranger_identifyRowCount"
                        || d->pins[0].value != 10)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                    if (d->rows[0].name
                        != "Common woodland creatures' tracks and direction of travel") ++bad;
                    if (d->rows[1].name
                        != "Common woodland creatures' number and pace") ++bad;
                    if (d->rows[2].name
                        != "Common woodland creatures' time of passage (outdoors only)") ++bad;
                    if (d->rows[3].name
                        != "As 3rd level with respect to uncommon woodland creatures") ++bad;
                    if (d->rows[4].name
                        != "As 3rd level with respect to rare woodland creatures") ++bad;
                    if (d->rows[5].name
                        != "As 3rd level with respect to very rare woodland creatures") ++bad;
                    if (d->rows[6].name
                        != "As 3rd level with respect to all sorts of creatures (woodland and otherwise) within a 100-mile radius") ++bad;
                    if (d->rows[7].name
                        != "As 7th level, plus the ability to determine the general size and weight of humans") ++bad;
                    if (d->rows[8].name
                        != "As 8th level, plus the ability to determine the size and numbers of mounted creatures") ++bad;
                    if (d->rows[9].name
                        != "As 9th level with respect to all creatures ever observed, prior to attaining 10th level or subsequently") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_socialclass");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 9
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_socialclassRowCount"
                        || d->pins[0].value != 9)
                        ++bad;
                    if ((int)d->tables.size() != 4) ++bad;
                    if (d->tables[0].name
                        != "band_high"
                        || (int)d->tables[0]
                            .values.size() != 9)
                        ++bad;
                    if (d->tables[1].name
                        != "band_low"
                        || (int)d->tables[1]
                            .values.size() != 9)
                        ++bad;
                    if (d->tables[2].name
                        != "roster_count"
                        || (int)d->tables[2]
                            .values.size() != 9)
                        ++bad;
                    if (d->tables[3].name
                        != "roster_offset"
                        || (int)d->tables[3]
                            .values.size() != 9)
                        ++bad;
                    if (d->rows[0].name
                        != "Lower Lower Class") ++bad;
                    if (d->rows[1].name
                        != "Middle Lower Class") ++bad;
                    if (d->rows[2].name
                        != "Upper Lower Class") ++bad;
                    if (d->rows[3].name
                        != "Lower Middle Class") ++bad;
                    if (d->rows[4].name
                        != "Middle Middle Class") ++bad;
                    if (d->rows[5].name
                        != "Upper Middle Class") ++bad;
                    if (d->rows[6].name
                        != "Lower Upper Class") ++bad;
                    if (d->rows[7].name
                        != "Middle Upper Class") ++bad;
                    if (d->rows[8].name
                        != "Upper Upper Class") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_socialclass_abbr");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 9
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_socialclass_abbrRowCount"
                        || d->pins[0].value != 9)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                    if (d->rows[0].name
                        != "LLC") ++bad;
                    if (d->rows[1].name
                        != "MLC") ++bad;
                    if (d->rows[2].name
                        != "ULC") ++bad;
                    if (d->rows[3].name
                        != "LMC") ++bad;
                    if (d->rows[4].name
                        != "MMC") ++bad;
                    if (d->rows[5].name
                        != "UMC") ++bad;
                    if (d->rows[6].name
                        != "LUC") ++bad;
                    if (d->rows[7].name
                        != "MUC") ++bad;
                    if (d->rows[8].name
                        != "UUC") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_socialclass_roster");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 68
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_socialclass_rosterRowCount"
                        || d->pins[0].value != 68)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                    if (d->rows[0].name
                        != "Freed slaves") ++bad;
                    if (d->rows[1].name
                        != "peasants") ++bad;
                    if (d->rows[2].name
                        != "tinkers") ++bad;
                    if (d->rows[3].name
                        != "vagabonds") ++bad;
                    if (d->rows[4].name
                        != "beggars") ++bad;
                    if (d->rows[5].name
                        != "criminals") ++bad;
                    if (d->rows[6].name
                        != "low-level thieves") ++bad;
                    if (d->rows[7].name
                        != "low-level and mid-level assassins") ++bad;
                    if (d->rows[8].name
                        != "herdsmen") ++bad;
                    if (d->rows[9].name
                        != "laborers") ++bad;
                    if (d->rows[10].name
                        != "peddlers") ++bad;
                    if (d->rows[11].name
                        != "actors") ++bad;
                    if (d->rows[12].name
                        != "jugglers") ++bad;
                    if (d->rows[13].name
                        != "men-at-arms") ++bad;
                    if (d->rows[14].name
                        != "low-level barbarians") ++bad;
                    if (d->rows[15].name
                        != "mid-level thieves") ++bad;
                    if (d->rows[16].name
                        != "high-level assassins") ++bad;
                    if (d->rows[17].name
                        != "low-level bards") ++bad;
                    if (d->rows[18].name
                        != "freemen") ++bad;
                    if (d->rows[19].name
                        != "tradesmen") ++bad;
                    if (d->rows[20].name
                        != "petty officers") ++bad;
                    if (d->rows[21].name
                        != "money-changers") ++bad;
                    if (d->rows[22].name
                        != "fences") ++bad;
                    if (d->rows[23].name
                        != "low-level fighters") ++bad;
                    if (d->rows[24].name
                        != "high-level thieves") ++bad;
                    if (d->rows[25].name
                        != "artisans") ++bad;
                    if (d->rows[26].name
                        != "craftsmen") ++bad;
                    if (d->rows[27].name
                        != "petty merchants") ++bad;
                    if (d->rows[28].name
                        != "junior officers") ++bad;
                    if (d->rows[29].name
                        != "bankers") ++bad;
                    if (d->rows[30].name
                        != "landless knights") ++bad;
                    if (d->rows[31].name
                        != "druids") ++bad;
                    if (d->rows[32].name
                        != "rangers") ++bad;
                    if (d->rows[33].name
                        != "landed gentry") ++bad;
                    if (d->rows[34].name
                        != "merchants") ++bad;
                    if (d->rows[35].name
                        != "petty officials") ++bad;
                    if (d->rows[36].name
                        != "senior officers") ++bad;
                    if (d->rows[37].name
                        != "landless petty nobles") ++bad;
                    if (d->rows[38].name
                        != "mid-level fighters") ++bad;
                    if (d->rows[39].name
                        != "low-level magic-users") ++bad;
                    if (d->rows[40].name
                        != "low-level illusionists") ++bad;
                    if (d->rows[41].name
                        != "guild masters") ++bad;
                    if (d->rows[42].name
                        != "great merchants") ++bad;
                    if (d->rows[43].name
                        != "military commanders") ++bad;
                    if (d->rows[44].name
                        != "officials") ++bad;
                    if (d->rows[45].name
                        != "landless nobles") ++bad;
                    if (d->rows[46].name
                        != "lesser clerics") ++bad;
                    if (d->rows[47].name
                        != "high-level fighters") ++bad;
                    if (d->rows[48].name
                        != "mid-level magic-users") ++bad;
                    if (d->rows[49].name
                        != "mid-level illusionists") ++bad;
                    if (d->rows[50].name
                        != "great landed gentry") ++bad;
                    if (d->rows[51].name
                        != "generals and marshals") ++bad;
                    if (d->rows[52].name
                        != "greater officials") ++bad;
                    if (d->rows[53].name
                        != "knights") ++bad;
                    if (d->rows[54].name
                        != "mid-level clerics") ++bad;
                    if (d->rows[55].name
                        != "cavaliers") ++bad;
                    if (d->rows[56].name
                        != "paladins") ++bad;
                    if (d->rows[57].name
                        != "high-level magic-users") ++bad;
                    if (d->rows[58].name
                        != "high-level illusionists") ++bad;
                    if (d->rows[59].name
                        != "knights") ++bad;
                    if (d->rows[60].name
                        != "commanders") ++bad;
                    if (d->rows[61].name
                        != "great clerics") ++bad;
                    if (d->rows[62].name
                        != "nobles") ++bad;
                    if (d->rows[63].name
                        != "high-level paladins") ++bad;
                    if (d->rows[64].name
                        != "very high-level magic-users and illusionists") ++bad;
                    if (d->rows[65].name
                        != "great nobles") ++bad;
                    if (d->rows[66].name
                        != "sovereign nobility") ++bad;
                    if (d->rows[67].name
                        != "royalty") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_birth");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 13
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_birthRowCount"
                        || d->pins[0].value != 13)
                        ++bad;
                    if ((int)d->tables.size() != 2) ++bad;
                    if (d->tables[0].name
                        != "row_high"
                        || (int)d->tables[0]
                            .values.size() != 13)
                        ++bad;
                    if (d->tables[1].name
                        != "row_low"
                        || (int)d->tables[1]
                            .values.size() != 13)
                        ++bad;
                    if (d->rows[0].name
                        != "Only child") ++bad;
                    if (d->rows[1].name
                        != "1st child") ++bad;
                    if (d->rows[2].name
                        != "2nd child") ++bad;
                    if (d->rows[3].name
                        != "3rd child") ++bad;
                    if (d->rows[4].name
                        != "4th child") ++bad;
                    if (d->rows[5].name
                        != "5th child") ++bad;
                    if (d->rows[6].name
                        != "6th child") ++bad;
                    if (d->rows[7].name
                        != "7th child") ++bad;
                    if (d->rows[8].name
                        != "8th child") ++bad;
                    if (d->rows[9].name
                        != "9th child") ++bad;
                    if (d->rows[10].name
                        != "10th child") ++bad;
                    if (d->rows[11].name
                        != "11th child") ++bad;
                    if (d->rows[12].name
                        != "12th child") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_subrace_prefs");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 17
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_subrace_prefsRowCount"
                        || d->pins[0].value != 17)
                        ++bad;
                    if ((int)d->tables.size() != 1) ++bad;
                    if (d->tables[0].name
                        != "pref_matrix"
                        || (int)d->tables[0]
                            .values.size() != 289)
                        ++bad;
                    if (d->rows[0].name
                        != "viewer_1") ++bad;
                    if (d->rows[1].name
                        != "viewer_2") ++bad;
                    if (d->rows[2].name
                        != "viewer_3") ++bad;
                    if (d->rows[3].name
                        != "viewer_4") ++bad;
                    if (d->rows[4].name
                        != "viewer_5") ++bad;
                    if (d->rows[5].name
                        != "viewer_6") ++bad;
                    if (d->rows[6].name
                        != "viewer_7") ++bad;
                    if (d->rows[7].name
                        != "viewer_8") ++bad;
                    if (d->rows[8].name
                        != "viewer_9") ++bad;
                    if (d->rows[9].name
                        != "viewer_10") ++bad;
                    if (d->rows[10].name
                        != "viewer_11") ++bad;
                    if (d->rows[11].name
                        != "viewer_12") ++bad;
                    if (d->rows[12].name
                        != "viewer_13") ++bad;
                    if (d->rows[13].name
                        != "viewer_14") ++bad;
                    if (d->rows[14].name
                        != "viewer_15") ++bad;
                    if (d->rows[15].name
                        != "viewer_16") ++bad;
                    if (d->rows[16].name
                        != "viewer_17") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_subrace_letters");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 6
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ua_subrace_lettersRowCount"
                        || d->pins[0].value != 6)
                        ++bad;
                    if ((int)d->tables.size() != 0) ++bad;
                    if (d->rows[0].name
                        != "P") ++bad;
                    if (d->rows[1].name
                        != "G") ++bad;
                    if (d->rows[2].name
                        != "T") ++bad;
                    if (d->rows[3].name
                        != "N") ++bad;
                    if (d->rows[4].name
                        != "A") ++bad;
                    if (d->rows[5].name
                        != "H") ++bad;
                }
            }
        }
        printf("R1056 uaclasses registry counts audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 3. A -----------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/ua_classes");
            {
                const items::MiscItemDef* d =
                    reg.find("ua_acrobat");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 1000) ++bad;
                    if (d->tables[0]
                        .values[1] != -1) ++bad;
                    if (d->tables[0]
                        .values[2] != 0) ++bad;
                    if (d->tables[0]
                        .values[3] != 2000) ++bad;
                    if (d->tables[0]
                        .values[4] != 1000) ++bad;
                    if (d->tables[0]
                        .values[5] != -1) ++bad;
                    if (d->tables[0]
                        .values[6] != 0) ++bad;
                    if (d->tables[0]
                        .values[7] != 2000) ++bad;
                    if (d->tables[0]
                        .values[8] != 1000) ++bad;
                    if (d->tables[0]
                        .values[9] != 3000) ++bad;
                    if (d->tables[0]
                        .values[10] != 2000) ++bad;
                    if (d->tables[0]
                        .values[11] != 1000) ++bad;
                    if (d->tables[0]
                        .values[12] != 4000) ++bad;
                    if (d->tables[0]
                        .values[13] != 3000) ++bad;
                    if (d->tables[0]
                        .values[14] != 2000) ++bad;
                    if (d->tables[1]
                        .values[0] != 1) ++bad;
                    if (d->tables[1]
                        .values[1] != 2) ++bad;
                    if (d->tables[1]
                        .values[2] != 3) ++bad;
                    if (d->tables[1]
                        .values[3] != 4) ++bad;
                    if (d->tables[2]
                        .values[0] != 2) ++bad;
                    if (d->tables[2]
                        .values[1] != 3) ++bad;
                    if (d->tables[2]
                        .values[2] != 5) ++bad;
                    if (d->tables[2]
                        .values[3] != 8) ++bad;
                    if (d->tables[3]
                        .values[0] != 0) ++bad;
                    if (d->tables[3]
                        .values[1] != 0) ++bad;
                    if (d->tables[3]
                        .values[2] != 5) ++bad;
                    if (d->tables[3]
                        .values[3] != 10) ++bad;
                    if (d->tables[4]
                        .values[0] != 5) ++bad;
                    if (d->tables[4]
                        .values[1] != 10) ++bad;
                    if (d->tables[4]
                        .values[2] != 15) ++bad;
                    if (d->tables[4]
                        .values[3] != 20) ++bad;
                    if (d->tables[5]
                        .values[0] != 0) ++bad;
                    if (d->tables[5]
                        .values[1] != 5) ++bad;
                    if (d->tables[5]
                        .values[2] != 10) ++bad;
                    if (d->tables[5]
                        .values[3] != 15) ++bad;
                    if (d->tables[6]
                        .values[0] != 0) ++bad;
                    if (d->tables[6]
                        .values[1] != 25) ++bad;
                    if (d->tables[6]
                        .values[2] != 50) ++bad;
                    if (d->tables[6]
                        .values[3] != 75) ++bad;
                    if (d->tables[7]
                        .values[0] != 2) ++bad;
                    if (d->tables[7]
                        .values[1] != 3) ++bad;
                    if (d->tables[7]
                        .values[2] != 4) ++bad;
                    if (d->tables[7]
                        .values[3] != 5) ++bad;
                    if (d->tables[8]
                        .values[0] != 6) ++bad;
                    if (d->tables[8]
                        .values[1] != 10) ++bad;
                    if (d->tables[8]
                        .values[2] != 25) ++bad;
                    if (d->tables[8]
                        .values[3] != 7) ++bad;
                    if (d->tables[8]
                        .values[4] != 10) ++bad;
                    if (d->tables[8]
                        .values[5] != 50) ++bad;
                    if (d->tables[8]
                        .values[6] != 8) ++bad;
                    if (d->tables[8]
                        .values[7] != 10) ++bad;
                    if (d->tables[8]
                        .values[8] != 75) ++bad;
                    if (d->tables[8]
                        .values[9] != 9) ++bad;
                    if (d->tables[8]
                        .values[10] != 10) ++bad;
                    if (d->tables[8]
                        .values[11] != 100) ++bad;
                    if (d->tables[8]
                        .values[12] != 9) ++bad;
                    if (d->tables[8]
                        .values[13] != 20) ++bad;
                    if (d->tables[8]
                        .values[14] != 25) ++bad;
                    if (d->tables[8]
                        .values[15] != 13) ++bad;
                    if (d->tables[8]
                        .values[16] != 30) ++bad;
                    if (d->tables[8]
                        .values[17] != 50) ++bad;
                    if (d->tables[8]
                        .values[18] != 14) ++bad;
                    if (d->tables[8]
                        .values[19] != 30) ++bad;
                    if (d->tables[8]
                        .values[20] != 75) ++bad;
                    if (d->tables[8]
                        .values[21] != 15) ++bad;
                    if (d->tables[8]
                        .values[22] != 40) ++bad;
                    if (d->tables[8]
                        .values[23] != 20) ++bad;
                    if (d->tables[8]
                        .values[24] != 16) ++bad;
                    if (d->tables[8]
                        .values[25] != 40) ++bad;
                    if (d->tables[8]
                        .values[26] != 40) ++bad;
                    if (d->tables[8]
                        .values[27] != 17) ++bad;
                    if (d->tables[8]
                        .values[28] != 40) ++bad;
                    if (d->tables[8]
                        .values[29] != 60) ++bad;
                    if (d->tables[8]
                        .values[30] != 18) ++bad;
                    if (d->tables[8]
                        .values[31] != 40) ++bad;
                    if (d->tables[8]
                        .values[32] != 80) ++bad;
                    if (d->tables[8]
                        .values[33] != 19) ++bad;
                    if (d->tables[8]
                        .values[34] != 50) ++bad;
                    if (d->tables[8]
                        .values[35] != 20) ++bad;
                    if (d->tables[8]
                        .values[36] != 20) ++bad;
                    if (d->tables[8]
                        .values[37] != 50) ++bad;
                    if (d->tables[8]
                        .values[38] != 40) ++bad;
                    if (d->tables[8]
                        .values[39] != 21) ++bad;
                    if (d->tables[8]
                        .values[40] != 50) ++bad;
                    if (d->tables[8]
                        .values[41] != 60) ++bad;
                    if (d->tables[8]
                        .values[42] != 22) ++bad;
                    if (d->tables[8]
                        .values[43] != 50) ++bad;
                    if (d->tables[8]
                        .values[44] != 80) ++bad;
                    if (d->tables[8]
                        .values[45] != 23) ++bad;
                    if (d->tables[8]
                        .values[46] != 50) ++bad;
                    if (d->tables[8]
                        .values[47] != 100) ++bad;
                    if (d->tables[8]
                        .values[48] != 23) ++bad;
                    if (d->tables[8]
                        .values[49] != 60) ++bad;
                    if (d->tables[8]
                        .values[50] != 20) ++bad;
                    if (d->tables[9]
                        .values[0] != 20000) ++bad;
                    if (d->tables[9]
                        .values[1] != 45000) ++bad;
                    if (d->tables[9]
                        .values[2] != 75000) ++bad;
                    if (d->tables[9]
                        .values[3] != 125000) ++bad;
                    if (d->tables[9]
                        .values[4] != 180000) ++bad;
                    if (d->tables[9]
                        .values[5] != 250000) ++bad;
                    if (d->tables[9]
                        .values[6] != 500000) ++bad;
                    if (std::string(rules::acrobatFrozenSkillName(0))
                        != "Find Traps") ++bad;
                    if (std::string(rules::acrobatFrozenSkillName(1))
                        != "Pick Pockets") ++bad;
                    if (std::string(rules::acrobatFrozenSkillName(2))
                        != "Open Locks") ++bad;
                    if (std::string(rules::acrobatFrozenSkillName(3))
                        != "Remove Traps") ++bad;
   if (rules::acrobatXpToAttain(6) != 20000) ++bad;
   if (rules::acrobatXpToAttain(7) != 45000) ++bad;
   if (rules::acrobatXpToAttain(8) != 75000) ++bad;
   if (rules::acrobatXpToAttain(9) != 125000) ++bad;
   if (rules::acrobatXpToAttain(10) != 180000) ++bad;
   if (rules::acrobatXpToAttain(11) != 250000) ++bad;
   if (rules::acrobatXpToAttain(12) != 500000) ++bad;
     if (rules::acrobatExtensionFailurePercent(0) != 0) ++bad;
     if (rules::acrobatExtensionFailurePercent(1) != 0) ++bad;
     if (rules::acrobatExtensionFailurePercent(2) != 0) ++bad;
     if (rules::acrobatExtensionFailurePercent(3) != 25) ++bad;
     if (rules::acrobatExtensionFailurePercent(4) != 50) ++bad;
     if (rules::acrobatExtensionFailurePercent(5) != 75) ++bad;
     if (rules::acrobatExtensionRecoverySegments(0) != 2) ++bad;
     if (rules::acrobatExtensionRecoverySegments(1) != 2) ++bad;
     if (rules::acrobatExtensionRecoverySegments(2) != 2) ++bad;
     if (rules::acrobatExtensionRecoverySegments(3) != 3) ++bad;
     if (rules::acrobatExtensionRecoverySegments(4) != 4) ++bad;
     if (rules::acrobatExtensionRecoverySegments(5) != 5) ++bad;
  if (rules::acrobatFootnoteCarryGp(1, 0) != 1000)
            ++bad;
  if (rules::acrobatFootnoteCarryGp(1, 2) != 0)
            ++bad;
  if (rules::acrobatFootnoteCarryGp(5, 0) != 4000)
            ++bad;
  if (rules::acrobatFootnoteCarryGp(5, 2) != 2000)
            ++bad;
      if (rules::acrobatFallingChanceKnown(6, 10) != 25)
          ++bad;
      if (rules::acrobatFallingChanceKnown(7, 10) != 50)
          ++bad;
      if (rules::acrobatFallingChanceKnown(8, 10) != 75)
          ++bad;
      if (rules::acrobatFallingChanceKnown(9, 10) != 100)
          ++bad;
      if (rules::acrobatFallingChanceKnown(9, 20) != 25)
          ++bad;
      if (rules::acrobatFallingChanceKnown(13, 30) != 50)
          ++bad;
      if (rules::acrobatFallingChanceKnown(14, 30) != 75)
          ++bad;
      if (rules::acrobatFallingChanceKnown(15, 40) != 20)
          ++bad;
      if (rules::acrobatFallingChanceKnown(16, 40) != 40)
          ++bad;
      if (rules::acrobatFallingChanceKnown(17, 40) != 60)
          ++bad;
      if (rules::acrobatFallingChanceKnown(18, 40) != 80)
          ++bad;
      if (rules::acrobatFallingChanceKnown(19, 50) != 20)
          ++bad;
      if (rules::acrobatFallingChanceKnown(20, 50) != 40)
          ++bad;
      if (rules::acrobatFallingChanceKnown(21, 50) != 60)
          ++bad;
      if (rules::acrobatFallingChanceKnown(22, 50) != 80)
          ++bad;
      if (rules::acrobatFallingChanceKnown(23, 50) != 100)
          ++bad;
      if (rules::acrobatFallingChanceKnown(23, 60) != 20)
          ++bad;
     if (rules::acrobatDexTightropeBonus(0) != 0) ++bad;
     if (rules::acrobatDexTightropeBonus(1) != 0) ++bad;
     if (rules::acrobatDexTightropeBonus(2) != 0) ++bad;
     if (rules::acrobatDexTightropeBonus(3) != 0) ++bad;
     if (rules::acrobatDexTightropeBonus(4) != 0) ++bad;
     if (rules::acrobatDexTightropeBonus(5) != 0) ++bad;
     if (rules::acrobatDexTightropeBonus(6) != 0) ++bad;
     if (rules::acrobatDexTightropeBonus(7) != 0) ++bad;
     if (rules::acrobatDexTightropeBonus(8) != 0) ++bad;
     if (rules::acrobatDexTightropeBonus(9) != 0) ++bad;
     if (rules::acrobatDexTightropeBonus(10) != 0) ++bad;
     if (rules::acrobatDexTightropeBonus(11) != 0) ++bad;
     if (rules::acrobatDexTightropeBonus(12) != 0) ++bad;
     if (rules::acrobatDexTightropeBonus(13) != 0) ++bad;
     if (rules::acrobatDexTightropeBonus(14) != 0) ++bad;
     if (rules::acrobatDexTightropeBonus(15) != 0) ++bad;
     if (rules::acrobatDexTightropeBonus(16) != 5) ++bad;
     if (rules::acrobatDexTightropeBonus(17) != 10) ++bad;
     if (rules::acrobatDexTightropeBonus(18) != 15) ++bad;
     if (rules::acrobatDexTightropeBonus(19) != 20) ++bad;
     if (rules::acrobatDexPoleVaultBonus(0) != 0) ++bad;
     if (rules::acrobatDexPoleVaultBonus(1) != 0) ++bad;
     if (rules::acrobatDexPoleVaultBonus(2) != 0) ++bad;
     if (rules::acrobatDexPoleVaultBonus(3) != 0) ++bad;
     if (rules::acrobatDexPoleVaultBonus(4) != 0) ++bad;
     if (rules::acrobatDexPoleVaultBonus(5) != 0) ++bad;
     if (rules::acrobatDexPoleVaultBonus(6) != 0) ++bad;
     if (rules::acrobatDexPoleVaultBonus(7) != 0) ++bad;
     if (rules::acrobatDexPoleVaultBonus(8) != 0) ++bad;
     if (rules::acrobatDexPoleVaultBonus(9) != 0) ++bad;
     if (rules::acrobatDexPoleVaultBonus(10) != 0) ++bad;
     if (rules::acrobatDexPoleVaultBonus(11) != 0) ++bad;
     if (rules::acrobatDexPoleVaultBonus(12) != 0) ++bad;
     if (rules::acrobatDexPoleVaultBonus(13) != 0) ++bad;
     if (rules::acrobatDexPoleVaultBonus(14) != 0) ++bad;
     if (rules::acrobatDexPoleVaultBonus(15) != 0) ++bad;
     if (rules::acrobatDexPoleVaultBonus(16) != 0) ++bad;
     if (rules::acrobatDexPoleVaultBonus(17) != 5) ++bad;
     if (rules::acrobatDexPoleVaultBonus(18) != 10) ++bad;
     if (rules::acrobatDexPoleVaultBonus(19) != 15) ++bad;
     if (rules::acrobatDexAttackBonus(0) != 0) ++bad;
     if (rules::acrobatDexAttackBonus(1) != 0) ++bad;
     if (rules::acrobatDexAttackBonus(2) != 0) ++bad;
     if (rules::acrobatDexAttackBonus(3) != 0) ++bad;
     if (rules::acrobatDexAttackBonus(4) != 0) ++bad;
     if (rules::acrobatDexAttackBonus(5) != 0) ++bad;
     if (rules::acrobatDexAttackBonus(6) != 0) ++bad;
     if (rules::acrobatDexAttackBonus(7) != 0) ++bad;
     if (rules::acrobatDexAttackBonus(8) != 0) ++bad;
     if (rules::acrobatDexAttackBonus(9) != 0) ++bad;
     if (rules::acrobatDexAttackBonus(10) != 0) ++bad;
     if (rules::acrobatDexAttackBonus(11) != 0) ++bad;
     if (rules::acrobatDexAttackBonus(12) != 0) ++bad;
     if (rules::acrobatDexAttackBonus(13) != 0) ++bad;
     if (rules::acrobatDexAttackBonus(14) != 0) ++bad;
     if (rules::acrobatDexAttackBonus(15) != 0) ++bad;
     if (rules::acrobatDexAttackBonus(16) != 1) ++bad;
     if (rules::acrobatDexAttackBonus(17) != 2) ++bad;
     if (rules::acrobatDexAttackBonus(18) != 3) ++bad;
     if (rules::acrobatDexAttackBonus(19) != 4) ++bad;
     if (rules::acrobatDexEvasionBonus(0) != 0) ++bad;
     if (rules::acrobatDexEvasionBonus(1) != 0) ++bad;
     if (rules::acrobatDexEvasionBonus(2) != 0) ++bad;
     if (rules::acrobatDexEvasionBonus(3) != 0) ++bad;
     if (rules::acrobatDexEvasionBonus(4) != 0) ++bad;
     if (rules::acrobatDexEvasionBonus(5) != 0) ++bad;
     if (rules::acrobatDexEvasionBonus(6) != 0) ++bad;
     if (rules::acrobatDexEvasionBonus(7) != 0) ++bad;
     if (rules::acrobatDexEvasionBonus(8) != 0) ++bad;
     if (rules::acrobatDexEvasionBonus(9) != 0) ++bad;
     if (rules::acrobatDexEvasionBonus(10) != 0) ++bad;
     if (rules::acrobatDexEvasionBonus(11) != 0) ++bad;
     if (rules::acrobatDexEvasionBonus(12) != 0) ++bad;
     if (rules::acrobatDexEvasionBonus(13) != 0) ++bad;
     if (rules::acrobatDexEvasionBonus(14) != 0) ++bad;
     if (rules::acrobatDexEvasionBonus(15) != 0) ++bad;
     if (rules::acrobatDexEvasionBonus(16) != 2) ++bad;
     if (rules::acrobatDexEvasionBonus(17) != 3) ++bad;
     if (rules::acrobatDexEvasionBonus(18) != 5) ++bad;
     if (rules::acrobatDexEvasionBonus(19) != 8) ++bad;
     if (rules::acrobatDexFallingBonus(0) != 0) ++bad;
     if (rules::acrobatDexFallingBonus(1) != 0) ++bad;
     if (rules::acrobatDexFallingBonus(2) != 0) ++bad;
     if (rules::acrobatDexFallingBonus(3) != 0) ++bad;
     if (rules::acrobatDexFallingBonus(4) != 0) ++bad;
     if (rules::acrobatDexFallingBonus(5) != 0) ++bad;
     if (rules::acrobatDexFallingBonus(6) != 0) ++bad;
     if (rules::acrobatDexFallingBonus(7) != 0) ++bad;
     if (rules::acrobatDexFallingBonus(8) != 0) ++bad;
     if (rules::acrobatDexFallingBonus(9) != 0) ++bad;
     if (rules::acrobatDexFallingBonus(10) != 0) ++bad;
     if (rules::acrobatDexFallingBonus(11) != 0) ++bad;
     if (rules::acrobatDexFallingBonus(12) != 0) ++bad;
     if (rules::acrobatDexFallingBonus(13) != 0) ++bad;
     if (rules::acrobatDexFallingBonus(14) != 0) ++bad;
     if (rules::acrobatDexFallingBonus(15) != 0) ++bad;
     if (rules::acrobatDexFallingBonus(16) != 0) ++bad;
     if (rules::acrobatDexFallingBonus(17) != 0) ++bad;
     if (rules::acrobatDexFallingBonus(18) != 5) ++bad;
     if (rules::acrobatDexFallingBonus(19) != 10) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_acrobat_retained");
                if (!d) { ++bad; } else {
                    if (std::string(rules::acrobatRetainedSkillName(0))
                        != "Move Silently") ++bad;
                    if (std::string(rules::acrobatRetainedSkillName(1))
                        != "Hide in Shadows") ++bad;
                    if (std::string(rules::acrobatRetainedSkillName(2))
                        != "Hear Noise") ++bad;
                    if (std::string(rules::acrobatRetainedSkillName(3))
                        != "Read Languages") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_barbarian");
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
                    if (d->tables[1]
                        .values[0] != 0) ++bad;
                    if (d->tables[1]
                        .values[1] != 6000) ++bad;
                    if (d->tables[1]
                        .values[2] != 12000) ++bad;
                    if (d->tables[1]
                        .values[3] != 24000) ++bad;
                    if (d->tables[1]
                        .values[4] != 48000) ++bad;
                    if (d->tables[1]
                        .values[5] != 80000) ++bad;
                    if (d->tables[1]
                        .values[6] != 150000) ++bad;
                    if (d->tables[1]
                        .values[7] != 275000) ++bad;
                    if (d->tables[1]
                        .values[8] != 500000) ++bad;
                    if (d->tables[1]
                        .values[9] != 1000000) ++bad;
                    if (d->tables[1]
                        .values[10] != 1500000) ++bad;
                    if (std::string(rules::barbarianTertiaryName(0))
                        != "Animal Handling") ++bad;
                    if (std::string(rules::barbarianTertiaryName(1))
                        != "Horsemanship") ++bad;
                    if (std::string(rules::barbarianTertiaryName(2))
                        != "Long-Distance Signaling") ++bad;
                    if (std::string(rules::barbarianTertiaryName(3))
                        != "Running") ++bad;
                    if (std::string(rules::barbarianTertiaryName(4))
                        != "Small Craft (Paddled and Rowed)") ++bad;
                    if (std::string(rules::barbarianTertiaryName(5))
                        != "Sound Imitation") ++bad;
                    if (std::string(rules::barbarianTertiaryName(6))
                        != "Snare Building") ++bad;
   if (rules::barbarianXpToAttain(1) != 0) ++bad;
   if (rules::barbarianXpToAttain(2) != 6000) ++bad;
   if (rules::barbarianXpToAttain(3) != 12000) ++bad;
   if (rules::barbarianXpToAttain(4) != 24000) ++bad;
   if (rules::barbarianXpToAttain(5) != 48000) ++bad;
   if (rules::barbarianXpToAttain(6) != 80000) ++bad;
   if (rules::barbarianXpToAttain(7) != 150000) ++bad;
   if (rules::barbarianXpToAttain(8) != 275000) ++bad;
   if (rules::barbarianXpToAttain(9) != 500000) ++bad;
   if (rules::barbarianXpToAttain(10) != 1000000) ++bad;
   if (rules::barbarianXpToAttain(11) != 1500000) ++bad;
     if (rules::barbarianStrikeLevel(0) != 4) ++bad;
     if (rules::barbarianStrikeLevel(1) != 4) ++bad;
     if (rules::barbarianStrikeLevel(2) != 6) ++bad;
     if (rules::barbarianStrikeLevel(3) != 8) ++bad;
     if (rules::barbarianStrikeLevel(4) != 10) ++bad;
     if (rules::barbarianStrikeLevel(5) != 12) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_barbarian_weapons");
                if (!d) { ++bad; } else {
                    if (std::string(rules::barbarianRequiredWeaponName(0))
                        != "Hand Axe") ++bad;
                    if (std::string(rules::barbarianRequiredWeaponName(1))
                        != "Knife") ++bad;
                    if (std::string(rules::barbarianRequiredWeaponName(2))
                        != "Spear") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_cavalier");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 3) ++bad;
                    if (d->tables[0]
                        .values[1] != 4) ++bad;
                    if (d->tables[0]
                        .values[2] != 5) ++bad;
                    if (d->tables[0]
                        .values[3] != 7) ++bad;
                    if (d->tables[0]
                        .values[4] != 9) ++bad;
                    if (d->tables[0]
                        .values[5] != 11) ++bad;
                    if (d->tables[1]
                        .values[0] != 0) ++bad;
                    if (d->tables[1]
                        .values[1] != 2500) ++bad;
                    if (d->tables[1]
                        .values[2] != 5000) ++bad;
                    if (d->tables[1]
                        .values[3] != 10000) ++bad;
                    if (d->tables[1]
                        .values[4] != 18500) ++bad;
                    if (d->tables[1]
                        .values[5] != 37000) ++bad;
                    if (d->tables[1]
                        .values[6] != 85000) ++bad;
                    if (d->tables[1]
                        .values[7] != 140000) ++bad;
                    if (d->tables[1]
                        .values[8] != 220000) ++bad;
                    if (d->tables[1]
                        .values[9] != 300000) ++bad;
                    if (d->tables[1]
                        .values[10] != 600000) ++bad;
                    if (d->tables[1]
                        .values[11] != 900000) ++bad;
                    if (std::string(rules::cavalierPreferredWeaponName(0))
                        != "lance") ++bad;
                    if (std::string(rules::cavalierPreferredWeaponName(1))
                        != "long sword") ++bad;
                    if (std::string(rules::cavalierPreferredWeaponName(2))
                        != "broad sword") ++bad;
                    if (std::string(rules::cavalierPreferredWeaponName(3))
                        != "bastard sword") ++bad;
                    if (std::string(rules::cavalierPreferredWeaponName(4))
                        != "short sword") ++bad;
                    if (std::string(rules::cavalierPreferredWeaponName(5))
                        != "horseman's mace") ++bad;
                    if (std::string(rules::cavalierPreferredWeaponName(6))
                        != "horseman's flail") ++bad;
                    if (std::string(rules::cavalierPreferredWeaponName(7))
                        != "horseman's military pick") ++bad;
                    if (std::string(rules::cavalierPreferredWeaponName(8))
                        != "dagger") ++bad;
                    if (std::string(rules::cavalierPreferredWeaponName(9))
                        != "scimitar") ++bad;
                    if (std::string(rules::cavalierPreferredWeaponName(10))
                        != "javelin") ++bad;
   if (rules::cavalierXpToAttain(1) != 0) ++bad;
   if (rules::cavalierXpToAttain(2) != 2500) ++bad;
   if (rules::cavalierXpToAttain(3) != 5000) ++bad;
   if (rules::cavalierXpToAttain(4) != 10000) ++bad;
   if (rules::cavalierXpToAttain(5) != 18500) ++bad;
   if (rules::cavalierXpToAttain(6) != 37000) ++bad;
   if (rules::cavalierXpToAttain(7) != 85000) ++bad;
   if (rules::cavalierXpToAttain(8) != 140000) ++bad;
   if (rules::cavalierXpToAttain(9) != 220000) ++bad;
   if (rules::cavalierXpToAttain(10) != 300000) ++bad;
   if (rules::cavalierXpToAttain(11) != 600000) ++bad;
   if (rules::cavalierXpToAttain(12) != 900000) ++bad;
     if (rules::cavalierHorsemanshipLevel(0) != 3) ++bad;
     if (rules::cavalierHorsemanshipLevel(1) != 4) ++bad;
     if (rules::cavalierHorsemanshipLevel(2) != 5) ++bad;
     if (rules::cavalierHorsemanshipLevel(3) != 7) ++bad;
     if (rules::cavalierHorsemanshipLevel(4) != 9) ++bad;
     if (rules::cavalierHorsemanshipLevel(5) != 11) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_cavalier_mind");
                if (!d) { ++bad; } else {
                    if (std::string(rules::cavalierMindPowerName(0))
                        != "beguiling") ++bad;
                    if (std::string(rules::cavalierMindPowerName(1))
                        != "charm") ++bad;
                    if (std::string(rules::cavalierMindPowerName(2))
                        != "domination") ++bad;
                    if (std::string(rules::cavalierMindPowerName(3))
                        != "hold") ++bad;
                    if (std::string(rules::cavalierMindPowerName(4))
                        != "hypnosis") ++bad;
                    if (std::string(rules::cavalierMindPowerName(5))
                        != "magic jar") ++bad;
                    if (std::string(rules::cavalierMindPowerName(6))
                        != "possession") ++bad;
                    if (std::string(rules::cavalierMindPowerName(7))
                        != "sleep") ++bad;
                    if (std::string(rules::cavalierMindPowerName(8))
                        != "suggestion") ++bad;
                    if (std::string(rules::cavalierMindPowerName(9))
                        != "psionic mind blast") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_cavmoney");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 0) ++bad;
                    if (d->tables[0]
                        .values[1] != 0) ++bad;
                    if (d->tables[0]
                        .values[2] != 0) ++bad;
                    if (d->tables[0]
                        .values[3] != 6) ++bad;
                    if (d->tables[0]
                        .values[4] != 6) ++bad;
                    if (d->tables[0]
                        .values[5] != 12) ++bad;
                    if (d->tables[1]
                        .values[0] != 0) ++bad;
                    if (d->tables[1]
                        .values[1] != 0) ++bad;
                    if (d->tables[1]
                        .values[2] != 0) ++bad;
                    if (d->tables[1]
                        .values[3] != 1) ++bad;
                    if (d->tables[1]
                        .values[4] != 1) ++bad;
                    if (d->tables[1]
                        .values[5] != 1) ++bad;
                    if (d->tables[2]
                        .values[0] != 0) ++bad;
                    if (d->tables[2]
                        .values[1] != 0) ++bad;
                    if (d->tables[2]
                        .values[2] != 0) ++bad;
                    if (d->tables[2]
                        .values[3] != 12) ++bad;
                    if (d->tables[2]
                        .values[4] != 6) ++bad;
                    if (d->tables[2]
                        .values[5] != 6) ++bad;
                    if (d->tables[3]
                        .values[0] != 80) ++bad;
                    if (d->tables[3]
                        .values[1] != 80) ++bad;
                    if (d->tables[3]
                        .values[2] != 80) ++bad;
                    if (d->tables[3]
                        .values[3] != 180) ++bad;
                    if (d->tables[3]
                        .values[4] != 180) ++bad;
                    if (d->tables[3]
                        .values[5] != 180) ++bad;
                    if (d->tables[4]
                        .values[0] != 20) ++bad;
                    if (d->tables[4]
                        .values[1] != 20) ++bad;
                    if (d->tables[4]
                        .values[2] != 20) ++bad;
                    if (d->tables[4]
                        .values[3] != 70) ++bad;
                    if (d->tables[4]
                        .values[4] != 70) ++bad;
                    if (d->tables[4]
                        .values[5] != 130) ++bad;
                    if (d->tables[5]
                        .values[0] != 3) ++bad;
                    if (d->tables[5]
                        .values[1] != 4) ++bad;
                    if (d->tables[5]
                        .values[2] != 4) ++bad;
                    if (d->tables[5]
                        .values[3] != 6) ++bad;
                    if (d->tables[5]
                        .values[4] != 6) ++bad;
                    if (d->tables[5]
                        .values[5] != 7) ++bad;
                    if (std::string(rules::cavMoneyStationName(0))
                        != "Lower Middle Class or less") ++bad;
                    if (std::string(rules::cavMoneyStationName(1))
                        != "Middle Middle Class") ++bad;
                    if (std::string(rules::cavMoneyStationName(2))
                        != "Upper Middle Class") ++bad;
                    if (std::string(rules::cavMoneyStationName(3))
                        != "Lower Upper Class") ++bad;
                    if (std::string(rules::cavMoneyStationName(4))
                        != "Middle Upper Class") ++bad;
                    if (std::string(rules::cavMoneyStationName(5))
                        != "Upper Upper Class") ++bad;
     if (rules::cavMoneyGoldLow(0) != 20) ++bad;
     if (rules::cavMoneyGoldLow(1) != 20) ++bad;
     if (rules::cavMoneyGoldLow(2) != 20) ++bad;
     if (rules::cavMoneyGoldLow(3) != 70) ++bad;
     if (rules::cavMoneyGoldLow(4) != 70) ++bad;
     if (rules::cavMoneyGoldLow(5) != 130) ++bad;
     if (rules::cavMoneyGoldHigh(0) != 80) ++bad;
     if (rules::cavMoneyGoldHigh(1) != 80) ++bad;
     if (rules::cavMoneyGoldHigh(2) != 80) ++bad;
     if (rules::cavMoneyGoldHigh(3) != 180) ++bad;
     if (rules::cavMoneyGoldHigh(4) != 180) ++bad;
     if (rules::cavMoneyGoldHigh(5) != 180) ++bad;
     if (rules::cavMoneyDiceCount(0) != 0) ++bad;
     if (rules::cavMoneyDiceCount(1) != 0) ++bad;
     if (rules::cavMoneyDiceCount(2) != 0) ++bad;
     if (rules::cavMoneyDiceCount(3) != 1) ++bad;
     if (rules::cavMoneyDiceCount(4) != 1) ++bad;
     if (rules::cavMoneyDiceCount(5) != 1) ++bad;
     if (rules::cavMoneyDiceFaces(0) != 0) ++bad;
     if (rules::cavMoneyDiceFaces(1) != 0) ++bad;
     if (rules::cavMoneyDiceFaces(2) != 0) ++bad;
     if (rules::cavMoneyDiceFaces(3) != 12) ++bad;
     if (rules::cavMoneyDiceFaces(4) != 6) ++bad;
     if (rules::cavMoneyDiceFaces(5) != 6) ++bad;
     if (rules::cavMoneyDiceBonus(0) != 0) ++bad;
     if (rules::cavMoneyDiceBonus(1) != 0) ++bad;
     if (rules::cavMoneyDiceBonus(2) != 0) ++bad;
     if (rules::cavMoneyDiceBonus(3) != 6) ++bad;
     if (rules::cavMoneyDiceBonus(4) != 6) ++bad;
     if (rules::cavMoneyDiceBonus(5) != 12) ++bad;
     if (rules::cavMoneyItemCount(0) != 3) ++bad;
     if (rules::cavMoneyItemCount(1) != 4) ++bad;
     if (rules::cavMoneyItemCount(2) != 4) ++bad;
     if (rules::cavMoneyItemCount(3) != 6) ++bad;
     if (rules::cavMoneyItemCount(4) != 6) ++bad;
     if (rules::cavMoneyItemCount(5) != 7) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_cavmoney_entry");
                if (!d) { ++bad; } else {
                    if (std::string(rules::cavMoneyStationEntry(0))
                        != "Horseman") ++bad;
                    if (std::string(rules::cavMoneyStationEntry(1))
                        != "Horseman") ++bad;
                    if (std::string(rules::cavMoneyStationEntry(2))
                        != "Horseman") ++bad;
                    if (std::string(rules::cavMoneyStationEntry(3))
                        != "Cavalier") ++bad;
                    if (std::string(rules::cavMoneyStationEntry(4))
                        != "Cavalier") ++bad;
                    if (std::string(rules::cavMoneyStationEntry(5))
                        != "Cavalier") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_cavmoney_items");
                if (!d) { ++bad; } else {
                }
            }
        }
        printf("R1056 uaclasses registry defs-A audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 4. B -----------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/ua_classes");
            {
                const items::MiscItemDef* d =
                    reg.find("ua_hierophant");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 85) ++bad;
                    if (d->tables[0]
                        .values[1] != 94) ++bad;
                    if (d->tables[0]
                        .values[2] != 98) ++bad;
                    if (d->tables[0]
                        .values[3] != 100) ++bad;
                    if (d->tables[0]
                        .values[4] != 85) ++bad;
                    if (d->tables[0]
                        .values[5] != 94) ++bad;
                    if (d->tables[0]
                        .values[6] != 98) ++bad;
                    if (d->tables[0]
                        .values[7] != 100) ++bad;
                    if (d->tables[0]
                        .values[8] != 85) ++bad;
                    if (d->tables[0]
                        .values[9] != 94) ++bad;
                    if (d->tables[0]
                        .values[10] != 98) ++bad;
                    if (d->tables[0]
                        .values[11] != 100) ++bad;
                    if (d->tables[0]
                        .values[12] != 85) ++bad;
                    if (d->tables[0]
                        .values[13] != 94) ++bad;
                    if (d->tables[0]
                        .values[14] != 98) ++bad;
                    if (d->tables[0]
                        .values[15] != 100) ++bad;
                    if (d->tables[0]
                        .values[16] != 85) ++bad;
                    if (d->tables[0]
                        .values[17] != 95) ++bad;
                    if (d->tables[0]
                        .values[18] != 100) ++bad;
                    if (d->tables[0]
                        .values[19] != 0) ++bad;
                    if (d->tables[1]
                        .values[0] != 1) ++bad;
                    if (d->tables[1]
                        .values[1] != 86) ++bad;
                    if (d->tables[1]
                        .values[2] != 95) ++bad;
                    if (d->tables[1]
                        .values[3] != 99) ++bad;
                    if (d->tables[1]
                        .values[4] != 1) ++bad;
                    if (d->tables[1]
                        .values[5] != 86) ++bad;
                    if (d->tables[1]
                        .values[6] != 95) ++bad;
                    if (d->tables[1]
                        .values[7] != 99) ++bad;
                    if (d->tables[1]
                        .values[8] != 1) ++bad;
                    if (d->tables[1]
                        .values[9] != 86) ++bad;
                    if (d->tables[1]
                        .values[10] != 95) ++bad;
                    if (d->tables[1]
                        .values[11] != 99) ++bad;
                    if (d->tables[1]
                        .values[12] != 1) ++bad;
                    if (d->tables[1]
                        .values[13] != 86) ++bad;
                    if (d->tables[1]
                        .values[14] != 95) ++bad;
                    if (d->tables[1]
                        .values[15] != 99) ++bad;
                    if (d->tables[1]
                        .values[16] != 1) ++bad;
                    if (d->tables[1]
                        .values[17] != 86) ++bad;
                    if (d->tables[1]
                        .values[18] != 96) ++bad;
                    if (d->tables[1]
                        .values[19] != 0) ++bad;
                    if (d->tables[2]
                        .values[0] != 1) ++bad;
                    if (d->tables[2]
                        .values[1] != 500001) ++bad;
                    if (d->tables[2]
                        .values[2] != 1000001) ++bad;
                    if (d->tables[2]
                        .values[3] != 1500001) ++bad;
                    if (d->tables[2]
                        .values[4] != 2000001) ++bad;
                    if (d->tables[2]
                        .values[5] != 2500001) ++bad;
                    if (d->tables[2]
                        .values[6] != 3000001) ++bad;
                    if (d->tables[2]
                        .values[7] != 3500001) ++bad;
   if (rules::hierophantXpBandLow(16) != 1) ++bad;
   if (rules::hierophantXpBandLow(17) != 500001) ++bad;
   if (rules::hierophantXpBandLow(18) != 1000001) ++bad;
   if (rules::hierophantXpBandLow(19) != 1500001) ++bad;
   if (rules::hierophantXpBandLow(20) != 2000001) ++bad;
   if (rules::hierophantXpBandLow(21) != 2500001) ++bad;
   if (rules::hierophantXpBandLow(22) != 3000001) ++bad;
   if (rules::hierophantXpBandLow(23) != 3500001) ++bad;
  if (rules::hierophantConjureLow(0, 0) != 1)
            ++bad;
  if (rules::hierophantConjureLow(0, 3) != 99)
            ++bad;
  if (rules::hierophantConjureLow(4, 0) != 1)
            ++bad;
  if (rules::hierophantConjureLow(4, 3) != 0)
            ++bad;
  if (rules::hierophantConjureHigh(0, 0) != 85)
            ++bad;
  if (rules::hierophantConjureHigh(0, 3) != 100)
            ++bad;
  if (rules::hierophantConjureHigh(4, 0) != 85)
            ++bad;
  if (rules::hierophantConjureHigh(4, 3) != 0)
            ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_hierophant_conjure");
                if (!d) { ++bad; } else {
          if (std::string(rules::hierophantConjureName(0, 0))
          != "16 HD fire elemental") ++bad;
          if (std::string(rules::hierophantConjureName(0, 1))
          != "2-4 salamanders") ++bad;
          if (std::string(rules::hierophantConjureName(0, 2))
          != "1 efreeti") ++bad;
          if (std::string(rules::hierophantConjureName(0, 3))
          != "21-24 HD fire elemental") ++bad;
          if (std::string(rules::hierophantConjureName(1, 0))
          != "earth elemental") ++bad;
          if (std::string(rules::hierophantConjureName(1, 1))
          != "2-4 xorn") ++bad;
          if (std::string(rules::hierophantConjureName(1, 2))
          != "1 dao") ++bad;
          if (std::string(rules::hierophantConjureName(1, 3))
          != "21-24 HD earth elemental") ++bad;
          if (std::string(rules::hierophantConjureName(2, 0))
          != "16 HD water elemental") ++bad;
          if (std::string(rules::hierophantConjureName(2, 1))
          != "7-12 tritons on hippocampi") ++bad;
          if (std::string(rules::hierophantConjureName(2, 2))
          != "1 marid") ++bad;
          if (std::string(rules::hierophantConjureName(2, 3))
          != "21-24 HD water elemental") ++bad;
          if (std::string(rules::hierophantConjureName(3, 0))
          != "16 HD air elemental") ++bad;
          if (std::string(rules::hierophantConjureName(3, 1))
          != "2-4 invisible stalkers") ++bad;
          if (std::string(rules::hierophantConjureName(3, 2))
          != "1 djinni") ++bad;
          if (std::string(rules::hierophantConjureName(3, 3))
          != "21-24 HD air elemental") ++bad;
          if (std::string(rules::hierophantConjureName(4, 0))
          != "16 HD para-elemental") ++bad;
          if (std::string(rules::hierophantConjureName(4, 1))
          != "special") ++bad;
          if (std::string(rules::hierophantConjureName(4, 2))
          != "21-24 HD para-elemental") ++bad;
          if (std::string(rules::hierophantConjureName(4, 3))
          != "") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_hierophant_special");
                if (!d) { ++bad; } else {
                    if (std::string(rules::hierophantConjureSpecialName(0))
                        != "5-8 lava children") ++bad;
                    if (std::string(rules::hierophantConjureSpecialName(1))
                        != "5-8 winter wolves") ++bad;
                    if (std::string(rules::hierophantConjureSpecialName(2))
                        != "21-24 mudmen") ++bad;
                    if (std::string(rules::hierophantConjureSpecialName(3))
                        != "21-24 vapor rats") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_paladin");
                if (!d) { ++bad; } else {
                    if (std::string(rules::paladinCavalierAbilityName(0))
                        != "weapons of choice") ++bad;
                    if (std::string(rules::paladinCavalierAbilityName(1))
                        != "parrying ability") ++bad;
                    if (std::string(rules::paladinCavalierAbilityName(2))
                        != "horsemanship") ++bad;
                    if (std::string(rules::paladinCavalierAbilityName(3))
                        != "saving throw bonuses") ++bad;
                    if (std::string(rules::paladinCavalierAbilityName(4))
                        != "immunity to fear") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_classtables");
                if (!d) { ++bad; } else {
                    if (std::string(rules::acrobatExtraWeaponName(0))
                        != "lasso") ++bad;
                    if (std::string(rules::acrobatExtraWeaponName(1))
                        != "staff") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_cavtable");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 2500) ++bad;
                    if (d->tables[0]
                        .values[1] != 5000) ++bad;
                    if (d->tables[0]
                        .values[2] != 10000) ++bad;
                    if (d->tables[0]
                        .values[3] != 18500) ++bad;
                    if (d->tables[0]
                        .values[4] != 37000) ++bad;
                    if (d->tables[0]
                        .values[5] != 85000) ++bad;
                    if (d->tables[0]
                        .values[6] != 140000) ++bad;
                    if (d->tables[0]
                        .values[7] != 220000) ++bad;
                    if (d->tables[0]
                        .values[8] != 300000) ++bad;
                    if (d->tables[0]
                        .values[9] != 600000) ++bad;
                    if (d->tables[0]
                        .values[10] != 900000) ++bad;
                    if (d->tables[0]
                        .values[11] != 0) ++bad;
                    if (d->tables[1]
                        .values[0] != 0) ++bad;
                    if (d->tables[1]
                        .values[1] != 2501) ++bad;
                    if (d->tables[1]
                        .values[2] != 5001) ++bad;
                    if (d->tables[1]
                        .values[3] != 10001) ++bad;
                    if (d->tables[1]
                        .values[4] != 18501) ++bad;
                    if (d->tables[1]
                        .values[5] != 37001) ++bad;
                    if (d->tables[1]
                        .values[6] != 85001) ++bad;
                    if (d->tables[1]
                        .values[7] != 140001) ++bad;
                    if (d->tables[1]
                        .values[8] != 220001) ++bad;
                    if (d->tables[1]
                        .values[9] != 300001) ++bad;
                    if (d->tables[1]
                        .values[10] != 600001) ++bad;
                    if (d->tables[1]
                        .values[11] != 900001) ++bad;
     if (rules::uacavtLevelXpLow(0) != 0) ++bad;
     if (rules::uacavtLevelXpLow(1) != 0) ++bad;
     if (rules::uacavtLevelXpLow(2) != 2501) ++bad;
     if (rules::uacavtLevelXpLow(3) != 5001) ++bad;
     if (rules::uacavtLevelXpLow(4) != 10001) ++bad;
     if (rules::uacavtLevelXpLow(5) != 18501) ++bad;
     if (rules::uacavtLevelXpLow(6) != 37001) ++bad;
     if (rules::uacavtLevelXpLow(7) != 85001) ++bad;
     if (rules::uacavtLevelXpLow(8) != 140001) ++bad;
     if (rules::uacavtLevelXpLow(9) != 220001) ++bad;
     if (rules::uacavtLevelXpLow(10) != 300001) ++bad;
     if (rules::uacavtLevelXpLow(11) != 600001) ++bad;
     if (rules::uacavtLevelXpLow(12) != 900001) ++bad;
     if (rules::uacavtLevelXpHigh(0) != 2500) ++bad;
     if (rules::uacavtLevelXpHigh(1) != 2500) ++bad;
     if (rules::uacavtLevelXpHigh(2) != 5000) ++bad;
     if (rules::uacavtLevelXpHigh(3) != 10000) ++bad;
     if (rules::uacavtLevelXpHigh(4) != 18500) ++bad;
     if (rules::uacavtLevelXpHigh(5) != 37000) ++bad;
     if (rules::uacavtLevelXpHigh(6) != 85000) ++bad;
     if (rules::uacavtLevelXpHigh(7) != 140000) ++bad;
     if (rules::uacavtLevelXpHigh(8) != 220000) ++bad;
     if (rules::uacavtLevelXpHigh(9) != 300000) ++bad;
     if (rules::uacavtLevelXpHigh(10) != 600000) ++bad;
     if (rules::uacavtLevelXpHigh(11) != 900000) ++bad;
     if (rules::uacavtLevelXpHigh(12) != 0) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_followers");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 1) ++bad;
                    if (d->tables[0]
                        .values[1] != 2) ++bad;
                    if (d->tables[0]
                        .values[2] != 3) ++bad;
                    if (d->tables[0]
                        .values[3] != 6) ++bad;
                    if (d->tables[0]
                        .values[4] != 12) ++bad;
                    if (d->tables[0]
                        .values[5] != 24) ++bad;
                    if (d->tables[0]
                        .values[6] != 48) ++bad;
                    if (d->tables[1]
                        .values[0] != 50) ++bad;
                    if (d->tables[1]
                        .values[1] != 75) ++bad;
                    if (d->tables[1]
                        .values[2] != 90) ++bad;
                    if (d->tables[1]
                        .values[3] != 100) ++bad;
                    if (d->tables[2]
                        .values[0] != 1) ++bad;
                    if (d->tables[2]
                        .values[1] != 51) ++bad;
                    if (d->tables[2]
                        .values[2] != 76) ++bad;
                    if (d->tables[2]
                        .values[3] != 91) ++bad;
   if (rules::uafolDiceCount(4) != 1) ++bad;
   if (rules::uafolDiceCount(5) != 2) ++bad;
   if (rules::uafolDiceCount(6) != 3) ++bad;
   if (rules::uafolDiceCount(7) != 6) ++bad;
   if (rules::uafolDiceCount(8) != 12) ++bad;
   if (rules::uafolDiceCount(9) != 24) ++bad;
   if (rules::uafolDiceCount(10) != 48) ++bad;
     if (rules::uafolEquipRowLo(0) != 1) ++bad;
     if (rules::uafolEquipRowLo(1) != 51) ++bad;
     if (rules::uafolEquipRowLo(2) != 76) ++bad;
     if (rules::uafolEquipRowLo(3) != 91) ++bad;
     if (rules::uafolEquipRowHi(0) != 50) ++bad;
     if (rules::uafolEquipRowHi(1) != 75) ++bad;
     if (rules::uafolEquipRowHi(2) != 90) ++bad;
     if (rules::uafolEquipRowHi(3) != 100) ++bad;
                }
            }
        }
        printf("R1056 uaclasses registry defs-B audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 5. C -----------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/ua_classes");
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ranger");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 20) ++bad;
                    if (d->tables[0]
                        .values[1] != 10) ++bad;
                    if (d->tables[0]
                        .values[2] != 0) ++bad;
                    if (d->tables[0]
                        .values[3] != -50) ++bad;
                    if (std::string(rules::uaRangerGiantRosterName(0))
                        != "bugbear") ++bad;
                    if (std::string(rules::uaRangerGiantRosterName(1))
                        != "cyclopskin") ++bad;
                    if (std::string(rules::uaRangerGiantRosterName(2))
                        != "dune stalker") ++bad;
                    if (std::string(rules::uaRangerGiantRosterName(3))
                        != "ettin") ++bad;
                    if (std::string(rules::uaRangerGiantRosterName(4))
                        != "flind") ++bad;
                    if (std::string(rules::uaRangerGiantRosterName(5))
                        != "gibberling") ++bad;
                    if (std::string(rules::uaRangerGiantRosterName(6))
                        != "giant") ++bad;
                    if (std::string(rules::uaRangerGiantRosterName(7))
                        != "gnoll") ++bad;
                    if (std::string(rules::uaRangerGiantRosterName(8))
                        != "goblin") ++bad;
                    if (std::string(rules::uaRangerGiantRosterName(9))
                        != "grimlock") ++bad;
                    if (std::string(rules::uaRangerGiantRosterName(10))
                        != "hobgoblin") ++bad;
                    if (std::string(rules::uaRangerGiantRosterName(11))
                        != "kobold") ++bad;
                    if (std::string(rules::uaRangerGiantRosterName(12))
                        != "meazel") ++bad;
                    if (std::string(rules::uaRangerGiantRosterName(13))
                        != "norker") ++bad;
                    if (std::string(rules::uaRangerGiantRosterName(14))
                        != "ogre") ++bad;
                    if (std::string(rules::uaRangerGiantRosterName(15))
                        != "ogre mage") ++bad;
                    if (std::string(rules::uaRangerGiantRosterName(16))
                        != "ogrillon") ++bad;
                    if (std::string(rules::uaRangerGiantRosterName(17))
                        != "orc") ++bad;
                    if (std::string(rules::uaRangerGiantRosterName(18))
                        != "quaggoth") ++bad;
                    if (std::string(rules::uaRangerGiantRosterName(19))
                        != "tasloi") ++bad;
                    if (std::string(rules::uaRangerGiantRosterName(20))
                        != "troll") ++bad;
                    if (std::string(rules::uaRangerGiantRosterName(21))
                        != "xvart") ++bad;
     if (rules::uaRangerTrackTerrainModifier(0) != 20) ++bad;
     if (rules::uaRangerTrackTerrainModifier(1) != 10) ++bad;
     if (rules::uaRangerTrackTerrainModifier(2) != 0) ++bad;
     if (rules::uaRangerTrackTerrainModifier(3) != -50) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ranger_identify");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uaRangerTrackIdentifyAbility(1))
                        != "Common woodland creatures' tracks and direction of travel") ++bad;
                    if (std::string(rules::uaRangerTrackIdentifyAbility(2))
                        != "Common woodland creatures' number and pace") ++bad;
                    if (std::string(rules::uaRangerTrackIdentifyAbility(3))
                        != "Common woodland creatures' time of passage (outdoors only)") ++bad;
                    if (std::string(rules::uaRangerTrackIdentifyAbility(4))
                        != "As 3rd level with respect to uncommon woodland creatures") ++bad;
                    if (std::string(rules::uaRangerTrackIdentifyAbility(5))
                        != "As 3rd level with respect to rare woodland creatures") ++bad;
                    if (std::string(rules::uaRangerTrackIdentifyAbility(6))
                        != "As 3rd level with respect to very rare woodland creatures") ++bad;
                    if (std::string(rules::uaRangerTrackIdentifyAbility(7))
                        != "As 3rd level with respect to all sorts of creatures (woodland and otherwise) within a 100-mile radius") ++bad;
                    if (std::string(rules::uaRangerTrackIdentifyAbility(8))
                        != "As 7th level, plus the ability to determine the general size and weight of humans") ++bad;
                    if (std::string(rules::uaRangerTrackIdentifyAbility(9))
                        != "As 8th level, plus the ability to determine the size and numbers of mounted creatures") ++bad;
                    if (std::string(rules::uaRangerTrackIdentifyAbility(10))
                        != "As 9th level with respect to all creatures ever observed, prior to attaining 10th level or subsequently") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_socialclass");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 4) ++bad;
                    if (d->tables[0]
                        .values[1] != 10) ++bad;
                    if (d->tables[0]
                        .values[2] != 20) ++bad;
                    if (d->tables[0]
                        .values[3] != 35) ++bad;
                    if (d->tables[0]
                        .values[4] != 55) ++bad;
                    if (d->tables[0]
                        .values[5] != 87) ++bad;
                    if (d->tables[0]
                        .values[6] != 96) ++bad;
                    if (d->tables[0]
                        .values[7] != 99) ++bad;
                    if (d->tables[0]
                        .values[8] != 100) ++bad;
                    if (d->tables[1]
                        .values[0] != 1) ++bad;
                    if (d->tables[1]
                        .values[1] != 5) ++bad;
                    if (d->tables[1]
                        .values[2] != 11) ++bad;
                    if (d->tables[1]
                        .values[3] != 21) ++bad;
                    if (d->tables[1]
                        .values[4] != 36) ++bad;
                    if (d->tables[1]
                        .values[5] != 56) ++bad;
                    if (d->tables[1]
                        .values[6] != 88) ++bad;
                    if (d->tables[1]
                        .values[7] != 97) ++bad;
                    if (d->tables[1]
                        .values[8] != 100) ++bad;
                    if (d->tables[2]
                        .values[0] != 8) ++bad;
                    if (d->tables[2]
                        .values[1] != 10) ++bad;
                    if (d->tables[2]
                        .values[2] != 7) ++bad;
                    if (d->tables[2]
                        .values[3] != 8) ++bad;
                    if (d->tables[2]
                        .values[4] != 8) ++bad;
                    if (d->tables[2]
                        .values[5] != 9) ++bad;
                    if (d->tables[2]
                        .values[6] != 9) ++bad;
                    if (d->tables[2]
                        .values[7] != 6) ++bad;
                    if (d->tables[2]
                        .values[8] != 3) ++bad;
                    if (std::string(rules::uasocBandFullName(0))
                        != "Lower Lower Class") ++bad;
                    if (std::string(rules::uasocBandFullName(1))
                        != "Middle Lower Class") ++bad;
                    if (std::string(rules::uasocBandFullName(2))
                        != "Upper Lower Class") ++bad;
                    if (std::string(rules::uasocBandFullName(3))
                        != "Lower Middle Class") ++bad;
                    if (std::string(rules::uasocBandFullName(4))
                        != "Middle Middle Class") ++bad;
                    if (std::string(rules::uasocBandFullName(5))
                        != "Upper Middle Class") ++bad;
                    if (std::string(rules::uasocBandFullName(6))
                        != "Lower Upper Class") ++bad;
                    if (std::string(rules::uasocBandFullName(7))
                        != "Middle Upper Class") ++bad;
                    if (std::string(rules::uasocBandFullName(8))
                        != "Upper Upper Class") ++bad;
     if (rules::uasocBandLow(0) != 1) ++bad;
     if (rules::uasocBandLow(1) != 5) ++bad;
     if (rules::uasocBandLow(2) != 11) ++bad;
     if (rules::uasocBandLow(3) != 21) ++bad;
     if (rules::uasocBandLow(4) != 36) ++bad;
     if (rules::uasocBandLow(5) != 56) ++bad;
     if (rules::uasocBandLow(6) != 88) ++bad;
     if (rules::uasocBandLow(7) != 97) ++bad;
     if (rules::uasocBandLow(8) != 100) ++bad;
     if (rules::uasocBandHigh(0) != 4) ++bad;
     if (rules::uasocBandHigh(1) != 10) ++bad;
     if (rules::uasocBandHigh(2) != 20) ++bad;
     if (rules::uasocBandHigh(3) != 35) ++bad;
     if (rules::uasocBandHigh(4) != 55) ++bad;
     if (rules::uasocBandHigh(5) != 87) ++bad;
     if (rules::uasocBandHigh(6) != 96) ++bad;
     if (rules::uasocBandHigh(7) != 99) ++bad;
     if (rules::uasocBandHigh(8) != 100) ++bad;
     if (rules::uasocRosterCount(0) != 8) ++bad;
     if (rules::uasocRosterCount(1) != 10) ++bad;
     if (rules::uasocRosterCount(2) != 7) ++bad;
     if (rules::uasocRosterCount(3) != 8) ++bad;
     if (rules::uasocRosterCount(4) != 8) ++bad;
     if (rules::uasocRosterCount(5) != 9) ++bad;
     if (rules::uasocRosterCount(6) != 9) ++bad;
     if (rules::uasocRosterCount(7) != 6) ++bad;
     if (rules::uasocRosterCount(8) != 3) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_socialclass_abbr");
                if (!d) { ++bad; } else {
                    if (std::string(rules::uasocBandAbbr(0))
                        != "LLC") ++bad;
                    if (std::string(rules::uasocBandAbbr(1))
                        != "MLC") ++bad;
                    if (std::string(rules::uasocBandAbbr(2))
                        != "ULC") ++bad;
                    if (std::string(rules::uasocBandAbbr(3))
                        != "LMC") ++bad;
                    if (std::string(rules::uasocBandAbbr(4))
                        != "MMC") ++bad;
                    if (std::string(rules::uasocBandAbbr(5))
                        != "UMC") ++bad;
                    if (std::string(rules::uasocBandAbbr(6))
                        != "LUC") ++bad;
                    if (std::string(rules::uasocBandAbbr(7))
                        != "MUC") ++bad;
                    if (std::string(rules::uasocBandAbbr(8))
                        != "UUC") ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_socialclass_roster");
                if (!d) { ++bad; } else {
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_birth");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 5) ++bad;
                    if (d->tables[0]
                        .values[1] != 10) ++bad;
                    if (d->tables[0]
                        .values[2] != 20) ++bad;
                    if (d->tables[0]
                        .values[3] != 35) ++bad;
                    if (d->tables[0]
                        .values[4] != 50) ++bad;
                    if (d->tables[0]
                        .values[5] != 65) ++bad;
                    if (d->tables[0]
                        .values[6] != 80) ++bad;
                    if (d->tables[0]
                        .values[7] != 85) ++bad;
                    if (d->tables[0]
                        .values[8] != 90) ++bad;
                    if (d->tables[0]
                        .values[9] != 94) ++bad;
                    if (d->tables[0]
                        .values[10] != 97) ++bad;
                    if (d->tables[0]
                        .values[11] != 99) ++bad;
                    if (d->tables[0]
                        .values[12] != 100) ++bad;
                    if (d->tables[1]
                        .values[0] != 1) ++bad;
                    if (d->tables[1]
                        .values[1] != 6) ++bad;
                    if (d->tables[1]
                        .values[2] != 11) ++bad;
                    if (d->tables[1]
                        .values[3] != 21) ++bad;
                    if (d->tables[1]
                        .values[4] != 36) ++bad;
                    if (d->tables[1]
                        .values[5] != 51) ++bad;
                    if (d->tables[1]
                        .values[6] != 66) ++bad;
                    if (d->tables[1]
                        .values[7] != 81) ++bad;
                    if (d->tables[1]
                        .values[8] != 86) ++bad;
                    if (d->tables[1]
                        .values[9] != 91) ++bad;
                    if (d->tables[1]
                        .values[10] != 95) ++bad;
                    if (d->tables[1]
                        .values[11] != 98) ++bad;
                    if (d->tables[1]
                        .values[12] != 100) ++bad;
                    if (std::string(rules::uabirthOrderLabel(0))
                        != "Only child") ++bad;
                    if (std::string(rules::uabirthOrderLabel(1))
                        != "1st child") ++bad;
                    if (std::string(rules::uabirthOrderLabel(2))
                        != "2nd child") ++bad;
                    if (std::string(rules::uabirthOrderLabel(3))
                        != "3rd child") ++bad;
                    if (std::string(rules::uabirthOrderLabel(4))
                        != "4th child") ++bad;
                    if (std::string(rules::uabirthOrderLabel(5))
                        != "5th child") ++bad;
                    if (std::string(rules::uabirthOrderLabel(6))
                        != "6th child") ++bad;
                    if (std::string(rules::uabirthOrderLabel(7))
                        != "7th child") ++bad;
                    if (std::string(rules::uabirthOrderLabel(8))
                        != "8th child") ++bad;
                    if (std::string(rules::uabirthOrderLabel(9))
                        != "9th child") ++bad;
                    if (std::string(rules::uabirthOrderLabel(10))
                        != "10th child") ++bad;
                    if (std::string(rules::uabirthOrderLabel(11))
                        != "11th child") ++bad;
                    if (std::string(rules::uabirthOrderLabel(12))
                        != "12th child") ++bad;
     if (rules::uabirthRowLow(0) != 1) ++bad;
     if (rules::uabirthRowLow(1) != 6) ++bad;
     if (rules::uabirthRowLow(2) != 11) ++bad;
     if (rules::uabirthRowLow(3) != 21) ++bad;
     if (rules::uabirthRowLow(4) != 36) ++bad;
     if (rules::uabirthRowLow(5) != 51) ++bad;
     if (rules::uabirthRowLow(6) != 66) ++bad;
     if (rules::uabirthRowLow(7) != 81) ++bad;
     if (rules::uabirthRowLow(8) != 86) ++bad;
     if (rules::uabirthRowLow(9) != 91) ++bad;
     if (rules::uabirthRowLow(10) != 95) ++bad;
     if (rules::uabirthRowLow(11) != 98) ++bad;
     if (rules::uabirthRowLow(12) != 100) ++bad;
     if (rules::uabirthRowHigh(0) != 5) ++bad;
     if (rules::uabirthRowHigh(1) != 10) ++bad;
     if (rules::uabirthRowHigh(2) != 20) ++bad;
     if (rules::uabirthRowHigh(3) != 35) ++bad;
     if (rules::uabirthRowHigh(4) != 50) ++bad;
     if (rules::uabirthRowHigh(5) != 65) ++bad;
     if (rules::uabirthRowHigh(6) != 80) ++bad;
     if (rules::uabirthRowHigh(7) != 85) ++bad;
     if (rules::uabirthRowHigh(8) != 90) ++bad;
     if (rules::uabirthRowHigh(9) != 94) ++bad;
     if (rules::uabirthRowHigh(10) != 97) ++bad;
     if (rules::uabirthRowHigh(11) != 99) ++bad;
     if (rules::uabirthRowHigh(12) != 100) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_subrace_prefs");
                if (!d) { ++bad; } else {
                    if (d->tables[0]
                        .values[0] != 0) ++bad;
                    if (d->tables[0]
                        .values[1] != 4) ++bad;
                    if (d->tables[0]
                        .values[2] != 4) ++bad;
                    if (d->tables[0]
                        .values[3] != 1) ++bad;
                    if (d->tables[0]
                        .values[4] != 5) ++bad;
                    if (d->tables[0]
                        .values[5] != 5) ++bad;
                    if (d->tables[0]
                        .values[6] != 5) ++bad;
                    if (d->tables[0]
                        .values[7] != 5) ++bad;
                    if (d->tables[0]
                        .values[8] != 5) ++bad;
                    if (d->tables[0]
                        .values[9] != 4) ++bad;
                    if (d->tables[0]
                        .values[10] != 4) ++bad;
                    if (d->tables[0]
                        .values[11] != 3) ++bad;
                    if (d->tables[0]
                        .values[12] != 3) ++bad;
                    if (d->tables[0]
                        .values[13] != 2) ++bad;
                    if (d->tables[0]
                        .values[14] != 3) ++bad;
                    if (d->tables[0]
                        .values[15] != 3) ++bad;
                    if (d->tables[0]
                        .values[16] != 3) ++bad;
                    if (d->tables[0]
                        .values[17] != 4) ++bad;
                    if (d->tables[0]
                        .values[18] != 0) ++bad;
                    if (d->tables[0]
                        .values[19] != 1) ++bad;
                    if (d->tables[0]
                        .values[20] != 5) ++bad;
                    if (d->tables[0]
                        .values[21] != 4) ++bad;
                    if (d->tables[0]
                        .values[22] != 4) ++bad;
                    if (d->tables[0]
                        .values[23] != 4) ++bad;
                    if (d->tables[0]
                        .values[24] != 4) ++bad;
                    if (d->tables[0]
                        .values[25] != 4) ++bad;
                    if (d->tables[0]
                        .values[26] != 3) ++bad;
                    if (d->tables[0]
                        .values[27] != 1) ++bad;
                    if (d->tables[0]
                        .values[28] != 3) ++bad;
                    if (d->tables[0]
                        .values[29] != 2) ++bad;
                    if (d->tables[0]
                        .values[30] != 1) ++bad;
                    if (d->tables[0]
                        .values[31] != 1) ++bad;
                    if (d->tables[0]
                        .values[32] != 5) ++bad;
                    if (d->tables[0]
                        .values[33] != 3) ++bad;
                    if (d->tables[0]
                        .values[34] != 4) ++bad;
                    if (d->tables[0]
                        .values[35] != 1) ++bad;
                    if (d->tables[0]
                        .values[36] != 0) ++bad;
                    if (d->tables[0]
                        .values[37] != 5) ++bad;
                    if (d->tables[0]
                        .values[38] != 4) ++bad;
                    if (d->tables[0]
                        .values[39] != 4) ++bad;
                    if (d->tables[0]
                        .values[40] != 4) ++bad;
                    if (d->tables[0]
                        .values[41] != 4) ++bad;
                    if (d->tables[0]
                        .values[42] != 4) ++bad;
                    if (d->tables[0]
                        .values[43] != 2) ++bad;
                    if (d->tables[0]
                        .values[44] != 2) ++bad;
                    if (d->tables[0]
                        .values[45] != 3) ++bad;
                    if (d->tables[0]
                        .values[46] != 2) ++bad;
                    if (d->tables[0]
                        .values[47] != 1) ++bad;
                    if (d->tables[0]
                        .values[48] != 2) ++bad;
                    if (d->tables[0]
                        .values[49] != 5) ++bad;
                    if (d->tables[0]
                        .values[50] != 3) ++bad;
                    if (d->tables[0]
                        .values[51] != 1) ++bad;
                    if (d->tables[0]
                        .values[52] != 4) ++bad;
                    if (d->tables[0]
                        .values[53] != 4) ++bad;
                    if (d->tables[0]
                        .values[54] != 0) ++bad;
                    if (d->tables[0]
                        .values[55] != 5) ++bad;
                    if (d->tables[0]
                        .values[56] != 5) ++bad;
                    if (d->tables[0]
                        .values[57] != 4) ++bad;
                    if (d->tables[0]
                        .values[58] != 5) ++bad;
                    if (d->tables[0]
                        .values[59] != 5) ++bad;
                    if (d->tables[0]
                        .values[60] != 5) ++bad;
                    if (d->tables[0]
                        .values[61] != 4) ++bad;
                    if (d->tables[0]
                        .values[62] != 4) ++bad;
                    if (d->tables[0]
                        .values[63] != 4) ++bad;
                    if (d->tables[0]
                        .values[64] != 4) ++bad;
                    if (d->tables[0]
                        .values[65] != 4) ++bad;
                    if (d->tables[0]
                        .values[66] != 2) ++bad;
                    if (d->tables[0]
                        .values[67] != 3) ++bad;
                    if (d->tables[0]
                        .values[68] != 4) ++bad;
                    if (d->tables[0]
                        .values[69] != 4) ++bad;
                    if (d->tables[0]
                        .values[70] != 4) ++bad;
                    if (d->tables[0]
                        .values[71] != 5) ++bad;
                    if (d->tables[0]
                        .values[72] != 0) ++bad;
                    if (d->tables[0]
                        .values[73] != 1) ++bad;
                    if (d->tables[0]
                        .values[74] != 4) ++bad;
                    if (d->tables[0]
                        .values[75] != 2) ++bad;
                    if (d->tables[0]
                        .values[76] != 1) ++bad;
                    if (d->tables[0]
                        .values[77] != 3) ++bad;
                    if (d->tables[0]
                        .values[78] != 2) ++bad;
                    if (d->tables[0]
                        .values[79] != 1) ++bad;
                    if (d->tables[0]
                        .values[80] != 2) ++bad;
                    if (d->tables[0]
                        .values[81] != 2) ++bad;
                    if (d->tables[0]
                        .values[82] != 1) ++bad;
                    if (d->tables[0]
                        .values[83] != 4) ++bad;
                    if (d->tables[0]
                        .values[84] != 3) ++bad;
                    if (d->tables[0]
                        .values[85] != 4) ++bad;
                    if (d->tables[0]
                        .values[86] != 4) ++bad;
                    if (d->tables[0]
                        .values[87] != 4) ++bad;
                    if (d->tables[0]
                        .values[88] != 5) ++bad;
                    if (d->tables[0]
                        .values[89] != 1) ++bad;
                    if (d->tables[0]
                        .values[90] != 0) ++bad;
                    if (d->tables[0]
                        .values[91] != 4) ++bad;
                    if (d->tables[0]
                        .values[92] != 3) ++bad;
                    if (d->tables[0]
                        .values[93] != 1) ++bad;
                    if (d->tables[0]
                        .values[94] != 2) ++bad;
                    if (d->tables[0]
                        .values[95] != 2) ++bad;
                    if (d->tables[0]
                        .values[96] != 1) ++bad;
                    if (d->tables[0]
                        .values[97] != 2) ++bad;
                    if (d->tables[0]
                        .values[98] != 2) ++bad;
                    if (d->tables[0]
                        .values[99] != 1) ++bad;
                    if (d->tables[0]
                        .values[100] != 4) ++bad;
                    if (d->tables[0]
                        .values[101] != 3) ++bad;
                    if (d->tables[0]
                        .values[102] != 4) ++bad;
                    if (d->tables[0]
                        .values[103] != 4) ++bad;
                    if (d->tables[0]
                        .values[104] != 4) ++bad;
                    if (d->tables[0]
                        .values[105] != 4) ++bad;
                    if (d->tables[0]
                        .values[106] != 3) ++bad;
                    if (d->tables[0]
                        .values[107] != 3) ++bad;
                    if (d->tables[0]
                        .values[108] != 0) ++bad;
                    if (d->tables[0]
                        .values[109] != 3) ++bad;
                    if (d->tables[0]
                        .values[110] != 3) ++bad;
                    if (d->tables[0]
                        .values[111] != 1) ++bad;
                    if (d->tables[0]
                        .values[112] != 1) ++bad;
                    if (d->tables[0]
                        .values[113] != 2) ++bad;
                    if (d->tables[0]
                        .values[114] != 3) ++bad;
                    if (d->tables[0]
                        .values[115] != 3) ++bad;
                    if (d->tables[0]
                        .values[116] != 2) ++bad;
                    if (d->tables[0]
                        .values[117] != 4) ++bad;
                    if (d->tables[0]
                        .values[118] != 4) ++bad;
                    if (d->tables[0]
                        .values[119] != 4) ++bad;
                    if (d->tables[0]
                        .values[120] != 4) ++bad;
                    if (d->tables[0]
                        .values[121] != 4) ++bad;
                    if (d->tables[0]
                        .values[122] != 5) ++bad;
                    if (d->tables[0]
                        .values[123] != 3) ++bad;
                    if (d->tables[0]
                        .values[124] != 3) ++bad;
                    if (d->tables[0]
                        .values[125] != 4) ++bad;
                    if (d->tables[0]
                        .values[126] != 0) ++bad;
                    if (d->tables[0]
                        .values[127] != 3) ++bad;
                    if (d->tables[0]
                        .values[128] != 4) ++bad;
                    if (d->tables[0]
                        .values[129] != 4) ++bad;
                    if (d->tables[0]
                        .values[130] != 4) ++bad;
                    if (d->tables[0]
                        .values[131] != 4) ++bad;
                    if (d->tables[0]
                        .values[132] != 4) ++bad;
                    if (d->tables[0]
                        .values[133] != 3) ++bad;
                    if (d->tables[0]
                        .values[134] != 4) ++bad;
                    if (d->tables[0]
                        .values[135] != 4) ++bad;
                    if (d->tables[0]
                        .values[136] != 4) ++bad;
                    if (d->tables[0]
                        .values[137] != 4) ++bad;
                    if (d->tables[0]
                        .values[138] != 4) ++bad;
                    if (d->tables[0]
                        .values[139] != 5) ++bad;
                    if (d->tables[0]
                        .values[140] != 1) ++bad;
                    if (d->tables[0]
                        .values[141] != 1) ++bad;
                    if (d->tables[0]
                        .values[142] != 4) ++bad;
                    if (d->tables[0]
                        .values[143] != 3) ++bad;
                    if (d->tables[0]
                        .values[144] != 0) ++bad;
                    if (d->tables[0]
                        .values[145] != 3) ++bad;
                    if (d->tables[0]
                        .values[146] != 3) ++bad;
                    if (d->tables[0]
                        .values[147] != 1) ++bad;
                    if (d->tables[0]
                        .values[148] != 2) ++bad;
                    if (d->tables[0]
                        .values[149] != 2) ++bad;
                    if (d->tables[0]
                        .values[150] != 1) ++bad;
                    if (d->tables[0]
                        .values[151] != 4) ++bad;
                    if (d->tables[0]
                        .values[152] != 3) ++bad;
                    if (d->tables[0]
                        .values[153] != 4) ++bad;
                    if (d->tables[0]
                        .values[154] != 3) ++bad;
                    if (d->tables[0]
                        .values[155] != 2) ++bad;
                    if (d->tables[0]
                        .values[156] != 5) ++bad;
                    if (d->tables[0]
                        .values[157] != 3) ++bad;
                    if (d->tables[0]
                        .values[158] != 3) ++bad;
                    if (d->tables[0]
                        .values[159] != 2) ++bad;
                    if (d->tables[0]
                        .values[160] != 3) ++bad;
                    if (d->tables[0]
                        .values[161] != 3) ++bad;
                    if (d->tables[0]
                        .values[162] != 0) ++bad;
                    if (d->tables[0]
                        .values[163] != 1) ++bad;
                    if (d->tables[0]
                        .values[164] != 3) ++bad;
                    if (d->tables[0]
                        .values[165] != 2) ++bad;
                    if (d->tables[0]
                        .values[166] != 2) ++bad;
                    if (d->tables[0]
                        .values[167] != 2) ++bad;
                    if (d->tables[0]
                        .values[168] != 4) ++bad;
                    if (d->tables[0]
                        .values[169] != 3) ++bad;
                    if (d->tables[0]
                        .values[170] != 4) ++bad;
                    if (d->tables[0]
                        .values[171] != 1) ++bad;
                    if (d->tables[0]
                        .values[172] != 1) ++bad;
                    if (d->tables[0]
                        .values[173] != 4) ++bad;
                    if (d->tables[0]
                        .values[174] != 2) ++bad;
                    if (d->tables[0]
                        .values[175] != 2) ++bad;
                    if (d->tables[0]
                        .values[176] != 1) ++bad;
                    if (d->tables[0]
                        .values[177] != 3) ++bad;
                    if (d->tables[0]
                        .values[178] != 3) ++bad;
                    if (d->tables[0]
                        .values[179] != 1) ++bad;
                    if (d->tables[0]
                        .values[180] != 0) ++bad;
                    if (d->tables[0]
                        .values[181] != 2) ++bad;
                    if (d->tables[0]
                        .values[182] != 1) ++bad;
                    if (d->tables[0]
                        .values[183] != 1) ++bad;
                    if (d->tables[0]
                        .values[184] != 1) ++bad;
                    if (d->tables[0]
                        .values[185] != 5) ++bad;
                    if (d->tables[0]
                        .values[186] != 3) ++bad;
                    if (d->tables[0]
                        .values[187] != 3) ++bad;
                    if (d->tables[0]
                        .values[188] != 3) ++bad;
                    if (d->tables[0]
                        .values[189] != 3) ++bad;
                    if (d->tables[0]
                        .values[190] != 0) ++bad;
                    if (d->tables[0]
                        .values[191] != 0) ++bad;
                    if (d->tables[0]
                        .values[192] != 0) ++bad;
                    if (d->tables[0]
                        .values[193] != 0) ++bad;
                    if (d->tables[0]
                        .values[194] != 4) ++bad;
                    if (d->tables[0]
                        .values[195] != 0) ++bad;
                    if (d->tables[0]
                        .values[196] != 3) ++bad;
                    if (d->tables[0]
                        .values[197] != 2) ++bad;
                    if (d->tables[0]
                        .values[198] != 0) ++bad;
                    if (d->tables[0]
                        .values[199] != 3) ++bad;
                    if (d->tables[0]
                        .values[200] != 3) ++bad;
                    if (d->tables[0]
                        .values[201] != 2) ++bad;
                    if (d->tables[0]
                        .values[202] != 4) ++bad;
                    if (d->tables[0]
                        .values[203] != 2) ++bad;
                    if (d->tables[0]
                        .values[204] != 3) ++bad;
                    if (d->tables[0]
                        .values[205] != 2) ++bad;
                    if (d->tables[0]
                        .values[206] != 2) ++bad;
                    if (d->tables[0]
                        .values[207] != 4) ++bad;
                    if (d->tables[0]
                        .values[208] != 2) ++bad;
                    if (d->tables[0]
                        .values[209] != 2) ++bad;
                    if (d->tables[0]
                        .values[210] != 3) ++bad;
                    if (d->tables[0]
                        .values[211] != 3) ++bad;
                    if (d->tables[0]
                        .values[212] != 2) ++bad;
                    if (d->tables[0]
                        .values[213] != 3) ++bad;
                    if (d->tables[0]
                        .values[214] != 2) ++bad;
                    if (d->tables[0]
                        .values[215] != 3) ++bad;
                    if (d->tables[0]
                        .values[216] != 0) ++bad;
                    if (d->tables[0]
                        .values[217] != 0) ++bad;
                    if (d->tables[0]
                        .values[218] != 0) ++bad;
                    if (d->tables[0]
                        .values[219] != 3) ++bad;
                    if (d->tables[0]
                        .values[220] != 2) ++bad;
                    if (d->tables[0]
                        .values[221] != 2) ++bad;
                    if (d->tables[0]
                        .values[222] != 1) ++bad;
                    if (d->tables[0]
                        .values[223] != 1) ++bad;
                    if (d->tables[0]
                        .values[224] != 4) ++bad;
                    if (d->tables[0]
                        .values[225] != 2) ++bad;
                    if (d->tables[0]
                        .values[226] != 2) ++bad;
                    if (d->tables[0]
                        .values[227] != 3) ++bad;
                    if (d->tables[0]
                        .values[228] != 3) ++bad;
                    if (d->tables[0]
                        .values[229] != 2) ++bad;
                    if (d->tables[0]
                        .values[230] != 2) ++bad;
                    if (d->tables[0]
                        .values[231] != 2) ++bad;
                    if (d->tables[0]
                        .values[232] != 3) ++bad;
                    if (d->tables[0]
                        .values[233] != 0) ++bad;
                    if (d->tables[0]
                        .values[234] != 0) ++bad;
                    if (d->tables[0]
                        .values[235] != 0) ++bad;
                    if (d->tables[0]
                        .values[236] != 3) ++bad;
                    if (d->tables[0]
                        .values[237] != 3) ++bad;
                    if (d->tables[0]
                        .values[238] != 3) ++bad;
                    if (d->tables[0]
                        .values[239] != 2) ++bad;
                    if (d->tables[0]
                        .values[240] != 2) ++bad;
                    if (d->tables[0]
                        .values[241] != 3) ++bad;
                    if (d->tables[0]
                        .values[242] != 1) ++bad;
                    if (d->tables[0]
                        .values[243] != 1) ++bad;
                    if (d->tables[0]
                        .values[244] != 2) ++bad;
                    if (d->tables[0]
                        .values[245] != 2) ++bad;
                    if (d->tables[0]
                        .values[246] != 1) ++bad;
                    if (d->tables[0]
                        .values[247] != 3) ++bad;
                    if (d->tables[0]
                        .values[248] != 2) ++bad;
                    if (d->tables[0]
                        .values[249] != 1) ++bad;
                    if (d->tables[0]
                        .values[250] != 0) ++bad;
                    if (d->tables[0]
                        .values[251] != 0) ++bad;
                    if (d->tables[0]
                        .values[252] != 0) ++bad;
                    if (d->tables[0]
                        .values[253] != 3) ++bad;
                    if (d->tables[0]
                        .values[254] != 3) ++bad;
                    if (d->tables[0]
                        .values[255] != 3) ++bad;
                    if (d->tables[0]
                        .values[256] != 5) ++bad;
                    if (d->tables[0]
                        .values[257] != 5) ++bad;
                    if (d->tables[0]
                        .values[258] != 3) ++bad;
                    if (d->tables[0]
                        .values[259] != 4) ++bad;
                    if (d->tables[0]
                        .values[260] != 4) ++bad;
                    if (d->tables[0]
                        .values[261] != 4) ++bad;
                    if (d->tables[0]
                        .values[262] != 4) ++bad;
                    if (d->tables[0]
                        .values[263] != 4) ++bad;
                    if (d->tables[0]
                        .values[264] != 4) ++bad;
                    if (d->tables[0]
                        .values[265] != 5) ++bad;
                    if (d->tables[0]
                        .values[266] != 4) ++bad;
                    if (d->tables[0]
                        .values[267] != 3) ++bad;
                    if (d->tables[0]
                        .values[268] != 3) ++bad;
                    if (d->tables[0]
                        .values[269] != 4) ++bad;
                    if (d->tables[0]
                        .values[270] != 0) ++bad;
                    if (d->tables[0]
                        .values[271] != 2) ++bad;
                    if (d->tables[0]
                        .values[272] != 3) ++bad;
                    if (d->tables[0]
                        .values[273] != 3) ++bad;
                    if (d->tables[0]
                        .values[274] != 3) ++bad;
                    if (d->tables[0]
                        .values[275] != 3) ++bad;
                    if (d->tables[0]
                        .values[276] != 3) ++bad;
                    if (d->tables[0]
                        .values[277] != 3) ++bad;
                    if (d->tables[0]
                        .values[278] != 3) ++bad;
                    if (d->tables[0]
                        .values[279] != 3) ++bad;
                    if (d->tables[0]
                        .values[280] != 3) ++bad;
                    if (d->tables[0]
                        .values[281] != 3) ++bad;
                    if (d->tables[0]
                        .values[282] != 3) ++bad;
                    if (d->tables[0]
                        .values[283] != 2) ++bad;
                    if (d->tables[0]
                        .values[284] != 3) ++bad;
                    if (d->tables[0]
                        .values[285] != 3) ++bad;
                    if (d->tables[0]
                        .values[286] != 3) ++bad;
                    if (d->tables[0]
                        .values[287] != 3) ++bad;
                    if (d->tables[0]
                        .values[288] != 0) ++bad;
 if (rules::subracePrefers((rules::CharSubRace)1, (rules::CharSubRace)2) != 4)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)1, (rules::CharSubRace)10) != 4)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)2, (rules::CharSubRace)2) != 0)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)2, (rules::CharSubRace)10) != 3)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)3, (rules::CharSubRace)2) != 1)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)3, (rules::CharSubRace)10) != 2)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)4, (rules::CharSubRace)2) != 4)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)4, (rules::CharSubRace)10) != 5)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)5, (rules::CharSubRace)2) != 4)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)5, (rules::CharSubRace)10) != 3)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)6, (rules::CharSubRace)2) != 4)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)6, (rules::CharSubRace)10) != 2)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)7, (rules::CharSubRace)2) != 4)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)7, (rules::CharSubRace)10) != 1)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)8, (rules::CharSubRace)2) != 4)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)8, (rules::CharSubRace)10) != 4)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)9, (rules::CharSubRace)2) != 4)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)9, (rules::CharSubRace)10) != 3)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)10, (rules::CharSubRace)2) != 3)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)10, (rules::CharSubRace)10) != 0)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)11, (rules::CharSubRace)2) != 1)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)11, (rules::CharSubRace)10) != 1)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)12, (rules::CharSubRace)2) != 3)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)12, (rules::CharSubRace)10) != 3)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)13, (rules::CharSubRace)2) != 2)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)13, (rules::CharSubRace)10) != 3)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)14, (rules::CharSubRace)2) != 1)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)14, (rules::CharSubRace)10) != 2)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)15, (rules::CharSubRace)2) != 2)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)15, (rules::CharSubRace)10) != 3)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)16, (rules::CharSubRace)2) != 5)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)16, (rules::CharSubRace)10) != 4)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)17, (rules::CharSubRace)2) != 3)
          ++bad;
 if (rules::subracePrefers((rules::CharSubRace)17, (rules::CharSubRace)10) != 3)
          ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_subrace_letters");
                if (!d) { ++bad; } else {
                }
            }
        }
        printf("R1056 uaclasses registry defs-C audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 6. seam ----------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/ua_classes");
            {
                const items::MiscItemDef* d =
                    reg.find("ua_acrobat");
                if (!d) { ++bad; } else {
   for (int i = 0; i < 7; ++i)
    if (rules::acrobatXpToAttain(6 + i)
        != (int)d->tables[9].values[i])
           ++bad;
   for (int i = 0; i < 4; ++i)
    if (rules::acrobatExtensionFailurePercent(2 + i)
        != (int)d->tables[6].values[i])
           ++bad;
   for (int i = 0; i < 4; ++i)
    if (rules::acrobatExtensionRecoverySegments(2 + i)
        != (int)d->tables[7].values[i])
           ++bad;
 for (int i = 0; i < 5; ++i)
 for (int j = 0; j < 3; ++j)
 if (rules::acrobatFootnoteCarryGp(1 + i, 0 + j)
 != (int)d->tables[0].values[(i + 0) * 3 + (j + 0)])
 ++bad;
  for (int i = 0; i < 17; ++i) {
    int got = rules::acrobatFallingChanceKnown(
         (int)d->tables[8].values[i * 3],
         (int)d->tables[8].values[i * 3 + 1]);
    if (got != (int)d->tables[8].values[i * 3 + 2])
            ++bad;
   }
   for (int i = 0; i < 4; ++i)
    if (rules::acrobatDexTightropeBonus(16 + i)
        != (int)d->tables[4].values[i])
           ++bad;
   for (int i = 0; i < 4; ++i)
    if (rules::acrobatDexPoleVaultBonus(16 + i)
        != (int)d->tables[5].values[i])
           ++bad;
   for (int i = 0; i < 4; ++i)
    if (rules::acrobatDexAttackBonus(16 + i)
        != (int)d->tables[1].values[i])
           ++bad;
   for (int i = 0; i < 4; ++i)
    if (rules::acrobatDexEvasionBonus(16 + i)
        != (int)d->tables[2].values[i])
           ++bad;
   for (int i = 0; i < 4; ++i)
    if (rules::acrobatDexFallingBonus(16 + i)
        != (int)d->tables[3].values[i])
           ++bad;
   for (int i = 0; i < (int)d->rows.size(); ++i)
    if (std::string(rules::acrobatFrozenSkillName(0 + i))
        != d->rows[i].name)
           ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_acrobat_retained");
                if (!d) { ++bad; } else {
   for (int i = 0; i < (int)d->rows.size(); ++i)
    if (std::string(rules::acrobatRetainedSkillName(0 + i))
        != d->rows[i].name)
           ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_barbarian");
                if (!d) { ++bad; } else {
   for (int i = 0; i < 11; ++i)
    if (rules::barbarianXpToAttain(1 + i)
        != (int)d->tables[1].values[i])
           ++bad;
   for (int i = 0; i < 5; ++i)
    if (rules::barbarianStrikeLevel(1 + i)
        != (int)d->tables[0].values[i])
           ++bad;
   for (int i = 0; i < (int)d->rows.size(); ++i)
    if (std::string(rules::barbarianTertiaryName(0 + i))
        != d->rows[i].name)
           ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_barbarian_weapons");
                if (!d) { ++bad; } else {
   for (int i = 0; i < (int)d->rows.size(); ++i)
    if (std::string(rules::barbarianRequiredWeaponName(0 + i))
        != d->rows[i].name)
           ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_cavalier");
                if (!d) { ++bad; } else {
   for (int i = 0; i < 12; ++i)
    if (rules::cavalierXpToAttain(1 + i)
        != (int)d->tables[1].values[i])
           ++bad;
   for (int i = 0; i < 6; ++i)
    if (rules::cavalierHorsemanshipLevel(0 + i)
        != (int)d->tables[0].values[i])
           ++bad;
   for (int i = 0; i < (int)d->rows.size(); ++i)
    if (std::string(rules::cavalierPreferredWeaponName(0 + i))
        != d->rows[i].name)
           ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_cavalier_mind");
                if (!d) { ++bad; } else {
   for (int i = 0; i < (int)d->rows.size(); ++i)
    if (std::string(rules::cavalierMindPowerName(0 + i))
        != d->rows[i].name)
           ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_cavmoney");
                if (!d) { ++bad; } else {
   for (int i = 0; i < 6; ++i)
    if (rules::cavMoneyGoldLow(0 + i)
        != (int)d->tables[4].values[i])
           ++bad;
   for (int i = 0; i < 6; ++i)
    if (rules::cavMoneyGoldHigh(0 + i)
        != (int)d->tables[3].values[i])
           ++bad;
   for (int i = 0; i < 6; ++i)
    if (rules::cavMoneyDiceCount(0 + i)
        != (int)d->tables[1].values[i])
           ++bad;
   for (int i = 0; i < 6; ++i)
    if (rules::cavMoneyDiceFaces(0 + i)
        != (int)d->tables[2].values[i])
           ++bad;
   for (int i = 0; i < 6; ++i)
    if (rules::cavMoneyDiceBonus(0 + i)
        != (int)d->tables[0].values[i])
           ++bad;
   for (int i = 0; i < 6; ++i)
    if (rules::cavMoneyItemCount(0 + i)
        != (int)d->tables[5].values[i])
           ++bad;
   for (int i = 0; i < (int)d->rows.size(); ++i)
    if (std::string(rules::cavMoneyStationName(0 + i))
        != d->rows[i].name)
           ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_cavmoney_entry");
                if (!d) { ++bad; } else {
   for (int i = 0; i < (int)d->rows.size(); ++i)
    if (std::string(rules::cavMoneyStationEntry(0 + i))
        != d->rows[i].name)
           ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_cavmoney_items");
                if (!d) { ++bad; } else {
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_hierophant");
                if (!d) { ++bad; } else {
   for (int i = 0; i < 8; ++i)
    if (rules::hierophantXpBandLow(16 + i)
        != (int)d->tables[2].values[i])
           ++bad;
 for (int i = 0; i < 5; ++i)
 for (int j = 0; j < 4; ++j)
 if (rules::hierophantConjureLow(0 + i, 0 + j)
 != (int)d->tables[1].values[(i + 0) * 4 + (j + 0)])
 ++bad;
 for (int i = 0; i < 5; ++i)
 for (int j = 0; j < 4; ++j)
 if (rules::hierophantConjureHigh(0 + i, 0 + j)
 != (int)d->tables[0].values[(i + 0) * 4 + (j + 0)])
 ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_hierophant_conjure");
                if (!d) { ++bad; } else {
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_hierophant_special");
                if (!d) { ++bad; } else {
   for (int i = 0; i < (int)d->rows.size(); ++i)
    if (std::string(rules::hierophantConjureSpecialName(0 + i))
        != d->rows[i].name)
           ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_paladin");
                if (!d) { ++bad; } else {
   for (int i = 0; i < (int)d->rows.size(); ++i)
    if (std::string(rules::paladinCavalierAbilityName(0 + i))
        != d->rows[i].name)
           ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_classtables");
                if (!d) { ++bad; } else {
   for (int i = 0; i < (int)d->rows.size(); ++i)
    if (std::string(rules::acrobatExtraWeaponName(0 + i))
        != d->rows[i].name)
           ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_cavtable");
                if (!d) { ++bad; } else {
   for (int i = 0; i < 12; ++i)
    if (rules::uacavtLevelXpLow(1 + i)
        != (int)d->tables[1].values[i])
           ++bad;
   for (int i = 0; i < 12; ++i)
    if (rules::uacavtLevelXpHigh(1 + i)
        != (int)d->tables[0].values[i])
           ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_followers");
                if (!d) { ++bad; } else {
   for (int i = 0; i < 7; ++i)
    if (rules::uafolDiceCount(4 + i)
        != (int)d->tables[0].values[i])
           ++bad;
   for (int i = 0; i < 4; ++i)
    if (rules::uafolEquipRowLo(0 + i)
        != (int)d->tables[2].values[i])
           ++bad;
   for (int i = 0; i < 4; ++i)
    if (rules::uafolEquipRowHi(0 + i)
        != (int)d->tables[1].values[i])
           ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ranger");
                if (!d) { ++bad; } else {
   for (int i = 0; i < 4; ++i)
    if (rules::uaRangerTrackTerrainModifier(0 + i)
        != (int)d->tables[0].values[i])
           ++bad;
   for (int i = 0; i < (int)d->rows.size(); ++i)
    if (std::string(rules::uaRangerGiantRosterName(0 + i))
        != d->rows[i].name)
           ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_ranger_identify");
                if (!d) { ++bad; } else {
   for (int i = 0; i < (int)d->rows.size(); ++i)
    if (std::string(rules::uaRangerTrackIdentifyAbility(1 + i))
        != d->rows[i].name)
           ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_socialclass");
                if (!d) { ++bad; } else {
   for (int i = 0; i < 9; ++i)
    if (rules::uasocBandLow(0 + i)
        != (int)d->tables[1].values[i])
           ++bad;
   for (int i = 0; i < 9; ++i)
    if (rules::uasocBandHigh(0 + i)
        != (int)d->tables[0].values[i])
           ++bad;
   for (int i = 0; i < 9; ++i)
    if (rules::uasocRosterCount(0 + i)
        != (int)d->tables[2].values[i])
           ++bad;
   for (int i = 0; i < (int)d->rows.size(); ++i)
    if (std::string(rules::uasocBandFullName(0 + i))
        != d->rows[i].name)
           ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_socialclass_abbr");
                if (!d) { ++bad; } else {
   for (int i = 0; i < (int)d->rows.size(); ++i)
    if (std::string(rules::uasocBandAbbr(0 + i))
        != d->rows[i].name)
           ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_socialclass_roster");
                if (!d) { ++bad; } else {
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_birth");
                if (!d) { ++bad; } else {
   for (int i = 0; i < 13; ++i)
    if (rules::uabirthRowLow(0 + i)
        != (int)d->tables[1].values[i])
           ++bad;
   for (int i = 0; i < 13; ++i)
    if (rules::uabirthRowHigh(0 + i)
        != (int)d->tables[0].values[i])
           ++bad;
   for (int i = 0; i < (int)d->rows.size(); ++i)
    if (std::string(rules::uabirthOrderLabel(0 + i))
        != d->rows[i].name)
           ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_subrace_prefs");
                if (!d) { ++bad; } else {
  for (int v = 1; v <= 17; ++v)
   for (int vd = 1; vd <= 17; ++vd)
    if ((int)rules::subracePrefers(
        (rules::CharSubRace)v,
         (rules::CharSubRace)vd)
       != (int)d->tables[0].values[
          (v - 1) * 17 + vd - 1])
             ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ua_subrace_letters");
                if (!d) { ++bad; } else {
                }
            }
        }
        printf("R1056 uaclasses registry seam audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 7. edges ------------------------------
        {
       if (rules::acrobatXpToAttain(5) != 0)
             ++bad;
       if (rules::acrobatXpToAttain(6) != 20000)
             ++bad;
       if (rules::acrobatXpToAttain(12) != 500000)
             ++bad;
       if (rules::acrobatXpToAttain(13) != 500000)
             ++bad;
       if (rules::acrobatExtensionFailurePercent(-1) != 0)
             ++bad;
       if (rules::acrobatExtensionFailurePercent(0) != 0)
             ++bad;
       if (rules::acrobatExtensionRecoverySegments(-1) != 2)
             ++bad;
       if (rules::acrobatExtensionRecoverySegments(0) != 2)
             ++bad;
       if (rules::acrobatFootnoteCarryGp(0, 0) != 1000)
             ++bad;
       if (rules::acrobatFootnoteCarryGp(6, 2) != 2000)
             ++bad;
       if (rules::acrobatFallingChanceKnown(7, 11) != -1)
            ++bad;
       if (rules::acrobatFallingChanceKnown(999, 999) != -1)
            ++bad;
       if (rules::acrobatDexTightropeBonus(15) != 0)
             ++bad;
       if (rules::acrobatDexTightropeBonus(16) != 5)
             ++bad;
       if (rules::acrobatDexTightropeBonus(19) != 20)
             ++bad;
       if (rules::acrobatDexTightropeBonus(20) != 20)
             ++bad;
       if (rules::acrobatDexPoleVaultBonus(15) != 0)
             ++bad;
       if (rules::acrobatDexPoleVaultBonus(16) != 0)
             ++bad;
       if (rules::acrobatDexPoleVaultBonus(19) != 15)
             ++bad;
       if (rules::acrobatDexPoleVaultBonus(20) != 15)
             ++bad;
       if (rules::acrobatDexAttackBonus(15) != 0)
             ++bad;
       if (rules::acrobatDexAttackBonus(16) != 1)
             ++bad;
       if (rules::acrobatDexAttackBonus(19) != 4)
             ++bad;
       if (rules::acrobatDexAttackBonus(20) != 4)
             ++bad;
       if (rules::acrobatDexEvasionBonus(15) != 0)
             ++bad;
       if (rules::acrobatDexEvasionBonus(16) != 2)
             ++bad;
       if (rules::acrobatDexEvasionBonus(19) != 8)
             ++bad;
       if (rules::acrobatDexEvasionBonus(20) != 8)
             ++bad;
       if (rules::acrobatDexFallingBonus(15) != 0)
             ++bad;
       if (rules::acrobatDexFallingBonus(16) != 0)
             ++bad;
       if (rules::acrobatDexFallingBonus(19) != 10)
             ++bad;
       if (rules::acrobatDexFallingBonus(20) != 10)
             ++bad;
       if (rules::barbarianXpToAttain(0) != 0)
             ++bad;
       if (rules::barbarianXpToAttain(1) != 0)
             ++bad;
       if (rules::barbarianXpToAttain(11) != 1500000)
             ++bad;
       if (rules::barbarianXpToAttain(12) != 1500000)
             ++bad;
       if (rules::barbarianStrikeLevel(0) != 4)
             ++bad;
       if (rules::barbarianStrikeLevel(1) != 4)
             ++bad;
       if (rules::cavalierXpToAttain(0) != 0)
             ++bad;
       if (rules::cavalierXpToAttain(1) != 0)
             ++bad;
       if (rules::cavalierXpToAttain(12) != 900000)
             ++bad;
       if (rules::cavalierXpToAttain(13) != 900000)
             ++bad;
       if (rules::cavalierHorsemanshipLevel(-1) != 3)
             ++bad;
       if (rules::cavalierHorsemanshipLevel(0) != 3)
             ++bad;
       if (rules::cavMoneyGoldLow(-1) != 20)
             ++bad;
       if (rules::cavMoneyGoldLow(0) != 20)
             ++bad;
       if (rules::cavMoneyGoldHigh(-1) != 80)
             ++bad;
       if (rules::cavMoneyGoldHigh(0) != 80)
             ++bad;
       if (rules::cavMoneyDiceCount(-1) != 0)
             ++bad;
       if (rules::cavMoneyDiceCount(0) != 0)
             ++bad;
       if (rules::cavMoneyDiceFaces(-1) != 0)
             ++bad;
       if (rules::cavMoneyDiceFaces(0) != 0)
             ++bad;
       if (rules::cavMoneyDiceBonus(-1) != 0)
             ++bad;
       if (rules::cavMoneyDiceBonus(0) != 0)
             ++bad;
       if (rules::cavMoneyItemCount(-1) != 3)
             ++bad;
       if (rules::cavMoneyItemCount(0) != 3)
             ++bad;
       if (rules::hierophantXpBandLow(15) != 0)
             ++bad;
       if (rules::hierophantXpBandLow(16) != 1)
             ++bad;
       if (rules::hierophantXpBandLow(23) != 3500001)
             ++bad;
       if (rules::hierophantXpBandLow(24) != 3500001)
             ++bad;
       if (rules::hierophantConjureLow(-1, 0) != 1)
             ++bad;
       if (rules::hierophantConjureLow(5, 3) != 0)
             ++bad;
       if (rules::hierophantConjureHigh(-1, 0) != 85)
             ++bad;
       if (rules::hierophantConjureHigh(5, 3) != 0)
             ++bad;
       if (rules::uacavtLevelXpLow(0) != 0)
             ++bad;
       if (rules::uacavtLevelXpLow(1) != 0)
             ++bad;
       if (rules::uacavtLevelXpHigh(0) != 2500)
             ++bad;
       if (rules::uacavtLevelXpHigh(1) != 2500)
             ++bad;
       if (rules::uafolDiceCount(3) != 0)
             ++bad;
       if (rules::uafolDiceCount(4) != 1)
             ++bad;
       if (rules::uafolDiceCount(10) != 48)
             ++bad;
       if (rules::uafolDiceCount(11) != 0)
             ++bad;
       if (rules::uafolEquipRowLo(-1) != 0)
             ++bad;
       if (rules::uafolEquipRowLo(0) != 1)
             ++bad;
       if (rules::uafolEquipRowHi(-1) != 0)
             ++bad;
       if (rules::uafolEquipRowHi(0) != 50)
             ++bad;
       if (rules::uaRangerTrackTerrainModifier(-1) != 20)
             ++bad;
       if (rules::uaRangerTrackTerrainModifier(0) != 20)
             ++bad;
       if (rules::uasocBandLow(-1) != 1)
             ++bad;
       if (rules::uasocBandLow(0) != 1)
             ++bad;
       if (rules::uasocBandHigh(-1) != 4)
             ++bad;
       if (rules::uasocBandHigh(0) != 4)
             ++bad;
       if (rules::uasocRosterCount(-1) != 8)
             ++bad;
       if (rules::uasocRosterCount(0) != 8)
             ++bad;
       if (rules::uabirthRowLow(-1) != 1)
             ++bad;
       if (rules::uabirthRowLow(0) != 1)
             ++bad;
       if (rules::uabirthRowHigh(-1) != 5)
             ++bad;
       if (rules::uabirthRowHigh(0) != 5)
             ++bad;
    if ((int)rules::subracePrefers(
       (rules::CharSubRace)0,
        (rules::CharSubRace)1) != 3)
              ++bad;
    if ((int)rules::subracePrefers(
       (rules::CharSubRace)1,
        (rules::CharSubRace)0) != 3)
              ++bad;
    if ((int)rules::subracePrefers(
       (rules::CharSubRace)18,
        (rules::CharSubRace)1) != 3)
              ++bad;
    if ((int)rules::subracePrefers(
       (rules::CharSubRace)1,
        (rules::CharSubRace)18) != 3)
              ++bad;
    if (std::string(rules::acrobatFrozenSkillName(-1))
        != "Find Traps") ++bad;
    if (std::string(rules::acrobatFrozenSkillName(4))
        != "Remove Traps") ++bad;
    if (std::string(rules::acrobatRetainedSkillName(-1))
        != "Move Silently") ++bad;
    if (std::string(rules::acrobatRetainedSkillName(4))
        != "Read Languages") ++bad;
    if (std::string(rules::barbarianRequiredWeaponName(-1))
        != "Hand Axe") ++bad;
    if (std::string(rules::barbarianRequiredWeaponName(3))
        != "Spear") ++bad;
    if (std::string(rules::barbarianTertiaryName(-1))
        != "Animal Handling") ++bad;
    if (std::string(rules::barbarianTertiaryName(7))
        != "Snare Building") ++bad;
    if (std::string(rules::cavalierPreferredWeaponName(-1))
        != "lance") ++bad;
    if (std::string(rules::cavalierPreferredWeaponName(11))
        != "javelin") ++bad;
    if (std::string(rules::cavalierMindPowerName(-1))
        != "beguiling") ++bad;
    if (std::string(rules::cavalierMindPowerName(10))
        != "psionic mind blast") ++bad;
    if (std::string(rules::cavMoneyStationName(-1))
        != "Lower Middle Class or less") ++bad;
    if (std::string(rules::cavMoneyStationName(6))
        != "Upper Upper Class") ++bad;
    if (std::string(rules::cavMoneyStationEntry(-1))
        != "Horseman") ++bad;
    if (std::string(rules::cavMoneyStationEntry(6))
        != "Cavalier") ++bad;
    if (std::string(rules::cavMoneyItemName(-1, 0))
        != "shield") ++bad;
    if (std::string(rules::cavMoneyItemName(5, 99))
        != "heavy warhorse with leather barding") ++bad;
    if (std::string(rules::hierophantConjureName(-1, -1))
        != "16 HD fire elemental") ++bad;
    if (std::string(rules::hierophantConjureName(5, 4))
        != "") ++bad;
    if (std::string(rules::hierophantConjureSpecialName(-1))
        != "5-8 lava children") ++bad;
    if (std::string(rules::hierophantConjureSpecialName(4))
        != "21-24 vapor rats") ++bad;
    if (std::string(rules::paladinCavalierAbilityName(-1))
        != "weapons of choice") ++bad;
    if (std::string(rules::paladinCavalierAbilityName(5))
        != "immunity to fear") ++bad;
    if (std::string(rules::acrobatExtraWeaponName(-1))
        != "lasso") ++bad;
    if (std::string(rules::acrobatExtraWeaponName(2))
        != "staff") ++bad;
    if (std::string(rules::uaRangerTrackIdentifyAbility(0))
        != "Common woodland creatures' tracks and direction of travel") ++bad;
    if (std::string(rules::uaRangerTrackIdentifyAbility(11))
        != "As 9th level with respect to all creatures ever observed, prior to attaining 10th level or subsequently") ++bad;
    if (std::string(rules::uaRangerGiantRosterName(-1))
        != "bugbear") ++bad;
    if (std::string(rules::uaRangerGiantRosterName(22))
        != "xvart") ++bad;
    if (std::string(rules::uasocBandFullName(-1))
        != "Lower Lower Class") ++bad;
    if (std::string(rules::uasocBandFullName(9))
        != "Upper Upper Class") ++bad;
    if (std::string(rules::uasocBandAbbr(-1))
        != "LLC") ++bad;
    if (std::string(rules::uasocBandAbbr(9))
        != "UUC") ++bad;
    if (std::string(rules::uasocRosterName(-1, 0))
        != "Freed slaves") ++bad;
    if (std::string(rules::uasocRosterName(8, 99))
        != "royalty") ++bad;
    if (std::string(rules::uabirthOrderLabel(-1))
        != "Only child") ++bad;
    if (std::string(rules::uabirthOrderLabel(13))
        != "12th child") ++bad;
      if (std::string(rules::racePrefLetter((rules::RacePref)-1))
          != "?") ++bad;
      if (std::string(rules::racePrefLetter((rules::RacePref)6))
          != "?") ++bad;
    if (rules::acrobatAnyRaceAllowed() != true)
              ++bad;
    if (rules::acrobatBalancePoleBonus() != 10)
              ++bad;
    if (rules::acrobatClimbWallsStillImproves() != true)
              ++bad;
    if (rules::acrobatConvertFromLevel() != 6)
              ++bad;
    if (rules::acrobatEvasionBaseCap() != 60)
              ++bad;
    if (rules::acrobatEvasionRequiresInitiative() != true)
              ++bad;
    if (rules::acrobatEvasionSegments() != 1)
              ++bad;
    if (rules::acrobatExtraWeaponCount() != 2)
              ++bad;
    if (rules::acrobatFallingDamageConverse() != true)
              ++bad;
    if (rules::acrobatFallingPastSafeAddsDice() != true)
              ++bad;
    if (rules::acrobatFrozenSkillCount() != 4)
              ++bad;
    if (rules::acrobatFunctionLevelLow() != 6)
              ++bad;
    if (rules::acrobatFunctionRowCount() != 18)
              ++bad;
    if (rules::acrobatHighJumpLandAboveMax() != 4)
              ++bad;
    if (rules::acrobatHighJumpLandBelowMax() != 2)
              ++bad;
    if (rules::acrobatHighJumpNeedsRun() != true)
              ++bad;
    if (rules::acrobatJumpBulkyArmorBanned() != true)
              ++bad;
    if (rules::acrobatJumpSegments() != 1)
              ++bad;
    if (rules::acrobatLandingSegments() != 1)
              ++bad;
    if (rules::acrobatMinDexterity() != 16)
              ++bad;
    if (rules::acrobatMinStrength() != 15)
              ++bad;
    if (rules::acrobatNoBackpackExceptTightrope() != true)
              ++bad;
    if (rules::acrobatNonAcrobatRunningBroad() != 8)
              ++bad;
    if (rules::acrobatNonAcrobatStandingBroad() != 4)
              ++bad;
    if (rules::acrobatNonAcrobatTightropeBase() != 20)
              ++bad;
    if (rules::acrobatNonAcrobatTightropeRate() != 30)
              ++bad;
    if (rules::acrobatNonAcrobatsCannotVault() != true)
              ++bad;
    if (rules::acrobatNonAcrobatsNoTumblingBenefit() != true)
              ++bad;
    if (rules::acrobatReadMagicNeverGained() != true)
              ++bad;
    if (rules::acrobatRetainedSkillCount() != 4)
              ++bad;
    if (rules::acrobatRunningBroadMinRun() != 20)
              ++bad;
    if (rules::acrobatSkillsFrozenAtLevel() != 5)
              ++bad;
    if (rules::acrobatSplitLevelHigh() != 12)
              ++bad;
    if (rules::acrobatSplitLevelLow() != 6)
              ++bad;
    if (rules::acrobatStandingBackwardHalf() != true)
              ++bad;
    if (rules::acrobatTightropeAscentMaxAngle() != 45)
              ++bad;
    if (rules::acrobatTightropeCarriedEvenlyBalanced() != true)
              ++bad;
    if (rules::acrobatTightropeGustyFailure() != 5)
              ++bad;
    if (rules::acrobatTightropeMaxDistance() != 60)
              ++bad;
    if (rules::acrobatTightropeModerateWindPenalty() != 10)
              ++bad;
    if (rules::acrobatTightropeMoveRate() != 60)
              ++bad;
    if (rules::acrobatTightropeStrongWindPenalty() != 20)
              ++bad;
    if (rules::acrobatTrainerMinLevel() != 10)
              ++bad;
    if (rules::acrobatTrainingWeeks() != 6)
              ++bad;
    if (rules::acrobatTumblingAttackIsPummeling() != true)
              ++bad;
    if (rules::acrobatVaultPoleExtraHeight() != 4)
              ++bad;
    if (rules::acrobatVaultRunStart() != 30)
              ++bad;
    if (rules::acrobatXpBonusAbilityMin() != 16)
              ++bad;
    if (rules::acrobatXpBonusPercent() != 10)
              ++bad;
    if (rules::acrobatXpPerLevelPast12() != 250000)
              ++bad;
    if (rules::archDruidBonusSpellLevels() != 4)
              ++bad;
    if (rules::archDruidCount() != 3)
              ++bad;
    if (rules::archDruidLevel() != 13)
              ++bad;
    if (rules::assassinScrollFromLevel() != 12)
              ++bad;
    if (rules::barbarianAcBonusPerDexPoint() != 2)
              ++bad;
    if (rules::barbarianAcBulkyBonusPerPoint() != 1)
              ++bad;
    if (rules::barbarianAcStepSize() != 1)
              ++bad;
    if (rules::barbarianConHpBonusPerPoint() != 2)
              ++bad;
    if (rules::barbarianDetectIllusionCap() != 75)
              ++bad;
    if (rules::barbarianDetectMagicBase() != 25)
              ++bad;
    if (rules::barbarianDetectMagicCap() != 90)
              ++bad;
    if (rules::barbarianDetectMagicPerLevel() != 5)
              ++bad;
    if (rules::barbarianDetectRounds() != 1)
              ++bad;
    if (rules::barbarianDetestsMagic() != true)
              ++bad;
    if (rules::barbarianDualClassBanned() != true)
              ++bad;
    if (rules::barbarianFirstAidActivePerDay() != 1)
              ++bad;
    if (rules::barbarianFirstAidCureKnownBase() != 50)
              ++bad;
    if (rules::barbarianFirstAidCureKnownCon() != 1)
              ++bad;
    if (rules::barbarianFirstAidCurePercent() != 10)
              ++bad;
    if (rules::barbarianFirstAidHp() != 1)
              ++bad;
    if (rules::barbarianFirstAidOtherHp() != 1)
              ++bad;
    if (rules::barbarianFirstAidRestPerDay() != 2)
              ++bad;
    if (rules::barbarianHideBonusLevels() != 3)
              ++bad;
    if (rules::barbarianHitDice() != 12)
              ++bad;
    if (rules::barbarianHpPerLevelPast8() != 4)
              ++bad;
    if (rules::barbarianHumanOnly() != true)
              ++bad;
    if (rules::barbarianLeadershipOnBarbarians() != true)
              ++bad;
    if (rules::barbarianLeapRunningHigh() != 21)
              ++bad;
    if (rules::barbarianLeapRunningLow() != 16)
              ++bad;
    if (rules::barbarianLeapStandingBackward() != 3)
              ++bad;
    if (rules::barbarianLeapStandingForward() != 10)
              ++bad;
    if (rules::barbarianLeapStandingUpward() != 3)
              ++bad;
    if (rules::barbarianLocaleAdaptWeeks() != 4)
              ++bad;
    if (rules::barbarianMaxWisdom() != 16)
              ++bad;
    if (rules::barbarianMoveRate() != 15)
              ++bad;
    if (rules::barbarianNoPrimeRequisite() != true)
              ++bad;
    if (rules::barbarianOutdoorCraftDruidLevel() != 3)
              ++bad;
    if (rules::barbarianRefusesMagicItems() != true)
              ++bad;
    if (rules::barbarianRequiredWeaponCount() != 3)
              ++bad;
    if (rules::barbarianSaveBonusParalysis() != 3)
              ++bad;
    if (rules::barbarianSaveBonusPoison() != 4)
              ++bad;
    if (rules::barbarianSaveBonusRodWandBreath() != 2)
              ++bad;
    if (rules::barbarianShamanException() != true)
              ++bad;
    if (rules::barbarianSpellSaveBonusPerStep() != 1)
              ++bad;
    if (rules::barbarianSpellSavePerLevels() != 4)
              ++bad;
    if (rules::barbarianSpringUpwardHigh() != 7)
              ++bad;
    if (rules::barbarianSpringUpwardLow() != 4)
              ++bad;
    if (rules::barbarianStrikeGivesNoBonus() != true)
              ++bad;
    if (rules::barbarianSurpriseFamiliar() != 4)
              ++bad;
    if (rules::barbarianSurpriseUnfamiliar() != 3)
              ++bad;
    if (rules::barbarianSurprisedFamiliar() != 5)
              ++bad;
    if (rules::barbarianSurprisedUnfamiliar() != 10)
              ++bad;
    if (rules::barbarianTertiaryCount() != 7)
              ++bad;
    if (rules::barbarianTracksAsRanger() != true)
              ++bad;
    if (rules::barbarianXpAwardForDestroying() != true)
              ++bad;
    if (rules::barbarianXpPerLevelPast11() != 500000)
              ++bad;
    if (rules::cavMoneyBelowUpperEsquired() != true)
              ++bad;
    if (rules::cavMoneyBelowUpperStartHorseman() != true)
              ++bad;
    if (rules::cavMoneyGoldRollTimesTen() != true)
              ++bad;
    if (rules::cavMoneyHorsesCompleteWithTack() != true)
              ++bad;
    if (rules::cavMoneyPaladinExceptionNoted() != true)
              ++bad;
    if (rules::cavMoneyStationCount() != 6)
              ++bad;
    if (rules::cavalierAlignmentChangeFreeLevel() != 4)
              ++bad;
    if (rules::cavalierChargeOrderCount() != 8)
              ++bad;
    if (rules::cavalierChoiceAttackLevelBonus() != 5)
              ++bad;
    if (rules::cavalierChoiceAttacksPerRoundLevel() != 16)
              ++bad;
    if (rules::cavalierCommanderLevel() != 13)
              ++bad;
    if (rules::cavalierEvilMayUsePoison() != true)
              ++bad;
    if (rules::cavalierGoodAlignmentOnly() != true)
              ++bad;
    if (rules::cavalierGoodHealPerWeekMax() != 4)
              ++bad;
    if (rules::cavalierGoodHealPerWeekMin() != 1)
              ++bad;
    if (rules::cavalierHorsemanXp() != -1500)
              ++bad;
    if (rules::cavalierHpPerLevelPast10() != 3)
              ++bad;
    if (rules::cavalierHumanMountedLevelBonus() != 1)
              ++bad;
    if (rules::cavalierIllusionSaveBonus() != 2)
              ++bad;
    if (rules::cavalierLanceDismountedDamageBonus() != 1)
              ++bad;
    if (rules::cavalierLancerXp() != -500)
              ++bad;
    if (rules::cavalierMindAffectResistPercent() != 90)
              ++bad;
    if (rules::cavalierMindPowersCount() != 10)
              ++bad;
    if (rules::cavalierNoPrimeRequisite() != true)
              ++bad;
    if (rules::cavalierPennonLevel() != 4)
              ++bad;
    if (rules::cavalierPercentileCap() != 100)
              ++bad;
    if (rules::cavalierPercentileGainDice() != 2)
              ++bad;
    if (rules::cavalierPercentileGainSides() != 10)
              ++bad;
    if (rules::cavalierPreferredWeaponCount() != 11)
              ++bad;
    if (rules::cavalierRevocationRetainsWoc() != true)
              ++bad;
    if (rules::cavalierSelfTrainFromLevel() != 6)
              ++bad;
    if (rules::cavalierShieldParryBase() != 1)
              ++bad;
    if (rules::cavalierSpecializationBanned() != true)
              ++bad;
    if (rules::cavalierSteedHighWorthNum() != 2)
              ++bad;
    if (rules::cavalierSteedHpBonusPerDie() != 2)
              ++bad;
    if (rules::cavalierSteedLowWorthNum() != 1)
              ++bad;
    if (rules::cavalierSteedWorthDen() != 3)
              ++bad;
    if (rules::cavalierTrainerLevelGap() != 2)
              ++bad;
    if (rules::cavalierTrainerMinLevel() != 4)
              ++bad;
    if (rules::cavalierXpPerLevelPast12() != 300000)
              ++bad;
    if (rules::drowSilentTongueRangeFeet() != 30)
              ++bad;
    if (rules::druidAbdicateAdditionalXp() != 500000)
              ++bad;
    if (rules::druidAbdicateBonusRelinquished() != 6)
              ++bad;
    if (rules::druidAbdicateXpAfter() != 1)
              ++bad;
    if (rules::druidAbdicateXpTotal() != 3500001)
              ++bad;
    if (rules::druidClassLevelLimit() != 23)
              ++bad;
    if (rules::duergarDayDexPenalty() != 2)
              ++bad;
    if (rules::duergarDayOpponentSaveBonus() != 2)
              ++bad;
    if (rules::duergarDayToHitPenalty() != 2)
              ++bad;
    if (rules::duergarMultiClassCount() != 4)
              ++bad;
    if (rules::duergarShadowSaveBonus() != 1)
              ++bad;
    if (rules::duergarShadowToHitPenalty() != 1)
              ++bad;
    if (rules::grandDruidAttendantCount() != 9)
              ++bad;
    if (rules::grandDruidBonusSpellLevels() != 6)
              ++bad;
    if (rules::grandDruidLevel() != 15)
              ++bad;
    if (rules::grandDruidSpellsPerLevel() != 6)
              ++bad;
    if (rules::grandDruidXpLow() != 3000001)
              ++bad;
    if (rules::greatDruidLevel() != 14)
              ++bad;
    if (rules::greatDruidXpLow() != 1500001)
              ++bad;
    if (rules::hierophantAppearanceAlterLevel() != 16)
              ++bad;
    if (rules::hierophantCastingLevelCap() != 15)
              ++bad;
    if (rules::hierophantConjureSpecialCount() != 4)
              ++bad;
    if (rules::hierophantConjureUsesPerDay() != 1)
              ++bad;
    if (rules::hierophantFirstLevel() != 16)
              ++bad;
    if (rules::hierophantHibernateLevel() != 17)
              ++bad;
    if (rules::hierophantHitDice() != 15)
              ++bad;
    if (rules::hierophantPlaneTransferenceRounds() != 1)
              ++bad;
    if (rules::hierophantPoisonImmunityLevel() != 16)
              ++bad;
    if (rules::hierophantSpellMaxPerLevel() != 6)
              ++bad;
    if (rules::hierophantSpellMaxSpellLevel() != 7)
              ++bad;
    if (rules::hierophantTopLevel() != 23)
              ++bad;
    if (rules::monkMaxHitDice() != 18)
              ++bad;
    if (rules::monkMaxHitDiceLevel() != 17)
              ++bad;
    if (rules::paladinCavalierAbilityCount() != 5)
              ++bad;
    if (rules::paladinCharismaMin() != 17)
              ++bad;
    if (rules::paladinCharismaPercentileGrowth() != true)
              ++bad;
    if (rules::paladinClericalFromLevel() != 9)
              ++bad;
    if (rules::paladinClericalMaxSpellLevel() != 4)
              ++bad;
    if (rules::paladinIsCavalierSubclass() != true)
              ++bad;
    if (rules::paladinLawfulGoodOnly() != true)
              ++bad;
    if (rules::paladinNoPrimeRequisite() != true)
              ++bad;
    if (rules::paladinPhbPowersUnchanged() != true)
              ++bad;
    if (rules::paladinRetainerRulesDiffer() != true)
              ++bad;
    if (rules::paladinRidesZeroLevelTrack() != true)
              ++bad;
    if (rules::paladinSocialStationRequired() != true)
              ++bad;
    if (rules::paladinSpecializationBanned() != true)
              ++bad;
    if (rules::paladinSponsoredByNobility() != true)
              ++bad;
    if (rules::paladinStrayBecomesCavalier() != true)
              ++bad;
    if (rules::paladinStrayStripsPowers() != true)
              ++bad;
    if (rules::paladinWisdomMin() != 13)
              ++bad;
    if (rules::rangerDruidicFromLevel() != 8)
              ++bad;
    if (rules::rangerDruidicMaxSpellLevel() != 3)
              ++bad;
    if (rules::rangerMaxHitDice() != 11)
              ++bad;
    if (rules::rangerMaxHitDiceLevel() != 10)
              ++bad;
    if (rules::rangerMuFromLevel() != 9)
              ++bad;
    if (rules::rangerMuMaxSpellLevel() != 2)
              ++bad;
    if (rules::svirfBrightLightFeet() != 30)
              ++bad;
    if (rules::svirfBrightToHitPenalty() != 1)
              ++bad;
    if (rules::svirfCamouflagePct() != 60)
              ++bad;
    if (rules::svirfDeepFoeDamageBonus() != 1)
              ++bad;
    if (rules::svirfDeepFoeToHitBonus() != 1)
              ++bad;
    if (rules::thiefScrollFromLevel() != 10)
              ++bad;
    if (rules::uaRangerGiantDamagePerLevel() != 1)
              ++bad;
    if (rules::uaRangerGiantRosterCount() != 22)
              ++bad;
    if (rules::uaRangerGiantRosterPhbCount() != 11)
              ++bad;
    if (rules::uaRangerTrackAdjustedCap() != 100)
              ++bad;
    if (rules::uaRangerTrackBaseBonus() != 10)
              ++bad;
    if (rules::uaRangerTrackBaseCap() != 110)
              ++bad;
    if (rules::uaRangerTrackBasePerLevel() != 10)
              ++bad;
    if (rules::uaRangerTrackFaintMax() != 30)
              ++bad;
    if (rules::uaRangerTrackFollowWindowHigh() != 30)
              ++bad;
    if (rules::uaRangerTrackFollowWindowLow() != 10)
              ++bad;
    if (rules::uaRangerTrackGoodLightAssumed() != true)
              ++bad;
    if (rules::uaRangerTrackHideAtRockBottomImpossible() != true)
              ++bad;
    if (rules::uaRangerTrackHideDropsCategory() != true)
              ++bad;
    if (rules::uaRangerTrackIdentifyCumulative() != true)
              ++bad;
    if (rules::uaRangerTrackIdentifyRowCount() != 10)
              ++bad;
    if (rules::uaRangerTrackIdentifySecondRoll() != true)
              ++bad;
    if (rules::uaRangerTrackIndoorBaseSame() != true)
              ++bad;
    if (rules::uaRangerTrackIndoorObservationRequired() != true)
              ++bad;
    if (rules::uaRangerTrackMoveRowCount() != 6)
              ++bad;
    if (rules::uaRangerTrackObviousMin() != 71)
              ++bad;
    if (rules::uaRangerTrackOccasionalHigh() != 70)
              ++bad;
    if (rules::uaRangerTrackOccasionalLow() != 31)
              ++bad;
    if (rules::uaRangerTrackPer12Hours() != 5)
              ++bad;
    if (rules::uaRangerTrackTerrainCategoryCount() != 4)
              ++bad;
    if (rules::uaRangerTrackTotalDarknessImpossible() != true)
              ++bad;
    if (rules::uabirthDmDecidesToMilieu() != true)
              ++bad;
    if (rules::uabirthDwarfMod() != -15)
              ++bad;
    if (rules::uabirthElfDrowMod() != -15)
              ++bad;
    if (rules::uabirthElfGrayMod() != -30)
              ++bad;
    if (rules::uabirthElfHighMod() != -20)
              ++bad;
    if (rules::uabirthElfHighModMagnitude() != 20)
              ++bad;
    if (rules::uabirthElfHighModSignLost() != false)
              ++bad;
    if (rules::uabirthElfOtherMod() != -15)
              ++bad;
    if (rules::uabirthElfWoodMod() != -10)
              ++bad;
    if (rules::uabirthGnomeMod() != -20)
              ++bad;
    if (rules::uabirthHalfElfMod() != -10)
              ++bad;
    if (rules::uabirthHalfOrcBirthMod() != 10)
              ++bad;
    if (rules::uabirthHalfOrcMaritalMod() != 75)
              ++bad;
    if (rules::uabirthHalflingMod() != -10)
              ++bad;
    if (rules::uabirthHumanNoMods() != true)
              ++bad;
    if (rules::uabirthIntroGarbled() != false)
              ++bad;
    if (rules::uabirthMarriedHigh() != 80)
              ++bad;
    if (rules::uabirthMarriedLow() != 1)
              ++bad;
    if (rules::uabirthRowCount() != 13)
              ++bad;
    if (rules::uabirthTablesAStartingPoint() != true)
              ++bad;
    if (rules::uabirthUnmarriedHigh() != 100)
              ++bad;
    if (rules::uabirthUnmarriedLow() != 81)
              ++bad;
    if (rules::uabirthUnmarriedOneClassBelowFather() != true)
              ++bad;
    if (rules::uacavtCommanderLevel() != 13)
              ++bad;
    if (rules::uacavtDiceColumnCumulative() != true)
              ++bad;
    if (rules::uacavtDirectFirstBonus() != 3)
              ++bad;
    if (rules::uacavtDirectFirstDice() != 1)
              ++bad;
    if (rules::uacavtDirectFirstSides() != 10)
              ++bad;
    if (rules::uacavtFirstLevelTrackFootnote() != true)
              ++bad;
    if (rules::uacavtHorsemanHpBonus() != 1)
              ++bad;
    if (rules::uacavtHorsemanHpDice() != 1)
              ++bad;
    if (rules::uacavtHorsemanHpDiceSides() != 4)
              ++bad;
    if (rules::uacavtHorsemanXpHigh() != -501)
              ++bad;
    if (rules::uacavtHorsemanXpLow() != -1500)
              ++bad;
    if (rules::uacavtHpPerLevelPast10() != 3)
              ++bad;
    if (rules::uacavtLancerHpBonus() != 1)
              ++bad;
    if (rules::uacavtLancerHpDice() != 2)
              ++bad;
    if (rules::uacavtLancerHpDiceSides() != 4)
              ++bad;
    if (rules::uacavtLancerXpHigh() != -1)
              ++bad;
    if (rules::uacavtLancerXpLow() != -500)
              ++bad;
    if (rules::uacavtLevel11BandDecoded() != true)
              ++bad;
    if (rules::uacavtLevel11FlatHp() != 3)
              ++bad;
    if (rules::uacavtLevel12FlatHp() != 6)
              ++bad;
    if (rules::uacavtLevel12XpUnbounded() != true)
              ++bad;
    if (rules::uacavtLevel5GridVsProseConflict() != true)
              ++bad;
    if (rules::uacavtLevel6TitleCellLost() != true)
              ++bad;
    if (rules::uacavtTrackFirstBonus() != 1)
              ++bad;
    if (rules::uacavtTrackFirstDice() != 3)
              ++bad;
    if (rules::uacavtTrackFirstSides() != 4)
              ++bad;
    if (rules::uacavtTwelveSidedHeaderSuspect() != true)
              ++bad;
    if (rules::uacavtXpPerLevelPast12() != 300000)
              ++bad;
    if (rules::uafolChevalierTravelFreedomLevel() != 9)
              ++bad;
    if (rules::uafolDiceCumulative() != false)
              ++bad;
    if (rules::uafolEquipRowCount() != 4)
              ++bad;
    if (rules::uafolEsquireLevel() != 3)
              ++bad;
    if (rules::uafolEvilBanditsBrigands() != true)
              ++bad;
    if (rules::uafolEvilMonsterCooperatePctPerLevel() != 5)
              ++bad;
    if (rules::uafolEvilMonsterFollowerPctPerLevel() != 1)
              ++bad;
    if (rules::uafolExtraManAtArmsLevel() != 8)
              ++bad;
    if (rules::uafolFollowersStartLevel() != 4)
              ++bad;
    if (rules::uafolFollowersTopLevel() != 10)
              ++bad;
    if (rules::uafolHenchmanBonusGood() != 3)
              ++bad;
    if (rules::uafolHenchmanBonusOther() != 1)
              ++bad;
    if (rules::uafolHenchmanEvilAssassins() != true)
              ++bad;
    if (rules::uafolHenchmanGoodPaladins() != true)
              ++bad;
    if (rules::uafolHenchmanNeutralThieves() != true)
              ++bad;
    if (rules::uafolHeraldGuardLevel() != 7)
              ++bad;
    if (rules::uafolLeaderFighterLevel() != 5)
              ++bad;
    if (rules::uafolLeaderTroopDenominator() != 20)
              ++bad;
    if (rules::uafolLeadersNotReplacedIfSlain() != true)
              ++bad;
    if (rules::uafolLieutenantLevel() != 3)
              ++bad;
    if (rules::uafolNeutralLeaveIfElsewhere() != true)
              ++bad;
    if (rules::uafolNeutralSpecificCause() != true)
              ++bad;
    if (rules::uafolNoGainIfRollNotHigher() != true)
              ++bad;
    if (rules::uafolPaladinNoFollowers() != true)
              ++bad;
    if (rules::uafolPaladinRetainersMustBeCavaliers() != true)
              ++bad;
    if (rules::uafolRetainerArmigerLevel() != 1)
              ++bad;
    if (rules::uafolRetainerKnightProseConflict() != true)
              ++bad;
    if (rules::uafolRetainerScutiferLevel() != 2)
              ++bad;
    if (rules::uafolRetainerStartLevel() != 4)
              ++bad;
    if (rules::uafolRetainersServeForCareAndUpkeep() != true)
              ++bad;
    if (rules::uafolRowFourBandedShieldLanceMace() != true)
              ++bad;
    if (rules::uafolRowFourStuddedLeatherLongSwordFlail() != true)
              ++bad;
    if (rules::uafolRowOneHeavyInfScalePoleArmClub() != true)
              ++bad;
    if (rules::uafolRowOneJavelinCount() != 3)
              ++bad;
    if (rules::uafolRowOneLightCavRingMailShield() != true)
              ++bad;
    if (rules::uafolRowThreeHeavyCrossbowShortSword() != true)
              ++bad;
    if (rules::uafolRowThreeLightCrossbowMilitaryFork() != true)
              ++bad;
    if (rules::uafolRowTwoLeatherPikeShortSword() != true)
              ++bad;
    if (rules::uafolRowTwoSplintMorningStarHandAxe() != true)
              ++bad;
    if (rules::uafolSeniorLeaderLevel() != 6)
              ++bad;
    if (rules::uafolSeniorLeaderTroops() != 60)
              ++bad;
    if (rules::uasocBandCount() != 9)
              ++bad;
    if (rules::uasocCavPaladinSeeMoneyHeading() != true)
              ++bad;
    if (rules::uasocDmModelsToMilieu() != true)
              ++bad;
    if (rules::uasocDwarvesGoldGemsReputation() != true)
              ++bad;
    if (rules::uasocDwarvesMMC() != true)
              ++bad;
    if (rules::uasocExceptCavaliersAndPaladins() != true)
              ++bad;
    if (rules::uasocFighterRequiresMlcMinimum() != true)
              ++bad;
    if (rules::uasocGnomeULCToLMC() != true)
              ++bad;
    if (rules::uasocGrayElfLUC() != true)
              ++bad;
    if (rules::uasocGuidelinesFollowTheTable() != true)
              ++bad;
    if (rules::uasocHalfElfSlightlyAboveHuman() != true)
              ++bad;
    if (rules::uasocHalfOrcLLC() != true)
              ++bad;
    if (rules::uasocHalflingParentheticalDivergence() != false)
              ++bad;
    if (rules::uasocHalflingULC() != true)
              ++bad;
    if (rules::uasocLlcBornOnlyThiefOrAssassin() != true)
              ++bad;
    if (rules::uasocLlcLabelCellGarbled() != false)
              ++bad;
    if (rules::uasocNonHumanPlacementMilieuDependent() != true)
              ++bad;
    if (rules::uasocPcStartMoneyUnaffected() != true)
              ++bad;
    if (rules::uasocProfessionOneRankBelowMinimum() != true)
              ++bad;
    if (rules::uasocTableExcludesPoliticalInfo() != true)
              ++bad;
    if (rules::uasocWoodElfULC() != true)
              ++bad;
    if (rules::wildElfAnimalFriendshipDeal() != 1)
              ++bad;
    if (rules::wildElfMultiClassCount() != 1)
              ++bad;
    if (rules::wildElfTrapSuccessPct() != 90)
              ++bad;
    if (rules::acrobatEvasionPercent(0) != 0)
              ++bad;
    if (rules::acrobatEvasionPercent(1) != 0)
              ++bad;
    if (rules::acrobatEvasionPercent(5) != 0)
              ++bad;
    if (rules::acrobatEvasionPercent(6) != 10)
              ++bad;
    if (rules::acrobatEvasionPercent(7) != 15)
              ++bad;
    if (rules::acrobatEvasionPercent(13) != 45)
              ++bad;
    if (rules::acrobatEvasionPercent(14) != 50)
              ++bad;
    if (rules::acrobatEvasionPercent(15) != 52)
              ++bad;
    if (rules::acrobatEvasionPercent(18) != 58)
              ++bad;
    if (rules::acrobatEvasionPercent(19) != 60)
              ++bad;
    if (rules::acrobatEvasionPercent(20) != 60)
              ++bad;
    if (rules::acrobatTightropePercent(0) != 0)
              ++bad;
    if (rules::acrobatTightropePercent(1) != 0)
              ++bad;
    if (rules::acrobatTightropePercent(5) != 0)
              ++bad;
    if (rules::acrobatTightropePercent(6) != 75)
              ++bad;
    if (rules::acrobatTightropePercent(7) != 80)
              ++bad;
    if (rules::acrobatTightropePercent(74) != 100)
              ++bad;
    if (rules::acrobatTightropePercent(75) != 100)
              ++bad;
    if (rules::acrobatTightropePercent(76) != 100)
              ++bad;
    if (rules::acrobatTightropePercent(99) != 100)
              ++bad;
    if (rules::acrobatTightropePercent(100) != 100)
              ++bad;
    if (rules::acrobatTightropePercent(101) != 100)
              ++bad;
    if (std::string(rules::acrobatTitle(0))
        != "") ++bad;
    if (std::string(rules::acrobatTitle(1))
        != "") ++bad;
    if (std::string(rules::acrobatTitle(6))
        != "Burglar-Acrobat") ++bad;
    if (std::string(rules::acrobatTitle(7))
        != "Second-Story Thief") ++bad;
    if (std::string(rules::acrobatTitle(8))
        != "Cat Burglar") ++bad;
    if (std::string(rules::acrobatTitle(9))
        != "Master Cat Burglar") ++bad;
    if (std::string(rules::acrobatTitle(10))
        != "Thief-Acrobat") ++bad;
    if (std::string(rules::acrobatTitle(11))
        != "Master Thief-Acrobat") ++bad;
    if (std::string(rules::acrobatTitle(12))
        != "Master Thief-Acrobat (12th)") ++bad;
    if (rules::acrobatTumblingAttackPercent(0) != 0)
              ++bad;
    if (rules::acrobatTumblingAttackPercent(1) != 0)
              ++bad;
    if (rules::acrobatTumblingAttackPercent(5) != 0)
              ++bad;
    if (rules::acrobatTumblingAttackPercent(6) != 6)
              ++bad;
    if (rules::acrobatTumblingAttackPercent(7) != 7)
              ++bad;
    if (rules::acrobatTumblingAttackPercent(19) != 19)
              ++bad;
    if (rules::acrobatTumblingAttackPercent(20) != 20)
              ++bad;
    if (rules::acrobatTumblingAttackPercent(21) != 20)
              ++bad;
    if (rules::barbarianBackProtectPercent(0) != 0)
              ++bad;
    if (rules::barbarianBackProtectPercent(1) != 5)
              ++bad;
    if (rules::barbarianClimbAsThiefLevel(0) != 0)
              ++bad;
    if (rules::barbarianClimbAsThiefLevel(1) != 1)
              ++bad;
    if (rules::barbarianDetectIllusionPercent(0) != 0)
              ++bad;
    if (rules::barbarianDetectIllusionPercent(1) != 5)
              ++bad;
    if (rules::barbarianDetectIllusionPercent(4) != 20)
              ++bad;
    if (rules::barbarianDetectIllusionPercent(5) != 25)
              ++bad;
    if (rules::barbarianDetectIllusionPercent(6) != 30)
              ++bad;
    if (rules::barbarianDetectIllusionPercent(74) != 75)
              ++bad;
    if (rules::barbarianDetectIllusionPercent(75) != 75)
              ++bad;
    if (rules::barbarianDetectIllusionPercent(76) != 75)
              ++bad;
    if (rules::barbarianMinAbility(1) != 0)
              ++bad;
    if (rules::barbarianMinAbility(3) != 14)
              ++bad;
    if (rules::barbarianMinAbility(4) != 15)
              ++bad;
    if (rules::barbarianStrikePlus(0) != 0)
              ++bad;
    if (rules::barbarianStrikePlus(1) != 0)
              ++bad;
    if (rules::barbarianStrikePlus(3) != 0)
              ++bad;
    if (rules::barbarianStrikePlus(4) != 1)
              ++bad;
    if (rules::barbarianStrikePlus(5) != 1)
              ++bad;
    if (rules::barbarianStrikePlus(6) != 2)
              ++bad;
    if (rules::barbarianStrikePlus(7) != 2)
              ++bad;
    if (rules::barbarianStrikePlus(8) != 3)
              ++bad;
    if (rules::barbarianStrikePlus(9) != 3)
              ++bad;
    if (rules::barbarianStrikePlus(10) != 4)
              ++bad;
    if (rules::barbarianStrikePlus(11) != 4)
              ++bad;
    if (rules::barbarianStrikePlus(12) != 5)
              ++bad;
    if (rules::barbarianStrikePlus(13) != 5)
              ++bad;
    if (rules::cavalierLanceMountedDamageBonus(0) != 0)
              ++bad;
    if (rules::cavalierLanceMountedDamageBonus(1) != 1)
              ++bad;
    if (rules::cavalierMinAbility(2) != 10)
              ++bad;
    if (rules::cavalierMinAbility(4) != 15)
              ++bad;
    if (rules::cavalierNegativeHpWindow(0) != 0)
              ++bad;
    if (rules::cavalierNegativeHpWindow(1) != 1)
              ++bad;
    if (rules::cavalierPercentileAbility(0) != true)
              ++bad;
    if (rules::cavalierPercentileAbility(1) != false)
              ++bad;
    if (rules::cavalierSaddlePercent(0) != 85)
              ++bad;
    if (rules::cavalierSaddlePercent(1) != 85)
              ++bad;
    if (rules::cavalierSaddlePercent(2) != 86)
              ++bad;
    if (rules::cavalierShieldParryMagicBonus(0) != 0)
              ++bad;
    if (rules::cavalierShieldParryMagicBonus(1) != 1)
              ++bad;
    if (std::string(rules::cavalierTitleKnown(0))
        != "") ++bad;
    if (std::string(rules::cavalierTitleKnown(1))
        != "Armiger") ++bad;
    if (std::string(rules::cavalierTitleKnown(2))
        != "Scutifer") ++bad;
    if (std::string(rules::cavalierTitleKnown(3))
        != "Esquire") ++bad;
    if (std::string(rules::cavalierTitleKnown(4))
        != "Knight Errant") ++bad;
    if (std::string(rules::cavalierTitleKnown(7))
        != "Grand Knight") ++bad;
    if (std::string(rules::cavalierTitleKnown(8))
        != "Banneret") ++bad;
    if (std::string(rules::cavalierTitleKnown(9))
        != "Chevalier") ++bad;
    if (std::string(rules::cavalierTitleKnown(10))
        != "Cavalier") ++bad;
    if (std::string(rules::cavalierTitleKnown(12))
        != "") ++bad;
    if (std::string(rules::cavalierTitleKnown(13))
        != "Cavalier Commander") ++bad;
    if (std::string(rules::cavalierTitleKnown(14))
        != "Cavalier Commander") ++bad;
    if (rules::cavalierTrackBonus(0) != 1)
              ++bad;
    if (rules::cavalierTrackBonus(1) != 3)
              ++bad;
    if (rules::cavalierTrackDice(0) != 3)
              ++bad;
    if (rules::cavalierTrackDice(1) != 1)
              ++bad;
    if (rules::cavalierTrackSides(0) != 4)
              ++bad;
    if (rules::cavalierTrackSides(1) != 10)
              ++bad;
    if (rules::halfElfAncestryExists((rules::HalfElfAncestry)0) != 1)
              ++bad;
    if (rules::halfElfAncestryExists((rules::HalfElfAncestry)1) != 1)
              ++bad;
    if (rules::hierophantConjureDesirePercent(0) != 0)
              ++bad;
    if (rules::hierophantConjureDesirePercent(1) != 1)
              ++bad;
    if (rules::hierophantConjureHpBonus(0) != 0)
              ++bad;
    if (rules::hierophantConjureHpBonus(1) != 1)
              ++bad;
    if (rules::hierophantConjureLevel(0) != 17)
              ++bad;
    if (rules::hierophantConjureLevel(1) != 18)
              ++bad;
    if (rules::hierophantConjureLevel(2) != 19)
              ++bad;
    if (rules::hierophantConjureLevel(3) != 20)
              ++bad;
    if (rules::hierophantConjureRowCount(0) != 4)
              ++bad;
    if (rules::hierophantConjureRowCount(1) != 4)
              ++bad;
    if (rules::hierophantConjureRowCount(3) != 4)
              ++bad;
    if (rules::hierophantConjureRowCount(4) != 3)
              ++bad;
    if (rules::hierophantConjureRowCount(5) != 4)
              ++bad;
    if (rules::hierophantHpBonus(0) != 0)
              ++bad;
    if (rules::hierophantHpBonus(1) != 0)
              ++bad;
    if (rules::hierophantHpBonus(15) != 0)
              ++bad;
    if (rules::hierophantHpBonus(16) != 1)
              ++bad;
    if (rules::hierophantHpBonus(17) != 2)
              ++bad;
    if (rules::hierophantHpBonus(22) != 7)
              ++bad;
    if (rules::hierophantHpBonus(23) != 8)
              ++bad;
    if (rules::hierophantHpBonus(24) != 8)
              ++bad;
    if (rules::hierophantLongevityDecades(0) != 0)
              ++bad;
    if (rules::hierophantLongevityDecades(1) != 1)
              ++bad;
    if (rules::hierophantPlaneEnterLevel(0) != 17)
              ++bad;
    if (rules::hierophantPlaneEnterLevel(1) != 18)
              ++bad;
    if (rules::hierophantPlaneEnterLevel(2) != 19)
              ++bad;
    if (rules::hierophantPlaneEnterLevel(3) != 20)
              ++bad;
    if (rules::hierophantPlaneEnterLevel(4) != 21)
              ++bad;
    if (rules::hierophantPlaneEnterLevel(5) != 22)
              ++bad;
    if (rules::hierophantPlaneEnterLevel(6) != 23)
              ++bad;
    if (std::string(rules::hierophantTitleKnown(0))
        != "") ++bad;
    if (std::string(rules::hierophantTitleKnown(1))
        != "") ++bad;
    if (std::string(rules::hierophantTitleKnown(14))
        != "Great Druid") ++bad;
    if (std::string(rules::hierophantTitleKnown(15))
        != "Grand Druid") ++bad;
    if (std::string(rules::hierophantTitleKnown(16))
        != "Hierophant Druid") ++bad;
    if (std::string(rules::hierophantTitleKnown(17))
        != "Hierophant Initiate") ++bad;
    if (std::string(rules::hierophantTitleKnown(18))
        != "Hierophant Adept") ++bad;
    if (std::string(rules::hierophantTitleKnown(19))
        != "Hierophant Master") ++bad;
    if (std::string(rules::hierophantTitleKnown(20))
        != "Numinous Hierophant") ++bad;
    if (std::string(rules::hierophantTitleKnown(22))
        != "Arcane Hierophant") ++bad;
    if (std::string(rules::hierophantTitleKnown(23))
        != "Hierophant of the Cabal") ++bad;
    if (std::string(rules::subraceName((rules::CharSubRace)1))
        != "Gray Dwarf (Duergar)") ++bad;
    if (std::string(rules::subraceName((rules::CharSubRace)2))
        != "Hill Dwarf") ++bad;
    if (std::string(rules::subraceName((rules::CharSubRace)3))
        != "Mountain Dwarf") ++bad;
    if (std::string(rules::subraceName((rules::CharSubRace)4))
        != "Dark Elf (Drow)") ++bad;
    if (std::string(rules::subraceName((rules::CharSubRace)5))
        != "Gray Elf") ++bad;
    if (std::string(rules::subraceName((rules::CharSubRace)6))
        != "High Elf") ++bad;
    if (std::string(rules::subraceName((rules::CharSubRace)7))
        != "Valley Elf") ++bad;
    if (std::string(rules::subraceName((rules::CharSubRace)8))
        != "Wild Elf (Grugach)") ++bad;
    if (std::string(rules::subraceName((rules::CharSubRace)9))
        != "Wood Elf (Sylvan)") ++bad;
    if (std::string(rules::subraceName((rules::CharSubRace)10))
        != "Deep Gnome (Svirfneblin)") ++bad;
    if (std::string(rules::subraceName((rules::CharSubRace)11))
        != "Surface Gnome") ++bad;
    if (std::string(rules::subraceName((rules::CharSubRace)12))
        != "Half-Elf") ++bad;
    if (std::string(rules::subraceName((rules::CharSubRace)13))
        != "Hairfoot Halfling") ++bad;
    if (std::string(rules::subraceName((rules::CharSubRace)14))
        != "Stout Halfling") ++bad;
    if (std::string(rules::subraceName((rules::CharSubRace)15))
        != "Tallfellow Halfling") ++bad;
    if (std::string(rules::subraceName((rules::CharSubRace)16))
        != "Half-Orc") ++bad;
    if (std::string(rules::subraceName((rules::CharSubRace)17))
        != "Human") ++bad;
    if (rules::subraceParentRace((rules::CharSubRace)3) != 1)
              ++bad;
    if (rules::subraceParentRace((rules::CharSubRace)9) != 2)
              ++bad;
    if (rules::subraceParentRace((rules::CharSubRace)11) != 3)
              ++bad;
    if (rules::subraceParentRace((rules::CharSubRace)12) != 4)
              ++bad;
    if (rules::subraceParentRace((rules::CharSubRace)15) != 5)
              ++bad;
    if (rules::subraceParentRace((rules::CharSubRace)16) != 6)
              ++bad;
    if (rules::uaClassAlignmentReq((rules::UaClass)1) != 2)
              ++bad;
    if (rules::uaClassAlignmentReq((rules::UaClass)3) != 3)
              ++bad;
    if (rules::uaClassAlignmentReq((rules::UaClass)5) != 4)
              ++bad;
    if (rules::uaClassAlignmentReq((rules::UaClass)6) != 1)
              ++bad;
    if (rules::uaClassAlignmentReq((rules::UaClass)10) != 5)
              ++bad;
    if (rules::uaClassAlignmentReq((rules::UaClass)11) != 6)
              ++bad;
    if (rules::uaClassAlignmentReq((rules::UaClass)12) != 7)
              ++bad;
    if (rules::uaClassAlignmentReq((rules::UaClass)13) != 8)
              ++bad;
    if (rules::uaClassFirstLevelDice((rules::UaClass)0) != 1)
              ++bad;
    if (rules::uaClassFirstLevelDice((rules::UaClass)1) != 1)
              ++bad;
    if (rules::uaClassHitDie((rules::UaClass)0) != 10)
              ++bad;
    if (rules::uaClassHitDie((rules::UaClass)1) != 0)
              ++bad;
    if (rules::uaClassHitDie((rules::UaClass)5) != 12)
              ++bad;
    if (rules::uaClassHitDie((rules::UaClass)6) != 8)
              ++bad;
    if (rules::uaClassHitDie((rules::UaClass)12) != 4)
              ++bad;
    if (rules::uaComelinessViewedSubraceAdj((rules::CharSubRace)0) != 0)
              ++bad;
    if (rules::uaComelinessViewedSubraceAdj((rules::CharSubRace)1) != 0)
              ++bad;
    if (rules::uaComelinessViewedSubraceAdj((rules::CharSubRace)6) != 2)
              ++bad;
    if (rules::uaComelinessViewedSubraceAdj((rules::CharSubRace)9) != 1)
              ++bad;
    if (rules::uaOilSiegeException((rules::UaClass)0) != true)
              ++bad;
    if (rules::uaOilSiegeException((rules::UaClass)1) != true)
              ++bad;
    if (rules::uaRangerTrackBaseAt(0) != 0)
              ++bad;
    if (rules::uaRangerTrackBaseAt(1) != 20)
              ++bad;
    if (rules::uaRangerTrackBaseAt(2) != 30)
              ++bad;
    if (rules::uaRangerTrackBaseAt(9) != 100)
              ++bad;
    if (rules::uaRangerTrackBaseAt(10) != 110)
              ++bad;
    if (rules::uaRangerTrackBaseAt(11) != 110)
              ++bad;
    if (rules::uaRangerTrackBaseAt(109) != 110)
              ++bad;
    if (rules::uaRangerTrackBaseAt(110) != 110)
              ++bad;
    if (rules::uaRangerTrackBaseAt(111) != 110)
              ++bad;
    if (rules::uaStationArmorBan((rules::UaClass)0) != true)
              ++bad;
    if (rules::uaStationArmorBan((rules::UaClass)1) != true)
              ++bad;
    if (rules::uaStationWeaponBan((rules::UaClass)0) != true)
              ++bad;
    if (rules::uaStationWeaponBan((rules::UaClass)1) != true)
              ++bad;
    if (rules::uacavtLevelDiceCount(0) != 1)
              ++bad;
    if (rules::uacavtLevelDiceCount(1) != 1)
              ++bad;
    if (rules::uacavtLevelDiceCount(2) != 2)
              ++bad;
    if (rules::uacavtLevelDiceCount(3) != 3)
              ++bad;
    if (rules::uacavtLevelDiceCount(9) != 9)
              ++bad;
    if (rules::uacavtLevelDiceCount(10) != 10)
              ++bad;
    if (rules::uacavtLevelDiceCount(11) != 10)
              ++bad;
    if (std::string(rules::uacavtTitle(1))
        != "Armiger") ++bad;
    if (std::string(rules::uacavtTitle(2))
        != "Scutifer") ++bad;
    if (std::string(rules::uacavtTitle(3))
        != "Esquire") ++bad;
    if (std::string(rules::uacavtTitle(4))
        != "Knight Errant") ++bad;
    if (std::string(rules::uacavtTitle(5))
        != "Knight") ++bad;
    if (std::string(rules::uacavtTitle(7))
        != "Grand Knight") ++bad;
    if (std::string(rules::uacavtTitle(8))
        != "Banneret") ++bad;
    if (std::string(rules::uacavtTitle(9))
        != "Chevalier") ++bad;
    if (std::string(rules::uacavtTitle(10))
        != "Cavalier") ++bad;
    if (std::string(rules::uacavtTitle(11))
        != "Cavalier, 11th") ++bad;
    if (std::string(rules::uacavtTitle(12))
        != "Cavalier, 12th") ++bad;
    if (std::string(rules::uacavtTitle(13))
        != "Cavalier Commander") ++bad;
    if (std::string(rules::uacavtTitle(14))
        != "Cavalier Commander") ++bad;
    if (rules::uafolDiceSides(0) != 0)
              ++bad;
    if (rules::uafolDiceSides(1) != 0)
              ++bad;
    if (rules::uafolDiceSides(3) != 0)
              ++bad;
    if (rules::uafolDiceSides(4) != 4)
              ++bad;
    if (rules::uafolDiceSides(5) != 4)
              ++bad;
    if (rules::uafolDiceSides(9) != 4)
              ++bad;
    if (rules::uafolDiceSides(10) != 4)
              ++bad;
    if (rules::uafolDiceSides(11) != 0)
              ++bad;
    if (rules::uafolEquipRowIsCavalry(-1) != false)
              ++bad;
    if (rules::uafolEquipRowIsCavalry(0) != true)
              ++bad;
    if (rules::uafolEquipRowIsCavalry(1) != false)
              ++bad;
    if (rules::uafolEquipRowIsCavalry(2) != false)
              ++bad;
    if (rules::uafolEquipRowIsCavalry(3) != true)
              ++bad;
    if (rules::uafolEquipRowIsCavalry(4) != false)
              ++bad;
    if (rules::uafolEquipRowMediumWarhorse(0) != false)
              ++bad;
    if (rules::uafolEquipRowMediumWarhorse(1) != false)
              ++bad;
    if (rules::uafolEquipRowMediumWarhorse(2) != false)
              ++bad;
    if (rules::uafolEquipRowMediumWarhorse(3) != true)
              ++bad;
    if (rules::uafolEquipRowMediumWarhorse(4) != false)
              ++bad;
{
           const char** L = nullptr;
            int n = rules::drowInnateBase(L);
            if (n != 3) ++bad;
        if (std::string(L[0])
         != "dancing lights") ++bad;
        if (std::string(L[1])
         != "faerie fire") ++bad;
        if (std::string(L[2])
         != "darkness 5 ft radius") ++bad;
}
{
           const char** L = nullptr;
            int n = rules::drowInnateAt4(L);
            if (n != 3) ++bad;
        if (std::string(L[0])
         != "detect magic") ++bad;
        if (std::string(L[1])
         != "know alignment") ++bad;
        if (std::string(L[2])
         != "levitate") ++bad;
}
{
           const char** L = nullptr;
            int n = rules::drowInnateFemale4(L);
            if (n != 4) ++bad;
        if (std::string(L[0])
         != "clairvoyance") ++bad;
        if (std::string(L[1])
         != "detect lie") ++bad;
        if (std::string(L[2])
         != "suggestion") ++bad;
        if (std::string(L[3])
         != "dispel magic") ++bad;
}
{
           const char** L = nullptr;
            int n = rules::svirfInnate(L);
            if (n != 3) ++bad;
        if (std::string(L[0])
         != "blindness") ++bad;
        if (std::string(L[1])
         != "blur") ++bad;
        if (std::string(L[2])
         != "change self") ++bad;
}
   for (int s = 0; s < 18; ++s) {
    const rules::SubRaceTraits& t =
           rules::subraceTraits((rules::CharSubRace)s);
          if (s == 1) {
           if (t.adj[0] != 0)
                  ++bad;
           if (t.adj[1] != 0)
                  ++bad;
           if (t.adj[2] != 0)
                  ++bad;
           if (t.adj[3] != 0)
                  ++bad;
           if (t.adj[4] != 0)
                  ++bad;
           if (t.adj[5] != 0)
                  ++bad;
            if (t.max[0] != 0)
                  ++bad;
            if (t.max[1] != 0)
                  ++bad;
            if (t.max[2] != 0)
                  ++bad;
            if (t.max[3] != 0)
                  ++bad;
            if (t.max[4] != 0)
                  ++bad;
            if (t.max[5] != 0)
                  ++bad;
        if (t.infravisionFeet != 120)
                  ++bad;
        if (t.saveVsMagicBonus != 0)
                  ++bad;
        if (t.saveVsPoisonBonus != 0)
                  ++bad;
        if (t.saveOtherBonus != 0)
                  ++bad;
        if (t.illusionImmune != 1)
                  ++bad;
        if (t.paralysisImmune != 1)
                  ++bad;
        if (t.magicPoisonImmune != 1)
                  ++bad;
        if (t.surpriseOn != 3)
                  ++bad;
        if (t.surpriseDie != 6)
                  ++bad;
        if (t.surprisedOn != 1)
                  ++bad;
        if (t.surprisedDie != 10)
                  ++bad;
        if (t.moveFemale != 0)
                  ++bad;
        if (t.moveMale != 0)
                  ++bad;
        if (t.twoWeaponFree != 0)
                  ++bad;
        if (t.losesSwordBowBonus != 0)
                  ++bad;
        if (t.maleOnlyPC != 0)
                  ++bad;
        if (t.noPsionics != 0)
                  ++bad;
           }
          if (s == 4) {
           if (t.adj[0] != 0)
                  ++bad;
           if (t.adj[1] != 0)
                  ++bad;
           if (t.adj[2] != 0)
                  ++bad;
           if (t.adj[3] != 0)
                  ++bad;
           if (t.adj[4] != 0)
                  ++bad;
           if (t.adj[5] != 0)
                  ++bad;
            if (t.max[0] != 0)
                  ++bad;
            if (t.max[1] != 0)
                  ++bad;
            if (t.max[2] != 0)
                  ++bad;
            if (t.max[3] != 0)
                  ++bad;
            if (t.max[4] != 0)
                  ++bad;
            if (t.max[5] != 0)
                  ++bad;
        if (t.infravisionFeet != 120)
                  ++bad;
        if (t.saveVsMagicBonus != 2)
                  ++bad;
        if (t.saveVsPoisonBonus != 0)
                  ++bad;
        if (t.saveOtherBonus != 0)
                  ++bad;
        if (t.illusionImmune != 0)
                  ++bad;
        if (t.paralysisImmune != 0)
                  ++bad;
        if (t.magicPoisonImmune != 0)
                  ++bad;
        if (t.surpriseOn != 0)
                  ++bad;
        if (t.surpriseDie != 0)
                  ++bad;
        if (t.surprisedOn != 1)
                  ++bad;
        if (t.surprisedDie != 8)
                  ++bad;
        if (t.moveFemale != 15)
                  ++bad;
        if (t.moveMale != 12)
                  ++bad;
        if (t.twoWeaponFree != 1)
                  ++bad;
        if (t.losesSwordBowBonus != 1)
                  ++bad;
        if (t.maleOnlyPC != 0)
                  ++bad;
        if (t.noPsionics != 0)
                  ++bad;
           }
  if (s == 5 && t.adj[1] != 1)
                     ++bad;
 if (s == 5 && t.max[1] != 19)
                      ++bad;
  if (s == 7 && t.adj[1] != 1)
                     ++bad;
 if (s == 7 && t.max[1] != 19)
                      ++bad;
  if (s == 8 && t.adj[0] != 2)
                     ++bad;
  if (s == 9 && t.adj[0] != 1)
                     ++bad;
  if (s == 9 && t.adj[1] != -1)
                     ++bad;
          if (s == 10) {
           if (t.adj[0] != 0)
                  ++bad;
           if (t.adj[1] != 0)
                  ++bad;
           if (t.adj[2] != 0)
                  ++bad;
           if (t.adj[3] != 0)
                  ++bad;
           if (t.adj[4] != 0)
                  ++bad;
           if (t.adj[5] != 0)
                  ++bad;
            if (t.max[0] != 0)
                  ++bad;
            if (t.max[1] != 0)
                  ++bad;
            if (t.max[2] != 0)
                  ++bad;
            if (t.max[3] != 0)
                  ++bad;
            if (t.max[4] != 0)
                  ++bad;
            if (t.max[5] != 0)
                  ++bad;
        if (t.infravisionFeet != 120)
                  ++bad;
        if (t.saveVsMagicBonus != 0)
                  ++bad;
        if (t.saveVsPoisonBonus != 2)
                  ++bad;
        if (t.saveOtherBonus != 3)
                  ++bad;
        if (t.illusionImmune != 1)
                  ++bad;
        if (t.paralysisImmune != 0)
                  ++bad;
        if (t.magicPoisonImmune != 0)
                  ++bad;
        if (t.surpriseOn != 9)
                  ++bad;
        if (t.surpriseDie != 10)
                  ++bad;
        if (t.surprisedOn != 1)
                  ++bad;
        if (t.surprisedDie != 12)
                  ++bad;
        if (t.moveFemale != 0)
                  ++bad;
        if (t.moveMale != 0)
                  ++bad;
        if (t.twoWeaponFree != 0)
                  ++bad;
        if (t.losesSwordBowBonus != 0)
                  ++bad;
        if (t.maleOnlyPC != 1)
                  ++bad;
        if (t.noPsionics != 1)
                  ++bad;
           }
   }
         int en = 0;
         const rules::EarthElementalRow* R =
           rules::svirfEarthElementalTable(en);
        if (en != 6) ++bad;
     if (R[0].lo != 1 || R[0].hi != 1)
             ++bad;
     if (std::string(R[0].result)
        != "24 HD earth elemental") ++bad;
     if (R[1].lo != 2 || R[1].hi != 6)
             ++bad;
     if (std::string(R[1].result)
        != "16 HD earth elemental") ++bad;
     if (R[2].lo != 7 || R[2].hi != 10)
             ++bad;
     if (std::string(R[2].result)
        != "12 HD earth elemental") ++bad;
     if (R[3].lo != 11 || R[3].hi != 15)
             ++bad;
     if (std::string(R[3].result)
        != "8 HD earth elemental") ++bad;
     if (R[4].lo != 16 || R[4].hi != 18)
             ++bad;
     if (std::string(R[4].result)
        != "xorn") ++bad;
     if (R[5].lo != 19 || R[5].hi != 20)
             ++bad;
     if (std::string(R[5].result)
        != "summoning fails, not retryable that day") ++bad;
        }
        printf("R1056 uaclasses registry edges audit: bad %d\n", bad);
    }
