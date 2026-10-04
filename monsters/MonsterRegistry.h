// ============================================================================
// Adnd1 - monsters/MonsterRegistry.h
// Lua-driven monster definitions. Each monsters/monsters/*.lua file
// returns a table describing one monster; the registry loads the
// directory and maps entries to ai::Actor via toActor().
//
// R49: remapped to the mm2lua.py schema (v2). New Lua field names:
//   hitDiceNum / hitDiceBonus / avgHp        (was hd / hpBonus)
//   armorClass  (number | table | string)    (was ac number)
//   numAttacks  (number | string)            (was attacks)
//   damage      (array of {min,max} routines) (was damageCount/damageSides)
//   magicResistance (string "25%" etc.)      (was magicResist number)
//   xp / xpPerHp / xpValue / xpSource        (xpValue = full kill XP)
//   frequency, noAppearing, lairPct, move, size, intelligence, alignment,
//   specialAttacks/specialDefenses (strings), text (full MM prose)
// Old-style keys (hd/ac/attacks/...) are still honored as fallbacks.
//
// Lua C API only (Lua 5.4), per the original project convention.
// ============================================================================

#pragma once

#include "../rules/character.h"
#include "../rules/classes.h"
#include "../ai/actor.h"

#include <map>
#include <string>
#include <vector>

namespace monsters {

// ----------------------------------------------------------------------------
// Special attacks: parsed from Lua, resolved by C++ handlers in the
// encounter driver (R18 hooks the full resolution).
// ----------------------------------------------------------------------------
enum SpecialAttackType : int {
    SPECIAL_NONE = 0,
    SPECIAL_POISON,        // save vs death/poison or suffer effect
    SPECIAL_PARALYSIS,     // save vs petrify/poly or paralyzed
    SPECIAL_ENERGY_DRAIN,  // level drain on hit (wight/wraith/spectre)
    SPECIAL_BREATH_WEAPON, // damage dice + save vs breath for half
    SPECIAL_TYPE_COUNT
};

struct SpecialAttack {
    SpecialAttackType type = SPECIAL_NONE;
    std::string       name;             // display name
    int               saveCategory = 0; // rules/SaveCategory
    int               savePenalty = 0;  // e.g. -2 vs poison
    int               diceCount = 0;    // breath weapon damage
    int               diceSides = 0;
    int               drainLevels = 1;  // energy drain
};

// ----------------------------------------------------------------------------
// One damage routine from the Lua damage array ({min=..,max=..} entries).
// ----------------------------------------------------------------------------
struct DamageRoutine {
    int min = 0;
    int max = 0;
};

// ----------------------------------------------------------------------------
// R71: Treasure type letters (MM p.105). The Lua `treasure` field is
// parsed into per-creature ("individuals") and in-lair letter lists.
// Splits follow the printed TREASURE TYPE lines (Curtiss-verified):
// semicolons/periods split the halves; for the comma-only
// "Individuals ... in lair" strings the J-N per-individual band is
// the default and the four book-verified exceptions are hard-coded
// (hobgoblin, kobold, ettin, dervish).
// ----------------------------------------------------------------------------
struct TreasureEntry {
    char letter = 'A';
    int  times  = 1;          // "(x10)" multiplier
    bool magicOnly = false;   // "G (magic)" / "C (magic only)"
};

struct TreasureSpec {
    std::vector<TreasureEntry> individual;   // rolled per slain creature
    std::vector<TreasureEntry> lair;          // rolled on a lair victory
    bool certain = false;                     // "100% ..." prefix
    bool empty() const {
        return individual.empty() && lair.empty();
    }
};

// ----------------------------------------------------------------------------
// MonsterDef: one loaded monster.
// ----------------------------------------------------------------------------
struct MonsterDef {
    std::string key;              // file basename, e.g. "orc"
    std::string name;             // "Orc"

    // hit dice (Lua: hitDiceNum, hitDiceBonus, avgHp; hitDice display string)
    float hitDice = 1.0f;          // hitDiceNum + hitDiceBonus/4 (compat)
    int   hitDiceNum = 1;
    int   hitDiceBonus = 0;
    int   avgHp = 0;              // book-average hp (0 = unknown)

    int   armorClass = 9;

    // attacks: Lua numAttacks may be a number or text ("1 and 1")
    int   attacks = 1;

    // damage routines in order (Lua damage array). Actor carries only
    // one dice pair, so toActor() maps the PRIMARY routine (largest
    // max) to count/sides as an approximation:
    //   min..max  ->  1 die of (max-min+1) sides   (1-4 -> 1d4, 2-24 -> 1d23)
    // Flat bonuses are folded into the approximation (same average).
    std::vector<DamageRoutine> damageRoutines;
    int   damageCount = 1, damageSides = 6;

    int   morale = 12;             // heuristic from intelligence if not given
    int   magicResist = 0;         // Lua magicResistance "25%" -> 25

    // R155: matrix II.C (DMG p.80) - classed-monster saves:
    // saveAs ("cleric 9" / "magic-user 5, cleric 7") parses into
    // class bits with per-class levels; saveAsBonus is a flat die
    // bonus (displacer +2).
    int   saveAsMask = 0;
    int   saveAsLevels[4] = {0, 0, 0, 0};
    int   saveAsBonus = 0;

    bool  undead = false;          // heuristic: name keywords
    int   requiredPlus = 0;        // heuristic: specialDefenses text
    int   levelTag = 1;            // heuristic: derived from HD
    bool  isLeader = false;

    // XP (Lua: xp base, xpPerHp, xpValue total for an average specimen,
    // xpSource appendixE|formula)
    int   xpBase = 0;
    int   xpPerHp = 0;
    int   xpValue = 10;            // full kill XP (base + per-hp x avgHp)
    std::string xpSource;

    // descriptive fields (R49: loaded, wiring later)
    std::string hitDiceText;       // e.g. "4 + 3"
    std::string frequency;        // "uncommon"
    int   noAppearingMin = 0, noAppearingMax = 0;
    int   lairPct = 0;
    int   moveRate = 0;            // primary move rate (inches/10')
    std::string size;              // "S"/"M"/"L"
    std::string intelligence;      // "low", "average", ...
    std::string alignment;         // "chaotic_evil"
    std::string specialAttacksText; // verbatim SPECIAL ATTACKS field
    std::string specialDefensesText;
    std::string text;              // complete MM prose (bestiary viewer)

    // R71: treasure type letters + verbatim Lua text (bestiary/debug)
    TreasureSpec treasure;
    std::string treasureText;

    std::vector<SpecialAttack> specials;
};

const char* specialAttackTypeName(SpecialAttackType t);

// ----------------------------------------------------------------------------
// Registry
// ----------------------------------------------------------------------------
class MonsterRegistry {
public:
    // Load every .lua in the directory. Returns count loaded, or -1
    // on a hard error (directory unreadable). Individual file errors
    // are skipped with a note in errors().
    int loadDirectory(const std::string& dirPath);

    // Registry lookup; nullptr if not loaded
    const MonsterDef* find(const std::string& key) const;

    // All loaded monsters
    const std::map<std::string, MonsterDef>& all() const { return m_defs; }

    // Instantiate as a combat actor (hp rolled from HD + bonus; a
    // flat-hp monster with no dice uses its book average).
    // R51: hdOverride rolls that many dice instead of the def's
    // hitDiceNum (dragons: rolled species HD; hydra: heads; animals:
    // rolled variable HD). hpPerDie > 0 gives FIXED hp per die
    // instead of a roll (dragon age bracket 1-8; hydra 8/hd full).
    // a.hitDice reflects the override so attack matrices follow.
    ai::Actor toActor(const std::string& key, rules::Dice& dice,
                      int hp = -1, int hdOverride = -1,
                      int hpPerDie = 0) const;   // hp < 0 = roll from HD

    // R52: DEPRECATED - superseded by dm/encounters.h (the
    // real DMG Appendix C tables). Kept for regtest only; new
    // code uses dm::encounterKeys / dm::rollDungeonEncounter.
    std::vector<std::string> keysForLevel(int dungeonLevel) const;

    const std::vector<std::string>& errors() const { return m_errors; }

private:
    bool loadFile(const std::string& path, const std::string& key);
    std::map<std::string, MonsterDef> m_defs;
    std::vector<std::string> m_errors;
};

} // namespace monsters
