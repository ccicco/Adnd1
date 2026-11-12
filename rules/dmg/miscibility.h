// ====================================================================
// Adnd1 - rules/dmg/miscibility.h
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

// R-refactor: namespace rules -> class Miscibility (instance methods)
class Miscibility {
public:


// The p.119 d100 bands (a roll of 100 reads 00).
    MiscibilityResult roll(int d100);


// The two trigger conditions: intermingled
// potions, or a potion consumed while another is
// still in effect.
    bool testNeeded( bool intermingled, bool otherStillInEffect);


// The explosion damage dice (the caller rolls):
// internal 6-60; an external mix 1-10 within a
// 5 foot radius, 4-24 in a 10 foot radius, no
// save for either.
    int explosionInternalMin();
    int explosionInternalMax();
    int explosionBlastNearMin();
    int explosionBlastNearMax();
    int explosionBlastNearRadius();
    int explosionBlastFarMin();
    int explosionBlastFarMax();
    int explosionBlastFarRadius();


// The mild poison band: 1 point each of strength
// and dexterity lost for 5-20 rounds, no saving
// throw possible; one potion cancelled, the other
// at half strength and duration (random which).
    int mildPoisonDurationMin();
    int mildPoisonDurationMax();


// The lethal poison band: the imbiber dead; an
// external mix a 10 foot poison gas cloud, save
// versus poison or die.
    int gasCloudRadius();


// The one-boosted band: 150 percent normal
// efficacy on the randomly determined potion.
    int boostPercent();


// The named campaign options the print suggests
// (DM decisions, not table data): delusion mixes
// with anything; treasure finding plus any other
// potion is lethal poison; oil of slipperiness plus
// oil of etherealness raises the lost-in-the-
// Ethereal chance to 50 percent for 5-30 days.
    bool optionDelusionMixes();
    bool optionTreasureFindingLethal();
    int optionEtherealLostPercent();
    int optionEtherealLostMinDays();
    int optionEtherealLostMaxDays();
};
