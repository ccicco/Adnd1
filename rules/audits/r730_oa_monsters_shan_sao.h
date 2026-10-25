    // ---- R730 OA monsters Shan Sao audit ----
    // OA round one hundred seventeen (capture pp. 282-283): the Chapter 12
    // monster roster - the shan sao, the stat block and the woodlander
    // description riding together, the xp ladder as consts per the R723
    // pattern, single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dkrAppearMin() != 1
            || dkrAppearMax() != 10
            || dkrLairMultiplier() != 3
            || dkrAC() != 4
            || dkrMoveGround() != 6
            || dkrMoveFly() != 15
            || dkrHDMin() != 2
            || dkrHDMax() != 4
            || dkrLairPct() != 10
            || dkrAttackCount() != 1
            || dkrDmgMin() != 1
            || dkrDmgMax() != 6
            || dkrPolymorphPerDay() != 3
            || dkrDiseaseRangeFt() != 10
            || dkrTigerSummonMin() != 1
            || dkrTigerSummonMax() != 3
            || dkrTigerArrivalDie() != 6
            || dkrWuJenChancePct() != 5
            || dkrFemaleBonusPct() != 50
            || dkrFemaleHD() != 1
            || dkrVillageGuardChancePct() != 10
            || dkrVillageGuardTigersMin() != 1
            || dkrVillageGuardTigersMax() != 2
            || dkrXP2Base() != 36
            || dkrXP2PerHP() != 2
            || dkrXP3Base() != 65
            || dkrXP3PerHP() != 3
            || dkrXP4Base() != 110
            || dkrXP4PerHP() != 4
            || !dkrFrequencyUncommon()
            || !dkrMCA()
            || !dkrTreasureB()
            || !dkrSpecialAttacksDisease()
            || !dkrSummonTigers()
            || !dkrImmuneToFear()
            || !dkrMRStandard()
            || !dkrIntAverage()
            || !dkrAlignmentChaoticNeutral()
            || !dkrSizeSmall()
            || !dkrPsionicNil()
            || !dkrModesNil()
            || !dkrOneFootTall()
            || !dkrWoodlandHills()
            || !dkrFearlessAndPrivate()
            || !dkrQuickToTakeOffense()
            || !dkrAdeptAtDefense()
            || !dkrPolymorphIntoBird()
            || !dkrFightsWithSwordsDartsUchiNe()
            || !dkrCausesDiseaseOncePerDay()
            || !dkrSummonsTigersOncePerDay()
            || !dkrTigersArriveAndFight()
            || !dkrWuJenSpellcasters()
            || !dkrBambooGroveHomes()
            || !dkrThatchedHouses()
            || !dkrFemalesDefend()
            || !dkrVillageGuardTigers()
            || !dkrDislikeLoudNoises()
            || !dkrSpeaksThreeLanguages()
        )
            ++bad;
        // the stat block - the stat block pins, healthy values, each
        // condition false
    if (dkrFrequencyUncommon() != 1
            || dkrAppearMin() != 1
            || dkrAppearMax() != 10
            || dkrLairMultiplier() != 3
            || dkrAC() != 4
            || dkrMoveGround() != 6
            || dkrMoveFly() != 15
            || dkrMCA() != 1
            || dkrHDMin() != 2
            || dkrHDMax() != 4
            || dkrLairPct() != 10
            || dkrTreasureB() != 1
            || dkrAttackCount() != 1
            || dkrDmgMin() != 1
            || dkrDmgMax() != 6
            || dkrSpecialAttacksDisease() != 1
            || dkrSummonTigers() != 1
            || dkrImmuneToFear() != 1
            || dkrMRStandard() != 1
            || dkrIntAverage() != 1
            || dkrAlignmentChaoticNeutral() != 1
            || dkrSizeSmall() != 1
            || dkrPsionicNil() != 1
            || dkrModesNil() != 1
        )
            ++bad;
        // the xp ladder - the three-step xp ladder, healthy values, each
        // condition false
    if (dkrXP2Base() != 36
            || dkrXP2PerHP() != 2
            || dkrXP3Base() != 65
            || dkrXP3PerHP() != 3
            || dkrXP4Base() != 110
            || dkrXP4PerHP() != 4
        )
            ++bad;
        // the woodlanders - the build and the character, healthy values, each
        // condition false
    if (dkrOneFootTall() != 1
            || dkrWoodlandHills() != 1
            || dkrFearlessAndPrivate() != 1
            || dkrQuickToTakeOffense() != 1
            || dkrAdeptAtDefense() != 1
        )
            ++bad;
        // the powers - the polymorph, the disease, and the tigers, healthy
        // values, each condition false
    if (dkrPolymorphIntoBird() != 1
            || dkrPolymorphPerDay() != 3
            || dkrFightsWithSwordsDartsUchiNe() != 1
            || dkrCausesDiseaseOncePerDay() != 1
            || dkrDiseaseRangeFt() != 10
            || dkrSummonsTigersOncePerDay() != 1
            || dkrTigerSummonMin() != 1
            || dkrTigerSummonMax() != 3
            || dkrTigersArriveAndFight() != 1
            || dkrTigerArrivalDie() != 6
            || dkrWuJenSpellcasters() != 1
            || dkrWuJenChancePct() != 5
        )
            ++bad;
        // the village - the bamboo homes and the guards, healthy values, each
        // condition false
    if (dkrBambooGroveHomes() != 1
            || dkrThatchedHouses() != 1
            || dkrFemalesDefend() != 1
            || dkrFemaleBonusPct() != 50
            || dkrFemaleHD() != 1
            || dkrVillageGuardTigers() != 1
            || dkrVillageGuardChancePct() != 10
            || dkrVillageGuardTigersMin() != 1
            || dkrVillageGuardTigersMax() != 2
            || dkrDislikeLoudNoises() != 1
            || dkrSpeaksThreeLanguages() != 1
        )
            ++bad;
        printf("R730 OA monsters Shan Sao audit: bad %d\n", bad);
        if (bad) return 1;
    }
