#!/usr/bin/env python3
# R354: the UA NEW DRUID SPELLS pin
# round, the 6th level (p. 45) -
# liveoak (the triggered treant,
# the 3-inch movement interleave
# decode) and water to dust (the
# name garble, the muddy
# multipliers and the water-native
# save gate). The digit-garble
# family decodes the "7 turn" as 1.
# The item stays open (the 7th
# level).
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

# ---- (a) the seed: the R353 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '- R353 landed 2026-10-11: commit',
    '  cef4de6, census 280, the UA',
    '  new druid 5th level spells pin',
    '  round (rules/uadruidspells5.h):',
    '  moonbeam (the movable spotlight',
    '  beam with the color and vision',
    '  effects) and spike stones',
    '  (identical to the clerical); the',
    '  spike stones stat cells',
    '  seam-check the R347 clerical pin',
    '  exactly - but the school cell',
    '  prints Enhancement where the',
    '  clerical reads Enchantment',
    '  (flagged pending the PDF); the',
    '  casting time cell lost. GREEN on',
    '  the first run.',
])
s = rd(SD)
if 'R353 landed 2026-10-11' in s:
    already.append('seed: the R353 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R353 record')
s = rd(SD)
assert s.count('R353 landed 2026-10-11') == 1, 'a entry'
assert s.count('R352 landed 2026-10-11') == 1, 'a r352 kept'
assert s.count('R351 landed 2026-10-11') == 1, 'a r351 kept'
assert s.count('R350 landed 2026-10-11') == 1, 'a r350 kept'
assert s.count('R349 landed 2026-10-11') == 1, 'a r349 kept'
assert s.count('R348 landed 2026-10-11') == 1, 'a r348 kept'
assert s.count('R347 landed 2026-10-11') == 1, 'a r347 kept'
assert s.count('R343 landed 2026-10-11') == 1, 'a r343 kept'
assert s.count('## Knowledge maintenance') == 1, 'a maint'
assert len(applied) + len(already) == 1, 'a count'

# ---- (b) NEW rules/uadruidspells6.h ----
US = 'rules/uadruidspells6.h'
if os.path.exists(US) and 'R354' in rd(US):
    already.append('uadruidspells6.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uadruidspells6.h
// The UA NEW DRUID SPELLS (p. 45) pins, R354: the 6th-level
// spell descriptions - liveoak and water to dust.
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
//
// JUDGMENTs (the decode method):
//   - the digit-garble family (the R343 precedent): the liveoak
//     casting time prints "7 turn" - the family decodes
//     1 turn (liveoak prints a clean "Level: 6" cell; water to
//     dust prints a clean 6 and a clean "8 segments").
//   - the water to dust name header prints "Water To Dust (,"
//     [sic]) -
//     the school is lost in the garble; the gap item list calls
//     it "transmute water to dust" - the spell pins as Water To
//     Dust with the school and the transmute prefix flagged as
//     holes.
//   - the water to dust stat block interleaves both columns:
//     the components cell prints only "V,"; the prose pins the
//     full components (diamond dust of at least 500 gp value, a
//     bit of seashell, and the druid's mistletoe; the reverse
//     adds a pinch of normal dust).
//   - the liveoak treant interleave: ", matching the
//     specifications of the Monster Manual de-" + "scription,
//     but with only a 3\" + "rate. An oak" reassembles as:
//     matching the Monster Manual description, but with only a
//     3" movement rate. An oak spell will radiate a magic
//     aura - the word between 3" and "rate" position-decodes as
//     "movement", flagged with doubt pending the PDF.
//
// OCR holes (the item stays open - the 7th level pins in the
// next round; these stay pending the PDF): the liveoak movement
// word; the water to dust school and transmute prefix; the
// water to dust components cell beyond the "V," fragment.
// ===========================================================================

#pragma once

namespace rules {

// ---- liveoak (Enchantment), p. 45 ----
inline const char* uad6LiveoakName()
    { return "Liveoak (Enchantment)"; }

inline bool uad6LiveoakComponentsVSM()
    { return true; }

inline int uad6LiveoakLevel()
    { return 6; }

inline bool uad6LiveoakRangeTouch()
    { return true; }

inline int uad6LiveoakDurationDaysPerLevel()
    { return 1; }

inline bool uad6LiveoakAoeOneOakTree()
    { return true; }

// The casting time prints "7 turn" - the digit-garble family
// decodes 1 turn.
inline int uad6LiveoakCastingTimeTurns()
    { return 1; }

inline bool uad6LiveoakSaveNone()
    { return true; }

// The spell is cast on but a single tree at a time, and while a
// liveoak cast by a particular druid is in effect, he or she
// cannot cast another such spell.
inline bool uad6LiveoakSingleTreeAtATime()
    { return true; }

inline bool uad6LiveoakOnlyOnePerDruid()
    { return true; }

// The tree must be within 10 feet of the druid's dwelling
// place, within a place sacred to the druid, or within 10
// inches of something which the druid wishes to guard or
// protect.
inline int uad6LiveoakDwellingFeet()
    { return 10; }

inline bool uad6LiveoakWithinSacredPlace()
    { return true; }

inline int uad6LiveoakGuardedInches()
    { return 10; }

// A healthy tree of small, medium, or large size, according to
// desire and availability.
inline bool uad6LiveoakSizePerDesireAndAvailability()
    { return true; }

// A triggering phrase of up to one word per level of the caster
// is placed upon the dweomered oak.
inline int uad6LiveoakTriggerWordsPerLevel()
    { return 1; }

// The example: an 11-word trigger usable by a druid of 11th or
// higher level - attack any persons who come near without
// first saying the sacred mistletoe phrase.
inline int uad6LiveoakExampleTriggerWords()
    { return 11; }

inline int uad6LiveoakExampleCasterLevel()
    { return 11; }

// The liveoak triggers the tree into becoming a treant of
// appropriate size and attack capability, matching the Monster
// Manual specification.
inline bool uad6LiveoakBecomesTreantMmSpec()
    { return true; }

// The treant moves with only a 3-inch movement rate (the
// interleave decode; the movement word position-decoded with
// doubt).
inline int uad6LiveoakTreantMovementRateInches()
    { return 3; }

inline bool uad6LiveoakMovementWordDecoded()
    { return true; }

// The oak spell radiates a magic aura, and can be returned to
// normal by a successful dispel magic or upon the desire of the
// druid who enchanted it.
inline bool uad6LiveoakRadiatesMagicAura()
    { return true; }

inline bool uad6LiveoakDispelOrDesireReturns()
    { return true; }

inline bool uad6LiveoakMaterialMistletoe()
    { return true; }

// ---- water to dust, p. 45 ----
// The name header prints "Water To Dust (," [sic]) - the
// school is
// lost in the garble; the gap item list calls the spell
// "transmute water to dust".
inline const char* uad6WaterToDustName()
    { return "Water To Dust"; }

inline bool uad6WaterToDustNameHeaderGarbled()
    { return true; }

inline bool uad6WaterToDustSchoolLost()
    { return true; }

inline bool uad6WaterToDustGapItemSaysTransmute()
    { return true; }

// The components cell prints only "V," - a hole; the prose pins
// the full components.
inline bool uad6WaterToDustComponentsCellLost()
    { return true; }

inline int uad6WaterToDustLevel()
    { return 6; }

inline int uad6WaterToDustRangeInches()
    { return 6; }

inline int uad6WaterToDustCastingTimeSegments()
    { return 8; }

inline bool uad6WaterToDustSaveNoneAndSpecial()
    { return true; }

inline bool uad6WaterToDustDurationPermanent()
    { return true; }

inline int uad6WaterToDustAoeCubicInchesPerLevel()
    { return 1; }

// The stat block interleaves both columns; the prose opener
// splits as "in-" + "stantly" across the block.
inline bool uad6WaterToDustStatBlockInterleaveDecoded()
    { return true; }

// The subject area instantly undergoes a change from liquid to
// powdery dust.
inline bool uad6WaterToDustLiquidToPowderyDust()
    { return true; }

// Muddy water expands the area of effect to double normal; wet
// mud quadruples it.
inline int uad6WaterToDustMuddyAreaMultiplier()
    { return 2; }

inline int uad6WaterToDustWetMudAreaMultiplier()
    { return 4; }

// Water remaining in contact with the transmuted dust quickly
// permeates it, turning the dust into silty mud if a
// sufficient quantity exists, otherwise soaking or dampening
// accordingly.
inline bool uad6WaterToDustContactFormsSiltyMud()
    { return true; }

// Only liquid actually existing in the area at the moment of
// casting is affected.
inline bool uad6WaterToDustOnlyLiquidAtCasting()
    { return true; }

// Liquids only partially water are affected as far as the
// actual water is concerned; potions containing water as a
// component part are rendered useless.
inline bool uad6WaterToDustPartialWaterAffected()
    { return true; }

inline bool uad6WaterToDustPotionsRenderedUseless()
    { return true; }

// Living creatures are unaffected, except those native to the
// Elemental Plane of Water: they receive a saving throw versus
// spell to escape, and only one such creature can be affected
// by any single casting, regardless of size (creature or area).
inline bool uad6WaterToDustLivingUnaffectedExceptWaterNatives()
    { return true; }

inline bool uad6WaterToDustWaterNativeSaveVsSpell()
    { return true; }

inline bool uad6WaterToDustOneCreaturePerCasting()
    { return true; }

// The reverse is simply a very high-powered create water spell
// requiring a pinch of normal dust as an additional material
// component.
inline bool uad6WaterToDustReverseCreateWater()
    { return true; }

inline bool uad6WaterToDustReverseAddsDustPinch()
    { return true; }

// For either usage: diamond dust of at least 500 gp value, a
// bit of seashell, and the druid's mistletoe.
inline int uad6WaterToDustDiamondDustMinGp()
    { return 500; }

inline bool uad6WaterToDustMaterialSeashell()
    { return true; }

inline bool uad6WaterToDustMaterialMistletoe()
    { return true; }

}   // namespace rules"""
    clean(HDR, 78)
    wr(US, HDR + NL)
    applied.append('uadruidspells6.h: the pins')
s = rd(US)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 50, 'b inline count'
assert s.count('R354') == 1, 'b round tag'
assert s.count('uad6LiveoakName()') == 1, 'b liveoak fn'
assert s.count('uad6WaterToDustDiamondDustMinGp()') == 1, 'b dust fn'
assert 'uastDruid' not in s, 'b no r341 ref'
assert 'uac5' not in s, 'b no r347 ref'
assert 'uad5' not in s, 'b no r353 ref'
assert len(applied) + len(already) == 2, 'b count'

# ---- (c) the gap report: the note (the
# item STAYS OPEN - the 7th level) ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'R354: the 6th level pinned' in s:
    already.append('gap report: the note')
else:
    TAIL_OLD = NL.join([
        '        seam-checks there; the 6th and',
        '        7th levels stay open.',
        '- [ ] **The new magic-user spells**',
    ])
    assert s.count(TAIL_OLD) == 1, 'c tail'
    NOTE = NL.join([
        '      - R354: the 6th level pinned',
        '        (rules/uadruidspells6.h) - the',
        '        two spell descriptions (liveoak',
        '        with the triggered treant and',
        '        the 3-inch movement decode,',
        '        water to dust behind the name',
        '        garble with the muddy',
        '        multipliers and the',
        '        water-native save gate); the',
        '        family decodes the 7 as 1',
        '        (water to dust prints the',
        '        clean 6 and 8); the R341 druid',
        '        6th table prints five PHB',
        '        names - neither new name',
        '        seam-checks there; the 7th',
        '        level stays open.',
    ])
    clean(NOTE, 57)
    s = s.replace(TAIL_OLD, NL.join([
        '        seam-checks there; the 6th and',
        '        7th levels stay open.',
        NOTE,
        '- [ ] **The new magic-user spells**',
    ]))
    wr(GP, s)
    applied.append('gap report: the note')
s = rd(GP)
assert s.count('R354: the 6th level pinned') == 1, 'c note'
assert s.count('- [ ] **The new druid spells**'
    ' (pp.') == 1, 'c stays open'
assert s.count('R353: the 5th level pinned') == 1, 'c r353 kept'
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
if 'R354 UA druid 6th level spells pin audit' in s:
    already.append('regtest.cpp: the R354 audit')
else:
    INC_ANCH = (
        '#include "rules/uadruidspells5.h"'
        '  // R353: the UA new druid 5th'
        ' level')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uadruidspells6.h"'
        '  // R354: the UA new druid 6th'
        ' level',
    ])
    AUD_ANCH = ('    // ---- R227: the wis mental'
                ' save wiring audit ----')
    AUDIT = r"""    // ---- R354: the UA new druid 6th level spells pin audit ----
    // The UA NEW DRUID SPELLS (p. 45), the
    // 6th level - liveoak (the triggered
    // treant with the 3-inch movement
    // decode) and water to dust (the
    // scrambled stat block with the muddy
    // multipliers and the water-native
    // save gate). The digit-garble family
    // decodes the "7 turn" as 1. The item
    // stays open (the 7th level).
    {
        using namespace rules;
        int bad = 0;
        // U1: liveoak
        {
            if (strcmp(uad6LiveoakName(),
                "Liveoak (Enchantment)") != 0) ++bad;
            if (!uad6LiveoakComponentsVSM()) ++bad;
            if (uad6LiveoakLevel() != 6) ++bad;
            if (!uad6LiveoakRangeTouch()) ++bad;
            if (uad6LiveoakDurationDaysPerLevel() != 1)
                ++bad;
            if (!uad6LiveoakAoeOneOakTree()) ++bad;
            // the "7 turn" family decode
            if (uad6LiveoakCastingTimeTurns() != 1) ++bad;
            if (!uad6LiveoakSaveNone()) ++bad;
            if (!uad6LiveoakSingleTreeAtATime()) ++bad;
            if (!uad6LiveoakOnlyOnePerDruid()) ++bad;
            // the three placement bounds
            if (uad6LiveoakDwellingFeet() != 10) ++bad;
            if (!uad6LiveoakWithinSacredPlace()) ++bad;
            if (uad6LiveoakGuardedInches() != 10) ++bad;
            if (!uad6LiveoakSizePerDesireAndAvailability())
                ++bad;
            // the trigger phrase ladder
            if (uad6LiveoakTriggerWordsPerLevel() != 1)
                ++bad;
            if (uad6LiveoakExampleTriggerWords() != 11)
                ++bad;
            if (uad6LiveoakExampleCasterLevel() != 11)
                ++bad;
            if (!uad6LiveoakBecomesTreantMmSpec()) ++bad;
            // the 3-inch movement decode
            if (uad6LiveoakTreantMovementRateInches() != 3)
                ++bad;
            if (!uad6LiveoakMovementWordDecoded()) ++bad;
            if (!uad6LiveoakRadiatesMagicAura()) ++bad;
            if (!uad6LiveoakDispelOrDesireReturns()) ++bad;
            if (!uad6LiveoakMaterialMistletoe()) ++bad;
        }
        // U2: water to dust
        {
            if (strcmp(uad6WaterToDustName(),
                "Water To Dust") != 0) ++bad;
            // the "Water To Dust (," [sic])
            // garble
            if (!uad6WaterToDustNameHeaderGarbled()) ++bad;
            if (!uad6WaterToDustSchoolLost()) ++bad;
            if (!uad6WaterToDustGapItemSaysTransmute())
                ++bad;
            // the components cell prints only
            // "V," - a hole
            if (!uad6WaterToDustComponentsCellLost()) ++bad;
            if (uad6WaterToDustLevel() != 6) ++bad;
            if (uad6WaterToDustRangeInches() != 6) ++bad;
            if (uad6WaterToDustCastingTimeSegments() != 8)
                ++bad;
            if (!uad6WaterToDustSaveNoneAndSpecial()) ++bad;
            if (!uad6WaterToDustDurationPermanent()) ++bad;
            if (uad6WaterToDustAoeCubicInchesPerLevel() != 1)
                ++bad;
            if (!uad6WaterToDustStatBlockInterleaveDecoded())
                ++bad;
            if (!uad6WaterToDustLiquidToPowderyDust())
                ++bad;
            // the muddy multipliers
            if (uad6WaterToDustMuddyAreaMultiplier() != 2)
                ++bad;
            if (uad6WaterToDustWetMudAreaMultiplier() != 4)
                ++bad;
            if (!uad6WaterToDustContactFormsSiltyMud())
                ++bad;
            if (!uad6WaterToDustOnlyLiquidAtCasting()) ++bad;
            if (!uad6WaterToDustPartialWaterAffected()) ++bad;
            if (!uad6WaterToDustPotionsRenderedUseless())
                ++bad;
            // the water-native save gate
            if (!uad6WaterToDustLivingUnaffectedExceptWaterNatives())
                ++bad;
            if (!uad6WaterToDustWaterNativeSaveVsSpell())
                ++bad;
            if (!uad6WaterToDustOneCreaturePerCasting())
                ++bad;
            // the create water reverse
            if (!uad6WaterToDustReverseCreateWater()) ++bad;
            if (!uad6WaterToDustReverseAddsDustPinch()) ++bad;
            // the components
            if (uad6WaterToDustDiamondDustMinGp() != 500)
                ++bad;
            if (!uad6WaterToDustMaterialSeashell()) ++bad;
            if (!uad6WaterToDustMaterialMistletoe()) ++bad;
        }
        // U3: the R341 table seam
        {
            // The druid 6th-level table prints
            // five PHB names - neither new
            // name seam-checks there; both pin
            // from the prose.
            if (uastDruid6thCount() != 5) ++bad;
            if (strcmp(uastDruid6thName(0),
                "Cure Critical Wounds") != 0) ++bad;
            if (strcmp(uastDruid6thName(4),
                "Weather Summoning") != 0) ++bad;
        }
        printf("R354 UA druid 6th level spells pin audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R354 audit')
s = rd(RT)
assert s.count(
    'R354 UA druid 6th level spells'
    ' pin audit: bad ') == 1, 'd audit line'
assert s.count('audit: bad ') == 281, 'd census 281'
assert s.count(
    'R353 UA druid 5th level spells'
    ' pin audit: bad ') == 1, 'd r353 kept'
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
    '#include "rules/uadruidspells6.h"') == 1, 'd include'
assert len(applied) + len(already) == 4, 'd count'

# ---- the summary ----
print('R354 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R354 note: the UA new druid spells')
print('pin round, the 6th level - the two')
print('spell descriptions (liveoak with')
print('the triggered treant and the')
print('3-inch movement interleave decode,')
print('water to dust behind the name')
print('garble with the muddy multipliers')
print('and the water-native save gate);')
print('the family decodes the 7 turn as 1')
print('(water to dust prints the clean 6')
print('and 8); the R341 druid 6th table')
print('prints five PHB names - neither')
print('new name seam-checks there; the')
print('item stays open (the 7th level);')
print('the census 280 -> 281')
print('commit: R354: the UA new druid 6th')
print('level spells pin round (census 281)')

