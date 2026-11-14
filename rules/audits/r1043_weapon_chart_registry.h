    // ==== R1043: weapon chart registry ======================================
    // The R1043 de-wire: the PHB weapon weight/damage
    // chart (50 rows), the speed verify list (18) and
    // the five class allowlists ride
    // items::MiscItemRegistry from content/tables/
    // weapons/ (set names = def keys); this audit
    // loads its own registry instance and cross-reads
    // every row through the inline accessor surface
    // (weaponChart*/weaponSpeedVerified*/classAllowed*
    // in rules/phb/weapontables.h), so the r158/r189/
    // r198/r337 audits and this registry audit read
    // the same data.
    {
        int bad = 0;
        // -- 1. load --------------------------------------
        {
            items::MiscItemRegistry t;
            if (t.loadDirectory("content/tables/weapons") != 7)
                ++bad;
            if (!t.errors().empty()) ++bad;
            if (t.all().size() != 7) ++bad;
            if (t.all().count("weapon_chart") != 1) ++bad;
            if (t.all().count("weapon_speed") != 1) ++bad;
            if (t.all().count("weapon_cleric") != 1) ++bad;
            if (t.all().count("weapon_druid") != 1) ++bad;
            if (t.all().count("weapon_mu_illusionist") != 1) ++bad;
            if (t.all().count("weapon_thief") != 1) ++bad;
            if (t.all().count("weapon_monk") != 1) ++bad;
            if (t.all().count("weapon_chart_rows")) ++bad;
            if (t.all().count("treasure_potions")) ++bad;
            if (t.all().count("equipment_arms")) ++bad;
            if (t.all().count("weapon_fighter")) ++bad;
        }
        printf("R1043 weapon chart registry load audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 2. counts -------------------------------------
        {
            if (rules::weaponChartRowCount() != 50) ++bad;
            if (rules::weaponSpeedVerifiedCount() != 18) ++bad;
            if (rules::classAllowedWeaponCount(0) != 7) ++bad;
            if (rules::classAllowedWeaponCount(1) != 9) ++bad;
            if (rules::classAllowedWeaponCount(5) != 3) ++bad;
            if (rules::classAllowedWeaponCount(6) != 3) ++bad;
            if (rules::classAllowedWeaponCount(7) != 8) ++bad;
            if (rules::classAllowedWeaponCount(9) != 24) ++bad;
            if (rules::classAllowedWeaponCount(2) != -1) ++bad;
            if (rules::classAllowedWeaponCount(8) != -1) ++bad;
            if (rules::classAllowedWeaponCount(10) != 0) ++bad;
            items::MiscItemRegistry t;
            t.loadDirectory("content/tables/weapons");
            const auto* d_chart = t.find("weapon_chart");
            if (!d_chart || (int)d_chart->rows.size() != 50) ++bad;
            if (d_chart && ((int)d_chart->pins.size() != 1
                       || d_chart->pins[0].name
                              != std::string("weapon_chartRowCount")
                       || d_chart->pins[0].value != 50)) ++bad;
            const auto* d_speed = t.find("weapon_speed");
            if (!d_speed || (int)d_speed->rows.size() != 18) ++bad;
            if (d_speed && ((int)d_speed->pins.size() != 1
                       || d_speed->pins[0].name
                              != std::string("weapon_speedRowCount")
                       || d_speed->pins[0].value != 18)) ++bad;
            const auto* d_cleric = t.find("weapon_cleric");
            if (!d_cleric || (int)d_cleric->rows.size() != 7) ++bad;
            if (d_cleric && ((int)d_cleric->pins.size() != 1
                       || d_cleric->pins[0].name
                              != std::string("weapon_clericRowCount")
                       || d_cleric->pins[0].value != 7)) ++bad;
            const auto* d_druid = t.find("weapon_druid");
            if (!d_druid || (int)d_druid->rows.size() != 9) ++bad;
            if (d_druid && ((int)d_druid->pins.size() != 1
                       || d_druid->pins[0].name
                              != std::string("weapon_druidRowCount")
                       || d_druid->pins[0].value != 9)) ++bad;
            const auto* d_mu = t.find("weapon_mu_illusionist");
            if (!d_mu || (int)d_mu->rows.size() != 3) ++bad;
            if (d_mu && ((int)d_mu->pins.size() != 1
                       || d_mu->pins[0].name
                              != std::string("weapon_mu_illusionistRowCount")
                       || d_mu->pins[0].value != 3)) ++bad;
            const auto* d_thief = t.find("weapon_thief");
            if (!d_thief || (int)d_thief->rows.size() != 8) ++bad;
            if (d_thief && ((int)d_thief->pins.size() != 1
                       || d_thief->pins[0].name
                              != std::string("weapon_thiefRowCount")
                       || d_thief->pins[0].value != 8)) ++bad;
            const auto* d_monk = t.find("weapon_monk");
            if (!d_monk || (int)d_monk->rows.size() != 24) ++bad;
            if (d_monk && ((int)d_monk->pins.size() != 1
                       || d_monk->pins[0].name
                              != std::string("weapon_monkRowCount")
                       || d_monk->pins[0].value != 24)) ++bad;
        }
        printf("R1043 weapon chart registry counts audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 3. bands (the row-index axis) ----------------
        {
            items::MiscItemRegistry t;
            t.loadDirectory("content/tables/weapons");
            for (const auto& kv : t.all()) {
                const auto& d = kv.second;
                const int n = (int)d.rows.size();
                for (int i = 0; i < n; ++i)
                    if (d.rows[i].bandLo != i
                        || d.rows[i].bandHi != i
                        || d.rows[i].set != d.key
                        || d.rows[i].gpHi != 0) ++bad;
            }
            const auto* dc = t.find("weapon_chart");
            if (dc) {
                for (const auto& r : dc->rows) {
                    if (r.gp <= 0) ++bad;   // weight in gp
                    if (r.qtyLo > r.qtyHi) ++bad;   // S-M pair
                    if (r.xp > r.xpHi) ++bad;   // L pair
                }
            } else ++bad;
            const auto* ds = t.find("weapon_speed");
            if (ds) {
                for (const auto& r : ds->rows) {
                    if (r.gp < 1) ++bad;   // speed factor
                    if (r.xp != 0 || r.xpHi != 0
                        || r.qtyLo != 0 || r.qtyHi != 0) ++bad;
                }
            } else ++bad;
            for (const char* lk : {"weapon_cleric", "weapon_druid", "weapon_mu_illusionist", "weapon_thief", "weapon_monk"}) {
                const auto* dl = t.find(lk);
                if (!dl) { ++bad; continue; }
                for (const auto& r : dl->rows)
                    if (r.xp != 0 || r.xpHi != 0 || r.gp != 0
                        || r.qtyLo != 0 || r.qtyHi != 0) ++bad;
            }
        }
        printf("R1043 weapon chart registry bands audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 4. data (famous rows via the accessors) ------
        {
            if (rules::weaponChartName(0) != std::string("arrow")) ++bad;
            if (rules::weaponChartWeight(0) != 2) ++bad;
            if (rules::weaponChartDamageSMMin(0) != 1
                || rules::weaponChartDamageSMMax(0) != 6) ++bad;
            if (rules::weaponChartDamageLMin(0) != 1
                || rules::weaponChartDamageLMax(0) != 6) ++bad;
            if (rules::weaponChartName(47) != std::string("two-handed sword")) ++bad;
            if (rules::weaponChartWeight(47) != 250) ++bad;
            if (rules::weaponChartDamageSMMin(47) != 1
                || rules::weaponChartDamageSMMax(47) != 10) ++bad;
            if (rules::weaponChartDamageLMin(47) != 3
                || rules::weaponChartDamageLMax(47) != 18) ++bad;
            if (rules::weaponChartName(40) != std::string("spear")) ++bad;
            if (rules::weaponChartWeight(40) != 40) ++bad;
            if (rules::weaponChartDamageSMMin(40) != 1
                || rules::weaponChartDamageSMMax(40) != 6) ++bad;
            if (rules::weaponChartDamageLMin(40) != 1
                || rules::weaponChartDamageLMax(40) != 8) ++bad;
            if (rules::weaponChartName(45) != std::string("long sword")) ++bad;
            if (rules::weaponChartWeight(45) != 60) ++bad;
            if (rules::weaponChartDamageSMMin(45) != 1
                || rules::weaponChartDamageSMMax(45) != 8) ++bad;
            if (rules::weaponChartDamageLMin(45) != 1
                || rules::weaponChartDamageLMax(45) != 12) ++bad;
            if (rules::weaponChartName(8) != std::string("dagger")) ++bad;
            if (rules::weaponChartWeight(8) != 10) ++bad;
            if (rules::weaponChartDamageSMMin(8) != 1
                || rules::weaponChartDamageSMMax(8) != 4) ++bad;
            if (rules::weaponChartDamageLMin(8) != 1
                || rules::weaponChartDamageLMax(8) != 3) ++bad;
            if (rules::weaponChartName(42) != std::string("quarterstaff")) ++bad;
            if (rules::weaponChartWeight(42) != 50) ++bad;
            if (rules::weaponChartDamageSMMin(42) != 1
                || rules::weaponChartDamageSMMax(42) != 6) ++bad;
            if (rules::weaponChartDamageLMin(42) != 1
                || rules::weaponChartDamageLMax(42) != 6) ++bad;
            if (rules::weaponSpeedVerifiedName(0) != std::string("fist")) ++bad;
            if (rules::weaponSpeedVerifiedFactor(0) != 1) ++bad;
            if (rules::weaponSpeedVerifiedName(1) != std::string("dagger")) ++bad;
            if (rules::weaponSpeedVerifiedFactor(1) != 2) ++bad;
            if (rules::weaponSpeedVerifiedName(11) != std::string("spear")) ++bad;
            if (rules::weaponSpeedVerifiedFactor(11) != 7) ++bad;
            if (rules::weaponSpeedVerifiedName(16) != std::string("two-handed sword")) ++bad;
            if (rules::weaponSpeedVerifiedFactor(16) != 10) ++bad;
            if (rules::weaponSpeedVerifiedName(17) != std::string("pike")) ++bad;
            if (rules::weaponSpeedVerifiedFactor(17) != 13) ++bad;
            if (rules::classAllowedWeaponName(0, 0) != std::string("club"))
                ++bad;
            if (rules::classAllowedWeaponName(0, 6) != std::string("quarterstaff"))
                ++bad;
            if (rules::classAllowedWeaponName(1, 0) != std::string("club"))
                ++bad;
            if (rules::classAllowedWeaponName(7, 7) != std::string("long sword"))
                ++bad;
            if (rules::classAllowedWeaponName(9, 0) != std::string("bo stick"))
                ++bad;
            if (rules::classAllowedWeaponName(9, 23) != std::string("voulge"))
                ++bad;
            {
                int lo = 0, hi = 0;
                rules::spearWeightRange(lo, hi);
                if (lo != 40 || hi != 60) ++bad;
                if (!rules::lanceChargingDouble(24)
                    || !rules::lanceChargingDouble(26)
                    || rules::lanceChargingDouble(23)
                    || rules::lanceChargingDouble(27)) ++bad;
                if (!rules::spearSetChargingDouble()) ++bad;
                if (rules::weaponBackOrUnseenBonus() != 2) ++bad;
                if (rules::weaponStunnedProneMotionlessBonus()
                        != 4) ++bad;
            }
        }
        printf("R1043 weapon chart registry data audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 5. rows (full cross-read) --------------------
        {
            items::MiscItemRegistry t;
            t.loadDirectory("content/tables/weapons");
            const auto* dc = t.find("weapon_chart");
            if (dc) {
                for (int i = 0; i < 50; ++i) {
                    const auto& r = dc->rows[i];
                    if (rules::weaponChartName(i) != r.name
                        || rules::weaponChartWeight(i) != r.gp
                        || rules::weaponChartDamageSMMin(i)
                               != r.qtyLo
                        || rules::weaponChartDamageSMMax(i)
                               != r.qtyHi
                        || rules::weaponChartDamageLMin(i)
                               != r.xp
                        || rules::weaponChartDamageLMax(i)
                               != r.xpHi) ++bad;
                }
            } else ++bad;
            const auto* ds = t.find("weapon_speed");
            if (ds) {
                for (int i = 0; i < 18; ++i) {
                    const auto& r = ds->rows[i];
                    if (rules::weaponSpeedVerifiedName(i) != r.name
                        || rules::weaponSpeedVerifiedFactor(i)
                               != r.gp) ++bad;
                }
            } else ++bad;
            for (int cls = 0; cls < 10; ++cls) {
                const char* key = 0;
                if (cls == 0) key = "weapon_cleric";
                else if (cls == 1) key = "weapon_druid";
                else if (cls == 5 || cls == 6) key = "weapon_mu_illusionist";
                else if (cls == 7) key = "weapon_thief";
                else if (cls == 9) key = "weapon_monk";
                if (!key) continue;
                const auto* dl = t.find(key);
                if (!dl) { ++bad; continue; }
                const int n = (int)dl->rows.size();
                for (int i = 0; i < n; ++i)
                    if (rules::classAllowedWeaponName(cls, i)
                            != dl->rows[i].name) ++bad;
            }
        }
        printf("R1043 weapon chart registry rows audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 6. edges (clamps + dispatch) -----------------
        {
            if (rules::weaponChartName(-1)
                    != rules::weaponChartName(0)) ++bad;
            if (rules::weaponChartName(999)
                    != rules::weaponChartName(49)) ++bad;
            if (rules::weaponChartWeight(-5)
                    != rules::weaponChartWeight(0)) ++bad;
            if (rules::weaponChartDamageLMax(999)
                    != rules::weaponChartDamageLMax(49)) ++bad;
            if (rules::weaponSpeedVerifiedName(-1)
                    != rules::weaponSpeedVerifiedName(0)) ++bad;
            if (rules::weaponSpeedVerifiedFactor(99)
                    != rules::weaponSpeedVerifiedFactor(17)) ++bad;
            if (rules::classAllowedWeaponName(0, 99)
                    != rules::classAllowedWeaponName(0, 6)) ++bad;
            if (rules::classAllowedWeaponName(9, -1)
                    != rules::classAllowedWeaponName(9, 0)) ++bad;
            if (rules::classAllowedWeaponName(10, 0)
                != std::string("club")) ++bad;
            if (!rules::classUsesAnyWeapon(2)
                || !rules::classUsesAnyWeapon(3)
                || !rules::classUsesAnyWeapon(4)
                || !rules::classUsesAnyWeapon(8)) ++bad;
            if (rules::classUsesAnyWeapon(0)
                || rules::classUsesAnyWeapon(9)) ++bad;
            if (rules::weaponAllowedForClass(0, "quarterstaff")
                != true) ++bad;
            if (rules::weaponAllowedForClass(0, "two-handed sword")
                != false) ++bad;
            if (rules::weaponAllowedForClass(2, "two-handed sword")
                != true) ++bad;
            if (rules::weaponAllowedForClass(0, 0) != false) ++bad;
            if (rules::classOilUse(9) != 0) ++bad;
            if (rules::classOilUse(0) != 1) ++bad;
            if (rules::classPoisonUse(0) != 0) ++bad;
            if (rules::classPoisonUse(8) != 1) ++bad;
            if (rules::classPoisonUseForAlignment(0, true) != -1)
                ++bad;
            if (rules::classPoisonUseForAlignment(0, false) != 0)
                ++bad;
        }
        printf("R1043 weapon chart registry edges audit: bad %d\n", bad);
        if (bad) return 1;
    }
