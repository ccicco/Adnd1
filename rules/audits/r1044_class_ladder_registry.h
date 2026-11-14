    // ==== R1044: class ladder registry ======================================
    // The R1044 de-wire: the six subclass
    // xp-title ladders (11/12/14/12/15/17
    // rows) and the bard ladder (23) ride
    // items::MiscItemRegistry from
    // content/tables/class_ladders/ (def
    // keys = the SubclassDef name fields,
    // plus "bard_ladder"); this audit loads
    // its own registry instance and cross-reads
    // every row through the inline accessor
    // surface (subclassXpFor/subclassTitle/
    // bardXpForLevel/bardTitle), so the r179,
    // r186 and r327 audits and this registry
    // audit read the same data.
    {
        int bad = 0;
        // -- 1. load --------------------------------------
        {
            items::MiscItemRegistry t;
            if (t.loadDirectory("content/tables/class_ladders") != 7)
                ++bad;
            if (!t.errors().empty()) ++bad;
            if (t.all().size() != 7) ++bad;
            if (t.all().count("paladin") != 1) ++bad;
            if (t.all().count("ranger") != 1) ++bad;
            if (t.all().count("druid") != 1) ++bad;
            if (t.all().count("illusionist") != 1) ++bad;
            if (t.all().count("assassin") != 1) ++bad;
            if (t.all().count("monk") != 1) ++bad;
            if (t.all().count("bard_ladder") != 1) ++bad;
            if (t.all().count("subclass_paladin")) ++bad;
            if (t.all().count("weapon_chart")) ++bad;
            if (t.all().count("equipment_armor")) ++bad;
            if (t.all().count("treasure_potions")) ++bad;
            if (t.all().count("")) ++bad;
        }
        printf("R1044 class ladder registry load audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 2. counts ------------------------------------
        {
            items::MiscItemRegistry t;
            t.loadDirectory("content/tables/class_ladders");
            if (rules::subclassCount() != 6) ++bad;
            const auto* d_0 = t.find("paladin");
            if (!d_0 || (int)d_0->rows.size() != 11) ++bad;
            if (d_0 && ((int)d_0->pins.size() != 1
                       || d_0->pins[0].name
                              != std::string("paladinRowCount")
                       || d_0->pins[0].value != 11)) ++bad;
            if (d_0 && (int)d_0->sources.size() != 1) ++bad;
            const auto* d_1 = t.find("ranger");
            if (!d_1 || (int)d_1->rows.size() != 12) ++bad;
            if (d_1 && ((int)d_1->pins.size() != 1
                       || d_1->pins[0].name
                              != std::string("rangerRowCount")
                       || d_1->pins[0].value != 12)) ++bad;
            if (d_1 && (int)d_1->sources.size() != 1) ++bad;
            const auto* d_2 = t.find("druid");
            if (!d_2 || (int)d_2->rows.size() != 14) ++bad;
            if (d_2 && ((int)d_2->pins.size() != 1
                       || d_2->pins[0].name
                              != std::string("druidRowCount")
                       || d_2->pins[0].value != 14)) ++bad;
            if (d_2 && (int)d_2->sources.size() != 1) ++bad;
            const auto* d_3 = t.find("illusionist");
            if (!d_3 || (int)d_3->rows.size() != 12) ++bad;
            if (d_3 && ((int)d_3->pins.size() != 1
                       || d_3->pins[0].name
                              != std::string("illusionistRowCount")
                       || d_3->pins[0].value != 12)) ++bad;
            if (d_3 && (int)d_3->sources.size() != 1) ++bad;
            const auto* d_4 = t.find("assassin");
            if (!d_4 || (int)d_4->rows.size() != 15) ++bad;
            if (d_4 && ((int)d_4->pins.size() != 1
                       || d_4->pins[0].name
                              != std::string("assassinRowCount")
                       || d_4->pins[0].value != 15)) ++bad;
            if (d_4 && (int)d_4->sources.size() != 1) ++bad;
            const auto* d_5 = t.find("monk");
            if (!d_5 || (int)d_5->rows.size() != 17) ++bad;
            if (d_5 && ((int)d_5->pins.size() != 1
                       || d_5->pins[0].name
                              != std::string("monkRowCount")
                       || d_5->pins[0].value != 17)) ++bad;
            if (d_5 && (int)d_5->sources.size() != 1) ++bad;
            const auto* d_b = t.find("bard_ladder");
            if (!d_b || (int)d_b->rows.size() != 23) ++bad;
            if (d_b && ((int)d_b->pins.size() != 1
                       || d_b->pins[0].name
                              != std::string("bard_ladderRowCount")
                       || d_b->pins[0].value != 23)) ++bad;
            if (rules::subclassDef(0).xpRowCount != 11) ++bad;
            if (rules::subclassDef(0).titleCount != 11) ++bad;
            if (rules::subclassDef(1).xpRowCount != 12) ++bad;
            if (rules::subclassDef(1).titleCount != 12) ++bad;
            if (rules::subclassDef(2).xpRowCount != 14) ++bad;
            if (rules::subclassDef(2).titleCount != 14) ++bad;
            if (rules::subclassDef(3).xpRowCount != 12) ++bad;
            if (rules::subclassDef(3).titleCount != 12) ++bad;
            if (rules::subclassDef(4).xpRowCount != 15) ++bad;
            if (rules::subclassDef(4).titleCount != 15) ++bad;
            if (rules::subclassDef(5).xpRowCount != 17) ++bad;
            if (rules::subclassDef(5).titleCount != 17) ++bad;
        }
        printf("R1044 class ladder registry counts audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 3. bands (the level axis) --------------------
        {
            items::MiscItemRegistry t;
            t.loadDirectory("content/tables/class_ladders");
            for (const auto& kv : t.all()) {
                const auto& d = kv.second;
                const int n = (int)d.rows.size();
                for (int i = 0; i < n; ++i)
                    if (d.rows[i].bandLo != i + 1
                        || d.rows[i].bandHi != i + 1
                        || d.rows[i].set != d.key
                        || d.rows[i].gpHi != 0
                        || d.rows[i].xp != 0
                        || d.rows[i].xpHi != 0
                        || d.rows[i].qtyLo != 0
                        || d.rows[i].qtyHi != 0) ++bad;
                for (int i = 0; i < n; ++i) {
                    if (d.rows[i].gp < 0) ++bad;
                    if (d.rows[i].name.empty()) ++bad;
                    if (i > 0
                        && d.rows[i].gp <= d.rows[i - 1].gp)
                        ++bad;   // strictly increasing
                }
            }
        }
        printf("R1044 class ladder registry bands audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 4. data (famous pins, all computed) ----------
        {
            if (rules::subclassXpFor(0, 1) != 0) ++bad;
            if (rules::subclassXpFor(0, 11) != 1050000) ++bad;
            if (rules::subclassXpFor(1, 12) != 975000) ++bad;
            if (rules::subclassXpFor(2, 9) != 90000) ++bad;
            if (rules::subclassXpFor(3, 10) != 220000) ++bad;
            if (rules::subclassXpFor(4, 15) != 1500000) ++bad;
            if (rules::subclassXpFor(5, 17) != 3250000) ++bad;
            if (std::string(rules::subclassTitle(0, 1))
                    != std::string("Gallant")) ++bad;
            if (std::string(rules::subclassTitle(2, 14))
                    != std::string("The Great Druid")) ++bad;
            if (std::string(rules::subclassTitle(4, 15))
                    != std::string("Grandfather of Assassins")) ++bad;
            if (std::string(rules::subclassTitle(5, 17))
                    != std::string("Grand Master of Flowers")) ++bad;
            if (rules::bardXpForLevel(2) != 2001) ++bad;
            if (rules::bardXpForLevel(23) != 3000001) ++bad;
            if (std::string(rules::bardTitle(1))
                    != std::string("Rhymer")) ++bad;
            if (std::string(rules::bardTitle(12))
                    != std::string("Master Bard")) ++bad;
            if (std::string(rules::bardTitle(23))
                    != std::string("M. Bard 23rd")) ++bad;
            if (std::string(rules::subclassDef(0).name)
                    != std::string("paladin")) ++bad;
            if (rules::subclassDef(0).base != 0
                || rules::subclassDef(0).group != 0
                || rules::subclassDef(0).levelCap != 9
                || rules::subclassDef(0).hpBeyondCap != 3
                || rules::subclassDef(0).hitDie != 10
                || rules::subclassDef(0).twoDiceFirstLevel
                       != 0
                || rules::subclassDef(0).xpAdder != 350000
                || rules::subclassDef(0).prime != 0) ++bad;
            if (std::string(rules::subclassDef(1).name)
                    != std::string("ranger")) ++bad;
            if (rules::subclassDef(1).base != 0
                || rules::subclassDef(1).group != 0
                || rules::subclassDef(1).levelCap != 10
                || rules::subclassDef(1).hpBeyondCap != 2
                || rules::subclassDef(1).hitDie != 8
                || rules::subclassDef(1).twoDiceFirstLevel
                       != 1
                || rules::subclassDef(1).xpAdder != 325000
                || rules::subclassDef(1).prime != 0) ++bad;
            if (std::string(rules::subclassDef(2).name)
                    != std::string("druid")) ++bad;
            if (rules::subclassDef(2).base != 2
                || rules::subclassDef(2).group != 1
                || rules::subclassDef(2).levelCap != 14
                || rules::subclassDef(2).hpBeyondCap != 2
                || rules::subclassDef(2).hitDie != 8
                || rules::subclassDef(2).twoDiceFirstLevel
                       != 0
                || rules::subclassDef(2).xpAdder != 0
                || rules::subclassDef(2).prime != 2) ++bad;
            if (std::string(rules::subclassDef(3).name)
                    != std::string("illusionist")) ++bad;
            if (rules::subclassDef(3).base != 1
                || rules::subclassDef(3).group != 2
                || rules::subclassDef(3).levelCap != 10
                || rules::subclassDef(3).hpBeyondCap != 1
                || rules::subclassDef(3).hitDie != 4
                || rules::subclassDef(3).twoDiceFirstLevel
                       != 0
                || rules::subclassDef(3).xpAdder != 220000
                || rules::subclassDef(3).prime != 1) ++bad;
            if (std::string(rules::subclassDef(4).name)
                    != std::string("assassin")) ++bad;
            if (rules::subclassDef(4).base != 3
                || rules::subclassDef(4).group != 3
                || rules::subclassDef(4).levelCap != 10
                || rules::subclassDef(4).hpBeyondCap != 2
                || rules::subclassDef(4).hitDie != 6
                || rules::subclassDef(4).twoDiceFirstLevel
                       != 0
                || rules::subclassDef(4).xpAdder != 0
                || rules::subclassDef(4).prime != 3) ++bad;
            if (std::string(rules::subclassDef(5).name)
                    != std::string("monk")) ++bad;
            if (rules::subclassDef(5).base != -1
                || rules::subclassDef(5).group != 3
                || rules::subclassDef(5).levelCap != 17
                || rules::subclassDef(5).hpBeyondCap != 0
                || rules::subclassDef(5).hitDie != 4
                || rules::subclassDef(5).twoDiceFirstLevel
                       != 1
                || rules::subclassDef(5).xpAdder != 0
                || rules::subclassDef(5).prime != 0) ++bad;
            if (rules::bardHitDice(23) != 22) ++bad;
            if (rules::bardDruidCastLevel(23) != 13) ++bad;
            if (rules::bardDruidCastLevel(13) != 12) ++bad;
        }
        printf("R1044 class ladder registry data audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 5. rows (the full cross-read) ----------------
        {
            items::MiscItemRegistry t;
            t.loadDirectory("content/tables/class_ladders");
            const auto* v_0 = t.find("paladin");
            if (!v_0) { ++bad; } else {
                for (int l = 1; l <= 11; ++l) {
                    if (rules::subclassXpFor(0, l)
                            != v_0->rows[l - 1].gp
                        || std::string(rules::subclassTitle(0, l))
                            != v_0->rows[l - 1].name) ++bad;
                }
            }
            const auto* v_1 = t.find("ranger");
            if (!v_1) { ++bad; } else {
                for (int l = 1; l <= 12; ++l) {
                    if (rules::subclassXpFor(1, l)
                            != v_1->rows[l - 1].gp
                        || std::string(rules::subclassTitle(1, l))
                            != v_1->rows[l - 1].name) ++bad;
                }
            }
            const auto* v_2 = t.find("druid");
            if (!v_2) { ++bad; } else {
                for (int l = 1; l <= 14; ++l) {
                    if (rules::subclassXpFor(2, l)
                            != v_2->rows[l - 1].gp
                        || std::string(rules::subclassTitle(2, l))
                            != v_2->rows[l - 1].name) ++bad;
                }
            }
            const auto* v_3 = t.find("illusionist");
            if (!v_3) { ++bad; } else {
                for (int l = 1; l <= 12; ++l) {
                    if (rules::subclassXpFor(3, l)
                            != v_3->rows[l - 1].gp
                        || std::string(rules::subclassTitle(3, l))
                            != v_3->rows[l - 1].name) ++bad;
                }
            }
            const auto* v_4 = t.find("assassin");
            if (!v_4) { ++bad; } else {
                for (int l = 1; l <= 15; ++l) {
                    if (rules::subclassXpFor(4, l)
                            != v_4->rows[l - 1].gp
                        || std::string(rules::subclassTitle(4, l))
                            != v_4->rows[l - 1].name) ++bad;
                }
            }
            const auto* v_5 = t.find("monk");
            if (!v_5) { ++bad; } else {
                for (int l = 1; l <= 17; ++l) {
                    if (rules::subclassXpFor(5, l)
                            != v_5->rows[l - 1].gp
                        || std::string(rules::subclassTitle(5, l))
                            != v_5->rows[l - 1].name) ++bad;
                }
            }
            const auto* v_b = t.find("bard_ladder");
            if (!v_b) { ++bad; } else {
                for (int lv = 1; lv <= 23; ++lv) {
                    if (rules::bardXpForLevel(lv)
                            != v_b->rows[lv - 1].gp
                        || std::string(rules::bardTitle(lv))
                            != v_b->rows[lv - 1].name) ++bad;
                }
            }
        }
        printf("R1044 class ladder registry rows audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 6. edges (adders, clamps, negatives) --------
        {
            if (rules::subclassXpFor(0, 12) != 1400000
                || rules::subclassXpFor(0, 13) != 1750000) ++bad;
            if (rules::subclassXpFor(1, 13) != 1300000
                || rules::subclassXpFor(1, 14) != 1625000) ++bad;
            if (rules::subclassXpFor(2, 15) != 1500000
                || rules::subclassXpFor(2, 17) != 1500000) ++bad;
            if (rules::subclassXpFor(3, 13) != 880000
                || rules::subclassXpFor(3, 14) != 1100000) ++bad;
            if (rules::subclassXpFor(4, 16) != 1500000
                || rules::subclassXpFor(4, 18) != 1500000) ++bad;
            if (rules::subclassXpFor(5, 18) != 3250000
                || rules::subclassXpFor(5, 20) != 3250000) ++bad;
            if (rules::subclassXpFor(0, 0) != 0) ++bad;
            if (rules::subclassXpFor(5, -3) != 0) ++bad;
            if (rules::subclassXpFor(-1, 9)
                    != rules::subclassXpFor(0, 9)) ++bad;
            if (rules::subclassXpFor(99, 9)
                    != rules::subclassXpFor(5, 9)) ++bad;
            if (std::string(rules::subclassTitle(0, -1))
                    != std::string("Gallant")) ++bad;
            if (std::string(rules::subclassTitle(2, 999))
                    != std::string("The Great Druid")) ++bad;
            if (std::string(rules::subclassDef(-1).name)
                    != std::string("paladin")
                || std::string(rules::subclassDef(99).name)
                       != std::string("monk")) ++bad;
            if (rules::bardXpForLevel(0) != 0) ++bad;
            if (rules::bardXpForLevel(99) != 3000001) ++bad;
            if (rules::bardXpForLevel(-4) != 0) ++bad;
            if (std::string(rules::bardTitle(24))
                    != std::string("M. Bard 23rd")) ++bad;
            if (std::string(rules::bardTitle(0))
                    != std::string("Rhymer")) ++bad;
            if (!rules::scLadder("no_such_ladder").empty())
                ++bad;
            if (rules::ladderReg().find("paladi") != nullptr) ++bad;
            if (rules::ladderReg().find("") != nullptr) ++bad;
            if (rules::subclassXpFor(0, 1) != 0) ++bad;
        }
        printf("R1044 class ladder registry edges audit: bad %d\n", bad);
    }
