// ============================================================================
// Adnd1 - rules/classes.cpp
//
// RE-AUTHORED from the R4 spec after the original upload was lost.
// R162: the titleFor ladders and the HP_BEYOND_CAP convention are
// verified against the PHB print (pp.20-31); R176 repins the
// xpForLevel rows to the printed XP boundaries cell by cell (the
// R162 divergence closed - the printed adders, the band-lower-1
// attain convention; see the R176 battery audit).
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
// XP tables (PHB pp.20-31 printed class tables, pinned R176).
// Convention: the XP to ATTAIN level N is the printed band lower
// bound - 1 (fighter level 5: the band 18,001-35,000 gives 18000);
// level 1 is 0. Rows through level 13 (index = level-1); beyond,
// each level adds the printed adder (fighter 250k past the 11th,
// MU 375k past the 12th, cleric 225k past the 11th, thief 220k
// past the 12th).
// ----------------------------------------------------------------------------

static const int XP_FIGHTER[13] = {
        0,    2000,    4000,    8000,   18000,   35000,
    70000,  125000,  250000,  500000,  750000, 1000000,
  1250000
};

static const int XP_MAGIC_USER[13] = {
        0,    2500,    5000,   10000,   22500,   40000,
    60000,   90000,  135000,  250000,  375000,  750000,
  1125000
};

static const int XP_CLERIC[13] = {
        0,    1500,    3000,    6000,   13000,   27500,
    55000,  110000,  225000,  450000,  675000,  900000,
  1125000
};

static const int XP_THIEF[13] = {
        0,    1250,    2500,    5000,   10000,   20000,
    42500,   70000,  110000,  160000,  220000,  440000,
   660000
};

// The printed adders per level beyond the table rows
static const int XP_ADDER[CLASS_COUNT] = { 250000, 375000, 225000, 220000 };

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
