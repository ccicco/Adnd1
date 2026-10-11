#!/usr/bin/env python3
# R352: the UA NEW DRUID SPELLS pin
# round, the 3rd level (pp. 44-45) -
# cloudburst (the stat-block
# interleave, the call lightning
# exclusion), know alignment (the
# five-creature cap, not reversible),
# spike growth (the material
# interleave) and starshine (the
# school tail lost). The digit-garble
# family decodes the "7 turn/level"
# as 1. The item stays open (the
# 5th-7th levels; the UA prints no
# 4th-level druid section).
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

# ---- (a) the seed: the R351 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R351 landed 2026-10-11: commit',
    '  4f47d8a, census 278, the UA',
    '  new druid 2nd level spells pin',
    '  round (rules/uadruidspells2.h):',
    '  flame blade (the undead and',
    '  fire damage modifiers), the',
    '  goodberry reverse (the name',
    '  header lost), the reflecting',
    '  pool behind the "Pool ion -"',
    '  name garble (the scrying',
    '  mechanics with the',
    '  cast-through ladder) and slow',
    '  poison (the herbal antidote',
    '  chance); the family decodes',
    '  the three 7s as 1; the ritual',
    '  block dropped the invented',
    '  git pull and the paste step -',
    '  gates and landing only. GREEN',
    '  on the first run.',
])
s = rd(SD)
if 'R351 landed 2026-10-11' in s:
    already.append('seed: the R351 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R351 record')
s = rd(SD)
assert s.count('R351 landed 2026-10-11') == 1, 'a entry'
assert s.count('R350 landed 2026-10-11') == 1, 'a r350 kept'
assert s.count('R349 landed 2026-10-11') == 1, 'a r349 kept'
assert s.count('R348 landed 2026-10-11') == 1, 'a r348 kept'
assert s.count('R347 landed 2026-10-11') == 1, 'a r347 kept'
assert s.count('R346 landed 2026-10-11') == 1, 'a r346 kept'
assert s.count('R345 landed 2026-10-11') == 1, 'a r345 kept'
assert s.count('R344 landed 2026-10-11') == 1, 'a r344 kept'
assert s.count('R343 landed 2026-10-11') == 1, 'a r343 kept'
assert s.count('R342 landed 2026-10-11') == 1, 'a r342 kept'
assert s.count('R341 landed 2026-10-11') == 1, 'a r341 kept'
assert s.count('R340 landed 2026-10-11') == 1, 'a r340 kept'
assert s.count('## Knowledge maintenance') == 1, 'a maint'
assert len(applied) + len(already) == 1, 'a count'

# ---- (b) NEW rules/uadruidspells3.h ----
US = 'rules/uadruidspells3.h'
if os.path.exists(US) and 'R352' in rd(US):
    already.append('uadruidspells3.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uadruidspells3.h
// The UA NEW DRUID SPELLS (pp. 44-45) pins, R352: the 3rd-level
// spell descriptions - cloudburst, know alignment, spike growth
// and starshine.
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
//
// JUDGMENTs (the decode method):
//   - the digit-garble family (the R343 precedent): the starshine
//     duration prints "7 turn/level" - the family decodes
//     1 turn/level (starshine prints a clean "Level: 3" cell).
//   - the cloudburst stat block scrambles both columns into one
//     print: "pid pve; 3 Effect: 1 ro 4 diam. cylinder up to
//     Components: Casting Saving 6" high Throw: Time: V, 5 None
//     S, segments M (& special)" plus the stray "vol" and "Area
//     of" fragments. Reassembly: Components V, S, M; Level 3;
//     Casting Time 5 segments; Saving Throw None (& special);
//     Duration 1 round/level (the "1 ro" + "vol" split);
//     Area of Effect a 4" diameter cylinder up to 6" high. The
//     "pid pve;" fragment is a lost head - a hole. The range
//     never prints - a hole.
//   - the cloudburst prose head scrambles: "This spell is the
//     same as the 3rd-level clerical spell of the same name,
//     with only the following special notations and additions:"
//     with the call lightning fragments interleaved - decoded as
//     the exclusion: a call lightning spell cannot be used in
//     the same area at the same time.
//   - the know alignment components cell prints "V, S\$" - the
//     S-garble family (the R343 "V, §" precedent); decoded.
//   - the know alignment prose: same as the 2nd-level clerical
//     spell except as noted in the stat cells; because of the
//     shorter duration only five creatures (maximum) can be
//     examined, and it cannot be reversed.
//   - the spike growth prose head prints "This spell i ... ially
//     the same as" - the lost head decodes as "is essentially".
//     The interleave reassembly: the affected area will radiate
//     an aura; a detect magic [spell] will reveal the location
//     of pits and snares; the druid must use mistletoe as an
//     addition to the material component of spike growth, in
//     place of the cleric's holy symbol, [and] seven small
//     twigs or thorns.
//   - the starshine name header prints "Starshine (Evocation -"
//     [sic]) - the school tail is lost; the school pins as
//     Evocation with the tail flagged as a hole.
//   - the starshine prose prints clean: the vision bands (clear
//     to 30', indistinct to 60', gleams beyond), the ultravision
//     enhancement without infravision effect, the disbelief
//     reveal, and the amaryllis plus holly berry components.
//
// OCR holes (the item stays open - the 5th-7th levels pin in
// later rounds - note the UA prints no 4th-level druid section;
// these stay pending the PDF): the cloudburst "pid pve;"
// head fragment; the cloudburst range cell; the know alignment
// "except as noted above" referents beyond the stat cells; the
// spike growth aura/detect-magic clause beyond the fragments;
// the starshine school tail.
// ===========================================================================

#pragma once

namespace rules {

// ---- cloudburst (Alteration), p. 44 ----
inline const char* uad3CloudburstName()
    { return "Cloudburst (Alteration)"; }

inline bool uad3CloudburstComponentsVSM()
    { return true; }

inline int uad3CloudburstLevel()
    { return 3; }

inline int uad3CloudburstCastingTimeSegments()
    { return 5; }

// The saving throw prints "None (& special)".
inline bool uad3CloudburstSaveNoneAndSpecial()
    { return true; }

// The duration decodes from the "1 ro" + "vol" fragments as
// 1 round/level (the stat block interleave).
inline int uad3CloudburstDurationRoundsPerLevel()
    { return 1; }

inline int uad3CloudburstCylinderDiameterInches()
    { return 4; }

inline int uad3CloudburstCylinderHeightInches()
    { return 6; }

inline bool uad3CloudburstStatBlockInterleaveDecoded()
    { return true; }

// The "pid pve;" fragment and the missing range cell - holes.
inline bool uad3CloudburstHeadFragmentLost()
    { return true; }

inline bool uad3CloudburstRangeLost()
    { return true; }

// The prose head scramble decodes: this spell is the same as
// the 3rd-level clerical spell of the same name.
inline bool uad3CloudburstIdenticalToClerical3rd()
    { return true; }

// The special notation: a call lightning spell cannot be used
// in the same area at the same time (the interleave decode).
inline bool uad3CloudburstCallLightningExclusion()
    { return true; }

inline bool uad3CloudburstProseHeadScrambleDecoded()
    { return true; }

// The druid must use mistletoe as an additional material
// component (prints clean).
inline bool uad3CloudburstMaterialMistletoe()
    { return true; }

// ---- know alignment (Divination), p. 44 ----
inline const char* uad3KnowAlignmentName()
    { return "Know Alignment (Divination)"; }

// The components cell prints "V, S$" - the S-garble family.
inline bool uad3KnowAlignmentComponentsVSGarble()
    { return true; }

inline int uad3KnowAlignmentLevel()
    { return 3; }

inline int uad3KnowAlignmentRangeInches()
    { return 1; }

inline int uad3KnowAlignmentDurationRounds()
    { return 5; }

inline bool uad3KnowAlignmentAoeOnePerRound()
    { return true; }

inline int uad3KnowAlignmentCastingTimeSegments()
    { return 5; }

inline bool uad3KnowAlignmentSaveNone()
    { return true; }

// The prose head scramble decodes: this spell is the same as
// the 2nd-level clerical spell of the same name, except as
// noted in the stat cells.
inline bool uad3KnowAlignmentIdenticalToClerical2nd()
    { return true; }

// Because of the shorter duration, only five creatures
// (maximum) can be examined.
inline int uad3KnowAlignmentMaxCreaturesExamined()
    { return 5; }

inline bool uad3KnowAlignmentCannotBeReversed()
    { return true; }

// ---- spike growth (Alteration/Enchantment), p. 45 ----
inline const char* uad3SpikeGrowthName()
    { return "Spike Growth (Alteration/Enchantment)"; }

inline bool uad3SpikeGrowthComponentsVSM()
    { return true; }

inline int uad3SpikeGrowthLevel()
    { return 3; }

inline int uad3SpikeGrowthCastingTimeSegments()
    { return 5; }

inline int uad3SpikeGrowthRangeInches()
    { return 6; }

inline bool uad3SpikeGrowthSaveNone()
    { return true; }

inline int uad3SpikeGrowthDurationTurnsMin()
    { return 3; }

inline int uad3SpikeGrowthDurationTurnsMax()
    { return 12; }

inline int uad3SpikeGrowthDurationTurnsPerLevel()
    { return 1; }

inline int uad3SpikeGrowthAoeSquaresPerLevel()
    { return 10; }

// The prose head prints "This spell i ... ially the same as" -
// the lost head decodes as "is essentially" - this spell is
// essentially the same as the 4th-level clerical spell of the
// same name, except as noted above.
inline bool uad3SpikeGrowthIdenticalToClerical4th()
    { return true; }

inline bool uad3SpikeGrowthHeadDecodeEssentially()
    { return true; }

// The interleave: the affected area will radiate an aura, and a
// detect magic [spell] will reveal the location of pits and
// snares.
inline bool uad3SpikeGrowthRadiatesAura()
    { return true; }

inline bool uad3SpikeGrowthDetectMagicRevealsPitsAndSnares()
    { return true; }

// The material interleave decode: mistletoe as an addition to
// the material component of spike growth, in place of the
// cleric's holy symbol, and seven small twigs or thorns.
inline bool uad3SpikeGrowthMaterialMistletoe()
    { return true; }

inline bool uad3SpikeGrowthMaterialInPlaceOfHolySymbol()
    { return true; }

inline int uad3SpikeGrowthMaterialTwigsOrThorns()
    { return 7; }

inline bool uad3SpikeGrowthMaterialInterleaveDecoded()
    { return true; }

// ---- starshine (Evocation - ...), p. 45 ----
inline const char* uad3StarshineName()
    { return "Starshine"; }

// The name header prints "Starshine (Evocation -" [sic]) - the
// school tail is lost; the school pins as Evocation with the
// tail flagged.
inline bool uad3StarshineSchoolEvocation()
    { return true; }

inline bool uad3StarshineSchoolTailLost()
    { return true; }

inline bool uad3StarshineComponentsVSM()
    { return true; }

inline int uad3StarshineLevel()
    { return 3; }

inline int uad3StarshineCastingTimeSegments()
    { return 5; }

inline int uad3StarshineRangeInchesPerLevel()
    { return 1; }

inline bool uad3StarshineSaveNone()
    { return true; }

// The duration prints "7 turn/level" - the digit-garble family
// decodes 1 turn/level.
inline int uad3StarshineDurationTurnsPerLevel()
    { return 1; }

inline int uad3StarshineAoeSquaresPerLevel()
    { return 10; }

// Softly illuminates an area as if exposed to a clear night sky
// filled with stars; regardless of the height of the open area,
// the ground immediately beneath is lit by starshine.
inline bool uad3StarshineNightSkyIllumination()
    { return true; }

inline bool uad3StarshineRegardlessOfHeight()
    { return true; }

// Vision is clear at up to 30 feet, indistinct out to 60 feet,
// and beyond that only gleams and glimmers are discernible.
inline int uad3StarshineVisionClearFeet()
    { return 30; }

inline int uad3StarshineVisionIndistinctFeet()
    { return 60; }

inline bool uad3StarshineGleamsBeyond()
    { return true; }

// The starshine allows shadows; it enhances ultravision to its
// full potential but does not affect infravision.
inline bool uad3StarshineAllowsShadows()
    { return true; }

inline bool uad3StarshineEnhancesUltravision()
    { return true; }

inline bool uad3StarshineNoInfravisionEffect()
    { return true; }

// The area appears to be a night sky, but disbelief merely
// allows the disbeliever to note that the "stars" are actually
// evoked lights.
inline bool uad3StarshineDisbeliefRevealsEvokedLights()
    { return true; }

// The material: several stalks from an amaryllis (especially
// Hypoxis) and several holly berries.
inline bool uad3StarshineMaterialAmaryllisStalks()
    { return true; }

inline bool uad3StarshineMaterialHollyBerries()
    { return true; }

// The R351 reflecting pool seam: starshine operates normally
// through the reflecting pool (see rules/uadruidspells2.h).
inline bool uad3StarshineWorksThroughReflectingPool()
    { return true; }

}   // namespace rules"""
    clean(HDR, 78)
    wr(US, HDR + NL)
    applied.append('uadruidspells3.h: the pins')
s = rd(US)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 66, 'b inline count'
assert s.count('R352') == 1, 'b round tag'
assert s.count('uad3StarshineWorksThroughReflectingPool()') == 1, 'b seam fn'
assert s.count('uad3CloudburstName()') == 1, 'b cloudburst fn'
assert 'uastDruid' not in s, 'b no r341 ref'
assert 'uad2' not in s and 'uad1' not in s, 'b no prior refs'
assert len(applied) + len(already) == 2, 'b count'

# ---- (c) the gap report: the note (the
# item STAYS OPEN - the 5th-7th levels) ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'R352: the 3rd level pinned' in s:
    already.append('gap report: the note')
else:
    TAIL_OLD = NL.join([
        '        through 7th levels stay open.',
        '- [ ] **The new magic-user spells**',
    ])
    assert s.count(TAIL_OLD) == 1, 'c tail'
    NOTE = NL.join([
    '      - R352: the 3rd level pinned',
    '        (rules/uadruidspells3.h) - the',
    '        four spell descriptions',
    '        (cloudburst with the stat-',
    '        block interleave and the',
    '        call lightning exclusion,',
    '        know alignment with the',
    '        five-creature cap and the',
    '        no-reverse gate, spike',
    '        growth with the material',
    '        interleave, starshine with',
    '        the school tail lost); the',
    '        family decodes the 7 as 1',
    '        and the cloudburst',
    '        duration decodes from the',
    '        "1 ro" + "vol" fragments;',
    '        starshine seam-checks',
    '        against the R351 reflecting',
    '        pool pin; the R341 druid',
    '        table prints no 3rd-level',
    '        roster - all four names pin',
    '        from the prose; the 5th',
    '        through 7th levels stay open',
    '        (the UA prints no 4th-level',
    '        druid section).',
])
    clean(NOTE, 57)
    s = s.replace(TAIL_OLD, NL.join([
        '        through 7th levels stay open.',
        NOTE,
        '- [ ] **The new magic-user spells**',
    ]))
    wr(GP, s)
    applied.append('gap report: the note')
s = rd(GP)
assert s.count('R352: the 3rd level pinned') == 1, 'c note'
assert s.count('- [ ] **The new druid spells**'
    ' (pp.') == 1, 'c stays open'
assert s.count('R351: the 2nd level pinned') == 1, 'c r351 kept'
assert s.count('R350: the 1st level pinned') == 1, 'c r350 kept'
assert s.count('R349: the 7th level pinned') == 1, 'c r349 kept'
assert s.count('CLOSED R349') == 1, 'c r349 closed kept'
assert s.count('R348: the 6th level pinned') == 1, 'c r348 kept'
assert s.count('R343: the 1st level pinned') == 1, 'c r343 kept'
assert len(applied) + len(already) == 3, 'c count'

# ---- (d) regtest.cpp: the include, the
# audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R352 UA druid 3rd level spells pin audit' in s:
    already.append('regtest.cpp: the R352 audit')
else:
    INC_ANCH = (
        '#include "rules/uadruidspells2.h"'
        '  // R351: the UA new druid 2nd'
        ' level')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uadruidspells3.h"'
        '  // R352: the UA new druid 3rd'
        ' level',
    ])
    AUD_ANCH = ('    // ---- R227: the wis mental'
                ' save wiring audit ----')
    AUDIT = r"""    // ---- R352: the UA new druid 3rd level spells pin audit ----
    // The UA NEW DRUID SPELLS (pp. 44-45),
    // the 3rd level - cloudburst (the
    // stat-block interleave with the call
    // lightning exclusion), know alignment
    // (the five-creature cap, not
    // reversible), spike growth (the
    // mistletoe-plus-twigs material
    // interleave) and starshine (the school
    // tail lost). The digit-garble family
    // decodes the "7 turn/level" as 1; the
    // cloudburst duration decodes from the
    // "1 ro" + "vol" fragments. The item
    // stays open (the 5th-7th levels; the UA
    // prints no 4th-level druid section).
    {
        using namespace rules;
        int bad = 0;
        // U1: cloudburst
        {
            if (strcmp(uad3CloudburstName(),
                "Cloudburst (Alteration)") != 0) ++bad;
            if (!uad3CloudburstComponentsVSM()) ++bad;
            if (uad3CloudburstLevel() != 3) ++bad;
            if (uad3CloudburstCastingTimeSegments() != 5)
                ++bad;
            if (!uad3CloudburstSaveNoneAndSpecial()) ++bad;
            // the "1 ro" + "vol" duration decode
            if (uad3CloudburstDurationRoundsPerLevel()
                != 1) ++bad;
            if (uad3CloudburstCylinderDiameterInches()
                != 4) ++bad;
            if (uad3CloudburstCylinderHeightInches() != 6)
                ++bad;
            if (!uad3CloudburstStatBlockInterleaveDecoded())
                ++bad;
            // the "pid pve;" fragment and the
            // missing range cell - holes
            if (!uad3CloudburstHeadFragmentLost()) ++bad;
            if (!uad3CloudburstRangeLost()) ++bad;
            if (!uad3CloudburstIdenticalToClerical3rd())
                ++bad;
            // the call lightning exclusion
            if (!uad3CloudburstCallLightningExclusion())
                ++bad;
            if (!uad3CloudburstProseHeadScrambleDecoded())
                ++bad;
            if (!uad3CloudburstMaterialMistletoe()) ++bad;
        }
        // U2: know alignment
        {
            if (strcmp(uad3KnowAlignmentName(),
                "Know Alignment (Divination)") != 0) ++bad;
            // the "V, S$" S-garble family
            if (!uad3KnowAlignmentComponentsVSGarble())
                ++bad;
            if (uad3KnowAlignmentLevel() != 3) ++bad;
            if (uad3KnowAlignmentRangeInches() != 1) ++bad;
            if (uad3KnowAlignmentDurationRounds() != 5)
                ++bad;
            if (!uad3KnowAlignmentAoeOnePerRound()) ++bad;
            if (uad3KnowAlignmentCastingTimeSegments() != 5)
                ++bad;
            if (!uad3KnowAlignmentSaveNone()) ++bad;
            if (!uad3KnowAlignmentIdenticalToClerical2nd())
                ++bad;
            // the five-creature cap
            if (uad3KnowAlignmentMaxCreaturesExamined()
                != 5) ++bad;
            if (!uad3KnowAlignmentCannotBeReversed()) ++bad;
        }
        // U3: spike growth
        {
            if (strcmp(uad3SpikeGrowthName(),
                "Spike Growth (Alteration/Enchantment)")
                != 0) ++bad;
            if (!uad3SpikeGrowthComponentsVSM()) ++bad;
            if (uad3SpikeGrowthLevel() != 3) ++bad;
            if (uad3SpikeGrowthCastingTimeSegments() != 5)
                ++bad;
            if (uad3SpikeGrowthRangeInches() != 6) ++bad;
            if (!uad3SpikeGrowthSaveNone()) ++bad;
            // the 3-12 turns + 1/level duration
            if (uad3SpikeGrowthDurationTurnsMin() != 3)
                ++bad;
            if (uad3SpikeGrowthDurationTurnsMax() != 12)
                ++bad;
            if (uad3SpikeGrowthDurationTurnsPerLevel()
                != 1) ++bad;
            if (uad3SpikeGrowthAoeSquaresPerLevel() != 10)
                ++bad;
            // the "is essentially" head decode
            if (!uad3SpikeGrowthIdenticalToClerical4th())
                ++bad;
            if (!uad3SpikeGrowthHeadDecodeEssentially())
                ++bad;
            if (!uad3SpikeGrowthRadiatesAura()) ++bad;
            if (!uad3SpikeGrowthDetectMagicRevealsPitsAndSnares())
                ++bad;
            // the material interleave
            if (!uad3SpikeGrowthMaterialMistletoe()) ++bad;
            if (!uad3SpikeGrowthMaterialInPlaceOfHolySymbol())
                ++bad;
            if (uad3SpikeGrowthMaterialTwigsOrThorns()
                != 7) ++bad;
            if (!uad3SpikeGrowthMaterialInterleaveDecoded())
                ++bad;
        }
        // U4: starshine
        {
            if (strcmp(uad3StarshineName(),
                "Starshine") != 0) ++bad;
            // the school prints "Evocation -"
            // with the tail lost
            if (!uad3StarshineSchoolEvocation()) ++bad;
            if (!uad3StarshineSchoolTailLost()) ++bad;
            if (!uad3StarshineComponentsVSM()) ++bad;
            if (uad3StarshineLevel() != 3) ++bad;
            if (uad3StarshineCastingTimeSegments() != 5)
                ++bad;
            if (uad3StarshineRangeInchesPerLevel() != 1)
                ++bad;
            if (!uad3StarshineSaveNone()) ++bad;
            // the "7 turn/level" family decode
            if (uad3StarshineDurationTurnsPerLevel()
                != 1) ++bad;
            if (uad3StarshineAoeSquaresPerLevel() != 10)
                ++bad;
            if (!uad3StarshineNightSkyIllumination()) ++bad;
            if (!uad3StarshineRegardlessOfHeight()) ++bad;
            // the vision bands
            if (uad3StarshineVisionClearFeet() != 30) ++bad;
            if (uad3StarshineVisionIndistinctFeet() != 60)
                ++bad;
            if (!uad3StarshineGleamsBeyond()) ++bad;
            if (!uad3StarshineAllowsShadows()) ++bad;
            if (!uad3StarshineEnhancesUltravision()) ++bad;
            if (!uad3StarshineNoInfravisionEffect()) ++bad;
            if (!uad3StarshineDisbeliefRevealsEvokedLights())
                ++bad;
            // the amaryllis and holly berries
            if (!uad3StarshineMaterialAmaryllisStalks())
                ++bad;
            if (!uad3StarshineMaterialHollyBerries()) ++bad;
            if (!uad3StarshineWorksThroughReflectingPool())
                ++bad;
        }
        // U5: the cross-round and R341 seams
        {
            // the R351 reflecting pool pin named
            // starshine as operating through the
            // pool - both ends now pin
            if (!uad2ReflectingPoolStarshineOperates())
                ++bad;
            if (!uad3StarshineWorksThroughReflectingPool())
                ++bad;
            // the R341 druid table prints no
            // 3rd-level roster - all four names
            // pin from the prose
            if (uastDruid1stCount() != 4) ++bad;
            if (strcmp(uastDruid1stName(2),
                "Shillelagh") != 0) ++bad;
            if (uastDruid4thCount() != 6) ++bad;
            if (strcmp(uastDruid4thName(2),
                "Hallucinatory Forest") != 0) ++bad;
            if (uastDruid6thCount() != 5) ++bad;
            if (strcmp(uastDruid6thName(4),
                "Weather Summoning") != 0) ++bad;
        }
        printf("R352 UA druid 3rd level spells pin audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R352 audit')
s = rd(RT)
assert s.count(
    'R352 UA druid 3rd level spells'
    ' pin audit: bad ') == 1, 'd audit line'
assert s.count('audit: bad ') == 279, 'd census 279'
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
    'R343 UA cleric 1st level spells'
    ' pin audit: bad ') == 1, 'd r343 kept'
assert s.count('R227: the wis mental save') == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uadruidspells3.h"') == 1, 'd include'
assert len(applied) + len(already) == 4, 'd count'

# ---- the summary ----
print('R352 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R352 note: the UA new druid spells')
print('pin round, the 3rd level - the four')
print('spell descriptions (cloudburst with')
print('the stat-block interleave and the')
print('call lightning exclusion, know')
print('alignment with the five-creature')
print('cap and the no-reverse gate, spike')
print('growth with the material interleave,')
print('starshine with the school tail')
print('lost); the family decodes the 7 as')
print('1 and the cloudburst duration from')
print('the "1 ro" + "vol" fragments; starshine')
print('seam-checks against the R351')
print('reflecting pool pin; the item stays')
print('open (the 5th-7th levels; the UA')
print('prints no 4th-level druid section);')
print('the census 278 -> 279')
print('commit: R352: the UA new druid 3rd')
print('level spells pin round (census 279)')

