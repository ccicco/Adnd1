#!/usr/bin/env python3
# r424_splice: the APPENDIX T
# RESOLUTION, census 349 -> 350.
# The LAST open book-content
# box in the UA gap report -
# the five R391 flagged holes
# in rules/uaappendt.h (the
# pp. 123-129 stretch) resolve
# with the clean OCR read
# (pages 124, 127, 128, 129 =
# printed 123, 126, 127, 128):
#   - the classification system
#     paragraph prints whole
#     ("a system of
#     classification and
#     nomenclature is presented
#     here that seems both
#     reasonable and easy to
#     use" - the "reasonable"
#     line included);
#   - the fauchard description
#     prints whole (the scythe/
#     sickle development, the
#     cut-and-thrust that did
#     neither too well, the
#     little parrying, the
#     no-dismount early form,
#     the later back hook, the
#     quick passing, the
#     fauchard-fork remaining);
#   - the Lucern/bec comparison
#     tail prints whole ("for
#     the latter weapon was not
#     so specialized");
#   - the combination intro
#     prints whole ("it is
#     necessary to ignore
#     secondary spear tips when
#     classifying pole arms");
#   - the bill-guisarme
#     features list prints
#     whole ("a back spike for
#     armor penetration" - no
#     "armor ion" split exists
#     in the print);
#   - the confusion sentence
#     prints whole ("is
#     certainly understandable,
#     and care must be taken in
#     identifying such
#     weapons").
#
# ALL SIX flag names describe
# the garble (unlike R422,
# where four kept their names)
# - the R422 monks-druids
# precedent applies: every
# flag REPLACES with a
# ReadsClean pin, 1:1, so the
# inline count stays 161.
#
# Patches (22):
#   - the seed takes the R423
#     record
#   - rules/uaappendt.h: the
#     top comment, six flag
#     sites, the ledger (clean
#     2 -> 7, flagged 5 -> 0)
#   - regtest.cpp: the R391
#     block comment, six flag
#     asserts REPLACE, the
#     ledger asserts, the R424
#     audit block before the
#     R227 anchor; census 349
#     -> 350
#   - ua_gap_report.md: the
#     Appendix T box flips and
#     takes AMENDED R424
#
# Guards: the string-literal
# parity gate (the R421b
# lesson), the census 350, the
# no-bare-'||' gate (the R418b
# lesson) over uapa, the header
# mirror, the header statics
# (lines <= 78, the inline
# count 161), the gap censuses
# (102 closed, three open
# lines - the two logging
# boxes plus the legend), the
# seed record, the caller
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
        'R424 splice ABORT: ' + msg)


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


AT = 'rules/uaappendt.h'
RT = 'regtest.cpp'
GP = 'tools/ua_gap_report.md'
SD = ('doc/vibe/'
      'adnd1_knowledge_seed_v2.md')

# ======== (a) the seed ========

SEED_ENTRY = E(
    '- R423 landed 2026-10-13:',
    '  commit a44b3d0 (census 349,',
    '  preflight GREEN on the FIRST',
    '  run, pushed a911b59..a44b3d0),',
    '  the UA APPENDIX S PANTHEON',
    '  PROSE - the five pantheon',
    '  intro sections (pp. 110-120,',
    '  the clean OCR read) pin as',
    '  rules/uapantheon.h (NEW,',
    '  prefix uapn), the censuses',
    '  cross-checked live against',
    '  the R405 seam (the described',
    '  counts mirror nhdPantheonSize',
    '  row for row, the sum mirrors',
    '  nhdDeityCount 23, the Moradin',
    '  rulings mirror the R405 seam',
    '  functions); the Appendix S',
    '  item CLOSES - the box flips,',
    '  nothing stays open; census',
    '  348 -> 349.')

ANCH = NL + '## Knowledge maintenance'
s = rd(SD)
if 'R423 landed 2026-10-13' in s:
    already.append('seed: the R423 record')
elif s.count(ANCH) != 1:
    die('the seed maintenance head')
else:
    s = s.replace(ANCH, NL + SEED_ENTRY
                 + ANCH)
    wr(SD, s)
    applied.append('seed: the R423 record')

# ======== (b) rules/uaappendt.h ========

# the top comment
pair(AT,
     E('// list, the confusion sentence).',
       '// Nothing fully garbles - every',
       '// classification survives its',
       '// scrambled prose. The taxonomy',
       '// pairs with the R340 new',
       '// weapons roster (the hook',
       '// fauchard seam). Pin-era',
       '// pattern (R322).'),
     E('// list, the confusion sentence)',
       '// - RESOLVED (R424): the clean',
       '// pp. 123-128 read resolves all',
       '// five; the seven items stand',
       '// fully clean. The taxonomy',
       '// pairs with the R340 new',
       '// weapons roster (the hook',
       '// fauchard seam). Pin-era',
       '// pattern (R322).'),
     'at: the top comment')

# flag site 1: the system
# paragraph - the flag
# REPLACES with the resolved
# pin
pair(AT,
     E('// FLAG: the print garbles the',
       '// system-rationale paragraph',
       '// head (the "reasonable"',
       '// line) - the classification',
       '// standard recovers only in',
       '// part.',
       'inline bool uapaSystemParagraph'
       'Garbles()',
       '    { return true; }'),
     E('// A system of classification',
       '// and nomenclature is presented',
       '// here that seems both',
       '// reasonable and easy to use -',
       '// RESOLVED (R424): the clean',
       '// p. 123 read gives the whole',
       '// sentence, the "reasonable"',
       '// line included; the print',
       '// never garbles.',
       'inline bool uapaSystemParagraph'
       'ReadsClean()',
       '    { return true; }'),
     'at: the system paragraph')

# flag site 2: the fauchard
# description - the flag
# REPLACES with the resolved
# pin
pair(AT,
     E('// FLAG: the print scrambles',
       '// the fauchard description',
       '// body into column order -',
       '// the classification',
       '// survives, the prose',
       '// garbles.',
       'inline bool uapaFauchardGarbles'
       'Full()',
       '    { return true; }'),
     E('// The fauchard description',
       '// prints whole - RESOLVED',
       '// (R424): the clean p. 126',
       '// read gives the scythe/sickle',
       '// development, the cut-and-',
       '// thrust that did neither too',
       '// well, the little parrying,',
       '// the no-dismount early form',
       '// and the later back hook.',
       'inline bool uapaFauchard'
       'DescriptionReadsClean()',
       '    { return true; }'),
     'at: the fauchard description')

# flag site 3: the Lucern/bec
# comparison tail - the flag
# REPLACES with the resolved
# pin
pair(AT,
     E('// FLAG: the print garbles the',
       '// Lucern/bec de corbin',
       '// comparison tail into column',
       '// order - the classifications',
       '// survive, the prose',
       '// garbles.',
       'inline bool uapaLucernBec'
       'ComparisonGarbles()',
       '    { return true; }'),
     E('// "For the latter weapon was',
       '// not so specialized" -',
       '// RESOLVED (R424): the clean',
       '// p. 127 read prints the',
       '// Lucern/bec comparison tail',
       '// whole; the print never',
       '// garbles.',
       'inline bool uapaLucernBec'
       'ComparisonReadsClean()',
       '    { return true; }'),
     'at: the Lucern/bec tail')

# flag site 4: the combination
# intro - the flag REPLACES
# with the resolved pin
pair(AT,
     E('// FLAG: the print garbles the',
       '// combination intro (the',
       '// "to ignore" line) - the',
       '// doctrine recovers in',
       '// part.',
       'inline bool uapaCombinationIntro'
       'Garbles()',
       '    { return true; }'),
     E('// It is necessary to ignore',
       '// secondary spear tips when',
       '// classifying pole arms -',
       '// RESOLVED (R424): the clean',
       '// p. 127 read prints the',
       '// combination intro whole,',
       '// the "to ignore" line',
       '// included.',
       'inline bool uapaCombinationIntro'
       'ReadsClean()',
       '    { return true; }'),
     'at: the combination intro')

# flag site 5: the bill-
# guisarme features list - the
# flag REPLACES with the
# resolved pin
pair(AT,
     E('// FLAG: the print splits the',
       '// features list (the "armor',
       '// ion" cell) - the roster',
       '// recovers, the prose',
       '// garbles.',
       'inline bool uapaBillGuisarme'
       'FeaturesGarble()',
       '    { return true; }'),
     E('// "A back spike for armor',
       '// penetration" - RESOLVED',
       '// (R424): the clean p. 128',
       '// read prints the bill-',
       '// guisarme features list',
       '// whole; no "armor ion" split',
       '// exists in the print.',
       'inline bool uapaBillGuisarme'
       'FeaturesReadsClean()',
       '    { return true; }'),
     'at: the features list')

# flag site 6: the confusion
# sentence - the flag REPLACES
# with the resolved pin
pair(AT,
     E('// FLAG: the print cuts the',
       '// confusion sentence tail',
       '// ("is certainly") - the',
       '// caution recovers in part.',
       'inline bool uapaConfusion'
       'SentenceGarbles()',
       '    { return true; }'),
     E('// Confusion regarding the',
       '// combination weapons "is',
       '// certainly understandable,',
       '// and care must be taken in',
       '// identifying such weapons" -',
       '// RESOLVED (R424): the clean',
       '// p. 128 read prints the',
       '// confusion sentence whole,',
       '// tail included.',
       'inline bool uapaConfusion'
       'SentenceReadsClean()',
       '    { return true; }'),
     'at: the confusion sentence')

# the ledger: the clean count
pair(AT,
     E('// Two fully clean (the spear',
       '// family, the axe family).',
       'inline int uapaPartCleanCount()',
       '    { return 2; }'),
     E('// All seven items fully clean -',
       '// RESOLVED (R424): the clean',
       '// pp. 123-128 read resolves the',
       '// five flagged holes (the',
       '// original two fully clean:',
       '// the spear family, the axe',
       '// family).',
       'inline int uapaPartCleanCount()',
       '    { return 7; }'),
     'at: the clean count')

# the ledger: the flagged count
pair(AT,
     E('// Five mechanics-clean with',
       '// flagged holes (the',
       '// classification system',
       '// paragraph, the fauchard',
       '// description, the Lucern/bec',
       '// comparison tail, the',
       '// combination intro and',
       '// features list, the',
       '// confusion sentence).',
       'inline int uapaPartFlaggedCount()',
       '    { return 5; }'),
     E('// Zero flagged holes remain -',
       '// RESOLVED (R424): the clean',
       '// pp. 123-128 read resolves the',
       '// classification system',
       '// paragraph, the fauchard',
       '// description, the Lucern/bec',
       '// comparison tail, the',
       '// combination intro and',
       '// features list, and the',
       '// confusion sentence.',
       'inline int uapaPartFlaggedCount()',
       '    { return 0; }'),
     'at: the flagged count')

# ======== (c) regtest.cpp ========

# the R391 block comment
pair(RT,
     E('    // combination intro and',
       '    // features list, the',
       '    // confusion sentence); the',
       '    // R340 seam the hook',
       '    // fauchard roster.'),
     E('    // combination intro and',
       '    // features list, the',
       '    // confusion sentence) -',
       '    // RESOLVED (R424): the',
       '    // clean pp. 123-128 read',
       '    // resolves all five; the',
       '    // R340 seam the hook',
       '    // fauchard roster.'),
     'regtest: the R391 block comment')

# assert 1: the system
# paragraph flag assert
# REPLACES
pair(RT,
     '            if (!uapaSystemParagraph'
     'Garbles()) ++bad;',
     '            if (!uapaSystemParagraph'
     'ReadsClean()) ++bad;',
     'regtest: the system paragraph pin')

# assert 2: the fauchard flag
# assert REPLACES
pair(RT,
     '            if (!uapaFauchardGarbles'
     'Full()) ++bad;',
     '            if (!uapaFauchard'
     'DescriptionReadsClean()) ++bad;',
     'regtest: the fauchard pin')

# assert 3: the Lucern/bec
# flag assert REPLACES
pair(RT,
     '            if (!uapaLucernBec'
     'ComparisonGarbles()) ++bad;',
     '            if (!uapaLucernBec'
     'ComparisonReadsClean()) ++bad;',
     'regtest: the Lucern/bec pin')

# assert 4: the combination
# intro flag assert REPLACES
pair(RT,
     '            if (!uapaCombinationIntro'
     'Garbles()) ++bad;',
     '            if (!uapaCombinationIntro'
     'ReadsClean()) ++bad;',
     'regtest: the combination intro pin')

# assert 5: the features list
# flag assert REPLACES
pair(RT,
     '            if (!uapaBillGuisarme'
     'FeaturesGarble()) ++bad;',
     '            if (!uapaBillGuisarme'
     'FeaturesReadsClean()) ++bad;',
     'regtest: the features list pin')

# assert 6: the confusion
# sentence flag assert
# REPLACES
pair(RT,
     '            if (!uapaConfusion'
     'SentenceGarbles()) ++bad;',
     '            if (!uapaConfusion'
     'SentenceReadsClean()) ++bad;',
     'regtest: the confusion sentence pin')

# the ledger asserts
pair(RT,
     '            if (uapaPartClean'
     'Count() != 2) ++bad;',
     '            if (uapaPartClean'
     'Count() != 7) ++bad;',
     'regtest: the clean assert')

pair(RT,
     '            if (uapaPartFlagged'
     'Count() != 5) ++bad;',
     '            if (uapaPartFlagged'
     'Count() != 0) ++bad;',
     'regtest: the flagged assert')

# ---- the R424 audit block ----
AUD = E(
    '    // ---- R424: the appendix T',
    '    // resolution pin audit ----',
    '    // The clean pp. 123-128 read',
    '    // resolves the five R391',
    '    // flagged holes: the',
    '    // classification system',
    '    // paragraph prints whole',
    '    // ("a system of',
    '    // classification and',
    '    // nomenclature is presented',
    '    // here that seems both',
    '    // reasonable and easy to',
    '    // use"); the fauchard',
    '    // description prints whole',
    '    // (the scythe/sickle',
    '    // development, the cut-and-',
    '    // thrust that did neither too',
    '    // well, the little parrying,',
    '    // the no-dismount early form,',
    '    // the later back hook); the',
    '    // Lucern/bec comparison tail',
    '    // prints whole ("for the',
    '    // latter weapon was not so',
    '    // specialized"); the',
    '    // combination intro prints',
    '    // whole ("it is necessary to',
    '    // ignore secondary spear tips',
    '    // when classifying pole',
    '    // arms"); the bill-guisarme',
    '    // features list prints whole',
    '    // ("a back spike for armor',
    '    // penetration" - no "armor',
    '    // ion" split exists in the',
    '    // print); and the confusion',
    '    // sentence prints whole ("is',
    '    // certainly understandable,',
    '    // and care must be taken in',
    '    // identifying such',
    '    // weapons"). All seven items',
    '    // now stand fully clean;',
    '    // census 349 -> 350.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        if (!uapaSystemParagraph'
    'ReadsClean()',
    '                || !uapaFauchard'
    'DescriptionReadsClean()',
    '                || !uapaLucernBec'
    'ComparisonReadsClean()',
    '                || !uapaCombination'
    'IntroReadsClean()',
    '                || !uapaBillGuisarme'
    'FeaturesReadsClean()',
    '                || !uapaConfusion'
    'SentenceReadsClean())',
    '            ++bad;',
    '        if (uapaPartItemTotal() != 7',
    '                || uapaPartClean'
    'Count() != 7',
    '                || uapaPartFlagged'
    'Count() != 0',
    '                || uapaPartGarbled'
    'Count() != 0)',
    '            ++bad;',
    '        if (uapaPartCleanCount()',
    '                + uapaPartFlagged'
    'Count()',
    '                + uapaPartGarbled'
    'Count()',
    '                != uapaPart'
    'ItemTotal())',
    '            ++bad;',
    '        if (!uapaFauchardSickle'
    'Development()',
    '                || !uapaSecondarySpear'
    'TipCombination()',
    '                || uapaBillGuisarme'
    'FeatureCount() != 4',
    '                || !uapaCareShaftLength'
    'HeadShape()',
    '                || !uapaHuntingOr'
    'AgriculturalOrigin()',
    '                || !uapaSystemDerived'
    'Britannica())',
    '            ++bad;',
    '        printf("R424 UA appendix T'
    ' resolution pin audit: bad'
    ' %d' + chr(92) + 'n", bad);',
    '        if (bad) return 1;',
    '    }')

R227 = ('    // ---- R227: the wis mental'
        ' save wiring audit ----')
pair(RT, R227, AUD + NL + R227,
     'regtest: the R424 audit block')

# ======== (d) tools/ua_gap_report.md ========

pair(GP,
     '- [ ] **Appendix T: pole-arm',
     '- [x] **Appendix T: pole-arm',
     'gap: the Appendix T box flips')

pair(GP,
     E('        fauchard roster, stays',
       '        PDF-gated only.',
       '',
       '## Players tables and charts'
       ' (the manifest)'),
     E('        fauchard roster, stays',
       '        PDF-gated only.',
       '      - AMENDED R424: the clean',
       '        pp. 123-128 read resolves',
       '        the five flagged holes -',
       '        the classification system',
       '        paragraph, the fauchard',
       '        description, the Lucern/',
       '        bec comparison tail, the',
       '        combination intro, the',
       '        bill-guisarme features list',
       '        and the confusion sentence',
       '        print whole; all seven',
       '        items fully clean, the',
       '        box flips - the LAST open',
       '        book-content item in the',
       '        report closes.',
       '',
       '## Players tables and charts'
       ' (the manifest)'),
     'gap: the AMENDED R424 stratum')

# ======== the verify pass ========

if applied and already:
    die('the mixed applied/already'
        ' state (the R420 lesson)')

s = rd(RT)
if s.count('audit: bad') != 350:
    die('the census %d'
        % s.count('audit: bad'))
if s.count('R424 UA appendix T'
           ' resolution') != 1:
    die('the R424 audit label')

# the string-literal parity gate
# (the R421b lesson): no CODE
# line in the R424 audit block
# may carry an unterminated
# string literal (comment lines
# may hold lone quotes)
for ln in AUD.split(NL):
    c = ln.lstrip()
    if (c and not c.startswith('//')
            and ln.count(chr(34)) % 2):
        die('the R424 audit block has'
            ' an unterminated string'
            ' literal')

# the flags are gone - everywhere
for flag in ('uapaSystemParagraph'
             'Garbles',
             'uapaFauchardGarbles'
             'Full',
             'uapaLucernBec'
             'ComparisonGarbles',
             'uapaCombinationIntro'
             'Garbles',
             'uapaBillGuisarme'
             'FeaturesGarble',
             'uapaConfusion'
             'SentenceGarbles'):
    if s.count(flag):
        die('the %s flag survives in'
            ' regtest' % flag)
    if flag in rd(AT):
        die('the %s flag survives in'
            ' the header' % flag)

# the no-bare-|| gate (the R418b
# lesson): no uapa chain may BEGIN
# with '||' - a '||' line is legal
# only inside an open chain
prev = ''
for ln in s.split(NL):
    if ('uapa' in ln
            and ln != prev
            and _re.match(r'^ +\|\| ', ln)
            and (prev.rstrip().endswith(';')
                 or not prev.strip()
                 or prev.lstrip()
                 .startswith('//'))):
        die('a bare || uapa line')
    prev = ln

# the header mirror: the ledger
# and the six resolved pins
h = rd(AT)
if h.count('FLAG:'):
    die('the header still flags %d'
        % h.count('FLAG:'))
for pin in ('uapaSystemParagraph'
            'ReadsClean',
            'uapaFauchard'
            'DescriptionReadsClean',
            'uapaLucernBec'
            'ComparisonReadsClean',
            'uapaCombinationIntro'
            'ReadsClean',
            'uapaBillGuisarme'
            'FeaturesReadsClean',
            'uapaConfusion'
            'SentenceReadsClean'):
    if pin not in h:
        die('the %s pin missing from'
            ' the header' % pin)
    if pin not in s:
        die('the %s pin missing from'
            ' regtest' % pin)
if (h.count('uapaPartCleanCount()'
            + NL + '    { return 7; }')
        != 1):
    die('the header clean mirror')
if (h.count('uapaPartFlaggedCount()'
            + NL + '    { return 0; }')
        != 1):
    die('the header flagged mirror')

# the include line (the R390
# lesson): the uaappendt include
# comment must stay whole
if s.count('#include "rules/uaappendt.h"'
          '  // R391: the UA pole-arm'
          ' nomenclature') != 1:
    die('the uaappendt include line')

# the statics: no header line
# over 78 columns
for ln in h.split(NL):
    if len(ln) > 78:
        die('the header line %d long'
            % len(ln))

# the header inline count: the
# six flags replace 1:1 with the
# six resolved pins - 161 stays
if h.count('inline ') != 161:
    die('the header inline count %d'
        % h.count('inline '))

# the gap censuses: 102 closed,
# three open lines - two boxes
# (the two logging layers, out
# by the user decision) plus the
# legend
g = rd(GP)
if (E('- [x] **Appendix T: pole-arm',
      '      nomenclature**'
      ' (pp. 123-129)')
    not in g):
    die('the Appendix T box still'
        ' open')
if g.count(chr(10) + '- [x]') != 102:
    die('the gap closed count %d'
        % g.count(chr(10) + '- [x]'))
opens = [l for l in g.split(NL)
         if l.startswith('- [ ]')]
if len(opens) != 3:
    die('the gap open count %d'
        % len(opens))

# the seed record
if 'R423 landed 2026-10-13' not in rd(SD):
    die('the seed R423 record')

# the caller contract: no engine
# caller touches the uapa pins
for path in ('dm/treasure.cpp',
             'game/state_combat.cpp'):
    if _re.search(r'\buapa\w', rd(path)):
        die('%s calls the uapa pins'
            ' early' % path)

print('R424 splice: ALL OK'
      ' (applied %d, already %d)'
      % (len(applied), len(already)))
print('NOTE: the appendix T'
      ' resolution - the clean')
print('  pp. 123-128 read resolves')
print('  the five R391 flagged holes')
print('  (the classification system')
print('  paragraph, the fauchard')
print('  description, the Lucern/bec')
print('  comparison tail, the')
print('  combination intro, the')
print('  bill-guisarme features list')
print('  and the confusion sentence')
print('  print whole); all seven')
print('  items fully clean, the LAST')
print('  open book-content box flips;')
print('  census 349 -> 350')
print('commit: R424: the appendix T'
      ' resolution (census 350)')

