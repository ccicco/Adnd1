    // ---- R769 OA Daily Life Names audit ----
    // OA round one hundred fifty-six (capture pp. 312-313): the Chapter 15
    // closer, Names - the western single name against the Oriental multiple
    // names, the secret, childhood, adult, family, clan, place, nickname,
    // substitute, religious, event, and posthumous names, single-pass pins
    // per the R679 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dmeMinimumLifelongNames() != 2
            || dmeNameTypesCount() != 13
            || !dmeWesternSingleName()
            || !dmeOrientalMultipleNames()
            || !dmeNamesDroppedWithNew()
            || !dmeSecretName()
            || !dmeChildhoodName()
            || !dmeAdultName()
            || !dmeHereditaryFamilyName()
            || !dmeClanTribeName()
            || !dmePlaceName()
            || !dmeNickname()
            || !dmeSubstituteUndesiredName()
            || !dmeArtistPenName()
            || !dmeSchoolMasterName()
            || !dmeReligiousName()
            || !dmeEventNames()
            || !dmePosthumousName()
        )
            ++bad;
        // the doctrine example
    if (dmeMinimumLifelongNames() != 2
            || dmeWesternSingleName() != 1
            || dmeOrientalMultipleNames() != 1
        )
            ++bad;
        // the types example
    if (dmeNameTypesCount() != 13
            || dmeNamesDroppedWithNew() != 1
        )
            ++bad;
        // the life names example
    if (dmeSecretName() != 1
            || dmeChildhoodName() != 1
            || dmeAdultName() != 1
        )
            ++bad;
        // the family example
    if (dmeHereditaryFamilyName() != 1
            || dmeClanTribeName() != 1
        )
            ++bad;
        // the place example
    if (dmePlaceName() != 1
            || dmeNickname() != 1
        )
            ++bad;
        // the substitute example
    if (dmeSubstituteUndesiredName() != 1
            || dmeArtistPenName() != 1
            || dmeSchoolMasterName() != 1
        )
            ++bad;
        // the sacred example
    if (dmeReligiousName() != 1
            || dmeEventNames() != 1
            || dmePosthumousName() != 1
        )
            ++bad;
        printf("R769 OA Daily Life Names audit: bad %d\n", bad);
        if (bad) return 1;
    }
