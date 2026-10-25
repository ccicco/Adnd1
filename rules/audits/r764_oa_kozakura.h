    // ---- R764 OA Kozakura audit ----
    // OA round one hundred fifty-one (capture p. 304): the island of Kozakura
    // - the Little Cherry Blossom, the same race and customs as Wa, the
    // incessant daimyo warfare for the shogun title, the adventurer haven,
    // the emperor against the bakufu, the families allied to both sides, the
    // peasant risen to lord, single-pass pins per the R679 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dlzStruggleSides() != 2
            || !dlzLittleCherryBlossomName()
            || !dlzSameRaceAsWa()
            || !dlzSharedCustomsTraditions()
            || !dlzFarFromUnifiedState()
            || !dlzIncessantDaimyoWarfare()
            || !dlzShogunTitleStruggle()
            || !dlzFiefsAndEstatesRule()
            || !dlzTurbulentFortunes()
            || !dlzAdventurerHaven()
            || !dlzEmperorRegainsPower()
            || !dlzBakufuRemainsOppose()
            || !dlzFamiliesAlliedEachSide()
            || !dlzLoyaltyOrPowerMotive()
            || !dlzAlliedToBothSides()
            || !dlzWarriorMostRespected()
            || !dlzLacksRigidLaws()
            || !dlzPeasantRisenToLord()
        )
            ++bad;
        // the island example
    if (dlzLittleCherryBlossomName() != 1
            || dlzSameRaceAsWa() != 1
            || dlzSharedCustomsTraditions() != 1
        )
            ++bad;
        // the wars example
    if (dlzFarFromUnifiedState() != 1
            || dlzIncessantDaimyoWarfare() != 1
            || dlzShogunTitleStruggle() != 1
        )
            ++bad;
        // the fief example
    if (dlzFiefsAndEstatesRule() != 1
            || dlzTurbulentFortunes() != 1
            || dlzAdventurerHaven() != 1
        )
            ++bad;
        // the struggle example
    if (dlzStruggleSides() != 2
            || dlzEmperorRegainsPower() != 1
            || dlzBakufuRemainsOppose() != 1
        )
            ++bad;
        // the families example
    if (dlzFamiliesAlliedEachSide() != 1
            || dlzLoyaltyOrPowerMotive() != 1
            || dlzAlliedToBothSides() != 1
        )
            ++bad;
        // the warrior example
    if (dlzWarriorMostRespected() != 1
            || dlzLacksRigidLaws() != 1
            || dlzPeasantRisenToLord() != 1
        )
            ++bad;
        printf("R764 OA Kozakura audit: bad %d\n", bad);
        if (bad) return 1;
    }
