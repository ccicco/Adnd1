// R-refactor: split from specart.h - definitions
#include "rules/dmg/specart.h"

int Specart::saRowCount() {
    // the Axe through the Wand of Orcus
    return 29;
}

int Specart::saRowLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 28) i = 28;
    static const int t[29] = {
        1, 2, 3, 5, 21, 22, 23, 25, 26, 27,
        28, 30, 32, 33, 34, 36, 38, 39, 41, 48,
        64, 65, 67, 69, 75, 92, 93, 99, 100,
    };
    return t[i];
}

int Specart::saRowHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 28) i = 28;
    static const int t[29] = {
        1, 2, 4, 20, 21, 22, 24, 25, 26, 27,
        29, 31, 32, 33, 35, 37, 38, 40, 47, 63,
        64, 66, 68, 74, 91, 92, 98, 99, 100,
    };
    return t[i];
}

int Specart::saSaleGp(int i) {
    // the printed g.p. sale values; i clamps
    if (i < 0) i = 0;
    if (i > 28) i = 28;
    static const int t[29] = {
        55000, 90000, 62500, 50000, 75000, 85000, 35000, 60000,
        25000, 20000, 47500, 50000, 100000, 40000, 27500, 35000,
        72500, 185000, 10000, 100000, 112500, 80000, 17500, 25000,
        150000, 97000, 5000, 0, 10000,
    };
    return t[i];
}

int Specart::saSaleGpHi(int i) {
    // the range upper bound (the Orb only); i clamps
    if (i < 0) i = 0;
    if (i > 28) i = 28;
    static const int t[29] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 80000, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    return t[i];
}

int Specart::saXpValue(int i) {
    // the no-x.p. convention - all rows zero; i clamps
    if (i < 0) i = 0;
    if (i > 28) i = 28;
    static const int t[29] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    return t[i];
}

int Specart::saNoXpRowCount() {
    // every row brings no experience points
    return 29;
}

int Specart::saDualRangeCount() {
    // the Orb of the Dragonkind 10-80,000
    return 1;
}

int Specart::saNoSaleRowCount() {
    // the Throne of the Gods prints no sale value
    return 1;
}

int Specart::saPerToothRowCount() {
    // the Teeth of Dahlver-Nar 5,000/tooth
    return 1;
}
