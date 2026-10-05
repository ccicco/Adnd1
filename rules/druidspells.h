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

} // namespace rules
