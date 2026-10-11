#!/usr/bin/env python3
# R353: the UA NEW DRUID SPELLS pin
# round, the 5th level (p. 45) -
# moonbeam (the movable spotlight
# beam, the color and vision effects)
# and spike stones (identical to the
# clerical; the school cell prints
# Enhancement where the R347 clerical
# pin reads Enchantment - flagged).
# The digit-garble family decodes the
# "7 segments" as 1. The item stays
# open (the 6th-7th levels).
# Pin-era pattern (R322).
# Idempotent; run twice.
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

# ---- (a) the seed: the R352 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R352 landed 2026-10-11: commit',
    '  849d516, census 279, the UA',
    '  new druid 3rd level spells pin',
    '  round (rules/uadruidspells3.h):',
    '  cloudburst (the stat-block',
    '  interleave decoded with the',
    '  call lightning exclusion),',
    '  know alignment (the',
    '  five-creature cap, not',
    '  reversible), spike growth (the',
    '  material interleave with the',
    '  seven twigs) and starshine (the',
    '  school tail lost; seam-checks',
    '  the R351 reflecting pool pin);',
    '  the UA prints no 4th-level',
    '  druid section. Lesson: the gap',
    '  note tail line now ends two',
    '  prior notes - the insert',
    '  anchors on the two-line tail',
    '  (note end plus the next item)',
    '  or it would double-insert;',
    '  the ACID assert caught it.',
    '  GREEN on the first run.',
])
s = rd(SD)
if 'R352 landed 2026-10-11' in s:
    already.append('seed: the R352 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R352 record')
s = rd(SD)
assert s.count('R352 landed 2026-10-11') == 1, 'a entry'
assert s.count('R351 landed 2026-10-11') == 1, 'a r351 kept'
assert s.count('R350 landed 2026-10-11') == 1, 'a r350 kept'
assert s.count('R349 landed 2026-10-11') == 1, 'a r349 kept'
assert s.count('R348 landed 2026-10-11') == 1, 'a r348 kept'
assert s.count('R347 landed 2026-10-11') == 1, 'a r347 kept'
assert s.count('R343 landed 2026-10-11') == 1, 'a r343 kept'
assert s.count('## Knowledge maintenance') == 1, 'a maint'
assert len(applied) + len(already) == 1, 'a count'

# ---- (b) NEW rules/uadruidspells5.h ----
US = 'rules/uadruidspells5.h'
if os.path.exists(US) and 'R353' in rd(US):
    already.append('uadruidspells5.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uadruidspells5.h
// The UA NEW DRUID SPELLS (p. 45) pins, R353: the 5th-level
// spell descriptions - moonbeam and spike stones.
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
//
// JUDGMENTs (the decode method):
//   - the digit-garble family (the R343 precedent): the moonbeam
//     casting time prints "7 segments" - the family decodes
//     1 segment (moonbeam prints a clean "Level: 5" cell).
//   - the moonbeam name header prints "Moonbeam (Evocation -
//     Alteration)" without the "## " marker - a formatting loss,
//     not a content loss; the name and school pin clean.
//   - the moonbeam range cell prints "Range: 1" - the unit mark
//     is lost; position-decoded as 1 inch (the R346 interleave
//     precedent), pinned with doubt pending the PDF.
//   - the spike stones school cell prints "Alteration/
//     Enhancement" while the R347 clerical pin (rules/
//     uaclericspells5.h) reads "Alteration/Enchantment" - the
//     druid cell is pinned verbatim with the discrepancy
//     flagged; pending the PDF.
//   - the spike stones casting time cell prints empty - a hole;
//     the clerical R347 pin reads 6 segments (noted, not
//     re-pinned here).
//   - the spike stones prose: "This spell is the same as the
//     5th-level clerical spell of the same name." - the druid
//     version pins as identical; every stat cell seam-checks
//     against the R347 clerical pin (range 3", save none,
//     duration 3-12 turns + 1/level, area 1" square per level
//     with 1 spike per square foot).
//   - the druid spike stones area cell prints "1" square per
//     level, 1 spike per 1' sq." - corroborating the R347
//     decode of the clerical area cell.
//
// OCR holes (the item stays open - the 6th and 7th levels pin
// in later rounds; these stay pending the PDF): the moonbeam
// range unit mark; the spike stones casting time cell; the
// spike stones school discrepancy (Enhancement vs the R347
// clerical Enchantment).
// ===========================================================================

#pragma once

namespace rules {

// ---- moonbeam (Evocation - Alteration), p. 45 ----
inline const char* uad5MoonbeamName()
    { return "Moonbeam (Evocation - Alteration)"; }

// The name header prints without the "## " marker - a
// formatting loss; the name and school pin clean.
inline bool uad5MoonbeamHeaderMarkerLost()
    { return true; }

inline bool uad5MoonbeamComponentsVSM()
    { return true; }

inline int uad5MoonbeamLevel()
    { return 5; }

// The casting time prints "7 segments" - the digit-garble
// family decodes 1 segment.
inline int uad5MoonbeamCastingTimeSegments()
    { return 1; }

// The range cell prints "Range: 1" - the unit mark is lost;
// position-decoded as 1 inch, with doubt.
inline int uad5MoonbeamRangeInches()
    { return 1; }

inline bool uad5MoonbeamRangeUnitLost()
    { return true; }

inline bool uad5MoonbeamSaveNone()
    { return true; }

inline int uad5MoonbeamDurationRoundsPerLevel()
    { return 1; }

inline bool uad5MoonbeamAoeOneInchSpherePlusSpecial()
    { return true; }

// A beam of soft, pale light strikes downward from overhead and
// illuminates whatever area the caster is pointing at.
inline bool uad5MoonbeamDownwardBeamOnPointedArea()
    { return true; }

// The light is exactly the same as moonlight - colors other
// than shades of black, gray, or white are not determinable.
inline bool uad5MoonbeamExactMoonlight()
    { return true; }

inline bool uad5MoonbeamColorsNotDeterminable()
    { return true; }

// The caster can easily cause the moonbeam to move to any area
// he or she can see and point to - an effective spotlight, for
// example upon an opponent.
inline bool uad5MoonbeamMovesToSeenPointedAreas()
    { return true; }

inline bool uad5MoonbeamEffectiveSpotlight()
    { return true; }

// The moonbeam allows shadows; a creature centered in it is
// most certainly under observation.
inline bool uad5MoonbeamAllowsShadows()
    { return true; }

inline bool uad5MoonbeamCenteredCreatureObserved()
    { return true; }

// The reflected light allows dim visual perception 1 inch
// beyond the area of effect.
inline int uad5MoonbeamDimPerceptionInchesBeyond()
    { return 1; }

// The light does not adversely affect infravision, and
// enhances ultravision to its greatest potential.
inline bool uad5MoonbeamNoInfravisionAdverseEffect()
    { return true; }

inline bool uad5MoonbeamEnhancesUltravision()
    { return true; }

// The material: several seeds of any moonseed plant and a
// piece of opalescent feldspar (moonstone).
inline bool uad5MoonbeamMaterialMoonseedSeeds()
    { return true; }

inline bool uad5MoonbeamMaterialMoonstoneFeldspar()
    { return true; }

// ---- spike stones (Alteration/Enhancement), p. 45 ----
// The druid school cell prints "Alteration/Enhancement" - the
// R347 clerical pin reads "Alteration/Enchantment"; the druid
// cell is pinned verbatim with the discrepancy flagged.
inline const char* uad5SpikeStonesName()
    { return "Spike Stones (Alteration/Enhancement)"; }

inline bool uad5SpikeStonesSchoolDiscrepancyFlagged()
    { return true; }

inline bool uad5SpikeStonesComponentsVSM()
    { return true; }

inline int uad5SpikeStonesLevel()
    { return 5; }

// The casting time cell prints empty - a hole; the R347
// clerical pin reads 6 segments (noted, not re-pinned).
inline bool uad5SpikeStonesCastingTimeCellLost()
    { return true; }

inline int uad5SpikeStonesRangeInches()
    { return 3; }

inline bool uad5SpikeStonesSaveNone()
    { return true; }

inline int uad5SpikeStonesDurationTurnsMin()
    { return 3; }

inline int uad5SpikeStonesDurationTurnsMax()
    { return 12; }

inline int uad5SpikeStonesDurationTurnsPerLevel()
    { return 1; }

inline int uad5SpikeStonesAoeSquareInchesPerLevel()
    { return 1; }

inline int uad5SpikeStonesSpikesPerSquareFoot()
    { return 1; }

// The prose: this spell is the same as the 5th-level clerical
// spell of the same name.
inline bool uad5SpikeStonesIdenticalToClerical()
    { return true; }

}   // namespace rules"""
    clean(HDR, 78)
    wr(US, HDR + NL)
    applied.append('uadruidspells5.h: the pins')
s = rd(US)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 35, 'b inline count'
assert s.count('R353') == 1, 'b round tag'
assert s.count('uad5MoonbeamName()') == 1, 'b moonbeam fn'
assert s.count('uad5SpikeStonesIdenticalToClerical()') == 1, 'b identical fn'
assert 'uastDruid' not in s, 'b no r341 ref'
assert 'uac5' not in s, 'b no r347 ref'
assert len(applied) + len(already) == 2, 'b count'

# ---- (c) the gap report: the note (the
# item STAYS OPEN - the 6th-7th levels) ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'R353: the 5th level pinned' in s:
    already.append('gap report: the note')
else:
    TAIL_OLD = NL.join([
        '        druid section).',
        '- [ ] **The new magic-user spells**',
    ])
    assert s.count(TAIL_OLD) == 1, 'c tail'
    NOTE = NL.join([
    '      - R353: the 5th level pinned',
    '        (rules/uadruidspells5.h) - the',
    '        two spell descriptions (moonbeam',
    '        with the movable spotlight beam',
    '        and the color and vision',
    '        effects, spike stones identical',
    '        to the clerical); the family',
    '        decodes the 7 as 1 (moonbeam',
    '        prints the clean 5); the spike',
    '        stones stat cells seam-check',
    '        against the R347 clerical pin',
    '        (the school cell prints',
    '        Enhancement where the clerical',
    '        reads Enchantment - flagged; the',
    '        casting time cell lost); the R341',
    '        druid 5th table prints six PHB',
    '        names - neither new name',
    '        seam-checks there; the 6th and',
    '        7th levels stay open.',
])
    clean(NOTE, 57)
    s = s.replace(TAIL_OLD, NL.join([
        '        druid section).',
        NOTE,
        '- [ ] **The new magic-user spells**',
    ]))
    wr(GP, s)
    applied.append('gap report: the note')
s = rd(GP)
assert s.count('R353: the 5th level pinned') == 1, 'c note'
assert s.count('- [ ] **The new druid spells**'
    ' (pp.') == 1, 'c stays open'
assert s.count('R352: the 3rd level pinned') == 1, 'c r352 kept'
assert s.count('R351: the 2nd level pinned') == 1, 'c r351 kept'
assert s.count('R350: the 1st level pinned') == 1, 'c r350 kept'
assert s.count('R349: the 7th level pinned') == 1, 'c r349 kept'
assert s.count('CLOSED R349') == 1, 'c r349 closed kept'
assert len(applied) + len(already) == 3, 'c count'

# ---- (d) regtest.cpp: the include, the
# audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R353 UA druid 5th level spells pin audit' in s:
    already.append('regtest.cpp: the R353 audit')
else:
    INC_ANCH = (
        '#include "rules/uadruidspells3.h"'
        '  // R352: the UA new druid 3rd'
        ' level')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uadruidspells5.h"'
        '  // R353: the UA new druid 5th'
        ' level',
    ])
    AUD_ANCH = ('    // ---- R227: the wis mental'
                ' save wiring audit ----')
    AUDIT = r"""    // ---- R353: the UA new druid 5th level spells pin audit ----
    // The UA NEW DRUID SPELLS (p. 45), the
    // 5th level - moonbeam (the movable
    // spotlight beam with the color and
    // vision effects) and spike stones
    // (the school discrepancy vs the R347
    // clerical pin flagged; the stat cells
    // seam-check). The digit-garble family
    // decodes the "7 segments" as 1. The
    // item stays open (the 6th-7th levels).
    {
        using namespace rules;
        int bad = 0;
        // U1: moonbeam
        {
            if (strcmp(uad5MoonbeamName(),
                "Moonbeam (Evocation - Alteration)")
                != 0) ++bad;
            // the "## " marker lost - a
            // formatting hole
            if (!uad5MoonbeamHeaderMarkerLost()) ++bad;
            if (!uad5MoonbeamComponentsVSM()) ++bad;
            if (uad5MoonbeamLevel() != 5) ++bad;
            // the "7 segments" family decode
            if (uad5MoonbeamCastingTimeSegments() != 1)
                ++bad;
            // the unit-less range cell - with
            // doubt
            if (uad5MoonbeamRangeInches() != 1) ++bad;
            if (!uad5MoonbeamRangeUnitLost()) ++bad;
            if (!uad5MoonbeamSaveNone()) ++bad;
            if (uad5MoonbeamDurationRoundsPerLevel()
                != 1) ++bad;
            if (!uad5MoonbeamAoeOneInchSpherePlusSpecial())
                ++bad;
            if (!uad5MoonbeamDownwardBeamOnPointedArea())
                ++bad;
            if (!uad5MoonbeamExactMoonlight()) ++bad;
            if (!uad5MoonbeamColorsNotDeterminable())
                ++bad;
            if (!uad5MoonbeamMovesToSeenPointedAreas())
                ++bad;
            if (!uad5MoonbeamEffectiveSpotlight()) ++bad;
            if (!uad5MoonbeamAllowsShadows()) ++bad;
            if (!uad5MoonbeamCenteredCreatureObserved())
                ++bad;
            // the 1 inch dim perception
            if (uad5MoonbeamDimPerceptionInchesBeyond()
                != 1) ++bad;
            if (!uad5MoonbeamNoInfravisionAdverseEffect())
                ++bad;
            if (!uad5MoonbeamEnhancesUltravision()) ++bad;
            // the moonseed and moonstone
            if (!uad5MoonbeamMaterialMoonseedSeeds())
                ++bad;
            if (!uad5MoonbeamMaterialMoonstoneFeldspar())
                ++bad;
        }
        // U2: spike stones
        {
            // the druid school cell prints
            // Enhancement; the R347 clerical
            // pin reads Enchantment
            if (strcmp(uad5SpikeStonesName(),
                "Spike Stones (Alteration/Enhancement)")
                != 0) ++bad;
            if (!uad5SpikeStonesSchoolDiscrepancyFlagged())
                ++bad;
            if (!uad5SpikeStonesComponentsVSM()) ++bad;
            if (uad5SpikeStonesLevel() != 5) ++bad;
            // the empty casting time cell - a
            // hole
            if (!uad5SpikeStonesCastingTimeCellLost())
                ++bad;
            if (uad5SpikeStonesRangeInches() != 3) ++bad;
            if (!uad5SpikeStonesSaveNone()) ++bad;
            if (uad5SpikeStonesDurationTurnsMin() != 3)
                ++bad;
            if (uad5SpikeStonesDurationTurnsMax() != 12)
                ++bad;
            if (uad5SpikeStonesDurationTurnsPerLevel()
                != 1) ++bad;
            if (uad5SpikeStonesAoeSquareInchesPerLevel()
                != 1) ++bad;
            if (uad5SpikeStonesSpikesPerSquareFoot() != 1)
                ++bad;
            if (!uad5SpikeStonesIdenticalToClerical())
                ++bad;
        }
        // U3: the R347 clerical seam
        {
            // The druid spike stones pin
            // seam-checks against the R347
            // clerical pin cell by cell.
            if (uad5SpikeStonesRangeInches()
                != uac5SpikeStonesRangeInches()) ++bad;
            if (uad5SpikeStonesDurationTurnsMin()
                != uac5SpikeStonesDurationTurnsMin())
                ++bad;
            if (uad5SpikeStonesDurationTurnsMax()
                != uac5SpikeStonesDurationTurnsMax())
                ++bad;
            if (uad5SpikeStonesDurationTurnsPerLevel()
                != uac5SpikeStonesDurationTurnsPerLevel())
                ++bad;
            if (uad5SpikeStonesAoeSquareInchesPerLevel()
                != uac5SpikeStonesAoeSquareInchesPerLevel())
                ++bad;
            if (uad5SpikeStonesSpikesPerSquareFoot()
                != uac5SpikeStonesSpikesPerSquareFoot())
                ++bad;
            if (!uac5SpikeStonesSaveNone()) ++bad;
            // the R341 druid 5th-level table
            // prints six PHB names - neither
            // new name seam-checks there; both
            // pin from the prose
            if (uastDruid5thCount() != 6) ++bad;
            if (strcmp(uastDruid5thName(0),
                "Commune With Nature") != 0) ++bad;
            if (strcmp(uastDruid5thName(5),
                "Wall Of Fire") != 0) ++bad;
        }
        printf("R353 UA druid 5th level spells pin audit: bad %d\n", bad);
        if (bad) return 1;
    }"""
    assert s.count(INC_ANCH) == 1, 'd inc anchor'
    assert s.count(AUD_ANCH) == 1, 'd aud anchor'
    clean(INC_NEW, 78)
    clean(AUDIT, 76)
    s = s.replace(INC_ANCH, INC_NEW)
    s = s.replace(AUD_ANCH,
        AUDIT + NL + NL + AUD_ANCH)
    wr(RT, s)
    applied.append('regtest.cpp: the R353 audit')
s = rd(RT)
assert s.count(
    'R353 UA druid 5th level spells'
    ' pin audit: bad ') == 1, 'd audit line'
assert s.count('audit: bad ') == 280, 'd census 280'
assert s.count(
    'R352 UA druid 3rd level spells'
    ' pin audit: bad ') == 1, 'd r352 kept'
assert s.count(
    'R351 UA druid 2nd level spells'
    ' pin audit: bad ') == 1, 'd r351 kept'
assert s.count(
    'R350 UA druid 1st level spells'
    ' pin audit: bad ') == 1, 'd r350 kept'
assert s.count(
    'R349 UA cleric 7th level spells'
    ' pin audit: bad ') == 1, 'd r349 kept'
assert s.count(
    'R347 UA cleric 5th level spells'
    ' pin audit: bad ') == 1, 'd r347 kept'
assert s.count('R227: the wis mental save') == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uadruidspells5.h"') == 1, 'd include'
assert len(applied) + len(already) == 4, 'd count'

# ---- the summary ----
print('R353 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R353 note: the UA new druid spells')
print('pin round, the 5th level - the two')
print('spell descriptions (moonbeam with')
print('the movable spotlight beam and the')
print('color and vision effects, spike')
print('stones identical to the clerical);')
print('the family decodes the 7 as 1; the')
print('spike stones stat cells seam-check')
print('against the R347 clerical pin (the')
print('school cell prints Enhancement where')
print('the clerical reads Enchantment -')
print('flagged; the casting time cell lost);')
print('the item stays open (the 6th-7th')
print('levels); the census 279 -> 280')
print('commit: R353: the UA new druid 5th')
print('level spells pin round (census 280)')

