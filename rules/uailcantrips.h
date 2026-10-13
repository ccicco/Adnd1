// ===========================================================================
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
//     numerals never print clean; RESOLVED (R421):
//     the clean PDF read pins all eight cells (the
//     uailcCastTimeDen family below).
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
//   - the R342 IL cantrip column: the scan read
//     it wholly lost - RESOLVED (R421): the clean
//     p. 31 read gives the whole column (the
//     uas2IlCantrip roster), the eight names
//     seam-checking this description roster row
//     for row, asserted in the audit.
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

// The reflection sentence: the PDF read
// resolves the garble (R421) - the
// illumination from any one globe will
// not cast reflections beyond 1 inch,
// and the light shed cannot be detected
// beyond 3 inches. The
// visual-capability read stands: pale
// blue or pink hues leave the visual
// capabilities undisturbed, other hues
// disturb them.
inline int uailcLightsReflectionBeyondInches()
    { return 1; }

inline int uailcLightsDetectedBeyondInches()
    { return 3; }

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

// The casting times: the PDF read (R421 -
// the clean p. 65-66 print) resolves the
// whole family - every cell a clean unit
// fraction, one segment over the
// denominator. The denominators, in roster
// order (colored lights, dim, haze and
// mirage at 1/2; rainbow at 1/3;
// mask, noise and the two-d-lusion at 1/8):
inline int uailcCastTimeDen(int i)
{
    static const int D[8] = { 2, 2, 2, 8,
        2, 8, 3, 8 };
    if (i < 0) i = 0;
    if (i > 7) i = 7;
    return D[i];
}

// The casting-time denominator census
// helper.
inline int uailcCastTimeDenCount(int d)
{
    int n = 0;
    for (int i = 0; i < 8; ++i)
        if (uailcCastTimeDen(i) == d)
            ++n;
    return n;
}

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

// The casting time: 1/2 segment (the PDF
// read - R421); rides uailcCastTimeDen(1).

// ---- haze (Alteration) ----
inline const char* uailcHazeName()
    { return "Haze (Alteration)"; }

// The area cell prints 7" cube - the digit-garble
// family decodes the 1-inch cube, flagged pending
// the PDF.
inline int uailcHazeAoeCubeInches()
    { return 1; }

// The area cell: the PDF read confirms
// the decode (R421) - the print reads
// 1" cube CLEAN; the decode flag amends
// away.

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

// The casting time: 1/2 segment (the PDF
// read - R421); rides uailcCastTimeDen(2).

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

// The casting time: 1/8 segment (the PDF
// read - R421); rides uailcCastTimeDen(3).

// ---- mirage ----
inline const char* uailcMirageName()
    { return "Mirage"; }

// The school cell: the PDF read resolves
// the loss (R421) - the header prints
// Mirage (Illusion).
inline bool uailcMirageSchoolIsIllusion()
    { return true; }

// The area cell: the PDF read resolves
// the fragment (R421) - the print
// reads 2 sq. " (two square inches).
inline int uailcMirageAoeSquareInches()
    { return 2; }

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

// The somatic tail: the PDF read resolves
// the garble (R421) - the caster
// speaks a word or two descriptive of the
// mirage and then makes a single pass
// to cause the magic to begin; it is
// maintained by concentration alone
// thereafter. The casting cell prints 1/2
// segment - rides uailcCastTimeDen(4).
inline bool uailcMirageWordOrTwoThenSinglePass()
    { return true; }

inline bool uailcMirageKeptByConcentrationAlone()
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

// The casting time: 1/8 segment (the PDF
// read - R421); rides uailcCastTimeDen(5).

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

// The casting time: 1/3 segment (the PDF
// read - R421); rides uailcCastTimeDen(6).

// ---- the two-d-lusion ----
// The name prints with an apostrophe: Two-D'lusion.
inline const char* uailcTwodName()
    { return "Two-D'lusion"; }

// The school cell: the PDF read resolves
// the loss (R421) - the header prints
// Two-D'lusion (Illusion).
inline bool uailcTwodSchoolIsIllusion()
    { return true; }

// The area-of-effect cell: the PDF read
// resolves the loss (R421) - the print
// reads 4 sq. " (four square inches).
inline int uailcTwodAoeSquareInches()
    { return 4; }

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

// The casting time: 1/8 segment (the PDF
// read - R421); rides uailcCastTimeDen(7).

}   // namespace rules

