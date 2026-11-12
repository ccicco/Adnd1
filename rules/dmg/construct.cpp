// R-refactor: split from construct.h - definitions
#include "rules/dmg/construct.h"

int Construct::miningGroupCount() { return 8; }

int Construct::miningCubicFeetPer8h(int group, int rock) {
    // cubic feet of rock per 8 hours of
    // labor per miner, the print table
    if (group < 0) group = 0;
    if (group > 7) group = 7;
    if (rock < 0) rock = 0;
    if (rock > 2) rock = 2;
    static const int t[24] = {
        75, 50, 25,
        80, 60, 30,
        85, 65, 30,
        90, 70, 35,
        150, 100, 50,
        250, 150, 75,
        300, 200, 100,
        500, 350, 175,
    };
    return t[group * 3 + rock];
}

int Construct::miningVolumeCubicFeet(int group, int rock, int miners) {
    // each extra miner adds an appropriate
    // additional volume (the shaft capacity
    // is the caller concern)
    if (miners < 0) miners = 0;
    return miningCubicFeetPer8h(group, rock) * miners;
}

int Construct::shaftMaxMiners(int group) {
    // max miners per 10-foot wide shaft
    if (group < 0) group = 0;
    if (group > 4) group = 4;
    static const int t[5] = { 16, 12, 8, 6, 4 };
    return t[group];
}

int Construct::shaftWidthFeet() { return 10; }

int Construct::shaftPeakFeet() { return 16; }

int Construct::constructionHoursPerDay() { return 24; }

int Construct::workerMaxHoursPerDay() { return 8; }

int Construct::maxShiftsPerDay() { return 3; }

int Construct::naturalCaveChancePct(int rock) {
    // limestone 1 in 10, other sedimentary
    // 1 in 50, lava 1 in 20, other igneous
    // 1 in 100
    if (rock < 0) rock = 0;
    if (rock > 3) rock = 3;
    static const int t[4] = { 10, 2, 5, 1 };
    return t[rock];
}

int Construct::slaveGuardPerWorkers() {
    // 1 comparable guard per 4 workers is
    // about the minimum
    return 4;
}

int Construct::slaveEfficiencyMinPct() { return 50; }

int Construct::slaveEfficiencyMaxPct() { return 80; }

int Construct::slaveEfficiencyPct(int workersPerForeman) {
    // 50 to 80 percent of normal, by the
    // foreman ratio: 1 per 16 is 50, 1 per
    // 12 is 60, 1 per 8 is 70, 1 per 4 is
    // 80; ratios below 1 per 4 stay at 80
    if (workersPerForeman < 1) workersPerForeman = 1;
    if (workersPerForeman >= 16) return 50;
    if (workersPerForeman >= 12) return 60;
    if (workersPerForeman >= 8) return 70;
    return 80;
}

int Construct::ditchCrewMin() { return 3; }

int Construct::ditchCrewMax() { return 4; }

int Construct::ditchWeeks() { return 6; }

int Construct::heavyClayTimeFactor() { return 2; }

int Construct::stoneFortressWeeksPer10FootCube() { return 1; }

int Construct::stoneRateFactor(int costPct) {
    // 150 percent of the expenditure
    // doubles the construction rate, 250
    // percent triples it - the maximum
    if (costPct >= 250) return 3;
    if (costPct >= 150) return 2;
    return 1;
}

int Construct::stoneBuildingMonths() { return 4; }

int Construct::woodBuildingMonths() { return 2; }

int Construct::hoardingsFeetPerDay() { return 10; }

int Construct::castleYears(int kind) {
    // the rough estimate years
    if (kind < 0) kind = 0;
    if (kind > 3) kind = 3;
    static const int t[4] = { 1, 2, 3, 5 };
    return t[kind];
}

int Construct::castleExtraMonthsMin(int kind) {
    // the low edge of the extra months
    if (kind < 0) kind = 0;
    if (kind > 3) kind = 3;
    static const int t[4] = { 2, 1, 2, 1 };
    return t[kind];
}

int Construct::castleExtraMonthsMax(int kind) {
    // the high edge of the extra months
    if (kind < 0) kind = 0;
    if (kind > 3) kind = 3;
    static const int t[4] = { 8, 6, 8, 12 };
    return t[kind];
}

int Construct::citizenLaborTimePct() {
    // willing citizens reduce the time
    // by 50 percent
    return 50;
}

int Construct::constructionItemCount() { return 44; }

int Construct::constructionCost(int item) {
    // the gold piece cost, the print
    // order
    if (item < 0) item = 0;
    if (item > 43) item = 43;
    static const int t[44] = {
        3, 5, 4000, 300, 50, 20, 500,
        200, 15, 10, 100, 100, 50, 2, 10,
        25, 400, 3, 2000, 10,
        100, 6, 10, 250, 10, 100, 10, 25,
        4, 500, 100, 50, 10,
        850, 1350, 1600, 600, 900, 1200,
        100, 500, 1000, 7, 10,
    };
    return t[item];
}

int Construct::doorIronAdjustGpPerSqFt() { return 2; }

int Construct::doorSecretLargerGpPerSqFt() { return 5; }

int Construct::doorTrapAdjustSpPerSqFt() { return 1; }

int Construct::doorWoodenAdjustSpPerSqFt() { return 2; }

int Construct::doorReinforcedAdjustSpPerSqFt() { return 5; }

int Construct::drawbridgeAdjustGpPerSqFt() { return 2; }

int Construct::portcullisAdjustGpPerSqFt() { return 2; }

int Construct::buildingStoneCoursePct() { return 10; }

int Construct::buildingStoneCostCourses(int baseGp, int courses) {
    // +10 percent of the initial cost per
    // extra course of stone (1 foot of
    // thickness); the worked example: 500
    // gp at 10 courses (10-foot walls) is
    // 950 gp
    if (baseGp < 0) baseGp = 0;
    if (courses < 1) courses = 1;
    return baseGp + baseGp / 10 * (courses - 1);
}

int Construct::tunnelCostFactor(int ground) {
    // soft earth 1x, hard earth +100
    // percent (2x), solid rock 500
    // percent (5x) of the shown figure
    if (ground < 0) ground = 0;
    if (ground > 2) ground = 2;
    static const int t[3] = { 1, 2, 5 };
    return t[ground];
}

int Construct::rampartAboveDitchCostPct() {
    // a rampart built immediately above
    // one side of a ditch costs only 20
    // percent of the shown amount
    return 20;
}

int Construct::battlementSectionFeet() { return 14; }

int Construct::battlementMerlons() { return 2; }

int Construct::battlementMerlonWidthFeet() { return 4; }

int Construct::battlementEmbrasures() { return 2; }

int Construct::battlementEmbrasureWidthFeet() { return 3; }

int Construct::buttressSectionsPer20Feet() { return 3; }

int Construct::siegeDeviceCount() { return 12; }

int Construct::siegeDeviceCost(int device) {
    // the gold piece cost, the print
    // order
    if (device < 0) device = 0;
    if (device > 11) device = 11;
    static const int t[12] = {
        75, 200, 150, 50, 350, 150,
        15, 500, 20, 800, 500, 500,
    };
    return t[device];
}
