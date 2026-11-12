    // ---- R908 Prowler opener audit ----
    // THE DRAGON ISSUE-7 OPENER ROUND - the thin single-chain harvest. The
    // Prowler (folio 24): the stat pin - 14 hit dice, armor class 1, move 12,
    // number appearing 1, the constriction 4-48 and bite 1-8 attacks, the 50
    // percent magic resistance; the lifecycle pin - the mind-blank gaze with
    // its save vs. magic and zombei control, the 1-8 tentacle egg-injection,
    // the 2-8 day hatch, the hatched brood's first meal, the exceptional
    // hatcheries and the three-Patriarch dispel evil restoration; and the DMG
    // p.85 XP conversion at the 13 to 14+ dice category, the
    // special/exceptional count a noted judgment.
    {
        using namespace rules;
        int bad = 0;
    if (pwlHd() != 14
            || pwlMove() != 12
            || pwlAc() != 1
            || pwlNumAppearing() != 1
            || pwlConstrictMin() != 4
            || pwlConstrictMax() != 48
            || pwlBiteMin() != 1
            || pwlBiteMax() != 8
            || pwlMagicResistPct() != 50
            || pwlEggDamageMin() != 1
            || pwlEggDamageMax() != 8
            || pwlHatchDaysMin() != 2
            || pwlHatchDaysMax() != 8
            || pwlRestorePatriarchs() != 3
            || pwlAvgHp() != 63
            || pwlXp() != 5850
            || pwlXpPerHp() != 18
            || pwlXpValue() != 6984
            || !pwlEvil()
            || !pwlGazeSaveVsMagic()
            || !pwlZombeiUnderControl()
            || !pwlConstrictOnSave()
            || !pwlEggsViaTentacles()
            || !pwlHatchedFirstMeal()
            || !pwlExceptionalFormHatcheries()
        )
            ++bad;
        // the Prowler stat line - 14 hit dice, move 12, armor class 1, number
        // appearing 1 (folio 24)
    if (pwlHd() != 14
            || pwlMove() != 12
            || pwlAc() != 1
            || pwlNumAppearing() != 1
        )
            ++bad;
        // the Prowler attacks - constriction 4-48 hit points per turn, bite
        // 1-8, 50 percent magic resistant (folio 24)
    if (pwlConstrictMin() != 4
            || pwlConstrictMax() != 48
            || pwlBiteMin() != 1
            || pwlBiteMax() != 8
            || pwlMagicResistPct() != 50
        )
            ++bad;
        // the Prowler lifecycle - the 1-8 injection damage, the 2-8 day
        // hatch, the three Patriarchs' simultaneous dispel evil (folio 24)
    if (pwlEggDamageMin() != 1
            || pwlEggDamageMax() != 8
            || pwlHatchDaysMin() != 2
            || pwlHatchDaysMax() != 8
            || pwlRestorePatriarchs() != 3
        )
            ++bad;
        // the Prowler XP conversion - the DMG p.85 additive formula: 1800
        // base + 3 x 950 specials + 1200 exceptional, plus 18 per hit point
        // at the 63 average; the conversion noted, never silent (folio 24)
    if (pwlAvgHp() != 63
            || pwlXp() != 5850
            || pwlXpPerHp() != 18
            || pwlXpValue() != 6984
        )
            ++bad;
        // the Prowler doctrines - the gaze save vs. magic, the zombei
        // control, the constriction on a save, the tentacle eggs, the hatched
        // first meal, the exceptional hatcheries (folio 24)
    if (pwlEvil() != 1
            || pwlGazeSaveVsMagic() != 1
            || pwlZombeiUnderControl() != 1
            || pwlConstrictOnSave() != 1
            || pwlEggsViaTentacles() != 1
            || pwlHatchedFirstMeal() != 1
            || pwlExceptionalFormHatcheries() != 1
        )
            ++bad;
        printf("R908 Prowler opener audit: bad %d\n", bad);
        if (bad) return 1;
    }
