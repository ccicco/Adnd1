// ============================================================================
// Adnd1 - rules/bard.h
// The bard, PHB Appendix II (R186).
//
// Bards Table I (23 levels, bard XP only), Bards
// Table II (colleges, language gains, charm and
// legend lore percents, every cell), the
// progression gates, the ability minimums, the
// race and alignment pins, Bards Table III,
// the combat/thief/saves wiring, the poetics
// layers, the henchmen ladder and the musical
// item bonuses.
//
// JUDGMENTs:
//   - the Table I row-20 lower bound pins as
//     1,800,001: the sequence 1.4 / 1.6 / 1.8 /
//     2.0 million is strictly increasing, and
//     the OCR of the upload shows 1,000,001
//     which would fall below the 19th row; the
//     print boundary is 1,800,001.
//   - the Table I hit dice column (6-sided dice
//     for accumulated hit points) pins as the
//     count of BARD d6s: 0 at 1st (the asterisk:
//     the fighter dice - and thief dice if the
//     thief level exceeds the fighter level -
//     are retained), 1 through 10 at 2nd-11th,
//     then 10+1 through 10+12 at 12th-23rd.
//   - the bard casts druid spells as a druid of
//     the same level, never beyond 12th-level
//     druid ability until the 23rd, which casts
//     at 13th. Bards can read druid scrolls.
//   - Table III: leather or magical chainmail
//     only, no shield; the nine permitted
//     weapons (the sword covers bastard, broad,
//     long and short); oil yes; poison never
//     (except by neutral evil bards).
//   - a bard always engages in combat at the
//     fighter level attained, functions as a
//     thief of the level previously attained,
//     and saves on the most favorable table
//     with the bard level read as a druid. The
//     stringed instrument requirement, the
//     stronghold-at-23rd rule and the college
//     snobbery (Magna Alumnae aid any bard)
//     are recorded as comments.
//   - poetics: morale +10% and attack +1, both
//     requiring 2 rounds, lasting 1 complete
//     turn; 1 round does neither.
//   - the alignment pin (always neutral) is a
//     constant; the engine alignment graph
//     round consumes it.
//
// DATA-DRIVEN (the standing scope).
// ============================================================================

#pragma once

#include <cstdint>
#include <string>

namespace rules {

// ---- the gates ----

// R235: named enum constants (was static const
// ints) so the audit_eval seam reads the same
// values (the R233 McBits convention).
enum BardPins {
    BARD_LEVEL_COUNT = 23,
    BARD_PRIME_MIN = 15,   // STR WIS DEX CHA
    BARD_INT_MIN = 12,
    BARD_CON_MIN = 10,
};

// True when the six ability scores meet the
// printed minimums (STR WIS DEX CHA 15+,
// INT 12, CON 10).
inline bool bardAbilityGate(int str, int wis,
                          int dex, int cha,
                          int int_, int con) {
    return str >= BARD_PRIME_MIN
           && wis >= BARD_PRIME_MIN
           && dex >= BARD_PRIME_MIN
           && cha >= BARD_PRIME_MIN
           && int_ >= BARD_INT_MIN
           && con >= BARD_CON_MIN;
}

// Human or half-elf only (the CharRace
// order: human 0, half-elf 4).
inline bool bardRaceAllowed(int race) {
    return race == 0 || race == 4;
}

// The fighter gate: exclusively fighter
// until at least 5th, and in any event the
// change to thief comes before 8th.
inline bool bardFighterWindow(int fighterLevel) {
    return fighterLevel >= 5 && fighterLevel <= 7;
}

// The thief gate: leave off thieving
// sometime between 5th and 9th level of
// ability and begin the druid studies.
inline bool bardThiefWindow(int thiefLevel) {
    return thiefLevel >= 5 && thiefLevel <= 9;
}

// Always neutral (chaotic, evil, good or
// lawful neutral permitted).
inline bool bardNeutralOnly() {
    return true;
}

// ---- Bards Table I ----

// The bard XP threshold of level (bard XP
// only; previously earned XP is not
// considered). Level clamps to 1-23.
inline int bardXpForLevel(int level) {
    static const int kXp[23] = {
        0,
        2001,
        4001,
        8001,
        16001,
        25001,
        40001,
        60001,
        85001,
        110001,
        150001,
        200001,
        400001,
        600001,
        800001,
        1000001,
        1200001,
        1400001,
        1600001,
        1800001,
        2000001,
        2200001,
        3000001,
    };
    if (level < 1) level = 1;
    if (level > 23) level = 23;
    return kXp[level - 1];
}

// The level titles (Rhymer through M.
// Bard 23rd).
inline const char* bardTitle(int level) {
    static const char* const kTitles[23] = {
        "Rhymer",
        "Lyrist",
        "Sonnateer",
        "Skald",
        "Racaraide",
        "Joungleur",
        "Troubador",
        "Minstrel",
        "Muse",
        "Lorist",
        "Bard",
        "Master Bard",
        "M. Bard 13th",
        "M. Bard 14th",
        "M. Bard 15th",
        "M. Bard 16th",
        "M. Bard 17th",
        "M. Bard 18th",
        "M. Bard 19th",
        "M. Bard 20th",
        "M. Bard 21st",
        "M. Bard 22nd",
        "M. Bard 23rd",
    };
    if (level < 1) level = 1;
    if (level > 23) level = 23;
    return kTitles[level - 1];
}

// The accumulated bard hit dice: 0 at 1st
// (the fighter dice - plus thief dice if
// the thief level exceeds the fighter
// level - are retained), then d6 per bard
// level through 10, then +1 per level past
// the 11th (10+1 ... 10+12).
inline int bardHitDice(int level) {
    if (level < 1) return 0;
    if (level > 23) level = 23;
    int dice = level - 1;
    if (dice > 10) dice = 10;
    if (level > 11) dice += level - 11;
    return dice;
}

// The druid spell slots of spellLevel
// (1-5) at bard level. Dashes pin as 0.
inline int bardDruidSlots(int level, int spellLevel) {
    static const int kSlots[23][5] = {
        { 1, 0, 0, 0, 0 },
        { 2, 0, 0, 0, 0 },
        { 3, 0, 0, 0, 0 },
        { 3, 1, 0, 0, 0 },
        { 3, 2, 0, 0, 0 },
        { 3, 3, 0, 0, 0 },
        { 3, 3, 1, 0, 0 },
        { 3, 3, 2, 0, 0 },
        { 3, 3, 3, 0, 0 },
        { 3, 3, 3, 1, 0 },
        { 3, 3, 3, 2, 0 },
        { 3, 3, 3, 3, 0 },
        { 3, 3, 3, 3, 1 },
        { 3, 3, 3, 3, 2 },
        { 3, 3, 3, 3, 3 },
        { 4, 3, 3, 3, 3 },
        { 4, 4, 3, 3, 3 },
        { 4, 4, 4, 3, 3 },
        { 5, 4, 4, 4, 3 },
        { 5, 4, 4, 4, 4 },
        { 5, 5, 4, 4, 4 },
        { 5, 5, 5, 4, 4 },
        { 5, 5, 5, 5, 5 },
    };
    if (level < 1) return 0;
    if (level > 23) level = 23;
    if (spellLevel < 1) spellLevel = 1;
    if (spellLevel > 5) spellLevel = 5;
    return kSlots[level - 1][spellLevel - 1];
}

// The druid ability the bard casts at:
// the same level, capped at 12th-level
// druid ability until the 23rd, which
// casts at 13th.
inline int bardDruidCastLevel(int level) {
    if (level < 1) return 0;
    if (level >= 23) return 13;
    if (level > 12) return 12;
    return level;
}

// ---- Bards Table II ----

// The college of the level (Probationer
// through Magna Alumnae).
inline const char* bardCollege(int level) {
    static const char* const kCollege[23] = {
        "Probationer",
        "Fochlucan",
        "Fochlucan",
        "Fochlucan",
        "Mac-Fuirmidh",
        "Mac-Fuirmidh",
        "Mac-Fuirmidh",
        "Doss",
        "Doss",
        "Doss",
        "Canaith",
        "Canaith",
        "Canaith",
        "Cli",
        "Cli",
        "Cli",
        "Anstruth",
        "Anstruth",
        "Anstruth",
        "Ollamh",
        "Ollamh",
        "Ollamh",
        "Magna Alumnae",
    };
    if (level < 1) level = 1;
    if (level > 23) level = 23;
    return kCollege[level - 1];
}

// The new languages gained upon achieving
// the level (no study required).
inline int bardLanguages(int level) {
    static const int kLang[23] = {
        0,
        0,
        0,
        1,
        0,
        1,
        1,
        0,
        1,
        1,
        0,
        1,
        1,
        0,
        1,
        1,
        0,
        1,
        1,
        1,
        1,
        1,
        1,
    };
    if (level < 1) return 0;
    if (level > 23) level = 23;
    return kLang[level - 1];
}

// The charm percentage: the chance of
// successfully casting a charm person (or
// charm monster) spell with music. Does
// not negate immunities or the save.
inline int bardCharmPercent(int level) {
    static const int kCharm[23] = {
        15,
        20,
        22,
        24,
        30,
        32,
        34,
        40,
        42,
        44,
        50,
        53,
        56,
        60,
        63,
        66,
        70,
        73,
        76,
        80,
        84,
        88,
        95,
    };
    if (level < 1) return 0;
    if (level > 23) level = 23;
    return kCharm[level - 1];
}

// The legend lore and item knowledge
// percentage (weapons, armor, potions,
// scrolls and employed or inscribed items).
inline int bardLegendLorePercent(int level) {
    static const int kLore[23] = {
        0,
        5,
        7,
        10,
        13,
        16,
        20,
        25,
        30,
        35,
        50,
        53,
        56,
        55,
        60,
        65,
        70,
        75,
        80,
        85,
        90,
        95,
        99,
    };
    if (level < 1) return 0;
    if (level > 23) level = 23;
    return kLore[level - 1];
}

// ---- Bards Table III and the wiring ----

// The nine permitted weapons (the sword
// covers bastard, broad, long, short;
// magical weapons of the named types
// included). Matching is lowercase name
// equality.
inline int bardWeaponCount() { return 9; }

inline const char* bardWeaponName(int i) {
    static const char* const kNames[9] = {
        "club",
        "dagger",
        "dart",
        "javelin",
        "sling",
        "scimitar",
        "spear",
        "staff",
        "sword",
    };
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    return kNames[i];
}

// True when the lowercase weapon name is
// permitted to a bard.
inline bool bardWeaponAllowed(const char* name) {
    if (!name) return false;
    for (int i = 0; i < 9; ++i)
        if (std::string(name) == bardWeaponName(i))
            return true;
    return false;
}

// The armor pin: leather or magical
// chainmail only, never a shield.
enum BardArmor : int {
    BARD_ARMOR_LEATHER_OR_CHAINMAIL = 0
};

inline bool bardShieldAllowed() { return false; }

// Oil is permitted; poison never (except
// by neutral evil bards).
inline bool bardOilAllowed() { return true; }

inline bool bardPoisonAllowed(bool neutralEvil) {
    return neutralEvil;
}

// ---- the R235 career seam (pure expressions -
// the evaluable-subset convention) ----

// The career gate: the druid studies open to a
// fighter-turned-thief inside BOTH printed
// windows (fighter 5th-7th, then thief 5th-9th).
inline bool bardCareerGate(int fighterLevel,
                            int thiefLevel) {
    return bardFighterWindow(fighterLevel)
           && bardThiefWindow(thiefLevel);
}

// The wiring: combat at the fighter level
// attained, thief functions at the thief
// level previously attained, saves on the
// most favorable table with the bard level
// read as a druid (consumed by the engine
// save rounds).

// ---- the poetics layers ----

static const int BARD_POETIC_ROUNDS = 2;
static const int BARD_POETIC_TURN = 1;   // lasts 1 complete turn
static const int BARD_MORALE_BONUS = 10; // percent
static const int BARD_HIT_BONUS = 1;     // ferocity in attack

// ---- the henchmen ladder ----

// 1 henchman at 5th, 2 at 8th, 3 at 11th,
// 4 at 14th, 5 at 17th, 6 at 20th, any
// number at 23rd; subject to charisma.
// Henchmen are druids, fighters or thieves
// of human, half-elven or elven race; a
// bard never serves as a henchman longer
// than 1-4 months; only 23rd-level bards
// construct strongholds.
inline int bardHenchmen(int level) {
    static const int kHench[24] = {
        0,
        0,
        0,
        0,
        0,
        1,
        1,
        1,
        2,
        2,
        2,
        3,
        3,
        3,
        4,
        4,
        4,
        5,
        5,
        5,
        6,
        6,
        6,
        999,   // any number at 23rd
    };
    if (level < 0) return 0;
    if (level > 23) level = 23;
    return kHench[level];
}

// ---- the musical item bonuses ----

// Miscellaneous musical magic is superior
// when employed by a bard: Drums of Panic
// save at -1, Horn of Blasting 50% greater
// damage, Lyre of Building double effects,
// Pipes of the Sewer double the rats in
// half the usual time.
inline int bardDrumsOfPanicSaveMod() { return -1; }

inline int bardHornOfBlastingDamageFactorPercent() {
    return 150;
}

inline int bardLyreOfBuildingFactor() { return 2; }

inline int bardPipesOfSewerRatFactor() { return 2; }

} // namespace rules
