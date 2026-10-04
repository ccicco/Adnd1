// ====================================================================
// Adnd1 - rules/weaponless.h
// R160: weaponless combat (DMG pp.72-73) - PUMMEL,
// GRAPPLE, OVERBEAR: the three procedures, their
// modifiers and their tables.
//
// Header-only (the grenade.h pattern): the caller rolls
// percentile dice, adds the adjustments, and reads the
// table; the caller carries the state flags (slowed,
// stunned, helpless, holds, occupied hands).
//
// The shared variable (p.72): the attacker takes the
// weapon-attack column number (1 lowest levels, up) plus
// a secret d6; the defender the column plus a d4. Each
// side spends its variable on EITHER the base chance OR
// the succeeded-attack score, decided before each attack.
// Unconscious parties gain no such variable.
//
// First-attack initiative (p.72): surprise, then
// charging to attack, then higher dexterity, then higher
// die roll - in that order.
//
// Damage accounting: 25% actual for pummel and grapple,
// 50% for overbear; the balance restored at 1 hit point
// per round. 0 hit points = unconsciousness: 1 round plus
// 1 round per point beyond 0 (the print: 4 hit points
// beyond = 5 rounds). An unconscious opponent can be
// trussed or slain in 1 round.
//
// Pummel (p.72): fists or dagger pommel; two pummeling
// attacks per round. Base score: opponent AC x 10 (AC 10
// = 100% down to AC 0 and below = none).
// Grapple (p.72-73): hold the opponent helpless; an
// attack and a counter each round; an existing hold acts
// first until broken; attacker hands must be free. Base:
// attacker AC x 10, magical devices ignored, +1% per
// magical armor plus.
// Overbear (p.73): take the opponent prone; hands may be
// occupied (shield, weapon). Base: same as grapple. Once
// overborne, some other form of combat MUST follow.
//
// General notes: as many opponents as can physically
// engage may attack; attack from behind negates the
// shield and dexterity components; a weapon-wielding
// opponent strikes first (its hit does no damage, just
// fends the attack off) unless the attacker has surprise;
// monsters choose the most effective mode if human/
// humanoid with above-average intelligence, else random;
// weaponless non-weapon monsters always overbear except
// bears and similar huggers (grapple); monks conduct
// open hand combat normally until stunned or unconscious.
// ====================================================================

#pragma once

#include "dice.h"

#include <cstring>

namespace rules {

// ----------------------------------------------------------------------------
// Kinds, defender armor and helmet categories, pummel
// weapons. WLA_CHAIN_RING_SCALE also reads studded mail for
// the pummel strike table row (chain, ring, scale or
// studded -20%); the grapple base table lists chain, ring,
// scale (+20%) and the overbear base reads the grapple one.
// ----------------------------------------------------------------------------
enum WeaponlessKind { WL_PUMMEL = 0, WL_GRAPPLE,
                      WL_OVERBEAR, WL_KIND_COUNT };

enum WeaponlessArmor { WLA_NONE = 0, WLA_LEATHER_PADDED,
                       WLA_CHAIN_RING_SCALE,
                       WLA_BANDED_PLATE_SPLINT };

enum WeaponlessHelmet { WLH_NONE = 0, WLH_OPEN, WLH_NASALED,
                       WLH_VISORED };

enum WeaponlessPummelWeapon { WLP_FISTS = 0,
                             WLP_WOODEN_MAILED,
                             WLP_METAL_POMMEL };

// ----------------------------------------------------------------------------
// The shared variable: the attacker column + d6, the
// defender column + d4. The caller decides the spend.
// ----------------------------------------------------------------------------
inline int weaponlessVariable(Dice& dice, int column,
                               bool attacker) {
    int d = attacker ? (int)dice.d6() : (int)dice.d4();
    return column + d;
}

inline bool weaponlessUnconsciousGetsVariable() {
    return false;
}

// ----------------------------------------------------------------------------
// First-attack initiative (p.72): surprise, then charging,
// then higher dexterity, then higher die roll. Returns
// -1 if the attacker is first, 1 if the defender is
// first, 0 if tied.
// ----------------------------------------------------------------------------
inline int weaponlessInitiativeFirst(bool attackerSurprise,
                                      bool defenderSurprise,
                                      bool attackerCharging,
                                      bool defenderCharging,
                                      int dexA, int dexB,
                                      int rollA, int rollB) {
    if (attackerSurprise != defenderSurprise)
        return attackerSurprise ? -1 : 1;
    if (attackerCharging != defenderCharging)
        return attackerCharging ? -1 : 1;
    if (dexA != dexB) return dexA > dexB ? -1 : 1;
    if (rollA != rollB) return rollA > rollB ? -1 : 1;
    return 0;
}

// ----------------------------------------------------------------------------
// Damage accounting
// ----------------------------------------------------------------------------
inline int weaponlessActualPct(WeaponlessKind k) {
    return (k == WL_OVERBEAR) ? 50 : 25;
}

inline int weaponlessHealPerRound() { return 1; }

// 0 hit points = unconscious: 1 round plus 1 round per
// point beyond 0 (the print example: 4 beyond = 5 rounds).
inline int weaponlessUnconsciousRounds(int hpBeyondZero) {
    if (hpBeyondZero < 0) hpBeyondZero = 0;
    return 1 + hpBeyondZero;
}

inline int weaponlessTrussRounds() { return 1; }

// Two pummeling attacks per round (p.72).
inline int weaponlessPummelAttacksPerRound() { return 2; }

// Grapple: an attack and a counter each round; an
// existing hold automatically goes first until broken.
inline bool grappleAttackAndCounterPerRound() { return true; }
inline bool grappleHoldActsFirst() { return true; }

// The attacker cannot grapple if either or both hands
// hold anything (p.72); overbearing hands may be occupied.
inline bool grappleHandsFree(bool eitherHandOccupied) {
    return !eitherHandOccupied;
}
inline bool overbearAllowsOccupiedHands() { return true; }

// Once overborne, some other form of combat MUST take
// place (p.73).
inline bool overbearRequiresFollowUp() { return true; }

// ----------------------------------------------------------------------------
// Pummel (p.72): base score = opponent AC x 10, down to
// AC 0 and minus values (no or negative chance).
// ----------------------------------------------------------------------------
inline int pummelBaseChance(int opponentAc) {
    return opponentAc * 10;   // AC 10 = 100%; <= 0: none
}

// The base-chance modifiers (p.72): attacker dex +1% per
// point, attacker strength +1% per point over 15,
// attacker AC +1% per point (negative AC as positive),
// opponent slowed +10%, opponent stunned +20%, opponent
// base movement over 12 inches -5%, opponent hasted
// (speed potion included) -10%. Opponent prone without
// shield or ready weapon and/or helpless: AUTOMATIC HIT.
inline int pummelHitAdj(int attackerDex,
                        int attackerStrOver15,
                        int attackerAc, bool oppSlowed,
                        bool oppStunned, int oppBaseMove,
                        bool oppHasted) {
    int a = attackerDex;
    a += attackerStrOver15;
    a += (attackerAc < 0) ? -attackerAc : attackerAc;
    if (oppSlowed)  a += 10;
    if (oppStunned) a += 20;
    if (oppBaseMove > 12) a -= 5;
    if (oppHasted) a -= 10;
    return a;
}

inline bool pummelAutomaticHit(bool oppProneHelpless) {
    return oppProneHelpless;
}

// The strike-score modifiers (p.72), applied to the
// percentile roll before the PUMMELING TABLE:
// attacker strength +1% per point over 12, +2% per 10%
// over 18; wooden butt or mailed fist +5%; metal pommel
// +10%; opponent slowed +10%, stunned +20%, helpless
// +30%; active defender dex -2% per point over 14,
// shield -10%, leather or padded -10%, chain/ring/
// scale/studded -20%, magical cloak or ring -30%,
// banded/plate/splint -40%; helmets open-faced -5%,
// nasaled -10%, visored or slitted -20%.
inline int pummelStrikeAdj(int attackerStrOver12,
                           int strPctOver18,
                           WeaponlessPummelWeapon weapon,
                           bool oppSlowed, bool oppStunned,
                           bool oppHelpless, int oppDexOver14,
                           bool oppShield,
                           WeaponlessArmor oppArmor,
                           bool oppMagicCloakOrRing,
                           WeaponlessHelmet oppHelmet) {
    int a = attackerStrOver12 + 2 * (strPctOver18 / 10);
    if (weapon == WLP_WOODEN_MAILED) a += 5;
    if (weapon == WLP_METAL_POMMEL) a += 10;
    if (oppSlowed)  a += 10;
    if (oppStunned) a += 20;
    if (oppHelpless) a += 30;
    a -= 2 * oppDexOver14;
    if (oppShield) a -= 10;
    if (oppArmor == WLA_LEATHER_PADDED) a -= 10;
    if (oppArmor == WLA_CHAIN_RING_SCALE) a -= 20;
    if (oppMagicCloakOrRing) a -= 30;
    if (oppArmor == WLA_BANDED_PLATE_SPLINT) a -= 40;
    if (oppHelmet == WLH_OPEN) a -= 5;
    if (oppHelmet == WLH_NASALED) a -= 10;
    if (oppHelmet == WLH_VISORED) a -= 20;
    return a;
}

// ----------------------------------------------------------------------------
// Grapple (pp.72-73): base score = attacker AC x 10,
// magical devices ignored, +1% per magical armor plus.
// ----------------------------------------------------------------------------
inline int grappleBaseChance(int attackerAc,
                             int magicArmorPlus) {
    return attackerAc * 10 + magicArmorPlus;
}

// The base-chance modifiers (p.72): attacker dex +1% per
// point; defender armor leather or padded +10%, chain or
// ring or scale +20%, banded or plate or splint +30%;
// opponent slowed or stunned +20%; opponent base
// movement 3 inches faster -10% per 3 inches; opponent
// hasted (speed potion included) -20%.
inline int grappleBaseAdj(int attackerDex,
                          WeaponlessArmor defenderArmor,
                          bool oppSlowedOrStunned,
                          int oppMoveFasterPer3Inches,
                          bool oppHasted) {
    int a = attackerDex;
    if (defenderArmor == WLA_LEATHER_PADDED) a += 10;
    if (defenderArmor == WLA_CHAIN_RING_SCALE) a += 20;
    if (defenderArmor == WLA_BANDED_PLATE_SPLINT) a += 30;
    if (oppSlowedOrStunned) a += 20;
    a -= 10 * oppMoveFasterPer3Inches;
    if (oppHasted) a -= 20;
    return a;
}

// The hold-roll modifiers (pp.72-73), applied to the
// second percentile roll: attacker dex +1% per point,
// attacker strength +1% per point, +1% per 10% over 18;
// opponent slowed +10%, stunned +20%, helpless +30%;
// per 10% weight difference (attacker heavier positive)
// +/-5%; per 10% height difference +/-5%; opponent dex
// -2% per point over 14; opponent strength -1% per point
// over 12, -1% per 10% over 18; opponent banded or plate
// -10%; gorget and helmet -10%; shield -10%.
inline int grappleHoldAdj(int attackerDex, int attackerStr,
                          int strPctOver18, bool oppSlowed,
                          bool oppStunned, bool oppHelpless,
                          int weightPctDiff,
                          int heightPctDiff, int oppDexOver14,
                          int oppStrOver12, int oppStrPctOver18,
                          bool oppBandedOrPlate,
                          bool oppGorgetAndHelmet,
                          bool oppShield) {
    int a = attackerDex + attackerStr;
    a += strPctOver18 / 10;
    if (oppSlowed)  a += 10;
    if (oppStunned) a += 20;
    if (oppHelpless) a += 30;
    a += 5 * (weightPctDiff / 10);
    a += 5 * (heightPctDiff / 10);
    a -= 2 * oppDexOver14;
    a -= oppStrOver12;
    a -= oppStrPctOver18 / 10;
    if (oppBandedOrPlate) a -= 10;
    if (oppGorgetAndHelmet) a -= 10;
    if (oppShield) a -= 10;
    return a;
}

// The hold ladder: a higher-percentage hold breaks a
// lower one (an arm lock breaks a waist clinch, a hand
// lock breaks an arm lock, and so forth). A stunned
// opponent cannot counter for 1 round, and a second
// attack may immediately be made.
inline bool grappleHoldBreaks(int newHoldIdx, int oldHoldIdx) {
    return newHoldIdx > oldHoldIdx;
}
inline bool grappleStunnedAllowsImmediateSecond() {
    return true;
}

// ----------------------------------------------------------------------------
// Overbear (p.73): base score same as grappling.
// ----------------------------------------------------------------------------
// The overbear-roll modifiers, applied to the second
// percentile roll: attacker strength +1% per point,
// +2% per 10% over 18; opponent slowed or one foot held
// +10%; rushing or leaping to attack +15%; opponent
// stunned or both feet held +20%; per 10% weight
// difference +/-10%; per 10% height difference +/-5%;
// opponent strength -1% per point over 14, -2% per 10%
// over 18; opponent dex -2% per point over 14;
// opponent braced -10%.
inline int overbearAdj(int attackerStr, int strPctOver18,
                       bool oppSlowedOrOneFootHeld,
                       bool rushingOrLeaping,
                       bool oppStunnedOrBothFeetHeld,
                       int weightPctDiff, int heightPctDiff,
                       int oppStrOver14, int oppStrPctOver18,
                       int oppDexOver14, bool oppBraced) {
    int a = attackerStr + 2 * (strPctOver18 / 10);
    if (oppSlowedOrOneFootHeld) a += 10;
    if (rushingOrLeaping) a += 15;
    if (oppStunnedOrBothFeetHeld) a += 20;
    a += 10 * (weightPctDiff / 10);
    a += 5 * (heightPctDiff / 10);
    a -= oppStrOver14;
    a -= 2 * (oppStrPctOver18 / 10);
    a -= 2 * oppDexOver14;
    if (oppBraced) a -= 10;
    return a;
}

// ----------------------------------------------------------------------------
// The three tables. Adjusted score -> tier; the damage
// base rides the tier (the strength bonus is added by
// the caller). Over 00 tiers read at 101 and above.
// ----------------------------------------------------------------------------
struct WeaponlessTier {
    const char* name;
    int lo, hi;      // inclusive adjusted-score range
    int baseDmg;     // + strength bonus, caller-side
};

inline const WeaponlessTier* weaponlessTiers(
        WeaponlessKind k, int& count) {
    static const WeaponlessTier pummel[] = {
        { "blow misses, opponent may counter", -1000,   0,  0 },
        { "ineffective blow, strike again",       1,  20,  0 },
        { "glancing blow, off balance",          21,  40,  2 },
        { "glancing blow, strike again",         41,  60,  4 },
        { "solid punch, off balance",             61,  80,  6 },
        { "solid punch, strike again",           81, 100,  8 },
        { "crushing blow, opponent stunned",     101, 1000, 10 },
    };
    static const WeaponlessTier grapple[] = {
        { "waist clinch, opponent may counter", -1000, 20, 0 },
        { "arm lock, forearm or elbow smash",      21, 40, 1 },
        { "hand or finger lock, bite",             41, 55, 2 },
        { "bear hug, trip",                       56, 70, 3 },
        { "headlock, flip or throw",              71, 85, 5 },
        { "strangle hold, head butt",             86, 95, 6 },
        { "kick, knee or gouge, stunned",         96, 1000, 8 },
    };
    static const WeaponlessTier overbear[] = {
        { "bounce off or avoided, opponent may counter",
                                                       -1000, 20, 0 },
        { "slip down and grab leg",                    21, 40, 0 },
        { "opponent staggered, attack again",          41, 60, 1 },
        { "opponent knocked to knees",                 61, 80, 2 },
        { "opponent knocked to hands and knees",      81, 100, 3 },
        { "opponent knocked flat, stunned 1 round",   101, 1000, 4 },
    };
    switch (k) {
        case WL_PUMMEL:  count = 7; return pummel;
        case WL_GRAPPLE: count = 7; return grapple;
        default:         count = 6; return overbear;
    }
}

inline int weaponlessTierIndex(WeaponlessKind k,
                               int adjustedScore) {
    int n = 0;
    const WeaponlessTier* t = weaponlessTiers(k, n);
    for (int i = 0; i < n; ++i)
        if (adjustedScore >= t[i].lo && adjustedScore <= t[i].hi)
            return i;
    return (adjustedScore > 0) ? n - 1 : 0;
}

inline int weaponlessTierDamage(WeaponlessKind k, int idx) {
    int n = 0;
    const WeaponlessTier* t = weaponlessTiers(k, n);
    if (idx < 0) idx = 0;
    if (idx >= n) idx = n - 1;
    return t[idx].baseDmg;
}

// ----------------------------------------------------------------------------
// General notes
// ----------------------------------------------------------------------------
// A weapon-wielding opponent strikes first (its hit does
// no damage but fends the attack off) unless the
// attacker has surprise; a surprised weapon wielder has
// no fending strike unless the attacker must spend all
// surprise segments closing.
inline bool weaponlessWeaponWielderFirst(
        bool attackerHasSurprise) {
    return !attackerHasSurprise;
}

// Attack from behind negates the shield and dexterity
// components of the defending creature.
inline bool weaponlessBehindNegatesShieldAndDex() {
    return true;
}

// Monsters choose the most effective mode if human or
// humanoid with above-average intelligence, else random;
// creatures that do not use weapons always overbear,
// except bears and similar hugging monsters (grapple).
inline bool bearLikeHuggerGrappples() { return true; }
inline bool weaponlessMonsterOverbears() { return true; }

// Monks conduct open hand combat normally even if
// grappled, pummeled or overborne, until stunned or
// unconscious.
inline bool monkOpenHandUnimpeded() { return true; }

} // namespace rules
