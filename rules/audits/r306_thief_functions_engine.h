    // ---- R306: the thief functions engine audit ----
    // The three wired sites: [I] hides the
    // first living thief (the unobserved
    // attempt stands the dice - the DMG
    // commentary print) and the flag folds at
    // the wander spawn; the pit trap draws
    // the climb walls haul (the coarse
    // surface); the monster lair draws the
    // read languages script (one try per
    // delve). Every scenario sits on a seeded
    // sequence the replica walked first (no
    // compiler in the splice sandbox). The
    // seeds discriminate: scenario 3 reads
    // the draw 165 against the zero dex-9
    // chance while scenario 2 reads the same
    // draw under the 17th-level 990; scenario
    // 4 rides the wander d12 read 1 and the
    // hidden gate must absorb it; scenario 6
    // reads the climb 977 over the 850 - the
    // haul spends its turn; scenario 9 reads
    // the script draw 165 under the 200 with
    // the cache 240 gp at level 3 and the
    // second call must draw nothing.
    {
        int bad = 0;
        // scenario 1: no thief - the turn
        // spends and the shadows stay empty
        // (seed 1: the wander d12 reads 2)
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            Character bru;
            bru.name = "Bru";
            bru.classIndex = 0; bru.level = 1;
            bru.race = 0; bru.abilities.str = 10;
            bru.hp = 30; bru.maxHp = 30;
            st.party.members.push_back(bru);
            st.party.formed = true;
            st.rng.seed(1);
            st.hideExplore();
            if (st.turnCount != 1) ++bad;
            if (st.hiddenThief) ++bad;
            if (st.log.get(0).find(
                    "the shadows stay empty")
                == std::string::npos) ++bad;
        }
        // scenario 2: the hide succeeds - the
        // 17th-level chance reads 990 and the
        // draw 165 hides (seed 1: the wander
        // d12 reads 6, quiet)
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            Character filch;
            filch.name = "Filch";
            filch.classIndex = 3; filch.level = 17;
            filch.race = 0; filch.abilities.dex = 13;
            filch.hp = 30; filch.maxHp = 30;
            st.party.members.push_back(filch);
            st.party.formed = true;
            st.rng.seed(1);
            st.hideExplore();
            if (st.turnCount != 1 || !st.hiddenThief)
                ++bad;
            if (st.log.get(0).find(
                    "Filch melts into the shadows")
                == std::string::npos) ++bad;
        }
        // scenario 3: the same draw 165 against
        // the dex-9 level-1 zero chance - the
        // attempt betrays (seed 1)
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            Character green;
            green.name = "Green";
            green.classIndex = 3; green.level = 1;
            green.race = 0; green.abilities.dex = 9;
            green.hp = 30; green.maxHp = 30;
            st.party.members.push_back(green);
            st.party.formed = true;
            st.rng.seed(1);
            st.hideExplore();
            if (st.turnCount != 1 || st.hiddenThief)
                ++bad;
            if (st.log.get(0).find(
                    "betray the attempt")
                == std::string::npos) ++bad;
        }
        // scenario 4: the hide reads 984 (under
        // the 990) and the same-turn wander
        // reads 1 - the hidden gate absorbs it
        // and the flag is spent (seed 10)
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            Character filch;
            filch.name = "Filch";
            filch.classIndex = 3; filch.level = 17;
            filch.race = 0; filch.abilities.dex = 13;
            filch.hp = 30; filch.maxHp = 30;
            st.party.members.push_back(filch);
            st.party.formed = true;
            st.rng.seed(10);
            st.hideExplore();
            if (st.turnCount != 1 || st.hiddenThief)
                ++bad;
            if (st.log.get(0).find(
                    "the wanderer passes")
                == std::string::npos) ++bad;
            if (st.log.get(1).find(
                    "melts into the shadows")
                == std::string::npos) ++bad;
        }
        // scenario 5: the pit haul - the find
        // draw 165 misses, the victim pick
        // lands on the fighter, the save 4
        // fails, the strike reads 7 and the
        // climb 721 hauls the fighter out (no
        // turn; seed 1, trap kind 28)
        {
            AppState st;
            st.occupancy.rooms.resize(1);
            st.occupancy.rooms[0].roomIndex = 0;
            st.occupancy.rooms[0].trap = 1;
            st.occupancy.rooms[0].trapKind = 28;
            Character pounce;
            pounce.name = "Pounce";
            pounce.classIndex = 3; pounce.level = 1;
            pounce.race = 0;
            pounce.abilities.dex = 9;
            pounce.hp = 30; pounce.maxHp = 30;
            st.party.members.push_back(pounce);
            Character fite;
            fite.name = "Fighter";
            fite.classIndex = 0; fite.level = 1;
            fite.hp = 30; fite.maxHp = 30;
            st.party.members.push_back(fite);
            st.party.formed = true;
            st.rng.seed(1);
            st.springTrap(0);
            if (st.turnCount != 0) ++bad;
            if (st.party.members[0].hp != 30) ++bad;
            if (st.party.members[1].hp != 23) ++bad;
            if (st.occupancy.rooms[0].trap != 2) ++bad;
            if (st.log.get(0).find(
                    "climbs down the pit")
                == std::string::npos) ++bad;
            if (st.log.get(1).find(
                    "strikes Fighter for 7")
                == std::string::npos) ++bad;
        }
        // scenario 6: the missed climb reads
        // 977 (over the 850) - the ropes still
        // haul the fighter out but the turn
        // spends (seed 9: the wander d12
        // reads 6, quiet)
        {
            AppState st;
            st.occupancy.rooms.resize(1);
            st.occupancy.rooms[0].roomIndex = 0;
            st.occupancy.rooms[0].trap = 1;
            st.occupancy.rooms[0].trapKind = 28;
            Character pounce;
            pounce.name = "Pounce";
            pounce.classIndex = 3; pounce.level = 1;
            pounce.race = 0;
            pounce.abilities.dex = 9;
            pounce.hp = 30; pounce.maxHp = 30;
            st.party.members.push_back(pounce);
            Character fite;
            fite.name = "Fighter";
            fite.classIndex = 0; fite.level = 1;
            fite.hp = 30; fite.maxHp = 30;
            st.party.members.push_back(fite);
            st.party.formed = true;
            st.rng.seed(9);
            st.springTrap(0);
            if (st.turnCount != 1) ++bad;
            if (st.party.members[1].hp != 22) ++bad;
            if (st.log.get(0).find(
                    "ropes Fighter out")
                == std::string::npos) ++bad;
            if (st.log.get(1).find(
                    "strikes Fighter for 8")
                == std::string::npos) ++bad;
        }
        // scenario 7: the non-pit regression -
        // the same seed-1 draws but the arrow
        // kind draws no climb and spends no
        // turn
        {
            AppState st;
            st.occupancy.rooms.resize(1);
            st.occupancy.rooms[0].roomIndex = 0;
            st.occupancy.rooms[0].trap = 1;
            st.occupancy.rooms[0].trapKind = 0;
            Character pounce;
            pounce.name = "Pounce";
            pounce.classIndex = 3; pounce.level = 1;
            pounce.race = 0;
            pounce.abilities.dex = 9;
            pounce.hp = 30; pounce.maxHp = 30;
            st.party.members.push_back(pounce);
            Character fite;
            fite.name = "Fighter";
            fite.classIndex = 0; fite.level = 1;
            fite.hp = 30; fite.maxHp = 30;
            st.party.members.push_back(fite);
            st.party.formed = true;
            st.rng.seed(1);
            st.springTrap(0);
            if (st.turnCount != 0) ++bad;
            if (st.party.members[1].hp != 23) ++bad;
            if (st.log.get(0).find(
                    "strikes Fighter for 7")
                == std::string::npos) ++bad;
            if (st.log.get(0).find("hauls")
                != std::string::npos) ++bad;
            if (st.log.get(0).find("ropes")
                != std::string::npos) ++bad;
        }
        // scenario 8: the pit with NO thief -
        // the save 6 fails and the strike reads
        // 8, but no thief draws a climb and no
        // turn spends (seed 1)
        {
            AppState st;
            st.occupancy.rooms.resize(1);
            st.occupancy.rooms[0].roomIndex = 0;
            st.occupancy.rooms[0].trap = 1;
            st.occupancy.rooms[0].trapKind = 28;
            Character fite;
            fite.name = "Fighter";
            fite.classIndex = 0; fite.level = 1;
            fite.hp = 30; fite.maxHp = 30;
            st.party.members.push_back(fite);
            st.party.formed = true;
            st.rng.seed(1);
            st.springTrap(0);
            if (st.turnCount != 0) ++bad;
            if (st.party.members[0].hp != 22) ++bad;
            if (st.log.get(0).find("hauls")
                != std::string::npos) ++bad;
            if (st.log.get(0).find("ropes")
                != std::string::npos) ++bad;
        }
        // scenario 9: the script reads - the
        // draw 165 lands under the 4th-level
        // 200 and the cache reads 240 gp at
        // level 3; the second call draws
        // nothing (seed 1)
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            st.dungeonLevel = 3;
            Character filch;
            filch.name = "Filch";
            filch.classIndex = 3; filch.level = 4;
            filch.race = 0; filch.abilities.dex = 13;
            filch.hp = 30; filch.maxHp = 30;
            st.party.members.push_back(filch);
            st.party.formed = true;
            st.rng.seed(1);
            st.readScript();
            if (!st.scriptTried) ++bad;
            if (st.party.gold != 240) ++bad;
            if (st.party.delveGold != 240) ++bad;
            if (st.log.get(0).find(
                    "a cache holds 240 gp")
                == std::string::npos) ++bad;
            std::string snap = st.log.get(0);
            st.readScript();
            if (st.party.gold != 240) ++bad;
            if (st.log.get(0) != snap) ++bad;
        }
        // scenario 10: the failed read - the
        // draw 330 sits over the 200 and the
        // script stays cryptic; the try is
        // spent either way (seed 2)
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            st.dungeonLevel = 3;
            Character filch;
            filch.name = "Filch";
            filch.classIndex = 3; filch.level = 4;
            filch.race = 0; filch.abilities.dex = 13;
            filch.hp = 30; filch.maxHp = 30;
            st.party.members.push_back(filch);
            st.party.formed = true;
            st.rng.seed(2);
            st.readScript();
            if (!st.scriptTried) ++bad;
            if (st.party.gold != 0) ++bad;
            if (st.log.get(0).find("stays cryptic")
                == std::string::npos) ++bad;
            std::string snap = st.log.get(0);
            st.readScript();
            if (st.log.get(0) != snap) ++bad;
        }
        // scenario 11: no thief - the script
        // waits (the try still spends; seed 1)
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            Character bru;
            bru.name = "Bru";
            bru.classIndex = 0; bru.level = 1;
            bru.race = 0; bru.abilities.str = 10;
            bru.hp = 30; bru.maxHp = 30;
            st.party.members.push_back(bru);
            st.party.formed = true;
            st.rng.seed(1);
            st.readScript();
            if (!st.scriptTried) ++bad;
            if (st.log.get(0).find(
                    "waits for a thief")
                == std::string::npos) ++bad;
        }
        printf("R306 thief functions engine audit: bad %d\n", bad);
        if (bad) return 1;
    }
