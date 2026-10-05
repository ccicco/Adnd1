// ============================================================================
// Adnd1 - items/items.h
// Weapons, armor, gear, encumbrance.
//
// Source: Players Handbook (2012 Premium reprint), pp. 35-39
// (equipment tables: weapons damage by target size, armor AC,
// gear costs/weights, encumbrance movement rates). Values follow
// the PHB tables as recorded in project notes; verification debt
// applies - printed table wins when the PHB PDF is re-uploaded.
// ============================================================================

#pragma once

#include "../rules/combat.h"   // WeaponClass, AcType, weaponVsAc...

#include "../rules/classes.h"   // ArmorWeight, ARMOR_NONE/LEATHER/CHAIN/PLATE
#include "../rules/character.h" // ExceptionalStrength
#include <cstdint>

namespace items {

// ----------------------------------------------------------------------------
// Weapons (PHB p.36-38)
//   damage vs small/medium and vs large targets, in dice notation
//   (count, sides, bonus) - e.g. long sword 1d8 vs S/M, 1d12 vs L.
//   Missile weapons carry range (in tens of feet) and rate of fire.
// ----------------------------------------------------------------------------
enum WeaponId : int {
    WPN_DAGGER = 0,
    WPN_HAND_AXE,
    WPN_SHORT_SWORD,
    WPN_LONG_SWORD,
    WPN_BATTLE_AXE,
    WPN_MACE,
    WPN_FLAIL,
    WPN_MORNING_STAR,
    WPN_SPEAR,
    WPN_QUARTERSTAFF,
    WPN_CLUB,
    WPN_SHORT_BOW,
    WPN_LONG_BOW,
    WPN_CROSSBOW_LIGHT,
    WPN_SLING,
    WPN_COUNT
};

struct WeaponDef {
    const char* name;
    rules::WeaponClass wclass;   // bludgeon/pierce/slash
    int  smCount, smSides, smBonus;   // damage vs small/medium
    int  lCount,  lSides,  lBonus;    // damage vs large
    bool missile;
    int  rangeTens;              // short range, tens of feet (0 melee)
    int  rateOfFire;             // shots per round (0 melee)
    int  weightGp;               // weight in gold-piece units (1 gp = 1/10 lb)
    int  costGp;                 // list price
    // R145: the PHB p.38 'to hit' adjustment row, columns
    // AC 0..10 (positive = easier to hit that armor)
    int  acAdj[11];
};

const WeaponDef& weapon(WeaponId id);

// ----------------------------------------------------------------------------
// Armor (PHB p.36) + shields
//   AC values descending (unarmored 10, the printed ARMOR
//   CLASS TABLE R191; armor sets the base).
//   ArmorWeight links to rules/classes armorAllowed.
// ----------------------------------------------------------------------------
enum ArmorId : int {
    ARMOR_NONE_EQUIPPED = 0,
    ARMOR_PADDED,
    ARMOR_LEATHER,
    ARMOR_STUDDED_LEATHER,
    ARMOR_RING_MAIL,
    ARMOR_SCALE_MAIL,
    ARMOR_CHAIN_MAIL,
    ARMOR_SPLINTED,
    ARMOR_BANDED,
    ARMOR_PLATE,
    ARMOR_COUNT
};

struct ArmorDef {
    const char* name;
    int baseAc;                  // AC when worn before DEX/shield
    rules::ArmorWeight weight;   // for class restriction checks
    int weightGp;
    int costGp;
};

const ArmorDef& armor(ArmorId id);

// ----------------------------------------------------------------------------
// Magic bonus plumbing: a weapon/armor instance can carry a plus.
// Weapon plus adds to hit AND damage (PHB magic weapons) and to the
// gating check (rules/combat weaponSufficient). Armor plus improves
// AC (lowers the number).
// ----------------------------------------------------------------------------
struct WeaponInstance {
    WeaponId id  = WPN_DAGGER;
    int      plus = 0;           // enchantment level
};

struct ArmorInstance {
    ArmorId id   = ARMOR_NONE_EQUIPPED;
    int     plus = 0;
};

// R145: the per-weapon p.38 'to hit' adjustment vs. the
// defender's APPARENT ARMOR AC. The book's table runs
// AC 0-10; better-than-0 reads column 0, worse-than-10
// column 10. R203 closes the named approximation: the
// column keys to the armor the defender wears - armor
// base + shield, magic and DEX do not shift it - per the
// book's own p.38 note: the adjustments are for weapons
// versus specific types of armor, not necessarily against
// actual armor class.
int weaponAcAdjustment(WeaponId id, int defenderArmorAc);

// R203: the apparent armor AC - the armor's own printed AC,
// armor base + shield one better. The enchantment plus and
// the DEX defensive adjustment do NOT shift it - this is
// the p.38 column key, distinct from effectiveAc.
int apparentArmorAc(const ArmorInstance& a, bool shield);

// Effective to-hit adjustment for an attack: STR adj + weapon plus +
// the per-weapon p.38 adjustment vs. the defender's apparent
// armor AC.
int attackAdjustment(const WeaponInstance& w, const rules::ExceptionalStrength& ex,
                     uint8_t str, int defenderArmorAc);

// Effective AC for a defender: armor base, + DEX defensive adj
// (negative = better), + shield (1 better), + armor plus.
int effectiveAc(const ArmorInstance& a, bool shield, int shieldPlus,
                uint8_t dex);

// ----------------------------------------------------------------------------
// Encumbrance (PHB p.38 movement rates). Weight carried in gp units
// (1 gp = 1/10 lb); bands by strength. Movement in feet per turn:
//   unencumbered: 120'
//   light:          90'
//   moderate:       60'
//   heavy:          30'
// Band thresholds scale with STR (base thresholds at STR 10:
//   light 350 gp-wt, moderate 700, heavy 1050; each STR point above
//   10 adds 10%; below 10 subtracts 10%, floor 50%).
// ----------------------------------------------------------------------------
enum EncumbranceBand : int {
    ENC_UNENCUMBERED = 0,
    ENC_LIGHT,
    ENC_MODERATE,
    ENC_HEAVY,
    ENC_BAND_COUNT
};

EncumbranceBand encumbranceBand(int weightGpCarried, uint8_t str);
int movementForBand(EncumbranceBand band);   // feet per turn

// Total weight of equipped weapon+armor+shield (gp units).
int equippedWeight(const WeaponInstance& w, const ArmorInstance& a,
                   bool shield);

// R87: the plain-shield weight (gp units) - was a file-static
// in items.cpp; pack weights need it too.
int shieldWeightGp();

} // namespace items