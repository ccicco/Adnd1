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

} // namespace rules
