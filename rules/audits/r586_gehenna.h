    // ---- R586 Gehenna audit ----
    // GEHENNA, printed pp. 107-109, the fourfold furnaces: smoky, burning
    // realms where the ground gives both light (like Tarterus's orbs) and
    // heat, hot enough to set unprotected flammables aflame. The mountains
    // have neither bases nor peaks - all is built onto or carved into their
    // sides, the gravity at 45 degrees to the ground so that a lost footing
    // means miles of tumbling, a strike against a wall wounding as a fall
    // from the height of the distance tumbled, and the terrain slippery to
    // slightly slippery throughout. The heat rises from the ground itself -
    // vents, fumaroles, mud pots, flank-running lava, eruptions and
    // earthquakes - dealing 1d8 per turn to the unprotected, negated by the
    // means that master elemental Fire. The layers: Khalas the temperate top,
    // its steam-swathed waterfalls crowned by the Styx's cascades falling
    // thousands of feet into the underground passages, devils of the Hells
    // hiding in its crags; Chamada the violent second, lava cascades
    // thousands of miles wide, volcano throats wide enough to swallow cities,
    // and within 10 miles of the surface an acrid cloud that blinds
    // unprotected eyes and chokes as a permanent stinking cloud - the
    // burning-hair smell reaching even the clear depths below; Mungoth the
    // cold third, ash and burning snow, wet-snow-and-burning-rock avalanches
    // its greatest danger; and Krangath the dead furnaces, completely dark,
    // without heat or light even underground. The ways in: the Styx through
    // Khalas, the Astral's color pools, the adjacent Hells, Hades and
    // Concordant Opposition - the interplanar portals always deep beneath the
    // surface as black chasms in the floor, marked by whoever cares; the
    // barriers beneath the furnaces in dead-end corridors, sages' pyramid
    // supposition, and the 5% chance a deeper barrier opens into a volcanic
    // region or a sealed cavern. The features: the plane of exile overrun by
    // nightmares, imps, manes, daemons, mephits, lesser devils and achalera
    // hiding from their betters, the disfavored arch-devils and daemon
    // masters; the barghests, the only true natives, swarming the upper
    // rifts, solitary enslavers of petty baronies whose continual wars send
    // their young to be raised on the Prime; and the sparse Powers -
    // Chih-Chiang Fyu-Ya's teardrop citadel with the giant-skull bell that
    // tolls across the slopes when judgment is called, Loviatar's
    // spell-warded ice fortress of cruelty and abuse on Mungoth, and Shargaas
    // the Night Lord of the deep Night Land, seeing in the dark of the
    // caverns beneath, the only one who might know whether Gehenna goes
    // deeper.
    {
        using namespace rules;
        int bad = 0;
    if (ddoGehennaLayerCount() != 4
            || ddoGravityDegrees() != 45
            || ddoHeatDamage() != 8
            || ddoChamadaCloudMiles() != 10
            || ddoBarrierHazardPct() != 5
            || !ddoGehennaDoctrine()
            || !ddoKhalasRule()
            || !ddoMungothKrangathRule()
            || !ddoGehennaPortals()
            || !ddoBarghestRule()
            || !ddoGehennaPowers()
        )
            ++bad;
        // the GehennaLayerCount pin
    if (ddoGehennaLayerCount() != 4
        )
            ++bad;
        // the GravityDegrees pin
    if (ddoGravityDegrees() != 45
        )
            ++bad;
        // the HeatDamage pin
    if (ddoHeatDamage() != 8
        )
            ++bad;
        // the ChamadaCloudMiles pin
    if (ddoChamadaCloudMiles() != 10
        )
            ++bad;
        // the BarrierHazardPct pin
    if (ddoBarrierHazardPct() != 5
        )
            ++bad;
        // the GehennaDoctrine pin
    if (ddoGehennaDoctrine() != 1
        )
            ++bad;
        // the KhalasRule pin
    if (ddoKhalasRule() != 1
        )
            ++bad;
        // the MungothKrangathRule pin
    if (ddoMungothKrangathRule() != 1
        )
            ++bad;
        // the GehennaPortals pin
    if (ddoGehennaPortals() != 1
        )
            ++bad;
        // the BarghestRule pin
    if (ddoBarghestRule() != 1
        )
            ++bad;
        // the GehennaPowers pin
    if (ddoGehennaPowers() != 1
        )
            ++bad;
        printf("R586 Gehenna audit: bad %d\n", bad);
        if (bad) return 1;
    }
