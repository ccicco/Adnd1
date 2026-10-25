    // ---- R588 Acheron audit ----
    // ACHERON, printed pp. 113-114, the iron-shod battle plains, the most
    // lawful of the evil planes, bridging the Hells and Nirvana's clockwork:
    // home of those who inflict evil secondarily, order their chief aim -
    // many armies, few leaders, initiative drifting away to more definite
    // alignments. The four layers of huge blocks, nation-sized, drifting
    // together and parting without tremors, gravity to each block's center,
    // the between as air. Avalas the Battleplains: the black metal-hard
    // ground reverberating to thousands of troops, cone mountains, pits, iron
    // citadels, and the Styx rising from one pit to vanish into another,
    // Charon riding the blocks it touches. Thuldanin the scrap heap: hollow
    // pockmarked blocks stuffed with ships burst asunder, toppled buildings
    // and flying devices, all turned to stone by the plane's magics, a day's
    // search 0.1% likely to yield anything useful (and the DM decides if it
    // even works home), the monthly crushing-blow saves turning left items to
    // rock, no natives, only the victory-seeking visitors. Tintibulus: the
    // solid grey volcanic blocks in regular shapes, fault-fracturing into
    // huge hexagons, lifeless and attractive to magical researchers.
    // Ocanthus: no blocks, only razor-thin black squares few inches to miles
    // across flying like geese through the snow-white sky, walkable both
    // faces, the edge-on strike 1d10 dice hitting as a 1d10-hit-die monster
    // with no magical-armor benefit. The spherical portals hanging fixed
    // while blocks orbit - touched to activate, the chord to Nirvana, the
    // discord to Avernus, the silence to Concordant Opposition - the arrival
    // draw toward the nearest block and its 20d6 for the flightless, the
    // spheres passing through blocks freely and quiet within them; the
    // barriers unmoored in space, the lower reaches hard to reach, but the
    // careful order of the spinning discoverable by an Intelligence check of
    // the 18-plus, one per visit. The features: a wasteland of immigrant
    // imps, achaiarai, rust monsters, occasional modrons and devils - and the
    // spirit legions, nations of the lawful-evil dead who lost sight of their
    // war's objectives, humans, dwarves, halflings, kender, ogres, leaderless
    // and milieu-tacticed, conquering block after block, the slain returning
    // to full strength within 24 hours, the eternal soldier without respite.
    // The Powers: Lei Kung the Duke of Thunder alone on his cloud-island
    // temple, striking the guilty for Shang-Ti of Nirvana, servantless; and
    // the great contested block of Maglubiyet and Gruumsh - goblin and
    // hobgoblin legions clashing daily with the orcish, citadel sieges
    // perpetual, the wandering orcish pantheon seeking an Asgard of their
    // own, the orbiting holdings of Luthic, Bahgtru and Ilneval matching the
    // goblin pantheon's aid, both sides waiting to hold the layer as the
    // elves hold Arvandor, neither moving nor sharing the dull block - the
    // everlasting war most deities cite as the folly of violence for its own
    // end.
    {
        using namespace rules;
        int bad = 0;
    if (ddrAcheronLayerCount() != 4
            || ddrThuldaninSearchChance() != 1000
            || ddrOcanthusEdgeDice() != 10
            || ddrPortalFallDice() != 20
            || !ddrAcheronDoctrine()
            || !ddrAvalasRule()
            || !ddrTintibulusRule()
            || !ddrAcheronPortals()
            || !ddrSpiritLegionRule()
            || !ddrAcheronPowers()
        )
            ++bad;
        // the AcheronLayerCount pin
    if (ddrAcheronLayerCount() != 4
        )
            ++bad;
        // the ThuldaninSearchChance pin
    if (ddrThuldaninSearchChance() != 1000
        )
            ++bad;
        // the OcanthusEdgeDice pin
    if (ddrOcanthusEdgeDice() != 10
        )
            ++bad;
        // the PortalFallDice pin
    if (ddrPortalFallDice() != 20
        )
            ++bad;
        // the AcheronDoctrine pin
    if (ddrAcheronDoctrine() != 1
        )
            ++bad;
        // the AvalasRule pin
    if (ddrAvalasRule() != 1
        )
            ++bad;
        // the TintibulusRule pin
    if (ddrTintibulusRule() != 1
        )
            ++bad;
        // the AcheronPortals pin
    if (ddrAcheronPortals() != 1
        )
            ++bad;
        // the SpiritLegionRule pin
    if (ddrSpiritLegionRule() != 1
        )
            ++bad;
        // the AcheronPowers pin
    if (ddrAcheronPowers() != 1
        )
            ++bad;
        printf("R588 Acheron audit: bad %d\n", bad);
        if (bad) return 1;
    }
