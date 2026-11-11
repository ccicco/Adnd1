#include "races.h"

#include <cstring>

namespace rules {

const char* raceName(CharRace r) {
    static const char* N[RACE_CHAR_COUNT] = {
        "human", "dwarf", "elf", "gnome",
        "half-elf", "halfling", "half-orc"
    };
    if (r < 0 || r >= RACE_CHAR_COUNT) return N[0];
    return N[r];
}

int raceAbilityAdj(CharRace r, Ability a) {
    if (r == RACE_DWARF) {
        if (a == ABILITY_CON) return 1;
        if (a == ABILITY_CHA) return -1;
        return 0;
    }
    if (r == RACE_ELF) {
        if (a == ABILITY_DEX) return 1;
        if (a == ABILITY_CON) return -1;
        return 0;
    }
    if (r == RACE_HALF_ORC) {
        if (a == ABILITY_STR) return 1;
        if (a == ABILITY_CON) return 1;
        if (a == ABILITY_CHA) return -2;
        return 0;
    }
    if (r == RACE_HALFLING) {
        if (a == ABILITY_STR) return -1;
        if (a == ABILITY_DEX) return 1;
        return 0;
    }
    return 0;   // gnome, half-elf, human
}

// Table III: [race][ability][0 = male, 1 = female].
// The printed minimums are identical for males and females
// (every min column prints the same value twice); the
// maximums differ only where the print shows M/F rows.
static const int kMin[RACE_CHAR_COUNT][ABILITY_COUNT][2] = {
    // human
    { { 3, 3}, { 3, 3}, { 3, 3}, { 3, 3}, { 3, 3}, { 3, 3} },
    // dwarf
    { { 8, 8}, { 3, 3}, { 3, 3}, { 3, 3}, {12,12}, { 3, 3} },
    // elf
    { { 3, 3}, { 8, 8}, { 3, 3}, { 7, 7}, { 6, 6}, { 8, 8} },
    // gnome
    { { 6, 6}, { 7, 7}, { 3, 3}, { 3, 3}, { 8, 8}, { 3, 3} },
    // half-elf
    { { 3, 3}, { 4, 4}, { 3, 3}, { 6, 6}, { 6, 6}, { 3, 3} },
    // halfling
    { { 6, 6}, { 6, 6}, { 3, 3}, { 8, 8}, {10,10}, { 3, 3} },
    // half-orc
    { { 6, 6}, { 3, 3}, { 3, 3}, { 3, 3}, {13,13}, { 3, 3} },
};
static const int kMax[RACE_CHAR_COUNT][ABILITY_COUNT][2] = {
    // human
    { {18,18}, {18,18}, {18,18}, {18,18}, {18,18}, {18,18} },
    // dwarf
    { {18,17}, {18,18}, {18,18}, {17,17}, {19,19}, {16,16} },
    // elf
    { {18,16}, {18,18}, {18,18}, {19,19}, {18,18}, {18,18} },
    // gnome
    { {18,15}, {18,18}, {18,18}, {18,18}, {18,18}, {18,18} },
    // half-elf
    { {18,17}, {18,18}, {18,18}, {18,18}, {18,18}, {18,18} },
    // halfling
    { {17,14}, {18,18}, {17,17}, {18,18}, {19,19}, {18,18} },
    // half-orc
    { {18,18}, {17,17}, {14,14}, {17,17}, {19,19}, {12,12} },
};

static void clampRaceIndex(CharRace& r) {
    if (r < 0 || r >= RACE_CHAR_COUNT) r = RACE_HUMAN;
}

int raceAbilityMin(CharRace r, Ability a, bool female) {
    clampRaceIndex(r);
    if (a < 0 || a >= ABILITY_COUNT) a = ABILITY_STR;
    return kMin[r][a][female ? 1 : 0];
}

int raceAbilityMax(CharRace r, Ability a, bool female) {
    clampRaceIndex(r);
    if (a < 0 || a >= ABILITY_COUNT) a = ABILITY_STR;
    return kMax[r][a][female ? 1 : 0];
}

void applyRacialAdjustments(AbilityScores& s, CharRace r,
                            bool female) {
    clampRaceIndex(r);
    for (int i = 0; i < ABILITY_COUNT; ++i) {
        Ability a = (Ability)i;
        int v = s.get(a) + raceAbilityAdj(r, a);
        int mx = raceAbilityMax(r, a, female);
        if (v > mx) v = mx;
        s.set(a, (uint8_t)v);
    }
}

bool raceMeetsMinimums(const AbilityScores& s, CharRace r,
                       bool female) {
    clampRaceIndex(r);
    for (int i = 0; i < ABILITY_COUNT; ++i) {
        Ability a = (Ability)i;
        if (s.get(a) + raceAbilityAdj(r, a)
            < raceAbilityMin(r, a, female))
            return false;
    }
    return true;
}

int raceInfravisionFeet(CharRace r) {
    switch (r) {
        case RACE_DWARF: case RACE_ELF: case RACE_GNOME:
        case RACE_HALF_ELF: case RACE_HALF_ORC:
            return 60;
        case RACE_HALFLING:
            return 30;   // the mixed-blood line (Stouts 60)
        default:
            return 0;    // human
    }
}

int raceSleepCharmResistPct(CharRace r) {
    if (r == RACE_ELF) return 90;
    if (r == RACE_HALF_ELF) return 30;
    return 0;
}

// the R147 dwarf shape: +1 per 3.5 points of CON, clamped
// 0..5 - matches every printed band (4-6 +1, 7-10 +2,
// 11-13 +3, 14-17 +4, 18 +5)
static int conSaveBonusShape(uint8_t con) {
    int b = ((int)con * 2) / 7;
    if (b < 0) b = 0;
    if (b > 5) b = 5;
    return b;
}

int raceMagicSaveBonus(CharRace r, uint8_t con) {
    if (r == RACE_DWARF || r == RACE_GNOME
        || r == RACE_HALFLING)
        return conSaveBonusShape(con);
    return 0;
}

int racePoisonSaveBonus(CharRace r, uint8_t con) {
    if (r == RACE_DWARF || r == RACE_HALFLING)
        return conSaveBonusShape(con);
    return 0;   // the gnome print names magic only
}

bool classAllowedForRace(int classIndex, CharRace r) {
    // Race Table I, the base four classes
    if (classIndex == CLASS_FIGHTER) return true;
    if (classIndex == CLASS_MAGIC_USER)
        return r == RACE_ELF || r == RACE_HALF_ELF
            || r == RACE_HUMAN;
    if (classIndex == CLASS_CLERIC)
        return r == RACE_HALF_ELF || r == RACE_HALF_ORC
            || r == RACE_HUMAN;
    if (classIndex == CLASS_THIEF) return true;
    return false;
}

int raceLevelCap(int classIndex, CharRace r, uint8_t str,
                 uint8_t int_, uint8_t dex) {
    if (!classAllowedForRace(classIndex, r)) return 0;
    if (r == RACE_HUMAN) return -1;   // no limit
    if (classIndex == CLASS_FIGHTER) {
        switch (r) {
            case RACE_DWARF:   // f1: <17: 7, 17: 8, 18: 9
                if (str >= 18) return 9;
                return str == 17 ? 8 : 7;
            case RACE_ELF:     // f2: <17: 5, 17: 6, 18: 7
                if (str >= 18) return 7;
                return str == 17 ? 6 : 5;
            case RACE_GNOME:   // f3: <18: 5, 18: 6
                return str >= 18 ? 6 : 5;
            case RACE_HALF_ELF: // f4: <17: 6, 17: 7, 18: 8
                if (str >= 18) return 8;
                return str == 17 ? 7 : 6;
            case RACE_HALFLING:
                // f5: sub-race bands - the engine takes
                // the STR ladder on the Tallfellow best
                // line (<17: 4, 17: 5, 18: 6); the
                // Stout-at-18 5 cap is sub-race narration
                if (str >= 18) return 6;
                return str == 17 ? 5 : 4;
            case RACE_HALF_ORC:
                return 10;
            default:
                return -1;
        }
    }
    if (classIndex == CLASS_MAGIC_USER) {
        if (r == RACE_ELF) {   // f6: <17 INT: 9, 17: 10
            if (int_ >= 18) return 11;
            return int_ == 17 ? 10 : 9;
        }
        if (r == RACE_HALF_ELF) {   // f7: <17: 6, 17: 7
            if (int_ >= 18) return 8;
            return int_ == 17 ? 7 : 6;
        }
        return -1;
    }
    if (classIndex == CLASS_CLERIC) {
        if (r == RACE_HALF_ELF) return 5;
        if (r == RACE_HALF_ORC) return 4;
        return -1;   // the parenthesized dwarf/elf/gnome
    }                // cleric caps are NPC-only per print
    if (classIndex == CLASS_THIEF) {
        if (r == RACE_HALF_ORC) {   // f9: <17 DEX: 6, 17: 7
            if (dex >= 18) return 8;
            return dex == 17 ? 7 : 6;
        }
        return -1;
    }
    return -1;
}

// the printed foe lists (base names, null-terminated)
static const char* const kDwarfBonusFoes[] = {
    "half-orc", "goblin", "hobgoblin", "orc", nullptr
};
static const char* const kGnomeBonusFoes[] = {
    "kobold", "goblin", nullptr
};
static const char* const kDwarfGiantKind[] = {
    "ogre", "troll", "ogre mage", "giant", "titan", nullptr
};
static const char* const kGnomeGiantKind[] = {
    "gnoll", "bugbear", "ogre", "troll", "ogre mage",
    "giant", "titan", nullptr
};

static bool nameOnList(const char* const* list,
                       const char* name) {
    if (!name) return false;
    for (int i = 0; list[i]; ++i)
        if (std::strcmp(name, list[i]) == 0) return true;
    return false;
}

int raceBonusVsFoeName(CharRace r, const char* foeName) {
    if (r == RACE_DWARF)
        return nameOnList(kDwarfBonusFoes, foeName) ? 1 : 0;
    if (r == RACE_GNOME)
        return nameOnList(kGnomeBonusFoes, foeName) ? 1 : 0;
    return 0;
}

int raceFoeAttackPenalty(CharRace r, const char* foeName) {
    if (r == RACE_DWARF)
        return nameOnList(kDwarfGiantKind, foeName) ? 4 : 0;
    if (r == RACE_GNOME)
        return nameOnList(kGnomeGiantKind, foeName) ? 4 : 0;
    return 0;
}

static const ChanceIn kDetectNone = { 0, 0 };

ChanceIn raceDetectChance(CharRace r, DetectKind k) {
    switch (k) {
        case DET_GRADE:
            if (r == RACE_DWARF) return ChanceIn{ 3, 4 };
            if (r == RACE_GNOME) return ChanceIn{ 8, 10 };
            if (r == RACE_HALFLING) return ChanceIn{ 3, 4 };
            return kDetectNone;
        case DET_NEW_CONSTRUCTION:
            if (r == RACE_DWARF) return ChanceIn{ 3, 4 };
            return kDetectNone;
        case DET_SLIDING_WALLS:
            if (r == RACE_DWARF) return ChanceIn{ 4, 6 };
            return kDetectNone;
        case DET_STONE_TRAPS:
            if (r == RACE_DWARF) return ChanceIn{ 2, 4 };
            return kDetectNone;
        case DET_DEPTH:
            if (r == RACE_DWARF) return ChanceIn{ 1, 2 };
            if (r == RACE_GNOME) return ChanceIn{ 6, 10 };
            return kDetectNone;
        case DET_UNSAFE_SURFACES:
            if (r == RACE_GNOME) return ChanceIn{ 7, 10 };
            return kDetectNone;
        case DET_DIRECTION:
            if (r == RACE_GNOME) return ChanceIn{ 1, 2 };
            if (r == RACE_HALFLING) return ChanceIn{ 1, 2 };
            return kDetectNone;
        case DET_SECRET_PASS:
            if (r == RACE_ELF || r == RACE_HALF_ELF)
                return ChanceIn{ 1, 6 };
            return kDetectNone;
        case DET_SECRET_SEARCH:
            if (r == RACE_ELF || r == RACE_HALF_ELF)
                return ChanceIn{ 2, 6 };
            return kDetectNone;
        case DET_CONCEALED_SEARCH:
            if (r == RACE_ELF || r == RACE_HALF_ELF)
                return ChanceIn{ 3, 6 };
            return kDetectNone;
        default:
            return kDetectNone;
    }
}

int raceDetectPct(CharRace r, DetectKind k) {
    ChanceIn c = raceDetectChance(r, k);
    if (c.den <= 0) return 0;
    return (c.num * 100) / c.den;
}

} // namespace rules
