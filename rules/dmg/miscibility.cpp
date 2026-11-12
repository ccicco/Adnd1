// R-refactor: split from miscibility.h - definitions
#include "rules/dmg/miscibility.h"

MiscibilityResult Miscibility::miscibilityRoll(int d100) {
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

bool Miscibility::miscibilityTestNeeded( bool intermingled, bool otherStillInEffect) {
    return intermingled || otherStillInEffect;
}

int Miscibility::miscibilityExplosionInternalMin() { return 6; }

int Miscibility::miscibilityExplosionInternalMax() { return 60; }

int Miscibility::miscibilityExplosionBlastNearMin() { return 1; }

int Miscibility::miscibilityExplosionBlastNearMax() { return 10; }

int Miscibility::miscibilityExplosionBlastNearRadius() { return 5; }

int Miscibility::miscibilityExplosionBlastFarMin() { return 4; }

int Miscibility::miscibilityExplosionBlastFarMax() { return 24; }

int Miscibility::miscibilityExplosionBlastFarRadius() { return 10; }

int Miscibility::miscibilityMildPoisonDurationMin() { return 5; }

int Miscibility::miscibilityMildPoisonDurationMax() { return 20; }

int Miscibility::miscibilityGasCloudRadius() { return 10; }

int Miscibility::miscibilityBoostPercent() { return 150; }

bool Miscibility::miscibilityOptionDelusionMixes() {
    return true;
}

bool Miscibility::miscibilityOptionTreasureFindingLethal() {
    return true;
}

int Miscibility::miscibilityOptionEtherealLostPercent() {
    return 50;
}

int Miscibility::miscibilityOptionEtherealLostMinDays() {
    return 5;
}

int Miscibility::miscibilityOptionEtherealLostMaxDays() {
    return 30;
}
