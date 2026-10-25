    // ---- R316: the underwater vision seam
    // audit ----
    // The R311 distance pins charge the
    // Encounter vision state at the water
    // fight (the fresh pool surface - 50
    // feet, uwVisionBaseFt); the dry fight
    // keeps the zero default. Draw-
    // independent: the fold reads the pin,
    // no dice.
    {
        int bad = 0;
        // V1: the water fight - the seam
        // reads 50 feet and prints it
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
            std::vector<ai::Actor> foes;
            ai::Actor m;
            m.team = 1; m.hitDice = 2;
            m.hp = 11; m.maxHp = 11;
            foes.push_back(m);
            st.beginCombat(std::move(foes), -1,
                           "giant_rat");
            if (!st.combat.encounter) ++bad;
            if (st.combat.encounter &&
                st.combat.encounter->visionFt()
                    != rules::uwVisionBaseFt(0)) ++bad;
            bool seen = false;
            for (int i = 0; i < 4; ++i)
                if (st.log.get(i).find("Sight runs 50 feet")
                    != std::string::npos)
                    seen = true;
            if (!seen) ++bad;
        }
        // V2: the dry fight - the zero default
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
            st.map.set(5, 5, world::TILE_FLOOR);
            std::vector<ai::Actor> foes;
            ai::Actor m;
            m.team = 1; m.hitDice = 2;
            m.hp = 11; m.maxHp = 11;
            foes.push_back(m);
            st.beginCombat(std::move(foes), -1,
                           "giant_rat");
            if (st.combat.encounter &&
                st.combat.encounter->visionFt()
                    != 0) ++bad;
            for (int i = 0; i < 4; ++i)
                if (st.log.get(i).find("Sight runs")
                    != std::string::npos)
                    ++bad;
        }
        // V3: the setter seam - the state
        // holds what the app feeds
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
            enc.setVisionFt(75);
            if (enc.visionFt() != 75) ++bad;
            enc.setVisionFt(120);
            if (enc.visionFt() != 120) ++bad;
        }
        // V4: the pin bases - fresh 50,
        // salt 100 (the R311 data)
        {
            if (rules::uwVisionBaseFt(0) != 50 ||
                rules::uwVisionBaseFt(1) != 100)
                ++bad;
        }
        printf("R316 underwater vision seam audit: bad %d\n", bad);
        if (bad) return 1;
    }
