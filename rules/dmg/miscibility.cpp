// R-refactor: split from miscibility.h - definitions
#include "rules/dmg/miscibility.h"

MiscibilityResult Miscibility::roll(int d100) {
    if (d100 < 1) d100 = 1;
    if (d100 > 100) d100 = 100;
    if (d100 == 1) return MISC_EXPLOSION;
    if (d100 <= 3) return MISC_LETHAL_POISON;
    if (d100 <= 8) return MISC_MILD_POISON;
    if (d100 <= 15) return MISC_BOTH_DESTROYED;
    if (d100 <= 25) return MISC_ONE_CANCELLED;
    if (d100 <= 35) return MISC_BOTH_HALF;
    if (d100 <= 90) return MISC_COMPATIBLE;
    if (d100 <= 99) return MISC_ONE_BOOSTED;
    return MISC_DISCOVERY;
}

bool Miscibility::testNeeded( bool intermingled, bool otherStillInEffect) {
    return intermingled || otherStillInEffect;
}

int Miscibility::explosionInternalMin() { return 6; }

int Miscibility::explosionInternalMax() { return 60; }

int Miscibility::explosionBlastNearMin() { return 1; }

int Miscibility::explosionBlastNearMax() { return 10; }

int Miscibility::explosionBlastNearRadius() { return 5; }

int Miscibility::explosionBlastFarMin() { return 4; }

int Miscibility::explosionBlastFarMax() { return 24; }

int Miscibility::explosionBlastFarRadius() { return 10; }

int Miscibility::mildPoisonDurationMin() { return 5; }

int Miscibility::mildPoisonDurationMax() { return 20; }

int Miscibility::gasCloudRadius() { return 10; }

int Miscibility::boostPercent() { return 150; }

bool Miscibility::optionDelusionMixes() {
    return true;
}

bool Miscibility::optionTreasureFindingLethal() {
    return true;
}

int Miscibility::optionEtherealLostPercent() {
    return 50;
}

int Miscibility::optionEtherealLostMinDays() {
    return 5;
}

int Miscibility::optionEtherealLostMaxDays() {
    return 30;
}
