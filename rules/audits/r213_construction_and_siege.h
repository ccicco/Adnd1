    // ---- R213: the construction and siege economics audit ----
    // DMG pp.106-108: the mining tables,
    // the construction time pins, the
    // constructions cost table, and the
    // siege engine costs.
    {
        int bad = 0;
        // the mining table: every cell
        if (rules::miningGroupCount() != 8
            || rules::MG_COUNT != 8
            || rules::MG_GNOLL_HALFLING_HUMAN != 0
            || rules::MG_STONE_GIANT != 7
            || rules::MRK_VERY_SOFT != 0
            || rules::MRK_SOFT != 1
            || rules::MRK_HARD != 2) ++bad;
        static const int kMine[24] = {
            75, 50, 25,
            80, 60, 30,
            85, 65, 30,
            90, 70, 35,
            150, 100, 50,
            250, 150, 75,
            300, 200, 100,
            500, 350, 175,
        };
        for (int g = 0; g < 8; ++g)
            for (int r = 0; r < 3; ++r)
                if (rules::miningCubicFeetPer8h(g, r)
                        != kMine[g * 3 + r]) ++bad;
        if (rules::miningCubicFeetPer8h(
                rules::MG_STONE_GIANT, rules::MRK_HARD)
                != 175 ||
            rules::miningCubicFeetPer8h(0, 0) != 75 ||
            rules::miningCubicFeetPer8h(-5, 9) != 25) ++bad;
        // the multiple-workers volume: linear
        if (rules::miningVolumeCubicFeet(
                rules::MG_HILL_GIANT, rules::MRK_SOFT, 3)
                != 450 ||
            rules::miningVolumeCubicFeet(
                rules::MG_HILL_GIANT, rules::MRK_SOFT, 0)
                != 0 ||
            rules::miningVolumeCubicFeet(
                rules::MG_HILL_GIANT, rules::MRK_SOFT, -7)
                != 0 ||
            rules::miningVolumeCubicFeet(
                rules::MG_OGRE, rules::MRK_VERY_SOFT, 4)
                != 600) ++bad;
        // the shaft capacity and the shifts
        if (rules::SG_COUNT != 5
            || rules::SG_SMALL != 0
            || rules::SG_MAN != 1
            || rules::SG_GNOLL != 2
            || rules::SG_OGRE != 3
            || rules::SG_GIANT_ANY != 4) ++bad;
        static const int kShaft[5] = { 16, 12, 8, 6, 4 };
        for (int s = 0; s < 5; ++s)
            if (rules::shaftMaxMiners(s) != kShaft[s]) ++bad;
        if (rules::shaftMaxMiners(-1) != 16 ||
            rules::shaftMaxMiners(9) != 4 ||
            rules::shaftWidthFeet() != 10 ||
            rules::shaftPeakFeet() != 16 ||
            rules::constructionHoursPerDay() != 24 ||
            rules::workerMaxHoursPerDay() != 8 ||
            rules::maxShiftsPerDay() != 3) ++bad;
        // the natural cave area chances
        static const int kNat[4] = { 10, 2, 5, 1 };
        for (int r = 0; r < 4; ++r)
            if (rules::naturalCaveChancePct(r)
                    != kNat[r]) ++bad;
        if (rules::NR_COUNT != 4 ||
            rules::NR_LIMESTONE_VERY_SOFT != 0 ||
            rules::NR_OTHER_SEDIMENTARY_SOFT != 1 ||
            rules::NR_LAVA_HARD != 2 ||
            rules::NR_OTHER_IGNEOUS_HARD != 3 ||
            rules::naturalCaveChancePct(-3) != 10 ||
            rules::naturalCaveChancePct(9) != 1) ++bad;
        // the slave or unwilling labor
        if (rules::slaveGuardPerWorkers() != 4 ||
            rules::slaveEfficiencyMinPct() != 50 ||
            rules::slaveEfficiencyMaxPct() != 80 ||
            rules::slaveEfficiencyPct(16) != 50 ||
            rules::slaveEfficiencyPct(20) != 50 ||
            rules::slaveEfficiencyPct(12) != 60 ||
            rules::slaveEfficiencyPct(15) != 60 ||
            rules::slaveEfficiencyPct(10) != 70 ||
            rules::slaveEfficiencyPct(8) != 70 ||
            rules::slaveEfficiencyPct(5) != 80 ||
            rules::slaveEfficiencyPct(4) != 80 ||
            rules::slaveEfficiencyPct(1) != 80 ||
            rules::slaveEfficiencyPct(0) != 80 ||
            rules::slaveEfficiencyPct(-3) != 80) ++bad;
        // the construction time pins
        if (rules::ditchCrewMin() != 3 ||
            rules::ditchCrewMax() != 4 ||
            rules::ditchWeeks() != 6 ||
            rules::heavyClayTimeFactor() != 2 ||
            rules::stoneFortressWeeksPer10FootCube() != 1 ||
            rules::stoneRateFactor(100) != 1 ||
            rules::stoneRateFactor(149) != 1 ||
            rules::stoneRateFactor(150) != 2 ||
            rules::stoneRateFactor(200) != 2 ||
            rules::stoneRateFactor(249) != 2 ||
            rules::stoneRateFactor(250) != 3 ||
            rules::stoneRateFactor(400) != 3 ||
            rules::stoneRateFactor(-5) != 1 ||
            rules::stoneBuildingMonths() != 4 ||
            rules::woodBuildingMonths() != 2 ||
            rules::hoardingsFeetPerDay() != 10) ++bad;
        // the castle estimates
        if (rules::CK_COUNT != 4 ||
            rules::CK_MOAT_HOUSE_SHELL_KEEP_SMALL != 0 ||
            rules::CK_LARGE_CONCENTRIC_WALLING_TOWN != 3) ++bad;
        static const int kYears[4] = { 1, 2, 3, 5 };
        static const int kMoLo[4] = { 2, 1, 2, 1 };
        static const int kMoHi[4] = { 8, 6, 8, 12 };
        for (int k = 0; k < 4; ++k)
            if (rules::castleYears(k) != kYears[k] ||
                rules::castleExtraMonthsMin(k) != kMoLo[k] ||
                rules::castleExtraMonthsMax(k) != kMoHi[k]) ++bad;
        if (rules::citizenLaborTimePct() != 50) ++bad;
        // the constructions cost table: every
        // row
        if (rules::constructionItemCount() != 44
            || rules::CI_COUNT != 44
            || rules::CI_ARROW_SLIT != 0
            || rules::CI_WINDOW_SHUTTERED_BARRED != 43
            || rules::CI_BARBICAN != 2
            || rules::CI_WALL_CURTAIN != 41
            || rules::CI_TOWER_ROUND_20 != 33) ++bad;
        static const int kCost[44] = {
            3, 5, 4000, 300, 50, 20, 500,
            200, 15, 10, 100, 100, 50, 2, 10,
            25, 400, 3, 2000, 10,
            100, 6, 10, 250, 10, 100, 10, 25,
            4, 500, 100, 50, 10,
            850, 1350, 1600, 600, 900, 1200,
            100, 500, 1000, 7, 10,
        };
        for (int i = 0; i < 44; ++i)
            if (rules::constructionCost(i) != kCost[i]) ++bad;
        if (rules::constructionCost(rules::CI_BARBICAN)
                != 4000 ||
            rules::constructionCost(rules::CI_GATEHOUSE_STONE)
                != 2000 ||
            rules::constructionCost(rules::CI_TOWER_ROUND_20)
                != 850 ||
            rules::constructionCost(rules::CI_WALL_CURTAIN)
                != 1000 ||
            rules::constructionCost(rules::CI_PORTCULLIS)
                != 500 ||
            rules::constructionCost(rules::CI_BUILDING_STONE)
                != 500 ||
            rules::constructionCost(rules::CI_BUILDING_WOOD)
                != 200 ||
            rules::constructionCost(rules::CI_MURDER_HOLE)
                != 10 ||
            rules::constructionCost(rules::CI_PIT)
                != 4 ||
            rules::constructionCost(rules::CI_DOOR_TRAP)
                != 2 ||
            rules::constructionCost(
                rules::CI_WINDOW_SHUTTERED) != 7) ++bad;
        if (rules::constructionCost(-3)
                != rules::constructionCost(0) ||
            rules::constructionCost(99)
                != rules::constructionCost(43)) ++bad;
        // the per-square-foot adjustments
        if (rules::doorIronAdjustGpPerSqFt() != 2 ||
            rules::doorSecretLargerGpPerSqFt() != 5 ||
            rules::doorTrapAdjustSpPerSqFt() != 1 ||
            rules::doorWoodenAdjustSpPerSqFt() != 2 ||
            rules::doorReinforcedAdjustSpPerSqFt() != 5 ||
            rules::drawbridgeAdjustGpPerSqFt() != 2 ||
            rules::portcullisAdjustGpPerSqFt() != 2) ++bad;
        // the stone course formula
        if (rules::buildingStoneCoursePct() != 10 ||
            rules::buildingStoneCostCourses(500, 1) != 500 ||
            rules::buildingStoneCostCourses(500, 10) != 950 ||
            rules::buildingStoneCostCourses(500, 2) != 550 ||
            rules::buildingStoneCostCourses(200, 3) != 240 ||
            rules::buildingStoneCostCourses(500, 0) != 500 ||
            rules::buildingStoneCostCourses(500, -4) != 500) ++bad;
        // the tunnel ground factors
        if (rules::TG_COUNT != 3 ||
            rules::TG_SOFT_EARTH != 0 ||
            rules::TG_HARD_EARTH != 1 ||
            rules::TG_SOLID_ROCK != 2 ||
            rules::tunnelCostFactor(0) != 1 ||
            rules::tunnelCostFactor(1) != 2 ||
            rules::tunnelCostFactor(2) != 5 ||
            rules::tunnelCostFactor(9) != 5 ||
            rules::tunnelCostFactor(-1) != 1) ++bad;
        // the combination clauses
        if (rules::rampartAboveDitchCostPct() != 20 ||
            rules::battlementSectionFeet() != 14 ||
            rules::battlementMerlons() != 2 ||
            rules::battlementMerlonWidthFeet() != 4 ||
            rules::battlementEmbrasures() != 2 ||
            rules::battlementEmbrasureWidthFeet() != 3 ||
            rules::buttressSectionsPer20Feet() != 3) ++bad;
        // the siege engine costs
        if (rules::siegeDeviceCount() != 12
            || rules::SD_COUNT != 12
            || rules::SD_BALLISTA != 0
            || rules::SD_TREBUCHET != 11) ++bad;
        static const int kEng[12] = {
            75, 200, 150, 50, 350, 150,
            15, 500, 20, 800, 500, 500,
        };
        for (int d = 0; d < 12; ++d)
            if (rules::siegeDeviceCost(d) != kEng[d]) ++bad;
        if (rules::siegeDeviceCost(rules::SD_BALLISTA) != 75 ||
            rules::siegeDeviceCost(rules::SD_TREBUCHET)
                != 500 ||
            rules::siegeDeviceCost(rules::SD_SIEGE_TOWER)
                != 800 ||
            rules::siegeDeviceCost(rules::SD_MANTLET)
                != 15 ||
            rules::siegeDeviceCost(-1)
                != rules::siegeDeviceCost(0) ||
            rules::siegeDeviceCost(12)
                != rules::siegeDeviceCost(11)) ++bad;
        printf("R213 construction and siege economics audit: bad %d\n", bad);
        if (bad) return 1;
    }
