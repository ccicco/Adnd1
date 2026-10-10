#!/usr/bin/env python3
# tools/r309_splice.py - R309: the hirelings
# cost tables pinned (the first R307 DMG
# open item paid; the R300 successor -
# the DMG HIRELINGS tables join the
# equipment cost columns in the pure-data
# convention).
#
# The pin: the STANDARD HIRELINGS TABLE OF
# DAILY AND MONTHLY COSTS - 10 rows
# (every daily cost in silver pieces,
# every monthly cost in its printed coin -
# gold or silver, exactly one monthly
# column nonzero per row) - and the
# EXPERT HIRELINGS TABLE OF MONTHLY COSTS
# IN GOLD PIECES - 33 rows (the 14
# professions around the 19-row mercenary
# soldier block; the special rows pinned
# -1, the asterisk rows paying 10 percent
# per job on top). The standard
# employment bands ride (1 in 6 long-term
# without a bonus, 3 in 6 with double or
# treble the daily wage). The compilation
# cross-read agrees on every cell but adds
# two OSRIC-sourced rows (cook, groom) -
# excluded per the R211 ground-truth rule.
#
#   (a) rules/hirelings.h - CREATED (the
#       grenade.h pattern; the R300 shape).
#   (b) regtest.cpp - the include line.
#   (c) regtest.cpp - the R309 battery audit
#       (the battery census 232 -> 233): both
#       tables walked cell for cell, the coin
#       identity, the employment bands, the
#       mercenary block, the special and
#       asterisk flags and the clamps.
#   (d) tools/dmg_gap_report.md - the
#       chronicle paragraph.
#   (e) tools/dmg_gap_report.md - the R307
#       open box flipped to the PINNED form
#       (the sage box stays open).
#
# Idempotent: safe to run twice; a silent run
# means the paste was truncated - this tail
# ALWAYS prints. An assert follows EVERY
# patch (the R142 lesson). ZERO literal
# backslash bytes in this file except the
# printf continuation, built via chr(92); no
# CONTENT string embeds an apostrophe,
# non-ASCII, or a line past its bound (78 the
# header, 76 regtest, 57 the gap report).
# Commit: "R309: the hirelings cost tables
# pinned (census 233)"
import os, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NL = chr(10)
Q = chr(39)
DQ = chr(34)
BS = chr(92)
applied, already, fails = [], [], []

def rd(p):
    with open(os.path.join(ROOT, p), encoding='ascii') as f:
        return f.read()

def wr(p, s):
    with open(os.path.join(ROOT, p), 'w', encoding='ascii') as f:
        f.write(s)

def clean(s, limit, gap=False):
    if gap:
        assert Q not in s, 'apostrophe in gap content'
    assert BS not in s, 'backslash in content'
    for ln in s.split(NL):
        assert all(ord(c) < 128 for c in ln), 'non-ascii line'
        assert len(ln) <= limit, 'line too long: ' + ln

# ---- the pin data (single source) ----
# standard rows: (name, dailySp, monthlyGold,
# monthlySilver, the craft percent flag)
STD = [
    ('bearer/porter', 1, 1, 0, 0),
    ('carpenter', 3, 2, 0, 1),
    ('leather worker', 2, 0, 30, 1),
    ('limner', 10, 10, 0, 0),
    ('linkboy', 1, 1, 0, 0),
    ('mason', 4, 3, 0, 0),
    ('pack handler', 2, 0, 30, 0),
    ('tailor', 2, 0, 30, 1),
    ('teamster', 5, 5, 0, 0),
    ('valet/lackey', 3, 0, 50, 0),
]
# expert rows: (name, costGold, mercenary flag,
# the asterisk flag); -1 = special cost
EXP = [
    ('alchemist', 300, 0, 0),
    ('armorer', 100, 0, 1),
    ('blacksmith', 30, 0, 0),
    ('engineer-architect', 100, 0, 1),
    ('engineer-artillerist', 150, 0, 0),
    ('engineer-sapper/miner', 150, 0, 0),
    ('jeweler-gemcutter', 100, 0, 1),
    ('archer, longbow', 4, 1, 0),
    ('archer, shortbow', 2, 1, 0),
    ('artillerist', 5, 1, 0),
    ('captain', -1, 1, 0),
    ('crossbowman', 2, 1, 0),
    ('footman, heavy', 2, 1, 0),
    ('footman, light', 1, 1, 0),
    ('footman, pikeman', 3, 1, 0),
    ('hobilar, heavy', 3, 1, 0),
    ('hobilar, light', 2, 1, 0),
    ('horseman, archer', 6, 1, 0),
    ('horseman, crossbowman', 4, 1, 0),
    ('horseman, heavy', 6, 1, 0),
    ('horseman, light', 3, 1, 0),
    ('horseman, medium', 4, 1, 0),
    ('lieutenant', -1, 1, 0),
    ('sapper/miner', 4, 1, 0),
    ('serjeant', -1, 1, 0),
    ('slinger', 3, 1, 0),
    ('sage', -1, 0, 0),
    ('scribe', 15, 0, 0),
    ('ship crew', -1, 0, 0),
    ('ship master', -1, 0, 0),
    ('spy', -1, 0, 0),
    ('steward/castellan', -1, 0, 0),
    ('weapon maker', 100, 0, 1),
]

def _sanity():
    assert len(STD) == 10, 'std row count'
    assert len(EXP) == 33, 'exp row count'
    for _n, _d, _g, _s, _p in STD:
        assert (_g > 0) + (_s > 0) == 1, 'std monthly coin'
        assert _d > 0 and _g >= 0 and _s >= 0, 'std signs'
    _merc = [_i for _i, _r in enumerate(EXP) if _r[2] == 1]
    assert _merc == list(range(7, 26)), 'mercenary block'
    _ast = [_i for _i, _r in enumerate(EXP) if _r[3] == 1]
    assert _ast == [1, 3, 6, 32], 'asterisk rows'
    assert sum(1 for _r in EXP if _r[1] < 0) == 8, 'special rows'
    assert sum(1 for _r in EXP if _r[1] == 100) == 4, '100-cost rows'
    assert len(set(_r[0] for _r in EXP)) == 33, 'exp names unique'
    assert len(set(_r[0] for _r in STD)) == 10, 'std names unique'
_sanity()

STD_DAILY = [r[1] for r in STD]
STD_GOLD = [r[2] for r in STD]
STD_SILVER = [r[3] for r in STD]
STD_PCT = [r[4] for r in STD]
EXP_COST = [r[1] for r in EXP]
EXP_MERC = [r[2] for r in EXP]
EXP_AST = [r[3] for r in EXP]
EXP_SPEC = [1 if c < 0 else 0 for c in EXP_COST]

def arrlines(vals, indent, per=10):
    out = []
    i = 0
    while i < len(vals):
        chunk = vals[i:i + per]
        out.append(indent + ', '.join('%4d' % v for v in chunk) + ',')
        i += per
    return out

def namelines(names, indent):
    out = []
    for n in names:
        out.append(indent + DQ + n + DQ + ',')
    return out

# ---- (a) rules/hirelings.h CREATED ----
HB = NL.join(
    ['// ===========================================================================',
     '// Adnd1 - rules/hirelings.h',
     '// The hirelings cost tables (R309).',
     '//',
     '// The DMG HIRELINGS section (the STANDARD HIRELINGS',
     '// TABLE OF DAILY AND MONTHLY COSTS, upload line 1817;',
     '// the EXPERT HIRELINGS TABLE OF MONTHLY COSTS IN GOLD',
     '// PIECES, upload line 1873): the standard table - 10',
     '// rows, every daily cost in silver pieces and every',
     '// monthly cost in its printed coin (gold or silver,',
     '// exactly one monthly column nonzero per row) - and',
     '// the expert table - 33 rows, the 14 professions',
     '// around the 19-row mercenary soldier block (the',
     '// block sits between jeweler-gemcutter and sage, the',
     '// print order). The special-cost rows pin as -1 (the',
     '// cost is negotiated: captain, lieutenant, serjeant,',
     '// sage, ship crew, ship master, spy,',
     '// steward/castellan). The asterisk rows (armorer,',
     '// engineer-architect, jeweler-gemcutter, weapon maker',
     '// - the four 100 g.p. rows) and the standard',
     '// double-asterisk rows (carpenter, leather worker,',
     '// tailor) pay 10 percent of the usual price of items',
     '// fashioned or handled on top, per job. The standard',
     '// monthly rate assumes quarters with a bed. The',
     '// standard employment bands: a long-term offer draws',
     '// 1 in 6 willing without a sufficient bonus; a double',
     '// or treble daily-wage bonus makes 3 in 6 willing.',
     '//',
     '// SOURCE NOTE: the 1eonline.info compilation',
     '// cross-read agrees on every cell of both tables but',
     '// adds two rows it sources to OSRIC (cook, groom) -',
     '// compilation additions, not the print; excluded per',
     '// the R211 ground-truth rule.',
     '//',
     '// The description prose rides this pin as recorded',
     '// notes: the armorer skill bands (01-50 ring scale or',
     '// studded, 51-75 plus splint, 76-90 plus chain, 91-00',
     '// any) and manufacture times, one armorer per 40',
     '// soldiers with the spare-time prorate and the',
     '// 310-400 g.p. workroom, the blacksmith 40/160',
     '// coverage and monthly output, the jeweler value',
     '// bands, the alchemist attraction terms, the engineer',
     '// fees and the race efficiency and cost multipliers.',
     '// No engine site charges any of this yet (no',
     '// stronghold hiring layer exists; the town stores',
     '// price canonically).',
     '//',
     '// DATA-DRIVEN (the standing scope).',
     '// ===========================================================================',
     '',
     '#pragma once',
     '',
     'namespace rules {',
     '',
     '// ---- the standard table (10 rows) ----',
     '',
     '// The standard row count (the print: 10 occupations).',
     'inline int hireStdCount() {',
     '    return 10;',
     '}',
     '',
     '// The standard row name at index i (clamped); the',
     '// slash names print as shown.',
     'inline const char* hireStdName(int i) {',
     '    static const char* const kNames[10] = {',
     ] + namelines([r[0] for r in STD], '        ') + [
     '    };',
     '    if (i < 0) i = 0;',
     '    if (i > 9) i = 9;',
     '    return kNames[i];',
     '}',
     '',
     '// The daily cost in silver pieces (clamped).',
     'inline int hireStdDailySp(int i) {',
     '    static const int kDaily[10] = {',
     ] + arrlines(STD_DAILY, '        ') + [
     '    };',
     '    if (i < 0) i = 0;',
     '    if (i > 9) i = 9;',
     '    return kDaily[i];',
     '}',
     '',
     '// The monthly cost in gold pieces (clamped; 0 when',
     '// the row prints in silver).',
     'inline int hireStdMonthlyGold(int i) {',
     '    static const int kGold[10] = {',
     ] + arrlines(STD_GOLD, '        ') + [
     '    };',
     '    if (i < 0) i = 0;',
     '    if (i > 9) i = 9;',
     '    return kGold[i];',
     '}',
     '',
     '// The monthly cost in silver pieces (clamped; 0 when',
     '// the row prints in gold).',
     'inline int hireStdMonthlySilver(int i) {',
     '    static const int kSilver[10] = {',
     ] + arrlines(STD_SILVER, '        ') + [
     '    };',
     '    if (i < 0) i = 0;',
     '    if (i > 9) i = 9;',
     '    return kSilver[i];',
     '}',
     '',
     '// The craft percent flag (clamped): the',
     '// double-asterisk rows add 10 percent of the usual',
     '// price of items fashioned, per job (carpenter,',
     '// leather worker, tailor).',
     'inline int hireStdPercentOnTop(int i) {',
     '    static const int kPct[10] = {',
     ] + arrlines(STD_PCT, '        ') + [
     '    };',
     '    if (i < 0) i = 0;',
     '    if (i > 9) i = 9;',
     '    return kPct[i];',
     '}',
     '',
     '// The long-term employment acceptance: 1 in 6 willing',
     '// without a sufficient bonus; a bonus of double or',
     '// treble the daily wage makes 3 in 6 willing (a',
     '// single daily wage is too small).',
     'inline int hireStdLongTermSixths(int bonusMultiple) {',
     '    if (bonusMultiple >= 2) return 3;',
     '    return 1;',
     '}',
     '',
     '// ---- the expert table (33 rows) ----',
     '',
     '// The expert row count (the print: 14 professions and',
     '// the 19-row mercenary soldier block).',
     'inline int hireExpCount() {',
     '    return 33;',
     '}',
     '',
     '// The expert row name at index i (clamped); the print',
     '// parenthetical weapons read as commas (the R300',
     '// convention).',
     'inline const char* hireExpName(int i) {',
     '    static const char* const kNames[33] = {',
     ] + namelines([r[0] for r in EXP], '        ') + [
     '    };',
     '    if (i < 0) i = 0;',
     '    if (i > 32) i = 32;',
     '    return kNames[i];',
     '}',
     '',
     '// The monthly cost in gold pieces (clamped); -1 pins',
     '// the special rows (the cost is negotiated, not',
     '// fixed).',
     'inline int hireExpCost(int i) {',
     '    static const int kCost[33] = {',
     ] + arrlines(EXP_COST, '        ') + [
     '    };',
     '    if (i < 0) i = 0;',
     '    if (i > 32) i = 32;',
     '    return kCost[i];',
     '}',
     '',
     '// The mercenary soldier block: rows 7-25, the print',
     '// order (the block sits between jeweler-gemcutter',
     '// and sage).',
     'inline int hireExpMercenaryFirst() {',
     '    return 7;',
     '}',
     '',
     'inline int hireExpMercenaryCount() {',
     '    return 19;',
     '}',
     '',
     '// The mercenary block membership at row i (clamped).',
     'inline int hireExpIsMercenary(int i) {',
     '    if (i < 0) i = 0;',
     '    if (i > 32) i = 32;',
     '    if (i >= 7 && i <= 25) return 1;',
     '    return 0;',
     '}',
     '',
     '// The special-cost row flag (clamped): -1 reads',
     '// special.',
     'inline int hireExpIsSpecial(int i) {',
     '    return hireExpCost(i) < 0;',
     '}',
     '',
     '// The asterisk flag (clamped): the rows that add 10',
     '// percent of the usual price of items handled or',
     '// made, per job - the four 100 g.p. rows.',
     'inline int hireExpPercentOnTop(int i) {',
     '    static const int kPct[33] = {',
     ] + arrlines(EXP_AST, '        ') + [
     '    };',
     '    if (i < 0) i = 0;',
     '    if (i > 32) i = 32;',
     '    return kPct[i];',
     '}',
     '',
     '}  // namespace rules',
     '',
     ])
clean(HB, 78)
assert Q not in HB, 'apostrophe in header'

p = 'rules/hirelings.h'
if os.path.exists(os.path.join(ROOT, p)):
    s = rd(p)
    if 'inline int hireStdCount() {' in s:
        already.append('hirelings.h created')
    else:
        fails.append('hirelings.h exists without the R309 marker')
else:
    wr(p, HB)
    applied.append('hirelings.h created')

s = rd(p)
assert s.count('inline int hireStd') == 6, 'hb std pin count'
assert s.count('hireStd') == 7, 'hb std name count'
assert s.count('inline int hireExp') == 7, 'hb exp pin count'
assert s.count('hireExp') == 9, 'hb exp name count'
assert s.count('hireStdLongTermSixths') == 1, 'hb employment pin'
assert s.count('}  // namespace rules') == 1, 'hb namespace close'
assert s.count('{') == s.count('}'), 'hb brace balance'
assert s.count('(') == s.count(')'), 'hb paren balance'
assert Q not in s, 'hb apostrophes'
assert s.count('return 10;') == 1, 'hb std count'
assert s.count('return 33;') == 1, 'hb exp count'
assert s.count('return 19;') == 1, 'hb merc count'
assert s.count('return 7;') == 1, 'hb merc first'
assert len(applied) + len(already) == 1, 'patch a count wrong'

# ---- (b) regtest.cpp: the include line ----
INC_OLD = NL.join([
    '#include "rules/equipcosts.h"  // R300: the equipment cost columns',
])
INC_NEW = NL.join([
    '#include "rules/equipcosts.h"  // R300: the equipment cost columns',
    '#include "rules/hirelings.h"  // R309: the hirelings cost tables',
])
clean(INC_OLD, 76)
clean(INC_NEW, 76)

p = 'regtest.cpp'
s = rd(p)
if '#include "rules/hirelings.h"' in s:
    already.append('regtest.cpp: the include line')
else:
    assert s.count(INC_OLD) == 1, 'include anchor not unique'
    assert 'hirelings.h' not in s, 'include marker collision'
    s = s.replace(INC_OLD, INC_NEW)
    wr(p, s)
    applied.append('regtest.cpp: the include line')

s = rd(p)
assert s.count('#include "rules/hirelings.h"') == 1, 'patch b include'
assert s.count('#include "rules/equipcosts.h"') == 1, 'patch b intact'
assert len(applied) + len(already) == 2, 'patch b count wrong'

# ---- (c) regtest.cpp: the audit block ----
RT_TAIL = NL.join([
    '        printf("R308 general equipment lists audit: bad %d'
    + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
])
RT_AUD = NL.join(
    ['    // ---- R309: the hirelings cost tables audit ----',
     '    // The two DMG HIRELINGS tables (rules/hirelings.h)',
     '    // walked cell for cell against this local ground',
     '    // truth: the standard daily and monthly columns',
     '    // (the monthly coin identity), the craft percent',
     '    // flags, the employment bands, the expert cost',
     '    // column (the -1 special rows), the mercenary',
     '    // block boundaries, the special and asterisk flags',
     '    // and the clamps.',
     '    {',
     '        int bad = 0;',
     '        static const int kDaily[10] = {',
     ] + arrlines(STD_DAILY, '            ') + [
     '        };',
     '        static const int kGold[10] = {',
     ] + arrlines(STD_GOLD, '            ') + [
     '        };',
     '        static const int kSilver[10] = {',
     ] + arrlines(STD_SILVER, '            ') + [
     '        };',
     '        static const int kPct[10] = {',
     ] + arrlines(STD_PCT, '            ') + [
     '        };',
     '        static const int kCost[33] = {',
     ] + arrlines(EXP_COST, '            ') + [
     '        };',
     '        static const int kMerc[33] = {',
     ] + arrlines(EXP_MERC, '            ') + [
     '        };',
     '        static const int kSpec[33] = {',
     ] + arrlines(EXP_SPEC, '            ') + [
     '        };',
     '        static const int kAst[33] = {',
     ] + arrlines(EXP_AST, '            ') + [
     '        };',
     '        // the standard counts and columns',
     '        if (rules::hireStdCount() != 10) ++bad;',
     '        for (int i = 0; i < 10; ++i)',
     '            if (rules::hireStdDailySp(i) != kDaily[i]) ++bad;',
     '        for (int i = 0; i < 10; ++i)',
     '            if (rules::hireStdMonthlyGold(i) != kGold[i]) ++bad;',
     '        for (int i = 0; i < 10; ++i)',
     '            if (rules::hireStdMonthlySilver(i) != kSilver[i])',
     '                ++bad;',
     '        // the monthly coin identity: exactly one',
     '        // nonzero column per row (two columns - the',
     '        // pairwise form reads exactly-one-nonzero)',
     '        for (int i = 0; i < 10; ++i)',
     '            if ((rules::hireStdMonthlyGold(i) == 0) ==',
     '                (rules::hireStdMonthlySilver(i) == 0)) ++bad;',
     '        // the craft percent flags',
     '        for (int i = 0; i < 10; ++i)',
     '            if (rules::hireStdPercentOnTop(i) != kPct[i]) ++bad;',
     '        // worked standard rows: the limner 10 s.p.',
     '        // daily and 10 g.p. monthly, the leather',
     '        // worker 30 s.p., the valet 50 s.p.',
     '        if (rules::hireStdDailySp(3) != 10 ||',
     '            rules::hireStdMonthlyGold(3) != 10 ||',
     '            rules::hireStdMonthlySilver(2) != 30 ||',
     '            rules::hireStdMonthlySilver(9) != 50) ++bad;',
     '        // the standard clamps (row -5 the bearer, row',
     '        // 99 the valet)',
     '        if (rules::hireStdDailySp(-5) != 1 ||',
     '            rules::hireStdDailySp(99) != 3 ||',
     '            rules::hireStdMonthlyGold(-5) != 1 ||',
     '            rules::hireStdMonthlyGold(99) != 0 ||',
     '            rules::hireStdMonthlySilver(-5) != 0 ||',
     '            rules::hireStdMonthlySilver(99) != 50 ||',
     '            rules::hireStdPercentOnTop(-5) != 0 ||',
     '            rules::hireStdPercentOnTop(99) != 0) ++bad;',
     '        // the employment bands: no bonus or a single',
     '        // daily wage draws 1 in 6; double or treble',
     '        // draws 3 in 6',
     '        if (rules::hireStdLongTermSixths(0) != 1 ||',
     '            rules::hireStdLongTermSixths(1) != 1 ||',
     '            rules::hireStdLongTermSixths(2) != 3 ||',
     '            rules::hireStdLongTermSixths(3) != 3 ||',
     '            rules::hireStdLongTermSixths(9) != 3) ++bad;',
     '        // the expert counts and boundaries',
     '        if (rules::hireExpCount() != 33 ||',
     '            rules::hireExpMercenaryFirst() != 7 ||',
     '            rules::hireExpMercenaryCount() != 19) ++bad;',
     '        // the expert cost column, every row',
     '        for (int i = 0; i < 33; ++i)',
     '            if (rules::hireExpCost(i) != kCost[i]) ++bad;',
     '        // the mercenary block membership',
     '        for (int i = 0; i < 33; ++i)',
     '            if (rules::hireExpIsMercenary(i) != kMerc[i]) ++bad;',
     '        // the special rows read -1',
     '        for (int i = 0; i < 33; ++i)',
     '            if (rules::hireExpIsSpecial(i) != kSpec[i]) ++bad;',
     '        // the asterisk flags',
     '        for (int i = 0; i < 33; ++i)',
     '            if (rules::hireExpPercentOnTop(i) != kAst[i]) ++bad;',
     '        // the asterisk-cost identity: the flagged rows',
     '        // are exactly the four 100 g.p. rows',
     '        for (int i = 0; i < 33; ++i)',
     '            if ((rules::hireExpCost(i) == 100) !=',
     '                (rules::hireExpPercentOnTop(i) == 1)) ++bad;',
     '        // worked expert rows: the alchemist 300, the',
     '        // blacksmith 30, the scribe 15, the horseman',
     '        // heavy 6, the footman light 1',
     '        if (rules::hireExpCost(0) != 300 ||',
     '            rules::hireExpCost(2) != 30 ||',
     '            rules::hireExpCost(27) != 15 ||',
     '            rules::hireExpCost(19) != 6 ||',
     '            rules::hireExpCost(13) != 1) ++bad;',
     '        // the expert clamps (row -5 the alchemist, row',
     '        // 99 the weapon maker; the mercenary edges)',
     '        if (rules::hireExpCost(-5) != 300 ||',
     '            rules::hireExpCost(99) != 100 ||',
     '            rules::hireExpIsMercenary(6) != 0 ||',
     '            rules::hireExpIsMercenary(7) != 1 ||',
     '            rules::hireExpIsMercenary(25) != 1 ||',
     '            rules::hireExpIsMercenary(26) != 0 ||',
     '            rules::hireExpIsMercenary(-5) != 0 ||',
     '            rules::hireExpIsMercenary(99) != 0 ||',
     '            rules::hireExpPercentOnTop(-5) != 0 ||',
     '            rules::hireExpPercentOnTop(99) != 1) ++bad;',
     '        printf("R309 hirelings cost tables audit: bad %d'
     + BS + 'n", bad);',
     '        if (bad) return 1;',
     '    }',
     ])
RT_OLD = NL.join([
    RT_TAIL,
    '    // ---- R227: the wis mental save wiring audit ----',
])
RT_NEW = NL.join([
    RT_TAIL,
    RT_AUD,
    '    // ---- R227: the wis mental save wiring audit ----',
])
# the audit block carries the printf newline (BS) - the
# R300 check: BS lives ONLY on the printf lines, one
# per line, and nothing else carries a backslash
for _t in (RT_OLD, RT_NEW):
    for _ln in _t.split(NL):
        assert all(ord(_c) < 128 for _c in _ln), 'non-ascii in audit'
        assert len(_ln) <= 76, 'audit line too long: ' + _ln
        assert Q not in _ln, 'apostrophe in audit'
        if 'printf("' in _ln:
            assert _ln.count(BS) == 1, 'printf BS count wrong'
        else:
            assert BS not in _ln, 'stray backslash in audit'

p = 'regtest.cpp'
s = rd(p)
if 'R309 hirelings cost tables audit' in s:
    already.append('regtest.cpp: the audit block')
else:
    assert s.count('audit: bad') == 232, 'rt census not 232'
    assert s.count(RT_OLD) == 1, 'rt anchor not unique'
    assert 'hireStd' not in s and 'hireExp' not in s, 'rt collision'
    s = s.replace(RT_OLD, RT_NEW)
    wr(p, s)
    applied.append('regtest.cpp: the audit block')

s = rd(p)
assert s.count('audit: bad') == 233, 'patch c census wrong'
assert s.count('R309 hirelings cost tables audit') == 1, 'c label'
assert s.count('R308 general equipment lists audit') == 1, 'c r308 tail'
assert s.count('R227: the wis mental save wiring audit') == 1, 'c head'
assert s.count('rules/hirelings.h') == 2, 'c references'
assert s.count('{') == s.count('}'), 'rt brace balance'
assert s.count('(') == s.count(')'), 'rt paren balance'
assert len(applied) + len(already) == 3, 'patch c count wrong'

# ---- (d) tools/dmg_gap_report.md: the chronicle ----
CH_OLD = NL.join([
    'the battery census stays 231.',
    '',
    'Categories:',
])
CH_NEW = NL.join([
    'the battery census stays 231.',
    '',
    'R309 the hirelings cost tables pin (an',
    'engine round): the first R307 open box',
    'paid. rules/hirelings.h (the grenade.h',
    'pattern): the STANDARD table - 10 rows,',
    'every daily cost in silver, every',
    'monthly cost in its printed coin',
    '(exactly one monthly column nonzero);',
    'the EXPERT table - 33 rows, the special',
    'rows pinned -1 (negotiated: captain,',
    'lieutenant, serjeant, sage, ship crew,',
    'ship master, spy, steward/castellan)',
    'and the asterisk rows (the four 100',
    'g.p. rows: armorer, engineer-architect,',
    'jeweler-gemcutter, weapon maker) paying',
    '10 percent per job on top. The standard',
    'employment bands ride (1 in 6 long-term',
    'without a bonus, 3 in 6 with double or',
    'treble the daily wage). The compilation',
    'cross-read agrees on every cell but',
    'adds two OSRIC-sourced rows (cook,',
    'groom) - excluded per the R211 rule. No',
    'engine site charges them yet; the',
    'battery census moves 232 -> 233 with',
    'the R309 audit.',
    '',
    'Categories:',
])
clean(CH_OLD, 57, gap=True)
clean(CH_NEW, 57, gap=True)

p = 'tools/dmg_gap_report.md'
s = rd(p)
if 'R309 the hirelings cost tables pin' in s:
    already.append('dmg report: the chronicle')
else:
    assert s.count(CH_OLD) == 1, 'chronicle anchor not unique'
    s = s.replace(CH_OLD, CH_NEW)
    wr(p, s)
    applied.append('dmg report: the chronicle')

s = rd(p)
assert s.count('R309 the hirelings cost tables pin') == 1, 'd entry'
assert s.count('Categories:') == 1, 'd legend head'
assert s.count('moves 232 -> 233') == 1, 'd census note'
assert len(applied) + len(already) == 4, 'patch d count wrong'

# ---- (e) tools/dmg_gap_report.md: the box flip ----
BX_OLD = NL.join([
    '- [ ] **Standard and expert hirelings',
    '      cost tables (the STANDARD',
    '      HIRELINGS TABLE OF DAILY AND',
    '      MONTHLY COSTS, upload line 1817;',
    '      the EXPERT HIRELINGS TABLE OF',
    '      MONTHLY COSTS IN GOLD PIECES,',
    '      upload line 1873) - OPENED R307:**',
    '      the R121 officers slice',
    '      and the R212 NPC spell prices',
    '      never carried the tables. A',
    '      data candidate: the daily and',
    '      monthly bands pin rules-side',
    '      (the R300 pattern - pure data;',
    '      no site charges them until a',
    '      round wires one). The expert',
    '      types prose and the employment',
    '      prose ride this box, and the PHB',
    '      HIRELINGS prose rides it too',
    '      (the hireling count is never',
    '      charisma-limited; the loyalty',
    '      discussion is the henchmen one).',
])
BX_NEW = NL.join([
    '- [x] **Standard and expert hirelings',
    '      cost tables (the STANDARD',
    '      HIRELINGS TABLE OF DAILY AND',
    '      MONTHLY COSTS, upload line 1817;',
    '      the EXPERT HIRELINGS TABLE OF',
    '      MONTHLY COSTS IN GOLD PIECES,',
    '      upload line 1873) - PINNED R309:**',
    '      rules/hirelings.h (the R300',
    '      pattern): the standard table -',
    '      10 rows, the daily costs in',
    '      silver, the monthly costs in the',
    '      printed coin (exactly one',
    '      monthly column nonzero per row);',
    '      the craft percent flags on',
    '      carpenter, leather worker and',
    '      tailor; the employment bands (1',
    '      in 6 long-term, 3 in 6 with a',
    '      double or treble daily-wage',
    '      bonus); the expert table - 33',
    '      rows, the mercenary soldier',
    '      block at rows 7-25, the special',
    '      rows pinned -1 and the asterisk',
    '      rows (the four 100 g.p. rows)',
    '      paying 10 percent per job. The',
    '      description prose (the armorer',
    '      skill bands and manufacture',
    '      times, the blacksmith output,',
    '      the jeweler bands, the race',
    '      multipliers) rides as recorded',
    '      notes; no engine site charges',
    '      them yet (no stronghold hiring',
    '      layer). The sage subsection',
    '      stays open below.',
    '      Census 233. The',
    '      ledger holds ONE open item.',
])
clean(BX_OLD, 57, gap=True)
clean(BX_NEW, 57, gap=True)

p = 'tools/dmg_gap_report.md'
s = rd(p)
if 'PINNED R309' in s:
    already.append('dmg report: the box flip')
else:
    assert s.count(BX_OLD) == 1, 'box anchor not unique'
    assert s.count('- [ ]') == 3, 'dmg open count not 3'
    s = s.replace(BX_OLD, BX_NEW)
    wr(p, s)
    applied.append('dmg report: the box flip')

s = rd(p)
assert s.count('PINNED R309') == 1, 'patch e pinned tag'
assert s.count('OPENED R307') == 1, 'patch e sage box intact'
assert s.count('- [ ]') == 2, 'patch e open residue'
assert s.count('Census 233') == 1, 'patch e census note'
assert s.count('## Out of scope by design') == 1, 'e out head intact'
assert len(applied) + len(already) == 5, 'patch e count wrong'

# ---- R309 fails/tail ----
if fails:
    print('R309 splice: FAIL - ' + str(len(fails))
          + ' patch(es) failed:')
    for f in fails:
        print('  ' + f)
    sys.exit(1)
if len(applied) + len(already) != 5:
    print('R309 splice: FAIL - expected 5 patches, counted '
          + str(len(applied) + len(already))
          + ' (a truncated paste?)')
    sys.exit(1)
print('R309 splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R309 note: 5 patches; the hirelings')
print('cost tables pinned - the battery')
print('census moves 232 -> 233; the dmg')
print('ledger holds ONE open item (sage)')
print('commit: R309: the hirelings cost tables')
print('pinned (census 233)')

