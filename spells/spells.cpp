// ============================================================================
// Adnd1 — spells/spells.cpp
// PHB spell data + slot tables.
// ============================================================================

#include "spells.h"

namespace spells {

// ----------------------------------------------------------------------------
// Registry (levels 1-3 per class). Casting times per PHB spells:
//   1st-3rd level MU spells are 1 segment except noted (sleep 1,
//   fireball/lightning 2... actually PHB gives MU spells casting
//   time = spell level in segments by convention when not printed;
//   rebuild convention: MU casting time = spell level segments,
//   cleric = spell level + 1 rounded per PHB spell descriptions
//   where known — see verification debt).
// Damage scaling: MU damage spells 1d6 per caster level (fireball,
// lightning bolt cap at 10d6+ per PHB; the engine caps at cast time).
// ----------------------------------------------------------------------------

static const SpellDef kSpells[SPELL_COUNT] = {
    // name                class        lv  ct  rng dur save target          aoe dmg
    { "Sleep",             SPELL_MU,     1,  1, 10,  0,  -1, TARGET_CREATURES,  0, 0, 0, false },
    { "Magic Missile",     SPELL_MU,     1,  1,  6,  0,  -1, TARGET_CREATURE,   0, 1, 4, false },
    { "Shield",            SPELL_MU,     1,  1,  0, 20,  -1, TARGET_SELF,       0, 0, 0, false },
    { "Light",             SPELL_MU,     1,  1, 12, 60,  -1, TARGET_SPECIAL,    3, 0, 0, false },
    { "Detect Magic",      SPELL_MU,     1,  1,  6, 12,  -1, TARGET_SELF,       0, 0, 0, false },
    { "Charm Person",      SPELL_MU,     1,  1, 12,  0,   4, TARGET_CREATURE,   0, 0, 0, false },
    { "Floating Disc",     SPELL_MU,     1,  1,  2, 60,  -1, TARGET_SPECIAL,    0, 0, 0, false },
    { "Hold Portal",       SPELL_MU,     1,  1,  2, 20,  -1, TARGET_SPECIAL,    0, 0, 0, false },
    { "Invisibility",      SPELL_MU,     2,  2,  1,  0,  -1, TARGET_CREATURE,   0, 0, 0, false },
    { "Mirror Image",      SPELL_MU,     2,  2,  0,  0,  -1, TARGET_SELF,       0, 0, 0, false },
    { "Web",               SPELL_MU,     2,  2,  5, 60,   1, TARGET_AREA,       1, 0, 0, false },
    { "Strength",          SPELL_MU,     2,  2,  1, 60,  -1, TARGET_CREATURE,   0, 0, 0, false },
    { "Invisibility 10'",  SPELL_MU,     2,  2,  0,  0,  -1, TARGET_AREA,       1, 0, 0, false },
    { "Fireball",          SPELL_MU,     3,  3, 10,  0,   4, TARGET_AREA,       2, 1, 6, false },
    { "Lightning Bolt",    SPELL_MU,     3,  3, 10,  0,   4, TARGET_AREA,       2, 1, 6, false },
    { "Fly",               SPELL_MU,     3,  3,  1, 60,  -1, TARGET_CREATURE,   0, 0, 0, false },
    { "Haste",             SPELL_MU,     3,  3, 12, 30,  -1, TARGET_AREA,       3, 0, 0, false },
    { "Dispel Magic",      SPELL_MU,     3,  3, 12,  0,  -1, TARGET_SPECIAL,    0, 0, 0, false },
    { "Cure Light Wounds", SPELL_CLERIC,  1,  2,  0,  0,  -1, TARGET_CREATURE,   0, 1, 8, true  },
    { "Cause Light Wounds",SPELL_CLERIC,  1,  2,  0,  0,  -1, TARGET_CREATURE,   0, 1, 8, true  },
    { "Detect Magic",      SPELL_CLERIC,  1,  2, 12, 12,  -1, TARGET_SELF,       0, 0, 0, false },
    { "Light",             SPELL_CLERIC,  1,  2, 12, 60,  -1, TARGET_SPECIAL,    3, 0, 0, true  },
    { "Protection from Evil",SPELL_CLERIC,1,  2,  0, 60,  -1, TARGET_SELF,       0, 0, 0, false },
    { "Purify Food & Drink",SPELL_CLERIC,1,  2, 12,  0,  -1, TARGET_AREA,       1, 0, 0, false },
    { "Resist Cold",       SPELL_CLERIC,  1,  2,  3, 20,  -1, TARGET_AREA,       3, 0, 0, false },
    { "Blight",            SPELL_CLERIC,  1,  2, 12,  0,  -1, TARGET_AREA,       1, 0, 0, true  },
    { "Hold Person",       SPELL_CLERIC,  2,  3, 12, 20,   4, TARGET_CREATURES,  0, 0, 0, false },
    { "Silence 15' Radius",SPELL_CLERIC,  2,  3, 12, 20,   4, TARGET_AREA,       2, 0, 0, false },
    { "Slow Poison",       SPELL_CLERIC,  2,  3,  3, 60,  -1, TARGET_CREATURE,   0, 0, 0, false },
    { "Cure Serious Wounds",SPELL_CLERIC,2,  3,  0,  0,  -1, TARGET_CREATURE,   0, 2, 8, true  },
    { "Cause Serious Wounds",SPELL_CLERIC,2, 3,  0,  0,  -1, TARGET_CREATURE,   0, 2, 8, true  },
    { "Dispel Magic",      SPELL_CLERIC,  3,  4, 12,  0,  -1, TARGET_SPECIAL,    0, 0, 0, false },
    { "Prayer",            SPELL_CLERIC,  3,  4,  0, 60,  -1, TARGET_AREA,       3, 0, 0, false },
};

const SpellDef& spell(SpellId id) {
    return kSpells[id < 0 || id >= SPELL_COUNT ? 0 : id];
}

int spellLevel(SpellId id)      { return spell(id).level; }
SpellClass spellClass(SpellId id) { return spell(id).sclass; }

// ----------------------------------------------------------------------------
// Slot tables (PHB p.20+)
//   MU: L1: 1 slot;  L2: 2; L3: 2/1; L4: 3/2; L5: 4/2/1; L6: 4/2/2;
//       L7: 5/3/2/1 ... (rows to L12)
//   Cleric: L1: 1; L2: 2; L3: 2/1; L4: 3/2; L5: 3/3/1;
//       L6: 4/3/2; L7: 5/3/2/1 ... (rows to L12)
// Encoded: max spell level 6 (columns), levels 1-12 (rows).
// ----------------------------------------------------------------------------

static const int kSlots = 6;      // spell levels 1-6 encoded
static const int kLevels = 12;    // class levels 1-12

static const int kMuSlots[kLevels][kSlots] = {
    {1,0,0,0,0,0},{2,0,0,0,0,0},{2,1,0,0,0,0},{3,2,0,0,0,0},
    {4,2,1,0,0,0},{4,2,2,0,0,0},{5,3,2,1,0,0},{5,3,3,2,0,0},
    {5,3,3,2,1,0},{5,4,4,2,1,0},{5,4,4,2,2,0},{5,4,4,3,2,1},
};
static const int kClericSlots[kLevels][kSlots] = {
    {1,0,0,0,0,0},{2,0,0,0,0,0},{2,1,0,0,0,0},{3,2,0,0,0,0},
    {3,3,1,0,0,0},{4,3,2,0,0,0},{5,3,2,1,0,0},{5,4,3,2,0,0},
    {5,4,4,2,1,0},{5,5,4,3,2,0},{5,5,5,3,2,1},{5,5,5,4,3,2},
};

int spellSlots(SpellClass sc, int classLevel, int spellLevel) {
    if (spellLevel < 1 || spellLevel > kSlots) return 0;
    if (classLevel < 1) classLevel = 1;
    if (classLevel > kLevels) classLevel = kLevels;
    return (sc == SPELL_MU ? kMuSlots : kClericSlots)
               [classLevel - 1][spellLevel - 1];
}

// ----------------------------------------------------------------------------
// Chance to learn (PHB p.10)
// ----------------------------------------------------------------------------

int chanceToLearnPct(uint8_t int_) {
    switch (int_) {
        case 0: case 1: case 2: case 3: case 4:
        case 5: case 6: case 7: case 8:  return 0;
        case 9: case 10:                return 35;
        case 11: case 12:               return 45;
        case 13: case 14:               return 55;
        case 15:                        return 65;
        case 16:                        return 70;
        case 17:                        return 85;
        default:                        return 95;   // 18+
    }
}

bool rollChanceToLearn(Dice& dice, uint8_t int_) {
    int pct = chanceToLearnPct(int_);
    if (pct <= 0) return false;
    return (int)dice.d100() <= pct;
}

// ----------------------------------------------------------------------------
// Max spell level gates
// ----------------------------------------------------------------------------

int maxSpellLevelForInt(uint8_t int_) {
    // PHB p.10 minimum INT by spell level: L1-2: 9, L3: 11, L4: 14,
    // L5: 15, L6: 16+ ... encoded as a lookup
    if (int_ < 9)  return 0;
    if (int_ < 11) return 2;
    if (int_ < 14) return 3;
    if (int_ < 15) return 4;
    if (int_ < 16) return 5;
    return 6;
}

int maxSpellLevelForClericLevel(int classLevel) {
    if (classLevel < 1)  return 0;
    if (classLevel < 3)  return 1;
    if (classLevel < 5)  return 2;
    if (classLevel < 7)  return 3;
    if (classLevel < 9)  return 4;
    if (classLevel < 11) return 5;
    return 6;
}

} // namespace spells