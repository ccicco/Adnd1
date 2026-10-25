    // ---- R551 DSG worlds of adventure audit ----
    // The rest of Worlds of Adventure pins printed pp. 101-103: the
    // location-type variety (the missing climate criterion, the
    // natural/artificial settings, the unique area characteristics, the
    // inhabitant variety with the individualistic monsters), the
    // dangerous/safe mix (the friendly encounters, the shoot-first
    // consequences, the tranquil havens), Consistency (the
    // familiarity-over-realism doctrine with the dragon example, the source
    // and historical familiarity, the stable world rules, the social laws and
    // consequences), the Intelligent Races design questionnaire (appearance,
    // livelihood, civilization, settlements, customs, limitations,
    // preferences, first impressions), and Uniqueness (the DM's style, the
    // creative additions, the faithful-recreation exception).
    {
        using namespace rules;
        int bad = 0;
    if (!dcdLocationTypes()
            || !dcdNaturalArtificial()
            || !dcdInhabitantVariety()
            || !dcdIndividualistic()
            || !dcdStaleSurprise()
            || !dcdEncounterMix()
            || !dcdFriendlyEncounters()
            || !dcdShootFirstConsequences()
            || !dcdTranquilHavens()
            || !dcdHavenRespect()
            || !dcdUnderlyingIdea()
            || !dcdFamiliarityOverRealism()
            || !dcdDragonFamiliarity()
            || !dcdSourceConsistency()
            || !dcdHistoricalFamiliarity()
            || !dcdWorldRulesStable()
            || !dcdNatureLaws()
            || !dcdFamiliarityGrows()
            || !dcdSocialFamiliarity()
            || !dcdLawConsequences()
            || !dcdRacesNeedForesight()
            || !dcdOriginalRaceExtensive()
            || !dcdRaceAppearance()
            || !dcdRaceLivelihood()
            || !dcdCivilizationHallmarks()
            || !dcdCivilizationConsequences()
            || !dcdSettlementScale()
            || !dcdRaceCustoms()
            || !dcdHandshakeCustom()
            || !dcdCustomsIncremental()
            || !dcdRaceLimitations()
            || !dcdRacePreferences()
            || !dcdFirstImpressions()
            || !dcdUniquenessStyle()
            || !dcdUnusualNames()
            || !dcdNewForms()
            || !dcdFaithfulRecreation()
        )
            ++bad;
        // the location frame: the types required, the natural/artificial
        // source.
    if (dcdLocationTypes() != 1
            || dcdNaturalArtificial() != 1
        )
            ++bad;
        // the variety craft: the individualistic monsters, the stale-campaign
        // surprise.
    if (dcdIndividualistic() != 1
            || dcdStaleSurprise() != 1
        )
            ++bad;
        // the mix: friendly encounters, the havens, the no-regular-violations
        // rule.
    if (dcdFriendlyEncounters() != 1
            || dcdTranquilHavens() != 1
            || dcdHavenRespect() != 1
        )
            ++bad;
        // the consistency doctrine: familiarity over realism, the dragon
        // example.
    if (dcdFamiliarityOverRealism() != 1
            || dcdDragonFamiliarity() != 1
        )
            ++bad;
        // the stable world: the founded rules, the nature laws, the law
        // consequences.
    if (dcdWorldRulesStable() != 1
            || dcdNatureLaws() != 1
            || dcdLawConsequences() != 1
        )
            ++bad;
        // the race questionnaire: appearance, livelihood, limitations,
        // preferences.
    if (dcdRaceAppearance() != 1
            || dcdRaceLivelihood() != 1
            || dcdRaceLimitations() != 1
            || dcdRacePreferences() != 1
        )
            ++bad;
        // the race culture: the handshake custom, the civilization hallmarks.
    if (dcdHandshakeCustom() != 1
            || dcdCivilizationHallmarks() != 1
        )
            ++bad;
        // the uniqueness split: the DM's own style against the
        // faithful-recreation exception.
    if (dcdUniquenessStyle() != 1
            || dcdFaithfulRecreation() != 1
        )
            ++bad;
        printf("R551 DSG worlds of adventure audit: bad %d\n", bad);
        if (bad) return 1;
    }
