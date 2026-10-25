    // ---- R313: the underwater fight engine audit ----
    // The strength-fed cap and the combat pins
    // charge the R312 crossing site: the laden weak
    // member bars the company (the bump
    // convention), the strong member passes the
    // cap and rolls the drown percent (the replica
    // walked every seed first), the water fight
    // gates the mace swing (the water turns the
    // stroke, the monster hp untouched; the spear
    // strikes, the dry fight swings free) and the
    // missile and hurl commands bar in the pool.
    // The gate scenarios assert only the
    // roll-independent facts (the gate fires before
    // any die; the party of 30 hp outlives the one
    // monster swing of a 1-HD foe).
    {
        int bad = 0;
        // scenario 1: the str 3 member (allowance
        // -350, cap 17) carries 23 lbs beyond the
        // bare armor - barred (seed 1: the wander
        // d12 reads 2, quiet)
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            Character wea;
            wea.name = "Wea";
            wea.classIndex = 0; wea.level = 1;
            wea.race = 0;
            wea.hp = 30; wea.maxHp = 30;
            wea.abilities.str = 3;
            wea.armor.id = items::ARMOR_NONE_EQUIPPED;
            PackItem axe;
            axe.kind = 0;
            axe.id = items::WPN_BATTLE_AXE;
            for (int i = 0; i < 3; ++i)
                wea.pack.push_back(axe);
            st.party.members.push_back(wea);
            st.rng.seed(1);
            if (st.enterWater(5, 7)) ++bad;
            if (st.turnCount != 1) ++bad;
            if (st.party.members[0].hp != 30) ++bad;
            if (st.log.get(0).find(
                    "Wea is too laden to swim")
                == std::string::npos) ++bad;
        }
        // scenario 2: the str 18 member (allowance
        // 750, cap 27) carries 24 lbs - passes the
        // cap; the drown percent reads 13: seed 26
        // rolls 12 (goes under), seed 2 rolls 30
        // (the water holds)
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            Character str;
            str.name = "Str";
            str.classIndex = 0; str.level = 1;
            str.race = 0;
            str.hp = 30; str.maxHp = 30;
            str.abilities.str = 18;
            str.armor.id = items::ARMOR_NONE_EQUIPPED;
            PackItem axe;
            axe.kind = 0;
            axe.id = items::WPN_BATTLE_AXE;
            str.pack.push_back(axe);
            str.pack.push_back(axe);
            PackItem mace;
            mace.kind = 0;
            mace.id = items::WPN_MACE;
            str.pack.push_back(mace);
            st.party.members.push_back(str);
            st.rng.seed(26);
            if (!st.enterWater(5, 7)) ++bad;
            if (st.party.members[0].hp != 0) ++bad;
            if (st.log.get(0).find(
                    "Str goes under - drowned.")
                == std::string::npos) ++bad;
        }
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            Character str;
            str.name = "Str";
            str.classIndex = 0; str.level = 1;
            str.race = 0;
            str.hp = 30; str.maxHp = 30;
            str.abilities.str = 18;
            str.armor.id = items::ARMOR_NONE_EQUIPPED;
            PackItem axe;
            axe.kind = 0;
            axe.id = items::WPN_BATTLE_AXE;
            str.pack.push_back(axe);
            str.pack.push_back(axe);
            PackItem mace;
            mace.kind = 0;
            mace.id = items::WPN_MACE;
            str.pack.push_back(mace);
            st.party.members.push_back(str);
            st.rng.seed(2);
            if (!st.enterWater(5, 7)) ++bad;
            if (st.party.members[0].hp != 30) ++bad;
            if (st.log.get(0).find(
                    "takes to the water")
                == std::string::npos) ++bad;
        }
        // scenario 3: the water fight - the mace
        // swing fails (the water turns the stroke,
        // the monster hp untouched); the spear
        // strikes; the dry fight swings free
        {
            std::vector<ai::Actor> pt;
            ai::Actor a;
            a.isCharacter = true;
            a.classIndex = 0; a.level = 1;
            a.hp = 30; a.maxHp = 30;
            a.weapon.id = items::WPN_MACE;
            pt.push_back(a);
            std::vector<ai::Actor> mons;
            ai::Actor m;
            m.team = 1; m.hitDice = 1;
            m.hp = 6; m.maxHp = 6;
            mons.push_back(m);
            ai::Encounter enc(pt, mons, 7);
            enc.setWaterFight();
            enc.setOpeningBands(1);
            enc.stepRound();
            bool turned = false;
            for (const auto& ln : enc.log())
                if (ln.text.find(
                        "the water turns the stroke")
                    != std::string::npos) turned = true;
            if (!turned) ++bad;
            if (enc.monsters()[0].hp != 6) ++bad;
        }
        {
            std::vector<ai::Actor> pt;
            ai::Actor a;
            a.isCharacter = true;
            a.classIndex = 0; a.level = 1;
            a.hp = 30; a.maxHp = 30;
            a.weapon.id = items::WPN_MACE;
            pt.push_back(a);
            std::vector<ai::Actor> mons;
            ai::Actor m;
            m.team = 1; m.hitDice = 1;
            m.hp = 6; m.maxHp = 6;
            mons.push_back(m);
            ai::Encounter enc(pt, mons, 7);
            enc.setOpeningBands(1);
            enc.stepRound();
            bool turned = false;
            for (const auto& ln : enc.log())
                if (ln.text.find(
                        "the water turns the stroke")
                    != std::string::npos) turned = true;
            if (turned) ++bad;
        }
        {
            std::vector<ai::Actor> pt;
            ai::Actor a;
            a.isCharacter = true;
            a.classIndex = 0; a.level = 1;
            a.hp = 30; a.maxHp = 30;
            a.weapon.id = items::WPN_SPEAR;
            pt.push_back(a);
            std::vector<ai::Actor> mons;
            ai::Actor m;
            m.team = 1; m.hitDice = 1;
            m.hp = 6; m.maxHp = 6;
            mons.push_back(m);
            ai::Encounter enc(pt, mons, 7);
            enc.setWaterFight();
            enc.setOpeningBands(1);
            enc.stepRound();
            bool turned = false;
            for (const auto& ln : enc.log())
                if (ln.text.find(
                        "the water turns the stroke")
                    != std::string::npos) turned = true;
            if (turned) ++bad;
        }
        // scenario 4: the missile and hurl bars -
        // the company in the pool cannot shoot or
        // hurl (beginCombat sets the water fight,
        // the commands bar at the tile)
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            Character arc;
            arc.name = "Arc";
            arc.classIndex = 0; arc.level = 1;
            arc.race = 0;
            arc.hp = 30; arc.maxHp = 30;
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
            st.combatThrow();
            if (st.log.get(0).find(
                    "bars the hurl")
                == std::string::npos) ++bad;
        }
        printf("R313 underwater fight engine audit: bad %d\n", bad);
        if (bad) return 1;
    }
