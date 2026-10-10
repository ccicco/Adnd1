#!/usr/bin/env python3
# tools/r310_splice.py - R310: the sage
# subsection pinned (the LAST R307 DMG open
# item paid - the dmg ledger clears).
#
# The pin (rules/sage.h, the grenade.h
# pattern): the fields-count table - 6 dice
# bands; the SAGE FIELDS OF STUDY - 7 fields
# carrying 68 special knowledge categories
# (the OCR column interleave resolved per the
# compilation cross-read: Chemistry restored
# to the physical universes, Trees restored
# to flora); the CHANCE OF KNOWING table - 4
# scopes by 3 natures, the none cell pinned
# -1, the scrambled 57-60 major specific
# cell recovered; the sage characteristics
# (the ability dice rows, the nine alignment
# bands, 8d4 hit points, the spell limits
# and kinds); the offer table (200 to 1,200
# g.p. twice, the 20,000 g.p. minimum); the
# efficiency milestones with the improvement
# ladder; the INFORMATION DISCOVERY TIME AND
# COST table (the lone hours cell, the
# free-spread thresholds, the 51-100 unknown
# band at half cost).
#
#   (a) rules/sage.h - CREATED.
#   (b) regtest.cpp - the include line.
#   (c) regtest.cpp - the R310 battery audit
#       (the battery census 233 -> 234): every
#       table walked cell for cell, the band
#       tiling, the none identities and the
#       clamps.
#   (d) tools/dmg_gap_report.md - the
#       chronicle paragraph.
#   (e) tools/dmg_gap_report.md - the LAST
#       open box flipped to the PINNED form
#       (the ledger holds ZERO open items).
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
# Commit: "R310: the sage subsection pinned
# (census 234)"
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
# fields: (name, percent lo, percent hi,
# the special knowledge categories)
FIELDS = [
    ('Humankind', 1, 30, [
        'Art & Music', 'Biology', 'Demography', 'History',
        'Languages', 'Legends & Folklore', 'Law & Customs',
        'Philosophy & Ethics', 'Politics & Genealogy',
        'Psychology', 'Sociology', 'Theology & Myth']),
    ('Demi-Humankind', 31, 50, [
        'Art & Music', 'Biology', 'Demography', 'Languages',
        'Legends & Folklore', 'Law & Customs',
        'Philosophy & Ethics', 'Politics & Genealogy',
        'Psychology', 'Sociology', 'Theology & Myth']),
    ('Humanoids & Giantkind', 51, 60, [
        'Biology', 'Demography', 'History', 'Languages',
        'Legends & Folklore', 'Law & Customs', 'Sociology',
        'Theology & Myth']),
    ('Physical Universe(s)', 61, 70, [
        'Architecture & Engineering', 'Astronomy',
        'Chemistry', 'Geography', 'Geology & Mineralogy',
        'Mathematics', 'Meteorology & Climatology',
        'Oceanography', 'Physics',
        'Topography & Cartography']),
    ('Fauna', 71, 80, [
        'Amphibians', 'Arachnids', 'Avians',
        'Cephalopods & Echinoderms',
        'Crustaceans & Mollusks', 'Ichthyoids',
        'Insects', 'Mammals', 'Marsupials', 'Reptiles']),
    ('Flora', 81, 90, [
        'Bushes & Shrubs', 'Flowers', 'Fungi',
        'Grasses & Grains', 'Herbs', 'Mosses & Ferns',
        'Trees', 'Weeds']),
    ('Supernatural & Unusual', 91, 100, [
        'Astrology & Numerology', 'Cryptography',
        'Divination', 'Dweomercraeft',
        'Heraldry, Signs & Sigils', 'Medicine',
        'Metaphysics', 'Planes (Astral, Elemental & Ethereal)',
        'Planes (Outer)']),
]
# the fields-count table: (dice lo, dice hi,
# minor fields, special categories in the
# major field)
BANDS = [
    (1, 10, 1, 2),
    (11, 30, 1, 3),
    (31, 50, 1, 4),
    (51, 70, 2, 2),
    (71, 90, 2, 3),
    (91, 100, 2, 4),
]
# the chance-of-knowing percent bands:
# [scope][nature]; scope 0 out of fields,
# 1 minor field, 2 major field, 3 special
# category; nature 0 general, 1 specific,
# 2 exacting; -1 pins the none cell (the
# print dash)
KNOW_LO = [
    [31, 11, -1],
    [46, 31, 11],
    [61, 57, 26],
    [81, 76, 61],
]
KNOW_HI = [
    [50, 20, -1],
    [65, 40, 20],
    [80, 60, 35],
    [100, 96, 80],
]
# the ability dice rows: (name, die, count,
# plus) in STR INT WIS DEX CON CHA order
ABIL = [
    ('STR', 8, 1, 7),
    ('INT', 4, 1, 14),
    ('WIS', 6, 1, 12),
    ('DEX', 6, 3, 0),
    ('CON', 6, 2, 3),
    ('CHA', 6, 2, 2),
]
# the alignment bands: (lo, hi, name) in the
# ascending dice order
ALIGN = [
    (1, 5, 'chaotic evil'),
    (6, 10, 'chaotic good'),
    (11, 20, 'chaotic neutral'),
    (21, 30, 'lawful evil'),
    (31, 40, 'lawful good'),
    (41, 60, 'lawful neutral'),
    (61, 80, 'neutral'),
    (81, 90, 'neutral evil'),
    (91, 100, 'neutral good'),
]
# the field spell kinds: 0 clerical,
# 1 druidical, 2 magic-user or illusionist
SPELL_KIND = [0, 0, 0, 0, 1, 1, 2]
# the offer table: (lo, hi) per month
OFFER = [
    (200, 1200),
    (200, 1200),
    (20000, 20000),
]
# the efficiency milestones
EFF_COST = [20000, 60000, 100000]
EFF_PCT = [50, 90, 100]
# the improvement ladder: (cost, months,
# the max; -1 = no stated maximum)
IMPROVE = [
    (5000, 1, 5),
    (10000, 1, 5),
    (100000, 24, 3),
    (200000, 24, -1),
]
# the discovery time bands: [scope][nature];
# unit 0 rounds, 1 hours, 2 days; -1 pins the
# none cell
TIME_LO = [
    [1, 2, -1],
    [1, 2, 5],
    [1, 1, 3],
    [1, 1, 2],
]
TIME_HI = [
    [6, 24, -1],
    [4, 20, 40],
    [3, 12, 30],
    [2, 10, 12],
]
TIME_UNIT = [
    [0, 2, 0],
    [0, 2, 2],
    [0, 2, 2],
    [0, 1, 2],
]
# the g.p. cost per day by scope; the
# free-cost spread thresholds
COST_DAY = [100, 1000, 500, 200]
FREE = [20, 20, 20, 80]

def _sanity():
    assert len(FIELDS) == 7, 'field count'
    assert [f[0] for f in FIELDS] == [
        'Humankind', 'Demi-Humankind',
        'Humanoids & Giantkind', 'Physical Universe(s)',
        'Fauna', 'Flora', 'Supernatural & Unusual']
    assert [f[1] for f in FIELDS] == [
        1, 31, 51, 61, 71, 81, 91], 'field lo'
    assert [f[2] for f in FIELDS] == [
        30, 50, 60, 70, 80, 90, 100], 'field hi'
    assert [len(f[3]) for f in FIELDS] == [
        12, 11, 8, 10, 10, 8, 9], 'field cat counts'
    for _f in FIELDS:
        assert len(set(_f[3])) == len(_f[3]), 'dup cat in field'
    assert sum(len(f[3]) for f in FIELDS) == 68, 'cat total'
    _bl = [b[0] for b in BANDS]
    _bh = [b[1] for b in BANDS]
    assert _bl[0] == 1 and _bh[5] == 100, 'band ends'
    for _k in range(5):
        assert _bh[_k] + 1 == _bl[_k + 1], 'band gap'
    assert [b[2] for b in BANDS] == [1, 1, 1, 2, 2, 2], 'band minor'
    assert [b[3] for b in BANDS] == [2, 3, 4, 2, 3, 4], 'band special'
    for _s in range(4):
        assert len(KNOW_LO[_s]) == 3 and len(KNOW_HI[_s]) == 3
        for _n in range(3):
            if KNOW_LO[_s][_n] < 0:
                assert KNOW_HI[_s][_n] < 0, 'know none pair'
            else:
                assert 1 <= KNOW_LO[_s][_n] < KNOW_HI[_s][_n] <= 100
    _kn = sum(1 for _s in range(4) for _n in range(3)
              if KNOW_LO[_s][_n] < 0)
    assert _kn == 1, 'know none count'
    assert [a[0] for a in ABIL] == [
        'STR', 'INT', 'WIS', 'DEX', 'CON', 'CHA']
    for _a in ABIL:
        _lo = _a[3] + _a[2]
        _hi = _a[3] + _a[2] * _a[1]
        assert 3 <= _lo <= 18, 'ability lo range'
        assert 3 <= _hi <= 18, 'ability hi range'
    assert len(ALIGN) == 9, 'align count'
    assert ALIGN[0][0] == 1 and ALIGN[8][1] == 100, 'align ends'
    for _k in range(8):
        assert ALIGN[_k][1] + 1 == ALIGN[_k + 1][0], 'align gap'
    assert len(set(a[2] for a in ALIGN)) == 9, 'align dups'
    assert SPELL_KIND == [0, 0, 0, 0, 1, 1, 2], 'spell kinds'
    assert OFFER[0] == (200, 1200), 'offer salary'
    assert OFFER[1] == (200, 1200), 'offer grants'
    assert OFFER[2] == (20000, 20000), 'offer materials'
    assert EFF_COST == [20000, 60000, 100000], 'eff cost'
    assert EFF_PCT == [50, 90, 100], 'eff pct'
    assert IMPROVE[0] == (5000, 1, 5), 'improve out'
    assert IMPROVE[1] == (10000, 1, 5), 'improve minor'
    assert IMPROVE[2] == (100000, 24, 3), 'improve minor field'
    assert IMPROVE[3] == (200000, 24, -1), 'improve major field'
    _tn = 0
    for _s in range(4):
        for _n in range(3):
            if TIME_LO[_s][_n] < 0:
                _tn += 1
                assert TIME_HI[_s][_n] < 0, 'time none pair'
                assert TIME_UNIT[_s][_n] == 0, 'time none unit'
            else:
                assert TIME_LO[_s][_n] <= TIME_HI[_s][_n], 'time band'
                assert TIME_UNIT[_s][_n] in (0, 1, 2), 'time unit'
    assert _tn == 1, 'time none count'
    assert sum(1 for _r in TIME_UNIT for _v in _r if _v == 1) == 1
    assert COST_DAY == [100, 1000, 500, 200], 'cost day'
    assert FREE == [20, 20, 20, 80], 'free spread'
_sanity()

# derived from the fields (the single source)
FNAMES = [f[0] for f in FIELDS]
FLO = [f[1] for f in FIELDS]
FHI = [f[2] for f in FIELDS]
FCOUNT = [len(f[3]) for f in FIELDS]
CATS = [c for _fn, _fl, _fh, _cs in FIELDS for c in _cs]
CATFIELD = []
for _fi, _f in enumerate(FIELDS):
    CATFIELD += [_fi] * len(_f[3])
FFIRST = []
_run = 0
for _c in FCOUNT:
    FFIRST.append(_run)
    _run += _c
BAND_LO = [b[0] for b in BANDS]
BAND_HI = [b[1] for b in BANDS]
BAND_MINOR = [b[2] for b in BANDS]
BAND_SPECIAL = [b[3] for b in BANDS]
ABIL_DICE = [a[1] for a in ABIL]
ABIL_CNT = [a[2] for a in ABIL]
ABIL_PLUS = [a[3] for a in ABIL]
ALIGN_LO = [a[0] for a in ALIGN]
ALIGN_HI = [a[1] for a in ALIGN]
ALIGN_NAMES = [a[2] for a in ALIGN]
OFFER_LO = [o[0] for o in OFFER]
OFFER_HI = [o[1] for o in OFFER]
IMP_COST = [i[0] for i in IMPROVE]
IMP_MONTHS = [i[1] for i in IMPROVE]
IMP_MAX = [i[2] for i in IMPROVE]

def arrlines(vals, indent, per=10):
    out = []
    i = 0
    while i < len(vals):
        chunk = vals[i:i + per]
        out.append(indent + ', '.join('%4d' % v for v in chunk) + ',')
        i += per
    return out

def arr2d(rows, indent):
    out = []
    for r in rows:
        out.append(indent + '{' + ', '.join('%4d' % v for v in r)
                   + '},')
    return out

def namelines(names, indent):
    out = []
    for n in names:
        out.append(indent + DQ + n + DQ + ',')
    return out

def _accs(text):
    # the accessor names, extracted from the text
    # itself (the R309 lesson: never count from
    # the design sketch)
    out = []
    for _ln in text.split(NL):
        _n = None
        if _ln.startswith('inline int sage') and _ln.endswith(' {'):
            _n = _ln[len('inline int '):_ln.rindex('(')]
        if _ln.startswith('inline const char* sage') and _ln.endswith(' {'):
            _n = _ln[len('inline const char* '):_ln.rindex('(')]
        if _n is not None:
            out.append(_n)
    return out

def _calls_in(text):
    out = set()
    _rest = text
    while True:
        _i = _rest.find('rules::')
        if _i < 0:
            break
        _rest = _rest[_i + 7:]
        _j = _rest.find('(')
        if _j < 0:
            break
        out.add(_rest[:_j])
    return out

# ---- (a) rules/sage.h CREATED ----
SB = NL.join(
    ['// ===========================================================================',
     '// Adnd1 - rules/sage.h',
     '// The sage subsection (R310).',
     '//',
     '// The DMG SAGE subsection (upload line 2110):',
     '// the fields-count table, the SAGE FIELDS OF',
     '// STUDY AND SPECIAL KNOWLEDGE CATEGORIES, the',
     '// CHANCE OF KNOWING ANSWER TO A QUESTION table,',
     '// the sage characteristics (the six ability dice',
     '// rows, the nine alignment bands, the 8d4 hit',
     '// points, the spell limits), the SUPPORT and',
     '// SALARY offer table, the efficiency economics',
     '// with the improvement ladder, and the INFORMATION',
     '// DISCOVERY TIME AND COST TABLE.',
     '//',
     '// The fields-count table: 6 dice bands (the minor',
     '// fields and the special categories in the major',
     '// field). The fields: 7 percent bands carrying 68',
     '// special knowledge categories (humankind 12,',
     '// demi-humankind 11, humanoids and giantkind 8,',
     '// the physical universes 10, fauna 10, flora 8,',
     '// supernatural and unusual 9).',
     '//',
     '// SOURCE NOTE: the 1eonline.info compilation',
     '// cross-read agrees on every cell. The upload OCR',
     '// flattened the seven-column print: HISTORY',
     '// HISTORY reads History; HISTORY CHEMISTRY splits',
     '// History (humanoids) and restores CHEMISTRY to',
     '// the physical universes; INSECTS TREES splits',
     '// Insects (fauna) and restores TREES to flora - a',
     '// third transcription confirms both recoveries.',
     '// The chance-of-knowing print row for the major',
     '// field interleaves three bands (61-80, 57-60,',
     '// 26-35); the compilation resolves the order.',
     '//',
     '// The none cells pin -1 (the print dash): the',
     '// out-of-fields exacting chance and the',
     '// out-of-fields exacting time - an exacting',
     '// question outside the fields cannot be answered',
     '// at all. The special-category specific time band',
     '// is the only HOURS cell (1-10 h.); every general',
     '// band is rounds.',
     '//',
     '// The recorded notes ride the pin: the hiring',
     '// restriction (only fighters, paladins, rangers,',
     '// thieves and assassins hire permanently; any',
     '// class may consult short-term - 100 g.p. per day',
     '// plus the question difficulty, one week maximum,',
     '// a one-game-month cooldown after; permanent',
     '// offers are lifetime service only, the sage',
     '// bringing nothing save thinking ability and',
     '// knowledge), the location prose (large towns and',
     '// cities only, near colleges, schools and',
     '// libraries), the spell casting level (the minimum',
     '// class level for the spell; a sage with',
     '// third-level magic-user use casts at 5th), the',
     '// excluded spells (bless, chant, prayer, commune,',
     '// raise dead, commune with nature, contact other',
     '// plane and their reverses), the remote doubler',
     '// (no nearby town doubles times and costs), the',
     '// rest rule (1 day per 3 research days, 1-2 extra',
     '// if bothered) and the unknown-information terms',
     '// (51-100 percent of the maximum time at half',
     '// cost). No engine site charges any of this yet',
     '// (no sage consultation layer exists; the town',
     '// stores price canonically).',
     '//',
     '// DATA-DRIVEN (the standing scope).',
     '// ===========================================================================',
     '',
     '#pragma once',
     '',
     'namespace rules {',
     '',
     '// ---- the fields of study ----',
     '',
     '// The field count (the print: 7 fields).',
     'inline int sageFieldCount() {',
     '    return 7;',
     '}',
     '',
     '// The field name at index f (clamped).',
     'inline const char* sageFieldName(int f) {',
     '    static const char* const kNames[7] = {',
     ] + namelines(FNAMES, '        ') + [
     '    };',
     '    if (f < 0) f = 0;',
     '    if (f > 6) f = 6;',
     '    return kNames[f];',
     '}',
     '',
     '// The field percent band low (clamped; the',
     '// seven bands tile 1-100).',
     'inline int sageFieldLo(int f) {',
     '    static const int kLo[7] = {',
     ] + arrlines(FLO, '        ') + [
     '    };',
     '    if (f < 0) f = 0;',
     '    if (f > 6) f = 6;',
     '    return kLo[f];',
     '}',
     '',
     '// The field percent band high (clamped).',
     'inline int sageFieldHi(int f) {',
     '    static const int kHi[7] = {',
     ] + arrlines(FHI, '        ') + [
     '    };',
     '    if (f < 0) f = 0;',
     '    if (f > 6) f = 6;',
     '    return kHi[f];',
     '}',
     '',
     '// The special knowledge categories in the',
     '// field (clamped).',
     'inline int sageFieldCategoryCount(int f) {',
     '    static const int kCount[7] = {',
     ] + arrlines(FCOUNT, '        ') + [
     '    };',
     '    if (f < 0) f = 0;',
     '    if (f > 6) f = 6;',
     '    return kCount[f];',
     '}',
     '',
     '// The flat index of the first category in the',
     '// field (clamped); the categories run field by',
     '// field in the print order.',
     'inline int sageFieldCategoryFirst(int f) {',
     '    static const int kFirst[7] = {',
     ] + arrlines(FFIRST, '        ') + [
     '    };',
     '    if (f < 0) f = 0;',
     '    if (f > 6) f = 6;',
     '    return kFirst[f];',
     '}',
     '',
     '// ---- the special knowledge categories ----',
     '',
     '// The category count (the print: 68 categories',
     '// across the seven fields).',
     'inline int sageCategoryCount() {',
     '    return 68;',
     '}',
     '',
     '// The category name at flat index i (clamped).',
     'inline const char* sageCategoryName(int i) {',
     '    static const char* const kNames[68] = {',
     ] + namelines(CATS, '        ') + [
     '    };',
     '    if (i < 0) i = 0;',
     '    if (i > 67) i = 67;',
     '    return kNames[i];',
     '}',
     '',
     '// The owning field of the category at flat',
     '// index i (clamped).',
     'inline int sageCategoryField(int i) {',
     '    static const int kField[68] = {',
     ] + arrlines(CATFIELD, '        ') + [
     '    };',
     '    if (i < 0) i = 0;',
     '    if (i > 67) i = 67;',
     '    return kField[i];',
     '}',
     '',
     '// ---- the fields-count table ----',
     '',
     '// The dice band count.',
     'inline int sageFieldsBandCount() {',
     '    return 6;',
     '}',
     '',
     '// The dice band low (clamped; the six bands',
     '// tile 1-100).',
     'inline int sageFieldsBandLo(int b) {',
     '    static const int kLo[6] = {',
     ] + arrlines(BAND_LO, '        ') + [
     '    };',
     '    if (b < 0) b = 0;',
     '    if (b > 5) b = 5;',
     '    return kLo[b];',
     '}',
     '',
     '// The dice band high (clamped).',
     'inline int sageFieldsBandHi(int b) {',
     '    static const int kHi[6] = {',
     ] + arrlines(BAND_HI, '        ') + [
     '    };',
     '    if (b < 0) b = 0;',
     '    if (b > 5) b = 5;',
     '    return kHi[b];',
     '}',
     '',
     '// The minor fields in the band (clamped).',
     'inline int sageFieldsBandMinor(int b) {',
     '    static const int kMinor[6] = {',
     ] + arrlines(BAND_MINOR, '        ') + [
     '    };',
     '    if (b < 0) b = 0;',
     '    if (b > 5) b = 5;',
     '    return kMinor[b];',
     '}',
     '',
     '// The special categories in the major field',
     '// (clamped).',
     'inline int sageFieldsBandSpecial(int b) {',
     '    static const int kSpecial[6] = {',
     ] + arrlines(BAND_SPECIAL, '        ') + [
     '    };',
     '    if (b < 0) b = 0;',
     '    if (b > 5) b = 5;',
     '    return kSpecial[b];',
     '}',
     '',
     '// ---- the chance of knowing an answer ----',
     '',
     '// The knowing percent band low (both clamped).',
     '// Scope: 0 out of fields, 1 minor field, 2 major',
     '// field, 3 special category. Nature: 0 general,',
     '// 1 specific, 2 exacting. -1 pins the none cell',
     '// (the print dash - an exacting question out of',
     '// the fields cannot be answered at all).',
     'inline int sageKnowLo(int scope, int nature) {',
     '    static const int kLo[4][3] = {',
     ] + arr2d(KNOW_LO, '        ') + [
     '    };',
     '    if (scope < 0) scope = 0;',
     '    if (scope > 3) scope = 3;',
     '    if (nature < 0) nature = 0;',
     '    if (nature > 2) nature = 2;',
     '    return kLo[scope][nature];',
     '}',
     '',
     '// The knowing percent band high (both clamped).',
     'inline int sageKnowHi(int scope, int nature) {',
     '    static const int kHi[4][3] = {',
     ] + arr2d(KNOW_HI, '        ') + [
     '    };',
     '    if (scope < 0) scope = 0;',
     '    if (scope > 3) scope = 3;',
     '    if (nature < 0) nature = 0;',
     '    if (nature > 2) nature = 2;',
     '    return kHi[scope][nature];',
     '}',
     '',
     '// The none flag: 1 when the cell prints a dash.',
     'inline int sageKnowNone(int scope, int nature) {',
     '    return sageKnowLo(scope, nature) < 0;',
     '}',
     '',
     '// ---- the sage characteristics ----',
     '',
     '// The ability row count (0 STR, 1 INT, 2 WIS,',
     '// 3 DEX, 4 CON, 5 CHA).',
     'inline int sageAbilityCount() {',
     '    return 6;',
     '}',
     '',
     '// The ability die (clamped).',
     'inline int sageAbilityDice(int a) {',
     '    static const int kDice[6] = {',
     ] + arrlines(ABIL_DICE, '        ') + [
     '    };',
     '    if (a < 0) a = 0;',
     '    if (a > 5) a = 5;',
     '    return kDice[a];',
     '}',
     '',
     '// The ability dice count (clamped).',
     'inline int sageAbilityDiceCount(int a) {',
     '    static const int kCount[6] = {',
     ] + arrlines(ABIL_CNT, '        ') + [
     '    };',
     '    if (a < 0) a = 0;',
     '    if (a > 5) a = 5;',
     '    return kCount[a];',
     '}',
     '',
     '// The ability plus (clamped); the score bands',
     '// run plus + count to plus + count * dice.',
     'inline int sageAbilityPlus(int a) {',
     '    static const int kPlus[6] = {',
     ] + arrlines(ABIL_PLUS, '        ') + [
     '    };',
     '    if (a < 0) a = 0;',
     '    if (a > 5) a = 5;',
     '    return kPlus[a];',
     '}',
     '',
     '// The alignment band count (ascending dice',
     '// order; the nine bands tile 1-100).',
     'inline int sageAlignBandCount() {',
     '    return 9;',
     '}',
     '',
     '// The alignment band low (clamped).',
     'inline int sageAlignLo(int b) {',
     '    static const int kLo[9] = {',
     ] + arrlines(ALIGN_LO, '        ') + [
     '    };',
     '    if (b < 0) b = 0;',
     '    if (b > 8) b = 8;',
     '    return kLo[b];',
     '}',
     '',
     '// The alignment band high (clamped).',
     'inline int sageAlignHi(int b) {',
     '    static const int kHi[9] = {',
     ] + arrlines(ALIGN_HI, '        ') + [
     '    };',
     '    if (b < 0) b = 0;',
     '    if (b > 8) b = 8;',
     '    return kHi[b];',
     '}',
     '',
     '// The alignment band name (clamped).',
     'inline const char* sageAlignName(int b) {',
     '    static const char* const kNames[9] = {',
     ] + namelines(ALIGN_NAMES, '        ') + [
     '    };',
     '    if (b < 0) b = 0;',
     '    if (b > 8) b = 8;',
     '    return kNames[b];',
     '}',
     '',
     '// The hit points: 8d4 plus the constitution',
     '// bonus as applicable.',
     'inline int sageHpDiceCount() {',
     '    return 8;',
     '}',
     '',
     'inline int sageHpDie() {',
     '    return 4;',
     '}',
     '',
     '// ---- the spell skills ----',
     '',
     '// The spell kind count.',
     'inline int sageSpellKindCount() {',
     '    return 3;',
     '}',
     '',
     '// The field spell kind (clamped): 0 clerical,',
     '// 1 druidical, 2 magic-user or illusionist (the',
     '// art and music and legends and folklore',
     '// categories read clerical or magic-user).',
     'inline int sageSpellKind(int f) {',
     '    static const int kKind[7] = {',
     ] + arrlines(SPELL_KIND, '        ') + [
     '    };',
     '    if (f < 0) f = 0;',
     '    if (f > 6) f = 6;',
     '    return kKind[f];',
     '}',
     '',
     '// The maximum spell level: d4 + 2, the 3-6',
     '// band inclusive.',
     'inline int sageSpellMaxDie() {',
     '    return 4;',
     '}',
     '',
     'inline int sageSpellMaxPlus() {',
     '    return 2;',
     '}',
     '',
     'inline int sageSpellMaxLo() {',
     '    return 3;',
     '}',
     '',
     'inline int sageSpellMaxHi() {',
     '    return 6;',
     '}',
     '',
     '// The spells held per level and the ready cap',
     '// (1-4 per level, no more than 1 of each level',
     '// available for use at a time).',
     'inline int sageSpellPerLevelLo() {',
     '    return 1;',
     '}',
     '',
     'inline int sageSpellPerLevelHi() {',
     '    return 4;',
     '}',
     '',
     'inline int sageSpellReadyPerLevel() {',
     '    return 1;',
     '}',
     '',
     '// ---- the employment offer ----',
     '',
     '// The offer row count: row 0 the support and',
     '// salary per month (2d6 hundred g.p.), row 1 the',
     '// research grants per month (2d6 hundred g.p.),',
     '// row 2 the initial material expenditure (the',
     '// 20,000 g.p. minimum; lo equals hi).',
     'inline int sageOfferCount() {',
     '    return 3;',
     '}',
     '',
     '// The offer row low (clamped; g.p. per month).',
     'inline int sageOfferLo(int i) {',
     '    static const int kLo[3] = {',
     ] + arrlines(OFFER_LO, '        ') + [
     '    };',
     '    if (i < 0) i = 0;',
     '    if (i > 2) i = 2;',
     '    return kLo[i];',
     '}',
     '',
     '// The offer row high (clamped; g.p. per month).',
     'inline int sageOfferHi(int i) {',
     '    static const int kHi[3] = {',
     ] + arrlines(OFFER_HI, '        ') + [
     '    };',
     '    if (i < 0) i = 0;',
     '    if (i > 2) i = 2;',
     '    return kHi[i];',
     '}',
     '',
     '// ---- the efficiency economics ----',
     '',
     '// The efficiency milestone count.',
     'inline int sageEffMilestoneCount() {',
     '    return 3;',
     '}',
     '',
     '// The milestone cost (clamped): 20,000 g.p.',
     '// buys 50 percent, 60,000 reaches 90 and',
     '// 100,000 the full 100 (the specific and',
     '// exacting areas).',
     'inline int sageEffMilestoneCost(int i) {',
     '    static const int kCost[3] = {',
     ] + arrlines(EFF_COST, '        ') + [
     '    };',
     '    if (i < 0) i = 0;',
     '    if (i > 2) i = 2;',
     '    return kCost[i];',
     '}',
     '',
     '// The milestone efficiency percent (clamped).',
     'inline int sageEffMilestonePercent(int i) {',
     '    static const int kPct[3] = {',
     ] + arrlines(EFF_PCT, '        ') + [
     '    };',
     '    if (i < 0) i = 0;',
     '    if (i > 2) i = 2;',
     '    return kPct[i];',
     '}',
     '',
     '// The +1 percent step cost to 90 percent.',
     'inline int sageEffStepCost() {',
     '    return 1000;',
     '}',
     '',
     '// The +1 percent step cost after 90.',
     'inline int sageEffHighCostPerPercent() {',
     '    return 4000;',
     '}',
     '',
     '// ---- the improvement ladder ----',
     '',
     '// The improvement row count: row 0 the',
     '// out-of-fields knowledge +1 percent (5,000',
     '// g.p. and a month, max +5), row 1 the',
     '// minor-field ability +1 percent (10,000 g.p.',
     '// and a month, max +5), row 2 an extra minor',
     '// field (100,000 g.p. and two years, three',
     '// maximum), row 3 an extra major field',
     '// (200,000 g.p. and two years; -1 pins no',
     '// stated maximum).',
     'inline int sageImproveCount() {',
     '    return 4;',
     '}',
     '',
     '// The improvement cost in g.p. (clamped).',
     'inline int sageImproveCost(int i) {',
     '    static const int kCost[4] = {',
     ] + arrlines(IMP_COST, '        ') + [
     '    };',
     '    if (i < 0) i = 0;',
     '    if (i > 3) i = 3;',
     '    return kCost[i];',
     '}',
     '',
     '// The improvement time in months (clamped).',
     'inline int sageImproveMonths(int i) {',
     '    static const int kMonths[4] = {',
     ] + arrlines(IMP_MONTHS, '        ') + [
     '    };',
     '    if (i < 0) i = 0;',
     '    if (i > 3) i = 3;',
     '    return kMonths[i];',
     '}',
     '',
     '// The improvement maximum (clamped; -1 pins',
     '// no stated maximum).',
     'inline int sageImproveMax(int i) {',
     '    static const int kMax[4] = {',
     ] + arrlines(IMP_MAX, '        ') + [
     '    };',
     '    if (i < 0) i = 0;',
     '    if (i > 3) i = 3;',
     '    return kMax[i];',
     '}',
     '',
     '// ---- the information discovery table ----',
     '',
     '// The discovery time band low (both clamped).',
     '// Scope and nature read as the knowing table;',
     '// -1 pins the none cell (the print dash).',
     'inline int sageTimeLo(int scope, int nature) {',
     '    static const int kLo[4][3] = {',
     ] + arr2d(TIME_LO, '        ') + [
     '    };',
     '    if (scope < 0) scope = 0;',
     '    if (scope > 3) scope = 3;',
     '    if (nature < 0) nature = 0;',
     '    if (nature > 2) nature = 2;',
     '    return kLo[scope][nature];',
     '}',
     '',
     '// The discovery time band high (both clamped).',
     'inline int sageTimeHi(int scope, int nature) {',
     '    static const int kHi[4][3] = {',
     ] + arr2d(TIME_HI, '        ') + [
     '    };',
     '    if (scope < 0) scope = 0;',
     '    if (scope > 3) scope = 3;',
     '    if (nature < 0) nature = 0;',
     '    if (nature > 2) nature = 2;',
     '    return kHi[scope][nature];',
     '}',
     '',
     '// The discovery time unit (both clamped):',
     '// 0 rounds, 1 hours, 2 days (the lone HOURS',
     '// cell the special-category specific band).',
     'inline int sageTimeUnit(int scope, int nature) {',
     '    static const int kUnit[4][3] = {',
     ] + arr2d(TIME_UNIT, '        ') + [
     '    };',
     '    if (scope < 0) scope = 0;',
     '    if (scope > 3) scope = 3;',
     '    if (nature < 0) nature = 0;',
     '    if (nature > 2) nature = 2;',
     '    return kUnit[scope][nature];',
     '}',
     '',
     '// The none flag: 1 when the cell prints a dash.',
     'inline int sageTimeNone(int scope, int nature) {',
     '    return sageTimeLo(scope, nature) < 0;',
     '}',
     '',
     '// The g.p. cost per day for the scope (clamped).',
     'inline int sageCostPerDay(int scope) {',
     '    static const int kCost[4] = {',
     ] + arrlines(COST_DAY, '        ') + [
     '    };',
     '    if (scope < 0) scope = 0;',
     '    if (scope > 3) scope = 3;',
     '    return kCost[scope];',
     '}',
     '',
     '// The free-cost spread threshold (clamped):',
     '// a knowing roll in the lower 20 percent of',
     '// the spread means the materials are on hand;',
     '// the special category widens to the lower 80',
     '// percent.',
     'inline int sageFreeSpreadPercent(int scope) {',
     '    static const int kFree[4] = {',
     ] + arrlines(FREE, '        ') + [
     '    };',
     '    if (scope < 0) scope = 0;',
     '    if (scope > 3) scope = 3;',
     '    return kFree[scope];',
     '}',
     '',
     '// The unknown-information band: 51-100',
     '// percent of the maximum time.',
     'inline int sageUnknownPercentLo() {',
     '    return 51;',
     '}',
     '',
     'inline int sageUnknownPercentHi() {',
     '    return 100;',
     '}',
     '',
     '// The unknown-information cost divisor (the',
     '// costs accrue at half the stated amount).',
     'inline int sageUnknownCostDivisor() {',
     '    return 2;',
     '}',
     '',
     '// The short-term terms: 100 g.p. per day plus',
     '// the question difficulty, one week maximum,',
     '// a one-game-month cooldown after.',
     'inline int sageShortTermCostPerDay() {',
     '    return 100;',
     '}',
     '',
     'inline int sageShortTermMaxDays() {',
     '    return 7;',
     '}',
     '',
     'inline int sageShortTermCooldownMonths() {',
     '    return 1;',
     '}',
     '',
     '// The permanent offer is lifetime service only.',
     'inline int sagePermanentHireOnly() {',
     '    return 1;',
     '}',
     '',
     '}  // namespace rules',
     '',
     ])
clean(SB, 78)
assert Q not in SB, 'apostrophe in header'

p = 'rules/sage.h'
if os.path.exists(os.path.join(ROOT, p)):
    s = rd(p)
    if 'inline int sageFieldCount() {' in s:
        already.append('sage.h created')
    else:
        fails.append('sage.h exists without the R310 marker')
else:
    wr(p, SB)
    applied.append('sage.h created')

s = rd(p)
assert Q not in s, 'sb apostrophes'
assert s.count('namespace rules') == 2, 'sb namespace pair'
assert s.count('}  // namespace rules') == 1, 'sb namespace close'
assert s.count('{') == s.count('}'), 'sb brace balance'
assert s.count('(') == s.count(')'), 'sb paren balance'
_found = _accs(s)
assert len(_found) == 61, 'sb accessor count'
assert len(set(_found)) == 61, 'sb accessor dups'
assert s.count('inline int sage') == 58, 'sb int accessor count'
assert s.count('inline const char* sage') == 3, 'sb name accessor'
assert s.count('return 68;') == 1, 'sb cat count pin'
assert s.count('static const int kLo[4][3]') == 2, 'sb know/time lo'
assert s.count('static const int kHi[4][3]') == 2, 'sb know/time hi'
assert s.count('return sageKnowLo(scope, nature) < 0;') == 1
assert s.count('return sageTimeLo(scope, nature) < 0;') == 1
assert len(applied) + len(already) == 1, 'patch a count wrong'

# ---- (b) regtest.cpp: the include line ----
INC_OLD = NL.join([
    '#include "rules/hirelings.h"  // R309: the hirelings cost tables',
])
INC_NEW = NL.join([
    '#include "rules/hirelings.h"  // R309: the hirelings cost tables',
    '#include "rules/sage.h"  // R310: the sage subsection',
])
clean(INC_OLD, 76)
clean(INC_NEW, 76)

p = 'regtest.cpp'
s = rd(p)
if '#include "rules/sage.h"' in s:
    already.append('regtest.cpp: the include line')
else:
    assert s.count(INC_OLD) == 1, 'include anchor not unique'
    assert 'sage.h' not in s, 'include marker collision'
    s = s.replace(INC_OLD, INC_NEW)
    wr(p, s)
    applied.append('regtest.cpp: the include line')

s = rd(p)
assert s.count('#include "rules/sage.h"') == 1, 'patch b include'
assert s.count('#include "rules/hirelings.h"') == 1, 'patch b anchor'
assert len(applied) + len(already) == 2, 'patch b count wrong'

# ---- (c) regtest.cpp: the audit block ----
RT_TAIL = NL.join([
    '        printf("R309 hirelings cost tables audit: bad %d'
    + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
])
RT_AUD = NL.join(
    ['    // ---- R310: the sage subsection audit ----',
     '    // The DMG SAGE subsection (rules/sage.h)',
     '    // walked cell for cell against this local',
     '    // ground truth: the fields-count bands, the',
     '    // seven fields with their 68 special',
     '    // knowledge categories, the chance-of-knowing',
     '    // bands, the sage characteristics (the',
     '    // ability dice, the alignment bands, the',
     '    // spell limits), the offer table, the',
     '    // efficiency milestones, the improvement',
     '    // ladder and the information discovery time',
     '    // and cost table.',
     '    {',
     '        int bad = 0;',
     '        static const int kFieldLo[7] = {',
     ] + arrlines(FLO, '            ') + [
     '        };',
     '        static const int kFieldHi[7] = {',
     ] + arrlines(FHI, '            ') + [
     '        };',
     '        static const int kFieldCat[7] = {',
     ] + arrlines(FCOUNT, '            ') + [
     '        };',
     '        static const int kFieldFirst[7] = {',
     ] + arrlines(FFIRST, '            ') + [
     '        };',
     '        static const int kCatField[68] = {',
     ] + arrlines(CATFIELD, '            ') + [
     '        };',
     '        static const int kBandLo[6] = {',
     ] + arrlines(BAND_LO, '            ') + [
     '        };',
     '        static const int kBandHi[6] = {',
     ] + arrlines(BAND_HI, '            ') + [
     '        };',
     '        static const int kBandMinor[6] = {',
     ] + arrlines(BAND_MINOR, '            ') + [
     '        };',
     '        static const int kBandSpecial[6] = {',
     ] + arrlines(BAND_SPECIAL, '            ') + [
     '        };',
     '        static const int kKnowLo[4][3] = {',
     ] + arr2d(KNOW_LO, '            ') + [
     '        };',
     '        static const int kKnowHi[4][3] = {',
     ] + arr2d(KNOW_HI, '            ') + [
     '        };',
     '        static const int kDice[6] = {',
     ] + arrlines(ABIL_DICE, '            ') + [
     '        };',
     '        static const int kCnt[6] = {',
     ] + arrlines(ABIL_CNT, '            ') + [
     '        };',
     '        static const int kPlus[6] = {',
     ] + arrlines(ABIL_PLUS, '            ') + [
     '        };',
     '        static const int kAlignLo[9] = {',
     ] + arrlines(ALIGN_LO, '            ') + [
     '        };',
     '        static const int kAlignHi[9] = {',
     ] + arrlines(ALIGN_HI, '            ') + [
     '        };',
     '        static const int kSpellKind[7] = {',
     ] + arrlines(SPELL_KIND, '            ') + [
     '        };',
     '        static const int kOfferLo[3] = {',
     ] + arrlines(OFFER_LO, '            ') + [
     '        };',
     '        static const int kOfferHi[3] = {',
     ] + arrlines(OFFER_HI, '            ') + [
     '        };',
     '        static const int kEffCost[3] = {',
     ] + arrlines(EFF_COST, '            ') + [
     '        };',
     '        static const int kEffPct[3] = {',
     ] + arrlines(EFF_PCT, '            ') + [
     '        };',
     '        static const int kImproveCost[4] = {',
     ] + arrlines(IMP_COST, '            ') + [
     '        };',
     '        static const int kImproveMonths[4] = {',
     ] + arrlines(IMP_MONTHS, '            ') + [
     '        };',
     '        static const int kImproveMax[4] = {',
     ] + arrlines(IMP_MAX, '            ') + [
     '        };',
     '        static const int kTimeLo[4][3] = {',
     ] + arr2d(TIME_LO, '            ') + [
     '        };',
     '        static const int kTimeHi[4][3] = {',
     ] + arr2d(TIME_HI, '            ') + [
     '        };',
     '        static const int kTimeUnit[4][3] = {',
     ] + arr2d(TIME_UNIT, '            ') + [
     '        };',
     '        static const int kCostDay[4] = {',
     ] + arrlines(COST_DAY, '            ') + [
     '        };',
     '        static const int kFree[4] = {',
     ] + arrlines(FREE, '            ') + [
     '        };',
     '        // the fields of study',
     '        if (rules::sageFieldCount() != 7) ++bad;',
     '        for (int i = 0; i < 7; ++i)',
     '            if (rules::sageFieldLo(i) != kFieldLo[i] ||',
     '                rules::sageFieldHi(i) != kFieldHi[i] ||',
     '                rules::sageFieldCategoryCount(i) !=',
     '                    kFieldCat[i] ||',
     '                rules::sageFieldCategoryFirst(i) !=',
     '                    kFieldFirst[i]) ++bad;',
     '        // the field bands tile 1-100 without gaps',
     '        if (rules::sageFieldLo(0) != 1 ||',
     '            rules::sageFieldHi(6) != 100) ++bad;',
     '        for (int i = 0; i < 6; ++i)',
     '            if (rules::sageFieldHi(i) + 1 !=',
     '                rules::sageFieldLo(i + 1)) ++bad;',
     '        // the category block boundaries (first(0)',
     '        // is 0; first(6) + count(6) is 68)',
     '        if (rules::sageFieldCategoryFirst(0) != 0) ++bad;',
     '        for (int i = 0; i < 6; ++i)',
     '            if (rules::sageFieldCategoryFirst(i) +',
     '                rules::sageFieldCategoryCount(i) !=',
     '                rules::sageFieldCategoryFirst(i + 1)) ++bad;',
     '        if (rules::sageFieldCategoryFirst(6) +',
     '            rules::sageFieldCategoryCount(6) != 68) ++bad;',
     '        // the categories',
     '        if (rules::sageCategoryCount() != 68) ++bad;',
     '        for (int i = 0; i < 68; ++i)',
     '            if (rules::sageCategoryField(i) !=',
     '                kCatField[i]) ++bad;',
     '        // the category edges sit in their fields',
     '        for (int i = 0; i < 7; ++i)',
     '            if (rules::sageCategoryField(',
     '                    rules::sageFieldCategoryFirst(i)) != i ||',
     '                rules::sageCategoryField(',
     '                    rules::sageFieldCategoryFirst(i) +',
     '                    rules::sageFieldCategoryCount(i) -',
     '                    1) != i) ++bad;',
     '        // the field clamps (field -5 humankind,',
     '        // 99 supernatural and unusual)',
     '        if (rules::sageFieldLo(-5) != 1 ||',
     '            rules::sageFieldHi(-5) != 30 ||',
     '            rules::sageFieldLo(99) != 91 ||',
     '            rules::sageFieldHi(99) != 100 ||',
     '            rules::sageFieldCategoryCount(-5) != 12 ||',
     '            rules::sageFieldCategoryCount(99) != 9 ||',
     '            rules::sageFieldCategoryFirst(-5) != 0 ||',
     '            rules::sageFieldCategoryFirst(99) != 59 ||',
     '            rules::sageCategoryField(-5) != 0 ||',
     '            rules::sageCategoryField(99) != 6) ++bad;',
     '        // the fields-count table',
     '        if (rules::sageFieldsBandCount() != 6) ++bad;',
     '        for (int i = 0; i < 6; ++i)',
     '            if (rules::sageFieldsBandLo(i) != kBandLo[i] ||',
     '                rules::sageFieldsBandHi(i) != kBandHi[i] ||',
     '                rules::sageFieldsBandMinor(i) !=',
     '                    kBandMinor[i] ||',
     '                rules::sageFieldsBandSpecial(i) !=',
     '                    kBandSpecial[i]) ++bad;',
     '        // the bands tile 1-100',
     '        if (rules::sageFieldsBandLo(0) != 1 ||',
     '            rules::sageFieldsBandHi(5) != 100) ++bad;',
     '        for (int i = 0; i < 5; ++i)',
     '            if (rules::sageFieldsBandHi(i) + 1 !=',
     '                rules::sageFieldsBandLo(i + 1)) ++bad;',
     '        // the band clamps',
     '        if (rules::sageFieldsBandLo(-5) != 1 ||',
     '            rules::sageFieldsBandHi(-5) != 10 ||',
     '            rules::sageFieldsBandLo(99) != 91 ||',
     '            rules::sageFieldsBandHi(99) != 100 ||',
     '            rules::sageFieldsBandMinor(-5) != 1 ||',
     '            rules::sageFieldsBandMinor(99) != 2 ||',
     '            rules::sageFieldsBandSpecial(-5) != 2 ||',
     '            rules::sageFieldsBandSpecial(99) != 4) ++bad;',
     '        // the chance-of-knowing bands',
     '        for (int s = 0; s < 4; ++s)',
     '            for (int n = 0; n < 3; ++n)',
     '                if (rules::sageKnowLo(s, n) !=',
     '                    kKnowLo[s][n] ||',
     '                    rules::sageKnowHi(s, n) !=',
     '                    kKnowHi[s][n]) ++bad;',
     '        // the none identity (only the',
     '        // out-of-fields exacting cell prints a',
     '        // dash)',
     '        for (int s = 0; s < 4; ++s)',
     '            for (int n = 0; n < 3; ++n)',
     '                if ((rules::sageKnowLo(s, n) < 0) !=',
     '                    (rules::sageKnowNone(s, n) == 1)) ++bad;',
     '        // the real bands have lo below hi',
     '        for (int s = 0; s < 4; ++s)',
     '            for (int n = 0; n < 3; ++n)',
     '                if (kKnowLo[s][n] >= 0 &&',
     '                    rules::sageKnowLo(s, n) >=',
     '                    rules::sageKnowHi(s, n)) ++bad;',
     '        // the worked rows: the scrambled major',
     '        // row (61-80, 57-60, 26-35) and the',
     '        // special category column',
     '        if (rules::sageKnowLo(2, 0) != 61 ||',
     '            rules::sageKnowHi(2, 0) != 80 ||',
     '            rules::sageKnowLo(2, 1) != 57 ||',
     '            rules::sageKnowHi(2, 1) != 60 ||',
     '            rules::sageKnowLo(2, 2) != 26 ||',
     '            rules::sageKnowHi(2, 2) != 35 ||',
     '            rules::sageKnowLo(3, 1) != 76 ||',
     '            rules::sageKnowHi(3, 1) != 96 ||',
     '            rules::sageKnowNone(0, 2) != 1 ||',
     '            rules::sageKnowNone(3, 2) != 0) ++bad;',
     '        // the know clamps ((9, 9) the special',
     '        // category exacting cell)',
     '        if (rules::sageKnowLo(-5, -5) != 31 ||',
     '            rules::sageKnowHi(-5, -5) != 50 ||',
     '            rules::sageKnowLo(9, 9) != 61 ||',
     '            rules::sageKnowHi(9, 9) != 80) ++bad;',
     '        // the ability dice rows',
     '        if (rules::sageAbilityCount() != 6) ++bad;',
     '        for (int i = 0; i < 6; ++i)',
     '            if (rules::sageAbilityDice(i) != kDice[i] ||',
     '                rules::sageAbilityDiceCount(i) != kCnt[i] ||',
     '                rules::sageAbilityPlus(i) != kPlus[i]) ++bad;',
     '        // the worked ability rows: STR d8 + 7,',
     '        // INT d4 + 14, WIS d6 + 12, DEX 3d6,',
     '        // CON 2d6 + 3, CHA 2d6 + 2',
     '        if (rules::sageAbilityDice(0) != 8 ||',
     '            rules::sageAbilityDiceCount(0) != 1 ||',
     '            rules::sageAbilityPlus(0) != 7 ||',
     '            rules::sageAbilityDice(1) != 4 ||',
     '            rules::sageAbilityPlus(1) != 14 ||',
     '            rules::sageAbilityDice(2) != 6 ||',
     '            rules::sageAbilityPlus(2) != 12 ||',
     '            rules::sageAbilityDiceCount(3) != 3 ||',
     '            rules::sageAbilityPlus(3) != 0 ||',
     '            rules::sageAbilityDiceCount(4) != 2 ||',
     '            rules::sageAbilityPlus(4) != 3 ||',
     '            rules::sageAbilityPlus(5) != 2) ++bad;',
     '        // the ability clamps',
     '        if (rules::sageAbilityDice(-5) != 8 ||',
     '            rules::sageAbilityDiceCount(-5) != 1 ||',
     '            rules::sageAbilityPlus(-5) != 7 ||',
     '            rules::sageAbilityDice(99) != 6 ||',
     '            rules::sageAbilityDiceCount(99) != 2 ||',
     '            rules::sageAbilityPlus(99) != 2) ++bad;',
     '        // the alignment bands',
     '        if (rules::sageAlignBandCount() != 9) ++bad;',
     '        for (int i = 0; i < 9; ++i)',
     '            if (rules::sageAlignLo(i) != kAlignLo[i] ||',
     '                rules::sageAlignHi(i) != kAlignHi[i]) ++bad;',
     '        if (rules::sageAlignLo(0) != 1 ||',
     '            rules::sageAlignHi(8) != 100) ++bad;',
     '        for (int i = 0; i < 8; ++i)',
     '            if (rules::sageAlignHi(i) + 1 !=',
     '                rules::sageAlignLo(i + 1)) ++bad;',
     '        // the alignment clamps (band -5 the',
     '        // chaotic evil, 99 the neutral good)',
     '        if (rules::sageAlignLo(-5) != 1 ||',
     '            rules::sageAlignHi(-5) != 5 ||',
     '            rules::sageAlignLo(99) != 91 ||',
     '            rules::sageAlignHi(99) != 100) ++bad;',
     '        // the hit points: 8d4',
     '        if (rules::sageHpDiceCount() != 8 ||',
     '            rules::sageHpDie() != 4) ++bad;',
     '        // the spell kinds and limits',
     '        if (rules::sageSpellKindCount() != 3) ++bad;',
     '        for (int i = 0; i < 7; ++i)',
     '            if (rules::sageSpellKind(i) !=',
     '                kSpellKind[i]) ++bad;',
     '        if (rules::sageSpellMaxDie() != 4 ||',
     '            rules::sageSpellMaxPlus() != 2 ||',
     '            rules::sageSpellMaxLo() != 3 ||',
     '            rules::sageSpellMaxHi() != 6 ||',
     '            rules::sageSpellPerLevelLo() != 1 ||',
     '            rules::sageSpellPerLevelHi() != 4 ||',
     '            rules::sageSpellReadyPerLevel() != 1) ++bad;',
     '        // the spell kind clamps',
     '        if (rules::sageSpellKind(-5) != 0 ||',
     '            rules::sageSpellKind(99) != 2) ++bad;',
     '        // the offer table',
     '        if (rules::sageOfferCount() != 3) ++bad;',
     '        for (int i = 0; i < 3; ++i)',
     '            if (rules::sageOfferLo(i) != kOfferLo[i] ||',
     '                rules::sageOfferHi(i) != kOfferHi[i]) ++bad;',
     '        // the offer clamps (row 2 the material',
     '        // minimum)',
     '        if (rules::sageOfferLo(-5) != 200 ||',
     '            rules::sageOfferHi(-5) != 1200 ||',
     '            rules::sageOfferLo(99) != 20000 ||',
     '            rules::sageOfferHi(99) != 20000) ++bad;',
     '        // the efficiency milestones and steps',
     '        if (rules::sageEffMilestoneCount() != 3) ++bad;',
     '        for (int i = 0; i < 3; ++i)',
     '            if (rules::sageEffMilestoneCost(i) !=',
     '                kEffCost[i] ||',
     '                rules::sageEffMilestonePercent(i) !=',
     '                kEffPct[i]) ++bad;',
     '        if (rules::sageEffStepCost() != 1000 ||',
     '            rules::sageEffHighCostPerPercent() != 4000)',
     '            ++bad;',
     '        // the efficiency clamps (the 100,000',
     '        // g.p. full-cost pin)',
     '        if (rules::sageEffMilestoneCost(-5) != 20000 ||',
     '            rules::sageEffMilestonePercent(-5) != 50 ||',
     '            rules::sageEffMilestoneCost(99) != 100000 ||',
     '            rules::sageEffMilestonePercent(99) != 100)',
     '            ++bad;',
     '        // the improvement ladder',
     '        if (rules::sageImproveCount() != 4) ++bad;',
     '        for (int i = 0; i < 4; ++i)',
     '            if (rules::sageImproveCost(i) !=',
     '                    kImproveCost[i] ||',
     '                rules::sageImproveMonths(i) !=',
     '                    kImproveMonths[i] ||',
     '                rules::sageImproveMax(i) !=',
     '                    kImproveMax[i]) ++bad;',
     '        // the improvement clamps',
     '        if (rules::sageImproveCost(-5) != 5000 ||',
     '            rules::sageImproveMonths(-5) != 1 ||',
     '            rules::sageImproveMax(-5) != 5 ||',
     '            rules::sageImproveCost(99) != 200000 ||',
     '            rules::sageImproveMonths(99) != 24 ||',
     '            rules::sageImproveMax(99) != -1) ++bad;',
     '        // the information discovery time bands',
     '        for (int s = 0; s < 4; ++s)',
     '            for (int n = 0; n < 3; ++n)',
     '                if (rules::sageTimeLo(s, n) !=',
     '                    kTimeLo[s][n] ||',
     '                    rules::sageTimeHi(s, n) !=',
     '                    kTimeHi[s][n] ||',
     '                    rules::sageTimeUnit(s, n) !=',
     '                    kTimeUnit[s][n]) ++bad;',
     '        // the time none identity',
     '        for (int s = 0; s < 4; ++s)',
     '            for (int n = 0; n < 3; ++n)',
     '                if ((rules::sageTimeLo(s, n) < 0) !=',
     '                    (rules::sageTimeNone(s, n) == 1)) ++bad;',
     '        // the worked time rows: the special',
     '        // category specific band is the lone',
     '        // HOURS cell (1-10); the major exacting',
     '        // is 3-30 days',
     '        if (rules::sageTimeLo(3, 1) != 1 ||',
     '            rules::sageTimeHi(3, 1) != 10 ||',
     '            rules::sageTimeUnit(3, 1) != 1 ||',
     '            rules::sageTimeLo(2, 2) != 3 ||',
     '            rules::sageTimeHi(2, 2) != 30 ||',
     '            rules::sageTimeNone(0, 2) != 1 ||',
     '            rules::sageTimeNone(3, 2) != 0) ++bad;',
     '        // the time clamps ((9, 9) the special',
     '        // category exacting cell)',
     '        if (rules::sageTimeLo(9, 9) != 2 ||',
     '            rules::sageTimeHi(9, 9) != 12 ||',
     '            rules::sageTimeUnit(9, 9) != 2 ||',
     '            rules::sageTimeLo(-5, -5) != 1 ||',
     '            rules::sageTimeHi(-5, -5) != 6) ++bad;',
     '        // the cost per day and the free-spread',
     '        // thresholds',
     '        for (int s = 0; s < 4; ++s)',
     '            if (rules::sageCostPerDay(s) != kCostDay[s] ||',
     '                rules::sageFreeSpreadPercent(s) !=',
     '                kFree[s]) ++bad;',
     '        if (rules::sageCostPerDay(-5) != 100 ||',
     '            rules::sageCostPerDay(99) != 200 ||',
     '            rules::sageFreeSpreadPercent(-5) != 20 ||',
     '            rules::sageFreeSpreadPercent(99) != 80) ++bad;',
     '        // the unknown band and the short-term',
     '        // terms',
     '        if (rules::sageUnknownPercentLo() != 51 ||',
     '            rules::sageUnknownPercentHi() != 100 ||',
     '            rules::sageUnknownCostDivisor() != 2 ||',
     '            rules::sageShortTermCostPerDay() != 100 ||',
     '            rules::sageShortTermMaxDays() != 7 ||',
     '            rules::sageShortTermCooldownMonths() != 1 ||',
     '            rules::sagePermanentHireOnly() != 1) ++bad;',
     '        printf("R310 sage subsection audit: bad %d'
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
for _t in (RT_OLD, RT_NEW, RT_AUD):
    for _ln in _t.split(NL):
        assert all(ord(_c) < 128 for _c in _ln), 'non-ascii in audit'
        assert len(_ln) <= 76, 'audit line too long: ' + _ln
        assert Q not in _ln, 'apostrophe in audit'
        if 'printf("' in _ln:
            assert _ln.count(BS) == 1, 'printf BS count wrong'
        else:
            assert BS not in _ln, 'stray backslash in audit'
_calls = _calls_in(RT_AUD)
assert len(_calls) == 58, 'audit call coverage'
_hx = _accs(rd('rules/sage.h'))
assert _calls <= set(_hx), 'audit calls unknown accessor'

p = 'regtest.cpp'
s = rd(p)
if 'R310 sage subsection audit' in s:
    already.append('regtest.cpp: the audit block')
else:
    assert s.count('audit: bad') == 233, 'rt census not 233'
    assert s.count(RT_OLD) == 1, 'rt anchor not unique'
    assert 'sageField' not in s, 'rt collision'
    assert 'sageKnow' not in s, 'rt collision'
    assert 'sageTime' not in s, 'rt collision'
    s = s.replace(RT_OLD, RT_NEW)
    wr(p, s)
    applied.append('regtest.cpp: the audit block')

s = rd(p)
assert s.count('audit: bad') == 234, 'patch c census wrong'
assert s.count('R310 sage subsection audit') == 1, 'c label'
assert s.count('R309 hirelings cost tables audit') == 1, 'c r309 tail'
assert s.count('R227: the wis mental save wiring audit') == 1, 'c head'
assert s.count('rules/sage.h') == 2, 'c references'
assert s.count('{') == s.count('}'), 'rt brace balance'
assert s.count('(') == s.count(')'), 'rt paren balance'
assert len(applied) + len(already) == 3, 'patch c count wrong'

# ---- (d) tools/dmg_gap_report.md: the chronicle ----
CH_OLD = NL.join([
    'the R309 audit.',
    '',
    'Categories:',
])
CH_NEW = NL.join([
    'the R309 audit.',
    '',
    'R310 the sage subsection pin (the',
    'last R307 open box paid - the dmg',
    'ledger clears): rules/sage.h (the',
    'grenade.h pattern): the',
    'fields-count table (6 dice bands);',
    'the fields of study - 7 fields',
    'carrying 68 special knowledge',
    'categories (the OCR column',
    'interleave resolved per the',
    'compilation cross-read:',
    'Chemistry restored to the',
    'physical universes, Trees',
    'restored to flora); the',
    'chance-of-knowing bands (4',
    'scopes by 3 natures, the',
    'out-of-fields exacting cell',
    'pinned -1, the scrambled 57-60',
    'major specific cell recovered);',
    'the sage characteristics (the',
    'ability dice rows, the nine',
    'alignment bands, 8d4 hit',
    'points, the spell limits and',
    'kinds); the offer table (200 to',
    '1,200 g.p. twice, the 20,000',
    'g.p. minimum); the efficiency',
    'milestones with the',
    'improvement ladder; the',
    'information discovery time and',
    'cost table (the rounds, hours',
    'and days bands, 100 to 1,000',
    'g.p. per day, the free-spread',
    'thresholds, the 51-100 percent',
    'unknown band at half cost). No',
    'engine site charges them yet;',
    'the battery census moves 233 ->',
    '234 with the R310 audit.',
    '',
    'Categories:',
])
clean(CH_OLD, 57, gap=True)
clean(CH_NEW, 57, gap=True)

p = 'tools/dmg_gap_report.md'
s = rd(p)
if 'R310 the sage subsection pin' in s:
    already.append('dmg report: the chronicle')
else:
    assert s.count(CH_OLD) == 1, 'chronicle anchor not unique'
    s = s.replace(CH_OLD, CH_NEW)
    wr(p, s)
    applied.append('dmg report: the chronicle')

s = rd(p)
assert s.count('R310 the sage subsection pin') == 1, 'd entry'
assert s.count('Categories:') == 1, 'd legend head'
assert s.count('moves 233 ->' + NL + '234 with the R310 audit.') == 1, 'd census note'
assert len(applied) + len(already) == 4, 'patch d count wrong'

# ---- (e) tools/dmg_gap_report.md: the box flip ----
BX_OLD = NL.join([
    '- [ ] **The sage subsection (upload',
    '      line 2110) - OPENED R307:** the',
    '      fields of study with the special',
    '      knowledge categories, the exact',
    '      versus learned question chances',
    '      and the location prose. A data',
    '      candidate: the fields and chance',
    '      bands pin dm/-side (the',
    '      appendixa.h pattern); no town',
    '      consultation site exists - the',
    '      judgment waits for the pin round.',
])
BX_NEW = NL.join([
    '- [x] **The sage subsection (upload',
    '      line 2110) - PINNED R310:**',
    '      rules/sage.h (the grenade.h',
    '      pattern): the fields-count',
    '      table - 6 dice bands; the',
    '      fields of study - 7 fields',
    '      carrying 68 special knowledge',
    '      categories; the',
    '      chance-of-knowing table - 4',
    '      scopes by 3 natures with the',
    '      none cell pinned -1 (the',
    '      scrambled major row recovered',
    '      per the compilation',
    '      cross-read, which also',
    '      restores Chemistry to the',
    '      physical universes and Trees',
    '      to flora from the OCR column',
    '      interleave); the sage',
    '      characteristics - the six',
    '      ability dice rows, the nine',
    '      alignment bands, 8d4 hit',
    '      points, the spell limits (d4',
    '      + 2 for the 3-6 maximum, 1-4',
    '      spells per level, 1 ready);',
    '      the offer table (200 to 1,200',
    '      g.p. twice and the 20,000',
    '      g.p. minimum); the efficiency',
    '      economics (20000, 60000 and',
    '      100000 g.p. at 50, 90 and 100',
    '      percent) with the improvement',
    '      ladder; the information',
    '      discovery time and cost table',
    '      (the lone hours cell the',
    '      special-category specific',
    '      band; costs 100 to 1,000 g.p.',
    '      per day; the free-spread',
    '      thresholds 20 and 80 percent;',
    '      the 51-100 unknown band at',
    '      half cost). The hiring and',
    '      location prose rides as',
    '      recorded notes; no engine',
    '      site charges them yet (no',
    '      sage consultation layer).',
    '      Census 234. The ledger holds',
    '      ZERO open items.',
])
clean(BX_OLD, 57, gap=True)
clean(BX_NEW, 57, gap=True)

p = 'tools/dmg_gap_report.md'
s = rd(p)
if 'PINNED R310' in s:
    already.append('dmg report: the box flip')
else:
    assert s.count(BX_OLD) == 1, 'box anchor not unique'
    assert s.count('- [ ]') == 2, 'dmg open count not 2'
    s = s.replace(BX_OLD, BX_NEW)
    wr(p, s)
    applied.append('dmg report: the box flip')

s = rd(p)
assert s.count('PINNED R310') == 1, 'patch e pinned tag'
assert s.count('OPENED R307') == 0, 'patch e open tag residue'
assert s.count('- [ ]') == 1, 'patch e open residue'
assert s.count('Census 234') == 1, 'patch e census note'
assert s.count('Census 233') == 1, 'patch e r309 census intact'
assert s.count('## Out of scope by design') == 1, 'e out head intact'
assert len(applied) + len(already) == 5, 'patch e count wrong'

# ---- R310 fails/tail ----
if fails:
    print('R310 splice: FAIL - ' + str(len(fails))
          + ' patch(es) failed:')
    for f in fails:
        print('  ' + f)
    sys.exit(1)
if len(applied) + len(already) != 5:
    print('R310 splice: FAIL - expected 5 patches, counted '
          + str(len(applied) + len(already))
          + ' (a truncated paste?)')
    sys.exit(1)
print('R310 splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R310 note: 5 patches; the sage')
print('subsection pinned - the battery')
print('census moves 233 -> 234; the dmg')
print('ledger holds ZERO open items')
print('commit: R310: the sage subsection')
print('pinned (census 234)')

