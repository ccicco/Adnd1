    // ---- R301: the thief trap rolls engine audit ----
    // The engine audit (the R300/R299 precedent -
    // the C++ battery is the gate; audit_eval reads
    // no engine objects): the seeded rng drives
    // every springTrap branch - the fighter-only
    // strike, the find-and-remove disarm, the
    // too-late strike with the saving victim, the
    // failed find with the multi-member victim
    // pick, the dead-thief skip - and the
    // checkTrapOnEntry wire (the bounds guard,
    // the outside no-op, the in-room spring, the
    // sprung no-op and the MODE_TOWN gate). Every
    // draw sequence was replicated seed-for-seed
    // before the splice was written (the
    // xorshift64* replica; the party formed flag
    // rides every scenario - alive() reads it).
    {
        int bad = 0;
        // the fighter-only strike - seed 1 saves 6
        // (fails the level-1 death 14) and strikes 8:
        // the 30 hit points read 22
        {
            AppState st;
            st.occupancy.rooms.resize(1);
            st.occupancy.rooms[0].roomIndex = 0;
            st.occupancy.rooms[0].trap = 1;
            st.occupancy.rooms[0].trapKind = 0;
            Character f;
            f.name = "Fighter";
            f.classIndex = 0; f.level = 1;
            f.hp = 30; f.maxHp = 30;
            st.party.members.push_back(f);
            st.party.formed = true;
            st.rng.seed(1);
            st.springTrap(0);
            if (st.party.members[0].hp != 22) ++bad;
            if (st.occupancy.rooms[0].trap != 2) ++bad;
            if (st.log.get(0).find("strikes Fighter")
                == std::string::npos) ++bad;
        }
        // the disarm - seed 33 draws the find 21 and
        // the remove 95, both at or below the 100
        // tenths chance (level 1 human dex 9)
        {
            AppState st;
            st.occupancy.rooms.resize(1);
            st.occupancy.rooms[0].roomIndex = 0;
            st.occupancy.rooms[0].trap = 1;
            st.occupancy.rooms[0].trapKind = 0;
            Character t;
            t.name = "Thief";
            t.classIndex = 3; t.level = 1;
            t.hp = 30; t.maxHp = 30;
            t.abilities.dex = 9;
            st.party.members.push_back(t);
            st.party.formed = true;
            st.rng.seed(33);
            st.springTrap(0);
            if (st.party.members[0].hp != 30) ++bad;
            if (st.occupancy.rooms[0].trap != 2) ++bad;
            if (st.log.get(0).find("and disarms it")
                == std::string::npos) ++bad;
            if (st.log.get(0).find("A trap!")
                != std::string::npos) ++bad;
        }
        // the too-late strike - seed 13 finds 14 but
        // draws the remove 614; the thief saves (17
        // against the level-1 death 13)
        {
            AppState st;
            st.occupancy.rooms.resize(1);
            st.occupancy.rooms[0].roomIndex = 0;
            st.occupancy.rooms[0].trap = 1;
            st.occupancy.rooms[0].trapKind = 0;
            Character t;
            t.name = "Thief";
            t.classIndex = 3; t.level = 1;
            t.hp = 30; t.maxHp = 30;
            t.abilities.dex = 9;
            st.party.members.push_back(t);
            st.party.formed = true;
            st.rng.seed(13);
            st.springTrap(0);
            if (st.party.members[0].hp != 30) ++bad;
            if (st.occupancy.rooms[0].trap != 2) ++bad;
            if (st.log.get(0).find("saved!")
                == std::string::npos) ++bad;
            if (st.log.get(1).find("too late")
                == std::string::npos) ++bad;
        }
        // the failed find - seed 1 draws the find 165
        // (above the 100); the victim pick lands on
        // the fighter, the save 4 fails and the
        // strike reads 7
        {
            AppState st;
            st.occupancy.rooms.resize(1);
            st.occupancy.rooms[0].roomIndex = 0;
            st.occupancy.rooms[0].trap = 1;
            st.occupancy.rooms[0].trapKind = 0;
            Character t;
            t.name = "Thief";
            t.classIndex = 3; t.level = 1;
            t.hp = 30; t.maxHp = 30;
            t.abilities.dex = 9;
            st.party.members.push_back(t);
            Character f;
            f.name = "Fighter";
            f.classIndex = 0; f.level = 1;
            f.hp = 30; f.maxHp = 30;
            st.party.members.push_back(f);
            st.party.formed = true;
            st.rng.seed(1);
            st.springTrap(0);
            if (st.party.members[0].hp != 30) ++bad;
            if (st.party.members[1].hp != 23) ++bad;
            if (st.occupancy.rooms[0].trap != 2) ++bad;
            if (st.log.get(0).find("strikes Fighter for 7")
                == std::string::npos) ++bad;
            if (st.log.get(0).find("spots the trap")
                != std::string::npos) ++bad;
        }
        // the dead-thief skip - a dead thief draws
        // nothing (the hp gate); the fighter takes
        // the seed-1 strike (22)
        {
            AppState st;
            st.occupancy.rooms.resize(1);
            st.occupancy.rooms[0].roomIndex = 0;
            st.occupancy.rooms[0].trap = 1;
            st.occupancy.rooms[0].trapKind = 0;
            Character t;
            t.name = "Thief";
            t.classIndex = 3; t.level = 1;
            t.hp = 0; t.maxHp = 30;
            t.abilities.dex = 9;
            st.party.members.push_back(t);
            Character f;
            f.name = "Fighter";
            f.classIndex = 0; f.level = 1;
            f.hp = 30; f.maxHp = 30;
            st.party.members.push_back(f);
            st.party.formed = true;
            st.rng.seed(1);
            st.springTrap(0);
            if (st.party.members[0].hp != 0) ++bad;
            if (st.party.members[1].hp != 22) ++bad;
            if (st.log.get(0).find("strikes Fighter")
                == std::string::npos) ++bad;
        }
        // the entry wire - the bounds guard holds
        // (the trap stays armed), the party outside
        // the room reads no trap, the step into the
        // chamber springs it, the sprung room is a
        // no-op and the MODE_TOWN gate holds after
        // a re-arm
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            st.dungeon.rooms.push_back(
                dm::GeneratedRoom{10, 10, 3, 3,
                                   dm::ROOM_EMPTY});
            st.occupancy.rooms.resize(1);
            st.occupancy.rooms[0].roomIndex = 0;
            st.occupancy.rooms[0].trap = 1;
            st.occupancy.rooms[0].trapKind = 0;
            Character f;
            f.name = "Fighter";
            f.classIndex = 0; f.level = 1;
            f.hp = 30; f.maxHp = 30;
            st.party.members.push_back(f);
            st.party.formed = true;
            st.rng.seed(1);
            st.springTrap(-1);
            st.springTrap(99);
            if (st.occupancy.rooms[0].trap != 1) ++bad;
            if (!st.log.get(0).empty()) ++bad;
            st.party.x = 5; st.party.y = 5;
            st.checkTrapOnEntry();
            if (st.occupancy.rooms[0].trap != 1) ++bad;
            if (st.party.members[0].hp != 30) ++bad;
            st.party.x = 11; st.party.y = 11;
            st.checkTrapOnEntry();
            if (st.party.members[0].hp != 22) ++bad;
            if (st.occupancy.rooms[0].trap != 2) ++bad;
            std::string snap = st.log.get(0);
            if (snap.find("strikes Fighter")
                == std::string::npos) ++bad;
            st.checkTrapOnEntry();
            if (st.party.members[0].hp != 22) ++bad;
            if (st.log.get(0) != snap) ++bad;
            st.occupancy.rooms[0].trap = 1;
            st.mode = MODE_TOWN;
            st.checkTrapOnEntry();
            if (st.occupancy.rooms[0].trap != 1) ++bad;
            if (st.party.members[0].hp != 22) ++bad;
            if (st.log.get(0) != snap) ++bad;
        }
        printf("R301 thief trap rolls engine audit: bad %d\n", bad);
        if (bad) return 1;
    }
