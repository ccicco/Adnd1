// R-refactor: re-split from miscmagic_alchemy_jug_to_wings_of_flying.cpp - definitions
#include "rules/dmg/misc_magic/miscmagic_candle_of_invocation_to_cloak_of_protection.h"

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpCandleAlignments() {
    // one candle per alignment
    return 9;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpCandleClericLevelBoost() {
    // same-alignment cleric level, while aflame
    return 2;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpCandleBurnHours() {
    // each candle burns for 4 hours
    return 4;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpCandleGateSpell() {
    // any burning allows a gate; taper consumed
    return 1;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpCarpetRowCount() {
    // the random carpet table rows
    return 4;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpCenserAirHd() {
    // the summoned air elemental
    return 12;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpCenserAirMedBonusPerDie() {
    // incense of meditation: +3 per die
    return 3;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpCenserAirWidthInches() {
    // the half-foot-wide vessel
    return 6;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpCenserAirHeightInches() {
    // the 1-foot-high vessel
    return 12;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpCenserAirTurnsIfExtinguished() {
    // extinguished: elemental remains, turns hostile
    return 1;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpCenserHostileMin() {
    // enraged elementals, minimum
    return 1;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpCenserHostileMax() {
    // enraged elementals, maximum
    return 4;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpCenserHostilePerRound() {
    // elementals appear 1 per round
    return 1;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpChimeOpenLengthInches() {
    // the hollow mithral tube
    return 12;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpChimeOpenWizardLockLevel() {
    // defeats locks cast below 15th level
    return 15;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpChimeOpenRoundPerFunction() {
    // one function completes per round
    return 1;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpChimeOpenSoundingsMin() {
    // the fully chained and locked chest
    return 4;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpChimeOpenSoundingsMax() {
    // the fully chained and locked chest
    return 5;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpChimeOpenChargesMin() {
    // 20-80 charges, 20 + d6 x 10
    return 20;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpChimeOpenChargesMax() {
    // 20-80 charges, 20 + d6 x 10
    return 80;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpChimeOpenChargesDieSides() {
    // 20 + d6 x 10
    return 6;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpChimeOpenChargesDieMult() {
    // 20 + d6 x 10
    return 10;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpChimeHungerRadiusInches() {
    // ravenous hunger radius
    return 6;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpChimeHungerMinEatRounds() {
    // must eat at least 1 round
    return 1;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpDisplacementMinFeet() {
    // apparent offset, minimum
    return 1;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpDisplacementMaxFeet() {
    // apparent offset, maximum
    return 2;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpDisplacementAcBonus() {
    // 2 classes better, after the first attack
    return 2;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpDisplacementSaveBonus() {
    // saving throw dice bonus
    return 2;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpDisplacementHumanoidPct() {
    // sized for humans or elves
    return 75;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpDisplacementSmallPct() {
    // sized for 4-foot persons
    return 25;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpElvenkindRowCount() {
    // the invisibility table rows
    return 9;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpElvenkindOutdoorNaturalRows() {
    // heavy growth, light growth, open fields
    return 3;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpElvenkindOutdoorOtherRows() {
    // rocky terrain, buildings, bright room
    return 3;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpElvenkindUndergroundRows() {
    // torch, infravision, light
    return 3;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpElvenkindHumanoidPct() {
    // human to elven sized cloaks
    return 90;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpElvenkindSmallPct() {
    // smaller persons, about 4 feet
    return 10;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpMantaRayLikenessPct() {
    // identical to a manta ray in salt water
    return 90;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpMantaRayMoveInches() {
    // moves as a manta ray
    return 18;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpMantaRayAc() {
    // armor class of at least 6
    return 6;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpMantaRayTailDmgMin() {
    // tail spine damage
    return 1;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpMantaRayTailDmgMax() {
    // tail spine damage
    return 6;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpMantaRayTailStun() {
    // no chance of stunning
    return 0;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpMantaRaySaltWaterTrigger() {
    // the cloak adheres in salt water
    return 1;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpPoisonCloakRevivalPctPenalty() {
    // raise dead chance penalty
    return 10;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpPoisonCloakRemoveCurseDestroys() {
    // remove curse removes and destroys the magic
    return 1;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpPoisonCloakNeutralizeNoEffect() {
    // neutralize poison does not affect it
    return 1;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpCloakProtRowCount() {
    // the random plus table rows
    return 5;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpCloakProtAcPerPlus() {
    // armor class better per plus
    return 1;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpCloakProtSavePerPlus() {
    // saving throw added per plus
    return 1;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpCloakProtExampleBaseAc() {
    // the +1 example: AC 10 becomes 9
    return 10;
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpCarpetBandLo(int i) {
    // the carpet band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 21, 56, 81,
    };
    return t[i];
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpCarpetBandHi(int i) {
    // the carpet band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        20, 55, 80, 100,
    };
    return t[i];
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpCarpetWidthFeet(int i) {
    // the carpet width; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        3, 4, 5, 6,
    };
    return t[i];
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpCarpetLengthFeet(int i) {
    // the carpet length; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        5, 6, 7, 9,
    };
    return t[i];
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpCarpetPersons(int i) {
    // the carpet capacity; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 2, 3, 4,
    };
    return t[i];
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpCarpetSpeedInches(int i) {
    // the carpet speed; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        42, 36, 30, 24,
    };
    return t[i];
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpElvenkindInvisibilityPct(int i) {
    // invisibility per setting; i clamps
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    static const int t[9] = {
        100, 99, 95, 98, 90, 50, 95, 90, 50,
    };
    return t[i];
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpCloakProtBandLo(int i) {
    // the plus band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    static const int t[5] = {
        1, 36, 66, 86, 96,
    };
    return t[i];
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpCloakProtBandHi(int i) {
    // the plus band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    static const int t[5] = {
        35, 65, 85, 95, 100,
    };
    return t[i];
}

int Miscmagic_candle_of_invocation_to_cloak_of_protection::mmpCloakProtPlus(int i) {
    // the cloak plus per band; i clamps
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    static const int t[5] = {
        1, 2, 3, 4, 5,
    };
    return t[i];
}
