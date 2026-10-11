// ===========================================================================
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

}   // namespace rules
