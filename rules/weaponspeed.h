// ====================================================================
// Adnd1 - rules/weaponspeed.h
// R158: weapon speed factors in initiative (DMG p.66,
// the PHB p.38 Combined Weapons Table column).
//
// Pure data + decision logic, header-only (the grenade.h
// pattern). rules/turn verified first: the segment
// scheduler needs NO change - the DMG applies the speed
// factor only in three caller-detected cases:
//   1. Simultaneous initiative, both opponents armed:
//      the lower factor strikes first.
//   2. A factor-determinant round (after an initial
//      round, or when closing/charging was not needed):
//      a big factor gap earns attacks before the slower
//      weapon acts. NOT applicable when closing or
//      charging.
//   3. Weapon vs an opponent mid-activity (a spell in
//      progress): strike segment = factor minus the
//      LOSING initiative die roll, negatives read as
//      positive; compare against the casting segments.
//      If initiative is tied there is no modification.
// ====================================================================

#pragma once

#include <cstring>

namespace rules {

// ----------------------------------------------------------------------------
// The PHB p.38 speed-factor column (melee weapons, named;
// missile weapons carry no factor). JUDGMENTS: the spear
// prints 6-8 (length 5 feet to 13+ feet, grip-dependent) -
// the engine default is 7, the range rides its own helper;
// footman/horseman mace and flail are named per the print
// (the engine items Mace/Flail read the footman rows).
// ----------------------------------------------------------------------------
inline int weaponSpeedFactor(const char* name) {
    static const struct { const char* n; int sf; } t[] = {
        { "fist",             1 },   // DMG p.66 example
        { "dagger",           2 },
        { "short sword",      3 },
        { "hammer",           4 },   // DMG p.66 example
        { "club",             4 },
        { "hand axe",         4 },
        { "quarterstaff",     4 },
        { "scimitar",         4 },
        { "long sword",       5 },   // DMG: broad or long
        { "broad sword",      5 },
        { "horseman mace",    6 },
        { "horseman flail",   6 },
        { "spear",            7 },   // print 6-8, default 7
        { "footman mace",     7 },
        { "footman flail",    7 },
        { "morning star",     7 },
        { "battle axe",       7 },
        { "two-handed sword", 10 },  // DMG p.64/p.66
        { "pike",             13 },  // the DMG p.66 example
    };
    for (int i = 0; i < (int)(sizeof(t) / sizeof(t[0])); ++i)
        if (std::strcmp(name, t[i].n) == 0) return t[i].sf;
    return 0;   // unknown: caller decides
}

inline void spearSpeedFactorRange(int& lo, int& hi) {
    lo = 6; hi = 8;   // the printed 5-13+ foot length spread
}

// ----------------------------------------------------------------------------
// Case 1 (DMG p.66 Simultaneous Initiative): tied rolls,
// blows otherwise simultaneous - the lower factor
// strikes first. Returns -1 if A first, 1 if B first,
// 0 if equal (truly simultaneous).
// ----------------------------------------------------------------------------
inline int speedFactorFirst(int sfA, int sfB) {
    if (sfA < sfB) return -1;
    if (sfB < sfA) return 1;
    return 0;
}

// ----------------------------------------------------------------------------
// Case 2 (DMG p.66): the attacks the lower-factored
// wielder is entitled to BEFORE the higher acts.
//   difference >= 10             -> 3 (two before, one
//                                   simultaneous with the
//                                   slower first attack)
//   difference >= 2 x lower      -> 2 (two before any),
//   or difference >= 5 in any case
//   otherwise                    -> 1 (the normal one).
// Never when closing or charging (speedFactorApplies).
// ----------------------------------------------------------------------------
inline int speedFactorAttacksBefore(int sfLow, int sfHigh) {
    int diff = sfHigh - sfLow;
    if (diff <= 0) return 1;
    if (diff >= 10) return 3;
    if (diff >= 2 * sfLow || diff >= 5) return 2;
    return 1;
}

inline bool speedFactorApplies(bool closingOrCharging) {
    return !closingOrCharging;   // the print exempts both
}

// ----------------------------------------------------------------------------
// Case 3 (DMG p.66 Other Weapon Factor Determinants):
// the weapon strike segment when the wielder LOST
// initiative to an opponent mid-activity: factor minus
// the losing die roll, NEGATIVES READ AS POSITIVE.
// ----------------------------------------------------------------------------
inline int weaponVsActivitySegment(int speedFactor,
                                   int losingInitiativeRoll) {
    int v = speedFactor - losingInitiativeRoll;
    if (v < 0) v = -v;
    return v;
}

// Order vs the activity (a spell, casting segments):
// returns -1 if the weapon strikes first, 0 if
// simultaneous, 1 if the activity completes first.
inline int weaponVsActivityOrder(int strikeSegment,
                                 int activitySegments) {
    if (strikeSegment < activitySegments) return -1;
    if (strikeSegment > activitySegments) return 1;
    return 0;
}

// The print: if combat is simultaneous, there is no
// modification of the weapon speed factor (case 3 never
// subtracts a die roll the tied round does not have).
inline bool speedFactorModifiedWhenSimultaneous() {
    return false;
}

} // namespace rules
