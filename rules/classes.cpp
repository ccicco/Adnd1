// ============================================================================
// Adnd1 - rules/classes.cpp
//
// RE-AUTHORED from the R4 spec after the original upload was lost.
// R162: the titleFor ladders and the HP_BEYOND_CAP convention are
// verified against the PHB print (pp.20-31); the xpForLevel rows
// DIVERGE from the print from mid-table on (fighter level 5 reads
// 16000 against the printed 18000 boundary; the MU, cleric and
// thief rows diverge above that) and stay open.
// ============================================================================

#include "classes.h"

#include <algorithm>

namespace rules {

// ----------------------------------------------------------------------------
// Constants
// ----------------------------------------------------------------------------

const int CLASS_LEVEL_CAP[CLASS_COUNT]  = { 9, 11, 9, 10 };
const int HP_BEYOND_CAP[CLASS_COUNT]    = { 3, 1, 2, 2 };
const int CLASS_HIT_DIE[CLASS_COUNT]    = { 10, 4, 8, 6 };

// ----------------------------------------------------------------------------
// XP tables (index = level - 1; rows through level 12, then linear)
// NOTE: transcribed from project notes; verify vs PHB p.20-31.
// ----------------------------------------------------------------------------

static const int XP_FIGHTER[13] = {
        0,    2000,    4000,    8000,   16000,   35000,
    70000,  125000,  250000,  350000,  450000,  550000,
   650000
};

static const int XP_MAGIC_USER[13] = {
        0,    2500,    5000,   10000,   20000,   40000,
    60000,   80000,  105000,  135000,  165000,  195000,
   225000
};

static const int XP_CLERIC[13] = {
        0,    1500,    3000,    6000,   13000,   27500,
    55000,  110000,  225000,  337500,  450000,  562500,
   675000
};

static const int XP_THIEF[13] = {
        0,    1250,    2500,    5000,   10000,   20000,
    42500,   70000,  110000,  160000,  210000,  260000,
   310000
};

// Linear adder per level beyond the 12-row tables
static const int XP_ADDER[CLASS_COUNT] = { 100000, 125000, 112500, 110000 };

int xpForLevel(int classIndex, int level) {
    if (classIndex < 0 || classIndex >= CLASS_COUNT) return 0;
    if (level <= 1) return 0;

    static const int* tables[CLASS_COUNT] = {
        XP_FIGHTER, XP_MAGIC_USER, XP_CLERIC, XP_THIEF
    };

    if (level <= 13)
        return tables[classIndex][level - 1];

    // beyond the table: last row + (levels past 13) x adder
    return tables[classIndex][12] + (level - 13) * XP_ADDER[classIndex];
}

// ----------------------------------------------------------------------------
// Titles (the PHB p.20-31 printed ladders - R162 verified; the
// cleric level 5 cell prints blank and carries Curate down)
// ----------------------------------------------------------------------------

static const char* const TITLES_FIGHTER[9] = {
    "Veteran", "Warrior", "Swordsman", "Hero", "Swashbuckler",
    "Myrmidon", "Champion", "Superhero", "Lord"
};
static const char* const TITLES_MAGIC_USER[11] = {
    "Prestidigitator", "Evoker", "Conjurer", "Theurgist",
    "Thaumaturgist", "Magician", "Enchanter", "Warlock",
    "Sorcerer", "Necromancer", "Wizard"
};
static const char* const TITLES_CLERIC[9] = {
    "Acolyte", "Adept", "Priest", "Curate", "Curate",
    "Canon", "Lama", "Patriarch", "High Priest"
};
static const char* const TITLES_THIEF[10] = {
    "Rogue (Apprentice)", "Footpad", "Cutpurse", "Robber",
    "Burglar", "Filcher", "Sharper", "Magsman", "Thief",
    "Master Thief"
};

const char* titleFor(int classIndex, int level) {
    if (classIndex < 0 || classIndex >= CLASS_COUNT) return "Unknown";
    if (level < 1) level = 1;

    int cap = CLASS_LEVEL_CAP[classIndex];
    if (level > cap) level = cap;

    switch (classIndex) {
        case CLASS_FIGHTER:    return TITLES_FIGHTER[level - 1];
        case CLASS_MAGIC_USER: return TITLES_MAGIC_USER[level - 1];
        case CLASS_CLERIC:     return TITLES_CLERIC[level - 1];
        case CLASS_THIEF:      return TITLES_THIEF[level - 1];
    }
    return "Unknown";
}

// ----------------------------------------------------------------------------
// Prerequisites and adjustments
// ----------------------------------------------------------------------------

int primeRequisite(int classIndex) {
    switch (classIndex) {
        case CLASS_FIGHTER:    return ABILITY_STR;
        case CLASS_MAGIC_USER: return ABILITY_INT;
        case CLASS_CLERIC:     return ABILITY_WIS;
        case CLASS_THIEF:      return ABILITY_DEX;
    }
    return ABILITY_STR;
}

int classMinAbility(int classIndex) {
    (void)classIndex;
    return 9;   // all classes: minimum 9 in the prime requisite
}

int conHPAdjustment(int classIndex, int con) {
    if (con <= 3) return -2;
    if (con <= 6) return -1;
    if (con <= 14) return 0;
    if (con == 15) return 1;
    if (con == 16) return 2;
    // CON 17-18: fighters get +3/+4; everyone else caps at +2
    if (classIndex == CLASS_FIGHTER)
        return (con >= 18) ? 4 : 3;
    return 2;
}

int rollHitPoints(int classIndex, int level, int conAdj, Dice& dice) {
    if (classIndex < 0 || classIndex >= CLASS_COUNT) return 1;
    if (level < 1) level = 1;

    int hp;
    if (level > CLASS_LEVEL_CAP[classIndex]) {
        // beyond the name cap: fixed value per level
        hp = HP_BEYOND_CAP[classIndex] + conAdj;
    } else {
        // one hit die for the level, + con adjustment
        int die = (int)dice.roll(1, (uint32_t)CLASS_HIT_DIE[classIndex], 0);
        hp = die + conAdj;
    }
    if (hp < 1) hp = 1;   // per-die floor
    return hp;
}

int averageHitPoints(int classIndex) {
    if (classIndex < 0 || classIndex >= CLASS_COUNT) return 1;
    return (1 + CLASS_HIT_DIE[classIndex]) / 2;
}

// ----------------------------------------------------------------------------
// Equipment permissions
// ----------------------------------------------------------------------------

bool armorAllowed(int classIndex, ArmorWeight weight) {
    switch (classIndex) {
        case CLASS_FIGHTER:
            return true;                       // any armor
        case CLASS_MAGIC_USER:
            return weight == ARMOR_NONE;       // none
        case CLASS_CLERIC:
            return weight <= ARMOR_CHAIN;      // up to chain
        case CLASS_THIEF:
            return weight <= ARMOR_LEATHER;    // up to leather
    }
    return false;
}

bool shieldAllowed(int classIndex) {
    switch (classIndex) {
        case CLASS_FIGHTER:
        case CLASS_CLERIC:
            return true;
        default:
            return false;
    }
}

int rollExceptionalStrength(Dice& dice) {
    return (int)dice.roll(1, 100, 0);   // 1..100
}

} // namespace rules
