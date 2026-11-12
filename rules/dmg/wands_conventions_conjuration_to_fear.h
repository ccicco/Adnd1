// ====================================================================
// Adnd1 - rules/dmg/wands_conventions_conjuration_to_fear.h
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

// R-refactor: namespace rules -> class Wands_conventions_conjuration_to_fear (instance methods)
class Wands_conventions_conjuration_to_fear {
public:
    int wdLevelOfUse();
    int wdBackfirePercent();
    int wdConjRecognizedCount();
    int wdConjSummonMaxCharges();
    int wdConjSummonSegments();
    int wdConjCurtainSqFeet();
    int wdConjCurtainCharges();
    int wdConjPrismaticChargesPerColor();
    int wdConjFunctionSegments();
    int wdConjFunctionsPerRound();
    int wdConjRechargeable();
    int wdEnemyRadiusInches();
    int wdEnemyChargesPerTurn();
    int wdEnemyRechargeable();
    int wdFearConeLengthInches();
    int wdFearConeWidthInches();
    int wdFearSegments();
    int wdFearFleeRounds();
    int wdFearChargesPerUse();
    int wdFearUsesPerRound();
    int wdFearRechargeable();
    int wdFireFunctionCount();
    int wdFireHandsWidthFeet();
    int wdFireHandsLengthFeet();
    int wdFireHandsHp();
    int wdFireHandsSegments();
    int wdFireHandsCharges();
    int wdFirePyroSegments();
    int wdFirePyroCharges();
    int wdFireBallRangeInches();
    int wdFireBallSegments();
    int wdFireBallCharges();
    int wdFireBallDice();
    int wdFireBallFaces();
    int wdFireBallDamageLo();
    int wdFireBallDamageHi();
    int wdFireWallAreaSqInches();
    int wdFireWallRounds();
    int wdFireWallTouchLo();
    int wdFireWallTouchHi();
    int wdFireWallNearLo();
    int wdFireWallNearHi();
    int wdFireWallFarLo();
    int wdFireWallFarHi();
    int wdFireWallRingQuarterInches();
    int wdFireUsesPerRound();
    int wdFireRechargeable();
    int wdFrostFunctionCount();
    int wdFrostStormRangeInches();
    int wdFrostStormSegments();
    int wdFrostStormCharges();
    int wdFrostWallThicknessInches();
    int wdFrostWallAreaInches();
    int wdFrostWallSegments();
    int wdFrostWallCharges();
    int wdFrostConeLengthInches();
    int wdFrostConeWidthInches();
    int wdFrostConeSegments();
    int wdFrostConeTempF();
    int wdFrostConeDice();
    int wdFrostConeDamageLo();
    int wdFrostConeDamageHi();
    int wdFrostConeCharges();
    int wdFrostUsesPerRound();
    int wdFrostRechargeable();
};
