    // ---- R129: caster aging audit ----
    {
        int bad = 0;
        // the registry grew to 192 (R229): MU 31, CL 23,
        // DR 77, IL 61
        if (spells::SPELL_COUNT != 192) ++bad;
        {
            int mu = 0, cl = 0, dr = 0, il = 0;
            for (int id = 0; id < spells::SPELL_COUNT; ++id) {
                const spells::SpellDef& s =
                    spells::spell((spells::SpellId)id);
                if (s.sclass == spells::SPELL_MU) ++mu;
                else if (s.sclass == spells::SPELL_DRUID) ++dr;
                else if (s.sclass == spells::SPELL_ILLUSIONIST) ++il;
                else ++cl;
            }
            if (mu != 31 || cl != 23 || dr != 77 ||
                il != 61) ++bad;
        }
        // the six p.14 rows: name, class, level, self-target
        {
            const spells::SpellDef& d =
                spells::spell(spells::MU_LIMITED_WISH);
            if (std::string(d.name) != "Limited Wish" ||
                d.sclass != spells::SPELL_MU || d.level != 7 ||
                d.target != spells::TARGET_SELF) ++bad;
        }
        {
            const spells::SpellDef& d =
                spells::spell(spells::MU_ALTER_REALITY);
            if (std::string(d.name) != "Alter Reality" ||
                d.sclass != spells::SPELL_MU || d.level != 7 ||
                d.target != spells::TARGET_SELF) ++bad;
        }
        {
            const spells::SpellDef& d =
                spells::spell(spells::MU_WISH);
            if (std::string(d.name) != "Wish" ||
                d.sclass != spells::SPELL_MU || d.level != 9 ||
                d.target != spells::TARGET_SELF) ++bad;
        }
        {
            const spells::SpellDef& d =
                spells::spell(spells::MU_GATE);
            if (std::string(d.name) != "Gate" ||
                d.sclass != spells::SPELL_MU || d.level != 9 ||
                d.target != spells::TARGET_SELF) ++bad;
        }
        {
            const spells::SpellDef& d =
                spells::spell(spells::CL_RESTORATION);
            if (std::string(d.name) != "Restoration" ||
                d.sclass != spells::SPELL_CLERIC ||
                d.level != 7 ||
                d.target != spells::TARGET_SELF) ++bad;
        }
        {
            const spells::SpellDef& d =
                spells::spell(spells::CL_RESURRECTION);
            if (std::string(d.name) != "Resurrection" ||
                d.sclass != spells::SPELL_CLERIC ||
                d.level != 7 ||
                d.target != spells::TARGET_SELF) ++bad;
        }
        // the DMG p.14 pins: the caster-aged causes
        if (spells::magicalAgingYears(
                spells::MU_LIMITED_WISH) != 1) ++bad;
        if (spells::magicalAgingYears(
                spells::CL_RESTORATION) != 2) ++bad;
        if (spells::magicalAgingYears(
                spells::MU_ALTER_REALITY) != 3) ++bad;
        if (spells::magicalAgingYears(
                spells::MU_WISH) != 3) ++bad;
        if (spells::magicalAgingYears(
                spells::CL_RESURRECTION) != 3) ++bad;
        if (spells::magicalAgingYears(
                spells::MU_GATE) != 5) ++bad;
        // the R115 precedent stands
        if (spells::magicalAgingYears(
                spells::MU_HASTE) != 1) ++bad;
        if (spells::magicalAgingYears(
                spells::MU_FIREBALL) != 0) ++bad;
        // R130: the printed tables now encode 1-9; these
        // 12th-level pins still hold (no 7th-9th at 12)
        if (spells::spellSlots(
                spells::SPELL_MU, 12, 7) != 0) ++bad;
        if (spells::spellSlots(
                spells::SPELL_MU, 12, 9) != 0) ++bad;
        if (spells::spellSlots(
                spells::SPELL_CLERIC, 12, 7) != 0) ++bad;
        printf("R129 caster aging audit: bad %d\n", bad);
        if (bad) return 1;
    }
