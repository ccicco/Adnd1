#!/usr/bin/env python3
# R255 splice: the ringIsChargeLimited fix.
#
# The R223 divergence, found by the R254 ground truth
# before any pin: rings.h ringIsChargeLimited flags
# Protection (row 11) and not Mammal Control (row 9),
# while the DMG p.137 table (upload ~9590-9617) carries
# the double-dagger on Mammal Control only, and the
# ringChargeLimitedCount comment already names Mammal
# Control. This round swaps rows 9 and 11 everywhere
# the divergence lives:
#   - rules/rings.h: the array (comment names the fix)
#   - rules/ringsprose2.h: the three divergence
#     comments now record the resolution
#   - regtest.cpp: the R223 audit kChg array + the
#     truthy/negative per-index asserts, and the R254
#     audit NOTE (rows 9/11 now asserted: 29 -> 31)
#   - tools/dmg_gap_report.md: the divergence note
#     flipped to RESOLVED, plus the R255 log entry
# No new audit line; census stays 173.
#
# commit: R255: the ringIsChargeLimited fix - Mammal Control row 9 in, Protection row 11 out (DMG p.137 table; census 173)

import sys

RH  = 'rules/rings.h'
R2  = 'rules/ringsprose2.h'
REG = 'regtest.cpp'
GAP = 'tools/dmg_gap_report.md'

NL = chr(10)

# pre-check - the census is 173 in BOTH states (no new
# audit line is added by a fix round); also the tree must
# be an R223-era rings tree
t = open(REG).read()
if t.count('audit: bad ') != 173:
    print('R255 FAIL: regtest census is not 173')
    sys.exit(1)
t = open(RH).read()
if 'ringIsChargeLimited' not in t or 'ringChargeLimitedCount' not in t:
    print('R255 FAIL: rings.h is not the R223 rings tree')
    sys.exit(1)

# ---- patch 1: rings.h, the charge-limited array ----
rh_old = [
    'inline int ringIsChargeLimited(int i) {',
    '    // the double-dagger charge-limited rows; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 23) i = 23;',
    '    static const int t[24] = {',
    '        0, 0, 1, 0, 0, 0, 0, 1, 0, 0,',
    '        1, 1, 0, 0, 0, 0, 0, 1, 1, 0,',
    '        0, 0, 1, 0,',
    '    };',
]
rh_new = [
    'inline int ringIsChargeLimited(int i) {',
    '    // the double-dagger charge-limited rows',
    '    // (the R255 fix: row 9 Mammal Control',
    '    // flagged, row 11 Protection not); i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 23) i = 23;',
    '    static const int t[24] = {',
    '        0, 0, 1, 0, 0, 0, 0, 1, 0, 1,',
    '        1, 0, 0, 0, 0, 0, 0, 1, 1, 0,',
    '        0, 0, 1, 0,',
    '    };',
]

# ---- patch 2: ringsprose2.h, the header banner ----
r2a_old = [
    '// against the R223 charge-limited rows. The',
    '// Mammal Control / Protection charge-limited',
    '// divergence (the R223 array flags the wrong',
    '// row) is documented in the gap report as',
    '// the ranked fix candidate. Pure data +',
    '// helpers, header-only (the grenade.h',
]
r2a_new = [
    '// against the R223 charge-limited rows. The',
    '// Mammal Control / Protection charge-limited',
    '// divergence (the R223 array flags the wrong',
    '// row) was resolved by the R255 fix. Pure',
    '// data + helpers, header-only (the grenade.h',
]

# ---- patch 3: ringsprose2.h, the mammal control flag ----
r2b_old = [
    '    // the prose entry carries the',
    '    // double-dagger; the R223 array',
    '    // does NOT flag row 9 - the',
    '    // documented divergence, the',
    '    // ranked fix candidate',
    '    return 1;',
]
r2b_new = [
    '    // the prose entry carries the',
    '    // double-dagger; the R255 fix',
    '    // made the R223 array flag',
    '    // row 9 correctly',
    '    return 1;',
]

# ---- patch 4: ringsprose2.h, the protection flag ----
r2c_old = [
    '    // the prose entry carries NO',
    '    // double-dagger; the R223 array',
    '    // flags row 11 - the documented',
    '    // divergence, the ranked fix',
    '    // candidate',
    '    return 0;',
]
r2c_new = [
    '    // the prose entry carries NO',
    '    // double-dagger; the R255 fix',
    '    // made the R223 array leave',
    '    // row 11 unflagged correctly',
    '    return 0;',
]

# ---- patch 5: regtest, the kChg array ----
kchg_old = [
    '        static const int kChg[24] = {',
    '            0, 0, 1, 0, 0, 0, 0, 1, 0, 0,',
    '            1, 1, 0, 0, 0, 0, 0, 1, 1, 0,',
    '            0, 0, 1, 0,',
    '        };',
]
kchg_new = [
    '        static const int kChg[24] = {',
    '            0, 0, 1, 0, 0, 0, 0, 1, 0, 1,',
    '            1, 0, 0, 0, 0, 0, 0, 1, 1, 0,',
    '            0, 0, 1, 0,',
    '        };',
]

# ---- patch 6: regtest, the charge-rows asserts ----
chg_old = [
    '        // the charge rows: the seven',
    '        // double-dagger rings',
    '        if (rules::ringChargeLimitedCount() != 7) ++bad;',
    '        if (!rules::ringIsChargeLimited(2) ||',
    '            !rules::ringIsChargeLimited(7) ||',
    '            !rules::ringIsChargeLimited(10) ||',
    '            !rules::ringIsChargeLimited(11) ||',
    '            !rules::ringIsChargeLimited(17) ||',
    '            !rules::ringIsChargeLimited(18) ||',
    '            !rules::ringIsChargeLimited(22)) ++bad;',
    '        if (rules::ringIsChargeLimited(0) ||',
    '            rules::ringIsChargeLimited(1) ||',
    '            rules::ringIsChargeLimited(3) ||',
    '            rules::ringIsChargeLimited(12) ||',
    '            rules::ringIsChargeLimited(15) ||',
    '            rules::ringIsChargeLimited(23)) ++bad;',
]
chg_new = [
    '        // the charge rows: the seven',
    '        // double-dagger rings (the R255',
    '        // fix: row 9 Mammal Control IN,',
    '        // row 11 Protection OUT)',
    '        if (rules::ringChargeLimitedCount() != 7) ++bad;',
    '        if (!rules::ringIsChargeLimited(2) ||',
    '            !rules::ringIsChargeLimited(7) ||',
    '            !rules::ringIsChargeLimited(9) ||',
    '            !rules::ringIsChargeLimited(10) ||',
    '            !rules::ringIsChargeLimited(17) ||',
    '            !rules::ringIsChargeLimited(18) ||',
    '            !rules::ringIsChargeLimited(22)) ++bad;',
    '        if (rules::ringIsChargeLimited(0) ||',
    '            rules::ringIsChargeLimited(1) ||',
    '            rules::ringIsChargeLimited(3) ||',
    '            rules::ringIsChargeLimited(11) ||',
    '            rules::ringIsChargeLimited(12) ||',
    '            rules::ringIsChargeLimited(15) ||',
    '            rules::ringIsChargeLimited(23)) ++bad;',
]

# ---- patch 7: regtest, the R254 audit NOTE ----
note_old = [
    '        // the double-dagger cross-pins. NOTE: the R223',
    '        // array flags Protection (row 11) instead of',
    '        // Mammal Control (row 9) - the documented',
    '        // divergence, the ranked fix candidate; this',
    '        // audit asserts only the consistent rows',
    '        if (rules::ringIsChargeLimited(7) != 1 ||',
    '            rules::ringIsChargeLimited(10) != 1 ||',
    '            rules::ringChargeLimitedCount() != 7) ++bad;',
]
note_new = [
    '        // the double-dagger cross-pins (the R255',
    '        // fix resolved the R223 divergence: row 9',
    '        // Mammal Control flagged, row 11 Protection',
    '        // not; the rows may now be asserted)',
    '        if (rules::ringIsChargeLimited(7) != 1 ||',
    '            rules::ringIsChargeLimited(9) != 1 ||',
    '            rules::ringIsChargeLimited(10) != 1 ||',
    '            rules::ringIsChargeLimited(11) != 0 ||',
    '            rules::ringChargeLimitedCount() != 7) ++bad;',
]

# ---- patch 8: the gap divergence note flip ----
gap_old = [
    'Wishes. DIVERGENCE FOUND BY',
    'THE GROUND TRUTH BEFORE ANY',
    'PIN (the ranked fix candidate):',
]
gap_new = [
    'Wishes. DIVERGENCE FOUND BY',
    'THE GROUND TRUTH BEFORE ANY',
    'PIN (the ranked fix candidate,',
    'RESOLVED by R255):',
]

# ---- patch 9: the gap log entry ----
tail_old = [
    'Next: R255 the',
    'ringIsChargeLimited fix round',
    '(rings.h + the R223 audit',
    'amendment), then part 3',
    '(~10458-10561, Spell Storing',
    'through X-Ray Vision), then',
    'III.E (part1 ~10948-11067',
    'continuing seamlessly into',
    'part2; global line = part1',
    'line or ~11065 + part2 line,',
    'the TREASURE (MISCELLANEOUS',
    'MAGIC) headers are running',
    'page headers mid-paragraph).',
]
tail_new = [
    'Next: R255 the',
    'ringIsChargeLimited fix round',
    '(rings.h + the R223 audit',
    'amendment), then part 3',
    '(~10458-10561, Spell Storing',
    'through X-Ray Vision), then',
    'III.E (part1 ~10948-11067',
    'continuing seamlessly into',
    'part2; global line = part1',
    'line or ~11065 + part2 line,',
    'the TREASURE (MISCELLANEOUS',
    'MAGIC) headers are running',
    'page headers mid-paragraph).',
    '',
    'R255 landed the',
    'ringIsChargeLimited fix (the',
    'R223 divergence resolved -',
    'DMG p.137 table, upload',
    '~9590-9617: the double-',
    'dagger rows are Djinni',
    'Summoning, Human Influence,',
    'MAMMAL CONTROL, Multiple',
    'Wishes, Telekinesis, Three',
    'Wishes, Wizardry; the',
    'landed array wrongly flagged',
    'Protection row 11 instead of',
    'Mammal Control row 9). Fixed',
    'in rings.h ringIsChargeLimited',
    '(row 9 0->1, row 11 1->0,',
    'count stays 7); the R223',
    'regtest audit (kChg array',
    'swapped; the truthy assert',
    'list now 2/7/9/10/17/18/22;',
    'the negative list gains 11);',
    'the R254 audit NOTE (its',
    'cross-pin if now asserts',
    'rows 9 and 11 directly); the',
    'ringsprose2.h divergence',
    'comments (header banner,',
    'Mammal Control dagger flag,',
    'Protection dagger flag) now',
    'record the resolution; this',
    'gap note flipped. Five',
    'content files with the',
    'splice. No new audit line;',
    'census stays 173. Next: R256',
    '- rings part 3 (~10458-10561:',
    'Spell Storing d4+1 and the',
    'level table, Spell Turning (3',
    'exceptions, the percentile',
    'tables, the 09-or-less/',
    '91-or-more save note),',
    'Swimming (21 inch base, 50',
    'foot dive, 4 rounds),',
    'Telekinesis (the weight',
    'table), Three Wishes (25%',
    'limited), Warmth (+2 saves,',
    '-1 per die), Water Walking,',
    'Weakness (1 point per turn',
    'to 3, the invisible doubling,',
    '5% berserk reversal), Wizardry',
    '(the doubling table), X-Ray',
    'Vision (20 feet, the',
    'penetration depths)), then',
    'III.E (part1 ~10948-11067',
    'continuing seamlessly into',
    'part2; global line = part1',
    'line or ~11065 + part2 line,',
    'the TREASURE (MISCELLANEOUS',
    'MAGIC) headers are running',
    'page headers mid-paragraph).',
]

applied = 0
already = 0

for path, mark, old, new in [
    (RH,  'the rings.h charge array',   rh_old,   rh_new),
    (R2,  'the ringsprose2 banner',      r2a_old,  r2a_new),
    (R2,  'the mammal control comment', r2b_old,  r2b_new),
    (R2,  'the protection comment',     r2c_old,  r2c_new),
    (REG, 'the regtest kChg array',     kchg_old, kchg_new),
    (REG, 'the charge-rows asserts',    chg_old,  chg_new),
    (REG, 'the R254 audit NOTE',        note_old, note_new),
    (GAP, 'the divergence note flip',   gap_old,  gap_new),
    (GAP, 'the R255 log entry',         tail_old, tail_new),
]:
    with open(path) as f:
        text = f.read()
    old_s = NL.join(old)
    new_s = NL.join(new)
    # the idempotence signal is the NEW text
    if new_s in text:
        already += 1
        continue
    if text.count(old_s) == 1:
        text = text.replace(old_s, new_s)
        applied += 1
    else:
        print('R255 FAIL: anchor count is ' + str(text.count(old_s)) + ' for: ' + mark)
        sys.exit(1)
    with open(path, 'w') as f:
        f.write(text)

# post-conditions on the full pass
if applied + already == 9:
    t = open(REG).read()
    if t.count('audit: bad ') != 173:
        print('R255 FAIL: census is not 173')
        sys.exit(1)
    if t.count('R255') != 2:
        print('R255 FAIL: the regtest fix comments must appear twice')
        sys.exit(1)
    h = open(RH).read()
    if h.count('R255') != 1:
        print('R255 FAIL: the rings.h fix comment must appear once')
        sys.exit(1)
    if h.count('        0, 0, 1, 0, 0, 0, 0, 1, 0, 1,') != 1:
        print('R255 FAIL: the fixed rings.h array row is wrong')
        sys.exit(1)
    r2 = open(R2).read()
    if r2.count('R255') != 3:
        print('R255 FAIL: the ringsprose2 resolution comments must appear three times')
        sys.exit(1)
    if 'fix candidate' in r2 or 'fix candidate' in t:
        print('R255 FAIL: stale fix-candidate text survives')
        sys.exit(1)
    g = open(GAP).read()
    if g.count(NL.join(['R255 landed the', 'ringIsChargeLimited fix (the'])) != 1:
        print('R255 FAIL: the R255 log entry is missing')
        sys.exit(1)
    if g.count('RESOLVED by R255') != 1:
        print('R255 FAIL: the divergence note was not flipped')
        sys.exit(1)

print('R255 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R255 note: 9 patches; the ringIsChargeLimited fix - row 9')
print('Mammal Control IN, row 11 Protection OUT; census stays 173.')
print('commit: R255: the ringIsChargeLimited fix - Mammal Control row 9 in, Protection row 11 out (DMG p.137 table; census 173)')

