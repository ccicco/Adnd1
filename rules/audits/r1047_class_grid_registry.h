    // ==== R1047: class grid registry ================================
    // The R1047 de-wire: the PHB class grids
    // (the bard college column 23, the bard
    // druid slots 23 x 5, the druid slots
    // 14 x 7) ride items::MiscItemRegistry
    // from content/tables/class_grids/ (def
    // keys bard_colleges, bard_druid_slots,
    // druid_slots). This audit loads its own
    // registry instance and cross-reads every
    // cell through the inline accessor surface
    // (bardCollege/bardDruidSlots/
    // druidSpellSlots) and the gridRows/
    // gridValues seam, so the r186/r228/r235a
    // audits and this registry audit read the
    // same data through the same signatures.
    {
        int bad = 0;
        // -- 1. load ---------------------------------------
        {
            items::MiscItemRegistry t;
            if (t.loadDirectory("content/tables/class_grids") != 3)
                ++bad;
            if (!t.errors().empty()) ++bad;
            if (t.all().size() != 3) ++bad;
            if (t.all().count("bard_colleges") != 1) ++bad;
            if (t.all().count("bard_druid_slots") != 1) ++bad;
            if (t.all().count("druid_slots") != 1) ++bad;
            if (t.all().count("bard_ladder")) ++bad;
            if (t.all().count("bard_college")) ++bad;
            if (t.all().count("druid_slot")) ++bad;
            if (t.all().count("appendixa_door_location")) ++bad;
            if (t.all().count("")) ++bad;
        }
        printf("R1047 class grid registry load audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 2. counts -------------------------------------
        {
            items::MiscItemRegistry t;
            t.loadDirectory("content/tables/class_grids");
            const auto* vc = t.find("bard_colleges");
            if (!vc) { ++bad; } else {
                if ((int)vc->rows.size() != 23)
                    ++bad;
                if ((int)vc->pins.size() != 1
                    || vc->pins[0].name != std::string("bard_collegesRowCount")
                    || vc->pins[0].value != 23)
                    ++bad;
                if ((int)vc->sources.size() != 1
                    || (int)vc->tables.size() != 0)
                    ++bad;
            }
            const auto* vb = t.find("bard_druid_slots");
            if (!vb) { ++bad; } else {
                if ((int)vb->rows.size() != 0)
                    ++bad;
                if ((int)vb->pins.size() != 2
                    || vb->pins[0].name != std::string(
                        "bard_druid_slotsRowCount")
                    || vb->pins[0].value != 23
                    || vb->pins[1].name != std::string(
                        "bard_druid_slotsColCount")
                    || vb->pins[1].value != 5)
                    ++bad;
                if ((int)vb->sources.size() != 1
                    || (int)vb->tables.size() != 1)
                    ++bad;
            }
            const auto* vd = t.find("druid_slots");
            if (!vd) { ++bad; } else {
                if ((int)vd->rows.size() != 0)
                    ++bad;
                if ((int)vd->pins.size() != 2
                    || vd->pins[0].name != std::string(
                        "druid_slotsRowCount")
                    || vd->pins[0].value != 14
                    || vd->pins[1].name != std::string(
                        "druid_slotsColCount")
                    || vd->pins[1].value != 7)
                    ++bad;
                if ((int)vd->sources.size() != 1
                    || (int)vd->tables.size() != 1)
                    ++bad;
            }
        }
        printf("R1047 class grid registry counts audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 3. bands (the level axis) ------------
        {
            items::MiscItemRegistry t;
            t.loadDirectory("content/tables/class_grids");
            const auto* vc = t.find("bard_colleges");
            if (!vc) { ++bad; } else {
                for (int i = 0;
                     i < (int)vc->rows.size(); ++i) {
                    const auto& r = vc->rows[i];
                    if (r.bandLo != i + 1
                        || r.bandHi != i + 1
                        || r.set != vc->key
                        || r.name.empty()
                        || r.gp != 0
                        || r.gpHi != 0
                        || r.xp != 0
                        || r.xpHi != 0
                        || r.qtyLo != 0
                        || r.qtyHi != 0) ++bad;
                }
            }
            const auto* vb = t.find("bard_druid_slots");
            if (!vb) { ++bad; } else {
                if (vb->tables[0].name !=
                    std::string("grid")
                    || (int)vb->tables[0].values.size()
                       != 115) ++bad;
                for (long long x : vb->tables[0].values)
                    if (x < 0 || x > 9) ++bad;
            }
            const auto* vd = t.find("druid_slots");
            if (!vd) { ++bad; } else {
                if (vd->tables[0].name !=
                    std::string("grid")
                    || (int)vd->tables[0].values.size()
                       != 98) ++bad;
                for (long long x : vd->tables[0].values)
                    if (x < 0 || x > 9) ++bad;
            }
        }
        printf("R1047 class grid registry bands audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 4. data (famous pins, all computed) --
        {
            if (std::string(rules::bardCollege(1))
                    != std::string("Probationer")) ++bad;
            if (std::string(rules::bardCollege(12))
                    != std::string("Canaith")) ++bad;
            if (std::string(rules::bardCollege(23))
                    != std::string("Magna Alumnae")) ++bad;
            if (rules::gridRows("bard_colleges")[11].name
                    != std::string("Canaith")) ++bad;
            if (rules::bardDruidSlots(1, 1) != 1)
                ++bad;
            if (rules::bardDruidSlots(23, 5) != 5)
                ++bad;
            if (rules::bardDruidSlots(16, 1) != 4)
                ++bad;
            if (rules::bardDruidSlots(10, 4) != 1)
                ++bad;
            if (rules::bardDruidSlots(14, 5) != 2)
                ++bad;
            if (rules::druidSpellSlots(1, 1) != 2)
                ++bad;
            if (rules::druidSpellSlots(14, 7) != 3)
                ++bad;
            if (rules::druidSpellSlots(12, 4) != 4)
                ++bad;
            if (rules::druidSpellSlots(9, 5) != 1)
                ++bad;
            if (rules::druidSpellSlots(13, 4) != 5)
                ++bad;
        }
        printf("R1047 class grid registry data audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 5. rows (the full cross-read) --------
        {
            items::MiscItemRegistry t;
            t.loadDirectory("content/tables/class_grids");
            const auto* vc = t.find("bard_colleges");
            if (!vc) { ++bad; } else {
                for (int lv = 1; lv <= 23; ++lv)
                    if (std::string(rules::bardCollege(lv))
                            != vc->rows[lv - 1].name)
                        ++bad;
            }
            const auto* vb = t.find("bard_druid_slots");
            if (!vb) { ++bad; } else {
                const auto& g =
                    vb->tables[0].values;
                for (int lv = 1; lv <= 23; ++lv)
                    for (int sl = 1; sl <= 5; ++sl)
                        if (rules::bardDruidSlots(lv, sl)
                                != (int)g[(lv - 1) * 5
                                    + (sl - 1)])
                            ++bad;
            }
            const auto* vd = t.find("druid_slots");
            if (!vd) { ++bad; } else {
                const auto& g =
                    vd->tables[0].values;
                for (int lv = 1; lv <= 14; ++lv)
                    for (int sl = 1; sl <= 7; ++sl)
                        if (rules::druidSpellSlots(lv, sl)
                                != (int)g[(lv - 1) * 7
                                    + (sl - 1)])
                            ++bad;
            }
        }
        printf("R1047 class grid registry rows audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 6. edges (clamps, negatives) ----------
        {
            if (rules::bardDruidSlots(0, 1) != 0)
                ++bad;
            if (rules::bardDruidSlots(24, 3)
                    != rules::bardDruidSlots(23, 3))
                ++bad;
            if (rules::bardDruidSlots(24, 6)
                    != rules::bardDruidSlots(23, 5))
                ++bad;
            if (rules::bardDruidSlots(5, 0)
                    != rules::bardDruidSlots(5, 1))
                ++bad;
            if (rules::druidSpellSlots(0, 1)
                    != rules::druidSpellSlots(1, 1))
                ++bad;
            if (rules::druidSpellSlots(99, 7)
                    != rules::druidSpellSlots(14, 7))
                ++bad;
            if (rules::druidSpellSlots(14, 8)
                    != rules::druidSpellSlots(14, 7))
                ++bad;
            if (rules::druidSpellSlots(14, 0)
                    != rules::druidSpellSlots(14, 1))
                ++bad;
            if (std::string(rules::bardCollege(0))
                    != std::string("Probationer")) ++bad;
            if (std::string(rules::bardCollege(99))
                    != std::string("Magna Alumnae")) ++bad;
            if (!rules::gridValues("no_such_table").empty())
                ++bad;
            if (!rules::gridRows("no_such_table").empty())
                ++bad;
            if (rules::gridReg().find("bard_ladder")
                    != nullptr) ++bad;
            if (rules::gridReg().find("") != nullptr)
                ++bad;
        }
        printf("R1047 class grid registry edges audit: bad %d\n", bad);
    }
