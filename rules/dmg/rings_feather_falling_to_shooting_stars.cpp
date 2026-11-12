// R-refactor: split from rings_feather_falling_to_shooting_stars.h - definitions
#include "rules/dmg/rings_feather_falling_to_shooting_stars.h"

int Rings_feather_falling_to_shooting_stars::rgpFeatherFallMinFeet() {
    // automatic activation if the
    // individual falls 5 feet or more
    return 5;
}

int Rings_feather_falling_to_shooting_stars::rgpFireResistLargeFireDamagePerRound() {
    // very large and hot fires cause
    // this much per round
    return 10;
}

int Rings_feather_falling_to_shooting_stars::rgpFireResistLargeFirePerSegment() {
    // the same damage expressed per
    // segment
    return 1;
}

int Rings_feather_falling_to_shooting_stars::rgpFireResistHotSaveBonus() {
    // exceptionally hot fires are
    // saved against at +4
    return 4;
}

int Rings_feather_falling_to_shooting_stars::rgpFireResistHotDamagePerDieMod() {
    // all damage dice calculated at
    // -2 per die
    return -2;
}

int Rings_feather_falling_to_shooting_stars::rgpFireResistHotDieFloor() {
    // each die is never less than 1
    return 1;
}

int Rings_feather_falling_to_shooting_stars::rgpFireResistVeryHotExposureMax() {
    // rule of thumb: very hot fires
    // are up to 24 hit points of
    // maximum initial exposure
    return 24;
}

int Rings_feather_falling_to_shooting_stars::rgpFireResistExceptionalExposureMin() {
    // fires of exceptional heat are
    // 25 or more hit points
    return 25;
}

int Rings_feather_falling_to_shooting_stars::rgpHumanInfluenceCharisma() {
    // raises the wearer charisma to
    // 18 for encounter reactions
    return 18;
}

int Rings_feather_falling_to_shooting_stars::rgpHumanInfluenceCharmLevels() {
    // charm up to 21 levels/hit
    // dice of humans/humanoids
    return 21;
}

int Rings_feather_falling_to_shooting_stars::rgpHumanInfluenceUsesPerDay() {
    // suggestion and charm are each
    // applicable but once per day
    return 1;
}

int Rings_feather_falling_to_shooting_stars::rgpHumanInfluenceCastSegments() {
    // suggestion or charm requires
    // 3 segments of casting time
    return 3;
}

int Rings_feather_falling_to_shooting_stars::rgpHumanInfluenceDaggerFlag() {
    // the prose entry carries the
    // double-dagger; cross-pins the
    // R223 charge-limited row 7
    return 1;
}

int Rings_feather_falling_to_shooting_stars::rgpInvisibilityInaudiblePercent() {
    // 10% of these rings also have
    // inaudibility
    return 10;
}

int Rings_feather_falling_to_shooting_stars::rgpMammalControlMaxIntelligence() {
    // controls mammals with
    // intelligence of 4 or less
    return 4;
}

int Rings_feather_falling_to_shooting_stars::rgpMammalControlHitDice() {
    // up to 30 hit dice of mammals
    return 30;
}

int Rings_feather_falling_to_shooting_stars::rgpMammalControlTimeSegments() {
    // control time is 3 segments
    return 3;
}

int Rings_feather_falling_to_shooting_stars::rgpMammalControlDaggerFlag() {
    // the prose entry carries the
    // double-dagger; the R255 fix
    // made the R223 array flag
    // row 9 correctly
    return 1;
}

int Rings_feather_falling_to_shooting_stars::rgpMultipleWishesLo() {
    // contains from 2 wish spells
    return 2;
}

int Rings_feather_falling_to_shooting_stars::rgpMultipleWishesHi() {
    // up to 8 wish spells
    return 8;
}

int Rings_feather_falling_to_shooting_stars::rgpMultipleWishesDice() {
    // 2 dice
    return 2;
}

int Rings_feather_falling_to_shooting_stars::rgpMultipleWishesFaces() {
    // of 4 faces each
    return 4;
}

int Rings_feather_falling_to_shooting_stars::rgpMultipleWishesDaggerFlag() {
    // the prose entry carries the
    // double-dagger; cross-pins the
    // R223 charge-limited row 10
    return 1;
}

int Rings_feather_falling_to_shooting_stars::rgpProtectionRowCount() {
    // the value table has 7 rows
    return 7;
}

int Rings_feather_falling_to_shooting_stars::rgpProtectionRowLo(int i) {
    // the row lower edges: 01-70,
    // 71-82, 83, 84-90, 91, 92-97,
    // 98-00; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        1, 71, 83, 84, 91, 92, 98,
    };
    return t[i];
}

int Rings_feather_falling_to_shooting_stars::rgpProtectionRowHi(int i) {
    // the row upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        70, 82, 83, 90, 91, 97, 100,
    };
    return t[i];
}

int Rings_feather_falling_to_shooting_stars::rgpProtectionRowAc(int i) {
    // the armor class bonus per row:
    // +1, +2, +2, +3, +3, +4, +6;
    // i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        1, 2, 2, 3, 3, 4, 6,
    };
    return t[i];
}

int Rings_feather_falling_to_shooting_stars::rgpProtectionRowSave(int i) {
    // the saving throw bonus per
    // row: +1, +2, +2, +3, +3,
    // +2, +1; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        1, 2, 2, 3, 3, 2, 1,
    };
    return t[i];
}

int Rings_feather_falling_to_shooting_stars::rgpProtectionRowRadius(int i) {
    // rows 83 and 91 carry the 5
    // foot radius protection; i
    // clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        0, 0, 1, 0, 1, 0, 0,
    };
    return t[i];
}

int Rings_feather_falling_to_shooting_stars::rgpProtectionRadiusFeet() {
    // the radius bonus extends to
    // all creatures within its
    // circle, but saves only
    return 5;
}

int Rings_feather_falling_to_shooting_stars::rgpProtectionDaggerFlag() {
    // the prose entry carries NO
    // double-dagger; the R255 fix
    // made the R223 array leave
    // row 11 unflagged correctly
    return 0;
}

int Rings_feather_falling_to_shooting_stars::rgpRegenerationFormCount() {
    // there are 2 forms of this
    // ring
    return 2;
}

int Rings_feather_falling_to_shooting_stars::rgpRegenerationHpPerTurn() {
    // the standard form restores 1
    // hit point per turn
    return 1;
}

int Rings_feather_falling_to_shooting_stars::rgpRegenerationVampiricPercent() {
    // the vampiric form bestows
    // one-half of damage inflicted
    return 50;
}

int Rings_feather_falling_to_shooting_stars::rgpRegenerationStandardBandHi() {
    // 01-90 = ring of regeneration
    return 90;
}

int Rings_feather_falling_to_shooting_stars::rgpRegenerationVampiricBandLo() {
    // 91-00 = vampiric ring
    return 91;
}

int Rings_feather_falling_to_shooting_stars::rgpShootingStarsModeCount() {
    // 2 modes of operation, both
    // only in relative darkness
    return 2;
}

int Rings_feather_falling_to_shooting_stars::rgpShootingStarsDancingLightsPerHour() {
    // dancing lights once per hour
    return 1;
}

int Rings_feather_falling_to_shooting_stars::rgpShootingStarsLightPerNight() {
    // light twice per night
    return 2;
}

int Rings_feather_falling_to_shooting_stars::rgpShootingStarsLightRangeInches() {
    // the light function range
    return 12;
}

int Rings_feather_falling_to_shooting_stars::rgpShootingStarsBallLightningPerNight() {
    // ball lightning once per night
    return 1;
}

int Rings_feather_falling_to_shooting_stars::rgpBallLightningCountLo() {
    // releases 1 to 4 balls of
    // lightning
    return 1;
}

int Rings_feather_falling_to_shooting_stars::rgpBallLightningCountHi() {
    // the upper ball count
    return 4;
}

int Rings_feather_falling_to_shooting_stars::rgpBallLightningRangeInches() {
    // the spheres have a 12 range
    return 12;
}

int Rings_feather_falling_to_shooting_stars::rgpBallLightningDurationRounds() {
    // a 4 round duration
    return 4;
}

int Rings_feather_falling_to_shooting_stars::rgpBallLightningMoveInches() {
    // moved at 4 per round
    return 4;
}

int Rings_feather_falling_to_shooting_stars::rgpBallLightningDiameterFeet() {
    // each sphere is about 3 feet
    // in diameter
    return 3;
}

int Rings_feather_falling_to_shooting_stars::rgpBallLightningChargeTierCount() {
    // the charge value list has 4
    // tiers (the upload drops the
    // charge die bands)
    return 4;
}

int Rings_feather_falling_to_shooting_stars::rgpBallLightningChargeBalls(int i) {
    // the charge tiers: 4, 3, 2, 1
    // lightning balls; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        4, 3, 2, 1,
    };
    return t[i];
}

int Rings_feather_falling_to_shooting_stars::rgpShootingStarsPerWeek() {
    // 3 shooting stars per week
    return 3;
}

int Rings_feather_falling_to_shooting_stars::rgpShootingStarImpactDamage() {
    // they impact for 12 hit
    // points of damage
    return 12;
}

int Rings_feather_falling_to_shooting_stars::rgpShootingStarBurstDamage() {
    // the burst is 24 hit points
    return 24;
}

int Rings_feather_falling_to_shooting_stars::rgpShootingStarBurstDiameterInches() {
    // the burst is a 1 diameter
    // sphere
    return 1;
}

int Rings_feather_falling_to_shooting_stars::rgpShootingStarRangeInches() {
    // range is 7
    return 7;
}

int Rings_feather_falling_to_shooting_stars::rgpShootingStarSaveModNear() {
    // saving throws at -3 within
    // 2 of the ring wearer
    return -3;
}

int Rings_feather_falling_to_shooting_stars::rgpShootingStarNearLimitInches() {
    // the near zone limit
    return 2;
}

int Rings_feather_falling_to_shooting_stars::rgpShootingStarSaveModMid() {
    // saving throws at -1 within 2
    // to 4
    return -1;
}

int Rings_feather_falling_to_shooting_stars::rgpShootingStarMidLimitInches() {
    // the mid zone limit, normal
    // beyond
    return 4;
}

int Rings_feather_falling_to_shooting_stars::rgpShootingStarsFaerieFirePerDay() {
    // indoors: faerie fire twice
    // per day
    return 2;
}

int Rings_feather_falling_to_shooting_stars::rgpShootingStarsSparkShowerPerDay() {
    // indoors: spark shower once
    // per day
    return 1;
}

int Rings_feather_falling_to_shooting_stars::rgpSparkShowerLengthFeet() {
    // fans out from the ring for
    // 20 feet
    return 20;
}

int Rings_feather_falling_to_shooting_stars::rgpSparkShowerBreadthFeet() {
    // to a breadth of 10 feet
    return 10;
}

int Rings_feather_falling_to_shooting_stars::rgpSparkShowerDamageLo() {
    // 2-8 damage with no metallic
    // armor or weapon
    return 2;
}

int Rings_feather_falling_to_shooting_stars::rgpSparkShowerDamageHi() {
    // the upper no-metal damage
    return 8;
}

int Rings_feather_falling_to_shooting_stars::rgpSparkShowerMetalDamageLo() {
    // 4-16 damage with metal
    return 4;
}

int Rings_feather_falling_to_shooting_stars::rgpSparkShowerMetalDamageHi() {
    // the upper with-metal damage
    return 16;
}

int Rings_feather_falling_to_shooting_stars::rgpShootingStarsCastSegments() {
    // casting time is 5 segments
    return 5;
}
