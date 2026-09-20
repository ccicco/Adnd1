// ============================================================================
// Adnd1 — abilities/abilities.cpp
// PHB thief skill tables and ability checks.
// ============================================================================

#include "abilities.h"

namespace abilities {

// ----------------------------------------------------------------------------
// Thief skill table (PHB p.28), levels 1-12.
// NOTE (rebuild): verify line-by-line when the PHB PDF is re-uploaded
// (verification debt — printed table wins).
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

bool listenAtDoor(Dice& dice, int chanceIn6) {
    if (chanceIn6 <= 0) return false;
    if (chanceIn6 >= 6) return true;
    return (int)dice.d6() <= chanceIn6;
}

int listenChanceIn6(bool stoneDoor, bool isThief, int thiefLevel) {
    if (isThief) {
        // thieves substitute their hear-noise percent — handled by
        // the caller with attemptThiefSkill; here map to a d6 band
        (void)thiefLevel;
        return 3;
    }
    if (stoneDoor) return 1;   // 1-in-10 approximated as worst band
    return 2;                  // 1-2 on d6
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