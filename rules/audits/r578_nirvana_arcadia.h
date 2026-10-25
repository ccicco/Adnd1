    // ---- R578 Nirvana-Arcadia audit ----
    // NIRVANA and ARCADIA, printed pp. 84-87, the first two named planes of
    // the Planes of Power in one round: Nirvana the clockwork plane of
    // ultimate Law (the infinite interlocking disks at 500 miles plus, the
    // per-disk gravity with the walk-over-the-edge rule, the air-filled void,
    // the 1/100-turn realm pull, the light-green and deep-red portals cycling
    // once per disk revolution at 20 days on Primus's plane, the always-open
    // Concordant Opposition portal beneath Primus's disk, the no-illusion
    // rule - phantasms as thin smoke fooling no one, Primus the One and Prime
    // with the modrons and Anu's Way, and the pantheons - Anu, Shang-Ti with
    // the peaches and the library of lost knowledge, Shan-Hai Ching, Varuna,
    // Rudra and Yama, Horus, Utu and Enki); and Arcadia the orchard plane of
    // law for the common good (the half-radiant half-black day sphere with
    // its dawnless Prime-length day, the three layers, the metallic trees
    // with double-strength potion fruit spoiling in 1-10 days, the
    // pupilless-eyed watch beasts immune to Prime spells, the ivory and steel
    // archway portals with the 1-in-10 mist and the 90/10 sides rule, the
    // spirit-folk militias with their divination over the static, and the
    // Powers - Marduk the Valiant with the kirdari, and Clanggedin
    // Silverbeard the dwarven Father of Battle with his fortress mountain and
    // his Acheron raids).
    {
        using namespace rules;
        int bad = 0;
    if (ddgDiskRadiusMiles() != 500
            || ddgRealmPullTurns() != 100
            || ddgPortalCycleDays() != 20
            || ddgFruitSpoilDays() != 10
            || ddgArchMistDenom() != 10
            || ddgArchBothSidesPct() != 90
            || !ddgNirvanaNoIllusion()
            || !ddgPrimusDoctrine()
            || !ddgNirvanaPantheon()
            || !ddgArcadiaDaySphere()
            || !ddgArcadiaLayers()
            || !ddgArcadiaWatchBeasts()
            || !ddgArcadiaMilitia()
            || !ddgArcadiaPowers()
        )
            ++bad;
        // the DiskRadiusMiles pin
    if (ddgDiskRadiusMiles() != 500
        )
            ++bad;
        // the RealmPullTurns pin
    if (ddgRealmPullTurns() != 100
        )
            ++bad;
        // the PortalCycleDays pin
    if (ddgPortalCycleDays() != 20
        )
            ++bad;
        // the FruitSpoilDays pin
    if (ddgFruitSpoilDays() != 10
        )
            ++bad;
        // the ArchMistDenom pin
    if (ddgArchMistDenom() != 10
        )
            ++bad;
        // the ArchBothSidesPct pin
    if (ddgArchBothSidesPct() != 90
        )
            ++bad;
        // the NirvanaNoIllusion pin
    if (ddgNirvanaNoIllusion() != 1
        )
            ++bad;
        // the PrimusDoctrine pin
    if (ddgPrimusDoctrine() != 1
        )
            ++bad;
        // the NirvanaPantheon pin
    if (ddgNirvanaPantheon() != 1
        )
            ++bad;
        // the ArcadiaDaySphere pin
    if (ddgArcadiaDaySphere() != 1
        )
            ++bad;
        // the ArcadiaLayers pin
    if (ddgArcadiaLayers() != 1
        )
            ++bad;
        // the ArcadiaWatchBeasts pin
    if (ddgArcadiaWatchBeasts() != 1
        )
            ++bad;
        // the ArcadiaMilitia pin
    if (ddgArcadiaMilitia() != 1
        )
            ++bad;
        // the ArcadiaPowers pin
    if (ddgArcadiaPowers() != 1
        )
            ++bad;
        printf("R578 Nirvana-Arcadia audit: bad %d\n", bad);
        if (bad) return 1;
    }
