// ====================================================================
// Adnd1 - rules/dmg/rings_feather_falling_to_shooting_stars.h
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

// R-refactor: namespace rules -> class Rings_feather_falling_to_shooting_stars (instance methods)
class Rings_feather_falling_to_shooting_stars {
public:
    int rgpFeatherFallMinFeet();
    int rgpFireResistLargeFireDamagePerRound();
    int rgpFireResistLargeFirePerSegment();
    int rgpFireResistHotSaveBonus();
    int rgpFireResistHotDamagePerDieMod();
    int rgpFireResistHotDieFloor();
    int rgpFireResistVeryHotExposureMax();
    int rgpFireResistExceptionalExposureMin();
    int rgpHumanInfluenceCharisma();
    int rgpHumanInfluenceCharmLevels();
    int rgpHumanInfluenceUsesPerDay();
    int rgpHumanInfluenceCastSegments();
    int rgpHumanInfluenceDaggerFlag();
    int rgpInvisibilityInaudiblePercent();
    int rgpMammalControlMaxIntelligence();
    int rgpMammalControlHitDice();
    int rgpMammalControlTimeSegments();
    int rgpMammalControlDaggerFlag();
    int rgpMultipleWishesLo();
    int rgpMultipleWishesHi();
    int rgpMultipleWishesDice();
    int rgpMultipleWishesFaces();
    int rgpMultipleWishesDaggerFlag();
    int rgpProtectionRowCount();
    int rgpProtectionRowLo(int i);
    int rgpProtectionRowHi(int i);
    int rgpProtectionRowAc(int i);
    int rgpProtectionRowSave(int i);
    int rgpProtectionRowRadius(int i);
    int rgpProtectionRadiusFeet();
    int rgpProtectionDaggerFlag();
    int rgpRegenerationFormCount();
    int rgpRegenerationHpPerTurn();
    int rgpRegenerationVampiricPercent();
    int rgpRegenerationStandardBandHi();
    int rgpRegenerationVampiricBandLo();
    int rgpShootingStarsModeCount();
    int rgpShootingStarsDancingLightsPerHour();
    int rgpShootingStarsLightPerNight();
    int rgpShootingStarsLightRangeInches();
    int rgpShootingStarsBallLightningPerNight();
    int rgpBallLightningCountLo();
    int rgpBallLightningCountHi();
    int rgpBallLightningRangeInches();
    int rgpBallLightningDurationRounds();
    int rgpBallLightningMoveInches();
    int rgpBallLightningDiameterFeet();
    int rgpBallLightningChargeTierCount();
    int rgpBallLightningChargeBalls(int i);
    int rgpShootingStarsPerWeek();
    int rgpShootingStarImpactDamage();
    int rgpShootingStarBurstDamage();
    int rgpShootingStarBurstDiameterInches();
    int rgpShootingStarRangeInches();
    int rgpShootingStarSaveModNear();
    int rgpShootingStarNearLimitInches();
    int rgpShootingStarSaveModMid();
    int rgpShootingStarMidLimitInches();
    int rgpShootingStarsFaerieFirePerDay();
    int rgpShootingStarsSparkShowerPerDay();
    int rgpSparkShowerLengthFeet();
    int rgpSparkShowerBreadthFeet();
    int rgpSparkShowerDamageLo();
    int rgpSparkShowerDamageHi();
    int rgpSparkShowerMetalDamageLo();
    int rgpSparkShowerMetalDamageHi();
    int rgpShootingStarsCastSegments();
};
