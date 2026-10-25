    // ---- R143: crypt wing audit ----
    // The sample dungeon's crypts are delved at last:
    // three crypt chambers off a spine south of the
    // dome, SEALED behind the seventh knob's door (rock
    // until openCryptDoor turns it), laired per the
    // book's crypt-column area hints, and the crypt
    // wandering column wired - the evil cleric row rides
    // the Character-foe path in the engine (no audit
    // hook; the row's hobgoblins are pinned in R142).
    {
        int bad = 0;
        dm::DungeonResult d =
            dm::sampledungeon::buildSampleDungeon();
        // the crypt wing hangs south of the dome
        if (d.rooms.size() < 6) {
            ++bad;
        } else {
            if (d.rooms[3].x != 40 || d.rooms[3].y != 38 ||
                d.rooms[3].w != 4 || d.rooms[3].h != 3) ++bad;
            if (d.rooms[4].x != 46 || d.rooms[4].y != 38 ||
                d.rooms[4].w != 4 || d.rooms[4].h != 3) ++bad;
            if (d.rooms[5].x != 52 || d.rooms[5].y != 38 ||
                d.rooms[5].w != 4 || d.rooms[5].h != 3) ++bad;
        }
        // the crypt chambers are carved walkable
        for (int i = 3; i < 6 && i < (int)d.rooms.size();
             ++i) {
            const dm::GeneratedRoom& r = d.rooms[i];
            for (int yy = 0; yy < r.h; ++yy)
                for (int xx = 0; xx < r.w; ++xx)
                    if (!d.map.walkable(r.x + xx, r.y + yy))
                        ++bad;
        }
        // the descent and the spine
        if (!d.map.walkable(47, 35) ||
            !d.map.walkable(47, 36)) ++bad;
        for (int x = 40; x <= 55; ++x)
            if (!d.map.walkable(x, 37)) ++bad;
        // the knob door is SEALED rock until turned
        if (d.map.walkable(dm::sampledungeon::kCryptDoorX,
                          dm::sampledungeon::kCryptDoorY))
            ++bad;
        if (dm::sampledungeon::cryptDoorOpen(d.map)) ++bad;
        dm::sampledungeon::openCryptDoor(d.map);
        if (!dm::sampledungeon::cryptDoorOpen(d.map)) ++bad;
        if (d.map.at(dm::sampledungeon::kCryptDoorX,
                     dm::sampledungeon::kCryptDoorY) !=
            world::TILE_DOOR) ++bad;
        // the wing's boundary: the halls sit above the
        // knob, the crypts below it
        if (dm::sampledungeon::inCrypts(31, 31)) ++bad;
        if (!dm::sampledungeon::inCrypts(47, 37)) ++bad;
        if (!dm::sampledungeon::inCrypts(53, 40)) ++bad;
        // the crypt texts: nonempty, pure ASCII
        for (int i = 3; i < 6; ++i) {
            const char* t =
                dm::sampledungeon::sampleRoomText(i);
            if (!t || !t[0]) { ++bad; continue; }
            for (const char* p = t; *p; ++p)
                if ((unsigned char)*p > 127) ++bad;
        }
        printf("R143 crypt wing audit: bad %d\n", bad);
        if (bad) return 1;
    }
