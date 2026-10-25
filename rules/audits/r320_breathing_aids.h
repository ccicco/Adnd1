    // ---- R320: the breathing aids audit ----
    // The R311 recorded-notes charge: the
    // druid Water Breathing (the status at
    // the engine, the row saves not) and
    // the III.A potion (the claim layer).
    // No drowning site exists - the prints
    // are the charge. Draw-independent: the
    // row saves not, the folds read pins.
    {
        int bad = 0;
        // B1: the status - the spell engine
        // level (no save on the row)
        {
            rules::Rng r(11);
            rules::Dice d(r);
            ai::Actor t;
            t.team = 1; t.hitDice = 1;
            t.hp = 6; t.maxHp = 6;
            std::vector<spelleffects::TargetDesc>
                ds;
            ds.push_back(t.asTarget());
            spelleffects::SpellCastResult r1 =
                spelleffects::resolveSpell(
                    d, spells::DR_WATER_BREATHING,
                    5, ds);
            if (r1.perTarget.size() != 1) ++bad;
            if (!r1.perTarget.empty() &&
                r1.perTarget[0].status.kind !=
                    spelleffects::
                    STATUS_WATERBREATHING)
                ++bad;
        }
        // B2: the cast fold - a party cast in
        // the water fight marks the company
        {
            std::vector<ai::Actor> pt;
            ai::Actor a;
            a.isCharacter = true;
            a.team = 0;
            a.name = "Heroa";
            a.classIndex = 4; a.level = 5;
            a.slotsByLevel[2] = 1;
            a.hp = 30; a.maxHp = 30;
            pt.push_back(a);
            std::vector<ai::Actor> mons;
            ai::Actor m;
            m.team = 1; m.hitDice = 1;
            m.name = "Monst";
            m.hp = 6; m.maxHp = 6;
            mons.push_back(m);
            ai::Encounter enc(pt, mons, 20);
            enc.setWaterFight();
            enc.resolveCast(
                enc.partyMutable()[0],
                spells::DR_WATER_BREATHING);
            if (!enc.breathActive()) ++bad;
            bool br = false;
            for (const auto& ln : enc.log())
                if (ln.text.find("breathes water freely") !=
                    std::string::npos)
                    br = true;
            if (!br) ++bad;
            // the slot spent
            if (enc.partyMutable()[0]
                    .slotsByLevel[2] != 0) ++bad;
        }
        // B3: the dry gate - no water fight,
        // no mark, no print
        {
            std::vector<ai::Actor> pt;
            ai::Actor a;
            a.isCharacter = true;
            a.team = 0;
            a.name = "Heroa";
            a.classIndex = 4; a.level = 5;
            a.slotsByLevel[2] = 1;
            a.hp = 30; a.maxHp = 30;
            pt.push_back(a);
            std::vector<ai::Actor> mons;
            ai::Actor m;
            m.team = 1; m.hitDice = 1;
            m.name = "Monst";
            m.hp = 6; m.maxHp = 6;
            mons.push_back(m);
            ai::Encounter enc(pt, mons, 20);
            enc.resolveCast(
                enc.partyMutable()[0],
                spells::DR_WATER_BREATHING);
            if (enc.breathActive()) ++bad;
            bool br = false;
            for (const auto& ln : enc.log())
                if (ln.text.find("breathes water freely") !=
                    std::string::npos)
                    br = true;
            if (br) ++bad;
        }
        // B4: the claim (the claimUwHelm
        // pattern)
        {
            Character c;
            c.hp = 10;
            if (!claimUwDraught(
                    c, "Potion of Water Breathing",
                    1)) ++bad;
            if (!c.uwDraught) ++bad;
            // one draught per member
            if (claimUwDraught(
                    c, "Potion of Water Breathing",
                    1)) ++bad;
            c.uwDraught = false;
            // other potions never claim
            if (claimUwDraught(
                    c, "Potion of Healing",
                    1)) ++bad;
            // bundles never claim
            if (claimUwDraught(
                    c, "Potion of Water Breathing",
                    2)) ++bad;
            // the dead claim nothing
            c.hp = 0;
            if (claimUwDraught(
                    c, "Potion of Water Breathing",
                    1)) ++bad;
        }
        // B5: the pool print - the carried
        // draught holds at the water fight
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            st.party.formed = true;
            Character arc;
            arc.name = "Arc";
            arc.classIndex = 0; arc.level = 1;
            arc.race = 0;
            arc.hp = 30; arc.maxHp = 30;
            arc.uwDraught = true;
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
            bool dp = false;
            for (int i = 0; i < 5; ++i)
                if (st.log.get(i).find("draught of water breathing") !=
                    std::string::npos)
                    dp = true;
            if (!dp) ++bad;
        }
        // B6: the name array - every kind
        // names (the R319 shortfall pinned)
        {
            for (int k = 0;
                 k < (int)spelleffects::STATUS_COUNT;
                 ++k)
                if (spelleffects::statusName(
                        (spelleffects::StatusKind)k)
                    == nullptr) ++bad;
            // R515: a strcmp, not a pointer compare against the literal
            // (the old != "Breathing" checked identity, not content).
            if (std::strcmp(spelleffects::statusName(
                    spelleffects::STATUS_WATERBREATHING),
                    "Breathing") != 0) ++bad;
        }
        printf("R320 breathing aids audit: bad %d\n", bad);
        if (bad) return 1;
    }
