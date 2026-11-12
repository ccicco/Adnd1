// R-refactor: split from weaponless.h - definitions
#include "rules/dmg/weaponless.h"

int Weaponless::weaponlessVariable(Dice& dice, int column, bool attacker) {
    int d = attacker ? (int)dice.d6() : (int)dice.d4();
    return column + d;
}

bool Weaponless::weaponlessUnconsciousGetsVariable() {
    return false;
}

int Weaponless::weaponlessInitiativeFirst(bool attackerSurprise, bool defenderSurprise, bool attackerCharging, bool defenderCharging, int dexA, int dexB, int rollA, int rollB) {
    if (attackerSurprise != defenderSurprise)
        return attackerSurprise ? -1 : 1;
    if (attackerCharging != defenderCharging)
        return attackerCharging ? -1 : 1;
    if (dexA != dexB) return dexA > dexB ? -1 : 1;
    if (rollA != rollB) return rollA > rollB ? -1 : 1;
    return 0;
}

int Weaponless::weaponlessActualPct(WeaponlessKind k) {
    return (k == WL_OVERBEAR) ? 50 : 25;
}

int Weaponless::weaponlessHealPerRound() { return 1; }

int Weaponless::weaponlessUnconsciousRounds(int hpBeyondZero) {
    if (hpBeyondZero < 0) hpBeyondZero = 0;
    return 1 + hpBeyondZero;
}

int Weaponless::weaponlessTrussRounds() { return 1; }

int Weaponless::weaponlessPummelAttacksPerRound() { return 2; }

bool Weaponless::grappleAttackAndCounterPerRound() { return true; }

bool Weaponless::grappleHoldActsFirst() { return true; }

bool Weaponless::grappleHandsFree(bool eitherHandOccupied) {
    return !eitherHandOccupied;
}

bool Weaponless::overbearAllowsOccupiedHands() { return true; }

bool Weaponless::overbearRequiresFollowUp() { return true; }

int Weaponless::pummelBaseChance(int opponentAc) {
    return opponentAc * 10;   // AC 10 = 100%; <= 0: none
}

int Weaponless::pummelHitAdj(int attackerDex, int attackerStrOver15, int attackerAc, bool oppSlowed, bool oppStunned, int oppBaseMove, bool oppHasted) {
    int a = attackerDex;
    a += attackerStrOver15;
    a += (attackerAc < 0) ? -attackerAc : attackerAc;
    if (oppSlowed)  a += 10;
    if (oppStunned) a += 20;
    if (oppBaseMove > 12) a -= 5;
    if (oppHasted) a -= 10;
    return a;
}

bool Weaponless::pummelAutomaticHit(bool oppProneHelpless) {
    return oppProneHelpless;
}

int Weaponless::pummelStrikeAdj(int attackerStrOver12, int strPctOver18, WeaponlessPummelWeapon weapon, bool oppSlowed, bool oppStunned, bool oppHelpless, int oppDexOver14, bool oppShield, WeaponlessArmor oppArmor, bool oppMagicCloakOrRing, WeaponlessHelmet oppHelmet) {
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

int Weaponless::grappleBaseChance(int attackerAc, int magicArmorPlus) {
    return attackerAc * 10 + magicArmorPlus;
}

int Weaponless::grappleBaseAdj(int attackerDex, WeaponlessArmor defenderArmor, bool oppSlowedOrStunned, int oppMoveFasterPer3Inches, bool oppHasted) {
    int a = attackerDex;
    if (defenderArmor == WLA_LEATHER_PADDED) a += 10;
    if (defenderArmor == WLA_CHAIN_RING_SCALE) a += 20;
    if (defenderArmor == WLA_BANDED_PLATE_SPLINT) a += 30;
    if (oppSlowedOrStunned) a += 20;
    a -= 10 * oppMoveFasterPer3Inches;
    if (oppHasted) a -= 20;
    return a;
}

int Weaponless::grappleHoldAdj(int attackerDex, int attackerStr, int strPctOver18, bool oppSlowed, bool oppStunned, bool oppHelpless, int weightPctDiff, int heightPctDiff, int oppDexOver14, int oppStrOver12, int oppStrPctOver18, bool oppBandedOrPlate, bool oppGorgetAndHelmet, bool oppShield) {
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

bool Weaponless::grappleHoldBreaks(int newHoldIdx, int oldHoldIdx) {
    return newHoldIdx > oldHoldIdx;
}

bool Weaponless::grappleStunnedAllowsImmediateSecond() {
    return true;
}

int Weaponless::overbearAdj(int attackerStr, int strPctOver18, bool oppSlowedOrOneFootHeld, bool rushingOrLeaping, bool oppStunnedOrBothFeetHeld, int weightPctDiff, int heightPctDiff, int oppStrOver14, int oppStrPctOver18, int oppDexOver14, bool oppBraced) {
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

const WeaponlessTier* Weaponless::weaponlessTiers( WeaponlessKind k, int& count) {
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

int Weaponless::weaponlessTierIndex(WeaponlessKind k, int adjustedScore) {
    int n = 0;
    const WeaponlessTier* t = weaponlessTiers(k, n);
    for (int i = 0; i < n; ++i)
        if (adjustedScore >= t[i].lo && adjustedScore <= t[i].hi)
            return i;
    return (adjustedScore > 0) ? n - 1 : 0;
}

int Weaponless::weaponlessTierDamage(WeaponlessKind k, int idx) {
    int n = 0;
    const WeaponlessTier* t = weaponlessTiers(k, n);
    if (idx < 0) idx = 0;
    if (idx >= n) idx = n - 1;
    return t[idx].baseDmg;
}

bool Weaponless::weaponlessWeaponWielderFirst( bool attackerHasSurprise) {
    return !attackerHasSurprise;
}

bool Weaponless::weaponlessBehindNegatesShieldAndDex() {
    return true;
}

bool Weaponless::bearLikeHuggerGrappples() { return true; }

bool Weaponless::weaponlessMonsterOverbears() { return true; }

bool Weaponless::monkOpenHandUnimpeded() { return true; }
