// R-refactor: split from hirelings.h - definitions
#include "rules/dmg/hirelings.h"

int Hirelings::hireStdCount() {
    return 10;
}

const char* Hirelings::hireStdName(int i) {
    static const char* const kNames[10] = {
        "bearer/porter",
        "carpenter",
        "leather worker",
        "limner",
        "linkboy",
        "mason",
        "pack handler",
        "tailor",
        "teamster",
        "valet/lackey",
    };
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    return kNames[i];
}

int Hirelings::hireStdDailySp(int i) {
    static const int kDaily[10] = {
           1,    3,    2,   10,    1,    4,    2,    2,    5,    3,
    };
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    return kDaily[i];
}

int Hirelings::hireStdMonthlyGold(int i) {
    static const int kGold[10] = {
           1,    2,    0,   10,    1,    3,    0,    0,    5,    0,
    };
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    return kGold[i];
}

int Hirelings::hireStdMonthlySilver(int i) {
    static const int kSilver[10] = {
           0,    0,   30,    0,    0,    0,   30,   30,    0,   50,
    };
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    return kSilver[i];
}

int Hirelings::hireStdPercentOnTop(int i) {
    static const int kPct[10] = {
           0,    1,    1,    0,    0,    0,    0,    1,    0,    0,
    };
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    return kPct[i];
}

int Hirelings::hireStdLongTermSixths(int bonusMultiple) {
    if (bonusMultiple >= 2) return 3;
    return 1;
}

int Hirelings::hireExpCount() {
    return 33;
}

const char* Hirelings::hireExpName(int i) {
    static const char* const kNames[33] = {
        "alchemist",
        "armorer",
        "blacksmith",
        "engineer-architect",
        "engineer-artillerist",
        "engineer-sapper/miner",
        "jeweler-gemcutter",
        "archer, longbow",
        "archer, shortbow",
        "artillerist",
        "captain",
        "crossbowman",
        "footman, heavy",
        "footman, light",
        "footman, pikeman",
        "hobilar, heavy",
        "hobilar, light",
        "horseman, archer",
        "horseman, crossbowman",
        "horseman, heavy",
        "horseman, light",
        "horseman, medium",
        "lieutenant",
        "sapper/miner",
        "serjeant",
        "slinger",
        "sage",
        "scribe",
        "ship crew",
        "ship master",
        "spy",
        "steward/castellan",
        "weapon maker",
    };
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    return kNames[i];
}

int Hirelings::hireExpCost(int i) {
    static const int kCost[33] = {
         300,  100,   30,  100,  150,  150,  100,    4,    2,    5,
          -1,    2,    2,    1,    3,    3,    2,    6,    4,    6,
           3,    4,   -1,    4,   -1,    3,   -1,   15,   -1,   -1,
          -1,   -1,  100,
    };
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    return kCost[i];
}

int Hirelings::hireExpMercenaryFirst() {
    return 7;
}

int Hirelings::hireExpMercenaryCount() {
    return 19;
}

int Hirelings::hireExpIsMercenary(int i) {
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    if (i >= 7 && i <= 25) return 1;
    return 0;
}

int Hirelings::hireExpIsSpecial(int i) {
    return hireExpCost(i) < 0;
}

int Hirelings::hireExpPercentOnTop(int i) {
    static const int kPct[33] = {
           0,    1,    0,    1,    0,    0,    1,    0,    0,    0,
           0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
           0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
           0,    0,    1,
    };
    if (i < 0) i = 0;
    if (i > 32) i = 32;
    return kPct[i];
}
