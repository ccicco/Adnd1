#!/usr/bin/env python3
# R361: the UA NEW MAGIC-USER
# SPELLS pin round, the 7th level
# (pp. 66-71) - banishment,
# forcecage, the Mordenkainen
# magnificent mansion, sequester,
# teleport without error,
# torment, truename, volley (the
# last two printing past the
# 8th-level table page). The
# digit-garble family decodes the
# casting and duration 7s as 1.
# The R342 table seam prints only
# PHB fragments - none of the new
# names seam-checks. The item
# stays open (the 8th-9th
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


# ---- (a) the seed: the R360 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R360 landed 2026-10-11: commit',
    '  47a3e4f plus the 997ef44 b',
    '  follow-up, census 287, the',
    '  UA new magic-user 5th and',
    '  6th level spells pin round',
    '  (rules/uamuspells5.h and',
    '  rules/uamuspells6.h): the',
    '  twelve spell descriptions',
    '  (avoidance behind the lost',
    '  name header, dismissal',
    '  behind the belabourment',
    '  interleave, dolor with the',
    '  range as printed, fabricate,',
    '  the Leomund belabourment',
    '  behind the lost name header,',
    '  sending; chain lightning',
    '  behind the truncated range',
    '  tail and the garbled save',
    '  fraction, contingency',
    '  behind the lost casting',
    '  cells, ensnarement behind',
    '  the lost name header,',
    '  eyebite behind the garbled',
    '  school tail, the Mordenkainen',
    '  lucubration behind the lost',
    '  name header, transmute water',
    '  to dust seam-checking the',
    '  druid pin minus the mistletoe',
    '  with the 6-segment print',
    '  flagged against the druid 8);',
    '  the family decodes the',
    '  casting and duration 7s as',
    '  1 with the range 7s staying',
    '  as printed; the R342 MU',
    '  table seam prints four of',
    '  the 5th-level names,',
    '  avoidance and dolor absent,',
    '  and the 6th-level column is',
    '  wholly lost; the b follow-up',
    '  repaired the split audit',
    '  printf; GREEN on the first',
    '  run.',
])
s = rd(SD)
if 'R360 landed 2026-10-11' in s:
    already.append('seed: the R360 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R360 record')
s = rd(SD)
assert s.count('R360 landed 2026-10-11') == 1, 'a entry'
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


# ---- (b) NEW rules/uamuspells7.h ----
US = 'rules/uamuspells7.h'
if os.path.exists(US) and 'R361' in rd(US):
    already.append('uamuspells7.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uamuspells7.h
// The UA NEW MAGIC-USER SPELLS (pp. 66-71) pins, R361: the
// 7th-level spell descriptions - banishment, forcecage, the
// Mordenkainen magnificent mansion, sequester, teleport
// without error, torment, truename and volley.
//
// Pin-era pattern (R322): pinned data only - no engine site
// exists.
//
// JUDGMENTs (the decode method):
//   - the digit-garble family (the R343 precedent): the
//     casting-time and duration 7s decode as 1 - the
//     banishment 7 segments as 1, the mansion 7 rounds as
//     1, the sequester and torment 7 rounds as 1, the
//     truename 7 segments as 1. No range cell prints a
//     corroborated 7 this round.
//   - the R342 MU table seam prints only seven readable
//     7th-level fragments - all PHB names; none of the new
//     names seam-checks, noted in the audit. Every new name
//     pins from the section bodies and the gap item list.
//   - the volley and truename sections print AFTER the
//     8th-level spell-table page - a misbinding; their
//     level cells print the clean 7 and the gap item list
//     carries them under the 7th level.
//   - the banishment stat head scrambles - the components
//     print as a garbled V, S, segments M line above a
//     bare Components cell; the range prints as a stray
//     2 fragment after the casting time - flagged pending
//     the PDF, pinned from the interleave.
//   - the forcecage components, casting time and save
//     cells print after the prose - an interleave; the gap
//     fraction cell garbles (the bands carry half-inch
//     gaps) - flagged pending the PDF.
//   - the mansion name header garbles to a bare possessive
//     fragment; the name pins from the gap item list and
//     the prose. The level cell is lost - the level pins
//     from the section heading; the school is lost pending
//     the PDF. The duration cell loses its head (a bare
//     ion fragment); the portal dimensions print with a
//     degree garble for feet.
//   - the sequester name header is lost entirely - the
//     stat block prints after the mansion prose; the name
//     pins from the gap item list and the prose. The
//     comatose sentences scramble - flagged pending the
//     PDF.
//   - the teleport without error cells print as loose
//     fragments after the prose - pinned from the
//     fragments, the interleave flagged.
//   - the torment range cell garbles (a Ran fragment with
//     a stray asterisk) - a hole pending the PDF; the
//     duration cell displaces its Special above the Saving
//     Throw line. The save ladder ends at round 6 but the
//     print says no penalty following round 8 - flagged as
//     printed. The intelligence tail scrambles - flagged
//     pending the PDF.
//   - the truename components, casting time and save
//     cells print in a scrambled tail shared with volley -
//     the Special and Neg. save fragments cannot be
//     attributed - the save is a hole pending the PDF, not
//     pinned as data. The transport verse list ends at the
//     2,000-mile range - anything beyond is a hole pending
//     the PDF.
//   - the volley Explanation line is lost; its stat tail
//     scrambles into the shared fragments - the
//     components, casting time and save cells are holes
//     pending the PDF, not pinned as data.
// ===========================================================================

namespace rules {

// ---- banishment (Abjuration - Evocation) ----
inline const char* uam7BanName()
    { return "Banishment (Abjuration - Evocation)"; }

inline int uam7BanLevel()
    { return 7; }

// The stat head scrambles - the components print as a
// garbled V, S, segments M line above a bare Components
// cell; flagged pending the PDF.
inline bool uam7BanStatHeadScrambled()
    { return true; }

inline bool uam7BanComponentsVSM()
    { return true; }

// The range prints as a stray 2 fragment after the casting
// time - pinned from the interleave, flagged pending the
// PDF.
inline int uam7BanRangeInches()
    { return 2; }

inline bool uam7BanRangeCellInterleaved()
    { return true; }

// The digit-garble family decodes the 7-segment casting
// time as 1.
inline int uam7BanCastingTimeSegments()
    { return 1; }

inline bool uam7BanSaveSpecial()
    { return true; }

inline bool uam7BanDurationPermanent()
    { return true; }

// The area: 2 levels or hit dice of creatures per level of
// the caster.
inline int uam7BanAoeLevelsPerCasterLevel()
    { return 2; }

// The spell forces a creature from another plane to return
// to its own abode; the effect is instantaneous, and the
// subject cannot come back without special summoning or
// means of egress.
inline bool uam7BanForcesPlanarCreatureHome()
    { return true; }

inline bool uam7BanEffectInstantaneous()
    { return true; }

inline bool uam7BanCannotReturnWithoutSummoning()
    { return true; }

// More than one creature can be forced out, providing the
// caster is of sufficient strength and the subjects are
// within range.
inline bool uam7BanMultipleCreaturesIfStrength()
    { return true; }

// The caster must name the type of creature, give its true
// and proper name, and call upon powers opposed to it.
inline bool uam7BanMustNameTypeAndTrueName()
    { return true; }

inline bool uam7BanCallsOpposedPowers()
    { return true; }

inline bool uam7BanMagicResistanceMustBeDefeated()
    { return true; }

// The materials are substances harmful, hateful, or
// opposed to the subject; each included substance costs
// the subject 2 points on its save versus spell.
inline int uam7BanMaterialSaveAdjPerSubstance()
    { return 2; }

// The four-substance example - iron, holy water, sunstone,
// a sprig of rosemary upon a demon - saves at -8.
inline int uam7BanExampleSubstanceCount()
    { return 4; }

inline int uam7BanExampleSaveAdj()
    { return 8; }

// Special items - ki-rin tail hair, couatl feathers - can
// bring the factor to -3 or -4 per item.
inline int uam7BanSpecialItemAdjMin()
    { return 3; }

inline int uam7BanSpecialItemAdjMax()
    { return 4; }

// In contrast, a devil scale, titan hair, or druid-blessed
// mistletoe might lower the factor to -1 against a demon.
inline int uam7BanContrarySubstanceLowersTo()
    { return 1; }

// A failed save stings the caster with a backlash - 2-12
// points of damage and a 2-12 segment stun.
inline int uam7BanBacklashDamageMin()
    { return 2; }

inline int uam7BanBacklashDamageMax()
    { return 12; }

inline int uam7BanBacklashStunSegmentsMin()
    { return 2; }

inline int uam7BanBacklashStunSegmentsMax()
    { return 12; }

// Powers directly opposed to the subject, or favorably
// concerned with the caster, augment the components by -1
// to -6 - referee judgement.
inline int uam7BanPowerAugmentMin()
    { return 1; }

inline int uam7BanPowerAugmentMax()
    { return 6; }

// ---- forcecage (Evocation) ----
inline const char* uam7ForceName()
    { return "Forcecage (Evocation)"; }

inline int uam7ForceLevel()
    { return 7; }

// The range: 1 inch per 2 levels of the caster.
inline int uam7ForceRangeInchesPerTwoLevels()
    { return 1; }

inline int uam7ForceDurationBaseTurns()
    { return 6; }

inline int uam7ForceDurationTurnsPerLevel()
    { return 1; }

inline int uam7ForceAoeCubeInches()
    { return 2; }

// The components, casting time and save cells print after
// the prose - an interleave.
inline bool uam7ForceStatTailInterleaved()
    { return true; }

inline bool uam7ForceComponentsVSPlusSpecial()
    { return true; }

inline int uam7ForceCastingTimeSegmentsMin()
    { return 3; }

inline int uam7ForceCastingTimeSegmentsMax()
    { return 4; }

inline bool uam7ForceSaveNone()
    { return true; }

// The cage has alternating bands of force with half-inch
// gaps between - the fraction cell garbles; flagged
// pending the PDF.
inline bool uam7ForceHalfInchGaps()
    { return true; }

inline bool uam7ForceGapCellGarbled()
    { return true; }

// Creatures in the area are caught and contained unless
// able to pass through the openings; all spells and breath
// weapons pass through the gaps.
inline bool uam7ForceContainedUnlessPassesOpenings()
    { return true; }

inline bool uam7ForceSpellsAndBreathPassGaps()
    { return true; }

// A creature with magic resistance gets a single attempt to
// pass through; on failure it is caged. All other creatures
// in the area are trapped unless they also have resistance.
inline bool uam7ForceMagicResistanceSingleAttempt()
    { return true; }

inline bool uam7ForceOthersTrappedUnlessResistant()
    { return true; }

// Unlike a cube of force, the forcecage is removed only by
// a dispel magic or by expiration.
inline bool uam7ForceRemovedByDispelMagic()
    { return true; }

// Special preparation at memorization alters the spell to a
// forcecube - one-eighth the area, a cube 1 inch on a side,
// resembling a cube of force.
inline bool uam7ForcecubeVariant()
    { return true; }

inline int uam7ForcecubeAreaFactor()
    { return 8; }

inline int uam7ForcecubeAoeCubeInches()
    { return 1; }

inline bool uam7ForcecubeResemblesCubeOfForce()
    { return true; }

// The casting requires no material component, but the
// study demands powdering a diamond of at least 1,000 gp
// value to trace the outlines.
inline bool uam7ForceNoMaterialOnCasting()
    { return true; }

inline int uam7ForceDiamondDustGpMin()
    { return 1000; }

// The dust sentence scrambles at the section tail -
// flagged pending the PDF.
inline bool uam7ForceDiamondDustTailScrambled()
    { return true; }

// ---- the Mordenkainen magnificent mansion ----
// The name header garbles to a bare possessive fragment;
// the name pins from the gap item list and the prose. The
// school is lost pending the PDF.
inline const char* uam7MansionName()
    { return "Mordenkainen's Magnificent Mansion"; }

inline bool uam7MansionNameHeaderGarbled()
    { return true; }

inline bool uam7MansionSchoolLost()
    { return true; }

// The level cell is lost - the level pins from the section
// heading.
inline bool uam7MansionLevelCellLost()
    { return true; }

inline int uam7MansionLevel()
    { return 7; }

inline bool uam7MansionComponentsVSM()
    { return true; }

// The digit-garble family decodes the 7-round casting time
// as 1 round.
inline int uam7MansionCastingTimeRounds()
    { return 1; }

inline bool uam7MansionSaveNone()
    { return true; }

// The duration cell loses its head - a bare ion fragment
// before the 1 hour per level; flagged pending the PDF.
inline int uam7MansionDurationHoursPerLevel()
    { return 1; }

inline bool uam7MansionDurationCellTailGarbled()
    { return true; }

inline int uam7MansionAoeSqFtPerLevel()
    { return 300; }

// The spell conjures an extra-dimensional dwelling entered
// only at a single point on the casting plane.
inline bool uam7MansionExtraDimensionalDwelling()
    { return true; }

inline bool uam7MansionSingleEntryPoint()
    { return true; }

// Observers see a faint shimmering - an area 4 feet wide
// and 8 feet high; the dimension cells print with a
// degree garble for feet.
inline int uam7MansionPortalFeetWide()
    { return 4; }

inline int uam7MansionPortalFeetHigh()
    { return 8; }

inline bool uam7MansionPortalDegreeGarble()
    { return true; }

// The caster controls entry; the portal shuts and turns
// invisible behind him, reopenable from his own side.
inline bool uam7MansionCasterControlsEntry()
    { return true; }

inline bool uam7MansionPortalInvisibleBehindCaster()
    { return true; }

// The place holds a nine-course banquet for as many dozens
// of people as the caster has levels, served by a staff of
// near-transparent servants.
inline int uam7MansionBanquetCourses()
    { return 9; }

inline bool uam7MansionDozensPerCasterLevel()
    { return true; }

inline bool uam7MansionServantStaff()
    { return true; }

inline bool uam7MansionAtmosphereCleanFreshWarm()
    { return true; }

// Outside conditions do not affect the mansion, nor do
// inside conditions pass beyond.
inline bool uam7MansionOutsideConditionsExcluded()
    { return true; }

// The food is not real nourishment - it seems filling only
// inside; outside, ravenous hunger strikes unless normal
// food was eaten.
inline bool uam7MansionFoodNotRealNourishment()
    { return true; }

// Each imaginary meal costs 1 hour of eating normal fare;
// failure loses 1 strength point per meal, restorable only
// within 6 hours or the loss is permanent.
inline int uam7MansionRecoveryHoursPerImaginaryMeal()
    { return 1; }

inline bool uam7MansionStrengthLossPerMeal()
    { return true; }

inline int uam7MansionLossPermanentAfterHours()
    { return 6; }

// The materials: a miniature portal carved from ivory, a
// piece of polished marble, and a tiny silver spoon -
// utterly destroyed by the casting.
inline bool uam7MansionMaterialIvoryPortal()
    { return true; }

inline bool uam7MansionMaterialPolishedMarble()
    { return true; }

inline bool uam7MansionMaterialSilverSpoon()
    { return true; }

inline bool uam7MansionMaterialsDestroyed()
    { return true; }

// The spell has been used with a normal portal and with
// illusion magic; the design can be altered to suit the
// caster.
inline bool uam7MansionDesignAlterable()
    { return true; }

// ---- sequester ----
// The name header is lost entirely - the stat block
// prints after the mansion prose; the name pins from the
// gap item list and the prose. The school is lost pending
// the PDF.
inline const char* uam7SequesterName()
    { return "Sequester"; }

inline bool uam7SequesterNameHeaderLost()
    { return true; }

inline bool uam7SequesterSchoolLost()
    { return true; }

inline bool uam7SequesterComponentsVSM()
    { return true; }

inline int uam7SequesterLevel()
    { return 7; }

inline bool uam7SequesterRangeTouch()
    { return true; }

// The digit-garble family decodes the 7-round casting time
// as 1 round.
inline int uam7SequesterCastingTimeRounds()
    { return 1; }

inline bool uam7SequesterSaveSpecial()
    { return true; }

inline int uam7SequesterDurationBaseWeeks()
    { return 1; }

inline int uam7SequesterDurationDaysPerLevel()
    { return 1; }

// The area: a 2-foot cube per level of the caster.
inline int uam7SequesterAoeCubeFeetPerLevel()
    { return 2; }

// The spell blocks detection and location spells and
// renders the subject invisible to any form of sight.
inline bool uam7SequesterBlocksDetectionAndLocation()
    { return true; }

inline bool uam7SequesterInvisibleToAllSight()
    { return true; }

// It masks a secret door or treasure vault but is not
// proof from tactile discovery, a robe of eyes, or a gem
// of seeing.
inline bool uam7SequesterNotProofFromTactileOrDevices()
    { return true; }

// A creature not desiring to be affected gets a saving
// throw; an affected creature is kept comatose until the
// spell wears off or is dispelled.
inline bool uam7SequesterUnwillingCreatureSave()
    { return true; }

inline bool uam7SequesterComatoseUntilWearsOff()
    { return true; }

// The comatose sentences scramble in the print - flagged
// pending the PDF.
inline bool uam7SequesterProseScrambled()
    { return true; }

// The materials: a basilisk eyelash, gum arabic, and a
// dram of whitewash.
inline bool uam7SequesterMaterialBasiliskEyelash()
    { return true; }

inline bool uam7SequesterMaterialGumArabic()
    { return true; }

inline bool uam7SequesterMaterialWhitewashDram()
    { return true; }

// ---- teleport without error (Alteration) ----
inline const char* uam7TeleportName()
    { return "Teleport Without Error (Alteration)"; }

inline int uam7TeleportLevel()
    { return 7; }

inline bool uam7TeleportRangeTouch()
    { return true; }

inline bool uam7TeleportDurationInstantaneous()
    { return true; }

inline bool uam7TeleportAoeSpecial()
    { return true; }

// The cells print as loose fragments after the prose -
// pinned from the fragments, the interleave flagged.
inline bool uam7TeleportStatCellsScrambled()
    { return true; }

inline bool uam7TeleportComponentsV()
    { return true; }

inline int uam7TeleportCastingTimeSegments()
    { return 1; }

inline bool uam7TeleportSaveNone()
    { return true; }

// The caster transports himself plus the teleport-noted
// weight to any known location on his home plane with no
// chance for error.
inline bool uam7TeleportHomePlaneNoError()
    { return true; }

inline bool uam7TeleportWeightAsTeleport()
    { return true; }

// Other planes are possible at a studied-carefully best -
// the caster must have been there and perused the area;
// the teleport table governs off-plane travel.
inline bool uam7TeleportOtherPlanesStudiedCarefully()
    { return true; }

inline bool uam7TeleportUsesTeleportTableOffPlane()
    { return true; }

// Exception: the 9th-level succor spell, described
// hereafter.
inline bool uam7TeleportSuccorException()
    { return true; }

// The caster can do nothing else in the round he appears.
inline bool uam7TeleportNothingElseThatRound()
    { return true; }

// ---- torment (Evocation - Alteration) ----
inline const char* uam7TormentName()
    { return "Torment (Evocation - Alteration)"; }

inline bool uam7TormentComponentsVSM()
    { return true; }

inline int uam7TormentLevel()
    { return 7; }

// The range cell garbles - a Ran fragment with a stray
// asterisk; a hole pending the PDF.
inline bool uam7TormentRangeCellLost()
    { return true; }

// The digit-garble family decodes the 7-round casting time
// as 1 round.
inline int uam7TormentCastingTimeRounds()
    { return 1; }

inline bool uam7TormentSaveSpecial()
    { return true; }

// The duration cell displaces its Special above the
// Saving Throw line; flagged as printed.
inline bool uam7TormentDurationSpecial()
    { return true; }

inline bool uam7TormentDurationCellDisplaced()
    { return true; }

inline bool uam7TormentAoeOneCreature()
    { return true; }

// The spell forces submission and obedience from a captive
// creature of another plane (cf. dolor and ensnarement).
inline bool uam7TormentForcesSubmissionForService()
    { return true; }

inline bool uam7TormentCfDolorAndEnsnarement()
    { return true; }

// The initial uttering links the caster to the captive
// bound in a magic circle, thaumaturgic triangle, or
// pentagram; the victim must fail any magic resistance
// check.
inline bool uam7TormentLinkToCaptiveInCircle()
    { return true; }

inline bool uam7TormentMagicResistanceMustFail()
    { return true; }

// The caster reads the specially prepared writing; each
// round the captive feels worse - twinges the first two
// rounds, shooting pains the third and fourth, aches and
// cramps the fifth and sixth.
inline bool uam7TormentReadingRoundsLadder()
    { return true; }

inline int uam7TormentTwingesRounds()
    { return 2; }

inline int uam7TormentShootingPainsStartRound()
    { return 3; }

inline int uam7TormentAchesCrampsStartRound()
    { return 5; }

// The refusing creature saves versus spell, adjusted per
// round: -1, -2, -3, -4, then -6 and -8.
inline int uam7TormentSaveAdjR1()
    { return -1; }

inline int uam7TormentSaveAdjR2()
    { return -2; }

inline int uam7TormentSaveAdjR3()
    { return -3; }

inline int uam7TormentSaveAdjR4()
    { return -4; }

inline int uam7TormentSaveAdjR5()
    { return -6; }

inline int uam7TormentSaveAdjR6()
    { return -8; }

// A failed save means the creature has agreed to the
// demands.
inline bool uam7TormentFailingSaveMeansAgreement()
    { return true; }

// The print says no penalty follows round 8, though the
// ladder ends at round 6 - flagged as printed.
inline int uam7TormentNoPenaltyAfterRound()
    { return 8; }

inline bool uam7TormentRoundEightWordingFlagged()
    { return true; }

// If it breaks loose: -1 initiative per 2 rounds in
// effect, to a maximum -4 on round 8.
inline int uam7TormentInitiativePenaltyPerTwoRounds()
    { return 1; }

inline int uam7TormentInitiativePenaltyMax()
    { return 4; }

inline int uam7TormentInitiativeMaxAtRound()
    { return 8; }

// To hit and damage per die: -1 after round 3, growing -1
// per round to -4 in round 6, then decreasing to -1 in
// round 9.
inline int uam7TormentHitDamagePenaltyAfterRound()
    { return 3; }

inline int uam7TormentHitDamagePenaltyMin()
    { return 1; }

inline int uam7TormentHitDamagePenaltyMax()
    { return 4; }

inline int uam7TormentHitDamageMaxAtRound()
    { return 6; }

inline int uam7TormentHitDamageMinAgainAtRound()
    { return 9; }

// An intelligent creature with low moral standards submits
// once it realizes the nature of the spell; the service is
// carried out to the letter, but revenge is certain to be
// sought.
inline bool uam7TormentIntelligentSubmits()
    { return true; }

inline bool uam7TormentServiceToTheLetter()
    { return true; }

inline bool uam7TormentRevengeSought()
    { return true; }

// Preparation requires the secret name for the creature
// type or its given name inscribed in the incantation, and
// the caster must identify himself in the text.
inline bool uam7TormentRequiresNameInscribed()
    { return true; }

inline bool uam7TormentCasterSelfIdentification()
    { return true; }

// The intelligence tail scrambles - flagged pending the
// PDF, not pinned as data.
inline bool uam7TormentIntelligenceClauseScrambled()
    { return true; }

// ---- truename (Enchantment/Alteration) ----
inline const char* uam7TruenameName()
    { return "Truename (Enchantment/Alteration)"; }

inline int uam7TruenameLevel()
    { return 7; }

inline int uam7TruenameRangeInches()
    { return 3; }

inline bool uam7TruenameDurationSpecial()
    { return true; }

inline bool uam7TruenameAoeThingNamed()
    { return true; }

// The components, casting time and save cells print in a
// scrambled tail shared with volley - the Special and Neg.
// save fragments cannot be attributed; the save is a hole
// pending the PDF.
inline bool uam7TruenameStatTailInterleaved()
    { return true; }

inline bool uam7TruenameComponentsVSM()
    { return true; }

// The digit-garble family decodes the 7-segment fragment
// as 1.
inline int uam7TruenameCastingTimeSegments()
    { return 1; }

inline bool uam7TruenameSaveCellLost()
    { return true; }

// The spell gives power over any living thing whose name,
// generic or individual, is known; true names come only
// through hard work, spying, legend lore, and sagecraft.
inline bool uam7TruenameTrueNamesHardToLearn()
    { return true; }

// The casting calls out the true name, then a verse
// recital of the nature or history of the subject - 3
// segments.
inline int uam7TruenameRecitationSegments()
    { return 3; }

// Multiple suggestion: 1 to 4 suggestions, each recited in
// 1 segment as a suggestion spell; the scrambled fragment
// limits the total to 4.
inline int uam7TruenameSuggestionMin()
    { return 1; }

inline int uam7TruenameSuggestionMax()
    { return 4; }

inline int uam7TruenameSuggestionSecondsPerEach()
    { return 1; }

inline bool uam7TruenameSuggestionAsSuggestionSpell()
    { return true; }

// Weakness and surrender: 1 strength point per segment of
// recitation - -1 to hit and damage, -1 movement - and each
// point lost forces a save versus paralyzation or meek
// surrender.
inline int uam7TruenameWeaknessPerSegment()
    { return 1; }

inline bool uam7TruenameWeaknessSaveParalyzation()
    { return true; }

// Strength is recovered in 2-8 rounds after the recitation
// ceases, and with it the will to resist.
inline int uam7TruenameStrengthRecoveryRoundsMin()
    { return 2; }

inline int uam7TruenameStrengthRecoveryRoundsMax()
    { return 8; }

// Polymorph: as a polymorph any object, with no system
// shock save; the verse ladder by radicality, the reverse
// cases hold, and unstated cases use the closest stated
// one.
inline bool uam7TruenamePolymorphAsAnyObject()
    { return true; }

inline bool uam7TruenamePolymorphNoSystemShock()
    { return true; }

inline int uam7TruenamePolyVersesMineralToAnimal()
    { return 10; }

inline int uam7TruenamePolyVersesMineralToVegetable()
    { return 9; }

inline int uam7TruenamePolyVersesVegetableToAnimal()
    { return 8; }

inline int uam7TruenamePolyVersesMonsterToNormal()
    { return 7; }

inline int uam7TruenamePolyVersesMonsterToMonster()
    { return 6; }

inline int uam7TruenamePolyVersesOtherToHuman()
    { return 5; }

inline int uam7TruenamePolyVersesAnimalToAnimal()
    { return 4; }

inline int uam7TruenamePolyVersesVegetableToVegetable()
    { return 3; }

inline int uam7TruenamePolyVersesMineralToMineral()
    { return 2; }

inline bool uam7TruenamePolyReverseHolds()
    { return true; }

inline bool uam7TruenamePolyDmClosestCase()
    { return true; }

// The subject returns to natural form in 6 turns per level
// minus 1 turn per verse required, thinking and behaving
// as the new type but keeping its original hit points.
inline int uam7TruenamePolyDurationTurnsPerLevel()
    { return 6; }

inline int uam7TruenamePolyTurnsOffPerVerse()
    { return 1; }

inline bool uam7TruenamePolyKeepsOriginalHp()
    { return true; }

// Transport: the subject is teleported without error or
// otherwise moved - 4 verses per 100 miles, 5 per 500, 6
// per 2,000 on the same plane; the printed list ends there,
// a hole pending the PDF.
inline bool uam7TruenameTransportTeleportsWithoutError()
    { return true; }

inline int uam7TruenameTransportVerses100Miles()
    { return 4; }

inline int uam7TruenameTransportVerses500Miles()
    { return 5; }

inline int uam7TruenameTransportVerses2000Miles()
    { return 6; }

inline bool uam7TruenameTransportListTruncated()
    { return true; }

// ---- volley (Abjuration) ----
inline const char* uam7VolleyName()
    { return "Volley (Abjuration)"; }

inline int uam7VolleyLevel()
    { return 7; }

inline bool uam7VolleyRangeSpecial()
    { return true; }

inline bool uam7VolleyDurationSpecial()
    { return true; }

inline bool uam7VolleyAoeSpecial()
    { return true; }

// The Explanation line is lost; the components, casting
// time and save cells scramble into the shared tail -
// holes pending the PDF, not pinned as data.
inline bool uam7VolleyExplanationLineLost()
    { return true; }

inline bool uam7VolleyStatTailScrambled()
    { return true; }

inline bool uam7VolleyComponentsCellLost()
    { return true; }

inline bool uam7VolleyCastingTimeCellLost()
    { return true; }

inline bool uam7VolleySaveCellLost()
    { return true; }

// The volley turns a casting back upon its sender; the
// range, duration, area and save depend on the
// circumstances and the spell being volleyed.
inline bool uam7VolleyTurnsCastingBackOnSender()
    { return true; }

inline bool uam7VolleyStatsDependOnCircumstance()
    { return true; }

// The power word kill example: the volley bounces the
// spell to its caster, who saves versus spell or suffers
// his own magic; a save returns it to the target, and the
// exchanges continue until one side fails or the spell
// dissipates.
inline bool uam7VolleyPowerWordKillExample()
    { return true; }

inline bool uam7VolleyBounceRequiresSaveVsSpell()
    { return true; }

inline bool uam7VolleySentBackUntilSaveFails()
    { return true; }

// Each volley, not the original casting, counts as half a
// single exchange; a 1st-level spell dissipates after the
// first volley and return, a 2nd-level spell goes through
// four volley portions - two complete exchanges.
inline bool uam7VolleyCountsHalfExchangePerVolley()
    { return true; }

inline bool uam7VolleyFirstLevelDissipatesExample()
    { return true; }

inline bool uam7VolleySecondLevelFourPortions()
    { return true; }

// The willow-wood and 10-feet fragments scramble at the
// tail - flagged pending the PDF.
inline bool uam7VolleyProseTailScrambled()
    { return true; }

// The material: a bit of willow or other flexible wood,
// crisscrossed with specially prepared bent strands of
// gut.
inline bool uam7VolleyMaterialWillowWood()
    { return true; }

inline bool uam7VolleyMaterialGutStrands()
    { return true; }

// The volley and truename sections print after the
// 8th-level spell-table page - a misbinding.
inline bool uam7VolleyPrintsPastEighthTablePage()
    { return true; }

}   // namespace rules
"""
    clean(HDR, 78)
    wr(US, HDR + NL)
    applied.append('uamuspells7.h: the pins')
s = rd(US)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 223, 'b inline count'
assert s.count('R361') == 1, 'b round tag'
assert s.count('uam7BanName()') == 1, 'b ban fn'
assert s.count(
    'uam7VolleyMaterialGutStrands()'
    ) == 1, 'b volley fn'
assert 'uam6' not in s, 'b no r360 ref'
assert 'uam5' not in s, 'b no r360-5 ref'
assert 'uam4' not in s, 'b no r359 ref'
assert 'uam3' not in s, 'b no r358 ref'
assert 'uam2' not in s, 'b no r357 ref'
assert 'uam1' not in s, 'b no r356 ref'
assert 'uac1' not in s, 'b no r343 ref'
assert 'uad3' not in s, 'b no druid ref'
assert 'uas2' not in s, 'b no r342 ref'
assert 'uast' not in s, 'b no r341 ref'
assert len(applied) + len(already) == 2, 'b count'


# ---- (c) the gap report: the note (the
# item STAYS OPEN - the 8th-9th levels) ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'R361: the 7th level pinned' in s:
    already.append('gap report: the note')
else:
    TAIL_OLD = NL.join([
        '        wholly lost; the 7th through',
        '        9th levels stay open.',
        '- [ ] **The new illusionist spells**',
    ])
    assert s.count(TAIL_OLD) == 1, 'c tail'
    NOTE = NL.join([
    '      - R361: the 7th level pinned',
    '        (rules/uamuspells7.h) - the',
    '        eight spell descriptions',
    '        (banishment with the',
    '        scrambled stat head and',
    '        the range interleaved,',
    '        forcecage with the stat',
    '        tail interleaved and the',
    '        gap fraction garbled, the',
    '        Mordenkainen magnificent',
    '        mansion behind the garbled',
    '        name header with the level',
    '        cell lost, sequester behind',
    '        the lost name header,',
    '        teleport without error with',
    '        the stat cells scrambled,',
    '        torment with the range cell',
    '        lost and the save ladder',
    '        pinned, truename with the',
    '        stat tail interleaved and',
    '        the save fragment',
    '        unattributed, volley with',
    '        the Explanation line lost',
    '        and the stat cells holes,',
    '        the volley and truename',
    '        sections printing past the',
    '        8th-level table page); the',
    '        family decodes the casting',
    '        and duration 7s as 1; the',
    '        R342 MU table seam prints',
    '        only the seven PHB',
    '        fragments, none of the new',
    '        names seam-checks; the 8th',
    '        and 9th levels stay open.',
    ])
    clean(NOTE, 57)
    s = s.replace(TAIL_OLD, NL.join([
        '        wholly lost; the 7th through',
        '        9th levels stay open.',
        NOTE,
        '- [ ] **The new illusionist spells**',
    ]))
    wr(GP, s)
    applied.append('gap report: the note')
s = rd(GP)
assert s.count('R361: the 7th level pinned') == 1, 'c note'
assert s.count(
    'R360: the 5th and 6th levels'
    ) == 1, 'c r360 kept'
assert s.count(
    '- [ ] **The new magic-user spells**'
    ) == 1, 'c stays open'
assert s.count(
    '- [x] **The new druid spells**'
    ) == 1, 'c druid closed kept'
assert s.count(
    '- [ ] **The new illusionist spells**'
    ) == 1, 'c illusionist kept'
assert len(applied) + len(already) == 3, 'c count'


# ---- (d) regtest.cpp: the include, the
# audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R361 UA MU 7th level spells pin audit' in s:
    already.append('regtest.cpp: the R361 audit')
else:
    INC_ANCH = (
        '#include "rules/uamuspells6.h"'
        '  // R360: the UA new magic-user'
        ' 6th level')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uamuspells7.h"'
        '  // R361: the UA new magic-user'
        ' 7th level',
    ])
    AUD_ANCH = (
        '    // ---- R227: the wis mental save'
        ' wiring audit ----')
    AUDIT = r"""    // ---- R361: the UA new magic-user 7th level
    // spells pin audit ----
    // The UA NEW MAGIC-USER SPELLS (pp.
    // 66-71), the 7th level - banishment
    // behind the scrambled stat head,
    // forcecage with the stat tail
    // interleaved, the Mordenkainen
    // magnificent mansion behind the
    // garbled name header, sequester
    // behind the lost name header,
    // teleport without error with the
    // stat cells scrambled, torment
    // with the range cell lost,
    // truename with the save fragment
    // unattributed, volley with the
    // Explanation line lost; the
    // volley and truename sections
    // print past the 8th-level table
    // page. The family decodes the
    // casting and duration 7s as 1.
    // The R342 table seam prints
    // only PHB fragments - none of
    // the new names seam-checks. The
    // item stays open (the 8th-9th
    // levels).
    {
        using namespace rules;
        int bad = 0;
        // U1: banishment
            if (strcmp(uam7BanName(),
                "Banishment (Abjuration - Evocation)") != 0) ++bad;
            if (uam7BanLevel() != 7) ++bad;
            if (!uam7BanStatHeadScrambled()) ++bad;
            if (!uam7BanComponentsVSM()) ++bad;
            if (uam7BanRangeInches() != 2) ++bad;
            if (!uam7BanRangeCellInterleaved()) ++bad;
            if (uam7BanCastingTimeSegments() != 1) ++bad;
            if (!uam7BanSaveSpecial()) ++bad;
            if (!uam7BanDurationPermanent()) ++bad;
            if (uam7BanAoeLevelsPerCasterLevel() != 2) ++bad;
            if (!uam7BanForcesPlanarCreatureHome()) ++bad;
            if (!uam7BanEffectInstantaneous()) ++bad;
            if (!uam7BanCannotReturnWithoutSummoning()) ++bad;
            if (!uam7BanMultipleCreaturesIfStrength()) ++bad;
            if (!uam7BanMustNameTypeAndTrueName()) ++bad;
            if (!uam7BanCallsOpposedPowers()) ++bad;
            if (!uam7BanMagicResistanceMustBeDefeated()) ++bad;
            if (uam7BanMaterialSaveAdjPerSubstance() != 2) ++bad;
            if (uam7BanExampleSubstanceCount() != 4) ++bad;
            if (uam7BanExampleSaveAdj() != 8) ++bad;
            if (uam7BanSpecialItemAdjMin() != 3) ++bad;
            if (uam7BanSpecialItemAdjMax() != 4) ++bad;
            if (uam7BanContrarySubstanceLowersTo() != 1) ++bad;
            if (uam7BanBacklashDamageMin() != 2) ++bad;
            if (uam7BanBacklashDamageMax() != 12) ++bad;
            if (uam7BanBacklashStunSegmentsMin() != 2) ++bad;
            if (uam7BanBacklashStunSegmentsMax() != 12) ++bad;
            if (uam7BanPowerAugmentMin() != 1) ++bad;
            if (uam7BanPowerAugmentMax() != 6) ++bad;

        // U2: forcecage
            if (strcmp(uam7ForceName(),
                "Forcecage (Evocation)") != 0) ++bad;
            if (uam7ForceLevel() != 7) ++bad;
            if (uam7ForceRangeInchesPerTwoLevels() != 1) ++bad;
            if (uam7ForceDurationBaseTurns() != 6) ++bad;
            if (uam7ForceDurationTurnsPerLevel() != 1) ++bad;
            if (uam7ForceAoeCubeInches() != 2) ++bad;
            if (!uam7ForceStatTailInterleaved()) ++bad;
            if (!uam7ForceComponentsVSPlusSpecial()) ++bad;
            if (uam7ForceCastingTimeSegmentsMin() != 3) ++bad;
            if (uam7ForceCastingTimeSegmentsMax() != 4) ++bad;
            if (!uam7ForceSaveNone()) ++bad;
            if (!uam7ForceHalfInchGaps()) ++bad;
            if (!uam7ForceGapCellGarbled()) ++bad;
            if (!uam7ForceContainedUnlessPassesOpenings()) ++bad;
            if (!uam7ForceSpellsAndBreathPassGaps()) ++bad;
            if (!uam7ForceMagicResistanceSingleAttempt()) ++bad;
            if (!uam7ForceOthersTrappedUnlessResistant()) ++bad;
            if (!uam7ForceRemovedByDispelMagic()) ++bad;
            if (!uam7ForcecubeVariant()) ++bad;
            if (uam7ForcecubeAreaFactor() != 8) ++bad;
            if (uam7ForcecubeAoeCubeInches() != 1) ++bad;
            if (!uam7ForcecubeResemblesCubeOfForce()) ++bad;
            if (!uam7ForceNoMaterialOnCasting()) ++bad;
            if (uam7ForceDiamondDustGpMin() != 1000) ++bad;
            if (!uam7ForceDiamondDustTailScrambled()) ++bad;

        // U3: the Mordenkainen magnificent mansion
            if (strcmp(uam7MansionName(),
                "Mordenkainen's Magnificent Mansion") != 0) ++bad;
            if (!uam7MansionNameHeaderGarbled()) ++bad;
            if (!uam7MansionSchoolLost()) ++bad;
            if (!uam7MansionLevelCellLost()) ++bad;
            if (uam7MansionLevel() != 7) ++bad;
            if (!uam7MansionComponentsVSM()) ++bad;
            if (uam7MansionCastingTimeRounds() != 1) ++bad;
            if (!uam7MansionSaveNone()) ++bad;
            if (uam7MansionDurationHoursPerLevel() != 1) ++bad;
            if (!uam7MansionDurationCellTailGarbled()) ++bad;
            if (uam7MansionAoeSqFtPerLevel() != 300) ++bad;
            if (!uam7MansionExtraDimensionalDwelling()) ++bad;
            if (!uam7MansionSingleEntryPoint()) ++bad;
            if (uam7MansionPortalFeetWide() != 4) ++bad;
            if (uam7MansionPortalFeetHigh() != 8) ++bad;
            if (!uam7MansionPortalDegreeGarble()) ++bad;
            if (!uam7MansionCasterControlsEntry()) ++bad;
            if (!uam7MansionPortalInvisibleBehindCaster()) ++bad;
            if (uam7MansionBanquetCourses() != 9) ++bad;
            if (!uam7MansionDozensPerCasterLevel()) ++bad;
            if (!uam7MansionServantStaff()) ++bad;
            if (!uam7MansionAtmosphereCleanFreshWarm()) ++bad;
            if (!uam7MansionOutsideConditionsExcluded()) ++bad;
            if (!uam7MansionFoodNotRealNourishment()) ++bad;
            if (uam7MansionRecoveryHoursPerImaginaryMeal() != 1) ++bad;
            if (!uam7MansionStrengthLossPerMeal()) ++bad;
            if (uam7MansionLossPermanentAfterHours() != 6) ++bad;
            if (!uam7MansionMaterialIvoryPortal()) ++bad;
            if (!uam7MansionMaterialPolishedMarble()) ++bad;
            if (!uam7MansionMaterialSilverSpoon()) ++bad;
            if (!uam7MansionMaterialsDestroyed()) ++bad;
            if (!uam7MansionDesignAlterable()) ++bad;

        // U4: sequester
            if (strcmp(uam7SequesterName(),
                "Sequester") != 0) ++bad;
            if (!uam7SequesterNameHeaderLost()) ++bad;
            if (!uam7SequesterSchoolLost()) ++bad;
            if (!uam7SequesterComponentsVSM()) ++bad;
            if (uam7SequesterLevel() != 7) ++bad;
            if (!uam7SequesterRangeTouch()) ++bad;
            if (uam7SequesterCastingTimeRounds() != 1) ++bad;
            if (!uam7SequesterSaveSpecial()) ++bad;
            if (uam7SequesterDurationBaseWeeks() != 1) ++bad;
            if (uam7SequesterDurationDaysPerLevel() != 1) ++bad;
            if (uam7SequesterAoeCubeFeetPerLevel() != 2) ++bad;
            if (!uam7SequesterBlocksDetectionAndLocation()) ++bad;
            if (!uam7SequesterInvisibleToAllSight()) ++bad;
            if (!uam7SequesterNotProofFromTactileOrDevices()) ++bad;
            if (!uam7SequesterUnwillingCreatureSave()) ++bad;
            if (!uam7SequesterComatoseUntilWearsOff()) ++bad;
            if (!uam7SequesterProseScrambled()) ++bad;
            if (!uam7SequesterMaterialBasiliskEyelash()) ++bad;
            if (!uam7SequesterMaterialGumArabic()) ++bad;
            if (!uam7SequesterMaterialWhitewashDram()) ++bad;

        // U5: teleport without error
            if (strcmp(uam7TeleportName(),
                "Teleport Without Error (Alteration)") != 0) ++bad;
            if (uam7TeleportLevel() != 7) ++bad;
            if (!uam7TeleportRangeTouch()) ++bad;
            if (!uam7TeleportDurationInstantaneous()) ++bad;
            if (!uam7TeleportAoeSpecial()) ++bad;
            if (!uam7TeleportStatCellsScrambled()) ++bad;
            if (!uam7TeleportComponentsV()) ++bad;
            if (uam7TeleportCastingTimeSegments() != 1) ++bad;
            if (!uam7TeleportSaveNone()) ++bad;
            if (!uam7TeleportHomePlaneNoError()) ++bad;
            if (!uam7TeleportWeightAsTeleport()) ++bad;
            if (!uam7TeleportOtherPlanesStudiedCarefully()) ++bad;
            if (!uam7TeleportUsesTeleportTableOffPlane()) ++bad;
            if (!uam7TeleportSuccorException()) ++bad;
            if (!uam7TeleportNothingElseThatRound()) ++bad;

        // U6: torment
            if (strcmp(uam7TormentName(),
                "Torment (Evocation - Alteration)") != 0) ++bad;
            if (!uam7TormentComponentsVSM()) ++bad;
            if (uam7TormentLevel() != 7) ++bad;
            if (!uam7TormentRangeCellLost()) ++bad;
            if (uam7TormentCastingTimeRounds() != 1) ++bad;
            if (!uam7TormentSaveSpecial()) ++bad;
            if (!uam7TormentDurationSpecial()) ++bad;
            if (!uam7TormentDurationCellDisplaced()) ++bad;
            if (!uam7TormentAoeOneCreature()) ++bad;
            if (!uam7TormentForcesSubmissionForService()) ++bad;
            if (!uam7TormentCfDolorAndEnsnarement()) ++bad;
            if (!uam7TormentLinkToCaptiveInCircle()) ++bad;
            if (!uam7TormentMagicResistanceMustFail()) ++bad;
            if (!uam7TormentReadingRoundsLadder()) ++bad;
            if (uam7TormentTwingesRounds() != 2) ++bad;
            if (uam7TormentShootingPainsStartRound() != 3) ++bad;
            if (uam7TormentAchesCrampsStartRound() != 5) ++bad;
            if (uam7TormentSaveAdjR1() != -1) ++bad;
            if (uam7TormentSaveAdjR2() != -2) ++bad;
            if (uam7TormentSaveAdjR3() != -3) ++bad;
            if (uam7TormentSaveAdjR4() != -4) ++bad;
            if (uam7TormentSaveAdjR5() != -6) ++bad;
            if (uam7TormentSaveAdjR6() != -8) ++bad;
            if (!uam7TormentFailingSaveMeansAgreement()) ++bad;
            if (uam7TormentNoPenaltyAfterRound() != 8) ++bad;
            if (!uam7TormentRoundEightWordingFlagged()) ++bad;
            if (uam7TormentInitiativePenaltyPerTwoRounds() != 1) ++bad;
            if (uam7TormentInitiativePenaltyMax() != 4) ++bad;
            if (uam7TormentInitiativeMaxAtRound() != 8) ++bad;
            if (uam7TormentHitDamagePenaltyAfterRound() != 3) ++bad;
            if (uam7TormentHitDamagePenaltyMin() != 1) ++bad;
            if (uam7TormentHitDamagePenaltyMax() != 4) ++bad;
            if (uam7TormentHitDamageMaxAtRound() != 6) ++bad;
            if (uam7TormentHitDamageMinAgainAtRound() != 9) ++bad;
            if (!uam7TormentIntelligentSubmits()) ++bad;
            if (!uam7TormentServiceToTheLetter()) ++bad;
            if (!uam7TormentRevengeSought()) ++bad;
            if (!uam7TormentRequiresNameInscribed()) ++bad;
            if (!uam7TormentCasterSelfIdentification()) ++bad;
            if (!uam7TormentIntelligenceClauseScrambled()) ++bad;

        // U7: truename
            if (strcmp(uam7TruenameName(),
                "Truename (Enchantment/Alteration)") != 0) ++bad;
            if (uam7TruenameLevel() != 7) ++bad;
            if (uam7TruenameRangeInches() != 3) ++bad;
            if (!uam7TruenameDurationSpecial()) ++bad;
            if (!uam7TruenameAoeThingNamed()) ++bad;
            if (!uam7TruenameStatTailInterleaved()) ++bad;
            if (!uam7TruenameComponentsVSM()) ++bad;
            if (uam7TruenameCastingTimeSegments() != 1) ++bad;
            if (!uam7TruenameSaveCellLost()) ++bad;
            if (!uam7TruenameTrueNamesHardToLearn()) ++bad;
            if (uam7TruenameRecitationSegments() != 3) ++bad;
            if (uam7TruenameSuggestionMin() != 1) ++bad;
            if (uam7TruenameSuggestionMax() != 4) ++bad;
            if (uam7TruenameSuggestionSecondsPerEach() != 1) ++bad;
            if (!uam7TruenameSuggestionAsSuggestionSpell()) ++bad;
            if (uam7TruenameWeaknessPerSegment() != 1) ++bad;
            if (!uam7TruenameWeaknessSaveParalyzation()) ++bad;
            if (uam7TruenameStrengthRecoveryRoundsMin() != 2) ++bad;
            if (uam7TruenameStrengthRecoveryRoundsMax() != 8) ++bad;
            if (!uam7TruenamePolymorphAsAnyObject()) ++bad;
            if (!uam7TruenamePolymorphNoSystemShock()) ++bad;
            if (uam7TruenamePolyVersesMineralToAnimal() != 10) ++bad;
            if (uam7TruenamePolyVersesMineralToVegetable() != 9) ++bad;
            if (uam7TruenamePolyVersesVegetableToAnimal() != 8) ++bad;
            if (uam7TruenamePolyVersesMonsterToNormal() != 7) ++bad;
            if (uam7TruenamePolyVersesMonsterToMonster() != 6) ++bad;
            if (uam7TruenamePolyVersesOtherToHuman() != 5) ++bad;
            if (uam7TruenamePolyVersesAnimalToAnimal() != 4) ++bad;
            if (uam7TruenamePolyVersesVegetableToVegetable() != 3) ++bad;
            if (uam7TruenamePolyVersesMineralToMineral() != 2) ++bad;
            if (!uam7TruenamePolyReverseHolds()) ++bad;
            if (!uam7TruenamePolyDmClosestCase()) ++bad;
            if (uam7TruenamePolyDurationTurnsPerLevel() != 6) ++bad;
            if (uam7TruenamePolyTurnsOffPerVerse() != 1) ++bad;
            if (!uam7TruenamePolyKeepsOriginalHp()) ++bad;
            if (!uam7TruenameTransportTeleportsWithoutError()) ++bad;
            if (uam7TruenameTransportVerses100Miles() != 4) ++bad;
            if (uam7TruenameTransportVerses500Miles() != 5) ++bad;
            if (uam7TruenameTransportVerses2000Miles() != 6) ++bad;
            if (!uam7TruenameTransportListTruncated()) ++bad;

        // U8: volley
            if (strcmp(uam7VolleyName(),
                "Volley (Abjuration)") != 0) ++bad;
            if (uam7VolleyLevel() != 7) ++bad;
            if (!uam7VolleyRangeSpecial()) ++bad;
            if (!uam7VolleyDurationSpecial()) ++bad;
            if (!uam7VolleyAoeSpecial()) ++bad;
            if (!uam7VolleyExplanationLineLost()) ++bad;
            if (!uam7VolleyStatTailScrambled()) ++bad;
            if (!uam7VolleyComponentsCellLost()) ++bad;
            if (!uam7VolleyCastingTimeCellLost()) ++bad;
            if (!uam7VolleySaveCellLost()) ++bad;
            if (!uam7VolleyTurnsCastingBackOnSender()) ++bad;
            if (!uam7VolleyStatsDependOnCircumstance()) ++bad;
            if (!uam7VolleyPowerWordKillExample()) ++bad;
            if (!uam7VolleyBounceRequiresSaveVsSpell()) ++bad;
            if (!uam7VolleySentBackUntilSaveFails()) ++bad;
            if (!uam7VolleyCountsHalfExchangePerVolley()) ++bad;
            if (!uam7VolleyFirstLevelDissipatesExample()) ++bad;
            if (!uam7VolleySecondLevelFourPortions()) ++bad;
            if (!uam7VolleyProseTailScrambled()) ++bad;
            if (!uam7VolleyMaterialWillowWood()) ++bad;
            if (!uam7VolleyMaterialGutStrands()) ++bad;
            if (!uam7VolleyPrintsPastEighthTablePage()) ++bad;

        // the R342 table seam (only the seven
        // PHB fragments print; none of the new
        // names seam-checks)
        if (uas2Mu7thCount() != 7) ++bad;
        if (strcmp(uas2Mu7thName(0),
                "Drawmij's Instant") != 0)
            ++bad;
        if (strcmp(uas2Mu7thName(1),
                "Invisible Stalker") != 0)
            ++bad;
        if (strcmp(uas2Mu7thName(2),
                "Legend Lore") != 0) ++bad;
        if (strcmp(uas2Mu7thName(3),
                "Lower Water") != 0) ++bad;
        if (strcmp(uas2Mu7thName(4),
                "Monster Summoning") != 0)
            ++bad;
        if (strcmp(uas2Mu7thName(5),
                "Otiluke's Freezing Sphere")
                != 0) ++bad;
        if (strcmp(uas2Mu7thName(6),
                "Part Water") != 0) ++bad;
        // the absent new names (the seam
        // carries only PHB fragments)
        for (int i = 0; i < 7; ++i) {
            const char* n = uas2Mu7thName(i);
            if (strcmp(n, "Banishment") == 0)
                ++bad;
            if (strcmp(n, "Forcecage") == 0)
                ++bad;
            if (strcmp(n, "Mordenkainen's Magnificent")
                == 0)
                ++bad;
            if (strcmp(n, "Sequester") == 0)
                ++bad;
            if (strcmp(n,
                    "Teleport Without Error") == 0)
                ++bad;
            if (strcmp(n, "Torment") == 0) ++bad;
            if (strcmp(n, "Truename") == 0) ++bad;
            if (strcmp(n, "Volley") == 0) ++bad;
        }
        printf("R361 UA MU 7th level spells pin audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R361 audit')
s = rd(RT)
assert s.count(
    'R361 UA MU 7th level spells pin audit'
    ) == 1, 'd audit line'
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
assert s.count('audit: bad ') == 288, 'd census 288'
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
    '#include "rules/uamuspells7.h"'
    ) == 1, 'd include'
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
assert len(applied) + len(already) == 4, 'd count'


# ---- the summary ----
print('R361 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R361 note: the UA new magic-user')
print('spells pin round, the 7th level -')
print('the eight spell descriptions')
print('(banishment behind the scrambled')
print('stat head with the range')
print('interleaved; forcecage with the')
print('stat tail interleaved and the')
print('gap fraction garbled; the')
print('Mordenkainen magnificent mansion')
print('behind the garbled name header')
print('with the level cell lost;')
print('sequester behind the lost name')
print('header; teleport without error')
print('with the stat cells scrambled;')
print('torment with the range cell lost')
print('and the -1/-2/-3/-4/-6/-8 save')
print('ladder; truename with the')
print('polymorph verse ladder and the')
print('transport verses; volley with')
print('the Explanation line lost; the')
print('volley and truename sections')
print('print past the 8th-level table')
print('page); the family decodes the')
print('casting and duration 7s as 1;')
print('the R342 MU table seam prints')
print('only the seven PHB fragments,')
print('none of the new names')
print('seam-checks; the item stays')
print('open (the 8th-9th levels); the')
print('census 287 -> 288')
print('commit: R361: the UA new')
print('magic-user 7th level spells pin')
print('round (census 288)')

