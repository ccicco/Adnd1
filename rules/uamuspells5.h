// ===========================================================================
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

