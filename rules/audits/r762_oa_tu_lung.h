    // ---- R762 OA Tu Lung audit ----
    // OA round one hundred forty-nine (capture pp. 303-304): the Tu Lung
    // empire - the Earth Dragon, the succession break of 300 years ago, the
    // Lui Dynasty, the noble control of the examinations, the six provinces,
    // the capital Chia Wan Chuan, single-pass pins per the R679 provenance
    // shift
    {
        using namespace rules;
        int bad = 0;
    if (dlxYearsSinceSplit() != 300
            || dlxProvinceCount() != 6
            || !dlxEarthDragon()
            || !dlxPartOfShouLung()
            || !dlxOwnEmperorSeparateCourt()
            || !dlxWarsStabilized()
            || !dlxNoLoveLost()
            || !dlxRebelNoblesGreatPower()
            || !dlxModeledAfterShouLung()
            || !dlxLuiDynasty()
            || !dlxEmperorCannotBreakNobles()
            || !dlxNoblesControlExaminations()
            || !dlxOfficesHereditary()
            || !dlxEstatesExemptEdicts()
            || !dlxMajorityConsent()
            || !dlxCommonersLittleChance()
            || !dlxPostCorruption()
            || !dlxHereditaryGovernors()
            || !dlxDistrictsFamilyGraft()
            || !dlxInheritedPublicWorks()
            || !dlxWorksPoorlyMaintained()
            || !dlxPeopleEasilyOppressed()
            || !dlxCapitalPlotting()
            || !dlxSecretSocieties()
        )
            ++bad;
        // the founding example
    if (dlxEarthDragon() != 1
            || dlxPartOfShouLung() != 1
            || dlxYearsSinceSplit() != 300
            || dlxOwnEmperorSeparateCourt() != 1
        )
            ++bad;
        // the wars example
    if (dlxWarsStabilized() != 1
            || dlxNoLoveLost() != 1
            || dlxRebelNoblesGreatPower() != 1
        )
            ++bad;
        // the government example
    if (dlxModeledAfterShouLung() != 1
            || dlxLuiDynasty() != 1
            || dlxEmperorCannotBreakNobles() != 1
        )
            ++bad;
        // the noble power example
    if (dlxNoblesControlExaminations() != 1
            || dlxOfficesHereditary() != 1
            || dlxEstatesExemptEdicts() != 1
            || dlxMajorityConsent() != 1
        )
            ++bad;
        // the commoner example
    if (dlxCommonersLittleChance() != 1
            || dlxPostCorruption() != 1
        )
            ++bad;
        // the administration example
    if (dlxProvinceCount() != 6
            || dlxHereditaryGovernors() != 1
            || dlxDistrictsFamilyGraft() != 1
        )
            ++bad;
        // the works example
    if (dlxInheritedPublicWorks() != 1
            || dlxWorksPoorlyMaintained() != 1
            || dlxPeopleEasilyOppressed() != 1
        )
            ++bad;
        // the capital example
    if (dlxCapitalPlotting() != 1
            || dlxSecretSocieties() != 1
        )
            ++bad;
        printf("R762 OA Tu Lung audit: bad %d\n", bad);
        if (bad) return 1;
    }
