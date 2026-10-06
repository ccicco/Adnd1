// ============================================================================
// Adnd1 - rules/druidspells.h
// The druid spell layer (R182).
//
// The SPELLS USABLE BY CLASS AND LEVEL - DRUIDS table
// (14 druid levels x 7 spell levels, every printed cell)
// and the full druid spell roster - 77 spells with the
// printed level and the reversible flag. The druid
// spell-sourcing rules (the mistletoe religious symbol,
// the component-reduction percentages for lesser
// mistletoe / borrowed mistletoe / holly / oak leaves)
// are display and flavor; the metal-armor spoilage and
// the no-turn-undead notes are recorded in the R180
// gates round commentary.
//
// JUDGMENTs:
//   - the printed table dashes (no slots) pin as 0.
//   - the druid hierarchy tops at the 14th level; slot
//     queries past it clamp to the 14th-level row.
//   - the roster order is the printed alphabetical
//     order within each level (the DRUID SPELLS
//     section order).
//
// DATA-DRIVEN (the standing scope): a future spell list
// (the illusionist layer, the bard druidical casting)
// lands as its own roster file with the same shape.
// ============================================================================

#pragma once

#include <cstdint>

namespace rules {

// The number of spell slots of spellLevel (1-7) usable
// by a druid of druidLevel (1-14; past it, the 14th row).
inline int druidSpellSlots(int druidLevel, int spellLevel) {
    static const int kSlots[14][7] = {
        { 2, 0, 0, 0, 0, 0, 0 },
        { 2, 1, 0, 0, 0, 0, 0 },
        { 3, 2, 1, 0, 0, 0, 0 },
        { 4, 2, 2, 0, 0, 0, 0 },
        { 4, 3, 2, 0, 0, 0, 0 },
        { 4, 3, 2, 1, 0, 0, 0 },
        { 4, 4, 3, 1, 0, 0, 0 },
        { 4, 4, 3, 2, 0, 0, 0 },
        { 5, 4, 3, 2, 1, 0, 0 },
        { 5, 4, 3, 3, 2, 0, 0 },
        { 5, 5, 3, 3, 2, 1, 0 },
        { 5, 5, 4, 4, 3, 2, 1 },
        { 6, 5, 5, 5, 4, 3, 2 },
        { 6, 6, 6, 6, 5, 4, 3 },
    };
    if (druidLevel < 1) druidLevel = 1;
    if (druidLevel > 14) druidLevel = 14;
    if (spellLevel < 1) spellLevel = 1;
    if (spellLevel > 7) spellLevel = 7;
    return kSlots[druidLevel - 1][spellLevel - 1];
}

// ---- the roster (77 printed spells) ----

struct DruidSpell {
    int level;        // 1-7
    const char* name; // the printed name
    int reversible;   // the printed Reversible marker
};

static const DruidSpell kDruidSpells[77] = {
    { 1, "Animal Friendship", 0 },
    { 1, "Detect Magic", 0 },
    { 1, "Detect Snares & Pits", 0 },
    { 1, "Entangle", 0 },
    { 1, "Faerie Fire", 0 },
    { 1, "Invisibility To Animals", 0 },
    { 1, "Locate Animals", 0 },
    { 1, "Pass Without Trace", 0 },
    { 1, "Predict Weather", 0 },
    { 1, "Purify Water", 1 },
    { 1, "Shillelagh", 0 },
    { 1, "Speak With Animals", 0 },
    { 2, "Barkskin", 0 },
    { 2, "Charm Person Or Mammal", 0 },
    { 2, "Create Water", 0 },
    { 2, "Cure Light Wounds", 1 },
    { 2, "Feign Death", 0 },
    { 2, "Fire Trap", 0 },
    { 2, "Heat Metal", 1 },
    { 2, "Locate Plants", 0 },
    { 2, "Obscurement", 0 },
    { 2, "Produce Flame", 0 },
    { 2, "Trip", 0 },
    { 2, "Warp Wood", 0 },
    { 3, "Call Lightning", 0 },
    { 3, "Cure Disease", 1 },
    { 3, "Hold Animal", 0 },
    { 3, "Neutralize Poison", 1 },
    { 3, "Plant Growth", 0 },
    { 3, "Protection From Fire", 0 },
    { 3, "Pyrotechnics", 0 },
    { 3, "Snare", 0 },
    { 3, "Stone Shape", 0 },
    { 3, "Summon Insects", 0 },
    { 3, "Tree", 0 },
    { 3, "Water Breathing", 1 },
    { 4, "Animal Summoning I", 0 },
    { 4, "Call Woodland Beings", 0 },
    { 4, "Control Temperature, 10' Radius", 0 },
    { 4, "Cure Serious Wounds", 1 },
    { 4, "Dispel Magic", 0 },
    { 4, "Hallucinatory Forest", 1 },
    { 4, "Hold Plant", 0 },
    { 4, "Plant Door", 0 },
    { 4, "Produce Fire", 1 },
    { 4, "Protection From Lightning", 0 },
    { 4, "Repel Insects", 0 },
    { 4, "Speak With Plants", 0 },
    { 5, "Animal Growth", 1 },
    { 5, "Animal Summoning II", 0 },
    { 5, "Anti-Plant Shell", 0 },
    { 5, "Commune With Nature", 0 },
    { 5, "Control Winds", 0 },
    { 5, "Insect Plague", 0 },
    { 5, "Wall of Fire", 0 },
    { 5, "Pass Plant", 0 },
    { 6, "Animal Summoning III", 0 },
    { 6, "Anti-Animal Shell", 0 },
    { 6, "Sticks to Snakes", 1 },
    { 6, "Conjure Fire Elemental", 1 },
    { 6, "Transmute Rock to Mud", 1 },
    { 6, "Cure Critical Wounds", 1 },
    { 6, "Feeblemind", 0 },
    { 6, "Transport Via Plants", 0 },
    { 6, "Turn Wood", 0 },
    { 6, "Wall of Thorns", 0 },
    { 6, "Weather Summoning", 0 },
    { 6, "Confusion", 0 },
    { 7, "Animate Rock", 0 },
    { 7, "Conjure Earth Elemental", 1 },
    { 7, "Control Weather", 0 },
    { 7, "Chariot Of Sustarre", 0 },
    { 7, "Creeping Doom", 0 },
    { 7, "Finger Of Death", 0 },
    { 7, "Fire Storm", 1 },
    { 7, "Reincarnate", 0 },
    { 7, "Transmute Metal To Wood", 0 },
};

inline int druidSpellTotal() { return 77; }

inline const DruidSpell& druidSpell(int i) {
    if (i < 0) i = 0;
    if (i > 76) i = 76;
    return kDruidSpells[i];
}

// The number of roster spells of the given level
// (12/12/12/12/8/12/9).
inline int druidSpellCountByLevel(int spellLevel) {
    if (spellLevel < 1) spellLevel = 1;
    if (spellLevel > 7) spellLevel = 7;
    static const int kByLevel[7] =
        { 12, 12, 12, 12, 8, 12, 9 };
    return kByLevel[spellLevel - 1];
}

// ---------------------------------------------------------------------------
// R228: the registry parameter seam. The R182 roster carries
// identity (level, name, reversible); these tables carry the
// per-spell registry parameters extracted from the PHB spell
// description headers (Level/Range/Duration/Area of
// Effect/Casting Time/Saving Throw blocks), in the engine
// SpellDef conventions:
//   - ct: casting time in SEGMENTS (a printed turn is 60,
//     a printed round 10; Special pins 0);
//   - range: tens of feet (Touch pins 0);
//   - dur: base ROUNDS (a per-level scale pins its base
//     number - the scaling itself is an effects-round
//     concern; Permanent/Special pin 0; a turn is 10);
//   - aoe: radius in TENS of feet where the print gives a
//     circle (diameter halves, round up); paths, cubes,
//     linear feet and square miles pin 0;
//   - save: rules::SaveCategory (-1 none; the printed
//     Neg./half pins SAVE_SPELLS = 4);
//   - target: the SpellTarget enum value.
// JUDGMENTs (the OCR-scattered blocks): Entangle (table-form
// header read directly), Invisibility To Animals, Faerie Fire,
// Insect Plague (mirrors the cleric q.v. row: ct 5, save
// none), Conjure Fire Elemental (ct 6 rounds = 60; save
// none), Weather Summoning (ct 1 turn = 60, the
// control-weather q.v.), Animate Rock (ct 1 turn = 60, save
// none), Conjure Earth Elemental (ct 9 segments, save none).
// The spells.cpp registry rows carry the same values; the
// R228 battery walks the match.
// ---------------------------------------------------------------------------


inline int druidSpellLevel(int i) {
        static const int kLevel[77] = {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 3, 3, 3, 3, 3, 3,
        3, 3, 3, 3, 3, 3, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 5, 5,
        5, 5, 5, 5, 5, 5, 6, 6, 6, 6,
        6, 6, 6, 6, 6, 6, 6, 6, 7, 7,
        7, 7, 7, 7, 7, 7, 7,
    };
    if (i < 0) i = 0;
    if (i > 76) i = 76;
    return kLevel[i];
}

inline int druidSpellRev(int i) {
        static const int kRev[77] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 1, 0, 0, 1, 0,
        0, 0, 0, 0, 0, 1, 0, 1, 0, 0,
        0, 0, 0, 0, 0, 1, 0, 0, 0, 1,
        0, 1, 0, 0, 1, 0, 0, 0, 1, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
        1, 1, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 1, 0, 0,
    };
    if (i < 0) i = 0;
    if (i > 76) i = 76;
    return kRev[i];
}

inline int druidSpellCt(int i) {
        static const int kCt[77] = {
        360, 3, 3, 3, 3, 4, 10, 10, 10, 10,
        1, 3, 3, 4, 60, 4, 3, 60, 4, 10,
        4, 4, 4, 4, 60, 10, 5, 5, 10, 5,
        5, 30, 10, 10, 5, 5, 6, 0, 6, 6,
        6, 6, 6, 6, 6, 6, 10, 60, 7, 7,
        7, 60, 7, 5, 60, 7, 8, 10, 7, 60,
        7, 8, 8, 3, 8, 8, 60, 60, 60, 9,
        60, 60, 9, 5, 9, 60, 9,
    };
    if (i < 0) i = 0;
    if (i > 76) i = 76;
    return kCt[i];
}

inline int druidSpellRangeTens(int i) {
        static const int kRng[77] = {
        1, 0, 0, 8, 8, 0, 0, 0, 0, 4,
        0, 0, 0, 8, 1, 0, 1, 0, 4, 0,
        0, 0, 0, 1, 0, 0, 8, 0, 16, 0,
        16, 0, 0, 3, 0, 0, 4, 12, 0, 0,
        8, 8, 8, 0, 4, 0, 0, 0, 8, 6,
        0, 0, 0, 32, 8, 0, 8, 0, 4, 8,
        16, 0, 16, 0, 0, 8, 0, 8, 4, 4,
        0, 1, 0, 6, 16, 0, 8,
    };
    if (i < 0) i = 0;
    if (i > 76) i = 76;
    return kRng[i];
}

inline int druidSpellDur(int i) {
        static const int kDur[77] = {
        0, 12, 4, 10, 4, 10, 1, 10, 120, 0,
        1, 2, 4, 0, 0, 0, 4, 0, 7, 10,
        4, 2, 10, 0, 10, 0, 2, 0, 0, 0,
        0, 0, 0, 1, 60, 60, 0, 0, 40, 0,
        0, 0, 1, 10, 1, 0, 10, 2, 2, 0,
        10, 0, 10, 10, 0, 0, 0, 10, 2, 10,
        0, 0, 0, 0, 4, 10, 0, 1, 1, 10,
        0, 60, 4, 0, 1, 0, 0,
    };
    if (i < 0) i = 0;
    if (i > 76) i = 76;
    return kDur[i];
}

inline int druidSpellAoeTens(int i) {
        static const int kAoe[77] = {
        0, 0, 0, 2, 4, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 36, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
        0, 0, 0, 0, 0, 0, 1, 4, 0, 0,
        1, 0, 0, 2, 0, 0, 0, 1, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,
    };
    if (i < 0) i = 0;
    if (i > 76) i = 76;
    return kAoe[i];
}

inline int druidSpellSaveCat(int i) {
        static const int kSave[77] = {
        4, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, 4, -1, -1, -1, 4, -1, -1,
        -1, -1, 4, -1, 4, -1, 4, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, 4, -1, -1,
        -1, -1, 4, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, 4, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, 4, 4, -1, -1,
    };
    if (i < 0) i = 0;
    if (i > 76) i = 76;
    return kSave[i];
}

inline int druidSpellTarget(int i) {
        static const int kTgt[77] = {
        1, 2, 2, 2, 2, 1, 2, 1, 4, 2,
        4, 1, 1, 1, 2, 1, 1, 4, 4, 2,
        4, 4, 4, 4, 2, 1, 1, 1, 2, 1,
        4, 2, 2, 4, 0, 1, 4, 4, 2, 1,
        2, 2, 4, 4, 2, 1, 2, 2, 2, 4,
        2, 4, 2, 2, 4, 4, 4, 2, 2, 4,
        2, 1, 1, 4, 2, 2, 4, 2, 4, 4,
        4, 4, 4, 1, 2, 1, 4,
    };
    if (i < 0) i = 0;
    if (i > 76) i = 76;
    return kTgt[i];
}
} // namespace rules
