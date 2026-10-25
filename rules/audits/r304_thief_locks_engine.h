    // ---- R304: the thief locks engine audit ----
    // The locked-door site (the R45 placement
    // pattern): one door per delve bars a wall
    // slot with open tiles on both sides of one
    // axis; the bump spends the turn and the
    // first living thief works the lock for the
    // DMG time draw (1-10 rounds) against the
    // printed open locks percentile (the R298
    // seam), one try per lock - a retry waits
    // for a higher level thief. Every scenario
    // sits on a seeded sequence the replica
    // walked first (no compiler in the splice
    // sandbox). The seeds discriminate: the
    // scenario 1 coordinate (x 33) pins the
    // scan draws, the scenario 2 map defeats
    // the one-sided predicate, and the
    // scenario 5 first roll (167) fails only
    // WITH the dex 9 fold (the plain 250 base
    // would open it).
    {
        int bad = 0;
        // scenario 1: a crafted strip - floor
        // rows y 9 and y 11, wall row y 10.
        // Seed 1: the scan lands x 33 y 10
        {
            AppState st;
            for (int y = 0; y < 64; ++y)
                for (int x = 0; x < 64; ++x)
                    st.map.set(x, y, world::TILE_WALL);
            for (int x = 0; x < 64; ++x) {
                st.map.set(x, 9, world::TILE_FLOOR);
                st.map.set(x, 11, world::TILE_FLOOR);
            }
            st.rng.seed(1);
            st.placeLockedDoors();
            if ((int)st.lockedDoors.size() != 1) ++bad;
            if (st.lockedDoors[0].x != 33 ||
                st.lockedDoors[0].y != 10) ++bad;
            if (st.map.at(33, 10) !=
                world::TILE_DOOR) ++bad;
            if (st.lockedDoorAt(33, 10) == nullptr)
                ++bad;
            if (st.lockedDoorAt(33, 9) != nullptr) ++bad;
            if (st.lockedDoorAt(3, 10) != nullptr) ++bad;
        }
        // scenario 2: one open side is no slot -
        // the lone floor row y 9 places nothing
        {
            AppState st;
            for (int y = 0; y < 64; ++y)
                for (int x = 0; x < 64; ++x)
                    st.map.set(x, y, world::TILE_WALL);
            for (int x = 0; x < 64; ++x)
                st.map.set(x, 9, world::TILE_FLOOR);
            st.rng.seed(2);
            st.placeLockedDoors();
            if (!st.lockedDoors.empty()) ++bad;
        }
        // scenario 3: the no-thief bump - the
        // turn is spent, the try is not (seed
        // 1: the wander d12 reads 2, quiet)
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            LockedDoor d;
            d.x = 5; d.y = 7;
            st.lockedDoors.push_back(d);
            st.rng.seed(1);
            st.bumpLockedDoor(5, 7);
            if (st.turnCount != 1) ++bad;
            if (st.lockedDoors[0].tryLevel != 0 ||
                st.lockedDoors[0].opened) ++bad;
            if (st.log.get(0).find("no thief")
                == std::string::npos) ++bad;
            if (st.lockedDoorAt(5, 7) == nullptr) ++bad;
        }
        // scenario 4: the pick succeeds - the
        // DEAD thief never rolls; the living one
        // (level 17 human dex 18, chance 1140)
        // opens it (seed 1: 6 rounds, the roll
        // 517, the wander d12 8)
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            Character fell;
            fell.name = "Fell";
            fell.classIndex = 3; fell.level = 17;
            fell.race = 0; fell.abilities.dex = 18;
            fell.hp = 0; fell.maxHp = 30;
            st.party.members.push_back(fell);
            Character sly;
            sly.name = "Sly";
            sly.classIndex = 3; sly.level = 17;
            sly.race = 0; sly.abilities.dex = 18;
            sly.hp = 30; sly.maxHp = 30;
            st.party.members.push_back(sly);
            LockedDoor d;
            d.x = 5; d.y = 7;
            st.lockedDoors.push_back(d);
            st.rng.seed(1);
            st.bumpLockedDoor(5, 7);
            if (st.turnCount != 1) ++bad;
            if (!st.lockedDoors[0].opened ||
                st.lockedDoors[0].tryLevel != 17) ++bad;
            if (st.log.get(0).find(
                    "Sly works the lock for 6 rounds "
                    "- it opens")
                == std::string::npos) ++bad;
            if (st.log.get(0).find("Fell")
                != std::string::npos) ++bad;
            if (st.lockedDoorAt(5, 7) != nullptr) ++bad;
        }
        // scenario 5: the one-try ladder (seed
        // 23). Bump 1 at level 1 (chance 150):
        // the roll 167 resists - only WITH the
        // dex 9 fold; bump 2 at the same level
        // reads the refuse line (no time or
        // percentile draw); bump 3 at level 2
        // (chance 190) retries: 6 rounds, the
        // roll 299 resists again
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            Character sly;
            sly.name = "Sly";
            sly.classIndex = 3; sly.level = 1;
            sly.race = 0; sly.abilities.dex = 9;
            sly.hp = 30; sly.maxHp = 30;
            st.party.members.push_back(sly);
            LockedDoor d;
            d.x = 5; d.y = 7;
            st.lockedDoors.push_back(d);
            st.rng.seed(23);
            st.bumpLockedDoor(5, 7);
            if (st.lockedDoors[0].opened ||
                st.lockedDoors[0].tryLevel != 1) ++bad;
            if (st.log.get(0).find(
                    "for 1 rounds - it resists")
                == std::string::npos) ++bad;
            st.bumpLockedDoor(5, 7);
            if (st.turnCount != 2 ||
                st.lockedDoors[0].tryLevel != 1) ++bad;
            if (st.log.get(0).find("higher level")
                == std::string::npos) ++bad;
            st.party.members[0].level = 2;
            st.bumpLockedDoor(5, 7);
            if (st.turnCount != 3 ||
                st.lockedDoors[0].opened ||
                st.lockedDoors[0].tryLevel != 2) ++bad;
            if (st.log.get(0).find(
                    "for 6 rounds - it resists")
                == std::string::npos) ++bad;
            if (st.log.get(0).find("higher level")
                != std::string::npos) ++bad;
            if (st.lockedDoorAt(5, 7) == nullptr) ++bad;
        }
        printf("R304 thief locks engine audit: bad %d\n", bad);
        if (bad) return 1;
    }
