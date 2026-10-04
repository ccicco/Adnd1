// ====================================================================
// Adnd1 - rules/twoweapon.h
// R161: attacks with two weapons (DMG p.70) - the
// two-weapon conventions for attack and armor class.
//
// Header-only (the grenade.h pattern): the caller
// decides to fight two-handed and carries the flag.
//
// The p.70 print:
//   - A character normally using a single weapon may
//     choose to use one in each hand, discarding the
//     option of using a shield.
//   - The second weapon must be either a dagger or a
//     hand axe.
//   - Employment of a second weapon is always at a
//     penalty: primary weapon -2, secondary -4.
//   - If the user dexterity is BELOW 6, the PHB
//     Reaction/Attacking Adjustment penalties are
//     added to EACH weapon attack (caller-side).
//   - If the user dexterity is ABOVE 15, the penalties
//     ease: at 16 the secondary/primary penalty is
//     -3/-1, at 17 -2/0, at 18 -1/0 - and this never
//     gives a positive (bonus) rating.
//   - The secondary weapon does not act as a shield or
//     parrying device in any event.
// ====================================================================

#pragma once

#include <cstring>

namespace rules {

// The second weapon gate: dagger or hand axe only.
inline bool twoWeaponSecondaryAllowed(const char* name) {
    return std::strcmp(name, "dagger") == 0
        || std::strcmp(name, "hand axe") == 0;
}

// The penalty ladder. Primary -2, secondary -4; dex
// above 15 eases both by (dex - 15) points, clamped so
// the primary never goes positive (the print: 16 gives
// -1/-3, 17 0/-2, 18 0/-1).
inline int twoWeaponPrimaryPenalty(int dex) {
    int adj = (dex > 15) ? (dex - 15) : 0;
    int p = -2 + adj;
    return (p > 0) ? 0 : p;
}

inline int twoWeaponSecondaryPenalty(int dex) {
    int adj = (dex > 15) ? (dex - 15) : 0;
    return -4 + adj;   // max -1 at dex 18: no clamp
}

// Dex below 6: the PHB Reaction/Attacking Adjustment
// penalties are added to EACH weapon attack (the
// caller adds its table value to both).
inline bool twoWeaponLowDexAddsToEach(int dex) {
    return dex < 6;
}

// The secondary weapon never shields or parries.
inline bool twoWeaponSecondaryParries() {
    return false;
}

// Fighting with a weapon in each hand discards the
// shield option (the off hand holds the second weapon).
inline bool twoWeaponAllowsShield() {
    return false;
}

} // namespace rules
