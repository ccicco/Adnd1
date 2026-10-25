    // ---- R582 Limbo-Pandemonium audit ----
    // LIMBO AND PANDEMONIUM, printed pp. 97-101, the first two Chaos planes
    // in one round: Limbo, chaos supreme at Nirvana's antipode (the
    // quicksilver mish-mash of primal forces, the contact-only gravity, the
    // random-entry table - safe pocket through the sentient's area, the
    // drowning liquid at 10% magma, the collapsing pocket, the suffocation,
    // the 1d10-d6 fire and 1d6-d8 cold sources - the safe-zone radius ladder
    // by Intelligence at 10 feet/10 yards/100 yards/1 mile per point with
    // companion increments, the concentration rule with no spellcasting while
    // holding, the emotion-collapse onto the entry table, the 1d10-hour
    // semi-permanent created matter, the five weakly-barriered layers Gith
    // and Slaad through the Lost Gods, the 33% three-way portals, the slaadi
    // with Ssendam's golden castle and Ygort's whirling spheres, the
    // githzerai with the Citadel of Gith and the 16/23 wizard-king Zaarith,
    // the cord-severing maroon tactic, the chaos elementals at 6d6, and the
    // floating realms - Indra's milk-vault Swarga, Agni's roaming flame,
    // Susanowo's salt-water sphere, Huan-Ti's unconsuming bamboo palace with
    // the 3d6-per-gallon steam); and Pandemonium, chaos tinged by evil, the
    // underground opposite of Gladsheim (the wind-carved tunnels with
    // center-outward gravity, the 10-foot noise rule with the deafness
    // ladder, the wind that lifts 100 lbs for 1d6 miles at 4d6 damage, the
    // four layers - Pandeemos, the shrill tool-carved Cocytus with its
    // 10d10-turn insanity, the light-halved Phlegethon, and bubble-deep
    // Agathion with its 400-lb storms and 50/50 stale-or-vacuum prisons - the
    // flat-square portals at 20% misroute, the immigrant life, and the Powers
    // - Loki's white-crystal Hidden Realm with its Jotenheim shortcut,
    // Tuonela ringed by the desire-draining Manala, retired Anshar's
    // dead-tongued city, and Hruggek's bugbear fortress).
    {
        using namespace rules;
        int bad = 0;
    if (ddkLimboLayerCount() != 5
            || ddkEntrySafePct() != 20
            || ddkSafeZoneYardsPerInt() != 100
            || ddkChaosMatterHours() != 10
            || ddkPandemoniumShoutFeet() != 10
            || ddkWindLiftPounds() != 100
            || !ddkLimboDoctrine()
            || !ddkLimboPortals()
            || !ddkSlaadRule()
            || !ddkGithzeraiRule()
            || !ddkChaosElementalRule()
            || !ddkLimboPowers()
            || !ddkPandemoniumStructure()
            || !ddkPandemoniumPortals()
            || !ddkPandemoniumPowers()
        )
            ++bad;
        // the LimboLayerCount pin
    if (ddkLimboLayerCount() != 5
        )
            ++bad;
        // the EntrySafePct pin
    if (ddkEntrySafePct() != 20
        )
            ++bad;
        // the SafeZoneYardsPerInt pin
    if (ddkSafeZoneYardsPerInt() != 100
        )
            ++bad;
        // the ChaosMatterHours pin
    if (ddkChaosMatterHours() != 10
        )
            ++bad;
        // the PandemoniumShoutFeet pin
    if (ddkPandemoniumShoutFeet() != 10
        )
            ++bad;
        // the WindLiftPounds pin
    if (ddkWindLiftPounds() != 100
        )
            ++bad;
        // the LimboDoctrine pin
    if (ddkLimboDoctrine() != 1
        )
            ++bad;
        // the LimboPortals pin
    if (ddkLimboPortals() != 1
        )
            ++bad;
        // the SlaadRule pin
    if (ddkSlaadRule() != 1
        )
            ++bad;
        // the GithzeraiRule pin
    if (ddkGithzeraiRule() != 1
        )
            ++bad;
        // the ChaosElementalRule pin
    if (ddkChaosElementalRule() != 1
        )
            ++bad;
        // the LimboPowers pin
    if (ddkLimboPowers() != 1
        )
            ++bad;
        // the PandemoniumStructure pin
    if (ddkPandemoniumStructure() != 1
        )
            ++bad;
        // the PandemoniumPortals pin
    if (ddkPandemoniumPortals() != 1
        )
            ++bad;
        // the PandemoniumPowers pin
    if (ddkPandemoniumPowers() != 1
        )
            ++bad;
        printf("R582 Limbo-Pandemonium audit: bad %d\n", bad);
        if (bad) return 1;
    }
