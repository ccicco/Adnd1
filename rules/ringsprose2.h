// ====================================================================
// Adnd1 - rules/ringsprose2.h
// R254: the III.C rings explanation prose part 2
// pins (DMG pp.138-139) - Feather Falling
// through Shooting Stars, the second ten
// rings of the EXPLANATIONS AND
// DESCRIPTIONS section (upload lines
// ~10393-10457):
//   - Feather Falling: automatic feather
//     fall at 5 feet or more.
//   - Fire Resistance: immune to normal
//     fires; very large/hot fires 10 hit
//     points per round (1 per segment);
//     exceptionally hot fires save at +4,
//     damage dice at -2 per die but each
//     die never less than 1; the rule of
//     thumb: very hot up to 24 hit points
//     initial exposure, exceptional heat
//     25 or more.
//   - Free Action: web, hold, slow have no
//     effect; normal underwater speed and
//     full damage; no water breathing.
//   - Human Influence: charisma 18;
//     suggestion and charm up to 21
//     levels; once per day; 3 segments;
//     double-dagger flagged.
//   - Invisibility: at will, instantly;
//     10% of these rings also have
//     inaudibility.
//   - Mammal Control: intelligence 4 or
//     less; up to 30 hit dice; control
//     time 3 segments; double-dagger
//     flagged.
//   - Multiple Wishes: 2-8 (2d4) wish
//     spells; double-dagger flagged.
//   - Protection: the 7-row value table
//     01-70 +1 through 98-00 +6 on AC
//     +1 saves; rows 83 and 91 carry the
//     5 foot radius (saves only); NO
//     double-dagger.
//   - Regeneration: 2 forms; 1 hit point
//     per turn; the vampiric form bestows
//     one-half of damage inflicted; 01-90
//     standard, 91-00 vampiric.
//   - Shooting Stars: 2 modes in relative
//     darkness; dancing lights once per
//     hour; light twice per night at 12
//     range; ball lightning once per night
//     (1 to 4 balls, 12 range, 4 round
//     duration, 4 per round move, 3 feet
//     diameter, the 4 charge tiers 4/3/2/1
//     balls); 3 stars per week, 12 impact
//     plus a 1 diameter burst for 24;
//     range 7; saves at -3 within 2 of
//     the wearer, -1 within 2 to 4;
//     indoors: faerie fire twice per day;
//     spark shower once per day (20 feet
//     to a 10 feet breadth, 2-8 damage
//     with no metal, 4-16 with); casting
//     time 5 segments.
// The ten rings are the engine III.C table
// rows 16-63 (dm/treasure.cpp kRings, the
// R223 rings.h band pins) - cross-checked in
// the audit, with the Human Influence and
// Multiple Wishes double-daggers cross-pinned
// against the R223 charge-limited rows. The
// Mammal Control / Protection charge-limited
// divergence (the R223 array flags the wrong
// row) was resolved by the R255 fix. Pure
// data + helpers, header-only (the grenade.h
// pattern).
// ====================================================================

#pragma once

namespace rules {

inline int rgpFeatherFallMinFeet() {
    // automatic activation if the
    // individual falls 5 feet or more
    return 5;
}

inline int rgpFireResistLargeFireDamagePerRound() {
    // very large and hot fires cause
    // this much per round
    return 10;
}

inline int rgpFireResistLargeFirePerSegment() {
    // the same damage expressed per
    // segment
    return 1;
}

inline int rgpFireResistHotSaveBonus() {
    // exceptionally hot fires are
    // saved against at +4
    return 4;
}

inline int rgpFireResistHotDamagePerDieMod() {
    // all damage dice calculated at
    // -2 per die
    return -2;
}

inline int rgpFireResistHotDieFloor() {
    // each die is never less than 1
    return 1;
}

inline int rgpFireResistVeryHotExposureMax() {
    // rule of thumb: very hot fires
    // are up to 24 hit points of
    // maximum initial exposure
    return 24;
}

inline int rgpFireResistExceptionalExposureMin() {
    // fires of exceptional heat are
    // 25 or more hit points
    return 25;
}

inline int rgpHumanInfluenceCharisma() {
    // raises the wearer charisma to
    // 18 for encounter reactions
    return 18;
}

inline int rgpHumanInfluenceCharmLevels() {
    // charm up to 21 levels/hit
    // dice of humans/humanoids
    return 21;
}

inline int rgpHumanInfluenceUsesPerDay() {
    // suggestion and charm are each
    // applicable but once per day
    return 1;
}

inline int rgpHumanInfluenceCastSegments() {
    // suggestion or charm requires
    // 3 segments of casting time
    return 3;
}

inline int rgpHumanInfluenceDaggerFlag() {
    // the prose entry carries the
    // double-dagger; cross-pins the
    // R223 charge-limited row 7
    return 1;
}

inline int rgpInvisibilityInaudiblePercent() {
    // 10% of these rings also have
    // inaudibility
    return 10;
}

inline int rgpMammalControlMaxIntelligence() {
    // controls mammals with
    // intelligence of 4 or less
    return 4;
}

inline int rgpMammalControlHitDice() {
    // up to 30 hit dice of mammals
    return 30;
}

inline int rgpMammalControlTimeSegments() {
    // control time is 3 segments
    return 3;
}

inline int rgpMammalControlDaggerFlag() {
    // the prose entry carries the
    // double-dagger; the R255 fix
    // made the R223 array flag
    // row 9 correctly
    return 1;
}

inline int rgpMultipleWishesLo() {
    // contains from 2 wish spells
    return 2;
}

inline int rgpMultipleWishesHi() {
    // up to 8 wish spells
    return 8;
}

inline int rgpMultipleWishesDice() {
    // 2 dice
    return 2;
}

inline int rgpMultipleWishesFaces() {
    // of 4 faces each
    return 4;
}

inline int rgpMultipleWishesDaggerFlag() {
    // the prose entry carries the
    // double-dagger; cross-pins the
    // R223 charge-limited row 10
    return 1;
}

inline int rgpProtectionRowCount() {
    // the value table has 7 rows
    return 7;
}

inline int rgpProtectionRowLo(int i) {
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

inline int rgpProtectionRowHi(int i) {
    // the row upper edges; i clamps
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    static const int t[7] = {
        70, 82, 83, 90, 91, 97, 100,
    };
    return t[i];
}

inline int rgpProtectionRowAc(int i) {
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

inline int rgpProtectionRowSave(int i) {
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

inline int rgpProtectionRowRadius(int i) {
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

inline int rgpProtectionRadiusFeet() {
    // the radius bonus extends to
    // all creatures within its
    // circle, but saves only
    return 5;
}

inline int rgpProtectionDaggerFlag() {
    // the prose entry carries NO
    // double-dagger; the R255 fix
    // made the R223 array leave
    // row 11 unflagged correctly
    return 0;
}

inline int rgpRegenerationFormCount() {
    // there are 2 forms of this
    // ring
    return 2;
}

inline int rgpRegenerationHpPerTurn() {
    // the standard form restores 1
    // hit point per turn
    return 1;
}

inline int rgpRegenerationVampiricPercent() {
    // the vampiric form bestows
    // one-half of damage inflicted
    return 50;
}

inline int rgpRegenerationStandardBandHi() {
    // 01-90 = ring of regeneration
    return 90;
}

inline int rgpRegenerationVampiricBandLo() {
    // 91-00 = vampiric ring
    return 91;
}

inline int rgpShootingStarsModeCount() {
    // 2 modes of operation, both
    // only in relative darkness
    return 2;
}

inline int rgpShootingStarsDancingLightsPerHour() {
    // dancing lights once per hour
    return 1;
}

inline int rgpShootingStarsLightPerNight() {
    // light twice per night
    return 2;
}

inline int rgpShootingStarsLightRangeInches() {
    // the light function range
    return 12;
}

inline int rgpShootingStarsBallLightningPerNight() {
    // ball lightning once per night
    return 1;
}

inline int rgpBallLightningCountLo() {
    // releases 1 to 4 balls of
    // lightning
    return 1;
}

inline int rgpBallLightningCountHi() {
    // the upper ball count
    return 4;
}

inline int rgpBallLightningRangeInches() {
    // the spheres have a 12 range
    return 12;
}

inline int rgpBallLightningDurationRounds() {
    // a 4 round duration
    return 4;
}

inline int rgpBallLightningMoveInches() {
    // moved at 4 per round
    return 4;
}

inline int rgpBallLightningDiameterFeet() {
    // each sphere is about 3 feet
    // in diameter
    return 3;
}

inline int rgpBallLightningChargeTierCount() {
    // the charge value list has 4
    // tiers (the upload drops the
    // charge die bands)
    return 4;
}

inline int rgpBallLightningChargeBalls(int i) {
    // the charge tiers: 4, 3, 2, 1
    // lightning balls; i clamps
    if (i < 0) i = 0;
    if (i > 3) i = 3;
    static const int t[4] = {
        4, 3, 2, 1,
    };
    return t[i];
}

inline int rgpShootingStarsPerWeek() {
    // 3 shooting stars per week
    return 3;
}

inline int rgpShootingStarImpactDamage() {
    // they impact for 12 hit
    // points of damage
    return 12;
}

inline int rgpShootingStarBurstDamage() {
    // the burst is 24 hit points
    return 24;
}

inline int rgpShootingStarBurstDiameterInches() {
    // the burst is a 1 diameter
    // sphere
    return 1;
}

inline int rgpShootingStarRangeInches() {
    // range is 7
    return 7;
}

inline int rgpShootingStarSaveModNear() {
    // saving throws at -3 within
    // 2 of the ring wearer
    return -3;
}

inline int rgpShootingStarNearLimitInches() {
    // the near zone limit
    return 2;
}

inline int rgpShootingStarSaveModMid() {
    // saving throws at -1 within 2
    // to 4
    return -1;
}

inline int rgpShootingStarMidLimitInches() {
    // the mid zone limit, normal
    // beyond
    return 4;
}

inline int rgpShootingStarsFaerieFirePerDay() {
    // indoors: faerie fire twice
    // per day
    return 2;
}

inline int rgpShootingStarsSparkShowerPerDay() {
    // indoors: spark shower once
    // per day
    return 1;
}

inline int rgpSparkShowerLengthFeet() {
    // fans out from the ring for
    // 20 feet
    return 20;
}

inline int rgpSparkShowerBreadthFeet() {
    // to a breadth of 10 feet
    return 10;
}

inline int rgpSparkShowerDamageLo() {
    // 2-8 damage with no metallic
    // armor or weapon
    return 2;
}

inline int rgpSparkShowerDamageHi() {
    // the upper no-metal damage
    return 8;
}

inline int rgpSparkShowerMetalDamageLo() {
    // 4-16 damage with metal
    return 4;
}

inline int rgpSparkShowerMetalDamageHi() {
    // the upper with-metal damage
    return 16;
}

inline int rgpShootingStarsCastSegments() {
    // casting time is 5 segments
    return 5;
}

}  // namespace rules

