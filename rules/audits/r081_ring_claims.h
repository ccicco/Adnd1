    // ---- R81: ring claims, scroll picks, status helpers --------
    {
        int bad = 0;
        Character c;
        c.hp = 10;
        // a member takes the ring
        if (!claimRing(c, "Ring of Protection", 1)) ++bad;
        if (c.ringPlus != 1) ++bad;
        // one ring per member
        if (claimRing(c, "Ring of Protection", 1)) ++bad;
        c.ringPlus = 0;
        // other rings never claim
        if (claimRing(c, "Ring of Fire Resistance", 1)) ++bad;
        // bundles never claim
        if (claimRing(c, "Ring of Protection", 2)) ++bad;
        // the dead claim nothing
        c.hp = 0;
        if (claimRing(c, "Ring of Protection", 1)) ++bad;
        c.hp = 10;
        // scroll-study pick: the lowest-level unknown MU spell,
        // deterministic id order
        c.classIndex = 1;
        c.knownSpells.clear();
        int sid = pickStudySpell(c);
        if (sid < 0) ++bad;
        const spells::SpellDef& s0 =
            spells::spell((spells::SpellId)sid);
        if (s0.sclass != spells::SPELL_MU || s0.level != 1) ++bad;
        c.knownSpells.push_back(sid);
        int sid2 = pickStudySpell(c);
        if (sid2 == sid) ++bad;   // moves on to the next unknown
        // a complete book yields -1
        for (int id = 0; id < spells::SPELL_COUNT; ++id)
            if (spells::spell((spells::SpellId)id).sclass ==
                spells::SPELL_MU)
                c.knownSpells.push_back(id);
        if (pickStudySpell(c) != -1) ++bad;
        // fire shield reflect math: half, rounded up, min 1
        if (spelleffects::fireShieldDamage(1) != 1) ++bad;
        if (spelleffects::fireShieldDamage(5) != 3) ++bad;
        if (spelleffects::fireShieldDamage(8) != 4) ++bad;
        printf("R81 rings/scrolls/status audit: bad %d\n", bad);
        if (bad) return 1;
    }
