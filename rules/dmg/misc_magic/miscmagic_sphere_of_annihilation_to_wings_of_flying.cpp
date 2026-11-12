// R-refactor: re-split from miscmagic_alchemy_jug_to_wings_of_flying.cpp - definitions
#include "rules/dmg/misc_magic/miscmagic_sphere_of_annihilation_to_wings_of_flying.h"

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereDiameterFeet() {
    // a ball of nothingness 2 feet in diameter
    return 2;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereControlRangeFeet() {
    // control range is 40 feet initially
    return 40;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereControlPerLevelInches() {
    // 1 inch per level once control is established
    return 1;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereBaseMoveFeetPerRound() {
    // basic movement rate is 10 feet per round
    return 10;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereIntBonusLowPct() {
    // adds 1 percent for each point from 13 to 15
    return 1;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereIntBonusHighPct() {
    // another 3 percent for each point from 16 to 18
    return 3;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereIntBonusMaxPct() {
    // a maximum of 12 percent bonus
    return 12;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereIntBonusLowStat() {
    // the low band runs from intelligence 13
    return 13;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereIntBonusHighStat() {
    // the high band runs from intelligence 16
    return 16;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereIntBonusMaxStat() {
    // the maximum bonus lands at 18 intelligence
    return 18;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereDriftRoundsMin() {
    // uncontrolled it slides toward the user 1-4 rounds
    return 1;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereDriftRoundsMax() {
    // the drift ceiling
    return 4;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereDriftRangeFeet() {
    // it keeps coming if the user stays within 30 feet
    return 30;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereMultiUserPenaltyPct() {
    // 2 or more users drop the chance 5 percent each
    return 5;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereGateDestroyPct() {
    // a gate spell destroys it 50 percent of the time
    return 50;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereGateNothingPct() {
    // the gate does nothing 35 percent
    return 35;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereGateTearPct() {
    // the gate tears a spatial gap 15 percent
    return 15;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereGateTearRadiusInches() {
    // the gap catapults everything within 18 inches
    return 18;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereCancelRadiusInches() {
    // a rod of cancellation explodes within 6 inches
    return 6;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereCancelDmgMin() {
    // the cancellation blast delivers 30-120 damage
    return 30;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereCancelDmgMax() {
    // the cancellation damage ceiling
    return 120;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereCtlRows() {
    // the control grid has nine level bands
    return 9;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereCtlLevelLo(int i) {
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

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereCtlLevelHi(int i) {
    // the level band upper edges; i clamps; the open
    // 21st-and-above band prints no ceiling and pins 0
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    static const int t[9] = {
        5, 7, 9, 11, 13, 15, 17, 20, 0,
    };
    return t[i];
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereCtlMoveFeet(int i) {
    // the movement per round per band; i clamps
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    static const int t[9] = {
        8, 9, 10, 11, 12, 13, 14, 15, 16,
    };
    return t[i];
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereCtlProbPct(int i) {
    // the control probability per round per band; i clamps
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    static const int t[9] = {
        15, 20, 30, 40, 50, 60, 70, 75, 80,
    };
    return t[i];
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpEarthStoneEarthDice() {
    // an earth elemental of 12 hit dice from earth
    return 12;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpEarthStoneRoughDice() {
    // 8 hit dice from rough unhewn stone or sand
    return 8;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpEarthStoneWorkedStoneDice() {
    // none can be summoned from worked stone
    return 0;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpEarthStoneAreaFeet() {
    // the summoning area must be 4 feet square
    return 4;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpEarthStoneVolumeYards() {
    // and hold 4 cubic yards of medium
    return 4;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpEarthStoneRoundsMin() {
    // the elemental appears in 1-4 rounds
    return 1;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpEarthStoneRoundsMax() {
    // the appearance ceiling
    return 4;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpEarthStonePerDay() {
    // one elemental per day by means of the stone
    return 1;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpLuckSaveBonus() {
    // +1 on adverse-happening dice rolls
    return 1;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpLuckSavePctBonus() {
    // +5 percent where applicable
    return 5;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpLuckItemPctMin() {
    // 1 percent on magic item and treasure division rolls
    return 1;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpLuckItemPctMax() {
    // up to 10 percent at owner option
    return 10;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpLoadMoveReductionPct() {
    // a 50 percent reduction in movement when haste is due
    return 50;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpLoadAttackReductionPct() {
    // attacks also reduced to 50 percent normal rate
    return 50;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpLoadDispelClears() {
    // a dispel evil makes the item disappear
    return 1;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpPureGoodCharges() {
    // the talisman of pure good has 7 charges
    return 7;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpPureGoodRechargeable() {
    // it cannot be recharged
    return 0;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpPureGoodNeutralDmgMin() {
    // a neutral cleric touching it takes 7-28 damage
    return 7;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpPureGoodNeutralDmgMax() {
    // the neutral touch ceiling
    return 28;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpPureGoodEvilDmgMin() {
    // an evil cleric touching it takes 12-48 damage
    return 12;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpPureGoodEvilDmgMax() {
    // the evil touch ceiling
    return 48;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpPureGoodNonClericDmg() {
    // non-clerics are not affected by the device
    return 0;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereTaliNonMuDmgMin() {
    // any other class touching it takes 5-30 damage
    return 5;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereTaliNonMuDmgMax() {
    // the wrong-class touch ceiling
    return 30;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereTaliLowPctPerPoint() {
    // doubles the bonus: 2 percent per point 13-15
    return 2;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereTaliHighPctPerPoint() {
    // and 6 percent per point 16-18
    return 6;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereTaliCheckIntervalRounds() {
    // held, the wielder checks control every other round
    return 2;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereTaliMaxMoveFeet() {
    // an uncontrolled sphere approaches at 16 feet
    return 16;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereWandNegationOnTalisman() {
    // a wand of negation stops the talisman control
    return 1;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSphereWandNegationOnSphere() {
    // but has no effect upon the sphere itself
    return 0;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpUltimateEvilCharges() {
    // the exact opposite of pure good; 6 charges
    return 6;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpZagyHostileDmgMin() {
    // a hostile reaction acts as a stone of weight;
    // discarding or destroying it costs 5-30 damage
    return 5;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpZagyHostileDmgMax() {
    // the hostile discard ceiling
    return 30;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpZagyNeutralHoursMin() {
    // a neutral reaction stays 5-30 hours
    return 5;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpZagyNeutralHoursMax() {
    // the neutral stay ceiling
    return 30;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpZagyFriendlyMonthsPerChaPoint() {
    // friendly, it stays one month per charisma point
    return 1;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpZagyWishChaDivisor() {
    // it grants 1 wish per 6 charisma points
    return 6;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpZagyTrapRangeFeet() {
    // it grows warm within 20 feet of a trap
    return 20;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpZagyDiamondGp() {
    // a base 10,000 gp diamond remains behind
    return 10000;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpClearThoughtIntGain() {
    // the tome raises intelligence by 1 point
    return 1;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpClearThoughtReadHours() {
    // reading takes 48 hours over 6 days
    return 48;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpClearThoughtReadDays() {
    // the six reading days
    return 6;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpClearThoughtStartWeeks() {
    // the exercises must begin within 1 week
    return 1;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpClearThoughtGainMonths() {
    // intelligence goes up after 1 full month
    return 1;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpClearThoughtRereadGain() {
    // any further perusal is of no benefit
    return 0;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpLeadershipChaGain() {
    // leadership and influence raises charisma by 1
    return 1;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpUnderstandingWisGain() {
    // the tome of understanding raises wisdom by 1
    return 1;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpFishCmdRadiusInches() {
    // all fish within a 6 inch radius save versus magic
    return 6;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpFishCmdChargeCost() {
    // the command uses one charge
    return 1;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpFishCmdProtectFeet() {
    // commanded fish spare all within 10 feet
    return 10;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpFishCmdApproachFeet() {
    // free fish keep 10 feet off the trident
    return 10;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpFishCmdSchoolsAsOne() {
    // schooling fish check as a single entity
    return 1;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpFishCmdChargesMin() {
    // it contains 17-20 charges
    return 17;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpFishCmdChargesMax() {
    // the charge ceiling
    return 20;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpFishCmdMagicBonus() {
    // otherwise a +1 magic weapon
    return 1;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSubmitMoraleDelayRounds() {
    // a failed save means a morale check the next round
    return 1;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSubmitHopelessRoundsMin() {
    // the hopelessness lasts 2-8 rounds
    return 2;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSubmitHopelessRoundsMax() {
    // the hopelessness ceiling
    return 8;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSubmitChargesMin() {
    // it has 17-20 charges
    return 17;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSubmitChargesMax() {
    // the charge ceiling
    return 20;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpSubmitMagicBonus() {
    // a +1 magic weapon
    return 1;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpWarningRadiusInches() {
    // it scans hostile hungry predators within 24 inches
    return 24;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpWarningScanRounds() {
    // one round scans the 24 inch hemisphere
    return 1;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpWarningChargesMin() {
    // it carries 19-24 charges
    return 19;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpWarningChargesMax() {
    // the charge ceiling
    return 24;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpWarningChargeRounds() {
    // each charge lasts for 2 rounds of scanning
    return 2;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpWarningMagicBonus() {
    // otherwise a +2 magic weapon
    return 2;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpYearningMagicPenalty() {
    // a -2 cursed magical weapon
    return 2;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpYearningFreeingSpells() {
    // freed by water breathing, wish or alter reality
    return 3;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpYearningGrantsWaterBreathing() {
    // it does not confer the ability to breathe underwater
    return 0;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpVacuousSaveCount() {
    // the reader must make 2 saving throws versus magic
    return 2;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpVacuousIntLoss() {
    // the first throw: 1 point of intelligence lost
    return 1;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpVacuousWisLoss() {
    // the second throw: 2 points of wisdom lost
    return 2;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpVacuousBurnAfterRemoveCurse() {
    // it must be burned to be rid of after remove curse
    return 1;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpWellTwoWay() {
    // things come through the opening both ways
    return 1;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpWingsSpanFeet() {
    // gigantic bat wings of 20 foot span
    return 20;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpWingsRestHours() {
    // after maximum flight the wearer rests 1 hour
    return 1;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpWingsQuietHours() {
    // shorter flights need only 1 hour of quiet
    return 1;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpWingsNoRestTurns() {
    // flights under 1 turn need no rest at all
    return 1;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpWingsUsesPerDay() {
    // the wings work but once per day
    return 1;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpWingsSupportPounds() {
    // they support up to 500 pounds weight
    return 500;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpWingsSpeedRows() {
    // the duration list has three entries
    return 3;
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpWingsSpeedTurns(int i) {
    // the turns flown per speed entry; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    // 2 turns at 32 inches, 4 at 18, 8 at 12
    static const int t[3] = {
        2, 4, 8,
    };
    return t[i];
}

int Miscmagic_sphere_of_annihilation_to_wings_of_flying::mmpWingsSpeedInches(int i) {
    // the flight speed per entry; i clamps
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    static const int t[3] = {
        32, 18, 12,
    };
    return t[i];
}
