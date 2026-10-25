    // ---- R583 Abyss audit ----
    // THE ABYSS, printed pp. 101-103, the deepest evil: 666 estimated layers
    // (the most layers and potentially the most inhabitants of any outer
    // plane, each Power claiming at least one, the count standing because
    // definition is impossible in the plane that combines all that is evil
    // with all that is chaotic - the birthing place of the demon races,
    // Demonholme to Gladsheim, Jurgarten to Arvandor). The only well-known
    // layer is the first - Pazunia, the Plains of Infinite Portals, the
    // Palace of 1,001 Closets - a barren dusty place baking beneath a
    // hell-red sun, broken by the three features: the holes (conduits to
    // every layer, working like Astral conduits), the iron fortresses
    // (housing the material bodies of astrally-traveling demon lords, guarded
    // by servants who fight to the death - permanent here - amid common
    // sieges, the fortresses immune to astral-viewing portals), and the
    // winding Styx with its reverse waterfalls (use Charon or his servants);
    // no known barriers on the first layer, the deeper layers' barriers
    // jealously guarded, any terrain to any terrain. The terrain d100: eight
    // even 10-point bands - desert (WSG dehydration), glacier (para-elemental
    // Ice), spatial (airless gravity-free air-only), maelstrom (Limbo churn,
    // a safe zone needing lesser-god power), rocky (lava and volcanoes),
    // underground (conduits landing in temporary safety), water (a surfaced
    // ocean), normal (Prime variety) - then the layer of delusion (a sentient
    // layer seeking the invaders' destruction: poison flowers, attacking
    // trees, friends-turned-assassins), the realm band (a prince's or Power's
    // palace, visitors unwelcome), and the evil-incarnate tail (good mortals
    // save vs spell or die; neutrals and the saved flung to a random layer;
    // evil mortals become bodaks with no save). The races: the limitless
    // demon hordes always turning on each other, the MM2 page-35 frequencies
    // with the Abyss additions (bodaks uncommon, shadow demons rare, hordings
    // rare), the rulers' vast standing forces, the lords unified only by
    // hatred of good. The eleven rumored dwellings: Orcus's bone palace with
    // its undead guards, Demogorgon's dinosaur jungles, Yeenoghu's
    // slave-pulled rolling mansion, Juiblex's fungus-and-rot layer, Lolth's
    // web amid the primal maelstrom, Baphomet's changing infinite maze of
    // minotaurs, Fraz-Urb'Luu's deceptive beauty over rotting flesh,
    // Graz'zt's palace-layer army against Orcus and Demogorgon, Kostchtchie's
    // glacial hatred, Pazuzu ceded the air of every layer (the well-liked
    // demon), Zuggtmoy's purplish fungoid realms; the lords are Lesser Powers
    // in their home planes, dead if slain in the Abyss though a successor
    // evolves to fill the gap. The servants: armor 1 better, +2 to hit below
    // low Intelligence, 10% casting as evil clerics of level 1d10. And the
    // Powers: few Greater Powers bother - Vaprak of the trolls and Laogzed of
    // the troglodytes ruling parts of single layers, Urdlen's hate-carved
    // tunnels, Tou Mu and Lu Yueh's Feng-Tu citadel up the How Nai-ho fork of
    // the Styx through the Kuei-Men-Kuan gate of demons, and Kali's blood-red
    // layer of scarlet-vined temples and rakshasa servants.
    {
        using namespace rules;
        int bad = 0;
    if (ddlAbyssLayerCount() != 666
            || ddlTerrainBand() != 10
            || ddlTerrainRealmEnd() != 95
            || ddlTerrainEvilEnd() != 100
            || ddlServantAcBonus() != 1
            || ddlServantHitBonus() != 2
            || ddlServantCastPct() != 10
            || !ddlAbyssDoctrine()
            || !ddlPazuniaRule()
            || !ddlAbyssRaces()
            || !ddlDemonPrinces()
            || !ddlAbyssServantRule()
            || !ddlAbyssPowers()
        )
            ++bad;
        // the AbyssLayerCount pin
    if (ddlAbyssLayerCount() != 666
        )
            ++bad;
        // the TerrainBand pin
    if (ddlTerrainBand() != 10
        )
            ++bad;
        // the TerrainRealmEnd pin
    if (ddlTerrainRealmEnd() != 95
        )
            ++bad;
        // the TerrainEvilEnd pin
    if (ddlTerrainEvilEnd() != 100
        )
            ++bad;
        // the ServantAcBonus pin
    if (ddlServantAcBonus() != 1
        )
            ++bad;
        // the ServantHitBonus pin
    if (ddlServantHitBonus() != 2
        )
            ++bad;
        // the ServantCastPct pin
    if (ddlServantCastPct() != 10
        )
            ++bad;
        // the AbyssDoctrine pin
    if (ddlAbyssDoctrine() != 1
        )
            ++bad;
        // the PazuniaRule pin
    if (ddlPazuniaRule() != 1
        )
            ++bad;
        // the AbyssRaces pin
    if (ddlAbyssRaces() != 1
        )
            ++bad;
        // the DemonPrinces pin
    if (ddlDemonPrinces() != 1
        )
            ++bad;
        // the AbyssServantRule pin
    if (ddlAbyssServantRule() != 1
        )
            ++bad;
        // the AbyssPowers pin
    if (ddlAbyssPowers() != 1
        )
            ++bad;
        printf("R583 Abyss audit: bad %d\n", bad);
        if (bad) return 1;
    }
