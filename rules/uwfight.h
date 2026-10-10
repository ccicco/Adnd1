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
// range - the R311 data). No such item
// is pinned in the engine, so the bar
// reads total; the fold opens when the
// crossbow is pinned.
//
// NOT CHARGED (recorded, ride the R311
// pin, not data): the aquatic first
// strike (no aquatic monster roster is
// pinned), the net throw prose, the free
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
// except the specially-made crossbow (no
// such item is pinned - the bar reads
// total until the crossbow lands).
inline int uwMissileBarred() {
    return 1;
}

}  // namespace rules
