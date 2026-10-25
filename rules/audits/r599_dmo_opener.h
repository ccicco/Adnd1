    // ---- R599 DMO opener audit ----
    // THE DMO ARC OPENER (the R564 pattern): Dungeon Master Option:
    // High-Level Campaigns (1995, Skip Williams, 192 pp.), the front matter
    // and the Seven Maxims - the foreword previews (the true dweomers as
    // 10th-level spells, the automatic saving-throw failure), the
    // seven-principle roster, the high-level definitions (level 10+, the
    // 30th-level cap, the retirement frame), the flat-XP breakdown from 9th,
    // and the Table 1 demographics ladder (the 1-in-5,000 10th, the
    // one-in-a-million 18th, the 1-in-500 paladin).
    {
        using namespace rules;
        int bad = 0;
    if (degMaximCount() != 7
            || degHighLevelFloor() != 10
            || degBookLevelCap() != 30
            || degRetirementLevel() != 20
            || degFlatXpFrom() != 9
            || degDemographicTenth() != 5000
            || degDemographicEighteenth() != 1000000
            || degPaladinRate() != 500
            || !degMaximRoster()
            || !degForewordDweomerThesis()
            || !degForewordAutoFail()
            || !degTensionDoctrine()
            || !degEpicScaleDoctrine()
        )
            ++bad;
        // the degMaximCount pin
    if (degMaximCount() != 7
        )
            ++bad;
        // the degHighLevelFloor pin
    if (degHighLevelFloor() != 10
        )
            ++bad;
        // the degBookLevelCap pin
    if (degBookLevelCap() != 30
        )
            ++bad;
        // the degRetirementLevel pin
    if (degRetirementLevel() != 20
        )
            ++bad;
        // the degFlatXpFrom pin
    if (degFlatXpFrom() != 9
        )
            ++bad;
        // the degDemographicTenth pin
    if (degDemographicTenth() != 5000
        )
            ++bad;
        // the degDemographicEighteenth pin
    if (degDemographicEighteenth() != 1000000
        )
            ++bad;
        // the degPaladinRate pin
    if (degPaladinRate() != 500
        )
            ++bad;
        // the degMaximRoster pin
    if (degMaximRoster() != 1
        )
            ++bad;
        // the degForewordDweomerThesis pin
    if (degForewordDweomerThesis() != 1
        )
            ++bad;
        // the degForewordAutoFail pin
    if (degForewordAutoFail() != 1
        )
            ++bad;
        // the degTensionDoctrine pin
    if (degTensionDoctrine() != 1
        )
            ++bad;
        // the degEpicScaleDoctrine pin
    if (degEpicScaleDoctrine() != 1
        )
            ++bad;
        printf("R599 DMO opener audit: bad %d\n", bad);
        if (bad) return 1;
    }
