// ============================================================================
// Adnd1 - rules/attacksround.h
// Attacks per melee round (R181).
//
// The fighters, paladins and rangers attacks-per-melee-round
// table (PHB, the class tables section): 1/1 round in the low
// band, 3/2 rounds in the middle band, 2/1 round in the high band
// - with any thrusting or striking weapon. The table note: this
// excludes melee with monsters of less than one hit die (d8) and
// non-exceptional 0-level humans and semi-humans; against all
// such creatures a fighter attacks once for each experience
// level per round.
//
// The monk unarmed ladder (PHB Monks Table II): the effective
// armor class, the movement, the attacks per melee round and the
// open-hand damage for all 17 printed levels. The monk also adds
// half a hit point per level of weapon damage on a successful
// weapon attack (the doubled form below avoids halves), attacks
// on the thief table, and the monk to-hit is never modified by
// strength bonuses.
//
// JUDGMENTs:
//   - the rate convention: attacks per rounds, so 3/2 rounds is
//     3 attacks per 2 rounds, the extra attack at the end of the
//     round sequence (the printed slash convention; 5/4 likewise
//     5 attacks per 4 rounds).
//   - the engine round model carries two swing slots (initiative
//     and initiative+5, rules/turn.cpp); meleeAttacksPerRound
//     returns the routine count of the HEAVY round of the printed
//     cycle: 1 below the 3/2 band, 2 in the 3/2 and 2/1 bands.
//     The full printed rates live HERE.
//   - the monk stun, kill and quivering-palm rules are specials
//     (the R187+ rounds), not this table.
//
// DATA-DRIVEN (the standing scope): a future class appends its
// band edges or its ladder rows.
// ============================================================================

#pragma once

#include "classes.h"
#include "subclasses.h"

#include <cstdint>

namespace rules {

// The printed rate: attacks per rounds (1/1, 3/2, 2/1,
// the monk 5/4 and 5/2 likewise).
struct AtkRate {
    int attacks;
    int rounds;
};

// ---- the fighter-group table ----
// kind 0 = fighter, 1 = paladin, 2 = ranger.
// Band edges: fighter and paladin 1-6 / 7-12 / 13 and up;
// ranger 1-7 / 8-14 / 15 and up (the print).
inline AtkRate fighterGroupAttacks(int kind, int level) {
    static const int kMid[3]  = { 7, 7, 8 };
    static const int kHigh[3] = { 13, 13, 15 };
    if (kind < 0) kind = 0;
    if (kind > 2) kind = 2;
    if (level < 1) level = 1;
    if (level < kMid[kind])
        return { 1, 1 };
    if (level < kHigh[kind])
        return { 3, 2 };
    return { 2, 1 };
}

// The table note: against creatures of less than one hit die
// (d8) and non-exceptional 0-level humans and semi-humans, one
// attack per fighter experience level per round.
inline int fighterAttacksVsSubOneHitDice(int level) {
    if (level < 1) return 1;
    return level;
}

// ---- the monk unarmed ladder (Monks Table II) ----

struct MonkLadderRow {
    int level;      // 1-17
    int acClass;    // the effective armor class (open hand)
    int moveInches; // the printed movement
    int atkAttacks;// attacks ...
    int atkRounds; // ... per this many rounds
    int dmgLo;     // open-hand damage low
    int dmgHi;     // open-hand damage high
};

static const MonkLadderRow kMonkLadder[17] = {
    {  1, 10, 15, 1, 1, 1,  3 },
    {  2,  9, 16, 1, 1, 1,  4 },
    {  3,  8, 17, 1, 1, 1,  6 },
    {  4,  7, 18, 5, 4, 1,  6 },
    {  5,  7, 19, 5, 4, 2,  7 },
    {  6,  6, 20, 3, 2, 2,  8 },
    {  7,  5, 21, 3, 2, 3,  9 },
    {  8,  4, 22, 3, 2, 2, 12 },
    {  9,  3, 23, 2, 1, 3, 12 },
    { 10,  3, 24, 2, 1, 3, 13 },
    { 11,  2, 25, 5, 2, 4, 13 },
    { 12,  1, 26, 5, 2, 4, 16 },
    { 13,  0, 27, 5, 2, 5, 17 },
    { 14, -1, 28, 3, 1, 5, 20 },
    { 15, -1, 29, 3, 1, 6, 24 },
    { 16, -2, 30, 4, 1, 5, 30 },
    { 17, -3, 32, 4, 1, 8, 32 }
};

inline int monkLadderRowCount() { return 17; }

inline const MonkLadderRow& monkLadderRow(int level) {
    if (level < 1) level = 1;
    if (level > 17) level = 17;
    return kMonkLadder[level - 1];
}

// The open-hand attacks per melee round (the printed slash).
inline AtkRate monkOpenHandAttacks(int level) {
    const MonkLadderRow& r = monkLadderRow(level);
    return { r.atkAttacks, r.atkRounds };
}

// The monk weapon damage: half a hit point per level of
// experience added to the weapon damage on a hit (1st level
// +1/2, 2nd +1, ... Grand Master of Flowers +8 1/2). Doubled
// form: the bonus is monkWeaponDamageBonus2x / 2.
inline int monkWeaponDamageBonus2x(int level) {
    if (level < 1) level = 1;
    if (level > 17) level = 17;
    return level;
}

} // namespace rules
