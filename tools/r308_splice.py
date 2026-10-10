#!/usr/bin/env python3
# tools/r308_splice.py - R308: the general
# equipment lists pinned (the R307 open item
# paid; the R300 successor - the eight printed
# general lists join the arms and armor columns
# in rules/equipcosts.h).
#
# The pin: 99 rows across the EIGHT printed
# lists - clothing 11, herbs 3, livestock 21,
# miscellaneous equipment and items 29,
# provisions 10, religious items 6, tack and
# harness 9, transport 10. Every price pins in
# its printed coin (three coin columns, exactly
# one nonzero per row: 11 copper, 29 silver,
# 59 gold). The reference sheet is the complete
# legible copy (it resolves the scrambled herbs
# cells and the eight transport cells the
# equipment-section OCR drops); both copies
# agree on every shared cell. The row order is
# the R300 arms convention (left column then
# right, per list). The monetary pins join the
# R300 silver one: 10 c.p. = 1 s.p. and
# 200 c.p. = 1 g.p.
#
#   (a) rules/equipcosts.h - the head line
#       amended, the out-of-scope note amended
#       (the R307 open item supersedes it) and
#       the general section grown (the count,
#       list-count and first-row helpers, the
#       name array and the three coin arrays;
#       the copper monetary pins).
#   (b) regtest.cpp - the R308 battery audit
#       (the battery census 231 -> 232): the 99
#       rows walked cell for cell against the
#       local ground truth, the coin identity,
#       the list boundaries, the clamps, the
#       herbs cells and the monetary pins.
#   (c) tools/phb_gap_report.md - the R307 open
#       box flipped to the PINNED form (the
#       ledger holds ZERO open items again).
#
# Idempotent: safe to run twice; a silent run
# means the paste was truncated - this tail
# ALWAYS prints. An assert follows EVERY patch
# (the R142 lesson). ZERO literal backslash
# bytes in this file except the assert
# continuations; no CONTENT string embeds an
# apostrophe outside the two print names (built
# via chr(39), the R182 precedent), non-ASCII,
# or a line past its bound (78 the header, 76
# regtest, 57 the gap report). The audit arrays
# and the header arrays build from ONE table -
# they cannot drift.
# Commit: "R308: the general equipment lists
# pinned (census 232)"
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

# ---- the pin table: 8 lists, 99 rows ----
# (name, coin, value); coin g gold, s silver, c copper.
GENERAL = [
    ('clothing', [
        ('belt', 's', 3),
        ('boots, high, hard', 'g', 2),
        ('boots, high, soft', 'g', 1),
        ('boots, low, hard', 'g', 1),
        ('boots, low, soft', 's', 8),
        ('cap', 's', 1),
        ('cloak', 's', 5),
        ('girdle, broad', 'g', 2),
        ('girdle, normal', 's', 10),
        ('hat', 's', 7),
        ('robe', 's', 6),
    ]),
    ('herbs', [
        ('belladonna, sprig', 's', 4),
        ('garlic, bud', 'c', 5),
        ('wolvesbane, sprig', 's', 10),
    ]),
    ('livestock', [
        ('chicken', 'c', 3),
        ('cow', 'g', 10),
        ('dog, guard', 'g', 25),
        ('dog, hunting', 'g', 17),
        ('donkey', 'g', 8),
        ('goat', 'g', 1),
        ('hawk, large', 'g', 40),
        ('hawk, small', 'g', 18),
        ('horse, draft', 'g', 30),
        ('horse, heavy war', 'g', 300),
        ('horse, light war', 'g', 150),
        ('horse, medium war', 'g', 225),
        ('horse, riding, light', 'g', 25),
        ('mule', 'g', 20),
        ('ox', 'g', 15),
        ('pigeon', 'c', 2),
        ('piglet', 'g', 1),
        ('pig', 'g', 3),
        ('pony', 'g', 15),
        ('sheep', 'g', 2),
        ('songbird', 'c', 4),
    ]),
    ('misc', [
        ('backpack, leather', 'g', 2),
        ('box, iron, large', 'g', 28),
        ('box, iron, small', 'g', 9),
        ('candle, tallow', 'c', 1),
        ('candle, wax', 's', 1),
        ('case, bone, map or scroll', 'g', 5),
        ('case, leather, map or scroll', 's', 15),
        ('chest, wooden, large', 's', 17),
        ('chest, wooden, small', 's', 8),
        ('lantern, bullseye', 'g', 12),
        ('lantern, hooded', 'g', 7),
        ('mirror, large metal', 'g', 10),
        ('mirror, small, silver', 'g', 20),
        ('oil, flask of', 'g', 1),
        ('pole, 10 foot', 'c', 3),
        ('pouch, belt, large', 'g', 1),
        ('pouch, belt, small', 's', 15),
        ('quiver, 1 dozen arrows', 's', 8),
        ('quiver, 1 score arrows', 's', 12),
        ('quiver, 1 score bolts', 's', 15),
        ('quiver, 2 score bolts', 'g', 1),
        ('rope, 50 foot', 's', 4),
        ('sack, large', 'c', 16),
        ('sack, small', 'c', 10),
        ('skin for water or wine', 's', 15),
        ('spike, iron, large', 'c', 1),
        ('thievesTHIEF picks and tools', 'g', 30),
        ('tinder box with flint and steel', 'g', 1),
        ('torch', 'c', 1),
    ]),
    ('provisions', [
        ('ale, pint', 's', 1),
        ('beer, small, pint', 'c', 5),
        ('food, merchantFOOD meal', 's', 1),
        ('food, rich meal', 'g', 1),
        ('grain, horse meal, 1 day', 's', 1),
        ('mead, pint', 's', 5),
        ('rations, iron, 1 week', 'g', 5),
        ('rations, standard, 1 week', 'g', 3),
        ('wine, pint, good', 's', 10),
        ('wine, pint, watered', 's', 5),
    ]),
    ('religious', [
        ('beads, prayer', 'g', 1),
        ('incense, stick', 'g', 1),
        ('symbol, holy, iron', 'g', 2),
        ('symbol, holy, silver', 'g', 50),
        ('symbol, holy, wooden', 's', 7),
        ('water, holy, vial', 'g', 25),
    ]),
    ('tack', [
        ('barding, chain', 'g', 250),
        ('barding, leather', 'g', 100),
        ('barding, plate', 'g', 500),
        ('bit and bridle', 's', 15),
        ('harness', 's', 12),
        ('saddle', 'g', 10),
        ('saddle bags, large', 'g', 4),
        ('saddle bags, small', 'g', 3),
        ('saddle blanket', 's', 3),
    ]),
    ('transport', [
        ('barge or raft, small', 'g', 50),
        ('boat, small', 'g', 75),
        ('boat, long', 'g', 150),
        ('cart', 'g', 50),
        ('galley, large', 'g', 25000),
        ('galley, small', 'g', 10000),
        ('ship, merchant, large', 'g', 15000),
        ('ship, merchant, small', 'g', 5000),
        ('ship, war', 'g', 20000),
        ('wagon', 'g', 150),
    ]),
]

# the two print apostrophe names build via Q (the R182 lesson)
GENERAL[3][1][26] = ('thieves' + Q + ' picks and tools', 'g', 30)
GENERAL[4][1][2] = ('food, merchant' + Q + 's meal', 's', 1)

ROWS = []
for _name, _rows in GENERAL:
    ROWS.extend(_rows)
COUNTS = [len(_r) for _, _r in GENERAL]
FIRSTS = []
_acc = 0
for _c in COUNTS:
    FIRSTS.append(_acc)
    _acc += _c

GOLD = [v if c == 'g' else 0 for _n, c, v in ROWS]
SILVER = [v if c == 's' else 0 for _n, c, v in ROWS]
COPPER = [v if c == 'c' else 0 for _n, c, v in ROWS]

def _sanity():
    assert len(ROWS) == 99, 'row count'
    assert COUNTS == [11, 3, 21, 29, 10, 6, 9, 10], 'counts'
    assert FIRSTS == [0, 11, 14, 35, 64, 74, 80, 89], 'firsts'
    for i in range(99):
        nz = (GOLD[i] > 0) + (SILVER[i] > 0) + (COPPER[i] > 0)
        assert nz == 1, 'coin identity row ' + str(i)
    assert COPPER.count(0) == 88, 'copper rows'
    assert SILVER.count(0) == 70, 'silver rows'
    assert GOLD.count(0) == 40, 'gold rows'
_sanity()

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

# ---- (a1) rules/equipcosts.h: the head line ----
EQ_A1_OLD = NL.join([
    '// The equipment cost columns (R300).',
])
EQ_A1_NEW = NL.join([
    '// The equipment cost columns (R300; the',
    '// general lists R308).',
])
clean(EQ_A1_OLD, 78)
clean(EQ_A1_NEW, 78)

# ---- (a2) rules/equipcosts.h: the scope note ----
EQ_A2_OLD = NL.join([
    '// armor id to its printed row. The general equipment rows',
    '// (clothing, herbs, livestock, provisions, religious items,',
    '// tack, transport) carry no engine layer - out of engine',
    '// scope.',
])
EQ_A2_NEW = NL.join([
    '// armor id to its printed row. The general equipment rows',
    '// (clothing, herbs, livestock, provisions, religious items,',
    '// tack, transport) are the R308 general lists below - the',
    '// R307 scope pass opened them, R308 pins them, and no',
    '// engine site charges them yet (the town stores price',
    '// canonically).',
])
clean(EQ_A2_OLD, 78)
clean(EQ_A2_NEW, 78)

# ---- (a3) rules/equipcosts.h: the general section ----
EQ_A3_OLD = NL.join([
    '// The monetary-system pin: 20 silver pieces = 1 gold',
    '// piece (the upload MONETARY SYSTEM section).',
    'inline int eqcSilverPerGold() {',
    '    return 20;',
    '}',
    '',
    '}  // namespace rules',
])
GEN_NAMES = namelines([_r[0] for _r in ROWS], '        ')
GOLD_H = arrlines(GOLD, '        ')
SILVER_H = arrlines(SILVER, '        ')
COPPER_H = arrlines(COPPER, '        ')
EQ_A3_NEW = NL.join(
    ['// ---- the general lists (R308) ----',
     '',
     '// The EIGHT printed general lists of the BASIC',
     '// EQUIPMENT AND SUPPLIES COSTS tables (the',
     '// equipment section, upload lines 2344-2437; the',
     '// reference-sheet repeat, upload lines 13473-13541):',
     '// clothing 11 rows, herbs 3, livestock 21,',
     '// miscellaneous equipment and items 29, provisions',
     '// 10, religious items 6, tack and harness 9,',
     '// transport 10 - 99 rows together. Every price pins',
     '// in its printed coin (exactly one coin column',
     '// nonzero per row: 11 copper, 29 silver, 59 gold).',
     '// The row order is the R300 arms convention (the',
     '// left column then the right, per list). The',
     '// reference sheet is the complete legible copy: it',
     '// resolves the scrambled herbs cells and the eight',
     '// transport cells the equipment-section OCR drops.',
     '',
     '// The chart row count (the print: 99 general rows).',
     'inline int eqcGeneralCount() {',
     '    return 99;',
     '}',
     '',
     '// The list row count at list index l (clamped):',
     '// clothing 0, herbs 1, livestock 2, miscellaneous',
     '// equipment and items 3, provisions 4, religious',
     '// items 5, tack and harness 6, transport 7.',
     'inline int eqcGeneralListCount(int l) {',
     '    static const int kCounts[8] = {',
     ] + arrlines(COUNTS, '        ') + [
     '    };',
     '    if (l < 0) l = 0;',
     '    if (l > 7) l = 7;',
     '    return kCounts[l];',
     '}',
     '',
     '// The first row of list l (clamped).',
     'inline int eqcGeneralFirst(int l) {',
     '    static const int kFirst[8] = {',
     ] + arrlines(FIRSTS, '        ') + [
     '    };',
     '    if (l < 0) l = 0;',
     '    if (l > 7) l = 7;',
     '    return kFirst[l];',
     '}',
     '',
     '// The general row name at index i (clamped), the',
     '// R300 name spellings (the foot marks spelled out;',
     '// the ampersands read as and; the riding-light',
     '// horse parens dropped). The two print apostrophe',
     '// names ride as printed; the holy symbol and holy',
     '// water rows serve the unholy footnote equally.',
     'inline const char* eqcGeneralName(int i) {',
     '    static const char* const kNames[99] = {',
     ] + GEN_NAMES + [
     '    };',
     '    if (i < 0) i = 0;',
     '    if (i > 98) i = 98;',
     '    return kNames[i];',
     '}',
     '',
     '// The general price in gold pieces (clamped; the 59',
     '// gold rows).',
     'inline int eqcGeneralGold(int i) {',
     '    static const int kGold[99] = {',
     ] + GOLD_H + [
     '    };',
     '    if (i < 0) i = 0;',
     '    if (i > 98) i = 98;',
     '    return kGold[i];',
     '}',
     '',
     '// The general price in silver pieces (clamped; the',
     '// 29 silver rows).',
     'inline int eqcGeneralSilver(int i) {',
     '    static const int kSilver[99] = {',
     ] + SILVER_H + [
     '    };',
     '    if (i < 0) i = 0;',
     '    if (i > 98) i = 98;',
     '    return kSilver[i];',
     '}',
     '',
     '// The general price in copper pieces (clamped; the',
     '// 11 copper rows).',
     'inline int eqcGeneralCopper(int i) {',
     '    static const int kCopper[99] = {',
     ] + COPPER_H + [
     '    };',
     '    if (i < 0) i = 0;',
     '    if (i > 98) i = 98;',
     '    return kCopper[i];',
     '}',
     '',
     '// The monetary-system pins (the upload MONETARY',
     '// SYSTEM section: 200 c.p. = 20 s.p. = 1 g.p.): the',
     '// R300 silver pin and the R308 copper pins.',
     'inline int eqcSilverPerGold() {',
     '    return 20;',
     '}',
     '',
     'inline int eqcCopperPerSilver() {',
     '    return 10;',
     '}',
     '',
     'inline int eqcCopperPerGold() {',
     '    return 200;',
     '}',
     '',
     '}  // namespace rules',
     ])
clean(EQ_A3_OLD, 78)
clean(EQ_A3_NEW, 78)

# ---- apply: the equipcosts.h patches ----
p = 'rules/equipcosts.h'
s = rd(p)
if 'general lists R308).' in s:
    already.append('equipcosts.h: the head line')
else:
    assert s.count(EQ_A1_OLD) == 1, 'eq a1 anchor not unique'
    s = s.replace(EQ_A1_OLD, EQ_A1_NEW)
    applied.append('equipcosts.h: the head line')
if 'R307 scope pass opened them' in s:
    already.append('equipcosts.h: the scope note')
else:
    assert s.count(EQ_A2_OLD) == 1, 'eq a2 anchor not unique'
    s = s.replace(EQ_A2_OLD, EQ_A2_NEW)
    applied.append('equipcosts.h: the scope note')
if 'inline int eqcGeneralCount() {' in s:
    already.append('equipcosts.h: the general section')
else:
    assert s.count(EQ_A3_OLD) == 1, 'eq a3 anchor not unique'
    assert 'eqcGeneral' not in s, 'eq marker collision'
    s = s.replace(EQ_A3_OLD, EQ_A3_NEW)
    applied.append('equipcosts.h: the general section')
wr(p, s)

s = rd(p)
assert s.count('general lists R308).') == 1, 'patch a1 head'
assert s.count('R307 scope pass opened them') == 1, 'patch a2 note'
assert s.count('inline int eqcGeneralCount() {') == 1, 'a3 count fn'
assert s.count('inline int eqcGeneralListCount(int l) {') == 1, 'a3 lc'
assert s.count('inline int eqcGeneralFirst(int l) {') == 1, 'a3 first'
assert s.count('inline const char* eqcGeneralName(int i) {') == 1
assert s.count('inline int eqcGeneralGold(int i) {') == 1, 'a3 gold'
assert s.count('inline int eqcGeneralSilver(int i) {') == 1, 'a3 silver'
assert s.count('inline int eqcGeneralCopper(int i) {') == 1, 'a3 copper'
assert s.count('inline int eqcCopperPerSilver() {') == 1, 'a3 cps'
assert s.count('inline int eqcCopperPerGold() {') == 1, 'a3 cpg'
assert s.count('return 99;') == 1, 'a3 row count'
assert s.count('return 200;') == 1, 'a3 copper gold pin'
assert s.count('out of engine') == 0, 'scope note residue'
assert s.count(Q) == 2, 'apostrophe count'
assert s.count('{') == s.count('}'), 'eq brace balance'
assert s.count('(') == s.count(')'), 'eq paren balance'
assert len(applied) + len(already) == 3, 'eq patch count wrong'

# ---- (b) regtest.cpp: the audit block ----
RT_TAIL = NL.join([
    '        printf("R306 thief functions engine audit: bad %d'
    + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
])
RT_AUD = NL.join(
    ['    // ---- R308: the general equipment lists audit ----',
     '    // The EIGHT printed general lists (the',
     '    // rules/equipcosts.h general section) walked cell',
     '    // for cell against this local ground truth: the',
     '    // row count, the list boundaries, the three coin',
     '    // columns, the coin identity (exactly one nonzero',
     '    // column per row), the clamps, the herbs cells the',
     '    // reference sheet resolves, the worked rows and',
     '    // the monetary pins.',
     '    {',
     '        int bad = 0;',
     '        static const int kGold[99] = {',
     ] + arrlines(GOLD, '            ') + [
     '        };',
     '        static const int kSilver[99] = {',
     ] + arrlines(SILVER, '            ') + [
     '        };',
     '        static const int kCopper[99] = {',
     ] + arrlines(COPPER, '            ') + [
     '        };',
     '        static const int kFirst[8] = {',
     ] + arrlines(FIRSTS, '            ') + [
     '        };',
     '        static const int kCount[8] = {',
     ] + arrlines(COUNTS, '            ') + [
     '        };',
     '        // the row count',
     '        if (rules::eqcGeneralCount() != 99) ++bad;',
     '        // the list boundaries',
     '        for (int l = 0; l < 8; ++l)',
     '            if (rules::eqcGeneralFirst(l) != kFirst[l] ||',
     '                rules::eqcGeneralListCount(l) != kCount[l])',
     '                ++bad;',
     '        // the three coin columns, every row',
     '        for (int i = 0; i < 99; ++i)',
     '            if (rules::eqcGeneralGold(i) != kGold[i]) ++bad;',
     '        for (int i = 0; i < 99; ++i)',
     '            if (rules::eqcGeneralSilver(i) != kSilver[i])',
     '                ++bad;',
     '        for (int i = 0; i < 99; ++i)',
     '            if (rules::eqcGeneralCopper(i) != kCopper[i])',
     '                ++bad;',
     '        // the coin identity: exactly one nonzero',
     '        // column per row (the three-column count -',
     '        // the R300 pairwise form reads false on the',
     '        // copper rows, where gold and silver both',
     '        // sit at zero)',
     '        for (int i = 0; i < 99; ++i)',
     '            if ((rules::eqcGeneralGold(i) > 0) +',
     '                (rules::eqcGeneralSilver(i) > 0) +',
     '                (rules::eqcGeneralCopper(i) > 0) != 1)',
     '                ++bad;',
     '        // the clamps: past either edge reads the edge',
     '        // row (row -5 the belt, 3 silver 0 copper;',
     '        // row 99 the wagon 150 gold; list -5 the',
     '        // clothing 11; list 99 the transport 10)',
     '        if (rules::eqcGeneralSilver(-5) != 3 ||',
     '            rules::eqcGeneralGold(99) != 150 ||',
     '            rules::eqcGeneralCopper(-5) != 0 ||',
     '            rules::eqcGeneralFirst(-5) != 0 ||',
     '            rules::eqcGeneralFirst(99) != 89 ||',
     '            rules::eqcGeneralListCount(-5) != 11 ||',
     '            rules::eqcGeneralListCount(99) != 10) ++bad;',
     '        // the herbs cells (the reference sheet',
     '        // resolves the scrambled equipment copy)',
     '        if (rules::eqcGeneralSilver(11) != 4 ||',
     '            rules::eqcGeneralCopper(12) != 5 ||',
     '            rules::eqcGeneralSilver(13) != 10) ++bad;',
     '        // the worked rows: the heavy war horse 300,',
     '        // the medium 225, the plate barding 500, the',
     '        // large galley 25000, the small 10000 and the',
     '        // warship 20000',
     '        if (rules::eqcGeneralGold(23) != 300 ||',
     '            rules::eqcGeneralGold(25) != 225 ||',
     '            rules::eqcGeneralGold(82) != 500 ||',
     '            rules::eqcGeneralGold(93) != 25000 ||',
     '            rules::eqcGeneralGold(94) != 10000 ||',
     '            rules::eqcGeneralGold(97) != 20000) ++bad;',
     '        // the monetary pins (the R300 silver one',
     '        // plus the R308 copper ones)',
     '        if (rules::eqcSilverPerGold() != 20 ||',
     '            rules::eqcCopperPerSilver() != 10 ||',
     '            rules::eqcCopperPerGold() != 200) ++bad;',
     '        printf("R308 general equipment lists audit: bad %d'
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
if 'R308 general equipment lists audit' in s:
    already.append('regtest.cpp: the audit block')
else:
    assert s.count('audit: bad') == 231, 'rt census not 231'
    assert s.count(RT_OLD) == 1, 'rt anchor not unique'
    assert 'eqcGeneral' not in s, 'rt marker collision'
    s = s.replace(RT_OLD, RT_NEW)
    wr(p, s)
    applied.append('regtest.cpp: the audit block')

s = rd(p)
assert s.count('audit: bad') == 232, 'patch b census wrong'
assert s.count('R308 general equipment lists audit') == 1, 'b label'
assert s.count('R306 thief functions engine audit') == 1, 'b r306 tail'
assert s.count('R227: the wis mental save wiring audit') == 1, 'b head'
assert s.count('{') == s.count('}'), 'rt brace balance'
assert s.count('(') == s.count(')'), 'rt paren balance'
assert len(applied) + len(already) == 4, 'patch b count wrong'

# ---- (c) tools/phb_gap_report.md: the box flip ----
PHB_C_OLD = NL.join([
    '- [ ] **The general equipment cost',
    '      lists (Clothing, Herbs,',
    '      Livestock, Provisions and',
    '      Transport; upload lines 2344-2430',
    '      with the reference-sheet repeats',
    '      at 13473-13535) - OPENED R307:**',
    '      the R300 cost columns pinned the',
    '      52 arms and the 14 armor rows',
    '      only. The five general lists stay',
    '      unpinned (the clothing and',
    '      footwear prices, the herb costs,',
    '      livestock, the provisions and the',
    '      transport costs - mounts, tack',
    '      and vehicles). A data candidate:',
    '      rules/equipcosts.h grows the rows',
    '      (the R300 pattern; the',
    '      reference-sheet copies resolve any',
    '      ambiguous cell). The judgment',
    '      waits for the pin round.',
])
PHB_C_NEW = NL.join([
    '- [x] **The general equipment cost',
    '      lists (Clothing, Herbs,',
    '      Livestock, Miscellaneous',
    '      Equipment and Items,',
    '      Provisions, Religious Items,',
    '      Tack and Harness and',
    '      Transport; upload lines 2344-2437',
    '      with the reference-sheet repeats',
    '      at 13473-13541) - PINNED R308:**',
    '      rules/equipcosts.h grows the',
    '      general section: 99 rows across',
    '      the EIGHT printed lists (11, 3,',
    '      21, 29, 10, 6, 9 and 10), every',
    '      price in its printed coin (11',
    '      copper, 29 silver, 59 gold -',
    '      exactly one coin column nonzero',
    '      per row). The reference sheet is',
    '      the complete legible copy: it',
    '      resolves the scrambled herbs',
    '      cells (belladonna 4 s.p., garlic',
    '      bud 5 c.p., wolvesbane 10 s.p.)',
    '      and the eight transport cells',
    '      the equipment-section OCR drops;',
    '      the copies agree on every shared',
    '      cell. The monetary pins join the',
    '      R300 silver one (10 c.p. = 1',
    '      s.p., 200 c.p. = 1 g.p.). The',
    '      row order and the name',
    '      normalizations ride the R300',
    '      conventions (the foot marks',
    '      spelled out; the ampersands read',
    '      as and). No engine site charges',
    '      them yet (the town stores price',
    '      canonically); the R308 battery',
    '      audit walks every cell, the list',
    '      boundaries, the clamps, the coin',
    '      identity and the monetary pins.',
    '      Census 232. The ledger holds',
    '      ZERO open items.',
])
clean(PHB_C_OLD, 57, gap=True)
clean(PHB_C_NEW, 57, gap=True)

p = 'tools/phb_gap_report.md'
s = rd(p)
if 'PINNED R308' in s:
    already.append('phb report: the box flip')
else:
    assert s.count(PHB_C_OLD) == 1, 'phb anchor not unique'
    assert s.count('- [ ]') == 1, 'phb open count not 1'
    s = s.replace(PHB_C_OLD, PHB_C_NEW)
    wr(p, s)
    applied.append('phb report: the box flip')

s = rd(p)
assert s.count('- [ ]') == 0, 'patch c open residue'
assert s.count('PINNED R308') == 1, 'patch c pinned tag'
assert s.count('OPENED R307') == 0, 'patch c opened residue'
assert s.count('Census 232') == 1, 'patch c census note'
assert s.count('## Open items (the R307 addition)') == 1, 'c open head'
assert s.count('## Out of engine scope (the R296') == 1, 'c r296 head'
assert s.count('## R307 the fresh gap pass') == 1, 'c pass head intact'
assert len(applied) + len(already) == 5, 'patch c count wrong'

# ---- R308 fails/tail ----
if fails:
    print('R308 splice: FAIL - ' + str(len(fails))
          + ' patch(es) failed:')
    for f in fails:
        print('  ' + f)
    sys.exit(1)
if len(applied) + len(already) != 5:
    print('R308 splice: FAIL - expected 5 patches, counted '
          + str(len(applied) + len(already))
          + ' (a truncated paste?)')
    sys.exit(1)
print('R308 splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R308 note: 5 patches; the general')
print('lists pinned - the battery census')
print('moves 231 -> 232; the phb ledger')
print('holds ZERO open items again')
print('commit: R308: the general equipment lists')
print('pinned (census 232)')

