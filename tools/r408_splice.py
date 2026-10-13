#!/usr/bin/env python3
# R408: the UA p. 26 ARMOR
# CLASS TABLE - the composite
# ladder pinned directly. The
# R392 manifest closed the
# item by derivation (the
# R371 pin + the R191 seam);
# this round pins the 11
# printed rows as printed
# and closes the two STALE
# DUPLICATE boxes the R392
# pass missed in the weapons
# section checklist. The
# cross-check round also
# re-verifies the R392
# equipment-costs pins
# against the independent
# djvu scan (the PDF was the
# R392 source; the scan
# agrees cell for cell).
#
# 1. rules/uaac26.h (NEW,
#    prefix uacr, 8 inline
#    functions): the 11
#    composite rows (AC 10
#    down to 0, the printed
#    armor-set description
#    and the member count
#    per row; 28 composites
#    total), cross-checked
#    live against the R191
#    ladder (armorRatingAc,
#    armorRatingShieldStep),
#    the R371 bronze AC (4 =
#    one worse than plate
#    mail), and the R392
#    equipment costs (the
#    four armor rows, the
#    spot arms rows).
# 2. regtest.cpp: the
#    include rides the R392
#    equipment include; the
#    R408 audit block lands
#    before the R227 anchor -
#    the ladder rows pin, the
#    shield composites read
#    base minus the step, the
#    bronze read cross-checks
#    R371, the equipment costs
#    cross-check R392 live;
#    census 334 -> 335.
# 3. tools/ua_gap_report.md:
#    the two stale boxes
#    (the Armor Class Table,
#    the Equipment and
#    Supplies Costs table)
#    take AMENDED R408 notes
#    and close - the R392
#    manifest closures plus
#    the new direct pin.
# 4. The seed takes the R407
#    record.
import io
import os

NL = chr(10)

applied = []
already = []


def rd(p):
    with io.open(p, encoding='utf-8') as f:
        return f.read()


def wr(p, s):
    with io.open(p, 'w', encoding='utf-8') as f:
        f.write(s)


def E(*lines):
    return NL.join(lines)


def die(msg):
    raise SystemExit(
        'R408 splice ABORT: ' + msg)


def pair(path, old, new, label):
    s = rd(path)
    if new in s:
        already.append(label)
        return
    n = s.count(old)
    if n != 1:
        die('%s: old text count %d (%r...)'
            % (label, n, old[:60]))
    wr(path, s.replace(old, new))
    applied.append(label)


def newfile(path, body, label):
    if os.path.exists(path):
        already.append(label)
        return
    wr(path, body)
    applied.append(label)


# ========= (a) the seed record =========
SD = 'doc/vibe/' \
     'adnd1_knowledge_seed_v2.md'

SEED_ENTRY = E(
    '- R407 landed 2026-10-13:',
    '  commit a3570fb (census 334,',
    '  preflight GREEN), the UA',
    '  Appendix S clerical charts -',
    '  rules/uascharts.h (prefix usc)',
    '  - the five 8-column charts,',
    '  23 rows, the 13 sacred',
    '  animals, the gender reads,',
    '  the frequency catches. The',
    '  chart item CLOSES; Appendix',
    '  S stays open on the class',
    '  lines, MOVE, stat lines,',
    '  prose. The ./nn save hash',
    '  diverged for the fifteenth',
    '  round running - benign; the',
    '  md5 stays advisory.')
ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R407 landed 2026-10-13' in s:
    already.append('seed: the R407 record')
elif s.count(ANCH) != 1:
    die('the seed maintenance head')
else:
    s = s.replace(ANCH, NL + SEED_ENTRY
                  + ANCH)
    wr(SD, s)
    applied.append('seed: the R407 record')
s = rd(SD)
if s.count('R407 landed 2026-10-13') != 1:
    die('the R407 seed entry count')
if s.count('## Knowledge maintenance') != 1:
    die('the seed maintenance head')

# ========= (b) rules/uaac26.h =========
AC = 'rules/uaac26.h'

ACBODY = E(
    '// ===========================================================================',
    '// Adnd1 - rules/uaac26.h',
    '// The UA ARMOR CLASS TABLE (p. 26),',
    '// R408: the 11 composite rows AC 10',
    '// down to 0, pinned directly from',
    '// the print. The R392 manifest',
    '// closed the item by derivation',
    '// (the R371 pin pp. 75-76 + the',
    '// R191 seam); this round pins the',
    '// printed rows as printed and',
    '// closes the two stale duplicate',
    '// boxes the R392 pass missed in',
    '// the weapons section checklist.',
    '//',
    '// The print (the clean djvu scan,',
    '// agreeing with the R392 PDF read):',
    '//   10: none;',
    '//    9: shield only;',
    '//    8: leather armor or padded',
    '//       armor;',
    '//    7: leather + shield, padded +',
    '//       shield, studded leather,',
    '//       ring mail;',
    '//    6: studded leather + shield,',
    '//       ring mail + shield, scale',
    '//       mail;',
    '//    5: scale mail + shield, chain',
    '//       mail, elfin chain mail;',
    '//    4: chain mail + shield, elfin',
    '//       chain + shield, splint',
    '//       mail, banded mail, bronze',
    '//       plate mail;',
    '//    3: splint mail + shield,',
    '//       banded mail + shield,',
    '//       bronze plate mail + shield,',
    '//       plate mail;',
    '//    2: plate mail + shield or',
    '//       field plate armor;',
    '//    1: field plate armor + shield',
    '//       or full plate armor;',
    '//    0: full plate armor + shield.',
    '// 28 composites across the 11 rows.',
    '//',
    '// The cross-checks run live:',
    '//   - the type rows read',
    '//     armorRatingAc (the R191',
    '//     ladder): leather 8, chain 5,',
    '//     plate mail 3;',
    '//   - the shield composites read',
    '//     base minus',
    '//     armorRatingShieldStep (the',
    '//     leather 8 with shield 7, the',
    '//     scale 6 with shield 5, the',
    '//     full plate 1 with shield 0);',
    '//   - the bronze plate mail reads 4,',
    '//     one worse than plate mail 3 -',
    '//     the R371 description pin;',
    '//   - the R392 equipment costs',
    '//     re-verify against the scan:',
    '//     bronze plate 100 gp, full',
    '//     plate 4000 gp, field plate',
    '//     2000 gp, the buckler 5 gp.',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    '// The row count (AC 10 down to 0).',
    'inline int uacrRowCount()',
    '    { return 11; }',
    '',
    '// The i-th row armor class',
    '// (10 - i).',
    'inline int uacrRowAc(int i)',
    '    { return 10 - i; }',
    '',
    '// The i-th row armor-set',
    '// description, as printed.',
    'inline const char* uacrRowSet(int i) {',
    '    static const char* const k[11] = {',
    '        "none",',
    '        "shield only",',
    '        "leather armor or padded armor",',
    '        "leather + shield, padded + shield,'
    ' studded leather, ring mail",',
    '        "studded leather + shield, ring mail'
    ' + shield, scale mail",',
    '        "scale mail + shield, chain mail,'
    ' elfin chain mail",',
    '        "chain mail + shield, elfin chain"',
    '        " + shield, splint mail, banded"',
    '        " mail, bronze plate mail",',
    '        "splint mail + shield, banded mail"',
    '        " + shield, bronze plate mail"',
    '        " + shield, plate mail",',
    '        "plate mail + shield or field plate'
    ' armor",',
    '        "field plate armor + shield or full'
    ' plate armor",',
    '        "full plate armor + shield",',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 10) i = 10;',
    '    return k[i];',
    '}',
    '',
    '// The composite count per row:',
    '// 1, 1, 2, 4, 3, 3, 5, 4, 2, 2, 1 -',
    '// 28 total.',
    'inline int uacrRowMemberCount(int i) {',
    '    static const int k[11] = {',
    '        1, 1, 2, 4, 3, 3, 5, 4, 2, 2, 1',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 10) i = 10;',
    '    return k[i];',
    '}',
    '',
    '// The total composite count (28).',
    'inline int uacrCompositeCount()',
    '    { return 28; }',
    '',
    '// True when the row reads a shield',
    '// composite member (rows 3-10 carry',
    '// at least one; rows 0-2 none).',
    'inline bool uacrRowHasShieldMember(int i) {',
    '    return i >= 3;',
    '}',
    '',
    '}   // namespace rules',
    '')
newfile(AC, ACBODY + NL,
        'the p. 26 AC table header')

# ========= (c) regtest.cpp =========
RT = 'regtest.cpp'

pair(RT,
     '#include "rules/uaequip26.h"  '
     '// R392: the UA equipment costs',
     E(
    '#include "rules/uaequip26.h"  '
    '// R392: the UA equipment costs',
    '#include "rules/uaac26.h"  '
    '// R408: the UA p. 26 AC table'),
     'regtest: the AC table include')

AUD = E(
    '    // ---- R408: the UA p. 26 armor',
    '    // class table pin audit ----',
    '    // The composite ladder pins',
    '    // directly: the 11 rows AC 10 to',
    '    // 0, the printed armor sets, the',
    '    // 28 composites; the type rows',
    '    // cross-check the R191 ladder',
    '    // live, the shield composites',
    '    // read base minus the step, the',
    '    // bronze read cross-checks the',
    '    // R371 pin, and the R392',
    '    // equipment costs re-verify',
    '    // against the independent scan;',
    '    // the two stale boxes close;',
    '    // census 334 -> 335.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // ---- the ladder ----',
    '        if (uacrRowCount() != 11) ++bad;',
    '        if (uacrRowAc(0) != 10',
    '                || uacrRowAc(5) != 5',
    '                || uacrRowAc(10) != 0)',
    '            ++bad;',
    '        if (strcmp(uacrRowSet(0), "none") != 0)',
    '            ++bad;',
    '        if (strcmp(uacrRowSet(1),',
    '                   "shield only") != 0)',
    '            ++bad;',
    '        if (strcmp(uacrRowSet(10),',
    '                   "full plate armor + shield")',
    '                != 0)',
    '            ++bad;',
    '        if (uacrRowMemberCount(0) != 1',
    '                || uacrRowMemberCount(3) != 4',
    '                || uacrRowMemberCount(6) != 5',
    '                || uacrRowMemberCount(10) != 1)',
    '            ++bad;',
    '        // the composites add up',
    '        if (uacrRowMemberCount(0)',
    '                + uacrRowMemberCount(1)',
    '                + uacrRowMemberCount(2)',
    '                + uacrRowMemberCount(3)',
    '                + uacrRowMemberCount(4)',
    '                + uacrRowMemberCount(5)',
    '                + uacrRowMemberCount(6)',
    '                + uacrRowMemberCount(7)',
    '                + uacrRowMemberCount(8)',
    '                + uacrRowMemberCount(9)',
    '                + uacrRowMemberCount(10)',
    '                != uacrCompositeCount()) ++bad;',
    '        if (uacrCompositeCount() != 28) ++bad;',
    '        if (!uacrRowHasShieldMember(3)',
    '                || !uacrRowHasShieldMember(10)',
    '                || uacrRowHasShieldMember(0)',
    '                || uacrRowHasShieldMember(2))',
    '            ++bad;',
    '        // ---- the R191 cross-checks ----',
    '        // the type rows read the ladder',
    '        if (uacrRowAc(2) != armorRatingAc(3))',
    '            ++bad;',
    '        if (uacrRowAc(4) != armorRatingAc(6))',
    '            ++bad;',
    '        if (uacrRowAc(5) != armorRatingAc(7))',
    '            ++bad;',
    '        if (uacrRowAc(7) != armorRatingAc(10))',
    '            ++bad;',
    '        // the shield composites read base',
    '        // minus the step: leather 8 with',
    '        // shield 7, scale 6 with shield 5,',
    '        // full plate 1 with shield 0',
    '        if (uacrRowAc(2)',
    '                - armorRatingShieldStep()',
    '                != uacrRowAc(3)) ++bad;',
    '        if (uacrRowAc(4)',
    '                - armorRatingShieldStep()',
    '                != uacrRowAc(5)) ++bad;',
    '        if (uacrRowAc(8)',
    '                - armorRatingShieldStep()',
    '                != uacrRowAc(9)) ++bad;',
    '        if (uacrRowAc(9)',
    '                - armorRatingShieldStep()',
    '                != uacrRowAc(10)) ++bad;',
    '        // ---- the R371 bronze read ----',
    '        if (uaarmBronzeAc() != 4) ++bad;',
    '        if (uaarmBronzeAc()',
    '                != armorRatingAc(7) - 1)',
    '            ++bad;',
    '        // the bronze plate mail composite',
    '        // reads row 4, its shield row 3',
    '        if (uaarmBronzeAc() != uacrRowAc(6))',
    '            ++bad;',
    '        if (uaarmBronzeAc()',
    '                - armorRatingShieldStep()',
    '                != uacrRowAc(7)) ++bad;',
    '        // ---- the R392 equipment costs ----',
    '        // the scan re-verifies the pins:',
    '        // bronze 100, full 4000, field',
    '        // 2000, the buckler 5',
    '        if (uaecArmorCount() != 4) ++bad;',
    '        if (uaecArmorCost(0) != 100',
    '                || uaecArmorCost(1) != 4000',
    '                || uaecArmorCost(2) != 2000',
    '                || uaecArmorCost(3) != 5)',
    '            ++bad;',
    '        if (uaecArmsCount() != 19) ++bad;',
    '        if (uaecArmsCost(0) != 2',
    '                || uaecArmsCost(5) != 300',
    '                || uaecArmsCost(6) != 100)',
    '            ++bad;',
    '        if (uaecArmsPriceIsSilver(11)',
    '                != true) ++bad;',
    '        printf("R408 UA armor class table'
    ' pin audit: bad %d' + chr(92) + 'n", bad);',
    '        if (bad) return 1;',
    '    }')

R227 = ('    // ---- R227: the wis mental'
        ' save wiring audit ----')
pair(RT, R227, AUD + NL + R227,
     'regtest: the R408 audit block')

# ======== (d) tools/ua_gap_report.md ========
GP = 'tools/ua_gap_report.md'

pair(GP, E(
    '- [ ] **The Armor Class Table** (p. 26)',
    '      - the expanded AC-by-armor table.'),
    E(
    '- [x] **The Armor Class Table** (p. 26)',
    '      - CLOSED R408 (rules/uaac26.h;',
    '      the R408 armor class table pin',
    '      audit, census 335): the 11',
    '      composite rows pin directly',
    '      from the print (AC 10 to 0, the',
    '      printed armor sets, the 28',
    '      composites) - cross-checked',
    '      live against the R191 ladder,',
    '      the R371 bronze AC and the',
    '      R392 equipment costs. This',
    '      box was a stale duplicate of',
    '      the R392 manifest closure; the',
    '      direct pin now backs it.'),
    'gap: the AC table box closes')

pair(GP, E(
    '- [ ] **The Equipment and Supplies',
    '      Costs table** (p. 26).'),
    E(
    '- [x] **The Equipment and Supplies',
    '      Costs table** (p. 26) - CLOSED',
    '      R392 (rules/uaequip26.h) and',
    '      re-verified R408 against the',
    '      independent djvu scan (the',
    '      R408 audit cross-checks the',
    '      four armor rows and the arms',
    '      rows live). This box was a',
    '      stale duplicate of the R392',
    '      manifest closure.'),
    'gap: the equipment costs box closes')

# ============ the final verification ============
s = rd(RT)
if s.count('audit: bad') != 335:
    die('the census %d' % s.count('audit: bad'))
if s.count('R408 UA armor class table'
           ' pin audit') != 1:
    die('the R408 audit label')
if s.count('uacrRow') < 15:
    die('the uacr call count %d'
        % s.count('uacrRow'))

p = rd(AC)
if p.count('inline') != 6:
    die('the AC table inline count %d'
        % p.count('inline'))
if not p.endswith(NL):
    die('the AC table trailing newline')

g = rd(GP)
if g.count('CLOSED R408') != 1:
    die('the gap closed count %d'
        % g.count('CLOSED R408'))

for path, mark in ((AC, 'uacrRowAc'),
                   (RT, 'uacrRowCount'),
                   (SD, 'R407 landed')):
    if mark not in rd(path):
        die('%s carries no R408 round' % path)

# the contract: no engine caller
import re as _re
for path in ('dm/treasure.cpp',
             'game/state_combat.cpp'):
    if _re.search(r'\\buacr', rd(path)):
        die('%s calls the pins early'
            % path)

print('R408 splice: ALL OK'
      ' (applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the p. 26 armor class table')
print('  pins - 11 composite rows, 28')
print('  composites, the R191/R371/R392')
print('  cross-checks live; the two')
print('  stale duplicate boxes close;')
print('  census 334 -> 335')
print('commit: R408: the UA p. 26 armor'
      ' class table (census 335)')

