    // ==== R1048: straggler registry =================================
    // The R1048 de-wire: the four stragglers
    // (paladin 12 x 4 and ranger 10 x 5 slot
    // grids, the Appendix G trap list 46 d%
    // bands, the WSG inedible 1d8 and cyclone
    // drift 2d6 dispatches) ride
    // items::MiscItemRegistry from
    // content/tables/{class_slots,appendixg,
    // wsg}/. This audit loads its own
    // registry instances and cross-reads every
    // cell and band through the inline accessor
    // surface, so the r125/r184/r463/r494
    // audits and this registry audit read the
    // same data through the same signatures.
    {
        int bad = 0;
        // -- 1. load ---------------------------------------
        {
            items::MiscItemRegistry ts;
            if (ts.loadDirectory("content/tables/class_slots")
                    != 2) ++bad;
            if (!ts.errors().empty()) ++bad;
            if ((int)ts.all().size() != 2) ++bad;
            items::MiscItemRegistry tg;
            if (tg.loadDirectory("content/tables/appendixg")
                    != 1) ++bad;
            if (!tg.errors().empty()) ++bad;
            if ((int)tg.all().size() != 1) ++bad;
            items::MiscItemRegistry tw;
            if (tw.loadDirectory("content/tables/wsg")
                    != 2) ++bad;
            if (!tw.errors().empty()) ++bad;
            if ((int)tw.all().size() != 2) ++bad;
            if (!ts.all().count("paladin_slots")) ++bad;
            if (!ts.all().count("ranger_slots")) ++bad;
            if (!tg.all().count("trap_list")) ++bad;
            if (!tw.all().count("wsg_inedible_bands")) ++bad;
            if (!tw.all().count("wsg_cyclone_drift_bands")) ++bad;
            if (ts.all().count("paladin_slot"))
                ++bad;   // singular
            if (ts.all().count("bard_druid_slots"))
                ++bad;   // cross-family
            if (tg.all().count("traplist")) ++bad;
            if (tg.all().count("appendixa_turn")) ++bad;
            if (tw.all().count("wsg_cyclone")) ++bad;
            if (ts.all().count("")) ++bad;
            if (tg.all().count("")) ++bad;
            if (tw.all().count("")) ++bad;
        }
        printf("R1048 straggler registry load audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 2. counts -------------------------------------
        {
            items::MiscItemRegistry ts;
            ts.loadDirectory("content/tables/class_slots");
            items::MiscItemRegistry tg;
            tg.loadDirectory("content/tables/appendixg");
            items::MiscItemRegistry tw;
            tw.loadDirectory("content/tables/wsg");
            {
            const auto* v = ts.find("paladin_slots");
            if (!v) { ++bad; } else {
                if ((int)v->rows.size() != 0
                    || (int)v->sources.size() != 1
                    || (int)v->pins.size() != 2
                    || v->pins[0].value != 12
                    || v->pins[1].value != 4
                    || (int)v->tables.size() != 1
                    || v->tables[0].name !=
                        std::string("grid")
                    || (int)v->tables[0].values.size()
                       != 48) ++bad;
            }
            }
            {
            const auto* v = ts.find("ranger_slots");
            if (!v) { ++bad; } else {
                if ((int)v->rows.size() != 0
                    || (int)v->sources.size() != 1
                    || (int)v->pins.size() != 2
                    || v->pins[0].value != 10
                    || v->pins[1].value != 5
                    || (int)v->tables.size() != 1
                    || v->tables[0].name !=
                        std::string("grid")
                    || (int)v->tables[0].values.size()
                       != 50) ++bad;
            }
            }
            const auto* vt = tg.find("trap_list");
            if (!vt) { ++bad; } else {
                if ((int)vt->rows.size() != 46
                    || (int)vt->sources.size() != 1
                    || (int)vt->pins.size() != 1
                    || (int)vt->tables.size() != 0
                    || vt->pins[0].name != std::string(
                        "trap_listRowCount")
                    || vt->pins[0].value != 46)
                    ++bad;
            }
            {
            const auto* vw = tw.find("wsg_inedible_bands");
            if (!vw) { ++bad; } else {
                if ((int)vw->rows.size() != 3
                    || (int)vw->sources.size() != 1
                    || (int)vw->pins.size() != 1
                    || (int)vw->tables.size() != 0
                    || vw->pins[0].value != 3)
                    ++bad;
            }
            }
            {
            const auto* vw = tw.find("wsg_cyclone_drift_bands");
            if (!vw) { ++bad; } else {
                if ((int)vw->rows.size() != 3
                    || (int)vw->sources.size() != 1
                    || (int)vw->pins.size() != 1
                    || (int)vw->tables.size() != 0
                    || vw->pins[0].value != 3)
                    ++bad;
            }
            }
        }
        printf("R1048 straggler registry counts audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 3. bands (the roll axes) --------------
        {
            items::MiscItemRegistry tg;
            tg.loadDirectory("content/tables/appendixg");
            items::MiscItemRegistry tw;
            tw.loadDirectory("content/tables/wsg");
            const auto* vt = tg.find("trap_list");
            if (!vt) { ++bad; } else {
                int prevHi = 0;
                for (const auto& r : vt->rows) {
                    if (r.bandLo != prevHi + 1
                        || r.bandHi < r.bandLo
                        || r.bandHi > 100
                        || r.set != vt->key
                        || r.name.empty()
                        || r.gp != 0
                        || r.gpHi != 0
                        || r.xp != 0
                        || r.xpHi != 0
                        || r.qtyLo != 0
                        || r.qtyHi != 0) ++bad;
                    prevHi = r.bandHi;
                }
                if (prevHi != 100) ++bad;
            }
            {
            const auto* vw = tw.find("wsg_inedible_bands");
            if (!vw) { ++bad; } else {
                int prevHi = 0;
                for (int i = 0;
                     i < (int)vw->rows.size(); ++i) {
                    const auto& r = vw->rows[i];
                    if (r.bandLo != prevHi + 1
                        || r.set != vw->key
                        || r.name.empty()
                        || r.gp != i) ++bad;
                    prevHi = r.bandHi;
                }
            }
            }
            {
            const auto* vw = tw.find("wsg_cyclone_drift_bands");
            if (!vw) { ++bad; } else {
                int prevHi = 0;
                for (int i = 0;
                     i < (int)vw->rows.size(); ++i) {
                    const auto& r = vw->rows[i];
                    if (r.bandLo != prevHi + 1
                        || r.set != vw->key
                        || r.name.empty()
                        || r.gp != i) ++bad;
                    prevHi = r.bandHi;
                }
            }
            }
        }
        printf("R1048 straggler registry bands audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 4. data (famous pins, all computed) --
        {
            if (dm::appendixg::trapBandLo(0) != 1
                || dm::appendixg::trapBandHi(0) != 5) ++bad;
            if (dm::appendixg::trapBandLo(28) != 60
                || dm::appendixg::trapBandHi(28) != 63) ++bad;
            if (dm::appendixg::trapBandLo(45) != 95
                || dm::appendixg::trapBandHi(45) != 100) ++bad;
            if (dm::appendixg::trapFor(1) != 0
                || dm::appendixg::trapFor(5) != 0) ++bad;
            if (dm::appendixg::trapFor(100) != 45
                || dm::appendixg::trapFor(95) != 45) ++bad;
            if (rules::paladinSpellSlots(9, 1) != 1)
                ++bad;
            if (rules::paladinSpellSlots(20, 4) != 3)
                ++bad;
            if (rules::paladinSpellSlots(15, 2) != 2)
                ++bad;
            if (rules::rangerSpellSlots(8, 0, 1) != 1)
                ++bad;
            if (rules::rangerSpellSlots(17, 1, 2) != 2)
                ++bad;
            if (rules::rangerSpellSlots(10, 1, 1) != 1)
                ++bad;
            if (rules::wfgInedBandFor(1) != 0) ++bad;
            if (rules::wfgInedBandFor(2) != 1) ++bad;
            if (rules::wfgInedBandFor(4) != 1) ++bad;
            if (rules::wfgInedBandFor(5) != 2) ++bad;
            if (rules::wfgInedBandFor(8) != 2) ++bad;
            if (rules::wwyCycloneDriftFor(2) != 0)
                ++bad;
            if (rules::wwyCycloneDriftFor(6) != 0)
                ++bad;
            if (rules::wwyCycloneDriftFor(7) != 1)
                ++bad;
            if (rules::wwyCycloneDriftFor(8) != 2)
                ++bad;
            if (rules::wwyCycloneDriftFor(12) != 2)
                ++bad;
        }
        printf("R1048 straggler registry data audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 5. rows (the full cross-read) --------
        {
            items::MiscItemRegistry ts;
            ts.loadDirectory("content/tables/class_slots");
            items::MiscItemRegistry tg;
            tg.loadDirectory("content/tables/appendixg");
            items::MiscItemRegistry tw;
            tw.loadDirectory("content/tables/wsg");
            const auto* vp = ts.find("paladin_slots");
            if (!vp) { ++bad; } else {
                const auto& g = vp->tables[0].values;
                for (int lv = 9; lv <= 20; ++lv)
                    for (int sl = 1; sl <= 4; ++sl)
                        if (rules::paladinSpellSlots(lv, sl)
                                != (int)g[(lv - 9) * 4
                                    + (sl - 1)]) ++bad;
            }
            const auto* vr = ts.find("ranger_slots");
            if (!vr) { ++bad; } else {
                const auto& g = vr->tables[0].values;
                for (int lv = 8; lv <= 17; ++lv)
                    for (int col = 1; col <= 5; ++col) {
                        int kind = (col <= 3) ? 0 : 1;
                        int sl = (col <= 3)
                            ? col : col - 3;
                        if (rules::rangerSpellSlots(lv, kind, sl)
                                != (int)g[(lv - 8) * 5
                                    + (col - 1)]) ++bad;
                    }
            }
            const auto* vt = tg.find("trap_list");
            if (!vt) { ++bad; } else {
                for (int r = 1; r <= 100; ++r) {
                    int want = 0;
                    for (int i = 0;
                         i < (int)vt->rows.size(); ++i) {
                        if (r <= vt->rows[i].bandHi) {
                            want = i;
                            break;
                        }
                    }
                    if (dm::appendixg::trapFor(r) != want) ++bad;
                }
            }
            {
            const auto* vw = tw.find("wsg_inedible_bands");
            if (!vw) { ++bad; } else {
                for (int r = 0; r <= 9; ++r) {
                    int want =
                        (int)vw->rows.size() - 1;
                    for (int i = 0;
                         i < (int)vw->rows.size(); ++i) {
                        if (r <= vw->rows[i].bandHi) {
                            want = i;
                            break;
                        }
                    }
                    if (rules::wfgInedBandFor(r) != want) ++bad;
                }
            }
            }
            {
            const auto* vw = tw.find("wsg_cyclone_drift_bands");
            if (!vw) { ++bad; } else {
                for (int r = 0; r <= 13; ++r) {
                    int want =
                        (int)vw->rows.size() - 1;
                    for (int i = 0;
                         i < (int)vw->rows.size(); ++i) {
                        if (r <= vw->rows[i].bandHi) {
                            want = i;
                            break;
                        }
                    }
                    if (rules::wwyCycloneDriftFor(r) != want) ++bad;
                }
            }
            }
        }
        printf("R1048 straggler registry rows audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 6. edges (clamps, negatives) ----------
        {
            if (rules::paladinSpellSlots(8, 1) != 0
                || rules::paladinSpellSlots(1, 1) != 0)
                ++bad;
            if (rules::paladinSpellSlots(21, 1)
                    != rules::paladinSpellSlots(20, 1))
                ++bad;
            if (rules::paladinSpellSlots(9, 0)
                    != rules::paladinSpellSlots(9, 1)
                || rules::paladinSpellSlots(9, 5)
                   != rules::paladinSpellSlots(9, 4))
                ++bad;
            if (rules::rangerSpellSlots(7, 0, 1) != 0)
                ++bad;
            if (rules::rangerSpellSlots(18, 0, 3)
                    != rules::rangerSpellSlots(17, 0, 3))
                ++bad;
            if (rules::rangerSpellSlots(10, 1, 3)
                    != rules::rangerSpellSlots(10, 1, 2))
                ++bad;
            if (dm::appendixg::trapFor(0) != 0
                || dm::appendixg::trapFor(101) != 45
                || dm::appendixg::trapFor(999) != 45)
                ++bad;
            if (dm::appendixg::trapBandLo(-1) != 0
                || dm::appendixg::trapBandLo(99) != 0
                || dm::appendixg::trapBandHi(-1) != 0
                || dm::appendixg::trapBandHi(99) != 0)
                ++bad;
            if (std::string(dm::appendixg::trapName(-1))
                    != std::string("unknown")) ++bad;
            if (rules::wfgInedBandFor(0) != 0
                || rules::wfgInedBandFor(99) != 2) ++bad;
            if (rules::wwyCycloneDriftFor(1) != 0
                || rules::wwyCycloneDriftFor(13) != 2
                || rules::wwyCycloneDriftFor(99) != 2)
                ++bad;
            if (!slotValues("no_such").empty())
                ++bad;
            if (!ghView("no_such").empty())
                ++bad;
            if (!rules::wsgBandRows("no_such").empty())
                ++bad;
            if (slotsReg().find("bard_druid_slots")
                    != nullptr) ++bad;
            if (ghReg().find("traplist")
                    != nullptr) ++bad;
            if (rules::wsgBandReg().find("wsg_cyclone")
                    != nullptr) ++bad;
            if (slotsReg().find("") != nullptr)
                ++bad;
        }
        printf("R1048 straggler registry edges audit: bad %d\n", bad);
    }
