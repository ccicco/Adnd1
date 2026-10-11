// ===========================================================================
// Adnd1 - rules/uamuspells2.h
// The UA NEW MAGIC-USER SPELLS (pp. 51-52) pins, R357: the
// 2nd-level spell descriptions - bind, deeppockets, flaming
// sphere, irritation, know alignment, the Melf acid arrow,
// preserve, protection from cantrips, the Tasha laughter,
// vocalize, whip and zephyr.
//
// Pin-era pattern (R322): pinned data only - no engine site
// exists.
//
// JUDGMENTs (the decode method):
//   - the digit-garble family (the R343 precedent): the
//     casting-time and duration 7s decode as 1 - the
//     deeppockets "7 turn" as 1 turn; the know alignment
//     "7 round" and "7 round/level" as 1 round and 1
//     round per level; the vocalize "7 round" as 1 round;
//     the zephyr "7 segment" as 1 segment; the flaming
//     sphere "7\"" range as 1 inch, corroborated by the
//     prose (the globe appears up to 1" distant).
//   - the deeppockets name header is lost entirely - no
//     header line prints between the bind tail and the
//     scrambled stat block; the name pins as Deeppockets
//     from the gap item list and the prose ("The
//     deeppockets spell then makes...").
//   - the protection from cantrips header prints only
//     "From Cantrips" - the "Protection" head is lost;
//     the name pins from the gap item list.
//   - the whip level cell is lost in the interleave; the
//     spell pins as 2nd level from the section heading.
//   - the preserve area-of-effect cell loses its leading
//     number - only "cu. ft. per level of caster" pins;
//     a hole pending the PDF.
//   - the know alignment range cell prints empty and the
//     components cell truncates at "V," - holes; the
//     spell is reversible and same as the 2nd-level
//     clerical (a PHB spell - no UA pin to seam-check).
//   - the zephyr casting-time cell prints "2" with the
//     unit lost (the whip block prints the split "2" +
//     "segments"); the 2 pins, decoded as segments with
//     doubt pending the PDF. The zephyr area path length
//     prints a garbled fraction - flagged pending the
//     PDF.
//   - the degree-mark family: the foot marks print as
//     degrees - the bind "50 degrees" as 50 feet and 5
//     feet per level; the flaming sphere barrier as 4
//     feet; the Melf range "3 degrees" as 3 inches; the
//     Tasha range "5 degrees" as 5 inches.
//   - the deeppockets components cell garbles: "V, S
//     [section-mark], M" - the mark decodes as S.
//   - interleave garbles pinned verbatim with flags:
//     the bind "as atrip line" [sic]; the flaming
//     sphere "atarate of save" sequence; the preserve
//     "il effectual sled" opener; the protection
//     "creatures that trip she" sequence; the vocalize
//     "speli(s)" [sic]; the whip split casting cell.
//   - the R342 table seam: the MU 2nd-level table prints
//     30 names - eight of the twelve new spells appear
//     there (bind, irritation, know alignment, the Melf
//     arrow, preserve, the Tasha laughter, whip, zephyr);
//     deeppockets, flaming sphere, protection from
//     cantrips and vocalize do not.
//
// OCR holes (the item stays open - the 3rd through 9th
// levels pin in later rounds; these stay pending the PDF):
// the preserve area number; the know alignment range;
// the zephyr casting unit and path fraction; the four
// absent table names.
// ===========================================================================

#pragma once

namespace rules {

// ---- bind (Alteration/Enchantment), p. 51 ----
inline const char* uam2BindName()
    { return "Bind (Alteration/Enchantment)"; }

inline int uam2BindLevel()
    { return 2; }

inline int uam2BindRangeInches()
    { return 3; }

inline int uam2BindDurationRoundsPerLevel()
    { return 1; }

inline bool uam2BindAoeSpecial()
    { return true; }

inline bool uam2BindComponentsVSM()
    { return true; }

inline int uam2BindCastingTimeSegments()
    { return 2; }

inline bool uam2BindSaveNone()
    { return true; }

// Any ropelike object of non-living material - string,
// yarn, cord, line, rope, or even a cable.
inline bool uam2BindRopelikeNonLiving()
    { return true; }

inline bool uam2BindBehavesAsOrdered()
    { return true; }

// About 50 feet of normal 1-inch-diameter rope, plus 5
// feet per level of the caster (the degree-mark family).
inline int uam2BindBaseFeet()
    { return 50; }

inline int uam2BindFeetPerLevel()
    { return 5; }

// Reduce length proportionately when diameter
// increases; increase by 50 percent when halved.
inline bool uam2BindReduceWithDiameter()
    { return true; }

inline int uam2BindHalvingBonusPct()
    { return 50; }

// The commands: Coil, Coil & Knot, Loop, Loop & Knot,
// Tie & Knot, and the reverses of all of the above.
inline bool uam2BindCommandsCoilLoopTie()
    { return true; }

inline bool uam2BindReversesAvailable()
    { return true; }

// The rope must be within about 1 foot of any object to
// respond - it must usually be thrown or hurled nearby.
inline int uam2BindRespondWithinFeet()
    { return 1; }

inline bool uam2BindUsuallyThrown()
    { return true; }

// A creature affected by the object interacts with it as
// normal; the creature hold overrides the dweomer.
inline bool uam2BindCreatureHoldOverrides()
    { return true; }

// The rope takes 2 points of slashing damage before
// breaking.
inline int uam2BindSlashingDamageToBreak()
    { return 2; }

// No garrot use; a trip line [sic] or an entangle as the
// druid spell against a single opponent.
inline bool uam2BindNoGarrotUse()
    { return true; }

inline bool uam2BindTripLineOrEntangle()
    { return true; }

// The dweomer grants no magic beyond obeying commands
// (cf. rope of climbing, rope of entanglement).
inline bool uam2BindNoMagicBeyondCommands()
    { return true; }

// ---- deeppockets, p. 51 ----
// The name header is lost entirely; the name pins from
// the gap item list and the prose.
inline const char* uam2DeeppocketsName()
    { return "Deeppockets"; }

inline bool uam2DeeppocketsNameHeaderLost()
    { return true; }

// The components cell garbles: "V, [section], M" - the
// mark decodes as S.
inline bool uam2DeeppocketsComponentsGarbled()
    { return true; }

inline int uam2DeeppocketsLevel()
    { return 2; }

// The casting time prints "7 turn" - the family decodes
// 1 turn.
inline int uam2DeeppocketsCastingTimeTurns()
    { return 1; }

inline bool uam2DeeppocketsRangeTouch()
    { return true; }

inline bool uam2DeeppocketsSaveNone()
    { return true; }

inline int uam2DeeppocketsDurationTurnsBase()
    { return 24; }

inline int uam2DeeppocketsDurationTurnsPerLevel()
    { return 6; }

inline bool uam2DeeppocketsAoeOneGarment()
    { return true; }

// The garment: finely sewn, high-quality material of at
// least 300 gp value; one dozen pockets minimum.
inline int uam2DeeppocketsGarmentMinGp()
    { return 300; }

inline int uam2DeeppocketsMinPockets()
    { return 12; }

// One pocket holds 1,000 gp of weight (5 cubic feet) as
// if only 100 gp, with no discernible bulge.
inline int uam2DeeppocketsSpecialPocketGp()
    { return 1000; }

inline int uam2DeeppocketsSpecialPocketCuFt()
    { return 5; }

inline int uam2DeeppocketsAsIfGp()
    { return 100; }

inline bool uam2DeeppocketsNoBulge()
    { return true; }

// The alternative: 10 pockets of 100 gp weight each, 1
// cubic foot each (the leading 1 lost in the cell).
inline int uam2DeeppocketsAltPocketCount()
    { return 10; }

inline int uam2DeeppocketsAltPocketGp()
    { return 100; }

inline bool uam2DeeppocketsAltVolumeNumberLost()
    { return true; }

// The 100-pocket garment (1,000 gp minimum cost): 100
// pockets of 10 gp weight each, a fraction of a cubic
// foot each (the fraction garbles).
inline int uam2DeeppocketsHundredPocketGarmentGp()
    { return 1000; }

inline int uam2DeeppocketsHundredPocketCount()
    { return 100; }

inline int uam2DeeppocketsHundredPocketGp()
    { return 10; }

inline bool uam2DeeppocketsHundredPocketFractionGarbled()
    { return true; }

// On expiry with material inside, or on dispel: the
// wearer saves versus spell; failure sends the material
// from extra-dimensional to astral space - lost forever;
// success drops it around the wearer, suddenly and
// totally, to the ground.
inline bool uam2DeeppocketsExpirySaveVsSpell()
    { return true; }

inline bool uam2DeeppocketsFailAstralLostForever()
    { return true; }

inline bool uam2DeeppocketsSuccessAppearsAndFalls()
    { return true; }

// The materials: a tiny golden needle and a strip of
// fine cloth given a half-twist and fastened at the
// ends.
inline bool uam2DeeppocketsMaterialGoldenNeedle()
    { return true; }

inline bool uam2DeeppocketsMaterialClothHalfTwist()
    { return true; }

// ---- flaming sphere (Alteration/Evocation), p. 51 ----
inline const char* uam2FlamingSphereName()
    { return "Flaming Sphere (Alteration/Evocation)"; }

inline int uam2FlamingSphereLevel()
    { return 2; }

// The range cell prints "7\"" - the family decodes 1
// inch, corroborated by the prose (up to 1" distant).
inline int uam2FlamingSphereRangeInches()
    { return 1; }

inline bool uam2FlamingSphereRangeGarbleDecoded()
    { return true; }

inline int uam2FlamingSphereCastingTimeSegments()
    { return 2; }

inline bool uam2FlamingSphereSaveNegates()
    { return true; }

inline int uam2FlamingSphereDurationRoundsPerLevel()
    { return 1; }

// The area of effect: a 6-foot diameter sphere.
inline int uam2FlamingSphereDiameterFeet()
    { return 6; }

inline bool uam2FlamingSphereComponentsVSM()
    { return true; }

// A burning globe of normal-type fire comes into being
// up to 1 inch distant from the caster.
inline int uam2FlamingSphereAppearsWithinInches()
    { return 1; }

// The sphere rolls in the pointed direction, even
// uphill, rolling over low barriers not over 4 feet
// tall.
inline bool uam2FlamingSphereRollsAsPointed()
    { return true; }

inline int uam2FlamingSphereBarrierMaxFeet()
    { return 4; }

// Flammable substances are set afire by contact.
inline bool uam2FlamingSphereSetsFlammablesAfire()
    { return true; }

// Creatures struck suffer 2-8 fire damage; the sphere
// moves at 1 inch per round as long as the caster points
// (the interleave garble decoded).
inline int uam2FlamingSphereDamageMin()
    { return 2; }

inline int uam2FlamingSphereDamageMax()
    { return 8; }

inline int uam2FlamingSphereMoveInchesPerRound()
    { return 1; }

inline bool uam2FlamingSphereInterleaveGarbleDecoded()
    { return true; }

// All creatures within a 5-foot radius of the center
// save versus spell or take the damage; success negates.
inline int uam2FlamingSphereBlastRadiusFeet()
    { return 5; }

// Otherwise the sphere merely stays at rest and flames;
// it is extinguished as any normal fire of its size.
inline bool uam2FlamingSphereRestsUnpointed()
    { return true; }

inline bool uam2FlamingSphereExtinguishedAsNormalFire()
    { return true; }

// The materials: a bit of tallow, a pinch of sulphur,
// and a dusting of powdered iron.
inline bool uam2FlamingSphereMaterialTallow()
    { return true; }

inline bool uam2FlamingSphereMaterialSulphur()
    { return true; }

inline bool uam2FlamingSphereMaterialPowderedIron()
    { return true; }

// ---- irritation (Alteration), p. 51 ----
inline const char* uam2IrritationName()
    { return "Irritation (Alteration)"; }

inline int uam2IrritationLevel()
    { return 2; }

inline int uam2IrritationRangeInchesPerLevel()
    { return 1; }

inline int uam2IrritationCastingTimeSegments()
    { return 2; }

inline bool uam2IrritationSaveNegates()
    { return true; }

inline bool uam2IrritationDurationSpecial()
    { return true; }

inline bool uam2IrritationAoeOneCreature()
    { return true; }

inline bool uam2IrritationComponentsVSM()
    { return true; }

// The spell affects the epidermis; very thick or
// insensitive skins (buffalo, elephants, scaled
// creatures) are basically unaffected.
inline bool uam2IrritationAffectsEpidermis()
    { return true; }

inline bool uam2IrritationThickSkinnedUnaffected()
    { return true; }

// Two versions cast from the standard preparation.
inline bool uam2IrritationTwoVersions()
    { return true; }

// Itching: an instant itching sensation; if 5-8
// segments are not immediately spent scratching, the
// next 3 rounds squirm - armor class worse by 4, to-hit
// by 2; spells ruined the initial round only.
inline int uam2IrritationScratchSegmentsMin()
    { return 5; }

inline int uam2IrritationScratchSegmentsMax()
    { return 8; }

inline int uam2IrritationSquirmRounds()
    { return 3; }

inline int uam2IrritationAcWorseBy()
    { return 4; }

inline int uam2IrritationToHitWorseBy()
    { return 2; }

inline bool uam2IrritationSpellsRuinedFirstRoundOnly()
    { return true; }

// Rash: nothing for 1-4 rounds, then red welts faintly
// itching; persists until cure disease or dispel magic;
// comeliness -1 per day to a maximum of 4, dexterity -1
// after one week; symptoms vanish on removal.
inline int uam2IrritationRashLatencyMinRounds()
    { return 1; }

inline int uam2IrritationRashLatencyMaxRounds()
    { return 4; }

inline bool uam2IrritationRashPersistsUntilCureOrDispel()
    { return true; }

inline int uam2IrritationRashComelinessPerDay()
    { return 1; }

inline int uam2IrritationRashComelinessMaxLoss()
    { return 4; }

inline int uam2IrritationRashDexLossAfterWeek()
    { return 1; }

inline bool uam2IrritationRashVanishesOnRemoval()
    { return true; }

// The material: powdered leaf from poison ivy, oak, or
// sumac.
inline bool uam2IrritationMaterialPoisonLeaf()
    { return true; }

// ---- know alignment (Divination), reversible, p. 51 ----
inline const char* uam2KnowAlignmentName()
    { return "Know Alignment (Divination)"; }

inline int uam2KnowAlignmentLevel()
    { return 2; }

inline bool uam2KnowAlignmentReversible()
    { return true; }

// The components cell truncates at "V," - a hole.
inline bool uam2KnowAlignmentComponentsCellLost()
    { return true; }

// The casting time prints "7 round" - the family decodes
// 1 round.
inline int uam2KnowAlignmentCastingTimeRounds()
    { return 1; }

// The range cell prints empty - a hole.
inline bool uam2KnowAlignmentRangeCellLost()
    { return true; }

inline bool uam2KnowAlignmentSaveNone()
    { return true; }

// The duration prints "7 round/level" - the family
// decodes 1 round per level.
inline int uam2KnowAlignmentDurationRoundsPerLevel()
    { return 1; }

// One creature per 2 rounds may be scried.
inline int uam2KnowAlignmentAoeCreaturesPer2Rounds()
    { return 1; }

// Except as noted, the spell is the same as the
// 2nd-level clerical spell of the same name (a PHB
// spell - no UA pin to seam-check).
inline bool uam2KnowAlignmentSameAsClerical()
    { return true; }

// A target scried for only one round reveals only its
// alignment ethic (law/chaos).
inline bool uam2KnowAlignmentOneRoundEthicOnly()
    { return true; }

// ---- Melf's acid arrow (Evocation), p. 51 ----
inline const char* uam2AcidArrowName()
    { return "Melf's Acid Arrow (Evocation)"; }

inline int uam2AcidArrowLevel()
    { return 2; }

inline int uam2AcidArrowRangeInches()
    { return 3; }

inline bool uam2AcidArrowDurationSpecial()
    { return true; }

inline bool uam2AcidArrowAoeOneTarget()
    { return true; }

inline bool uam2AcidArrowComponentsVSM()
    { return true; }

inline int uam2AcidArrowCastingTimeSegments()
    { return 4; }

inline bool uam2AcidArrowSaveSpecial()
    { return true; }

// The arrow speeds to its target as if fired from the
// bow of a fighter of the caster level.
inline bool uam2AcidArrowSpeedsAsFighterBow()
    { return true; }

// The arrow equals a +1 weapon for hit determination.
inline int uam2AcidArrowPlusForHit()
    { return 1; }

// A hit may damage even a target not normally harmed by
// a +1 weapon - the acid.
inline bool uam2AcidArrowAcidBypassesPlusOneImmunity()
    { return true; }

// The arrow itself does 2-5 points of damage.
inline int uam2AcidArrowDamageMin()
    { return 2; }

inline int uam2AcidArrowDamageMax()
    { return 5; }

// The gushing acid: an 8-ounce volume, 2-8 hit points
// damage, plus item saving throw; splash does not apply.
inline int uam2AcidArrowAcidVolumeOunces()
    { return 8; }

inline int uam2AcidArrowAcidDamageMin()
    { return 2; }

inline int uam2AcidArrowAcidDamageMax()
    { return 8; }

inline bool uam2AcidArrowItemSavingThrowApplies()
    { return true; }

inline bool uam2AcidArrowNoSplash()
    { return true; }

// The acid strength increases by one round of damage
// per 3 levels above the 3rd - two rounds of damage
// from a 4th-6th level caster, unless neutralized.
inline int uam2AcidArrowExtraRoundsPer3Levels()
    { return 1; }

inline int uam2AcidArrowExtraRoundsFromLevel()
    { return 4; }

inline bool uam2AcidArrowNeutralizationStops()
    { return true; }

// The materials: a dart, powdered rhubarb leaf, and an
// adder stomach.
inline bool uam2AcidArrowMaterialDart()
    { return true; }

inline bool uam2AcidArrowMaterialRhubarbLeaf()
    { return true; }

inline bool uam2AcidArrowMaterialAdderStomach()
    { return true; }

// ---- preserve (Abjuration), p. 51 ----
inline const char* uam2PreserveName()
    { return "Preserve (Abjuration)"; }

inline int uam2PreserveLevel()
    { return 2; }

inline int uam2PreserveCastingTimeRounds()
    { return 2; }

inline bool uam2PreserveRangeTouch()
    { return true; }

inline bool uam2PreserveSaveNone()
    { return true; }

inline bool uam2PreserveDurationPermanent()
    { return true; }

// The area cell loses its leading number - only cubic
// feet per level pins; a hole pending the PDF.
inline bool uam2PreserveAoeNumberLost()
    { return true; }

inline bool uam2PreserveAoeCuFtPerLevel()
    { return true; }

inline bool uam2PreserveComponentsVSM()
    { return true; }

// The spell retains an item fresh and whole until
// needed in a spell; the heavily garbled opener decodes
// as ineffective for materials such as mistletoe and
// holly berries, which must be gathered periodically.
inline bool uam2PreserveRetainsItemFresh()
    { return true; }

inline bool uam2PreserveIneffectiveForFreshGather()
    { return true; }

inline bool uam2PreserveOpenerGarbleDecoded()
    { return true; }

// The material ladder by caster level: hard, dry
// material 2nd-4th; soft, wet material 5th-7th;
// semi-liquid and liquid 8th and up.
inline int uam2PreserveHardDryMinLevel()
    { return 2; }

inline int uam2PreserveHardDryMaxLevel()
    { return 4; }

inline int uam2PreserveSoftWetMinLevel()
    { return 5; }

inline int uam2PreserveSoftWetMaxLevel()
    { return 7; }

inline int uam2PreserveLiquidMinLevel()
    { return 8; }

// A container is necessary only where a high degree of
// moisture is involved.
inline bool uam2PreserveContainerOnlyForMoisture()
    { return true; }

// The materials: a pinch of dust, a bit of resin (or
// amber), and a drop of brandy.
inline bool uam2PreserveMaterialDust()
    { return true; }

inline bool uam2PreserveMaterialResinOrAmber()
    { return true; }

inline bool uam2PreserveMaterialBrandy()
    { return true; }

// ---- protection from cantrips, p. 52 ----
// The header prints only "From Cantrips" - the
// Protection head is lost; the name pins from the gap
// item list.
inline const char* uam2PfcName()
    { return "Protection From Cantrips"; }

inline bool uam2PfcNameHeaderGarbled()
    { return true; }

inline int uam2PfcLevel()
    { return 2; }

inline bool uam2PfcRangeTouch()
    { return true; }

inline int uam2PfcCastingTimeSegments()
    { return 2; }

// The save cell prints "None or Neg."
inline bool uam2PfcSaveNoneOrNegates()
    { return true; }

inline int uam2PfcDurationDaysPerLevel()
    { return 1; }

// The area of effect: one creature or object; the
// components cell truncates at "V," - a hole.
inline bool uam2PfcAoeOneCreatureOrObject()
    { return true; }

inline bool uam2PfcComponentsCellLost()
    { return true; }

// The spell grants immunity to cantrips cast by other
// magic-users or creatures; the protection prose
// interleaves (the "creatures that trip she" garble).
inline bool uam2PfcImmunityToCantrips()
    { return true; }

inline bool uam2PfcProseInterleaveDecoded()
    { return true; }

// It protects the caster, or one item or person - a
// spell book or a drawer of spell components.
inline bool uam2PfcProtectsCasterOrItem()
    { return true; }

// Any cantrip cast against the protected person or item
// dissipates with an audible popping sound.
inline bool uam2PfcCantripDissipatesWithPop()
    { return true; }

// The classic use: a magic-user with mischievous
// apprentices, who must clean or shine with elbow
// grease instead of magic.
inline bool uam2PfcMischievousApprenticesUse()
    { return true; }

// An unwilling target must be touched via a to-hit
// roll and is allowed a save versus spell to escape.
inline bool uam2PfcUnwillingToHitAndSave()
    { return true; }

// ---- Tasha's hideous laughter (Evocation), p. 52 ----
inline const char* uam2TashaName()
    { return "Tasha's Uncontrollable Hideous Laughter (Evocation)"; }

inline int uam2TashaLevel()
    { return 2; }

inline int uam2TashaCastingTimeSegments()
    { return 2; }

inline int uam2TashaRangeInches()
    { return 5; }

inline bool uam2TashaSaveSpecial()
    { return true; }

inline int uam2TashaDurationRounds()
    { return 1; }

inline bool uam2TashaAoeOneCreature()
    { return true; }

inline bool uam2TashaComponentsVSM()
    { return true; }

// The subject perceives everything as hilariously
// funny; the effect is not immediate - a slight
// tingling the round the dweomer is placed.
inline bool uam2TashaEverythingHilarious()
    { return true; }

inline bool uam2TashaTinglingFirstRound()
    { return true; }

// The next round: smiling, chuckling, tittering,
// snickering, into gales of hideous laughter (the
// interleave garble decoded).
inline bool uam2TashaLaughterSequenceDecoded()
    { return true; }

// The mirth lasts a single round; the next round
// regains feet; -2 strength (or -2 to hit and damage)
// on the 3rd and 4th rounds.
inline bool uam2TashaNextRoundRegainFeet()
    { return true; }

inline int uam2TashaMinusTwoRounds()
    { return 2; }

inline int uam2TashaPenaltyRounds()
    { return 2; }

// A successful save versus spell negates; the save
// depends on intelligence: 3 or less totally
// unaffected; 4-8 save at -6; 9-12 at -4; 13-15 at
// -2; 16 or greater normal.
inline bool uam2TashaSaveNegates()
    { return true; }

inline int uam2TashaUnaffectedIntMax()
    { return 3; }

inline int uam2TashaInt4to8SaveMod()
    { return -6; }

inline int uam2TashaInt9to12SaveMod()
    { return -4; }

inline int uam2TashaInt13to15SaveMod()
    { return -2; }

inline bool uam2TashaInt16PlusNormalSave()
    { return true; }

// The materials: a small feather waved in one hand, a
// tiny wooden paddle tapped against the caster
// posterior, and a minute tort hurled at the subject.
inline bool uam2TashaMaterialFeather()
    { return true; }

inline bool uam2TashaMaterialPaddle()
    { return true; }

inline bool uam2TashaMaterialTort()
    { return true; }

// ---- vocalize (Alteration), p. 52 ----
inline const char* uam2VocalizeName()
    { return "Vocalize (Alteration)"; }

// The components print S, M - no verbal component.
inline bool uam2VocalizeComponentsSM()
    { return true; }

inline int uam2VocalizeLevel()
    { return 2; }

inline bool uam2VocalizeRangeTouch()
    { return true; }

// The casting time prints "7 round" - the family
// decodes 1 round.
inline int uam2VocalizeCastingTimeRounds()
    { return 1; }

inline bool uam2VocalizeSaveNone()
    { return true; }

inline int uam2VocalizeDurationRounds()
    { return 5; }

inline bool uam2VocalizeAoeOneSpellCastingCreature()
    { return true; }

// The recipient casts verbal spells silently, so long
// as the casting takes place entirely within the
// vocalize duration (the "speli(s)" [sic] garble).
inline bool uam2VocalizeCastsSilently()
    { return true; }

inline bool uam2VocalizeWithinDurationOnly()
    { return true; }

inline bool uam2VocalizeSpeliGarble()
    { return true; }

// Of great use where quiet is desired, or under a
// silence spell; it does not negate the silence but
// offsets it for subsequent spell casting - audible
// effects are masked while the silence remains.
inline bool uam2VocalizeUsefulUnderSilence()
    { return true; }

inline bool uam2VocalizeOffsetsNotNegates()
    { return true; }

inline bool uam2VocalizeMasksAudibleEffects()
    { return true; }

// The interleave garble: no vocal communication from
// within the silence, and no information transmitted
// back to the caster.
inline bool uam2VocalizeNoInfoBackToCaster()
    { return true; }

// The material: a bell without a clapper, or else a
// jailbird's tongue.
inline bool uam2VocalizeMaterialBellNoClapper()
    { return true; }

inline bool uam2VocalizeMaterialJailbirdsTongue()
    { return true; }

// ---- whip (Evocation), p. 52 ----
inline const char* uam2WhipName()
    { return "Whip (Evocation)"; }

// The level cell is lost in the interleave; the spell
// pins as 2nd level from the section heading.
inline int uam2WhipLevel()
    { return 2; }

inline bool uam2WhipLevelCellLost()
    { return true; }

inline int uam2WhipDurationRoundsPerLevel()
    { return 1; }

inline bool uam2WhipAoeSpecial()
    { return true; }

inline bool uam2WhipComponentsVSM()
    { return true; }

// The casting cell prints "2" and "segments" on split
// lines - the interleave decoded.
inline int uam2WhipCastingTimeSegments()
    { return 2; }

inline bool uam2WhipCastingCellSplitDecoded()
    { return true; }

inline bool uam2WhipSaveSpecial()
    { return true; }

// The caster creates a material whip-like substance up
// to 1 inch distant, wielded by moving the hand as if
// holding an actual whip.
inline int uam2WhipReachInches()
    { return 1; }

inline bool uam2WhipWieldedByHandMovement()
    { return true; }

// The lash makes both a whistling crack and an actual
// strike each turn.
inline bool uam2WhipCrackAndStrikeEachTurn()
    { return true; }

// The sound alone keeps normal animals at bay unless
// they save versus spell.
inline bool uam2WhipSoundKeepsAnimalsAtBay()
    { return true; }

// A struck animal (normal hit die roll) saves versus
// spell at -1 to -4 or slinks away, not returning for
// at least an hour; the whip does no actual damage.
inline int uam2WhipAnimalSaveModMin()
    { return -1; }

inline int uam2WhipAnimalSaveModMax()
    { return -4; }

inline int uam2WhipSlinkAwayHours()
    { return 1; }

inline bool uam2WhipNoActualDamage()
    { return true; }

// Creatures of intelligence above 3 are unaffected,
// nor giant-sized animals above bear-size, nor
// monsters.
inline int uam2WhipUnaffectedIntAbove()
    { return 3; }

inline bool uam2WhipGiantAboveBearSizeUnaffected()
    { return true; }

inline bool uam2WhipMonstersUnaffected()
    { return true; }

// In melee: a to-hit indicates the lash wrapped the
// opponent weapon; an edged weapon forces the whip to
// save versus crushing blow (13 or better), a non-edged
// versus normal blow (6 or better).
inline bool uam2WhipMeleeWrapsWeapon()
    { return true; }

inline int uam2WhipEdgedSaveVsCrushingBlow()
    { return 13; }

inline int uam2WhipNonEdgedSaveVsNormalBlow()
    { return 6; }

// Success tears the weapon from the hand unless the
// opponent succeeds on a save versus spell; the weapon
// is cast to the ground and takes 1 round to recover.
inline bool uam2WhipSuccessTearsFromHand()
    { return true; }

inline bool uam2WhipOpponentSaveKeepsWeapon()
    { return true; }

inline int uam2WhipWeaponRecoverRounds()
    { return 1; }

// The magic bonus of the target weapon penalizes the
// whip save; the magic resistance of the intended
// target must fail for a to-hit to be possible.
inline bool uam2WhipMagicBonusPenalizesSave()
    { return true; }

inline bool uam2WhipMagicResistanceMustFail()
    { return true; }

// The material: a small bit of silk braided so as to
// form a miniature whip.
inline bool uam2WhipMaterialSilkBraided()
    { return true; }

// ---- zephyr (Evocation), p. 52 ----
inline const char* uam2ZephyrName()
    { return "Zephyr (Evocation)"; }

// The components cell splits: "V, S," then "M".
inline bool uam2ZephyrComponentsVSM()
    { return true; }

inline bool uam2ZephyrComponentsCellSplit()
    { return true; }

inline int uam2ZephyrLevel()
    { return 2; }

inline int uam2ZephyrRangeZero()
    { return 0; }

// The casting cell prints "2" with the unit lost - a
// hole; decoded as segments with doubt pending the PDF.
inline int uam2ZephyrCastingTimeSegments()
    { return 2; }

inline bool uam2ZephyrCastingUnitLost()
    { return true; }

inline bool uam2ZephyrSaveNone()
    { return true; }

// The duration prints "7 segment" - the family decodes
// 1 segment.
inline int uam2ZephyrDurationSegments()
    { return 1; }

// The area: one path, a garbled fraction of an inch per
// level in length - flagged pending the PDF.
inline bool uam2ZephyrAoeOnePath()
    { return true; }

inline bool uam2ZephyrPathFractionGarbled()
    { return true; }

// A gentle draft moves from the caster in the faced
// direction, continuing until the maximum area of
// effect is reached.
inline bool uam2ZephyrDraftInFacedDirection()
    { return true; }

// The force causes small flames to waver and dance,
// fans larger flames hotter (+1 on damage dice, if
// applicable).
inline bool uam2ZephyrSmallFlamesWaver()
    { return true; }

inline int uam2ZephyrFanDamageBonus()
    { return 1; }

// It holds back moving clouds of vapors (such as a
// cloudkill) for 1 round.
inline int uam2ZephyrHoldVaporsRounds()
    { return 1; }

// It weakens fog cloud and wall of fog so as to halve
// their duration.
inline bool uam2ZephyrHalvesFogDuration()
    { return true; }

// It moves stagnant air, vapors, or poisonous gases
// backwards by 1 inch, halving duration and potency,
// unless renewed by some source.
inline int uam2ZephyrMoveGasesBackInches()
    { return 1; }

inline bool uam2ZephyrHalvesGasDurationAndPotency()
    { return true; }

inline bool uam2ZephyrUnlessRenewed()
    { return true; }

// The material: fine parchment, accordion-folded and
// tacked near the bottom with a pin or ivory or
// silver.
inline bool uam2ZephyrMaterialParchmentFolded()
    { return true; }

inline bool uam2ZephyrMaterialPinIvorySilver()
    { return true; }

}   // namespace rules
