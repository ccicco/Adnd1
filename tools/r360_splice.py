#!/usr/bin/env python3
# R360: the UA NEW MAGIC-USER
# SPELLS pin round, the 5th and
# 6th levels (pp. 51-71) -
# avoidance, dismissal, dolor,
# fabricate, the Leomund
# belabourment, sending; chain
# lightning, contingency,
# ensnarement, eyebite, the
# Mordenkainen lucubration,
# transmute water to dust. The
# digit-garble family decodes
# the casting and duration 7s
# as 1; the range 7s stay as
# printed. The R342 table seam
# pins 4 of the 6 5th-level
# names; the 6th-level column
# is wholly lost. The item
# stays open (the 7th-9th
# levels).
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


# ---- (a) the seed: the R359 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R359 landed 2026-10-11: commit',
    '  97e1ff2, census 286, the UA',
    '  new magic-user 4th level spells',
    '  pin round (rules/uamuspells4.h):',
    '  the eight spell descriptions',
    '  (dispel illusion behind the lost',
    '  name tail and the garbled',
    '  half-inch range, the Evard',
    '  black tentacles behind the lost',
    '  level and range cells with the',
    '  stray gf line, the Leomund',
    '  secure shelter with the',
    '  scrambled wind sentence, magic',
    '  mirror with the scrambled',
    '  component list, the Otiluke',
    '  resilient sphere with the lost',
    '  globe sentence, shout with the',
    '  scrambled area tail, stoneskin',
    '  behind the lost level and range',
    '  cells, ultravision with the tail',
    '  past the 5th heading); the R342',
    '  MU table seam prints seven of',
    '  the eight names, the Dispel',
    '  fragment cell reads as a hole;',
    '  the 5th through 9th',
    '  levels. GREEN on the first',
    '  run.',
])
s = rd(SD)
if 'R359 landed 2026-10-11' in s:
    already.append('seed: the R359 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R359 record')
s = rd(SD)
assert s.count('R359 landed 2026-10-11') == 1, 'a entry'
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


# ---- (b) NEW rules/uamuspells5.h ----
US5 = 'rules/uamuspells5.h'
if os.path.exists(US5) and 'R360' in rd(US5):
    already.append('uamuspells5.h: the pins')
else:
    HDR5 = r"""// ===========================================================================
// Adnd1 - rules/uamuspells5.h
// The UA NEW MAGIC-USER SPELLS (pp. 51-66) pins, R360: the
// 5th-level spell descriptions - avoidance, dismissal,
// dolor, fabricate, the Leomund belabourment and
// sending.
//
// Pin-era pattern (R322): pinned data only - no engine site
// exists.
//
// JUDGMENTs (the decode method):
//   - the digit-garble family (the R343 precedent): the
//     casting-time and duration 7s decode as 1 - the
//     sending "7 turn" as 1 turn. The range 7s stay as
//     printed (the dolor "7"" and the ensnarement "7"",
//     in rules/uamuspells6.h): the family decodes a
//     range cell only when corroborated (the flaming
//     sphere prose, the R352 cloudburst seam, the druid
//     water-to-dust seam below) - pending the PDF.
//   - the avoidance name header is lost entirely - the
//     section head prints bare; the name pins from the
//     gap item list and the prose ("cast avoidance upon
//     the apparel"). The range cell prints empty and the
//     area cell truncates at "Up to" - holes pending the
//     PDF; the components cell is lost in the interleave
//     (the prose supplies the magnetized needle).
//   - the dismissal name header is lost in the
//     belabourment interleave - the Explanation line
//     prints inside the scrambled open-paren-C block; the clean
//     stat lines (V, M; 3 segments; special) print after
//     the avoidance prose; a stray "cube" fragment
//     follows - flagged pending the PDF. The dismissal
//     prose tail (the Prime Material exclusions - shedu,
//     cambions) prints at the region head, above the
//     avoidance block.
//   - the belabourment name header is lost - the
//     fragment plus "peel 5"; the name pins from the gap
//     item list and the R342 table seam (Leomund's
//     Lamentable Belabourment). The components cell is
//     lost (the prose pins the spell as entirely
//     verbal); the school is lost pending the PDF. The
//     scrambled head carries stat fragments (one round
//     casting, neg. save, permanent, one creature) and
//     the dominating-intelligence fragment - their
//     attribution is uncertain, flagged pending the PDF,
//     not pinned as data.
//   - the dolor prose head scrambles ("By mess of this
//     spell...") - the effect ladder and the -1/-2/-3
//     save adjustments still pin.
//   - the fabricate block pins clean.
//   - the sending block pins clean except the family
//     casting-time cell.
//
// ===========================================================================

namespace rules {

// ---- avoidance (Abjuration unknown), the 5th level ----
// The name header is lost entirely - the section head
// prints bare; the name pins from the gap item list.
inline const char* uam5AvoidanceName()
    { return "Avoidance"; }

inline bool uam5AvoidanceNameHeaderLost()
    { return true; }

inline int uam5AvoidanceLevel()
    { return 5; }

// The range cell prints empty - a hole pending the PDF.
inline bool uam5AvoidanceRangeCellEmpty()
    { return true; }

inline bool uam5AvoidanceDurationUntilDispelled()
    { return true; }

// The area cell truncates at "Up to" - a hole pending
// the PDF.
inline bool uam5AvoidanceAoeCellTruncated()
    { return true; }

// The components cell is lost in the interleave; the
// prose supplies the material.
inline bool uam5AvoidanceComponentsCellLost()
    { return true; }

// The caster sets up a natural repulsion between the
// affected object and any living things.
inline bool uam5AvoidanceNaturalRepulsion()
    { return true; }

// Any living creature attempting to touch the affected
// object is repulsed - unable to come closer than 1
// foot (the degree-mark family) - or repulses the
// object, depending on the relative mass of the two.
inline int uam5AvoidanceRepulsionFeet()
    { return 1; }

inline bool uam5AvoidanceDependsOnRelativeMass()
    { return true; }

// A lone halfling attempting to touch an iron chest
// with the spell upon it is thrown back; a dozen such
// halflings cannot come within 1 foot of the chest.
inline bool uam5AvoidanceLoneHalflingThrownBack()
    { return true; }

inline bool uam5AvoidanceDozenHalflingsKeptOff()
    { return true; }

// The chest skitters away from a giant-sized creature
// as the creature approaches.
inline bool uam5AvoidanceObjectSkittersFromGiant()
    { return true; }

// The spell cannot be cast upon living things; any
// attempt to cast it upon the apparel or possessions
// borne by a living creature entitles the subject to a
// saving throw.
inline bool uam5AvoidanceNotOnLivingThings()
    { return true; }

inline bool uam5AvoidancePossessionsEntitleSave()
    { return true; }

// The material: a magnetized needle.
inline bool uam5AvoidanceMaterialMagnetizedNeedle()
    { return true; }

// The reverse, attraction, uses the same material
// components and sets up a natural attraction between
// the object and all living things.
inline bool uam5AvoidanceReverseAttraction()
    { return true; }

// A smaller creature is drawn to the object; a
// greater-mass creature draws the object to slide
// toward it.
inline bool uam5AvoidanceReverseMassBehavior()
    { return true; }

// A successful bend bars roll removes an object once
// it has adhered to another object or creature.
inline bool uam5AvoidanceReverseBendBarsRemoves()
    { return true; }

// ---- dismissal (school lost), the 5th level ----
// The name header is lost in the belabourment
// interleave; the name pins from the gap item list.
inline const char* uam5DismissalName()
    { return "Dismissal"; }

inline bool uam5DismissalNameHeaderLost()
    { return true; }

inline int uam5DismissalLevel()
    { return 5; }

// The clean stat lines print after the avoidance prose.
inline bool uam5DismissalStatAfterAvoidanceProse()
    { return true; }

inline bool uam5DismissalComponentsVM()
    { return true; }

inline int uam5DismissalCastingTimeSegments()
    { return 3; }

inline bool uam5DismissalSaveSpecial()
    { return true; }

// A stray "cube" fragment follows the stat lines -
// flagged pending the PDF, not pinned as data.
inline bool uam5DismissalCubeFragmentGarbled()
    { return true; }

// The Explanation line prints inside the scrambled
// belabourment block.
inline bool uam5DismissalProseInBelabourmentBlock()
    { return true; }

// The spell seeks to force or allow some creature from
// another plane of existence to return to its proper
// plane (cf. the 4th-level cleric spell abjure).
inline bool uam5DismissalReturnsToProperPlane()
    { return true; }

inline bool uam5DismissalCfAbjure()
    { return true; }

// The name of the type of creature must be known; a
// given, proper, or surname too must be known and used.
inline bool uam5DismissalNameMustBeKnown()
    { return true; }

// Magic resistance, if any, is checked for effect
// immediately.
inline bool uam5DismissalMagicResistanceImmediate()
    { return true; }

// The caster level is compared to the creature level or
// hit dice: a higher caster number subtracts the
// difference from the creature saving-throw score; a
// higher creature number adds it.
inline bool uam5DismissalLevelCompareAdjustsSave()
    { return true; }

// Exception: if the creature desires to be dismissed,
// then only a saving throw is needed.
inline bool uam5DismissalDesireMeansSaveOnly()
    { return true; }

// Certain arcane works are reputed to allow greatly
// enhanced chances for spell success.
inline bool uam5DismissalArcaneWorksEnhance()
    { return true; }

// On success the creature is instantly whisked away;
// the spell has a 20% chance of sending the subject to
// a plane other than its own.
inline bool uam5DismissalInstantWhisk()
    { return true; }

inline int uam5DismissalWrongPlanePct()
    { return 20; }

// The reverse, beckon, conjures up a known and named
// (if applicable) creature from another plane;
// success determined the same way, but magic
// resistance is only checked if the creature has no
// known proper name.
inline bool uam5DismissalReverseBeckon()
    { return true; }

inline bool uam5DismissalBeckonResistanceOnlyUnnamed()
    { return true; }

// On beckon success the creature is instantly
// transported to the plane of the spell caster - not
// guaranteed kindly disposed nor subject to the
// caster's wishes.
inline bool uam5DismissalBeckonTransportedToCaster()
    { return true; }

inline bool uam5DismissalBeckonNotKindlyDisposal()
    { return true; }

// The materials vary with the creature type:
// inimical and distasteful items for a dismissal;
// pleasing, desirable, rewarding ones for a beckon.
inline bool uam5DismissalMaterialsVaryWithCreature()
    { return true; }

inline bool uam5DismissalMaterialInimical()
    { return true; }

inline bool uam5DismissalBeckonMaterialPleasing()
    { return true; }

// The prose tail prints at the region head, above the
// avoidance block: the spell does not work on
// creatures native to the Prime Material Plane that
// travel to other planes (such as shedu), nor against
// creatures with part of their ancestry in the Prime
// Material Plane (such as cambions).
inline bool uam5DismissalTailAtRegionHead()
    { return true; }

inline bool uam5DismissalNotOnPrimeNatives()
    { return true; }

inline bool uam5DismissalNotOnPrimeAncestry()
    { return true; }

// ---- dolor (Enchantment/Charm), the 5th level ----
inline const char* uam5DolorName()
    { return "Dolor (Enchantment/Charm)"; }

inline int uam5DolorLevel()
    { return 5; }

// The range prints 7 inches - pinned as printed; the
// family decodes only corroborated range cells.
inline int uam5DolorRangeInches()
    { return 7; }

inline bool uam5DolorRangeAsPrintedPendingPdf()
    { return true; }

inline int uam5DolorDurationRounds()
    { return 2; }

inline bool uam5DolorAoeOneCreature()
    { return true; }

inline bool uam5DolorComponentsVS()
    { return true; }

inline int uam5DolorCastingTimeSegments()
    { return 5; }

inline bool uam5DolorSaveSpecial()
    { return true; }

// The prose head scrambles ("By mess of this spell...")
// - the effect ladder still pins.
inline bool uam5DolorProseHeadScrambled()
    { return true; }

// The dweomer causes unease in the creature during its
// mere casting; on the round after, the subject becomes
// nervous and filled with doubts; on the last round of
// effect the creature feels a dull, all-encompassing
// dolor.
inline bool uam5DolorUneaseDuringCasting()
    { return true; }

inline bool uam5DolorNervousSecondRound()
    { return true; }

inline bool uam5DolorDullDolorLastRound()
    { return true; }

// The saving throws are adjusted: -1 initially, -2
// next, -3 on the tertiary effect; thereafter the
// creature is no longer affected and saves without
// adjustment.
inline int uam5DolorSaveAdjustInitial()
    { return 1; }

inline int uam5DolorSaveAdjustSecond()
    { return 2; }

inline int uam5DolorSaveAdjustTertiary()
    { return 3; }

inline bool uam5DolorAdjustsAllSaves()
    { return true; }

inline bool uam5DolorUnaffectedAfterLastRound()
    { return true; }

// The verbal component must deal with the class of
// creature in question, containing as much information
// as possible about the subject.
inline bool uam5DolorVerbalDealsWithCreatureClass()
    { return true; }

// ---- fabricate (Enchantment/Alteration), the 5th ----
inline const char* uam5FabricateName()
    { return "Fabricate (Enchantment - Alteration)"; }

inline int uam5FabricateLevel()
    { return 5; }

inline bool uam5FabricateDurationPermanent()
    { return true; }

inline bool uam5FabricateComponentsVSM()
    { return true; }

inline bool uam5FabricateCastingTimeSpecial()
    { return true; }

inline bool uam5FabricateSaveNone()
    { return true; }

inline int uam5FabricateAoeCuYdPerLevel()
    { return 1; }

// The spell converts material of one sort into a
// product of desired nature basically of the same
// material - a wooden bridge from a clump of trees, a
// rope from hemp, clothes from flax or wool.
inline bool uam5FabricateSameMaterialProducts()
    { return true; }

inline bool uam5FabricateBridgeRopeClothesExamples()
    { return true; }

// Magical or living things cannot be created or
// altered.
inline bool uam5FabricateNoMagicalOrLiving()
    { return true; }

// The quality of items made is commensurate with the
// quality of the material used.
inline bool uam5FabricateQualityCommensurate()
    { return true; }

// With mineral material the area of effect reduces by
// a factor of nine - 1 cubic yard becomes 1 cubic
// foot.
inline int uam5FabricateMineralFactor()
    { return 9; }

inline bool uam5FabricateMineralYdToFoot()
    { return true; }

// Articles requiring a high degree of craftsmanship -
// jewelry, swords, glass, crystal - cannot be
// fabricated unless the caster actually has great
// skill in the craft.
inline bool uam5FabricateCraftsmanshipNeedsSkill()
    { return true; }

inline bool uam5FabricateCraftArticlesExamples()
    { return true; }

// Casting requires 1 full round per cubic yard (or
// foot) of material affected.
inline int uam5FabricateRoundsPerCuUnit()
    { return 1; }

// ---- the Leomund belabourment, the 5th level ----
// The name header is lost - the open-paren-C fragment plus
// "peel 5"; the name pins from the gap item list and
// the R342 table seam.
inline const char* uam5BelabourmentName()
    { return "Leomund's Lamentable Belabourment"; }

inline bool uam5BelabourmentNameHeaderLost()
    { return true; }

inline bool uam5BelabourmentSchoolLost()
    { return true; }

inline int uam5BelabourmentLevel()
    { return 5; }

// The components cell is lost; the prose pins the
// spell as entirely verbal.
inline bool uam5BelabourmentComponentsCellLost()
    { return true; }

inline bool uam5BelabourmentEntirelyVerbal()
    { return true; }

inline int uam5BelabourmentCastingTimeSegments()
    { return 5; }

inline int uam5BelabourmentRangeInches()
    { return 1; }

inline bool uam5BelabourmentSaveSpecial()
    { return true; }

inline bool uam5BelabourmentDurationSpecial()
    { return true; }

inline bool uam5BelabourmentAoeOneOrMoreIn1InchRadius()
    { return true; }

// The scrambled head carries stat fragments (one round
// casting, neg. save, permanent, one creature) and the
// dominating-intelligence fragment - attribution
// uncertain, flagged pending the PDF, not pinned as
// data.
inline bool uam5BelabourmentHeadFragmentsUncertain()
    { return true; }

// The caster speaks the language of the creature(s)
// and begins discussion of some topic germane to them.
inline bool uam5BelabourmentGermaneDiscussion()
    { return true; }

// Those not saving versus spell immediately begin to
// converse with the caster, agreeing or disagreeing,
// all most politely.
inline bool uam5BelabourmentConversePolitely()
    { return true; }

// The caster maintains the spell by conversing, as
// long as chosen; the subjects ignore all else going
// on around them so long as no attack is made upon
// them, spending time exclusively talking and
// arguing.
inline bool uam5BelabourmentMaintainedByConversing()
    { return true; }

inline bool uam5BelabourmentSubjectsIgnoreAllElse()
    { return true; }

// The saving throw is modified by the target
// intelligence: 2 or lower unaffected; 3-7 save at -1;
// 8-10 save normally; 11-14 at +1; 15 or higher at
// +2.
inline int uam5BelabourmentIntUnaffectedMax()
    { return 2; }

inline int uam5BelabourmentIntLowSaveMinus()
    { return 1; }

inline bool uam5BelabourmentIntLadder()
    { return true; }

// If maintained more than 3 rounds, each subject must
// attempt another save: those failing wander off in
// confusion for 3-12 rounds, avoiding the caster; the
// survivors stay in fascination and save again in the
// 4th, 5th and 6th rounds (or as long as maintained).
inline int uam5BelabourmentConfusionAfterRounds()
    { return 3; }

inline int uam5BelabourmentConfusionRoundsMin()
    { return 3; }

inline int uam5BelabourmentConfusionRoundsMax()
    { return 12; }

inline bool uam5BelabourmentFascinationResave456()
    { return true; }

// If maintained more than 6 rounds, each subject saves
// to avoid a rage - at oneself if the sole object, or
// at all other subjects - attacking one's own person
// or falling upon the nearest other subject with
// intent to kill; the rage lasts 2-5 rounds.
inline int uam5BelabourmentRageAfterRounds()
    { return 6; }

inline int uam5BelabourmentRageRoundsMin()
    { return 2; }

inline int uam5BelabourmentRageRoundsMax()
    { return 5; }

inline bool uam5BelabourmentRageAtSelfOrOthers()
    { return true; }

// Those saving against the rage realize they have
// fallen prey to the spell and collapse onto the
// ground, lamenting their foolishness, for 1-4 rounds
// unless attacked or otherwise disturbed.
inline int uam5BelabourmentLamentRoundsMin()
    { return 1; }

inline int uam5BelabourmentLamentRoundsMax()
    { return 4; }

// If the caster is attacked or distracted during the
// maintenance, he or she is still protected - the
// subjects will not notice.
inline bool uam5BelabourmentCasterProtectedIfAttacked()
    { return true; }

// The caster can leave at any time after the casting;
// the subjects continue for 1 full round as if the
// caster were still there, but continuance saves are
// not applicable then.
inline bool uam5BelabourmentCasterCanLeave()
    { return true; }

inline int uam5BelabourmentContinuesAfterLeavingRounds()
    { return 1; }

inline bool uam5BelabourmentNoSavesAfterLeaving()
    { return true; }

// ---- sending (Evocation), the 5th level ----
inline const char* uam5SendingName()
    { return "Sending (Evocation)"; }

inline int uam5SendingLevel()
    { return 5; }

inline bool uam5SendingRangeSpecial()
    { return true; }

inline bool uam5SendingDurationSpecial()
    { return true; }

inline bool uam5SendingAoeOneCreature()
    { return true; }

inline bool uam5SendingComponentsVSM()
    { return true; }

// The casting time prints "7 turn" - the family
// decodes 1 turn.
inline int uam5SendingCastingTimeTurns()
    { return 1; }

inline bool uam5SendingSaveNone()
    { return true; }

// The caster contacts a single creature with whom he
// or she is familiar and whose name and appearance are
// well known.
inline bool uam5SendingContactFamiliarNamed()
    { return true; }

// Off the same plane, there is a 5% chance per plane
// removed that the sending will not arrive - two
// planes removed, a 10% chance of failure.
inline int uam5SendingFailPctPerPlane()
    { return 5; }

inline bool uam5SendingTwoPlanesTenPctExample()
    { return true; }

// The caster sends one word per level of experience,
// with articles (a, an, the) not counted.
inline bool uam5SendingOneWordPerLevel()
    { return true; }

inline bool uam5SendingArticlesNotCounted()
    { return true; }

// The subject is not obligated to act upon the
// sending in any manner.
inline bool uam5SendingNotObligated()
    { return true; }

// The sending is understood even by a creature with
// an intelligence as little as 1 (animal
// intelligence).
inline bool uam5SendingUnderstoodAtIntOne()
    { return true; }

// The material: two tiny cylinders, each with one open
// end, connected by a short piece of copper wire.
inline bool uam5SendingMaterialTwoCylindersCopperWire()
    { return true; }

}   // namespace rules
"""
    clean(HDR5, 78)
    wr(US5, HDR5 + NL)
    applied.append('uamuspells5.h: the pins')
s = rd(US5)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 131, 'b inline count'
assert s.count('R360') == 1, 'b round tag'
assert s.count('uam5AvoidanceName()') == 1, 'b avoidance fn'
assert s.count(
    'uam5SendingMaterialTwoCylindersCopperWire()'
    ) == 1, 'b sending fn'
assert 'uam4' not in s, 'b no r359 ref'
assert 'uam3' not in s, 'b no r358 ref'
assert 'uam2' not in s, 'b no r357 ref'
assert 'uam1' not in s, 'b no r356 ref'
assert 'uac1' not in s, 'b no r343 ref'
assert 'uad3' not in s, 'b no druid ref'
assert 'uas2' not in s, 'b no r342 ref'
assert len(applied) + len(already) == 2, 'b count'


# ---- (b2) NEW rules/uamuspells6.h ----
US6 = 'rules/uamuspells6.h'
if os.path.exists(US6) and 'R360' in rd(US6):
    already.append('uamuspells6.h: the pins')
else:
    HDR6 = r"""// ===========================================================================
// Adnd1 - rules/uamuspells6.h
// The UA NEW MAGIC-USER SPELLS (pp. 66-71) pins, R360: the
// 6th-level spell descriptions - chain lightning,
// contingency, ensnarement, eyebite, the Mordenkainen
// lucubration and transmute water to dust.
//
// Pin-era pattern (R322): pinned data only - no engine site
// exists.
//
// JUDGMENTs (the decode method):
//   - the digit-garble family (the R343 precedent): the
//     casting-time and duration 7s decode as 1 - the
//     contingency "7 day/level" as 1 day/level, the
//     eyebite and lucubration "7 segment" as 1 segment.
//     The range 7s stay as printed (the ensnarement "7""
//     below): the family decodes a range cell only when
//     corroborated (the flaming sphere prose, the R352
//     cloudburst seam, the druid water-to-dust seam
//     below) - pending the PDF. The water-to-dust "7
//     cubic" area decodes as 1 - corroborated by the
//     druid seam in rules/uadruidspells6.h.
//   - the R342 MU table seam loses the whole 6th-level
//     column - no 6th-level seam fn
//     exists; every 6th-level name pins
//     from the section bodies and the gap item list.
//   - the ensnarement name header is lost - the section
//     opens with a bare open-paren-C fragment; the name
//     pins from the gap item list and the prose (the
//     "ensnarement spell" self-references). The stat
//     block prints clean after the scrambled head.
//   - the eyebite header garbles the school tail
//     ("harm, lllusion/F tasm") - the school is a hole
//     pending the PDF, not pinned as data. The
//     components cell prints "V" plus a garbled sign -
//     flagged pending the PDF. A scrambled note has the
//     creatures saving at +4 - flagged pending the PDF.
//   - the lucubration name header is lost - the section
//     opens with a bare "sl" fragment; the name pins
//     from the gap item list and the prose (the
//     "Mordenkainen Lucubration" self-reference). The
//     duration cell is lost - the "Instantaneous" line
//     prints as a bare stat fragment.
//   - the water-to-dust header prints the short name
//     only; the full name "Transmute Water To Dust"
//     pins from the R342 spell-table seam and the
//     druid spell of the same name. The magic-user
//     print gives a 6-segment casting against the
//     druid seam 8 - flagged as a print discrepancy
//     (the cloudburst precedent), pinned as printed.
//   - the chain lightning range cell truncates after
//     the base 4 - the per-level tail is a hole pending
//     the PDF, the base pins as printed. The saving
//     throw cell garbles a "2 fraction ("2 or Neg.")
//     - the save pins from the prose (a half-damage
//     save per strike plus a hit-arc save), the cell
//     flagged pending the PDF.
// ===========================================================================

namespace rules {

// ---- chain lightning (Evocation) ----
inline const char* uam6ChainName()
    { return "Chain Lightning (Evocation)"; }

inline int uam6ChainLevel()
    { return 6; }

inline bool uam6ChainComponentsVSM()
    { return true; }

inline int uam6ChainCastingTimeSegments()
    { return 6; }

// The range cell truncates after the base 4 - the
// per-level tail is a hole pending the PDF.
inline int uam6ChainRangeBaseInches()
    { return 4; }

inline bool uam6ChainRangePerLevelTailLost()
    { return true; }

// The saving throw cell garbles a 2 fraction; the save
// pins from the prose instead.
inline bool uam6ChainSaveCellFractionGarbled()
    { return true; }

// A saving throw versus spell decides whether the bolt
// actually arcs to a secondary target; a saved target
// takes no damage and the stroke arcs onward.
inline bool uam6ChainSaveAvoidsSecondaryHit()
    { return true; }

// Each strike also allows the half-damage save.
inline bool uam6ChainHalfDamageSavePerStrike()
    { return true; }

inline bool uam6ChainDurationInstantaneous()
    { return true; }

inline bool uam6ChainAoeSpecial()
    { return true; }

// The bolt begins one quarter inch wide at the
// fingertips and extends to the primary target.
inline bool uam6ChainStrokeQuarterInchWide()
    { return true; }

// The primary target must lie within the maximum range
// dictated by the caster level.
inline bool uam6ChainPrimaryWithinRangeLimit()
    { return true; }

// The primary target takes 1d6 damage per caster level.
inline int uam6ChainPrimaryDicePerLevel()
    { return 1; }

inline int uam6ChainPrimaryDiceSides()
    { return 6; }

// Each target after the primary takes one less d6 than
// the target before it, down to 1d6.
inline int uam6ChainDiceStepDownPerTarget()
    { return 1; }

// The chain builds up to as many links, including the
// initial target, as the caster has levels.
inline bool uam6ChainLinksEqualCasterLevels()
    { return true; }

// A 12th-level caster hits 12 targets: the primary
// first, then 11 others.
inline int uam6ChainExampleLevel()
    { return 12; }

inline int uam6ChainExampleTargets()
    { return 12; }

// Equidistant targets: the bolt arcs to metal first,
// then to the one with the most fluid, else at random.
inline bool uam6ChainTiebreakMetalThenFluid()
    { return true; }

// The chain can oscillate between two immobilized
// objects or form a regular pattern of three or more.
inline bool uam6ChainOscillationPossible()
    { return true; }

// A single arc can never exceed the range limit; a
// longer needed arc fades into nothing.
inline bool uam6ChainArcBoundedByRange()
    { return true; }

// A tree or a substantial piece of conductive metal
// grounds the stroke and ends the arcing.
inline bool uam6ChainGroundedByTreeOrMetal()
    { return true; }

// The caster can be struck by an arc from his or her
// own spell.
inline bool uam6ChainCasterCanBeStruck()
    { return true; }

// The material components: a bit of fur; an amber,
// glass, or crystal rod; and as many silver pins as the
// caster has levels.
inline bool uam6ChainMaterialFurRodPins()
    { return true; }

inline bool uam6ChainSilverPinsPerLevel()
    { return true; }

// ---- contingency (Evocation) ----
inline const char* uam6ContName()
    { return "Contingency (Evocation)"; }

inline int uam6ContLevel()
    { return 6; }

// The casting time and components cells are lost in
// the scrambled block; the prose pins the 1-turn
// casting as the total for both spells.
inline bool uam6ContCastingCellsLost()
    { return true; }

inline int uam6ContCastingTimeTurns()
    { return 1; }

inline bool uam6ContCastingCoversBothSpells()
    { return true; }

inline int uam6ContRangeZero()
    { return 0; }

// The digit-garble family decodes the "7 day/level"
// duration as 1 day per level.
inline int uam6ContDurationDaysPerLevel()
    { return 1; }

inline bool uam6ContSaveNone()
    { return true; }

inline bool uam6ContAoeTheMagicUser()
    { return true; }

// The companion spell must affect the magic-user's
// person (feather fall, levitation, fly, statue,
// feign death, etc.).
inline bool uam6ContCompanionAffectsCaster()
    { return true; }

// The companion is limited to one-third of the caster
// level, rounded down, capped at the 6th spell level.
inline int uam6ContCompanionLevelDivisor()
    { return 3; }

inline bool uam6ContCompanionLevelCap()
    { return 6; }

// A 4th-level maximum at 12th, 13th or 14th level.
inline int uam6ContMax4thAtLevel()
    { return 12; }

// A 5th-level maximum at 15th, 16th or 17th level.
inline int uam6ContMax5thAtLevel()
    { return 15; }

// A 6th-level maximum at 18th level and beyond.
inline int uam6ContMax6thAtLevel()
    { return 18; }

// Only one contingency can be in effect at a time; a
// second cancels the first if still active.
inline bool uam6ContOneAtATime()
    { return true; }

inline bool uam6ContSecondCancelsFirst()
    { return true; }

// The prescribed situation must be clear, although it
// can be rather general.
inline bool uam6ContSituationClearThoughGeneral()
    { return true; }

// The companion spell is cast instantaneously when the
// circumstances occur.
inline bool uam6ContCompanionInstantaneous()
    { return true; }

// Complex or unlikely situations are likely to cause
// the whole spell complex to fail when called upon.
inline bool uam6ContComplexSituationsLikelyFail()
    { return true; }

// The material components, beyond the companion
// spell's own: 100 gp worth of quicksilver, an
// elephant ivory statuette of the magic-user, and an
// eyelash of an ogre magi, ki-rin, or similar
// spell-using creature.
inline int uam6ContQuicksilverGp()
    { return 100; }

inline bool uam6ContMaterialIvoryStatuette()
    { return true; }

inline bool uam6ContMaterialEyelashSpellUser()
    { return true; }

// The statuette is not destroyed by the casting and
// must be carried on the caster's person.
inline bool uam6ContStatuetteNotConsumed()
    { return true; }

inline bool uam6ContStatuetteMustBeCarried()
    { return true; }

// ---- ensnarement (Conjuration/Summoning) ----
// The name header is lost; the school cell does not
// print. The name pins from the gap item list and the
// prose; the school is a hole pending the PDF.
inline const char* uam6EnsnareName()
    { return "Ensnarement (Conjuration/Summoning)"; }

inline bool uam6EnsnareNameHeaderLost()
    { return true; }

inline bool uam6EnsnareSchoolCellLost()
    { return true; }

inline bool uam6EnsnareComponentsVSM()
    { return true; }

inline int uam6EnsnareLevel()
    { return 6; }

inline int uam6EnsnareCastingTimeTurns()
    { return 1; }

// The range 7 stays as printed - the family decodes a
// range cell only when corroborated; flagged pending
// the PDF.
inline int uam6EnsnareRangeInches()
    { return 7; }

inline bool uam6EnsnareRangePendingPdf()
    { return true; }

inline bool uam6EnsnareDurationSpecial()
    { return true; }

inline bool uam6EnsnareAoeSpecial()
    { return true; }

inline bool uam6EnsnareSaveNeg()
    { return true; }

// The spell lures a powerful creature from another
// plane into a specially prepared trap, holding it
// until it agrees to perform one service.
inline bool uam6EnsnareOneServiceForFreedom()
    { return true; }

// The creature must save by rolling equal to or less
// than its intelligence on 3d6.
inline int uam6EnsnareSaveDice()
    { return 3; }

inline int uam6EnsnareSaveDieSides()
    { return 6; }

// If the creature's intelligence is higher, the
// difference is subtracted from its roll; if the
// caster's is higher, the difference is added.
inline bool uam6EnsnareSaveModifiedByIntDiff()
    { return true; }

// A saved throw means the creature ignores the
// opening and the dweomer fails.
inline bool uam6EnsnareSaveIgnoresOpening()
    { return true; }

// The creature type must be known and stated; a
// specific, proper, or given name must be used.
inline bool uam6EnsnareCreatureMustBeNamed()
    { return true; }

// A magic circle for Ethereal or Astral creatures; a
// pentagram for creatures from the lower infernal
// planes.
inline bool uam6EnsnareCircleForEtherealAstral()
    { return true; }

inline bool uam6EnsnarePentagramForInfernal()
    { return true; }

// Break-free base: 20% for a hand-done design, 10%
// for one inlaid or carved.
inline int uam6EnsnareBreakBaseHandPct()
    { return 20; }

inline int uam6EnsnareBreakBaseInlaidPct()
    { return 10; }

// The base chance applies for the first time only,
// indicating whether the job was done properly.
inline bool uam6EnsnareBaseFirstTimeOnly()
    { return true; }

// The break-free chance is further modified by the
// combined caster level and intelligence against the
// creature level-or-hit-dice and intelligence.
inline bool uam6EnsnareBreakModifiedByTotals()
    { return true; }

// If the caster's total is higher, the difference is
// subtracted from the creature's chance; if the
// creature's total is higher, it is added.
inline bool uam6EnsnareBreakDiffSubtractedOrAdded()
    { return true; }

// Specially prepared pigments at 1,000 gp per turn of
// application reduce the chance by 1% per turn.
inline int uam6EnsnarePigmentGpPerTurn()
    { return 1000; }

inline int uam6EnsnarePigmentPctPerTurn()
    { return 1; }

// This can bring the base to 0%, but the intelligence
// and level/hit-dice modifications still apply.
inline bool uam6EnsnarePigmentCannotNegateMods()
    { return true; }

// An inlaid or inscribed design reaches 0% by inlaying
// metals, minerals, etc., into the stone - one month
// of full-time work and not less than 50,000 gp.
inline int uam6EnsnareInlayMonths()
    { return 1; }

inline int uam6EnsnareInlayGp()
    { return 50000; }

// A straw dropped across the lines, or any blurring of
// the glyphs, runes, and sigils, spoils the barrier
// and the creature breaks free automatically.
inline bool uam6EnsnareStrawSpoilsBarrier()
    { return true; }

// The creature within cannot place a straw upon any
// portion of the device - the barrier prevents it.
inline bool uam6EnsnareCreatureCannotSpoil()
    { return true; }

// The caster can bribe, promise, or threaten; the DM
// rates the offer from 0 to 6, subtracted from the
// creature's intelligence.
inline int uam6EnsnareOfferRatingMin()
    { return 0; }

inline int uam6EnsnareOfferRatingMax()
    { return 6; }

// A save equal to or less than the adjusted
// intelligence means the creature refuses service.
inline bool uam6EnsnareSaveRefusesService()
    { return true; }

// New offers can be made 24 hours later, when the
// creature's intelligence has dropped by 1 point from
// the confinement.
inline int uam6EnsnareReofferHours()
    { return 24; }

inline int uam6EnsnareIntDropPerDay()
    { return 1; }

// The cycle repeats until service, break-free, or a
// riddance spell release.
inline bool uam6EnsnareRepeatUntilService()
    { return true; }

// Once the single service is completed, the creature
// need only inform the caster to be instantly
// teleported from whence it came.
inline bool uam6EnsnareTeleportAfterService()
    { return true; }

// Revenge can be sought - cf. efreeti, aerial servant,
// and invisible stalker; certain services will never
// be agreed to.
inline bool uam6EnsnareRevengeRisk()
    { return true; }

// ---- eyebite ----
// The header garbles the school tail; the school is a
// hole pending the PDF, not pinned as data.
inline const char* uam6EyeName()
    { return "Eyebite"; }

inline bool uam6EyeSchoolHeaderGarbled()
    { return true; }

inline bool uam6EyeSchoolPendingPdf()
    { return true; }

// The components cell prints V plus a garbled sign -
// flagged pending the PDF.
inline bool uam6EyeComponentsV()
    { return true; }

inline bool uam6EyeComponentsCellGarbled()
    { return true; }

inline int uam6EyeLevel()
    { return 6; }

inline int uam6EyeRangeInches()
    { return 20; }

// The digit-garble family decodes the "7 segment"
// casting time as 1 segment.
inline int uam6EyeCastingTimeSegments()
    { return 1; }

inline bool uam6EyeDurationSpecial()
    { return true; }

inline bool uam6EyeSaveSpecial()
    { return true; }

inline bool uam6EyeAoeOneCreature()
    { return true; }

// The caster meets the subject's gaze and speaks a
// single word; choosing one effect dissipates the
// spell even though only one of four was used.
inline bool uam6EyeGazePlusSingleWord()
    { return true; }

inline int uam6EyeEffectCount()
    { return 4; }

inline bool uam6EyeDissipatesAfterOneEffect()
    { return true; }

// A scrambled note has the creatures saving at +4 -
// flagged pending the PDF.
inline bool uam6EyeSavePlusFourNoteGarbled()
    { return true; }

// Charm: a person or monster becomes absolutely loyal
// and docile, even to personal danger; otherwise the
// same as charm person or charm monster. A save versus
// spell negates.
inline bool uam6EyeCharmLoyalDocile()
    { return true; }

inline bool uam6EyeCharmSameAsCharmSpells()
    { return true; }

inline bool uam6EyeCharmSaveNegates()
    { return true; }

// Fear: the subject acts as if struck by a fear spell
// unless a save versus spell succeeds.
inline bool uam6EyeFearAsFearSpell()
    { return true; }

inline bool uam6EyeFearSaveNegates()
    { return true; }

// Sicken: sudden nausea - one-half normal abilities and
// movement; the victim must rest half of each turn to
// move at all. Creatures without ability scores are
// not affected. A save versus spell negates.
inline bool uam6EyeSickenHalfAbilities()
    { return true; }

inline bool uam6EyeSickenHalfMovement()
    { return true; }

inline bool uam6EyeSickenRestHalfTurn()
    { return true; }

inline bool uam6EyeSickenSkipsNoScoreCreatures()
    { return true; }

inline bool uam6EyeSickenSaveNegates()
    { return true; }

// Otherwise the victim loses one point of
// constitution per day until death at zero.
inline int uam6EyeSickenConLossPerDay()
    { return 1; }

// The sickness is negated by a dispel magic or a heal;
// alter reality, limited wish, and wish also cure it,
// but a cure disease does not.
inline bool uam6EyeSickenCuredByDispelOrHeal()
    { return true; }

inline bool uam6EyeSickenCuredByWishFamily()
    { return true; }

inline bool uam6EyeSickenNotCuredByCureDisease()
    { return true; }

// Sleep: a comatose slumber unless the subject saves
// versus spell. Creatures normally subject to the
// 1st-level sleep spell save at -2. Undead are not
// subject. Affected creatures must be shaken or
// shocked back to consciousness.
inline bool uam6EyeSleepComatose()
    { return true; }

inline bool uam6EyeSleepSaveNegates()
    { return true; }

inline int uam6EyeSleepSaveAdj()
    { return -2; }

inline bool uam6EyeSleepUndeadImmune()
    { return true; }

inline bool uam6EyeSleepNeedsShaking()
    { return true; }

// ---- the Mordenkainen lucubration ----
// The name header is lost - a bare "sl" fragment; the
// name pins from the gap item list and the prose.
inline const char* uam6LucName()
    { return "Mordenkainen's Lucubration"; }

inline bool uam6LucNameHeaderLost()
    { return true; }

inline bool uam6LucComponentsVS()
    { return true; }

// The digit-garble family decodes the "7 segment"
// casting time as 1 segment.
inline int uam6LucCastingTimeSegments()
    { return 1; }

inline bool uam6LucSaveNone()
    { return true; }

// The duration cell is lost - the "Instantaneous"
// line prints as a bare stat fragment; flagged
// pending the PDF.
inline bool uam6LucDurationCellLost()
    { return true; }

inline bool uam6LucDurationInstantaneous()
    { return true; }

inline int uam6LucLevel()
    { return 6; }

inline bool uam6LucAoeTheMagicUser()
    { return true; }

// The caster instantly recalls any spell used and
// otherwise forgotten during the past 24 hours.
inline int uam6LucRecallWindowHours()
    { return 24; }

// The recalled spell must have been memorized and
// actually used within the window, and cannot be of
// greater power than fifth level.
inline bool uam6LucRecallMustHaveBeenCast()
    { return true; }

inline int uam6LucRecallMaxLevel()
    { return 5; }

// Only one such spell can be recalled per lucubration;
// it can be cast normally on any succeeding round.
inline bool uam6LucOneSpellPerCasting()
    { return true; }

inline bool uam6LucRecastOnSucceedingRound()
    { return true; }

// Material spell components must be available if the
// recalled spell requires such, or the remembered
// spell is not usable until they are.
inline bool uam6LucComponentsMustBeAvailable()
    { return true; }

// ---- transmute water to dust ----
// The header prints the short name only; the full name
// pins from the R342 spell-table seam and the druid
// spell of the same name.
inline const char* uam6WaterName()
    { return "Transmute Water To Dust"; }

inline bool uam6WaterHeaderPrintsShortName()
    { return true; }

// The components cell prints a garbled sign for the S;
// the spell is V, S, M - the magic-user needs no
// mistletoe, unlike the druid version.
inline bool uam6WaterComponentsVSM()
    { return true; }

inline bool uam6WaterComponentsCellGarbled()
    { return true; }

inline bool uam6WaterNoMistletoe()
    { return true; }

inline int uam6WaterLevel()
    { return 6; }

inline int uam6WaterRangeInches()
    { return 6; }

// The print gives a 6-segment casting against the
// druid seam 8 - flagged as a print discrepancy (the
// cloudburst precedent), pinned as printed.
inline int uam6WaterCastingTimeSegments()
    { return 6; }

inline int uam6WaterDruidSeamCastingTimeSegments()
    { return 8; }

inline bool uam6WaterCastingDiscrepancyFlagged()
    { return true; }

inline bool uam6WaterSaveNoneAndSpecial()
    { return true; }

inline bool uam6WaterDurationPermanent()
    { return true; }

// The "7 cubic" area decodes as 1 cubic inch per
// caster level - corroborated by the druid seam.
inline int uam6WaterCubicInchesPerLevel()
    { return 1; }

inline bool uam6WaterAoeGarbleCorroborated()
    { return true; }

// The spell is identical to the 6th-level druid spell
// of the same name, except as noted above.
inline bool uam6WaterSameAsDruid6th()
    { return true; }

// ===========================================================================

}   // namespace rules
"""
    clean(HDR6, 78)
    wr(US6, HDR6 + NL)
    applied.append('uamuspells6.h: the pins')
s = rd(US6)
assert s.count('namespace rules {') == 1, 'b2 ns'
assert s.count('inline') == 154, 'b2 inline count'
assert s.count('R360') == 1, 'b2 round tag'
assert s.count('uam6ChainName()') == 1, 'b2 chain fn'
assert s.count(
    'uam6WaterSameAsDruid6th()'
    ) == 1, 'b2 water fn'
assert 'uam5' not in s, 'b2 no r360-5 ref'
assert 'uam4' not in s, 'b2 no r359 ref'
assert 'uam3' not in s, 'b2 no r358 ref'
assert 'uam2' not in s, 'b2 no r357 ref'
assert 'uam1' not in s, 'b2 no r356 ref'
assert 'uac1' not in s, 'b2 no r343 ref'
assert 'uad3' not in s, 'b2 no druid ref'
assert 'uas2' not in s, 'b2 no r342 ref'
assert len(applied) + len(already) == 3, 'b2 count'


# ---- (c) the gap report: the note (the
# item STAYS OPEN - the 7th-9th levels) ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'R360: the 5th and 6th levels' in s:
    already.append('gap report: the note')
else:
    TAIL_OLD = NL.join([
        '        fragment cell reads as a',
        '        hole; the 5th through 9th',
        '        levels stay open.',
        '- [ ] **The new illusionist spells**',
    ])
    assert s.count(TAIL_OLD) == 1, 'c tail'
    NOTE = NL.join([
    '      - R360: the 5th and 6th levels',
    '        pinned (rules/uamuspells5.h',
    '        and rules/uamuspells6.h) - the',
    '        six 5th-level descriptions',
    '        (avoidance behind the lost',
    '        name header, dismissal behind',
    '        the belabourment interleave,',
    '        dolor with the range as',
    '        printed, fabricate, the Leomund',
    '        belabourment behind the lost',
    '        name header, sending) and the',
    '        six 6th-level descriptions',
    '        (chain lightning behind the',
    '        truncated range tail and the',
    '        garbled save fraction,',
    '        contingency behind the lost',
    '        casting cells, ensnarement',
    '        behind the lost name header,',
    '        eyebite behind the garbled',
    '        school tail, the Mordenkainen',
    '        lucubration behind the lost',
    '        name header, transmute water',
    '        to dust seam-checking the',
    '        druid pin minus the mistletoe',
    '        with the 6-segment print',
    '        flagged against the druid 8);',
    '        the family decodes the casting',
    '        and duration 7s as 1 with the',
    '        range 7s staying as printed;',
    '        the R342 MU table seam prints',
    '        four of the 5th-level names,',
    '        avoidance and dolor absent,',
    '        and the 6th-level column is',
    '        wholly lost; the 7th through',
    '        9th levels stay open.',
    ])
    clean(NOTE, 57)
    s = s.replace(TAIL_OLD, NL.join([
        '        fragment cell reads as a',
        '        hole; the 5th through 9th',
        '        levels stay open.',
        NOTE,
        '- [ ] **The new illusionist spells**',
    ]))
    wr(GP, s)
    applied.append('gap report: the note')
s = rd(GP)
assert s.count(
    'R360: the 5th and 6th levels'
    ) == 1, 'c note'
assert s.count(
    'R359: the 4th level pinned'
    ) == 1, 'c r359 kept'
assert s.count(
    '- [ ] **The new magic-user spells**'
    ) == 1, 'c stays open'
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
if 'R360 UA MU 5th and 6th level spells pin' in s:
    already.append('regtest.cpp: the R360 audit')
else:
    INC_ANCH = (
        '#include "rules/uamuspells4.h"'
        '  // R359: the UA new magic-user'
        ' 4th level')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uamuspells5.h"'
        '  // R360: the UA new magic-user'
        ' 5th level',
        '#include "rules/uamuspells6.h"'
        '  // R360: the UA new magic-user'
        ' 6th level',
    ])
    AUD_ANCH = ('    // ---- R227: the wis mental'
                ' save wiring audit ----')
    AUDIT = r"""    // ---- R360: the UA new magic-user 5th and
    // 6th level spells pin audit ----
    // The UA NEW MAGIC-USER SPELLS (pp.
    // 51-71), the 5th and 6th levels -
    // avoidance behind the lost name
    // header, dismissal behind the
    // belabourment interleave, dolor with
    // the range as printed, fabricate,
    // the Leomund belabourment, sending;
    // chain lightning behind the
    // truncated range tail, contingency
    // behind the lost casting cells,
    // ensnarement behind the lost name
    // header, eyebite behind the garbled
    // school tail, the Mordenkainen
    // lucubration behind the lost name
    // header, transmute water to dust
    // seam-checking the druid pin minus
    // the mistletoe with the 6-segment
    // print flagged against the druid 8.
    // The family decodes the casting and
    // duration 7s as 1; the range 7s stay
    // as printed. The R342 table seam
    // prints 4 of the 5th-level names
    // (avoidance and dolor absent); the
    // 6th-level column is wholly lost -
    // no seam exists. The item stays open
    // (the 7th-9th levels).
    {
        using namespace rules;
        int bad = 0;
        // U1: avoidance
            if (strcmp(uam5AvoidanceName(),
                "Avoidance") != 0) ++bad;
            if (!uam5AvoidanceNameHeaderLost()) ++bad;
            if (uam5AvoidanceLevel() != 5) ++bad;
            if (!uam5AvoidanceRangeCellEmpty()) ++bad;
            if (!uam5AvoidanceDurationUntilDispelled()) ++bad;
            if (!uam5AvoidanceAoeCellTruncated()) ++bad;
            if (!uam5AvoidanceComponentsCellLost()) ++bad;
            if (!uam5AvoidanceNaturalRepulsion()) ++bad;
            if (uam5AvoidanceRepulsionFeet() != 1) ++bad;
            if (!uam5AvoidanceDependsOnRelativeMass()) ++bad;
            if (!uam5AvoidanceLoneHalflingThrownBack()) ++bad;
            if (!uam5AvoidanceDozenHalflingsKeptOff()) ++bad;
            if (!uam5AvoidanceObjectSkittersFromGiant()) ++bad;
            if (!uam5AvoidanceNotOnLivingThings()) ++bad;
            if (!uam5AvoidancePossessionsEntitleSave()) ++bad;
            if (!uam5AvoidanceMaterialMagnetizedNeedle()) ++bad;
            if (!uam5AvoidanceReverseAttraction()) ++bad;
            if (!uam5AvoidanceReverseMassBehavior()) ++bad;
            if (!uam5AvoidanceReverseBendBarsRemoves()) ++bad;

        // U2: dismissal
            if (strcmp(uam5DismissalName(),
                "Dismissal") != 0) ++bad;
            if (!uam5DismissalNameHeaderLost()) ++bad;
            if (uam5DismissalLevel() != 5) ++bad;
            if (!uam5DismissalStatAfterAvoidanceProse()) ++bad;
            if (!uam5DismissalComponentsVM()) ++bad;
            if (uam5DismissalCastingTimeSegments() != 3) ++bad;
            if (!uam5DismissalSaveSpecial()) ++bad;
            if (!uam5DismissalCubeFragmentGarbled()) ++bad;
            if (!uam5DismissalProseInBelabourmentBlock()) ++bad;
            if (!uam5DismissalReturnsToProperPlane()) ++bad;
            if (!uam5DismissalCfAbjure()) ++bad;
            if (!uam5DismissalNameMustBeKnown()) ++bad;
            if (!uam5DismissalMagicResistanceImmediate()) ++bad;
            if (!uam5DismissalLevelCompareAdjustsSave()) ++bad;
            if (!uam5DismissalDesireMeansSaveOnly()) ++bad;
            if (!uam5DismissalArcaneWorksEnhance()) ++bad;
            if (!uam5DismissalInstantWhisk()) ++bad;
            if (uam5DismissalWrongPlanePct() != 20) ++bad;
            if (!uam5DismissalReverseBeckon()) ++bad;
            if (!uam5DismissalBeckonResistanceOnlyUnnamed()) ++bad;
            if (!uam5DismissalBeckonTransportedToCaster()) ++bad;
            if (!uam5DismissalBeckonNotKindlyDisposal()) ++bad;
            if (!uam5DismissalMaterialsVaryWithCreature()) ++bad;
            if (!uam5DismissalMaterialInimical()) ++bad;
            if (!uam5DismissalBeckonMaterialPleasing()) ++bad;
            if (!uam5DismissalTailAtRegionHead()) ++bad;
            if (!uam5DismissalNotOnPrimeNatives()) ++bad;
            if (!uam5DismissalNotOnPrimeAncestry()) ++bad;

        // U3: dolor
            if (strcmp(uam5DolorName(),
                "Dolor (Enchantment/Charm)") != 0) ++bad;
            if (uam5DolorLevel() != 5) ++bad;
            if (uam5DolorRangeInches() != 7) ++bad;
            if (!uam5DolorRangeAsPrintedPendingPdf()) ++bad;
            if (uam5DolorDurationRounds() != 2) ++bad;
            if (!uam5DolorAoeOneCreature()) ++bad;
            if (!uam5DolorComponentsVS()) ++bad;
            if (uam5DolorCastingTimeSegments() != 5) ++bad;
            if (!uam5DolorSaveSpecial()) ++bad;
            if (!uam5DolorProseHeadScrambled()) ++bad;
            if (!uam5DolorUneaseDuringCasting()) ++bad;
            if (!uam5DolorNervousSecondRound()) ++bad;
            if (!uam5DolorDullDolorLastRound()) ++bad;
            if (uam5DolorSaveAdjustInitial() != 1) ++bad;
            if (uam5DolorSaveAdjustSecond() != 2) ++bad;
            if (uam5DolorSaveAdjustTertiary() != 3) ++bad;
            if (!uam5DolorAdjustsAllSaves()) ++bad;
            if (!uam5DolorUnaffectedAfterLastRound()) ++bad;
            if (!uam5DolorVerbalDealsWithCreatureClass()) ++bad;

        // U4: fabricate
            if (strcmp(uam5FabricateName(),
                "Fabricate (Enchantment - Alteration)") != 0) ++bad;
            if (uam5FabricateLevel() != 5) ++bad;
            if (!uam5FabricateDurationPermanent()) ++bad;
            if (!uam5FabricateComponentsVSM()) ++bad;
            if (!uam5FabricateCastingTimeSpecial()) ++bad;
            if (!uam5FabricateSaveNone()) ++bad;
            if (uam5FabricateAoeCuYdPerLevel() != 1) ++bad;
            if (!uam5FabricateSameMaterialProducts()) ++bad;
            if (!uam5FabricateBridgeRopeClothesExamples()) ++bad;
            if (!uam5FabricateNoMagicalOrLiving()) ++bad;
            if (!uam5FabricateQualityCommensurate()) ++bad;
            if (uam5FabricateMineralFactor() != 9) ++bad;
            if (!uam5FabricateMineralYdToFoot()) ++bad;
            if (!uam5FabricateCraftsmanshipNeedsSkill()) ++bad;
            if (!uam5FabricateCraftArticlesExamples()) ++bad;
            if (uam5FabricateRoundsPerCuUnit() != 1) ++bad;

        // U5: the Leomund belabourment
            if (strcmp(uam5BelabourmentName(),
                "Leomund's Lamentable Belabourment") != 0) ++bad;
            if (!uam5BelabourmentNameHeaderLost()) ++bad;
            if (!uam5BelabourmentSchoolLost()) ++bad;
            if (uam5BelabourmentLevel() != 5) ++bad;
            if (!uam5BelabourmentComponentsCellLost()) ++bad;
            if (!uam5BelabourmentEntirelyVerbal()) ++bad;
            if (uam5BelabourmentCastingTimeSegments() != 5) ++bad;
            if (uam5BelabourmentRangeInches() != 1) ++bad;
            if (!uam5BelabourmentSaveSpecial()) ++bad;
            if (!uam5BelabourmentDurationSpecial()) ++bad;
            if (!uam5BelabourmentAoeOneOrMoreIn1InchRadius()) ++bad;
            if (!uam5BelabourmentHeadFragmentsUncertain()) ++bad;
            if (!uam5BelabourmentGermaneDiscussion()) ++bad;
            if (!uam5BelabourmentConversePolitely()) ++bad;
            if (!uam5BelabourmentMaintainedByConversing()) ++bad;
            if (!uam5BelabourmentSubjectsIgnoreAllElse()) ++bad;
            if (uam5BelabourmentIntUnaffectedMax() != 2) ++bad;
            if (uam5BelabourmentIntLowSaveMinus() != 1) ++bad;
            if (!uam5BelabourmentIntLadder()) ++bad;
            if (uam5BelabourmentConfusionAfterRounds() != 3) ++bad;
            if (uam5BelabourmentConfusionRoundsMin() != 3) ++bad;
            if (uam5BelabourmentConfusionRoundsMax() != 12) ++bad;
            if (!uam5BelabourmentFascinationResave456()) ++bad;
            if (uam5BelabourmentRageAfterRounds() != 6) ++bad;
            if (uam5BelabourmentRageRoundsMin() != 2) ++bad;
            if (uam5BelabourmentRageRoundsMax() != 5) ++bad;
            if (!uam5BelabourmentRageAtSelfOrOthers()) ++bad;
            if (uam5BelabourmentLamentRoundsMin() != 1) ++bad;
            if (uam5BelabourmentLamentRoundsMax() != 4) ++bad;
            if (!uam5BelabourmentCasterProtectedIfAttacked()) ++bad;
            if (!uam5BelabourmentCasterCanLeave()) ++bad;
            if (uam5BelabourmentContinuesAfterLeavingRounds() != 1) ++bad;
            if (!uam5BelabourmentNoSavesAfterLeaving()) ++bad;

        // U6: sending
            if (strcmp(uam5SendingName(),
                "Sending (Evocation)") != 0) ++bad;
            if (uam5SendingLevel() != 5) ++bad;
            if (!uam5SendingRangeSpecial()) ++bad;
            if (!uam5SendingDurationSpecial()) ++bad;
            if (!uam5SendingAoeOneCreature()) ++bad;
            if (!uam5SendingComponentsVSM()) ++bad;
            if (uam5SendingCastingTimeTurns() != 1) ++bad;
            if (!uam5SendingSaveNone()) ++bad;
            if (!uam5SendingContactFamiliarNamed()) ++bad;
            if (uam5SendingFailPctPerPlane() != 5) ++bad;
            if (!uam5SendingTwoPlanesTenPctExample()) ++bad;
            if (!uam5SendingOneWordPerLevel()) ++bad;
            if (!uam5SendingArticlesNotCounted()) ++bad;
            if (!uam5SendingNotObligated()) ++bad;
            if (!uam5SendingUnderstoodAtIntOne()) ++bad;
            if (!uam5SendingMaterialTwoCylindersCopperWire()) ++bad;

        // U7: chain lightning
            if (strcmp(uam6ChainName(),
                "Chain Lightning (Evocation)") != 0) ++bad;
            if (uam6ChainLevel() != 6) ++bad;
            if (!uam6ChainComponentsVSM()) ++bad;
            if (uam6ChainCastingTimeSegments() != 6) ++bad;
            if (uam6ChainRangeBaseInches() != 4) ++bad;
            if (!uam6ChainRangePerLevelTailLost()) ++bad;
            if (!uam6ChainSaveCellFractionGarbled()) ++bad;
            if (!uam6ChainSaveAvoidsSecondaryHit()) ++bad;
            if (!uam6ChainHalfDamageSavePerStrike()) ++bad;
            if (!uam6ChainDurationInstantaneous()) ++bad;
            if (!uam6ChainAoeSpecial()) ++bad;
            if (!uam6ChainStrokeQuarterInchWide()) ++bad;
            if (!uam6ChainPrimaryWithinRangeLimit()) ++bad;
            if (uam6ChainPrimaryDicePerLevel() != 1) ++bad;
            if (uam6ChainPrimaryDiceSides() != 6) ++bad;
            if (uam6ChainDiceStepDownPerTarget() != 1) ++bad;
            if (!uam6ChainLinksEqualCasterLevels()) ++bad;
            if (uam6ChainExampleLevel() != 12) ++bad;
            if (uam6ChainExampleTargets() != 12) ++bad;
            if (!uam6ChainTiebreakMetalThenFluid()) ++bad;
            if (!uam6ChainOscillationPossible()) ++bad;
            if (!uam6ChainArcBoundedByRange()) ++bad;
            if (!uam6ChainGroundedByTreeOrMetal()) ++bad;
            if (!uam6ChainCasterCanBeStruck()) ++bad;
            if (!uam6ChainMaterialFurRodPins()) ++bad;
            if (!uam6ChainSilverPinsPerLevel()) ++bad;

        // U8: contingency
            if (strcmp(uam6ContName(),
                "Contingency (Evocation)") != 0) ++bad;
            if (uam6ContLevel() != 6) ++bad;
            if (!uam6ContCastingCellsLost()) ++bad;
            if (uam6ContCastingTimeTurns() != 1) ++bad;
            if (!uam6ContCastingCoversBothSpells()) ++bad;
            if (uam6ContRangeZero() != 0) ++bad;
            if (uam6ContDurationDaysPerLevel() != 1) ++bad;
            if (!uam6ContSaveNone()) ++bad;
            if (!uam6ContAoeTheMagicUser()) ++bad;
            if (!uam6ContCompanionAffectsCaster()) ++bad;
            if (uam6ContCompanionLevelDivisor() != 3) ++bad;
            if (!uam6ContCompanionLevelCap()) ++bad;
            if (uam6ContMax4thAtLevel() != 12) ++bad;
            if (uam6ContMax5thAtLevel() != 15) ++bad;
            if (uam6ContMax6thAtLevel() != 18) ++bad;
            if (!uam6ContOneAtATime()) ++bad;
            if (!uam6ContSecondCancelsFirst()) ++bad;
            if (!uam6ContSituationClearThoughGeneral()) ++bad;
            if (!uam6ContCompanionInstantaneous()) ++bad;
            if (!uam6ContComplexSituationsLikelyFail()) ++bad;
            if (uam6ContQuicksilverGp() != 100) ++bad;
            if (!uam6ContMaterialIvoryStatuette()) ++bad;
            if (!uam6ContMaterialEyelashSpellUser()) ++bad;
            if (!uam6ContStatuetteNotConsumed()) ++bad;
            if (!uam6ContStatuetteMustBeCarried()) ++bad;

        // U9: ensnarement
            if (strcmp(uam6EnsnareName(),
                "Ensnarement (Conjuration/Summoning)") != 0) ++bad;
            if (!uam6EnsnareNameHeaderLost()) ++bad;
            if (!uam6EnsnareSchoolCellLost()) ++bad;
            if (!uam6EnsnareComponentsVSM()) ++bad;
            if (uam6EnsnareLevel() != 6) ++bad;
            if (uam6EnsnareCastingTimeTurns() != 1) ++bad;
            if (uam6EnsnareRangeInches() != 7) ++bad;
            if (!uam6EnsnareRangePendingPdf()) ++bad;
            if (!uam6EnsnareDurationSpecial()) ++bad;
            if (!uam6EnsnareAoeSpecial()) ++bad;
            if (!uam6EnsnareSaveNeg()) ++bad;
            if (!uam6EnsnareOneServiceForFreedom()) ++bad;
            if (uam6EnsnareSaveDice() != 3) ++bad;
            if (uam6EnsnareSaveDieSides() != 6) ++bad;
            if (!uam6EnsnareSaveModifiedByIntDiff()) ++bad;
            if (!uam6EnsnareSaveIgnoresOpening()) ++bad;
            if (!uam6EnsnareCreatureMustBeNamed()) ++bad;
            if (!uam6EnsnareCircleForEtherealAstral()) ++bad;
            if (!uam6EnsnarePentagramForInfernal()) ++bad;
            if (uam6EnsnareBreakBaseHandPct() != 20) ++bad;
            if (uam6EnsnareBreakBaseInlaidPct() != 10) ++bad;
            if (!uam6EnsnareBaseFirstTimeOnly()) ++bad;
            if (!uam6EnsnareBreakModifiedByTotals()) ++bad;
            if (!uam6EnsnareBreakDiffSubtractedOrAdded()) ++bad;
            if (uam6EnsnarePigmentGpPerTurn() != 1000) ++bad;
            if (uam6EnsnarePigmentPctPerTurn() != 1) ++bad;
            if (!uam6EnsnarePigmentCannotNegateMods()) ++bad;
            if (uam6EnsnareInlayMonths() != 1) ++bad;
            if (uam6EnsnareInlayGp() != 50000) ++bad;
            if (!uam6EnsnareStrawSpoilsBarrier()) ++bad;
            if (!uam6EnsnareCreatureCannotSpoil()) ++bad;
            if (uam6EnsnareOfferRatingMin() != 0) ++bad;
            if (uam6EnsnareOfferRatingMax() != 6) ++bad;
            if (!uam6EnsnareSaveRefusesService()) ++bad;
            if (uam6EnsnareReofferHours() != 24) ++bad;
            if (uam6EnsnareIntDropPerDay() != 1) ++bad;
            if (!uam6EnsnareRepeatUntilService()) ++bad;
            if (!uam6EnsnareTeleportAfterService()) ++bad;
            if (!uam6EnsnareRevengeRisk()) ++bad;

        // U10: eyebite
            if (strcmp(uam6EyeName(),
                "Eyebite") != 0) ++bad;
            if (!uam6EyeSchoolHeaderGarbled()) ++bad;
            if (!uam6EyeSchoolPendingPdf()) ++bad;
            if (!uam6EyeComponentsV()) ++bad;
            if (!uam6EyeComponentsCellGarbled()) ++bad;
            if (uam6EyeLevel() != 6) ++bad;
            if (uam6EyeRangeInches() != 20) ++bad;
            if (uam6EyeCastingTimeSegments() != 1) ++bad;
            if (!uam6EyeDurationSpecial()) ++bad;
            if (!uam6EyeSaveSpecial()) ++bad;
            if (!uam6EyeAoeOneCreature()) ++bad;
            if (!uam6EyeGazePlusSingleWord()) ++bad;
            if (uam6EyeEffectCount() != 4) ++bad;
            if (!uam6EyeDissipatesAfterOneEffect()) ++bad;
            if (!uam6EyeSavePlusFourNoteGarbled()) ++bad;
            if (!uam6EyeCharmLoyalDocile()) ++bad;
            if (!uam6EyeCharmSameAsCharmSpells()) ++bad;
            if (!uam6EyeCharmSaveNegates()) ++bad;
            if (!uam6EyeFearAsFearSpell()) ++bad;
            if (!uam6EyeFearSaveNegates()) ++bad;
            if (!uam6EyeSickenHalfAbilities()) ++bad;
            if (!uam6EyeSickenHalfMovement()) ++bad;
            if (!uam6EyeSickenRestHalfTurn()) ++bad;
            if (!uam6EyeSickenSkipsNoScoreCreatures()) ++bad;
            if (!uam6EyeSickenSaveNegates()) ++bad;
            if (uam6EyeSickenConLossPerDay() != 1) ++bad;
            if (!uam6EyeSickenCuredByDispelOrHeal()) ++bad;
            if (!uam6EyeSickenCuredByWishFamily()) ++bad;
            if (!uam6EyeSickenNotCuredByCureDisease()) ++bad;
            if (!uam6EyeSleepComatose()) ++bad;
            if (!uam6EyeSleepSaveNegates()) ++bad;
            if (uam6EyeSleepSaveAdj() != -2) ++bad;
            if (!uam6EyeSleepUndeadImmune()) ++bad;
            if (!uam6EyeSleepNeedsShaking()) ++bad;

        // U11: the Mordenkainen lucubration
            if (strcmp(uam6LucName(),
                "Mordenkainen's Lucubration") != 0) ++bad;
            if (!uam6LucNameHeaderLost()) ++bad;
            if (!uam6LucComponentsVS()) ++bad;
            if (uam6LucCastingTimeSegments() != 1) ++bad;
            if (!uam6LucSaveNone()) ++bad;
            if (!uam6LucDurationCellLost()) ++bad;
            if (!uam6LucDurationInstantaneous()) ++bad;
            if (uam6LucLevel() != 6) ++bad;
            if (!uam6LucAoeTheMagicUser()) ++bad;
            if (uam6LucRecallWindowHours() != 24) ++bad;
            if (!uam6LucRecallMustHaveBeenCast()) ++bad;
            if (uam6LucRecallMaxLevel() != 5) ++bad;
            if (!uam6LucOneSpellPerCasting()) ++bad;
            if (!uam6LucRecastOnSucceedingRound()) ++bad;
            if (!uam6LucComponentsMustBeAvailable()) ++bad;

        // U12: transmute water to dust
            if (strcmp(uam6WaterName(),
                "Transmute Water To Dust") != 0) ++bad;
            if (!uam6WaterHeaderPrintsShortName()) ++bad;
            if (!uam6WaterComponentsVSM()) ++bad;
            if (!uam6WaterComponentsCellGarbled()) ++bad;
            if (!uam6WaterNoMistletoe()) ++bad;
            if (uam6WaterLevel() != 6) ++bad;
            if (uam6WaterRangeInches() != 6) ++bad;
            if (uam6WaterCastingTimeSegments() != 6) ++bad;
            if (uam6WaterDruidSeamCastingTimeSegments() != 8) ++bad;
            if (!uam6WaterCastingDiscrepancyFlagged()) ++bad;
            if (!uam6WaterSaveNoneAndSpecial()) ++bad;
            if (!uam6WaterDurationPermanent()) ++bad;
            if (uam6WaterCubicInchesPerLevel() != 1) ++bad;
            if (!uam6WaterAoeGarbleCorroborated()) ++bad;
            if (!uam6WaterSameAsDruid6th()) ++bad;

        // the R342 table seam (4 of the 6 5th-level
        // names; avoidance and dolor absent; the
        // 6th-level column is wholly lost)
        if (uas2Mu5thCount() != 28) ++bad;
        if (strcmp(uas2Mu5thName(8),
                "Dismissal") != 0) ++bad;
        if (strcmp(uas2Mu5thName(11),
                "Fabricate") != 0) ++bad;
        if (strcmp(uas2Mu5thName(14),
                "Leomund's Lamentable Belabourment")
                != 0) ++bad;
        if (strcmp(uas2Mu5thName(20),
                "Sending") != 0) ++bad;
        // the absent names (the avoidance and
        // dolor holes)
        for (int i = 0; i < 28; ++i) {
            const char* n = uas2Mu5thName(i);
            if (strcmp(n, "Avoidance") == 0)
                ++bad;
            if (strcmp(n, "Dolor") == 0) ++bad;
        }
        // the water-to-dust seam against the R352
        // druid pin - identical data except the
        // mistletoe and the flagged casting time
        if (uam6WaterLevel()
                != uad6WaterToDustLevel()) ++bad;
        if (uam6WaterRangeInches()
                != uad6WaterToDustRangeInches()) ++bad;
        if (uam6WaterCastingTimeSegments() != 6)
            ++bad;
        if (uad6WaterToDustCastingTimeSegments()
                != 8) ++bad;
        if (uam6WaterCastingTimeSegments()
                == uad6WaterToDustCastingTimeSegments())
            ++bad;
        if (!uam6WaterCastingDiscrepancyFlagged())
            ++bad;
        if (uam6WaterCubicInchesPerLevel()
                != uad6WaterToDustAoeCubicInchesPerLevel())
            ++bad;
        if (!uam6WaterAoeGarbleCorroborated())
            ++bad;
        if (strcmp(uam6WaterName(),
                "Transmute Water To Dust") != 0)
            ++bad;
        if (uad6WaterToDustMaterialMistletoe()
                && uam6WaterNoMistletoe()) { /* ok */ }
        else ++bad;
        if (!uad6WaterToDustMaterialMistletoe())
            ++bad;
        if (!uam6WaterSameAsDruid6th()) ++bad;
        printf("R360 UA MU 5th and 6th level spells pin
               " audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R360 audit')
s = rd(RT)
assert s.count(
    'R360 UA MU 5th and 6th level spells pin'
    ) == 1, 'd audit line'
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
assert s.count('audit: bad ') == 287, 'd census 287'
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
    '#include "rules/uamuspells6.h"'
    ) == 1, 'd include 6'
assert s.count(
    '#include "rules/uamuspells5.h"'
    ) == 1, 'd include 5'
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
print('R360 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R360 note: the UA new magic-user')
print('spells pin round, the 5th and')
print('6th levels - the twelve spell')
print('descriptions (avoidance behind')
print('the lost name header; dismissal')
print('behind the belabourment')
print('interleave; dolor with the')
print('range as printed; fabricate;')
print('the Leomund belabourment')
print('behind the lost name header;')
print('sending; chain lightning')
print('behind the truncated range')
print('tail and the garbled save')
print('fraction; contingency behind')
print('the lost casting cells;')
print('ensnarement behind the lost')
print('name header; eyebite behind')
print('the garbled school tail; the')
print('Mordenkainen lucubration')
print('behind the lost name header;')
print('transmute water to dust')
print('seam-checking the druid pin')
print('minus the mistletoe with the')
print('6-segment print flagged')
print('against the druid 8); the')
print('family decodes the casting and')
print('duration 7s as 1 with the')
print('range 7s staying as printed;')
print('the R342 MU table seam prints')
print('four of the 5th-level names,')
print('avoidance and dolor absent,')
print('and the 6th-level column is')
print('wholly lost; the item stays')
print('open (the 7th-9th levels);')
print('the census 286 -> 287')
print('commit: R360: the UA new')
print('magic-user 5th and 6th level')
print('spells pin round (census 287)')

