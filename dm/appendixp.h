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

#include "../rules/dice.h"

namespace dm {
namespace appendixp {

// ---- LEVEL (p.225): three printed options per band -----
enum LevelBand { BAND_LOW = 0, BAND_MEDIUM, BAND_UPPER };

inline int bandLevelLo(int band, int option) {
    static const int lo[3][3] = {
        { 1, 1, 2 },    // low: 1-2 / 1-3 / 2-4
        { 5, 5, 7 },    // medium: 5-7 / 5-8 / 7-9
        { 8, 8, 9 },    // upper: 8-10 / 8-11 / 9-12
    };
    if (band < 0) band = 0;
    if (band > 2) band = 2;
    if (option < 0) option = 0;
    if (option > 2) option = 2;
    return lo[band][option];
}

inline int bandLevelHi(int band, int option) {
    static const int hi[3][3] = {
        { 2, 3, 4 },
        { 7, 8, 9 },
        { 10, 11, 12 },
    };
    if (band < 0) band = 0;
    if (band > 2) band = 2;
    if (option < 0) option = 0;
    if (option > 2) option = 2;
    return hi[band][option];
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
    static const int t[4][7] = {
        { 10, 6, 8, 10,  0,  0, 0 },   // fighter
        {  0, 0, 0,  0,  0, 15, 4 },   // magic-user
        { 10, 5, 6,  8,  0,  2, 0 },   // cleric
        {  0, 0, 0,  0, 10,  4, 0 },   // thief
    };
    if (classIndex < 0) classIndex = 0;
    if (classIndex > 3) classIndex = 3;
    if (col < 0) col = 0;
    if (col > 6) col = 6;
    return t[classIndex][col];
}

// ---- WEAPONS TABLE (p.225-226) -------------------------
// Columns: 0 dagger, 1 sword, 2 mace, 3 battle axe,
// 4 spear, 5 bow, 6 the 15 bolts +2. Same row order.
inline int weaponPct(int classIndex, int col) {
    static const int t[4][7] = {
        { 10, 10,  0, 7, 8, 1, 10 },   // fighter
        { 15,  0,  0, 0, 0, 0,  0 },   // magic-user
        {  0,  0, 12, 0, 0, 0,  0 },   // cleric
        { 12, 11,  0, 0, 0, 0,  0 },   // thief
    };
    if (classIndex < 0) classIndex = 0;
    if (classIndex > 3) classIndex = 3;
    if (col < 0) col = 0;
    if (col > 6) col = 6;
    return t[classIndex][col];
}

// ---- POTIONS TABLE (p.226) -----------------------------
// Per-level chance of having a potion, the max carried,
// and the 10 printed types (roll 10 = the book's "0.",
// Polymorph Self).
inline int potionPct(int classIndex) {
    static const int t[4] = { 8, 10, 6, 9 };
    if (classIndex < 0) classIndex = 0;
    if (classIndex > 3) classIndex = 3;
    return t[classIndex];
}

inline int potionMax(int classIndex) {
    static const int t[4] = { 1, 3, 1, 2 };
    if (classIndex < 0) classIndex = 0;
    if (classIndex > 3) classIndex = 3;
    return t[classIndex];
}

inline const char* potionType(int roll) {
    static const char* const k[10] = {
        "Climbing", "Diminution", "Extra-Healing",
        "Fire Resistance", "Flying", "Gaseous Form",
        "Growth", "Healing", "Invisibility",
        "Polymorph Self",
    };
    if (roll < 1) roll = 1;
    if (roll > 10) roll = 10;
    return k[roll - 1];
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
    static const int kArmor[4]  = { 10, 15, 8, 10 };
    static const int kWeapon[4] = { 10, 15, 12, 11 };
    if (classIndex < 0) classIndex = 0;
    if (classIndex > 3) classIndex = 3;
    MemberMagic m;
    m.armorPlus  = rollItemPlus(dice, kArmor[classIndex], level);
    m.weaponPlus = rollItemPlus(dice, kWeapon[classIndex], level);
    if (classIndex == 0 || classIndex == 2)
        m.shieldPlus = rollItemPlus(dice, 10, level);
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