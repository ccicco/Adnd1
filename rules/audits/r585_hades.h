    // ---- R585 Hades audit ----
    // HADES, printed pp. 105-107, the plane of evil balanced between Law and
    // Chaos, the most accessible of the lower planes: the Styx midpoint with
    // Mount Olympus and the Yggdrasil both rooting here into the lower
    // layers. The three Glooms: Oinos, the sickly grey land of disease (10%
    // major disease for walkers and Styx-sailors alike, named for Anthraxus
    // the Oinodaemon); Niflheim, cooler and pine-cloaked but mist-bound at
    // 100 feet, reached by the Yggdrasil; Pluton, the grove of Persephone
    // with its black willows and single white laurel under Olympus's base.
    // The plane's evil: colors muted after one week, grey by two, and past
    // two weeks the save vs spell or the month-long fade into larvae -
    // rescuable only by a pull or a wish. The spinning-coin portals (copper
    // to Gehenna, silver to Concordant Opposition, gold to Tarterus, walled
    // off by arcanadaemon iron) and the tight barriers (to the Yggdrasil
    // roots before Hel's feast hall, to Persephone's grove and Cerberus). The
    // daemons in theory under Anthraxus but outnumbered by diakk and
    // hordlings, the sniping demodand war, and the Khin-Oin - the 20-mile
    // Wasting Tower wracked by internal plots, its daemon masters an
    // unbeatable common front when united, the fortress never stormed. The
    // night hags gathering the human-headed larvae that pass for coin in the
    // lower planes. The jailer doctrine - Law's guardians turned grey
    // prisoners, only greater gods free to wander. And the Powers: Hades of
    // Pluton with his bronze-dented gates and the wish-reviving Cerberus; Hel
    // of Niflheim with her grey einherjar; Nidhogg gnawing the World Ash, a
    // brood-member reborn within the year; Nergal's seven-domed Nergaltos
    // with the cumulative -2 gate saves (-14 at the seventh, potent enough to
    // trap Ishtar) holding Marduk's defeated forgotten Powers; the Indian
    // demigoddess of night and thieves; Abbathor's Glitterhell of spark-lit
    // gold with its rumored Niflheim barrier; and silent Yurtrus of the orcs,
    // whose Oinos realm kills plants at its borders and makes even daemons
    // cross carefully.
    {
        using namespace rules;
        int bad = 0;
    if (ddnHadesLayerCount() != 3
            || ddnOinosDiseasePct() != 10
            || ddnNiflheimVisionFeet() != 100
            || ddnLarvaSaveWeeks() != 2
            || ddnKhinOinMiles() != 20
            || ddnNergalDomePenalty() != 2
            || !ddnHadesDoctrine()
            || !ddnHadesPortals()
            || !ddnDaemonRule()
            || !ddnLarvaRule()
            || !ddnJailerRule()
            || !ddnHadesPowers()
        )
            ++bad;
        // the HadesLayerCount pin
    if (ddnHadesLayerCount() != 3
        )
            ++bad;
        // the OinosDiseasePct pin
    if (ddnOinosDiseasePct() != 10
        )
            ++bad;
        // the NiflheimVisionFeet pin
    if (ddnNiflheimVisionFeet() != 100
        )
            ++bad;
        // the LarvaSaveWeeks pin
    if (ddnLarvaSaveWeeks() != 2
        )
            ++bad;
        // the KhinOinMiles pin
    if (ddnKhinOinMiles() != 20
        )
            ++bad;
        // the NergalDomePenalty pin
    if (ddnNergalDomePenalty() != 2
        )
            ++bad;
        // the HadesDoctrine pin
    if (ddnHadesDoctrine() != 1
        )
            ++bad;
        // the HadesPortals pin
    if (ddnHadesPortals() != 1
        )
            ++bad;
        // the DaemonRule pin
    if (ddnDaemonRule() != 1
        )
            ++bad;
        // the LarvaRule pin
    if (ddnLarvaRule() != 1
        )
            ++bad;
        // the JailerRule pin
    if (ddnJailerRule() != 1
        )
            ++bad;
        // the HadesPowers pin
    if (ddnHadesPowers() != 1
        )
            ++bad;
        printf("R585 Hades audit: bad %d\n", bad);
        if (bad) return 1;
    }
