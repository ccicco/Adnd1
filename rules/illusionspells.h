// ============================================================================
// Adnd1 - rules/illusionspells.h
// The illusionist spell layer (R183).
//
// The SPELLS USABLE BY CLASS AND LEVEL - ILLUSIONISTS table
// (26 illusionist levels x 7 spell levels, every printed
// cell) and the full illusionist spell roster - 61 spells
// in the printed book order (the PHB illusionist section).
//
// JUDGMENTs:
//   - the printed table dashes (no slots) pin as 0.
//   - the illusionist section prints NO Reversible
//     markers (unlike the druid list): Continual Darkness
//     and Continual Light are separate listed spells, not
//     reverses of one another; the roster carries no
//     reversible flag.
//   - the roster order is the printed section order, not
//     alphabetical (the book order within each level).
//   - the printed table runs to illusionist level 26; slot
//     queries past it clamp to the 26th-level row.
//
// DATA-DRIVEN (the standing scope): the same roster shape
// as the druid layer (R182); a future list lands the same
// way.
// ============================================================================

#pragma once

#include <cstdint>

namespace rules {

// The number of spell slots of spellLevel (1-7) usable
// by an illusionist of illusionistLevel (1-26; past it,
// the 26th row).
inline int illusionistSpellSlots(int illusionistLevel,
                           int spellLevel) {
    static const int kSlots[26][7] = {
        { 1, 0, 0, 0, 0, 0, 0 },
        { 2, 0, 0, 0, 0, 0, 0 },
        { 2, 1, 0, 0, 0, 0, 0 },
        { 3, 2, 0, 0, 0, 0, 0 },
        { 4, 2, 1, 0, 0, 0, 0 },
        { 4, 3, 1, 0, 0, 0, 0 },
        { 4, 3, 2, 0, 0, 0, 0 },
        { 4, 3, 2, 1, 0, 0, 0 },
        { 5, 3, 3, 2, 0, 0, 0 },
        { 5, 4, 3, 2, 1, 0, 0 },
        { 5, 4, 3, 3, 2, 0, 0 },
        { 5, 5, 4, 3, 2, 1, 0 },
        { 5, 5, 4, 3, 2, 2, 0 },
        { 5, 5, 4, 3, 2, 2, 1 },
        { 5, 5, 4, 4, 2, 2, 2 },
        { 5, 5, 5, 4, 3, 2, 2 },
        { 5, 5, 5, 5, 3, 2, 2 },
        { 5, 5, 5, 5, 3, 3, 2 },
        { 5, 5, 5, 5, 4, 3, 2 },
        { 5, 5, 5, 5, 4, 3, 3 },
        { 5, 5, 5, 5, 5, 4, 3 },
        { 5, 5, 5, 5, 5, 5, 4 },
        { 5, 5, 5, 5, 5, 5, 5 },
        { 6, 6, 6, 6, 5, 5, 5 },
        { 6, 6, 6, 6, 6, 6, 6 },
        { 7, 7, 7, 7, 6, 6, 6 },
    };
    if (illusionistLevel < 1) illusionistLevel = 1;
    if (illusionistLevel > 26) illusionistLevel = 26;
    if (spellLevel < 1) spellLevel = 1;
    if (spellLevel > 7) spellLevel = 7;
    return kSlots[illusionistLevel - 1][spellLevel - 1];
}

// ---- the roster (61 printed spells) ----

struct IllusionistSpell {
    int level;        // 1-7
    const char* name; // the printed name
};

static const IllusionistSpell kIllusionistSpells[61] = {
    { 1, "Audible Glamer" },
    { 1, "Detect Invisibility" },
    { 1, "Change Self" },
    { 1, "Gaze Reflection" },
    { 1, "Hypnotism" },
    { 1, "Light" },
    { 1, "Phantasmal Force" },
    { 1, "Wall Of Fog" },
    { 2, "Blindness" },
    { 2, "Blur" },
    { 2, "Deafness" },
    { 2, "Detect Magic" },
    { 2, "Fog Cloud" },
    { 2, "Hypnotic Pattern" },
    { 2, "Improved Phantasmal Force" },
    { 2, "Invisibility" },
    { 2, "Dispel Illusion" },
    { 2, "Magic Mouth" },
    { 2, "Fear" },
    { 2, "Mirror Image" },
    { 2, "Hallucinatory Terrain" },
    { 2, "Misdirection" },
    { 2, "Illusionary Script" },
    { 2, "Ventriloquism" },
    { 3, "Invisibility, 10' Radius" },
    { 3, "Continual Darkness" },
    { 3, "Continual Light" },
    { 3, "Non-detection" },
    { 3, "Emotion" },
    { 3, "Paralyzation" },
    { 3, "Rope Trick" },
    { 3, "Spectral Force" },
    { 3, "Improved Invisibility" },
    { 3, "Suggestion" },
    { 3, "Massmorph" },
    { 4, "Confusion" },
    { 4, "Dispel Exhaustion" },
    { 4, "Minor Creation" },
    { 4, "Phantasmal Killer" },
    { 4, "Shadow Monsters" },
    { 5, "Chaos" },
    { 5, "Demi-Shadow Monsters" },
    { 5, "Major Creation" },
    { 5, "Maze" },
    { 5, "Projected Image" },
    { 5, "Mass Suggestion" },
    { 5, "Shadow Door" },
    { 5, "Permanent Illusion" },
    { 5, "Shadow Magic" },
    { 5, "Programmed Illusion" },
    { 5, "Summon Shadow" },
    { 5, "Shades" },
    { 6, "Conjure Animals" },
    { 6, "True Sight" },
    { 6, "Demi-Shadow Magic" },
    { 6, "Veil" },
    { 7, "Alter Reality" },
    { 7, "Astral Spell" },
    { 7, "Prismatic Spray" },
    { 7, "Prismatic Wall" },
    { 7, "Vision" },
};

inline int illusionistSpellTotal() { return 61; }

inline const IllusionistSpell& illusionistSpell(int i) {
    if (i < 0) i = 0;
    if (i > 60) i = 60;
    return kIllusionistSpells[i];
}

// The number of roster spells of the given level
// (8/16/11/5/12/4/5).
inline int illusionistSpellCountByLevel(int spellLevel) {
    if (spellLevel < 1) spellLevel = 1;
    if (spellLevel > 7) spellLevel = 7;
    static const int kByLevel[7] =
        { 8, 16, 11, 5, 12, 4, 5 };
    return kByLevel[spellLevel - 1];
}

// ---------------------------------------------------------------------------
// R229: the registry parameter seam. The R183 roster carries
// identity (level, name - the illusionist print carries no
// reversible markers); these tables carry the per-spell registry
// parameters extracted from the PHB illusionist spell
// description headers, in the engine SpellDef conventions
// (the R228 druid conventions):
//   - ct: casting time in SEGMENTS (a printed turn 60, a
//     round 10; Special pins 0);
//   - range: tens of feet (Touch/Unlimited/Special 0; a
//     per-level scale pins its base; a printed half-inch
//     pins 0);
//   - dur: base ROUNDS (a per-level scale pins its base;
//     Permanent/Special/Instantaneous 0; a turn 10);
//   - aoe: radius in TENS of feet where the print gives a
//     circle; squares/paths/cubes pin 0;
//   - save: -1 none/Special; the printed Neg. pins
//     SAVE_SPELLS = 4;
//   - target: the SpellTarget enum value.
// The OCR-scattered blocks pinned as JUDGMENTs (the section
// interleaves neighbors; the q.v. MU/cleric prints close the
// chains): Detect Invisibility (save None, the q.v. MU print),
// Invisibility (the q.v. MU print: Touch/Special/CT 2/None),
// Dispel Illusion (the resident 2nd-level set: 1"/level,
// Permanent, Special, CT 3, None), Fear (CT 4/Neg., the q.v.
// MU fear print), Hallucinatory Terrain (R 2"+2"/level,
// D Special, AoE 4"x4", CT 5 rounds = 50, SV None),
// Invisibility 10' Radius (the q.v. MU 3rd print: Touch,
// Special, CT 3, None, 10' radius), Continual Light (CT 3/
// None, the pair scattered into the Non-detection region),
// Emotion (the twin Level-3 set: 1"/level, Special, 4"x4",
// CT 3, Neg.), Mass Suggestion (R 3/CT 6 in its block; the
// duration 4 turns + 4 turns/level and the one
// creature/level area recovered from the mis-scattered
// lines; SV Neg., the suggestion ladder), Permanent
// Illusion (SV Special, the spectral force q.v.), Conjure
// Animals (CT 9/None, the q.v. cleric 6th print),
// Demi-Shadow Magic (CT 5/Special, the shadow magic q.v.),
// Alter Reality (TARGET_SELF - the engine's MU row and the
// R129 caster-aging convention; the print's AoE is Special).
// Six blocks print a Level: divergent from the roster
// (Dispel Illusion 3, Fear 3, Hallucinatory Terrain 3,
// Illusionary Script 3, Improved Invisibility 4, Massmorph 4)
// - the printed TABLE (R183) wins.
// ---------------------------------------------------------------------------
inline int illusionistSpellLevel(int i) {
    static const int kLevel[61] = {
        1, 1, 1, 1, 1, 1, 1, 1, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 3, 3, 3, 3, 3, 3,
        3, 3, 3, 3, 3, 4, 4, 4, 4, 4,
        5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
        5, 5, 6, 6, 6, 6, 7, 7, 7, 7,
        7,
    };
    if (i < 0) i = 0;
    if (i > 60) i = 60;
    return kLevel[i];
}
inline int illusionistSpellCt(int i) {
    static const int kCt[61] = {
        5, 1, 1, 1, 1, 1, 1, 1, 2, 2,
        2, 2, 2, 2, 2, 2, 3, 2, 4, 2,
        50, 2, 0, 2, 3, 3, 3, 3, 3, 3,
        3, 3, 4, 3, 4, 4, 4, 60, 4, 4,
        5, 5, 60, 5, 5, 6, 2, 6, 5, 6,
        5, 6, 9, 10, 5, 3, 0, 180, 7, 7,
        7,
    };
    if (i < 0) i = 0;
    if (i > 60) i = 60;
    return kCt[i];
}
inline int illusionistSpellRangeTens(int i) {
    static const int kRangeTens[61] = {
        6, 1, 0, 0, 3, 6, 6, 3, 3, 0,
        6, 0, 1, 0, 6, 0, 1, 0, 0, 0,
        2, 3, 0, 1, 0, 6, 6, 0, 1, 1,
        0, 6, 0, 3, 1, 8, 0, 0, 0, 3,
        0, 3, 1, 0, 0, 3, 1, 1, 5, 1,
        1, 3, 3, 0, 6, 1, 0, 0, 0, 1,
        0,
    };
    if (i < 0) i = 0;
    if (i > 60) i = 60;
    return kRangeTens[i];
}
inline int illusionistSpellDur(int i) {
    static const int kDurRounds[61] = {
        3, 5, 2, 1, 1, 10, 0, 2, 0, 3,
        0, 2, 4, 0, 0, 0, 0, 0, 0, 3,
        0, 1, 0, 4, 0, 0, 0, 10, 0, 0,
        20, 0, 4, 40, 0, 1, 30, 60, 1, 1,
        1, 1, 60, 0, 1, 40, 40, 0, 0, 0,
        1, 1, 1, 1, 0, 10, 0, 0, 0, 10,
        0,
    };
    if (i < 0) i = 0;
    if (i > 60) i = 60;
    return kDurRounds[i];
}
inline int illusionistSpellAoeTens(int i) {
    static const int kAoeTens[61] = {
        0, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 3, 6, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0,
    };
    if (i < 0) i = 0;
    if (i > 60) i = 60;
    return kAoeTens[i];
}
inline int illusionistSpellSaveCat(int i) {
    static const int kSaveCat[61] = {
        -1, -1, -1, -1, 4, -1, -1, -1, 4, -1,
        4, -1, -1, 4, -1, -1, -1, -1, 4, -1,
        -1, 4, -1, -1, -1, -1, -1, -1, 4, 4,
        -1, -1, -1, 4, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, 4, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1,
    };
    if (i < 0) i = 0;
    if (i > 60) i = 60;
    return kSaveCat[i];
}
inline int illusionistSpellTarget(int i) {
    static const int kTarget[61] = {
        4, 2, 0, 4, 3, 2, 2, 4, 1, 0,
        1, 2, 2, 2, 2, 1, 4, 4, 2, 0,
        2, 4, 1, 4, 2, 2, 2, 0, 2, 2,
        4, 2, 1, 1, 2, 2, 3, 4, 1, 2,
        2, 2, 4, 1, 4, 3, 4, 2, 4, 2,
        2, 2, 4, 1, 4, 2, 0, 4, 2, 4,
        0,
    };
    if (i < 0) i = 0;
    if (i > 60) i = 60;
    return kTarget[i];
}
} // namespace rules
