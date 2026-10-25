    // ---- R197: the mental-form flag audit ----
    // The printed Wisdom Table I note: the magical defense
    // adjustment rides only will-force forms. The registry
    // holds two: charm person (charming) and charm monster
    // (mass charming). The holds are not will-force forms.
    {
        int bad = 0;
        // the flagged rows
        if (!spells::spellIsMentalForm(spells::MU_CHARM_PERSON))
            ++bad;
        if (!spells::spellIsMentalForm(spells::MU_CHARM_MONSTER))
            ++bad;
        // the unflagged rows: holds are not will-force forms,
        // and the physical/utility spells are not either
        if (spells::spellIsMentalForm(spells::MU_HOLD_MONSTER)) ++bad;
        if (spells::spellIsMentalForm(spells::CL_HOLD_PERSON)) ++bad;
        if (spells::spellIsMentalForm(spells::MU_SLEEP)) ++bad;
        if (spells::spellIsMentalForm(spells::MU_FIREBALL)) ++bad;
        if (spells::spellIsMentalForm(spells::MU_MAGIC_MISSILE)) ++bad;
        if (spells::spellIsMentalForm(spells::MU_POLYMORPH_OTHER))
            ++bad;
        if (spells::spellIsMentalForm(spells::CL_SILENCE_15)) ++bad;
        // the assembly: the ladder on mental forms
        if (spells::spellSaveModWis(spells::MU_CHARM_PERSON, 18) != 4)
            ++bad;
        if (spells::spellSaveModWis(spells::MU_CHARM_PERSON, 3) != -3)
            ++bad;
        if (spells::spellSaveModWis(spells::MU_CHARM_PERSON, 10) != 0)
            ++bad;
        if (spells::spellSaveModWis(spells::MU_CHARM_MONSTER, 17) != 3)
            ++bad;
        // and 0 off them, whatever the wisdom
        if (spells::spellSaveModWis(spells::MU_FIREBALL, 3) != 0)
            ++bad;
        if (spells::spellSaveModWis(spells::MU_MAGIC_MISSILE, 18) != 0)
            ++bad;
        // the ladder handoff: the helper IS wisMagicalAttackAdj
        for (int w = 3; w <= 18; ++w) {
            if (spells::spellSaveModWis(
                    spells::MU_CHARM_PERSON, (uint8_t)w)
                != rules::wisMagicalAttackAdj((uint8_t)w)) ++bad;
        }
        printf("R197 mental-form flag audit: bad %d\n", bad);
        if (bad) return 1;
    }
