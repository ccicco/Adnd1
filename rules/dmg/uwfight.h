// ====================================================================
// Adnd1 - rules/dmg/uwfight.h
// R313: the DMG UNDERWATER ADVENTURES
// movement and combat pins (R311,
// rules/seams/underwater.h) folded for the
// flooded crossing (R312,
// rules/dmg/swimcross.h) - the seam the
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
// pin, not data): the net throw
// untrained -4 and the strength-point
// range (the throw itself is charged
// R315 - the state_combat volley fold),
// the free
// action weapon exception (no free action
// effect exists), the vision decay (no
// engine vision layer - a future seam)
// and the breathing aids (recorded notes
// only - no breathing print pin).
//
// The wclass reads the plain
// rules::WeaponClass ints (rules/engine/combat.h
// order): 0 bludgeoning, 1 piercing,
// 2 slashing - dagger, short sword and
// spear thrust; the swords, axes, maces
// and staves fail.
// ====================================================================

#pragma once

#include "../seams/underwater.h"  // R311: the cap pin

// R-refactor: namespace rules -> class Uwfight (instance methods)
class Uwfight {
public:


// The crossing equipment cap in pounds:
// the R311 movement pin (20 + 1 per full
// 100 g.p. of the strength weight
// allowance, C truncation - the negatives
// move the cap down).
    int uwCrossCapLbs(int allowanceGp);


// The crossing load gate: the load beyond
// the worn armor bars the crossing past
// the strength-fed cap (1 = barred).
    int uwCrossLoadBars(int loadLbs, int capLbs);


// The underwater strike: only the
// thrusting weapons connect underwater
// (the crushing and cleaving swings fail
// - the print); wclass reads the plain
// rules::WeaponClass ints: 0 bludgeoning,
// 1 piercing, 2 slashing.
    int uwStrikeAllowed(int wclass);


// Missile fire underwater is impossible
// except the specially-made crossbow
// (R314: the deep crossbow is pinned in
// items - the bar lifts for it alone at
// the combatShoot fold).
    int uwMissileBarred();


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
    int uwAquaticFirstStrikeSegment();


// The company (the land-side weapons)
// acts no earlier than this segment in
// the aquatic first-strike fold.
    int uwCompanyEarliestSegment();


// The waterborne wanderer is the aquatic
// monster (the R127 fresh-water table
// feeds the flood pool).
    int uwWaterborneIsAquatic();


// The deep crossbow (the specially-made
// underwater crossbow, R314, items) lifts
// the underwater missile bar.
    int uwDeepCrossbowAllowed();


// The net entrap: the MM grasp-and-tear
// strength (the sahuagin hooked nets -
// escape virtually impossible for victims
// not able to grasp and tear with a
// strength of 16 or greater; the R318
// stepRound tear fold reads this pin).
    int uwNetEntrapStrTear();
};
