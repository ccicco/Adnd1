#!/usr/bin/env python3
# R357: the UA NEW MAGIC-USER
# SPELLS pin round, the 2nd level
# (pp. 51-52) - bind, deeppockets
# (the lost name header), flaming
# sphere, irritation, know
# alignment, the Melf acid arrow,
# preserve, protection from
# cantrips, the Tasha laughter,
# vocalize, whip and zephyr. The
# digit-garble family decodes the
# 7s as 1. The R342 table seam
# pins 8 of 12 names. The item
# stays open (the 3rd-9th levels).
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

# ---- (a) the seed: the R355 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R356 landed 2026-10-11: commit',
    '  79cb0ce, census 283, the UA',
    '  new magic-user 1st level spells',
    '  pin round (rules/uamuspells1.h):',
    '  the ten spell descriptions',
    '  (alarm, armor, firewater,',
    '  grease, melt, mount,',
    '  precipitation seam-checking',
    '  the R343 clerical pin minus',
    '  the holy symbol, run, taunt,',
    '  wizard mark); the family',
    '  decodes the seven 7s as 1;',
    '  no 1st-level MU table seam',
    '  exists. GREEN on the first',
    '  run.',
])
s = rd(SD)
if 'R356 landed 2026-10-11' in s:
    already.append('seed: the R356 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R356 record')
s = rd(SD)
assert s.count('R356 landed 2026-10-11') == 1, 'a entry'
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

# ---- (b) NEW rules/uamuspells1.h ----
US = 'rules/uamuspells2.h'
if os.path.exists(US) and 'R357' in rd(US):
    already.append('uamuspells2.h: the pins')
else:
    HDR = r"""// ===========================================================================
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

}   // namespace rules"""
    clean(HDR, 78)
    wr(US, HDR + NL)
    applied.append('uamuspells2.h: the pins')
s = rd(US)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 260, 'b inline count'
assert s.count('R357') == 1, 'b round tag'
assert s.count('uam2BindName()') == 1, 'b bind fn'
assert s.count(
    'uam2ZephyrMaterialPinIvorySilver()'
    ) == 1, 'b ivory fn'
assert 'uastDruid' not in s, 'b no r341 ref'
assert 'uam1' not in s, 'b no r356 ref'
assert 'uac1' not in s, 'b no r343 ref'
assert 'uad' not in s, 'b no druid ref'
assert len(applied) + len(already) == 2, 'b count'

# ---- (c) the gap report: the note (the
# item STAYS OPEN - the 3rd-9th levels) ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'R357: the 2nd level pinned' in s:
    already.append('gap report: the note')
else:
    TAIL_OLD = NL.join([
        '        through 9th levels stay',
        '        open.',
        '- [ ] **The new illusionist spells**',
    ])
    assert s.count(TAIL_OLD) == 1, 'c tail'
    NOTE = NL.join([
        '      - R357: the 2nd level pinned',
        '        (rules/uamuspells2.h) - the',
        '        twelve spell descriptions',
        '        (bind, deeppockets behind',
        '        the lost name header,',
        '        flaming sphere, irritation',
        '        with the two versions, know',
        '        alignment reversible behind',
        '        the lost range cell, the',
        '        Melf acid arrow, preserve',
        '        behind the lost area number,',
        '        protection from cantrips',
        '        behind the From Cantrips',
        '        header garble, the Tasha',
        '        laughter with the',
        '        intelligence save ladder,',
        '        vocalize, whip behind the',
        '        lost level cell, zephyr);',
        '        the family decodes the',
        '        casting-time and duration',
        '        7s as 1; the R342 MU table',
        '        seam: eight of the twelve',
        '        names print there, the four',
        '        absent are noted; the 3rd',
        '        through 9th levels stay',
        '        open.',
    ])
    clean(NOTE, 57)
    s = s.replace(TAIL_OLD, NL.join([
        '        through 9th levels stay',
        '        open.',
        NOTE,
        '- [ ] **The new illusionist spells**',
    ]))
    wr(GP, s)
    applied.append('gap report: the note')
s = rd(GP)
assert s.count('R357: the 2nd level pinned') == 1, 'c note'
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
if 'R357 UA MU 2nd level spells pin audit' in s:
    already.append('regtest.cpp: the R357 audit')
else:
    INC_ANCH = (
        '#include "rules/uamuspells1.h"'
        '  // R356: the UA new magic-user'
        ' 1st level')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uamuspells2.h"'
        '  // R357: the UA new magic-user'
        ' 2nd level',
    ])
    AUD_ANCH = ('    // ---- R227: the wis mental'
                ' save wiring audit ----')
    AUDIT = r"""    // ---- R357: the UA new magic-user 2nd level spells pin audit ----
    // The UA NEW MAGIC-USER SPELLS (pp.
    // 51-52), the 2nd level - bind,
    // deeppockets (the lost name header),
    // flaming sphere, irritation, know
    // alignment, the Melf acid arrow,
    // preserve, protection from
    // cantrips, the Tasha laughter,
    // vocalize, whip and zephyr. The
    // family decodes the 7s as 1. The
    // R342 table seam pins 8 of 12;
    // the item stays open (the 3rd-9th
    // levels).
    {
        using namespace rules;
        int bad = 0;
        // U1: bind
            if (strcmp(uam2BindName(),
                "Bind (Alteration/Enchantment)") != 0) ++bad;
            if (uam2BindLevel() != 2) ++bad;
            if (uam2BindRangeInches() != 3) ++bad;
            if (uam2BindDurationRoundsPerLevel() != 1) ++bad;
            if (!uam2BindAoeSpecial()) ++bad;
            if (!uam2BindComponentsVSM()) ++bad;
            if (uam2BindCastingTimeSegments() != 2) ++bad;
            if (!uam2BindSaveNone()) ++bad;
            if (!uam2BindRopelikeNonLiving()) ++bad;
            if (!uam2BindBehavesAsOrdered()) ++bad;
            if (uam2BindBaseFeet() != 50) ++bad;
            if (uam2BindFeetPerLevel() != 5) ++bad;
            if (!uam2BindReduceWithDiameter()) ++bad;
            if (uam2BindHalvingBonusPct() != 50) ++bad;
            if (!uam2BindCommandsCoilLoopTie()) ++bad;
            if (!uam2BindReversesAvailable()) ++bad;
            if (uam2BindRespondWithinFeet() != 1) ++bad;
            if (!uam2BindUsuallyThrown()) ++bad;
            if (!uam2BindCreatureHoldOverrides()) ++bad;
            if (uam2BindSlashingDamageToBreak() != 2) ++bad;
            if (!uam2BindNoGarrotUse()) ++bad;
            if (!uam2BindTripLineOrEntangle()) ++bad;
            if (!uam2BindNoMagicBeyondCommands()) ++bad;
        // U2: deeppockets
            if (strcmp(uam2DeeppocketsName(), "Deeppockets") != 0) ++bad;
            if (!uam2DeeppocketsNameHeaderLost()) ++bad;
            if (!uam2DeeppocketsComponentsGarbled()) ++bad;
            if (uam2DeeppocketsLevel() != 2) ++bad;
            if (uam2DeeppocketsCastingTimeTurns() != 1) ++bad;
            if (!uam2DeeppocketsRangeTouch()) ++bad;
            if (!uam2DeeppocketsSaveNone()) ++bad;
            if (uam2DeeppocketsDurationTurnsBase() != 24) ++bad;
            if (uam2DeeppocketsDurationTurnsPerLevel() != 6) ++bad;
            if (!uam2DeeppocketsAoeOneGarment()) ++bad;
            if (uam2DeeppocketsGarmentMinGp() != 300) ++bad;
            if (uam2DeeppocketsMinPockets() != 12) ++bad;
            if (uam2DeeppocketsSpecialPocketGp() != 1000) ++bad;
            if (uam2DeeppocketsSpecialPocketCuFt() != 5) ++bad;
            if (uam2DeeppocketsAsIfGp() != 100) ++bad;
            if (!uam2DeeppocketsNoBulge()) ++bad;
            if (uam2DeeppocketsAltPocketCount() != 10) ++bad;
            if (uam2DeeppocketsAltPocketGp() != 100) ++bad;
            if (!uam2DeeppocketsAltVolumeNumberLost()) ++bad;
            if (uam2DeeppocketsHundredPocketGarmentGp() != 1000) ++bad;
            if (uam2DeeppocketsHundredPocketCount() != 100) ++bad;
            if (uam2DeeppocketsHundredPocketGp() != 10) ++bad;
            if (!uam2DeeppocketsHundredPocketFractionGarbled()) ++bad;
            if (!uam2DeeppocketsExpirySaveVsSpell()) ++bad;
            if (!uam2DeeppocketsFailAstralLostForever()) ++bad;
            if (!uam2DeeppocketsSuccessAppearsAndFalls()) ++bad;
            if (!uam2DeeppocketsMaterialGoldenNeedle()) ++bad;
            if (!uam2DeeppocketsMaterialClothHalfTwist()) ++bad;
        // U3: flaming sphere
            if (strcmp(uam2FlamingSphereName(),
                "Flaming Sphere (Alteration/Evocation)") != 0) ++bad;
            if (uam2FlamingSphereLevel() != 2) ++bad;
            if (uam2FlamingSphereRangeInches() != 1) ++bad;
            if (!uam2FlamingSphereRangeGarbleDecoded()) ++bad;
            if (uam2FlamingSphereCastingTimeSegments() != 2) ++bad;
            if (!uam2FlamingSphereSaveNegates()) ++bad;
            if (uam2FlamingSphereDurationRoundsPerLevel() != 1) ++bad;
            if (uam2FlamingSphereDiameterFeet() != 6) ++bad;
            if (!uam2FlamingSphereComponentsVSM()) ++bad;
            if (uam2FlamingSphereAppearsWithinInches() != 1) ++bad;
            if (!uam2FlamingSphereRollsAsPointed()) ++bad;
            if (uam2FlamingSphereBarrierMaxFeet() != 4) ++bad;
            if (!uam2FlamingSphereSetsFlammablesAfire()) ++bad;
            if (uam2FlamingSphereDamageMin() != 2) ++bad;
            if (uam2FlamingSphereDamageMax() != 8) ++bad;
            if (uam2FlamingSphereMoveInchesPerRound() != 1) ++bad;
            if (!uam2FlamingSphereInterleaveGarbleDecoded()) ++bad;
            if (uam2FlamingSphereBlastRadiusFeet() != 5) ++bad;
            if (!uam2FlamingSphereRestsUnpointed()) ++bad;
            if (!uam2FlamingSphereExtinguishedAsNormalFire()) ++bad;
            if (!uam2FlamingSphereMaterialTallow()) ++bad;
            if (!uam2FlamingSphereMaterialSulphur()) ++bad;
            if (!uam2FlamingSphereMaterialPowderedIron()) ++bad;
        // U4: irritation
            if (strcmp(uam2IrritationName(),
                "Irritation (Alteration)") != 0) ++bad;
            if (uam2IrritationLevel() != 2) ++bad;
            if (uam2IrritationRangeInchesPerLevel() != 1) ++bad;
            if (uam2IrritationCastingTimeSegments() != 2) ++bad;
            if (!uam2IrritationSaveNegates()) ++bad;
            if (!uam2IrritationDurationSpecial()) ++bad;
            if (!uam2IrritationAoeOneCreature()) ++bad;
            if (!uam2IrritationComponentsVSM()) ++bad;
            if (!uam2IrritationAffectsEpidermis()) ++bad;
            if (!uam2IrritationThickSkinnedUnaffected()) ++bad;
            if (!uam2IrritationTwoVersions()) ++bad;
            if (uam2IrritationScratchSegmentsMin() != 5) ++bad;
            if (uam2IrritationScratchSegmentsMax() != 8) ++bad;
            if (uam2IrritationSquirmRounds() != 3) ++bad;
            if (uam2IrritationAcWorseBy() != 4) ++bad;
            if (uam2IrritationToHitWorseBy() != 2) ++bad;
            if (!uam2IrritationSpellsRuinedFirstRoundOnly()) ++bad;
            if (uam2IrritationRashLatencyMinRounds() != 1) ++bad;
            if (uam2IrritationRashLatencyMaxRounds() != 4) ++bad;
            if (!uam2IrritationRashPersistsUntilCureOrDispel()) ++bad;
            if (uam2IrritationRashComelinessPerDay() != 1) ++bad;
            if (uam2IrritationRashComelinessMaxLoss() != 4) ++bad;
            if (uam2IrritationRashDexLossAfterWeek() != 1) ++bad;
            if (!uam2IrritationRashVanishesOnRemoval()) ++bad;
            if (!uam2IrritationMaterialPoisonLeaf()) ++bad;
        // U5: know alignment
            if (strcmp(uam2KnowAlignmentName(),
                "Know Alignment (Divination)") != 0) ++bad;
            if (uam2KnowAlignmentLevel() != 2) ++bad;
            if (!uam2KnowAlignmentReversible()) ++bad;
            if (!uam2KnowAlignmentComponentsCellLost()) ++bad;
            if (uam2KnowAlignmentCastingTimeRounds() != 1) ++bad;
            if (!uam2KnowAlignmentRangeCellLost()) ++bad;
            if (!uam2KnowAlignmentSaveNone()) ++bad;
            if (uam2KnowAlignmentDurationRoundsPerLevel() != 1) ++bad;
            if (uam2KnowAlignmentAoeCreaturesPer2Rounds() != 1) ++bad;
            if (!uam2KnowAlignmentSameAsClerical()) ++bad;
            if (!uam2KnowAlignmentOneRoundEthicOnly()) ++bad;
        // U6: the Melf acid arrow
            if (strcmp(uam2AcidArrowName(),
                "Melf's Acid Arrow (Evocation)") != 0) ++bad;
            if (uam2AcidArrowLevel() != 2) ++bad;
            if (uam2AcidArrowRangeInches() != 3) ++bad;
            if (!uam2AcidArrowDurationSpecial()) ++bad;
            if (!uam2AcidArrowAoeOneTarget()) ++bad;
            if (!uam2AcidArrowComponentsVSM()) ++bad;
            if (uam2AcidArrowCastingTimeSegments() != 4) ++bad;
            if (!uam2AcidArrowSaveSpecial()) ++bad;
            if (!uam2AcidArrowSpeedsAsFighterBow()) ++bad;
            if (uam2AcidArrowPlusForHit() != 1) ++bad;
            if (!uam2AcidArrowAcidBypassesPlusOneImmunity()) ++bad;
            if (uam2AcidArrowDamageMin() != 2) ++bad;
            if (uam2AcidArrowDamageMax() != 5) ++bad;
            if (uam2AcidArrowAcidVolumeOunces() != 8) ++bad;
            if (uam2AcidArrowAcidDamageMin() != 2) ++bad;
            if (uam2AcidArrowAcidDamageMax() != 8) ++bad;
            if (!uam2AcidArrowItemSavingThrowApplies()) ++bad;
            if (!uam2AcidArrowNoSplash()) ++bad;
            if (uam2AcidArrowExtraRoundsPer3Levels() != 1) ++bad;
            if (uam2AcidArrowExtraRoundsFromLevel() != 4) ++bad;
            if (!uam2AcidArrowNeutralizationStops()) ++bad;
            if (!uam2AcidArrowMaterialDart()) ++bad;
            if (!uam2AcidArrowMaterialRhubarbLeaf()) ++bad;
            if (!uam2AcidArrowMaterialAdderStomach()) ++bad;
        // U7: preserve
            if (strcmp(uam2PreserveName(),
                "Preserve (Abjuration)") != 0) ++bad;
            if (uam2PreserveLevel() != 2) ++bad;
            if (uam2PreserveCastingTimeRounds() != 2) ++bad;
            if (!uam2PreserveRangeTouch()) ++bad;
            if (!uam2PreserveSaveNone()) ++bad;
            if (!uam2PreserveDurationPermanent()) ++bad;
            if (!uam2PreserveAoeNumberLost()) ++bad;
            if (!uam2PreserveAoeCuFtPerLevel()) ++bad;
            if (!uam2PreserveComponentsVSM()) ++bad;
            if (!uam2PreserveRetainsItemFresh()) ++bad;
            if (!uam2PreserveIneffectiveForFreshGather()) ++bad;
            if (!uam2PreserveOpenerGarbleDecoded()) ++bad;
            if (uam2PreserveHardDryMinLevel() != 2) ++bad;
            if (uam2PreserveHardDryMaxLevel() != 4) ++bad;
            if (uam2PreserveSoftWetMinLevel() != 5) ++bad;
            if (uam2PreserveSoftWetMaxLevel() != 7) ++bad;
            if (uam2PreserveLiquidMinLevel() != 8) ++bad;
            if (!uam2PreserveContainerOnlyForMoisture()) ++bad;
            if (!uam2PreserveMaterialDust()) ++bad;
            if (!uam2PreserveMaterialResinOrAmber()) ++bad;
            if (!uam2PreserveMaterialBrandy()) ++bad;
        // U8: protection from cantrips
            if (strcmp(uam2PfcName(),
                "Protection From Cantrips") != 0) ++bad;
            if (!uam2PfcNameHeaderGarbled()) ++bad;
            if (uam2PfcLevel() != 2) ++bad;
            if (!uam2PfcRangeTouch()) ++bad;
            if (uam2PfcCastingTimeSegments() != 2) ++bad;
            if (!uam2PfcSaveNoneOrNegates()) ++bad;
            if (uam2PfcDurationDaysPerLevel() != 1) ++bad;
            if (!uam2PfcAoeOneCreatureOrObject()) ++bad;
            if (!uam2PfcComponentsCellLost()) ++bad;
            if (!uam2PfcImmunityToCantrips()) ++bad;
            if (!uam2PfcProseInterleaveDecoded()) ++bad;
            if (!uam2PfcProtectsCasterOrItem()) ++bad;
            if (!uam2PfcCantripDissipatesWithPop()) ++bad;
            if (!uam2PfcMischievousApprenticesUse()) ++bad;
            if (!uam2PfcUnwillingToHitAndSave()) ++bad;
        // U9: the Tasha laughter
            if (strcmp(uam2TashaName(),
                "Tasha's Uncontrollable Hideous Laughter (Evo"
                "cation)") != 0) ++bad;
            if (uam2TashaLevel() != 2) ++bad;
            if (uam2TashaCastingTimeSegments() != 2) ++bad;
            if (uam2TashaRangeInches() != 5) ++bad;
            if (!uam2TashaSaveSpecial()) ++bad;
            if (uam2TashaDurationRounds() != 1) ++bad;
            if (!uam2TashaAoeOneCreature()) ++bad;
            if (!uam2TashaComponentsVSM()) ++bad;
            if (!uam2TashaEverythingHilarious()) ++bad;
            if (!uam2TashaTinglingFirstRound()) ++bad;
            if (!uam2TashaLaughterSequenceDecoded()) ++bad;
            if (!uam2TashaNextRoundRegainFeet()) ++bad;
            if (uam2TashaMinusTwoRounds() != 2) ++bad;
            if (uam2TashaPenaltyRounds() != 2) ++bad;
            if (!uam2TashaSaveNegates()) ++bad;
            if (uam2TashaUnaffectedIntMax() != 3) ++bad;
            if (uam2TashaInt4to8SaveMod() != -6) ++bad;
            if (uam2TashaInt9to12SaveMod() != -4) ++bad;
            if (uam2TashaInt13to15SaveMod() != -2) ++bad;
            if (!uam2TashaInt16PlusNormalSave()) ++bad;
            if (!uam2TashaMaterialFeather()) ++bad;
            if (!uam2TashaMaterialPaddle()) ++bad;
            if (!uam2TashaMaterialTort()) ++bad;
        // U10: vocalize
            if (strcmp(uam2VocalizeName(),
                "Vocalize (Alteration)") != 0) ++bad;
            if (!uam2VocalizeComponentsSM()) ++bad;
            if (uam2VocalizeLevel() != 2) ++bad;
            if (!uam2VocalizeRangeTouch()) ++bad;
            if (uam2VocalizeCastingTimeRounds() != 1) ++bad;
            if (!uam2VocalizeSaveNone()) ++bad;
            if (uam2VocalizeDurationRounds() != 5) ++bad;
            if (!uam2VocalizeAoeOneSpellCastingCreature()) ++bad;
            if (!uam2VocalizeCastsSilently()) ++bad;
            if (!uam2VocalizeWithinDurationOnly()) ++bad;
            if (!uam2VocalizeSpeliGarble()) ++bad;
            if (!uam2VocalizeUsefulUnderSilence()) ++bad;
            if (!uam2VocalizeOffsetsNotNegates()) ++bad;
            if (!uam2VocalizeMasksAudibleEffects()) ++bad;
            if (!uam2VocalizeNoInfoBackToCaster()) ++bad;
            if (!uam2VocalizeMaterialBellNoClapper()) ++bad;
            if (!uam2VocalizeMaterialJailbirdsTongue()) ++bad;
        // U11: whip
            if (strcmp(uam2WhipName(), "Whip (Evocation)") != 0) ++bad;
            if (uam2WhipLevel() != 2) ++bad;
            if (!uam2WhipLevelCellLost()) ++bad;
            if (uam2WhipDurationRoundsPerLevel() != 1) ++bad;
            if (!uam2WhipAoeSpecial()) ++bad;
            if (!uam2WhipComponentsVSM()) ++bad;
            if (uam2WhipCastingTimeSegments() != 2) ++bad;
            if (!uam2WhipCastingCellSplitDecoded()) ++bad;
            if (!uam2WhipSaveSpecial()) ++bad;
            if (uam2WhipReachInches() != 1) ++bad;
            if (!uam2WhipWieldedByHandMovement()) ++bad;
            if (!uam2WhipCrackAndStrikeEachTurn()) ++bad;
            if (!uam2WhipSoundKeepsAnimalsAtBay()) ++bad;
            if (uam2WhipAnimalSaveModMin() != -1) ++bad;
            if (uam2WhipAnimalSaveModMax() != -4) ++bad;
            if (uam2WhipSlinkAwayHours() != 1) ++bad;
            if (!uam2WhipNoActualDamage()) ++bad;
            if (uam2WhipUnaffectedIntAbove() != 3) ++bad;
            if (!uam2WhipGiantAboveBearSizeUnaffected()) ++bad;
            if (!uam2WhipMonstersUnaffected()) ++bad;
            if (!uam2WhipMeleeWrapsWeapon()) ++bad;
            if (uam2WhipEdgedSaveVsCrushingBlow() != 13) ++bad;
            if (uam2WhipNonEdgedSaveVsNormalBlow() != 6) ++bad;
            if (!uam2WhipSuccessTearsFromHand()) ++bad;
            if (!uam2WhipOpponentSaveKeepsWeapon()) ++bad;
            if (uam2WhipWeaponRecoverRounds() != 1) ++bad;
            if (!uam2WhipMagicBonusPenalizesSave()) ++bad;
            if (!uam2WhipMagicResistanceMustFail()) ++bad;
            if (!uam2WhipMaterialSilkBraided()) ++bad;
        // U12: zephyr
            if (strcmp(uam2ZephyrName(), "Zephyr (Evocation)") != 0) ++bad;
            if (!uam2ZephyrComponentsVSM()) ++bad;
            if (!uam2ZephyrComponentsCellSplit()) ++bad;
            if (uam2ZephyrLevel() != 2) ++bad;
            if (uam2ZephyrRangeZero() != 0) ++bad;
            if (uam2ZephyrCastingTimeSegments() != 2) ++bad;
            if (!uam2ZephyrCastingUnitLost()) ++bad;
            if (!uam2ZephyrSaveNone()) ++bad;
            if (uam2ZephyrDurationSegments() != 1) ++bad;
            if (!uam2ZephyrAoeOnePath()) ++bad;
            if (!uam2ZephyrPathFractionGarbled()) ++bad;
            if (!uam2ZephyrDraftInFacedDirection()) ++bad;
            if (!uam2ZephyrSmallFlamesWaver()) ++bad;
            if (uam2ZephyrFanDamageBonus() != 1) ++bad;
            if (uam2ZephyrHoldVaporsRounds() != 1) ++bad;
            if (!uam2ZephyrHalvesFogDuration()) ++bad;
            if (uam2ZephyrMoveGasesBackInches() != 1) ++bad;
            if (!uam2ZephyrHalvesGasDurationAndPotency()) ++bad;
            if (!uam2ZephyrUnlessRenewed()) ++bad;
            if (!uam2ZephyrMaterialParchmentFolded()) ++bad;
            if (!uam2ZephyrMaterialPinIvorySilver()) ++bad;
        // the R342 table seam (8 of 12 names)
        if (uas2Mu2ndCount() != 30) ++bad;
        if (strcmp(uas2Mu2ndName(1),
                "Bind") != 0) ++bad;
        if (strcmp(uas2Mu2ndName(9),
                "Irritation") != 0) ++bad;
        if (strcmp(uas2Mu2ndName(11),
                "Know Alignment") != 0) ++bad;
        if (strcmp(uas2Mu2ndName(16),
                "Melf's Acid Arrow") != 0) ++bad;
        if (strcmp(uas2Mu2ndName(18),
                "Preserve") != 0) ++bad;
        if (strcmp(uas2Mu2ndName(26),
                "Tasha's Uncontrollable "
                "Hideous Laughter") != 0) ++bad;
        if (strcmp(uas2Mu2ndName(27),
                "Whip") != 0) ++bad;
        if (strcmp(uas2Mu2ndName(29),
                "Zephyr") != 0) ++bad;
        // the four names absent from the seam
        for (int i = 0; i < 30; ++i) {
            const char* n = uas2Mu2ndName(i);
            if (strcmp(n, "Deeppockets") == 0) ++bad;
            if (strcmp(n, "Flaming Sphere") == 0)
                ++bad;
            if (strcmp(n, "Protection From "
                "Cantrips") == 0)
                ++bad;
            if (strcmp(n, "Vocalize") == 0) ++bad;
        }
        printf("R357 UA MU 2nd level spells pin audit: bad %d\n", bad);
        if (bad) return 1;
    }"""
    assert s.count(INC_ANCH) == 1, 'd inc anchor'
    assert s.count(AUD_ANCH) == 1, 'd aud anchor'
    clean(INC_NEW, 78)
    clean(AUDIT, 76)
    s = s.replace(INC_ANCH, INC_NEW)
    s = s.replace(AUD_ANCH,
        AUDIT + NL + NL + AUD_ANCH)
    wr(RT, s)
    applied.append('regtest.cpp: the R357 audit')
s = rd(RT)
assert s.count(
    'R357 UA MU 2nd level spells pin audit'
    ': bad ') == 1, 'd audit line'
assert s.count(
    'R356 UA MU 1st level spells'
    ' pin audit: bad ') == 1, 'd r356 kept'
assert s.count('audit: bad ') == 284, 'd census 284'
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
assert s.count('R227: the wis mental save') == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uamuspells2.h"') == 1, 'd include'
assert s.count(
    '#include "rules/uamuspells1.h"') == 1, 'd r356 include'
assert len(applied) + len(already) == 4, 'd count'

# ---- the summary ----
print('R357 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R357 note: the UA new magic-user')
print('spells pin round, the 2nd level -')
print('the twelve spell descriptions')
print('(bind, deeppockets behind the')
print('lost name header, flaming')
print('sphere, irritation, know')
print('alignment behind the lost range')
print('cell, the Melf acid arrow,')
print('preserve, protection from')
print('cantrips behind the From')
print('Cantrips header garble, the')
print('Tasha laughter, vocalize, whip')
print('behind the lost level cell,')
print('zephyr); the family decodes')
print('the 7s as 1; the R342 MU table')
print('seam prints eight of the twelve')
print('names, the four absent noted;')
print('the item stays open (the')
print('3rd-9th levels); the census')
print('283 -> 284')
print('commit: R357: the UA new')
print('magic-user 2nd level spells pin')
print('round (census 284)')

