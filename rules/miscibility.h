// ====================================================================
// Adnd1 - rules/miscibility.h
// R165: potion miscibility (DMG p.119) - the
// interactions table for intermingled or stacked
// potions.
//
// Pure data, header-only (the grenade.h pattern: the
// caller rolls the d100 secretly and owns the
// damage, saves and duration bookkeeping).
//
// The p.119 print:
//   - Test miscibility whenever (1) two potions are
//     actually intermingled, or (2) a potion is
//     consumed while another consumed potion is
//     still in effect. The roll is made secretly.
//   - The d100 bands: 01 explosion, 02-03 lethal
//     poison, 04-08 mild poison (nausea, -1
//     strength and -1 dexterity for 5-20 rounds,
//     no save; one potion cancelled, the other at
//     half strength and duration, randomly
//     determined which), 09-15 both destroyed,
//     16-25 one cancelled the other normal,
//     26-35 both at half efficacy, 36-90 miscible
//     (contradictory effects simply cancel), 91-99
//     one potion at 150 percent efficacy,
//     00 discovery (one potion only functions,
//     its effect permanent on the imbiber, with
//     possible harmful side effects).
//   - The explosion: internal damage 6-60 hp; an
//     external mix blasts all within a 5 foot
//     radius for 1-10 hp and all in a 10 foot
//     radius for 4-24 hp, no save. (The print
//     renders the small radius as 5 double-prime
//     feet - read as 5 feet.)
//   - The lethal poison band: the imbiber is
//     dead; an external mix makes a 10 foot poison
//     gas cloud, all within saving versus poison
//     or dying.
//   - The print suggests campaign-fixed certain
//     results (delusion mixes with anything,
//     treasure finding plus any potion is lethal
//     poison, oil of slipperiness plus oil of
//     etherealness raising the lost-in-the-
//     Ethereal chance to 50 percent for 5-30
//     days) but marks them as the DMs own
//     decisions - named options below, not table
//     data.
// ====================================================================

#pragma once

namespace rules {

enum MiscibilityResult {
    MISC_EXPLOSION = 0,
    MISC_LETHAL_POISON,
    MISC_MILD_POISON,
    MISC_BOTH_DESTROYED,
    MISC_ONE_CANCELLED,
    MISC_BOTH_HALF,
    MISC_COMPATIBLE,
    MISC_ONE_BOOSTED,
    MISC_DISCOVERY
};

// The p.119 d100 bands (a roll of 100 reads 00).
inline MiscibilityResult miscibilityRoll(int d100) {
    if (d100 < 1) d100 = 1;
    if (d100 > 100) d100 = 100;
    if (d100 == 1) return MISC_EXPLOSION;
    if (d100 <= 3) return MISC_LETHAL_POISON;
    if (d100 <= 8) return MISC_MILD_POISON;
    if (d100 <= 15) return MISC_BOTH_DESTROYED;
    if (d100 <= 25) return MISC_ONE_CANCELLED;
    if (d100 <= 35) return MISC_BOTH_HALF;
    if (d100 <= 90) return MISC_COMPATIBLE;
    if (d100 <= 99) return MISC_ONE_BOOSTED;
    return MISC_DISCOVERY;
}

// The two trigger conditions: intermingled
// potions, or a potion consumed while another is
// still in effect.
inline bool miscibilityTestNeeded(
        bool intermingled, bool otherStillInEffect) {
    return intermingled || otherStillInEffect;
}

// The explosion damage dice (the caller rolls):
// internal 6-60; an external mix 1-10 within a
// 5 foot radius, 4-24 in a 10 foot radius, no
// save for either.
inline int miscibilityExplosionInternalMin() { return 6; }
inline int miscibilityExplosionInternalMax() { return 60; }
inline int miscibilityExplosionBlastNearMin() { return 1; }
inline int miscibilityExplosionBlastNearMax() { return 10; }
inline int miscibilityExplosionBlastNearRadius() { return 5; }
inline int miscibilityExplosionBlastFarMin() { return 4; }
inline int miscibilityExplosionBlastFarMax() { return 24; }
inline int miscibilityExplosionBlastFarRadius() { return 10; }

// The mild poison band: 1 point each of strength
// and dexterity lost for 5-20 rounds, no saving
// throw possible; one potion cancelled, the other
// at half strength and duration (random which).
inline int miscibilityMildPoisonDurationMin() { return 5; }
inline int miscibilityMildPoisonDurationMax() { return 20; }

// The lethal poison band: the imbiber dead; an
// external mix a 10 foot poison gas cloud, save
// versus poison or die.
inline int miscibilityGasCloudRadius() { return 10; }

// The one-boosted band: 150 percent normal
// efficacy on the randomly determined potion.
inline int miscibilityBoostPercent() { return 150; }

// The named campaign options the print suggests
// (DM decisions, not table data): delusion mixes
// with anything; treasure finding plus any other
// potion is lethal poison; oil of slipperiness plus
// oil of etherealness raises the lost-in-the-
// Ethereal chance to 50 percent for 5-30 days.
inline bool miscibilityOptionDelusionMixes() {
    return true;
}
inline bool miscibilityOptionTreasureFindingLethal() {
    return true;
}
inline int miscibilityOptionEtherealLostPercent() {
    return 50;
}
inline int miscibilityOptionEtherealLostMinDays() {
    return 5;
}
inline int miscibilityOptionEtherealLostMaxDays() {
    return 30;
}

} // namespace rules
