    // ---- R213: the construction and siege economics audit ----
    // DMG pp.106-108: the mining tables,
    // the construction time pins, the
    // constructions cost table, and the
    // siege engine costs.
    {
        Construct construct;
        int bad = 0;
        // the mining table: every cell
        if (construct.miningGroupCount() != 8
            || MG_COUNT != 8
            || MG_GNOLL_HALFLING_HUMAN != 0
            || MG_STONE_GIANT != 7
            || MRK_VERY_SOFT != 0
            || MRK_SOFT != 1
            || MRK_HARD != 2) ++bad;
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
                if (construct.miningCubicFeetPer8h(g, r)
                        != kMine[g * 3 + r]) ++bad;
        if (construct.miningCubicFeetPer8h(
                MG_STONE_GIANT, MRK_HARD)
                != 175 ||
            construct.miningCubicFeetPer8h(0, 0) != 75 ||
            construct.miningCubicFeetPer8h(-5, 9) != 25) ++bad;
        // the multiple-workers volume: linear
        if (construct.miningVolumeCubicFeet(
                MG_HILL_GIANT, MRK_SOFT, 3)
                != 450 ||
            construct.miningVolumeCubicFeet(
                MG_HILL_GIANT, MRK_SOFT, 0)
                != 0 ||
            construct.miningVolumeCubicFeet(
                MG_HILL_GIANT, MRK_SOFT, -7)
                != 0 ||
            construct.miningVolumeCubicFeet(
                MG_OGRE, MRK_VERY_SOFT, 4)
                != 600) ++bad;
        // the shaft capacity and the shifts
        if (SG_COUNT != 5
            || SG_SMALL != 0
            || SG_MAN != 1
            || SG_GNOLL != 2
            || SG_OGRE != 3
            || SG_GIANT_ANY != 4) ++bad;
        static const int kShaft[5] = { 16, 12, 8, 6, 4 };
        for (int s = 0; s < 5; ++s)
            if (construct.shaftMaxMiners(s) != kShaft[s]) ++bad;
        if (construct.shaftMaxMiners(-1) != 16 ||
            construct.shaftMaxMiners(9) != 4 ||
            construct.shaftWidthFeet() != 10 ||
            construct.shaftPeakFeet() != 16 ||
            construct.constructionHoursPerDay() != 24 ||
            construct.workerMaxHoursPerDay() != 8 ||
            construct.maxShiftsPerDay() != 3) ++bad;
        // the natural cave area chances
        static const int kNat[4] = { 10, 2, 5, 1 };
        for (int r = 0; r < 4; ++r)
            if (construct.naturalCaveChancePct(r)
                    != kNat[r]) ++bad;
        if (NR_COUNT != 4 ||
            NR_LIMESTONE_VERY_SOFT != 0 ||
            NR_OTHER_SEDIMENTARY_SOFT != 1 ||
            NR_LAVA_HARD != 2 ||
            NR_OTHER_IGNEOUS_HARD != 3 ||
            construct.naturalCaveChancePct(-3) != 10 ||
            construct.naturalCaveChancePct(9) != 1) ++bad;
        // the slave or unwilling labor
        if (construct.slaveGuardPerWorkers() != 4 ||
            construct.slaveEfficiencyMinPct() != 50 ||
            construct.slaveEfficiencyMaxPct() != 80 ||
            construct.slaveEfficiencyPct(16) != 50 ||
            construct.slaveEfficiencyPct(20) != 50 ||
            construct.slaveEfficiencyPct(12) != 60 ||
            construct.slaveEfficiencyPct(15) != 60 ||
            construct.slaveEfficiencyPct(10) != 70 ||
            construct.slaveEfficiencyPct(8) != 70 ||
            construct.slaveEfficiencyPct(5) != 80 ||
            construct.slaveEfficiencyPct(4) != 80 ||
            construct.slaveEfficiencyPct(1) != 80 ||
            construct.slaveEfficiencyPct(0) != 80 ||
            construct.slaveEfficiencyPct(-3) != 80) ++bad;
        // the construction time pins
        if (construct.ditchCrewMin() != 3 ||
            construct.ditchCrewMax() != 4 ||
            construct.ditchWeeks() != 6 ||
            construct.heavyClayTimeFactor() != 2 ||
            construct.stoneFortressWeeksPer10FootCube() != 1 ||
            construct.stoneRateFactor(100) != 1 ||
            construct.stoneRateFactor(149) != 1 ||
            construct.stoneRateFactor(150) != 2 ||
            construct.stoneRateFactor(200) != 2 ||
            construct.stoneRateFactor(249) != 2 ||
            construct.stoneRateFactor(250) != 3 ||
            construct.stoneRateFactor(400) != 3 ||
            construct.stoneRateFactor(-5) != 1 ||
            construct.stoneBuildingMonths() != 4 ||
            construct.woodBuildingMonths() != 2 ||
            construct.hoardingsFeetPerDay() != 10) ++bad;
        // the castle estimates
        if (CK_COUNT != 4 ||
            CK_MOAT_HOUSE_SHELL_KEEP_SMALL != 0 ||
            CK_LARGE_CONCENTRIC_WALLING_TOWN != 3) ++bad;
        static const int kYears[4] = { 1, 2, 3, 5 };
        static const int kMoLo[4] = { 2, 1, 2, 1 };
        static const int kMoHi[4] = { 8, 6, 8, 12 };
        for (int k = 0; k < 4; ++k)
            if (construct.castleYears(k) != kYears[k] ||
                construct.castleExtraMonthsMin(k) != kMoLo[k] ||
                construct.castleExtraMonthsMax(k) != kMoHi[k]) ++bad;
        if (construct.citizenLaborTimePct() != 50) ++bad;
        // the constructions cost table: every
        // row
        if (construct.constructionItemCount() != 44
            || CI_COUNT != 44
            || CI_ARROW_SLIT != 0
            || CI_WINDOW_SHUTTERED_BARRED != 43
            || CI_BARBICAN != 2
            || CI_WALL_CURTAIN != 41
            || CI_TOWER_ROUND_20 != 33) ++bad;
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
            if (construct.constructionCost(i) != kCost[i]) ++bad;
        if (construct.constructionCost(CI_BARBICAN)
                != 4000 ||
            construct.constructionCost(CI_GATEHOUSE_STONE)
                != 2000 ||
            construct.constructionCost(CI_TOWER_ROUND_20)
                != 850 ||
            construct.constructionCost(CI_WALL_CURTAIN)
                != 1000 ||
            construct.constructionCost(CI_PORTCULLIS)
                != 500 ||
            construct.constructionCost(CI_BUILDING_STONE)
                != 500 ||
            construct.constructionCost(CI_BUILDING_WOOD)
                != 200 ||
            construct.constructionCost(CI_MURDER_HOLE)
                != 10 ||
            construct.constructionCost(CI_PIT)
                != 4 ||
            construct.constructionCost(CI_DOOR_TRAP)
                != 2 ||
            construct.constructionCost(
                CI_WINDOW_SHUTTERED) != 7) ++bad;
        if (construct.constructionCost(-3)
                != construct.constructionCost(0) ||
            construct.constructionCost(99)
                != construct.constructionCost(43)) ++bad;
        // the per-square-foot adjustments
        if (construct.doorIronAdjustGpPerSqFt() != 2 ||
            construct.doorSecretLargerGpPerSqFt() != 5 ||
            construct.doorTrapAdjustSpPerSqFt() != 1 ||
            construct.doorWoodenAdjustSpPerSqFt() != 2 ||
            construct.doorReinforcedAdjustSpPerSqFt() != 5 ||
            construct.drawbridgeAdjustGpPerSqFt() != 2 ||
            construct.portcullisAdjustGpPerSqFt() != 2) ++bad;
        // the stone course formula
        if (construct.buildingStoneCoursePct() != 10 ||
            construct.buildingStoneCostCourses(500, 1) != 500 ||
            construct.buildingStoneCostCourses(500, 10) != 950 ||
            construct.buildingStoneCostCourses(500, 2) != 550 ||
            construct.buildingStoneCostCourses(200, 3) != 240 ||
            construct.buildingStoneCostCourses(500, 0) != 500 ||
            construct.buildingStoneCostCourses(500, -4) != 500) ++bad;
        // the tunnel ground factors
        if (TG_COUNT != 3 ||
            TG_SOFT_EARTH != 0 ||
            TG_HARD_EARTH != 1 ||
            TG_SOLID_ROCK != 2 ||
            construct.tunnelCostFactor(0) != 1 ||
            construct.tunnelCostFactor(1) != 2 ||
            construct.tunnelCostFactor(2) != 5 ||
            construct.tunnelCostFactor(9) != 5 ||
            construct.tunnelCostFactor(-1) != 1) ++bad;
        // the combination clauses
        if (construct.rampartAboveDitchCostPct() != 20 ||
            construct.battlementSectionFeet() != 14 ||
            construct.battlementMerlons() != 2 ||
            construct.battlementMerlonWidthFeet() != 4 ||
            construct.battlementEmbrasures() != 2 ||
            construct.battlementEmbrasureWidthFeet() != 3 ||
            construct.buttressSectionsPer20Feet() != 3) ++bad;
        // the siege engine costs
        if (construct.siegeDeviceCount() != 12
            || SD_COUNT != 12
            || SD_BALLISTA != 0
            || SD_TREBUCHET != 11) ++bad;
        static const int kEng[12] = {
            75, 200, 150, 50, 350, 150,
            15, 500, 20, 800, 500, 500,
        };
        for (int d = 0; d < 12; ++d)
            if (construct.siegeDeviceCost(d) != kEng[d]) ++bad;
        if (construct.siegeDeviceCost(SD_BALLISTA) != 75 ||
            construct.siegeDeviceCost(SD_TREBUCHET)
                != 500 ||
            construct.siegeDeviceCost(SD_SIEGE_TOWER)
                != 800 ||
            construct.siegeDeviceCost(SD_MANTLET)
                != 15 ||
            construct.siegeDeviceCost(-1)
                != construct.siegeDeviceCost(0) ||
            construct.siegeDeviceCost(12)
                != construct.siegeDeviceCost(11)) ++bad;
        printf("R213 construction and siege economics audit: bad %d\n", bad);
        if (bad) return 1;
    }
