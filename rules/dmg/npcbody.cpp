// R-refactor: split from npcbody.h - definitions
#include "rules/dmg/npcbody.h"

int Npcbody::npcDieCount(int packed) { return packed / 100; }

int Npcbody::npcDieSides(int packed) { return packed % 100; }

int Npcbody::npcBodyRaceCount() { return 7; }

int Npcbody::npcHeightAvgInches(int female, int race) {
    // the print averages: male 48/60/42/
    // 66/36/66/72, female 46/54/39/62/33/
    // 62/66
    if (female < 0) female = 0;
    if (female > 1) female = 1;
    if (race < 0) race = 0;
    if (race > 6) race = 6;
    static const int t[14] = {
        48, 60, 42, 66, 36, 66, 72,
        46, 54, 39, 62, 33, 62, 66,
    };
    return t[female * 7 + race];
}

int Npcbody::npcWeightAvgPounds(int female, int race) {
    // male 150/100/80/130/60/150/175,
    // female 120/80/75/100/50/120/130
    if (female < 0) female = 0;
    if (female > 1) female = 1;
    if (race < 0) race = 0;
    if (race > 6) race = 6;
    static const int t[14] = {
        150, 100, 80, 130, 60, 150, 175,
        120, 80, 75, 100, 50, 120, 130,
    };
    return t[female * 7 + race];
}

int Npcbody::npcHeightDie(int female, int race, int over) {
    // the under/over adjustment dice,
    // packed count*100+sides: male dwarf
    // 1d4/1d6 ... female human 1d6/1d8
    if (female < 0) female = 0;
    if (female > 1) female = 1;
    if (race < 0) race = 0;
    if (race > 6) race = 6;
    if (over < 0) over = 0;
    if (over > 1) over = 1;
    static const int t[28] = {
        104, 104, 103, 106, 103, 104, 112,
        106, 106, 103, 106, 106, 104, 112,
        104, 104, 103, 106, 103, 103, 106,
        104, 106, 103, 106, 103, 103, 108,
    };
    return t[female * 14 + over * 7 + race];
}

int Npcbody::npcWeightDie(int female, int race, int over) {
    // male dwarf 2d8/2d12 ... half-orc
    // 2d8/4d10, human 3d12/5d12; female
    // half-orc 3d6/4d8, human 3d10/4d12
    if (female < 0) female = 0;
    if (female > 1) female = 1;
    if (race < 0) race = 0;
    if (race > 6) race = 6;
    if (over < 0) over = 0;
    if (over > 1) over = 1;
    static const int t[28] = {
        208, 110, 204, 120, 204, 208, 312,
        212, 120, 206, 120, 206, 410, 512,
        208, 110, 108, 112, 204, 306, 310,
        210, 206, 108, 208, 204, 408, 412,
    };
    return t[female * 14 + over * 7 + race];
}

int Npcbody::npcHeightBandUnderEdge(int race) {
    if (race < 0) race = 0;
    if (race > 6) race = 6;
    static const int e[7] = { 15, 10, 20, 35, 10, 45, 20 };
    return e[race];
}

int Npcbody::npcHeightBandAvgEdge(int race) {
    if (race < 0) race = 0;
    if (race > 6) race = 6;
    static const int e[7] = { 80, 80, 85, 90, 90, 75, 80 };
    return e[race];
}

int Npcbody::npcWeightBandUnderEdge(int race) {
    if (race < 0) race = 0;
    if (race > 6) race = 6;
    static const int e[7] = { 20, 15, 20, 20, 10, 30, 25 };
    return e[race];
}

int Npcbody::npcWeightBandAvgEdge(int race) {
    if (race < 0) race = 0;
    if (race > 6) race = 6;
    static const int e[7] = { 65, 90, 75, 85, 50, 55, 75 };
    return e[race];
}

int Npcbody::npcBandClass(int pct, int underEdge, int avgEdge) {
    // 0 under, 1 average, 2 over; the roll
    // clamps to 1..100
    if (pct < 1) pct = 1;
    if (pct > 100) pct = 100;
    if (pct <= underEdge) return 0;
    if (pct <= avgEdge) return 1;
    return 2;
}

int Npcbody::npcDetermineHeightClass(int race, int pct) {
    return npcBandClass(pct,
        npcHeightBandUnderEdge(race),
        npcHeightBandAvgEdge(race));
}

int Npcbody::npcDetermineWeightClass(int race, int pct) {
    return npcBandClass(pct,
        npcWeightBandUnderEdge(race),
        npcWeightBandAvgEdge(race));
}

int Npcbody::npcLanguageKindCount() { return 55; }

int Npcbody::npcLanguageFor(int pct) {
    // the 100-face table, d100; the roll
    // clamps to 1..100
    if (pct < 1) pct = 1;
    if (pct > 100) pct = 100;
    static const int t[100] = {
        0, 1, 1, 2,
        3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
        13,
        14, 14, 14, 14, 14,
        15, 15, 15, 15, 15,
        16,
        17,
        18, 19, 20, 21, 22, 23, 24, 25,
        26, 26, 26, 26,
        27,
        28, 28, 28, 28,
        29, 29, 29, 29, 29,
        30, 30,
        31, 31, 31,
        32,
        33, 33, 33,
        34,
        35,
        36,
        37, 38, 39,
        40,
        41,
        42, 42, 42, 42,
        43,
        44, 44, 44, 44, 44,
        45,
        46,
        47,
        48,
        49,
        50,
        51,
        52,
        53,
        54, 54, 54, 54, 54, 54, 54, 54,
        54, 54, 54, 54, 54, 54, 54,
    };
    return t[pct - 1];
}
