    // ---- R315: the net throwers engine
    // audit ----
    // The MM arms rows (the Lua roster):
    // sahuagin trident, net and dagger 50
    // percent; locathah and merman net rows
    // - the waterborne races open the water
    // fight with a net volley (the R37
    // pattern), the bands read the DMG throw
    // pins (sahuagin 20 feet = 2 bands, the
    // underwater races 15 feet = 1). The
    // asserts read the volley marks and the
    // round spend, draw-independent (the hit
    // rolls ride the R37 dice); on land the
    // nets stay swapped for javelins (MM).
    {
        int bad = 0;
        // N1: the sahuagin net volley - 2
        // bands (uwNetThrowSahuaginFt)
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
                           "sahuagin");
            if (!st.combat.encounter) ++bad;
            if (st.combat.encounter &&
                !st.combat.encounter->monsters()[0].monsterRanged) ++bad;
            if (st.combat.encounter &&
                st.combat.encounter->monsters()[0].rangedRounds != 2) ++bad;
        }
        // N2: the locathah net - 1 band
        // (uwNetThrowUnderwaterRaceFt)
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
                           "locathah");
            if (!st.combat.encounter) ++bad;
            if (st.combat.encounter &&
                st.combat.encounter->monsters()[0].rangedRounds != 1) ++bad;
        }
        // N3: the merman net - 1 band
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
                           "merman");
            if (!st.combat.encounter) ++bad;
            if (st.combat.encounter &&
                st.combat.encounter->monsters()[0].rangedRounds != 1) ++bad;
        }
        // N4: on land the nets stay swapped
        // for javelins (MM) - no volley
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
                           "sahuagin");
            if (!st.combat.encounter) ++bad;
            if (st.combat.encounter &&
                st.combat.encounter->monsters()[0].monsterRanged) ++bad;
        }
        // N5: the giant rat keeps no net
        // (the R313 audit scenario 4
        // regression)
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
                st.combat.encounter->monsters()[0].monsterRanged) ++bad;
        }
        // N6: the volley spend - one band
        // per round (the R42 convention),
        // the third round adds no volley
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
                           "sahuagin");
            if (!st.combat.encounter) ++bad;
            if (st.combat.encounter)
                st.combat.encounter->stepRound();
            if (st.combat.encounter &&
                st.combat.encounter->monsters()[0].rangedRounds != 1) ++bad;
            if (st.combat.encounter)
                st.combat.encounter->stepRound();
            if (st.combat.encounter &&
                st.combat.encounter->monsters()[0].rangedRounds != 0) ++bad;
            if (st.combat.encounter)
                st.combat.encounter->stepRound();
            if (st.combat.encounter &&
                st.combat.encounter->monsters()[0].rangedRounds != 0) ++bad;
        }
        printf("R315 net throwers engine audit: bad %d\n", bad);
        if (bad) return 1;
    }
