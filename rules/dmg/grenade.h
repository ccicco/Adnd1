// ====================================================================
// Adnd1 - rules/dmg/grenade.h
// R157: grenade-like missiles - boulders and containers of
// acid, holy/unholy water, oil and poison (DMG pp.64-65).
//
// Pure data + rollers, header-only (the appendixp.h pattern:
// the caller decides when to throw; the to-hit roll itself
// is the missile-fire lane). Conventions, named in place:
//   - Damage occurs only when the container BREAKS, and oil
//     must be alight to damage at all (a rag wick lit before
//     the throw, or a torch brought to the puddle after) -
//     the caller carries the alight and weakened flags.
//   - The break roll is the Item Saving Throw Matrix (DMG
//     p.80) BLOW, CRUSHING column: the container SAVES on
//     d20 >= value. The print names the (ceramic) flask of
//     oil and the (crystal or glass) vial of holy water;
//     ceramic flasks (acid, oil) read the ceramic row (18
//     crushing / 12 normal), crystal vials (holy/unholy
//     water, poison) the crystal-or-vial row (19 / 14).
//     JUDGMENT: the acid flask rides the ceramic flask row
//     and the poison vial the crystal vial row. A specially
//     scored or fragile container breaks automatically -
//     caller-side.
//   - Poison damage is print-special (contact poison vs a
//     container hurled into the ingestive or respiratory
//     orifice; an unstoppered container need not break):
//     the pairs read 0-0 and the caller handles the poison
//     lane.
// ====================================================================

#pragma once

#include "../engine/dice.h"
using rules::Dice;  // R-refactor: engine type, was namespace-implicit




// ----------------------------------------------------------------------------
// Kinds (the printed Size list order)
// ----------------------------------------------------------------------------
enum GrenadeKind {
    GREN_ACID = 0,
    GREN_HOLY_WATER,
    GREN_UNHOLY_WATER,
    GREN_OIL,
    GREN_POISON,
    GREN_COUNT
};

// R-refactor: namespace rules -> class Grenade (instance methods)
class Grenade {
public:
    GrenadeKind clamp(GrenadeKind k);
    const char* name(GrenadeKind k);


// container size in fluid ounces (the printed Size list:
// acid half pint, holy/unholy water quarter pint, oil a
// pint, poison quarter pint)
    int sizeOz(GrenadeKind k);


// ----------------------------------------------------------------------------
// The effect table: direct-hit and splash damage pairs (the
// print dice: acid 2-8 hit / 1 hp splash, water 2-7 / 2,
// alight oil 2-12 the first round / 1-3 splash, poison
// special). Oil: the second-round burn and the segment burn
// ride their own helpers.
// ----------------------------------------------------------------------------
    void directHit(GrenadeKind k, int& lo, int& hi);
    void splashDamage(GrenadeKind k, int& lo, int& hi);
    int splashDiameterFeet(GrenadeKind k);
    int rollGrenadeDirectHit(rules::Dice& dice, GrenadeKind k);
    int rollGrenadeSplashDamage(rules::Dice& dice, GrenadeKind k);


// alight oil, direct hit: 2-12 the first round and 1-6 more
// the second, then burns out
    void oilSecondRound(int& lo, int& hi);
    int rollGrenadeOilSecondRound(rules::Dice& dice);


// alight-oil splash: burns 1-3 segments at 1 hp per segment
    int oilBurnSegmentsMax();
    int oilBurnDamagePerSegment();


// ----------------------------------------------------------------------------
// Splash hits (p.64): every creature within three feet of
// the impact and break point saves vs poison (the engine
// SAVE_DEATH_POISON category) or is splashed with the
// contents.
// ----------------------------------------------------------------------------
    int splashRadiusFeet();


// ----------------------------------------------------------------------------
// Range (p.64): all container missiles fly 3". Through 1"
// is short (no adjustment), beyond 1" medium (-2), beyond
// 2" long (-5).
// ----------------------------------------------------------------------------
    int rangeMaxInches();
    int rangeToHitAdj(int inches);


// ----------------------------------------------------------------------------
// Break saves (the Item Saving Throw Matrix, DMG p.80): the
// container SAVES on d20 >= value. Crushing (the hurled-
// against-hard-surface case) for the BLOW, CRUSHING column;
// the poison-into-orifice case reads BLOW, NORMAL.
// ----------------------------------------------------------------------------
    int breakSaveCrushing(GrenadeKind k);
    int breakSaveNormal(GrenadeKind k);


// ----------------------------------------------------------------------------
// Misses (p.64): the d6 (optionally d4 at short range) feet
// off target, and the d8 direction cone - long read as
// high, short as low when hurled at a plane.
// ----------------------------------------------------------------------------
    int missDistance(rules::Dice& dice, bool shortRange);
    int missDirection(rules::Dice& dice);
    const char* missDirectionName(int dir);


// ----------------------------------------------------------------------------
// Holy/unholy water (p.65): holy water burns all undead and
// lower-plane creatures (demons, devils, night hags, night
// mares, nycadaemons); unholy water burns paladins, lammasu,
// shedu, ki-rin and similar good (or upper-plane) creatures.
// Non-material undead (a ghost before it takes form, a
// gaseous vampire) are unaffected - the caller holds the
// material-form flag.
// ----------------------------------------------------------------------------
    bool holyWaterAffects(bool isUndead, bool fromLowerPlane, bool materialForm);
    bool unholyWaterAffects(bool isGoodOutsiderOrPaladin, bool materialForm);


// ----------------------------------------------------------------------------
// Crossing flaming oil (p.65): walking through or standing
// in it costs 1-6 hp per melee round; leaping over costs
// nothing (the caller checks the mode). Cloth garments save
// vs fire (normal) or catch - the item-save lane, later.
// ----------------------------------------------------------------------------
    void flamingOilWalkDamage(int& lo, int& hi);
    int rollFlamingOilWalkDamage(rules::Dice& dice);


// ----------------------------------------------------------------------------
// The empty blessed/cursed crystal vial: 2-5 gold pieces
// (the vial-cost print; the font lane is elsewhere).
// ----------------------------------------------------------------------------
    int vialCostLo();
    int vialCostHi();


// ----------------------------------------------------------------------------
// Boulders (p.64): 1 foot diameter for giants, 2 feet for
// siege engines (the siege machines keep their own section).
// A dropped boulder: each 14 lbs of weight inflicts 1 hp per
// foot of drop, the window 10-60 feet (above 60 reads as
// 60). The flat alternative: each 14 lbs inflicts 1-6 hp.
// JUDGMENT: a drop under 10 feet reads at the 10-foot
// window edge (the print caps only the far end).
// ----------------------------------------------------------------------------
    int boulderDiameterFeet(bool siege);
    int boulderDropDamage(int weightLbs, int feetDropped);
    int rollGrenadeBoulderFlatDamage(rules::Dice& dice, int weightLbs);
};
