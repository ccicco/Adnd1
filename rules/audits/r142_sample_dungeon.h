    // ---- R142: sample dungeon audit ----
    // The DMG's own sample delve (pp.94-96, the MONASTERY
    // CELLARS) is keyed as pure data: three rooms (room 0
    // exactly the book 30 foot square entry chamber = 3x3
    // tiles at 10 feet), the two d4 wandering tables, and
    // the keyed texts. The crypt column, the crypt-cleric
    // row, and the crypts behind the seventh knob ride the
    // future-crypts debt (data now, delve later).
    {
        int bad = 0;
        // the sample seed is not the default delve seed
        if (dm::sampledungeon::kSampleSeed == 1) ++bad;
        dm::DungeonResult d =
            dm::sampledungeon::buildSampleDungeon();
        // six rooms: the three keyed chambers plus the
        // three crypt chambers of the R143 crypt wing
        if (d.rooms.size() != 6) {
            ++bad;
        } else {
            if (d.rooms[0].x != 30 || d.rooms[0].y != 30) ++bad;
            if (d.rooms[0].w != 3 || d.rooms[0].h != 3) ++bad;
            if (d.rooms[1].w != 4 || d.rooms[1].h != 5) ++bad;
            if (d.rooms[2].w != 4 || d.rooms[2].h != 4) ++bad;
        }
        // the entry stair lands at the chamber center
        if (d.entryX != 31 || d.entryY != 31) ++bad;
        if (!d.map.walkable(d.entryX, d.entryY)) ++bad;
        // every room tile is walkable
        for (int i = 0; i < (int)d.rooms.size(); ++i) {
            const dm::GeneratedRoom& r = d.rooms[i];
            if (r.w <= 0 || r.h <= 0) { ++bad; continue; }
            for (int yy = 0; yy < r.h; ++yy)
                for (int xx = 0; xx < r.w; ++xx)
                    if (!d.map.walkable(r.x + xx, r.y + yy))
                        ++bad;
        }
        // the passage knits the three chambers together
        for (int x = 33; x <= 45; ++x)
            if (!d.map.walkable(x, 31)) ++bad;
        // determinism: two builds agree tile for tile
        {
            dm::DungeonResult d2 =
                dm::sampledungeon::buildSampleDungeon();
            for (int y = 0; y < world::MAP_TILES_Y; ++y)
                for (int x = 0; x < world::MAP_TILES_X; ++x)
                    if (d.map.at(x, y) != d2.map.at(x, y)) ++bad;
            if (d2.entryX != d.entryX ||
                d2.entryY != d.entryY) ++bad;
        }
        // the halls table, row for row (p.96)
        {
            dm::sampledungeon::SampleWanderingRow w;
            w = dm::sampledungeon::sampleWandering(false, 1);
            if (std::string(w.key) != "goblin" ||
                w.lo != 3 || w.hi != 12) ++bad;
            w = dm::sampledungeon::sampleWandering(false, 2);
            if (std::string(w.key) != "bandit" ||
                w.lo != 2 || w.hi != 5) ++bad;
            w = dm::sampledungeon::sampleWandering(false, 3);
            if (std::string(w.key) != "giant_rat" ||
                w.lo != 7 || w.hi != 12) ++bad;
            w = dm::sampledungeon::sampleWandering(false, 4);
            if (std::string(w.key) != "fire_beetle" ||
                w.lo != 1 || w.hi != 2) ++bad;
        }
        // the crypt column, row for row (future data)
        {
            dm::sampledungeon::SampleWanderingRow w;
            w = dm::sampledungeon::sampleWandering(true, 1);
            if (std::string(w.key) != "ghoul" ||
                w.lo != 1 || w.hi != 2) ++bad;
            w = dm::sampledungeon::sampleWandering(true, 2);
            if (std::string(w.key) != "hobgoblin" ||
                w.lo != 2 || w.hi != 2) ++bad;
            w = dm::sampledungeon::sampleWandering(true, 3);
            if (std::string(w.key) != "giant_rat" ||
                w.lo != 7 || w.hi != 12) ++bad;
            w = dm::sampledungeon::sampleWandering(true, 4);
            if (std::string(w.key) != "skeleton" ||
                w.lo != 2 || w.hi != 5) ++bad;
        }
        // the six keyed texts: nonempty, pure ASCII
        for (int i = 0; i < 6; ++i) {
            const char* t =
                dm::sampledungeon::sampleRoomText(i);
            if (!t || !t[0]) { ++bad; continue; }
            for (const char* p = t; *p; ++p)
                if ((unsigned char)*p > 127) ++bad;
        }
        printf("R142 sample dungeon audit: bad %d\n", bad);
        if (bad) return 1;
    }
