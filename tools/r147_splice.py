#!/usr/bin/env python3
# tools/r147_splice.py - R147, three independent lanes:
#
# (a) DWARF CON MAGIC-SAVE BONUS (PHB p.16, the standing
#     approximation R144 named): rules::dwarfConSaveBonus -
#     con*2/7 clamped 0..5, matching every printed band
#     (4-6 +1, 7-10 +2, 11-13 +3, 14-17 +4, 18+ +5). NPC
#     foes carry the p.176 race roll on the Actor (the two
#     race-only bands, half-elf 61-85 / half-orc 96-00,
#     previously fell through unnamed); asTarget lands the
#     bonus on the TargetDesc, and spelleffects::trySave +
#     the ai trySaveVs helper apply it to wands / spells /
#     death-poison saves only. Party PCs are human - only
#     NPC-foe dwarves benefit.
# (b) MATRIX II FOOTNOTE D (DMG p.80): non-intelligence
#     saves at half hit dice rounded up - half the II.B-
#     stepped level - except vs. death/poison. Pinned as
#     spelleffects::effectiveSaveLevel (inline, public -
#     both consumers link it); toActor maps MM intelligence
#     "non" (containsCI, no dash - "non-" wordings are
#     average-and-up, not the animal mind; exactly 90 of
#     the 408, census-pinned; "animal" keeps II.B, a named
#     judgment call).
# (c) APPENDIX P (DMG pp.225-226, creating a party on the
#     spur of the moment): NEW header-only dm/appendixp.h,
#     the appendixa.h pattern (data + rollers, the caller
#     decides when). Level bands, 4d6-drop-lowest ability
#     rolls, the protective + weapons per-level percentage
#     tables (the four primary classes; the book's subclass
#     and UA/OA rows are its own variants, out of scope),
#     the potion rows, the item/+2/+3 chance chain (Gonzo's
#     worked example pinned: 15%/lvl chain at 9th = 135%,
#     +2 chance 9 + 45 = 54, +3 check 9), and the
#     rollMemberMagic kit builder. No caller yet - data +
#     rollers only (the p.176 convention-party generator is
#     a future lane).
#
#  - rules/character.h/.cpp: dwarfConSaveBonus
#  - ai/actor.h: Actor.race + Actor.nonIntelligent; the
#    asTarget comment amended
#  - ai/actor.cpp: dm/encounters.h include; asTarget
#    carries the descriptors; trySaveVs mirrors II.D
#  - monsters/MonsterRegistry.cpp: toActor maps "non"
#  - spelleffects/spelleffects.h: doc + TargetDesc fields
#    + effectiveSaveLevel; spelleffects.cpp: trySave applies
#  - game/state_combat.cpp: buildFoesFromParty lands a.race
#  - NEW dm/appendixp.h
#  - regtest.cpp: include + 3 audits (census 64 -> 67)
#  - tools/dmg_gap_report.md: the R144 box amended + two
#    R147 boxes
#
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints. An assert
# follows EVERY patch (the R142 lesson).
# This file contains ZERO backslash characters (the
# R133b lesson); the audit printfs assemble their escaped
# newlines from chr(92).
# Commit: "R147: dwarf CON save bonus + matrix II.D +
# Appendix P (census 67)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BS = chr(92)   # one backslash
NL = chr(10)   # one newline
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding="ascii") as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), "w", encoding="ascii") as f:
        f.write(s)

def patch(p, old, new, tag, expect=1, marker=None):
    s = rd(p)
    if marker is None:
        marker = new
    if marker in s:
        already.append(tag)
        return
    n = s.count(old)
    if n != expect:
        fails.append(tag + ": anchor count " + str(n)
                     + " (expected " + str(expect) + ")")
        return
    wr(p, s.replace(old, new))
    applied.append(tag)

def newfile(p, content, tag):
    path = os.path.join(ROOT, p)
    if os.path.exists(path):
        already.append(tag)
        return
    wr(p, content)
    applied.append(tag)

# ---- (1) rules/character.h: dwarfConSaveBonus decl ----
old_ch_h = NL.join([
    'int  conPoisonSaveAdj(uint8_t con);  // -2..+2',
])
new_ch_h = NL.join([
    'int  conPoisonSaveAdj(uint8_t con);  // -2..+2',
    '',
    '// R147: dwarf CON magic-save bonus (PHB p.16) - applies',
    '// vs. wands/staves/rods, spells, and poison "in the same',
    '// manner". Book bands: CON 4-6 +1, 7-10 +2, 11-13 +3,',
    '// 14-17 +4, 18+ +5; the formula con*2/7 clamped 0..5',
    '// matches every band.',
    'int  dwarfConSaveBonus(uint8_t con); // 0..+5 (0 below CON 4)',
])

# ---- (2) rules/character.cpp: impl ----
old_ch_cpp = NL.join([
    'int conPoisonSaveAdj(uint8_t con) {',
    '    static constexpr int v[16] = {',
    '        -2, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2',
    '    };',
    '    return v[conIndex(con)];',
    '}',
])
new_ch_cpp = NL.join([
    'int conPoisonSaveAdj(uint8_t con) {',
    '    static constexpr int v[16] = {',
    '        -2, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2',
    '    };',
    '    return v[conIndex(con)];',
    '}',
    '',
    '// R147: dwarf CON magic-save bonus (PHB p.16) - +1 per 3.5',
    '// points of CON, clamped 0..5. Matches every printed band',
    '// (4-6 +1, 7-10 +2, 11-13 +3, 14-17 +4, 18 +5).',
    'int dwarfConSaveBonus(uint8_t con) {',
    '    int b = ((int)con * 2) / 7;',
    '    if (b < 0) b = 0;',
    '    if (b > 5) b = 5;',
    '    return b;',
    '}',
])

# ---- (3) ai/actor.h: race + nonIntelligent fields ----
old_ah_fields = NL.join([
    '    // identity: character or monster',
    '    bool isCharacter = false;',
])
new_ah_fields = NL.join([
    '    // identity: character or monster',
    '    bool isCharacter = false;',
    '    // R147: race (dm::NpcRace int - party PCs stay human,',
    '    // 0; NPC-foe dwarves carry their CON magic-save bonus',
    '    // into saves) and the DMG p.80 matrix II footnote D',
    '    // flag (MM intelligence "non" - saves at half level',
    '    // except vs. death/poison).',
    '    int  race = 0;',
    '    bool nonIntelligent = false;',
])

# ---- (4) ai/actor.h: asTarget comment ----
old_ah_ast = NL.join([
    '    // R14 target descriptor view of this actor',
    '    spelleffects::TargetDesc asTarget() const;',
])
new_ah_ast = NL.join([
    '    // R14 target descriptor view of this actor; R147: also',
    '    // lands the dwarf CON save bonus + matrix II.D flag',
    '    spelleffects::TargetDesc asTarget() const;',
])

# ---- (5) ai/actor.cpp: encounters include ----
old_ac_inc = NL.join([
    '#include "actor.h"',
    '',
    '#include <algorithm>',
    '#include <cstdio>',
])
new_ac_inc = NL.join([
    '#include "actor.h"',
    '',
    '#include "../dm/encounters.h"   // R147: dm::NpcRace ints',
    '',
    '#include <algorithm>',
    '#include <cstdio>',
])

# ---- (6) ai/actor.cpp: asTarget carries the descriptors ----
old_ac_ast = NL.join([
    '    t.isUndead = undead;',
    '    t.isLarge = hitDice >= 8;',
    '    return t;',
])
new_ac_ast = NL.join([
    '    t.isUndead = undead;',
    '    t.isLarge = hitDice >= 8;',
    '    // R147: dwarf CON magic-save bonus (PHB p.16) and the',
    '    // matrix II.D non-intelligence flag ride the target',
    '    // descriptor; trySave / trySaveVs apply them.',
    '    t.saveDwarfBonus =',
    '        (!isCharacter && race == dm::RACE_DWARF)',
    '            ? rules::dwarfConSaveBonus(con) : 0;',
    '    t.saveNonIntelligent = !isCharacter && nonIntelligent;',
    '    return t;',
])

# ---- (7) ai/actor.cpp: trySaveVs mirrors II.D ----
old_ac_tsv = NL.join([
    '    auto trySaveVs = [&](int saveCategory, int penalty) {',
    '        int target = rules::saveTarget(',
    '            defender.isCharacter ? defender.classIndex : 0,',
    '            defender.isCharacter ? defender.level',
    '                                 : rules::monsterSaveLevel(defender.hitDice),',
    '            (rules::SaveCategory)saveCategory);',
])
new_ac_tsv = NL.join([
    '    auto trySaveVs = [&](int saveCategory, int penalty) {',
    '        // R147: matrix II footnote D parity with',
    '        // spelleffects::trySave - non-intelligence halves',
    '        // the save level except vs. death/poison, and the',
    '        // dwarf CON bonus (PHB p.16) eases wands, spells',
    '        // and death-poison saves.',
    '        int lvl = defender.isCharacter',
    '            ? defender.level',
    '            : spelleffects::effectiveSaveLevel(',
    '                rules::monsterSaveLevel(defender.hitDice),',
    '                defender.nonIntelligent, saveCategory);',
    '        int target = rules::saveTarget(',
    '            defender.isCharacter ? defender.classIndex : 0,',
    '            lvl,',
    '            (rules::SaveCategory)saveCategory);',
    '        if (!defender.isCharacter &&',
    '            defender.race == dm::RACE_DWARF &&',
    '            saveCategory != rules::SAVE_PETRIFY_POLY &&',
    '            saveCategory != rules::SAVE_BREATH)',
    '            target -= rules::dwarfConSaveBonus(defender.con);',
])

# ---- (8) monsters/MonsterRegistry.cpp: toActor maps "non" ----
old_mr = NL.join([
    '    a.morale = def->morale;',
    '    a.isLeader = def->isLeader;',
])
new_mr = NL.join([
    '    a.morale = def->morale;',
    '    a.isLeader = def->isLeader;',
    '',
    '    // R147: matrix II footnote D - printed intelligence',
    '    // "non" (containsCI, no dash: "non-" is average-and-up',
    '    // wording, not the animal mind) flags the half-level',
    '    // save. "animal" keeps the II.B convention (a named',
    '    // judgment call); the audit census pins exactly 90 of',
    '    // the 408.',
    '    if (containsCI(def->intelligence, "non") &&',
    "        def->intelligence.find('-') == std::string::npos)",
    '        a.nonIntelligent = true;',
])

# ---- (9) spelleffects.h: TargetDesc doc ----
old_se_doc = NL.join([
    '//   saveBonus         flat modifier (WIS magic adj, rings, etc.)',
])
new_se_doc = NL.join([
    '//   saveBonus         flat modifier (WIS magic adj, rings, etc.)',
    '//   saveDwarfBonus    R147 dwarf CON magic-save bonus (PHB p.16)',
    '//   saveNonIntelligent  R147 matrix II.D half-level flag',
])

# ---- (10) spelleffects.h: TargetDesc fields ----
old_se_fld = NL.join([
    '    int saveBonus   = 0;',
    '    int magicResistPct = 0;',
])
new_se_fld = NL.join([
    '    int saveBonus   = 0;',
    '    // R147: dwarf CON magic-save bonus (0 for everyone but',
    '    // NPC-foe dwarves) and the matrix II.D non-intelligence',
    '    // flag - applied by trySave / the ai save helper.',
    '    int saveDwarfBonus = 0;',
    '    bool saveNonIntelligent = false;',
    '    int magicResistPct = 0;',
])

# ---- (11) spelleffects.h: effectiveSaveLevel ----
old_se_eff = NL.join([
    '// Per-target outcome of one spell.',
    'struct TargetResult {',
])
new_se_eff = NL.join([
    '// R147: DMG p.80 matrix II footnote D - a creature of',
    '// non-intelligence saves at half its (II.B-stepped)',
    '// level, rounded up, except vs. death magic/poison where',
    '// the footnote grants no relief. Consumed by trySave and',
    '// the ai trySaveVs helper.',
    'inline int effectiveSaveLevel(int level, bool nonIntelligent,',
    '                              int saveCategory) {',
    '    if (level < 1) level = 1;',
    '    if (nonIntelligent &&',
    '        saveCategory != (int)rules::SAVE_DEATH_POISON)',
    '        return (level + 1) / 2;',
    '    return level;',
    '}',
    '',
    '// Per-target outcome of one spell.',
    'struct TargetResult {',
])

# ---- (12) spelleffects.cpp: trySave applies both ----
old_se_cpp = NL.join([
    'static bool trySave(Dice& dice, const spells::SpellDef& s,',
    '                    const TargetDesc& t) {',
    '    if (s.saveCategory < 0) return false;   // no save allowed',
    '    int target = rules::saveTarget(t.saveClass, t.saveLevel,',
    '                                   (rules::SaveCategory)s.saveCategory);',
    '    return rules::attemptSave(dice, target, t.saveBonus);',
    '}',
])
new_se_cpp = NL.join([
    'static bool trySave(Dice& dice, const spells::SpellDef& s,',
    '                    const TargetDesc& t) {',
    '    if (s.saveCategory < 0) return false;   // no save allowed',
    '    // R147: matrix II.D halves the non-intelligent save',
    '    // level (except death/poison); the dwarf CON bonus',
    '    // (PHB p.16) eases wands, spells and death-poison',
    '    // saves.',
    '    int lvl = effectiveSaveLevel(t.saveLevel,',
    '                                 t.saveNonIntelligent,',
    '                                 s.saveCategory);',
    '    int target = rules::saveTarget(t.saveClass, lvl,',
    '                                   (rules::SaveCategory)s.saveCategory);',
    '    int bonus = t.saveBonus;',
    '    if (s.saveCategory == rules::SAVE_WANDS ||',
    '        s.saveCategory == rules::SAVE_SPELLS ||',
    '        s.saveCategory == rules::SAVE_DEATH_POISON)',
    '        bonus += t.saveDwarfBonus;',
    '    return rules::attemptSave(dice, target, bonus);',
    '}',
])

# ---- (13) game/state_combat.cpp: the race lands ----
old_sc = NL.join([
    '            int raceRoll = (int)dice.roll(1, 100, 0);',
])
new_sc = NL.join([
    '            int raceRoll = (int)dice.roll(1, 100, 0);',
    '            // R147: the p.176 race lands on the foe Actor -',
    '            // NPC-foe dwarves carry their CON magic-save',
    '            // bonus into saves. The two race-only bands',
    '            // (half-elf 61-85, half-orc 96-00) previously',
    '            // fell through unnamed; they mark the race now.',
    '            if (raceRoll <= 25)      a.race = dm::RACE_DWARF;',
    '            else if (raceRoll <= 50) a.race = dm::RACE_ELF;',
    '            else if (raceRoll <= 60) a.race = dm::RACE_GNOME;',
    '            else if (raceRoll <= 85) a.race = dm::RACE_HALF_ELF;',
    '            else if (raceRoll <= 95) a.race = dm::RACE_HALFLING;',
    '            else                    a.race = dm::RACE_HALF_ORC;',
])

# ---- (14) NEW dm/appendixp.h ----
appendixp = NL.join([
    '// ============================================================================',
    '// Adnd1 - dm/appendixp.h',
    '// R147: DMG pp.225-226 - APPENDIX P, CREATING A PARTY ON',
    '// THE SPUR OF THE MOMENT. Pure data + rollers,',
    '// header-only (the appendixa.h pattern: the caller',
    '// decides when to roll; any table luck beyond a row is',
    "// the caller's). Transcribed from the 1eonline.info",
    '// compilation - the repo-trusted source; the DMG',
    "// re-upload's OCR debt stands (the compilation's own",
    '// prose typos - "far" for "for", "fallowing" - carry no',
    '// data and stay unpinned).',
    '//',
    '// Conventions, all named in place:',
    "//   - classIndex is the engine's four (0 fighter,",
    '//     1 magic-user, 2 cleric, 3 thief - CharClass). The',
    "//     book's subclass and UA/OA rows (cavalier, paladin,",
    '//     ranger, druid, barbarian, illusionist, assassin,',
    "//     monk) are the book's own variants - out of scope.",
    '//   - "Only one sort may be tried for" (both armor and',
    '//     weapons): rollMemberMagic tries exactly one armor',
    '//     category and one weapon category per member.',
    '//   - A printed dash (never) encodes as 0 percent.',
    '//   - The potion list prints "0. Polymorph Self"; the',
    '//     roller types run 1-10 with 10 = that entry.',
    '// ============================================================================',
    '',
    '#pragma once',
    '',
    '#include "../rules/dice.h"',
    '',
    'namespace dm {',
    'namespace appendixp {',
    '',
    '// ---- LEVEL (p.225): three printed options per band -----',
    'enum LevelBand { BAND_LOW = 0, BAND_MEDIUM, BAND_UPPER };',
    '',
    'inline int bandLevelLo(int band, int option) {',
    '    static const int lo[3][3] = {',
    '        { 1, 1, 2 },    // low: 1-2 / 1-3 / 2-4',
    '        { 5, 5, 7 },    // medium: 5-7 / 5-8 / 7-9',
    '        { 8, 8, 9 },    // upper: 8-10 / 8-11 / 9-12',
    '    };',
    '    if (band < 0) band = 0;',
    '    if (band > 2) band = 2;',
    '    if (option < 0) option = 0;',
    '    if (option > 2) option = 2;',
    '    return lo[band][option];',
    '}',
    '',
    'inline int bandLevelHi(int band, int option) {',
    '    static const int hi[3][3] = {',
    '        { 2, 3, 4 },',
    '        { 7, 8, 9 },',
    '        { 10, 11, 12 },',
    '    };',
    '    if (band < 0) band = 0;',
    '    if (band > 2) band = 2;',
    '    if (option < 0) option = 0;',
    '    if (option > 2) option = 2;',
    '    return hi[band][option];',
    '}',
    '',
    '// ---- ABILITIES (p.225): 4d6, discard the low die -------',
    'inline int abilityRoll(rules::Dice& dice) {',
    '    return (int)dice.bestOf(4, 6, 3);',
    '}',
    '',
    '// ---- PROTECTIVE ITEMS TABLE (p.225) ---------------------',
    '// Per-level chance for shield, armor, etc. (typically',
    '// +1). Columns: 0 shield, 1 plate, 2 banded, 3 chain,',
    '// 4 leather, 5 ring of protection, 6 bracers (of AC 6',
    '// value). Rows: 0 fighter, 1 magic-user, 2 cleric,',
    '// 3 thief.',
    'inline int protectivePct(int classIndex, int col) {',
    '    static const int t[4][7] = {',
    '        { 10, 6, 8, 10,  0,  0, 0 },   // fighter',
    '        {  0, 0, 0,  0,  0, 15, 4 },   // magic-user',
    '        { 10, 5, 6,  8,  0,  2, 0 },   // cleric',
    '        {  0, 0, 0,  0, 10,  4, 0 },   // thief',
    '    };',
    '    if (classIndex < 0) classIndex = 0;',
    '    if (classIndex > 3) classIndex = 3;',
    '    if (col < 0) col = 0;',
    '    if (col > 6) col = 6;',
    '    return t[classIndex][col];',
    '}',
    '',
    '// ---- WEAPONS TABLE (p.225-226) -------------------------',
    '// Columns: 0 dagger, 1 sword, 2 mace, 3 battle axe,',
    '// 4 spear, 5 bow, 6 the 15 bolts +2. Same row order.',
    'inline int weaponPct(int classIndex, int col) {',
    '    static const int t[4][7] = {',
    '        { 10, 10,  0, 7, 8, 1, 10 },   // fighter',
    '        { 15,  0,  0, 0, 0, 0,  0 },   // magic-user',
    '        {  0,  0, 12, 0, 0, 0,  0 },   // cleric',
    '        { 12, 11,  0, 0, 0, 0,  0 },   // thief',
    '    };',
    '    if (classIndex < 0) classIndex = 0;',
    '    if (classIndex > 3) classIndex = 3;',
    '    if (col < 0) col = 0;',
    '    if (col > 6) col = 6;',
    '    return t[classIndex][col];',
    '}',
    '',
    '// ---- POTIONS TABLE (p.226) -----------------------------',
    '// Per-level chance of having a potion, the max carried,',
    '// and the 10 printed types (roll 10 = the book' + "'" + 's "0.",',
    '// Polymorph Self).',
    'inline int potionPct(int classIndex) {',
    '    static const int t[4] = { 8, 10, 6, 9 };',
    '    if (classIndex < 0) classIndex = 0;',
    '    if (classIndex > 3) classIndex = 3;',
    '    return t[classIndex];',
    '}',
    '',
    'inline int potionMax(int classIndex) {',
    '    static const int t[4] = { 1, 3, 1, 2 };',
    '    if (classIndex < 0) classIndex = 0;',
    '    if (classIndex > 3) classIndex = 3;',
    '    return t[classIndex];',
    '}',
    '',
    'inline const char* potionType(int roll) {',
    '    static const char* const k[10] = {',
    '        "Climbing", "Diminution", "Extra-Healing",',
    '        "Fire Resistance", "Flying", "Gaseous Form",',
    '        "Growth", "Healing", "Invisibility",',
    '        "Polymorph Self",',
    '    };',
    '    if (roll < 1) roll = 1;',
    '    if (roll > 10) roll = 10;',
    '    return k[roll - 1];',
    '}',
    '',
    '// ---- THE CHANCE CHAIN (p.225) --------------------------',
    '// Item chance: level x percentage. Above-average (+2,',
    '// or bracers AC 5): 1% per level, plus any excess over',
    '// 90% in the item chance folded in. Above that, +3 (or',
    "// bracers AC 4) on a straight 1% per level. Gonzo's",
    '// worked example: 15%/level chain at 9th = 135%, +2',
    '// chance 9 + 45 = 54 (rolled 51 -> at least +2), +3',
    '// check 9 (rolled 99 -> just +2).',
    'inline int itemChancePct(int pct, int level) {',
    '    if (level < 1) level = 1;',
    '    return pct * level;',
    '}',
    '',
    'inline int plusTwoChancePct(int pct, int level) {',
    '    if (level < 1) level = 1;',
    '    int c = pct * level;',
    '    int excess = c > 90 ? c - 90 : 0;',
    '    return level + excess;',
    '}',
    '',
    'inline int plusThreeChancePct(int level) {',
    '    if (level < 1) level = 1;',
    '    return level;',
    '}',
    '',
    '// The full chain: 0 = none, else the plus (1-3).',
    'inline int rollItemPlus(rules::Dice& dice, int pct, int level) {',
    '    if (pct <= 0) return 0;',
    '    if (level < 1) level = 1;',
    '    if ((int)dice.d100() > itemChancePct(pct, level)) return 0;',
    '    if ((int)dice.d100() <= plusTwoChancePct(pct, level)) {',
    '        if ((int)dice.d100() <= plusThreeChancePct(level))',
    '            return 3;',
    '        return 2;',
    '    }',
    '    return 1;',
    '}',
    '',
    '// ---- KIT BUILDER ---------------------------------------',
    "// One member's magic kit: one armor sort (the book's",
    '// only-one-sort rule), one weapon sort, and a shield try',
    '// for the armored classes. The class picks:',
    '//   armor  - fighter chain 10%, MU ring 15%, cleric',
    '//            chain 8%, thief leather 10%',
    '//   weapon - fighter sword 10%, MU dagger 15%, cleric',
    '//            mace 12%, thief sword 11%',
    '//   shield - fighter and cleric, both at 10%',
    'struct MemberMagic {',
    '    int armorPlus  = 0;   // 0 = none',
    '    int weaponPlus = 0;',
    '    int shieldPlus = 0;',
    '};',
    '',
    'inline MemberMagic rollMemberMagic(rules::Dice& dice,',
    '                                   int classIndex, int level) {',
    '    static const int kArmor[4]  = { 10, 15, 8, 10 };',
    '    static const int kWeapon[4] = { 10, 15, 12, 11 };',
    '    if (classIndex < 0) classIndex = 0;',
    '    if (classIndex > 3) classIndex = 3;',
    '    MemberMagic m;',
    '    m.armorPlus  = rollItemPlus(dice, kArmor[classIndex], level);',
    '    m.weaponPlus = rollItemPlus(dice, kWeapon[classIndex], level);',
    '    if (classIndex == 0 || classIndex == 2)',
    '        m.shieldPlus = rollItemPlus(dice, 10, level);',
    '    return m;',
    '}',
    '',
    '} // namespace appendixp',
    '} // namespace dm',
])

# ---- (15) regtest.cpp: include ----
old_rt_inc = NL.join([
    '#include "dm/sampledungeon.h"  // R142: pp.94-96 the DMG sample dungeon',
])
new_rt_inc = NL.join([
    '#include "dm/sampledungeon.h"  // R142: pp.94-96 the DMG sample dungeon',
    '#include "dm/appendixp.h"  // R147: pp.225-226 Appendix P tables',
])

# ---- (16) regtest.cpp: the three R147 audits ----
audits = NL.join([
    '    // ---- R147: dwarf CON magic-save bonus audit ----',
    '    // PHB p.16: dwarves add their constitution to saves',
    '    // vs. wands/staves/rods, spells, and poison. The',
    '    // formula con*2/7 clamped 0..5 matches every printed',
    '    // band (4-6 +1, 7-10 +2, 11-13 +3, 14-17 +4, 18+ +5).',
    '    {',
    '        int bad = 0;',
    '        static const int kPins[][2] = {',
    '            { 3, 0 }, { 4, 1 }, { 6, 1 }, { 7, 2 },',
    '            { 10, 2 }, { 11, 3 }, { 13, 3 }, { 14, 4 },',
    '            { 17, 4 }, { 18, 5 }, { 21, 5 },',
    '        };',
    '        for (int i = 0; i < 11; ++i)',
    '            if (rules::dwarfConSaveBonus(',
    '                    (uint8_t)kPins[i][0]) != kPins[i][1]) ++bad;',
    '        int prev = -1;',
    '        for (int c = 1; c <= 30; ++c) {',
    '            int b = rules::dwarfConSaveBonus((uint8_t)c);',
    '            if (b < 0 || b > 5) ++bad;',
    '            if (b < prev) ++bad;',
    '            prev = b;',
    '        }',
    '        printf("R147 dwarf CON save bonus audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R147: matrix II.D audit ----',
    '    // DMG p.80 footnote D: non-intelligence saves at',
    '    // half hit dice rounded up - half the II.B-stepped',
    '    // level - except vs. death/poison. Pins: the halving',
    '    // against the stepped level, the category exception,',
    '    // the iron_golem/goblin mapping, and the census',
    '    // (exactly 90 of the 408 print intelligence "non";',
    '    // "animal" keeps II.B - a named judgment call).',
    '    {',
    '        int bad = 0;',
    '        struct { float hd; int lvl; int half; } kPin[] = {',
    '            { 0.5f, 1, 1 }, { 2.0f, 2, 1 },',
    '            { 3.0f, 3, 2 }, { 4.0f, 4, 2 },',
    '            { 4.75f, 5, 3 }, { 6.0f, 6, 3 },',
    '            { 8.5f, 9, 5 }, { 10.0f, 10, 5 },',
    '            { 12.0f, 12, 6 }, { 16.0f, 16, 8 },',
    '            { 20.0f, 20, 10 },',
    '        };',
    '        for (int i = 0; i < 11; ++i) {',
    '            int lvl = rules::monsterSaveLevel(kPin[i].hd);',
    '            if (lvl != kPin[i].lvl) ++bad;',
    '            int h = spelleffects::effectiveSaveLevel(',
    '                lvl, true, rules::SAVE_SPELLS);',
    '            if (h != kPin[i].half) ++bad;',
    '            if (spelleffects::effectiveSaveLevel(',
    '                    lvl, true, rules::SAVE_DEATH_POISON)',
    '                != lvl) ++bad;',
    '        }',
    '        if (spelleffects::effectiveSaveLevel(',
    '                9, false, rules::SAVE_SPELLS) != 9) ++bad;',
    '        {',
    '            rules::Rng rngII(20261004);',
    '            rules::Dice diceII(rngII);',
    '            if (!reg.toActor("iron_golem", diceII)',
    '                    .nonIntelligent) ++bad;',
    '            if (reg.toActor("goblin", diceII)',
    '                    .nonIntelligent) ++bad;',
    '            int non = 0;',
    '            for (const auto& kv : reg.all())',
    '                if (reg.toActor(kv.first, diceII)',
    '                        .nonIntelligent) ++non;',
    '            if (non != 90) ++bad;',
    '        }',
    '        printf("R147 matrix II.D audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R147: Appendix P audit ----',
    '    // DMG pp.225-226: every table cell pinned (level',
    '    // bands, protective + weapon percentages per class,',
    "    // potion rows), Gonzo's worked example (15%/level",
    '    // chain at 9th = 135; +2 chance 9 + 45 = 54, rolled',
    '    // 51 -> at least +2; +3 check 9, rolled 99 -> just',
    '    // +2), band sweeps, and the kit smoke (2000 members,',
    '    // level 9, class i%4, seed 20261003 - floors arm',
    '    // 1200 / shield 600 / weapon 1500).',
    '    {',
    '        int bad = 0;',
    '        static const int kLo[3][3] = {',
    '            { 1, 1, 2 }, { 5, 5, 7 }, { 8, 8, 9 },',
    '        };',
    '        static const int kHi[3][3] = {',
    '            { 2, 3, 4 }, { 7, 8, 9 }, { 10, 11, 12 },',
    '        };',
    '        for (int b = 0; b < 3; ++b)',
    '            for (int o = 0; o < 3; ++o) {',
    '                if (dm::appendixp::bandLevelLo(b, o)',
    '                    != kLo[b][o]) ++bad;',
    '                if (dm::appendixp::bandLevelHi(b, o)',
    '                    != kHi[b][o]) ++bad;',
    '            }',
    '        static const int kProt[4][7] = {',
    '            { 10, 6, 8, 10, 0, 0, 0 },',
    '            { 0, 0, 0, 0, 0, 15, 4 },',
    '            { 10, 5, 6, 8, 0, 2, 0 },',
    '            { 0, 0, 0, 0, 10, 4, 0 },',
    '        };',
    '        for (int c = 0; c < 4; ++c)',
    '            for (int k = 0; k < 7; ++k)',
    '                if (dm::appendixp::protectivePct(c, k)',
    '                    != kProt[c][k]) ++bad;',
    '        static const int kWpn[4][7] = {',
    '            { 10, 10, 0, 7, 8, 1, 10 },',
    '            { 15, 0, 0, 0, 0, 0, 0 },',
    '            { 0, 0, 12, 0, 0, 0, 0 },',
    '            { 12, 11, 0, 0, 0, 0, 0 },',
    '        };',
    '        for (int c = 0; c < 4; ++c)',
    '            for (int k = 0; k < 7; ++k)',
    '                if (dm::appendixp::weaponPct(c, k)',
    '                    != kWpn[c][k]) ++bad;',
    '        static const int kPot[4][2] = {',
    '            { 8, 1 }, { 10, 3 }, { 6, 1 }, { 9, 2 },',
    '        };',
    '        for (int c = 0; c < 4; ++c) {',
    '            if (dm::appendixp::potionPct(c)',
    '                != kPot[c][0]) ++bad;',
    '            if (dm::appendixp::potionMax(c)',
    '                != kPot[c][1]) ++bad;',
    '        }',
    '        for (int p = 1; p <= 10; ++p)',
    '            if (!*dm::appendixp::potionType(p)) ++bad;',
    '        if (dm::appendixp::itemChancePct(15, 9)',
    '            != 135) ++bad;',
    '        if (dm::appendixp::plusTwoChancePct(15, 9)',
    '            != 54) ++bad;',
    '        if (dm::appendixp::plusThreeChancePct(9)',
    '            != 9) ++bad;',
    '        {',
    '            rules::Rng rngP(20261003);',
    '            rules::Dice diceP(rngP);',
    '            for (int i = 0; i < 200; ++i) {',
    '                int v = dm::appendixp::abilityRoll(diceP);',
    '                if (v < 3 || v > 18) ++bad;',
    '            }',
    '            int items = 0, plus2 = 0, plus3 = 0;',
    '            for (int i = 0; i < 4000; ++i) {',
    '                int p = dm::appendixp::rollItemPlus(',
    '                    diceP, 15, 9);',
    '                if (p > 0) ++items;',
    '                if (p >= 2) ++plus2;',
    '                if (p == 3) ++plus3;',
    '            }',
    '            if (items != 4000) ++bad;',
    '            if (plus2 < 1900 || plus2 > 2420) ++bad;',
    '            if (plus3 < 100 || plus3 > 300) ++bad;',
    '            int arm = 0, shd = 0, wpn = 0;',
    '            for (int i = 0; i < 2000; ++i) {',
    '                dm::appendixp::MemberMagic m =',
    '                    dm::appendixp::rollMemberMagic(',
    '                        diceP, i % 4, 9);',
    '                if (m.armorPlus > 0) ++arm;',
    '                if (m.shieldPlus > 0) ++shd;',
    '                if (m.weaponPlus > 0) ++wpn;',
    '            }',
    '            if (arm < 1200) ++bad;',
    '            if (shd < 600) ++bad;',
    '            if (wpn < 1500) ++bad;',
    '        }',
    '        printf("R147 Appendix P audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R146: city flavor subtables audit ----',
])
old_rt_aud = NL.join([
    '    // ---- R146: city flavor subtables audit ----',
])

# ---- (17) gap report: the R144 box amended ----
old_gap144 = NL.join([
    '      lane), as is the dwarf CON magic-save bonus (the',
    '      engine models CON only vs. poison). Pinned by the',
])
new_gap144 = NL.join([
    '      lane), as was the dwarf CON magic-save bonus until',
    '      R147 closed it (PHB p.16 - rules::dwarfConSaveBonus;',
    '      see the R147 boxes). Pinned by the',
])

# ---- (18) gap report: the two R147 boxes ----
old_gap_tail = NL.join([
    '      half-orc/humanoid note. Pinned by the R146 city',
    '      flavor audit; census 64.',
    '',
    '## Out of scope by design',
])
new_gap_tail = NL.join([
    '      half-orc/humanoid note. Pinned by the R146 city',
    '      flavor audit; census 64.',
    '- [x] **The dwarf CON magic-save bonus + matrix II',
    "      footnote D (R144's named standing approximation",
    '      + the p.80 footnote)** - CLOSED R147: dwarves add',
    '      their constitution to saves vs. wands/staves/rods,',
    '      spells, and poison "in the same manner" (PHB',
    '      p.16) - pinned as rules::dwarfConSaveBonus (con*2/7',
    '      clamped 0..5, matching every printed band 4-6 +1',
    '      through 18 +5); NPC foes carry the rolled p.176',
    '      race on the Actor (the half-elf and half-orc',
    '      race-only bands now mark the race where they',
    '      previously fell through), and asTarget / trySaveVs',
    '      apply the bonus to wands, spells, and death-poison',
    '      saves (the party is human - only NPC-foe dwarves',
    '      benefit). Footnote D: non-intelligence saves at',
    '      half hit dice rounded up except vs. death/poison -',
    '      pinned as spelleffects::effectiveSaveLevel, consumed',
    '      by both trySave and the ai trySaveVs; toActor maps',
    '      MM intelligence "non" (containsCI, no dash -',
    '      "non-" wordings excluded; exactly 90 of the 408,',
    '      census-pinned; "animal" keeps the II.B step, a',
    '      named judgment call). Matrix II.C (classed monsters',
    '      saving on their most favorable matrix) stays a',
    '      named gap - the per-monster class pass is a future',
    '      lane. Pinned by the R147 dwarf CON + II.D audits;',
    '      census 67.',
    '- [x] **Appendix P: creating a party on the spur of the',
    '      moment (DMG pp.225-226)** - CLOSED R147: pinned as',
    '      the header-only dm/appendixp.h (the appendixa.h',
    '      pattern - data + rollers, the caller decides when).',
    '      The three level-band options per range (low 1-2 /',
    '      1-3 / 2-4, medium 5-7 / 5-8 / 7-9, upper 8-10 /',
    '      8-11 / 9-12), the 4d6-drop-lowest ability rolls,',
    '      the protective and weapons per-level percentage',
    "      tables (the four primary classes; the book's",
    '      subclass and UA/OA rows are its own variants, out',
    '      of scope), the potion rows (per-level chance, max',
    '      carried, the 10 printed types - the book' + "'" + 's "0."',
    '      prints as type 10), the item/+2/+3 chance chain',
    '      (item = level x pct; above-90 excess folds into the',
    '      +2 chance; +3 is a straight 1% per level), and the',
    '      rollMemberMagic kit builder (one armor sort',
    '      chain/ring/chain/leather by class, one weapon sort',
    '      sword/dagger/mace/sword, a shield try for the',
    "      armored classes). Gonzo's worked example pinned:",
    '      15%/level chain at 9th = 135%, +2 chance 9 + 45 =',
    '      54 (rolled 51 - at least +2), +3 check 9 (rolled',
    '      99 - just +2). No caller yet - data + rollers',
    '      only (the p.176 convention-party generator is a',
    '      future lane). Pinned by the R147 Appendix P audit;',
    '      census 67.',
    '',
    '## Out of scope by design',
])

# ---- run ----
patch("rules/character.h", old_ch_h, new_ch_h,
      "character.h: dwarfConSaveBonus decl",
      marker="int  dwarfConSaveBonus(uint8_t con);")
assert len(applied) + len(already) == 1

patch("rules/character.cpp", old_ch_cpp, new_ch_cpp,
      "character.cpp: dwarfConSaveBonus impl",
      marker="int dwarfConSaveBonus(uint8_t con) {")
assert len(applied) + len(already) == 2

patch("ai/actor.h", old_ah_fields, new_ah_fields,
      "actor.h: race + nonIntelligent fields",
      marker="bool nonIntelligent = false;")
assert len(applied) + len(already) == 3

patch("ai/actor.h", old_ah_ast, new_ah_ast,
      "actor.h: asTarget comment amended",
      marker="R147: also")
assert len(applied) + len(already) == 4

patch("ai/actor.cpp", old_ac_inc, new_ac_inc,
      "actor.cpp: encounters include",
      marker='R147: dm::NpcRace ints')
assert len(applied) + len(already) == 5

patch("ai/actor.cpp", old_ac_ast, new_ac_ast,
      "actor.cpp: asTarget descriptors",
      marker="t.saveDwarfBonus =")
assert len(applied) + len(already) == 6

patch("ai/actor.cpp", old_ac_tsv, new_ac_tsv,
      "actor.cpp: trySaveVs mirrors II.D",
      marker="spelleffects::effectiveSaveLevel(")
assert len(applied) + len(already) == 7

patch("monsters/MonsterRegistry.cpp", old_mr, new_mr,
      "MonsterRegistry.cpp: toActor maps non",
      marker="a.nonIntelligent = true;")
assert len(applied) + len(already) == 8

patch("spelleffects/spelleffects.h", old_se_doc, new_se_doc,
      "spelleffects.h: TargetDesc doc",
      marker="R147 dwarf CON magic-save bonus (PHB p.16)")
assert len(applied) + len(already) == 9

patch("spelleffects/spelleffects.h", old_se_fld, new_se_fld,
      "spelleffects.h: TargetDesc fields",
      marker="bool saveNonIntelligent = false;")
assert len(applied) + len(already) == 10

patch("spelleffects/spelleffects.h", old_se_eff, new_se_eff,
      "spelleffects.h: effectiveSaveLevel",
      marker="inline int effectiveSaveLevel(")
assert len(applied) + len(already) == 11

patch("spelleffects/spelleffects.cpp", old_se_cpp, new_se_cpp,
      "spelleffects.cpp: trySave applies both",
      marker="int lvl = effectiveSaveLevel(")
assert len(applied) + len(already) == 12

patch("game/state_combat.cpp", old_sc, new_sc,
      "state_combat.cpp: race lands",
      marker="a.race = dm::RACE_HALF_ORC;")
assert len(applied) + len(already) == 13

newfile("dm/appendixp.h", appendixp, "NEW dm/appendixp.h")
assert len(applied) + len(already) == 14

patch("regtest.cpp", old_rt_inc, new_rt_inc,
      "regtest.cpp: appendixp include",
      marker='#include "dm/appendixp.h"')
assert len(applied) + len(already) == 15

patch("regtest.cpp", old_rt_aud, audits,
      "regtest.cpp: R147 audits",
      marker="R147 Appendix P audit")
assert len(applied) + len(already) == 16

patch("tools/dmg_gap_report.md", old_gap144, new_gap144,
      "gap report: R144 box amended",
      marker="as was the dwarf CON magic-save bonus until")
assert len(applied) + len(already) == 17

patch("tools/dmg_gap_report.md", old_gap_tail, new_gap_tail,
      "gap report: R147 boxes",
      marker="CLOSED R147: pinned as")
assert len(applied) + len(already) == 18

# ---- R147 fails/tail ----
if fails:
    print("R147 splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 18:
    print("R147 splice: FAIL - expected 18 patches, "
          "counted " + str(len(applied) + len(already))
          + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R147 splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R147 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
print("R147 note: expect the battery to gain three audit")
print("lines (dwarf CON, matrix II.D, Appendix P) - AUDIT")
print("CENSUS 67; commit: R147: dwarf CON save bonus +")
print("matrix II.D + Appendix P (census 67)")
