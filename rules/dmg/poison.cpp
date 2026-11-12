// R-refactor: split from poison.h - definitions
#include "rules/dmg/poison.h"

bool Poison::poisonGradeExists(int route, int grade) {
    if (grade < 0 || grade > 4) return false;
    if (route == POISON_INSINUATIVE) return grade <= 3;
    return true;
}

int Poison::poisonCostPerDose(int route, int grade) {
    if (!poisonGradeExists(route, grade)) return 0;
    static const int kIngestive[5] = { 5, 30, 200, 500, 1000 };
    static const int kInsinuative[4] = { 10, 75, 600, 1500 };
    if (route == POISON_INSINUATIVE) return kInsinuative[grade];
    return kIngestive[grade];
}

int Poison::poisonOnsetMin(int route, int grade) {
    static const int kIn[5] = { 2, 2, 1, 1, 1 };
    static const int kIns[4] = { 2, 1, 1, 1 };
    if (!poisonGradeExists(route, grade)) return 0;
    if (route == POISON_INSINUATIVE) return kIns[grade];
    return kIn[grade];
}

int Poison::poisonOnsetMax(int route, int grade) {
    static const int kIn[5] = { 8, 5, 2, 1, 4 };
    static const int kIns[4] = { 5, 3, 1, 1 };
    if (!poisonGradeExists(route, grade)) return 0;
    if (route == POISON_INSINUATIVE) return kIns[grade];
    return kIn[grade];
}

PoisonUnit Poison::poisonOnsetUnit(int route, int grade) {
    // ingestive D: 1 segment; ingestive E: 1-4 turns;
    // everything else: rounds
    if (route == POISON_INGESTIVE && grade == 3)
        return POISON_UNIT_SEGMENT;
    if (route == POISON_INGESTIVE && grade == 4)
        return POISON_UNIT_TURN;
    if (!poisonGradeExists(route, grade))
        return POISON_UNIT_ROUND;
    return POISON_UNIT_ROUND;
}

int Poison::poisonVictimSaveBonus(int route, int grade) {
    if (!poisonGradeExists(route, grade)) return 0;
    if (grade <= 2) return 4 - grade;
    if (grade == 3) return 1;
    return 0;
}

int Poison::poisonDetectChance(int route, int grade) {
    if (!poisonGradeExists(route, grade)) return 0;
    static const int k[5] = { 80, 65, 40, 15, 0 };
    return k[grade];
}

int Poison::poisonDamageIfSave(int route, int grade) {
    if (!poisonGradeExists(route, grade)) return -1;
    if (route == POISON_INSINUATIVE) return 0;
    static const int k[5] = { 10, 15, 20, 25, 30 };
    return k[grade];
}

bool Poison::poisonKillsIfNoSave(int route, int grade) {
    if (!poisonGradeExists(route, grade)) return false;
    if (route == POISON_INSINUATIVE) return grade == 3;
    return grade >= 3;
}

int Poison::poisonDamageIfNoSave(int route, int grade) {
    if (poisonKillsIfNoSave(route, grade)) return -1;
    if (!poisonGradeExists(route, grade)) return -1;
    if (route == POISON_INSINUATIVE) {
        static const int k[4] = { 15, 25, 35, 0 };
        return k[grade];
    }
    static const int k[5] = { 20, 30, 40, 0, 0 };
    return k[grade];
}

int Poison::poisonUserEfficiencyAdj( bool assassin, bool studied) {
    if (assassin && studied) return 0;
    if (assassin) return 1;
    return 2;
}

bool Poison::poisonMonsterAllOrNothing() {
    return true;
}

bool Poison::poisonMonsterDualUse() {
    return true;
}

int Poison::poisonBladeVenomPotencyPercent(int interval) {
    if (interval <= 0) return 100;
    if (interval == 1) return 50;
    return 0;
}

bool Poison::poisonBladeVenomDecayedGivesSaveBonus( int interval) {
    return interval >= 1;
}
