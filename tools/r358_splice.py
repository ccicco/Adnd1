#!/usr/bin/env python3
# R358: the UA NEW MAGIC-USER
# SPELLS pin round, the 3rd level
# (pp. 51-66) - cloudburst
# seam-checking the R352 druid
# pin, detect illusion behind
# the lost name tail, item,
# material behind the degree
# range, the Melf minute
# meteors, secret page behind
# the 4th-heading interleave,
# the sepia snake sigil, wind
# wall. The digit-garble family
# decodes the 7s as 1. The R342
# table seam pins 4 of 8 names.
# The item stays open (the
# 4th-9th levels).
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

# ---- (a) the seed: the R356 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R357 landed 2026-10-11: commit',
    '  46924c5, census 284, the UA',
    '  new magic-user 2nd level spells',
    '  pin round (rules/uamuspells2.h):',
    '  the twelve spell descriptions',
    '  (bind, deeppockets behind the',
    '  lost name header, flaming',
    '  sphere, irritation, know',
    '  alignment behind the lost range',
    '  cell, the Melf acid arrow,',
    '  preserve, protection from',
    '  cantrips behind the From',
    '  Cantrips header garble, the',
    '  Tasha laughter, vocalize, whip',
    '  behind the lost level cell,',
    '  zephyr); the family decodes',
    '  the 7s as 1; the R342 MU table',
    '  seam prints eight of the twelve',
    '  names, the four absent noted.',
    '  GREEN on the first run.',
])
s = rd(SD)
if 'R357 landed 2026-10-11' in s:
    already.append('seed: the R357 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R357 record')
s = rd(SD)
assert s.count('R357 landed 2026-10-11') == 1, 'a entry'
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

# ---- (b) NEW rules/uamuspells1.h ----
US = 'rules/uamuspells3.h'
if os.path.exists(US) and 'R358' in rd(US):
    already.append('uamuspells3.h: the pins')
else:
    HDR = r"""// ===========================================================================
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

}   // namespace rules"""
    clean(HDR, 78)
    wr(US, HDR + NL)
    applied.append('uamuspells3.h: the pins')
s = rd(US)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 163, 'b inline count'
assert s.count('R358') == 1, 'b round tag'
assert s.count('uam3CloudburstName()') == 1, 'b cloudburst fn'
assert s.count(
    'uam3WindWallLooseMaterialFliesUpward()'
    ) == 1, 'b wind wall fn'
assert 'uastDruid' not in s, 'b no r341 ref'
assert 'uam2' not in s, 'b no r357 ref'
assert 'uam1' not in s, 'b no r356 ref'
assert 'uac1' not in s, 'b no r343 ref'
assert 'uad3' not in s, 'b no druid ref'
assert len(applied) + len(already) == 2, 'b count'

# ---- (c) the gap report: the note (the
# item STAYS OPEN - the 4th-9th levels) ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'R358: the 3rd level pinned' in s:
    already.append('gap report: the note')
else:
    TAIL_OLD = NL.join([
        '        through 9th levels stay',
        '        open.',
        '- [ ] **The new illusionist spells**',
    ])
    assert s.count(TAIL_OLD) == 1, 'c tail'
    NOTE = NL.join([
        '      - R358: the 3rd level pinned',
        '        (rules/uamuspells3.h) - the',
        '        eight spell descriptions',
        '        (cloudburst seam-checking',
        '        the R352 druid pin minus',
        '        the holy symbol, with the 3',
        '        diam. print flagged against',
        '        the druid 4; detect',
        '        illusion behind the lost',
        '        name tail and area length;',
        '        item; material behind the',
        '        degree range; the Melf',
        '        minute meteors behind the',
        '        empty range and the sepia',
        '        interleave; secret page',
        '        behind the 4th-heading',
        '        interleave; the sepia snake',
        '        sigil behind the lost',
        '        casting-time head; wind',
        '        wall behind the truncated',
        '        components cell); the family',
        '        decodes the 7s as 1; the',
        '        R342 MU table seam: four of',
        '        the eight names print',
        '        there, the four absent are',
        '        noted; the 4th through 9th',
        '        levels stay open.',
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
assert s.count('R358: the 3rd level pinned') == 1, 'c note'
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
if 'R358 UA MU 3rd level spells pin audit' in s:
    already.append('regtest.cpp: the R358 audit')
else:
    INC_ANCH = (
        '#include "rules/uamuspells2.h"'
        '  // R357: the UA new magic-user'
        ' 2nd level')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uamuspells3.h"'
        '  // R358: the UA new magic-user'
        ' 3rd level',
    ])
    AUD_ANCH = ('    // ---- R227: the wis mental'
                ' save wiring audit ----')
    AUDIT = r"""    // ---- R358: the UA new magic-user 3rd level spells pin audit ----
    // The UA NEW MAGIC-USER SPELLS (pp.
    // 51-66), the 3rd level - cloudburst
    // (the R352 druid seam minus the
    // holy symbol, the 3 diam. print
    // flagged against the druid 4),
    // detect illusion behind the lost
    // name tail, item, material
    // behind the degree range, the
    // Melf minute meteors behind the
    // empty range, secret page
    // behind the 4th-heading
    // interleave, the sepia snake
    // sigil behind the lost
    // casting-time head, wind wall.
    // The family decodes the 7s as 1.
    // The R342 table seam pins 4 of 8;
    // the item stays open (the
    // 4th-9th levels).
    {
        using namespace rules;
        int bad = 0;
        // U1: cloudburst
            if (strcmp(uam3CloudburstName(),
                "Cloudburst (Alteration)") != 0) ++bad;
            if (uam3CloudburstLevel() != 3) ++bad;
            if (!uam3CloudburstComponentsVSM()) ++bad;
            if (uam3CloudburstRangeInchesPerLevel() != 1) ++bad;
            if (!uam3CloudburstCastingTimeNumberLost()) ++bad;
            if (!uam3CloudburstCastingTimeUnitSegments()) ++bad;
            if (!uam3CloudburstStatBlockScrambled()) ++bad;
            if (!uam3CloudburstSaveNoneAndSpecial()) ++bad;
            if (!uam3CloudburstSaveCellTruncated()) ++bad;
            if (uam3CloudburstDurationRoundsPerLevel() != 1) ++bad;
            if (uam3CloudburstCylinderDiameterInches() != 3) ++bad;
            if (!uam3CloudburstDiameterDisagreesWithDruidSeam()) ++bad;
            if (uam3CloudburstCylinderHeightInches() != 6) ++bad;
            if (!uam3CloudburstIdenticalToClerical3rd()) ++bad;
            if (!uam3CloudburstNoHolySymbolComponent()) ++bad;
            // the R352 druid seam, cell by cell
            if (uad3CloudburstDurationRoundsPerLevel()
                != uam3CloudburstDurationRoundsPerLevel())
                ++bad;
            if (uad3CloudburstCylinderHeightInches()
                != uam3CloudburstCylinderHeightInches())
                ++bad;
            if (uad3CloudburstComponentsVSM()
                != uam3CloudburstComponentsVSM()) ++bad;
            if (uad3CloudburstSaveNoneAndSpecial()
                != uam3CloudburstSaveNoneAndSpecial())
                ++bad;
            // the range cell the druid block lost
            if (!uad3CloudburstRangeLost()) ++bad;
            if (uad3CloudburstCastingTimeSegments() != 5)
                ++bad;
            // the 3 vs 4 diameter disagreement
            if (uad3CloudburstCylinderDiameterInches()
                != 4) ++bad;
        // U2: detect illusion
            if (strcmp(uam3DetectName(),
                "Detect Illusion (Divination)") != 0) ++bad;
            if (!uam3DetectNameHeaderTailLost()) ++bad;
            if (uam3DetectLevel() != 3) ++bad;
            if (!uam3DetectComponentsVSM()) ++bad;
            if (uam3DetectCastingTimeSegments() != 3) ++bad;
            if (!uam3DetectRangeTouch()) ++bad;
            if (!uam3DetectSaveNone()) ++bad;
            if (uam3DetectDurationRoundsMin() != 2) ++bad;
            if (uam3DetectDurationRoundsPerLevel() != 1) ++bad;
            if (!uam3DetectAoeLineOfSightOneInchWide()) ++bad;
            if (!uam3DetectAoeLengthLost()) ++bad;
            if (!uam3DetectSameAsIllusionist1st()) ++bad;
            if (!uam3DetectExceptAsNotedTruncated()) ++bad;
        // U3: item
            if (strcmp(uam3ItemName(), "Item (Alteration)") != 0) ++bad;
            if (uam3ItemLevel() != 3) ++bad;
            if (!uam3ItemRangeTouch()) ++bad;
            if (uam3ItemDurationTurnsPerLevel() != 6) ++bad;
            if (!uam3ItemDurationQuadrupledNonLiving()) ++bad;
            if (uam3ItemAoeCuFtPerLevel() != 2) ++bad;
            if (!uam3ItemShrinksToOneTwelfth()) ++bad;
            if (!uam3ItemClothCompositionOption()) ++bad;
            if (!uam3ItemLivingEntitledToSave()) ++bad;
            if (uam3ItemLivingSavePlus4() != 4) ++bad;
            if (!uam3ItemClothSavesNormally()) ++bad;
            if (!uam3ItemReturnsOnTossOrCommand()) ++bad;
            if (!uam3ItemCanAffectFireAndFuel()) ++bad;
            if (!uam3ItemComponentsV()) ++bad;
            if (!uam3ItemComponentsM()) ++bad;
            if (!uam3ItemComponentsCellSplit()) ++bad;
            if (uam3ItemCastingTimeSegments() != 3) ++bad;
            if (!uam3ItemSaveSpecial()) ++bad;
        // U4: material
            if (strcmp(uam3MaterialName(),
                "Material (Evocation-Conjuration)") != 0) ++bad;
            if (uam3MaterialLevel() != 3) ++bad;
            if (!uam3MaterialComponentsV()) ++bad;
            if (!uam3MaterialComponentsCellGarbled()) ++bad;
            if (uam3MaterialCastingTimeRounds() != 1) ++bad;
            if (!uam3MaterialRangePrintsDegrees()) ++bad;
            if (uam3MaterialRangeDecodedOne() != 1) ++bad;
            if (!uam3MaterialSaveNone()) ++bad;
            if (!uam3MaterialDurationPermanent()) ++bad;
            if (uam3MaterialAoeCuFtPerLevel() != 7) ++bad;
            if (!uam3MaterialProseHeadScrambled()) ++bad;
            if (!uam3MaterialCommonStoneEarthWood()) ++bad;
            if (!uam3MaterialInorganicNonLivingEtc()) ++bad;
            if (uam3MaterialGrassBaseFailurePct() != 100) ++bad;
            if (!uam3MaterialGrassFailureMinusOnePctPerLevel()) ++bad;
            if (!uam3MaterialAnimalLifeNever()) ++bad;
            if (!uam3MaterialNoWorkedRefinedFabricated()) ++bad;
            if (!uam3MaterialNoRoughGemsOrPreciousMetals()) ++bad;
            if (!uam3MaterialCreatesCommonBasicThings()) ++bad;
        // U5: the Melf minute meteors
            if (strcmp(uam3MeteorsName(),
                "Melf's Minute Meteors (Evocation/Alteration)") != 0) ++bad;
            if (uam3MeteorsLevel() != 3) ++bad;
            if (!uam3MeteorsComponentsVSM()) ++bad;
            if (uam3MeteorsCastingTimeSegments() != 5) ++bad;
            if (!uam3MeteorsRangeCellEmpty()) ++bad;
            if (!uam3MeteorsDurationSpecial()) ++bad;
            if (!uam3MeteorsSaveNone()) ++bad;
            if (!uam3MeteorsAoeOneTargetPerMissile()) ++bad;
            if (uam3MeteorsBurstDiameterFeet() != 1) ++bad;
            if (uam3MeteorsDamageMin() != 1) ++bad;
            if (uam3MeteorsDamageMax() != 4) ++bad;
            if (!uam3MeteorsIgnitesCombustibles()) ++bad;
            if (!uam3MeteorsMissileWeapons()) ++bad;
            if (!uam3MeteorsMissesGrenadeLike()) ++bad;
            if (!uam3MeteorsOnePerLevelOfExperience()) ++bad;
            if (!uam3MeteorsDispelMagicEnds()) ++bad;
            if (!uam3MeteorsFireRateSentenceScrambled()) ++bad;
            if (!uam3MeteorsTwoRateOptions()) ++bad;
            if (!uam3MeteorsRateOneEvery2Segments()) ++bad;
            if (!uam3MeteorsRateOneEveryRound()) ++bad;
            if (!uam3MeteorsRateChoiceCannotSwitch()) ++bad;
            if (!uam3MeteorsRateOnePointEvery2Segments()) ++bad;
            if (!uam3MeteorsCarriesIntoFollowingRound()) ++bad;
            if (!uam3MeteorsRateTwoWithholdPerRound()) ++bad;
            if (!uam3MeteorsRateTwoSpellSameRound()) ++bad;
            if (!uam3MeteorsRateTwoNoConcentration()) ++bad;
            if (!uam3MeteorsLoseRemainderOnLostCount()) ++bad;
            if (!uam3MeteorsMaterialNitreSulphurPineTarBead()) ++bad;
            if (!uam3MeteorsMaterialGoldTube()) ++bad;
            if (uam3MeteorsTubeCostGpMin() != 1000) ++bad;
            if (!uam3MeteorsTubeReusableUnlessDamaged()) ++bad;
            if (!uam3MeteorsSepiaTailInterleaved()) ++bad;
        // U6: secret page
            if (strcmp(uam3SecretPageName(),
                "Secret Page (Alteration)") != 0) ++bad;
            if (!uam3SecretPageUnderFourthHeading()) ++bad;
            if (!uam3SecretPageStatInterleavedWithDispelIllusion()) ++bad;
            if (uam3SecretPageLevel() != 3) ++bad;
            if (!uam3SecretPageComponentsVSM()) ++bad;
            if (uam3SecretPageCastingTimeTurns() != 1) ++bad;
            if (!uam3SecretPageRangeTouch()) ++bad;
            if (!uam3SecretPageDurationUntilDispelled()) ++bad;
            if (!uam3SecretPageSaveNone()) ++bad;
            if (uam3SecretPageAoeMaxFt() != 2) ++bad;
            if (!uam3SecretPageAoeOnePageUpTo2FtSquare()) ++bad;
            if (!uam3SecretPageAltersContents()) ++bad;
            if (!uam3SecretPageMapToTreatiseExample()) ++bad;
            if (!uam3SecretPageRunesAllowed()) ++bad;
            if (!uam3SecretPageComprehendLanguagesFails()) ++bad;
            if (!uam3SecretPageReversedByCommandWord()) ++bad;
            if (!uam3SecretPageRemovedByDoubleCommand()) ++bad;
            if (!uam3SecretPageFailedDispelDestroysPage()) ++bad;
            if (!uam3SecretPageEssenceReveals()) ++bad;
            if (!uam3SecretPageMaterialHerringScales()) ++bad;
        // U7: the sepia snake sigil
            if (strcmp(uam3SepiaName(),
                "Sepia Snake Sigil (Conjuration/Summoning)") != 0) ++bad;
            if (!uam3SepiaBodyPrintsInFourthRegion()) ++bad;
            if (uam3SepiaLevel() != 3) ++bad;
            if (!uam3SepiaComponentsVSM()) ++bad;
            if (uam3SepiaRangeInches() != 2) ++bad;
            if (!uam3SepiaRangePrintsQuotedTwo()) ++bad;
            if (!uam3SepiaDurationSpecial()) ++bad;
            if (!uam3SepiaAoeOneSigil()) ++bad;
            if (!uam3SepiaCastingTimeHeadLost()) ++bad;
            if (uam3SepiaCastingTimeSegments() != 3) ++bad;
            if (!uam3SepiaSaveNone()) ++bad;
            if (!uam3SepiaThreeForms()) ++bad;
            if (!uam3SepiaStrikesNearestLiving()) ++bad;
            if (!uam3SepiaNeverAttacksCaster()) ++bad;
            if (!uam3SepiaAttackHdPerLevel()) ++bad;
            if (!uam3SepiaEngulfsOnStrike()) ++bad;
            if (!uam3SepiaAmberFieldOfForce()) ++bad;
            if (!uam3SepiaFrozenUntilReleaseOrDispel()) ++bad;
            if (!uam3SepiaNothingCanAffect()) ++bad;
            if (!uam3SepiaNoAgeHungerSleepOrSpells()) ++bad;
            if (!uam3SepiaMissDissipatesBrownFlash()) ++bad;
            if (uam3SepiaMissSmokeInches() != 1) ++bad;
            if (uam3SepiaMissSmokeRounds() != 1) ++bad;
            if (!uam3SepiaApplicationAirSigil()) ++bad;
            if (!uam3SepiaApplicationGlyphUmber()) ++bad;
            if (!uam3SepiaApplicationWrittenIntoWork()) ++bad;
            if (uam3SepiaMaterialAmberGp() != 100) ++bad;
            if (!uam3SepiaMaterialSnakeScale()) ++bad;
            if (!uam3SepiaMaterialMushroomSpores()) ++bad;
        // U8: wind wall
            if (strcmp(uam3WindWallName(),
                "Wind Wall (Alteration)") != 0) ++bad;
            if (uam3WindWallLevel() != 3) ++bad;
            if (!uam3WindWallComponentsCellTruncated()) ++bad;
            if (!uam3WindWallMaterialTinyFanAndExoticFeather()) ++bad;
            if (uam3WindWallRangeInchesPerLevel() != 1) ++bad;
            if (uam3WindWallCastingTimeSegments() != 3) ++bad;
            if (!uam3WindWallCastingTimeUnitLost()) ++bad;
            if (!uam3WindWallSaveSpecial()) ++bad;
            if (uam3WindWallDurationRoundsPerLevel() != 1) ++bad;
            if (uam3WindWallAoeInchesPerLevel() != 1) ++bad;
            if (!uam3WindWallAoeWideAndHigh()) ++bad;
            if (!uam3WindWallInvisibleCurtain()) ++bad;
            if (!uam3WindWallBlowsBirdsUpToCrows()) ++bad;
            if (!uam3WindWallTearsPapersFromHands()) ++bad;
            if (!uam3WindWallSaveToMaintainGrasp()) ++bad;
            if (!uam3WindWallNormalInsectsCannotPass()) ++bad;
            if (!uam3WindWallLooseMaterialFliesUpward()) ++bad;
        // the R342 table seam (4 of 8 names)
        if (uas2Mu3rdCount() != 28) ++bad;
        if (strcmp(uas2Mu3rdName(16),
                "Melf's Minute Meteor") != 0) ++bad;
        if (strcmp(uas2Mu3rdName(21),
                "Secret Page") != 0) ++bad;
        if (strcmp(uas2Mu3rdName(22),
                "Sepia Snake Sigil") != 0) ++bad;
        if (strcmp(uas2Mu3rdName(27),
                "Wind Wall") != 0) ++bad;
        // the four names absent from the seam
        for (int i = 0; i < 28; ++i) {
            const char* n = uas2Mu3rdName(i);
            if (strcmp(n, "Cloudburst") == 0) ++bad;
            if (strcmp(n, "Detect Illusion") == 0)
                ++bad;
            if (strcmp(n, "Item") == 0) ++bad;
            if (strcmp(n, "Material") == 0) ++bad;
        }
        printf("R358 UA MU 3rd level spells pin audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R358 audit')
s = rd(RT)
assert s.count(
    'R358 UA MU 3rd level spells pin audit'
    ': bad ') == 1, 'd audit line'
assert s.count(
    'R357 UA MU 2nd level spells'
    ' pin audit: bad ') == 1, 'd r357 kept'
assert s.count(
    'R356 UA MU 1st level spells'
    ' pin audit: bad ') == 1, 'd r356 kept'
assert s.count('audit: bad ') == 285, 'd census 285'
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
    '#include "rules/uamuspells3.h"') == 1, 'd include'
assert s.count(
    '#include "rules/uamuspells2.h"') == 1, 'd r357 include'
assert s.count(
    '#include "rules/uamuspells1.h"') == 1, 'd r356 include'
assert len(applied) + len(already) == 4, 'd count'

# ---- the summary ----
print('R358 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R358 note: the UA new magic-user')
print('spells pin round, the 3rd level -')
print('the eight spell descriptions')
print('(cloudburst seam-checking the')
print('R352 druid pin minus the holy')
print('symbol, with the 3 diam. print')
print('flagged against the druid 4;')
print('detect illusion behind the lost')
print('name tail and area length; item;')
print('material behind the degree')
print('range; the Melf minute meteors')
print('behind the empty range and the')
print('sepia interleave; secret page')
print('behind the 4th-heading')
print('interleave; the sepia snake')
print('sigil behind the lost')
print('casting-time head; wind wall')
print('behind the truncated components')
print('cell); the family decodes the')
print('7s as 1; the R342 MU table seam')
print('prints four of the eight names,')
print('the four absent noted; the item')
print('stays open (the 4th-9th')
print('levels); the census 284 -> 285')
print('commit: R358: the UA new')
print('magic-user 3rd level spells pin')
print('round (census 285)')

