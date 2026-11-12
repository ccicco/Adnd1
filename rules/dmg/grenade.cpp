// R-refactor: split from grenade.h - definitions
#include "rules/dmg/grenade.h"

GrenadeKind Grenade::clamp(GrenadeKind k) {
    if (k < 0) k = GREN_ACID;
    if (k >= GREN_COUNT) k = GREN_ACID;
    return k;
}

const char* Grenade::name(GrenadeKind k) {
    static const char* const n[GREN_COUNT] = {
        "acid", "holy water", "unholy water", "oil", "poison"
    };
    return n[clamp(k)];
}

int Grenade::sizeOz(GrenadeKind k) {
    static const int oz[GREN_COUNT] = { 8, 4, 4, 16, 4 };
    return oz[clamp(k)];
}

void Grenade::directHit(GrenadeKind k, int& lo, int& hi) {
    static const int t[GREN_COUNT][2] = {
        { 2, 8 }, { 2, 7 }, { 2, 7 }, { 2, 12 }, { 0, 0 },
    };
    lo = t[clamp(k)][0];
    hi = t[clamp(k)][1];
}

void Grenade::splashDamage(GrenadeKind k, int& lo, int& hi) {
    static const int t[GREN_COUNT][2] = {
        { 1, 1 }, { 2, 2 }, { 2, 2 }, { 1, 3 }, { 0, 0 },
    };
    lo = t[clamp(k)][0];
    hi = t[clamp(k)][1];
}

int Grenade::splashDiameterFeet(GrenadeKind k) {
    static const int t[GREN_COUNT] = { 1, 1, 1, 3, 1 };
    return t[clamp(k)];
}

int Grenade::rollGrenadeDirectHit(rules::Dice& dice, GrenadeKind k) {
    int lo, hi;
    directHit(k, lo, hi);
    if (hi <= 0) return 0;   // poison special: caller-side
    return (int)dice.roll(1, (uint32_t)(hi - lo + 1), lo - 1);
}

int Grenade::rollGrenadeSplashDamage(rules::Dice& dice, GrenadeKind k) {
    int lo, hi;
    splashDamage(k, lo, hi);
    if (hi <= 0) return 0;
    return (int)dice.roll(1, (uint32_t)(hi - lo + 1), lo - 1);
}

void Grenade::oilSecondRound(int& lo, int& hi) {
    lo = 1; hi = 6;
}

int Grenade::rollGrenadeOilSecondRound(rules::Dice& dice) {
    return (int)dice.roll(1, 6, 0);
}

int Grenade::oilBurnSegmentsMax() { return 3; }

int Grenade::oilBurnDamagePerSegment() { return 1; }

int Grenade::splashRadiusFeet() { return 3; }

int Grenade::rangeMaxInches() { return 3; }

int Grenade::rangeToHitAdj(int inches) {
    if (inches <= 1) return 0;
    if (inches <= 2) return -2;
    return -5;   // through the 3" maximum
}

int Grenade::breakSaveCrushing(GrenadeKind k) {
    static const int t[GREN_COUNT] = { 18, 19, 19, 18, 19 };
    return t[clamp(k)];
}

int Grenade::breakSaveNormal(GrenadeKind k) {
    static const int t[GREN_COUNT] = { 12, 14, 14, 12, 14 };
    return t[clamp(k)];
}

int Grenade::missDistance(rules::Dice& dice, bool shortRange) {
    if (shortRange) return (int)dice.d4();
    return (int)dice.d6();
}

int Grenade::missDirection(rules::Dice& dice) {
    return (int)dice.d8();
}

const char* Grenade::missDirectionName(int dir) {
    static const char* const n[8] = {
        "long right", "right", "short right", "short (before)",
        "short left", "left", "long left", "long (over)"
    };
    if (dir < 1) dir = 1;
    if (dir > 8) dir = 8;
    return n[dir - 1];
}

bool Grenade::holyWaterAffects(bool isUndead, bool fromLowerPlane, bool materialForm) {
    if (!materialForm) return false;
    return isUndead || fromLowerPlane;
}

bool Grenade::unholyWaterAffects(bool isGoodOutsiderOrPaladin, bool materialForm) {
    if (!materialForm) return false;
    return isGoodOutsiderOrPaladin;
}

void Grenade::flamingOilWalkDamage(int& lo, int& hi) {
    lo = 1; hi = 6;
}

int Grenade::rollFlamingOilWalkDamage(rules::Dice& dice) {
    return (int)dice.roll(1, 6, 0);
}

int Grenade::vialCostLo() { return 2; }

int Grenade::vialCostHi() { return 5; }

int Grenade::boulderDiameterFeet(bool siege) {
    return siege ? 2 : 1;
}

int Grenade::boulderDropDamage(int weightLbs, int feetDropped) {
    int per14 = weightLbs / 14;
    if (per14 < 1) return 0;
    if (feetDropped < 10) feetDropped = 10;
    if (feetDropped > 60) feetDropped = 60;
    return per14 * feetDropped;
}

int Grenade::rollGrenadeBoulderFlatDamage(rules::Dice& dice, int weightLbs) {
    int per14 = weightLbs / 14;
    if (per14 < 1) return 0;
    return per14 * (int)dice.roll(1, 6, 0);
}
