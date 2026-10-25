    // ---- R130: high-level slots audit ----
    // PHB class-table pins: corrected low rows, printed
    // high rows, the holds past the print, and the gates.
    // Line-diff source: the 1eonline.info PHB compilation.
    // R130b: namespaced spells:: calls (the first R130
    // paste ran bare names - caught by the user's build).
    {
        int bad = 0;
        // the corrected R80 rows (levels 7-12)
        if (spells::spellSlots(spells::SPELL_MU, 7, 1) != 4) ++bad;
        if (spells::spellSlots(spells::SPELL_MU, 8, 2) != 3) ++bad;
        if (spells::spellSlots(spells::SPELL_MU, 9, 5) != 1) ++bad;
        if (spells::spellSlots(spells::SPELL_MU, 10, 4) != 3) ++bad;
        if (spells::spellSlots(spells::SPELL_MU, 11, 5) != 3) ++bad;
        if (spells::spellSlots(spells::SPELL_MU, 12, 5) != 4) ++bad;
        // R130c: the L12 print gives ONE 6th-level slot
        // (L12 = 4,4,4,4,4,1) - the r130b pin read the
        // 5th column twice
        if (spells::spellSlots(spells::SPELL_MU, 12, 6) != 1) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 6, 3) != 2) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 7, 4) != 1) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 8, 4) != 2) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 9, 5) != 1) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 10, 5) != 2) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 11, 1) != 5) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 12, 1) != 6) ++bad;
        // the printed high rows (13-20)
        if (spells::spellSlots(spells::SPELL_MU, 13, 6) != 2) ++bad;
        if (spells::spellSlots(spells::SPELL_MU, 17, 7) != 2) ++bad;
        if (spells::spellSlots(spells::SPELL_MU, 18, 9) != 1) ++bad;
        if (spells::spellSlots(spells::SPELL_MU, 20, 9) != 2) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 13, 5) != 2) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 16, 7) != 1) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 17, 7) != 1) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 20, 7) != 2) ++bad;
        // the holds past the print (L29 = the final row)
        if (spells::spellSlots(spells::SPELL_MU, 29, 9) != 2) ++bad;
        if (spells::spellSlots(spells::SPELL_CLERIC, 29, 7) != 7) ++bad;
        // the gates: cleric 7th at 17; INT 17 -> 7, 18 -> 9
        if (spells::maxSpellLevelForClericLevel(16) != 6) ++bad;
        if (spells::maxSpellLevelForClericLevel(17) != 7) ++bad;
        if (spells::maxSpellLevelForClericLevel(29) != 7) ++bad;
        if (spells::maxSpellLevelForInt(15) != 5) ++bad;
        if (spells::maxSpellLevelForInt(16) != 6) ++bad;
        if (spells::maxSpellLevelForInt(17) != 7) ++bad;
        if (spells::maxSpellLevelForInt(18) != 9) ++bad;
        printf("R130 high-level slots audit: bad %d\n", bad);
        if (bad) return 1;
    }
