// ====================================================================
// Adnd1 - rules/miscprose5.h
// R261: the III.E misc magic explanation prose part 5
// (DMG p.132) - Candle of Invocation through Cloak
// of Protection, part2 lines 155-220 (global =
// 11065 + part2 line). THREE page headers strip
// (155 TABLE (III.E.) 2., 159 and 183 both the
// TREASURE page); TWO seams pin exactly: the Candle
// (line 157 ends one of the, line 161 continues
// nine alignments) and the Cloak of Displacement
// (line 180 ends with such as spells,, line 185
// continues gaze weapon attacks). 60 accessors:
// 50 scalars + 10 array walkers, no name
// collisions with miscprose1.h through
// miscprose4.h. The slice completes kMisc2 rows
// 0-10; the per-plus asterisk sits on row 10
// (Cloak of Protection 33-55) - the R226 pin is
// correct, no R260-style off-by-one.
// Pure data + helpers, header-only (the
// grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int mmpCandleAlignments() {
    // one candle per alignment
    return 9;
}

inline int mmpCandleClericLevelBoost() {
    // same-alignment cleric level, while aflame
    return 2;
}

inline int mmpCandleBurnHours() {
    // each candle burns for 4 hours
    return 4;
}

inline int mmpCandleGateSpell() {
    // any burning allows a gate; taper consumed
    return 1;
}

inline int mmpCarpetRowCount() {
    // the random carpet table rows
    return 4;
}

inline int mmpCenserAirHd() {
    // the summoned air elemental
    return 12;
}

inline int mmpCenserAirMedBonusPerDie() {
    // incense of meditation: +3 per die
    return 3;
}

inline int mmpCenserAirWidthInches() {
    // the half-foot-wide vessel
    return 6;
}

inline int mmpCenserAirHeightInches() {
    // the 1-foot-high vessel
    return 12;
}

inline int mmpCenserAirTurnsIfExtinguished() {
    // extinguished: elemental remains, turns hostile
    return 1;
}

inline int mmpCenserHostileMin() {
    // enraged elementals, minimum
    return 1;
}

inline int mmpCenserHostileMax() {
    // enraged elementals, maximum
    return 4;
}

inline int mmpCenserHostilePerRound() {
    // elementals appear 1 per round
    return 1;
}

inline int mmpChimeOpenLengthInches() {
    // the hollow mithral tube
    return 12;
}

inline int mmpChimeOpenWizardLockLevel() {
    // defeats locks cast below 15th level
    return 15;
}

inline int mmpChimeOpenRoundPerFunction() {
    // one function completes per round
    return 1;
}

inline int mmpChimeOpenSoundingsMin() {
    // the fully chained and locked chest
    return 4;
}

inline int mmpChimeOpenSoundingsMax() {
    // the fully chained and locked chest
    return 5;
}

inline int mmpChimeOpenChargesMin() {
    // 20-80 charges, 20 + d6 x 10
    return 20;
}

inline int mmpChimeOpenChargesMax() {
    // 20-80 charges, 20 + d6 x 10
    return 80;
}

inline int mmpChimeOpenChargesDieSides() {
    // 20 + d6 x 10
    return 6;
}

inline int mmpChimeOpenChargesDieMult() {
    // 20 + d6 x 10
    return 10;
}

inline int mmpChimeHungerRadiusInches() {
    // ravenous hunger radius
    return 6;
}

inline int mmpChimeHungerMinEatRounds() {
    // must eat at least 1 round
    return 1;
}

inline int mmpDisplacementMinFeet() {
    // apparent offset, minimum
    return 1;
}

inline int mmpDisplacementMaxFeet() {
    // apparent offset, maximum
    return 2;
}

inline int mmpDisplacementAcBonus() {
    // 2 classes better, after the first attack
    return 2;
}

inline int mmpDisplacementSaveBonus() {
    // saving throw dice bonus
    return 2;
}

inline int mmpDisplacementHumanoidPct() {
    // sized for humans or elves
    return 75;
}

inline int mmpDisplacementSmallPct() {
    // sized for 4-foot persons
    return 25;
}

inline int mmpElvenkindRowCount() {
    // the invisibility table rows
    return 9;
}

inline int mmpElvenkindOutdoorNaturalRows() {
    // heavy growth, light growth, open fields
    return 3;
}

inline int mmpElvenkindOutdoorOtherRows() {
    // rocky terrain, buildings, bright room
    return 3;
}

inline int mmpElvenkindUndergroundRows() {
    // torch, infravision, light
    return 3;
}

inline int mmpElvenkindHumanoidPct() {
    // human to elven sized cloaks
    return 90;
}

inline int mmpElvenkindSmallPct() {
    // smaller persons, about 4 feet
    return 10;
}

inline int mmpMantaRayLikenessPct() {
    // identical to a manta ray in salt water
    return 90;
}

inline int mmpMantaRayMoveInches() {
    // moves as a manta ray
    return 18;
}

inline int mmpMantaRayAc() {
    // armor class of at least 6
    return 6;
}

inline int mmpMantaRayTailDmgMin() {
    // tail spine damage
    return 1;
}

inline int mmpMantaRayTailDmgMax() {
    // tail spine damage
    return 6;
}

inline int mmpMantaRayTailStun() {
    // no chance of stunning
    return 0;
}

inline int mmpMantaRaySaltWaterTrigger() {
    // the cloak adheres in salt water
    return 1;
}

inline int mmpPoisonCloakRevivalPctPenalty() {
    // raise dead chance penalty
    return 10;
}

inline int mmpPoisonCloakRemoveCurseDestroys() {
    // remove curse removes and destroys the magic
    return 1;
}

inline int mmpPoisonCloakNeutralizeNoEffect() {
    // neutralize poison does not affect it
    return 1;
}

inline int mmpCloakProtRowCount() {
    // the random plus table rows
    return 5;
}

inline int mmpCloakProtAcPerPlus() {
    // armor class better per plus
    return 1;
}

inline int mmpCloakProtSavePerPlus() {
    // saving throw added per plus
    return 1;
}

inline int mmpCloakProtExampleBaseAc() {
    // the +1 example: AC 10 becomes 9
    return 10;
}

inline int mmpCarpetBandLo(int i) {
    // the carpet band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 21, 56, 81,
    };
    return t[i];
}

inline int mmpCarpetBandHi(int i) {
    // the carpet band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        20, 55, 80, 100,
    };
    return t[i];
}

inline int mmpCarpetWidthFeet(int i) {
    // the carpet width; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        3, 4, 5, 6,
    };
    return t[i];
}

inline int mmpCarpetLengthFeet(int i) {
    // the carpet length; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        5, 6, 7, 9,
    };
    return t[i];
}

inline int mmpCarpetPersons(int i) {
    // the carpet capacity; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        1, 2, 3, 4,
    };
    return t[i];
}

inline int mmpCarpetSpeedInches(int i) {
    // the carpet speed; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        42, 36, 30, 24,
    };
    return t[i];
}

inline int mmpElvenkindInvisibilityPct(int i) {
    // invisibility per setting; i clamps
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    static const int t[9] = {
        100, 99, 95, 98, 90, 50, 95, 90, 50,
    };
    return t[i];
}

inline int mmpCloakProtBandLo(int i) {
    // the plus band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    static const int t[5] = {
        1, 36, 66, 86, 96,
    };
    return t[i];
}

inline int mmpCloakProtBandHi(int i) {
    // the plus band upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    static const int t[5] = {
        35, 65, 85, 95, 100,
    };
    return t[i];
}

inline int mmpCloakProtPlus(int i) {
    // the cloak plus per band; i clamps
    if (i < 0) i = 0;
    if (i > 4) i = 4;
    static const int t[5] = {
        1, 2, 3, 4, 5,
    };
    return t[i];
}

} // namespace rules
