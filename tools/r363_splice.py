#!/usr/bin/env python3
# R363: the UA NEW ILLUSIONIST
# SPELLS pin round, the cantrips
# and the 1st and 2nd levels
# (pp. 65-68) - colored lights,
# dim, haze, mask, mirage, noise,
# rainbow, the two-d illusion;
# the chromatic orb, phantom
# armor; read magic, spook, alter
# self, fascinate, the ultravision
# and wind reprints. The R342
# IL table seam prints only PHB
# names, none of the new names
# seam-checks. The item stays
# open - the 3rd through 7th
# levels pin later.
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


# ---- (a) the seed: the R362 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R362 landed 2026-10-11: commit',
    '  f9ef2b6, census 289, the UA new',
    '  magic-user 8th and 9th level',
    '  spells pin round',
    '  (rules/uamuspells8.h and',
    '  rules/uamuspells9.h): the four',
    '  8th-level descriptions (binding',
    '  with the lost range and duration',
    '  cells and the six forms with the',
    '  save ladder, demand behind the',
    '  garbled components cell, the',
    '  Otiluke telekinetic sphere behind',
    '  the garbled name header with the',
    '  lost range cell, sink with the',
    '  lost level cell and the sinking',
    '  ladder) and the four 9th-level',
    '  descriptions (crystalbrittle with',
    '  the item save ladder, succor with',
    '  the interleaved stat tail, energy',
    '  drain with the displaced casting',
    '  cell, the Mordenkainen disjunction',
    '  behind the garbled name header',
    '  with the artifact chances); the',
    '  R342 MU table seam checks demand',
    '  at index 0 and sink at index 8',
    '  with binding and the sphere',
    '  absent, and only the two PHB 9th',
    '  names print; the item CLOSED -',
    '  all printed levels pinned',
    '  (R356-R361 plus this round); GREEN',
    '  on the first run.',
])
s = rd(SD)
if 'R362 landed 2026-10-11' in s:
    already.append('seed: the R362 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R362 record')
s = rd(SD)
assert s.count('R362 landed 2026-10-11') == 1, 'a entry'
assert s.count('R361 landed 2026-10-11') == 1, 'a r361 kept'
assert s.count('R360 landed 2026-10-11') == 1, 'a r360 kept'
assert s.count('R359 landed 2026-10-11') == 1, 'a r359 kept'
assert s.count('R358 landed 2026-10-11') == 1, 'a r358 kept'
assert s.count('R357 landed 2026-10-11') == 1, 'a r357 kept'
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


# ---- (b) NEW rules/uailcantrips.h ----
USC = 'rules/uailcantrips.h'
if os.path.exists(USC) and 'R363' in rd(USC):
    already.append('uailcantrips.h: the pins')
else:
    HDRC = r"""// ===========================================================================
// Adnd1 - rules/uailcantrips.h
// The UA NEW ILLUSIONIST CANTRIPS (pp. 65-66) pins, R363:
// the eight minor-illusion cantrip descriptions -
// colored lights, dim, haze, mask, mirage, noise,
// rainbow and the two-d-lusion.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists. The cantrip TIER SEAM (a sub-1st
// registry tier) stays open - the descriptions pin
// now, the registry charge waits for the seam (the
// R322 deferred-seams graph).
//
// JUDGMENTs (the decode method):
//   - the item list (the R322 index) names seven
//     cantrips; the print describes an eighth, the
//     two-d-lusion, between rainbow and the first
//     level - pinned, the list amended.
//   - the casting-time cells print fraction garbles
//     (/z, "2, />, "/s, /s and '/s segment) - the
//     numerals never print clean; holes pending the
//     PDF, not pinned as numeric data.
//   - the haze area cell prints 7" cube - the
//     digit-garble family (the R356 precedent) decodes
//     the 1" cube, flagged pending the PDF.
//   - the mirage area cell prints a bare 2sq. fragment
//     and the two-d-lusion area cell prints empty -
//     holes pending the PDF.
//   - the colored-lights reflection sentence garbles
//     (will not cast reflections > beyond 17) and
//     reads as the visual-capability note: pale blue
//     or pink hues leave them undisturbed, other hues
//     disturb them - flagged pending the PDF.
//   - the mirage somatic tail garbles (a single pass)
//     and the noise casting cell prints a bare s -
//     flagged pending the PDF.
//   - the R342 IL cantrip column is wholly lost
//     (uas2IlCantripListLost) - none of the names
//     seam-checks, asserted in the audit.
// ===========================================================================

#pragma once

namespace rules {

// ---- colored lights (Alteration) ----
inline const char* uailcLightsName()
    { return "Colored Lights (Alteration)"; }

inline bool uailcLightsAoeSpecial()
    { return true; }

// The globe ladder: a single 1-foot globe, a pair of
// 6-inch globes, three 4-inch globes, or four 3-inch
// globes.
inline int uailcLightsSingleGlobeFeet()
    { return 1; }

inline int uailcLightsPairGlobesInches()
    { return 6; }

inline int uailcLightsThreeGlobesInches()
    { return 4; }

inline int uailcLightsFourGlobesInches()
    { return 3; }

// The globes can be of any pastel color (cf. the
// magic-user bluelight cantrip).
inline bool uailcLightsAnyPastelColor()
    { return true; }

inline bool uailcLightsCfBluelight()
    { return true; }

// Each globe illuminates a radius equal to five
// diameters: a 1-foot globe a 5-foot radius of
// brilliance, a 3-inch globe only 15 inches.
inline int uailcLightsRadiusInDiameters()
    { return 5; }

inline int uailcLightsFootGlobeRadiusFeet()
    { return 5; }

inline int uailcLightsThreeInchGlobeRadiusInches()
    { return 15; }

// Active as long as the caster concentrates; the
// globes float near or rest upon the caster as
// desired, within the 1-inch range, and are moved
// back and forth, up and down, to and fro as desired.
inline bool uailcLightsConcentrationMaintained()
    { return true; }

inline int uailcLightsRangeInches()
    { return 1; }

inline bool uailcLightsMovedAsDesired()
    { return true; }

// The reflection sentence garbles; the
// visual-capability read pins: pale blue or pink
// hues leave the visual capabilities undisturbed,
// other hues disturb them - flagged pending the PDF.
inline bool uailcLightsReflectionSentenceGarbled()
    { return true; }

inline bool uailcLightsPaleBluePinkSparesVision()
    { return true; }

// Verbal and somatic: speak the color and number of
// globes desired, then a magic word (noma, mazda,
// etc.), while directing the globes with one or more
// fingers.
inline bool uailcLightsSpeakColorAndNumber()
    { return true; }

inline bool uailcLightsMagicWord()
    { return true; }

inline bool uailcLightsDirectsWithFingers()
    { return true; }

// The casting-time cell prints a fraction garble - a
// hole pending the PDF.
inline bool uailcLightsCastingCellGarbled()
    { return true; }

// ---- dim (Alteration) ----
inline const char* uailcDimName()
    { return "Dim (Alteration)"; }

inline bool uailcDimAoeSpecial()
    { return true; }

// The cantrip causes a light source to become weaker
// or the very air to become less permeated by light
// rays.
inline bool uailcDimWeakensLightOrAir()
    { return true; }

// About 6 torches, a medium-sized fire (such as in a
// fireplace or campfire), 72 candles, or even a light
// or continual light spell can be affected.
inline int uailcDimTorches()
    { return 6; }

inline int uailcDimCandles()
    { return 72; }

inline bool uailcDimAffectsLightSpells()
    { return true; }

// Any affected source sheds at best half its normal
// radiance for one full round.
inline bool uailcDimHalfRadiance()
    { return true; }

inline int uailcDimDurationRounds()
    { return 1; }

// Torches burn only as brightly as candles; candles
// but glow dimly; a fire becomes torchlike; light
// spells dim to half their brightness.
inline bool uailcDimTorchAsCandle()
    { return true; }

inline bool uailcDimFireBecomesTorchlike()
    { return true; }

inline bool uailcDimLightSpellsDimToHalf()
    { return true; }

// Affected light must be within 1 inch of the caster.
inline int uailcDimRangeInches()
    { return 1; }

// A magical phrase (bee-row-nout, rhee-oh-stat) and a
// downward motion with one hand effectuate it.
inline bool uailcDimPhraseAndDownwardMotion()
    { return true; }

inline bool uailcDimCastingCellGarbled()
    { return true; }

// ---- haze (Alteration) ----
inline const char* uailcHazeName()
    { return "Haze (Alteration)"; }

// The area cell prints 7" cube - the digit-garble
// family decodes the 1-inch cube, flagged pending
// the PDF.
inline int uailcHazeAoeCubeInches()
    { return 1; }

inline bool uailcHazeAoeCellGarbleDecoded()
    { return true; }

// The atmosphere in the area becomes cloudy, as if
// layered by smoke or filled with floating dust.
inline bool uailcHazeSmokeOrDust()
    { return true; }

// A target screened by the haze is 5% harder to hit:
// missile discharge at -1 to hit, saving throws at
// +1 (or one given when otherwise none is allowed -
// only a 5% chance to save in the latter case).
inline int uailcHazeHarderToHitPct()
    { return 5; }

inline int uailcHazeMissileToHitAdj()
    { return -1; }

inline int uailcHazeSaveBonus()
    { return 1; }

inline int uailcHazeSaveWhenOtherwiseNonePct()
    { return 5; }

// Hiding in shadows is 5% more effective when
// screened by the haze.
inline int uailcHazeHideInShadowsBonusPct()
    { return 5; }

// The hazy effect lasts but a single round, cast
// over an area within 1 inch of the caster.
inline int uailcHazeDurationRounds()
    { return 1; }

inline int uailcHazeRangeInches()
    { return 1; }

// Atmospheric conditions destroy the haze - a good
// breeze, rain, etc.; a gust of wind disperses it
// immediately.
inline bool uailcHazeWeatherDestroys()
    { return true; }

inline bool uailcHazeGustOfWindDisperses()
    { return true; }

// The caster hums a melody while the hands make
// passes before the body.
inline bool uailcHazeHumAndHandPasses()
    { return true; }

inline bool uailcHazeCastingCellGarbled()
    { return true; }

// ---- mask (Illusion) ----
inline const char* uailcMaskName()
    { return "Mask (Illusion)"; }

inline bool uailcMaskAoeOnePerson()
    { return true; }

// The caster alters his or her own visage, or that of
// a chosen subject - human, demi-human, or humanoid.
inline bool uailcMaskAlterOwnOrSubjectVisage()
    { return true; }

inline bool uailcMaskSubjectHumanDemiHumanHumanoid()
    { return true; }

// Ears, hair, head shape, facial features and all
// such aspects of appearance are affected.
inline bool uailcMaskFeaturesAffected()
    { return true; }

// The mask is detectable only if a viewer peers
// closely or can detect illusion and does so.
inline bool uailcMaskDetectedOnlyCloseUp()
    { return true; }

// The effect lasts 3-6 rounds.
inline int uailcMaskDurationRoundsMin()
    { return 3; }

inline int uailcMaskDurationRoundsMax()
    { return 6; }

// The caster touches the face, thinks of the desired
// features, then speaks a word descriptive of the
// visage desired.
inline bool uailcMaskTouchThinkSpeak()
    { return true; }

inline bool uailcMaskCastingCellGarbled()
    { return true; }

// ---- mirage ----
inline const char* uailcMirageName()
    { return "Mirage"; }

// The school cell never prints - a hole pending the
// PDF.
inline bool uailcMirageSchoolCellLost()
    { return true; }

// The area cell prints a bare 2sq. fragment - a hole
// pending the PDF.
inline bool uailcMirageAoeCellGarbled()
    { return true; }

// The caster causes an area to appear to be
// something other than it is - an illusionary scene
// covers the area.
inline bool uailcMirageAreaAppearsOther()
    { return true; }

// The area must be relatively flat and featureless,
// and the mirage must be an actual place, in
// existence at the time, which the caster has
// actually beheld.
inline bool uailcMirageFlatFeatureless()
    { return true; }

inline bool uailcMirageActualBeheldPlace()
    { return true; }

// A saving throw versus spell is applicable.
inline bool uailcMirageSaveApplicable()
    { return true; }

// The cantrip lasts as long as the caster
// concentrates, with a 5% cumulative chance each
// round of wavering and revealing its true nature.
inline bool uailcMirageConcentrationMaintained()
    { return true; }

inline int uailcMirageWaverCumulativePct()
    { return 5; }

// Touching a mirage instantly dispels it, as does
// dispel illusion or dispel magic.
inline bool uailcMirageTouchDispel()
    { return true; }

inline bool uailcMirageDispelIllusionOrMagic()
    { return true; }

// The somatic tail garbles (a single pass to cause
// the magic to begin); the casting cell prints a
// bare segment fragment - the numeral lost - holes
// pending the PDF.
inline bool uailcMirageSomaticTailGarbled()
    { return true; }

inline bool uailcMirageCastingNumeralLost()
    { return true; }

// ---- noise (Illusion) ----
inline const char* uailcNoiseName()
    { return "Noise (Illusion)"; }

// The area of effect is a 1-inch radius.
inline int uailcNoiseRadiusInches()
    { return 1; }

// Illusory sound of whatever nature desired -
// indistinct and confusing: a murmuring as of many
// voices behind a thick door or at a great distance,
// a rushing sound of wings and wind combined,
// shuffling and scraping as of many people moving
// things or walking slowly at some distant place.
inline bool uailcNoiseIndistinctConfusing()
    { return true; }

inline bool uailcNoiseMurmurRushShuffleExamples()
    { return true; }

// All creatures within the area are subject, but
// each gets a saving throw - success negates the
// noise with respect to that individual.
inline bool uailcNoiseEachCreatureSaves()
    { return true; }

inline bool uailcNoiseSaveNegatesPerIndividual()
    { return true; }

// The range is 1 inch for the radius of sound.
inline int uailcNoiseRangeInches()
    { return 1; }

// The caster points a digit at the desired area,
// then softly makes sounds imitative of the noise
// desired.
inline bool uailcNoisePointAndImitate()
    { return true; }

// The casting cell prints a bare s fragment - a
// garble, a hole pending the PDF.
inline bool uailcNoiseCastingCellGarbled()
    { return true; }

// ---- rainbow (Alteration) ----
inline const char* uailcRainbowName()
    { return "Rainbow (Alteration)"; }

inline bool uailcRainbowAoeSpecial()
    { return true; }

// A plane of pastel colors exactly duplicating a
// rainbow: a 30-foot-long, 1-foot-wide band of
// color, arched into a bowed shape, kept a ribbon,
// twisted and turned, etc.
inline int uailcRainbowLengthFeet()
    { return 30; }

inline int uailcRainbowWidthFeet()
    { return 1; }

// One end of the rainbow must be within 1 inch of
// the caster when the cantrip is cast.
inline int uailcRainbowEndWithinInches()
    { return 1; }

// The colors glow softly and are visible even in
// total (normal) darkness.
inline bool uailcRainbowGlowsInDarkness()
    { return true; }

// If no motion is desired the caster may leave the
// vicinity; if motion is desired the caster controls
// it by hand gesture and remains within 1 inch of
// it.
inline bool uailcRainbowNoMotionMayLeave()
    { return true; }

inline int uailcRainbowMotionStayWithinInches()
    { return 1; }

// The rainbow lasts 1 round and then fades away.
inline int uailcRainbowDurationRounds()
    { return 1; }

// All creatures failing to save versus spell gaze at
// the rainbow for 1-4 segments, 2-5 if the caster
// keeps it in motion.
inline int uailcRainbowGazeSegmentsMin()
    { return 1; }

inline int uailcRainbowGazeSegmentsMax()
    { return 4; }

inline int uailcRainbowGazeMovingMin()
    { return 2; }

inline int uailcRainbowGazeMovingMax()
    { return 5; }

// The verbal component is a name of power (gar-land,
// pegee-lee, etc.), spoken while the fingers of both
// hands form a pyramid.
inline bool uailcRainbowNameOfPowerPyramid()
    { return true; }

inline bool uailcRainbowCastingCellGarbled()
    { return true; }

// ---- the two-d-lusion ----
// The name prints with an apostrophe: Two-D'lusion.
inline const char* uailcTwodName()
    { return "Two-D'lusion"; }

// The school cell never prints - a hole pending the
// PDF.
inline bool uailcTwodSchoolCellLost()
    { return true; }

// The area-of-effect cell prints empty - a hole
// pending the PDF.
inline bool uailcTwodAoeCellLost()
    { return true; }

// Virtually the same as a phantasmal force spell in
// most respects: the caster creates a
// two-dimensional illusion of whatever he or she
// desires.
inline bool uailcTwodSameAsPhantasmalForce()
    { return true; }

// Viewed from an angle of more than 45 degrees from
// its horizontal or vertical viewing axis, the
// nature of the illusion is immediately apparent.
inline int uailcTwodTellAngleDegrees()
    { return 45; }

// Dispelled by touch or magic (dispel illusion or
// dispel magic); invisible from the side or the
// rear.
inline bool uailcTwodDispelByTouchOrMagic()
    { return true; }

inline bool uailcTwodInvisibleFromSideOrRear()
    { return true; }

// Lasts as long as the caster concentrates upon it.
inline bool uailcTwodConcentrationMaintained()
    { return true; }

// The caster speaks a phrase descriptive of the
// illusion while making a circular motion with the
// closed hand.
inline bool uailcTwodPhraseAndCircularMotion()
    { return true; }

inline bool uailcTwodCastingCellGarbled()
    { return true; }

}   // namespace rules
"""
    clean(HDRC, 78)
    wr(USC, HDRC + NL)
    applied.append('uailcantrips.h: the pins')
s = rd(USC)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 106, 'b inline count'
assert s.count('R363') == 1, 'b round tag'
assert s.count('uailcLightsName()') == 1, 'b lights fn'
assert s.count('uailcTwodName()') == 1, 'b twod fn'
assert 'uam' not in s, 'b no mu ref'
assert 'uadruid' not in s, 'b no druid ref'
assert len(applied) + len(already) == 2, 'b count'


# ---- (b2) NEW rules/uailspells1.h ----
US1 = 'rules/uailspells1.h'
if os.path.exists(US1) and 'R363' in rd(US1):
    already.append('uailspells1.h: the pins')
else:
    HDR1 = r"""// ===========================================================================
// Adnd1 - rules/uailspells1.h
// The UA NEW ILLUSIONIST SPELLS (pp. 66-68) pins, R363:
// the 1st-level spell descriptions - the chromatic
// orb and phantom armor.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists.
//
// JUDGMENTs (the decode method):
//   - the chromatic orb name header garbles to a bare
//     cl-orb fragment - the name pins from the gap
//     item list and the prose; the school tail is
//     lost - a hole pending the PDF.
//   - the orb casting cell prints 7 segment - the
//     digit-garble family (the R343 precedent) decodes
//     the 1 segment.
//   - the orb to-hit ladder interleaves with the
//     range sentence: +3 at 1 inch or closer, +2 at
//     over 1 to 2 inches, +1 from over 2 inches to the
//     3-inch maximum - the fragments corroborate the
//     band values; the sentence garbles, flagged
//     pending the PDF.
//   - the orb color table prints nine rows - the
//     level ladder jumps 7th to 10th to 12th (no 8th
//     or 9th row prints) and the 10th and 12th damage
//     cells print empty - pinned as printed, the
//     holes noted pending the PDF; the special-power
//     notes print as an unnumbered bullet ladder with
//     garbled markers, mapped to the rows by order.
//   - the phantom armor level cell prints the clean
//     1 - the item list (the R322 index) names it at
//     2nd; the print wins, the divergence flagged in
//     the round note pending the PDF. The save-bonus
//     numeral garbles (a bare +) - a hole.
//   - the R342 IL table seam: the readable 1st
//     column prints five PHB names - neither new
//     name seam-checks, asserted in the audit.
// ===========================================================================

#pragma once

namespace rules {

// ---- the chromatic orb ----
// The name header garbles to a bare cl-orb fragment;
// the name pins from the gap item list and the
// prose. The school tail is lost - a hole pending
// the PDF.
inline const char* uail1OrbName()
    { return "Chromatic Orb"; }

inline bool uail1OrbNameHeaderGarbled()
    { return true; }

inline bool uail1OrbSchoolTailLost()
    { return true; }

inline int uail1OrbLevel()
    { return 1; }

inline bool uail1OrbRangeZero()
    { return true; }

inline bool uail1OrbDurationSpecial()
    { return true; }

inline bool uail1OrbAoeOneCreature()
    { return true; }

inline bool uail1OrbComponentsVSM()
    { return true; }

// The casting cell prints 7 segment - the family
// decodes the 1 segment.
inline int uail1OrbCastingTimeSegments()
    { return 1; }

inline bool uail1OrbCastingGarbleDecoded()
    { return true; }

inline bool uail1OrbSaveSpecial()
    { return true; }

// A small globe of varying hue, created in the hand
// and hurled at any opponent - no barriers between
// the illusionist and the target, which must be
// within the 3-inch maximum hurl distance.
inline int uail1OrbMaxHurlInches()
    { return 3; }

inline bool uail1OrbNoBarriers()
    { return true; }

// The orb is magical - even creatures normally
// struck only by +5, +4 etc. magic weapons are
// affected if it strikes; magic resistance
// withstands the spell.
inline bool uail1OrbMagicalVsHighPlus()
    { return true; }

inline bool uail1OrbMagicResistanceWithstands()
    { return true; }

// The to-hit ladder (the sentence interleaves with
// the range fragments, flagged pending the PDF):
// +3 at 1 inch or closer, +2 at over 1 to 2 inches,
// +1 from over 2 inches to the maximum 3 inches.
inline int uail1OrbHitAdjAtOneInch()
    { return 3; }

inline int uail1OrbHitAdjAtTwoInches()
    { return 2; }

inline int uail1OrbHitAdjAtMaxRange()
    { return 1; }

inline bool uail1OrbToHitSentenceInterleaved()
    { return true; }

// The color of the globe determines the effect when
// the subject is struck; low-level illusionists are
// restricted to colors at or below their level, the
// hues below always available.
inline bool uail1OrbColorDeterminesEffect()
    { return true; }

inline bool uail1OrbColorRestrictedByLevel()
    { return true; }

inline bool uail1OrbLowerHuesAlwaysAvailable()
    { return true; }

// The nine-row color ladder (the level cells print
// 1st through 7th, then 10th and 12th - the ladder
// jumps, no 8th or 9th row prints).
inline int uail1OrbRowCount()
    { return 9; }

inline int uail1OrbRowLevel(int i) {
    static const int k[9] = {
        1, 2, 3, 4, 5, 6, 7, 10, 12,
    };
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    return k[i];
}

inline const char* uail1OrbRowName(int i) {
    static const char* const k[9] = {
        "Pearly", "Ruby", "Flame", "Amber",
        "Emerald", "Turquoise", "Sapphire",
        "Amethyst", "Ashen",
    };
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    return k[i];
}

// The 10th and 12th damage cells print empty - holes
// pending the PDF, pinned as zero with the lost
// flag.
inline int uail1OrbRowDamageMin(int i) {
    static const int k[9] = {
        1, 1, 1, 1, 1, 2, 2, 0, 0,
    };
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    return k[i];
}

inline int uail1OrbRowDamageMax(int i) {
    static const int k[9] = {
        4, 6, 8, 10, 12, 16, 8, 0, 0,
    };
    if (i < 0) i = 0;
    if (i > 8) i = 8;
    return k[i];
}

inline bool uail1OrbRowDamageCellLost(int i)
    { return i == 7 || i == 8; }

// The special powers, mapped by row order (the note
// markers garble in the print).
// Pearly: light equal to a light spell persists 1
// round per caster level; a subject failing to save
// versus spell is blinded for the duration.
inline int uail1OrbPearlyLightRoundsPerLevel()
    { return 1; }

inline bool uail1OrbPearlyBlindsOnFailedSave()
    { return true; }

// Ruby: heat melts up to 1 cubic yard of ice; a
// creature not saving versus spell suffers a loss
// of 1 strength point and 1 dexterity point (or -1
// to hit and AC) for 1 round following the strike.
inline int uail1OrbRubyMeltsIceCuYd()
    { return 1; }

inline int uail1OrbRubyStatLossPerStat()
    { return 1; }

inline int uail1OrbRubyStatLossRounds()
    { return 1; }

// Flame: fire sets aflame all combustibles within 1
// inch radius of the target; unless the target saves
// versus spell an additional 2 points of fire
// damage are suffered (except when protected from
// fire by magical or natural means).
inline int uail1OrbFlameCombustiblesRadiusInches()
    { return 1; }

inline int uail1OrbFlameExtraDamage()
    { return 2; }

// Amber: the subject suffers blindness for 5-8
// rounds unless the save versus spell is made (cure
// blindness or dispel magic negates).
inline int uail1OrbAmberBlindRoundsMin()
    { return 5; }

inline int uail1OrbAmberBlindRoundsMax()
    { return 8; }

// Emerald: a magical stinking cloud of 5-radius
// around the target on a successful hit; the subject
// must save versus poison or be helpless, and in any
// event is helpless until leaving the vapors (cf.
// the stinking cloud spell).
inline int uail1OrbEmeraldCloudRadiusFeet()
    { return 5; }

// Turquoise: electrical damage; if the target wears
// ferrous metal it is magnetized for 3-12 rounds
// unless the save versus spell is made. Magnetized
// metal sticks fast to other magnetized items;
// non-magnetized ferrous items cling until pulled
// free.
inline int uail1OrbTurquoiseMagnetizeRoundsMin()
    { return 3; }

inline int uail1OrbTurquoiseMagnetizeRoundsMax()
    { return 12; }

// Sapphire: the subject is paralyzed for 5-20
// rounds unless the save versus paralyzation is
// made.
inline int uail1OrbSapphireParalysisRoundsMin()
    { return 5; }

inline int uail1OrbSapphireParalysisRoundsMax()
    { return 20; }

// Amethyst: the subject is turned to stone unless
// the save versus petrification is made; even if
// the save is made, the subject is slowed for 2-8
// rounds (cf. the slow spell).
inline bool uail1OrbAmethystStoneOnFailedSave()
    { return true; }

inline int uail1OrbAmethystSlowRoundsMin()
    { return 2; }

inline int uail1OrbAmethystSlowRoundsMax()
    { return 8; }

// Ashen: the subject dies unless the save versus
// death magic is made; even if the save is made, the
// subject is paralyzed for 2-5 rounds.
inline bool uail1OrbAshenDeathOnFailedSave()
    { return true; }

inline int uail1OrbAshenParalysisRoundsMin()
    { return 2; }

inline int uail1OrbAshenParalysisRoundsMax()
    { return 5; }

// The material component: a gem of the appropriate
// hue, or a clear crystal one (such as a diamond) -
// as small as 50 gold pieces in value as long as
// the color is appropriate.
inline int uail1OrbGemGpMin()
    { return 50; }

inline bool uail1OrbClearCrystalSubstitute()
    { return true; }

// ---- phantom armor (Alteration/Illusion) ----
inline const char* uail1PhantomName()
    { return "Phantom Armor (Alteration/Illusion)"; }

inline bool uail1PhantomComponentsVSM()
    { return true; }

// The level cell prints the clean 1 - the item list
// names the spell at 2nd; the print wins, the
// divergence flagged in the R363 note.
inline int uail1PhantomLevel()
    { return 1; }

inline bool uail1PhantomLevelDivergenceFlagged()
    { return true; }

// The casting cell prints 7 round - the family
// decodes the 1 round.
inline int uail1PhantomCastingTimeRounds()
    { return 1; }

inline bool uail1PhantomCastingGarbleDecoded()
    { return true; }

inline bool uail1PhantomRangeTouch()
    { return true; }

inline bool uail1PhantomDurationSpecial()
    { return true; }

inline bool uail1PhantomSaveNone()
    { return true; }

inline bool uail1PhantomAoeOnePerson()
    { return true; }

// The illusionist creates a quasi-real suit of
// plate mail - semi-illusory material covering the
// subject and giving some real protection.
inline bool uail1PhantomQuasiRealPlateMail()
    { return true; }

// The armor protects the wearer as if in plate mail:
// AC 3, armor type 3 as well.
inline int uail1PhantomAc()
    { return 3; }

inline int uail1PhantomArmorType()
    { return 3; }

// For each caster level the phantom armor absorbs
// 1 point of damage from a blow which would
// otherwise hit armor class 3; when it has absorbed
// as many points as the caster has levels, it is
// dispelled and vanishes - any remaining and all
// additional damage accrues to the person.
inline int uail1PhantomAbsorbPerLevel()
    { return 1; }

inline bool uail1PhantomVanishesAtLevelsAbsorbed()
    { return true; }

inline bool uail1PhantomRemainderAccrues()
    { return true; }

// The armor gives real protection unless the
// opponent actively disbelieves (saves versus
// spell), a dispel illusion or dispel magic is cast
// upon it, or a wand of negation affects it.
inline bool uail1PhantomDisbeliefBreaks()
    { return true; }

inline bool uail1PhantomDispelBreaks()
    { return true; }

inline bool uail1PhantomWandOfNegationBreaks()
    { return true; }

// The save-bonus numeral garbles (a bare + before
// saving throws versus all attack forms similarly
// modified by magic armor) - a hole pending the
// PDF.
inline bool uail1PhantomSaveBonusCellLost()
    { return true; }

// The dweomer in no way affects the movement or
// spell-casting abilities of the wearer.
inline bool uail1PhantomNoMovementOrCastingHindrance()
    { return true; }

// Not subject to rust monster attack (and such an
// attack may enhance disbelief).
inline bool uail1PhantomRustMonsterImmune()
    { return true; }

// The spell will not function with any other form
// of magical protection.
inline bool uail1PhantomNoOtherProtection()
    { return true; }

// The material component: a small plate of mithral
// (10 gp value) which disappears when the spell is
// cast.
inline int uail1PhantomMithralGp()
    { return 10; }

inline bool uail1PhantomDisappearsOnCast()
    { return true; }

}   // namespace rules
"""
    clean(HDR1, 78)
    wr(US1, HDR1 + NL)
    applied.append('uailspells1.h: the pins')
s = rd(US1)
assert s.count('namespace rules {') == 1, 'b2 ns'
assert s.count('inline') == 75, 'b2 inline count'
assert s.count('R363') == 2, 'b2 round tags'
assert s.count('uail1OrbName()') == 1, 'b2 orb fn'
assert s.count('uail1PhantomName()') == 1, 'b2 phantom fn'
assert 'uam' not in s, 'b2 no mu ref'
assert 'uailc' not in s, 'b2 no cantrip ref'
assert len(applied) + len(already) == 3, 'b2 count'


# ---- (b3) NEW rules/uailspells2.h ----
US2 = 'rules/uailspells2.h'
if os.path.exists(US2) and 'R363' in rd(US2):
    already.append('uailspells2.h: the pins')
else:
    HDR2 = r"""// ===========================================================================
// Adnd1 - rules/uailspells2.h
// The UA NEW ILLUSIONIST SPELLS (pp. 67-68) pins,
// R363: the 2nd-level spell descriptions - read
// magic, spook, alter self and fascinate, plus the
// ultravision and wind reprints with their illusion-
// ist stat blocks.
//
// Pin-era pattern (R322): pinned data only - no
// engine site exists.
//
// JUDGMENTs (the decode method):
//   - the printed section carries read magic and
//     spook under a 2ND LEVEL running header: the
//     read magic level cell never prints (the stat
//     block scrambles into V, and M fragments) - the
//     level pins from the header, flagged pending the
//     PDF; the spook level cell prints the digit-
//     garble 7 - the family decodes the 2 (the header
//     corroborates), flagged.
//   - the item list (the R322 index) names phantom
//     armor, read magic and spook at 2nd and delude
//     and wraithform there as well; the print places
//     phantom armor at 1st (a clean Level: 1 cell)
//     and delude and wraithform in the third-level
//     section - the print wins, the divergence
//     flagged in the R363 note; delude and wraithform
//     pin with the third level in a later round.
//   - the alter self components cell garbles the
//     sign (V, $) - the V, S pin from the pattern;
//     the maneuverability minimum class is lost in a
//     mid-sentence cut - a hole.
//   - the fascinate stat block interleaves (the
//     casting 2 segments scrambles) and the request
//     sentence garbles - the +2 to +6 dangerous-
//     request ladder pins from the fragments,
//     flagged pending the PDF.
//   - ultravision and wind are reprints of PHB magic-
//     user spells with illusionist stat blocks -
//     pinned small (the ultravision version seam-
//     checks the R359 MU pin); the wind name header
//     garbles and the prose reads as the whispering
//     wind throughout.
//   - the R342 IL table seam: the readable 2nd column
//     prints four PHB names - none of the new names
//     seam-checks, asserted in the audit.
// ===========================================================================

#pragma once

namespace rules {

// ---- read magic (Divination), reversible ----
inline const char* uail2ReadName()
    { return "Read Magic (Divination)"; }

inline bool uail2ReadReversible()
    { return true; }

// The stat block scrambles - the level cell never
// prints; the components print as bare V, and M
// fragments.
inline bool uail2ReadStatBlockScrambled()
    { return true; }

inline bool uail2ReadComponentsVM()
    { return true; }

inline bool uail2ReadLevelCellLost()
    { return true; }

// The level pins from the printed 2ND LEVEL section
// header - flagged pending the PDF.
inline int uail2ReadLevel()
    { return 2; }

inline bool uail2ReadLevelFromSectionHeader()
    { return true; }

// The casting cell prints 7 segment - the family
// decodes the 1 segment.
inline int uail2ReadCastingTimeSegments()
    { return 1; }

inline bool uail2ReadCastingGarbleDecoded()
    { return true; }

// The duration prints 2 rounds per level.
inline int uail2ReadDurationRoundsPerLevel()
    { return 2; }

inline bool uail2ReadSaveNone()
    { return true; }

inline bool uail2ReadAoeSpecial()
    { return true; }

// The same as the 1st-level magic-user spell read
// magic, except that it applies only to spells
// usable by and used by illusionists, as well as to
// various other inscriptions written in
// illusionist-type magic script by illusionists.
inline bool uail2ReadSameAsMuFirstLevelReadMagic()
    { return true; }

inline bool uail2ReadIllusionistScriptOnly()
    { return true; }

// ---- spook (Illusion/Phantasm) ----
inline const char* uail2SpookName()
    { return "Spook (Illusion/Phantasm)"; }

// The level cell prints the digit-garble 7 - the
// family decodes the 2 (the printed 2ND LEVEL
// section header corroborates), flagged pending
// the PDF.
inline int uail2SpookLevel()
    { return 2; }

inline bool uail2SpookLevelGarbleDecoded()
    { return true; }

// The range cell prints empty - a hole pending the
// PDF.
inline bool uail2SpookRangeCellLost()
    { return true; }

// The casting cell prints 7 segment - the family
// decodes the 1 segment.
inline int uail2SpookCastingTimeSegments()
    { return 1; }

inline bool uail2SpookCastingGarbleDecoded()
    { return true; }

inline bool uail2SpookDurationSpecial()
    { return true; }

inline bool uail2SpookSaveNegates()
    { return true; }

// The area of effect: one creature within 1 inch of
// the illusionist.
inline int uail2SpookAoeOneCreatureWithinInches()
    { return 1; }

// The spell plays upon natural fears to cause the
// subject to perceive the spell caster as someone
// or something inimical; the illusionist advances
// threateningly without actually knowing what the
// subject perceives.
inline bool uail2SpookPlaysOnNaturalFears()
    { return true; }

inline bool uail2SpookSubjectPerceivesCasterInimical()
    { return true; }

inline bool uail2SpookAdvancesThreateningly()
    { return true; }

// On a failed save versus spell the creature reacts
// by rapidly fleeing, getting as much distance from
// the illusionist as possible - the effects as a
// wand of fear; items carried are not dropped.
inline bool uail2SpookFleesRapidlyOnFailedSave()
    { return true; }

inline bool uail2SpookEffectsAsWandOfFear()
    { return true; }

inline bool uail2SpookItemsNotDropped()
    { return true; }

// The caster does not actually pursue - a phantasm
// from the fleeing creature own mind does so.
inline bool uail2SpookPhantasmPursues()
    { return true; }

// Each round after the initial casting the creature
// is entitled to another saving throw, each at a
// cumulative +1 per round, until it successfully
// saves and the spell is broken.
inline int uail2SpookCumulativeSaveBonusPerRound()
    { return 1; }

// The spell functions only against creatures with
// intelligence of not less than 1.
inline int uail2SpookMinIntelligence()
    { return 1; }

// ---- alter self (Alteration/Illusion) ----
inline const char* uail2AlterName()
    { return "Alter Self (Alteration/Illusion)"; }

inline int uail2AlterLevel()
    { return 2; }

// The components cell garbles the sign (V, $) - the
// V, S pins from the stat pattern.
inline bool uail2AlterComponentsVS()
    { return true; }

inline bool uail2AlterComponentsCellGarbled()
    { return true; }

inline bool uail2AlterRangeZero()
    { return true; }

inline int uail2AlterCastingTimeSegments()
    { return 2; }

// The duration: 3-12 rounds plus 2 per level.
inline int uail2AlterDurationRoundsMin()
    { return 3; }

inline int uail2AlterDurationRoundsMax()
    { return 12; }

inline int uail2AlterDurationRoundsPerLevel()
    { return 2; }

inline bool uail2AlterSaveNone()
    { return true; }

inline bool uail2AlterAoeTheIllusionist()
    { return true; }

// The illusionist alters himself or herself in a
// manner similar to a change self spell - but with a
// quasi-real change.
inline bool uail2AlterSimilarToChangeSelf()
    { return true; }

inline bool uail2AlterQuasiRealChange()
    { return true; }

// Size can be altered by 50% of actual.
inline int uail2AlterSizeChangePct()
    { return 50; }

// If the form selected has wings the illusionist
// can actually fly - at one-quarter the rate of
// speed of a true creature of that type, with a
// loss of two Maneuverability Classes (to a minimum
// lost in a mid-sentence cut - a hole pending the
// PDF).
inline bool uail2AlterFlyQuarterSpeed()
    { return true; }

inline int uail2AlterManeuverClassLoss()
    { return 2; }

inline bool uail2AlterMinManeuverClassHole()
    { return true; }

// If the form has gills, the illusionist can
// breathe underwater as long as the spell lasts.
inline bool uail2AlterGillsBreatheWater()
    { return true; }

// Changing into a larger creature does not permit
// additional attacks or damage unless the
// illusionist is accustomed to this form.
inline bool uail2AlterLargerFormNoExtraAttacks()
    { return true; }

inline bool uail2AlterUnlessAccustomed()
    { return true; }

// ---- fascinate (Illusion/Phantasm) ----
// The R322 comeliness pin names fascinate as the
// 2nd-level illusionist spell - the corroborating
// seam for the section-heading level.
inline const char* uail2FascName()
    { return "Fascinate (Illusion/Phantasm)"; }

// The level cell never prints - the level pins from
// the printed Second Level Spells section heading,
// flagged pending the PDF.
inline bool uail2FascLevelCellLost()
    { return true; }

inline int uail2FascLevel()
    { return 2; }

inline bool uail2FascLevelFromSectionHeader()
    { return true; }

// The components cell garbles the sign (V, a
// paragraph sign) - the V, S pins from the pattern.
inline bool uail2FascComponentsVS()
    { return true; }

inline bool uail2FascComponentsCellGarbled()
    { return true; }

// The stat block interleaves - the casting 2
// segments scrambles across lines.
inline int uail2FascCastingTimeSegments()
    { return 2; }

inline bool uail2FascStatBlockInterleaved()
    { return true; }

inline bool uail2FascDurationSpecial()
    { return true; }

inline bool uail2FascSaveNegates()
    { return true; }

inline bool uail2FascAoeOneCreature()
    { return true; }

// The illusionist attempts to captivate the subject
// attention and gain its love - becoming, in the
// eyes of the subject, a trusted and/or desired
// companion.
inline bool uail2FascCaptivatesAttentionAndLove()
    { return true; }

inline bool uail2FascTrustedDesiredCompanion()
    { return true; }

// Unless the save versus spell is made, the subject
// follows the illusionist wherever he or she goes,
// if possible without undue risk to life and
// safety.
inline bool uail2FascFollowsWithoutUndueRisk()
    { return true; }

// If the illusionist can converse with the
// fascinated creature, the subject obeys requests
// as long as a roll of 3d6 per request does not
// exceed the comeliness of the illusionist.
inline int uail2FascRequestDiceCount()
    { return 3; }

inline int uail2FascRequestDiceSides()
    { return 6; }

inline bool uail2FascRequestRollVsComeliness()
    { return true; }

// The request sentence garbles: requests obviously
// against the creature add from +2 to +6 to the
// dice roll, and the subject will certainly be
// filled with rage and hate - the ladder pins from
// the fragments, flagged pending the PDF.
inline int uail2FascDangerousRequestBonusMin()
    { return 2; }

inline int uail2FascDangerousRequestBonusMax()
    { return 6; }

inline bool uail2FascRequestSentenceGarbled()
    { return true; }

inline bool uail2FascRageAndHate()
    { return true; }

// Creatures of normal sort with animal intelligence
// remain fascinated for only a short period - 1-4
// days.
inline int uail2FascAnimalIntDaysMin()
    { return 1; }

inline int uail2FascAnimalIntDaysMax()
    { return 4; }

// If the illusionist treats the subject well,
// attends to its needs and feeds it, there is a 2%
// chance per point of caster comeliness that the
// subject willingly chooses to befriend and follow.
inline int uail2FascBefriendPctPerComelinessPoint()
    { return 2; }

// Otherwise the creature attacks (if it was not
// cared for) or leaves (if it was) when the spell
// wears off.
inline bool uail2FascAttackOrLeaveWhenWorn()
    { return true; }

// Non-intelligent creatures are not subject to a
// fascinate spell (cf. charm person).
inline bool uail2FascNonIntelligentImmune()
    { return true; }

// The section tail prints stray fragments (the spell
// illusion around the better) - a hole pending the
// PDF.
inline bool uail2FascTailFragmentsHole()
    { return true; }

// ---- ultravision (Alteration), the IL reprint ----
inline const char* uail2UltraName()
    { return "Ultravision (Alteration)"; }

inline int uail2UltraLevel()
    { return 2; }

inline bool uail2UltraRangeTouch()
    { return true; }

// The duration: 6 turns plus 1 per level.
inline int uail2UltraDurationTurnsBase()
    { return 6; }

inline int uail2UltraDurationTurnsPerLevel()
    { return 1; }

inline bool uail2UltraAoeCreatureTouched()
    { return true; }

// The components cell garbles the sign - the V, S, M
// pins from the stat pattern.
inline bool uail2UltraComponentsVSM()
    { return true; }

inline bool uail2UltraComponentsCellGarbled()
    { return true; }

inline int uail2UltraCastingTimeSegments()
    { return 2; }

inline bool uail2UltraSaveNone()
    { return true; }

// Essentially the same as the 4th-level magic-user
// spell of the same name (the R359 pin) - except as
// the IL stat block prints: level 2, touch, 6 turns
// + 1 per level.
inline bool uail2UltraSameAsMuFourthLevel()
    { return true; }

// With high intelligence the caster might be able
// to detect invisible creatures by the use of
// ultravision, either natural or magically bestowed
// - the note sentence scrambles, flagged pending
// the PDF.
inline bool uail2UltraHighIntDetectsInvisible()
    { return true; }

inline bool uail2UltraNoteSentenceGarbled()
    { return true; }

// The material component: a powdered essence of
// carrots.
inline bool uail2UltraMaterialPowderedCarrots()
    { return true; }

// ---- wind (Phantasm), the IL reprint ----
// The name header garbles (Wind, with the school a
// bare fragment); the prose reads as the whispering
// wind throughout.
inline const char* uail2WindName()
    { return "Wind (Phantasm)"; }

inline bool uail2WindNameHeaderGarbled()
    { return true; }

inline bool uail2WindWhisperingWindProse()
    { return true; }

inline int uail2WindLevel()
    { return 2; }

inline bool uail2WindComponentsVS()
    { return true; }

inline int uail2WindCastingTimeSegments()
    { return 2; }

inline bool uail2WindRangeSpecial()
    { return true; }

inline bool uail2WindSaveNone()
    { return true; }

inline bool uail2WindDurationSpecial()
    { return true; }

// The area of effect prints a 2-radius - pinned as
// printed.
inline int uail2WindAoeRadiusFeet()
    { return 2; }

// The illusionist either sends a message or causes
// a desired sound effect: the whispering wind
// travels as many tens of feet underground or miles
// above ground as the caster has levels - a
// 3rd-level illusionist sends it 30 feet in a
// dungeon or three miles outdoors.
inline bool uail2WindTensFeetPerLevelUnderground()
    { return true; }

inline bool uail2WindMilesPerLevelAboveGround()
    { return true; }

// The wind is as gentle and unnoticed as a zephyr
// until it reaches the objective; it then delivers
// its whisper-quiet message or other sound for up
// to two segments.
inline int uail2WindDeliverySegments()
    { return 2; }

// The dweomer fades and vanishes if the subject is
// beyond range, more than two hours of time have
// elapsed, or it is magically dispelled.
inline int uail2WindFadesAfterHours()
    { return 2; }

// The spell bears a message of up to 12 words,
// delivers other sounds for 12 seconds, or merely a
// faint stirring of the air with a susurrant sound.
inline int uail2WindMessageWords()
    { return 12; }

inline int uail2WindSoundSeconds()
    { return 12; }

// The wind moves as slowly as 1 inch per round or
// as quickly as 20 inches (or any rate in
// between); it swirls and remains the full two
// segments at the objective regardless of speed.
inline int uail2WindSpeedMinInchesPerRound()
    { return 1; }

inline int uail2WindSpeedMaxInchesPerRound()
    { return 20; }

// As with the magic mouth spell, no spells may be
// cast through the whispering wind.
inline bool uail2WindNoSpellsThrough()
    { return true; }

}   // namespace rules
"""
    clean(HDR2, 78)
    wr(US2, HDR2 + NL)
    applied.append('uailspells2.h: the pins')
s = rd(US2)
assert s.count('namespace rules {') == 1, 'b3 ns'
assert s.count('inline') == 112, 'b3 inline count'
assert s.count('R363') == 2, 'b3 round tags'
assert s.count('uail2ReadName()') == 1, 'b3 read fn'
assert s.count('uail2WindName()') == 1, 'b3 wind fn'
assert 'uam' not in s, 'b3 no mu ref'
assert 'uailc' not in s, 'b3 no cantrip ref'
assert 'uail1' not in s, 'b3 no 1st ref'
assert len(applied) + len(already) == 4, 'b3 count'


# ---- (c) the gap report: the two notes ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'R363: the cantrips and the' in s:
    already.append('gap report: the spells item note')
else:
    TAIL_OLD = NL.join([
        '      charges verifies against the',
        '      spell table (p. 31) first.',
        '',
        '## Cantrips (a category of their own)',
    ])
    assert s.count(TAIL_OLD) == 1, 'c tail'
    NOTE1 = NL.join([
        '      - R363: the cantrips and the',
        '        1st and 2nd levels pinned',
        '        (rules/uailcantrips.h,',
        '        rules/uailspells1.h and',
        '        rules/uailspells2.h) - the',
        '        eight cantrip descriptions,',
        '        the chromatic orb with the',
        '        color-by-level ladder,',
        '        phantom armor, read magic,',
        '        spook, alter self and',
        '        fascinate plus the',
        '        ultravision and wind',
        '        reprints; the print places',
        '        phantom armor at 1st (a',
        '        clean Level: 1 cell) and',
        '        carries delude and',
        '        wraithform in the third-',
        '        level section - the',
        '        divergence from the item',
        '        list flagged pending the',
        '        PDF; the R342 IL table seam',
        '        prints only PHB names in',
        '        the readable columns, none',
        '        of the new names seam-',
        '        checks; the 3rd through 7th',
        '        levels stay open.',
    ])
    clean(NOTE1, 57)
    s = s.replace(TAIL_OLD, NL.join([
        '      charges verifies against the',
        '      spell table (p. 31) first.',
        NOTE1,
        '',
        '## Cantrips (a category of their own)',
    ]))
    wr(GP, s)
    applied.append('gap report: the spells item note')
if 'R363: the eight cantrip' in s:
    already.append('gap report: the cantrips item note')
else:
    TAIL2_OLD = NL.join([
        '      (7 named).',
        '- [ ] **The cantrip acquisition rules**',
    ])
    assert s.count(TAIL2_OLD) == 1, 'c tail2'
    NOTE2 = NL.join([
        '      - R363: the eight cantrip',
        '        descriptions pinned',
        '        (rules/uailcantrips.h) -',
        '        colored lights with the',
        '        globe ladder, dim with the',
        '        half-radiance round, haze',
        '        with the missile and save',
        '        adjustments, mask, mirage,',
        '        noise, rainbow, and the',
        '        eighth the print adds',
        '        behind the item list (the',
        '        two-d illusion); the',
        '        casting-time cells print',
        '        fraction garbles - holes',
        '        pending the PDF; the box',
        '        stays open on the cantrip',
        '        tier seam (the registry',
        '        charge), the descriptions',
        '        are pinned.',
    ])
    clean(NOTE2, 57)
    s = s.replace(TAIL2_OLD, NL.join([
        '      (7 named).',
        NOTE2,
        '- [ ] **The cantrip acquisition rules**',
    ]))
    wr(GP, s)
    applied.append('gap report: the cantrips item note')
s = rd(GP)
assert s.count('R363: the cantrips and the') == 1, 'c note1'
assert s.count('R363: the eight cantrip') == 1, 'c note2'
assert s.count(
    '- [ ] **The new illusionist spells**'
) == 1, 'c open header'
assert s.count(
    '- [ ] **The illusionist cantrips**'
) == 1, 'c cantrips header'
assert s.count(
    'R362: the 8th and 9th levels'
    ) == 1, 'c r362 kept'
assert s.count(
    'R361: the 7th level pinned'
    ) == 1, 'c r361 kept'
assert s.count(
    'R360: the 5th and 6th levels'
    ) == 1, 'c r360 kept'
assert s.count(
    'CLOSED R362') == 1, 'c r362 closed'
assert s.count(
    '- [x] **The new magic-user spells**'
    ) == 1, 'c mu closed kept'
assert len(applied) + len(already) == 6, 'c count'


# ---- (d) regtest.cpp: the includes, the
# audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R363 UA IL cantrips/1st/2nd pin audit' in s:
    already.append('regtest.cpp: the R363 audit')
else:
    INC_ANCH = (
        '#include "rules/uamuspells9.h"'
        '  // R362: the UA new magic-user'
        ' 9th level')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uailcantrips.h"'
        '  // R363: the UA new illusionist'
        ' cantrips',
        '#include "rules/uailspells1.h"'
        '  // R363: the UA new illusionist'
        ' 1st level',
        '#include "rules/uailspells2.h"'
        '  // R363: the UA new illusionist'
        ' 2nd level',
    ])
    AUD_ANCH = (
        '    // ---- R227: the wis mental save'
        ' wiring audit ----')
    AUDIT = r"""    // ---- R363: the UA new illusionist
    // cantrips and 1st/2nd level spells
    // pin audit ----
    // The UA NEW ILLUSIONIST SPELLS
    // (pp. 65-68) - the eight cantrip
    // descriptions (colored lights with
    // the globe ladder, dim, haze, mask,
    // mirage, noise, rainbow, and the
    // two-d-lusion the item list missed);
    // the chromatic orb with the color
    // ladder, phantom armor; read magic,
    // spook, alter self, fascinate, and
    // the ultravision and wind reprints.
    // The R342 IL table seam prints only
    // PHB names in the readable columns;
    // the cantrip column is lost. The item
    // stays open - the 3rd through 7th
    // levels pin in later rounds.
    {
        using namespace rules;
        int bad = 0;
        // ---- U1: colored lights ----
            if (strcmp(uailcLightsName(),
                "Colored Lights (Alteration)") != 0) ++bad;
            if (!uailcLightsAoeSpecial()) ++bad;
            if (uailcLightsSingleGlobeFeet() != 1) ++bad;
            if (uailcLightsPairGlobesInches() != 6) ++bad;
            if (uailcLightsThreeGlobesInches() != 4) ++bad;
            if (uailcLightsFourGlobesInches() != 3) ++bad;
            if (!uailcLightsAnyPastelColor()) ++bad;
            if (!uailcLightsCfBluelight()) ++bad;
            if (uailcLightsRadiusInDiameters() != 5) ++bad;
            if (uailcLightsFootGlobeRadiusFeet() != 5) ++bad;
            if (uailcLightsThreeInchGlobeRadiusInches() != 15) ++bad;
            if (!uailcLightsConcentrationMaintained()) ++bad;
            if (uailcLightsRangeInches() != 1) ++bad;
            if (!uailcLightsMovedAsDesired()) ++bad;
            if (!uailcLightsReflectionSentenceGarbled()) ++bad;
            if (!uailcLightsPaleBluePinkSparesVision()) ++bad;
            if (!uailcLightsSpeakColorAndNumber()) ++bad;
            if (!uailcLightsMagicWord()) ++bad;
            if (!uailcLightsDirectsWithFingers()) ++bad;
            if (!uailcLightsCastingCellGarbled()) ++bad;
            if (strcmp(uailcDimName(), "Dim (Alteration)") != 0) ++bad;
            if (!uailcDimAoeSpecial()) ++bad;
            if (!uailcDimWeakensLightOrAir()) ++bad;
            if (uailcDimTorches() != 6) ++bad;
            if (uailcDimCandles() != 72) ++bad;
            if (!uailcDimAffectsLightSpells()) ++bad;
            if (!uailcDimHalfRadiance()) ++bad;
            if (uailcDimDurationRounds() != 1) ++bad;
            if (!uailcDimTorchAsCandle()) ++bad;
            if (!uailcDimFireBecomesTorchlike()) ++bad;
            if (!uailcDimLightSpellsDimToHalf()) ++bad;
            if (uailcDimRangeInches() != 1) ++bad;
            if (!uailcDimPhraseAndDownwardMotion()) ++bad;
            if (!uailcDimCastingCellGarbled()) ++bad;
            if (strcmp(uailcHazeName(), "Haze (Alteration)") != 0) ++bad;
            if (uailcHazeAoeCubeInches() != 1) ++bad;
            if (!uailcHazeAoeCellGarbleDecoded()) ++bad;
            if (!uailcHazeSmokeOrDust()) ++bad;
            if (uailcHazeHarderToHitPct() != 5) ++bad;
            if (uailcHazeMissileToHitAdj() != -1) ++bad;
            if (uailcHazeSaveBonus() != 1) ++bad;
            if (uailcHazeSaveWhenOtherwiseNonePct() != 5) ++bad;
            if (uailcHazeHideInShadowsBonusPct() != 5) ++bad;
            if (uailcHazeDurationRounds() != 1) ++bad;
            if (uailcHazeRangeInches() != 1) ++bad;
            if (!uailcHazeWeatherDestroys()) ++bad;
            if (!uailcHazeGustOfWindDisperses()) ++bad;
            if (!uailcHazeHumAndHandPasses()) ++bad;
            if (!uailcHazeCastingCellGarbled()) ++bad;
            if (strcmp(uailcMaskName(), "Mask (Illusion)") != 0) ++bad;
            if (!uailcMaskAoeOnePerson()) ++bad;
            if (!uailcMaskAlterOwnOrSubjectVisage()) ++bad;
            if (!uailcMaskSubjectHumanDemiHumanHumanoid()) ++bad;
            if (!uailcMaskFeaturesAffected()) ++bad;
            if (!uailcMaskDetectedOnlyCloseUp()) ++bad;
            if (uailcMaskDurationRoundsMin() != 3) ++bad;
            if (uailcMaskDurationRoundsMax() != 6) ++bad;
            if (!uailcMaskTouchThinkSpeak()) ++bad;
            if (!uailcMaskCastingCellGarbled()) ++bad;
            if (strcmp(uailcMirageName(), "Mirage") != 0) ++bad;
            if (!uailcMirageSchoolCellLost()) ++bad;
            if (!uailcMirageAoeCellGarbled()) ++bad;
            if (!uailcMirageAreaAppearsOther()) ++bad;
            if (!uailcMirageFlatFeatureless()) ++bad;
            if (!uailcMirageActualBeheldPlace()) ++bad;
            if (!uailcMirageSaveApplicable()) ++bad;
            if (!uailcMirageConcentrationMaintained()) ++bad;
            if (uailcMirageWaverCumulativePct() != 5) ++bad;
            if (!uailcMirageTouchDispel()) ++bad;
            if (!uailcMirageDispelIllusionOrMagic()) ++bad;
            if (!uailcMirageSomaticTailGarbled()) ++bad;
            if (!uailcMirageCastingNumeralLost()) ++bad;
            if (strcmp(uailcNoiseName(), "Noise (Illusion)") != 0) ++bad;
            if (uailcNoiseRadiusInches() != 1) ++bad;
            if (!uailcNoiseIndistinctConfusing()) ++bad;
            if (!uailcNoiseMurmurRushShuffleExamples()) ++bad;
            if (!uailcNoiseEachCreatureSaves()) ++bad;
            if (!uailcNoiseSaveNegatesPerIndividual()) ++bad;
            if (uailcNoiseRangeInches() != 1) ++bad;
            if (!uailcNoisePointAndImitate()) ++bad;
            if (!uailcNoiseCastingCellGarbled()) ++bad;
            if (strcmp(uailcRainbowName(),
                "Rainbow (Alteration)") != 0) ++bad;
            if (!uailcRainbowAoeSpecial()) ++bad;
            if (uailcRainbowLengthFeet() != 30) ++bad;
            if (uailcRainbowWidthFeet() != 1) ++bad;
            if (uailcRainbowEndWithinInches() != 1) ++bad;
            if (!uailcRainbowGlowsInDarkness()) ++bad;
            if (!uailcRainbowNoMotionMayLeave()) ++bad;
            if (uailcRainbowMotionStayWithinInches() != 1) ++bad;
            if (uailcRainbowDurationRounds() != 1) ++bad;
            if (uailcRainbowGazeSegmentsMin() != 1) ++bad;
            if (uailcRainbowGazeSegmentsMax() != 4) ++bad;
            if (uailcRainbowGazeMovingMin() != 2) ++bad;
            if (uailcRainbowGazeMovingMax() != 5) ++bad;
            if (!uailcRainbowNameOfPowerPyramid()) ++bad;
            if (!uailcRainbowCastingCellGarbled()) ++bad;
            if (strcmp(uailcTwodName(), "Two-D'lusion") != 0) ++bad;
            if (!uailcTwodSchoolCellLost()) ++bad;
            if (!uailcTwodAoeCellLost()) ++bad;
            if (!uailcTwodSameAsPhantasmalForce()) ++bad;
            if (uailcTwodTellAngleDegrees() != 45) ++bad;
            if (!uailcTwodDispelByTouchOrMagic()) ++bad;
            if (!uailcTwodInvisibleFromSideOrRear()) ++bad;
            if (!uailcTwodConcentrationMaintained()) ++bad;
            if (!uailcTwodPhraseAndCircularMotion()) ++bad;
            if (!uailcTwodCastingCellGarbled()) ++bad;
        // ---- U2: the chromatic orb ----
            if (strcmp(uail1OrbName(), "Chromatic Orb") != 0) ++bad;
            if (!uail1OrbNameHeaderGarbled()) ++bad;
            if (!uail1OrbSchoolTailLost()) ++bad;
            if (uail1OrbLevel() != 1) ++bad;
            if (!uail1OrbRangeZero()) ++bad;
            if (!uail1OrbDurationSpecial()) ++bad;
            if (!uail1OrbAoeOneCreature()) ++bad;
            if (!uail1OrbComponentsVSM()) ++bad;
            if (uail1OrbCastingTimeSegments() != 1) ++bad;
            if (!uail1OrbCastingGarbleDecoded()) ++bad;
            if (!uail1OrbSaveSpecial()) ++bad;
            if (uail1OrbMaxHurlInches() != 3) ++bad;
            if (!uail1OrbNoBarriers()) ++bad;
            if (!uail1OrbMagicalVsHighPlus()) ++bad;
            if (!uail1OrbMagicResistanceWithstands()) ++bad;
            if (uail1OrbHitAdjAtOneInch() != 3) ++bad;
            if (uail1OrbHitAdjAtTwoInches() != 2) ++bad;
            if (uail1OrbHitAdjAtMaxRange() != 1) ++bad;
            if (!uail1OrbToHitSentenceInterleaved()) ++bad;
            if (!uail1OrbColorDeterminesEffect()) ++bad;
            if (!uail1OrbColorRestrictedByLevel()) ++bad;
            if (!uail1OrbLowerHuesAlwaysAvailable()) ++bad;
            if (uail1OrbRowCount() != 9) ++bad;
            if (uail1OrbPearlyLightRoundsPerLevel() != 1) ++bad;
            if (!uail1OrbPearlyBlindsOnFailedSave()) ++bad;
            if (uail1OrbRubyMeltsIceCuYd() != 1) ++bad;
            if (uail1OrbRubyStatLossPerStat() != 1) ++bad;
            if (uail1OrbRubyStatLossRounds() != 1) ++bad;
            if (uail1OrbFlameCombustiblesRadiusInches() != 1) ++bad;
            if (uail1OrbFlameExtraDamage() != 2) ++bad;
            if (uail1OrbAmberBlindRoundsMin() != 5) ++bad;
            if (uail1OrbAmberBlindRoundsMax() != 8) ++bad;
            if (uail1OrbEmeraldCloudRadiusFeet() != 5) ++bad;
            if (uail1OrbTurquoiseMagnetizeRoundsMin() != 3) ++bad;
            if (uail1OrbTurquoiseMagnetizeRoundsMax() != 12) ++bad;
            if (uail1OrbSapphireParalysisRoundsMin() != 5) ++bad;
            if (uail1OrbSapphireParalysisRoundsMax() != 20) ++bad;
            if (!uail1OrbAmethystStoneOnFailedSave()) ++bad;
            if (uail1OrbAmethystSlowRoundsMin() != 2) ++bad;
            if (uail1OrbAmethystSlowRoundsMax() != 8) ++bad;
            if (!uail1OrbAshenDeathOnFailedSave()) ++bad;
            if (uail1OrbAshenParalysisRoundsMin() != 2) ++bad;
            if (uail1OrbAshenParalysisRoundsMax() != 5) ++bad;
            if (uail1OrbGemGpMin() != 50) ++bad;
            if (!uail1OrbClearCrystalSubstitute()) ++bad;
            if (strcmp(uail1PhantomName(),
                "Phantom Armor (Alteration/Illusion)") != 0) ++bad;
            if (!uail1PhantomComponentsVSM()) ++bad;
            if (uail1PhantomLevel() != 1) ++bad;
            if (!uail1PhantomLevelDivergenceFlagged()) ++bad;
            if (uail1PhantomCastingTimeRounds() != 1) ++bad;
            if (!uail1PhantomCastingGarbleDecoded()) ++bad;
            if (!uail1PhantomRangeTouch()) ++bad;
            if (!uail1PhantomDurationSpecial()) ++bad;
            if (!uail1PhantomSaveNone()) ++bad;
            if (!uail1PhantomAoeOnePerson()) ++bad;
            if (!uail1PhantomQuasiRealPlateMail()) ++bad;
            if (uail1PhantomAc() != 3) ++bad;
            if (uail1PhantomArmorType() != 3) ++bad;
            if (uail1PhantomAbsorbPerLevel() != 1) ++bad;
            if (!uail1PhantomVanishesAtLevelsAbsorbed()) ++bad;
            if (!uail1PhantomRemainderAccrues()) ++bad;
            if (!uail1PhantomDisbeliefBreaks()) ++bad;
            if (!uail1PhantomDispelBreaks()) ++bad;
            if (!uail1PhantomWandOfNegationBreaks()) ++bad;
            if (!uail1PhantomSaveBonusCellLost()) ++bad;
            if (!uail1PhantomNoMovementOrCastingHindrance()) ++bad;
            if (!uail1PhantomRustMonsterImmune()) ++bad;
            if (!uail1PhantomNoOtherProtection()) ++bad;
            if (uail1PhantomMithralGp() != 10) ++bad;
            if (!uail1PhantomDisappearsOnCast()) ++bad;
        // ---- U3: read magic ----
            if (strcmp(uail2ReadName(),
                "Read Magic (Divination)") != 0) ++bad;
            if (!uail2ReadReversible()) ++bad;
            if (!uail2ReadStatBlockScrambled()) ++bad;
            if (!uail2ReadComponentsVM()) ++bad;
            if (!uail2ReadLevelCellLost()) ++bad;
            if (uail2ReadLevel() != 2) ++bad;
            if (!uail2ReadLevelFromSectionHeader()) ++bad;
            if (uail2ReadCastingTimeSegments() != 1) ++bad;
            if (!uail2ReadCastingGarbleDecoded()) ++bad;
            if (uail2ReadDurationRoundsPerLevel() != 2) ++bad;
            if (!uail2ReadSaveNone()) ++bad;
            if (!uail2ReadAoeSpecial()) ++bad;
            if (!uail2ReadSameAsMuFirstLevelReadMagic()) ++bad;
            if (!uail2ReadIllusionistScriptOnly()) ++bad;
            if (strcmp(uail2SpookName(),
                "Spook (Illusion/Phantasm)") != 0) ++bad;
            if (uail2SpookLevel() != 2) ++bad;
            if (!uail2SpookLevelGarbleDecoded()) ++bad;
            if (!uail2SpookRangeCellLost()) ++bad;
            if (uail2SpookCastingTimeSegments() != 1) ++bad;
            if (!uail2SpookCastingGarbleDecoded()) ++bad;
            if (!uail2SpookDurationSpecial()) ++bad;
            if (!uail2SpookSaveNegates()) ++bad;
            if (uail2SpookAoeOneCreatureWithinInches() != 1) ++bad;
            if (!uail2SpookPlaysOnNaturalFears()) ++bad;
            if (!uail2SpookSubjectPerceivesCasterInimical()) ++bad;
            if (!uail2SpookAdvancesThreateningly()) ++bad;
            if (!uail2SpookFleesRapidlyOnFailedSave()) ++bad;
            if (!uail2SpookEffectsAsWandOfFear()) ++bad;
            if (!uail2SpookItemsNotDropped()) ++bad;
            if (!uail2SpookPhantasmPursues()) ++bad;
            if (uail2SpookCumulativeSaveBonusPerRound() != 1) ++bad;
            if (uail2SpookMinIntelligence() != 1) ++bad;
            if (strcmp(uail2AlterName(),
                "Alter Self (Alteration/Illusion)") != 0) ++bad;
            if (uail2AlterLevel() != 2) ++bad;
            if (!uail2AlterComponentsVS()) ++bad;
            if (!uail2AlterComponentsCellGarbled()) ++bad;
            if (!uail2AlterRangeZero()) ++bad;
            if (uail2AlterCastingTimeSegments() != 2) ++bad;
            if (uail2AlterDurationRoundsMin() != 3) ++bad;
            if (uail2AlterDurationRoundsMax() != 12) ++bad;
            if (uail2AlterDurationRoundsPerLevel() != 2) ++bad;
            if (!uail2AlterSaveNone()) ++bad;
            if (!uail2AlterAoeTheIllusionist()) ++bad;
            if (!uail2AlterSimilarToChangeSelf()) ++bad;
            if (!uail2AlterQuasiRealChange()) ++bad;
            if (uail2AlterSizeChangePct() != 50) ++bad;
            if (!uail2AlterFlyQuarterSpeed()) ++bad;
            if (uail2AlterManeuverClassLoss() != 2) ++bad;
            if (!uail2AlterMinManeuverClassHole()) ++bad;
            if (!uail2AlterGillsBreatheWater()) ++bad;
            if (!uail2AlterLargerFormNoExtraAttacks()) ++bad;
            if (!uail2AlterUnlessAccustomed()) ++bad;
            if (strcmp(uail2FascName(),
                "Fascinate (Illusion/Phantasm)") != 0) ++bad;
            if (!uail2FascLevelCellLost()) ++bad;
            if (uail2FascLevel() != 2) ++bad;
            if (!uail2FascLevelFromSectionHeader()) ++bad;
            if (!uail2FascComponentsVS()) ++bad;
            if (!uail2FascComponentsCellGarbled()) ++bad;
            if (uail2FascCastingTimeSegments() != 2) ++bad;
            if (!uail2FascStatBlockInterleaved()) ++bad;
            if (!uail2FascDurationSpecial()) ++bad;
            if (!uail2FascSaveNegates()) ++bad;
            if (!uail2FascAoeOneCreature()) ++bad;
            if (!uail2FascCaptivatesAttentionAndLove()) ++bad;
            if (!uail2FascTrustedDesiredCompanion()) ++bad;
            if (!uail2FascFollowsWithoutUndueRisk()) ++bad;
            if (uail2FascRequestDiceCount() != 3) ++bad;
            if (uail2FascRequestDiceSides() != 6) ++bad;
            if (!uail2FascRequestRollVsComeliness()) ++bad;
            if (uail2FascDangerousRequestBonusMin() != 2) ++bad;
            if (uail2FascDangerousRequestBonusMax() != 6) ++bad;
            if (!uail2FascRequestSentenceGarbled()) ++bad;
            if (!uail2FascRageAndHate()) ++bad;
            if (uail2FascAnimalIntDaysMin() != 1) ++bad;
            if (uail2FascAnimalIntDaysMax() != 4) ++bad;
            if (uail2FascBefriendPctPerComelinessPoint() != 2) ++bad;
            if (!uail2FascAttackOrLeaveWhenWorn()) ++bad;
            if (!uail2FascNonIntelligentImmune()) ++bad;
            if (!uail2FascTailFragmentsHole()) ++bad;
            if (strcmp(uail2UltraName(),
                "Ultravision (Alteration)") != 0) ++bad;
            if (uail2UltraLevel() != 2) ++bad;
            if (!uail2UltraRangeTouch()) ++bad;
            if (uail2UltraDurationTurnsBase() != 6) ++bad;
            if (uail2UltraDurationTurnsPerLevel() != 1) ++bad;
            if (!uail2UltraAoeCreatureTouched()) ++bad;
            if (!uail2UltraComponentsVSM()) ++bad;
            if (!uail2UltraComponentsCellGarbled()) ++bad;
            if (uail2UltraCastingTimeSegments() != 2) ++bad;
            if (!uail2UltraSaveNone()) ++bad;
            if (!uail2UltraSameAsMuFourthLevel()) ++bad;
            if (!uail2UltraHighIntDetectsInvisible()) ++bad;
            if (!uail2UltraNoteSentenceGarbled()) ++bad;
            if (!uail2UltraMaterialPowderedCarrots()) ++bad;
            if (strcmp(uail2WindName(), "Wind (Phantasm)") != 0) ++bad;
            if (!uail2WindNameHeaderGarbled()) ++bad;
            if (!uail2WindWhisperingWindProse()) ++bad;
            if (uail2WindLevel() != 2) ++bad;
            if (!uail2WindComponentsVS()) ++bad;
            if (uail2WindCastingTimeSegments() != 2) ++bad;
            if (!uail2WindRangeSpecial()) ++bad;
            if (!uail2WindSaveNone()) ++bad;
            if (!uail2WindDurationSpecial()) ++bad;
            if (uail2WindAoeRadiusFeet() != 2) ++bad;
            if (!uail2WindTensFeetPerLevelUnderground()) ++bad;
            if (!uail2WindMilesPerLevelAboveGround()) ++bad;
            if (uail2WindDeliverySegments() != 2) ++bad;
            if (uail2WindFadesAfterHours() != 2) ++bad;
            if (uail2WindMessageWords() != 12) ++bad;
            if (uail2WindSoundSeconds() != 12) ++bad;
            if (uail2WindSpeedMinInchesPerRound() != 1) ++bad;
            if (uail2WindSpeedMaxInchesPerRound() != 20) ++bad;
            if (!uail2WindNoSpellsThrough()) ++bad;
        // the orb row ladder (9 rows)
            if (uail1OrbRowCount() != 9) ++bad;
            if (uail1OrbRowLevel(0) != 1)
                ++bad;
            if (strcmp(uail1OrbRowName(0),
                "Pearly") != 0) ++bad;
            if (uail1OrbRowDamageMin(0) != 1)
                ++bad;
            if (uail1OrbRowDamageMax(0) != 4)
                ++bad;
            if (uail1OrbRowDamageCellLost(0) != false)
                ++bad;
            if (uail1OrbRowLevel(1) != 2)
                ++bad;
            if (strcmp(uail1OrbRowName(1),
                "Ruby") != 0) ++bad;
            if (uail1OrbRowDamageMin(1) != 1)
                ++bad;
            if (uail1OrbRowDamageMax(1) != 6)
                ++bad;
            if (uail1OrbRowDamageCellLost(1) != false)
                ++bad;
            if (uail1OrbRowLevel(2) != 3)
                ++bad;
            if (strcmp(uail1OrbRowName(2),
                "Flame") != 0) ++bad;
            if (uail1OrbRowDamageMin(2) != 1)
                ++bad;
            if (uail1OrbRowDamageMax(2) != 8)
                ++bad;
            if (uail1OrbRowDamageCellLost(2) != false)
                ++bad;
            if (uail1OrbRowLevel(3) != 4)
                ++bad;
            if (strcmp(uail1OrbRowName(3),
                "Amber") != 0) ++bad;
            if (uail1OrbRowDamageMin(3) != 1)
                ++bad;
            if (uail1OrbRowDamageMax(3) != 10)
                ++bad;
            if (uail1OrbRowDamageCellLost(3) != false)
                ++bad;
            if (uail1OrbRowLevel(4) != 5)
                ++bad;
            if (strcmp(uail1OrbRowName(4),
                "Emerald") != 0) ++bad;
            if (uail1OrbRowDamageMin(4) != 1)
                ++bad;
            if (uail1OrbRowDamageMax(4) != 12)
                ++bad;
            if (uail1OrbRowDamageCellLost(4) != false)
                ++bad;
            if (uail1OrbRowLevel(5) != 6)
                ++bad;
            if (strcmp(uail1OrbRowName(5),
                "Turquoise") != 0) ++bad;
            if (uail1OrbRowDamageMin(5) != 2)
                ++bad;
            if (uail1OrbRowDamageMax(5) != 16)
                ++bad;
            if (uail1OrbRowDamageCellLost(5) != false)
                ++bad;
            if (uail1OrbRowLevel(6) != 7)
                ++bad;
            if (strcmp(uail1OrbRowName(6),
                "Sapphire") != 0) ++bad;
            if (uail1OrbRowDamageMin(6) != 2)
                ++bad;
            if (uail1OrbRowDamageMax(6) != 8)
                ++bad;
            if (uail1OrbRowDamageCellLost(6) != false)
                ++bad;
            if (uail1OrbRowLevel(7) != 10)
                ++bad;
            if (strcmp(uail1OrbRowName(7),
                "Amethyst") != 0) ++bad;
            if (uail1OrbRowDamageMin(7) != 0)
                ++bad;
            if (uail1OrbRowDamageMax(7) != 0)
                ++bad;
            if (uail1OrbRowDamageCellLost(7) != true)
                ++bad;
            if (uail1OrbRowLevel(8) != 12)
                ++bad;
            if (strcmp(uail1OrbRowName(8),
                "Ashen") != 0) ++bad;
            if (uail1OrbRowDamageMin(8) != 0)
                ++bad;
            if (uail1OrbRowDamageMax(8) != 0)
                ++bad;
            if (uail1OrbRowDamageCellLost(8) != true)
                ++bad;
        // the R342 IL table seam: the readable
        // 1st and 2nd columns print only PHB
        // names; the cantrip column is lost
            if (uas2Il1stCount() != 5) ++bad;
            if (uas2Il2ndCount() != 4) ++bad;
            if (strcmp(uas2Il1stName(4),
                        "Phantasmal Force") != 0) ++bad;
            if (strcmp(uas2Il2ndName(0),
                        "Dispel Illusion") != 0) ++bad;
            if (strcmp(uas2Il7thName(0),
                        "Shadow Walk") != 0) ++bad;
            if (!uas2IlCantripListLost()) ++bad;
        // none of the new illusionist names
        // seam-checks in the readable columns
            static const char* const nn[6] = {
                "Chromatic Orb", "Phantom Armor",
                "Read Magic", "Spook",
                "Alter Self", "Fascinate",
            };
            for (int n = 0; n < 6; ++n) {
                for (int i = 0; i < 5; ++i) {
                    if (strcmp(uas2Il1stName(i),
                        nn[n]) == 0) ++bad;
                }
                for (int i = 0; i < 4; ++i) {
                    if (strcmp(uas2Il2ndName(i),
                        nn[n]) == 0) ++bad;
                }
            }
        printf("R363 UA IL cantrips/1st/2nd pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
"""
    assert s.count(INC_ANCH) == 1, 'd inc anchor'
    assert s.count(AUD_ANCH) == 1, 'd aud anchor'
    clean(INC_NEW, 78)
    clean(AUDIT, 76)
    s = s.replace(INC_ANCH, INC_NEW)
    s = s.replace(AUD_ANCH,
        AUDIT + NL + NL + AUD_ANCH)
    wr(RT, s)
    applied.append('regtest.cpp: the R363 audit')
s = rd(RT)
assert s.count(
    'R363 UA IL cantrips/1st/2nd pin audit'
    ) == 1, 'd audit line'
assert s.count(
    'R362 UA MU 8th/9th level spells pin'
    ' audit: bad ') == 1, 'd r362 kept'
assert s.count(
    'R361 UA MU 7th level spells pin'
    ' audit: bad ') == 1, 'd r361 kept'
assert s.count(
    'R360 UA MU 5th/6th level spells pin'
    ' audit: bad ') == 1, 'd r360 kept'
assert s.count(
    'R359 UA MU 4th level spells'
    ' pin audit: bad ') == 1, 'd r359 kept'
assert s.count(
    'R358 UA MU 3rd level spells'
    ' pin audit: bad ') == 1, 'd r358 kept'
assert s.count(
    'R357 UA MU 2nd level spells'
    ' pin audit: bad ') == 1, 'd r357 kept'
assert s.count(
    'R356 UA MU 1st level spells'
    ' pin audit: bad ') == 1, 'd r356 kept'
assert s.count('audit: bad ') == 290, 'd census 290'
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
assert s.count(
    'R227: the wis mental save'
    ) == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uailcantrips.h"'
    ) == 1, 'd cantrips include'
assert s.count(
    '#include "rules/uailspells1.h"'
    ) == 1, 'd spells1 include'
assert s.count(
    '#include "rules/uailspells2.h"'
    ) == 1, 'd spells2 include'
assert s.count(
    '#include "rules/uamuspells9.h"'
    ) == 1, 'd r362 include'
assert s.count(
    '#include "rules/uamuspells8.h"'
    ) == 1, 'd r362-8 include'
assert s.count(
    '#include "rules/uamuspells7.h"'
    ) == 1, 'd r361 include'
assert s.count(
    '#include "rules/uamuspells6.h"'
    ) == 1, 'd r360-6 include'
assert s.count(
    '#include "rules/uamuspells5.h"'
    ) == 1, 'd r360-5 include'
assert s.count(
    '#include "rules/uamuspells4.h"'
    ) == 1, 'd r359 include'
assert s.count(
    '#include "rules/uamuspells3.h"'
    ) == 1, 'd r358 include'
assert s.count(
    '#include "rules/uamuspells2.h"'
    ) == 1, 'd r357 include'
assert s.count(
    '#include "rules/uamuspells1.h"'
    ) == 1, 'd r356 include'
assert len(applied) + len(already) == 7, 'd count'


# ---- the summary ----
print('R363 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R363 note: the UA new illusionist')
print('spells pin round, the cantrips and')
print('the 1st and 2nd levels - the eight')
print('cantrip descriptions (colored')
print('lights with the globe ladder and')
print('the five-diameters illumination;')
print('dim with the half-radiance round;')
print('haze with the missile and save')
print('adjustments; mask; mirage with')
print('the cumulative waver; noise;')
print('rainbow with the gaze ladder; the')
print('two-d illusion, the eighth the')
print('item list missed); the chromatic')
print('orb with the color-by-level')
print('ladder and the special powers;')
print('phantom armor at the printed 1st;')
print('read magic and spook under the')
print('2ND LEVEL header; alter self and')
print('fascinate plus the ultravision and')
print('wind reprints; the R342 IL table')
print('seam prints only PHB names, none')
print('of the new names seam-checks;')
print('the levels stay open (3rd through')
print('7th); the census 289 -> 290')
print('commit: R363: the UA new')
print('illusionist cantrips and 1st/2nd')
print('level spells pin round')
print('(census 290)')

