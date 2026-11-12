// R-refactor: split from swimcross.h - definitions
#include "rules/dmg/swimcross.h"

int Swimcross::swimArmorSwims(int armorId) {
    return armorId <= 2 ? 1 : 0;
}

int Swimcross::swimMagicArmorSwims() {
    return 1;
}

int Swimcross::swimCanSwim(int armorId, int armorPlus) {
    return armorPlus > 0 ? swimMagicArmorSwims()
                         : swimArmorSwims(armorId);
}

int Swimcross::swimLoadBeyondArmorLbs(int carriedGp, int armorGp) {
    int lbs = (carriedGp - armorGp) / 10;
    if (lbs < 0) lbs = 0;
    return lbs;
}

int Swimcross::swimDrownRollPerCrossing() {
    return 1;
}

int Swimcross::floodPerDelveCount() {
    return 1;
}

int Swimcross::floodSideMin() {
    return 2;
}

int Swimcross::floodSideMax() {
    return 3;
}
