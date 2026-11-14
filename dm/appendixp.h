// ============================================================================
// Adnd1 - dm/appendixp.h
// R147: DMG pp.225-226 - APPENDIX P, CREATING A PARTY ON
// THE SPUR OF THE MOMENT. Pure data + rollers,
// header-only (the appendixa.h pattern: the caller
// decides when to roll; any table luck beyond a row is
// the caller's). Transcribed from the 1eonline.info
// compilation - the repo-trusted source; the DMG
// re-upload's OCR debt stands (the compilation's own
// prose typos - "far" for "for", "fallowing" - carry no
// data and stay unpinned).
//
// Conventions, all named in place:
//   - classIndex is the engine's four (0 fighter,
//     1 magic-user, 2 cleric, 3 thief - CharClass). The
//     book's subclass and UA/OA rows (cavalier, paladin,
//     ranger, druid, barbarian, illusionist, assassin,
//     monk) are the book's own variants - out of scope.
//   - "Only one sort may be tried for" (both armor and
//     weapons): rollMemberMagic tries exactly one armor
//     category and one weapon category per member.
//   - A printed dash (never) encodes as 0 percent.
//   - The potion list prints "0. Polymorph Self"; the
//     roller types run 1-10 with 10 = that entry.
// ============================================================================

#pragma once

#include "../rules/engine/dice.h"
#include "EncounterTableRegistry.h"   // R1040: the kit tables ride the registry

namespace dm {
namespace appendixp {

// ---- LEVEL (p.225): three printed options per band -----

// R1040 (the registry-native de-wire, the R1032-R1039 shape):
// the printed pp.225-226 tables retired into
// content/tables/appendixp/ (six files; the gear tables
// transposed to one row per printed column). This seam is
// header-only like the module: the registry rides its own
// inline singleton below (encReg() in encounters.cpp is
// file-static and out of reach from a header - the load is
// this module's own concern). Every signature above and
// below is unchanged (rules/audits/r147_appendix_p.h and
// r156_convention_party.h pin them); the mechanics - the
// abilityRoll, the itemChance chain with the Gonzo worked
// example, rollItemPlus, the member builders - stay verbatim.

inline dm::EncounterTableRegistry& apReg() {
    static dm::EncounterTableRegistry reg;
    static bool loaded = false;
    if (!loaded) {
        loaded = true;
        reg.loadDirectory("content/tables/appendixp");
    }
    return reg;
}

// the registry-backed per-TU static cache (the R1032-R1039
// idiom; function-local statics in inline functions are
// shared across TUs)
inline const std::vector<dm::EncounterAppendixPRow>& apView(
        const char* name) {
    static std::map<std::string,
        std::vector<dm::EncounterAppendixPRow>> cache;
    auto it = cache.find(name);
    if (it == cache.end())
        it = cache.emplace(
            name, apReg().appendixPRows(name)).first;
    return it->second;
}

enum LevelBand { BAND_LOW = 0, BAND_MEDIUM, BAND_UPPER };

inline int bandLevelLo(int band, int option) {
    if (band < 0) band = 0;
    if (band > 2) band = 2;
    if (option < 0) option = 0;
    if (option > 2) option = 2;
    for (const auto& r : apView("appendixp_band_level"))
        if (r.band == band + 1 && r.option == option + 1)
            return r.lo;
    return 1;   // defensive: the printed table covers 3x3
}

inline int bandLevelHi(int band, int option) {
    if (band < 0) band = 0;
    if (band > 2) band = 2;
    if (option < 0) option = 0;
    if (option > 2) option = 2;
    for (const auto& r : apView("appendixp_band_level"))
        if (r.band == band + 1 && r.option == option + 1)
            return r.hi;
    return 2;   // defensive: the printed table covers 3x3
}

// ---- ABILITIES (p.225): 4d6, discard the low die -------
inline int abilityRoll(rules::Dice& dice) {
    return (int)dice.bestOf(4, 6, 3);
}

// ---- PROTECTIVE ITEMS TABLE (p.225) ---------------------
// Per-level chance for shield, armor, etc. (typically
// +1). Columns: 0 shield, 1 plate, 2 banded, 3 chain,
// 4 leather, 5 ring of protection, 6 bracers (of AC 6
// value). Rows: 0 fighter, 1 magic-user, 2 cleric,
// 3 thief.
inline int protectivePct(int classIndex, int col) {
    if (classIndex < 0) classIndex = 0;
    if (classIndex > 3) classIndex = 3;
    if (col < 0) col = 0;
    if (col > 6) col = 6;
    for (const auto& r : apView("appendixp_protective"))
        if (r.lo == col + 1)
            return classIndex == 0 ? r.fighter
                 : classIndex == 1 ? r.magic_user
                 : classIndex == 2 ? r.cleric
                 : r.thief;
    return 0;   // defensive: a printed dash encodes as 0
}

// ---- WEAPONS TABLE (p.225-226) -------------------------
// Columns: 0 dagger, 1 sword, 2 mace, 3 battle axe,
// 4 spear, 5 bow, 6 the 15 bolts +2. Same row order.
inline int weaponPct(int classIndex, int col) {
    if (classIndex < 0) classIndex = 0;
    if (classIndex > 3) classIndex = 3;
    if (col < 0) col = 0;
    if (col > 6) col = 6;
    for (const auto& r : apView("appendixp_weapons"))
        if (r.lo == col + 1)
            return classIndex == 0 ? r.fighter
                 : classIndex == 1 ? r.magic_user
                 : classIndex == 2 ? r.cleric
                 : r.thief;
    return 0;   // defensive: a printed dash encodes as 0
}

// ---- POTIONS TABLE (p.226) -----------------------------
// Per-level chance of having a potion, the max carried,
// and the 10 printed types (roll 10 = the book's "0.",
// Polymorph Self).
inline int potionPct(int classIndex) {
    if (classIndex < 0) classIndex = 0;
    if (classIndex > 3) classIndex = 3;
    for (const auto& r : apView("appendixp_potions"))
        if (r.lo == classIndex + 1)
            return r.pct;
    return 0;   // defensive
}

inline int potionMax(int classIndex) {
    if (classIndex < 0) classIndex = 0;
    if (classIndex > 3) classIndex = 3;
    for (const auto& r : apView("appendixp_potions"))
        if (r.lo == classIndex + 1)
            return r.max;
    return 1;   // defensive
}

inline const char* potionType(int roll) {
    if (roll < 1) roll = 1;
    if (roll > 10) roll = 10;
    for (const auto& r : apView("appendixp_potion_types"))
        if (r.lo == roll)
            return r.key.c_str();
    return "";   // defensive: the table covers 1-10
}

// ---- THE CHANCE CHAIN (p.225) --------------------------
// Item chance: level x percentage. Above-average (+2,
// or bracers AC 5): 1% per level, plus any excess over
// 90% in the item chance folded in. Above that, +3 (or
// bracers AC 4) on a straight 1% per level. Gonzo's
// worked example: 15%/level chain at 9th = 135%, +2
// chance 9 + 45 = 54 (rolled 51 -> at least +2), +3
// check 9 (rolled 99 -> just +2).
inline int itemChancePct(int pct, int level) {
    if (level < 1) level = 1;
    return pct * level;
}

inline int plusTwoChancePct(int pct, int level) {
    if (level < 1) level = 1;
    int c = pct * level;
    int excess = c > 90 ? c - 90 : 0;
    return level + excess;
}

inline int plusThreeChancePct(int level) {
    if (level < 1) level = 1;
    return level;
}

// The full chain: 0 = none, else the plus (1-3).
inline int rollItemPlus(rules::Dice& dice, int pct, int level) {
    if (pct <= 0) return 0;
    if (level < 1) level = 1;
    if ((int)dice.d100() > itemChancePct(pct, level)) return 0;
    if ((int)dice.d100() <= plusTwoChancePct(pct, level)) {
        if ((int)dice.d100() <= plusThreeChancePct(level))
            return 3;
        return 2;
    }
    return 1;
}

// ---- KIT BUILDER ---------------------------------------
// One member's magic kit: one armor sort (the book's
// only-one-sort rule), one weapon sort, and a shield try
// for the armored classes. The class picks:
//   armor  - fighter chain 10%, MU ring 15%, cleric
//            chain 8%, thief leather 10%
//   weapon - fighter sword 10%, MU dagger 15%, cleric
//            mace 12%, thief sword 11%
//   shield - fighter and cleric, both at 10%
struct MemberMagic {
    int armorPlus  = 0;   // 0 = none
    int weaponPlus = 0;
    int shieldPlus = 0;
};

inline MemberMagic rollMemberMagic(rules::Dice& dice,
                                   int classIndex, int level) {
    if (classIndex < 0) classIndex = 0;
    if (classIndex > 3) classIndex = 3;
    MemberMagic m;
    const dm::EncounterAppendixPRow* k = nullptr;
    for (const auto& r : apView("appendixp_kit"))
        if (r.lo == classIndex + 1) { k = &r; break; }
    if (!k) return m;   // defensive: the table covers 1-4
    m.armorPlus  = rollItemPlus(dice, k->armorPct, level);
    m.weaponPlus = rollItemPlus(dice, k->weaponPct, level);
    // the shield try is the armored classes' printed row
    // (fighter and cleric at 10%; the others carry none)
    if (classIndex == 0 || classIndex == 2)
        m.shieldPlus = rollItemPlus(dice, k->shieldPct, level);
    return m;
}

// ----
// R156: THE SPUR-OF-THE-MOMENT MEMBER (pp.225-226) - the
// convention character pre-roll: the band/option level
// roll, the six 4d6-best-of ability scores (the book has
// the player arrange as desired - the engine just
// supplies the six), and the magic kit. Multi-class level
// math and alignment curation are player-side and stay
// out of the engine.
struct SpurMember {
    int classIndex = 0;          // engine class (caller-chosen)
    int level = 1;               // rolled in the band
    int abilities[6] = {0, 0, 0, 0, 0, 0};   // STR INT WIS DEX CON CHA
    MemberMagic kit;
};

inline SpurMember rollSpurMember(rules::Dice& dice, int band,
                                 int option, int classIndex) {
    if (classIndex < 0) classIndex = 0;
    if (classIndex > 3) classIndex = 3;
    SpurMember m;
    m.classIndex = classIndex;
    int lo = bandLevelLo(band, option);
    int hi = bandLevelHi(band, option);
    m.level = lo + (int)dice.roll(1, (uint32_t)(hi - lo + 1), 0) - 1;
    for (int i = 0; i < 6; ++i)
        m.abilities[i] = abilityRoll(dice);
    m.kit = rollMemberMagic(dice, classIndex, m.level);
    return m;
}

} // namespace appendixp
} // namespace dm