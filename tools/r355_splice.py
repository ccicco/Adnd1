#!/usr/bin/env python3
# R355: the UA NEW DRUID SPELLS pin
# round, the 7th level (p. 45) -
# changestaff (the lost name
# header, the hit-die ladder with
# the wish-only recovery) and
# sunray (the blindness tiers and
# the undead damage split). The
# digit-garble family decodes the
# "7 round" as 1. This round also
# repairs the R354 seed merge and
# CLOSES the druid spells item.
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

# ---- (a) the seed: the R354 record
# plus the merged-line repair ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R354 landed 2026-10-11: commit',
    '  ae75dd2, census 281, the UA',
    '  new druid 6th level spells pin',
    '  round (rules/uadruidspells6.h):',
    '  liveoak (the triggered treant',
    '  with the 3-inch movement',
    '  interleave decode) and water',
    '  to dust (the name garble, the',
    '  muddy multipliers and the',
    '  water-native save gate); the',
    '  family decodes the 7 turn as',
    '  1. Lesson: the R354 splice',
    '  dropped the leading blank',
    '  entry line, merging the R352',
    '  seed tail with the R353',
    '  record on one line - this',
    '  round repairs the merge; the',
    '  entry list must open with a',
    '  blank element. GREEN on the',
    '  first run.',
])
MERGED = 'GREEN on the first run.- R353 landed'
FIXED = ('GREEN on the first run.' + NL
    + '- R353 landed')
s = rd(SD)
if MERGED in s:
    assert s.count(MERGED) == 1, 'a merge'
    s = s.replace(MERGED, FIXED)
    wr(SD, s)
    applied.append('seed: the merged line repair')
else:
    already.append('seed: the merged line repair')
s = rd(SD)
if 'R354 landed 2026-10-11' in s:
    already.append('seed: the R354 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R354 record')
s = rd(SD)
assert s.count('R354 landed 2026-10-11') == 1, 'a entry'
assert MERGED not in s, 'a no merge left'
assert s.count('R353 landed 2026-10-11') == 1, 'a r353 kept'
assert s.count('R352 landed 2026-10-11') == 1, 'a r352 kept'
assert s.count('R351 landed 2026-10-11') == 1, 'a r351 kept'
assert s.count('R350 landed 2026-10-11') == 1, 'a r350 kept'
assert s.count('R349 landed 2026-10-11') == 1, 'a r349 kept'
assert s.count('R348 landed 2026-10-11') == 1, 'a r348 kept'
assert s.count('R347 landed 2026-10-11') == 1, 'a r347 kept'
assert s.count('R343 landed 2026-10-11') == 1, 'a r343 kept'
assert s.count('## Knowledge maintenance') == 1, 'a maint'
assert len(applied) + len(already) == 2, 'a count'

# ---- (b) NEW rules/uadruidspells7.h ----
US = 'rules/uadruidspells7.h'
if os.path.exists(US) and 'R355' in rd(US):
    already.append('uadruidspells7.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uadruidspells7.h
// The UA NEW DRUID SPELLS (p. 45) pins, R355: the 7th-level
// spell descriptions - changestaff and sunray. This round
// CLOSES the druid spells item.
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
//
// JUDGMENTs (the decode method):
//   - the changestaff name header is lost - the section prints
//     only a stray "-" line where the name header belongs; the
//     name pins as Changestaff from the gap item list and the
//     prose; the school cell is lost with the header.
//   - the changestaff stat block interleaves both columns; the
//     Level cell is lost - the spell pins as 7th level from the
//     section heading; components, range, casting time,
//     duration, save and area cells pin clean.
//   - the changestaff lightning sentence interleaves: "chance
//     for any given tree," + "on the severity of" + "(" [sic]
//     + "). He" - words are lost between the fragments;
//     position-decoded as "depending on the severity of the
//     storm", with doubt pending the PDF.
//   - the changestaff hit-die garbles: "re- duces it my 1 hit
//     die" [sic] - the my decodes as by; "Justi ke powder" [sic]
//     pins verbatim, flagged pending the PDF; "itis by no means
//     a true treant" [sic] - the itis decodes as "it is".
//   - the digit-garble family (the R343 precedent): the sunray
//     duration prints "7 round" - the family decodes 1 round
//     (sunray prints a clean "Level: 7" cell and clean 3
//     segments).
//   - the item header list names only changestaff for the 7th
//     level - the section prints two spells; sunray joins the
//     pin this round.
//
// OCR holes (the item CLOSES this round; these stay pending
// the PDF): the changestaff school cell; the changestaff
// lightning-sentence lost words; the Justi ke powder garble.
// ===========================================================================

#pragma once

namespace rules {

// ---- changestaff, p. 45 ----
// The name header is lost - a stray "-" line; the name pins
// from the gap item list and the prose.
inline const char* uad7ChangestaffName()
    { return "Changestaff"; }

inline bool uad7ChangestaffNameHeaderLost()
    { return true; }

inline bool uad7ChangestaffSchoolLost()
    { return true; }

// The Level cell is lost in the stat-block interleave; the
// spell pins as 7th level from the section heading.
inline int uad7ChangestaffLevel()
    { return 7; }

inline bool uad7ChangestaffLevelCellLost()
    { return true; }

inline bool uad7ChangestaffComponentsVSM()
    { return true; }

inline bool uad7ChangestaffRangeTouch()
    { return true; }

inline int uad7ChangestaffCastingTimeSegments()
    { return 3; }

inline bool uad7ChangestaffDurationSpecial()
    { return true; }

inline bool uad7ChangestaffSaveNone()
    { return true; }

inline bool uad7ChangestaffAoeTheDruidsStaff()
    { return true; }

// The spell changes the staff from a pole of dead wood into a
// treant of largest size.
inline bool uad7ChangestaffStaffToLargestTreant()
    { return true; }

// The druid must first have located a tree struck by lightning
// within the past 24 hours.
inline int uad7ChangestaffLightningTreeHours()
    { return 24; }

// The chance prints 1%-5% for any given tree, on the severity
// of the storm (the lost words position-decoded, with doubt).
inline int uad7ChangestaffLightningChanceMinPct()
    { return 1; }

inline int uad7ChangestaffLightningChanceMaxPct()
    { return 5; }

inline bool uad7ChangestaffSeverityWordsLost()
    { return true; }

// The staff must be of ash, oak, or yew wood.
inline bool uad7ChangestaffStaffAshOakYew()
    { return true; }

// Curing by sun drying and special smoke requires 28 days;
// shaping, carving, smoothing and polishing require another 28
// days; the druid cannot engage in other activity during
// either period.
inline int uad7ChangestaffCuringDays()
    { return 28; }

inline int uad7ChangestaffShapingDays()
    { return 28; }

inline bool uad7ChangestaffNoOtherActivityDuringPrep()
    { return true; }

// The finished staff, engraved with scenes of woodland life,
// is rubbed with the juice of holly berries, and its end is
// thrust into the earth of the druid grove while the druid
// speaks with plants, calling upon the staff to assist in
// time of need.
inline bool uad7ChangestaffHollyBerryJuiceRub()
    { return true; }

inline bool uad7ChangestaffGroveEarthAndSpeakWithPlants()
    { return true; }

// The item is charged with a dweomer which lasts for many
// changes from staff to treant and back again.
inline bool uad7ChangestaffDweomerLastsManyChanges()
    { return true; }

// The staff/treant begins at 12 hit dice and 96 hit points,
// and goes to 11 and 88, 10 and 80, 9 and 72, and so on.
inline int uad7ChangestaffStartHitDice()
    { return 12; }

inline int uad7ChangestaffStartHitPoints()
    { return 96; }

// Each 8 points of damage accumulated reduces it by 1 hit die
// (the "my" garble decodes as "by").
inline int uad7ChangestaffDamagePerHitDieLost()
    { return 8; }

inline bool uad7ChangestaffMyGarbleDecoded()
    { return true; }

// As it loses hit dice it becomes smaller, losing attack
// power; brought below 7 hit dice, it crumbles to Justi ke
// powder [sic] and is lost.
inline int uad7ChangestaffCrumbleBelowHitDice()
    { return 7; }

inline bool uad7ChangestaffJustiKePowderGarbled()
    { return true; }

// The staff can never be brought upwards in hit dice or hit
// points, except by a wish, which restores it completely.
inline bool uad7ChangestaffNeverRegainedExceptWish()
    { return true; }

inline bool uad7ChangestaffWishRestoresCompletely()
    { return true; }

// The transformation: the druid plants the staff end in the
// ground and speaks a special command prayer and invocation.
inline bool uad7ChangestaffPlantsAndSpeaksInvocation()
    { return true; }

// The staff/treant defends the druid or obeys in any way, but
// is by no means a true treant and cannot converse with
// actual treants (the "itis" garble decodes as "it is").
inline bool uad7ChangestaffNotATrueTreant()
    { return true; }

inline bool uad7ChangestaffCannotConverseWithTreants()
    { return true; }

// The transformation lasts as many turns as the druid has
// levels, until commanded to return to true form, or until
// destroyed, whichever first occurs.
inline int uad7ChangestaffDurationTurnsPerLevel()
    { return 1; }

inline bool uad7ChangestaffEndsOnCommandOrDestruction()
    { return true; }

// The material: mistletoe, or leaves of ash, oak, or yew of
// the same sort as the staff.
inline bool uad7ChangestaffMaterialMistletoeOrMatchingLeaves()
    { return true; }

// ---- sunray (Evocation - Alteration), p. 45 ----
inline const char* uad7SunrayName()
    { return "Sunray (Evocation - Alteration)"; }

inline bool uad7SunrayComponentsVSM()
    { return true; }

inline int uad7SunrayLevel()
    { return 7; }

inline int uad7SunrayRangeInchesPerLevel()
    { return 1; }

// The duration prints "7 round" - the digit-garble family
// decodes 1 round.
inline int uad7SunrayDurationRounds()
    { return 1; }

inline bool uad7SunrayDurationGarbleDecoded()
    { return true; }

inline bool uad7SunrayAoeOneInchDiameterSpherePlusSpecial()
    { return true; }

inline int uad7SunrayCastingTimeSegments()
    { return 3; }

inline bool uad7SunraySaveSpecial()
    { return true; }

// The spell evokes a burning beam of light similar to actual
// sunlight in all important aspects.
inline bool uad7SunrayBeamLikeActualSunlight()
    { return true; }

// It inflicts blindness for 1-3 rounds upon all creatures
// within the area of effect unless a save versus spell is
// made.
inline int uad7SunrayBlindnessMinRounds()
    { return 1; }

inline int uad7SunrayBlindnessMaxRounds()
    { return 3; }

inline bool uad7SunraySaveNegatesBlindness()
    { return true; }

// Creatures using ultravision may be blinded for 2-8 rounds.
inline int uad7SunrayUltravisionBlindnessMinRounds()
    { return 2; }

inline int uad7SunrayUltravisionBlindnessMaxRounds()
    { return 8; }

// Those to whom sunlight is harmful or unnatural suffer
// permanent blindness unless the save is made, in which case
// the blindness lasts 2-12 rounds.
inline bool uad7SunraySunlightHarmfulPermanentUnlessSave()
    { return true; }

inline int uad7SunraySunlightHarmfulMaxRoundsOnSave()
    { return 12; }

// Those within the area of effect, and creatures within 2
// inches of its perimeter, have no infravisual capabilities
// for 2-5 rounds.
inline int uad7SunrayInfravisionLossMinRounds()
    { return 2; }

inline int uad7SunrayInfravisionLossMaxRounds()
    { return 5; }

inline int uad7SunrayInfravisionLossRadiusInches()
    { return 2; }

// Undead, including vampires, caught within the main area of
// effect must save versus spell, taking 8-48 points of damage
// or half damage if the save is made.
inline int uad7SunrayUndeadDamageDiceCount()
    { return 8; }

inline int uad7SunrayUndeadDamageDiceSides()
    { return 6; }

inline bool uad7SunrayUndeadHalfDamageOnSave()
    { return true; }

// Those within the secondary area of effect, up to 2 inches
// from the perimeter, take 3-18 points of damage or none if
// the save is made.
inline int uad7SunraySecondaryDamageDiceCount()
    { return 3; }

inline int uad7SunraySecondaryDamageDiceSides()
    { return 6; }

inline bool uad7SunraySecondaryNoDamageOnSave()
    { return true; }

// The ultraviolet light damages fungoid creatures and
// subterranean fungi as if they were undead, but no saving
// throw is possible.
inline bool uad7SunrayFungoidDamagedAsUndead()
    { return true; }

inline bool uad7SunrayFungoidNoSavePossible()
    { return true; }

// The material components are an aster seed and a piece of
// aventurine feldspar (sunstone).
inline bool uad7SunrayMaterialAsterSeed()
    { return true; }

inline bool uad7SunrayMaterialSunstoneFeldspar()
    { return true; }

}   // namespace rules"""
    clean(HDR, 78)
    wr(US, HDR + NL)
    applied.append('uadruidspells7.h: the pins')
s = rd(US)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 67, 'b inline count'
assert s.count('R355') == 1, 'b round tag'
assert s.count('uad7ChangestaffName()') == 1, 'b staff fn'
assert s.count('uad7SunrayMaterialSunstoneFeldspar()')    == 1, 'b sunray fn'
assert 'uastDruid' not in s, 'b no r341 ref'
assert 'uac5' not in s, 'b no r347 ref'
assert 'uad5' not in s, 'b no r353 ref'
assert 'uad6' not in s, 'b no r354 ref'
assert len(applied) + len(already) == 3, 'b count'

# ---- (c) the gap report: the note and
# the CLOSE (the item flips to [x]) ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'R355: the 7th level pinned' in s:
    already.append('gap report: the note and the close')
else:
    TAIL_OLD = NL.join([
        '        seam-checks there; the 7th',
        '        level stays open.',
        '- [ ] **The new magic-user spells**',
    ])
    assert s.count(TAIL_OLD) == 1, 'c tail'
    assert s.count('- [ ] **The new druid'
        ' spells**') == 1, 'c open header'
    NOTE = NL.join([
        '      - R355: the 7th level pinned',
        '        (rules/uadruidspells7.h) -',
        '        the two spell descriptions',
        '        (changestaff behind the',
        '        lost name header with the',
        '        hit-die ladder and the',
        '        wish-only recovery, sunray',
        '        with the blindness tiers',
        '        and the undead damage',
        '        split); the family decodes',
        '        the 7 round as 1; the item',
        '        header lists only',
        '        changestaff - the section',
        '        prints two spells, sunray',
        '        joins the pin; the R341',
        '        table pins stop at the',
        '        druid 6th - no 7th table',
        '        seam exists; the item',
        '        closes.',
        '      - CLOSED R355: the item',
        '        closed - all printed',
        '        levels pinned (R350-R354',
        '        plus this round).',
    ])
    clean(NOTE, 57)
    s = s.replace(TAIL_OLD, NL.join([
        '        seam-checks there; the 7th',
        '        level stays open.',
        NOTE,
        '- [ ] **The new magic-user spells**',
    ]))
    s = s.replace(
        '- [ ] **The new druid spells**',
        '- [x] **The new druid spells**')
    wr(GP, s)
    applied.append('gap report: the note and the close')
s = rd(GP)
assert s.count('R355: the 7th level pinned') == 1, 'c note'
assert s.count('CLOSED R355') == 1, 'c closed'
assert s.count('- [x] **The new druid spells**') == 1, 'c flipped'
assert s.count('- [ ] **The new druid spells**') == 0, 'c no open header left'
assert s.count('R354: the 6th level pinned') == 1, 'c r354 kept'
assert s.count('R353: the 5th level pinned') == 1, 'c r353 kept'
assert s.count('R352: the 3rd level pinned') == 1, 'c r352 kept'
assert s.count('R351: the 2nd level pinned') == 1, 'c r351 kept'
assert s.count('R350: the 1st level pinned') == 1, 'c r350 kept'
assert s.count('- [ ] **The new magic-user spells**') == 1, 'c mu stays open'
assert len(applied) + len(already) == 4, 'c count'

# ---- (d) regtest.cpp: the include, the
# audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R355 UA druid 7th level spells pin audit' in s:
    already.append('regtest.cpp: the R355 audit')
else:
    INC_ANCH = (
        '#include "rules/uadruidspells6.h"'
        '  // R354: the UA new druid 6th'
        ' level')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uadruidspells7.h"'
        '  // R355: the UA new druid 7th'
        ' level',
    ])
    AUD_ANCH = ('    // ---- R227: the wis mental'
                ' save wiring audit ----')
    AUDIT = r"""    // ---- R355: the UA new druid 7th level spells pin audit ----
    // The UA NEW DRUID SPELLS (p. 45), the
    // 7th level - changestaff (the lost
    // name header, the hit-die ladder
    // with the wish-only recovery) and
    // sunray (the blindness tiers and the
    // undead damage split). The family
    // decodes the "7 round" as 1. The
    // item CLOSES this round.
    {
        using namespace rules;
        int bad = 0;
        // U1: changestaff
        {
            if (strcmp(uad7ChangestaffName(),
                "Changestaff") != 0) ++bad;
            // the lost "-" name header
            if (!uad7ChangestaffNameHeaderLost()) ++bad;
            if (!uad7ChangestaffSchoolLost()) ++bad;
            // the lost level cell
            if (uad7ChangestaffLevel() != 7) ++bad;
            if (!uad7ChangestaffLevelCellLost()) ++bad;
            if (!uad7ChangestaffComponentsVSM()) ++bad;
            if (!uad7ChangestaffRangeTouch()) ++bad;
            if (uad7ChangestaffCastingTimeSegments() != 3)
                ++bad;
            if (!uad7ChangestaffDurationSpecial()) ++bad;
            if (!uad7ChangestaffSaveNone()) ++bad;
            if (!uad7ChangestaffAoeTheDruidsStaff()) ++bad;
            // the largest-size treant
            if (!uad7ChangestaffStaffToLargestTreant())
                ++bad;
            // the lightning-struck tree gate
            if (uad7ChangestaffLightningTreeHours() != 24)
                ++bad;
            if (uad7ChangestaffLightningChanceMinPct() != 1)
                ++bad;
            if (uad7ChangestaffLightningChanceMaxPct() != 5)
                ++bad;
            if (!uad7ChangestaffSeverityWordsLost()) ++bad;
            if (!uad7ChangestaffStaffAshOakYew()) ++bad;
            // the two 28-day periods
            if (uad7ChangestaffCuringDays() != 28) ++bad;
            if (uad7ChangestaffShapingDays() != 28) ++bad;
            if (!uad7ChangestaffNoOtherActivityDuringPrep())
                ++bad;
            // the holly berries and the grove
            if (!uad7ChangestaffHollyBerryJuiceRub()) ++bad;
            if (!uad7ChangestaffGroveEarthAndSpeakWithPlants())
                ++bad;
            if (!uad7ChangestaffDweomerLastsManyChanges())
                ++bad;
            // the hit-die ladder
            if (uad7ChangestaffStartHitDice() != 12) ++bad;
            if (uad7ChangestaffStartHitPoints() != 96) ++bad;
            if (uad7ChangestaffDamagePerHitDieLost() != 8)
                ++bad;
            if (!uad7ChangestaffMyGarbleDecoded()) ++bad;
            if (uad7ChangestaffCrumbleBelowHitDice() != 7)
                ++bad;
            if (!uad7ChangestaffJustiKePowderGarbled())
                ++bad;
            // the wish-only recovery
            if (!uad7ChangestaffNeverRegainedExceptWish())
                ++bad;
            if (!uad7ChangestaffWishRestoresCompletely())
                ++bad;
            // the transformation
            if (!uad7ChangestaffPlantsAndSpeaksInvocation())
                ++bad;
            if (!uad7ChangestaffNotATrueTreant()) ++bad;
            if (!uad7ChangestaffCannotConverseWithTreants())
                ++bad;
            if (uad7ChangestaffDurationTurnsPerLevel() != 1)
                ++bad;
            if (!uad7ChangestaffEndsOnCommandOrDestruction())
                ++bad;
            if (!uad7ChangestaffMaterialMistletoeOrMatchingLeaves())
                ++bad;
        }
        // U2: sunray
        {
            if (strcmp(uad7SunrayName(),
                "Sunray (Evocation - Alteration)")
                != 0) ++bad;
            if (!uad7SunrayComponentsVSM()) ++bad;
            if (uad7SunrayLevel() != 7) ++bad;
            if (uad7SunrayRangeInchesPerLevel() != 1) ++bad;
            // the "7 round" family decode
            if (uad7SunrayDurationRounds() != 1) ++bad;
            if (!uad7SunrayDurationGarbleDecoded()) ++bad;
            if (!uad7SunrayAoeOneInchDiameterSpherePlusSpecial())
                ++bad;
            if (uad7SunrayCastingTimeSegments() != 3) ++bad;
            if (!uad7SunraySaveSpecial()) ++bad;
            if (!uad7SunrayBeamLikeActualSunlight()) ++bad;
            // the blindness tiers
            if (uad7SunrayBlindnessMinRounds() != 1) ++bad;
            if (uad7SunrayBlindnessMaxRounds() != 3) ++bad;
            if (!uad7SunraySaveNegatesBlindness()) ++bad;
            if (uad7SunrayUltravisionBlindnessMinRounds()
                != 2) ++bad;
            if (uad7SunrayUltravisionBlindnessMaxRounds()
                != 8) ++bad;
            if (!uad7SunraySunlightHarmfulPermanentUnlessSave())
                ++bad;
            if (uad7SunraySunlightHarmfulMaxRoundsOnSave()
                != 12) ++bad;
            if (uad7SunrayInfravisionLossMinRounds() != 2)
                ++bad;
            if (uad7SunrayInfravisionLossMaxRounds() != 5)
                ++bad;
            if (uad7SunrayInfravisionLossRadiusInches() != 2)
                ++bad;
            // the undead damage split
            if (uad7SunrayUndeadDamageDiceCount() != 8) ++bad;
            if (uad7SunrayUndeadDamageDiceSides() != 6) ++bad;
            if (!uad7SunrayUndeadHalfDamageOnSave()) ++bad;
            if (uad7SunraySecondaryDamageDiceCount() != 3)
                ++bad;
            if (uad7SunraySecondaryDamageDiceSides() != 6)
                ++bad;
            if (!uad7SunraySecondaryNoDamageOnSave()) ++bad;
            // the fungoid gate
            if (!uad7SunrayFungoidDamagedAsUndead()) ++bad;
            if (!uad7SunrayFungoidNoSavePossible()) ++bad;
            // the aster seed and sunstone
            if (!uad7SunrayMaterialAsterSeed()) ++bad;
            if (!uad7SunrayMaterialSunstoneFeldspar()) ++bad;
        }
        // U3: the treant seam and the closure
        {
            // The changestaff staff/treant is
            // by no means a true treant - it
            // cannot converse with actual
            // treants; the R354 liveoak pin
            // matches the Monster Manual
            // treant specification - the two
            // treant pins differ.
            if (!uad7ChangestaffNotATrueTreant()) ++bad;
            if (!uad6LiveoakBecomesTreantMmSpec()) ++bad;
            // The R341 druid table pins stop
            // at the 6th level - no 7th
            // table seam exists; both names
            // pin from the prose.
            if (uastDruid6thCount() != 5) ++bad;
        }
        printf("R355 UA druid 7th level spells pin audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R355 audit')
s = rd(RT)
assert s.count(
    'R355 UA druid 7th level spells'
    ' pin audit: bad ') == 1, 'd audit line'
assert s.count('audit: bad ') == 282, 'd census 282'
assert s.count(
    'R354 UA druid 6th level spells'
    ' pin audit: bad ') == 1, 'd r354 kept'
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
    '#include "rules/uadruidspells7.h"') == 1, 'd include'
assert len(applied) + len(already) == 5, 'd count'

# ---- the summary ----
print('R355 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R355 note: the UA new druid spells')
print('pin round, the 7th level - the two')
print('spell descriptions (changestaff')
print('behind the lost name header with')
print('the hit-die ladder and the')
print('wish-only recovery, sunray with')
print('the blindness tiers and the')
print('undead damage split); the family')
print('decodes the 7 round as 1; the')
print('R354 seed merge repaired; the')
print('druid spells item CLOSES; the')
print('census 281 -> 282')
print('commit: R355: the UA new druid 7th')
print('level spells pin round (census 282)')

