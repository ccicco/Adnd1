// R-refactor: split from disease.h - definitions
#include "rules/dmg/disease.h"

int Disease::contractBasePercent() { return 2; }

int Disease::parasiteContractBasePercent() { return 3; }

int Disease::modCurrentlyAfflicted() { return 1; }

int Disease::modCrowding() { return 1; }

int Disease::modFilth() { return 1; }

int Disease::modOld() { return 2; }

int Disease::modMarshEnvironment() { return 2; }

int Disease::modHotMoist() { return 2; }

int Disease::modVenerable() { return 5; }

int Disease::modCarrierExposure() { return 10; }

int Disease::modCoolClimate() { return -1; }

int Disease::modColdHighMountains() { return -2; }

int Disease::modShipboardPastTwoWeeks() { return -2; }

int Disease::parasiteModFilth() { return 1; }

int Disease::parasiteModImproperlyCookedMeat() { return 2; }

int Disease::parasiteModPollutedWater() { return 5; }

int Disease::parasiteModSwampJungle() { return 5; }

int Disease::parasiteModCoolOrDesert() { return -1; }

int Disease::parasiteModColdOrCoolDesert() { return -1; }

bool Disease::weeklyCheckWhenFavorable() { return true; }

bool Disease::checkOnEachCarrierExposure() { return true; }

int Disease::areaCount() { return 16; }

const char* Disease::areaName(int idx) {
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

int Disease::areaForD100(int d100) {
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

int Disease::acuteHi(int idx) {
    static const int k[16] = {
        3, 1, 6, 3, 1, 7, 7, 6, 2, 4,
        7, 5, 6, 6, 5, 6
    };
    if (idx < 0) idx = 0;
    if (idx > 15) idx = 15;
    return k[idx];
}

int Disease::chronicLo(int idx) {
    return acuteHi(idx) + 1;
}

bool Disease::isAcute(int idx, int d8) {
    return d8 <= acuteHi(idx);
}

bool Disease::isChronic(int idx, int d8) {
    return d8 >= chronicLo(idx);
}

int Disease::severityMildHi(int idx) {
    static const int k[16] = {
        2, 1, 2, 2, 1, 6, 5, 5, 3, 6,
        6, 5, 6, 5, 5, 5
    };
    if (idx < 0) idx = 0;
    if (idx > 15) idx = 15;
    return k[idx];
}

int Disease::severitySevereHi(int idx) {
    static const int k[16] = {
        5, 3, 5, 4, 3, 7, 7, 7, 7, 8,
        8, 7, 8, 7, 7, 7
    };
    if (idx < 0) idx = 0;
    if (idx > 15) idx = 15;
    return k[idx];
}

int Disease::severityTerminalHi(int idx) {
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

int Disease::mildWeeksMin() { return 1; }

int Disease::mildWeeksMax() { return 3; }

int Disease::severeHitPointPercent() { return 50; }

int Disease::severeDisabledWeeksMin() { return 1; }

int Disease::severeDisabledWeeksMax() { return 2; }

int Disease::severeMildRecoveryWeeksMin() { return 1; }

int Disease::severeMildRecoveryWeeksMax() { return 2; }

int Disease::terminalDaysMin() { return 1; }

int Disease::terminalDaysMax() { return 12; }

DiseaseDurationUnit Disease::terminalUnit(int idx) {
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

bool Disease::hasTerminalColumn(int idx) {
    return severityTerminalHi(idx) != 0;
}

bool Disease::terminalIsFunctionLoss(int idx) {
    return idx == 5 || idx == 6;
}

int Disease::eyesBlindBothChance() { return 50; }

bool Disease::terminalTreatedAsChronicSevere( int idx) {
    return idx == 4;
}

int Disease::bloodWeeklyStrLoss() { return 1; }

int Disease::bloodWeeklyConLoss() { return 1; }

int Disease::brainIntLoss() { return 1; }

int Disease::brainDexLoss() { return 1; }

int Disease::connectiveMonthlyLoss() { return 1; }

int Disease::gastroStrConLoss() { return 1; }

int Disease::jointsDexLoss() { return 1; }

int Disease::mucousConLoss() { return 1; }

int Disease::muscleStrDexLoss() { return 1; }

int Disease::muscleSeverePermanentChance() {
    return 25;
}

int Disease::noseThroatSevereConLossChance() {
    return 10;
}

int Disease::respiratoryLossChance() { return 10; }

int Disease::skinSevereChaLossChance() { return 10; }

int Disease::skinChronicMildChance() { return 10; }

int Disease::skinChronicSevereChance() { return 25; }

int Disease::urinaryLossChance() { return 20; }

int Disease::conRollAdjust(int con) {
    if (con <= 2) return 2;
    if (con <= 5) return 1;
    if (con <= 9) return 0;
    if (con <= 12) return -1;
    if (con <= 15) return -2;
    if (con <= 17) return -3;
    return -4;
}

int Disease::adjustChronicDisease() { return 1; }

int Disease::adjustSevereInfestation() { return 1; }

int Disease::adjustLowHitPoints() { return 1; }

bool Disease::adjustmentsApplyToParasites() {
    return false;
}

bool Disease::rollMeansNoContraction(int die) {
    return die <= 0;
}

int Disease::deathRelapseChance() { return 90; }

bool Disease::permanentLossFixedByCurative() {
    return false;
}
