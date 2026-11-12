// R-refactor: split from rings_spell_storing_to_x_ray_vision.h - definitions
#include "rules/dmg/rings_spell_storing_to_x_ray_vision.h"

int Rings_spell_storing_to_x_ray_vision::rgpSpellStoringSpellLo() {
    // contains from 2 spells
    return 2;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellStoringSpellHi() {
    // contains up to 5 spells
    return 5;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellStoringSpellDice() {
    // 2-5 is d4 + 1: one die
    return 1;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellStoringSpellPlus() {
    // the + 1 of d4 + 1
    return 1;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellStoringClericFaces() {
    // cleric spell level: d6
    return 6;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellStoringClericSwapOn() {
    // if 6 is rolled
    return 6;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellStoringClericSwapFaces() {
    // roll d4 instead
    return 4;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellStoringMuFaces() {
    // magic-user spell level: d8
    return 8;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellStoringMuSwapOn() {
    // if 8 is rolled
    return 8;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellStoringMuSwapFaces() {
    // roll d6 instead
    return 6;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellStoringRestoreMULevel() {
    // a 12th level magic-user restores
    return 12;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellStoringRestoreSpellLevel() {
    // a 6th level magic-user spell
    return 6;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellStoringCastSegments() {
    // spells stored require 5 segments
    // each to cast
    return 5;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellTurningExceptionCount() {
    // area spells, touch, devices
    return 3;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellTurningScrollIsDevice() {
    // a scroll spell is not a device
    return 0;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellTurningRoundDownMax() {
    // 1-5 is dropped
    return 5;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellTurningRoundUpMin() {
    // 6-9 rounds up
    return 6;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellTurningRoundUpAdd() {
    // the rounding adds 10
    return 10;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellTurningFloorExample() {
    // so 05 equals 0%
    return 0;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellTurningCeilExample() {
    // but 96 equals 100%
    return 100;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellTurningSaveAdjPer10Pct() {
    // saves +1 for each 10% below 100%
    return 1;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellTurningSaveAdjAt80() {
    // 80% = +2
    return 2;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellTurningSaveAdjAt10() {
    // 10% = +9
    return 9;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellTurningSpecialSaveLowMax() {
    // at 09 or less the special save
    // does not apply
    return 9;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellTurningSpecialSaveHighMin() {
    // at 91 or more it does not apply
    // either
    return 91;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellTurningSaveChancePer10Pct() {
    // for each 10% turned, a 5% chance
    // (1 in 20) to save
    return 5;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellTurningLowBandSaveRoll() {
    // if 11-19 is rolled, a roll of
    // 20 saves
    return 20;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellTurningExampleTurnedPct() {
    // the maze example: the ring turns
    // 34% of the spell effect
    return 34;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellTurningExampleWearerSave() {
    // the fighter has a 15% chance to
    // save
    return 15;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellTurningExampleCasterSave() {
    // the illusionist converts to a
    // 30% chance to save
    return 30;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellTurningExampleCasterRollLo() {
    // by rolling a 15-20
    return 15;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellTurningMustRemoveToReceive() {
    // the wearer must remove the ring
    // to receive a spell
    return 1;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellTurningPsionicIsSpellcasting() {
    // psionic attacks are not
    // considered spell casting
    return 0;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellTurningResonantRowCount() {
    // both wear rings: 4 results
    return 4;
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellTurningResonantLo(int i) {
    // the resonating field bands:
    // 01-70 drains, 71-80 both full,
    // 81-97 both drained, 98-00 rift
    static const int t[4] = {
        1, 71, 81, 98,
    };
    return t[i];
}

int Rings_spell_storing_to_x_ray_vision::rgpSpellTurningResonantHi(int i) {
    static const int t[4] = {
        70, 80, 97, 100,
    };
    return t[i];
}

int Rings_spell_storing_to_x_ray_vision::rgpSwimmingBaseSpeedInches() {
    // swim at a full 21 inch base
    // speed
    return 21;
}

int Rings_spell_storing_to_x_ray_vision::rgpSwimmingDiveFeet() {
    // dive up to 50 feet without
    // injury
    return 50;
}

int Rings_spell_storing_to_x_ray_vision::rgpSwimmingDiveDepthInchesPer10Feet() {
    // water at least 1.5 feet deep
    // per 10 feet of diving elevation
    return 18;
}

int Rings_spell_storing_to_x_ray_vision::rgpSwimmingBreathRounds() {
    // stay underwater up to 4 rounds
    return 4;
}

int Rings_spell_storing_to_x_ray_vision::rgpSwimmingSurfaceHours() {
    // surface swimming 4 hours
    return 4;
}

int Rings_spell_storing_to_x_ray_vision::rgpSwimmingRestHours() {
    // then a 1 hour floating rest
    return 1;
}

int Rings_spell_storing_to_x_ray_vision::rgpSwimmingAfloatExceptTyphoon() {
    // afloat under all but
    // typhoon-like conditions
    return 1;
}

int Rings_spell_storing_to_x_ray_vision::rgpTelekinesisRowCount() {
    // the weight table has 5 rows
    return 5;
}

int Rings_spell_storing_to_x_ray_vision::rgpTelekinesisRowLo(int i) {
    // bands 01-25, 26-50, 51-89,
    // 90-99, 00
    static const int t[5] = {
        1, 26, 51, 90, 100,
    };
    return t[i];
}

int Rings_spell_storing_to_x_ray_vision::rgpTelekinesisRowHi(int i) {
    static const int t[5] = {
        25, 50, 89, 99, 100,
    };
    return t[i];
}

int Rings_spell_storing_to_x_ray_vision::rgpTelekinesisRowGp(int i) {
    // 250 / 500 / 1000 / 2000 /
    // 4000 g.p. maximum
    static const int t[5] = {
        250, 500, 1000, 2000, 4000,
    };
    return t[i];
}

int Rings_spell_storing_to_x_ray_vision::rgpTelekinesisStartSegments() {
    // 1 segment to begin the effect
    return 1;
}

int Rings_spell_storing_to_x_ray_vision::rgpTelekinesisDaggerFlag() {
    // the prose entry carries the
    // double-dagger
    return 1;
}

int Rings_spell_storing_to_x_ray_vision::rgpThreeWishesWishCount() {
    // contains 3 wish spells
    return 3;
}

int Rings_spell_storing_to_x_ray_vision::rgpThreeWishesLimitedPct() {
    // 25% are limited wish rings
    return 25;
}

int Rings_spell_storing_to_x_ray_vision::rgpThreeWishesLimitedBandLo() {
    // the 01-25 band
    return 1;
}

int Rings_spell_storing_to_x_ray_vision::rgpThreeWishesLimitedBandHi() {
    return 25;
}

int Rings_spell_storing_to_x_ray_vision::rgpThreeWishesDaggerFlag() {
    // the table carries the
    // double-dagger (row 18)
    return 1;
}

int Rings_spell_storing_to_x_ray_vision::rgpWarmthRestoreHpPerTurn() {
    // restores cold-sustained damage
    // at 1 hp per turn
    return 1;
}

int Rings_spell_storing_to_x_ray_vision::rgpWarmthColdSaveBonus() {
    // cold saves +2
    return 2;
}

int Rings_spell_storing_to_x_ray_vision::rgpWarmthColdDamagePerDieMod() {
    // cold damage -1 per die
    return -1;
}

int Rings_spell_storing_to_x_ray_vision::rgpWaterWalkingMaxLoadPounds() {
    // supports up to 1200 pounds
    return 1200;
}

int Rings_spell_storing_to_x_ray_vision::rgpWaterWalkingDepressionLengthInches() {
    // oval depressions about 1.5
    // feet long
    return 18;
}

int Rings_spell_storing_to_x_ray_vision::rgpWaterWalkingDepressionDepthInches() {
    // 1 inch deep
    return 1;
}

int Rings_spell_storing_to_x_ray_vision::rgpWaterWalkingDepressionPerPounds() {
    // per 100 pounds of weight
    return 100;
}

int Rings_spell_storing_to_x_ray_vision::rgpWeaknessLossPerTurn() {
    // lose 1 point of strength and
    // 1 point of constitution
    return 1;
}

int Rings_spell_storing_to_x_ray_vision::rgpWeaknessFloorScore() {
    // until 3 in each ability area
    return 3;
}

int Rings_spell_storing_to_x_ray_vision::rgpWeaknessInvisibleFlag() {
    // the ring also makes the wearer
    // invisible at will
    return 1;
}

int Rings_spell_storing_to_x_ray_vision::rgpWeaknessInvisibleLossMultiplier() {
    // invisibility doubles the loss
    // rate
    return 2;
}

int Rings_spell_storing_to_x_ray_vision::rgpWeaknessBerserkChancePct() {
    // 5% chance the ring is reversed
    return 5;
}

int Rings_spell_storing_to_x_ray_vision::rgpWeaknessBerserkTargetScore() {
    // berserk strength rises to 18
    // in each ability
    return 18;
}

int Rings_spell_storing_to_x_ray_vision::rgpWeaknessBerserkGainPerTurn() {
    // increase is 1 point per
    // ability per turn
    return 1;
}

int Rings_spell_storing_to_x_ray_vision::rgpWeaknessRestDaysPerPoint() {
    // restored by rest, 1 day for
    // 1 point
    return 1;
}

int Rings_spell_storing_to_x_ray_vision::rgpWizardryRowCount() {
    // the doubling table has 8 rows
    return 8;
}

int Rings_spell_storing_to_x_ray_vision::rgpWizardryRowLo(int i) {
    // bands 01-50, 51-75, 76-82,
    // 83-88, 89-92, 93-95, 96-99, 00
    static const int t[8] = {
        1, 51, 76, 83, 89, 93, 96, 100,
    };
    return t[i];
}

int Rings_spell_storing_to_x_ray_vision::rgpWizardryRowHi(int i) {
    static const int t[8] = {
        50, 75, 82, 88, 92, 95, 99, 100,
    };
    return t[i];
}

int Rings_spell_storing_to_x_ray_vision::rgpWizardryRowSpellLo(int i) {
    // doubles: first, second, third,
    // first+second, fourth, fifth,
    // first through third,
    // fourth+fifth
    static const int t[8] = {
        1, 2, 3, 1, 4, 5, 1, 4,
    };
    return t[i];
}

int Rings_spell_storing_to_x_ray_vision::rgpWizardryRowSpellHi(int i) {
    static const int t[8] = {
        1, 2, 3, 2, 4, 5, 3, 5,
    };
    return t[i];
}

int Rings_spell_storing_to_x_ray_vision::rgpWizardryMuOnlyFlag() {
    // only magic-users benefit; the
    // (M) row 22
    return 1;
}

int Rings_spell_storing_to_x_ray_vision::rgpWizardryDaggerFlag() {
    // the table carries the
    // double-dagger (row 22)
    return 1;
}

int Rings_spell_storing_to_x_ray_vision::rgpXRayVisionRangeFeet() {
    // vision range is 20 feet
    return 20;
}

int Rings_spell_storing_to_x_ray_vision::rgpXRayScanSqFtPerRound() {
    // scans 100 square feet per round
    return 100;
}

int Rings_spell_storing_to_x_ray_vision::rgpXRaySecretFindPct() {
    // secret compartments, drawers,
    // recesses and doors 90% likely
    return 90;
}

int Rings_spell_storing_to_x_ray_vision::rgpXRayDrainIntervalTurns() {
    // drains if used more frequently
    // than once every 6 turns
    return 6;
}

int Rings_spell_storing_to_x_ray_vision::rgpXRayDrainAmount() {
    // drains 1 point of constitution
    return 1;
}

int Rings_spell_storing_to_x_ray_vision::rgpXRayDrainAt3TurnsPerHour() {
    // 3 turns in 1 hour loses 2
    // points
    return 2;
}

int Rings_spell_storing_to_x_ray_vision::rgpXRayDrainAt4TurnsPerHour() {
    // 4 turns loses 3 points
    return 3;
}

int Rings_spell_storing_to_x_ray_vision::rgpXRayConRecoveryPerDay() {
    // recovered at 2 points per day
    // of rest
    return 2;
}

int Rings_spell_storing_to_x_ray_vision::rgpXRayExhaustedScore() {
    // constitution of 2 means
    // exhausted, must rest
    return 2;
}

int Rings_spell_storing_to_x_ray_vision::rgpXRayResumeScore() {
    // no activity until constitution
    // of 3 or better
    return 3;
}

int Rings_spell_storing_to_x_ray_vision::rgpXRaySubstanceCount() {
    // the penetration table has 5
    // substances
    return 5;
}

int Rings_spell_storing_to_x_ray_vision::rgpXRaySubstanceRateInches(int i) {
    // per round: animal 4 feet,
    // vegetable 2.5 feet, stone 1
    // foot, iron 1 inch, lead nil
    static const int t[5] = {
        48, 30, 12, 1, 0,
    };
    return t[i];
}

int Rings_spell_storing_to_x_ray_vision::rgpXRaySubstanceMaxInches(int i) {
    // maximum: 20 feet, 20 feet,
    // 10 feet, 10 inches, nil
    static const int t[5] = {
        240, 240, 120, 10, 0,
    };
    return t[i];
}
