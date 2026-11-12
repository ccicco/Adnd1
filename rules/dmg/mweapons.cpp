// R-refactor: split from mweapons.h - definitions
#include "rules/dmg/mweapons.h"

int Mweapons::mwRowCount() {
    // Arrow +1 through the Trident (Military Fork)
    return 36;
}

int Mweapons::mwRowLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    static const int t[36] = {
        1, 9, 13, 15, 16, 21, 23, 24, 25, 28, 33, 36,
        37, 38, 39, 47, 51, 52, 57, 61, 63, 64, 65, 68,
        73, 76, 77, 78, 81, 84, 89, 90, 95, 97, 98, 100,
    };
    return t[i];
}

int Mweapons::mwRowHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    static const int t[36] = {
        8, 12, 14, 15, 20, 22, 23, 24, 27, 32, 35, 36,
        37, 38, 46, 50, 51, 56, 60, 62, 63, 64, 67, 72,
        75, 76, 77, 80, 83, 88, 89, 94, 96, 97, 99, 100,
    };
    return t[i];
}

int Mweapons::mwXpValue(int i) {
    // the x.p. point values; the Backbiter is 0; i clamps
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    static const int t[36] = {
        20, 50, 75, 250, 300, 600, 750, 1000, 400, 50, 500, 2000,
        1500, 1500, 100, 250, 350, 450, 300, 650, 1500, 2500, 750, 350,
        700, 1750, 1500, 350, 400, 750, 700, 500, 1000, 1750, 0, 1500,
    };
    return t[i];
}

int Mweapons::mwSaleGp(int i) {
    // the g.p. sale values; i clamps
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    static const int t[36] = {
        120, 300, 450, 2500, 1750, 3750, 4500, 7000, 2500, 300, 3500, 12000,
        7500, 7500, 750, 2000, 3000, 4000, 2500, 6000, 15000, 25000, 5000, 3000,
        4500, 17500, 15000, 2500, 3000, 6000, 7000, 3000, 6500, 15000, 1000, 12500,
    };
    return t[i];
}

int Mweapons::mwQtyLo(int i) {
    // the ammo quantity lower bounds; 0 = a single item; i clamps
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    static const int t[36] = {
        2, 2, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    return t[i];
}

int Mweapons::mwQtyHi(int i) {
    // the ammo quantity upper bounds; 0 = a single item; i clamps
    if (i < 0) i = 0;
    if (i > 35) i = 35;
    static const int t[36] = {
        24, 16, 12, 0, 0, 0, 0, 0, 0, 20, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };
    return t[i];
}

int Mweapons::mwQtyRangeCount() {
    // the three Arrows and the Bolt
    return 4;
}

int Mweapons::mwNoXpCount() {
    // the cursed Backbiter prints --- x.p.
    return 1;
}

int Mweapons::mwDuplicateNameCount() {
    // the two Hammer +2 rows (Curtiss-verified p.125)
    return 2;
}
