// ============================================================================
// Adnd1 - rules/phb/palrangerspells.h
// The paladin and ranger spell layers (R184).
//
// The SPELLS USABLE BY CLASS AND LEVEL - PALADINS table
// (paladin levels 9-20 x 4 clerical spell levels) and the
// RANGERS table (ranger levels 8-17 x the five printed
// columns: druidic 1-3 and magic-user 1-2), every printed
// cell; the shared-list wiring; and the printed specials
// the R184 box names - lay on hands, cure disease, the
// ranger giant-class damage bonus.
//
// JUDGMENTs:
//   - the printed table dashes (no slots) pin as 0.
//   - the paladin gains cleric spell ability at 9th level
//     through 20th (the print footnote: maximum spell
//     ability); below 9th, no slots; past 20th, the 20th
//     row clamps. The paladin casts from the CLERIC list
//     (levels 1-4) but never from clerical scrolls.
//   - the ranger gains druidic spell ability at 8th and
//     magic-user spell ability at 9th, additions through
//     the 17th (the print footnote: maximum spell ability);
//     below 8th, no slots; past 17th, the 17th row clamps.
//     The ranger casts druid spells from the R182 druid
//     roster (levels 1-3) and magic-user spells (levels
//     1-2), and must check which spells are learnable just
//     as if a magic-user (the print footnote); rangers
//     cannot read druid or magic-user scrolls in any event.
//   - lay on hands: 2 hit points per paladin level, once
//     per day. Cure disease: once per week per five levels
//     (levels 1-5 one, 6-10 two, 11-15 three, and so on).
//   - the giant-class damage bonus: +1 hit point per ranger
//     experience level vs the 11 listed creatures. The
//     ranger surprise numbers (surprises on d6 1-3, is
//     surprised on 1) and the paladin turn-undead ladder
//     (as a cleric of level-2 from 3rd level) are specials
//     recorded for the R187+ rounds.
//
// DATA-DRIVEN (the standing scope): the same table shape
// as the R182/R183 spell layers.
// ============================================================================

#pragma once

#include "../engine/classes.h"

#include <cstdint>
#include <string>

#include "items/MiscItemRegistry.h"   // R1048: the slot grids ride the registry

// ---- the R1048 slots registry seam ----------------------------
// The paladin and ranger spell-slot grids ride
// items::MiscItemRegistry from
// content/tables/class_slots/ (def keys
// paladin_slots, ranger_slots; tables[1]
// "grid", values flat row-major - the R1047
// grid encoding, but its OWN directory: the
// R1047 fragment pins class_grids at 3 defs).
// Header-only seam (the R1040-R1044 idiom);
// the accessor signatures and clamp semantics
// below are unchanged.

inline items::MiscItemRegistry& slotsReg() {
    static items::MiscItemRegistry reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        reg.loadDirectory("content/tables/class_slots");
    }
    return reg;
}

// the per-view cache (the R1032-R1044 idiom)
inline const std::vector<long long>&
slotValues(const char* name) {
    static std::map<std::string,
        std::vector<long long>> cache;
    auto it = cache.find(name);
    if (it == cache.end()) {
        std::vector<long long> v;
        const items::MiscItemDef* d =
            slotsReg().find(name);
        if (d && d->tables.size() == 1
            && d->tables[0].name == "grid")
            v = d->tables[0].values;
        it = cache.emplace(name, v).first;
    }
    return it->second;
}


namespace rules {

// ---- the paladin progression ----

// The clerical spell slots of spellLevel (1-4)
// usable by a paladin of paladinLevel. Below
// 9th level: 0 (no spell ability). Past 20th:
// the 20th row (maximum spell ability).
inline int paladinSpellSlots(int paladinLevel,
                        int spellLevel) {
    if (paladinLevel < 9) return 0;
    if (paladinLevel > 20) paladinLevel = 20;
    if (spellLevel < 1) spellLevel = 1;
    if (spellLevel > 4) spellLevel = 4;
    const auto& v = slotValues("paladin_slots");
    if (v.empty()) return 0;   // defensive: unloaded view
    return (int)v[(paladinLevel - 9) * 4
                 + (spellLevel - 1)];
}

// The shared-list wiring: the paladin casts
// cleric spells (never clerical scrolls).
inline int paladinSpellListClass() {
    return CLASS_CLERIC;
}

// ---- the ranger progression ----

// The ranger spell slots. kind 0 = druidic,
// 1 = magic-user; spellLevel 1-3 druidic, 1-2
// magic-user. Below 8th level: 0. Past 17th:
// the 17th row (maximum spell ability).
inline int rangerSpellSlots(int rangerLevel, int kind,
                       int spellLevel) {
    if (rangerLevel < 8) return 0;
    if (rangerLevel > 17) rangerLevel = 17;
    int col;
    if (kind == 0) {
        if (spellLevel < 1) spellLevel = 1;
        if (spellLevel > 3) spellLevel = 3;
        col = spellLevel;
    } else {
        if (spellLevel < 1) spellLevel = 1;
        if (spellLevel > 2) spellLevel = 2;
        col = spellLevel + 3;
    }
    const auto& v = slotValues("ranger_slots");
    if (v.empty()) return 0;   // defensive: unloaded view
    return (int)v[(rangerLevel - 8) * 5
                 + (col - 1)];
}

// The shared-list wiring: the ranger casts
// druid spells (the R182 roster, levels 1-3)
// and magic-user spells (levels 1-2).
inline int rangerDruidicSpellListClass() {
    return CLASS_CLERIC;   // the druid roster rides the cleric base (R179)
}

inline int rangerMagicSpellListClass() {
    return CLASS_MAGIC_USER;
}

// ---- the printed specials (the R184 box) ----

// Lay on hands: heals 2 hit points per paladin
// level of experience, once per day.
inline int paladinLayOnHandsHp(int paladinLevel) {
    if (paladinLevel < 1) return 0;
    return 2 * paladinLevel;
}

// Cure disease: once per week for each five
// levels of experience (1 through 5: one,
// 6 through 10: two, 11 through 15: three...).
inline int paladinCureDiseasePerWeek(int paladinLevel) {
    if (paladinLevel < 1) return 0;
    return (paladinLevel + 4) / 5;
}

// The giant-class roster: the 11 listed
// creatures (the print). Matching is by
// lowercase name equality.
inline int rangerGiantClassCount() { return 11; }

inline const char* rangerGiantClassName(int i) {
    static const char* const kNames[11] = {
        "bugbear",
        "ettin",
        "giant",
        "gnoll",
        "goblin",
        "hobgoblin",
        "kobold",
        "ogre",
        "ogre mage",
        "orc",
        "troll",
    };
    if (i < 0) i = 0;
    if (i > 10) i = 10;
    return kNames[i];
}

// True when the lowercase monster name is one
// of the 11 giant-class creatures.
inline bool rangerIsGiantClass(const char* name) {
    if (!name) return false;
    for (int i = 0; i < 11; ++i)
        if (std::string(name) == rangerGiantClassName(i))
            return true;
    return false;
}

// The giant-class damage bonus: +1 hit point
// per ranger experience level on a melee hit.
inline int rangerGiantClassBonus(int rangerLevel) {
    if (rangerLevel < 1) return 0;
    return rangerLevel;
}

} // namespace rules
