// ============================================================================
// Adnd1 - abilities/abilities.cpp
// PHB thief skill tables and ability checks.
// ============================================================================

#include "abilities.h"

namespace abilities {

// ----------------------------------------------------------------------------
// Thief skill table (PHB p.28), levels 1-12.
// NOTE (rebuild): verify line-by-line when the PHB PDF is re-uploaded
// (verification debt - printed table wins).
// ----------------------------------------------------------------------------

static const int kSkillRows = 12;
static const int kThiefSkills[kSkillRows][SKILL_COUNT] = {
    /* L1  */ { 30, 25, 20, 15, 10, 10, 85,  0 },
    /* L2  */ { 35, 29, 25, 21, 15, 10, 86,  0 },
    /* L3  */ { 40, 33, 30, 27, 20, 15, 87,  0 },
    /* L4  */ { 45, 37, 35, 33, 25, 15, 88, 25 },
    /* L5  */ { 50, 42, 40, 39, 31, 20, 90, 30 },
    /* L6  */ { 55, 47, 45, 45, 37, 20, 91, 35 },
    /* L7  */ { 60, 52, 50, 51, 43, 25, 92, 40 },
    /* L8  */ { 65, 57, 55, 57, 49, 25, 93, 45 },
    /* L9  */ { 70, 62, 60, 63, 56, 30, 94, 50 },
    /* L10 */ { 80, 67, 65, 70, 63, 30, 95, 55 },
    /* L11 */ { 90, 72, 70, 77, 70, 35, 96, 60 },
    /* L12 */ { 99, 77, 75, 84, 77, 35, 97, 65 },
};

static const char* const kSkillNames[SKILL_COUNT] = {
    "Pick Pockets", "Open Locks", "Find Traps", "Move Silently",
    "Hide in Shadows", "Hear Noise", "Climb Walls", "Read Languages"
};

const char* thiefSkillName(ThiefSkill s) {
    return kSkillNames[(int)s];
}

int thiefSkillBase(ThiefSkill skill, int level) {
    if (skill < 0 || skill >= SKILL_COUNT) return 0;
    if (level < 1) level = 1;
    if (level > kSkillRows) level = kSkillRows;   // L12 row repeats
    return kThiefSkills[level - 1][skill];
}

bool attemptThiefSkill(Dice& dice, ThiefSkill skill, int level,
                       int dexAdj, int armorPenalty) {
    int chance = thiefSkillBase(skill, level) + dexAdj + armorPenalty;
    if (chance < 5)   chance = 5;    // always a faint chance
    if (chance > 99)  chance = 99;   // never a sure thing
    return (int)dice.d100() <= chance;
}

int backstabMultiplier(int thiefLevel) {
    if (thiefLevel <= 4)  return 2;
    if (thiefLevel <= 8)  return 3;
    if (thiefLevel <= 12) return 4;
    return 5;
}

// R118: listening at doors (DMG p.60) - the
// book's racial d20 table (R11's d6-band
// approximation retired; no callers existed,
// so the reshape is free)
int raceListenIn20(ListenRace race) {
    // the book's table: chance of hearing noise,
    // in 20 (dwarf, elf, gnome, half-elf,
    // halfling, half-orc, human)
    static const int kChance[LISTEN_RACE_COUNT] = {
        2, 3, 4, 2, 3, 3, 2
    };
    if (race < 0 || race >= LISTEN_RACE_COUNT)
        return kChance[LISTEN_HUMAN];   // unknown -> human band
    return kChance[race];
}

int listenChanceIn20(ListenRace race, int keenIn20) {
    int chance = raceListenIn20(race) + keenIn20;
    if (chance < 0)  chance = 0;
    if (chance > 20) chance = 20;
    return chance;
}

int thiefListenIn20(int thiefLevel, int keenIn20) {
    // thieves ride their hear-noise skill (PHB):
    // percent / 5 = in-20 bands (documented
    // derivation; the PHB table's verification-
    // debt NOTE rides)
    int chance = thiefSkillBase(SKILL_HEAR_NOISE, thiefLevel) / 5
               + keenIn20;
    if (chance < 0)  chance = 0;
    if (chance > 20) chance = 20;
    return chance;
}

bool listenAtDoor(Dice& dice, int chanceIn20) {
    if (chanceIn20 <= 0) return false;
    if (chanceIn20 >= 20) return true;
    return (int)dice.d20() <= chanceIn20;
}

int bestListenIn20(bool hasThief, int thiefLevel) {
    // R120: the best ear leads - a thief's
    // hear-noise skill, else the human band
    if (hasThief) return thiefListenIn20(thiefLevel, 0);
    return listenChanceIn20(LISTEN_HUMAN, 0);
}

int climbChancePct(bool isThief, int thiefLevel) {
    if (isThief) return thiefSkillBase(SKILL_CLIMB_WALLS, thiefLevel);
    return 40;   // sheer surface, non-thief (DMG)
}

bool canUseScroll(int classIndex, int level) {
    if (classIndex == 1) return true;                 // MU: any level
    if (classIndex == 3 && level >= 10) return true;  // thief L10+
    return false;
}

bool fighterFollowersAt(int level)  { return level >= 9; }
bool clericStrongholdAt(int level)  { return level >= 8; }

} // namespace abilities