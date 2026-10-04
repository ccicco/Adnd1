// ====================================================================
// Adnd1 - rules/grenade.h
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

#include "dice.h"

namespace rules {

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

inline GrenadeKind grenadeClamp(GrenadeKind k) {
    if (k < 0) k = GREN_ACID;
    if (k >= GREN_COUNT) k = GREN_ACID;
    return k;
}

inline const char* grenadeName(GrenadeKind k) {
    static const char* const n[GREN_COUNT] = {
        "acid", "holy water", "unholy water", "oil", "poison"
    };
    return n[grenadeClamp(k)];
}

// container size in fluid ounces (the printed Size list:
// acid half pint, holy/unholy water quarter pint, oil a
// pint, poison quarter pint)
inline int grenadeSizeOz(GrenadeKind k) {
    static const int oz[GREN_COUNT] = { 8, 4, 4, 16, 4 };
    return oz[grenadeClamp(k)];
}

// ----------------------------------------------------------------------------
// The effect table: direct-hit and splash damage pairs (the
// print dice: acid 2-8 hit / 1 hp splash, water 2-7 / 2,
// alight oil 2-12 the first round / 1-3 splash, poison
// special). Oil: the second-round burn and the segment burn
// ride their own helpers.
// ----------------------------------------------------------------------------
inline void grenadeDirectHit(GrenadeKind k, int& lo, int& hi) {
    static const int t[GREN_COUNT][2] = {
        { 2, 8 }, { 2, 7 }, { 2, 7 }, { 2, 12 }, { 0, 0 },
    };
    lo = t[grenadeClamp(k)][0];
    hi = t[grenadeClamp(k)][1];
}

inline void grenadeSplashDamage(GrenadeKind k, int& lo, int& hi) {
    static const int t[GREN_COUNT][2] = {
        { 1, 1 }, { 2, 2 }, { 2, 2 }, { 1, 3 }, { 0, 0 },
    };
    lo = t[grenadeClamp(k)][0];
    hi = t[grenadeClamp(k)][1];
}

inline int grenadeSplashDiameterFeet(GrenadeKind k) {
    static const int t[GREN_COUNT] = { 1, 1, 1, 3, 1 };
    return t[grenadeClamp(k)];
}

inline int rollGrenadeDirectHit(rules::Dice& dice, GrenadeKind k) {
    int lo, hi;
    grenadeDirectHit(k, lo, hi);
    if (hi <= 0) return 0;   // poison special: caller-side
    return (int)dice.roll(1, (uint32_t)(hi - lo + 1), lo - 1);
}

inline int rollGrenadeSplashDamage(rules::Dice& dice, GrenadeKind k) {
    int lo, hi;
    grenadeSplashDamage(k, lo, hi);
    if (hi <= 0) return 0;
    return (int)dice.roll(1, (uint32_t)(hi - lo + 1), lo - 1);
}

// alight oil, direct hit: 2-12 the first round and 1-6 more
// the second, then burns out
inline void grenadeOilSecondRound(int& lo, int& hi) {
    lo = 1; hi = 6;
}

inline int rollGrenadeOilSecondRound(rules::Dice& dice) {
    return (int)dice.roll(1, 6, 0);
}

// alight-oil splash: burns 1-3 segments at 1 hp per segment
inline int grenadeOilBurnSegmentsMax() { return 3; }
inline int grenadeOilBurnDamagePerSegment() { return 1; }

// ----------------------------------------------------------------------------
// Splash hits (p.64): every creature within three feet of
// the impact and break point saves vs poison (the engine
// SAVE_DEATH_POISON category) or is splashed with the
// contents.
// ----------------------------------------------------------------------------
inline int grenadeSplashRadiusFeet() { return 3; }

// ----------------------------------------------------------------------------
// Range (p.64): all container missiles fly 3". Through 1"
// is short (no adjustment), beyond 1" medium (-2), beyond
// 2" long (-5).
// ----------------------------------------------------------------------------
inline int grenadeRangeMaxInches() { return 3; }

inline int grenadeRangeToHitAdj(int inches) {
    if (inches <= 1) return 0;
    if (inches <= 2) return -2;
    return -5;   // through the 3" maximum
}

// ----------------------------------------------------------------------------
// Break saves (the Item Saving Throw Matrix, DMG p.80): the
// container SAVES on d20 >= value. Crushing (the hurled-
// against-hard-surface case) for the BLOW, CRUSHING column;
// the poison-into-orifice case reads BLOW, NORMAL.
// ----------------------------------------------------------------------------
inline int grenadeBreakSaveCrushing(GrenadeKind k) {
    static const int t[GREN_COUNT] = { 18, 19, 19, 18, 19 };
    return t[grenadeClamp(k)];
}

inline int grenadeBreakSaveNormal(GrenadeKind k) {
    static const int t[GREN_COUNT] = { 12, 14, 14, 12, 14 };
    return t[grenadeClamp(k)];
}

// ----------------------------------------------------------------------------
// Misses (p.64): the d6 (optionally d4 at short range) feet
// off target, and the d8 direction cone - long read as
// high, short as low when hurled at a plane.
// ----------------------------------------------------------------------------
inline int grenadeMissDistance(rules::Dice& dice, bool shortRange) {
    if (shortRange) return (int)dice.d4();
    return (int)dice.d6();
}

inline int grenadeMissDirection(rules::Dice& dice) {
    return (int)dice.d8();
}

inline const char* grenadeMissDirectionName(int dir) {
    static const char* const n[8] = {
        "long right", "right", "short right", "short (before)",
        "short left", "left", "long left", "long (over)"
    };
    if (dir < 1) dir = 1;
    if (dir > 8) dir = 8;
    return n[dir - 1];
}

// ----------------------------------------------------------------------------
// Holy/unholy water (p.65): holy water burns all undead and
// lower-plane creatures (demons, devils, night hags, night
// mares, nycadaemons); unholy water burns paladins, lammasu,
// shedu, ki-rin and similar good (or upper-plane) creatures.
// Non-material undead (a ghost before it takes form, a
// gaseous vampire) are unaffected - the caller holds the
// material-form flag.
// ----------------------------------------------------------------------------
inline bool holyWaterAffects(bool isUndead, bool fromLowerPlane,
                              bool materialForm) {
    if (!materialForm) return false;
    return isUndead || fromLowerPlane;
}

inline bool unholyWaterAffects(bool isGoodOutsiderOrPaladin,
                               bool materialForm) {
    if (!materialForm) return false;
    return isGoodOutsiderOrPaladin;
}

// ----------------------------------------------------------------------------
// Crossing flaming oil (p.65): walking through or standing
// in it costs 1-6 hp per melee round; leaping over costs
// nothing (the caller checks the mode). Cloth garments save
// vs fire (normal) or catch - the item-save lane, later.
// ----------------------------------------------------------------------------
inline void flamingOilWalkDamage(int& lo, int& hi) {
    lo = 1; hi = 6;
}

inline int rollFlamingOilWalkDamage(rules::Dice& dice) {
    return (int)dice.roll(1, 6, 0);
}

// ----------------------------------------------------------------------------
// The empty blessed/cursed crystal vial: 2-5 gold pieces
// (the vial-cost print; the font lane is elsewhere).
// ----------------------------------------------------------------------------
inline int grenadeVialCostLo() { return 2; }
inline int grenadeVialCostHi() { return 5; }

// ----------------------------------------------------------------------------
// Boulders (p.64): 1 foot diameter for giants, 2 feet for
// siege engines (the siege machines keep their own section).
// A dropped boulder: each 14 lbs of weight inflicts 1 hp per
// foot of drop, the window 10-60 feet (above 60 reads as
// 60). The flat alternative: each 14 lbs inflicts 1-6 hp.
// JUDGMENT: a drop under 10 feet reads at the 10-foot
// window edge (the print caps only the far end).
// ----------------------------------------------------------------------------
inline int grenadeBoulderDiameterFeet(bool siege) {
    return siege ? 2 : 1;
}

inline int grenadeBoulderDropDamage(int weightLbs, int feetDropped) {
    int per14 = weightLbs / 14;
    if (per14 < 1) return 0;
    if (feetDropped < 10) feetDropped = 10;
    if (feetDropped > 60) feetDropped = 60;
    return per14 * feetDropped;
}

inline int rollGrenadeBoulderFlatDamage(rules::Dice& dice,
                                        int weightLbs) {
    int per14 = weightLbs / 14;
    if (per14 < 1) return 0;
    return per14 * (int)dice.roll(1, 6, 0);
}

} // namespace rules
