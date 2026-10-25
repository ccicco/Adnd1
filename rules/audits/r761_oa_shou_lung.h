    // ---- R761 OA Shou Lung audit ----
    // OA round one hundred forty-eight (capture p. 303): the Shou Lung empire
    // - the Receiver of the Dragon, the oldest state of over 1,200 years, the
    // Chin emperor of the Kuo Dynasty the eighth, the examination bureaucracy
    // with the commoner rise, the fourteen provinces and the districts, the
    // roads and bridges, the Imperial Messengers of Tien Shih, the dikes and
    // dams, the coinage and paper money, single-pass pins per the Chapter 9
    // provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dlwYearsOfState() != 1200
            || dlwDynastyCount() != 8
            || dlwProvinceCount() != 14
            || !dlwReceiverOfTheDragon()
            || !dlwLargestMostPowerful()
            || !dlwOldestState()
            || !dlwEmperorAllHistory()
            || !dlwTurmoilPeriods()
            || !dlwKuoDynastyChin()
            || !dlwExaminedBureaucracy()
            || !dlwCommonerRise()
            || !dlwGovernorPerProvince()
            || !dlwDistrictOwnOfficial()
            || !dlwOfficialDuties()
            || !dlwRoadsAndBridges()
            || !dlwImperialMessengers()
            || !dlwDikesAndDams()
            || !dlwCoinageAndPaper()
        )
            ++bad;
        // the standing example
    if (dlwReceiverOfTheDragon() != 1
            || dlwLargestMostPowerful() != 1
            || dlwOldestState() != 1
            || dlwYearsOfState() != 1200
        )
            ++bad;
        // the throne example
    if (dlwEmperorAllHistory() != 1
            || dlwTurmoilPeriods() != 1
            || dlwKuoDynastyChin() != 1
            || dlwDynastyCount() != 8
        )
            ++bad;
        // the bureaucracy example
    if (dlwExaminedBureaucracy() != 1
            || dlwCommonerRise() != 1
        )
            ++bad;
        // the administration example
    if (dlwProvinceCount() != 14
            || dlwGovernorPerProvince() != 1
            || dlwDistrictOwnOfficial() != 1
            || dlwOfficialDuties() != 1
        )
            ++bad;
        // the infrastructure example
    if (dlwRoadsAndBridges() != 1
            || dlwImperialMessengers() != 1
            || dlwDikesAndDams() != 1
            || dlwCoinageAndPaper() != 1
        )
            ++bad;
        printf("R761 OA Shou Lung audit: bad %d\n", bad);
        if (bad) return 1;
    }
