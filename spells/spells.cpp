// ============================================================================
// Adnd1 - spells/spells.cpp
// PHB spell data + slot tables.
// ============================================================================

#include "spells.h"
#include "../rules/wisdom.h"  // R192: Wisdom Tables I and II

namespace spells {

// ----------------------------------------------------------------------------
// Registry (levels 1-3 per class). Casting times per PHB spells:
//   1st-3rd level MU spells are 1 segment except noted (sleep 1,
//   fireball/lightning 2... actually PHB gives MU spells casting
//   time = spell level in segments by convention when not printed;
//   rebuild convention: MU casting time = spell level segments,
//   cleric = spell level + 1 rounded per PHB spell descriptions
//   where known - see verification debt).
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
    // ---- R80: levels 4-6 (PHB premium reprint; values carry the
    // file's standing verification debt - printed tables win).
    // Utility rows land "known, cast pending" (resolveSpell
    // default); combat rows are wired in spelleffects.cpp.
    { "Polymorph Other",     SPELL_MU,     4,  4,  6,  0,   2, TARGET_CREATURE,   0, 0, 0, false },
    { "Ice Storm",           SPELL_MU,     4,  4, 10,  4,  -1, TARGET_AREA,       3, 2, 8, false },
    { "Fire Shield",         SPELL_MU,     4,  4,  0, 60,  -1, TARGET_SELF,       0, 0, 0, false },
    { "Charm Monster",       SPELL_MU,     4,  4, 12,  0,   4, TARGET_CREATURES,  0, 0, 0, false },
    { "Cone of Cold",        SPELL_MU,     5,  5,  0,  0,   3, TARGET_AREA,       2, 1, 6, false },
    { "Teleport",            SPELL_MU,     5,  2,  0,  0,  -1, TARGET_SPECIAL,    0, 0, 0, false },
    { "Hold Monster",        SPELL_MU,     5,  5, 12,  6,   4, TARGET_CREATURES,  0, 0, 0, false },
    { "Death Spell",         SPELL_MU,     6,  6,  6,  0,  -1, TARGET_AREA,       4, 0, 0, false },
    { "Disintegrate",        SPELL_MU,     6,  6,  6,  0,   4, TARGET_CREATURE,   0, 0, 0, false },
    { "Cure Critical Wounds",SPELL_CLERIC, 4,  4,  0,  0,  -1, TARGET_CREATURE,   0, 3, 8, true  },
    { "Cause Critical Wounds",SPELL_CLERIC, 4,  4,  0,  0,  -1, TARGET_CREATURE,   0, 3, 8, true  },
    { "Neutralize Poison",   SPELL_CLERIC, 4,  4,  0,  0,  -1, TARGET_CREATURE,   0, 0, 0, true  },
    { "Raise Dead",          SPELL_CLERIC, 5,  5,  0,  0,  -1, TARGET_CREATURE,   0, 0, 0, true  },
    { "Insect Plague",       SPELL_CLERIC, 5,  5,  3, 12,  -1, TARGET_AREA,       3, 2, 8, true  },
    { "Heal",                SPELL_CLERIC, 6,  6,  0,  0,  -1, TARGET_CREATURE,   0, 8, 8, true  },
    // ---- R129: the DMG p.14 caster-aging spells (levels
    // 7-9). "Known, cast pending" rows (the R80 utility
    // convention): the slot tables encode levels 1-6, so
    // spellSlots() yielded 0 for these until R130 delivered
    // the printed tables (MU to L20, cleric to L29); a
    // 12th-level caster still has no 7th-9th slot, so the
    // R129 pins stand - documented; the p.14 aging pins ride
    // magicalAgingYears regardless. TARGET_SELF: the aging
    // rider ages the target - for these rows the target IS
    // the caster. Casting times ride the file's convention
    // (MU = spell level segments, cleric = spell level + 1)
    // under the standing verification debt.
    { "Limited Wish",      SPELL_MU,     7,  7,  0,  0,  -1, TARGET_SELF, 0, 0, 0, false },
    { "Alter Reality",     SPELL_MU,     7,  7,  0,  0,  -1, TARGET_SELF, 0, 0, 0, false },
    { "Wish",              SPELL_MU,     9,  9,  0,  0,  -1, TARGET_SELF, 0, 0, 0, false },
    { "Gate",              SPELL_MU,     9,  9,  0,  0,  -1, TARGET_SELF, 0, 0, 0, false },
    { "Restoration",      SPELL_CLERIC,  7,  8,  0,  0,  -1, TARGET_SELF, 0, 0, 0, false },
    { "Resurrection",     SPELL_CLERIC,  7,  8,  0,  0,  -1, TARGET_SELF, 0, 0, 0, false },
};

const SpellDef& spell(SpellId id) {
    return kSpells[id < 0 || id >= SPELL_COUNT ? 0 : id];
}

int spellLevel(SpellId id)      { return spell(id).level; }
SpellClass spellClass(SpellId id) { return spell(id).sclass; }

// ----------------------------------------------------------------------------
// Slot tables (PHB class tables - R130 line-diff against the
// 1eonline.info PHB compilation: the class Table I and the
// SPELLS USABLE BY CLASS AND LEVEL appendix, which agree row
// for row except the MU L17 7th slot noted below. The R80
// project-notes rows 7-12 were corrected to the printed
// values; rows 1-6 matched. MU printed rows run to L20,
// cleric to L29; beyond the printed rows the final row holds
// (the compilation prints no further spell rows - the xp
// line keeps advancing, the spell rows do not). The printed
// wisdom footnotes are wired R192 (rules/wisdom.h and
// clericSpellSlotsWithWis: the 6th needs Wis 17, the 7th
// Wis 18 - Wisdom Table I; the printed ** puts a Wis-18
// cleric's first 7th at 16, which the L16 table row
// already grants - the gate is wisdom-side). Values ride
// the file's standing verification debt - the printed tables
// win when the PDF is re-uploaded.)
// ----------------------------------------------------------------------------

static const int kSlots = 9;      // spell levels 1-9 encoded
static const int kLevels = 29;    // class levels 1-29 (rows)

static const int kMuSlots[kLevels][kSlots] = {
    {1,0,0,0,0,0,0,0,0},   // L1 (unchanged - matches the print)
    {2,0,0,0,0,0,0,0,0},   // L2
    {2,1,0,0,0,0,0,0,0},   // L3
    {3,2,0,0,0,0,0,0,0},   // L4
    {4,2,1,0,0,0,0,0,0},   // L5
    {4,2,2,0,0,0,0,0,0},   // L6
    {4,3,2,1,0,0,0,0,0},   // L7 - corrected R130 (notes said 5,3,2,1)
    {4,3,3,2,0,0,0,0,0},   // L8 - corrected R130 (notes said 5,3,3,2)
    {4,3,3,2,1,0,0,0,0},   // L9 - corrected R130 (notes said 5,3,3,2,1)
    {4,4,3,3,2,0,0,0,0},   // L10 - corrected R130 (notes said 5,4,4,2,1)
    {4,4,4,3,3,0,0,0,0},   // L11 - corrected R130 (notes said 5,4,4,2,2)
    {4,4,4,4,4,1,0,0,0},   // L12 - corrected R130 (notes said 5,4,4,3,2,1)
    {5,5,5,4,4,2,0,0,0},   // L13 (printed; 7th at 14, 8th at 16, 9th at 18)
    {5,5,5,4,4,2,1,0,0},   // L14
    {5,5,5,5,5,2,1,0,0},   // L15
    {5,5,5,5,5,3,2,1,0},   // L16
    {5,5,5,5,5,3,2,2,0},   // L17 - the compilation's appendix prints 7th=2; its Table I prints 3 (documented fold; printed table wins on re-verify)
    {5,5,5,5,5,3,3,2,1},   // L18 (the Wish circle)
    {5,5,5,5,5,3,3,3,1},   // L19
    {5,5,5,5,5,4,3,3,2},   // L20 (last printed row)
    {5,5,5,5,5,4,3,3,2},   // L21 held
    {5,5,5,5,5,4,3,3,2},   // L22 held
    {5,5,5,5,5,4,3,3,2},   // L23 held
    {5,5,5,5,5,4,3,3,2},   // L24 held
    {5,5,5,5,5,4,3,3,2},   // L25 held
    {5,5,5,5,5,4,3,3,2},   // L26 held
    {5,5,5,5,5,4,3,3,2},   // L27 held
    {5,5,5,5,5,4,3,3,2},   // L28 held
    {5,5,5,5,5,4,3,3,2},   // L29 held (beyond the print, final row repeats)
};
static const int kClericSlots[kLevels][kSlots] = {
    {1,0,0,0,0,0,0,0,0},   // L1 (unchanged - matches the print)
    {2,0,0,0,0,0,0,0,0},   // L2
    {2,1,0,0,0,0,0,0,0},   // L3
    {3,2,0,0,0,0,0,0,0},   // L4
    {3,3,1,0,0,0,0,0,0},   // L5
    {3,3,2,0,0,0,0,0,0},   // L6 - corrected R130 (notes said 4,3,2)
    {3,3,2,1,0,0,0,0,0},   // L7 - corrected R130 (notes said 5,3,2,1)
    {3,3,3,2,0,0,0,0,0},   // L8 - corrected R130 (notes said 5,4,3,2)
    {4,4,3,2,1,0,0,0,0},   // L9 - corrected R130 (notes said 5,4,4,2,1)
    {4,4,3,3,2,0,0,0,0},   // L10 - corrected R130 (notes said 5,5,4,3,2)
    {5,4,4,3,2,1,0,0,0},   // L11 - corrected R130 (notes said 5,5,5,3,2,1); the printed * (Wis 17) on the 6th is not modeled
    {6,5,5,3,3,2,0,0,0},   // L12 - corrected R130 (notes said 5,5,5,4,3,2)
    {6,6,6,4,2,2,0,0,0},   // L13 - the printed 5th-level dip (2)
    {6,6,6,5,3,2,0,0,0},   // L14
    {7,7,7,5,4,2,0,0,0},   // L15
    {7,7,7,6,5,3,1,0,0},   // L16 - the printed ** (Wis 18) on the 7th; the level gate puts 7th at 17
    {8,8,8,6,5,3,1,0,0},   // L17
    {8,8,8,7,6,4,1,0,0},   // L18
    {9,9,9,7,6,4,2,0,0},   // L19
    {9,9,9,8,7,5,2,0,0},   // L20
    {9,9,9,9,8,6,2,0,0},   // L21
    {9,9,9,9,9,6,3,0,0},   // L22
    {9,9,9,9,9,7,3,0,0},   // L23
    {9,9,9,9,9,8,3,0,0},   // L24
    {9,9,9,9,9,8,4,0,0},   // L25
    {9,9,9,9,9,9,4,0,0},   // L26
    {9,9,9,9,9,9,5,0,0},   // L27
    {9,9,9,9,9,9,6,0,0},   // L28
    {9,9,9,9,9,9,7,0,0},   // L29 (last printed row)
};

int spellSlots(SpellClass sc, int classLevel, int spellLevel) {
    if (spellLevel < 1 || spellLevel > kSlots) return 0;
    if (classLevel < 1) classLevel = 1;
    if (classLevel > kLevels) classLevel = kLevels;
    return (sc == SPELL_MU ? kMuSlots : kClericSlots)
               [classLevel - 1][spellLevel - 1];
}

// ----------------------------------------------------------------------------
// R192: the wisdom wiring (PHB Wisdom Tables I and II)
// ----------------------------------------------------------------------------

// The cleric bonus spells at the wisdom score (the
// printed cumulative ladder; the caller gates the
// entitlement).
int clericBonusSpells(uint8_t wis, int spellLevel) {
    return rules::wisBonusSpells(wis, spellLevel);
}

// Cleric slots with wisdom: the printed table slots
// PLUS the cumulative wisdom bonus - granted only
// when the cleric is entitled to spells of that
// level (base slots at least 1, the printed note) -
// and the Table I high-circle gates applied: the 6th
// needs Wis 17, the 7th Wis 18 (the R130 documented
// engine limit now closed).
int clericSpellSlotsWithWis(int classLevel, int spellLevel,
                           uint8_t wis) {
    if (spellLevel == 6 && wis < 17) return 0;
    if (spellLevel == 7 && wis < 18) return 0;
    int base = spellSlots(SPELL_CLERIC, classLevel, spellLevel);
    if (base <= 0) return 0;
    return base + rules::wisBonusSpells(wis, spellLevel);
}

// The chance of spell failure for low wisdom.
int clericSpellFailurePct(uint8_t wis) {
    return rules::wisSpellFailurePct(wis);
}

// The failure roll: percentile dice, and if the
// number is equal to or less than the failure
// number the spell is expended and has absolutely
// no effect whatsoever.
bool rollClericSpellFailure(Dice& dice, uint8_t wis) {
    int pct = clericSpellFailurePct(wis);
    if (pct <= 0) return false;
    return (int)dice.d100() <= pct;
}

// ----------------------------------------------------------------------------
// Chance to learn (PHB p.10)
// ----------------------------------------------------------------------------

// R196: the printed INTELLIGENCE TABLE II chance-to-know
// column (the engine ladder diverged at 10, 16, 17
// and 18): 9 35, 10-12 45, 13-14 55, 15-16 65,
// 17 75, 18 85, 19+ 95 (the printed or-more row).
// The table starts at 9 - the MU minimum.
int chanceToLearnPct(uint8_t int_) {
    if (int_ <= 8)  return 0;
    if (int_ == 9)  return 35;   // R196: the print
    if (int_ <= 12) return 45;   // 10, 11, 12
    if (int_ <= 14) return 55;   // 13, 14
    if (int_ <= 16) return 65;   // 15, 16
    if (int_ == 17) return 75;
    if (int_ == 18) return 85;
    return 95;   // 19 and up (the or-more row)
}

bool rollChanceToLearn(Dice& dice, uint8_t int_) {
    int pct = chanceToLearnPct(int_);
    if (pct <= 0) return false;
    return (int)dice.d100() <= pct;
}

// ----------------------------------------------------------------------------
// R196: INTELLIGENCE TABLE II, the min and max spells-per-level
// columns. All pins as -1 (the repo unlimited convention).
// R196b: the accessors live at file scope - the nested-function fix.
// ----------------------------------------------------------------------------

int minSpellsPerLevel(uint8_t int_) {
    if (int_ < 9)  return 0;
    if (int_ == 9)  return 4;
    if (int_ <= 12) return 5;   // 10, 11, 12
    if (int_ <= 14) return 6;   // 13, 14
    if (int_ <= 16) return 7;   // 15, 16
    if (int_ == 17) return 8;
    if (int_ == 18) return 9;
    return 10;   // 19 and up
}

int maxSpellsPerLevel(uint8_t int_) {
    if (int_ < 9)  return 0;
    if (int_ == 9)  return 6;
    if (int_ <= 12) return 7;   // 10, 11, 12
    if (int_ <= 14) return 9;   // 13, 14
    if (int_ <= 16) return 11;   // 15, 16
    if (int_ == 17) return 14;
    if (int_ == 18) return 18;
    return -1;   // 19 and up: All (unlimited)
}

// ----------------------------------------------------------------------------
// R197: the printed Wisdom Table I note - the magical defense
// adjustment applies only to mental attack forms involving
// will force: beguiling, charming, fear, hypnosis, illusion,
// magic jarring, mass charming, phantasmal forces, possession,
// rulership, suggestion, telepathic attack. Per-spell engine
// data: which registry spells ARE those forms. The 54-spell
// registry holds two: charm person (charming) and charm
// monster (mass charming). The holds are NOT will-force
// forms - the PHB Serten spell immunity print groups hold
// with command, domination, fear and scare, apart from
// beguiling, charm and suggestion. Fear, hypnosis,
// suggestion and the phantasmal forces ride the flag
// when their registry rows arrive.
// ----------------------------------------------------------------------------
bool spellIsMentalForm(SpellId id) {
    switch (id) {
        case MU_CHARM_PERSON:     // charming
        case MU_CHARM_MONSTER:    // mass charming
            return true;
        default:
            return false;
    }
}

// The save-modifier assembly: the WIS magical defense
// adjustment - the printed Wisdom Table I ladder,
// wisMagicalAttackAdj, the same one R194 wisMagDefAdj
// delegates to - on mental-form spells; 0 on everything
// else. The save rolls stay caller-assembled
// (rules/saves.h); callers call this.
int spellSaveModWis(SpellId id, uint8_t wis) {
    if (!spellIsMentalForm(id)) return 0;
    return rules::wisMagicalAttackAdj(wis);
}

// ----------------------------------------------------------------------------
// R115: the years magic steals (DMG p.14). Only haste is in
// the registry today (its recipient pays 1 year); the rest
// of the book's table rides the comment in spells.h until
// those spells arrive.
// ----------------------------------------------------------------------------
int magicalAgingYears(SpellId id) {
    if (id == MU_HASTE) return 1;   // p.14: under a haste spell
    // R129: the p.14 caster-aged causes (TARGET_SELF rows -
    // the rider ages the caster)
    if (id == MU_LIMITED_WISH)  return 1;   // p.14
    if (id == CL_RESTORATION)   return 2;   // p.14
    if (id == MU_ALTER_REALITY) return 3;   // p.14
    if (id == MU_WISH)          return 3;   // p.14
    if (id == CL_RESURRECTION)  return 3;   // p.14
    if (id == MU_GATE)          return 5;   // p.14
    return 0;
}

// ----------------------------------------------------------------------------
// Max spell level gates
// ----------------------------------------------------------------------------

int maxSpellLevelForInt(uint8_t int_) {
    // PHB p.10 minimum INT by spell level: L1-2: 9, L3: 11, L4: 14,
    // L5: 15, L6: 16+ ... encoded as a lookup. R130 extends past
    // 6th by the file's convention: 17 opens the 7th circle and
    // 18 the 8th and 9th (the PHB's own "only the highest
    // intelligence is able to comprehend the mighty magics
    // contained in 9th level spells" note; a convention
    // extension riding the standing verification debt)
    if (int_ < 9)  return 0;
    if (int_ < 11) return 2;
    if (int_ < 14) return 3;
    if (int_ < 15) return 4;
    if (int_ < 16) return 5;
    if (int_ < 17) return 6;
    if (int_ < 18) return 7;
    return 9;
}

int maxSpellLevelForClericLevel(int classLevel) {
    // R130: 7th at 17 in the level view (R192: the printed **
    // footnote puts a Wis-18 cleric's first 7th at 16 -
    // the level gate is the printed rule; the wisdom gate
    // rides clericSpellSlotsWithWis, Wisdom Table I)
    if (classLevel < 1)  return 0;
    if (classLevel < 3)  return 1;
    if (classLevel < 5)  return 2;
    if (classLevel < 7)  return 3;
    if (classLevel < 9)  return 4;
    if (classLevel < 11) return 5;
    if (classLevel < 17) return 6;
    return 7;
}

} // namespace spells