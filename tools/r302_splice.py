#!/usr/bin/env python3
# tools/r302_splice.py - R302: the thief
# silence wired (the R301 standing
# successor; the R227 wiring-arc
# precedent).
#
# The R298 move silently column rode the
# future thief roll round (the surprise
# link), and the engine surprise roll
# hardcoded both DEX adjustments to zero -
# the R178c DEX reaction ladder never
# reached it and no thief roll ran. This
# round wires both:
#
#   (a) rules/thieffunc.h - the
#       surprise-site helpers:
#       thfSilenceSurpriseAdj (one roll
#       step of the DMG p.62 2d6 ladder -
#       JUDGMENT, the SILENT MOVEMENT print
#       carries no ladder modifier) and
#       thfNoteSilenceEachMove (the printed
#       note; the site rolls it once per
#       encounter).
#   (b) ai/actor.h - the Actor gains
#       pcRace (the PC CharRace for the
#       percentile; Actor.race stays the
#       dm::NpcRace int) and Encounter
#       gains rollSurpriseWired.
#   (c) ai/actor.cpp - the roll: the party
#       side reads the best living member
#       DEX reaction adjustment (the DMG
#       most-favorable-member reading) and
#       the first living thief rolls ONE
#       printed move silently percentile
#       (success -> the monster side takes
#       the silence step); stepRound calls
#       it (the hardcoded zeros retired).
#   (d) game/party.h - toActor copies
#       pcRace.
#   (e) regtest.cpp - the R302 audit pair
#       (the battery census 221 -> 223):
#       the R302a seam audit walks the
#       silence step and the move silently
#       percentile boundaries (evaluable -
#       verified by audit_eval) and the
#       R302 engine audit pins every
#       scenario on seeded sequences (the
#       replica walked the draws first -
#       no compiler in the splice sandbox).
#   (f) tools/phb_gap_report.md - the
#       wiring-arc box (the R298 box head
#       amended; the ledger holds ZERO
#       open items).
#
# Idempotent: safe to run twice; a silent run
# means the paste was truncated - this tail
# ALWAYS prints. An assert follows EVERY patch
# (the R142 lesson). ZERO literal backslash
# bytes in this file (the audit printf newline
# builds via BS) and no CONTENT string embeds
# an apostrophe, non-ASCII or (for the gap
# report) a line past 57 columns.
# Commit: "R302: the thief silence wired
# (census 223)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
BS = chr(92)
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding='ascii') as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), 'w', encoding='ascii') as f:
        f.write(s)

def clean(s, limit):
    assert chr(39) not in s, 'apostrophe in content'
    assert BS not in s, 'backslash in content'
    for ln in s.split(NL):
        assert all(ord(c) < 128 for c in ln), 'non-ascii line'
        assert len(ln) <= limit, 'line too long: ' + ln

# ---- (a) rules/thieffunc.h: the site helpers ----
TF_TOP_OLD = NL.join([
    '// trap site (the thfAttemptSucceeds seam);',
    '// the other functions wait for engine sites',
    '// that do not exist yet.',
])
TF_TOP_NEW = NL.join([
    '// trap site (the thfAttemptSucceeds seam);',
    '// R302: the move silently roll now runs at',
    '// the surprise site; the other functions',
    '// wait for engine sites that do not exist',
    '// yet.',
])
TF_SEAM_OLD = NL.join([
    '    // succeeds). R301: the trap site rolls',
    '    // this seam (the find and the remove',
    '    // draws); the other functions stay data',
])
TF_SEAM_NEW = NL.join([
    '    // succeeds). R301: the trap site rolls',
    '    // this seam (the find and the remove',
    '    // draws); R302: the surprise site rolls',
    '    // the move silently draw (one per',
    '    // encounter); the rest stay data',
])
TF_TAIL_OLD = NL.join([
    '    return thfPercentileSucceeds(',
    '        rollTenths,',
    '        thfChanceTenths(fn, level, race, dex));',
    '}',
    '',
    '}  // namespace rules',
])
TF_TAIL_NEW = NL.join([
    '    return thfPercentileSucceeds(',
    '        rollTenths,',
    '        thfChanceTenths(fn, level, race, dex));',
    '}',
    '',
    '// R302: the surprise-site silence modifier.',
    '// The SILENT MOVEMENT print: success means',
    '// silent movement and an improved chance to',
    '// surprise an opponent. The PHB surprise',
    '// prose is d6-form (the silent party',
    '// doubles its surprise faces); the engine',
    '// surprise is the DMG p.62 2d6 ladder, so',
    '// the improvement pins as one roll step on',
    '// the surprised side (a band of the ladder)',
    '// - JUDGMENT: the print carries no',
    '// 2d6-ladder modifier.',
    'inline int thfSilenceSurpriseAdj(bool silent) {',
    '    return silent ? -2 : 0;',
    '}',
    '',
    '// R302: the printed note - moving silently',
    '// can be attempted each time the thief',
    '// moves. The encounter site rolls it once',
    '// per encounter (the movement granularity',
    '// simplification, recorded in the phb gap',
    '// report).',
    'inline int thfNoteSilenceEachMove() {',
    '    return 1;',
    '}',
    '',
    '}  // namespace rules',
])
for t in (TF_TOP_OLD, TF_TOP_NEW, TF_SEAM_OLD, TF_SEAM_NEW,
          TF_TAIL_OLD, TF_TAIL_NEW):
    clean(t, 78)

p = 'rules/thieffunc.h'
s = rd(p)
if 'thfSilenceSurpriseAdj' in s:
    already.append('thieffunc.h: the site helpers')
else:
    assert s.count(TF_TOP_OLD) == 1, 'tf top anchor not unique'
    assert s.count(TF_SEAM_OLD) == 1, 'tf seam anchor not unique'
    assert s.count(TF_TAIL_OLD) == 1, 'tf tail anchor not unique'
    assert 'thfNoteSilenceEachMove' not in s, 'tf marker collision'
    s = s.replace(TF_TOP_OLD, TF_TOP_NEW)
    s = s.replace(TF_SEAM_OLD, TF_SEAM_NEW)
    s = s.replace(TF_TAIL_OLD, TF_TAIL_NEW)
    wr(p, s)
    applied.append('thieffunc.h: the site helpers')
s = rd(p)
assert 'thfSilenceSurpriseAdj' in s, 'patch a failed'
assert s.count('inline int thfSilenceSurpriseAdj') == 1, 'patch a helper'
assert s.count('inline int thfNoteSilenceEachMove') == 1, 'patch a note'
assert 'the other functions stay data' not in s, 'patch a stale seam note'
assert 'wait for engine sites' in s, 'patch a ate the top note'
assert s.count('}  // namespace rules') == 1, 'patch a namespace close'
assert s.count('inline bool thf') == 2, 'patch a ate the R301 pair'
assert 'thfTakeTenths' in s and 'thfNoteLocksOneTry' in s, 'patch a ate a pin'
assert len(applied) + len(already) == 1, 'patch a count wrong'

# ---- (b) ai/actor.h: pcRace + the declaration ----
AH_ACTOR_OLD = NL.join([
    '    bool nonIntelligent = false;',
])
AH_ACTOR_NEW = NL.join([
    '    bool nonIntelligent = false;',
    '    // R302: the PC CharRace (rules/races.h)',
    '    // for the thief percentile columns - the',
    '    // race field above stays the dm::NpcRace',
    '    // int (the R147 saves convention)',
    '    int  pcRace = 0;',
])
AH_ENC_OLD = NL.join([
    '    // single-round step (interactive combat drives this)',
    '    int stepRound();',
])
AH_ENC_NEW = NL.join([
    '    // single-round step (interactive combat drives this)',
    '    int stepRound();',
    '',
    '    // R302: the wired surprise roll - the',
    '    // party side reads the best living member',
    '    // DEX reaction adjustment (the DMG p.62',
    '    // most-favorable-member reading; the DEX',
    '    // reaction surprise note is individual-',
    '    // only and the engine keeps no per-member',
    '    // surprise clocks), and the first living',
    '    // thief rolls one printed move silently',
    '    // percentile (success -> the monster side',
    '    // takes the silence roll step,',
    '    // rules::thfSilenceSurpriseAdj). One roll',
    '    // per encounter - the movement',
    '    // granularity simplification.',
    '    void rollSurpriseWired(int& segsA, int& segsB);',
])
for t in (AH_ACTOR_OLD, AH_ACTOR_NEW, AH_ENC_OLD, AH_ENC_NEW):
    clean(t, 78)

p = 'ai/actor.h'
s = rd(p)
if 'rollSurpriseWired' in s:
    already.append('actor.h: pcRace + the declaration')
else:
    assert s.count(AH_ACTOR_OLD) == 1, 'ah actor anchor not unique'
    assert s.count(AH_ENC_OLD) == 1, 'ah enc anchor not unique'
    assert 'int  pcRace = 0;' not in s, 'ah marker collision'
    s = s.replace(AH_ACTOR_OLD, AH_ACTOR_NEW)
    s = s.replace(AH_ENC_OLD, AH_ENC_NEW)
    wr(p, s)
    applied.append('actor.h: pcRace + the declaration')
s = rd(p)
assert s.count('int  pcRace = 0;') == 1, 'patch b pcRace field'
assert s.count('rollSurpriseWired') == 1, 'patch b declaration'
assert s.count('int stepRound();') == 1, 'patch b ate stepRound'
assert 'R147: race (dm::NpcRace int' in s, 'patch b ate the R147 note'
assert 'class Encounter' in s, 'patch b ate the class'
assert len(applied) + len(already) == 2, 'patch b count wrong'

# ---- (c) ai/actor.cpp: the roll + the wire ----
AC_INC_OLD = NL.join([
    '#include "../rules/weaponprof.h"  // R297: the proficiency table',
])
AC_INC_NEW = NL.join([
    '#include "../rules/weaponprof.h"  // R297: the proficiency table',
    '#include "../rules/thieffunc.h"  // R302: the silence percentile',
])
AC_DEF_OLD = NL.join([
    'int Encounter::stepRound() {',
])
AC_DEF_NEW = NL.join([
    '// R302: the wired surprise roll (the header',
    '// comment pins the convention). The draw',
    '// order: the percentile first (a living',
    '// thief), then the party 2d6 pair, then the',
    '// monster pair - the R302 engine audit pins',
    '// this order seed by seed.',
    'void Encounter::rollSurpriseWired(int& segsA, int& segsB) {',
    '    int pAdj = 0;',
    '    bool seen = false;',
    '    for (const Actor& a : m_party) {',
    '        if (!a.alive()) continue;',
    '        int adj = rules::dexReactionAdj(a.dex);',
    '        if (!seen || adj > pAdj) pAdj = adj;',
    '        seen = true;',
    '    }',
    '    int mAdj = 0;',
    '    for (const Actor& a : m_party) {',
    '        if (!a.alive()) continue;',
    '        if (a.classIndex != 3) continue;   // CLASS_THIEF',
    '        // R302: one printed move silently roll',
    '        // per encounter - the FIRST living',
    '        // thief carries it (a second thief',
    '        // adds no second roll)',
    '        int roll = (int)m_rng.below(1000);',
    '        if (rules::thfAttemptSucceeds(',
    '                roll, rules::THF_MOVE_SILENTLY,',
    '                a.level, a.pcRace, (int)a.dex))',
    '            mAdj = rules::thfSilenceSurpriseAdj(true);',
    '        break;',
    '    }',
    '    rules::rollSurprise(m_dice, pAdj, mAdj,',
    '                       segsA, segsB);',
    '}',
    '',
    'int Encounter::stepRound() {',
])
AC_CALL_OLD = NL.join([
    '        rules::rollSurprise(m_dice, 0, 0, pSurp, mSurp);',
])
AC_CALL_NEW = NL.join([
    '        rollSurpriseWired(pSurp, mSurp);   // R302',
])
for t in (AC_INC_OLD, AC_INC_NEW, AC_DEF_OLD, AC_DEF_NEW,
          AC_CALL_OLD, AC_CALL_NEW):
    clean(t, 78)

p = 'ai/actor.cpp'
s = rd(p)
if 'rollSurpriseWired' in s:
    already.append('actor.cpp: the roll + the wire')
else:
    assert s.count(AC_INC_OLD) == 1, 'ac include anchor not unique'
    assert s.count(AC_DEF_OLD) == 1, 'ac def anchor not unique'
    assert s.count(AC_CALL_OLD) == 1, 'ac call anchor not unique'
    assert 'rules::rollSurprise(m_dice, 0, 0' in s, 'ac anchor drift'
    s = s.replace(AC_INC_OLD, AC_INC_NEW)
    s = s.replace(AC_DEF_OLD, AC_DEF_NEW)
    s = s.replace(AC_CALL_OLD, AC_CALL_NEW)
    wr(p, s)
    applied.append('actor.cpp: the roll + the wire')
s = rd(p)
assert s.count('rollSurpriseWired') == 2, 'patch c def + call'
assert 'rules::rollSurprise(m_dice, 0, 0' not in s, 'patch c left the zeros'
assert s.count('rules/thieffunc.h') == 1, 'patch c include'
assert s.count('int Encounter::stepRound() {') == 1, 'patch c ate stepRound'
assert s.count('rollSurpriseWired(pSurp, mSurp);') == 1, 'patch c call'
assert 'The party is surprised' in s, 'patch c ate the log line'
assert 'm_monsSurprised = mSurp;' in s, 'patch c ate the backstab gate'
assert len(applied) + len(already) == 3, 'patch c count wrong'

# ---- (d) game/party.h: the toActor copy ----
PT_OLD = NL.join([
    '        a.bard        = bard;   // R235: the druid studies',
])
PT_NEW = NL.join([
    '        a.bard        = bard;   // R235: the druid studies',
    '        a.pcRace      = race;   // R302: the thief percentile',
])
for t in (PT_OLD, PT_NEW):
    clean(t, 78)

p = 'game/party.h'
s = rd(p)
if 'a.pcRace      = race;' in s:
    already.append('party.h: the toActor copy')
else:
    assert s.count(PT_OLD) == 1, 'pt anchor not unique'
    assert 'a.pcRace' not in s, 'pt marker collision'
    s = s.replace(PT_OLD, PT_NEW)
    wr(p, s)
    applied.append('party.h: the toActor copy')
s = rd(p)
assert s.count('a.pcRace      = race;') == 1, 'patch d copy'
assert 'a.bard        = bard;' in s, 'patch d ate the bard copy'
assert 'a.subclass    = subclass;' in s, 'patch d ate the subclass copy'
assert 'ai::Actor toActor() const' in s, 'patch d ate the method'
assert len(applied) + len(already) == 4, 'patch d count wrong'

# ---- (e) regtest.cpp: the R302 audit pair ----
RT_OLD = NL.join([
    '        printf("R301 thief trap rolls engine audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    '    // ---- R227: the wis mental save wiring audit ----',
])
RT_R302A = NL.join([
    '    // ---- R302: the thief silence seam audit ----',
    '    // The surprise-site helpers: the silence',
    '    // roll step (one band of the DMG p.62 2d6',
    '    // ladder - JUDGMENT, the SILENT MOVEMENT',
    '    // print carries no ladder modifier) and',
    '    // the printed each-move note (the site',
    '    // rolls it once per encounter). The move',
    '    // silently percentile boundaries walk the',
    '    // R301a convention (plain int race codes:',
    '    // 0 human, 5 halfling, 6 half-orc).',
    '    {',
    '        int bad = 0;',
    '        // the silence step: -2 silent, 0 plain',
    '        if (rules::thfSilenceSurpriseAdj(true) != -2 ||',
    '            rules::thfSilenceSurpriseAdj(false) != 0) ++bad;',
    '        // the printed note: attempted each',
    '        // time the thief moves',
    '        if (rules::thfNoteSilenceEachMove() != 1) ++bad;',
    '        // move silently level 1 human dex 9',
    '        // prints -5 percent (the 150 base less',
    '        // the dex 9 -20 column - no roll of',
    '        // the band succeeds)',
    '        if (rules::thfAttemptSucceeds(0,',
    '                rules::THF_MOVE_SILENTLY, 1, 0, 9) ||',
    '            rules::thfAttemptSucceeds(999,',
    '                rules::THF_MOVE_SILENTLY, 1, 0, 9)) ++bad;',
    '        // move silently level 7 human dex 13',
    '        // prints 55 percent (550 tenths)',
    '        if (!rules::thfAttemptSucceeds(549,',
    '                rules::THF_MOVE_SILENTLY, 7, 0, 13) ||',
    '            rules::thfAttemptSucceeds(550,',
    '                rules::THF_MOVE_SILENTLY, 7, 0, 13)) ++bad;',
    '        // move silently level 10 halfling',
    '        // dex 13 prints 88 percent (880)',
    '        if (!rules::thfAttemptSucceeds(879,',
    '                rules::THF_MOVE_SILENTLY, 10, 5, 13) ||',
    '            rules::thfAttemptSucceeds(880,',
    '                rules::THF_MOVE_SILENTLY, 10, 5, 13)) ++bad;',
    '        // move silently level 17 half-orc',
    '        // dex 18 prints 109 percent (1090 -',
    '        // every draw of the band succeeds)',
    '        if (!rules::thfAttemptSucceeds(999,',
    '                rules::THF_MOVE_SILENTLY, 17, 6, 18)) ++bad;',
    '        // move silently level 1 human dex 18',
    '        // prints 25 percent (250 tenths)',
    '        if (!rules::thfAttemptSucceeds(249,',
    '                rules::THF_MOVE_SILENTLY, 1, 0, 18) ||',
    '            rules::thfAttemptSucceeds(250,',
    '                rules::THF_MOVE_SILENTLY, 1, 0, 18)) ++bad;',
    '        printf("R302a thief silence seam audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
])
RT_R302 = NL.join([
    '    // ---- R302: the thief silence engine audit ----',
    '    // The wired surprise roll on pinned seeds: the',
    '    // party side reads the best living DEX',
    '    // reaction adjustment, the first living thief',
    '    // rolls ONE move silently percentile, the',
    '    // monster side takes the -2 step on success.',
    '    // Expected values from the xorshift64* replica',
    '    // (the R301 convention - the splice sandbox',
    '    // compiles nothing; the replica walked every',
    '    // draw first). Each scenario asserts BOTH',
    '    // segments, so a shifted draw count, a wrong',
    '    // adjustment source or a missed silence step',
    '    // all fire.',
    '    {',
    '        int bad = 0;',
    '        // the scenario driver: one stock monster,',
    '        // the wired call, both segments checked',
    '        auto silScenario = [](',
    '                const std::vector<ai::Actor>& pt,',
    '                uint64_t seed, int wantA,',
    '                int wantB, int* badp) {',
    '            std::vector<ai::Actor> mons;',
    '            ai::Actor m;',
    '            m.team = 1;',
    '            m.hitDice = 1;',
    '            m.hp = 6;',
    '            m.maxHp = 6;',
    '            mons.push_back(m);',
    '            ai::Encounter enc(pt, mons, seed);',
    '            int sa = -1, sb = -1;',
    '            enc.rollSurpriseWired(sa, sb);',
    '            if (sa != wantA || sb != wantB) ++*badp;',
    '        };',
    '        auto silMk = [](int cls, int level,',
    '                       int race, int dex, int hp) {',
    '            ai::Actor a;',
    '            a.isCharacter = true;',
    '            a.classIndex = cls;',
    '            a.level = level;',
    '            a.pcRace = race;',
    '            a.dex = (uint8_t)dex;',
    '            a.hp = hp;',
    '            a.maxHp = hp > 0 ? hp : 30;',
    '            return a;',
    '        };',
    '        // seed 3: no thief, dex 10 - the plain pair',
    '        // (party 6, monsters 6 -> 1 segment each)',
    '        {',
    '            std::vector<ai::Actor> pt;',
    '            pt.push_back(silMk(0, 1, 0, 10, 30));',
    '            silScenario(pt, 3, 1, 1, &bad);',
    '        }',
    '        // seed 2: dex 18 - the +3 lands (the party',
    '        // roll 4 reads 7: 1 segment, not the plain 2)',
    '        {',
    '            std::vector<ai::Actor> pt;',
    '            pt.push_back(silMk(0, 1, 0, 18, 30));',
    '            silScenario(pt, 2, 1, 0, &bad);',
    '        }',
    '        // seed 1: dex 3 - the -3 lands (the party',
    '        // roll 8 reads 5: 2 segments, not 0)',
    '        {',
    '            std::vector<ai::Actor> pt;',
    '            pt.push_back(silMk(0, 1, 0, 3, 30));',
    '            silScenario(pt, 1, 2, 1, &bad);',
    '        }',
    '        // seed 66: a level 1 human dex 9 thief -',
    '        // the printed chance reads -50, so the',
    '        // percentile (42) fails and the silence',
    '        // step never lands (monsters 7 -> 1)',
    '        {',
    '            std::vector<ai::Actor> pt;',
    '            pt.push_back(silMk(3, 1, 0, 9, 30));',
    '            silScenario(pt, 66, 0, 1, &bad);',
    '        }',
    '        // seed 4: a level 10 human dex 13 thief -',
    '        // the percentile 761 reads under 780:',
    '        // silenced; the monster pair rolls 8 and',
    '        // the -2 step lands 1 segment (0 plain)',
    '        {',
    '            std::vector<ai::Actor> pt;',
    '            pt.push_back(silMk(3, 10, 0, 13, 30));',
    '            silScenario(pt, 4, 1, 1, &bad);',
    '        }',
    '        // seed 5: two thieves - ONE percentile',
    '        // (492, under 780), not two: the pair',
    '        // lands (party 5 -> 2, monsters 9 with',
    '        // the step -> 1)',
    '        {',
    '            std::vector<ai::Actor> pt;',
    '            pt.push_back(silMk(3, 10, 0, 13, 30));',
    '            pt.push_back(silMk(3, 10, 0, 13, 30));',
    '            silScenario(pt, 5, 2, 1, &bad);',
    '        }',
    '        // seed 2: the dead thief (hp 0, dex 18)',
    '        // draws nothing and feeds no adjustment;',
    '        // the living fighter dex 10 reads pAdj 0',
    '        // (party 4 -> 2 segments, monsters 10 -> 0)',
    '        {',
    '            std::vector<ai::Actor> pt;',
    '            pt.push_back(silMk(3, 10, 0, 18, 0));',
    '            pt.push_back(silMk(0, 1, 0, 10, 30));',
    '            silScenario(pt, 2, 2, 0, &bad);',
    '        }',
    '        // seed 1: dex 3 + dex 18 + a level 1',
    '        // halfling dex 13 thief (chance 250, the',
    '        // percentile 165 succeeds) - pAdj reads',
    '        // the BEST living member (+3: the party',
    '        // roll 8 reads 11 -> 0) and the monster',
    '        // side takes the step (7 reads 5 -> 2)',
    '        {',
    '            std::vector<ai::Actor> pt;',
    '            pt.push_back(silMk(0, 1, 0, 3, 30));',
    '            pt.push_back(silMk(0, 1, 0, 18, 30));',
    '            pt.push_back(silMk(3, 1, 5, 13, 30));',
    '            silScenario(pt, 1, 0, 2, &bad);',
    '        }',
    '        printf("R302 thief silence engine audit: bad %d' + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
])
RT_NEW = NL.join([
    '        printf("R301 thief trap rolls engine audit: bad %d'
    + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
    RT_R302A,
    RT_R302,
    '    // ---- R227: the wis mental save wiring audit ----',
])
# the audit blocks carry the printf newline (BS) - the
# R300 check: BS lives ONLY on the printf lines, one
# per line, and nothing else carries a backslash
for t in (RT_OLD, RT_R302A, RT_R302):
    for ln in t.split(NL):
        assert all(ord(c) < 128 for c in ln), 'non-ascii in audit'
        assert len(ln) <= 76, 'audit line too long: ' + ln
        assert chr(39) not in ln, 'apostrophe in audit'
        if 'printf("' in ln:
            assert ln.count(BS) == 1, 'printf BS count wrong'
        else:
            assert BS not in ln, 'stray backslash in audit'

p = 'regtest.cpp'
s = rd(p)
if 'R302 thief silence engine audit' in s:
    already.append('regtest.cpp: the R302 audit pair')
else:
    assert s.count('audit: bad') == 221, 'rt census not 221'
    assert s.count(RT_OLD) == 1, 'rt anchor not unique'
    assert 'R302a thief silence seam audit' not in s, 'rt marker collision'
    s = s.replace(RT_OLD, RT_NEW)
    wr(p, s)
    applied.append('regtest.cpp: the R302 audit pair')
s = rd(p)
assert s.count('audit: bad') == 223, 'patch e census wrong'
assert s.count('R302a thief silence seam audit') == 1, 'patch e R302a marker'
assert s.count('R302 thief silence engine audit') == 1, 'patch e R302 marker'
assert s.count('R302: the thief silence seam audit') == 1, 'patch e R302a head'
assert s.count('R302: the thief silence engine audit') == 1, 'patch e R302 head'
assert s.count('R227: the wis mental save wiring audit') == 1, 'patch e ate R227'
assert s.count('R301 thief trap rolls engine audit') == 1, 'patch e ate R301'
assert 'R300 equipment costs engine audit' in s, 'patch e ate R300'
assert 'R299a party kit recordings seam audit' in s, 'patch e ate R299a'
assert s.count('THF_MOVE_SILENTLY') == 9, 'patch e probe count'
assert s.count('silScenario(pt,') == 8, 'patch e scenario count'
assert 'rules/thieffunc.h' in s, 'patch e include'
assert len(applied) + len(already) == 5, 'patch e count wrong'

# ---- (f) tools/phb_gap_report.md: the wiring-arc box ----
GR_HEAD_OLD = NL.join([
    '      R301: the trap site now rolls the seam;',
    '      the other functions stay data) -',
])
GR_HEAD_NEW = NL.join([
    '      R301: the trap site now rolls the seam;',
    '      R302: the surprise site rolls the',
    '      move silently draw; the rest stay',
    '      data) -',
])
GR_INS_OLD = NL.join([
    '      sources). Census 221. The ledger',
    '      holds ZERO open items.',
    '',
    '## R299 the party recordings round (the third',
])
GR_BOX = NL.join([
    '- [x] **The thief silence wired - WIRED',
    '      R302:** the move silently column',
    '      gains its first engine site - the',
    '      encounter surprise roll.',
    '      rules/thieffunc.h gains',
    '      thfSilenceSurpriseAdj (the SILENT',
    '      MOVEMENT print: success means an',
    '      improved chance to surprise; the',
    '      PHB surprise prose is d6-form, the',
    '      engine surprise is the DMG p.62 2d6',
    '      ladder, so the improvement pins as',
    '      one roll step on the surprised side',
    '      - JUDGMENT, the print carries no',
    '      ladder modifier) and',
    '      thfNoteSilenceEachMove (the printed',
    '      note; the site rolls it once per',
    '      encounter - the movement',
    '      granularity simplification).',
    '      ai/actor.h: the Actor gains pcRace',
    '      (the PC CharRace for the percentile;',
    '      toActor copies it, game/party.h) and',
    '      Encounter gains rollSurpriseWired:',
    '      the party side reads the best living',
    '      member DEX reaction adjustment (the',
    '      DMG most-favorable-member reading -',
    '      the DEX reaction surprise note is',
    '      individual-only and the engine keeps',
    '      no per-member clocks) and the first',
    '      living thief rolls the printed',
    '      percentile (success -> the monster',
    '      side takes the -2 step). stepRound',
    '      calls it (the hardcoded zero',
    '      adjustments retired; the log lines',
    '      and the R232 backstab gate read the',
    '      same segments, unchanged). A',
    '      multi-class member rides the primary',
    '      class (the R233 toActor convention)',
    '      - no silence roll. The elven and',
    '      halfling racial surprise prose',
    '      (4-in-6 alone or 90 feet ahead, not',
    '      in metal armor - PHB lines 705/780)',
    '      stays data: no engine site tracks',
    '      formation or metal armor yet. The',
    '      R302a battery audit walks the',
    '      silence step and the move silently',
    '      percentile boundaries (evaluable -',
    '      verified by audit_eval); the R302',
    '      engine audit pins every scenario on',
    '      seeded sequences (the R301 replica',
    '      convention). Census 223. The ledger',
    '      holds ZERO open items.',
])
GR_INS_NEW = NL.join([
    '      sources). Census 221. The ledger',
    '      holds ZERO open items.',
    '',
    GR_BOX,
    '',
    '## R299 the party recordings round (the third',
])
for t in (GR_HEAD_OLD, GR_HEAD_NEW, GR_INS_OLD, GR_BOX, GR_INS_NEW):
    clean(t, 57)

p = 'tools/phb_gap_report.md'
s = rd(p)
if 'The thief silence wired' in s:
    already.append('phb_gap_report.md: the wiring-arc box')
else:
    assert s.count(GR_HEAD_OLD) == 1, 'gr head anchor not unique'
    assert s.count(GR_INS_OLD) == 1, 'gr insert anchor not unique'
    assert 'Census 223.' not in s, 'gr marker collision'
    s = s.replace(GR_HEAD_OLD, GR_HEAD_NEW)
    s = s.replace(GR_INS_OLD, GR_INS_NEW)
    wr(p, s)
    applied.append('phb_gap_report.md: the wiring-arc box')
s = rd(p)
assert s.count('The thief silence wired') == 1, 'patch f box'
assert s.count('R302: the surprise site rolls the') == 1, 'patch f head amend'
assert 'the other functions stay data' not in s, 'patch f stale note'
assert s.count('PINNED R298') == 1, 'patch f ate the R298 box head'
assert s.count('holds ZERO open items') == 2, 'patch f zero-item notes'
assert s.count('Census 223.') == 1, 'patch f census note'
assert 'Census 221.' in s, 'patch f ate the R301 census'
assert 'Census 215.' in s, 'patch f ate the R298 census'
assert 'Census 217.' in s, 'patch f ate the R299 census'
assert 'Census 219.' in s, 'patch f ate the R300 census'
assert 'WIRED R299' in s, 'patch f ate the R299 entry'
assert 'R299 SCOPE PASS' in s, 'patch f ate the R299 pass'
assert '## Out of engine scope' in s, 'patch f ate the scope head'
assert '## R299 the party recordings round' in s, 'patch f ate the R299 head'
assert s.count('- [ ]') == 0, 'patch f opened an item'
assert len(applied) + len(already) == 6, 'patch f count wrong'

# ---- R302 fails/tail ----
if fails:
    print('R302 splice: FAIL - ' + str(len(fails))
          + ' patch(es) failed:')
    for f in fails:
        print('  ' + f)
    sys.exit(1)
if len(applied) + len(already) != 6:
    print('R302 splice: FAIL - expected 6 patches, counted '
          + str(len(applied) + len(already))
          + ' (a truncated paste?)')
    sys.exit(1)
print('R302 splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R302 note: 6 patches; the battery census 221 -> 223;')
print('the phb ledger holds ZERO open items')
print('commit: R302: the thief silence wired (census 223)')

