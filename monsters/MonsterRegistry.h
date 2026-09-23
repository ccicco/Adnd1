// ============================================================================
// Adnd1 — monsters/MonsterRegistry.h
// Lua-driven monster definitions. Each monsters/monsters/*.lua file
// returns a table describing one monster; the registry loads the
// directory and maps entries to ai::Actor via toActor().
//
// Lua C API only (Lua 5.4), per the original project convention.
// ============================================================================

#pragma once

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
// MonsterDef: one loaded monster.
// ----------------------------------------------------------------------------
struct MonsterDef {
    std::string key;              // file basename, e.g. "orc"
    std::string name;             // "Orc"
    float       hitDice = 1.0f;
    int         hitPointBonus = 0;
    int         armorClass = 9;
    int         attacks = 1;      // routines per round
    int         damageCount = 1, damageSides = 6;
    int         damageBonus = 0;  // legacy flat addend / exact imported flat
    int         damageMin = 0, damageMax = 0;   // imported exact range
    std::string damageRaw;        // imported prose/raw damage note
    int         morale = 12;
    int         magicResist = 0;
    bool        undead = false;
    int         requiredPlus = 0; // weapon gating (R5)
    int         levelTag = 1;     // dungeon level tag (wandering tables)
    int         xpValue = 10;
    bool        isLeader = false;
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

    // Instantiate as a combat actor (hp rolled from HD + bonus).
    ai::Actor toActor(const std::string& key, rules::Dice& dice,
                      int hp = -1) const;   // hp < 0 = roll from HD

    // Monsters tagged for a dungeon level (Appendix C-ish filter)
    std::vector<std::string> keysForLevel(int dungeonLevel) const;

    const std::vector<std::string>& errors() const { return m_errors; }

private:
    bool loadFile(const std::string& path, const std::string& key);
    std::map<std::string, MonsterDef> m_defs;
    std::vector<std::string> m_errors;
};

} // namespace monsters