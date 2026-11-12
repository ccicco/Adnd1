// ====================================================================
// Adnd1 - rules/dmg/weaponspeed.h
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

// R-refactor: namespace rules -> class Weaponspeed (instance methods)
class Weaponspeed {
public:


// ----------------------------------------------------------------------------
// The PHB p.38 speed-factor column (melee weapons, named;
// missile weapons carry no factor). JUDGMENTS: the spear
// prints 6-8 (length 5 feet to 13+ feet, grip-dependent) -
// the engine default is 7, the range rides its own helper;
// footman/horseman mace and flail are named per the print
// (the engine items Mace/Flail read the footman rows).
// ----------------------------------------------------------------------------
    int weaponSpeedFactor(const char* name);
    void spearSpeedFactorRange(int& lo, int& hi);


// ----------------------------------------------------------------------------
// R782: the spear length spread - the R158 boundary closes.
// The printed speed cells keyed on the shaft length in feet:
// 5 feet and under reads 6, 13 feet and over reads 8, the
// middle lengths keep the R158 default 7 (the name-keyed
// ladder keeps its default for the bare spear name).
    int spearSpeedFactorByLengthFt(int lengthFt);


// ----------------------------------------------------------------------------
// Case 1 (DMG p.66 Simultaneous Initiative): tied rolls,
// blows otherwise simultaneous - the lower factor
// strikes first. Returns -1 if A first, 1 if B first,
// 0 if equal (truly simultaneous).
// ----------------------------------------------------------------------------
    int speedFactorFirst(int sfA, int sfB);


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
    int speedFactorAttacksBefore(int sfLow, int sfHigh);
    bool speedFactorApplies(bool closingOrCharging);


// ----------------------------------------------------------------------------
// Case 3 (DMG p.66 Other Weapon Factor Determinants):
// the weapon strike segment when the wielder LOST
// initiative to an opponent mid-activity: factor minus
// the losing die roll, NEGATIVES READ AS POSITIVE.
// ----------------------------------------------------------------------------
    int weaponVsActivitySegment(int speedFactor, int losingInitiativeRoll);


// Order vs the activity (a spell, casting segments):
// returns -1 if the weapon strikes first, 0 if
// simultaneous, 1 if the activity completes first.
    int weaponVsActivityOrder(int strikeSegment, int activitySegments);


// The print: if combat is simultaneous, there is no
// modification of the weapon speed factor (case 3 never
// subtracts a die roll the tied round does not have).
    bool speedFactorModifiedWhenSimultaneous();
};
