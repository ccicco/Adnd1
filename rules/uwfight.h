// ====================================================================
// Adnd1 - rules/uwfight.h
// R313: the DMG UNDERWATER ADVENTURES
// movement and combat pins (R311,
// rules/underwater.h) folded for the
// flooded crossing (R312,
// rules/swimcross.h) - the seam the
// crossing site charges.
//
// The print (the MOVEMENT paragraph):
// swimming is impossible in armor
// heavier than leather (magic armor
// excepted) or above 20 pounds of
// equipment - the cap moves 1 pound
// per 100 g.p. of strength bonus or
// penalty. The weight allowance derives
// at the site from the R153 ladder
// (rules/strWeightAllowGp, PHB STR
// Table II) - the R311 cap is
// un-caller-fed: the caller feeds the
// raw strength, the seam folds the pin.
// The JUDGMENT: the surface SWIMMING
// paragraph carries no load bar; the
// movement paragraph folds onto the
// crossing (the R312 one-roll precedent,
// the print condensed to the site).
//
// The print (the COMBAT paragraph):
// only thrusting weapons strike
// underwater - the crushing and cleaving
// swings fail; missile weapons are
// impossible except the specially-made
// crossbow (10x price, half the dungeon
// range - the R311 data). R314: the deep
// crossbow is pinned (items/items.h) - the
// missile bar lifts for it alone (the
// combatShoot fold in state_combat.cpp).
//
// NOT CHARGED (recorded, ride the R311
// pin, not data): the net throw prose,
// the free
// action weapon exception (no free action
// effect exists), the vision decay (no
// engine vision layer - a future seam)
// and the breathing aids (recorded notes
// only - no breathing print pin).
//
// The wclass reads the plain
// rules::WeaponClass ints (rules/combat.h
// order): 0 bludgeoning, 1 piercing,
// 2 slashing - dagger, short sword and
// spear thrust; the swords, axes, maces
// and staves fail.
// ====================================================================

#pragma once

#include "rules/underwater.h"  // R311: the cap pin

namespace rules {

// The crossing equipment cap in pounds:
// the R311 movement pin (20 + 1 per full
// 100 g.p. of the strength weight
// allowance, C truncation - the negatives
// move the cap down).
inline int uwCrossCapLbs(int allowanceGp) {
    return uwSwimEncumbranceCapLbs(allowanceGp);
}

// The crossing load gate: the load beyond
// the worn armor bars the crossing past
// the strength-fed cap (1 = barred).
inline int uwCrossLoadBars(int loadLbs,
                           int capLbs) {
    return loadLbs > capLbs ? 1 : 0;
}

// The underwater strike: only the
// thrusting weapons connect underwater
// (the crushing and cleaving swings fail
// - the print); wclass reads the plain
// rules::WeaponClass ints: 0 bludgeoning,
// 1 piercing, 2 slashing.
inline int uwStrikeAllowed(int wclass) {
    return wclass == 1 ? 1 : 0;
}

// Missile fire underwater is impossible
// except the specially-made crossbow
// (R314: the deep crossbow is pinned in
// items - the bar lifts for it alone at
// the combatShoot fold).
inline int uwMissileBarred() {
    return 1;
}

// The aquatic first strike (the R311 pin
// uwAquaticFirstStrike, above): the fold
// floors the aquatic monsters at the
// first segment and the company no
// earlier than the second - the print
// exception (the significantly-longer
// company weapon) reads data, no reach
// layer exists (the JUDGMENT: no aquatic
// monster roster is pinned - aquatic
// means the encounter arrived via the
// waterborne table, the R127 fold).
inline int uwAquaticFirstStrikeSegment() {
    return 1;
}

// The company (the land-side weapons)
// acts no earlier than this segment in
// the aquatic first-strike fold.
inline int uwCompanyEarliestSegment() {
    return 2;
}

// The waterborne wanderer is the aquatic
// monster (the R127 fresh-water table
// feeds the flood pool).
inline int uwWaterborneIsAquatic() {
    return 1;
}

// The deep crossbow (the specially-made
// underwater crossbow, R314, items) lifts
// the underwater missile bar.
inline int uwDeepCrossbowAllowed() {
    return 1;
}

}  // namespace rules
