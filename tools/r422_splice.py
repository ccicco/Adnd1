#!/usr/bin/env python3
# r422_splice: the APPENDIX R
# RESOLUTION, census 347 -> 348.
# The natural follow-up to
# R421/R421b: the clean PDF OCR
# read of the printed p. 109
# (file page 110) resolves the
# five R390 flagged holes in
# rules/uaappendr.h.
#
# 1. The subdual supercedes
#    sentence prints whole
#    ("supersedes previously
#    published material, in
#    particular with regard to
#    the subdual of dragons").
# 2. The vanquishing loser
#    sentence recovers its
#    tail ("must honorably
#    surrender immediately").
# 3. The chaotic constraints
#    line prints whole ("under
#    no constraints
#    whatsoever").
# 4. The monks-druids head
#    resolves ("It is also used
#    by monks and druids
#    seeking to advance to the
#    next level by combat") -
#    the garbled-head flag
#    REPLACES with the resolved
#    pin.
# 5. The disarming scimitar
#    seam confirms as the print
#    itself - the example
#    genuinely names the
#    scimitar, a weapon absent
#    from the six-entry length
#    list (the book's own seam,
#    pinned as printed).
# All seven items now stand
# fully clean; the gap box
# flips; the ledger amends
# (clean 2 -> 7, flagged
# 5 -> 0).
#
# Patches (20):
#   - seed: the R421 record
#   - uaappendr.h: the top
#     comment, the five flag
#     sites, the two ledger
#     entries (8)
#   - regtest.cpp: the R390
#     block comment, the five
#     flag asserts (one
#     replaces, four add the
#     resolved pins), the two
#     ledger asserts, the R422
#     audit block before the
#     R227 anchor (9)
#   - ua_gap_report.md: the
#     Appendix R box flips and
#     takes AMENDED R422 (2)
#
# Guards: the string-literal
# parity gate over the R422
# audit block (the R421b
# lesson), the census 348,
# the flag gone, the FLAG:
# ledger at zero, the
# no-bare-'||' gate (the R418b
# lesson), the header mirror,
# the include line (the R390
# lesson), the gap censuses,
# the seed record, the caller
# contract and the mixed
# applied/already ABORT (the
# R420 lesson).

import io
import re as _re

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
        'R422 splice ABORT: ' + msg)


def pair(path, old, new, label):
    s = rd(path)
    if new in s:
        already.append(label)
        return
    n = s.count(old)
    if n != 1:
        die('%s: old text count %d'
            ' (%r...)'
            % (label, n, old[:60]))
    wr(path, s.replace(old, new))
    applied.append(label)


AR = 'rules/uaappendr.h'
RT = 'regtest.cpp'
GP = 'tools/ua_gap_report.md'
SD = ('doc/vibe/'
      'adnd1_knowledge_seed_v2.md')

# ======== (a) the seed ========

SEED_ENTRY = E(
    '- R421 landed 2026-10-13:',
    '  commits d20e300 + the',
    '  R421b repair 1aa2c2f +',
    '  the cleanup 365ec5b (one',
    '  push, preflight GREEN on',
    '  the repair run), the UA',
    '  IL CANTRIP CAST-TIMES',
    '  RESOLUTION (book pp. 65-66',
    '  + the p. 31 column read) -',
    '  the PDF read resolves the',
    '  eight casting-time cells',
    '  (colored lights, dim, haze',
    '  and mirage at 1/2; rainbow',
    '  at 1/3; mask, noise and',
    '  the two-d-lusion at 1/8 -',
    '  the census 4/1/3, the',
    '  2..10 band holds), the',
    '  mirage and two-d-lusion',
    '  school cells and areas,',
    '  the mirage somatic tail,',
    '  the colored-lights',
    '  reflection sentence and',
    '  the R342 IL cantrip column',
    '  (the eight names,',
    '  cross-checked against the',
    '  description roster row for',
    '  row); the IL cantrip',
    '  descriptions stand',
    '  hole-free, the gap box',
    '  flips, census 346 -> 347.',
    '  DEFECT SHIPPED in d20e300',
    '  (the push aborted): the',
    '  R421 audit printf carried',
    '  an unterminated string',
    '  literal (the R418 pattern);',
    '  R421b heals it (one patch,',
    '  census stays 347) and lands',
    '  the standing string-literal',
    '  parity gate; the cleanup',
    '  commit removes the stray',
    '  "347" artifact. The ./nn',
    '  save hash diverged -',
    '  benign (23rd occurrence);',
    '  the md5 stays advisory.')

ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R421 landed 2026-10-13' in s:
    already.append('seed: the R421 record')
elif s.count(ANCH) != 1:
    die('the seed maintenance head')
else:
    s = s.replace(ANCH, NL + SEED_ENTRY
                 + ANCH)
    wr(SD, s)
    applied.append('seed: the R421 record')

# ======== (b) rules/uaappendr.h ========

# the top comment bullet
pair(AR,
     E('// holes (the subdual supercedes',
       '// sentence, the vanquishing',
       '// loser sentence, the chaotic',
       '// constraints line, the',
       '// monks-druids garble head, the',
       '// disarming scimitar seam).',
       '// Nothing fully garbles - the',
       '// recoverable tails pin, the',
       '// destroyed heads flag.'),
     E('// holes (the subdual supercedes',
       '// sentence, the vanquishing',
       '// loser sentence, the chaotic',
       '// constraints line, the',
       '// monks-druids garble head, the',
       '// disarming scimitar seam) -',
       '// RESOLVED (R422): the clean',
       '// p. 109 read resolves the four',
       '// garbles and confirms the',
       '// scimitar seam as the print',
       '// itself; all seven items now',
       '// stand fully clean.',
       '// Nothing garbles - the R422',
       '// read resolves every hole.'),
     'ar: the top comment')

# flag site 1: the supercedes
# sentence
pair(AR,
     E("// FLAG: the print splits",
       "// 'super-/previously published'",
       '// - the requirements and',
       '// effects of subdual under',
       '// this section supercede the',
       '// previously published',
       '// material.',
       'inline bool uanlSubdualSupercedes'
       'Published()',
       '    { return true; }'),
     E('// The requirements and effects',
       '// of subdual under this',
       '// section supercede the',
       '// previously published',
       '// material - RESOLVED (R422):',
       '// the clean p. 109 read gives',
       '// the whole sentence; the',
       '// print never splits.',
       'inline bool uanlSubdualSupercedes'
       'Published()',
       '    { return true; }',
       '// The supercedes sentence',
       '// prints clean - the R422',
       '// resolved read.',
       'inline bool uanlSubdualSupercedes'
       'ReadsClean()',
       '    { return true; }'),
     'ar: the supercedes sentence')

# flag site 2: the vanquishing
# loser sentence
pair(AR,
     E('// FLAG: the print garbles',
       "// 'reduced to0 hit points, he'",
       '// - reduced to 0 hit points',
       '// makes the loser; the',
       "// 'must' tail garbles.",
       'inline bool uanlVanqLoserAtZeroHp()',
       '    { return true; }'),
     E('// Reduced to 0 hit points',
       '// makes the loser - RESOLVED',
       '// (R422): the clean p. 109',
       '// read gives the whole',
       '// sentence, the tail',
       '// included.',
       'inline bool uanlVanqLoserAtZeroHp()',
       '    { return true; }',
       '// The loser must honorably',
       '// surrender immediately -',
       '// the R422 resolved tail.',
       'inline bool uanlVanqLoserMust'
       'HonorablySurrender()',
       '    { return true; }'),
     'ar: the loser sentence')

# flag site 3: the chaotic
# constraints line
pair(AR,
     E('// FLAG: the print garbles the',
       "// 're under no con-straints'",
       '// line - chaotic evil',
       '// opponents see no problem',
       '// striking after lowering',
       '// defenses.',
       'inline bool uanlVanqChaoticEvil'
       'NoConstraints()',
       '    { return true; }'),
     E('// Chaotic creatures are under',
       '// no constraints whatsoever;',
       '// chaotic evil opponents see',
       '// no problem striking after',
       '// lowering defenses - RESOLVED',
       '// (R422): the clean p. 109',
       '// read gives the whole line.',
       'inline bool uanlVanqChaoticEvil'
       'NoConstraints()',
       '    { return true; }',
       '// The chaotic constraints line',
       '// prints clean - the R422',
       '// resolved read.',
       'inline bool uanlVanqChaoticLine'
       'ReadsClean()',
       '    { return true; }'),
     'ar: the chaotic line')

# flag site 4: the monks-druids
# head - the flag REPLACES with
# the resolved pin
pair(AR,
     E('// FLAG: the print garbles the',
       '// sentence head (the monks',
       '// and druids stretch) - the',
       '// usage context recovers only',
       '// in part.',
       'inline bool uanlVanqMonksDruids'
       'GarbleHead()',
       '    { return true; }',
       '// Used seeking to advance to',
       '// the next level by combat',
       '// (the legible tail of the',
       '// garbled sentence).'),
     E('// Used by monks and druids',
       '// seeking to advance to the',
       '// next level by combat -',
       '// RESOLVED (R422): the clean',
       '// p. 109 read gives the whole',
       '// sentence, head included',
       '// (the garbled-head flag',
       '// comes off).',
       'inline bool uanlVanqUsedByMonks'
       'AndDruids()',
       '    { return true; }',
       '// Used seeking to advance to',
       '// the next level by combat',
       '// (the tail, now clean).'),
     'ar: the monks-druids head')

# flag site 5: the disarming
# scimitar seam
pair(AR,
     E('// FLAG: the scimitar example',
       '// names a weapon not in the',
       '// listed disarm weapons - a',
       '// print seam, pinned as',
       '// print.',
       'inline bool uanlDisarmScimitar'
       'Seam()',
       '    { return true; }'),
     E('// The scimitar example names',
       '// a weapon not in the listed',
       '// disarm weapons - the',
       "// book's own seam. RESOLVED",
       '// (R422): the clean p. 109',
       '// read confirms the print',
       '// genuinely says "a scimitar',
       '// may disarm someone with a',
       '// mace" - pinned as printed.',
       'inline bool uanlDisarmScimitar'
       'Seam()',
       '    { return true; }',
       '// The scimitar seam is the',
       '// print itself - the R422',
       '// resolved read.',
       'inline bool uanlDisarmScimitar'
       'SeamIsPrint()',
       '    { return true; }'),
     'ar: the scimitar seam')

# the ledger: the clean count
pair(AR,
     E('// Two fully clean (the subdual',
       '// eligibility, the subdual',
       '// damage accounting).',
       'inline int uanlPartCleanCount()',
       '    { return 2; }'),
     E('// All seven items fully clean -',
       '// RESOLVED (R422): the five',
       '// flagged holes resolve with',
       '// the clean p. 109 read (the',
       '// original two fully clean:',
       '// the subdual eligibility,',
       '// the subdual damage',
       '// accounting).',
       'inline int uanlPartCleanCount()',
       '    { return 7; }'),
     'ar: the clean count')

# the ledger: the flagged count
pair(AR,
     E('// Five mechanics-clean with',
       '// flagged holes (the subdual',
       '// supercedes sentence, the',
       '// vanquishing loser sentence,',
       '// the chaotic constraints line,',
       '// the monks-druids garble',
       '// head, the disarming scimitar',
       '// seam).',
       'inline int uanlPartFlaggedCount()',
       '    { return 5; }'),
     E('// Zero flagged holes remain -',
       '// RESOLVED (R422): the clean',
       '// p. 109 read resolves the',
       '// subdual supercedes sentence,',
       '// the vanquishing loser',
       '// sentence, the chaotic',
       '// constraints line and the',
       '// monks-druids head, and',
       '// confirms the disarming',
       '// scimitar seam as the print.',
       'inline int uanlPartFlaggedCount()',
       '    { return 0; }'),
     'ar: the flagged count')

# ======== (c) regtest.cpp ========

# the R390 block comment
pair(RT,
     E('    // five mechanics-clean with',
       '    // flagged holes (the subdual',
       '    // supercedes sentence, the',
       '    // vanquishing loser sentence,',
       '    // the chaotic constraints',
       '    // line, the monks-druids',
       '    // garble head, the disarming',
       '    // scimitar seam); the R159'),
     E('    // five mechanics-clean with',
       '    // flagged holes (the subdual',
       '    // supercedes sentence, the',
       '    // vanquishing loser sentence,',
       '    // the chaotic constraints',
       '    // line, the monks-druids',
       '    // garble head, the disarming',
       '    // scimitar seam) - RESOLVED',
       '    // (R422): the clean p. 109',
       '    // read resolves all five;',
       '    // the R159'),
     'regtest: the R390 block comment')

# assert 1: the supercedes
# resolved pin
pair(RT,
     '            if (!uanlSubdual'
     'SupercedesPublished()) ++bad;',
     E('            if (!uanlSubdual'
       'SupercedesPublished()) ++bad;',
       '            if (!uanlSubdual'
       'SupercedesReadsClean()) ++bad;'),
     'regtest: the supercedes pin')

# assert 2: the loser resolved
# tail pin
pair(RT,
     '            if (!uanlVanqLoser'
     'AtZeroHp()) ++bad;',
     E('            if (!uanlVanqLoser'
       'AtZeroHp()) ++bad;',
       '            if (!uanlVanqLoser'
       'MustHonorablySurrender())'
       ' ++bad;'),
     'regtest: the loser pin')

# assert 3: the chaotic resolved
# pin
pair(RT,
     '            if (!uanlVanqChaotic'
     'EvilNoConstraints()) ++bad;',
     E('            if (!uanlVanqChaotic'
       'EvilNoConstraints()) ++bad;',
       '            if (!uanlVanqChaotic'
       'LineReadsClean()) ++bad;'),
     'regtest: the chaotic pin')

# assert 4: the monks-druids
# flag assert REPLACES
pair(RT,
     '            if (!uanlVanqMonks'
     'DruidsGarbleHead()) ++bad;',
     '            if (!uanlVanqUsedBy'
     'MonksAndDruids()) ++bad;',
     'regtest: the monks-druids pin')

# assert 5: the scimitar
# resolved pin
pair(RT,
     '            if (!uanlDisarm'
     'ScimitarSeam()) ++bad;',
     E('            if (!uanlDisarm'
       'ScimitarSeam()) ++bad;',
       '            if (!uanlDisarm'
       'ScimitarSeamIsPrint()) ++bad;'),
     'regtest: the scimitar pin')

# the ledger asserts
pair(RT,
     '            if (uanlPartClean'
     'Count() != 2) ++bad;',
     '            if (uanlPartClean'
     'Count() != 7) ++bad;',
     'regtest: the clean assert')

pair(RT,
     '            if (uanlPartFlagged'
     'Count() != 5) ++bad;',
     '            if (uanlPartFlagged'
     'Count() != 0) ++bad;',
     'regtest: the flagged assert')

# ---- the R422 audit block ----
AUD = E(
    '    // ---- R422: the appendix R',
    '    // resolution pin audit ----',
    '    // The clean p. 109 read',
    '    // resolves the five R390',
    '    // flagged holes: the subdual',
    '    // supercedes sentence prints',
    '    // whole ("supersedes',
    '    // previously published',
    '    // material, in particular',
    '    // with regard to the subdual',
    '    // of dragons"); the',
    '    // vanquishing loser sentence',
    '    // recovers its tail ("must',
    '    // honorably surrender',
    '    // immediately"); the chaotic',
    '    // constraints line prints',
    '    // whole ("under no constraints',
    '    // whatsoever"); the',
    '    // monks-druids head resolves',
    '    // ("It is also used by monks',
    '    // and druids seeking to',
    '    // advance to the next level by',
    '    // combat"); and the disarming',
    '    // scimitar seam confirms as',
    '    // the print itself - the',
    '    // example genuinely names the',
    '    // scimitar, a weapon absent',
    '    // from the six-entry length',
    '    // list (the book\'s own seam,',
    '    // pinned as printed). All',
    '    // seven items now stand fully',
    '    // clean; census 347 -> 348.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        if (!uanlSubdualSupercedes'
    'ReadsClean()',
    '                || !uanlVanqLoser'
    'MustHonorablySurrender()',
    '                || !uanlVanqChaotic'
    'LineReadsClean()',
    '                || !uanlVanqUsedBy'
    'MonksAndDruids()',
    '                || !uanlDisarm'
    'ScimitarSeamIsPrint())',
    '            ++bad;',
    '        if (uanlPartItemTotal() != 7',
    '                || uanlPartClean'
    'Count() != 7',
    '                || uanlPartFlagged'
    'Count() != 0',
    '                || uanlPartGarbled'
    'Count() != 0)',
    '            ++bad;',
    '        if (uanlPartCleanCount()',
    '                + uanlPartFlagged'
    'Count()',
    '                + uanlPartGarbled'
    'Count()',
    '                != uanlPart'
    'ItemTotal())',
    '            ++bad;',
    '        if (!uanlSubdualSupercedes'
    'Published()',
    '                || !uanlSubdual'
    'SupercedesDragonSubdual()',
    '                || !uanlVanqLoser'
    'AtZeroHp()',
    '                || !uanlVanqChaotic'
    'EvilNoConstraints()',
    '                || !uanlDisarm'
    'ScimitarSeam())',
    '            ++bad;',
    '        printf("R422 UA appendix R'
    ' resolution pin audit: bad'
    ' %d' + chr(92) + 'n", bad);',
    '        if (bad) return 1;',
    '    }')

R227 = ('    // ---- R227: the wis mental'
        ' save wiring audit ----')
pair(RT, R227, AUD + NL + R227,
     'regtest: the R422 audit block')

# ======== (d) tools/ua_gap_report.md ========

pair(GP,
     '- [ ] **Appendix R: non-lethal'
     ' combat**',
     '- [x] **Appendix R: non-lethal'
     ' combat**',
     'gap: the Appendix R box flips')

pair(GP,
     E('        dial precedent), the R389',
       '        seam the System II',
       '        weaponless layer, stays',
       '        PDF-gated only.',
       '- [ ] **Appendix S: non-human'
       ' deities**'),
     E('        dial precedent), the R389',
       '        seam the System II',
       '        weaponless layer, stays',
       '        PDF-gated only.',
       '      - AMENDED R422: the clean',
       '        p. 109 read resolves the',
       '        five flagged holes - the',
       '        subdual supercedes',
       '        sentence, the vanquishing',
       '        loser sentence, the',
       '        chaotic constraints line',
       '        and the monks-druids head',
       '        print whole; the',
       '        disarming scimitar seam',
       '        confirms as the print',
       '        itself (the example names',
       '        a weapon absent from the',
       '        list - the book\'s own',
       '        seam, pinned as',
       '        printed); all seven',
       '        items fully clean, the',
       '        box flips.',
       '- [ ] **Appendix S: non-human'
       ' deities**'),
     'gap: the AMENDED R422 stratum')

# ======== the verify pass ========

if applied and already:
    die('the mixed applied/already'
        ' state (the R420 lesson)')

s = rd(RT)
if s.count('audit: bad') != 348:
    die('the census %d'
        % s.count('audit: bad'))
if s.count('R422 UA appendix R'
           ' resolution') != 1:
    die('the R422 audit label')

# the string-literal parity gate
# (the R421b lesson): no CODE
# line in the R422 audit block
# may carry an unterminated
# string literal (comment lines
# may hold lone quotes)
for ln in AUD.split(NL):
    c = ln.lstrip()
    if (c and not c.startswith('//')
            and ln.count(chr(34)) % 2):
        die('the R422 audit block has'
            ' an unterminated string'
            ' literal')

# the flag is gone - everywhere
for flag in ('uanlVanqMonksDruids'
             'GarbleHead',):
    if s.count(flag):
        die('the %s flag survives in'
            ' regtest' % flag)
    if flag in rd(AR):
        die('the %s flag survives in'
            ' the header' % flag)

# the no-bare-|| gate (the R418b
# lesson): no uanl chain may BEGIN
# with '||' - a '||' line is legal
# only inside an open chain
prev = ''
for ln in s.split(NL):
    if ('uanl' in ln
            and ln != prev
            and _re.match(r'^ +\|\| ', ln)
            and (prev.rstrip().endswith(';')
                 or not prev.strip()
                 or prev.lstrip()
                 .startswith('//'))):
        die('a bare || uanl line')
    prev = ln

# the header mirror: the ledger
# and the five resolved pins
h = rd(AR)
if h.count('FLAG:'):
    die('the header still flags %d'
        % h.count('FLAG:'))
for pin in ('uanlSubdualSupercedes'
            'ReadsClean',
            'uanlVanqLoserMust'
            'HonorablySurrender',
            'uanlVanqChaoticLine'
            'ReadsClean',
            'uanlVanqUsedByMonks'
            'AndDruids',
            'uanlDisarmScimitar'
            'SeamIsPrint'):
    if pin not in h:
        die('the %s pin missing from'
            ' the header' % pin)
    if pin not in s:
        die('the %s pin missing from'
            ' regtest' % pin)
if (h.count('uanlPartCleanCount()'
            + NL + '    { return 7; }')
        != 1):
    die('the header clean mirror')
if (h.count('uanlPartFlaggedCount()'
            + NL + '    { return 0; }')
        != 1):
    die('the header flagged mirror')

# the include line (the R390
# lesson): the uaappendr include
# comment must stay whole
if s.count('#include "rules/uaappendr.h"'
          '  // R390: the UA non-lethal'
          ' combat') != 1:
    die('the uaappendr include line')

# the statics: no header line
# over 78 columns
for ln in h.split(NL):
    if len(ln) > 78:
        die('the header line %d long'
            % len(ln))

# the header inline count: 85
# - 1 (the deleted flag) + 5
# (the new pins) = 89
if h.count('inline ') != 89:
    die('the header inline count %d'
        % h.count('inline '))

# the gap censuses: 100 closed,
# five open lines - four boxes
# (Appendix S, Appendix T; the two
# logging layers stay out by the
# user decision) plus the legend
g = rd(GP)
if ('- [x] **Appendix R: non-lethal'
    ' combat**') not in g:
    die('the Appendix R box still'
        ' open')
if g.count(chr(10) + '- [x]') != 100:
    die('the gap closed count %d'
        % g.count(chr(10) + '- [x]'))
opens = [l for l in g.split(NL)
         if l.startswith('- [ ]')]
if len(opens) != 5:
    die('the gap open count %d'
        % len(opens))

# the seed record
if 'R421 landed 2026-10-13' not in rd(SD):
    die('the seed R421 record')

# the caller contract: no engine
# caller touches the uanl pins
for path in ('dm/treasure.cpp',
             'game/state_combat.cpp'):
    if _re.search(r'\buanl\w', rd(path)):
        die('%s calls the uanl pins'
            ' early' % path)

print('R422 splice: ALL OK'
      ' (applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the appendix R'
      ' resolution - the clean')
print('  p. 109 read resolves the'
      ' five R390 flagged holes')
print('  (the subdual supercedes'
      ' sentence, the vanquishing')
print('  loser sentence, the chaotic'
      ' constraints line and the')
print('  monks-druids head print'
      ' whole; the disarming')
print('  scimitar seam confirms as'
      ' the print itself); all')
print('  seven items fully clean,'
      ' the gap box flips; census')
print('  347 -> 348')
print('commit: R422: the appendix R'
      ' resolution (census 348)')

