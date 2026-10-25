    // ---- R773 OA daily-life misses audit ----
    // OA round one hundred sixty: the daily-life misses - the three Chapter
    // 15 sections the post-OA maintenance audit found unpinned and unboxed
    // (Dress capture pp. 306-307, Religion p. 310, Law and Justice pp.
    // 310-312, the book's own seven-section list against the four pinned) -
    // pinned and boxed in one round
    {
        using namespace rules;
        int bad = 0;
    if (dmkRegionalMaterialCount() != 7
            || dmkCommonColorCount() != 5
            || dmkNamedReligionCount() != 5
            || dmkCommonerPunishmentCount() != 9
            || dmkHigherClassPunishmentCount() != 4
            || !dmkClothingStatusDoctrine()
            || !dmkCommonMaterials()
            || !dmkRegionalMaterials()
            || !dmkLeatherDoctrine()
            || !dmkWhiteMourning()
            || !dmkCommonColors()
            || !dmkTrouserDoctrine()
            || !dmkRobeDoctrine()
            || !dmkMinoRaincloak()
            || !dmkFootwearDoctrine()
            || !dmkHatDoctrine()
            || !dmkMaleBeauty()
            || !dmkFemaleBeauty()
            || !dmkHairDoctrine()
            || !dmkNoChurchConcept()
            || !dmkManyReligionsPractice()
            || !dmkReligiousTolerance()
            || !dmkSectDoctrine()
            || !dmkCourtStructure()
            || !dmkEvidenceGathering()
            || !dmkNoLawyers()
            || !dmkSpeakWithDeadTestimony()
            || !dmkClassDoubleStandard()
            || !dmkPunishmentDoctrine()
            || !dmkCivilMediation()
            || !dmkCollectiveResponsibility()
            || !dmkVendettaDoctrine()
            || !dmkVendettaRankRule()
            || !dmkVendettaApproval()
            || !dmkVendettaDuel()
        )
            ++bad;
        // the punishment ladder - the commoner punishments minus the
        // higher-class punishments is five
    if (dmkCommonerPunishmentCount() - dmkHigherClassPunishmentCount() != 5
        )
            ++bad;
        // the common colors equal the named religions - both five
    if (dmkCommonColorCount() != dmkNamedReligionCount()
        )
            ++bad;
        // the regional materials plus the named religions is twelve
    if (dmkRegionalMaterialCount() + dmkNamedReligionCount() != 12
        )
            ++bad;
        printf("R773 OA daily-life misses audit: bad %d\n", bad);
        if (bad) return 1;
    }
