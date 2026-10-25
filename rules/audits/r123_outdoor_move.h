    // ---- R123: outdoor movement audit ---------------------------------
    // The DMG pp.58-59 daily rates, pinned: the afoot table
    // (burden x terrain class, all nine cells), the burden
    // thresholds, the route-terrain mapping, the mounted and
    // afloat tables, and the company pace (the slowest
    // walker's rate from the true loads, the hire at his
    // kit, the fallen skipped).
    {
        int bad = 0;
        // the afoot table, all nine cells
        static const int kFoot[3][3] = {
            { 30, 20, 10 }, { 20, 10, 5 }, { 10, 5, 2 } };
        for (int b = 0; b < 3; ++b)
            for (int t = 0; t < 3; ++t)
                if (dm::footMilesPerDay(
                        (dm::FootBurden)b, (dm::TerrainClass)t)
                    != kFoot[b][t]) ++bad;
        // the burden thresholds (p.58-59)
        if (dm::footBurdenFor(0)  != dm::FB_LIGHT)   ++bad;
        if (dm::footBurdenFor(25) != dm::FB_LIGHT)   ++bad;
        if (dm::footBurdenFor(26) != dm::FB_AVERAGE) ++bad;
        if (dm::footBurdenFor(60) != dm::FB_AVERAGE) ++bad;
        if (dm::footBurdenFor(61) != dm::FB_HEAVY)   ++bad;
        if (dm::footBurdenFor(90) != dm::FB_HEAVY)   ++bad;
        if (dm::footBurdenFor(91) != dm::FB_HEAVY)   ++bad;
        // the route-terrain mapping (the 8 routes)
        if (dm::terrainClass(dm::T_PLAIN) != dm::TC_NORMAL) ++bad;
        if (dm::terrainClass(dm::T_SCRUB) != dm::TC_NORMAL) ++bad;
        if (dm::terrainClass(dm::T_DESERT) != dm::TC_NORMAL) ++bad;
        if (dm::terrainClass(dm::T_FOREST) != dm::TC_RUGGED) ++bad;
        if (dm::terrainClass(dm::T_ROUGH) != dm::TC_RUGGED) ++bad;
        if (dm::terrainClass(dm::T_HILLS) != dm::TC_RUGGED) ++bad;
        if (dm::terrainClass(dm::T_MOUNTAINS)
            != dm::TC_VERY_RUGGED) ++bad;
        if (dm::terrainClass(dm::T_MARSH)
            != dm::TC_VERY_RUGGED) ++bad;
        // mounted (p.58-59): the four mounts and the
        // road-only carts (the book's dash is 0)
        if (dm::mountedMilesPerDay(
                dm::MOUNT_LIGHT, dm::TC_NORMAL) != 60) ++bad;
        if (dm::mountedMilesPerDay(
                dm::MOUNT_LIGHT, dm::TC_RUGGED) != 25) ++bad;
        if (dm::mountedMilesPerDay(
                dm::MOUNT_LIGHT, dm::TC_VERY_RUGGED) != 5) ++bad;
        if (dm::mountedMilesPerDay(
                dm::MOUNT_MEDIUM, dm::TC_NORMAL) != 40) ++bad;
        if (dm::mountedMilesPerDay(
                dm::MOUNT_HEAVY, dm::TC_NORMAL) != 30) ++bad;
        if (dm::mountedMilesPerDay(
                dm::MOUNT_DRAFT, dm::TC_RUGGED) != 15) ++bad;
        if (dm::mountedMilesPerDay(
                dm::MOUNT_CART, dm::TC_NORMAL) != 25) ++bad;
        if (dm::mountedMilesPerDay(
                dm::MOUNT_CART, dm::TC_VERY_RUGGED) != 0) ++bad;
        if (dm::mountedMilesPerDay(
                dm::MOUNT_WAGON, dm::TC_RUGGED) != 10) ++bad;
        if (dm::mountedMilesPerDay(
                dm::MOUNT_WAGON, dm::TC_VERY_RUGGED) != 0) ++bad;
        // afloat, oared: raft, boat, galley, merchant, warship
        if (dm::oaredMilesPerDay(
                dm::VESSEL_RAFT, dm::WATER_LAKE) != 15) ++bad;
        if (dm::oaredMilesPerDay(
                dm::VESSEL_RAFT, dm::WATER_SEA) != 0) ++bad;
        if (dm::oaredMilesPerDay(
                dm::VESSEL_BOAT_SMALL, dm::WATER_RIVER) != 35)
            ++bad;
        if (dm::oaredMilesPerDay(
                dm::VESSEL_GALLEY_SMALL, dm::WATER_SEA) != 30)
            ++bad;
        if (dm::oaredMilesPerDay(
                dm::VESSEL_MERCHANT_SMALL, dm::WATER_SEA) != 20)
            ++bad;
        if (dm::oaredMilesPerDay(
                dm::VESSEL_WARSHIP, dm::WATER_SEA) != 20) ++bad;
        // afloat, sailed: the coaster's sea rate, the lake
        // bands, and the printed ranges (equal lo/hi where
        // the book prints one number)
        if (dm::sailedMilesLo(
                dm::VESSEL_MERCHANT_SMALL, dm::WATER_SEA) != 50 ||
            dm::sailedMilesHi(
                dm::VESSEL_MERCHANT_SMALL, dm::WATER_SEA) != 50)
            ++bad;
        if (dm::sailedMilesLo(
                dm::VESSEL_MERCHANT_SMALL, dm::WATER_LAKE) != 50 ||
            dm::sailedMilesHi(
                dm::VESSEL_MERCHANT_SMALL, dm::WATER_LAKE) != 60)
            ++bad;
        if (dm::sailedMilesLo(
                dm::VESSEL_BOAT_SMALL, dm::WATER_LAKE) != 80 ||
            dm::sailedMilesHi(
                dm::VESSEL_BOAT_SMALL, dm::WATER_LAKE) != 80)
            ++bad;
        if (dm::sailedMilesLo(
                dm::VESSEL_GALLEY_SMALL, dm::WATER_LAKE) != 70 ||
            dm::sailedMilesHi(
                dm::VESSEL_GALLEY_SMALL, dm::WATER_LAKE) != 80)
            ++bad;
        if (dm::sailedMilesLo(
                dm::VESSEL_GALLEY_LARGE, dm::WATER_LAKE) != 50 ||
            dm::sailedMilesHi(
                dm::VESSEL_GALLEY_LARGE, dm::WATER_LAKE) != 60)
            ++bad;
        if (dm::sailedMilesLo(
                dm::VESSEL_MERCHANT_LARGE,
                dm::WATER_LAKE) != 25 ||
            dm::sailedMilesHi(
                dm::VESSEL_MERCHANT_LARGE,
                dm::WATER_LAKE) != 35) ++bad;
        if (dm::sailedMilesLo(
                dm::VESSEL_WARSHIP, dm::WATER_SEA) != 50 ||
            dm::sailedMilesHi(
                dm::VESSEL_WARSHIP, dm::WATER_SEA) != 50) ++bad;
        if (dm::sailedMilesLo(
                dm::VESSEL_WARSHIP, dm::WATER_LAKE) != 40 ||
            dm::sailedMilesHi(
                dm::VESSEL_WARSHIP, dm::WATER_LAKE) != 50) ++bad;
        if (dm::sailedMilesLo(
                dm::VESSEL_RAFT, dm::WATER_SEA) != 0) ++bad;
        // the company pace: the slowest walker sets it, the
        // fallen are skipped, the hire counts at his kit
        {
            Party p;
            Character a; a.hp = 10; a.name = "Strider";
            p.members.push_back(a);
            if (companyFootMilesPerDay(p, dm::TC_NORMAL) != 30)
                ++bad;
            if (companyFootMilesPerDay(p, dm::TC_VERY_RUGGED)
                != 10) ++bad;
            Character b; b.hp = 10; b.name = "Plate";
            b.armor.id = items::ARMOR_PLATE;
            p.members.push_back(b);   // 450 gp wt: heavy
            if (companyFootMilesPerDay(p, dm::TC_NORMAL) != 10)
                ++bad;
            if (companyFootMilesPerDay(p, dm::TC_RUGGED) != 5)
                ++bad;
            p.members[1].hp = 0;   // the laden one falls
            if (companyFootMilesPerDay(p, dm::TC_NORMAL) != 30)
                ++bad;
            Party q;
            q.henchmanPresent = true;   // 625 gp wt: heavy
            if (companyFootMilesPerDay(q, dm::TC_NORMAL) != 10)
                ++bad;
            if (companyFootMilesPerDay(q, dm::TC_VERY_RUGGED)
                != 2) ++bad;
        }
        printf("R123 outdoor movement audit: bad %d\n", bad);
        if (bad) return 1;
    }
