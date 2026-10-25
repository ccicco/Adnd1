    // ---- R319: the underwater vision
    // multiples audit ----
    // The R311 vision paragraph closes: the
    // depth seam re-folds the water sight
    // (the decay pin, fresh), a party light
    // spell lifts the water sight
    // (resolveCast - the rows save not) and
    // the claimed Helm of Underwater Action
    // quintuples the pool sight (the claim
    // layer, the carried-item seam).
    // Continual light stays recorded (a
    // permanent mark dies at the round-end
    // tick - the R318b lesson). Draw-
    // independent: the light rows save not,
    // the folds read the pins.
    {
        int bad = 0;
        // W1: the light status - the spell
        // engine level (no save on the row)
        {
            rules::Rng r(7);
            rules::Dice d(r);
            ai::Actor t;
            t.team = 1; t.hitDice = 1;
            t.hp = 6; t.maxHp = 6;
            std::vector<spelleffects::TargetDesc>
                ds;
            ds.push_back(t.asTarget());
            spelleffects::SpellCastResult r1 =
                spelleffects::resolveSpell(
                    d, spells::MU_LIGHT, 1, ds);
            if (r1.perTarget.size() != 1) ++bad;
            if (!r1.perTarget.empty() &&
                r1.perTarget[0].status.kind !=
                    spelleffects::STATUS_LIGHT)
                ++bad;
        }
        // W2: the light fold - a party cast in
        // the water fight lifts the sight
        {
            std::vector<ai::Actor> pt;
            ai::Actor a;
            a.isCharacter = true;
            a.team = 0;
            a.name = "Heroa";
            a.classIndex = 1; a.level = 1;
            a.slotsByLevel[0] = 1;
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
            enc.setVisionFt(
                rules::uwVisionBaseFt(0));
            enc.resolveCast(
                enc.partyMutable()[0],
                spells::MU_LIGHT);
            if (enc.visionFt() !=
                rules::uwLightSpellVisionFt(
                    rules::uwVisionBaseFt(0)))
                ++bad;
            bool lit = false;
            for (const auto& ln : enc.log())
                if (ln.text.find("The light carries") !=
                    std::string::npos)
                    lit = true;
            if (!lit) ++bad;
            // the slot spent
            if (enc.partyMutable()[0]
                    .slotsByLevel[0] != 0) ++bad;
        }
        // W3: the dry gate - no water fight,
        // no sight state, no fold
        {
            std::vector<ai::Actor> pt;
            ai::Actor a;
            a.isCharacter = true;
            a.team = 0;
            a.name = "Heroa";
            a.classIndex = 1; a.level = 1;
            a.slotsByLevel[0] = 1;
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
                spells::MU_LIGHT);
            if (enc.visionFt() != 0) ++bad;
            bool lit = false;
            for (const auto& ln : enc.log())
                if (ln.text.find("The light carries") !=
                    std::string::npos)
                    lit = true;
            if (lit) ++bad;
        }
        // W4: the depth seam - the decay pin
        {
            std::vector<ai::Actor> pt;
            ai::Actor a;
            a.isCharacter = true;
            a.team = 0;
            a.name = "Heroa";
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
            enc.setVisionFt(
                rules::uwVisionBaseFt(0));
            enc.setDepthFt(30);
            if (enc.visionFt() !=
                rules::uwVisionDecayFt(0, 30))
                ++bad;
            enc.setDepthFt(70);
            if (enc.visionFt() != 0) ++bad;
            if (enc.depthFt() != 70) ++bad;
        }
        // W5: the dry depth - the R316 zero
        {
            std::vector<ai::Actor> pt;
            ai::Actor a;
            a.isCharacter = true;
            a.team = 0;
            a.name = "Heroa";
            a.hp = 30; a.maxHp = 30;
            pt.push_back(a);
            std::vector<ai::Actor> mons;
            ai::Actor m;
            m.team = 1; m.hitDice = 1;
            m.name = "Monst";
            m.hp = 6; m.maxHp = 6;
            mons.push_back(m);
            ai::Encounter enc(pt, mons, 20);
            enc.setDepthFt(30);
            if (enc.visionFt() != 0) ++bad;
        }
        // W6: the helm claim (the claimRing
        // pattern)
        {
            Character c;
            c.hp = 10;
            if (!claimUwHelm(
                    c, "Helm of Underwater Action",
                    1)) ++bad;
            if (!c.uwHelm) ++bad;
            // one helm per member
            if (claimUwHelm(
                    c, "Helm of Underwater Action",
                    1)) ++bad;
            c.uwHelm = false;
            // other misc never claims
            if (claimUwHelm(c, "Helm of Brilliance",
                            1)) ++bad;
            // bundles never claim
            if (claimUwHelm(
                    c, "Helm of Underwater Action",
                    2)) ++bad;
            // the dead claim nothing
            c.hp = 0;
            if (claimUwHelm(
                    c, "Helm of Underwater Action",
                    1)) ++bad;
        }
        // W7: the helm fold - the pool sight
        // quintuples (the beginCombat site)
        {
            AppState st;
            st.mode = MODE_EXPLORE;
            st.party.formed = true;
            Character arc;
            arc.name = "Arc";
            arc.classIndex = 0; arc.level = 1;
            arc.race = 0;
            arc.hp = 30; arc.maxHp = 30;
            arc.uwHelm = true;
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
                st.combat.encounter->visionFt() !=
                    rules::uwVisionBaseFt(0) *
                        rules::uwHelmVisionMultiple())
                ++bad;
            bool h = false;
            for (int i = 0; i < 4; ++i)
                if (st.log.get(i).find("Sight runs 250 feet") !=
                    std::string::npos)
                    h = true;
            if (!h) ++bad;
        }
        printf("R319 underwater vision multiples audit: bad %d\n", bad);
        if (bad) return 1;
    }
