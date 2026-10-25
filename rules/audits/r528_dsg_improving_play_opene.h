    // ---- R528 DSG improving-play opener audit ----
    // The DSG improving-play opener pins the expedition planning (the three
    // categories, the early-determined success, the scouting and rumor rules,
    // the preparation list, and the transport tradeoffs), the beasts of
    // burden (the mule 2,000/6,000 gp loads, the 50% chasm and steep-slope
    // persuasions, the 90% swim at 3 inches per round, the string-leader
    // rule, the 25% odor quartet, the 360/90-ft noise; and the dog 200/500 gp
    // loads at -4, the 50% stranger attack, the advanced-training discipline,
    // and the -2 darkness penalties), and the watercraft (the kayak
    // proficiency requirement, the larger-craft and collapsible tradeoffs,
    // and the waterborne scouting imperative).
    {
        using namespace rules;
        int bad = 0;
    if (dnipMuleFreeWtGp() != 2000
            || dnipMuleMaxWtGp() != 6000
            || dnipMuleOverHalfSpeedDiv() != 2
            || dnipMuleMaxWalkHours() != 8
            || dnipMuleChasmPct() != 50
            || dnipMuleChasmMaxFt() != 6
            || dnipMuleSteepPct() != 50
            || dnipMuleWaterPct() != 90
            || dnipMuleJumpHeightFt() != 6
            || dnipMuleSwimInches() != 3
            || dnipMuleOdorPct() != 25
            || dnipMuleNoiseFt() != 360
            || dnipMuleMuffledNoiseFt() != 90
            || dnipDogFreeWtGp() != 200
            || dnipDogMaxWtGp() != 500
            || dnipDogOverloadAtkPenalty() != 4
            || dnipDogWeightLbs() != 100
            || dnipDogStrangerPct() != 50
            || dnipDogDarkPenalty() != 2
            || !dnipThreeCategories()
            || !dnipSuccessDeterminedEarly()
            || !dnipLearnEverythingFirst()
            || !dnipRumorsHaveBasis()
            || !dnipScoutLightAvoidCombat()
            || !dnipScoutDuringAdventure()
            || !dnipExpeditionPlanningNeeds()
            || !dnipPrepareForTerrain()
            || !dnipExtraFoodCarried()
            || !dnipRoughGoingOnFoot()
            || !dnipWaterwaysEasyAccess()
            || !dnipWaterwaysDangerous()
            || !dnipMuleMostCommon()
            || !dnipMuleStairsAndFooting()
            || !dnipMuleStringLeader()
            || !dnipMuleOdorJittery()
            || !dnipDogWarDogVarieties()
            || !dnipDogTrainingRequired()
            || !dnipDogAdvancedDiscipline()
            || !dnipDogKeenSenses()
            || !dnipKayakMostNimble()
            || !dnipLargerCraftTradeoff()
            || !dnipCollapsibleTradeoff()
            || !dnipWaterScoutVital()
        )
            ++bad;
        // the mule load numbers: 2,000 gp free, 6,000 gp max at half speed
        // and eight hours, and the 50% six-foot chasm.
    if (dnipMuleFreeWtGp() != 2000
            || dnipMuleMaxWtGp() != 6000
            || dnipMuleOverHalfSpeedDiv() != 2
            || dnipMuleMaxWalkHours() != 8
            || dnipMuleChasmPct() != 50
            || dnipMuleChasmMaxFt() != 6
        )
            ++bad;
        // the mule action numbers: the 50% steep slope, the 90% swim with the
        // six-foot jump, the 3-inch swim, the 25% odor reactions, and the
        // 360/90-ft noise.
    if (dnipMuleSteepPct() != 50
            || dnipMuleWaterPct() != 90
            || dnipMuleJumpHeightFt() != 6
            || dnipMuleSwimInches() != 3
            || dnipMuleOdorPct() != 25
            || dnipMuleNoiseFt() != 360
            || dnipMuleMuffledNoiseFt() != 90
        )
            ++bad;
        // the dog numbers: 200 gp free and 500 gp max at -4, the 100-pound
        // war dog, the 50% stranger attack, and the -2 darkness penalties.
    if (dnipDogFreeWtGp() != 200
            || dnipDogMaxWtGp() != 500
            || dnipDogOverloadAtkPenalty() != 4
            || dnipDogWeightLbs() != 100
            || dnipDogStrangerPct() != 50
            || dnipDogDarkPenalty() != 2
        )
            ++bad;
        // the planning prose: the three categories, the rumor basis, the
        // light scouting, the extra food, the mule-string leader rule, the
        // kayak proficiency requirement, and the waterborne return-means
        // rule.
    if (dnipThreeCategories() != 1
            || dnipRumorsHaveBasis() != 1
            || dnipScoutLightAvoidCombat() != 1
            || dnipExtraFoodCarried() != 1
            || dnipMuleStringLeader() != 1
            || dnipKayakMostNimble() != 1
            || dnipWaterScoutVital() != 1
        )
            ++bad;
        printf("R528 DSG improving-play opener audit: bad %d\n", bad);
        if (bad) return 1;
    }
