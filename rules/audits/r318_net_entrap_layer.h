    // ---- R318: the net entrap layer audit
    // ----
    // The MM hooked nets: the R315 net
    // throwers entrapt on a volley hit
    // (resolveMissile, no wound - nets are
    // used to entrap); STATUS_ENTANGLED
    // bars action (the held precedent); a
    // strength of 16 or greater tears free
    // at the round start (uwNetEntrapStrTear,
    // the stepRound fold BEFORE the end
    // conditions); weaker victims stay held
    // (no escape roll - the print bars it).
    // The volley hit rides the R37 dice (the
    // R315 convention).
    {
        int bad = 0;
        // N1: the gate - an entrapped actor
        // cannot act (Actor-level, no dice)
        {
            ai::Actor a;
            a.isCharacter = true;
            a.name = "Heroa";
            a.hp = 10; a.maxHp = 10;
            a.str = 10;
            if (!a.canAct()) ++bad;
            spelleffects::StatusEffect st;
            st.kind =
                spelleffects::STATUS_ENTANGLED;
            a.addStatus(st);
            if (a.canAct()) ++bad;
        }
        // N2: the tear - STR 17 tears free at
        // the round start (no dice: the fold
        // reads the pin)
        {
            std::vector<ai::Actor> pt;
            ai::Actor a;
            a.isCharacter = true;
            a.name = "Heroa";
            a.classIndex = 0; a.level = 1;
            a.dex = 10;
            a.str = 17;
            a.hp = 30; a.maxHp = 30;
            a.weapon.id = items::WPN_SPEAR;
            spelleffects::StatusEffect st;
            st.kind =
                spelleffects::STATUS_ENTANGLED;
            st.roundsRemaining = 0;   // until torn
            a.addStatus(st);
            pt.push_back(a);
            std::vector<ai::Actor> mons;
            ai::Actor m;
            m.team = 1; m.hitDice = 1;
            m.name = "Monst";
            m.hp = 6; m.maxHp = 6;
            mons.push_back(m);
            ai::Encounter enc(pt, mons, 20);
            enc.stepRound();
            bool torn = false;
            for (const auto& ln : enc.log())
                if (ln.text.find("tears free of the net")
                    != std::string::npos)
                    torn = true;
            if (!torn) ++bad;
            if (enc.party().empty() ||
                enc.party()[0].hasStatus(
                    spelleffects::STATUS_ENTANGLED))
                ++bad;
        }
        // N3: the hold - STR 10 stays
        // entrapped (the hooks, no escape
        // roll exists)
        {
            std::vector<ai::Actor> pt;
            ai::Actor a;
            a.isCharacter = true;
            a.name = "Heroa";
            a.classIndex = 0; a.level = 1;
            a.dex = 10;
            a.str = 10;
            a.hp = 30; a.maxHp = 30;
            a.weapon.id = items::WPN_SPEAR;
            spelleffects::StatusEffect st;
            st.kind =
                spelleffects::STATUS_ENTANGLED;
            st.roundsRemaining = 0;   // until torn
            a.addStatus(st);
            pt.push_back(a);
            std::vector<ai::Actor> mons;
            ai::Actor m;
            m.team = 1; m.hitDice = 1;
            m.name = "Monst";
            m.hp = 6; m.maxHp = 6;
            mons.push_back(m);
            ai::Encounter enc(pt, mons, 20);
            enc.stepRound();
            for (const auto& ln : enc.log())
                if (ln.text.find("tears free of the net")
                    != std::string::npos)
                    ++bad;
            if (enc.party().empty() ||
                !enc.party()[0].hasStatus(
                    spelleffects::STATUS_ENTANGLED))
                ++bad;
            // R318b: the hooks re-assert - the
            // hold must survive a second
            // round-end tick
            enc.stepRound();
            for (const auto& ln : enc.log())
                if (ln.text.find("tears free of the net")
                    != std::string::npos)
                    ++bad;
            if (enc.party().empty() ||
                !enc.party()[0].hasStatus(
                    spelleffects::STATUS_ENTANGLED))
                ++bad;
        }
        // N4: the pins (the MM data)
        {
            if (rules::uwNetEntrapStrTear() != 16)
                ++bad;
        }
        // N5: the mark - the sahuagin net
        // thrower carries the entrap flag in
        // the water fight, not on land
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
                !st.combat.encounter->monsters()[0]
                    .netVolley) ++bad;
        }
        printf("R318 net entrap layer audit: bad %d\n", bad);
        if (bad) return 1;
    }
