// ============================================================================
// Adnd1 - rules/subclassspecials.h
// The per-subclass specials (R187): the assassin
// fees and disguise layer, the monk special
// abilities, backstab, the thief-skill sharing,
// plus the ranger surprise numbers and the
// paladin turn-undead ladder (the R184 records).
//
// JUDGMENTs:
//   - the fee table dashes pin as 0 (no fee
//     listed = the band is out of reach for that
//     assassin level). Important, popular and/or
//     noble victims count ABOVE their actual level
//     for fee purposes (the print footnote example:
//     a popular 4th-level town elder pays as three
//     times actual level) - recorded as comment,
//     the referee adjudicates the multiplier.
//   - the disguise chance: base 2% per day, +2%
//     per pose difference (another class, another
//     race, the opposite sex), maximum 8%; the
//     observer adjustment -1% per combined INT+WIS
//     point below 24, +1% per point above 30. The
//     result may go to 0 or negative after the
//     observer adjustment; clamp at 0 for a roll.
//   - backstab: the multiplier is 1 + one per four
//     experience levels (double 1-4, triple 5-8,
//     quadruple 9-12, quintuple 13-16, clamped at
//     quintuple past 16th); the hit bonus is +20%
//     (+4 on the to-hit die). The assassin backstabs
//     at FULL assassin level; all other thieving is
//     at two levels below (a 3rd-level assassin as a
//     1st-level thief).
//   - the monk performs the six listed thief
//     abilities at IDENTICAL level. The upload OCR
//     swallowed list item 1; the visible items run
//     2-6 and the PHB prints Open Locks first.
//   - the monk surprise ladder pins 33 at 1st (the
//     print 33 1/3%), 32 at 2nd, then 36 - 2 x level,
//     floored at 0.
//   - the monk specials A-K arrive one per level
//     from 3rd (speak with animals) through 13th
//     (the quivering palm); past 13th the table
//     shows no new letters and the abilities
//     persist. ESP masking: 30% success at 4th,
//     dropping 2% per level. Catalepsy: twice the
//     monk level in turns, from 6th. Healing: d4+1
//     at 7th, +1 per level after, once per day.
//     Charm-type resistance: 50% at 9th, +5% per
//     level after. Mind blast and telepathy vs a
//     monk of 10th+ reads as 18 intelligence.
//   - the quivering palm (13th): once per week,
//     the touch within 3 melee rounds or the power
//     drains for a week; no effect on the undead or
//     creatures hit only by magical weaponry; the
//     victim may not have more hit dice than the
//     monk nor more than 200% of the monk hit
//     points; the death command within one day per
//     monk level.
//   - the open-hand stun and kill: a to-hit score
//     5+ over the needed number stuns the opponent
//     for 1-6 (d6) melee rounds; the kill percent is
//     the victim AC plus one per monk level above
//     7th (AC -1 at 7th is a negative - no chance;
//     a 9th-level monk vs AC 5 is 7%). The monk
//     must hit, stun, then roll the percent or
//     less. The to-hit is never modified by
//     strength bonuses (the R181 pin).
//   - the monk save advantages: non-magical missiles
//     are dodged or knocked aside on a save vs
//     petrification; a successful save means NO
//     damage from the attack form; from 9th a
//     FAILED save still means only half the total
//     potential damage (a basilisk gaze still
//     petrifies).
//   - the ranger surprise numbers: the ranger
//     surprises opponents on d6 1-3 (50%), and is
//     surprised only on a 1 (16 2/3%).
//   - the paladin turn ladder: from 3rd level the
//     paladin affects undead as a cleric of
//     paladin level minus two (3rd as a 1st-level
//     cleric, 4th as a 2nd, and so on); below 3rd,
//     no power. This is the wrapper over the R147
//     matrix III in combat.h (the paladin subtracts
//     two levels there).
//
// DATA-DRIVEN (the standing scope).
// ============================================================================

#pragma once

#include <cstdint>

namespace rules {

// ---- the assassin fees ----

// The victim band of the fee table: 0, 1-2,
// 3-4, 5-6, 7-9, 10-12, 13-15, 16+.
inline int assassinVictimBand(int victimLevel) {
    if (victimLevel <= 0) return 0;
    if (victimLevel <= 2) return 1;
    if (victimLevel <= 4) return 2;
    if (victimLevel <= 6) return 3;
    if (victimLevel <= 9) return 4;
    if (victimLevel <= 12) return 5;
    if (victimLevel <= 15) return 6;
    return 7;
}

// The MINIMUM FEES FOR ASSASSINATION table,
// in gold pieces: assassin levels 1-15 x
// the eight victim bands. Dashes pin as 0.
// Levels clamp to 1-15.
inline int assassinMinimumFee(int assassinLevel,
                            int victimBand) {
    static const int kFees[15][8] = {
        { 50, 100, 150, 200, 250, 0, 0, 0 },
        { 60, 120, 175, 250, 300, 350, 0, 0 },
        { 75, 150, 225, 300, 400, 500, 0, 0 },
        { 100, 200, 300, 450, 600, 750, 1000, 0 },
        { 150, 300, 450, 700, 900, 1100, 1300, 1500 },
        { 250, 500, 750, 1000, 1300, 1600, 2000, 2500 },
        { 400, 800, 1200, 1600, 2000, 2500, 3500, 4500 },
        { 600, 1200, 1800, 2400, 3000, 3750, 5000, 7500 },
        { 850, 1700, 2600, 3500, 4400, 6000, 7500, 10000 },
        { 1200, 2400, 3600, 4800, 6000, 8000, 10000, 15000 },
        { 1700, 3500, 5100, 7000, 9000, 12000, 15000, 20000 },
        { 2500, 5000, 7500, 10000, 13000, 17500, 20000, 25000 },
        { 3500, 7000, 11000, 15000, 19000, 25000, 32500, 40000 },
        { 5000, 10000, 15000, 20000, 27500, 35000, 45000, 60000 },
        { 10000, 20000, 35000, 50000, 75000, 100000, 150000, 250000 },
    };
    if (assassinLevel < 1) assassinLevel = 1;
    if (assassinLevel > 15) assassinLevel = 15;
    if (victimBand < 0) victimBand = 0;
    if (victimBand > 7) victimBand = 7;
    return kFees[assassinLevel - 1][victimBand];
}

// ---- the assassin disguise layer ----

// The chance per day of a disguised assassin
// being spotted: base 2%, +2% per pose
// difference (another class, another race, the
// opposite sex), maximum 8%; then the observer
// adjustment, -1% per combined INT+WIS point
// below 24, +1% per point above 30. The result
// may fall to 0 or below after the observer
// adjustment - clamp for a roll.
inline int assassinDisguiseSpotPercent(
        bool posesAsAnotherClass,
        bool posesAsAnotherRace,
        bool posesAsOppositeSex,
        int observerIntWisCombined) {
    int chance = 2;
    if (posesAsAnotherClass) chance += 2;
    if (posesAsAnotherRace) chance += 2;
    if (posesAsOppositeSex) chance += 2;
    if (chance > 8) chance = 8;
    if (observerIntWisCombined < 24)
        chance -= 24 - observerIntWisCombined;
    else if (observerIntWisCombined > 30)
        chance += observerIntWisCombined - 30;
    return chance;
}

// ---- backstab ----

// The backstab damage multiplier: double at
// 1-4, triple at 5-8, quadruple at 9-12,
// quintuple at 13-16, clamped at quintuple.
inline int backstabMultiplier(int level) {
    if (level < 1) level = 1;
    if (level > 16) level = 16;
    return 1 + (level + 3) / 4;
}

// Striking by surprise from behind adds +20%
// to the hit probability (+4 on the die).
inline int backstabHitBonusPercent() { return 20; }

inline int backstabHitBonusDie() { return 4; }

// ---- the thief-skill sharing ----

// The assassin performs all thieving at two
// levels below the assassin level ...
inline int assassinThiefSkillLevel(int assassinLevel) {
    if (assassinLevel < 1) return 1;
    int t = assassinLevel - 2;
    return t < 1 ? 1 : t;
}

// ... except backstabbing, which is at the
// full assassin level.
inline int assassinBackstabLevel(int assassinLevel) {
    if (assassinLevel < 1) return 1;
    return assassinLevel;
}

// The monk performs the six listed thief
// abilities at identical level.
inline int monkThiefSkillLevel(int monkLevel) {
    if (monkLevel < 1) return 1;
    return monkLevel;
}

// The six abilities the monk shares with the
// thief class (the print list; open locks is
// the numbering head the OCR swallowed).
inline int monkThiefAbilityCount() { return 6; }

inline const char* monkThiefAbilityName(int i) {
    static const char* const kNames[6] = {
        "open locks",
        "find/remove traps",
        "move silently",
        "hide in shadows",
        "hear noise",
        "climb walls",
    };
    if (i < 0) i = 0;
    if (i > 5) i = 5;
    return kNames[i];
}

// ---- R200: the falling-while-climbing ladder ----
//
// The print, right under the thief-ability paragraph: a
// monk can fall while climbing and take no damage when
// close enough to a wall. The rungs: 4th level (Disciple)
// - up to 20 feet within 1 foot of a wall; 6th (Master) -
// up to 30 feet within 4 feet; 13th (Master of Winter) - any
// distance within 8 feet. The monk must have opportunity to
// periodically make contact with the wall during the
// descent; any similar surface - tree trunk, cliff face -
// serves.
//
// The fall distance: 0 below 4th, 20 at 4th-5th, 30 at
// 6th-12th, -1 (any distance) at 13th and up.
inline int monkWallAssistedFallFeet(int level) {
    if (level < 4)  return 0;
    if (level < 6)  return 20;   // 4th-5th, within 1
    if (level < 13) return 30;   // 6th-12th, within 4
    return -1;   // 13th and up: any distance
}

// The proximity column: how close to the wall the fall
// must happen. 1 foot at 4th-5th, 4 feet at 6th-12th,
// 8 feet at 13th and up; 0 below 4th (no wall assist).
inline int monkWallAssistedFallProximityFeet(int level) {
    if (level < 4)  return 0;
    if (level < 6)  return 1;
    if (level < 13) return 4;
    return 8;
}

// The wall-contact rule: the descent is damage-free only
// when the monk can periodically touch the wall - the
// print pins it as always required for the assist.
inline bool monkWallAssistedFallRequiresContact() {
    return true;
}

// ---- the monk surprise ladder ----

// The chance of surprising the monk: 33% at
// 1st (the print 33 1/3%), 32% at 2nd, then
// down 2% per level, floored at 0.
inline int monkSurprisedPercent(int level) {
    if (level < 1) level = 1;
    if (level == 1) return 33;
    if (level == 2) return 32;
    int v = 36 - 2 * level;
    return v > 0 ? v : 0;
}

// ---- the monk specials A-K ----

// The specials ladder: one letter per level
// from 3rd (A) through 13th (K); 0 before
// 3rd, clamped at 11 letters past 13th.
inline int monkSpecialsCount(int level) {
    if (level < 3) return 0;
    if (level > 13) return 11;
    return level - 2;
}

// The letter and the level of the i-th
// special (0-based).
inline char monkSpecialLetter(int i) {
    static const char kLetters[11] = {
        'A',
        'B',
        'C',
        'D',
        'E',
        'F',
        'G',
        'H',
        'I',
        'J',
        'K',
    };
    if (i < 0) i = 0;
    if (i > 10) i = 10;
    return kLetters[i];
}

inline int monkSpecialLevel(int i) {
    static const int kLevels[11] = {
        3,
        4,
        5,
        6,
        7,
        8,
        9,
        10,
        11,
        12,
        13,
    };
    if (i < 0) i = 0;
    if (i > 10) i = 10;
    return kLevels[i];
}

// The individual specials, as ladders.

// A: speak with animals as druids do, from 3rd.
inline int monkSpeakWithAnimalsLevel() { return 3; }

// B: ESP has 30% chance at 4th, dropping 2%
// per level thereafter.
inline int monkEspSuccessPercent(int level) {
    if (level < 4) return 100;
    int v = 30 - 2 * (level - 4);
    return v > 0 ? v : 0;
}

// C: no disease of any sort, never affected
// by haste or slow, from 5th.
inline int monkDiseaseImmuneLevel() { return 5; }

// D: self-induced catalepsy, from 6th;
// maintained for twice the level in turns
// (12 turns at 6th, 14 at 7th, ...).
inline int monkCatalepsyTurns(int level) {
    if (level < 6) return 0;
    return 2 * level;
}

// E: heal own damage, once per day: d4+1 at
// 7th, the bonus +1 per level thereafter
// (3-6 at 8th, 4-7 at 9th, ...).
inline int monkHealBonusPerDay(int level) {
    if (level < 7) return 0;
    return level - 6;
}

// F: speak with plants as druids do, from 8th.
inline int monkSpeakWithPlantsLevel() { return 8; }

// G: beguiling, charms, hypnosis and
// suggestion have but 50% chance at 9th,
// dropping 5% per level thereafter (45% at
// 10th, 40% at 11th, ...).
inline int monkCharmAffectPercent(int level) {
    if (level < 9) return 100;
    int v = 50 - 5 * (level - 9);
    return v > 0 ? v : 0;
}

// H: telepathic and mind blast attacks vs a
// monk of 10th or higher read as if the
// monk had 18 intelligence.
inline int monkMindBlastLevel() { return 10; }

inline int monkMindBlastEffectiveInt() { return 18; }

// I: not affected by poison of any type,
// from 11th.
inline int monkPoisonImmuneLevel() { return 11; }

// J: geas and quest spells have no effect,
// from 12th.
inline int monkGeasImmuneLevel() { return 12; }

// K: the quivering palm, from 13th. Once per
// week; the touch within 3 melee rounds or
// the power is drained for a week; no effect
// on the undead or creatures hit only by
// magical weaponry; the victim may not have
// more hit dice than the monk, nor more than
// 200% of the monk hit points; the death
// command within one day per monk level.
inline int monkQuiveringPalmLevel() { return 13; }

inline int monkQuiveringPalmAttemptsPerWeek() { return 1; }

inline int monkQuiveringPalmTouchRounds() { return 3; }

inline int monkQuiveringPalmHpCapPercent() { return 200; }

// ---- the open-hand stun and kill ----

// A to-hit die score exceeding the minimum
// needed by 5 or more stuns the opponent.
inline int monkStunMargin() { return 5; }

// A stunned opponent is out for 1-6 (d6)
// melee rounds.
inline int monkStunRoundsDie() { return 6; }

// The kill percent: the victim armor class
// modified by one percent per monk level
// above 7th (AC -1 at 7th is negative - no
// chance; a 9th-level monk vs AC 5 is 7%).
inline int monkKillPercent(int victimAc, int monkLevel) {
    int over = monkLevel > 7 ? monkLevel - 7 : 0;
    return victimAc + over;
}

// ---- the monk save advantages ----

// Non-magical missiles are dodged or knocked
// aside on a successful save vs petrification;
// a successful save means NO damage from the
// attack form. From 9th, a FAILED save still
// means but half the total potential damage
// (a basilisk gaze still petrifies).
inline int monkHalfDamageOnFailedSaveLevel() { return 9; }

// ---- the ranger surprise numbers (the R184 records) ----

// The ranger surprises opponents 50% of the
// time (d6 1-3) ...
inline int rangerSurpriseOnD6(int roll) {
    return roll >= 1 && roll <= 3;
}

// ... and is surprised only 16 2/3% of the
// time (d6 1).
inline int rangerSurprisedOnD6(int roll) {
    return roll == 1;
}

// ---- the paladin turn-undead ladder (the R184 records) ----

// From 3rd level the paladin affects undead
// as a cleric of paladin level minus two (3rd
// as a 1st-level cleric, 4th as a 2nd, and so
// on, upward with each level). Below 3rd: 0 -
// no power. This wraps the R147 matrix III
// (combat.h: the paladin subtracts two levels).
inline int paladinTurnClericLevel(int paladinLevel) {
    if (paladinLevel < 3) return 0;
    return paladinLevel - 2;
}

} // namespace rules
