// ============================================================================
// Adnd1 - items/items.cpp
// PHB p.35-39 equipment tables.
// ============================================================================

#include "items.h"
#include "../rules/character.h"   // dexDefensiveAdj, strHitAdj...

namespace items {

// ----------------------------------------------------------------------------
// Weapons (PHB p.37 table; damage vs S/M and L, missile data)
// Weight in gp units (1 gp = 1/10 lb). Costs from the same table.
// NOTE: values follow the standard 1e table from project notes
// (verification debt - printed table wins).
// R145: the last member is the PHB p.38 'to hit' adjustment row
// (columns AC 0..10, positive = easier), transcribed from the
// 1eonline.info compilation (both p.38 charts - melee weapons
// from the first, bows/crossbow/sling from the hurled/missile
// chart; the sling row is the bullet's, the DMG p.71 example's
// own weapon). Bow rows show the source's cell gaps (-4 to -1);
// the composite bows on the same page show the same quirk, so
// the rows are pinned as transcribed - the book-verify debt
// stands.
// ----------------------------------------------------------------------------

static const WeaponDef kWeapons[WPN_COUNT] = {
    // name             wclass              S/M dmg   L dmg    missile  range  rof  wt    cost  p.38 row
    { "Dagger",         rules::WCLASS_PIERCING,   1,4,0,   1,3,0,   false,   0,  0,   20,     2,
      // R145: p.38 row, AC 0..10
      {-4,-4,-3,-3,-2,-2, 0, 0,+1,+1,+3 } },
    { "Hand Axe",       rules::WCLASS_SLASHING,   1,6,0,   1,4,0,   false,   0,  0,   50,     4,
      // R145: p.38 row, AC 0..10
      {-5,-4,-3,-2,-1,-1, 0, 0,+1,+1,+1 } },
    { "Short Sword",    rules::WCLASS_PIERCING,   1,6,0,   1,8,0,   false,   0,  0,   50,     8,
      // R145: p.38 row, AC 0..10
      {-5,-4,-3,-2,-1, 0, 0, 0,+1, 0,+2 } },
    { "Long Sword",     rules::WCLASS_SLASHING,   1,8,0,  1,12,0,   false,   0,  0,   75,    15,
      // R145: p.38 row, AC 0..10
      {-4,-3,-2,-1, 0, 0, 0, 0, 0,+1,+2 } },
    { "Battle Axe",     rules::WCLASS_SLASHING,   1,8,0,  1,8,0,    false,   0,  0,   70,     7,
      // R145: p.38 row, AC 0..10
      {-5,-4,-3,-2,-1,-1, 0, 0,+1,+1,+2 } },
    { "Mace",           rules::WCLASS_BLUDGEONING,1,6,0,  1,6,0,    false,   0,  0,   80,     8,
      // R145: p.38 row, AC 0..10
      {+2,+2,+1,+1,+1, 0, 0, 0, 0,+1,-1 } },
    { "Flail",          rules::WCLASS_BLUDGEONING,1,6,1,  2,7,1,    false,   0,  0,   80,    15,
      // R145: p.38 row, AC 0..10
      {+3,+3,+2,+1,+1,+2,+1,+1,+1,+1,-1 } },
    { "Morning Star",   rules::WCLASS_BLUDGEONING,2,4,0,  1,6,1,    false,   0,  0,  100,    10,
      // R145: p.38 row, AC 0..10
      { 0, 0, 0,+1,+1,+1,+1,+1,+1,+2,+2 } },
    { "Spear",          rules::WCLASS_PIERCING,   1,6,0,  1,8,0,    false,   0,  0,   60,     3,
      // R145: p.38 row, AC 0..10
      {-2,-2,-2,-1,-1,-1, 0, 0, 0, 0, 0 } },
    { "Quarterstaff",   rules::WCLASS_BLUDGEONING,1,6,0,  1,6,0,    false,   0,  0,   40,     0,
      // R145: p.38 row, AC 0..10
      {-9,-8,-7,-5,-3,-1, 0, 0,+1,+1,+1 } },
    { "Club",           rules::WCLASS_BLUDGEONING,1,6,0,  1,3,1,    false,   0,  0,   30,     0,
      // R145: p.38 row, AC 0..10
      {-7,-6,-5,-4,-3,-2,-1,-1, 0, 0,+1 } },
    { "Short Bow",      rules::WCLASS_PIERCING,   1,6,0,  1,6,0,    true,    5,  2,   20,    25,
      // R145: p.38 row, AC 0..10
      {-7,-6,-5,-4,-1, 0, 0,+1,+2,+2,+2 } },
    { "Long Bow",       rules::WCLASS_PIERCING,   1,6,0,  1,6,0,    true,    7,  2,   30,    40,
      // R145: p.38 row, AC 0..10
      {-2,-1,-1, 0, 0,+1,+2,+3,+3,+3,+3 } },
    { "Light Crossbow", rules::WCLASS_PIERCING,   1,4,0,  1,4,0,    true,    6,  1,   70,    10,
      // R145: p.38 row, AC 0..10
      {-3,-2,-2,-1, 0, 0,+1,+2,+3,+3,+3 } },
    { "Sling",          rules::WCLASS_BLUDGEONING,1,4,0,  1,4,1,    true,    4,  1,   10,     2,
      // R145: p.38 row, AC 0..10
      {-3,-3,-2,-2,-1, 0, 0, 0,+2,+1,+3 } },
};

const WeaponDef& weapon(WeaponId id) {
    return kWeapons[id < 0 || id >= WPN_COUNT ? 0 : id];
}

// ----------------------------------------------------------------------------
// Armor (PHB p.36 table: AC, weight, cost) + shield data
// ----------------------------------------------------------------------------

static const ArmorDef kArmors[ARMOR_COUNT] = {
    // name             baseAc  weight                    wtGp  costGp
    // R191: the printed ARMOR CLASS TABLE says None 10,
    // shield only 9 - the engine read 9; the repin
    // also matches the engine p.38 worked examples
    // (Balto unarmored, AC 10).
    { "None",            10,    rules::ARMOR_NONE,           0,     0 },
    { "Padded",           8,    rules::ARMOR_LEATHER,      100,     4 },
    { "Leather",          8,    rules::ARMOR_LEATHER,      150,     5 },
    { "Studded Leather",  7,    rules::ARMOR_LEATHER,      200,    15 },
    { "Ring Mail",        7,    rules::ARMOR_CHAIN,        250,    30 },
    { "Scale Mail",       6,    rules::ARMOR_CHAIN,        400,    50 },
    { "Chain Mail",       5,    rules::ARMOR_CHAIN,        300,    75 },
    { "Splinted",         4,    rules::ARMOR_PLATE,        400,    80 },
    { "Banded",           4,    rules::ARMOR_PLATE,        350,    90 },
    { "Plate Mail",       3,    rules::ARMOR_PLATE,        450,   400 },
};

const ArmorDef& armor(ArmorId id) {
    return kArmors[id < 0 || id >= ARMOR_COUNT ? 0 : id];
}

static const int SHIELD_WEIGHT_GP = 100;

int shieldWeightGp() { return SHIELD_WEIGHT_GP; }
static const int SHIELD_COST_GP   = 10;

// ----------------------------------------------------------------------------
// Combat plumbing
// ----------------------------------------------------------------------------

// R145: the per-weapon p.38 row vs. effective AC. The
// book's table runs AC 0-10; the clamps read the end
// columns past the table's edges. NOTE: the book applies
// these rows to humans, demihumans, and humanoids only -
// the engine applies them to every defender (monsters
// included), a named approximation (gap report).
int weaponAcAdjustment(WeaponId id, int defenderAc) {
    if (defenderAc < 0) defenderAc = 0;
    if (defenderAc > 10) defenderAc = 10;
    return weapon(id).acAdj[defenderAc];
}

int attackAdjustment(const WeaponInstance& w, const rules::ExceptionalStrength& ex,
                     uint8_t str, int defenderAc) {
    int adj = rules::strHitAdj(str, ex);
    adj += w.plus;
    adj += weaponAcAdjustment(w.id, defenderAc);
    return adj;
}

int effectiveAc(const ArmorInstance& a, bool shield, int shieldPlus,
                uint8_t dex) {
    int ac = armor(a.id).baseAc;
    ac += rules::dexDefensiveAdj(dex);   // negative = better
    if (shield) ac -= 1 + shieldPlus;
    ac -= a.plus;
    if (ac < -10) ac = -10;
    if (ac > 10)  ac = 10;
    return ac;
}

// ----------------------------------------------------------------------------
// Encumbrance (PHB p.38)
// ----------------------------------------------------------------------------

EncumbranceBand encumbranceBand(int weightGpCarried, uint8_t str) {
    // base thresholds at STR 10: 350 / 700 / 1050 gp weight
    int scalePct = 100;
    if (str > 10)  scalePct = 100 + 10 * (str - 10);
    if (str < 10)  scalePct = 100 - 10 * (10 - str);
    if (scalePct < 50) scalePct = 50;

    int light   = (350 * scalePct) / 100;
    int moder   = (700 * scalePct) / 100;
    int heavy   = (1050 * scalePct) / 100;

    if (weightGpCarried <= light)  return ENC_UNENCUMBERED;
    if (weightGpCarried <= moder)  return ENC_LIGHT;
    if (weightGpCarried <= heavy)  return ENC_MODERATE;
    return ENC_HEAVY;
}

int movementForBand(EncumbranceBand band) {
    switch (band) {
        case ENC_UNENCUMBERED: return 120;
        case ENC_LIGHT:        return 90;
        case ENC_MODERATE:     return 60;
        default:               return 30;   // heavy
    }
}

int equippedWeight(const WeaponInstance& w, const ArmorInstance& a,
                   bool shield) {
    int wt = weapon(w.id).weightGp + armor(a.id).weightGp;
    if (shield) wt += SHIELD_WEIGHT_GP;
    return wt;
}

} // namespace items