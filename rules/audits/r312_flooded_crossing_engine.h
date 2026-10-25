    // ---- R312: the flooded crossing engine audit ----
    // The water site (the R304 locked-door
    // pattern): placeFlood draws a 2-3 by
    // 2-3 tile floor sheet clear of the
    // stairs and the entry, enterWater gates
    // the crossing on the swim armor (magic
    // armor dog paddles) and rolls the R311
    // drown percent once per living swimmer.
    // Every scenario sits on a seeded
    // sequence the replica walked first (no
    // compiler in the splice sandbox). The
    // bare member carries but the dagger (2
    // pounds beyond the armor, the drown
    // percent 5): the roll 4 goes under,
    // the roll 5 holds.
    {
        int bad = 0;
        // scenario 1: the crafted sheet - the
        // floor rows y 20 through 25; seed 3
        // accepts on the first draw: the pool
        // x 6 y 22, 2 by 2
        {
            AppState st;
            for (int y = 0; y < 64; ++y)
                for (int x = 0; x < 64; ++x)
                    st.map.set(x, y, world::TILE_WALL);
            for (int x = 0; x < 64; ++x)
                for (int y = 20; y <= 25; ++y)
                    st.map.set(x, y, world::TILE_FLOOR);
            st.stairsX = 2; st.stairsY = 2;
            st.rng.seed(3);
            st.placeFlood();
            if (st.map.at(6, 22) != world::TILE_WATER)
                ++bad;
            if (st.map.at(7, 23) != world::TILE_WATER)
                ++bad;
            if (st.map.at(5, 22) == world::TILE_WATER)
                ++bad;
            if (st.map.at(6, 21) == world::TILE_WATER)
                ++bad;
            int wet = 0;
            for (int y = 0; y < 64; ++y)
                for (int x = 0; x < 64; ++x)
                    if (st.map.at(x, y) ==
                        world::TILE_WATER) ++wet;
            if (wet != 4) ++bad;
        }
        // scenario 2: the stairs stay dry -
        // the only 2x2 floor pocket holds
        // them, so the one fitting rect
        // covers the stairs; nothing places
        // (seed 4)
        {
            AppState st;
            for (int y = 0; y < 64; ++y)
                for (int x = 0; x < 64; ++x)
                    st.map.set(x, y, world::TILE_WALL);
            for (int y = 10; y <= 11; ++y)
                for (int x = 10; x <= 11; ++x)
                    st.map.set(x, y, world::TILE_FLOOR);
            st.stairsX = 10; st.stairsY = 10;
            st.rng.seed(4);
            st.placeFlood();
            int wet = 0;
            for (int y = 0; y < 64; ++y)
                for (int x = 0; x < 64; ++x)
                    if (st.map.at(x, y) ==
                        world::TILE_WATER) ++wet;
            if (wet != 0) ++bad;
        }
        // scenario 3: the metal-armored member
        // bars the company - the bump turn is
        // spent and the leather swimmer never
        // rolls (seed 1: the wander d12 reads
        // 2, quiet)
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            Character fin;
            fin.name = "Fin";
            fin.classIndex = 0; fin.level = 1;
            fin.race = 0;
            fin.hp = 30; fin.maxHp = 30;
            fin.armor.id = items::ARMOR_LEATHER;
            st.party.members.push_back(fin);
            Character tank;
            tank.name = "Tank";
            tank.classIndex = 0; tank.level = 1;
            tank.race = 0;
            tank.hp = 30; tank.maxHp = 30;
            tank.armor.id = items::ARMOR_PLATE;
            st.party.members.push_back(tank);
            st.rng.seed(1);
            if (st.enterWater(5, 7)) ++bad;
            if (st.turnCount != 1) ++bad;
            if (st.party.members[0].hp != 30 ||
                st.party.members[1].hp != 30) ++bad;
            if (st.log.get(0).find(
                    "Tank cannot swim in")
                == std::string::npos) ++bad;
            if (st.log.get(0).find(
                    "takes to the water")
                != std::string::npos) ++bad;
        }
        // scenario 4: the enchanted plate dog
        // paddles - the crossing succeeds and
        // the roll 7 clears the 5 percent
        // (seed 60)
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            Character mys;
            mys.name = "Mys";
            mys.classIndex = 0; mys.level = 1;
            mys.race = 0;
            mys.hp = 30; mys.maxHp = 30;
            mys.armor.id = items::ARMOR_PLATE;
            mys.armor.plus = 1;
            st.party.members.push_back(mys);
            st.rng.seed(60);
            if (!st.enterWater(5, 7)) ++bad;
            if (st.turnCount != 0) ++bad;
            if (st.party.members[0].hp != 30) ++bad;
            if (st.log.get(0).find(
                    "The company takes to the water.")
                == std::string::npos) ++bad;
        }
        // scenario 5: the drown boundary - the
        // bare leather swimmer carries 2
        // pounds beyond the armor, 5 percent:
        // seed 69 rolls 4 (goes under), seed
        // 180 rolls 5 (the water holds)
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            Character fin;
            fin.name = "Fin";
            fin.classIndex = 0; fin.level = 1;
            fin.race = 0;
            fin.hp = 30; fin.maxHp = 30;
            fin.armor.id = items::ARMOR_LEATHER;
            st.party.members.push_back(fin);
            st.rng.seed(69);
            if (!st.enterWater(5, 7)) ++bad;
            if (st.party.members[0].hp != 0) ++bad;
            if (st.log.get(0).find(
                    "Fin goes under - drowned.")
                == std::string::npos) ++bad;
        }
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            Character fin;
            fin.name = "Fin";
            fin.classIndex = 0; fin.level = 1;
            fin.race = 0;
            fin.hp = 30; fin.maxHp = 30;
            fin.armor.id = items::ARMOR_LEATHER;
            st.party.members.push_back(fin);
            st.rng.seed(180);
            if (!st.enterWater(5, 7)) ++bad;
            if (st.party.members[0].hp != 30) ++bad;
            if (st.log.get(0).find(
                    "The company takes to the water.")
                == std::string::npos) ++bad;
        }
        // scenario 6: the fallen plate wearer
        // rides the pack - the living leather
        // swimmer crosses (seed 91: the roll
        // 9 clears the 5 percent)
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            Character ghost;
            ghost.name = "Ghost";
            ghost.classIndex = 0; ghost.level = 1;
            ghost.race = 0;
            ghost.hp = 0; ghost.maxHp = 30;
            ghost.armor.id = items::ARMOR_PLATE;
            st.party.members.push_back(ghost);
            Character fin;
            fin.name = "Fin";
            fin.classIndex = 0; fin.level = 1;
            fin.race = 0;
            fin.hp = 30; fin.maxHp = 30;
            fin.armor.id = items::ARMOR_LEATHER;
            st.party.members.push_back(fin);
            st.rng.seed(91);
            if (!st.enterWater(5, 7)) ++bad;
            if (st.turnCount != 0) ++bad;
            if (st.log.get(0).find("cannot swim")
                != std::string::npos) ++bad;
            if (st.party.members[0].hp != 0) ++bad;
            if (st.party.members[1].hp != 30) ++bad;
        }
        printf("R312 flooded crossing engine audit: bad %d\n", bad);
        if (bad) return 1;
    }
