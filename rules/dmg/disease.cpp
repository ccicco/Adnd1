// R-refactor: split from disease.h - definitions
#include "rules/dmg/disease.h"

int Disease::diseaseContractBasePercent() { return 2; }

int Disease::parasiteContractBasePercent() { return 3; }

int Disease::diseaseModCurrentlyAfflicted() { return 1; }

int Disease::diseaseModCrowding() { return 1; }

int Disease::diseaseModFilth() { return 1; }

int Disease::diseaseModOld() { return 2; }

int Disease::diseaseModMarshEnvironment() { return 2; }

int Disease::diseaseModHotMoist() { return 2; }

int Disease::diseaseModVenerable() { return 5; }

int Disease::diseaseModCarrierExposure() { return 10; }

int Disease::diseaseModCoolClimate() { return -1; }

int Disease::diseaseModColdHighMountains() { return -2; }

int Disease::diseaseModShipboardPastTwoWeeks() { return -2; }

int Disease::parasiteModFilth() { return 1; }

int Disease::parasiteModImproperlyCookedMeat() { return 2; }

int Disease::parasiteModPollutedWater() { return 5; }

int Disease::parasiteModSwampJungle() { return 5; }

int Disease::parasiteModCoolOrDesert() { return -1; }

int Disease::parasiteModColdOrCoolDesert() { return -1; }

bool Disease::diseaseWeeklyCheckWhenFavorable() { return true; }

bool Disease::diseaseCheckOnEachCarrierExposure() { return true; }

int Disease::diseaseAreaCount() { return 16; }

const char* Disease::diseaseAreaName(int idx) {
    static const char* const k[16] = {
        "blood/blood forming organs",
        "bones",
        "brain/nervous system",
        "cardiovascular-renal",
        "connective tissue",
        "ears",
        "eyes",
        "gastro-intestinal",
        "generative organs",
        "joints",
        "mucous membranes",
        "muscles",
        "nose-throat",
        "respiratory system",
        "skin",
        "urinary system"
    };
    if (idx < 0) idx = 0;
    if (idx > 15) idx = 15;
    return k[idx];
}

int Disease::diseaseAreaForD100(int d100) {
    static const int kLo[16] = {
        1, 4, 5, 6, 8, 10, 13, 19, 41, 43,
        49, 51, 53, 66, 86, 97
    };
    if (d100 < 1) d100 = 1;
    if (d100 > 100) d100 = 100;
    for (int i = 15; i >= 0; --i)
        if (d100 >= kLo[i]) return i;
    return 0;
}

int Disease::diseaseAcuteHi(int idx) {
    static const int k[16] = {
        3, 1, 6, 3, 1, 7, 7, 6, 2, 4,
        7, 5, 6, 6, 5, 6
    };
    if (idx < 0) idx = 0;
    if (idx > 15) idx = 15;
    return k[idx];
}

int Disease::diseaseChronicLo(int idx) {
    return diseaseAcuteHi(idx) + 1;
}

bool Disease::diseaseIsAcute(int idx, int d8) {
    return d8 <= diseaseAcuteHi(idx);
}

bool Disease::diseaseIsChronic(int idx, int d8) {
    return d8 >= diseaseChronicLo(idx);
}

int Disease::diseaseSeverityMildHi(int idx) {
    static const int k[16] = {
        2, 1, 2, 2, 1, 6, 5, 5, 3, 6,
        6, 5, 6, 5, 5, 5
    };
    if (idx < 0) idx = 0;
    if (idx > 15) idx = 15;
    return k[idx];
}

int Disease::diseaseSeveritySevereHi(int idx) {
    static const int k[16] = {
        5, 3, 5, 4, 3, 7, 7, 7, 7, 8,
        8, 7, 8, 7, 7, 7
    };
    if (idx < 0) idx = 0;
    if (idx > 15) idx = 15;
    return k[idx];
}

int Disease::diseaseSeverityTerminalHi(int idx) {
    static const int k[16] = {
        8, 8, 8, 8, 8, 8, 8, 8, 8, 0,
        0, 8, 0, 8, 8, 8
    };
    if (idx < 0) idx = 0;
    if (idx > 15) idx = 15;
    return k[idx];
}

int Disease::parasiteAreaCount() { return 6; }

const char* Disease::parasiteAreaName(int idx) {
    static const char* const k[6] = {
        "cardiovascular system",
        "intestines",
        "muscles",
        "respiratory system",
        "skin/hair",
        "stomach"
    };
    if (idx < 0) idx = 0;
    if (idx > 5) idx = 5;
    return k[idx];
}

int Disease::parasiteAreaForD100(int d100) {
    static const int kLo[6] = { 1, 11, 36, 41, 46, 76 };
    if (d100 < 1) d100 = 1;
    if (d100 > 100) d100 = 100;
    for (int i = 5; i >= 0; --i)
        if (d100 >= kLo[i]) return i;
    return 0;
}

int Disease::parasiteSeverityMildHi(int idx) {
    static const int k[6] = { 2, 2, 1, 1, 7, 2 };
    if (idx < 0) idx = 0;
    if (idx > 5) idx = 5;
    return k[idx];
}

int Disease::parasiteSeveritySevereHi(int idx) {
    static const int k[6] = { 5, 7, 3, 4, 8, 7 };
    if (idx < 0) idx = 0;
    if (idx > 5) idx = 5;
    return k[idx];
}

int Disease::parasiteSeverityTerminalHi(int idx) {
    static const int k[6] = { 8, 8, 8, 8, 0, 8 };
    if (idx < 0) idx = 0;
    if (idx > 5) idx = 5;
    return k[idx];
}

int Disease::diseaseMildWeeksMin() { return 1; }

int Disease::diseaseMildWeeksMax() { return 3; }

int Disease::diseaseSevereHitPointPercent() { return 50; }

int Disease::diseaseSevereDisabledWeeksMin() { return 1; }

int Disease::diseaseSevereDisabledWeeksMax() { return 2; }

int Disease::diseaseSevereMildRecoveryWeeksMin() { return 1; }

int Disease::diseaseSevereMildRecoveryWeeksMax() { return 2; }

int Disease::diseaseTerminalDaysMin() { return 1; }

int Disease::diseaseTerminalDaysMax() { return 12; }

DiseaseDurationUnit Disease::diseaseTerminalUnit(int idx) {
    // blood and bones: 1-12 weeks; brain: 1-12
    // hours; cardiovascular-renal: 1-12 days;
    // connective tissue: terminal treated as
    // chronic severe (no duration); ears and eyes:
    // function loss; gastro-intestinal and skin and
    // urinary: 1-12 weeks; generative organs,
    // muscles, respiratory: 1-12 months;
    // joints, mucous membranes, nose-throat: none
    static const DiseaseDurationUnit k[16] = {
        DUR_WEEKS, DUR_WEEKS, DUR_HOURS, DUR_DAYS,
        DUR_NONE, DUR_NONE, DUR_NONE, DUR_WEEKS,
        DUR_MONTHS, DUR_NONE, DUR_NONE, DUR_MONTHS,
        DUR_NONE, DUR_MONTHS, DUR_WEEKS, DUR_WEEKS
    };
    if (idx < 0) idx = 0;
    if (idx > 15) idx = 15;
    return k[idx];
}

bool Disease::diseaseHasTerminalColumn(int idx) {
    return diseaseSeverityTerminalHi(idx) != 0;
}

bool Disease::diseaseTerminalIsFunctionLoss(int idx) {
    return idx == 5 || idx == 6;
}

int Disease::diseaseEyesBlindBothChance() { return 50; }

bool Disease::diseaseTerminalTreatedAsChronicSevere( int idx) {
    return idx == 4;
}

int Disease::diseaseBloodWeeklyStrLoss() { return 1; }

int Disease::diseaseBloodWeeklyConLoss() { return 1; }

int Disease::diseaseBrainIntLoss() { return 1; }

int Disease::diseaseBrainDexLoss() { return 1; }

int Disease::diseaseConnectiveMonthlyLoss() { return 1; }

int Disease::diseaseGastroStrConLoss() { return 1; }

int Disease::diseaseJointsDexLoss() { return 1; }

int Disease::diseaseMucousConLoss() { return 1; }

int Disease::diseaseMuscleStrDexLoss() { return 1; }

int Disease::diseaseMuscleSeverePermanentChance() {
    return 25;
}

int Disease::diseaseNoseThroatSevereConLossChance() {
    return 10;
}

int Disease::diseaseRespiratoryLossChance() { return 10; }

int Disease::diseaseSkinSevereChaLossChance() { return 10; }

int Disease::diseaseSkinChronicMildChance() { return 10; }

int Disease::diseaseSkinChronicSevereChance() { return 25; }

int Disease::diseaseUrinaryLossChance() { return 20; }

int Disease::diseaseConRollAdjust(int con) {
    if (con <= 2) return 2;
    if (con <= 5) return 1;
    if (con <= 9) return 0;
    if (con <= 12) return -1;
    if (con <= 15) return -2;
    if (con <= 17) return -3;
    return -4;
}

int Disease::diseaseAdjustChronicDisease() { return 1; }

int Disease::diseaseAdjustSevereInfestation() { return 1; }

int Disease::diseaseAdjustLowHitPoints() { return 1; }

bool Disease::diseaseAdjustmentsApplyToParasites() {
    return false;
}

bool Disease::diseaseRollMeansNoContraction(int die) {
    return die <= 0;
}

int Disease::diseaseDeathRelapseChance() { return 90; }

bool Disease::diseasePermanentLossFixedByCurative() {
    return false;
}
