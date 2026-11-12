// R-refactor: split from twoweapon.h - definitions
#include "rules/dmg/twoweapon.h"

bool Twoweapon::twoWeaponSecondaryAllowed(const char* name) {
    return std::strcmp(name, "dagger") == 0
        || std::strcmp(name, "hand axe") == 0;
}

int Twoweapon::twoWeaponPrimaryPenalty(int dex) {
    int adj = (dex > 15) ? (dex - 15) : 0;
    int p = -2 + adj;
    return (p > 0) ? 0 : p;
}

int Twoweapon::twoWeaponSecondaryPenalty(int dex) {
    int adj = (dex > 15) ? (dex - 15) : 0;
    return -4 + adj;   // max -1 at dex 18: no clamp
}

bool Twoweapon::twoWeaponLowDexAddsToEach(int dex) {
    return dex < 6;
}

bool Twoweapon::twoWeaponSecondaryParries() {
    return false;
}

bool Twoweapon::twoWeaponAllowsShield() {
    return false;
}
