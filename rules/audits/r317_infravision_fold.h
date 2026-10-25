    // ---- R317: the infravision fold audit
    // ----
    // The R311 print (infravision as in
    // dungeons) meets the R154 race data
    // at the R316 vision site: the company
    // best infravision reports its range
    // in the water fight (an elf 60 feet,
    // the all-human company reads no
    // print, the dry fight reads none).
    // Draw-independent: no dice.
    {
        int bad = 0;
        // I1: the elf company - the print
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            st.party.formed = true;
            Character arc;
            arc.name = "Arc";
            arc.classIndex = 0; arc.level = 1;
            arc.race = 2;
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
            bool i1 = false;
            for (int i = 0; i < 4; ++i)
                if (st.log.get(i).find("Infravision reaches 60 feet")
                    != std::string::npos)
                    i1 = true;
            if (!i1) ++bad;
        }
        // I2: the all-human company - no print
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
            for (int i = 0; i < 4; ++i)
                if (st.log.get(i).find("Infravision reaches")
                    != std::string::npos)
                    ++bad;
        }
        // I3: the dry fight - no print
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            st.party.formed = true;
            Character arc;
            arc.name = "Arc";
            arc.classIndex = 0; arc.level = 1;
            arc.race = 2;
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
            if (!st.combat.encounter) ++bad;
            for (int i = 0; i < 4; ++i)
                if (st.log.get(i).find("Infravision reaches")
                    != std::string::npos)
                    ++bad;
        }
            // I4: the pins (the R311 data,
            // the R154 data)
            {
                if (rules::uwInfravisionSameAsDungeon()
                    != 1)
                    ++bad;
                if (rules::raceInfravisionFeet(
                        rules::RACE_ELF) != 60 ||
                    rules::raceInfravisionFeet(
                        rules::RACE_HUMAN) != 0)
                    ++bad;
            }
        printf("R317 infravision fold audit: bad %d\n", bad);
        if (bad) return 1;
    }
