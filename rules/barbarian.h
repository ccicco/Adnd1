// ===========================================================================
// Adnd1 - rules/barbarian.h
// The UA barbarian class (pp. 18-21) pins (R332).
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
// The registry rows and the creation-flow gates ride their own rounds.
// The d12 hit die rides the R327 pin (rules/classtables.h); the
// weapon specialization exclusion rides the R331 pin (the gate
// returns false for the barbarian).
//
// OCR holes documented in-header: the forward running-leap formula
// inside the 16-21 foot range is lost (the range survives); the
// detestation award tail after the XP-award clause is garbled (the
// award's existence is pinned as a bool, not a formula). The horde
// and the level-actions summary (pp. 20-21) ride their own rounds.
// ===========================================================================

#pragma once

#include "character.h"  // the Ability enum

namespace rules {

// ---- the requirements (p. 18) ----
// STR and CON 15, DEX 14; WIS capped at 16; no prime requisite
// (so no XP bonus); no dual-classing.
inline int barbarianMinAbility(int a) {
    switch (a) {
        case ABILITY_STR:
        case ABILITY_CON:
            return 15;
        case ABILITY_DEX:
            return 14;
        default:
            return 0;   // no minimum on the rest
    }
}

inline int barbarianMaxWisdom()
    { return 16; }

inline bool barbarianNoPrimeRequisite()
    { return true; }

inline bool barbarianDualClassBanned()
    { return true; }

inline bool barbarianHumanOnly()
    { return true; }

// ---- the AC and hit-point reads (p. 18) ----
// +2 AC steps per DEX point over 14 (non-bulky armor), replacing the
// defensive adjustment; +1 per point in fairly bulky or bulky armor;
// the reaction/attacking adjustment stays. CON grants +2 hp per
// point over 14.
inline int barbarianAcBonusPerDexPoint()
    { return 2; }

inline int barbarianAcStepSize()
    { return 1; }

inline int barbarianAcBulkyBonusPerPoint()
    { return 1; }

inline int barbarianConHpBonusPerPoint()
    { return 2; }

// ---- the combat reads (p. 18) ----
// d12 hit dice, 15" move, the fighter combat tables, any weapon,
// shield and armor; the hand axe, knife and spear are required.
inline int barbarianHitDice()
    { return 12; }

inline int barbarianMoveRate()
    { return 15; }

inline int barbarianRequiredWeaponCount()
    { return 3; }

inline const char* barbarianRequiredWeaponName(int i) {
    static const char* const k[3] = {
        "Hand Axe", "Knife", "Spear"
    };
    if (i < 0) i = 0;
    if (i > 2) i = 2;
    return k[i];
}

// ---- Barbarians Table I (p. 19) ----
// The XP-to-attain ladder (the R176 lower-bound-minus-one
// convention), 11 levels, 500000 xp per level past the 11th,
// +4 hp per level after the 8th (8+4, 8+8, 8+12).
inline int barbarianXpToAttain(int level) {
    static const int k[11] = {
        0, 6000, 12000, 24000, 48000,
        80000, 150000, 275000, 500000,
        1000000, 1500000
    };
    if (level < 1) return 0;
    if (level > 11) return 1500000;
    return k[level - 1];
}

inline int barbarianXpPerLevelPast11()
    { return 500000; }

inline int barbarianHpPerLevelPast8()
    { return 4; }

// ---- the magic detestation (p. 19) ----
// Barbarians detest magic and its users, refuse to employ any magic
// item, and (the garbled award tail) earn an XP award for destroying
// magic items - the award's existence is pinned; its formula is
// OCR-lost. The shaman-cleric exception holds at low level;
// high-level clerical spells grow suspect.
inline bool barbarianDetestsMagic()
    { return true; }

inline bool barbarianRefusesMagicItems()
    { return true; }

inline bool barbarianXpAwardForDestroying()
    { return true; }

inline bool barbarianShamanException()
    { return true; }

// ---- the natural attack progression (p. 19) ----
// The level at which a given weapon-plus can be struck: +1 at 4th,
// +2 at 6th, +3 at 8th, +4 at 10th, +5 at 12th. No "to hit" or
// damage bonus rides this - only the ability to affect the
// creature.
inline int barbarianStrikeLevel(int plus) {
    if (plus < 1) plus = 1;
    if (plus > 5) plus = 5;
    static const int k[5] = {4, 6, 8, 10, 12};
    return k[plus - 1];
}

inline int barbarianStrikePlus(int level) {
    if (level < 4) return 0;
    if (level < 6) return 1;
    if (level < 8) return 2;
    if (level < 10) return 3;
    if (level < 12) return 4;
    return 5;
}

inline bool barbarianStrikeGivesNoBonus()
    { return true; }

// ---- the saves (p. 19) ----
// +4 versus poison; +3 versus paralyzation, death magic,
// petrification and polymorph; +2 versus rod, staff and wand and
// breath weapon; versus spell, +1 per four levels.
inline int barbarianSaveBonusPoison()
    { return 4; }

inline int barbarianSaveBonusParalysis()
    { return 3; }

inline int barbarianSaveBonusRodWandBreath()
    { return 2; }

inline int barbarianSpellSavePerLevels()
    { return 4; }

inline int barbarianSpellSaveBonusPerStep()
    { return 1; }

// ---- the primary abilities (p. 20) ----
// Climb walls as a thief of the same level; hide in familiar
// natural surroundings as a thief 3 levels higher (unfamiliar:
// the same level); surprise 3 in 6 (4 in 6 familiar); surprised
// 10% (5% familiar); the rear attack detected and countered 5% per
// level, else it becomes a normal attack; the leaps - 10 feet
// forward, 3 backward, 3 upward from a stand; the forward running
// leap spans 16-21 feet (the formula inside the range is OCR-lost);
// the springing upward leap spans 4-7 feet; detect illusion 5% per
// level (never over 75%) after one round of concentration; detect
// magic 25% base +5% per level, capped at 90%, illusion excluded,
// type never revealed; leadership: the level added to charisma
// against other barbarians (comeliness unaffected); familiar
// terrain demands about a month of exposure.
inline int barbarianClimbAsThiefLevel(int level)
    { return level; }

inline int barbarianHideBonusLevels()
    { return 3; }

inline int barbarianSurpriseFamiliar()
    { return 4; }

inline int barbarianSurpriseUnfamiliar()
    { return 3; }

inline int barbarianSurprisedFamiliar()
    { return 5; }

inline int barbarianSurprisedUnfamiliar()
    { return 10; }

inline int barbarianBackProtectPercent(int level)
    { return 5 * level; }

inline int barbarianLeapStandingForward()
    { return 10; }

inline int barbarianLeapStandingBackward()
    { return 3; }

inline int barbarianLeapStandingUpward()
    { return 3; }

inline int barbarianLeapRunningLow()
    { return 16; }

inline int barbarianLeapRunningHigh()
    { return 21; }

inline int barbarianSpringUpwardLow()
    { return 4; }

inline int barbarianSpringUpwardHigh()
    { return 7; }

inline int barbarianDetectIllusionPercent(int level) {
    int p = 5 * level;
    return p > 75 ? 75 : p;
}

inline int barbarianDetectIllusionCap()
    { return 75; }

inline int barbarianDetectMagicBase()
    { return 25; }

inline int barbarianDetectMagicPerLevel()
    { return 5; }

inline int barbarianDetectMagicCap()
    { return 90; }

inline int barbarianDetectRounds()
    { return 1; }

inline bool barbarianLeadershipOnBarbarians()
    { return true; }

// ---- the secondary abilities (p. 20) ----
// Locale adaptation after about a month; first aid: the bound
// character regains 1 hit point immediately, 2 per day resting,
// 1 per day even active; the same first aid restores 1 hit point
// immediately to other characters; a 10% chance of curing natural
// poison or illness, rising to 50 plus the victim's CON when the
// poison or disease is known; outdoor craft as a 3rd-level druid;
// tracking as a ranger of the same level, outdoors only.
inline int barbarianLocaleAdaptWeeks()
    { return 4; }

inline int barbarianFirstAidHp()
    { return 1; }

inline int barbarianFirstAidRestPerDay()
    { return 2; }

inline int barbarianFirstAidActivePerDay()
    { return 1; }

inline int barbarianFirstAidOtherHp()
    { return 1; }

inline int barbarianFirstAidCurePercent()
    { return 10; }

inline int barbarianFirstAidCureKnownBase()
    { return 50; }

inline int barbarianFirstAidCureKnownCon()
    { return 1; }

inline int barbarianOutdoorCraftDruidLevel()
    { return 3; }

inline bool barbarianTracksAsRanger()
    { return true; }

// ---- the tertiary skills (p. 20) ----
// One or more of seven, per the locale and the culture: animal
// handling (usually dogs), horsemanship (combat use), long-distance
// signaling (drums, smoke, mirror flashes), running (double move
// for three full days), small craft paddled and rowed, sound
// imitation, snare building (deadfalls, pits and traps for large
// and very large animals).
inline int barbarianTertiaryCount()
    { return 7; }

inline const char* barbarianTertiaryName(int i) {
    static const char* const k[7] = {
        "Animal Handling", "Horsemanship",
        "Long-Distance Signaling", "Running",
        "Small Craft (Paddled and Rowed)",
        "Sound Imitation", "Snare Building"
    };
    if (i < 0) i = 0;
    if (i > 6) i = 6;
    return k[i];
}

}   // namespace rules