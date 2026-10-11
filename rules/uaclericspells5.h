// ===========================================================================
// Adnd1 - rules/uaclericspells5.h
// The UA NEW CLERIC SPELLS (pp. 40-41) pins, R347: the 5th-level
// spell descriptions - air walk, animate dead monsters, golem,
// magic font, rainbow and spike stones (the spike stones prose
// prints here in the cleric chapter; the druid chapter (pp.
// 42-45) cross-references it - the druid item will seam-check
// against this pin).
// Pin-era pattern (R322): pinned data only - no engine site exists.
// The R341 continued table (4th-7th) prints seven 5th-level
// fragments (Commune, Cure Critical Wounds, Dispel Evil, Magic
// Font, Plane Shift, Spike Growth, True Seeing); magic font is
// the one name of this round that seam-checks - the rest pin
// from the prose alone.
//
// JUDGMENTs (the decode method):
//   - the digit-garble family (established R343, corroborated
//     R344/R346): the OCR prints 7 where 1 belongs in the stat
//     cells. This round's three stat-cell 7s decode as 1: air
//     walk casting "7 segment" = 1 segment; animate dead
//     monsters casting "7 segments" = 1 segment; golem casting
//     "7 segments" = 1 segment - all three family decodes
//     without independent corroboration this round, verbatim
//     with doubt pending the PDF.
//   - two 7s stay genuine (not the family): the rainbow bow
//     "fire 7 missiles" is corroborated by the spelled-out
//     "seven-hued", "seven-colored" and "seven measures"; the
//     golem size ceiling "as large as 7" tall" is corroborated
//     by the clean "approximately man-sized" prose.
//   - the golem/rainbow page interleaves: the two stat tables
//     print in scrambled column order. Decoded by position -
//     the golem keeps Level 5, Range 1", Duration Special, Area
//     of Effect Special; the rainbow keeps Components V, S, M,
//     Casting Time 8 segments, Duration 1 round/level, Saving
//     Throw None. The rainbow Range cell never prints - a
//     hole.
//   - the straw golem SD line shatters across the air walk
//     table ("SD immune to" + "piercing weapons," + "The half
//     golem damage: is highly from blunt" + "ity is 30
//     pounds"); decoded: immune to piercing weapons, half
//     damage from blunt weapons, carrying capacity 30 pounds
//     - the reverse of the rope golem's clean line.
//   - magic font's components print "V, S\$, M" - the S-cell
//     garble decodes as the plain S (the family-standard
//     component trio).
//   - the bridge length cells print "20\"" and "120" - the
//     degree/inch marks are OCR noise for feet (the same mark
//     noise as the 12" rate cells); decoded as feet.
//   - the animate dead monsters prose garbles mid-sentence
//     ("the remains must ... be of bipedal ... similar to
//     those of humans, except ... hit dice (and ... with ...
//     7' height)"); the sense is pinned (bipedal, man-like,
//     hit-dice and height the exceptions), the fragment
//     region stays a hole.
//   - the magic font prose garbles around the capacity rule
//     ("becomes Magic similar Tr to a crystal ball (see under
//     Dungeon Masters For Guide, than each vial of capacity of
//     the basin of the font"); decoded: the basin becomes
//     similar to a crystal ball, and for each vial of capacity
//     the cleric may scry 1 round.
//   - the rainbow bridge prose garbles at the tail ("If the
//     bridge's ... is exceeded at any ... time, ... the ...
//     it will last for the length of the spell or until
//     ordered out of ... existence ... by the caster"); the
//     load limit and the two dismissal modes are pinned, the
//     fragment region stays a hole.
//
// OCR holes (the item stays open - the 6th-7th levels pin in
// later rounds; these stay pending the PDF): the animate dead
// monsters Range cell (blank); the rainbow Range cell (never
// prints); the three family casting-time decodes (air walk,
// animate dead monsters, golem); the straw golem SD decode;
// the animate dead monsters and magic font prose fragment
// regions; the rainbow bridge tail fragment region.
// ===========================================================================

#pragma once

namespace rules {

// ---- air walk (Alteration), p. 40 ----
inline const char* uac5AirwalkName()
    { return "Air Walk (Alteration)"; }

inline bool uac5AirwalkComponentsVSM()
    { return true; }

inline bool uac5AirwalkRangeTouch()
    { return true; }

// The casting time prints "7 segment" - the digit-garble family
// decodes 1 segment; verbatim with doubt pending the PDF.
inline int uac5AirwalkCastingTimeSegments()
    { return 1; }

inline bool uac5AirwalkSaveNone()
    { return true; }

inline int uac5AirwalkDurationTurnsBase()
    { return 6; }

inline int uac5AirwalkDurationTurnsPerLevel()
    { return 1; }

inline bool uac5AirwalkAoeOneCreature()
    { return true; }

// Tread upon air just as if it were solid ground; ascending is
// like walking up a hill - the steeper, the slower.
inline bool uac5AirwalkTreadsOnAir()
    { return true; }

// The ascent ladder: 45 degrees at one-half normal movement,
// 60 degrees at one-fourth, straight up at one-eighth.
inline int uac5AirwalkAscent45Divisor()
    { return 2; }

inline int uac5AirwalkAscent60Divisor()
    { return 4; }

inline int uac5AirwalkAscentStraightDivisor()
    { return 8; }

// Rapid descent inverts the ladder: straight downward can be
// done at eight times the normal rate (or any slower rate the
// traveller desires).
inline int uac5AirwalkDescentStraightMultiple()
    { return 8; }

// Always in control of the movement rate - someone descending
// rapidly can "stop on a copper piece" to avoid crashing.
inline bool uac5AirwalkAlwaysInControl()
    { return true; }

inline bool uac5AirwalkStopOnCopperPiece()
    { return true; }

// A gust of wind spell in the same area: one-half the usual
// rate going into the gust, twice the usual rate with it.
inline bool uac5AirwalkGustInterplay()
    { return true; }

inline int uac5AirwalkGustIntoDivisor()
    { return 2; }

inline int uac5AirwalkGustWithMultiple()
    { return 2; }

// Placed on any creature touched, up to and including one of
// giant size; a trained horse could be ridden through the air.
inline bool uac5AirwalkTargetUpToGiantSize()
    { return true; }

inline bool uac5AirwalkTrainedHorseExample()
    { return true; }

// An animal not accustomed to such movement would panic - the
// steed needs careful and lengthy training.
inline bool uac5AirwalkBeastNeedsTraining()
    { return true; }

// The material: the cleric's holy/unholy symbol and a bit of
// thistledown.
inline bool uac5AirwalkMaterialSymbolThistledown()
    { return true; }

// ---- animate dead monsters (Necromantic), p. 40 ----
inline const char* uac5AnimateName()
    { return "Animate Dead Monsters (Necromantic)"; }

inline bool uac5AnimateComponentsVSM()
    { return true; }

// The Range cell prints blank - unresolvable; a hole.
inline bool uac5AnimateRangeLost()
    { return true; }

// The casting time prints "7 segments" - the family decodes
// 1 segment; verbatim with doubt pending the PDF.
inline int uac5AnimateCastingTimeSegments()
    { return 1; }

inline bool uac5AnimateDurationPermanent()
    { return true; }

inline bool uac5AnimateSaveNone()
    { return true; }

inline bool uac5AnimateAoeSpecial()
    { return true; }

// Animates 1 humanoid or semi-humanoid skeleton or corpse for
// every 2 levels of experience attained.
inline int uac5AnimateAnimatedPerTwoLevels()
    { return 1; }

// Direct commands or instructions of up to about 12 words in
// length will be obeyed (cf. the animate dead spell).
inline int uac5AnimateCommandWordsMax()
    { return 12; }

inline bool uac5AnimateCfAnimateDead()
    { return true; }

// The monster-type examples: apes (carnivorous and giant),
// bugbears, ettins, giants (all varieties), ogres and trolls -
// the list is not exclusive.
inline int uac5AnimateExampleTypeCount()
    { return 6; }

inline const char* uac5AnimateExampleTypeName(int i)
    { static const char* const k[6] = {
        "apes (carnivorous and giant)", "bugbears",
        "ettins", "giants (all varieties)", "ogres",
        "trolls" };
      if (i < 0) i = 0; if (i > 5) i = 5;
      return k[i]; }

inline bool uac5AnimateListNotExclusive()
    { return true; }

// The garbled specimen rule: the remains must be of bipedal
// creatures similar to humans, except hit dice and height -
// the fragment region stays a hole pending the PDF.
inline bool uac5AnimateBipedalManLike()
    { return true; }

inline bool uac5AnimateSpecimenRuleFragmentLost()
    { return true; }

// Corpses: monster zombies (see Monster Manual II), or normal
// (living) creatures of the same form if that type normally
// has less than 6 hit dice.
inline bool uac5AnimateCorpseMonsterZombieMM2()
    { return true; }

inline int uac5AnimateLowHDThreshold()
    { return 6; }

// Skeletons: monsters of half the hit dice (rounded up) of the
// normal sort.
inline bool uac5AnimateSkeletonHalfHDRoundedUp()
    { return true; }

// Either type receives its normal physical attacks, but no
// special attacks or defenses beyond monster zombie/skeleton
// norms.
inline bool uac5AnimateNormalAttacksOnly()
    { return true; }

// The material: the cleric's holy/unholy symbol and a small
// specimen of the creature type to be animated.
inline bool uac5AnimateMaterialSymbolSpecimen()
    { return true; }

// ---- golem (Enchantment/Charm), pp. 40-41 ----
inline const char* uac5GolemName()
    { return "Golem (Enchantment/Charm)"; }

inline bool uac5GolemComponentsVSM()
    { return true; }

inline int uac5GolemRangeInches()
    { return 1; }

// The casting time prints "7 segments" - the family decodes
// 1 segment; verbatim with doubt pending the PDF.
inline int uac5GolemCastingTimeSegments()
    { return 1; }

inline bool uac5GolemDurationSpecial()
    { return true; }

inline bool uac5GolemSaveNone()
    { return true; }

inline bool uac5GolemAoeSpecial()
    { return true; }

// The cleric must personally construct the form of the golem
// and then place a prayer spell upon the construction.
inline bool uac5GolemRequiresPersonalConstruction()
    { return true; }

inline bool uac5GolemRequiresPrayerSpell()
    { return true; }

// All golems are man-shaped and approximately man-sized, from
// as small as 3 feet to as large as 7 feet tall.
inline bool uac5GolemManShapedManSized()
    { return true; }

inline int uac5GolemMinHeightFeet()
    { return 3; }

inline int uac5GolemMaxHeightFeet()
    { return 7; }

// The sort of golem depends on the material used and the level
// of the cleric - the four-material ladder.
inline int uac5GolemMaterialCount()
    { return 4; }

inline const char* uac5GolemMaterialName(int i)
    { static const char* const k[4] = {
        "straw", "rope", "leather", "wood" };
      if (i < 0) i = 0; if (i > 3) i = 3;
      return k[i]; }

inline int uac5GolemMinLevel(int i)
    { static const int k[4] = { 9, 11, 13, 15 };
      if (i < 0) i = 0; if (i > 3) i = 3;
      return k[i]; }

inline int uac5GolemBuildHours(int i)
    { static const int k[4] = { 1, 3, 9, 27 };
      if (i < 0) i = 0; if (i > 3) i = 3;
      return k[i]; }

inline int uac5GolemDurationHoursPerLevel(int i)
    { static const int k[4] = { 1, 3, 6, 12 };
      if (i < 0) i = 0; if (i > 3) i = 3;
      return k[i]; }

inline int uac5GolemAC(int i)
    { static const int k[4] = { 10, 8, 6, 4 };
      if (i < 0) i = 0; if (i > 3) i = 3;
      return k[i]; }

inline int uac5GolemMV(int i)
    { static const int k[4] = { 12, 9, 6, 3 };
      if (i < 0) i = 0; if (i > 3) i = 3;
      return k[i]; }

inline int uac5GolemHDBase(int i)
    { static const int k[4] = { 2, 3, 4, 5 };
      if (i < 0) i = 0; if (i > 3) i = 3;
      return k[i]; }

inline int uac5GolemHDBonus(int i)
    { static const int k[4] = { 4, 6, 8, 10 };
      if (i < 0) i = 0; if (i > 3) i = 3;
      return k[i]; }

inline int uac5GolemHP(int i)
    { static const int k[4] = { 20, 30, 40, 50 };
      if (i < 0) i = 0; if (i > 3) i = 3;
      return k[i]; }

inline int uac5GolemAT(int i)
    { static const int k[4] = { 2, 1, 2, 1 };
      if (i < 0) i = 0; if (i > 3) i = 3;
      return k[i]; }

inline const char* uac5GolemDamage(int i)
    { static const char* const k[4] = {
        "1-2/1-2", "1-6 plus strangulation",
        "1-6/1-6", "3-12" };
      if (i < 0) i = 0; if (i > 3) i = 3;
      return k[i]; }

inline const char* uac5GolemSD(int i)
    { static const char* const k[4] = {
        "immune to piercing, half from blunt",
        "immune to blunt, half from piercing",
        "+1 or better weapon, half from blunt",
        "+1 or better weapon, immune to blunt"
        " and piercing" };
      if (i < 0) i = 0; if (i > 3) i = 3;
      return k[i]; }

inline int uac5GolemCarryPounds(int i)
    { static const int k[4] = { 30, 40, 50, 60 };
      if (i < 0) i = 0; if (i > 3) i = 3;
      return k[i]; }

// The straw golem SD line shatters across the air walk table -
// the decode (immune to piercing weapons, half damage from
// blunt) is the reverse of the rope golem's clean line.
inline bool uac5GolemStrawSDDecoded()
    { return true; }

// The rope golem: strangulation inflicts 6 points per round
// after a hit until destroyed or caused to release its grip.
inline int uac5GolemRopeStranglePerRound()
    { return 6; }

inline bool uac5GolemRopeStrangleUntilRelease()
    { return true; }

// The wood golem: +1 or better magic weapon to hit, immune to
// blunt and piercing weapons (the leather golem shares the
// weapon gate and takes half damage from blunt).
inline bool uac5GolemWoodImmuneBluntPiercing()
    { return true; }

inline bool uac5GolemLeatherHalfFromBlunt()
    { return true; }

// Collectively the lesser golems, distinguished from the
// Monster Manual golems; they have no minds, so charm, fear,
// hold, sleep and the like have no effect.
inline bool uac5GolemLesserGolemsName()
    { return true; }

inline bool uac5GolemNoMinds()
    { return true; }

inline int uac5GolemMindlessSpellExamples()
    { return 4; }

inline const char* uac5GolemMindlessSpellName(int i)
    { static const char* const k[4] = {
        "charm", "fear", "hold", "sleep" };
      if (i < 0) i = 0; if (i > 3) i = 3;
      return k[i]; }

// The dweomer lets a lesser golem save as if a cleric of the
// same level as its creator.
inline bool uac5GolemSavesAsCreatorLevel()
    { return true; }

// They cannot speak, but comprehend and carry out simple
// instructions of no more than a dozen words.
inline bool uac5GolemCannotSpeak()
    { return true; }

inline int uac5GolemInstructionWordsMax()
    { return 12; }

// ---- magic font (Divination), p. 41 ----
inline const char* uac5FontName()
    { return "Magic Font (Divination)"; }

// The components print "V, S\$, M" - the S-cell garble decodes
// as the plain S (the family-standard trio).
inline bool uac5FontComponentsVSM()
    { return true; }

inline bool uac5FontComponentsDecoded()
    { return true; }

inline bool uac5FontRangeTouch()
    { return true; }

inline int uac5FontCastingTimeTurns()
    { return 5; }

inline bool uac5FontDurationSpecial()
    { return true; }

inline bool uac5FontSaveNone()
    { return true; }

inline bool uac5FontAoeSpecial()
    { return true; }

// A holy/unholy water font serves as a scrying device; the
// spell will not function unless the cleric is in good
// standing with his or her deity.
inline bool uac5FontScryingDevice()
    { return true; }

inline bool uac5FontRequiresGoodStanding()
    { return true; }

// The garbled capacity rule decoded: the basin of holy/unholy
// water becomes similar to a crystal ball (see the Dungeon
// Masters Guide); the fragment region stays a hole.
inline bool uac5FontLikeCrystalBall()
    { return true; }

inline bool uac5FontCapacityRuleFragmentLost()
    { return true; }

// For each vial of capacity of the basin, the cleric may scry
// for 1 round - the duration is directly related to the size
// of the receptacle.
inline int uac5FontRoundsPerVial()
    { return 1; }

inline bool uac5FontDurationTiedToCapacity()
    { return true; }

// The scrying-detection chances: the crystal ball description
// in the DMG and the magic-user spell magic mirror herein.
inline bool uac5FontDetectionSeeMagicMirror()
    { return true; }

// The material - the holy/unholy symbol and the font and its
// trappings - is not exhausted by the use of the spell.
inline bool uac5FontMaterialNotExhausted()
    { return true; }

// ---- rainbow (Evocation/Alteration), p. 41 ----
inline const char* uac5RainbowName()
    { return "Rainbow (Evocation/Alteration)"; }

inline bool uac5RainbowComponentsVSM()
    { return true; }

// The Range cell never prints in the scrambled table - a
// hole.
inline bool uac5RainbowRangeLost()
    { return true; }

inline int uac5RainbowCastingTimeSegments()
    { return 8; }

inline int uac5RainbowDurationRoundsPerLevel()
    { return 1; }

inline bool uac5RainbowSaveNone()
    { return true; }

inline bool uac5RainbowAoeSpecial()
    { return true; }

// The caster must be in sight of a rainbow of any sort, or
// have the special component (see below).
inline bool uac5RainbowNeedsRainbowSight()
    { return true; }

inline bool uac5RainbowSpecialComponentFallback()
    { return true; }

// Four applications; the cleric decides which is desired at
// the time of casting.
inline int uac5RainbowApplicationCount()
    { return 4; }

inline const char* uac5RainbowApplicationName(int i)
    { static const char* const k[4] = {
        "bow", "bridge", "elevator", "flagon" };
      if (i < 0) i = 0; if (i > 3) i = 3;
      return k[i]; }

// The bow: a shimmering, multi-layered bow of rainbow hues,
// light and easy to pull - anyone of strength 6 or better can
// use it.
inline bool uac5RainbowBowShimmering()
    { return true; }

inline int uac5RainbowBowStrengthMin()
    { return 6; }

// Each missile equals a +3 weapon; no non-proficiency penalty;
// only a member of a character class permitted to use a bow
// may employ it.
inline int uac5RainbowBowMissilePlus()
    { return 3; }

inline bool uac5RainbowBowNoNonproficiencyPenalty()
    { return true; }

inline bool uac5RainbowBowBowClassOnly()
    { return true; }

// The bow fires 7 missiles before disappearing - a genuine 7,
// corroborated by the spelled-out "seven-hued" and the seven
// colors (not the digit-garble family).
inline int uac5RainbowBowMissiles()
    { return 7; }

// It fires once or twice per round, according to the user's
// desire; each fired missile removes one hue.
inline int uac5RainbowBowMaxShotsPerRound()
    { return 2; }

inline bool uac5RainbowBowHueLeavesPerShot()
    { return true; }

// Each color causes double damage to its targets:
inline int uac5RainbowBowColorCount()
    { return 7; }

inline const char* uac5RainbowBowColorName(int i)
    { static const char* const k[7] = {
        "red", "orange", "yellow", "green",
        "blue", "indigo", "violet" };
      if (i < 0) i = 0; if (i > 6) i = 6;
      return k[i]; }

inline const char* uac5RainbowBowColorTarget(int i)
    { static const char* const k[7] = {
        "fire dwellers/users",
        "earth elementals",
        "vegetable targets (incl. fungus"
        " creatures, shambling mounds,"
        " treants)",
        "aquatic creatures and water"
        " elementals",
        "aerial creatures, electricity-using"
        " creatures, and air elementals",
        "acid-using or poison-using"
        " creatures",
        "metallic or regenerating creatures" };
      if (i < 0) i = 0; if (i > 6) i = 6;
      return k[i]; }

// When drawn, an arrow of the appropriate color magically
// appears, nocked and ready; if no color is requested, or one
// already used is asked for, the next arrow in spectrum order
// appears.
inline bool uac5RainbowBowArrowAppearsNocked()
    { return true; }

inline bool uac5RainbowBowSpectrumFallback()
    { return true; }

// The bridge: a seven-hued bridge, as many feet wide as the
// cleric has levels; it bears as much weight, in hundreds of
// pounds, as the cleric has levels.
inline bool uac5RainbowBridgeSevenHued()
    { return true; }

inline bool uac5RainbowBridgeWidthFeetPerLevel()
    { return true; }

inline bool uac5RainbowBridgeLoadHundredsPerLevel()
    { return true; }

// At least 20 feet long, up to 120 feet per the caster's
// desire (the inch/degree marks are OCR noise for feet).
inline int uac5RainbowBridgeMinLengthFeet()
    { return 20; }

inline int uac5RainbowBridgeMaxLengthFeet()
    { return 120; }

// The garbled tail decoded: the bridge lasts for the length
// of the spell or until ordered out of existence by the
// caster; the fragment region stays a hole.
inline bool uac5RainbowBridgeLastsSpellLength()
    { return true; }

inline bool uac5RainbowBridgeOrderedOutOfExistence()
    { return true; }

inline bool uac5RainbowBridgeTailFragmentLost()
    { return true; }

// The elevator: carries the caster and all within a 10-foot
// radius skyward, in a path arching upward to any altitude,
// then down again if desired.
inline int uac5RainbowElevatorRadiusFeet()
    { return 10; }

inline bool uac5RainbowElevatorArcPath()
    { return true; }

// Care must be taken to reach a place of safety before the
// duration expires, or the elevator disappears and leaves
// those on it with no support.
inline bool uac5RainbowElevatorDangerOnExpiry()
    { return true; }

// Movement along the elevator is at rate 12; the arc of the
// rainbow trails out 12 behind those traveling upon it.
inline int uac5RainbowElevatorRateInches()
    { return 12; }

inline int uac5RainbowElevatorTrailInches()
    { return 12; }

// The flagon: swirls and condenses into a seven-colored
// vessel containing seven measures of pure water; each poured
// measure mixes one hue into a magical draught; unused
// measures and the container disappear at expiration.
inline bool uac5RainbowFlagonSevenColored()
    { return true; }

inline int uac5RainbowFlagonMeasures()
    { return 7; }

inline bool uac5RainbowFlagonUnusedDisappear()
    { return true; }

inline int uac5RainbowFlagonDraughtCount()
    { return 7; }

inline const char* uac5RainbowFlagonDraughtColor(int i)
    { static const char* const k[7] = {
        "red", "orange", "yellow", "green",
        "blue", "indigo", "violet" };
      if (i < 0) i = 0; if (i > 6) i = 6;
      return k[i]; }

inline const char* uac5RainbowFlagonDraughtEffect(int i)
    { static const char* const k[7] = {
        "cure light wounds", "resist fire",
        "cure blindness", "slow poison",
        "cure disease", "resist cold",
        "remove paralysis" };
      if (i < 0) i = 0; if (i > 6) i = 6;
      return k[i]; }

// Each draught acts as if the spell had been cast by a cleric
// of 12th level; the effects persist after the duration of
// the rainbow spell expires.
inline int uac5RainbowFlagonCasterLevel()
    { return 12; }

inline bool uac5RainbowFlagonEffectsPersist()
    { return true; }

// The material: the holy/unholy symbol and a vial of
// holy/unholy water; without a rainbow in the vicinity, a
// diamond of not less than 1,000 gp value, prepared by the
// cleric when in sight of a rainbow by bless and prayer
// spells upon the gem; only the holy symbol remains after
// casting.
inline bool uac5RainbowMaterialSymbolAndVial()
    { return true; }

inline int uac5RainbowDiamondMinValueGP()
    { return 1000; }

inline bool uac5RainbowDiamondNeedsBlessPrayer()
    { return true; }

inline bool uac5RainbowOnlySymbolRemains()
    { return true; }

// ---- spike stones (Alteration/Enchantment), p. 41 ----
inline const char* uac5SpikeStonesName()
    { return "Spike Stones (Alteration/Enchantment)"; }

inline bool uac5SpikeStonesComponentsVSM()
    { return true; }

inline int uac5SpikeStonesCastingTimeSegments()
    { return 6; }

inline int uac5SpikeStonesRangeInches()
    { return 3; }

inline bool uac5SpikeStonesSaveNone()
    { return true; }

inline int uac5SpikeStonesDurationTurnsMin()
    { return 3; }

inline int uac5SpikeStonesDurationTurnsMax()
    { return 12; }

inline int uac5SpikeStonesDurationTurnsPerLevel()
    { return 1; }

// The area: 1 square inch per level, 1 spike per square foot.
inline int uac5SpikeStonesAoeSquareInchesPerLevel()
    { return 1; }

inline int uac5SpikeStonesSpikesPerSquareFoot()
    { return 1; }

// Rock shapes itself into long, sharp points that tend to
// blend into the background; effective on both natural rock
// and worked stone; serves to impede progress or inflict
// damage.
inline bool uac5SpikeStonesNaturalAndWorked()
    { return true; }

inline bool uac5SpikeStonesImpedesOrDamages()
    { return true; }

// If an area is carefully observed, each observer is 25%
// likely to notice the sharp points.
inline int uac5SpikeStonesNoticeChancePct()
    { return 25; }

// Each spike stone that hits inflicts 1-4 points; success is
// determined as if the caster were actually engaging in
// combat.
inline int uac5SpikeStonesDamageMin()
    { return 1; }

inline int uac5SpikeStonesDamageMax()
    { return 4; }

inline bool uac5SpikeStonesAttackAsCaster()
    { return true; }

// Those entering are attacked immediately upon setting foot
// in the area and upon each step thereafter; the initial
// step reveals the problem only if the initial attack
// succeeds.
inline bool uac5SpikeStonesAttackOnEntryAndSteps()
    { return true; }

inline bool uac5SpikeStonesInitialStepAlertsOnlyOnHit()
    { return true; }

// Charging or running victims suffer 2 attacks per inch of
// movement rate over the area after the initial damage, before
// being able to halt; others suffer 1 additional check.
inline int uac5SpikeStonesChargeAttacksPerInch()
    { return 2; }

inline int uac5SpikeStonesOthersExtraChecks()
    { return 1; }

// Falling into an affected pit: 6 attack-like checks, each at
// +2 "to hit" per 10 feet fallen and +2 damage per 10 feet,
// spike damage in addition to falling damage.
inline int uac5SpikeStonesPitChecks()
    { return 6; }

inline int uac5SpikeStonesPitToHitBonusPer10ft()
    { return 2; }

inline int uac5SpikeStonesPitDamageBonusPer10ft()
    { return 2; }

inline bool uac5SpikeStonesDamageInAdditionToFalling()
    { return true; }

// The material: four tiny stalactites.
inline bool uac5SpikeStonesMaterialStalactites()
    { return true; }

inline int uac5SpikeStonesStalactiteCount()
    { return 4; }

// The R341 continued table: the 5th-level column prints seven
// fragments (Commune, Cure Critical Wounds, Dispel Evil,
// Magic Font, Plane Shift, Spike Growth, True Seeing) - magic
// font is the one name of this round that seam-checks; the
// rest pin from the prose alone.
inline bool uac5MagicFontSeamChecks()
    { return true; }

inline bool uac5SpellsPinFromProse()
    { return true; }

}   // namespace rules
