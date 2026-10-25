    // ---- R580 Elysium-Beastlands audit ----
    // ELYSIUM AND THE HAPPY HUNTING GROUNDS, printed pp. 90-92, the next two
    // Upper Planes in one round: Elysium, ultimate good unsullied by
    // hierarchy or anarchy (the spirits at final rest beyond summoning or
    // control, the Powers answering only worthy or profitable callings, the
    // River Oceanus dominating the four layers - Amoria the arrival banks,
    // Eronia the mountains with doubled obstructions, Bellerin the flat
    // marshes, Thalasia the great sea with the Isles of the Blessed - the
    // 1d10-day transits with the 10% per-day snag chance, the dark Amoria
    // caverns with their divination-only destinations, the Oceanus-swallowing
    // caverns to the Beastlands, the indigo-to-robins-egg sky of the Powers'
    // passing craft, the phoenix and the moon dogs, and the MOVING realms -
    // Isis with her moon-dog patrols, Seker's flying sphere Ro Stau, Ishtar's
    // half-mile fighting statue, Enlil and Nin-Hursag, the crescent
    // moon-barque of Nanna-Sin, Ushas, Tsukiyomi and Bragi); and the Happy
    // Hunting Grounds, the triple-layered Beastlands of good tending toward
    // chaos (Krigala's zenith-fixed midday sun and realm-varying weather,
    // Brux's two rising-or-setting suns, Karasuthra's wandering unmoored
    // stars, the hollow-tree portals keyed by tree type, the identification
    // and communication spells in all layers, the wind-control prevention by
    // the aerial mortals - the faces in the clouds, the sentient
    // speech-capable beasts with their 10% spell-casting chance on the d100
    // ladder, the doubled hit dice and the 5%-plus-5% magic resistance lost
    // outside the outer and Astral planes, the Beast Lords with plane-wide
    // command of their kinds, and Skerrit the Forester); ONE AMENDMENT: the
    // spell-casting-creatures table the report filed under Olympus is the
    // Beastlands beasts table of printed p. 92.
    {
        using namespace rules;
        int bad = 0;
    if (ddiElysiumLayerCount() != 4
            || ddiOceanusTransitDays() != 10
            || ddiBeastlandLayerCount() != 3
            || ddiBeastCasterPct() != 10
            || ddiBeastHdMult() != 2
            || !ddiElysiumDoctrine()
            || !ddiElysiumCavernRule()
            || !ddiElysiumPowers()
            || !ddiElysiumCreatures()
            || !ddiBeastlandDoctrine()
            || !ddiBeastlandWindRule()
            || !ddiBeastLordRule()
        )
            ++bad;
        // the ElysiumLayerCount pin
    if (ddiElysiumLayerCount() != 4
        )
            ++bad;
        // the OceanusTransitDays pin
    if (ddiOceanusTransitDays() != 10
        )
            ++bad;
        // the BeastlandLayerCount pin
    if (ddiBeastlandLayerCount() != 3
        )
            ++bad;
        // the BeastCasterPct pin
    if (ddiBeastCasterPct() != 10
        )
            ++bad;
        // the BeastHdMult pin
    if (ddiBeastHdMult() != 2
        )
            ++bad;
        // the ElysiumDoctrine pin
    if (ddiElysiumDoctrine() != 1
        )
            ++bad;
        // the ElysiumCavernRule pin
    if (ddiElysiumCavernRule() != 1
        )
            ++bad;
        // the ElysiumPowers pin
    if (ddiElysiumPowers() != 1
        )
            ++bad;
        // the ElysiumCreatures pin
    if (ddiElysiumCreatures() != 1
        )
            ++bad;
        // the BeastlandDoctrine pin
    if (ddiBeastlandDoctrine() != 1
        )
            ++bad;
        // the BeastlandWindRule pin
    if (ddiBeastlandWindRule() != 1
        )
            ++bad;
        // the BeastLordRule pin
    if (ddiBeastLordRule() != 1
        )
            ++bad;
        printf("R580 Elysium-Beastlands audit: bad %d\n", bad);
        if (bad) return 1;
    }
