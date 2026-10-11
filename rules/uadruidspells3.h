// ===========================================================================
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

}   // namespace rules
