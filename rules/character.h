// ============================================================================
// Adnd1 — rules/character.h
// Ability scores and ability-score modifiers.
//
// Source: Players Handbook (2012 Premium reprint), pp. 9-13.
// Values cross-checked against the 1979 TSR scan (identical).
// All tables are constexpr arrays; page cites in comments.
// ============================================================================

#pragma once

#include "dice.h"

#include <cstdint>
#include <string>

namespace rules {

// ----------------------------------------------------------------------------
// Abilities (PHB p.9-11). Scores run 3-18 on the standard methods;
// STR 18 may carry exceptional percentile strength 01-00(100) for
// fighters (and fighter subclasses: paladin, ranger).
// ----------------------------------------------------------------------------
enum Ability : int {
    ABILITY_STR = 0,
    ABILITY_INT,
    ABILITY_WIS,
    ABILITY_DEX,
    ABILITY_CON,
    ABILITY_CHA,
    ABILITY_COUNT
};

const char* abilityName(Ability a);

struct AbilityScores {
    uint8_t str = 10;
    uint8_t int_ = 10;
    uint8_t wis = 10;
    uint8_t dex = 10;
    uint8_t con = 10;
    uint8_t cha = 10;

    uint8_t get(Ability a) const;
    void set(Ability a, uint8_t v);
};

// ----------------------------------------------------------------------------
// Exceptional strength (PHB p.9). Valid only at STR 18 for the fighter
// group; stored as 0 = none, 1-100 = 18/01..18/00. Percentile roll is
// d100: 01-50 -> 18/01-50, 51-75 -> 18/51-75, 76-90 -> 18/76-90,
// 91-99 -> 18/91-99, 00 -> 18/00 (percentile strength 100).
// The to-hit/damage/carry bands (PHB p.9) are indexed by 51/76/91/100.
// ----------------------------------------------------------------------------
struct ExceptionalStrength {
    bool   has = false;     // only true for fighter group at STR 18
    uint8_t pct = 0;        // 1-100; 100 printed as "00"

    // PHB p.9 table (bands: 01-50, 51-75, 76-90, 91-99, 00)
    int  hitAdj()    const;   // -1..+3 to hit
    int  dmgAdj()    const;   // -1..+6 damage
    int  weightAllow() const; // lbs before minor penalty
    int  press()     const;   // max press lbs (informational)
};

// ----------------------------------------------------------------------------
// Effective melee to-hit / damage adjustment from STR, combining the plain
// score table (PHB p.9) and exceptional strength at 18.
// ----------------------------------------------------------------------------
int strHitAdj(uint8_t str, const ExceptionalStrength& ex);
int strDmgAdj(uint8_t str, const ExceptionalStrength& ex);

// ----------------------------------------------------------------------------
// DEX tables (PHB p.11-12)
//   reactionAdj: missile fire + reaction adjustment (also used as the
//                personal surprise modifier in the turn/ layer)
//   defensiveAdj: AC modifier (missile and melee)
// ----------------------------------------------------------------------------
int dexReactionAdj(uint8_t dex);    // -2..+2
int dexDefensiveAdj(uint8_t dex);   // -4..+0  (better DEX = lower AC)

// ----------------------------------------------------------------------------
// CON table (PHB p.12)
//   hpAdj: bonus hp per hit die (clerics/fighters +1..+2 at high CON;
//          full table applies to all classes per PHB, fighters gain the
//          higher values — see rules/classes conHPAdjustment)
//   systemShock: percent (d100 <= value = survive)
//   resurrectionSurvival: percent
//   poisonSaveAdj: save modifier vs. poison
// ----------------------------------------------------------------------------
int  conHPAdj(uint8_t con);          // -2..+2
int  conSystemShock(uint8_t con);    // 25..99 (%)
int  conResSurvival(uint8_t con);    // 35..100 (%)
int  conPoisonSaveAdj(uint8_t con);  // -2..+2

// ----------------------------------------------------------------------------
// INT / WIS / CHA tables (PHB p.10-11)
// ----------------------------------------------------------------------------
int  intExtraLanguages(uint8_t int_);   // language count adj
int  wisMagDefAdj(uint8_t wis);         // save vs. magic adj, -2..+2
int  chaReactionAdj(uint8_t cha);       // -4..+4 (hireling reaction roll)
int  chaHenchmenMax(uint8_t cha);       // 0..15 (max henchmen, morale-linked)
int  chaLoyaltyBase(uint8_t cha);       // 1..12 base loyalty

// ----------------------------------------------------------------------------
// Prime requisites (PHB p.12-13): XP adjustment by class prime requisite.
// PHB method: 16-18 = +10%, 13-15 = +5%, 9-12 = 0, 6-8 = -10%, 3-5 = -20%.
// Multi-class characters average their requisites; the class layer
// (rules/classes) owns which abilities are prime for which class.
// ----------------------------------------------------------------------------
enum XPPct : int {
    XP_MINUS20 = -20,
    XP_MINUS10 = -10,
    XP_NONE    = 0,
    XP_PLUS5   = 5,
    XP_PLUS10  = 10,
};
XPPct primeRequisitePct(uint8_t score);

// ----------------------------------------------------------------------------
// Generation methods (PHB p.8-9 conventions; method names per PHB):
//   GEN_3D6:      3d6 in order, straight (the 1e default, "Method I")
//   GEN_4D6_DROP: 4d6 drop lowest, in order (rebuild default for pre-gens;
//                 logged as rebuild decision R3)
// Both roll STR first, then INT, WIS, DEX, CON, CHA. Exceptional
// strength is NOT rolled here — rolled on demand by the class layer
// for fighter-group characters (and only at STR 18).
// ----------------------------------------------------------------------------
enum GenMethod : int { GEN_3D6 = 0, GEN_4D6_DROP };

AbilityScores rollAbilities(Dice& dice, GenMethod method);

} // namespace rules