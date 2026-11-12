// ====================================================================
// Adnd1 - rules/dmg/weaponless.h
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

#include "../engine/dice.h"

#include <cstring>
using rules::Dice;  // R-refactor: engine type, was namespace-implicit




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
// The three tables. Adjusted score -> tier; the damage
// base rides the tier (the strength bonus is added by
// the caller). Over 00 tiers read at 101 and above.
// ----------------------------------------------------------------------------
struct WeaponlessTier {
    const char* name;
    int lo, hi;      // inclusive adjusted-score range
    int baseDmg;     // + strength bonus, caller-side
};

// R-refactor: namespace rules -> class Weaponless (instance methods)
class Weaponless {
public:


// ----------------------------------------------------------------------------
// The shared variable: the attacker column + d6, the
// defender column + d4. The caller decides the spend.
// ----------------------------------------------------------------------------
    int weaponlessVariable(Dice& dice, int column, bool attacker);
    bool weaponlessUnconsciousGetsVariable();


// ----------------------------------------------------------------------------
// First-attack initiative (p.72): surprise, then charging,
// then higher dexterity, then higher die roll. Returns
// -1 if the attacker is first, 1 if the defender is
// first, 0 if tied.
// ----------------------------------------------------------------------------
    int weaponlessInitiativeFirst(bool attackerSurprise, bool defenderSurprise, bool attackerCharging, bool defenderCharging, int dexA, int dexB, int rollA, int rollB);


// ----------------------------------------------------------------------------
// Damage accounting
// ----------------------------------------------------------------------------
    int weaponlessActualPct(WeaponlessKind k);
    int weaponlessHealPerRound();


// 0 hit points = unconscious: 1 round plus 1 round per
// point beyond 0 (the print example: 4 beyond = 5 rounds).
    int weaponlessUnconsciousRounds(int hpBeyondZero);
    int weaponlessTrussRounds();


// Two pummeling attacks per round (p.72).
    int weaponlessPummelAttacksPerRound();


// Grapple: an attack and a counter each round; an
// existing hold automatically goes first until broken.
    bool grappleAttackAndCounterPerRound();
    bool grappleHoldActsFirst();


// The attacker cannot grapple if either or both hands
// hold anything (p.72); overbearing hands may be occupied.
    bool grappleHandsFree(bool eitherHandOccupied);
    bool overbearAllowsOccupiedHands();


// Once overborne, some other form of combat MUST take
// place (p.73).
    bool overbearRequiresFollowUp();


// ----------------------------------------------------------------------------
// Pummel (p.72): base score = opponent AC x 10, down to
// AC 0 and minus values (no or negative chance).
// ----------------------------------------------------------------------------
    int pummelBaseChance(int opponentAc);


// The base-chance modifiers (p.72): attacker dex +1% per
// point, attacker strength +1% per point over 15,
// attacker AC +1% per point (negative AC as positive),
// opponent slowed +10%, opponent stunned +20%, opponent
// base movement over 12 inches -5%, opponent hasted
// (speed potion included) -10%. Opponent prone without
// shield or ready weapon and/or helpless: AUTOMATIC HIT.
    int pummelHitAdj(int attackerDex, int attackerStrOver15, int attackerAc, bool oppSlowed, bool oppStunned, int oppBaseMove, bool oppHasted);
    bool pummelAutomaticHit(bool oppProneHelpless);


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
    int pummelStrikeAdj(int attackerStrOver12, int strPctOver18, WeaponlessPummelWeapon weapon, bool oppSlowed, bool oppStunned, bool oppHelpless, int oppDexOver14, bool oppShield, WeaponlessArmor oppArmor, bool oppMagicCloakOrRing, WeaponlessHelmet oppHelmet);


// ----------------------------------------------------------------------------
// Grapple (pp.72-73): base score = attacker AC x 10,
// magical devices ignored, +1% per magical armor plus.
// ----------------------------------------------------------------------------
    int grappleBaseChance(int attackerAc, int magicArmorPlus);


// The base-chance modifiers (p.72): attacker dex +1% per
// point; defender armor leather or padded +10%, chain or
// ring or scale +20%, banded or plate or splint +30%;
// opponent slowed or stunned +20%; opponent base
// movement 3 inches faster -10% per 3 inches; opponent
// hasted (speed potion included) -20%.
    int grappleBaseAdj(int attackerDex, WeaponlessArmor defenderArmor, bool oppSlowedOrStunned, int oppMoveFasterPer3Inches, bool oppHasted);


// The hold-roll modifiers (pp.72-73), applied to the
// second percentile roll: attacker dex +1% per point,
// attacker strength +1% per point, +1% per 10% over 18;
// opponent slowed +10%, stunned +20%, helpless +30%;
// per 10% weight difference (attacker heavier positive)
// +/-5%; per 10% height difference +/-5%; opponent dex
// -2% per point over 14; opponent strength -1% per point
// over 12, -1% per 10% over 18; opponent banded or plate
// -10%; gorget and helmet -10%; shield -10%.
    int grappleHoldAdj(int attackerDex, int attackerStr, int strPctOver18, bool oppSlowed, bool oppStunned, bool oppHelpless, int weightPctDiff, int heightPctDiff, int oppDexOver14, int oppStrOver12, int oppStrPctOver18, bool oppBandedOrPlate, bool oppGorgetAndHelmet, bool oppShield);


// The hold ladder: a higher-percentage hold breaks a
// lower one (an arm lock breaks a waist clinch, a hand
// lock breaks an arm lock, and so forth). A stunned
// opponent cannot counter for 1 round, and a second
// attack may immediately be made.
    bool grappleHoldBreaks(int newHoldIdx, int oldHoldIdx);
    bool grappleStunnedAllowsImmediateSecond();


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
    int overbearAdj(int attackerStr, int strPctOver18, bool oppSlowedOrOneFootHeld, bool rushingOrLeaping, bool oppStunnedOrBothFeetHeld, int weightPctDiff, int heightPctDiff, int oppStrOver14, int oppStrPctOver18, int oppDexOver14, bool oppBraced);
    const WeaponlessTier* weaponlessTiers( WeaponlessKind k, int& count);
    int weaponlessTierIndex(WeaponlessKind k, int adjustedScore);
    int weaponlessTierDamage(WeaponlessKind k, int idx);


// ----------------------------------------------------------------------------
// General notes
// ----------------------------------------------------------------------------
// A weapon-wielding opponent strikes first (its hit does
// no damage but fends the attack off) unless the
// attacker has surprise; a surprised weapon wielder has
// no fending strike unless the attacker must spend all
// surprise segments closing.
    bool weaponlessWeaponWielderFirst( bool attackerHasSurprise);


// Attack from behind negates the shield and dexterity
// components of the defending creature.
    bool weaponlessBehindNegatesShieldAndDex();


// Monsters choose the most effective mode if human or
// humanoid with above-average intelligence, else random;
// creatures that do not use weapons always overbear,
// except bears and similar hugging monsters (grapple).
    bool bearLikeHuggerGrappples();
    bool weaponlessMonsterOverbears();


// Monks conduct open hand combat normally even if
// grappled, pummeled or overborne, until stunned or
// unconscious.
    bool monkOpenHandUnimpeded();
};
