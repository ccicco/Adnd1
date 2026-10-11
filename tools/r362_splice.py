#!/usr/bin/env python3
# R362: the UA NEW MAGIC-USER
# SPELLS pin round, the 8th and
# 9th levels (pp. 71-77) -
# binding, demand, the Otiluke
# telekinetic sphere, sink;
# crystalbrittle, succor, energy
# drain, the Mordenkainen
# disjunction. The R342 seam
# checks demand at index 0 and
# sink at index 8; only the two
# PHB 9th names print. The item
# CLOSES - all printed levels
# pinned.
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


# ---- (a) the seed: the R361 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R361 landed 2026-10-11: commit',
    '  5c52199, census 288, the UA',
    '  new magic-user 7th level spells',
    '  pin round (rules/uamuspells7.h):',
    '  the eight spell descriptions',
    '  (banishment behind the scrambled',
    '  stat head with the range',
    '  interleaved, forcecage with the',
    '  stat tail interleaved, the',
    '  Mordenkainen magnificent mansion',
    '  behind the garbled name header,',
    '  sequester behind the lost name',
    '  header, teleport without error',
    '  with the stat cells scrambled,',
    '  torment with the save ladder,',
    '  truename with the polymorph',
    '  verse ladder, volley with the',
    '  Explanation line lost, the last',
    '  two printing past the 8th-level',
    '  table page); the family decodes',
    '  the casting and duration 7s as',
    '  1; the R342 MU table seam',
    '  prints only the seven PHB',
    '  fragments, none of the new names',
    '  seam-checks; GREEN on the first',
    '  run.',
])
s = rd(SD)
if 'R361 landed 2026-10-11' in s:
    already.append('seed: the R361 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R361 record')
s = rd(SD)
assert s.count('R361 landed 2026-10-11') == 1, 'a entry'
assert s.count('R360 landed 2026-10-11') == 1, 'a r360 kept'
assert s.count('R359 landed 2026-10-11') == 1, 'a r359 kept'
assert s.count('R358 landed 2026-10-11') == 1, 'a r358 kept'
assert s.count('R357 landed 2026-10-11') == 1, 'a r357 kept'
assert s.count('R356 landed 2026-10-11') == 1, 'a r356 kept'
assert s.count('R355 landed 2026-10-11') == 1, 'a r355 kept'
assert s.count('R354 landed 2026-10-11') == 1, 'a r354 kept'
assert s.count('R353 landed 2026-10-11') == 1, 'a r353 kept'
assert s.count('R352 landed 2026-10-11') == 1, 'a r352 kept'
assert s.count('R351 landed 2026-10-11') == 1, 'a r351 kept'
assert s.count('R350 landed 2026-10-11') == 1, 'a r350 kept'
assert s.count('R349 landed 2026-10-11') == 1, 'a r349 kept'
assert s.count('R347 landed 2026-10-11') == 1, 'a r347 kept'
assert s.count('R343 landed 2026-10-11') == 1, 'a r343 kept'
assert s.count('## Knowledge maintenance') == 1, 'a maint'
assert len(applied) + len(already) == 1, 'a count'


# ---- (b) NEW rules/uamuspells8.h ----
US8 = 'rules/uamuspells8.h'
if os.path.exists(US8) and 'R362' in rd(US8):
    already.append('uamuspells8.h: the pins')
else:
    HDR8 = r"""// ===========================================================================
// Adnd1 - rules/uamuspells8.h
// The UA NEW MAGIC-USER SPELLS (pp. 71-74) pins, R362: the
// 8th-level spell descriptions - binding, demand, the
// Otiluke telekinetic sphere and sink.
//
// Pin-era pattern (R322): pinned data only - no engine site
// exists.
//
// JUDGMENTs (the decode method):
//   - no digit-garble 7s print in this level's cells; the
//     sink chant of 4 segments and casting of 8 segments
//     both pin clean from the prose ladder.
//   - the binding range and duration cells are lost (the
//     range prints a bare ge fragment, the duration cell
//     never prints) - holes pending the PDF; the casting
//     Special and the save Special pin from the stat
//     block.
//   - the demand components cell garbles (a bare sign
//     fragment) - the V, S, M pin from the prose; the
//     material list scrambles (the pair of open containers
//     and the copper wire) - flagged pending the PDF.
//   - the Otiluke telekinetic sphere name header garbles
//     - the Telekinetic word and the school tail are lost;
//     the name pins from the gap item list and the prose
//     (the same as the 4th-level Otiluke resilient
//     sphere). The range cell prints a bare hash
//     fragment - a hole pending the PDF; the weightless
//     fraction garbles (the ss fragment) and the
//     range-of-control number is lost - flagged pending
//     the PDF, not pinned as data.
//   - the sink level cell is lost (a bare 3 fragment
//     prints above the casting time) - the level pins
//     from the section heading; the duration Special
//     displaces into the stat scramble; the area unit
//     garbles (the asterisk for feet) - decoded as one
//     cubic foot per level, flagged pending the PDF.
//   - the R342 MU table seam prints 11 8th-level names -
//     demand at index 0 and sink at index 8 seam-check;
//     binding and the telekinetic sphere are absent,
//     asserted in the audit.
// ===========================================================================

namespace rules {

// ---- binding (Enchantment - Evocation) ----
inline const char* uam8BindName()
    { return "Binding (Enchantment - Evocation)"; }

inline bool uam8BindComponentsVSM()
    { return true; }

// The level cell is lost - the level pins from the
// section heading.
inline bool uam8BindLevelCellLost()
    { return true; }

inline int uam8BindLevel()
    { return 8; }

// The range cell prints a bare ge fragment - a hole
// pending the PDF.
inline bool uam8BindRangeCellLost()
    { return true; }

inline bool uam8BindCastingTimeSpecial()
    { return true; }

// The duration cell never prints - a hole pending the
// PDF; the forms below pin their own durations.
inline bool uam8BindDurationCellLost()
    { return true; }

inline bool uam8BindSaveSpecial()
    { return true; }

inline bool uam8BindAoeOneCreature()
    { return true; }

// The spell captures a creature from the lower planes
// already confined by a restraining diagram; the duration
// depends on the form, the caster level(s) and the length
// of the utterance.
inline bool uam8BindCapturesLowerPlanesCreature()
    { return true; }

inline bool uam8BindRequiresRestrainingDiagram()
    { return true; }

// The utterance: a continuous chant read from a scroll or
// book page, gestures appropriate to the form, and the
// materials.
inline bool uam8BindContinuousChantFromScroll()
    { return true; }

inline bool uam8BindGesturesMatchTheForm()
    { return true; }

// The material chains: iron for demonkind, silver for
// diabolical creatures, nickel for the minions of Hades.
inline bool uam8BindChainIronSilverNickel()
    { return true; }

// Soporific herbs of the rarest sort.
inline bool uam8BindMaterialSoporificHerbs()
    { return true; }

// A diamond or corundum gem of great size - 1,000 gp value
// per hit die of the subject.
inline int uam8BindGemGpPerHitDie()
    { return 1000; }

// A vellum depiction or carved statuette of the subject.
inline bool uam8BindMaterialVellumOrStatuette()
    { return true; }

// No save applies while the caster level(s) are at least
// twice the subject's hit dice.
inline int uam8BindNoSaveCasterLevelMultiple()
    { return 2; }

// Otherwise the subject saves versus spell, modified by
// the form and the ratio of caster level(s) to hit dice.
inline bool uam8BindSaveModifiedByFormAndRatio()
    { return true; }

// The principal caster's level is augmented by one-third
// of the level of each assistant of 9th or higher level.
inline bool uam8BindAssistantNinthPlusThird()
    { return true; }

// An additional level per assistant of 4th to 8th level.
inline bool uam8BindAssistantFourthToEighthOne()
    { return true; }

// No more than six other magic-users can assist.
inline int uam8BindAssistantMax()
    { return 6; }

// Chaining: restraints generating an antipathy affecting
// all who approach except the caster; up to one year per
// caster level; the subject stays within the diagram.
inline int uam8BindChainingYearsPerLevel()
    { return 1; }

inline bool uam8BindChainingAntipathy()
    { return true; }

inline bool uam8BindChainingStaysInDiagram()
    { return true; }

// Slumber: a comatose sleep of up to one year per caster
// level.
inline int uam8BindSlumberYearsPerLevel()
    { return 1; }

// Bound slumber: chaining plus slumber, up to one month
// per caster level.
inline int uam8BindBoundSlumberMonthsPerLevel()
    { return 1; }

// Hedged prison: the subject is confined within an area it
// may not wander from until the hedge is broken.
inline bool uam8BindHedgedPrisonUntilBroken()
    { return true; }

// Metamorphosis: a noncorporeal form save for the head or
// face; permanent until a prescribed act frees it.
inline bool uam8BindMetamorphosisNoncorporeal()
    { return true; }

inline bool uam8BindMetamorphosisUntilPrescribedAct()
    { return true; }

// Minimus containment: shrunk to one inch or less, held
// within the hedged prison of a gem or similar object.
inline int uam8BindMinimusHeightInches()
    { return 1; }

inline bool uam8BindMinimusHeldInGem()
    { return true; }

// The minimus, metamorphosis and hedged prison subjects
// radiate a very faint aura of magic.
inline bool uam8BindFormsRadiateFaintAura()
    { return true; }

// The save ladder: chaining normal, slumber +1, bound
// slumber +2, hedged prison +3, metamorphosis +4, minimus
// containment +5.
inline int uam8BindSaveAdjChaining()
    { return 0; }

inline int uam8BindSaveAdjSlumber()
    { return 1; }

inline int uam8BindSaveAdjBoundSlumber()
    { return 2; }

inline int uam8BindSaveAdjHedgedPrison()
    { return 3; }

inline int uam8BindSaveAdjMetamorphosis()
    { return 4; }

inline int uam8BindSaveAdjMinimus()
    { return 5; }

// A subject weakened by dolor or torment adjusts by -1 and
// -2 respectively, -4 for both in successive combination.
inline int uam8BindAdjDolor()
    { return -1; }

inline int uam8BindAdjTorment()
    { return -2; }

inline int uam8BindAdjBoth()
    { return -4; }

// A successful save bursts the bonds; the subject does as
// it pleases.
inline bool uam8BindSaveSuccessBurstsBonds()
    { return true; }

// The first three forms can be renewed - the subject gets
// no chance to break the bonds; after one year it gains a
// save versus spell, and a success breaks the binding.
inline bool uam8BindFirstThreeRenewable()
    { return true; }

inline int uam8BindRenewalSaveAfterYears()
    { return 1; }

// A weakened chaining or slumber (contact or magical touch
// attempts) allows a normal save on the renewal.
inline bool uam8BindWeakenedRenewalNormalSave()
    { return true; }

// ---- demand (Evocation - Enchantment/Charm) ----
inline const char* uam8DemandName()
    { return "Demand (Evocation - Enchantment/Charm)"; }

// The components cell garbles - a bare sign fragment; the
// V, S, M pin from the prose and the material list.
inline bool uam8DemandComponentsCellGarbled()
    { return true; }

inline bool uam8DemandComponentsVSM()
    { return true; }

inline int uam8DemandLevel()
    { return 8; }

inline bool uam8DemandRangeSpecial()
    { return true; }

inline int uam8DemandCastingTimeTurns()
    { return 1; }

inline bool uam8DemandDurationSpecial()
    { return true; }

inline bool uam8DemandSaveSpecial()
    { return true; }

inline bool uam8DemandAoeOneCreature()
    { return true; }

// The spell is the same as a sending spell, except the
// message may contain a suggestion; a failed save versus
// spell means the subject carries out the demand.
inline bool uam8DemandSameAsSending()
    { return true; }

inline bool uam8DemandCarriesSuggestion()
    { return true; }

inline bool uam8DemandFailedSaveCarriesOut()
    { return true; }

// An impossible or incongruous message gets no save.
inline bool uam8DemandImpossibleNoSave()
    { return true; }

// The materials: a pair of small open containers
// connected by a thin copper wire, and a small part of
// the subject - a hair, bit of nail, etc. The container
// list scrambles in the print - flagged pending the PDF.
inline bool uam8DemandMaterialCopperWire()
    { return true; }

inline bool uam8DemandMaterialSubjectPart()
    { return true; }

inline bool uam8DemandMaterialListScrambled()
    { return true; }

// ---- the Otiluke telekinetic sphere ----
// The name header garbles - the Telekinetic word and the
// school tail are lost; the name pins from the gap item
// list and the prose.
inline const char* uam8OtilukeName()
    { return "Otiluke's Telekinetic Sphere"; }

inline bool uam8OtilukeNameHeaderGarbled()
    { return true; }

inline bool uam8OtilukeSchoolLost()
    { return true; }

inline int uam8OtilukeLevel()
    { return 8; }

// The range cell prints a bare hash fragment - a hole
// pending the PDF.
inline bool uam8OtilukeRangeCellLost()
    { return true; }

inline int uam8OtilukeCastingTimeSegments()
    { return 4; }

inline bool uam8OtilukeSaveNeg()
    { return true; }

inline int uam8OtilukeDurationRoundsPerLevel()
    { return 1; }

// The area: a 1-foot diameter sphere per level of the
// caster.
inline bool uam8OtilukeAoeFeetPerLevel()
    { return true; }

// The spell is exactly the same as the 4th-level resilient
// sphere plus a virtually weightless interior - the
// weightless fraction garbles (the ss fragment), flagged
// pending the PDF.
inline bool uam8OtilukeSameAsResilientSphere()
    { return true; }

inline bool uam8OtilukeInteriorWeightless()
    { return true; }

inline bool uam8OtilukeWeightFractionGarbled()
    { return true; }

// A subject of up to 5,000 pounds can be telekinetically
// lifted in the sphere.
inline int uam8OtilukeLiftPoundsMax()
    { return 5000; }

// Even beyond 5,000 pounds englobed, the essential weight
// is a fraction of actual - the orb can be rolled without
// exceptional effort.
inline bool uam8OtilukeRolledWithoutEffort()
    { return true; }

// The range-of-control number is lost in the print - a
// hole pending the PDF, not pinned as data.
inline bool uam8OtilukeControlRangeNumberLost()
    { return true; }

inline bool uam8OtilukeControlPerLevel()
    { return true; }

// Rapid motion or falling within the field is relatively
// harmless - but the globe vanishing high above a hard
// surface is disastrous.
inline bool uam8OtilukeFallingHarmless()
    { return true; }

inline bool uam8OtilukeVanishHighDangerous()
    { return true; }

// Beyond the resilient sphere materials, the caster needs
// a pair of small bar magnets.
inline bool uam8OtilukeMaterialBarMagnets()
    { return true; }

// ---- sink (Enchantment - Alteration) ----
inline const char* uam8SinkName()
    { return "Sink (Enchantment - Alteration)"; }

// The level cell is lost - a bare 3 fragment prints above
// the casting time; the level pins from the section
// heading.
inline bool uam8SinkLevelCellLost()
    { return true; }

inline int uam8SinkLevel()
    { return 8; }

// The caster must chant the spell for 4 segments without
// interruption.
inline int uam8SinkChantSegments()
    { return 4; }

inline int uam8SinkCastingTimeSegments()
    { return 8; }

// The duration Special displaces into the stat scramble -
// pinned as printed.
inline bool uam8SinkDurationSpecial()
    { return true; }

inline bool uam8SinkSaveSpecial()
    { return true; }

// The area: one creature, or one object of 1 cubic foot
// per level - the unit garbles (the asterisk fragment),
// flagged pending the PDF.
inline bool uam8SinkAoeOneCreatureOrObject()
    { return true; }

inline int uam8SinkAoeCuFtPerLevel()
    { return 1; }

inline bool uam8SinkAoeUnitGarbled()
    { return true; }

// At the chant's juncture the subject roots to the spot
// unless it saves - versus spell for a creature, versus
// disintegration for a magical object.
inline bool uam8SinkRootsUnlessSave()
    { return true; }

inline bool uam8SinkCreatureSaveVsSpell()
    { return true; }

inline bool uam8SinkMagicObjectSaveVsDisintegration()
    { return true; }

// Magical properties: DMG magic items, enchanted or
// magical-origin items, and items with magic-type or
// similar spells upon them.
inline bool uam8SinkMagicalPropertiesDefined()
    { return true; }

// Non-magical items are not entitled to a save.
inline bool uam8SinkNonMagicNoSave()
    { return true; }

// A failed save also makes the subject the same density
// as the surface it stands on.
inline bool uam8SinkSameDensityAsSurface()
    { return true; }

// If the caster ceases, the dweomer loses power in 4
// turns and the subject returns to normal.
inline int uam8SinkCeaseTurns()
    { return 4; }

// Proceeding, the subject sinks: a quarter of its height on
// the 5th segment, another on the 6th, another on the 7th,
// totally sunken on the 8th.
inline int uam8SinkSinkingStartSegment()
    { return 5; }

inline int uam8SinkSinkingQuarterPerSegment()
    { return 1; }

inline int uam8SinkTotallySunkenSegment()
    { return 8; }

// The entombment places a living subject in stasis
// without harm; non-living subjects exist undamaged in
// the surface.
inline bool uam8SinkLivingStasisUnharmed()
    { return true; }

inline bool uam8SinkNonLivingUndamaged()
    { return true; }

// The upper extremity rests as far beneath the surface as
// the subject has height - a 6-foot subject 6 feet
// beneath, a 60-foot subject 60 feet below.
inline bool uam8SinkDepthEqualsHeight()
    { return true; }

// Removing the ground around the subject breaks the spell
// and returns it to normal - though it will not rise up.
inline bool uam8SinkGroundRemovalBreaks()
    { return true; }

// Dig, transmute rock to mud, and freedom (the reverse of
// imprisonment) do not harm the subject and help recover
// it in many cases.
inline bool uam8SinkRecoverySpellsHelpful()
    { return true; }

// A detect magic over the sunk area reveals a faint
// dweomer of undefinable nature, even beyond detection
// range; within range it notes enchantment-alteration
// magic.
inline bool uam8SinkDetectMagicFaintDweomer()
    { return true; }

inline bool uam8SinkDetectNotesEnchantAlteration()
    { return true; }

}   // namespace rules
"""
    clean(HDR8, 78)
    wr(US8, HDR8 + NL)
    applied.append('uamuspells8.h: the pins')
s = rd(US8)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 108, 'b inline count'
assert s.count('R362') == 1, 'b round tag'
assert s.count('uam8BindName()') == 1, 'b bind fn'
assert s.count(
    'uam8SinkDetectNotesEnchantAlteration()'
    ) == 1, 'b sink fn'
assert 'uam7' not in s, 'b no r361 ref'
assert 'uam6' not in s, 'b no r360 ref'
assert 'uam5' not in s, 'b no r360-5 ref'
assert 'uam4' not in s, 'b no r359 ref'
assert 'uam3' not in s, 'b no r358 ref'
assert 'uam2' not in s, 'b no r357 ref'
assert 'uam1' not in s, 'b no r356 ref'
assert 'uac1' not in s, 'b no r343 ref'
assert 'uad3' not in s, 'b no druid ref'
assert 'uas2' not in s, 'b no r342 ref'
assert len(applied) + len(already) == 2, 'b count'


# ---- (b2) NEW rules/uamuspells9.h ----
US9 = 'rules/uamuspells9.h'
if os.path.exists(US9) and 'R362' in rd(US9):
    already.append('uamuspells9.h: the pins')
else:
    HDR9 = r"""// ===========================================================================
// Adnd1 - rules/uamuspells9.h
// The UA NEW MAGIC-USER SPELLS (pp. 74-77) pins, R362: the
// 9th-level spell descriptions - crystalbrittle, succor,
// energy drain and the Mordenkainen disjunction.
//
// Pin-era pattern (R322): pinned data only - no engine site
// exists.
//
// JUDGMENTs (the decode method):
//   - the crystalbrittle casting head loses the Casting
//     word (a bare Time: 9 segments) - pinned as printed;
//     the components cell garbles the sign (V, S) - the
//     M pins from the stat pattern, flagged pending the
//     PDF.
//   - the succor stat head prints only the Duration and
//     Area cells; the Components, Casting Time and
//     Saving Throw cells print in an interleaved tail
//     after the prose - the casting garbles (a 17-to-4
//     print; the leading fragment reads as 1, flagged
//     pending the PDF). The level cell is lost - the
//     level pins from the section heading. The spell is
//     reversible.
//   - the energy drain stat block scrambles - the 3
//     segments displace above the Casting Time line, and
//     the duration and save cells never print - holes
//     pending the PDF; the material sentence scrambles
//     the spectre word (an essence-of fragment) and the
//     three-segments phrase - flagged pending the PDF.
//   - the Mordenkainen disjunction name header garbles
//     to a bare possessive-fragment; the name pins from
//     the gap item list and the prose. The school is
//     lost pending the PDF; the components cell prints
//     bare - a hole pending the PDF.
//   - the R342 MU table seam prints only two 9th-level
//     names (Prismatic Sphere, Shape Change) - none of
//     the new names seam-checks, asserted in the audit.
// ===========================================================================

namespace rules {

// ---- crystalbrittle (Alteration) ----
inline const char* uam9CrystalName()
    { return "Crystalbrittle (Alteration)"; }

// The components cell garbles the sign for the M - pinned
// as V, S, M, flagged pending the PDF.
inline bool uam9CrystalComponentsVSM()
    { return true; }

inline bool uam9CrystalComponentsCellGarbled()
    { return true; }

inline int uam9CrystalLevel()
    { return 9; }

// The casting head loses the Casting word - a bare Time:
// 9 segments; pinned as printed.
inline int uam9CrystalCastingTimeSegments()
    { return 9; }

inline bool uam9CrystalCastingHeadLost()
    { return true; }

inline bool uam9CrystalRangeTouch()
    { return true; }

inline bool uam9CrystalDurationPermanent()
    { return true; }

inline bool uam9CrystalSaveSpecial()
    { return true; }

inline int uam9CrystalAoeCuFtPerLevel()
    { return 2; }

// The dweomer turns metal - as soft as gold or as hard as
// adamantite - into a crystalline substance as brittle and
// fragile as crystal.
inline bool uam9CrystalTurnsMetalToCrystal()
    { return true; }

// A sword, metal shield, metal armor, or even an iron
// golem becomes delicate, glass-like material easily
// shattered by any forceful blow.
inline bool uam9CrystalShattersByBlow()
    { return true; }

// The change is unalterable short of a wish - dispel
// magic will not reverse it.
inline bool uam9CrystalReversibleOnlyByWish()
    { return true; }

// The caster must physically touch the target - equal to
// a hit in combat if worn, wielded, or a monster.
inline bool uam9CrystalTouchRequiresHit()
    { return true; }

// A single metal item is affected per casting - a worn
// suit of armor changes but the shield does not, or vice
// versa.
inline bool uam9CrystalSingleItemPerCasting()
    { return true; }

// Items save by their magical bonus value or protection:
// a +1/+3 sword gets a 10% chance (the average of the two
// plusses).
inline int uam9CrystalSwordSavePct()
    { return 10; }

// +5 magic armor gets a 25% chance to be unaffected.
inline int uam9CrystalArmorSavePct()
    { return 25; }

// An iron golem gets a 15% chance (hit only by +3 or
// better weapons).
inline int uam9CrystalGolemSavePct()
    { return 15; }

// Artifacts and relics of metal have a 95% chance to be
// unaffected.
inline int uam9CrystalArtifactSavePct()
    { return 95; }

// Unprotected items are shattered and permanently
// destroyed if struck by a normal blow from a metal tool
// or any weighty weapon, including a staff.
inline bool uam9CrystalDestroyedByWeightyBlow()
    { return true; }

// ---- succor (Alteration - Enchantment), reversible ----
inline const char* uam9SuccorName()
    { return "Succor (Alteration - Enchantment)"; }

inline bool uam9SuccorReversible()
    { return true; }

// The level cell is lost - the level pins from the
// section heading.
inline bool uam9SuccorLevelCellLost()
    { return true; }

inline int uam9SuccorLevel()
    { return 9; }

// The stat head prints only the Duration and Area cells;
// the Components, Casting Time and Save print in an
// interleaved tail after the prose.
inline bool uam9SuccorStatTailInterleaved()
    { return true; }

inline bool uam9SuccorComponentsVSM()
    { return true; }

// The casting garbles - a 17-to-4 days print; the leading
// fragment reads as 1, flagged pending the PDF.
inline int uam9SuccorCastingTimeDaysMin()
    { return 1; }

inline int uam9SuccorCastingTimeDaysMax()
    { return 4; }

inline bool uam9SuccorCastingPrintGarbled()
    { return true; }

inline bool uam9SuccorDurationSpecial()
    { return true; }

inline bool uam9SuccorSaveNone()
    { return true; }

inline bool uam9SuccorAoeOneIndividual()
    { return true; }

// The spell is the same as the 7th-level cleric spell of
// the same name.
inline bool uam9SuccorSameAsClericSeventh()
    { return true; }

// The magic-user version teleports without error the
// individual who breaks the object and speaks the command
// word - the R361 teleport exception.
inline bool uam9SuccorTeleportsWithoutError()
    { return true; }

// The reverse likewise brings the archmage to the presence
// of the individual.
inline bool uam9SuccorReverseBringsArchmage()
    { return true; }

// Unlike the cleric spell, the summoned archmage has no
// choice but to answer - making this version rare indeed.
inline bool uam9SuccorArchmageHasNoChoice()
    { return true; }

// Interference causes irrevocable loss of the individual
// or spell caster involved in the succor - the sentence
// scrambles, flagged pending the PDF.
inline bool uam9SuccorInterferenceIrrevocableLoss()
    { return true; }

inline bool uam9SuccorInterferenceSentenceScrambled()
    { return true; }

// The material component is gem material of not less than
// 5,000 gp value; faceted or not is immaterial.
inline int uam9SuccorGemGpMin()
    { return 5000; }

// The components can only be enchanted once per month -
// usually on the night of a clear, full moon - set then
// for the type of succor and its final destination.
inline bool uam9SuccorEnchantedOncePerMonth()
    { return true; }

inline bool uam9SuccorSetOnFullMoonNight()
    { return true; }

inline bool uam9SuccorSetForTypeAndDestination()
    { return true; }

// ---- energy drain (Evocation) ----
inline const char* uam9EnergyName()
    { return "Energy Drain (Evocation)"; }

inline bool uam9EnergyComponentsVSM()
    { return true; }

inline int uam9EnergyLevel()
    { return 9; }

// The stat block scrambles - the 3 segments displace above
// the Casting Time line; pinned as printed.
inline int uam9EnergyCastingTimeSegments()
    { return 3; }

inline bool uam9EnergyCastingCellDisplaced()
    { return true; }

inline bool uam9EnergyRangeTouch()
    { return true; }

// The duration and save cells never print - holes pending
// the PDF, not pinned as data.
inline bool uam9EnergyDurationCellLost()
    { return true; }

inline bool uam9EnergySaveCellLost()
    { return true; }

inline bool uam9EnergyAoeOneCreature()
    { return true; }

// The spell opens a channel between the caster's plane and
// the Negative Material Plane, the caster becoming the
// conductor between the two.
inline bool uam9EnergyNegativePlaneChannel()
    { return true; }

inline bool uam9EnergyCasterIsConductor()
    { return true; }

// A touch (equal to a hit in melee) drains two energy
// levels from any living creature, as if struck by a
// spectre.
inline int uam9EnergyLevelsDrained()
    { return 2; }

inline bool uam9EnergyAsSpectre()
    { return true; }

// A monster loses two hit dice permanently - hit points
// and attack ability both.
inline int uam9EnergyHitDiceDrained()
    { return 2; }

// A character loses levels, hit dice, hit points and
// abilities permanently - until regained through
// adventuring, if applicable.
inline bool uam9EnergyCharacterLossPermanent()
    { return true; }

// The material: essence of spectre or vampire dust - the
// print loses the spectre word, flagged pending the PDF.
inline bool uam9EnergyMaterialSpectreOrVampireDust()
    { return true; }

inline bool uam9EnergyMaterialWordLost()
    { return true; }

// The three-segments phrase scrambles into the material
// sentence - flagged pending the PDF.
inline bool uam9EnergyMaterialSentenceScrambled()
    { return true; }

// The component is cast forth; upon touching the victim
// the caster speaks the triggering word, and the dweomer
// takes effect instantly.
inline bool uam9EnergyTriggeringWord()
    { return true; }

// A 5% chance (1 in 20) that the caster is also drained of
// one energy level as the victim loses two.
inline int uam9EnergyCasterRiskPct()
    { return 5; }

inline int uam9EnergyCasterRiskLevels()
    { return 1; }

// Humans or humanoids brought to zero energy level become
// juju zombies.
inline bool uam9EnergyZeroLevelJujuZombies()
    { return true; }

// ---- the Mordenkainen disjunction ----
// The name header garbles to a bare possessive fragment;
// the name pins from the gap item list and the prose. The
// school is lost pending the PDF.
inline const char* uam9DisjunctionName()
    { return "Mordenkainen's Disjunction"; }

inline bool uam9DisjunctionNameHeaderGarbled()
    { return true; }

inline bool uam9DisjunctionSchoolLost()
    { return true; }

// The components cell prints bare - a hole pending the
// PDF, not pinned as data.
inline bool uam9DisjunctionComponentsCellLost()
    { return true; }

inline int uam9DisjunctionLevel()
    { return 9; }

inline int uam9DisjunctionRangeZero()
    { return 0; }

inline int uam9DisjunctionCastingTimeSegments()
    { return 9; }

inline bool uam9DisjunctionDurationPermanent()
    { return true; }

inline bool uam9DisjunctionSaveSpecial()
    { return true; }

inline int uam9DisjunctionAoeRadiusInches()
    { return 3; }

// All magic and magic items within the radius are
// disjoined, except those on the person of or being
// touched by the spell caster.
inline bool uam9DisjunctionDisjoinsAllMagic()
    { return true; }

inline bool uam9DisjunctionCasterPersonExempt()
    { return true; }

// Spells being cast are separated into their individual
// components and the effect spoiled, as does a dispel
// magic.
inline bool uam9DisjunctionSpoilsSpellsBeingCast()
    { return true; }

// Items must save - versus spell if actually cast upon a
// creature, versus dispel magic otherwise - or be turned
// into normal items.
inline bool uam9DisjunctionItemsSaveOrBecomeNormal()
    { return true; }

inline bool uam9DisjunctionItemSaveVsSpellIfCreature()
    { return true; }

// Even artifacts and relics are subject to the disjunction
// - a 1% chance per caster level of actually affecting
// such powerful items.
inline int uam9DisjunctionArtifactPctPerLevel()
    { return 1; }

// Thus all potions, scrolls, rings, rods et al,
// miscellaneous magic items, artifacts and relics, arms
// and armor, swords and miscellaneous weapons within 3
// inches of the caster can possibly lose all their
// magical properties.
inline bool uam9DisjunctionAffectsAllItemClasses()
    { return true; }

// Destroying artifacts is dangerous business - 95% likely
// to attract the attention of some powerful being with an
// interest or connection with the device.
inline int uam9DisjunctionArtifactAttentionPct()
    { return 95; }

// If an artifact is destroyed, the casting magic-user must
// save versus spell at -4 or permanently lose all spell
// casting abilities.
inline int uam9DisjunctionArtifactDestroySaveAdj()
    { return -4; }

inline bool uam9DisjunctionCasterMayLoseCasting()
    { return true; }

}   // namespace rules
"""
    clean(HDR9, 78)
    wr(US9, HDR9 + NL)
    applied.append('uamuspells9.h: the pins')
s = rd(US9)
assert s.count('namespace rules {') == 1, 'b2 ns'
assert s.count('inline') == 84, 'b2 inline count'
assert s.count('R362') == 1, 'b2 round tag'
assert s.count('uam9CrystalName()') == 1, 'b2 crystal fn'
assert s.count(
    'uam9DisjunctionCasterMayLoseCasting()'
    ) == 1, 'b2 disjunction fn'
assert 'uam8' not in s, 'b2 no r362-8 ref'
assert 'uam7' not in s, 'b2 no r361 ref'
assert 'uam6' not in s, 'b2 no r360 ref'
assert 'uam5' not in s, 'b2 no r360-5 ref'
assert 'uam4' not in s, 'b2 no r359 ref'
assert 'uam3' not in s, 'b2 no r358 ref'
assert 'uam2' not in s, 'b2 no r357 ref'
assert 'uam1' not in s, 'b2 no r356 ref'
assert 'uac1' not in s, 'b2 no r343 ref'
assert 'uad3' not in s, 'b2 no druid ref'
assert 'uas2' not in s, 'b2 no r342 ref'
assert len(applied) + len(already) == 3, 'b2 count'


# ---- (c) the gap report: the note and
# the CLOSE (the item flips to [x]) ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'R362: the 8th and 9th levels' in s:
    already.append('gap report: the note and the close')
else:
    TAIL_OLD = NL.join([
        '        names seam-checks; the 8th',
        '        and 9th levels stay open.',
        '- [ ] **The new illusionist spells**',
    ])
    assert s.count(TAIL_OLD) == 1, 'c tail'
    assert s.count('- [ ] **The new'
        ' magic-user spells**') == 1, 'c open header'
    NOTE = NL.join([
    '      - R362: the 8th and 9th levels',
    '        pinned (rules/uamuspells8.h',
    '        and rules/uamuspells9.h) - the',
    '        four 8th-level descriptions',
    '        (binding with the lost range',
    '        and duration cells and the six',
    '        forms with the save ladder,',
    '        demand behind the garbled',
    '        components cell, the Otiluke',
    '        telekinetic sphere behind the',
    '        garbled name header with the',
    '        lost range cell, sink with the',
    '        lost level cell and the',
    '        sinking ladder) and the four',
    '        9th-level descriptions',
    '        (crystalbrittle with the item',
    '        save ladder, succor with the',
    '        interleaved stat tail, energy',
    '        drain with the displaced casting',
    '        cell, the Mordenkainen',
    '        disjunction behind the garbled',
    '        name header with the artifact',
    '        chances); the R342 MU table',
    '        seam checks demand at index 0',
    '        and sink at index 8 with',
    '        binding and the sphere absent,',
    '        and only the two PHB 9th names',
    '        print; the item closes.',
    '      - CLOSED R362: the item closed',
    '        - all printed levels pinned',
    '        (R356-R361 plus this round).',
    ])
    clean(NOTE, 57)
    s = s.replace(TAIL_OLD, NL.join([
        '        names seam-checks; the 8th',
        '        and 9th levels stay open.',
        NOTE,
        '- [ ] **The new illusionist spells**',
    ]))
    s = s.replace(
        '- [ ] **The new magic-user spells**',
        '- [x] **The new magic-user spells**')
    wr(GP, s)
    applied.append('gap report: the note and the close')
s = rd(GP)
assert s.count('R362: the 8th and 9th levels') == 1, 'c note'
assert s.count('CLOSED R362') == 1, 'c closed'
assert s.count(
    '- [x] **The new magic-user spells**'
    ) == 1, 'c flipped'
assert s.count(
    '- [ ] **The new magic-user spells**'
    ) == 0, 'c no open header left'
assert s.count(
    'R361: the 7th level pinned'
    ) == 1, 'c r361 kept'
assert s.count(
    'R360: the 5th and 6th levels'
    ) == 1, 'c r360 kept'
assert s.count(
    '- [x] **The new druid spells**'
    ) == 1, 'c druid closed kept'
assert s.count(
    '- [ ] **The new illusionist spells**'
    ) == 1, 'c illusionist kept'
assert len(applied) + len(already) == 4, 'c count'


# ---- (d) regtest.cpp: the includes, the
# audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R362 UA MU 8th/9th level spells pin audit' in s:
    already.append('regtest.cpp: the R362 audit')
else:
    INC_ANCH = (
        '#include "rules/uamuspells7.h"'
        '  // R361: the UA new magic-user'
        ' 7th level')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uamuspells8.h"'
        '  // R362: the UA new magic-user'
        ' 8th level',
        '#include "rules/uamuspells9.h"'
        '  // R362: the UA new magic-user'
        ' 9th level',
    ])
    AUD_ANCH = (
        '    // ---- R227: the wis mental save'
        ' wiring audit ----')
    AUDIT = r"""    // ---- R362: the UA new magic-user 8th and 9th
    // level spells pin audit ----
    // The UA NEW MAGIC-USER SPELLS (pp.
    // 71-77), the 8th and 9th levels -
    // binding behind the lost range and
    // duration cells, demand behind the
    // garbled components cell, the
    // Otiluke telekinetic sphere behind
    // the garbled name header, sink
    // behind the lost level cell;
    // crystalbrittle with the item save
    // ladder, succor with the
    // interleaved stat tail, energy
    // drain with the displaced casting
    // cell, the Mordenkainen
    // disjunction behind the garbled
    // name header. The R342 seam
    // checks demand at index 0 and
    // sink at index 8; only the two
    // PHB 9th names print. The item
    // CLOSES with this round.
    {
        using namespace rules;
        int bad = 0;
        // U1: binding
            if (strcmp(uam8BindName(),
                "Binding (Enchantment - Evocation)") != 0) ++bad;
            if (!uam8BindComponentsVSM()) ++bad;
            if (!uam8BindLevelCellLost()) ++bad;
            if (uam8BindLevel() != 8) ++bad;
            if (!uam8BindRangeCellLost()) ++bad;
            if (!uam8BindCastingTimeSpecial()) ++bad;
            if (!uam8BindDurationCellLost()) ++bad;
            if (!uam8BindSaveSpecial()) ++bad;
            if (!uam8BindAoeOneCreature()) ++bad;
            if (!uam8BindCapturesLowerPlanesCreature()) ++bad;
            if (!uam8BindRequiresRestrainingDiagram()) ++bad;
            if (!uam8BindContinuousChantFromScroll()) ++bad;
            if (!uam8BindGesturesMatchTheForm()) ++bad;
            if (!uam8BindChainIronSilverNickel()) ++bad;
            if (!uam8BindMaterialSoporificHerbs()) ++bad;
            if (uam8BindGemGpPerHitDie() != 1000) ++bad;
            if (!uam8BindMaterialVellumOrStatuette()) ++bad;
            if (uam8BindNoSaveCasterLevelMultiple() != 2) ++bad;
            if (!uam8BindSaveModifiedByFormAndRatio()) ++bad;
            if (!uam8BindAssistantNinthPlusThird()) ++bad;
            if (!uam8BindAssistantFourthToEighthOne()) ++bad;
            if (uam8BindAssistantMax() != 6) ++bad;
            if (uam8BindChainingYearsPerLevel() != 1) ++bad;
            if (!uam8BindChainingAntipathy()) ++bad;
            if (!uam8BindChainingStaysInDiagram()) ++bad;
            if (uam8BindSlumberYearsPerLevel() != 1) ++bad;
            if (uam8BindBoundSlumberMonthsPerLevel() != 1) ++bad;
            if (!uam8BindHedgedPrisonUntilBroken()) ++bad;
            if (!uam8BindMetamorphosisNoncorporeal()) ++bad;
            if (!uam8BindMetamorphosisUntilPrescribedAct()) ++bad;
            if (uam8BindMinimusHeightInches() != 1) ++bad;
            if (!uam8BindMinimusHeldInGem()) ++bad;
            if (!uam8BindFormsRadiateFaintAura()) ++bad;
            if (uam8BindSaveAdjChaining() != 0) ++bad;
            if (uam8BindSaveAdjSlumber() != 1) ++bad;
            if (uam8BindSaveAdjBoundSlumber() != 2) ++bad;
            if (uam8BindSaveAdjHedgedPrison() != 3) ++bad;
            if (uam8BindSaveAdjMetamorphosis() != 4) ++bad;
            if (uam8BindSaveAdjMinimus() != 5) ++bad;
            if (uam8BindAdjDolor() != -1) ++bad;
            if (uam8BindAdjTorment() != -2) ++bad;
            if (uam8BindAdjBoth() != -4) ++bad;
            if (!uam8BindSaveSuccessBurstsBonds()) ++bad;
            if (!uam8BindFirstThreeRenewable()) ++bad;
            if (uam8BindRenewalSaveAfterYears() != 1) ++bad;
            if (!uam8BindWeakenedRenewalNormalSave()) ++bad;

        // U2: demand
            if (strcmp(uam8DemandName(),
                "Demand (Evocation - Enchantment/Charm)") != 0) ++bad;
            if (!uam8DemandComponentsCellGarbled()) ++bad;
            if (!uam8DemandComponentsVSM()) ++bad;
            if (uam8DemandLevel() != 8) ++bad;
            if (!uam8DemandRangeSpecial()) ++bad;
            if (uam8DemandCastingTimeTurns() != 1) ++bad;
            if (!uam8DemandDurationSpecial()) ++bad;
            if (!uam8DemandSaveSpecial()) ++bad;
            if (!uam8DemandAoeOneCreature()) ++bad;
            if (!uam8DemandSameAsSending()) ++bad;
            if (!uam8DemandCarriesSuggestion()) ++bad;
            if (!uam8DemandFailedSaveCarriesOut()) ++bad;
            if (!uam8DemandImpossibleNoSave()) ++bad;
            if (!uam8DemandMaterialCopperWire()) ++bad;
            if (!uam8DemandMaterialSubjectPart()) ++bad;
            if (!uam8DemandMaterialListScrambled()) ++bad;

        // U3: the Otiluke telekinetic sphere
            if (strcmp(uam8OtilukeName(),
                "Otiluke's Telekinetic Sphere") != 0) ++bad;
            if (!uam8OtilukeNameHeaderGarbled()) ++bad;
            if (!uam8OtilukeSchoolLost()) ++bad;
            if (uam8OtilukeLevel() != 8) ++bad;
            if (!uam8OtilukeRangeCellLost()) ++bad;
            if (uam8OtilukeCastingTimeSegments() != 4) ++bad;
            if (!uam8OtilukeSaveNeg()) ++bad;
            if (uam8OtilukeDurationRoundsPerLevel() != 1) ++bad;
            if (!uam8OtilukeAoeFeetPerLevel()) ++bad;
            if (!uam8OtilukeSameAsResilientSphere()) ++bad;
            if (!uam8OtilukeInteriorWeightless()) ++bad;
            if (!uam8OtilukeWeightFractionGarbled()) ++bad;
            if (uam8OtilukeLiftPoundsMax() != 5000) ++bad;
            if (!uam8OtilukeRolledWithoutEffort()) ++bad;
            if (!uam8OtilukeControlRangeNumberLost()) ++bad;
            if (!uam8OtilukeControlPerLevel()) ++bad;
            if (!uam8OtilukeFallingHarmless()) ++bad;
            if (!uam8OtilukeVanishHighDangerous()) ++bad;
            if (!uam8OtilukeMaterialBarMagnets()) ++bad;

        // U4: sink
            if (strcmp(uam8SinkName(),
                "Sink (Enchantment - Alteration)") != 0) ++bad;
            if (!uam8SinkLevelCellLost()) ++bad;
            if (uam8SinkLevel() != 8) ++bad;
            if (uam8SinkChantSegments() != 4) ++bad;
            if (uam8SinkCastingTimeSegments() != 8) ++bad;
            if (!uam8SinkDurationSpecial()) ++bad;
            if (!uam8SinkSaveSpecial()) ++bad;
            if (!uam8SinkAoeOneCreatureOrObject()) ++bad;
            if (uam8SinkAoeCuFtPerLevel() != 1) ++bad;
            if (!uam8SinkAoeUnitGarbled()) ++bad;
            if (!uam8SinkRootsUnlessSave()) ++bad;
            if (!uam8SinkCreatureSaveVsSpell()) ++bad;
            if (!uam8SinkMagicObjectSaveVsDisintegration()) ++bad;
            if (!uam8SinkMagicalPropertiesDefined()) ++bad;
            if (!uam8SinkNonMagicNoSave()) ++bad;
            if (!uam8SinkSameDensityAsSurface()) ++bad;
            if (uam8SinkCeaseTurns() != 4) ++bad;
            if (uam8SinkSinkingStartSegment() != 5) ++bad;
            if (uam8SinkSinkingQuarterPerSegment() != 1) ++bad;
            if (uam8SinkTotallySunkenSegment() != 8) ++bad;
            if (!uam8SinkLivingStasisUnharmed()) ++bad;
            if (!uam8SinkNonLivingUndamaged()) ++bad;
            if (!uam8SinkDepthEqualsHeight()) ++bad;
            if (!uam8SinkGroundRemovalBreaks()) ++bad;
            if (!uam8SinkRecoverySpellsHelpful()) ++bad;
            if (!uam8SinkDetectMagicFaintDweomer()) ++bad;
            if (!uam8SinkDetectNotesEnchantAlteration()) ++bad;

        // U5: crystalbrittle
            if (strcmp(uam9CrystalName(),
                "Crystalbrittle (Alteration)") != 0) ++bad;
            if (!uam9CrystalComponentsVSM()) ++bad;
            if (!uam9CrystalComponentsCellGarbled()) ++bad;
            if (uam9CrystalLevel() != 9) ++bad;
            if (uam9CrystalCastingTimeSegments() != 9) ++bad;
            if (!uam9CrystalCastingHeadLost()) ++bad;
            if (!uam9CrystalRangeTouch()) ++bad;
            if (!uam9CrystalDurationPermanent()) ++bad;
            if (!uam9CrystalSaveSpecial()) ++bad;
            if (uam9CrystalAoeCuFtPerLevel() != 2) ++bad;
            if (!uam9CrystalTurnsMetalToCrystal()) ++bad;
            if (!uam9CrystalShattersByBlow()) ++bad;
            if (!uam9CrystalReversibleOnlyByWish()) ++bad;
            if (!uam9CrystalTouchRequiresHit()) ++bad;
            if (!uam9CrystalSingleItemPerCasting()) ++bad;
            if (uam9CrystalSwordSavePct() != 10) ++bad;
            if (uam9CrystalArmorSavePct() != 25) ++bad;
            if (uam9CrystalGolemSavePct() != 15) ++bad;
            if (uam9CrystalArtifactSavePct() != 95) ++bad;
            if (!uam9CrystalDestroyedByWeightyBlow()) ++bad;

        // U6: succor
            if (strcmp(uam9SuccorName(),
                "Succor (Alteration - Enchantment)") != 0) ++bad;
            if (!uam9SuccorReversible()) ++bad;
            if (!uam9SuccorLevelCellLost()) ++bad;
            if (uam9SuccorLevel() != 9) ++bad;
            if (!uam9SuccorStatTailInterleaved()) ++bad;
            if (!uam9SuccorComponentsVSM()) ++bad;
            if (uam9SuccorCastingTimeDaysMin() != 1) ++bad;
            if (uam9SuccorCastingTimeDaysMax() != 4) ++bad;
            if (!uam9SuccorCastingPrintGarbled()) ++bad;
            if (!uam9SuccorDurationSpecial()) ++bad;
            if (!uam9SuccorSaveNone()) ++bad;
            if (!uam9SuccorAoeOneIndividual()) ++bad;
            if (!uam9SuccorSameAsClericSeventh()) ++bad;
            if (!uam9SuccorTeleportsWithoutError()) ++bad;
            if (!uam9SuccorReverseBringsArchmage()) ++bad;
            if (!uam9SuccorArchmageHasNoChoice()) ++bad;
            if (!uam9SuccorInterferenceIrrevocableLoss()) ++bad;
            if (!uam9SuccorInterferenceSentenceScrambled()) ++bad;
            if (uam9SuccorGemGpMin() != 5000) ++bad;
            if (!uam9SuccorEnchantedOncePerMonth()) ++bad;
            if (!uam9SuccorSetOnFullMoonNight()) ++bad;
            if (!uam9SuccorSetForTypeAndDestination()) ++bad;

        // U7: energy drain
            if (strcmp(uam9EnergyName(),
                "Energy Drain (Evocation)") != 0) ++bad;
            if (!uam9EnergyComponentsVSM()) ++bad;
            if (uam9EnergyLevel() != 9) ++bad;
            if (uam9EnergyCastingTimeSegments() != 3) ++bad;
            if (!uam9EnergyCastingCellDisplaced()) ++bad;
            if (!uam9EnergyRangeTouch()) ++bad;
            if (!uam9EnergyDurationCellLost()) ++bad;
            if (!uam9EnergySaveCellLost()) ++bad;
            if (!uam9EnergyAoeOneCreature()) ++bad;
            if (!uam9EnergyNegativePlaneChannel()) ++bad;
            if (!uam9EnergyCasterIsConductor()) ++bad;
            if (uam9EnergyLevelsDrained() != 2) ++bad;
            if (!uam9EnergyAsSpectre()) ++bad;
            if (uam9EnergyHitDiceDrained() != 2) ++bad;
            if (!uam9EnergyCharacterLossPermanent()) ++bad;
            if (!uam9EnergyMaterialSpectreOrVampireDust()) ++bad;
            if (!uam9EnergyMaterialWordLost()) ++bad;
            if (!uam9EnergyMaterialSentenceScrambled()) ++bad;
            if (!uam9EnergyTriggeringWord()) ++bad;
            if (uam9EnergyCasterRiskPct() != 5) ++bad;
            if (uam9EnergyCasterRiskLevels() != 1) ++bad;
            if (!uam9EnergyZeroLevelJujuZombies()) ++bad;

        // U8: the Mordenkainen disjunction
            if (strcmp(uam9DisjunctionName(),
                "Mordenkainen's Disjunction") != 0) ++bad;
            if (!uam9DisjunctionNameHeaderGarbled()) ++bad;
            if (!uam9DisjunctionSchoolLost()) ++bad;
            if (!uam9DisjunctionComponentsCellLost()) ++bad;
            if (uam9DisjunctionLevel() != 9) ++bad;
            if (uam9DisjunctionRangeZero() != 0) ++bad;
            if (uam9DisjunctionCastingTimeSegments() != 9) ++bad;
            if (!uam9DisjunctionDurationPermanent()) ++bad;
            if (!uam9DisjunctionSaveSpecial()) ++bad;
            if (uam9DisjunctionAoeRadiusInches() != 3) ++bad;
            if (!uam9DisjunctionDisjoinsAllMagic()) ++bad;
            if (!uam9DisjunctionCasterPersonExempt()) ++bad;
            if (!uam9DisjunctionSpoilsSpellsBeingCast()) ++bad;
            if (!uam9DisjunctionItemsSaveOrBecomeNormal()) ++bad;
            if (!uam9DisjunctionItemSaveVsSpellIfCreature()) ++bad;
            if (uam9DisjunctionArtifactPctPerLevel() != 1) ++bad;
            if (!uam9DisjunctionAffectsAllItemClasses()) ++bad;
            if (uam9DisjunctionArtifactAttentionPct() != 95) ++bad;
            if (uam9DisjunctionArtifactDestroySaveAdj() != -4) ++bad;
            if (!uam9DisjunctionCasterMayLoseCasting()) ++bad;

        // the R342 table seam (demand at
        // index 0 and sink at index 8;
        // binding and the sphere absent;
        // only the two PHB 9th names print)
        if (uas2Mu8thCount() != 11) ++bad;
        if (strcmp(uas2Mu8thName(0),
                "Demand") != 0) ++bad;
        if (strcmp(uas2Mu8thName(8),
                "Sink") != 0) ++bad;
        // the absent 8th-level names
        for (int i = 0; i < 11; ++i) {
            const char* n = uas2Mu8thName(i);
            if (strcmp(n, "Binding") == 0)
                ++bad;
            if (strcmp(n, "Otiluke's Telekinetic")
                == 0)
                ++bad;
        }
        if (uas2Mu9thCount() != 2) ++bad;
        if (strcmp(uas2Mu9thName(0),
                "Prismatic Sphere") != 0)
            ++bad;
        if (strcmp(uas2Mu9thName(1),
                "Shape Change") != 0) ++bad;
        // the absent 9th-level names
        for (int i = 0; i < 2; ++i) {
            const char* n = uas2Mu9thName(i);
            if (strcmp(n, "Crystalbrittle") == 0)
                ++bad;
            if (strcmp(n, "Succor") == 0) ++bad;
            if (strcmp(n, "Energy Drain") == 0)
                ++bad;
            if (strcmp(n, "Mordenkainen's")
                == 0)
                ++bad;
        }
        // the R361 teleport exception names
        // this succor - the cross-level link
        if (!uam7TeleportSuccorException() ||
            strcmp(uam9SuccorName(),
                "Succor (Alteration - Enchantment)")
                != 0) ++bad;
        printf("R362 UA MU 8th/9th level spells pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
"""
    assert s.count(INC_ANCH) == 1, 'd inc anchor'
    assert s.count(AUD_ANCH) == 1, 'd aud anchor'
    clean(INC_NEW, 78)
    clean(AUDIT, 76)
    s = s.replace(INC_ANCH, INC_NEW)
    s = s.replace(AUD_ANCH,
        AUDIT + NL + NL + AUD_ANCH)
    wr(RT, s)
    applied.append('regtest.cpp: the R362 audit')
s = rd(RT)
assert s.count(
    'R362 UA MU 8th/9th level spells pin audit'
    ) == 1, 'd audit line'
assert s.count(
    'R361 UA MU 7th level spells pin'
    ' audit: bad ') == 1, 'd r361 kept'
assert s.count(
    'R360 UA MU 5th/6th level spells pin'
    ' audit: bad ') == 1, 'd r360 kept'
assert s.count(
    'R359 UA MU 4th level spells'
    ' pin audit: bad ') == 1, 'd r359 kept'
assert s.count(
    'R358 UA MU 3rd level spells'
    ' pin audit: bad ') == 1, 'd r358 kept'
assert s.count(
    'R357 UA MU 2nd level spells'
    ' pin audit: bad ') == 1, 'd r357 kept'
assert s.count(
    'R356 UA MU 1st level spells'
    ' pin audit: bad ') == 1, 'd r356 kept'
assert s.count('audit: bad ') == 289, 'd census 289'
assert s.count(
    'R355 UA druid 7th level spells'
    ' pin audit: bad ') == 1, 'd r355 kept'
assert s.count(
    'R354 UA druid 6th level spells'
    ' pin audit: bad ') == 1, 'd r354 kept'
assert s.count(
    'R350 UA druid 1st level spells'
    ' pin audit: bad ') == 1, 'd r350 kept'
assert s.count(
    'R349 UA cleric 7th level spells'
    ' pin audit: bad ') == 1, 'd r349 kept'
assert s.count(
    'R227: the wis mental save'
    ) == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uamuspells9.h"'
    ) == 1, 'd include 9'
assert s.count(
    '#include "rules/uamuspells8.h"'
    ) == 1, 'd include 8'
assert s.count(
    '#include "rules/uamuspells7.h"'
    ) == 1, 'd r361 include'
assert s.count(
    '#include "rules/uamuspells6.h"'
    ) == 1, 'd r360 include'
assert s.count(
    '#include "rules/uamuspells5.h"'
    ) == 1, 'd r360-5 include'
assert s.count(
    '#include "rules/uamuspells4.h"'
    ) == 1, 'd r359 include'
assert s.count(
    '#include "rules/uamuspells3.h"'
    ) == 1, 'd r358 include'
assert s.count(
    '#include "rules/uamuspells2.h"'
    ) == 1, 'd r357 include'
assert s.count(
    '#include "rules/uamuspells1.h"'
    ) == 1, 'd r356 include'
assert len(applied) + len(already) == 5, 'd count'


# ---- the summary ----
print('R362 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R362 note: the UA new magic-user')
print('spells pin round, the 8th and 9th')
print('levels - the eight spell')
print('descriptions (binding behind the')
print('lost range and duration cells with')
print('the six forms and the save ladder;')
print('demand behind the garbled')
print('components cell; the Otiluke')
print('telekinetic sphere behind the')
print('garbled name header with the lost')
print('range cell; sink behind the lost')
print('level cell with the sinking')
print('ladder; crystalbrittle with the')
print('item save ladder; succor with the')
print('interleaved stat tail; energy')
print('drain with the displaced casting')
print('cell; the Mordenkainen disjunction')
print('behind the garbled name header')
print('with the artifact chances); the')
print('R342 MU table seam checks demand')
print('at index 0 and sink at index 8')
print('with binding and the sphere')
print('absent, and only the two PHB 9th')
print('names print; the item CLOSES -')
print('all printed levels pinned (R356-')
print('R361 plus this round); the census')
print('288 -> 289')
print('commit: R362: the UA new')
print('magic-user 8th and 9th level')
print('spells pin round (census 289)')

