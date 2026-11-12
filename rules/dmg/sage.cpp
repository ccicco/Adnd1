// R-refactor: split from sage.h - definitions
#include "rules/dmg/sage.h"

int Sage::fieldCount() {
    return 7;
}

const char* Sage::fieldName(int f) {
    static const char* const kNames[7] = {
        "Humankind",
        "Demi-Humankind",
        "Humanoids & Giantkind",
        "Physical Universe(s)",
        "Fauna",
        "Flora",
        "Supernatural & Unusual",
    };
    if (f < 0) f = 0;
    if (f > 6) f = 6;
    return kNames[f];
}

int Sage::fieldLo(int f) {
    static const int kLo[7] = {
           1,   31,   51,   61,   71,   81,   91,
    };
    if (f < 0) f = 0;
    if (f > 6) f = 6;
    return kLo[f];
}

int Sage::fieldHi(int f) {
    static const int kHi[7] = {
          30,   50,   60,   70,   80,   90,  100,
    };
    if (f < 0) f = 0;
    if (f > 6) f = 6;
    return kHi[f];
}

int Sage::fieldCategoryCount(int f) {
    static const int kCount[7] = {
          12,   11,    8,   10,   10,    8,    9,
    };
    if (f < 0) f = 0;
    if (f > 6) f = 6;
    return kCount[f];
}

int Sage::fieldCategoryFirst(int f) {
    static const int kFirst[7] = {
           0,   12,   23,   31,   41,   51,   59,
    };
    if (f < 0) f = 0;
    if (f > 6) f = 6;
    return kFirst[f];
}

int Sage::categoryCount() {
    return 68;
}

const char* Sage::categoryName(int i) {
    static const char* const kNames[68] = {
        "Art & Music",
        "Biology",
        "Demography",
        "History",
        "Languages",
        "Legends & Folklore",
        "Law & Customs",
        "Philosophy & Ethics",
        "Politics & Genealogy",
        "Psychology",
        "Sociology",
        "Theology & Myth",
        "Art & Music",
        "Biology",
        "Demography",
        "Languages",
        "Legends & Folklore",
        "Law & Customs",
        "Philosophy & Ethics",
        "Politics & Genealogy",
        "Psychology",
        "Sociology",
        "Theology & Myth",
        "Biology",
        "Demography",
        "History",
        "Languages",
        "Legends & Folklore",
        "Law & Customs",
        "Sociology",
        "Theology & Myth",
        "Architecture & Engineering",
        "Astronomy",
        "Chemistry",
        "Geography",
        "Geology & Mineralogy",
        "Mathematics",
        "Meteorology & Climatology",
        "Oceanography",
        "Physics",
        "Topography & Cartography",
        "Amphibians",
        "Arachnids",
        "Avians",
        "Cephalopods & Echinoderms",
        "Crustaceans & Mollusks",
        "Ichthyoids",
        "Insects",
        "Mammals",
        "Marsupials",
        "Reptiles",
        "Bushes & Shrubs",
        "Flowers",
        "Fungi",
        "Grasses & Grains",
        "Herbs",
        "Mosses & Ferns",
        "Trees",
        "Weeds",
        "Astrology & Numerology",
        "Cryptography",
        "Divination",
        "Dweomercraeft",
        "Heraldry, Signs & Sigils",
        "Medicine",
        "Metaphysics",
        "Planes (Astral, Elemental & Ethereal)",
        "Planes (Outer)",
    };
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    return kNames[i];
}

int Sage::categoryField(int i) {
    static const int kField[68] = {
           0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
           0,    0,    1,    1,    1,    1,    1,    1,    1,    1,
           1,    1,    1,    2,    2,    2,    2,    2,    2,    2,
           2,    3,    3,    3,    3,    3,    3,    3,    3,    3,
           3,    4,    4,    4,    4,    4,    4,    4,    4,    4,
           4,    5,    5,    5,    5,    5,    5,    5,    5,    6,
           6,    6,    6,    6,    6,    6,    6,    6,
    };
    if (i < 0) i = 0;
    if (i > 67) i = 67;
    return kField[i];
}

int Sage::fieldsBandCount() {
    return 6;
}

int Sage::fieldsBandLo(int b) {
    static const int kLo[6] = {
           1,   11,   31,   51,   71,   91,
    };
    if (b < 0) b = 0;
    if (b > 5) b = 5;
    return kLo[b];
}

int Sage::fieldsBandHi(int b) {
    static const int kHi[6] = {
          10,   30,   50,   70,   90,  100,
    };
    if (b < 0) b = 0;
    if (b > 5) b = 5;
    return kHi[b];
}

int Sage::fieldsBandMinor(int b) {
    static const int kMinor[6] = {
           1,    1,    1,    2,    2,    2,
    };
    if (b < 0) b = 0;
    if (b > 5) b = 5;
    return kMinor[b];
}

int Sage::fieldsBandSpecial(int b) {
    static const int kSpecial[6] = {
           2,    3,    4,    2,    3,    4,
    };
    if (b < 0) b = 0;
    if (b > 5) b = 5;
    return kSpecial[b];
}

int Sage::knowLo(int scope, int nature) {
    static const int kLo[4][3] = {
        {  31,   11,   -1},
        {  46,   31,   11},
        {  61,   57,   26},
        {  81,   76,   61},
    };
    if (scope < 0) scope = 0;
    if (scope > 3) scope = 3;
    if (nature < 0) nature = 0;
    if (nature > 2) nature = 2;
    return kLo[scope][nature];
}

int Sage::knowHi(int scope, int nature) {
    static const int kHi[4][3] = {
        {  50,   20,   -1},
        {  65,   40,   20},
        {  80,   60,   35},
        { 100,   96,   80},
    };
    if (scope < 0) scope = 0;
    if (scope > 3) scope = 3;
    if (nature < 0) nature = 0;
    if (nature > 2) nature = 2;
    return kHi[scope][nature];
}

int Sage::knowNone(int scope, int nature) {
    return knowLo(scope, nature) < 0;
}

int Sage::abilityCount() {
    return 6;
}

int Sage::abilityDice(int a) {
    static const int kDice[6] = {
           8,    4,    6,    6,    6,    6,
    };
    if (a < 0) a = 0;
    if (a > 5) a = 5;
    return kDice[a];
}

int Sage::abilityDiceCount(int a) {
    static const int kCount[6] = {
           1,    1,    1,    3,    2,    2,
    };
    if (a < 0) a = 0;
    if (a > 5) a = 5;
    return kCount[a];
}

int Sage::abilityPlus(int a) {
    static const int kPlus[6] = {
           7,   14,   12,    0,    3,    2,
    };
    if (a < 0) a = 0;
    if (a > 5) a = 5;
    return kPlus[a];
}

int Sage::alignBandCount() {
    return 9;
}

int Sage::alignLo(int b) {
    static const int kLo[9] = {
           1,    6,   11,   21,   31,   41,   61,   81,   91,
    };
    if (b < 0) b = 0;
    if (b > 8) b = 8;
    return kLo[b];
}

int Sage::alignHi(int b) {
    static const int kHi[9] = {
           5,   10,   20,   30,   40,   60,   80,   90,  100,
    };
    if (b < 0) b = 0;
    if (b > 8) b = 8;
    return kHi[b];
}

const char* Sage::alignName(int b) {
    static const char* const kNames[9] = {
        "chaotic evil",
        "chaotic good",
        "chaotic neutral",
        "lawful evil",
        "lawful good",
        "lawful neutral",
        "neutral",
        "neutral evil",
        "neutral good",
    };
    if (b < 0) b = 0;
    if (b > 8) b = 8;
    return kNames[b];
}

int Sage::hpDiceCount() {
    return 8;
}

int Sage::hpDie() {
    return 4;
}

int Sage::spellKindCount() {
    return 3;
}

int Sage::spellKind(int f) {
    static const int kKind[7] = {
           0,    0,    0,    0,    1,    1,    2,
    };
    if (f < 0) f = 0;
    if (f > 6) f = 6;
    return kKind[f];
}

int Sage::spellMaxDie() {
    return 4;
}

int Sage::spellMaxPlus() {
    return 2;
}

int Sage::spellMaxLo() {
    return 3;
}

int Sage::spellMaxHi() {
    return 6;
}

int Sage::spellPerLevelLo() {
    return 1;
}

int Sage::spellPerLevelHi() {
    return 4;
}

int Sage::spellReadyPerLevel() {
    return 1;
}

int Sage::offerCount() {
    return 3;
}

int Sage::offerLo(int i) {
    static const int kLo[3] = {
         200,  200, 20000,
    };
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    return kLo[i];
}

int Sage::offerHi(int i) {
    static const int kHi[3] = {
        1200, 1200, 20000,
    };
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    return kHi[i];
}

int Sage::effMilestoneCount() {
    return 3;
}

int Sage::effMilestoneCost(int i) {
    static const int kCost[3] = {
        20000, 60000, 100000,
    };
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    return kCost[i];
}

int Sage::effMilestonePercent(int i) {
    static const int kPct[3] = {
          50,   90,  100,
    };
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    return kPct[i];
}

int Sage::effStepCost() {
    return 1000;
}

int Sage::effHighCostPerPercent() {
    return 4000;
}

int Sage::improveCount() {
    return 4;
}

int Sage::improveCost(int i) {
    static const int kCost[4] = {
        5000, 10000, 100000, 200000,
    };
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    return kCost[i];
}

int Sage::improveMonths(int i) {
    static const int kMonths[4] = {
           1,    1,   24,   24,
    };
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    return kMonths[i];
}

int Sage::improveMax(int i) {
    static const int kMax[4] = {
           5,    5,    3,   -1,
    };
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    return kMax[i];
}

int Sage::timeLo(int scope, int nature) {
    static const int kLo[4][3] = {
        {   1,    2,   -1},
        {   1,    2,    5},
        {   1,    1,    3},
        {   1,    1,    2},
    };
    if (scope < 0) scope = 0;
    if (scope > 3) scope = 3;
    if (nature < 0) nature = 0;
    if (nature > 2) nature = 2;
    return kLo[scope][nature];
}

int Sage::timeHi(int scope, int nature) {
    static const int kHi[4][3] = {
        {   6,   24,   -1},
        {   4,   20,   40},
        {   3,   12,   30},
        {   2,   10,   12},
    };
    if (scope < 0) scope = 0;
    if (scope > 3) scope = 3;
    if (nature < 0) nature = 0;
    if (nature > 2) nature = 2;
    return kHi[scope][nature];
}

int Sage::timeUnit(int scope, int nature) {
    static const int kUnit[4][3] = {
        {   0,    2,    0},
        {   0,    2,    2},
        {   0,    2,    2},
        {   0,    1,    2},
    };
    if (scope < 0) scope = 0;
    if (scope > 3) scope = 3;
    if (nature < 0) nature = 0;
    if (nature > 2) nature = 2;
    return kUnit[scope][nature];
}

int Sage::timeNone(int scope, int nature) {
    return timeLo(scope, nature) < 0;
}

int Sage::costPerDay(int scope) {
    static const int kCost[4] = {
         100, 1000,  500,  200,
    };
    if (scope < 0) scope = 0;
    if (scope > 3) scope = 3;
    return kCost[scope];
}

int Sage::freeSpreadPercent(int scope) {
    static const int kFree[4] = {
          20,   20,   20,   80,
    };
    if (scope < 0) scope = 0;
    if (scope > 3) scope = 3;
    return kFree[scope];
}

int Sage::unknownPercentLo() {
    return 51;
}

int Sage::unknownPercentHi() {
    return 100;
}

int Sage::unknownCostDivisor() {
    return 2;
}

int Sage::shortTermCostPerDay() {
    return 100;
}

int Sage::shortTermMaxDays() {
    return 7;
}

int Sage::shortTermCooldownMonths() {
    return 1;
}

int Sage::permanentHireOnly() {
    return 1;
}
