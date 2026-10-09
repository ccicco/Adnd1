// ====================================================================
// Adnd1 - rules/miscprose23.h
// R279: the III.E misc magic explanation prose part 23
// (DMG p.156-158) - the Sphere of Annihilation, the Stone
// of Controlling Earth Elementals, the Stone of Good Luck,
// the Stone of Weight, the Talisman of Pure Good, the
// Talisman of the Sphere, the Talisman of Ultimate Evil,
// the Talisman of Zagy, the Tome of Clear Thought, the
// Tome of Leadership and Influence, the Tome of
// Understanding, the Trident of Fish Command, the Trident
// of Submission, the Trident of Warning, the Trident of
// Yearning, the Vacuous Grimoire, the Well of Many Worlds
// and the Wings of Flying, part2 lines 1083-1149
// (global = 11065 + part2 line), pinning the kMisc5 rows
// 17-34 of the 35-row III.E.5 table - the closing slice:
// rows 0-5 landed with part 21, rows 6-16 with part 22
// and rows 17-34 here, the table complete. This round has
// two seams restored: seam A is the p.156-157 page break
// between the Stone of Weight tail (1108) and the
// Talisman of Pure Good head (1113) with the blank pair
// at 1109-1110, the TREASURE (MISCELLANEOUS MAGIC) running
// head at 1111 and the 1112 post-head blank; seam B
// splits the Fish Command paragraph between the 1127 tail
// (but they will not) and the 1129 head (approach closer
// than 10 feet of the trident) across the single 1128
// blank - the p.157-158 page break, no running head
// captured. The upload quirks this round: the foot and
// inch primes print as curly marks; curly quotes wrap to
// hit on the luckstone; curly apostrophes print
// throughout; the minus sign prints true on the Yearning
// cursed weapon; the plus-minus sign prints on the
// luckstone 1 to 10 percent range; a multiplication sign
// prints in the cancellation 3d4 x 10 damage; the OCR
// splits Non- clerics and largest/ deepest with spaces;
// the sphere control table prints as a nine-row level
// grid; the wings durations print as a bare three-line
// list - all pinned as plain digits and words,
// apostrophe-free here. The part1 quirks: the eighteen
// slice rows print side-by-side with armor-table columns
// (part1 9892-9910); the Earth Elementals row wraps its
// name across two lines; the Loadstone, Yearning and
// Vacuous rows print --- in the x.p. column; the Sphere
// and its Talisman carry the (M) marks, the Pure Good
// and Ultimate Evil the (C) marks, the command/warning
// Tridents the (C, F, T) marks and the Submission the
// lone (F). The sphere control grid and the wings
// duration list are pinned as the walkers.
// 110 accessors: 104 scalars + 6 walkers, no name
// collisions with miscprose1.h through miscprose22.h.
// Pure data + helpers, header-only (the grenade.h
// pattern).
// ====================================================================

#pragma once

namespace rules {

inline int mmpSphereDiameterFeet() {
    // a ball of nothingness 2 feet in diameter
    return 2;
}

inline int mmpSphereControlRangeFeet() {
    // control range is 40 feet initially
    return 40;
}

inline int mmpSphereControlPerLevelInches() {
    // 1 inch per level once control is established
    return 1;
}

inline int mmpSphereBaseMoveFeetPerRound() {
    // basic movement rate is 10 feet per round
    return 10;
}

inline int mmpSphereIntBonusLowPct() {
    // adds 1 percent for each point from 13 to 15
    return 1;
}

inline int mmpSphereIntBonusHighPct() {
    // another 3 percent for each point from 16 to 18
    return 3;
}

inline int mmpSphereIntBonusMaxPct() {
    // a maximum of 12 percent bonus
    return 12;
}

inline int mmpSphereIntBonusLowStat() {
    // the low band runs from intelligence 13
    return 13;
}

inline int mmpSphereIntBonusHighStat() {
    // the high band runs from intelligence 16
    return 16;
}

inline int mmpSphereIntBonusMaxStat() {
    // the maximum bonus lands at 18 intelligence
    return 18;
}

inline int mmpSphereDriftRoundsMin() {
    // uncontrolled it slides toward the user 1-4 rounds
    return 1;
}

inline int mmpSphereDriftRoundsMax() {
    // the drift ceiling
    return 4;
}

inline int mmpSphereDriftRangeFeet() {
    // it keeps coming if the user stays within 30 feet
    return 30;
}

inline int mmpSphereMultiUserPenaltyPct() {
    // 2 or more users drop the chance 5 percent each
    return 5;
}

inline int mmpSphereGateDestroyPct() {
    // a gate spell destroys it 50 percent of the time
    return 50;
}

inline int mmpSphereGateNothingPct() {
    // the gate does nothing 35 percent
    return 35;
}

inline int mmpSphereGateTearPct() {
    // the gate tears a spatial gap 15 percent
    return 15;
}

inline int mmpSphereGateTearRadiusInches() {
    // the gap catapults everything within 18 inches
    return 18;
}

inline int mmpSphereCancelRadiusInches() {
    // a rod of cancellation explodes within 6 inches
    return 6;
}

inline int mmpSphereCancelDmgMin() {
    // the cancellation blast delivers 30-120 damage
    return 30;
}

inline int mmpSphereCancelDmgMax() {
    // the cancellation damage ceiling
    return 120;
}

inline int mmpSphereCtlRows() {
    // the control grid has nine level bands
    return 9;
}

inline int mmpSphereCtlLevelLo(int i) {
    // the control grid level band lower edges; i clamps
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    // up to 5th, 6th-7th, 8th-9th, 10th-11th, 12th-13th,
    // 14th-15th, 16th-17th, 18th-20th, 21st and above
    static const int t[9] = {
        1, 6, 8, 10, 12, 14, 16, 18, 21,
    };
    return t[i];
}

inline int mmpSphereCtlLevelHi(int i) {
    // the level band upper edges; i clamps; the open
    // 21st-and-above band prints no ceiling and pins 0
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    static const int t[9] = {
        5, 7, 9, 11, 13, 15, 17, 20, 0,
    };
    return t[i];
}

inline int mmpSphereCtlMoveFeet(int i) {
    // the movement per round per band; i clamps
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    static const int t[9] = {
        8, 9, 10, 11, 12, 13, 14, 15, 16,
    };
    return t[i];
}

inline int mmpSphereCtlProbPct(int i) {
    // the control probability per round per band; i clamps
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    static const int t[9] = {
        15, 20, 30, 40, 50, 60, 70, 75, 80,
    };
    return t[i];
}

inline int mmpEarthStoneEarthDice() {
    // an earth elemental of 12 hit dice from earth
    return 12;
}

inline int mmpEarthStoneRoughDice() {
    // 8 hit dice from rough unhewn stone or sand
    return 8;
}

inline int mmpEarthStoneWorkedStoneDice() {
    // none can be summoned from worked stone
    return 0;
}

inline int mmpEarthStoneAreaFeet() {
    // the summoning area must be 4 feet square
    return 4;
}

inline int mmpEarthStoneVolumeYards() {
    // and hold 4 cubic yards of medium
    return 4;
}

inline int mmpEarthStoneRoundsMin() {
    // the elemental appears in 1-4 rounds
    return 1;
}

inline int mmpEarthStoneRoundsMax() {
    // the appearance ceiling
    return 4;
}

inline int mmpEarthStonePerDay() {
    // one elemental per day by means of the stone
    return 1;
}

inline int mmpLuckSaveBonus() {
    // +1 on adverse-happening dice rolls
    return 1;
}

inline int mmpLuckSavePctBonus() {
    // +5 percent where applicable
    return 5;
}

inline int mmpLuckItemPctMin() {
    // 1 percent on magic item and treasure division rolls
    return 1;
}

inline int mmpLuckItemPctMax() {
    // up to 10 percent at owner option
    return 10;
}

inline int mmpLoadMoveReductionPct() {
    // a 50 percent reduction in movement when haste is due
    return 50;
}

inline int mmpLoadAttackReductionPct() {
    // attacks also reduced to 50 percent normal rate
    return 50;
}

inline int mmpLoadDispelClears() {
    // a dispel evil makes the item disappear
    return 1;
}

inline int mmpPureGoodCharges() {
    // the talisman of pure good has 7 charges
    return 7;
}

inline int mmpPureGoodRechargeable() {
    // it cannot be recharged
    return 0;
}

inline int mmpPureGoodNeutralDmgMin() {
    // a neutral cleric touching it takes 7-28 damage
    return 7;
}

inline int mmpPureGoodNeutralDmgMax() {
    // the neutral touch ceiling
    return 28;
}

inline int mmpPureGoodEvilDmgMin() {
    // an evil cleric touching it takes 12-48 damage
    return 12;
}

inline int mmpPureGoodEvilDmgMax() {
    // the evil touch ceiling
    return 48;
}

inline int mmpPureGoodNonClericDmg() {
    // non-clerics are not affected by the device
    return 0;
}

inline int mmpSphereTaliNonMuDmgMin() {
    // any other class touching it takes 5-30 damage
    return 5;
}

inline int mmpSphereTaliNonMuDmgMax() {
    // the wrong-class touch ceiling
    return 30;
}

inline int mmpSphereTaliLowPctPerPoint() {
    // doubles the bonus: 2 percent per point 13-15
    return 2;
}

inline int mmpSphereTaliHighPctPerPoint() {
    // and 6 percent per point 16-18
    return 6;
}

inline int mmpSphereTaliCheckIntervalRounds() {
    // held, the wielder checks control every other round
    return 2;
}

inline int mmpSphereTaliMaxMoveFeet() {
    // an uncontrolled sphere approaches at 16 feet
    return 16;
}

inline int mmpSphereWandNegationOnTalisman() {
    // a wand of negation stops the talisman control
    return 1;
}

inline int mmpSphereWandNegationOnSphere() {
    // but has no effect upon the sphere itself
    return 0;
}

inline int mmpUltimateEvilCharges() {
    // the exact opposite of pure good; 6 charges
    return 6;
}

inline int mmpZagyHostileDmgMin() {
    // a hostile reaction acts as a stone of weight;
    // discarding or destroying it costs 5-30 damage
    return 5;
}

inline int mmpZagyHostileDmgMax() {
    // the hostile discard ceiling
    return 30;
}

inline int mmpZagyNeutralHoursMin() {
    // a neutral reaction stays 5-30 hours
    return 5;
}

inline int mmpZagyNeutralHoursMax() {
    // the neutral stay ceiling
    return 30;
}

inline int mmpZagyFriendlyMonthsPerChaPoint() {
    // friendly, it stays one month per charisma point
    return 1;
}

inline int mmpZagyWishChaDivisor() {
    // it grants 1 wish per 6 charisma points
    return 6;
}

inline int mmpZagyTrapRangeFeet() {
    // it grows warm within 20 feet of a trap
    return 20;
}

inline int mmpZagyDiamondGp() {
    // a base 10,000 gp diamond remains behind
    return 10000;
}

inline int mmpClearThoughtIntGain() {
    // the tome raises intelligence by 1 point
    return 1;
}

inline int mmpClearThoughtReadHours() {
    // reading takes 48 hours over 6 days
    return 48;
}

inline int mmpClearThoughtReadDays() {
    // the six reading days
    return 6;
}

inline int mmpClearThoughtStartWeeks() {
    // the exercises must begin within 1 week
    return 1;
}

inline int mmpClearThoughtGainMonths() {
    // intelligence goes up after 1 full month
    return 1;
}

inline int mmpClearThoughtRereadGain() {
    // any further perusal is of no benefit
    return 0;
}

inline int mmpLeadershipChaGain() {
    // leadership and influence raises charisma by 1
    return 1;
}

inline int mmpUnderstandingWisGain() {
    // the tome of understanding raises wisdom by 1
    return 1;
}

inline int mmpFishCmdRadiusInches() {
    // all fish within a 6 inch radius save versus magic
    return 6;
}

inline int mmpFishCmdChargeCost() {
    // the command uses one charge
    return 1;
}

inline int mmpFishCmdProtectFeet() {
    // commanded fish spare all within 10 feet
    return 10;
}

inline int mmpFishCmdApproachFeet() {
    // free fish keep 10 feet off the trident
    return 10;
}

inline int mmpFishCmdSchoolsAsOne() {
    // schooling fish check as a single entity
    return 1;
}

inline int mmpFishCmdChargesMin() {
    // it contains 17-20 charges
    return 17;
}

inline int mmpFishCmdChargesMax() {
    // the charge ceiling
    return 20;
}

inline int mmpFishCmdMagicBonus() {
    // otherwise a +1 magic weapon
    return 1;
}

inline int mmpSubmitMoraleDelayRounds() {
    // a failed save means a morale check the next round
    return 1;
}

inline int mmpSubmitHopelessRoundsMin() {
    // the hopelessness lasts 2-8 rounds
    return 2;
}

inline int mmpSubmitHopelessRoundsMax() {
    // the hopelessness ceiling
    return 8;
}

inline int mmpSubmitChargesMin() {
    // it has 17-20 charges
    return 17;
}

inline int mmpSubmitChargesMax() {
    // the charge ceiling
    return 20;
}

inline int mmpSubmitMagicBonus() {
    // a +1 magic weapon
    return 1;
}

inline int mmpWarningRadiusInches() {
    // it scans hostile hungry predators within 24 inches
    return 24;
}

inline int mmpWarningScanRounds() {
    // one round scans the 24 inch hemisphere
    return 1;
}

inline int mmpWarningChargesMin() {
    // it carries 19-24 charges
    return 19;
}

inline int mmpWarningChargesMax() {
    // the charge ceiling
    return 24;
}

inline int mmpWarningChargeRounds() {
    // each charge lasts for 2 rounds of scanning
    return 2;
}

inline int mmpWarningMagicBonus() {
    // otherwise a +2 magic weapon
    return 2;
}

inline int mmpYearningMagicPenalty() {
    // a -2 cursed magical weapon
    return 2;
}

inline int mmpYearningFreeingSpells() {
    // freed by water breathing, wish or alter reality
    return 3;
}

inline int mmpYearningGrantsWaterBreathing() {
    // it does not confer the ability to breathe underwater
    return 0;
}

inline int mmpVacuousSaveCount() {
    // the reader must make 2 saving throws versus magic
    return 2;
}

inline int mmpVacuousIntLoss() {
    // the first throw: 1 point of intelligence lost
    return 1;
}

inline int mmpVacuousWisLoss() {
    // the second throw: 2 points of wisdom lost
    return 2;
}

inline int mmpVacuousBurnAfterRemoveCurse() {
    // it must be burned to be rid of after remove curse
    return 1;
}

inline int mmpWellTwoWay() {
    // things come through the opening both ways
    return 1;
}

inline int mmpWingsSpanFeet() {
    // gigantic bat wings of 20 foot span
    return 20;
}

inline int mmpWingsRestHours() {
    // after maximum flight the wearer rests 1 hour
    return 1;
}

inline int mmpWingsQuietHours() {
    // shorter flights need only 1 hour of quiet
    return 1;
}

inline int mmpWingsNoRestTurns() {
    // flights under 1 turn need no rest at all
    return 1;
}

inline int mmpWingsUsesPerDay() {
    // the wings work but once per day
    return 1;
}

inline int mmpWingsSupportPounds() {
    // they support up to 500 pounds weight
    return 500;
}

inline int mmpWingsSpeedRows() {
    // the duration list has three entries
    return 3;
}

inline int mmpWingsSpeedTurns(int i) {
    // the turns flown per speed entry; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    // 2 turns at 32 inches, 4 at 18, 8 at 12
    static const int t[3] = {
        2, 4, 8,
    };
    return t[i];
}

inline int mmpWingsSpeedInches(int i) {
    // the flight speed per entry; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        32, 18, 12,
    };
    return t[i];
}

}  // namespace rules