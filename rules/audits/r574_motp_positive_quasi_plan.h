    // ---- R574 MotP positive quasi-planes audit ----
    // the Positive Quasi-Planes, printed pp. 55-57, the four in one round:
    // Lightning, Radiance, Minerals and Steam - the agitated-matter doctrine
    // with the tidal Positive borders, the per-plane survival (the 5/10/20%
    // per-round strikes at 1d8-of-d10s, the thunder-deafness with the
    // wax-plug fix, the Radiance blind save with the smoked lenses, the
    // 1d4-plus-AC Minerals movement damage, the muggy Steam slow), the
    // 1-in-10 encounter check, the wall-of-brilliance intrusion at 3d6 per
    // round, the pocket conversion rule, the native immunities, the doubled
    // guide prices, the tower ring, the gem economy with the 1-in-100
    // survival, and the fossilization (save per true turn, the 80/20 split,
    // the 99% crumble).
    {
        using namespace rules;
        int bad = 0;
    if (ddcQuasiPlaneCount() != 4
            || ddcLightningStrikePctL() != 20
            || ddcLightningDeafTurns() != 264
            || ddcMineralsMoveDamageDie() != 4
            || ddcQuasiEncounterDenom() != 10
            || ddcWallAdvanceDieSides() != 6
            || ddcPocketConvertPct() != 30
            || ddcGemSurviveDenom() != 100
            || ddcPetrifyStonePct() != 80
            || !ddcRadianceBlindRule()
            || !ddcSteamMuggyRule()
            || !ddcLightningNativeImmunity()
            || !ddcGuidePriceDoubled()
            || !ddcNoQuasiArchoment()
        )
            ++bad;
        // the QuasiPlaneCount pin
    if (ddcQuasiPlaneCount() != 4
        )
            ++bad;
        // the LightningStrikePctL pin
    if (ddcLightningStrikePctL() != 20
        )
            ++bad;
        // the LightningDeafTurns pin
    if (ddcLightningDeafTurns() != 264
        )
            ++bad;
        // the MineralsMoveDamageDie pin
    if (ddcMineralsMoveDamageDie() != 4
        )
            ++bad;
        // the QuasiEncounterDenom pin
    if (ddcQuasiEncounterDenom() != 10
        )
            ++bad;
        // the WallAdvanceDieSides pin
    if (ddcWallAdvanceDieSides() != 6
        )
            ++bad;
        // the PocketConvertPct pin
    if (ddcPocketConvertPct() != 30
        )
            ++bad;
        // the GemSurviveDenom pin
    if (ddcGemSurviveDenom() != 100
        )
            ++bad;
        // the PetrifyStonePct pin
    if (ddcPetrifyStonePct() != 80
        )
            ++bad;
        // the RadianceBlindRule pin
    if (ddcRadianceBlindRule() != 1
        )
            ++bad;
        // the SteamMuggyRule pin
    if (ddcSteamMuggyRule() != 1
        )
            ++bad;
        // the LightningNativeImmunity pin
    if (ddcLightningNativeImmunity() != 1
        )
            ++bad;
        // the GuidePriceDoubled pin
    if (ddcGuidePriceDoubled() != 1
        )
            ++bad;
        // the NoQuasiArchoment pin
    if (ddcNoQuasiArchoment() != 1
        )
            ++bad;
        printf("R574 MotP positive quasi-planes audit: bad %d\n", bad);
        if (bad) return 1;
    }
