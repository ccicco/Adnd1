    // ==== R1050: dm movement registry ========================
    // The R1050 de-wire: the five movement grids of
    // dm/outdoormove.h ride items::MiscItemRegistry
    // from content/tables/dm_movement/ (5 defs). Six sections:
    // load, counts, land grids, afloat, seam, edges.
    // Census 1058 -> 1064. DO NOT
    // hand-edit: tools/r1050_splice.py is the
    // only writer.
    {
        int bad = 0;
        // -- 1. load ---------------------------------
        {
            items::MiscItemRegistry reg;
            int n = reg.loadDirectory(
                "content/tables/dm_movement");
            if (n != 5) ++bad;
            if (!reg.errors().empty()) ++bad;
            for (const auto& kv : reg.all())
                if ((int)kv.second.sources
                    .size() != 1)
                    ++bad;
        }
        printf("R1050 dm movement registry load audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 2. counts ---------------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/dm_movement");
            {
                const items::MiscItemDef* d =
                    reg.find("dm_move_foot");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 0
                        || (int)d->pins.size() != 2
                        || d->pins[0].value != 3
                        || d->pins[1].value != 3
                        || (int)d->tables.size() != 1
                        || d->tables[0].name != "grid"
                        || (int)d->tables[0].values
                            .size() != 9)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("dm_move_mounted");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 0
                        || (int)d->pins.size() != 2
                        || d->pins[0].value != 6
                        || d->pins[1].value != 3
                        || (int)d->tables.size() != 1
                        || d->tables[0].name != "grid"
                        || (int)d->tables[0].values
                            .size() != 18)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("dm_move_oared");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 0
                        || (int)d->pins.size() != 2
                        || d->pins[0].value != 8
                        || d->pins[1].value != 5
                        || (int)d->tables.size() != 1
                        || d->tables[0].name != "grid"
                        || (int)d->tables[0].values
                            .size() != 40)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("dm_move_sail_lo");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 0
                        || (int)d->pins.size() != 2
                        || d->pins[0].value != 8
                        || d->pins[1].value != 5
                        || (int)d->tables.size() != 1
                        || d->tables[0].name != "grid"
                        || (int)d->tables[0].values
                            .size() != 40)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("dm_move_sail_hi");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 0
                        || (int)d->pins.size() != 2
                        || d->pins[0].value != 8
                        || d->pins[1].value != 5
                        || (int)d->tables.size() != 1
                        || d->tables[0].name != "grid"
                        || (int)d->tables[0].values
                            .size() != 40)
                        ++bad;
                }
            }
        }
        printf("R1050 dm movement registry counts audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 3. land grids -----------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/dm_movement");
            const items::MiscItemDef* df = reg.find(
                "dm_move_foot");
            const items::MiscItemDef* dk = reg.find(
                "dm_move_mounted");
            if (!df || !dk) { ++bad; } else {
                const int wantFoot[] = { 30, 20, 10, 20, 10, 5, 10, 5, 2 };
                const int wantMounted[] = { 60, 25, 5, 40, 20, 5, 30, 15, 5,
                    30, 15, 5, 25, 15, 0, 25, 10, 0 };
                for (int i = 0; i < 9; ++i)
                    if ((int)df->tables[0].values[i] != wantFoot[i]) ++bad;
                for (int i = 0; i < 18; ++i)
                    if ((int)dk->tables[0].values[i] != wantMounted[i]) ++bad;
            }
        }
        printf("R1050 dm movement registry land grids audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 4. afloat ---------------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/dm_movement");
            const items::MiscItemDef* d1 = reg.find(
                "dm_move_oared");
            const items::MiscItemDef* d2 = reg.find(
                "dm_move_sail_lo");
            const items::MiscItemDef* d3 = reg.find(
                "dm_move_sail_hi");
            if (!d1 || !d2 || !d3) { ++bad; } else {
                const int wantOared[] = { 15, 5, 15, 0, 10, 30, 15, 35, 0, 25,
                    20, 5, 20, 0, 0, 40, 5, 40, 30, 0, 30, 0, 30, 30, 0, 10,
                    0, 15, 20, 0, 10, 0, 10, 15, 0, 10, 0, 10, 20, 0 };
                const int wantLo[] = { 30, 10, 30, 0, 15, 80, 20, 60, 0, 40,
                    50, 10, 40, 0, 0, 70, 0, 60, 50, 0, 50, 0, 50, 50, 0, 50,
                    0, 50, 50, 0, 25, 0, 35, 35, 0, 40, 0, 40, 50, 0 };
                const int wantHi[] = { 30, 10, 30, 0, 15, 80, 20, 60, 0, 40,
                    50, 10, 40, 0, 0, 80, 0, 60, 50, 0, 60, 0, 50, 50, 0, 60,
                    0, 50, 50, 0, 35, 0, 35, 35, 0, 50, 0, 40, 50, 0 };
                for (int i = 0; i < 40; ++i) {
                    if ((int)d1->tables[0].values[i] != wantOared[i]) ++bad;
                    if (wantLo[i] > wantHi[i]) ++bad;
                    if ((int)d2->tables[0].values[i] != wantLo[i]) ++bad;
                    if ((int)d3->tables[0].values[i] != wantHi[i]) ++bad;
                }
            }
        }
        printf("R1050 dm movement registry afloat audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 5. seam cross-read -------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/dm_movement");
            const items::MiscItemDef* dfr = reg.find(
                "dm_move_foot");
            const items::MiscItemDef* dmo = reg.find(
                "dm_move_mounted");
            const items::MiscItemDef* doe = reg.find(
                "dm_move_oared");
            const items::MiscItemDef* dlo = reg.find(
                "dm_move_sail_lo");
            const items::MiscItemDef* dhi = reg.find(
                "dm_move_sail_hi");
            if (!dfr || !dmo || !doe || !dlo || !dhi)
                ++bad;
            for (int b = 0; b < 3; ++b)
                for (int t = 0; t < 3; ++t)
                    if (dm::footMilesPerDay(
                            (dm::FootBurden)b,
                            (dm::TerrainClass)t)
                        != (int)dfr->tables[0]
                            .values[b * 3 + t])
                        ++bad;
            for (int m = 0; m < 6; ++m)
                for (int t = 0; t < 3; ++t)
                    if (dm::mountedMilesPerDay(
                            (dm::MountKind)m,
                            (dm::TerrainClass)t)
                        != (int)dmo->tables[0]
                            .values[m * 3 + t])
                        ++bad;
            for (int v = 0; v < 8; ++v)
                for (int w = 0; w < 5; ++w) {
                    int i = v * 5 + w;
                    if (dm::oaredMilesPerDay(
                            (dm::VesselKind)v,
                            (dm::WaterKind)w)
                        != (int)doe->tables[0]
                            .values[i]) ++bad;
                    if (dm::sailedMilesLo(
                            (dm::VesselKind)v,
                            (dm::WaterKind)w)
                        != (int)dlo->tables[0]
                            .values[i]) ++bad;
                    if (dm::sailedMilesHi(
                            (dm::VesselKind)v,
                            (dm::WaterKind)w)
                        != (int)dhi->tables[0]
                            .values[i]) ++bad;
                }
        }
        printf("R1050 dm movement registry seam audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 6. edges ---------------------------------
        {
            if (dm::footBurdenFor(0) != dm::FB_LIGHT) ++bad;
            if (dm::footBurdenFor(25) != dm::FB_LIGHT) ++bad;
            if (dm::footBurdenFor(26) != dm::FB_AVERAGE) ++bad;
            if (dm::footBurdenFor(60) != dm::FB_AVERAGE) ++bad;
            if (dm::footBurdenFor(61) != dm::FB_HEAVY) ++bad;
            if (dm::terrainClass(dm::T_DESERT)
                != dm::TC_NORMAL) ++bad;
            if (dm::terrainClass(dm::T_FOREST)
                != dm::TC_RUGGED) ++bad;
            if (dm::terrainClass(dm::T_HILLS)
                != dm::TC_RUGGED) ++bad;
            if (dm::terrainClass(dm::T_MARSH)
                != dm::TC_VERY_RUGGED) ++bad;
            if (dm::terrainClass(dm::T_MOUNTAINS)
                != dm::TC_VERY_RUGGED) ++bad;
            if (dm::terrainClass(dm::T_PLAIN)
                != dm::TC_NORMAL) ++bad;
            if (dm::terrainClass(dm::T_ROUGH)
                != dm::TC_RUGGED) ++bad;
            if (dm::terrainClass(dm::T_SCRUB)
                != dm::TC_NORMAL) ++bad;
            if (dm::sailedMilesLo(
                    dm::VESSEL_MERCHANT_SMALL,
                    dm::WATER_SEA) != 50) ++bad;
            if (dm::sailedMilesHi(
                    dm::VESSEL_MERCHANT_SMALL,
                    dm::WATER_SEA) != 50) ++bad;
            if (dm::footMilesPerDay(
                    dm::FB_HEAVY, dm::TC_VERY_RUGGED) != 2) ++bad;
            if (dm::mountedMilesPerDay(
                    dm::MOUNT_CART, dm::TC_VERY_RUGGED) != 0) ++bad;
            if (dm::mountedMilesPerDay(
                    dm::MOUNT_WAGON, dm::TC_VERY_RUGGED) != 0) ++bad;
        }
        printf("R1050 dm movement registry edges audit: bad %d\n", bad);
    }
