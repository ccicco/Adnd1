// R-refactor: split from wands_conventions_conjuration_to_fear.h - definitions
#include "rules/dmg/wands_conventions_conjuration_to_fear.h"

int Wands_conventions_conjuration_to_fear::wdLevelOfUse() {
    // wands perform at 6th level of experience
    return 6;
}

int Wands_conventions_conjuration_to_fear::wdBackfirePercent() {
    // at DM option 1% of all wands are
    // trapped to backfire
    return 1;
}

int Wands_conventions_conjuration_to_fear::wdConjRecognizedCount() {
    // the conjuration/summoning spells the
    // wielder recognizes on grasping
    return 11;
}

int Wands_conventions_conjuration_to_fear::wdConjSummonMaxCharges() {
    // monster summoning: max 6 charges,
    // 1 per level
    return 6;
}

int Wands_conventions_conjuration_to_fear::wdConjSummonSegments() {
    // the monster summoning takes 5 segments
    return 5;
}

int Wands_conventions_conjuration_to_fear::wdConjCurtainSqFeet() {
    // the curtain of blackness: 600 sq ft
    return 600;
}

int Wands_conventions_conjuration_to_fear::wdConjCurtainCharges() {
    // the curtain costs 2 charges
    return 2;
}

int Wands_conventions_conjuration_to_fear::wdConjPrismaticChargesPerColor() {
    // the prismatic sphere: 1 charge per
    // color, red to violet
    return 1;
}

int Wands_conventions_conjuration_to_fear::wdConjFunctionSegments() {
    // each function takes 5 segments
    return 5;
}

int Wands_conventions_conjuration_to_fear::wdConjFunctionsPerRound() {
    // only 1 function per round
    return 1;
}

int Wands_conventions_conjuration_to_fear::wdConjRechargeable() {
    // it may be recharged
    return 1;
}

int Wands_conventions_conjuration_to_fear::wdEnemyRadiusInches() {
    // Wand of Enemy Detection: 6" sphere
    return 6;
}

int Wands_conventions_conjuration_to_fear::wdEnemyChargesPerTurn() {
    // 1 charge to operate for 1 turn
    return 1;
}

int Wands_conventions_conjuration_to_fear::wdEnemyRechargeable() {
    // it can be recharged
    return 1;
}

int Wands_conventions_conjuration_to_fear::wdFearConeLengthInches() {
    // Wand of Fear: cone 6" long
    return 6;
}

int Wands_conventions_conjuration_to_fear::wdFearConeWidthInches() {
    // by 2" in base diameter
    return 2;
}

int Wands_conventions_conjuration_to_fear::wdFearSegments() {
    // flashes on in 1 segment
    return 1;
}

int Wands_conventions_conjuration_to_fear::wdFearFleeRounds() {
    // flee at fastest speed for 6 rounds
    return 6;
}

int Wands_conventions_conjuration_to_fear::wdFearChargesPerUse() {
    // each usage costs 1 charge
    return 1;
}

int Wands_conventions_conjuration_to_fear::wdFearUsesPerRound() {
    // it can operate but once per round
    return 1;
}

int Wands_conventions_conjuration_to_fear::wdFearRechargeable() {
    // it can be recharged
    return 1;
}

int Wands_conventions_conjuration_to_fear::wdFireFunctionCount() {
    // Wand of Fire: 4 separate functions
    return 4;
}

int Wands_conventions_conjuration_to_fear::wdFireHandsWidthFeet() {
    // burning hands: fan 10 ft wide
    return 10;
}

int Wands_conventions_conjuration_to_fear::wdFireHandsLengthFeet() {
    // and 12 ft long
    return 12;
}

int Wands_conventions_conjuration_to_fear::wdFireHandsHp() {
    // each creature touched takes 6 hp
    return 6;
}

int Wands_conventions_conjuration_to_fear::wdFireHandsSegments() {
    // the plane appears in 1 segment
    return 1;
}

int Wands_conventions_conjuration_to_fear::wdFireHandsCharges() {
    // it expends 1 charge
    return 1;
}

int Wands_conventions_conjuration_to_fear::wdFirePyroSegments() {
    // pyrotechnics: 2 segments to activate
    return 2;
}

int Wands_conventions_conjuration_to_fear::wdFirePyroCharges() {
    // it expends 1 charge
    return 1;
}

int Wands_conventions_conjuration_to_fear::wdFireBallRangeInches() {
    // fireball: maximum range 16"
    return 16;
}

int Wands_conventions_conjuration_to_fear::wdFireBallSegments() {
    // the function takes 2 segments
    return 2;
}

int Wands_conventions_conjuration_to_fear::wdFireBallCharges() {
    // it expends 2 charges
    return 2;
}

int Wands_conventions_conjuration_to_fear::wdFireBallDice() {
    // 6 hit dice of damage
    return 6;
}

int Wands_conventions_conjuration_to_fear::wdFireBallFaces() {
    // d6, with all 1s counted as 2s
    return 6;
}

int Wands_conventions_conjuration_to_fear::wdFireBallDamageLo() {
    // the burst does 12-36 hit points
    return 12;
}

int Wands_conventions_conjuration_to_fear::wdFireBallDamageHi() {
    return 36;
}

int Wands_conventions_conjuration_to_fear::wdFireWallAreaSqInches() {
    // wall of fire: a sheet of 12 square"
    return 12;
}

int Wands_conventions_conjuration_to_fear::wdFireWallRounds() {
    // it lasts for 6 rounds
    return 6;
}

int Wands_conventions_conjuration_to_fear::wdFireWallTouchLo() {
    // touched: 8-18 hp (2d6 + 6)
    return 8;
}

int Wands_conventions_conjuration_to_fear::wdFireWallTouchHi() {
    return 18;
}

int Wands_conventions_conjuration_to_fear::wdFireWallNearLo() {
    // within 1": 2-8 hp
    return 2;
}

int Wands_conventions_conjuration_to_fear::wdFireWallNearHi() {
    return 8;
}

int Wands_conventions_conjuration_to_fear::wdFireWallFarLo() {
    // within 2": 1-4 hp
    return 1;
}

int Wands_conventions_conjuration_to_fear::wdFireWallFarHi() {
    return 4;
}

int Wands_conventions_conjuration_to_fear::wdFireWallRingQuarterInches() {
    // the ring-shape circle is only 2.25 inches
    // in diameter - pinned as 9 quarter-inches
    return 9;
}

int Wands_conventions_conjuration_to_fear::wdFireUsesPerRound() {
    // once per round
    return 1;
}

int Wands_conventions_conjuration_to_fear::wdFireRechargeable() {
    // it can be recharged
    return 1;
}

int Wands_conventions_conjuration_to_fear::wdFrostFunctionCount() {
    // Wand of Frost: 3 functions
    return 3;
}

int Wands_conventions_conjuration_to_fear::wdFrostStormRangeInches() {
    // ice storm: up to 6" distant
    return 6;
}

int Wands_conventions_conjuration_to_fear::wdFrostStormSegments() {
    // in 1 segment
    return 1;
}

int Wands_conventions_conjuration_to_fear::wdFrostStormCharges() {
    // requires 1 charge
    return 1;
}

int Wands_conventions_conjuration_to_fear::wdFrostWallThicknessInches() {
    // wall of ice: 6 inches thick
    return 6;
}

int Wands_conventions_conjuration_to_fear::wdFrostWallAreaInches() {
    // square area equal to 6"
    return 6;
}

int Wands_conventions_conjuration_to_fear::wdFrostWallSegments() {
    // in 2 segments
    return 2;
}

int Wands_conventions_conjuration_to_fear::wdFrostWallCharges() {
    // at a cost of 1 charge
    return 1;
}

int Wands_conventions_conjuration_to_fear::wdFrostConeLengthInches() {
    // cone of cold: 6" length
    return 6;
}

int Wands_conventions_conjuration_to_fear::wdFrostConeWidthInches() {
    // and 2" terminal diameter
    return 2;
}

int Wands_conventions_conjuration_to_fear::wdFrostConeSegments() {
    // the cold comes forth in 2 segments
    return 2;
}

int Wands_conventions_conjuration_to_fear::wdFrostConeTempF() {
    // the temperature is c. -100 F
    return -100;
}

int Wands_conventions_conjuration_to_fear::wdFrostConeDice() {
    // damage is 6 hit dice
    return 6;
}

int Wands_conventions_conjuration_to_fear::wdFrostConeDamageLo() {
    // 6d6, treating 1s as 2s: 12-36
    return 12;
}

int Wands_conventions_conjuration_to_fear::wdFrostConeDamageHi() {
    return 36;
}

int Wands_conventions_conjuration_to_fear::wdFrostConeCharges() {
    // the cost is 2 charges per use
    return 2;
}

int Wands_conventions_conjuration_to_fear::wdFrostUsesPerRound() {
    // once per round
    return 1;
}

int Wands_conventions_conjuration_to_fear::wdFrostRechargeable() {
    // it may be recharged
    return 1;
}
