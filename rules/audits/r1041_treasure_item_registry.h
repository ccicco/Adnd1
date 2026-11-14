    // ==== R1041: treasure item registry ======================================
    // The R1041 de-wire: the seven pp.121-125 percentile
    // families ride items::MiscItemRegistry from
    // content/tables/treasure/ (set names = def keys);
    // this audit loads its own registry instance and
    // cross-reads every row through the engine pin
    // surface (magicTablePin), so the r122 structural
    // audit and this registry audit read the same data.
    {
        int bad = 0;
        // -- 1. load --------------------------------------
        items::MiscItemRegistry t;
        if (t.loadDirectory("content/tables/treasure") != 7)
            ++bad;
        if (!t.errors().empty()) ++bad;
        if (t.all().size() != 7) ++bad;
        if (t.all().count("treasure_potions") != 1) ++bad;
        if (t.all().count("treasure_rings") != 1) ++bad;
        if (t.all().count("treasure_rods") != 1) ++bad;
        if (t.all().count("treasure_artifacts") != 1) ++bad;
        if (t.all().count("treasure_armor") != 1) ++bad;
        if (t.all().count("treasure_swords") != 1) ++bad;
        if (t.all().count("treasure_weapons") != 1) ++bad;
        if (t.all().count("treasure_scroll")) ++bad;
        if (t.all().count("treasure_potion")) ++bad;
        if (t.all().count("treasure_scroll_spells")) ++bad;
        if (t.all().count("alchemy_jug")) ++bad;
        if (t.all().count("castle_master")) ++bad;
        if (t.all().count("appendixp_kit")) ++bad;
        if (t.all().count("treasure_potions_rows")) ++bad;
        printf("R1041 treasure item registry load audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 2. counts -------------------------------------
        {
            static const int kRows[13] = { 35, 25, 24, 30, 33,
                30, 33, 36, 35, 26, 26, 36, 29 };
            for (int c = 0; c <= 12; ++c)
                if (dm::treasure::magicTablePinCount(c)
                    != kRows[c]) ++bad;
        }
        if ((int)t.all().at("treasure_potions").rows.size() != 35) ++bad;
        if ((int)t.all().at("treasure_rings").rows.size() != 24) ++bad;
        if ((int)t.all().at("treasure_rods").rows.size() != 30) ++bad;
        if ((int)t.all().at("treasure_artifacts").rows.size() != 29) ++bad;
        if ((int)t.all().at("treasure_armor").rows.size() != 26) ++bad;
        if ((int)t.all().at("treasure_swords").rows.size() != 26) ++bad;
        if ((int)t.all().at("treasure_weapons").rows.size() != 36) ++bad;
        printf("R1041 treasure item registry counts audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 3. bands --------------------------------------
        {
            const auto& rows = t.all().at("treasure_potions").rows;
            int prevHi = 0;
            for (const auto& r : rows) {
                if (r.bandLo != prevHi + 1
                    || r.bandHi < r.bandLo
                    || r.bandHi > 100) { ++bad; break; }
                prevHi = r.bandHi;
            }
            if (prevHi != 100) ++bad;
        }
        {
            const auto& rows = t.all().at("treasure_rings").rows;
            int prevHi = 0;
            for (const auto& r : rows) {
                if (r.bandLo != prevHi + 1
                    || r.bandHi < r.bandLo
                    || r.bandHi > 100) { ++bad; break; }
                prevHi = r.bandHi;
            }
            if (prevHi != 100) ++bad;
        }
        {
            const auto& rows = t.all().at("treasure_rods").rows;
            int prevHi = 0;
            for (const auto& r : rows) {
                if (r.bandLo != prevHi + 1
                    || r.bandHi < r.bandLo
                    || r.bandHi > 100) { ++bad; break; }
                prevHi = r.bandHi;
            }
            if (prevHi != 100) ++bad;
        }
        {
            const auto& rows = t.all().at("treasure_artifacts").rows;
            int prevHi = 0;
            for (const auto& r : rows) {
                if (r.bandLo != prevHi + 1
                    || r.bandHi < r.bandLo
                    || r.bandHi > 100) { ++bad; break; }
                prevHi = r.bandHi;
            }
            if (prevHi != 100) ++bad;
        }
        {
            const auto& rows = t.all().at("treasure_armor").rows;
            int prevHi = 0;
            for (const auto& r : rows) {
                if (r.bandLo != prevHi + 1
                    || r.bandHi < r.bandLo
                    || r.bandHi > 100) { ++bad; break; }
                prevHi = r.bandHi;
            }
            if (prevHi != 100) ++bad;
        }
        {
            const auto& rows = t.all().at("treasure_swords").rows;
            int prevHi = 0;
            for (const auto& r : rows) {
                if (r.bandLo != prevHi + 1
                    || r.bandHi < r.bandLo
                    || r.bandHi > 100) { ++bad; break; }
                prevHi = r.bandHi;
            }
            if (prevHi != 100) ++bad;
        }
        {
            const auto& rows = t.all().at("treasure_weapons").rows;
            int prevHi = 0;
            for (const auto& r : rows) {
                if (r.bandLo != prevHi + 1
                    || r.bandHi < r.bandLo
                    || r.bandHi > 100) { ++bad; break; }
                prevHi = r.bandHi;
            }
            if (prevHi != 100) ++bad;
        }
        printf("R1041 treasure item registry bands audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 4. data (famous rows) -----------------------
        {
            dm::treasure::TablePin p;
            if (!dm::treasure::magicTablePin(0, 0, &p)
                || p.lo != 1 || p.hi != 3
                || p.xp != 250 || p.xpHi != 0
                || p.gp != 400 || p.gpHi != 0
                || p.qtyLo != 0 || p.qtyHi != 0)
                ++bad;
            if (!dm::treasure::magicTablePin(0, 4, &p)
                || p.lo != 13 || p.hi != 15
                || p.xp != 0 || p.xpHi != 0
                || p.gp != 150 || p.gpHi != 0
                || p.qtyLo != 0 || p.qtyHi != 0)
                ++bad;
            if (!dm::treasure::magicTablePin(0, 28, &p)
                || p.lo != 82 || p.hi != 84
                || p.xp != 0 || p.xpHi != 0
                || p.gp != 0 || p.gpHi != 0
                || p.qtyLo != 0 || p.qtyHi != 0)
                ++bad;
            if (!dm::treasure::magicTablePin(0, 34, &p)
                || p.lo != 98 || p.hi != 100
                || p.xp != 400 || p.xpHi != 0
                || p.gp != 900 || p.gpHi != 0
                || p.qtyLo != 0 || p.qtyHi != 0)
                ++bad;
            if (!dm::treasure::magicTablePin(2, 11, &p)
                || p.lo != 45 || p.hi != 60
                || p.xp != 2000 || p.xpHi != 4000
                || p.gp != 10000 || p.gpHi != 20000
                || p.qtyLo != 0 || p.qtyHi != 0)
                ++bad;
            if (!dm::treasure::magicTablePin(9, 25, &p)
                || p.lo != 98 || p.hi != 100
                || p.xp != 0 || p.xpHi != 0
                || p.gp != 750 || p.gpHi != 0
                || p.qtyLo != 0 || p.qtyHi != 0)
                ++bad;
            if (!dm::treasure::magicTablePin(11, 18, &p)
                || p.lo != 57 || p.hi != 60
                || p.xp != 300 || p.xpHi != 0
                || p.gp != 2500 || p.gpHi != 0
                || p.qtyLo != 0 || p.qtyHi != 0)
                ++bad;
            if (!dm::treasure::magicTablePin(11, 19, &p)
                || p.lo != 61 || p.hi != 62
                || p.xp != 650 || p.xpHi != 0
                || p.gp != 6000 || p.gpHi != 0
                || p.qtyLo != 0 || p.qtyHi != 0)
                ++bad;
            if (!dm::treasure::magicTablePin(11, 1, &p)
                || p.lo != 9 || p.hi != 12
                || p.xp != 50 || p.xpHi != 0
                || p.gp != 300 || p.gpHi != 0
                || p.qtyLo != 2 || p.qtyHi != 16)
                ++bad;
            if (!dm::treasure::magicTablePin(12, 27, &p)
                || p.lo != 99 || p.hi != 99
                || p.xp != 0 || p.xpHi != 0
                || p.gp != 0 || p.gpHi != 0
                || p.qtyLo != 0 || p.qtyHi != 0)
                ++bad;
            if (!dm::treasure::magicTablePin(12, 18, &p)
                || p.lo != 41 || p.hi != 47
                || p.xp != 0 || p.xpHi != 0
                || p.gp != 10000 || p.gpHi != 80000
                || p.qtyLo != 0 || p.qtyHi != 0)
                ++bad;
            if (p.name != std::string("Orb of the Dragonkind"))
                ++bad;
        }
        printf("R1041 treasure item registry data audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 5. rows (full cross-read) -------------------
        {
            const auto& rows = t.all().at("treasure_potions").rows;
            dm::treasure::TablePin p;
            for (int i = 0; i < (int)rows.size(); ++i) {
                if (!dm::treasure::magicTablePin(0, i, &p)
                    || p.lo != rows[i].bandLo
                    || p.hi != rows[i].bandHi
                    || p.name != rows[i].name
                    || p.xp != rows[i].xp
                    || p.xpHi != rows[i].xpHi
                    || p.gp != rows[i].gp
                    || p.gpHi != rows[i].gpHi
                    || p.qtyLo != rows[i].qtyLo
                    || p.qtyHi != rows[i].qtyHi) { ++bad; break; }
            }
        }
        {
            const auto& rows = t.all().at("treasure_rings").rows;
            dm::treasure::TablePin p;
            for (int i = 0; i < (int)rows.size(); ++i) {
                if (!dm::treasure::magicTablePin(2, i, &p)
                    || p.lo != rows[i].bandLo
                    || p.hi != rows[i].bandHi
                    || p.name != rows[i].name
                    || p.xp != rows[i].xp
                    || p.xpHi != rows[i].xpHi
                    || p.gp != rows[i].gp
                    || p.gpHi != rows[i].gpHi
                    || p.qtyLo != rows[i].qtyLo
                    || p.qtyHi != rows[i].qtyHi) { ++bad; break; }
            }
        }
        {
            const auto& rows = t.all().at("treasure_rods").rows;
            dm::treasure::TablePin p;
            for (int i = 0; i < (int)rows.size(); ++i) {
                if (!dm::treasure::magicTablePin(3, i, &p)
                    || p.lo != rows[i].bandLo
                    || p.hi != rows[i].bandHi
                    || p.name != rows[i].name
                    || p.xp != rows[i].xp
                    || p.xpHi != rows[i].xpHi
                    || p.gp != rows[i].gp
                    || p.gpHi != rows[i].gpHi
                    || p.qtyLo != rows[i].qtyLo
                    || p.qtyHi != rows[i].qtyHi) { ++bad; break; }
            }
        }
        {
            const auto& rows = t.all().at("treasure_artifacts").rows;
            dm::treasure::TablePin p;
            for (int i = 0; i < (int)rows.size(); ++i) {
                if (!dm::treasure::magicTablePin(12, i, &p)
                    || p.lo != rows[i].bandLo
                    || p.hi != rows[i].bandHi
                    || p.name != rows[i].name
                    || p.xp != rows[i].xp
                    || p.xpHi != rows[i].xpHi
                    || p.gp != rows[i].gp
                    || p.gpHi != rows[i].gpHi
                    || p.qtyLo != rows[i].qtyLo
                    || p.qtyHi != rows[i].qtyHi) { ++bad; break; }
            }
        }
        {
            const auto& rows = t.all().at("treasure_armor").rows;
            dm::treasure::TablePin p;
            for (int i = 0; i < (int)rows.size(); ++i) {
                if (!dm::treasure::magicTablePin(9, i, &p)
                    || p.lo != rows[i].bandLo
                    || p.hi != rows[i].bandHi
                    || p.name != rows[i].name
                    || p.xp != rows[i].xp
                    || p.xpHi != rows[i].xpHi
                    || p.gp != rows[i].gp
                    || p.gpHi != rows[i].gpHi
                    || p.qtyLo != rows[i].qtyLo
                    || p.qtyHi != rows[i].qtyHi) { ++bad; break; }
            }
        }
        {
            const auto& rows = t.all().at("treasure_swords").rows;
            dm::treasure::TablePin p;
            for (int i = 0; i < (int)rows.size(); ++i) {
                if (!dm::treasure::magicTablePin(10, i, &p)
                    || p.lo != rows[i].bandLo
                    || p.hi != rows[i].bandHi
                    || p.name != rows[i].name
                    || p.xp != rows[i].xp
                    || p.xpHi != rows[i].xpHi
                    || p.gp != rows[i].gp
                    || p.gpHi != rows[i].gpHi
                    || p.qtyLo != rows[i].qtyLo
                    || p.qtyHi != rows[i].qtyHi) { ++bad; break; }
            }
        }
        {
            const auto& rows = t.all().at("treasure_weapons").rows;
            dm::treasure::TablePin p;
            for (int i = 0; i < (int)rows.size(); ++i) {
                if (!dm::treasure::magicTablePin(11, i, &p)
                    || p.lo != rows[i].bandLo
                    || p.hi != rows[i].bandHi
                    || p.name != rows[i].name
                    || p.xp != rows[i].xp
                    || p.xpHi != rows[i].xpHi
                    || p.gp != rows[i].gp
                    || p.gpHi != rows[i].gpHi
                    || p.qtyLo != rows[i].qtyLo
                    || p.qtyHi != rows[i].qtyHi) { ++bad; break; }
            }
        }
        printf("R1041 treasure item registry rows audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 6. edges (refusals + scrolls) ---------------
        {
            dm::treasure::TablePin p;
            if (dm::treasure::magicTablePinCount(1) != 25) ++bad;
            if (dm::treasure::magicTablePin(1, 0, &p)) ++bad;
            if (dm::treasure::magicTablePin(0, 35, &p)) ++bad;
            if (dm::treasure::magicTablePin(0, -1, &p)) ++bad;
            if (dm::treasure::magicTablePin(13, 0, &p)) ++bad;
            if (dm::treasure::magicTablePin(-1, 0, &p)) ++bad;
            if (dm::treasure::magicTablePin(12, 29, &p)) ++bad;
            if (!dm::treasure::magicTablePin(12, 28, &p)) ++bad;
            if (dm::treasure::magicTablePinCount(13) != 0) ++bad;
            if (dm::treasure::magicTablePinCount(-1) != 0) ++bad;
            if (dm::treasure::magicTablePin(0, 0, nullptr)) ++bad;
        }
        printf("R1041 treasure item registry edges audit: bad %d\n", bad);
        if (bad) return 1;
    }
