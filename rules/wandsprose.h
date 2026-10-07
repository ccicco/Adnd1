// ====================================================================
// Adnd1 - rules/wandsprose.h
// R246: the III.D wands explanation prose
// pins, part 1 (DMG pp.143-144) - the
// section conventions and the FIRST FIVE
// wands of the RODS, et al. explanation
// prose (upload lines ~10786-10826):
//   - the conventions: wands perform at
//     6th level of experience; at DM
//     option 1% of all wands are trapped
//     to backfire.
//   - Wand of Conjuration: 11 recognized
//     conjuration/summoning spells (unseen
//     servant, monster summoning, conjure
//     elemental, death spell, invisible
//     stalker, limited wish, symbol, maze,
//     gate, prismatic sphere, wish);
//     monster summoning max 6 charges at 1
//     per level, 5 segments; curtain of
//     blackness 600 sq ft at 2 charges;
//     prismatic sphere 1 charge per color;
//     each function 5 segments, 1 per round.
//   - Wand of Enemy Detection: 6" sphere,
//     1 charge per turn.
//   - Wand of Fear: cone 6" long by 2" base,
//     1 segment flash, flee 6 rounds,
//     1 charge per use, once per round.
//   - Wand of Fire, 4 functions: burning
//     hands 10 ft wide 12 ft long 6 hp,
//     1 segment, 1 charge; pyrotechnics
//     2 segments 1 charge; fireball range
//     16", 2 segments, 2 charges, 6 dice
//     with 1s counted as 2s = 12-36 hp;
//     wall of fire 12 square", 6 rounds,
//     8-18 hp touched (2d6 + 6), 2-8
//     within 1", 1-4 within 2", ring
//     circle 2.25 inch diameter - pinned
//     as 9 quarter-inches; once per round.
//   - Wand of Frost, 3 functions: ice
//     storm 6" distant, 1 segment,
//     1 charge; wall of ice 6 inches thick,
//     6" square area, 2 segments,
//     1 charge; cone of cold 6" long, 2"
//     terminal diameter, 2 segments,
//     c. -100 F, 6 dice 12-36, 2 charges;
//     once per round.
// All five wands are rechargeable. The five
// wands are the engine III.D table wand rows
// 1-5 (dm/treasure.cpp kRods, bands 34-47);
// the illumination rows begin at band 48.
// Pure data + helpers, header-only (the
// grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int wdLevelOfUse() {
    // wands perform at 6th level of experience
    return 6;
}

inline int wdBackfirePercent() {
    // at DM option 1% of all wands are
    // trapped to backfire
    return 1;
}

inline int wdConjRecognizedCount() {
    // the conjuration/summoning spells the
    // wielder recognizes on grasping
    return 11;
}

inline int wdConjSummonMaxCharges() {
    // monster summoning: max 6 charges,
    // 1 per level
    return 6;
}

inline int wdConjSummonSegments() {
    // the monster summoning takes 5 segments
    return 5;
}

inline int wdConjCurtainSqFeet() {
    // the curtain of blackness: 600 sq ft
    return 600;
}

inline int wdConjCurtainCharges() {
    // the curtain costs 2 charges
    return 2;
}

inline int wdConjPrismaticChargesPerColor() {
    // the prismatic sphere: 1 charge per
    // color, red to violet
    return 1;
}

inline int wdConjFunctionSegments() {
    // each function takes 5 segments
    return 5;
}

inline int wdConjFunctionsPerRound() {
    // only 1 function per round
    return 1;
}

inline int wdConjRechargeable() {
    // it may be recharged
    return 1;
}

inline int wdEnemyRadiusInches() {
    // Wand of Enemy Detection: 6" sphere
    return 6;
}

inline int wdEnemyChargesPerTurn() {
    // 1 charge to operate for 1 turn
    return 1;
}

inline int wdEnemyRechargeable() {
    // it can be recharged
    return 1;
}

inline int wdFearConeLengthInches() {
    // Wand of Fear: cone 6" long
    return 6;
}

inline int wdFearConeWidthInches() {
    // by 2" in base diameter
    return 2;
}

inline int wdFearSegments() {
    // flashes on in 1 segment
    return 1;
}

inline int wdFearFleeRounds() {
    // flee at fastest speed for 6 rounds
    return 6;
}

inline int wdFearChargesPerUse() {
    // each usage costs 1 charge
    return 1;
}

inline int wdFearUsesPerRound() {
    // it can operate but once per round
    return 1;
}

inline int wdFearRechargeable() {
    // it can be recharged
    return 1;
}

inline int wdFireFunctionCount() {
    // Wand of Fire: 4 separate functions
    return 4;
}

inline int wdFireHandsWidthFeet() {
    // burning hands: fan 10 ft wide
    return 10;
}

inline int wdFireHandsLengthFeet() {
    // and 12 ft long
    return 12;
}

inline int wdFireHandsHp() {
    // each creature touched takes 6 hp
    return 6;
}

inline int wdFireHandsSegments() {
    // the plane appears in 1 segment
    return 1;
}

inline int wdFireHandsCharges() {
    // it expends 1 charge
    return 1;
}

inline int wdFirePyroSegments() {
    // pyrotechnics: 2 segments to activate
    return 2;
}

inline int wdFirePyroCharges() {
    // it expends 1 charge
    return 1;
}

inline int wdFireBallRangeInches() {
    // fireball: maximum range 16"
    return 16;
}

inline int wdFireBallSegments() {
    // the function takes 2 segments
    return 2;
}

inline int wdFireBallCharges() {
    // it expends 2 charges
    return 2;
}

inline int wdFireBallDice() {
    // 6 hit dice of damage
    return 6;
}

inline int wdFireBallFaces() {
    // d6, with all 1s counted as 2s
    return 6;
}

inline int wdFireBallDamageLo() {
    // the burst does 12-36 hit points
    return 12;
}

inline int wdFireBallDamageHi() {
    return 36;
}

inline int wdFireWallAreaSqInches() {
    // wall of fire: a sheet of 12 square"
    return 12;
}

inline int wdFireWallRounds() {
    // it lasts for 6 rounds
    return 6;
}

inline int wdFireWallTouchLo() {
    // touched: 8-18 hp (2d6 + 6)
    return 8;
}

inline int wdFireWallTouchHi() {
    return 18;
}

inline int wdFireWallNearLo() {
    // within 1": 2-8 hp
    return 2;
}

inline int wdFireWallNearHi() {
    return 8;
}

inline int wdFireWallFarLo() {
    // within 2": 1-4 hp
    return 1;
}

inline int wdFireWallFarHi() {
    return 4;
}

inline int wdFireWallRingQuarterInches() {
    // the ring-shape circle is only 2.25 inches
    // in diameter - pinned as 9 quarter-inches
    return 9;
}

inline int wdFireUsesPerRound() {
    // once per round
    return 1;
}

inline int wdFireRechargeable() {
    // it can be recharged
    return 1;
}

inline int wdFrostFunctionCount() {
    // Wand of Frost: 3 functions
    return 3;
}

inline int wdFrostStormRangeInches() {
    // ice storm: up to 6" distant
    return 6;
}

inline int wdFrostStormSegments() {
    // in 1 segment
    return 1;
}

inline int wdFrostStormCharges() {
    // requires 1 charge
    return 1;
}

inline int wdFrostWallThicknessInches() {
    // wall of ice: 6 inches thick
    return 6;
}

inline int wdFrostWallAreaInches() {
    // square area equal to 6"
    return 6;
}

inline int wdFrostWallSegments() {
    // in 2 segments
    return 2;
}

inline int wdFrostWallCharges() {
    // at a cost of 1 charge
    return 1;
}

inline int wdFrostConeLengthInches() {
    // cone of cold: 6" length
    return 6;
}

inline int wdFrostConeWidthInches() {
    // and 2" terminal diameter
    return 2;
}

inline int wdFrostConeSegments() {
    // the cold comes forth in 2 segments
    return 2;
}

inline int wdFrostConeTempF() {
    // the temperature is c. -100 F
    return -100;
}

inline int wdFrostConeDice() {
    // damage is 6 hit dice
    return 6;
}

inline int wdFrostConeDamageLo() {
    // 6d6, treating 1s as 2s: 12-36
    return 12;
}

inline int wdFrostConeDamageHi() {
    return 36;
}

inline int wdFrostConeCharges() {
    // the cost is 2 charges per use
    return 2;
}

inline int wdFrostUsesPerRound() {
    // once per round
    return 1;
}

inline int wdFrostRechargeable() {
    // it may be recharged
    return 1;
}

}  // namespace rules

