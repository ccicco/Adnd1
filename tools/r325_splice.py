# ============================================================================
# Adnd1 - tools/r325_splice.py
# The R325 splice: the Race Table II
# caller round - the level-up fold.
#
# Patches (all idempotent; each patch
# is guarded and re-runnable):
#   (a) doc/vibe/adnd1_knowledge_seed_v2.md -
#       the R324 round-state entry (the
#       oracle-read-back lesson, the
#       preflight-ordering lesson, the
#       replay discipline).
#   (b) rules/subracecap.h - NEW FILE: the
#       caller seam - the vital-ability
#       read (the p.8 print), the column
#       key build (the exceptional
#       strength encoder), the +2
#       eligibility (the combo bit read),
#       the member class mapping, the
#       derived cap (uaLevelCap).
#   (c) game/party.h - the uaSubrace field
#       and the fold at both level-up
#       sites (the gainXp queue, the
#       trainer).
#   (d) game/state_core.cpp - the optional
#       save line and the load tag (v1
#       saves load as none).
#   (e) tools/ua_gap_report.md - the R324
#       close sentence gains the R325
#       close (the wiring is wired).
#   (f) regtest.cpp - the include and the
#       R325 audit (live AppState walks);
#       census 251 -> 252.
# ============================================================================

import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
Q = chr(39)
DQ = chr(34)
BS = chr(92)
applied, already = [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding='ascii') as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), 'w', encoding='ascii') as f:
        f.write(s)

def clean(s, limit):
    for ln in s.split(NL):
        assert all(ord(c) < 128 for c in ln), 'non-ascii line'
        assert len(ln) <= limit, 'line too long: ' + ln

def cleanNB(s, limit):
    # content that carries a built
    # backslash byte (the printf newline)
    for ln in s.split(NL):
        assert all(ord(c) < 128 for c in ln), 'non-ascii line'
        assert len(ln) <= limit, 'line too long: ' + ln

SR_FILE = NL.join([
    '// ===========================================================================',
    '// Adnd1 - rules/subracecap.h',
    '// The UA Race Table II caller seam (R325)',
    '// - the level-up site\'s derived cap read.',
    '//',
    '// The print (UA p.8): the sub-table level',
    '// limits key on the class\'s vital ability',
    '// - fighters, rangers and assassins read',
    '// strength; clerics and druids read',
    '// wisdom; magic-users and illusionists',
    '// read intelligence; thieves read',
    '// dexterity - and a single-classed',
    '// character whose class could have been',
    '// a multi-class choice for the race',
    '// exceeds the column by 2 (the Important',
    '// paragraph). The engine name-level cap',
    '// still binds above a UA limit that',
    '// exceeds it.',
    '// ===========================================================================',
    '',
    '#pragma once',
    '',
    '#include "subracelevels.h"   // the columns',
    '#include "subclasses.h"      // the registry ids',
    '#include "multiclass.h"      // the combo bits',
    '',
    'namespace rules {',
    '',
    '// The vital ability a Race Table II',
    '// column keys on (the p.8 read).',
    'inline int uaColumnAbility(UaClass c) {',
    '    switch (c) {',
    '        case UACLASS_CLERIC:',
    '        case UACLASS_DRUID:',
    '            return ABILITY_WIS;',
    '        case UACLASS_MAGIC_USER:',
    '        case UACLASS_ILLUSIONIST:',
    '            return ABILITY_INT;',
    '        case UACLASS_THIEF:',
    '        case UACLASS_ACROBAT:',
    '            return ABILITY_DEX;',
    '        default:',
    '            // the fighter group: fighter,',
    '            // ranger, assassin (cavalier and',
    '            // barbarian carry no column)',
    '            return ABILITY_STR;',
    '    }',
    '}',
    '',
    '// The column key from live scores: the',
    '// vital ability\'s score*1000, strength',
    '// through the exceptional encoder (no',
    '// exceptional roll reads the plain 18',
    '// row).',
    'inline int uaColumnKey(UaClass c,',
    '                       const AbilityScores& a,',
    '                       const ExceptionalStrength& ex) {',
    '    switch (uaColumnAbility(c)) {',
    '        case ABILITY_WIS:',
    '            return a.wis*1000;',
    '        case ABILITY_INT:',
    '            return a.int_*1000;',
    '        case ABILITY_DEX:',
    '            return a.dex*1000;',
    '        default:',
    '            return subraceStrengthLevelKey(',
    '                a.str,',
    '                ex.has ? (int)ex.pct : -1);',
    '    }',
    '}',
    '',
    '// The multi-class bit of a UA class (0 =',
    '// never a multi-class choice: cavalier,',
    '// paladin, barbarian, druid, acrobat,',
    '// monk, bard).',
    'inline int uaClassBit(UaClass c) {',
    '    switch (c) {',
    '        case UACLASS_FIGHTER:',
    '            return MC_FIGHTER;',
    '        case UACLASS_MAGIC_USER:',
    '            return MC_MAGIC_USER;',
    '        case UACLASS_CLERIC:',
    '            return MC_CLERIC;',
    '        case UACLASS_THIEF:',
    '            return MC_THIEF;',
    '        case UACLASS_ILLUSIONIST:',
    '            return MC_ILLUSIONIST;',
    '        case UACLASS_RANGER:',
    '            return MC_RANGER;',
    '        case UACLASS_ASSASSIN:',
    '            return MC_ASSASSIN;',
    '        default:',
    '            return 0;',
    '    }',
    '}',
    '',
    '// The print\'s +2 eligibility leg (b): the',
    '// class could be a multi-classed choice',
    '// for the character\'s race - some printed',
    '// combo of the parent race carries the',
    '// class bit.',
    'inline bool uaBonusEligible(CharSubRace s,',
    '                            UaClass c) {',
    '    int bit = uaClassBit(c);',
    '    if (bit == 0) return false;',
    '    int race = (int)subraceParentRace(s);',
    '    for (int i = 0;',
    '         i < multiClassComboCount(race); ++i)',
    '        if (multiClassCombo(race, i) & bit)',
    '            return true;',
    '    return false;',
    '}',
    '',
    '// The UA class of an engine member: the',
    '// registry subclass when set, else the',
    '// base class (the R230 runtime-base',
    '// convention).',
    'inline UaClass uaClassOfMember(int classIndex,',
    '                               int subclass) {',
    '    switch (subclass) {',
    '        case SUB_PALADIN:',
    '            return UACLASS_PALADIN;',
    '        case SUB_RANGER:',
    '            return UACLASS_RANGER;',
    '        case SUB_DRUID:',
    '            return UACLASS_DRUID;',
    '        case SUB_ILLUSIONIST:',
    '            return UACLASS_ILLUSIONIST;',
    '        case SUB_ASSASSIN:',
    '            return UACLASS_ASSASSIN;',
    '        case SUB_MONK:',
    '            return UACLASS_MONK;',
    '        default: break;',
    '    }',
    '    switch (classIndex) {',
    '        case 1: return UACLASS_MAGIC_USER;',
    '        case 2: return UACLASS_CLERIC;',
    '        case 3: return UACLASS_THIEF;',
    '        default: return UACLASS_FIGHTER;',
    '    }',
    '}',
    '',
    '// The level-up fold: the member\'s cap',
    '// reads the Race Table II column of the',
    '// sub-race and class. No column (-1) or',
    '// a U read (0) leaves the engine cap; a',
    '// pinned limit rides the +2 rule when',
    '// the member is single-classed and the',
    '// class is a multi-class choice for the',
    '// race; the engine cap still binds',
    '// above. The dark-elf sex split rides',
    '// the creation round (the male columns',
    '// here).',
    'inline int uaLevelCap(int baseCap,',
    '                      CharSubRace s,',
    '                      UaClass c,',
    '                      const AbilityScores& a,',
    '                      const ExceptionalStrength& ex,',
    '                      int multiMask) {',
    '    if (s == SUB_NONE || s == SUB_HUMAN)',
    '        return baseCap;',
    '    int limit = subraceLevelLimit(',
    '        s, c, uaColumnKey(c, a, ex), 0);',
    '    if (limit <= 0) return baseCap;',
    '    if (multiMask == 0 && uaBonusEligible(s, c))',
    '        limit += singleClassLevelBonus();',
    '    return limit < baseCap ? limit : baseCap;',
    '}',
    '',
    '}   // namespace rules',
    '',
])

AUD_BLOCK = NL.join([
    '    // ---- R325: the Race Table II fold audit ----',
    '    // The caller seam (rules/subracecap.h):',
    '    // the vital-ability read, the column',
    '    // key build, the +2 eligibility, the',
    '    // derived cap - and the live level-up',
    '    // fold (the gainXp queue and the',
    '    // trainer reading the Race Table II',
    '    // cap through the uaSubrace field).',
    '    // Pinned against the p.8 print.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // U1: the vital-ability read (the',
    '        // p.8 left-hand column rule)',
    '        {',
    '            if (uaColumnAbility(',
    '                UACLASS_FIGHTER)',
    '                != ABILITY_STR) ++bad;',
    '            if (uaColumnAbility(',
    '                UACLASS_RANGER)',
    '                != ABILITY_STR) ++bad;',
    '            if (uaColumnAbility(',
    '                UACLASS_ASSASSIN)',
    '                != ABILITY_STR) ++bad;',
    '            if (uaColumnAbility(',
    '                UACLASS_CLERIC)',
    '                != ABILITY_WIS) ++bad;',
    '            if (uaColumnAbility(',
    '                UACLASS_DRUID)',
    '                != ABILITY_WIS) ++bad;',
    '            if (uaColumnAbility(',
    '                UACLASS_MAGIC_USER)',
    '                != ABILITY_INT) ++bad;',
    '            if (uaColumnAbility(',
    '                UACLASS_ILLUSIONIST)',
    '                != ABILITY_INT) ++bad;',
    '            if (uaColumnAbility(',
    '                UACLASS_THIEF)',
    '                != ABILITY_DEX) ++bad;',
    '        }',
    '        // U2: the column key build (the',
    '        // strength encoder rides the',
    '        // exceptional roll)',
    '        {',
    '            AbilityScores a;',
    '            ExceptionalStrength ex;',
    '            a.str = 17;',
    '            if (uaColumnKey(',
    '                UACLASS_FIGHTER, a, ex)',
    '                != 17000) ++bad;',
    '            a.str = 18;',
    '            if (uaColumnKey(',
    '                UACLASS_FIGHTER, a, ex)',
    '                != 18000) ++bad;',
    '            ex.has = true; ex.pct = 51;',
    '            if (uaColumnKey(',
    '                UACLASS_FIGHTER, a, ex)',
    '                != 18510) ++bad;',
    '            ex.pct = 100;',
    '            if (uaColumnKey(',
    '                UACLASS_FIGHTER, a, ex)',
    '                != 18999) ++bad;',
    '            ex.has = false;',
    '            a.wis = 15;',
    '            if (uaColumnKey(',
    '                UACLASS_CLERIC, a, ex)',
    '                != 15000) ++bad;',
    '            a.int_ = 21;',
    '            if (uaColumnKey(',
    '                UACLASS_MAGIC_USER, a, ex)',
    '                != 21000) ++bad;',
    '            a.dex = 9;',
    '            if (uaColumnKey(',
    '                UACLASS_THIEF, a, ex)',
    '                != 9000) ++bad;',
    '        }',
    '        // U3: the +2 eligibility (the',
    '        // Important paragraph): the',
    '        // dwarven assassin reads the',
    '        // plain limits - no assassin',
    '        // combo exists for the race',
    '        {',
    '            if (!uaBonusEligible(',
    '                SUB_DWARF_HILL,',
    '                UACLASS_FIGHTER)) ++bad;',
    '            if (uaBonusEligible(',
    '                SUB_DWARF_HILL,',
    '                UACLASS_ASSASSIN)) ++bad;',
    '            if (!uaBonusEligible(',
    '                SUB_HALFELF,',
    '                UACLASS_RANGER)) ++bad;',
    '            if (uaBonusEligible(',
    '                SUB_HALFLING_HAIRFOOT,',
    '                UACLASS_DRUID)) ++bad;',
    '            if (!uaBonusEligible(',
    '                SUB_GNOME_DEEP,',
    '                UACLASS_ILLUSIONIST)) ++bad;',
    '            if (uaBonusEligible(',
    '                SUB_HUMAN,',
    '                UACLASS_FIGHTER)) ++bad;',
    '            if (uaBonusEligible(',
    '                SUB_ELF_DARK,',
    '                UACLASS_CLERIC)) ++bad;',
    '        }',
    '        // U4: the derived cap - the p.8',
    '        // examples and the edge reads',
    '        {',
    '            AbilityScores a;',
    '            ExceptionalStrength ex;',
    '            // the hill dwarf 18-strength',
    '            // fighter: 8 multi, 10 single,',
    '            // the engine name-level cap (9)',
    '            // still binds above',
    '            a.str = 18;',
    '            if (uaLevelCap(9, SUB_DWARF_HILL,',
    '                UACLASS_FIGHTER, a, ex, 0)',
    '                != 9) ++bad;',
    '            // the 14-strength hill dwarf',
    '            // fighter: 6 multi, 8 single',
    '            a.str = 14;',
    '            if (uaLevelCap(9, SUB_DWARF_HILL,',
    '                UACLASS_FIGHTER, a, ex, 0)',
    '                != 8) ++bad;',
    '            if (uaLevelCap(9, SUB_DWARF_HILL,',
    '                UACLASS_FIGHTER, a, ex, 9)',
    '                != 6) ++bad;',
    '            // the dwarven assassin: the',
    '            // plain 9, no +2 (the print)',
    '            a.str = 18;',
    '            if (uaLevelCap(10, SUB_DWARF_HILL,',
    '                UACLASS_ASSASSIN, a, ex, 0)',
    '                != 9) ++bad;',
    '            // humans and unset members',
    '            // read the engine cap',
    '            a.str = 14;',
    '            if (uaLevelCap(9, SUB_HUMAN,',
    '                UACLASS_FIGHTER, a, ex, 0)',
    '                != 9) ++bad;',
    '            if (uaLevelCap(9, SUB_NONE,',
    '                UACLASS_FIGHTER, a, ex, 0)',
    '                != 9) ++bad;',
    '            // the hairfoot cleric: WIS 15',
    '            // pins 4, no halfling cleric',
    '            // combo - no +2',
    '            a.wis = 15;',
    '            if (uaLevelCap(9,',
    '                SUB_HALFLING_HAIRFOOT,',
    '                UACLASS_CLERIC, a, ex, 0)',
    '                != 4) ++bad;',
    '            // the half-elf ranger: 8 at',
    '            // STR 18 (+2 = 10), 11 at 18/00',
    '            // (+2 = 13)',
    '            a.wis = 10; a.str = 18;',
    '            if (uaLevelCap(15, SUB_HALFELF,',
    '                UACLASS_RANGER, a, ex, 0)',
    '                != 10) ++bad;',
    '            ex.has = true; ex.pct = 100;',
    '            if (uaLevelCap(15, SUB_HALFELF,',
    '                UACLASS_RANGER, a, ex, 0)',
    '                != 13) ++bad;',
    '            ex.has = false;',
    '            // the drow magic-user (male',
    '            // columns): INT 17 pins 12, +2',
    '            // = 14 - the engine cap (11)',
    '            // binds above; the female',
    '            // cleric split reads U at the',
    '            // R324 layer',
    '            a.str = 10; a.int_ = 17;',
    '            if (uaLevelCap(11, SUB_ELF_DARK,',
    '                UACLASS_MAGIC_USER, a, ex, 0)',
    '                != 11) ++bad;',
    '            if (subraceLevelLimit(',
    '                SUB_ELF_DARK, UACLASS_CLERIC,',
    '                17000, 1) != 0) ++bad;',
    '            // the wood-elf thief reads U -',
    '            // the engine cap stands',
    '            a.int_ = 10; a.dex = 18;',
    '            if (uaLevelCap(10, SUB_ELF_WOOD,',
    '                UACLASS_THIEF, a, ex, 0)',
    '                != 10) ++bad;',
    '            // the surface gnome',
    '            // illusionist: INT 18 pins 7,',
    '            // +2 = 9',
    '            a.dex = 10; a.int_ = 18;',
    '            if (uaLevelCap(11,',
    '                SUB_GNOME_SURFACE,',
    '                UACLASS_ILLUSIONIST, a, ex, 0)',
    '                != 9) ++bad;',
    '            // a class with no column',
    '            // (the elven cavalier) reads',
    '            // the engine cap',
    '            if (uaLevelCap(9, SUB_ELF_WOOD,',
    '                UACLASS_CAVALIER, a, ex, 0)',
    '                != 9) ++bad;',
    '        }',
    '        // U5: the member class mapping',
    '        // (the R230 runtime-base read)',
    '        {',
    '            if (uaClassOfMember(0, 1)',
    '                != UACLASS_RANGER) ++bad;',
    '            if (uaClassOfMember(2, 2)',
    '                != UACLASS_DRUID) ++bad;',
    '            if (uaClassOfMember(3, -1)',
    '                != UACLASS_THIEF) ++bad;',
    '            if (uaClassOfMember(0, -1)',
    '                != UACLASS_FIGHTER) ++bad;',
    '        }',
    '        // U6: the live level-up fold -',
    '        // the gainXp queue and the',
    '        // trainer both stop at the',
    '        // Race Table II cap (a million',
    '        // xp per award, thirty walks -',
    '        // the cap is the only stop)',
    '        {',
    '            // A: the 14-strength hill dwarf',
    '            // fighter, single-classed: 6 +',
    '            // 2 = 8',
    '            {',
    '                AppState st;',
    '                st.party.formed = true;',
    '                Character c;',
    '                c.name = "Bram";',
    '                c.race = 1;',
    '                c.uaSubrace = SUB_DWARF_HILL;',
    '                c.classIndex = 0;',
    '                c.abilities.str = 14;',
    '                c.level = 1;',
    '                c.hp = 30; c.maxHp = 30;',
    '                st.party.members.push_back(c);',
    '                st.rng.seed(7);',
    '                for (int i = 0; i < 30; ++i) {',
    '                    st.party.gainXp(1000000,',
    '                        st.rng, st.log);',
    '                    st.party.trainNext(',
    '                        st.rng, st.log);',
    '                }',
    '                if (st.party.members[0].level',
    '                    != 8) ++bad;',
    '            }',
    '            // B: the same member multi-',
    '            // classed (fighter/thief): the',
    '            // plain 6, no +2',
    '            {',
    '                AppState st;',
    '                st.party.formed = true;',
    '                Character c;',
    '                c.name = "Bram";',
    '                c.race = 1;',
    '                c.uaSubrace = SUB_DWARF_HILL;',
    '                c.classIndex = 0;',
    '                c.multiMask = 9;',
    '                c.abilities.str = 14;',
    '                c.level = 1;',
    '                c.hp = 30; c.maxHp = 30;',
    '                st.party.members.push_back(c);',
    '                st.rng.seed(7);',
    '                for (int i = 0; i < 30; ++i) {',
    '                    st.party.gainXp(1000000,',
    '                        st.rng, st.log);',
    '                    st.party.trainNext(',
    '                        st.rng, st.log);',
    '                }',
    '                if (st.party.members[0].level',
    '                    != 6) ++bad;',
    '            }',
    '            // C: the human fighter - no',
    '            // sub-race, the engine',
    '            // name-level cap stands',
    '            {',
    '                AppState st;',
    '                st.party.formed = true;',
    '                Character c;',
    '                c.name = "Aldo";',
    '                c.race = 0;',
    '                c.classIndex = 0;',
    '                c.abilities.str = 14;',
    '                c.level = 1;',
    '                c.hp = 30; c.maxHp = 30;',
    '                st.party.members.push_back(c);',
    '                st.rng.seed(7);',
    '                for (int i = 0; i < 30; ++i) {',
    '                    st.party.gainXp(1000000,',
    '                        st.rng, st.log);',
    '                    st.party.trainNext(',
    '                        st.rng, st.log);',
    '                }',
    '                if (st.party.members[0].level',
    '                    != 9) ++bad;',
    '            }',
    '            // D: the hairfoot halfling',
    '            // cleric - WIS 15 pins 4',
    '            {',
    '                AppState st;',
    '                st.party.formed = true;',
    '                Character c;',
    '                c.name = "Pip";',
    '                c.race = 5;',
    '                c.uaSubrace =',
    '                    SUB_HALFLING_HAIRFOOT;',
    '                c.classIndex = 2;',
    '                c.abilities.wis = 15;',
    '                c.level = 1;',
    '                c.hp = 30; c.maxHp = 30;',
    '                st.party.members.push_back(c);',
    '                st.rng.seed(7);',
    '                for (int i = 0; i < 30; ++i) {',
    '                    st.party.gainXp(1000000,',
    '                        st.rng, st.log);',
    '                    st.party.trainNext(',
    '                        st.rng, st.log);',
    '                }',
    '                if (st.party.members[0].level',
    '                    != 4) ++bad;',
    '            }',
    '        }',
    '        printf("R325 subrace level cap audit: bad %d\\n", bad);',
    '        if (bad) return 1;',
    '    }',
    '',
])

GP_ANCHOR = NL.join([
'leveling wiring (the class level-up site reading the',
'limit) is the caller round.',
])

GP_CLOSE = NL.join([
'leveling wiring CLOSED R325: the',
'level-up fold (rules/subracecap.h;',
'uaLevelCap at the gainXp queue and',
'the trainer, the uaSubrace field',
'with its save line; the R325 audit,',
'census 252).',
])

SEED_ENTRY = NL.join([
    '',
    '- R324 landed 2026-10-11: commit',
    '  a7a6a5c, census 251, the UA',
    '  Character Race Table II',
    '  (rules/subracelevels.h): the six',
    '  sub-tables (II.A dwarves, II.B',
    '  gnomes, II.C elves both printed',
    '  blocks, II.D half-elves, II.E',
    '  halflings, II.F half-orcs), the 47',
    '  columns keyed by the vital ability',
    '  (score*1000; the exceptional',
    '  strength ladder 18/01-18/00 as',
    '  18010-18999 with 18/00 at 18999),',
    '  the dark-elf sex split, the U',
    '  reads, the footnoted ability gates',
    '  with the OR footnote, the',
    '  escalation riders, the floor rule,',
    '  the +2 single-class rule. GREEN on',
    '  the second paste (one fix round,',
    '  r324b, folded by amend).',
    '  Lessons: (1) the oracle must read',
    '  back out of the GENERATED header',
    '  text, not the intent - the',
    '  build-time simulation carried the',
    '  wild elf in the elf gates block',
    '  while the generated C++ omitted',
    '  SUB_ELF_WILD; the double-entry',
    '  check verified audit-vs-model,',
    '  never model-vs-header, so the',
    '  preflight read bad 2 and the',
    '  if-bad-return bail-out cascaded',
    '  the census (every audit after the',
    '  block read CENSUS FAIL); the',
    '  replay discipline (port the landed',
    '  C++ literally into Python, replay',
    '  the audit mechanically) found the',
    '  2 fails exactly; (2) preflight is',
    '  a pre-commit gate - run it before',
    '  the git add; a post-amend run',
    '  reads hygiene RED on a clean tree',
    '  (untracked splice files with no',
    '  modified tracked file is the',
    '  never-ran shape, and the amend',
    '  leaves exactly that); (3) the',
    '  paste md5 drifts only the trailing',
    '  newline (nano); the splice asserts',
    '  are the tripwire.',
])

PARTY_INC = NL.join([
'#include "../rules/subracecap.h"  // R325: the Race Table II fold',
])

PARTY_FIELD = NL.join([
'    // R325: the UA sub-race (rules::CharSubRace; 0 = none/human, the',
'    // v1-save default). The Race Table II level-limit fold reads it.',
'    // Optional "uasub" line in the save.',
'    int  uaSubrace = 0;',
])

PARTY_FOLD = NL.join([
'            // R325: the UA Race Table II',
'            // fold - a sub-raced member cap',
'            // reads the level-limit column (the',
'            // vital ability keyed per the p.8',
'            // print; the +2 single-class rule;',
'            // the engine cap still binds above).',
'            // The dark-elf sex split rides the',
'            // creation round (the male columns',
'            // here).',
'            cap = rules::uaLevelCap(cap,',
'                (rules::CharSubRace)c.uaSubrace,',
'                rules::uaClassOfMember(',
'                    c.classIndex, c.subclass),',
'                c.abilities, c.exStr,',
'                c.multiMask);',
])

SC_SAVE = NL.join([
'            // R325: the UA sub-race (only when set -',
'            // v1 saves carry no line and load as none)',
'            if (c.uaSubrace != 0)',
'                fprintf(f, "uasub %d\\n",',
'                        c.uaSubrace);',
])

SC_LOAD = NL.join([
'                    c.race = rc;',
'                } else if (strcmp(tag, "uasub") == 0) {',
'                    int us = 0;',
'                    if (fscanf(f, "%d", &us) != 1 ||',
'                        us < 0 ||',
'                        us >= rules::SUBRACE_COUNT) {',
'                        fclose(f);',
'                        log.add("adnd1.sav is corrupt (uasub).");',
'                        return false;',
'                    }',
'                    c.uaSubrace = us;',
'                } else if (strcmp(tag, "subclass") == 0) {',
])


# ---- (a) the seed: the R324 entry ----
SEED = 'doc/vibe/adnd1_knowledge_seed_v2.md'
s = rd(SEED)
clean(SEED_ENTRY, 72)
if '- R324 landed 2026-10-11: commit' in s:
    already.append('the seed: the R324 entry')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'seed anchor'
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SEED, s)
    applied.append('the seed: the R324 entry')
s = rd(SEED)
assert s.count('- R324 landed 2026-10-11: commit') == 1, 'a once'
assert s.count('- R323 landed 2026-10-11: commit') == 1, 'a r323 kept'
assert s.count('- R322 landed 2026-10-11: commit') == 1, 'a r322 kept'
assert len(applied) + len(already) == 1, 'patch a count wrong'

# ---- (b) rules/subracecap.h: the seam ----
SC = 'rules/subracecap.h'
cleanNB(SR_FILE, 78)
if os.path.exists(os.path.join(ROOT, SC)):
    already.append('subracecap.h: the seam')
else:
    wr(SC, SR_FILE)
    applied.append('subracecap.h: the seam')
s = rd(SC)
assert s.count('inline int uaColumnAbility') == 1, 'b ability fn'
assert s.count('inline int uaColumnKey') == 1, 'b key fn'
assert s.count('inline int uaClassBit') == 1, 'b bit fn'
assert s.count('inline bool uaBonusEligible') == 1, 'b bonus fn'
assert s.count('inline UaClass uaClassOfMember') == 1, 'b member fn'
assert s.count('inline int uaLevelCap') == 1, 'b cap fn'
assert s.count('subracelevels.h') == 1, 'b columns include'
assert s.count('namespace rules {') == 1, 'b namespace'
assert 'SUB_COUNT' not in s, 'b no SUB_COUNT (the R323 lesson)'
assert len(applied) + len(already) == 2, 'patch b count wrong'

# ---- (c) game/party.h: the field and the folds ----
PH = 'game/party.h'
s = rd(PH)
cleanNB(PARTY_INC, 78)
cleanNB(PARTY_FIELD, 78)
cleanNB(PARTY_FOLD, 78)
if 'uaLevelCap' in s:
    already.append('party.h: the field and the folds')
else:
    MC_INC = ('#include "../rules/multiclass.h"'
              '  // R233: the multi-class engine')
    assert s.count(MC_INC) == 1, 'c include anchor'
    s = s.replace(MC_INC, MC_INC + NL + PARTY_INC)
    FIELD_ANCH = ('    // R154: racial stock (rules::CharRace;'
                  ' 0 = human, the' + NL
                  + '    // v1-save default). Optional "race" line'
                  ' in the save.' + NL
                  + '    int  race = 0;')
    assert s.count(FIELD_ANCH) == 1, 'c field anchor'
    s = s.replace(FIELD_ANCH, FIELD_ANCH + NL + PARTY_FIELD)
    GAINX_ANCH = ('            if (c.level < cap &&' + NL
                  + '                c.xp >= need &&')
    assert s.count(GAINX_ANCH) == 1, 'c gainXp anchor'
    s = s.replace(GAINX_ANCH, PARTY_FOLD + NL + GAINX_ANCH)
    STALE_ANCH = ('            if (c.hp <= 0 || c.level >= cap ||'
                  + NL + '                c.xp < need)')
    assert s.count(STALE_ANCH) == 1, 'c trainer anchor'
    s = s.replace(STALE_ANCH, PARTY_FOLD + NL + STALE_ANCH)
    wr(PH, s)
    applied.append('party.h: the field and the folds')
s = rd(PH)
assert s.count('uaSubrace') == 3, 'c field + 2 folds'
assert s.count('uaLevelCap') == 2, 'c the folds'
assert s.count('subracecap.h') == 1, 'c the include'
assert s.count('uaClassOfMember') == 2, 'c the mapping'
assert len(applied) + len(already) == 3, 'patch c count wrong'

# ---- (d) game/state_core.cpp: the save line and the load tag ----
CORE = 'game/state_core.cpp'
s = rd(CORE)
cleanNB(SC_SAVE, 78)
cleanNB(SC_LOAD, 78)
if 'uasub' in s:
    already.append('state_core.cpp: the save and the load')
else:
    SAVE_ANCH = ('            // R154: racial stock'
                 ' (nonzero only - v1 saves' + NL
                 + '            // carry no line and load as human)'
                 + NL
                 + '            if (c.race != 0)' + NL
                 + '                fprintf(f, "race %d' + BS
                 + 'n", c.race);')
    assert s.count(SAVE_ANCH) == 1, 'd save anchor'
    s = s.replace(SAVE_ANCH, SAVE_ANCH + NL + SC_SAVE)
    LOAD_ANCH = ('                    c.race = rc;' + NL
                 + '                } else if (strcmp(tag,'
                 ' "subclass") == 0) {')
    assert s.count(LOAD_ANCH) == 1, 'd load anchor'
    s = s.replace(LOAD_ANCH, SC_LOAD)
    wr(CORE, s)
    applied.append('state_core.cpp: the save and the load')
s = rd(CORE)
assert s.count('uasub') == 3, 'd save + load + log'
assert s.count('uaSubrace') == 3, 'd the field reads (save 2 + load 1)'
assert s.count('SUBRACE_COUNT') == 1, 'd the range gate'
assert len(applied) + len(already) == 4, 'patch d count wrong'

# ---- (e) the gap report: the wiring close ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
clean(GP_ANCHOR, 57)
clean(GP_CLOSE, 57)
assert Q not in GP_CLOSE, 'apostrophe in gp close'
if GP_CLOSE in s:
    already.append('ua_gap_report.md: the wiring close')
else:
    assert s.count(GP_ANCHOR) == 1, 'gp anchor not unique'
    s = s.replace(GP_ANCHOR, GP_CLOSE)
    wr(GP, s)
    applied.append('ua_gap_report.md: the wiring close')
s = rd(GP)
assert s.count('CLOSED R325') == 1, 'e one close'
assert s.count('CLOSED R324') == 1, 'e r324 kept'
assert s.count('CLOSED R323') == 4, 'e r323 kept'
assert s.count('CLOSED R322') == 1, 'e r322 kept'
assert len(applied) + len(already) == 5, 'patch e count wrong'

# ---- (f) regtest.cpp: the include and the audit ----
RG = 'regtest.cpp'
s = rd(RG)
INC_OLD = ('#include "rules/subracelevels.h"'
           '  // R324: UA Race Table II')
INC_NEW = (INC_OLD + NL
           + '#include "rules/subracecap.h"'
           '  // R325: UA Race Table II fold')
cleanNB(INC_NEW, 76)
AUD_ANCH = ('    // ---- R227: the wis mental'
            ' save wiring audit ----')
if 'R325 subrace level cap audit' not in s:
    assert s.count(INC_OLD) == 1, 'f include anchor'
    s = s.replace(INC_OLD, INC_NEW)
    assert s.count(AUD_ANCH) == 1, 'f audit anchor'
    cleanNB(AUD_BLOCK, 76)
    s = s.replace(AUD_ANCH, AUD_BLOCK + NL + AUD_ANCH)
    wr(RG, s)
    applied.append('regtest.cpp: the include and the audit')
else:
    already.append('regtest.cpp: the include and the audit')
s = rd(RG)
assert s.count('audit: bad') == 252, 'f census count'
assert s.count('R325 subrace level cap audit') == 1, 'f print once'
assert s.count('R324 subrace level limits audit') == 1, 'f r324 kept'
assert s.count('R323 subrace layer seam audit') == 1, 'f r323 kept'
assert s.count('rules/subracecap.h') == 2, 'f include refs'
assert len(applied) + len(already) == 6, 'patch f count wrong'

if len(applied) + len(already) != 6:
    print('R325 splice: FAIL - expected 6 patches, '
          'counted ' + str(len(applied) + len(already))
          + ' (a truncated paste?)')
    sys.exit(1)
print('R325 splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R325 note: the Race Table II caller')
print('round - the level-up fold lands:')
print('the uaSubrace field (with its save')
print('line), the cap read at the gainXp')
print('queue and the trainer, the +2')
print('single-class rule against the R185')
print('combo layer; the creation round')
print('(the subrace picker, the dark-elf')
print('sex split) stays open on the gap')
print('report; the battery census 251 -> 252')
print('commit: R325: the Race Table II')
print('level-up fold (census 252)')

