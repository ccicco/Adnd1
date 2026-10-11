#!/usr/bin/env python3
# R333: the UA ranger expansion
# (pp. 21-22) pin round - the
# tracking rules, the giant-class
# roster expansion, the spell
# progression via the landed seams
# (the per-creature and
# precipitation modifier values,
# the surface table cells and the
# movement-rate cells are OCR
# holes; the ranger weapons rules
# ride a later round). Pin-era
# pattern (R322). Idempotent; run
# twice.

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

# ---- (a) the seed: the R332 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R332 landed 2026-10-11: commit',
    '  b5380bd, census 259, the UA',
    '  barbarian pin round',
    '  (rules/barbarian.h): the',
    '  requirements and the wisdom',
    '  maximum, Barbarians Table I, the',
    '  magic detestation (the award tail',
    '  an OCR hole pinned as a bool), the',
    '  strike ladder, the saves, the',
    '  primary, secondary and tertiary',
    '  ability ladders. GREEN on the',
    '  first paste. No new lessons - the',
    '  R330/R331 ones held (the',
    '  comments-stripped-first balance',
    '  checker, the seam-comment naming).',
    ])
s = rd(SD)
if 'R332 landed 2026-10-11' in s:
    already.append('seed: the R332 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R332 record')
s = rd(SD)
assert s.count('R332 landed 2026-10-11') == 1, 'a entry'
assert s.count('R331 landed 2026-10-11') == 1, \
    'a r331 kept'
assert s.count('## Knowledge maintenance') == 1, \
    'a maint'
assert len(applied) + len(already) == 1, 'a count'

# ---- (b) NEW rules/uaranger.h ----
UR = 'rules/uaranger.h'
if os.path.exists(UR) and 'R333' in rd(UR):
    already.append('uaranger.h: the pins')
else:
    HDR = NL.join([
    '// ===========================================================================',
    '// Adnd1 - rules/uaranger.h',
    '// The UA ranger expansion (pp. 21-22) pins (R333).',
    '//',
    '// Pin-era pattern (R322): pinned data only - no engine site exists.',
    '// The registry rows and the creation-flow gates ride their own rounds.',
    '//',
    '// Scope = the gap-report item: the tracking rules, the giant-class',
    '// combat bonus, the spell progression. The spell bands (druidic from',
    '// the 8th up to 3rd, magic-user from the 9th up to 2nd) already ride',
    '// the R327 pins and the R184 spell layers - cross-checked in the',
    '// audit, not re-pinned here (the UA prose restating them is OCR-lost',
    '// from the extract). The ranger weapons rules (the bow-or-crossbow',
    '// requirement, the four required types by 4th level) are NOT in the',
    '// gap item - they ride a later round.',
    '//',
    '// OCR holes documented in-header: the per-creature-beyond-first and',
    '// per-hour-of-precipitation modifier values are lost; the indoor',
    '// surface-condition table cells are lost (the prose fixes the same',
    '// four-category ladder via the next-lower-category and -50%',
    '// references); the movement-rate-while-tracking table\'s six rows',
    '// survive but every rate cell is lost; the identification table\'s',
    '// level column is empty (the ladder is fixed by the internal',
    '// "As Nth level" references); the roster\'s "anoll" cell decodes as',
    '// gnoll (the g->a OCR slip; the alphabetical column confirms).',
    '// ===========================================================================',
    '',
    '#pragma once',
    '',
    'namespace rules {',
    '',
    '// ---- the outdoor tracking base (p. 21) ----',
    '// 10% per level plus an additional 10% (20% at 1st, 70% at 6th);',
    '// the base rises as high as 110% (10th level or higher) and never',
    '// more; an adjusted chance over 100% is treated as 100%.',
    'inline int uaRangerTrackBasePerLevel()',
    '    { return 10; }',
    '',
    'inline int uaRangerTrackBaseBonus()',
    '    { return 10; }',
    '',
    'inline int uaRangerTrackBaseCap()',
    '    { return 110; }',
    '',
    'inline int uaRangerTrackAdjustedCap()',
    '    { return 100; }',
    '',
    'inline int uaRangerTrackBaseAt(int level) {',
    '    if (level < 1) return 0;',
    '    int p = 10 * level + 10;',
    '    return p > 110 ? 110 : p;',
    '}',
    '',
    '// ---- the terrain modifiers (p. 21) ----',
    '// Four categories: soft +20%, occasional marks +10%, infrequent 0%,',
    '// minutest-traces -50%. Intelligent hiding drops one category; at',
    '// the -50% category tracking is impossible.',
    'inline int uaRangerTrackTerrainCategoryCount()',
    '    { return 4; }',
    '',
    'inline int uaRangerTrackTerrainModifier(int category) {',
    '    static const int k[4] = {20, 10, 0, -50};',
    '    if (category < 0) category = 0;',
    '    if (category > 3) category = 3;',
    '    return k[category];',
    '}',
    '',
    'inline bool uaRangerTrackHideDropsCategory()',
    '    { return true; }',
    '',
    'inline bool uaRangerTrackHideAtRockBottomImpossible()',
    '    { return true; }',
    '',
    '// ---- the other modifiers (p. 21) ----',
    '// -5% per 12 hours elapsed since the trail was made. The',
    '// per-creature-beyond-first and per-hour-of-precipitation values',
    '// are OCR-lost (documented above) - not pinned.',
    'inline int uaRangerTrackPer12Hours()',
    '    { return 5; }',
    '',
    '// ---- the indoor tracking (p. 21) ----',
    '// Same base chance; the surface-condition ladder runs the same four',
    '// categories (prose-verified); intelligent hiding (even through a',
    '// secret door) drops one category, impossible at the bottom;',
    '// indoors is impossible without an observed distinguishing feature',
    '// and a follow-up within 10-30 minutes of the quarry making the',
    '// trail.',
    'inline bool uaRangerTrackIndoorBaseSame()',
    '    { return true; }',
    '',
    'inline bool uaRangerTrackIndoorObservationRequired()',
    '    { return true; }',
    '',
    'inline int uaRangerTrackFollowWindowLow()',
    '    { return 10; }',
    '',
    'inline int uaRangerTrackFollowWindowHigh()',
    '    { return 30; }',
    '',
    '// ---- the light and movement reads (p. 21) ----',
    '// Good illumination assumed; total darkness is impossible without',
    '// non-visual evidence; the tracking movement rate is slowed even at',
    '// best (the six-row rate table\'s cells are OCR-lost).',
    'inline bool uaRangerTrackGoodLightAssumed()',
    '    { return true; }',
    '',
    'inline bool uaRangerTrackTotalDarknessImpossible()',
    '    { return true; }',
    '',
    'inline int uaRangerTrackMoveRowCount()',
    '    { return 6; }',
    '',
    '// ---- the tracking-quality definitions (p. 21) ----',
    '// Obvious 71% or better; occasional 31-70%; faint 30% or less;',
    '// poor illumination is anything under daylight over total darkness.',
    'inline int uaRangerTrackObviousMin()',
    '    { return 71; }',
    '',
    'inline int uaRangerTrackOccasionalLow()',
    '    { return 31; }',
    '',
    'inline int uaRangerTrackOccasionalHigh()',
    '    { return 70; }',
    '',
    'inline int uaRangerTrackFaintMax()',
    '    { return 30; }',
    '',
    '// ---- the identification ladder (p. 21) ----',
    '// Identification needs a second roll at the same chance; the',
    '// abilities are cumulative by level. The level cells are OCR-empty;',
    '// the ladder is fixed by the internal "As Nth level" references.',
    'inline bool uaRangerTrackIdentifySecondRoll()',
    '    { return true; }',
    '',
    'inline bool uaRangerTrackIdentifyCumulative()',
    '    { return true; }',
    '',
    'inline int uaRangerTrackIdentifyRowCount()',
    '    { return 10; }',
    '',
    'inline const char* uaRangerTrackIdentifyAbility(int level) {',
    '    static const char* const k[10] = {',
    '        "Common woodland creatures\' tracks"',
    '        " and direction of travel",',
    '        "Common woodland creatures\' number"',
    '        " and pace",',
    '        "Common woodland creatures\' time of"',
    '        " passage (outdoors only)",',
    '        "As 3rd level with respect to"',
    '        " uncommon woodland creatures",',
    '        "As 3rd level with respect to rare"',
    '        " woodland creatures",',
    '        "As 3rd level with respect to very"',
    '        " rare woodland creatures",',
    '        "As 3rd level with respect to all"',
    '        " sorts of creatures (woodland and"',
    '        " otherwise) within a 100-mile"',
    '        " radius",',
    '        "As 7th level, plus the ability to"',
    '        " determine the general size and"',
    '        " weight of humans",',
    '        "As 8th level, plus the ability to"',
    '        " determine the size and numbers"',
    '        " of mounted creatures",',
    '        "As 9th level with respect to all"',
    '        " creatures ever observed, prior"',
    '        " to attaining 10th level or"',
    '        " subsequently"',
    '    };',
    '    if (level < 1) level = 1;',
    '    if (level > 10) level = 10;',
    '    return k[level - 1];',
    '}',
    '',
    '// ---- the giant class (p. 22) ----',
    '// The damage bonus: +1 point per ranger level when a giant-class',
    '// creature is engaged. The expanded roster: the 11 Players',
    '// Handbook creatures (the R184 pins) plus the Fiend Folio and',
    '// Monster Manual II additions, 22 in all, stored lowercase and',
    '// sorted (the R184 matching convention); the garbled "anoll" cell',
    '// decodes as gnoll.',
    'inline int uaRangerGiantDamagePerLevel()',
    '    { return 1; }',
    '',
    'inline int uaRangerGiantRosterCount()',
    '    { return 22; }',
    '',
    'inline int uaRangerGiantRosterPhbCount()',
    '    { return 11; }',
    '',
    'inline const char* uaRangerGiantRosterName(int i) {',
    '    static const char* const k[22] = {',
    '        "bugbear", "cyclopskin", "dune stalker",',
    '        "ettin", "flind", "gibberling",',
    '        "giant", "gnoll", "goblin",',
    '        "grimlock", "hobgoblin", "kobold",',
    '        "meazel", "norker", "ogre",',
    '        "ogre mage", "ogrillon", "orc",',
    '        "quaggoth", "tasloi", "troll",',
    '        "xvart"',
    '    };',
    '    if (i < 0) i = 0;',
    '    if (i > 21) i = 21;',
    '    return k[i];',
    '}',
    '',
    '}   // namespace rules',
    ])
    clean(HDR, 78)
    wr(UR, HDR)
    applied.append('uaranger.h: the pins')
s = rd(UR)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('uaRangerTrackBaseAt') == 1, 'b base'
assert s.count('uaRangerTrackIdentifyAbility') == 1, 'b ladder fn'
assert s.count('uaRangerGiantRosterName') == 1, 'b roster'
assert s.count('uaRangerTrackTerrainModifier') == 1, 'b terrain fn'
assert s.count('inline') == 29, 'b inline count'
assert s.count('gnoll') == 3, 'b gnoll'
assert s.count('R333') == 1, 'b round tag'
assert 'rangerGiantClassName' not in s, 'b no r184 ref'
assert 'rangerDruidicFromLevel' not in s, \
    'b no r327 ref'
assert len(applied) + len(already) == 2, 'b count'

# ---- (c) the gap report: the close ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'CLOSED R333' in s:
    already.append('gap report: the close')
else:
    FIRST_OLD = ('- [ ] **The ranger expansion**'
                ' (pp.')
    TAIL_OLD = NL.join([
    '      9th to 2nd-level spells).',
    ])
    assert s.count(FIRST_OLD) == 1, 'c first'
    assert s.count(TAIL_OLD) == 1, 'c tail'
    FIRST_NEW = ('- [x] **The ranger expansion**'
                ' (pp.')
    CLOSE = NL.join([
    '      - CLOSED R333: the pin round',
    '      (rules/uaranger.h) - the',
    '      tracking base and terrain',
    '      ladders, the indoor reads, the',
    '      identification ladder, the',
    '      giant-class roster expansion',
    '      11 -> 22 (gnoll decoded from',
    '      the garbled cell). The spell',
    '      progression cross-checked',
    '      against the landed R327/R184',
    '      pins (the UA prose is',
    '      OCR-lost). The ranger weapons',
    '      rules ride a later round.',
    ])
    clean(CLOSE, 57)
    s = s.replace(FIRST_OLD, FIRST_NEW)
    s = s.replace(TAIL_OLD, TAIL_OLD + NL + CLOSE)
    wr(GP, s)
    applied.append('gap report: the close')
s = rd(GP)
assert s.count('- [x] **The ranger expansion**') == 1, 'c flipped'
assert s.count('CLOSED R333') == 1, 'c closed'
assert s.count('CLOSED R332') == 1, 'c r332 kept'
assert s.count('CLOSED R331') == 0, 'c r331 note only'
assert s.count('CLOSED R330') == 1, 'c r330 kept'
assert s.count('CLOSED R329') == 1, 'c r329 kept'
assert s.count('CLOSED R328') == 1, 'c r328 kept'
assert len(applied) + len(already) == 3, 'c count'

# ---- (d) regtest.cpp: the include, the
# audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R333 ranger expansion pin audit' in s:
    already.append('regtest.cpp: the R333 audit')
else:
    INC_ANCH = ('#include "rules/barbarian.h"'
                '  // R332: the UA barbarian')
    INC_NEW = NL.join([
    INC_ANCH,
    '#include "rules/uaranger.h"'
    '  // R333: the UA ranger expansion',
    ])
    AUD_ANCH = ('    // ---- R227: the wis mental'
                ' save wiring audit ----')
    AUDIT = NL.join([
    '    // ---- R333: the ranger expansion pin audit ----',
    '    // The UA ranger expansion (pp. 21-22) - the pin-era',
    '    // pattern: the tracking base and terrain ladders, the',
    '    // indoor reads, the identification ladder, the',
    '    // giant-class roster expansion 11 -> 22 (the',
    '    // per-creature and precipitation values, the surface',
    '    // cells and the rate cells are OCR holes - documented',
    '    // in the header). The spell-progression component and',
    '    // the R184/R327/R331/R332 seams cross-checked.',
    '    {',
    '        using namespace rules;',
    '        int bad = 0;',
    '        // U1: the outdoor tracking base',
    '        {',
    '            if (uaRangerTrackBasePerLevel() != 10)',
    '                ++bad;',
    '            if (uaRangerTrackBaseBonus() != 10)',
    '                ++bad;',
    '            if (uaRangerTrackBaseCap() != 110)',
    '                ++bad;',
    '            if (uaRangerTrackAdjustedCap()',
    '                != 100) ++bad;',
    '            if (uaRangerTrackBaseAt(1) != 20)',
    '                ++bad;',
    '            if (uaRangerTrackBaseAt(6) != 70)',
    '                ++bad;',
    '            if (uaRangerTrackBaseAt(10) != 110)',
    '                ++bad;',
    '            if (uaRangerTrackBaseAt(20) != 110)',
    '                ++bad;',
    '            if (uaRangerTrackBaseAt(0) != 0)',
    '                ++bad;',
    '        }',
    '        // U2: the terrain ladder and the hide rule',
    '        {',
    '            static const int k[4] = {',
    '                20, 10, 0, -50',
    '            };',
    '            if (uaRangerTrackTerrainCategoryCount()',
    '                != 4) ++bad;',
    '            for (int c = 0; c < 4; ++c)',
    '                if (uaRangerTrackTerrainModifier(c)',
    '                    != k[c]) ++bad;',
    '            if (!uaRangerTrackHideDropsCategory())',
    '                ++bad;',
    '            if (!uaRangerTrackHideAtRockBottomImpossible())',
    '                ++bad;',
    '        }',
    '        // U3: the elapsed-time modifier',
    '        {',
    '            if (uaRangerTrackPer12Hours() != 5)',
    '                ++bad;',
    '        }',
    '        // U4: the indoor reads',
    '        {',
    '            if (!uaRangerTrackIndoorBaseSame())',
    '                ++bad;',
    '            if (!uaRangerTrackIndoorObservationRequired())',
    '                ++bad;',
    '            if (uaRangerTrackFollowWindowLow()',
    '                != 10) ++bad;',
    '            if (uaRangerTrackFollowWindowHigh()',
    '                != 30) ++bad;',
    '        }',
    '        // U5: the light and movement reads',
    '        {',
    '            if (!uaRangerTrackGoodLightAssumed())',
    '                ++bad;',
    '            if (!uaRangerTrackTotalDarknessImpossible())',
    '                ++bad;',
    '            if (uaRangerTrackMoveRowCount() != 6)',
    '                ++bad;',
    '        }',
    '        // U6: the quality definitions',
    '        {',
    '            if (uaRangerTrackObviousMin() != 71)',
    '                ++bad;',
    '            if (uaRangerTrackOccasionalLow()',
    '                != 31) ++bad;',
    '            if (uaRangerTrackOccasionalHigh()',
    '                != 70) ++bad;',
    '            if (uaRangerTrackFaintMax() != 30)',
    '                ++bad;',
    '        }',
    '        // U7: the identification ladder',
    '        {',
    '            if (!uaRangerTrackIdentifySecondRoll())',
    '                ++bad;',
    '            if (!uaRangerTrackIdentifyCumulative())',
    '                ++bad;',
    '            if (uaRangerTrackIdentifyRowCount()',
    '                != 10) ++bad;',
    '            if (strcmp(uaRangerTrackIdentifyAbility(',
    '                1), "Common woodland creatures\'"',
    '                " tracks and direction of travel")',
    '                != 0) ++bad;',
    '            if (strcmp(uaRangerTrackIdentifyAbility(',
    '                3), "Common woodland creatures\'"',
    '                " time of passage (outdoors"',
    '                " only)") != 0) ++bad;',
    '            if (strcmp(uaRangerTrackIdentifyAbility(',
    '                4), "As 3rd level with respect"',
    '                " to uncommon woodland"',
    '                " creatures") != 0) ++bad;',
    '            if (strcmp(uaRangerTrackIdentifyAbility(',
    '                7), "As 3rd level with respect"',
    '                " to all sorts of creatures"',
    '                " (woodland and otherwise)"',
    '                " within a 100-mile radius")',
    '                != 0) ++bad;',
    '            if (strcmp(uaRangerTrackIdentifyAbility(',
    '                9), "As 8th level, plus the"',
    '                " ability to determine the"',
    '                " size and numbers of mounted"',
    '                " creatures") != 0) ++bad;',
    '            if (strcmp(uaRangerTrackIdentifyAbility(',
    '                10), "As 9th level with respect"',
    '                " to all creatures ever"',
    '                " observed, prior to attaining"',
    '                " 10th level or subsequently")',
    '                != 0) ++bad;',
    '        }',
    '        // U8: the giant class - the damage',
    '        // bonus, the roster, the superset',
    '        {',
    '            if (uaRangerGiantDamagePerLevel()',
    '                != 1) ++bad;',
    '            if (uaRangerGiantRosterCount() != 22)',
    '                ++bad;',
    '            if (uaRangerGiantRosterPhbCount()',
    '                != 11) ++bad;',
    '            if (strcmp(uaRangerGiantRosterName(7),',
    '                "gnoll") != 0) ++bad;',
    '            if (strcmp(uaRangerGiantRosterName(1),',
    '                "cyclopskin") != 0) ++bad;',
    '            if (strcmp(uaRangerGiantRosterName(21),',
    '                "xvart") != 0) ++bad;',
    '            // every R184 PHB name rides the',
    '            // UA roster (the printed superset',
    '            // claim)',
    '            for (int i = 0; i < 11; ++i) {',
    '                int found = 0;',
    '                for (int j = 0; j < 22; ++j)',
    '                    if (strcmp(',
    '                        rangerGiantClassName(i),',
    '                        uaRangerGiantRosterName(j))',
    '                        == 0) found = 1;',
    '                if (!found) ++bad;',
    '            }',
    '        }',
    '        // U9: the seams - the spell bands',
    '        // (R327), the R184 bonus, the R331',
    '        // spec gate, the R332 tracking read',
    '        {',
    '            if (rangerDruidicFromLevel() != 8)',
    '                ++bad;',
    '            if (rangerDruidicMaxSpellLevel()',
    '                != 3) ++bad;',
    '            if (rangerMuFromLevel() != 9) ++bad;',
    '            if (rangerMuMaxSpellLevel() != 2)',
    '                ++bad;',
    '            if (rangerGiantClassBonus(7) != 7)',
    '                ++bad;',
    '            if (!weaponSpecClassAllowed(',
    '                UACLASS_RANGER)) ++bad;',
    '            if (!barbarianTracksAsRanger())',
    '                ++bad;',
    '        }',
    '        printf("R333 ranger expansion pin audit: bad %d\\n", bad);',
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
    applied.append('regtest.cpp: the R333 audit')
s = rd(RT)
assert s.count(
    'R333 ranger expansion pin audit: bad ') == 1, \
    'd audit line'
assert s.count('audit: bad ') == 260, 'd census 260'
assert s.count(
    'R332 barbarian pin audit: bad ') == 1, \
    'd r332 kept'
assert s.count(
    'R331 weapon spec prose pin audit: bad ') == 1, \
    'd r331 kept'
assert s.count('R227: the wis mental save') == 1, \
    'd r227 kept'
assert s.count('#include "rules/uaranger.h"') == 1, \
    'd include'
assert len(applied) + len(already) == 4, 'd count'

# ---- the summary ----
print('R333 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R333 note: the UA ranger')
print('expansion pin round - the tracking')
print('base and terrain ladders, the')
print('indoor reads, the identification')
print('ladder, the giant-class roster')
print('expansion 11 -> 22; the spell')
print('progression via the landed seams')
print('(the weapons rules ride a later')
print('round); the census 259 -> 260')
print('commit: R333: the UA ranger')
print('expansion pin round (census 260)')

