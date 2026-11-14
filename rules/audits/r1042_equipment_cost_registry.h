    // ==== R1042: equipment cost registry =====================================
    // The R1042 de-wire: the PHB equipment price tables
    // (52 arms, 14 armor, 99 general rows) ride
    // items::MiscItemRegistry from content/tables/
    // equipment/ (set names = def keys); this audit
    // loads its own registry instance and cross-reads
    // every row through the inline accessor surface
    // (eqc* in rules/phb/equipcosts.h), so the
    // R300/R300a/R308 audits and this registry audit
    // read the same data.
    {
        int bad = 0;
        // -- 1. load --------------------------------------
        {
            items::MiscItemRegistry t;
            if (t.loadDirectory("content/tables/equipment") != 3)
                ++bad;
            if (!t.errors().empty()) ++bad;
            if (t.all().size() != 3) ++bad;
            if (t.all().count("equipment_arms") != 1) ++bad;
            if (t.all().count("equipment_armor") != 1) ++bad;
            if (t.all().count("equipment_general") != 1) ++bad;
            if (t.all().count("equipment_clothing")) ++bad;
            if (t.all().count("treasure_potions")) ++bad;
            if (t.all().count("appendixp_kit")) ++bad;
            if (t.all().count("equipment_arms_rows")) ++bad;
        }
        printf("R1042 equipment cost registry load audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 2. counts -------------------------------------
        {
            if (rules::eqcArmsCount() != 52) ++bad;
            if (rules::eqcArmorCount() != 14) ++bad;
            if (rules::eqcGeneralCount() != 99) ++bad;
            items::MiscItemRegistry t;
            t.loadDirectory("content/tables/equipment");
            const auto* d = t.find("equipment_general");
            if (!d) ++bad;
            else {
                int cg = 0, cs = 0, cc = 0;
                for (const auto& r : d->rows) {
                    if (r.qtyLo == 3) ++cg;
                    if (r.qtyLo == 2) ++cs;
                    if (r.qtyLo == 1) ++cc;
                }
                if (cg != 59 || cs != 29 || cc != 11) ++bad;
                const items::MiscItemTable* tc = nullptr;
                const items::MiscItemTable* tf = nullptr;
                for (const auto& tb : d->tables) {
                    if (tb.name == "list_counts") tc = &tb;
                    if (tb.name == "list_first") tf = &tb;
                }
                if (!tc || (int)tc->values.size() != 8) ++bad;
                if (!tf || (int)tf->values.size() != 8) ++bad;
                if ((int)d->pins.size() != 2) ++bad;
                else {
                    if (d->pins[0].name
                            != std::string("equipment_generalRowCount")
                        || d->pins[0].value != 99) ++bad;
                    if (d->pins[1].name
                            != std::string("equipment_generalCoinSplit")
                        || d->pins[1].value != 11029059LL) ++bad;
                }
                if (tc && tf) {
                    for (int l = 0; l < 8; ++l) {
                        if (rules::eqcGeneralListCount(l)
                                != (int)tc->values[l]) ++bad;
                        if (rules::eqcGeneralFirst(l)
                                != (int)tf->values[l]) ++bad;
                    }
                }
            }
            const auto* da = t.find("equipment_arms");
            if (!da || (int)da->rows.size() != 52) ++bad;
            if (da && ((int)da->pins.size() != 1
                       || da->pins[0].name
                              != std::string("equipment_armsRowCount")
                       || da->pins[0].value != 52)) ++bad;
            const auto* dr = t.find("equipment_armor");
            if (!dr || (int)dr->rows.size() != 14) ++bad;
            if (dr && ((int)dr->pins.size() != 1
                       || dr->pins[0].name
                              != std::string("equipment_armorRowCount")
                       || dr->pins[0].value != 14)) ++bad;
        }
        printf("R1042 equipment cost registry counts audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 3. bands (the row-index axis) ----------------
        {
            items::MiscItemRegistry t;
            t.loadDirectory("content/tables/equipment");
            for (const char* key : {"equipment_arms",
                                   "equipment_armor",
                                   "equipment_general"}) {
                const auto* d = t.find(key);
                if (!d) { ++bad; continue; }
                const int n = (int)d->rows.size();
                for (int i = 0; i < n; ++i)
                    if (d->rows[i].bandLo != i
                        || d->rows[i].bandHi != i
                        || d->rows[i].set != std::string(key)
                        || d->rows[i].qtyLo < 1
                        || d->rows[i].qtyLo > 3
                        || d->rows[i].qtyHi != 0
                        || d->rows[i].xp != 0
                        || d->rows[i].xpHi != 0
                        || d->rows[i].gpHi != 0
                        || d->rows[i].gp <= 0) ++bad;
            }
        }
        printf("R1042 equipment cost registry bands audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 4. data (famous rows via the accessors) ------
        {
            if (rules::eqcArmsName(0) != std::string("arrow, normal, single")) ++bad;
            if (rules::eqcArmsSilver(0) != 2) ++bad;
            if (rules::eqcArmsGold(0) != 0) ++bad;
            if (rules::eqcArmsName(1) != std::string("arrow, normal, dozen")) ++bad;
            if (rules::eqcArmsGold(1) != 1) ++bad;
            if (rules::eqcArmsSilver(1) != 0) ++bad;
            if (rules::eqcArmsName(9) != std::string("bow, composite, long")) ++bad;
            if (rules::eqcArmsGold(9) != 100) ++bad;
            if (rules::eqcArmsSilver(9) != 0) ++bad;
            if (rules::eqcArmsName(14) != std::string("dagger and scabbard")) ++bad;
            if (rules::eqcArmsGold(14) != 2) ++bad;
            if (rules::eqcArmsSilver(14) != 0) ++bad;
            if (rules::eqcArmsName(28) != std::string("javelin")) ++bad;
            if (rules::eqcArmsSilver(28) != 10) ++bad;
            if (rules::eqcArmsGold(28) != 0) ++bad;
            if (rules::eqcArmsName(45) != std::string("bastard sword and scabbard")) ++bad;
            if (rules::eqcArmsGold(45) != 25) ++bad;
            if (rules::eqcArmsSilver(45) != 0) ++bad;
            if (rules::eqcArmsName(47) != std::string("long sword and scabbard")) ++bad;
            if (rules::eqcArmsGold(47) != 15) ++bad;
            if (rules::eqcArmsSilver(47) != 0) ++bad;
            if (rules::eqcArmsName(49) != std::string("two-handed sword")) ++bad;
            if (rules::eqcArmsGold(49) != 30) ++bad;
            if (rules::eqcArmsSilver(49) != 0) ++bad;
            if (rules::eqcArmorName(0) != std::string("banded"))
                ++bad;
            if (rules::eqcArmorGold(0) != 90) ++bad;
            if (rules::eqcArmorGold(6) != 400) ++bad;
            if (rules::eqcArmorName(6) != std::string("plate"))
                ++bad;
            if (rules::eqcGeneralName(0) != std::string("belt")) ++bad;
            if (rules::eqcGeneralSilver(0) != 3) ++bad;
            if (rules::eqcGeneralName(64) != std::string("ale, pint")) ++bad;
            if (rules::eqcGeneralSilver(64) != 1) ++bad;
            if (rules::eqcGeneralName(12) != std::string("garlic, bud")) ++bad;
            if (rules::eqcGeneralCopper(12) != 5) ++bad;
            if (rules::eqcGeneralName(13) != std::string("wolvesbane, sprig")) ++bad;
            if (rules::eqcGeneralSilver(13) != 10) ++bad;
            if (rules::eqcGeneralName(23) != std::string("horse, heavy war")) ++bad;
            if (rules::eqcGeneralGold(23) != 300) ++bad;
            if (rules::eqcGeneralName(77) != std::string("symbol, holy, silver")) ++bad;
            if (rules::eqcGeneralGold(77) != 50) ++bad;
            if (rules::eqcGeneralName(97) != std::string("ship, war")) ++bad;
            if (rules::eqcGeneralGold(97) != 20000) ++bad;
            if (rules::eqcGeneralName(98) != std::string("wagon")) ++bad;
            if (rules::eqcGeneralGold(98) != 150) ++bad;
        }
        printf("R1042 equipment cost registry data audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 5. rows (full cross-read) --------------------
        {
            items::MiscItemRegistry t;
            t.loadDirectory("content/tables/equipment");
            const auto* da = t.find("equipment_arms");
            if (da) {
                for (int i = 0; i < 52; ++i) {
                    if (rules::eqcArmsName(i) != da->rows[i].name)
                        ++bad;
                    const int g = rules::eqcArmsGold(i);
                    const int s = rules::eqcArmsSilver(i);
                    if (da->rows[i].qtyLo == 3
                        ? (g != da->rows[i].gp || s != 0)
                        : (g != 0 || s != da->rows[i].gp))
                        ++bad;
                }
            } else ++bad;
            const auto* dr = t.find("equipment_armor");
            if (dr) {
                for (int i = 0; i < 14; ++i) {
                    if (rules::eqcArmorName(i) != dr->rows[i].name)
                        ++bad;
                    if (rules::eqcArmorGold(i)
                            != (dr->rows[i].qtyLo == 3
                                ? dr->rows[i].gp : 0))
                        ++bad;
                }
            } else ++bad;
            const auto* dg = t.find("equipment_general");
            if (dg) {
                for (int i = 0; i < 99; ++i) {
                    if (rules::eqcGeneralName(i) != dg->rows[i].name)
                        ++bad;
                    const int q = dg->rows[i].qtyLo;
                    const int v = dg->rows[i].gp;
                    if (rules::eqcGeneralGold(i)   != (q == 3 ? v : 0)
                        || rules::eqcGeneralSilver(i)
                               != (q == 2 ? v : 0)
                        || rules::eqcGeneralCopper(i)
                               != (q == 1 ? v : 0))
                        ++bad;
                }
            } else ++bad;
        }
        printf("R1042 equipment cost registry rows audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 6. edges (clamps) ----------------------------
        {
            if (rules::eqcArmsName(-1) != rules::eqcArmsName(0))
                ++bad;
            if (rules::eqcArmsName(999) != rules::eqcArmsName(51))
                ++bad;
            if (rules::eqcArmsGold(999) != rules::eqcArmsGold(51))
                ++bad;
            if (rules::eqcArmorGold(-3) != rules::eqcArmorGold(0))
                ++bad;
            if (rules::eqcGeneralName(-1)
                    != rules::eqcGeneralName(0))
                ++bad;
            if (rules::eqcGeneralCopper(9999)
                    != rules::eqcGeneralCopper(98))
                ++bad;
            if (rules::eqcGeneralListCount(-1) != 11) ++bad;
            if (rules::eqcGeneralListCount(8) != 10) ++bad;
            if (rules::eqcGeneralFirst(-1) != 0) ++bad;
            if (rules::eqcGeneralFirst(99) != 89) ++bad;
            if (rules::eqcSilverPerGold() != 20) ++bad;
            if (rules::eqcCopperPerSilver() != 10) ++bad;
            if (rules::eqcCopperPerGold() != 200) ++bad;
        }
        printf("R1042 equipment cost registry edges audit: bad %d\n", bad);
        if (bad) return 1;
    }
