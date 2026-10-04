# tools/r154_splice.py - R154, 26 patches: the PC races
# layer (PHB pp.15-18, Race Tables I-III) pinned - the
# races half of the authored-but-unlanded R148 combined
# splice, re-authored against current main (the stale
# splice never ran; its R147 half already landed).
#
# (1)-(2) the new rules/races layer: the racial ability
#     adjustments, Table III min/max (male AND female
#     columns), infravision, sleep-and-charm resistance
#     (elf 90 / half-elf 30), the CON magic-save bonus
#     for dwarf, gnome and halfling (the R147 dwarf
#     shape) - FINDING: the print gives the gnome MAGIC
#     ONLY, no poison line (dwarf and halfling carry
#     both); the gap box claimed gnome poison, the
#     print wins - Race Table I class limitations, the
#     footnoted Race Table II level caps, the goblin-
#     kind/giant-kind to-hit lists and the detection
#     lists (in-N pairs as printed). (3) preflight
#     gains rules/races.cpp in the battery build.
#     (4)-(5) the regtest include + the R154 audit: all
#     seven adjustment rows, the full 7x6 min table and
#     both max columns, every CON band 3-18 per race,
#     the 4x7 class matrix, 34 cap rows (every printed
#     footnote ladder), the foe lists and the detection
#     tables - CENSUS 72. (6)-(14) the game layer:
#     Character.race (optional save line, v1 saves load
#     as human), the CR_RACE creation stage between
#     ROLL and CLASS (ROLL -> RACE -> CLASS -> NAME),
#     the sex toggle (Table III M/F), the adjusted-
#     score convention (adjusted is actual; exStr and
#     CON hp/die ride the ADJUSTED scores). (15)-(17)
#     save/load/reset. (18)-(24) the Win32 shell keys
#     and render (NOTE: adnd1.cpp is not compiled on
#     Termux - the MSVC verify stays pending, the
#     backlog convention). (25)-(26) the gap report.
#
# Idempotent: safe to run twice; a silent run means the
# paste was truncated - this tail ALWAYS prints. An assert
# follows EVERY patch (the R142 lesson). ZERO backslash
# characters in this file; no content string embeds a
# literal apostrophe (the R133b + R147 lessons).
# Commit: "R154: PC races pinned - Race Tables I-III,
# adjustments, caps, detection, the RACE stage (census 72)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
AP = chr(39)
BS = chr(92)
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

def create(p, text, tag, marker):
    path = os.path.join(ROOT, p)
    if os.path.exists(path):
        s = rd(p)
        if marker in s:
            already.append(tag)
            return
        fails.append(tag + ": file exists without marker")
        return
    wr(p, text)
    applied.append(tag)

# ---- (1)-(2) the new rules/races layer ----
races_h_text = NL.join([
    '// ============================================================================',
    '// Adnd1 - rules/races.h',
    '// The PC races layer: PHB pp.15-18, Race Tables I-III.',
    '//',
    '// R154: the races half of the authored-but-unlanded R148',
    '// combined splice, re-authored against current main. The',
    '// printed tables are pinned: class limitations (Table I),',
    '// the footnoted level caps (Table II), ability minimums',
    '// and maximums with the racial adjustments (Table III and',
    '// the Penalties and Bonuses list), infravision, sleep and',
    '// charm resistance, the CON magic-save (and where printed,',
    '// poison-save) bonuses, the goblin-kind and giant-kind',
    '// to-hit adjustments, and the detection lists.',
    '//',
    '// Enum order matches dm::NpcRace (R62) exactly, so the',
    '// fiction layer and the rules layer share one indexing.',
    '// ============================================================================',
    '',
    '#pragma once',
    '',
    '#include "character.h"',
    '#include "classes.h"',
    '',
    '#include <cstdint>',
    '',
    'namespace rules {',
    '',
    'enum CharRace : int {',
    '    RACE_HUMAN = 0,',
    '    RACE_DWARF,',
    '    RACE_ELF,',
    '    RACE_GNOME,',
    '    RACE_HALF_ELF,',
    '    RACE_HALFLING,',
    '    RACE_HALF_ORC,',
    '    RACE_CHAR_COUNT',
    '};',
    '',
    'const char* raceName(CharRace r);',
    '',
    '// Racial adjustment applied to the initially rolled score',
    '// when the race is selected (PHB Penalties and Bonuses):',
    '//   dwarf     CON +1, CHA -1',
    '//   elf       DEX +1, CON -1',
    '//   half-orc  STR +1, CON +1, CHA -2',
    '//   halfling  STR -1, DEX +1',
    '//   gnome, half-elf, human: none',
    'int raceAbilityAdj(CharRace r, Ability a);',
    '',
    '// Table III minimums and maximums (male/female columns).',
    '// Minimums are eligibility, met CONSIDERING the racial',
    '// bonuses; maximums clamp the ADJUSTED score. Human: min 3,',
    '// max 18 across the board. The dwarf charisma parenthetical',
    '// (recorded 16(18) for dealings with dwarves) is a display',
    '// concern, not engine data.',
    'int raceAbilityMin(CharRace r, Ability a, bool female);',
    'int raceAbilityMax(CharRace r, Ability a, bool female);',
    '',
    '// The full race-selection arithmetic: adjustment first,',
    '// then the maximum clamp. Scores can pass 18 only via the',
    '// bonuses the print allows (dwarf CON 19, halfling CON 19,',
    '// half-orc CON 19, elf DEX 19). No floor: an adjusted',
    '// score below its minimum simply fails eligibility.',
    'void applyRacialAdjustments(AbilityScores& s, CharRace r,',
    '                            bool female);',
    '',
    '// eligibility: every ADJUSTED score meets the Table III',
    '// minimum for the race (the print: minimums must be met',
    '// considering such bonuses)',
    'bool raceMeetsMinimums(const AbilityScores& s, CharRace r,',
    '                       bool female);',
    '',
    '// Infravision in feet: 60 for dwarf, elf, gnome, half-elf',
    '// and half-orc; halfling 30 (the mixed-blood line; pure',
    '// Stoutish 60 is sub-race narration); human 0.',
    'int raceInfravisionFeet(CharRace r);',
    '',
    '// Resistance to sleep and charm spells, in percent: elf',
    '// 90, half-elf 30. The percentile roll gates the magic',
    '// before any save is even attempted (the print: 91 or',
    '// better on d100 lets the spell try, and then the normal',
    '// save applies).',
    'int raceSleepCharmResistPct(CharRace r);',
    '',
    '// CON magic-save bonus vs. wands, staves, rods and spells:',
    '// +1 per 3.5 points of CON (the R147 dwarf shape), for',
    '// dwarf, gnome and halfling. Poison saves ride the same',
    '// bonus for dwarf and halfling; the gnome print gives the',
    '// magic bonus ONLY (its paragraph names no poison line) -',
    '// the gap box claimed gnome poison saves; the print wins.',
    'int raceMagicSaveBonus(CharRace r, uint8_t con);',
    'int racePoisonSaveBonus(CharRace r, uint8_t con);',
    '',
    '// Race Table I, class limitations, for the base four',
    '// classes (sub-classes are not modeled; the druid,',
    '// illusionist, assassin, monk columns are out of scope).',
    'bool classAllowedForRace(int classIndex, CharRace r);',
    '',
    '// Race Table II, level caps WITH the printed footnotes,',
    '// as a single lookup. Returns 0 when the class is not',
    '// allowed for the race, -1 for unlimited, else the cap.',
    '// The score arguments are the ADJUSTED scores.',
    'int raceLevelCap(int classIndex, CharRace r, uint8_t str,',
    '                 uint8_t int_, uint8_t dex);',
    '',
    '// The goblin-kind and giant-kind melee lists (printed',
    '// prose): dwarf adds +1 to hit half-orcs, goblins,',
    '// hobgoblins and orcs; gnome adds +1 vs. kobolds and',
    '// goblins. When ATTACKED by the big kinds the foe',
    '// SUBTRACTS 4: dwarf vs. ogres, trolls, ogre magi,',
    '// giants, titans; gnome vs. gnolls, bugbears and the',
    '// same giant-kind list. The lists carry the printed base',
    '// names; family-name matching (hill giant, stone giant)',
    '// is the combat caller concern, named for a later round.',
    'int raceBonusVsFoeName(CharRace r, const char* foeName);',
    'int raceFoeAttackPenalty(CharRace r, const char* foeName);',
    '',
    '// The racial detection lists, as printed in-N chances.',
    '// The seeking rule is the caller concern: the print',
    '// requires active seeking (depth at any distance).',
    'struct ChanceIn { int num; int den; };',
    'enum DetectKind : int {',
    '    DET_GRADE = 0,            // passage slope, up or down',
    '    DET_NEW_CONSTRUCTION,     // new construction or passage',
    '    DET_SLIDING_WALLS,        // sliding or shifting walls/rooms',
    '    DET_STONE_TRAPS,          // pits, falling blocks, stonework',
    '    DET_DEPTH,                // approximate depth underground',
    '    DET_UNSAFE_SURFACES,      // unsafe walls, ceilings, floors',
    '    DET_DIRECTION,            // direction of travel underground',
    '    DET_SECRET_PASS,          // secret/concealed door, passing',
    '    DET_SECRET_SEARCH,        // secret door, active search',
    '    DET_CONCEALED_SEARCH,     // concealed door, active search',
    '    DET_KIND_COUNT',
    '};',
    'ChanceIn raceDetectChance(CharRace r, DetectKind k);',
    'int raceDetectPct(CharRace r, DetectKind k);   // rounded down',
    '',
    '} // namespace rules',
    '',
])

races_cpp_text = NL.join([
    '#include "races.h"',
    '',
    '#include <cstring>',
    '',
    'namespace rules {',
    '',
    'const char* raceName(CharRace r) {',
    '    static const char* N[RACE_CHAR_COUNT] = {',
    '        "human", "dwarf", "elf", "gnome",',
    '        "half-elf", "halfling", "half-orc"',
    '    };',
    '    if (r < 0 || r >= RACE_CHAR_COUNT) return N[0];',
    '    return N[r];',
    '}',
    '',
    'int raceAbilityAdj(CharRace r, Ability a) {',
    '    if (r == RACE_DWARF) {',
    '        if (a == ABILITY_CON) return 1;',
    '        if (a == ABILITY_CHA) return -1;',
    '        return 0;',
    '    }',
    '    if (r == RACE_ELF) {',
    '        if (a == ABILITY_DEX) return 1;',
    '        if (a == ABILITY_CON) return -1;',
    '        return 0;',
    '    }',
    '    if (r == RACE_HALF_ORC) {',
    '        if (a == ABILITY_STR) return 1;',
    '        if (a == ABILITY_CON) return 1;',
    '        if (a == ABILITY_CHA) return -2;',
    '        return 0;',
    '    }',
    '    if (r == RACE_HALFLING) {',
    '        if (a == ABILITY_STR) return -1;',
    '        if (a == ABILITY_DEX) return 1;',
    '        return 0;',
    '    }',
    '    return 0;   // gnome, half-elf, human',
    '}',
    '',
    '// Table III: [race][ability][0 = male, 1 = female].',
    '// The printed minimums are identical for males and females',
    '// (every min column prints the same value twice); the',
    '// maximums differ only where the print shows M/F rows.',
    'static const int kMin[RACE_CHAR_COUNT][ABILITY_COUNT][2] = {',
    '    // human',
    '    { { 3, 3}, { 3, 3}, { 3, 3}, { 3, 3}, { 3, 3}, { 3, 3} },',
    '    // dwarf',
    '    { { 8, 8}, { 3, 3}, { 3, 3}, { 3, 3}, {12,12}, { 3, 3} },',
    '    // elf',
    '    { { 3, 3}, { 8, 8}, { 3, 3}, { 7, 7}, { 6, 6}, { 8, 8} },',
    '    // gnome',
    '    { { 6, 6}, { 7, 7}, { 3, 3}, { 3, 3}, { 8, 8}, { 3, 3} },',
    '    // half-elf',
    '    { { 3, 3}, { 4, 4}, { 3, 3}, { 6, 6}, { 6, 6}, { 3, 3} },',
    '    // halfling',
    '    { { 6, 6}, { 6, 6}, { 3, 3}, { 8, 8}, {10,10}, { 3, 3} },',
    '    // half-orc',
    '    { { 6, 6}, { 3, 3}, { 3, 3}, { 3, 3}, {13,13}, { 3, 3} },',
    '};',
    'static const int kMax[RACE_CHAR_COUNT][ABILITY_COUNT][2] = {',
    '    // human',
    '    { {18,18}, {18,18}, {18,18}, {18,18}, {18,18}, {18,18} },',
    '    // dwarf',
    '    { {18,17}, {18,18}, {18,18}, {17,17}, {19,19}, {16,16} },',
    '    // elf',
    '    { {18,16}, {18,18}, {18,18}, {19,19}, {18,18}, {18,18} },',
    '    // gnome',
    '    { {18,15}, {18,18}, {18,18}, {18,18}, {18,18}, {18,18} },',
    '    // half-elf',
    '    { {18,17}, {18,18}, {18,18}, {18,18}, {18,18}, {18,18} },',
    '    // halfling',
    '    { {17,14}, {18,18}, {17,17}, {18,18}, {19,19}, {18,18} },',
    '    // half-orc',
    '    { {18,18}, {17,17}, {14,14}, {17,17}, {19,19}, {12,12} },',
    '};',
    '',
    'static void clampRaceIndex(CharRace& r) {',
    '    if (r < 0 || r >= RACE_CHAR_COUNT) r = RACE_HUMAN;',
    '}',
    '',
    'int raceAbilityMin(CharRace r, Ability a, bool female) {',
    '    clampRaceIndex(r);',
    '    if (a < 0 || a >= ABILITY_COUNT) a = ABILITY_STR;',
    '    return kMin[r][a][female ? 1 : 0];',
    '}',
    '',
    'int raceAbilityMax(CharRace r, Ability a, bool female) {',
    '    clampRaceIndex(r);',
    '    if (a < 0 || a >= ABILITY_COUNT) a = ABILITY_STR;',
    '    return kMax[r][a][female ? 1 : 0];',
    '}',
    '',
    'void applyRacialAdjustments(AbilityScores& s, CharRace r,',
    '                            bool female) {',
    '    clampRaceIndex(r);',
    '    for (int i = 0; i < ABILITY_COUNT; ++i) {',
    '        Ability a = (Ability)i;',
    '        int v = s.get(a) + raceAbilityAdj(r, a);',
    '        int mx = raceAbilityMax(r, a, female);',
    '        if (v > mx) v = mx;',
    '        s.set(a, (uint8_t)v);',
    '    }',
    '}',
    '',
    'bool raceMeetsMinimums(const AbilityScores& s, CharRace r,',
    '                       bool female) {',
    '    clampRaceIndex(r);',
    '    for (int i = 0; i < ABILITY_COUNT; ++i) {',
    '        Ability a = (Ability)i;',
    '        if (s.get(a) + raceAbilityAdj(r, a)',
    '            < raceAbilityMin(r, a, female))',
    '            return false;',
    '    }',
    '    return true;',
    '}',
    '',
    'int raceInfravisionFeet(CharRace r) {',
    '    switch (r) {',
    '        case RACE_DWARF: case RACE_ELF: case RACE_GNOME:',
    '        case RACE_HALF_ELF: case RACE_HALF_ORC:',
    '            return 60;',
    '        case RACE_HALFLING:',
    '            return 30;   // the mixed-blood line (Stouts 60)',
    '        default:',
    '            return 0;    // human',
    '    }',
    '}',
    '',
    'int raceSleepCharmResistPct(CharRace r) {',
    '    if (r == RACE_ELF) return 90;',
    '    if (r == RACE_HALF_ELF) return 30;',
    '    return 0;',
    '}',
    '',
    '// the R147 dwarf shape: +1 per 3.5 points of CON, clamped',
    '// 0..5 - matches every printed band (4-6 +1, 7-10 +2,',
    '// 11-13 +3, 14-17 +4, 18 +5)',
    'static int conSaveBonusShape(uint8_t con) {',
    '    int b = ((int)con * 2) / 7;',
    '    if (b < 0) b = 0;',
    '    if (b > 5) b = 5;',
    '    return b;',
    '}',
    '',
    'int raceMagicSaveBonus(CharRace r, uint8_t con) {',
    '    if (r == RACE_DWARF || r == RACE_GNOME',
    '        || r == RACE_HALFLING)',
    '        return conSaveBonusShape(con);',
    '    return 0;',
    '}',
    '',
    'int racePoisonSaveBonus(CharRace r, uint8_t con) {',
    '    if (r == RACE_DWARF || r == RACE_HALFLING)',
    '        return conSaveBonusShape(con);',
    '    return 0;   // the gnome print names magic only',
    '}',
    '',
    'bool classAllowedForRace(int classIndex, CharRace r) {',
    '    // Race Table I, the base four classes',
    '    if (classIndex == CLASS_FIGHTER) return true;',
    '    if (classIndex == CLASS_MAGIC_USER)',
    '        return r == RACE_ELF || r == RACE_HALF_ELF',
    '            || r == RACE_HUMAN;',
    '    if (classIndex == CLASS_CLERIC)',
    '        return r == RACE_HALF_ELF || r == RACE_HALF_ORC',
    '            || r == RACE_HUMAN;',
    '    if (classIndex == CLASS_THIEF) return true;',
    '    return false;',
    '}',
    '',
    'int raceLevelCap(int classIndex, CharRace r, uint8_t str,',
    '                 uint8_t int_, uint8_t dex) {',
    '    if (!classAllowedForRace(classIndex, r)) return 0;',
    '    if (r == RACE_HUMAN) return -1;   // no limit',
    '    if (classIndex == CLASS_FIGHTER) {',
    '        switch (r) {',
    '            case RACE_DWARF:   // f1: <17: 7, 17: 8, 18: 9',
    '                if (str >= 18) return 9;',
    '                return str == 17 ? 8 : 7;',
    '            case RACE_ELF:     // f2: <17: 5, 17: 6, 18: 7',
    '                if (str >= 18) return 7;',
    '                return str == 17 ? 6 : 5;',
    '            case RACE_GNOME:   // f3: <18: 5, 18: 6',
    '                return str >= 18 ? 6 : 5;',
    '            case RACE_HALF_ELF: // f4: <17: 6, 17: 7, 18: 8',
    '                if (str >= 18) return 8;',
    '                return str == 17 ? 7 : 6;',
    '            case RACE_HALFLING:',
    '                // f5: sub-race bands - the engine takes',
    '                // the STR ladder on the Tallfellow best',
    '                // line (<17: 4, 17: 5, 18: 6); the',
    '                // Stout-at-18 5 cap is sub-race narration',
    '                if (str >= 18) return 6;',
    '                return str == 17 ? 5 : 4;',
    '            case RACE_HALF_ORC:',
    '                return 10;',
    '            default:',
    '                return -1;',
    '        }',
    '    }',
    '    if (classIndex == CLASS_MAGIC_USER) {',
    '        if (r == RACE_ELF) {   // f6: <17 INT: 9, 17: 10',
    '            if (int_ >= 18) return 11;',
    '            return int_ == 17 ? 10 : 9;',
    '        }',
    '        if (r == RACE_HALF_ELF) {   // f7: <17: 6, 17: 7',
    '            if (int_ >= 18) return 8;',
    '            return int_ == 17 ? 7 : 6;',
    '        }',
    '        return -1;',
    '    }',
    '    if (classIndex == CLASS_CLERIC) {',
    '        if (r == RACE_HALF_ELF) return 5;',
    '        if (r == RACE_HALF_ORC) return 4;',
    '        return -1;   // the parenthesized dwarf/elf/gnome',
    '    }                // cleric caps are NPC-only per print',
    '    if (classIndex == CLASS_THIEF) {',
    '        if (r == RACE_HALF_ORC) {   // f9: <17 DEX: 6, 17: 7',
    '            if (dex >= 18) return 8;',
    '            return dex == 17 ? 7 : 6;',
    '        }',
    '        return -1;',
    '    }',
    '    return -1;',
    '}',
    '',
    '// the printed foe lists (base names, null-terminated)',
    'static const char* const kDwarfBonusFoes[] = {',
    '    "half-orc", "goblin", "hobgoblin", "orc", nullptr',
    '};',
    'static const char* const kGnomeBonusFoes[] = {',
    '    "kobold", "goblin", nullptr',
    '};',
    'static const char* const kDwarfGiantKind[] = {',
    '    "ogre", "troll", "ogre mage", "giant", "titan", nullptr',
    '};',
    'static const char* const kGnomeGiantKind[] = {',
    '    "gnoll", "bugbear", "ogre", "troll", "ogre mage",',
    '    "giant", "titan", nullptr',
    '};',
    '',
    'static bool nameOnList(const char* const* list,',
    '                       const char* name) {',
    '    if (!name) return false;',
    '    for (int i = 0; list[i]; ++i)',
    '        if (std::strcmp(name, list[i]) == 0) return true;',
    '    return false;',
    '}',
    '',
    'int raceBonusVsFoeName(CharRace r, const char* foeName) {',
    '    if (r == RACE_DWARF)',
    '        return nameOnList(kDwarfBonusFoes, foeName) ? 1 : 0;',
    '    if (r == RACE_GNOME)',
    '        return nameOnList(kGnomeBonusFoes, foeName) ? 1 : 0;',
    '    return 0;',
    '}',
    '',
    'int raceFoeAttackPenalty(CharRace r, const char* foeName) {',
    '    if (r == RACE_DWARF)',
    '        return nameOnList(kDwarfGiantKind, foeName) ? 4 : 0;',
    '    if (r == RACE_GNOME)',
    '        return nameOnList(kGnomeGiantKind, foeName) ? 4 : 0;',
    '    return 0;',
    '}',
    '',
    'static const ChanceIn kDetectNone = { 0, 0 };',
    '',
    'ChanceIn raceDetectChance(CharRace r, DetectKind k) {',
    '    switch (k) {',
    '        case DET_GRADE:',
    '            if (r == RACE_DWARF) return ChanceIn{ 3, 4 };',
    '            if (r == RACE_GNOME) return ChanceIn{ 8, 10 };',
    '            if (r == RACE_HALFLING) return ChanceIn{ 3, 4 };',
    '            return kDetectNone;',
    '        case DET_NEW_CONSTRUCTION:',
    '            if (r == RACE_DWARF) return ChanceIn{ 3, 4 };',
    '            return kDetectNone;',
    '        case DET_SLIDING_WALLS:',
    '            if (r == RACE_DWARF) return ChanceIn{ 4, 6 };',
    '            return kDetectNone;',
    '        case DET_STONE_TRAPS:',
    '            if (r == RACE_DWARF) return ChanceIn{ 2, 4 };',
    '            return kDetectNone;',
    '        case DET_DEPTH:',
    '            if (r == RACE_DWARF) return ChanceIn{ 1, 2 };',
    '            if (r == RACE_GNOME) return ChanceIn{ 6, 10 };',
    '            return kDetectNone;',
    '        case DET_UNSAFE_SURFACES:',
    '            if (r == RACE_GNOME) return ChanceIn{ 7, 10 };',
    '            return kDetectNone;',
    '        case DET_DIRECTION:',
    '            if (r == RACE_GNOME) return ChanceIn{ 1, 2 };',
    '            if (r == RACE_HALFLING) return ChanceIn{ 1, 2 };',
    '            return kDetectNone;',
    '        case DET_SECRET_PASS:',
    '            if (r == RACE_ELF || r == RACE_HALF_ELF)',
    '                return ChanceIn{ 1, 6 };',
    '            return kDetectNone;',
    '        case DET_SECRET_SEARCH:',
    '            if (r == RACE_ELF || r == RACE_HALF_ELF)',
    '                return ChanceIn{ 2, 6 };',
    '            return kDetectNone;',
    '        case DET_CONCEALED_SEARCH:',
    '            if (r == RACE_ELF || r == RACE_HALF_ELF)',
    '                return ChanceIn{ 3, 6 };',
    '            return kDetectNone;',
    '        default:',
    '            return kDetectNone;',
    '    }',
    '}',
    '',
    'int raceDetectPct(CharRace r, DetectKind k) {',
    '    ChanceIn c = raceDetectChance(r, k);',
    '    if (c.den <= 0) return 0;',
    '    return (c.num * 100) / c.den;',
    '}',
    '',
    '} // namespace rules',
    '',
])

# ---- (3) preflight.sh: the battery build ----
pf_old = NL.join([
    '  rules/saves.cpp rules/turn.cpp dm/dm.cpp dm/dungeon.cpp dm/encounters.cpp ' + BS + '',
])
pf_new = NL.join([
    '  rules/saves.cpp rules/turn.cpp rules/races.cpp ' + BS + '',
    '  dm/dm.cpp dm/dungeon.cpp dm/encounters.cpp ' + BS + '',
])

# ---- (4) regtest.cpp: the include ----
inc_old = NL.join([
    '#include "abilities/abilities.h"',
])
inc_new = NL.join([
    '#include "abilities/abilities.h"',
    '#include "rules/races.h"   // R154: pp.15-18 Race Tables I-III',
])

# ---- (5) regtest.cpp: the R154 audit block ----
aud_old = NL.join([
    '        printf("R153 exceptional strength audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
])
aud_new = NL.join([
    '        printf("R153 exceptional strength audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R154: PC races audit ---------------------------------',
    '    // PHB pp.15-18, Race Tables I-III: the racial ability',
    '    // adjustments, the Table III minimums and maximums',
    '    // (male and female columns), infravision, the',
    '    // sleep-and-charm resistance, the CON magic-save bonus',
    '    // (dwarf, gnome, halfling - the R147 shape) with the',
    '    // poison finding (the print gives the gnome MAGIC',
    '    // ONLY; dwarf and halfling ride poison too - the gap',
    '    // box claimed gnome poison, the print wins), Race',
    '    // Table I class limitations, the footnoted Race Table',
    '    // II level caps, the goblin-kind and giant-kind',
    '    // to-hit lists and the detection lists. The creation',
    '    // RACE stage itself lives in appstate/adnd1 (the game',
    '    // layer is outside the battery build; its syntax gate',
    '    // compiles appstate.h via game/*.cpp).',
    '    {',
    '        int bad = 0;',
    '        namespace RS = rules;',
    '        // the Penalties and Bonuses list, all races x abilities',
    '        static const int kAdj[7][6] = {',
    '            {  0,  0,  0,  0,  0,  0 },   // human',
    '            {  0,  0,  0,  0,  1, -1 },   // dwarf',
    '            {  0,  0,  0,  1, -1,  0 },   // elf',
    '            {  0,  0,  0,  0,  0,  0 },   // gnome',
    '            {  0,  0,  0,  0,  0,  0 },   // half-elf',
    '            { -1,  0,  0,  1,  0,  0 },   // halfling',
    '            {  1,  0,  0,  0,  1, -2 },   // half-orc',
    '        };',
    '        for (int r = 0; r < 7; ++r)',
    '            for (int a = 0; a < 6; ++a)',
    '                if (RS::raceAbilityAdj((RS::CharRace)r,',
    '                        (RS::Ability)a) != kAdj[r][a])',
    '                    ++bad;',
    '        // Table III minimums (identical M/F in print)',
    '        static const int kMin[7][6] = {',
    '            {  3,  3,  3,  3,  3,  3 },   // human',
    '            {  8,  3,  3,  3, 12,  3 },   // dwarf',
    '            {  3,  8,  3,  7,  6,  8 },   // elf',
    '            {  6,  7,  3,  3,  8,  3 },   // gnome',
    '            {  3,  4,  3,  6,  6,  3 },   // half-elf',
    '            {  6,  6,  3,  8, 10,  3 },   // halfling',
    '            {  6,  3,  3,  3, 13,  3 },   // half-orc',
    '        };',
    '        // Table III maximums, male then female columns',
    '        static const int kMaxM[7][6] = {',
    '            { 18, 18, 18, 18, 18, 18 },   // human',
    '            { 18, 18, 18, 17, 19, 16 },   // dwarf',
    '            { 18, 18, 18, 19, 18, 18 },   // elf',
    '            { 18, 18, 18, 18, 18, 18 },   // gnome',
    '            { 18, 18, 18, 18, 18, 18 },   // half-elf',
    '            { 17, 18, 17, 18, 19, 18 },   // halfling',
    '            { 18, 17, 14, 17, 19, 12 },   // half-orc',
    '        };',
    '        static const int kMaxF[7][6] = {',
    '            { 18, 18, 18, 18, 18, 18 },   // human',
    '            { 17, 18, 18, 17, 19, 16 },   // dwarf',
    '            { 16, 18, 18, 19, 18, 18 },   // elf',
    '            { 15, 18, 18, 18, 18, 18 },   // gnome',
    '            { 17, 18, 18, 18, 18, 18 },   // half-elf',
    '            { 14, 18, 17, 18, 19, 18 },   // halfling',
    '            { 18, 17, 14, 17, 19, 12 },   // half-orc',
    '        };',
    '        for (int r = 0; r < 7; ++r)',
    '            for (int a = 0; a < 6; ++a) {',
    '                if (RS::raceAbilityMin((RS::CharRace)r,',
    '                        (RS::Ability)a, false) != kMin[r][a])',
    '                    ++bad;',
    '                if (RS::raceAbilityMin((RS::CharRace)r,',
    '                        (RS::Ability)a, true) != kMin[r][a])',
    '                    ++bad;',
    '                if (RS::raceAbilityMax((RS::CharRace)r,',
    '                        (RS::Ability)a, false) != kMaxM[r][a])',
    '                    ++bad;',
    '                if (RS::raceAbilityMax((RS::CharRace)r,',
    '                        (RS::Ability)a, true) != kMaxF[r][a])',
    '                    ++bad;',
    '            }',
    '        // infravision and sleep-and-charm resistance',
    '        static const int kInfra[7] = { 0, 60, 60, 60, 60, 30, 60 };',
    '        static const int kSleep[7] = { 0,  0, 90,  0, 30,  0,  0 };',
    '        for (int r = 0; r < 7; ++r) {',
    '            if (RS::raceInfravisionFeet((RS::CharRace)r)',
    '                != kInfra[r]) ++bad;',
    '            if (RS::raceSleepCharmResistPct((RS::CharRace)r)',
    '                != kSleep[r]) ++bad;',
    '        }',
    '        // the CON magic-save bands, every score 3-18, per',
    '        // race - plus the poison finding (gnome: magic only)',
    '        for (int c = 3; c <= 18; ++c) {',
    '            int shape = (c * 2) / 7;',
    '            if (shape > 5) shape = 5;',
    '            for (int r = 0; r < 7; ++r) {',
    '                bool magicRace =',
    '                    r == RS::RACE_DWARF || r == RS::RACE_GNOME',
    '                    || r == RS::RACE_HALFLING;',
    '                bool poisonRace =',
    '                    r == RS::RACE_DWARF || r == RS::RACE_HALFLING;',
    '                if (RS::raceMagicSaveBonus((RS::CharRace)r,',
    '                        (uint8_t)c) != (magicRace ? shape : 0))',
    '                    ++bad;',
    '                if (RS::racePoisonSaveBonus((RS::CharRace)r,',
    '                        (uint8_t)c) != (poisonRace ? shape : 0))',
    '                    ++bad;',
    '            }',
    '        }',
    '        // Race Table I: class limitations, the base four',
    '        static const bool kAllow[4][7] = {',
    '            { true, true, true, true, true, true, true },   // F',
    '            { true, false, true, false, true, false, false },   // MU',
    '            { true, false, false, false, true, false, true },   // C',
    '            { true, true, true, true, true, true, true },   // T',
    '        };',
    '        for (int ci = 0; ci < 4; ++ci)',
    '            for (int r = 0; r < 7; ++r)',
    '                if (RS::classAllowedForRace(ci,',
    '                        (RS::CharRace)r) != kAllow[ci][r])',
    '                    ++bad;',
    '        // Race Table II level caps, with the footnotes',
    '        static const struct {',
    '            int ci; int r; int s; int dex; int cap;',
    '        } kCap[] = {',
    '            // fighter, footnote STR ladders',
    '            { 0, 1, 16, 0,  7 }, { 0, 1, 17, 0,  8 },',
    '            { 0, 1, 18, 0,  9 },',
    '            { 0, 2, 16, 0,  5 }, { 0, 2, 17, 0,  6 },',
    '            { 0, 2, 18, 0,  7 },',
    '            { 0, 3, 17, 0,  5 }, { 0, 3, 18, 0,  6 },',
    '            { 0, 4, 16, 0,  6 }, { 0, 4, 17, 0,  7 },',
    '            { 0, 4, 18, 0,  8 },',
    '            { 0, 5, 16, 0,  4 }, { 0, 5, 17, 0,  5 },',
    '            { 0, 5, 18, 0,  6 },',
    '            { 0, 6,  0, 0, 10 },',
    '            // magic-user, footnote INT ladders',
    '            { 1, 2, 16, 0,  9 }, { 1, 2, 17, 0, 10 },',
    '            { 1, 2, 18, 0, 11 },',
    '            { 1, 4, 16, 0,  6 }, { 1, 4, 17, 0,  7 },',
    '            { 1, 4, 18, 0,  8 },',
    '            // cleric caps (half-elf, half-orc)',
    '            { 2, 4,  0, 0,  5 },',
    '            { 2, 6,  0, 0,  4 },',
    '            // thief, the half-orc footnote DEX ladder',
    '            { 3, 6,  0, 16, 6 }, { 3, 6,  0, 17, 7 },',
    '            { 3, 6,  0, 18, 8 },',
    '            // unlimited: human everywhere, dwarf thief',
    '            { 0, 0,  0, 0, -1 }, { 1, 0,  0, 0, -1 },',
    '            { 2, 0,  0, 0, -1 }, { 3, 0,  0, 0, -1 },',
    '            { 3, 1,  0, 0, -1 },',
    '            // not allowed: MU dwarf, cleric dwarf/elf/gnome',
    '            { 1, 1, 18, 0,  0 }, { 2, 1,  0, 0,  0 },',
    '            { 2, 2,  0, 0,  0 }, { 2, 3,  0, 0,  0 },',
    '        };',
    '        for (size_t i = 0; i < sizeof(kCap)/sizeof(kCap[0]); ++i)',
    '            if (RS::raceLevelCap(kCap[i].ci,',
    '                    (RS::CharRace)kCap[i].r,',
    '                    (uint8_t)kCap[i].s,',
    '                    (uint8_t)kCap[i].s,',
    '                    (uint8_t)kCap[i].dex) != kCap[i].cap)',
    '                ++bad;',
    '        // the goblin-kind and giant-kind to-hit lists',
    '        static const struct {',
    '            int r; const char* foe; int bonus; int pen;',
    '        } kFoe[] = {',
    '            { 1, "half-orc",   1, 0 }, { 1, "goblin", 1, 0 },',
    '            { 1, "hobgoblin",  1, 0 }, { 1, "orc",    1, 0 },',
    '            { 1, "gnoll",      0, 0 }, { 1, "kobold", 0, 0 },',
    '            { 1, "ogre",       0, 4 }, { 1, "troll",  0, 4 },',
    '            { 1, "ogre mage",  0, 4 }, { 1, "giant",  0, 4 },',
    '            { 1, "titan",      0, 4 },',
    '            { 1, "gnoll",      0, 0 },   // dwarf: no gnoll pen',
    '            { 1, "bugbear",    0, 0 },',
    '            { 3, "kobold",     1, 0 }, { 3, "goblin", 1, 0 },',
    '            { 3, "orc",        0, 0 },',
    '            { 3, "gnoll",      0, 4 }, { 3, "bugbear", 0, 4 },',
    '            { 3, "ogre",       0, 4 }, { 3, "troll",   0, 4 },',
    '            { 3, "ogre mage",  0, 4 }, { 3, "giant",  0, 4 },',
    '            { 3, "titan",      0, 4 },',
    '            { 0, "goblin",     0, 0 }, { 2, "ogre",   0, 0 },',
    '            { 4, "goblin",     0, 0 },',
    '        };',
    '        for (size_t i = 0; i < sizeof(kFoe)/sizeof(kFoe[0]); ++i)',
    '            if (RS::raceBonusVsFoeName((RS::CharRace)kFoe[i].r,',
    '                    kFoe[i].foe) != kFoe[i].bonus',
    '                || RS::raceFoeAttackPenalty(',
    '                    (RS::CharRace)kFoe[i].r,',
    '                    kFoe[i].foe) != kFoe[i].pen)',
    '                ++bad;',
    '        // the detection lists, in-N pairs + spot percents',
    '        static const struct {',
    '            int r; RS::DetectKind k; int num; int den;',
    '        } kDet[] = {',
    '            { 1, RS::DET_GRADE,           3,  4 },',
    '            { 1, RS::DET_NEW_CONSTRUCTION, 3,  4 },',
    '            { 1, RS::DET_SLIDING_WALLS,   4,  6 },',
    '            { 1, RS::DET_STONE_TRAPS,      2,  4 },',
    '            { 1, RS::DET_DEPTH,            1,  2 },',
    '            { 3, RS::DET_GRADE,            8, 10 },',
    '            { 3, RS::DET_UNSAFE_SURFACES,  7, 10 },',
    '            { 3, RS::DET_DEPTH,            6, 10 },',
    '            { 3, RS::DET_DIRECTION,        1,  2 },',
    '            { 5, RS::DET_GRADE,            3,  4 },',
    '            { 5, RS::DET_DIRECTION,        1,  2 },',
    '            { 2, RS::DET_SECRET_PASS,      1,  6 },',
    '            { 2, RS::DET_SECRET_SEARCH,     2,  6 },',
    '            { 2, RS::DET_CONCEALED_SEARCH,  3,  6 },',
    '            { 4, RS::DET_SECRET_PASS,      1,  6 },',
    '            { 4, RS::DET_SECRET_SEARCH,     2,  6 },',
    '            { 4, RS::DET_CONCEALED_SEARCH,  3,  6 },',
    '        };',
    '        for (size_t i = 0; i < sizeof(kDet)/sizeof(kDet[0]); ++i) {',
    '            RS::ChanceIn c = RS::raceDetectChance(',
    '                (RS::CharRace)kDet[i].r, kDet[i].k);',
    '            if (c.num != kDet[i].num || c.den != kDet[i].den)',
    '                ++bad;',
    '        }',
    '        // a race with no entry reads 0-in-0 (and pct 0)',
    '        for (int r = 0; r < 7; ++r) {',
    '            RS::ChanceIn c = RS::raceDetectChance(',
    '                (RS::CharRace)r, RS::DET_SLIDING_WALLS);',
    '            bool dwarf = (r == RS::RACE_DWARF);',
    '            if (dwarf != (c.num == 4 && c.den == 6)) ++bad;',
    '            if (RS::raceDetectPct((RS::CharRace)r,',
    '                    RS::DET_SLIDING_WALLS) != (dwarf ? 66 : 0))',
    '                ++bad;',
    '        }',
    '        if (RS::raceDetectPct(RS::RACE_DWARF,',
    '                RS::DET_GRADE) != 75',
    '            || RS::raceDetectPct(RS::RACE_ELF,',
    '                RS::DET_SECRET_PASS) != 16) ++bad;',
    '        // applyRacialAdjustments + eligibility spot checks',
    '        RS::AbilityScores s;',
    '        s.str = 18; s.con = 18; s.cha = 18;',
    '        RS::applyRacialAdjustments(s, RS::RACE_DWARF, false);',
    '        if (s.str != 18 || s.con != 19 || s.cha != 16) ++bad;',
    '        s.str = 18; s.dex = 18; s.con = 18;',
    '        RS::applyRacialAdjustments(s, RS::RACE_ELF, false);',
    '        if (s.str != 18 || s.dex != 19 || s.con != 17) ++bad;',
    '        s.str = 18; s.dex = 18;',
    '        RS::applyRacialAdjustments(s, RS::RACE_ELF, true);',
    '        if (s.str != 16) ++bad;   // female STR max 16',
    '        s.str = 18; s.dex = 18; s.con = 18;',
    '        RS::applyRacialAdjustments(s, RS::RACE_HALFLING, false);',
    '        if (s.str != 17 || s.dex != 18) ++bad;',
    '        s.str = 18; s.con = 18; s.cha = 18;',
    '        RS::applyRacialAdjustments(s, RS::RACE_HALF_ORC, false);',
    '        // STR 18+1 clamps to the 18 max, CON reaches 19,',
    '        // CHA 18-2 = 16 clamps to the 12 max (Table III)',
    '        if (s.str != 18 || s.con != 19 || s.cha != 12) ++bad;',
    '        RS::AbilityScores e;',
    '        e.con = 11;',
    '        if (!RS::raceMeetsMinimums(e, RS::RACE_DWARF, false)) ++bad;',
    '        e.con = 10;',
    '        if (RS::raceMeetsMinimums(e, RS::RACE_DWARF, false)) ++bad;',
    '        e.con = 18; e.str = 7;',
    '        if (!RS::raceMeetsMinimums(e, RS::RACE_HALFLING, false))',
    '            ++bad;',
    '        e.str = 6;',
    '        if (RS::raceMeetsMinimums(e, RS::RACE_HALFLING, false)) ++bad;',
    '        printf("R154 PC races audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
])

# ---- (6) party.h: Character.race ----
pr_old = NL.join([
    '    rules::AbilityScores     abilities;',
    '    rules::ExceptionalStrength exStr;   // fighter group + STR 18 only',
])
pr_new = NL.join([
    '    rules::AbilityScores     abilities;',
    '    rules::ExceptionalStrength exStr;   // fighter group + STR 18 only',
    '    // R154: racial stock (rules::CharRace; 0 = human, the',
    '    // v1-save default). Optional "race" line in the save.',
    '    int  race = 0;',
])

# ---- (7) appstate.h: the races include ----
ai_old = NL.join([
    '#include "../rules/classes.h"',
    '#include "../rules/saves.h"   // R45: trap saves',
])
ai_new = NL.join([
    '#include "../rules/classes.h"',
    '#include "../rules/races.h"   // R154: Race Tables I-III',
    '#include "../rules/saves.h"   // R45: trap saves',
])

# ---- (8) appstate.h: the CR_RACE stage ----
en_old = NL.join([
    'enum CreationStage : int {',
    '    CR_ROLL = 0,',
    '    CR_CLASS,',
])
en_new = NL.join([
    'enum CreationStage : int {',
    '    CR_ROLL = 0,',
    '    CR_RACE,    // R154: the racial stock stage',
    '    CR_CLASS,',
])

# ---- (9) appstate.h: CreationState fields ----
fld_old = NL.join([
    '    rules::AbilityScores rolled;',
    '    int  classPick = 0;              // highlighted class row',
])
fld_new = NL.join([
    '    rules::AbilityScores rolled;',
    '    int  racePick = 0;               // R154: highlighted race row',
    '    bool female = false;             // R154: Table III M/F columns',
    '    int  classPick = 0;              // highlighted class row',
])

# ---- (10) appstate.h: rollFresh resets ----
rf_old = NL.join([
    '        stage = CR_ROLL;',
    '        classPick = 0;',
    '        nameBuf.clear();',
])
rf_new = NL.join([
    '        stage = CR_ROLL;',
    '        racePick = 0;     // R154',
    '        female = false;   // R154',
    '        classPick = 0;',
    '        nameBuf.clear();',
])

# ---- (11) appstate.h: raceAdjusted/raceEligible ----
ce_old = NL.join([
    '    // eligibility: prime requisite score meets the class minimum',
    '    bool classEligible(int classIndex) const {',
    '        int ab = rolled.get(',
    '            (rules::Ability)rules::primeRequisite(classIndex));',
    '        return ab >= rules::classMinAbility(classIndex);',
    '    }',
])
ce_new = NL.join([
    '    // R154: the scores as this race would carry them - the',
    '    // racial adjustment applied, then the Table III maximum',
    '    // clamp (the print: adjusted scores are the actual',
    '    // scores for all game purposes)',
    '    rules::AbilityScores raceAdjusted() const {',
    '        rules::AbilityScores s = rolled;',
    '        rules::applyRacialAdjustments(s,',
    '            (rules::CharRace)racePick, female);',
    '        return s;',
    '    }',
    '',
    '    // R154: Table III eligibility - minimums met considering',
    '    // the racial bonuses',
    '    bool raceEligible(int raceIdx) const {',
    '        return rules::raceMeetsMinimums(rolled,',
    '            (rules::CharRace)raceIdx, female);',
    '    }',
    '',
    '    // eligibility: prime requisite meets the class minimum,',
    '    // and Race Table I allows the class for the race (R154)',
    '    bool classEligible(int classIndex) const {',
    '        int ab = raceAdjusted().get(',
    '            (rules::Ability)rules::primeRequisite(classIndex));',
    '        if (ab < rules::classMinAbility(classIndex))',
    '            return false;',
    '        return rules::classAllowedForRace(classIndex,',
    '            (rules::CharRace)racePick);',
    '    }',
])

# ---- (12) appstate.h: makeMember ----
mm_old = NL.join([
    '    Character makeMember(int classIndex) {',
    '        Character c;',
    '        c.abilities = rolled;',
    '        c.classIndex = classIndex;',
])
mm_new = NL.join([
    '    Character makeMember(int classIndex) {',
    '        Character c;',
    '        c.race = racePick;              // R154: the chosen stock',
    '        c.abilities = raceAdjusted();   // R154: adjusted is actual',
    '        c.classIndex = classIndex;',
])

# ---- (13) appstate.h: the exStr gate ----
ex_old = NL.join([
    '        // exceptional strength: fighter group at STR 18',
    '        if (classIndex == rules::CLASS_FIGHTER &&',
    '            rolled.str == 18) {',
])
ex_new = NL.join([
    '        // exceptional strength: fighter group at STR 18',
    '        // (R154: the ADJUSTED score - a racial STR bonus can',
    '        // carry a male elf or half-orc fighter to 18)',
    '        if (classIndex == rules::CLASS_FIGHTER &&',
    '            c.abilities.str == 18) {',
])

# ---- (14) appstate.h: the conAdj line ----
ca_old = NL.join([
    '        // level-1 hit points (canonical signature, R4b)',
    '        int conAdj = rules::conHPAdjustment(classIndex, rolled.con);',
])
ca_new = NL.join([
    '        // level-1 hit points (canonical signature, R4b)',
    '        // R154: the ADJUSTED con (the racial bonus counts)',
    '        int conAdj = rules::conHPAdjustment(',
    '            classIndex, c.abilities.con);',
])

# ---- (15) state_core.cpp: reset ----
sc_old = NL.join([
    '        creation.stage = CR_ROLL;',
    '        creation.classPick = 0;',
])
sc_new = NL.join([
    '        creation.stage = CR_ROLL;',
    '        creation.racePick = 0;      // R154',
    '        creation.female = false;    // R154',
    '        creation.classPick = 0;',
])

# ---- (16) state_core.cpp: the save line ----
sv_old = NL.join([
    '                (int)c.armor.id, c.armor.plus,',
    '                c.shield ? 1 : 0);',
    '            // R56: the magic-shield enchant (nonzero only -',
])
sv_new = NL.join([
    '                (int)c.armor.id, c.armor.plus,',
    '                c.shield ? 1 : 0);',
    '            // R154: racial stock (nonzero only - v1 saves',
    '            // carry no line and load as human)',
    '            if (c.race != 0)',
    '                fprintf(f, "race %d' + BS + 'n", c.race);',
    '            // R56: the magic-shield enchant (nonzero only -',
])

# ---- (17) state_core.cpp: the load branch ----
ld_old = NL.join([
    '                if (strcmp(tag, "age") == 0) {',
])
ld_new = NL.join([
    '                if (strcmp(tag, "race") == 0) {',
    '                    int rc = 0;',
    '                    if (fscanf(f, "%d", &rc) != 1 ||',
    '                        rc < 0 ||',
    '                        rc >= rules::RACE_CHAR_COUNT) {',
    '                        fclose(f);',
    '                        log.add("adnd1.sav is corrupt (race).");',
    '                        return false;',
    '                    }',
    '                    c.race = rc;',
    '                } else if (strcmp(tag, "age") == 0) {',
])

# ---- (18) adnd1.cpp: roll accept ----
k1_old = NL.join([
    '                case VK_RETURN:',
    '                    cr.stage = CR_CLASS;',
    '                    break;',
])
k1_new = NL.join([
    '                case VK_RETURN:',
    '                    cr.stage = CR_RACE;   // R154: race first',
    '                    break;',
])

# ---- (19) adnd1.cpp: the CR_RACE keys ----
k2_old = NL.join([
    '        case CR_CLASS:',
    '            switch (wp) {',
])
k2_new = NL.join([
    '        case CR_RACE:   // R154: the racial stock choice',
    '            switch (wp) {',
    '                case ' + AP + '1' + AP + ': case ' + AP + '2' + AP + ':',
    '                case ' + AP + '3' + AP + ': case ' + AP + '4' + AP + ':',
    '                case ' + AP + '5' + AP + ': case ' + AP + '6' + AP + ':',
    '                case ' + AP + '7' + AP + ': {',
    '                    int idx = (int)(wp - ' + AP + '1' + AP + ');',
    '                    if (cr.raceEligible(idx)) {',
    '                        cr.racePick = idx;',
    '                        cr.classPick = 0;',
    '                        cr.stage = CR_CLASS;',
    '                    }',
    '                    break;',
    '                }',
    '                case ' + AP + 'X' + AP + ':',
    '                    cr.female = !cr.female;   // Table III M/F',
    '                    break;',
    '                case VK_ESCAPE:',
    '                    cr.stage = CR_ROLL;   // back to the dice',
    '                    break;',
    '            }',
    '            break;',
    '',
    '        case CR_CLASS:',
    '            switch (wp) {',
])

# ---- (20) adnd1.cpp: class Esc ----
k3_old = NL.join([
    '                case VK_ESCAPE:',
    '                    cr.stage = CR_ROLL;   // back to reroll',
    '                    break;',
])
k3_new = NL.join([
    '                case VK_ESCAPE:',
    '                    cr.stage = CR_RACE;   // back to race choice',
    '                    break;',
])

# ---- (21) adnd1.cpp: roll hint ----
h1_old = NL.join([
    '            TextOutA(dc, 20, VIEW_H - 60,',
    '                     "[R] reroll   [Enter] accept roll   [L] load save",',
])
h1_new = NL.join([
    '            TextOutA(dc, 20, VIEW_H - 60,',
    '                     "[R] reroll   [Enter] choose race   [L] load save",',
])

# ---- (22) adnd1.cpp: class hint ----
h2_old = NL.join([
    '                     "[1-4] choose class   [esc] back to roll",',
])
h2_new = NL.join([
    '                     "[1-4] choose class   [esc] back to race",',
])

# ---- (23) adnd1.cpp: the CR_RACE panel ----
r1_old = NL.join([
    '        case CR_CLASS: {',
    '            TextOutA(dc, 20, py, "CHOOSE A CLASS", 15);',
])
r1_new = NL.join([
    '        case CR_RACE: {   // R154: the racial stock table',
    '            TextOutA(dc, 20, py, "CHOOSE A RACE", 13);',
    '            py += 30;',
    '            for (int i = 0; i < rules::RACE_CHAR_COUNT; ++i) {',
    '                bool ok = cr.raceEligible(i);',
    '                char row[96];',
    '                snprintf(row, sizeof row, "  [%d] %-10s  %s",',
    '                         i + 1,',
    '                         rules::raceName((rules::CharRace)i),',
    '                         ok ? "" : "- min scores unmet");',
    '                SetTextColor(dc, ok ? RGB(210, 195, 165)',
    '                                    : RGB(110, 105, 95));',
    '                TextOutA(dc, 40, py, row, (int)strlen(row));',
    '                py += 26;',
    '            }',
    '            char sx[64];',
    '            snprintf(sx, sizeof sx, "  [X] sex: %s",',
    '                     cr.female ? "female" : "male");',
    '            SetTextColor(dc, RGB(210, 195, 165));',
    '            TextOutA(dc, 40, py + 4, sx, (int)strlen(sx));',
    '            SetTextColor(dc, RGB(190, 175, 140));',
    '            const char* rhint =',
    '                "[1-7] choose race   [X] sex   [esc] back";',
    '            TextOutA(dc, 20, VIEW_H - 60, rhint,',
    '                     (int)strlen(rhint));',
    '            break;',
    '        }',
    '',
    '        case CR_CLASS: {',
    '            TextOutA(dc, 20, py, "CHOOSE A CLASS", 15);',
])

# ---- (24) adnd1.cpp: the join message ----
jm_old = NL.join([
    '    snprintf(buf, sizeof buf, "%s the %s joins the party at %d years.",',
    '             c.name.c_str(), CLASS_NAMES[c.classIndex],',
    '             c.startAge);',
])
jm_new = NL.join([
    '    snprintf(buf, sizeof buf,',
    '             "%s the %s %s joins the party at %d years.",',
    '             c.name.c_str(),',
    '             rules::raceName((rules::CharRace)c.race),',
    '             CLASS_NAMES[c.classIndex], c.startAge);',
])

# ---- (25) gap report header ----
gh_old = NL.join([
    'Census 71.',
    '',
    'Categories:',
])
gh_new = NL.join([
    'Census 71.',
    'R154 PINNED the PC races layer (PHB pp.15-18, Race',
    'Tables I-III): the racial ability adjustments with',
    'the Table III minimums and maximums (male and female',
    'columns), infravision, elven 90% and half-elven 30%',
    'sleep-and-charm resistance, the CON magic-save bonus',
    'for dwarf, gnome and halfling (the R147 shape), Race',
    'Table I class limitations, the footnoted Race Table',
    'II level caps, the goblin-kind and giant-kind',
    'to-hit lists and the detection lists - and the',
    'creation flow gains the RACE stage (ROLL -> RACE ->',
    'CLASS -> NAME; appstate + the Win32 shell). FINDING:',
    'the print gives the gnome the magic-save bonus ONLY -',
    'no poison line rides it (dwarf and halfling carry',
    'both); the open box claimed gnome poison saves, the',
    'print wins. Census 72.',
    '',
    'Categories:',
])

# ---- (26) gap report box ----
gb_old = NL.join([
    '- [ ] **PC races layer (PHB pp.15-18, Race Tables I-III)**',
    '      - the races half of the authored-but-unlanded R148',
    '      combined splice: gnome and halfling CON magic-save',
    '      and poison-save bonuses (con*2/7, the R147 dwarf',
    '      shape), elven 90% / half-elven 30% sleep-and-charm',
    '      resistance, infravision, the racial detection',
    '      lists, ability adjustments with min/max, footnoted',
    '      level caps, race to-hit adjustments vs. goblin-kind',
    '      and giant-kind, and the creation-stage',
    '      ROLL->RACE->CLASS->NAME flow. Must be re-authored',
    '      against current main - the combined splice is',
    '      stale (its 18 R147 patches already landed).',
])
gb_new = NL.join([
    '- [x] **PC races layer (PHB pp.15-18, Race Tables I-III)**',
    '      - PINNED R154, re-authored against current main in',
    '      the new rules/races layer: the adjustments, the',
    '      Table III min/max (M/F), infravision, sleep-and-',
    '      charm resistance, the CON magic-save bonuses',
    '      (gnome poison corrected OUT - the print names',
    '      magic only), Race Tables I and II with every',
    '      printed footnote, the goblin-kind/giant-kind',
    '      to-hit lists and the detection lists; creation',
    '      gains the RACE stage and the save gains the',
    '      optional race line (the audit is the regtest.cpp',
    '      R154 block).',
])

# ---- run ----
create("rules/races.h", races_h_text,
      "rules/races.h: the PC races layer",
      marker="R154: the races half of the authored-but-unlanded")
assert len(applied) + len(already) == 1
create("rules/races.cpp", races_cpp_text,
      "rules/races.cpp: the PC races layer",
      marker="the gnome print names magic only")
assert len(applied) + len(already) == 2
patch("tools/preflight.sh", pf_old, pf_new,
      "preflight.sh: races.cpp joins the battery build",
      marker="rules/races.cpp")
assert len(applied) + len(already) == 3
patch("regtest.cpp", inc_old, inc_new,
      "regtest.cpp: races include",
      marker="R154: pp.15-18 Race Tables I-III")
assert len(applied) + len(already) == 4
patch("regtest.cpp", aud_old, aud_new,
      "regtest.cpp: R154 PC races audit",
      marker="R154 PC races audit")
assert len(applied) + len(already) == 5
patch("game/party.h", pr_old, pr_new,
      "party.h: Character.race field",
      marker="R154: racial stock (rules::CharRace; 0 = human")
assert len(applied) + len(already) == 6
patch("game/appstate.h", ai_old, ai_new,
      "appstate.h: races include",
      marker="rules/races.h")
assert len(applied) + len(already) == 7
patch("game/appstate.h", en_old, en_new,
      "appstate.h: the CR_RACE stage",
      marker="CR_RACE,    // R154: the racial stock stage")
assert len(applied) + len(already) == 8
patch("game/appstate.h", fld_old, fld_new,
      "appstate.h: racePick/female fields",
      marker="R154: highlighted race row")
assert len(applied) + len(already) == 9
patch("game/appstate.h", rf_old, rf_new,
      "appstate.h: rollFresh resets",
      marker="racePick = 0;     // R154")
assert len(applied) + len(already) == 10
patch("game/appstate.h", ce_old, ce_new,
      "appstate.h: raceAdjusted/raceEligible/classEligible",
      marker="rules::applyRacialAdjustments(s,")
assert len(applied) + len(already) == 11
patch("game/appstate.h", mm_old, mm_new,
      "appstate.h: makeMember applies the race",
      marker="c.abilities = raceAdjusted();")
assert len(applied) + len(already) == 12
patch("game/appstate.h", ex_old, ex_new,
      "appstate.h: exStr gate uses adjusted STR",
      marker="c.abilities.str == 18) {")
assert len(applied) + len(already) == 13
patch("game/appstate.h", ca_old, ca_new,
      "appstate.h: conAdj uses adjusted CON",
      marker="classIndex, c.abilities.con);")
assert len(applied) + len(already) == 14
patch("game/state_core.cpp", sc_old, sc_new,
      "state_core.cpp: creation reset",
      marker="creation.racePick = 0;      // R154")
assert len(applied) + len(already) == 15
patch("game/state_core.cpp", sv_old, sv_new,
      "state_core.cpp: the race save line",
      marker="race %d"),
assert len(applied) + len(already) == 16
patch("game/state_core.cpp", ld_old, ld_new,
      "state_core.cpp: the race load branch",
      marker="strcmp(tag, " + chr(34) + "race" + chr(34) + ") == 0")
assert len(applied) + len(already) == 17
patch("adnd1.cpp", k1_old, k1_new,
      "adnd1.cpp: roll accept goes to race",
      marker="cr.stage = CR_RACE;   // R154: race first")
assert len(applied) + len(already) == 18
patch("adnd1.cpp", k2_old, k2_new,
      "adnd1.cpp: the CR_RACE keys",
      marker="cr.raceEligible(idx)) {")
assert len(applied) + len(already) == 19
patch("adnd1.cpp", k3_old, k3_new,
      "adnd1.cpp: class Esc backs to race",
      marker="cr.stage = CR_RACE;   // back to race choice")
assert len(applied) + len(already) == 20
patch("adnd1.cpp", h1_old, h1_new,
      "adnd1.cpp: roll hint",
      marker="[Enter] choose race")
assert len(applied) + len(already) == 21
patch("adnd1.cpp", h2_old, h2_new,
      "adnd1.cpp: class hint",
      marker="[esc] back to race")
assert len(applied) + len(already) == 22
patch("adnd1.cpp", r1_old, r1_new,
      "adnd1.cpp: the CR_RACE panel",
      marker="CHOOSE A RACE")
assert len(applied) + len(already) == 23
patch("adnd1.cpp", jm_old, jm_new,
      "adnd1.cpp: the join message",
      marker="rules::raceName((rules::CharRace)c.race)")
assert len(applied) + len(already) == 24
patch("tools/dmg_gap_report.md", gh_old, gh_new,
      "gap report: R154 header note",
      marker="R154 PINNED the PC races layer")
assert len(applied) + len(already) == 25
patch("tools/dmg_gap_report.md", gb_old, gb_new,
      "gap report: PC races box closed",
      marker="PINNED R154, re-authored against current main")
assert len(applied) + len(already) == 26
# ---- R154 fails/tail ----
if fails:
    print("R154 splice: FAIL - " + str(len(fails))
          + " patch(es) failed:")
    for f in fails:
        print("  " + f)
    sys.exit(1)
if len(applied) + len(already) != 26:
    print("R154 splice: FAIL - expected 26 patches, counted "
          + str(len(applied) + len(already))
          + " (a truncated paste?)")
    sys.exit(1)
if already and not applied:
    print("R154 splice: ALL OK (applied 0, already "
          + str(len(already)) + ")")
else:
    print("R154 splice: ALL OK (applied " + str(len(applied))
          + ", already " + str(len(already)) + ")")
print("R154 note: 26 patches; the battery gains one audit")
print("line - AUDIT CENSUS 72; commit: R154: PC races pinned -")
print("Race Tables I-III, adjustments, caps, detection, the")
print("RACE stage (census 72)")
