    // ---- R83: teleport + L4-6 casting gates audit ----
    {
        int bad = 0;
        // the Teleport registry row (values from kSpells)
        const spells::SpellDef& tp =
            spells::spell(spells::MU_TELEPORT);
        if (std::string(tp.name) != "Teleport") ++bad;
        if (tp.sclass != spells::SPELL_MU) ++bad;
        if (tp.level != 5) ++bad;
        if (tp.castingTime < 1) ++bad;
        if (tp.saveCategory != -1) ++bad;
        if (tp.target != spells::TARGET_SPECIAL) ++bad;
        if (tp.reversible) ++bad;
        // L5 MU slots start at class level 9 (kMuSlots row 9)
        if (spells::spellSlots(spells::SPELL_MU, 9, 5) != 1) ++bad;
        if (spells::spellSlots(spells::SPELL_MU, 8, 5) != 0) ++bad;
        // INT gates the L5 (PHB p.10): 15 reaches L5, 16 reaches L6
        if (spells::maxSpellLevelForInt(15) != 5) ++bad;
        if (spells::maxSpellLevelForInt(16) != 6) ++bad;
        // every registry row sits in 1..9 (the R83 gate
        // domain, widened R129 alongside the R80 band: the
        // six p.14 caster-aging spells ride as levels 7-9)
        for (int id = 0; id < spells::SPELL_COUNT; ++id) {
            const spells::SpellDef& s2 =
                spells::spell((spells::SpellId)id);
            if (s2.level < 1 || s2.level > 9) ++bad;
        }
        printf("R83 teleport audit: bad %d\n", bad);
        if (bad) return 1;
    }
