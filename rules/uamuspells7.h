// ===========================================================================
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

