    // ---- R584 Tarterus audit ----
    // TARTERUS, printed pp. 103-105, the land between Hades and the Abyss:
    // six crimson-pearl layers, strings of world-sized orbs glowing dull red
    // like fire-beetle phosphorescence yet no hotter than a summer's
    // afternoon - the air-filled gulfs flyable, the orbs unspinning, the heat
    // from the ground and the light from ground and neighbor alike, no day or
    // night but by the Powers' wishes, the seasons random and the storm-fed
    // flowers withering in hours. The layers: Othrys (the greater titans,
    // orbs a hundred miles apart, marsh and glowing quicksand, the Styx and
    // innumerable rivers crossing every world), Cathrys (500-mile gaps,
    // overblown jungles and scarlet grass secreting an acid that eats metal
    // in 1d10 rounds and deals 1d6 on contact), Minethys (5,000-mile gulfs of
    // hard wind, poisonous-dust deserts under a permanent cloudkill, and
    // every ten days a massive tornado carrying its catch to an adjacent orb
    // or another string), Colothys (the most mountainous, spiked orbs a
    // half-million miles apart, hundreds-mile mountains and hell-chasms
    // walled with demon and daemon legions), Porphatys (the wettest save one,
    // millions of miles apart, black acidic demonic snow at 1d4 per round
    // that rots cloth in 10 rounds, spares stone and metal, and leaves the
    // orbs under 1d6 feet of water), and Agathys (the deepest and coldest,
    // each orb alone in pitch-black sky, dark ice streaked with red, the air
    // of a Prime mountain peak). The barriers sit at the lowest points and
    // always link the same orb layer-to-layer - nested spheres, the
    // fifth-to-sixth barriers underwater and anything beyond the sixth sealed
    // beneath miles of ice. The portals of Othrys are guarded obelisks read
    // by shape - taller than wide to Hades, wider than tall to the Abyss,
    // square to Concordant Opposition - transferred by touch, with the Styx
    // flowing through the topmost layer besides. The features: the demons
    // with numbers against the daemons with organization, a continual
    // insurgency arcanadaemons and cambions straddle; the demodands above
    // both - winged mixes of the worst of demon and daemon, the ruling
    // shators served by kelubar and farastu, enslaving what they catch,
    // spanning the gulfs and finding their way like elementals, before whom
    // all but the mightiest make way; the achalera, nightmares, hordings,
    // shadow demons, mephits and the shator-made vargouilles that ate their
    // master; the natives immune to snow and cold while visiting princes
    // shiver. And the Powers: the titans of Mount Othrys - Kronos's twin
    // 50-mile peaks, the court of Coeus, Crius and Oceanus, the shattered
    // road of Olympus that trapped them, the chaotic-good kin without and the
    // wait-and-plan within, seizing useful travelers; Surma's open graves of
    // walking undead and Kiputyto's winds of gout, ulcers and plague;
    // Grolantor of the hill giants holding the fourth layer's peaks while the
    // shators kneel out of fear.
    {
        using namespace rules;
        int bad = 0;
    if (ddmTarterusLayerCount() != 6
            || ddmOrbGapColothysMiles() != 500000
            || ddmCathrysAcidMetalRounds() != 10
            || ddmMinethysTornadoDays() != 10
            || ddmPorphatysSnowDamage() != 4
            || ddmTitanPeakMiles() != 50
            || !ddmTarterusDoctrine()
            || !ddmTarterusPortals()
            || !ddmDemodandRule()
            || !ddmTarterusCreatures()
            || !ddmKronosRule()
            || !ddmTarterusPowers()
        )
            ++bad;
        // the TarterusLayerCount pin
    if (ddmTarterusLayerCount() != 6
        )
            ++bad;
        // the OrbGapColothysMiles pin
    if (ddmOrbGapColothysMiles() != 500000
        )
            ++bad;
        // the CathrysAcidMetalRounds pin
    if (ddmCathrysAcidMetalRounds() != 10
        )
            ++bad;
        // the MinethysTornadoDays pin
    if (ddmMinethysTornadoDays() != 10
        )
            ++bad;
        // the PorphatysSnowDamage pin
    if (ddmPorphatysSnowDamage() != 4
        )
            ++bad;
        // the TitanPeakMiles pin
    if (ddmTitanPeakMiles() != 50
        )
            ++bad;
        // the TarterusDoctrine pin
    if (ddmTarterusDoctrine() != 1
        )
            ++bad;
        // the TarterusPortals pin
    if (ddmTarterusPortals() != 1
        )
            ++bad;
        // the DemodandRule pin
    if (ddmDemodandRule() != 1
        )
            ++bad;
        // the TarterusCreatures pin
    if (ddmTarterusCreatures() != 1
        )
            ++bad;
        // the KronosRule pin
    if (ddmKronosRule() != 1
        )
            ++bad;
        // the TarterusPowers pin
    if (ddmTarterusPowers() != 1
        )
            ++bad;
        printf("R584 Tarterus audit: bad %d\n", bad);
        if (bad) return 1;
    }
