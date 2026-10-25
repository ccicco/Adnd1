    // ---- R579 Heavens-Twins audit ----
    // THE SEVEN HEAVENS AND THE TWIN PARADISES, printed pp. 87-90, the next
    // two Upper Planes in one round: the Seven Heavens of goodness tempered
    // by law (the seven ascending layers with the barrier-at-the-peak
    // illusion of ascendency, the constant gravity, Lunia the Silver Heaven
    // with its holy-water surf arrivals and silvery stars, Mercuria the
    // Golden armory with Bahamut's court, Venya the Pearl with the halfling
    // Green Fields, Solania the Electrum with Moradin's Soul Forge in
    // Ereokhar, Mertion the Platinum with its citadels and domes, Jovar the
    // Glittering with the Jovarian archons and the ziggurat council rumor,
    // Chronias the Illuminated where goodness is raised and evil
    // extinguished), the archon ladder (the five types - Lanterns, Hounds,
    // Wardens, Swords, Tomes - deferring to the devas, planetars and solars),
    // the finished-stone portals (the granite color codes), and the Powers
    // (Yondalla's mythos with Brandobaris, Moradin and Berronar, the
    // four-layer Bahamut palace problem, Chung Kuel and Kuan Yin, Vishnu and
    // Surya with Garuda, Ebisu and Girru, the home-plane-benefits-anywhere
    // rule); and the Twin Paradises of good with organization only when
    // necessary (the book with no spine - the facing layers Dothion and
    // Shurrock 20 miles apart, upside down to each other, the midair barrier
    // crossed by the Wisdom check or paired mountains, the cavern portals
    // with concentric, radiating and spiderweb patterns, the mild pastoral
    // Dothion and the challenging dramatic Shurrock, NO additional
    // restrictions, and the Powers - the gnomish pantheon of Garl
    // Glittergold, Baervan with Whisperleaf, Segojan and Flandal, Ukko the
    // blizzard-throwing Finn across the barrier with his air maidens, and the
    // wandering destructive titan Epinetheus).
    {
        using namespace rules;
        int bad = 0;
    if (ddhHeavenLayerCount() != 7
            || ddhTwinSeparationMiles() != 20
            || ddhOceanusTransitDays() != 10
            || ddhArchonTypeCount() != 5
            || !ddhLuniaSurfRule()
            || !ddhHeavenLayersDoctrine()
            || !ddhHeavenPortalsRule()
            || !ddhHeavenPowers()
            || !ddhTwinPortalPatterns()
            || !ddhTwinPowers()
            || !ddhTwinNoRestrictions()
        )
            ++bad;
        // the HeavenLayerCount pin
    if (ddhHeavenLayerCount() != 7
        )
            ++bad;
        // the TwinSeparationMiles pin
    if (ddhTwinSeparationMiles() != 20
        )
            ++bad;
        // the OceanusTransitDays pin
    if (ddhOceanusTransitDays() != 10
        )
            ++bad;
        // the ArchonTypeCount pin
    if (ddhArchonTypeCount() != 5
        )
            ++bad;
        // the LuniaSurfRule pin
    if (ddhLuniaSurfRule() != 1
        )
            ++bad;
        // the HeavenLayersDoctrine pin
    if (ddhHeavenLayersDoctrine() != 1
        )
            ++bad;
        // the HeavenPortalsRule pin
    if (ddhHeavenPortalsRule() != 1
        )
            ++bad;
        // the HeavenPowers pin
    if (ddhHeavenPowers() != 1
        )
            ++bad;
        // the TwinPortalPatterns pin
    if (ddhTwinPortalPatterns() != 1
        )
            ++bad;
        // the TwinPowers pin
    if (ddhTwinPowers() != 1
        )
            ++bad;
        // the TwinNoRestrictions pin
    if (ddhTwinNoRestrictions() != 1
        )
            ++bad;
        printf("R579 Heavens-Twins audit: bad %d\n", bad);
        if (bad) return 1;
    }
