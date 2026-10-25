    // ---- R314: the crossbow and the
    // aquatic wanderers engine audit ----
    // The replica walked every seed first: the
    // pool spawn (seed 11) rolls the fresh
    // shallow cool waterborne table - the
    // percentile draws read 50 (lizard man,
    // 41-60) and 42, the registry count 10 +
    // below(31) reads 22; the first strike
    // (seed 20) reads party surprise 9 and
    // monster 8 (no segments), pIni 5 against
    // mIni 4 - the control company strikes
    // first, the aquatic fold floors the
    // monster at segment 1 and the company
    // at 2. The deep crossbow lifts the
    // missile bar; the short bow keeps it.
    {
        int bad = 0;
        // W1: the waterborne wanderer at the
        // pool - 22 lizard men surface and the
        // encounter begins (the waterborne
        // table owns the pool, the census
        // stays draw-independent)
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            st.party.formed = true;
            Character arc;
            arc.name = "Arc";
            arc.classIndex = 0; arc.level = 1;
            arc.race = 0;
            arc.hp = 30; arc.maxHp = 30;
            st.party.members.push_back(arc);
            st.party.x = 5; st.party.y = 5;
            st.map.set(5, 5, world::TILE_WATER);
            st.registry.loadDirectory(
                "monsters/monsters/l");
            st.rng.seed(11);
            st.spawnWanderingEncounter();
            if (st.mode != MODE_COMBAT) ++bad;
            if (!st.combat.encounter) ++bad;
            if (st.combat.encounter &&
                st.combat.encounter->monsters()
                    .size() != 22) ++bad;
            // R316: the vision print rides the
            // same log - the W1 line reads the
            // window, not the head (the sight
            // print displaces it)
            bool w1seen = false;
            for (int i = 0; i < 4; ++i)
                if (st.log.get(i).find(
                        "22 lizard_man surface in the "
                        "pool!")
                    != std::string::npos)
                    w1seen = true;
            if (!w1seen) ++bad;
        }
        // W2: the aquatic first strike - the
        // waterborne monsters strike first
        // (seed 20: no surprise segments,
        // pIni 5 against mIni 4); the control
        // reads the company first
        {
            std::vector<ai::Actor> pt;
            ai::Actor a;
            a.isCharacter = true;
            a.name = "Heroa";
            a.classIndex = 0; a.level = 1;
            a.dex = 10;
            a.hp = 30; a.maxHp = 30;
            a.weapon.id = items::WPN_SPEAR;
            pt.push_back(a);
            std::vector<ai::Actor> mons;
            ai::Actor m;
            m.team = 1; m.hitDice = 1;
            m.name = "Monst";
            m.hp = 6; m.maxHp = 6;
            mons.push_back(m);
            ai::Encounter enc(pt, mons, 20);
            enc.setWaterFight();
            enc.setAquatic();
            enc.setOpeningBands(1);
            enc.stepRound();
            int first = -1;   // 0 Heroa, 1 Monst
            for (const auto& ln : enc.log()) {
                if (ln.text.find("Heroa") == 0)
                    { first = 0; break; }
                if (ln.text.find("Monst") == 0)
                    { first = 1; break; }
            }
            if (first != 1) ++bad;
        }
        {
            std::vector<ai::Actor> pt;
            ai::Actor a;
            a.isCharacter = true;
            a.name = "Heroa";
            a.classIndex = 0; a.level = 1;
            a.dex = 10;
            a.hp = 30; a.maxHp = 30;
            a.weapon.id = items::WPN_SPEAR;
            pt.push_back(a);
            std::vector<ai::Actor> mons;
            ai::Actor m;
            m.team = 1; m.hitDice = 1;
            m.name = "Monst";
            m.hp = 6; m.maxHp = 6;
            mons.push_back(m);
            ai::Encounter enc(pt, mons, 20);
            enc.setWaterFight();
            enc.setOpeningBands(1);
            enc.stepRound();
            int first = -1;   // 0 Heroa, 1 Monst
            for (const auto& ln : enc.log()) {
                if (ln.text.find("Heroa") == 0)
                    { first = 0; break; }
                if (ln.text.find("Monst") == 0)
                    { first = 1; break; }
            }
            if (first != 0) ++bad;
        }
        // C1: the deep crossbow lifts the
        // underwater missile bar - the member
        // readies the shot in the pool
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            st.party.formed = true;
            Character arc;
            arc.name = "Arc";
            arc.classIndex = 0; arc.level = 1;
            arc.race = 0;
            arc.hp = 30; arc.maxHp = 30;
            arc.rangedWeapon.id =
                items::WPN_CROSSBOW_DEEP;
            arc.missileAmmo = 5;
            st.party.members.push_back(arc);
            st.party.x = 5; st.party.y = 5;
            st.map.set(5, 5, world::TILE_WATER);
            std::vector<ai::Actor> foes;
            ai::Actor m;
            m.team = 1; m.hitDice = 1;
            m.hp = 6; m.maxHp = 6;
            foes.push_back(m);
            st.beginCombat(std::move(foes), -1,
                           "giant_rat");
            st.combatShoot();
            if (st.log.get(0).find(
                    "Missiles readied")
                == std::string::npos) ++bad;
            if (st.log.get(0).find(
                    "bars missile fire")
                != std::string::npos) ++bad;
        }
        // C2: the short bow keeps the bar -
        // the lift is the deep crossbow alone
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            st.party.formed = true;
            Character arc;
            arc.name = "Arc";
            arc.classIndex = 0; arc.level = 1;
            arc.race = 0;
            arc.hp = 30; arc.maxHp = 30;
            arc.rangedWeapon.id =
                items::WPN_SHORT_BOW;
            arc.missileAmmo = 5;
            st.party.members.push_back(arc);
            st.party.x = 5; st.party.y = 5;
            st.map.set(5, 5, world::TILE_WATER);
            std::vector<ai::Actor> foes;
            ai::Actor m;
            m.team = 1; m.hitDice = 1;
            m.hp = 6; m.maxHp = 6;
            foes.push_back(m);
            st.beginCombat(std::move(foes), -1,
                           "giant_rat");
            st.combatShoot();
            if (st.log.get(0).find(
                    "bars missile fire")
                == std::string::npos) ++bad;
        }
        printf("R314 crossbow and aquatic engine audit: bad %d\n", bad);
        if (bad) return 1;
    }
