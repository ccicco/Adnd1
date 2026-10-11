// ===========================================================================
// Adnd1 - rules/uamuspells3.h
// The UA NEW MAGIC-USER SPELLS (pp. 51-66) pins, R358: the
// 3rd-level spell descriptions - cloudburst, detect
// illusion, item, material, the Melf minute meteors,
// secret page, the sepia snake sigil and wind wall.
//
// Pin-era pattern (R322): pinned data only - no engine site
// exists.
//
// JUDGMENTs (the decode method):
//   - the digit-garble family (the R343 precedent): the
//     casting-time, duration and range 7s decode as 1 -
//     the cloudburst 7"/level range as 1 inch per
//     level and the "7 round" duration as 1 round per
//     level (the R352 druid seam pins 1 round per level;
//     the per-level is lost in the MU interleave); the
//     material "7 degree" range as 1, the unit (inch or
//     foot) uncertain pending the PDF; the wind wall
//     "7 round/level" as 1 round per level.
//   - the cloudburst stat block scrambles its cell order
//     (the save cell prints before the duration); the
//     save cell truncates at None + ampersand; the
//     casting-time
//     number is lost ("Casting Tim ... segment"); the
//     area prints a 3 inch diameter where the R352
//     druid seam pins 4 - a discrepancy flagged pending
//     the PDF; the MU block supplies the range cell the
//     druid block lost.
//   - the detect illusion name header loses its tail -
//     "Detect (Divination)" only; the name pins from the
//     prose (the same as the 1st-level illusionist
//     spell); the "except as noted" tail truncates; the
//     area length number is lost; no illusionist seam
//     exists (the item stays open).
//   - the item components cell splits at "V," + "M"
//     across the interleave (an S, if any, is lost);
//     the duration prints 6 turns/level with the
//     asterisk (quadrupled on non-living material).
//   - the material components cell garbles at "V," plus
//     a section-mark;
//     the prose head scrambles - "A ial spell allows
//     the magi toac-" - the area 7 is genuine (not a
//     casting-time or duration cell).
//   - the Melf minute meteors range cell prints empty -
//     a hole pending the PDF; the firing-rate sentence
//     interleaves with the sepia snake sigil tail but
//     the two rates pin (1 every 2 segments, or 1
//     every round).
//   - the secret page description prints under the 4th
//     level heading; its stat block interleaves with
//     dispel illusion (4th level, next round): the
//     secret page cells pin as 1 turn casting time,
//     touch, until dispelled, none, one page up to 2
//     ft. square; the prose scrambles with the dispel
//     illusion and Evard tentacle text.
//   - the sepia snake sigil body prints in the 4th
//     level region; its casting-time head is lost
//     ("Time: 3 segments"); the range prints ""2"" -
//     pinned as 2 inches with the quote garble noted.
//   - the wind wall components cell truncates at
//     "V, S," - the prose supplies the material; the
//     casting-time unit is lost (the 3 pins, decoded
//     as segments with doubt pending the PDF).
//
// ===========================================================================

namespace rules {

// ---- cloudburst (Alteration), the 3rd level ----
inline const char* uam3CloudburstName()
    { return "Cloudburst (Alteration)"; }

inline int uam3CloudburstLevel()
    { return 3; }

inline bool uam3CloudburstComponentsVSM()
    { return true; }

// The range prints 7"/level - the family decodes 1 inch
// per level. This is the cell the R352 druid block lost.
inline int uam3CloudburstRangeInchesPerLevel()
    { return 1; }

// The casting-time number is lost; only the unit prints.
inline bool uam3CloudburstCastingTimeNumberLost()
    { return true; }

inline bool uam3CloudburstCastingTimeUnitSegments()
    { return true; }

// The save cell prints before the duration (scrambled).
inline bool uam3CloudburstStatBlockScrambled()
    { return true; }

// The save cell truncates at None + ampersand - the R352
// druid
// seam pins none and special.
inline bool uam3CloudburstSaveNoneAndSpecial()
    { return true; }

inline bool uam3CloudburstSaveCellTruncated()
    { return true; }

// The duration prints "7 round" - the family decodes 1
// round per level (the R352 druid seam).
inline int uam3CloudburstDurationRoundsPerLevel()
    { return 1; }

// The area prints a 3" diameter - the R352 druid seam
// pins 4; the disagreement is flagged pending the PDF.
inline int uam3CloudburstCylinderDiameterInches()
    { return 3; }

inline bool uam3CloudburstDiameterDisagreesWithDruidSeam()
    { return true; }

inline int uam3CloudburstCylinderHeightInches()
    { return 6; }

// The spell is identical to the 3rd-level clerical spell
// of the same name, except that a holy symbol is not
// part of the material component.
inline bool uam3CloudburstIdenticalToClerical3rd()
    { return true; }

inline bool uam3CloudburstNoHolySymbolComponent()
    { return true; }

// ---- detect illusion (Divination), the 3rd level ----
// The name header loses its tail - "Detect (Divination)"
// only; the name pins from the prose.
inline const char* uam3DetectName()
    { return "Detect Illusion (Divination)"; }

inline bool uam3DetectNameHeaderTailLost()
    { return true; }

inline int uam3DetectLevel()
    { return 3; }

inline bool uam3DetectComponentsVSM()
    { return true; }

inline int uam3DetectCastingTimeSegments()
    { return 3; }

inline bool uam3DetectRangeTouch()
    { return true; }

inline bool uam3DetectSaveNone()
    { return true; }

inline int uam3DetectDurationRoundsMin()
    { return 2; }

inline int uam3DetectDurationRoundsPerLevel()
    { return 1; }

// The area prints Line of sight 1" wide, then the
// length number is lost - a hole pending the PDF.
inline bool uam3DetectAoeLineOfSightOneInchWide()
    { return true; }

inline bool uam3DetectAoeLengthLost()
    { return true; }

// The spell is the same as the 1st-level illusionist
// spell detect illusion, except as noted (the tail
// truncates). No illusionist seam exists yet.
inline bool uam3DetectSameAsIllusionist1st()
    { return true; }

inline bool uam3DetectExceptAsNotedTruncated()
    { return true; }

// ---- item (Alteration), the 3rd level ----
inline const char* uam3ItemName()
    { return "Item (Alteration)"; }

inline int uam3ItemLevel()
    { return 3; }

inline bool uam3ItemRangeTouch()
    { return true; }

inline int uam3ItemDurationTurnsPerLevel()
    { return 6; }

// The asterisk: the duration quadruples on non-living
// material.
inline bool uam3ItemDurationQuadrupledNonLiving()
    { return true; }

inline int uam3ItemAoeCuFtPerLevel()
    { return 2; }

inline bool uam3ItemShrinksToOneTwelfth()
    { return true; }

inline bool uam3ItemClothCompositionOption()
    { return true; }

// Only living things are entitled to a save, at +4.
inline bool uam3ItemLivingEntitledToSave()
    { return true; }

inline int uam3ItemLivingSavePlus4()
    { return 4; }

// Objects and creatures transformed to cloth save
// normally against subsequent attacks.
inline bool uam3ItemClothSavesNormally()
    { return true; }

inline bool uam3ItemReturnsOnTossOrCommand()
    { return true; }

inline bool uam3ItemCanAffectFireAndFuel()
    { return true; }

// The components cell splits at "V," + "M" across the
// interleave; an S, if any, is lost.
inline bool uam3ItemComponentsV()
    { return true; }

inline bool uam3ItemComponentsM()
    { return true; }

inline bool uam3ItemComponentsCellSplit()
    { return true; }

inline int uam3ItemCastingTimeSegments()
    { return 3; }

inline bool uam3ItemSaveSpecial()
    { return true; }

// ---- material (Evocation-Conjuration), the 3rd ----
inline const char* uam3MaterialName()
    { return "Material (Evocation-Conjuration)"; }

inline int uam3MaterialLevel()
    { return 3; }

// The components cell garbles at "V," plus a section-mark.
inline bool uam3MaterialComponentsV()
    { return true; }

inline bool uam3MaterialComponentsCellGarbled()
    { return true; }

inline int uam3MaterialCastingTimeRounds()
    { return 1; }

// The range prints "7 degrees" - the family decodes 1;
// the unit (inch or foot) is uncertain pending the PDF.
inline bool uam3MaterialRangePrintsDegrees()
    { return true; }

inline int uam3MaterialRangeDecodedOne()
    { return 1; }

inline bool uam3MaterialSaveNone()
    { return true; }

inline bool uam3MaterialDurationPermanent()
    { return true; }

inline int uam3MaterialAoeCuFtPerLevel()
    { return 7; }

// The prose head scrambles: A ial spell allows the
// magi toac- tually bring into being certain common
// things.
inline bool uam3MaterialProseHeadScrambled()
    { return true; }

inline bool uam3MaterialCommonStoneEarthWood()
    { return true; }

// Other inorganic or non-living materials: water, air,
// dung, straw, etc. (the "living" head is lost in the
// interleave).
inline bool uam3MaterialInorganicNonLivingEtc()
    { return true; }

// Grass: a base 100% chance of total failure, modified
// downward by 1% per level of the caster.
inline int uam3MaterialGrassBaseFailurePct()
    { return 100; }

inline bool uam3MaterialGrassFailureMinusOnePctPerLevel()
    { return true; }

inline bool uam3MaterialAnimalLifeNever()
    { return true; }

// No worked, refined or fabricated items; no rough gems
// or precious metals.
inline bool uam3MaterialNoWorkedRefinedFabricated()
    { return true; }

inline bool uam3MaterialNoRoughGemsOrPreciousMetals()
    { return true; }

inline bool uam3MaterialCreatesCommonBasicThings()
    { return true; }

// ---- the Melf minute meteors (Evocation/Alteration) ----
inline const char* uam3MeteorsName()
    { return "Melf's Minute Meteors (Evocation/Alteration)"; }

inline int uam3MeteorsLevel()
    { return 3; }

inline bool uam3MeteorsComponentsVSM()
    { return true; }

inline int uam3MeteorsCastingTimeSegments()
    { return 5; }

// The range cell prints empty - a hole pending the PDF.
inline bool uam3MeteorsRangeCellEmpty()
    { return true; }

inline bool uam3MeteorsDurationSpecial()
    { return true; }

inline bool uam3MeteorsSaveNone()
    { return true; }

inline bool uam3MeteorsAoeOneTargetPerMissile()
    { return true; }

// Each globe bursts into a 1 ft. diameter sphere on
// impact, inflicting 1-4 points of damage.
inline int uam3MeteorsBurstDiameterFeet()
    { return 1; }

inline int uam3MeteorsDamageMin()
    { return 1; }

inline int uam3MeteorsDamageMax()
    { return 4; }

inline bool uam3MeteorsIgnitesCombustibles()
    { return true; }

// The meteors are missile weapons thrown by the mage;
// misses are treated as grenade-like missiles.
inline bool uam3MeteorsMissileWeapons()
    { return true; }

inline bool uam3MeteorsMissesGrenadeLike()
    { return true; }

// One missile per level of experience; the firing
// continues until the caster foregoes the remainder or
// a dispel magic succeeds.
inline bool uam3MeteorsOnePerLevelOfExperience()
    { return true; }

inline bool uam3MeteorsDispelMagicEnds()
    { return true; }

// The firing-rate sentence interleaves with the sepia
// snake sigil tail - the two rates still pin.
inline bool uam3MeteorsFireRateSentenceScrambled()
    { return true; }

inline bool uam3MeteorsTwoRateOptions()
    { return true; }

inline bool uam3MeteorsRateOneEvery2Segments()
    { return true; }

inline bool uam3MeteorsRateOneEveryRound()
    { return true; }

// The caster may not switch between the options once
// one is chosen.
inline bool uam3MeteorsRateChoiceCannotSwitch()
    { return true; }

// Option one: point at the target on the second segment
// after casting, repeated every 2 segments; the spell
// usually carries into at least the following round.
inline bool uam3MeteorsRateOnePointEvery2Segments()
    { return true; }

inline bool uam3MeteorsCarriesIntoFollowingRound()
    { return true; }

// Option two: withhold or discharge missiles at will, so
// long as one goes each round; the caster can discharge
// one and cast another spell in the same round, if the
// other spell needs no continuing concentration; a lost
// mental count forfeits the remainder.
inline bool uam3MeteorsRateTwoWithholdPerRound()
    { return true; }

inline bool uam3MeteorsRateTwoSpellSameRound()
    { return true; }

inline bool uam3MeteorsRateTwoNoConcentration()
    { return true; }

inline bool uam3MeteorsLoseRemainderOnLostCount()
    { return true; }

// The components: nitre and sulphur formed into a bead
// with pine tar, and a small tube of gold costing no
// less than 1,000 gp, potent through numerous castings
// unless damaged.
inline bool uam3MeteorsMaterialNitreSulphurPineTarBead()
    { return true; }

inline bool uam3MeteorsMaterialGoldTube()
    { return true; }

inline int uam3MeteorsTubeCostGpMin()
    { return 1000; }

inline bool uam3MeteorsTubeReusableUnlessDamaged()
    { return true; }

// The sepia snake sigil tail - "grow hungry, sleep or
// regain spells..." - interleaves into the material
// paragraph.
inline bool uam3MeteorsSepiaTailInterleaved()
    { return true; }

// ---- secret page (Alteration), the 3rd level ----
// The description prints under the 4th level heading;
// its stat block interleaves with dispel illusion (the
// 4th level, next round).
inline const char* uam3SecretPageName()
    { return "Secret Page (Alteration)"; }

inline bool uam3SecretPageUnderFourthHeading()
    { return true; }

inline bool uam3SecretPageStatInterleavedWithDispelIllusion()
    { return true; }

inline int uam3SecretPageLevel()
    { return 3; }

inline bool uam3SecretPageComponentsVSM()
    { return true; }

inline int uam3SecretPageCastingTimeTurns()
    { return 1; }

inline bool uam3SecretPageRangeTouch()
    { return true; }

inline bool uam3SecretPageDurationUntilDispelled()
    { return true; }

inline bool uam3SecretPageSaveNone()
    { return true; }

inline int uam3SecretPageAoeMaxFt()
    { return 2; }

inline bool uam3SecretPageAoeOnePageUpTo2FtSquare()
    { return true; }

// The spell alters the actual contents of a page to
// appear as something entirely different - a map to a
// treatise on burnishing ebony walking sticks, a spell
// text to a ledger or another spell.
inline bool uam3SecretPageAltersContents()
    { return true; }

inline bool uam3SecretPageMapToTreatiseExample()
    { return true; }

// Confuse and explosive runes may be cast upon the
// secret page; a comprehend languages will not reveal
// the actual contents.
inline bool uam3SecretPageRunesAllowed()
    { return true; }

inline bool uam3SecretPageComprehendLanguagesFails()
    { return true; }

// The caster reverses the effect by the mere utterance
// of the command word, peruses the actual page, and
// returns it to secret page form; a double repetition of
// the command word removes the spell.
inline bool uam3SecretPageReversedByCommandWord()
    { return true; }

inline bool uam3SecretPageRemovedByDoubleCommand()
    { return true; }

// Others noting the dim magic can attempt a dispel
// magic; if it fails, the page is destroyed. Short of
// alter reality or wish, only will-o-wisp or boggart
// essence reveals the true nature.
inline bool uam3SecretPageFailedDispelDestroysPage()
    { return true; }

inline bool uam3SecretPageEssenceReveals()
    { return true; }

inline bool uam3SecretPageMaterialHerringScales()
    { return true; }

// ---- the sepia snake sigil (Conjuration/Summoning) ----
// The body prints in the 4th level region; the casting
// head is lost ("Time: 3 segments").
inline const char* uam3SepiaName()
    { return "Sepia Snake Sigil (Conjuration/Summoning)"; }

inline bool uam3SepiaBodyPrintsInFourthRegion()
    { return true; }

inline int uam3SepiaLevel()
    { return 3; }

inline bool uam3SepiaComponentsVSM()
    { return true; }

// The range cell prints ""2"" - pinned as 2 inches with
// the quote garble noted.
inline int uam3SepiaRangeInches()
    { return 2; }

inline bool uam3SepiaRangePrintsQuotedTwo()
    { return true; }

inline bool uam3SepiaDurationSpecial()
    { return true; }

inline bool uam3SepiaAoeOneSigil()
    { return true; }

inline bool uam3SepiaCastingTimeHeadLost()
    { return true; }

inline int uam3SepiaCastingTimeSegments()
    { return 3; }

inline bool uam3SepiaSaveNone()
    { return true; }

// Three forms of the spell, each eventually conjuring a
// deep brown snake-like force that springs at the
// nearest living creature - never the caster - striking
// as a monster with hit dice equal to the caster level.
inline bool uam3SepiaThreeForms()
    { return true; }

inline bool uam3SepiaStrikesNearestLiving()
    { return true; }

inline bool uam3SepiaNeverAttacksCaster()
    { return true; }

inline bool uam3SepiaAttackHdPerLevel()
    { return true; }

// A struck victim is engulfed in a shimmering amber
// field of force, frozen and immobilized until the
// caster releases it or a dispel magic does so; nothing
// can get at the victim, move the force, or affect
// either.
inline bool uam3SepiaEngulfsOnStrike()
    { return true; }

inline bool uam3SepiaAmberFieldOfForce()
    { return true; }

inline bool uam3SepiaFrozenUntilReleaseOrDispel()
    { return true; }

inline bool uam3SepiaNothingCanAffect()
    { return true; }

// The victim does not age, grow hungry, sleep or regain
// spells, and is not aware of the surroundings.
inline bool uam3SepiaNoAgeHungerSleepOrSpells()
    { return true; }

// A miss dissipates in a flash of brown light, a loud
// noise and dun-colored smoke 1" in diameter lasting 1
// round.
inline bool uam3SepiaMissDissipatesBrownFlash()
    { return true; }

inline int uam3SepiaMissSmokeInches()
    { return 1; }

inline int uam3SepiaMissSmokeRounds()
    { return 1; }

// The three applications: a glowing sigil in the air
// drawn by the caster and pointed at the target; a
// glyph of umber marked on a surface touched or gazed
// upon; a small character written into a magic work to
// protect it.
inline bool uam3SepiaApplicationAirSigil()
    { return true; }

inline bool uam3SepiaApplicationGlyphUmber()
    { return true; }

inline bool uam3SepiaApplicationWrittenIntoWork()
    { return true; }

// The components: 100 gp worth of powdered amber, a
// scale from any snake, and a pinch of mushroom spores.
inline int uam3SepiaMaterialAmberGp()
    { return 100; }

inline bool uam3SepiaMaterialSnakeScale()
    { return true; }

inline bool uam3SepiaMaterialMushroomSpores()
    { return true; }

// ---- wind wall (Alteration), the 3rd level ----
inline const char* uam3WindWallName()
    { return "Wind Wall (Alteration)"; }

inline int uam3WindWallLevel()
    { return 3; }

// The components cell truncates at "V, S," - the prose
// supplies the material.
inline bool uam3WindWallComponentsCellTruncated()
    { return true; }

inline bool uam3WindWallMaterialTinyFanAndExoticFeather()
    { return true; }

inline int uam3WindWallRangeInchesPerLevel()
    { return 1; }

// The casting time prints 3 with the unit lost - the 3
// pins, decoded as segments with doubt pending the PDF.
inline int uam3WindWallCastingTimeSegments()
    { return 3; }

inline bool uam3WindWallCastingTimeUnitLost()
    { return true; }

inline bool uam3WindWallSaveSpecial()
    { return true; }

// The duration prints "7 round/level" - the family
// decodes 1 round per level.
inline int uam3WindWallDurationRoundsPerLevel()
    { return 1; }

// An area 1" wide and high per level of caster.
inline int uam3WindWallAoeInchesPerLevel()
    { return 1; }

inline bool uam3WindWallAoeWideAndHigh()
    { return true; }

inline bool uam3WindWallInvisibleCurtain()
    { return true; }

// Sufficient to blow birds as large as crows upward, or
// to tear papers and like materials from unsuspecting
// hands (a saving throw versus spell maintains the
// grasp); normal insects cannot pass; loose material,
// even cloth garments, caught in the wall flies upward.
inline bool uam3WindWallBlowsBirdsUpToCrows()
    { return true; }

inline bool uam3WindWallTearsPapersFromHands()
    { return true; }

inline bool uam3WindWallSaveToMaintainGrasp()
    { return true; }

inline bool uam3WindWallNormalInsectsCannotPass()
    { return true; }

inline bool uam3WindWallLooseMaterialFliesUpward()
    { return true; }

}   // namespace rules
