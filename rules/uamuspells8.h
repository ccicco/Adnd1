// ===========================================================================
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

