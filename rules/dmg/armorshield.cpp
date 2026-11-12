// R-refactor: split from armorshield.h - definitions
#include "rules/dmg/armorshield.h"

int Armorshield::asRowCount() {
    // Chain Mail +1 through the missile attractor
    return 26;
}

int Armorshield::asRowLo(int i) {
    // the printed band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 25) i = 25;
    static const int t[26] = {
        1, 6, 10, 12, 20, 27, 33, 36, 38,
        39, 40, 45, 51, 56, 60, 64, 67, 69,
        70, 76, 85, 90, 94, 96, 97, 98,
    };
    return t[i];
}

int Armorshield::asRowHi(int i) {
    // the printed band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 25) i = 25;
    static const int t[26] = {
        5, 9, 11, 19, 26, 32, 35, 37, 38,
        39, 44, 50, 55, 59, 63, 66, 68, 69,
        75, 84, 89, 93, 95, 96, 97, 100,
    };
    return t[i];
}

int Armorshield::asXpValue(int i) {
    // the x.p. point values; the cursed rows are 0; i clamps
    if (i < 0) i = 0;
    if (i > 25) i = 25;
    static const int t[26] = {
        600, 1200, 2000, 300, 800, 1750, 2750, 3500, 4500,
        5000, 0, 400, 500, 1100, 700, 1500, 2250, 3000,
        400, 250, 500, 800, 1200, 1750, 400, 0,
    };
    return t[i];
}

int Armorshield::asSaleGp(int i) {
    // the g.p. sale values; i clamps
    if (i < 0) i = 0;
    if (i > 25) i = 25;
    static const int t[26] = {
        3500, 7500, 12500, 2000, 5000, 10500, 15500, 20500, 27500,
        30000, 1500, 2500, 3000, 6750, 4000, 8500, 14500, 19000,
        2500, 2500, 5000, 8000, 12000, 17500, 4000, 750,
    };
    return t[i];
}

int Armorshield::asNoXpCount() {
    // the Plate of Vulnerability and the missile attractor
    return 2;
}

int Armorshield::asManSizedPct() {
    // 65% of all armor is man-sized
    return 65;
}

int Armorshield::asElfSizedPct() {
    // 20% is elf-sized
    return 20;
}

int Armorshield::asDwarfSizedPct() {
    // 10% is dwarf-sized
    return 10;
}

int Armorshield::asSmallUserPct() {
    // but 5% gnome or halfling sized
    return 5;
}
