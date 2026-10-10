#!/usr/bin/env python3
# tools/r300_splice.py - R300: the equipment
# cost columns pinned (the R299 open item; the
# R190 printed-table-wins debt) and the engine
# items costs repinned.
#
# The R299 scope pass opened ONE item: the
# BASIC EQUIPMENT AND SUPPLIES COSTS tables
# were never battery-pinned, and the items
# costGp column carried a verification debt.
# This round pays it:
#
#   (a) rules/equipcosts.h CREATED - the 52
#       arms rows and the 14 armor rows pinned
#       cell by cell (the gold and silver
#       columns - exactly one unit nonzero per
#       row), the name arrays and the monetary
#       pin 20 s.p. = 1 g.p. Both upload copies
#       read (the reference sheet legible; the
#       equipment copy interleaves - it
#       resolves the empty glaive cell).
#   (b) items/items.cpp - the costGp column
#       repinned where it diverged (9 rows)
#       and the verification-debt comment
#       amended.
#   (c) regtest.cpp - the R300 audit pair (the
#       battery census 217 -> 219): the seam
#       audit walks every printed cell against
#       a local ground truth (evaluable -
#       verified by audit_eval) and the engine
#       audit maps every items weapon and
#       armor id to its printed row (the C++
#       battery is the gate; the quarterstaff,
#       club, sling and None conventions
#       recorded).
#   (d) tools/phb_gap_report.md - the R299 open
#       item flipped to PINNED R300 (the
#       repins and JUDGMENTs recorded); the
#       ledger holds ZERO open items.
#
# Idempotent: safe to run twice; a silent run
# means the paste was truncated - this tail
# ALWAYS prints. An assert follows EVERY patch
# (the R142 lesson). ZERO literal backslash
# bytes in this file (the audit printf newline
# builds via BS), and no CONTENT string embeds
# an apostrophe, non-ASCII or (for the gap
# report) a line past 57 columns.
# Commit: "R300: the equipment cost columns
# pinned and the engine costs repinned
# (census 219)"
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

# ---- (a) rules/equipcosts.h: the printed columns ----
EQUIPCOSTS = NL.join([
    '// ============================================================================',
    '// Adnd1 - rules/equipcosts.h',
    '// The equipment cost columns (R300).',
    '//',
    '// The PHB BASIC EQUIPMENT AND SUPPLIES COSTS tables (the',
    '// equipment section, upload line 2113; the reference-sheet',
    '// repeat, upload line 13432): the ARMS list - 52 rows (the',
    '// left column arrow through hammer, the right column javelin',
    '// through voulge; together alphabetical) - and the ARMOR list',
    '// - 14 rows, alphabetical. Every price pins in its printed',
    '// coin: the gold-piece rows and the six silver-piece ammo',
    '// rows (the single arrow 2 s.p., the dart 5, the javelin 10,',
    '// the light quarrel 1, the dozen sling and bullets 15 and the',
    '// score of sling bullets 10). Exactly one coin column is',
    '// nonzero on every arms row (the R300a battery audit walks',
    '// the identity). The monetary-system pin rides: 20 silver',
    '// pieces = 1 gold piece (eqcSilverPerGold).',
    '//',
    '// SOURCE NOTE: the reference sheet is the legible copy; the',
    '// equipment-section table interleaves in the OCR, but it',
    '// confirms the left rows 1-28 and the right rows 1-24 and',
    '// resolves the empty reference-sheet glaive cell to 6 g.p.',
    '//',
    '// JUDGMENTs:',
    '//   - the armor row 1 prints Bonded in the reference sheet',
    '//     and Banded in the equipment copy - the standard banded',
    '//     mail row (90 g.p.), pinned under the banded name.',
    '//   - the row names follow the R189 weaponChartName spellings',
    '//     where the rows match (footman flail, lucern hammer,',
    '//     awl pike and the rest; the purchase units spelled out:',
    '//     arrow, normal, dozen and quarrel, light, single).',
    '//',
    '// The ENGINE side (items/items.cpp costGp) is repinned by',
    '// this round where it diverged - the printed-table-wins',
    '// debt; the R300 battery audit maps every engine weapon and',
    '// armor id to its printed row. The general equipment rows',
    '// (clothing, herbs, livestock, provisions, religious items,',
    '// tack, transport) carry no engine layer - out of engine',
    '// scope.',
    '//',
    '// DATA-DRIVEN (the standing scope).',
    '// ============================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    '// ---- the arms list (52 rows) ----',
    '',
    '// The chart row count (the print: 52 arms rows).',
    'inline int eqcArmsCount() {',
    '    // the two printed columns together, alphabetical',
    '    return 52;',
    '}',
    '',
    '// The arms row name at index i (clamped), the print order.',
    'inline const char* eqcArmsName(int i) {',
    '    static const char* const kNames[52] = {',
    '        "arrow, normal, single",',
    '        "arrow, normal, dozen",',
    '        "arrow, silver, single",',
    '        "axe, battle",',
    '        "axe, hand or throwing",',
    '        "bardiche",',
    '        "bec de corbin",',
    '        "bill-guisarme",',
    '        "bow, composite, short",',
    '        "bow, composite, long",',
    '        "bow, long",',
    '        "bow, short",',
    '        "crossbow, heavy",',
    '        "crossbow, light",',
    '        "dagger and scabbard",',
    '        "dart",',
    '        "fauchard",',
    '        "fauchard-fork",',
    '        "footman flail",',
    '        "horseman flail",',
    '        "military fork",',
    '        "glaive",',
    '        "glaive-guisarme",',
    '        "guisarme",',
    '        "guisarme-voulge",',
    '        "halberd",',
    '        "lucern hammer",',
    '        "hammer",',
    '        "javelin",',
    '        "lance",',
    '        "footman mace",',
    '        "horseman mace",',
    '        "morning star",',
    '        "partisan",',
    '        "footman pick",',
    '        "horseman pick",',
    '        "awl pike",',
    '        "quarrel, light, single",',
    '        "quarrel, heavy, score",',
    '        "ranseur",',
    '        "scimitar",',
    '        "sling and bullets, dozen",',
    '        "sling bullets, score",',
    '        "spear",',
    '        "spetum",',
    '        "bastard sword and scabbard",',
    '        "broad sword and scabbard",',
    '        "long sword and scabbard",',
    '        "short sword and scabbard",',
    '        "two-handed sword",',
    '        "trident",',
    '        "voulge",',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 51) i = 51;',
    '    return kNames[i];',
    '}',
    '',
    '// The arms price in gold pieces (the silver rows pin 0',
    '// here - exactly one unit nonzero per row).',
    'inline int eqcArmsGold(int i) {',
    '    static const int kGold[52] = {',
    '         0,   1,   1,   5,   1,   7,   6,   6,  75, 100,',
    '        60,  15,  20,  12,   2,   0,   3,   8,   3,   8,',
    '         4,   6,  10,   5,   7,   9,   7,   1,   0,   6,',
    '         8,   4,   5,  10,   8,   5,   3,   0,   2,   4,',
    '        15,   0,   0,   1,   3,  25,  10,  15,   8,  30,',
    '         4,   2,',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 51) i = 51;',
    '    return kGold[i];',
    '}',
    '',
    '// The arms price in silver pieces (the six ammo rows).',
    'inline int eqcArmsSilver(int i) {',
    '    static const int kSilver[52] = {',
    '         2,   0,   0,   0,   0,   0,   0,   0,   0,   0,',
    '         0,   0,   0,   0,   0,   5,   0,   0,   0,   0,',
    '         0,   0,   0,   0,   0,   0,   0,   0,  10,   0,',
    '         0,   0,   0,   0,   0,   0,   0,   1,   0,   0,',
    '         0,  15,  10,   0,   0,   0,   0,   0,   0,   0,',
    '         0,   0,',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 51) i = 51;',
    '    return kSilver[i];',
    '}',
    '',
    '// ---- the armor list (14 rows) ----',
    '',
    '// The armor row count (the print: 14 armor rows).',
    'inline int eqcArmorCount() {',
    '    // the two printed columns together, alphabetical',
    '    return 14;',
    '}',
    '',
    '// The armor row name at index i (clamped), the print order.',
    'inline const char* eqcArmorName(int i) {',
    '    static const char* const kNames[14] = {',
    '        "banded",',
    '        "chain",',
    '        "helmet, great",',
    '        "helmet, small",',
    '        "leather",',
    '        "padded",',
    '        "plate",',
    '        "ring",',
    '        "scale",',
    '        "shield, large",',
    '        "shield, small",',
    '        "shield, small, wooden",',
    '        "splinted",',
    '        "studded",',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 13) i = 13;',
    '    return kNames[i];',
    '}',
    '',
    '// The armor price in gold pieces (every armor row prints',
    '// in gold).',
    'inline int eqcArmorGold(int i) {',
    '    static const int kGold[14] = {',
    '        90,  75,  15,  10,   5,   4,',
    '       400,  30,  45,  15,  10,   1,',
    '        80,  15,',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 13) i = 13;',
    '    return kGold[i];',
    '}',
    '',
    '// The monetary-system pin: 20 silver pieces = 1 gold',
    '// piece (the upload MONETARY SYSTEM section).',
    'inline int eqcSilverPerGold() {',
    '    return 20;',
    '}',
    '',
    '}  // namespace rules',
    '',
])
clean(EQUIPCOSTS, 100)

p = 'rules/equipcosts.h'
if os.path.exists(os.path.join(ROOT, p)):
    s = rd(p)
    if 'The equipment cost columns (R300)' in s:
        already.append('equipcosts.h created')
    else:
        fails.append('equipcosts.h exists without the R300 marker')
else:
    wr(p, EQUIPCOSTS)
    applied.append('equipcosts.h created')
s = rd(p)
assert 'eqcArmsCount' in s, 'patch a failed'
assert s.count('inline int eqc') == 6, 'accessor count wrong'
assert s.count('}  // namespace rules') == 1, 'patch a namespace close'
assert len(applied) + len(already) == 1, 'patch a count wrong'

# ---- (b) items/items.cpp: the comment amend + the 9 repins ----
IT_NOTE_OLD = NL.join([
    '// Weight in gp units (1 gp = 1/10 lb). Costs from the same table.',
    '// NOTE: values follow the standard 1e table from project notes',
    '// (verification debt - printed table wins).',
])
IT_NOTE_NEW = NL.join([
    '// Weight in gp units (1 gp = 1/10 lb). R300: the costGp',
    '// column repinned to the printed BASIC EQUIPMENT AND SUPPLIES',
    '// COSTS tables (rules/equipcosts.h) - the printed-table-wins',
    '// debt paid. The rows NOT in the print (quarterstaff, club)',
    '// keep 0 as ENGINE CONVENTION; the sling keeps the 2 g.p.',
    '// engine price (the print prices the dozen sling and bullets',
    '// bundle, 15 s.p.); the generic mace and flail read the',
    '// printed footman rows (8 and 3 g.p.).',
])
REPINS = [
    ('    { "Hand Axe",       rules::WCLASS_SLASHING,   1,6,0,   1,4,0,   false,   0,  0,   50,     4,',
     '    { "Hand Axe",       rules::WCLASS_SLASHING,   1,6,0,   1,4,0,   false,   0,  0,   50,     1,'),
    ('    { "Battle Axe",     rules::WCLASS_SLASHING,   1,8,0,  1,8,0,    false,   0,  0,   70,     7,',
     '    { "Battle Axe",     rules::WCLASS_SLASHING,   1,8,0,  1,8,0,    false,   0,  0,   70,     5,'),
    ('    { "Flail",          rules::WCLASS_BLUDGEONING,1,6,1,  2,7,1,    false,   0,  0,   80,    15,',
     '    { "Flail",          rules::WCLASS_BLUDGEONING,1,6,1,  2,7,1,    false,   0,  0,   80,     3,'),
    ('    { "Morning Star",   rules::WCLASS_BLUDGEONING,2,4,0,  1,6,1,    false,   0,  0,  100,    10,',
     '    { "Morning Star",   rules::WCLASS_BLUDGEONING,2,4,0,  1,6,1,    false,   0,  0,  100,     5,'),
    ('    { "Spear",          rules::WCLASS_PIERCING,   1,6,0,  1,8,0,    false,   0,  0,   60,     3,',
     '    { "Spear",          rules::WCLASS_PIERCING,   1,6,0,  1,8,0,    false,   0,  0,   60,     1,'),
    ('    { "Short Bow",      rules::WCLASS_PIERCING,   1,6,0,  1,6,0,    true,    5,  2,   20,    25,',
     '    { "Short Bow",      rules::WCLASS_PIERCING,   1,6,0,  1,6,0,    true,    5,  2,   20,    15,'),
    ('    { "Long Bow",       rules::WCLASS_PIERCING,   1,6,0,  1,6,0,    true,    7,  2,   30,    40,',
     '    { "Long Bow",       rules::WCLASS_PIERCING,   1,6,0,  1,6,0,    true,    7,  2,   30,    60,'),
    ('    { "Light Crossbow", rules::WCLASS_PIERCING,   1,4,0,  1,4,0,    true,    6,  1,   70,    10,',
     '    { "Light Crossbow", rules::WCLASS_PIERCING,   1,4,0,  1,4,0,    true,    6,  1,   70,    12,'),
    ('    { "Scale Mail",       6,    rules::ARMOR_CHAIN,        400,    50 },',
     '    { "Scale Mail",       6,    rules::ARMOR_CHAIN,        400,    45 },'),
]
clean(IT_NOTE_OLD, 78)
clean(IT_NOTE_NEW, 78)
for old, new in REPINS:
    clean(old, 100)
    clean(new, 100)

p = 'items/items.cpp'
s = rd(p)
if 'R300: the costGp' in s:
    already.append('items.cpp: the comment + the 9 repins')
else:
    assert s.count(IT_NOTE_OLD) == 1, 'items note anchor not unique'
    s = s.replace(IT_NOTE_OLD, IT_NOTE_NEW)
    for old, new in REPINS:
        assert s.count(old) == 1, 'repin anchor not unique: ' + old[:30]
        s = s.replace(old, new)
    wr(p, s)
    applied.append('items.cpp: the comment + the 9 repins')
s = rd(p)
assert 'R300: the costGp' in s, 'patch b failed'
assert 'verification debt - printed table wins' not in s, 'patch b stale note'
for old, new in REPINS:
    assert old not in s, 'patch b left an old row: ' + old[:30]
    assert s.count(new) == 1, 'patch b new row count: ' + new[:30]
assert 'R145: the per-weapon p.38 row' in s, 'patch b ate the R145 note'
assert s.count('costGp') == 2, 'patch b field comment count wrong'
assert len(applied) + len(already) == 2, 'patch b count wrong'

# ---- (c) regtest.cpp: the include + the R300 audit pair ----
REG_INC_OLD = '#include "rules/thieffunc.h"  // R298: the thief function take table and DEX Table II'
REG_INC_NEW = NL.join([
    '#include "rules/thieffunc.h"  // R298: the thief function take table and DEX Table II',
    '#include "rules/equipcosts.h"  // R300: the equipment cost columns',
])
SEAM_AUDIT = NL.join([
    '    // ---- R300a: the equipment cost columns seam audit ----',
    '    // The printed BASIC EQUIPMENT AND SUPPLIES COSTS tables',
    '    // (rules/equipcosts.h) walked cell for cell against this',
    '    // local ground truth, the clamps, the coin-unit identity',
    '    // (exactly one of the gold and silver columns nonzero on',
    '    // every arms row), the six silver ammo rows and the',
    '    // monetary-system pin (20 s.p. = 1 g.p.). The ENGINE side',
    '    // (the items costGp repins) is the engine audit below.',
    '    {',
    '        int bad = 0;',
    '        static const int kGold[52] = {',
    '             0,   1,   1,   5,   1,   7,   6,   6,  75, 100,',
    '            60,  15,  20,  12,   2,   0,   3,   8,   3,   8,',
    '             4,   6,  10,   5,   7,   9,   7,   1,   0,   6,',
    '             8,   4,   5,  10,   8,   5,   3,   0,   2,   4,',
    '            15,   0,   0,   1,   3,  25,  10,  15,   8,  30,',
    '             4,   2,',
    '        };',
    '        static const int kSilver[52] = {',
    '             2,   0,   0,   0,   0,   0,   0,   0,   0,   0,',
    '             0,   0,   0,   0,   0,   5,   0,   0,   0,   0,',
    '             0,   0,   0,   0,   0,   0,   0,   0,  10,   0,',
    '             0,   0,   0,   0,   0,   0,   0,   1,   0,   0,',
    '             0,  15,  10,   0,   0,   0,   0,   0,   0,   0,',
    '             0,   0,',
    '        };',
    '        static const int kArmor[14] = {',
    '            90,  75,  15,  10,   5,   4,  400,  30,',
    '            45,  15,  10,   1,  80,  15,',
    '        };',
    '        // the row counts',
    '        if (rules::eqcArmsCount() != 52 ||',
    '            rules::eqcArmorCount() != 14) ++bad;',
    '        // the arms gold column, every row',
    '        for (int i = 0; i < 52; ++i)',
    '            if (rules::eqcArmsGold(i) != kGold[i]) ++bad;',
    '        // the arms silver column, every row',
    '        for (int i = 0; i < 52; ++i)',
    '            if (rules::eqcArmsSilver(i) != kSilver[i]) ++bad;',
    '        // the armor gold column, every row',
    '        for (int i = 0; i < 14; ++i)',
    '            if (rules::eqcArmorGold(i) != kArmor[i]) ++bad;',
    '        // the coin-unit identity: exactly one nonzero',
    '        // column on every arms row',
    '        for (int i = 0; i < 52; ++i)',
    '            if ((rules::eqcArmsGold(i) == 0) ==',
    '                (rules::eqcArmsSilver(i) == 0)) ++bad;',
    '        // the clamps: past either edge reads the edge row',
    '        // (the edges differ in both columns - the single',
    '        // arrow 0 gold 2 silver; the voulge 2 gold 0 silver)',
    '        if (rules::eqcArmsGold(-5) != 0 ||',
    '            rules::eqcArmsSilver(-5) != 2 ||',
    '            rules::eqcArmsGold(99) != 2 ||',
    '            rules::eqcArmsSilver(99) != 0) ++bad;',
    '        if (rules::eqcArmorGold(-5) != 90 ||',
    '            rules::eqcArmorGold(99) != 15) ++bad;',
    '        // the six silver rows are the ammo prices',
    '        if (rules::eqcArmsSilver(0) != 2 ||',
    '            rules::eqcArmsSilver(15) != 5 ||',
    '            rules::eqcArmsSilver(28) != 10 ||',
    '            rules::eqcArmsSilver(37) != 1 ||',
    '            rules::eqcArmsSilver(41) != 15 ||',
    '            rules::eqcArmsSilver(42) != 10) ++bad;',
    '        // the monetary-system pin',
    '        if (rules::eqcSilverPerGold() != 20) ++bad;',
    '        printf("R300a equipment cost columns seam audit: bad %d'
    + BS + 'n", bad);',
    '    }',
])
ENGINE_AUDIT = NL.join([
    '    // ---- R300: the equipment costs engine audit ----',
    '    // The items costGp column repinned to the printed tables',
    '    // (rules/equipcosts.h): every engine weapon and armor id',
    '    // maps to its printed row - the printed-table-wins debt',
    '    // paid. The recorded conventions: the quarterstaff and',
    '    // club are not in the print (0 stays the engine',
    '    // convention), the sling keeps the 2 g.p. engine price',
    '    // (the print prices the dozen sling and bullets bundle,',
    '    // 15 s.p.), the generic mace and flail read the footman',
    '    // rows and the unsold armor None reads 0. The shield',
    '    // file-static 10 g.p. equals the print Shield, small row',
    '    // (no accessor - recorded, not audited).',
    '    {',
    '        int bad = 0;',
    '        // the printed arms row each engine weapon reads',
    '        // (-1 = not in the print, 0 stays; -2 = the sling',
    '        // bundle convention, the engine keeps 2 g.p.)',
    '        static const int kRow[15] = {',
    '            14, 4, 48, 47, 3, 30, 18, 32, 43, -1,',
    '            -1, 11, 10, 13, -2,',
    '        };',
    '        for (int i = 0; i < 15; ++i) {',
    '            int want = 0;',
    '            if (kRow[i] >= 0)',
    '                want = rules::eqcArmsGold(kRow[i]);',
    '            if (kRow[i] == -2)',
    '                want = 2;',
    '            if (items::weapon((items::WeaponId)i).costGp != want)',
    '                ++bad;',
    '        }',
    '        // the printed armor row each engine armor id reads',
    '        // (-1 = the unsold None row, 0)',
    '        static const int kArow[10] = {',
    '            -1, 5, 4, 13, 7, 8, 1, 12, 0, 6,',
    '        };',
    '        for (int i = 0; i < 10; ++i) {',
    '            int want = 0;',
    '            if (kArow[i] >= 0)',
    '                want = rules::eqcArmorGold(kArow[i]);',
    '            if (items::armor((items::ArmorId)i).costGp != want)',
    '                ++bad;',
    '        }',
    '        // the repinned rows, spot-checked against the print',
    '        if (items::weapon(items::WPN_HAND_AXE).costGp != 1 ||',
    '            items::weapon(items::WPN_BATTLE_AXE).costGp != 5 ||',
    '            items::weapon(items::WPN_FLAIL).costGp != 3 ||',
    '            items::weapon(items::WPN_MORNING_STAR).costGp != 5 ||',
    '            items::weapon(items::WPN_SPEAR).costGp != 1 ||',
    '            items::weapon(items::WPN_SHORT_BOW).costGp != 15 ||',
    '            items::weapon(items::WPN_LONG_BOW).costGp != 60 ||',
    '            items::weapon(items::WPN_CROSSBOW_LIGHT).costGp != 12 ||',
    '            items::armor(items::ARMOR_SCALE_MAIL).costGp != 45)',
    '            ++bad;',
    '        // the kept rows: the print already agreed (dagger 2,',
    '        // short sword 8, long sword 15, mace 8, padded 4,',
    '        // leather 5, studded 15, ring 30, chain 75, splinted',
    '        // 80, banded 90, plate 400)',
    '        if (items::weapon(items::WPN_DAGGER).costGp != 2 ||',
    '            items::weapon(items::WPN_SHORT_SWORD).costGp != 8 ||',
    '            items::weapon(items::WPN_LONG_SWORD).costGp != 15 ||',
    '            items::weapon(items::WPN_MACE).costGp != 8 ||',
    '            items::armor(items::ARMOR_PADDED).costGp != 4 ||',
    '            items::armor(items::ARMOR_LEATHER).costGp != 5 ||',
    '            items::armor(items::ARMOR_STUDDED_LEATHER).costGp != 15 ||',
    '            items::armor(items::ARMOR_RING_MAIL).costGp != 30 ||',
    '            items::armor(items::ARMOR_CHAIN_MAIL).costGp != 75 ||',
    '            items::armor(items::ARMOR_SPLINTED).costGp != 80 ||',
    '            items::armor(items::ARMOR_BANDED).costGp != 90 ||',
    '            items::armor(items::ARMOR_PLATE).costGp != 400)',
    '            ++bad;',
    '        // the recorded conventions: the quarterstaff and',
    '        // club (not in the print), the sling (the bundle',
    '        // print, the 2 g.p. engine price) and the unsold',
    '        // armor None',
    '        if (items::weapon(items::WPN_QUARTERSTAFF).costGp != 0 ||',
    '            items::weapon(items::WPN_CLUB).costGp != 0 ||',
    '            items::weapon(items::WPN_SLING).costGp != 2 ||',
    '            items::armor(items::ARMOR_NONE_EQUIPPED).costGp != 0)',
    '            ++bad;',
    '        printf("R300 equipment costs engine audit: bad %d'
    + BS + 'n", bad);',
    '        if (bad) return 1;',
    '    }',
])
clean(REG_INC_OLD, 100)
clean(REG_INC_NEW, 100)
for ln in (SEAM_AUDIT + NL + ENGINE_AUDIT).split(NL):
    assert all(ord(c) < 128 for c in ln), 'non-ascii in audit'
    assert len(ln) <= 76, 'audit line too long: ' + ln
    assert chr(39) not in ln, 'apostrophe in audit'
    if 'printf' in ln:
        assert ln.count(BS) == 1, 'printf BS count wrong'
    else:
        assert BS not in ln, 'stray backslash in audit'

p = 'regtest.cpp'
s = rd(p)
if 'R300a equipment cost columns seam audit' in s:
    already.append('regtest.cpp: the R300 audit pair')
else:
    assert s.count('audit: bad') == 217, 'census is not 217'
    assert s.count(REG_INC_OLD) == 1, 'include anchor not unique'
    r299_tail = ('        printf("R299 party kit recordings engine audit: bad %d'
                 + BS + 'n", bad);')
    r227_head = '    // ---- R227: the wis mental save wiring audit ----'
    anchor = (r299_tail + NL + '        if (bad) return 1;' + NL +
              '    }' + NL + r227_head)
    assert s.count(anchor) == 1, 'regtest block anchor not unique'
    s = s.replace(REG_INC_OLD, REG_INC_NEW)
    new_region = (r299_tail + NL + '        if (bad) return 1;' + NL +
                  '    }' + NL + SEAM_AUDIT + NL + ENGINE_AUDIT + NL +
                  r227_head)
    s = s.replace(anchor, new_region)
    wr(p, s)
    applied.append('regtest.cpp: the R300 audit pair')
s = rd(p)
assert s.count('R300a equipment cost columns seam audit') == 1, 'patch c seam'
assert s.count('R300 equipment costs engine audit') == 1, 'patch c engine'
assert s.count('audit: bad') == 219, 'census is not 219'
assert 'R299 party kit recordings engine audit' in s, 'patch c ate R299'
assert '// ---- R227: the wis mental save wiring audit ----' in s, 'patch c ate R227'
assert '#include "rules/equipcosts.h"' in s, 'patch c include missing'
assert 'R298 thief function take table pins audit' in s, 'patch c ate R298'
assert len(applied) + len(already) == 3, 'patch c count wrong'

# ---- (d) tools/phb_gap_report.md: the flip ----
G_ITEM_OLD = NL.join([
    '- [ ] **The equipment cost columns (the BASIC',
    '      EQUIPMENT AND SUPPLIES COSTS tables,',
    '      upload line 2113; the reference-sheet',
    '      repeats at upload line 13432)** - the',
    '      arms and armor list prices the engine',
    '      carries as items costGp (dead data: no',
    '      shop charges them - the town stores',
    '      price canonically; verified repo-wide)',
    '      were never battery-pinned. A DATA-ONLY',
    '      pin candidate (the R190 precedent): a',
    '      rules header walking the printed arms',
    '      and armor cost columns cell by cell.',
    '      The R300 candidate. The general',
    '      equipment rows (clothing, herbs,',
    '      livestock, provisions, religious items,',
    '      tack, transport) carry no engine layer',
    '      - out of engine scope.',
])
G_ITEM_NEW = NL.join([
    '- [x] **The equipment cost columns (the BASIC',
    '      EQUIPMENT AND SUPPLIES COSTS tables,',
    '      upload line 2113; the reference-sheet',
    '      repeats at upload line 13432)** - PINNED',
    '      R300: rules/equipcosts.h CREATED - the',
    '      52 arms rows and the 14 armor rows',
    '      pinned cell by cell (eqcArmsGold,',
    '      eqcArmsSilver, eqcArmorGold and the',
    '      name arrays; exactly one coin unit',
    '      nonzero per arms row; the six silver',
    '      rows are the ammo prices - the single',
    '      arrow 2 s.p., the dart 5, the javelin',
    '      10, the light quarrel 1, the dozen',
    '      sling and bullets 15 and the score of',
    '      sling bullets 10) and the monetary pin',
    '      20 s.p. = 1 g.p. (eqcSilverPerGold).',
    '      Both upload copies read: the reference',
    '      sheet is legible, the equipment copy',
    '      interleaves - it resolves the empty',
    '      glaive cell to 6 g.p. and confirms the',
    '      left rows 1-28 and the right rows',
    '      1-24. The ENGINE items.cpp costGp',
    '      column REPINNED where it diverged',
    '      (9 repins: hand axe 4 to 1, battle axe',
    '      7 to 5, flail 15 to 3, morning star 10',
    '      to 5, spear 3 to 1, short bow 25 to 15,',
    '      long bow 40 to 60, light crossbow 10',
    '      to 12, scale mail 50 to 45) - the',
    '      printed-table-wins debt paid.',
    '      JUDGMENTs recorded: the generic mace',
    '      and flail read the printed footman',
    '      rows (8 and 3 g.p.); the quarterstaff',
    '      and club are not in the print (0 stays',
    '      ENGINE CONVENTION); the sling keeps',
    '      the 2 g.p. engine price (the print',
    '      prices the dozen-bullet bundle); the',
    '      shield file-static 10 g.p. equals the',
    '      print Shield, small row (no accessor -',
    '      recorded, not audited); the banded row',
    '      prints Bonded in one copy (the',
    '      standard banded mail, 90 g.p.). The',
    '      helmet rows and the ammo prices carry',
    '      no engine layer (dead data - no shop',
    '      charges them; the town stores price',
    '      canonically). The R300a battery audit',
    '      walks the seam (evaluable - verified',
    '      by audit_eval) and the R300 engine',
    '      audit maps every items weapon and',
    '      armor id to its printed row.',
    '      Census 219. The ledger holds ZERO',
    '      open items.',
])
clean(G_ITEM_OLD, 57)
clean(G_ITEM_NEW, 57)

p = 'tools/phb_gap_report.md'
s = rd(p)
if '13432)** - PINNED' in s:
    already.append('phb_gap_report.md: the flip')
else:
    assert s.count('- [ ]') == 1, 'the ledger does not hold exactly one open item'
    assert s.count(G_ITEM_OLD) == 1, 'gap item anchor not unique'
    assert s.count('- [ ] **The equipment cost columns (the BASIC') == 1, 'gap head line not unique'
    assert s.count('      The R300 candidate. The general') == 1, 'gap candidate line not unique'
    s = s.replace(G_ITEM_OLD, G_ITEM_NEW)
    wr(p, s)
    applied.append('phb_gap_report.md: the flip')
s = rd(p)
assert s.count('13432)** - PINNED') == 1, 'patch d failed'
assert s.count('- [ ]') == 0, 'patch d left an open item'
assert s.count('[x] **The equipment cost columns') == 1, 'flip box wrong'
assert 'Census 219.' in s, 'patch d census note missing'
assert 'Census 217.' in s, 'patch d ate the R299 census note'
assert 'Census 215.' in s, 'patch d ate the R298 census note'
assert 'WIRED R299' in s, 'patch d ate the R299 entry'
assert 'R299 SCOPE PASS' in s, 'patch d ate the R299 pass'
assert 'R296 SCOPE PASS' in s, 'patch d ate the R296 section'
assert '## Out of engine scope' in s, 'patch d ate the scope head'
assert len(applied) + len(already) == 4, 'patch d count wrong'

# ---- R300 fails/tail ----
if fails:
    print('R300 splice: FAIL - ' + str(len(fails))
          + ' patch(es) failed:')
    for f in fails:
        print('  ' + f)
    sys.exit(1)
if len(applied) + len(already) != 4:
    print('R300 splice: FAIL - expected 4 patches, counted '
          + str(len(applied) + len(already))
          + ' (a truncated paste?)')
    sys.exit(1)
print('R300 splice: ALL OK (applied '
      + str(len(applied)) + ', already '
      + str(len(already)) + ')')
print('R300 note: 4 patches; the battery census 217 -> 219;')
print('the phb ledger holds ZERO open items')
print('real gate: md5sum rules/equipcosts.h')
print('commit: R300: the equipment cost columns pinned and the engine costs repinned (census 219)')

