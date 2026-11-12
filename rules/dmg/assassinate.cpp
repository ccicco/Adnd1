// R-refactor: split from assassinate.h - definitions
#include "rules/dmg/assassinate.h"

int Assassinate::assassinationVictimBand(int victimLevel) {
    if (victimLevel < 0) victimLevel = 0;
    int band = victimLevel / 2;
    if (band > 9) band = 9;
    return band;
}

int Assassinate::assassinationChance( int assassinLevel, int victimLevel) {
    static const int kTable[15][10] = {
        { 50, 45, 35, 25, 10,  1, -1, -1, -1, -1 },
        { 55, 50, 40, 30, 15,  2, -1, -1, -1, -1 },
        { 60, 55, 45, 35, 20,  5, -1, -1, -1, -1 },
        { 65, 60, 50, 40, 25, 10,  1, -1, -1, -1 },
        { 70, 65, 55, 45, 30, 15,  5, -1, -1, -1 },
        { 75, 70, 60, 50, 35, 20, 10,  1, -1, -1 },
        { 80, 75, 65, 55, 40, 25, 15,  5, -1, -1 },
        { 85, 80, 70, 60, 45, 30, 20, 10,  2, -1 },
        { 95, 90, 80, 70, 55, 40, 30, 20,  5, -1 },
        { 99, 95, 85, 75, 60, 45, 35, 25, 10,  1 },
        { 100, 99, 90, 80, 65, 50, 40, 30, 15,  5 },
        { 100, 100, 95, 85, 70, 55, 45, 35, 20, 10 },
        { 100, 100, 99, 95, 80, 65, 50, 40, 25, 15 },
        { 100, 100, 100, 99, 90, 75, 60, 50, 35, 25 },
        { 100, 100, 100, 100, 99, 85, 70, 60, 40, 30 }
    };
    if (assassinLevel < 1) assassinLevel = 1;
    if (assassinLevel > 15) assassinLevel = 15;
    return kTable[assassinLevel - 1]
        [assassinationVictimBand(victimLevel)];
}

bool Assassinate::assassinationTableCoversHelpless() {
    return true;
}
