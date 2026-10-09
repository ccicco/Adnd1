#!/usr/bin/env python3
# R291 splice: the III.E Special artifacts
# explanation prose part 12 pins -
# the 21st, 22nd and 23rd of the 29
# artifact descriptions: the Queen
# Ehlissas Marvelous Nightingale, the
# Recorder of YeCind and the Ring of
# Gaxx, part2 lines 1625-1676. The
# Nightingale: made by Xagy and the
# volcano goddess Joramy 17 centuries
# ago (per Mordenkainen); Queen
# Ehlissa bent all to her will; a
# bejeweled songbird in golden wires
# that springs to life, wings,
# hops, performs; rumored eye rays
# and song wonders, ray-and-song
# spells; a 30 foot sphere against
# detection and magic or psionic
# intrusion, no hunger or thirst
# within; powers 4,0,1,1,1,1 (8). The
# Recorder: needs no musician, plays
# airs on command; alarms for
# stolen goods (itself included)
# within 30 feet; clue-word songs
# report the last 30 feet; rumored
# note-cast spells; powers
# 5,2,1,1,1,1 (11). The Ring of Gaxx:
# alien origin, platinum loop, fine
# spinel of unknown type; powers
# discovered on a finger; a
# nine-faceted gem, a power per
# facing to the top; turns itself
# off, on, or asleep; a random
# facet daily, DM-secret; one
# facing reveals the order;
# unmarkable, even a wish will not
# help; powers 3,2,1,1,1,1 (9) -
# one per facet. No break absorbed
# - the round closes on the standard
# blank at 1676; no page seam
# claimed (no running heads between
# upload lines 1450 and 1797). 35
# accessors: 32 scalars + 3 walkers.
# The audit cross-pins the R240 sale
# rows 20, 21 and 22: 64 at 112500,
# 65-66 at 80000, 67-68 at 17500 -
# all fixed rows.
# 3 patches, marker-based idempotence,
# assert after every patch. ZERO
# apostrophes and ZERO literal backslashes
# in the content below (the printf
# newline is built via BS = chr(92)).

import os
import re
import sys

HERE = os.path.abspath(os.path.dirname(sys.argv[0]))
ROOT = os.path.abspath(HERE + '/..')
NL = chr(10)
BS = chr(92)

applied = 0
already = 0

def rd(p):
    f = open(os.path.join(ROOT, p), encoding='utf-8')
    s = f.read()
    f.close()
    return s

def wr(p, s):
    f = open(os.path.join(ROOT, p), 'w', encoding='utf-8')
    f.write(s)
    f.close()


PINS = [
    'inline int sapNightingaleMadeByXagy() {',
    '    // Xagy is one of its makers',
    '    return 1;',
    '}',
    '',
    'inline int sapNightingaleJoramyCoMaker() {',
    '    // the volcano goddess Joramy is the other',
    '    return 1;',
    '}',
    '',
    'inline int sapNightingaleMadeCenturiesAgo() {',
    '    // Mordenkainen dated it this many centuries back',
    '    return 17;',
    '}',
    '',
    'inline int sapNightingaleEhlissaBentAll() {',
    '    // Queen Ehlissa bent all to her will',
    '    return 1;',
    '}',
    '',
    'inline int sapNightingaleNeverEscaped() {',
    '    // it never escaped its confinement',
    '    return 1;',
    '}',
    '',
    'inline int sapNightingaleGoldenWireCage() {',
    '    // held within a fine mesh of golden wires',
    '    return 1;',
    '}',
    '',
    'inline int sapNightingaleWingsPerchPerform() {',
    '    // wings open, hops to the perch, performs',
    '    return 1;',
    '}',
    '',
    'inline int sapNightingaleEyeRays() {',
    '    // its eyes shoot scintillating colored rays',
    '    return 1;',
    '}',
    '',
    'inline int sapNightingaleSongWonders() {',
    '    // its songs work magical wonders',
    '    return 1;',
    '}',
    '',
    'inline int sapNightingaleRaySongSpells() {',
    '    // rays and songs in combination weave spells',
    '    return 1;',
    '}',
    '',
    'inline int sapNightingaleSphereRadiusFeet() {',
    '    // the protective sphere radius, in feet',
    '    return 30;',
    '}',
    '',
    'inline int sapNightingaleSphereBlocksScrying() {',
    '    // no detection or magic or psionic intrusion',
    '    return 1;',
    '}',
    '',
    'inline int sapNightingaleNoHungerThirst() {',
    '    // those within neither hunger nor thirst',
    '    return 1;',
    '}',
    '',
    'inline int sapNightingalePowerTotal() {',
    '    // 4+0+1+1+1+1 - the total power count',
    '    return 8;',
    '}',
    '',
    'inline int sapNightingalePowerCount(int i) {',
    '    // the powers per tables I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        4, 0, 1, 1, 1, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapRecorderNeedsNoMusician() {',
    '    // it needs no musician to play it',
    '    return 1;',
    '}',
    '',
    'inline int sapRecorderPlaysOnCommand() {',
    '    // plays the most complicated airs on command',
    '    return 1;',
    '}',
    '',
    'inline int sapRecorderAlarmRadiusFeet() {',
    '    // the stolen-goods alarm radius, in feet',
    '    return 30;',
    '}',
    '',
    'inline int sapRecorderAlarmIncludesSelf() {',
    '    // it alarms for itself stolen as well',
    '    return 1;',
    '}',
    '',
    'inline int sapRecorderClueWordSongs() {',
    '    // information through clue-word songs',
    '    return 1;',
    '}',
    '',
    'inline int sapRecorderRumoredSpells() {',
    '    // rumored to cast spells with its notes',
    '    return 1;',
    '}',
    '',
    'inline int sapRecorderPowerTotal() {',
    '    // 5+2+1+1+1+1 - the total power count',
    '    return 11;',
    '}',
    '',
    'inline int sapRecorderPowerCount(int i) {',
    '    // the powers per tables I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        5, 2, 1, 1, 1, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
    'inline int sapGaxxAlienOrigin() {',
    '    // its origin is totally alien',
    '    return 1;',
    '}',
    '',
    'inline int sapGaxxPlatinumLoopSpinel() {',
    '    // a platinum loop about a fine spinel',
    '    return 1;',
    '}',
    '',
    'inline int sapGaxxUnknownGemType() {',
    '    // the workmanship unique, the gem unknown',
    '    return 1;',
    '}',
    '',
    'inline int sapGaxxFingerDiscovery() {',
    '    // donned on a finger to discover powers',
    '    return 1;',
    '}',
    '',
    'inline int sapGaxxFacetCount() {',
    '    // the nine-faceted gem',
    '    return 9;',
    '}',
    '',
    'inline int sapGaxxFacingToTop() {',
    '    // each facet powers when faced to the top',
    '    return 1;',
    '}',
    '',
    'inline int sapGaxxTurnsItself() {',
    '    // it turns itself off, on, or when asleep',
    '    return 1;',
    '}',
    '',
    'inline int sapGaxxDailyRandomFacet() {',
    '    // a random facet each day, secret to the DM',
    '    return 1;',
    '}',
    '',
    'inline int sapGaxxFacetOrderKnown() {',
    '    // one known facing reveals the order',
    '    return 1;',
    '}',
    '',
    'inline int sapGaxxCannotBeMarked() {',
    '    // unmarkable - even a wish will not help',
    '    return 1;',
    '}',
    '',
    'inline int sapGaxxPowerTotal() {',
    '    // 3+2+1+1+1+1 - the total power count',
    '    return 9;',
    '}',
    '',
    'inline int sapGaxxPowerCount(int i) {',
    '    // the powers per tables I-VI; i clamps',
    '    if (i < 0) i = 0;',
    '    if (i > 5) i = 5;',
    '    static const int t[6] = {',
    '        3, 2, 1, 1, 1, 1,',
    '    };',
    '    return t[i];',
    '}',
    '',
]

AUDIT = [
    '    // ---- R291: the III.E Special artifacts',
    '    // explanation prose part 12 ----',
    '    // The Nightingale, the Recorder of',
    '    // YeCind and the Ring of Gaxx, part2',
    '    // lines 1625-1676. No break absorbed -',
    '    // the round closes on the standard',
    '    // blank at 1676; no page seam claimed',
    '    // (no running heads between lines 1450',
    '    // and 1797).',
    '    {',
    '        int bad = 0;',
    '        // the Nightingale scalars and powers',
    '        if (rules::sapNightingaleMadeByXagy() != 1 ||',
    '            rules::sapNightingaleJoramyCoMaker() != 1 ||',
    '            rules::sapNightingaleMadeCenturiesAgo() != 17 ||',
    '            rules::sapNightingaleEhlissaBentAll() != 1 ||',
    '            rules::sapNightingaleNeverEscaped() != 1 ||',
    '            rules::sapNightingaleGoldenWireCage() != 1 ||',
    '            rules::sapNightingaleWingsPerchPerform() != 1 ||',
    '            rules::sapNightingaleEyeRays() != 1 ||',
    '            rules::sapNightingaleSongWonders() != 1 ||',
    '            rules::sapNightingaleRaySongSpells() != 1 ||',
    '            rules::sapNightingaleSphereRadiusFeet() != 30 ||',
    '            rules::sapNightingaleSphereBlocksScrying() != 1 ||',
    '            rules::sapNightingaleNoHungerThirst() != 1 ||',
    '            rules::sapNightingalePowerTotal() != 8) ++bad;',
    '        static const int kN[6] = {',
    '            4, 0, 1, 1, 1, 1,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapNightingalePowerCount(i) != kN[i]) ++bad;',
    '        if (rules::sapNightingalePowerCount(0) +',
    '            rules::sapNightingalePowerCount(1) +',
    '            rules::sapNightingalePowerCount(2) +',
    '            rules::sapNightingalePowerCount(3) +',
    '            rules::sapNightingalePowerCount(4) +',
    '            rules::sapNightingalePowerCount(5) !=',
    '            rules::sapNightingalePowerTotal()) ++bad;',
    '        // the Recorder scalars and powers',
    '        if (rules::sapRecorderNeedsNoMusician() != 1 ||',
    '            rules::sapRecorderPlaysOnCommand() != 1 ||',
    '            rules::sapRecorderAlarmRadiusFeet() != 30 ||',
    '            rules::sapRecorderAlarmIncludesSelf() != 1 ||',
    '            rules::sapRecorderClueWordSongs() != 1 ||',
    '            rules::sapRecorderRumoredSpells() != 1 ||',
    '            rules::sapRecorderPowerTotal() != 11) ++bad;',
    '        static const int kR[6] = {',
    '            5, 2, 1, 1, 1, 1,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapRecorderPowerCount(i) != kR[i]) ++bad;',
    '        if (rules::sapRecorderPowerCount(0) +',
    '            rules::sapRecorderPowerCount(1) +',
    '            rules::sapRecorderPowerCount(2) +',
    '            rules::sapRecorderPowerCount(3) +',
    '            rules::sapRecorderPowerCount(4) +',
    '            rules::sapRecorderPowerCount(5) !=',
    '            rules::sapRecorderPowerTotal()) ++bad;',
    '        // the Ring of Gaxx scalars and powers',
    '        if (rules::sapGaxxAlienOrigin() != 1 ||',
    '            rules::sapGaxxPlatinumLoopSpinel() != 1 ||',
    '            rules::sapGaxxUnknownGemType() != 1 ||',
    '            rules::sapGaxxFingerDiscovery() != 1 ||',
    '            rules::sapGaxxFacetCount() != 9 ||',
    '            rules::sapGaxxFacingToTop() != 1 ||',
    '            rules::sapGaxxTurnsItself() != 1 ||',
    '            rules::sapGaxxDailyRandomFacet() != 1 ||',
    '            rules::sapGaxxFacetOrderKnown() != 1 ||',
    '            rules::sapGaxxCannotBeMarked() != 1 ||',
    '            rules::sapGaxxPowerTotal() != 9) ++bad;',
    '        static const int kG[6] = {',
    '            3, 2, 1, 1, 1, 1,',
    '        };',
    '        for (int i = 0; i < 6; ++i)',
    '            if (rules::sapGaxxPowerCount(i) != kG[i]) ++bad;',
    '        if (rules::sapGaxxPowerCount(0) +',
    '            rules::sapGaxxPowerCount(1) +',
    '            rules::sapGaxxPowerCount(2) +',
    '            rules::sapGaxxPowerCount(3) +',
    '            rules::sapGaxxPowerCount(4) +',
    '            rules::sapGaxxPowerCount(5) !=',
    '            rules::sapGaxxPowerTotal()) ++bad;',
    '        // the Nightingale and the Recorder agree on 30 feet',
    '        if (rules::sapNightingaleSphereRadiusFeet() !=',
    '            rules::sapRecorderAlarmRadiusFeet()) ++bad;',
    '        // the Gaxx power total equals its facet count',
    '        if (rules::sapGaxxPowerTotal() !=',
    '            rules::sapGaxxFacetCount()) ++bad;',
    '        // the cross-pins: the R240 sale table rows',
    '        // (three fixed rows, 20, 21 and 22)',
    '        if (rules::saRowLo(20) != 64 ||',
    '            rules::saRowHi(20) != 64 ||',
    '            rules::saSaleGp(20) != 112500 ||',
    '            rules::saSaleGpHi(20) != 0) ++bad;',
    '        if (rules::saRowLo(21) != 65 ||',
    '            rules::saRowHi(21) != 66 ||',
    '            rules::saSaleGp(21) != 80000 ||',
    '            rules::saSaleGpHi(21) != 0) ++bad;',
    '        if (rules::saRowLo(22) != 67 ||',
    '            rules::saRowHi(22) != 68 ||',
    '            rules::saSaleGp(22) != 17500 ||',
    '            rules::saSaleGpHi(22) != 0) ++bad;',
    '        printf("R291 special artifacts prose part 12 pins audit: bad %d' + BS + 'n", bad);',
    '    }',
]

GAP = [
    'R291 landed the III.E Special',
    'artifacts explanation prose',
    'part 12 (part2 lines 1625-1676;',
    'global = 11065 + part2 line),',
    'the 21st, 22nd and 23rd of the',
    '29 descriptions: the Queen',
    'Ehlissas Marvelous Nightingale,',
    'the Recorder of YeCind and',
    'the Ring of Gaxx. The Nightingale:',
    'Mordenkainen asserted it was',
    'made by Xagy and Joramy, the',
    'goddess of volcanic activity,',
    '17 centuries ago; Queen Ehlissa',
    'bent all to her will and it',
    'never escaped its confinement;',
    'a bejeweled songbird in a fine',
    'mesh of golden wires that',
    'springs to life, opens its',
    'wings, hops to the highest',
    'perch and performs; rumored',
    'eye rays of brilliant color,',
    'songs of wonder, and ray-and-',
    'song spells; a protective',
    'sphere of 30 feet against',
    'detection and magic or psionic',
    'intrusion, its occupants',
    'neither hungering nor',
    'thirsting; powers 4,0,1,1,1,1',
    'total 8. The Recorder of',
    'YeCind: a wind instrument that',
    'needs no musician and plays',
    'the most complicated of airs',
    'on command; always alarms if',
    'anything of its possessor',
    '(including itself) is stolen',
    'within 30 feet; plays',
    'clue-word songs telling what',
    'took place within 30 feet;',
    'rumored to cast spells by its',
    'notes; powers 5,2,1,1,1,1',
    'total 11. The Ring of Gaxx:',
    'totally alien origin, a',
    'platinum loop and a fine',
    'spinel of unknown type with',
    'unique workmanship; powers',
    'discovered only on a finger;',
    'a nine-faceted gem, each',
    'facing a different power',
    'toward the top; it turns',
    'itself when taken off, put on',
    'or the wearer sleeps; a random',
    'facet each day, secretly',
    'determined by the DM; one',
    'known facing reveals the',
    'order once all are known;',
    'unmarkable - even a wish will',
    'not help; powers 3,2,1,1,1,1',
    'total 9 - one power per facet.',
    'No break absorbed - the round',
    'closes on the standard blank at',
    '1676; no page seam claimed (no',
    'running heads between lines',
    '1450 and 1797). The quirks:',
    'Ehlissas and YeCind print with',
    'the curly right single quote;',
    'the 30 feet marks print as the',
    'curly feet mark; 17 true',
    'multiplication signs; three',
    'backslash continuation rows -',
    'the Nightingale V slot and the',
    'Recorder III and V slots; the',
    'Recorder table prints its',
    'slots before the count lines;',
    'the Gaxx III through VI rows',
    'print trailing commas; the',
    'Gaxx em dash before even a',
    'wish - all pinned as plain',
    'digits and words,',
    'apostrophe-free and',
    'backslash-free here. 35',
    'accessors: 32 scalars + 3',
    'walkers (the nightingale',
    'walker 4,0,1,1,1,1, the',
    'recorder walker 5,2,1,1,1,1,',
    'the gaxx walker 3,2,1,1,1,1),',
    'no name collisions with the',
    'miscprose and specart headers;',
    'the audit cross-pins the R240',
    'sale rows 20, 21 and 22 - the',
    'Nightingale band 64 at 112500,',
    'the Recorder band 65-66 at',
    '80000, the Gaxx band 67-68 at',
    '17500, all fixed rows, their',
    'zero high bounds carried by',
    'saSaleGpHi (census 209). Next:',
    'R292 III.E Special part 13 -',
    'the Rod of Seven Parts in',
    'part2 from line 1677 (global',
    '12842; the assembly table,',
    'the complete rod powers and',
    'the ordering note follow; the',
    'III.E Special prose continue).',
]

# ---- the splice self-asserts ----
PTEXT = NL.join(PINS)
defs = re.findall(r'inline int (sap[A-Za-z0-9]+)[(]', PTEXT)
assert len(defs) == 35, 'accessor count is not 35'
assert len(set(defs)) == 35, 'accessor names not unique'
scal = re.findall(r'inline int (sap[A-Za-z0-9]+)[(][)]', PTEXT)
assert len(scal) == 32, 'scalar count is not 32'
walk = [d for d in defs if d not in scal]
assert len(walk) == 3, 'walker count is not 3'
assert set(walk) == {'sapNightingalePowerCount',
    'sapRecorderPowerCount',
    'sapGaxxPowerCount',
    }, 'wrong walkers'
ATEXT = NL.join(AUDIT)
audited = set(re.findall(r'rules::(sap[A-Za-z0-9]+)[(]', ATEXT))
assert audited == set(defs), 'audit does not probe every accessor'
for fn in sorted(os.listdir(os.path.join(ROOT, 'rules'))):
    if not fn.endswith('.h') or fn == 'specartprose2.h':
        continue
    pt = open(os.path.join(ROOT, 'rules', fn), encoding='utf-8').read()
    for n in defs:
        assert n not in pt, 'name collision with ' + fn
s0 = rd('rules/specartprose2.h')
assert 'sapOrbMightPowerCount' in s0, 'specartprose2.h missing the R290 accessors'
assert 'sapOrbGreatSerpentPowerCount' in s0, 'specartprose2.h missing the R289 accessors'
assert 'sapServantLumSameMake' in s0, 'specartprose2.h missing the R288 accessors'
assert s0.count('}  // namespace rules') == 1, 'namespace close not unique'
for grp in (PINS, AUDIT, GAP):
    for el in grp:
        assert chr(39) not in el, 'apostrophe in content'
        probe = el.replace(chr(92) + 'n', '')
        assert chr(92) not in probe, 'backslash in content'
        assert NL not in el, 'list element spans lines'
for el in GAP:
    assert len(el) <= 34, 'gap line too long: ' + el
assert ATEXT.count('{') == ATEXT.count('}'), 'audit braces unbalanced'
assert ATEXT.count('(') == ATEXT.count(')'), 'audit parens unbalanced'
assert AUDIT[-1] == '    }', 'audit block does not close'
assert PINS[-1] == '', 'pins block must end with a blank line'
assert PTEXT.count('{') == PTEXT.count('}'), 'pins braces unbalanced'
assert ATEXT.count('R291 special artifacts prose part 12 pins audit: bad %d' + BS + 'n') == 1, 'audit printf label not unique'
GJOIN = ' '.join(GAP)
for frag in ('part 12', 'the Ring of Gaxx', '1625-1676',
             'No break absorbed', 'Ehlissas',
             'census 209', 'R292', 'line 1677', '12842',
             'saSaleGpHi'):
    assert any(frag in el for el in GAP), 'gap frag not contiguous: ' + frag
    assert frag in GJOIN, 'gap frag missing: ' + frag
for frag in ('part 12', 'The Nightingale', 'the Ring of Gaxx',
             '1625-1676', 'No break absorbed'):
    assert any(frag in el for el in AUDIT), 'audit frag not contiguous: ' + frag

# ---- patch 1: extend rules/specartprose2.h ----
p = 'rules/specartprose2.h'
s = rd(p)
mark = 'inline int sapNightingaleMadeByXagy() {'
if mark in s:
    already += 1
else:
    anchor = '}  // namespace rules'
    assert s.count(anchor) == 1, 'namespace anchor not unique'
    s = s.replace(anchor, PTEXT + NL + anchor, 1)
    wr(p, s)
    applied += 1
s = rd(p)
assert s.count(mark) == 1, 'patch 1 failed'
assert s.count('}  // namespace rules') == 1, 'patch 1 broke the close'
assert s.endswith('}  // namespace rules'), 'patch 1 broke the tail'
alldefs = re.findall(r'inline int (sap[A-Za-z0-9]+)[(]', s)
assert len(alldefs) == 349, 'accessor count is not 349'
assert len(set(alldefs)) == 349, 'accessor names not unique'

# ---- patch 2: the regtest audit block ----
p = 'regtest.cpp'
s = rd(p)
mark = '    // ---- R291: the III.E Special artifacts'
if mark in s:
    already += 1
else:
    anchor = '    // ---- R227: the wis mental save wiring audit ----'
    assert s.count(anchor) == 1, 'audit anchor not unique'
    s = s.replace(anchor, ATEXT + NL + anchor, 1)
    wr(p, s)
    applied += 1
s = rd(p)
assert s.count(mark) == 1, 'patch 2 failed'
assert s.count('R291 special artifacts prose part 12 pins audit: bad %d' + BS + 'n') == 1, 'patch 2 doubled'

# ---- patch 3: the gap report entry ----
p = 'tools/dmg_gap_report.md'
s = rd(p)
mark = 'R291 landed the III.E Special'
if mark in s:
    already += 1
else:
    anchor = 'continue).' + NL + NL + 'Categories:'
    assert s.count(anchor) == 1, 'gap anchor not unique'
    s = s.replace(anchor, 'continue).' + NL + NL + NL.join(GAP) + NL + NL + 'Categories:', 1)
    wr(p, s)
    applied += 1
s = rd(p)
assert s.count(mark) == 1, 'patch 3 failed'

print('R291 splice: ALL OK (applied %d, already %d)' % (applied, already))
print('R291 note: 3 patches; the III.E Special')
print('artifacts and relics explanation prose')
print('part 12 - the Nightingale, the')
print('Recorder of YeCind and the Ring of')
print('Gaxx, part2 lines 1625-1676;')
print('census 209.')
print('commit: R291: the III.E Special artifacts explanation prose part 12 pinned - the Queen Ehlissas Marvelous Nightingale, the Recorder of YeCind and the Ring of Gaxx in part2 lines 1625-1676 (census 209)')

