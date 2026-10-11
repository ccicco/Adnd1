// ===========================================================================
// Adnd1 - rules/cavalier.h
// The UA cavalier class (pp. 14-16) pins (R328).
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
// The registry rows, the creation-flow gates and the reaction sites
// ride their own rounds. The Cavs Table I title cells for levels 5,
// 6, 11 and 12 are OCR-lost in the extract - the holes are documented
// at cavalierTitleKnown below and stay open with the gap report's
// Cavaliers Table I item (the L5/L6 grid/prose conflict too).
// ===========================================================================

#pragma once

#include <cstring>

#include "character.h"  // the Ability enum
#include "subraces.h"    // CharSubRace

namespace rules {

// ---- the class minima (p. 14) ----
// STR/DEX/CON 15, INT/WIS 10; no prime requisite (so no XP bonus);
// good alignment only; the cavalier and paladin take no weapon
// specialization (p. 18).
inline int cavalierMinAbility(int a) {
    switch (a) {
        case ABILITY_STR:
        case ABILITY_DEX:
        case ABILITY_CON:
            return 15;
        case ABILITY_INT:
        case ABILITY_WIS:
            return 10;
        default:
            return 0;   // charisma: no minimum
    }
}

inline bool cavalierNoPrimeRequisite()
    { return true; }

inline bool cavalierGoodAlignmentOnly()
    { return true; }

inline bool cavalierSpecializationBanned()
    { return true; }

// ---- the 0-level track (p. 14) ----
// Upper Class enters directly as a 1st-level Armiger (1d10+3); the
// sponsored lower classes ride the track: Horseman at -1500, Lancer
// at -500, Armiger at 0. The hp generators (3d4+1 vs d10+3) ride
// the R327 pins (rules/classtables.h); the class abilities begin at
// Armiger.
inline int cavalierHorsemanXp()
    { return -1500; }

inline int cavalierLancerXp()
    { return -500; }

// ---- the race gate (p. 14) ----
// Humans always; gray, dark or high elf stock (and half-elves of
// such descent) only when from or sponsored by a noble house. The
// other sub-races are excluded outright.
inline bool cavalierRaceAllowed(CharSubRace s,
                                bool sponsored) {
    switch (s) {
        case SUB_NONE:
        case SUB_HUMAN:
            return true;
        case SUB_ELF_DARK:
        case SUB_ELF_GRAY:
        case SUB_ELF_HIGH:
        case SUB_HALFELF:
            return sponsored;
        default:
            return false;
    }
}

// ---- the weapons of choice (p. 14) ----
// Mounted lance +1 at 1st/+2 at 7th/+3 at 13th; the broad/long/
// scimitar group +1 at 3rd/+2 at 9th; the horseman's mace/flail/
// pick group +1 at 5th/+2 at 11th - the higher plusses ride the
// weapon chosen at the lower level. Attacks with a weapon of
// choice read 5 levels higher, 3 per round at 16th and above. A
// mounted lance adds the level to damage; dismounted +1. A
// dismounted heavy lance reads as an awl pike, medium or light
// as a spear.
enum CavalierWeaponOfChoice : int {
    CAVALIER_WOC_LANCE = 0,
    CAVALIER_WOC_SWORD,      // broad, long or scimitar
    CAVALIER_WOC_MACE        // horseman's mace, flail
                             // or military pick
};

inline int cavalierWeaponOfChoiceBonus(
        int woc, int level) {
    switch (woc) {
        case CAVALIER_WOC_LANCE:
            if (level >= 13) return 3;
            if (level >= 7) return 2;
            return level >= 1 ? 1 : 0;
        case CAVALIER_WOC_SWORD:
            if (level >= 9) return 2;
            return level >= 3 ? 1 : 0;
        case CAVALIER_WOC_MACE:
            if (level >= 11) return 2;
            return level >= 5 ? 1 : 0;
        default:
            return 0;
    }
}

inline int cavalierChoiceAttackLevelBonus()
    { return 5; }

inline int cavalierChoiceAttacksPerRoundLevel()
    { return 16; }

inline int cavalierLanceMountedDamageBonus(
        int level)
    { return level; }

inline int cavalierLanceDismountedDamageBonus()
    { return 1; }

// The eleven preferred weapons (the lance is required of the
// 1st-level Armiger); elven and half-elven cavaliers add the
// short composite bow.
inline int cavalierPreferredWeaponCount()
    { return 11; }

inline const char* cavalierPreferredWeaponName(
        int i) {
    static const char* const k[11] = {
        "lance", "long sword", "broad sword",
        "bastard sword", "short sword",
        "horseman's mace", "horseman's flail",
        "horseman's military pick", "dagger",
        "scimitar", "javelin"
    };
    if (i < 0) i = 0;
    if (i > 10) i = 10;
    return k[i];
}

inline const char* cavalierElvenBowName()
    { return "short composite bow"; }

// ---- the parry reads (p. 15) ----
// A weapon parry subtracts all to-hit bonuses (strength, magic,
// weapon of choice); a shield parry on a second opponent reduces
// the roll by 1, plus 1 more per magic plus.
inline int cavalierShieldParryBase()
    { return 1; }

inline int cavalierShieldParryMagicBonus(int plus)
    { return plus; }

// ---- the armor preference order (p. 15) ----
// The rank the cavalier seeks: plate, plate mail, banded or
// splint, chain, scale, ring - never leather, studded or padded
// (the R327 station ban), and the order holds for magic armor.
inline int cavalierArmorPreference(
        const char* armor) {
    if (strcmp(armor, "plate") == 0)
        return 0;
    if (strcmp(armor, "plate mail") == 0)
        return 1;
    if (strcmp(armor, "banded") == 0
        || strcmp(armor, "splint") == 0)
        return 2;
    if (strcmp(armor, "chain") == 0)
        return 3;
    if (strcmp(armor, "scale") == 0)
        return 4;
    if (strcmp(armor, "ring") == 0)
        return 5;
    return -1;  // banned or unknown
}

// ---- the mounted reads (pp. 15-16) ----
// Human cavaliers (not elves or half-elves) make all mounted
// attacks at 1 level higher; the saddle/fall chance is 85%,
// +1% per level above 1st; the horsemanship ladder: 3rd vault,
// 4th the female-elf unicorn, 5th +2 speed for 6 turns, 7th
// pegasus, 9th hippogriff, 11th griffon; a chosen steed gains
// +2 hp per die; low worth reads at a third or less of the
// creature's maximum hp, high worth at two-thirds or better.
inline int cavalierHumanMountedLevelBonus()
    { return 1; }

inline int cavalierSaddlePercent(int level) {
    return 85 + (level > 1 ? level - 1 : 0);
}

inline int cavalierHorsemanshipLevel(int i) {
    static const int k[6] = {3, 4, 5, 7, 9, 11};
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    return k[i];
}

inline int cavalierSteedHpBonusPerDie()
    { return 2; }

inline int cavalierSteedLowWorthNum()
    { return 1; }

inline int cavalierSteedWorthDen()
    { return 3; }

inline int cavalierSteedHighWorthNum()
    { return 2; }

// ---- the percentile growth and the training rule (p. 16) ----
// STR/DEX/CON percentiles rolled at 1st; +2d10 per level; over
// 100 raises the main score by 1 (the excess discarded); the
// cap is 18/00; the percentiles are lost on level loss. The
// trainer must be 4th or 2 levels higher (whichever is
// higher); self-training after 6th.
inline int cavalierPercentileGainDice()
    { return 2; }

inline int cavalierPercentileGainSides()
    { return 10; }

inline int cavalierPercentileCap()
    { return 100; }

inline bool cavalierPercentileAbility(int a) {
    return a == ABILITY_STR || a == ABILITY_DEX
        || a == ABILITY_CON;
}

inline int cavalierTrainerMinLevel()
    { return 4; }

inline int cavalierTrainerLevelGap()
    { return 2; }

inline int cavalierSelfTrainFromLevel()
    { return 6; }

// ---- the saves and immunities (p. 16) ----
// Fear immunity plus the protection-from-fear aura (good
// only); 90% resistance to the mind-affecting powers (not
// comeliness); +2 versus illusion.
inline int cavalierMindAffectResistPercent()
    { return 90; }

inline int cavalierMindPowersCount()
    { return 10; }

inline const char* cavalierMindPowerName(int i) {
    static const char* const k[10] = {
        "beguiling", "charm", "domination",
        "hold", "hypnosis", "magic jar",
        "possession", "sleep", "suggestion",
        "psionic mind blast"
    };
    if (i < 0) i = 0;
    if (i > 9) i = 9;
    return k[i];
}

inline int cavalierIllusionSaveBonus()
    { return 2; }

// The good-alignment negative-hit-point window: the cavalier
// functions down to minus the 1st-level hp total, and heals
// an extra 1-4 points per week.
inline int cavalierNegativeHpWindow(
        int firstLevelHp)
    { return firstLevelHp; }

inline int cavalierGoodHealPerWeekMin()
    { return 1; }

inline int cavalierGoodHealPerWeekMax()
    { return 4; }

// ---- the chivalric code (p. 16) ----
// The pennon at 4th; the charge compulsion reads an 8-step
// preference order at full speed; alignment change is free
// before 4th (penalties after); neutral and evil lose the aura
// and the negative-hp window; evil may use poison; revocation
// makes a mere fighter - the weapons of choice survive it.
inline int cavalierPennonLevel()
    { return 4; }

inline int cavalierChargeOrderCount()
    { return 8; }

inline int cavalierAlignmentChangeFreeLevel()
    { return 4; }

inline bool cavalierEvilMayUsePoison()
    { return true; }

inline bool cavalierRevocationRetainsWoc()
    { return true; }

// ---- Cavaliers Table I, the clean cells (p. 15) ----
// The XP-to-attain ladder (the R176 lower-bound-minus-1
// convention): 0, 2500, 5000, 10000, 18500, 37000, 85000,
// 140000, 220000, 300000, 600000, 900000; 300,000 xp per level
// past the 12th; Cavalier Commander at 13th and above; 3 hp per
// level after the 10th.
inline int cavalierXpToAttain(int level) {
    static const int k[12] = {
        0, 2500, 5000, 10000, 18500, 37000,
        85000, 140000, 220000, 300000, 600000,
        900000
    };
    if (level < 1) return 0;
    if (level > 12) return 900000;
    return k[level - 1];
}

inline int cavalierXpPerLevelPast12()
    { return 300000; }

inline int cavalierCommanderLevel()
    { return 13; }

inline int cavalierHpPerLevelPast10()
    { return 3; }

// The level titles - the known cells only. Levels 5 and 6
// (the grid prints Knight 5; the retainer prose says becoming
// a Knight at 6th - the conflict documented here) and 11 and
// 12 (mangled cells) are OCR-lost: they return the empty
// string and stay open with the Cavaliers Table I item.
inline const char* cavalierTitleKnown(int level) {
    switch (level) {
        case 1: return "Armiger";
        case 2: return "Scutifer";
        case 3: return "Esquire";
        case 4: return "Knight Errant";
        case 7: return "Grand Knight";
        case 8: return "Banneret";
        case 9: return "Chevalier";
        case 10: return "Cavalier";
        default:
            if (level >= 13)
                return "Cavalier Commander";
            return "";   // levels 5, 6, 11, 12:
                         // the OCR-lost cells
    }
}

}   // namespace rules