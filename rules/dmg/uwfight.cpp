// R-refactor: split from uwfight.h - definitions
#include "rules/dmg/uwfight.h"

int Uwfight::uwCrossCapLbs(int allowanceGp) {
    return rules::uwSwimEncumbranceCapLbs(allowanceGp);
}

int Uwfight::uwCrossLoadBars(int loadLbs, int capLbs) {
    return loadLbs > capLbs ? 1 : 0;
}

int Uwfight::uwStrikeAllowed(int wclass) {
    return wclass == 1 ? 1 : 0;
}

int Uwfight::uwMissileBarred() {
    return 1;
}

int Uwfight::uwAquaticFirstStrikeSegment() {
    return 1;
}

int Uwfight::uwCompanyEarliestSegment() {
    return 2;
}

int Uwfight::uwWaterborneIsAquatic() {
    return 1;
}

int Uwfight::uwDeepCrossbowAllowed() {
    return 1;
}

int Uwfight::uwNetEntrapStrTear() {
    return 16;
}
