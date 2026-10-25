    // ---- R305: the door force engine audit ----
    // The [O] force site: up to
    // doorWidthStandardAttempts living members
    // roll the d6 against the R153 open-doors
    // parentheticals (the wrench is once ever
    // per door) or the simultaneous 1s tear
    // the lock out (the DMG doors prose; the
    // wander check rides, the bump
    // convention). Every scenario sits on a
    // seeded sequence the replica walked first
    // (no compiler in the splice sandbox). The
    // seeds discriminate: scenario 6 holds on
    // rolls 6, 1 and 4 at the width cap - the
    // counterfactual fourth roll reads 1, so a
    // broken cap would tear the lock out; the
    // scenario 8 second roll reads 2, which a
    // missing once-ever gate would spend again.
    {
        int bad = 0;
        // scenario 1: the R153 parentheticals -
        // only the exceptional rows force a lock
        {
            rules::ExceptionalStrength ex;
            if (rules::strOpenDoorsLockedMax(
                    18, ex) != 0) ++bad;
            ex.has = true; ex.pct = 95;
            if (rules::strOpenDoorsLockedMax(
                    18, ex) != 1) ++bad;
            ex.pct = 100;
            if (rules::strOpenDoorsLockedMax(
                    18, ex) != 2) ++bad;
            if (rules::strOpenDoorsLockedMax(
                    17, ex) != 0) ++bad;
        }
        // scenario 2: no lock in reach - the turn
        // spends and the shove finds nothing
        // (seed 1: the wander d12 reads 2, quiet)
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
            st.party.x = 4; st.party.y = 7;
            st.rng.seed(1);
            st.forceLockedDoor();
            if (st.turnCount != 1) ++bad;
            if (st.log.get(0).find("no locked door")
                == std::string::npos) ++bad;
        }
        // scenario 3: the lock sits DIAGONAL - no
        // shove target (seed 1)
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
            st.party.x = 4; st.party.y = 6;
            LockedDoor d;
            d.x = 5; d.y = 7;
            st.lockedDoors.push_back(d);
            st.rng.seed(1);
            st.forceLockedDoor();
            if (st.turnCount != 1) ++bad;
            if (st.log.get(0).find("no locked door")
                == std::string::npos) ++bad;
            if (st.lockedDoorAt(5, 7) == nullptr) ++bad;
            if (st.lockedDoors[0].opened) ++bad;
        }
        // scenario 4: the DEAD member never rolls;
        // the two living shoulders both roll 1 -
        // the lock tears out (seed 77)
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            Character dell;
            dell.name = "Dell";
            dell.classIndex = 0; dell.level = 1;
            dell.race = 0; dell.abilities.str = 10;
            dell.hp = 0; dell.maxHp = 30;
            st.party.members.push_back(dell);
            Character one;
            one.name = "One";
            one.classIndex = 0; one.level = 1;
            one.race = 0; one.abilities.str = 10;
            one.hp = 30; one.maxHp = 30;
            st.party.members.push_back(one);
            Character two;
            two.name = "Two";
            two.classIndex = 0; two.level = 1;
            two.race = 0; two.abilities.str = 10;
            two.hp = 30; two.maxHp = 30;
            st.party.members.push_back(two);
            st.party.formed = true;
            st.party.x = 4; st.party.y = 7;
            LockedDoor d;
            d.x = 5; d.y = 7;
            st.lockedDoors.push_back(d);
            st.rng.seed(77);
            st.forceLockedDoor();
            if (st.turnCount != 1) ++bad;
            if (!st.lockedDoors[0].opened) ++bad;
            if (st.lockedDoors[0].tryLevel != 0) ++bad;
            if (st.log.get(0).find("slam home")
                == std::string::npos) ++bad;
            if (st.log.get(0).find("Dell")
                != std::string::npos) ++bad;
            if (st.lockedDoorAt(5, 7) != nullptr) ++bad;
        }
        // scenario 5: repeatable - the first shove
        // rolls 1 and 6 (one 1, the door holds);
        // the second rolls 1 and 1 (the lock tears
        // out; seed 63)
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            Character one;
            one.name = "One";
            one.classIndex = 0; one.level = 1;
            one.race = 0; one.abilities.str = 10;
            one.hp = 30; one.maxHp = 30;
            st.party.members.push_back(one);
            Character two;
            two.name = "Two";
            two.classIndex = 0; two.level = 1;
            two.race = 0; two.abilities.str = 10;
            two.hp = 30; two.maxHp = 30;
            st.party.members.push_back(two);
            st.party.formed = true;
            st.party.x = 4; st.party.y = 7;
            LockedDoor d;
            d.x = 5; d.y = 7;
            st.lockedDoors.push_back(d);
            st.rng.seed(63);
            st.forceLockedDoor();
            if (st.lockedDoorAt(5, 7) == nullptr) ++bad;
            if (st.log.get(0).find("will not budge")
                == std::string::npos) ++bad;
            st.forceLockedDoor();
            if (st.turnCount != 2 ||
                !st.lockedDoors[0].opened) ++bad;
            if (st.log.get(0).find("slam home")
                == std::string::npos) ++bad;
        }
        // scenario 6: the width cap - four living
        // members but three rolls: 6, 1 and 4 hold
        // the door (the counterfactual fourth roll
        // reads 1 - a broken cap would tear the
        // lock out; seed 17)
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            Character one;
            one.name = "A";
            one.classIndex = 0; one.level = 1;
            one.race = 0; one.abilities.str = 10;
            one.hp = 30; one.maxHp = 30;
            st.party.members.push_back(one);
            Character two;
            two.name = "B";
            two.classIndex = 0; two.level = 1;
            two.race = 0; two.abilities.str = 10;
            two.hp = 30; two.maxHp = 30;
            st.party.members.push_back(two);
            Character three;
            three.name = "C";
            three.classIndex = 0; three.level = 1;
            three.race = 0; three.abilities.str = 10;
            three.hp = 30; three.maxHp = 30;
            st.party.members.push_back(three);
            Character four;
            four.name = "E";
            four.classIndex = 0; four.level = 1;
            four.race = 0; four.abilities.str = 10;
            four.hp = 30; four.maxHp = 30;
            st.party.members.push_back(four);
            st.party.formed = true;
            st.party.x = 4; st.party.y = 7;
            LockedDoor d;
            d.x = 5; d.y = 7;
            st.lockedDoors.push_back(d);
            st.rng.seed(17);
            st.forceLockedDoor();
            if (st.turnCount != 1 ||
                st.lockedDoors[0].opened) ++bad;
            if (st.log.get(0).find("will not budge")
                == std::string::npos) ++bad;
            if (st.log.get(0).find("wrenches")
                != std::string::npos) ++bad;
        }
        // scenario 7: the 18/00 wrench - the
        // parenthetical reads 2 and the roll 2
        // opens it (seed 1)
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            Character might;
            might.name = "Might";
            might.classIndex = 0; might.level = 1;
            might.race = 0;
            might.abilities.str = 18;
            might.exStr.has = true;
            might.exStr.pct = 100;
            might.hp = 30; might.maxHp = 30;
            st.party.members.push_back(might);
            st.party.formed = true;
            st.party.x = 4; st.party.y = 7;
            LockedDoor d;
            d.x = 5; d.y = 7;
            st.lockedDoors.push_back(d);
            st.rng.seed(1);
            st.forceLockedDoor();
            if (st.turnCount != 1) ++bad;
            if (!st.lockedDoors[0].opened ||
                !st.lockedDoors[0].exTried) ++bad;
            if (st.log.get(0).find(
                    "Might wrenches the locked "
                    "door open")
                == std::string::npos) ++bad;
            if (st.lockedDoorAt(5, 7) != nullptr) ++bad;
        }
        // scenario 8: the wrench is ONCE EVER - the
        // roll 3 spends it (the door holds); the
        // second roll reads 2 and the spent wrench
        // never fires (seed 2)
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            Character might;
            might.name = "Might";
            might.classIndex = 0; might.level = 1;
            might.race = 0;
            might.abilities.str = 18;
            might.exStr.has = true;
            might.exStr.pct = 100;
            might.hp = 30; might.maxHp = 30;
            st.party.members.push_back(might);
            st.party.formed = true;
            st.party.x = 4; st.party.y = 7;
            LockedDoor d;
            d.x = 5; d.y = 7;
            st.lockedDoors.push_back(d);
            st.rng.seed(2);
            st.forceLockedDoor();
            if (st.lockedDoors[0].opened ||
                !st.lockedDoors[0].exTried) ++bad;
            if (st.log.get(0).find("will not budge")
                == std::string::npos) ++bad;
            st.forceLockedDoor();
            if (st.turnCount != 2 ||
                st.lockedDoors[0].opened) ++bad;
            if (st.log.get(0).find("wrenches")
                != std::string::npos) ++bad;
            if (st.log.get(0).find("will not budge")
                == std::string::npos) ++bad;
            if (st.lockedDoorAt(5, 7) == nullptr) ++bad;
        }
        printf("R305 door force engine audit: bad %d\n", bad);
        if (bad) return 1;
    }
