// ====================================================================
// Adnd1 - rules/ringsprose3.h
// R256: the III.C rings explanation prose part 3
// pins (DMG pp.139-140) - Spell Storing
// through X-Ray Vision, the final ten
// rings of the EXPLANATIONS AND
// DESCRIPTIONS section (upload lines
// ~10458-10561):
//   - Spell Storing: 2-5 (d4+1) spells;
//     cleric d6, 6 rolls d4 instead;
//     magic-user d8, 8 rolls d6 instead;
//     druid and illusionist as cleric;
//     properties fixed once determined;
//     a 12th level magic-user restores
//     a 6th level spell; 5 segments each.
//   - Spell Turning: 3 exceptions (area
//     spells, touch, devices; a scroll
//     spell is not a device); percentile
//     rounding 1-5 down, 6-9 up, 05 = 0%
//     and 96 = 100%; saves +1 per 10%
//     below 100% (80% = +2 ... 10% = +9);
//     the 09-or-less / 91-or-more band
//     excludes the special save; 5% per
//     10% turned (11-19: roll 20 saves);
//     the maze example: 34% turned, the
//     fighter saves 15%, the illusionist
//     30% on 15-20; remove to receive;
//     psionics are not spell casting;
//     the 4-row resonating field table.
//   - Swimming: 21 inch base; 50 foot
//     dive; 1.5 feet of depth per 10
//     feet; 4 rounds breath; 4 hours
//     then 1 hour rest; afloat in all
//     but typhoon-like conditions.
//   - Telekinesis: the 5-row weight
//     table 250/500/1000/2000/4000 gp;
//     1 segment to begin; double-
//     dagger flagged.
//   - Three Wishes: 3 wishes; 25%
//     (01-25) are 3 limited wishes;
//     double-dagger flagged.
//   - Warmth: restores 1 hp per turn;
//     cold saves +2; cold damage -1
//     per die.
//   - Water Walking: any liquid; 1200
//     pounds; 1.5 foot by 1 inch
//     depressions per 100 pounds.
//   - Weakness: cursed; 1 point per
//     turn to 3; invisible at will
//     doubles the loss; remove curse
//     then dispel magic; 5% reversed
//     berserk (to 18s, 1 per turn,
//     then always melee); rest 1 day
//     per point.
//   - Wizardry: MU only (other classes
//     can neither use nor understand);
//     the 8-row doubling table; (M) and
//     double-dagger flagged.
//   - X-Ray Vision: 20 feet; the
//     5-substance penetration table;
//     100 sq ft per round; 90% secret
//     doors; 1 constitution per use
//     more than once every 6 turns
//     (2 points at 3 turns per hour,
//     3 at 4); 2 points per day rest;
//     exhausted at 2, resume at 3.
// The ten rings are the engine III.C
// table rows 64-100 (dm/treasure.cpp
// kRings, the R223 rings.h band pins)
// - cross-checked in the audit, with
// the Telekinesis / Three Wishes /
// Wizardry double-daggers cross-pinned
// against the R255-fixed charge array.
// Pure data + helpers, header-only (the
// grenade.h pattern).
// ====================================================================

#pragma once

namespace rules {

inline int rgpSpellStoringSpellLo() {
    // contains from 2 spells
    return 2;
}

inline int rgpSpellStoringSpellHi() {
    // contains up to 5 spells
    return 5;
}

inline int rgpSpellStoringSpellDice() {
    // 2-5 is d4 + 1: one die
    return 1;
}

inline int rgpSpellStoringSpellPlus() {
    // the + 1 of d4 + 1
    return 1;
}

inline int rgpSpellStoringClericFaces() {
    // cleric spell level: d6
    return 6;
}

inline int rgpSpellStoringClericSwapOn() {
    // if 6 is rolled
    return 6;
}

inline int rgpSpellStoringClericSwapFaces() {
    // roll d4 instead
    return 4;
}

inline int rgpSpellStoringMuFaces() {
    // magic-user spell level: d8
    return 8;
}

inline int rgpSpellStoringMuSwapOn() {
    // if 8 is rolled
    return 8;
}

inline int rgpSpellStoringMuSwapFaces() {
    // roll d6 instead
    return 6;
}

inline int rgpSpellStoringRestoreMULevel() {
    // a 12th level magic-user restores
    return 12;
}

inline int rgpSpellStoringRestoreSpellLevel() {
    // a 6th level magic-user spell
    return 6;
}

inline int rgpSpellStoringCastSegments() {
    // spells stored require 5 segments
    // each to cast
    return 5;
}

inline int rgpSpellTurningExceptionCount() {
    // area spells, touch, devices
    return 3;
}

inline int rgpSpellTurningScrollIsDevice() {
    // a scroll spell is not a device
    return 0;
}

inline int rgpSpellTurningRoundDownMax() {
    // 1-5 is dropped
    return 5;
}

inline int rgpSpellTurningRoundUpMin() {
    // 6-9 rounds up
    return 6;
}

inline int rgpSpellTurningRoundUpAdd() {
    // the rounding adds 10
    return 10;
}

inline int rgpSpellTurningFloorExample() {
    // so 05 equals 0%
    return 0;
}

inline int rgpSpellTurningCeilExample() {
    // but 96 equals 100%
    return 100;
}

inline int rgpSpellTurningSaveAdjPer10Pct() {
    // saves +1 for each 10% below 100%
    return 1;
}

inline int rgpSpellTurningSaveAdjAt80() {
    // 80% = +2
    return 2;
}

inline int rgpSpellTurningSaveAdjAt10() {
    // 10% = +9
    return 9;
}

inline int rgpSpellTurningSpecialSaveLowMax() {
    // at 09 or less the special save
    // does not apply
    return 9;
}

inline int rgpSpellTurningSpecialSaveHighMin() {
    // at 91 or more it does not apply
    // either
    return 91;
}

inline int rgpSpellTurningSaveChancePer10Pct() {
    // for each 10% turned, a 5% chance
    // (1 in 20) to save
    return 5;
}

inline int rgpSpellTurningLowBandSaveRoll() {
    // if 11-19 is rolled, a roll of
    // 20 saves
    return 20;
}

inline int rgpSpellTurningExampleTurnedPct() {
    // the maze example: the ring turns
    // 34% of the spell effect
    return 34;
}

inline int rgpSpellTurningExampleWearerSave() {
    // the fighter has a 15% chance to
    // save
    return 15;
}

inline int rgpSpellTurningExampleCasterSave() {
    // the illusionist converts to a
    // 30% chance to save
    return 30;
}

inline int rgpSpellTurningExampleCasterRollLo() {
    // by rolling a 15-20
    return 15;
}

inline int rgpSpellTurningMustRemoveToReceive() {
    // the wearer must remove the ring
    // to receive a spell
    return 1;
}

inline int rgpSpellTurningPsionicIsSpellcasting() {
    // psionic attacks are not
    // considered spell casting
    return 0;
}

inline int rgpSpellTurningResonantRowCount() {
    // both wear rings: 4 results
    return 4;
}

inline int rgpSpellTurningResonantLo(int i) {
    // the resonating field bands:
    // 01-70 drains, 71-80 both full,
    // 81-97 both drained, 98-00 rift
    static const int t[4] = {
        1, 71, 81, 98,
    };
    return t[i];
}

inline int rgpSpellTurningResonantHi(int i) {
    static const int t[4] = {
        70, 80, 97, 100,
    };
    return t[i];
}

inline int rgpSwimmingBaseSpeedInches() {
    // swim at a full 21 inch base
    // speed
    return 21;
}

inline int rgpSwimmingDiveFeet() {
    // dive up to 50 feet without
    // injury
    return 50;
}

inline int rgpSwimmingDiveDepthInchesPer10Feet() {
    // water at least 1.5 feet deep
    // per 10 feet of diving elevation
    return 18;
}

inline int rgpSwimmingBreathRounds() {
    // stay underwater up to 4 rounds
    return 4;
}

inline int rgpSwimmingSurfaceHours() {
    // surface swimming 4 hours
    return 4;
}

inline int rgpSwimmingRestHours() {
    // then a 1 hour floating rest
    return 1;
}

inline int rgpSwimmingAfloatExceptTyphoon() {
    // afloat under all but
    // typhoon-like conditions
    return 1;
}

inline int rgpTelekinesisRowCount() {
    // the weight table has 5 rows
    return 5;
}

inline int rgpTelekinesisRowLo(int i) {
    // bands 01-25, 26-50, 51-89,
    // 90-99, 00
    static const int t[5] = {
        1, 26, 51, 90, 100,
    };
    return t[i];
}

inline int rgpTelekinesisRowHi(int i) {
    static const int t[5] = {
        25, 50, 89, 99, 100,
    };
    return t[i];
}

inline int rgpTelekinesisRowGp(int i) {
    // 250 / 500 / 1000 / 2000 /
    // 4000 g.p. maximum
    static const int t[5] = {
        250, 500, 1000, 2000, 4000,
    };
    return t[i];
}

inline int rgpTelekinesisStartSegments() {
    // 1 segment to begin the effect
    return 1;
}

inline int rgpTelekinesisDaggerFlag() {
    // the prose entry carries the
    // double-dagger
    return 1;
}

inline int rgpThreeWishesWishCount() {
    // contains 3 wish spells
    return 3;
}

inline int rgpThreeWishesLimitedPct() {
    // 25% are limited wish rings
    return 25;
}

inline int rgpThreeWishesLimitedBandLo() {
    // the 01-25 band
    return 1;
}

inline int rgpThreeWishesLimitedBandHi() {
    return 25;
}

inline int rgpThreeWishesDaggerFlag() {
    // the table carries the
    // double-dagger (row 18)
    return 1;
}

inline int rgpWarmthRestoreHpPerTurn() {
    // restores cold-sustained damage
    // at 1 hp per turn
    return 1;
}

inline int rgpWarmthColdSaveBonus() {
    // cold saves +2
    return 2;
}

inline int rgpWarmthColdDamagePerDieMod() {
    // cold damage -1 per die
    return -1;
}

inline int rgpWaterWalkingMaxLoadPounds() {
    // supports up to 1200 pounds
    return 1200;
}

inline int rgpWaterWalkingDepressionLengthInches() {
    // oval depressions about 1.5
    // feet long
    return 18;
}

inline int rgpWaterWalkingDepressionDepthInches() {
    // 1 inch deep
    return 1;
}

inline int rgpWaterWalkingDepressionPerPounds() {
    // per 100 pounds of weight
    return 100;
}

inline int rgpWeaknessLossPerTurn() {
    // lose 1 point of strength and
    // 1 point of constitution
    return 1;
}

inline int rgpWeaknessFloorScore() {
    // until 3 in each ability area
    return 3;
}

inline int rgpWeaknessInvisibleFlag() {
    // the ring also makes the wearer
    // invisible at will
    return 1;
}

inline int rgpWeaknessInvisibleLossMultiplier() {
    // invisibility doubles the loss
    // rate
    return 2;
}

inline int rgpWeaknessBerserkChancePct() {
    // 5% chance the ring is reversed
    return 5;
}

inline int rgpWeaknessBerserkTargetScore() {
    // berserk strength rises to 18
    // in each ability
    return 18;
}

inline int rgpWeaknessBerserkGainPerTurn() {
    // increase is 1 point per
    // ability per turn
    return 1;
}

inline int rgpWeaknessRestDaysPerPoint() {
    // restored by rest, 1 day for
    // 1 point
    return 1;
}

inline int rgpWizardryRowCount() {
    // the doubling table has 8 rows
    return 8;
}

inline int rgpWizardryRowLo(int i) {
    // bands 01-50, 51-75, 76-82,
    // 83-88, 89-92, 93-95, 96-99, 00
    static const int t[8] = {
        1, 51, 76, 83, 89, 93, 96, 100,
    };
    return t[i];
}

inline int rgpWizardryRowHi(int i) {
    static const int t[8] = {
        50, 75, 82, 88, 92, 95, 99, 100,
    };
    return t[i];
}

inline int rgpWizardryRowSpellLo(int i) {
    // doubles: first, second, third,
    // first+second, fourth, fifth,
    // first through third,
    // fourth+fifth
    static const int t[8] = {
        1, 2, 3, 1, 4, 5, 1, 4,
    };
    return t[i];
}

inline int rgpWizardryRowSpellHi(int i) {
    static const int t[8] = {
        1, 2, 3, 2, 4, 5, 3, 5,
    };
    return t[i];
}

inline int rgpWizardryMuOnlyFlag() {
    // only magic-users benefit; the
    // (M) row 22
    return 1;
}

inline int rgpWizardryDaggerFlag() {
    // the table carries the
    // double-dagger (row 22)
    return 1;
}

inline int rgpXRayVisionRangeFeet() {
    // vision range is 20 feet
    return 20;
}

inline int rgpXRayScanSqFtPerRound() {
    // scans 100 square feet per round
    return 100;
}

inline int rgpXRaySecretFindPct() {
    // secret compartments, drawers,
    // recesses and doors 90% likely
    return 90;
}

inline int rgpXRayDrainIntervalTurns() {
    // drains if used more frequently
    // than once every 6 turns
    return 6;
}

inline int rgpXRayDrainAmount() {
    // drains 1 point of constitution
    return 1;
}

inline int rgpXRayDrainAt3TurnsPerHour() {
    // 3 turns in 1 hour loses 2
    // points
    return 2;
}

inline int rgpXRayDrainAt4TurnsPerHour() {
    // 4 turns loses 3 points
    return 3;
}

inline int rgpXRayConRecoveryPerDay() {
    // recovered at 2 points per day
    // of rest
    return 2;
}

inline int rgpXRayExhaustedScore() {
    // constitution of 2 means
    // exhausted, must rest
    return 2;
}

inline int rgpXRayResumeScore() {
    // no activity until constitution
    // of 3 or better
    return 3;
}

inline int rgpXRaySubstanceCount() {
    // the penetration table has 5
    // substances
    return 5;
}

inline int rgpXRaySubstanceRateInches(int i) {
    // per round: animal 4 feet,
    // vegetable 2.5 feet, stone 1
    // foot, iron 1 inch, lead nil
    static const int t[5] = {
        48, 30, 12, 1, 0,
    };
    return t[i];
}

inline int rgpXRaySubstanceMaxInches(int i) {
    // maximum: 20 feet, 20 feet,
    // 10 feet, 10 inches, nil
    static const int t[5] = {
        240, 240, 120, 10, 0,
    };
    return t[i];
}

}  // namespace rules
