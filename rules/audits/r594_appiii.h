    // ---- R594 AppIII audit ----
    // APPENDIX III: CREATURES FROM THE OUTER PLANES, printed pp. 122-123, the
    // new-creature summary - by no means exhaustive, but the DM's starting
    // point: the einheriar, the spirit legions of the neutral-to-good planes,
    // 10d10 to the patrol, immune to fear, slain and returned within the day,
    // the class die (fighters 1-40 through bards 99-00) and the level die
    // (level 4 at 1-50 through levels 11-16 at 00), the 5%-per-level magical
    // kit with no exceptional-function items, and the seven hosts - Anu's
    // soldiers, the shape-changing Horusyr, Clanggedin's dwarvish host, the
    // spirit folk of Arcadia and Elysium, the Hindari, Valhalla's einheriar,
    // and Acheron's spirit legions; the maruts of Rudra, the
    // polished-black-stone giants of Nirvana in gold armor, 15 HD with the
    // 8d10 blow and the once-an-hour earthquake, 15-die lightning bolt or
    // controlled winds; the mortal of the Happy Hunting Grounds, a huge cloud
    // with a face at AC -5 and move 48, godlike, the legend lore at will and
    // all air, wind, weather and cloud spells including cloudkill, glowing
    // golden in Arcadia's depths; and the archons, the armies of good and Law
    // with the four common powers (continual light, the visions, tongues, the
    // errorless teleport): the lantern proto-archons, 1d3-foot glowing
    // bubbles of half a hit die reforming within the day of their slaying;
    // the hounds, the dog-headed 9-HD fighters shape changing to wolf and
    // seeing the invisible, astral and ethereal; the bear-handed wardens of
    // all divination; the winged cat-headed swords, 15th-level casters gating
    // reinforcements each turn, four attacks from the one weapon; and the
    // hawk-headed tomes, the 8-foot geniuses of divination, alteration and
    // beneficial necromancy, the 2d10 radiant cone, the 20th-level cleric's
    // grip on the undead.
    {
        using namespace rules;
        int bad = 0;
    if (ddzEinheriarPatrolDice() != 10
            || ddzEinheriarMagicPctPerLevel() != 5
            || ddzMarutHourlyPowers() != 1
            || ddzArchonCommonPowers() != 4
            || ddzLanternReformDay() != 1
            || ddzSwordGateTurn() != 6
            || !ddzEinheriarTables()
            || !ddzEinheriarHosts()
            || !ddzMortalRule()
            || !ddzHoundWardenRule()
            || !ddzTomeRule()
        )
            ++bad;
        // the EinheriarPatrolDice pin
    if (ddzEinheriarPatrolDice() != 10
        )
            ++bad;
        // the EinheriarMagicPctPerLevel pin
    if (ddzEinheriarMagicPctPerLevel() != 5
        )
            ++bad;
        // the MarutHourlyPowers pin
    if (ddzMarutHourlyPowers() != 1
        )
            ++bad;
        // the ArchonCommonPowers pin
    if (ddzArchonCommonPowers() != 4
        )
            ++bad;
        // the LanternReformDay pin
    if (ddzLanternReformDay() != 1
        )
            ++bad;
        // the SwordGateTurn pin
    if (ddzSwordGateTurn() != 6
        )
            ++bad;
        // the EinheriarTables pin
    if (ddzEinheriarTables() != 1
        )
            ++bad;
        // the EinheriarHosts pin
    if (ddzEinheriarHosts() != 1
        )
            ++bad;
        // the MortalRule pin
    if (ddzMortalRule() != 1
        )
            ++bad;
        // the HoundWardenRule pin
    if (ddzHoundWardenRule() != 1
        )
            ++bad;
        // the TomeRule pin
    if (ddzTomeRule() != 1
        )
            ++bad;
        printf("R594 AppIII audit: bad %d\n", bad);
        if (bad) return 1;
    }
