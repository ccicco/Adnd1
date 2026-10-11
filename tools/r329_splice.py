#!/usr/bin/env python3
# R329: the UA paladin re-parented
# under the cavalier (p. 16) pin round
# - the re-parenting, the minima (the
# cavalier requisites plus WIS 13 and
# CHA 17), the lawful-good gate, the
# social station with the 0-level
# track, the cavalier charge, the CHA
# percentile growth. Pin-era pattern
# (R322): pin now, wire when a site
# exists. Idempotent; run twice.

import io
import os

NL = '\n'
applied = []
already = []

def rd(p):
    with io.open(p, 'r', encoding='utf-8') as f:
        return f.read()

def wr(p, s):
    with io.open(p, 'w', encoding='utf-8') as f:
        f.write(s)

def clean(block, w):
    for ln in block.split(NL):
        assert len(ln) <= w, 'wide %d: %s' % (
            len(ln), ln)

# ---- (a) the seed: the R328 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R328 landed 2026-10-11: commit',
    '  e9b26eb, census 255, the UA',
    '  cavalier pin round (rules/',
    '  cavalier.h): the minima, the',
    '  race gate, the weapons of',
    '  choice, the parry and armor',
    '  reads, the horsemanship',
    '  ladder, the percentile',
    '  growth, the saves and',
    '  immunities, the chivalric',
    '  code, the Table I clean',
    '  cells (the 5/6/11/12 title',
    '  holes stay open). GREEN on',
    '  the first paste. Lesson:',
    '  the four oracle fails were',
    '  OCR needles (curly quotes,',
    '  hyphenated breaks, scrambled',
    '  grid text), not facts - fix',
    '  needles against the extract,',
    '  never the fact.',
    ])
s = rd(SD)
if 'R328 landed 2026-10-11' in s:
    already.append('seed: the R328 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R328 record')
s = rd(SD)
assert s.count('R328 landed 2026-10-11') == 1, 'a entry'
assert s.count('R327 landed') == 1, 'a r327 kept'
assert s.count('## Knowledge maintenance') == 1, 'a maint'
assert len(applied) + len(already) == 1, 'a count'

# ---- (b) NEW rules/paladin.h ----
PL = 'rules/paladin.h'
if os.path.exists(PL) and 'R329' in rd(PL):
    already.append('paladin.h: the pins')
else:
    HDR = NL.join([
    '// ===========================================================================',
    '// Adnd1 - rules/paladin.h',
    '// The UA paladin re-parented under the',
    '// cavalier (p. 16) pins (R329).',
    '//',
    '// Pin-era pattern (R322): pinned data only - no engine site exists. The',
    '// paladin is no longer a sub-class of the fighter but of the cavalier:',
    '// the requisites, the social-station gate and the 0-level track delegate',
    '// to the R328 pins (rules/cavalier.h); the PHB powers ride the R184',
    '// spell layers. The book\'s second column here is OCR-scrambled in the',
    '// extract - the 0-level and no-prime reads are fragment-verified (the',
    '// oracle documents each fragment); the retainer cross-reference is the',
    '// DMG p. 75 read the gap report carries.',
    '// ===========================================================================',
    '',
    '#pragma once',
    '',
    '#include "cavalier.h"  // the parent-class pins',
    '',
    'namespace rules {',
    '',
    '// ---- the re-parenting (p. 16) ----',
    'inline bool paladinIsCavalierSubclass()',
    '    { return true; }',
    '',
    '// ---- the minima ----',
    '// All the cavalier requisites (STR/DEX/CON 15,',
    '// INT 10) plus wisdom 13 and charisma 17 or',
    '// higher; the STR/DEX/CON/INT legs delegate to',
    '// the R328 cavalierMinAbility.',
    'inline int paladinWisdomMin()',
    '    { return 13; }',
    '',
    'inline int paladinCharismaMin()',
    '    { return 17; }',
    '',
    'inline int paladinMinAbility(int a) {',
    '    if (a == ABILITY_WIS)',
    '        return paladinWisdomMin();',
    '    if (a == ABILITY_CHA)',
    '        return paladinCharismaMin();',
    '    return cavalierMinAbility(a);',
    '}',
    '',
    '// ---- the alignment gate ----',
    '// Lawful good only; a straying paladin',
    '// becomes a cavalier and is stripped of all',
    '// special paladin powers.',
    'inline bool paladinLawfulGoodOnly()',
    '    { return true; }',
    '',
    'inline bool paladinStrayBecomesCavalier()',
    '    { return true; }',
    '',
    'inline bool paladinStrayStripsPowers()',
    '    { return true; }',
    '',
    '// ---- the social station ----',
    '// The correct social station or sponsorship',
    '// by nobility; a sponsored paladin goes',
    '// through the Horseman and Lancer 0 levels',
    '// (the R328 cavalier track) before gaining',
    '// the paladin abilities.',
    'inline bool paladinSocialStationRequired()',
    '    { return true; }',
    '',
    'inline bool paladinSponsoredByNobility()',
    '    { return true; }',
    '',
    'inline bool paladinRidesZeroLevelTrack()',
    '    { return true; }',
    '',
    'inline int paladinZeroLevelHorsemanXp()',
    '    { return cavalierHorsemanXp(); }',
    '',
    'inline int paladinZeroLevelLancerXp()',
    '    { return cavalierLancerXp(); }',
    '',
    '// ---- the prime requisite ----',
    '// A paladin, as a sub-class of the',
    '// cavalier, has no prime requisite ability',
    '// and gains no experience bonus; paladins',
    '// take no weapon specialization (p. 14).',
    'inline bool paladinNoPrimeRequisite()',
    '    { return true; }',
    '',
    'inline bool paladinSpecializationBanned()',
    '    { return true; }',
    '',
    '// ---- the cavalier charge (p. 16) ----',
    '// The PHB powers and level advancement are',
    '// unchanged; in addition the paladin gains',
    '// the cavalier abilities.',
    'inline bool paladinPhbPowersUnchanged()',
    '    { return true; }',
    '',
    'inline int paladinCavalierAbilityCount()',
    '    { return 5; }',
    '',
    'inline const char* paladinCavalierAbilityName(',
    '        int i) {',
    '    static const char* const k[5] = {',
    '        "weapons of choice",',
    '        "parrying ability", "horsemanship",',
    '        "saving throw bonuses",',
    '        "immunity to fear"',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 4) i = 4;',
    '    return k[i];',
    '}',
    '',
    '// The paladin may increase charisma the',
    '// same way the cavalier increases',
    '// strength, dexterity and constitution',
    '// (the R328 percentile growth).',
    'inline bool paladinCharismaPercentileGrowth()',
    '    { return true; }',
    '',
    '// ---- the retainer read ----',
    '// The paladin\'s retainer rules differ from',
    '// the cavalier\'s (DMG p. 75); the follower',
    '// tables ride the cavalier gap item.',
    'inline bool paladinRetainerRulesDiffer()',
    '    { return true; }',
    '',
    '}   // namespace rules',
    ])
    clean(HDR, 78)
    wr(PL, HDR)
    applied.append('paladin.h: the pins')
s = rd(PL)
assert s.count('namespace rules {') == 1, 'b namespace'
assert s.count('paladinIsCavalierSubclass') == 1, 'b reparent fn'
assert s.count('paladinMinAbility') == 1, 'b minima fn'
assert s.count('cavalierMinAbility') == 2, 'b delegation'
assert s.count('paladinCavalierAbilityName') == 1, 'b charge fn'
assert s.count('#include "cavalier.h"') == 1, 'b parent inc'
assert 'SUB_COUNT' not in s, 'b no SUB_COUNT'
assert len(applied) + len(already) == 2, 'b count'

# ---- (c) the gap report: the close ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'CLOSED R329' in s:
    already.append('gap report: the close')
else:
    FIRST_OLD = NL.join([
    '- [ ] **The paladin re-parented under',
    ])
    FIRST_NEW = NL.join([
    '- [x] **The paladin re-parented under',
    ])
    TAIL_OLD = NL.join([
    '      specialization.',
    ])
    CLOSE = NL.join([
    '      - CLOSED R329: the pin round',
    '      (rules/paladin.h): the',
    '      re-parenting (cavalier',
    '      sub-class, no longer',
    '      fighter), the minima (the',
    '      R328 requisites plus WIS',
    '      13 and CHA 17), the',
    '      lawful-good gate with the',
    '      stray read, the social',
    '      station with the 0-level',
    '      track delegation, the',
    '      no-prime-requisite and',
    '      no-specialization reads,',
    '      the cavalier charge (the',
    '      five abilities), the CHA',
    '      percentile growth, the',
    '      retainer cross-reference',
    '      (DM p. 75); the R329 audit',
    '      (census 256).',
    ])
    assert s.count(FIRST_OLD) == 1, 'c first anchor'
    assert s.count(TAIL_OLD) == 1, 'c tail anchor'
    clean(CLOSE, 57)
    s = s.replace(FIRST_OLD, FIRST_NEW)
    s = s.replace(TAIL_OLD, TAIL_OLD + NL + CLOSE)
    wr(GP, s)
    applied.append('gap report: the close')
s = rd(GP)
assert s.count('CLOSED R329') == 1, 'c close'
assert s.count('CLOSED R328') == 1, 'c r328 kept'
assert s.count('- [x] **The paladin re-parented'
    ) == 1, 'c flipped'
assert s.count('- [ ] **The druid hierophant'
    ) == 1, 'c druid kept'
assert len(applied) + len(already) == 3, 'c count'

# ---- (d) regtest.cpp: the include, the
# audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R329 paladin reparent pin audit' in s:
    already.append('regtest.cpp: the R329 audit')
else:
    INC_ANCH = ('#include "rules/cavalier.h"'
                '  // R328: the UA cavalier')
    INC_NEW = NL.join([
    INC_ANCH,
    '#include "rules/paladin.h"'
    '  // R329: the paladin reparent'])
    AUD_ANCH = ('    // ---- R227: the wis mental'
                ' save wiring audit ----')
    AUDIT = NL.join([
    '    // ---- R329: the paladin reparent pin',
    '    // audit ----',
    '    // The UA paladin re-parented under the',
    '    // cavalier (p. 16) - the pin-era',
    '    // pattern: the re-parenting, the',
    '    // minima (the cavalier requisites plus',
    '    // WIS 13 and CHA 17), the lawful-good',
    '    // gate with the stray read, the social',
    '    // station with the 0-level track, the',
    '    // no-prime-requisite and',
    '    // no-specialization reads, the cavalier',
    '    // charge (the five abilities), the CHA',
    '    // percentile growth, the retainer',
    '    // cross-reference. The R327/R328 seams',
    '    // cross-checked.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // U1: the re-parenting',
    '        {',
    '            if (!paladinIsCavalierSubclass())',
    '                ++bad;',
    '        }',
    '        // U2: the minima - the WIS and CHA',
    '        // legs, and the delegation to the',
    '        // R328 cavalier requisites',
    '        {',
    '            if (paladinWisdomMin() != 13)',
    '                ++bad;',
    '            if (paladinCharismaMin() != 17)',
    '                ++bad;',
    '            if (paladinMinAbility(',
    '                ABILITY_WIS) != 13) ++bad;',
    '            if (paladinMinAbility(',
    '                ABILITY_CHA) != 17) ++bad;',
    '            if (paladinMinAbility(',
    '                ABILITY_STR) != 15) ++bad;',
    '            if (paladinMinAbility(',
    '                ABILITY_DEX) != 15) ++bad;',
    '            if (paladinMinAbility(',
    '                ABILITY_CON) != 15) ++bad;',
    '            if (paladinMinAbility(',
    '                ABILITY_INT) != 10) ++bad;',
    '            // the delegation: the non-WIS,',
    '            // non-CHA legs read the parent',
    '            if (paladinMinAbility(ABILITY_STR)',
    '                != cavalierMinAbility(',
    '                    ABILITY_STR)) ++bad;',
    '            if (paladinMinAbility(ABILITY_INT)',
    '                != cavalierMinAbility(',
    '                    ABILITY_INT)) ++bad;',
    '        }',
    '        // U3: the alignment gate',
    '        {',
    '            if (!paladinLawfulGoodOnly())',
    '                ++bad;',
    '            if (!paladinStrayBecomesCavalier())',
    '                ++bad;',
    '            if (!paladinStrayStripsPowers())',
    '                ++bad;',
    '        }',
    '        // U4: the social station and the',
    '        // 0-level track (the R328 seam)',
    '        {',
    '            if (!paladinSocialStationRequired())',
    '                ++bad;',
    '            if (!paladinSponsoredByNobility())',
    '                ++bad;',
    '            if (!paladinRidesZeroLevelTrack())',
    '                ++bad;',
    '            if (paladinZeroLevelHorsemanXp()',
    '                != cavalierHorsemanXp()) ++bad;',
    '            if (paladinZeroLevelLancerXp()',
    '                != cavalierLancerXp()) ++bad;',
    '            if (paladinZeroLevelHorsemanXp()',
    '                != -1500) ++bad;',
    '            if (paladinZeroLevelLancerXp()',
    '                != -500) ++bad;',
    '        }',
    '        // U5: no prime requisite, no',
    '        // specialization (the R327 station',
    '        // ban cross-checked)',
    '        {',
    '            if (!paladinNoPrimeRequisite())',
    '                ++bad;',
    '            if (!paladinSpecializationBanned())',
    '                ++bad;',
    '            if (!uaStationArmorBan(',
    '                UACLASS_PALADIN)) ++bad;',
    '            if (paladinClericalFromLevel()',
    '                != 9) ++bad;',
    '        }',
    '        // U6: the cavalier charge - the',
    '        // five abilities, the PHB read,',
    '        // the CHA growth',
    '        {',
    '            if (paladinCavalierAbilityCount()',
    '                != 5) ++bad;',
    '            if (strcmp(',
    '                paladinCavalierAbilityName(0),',
    '                "weapons of choice") != 0)',
    '                ++bad;',
    '            if (strcmp(',
    '                paladinCavalierAbilityName(4),',
    '                "immunity to fear") != 0)',
    '                ++bad;',
    '            if (!paladinPhbPowersUnchanged())',
    '                ++bad;',
    '            if (!paladinCharismaPercentileGrowth())',
    '                ++bad;',
    '        }',
    '        // U7: the retainer cross-reference',
    '        {',
    '            if (!paladinRetainerRulesDiffer())',
    '                ++bad;',
    '        }',
    '        printf("R329 paladin reparent pin audit: bad %d\\n", bad);',
    '        if (bad) return 1;',
    '    }',
    ])
    assert s.count(INC_ANCH) == 1, 'd inc anchor'
    assert s.count(AUD_ANCH) == 1, 'd aud anchor'
    clean(INC_NEW, 78)
    clean(AUDIT, 76)
    s = s.replace(INC_ANCH, INC_NEW)
    s = s.replace(AUD_ANCH, AUDIT + NL + NL + AUD_ANCH)
    wr(RT, s)
    applied.append('regtest.cpp: the R329 audit')
s = rd(RT)
assert s.count(
    'R329 paladin reparent pin audit: bad '
    ) == 1, 'd audit line'
assert s.count('audit: bad ') == 256, 'd census 256'
assert s.count(
    'R328 cavalier pin audit') == 1, 'd r328 kept'
assert s.count('R227: the wis mental save') == 1, \
    'd r227 kept'
assert s.count(
    '#include "rules/paladin.h"') == 1, \
    'd include'
assert len(applied) + len(already) == 4, 'd count'

# ---- the summary ----
print('R329 splice: ALL OK (applied %d,'
      ' already %d)'
      % (len(applied), len(already)))
print('R329 note: the paladin re-parented')
print('under the cavalier pin round - the')
print('re-parenting, the minima, the')
print('lawful-good gate, the social')
print('station, the cavalier charge, the')
print('CHA percentile growth; the battery')
print('census 255 -> 256')
print('commit: R329: the paladin re-parented')
print('under the cavalier pin round')
print('(census 256)')

