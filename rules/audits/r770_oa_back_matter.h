    // ---- R770 OA Back matter audit ----
    // OA round one hundred fifty-seven (capture pp. 313-314): the back matter
    // - the bibliography of Oriental Adventures, the plus-marked background,
    // the samurai, ninja, folklore, and culture shelves, with the missed
    // Chapter 14 and 15 parent boxes closed pre-landing, single-pass pins per
    // the R679 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dmfHearnTitlesCount() != 4
            || dmfTurnbullSamuraiTitlesCount() != 2
            || !dmfBibliographyHeader()
            || !dmfPlusMarkedBackground()
            || !dmfSunTzuArtOfWar()
            || !dmfMusashiFiveRings()
            || !dmfSecretsOfSamurai()
            || !dmfBudoshoshinshuEntry()
            || !dmfNinjutsuEntries()
            || !dmfHearnJapanTitles()
            || !dmfChineseMythologyTitles()
            || !dmfFolkTaleTitles()
            || !dmfArchitectureTitles()
            || !dmfArmsAndArmorTitles()
            || !dmfDailyLifeTitles()
            || !dmfReligionTitles()
            || !dmfChineseClassicTitles()
            || !dmfChineseSymbolismTitles()
        )
            ++bad;
        // the doctrine example
    if (dmfBibliographyHeader() != 1
            || dmfPlusMarkedBackground() != 1
        )
            ++bad;
        // the Hearn example
    if (dmfHearnTitlesCount() != 4
            || dmfHearnJapanTitles() != 1
        )
            ++bad;
        // the warfare example
    if (dmfTurnbullSamuraiTitlesCount() != 2
            || dmfSunTzuArtOfWar() != 1
            || dmfMusashiFiveRings() != 1
        )
            ++bad;
        // the samurai shelf example
    if (dmfSecretsOfSamurai() != 1
            || dmfBudoshoshinshuEntry() != 1
        )
            ++bad;
        // the ninja example
    if (dmfNinjutsuEntries() != 1
        )
            ++bad;
        // the folklore example
    if (dmfChineseMythologyTitles() != 1
            || dmfFolkTaleTitles() != 1
        )
            ++bad;
        // the craft example
    if (dmfArchitectureTitles() != 1
            || dmfArmsAndArmorTitles() != 1
        )
            ++bad;
        // the culture example
    if (dmfDailyLifeTitles() != 1
            || dmfReligionTitles() != 1
        )
            ++bad;
        // the classics example
    if (dmfChineseClassicTitles() != 1
            || dmfChineseSymbolismTitles() != 1
        )
            ++bad;
        printf("R770 OA Back matter audit: bad %d\n", bad);
        if (bad) return 1;
    }
