# R364: the UA NEW ILLUSIONIST
# SPELLS pin round, the 3rd, 4th
# and 5th levels (pp. 68-71) -
# delude, phantom steed, phantom
# wind and wraithform under the
# printed third-level header (the
# delude/wraithform item-list 2nd
# divergence stands); dispel
# magic, rainbow pattern, solid
# fog and vacancy at 4th; the
# advanced illusion named from the
# item list, dream, the magic
# mirror reprint and tempus fugit
# at 5th. The R342 IL table 3rd-
# 6th columns are wholly lost -
# none of the new names
# seam-checks. The item stays
# open - the 6th and 7th levels
# pin in the next round.
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


# ---- (a) the seed: the R363 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R363 landed 2026-10-11: commit',
    '  3737448, census 290, the UA new',
    '  illusionist cantrips and 1st/2nd',
    '  level spells pin round',
    '  (rules/uailcantrips.h,',
    '  rules/uailspells1.h and',
    '  rules/uailspells2.h): the eight',
    '  cantrip descriptions (colored',
    '  lights with the globe ladder, dim,',
    '  haze, mask, mirage, noise, rainbow',
    '  and the two-d illusion the item',
    '  list missed), the chromatic orb',
    '  with the color-by-level ladder,',
    '  phantom armor at the printed 1st,',
    '  read magic, spook, alter self and',
    '  fascinate plus the ultravision and',
    '  wind reprints; the R342 IL table',
    '  seam prints only PHB names in the',
    '  readable columns; the delude and',
    '  wraithform third-level divergence',
    '  flagged pending the PDF; the item',
    '  stays open - the 3rd through 7th',
    '  levels pin later; GREEN on the',
    '  first run.',
])
s = rd(SD)
if 'R363 landed 2026-10-11' in s:
    already.append('seed: the R363 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R363 record')
s = rd(SD)
assert s.count('R363 landed 2026-10-11') == 1, 'a entry'
assert s.count(
    'R362 landed 2026-10-11') == 1, 'a R362 kept'
assert s.count(
    'R361 landed 2026-10-11') == 1, 'a R361 kept'
assert s.count(
    'R360 landed 2026-10-11') == 1, 'a R360 kept'
assert s.count(
    'R359 landed 2026-10-11') == 1, 'a R359 kept'
assert s.count(
    'R358 landed 2026-10-11') == 1, 'a R358 kept'
assert s.count(
    'R357 landed 2026-10-11') == 1, 'a R357 kept'
assert s.count(
    'R356 landed 2026-10-11') == 1, 'a R356 kept'
assert s.count(
    'R355 landed 2026-10-11') == 1, 'a R355 kept'
assert s.count(
    'R354 landed 2026-10-11') == 1, 'a R354 kept'
assert s.count(
    'R353 landed 2026-10-11') == 1, 'a R353 kept'
assert s.count(
    'R352 landed 2026-10-11') == 1, 'a R352 kept'
assert s.count(
    'R351 landed 2026-10-11') == 1, 'a R351 kept'
assert s.count(
    'R350 landed 2026-10-11') == 1, 'a R350 kept'
assert s.count(
    'R349 landed 2026-10-11') == 1, 'a R349 kept'
assert s.count(
    'R347 landed 2026-10-11') == 1, 'a R347 kept'
assert s.count(
    'R343 landed 2026-10-11') == 1, 'a R343 kept'
assert s.count(
    '## Knowledge maintenance') == 1, 'a maint'
assert len(applied) + len(already) == 1, 'a count'


# ---- (b) NEW rules/uailspells3.h ----
US3 = 'rules/uailspells3.h'
if os.path.exists(US3) and 'R364' in rd(US3):
    already.append('uailspells3.h: the pins')
else:
    HDR3 = r"""// ===========================================================================
// Adnd1 - rules/uailspells3.h
// The UA NEW ILLUSIONIST SPELLS (pp. 68-69) pins, R364:
// the 3rd-level spell descriptions - delude,
// phantom steed, phantom wind and wraithform.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists.
//
// JUDGMENTs (the decode method):
//   - the delude and wraithform level cells print the
//     clean 3 under the Third Level Spells header - the
//     item list (the R322 index) carries both at 2nd;
//     the print wins (the R363 phantom-armor
//     precedent), the divergence flagged in the round
//     note pending the PDF.
//   - phantom steed and phantom wind appear under the
//     same printed header but nowhere in the item
//     list (its 3rd-level claim says nothing new per
//     the headers) - both pinned as printed; the R342
//     IL table seam carries a Phantom Wind fragment
//     among its lost-column holes, corroborating the
//     wind.
//   - the wraithform casting cell prints 7 segment -
//     the digit-garble family (the R343 precedent,
//     the R363 chromatic-orb reuse) decodes the 1
//     segment.
//   - the bare-7 duration cells (phantom wind 7
//     round/level) and the empty cells (the phantom
//     steed casting time, the saving throw, the
//     phantom wind range) read as holes pending the
//     PDF - no corroborating print exists to decode
//     them, so no numeric pin.
//   - the phantom steed components cell prints V, S
//     with a trailing comma - the tail is lost, a
//     hole; the phantom wind and wraithform section
//     garbles (the section sign for S, the lllusion
//     school tail) decode per the R363 convention.
//   - the R342 IL table seam: the 3rd-level column is
//     wholly lost - none of the new names
//     seam-checks, asserted in the audit.
// ===========================================================================

#pragma once

namespace rules {

// ---- delude ----
// The components cell prints a bare V with a trailing
// comma - the tail is lost, a hole pending the PDF.
inline const char* uail3DeludeName()
    { return "Delude (Alteration)"; }

inline bool uail3DeludeVerbalComponent()
    { return true; }

inline bool uail3DeludeComponentsTailLost()
    { return true; }

inline int uail3DeludeLevel()
    { return 3; }

inline int uail3DeludeRangeInches()
    { return 0; }

inline int uail3DeludeCastingTimeSegments()
    { return 3; }

inline bool uail3DeludeSaveNegates()
    { return true; }

inline int uail3DeludeDurationTurnsPerLevel()
    { return 1; }

inline bool uail3DeludeAoeTheIllusionist()
    { return true; }

// The aura exchange radius: 3 inches.
inline int uail3DeludeAuraRadiusInches()
    { return 3; }

inline bool uail3DeludeTargetMustExceedAnimalInt()
    { return true; }

inline bool uail3DeludeTargetRetainsAlignment()
    { return true; }

inline bool uail3DeludeKnowAlignmentSeesAuraOnly()
    { return true; }

inline bool uail3DeludeDetectSeesSubstitutedAura()
    { return true; }

inline bool uail3DeludeCopiedCreatureRadiatesMagic()
    { return true; }

inline bool uail3DeludeCasterRadiatesToSourceOnly()
    { return true; }

inline bool uail3DeludeWithChangeOrAlterSelfHides()
    { return true; }

inline bool uail3DeludeSaveOnlyOnAuraTransfer()
    { return true; }

// ---- phantom steed ----
// The casting-time cell garbles (a bare Casting Tim)
// and the saving-throw cell prints empty - holes
// pending the PDF.
inline const char* uail3SteedName()
    { return "Phantom Steed (Conjuration/Phantasm)"; }

inline int uail3SteedLevel()
    { return 3; }

inline bool uail3SteedComponentsVerbalSomatic()
    { return true; }

inline bool uail3SteedComponentsTailLost()
    { return true; }

inline bool uail3SteedRangeTouch()
    { return true; }

inline bool uail3SteedCastingTimeCellGarbled()
    { return true; }

inline int uail3SteedDurationTurnsPerLevel()
    { return 6; }

inline bool uail3SteedSaveCellEmpty()
    { return true; }

inline bool uail3SteedAoeSpecial()
    { return true; }

inline bool uail3SteedQuasiRealHorseLike()
    { return true; }

inline bool uail3SteedRiddenOnlyByCasterOrNamed()
    { return true; }

inline bool uail3SteedBlackHeadsAndBodies()
    { return true; }

inline bool uail3SteedGrayManesAndTails()
    { return true; }

inline bool uail3SteedSmokeColoredHooves()
    { return true; }

inline bool uail3SteedHoovesMakeNoSound()
    { return true; }

inline bool uail3SteedMilkyEyes()
    { return true; }

inline bool uail3SteedDoesNotFight()
    { return true; }

inline bool uail3SteedNormalAnimalsShun()
    { return true; }

inline bool uail3SteedOnlyMonstrousAnimalsAttack()
    { return true; }

// More than 12 points of damage dispels the steed.
inline int uail3SteedDamageToDispel()
    { return 12; }

inline int uail3SteedMaxRateInchesPerLevel()
    { return 4; }

inline bool uail3SteedSeemingSaddleAndBridle()
    { return true; }

inline bool uail3SteedCannotCarrySaddlebags()
    { return true; }

inline bool uail3SteedPower8thSoftGround()
    { return true; }

inline bool uail3SteedPower10thOverWater()
    { return true; }

inline bool uail3SteedPower12thAirTravel()
    { return true; }

inline bool uail3SteedPower12thNoCasualFlight()
    { return true; }

inline bool uail3SteedPower14thAsPegasus()
    { return true; }

// ---- phantom wind ----
// The components cell prints V with a section sign -
// the R363 convention decodes the somatic S; the range
// cell prints empty and the duration cell prints a
// bare 7 round/level - holes pending the PDF (no
// corroborating print exists to decode the 7).
inline const char* uail3PwindName()
    { return "Phantom Wind (Alteration/Phantasm)"; }

inline int uail3PwindLevel()
    { return 3; }

inline bool uail3PwindComponentsVerbalSomatic()
    { return true; }

inline int uail3PwindCastingTimeSegments()
    { return 3; }

inline bool uail3PwindRangeCellEmpty()
    { return true; }

inline bool uail3PwindSaveNone()
    { return true; }

inline bool uail3PwindDurationCellSuspectGarble()
    { return true; }

inline int uail3PwindAoeInchesBroadPath()
    { return 1; }

inline bool uail3PwindCannotBeSeenOrFelt()
    { return true; }

inline bool uail3PwindBlowsLightObjects()
    { return true; }

inline bool uail3PwindFluttersCurtainsAndDrapes()
    { return true; }

inline bool uail3PwindFlapsLooseClothing()
    { return true; }

inline bool uail3PwindFansFires()
    { return true; }

inline bool uail3PwindMovesGaseousClouds()
    { return true; }

inline bool uail3PwindMovesInPointedDirection()
    { return true; }

inline int uail3PwindPathGrowsInchesPerRound()
    { return 1; }

inline bool uail3PwindEffectsLastWholePath()
    { return true; }

// The vessel sentence interleaves as fragments (es
// the one iled to vessels) - a hole pending the PDF.
inline bool uail3PwindVesselSentenceGarbled()
    { return true; }

// ---- wraithform ----
// The stat tail prints displaced after the prose (the
// components and casting-time cells follow the
// description); the school tail garbles (lllusion)
// and decodes per the R363 convention; the casting
// cell prints 7 segment - the R343 digit-garble
// precedent decodes the 1 segment.
inline const char* uail3WraithName()
    { return "Wraithform (Alteration/Illusion)"; }

inline int uail3WraithLevel()
    { return 3; }

inline int uail3WraithRangeInches()
    { return 0; }

inline int uail3WraithDurationRoundsPerLevel()
    { return 2; }

inline bool uail3WraithAoeTheIllusionist()
    { return true; }

inline bool uail3WraithComponentsSomaticMaterial()
    { return true; }

inline int uail3WraithCastingTimeSegments()
    { return 1; }

inline bool uail3WraithSaveNone()
    { return true; }

inline bool uail3WraithInsubstantialWithGear()
    { return true; }

inline bool uail3WraithHitOnlyByPlusOneOrBetter()
    { return true; }

inline bool uail3WraithEtherealAbleCreaturesHit()
    { return true; }

inline bool uail3WraithMostUndeadIgnore()
    { return true; }

inline bool uail3WraithAppearsAsWraithOrSpectre()
    { return true; }

inline bool uail3WraithLichMayRecognize()
    { return true; }

// The lich save versus spell carries the -4 penalty.
inline int uail3WraithLichRecognizeSaveMod()
    { return -4; }

inline bool uail3WraithPassesThroughCracksWithGear()
    { return true; }

inline bool uail3WraithNoAttacksExceptVsEthereal()
    { return true; }

inline bool uail3WraithEtherealCombatNormalBothWays()
    { return true; }

inline bool uail3WraithDispelForcesNormalForm()
    { return true; }

inline bool uail3WraithReturnAtWillEndsSpell()
    { return true; }

// The material components: a bit of gauze and a wisp
// of smoke.
inline bool uail3WraithComponentsGauzeAndSmoke()
    { return true; }

}   // namespace rules
"""
    clean(HDR3, 78)
    wr(US3, HDR3 + NL)
    applied.append('uailspells3.h: the pins')
s = rd(US3)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 85, 'b inline count'
assert s.count('R364') == 1, 'b round tag'
assert s.count('uail3DeludeName()') == 1, 'b delude fn'
assert s.count('uail3SteedName()') == 1, 'b steed fn'
assert s.count('uail3PwindName()') == 1, 'b pwind fn'
assert s.count('uail3WraithName()') == 1, 'b wraith fn'
assert 'uam' not in s, 'b no mu ref'
assert 'uadruid' not in s, 'b no druid ref'
assert 'uailc' not in s, 'b no cantrip ref'
assert 'uail1' not in s, 'b no 1st ref'
assert 'uail2' not in s, 'b no 2nd ref'
assert len(applied) + len(already) == 2, 'b count'


# ---- (b2) NEW rules/uailspells4.h ----
US4 = 'rules/uailspells4.h'
if os.path.exists(US4) and 'R364' in rd(US4):
    already.append('uailspells4.h: the pins')
else:
    HDR4 = r"""// ===========================================================================
// Adnd1 - rules/uailspells4.h
// The UA NEW ILLUSIONIST SPELLS (pp. 69-70) pins,
// R364: the 4th-level spell descriptions - dispel
// magic, rainbow pattern, solid fog and vacancy.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists.
//
// JUDGMENTs (the decode method):
//   - the vacancy level cell prints the clean 4 - it
//     matches the item list; the print sits between a
//     stray 5TH LEVEL header and the Fifth Level
//     Spells header - the level cell wins, the header
//     noise noted.
//   - the solid fog level cell does not print - the
//     level pins from the Fourth Level Spells section
//     header (the R363 read-magic precedent); its
//     area cell prints 2 cubic with the unit lost and
//     its component cell garbles (a peas/hoof fragment
//     pile) - holes pending the PDF.
//   - the dispel magic area cell interleaves with the
//     prose (the 3 inch cube fragments) - the cell
//     decodes from the fragments; the two-levels-below
//     cast read and the clerical cross-reference pin
//     from the prose.
//   - the rainbow pattern casting-time cell prints a
//     bare Casting Time - the value is lost, a hole.
//   - the section sign components cells (dispel
//     magic) decode to the somatic S per the R363
//     convention.
//   - the bare-7 duration cell (vacancy 7 turn/level)
//     reads as a hole pending the PDF - no
//     corroborating print exists to decode it, so no
//     numeric pin.
//   - the R342 IL table seam: the 4th-level column is
//     wholly lost - none of the new names
//     seam-checks, asserted in the audit.
// ===========================================================================

#pragma once

namespace rules {

// ---- dispel magic ----
// The area cell interleaves with the prose; the
// fragments (3 inch cube, identical to the 3rd-level
// clerical spell) decode the cell.
inline const char* uail4DispelName()
    { return "Dispel Magic (Abjuration)"; }

inline int uail4DispelLevel()
    { return 4; }

inline int uail4DispelRangeInches()
    { return 9; }

inline bool uail4DispelDurationPermanent()
    { return true; }

inline int uail4DispelAoeInchesCube()
    { return 3; }

inline bool uail4DispelAoeCellInterleaved()
    { return true; }

inline bool uail4DispelComponentsVerbalSomatic()
    { return true; }

inline int uail4DispelCastingTimeSegments()
    { return 4; }

inline bool uail4DispelSaveNone()
    { return true; }

inline bool uail4DispelSameAsClericalThirdLevel()
    { return true; }

inline bool uail4DispelCastsTwoLevelsBelow()
    { return true; }

inline bool uail4DispelExampleNinthCastsAsSeventh()
    { return true; }

// ---- rainbow pattern ----
// The casting-time cell prints a bare Casting Time -
// the value is lost, a hole pending the PDF.
inline const char* uail4RainbowName()
    { return "Rainbow Pattern (Alteration/Phantasm)"; }

inline int uail4RainbowLevel()
    { return 4; }

inline bool uail4RainbowComponentsSomaticMaterial()
    { return true; }

inline bool uail4RainbowCastingTimeCellLost()
    { return true; }

inline int uail4RainbowRangeInches()
    { return 1; }

inline bool uail4RainbowSaveNegates()
    { return true; }

inline bool uail4RainbowDurationSpecial()
    { return true; }

inline int uail4RainbowAoeInchesSquare()
    { return 3; }

inline bool uail4RainbowPastelGlowingBand()
    { return true; }

inline bool uail4RainbowSameEffectAsHypnoticPattern()
    { return true; }

inline bool uail4RainbowMovesInGesturedDirection()
    { return true; }

inline int uail4RainbowSpeedInchesPerRound()
    { return 3; }

inline int uail4RainbowPersistsRoundsMin()
    { return 1; }

inline int uail4RainbowPersistsRoundsMax()
    { return 3; }

inline int uail4RainbowFollowerLevelsOrHdCap()
    { return 24; }

inline bool uail4RainbowDangerAllowsSecondSave()
    { return true; }

inline bool uail4RainbowBlockedViewNegates()
    { return true; }

inline bool uail4RainbowObscurementExample()
    { return true; }

// The material components: a crystal prism and a
// piece of phosphor.
inline bool uail4RainbowComponentsPrismPhosphor()
    { return true; }

// ---- solid fog ----
// The level cell does not print - the level pins from
// the Fourth Level Spells section header (the R363
// read-magic precedent); the area cell prints 2 cubic
// with the unit lost and the component cell garbles -
// holes pending the PDF.
inline const char* uail4FogName()
    { return "Solid Fog (Alteration)"; }

inline int uail4FogLevel()
    { return 4; }

inline bool uail4FogLevelCellLost()
    { return true; }

inline int uail4FogDurationRoundsBaseMin()
    { return 2; }

inline int uail4FogDurationRoundsBaseMax()
    { return 8; }

inline int uail4FogDurationPlusPerLevel()
    { return 1; }

inline int uail4FogAoeCubicPerLevel()
    { return 2; }

inline bool uail4FogAoeUnitCellLost()
    { return true; }

inline bool uail4FogComponentsVSM()
    { return true; }

inline int uail4FogCastingTimeSegments()
    { return 4; }

inline bool uail4FogSaveNone()
    { return true; }

inline bool uail4FogRollingBillowingWallOfFog()
    { return true; }

inline bool uail4FogOnlyVeryStrongWindMoves()
    { return true; }

inline bool uail4FogGustOfWindCannotAffect()
    { return true; }

// Movement through the fog: 1 inch of normal rate
// per inch of fog per round.
inline int uail4FogMoveInchesPerRound()
    { return 1; }

inline bool uail4FogFireballBurnsAwayOneRound()
    { return true; }

inline bool uail4FogFlameStrikeBurnsAway()
    { return true; }

inline bool uail4FogWallOfFireBurnsAway()
    { return true; }

inline bool uail4FogComponentCellGarbled()
    { return true; }

// ---- vacancy ----
// The duration cell prints a bare 7 turn/level - a
// hole pending the PDF (no corroborating print
// exists to decode the 7); the area cell interleaves
// (the 1 inch radius per level fragments).
inline const char* uail4VacancyName()
    { return "Vacancy (Alteration/Phantasm)"; }

inline int uail4VacancyLevel()
    { return 4; }

inline bool uail4VacancyComponentsVSM()
    { return true; }

inline int uail4VacancyCastingTimeSegments()
    { return 4; }

inline int uail4VacancyRangeInchesPerLevel()
    { return 1; }

inline bool uail4VacancySaveNone()
    { return true; }

inline bool uail4VacancyDurationCellSuspectGarble()
    { return true; }

inline int uail4VacancyAoeRadiusInchesPerLevel()
    { return 1; }

inline bool uail4VacancyAreaSeemsVacantNeglected()
    { return true; }

inline bool uail4VacancyDustCobwebsDirtTypical()
    { return true; }

inline bool uail4VacancyPassageSeemsToLeaveTracks()
    { return true; }

inline bool uail4VacancyPassageTearsCobwebs()
    { return true; }

inline bool uail4VacancyOnlyForcefulContactDisturbs()
    { return true; }

inline bool uail4VacancyCloaksOnlyNonLivingThings()
    { return true; }

inline bool uail4VacancyLivingThingsNotInvisible()
    { return true; }

inline bool uail4VacancyForcefulContactGrantsSaves()
    { return true; }

inline bool uail4VacancyFailedSaveBelievesInvisible()
    { return true; }

inline bool uail4VacancyDispelRemovesDweomer()
    { return true; }

inline bool uail4VacancyTrueSeeingPenetrates()
    { return true; }

inline bool uail4VacancyGemOfSeeingPenetrates()
    { return true; }

inline bool uail4VacancyDetectInvisibilityCannot()
    { return true; }

// The material component: a square of finest black
// silk of not less than 100 gp value.
inline int uail4VacancySilkMinGpValue()
    { return 100; }

}   // namespace rules
"""
    clean(HDR4, 78)
    wr(US4, HDR4 + NL)
    applied.append('uailspells4.h: the pins')
s = rd(US4)
assert s.count('namespace rules {') == 1, 'b2 ns'
assert s.count('inline') == 72, 'b2 inline count'
assert s.count('R364') == 1, 'b2 round tag'
assert s.count('uail4DispelName()') == 1, 'b2 dispel fn'
assert s.count('uail4RainbowName()') == 1, 'b2 rainbow fn'
assert s.count('uail4FogName()') == 1, 'b2 fog fn'
assert s.count('uail4VacancyName()') == 1, 'b2 vacancy fn'
assert 'uam' not in s, 'b2 no mu ref'
assert 'uadruid' not in s, 'b2 no druid ref'
assert 'uailc' not in s, 'b2 no cantrip ref'
assert 'uail1' not in s, 'b2 no 1st ref'
assert 'uail2' not in s, 'b2 no 2nd ref'
assert 'uail3' not in s, 'b2 no 3rd ref'
assert len(applied) + len(already) == 3, 'b2 count'


# ---- (b3) NEW rules/uailspells5.h ----
US5 = 'rules/uailspells5.h'
if os.path.exists(US5) and 'R364' in rd(US5):
    already.append('uailspells5.h: the pins')
else:
    HDR5 = r"""// ===========================================================================
// Adnd1 - rules/uailspells5.h
// The UA NEW ILLUSIONIST SPELLS (pp. 70-71) pins,
// R364: the 5th-level spell descriptions - the
// advanced illusion, dream, magic mirror and tempus
// fugit.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists.
//
// JUDGMENTs (the decode method):
//   - the first name header garbles to a bare (lllusi )
//     parenthesis fragment - the name pins from the
//     gap item list (the R363 chromatic-orb
//     precedent): advanced illusion; the prose
//     program spell cross-reference garbles and its
//     components (a bit of fleece and several grains
//     of sand) corroborate the identification.
//   - the bare-7 cells (the advanced illusion and
//     magic mirror durations, both 7 round/level; the
//     dream casting time, 7 day) read as holes pending
//     the PDF - the R343 digit-garble precedent
//     decoded only the 7 segment form with its
//     corroborated 1, and no corroborating print
//     exists here, so no numeric pin.
//   - the magic mirror is a cross-reference reprint
//     (virtually the same as the 4th-level magic-user
//     spell); its dollar-sign components cell decodes
//     to V, S, M per the R363 symbol-garble
//     convention.
//   - the tempus fugit area cell prints 7 radius -
//     unlike the per-level duration cells an area
//     radius has no corroborating print either way;
//     pinned as printed, the doubt noted pending the
//     PDF.
//   - the R342 IL table seam: the 5th-level column is
//     wholly lost - none of the new names
//     seam-checks, asserted in the audit.
// ===========================================================================

#pragma once

namespace rules {

// ---- advanced illusion ----
// The name header garbles to a bare (lllusi )
// fragment - the name pins from the gap item list;
// the prose cross-reference garbles (the similar-to
// fragment), a hole pending the PDF.
inline const char* uail5AdvilName()
    { return "Advanced Illusion (Illusion/Phantasm)"; }

inline bool uail5AdvilNameHeaderGarbled()
    { return true; }

inline int uail5AdvilLevel()
    { return 5; }

inline bool uail5AdvilComponentsVSM()
    { return true; }

inline int uail5AdvilCastingTimeSegments()
    { return 5; }

inline int uail5AdvilRangeInches()
    { return 6; }

inline int uail5AdvilRangeInchesPerLevel()
    { return 1; }

inline bool uail5AdvilSaveSpecial()
    { return true; }

inline bool uail5AdvilDurationCellSuspectGarble()
    { return true; }

inline int uail5AdvilAoeSquares()
    { return 4; }

inline int uail5AdvilAoeSquaresPerLevel()
    { return 1; }

inline bool uail5AdvilAoeCellInterleaved()
    { return true; }

inline bool uail5AdvilProgramSpell()
    { return true; }

inline bool uail5AdvilCrossRefCellGarbled()
    { return true; }

// The caster need only concentrate 5 segments after
// casting; the program then runs alone.
inline int uail5AdvilConcentrationSegments()
    { return 5; }

inline bool uail5AdvilProgramRunsAlone()
    { return true; }

inline bool uail5AdvilVisualComponent()
    { return true; }

inline bool uail5AdvilFullAudialComponent()
    { return true; }

inline bool uail5AdvilOlfactoryComponent()
    { return true; }

inline bool uail5AdvilThermalComponent()
    { return true; }

inline bool uail5AdvilActiveDisbelieveGrantsSave()
    { return true; }

inline int uail5AdvilCommunicatedDisbeliefBonus()
    { return 4; }

// The material components: a bit of fleece and
// several grains of sand - they corroborate the
// name decode.
inline bool uail5AdvilComponentsFleeceAndSand()
    { return true; }

// ---- dream ----
// The casting-time cell prints a bare 7 day - a hole
// pending the PDF (no corroborating print exists to
// decode the 7).
inline const char* uail5DreamName()
    { return "Dream (Alteration - Illusion/Phantasm)"; }

inline int uail5DreamLevel()
    { return 5; }

inline bool uail5DreamRangeSpecial()
    { return true; }

inline bool uail5DreamDurationSpecial()
    { return true; }

inline bool uail5DreamAoeSpecial()
    { return true; }

inline bool uail5DreamComponentsSpecial()
    { return true; }

inline bool uail5DreamCastingTimeCellSuspectGarble()
    { return true; }

inline bool uail5DreamSaveNegates()
    { return true; }

inline bool uail5DreamLimitedWishForm()
    { return true; }

inline bool uail5DreamMoreLimitedScope()
    { return true; }

inline bool uail5DreamMustLieProneAndSleep()
    { return true; }

inline int uail5DreamUndisturbedSleepHours()
    { return 8; }

inline int uail5DreamEffectuatedHoursMin()
    { return 1; }

inline int uail5DreamEffectuatedHoursMax()
    { return 12; }

inline bool uail5DreamResultRecoverLostHp()
    { return true; }

inline bool uail5DreamResultRestoreBodyMember()
    { return true; }

inline bool uail5DreamResultLocateUnguardedObject()
    { return true; }

inline bool uail5DreamResultDiscoverIngressEgress()
    { return true; }

inline bool uail5DreamResultSafeWildernessPath()
    { return true; }

inline bool uail5DreamResultImproveTreasureChances()
    { return true; }

// A scried creature of the printed hit-dice threshold
// may save; the threshold prints the clean 7 in the
// prose (unlike the stat-cell garbles), pinned as
// printed pending the PDF.
inline int uail5DreamScriedSaveHdThreshold()
    { return 7; }

inline bool uail5DreamScriedSaveHidesFromDream()
    { return true; }

inline bool uail5DreamScriedMaySenseCaster()
    { return true; }

inline bool uail5DreamResultsStrictlyLimited()
    { return true; }

inline bool uail5DreamNeverExceedsOnPermanentBasis()
    { return true; }

inline int uail5DreamCompanionTurnsPerLevel()
    { return 1; }

inline bool uail5DreamUnaffectedByExtensionOrPermanency()
    { return true; }

inline bool uail5DreamOncePerWeek()
    { return true; }

inline bool uail5DreamSecondCastInWeekFails()
    { return true; }

inline int uail5DreamSecondCastAgesYearsMin()
    { return 1; }

inline int uail5DreamSecondCastAgesYearsMax()
    { return 10; }

// ---- magic mirror ----
// A cross-reference reprint: virtually the same as
// the 4th-level magic-user spell of the same name;
// the dollar-sign components cell decodes to V, S, M
// per the R363 symbol-garble convention; the
// duration cell prints a bare 7 round/level - a hole
// pending the PDF.
inline const char* uail5MirrorName()
    { return "Magic Mirror (Enchantment - Divination)"; }

inline int uail5MirrorLevel()
    { return 5; }

inline bool uail5MirrorComponentsVSM()
    { return true; }

inline int uail5MirrorCastingTimeHours()
    { return 1; }

inline bool uail5MirrorRangeTouch()
    { return true; }

inline bool uail5MirrorSaveNone()
    { return true; }

inline bool uail5MirrorDurationCellSuspectGarble()
    { return true; }

inline bool uail5MirrorAoeSpecial()
    { return true; }

inline bool uail5MirrorSameAsFourthLevelMuSpell()
    { return true; }

inline bool uail5MirrorSameMaterialComponents()
    { return true; }

inline bool uail5MirrorVisionSpellReplacesComponents()
    { return true; }

inline bool uail5MirrorStillScrysWithVision()
    { return true; }

inline bool uail5MirrorVisionDoesNotFunctionNormally()
    { return true; }

// ---- tempus fugit ----
// The area cell prints 7 radius - pinned as printed
// (an area radius has no corroborating print either
// way), the doubt noted pending the PDF.
inline const char* uail5TempusName()
    { return "Tempus Fugit (Illusion/Phantasm)"; }

inline bool uail5TempusReversible()
    { return true; }

inline int uail5TempusLevel()
    { return 5; }

inline bool uail5TempusComponentsVerbalSomatic()
    { return true; }

inline int uail5TempusCastingTimeSegments()
    { return 5; }

inline int uail5TempusRangeInches()
    { return 0; }

inline bool uail5TempusSaveNone()
    { return true; }

inline int uail5TempusDurationTurnsPerLevel()
    { return 5; }

inline int uail5TempusAoeRadiusInches()
    { return 7; }

inline bool uail5TempusAffectsMindsAndBodies()
    { return true; }

inline bool uail5TempusLatecomersAlsoAffected()
    { return true; }

inline bool uail5TempusTurnSeemsLikeAnHour()
    { return true; }

inline bool uail5TempusFunctionsSpedUp()
    { return true; }

inline bool uail5TempusOtherSpellDurationsSped()
    { return true; }

inline bool uail5TempusOneHourIsAsSix()
    { return true; }

inline bool uail5TempusFourHoursAFullDay()
    { return true; }

inline bool uail5TempusAllowsRestRenewalRecovery()
    { return true; }

inline bool uail5TempusReversalSlowsTime()
    { return true; }

inline bool uail5TempusReverseHourSeemsATurn()
    { return true; }

inline bool uail5TempusReverseDayMereFourHours()
    { return true; }

inline bool uail5TempusReversalNeedsNoPreparation()
    { return true; }

inline bool uail5TempusCasterAlsoAffected()
    { return true; }

// Under the reverse the effects last at least 1 turn
// after the caster desires the dispelling (the
// slowed-reactions read).
inline int uail5TempusReverseLingersTurnsMin()
    { return 1; }

inline bool uail5TempusReverseLingersBySlowReactions()
    { return true; }

}   // namespace rules
"""
    clean(HDR5, 78)
    wr(US5, HDR5 + NL)
    applied.append('uailspells5.h: the pins')
s = rd(US5)
assert s.count('namespace rules {') == 1, 'b3 ns'
assert s.count('inline') == 91, 'b3 inline count'
assert s.count('R364') == 1, 'b3 round tag'
assert s.count('uail5AdvilName()') == 1, 'b3 advil fn'
assert s.count('uail5DreamName()') == 1, 'b3 dream fn'
assert s.count('uail5MirrorName()') == 1, 'b3 mirror fn'
assert s.count('uail5TempusName()') == 1, 'b3 tempus fn'
assert 'uam' not in s, 'b3 no mu ref'
assert 'uadruid' not in s, 'b3 no druid ref'
assert 'uailc' not in s, 'b3 no cantrip ref'
assert 'uail1' not in s, 'b3 no 1st ref'
assert 'uail2' not in s, 'b3 no 2nd ref'
assert 'uail3' not in s, 'b3 no 3rd ref'
assert 'uail4' not in s, 'b3 no 4th ref'
assert len(applied) + len(already) == 4, 'b3 count'


# ---- (c) the gap report: the note ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'R364: the 3rd, 4th and' in s:
    already.append('gap report: the note')
else:
    TAIL_OLD = NL.join([
        '        levels stay open.',
        '',
        '## Cantrips (a category of their own)',
    ])
    assert s.count(TAIL_OLD) == 1, 'c tail'
    NOTE = NL.join([
        '      - R364: the 3rd, 4th and 5th',
        '        levels pinned',
        '        (rules/uailspells3.h,',
        '        rules/uailspells4.h and',
        '        rules/uailspells5.h) - delude',
        '        and wraithform pinned at the',
        '        printed 3rd (the Level: 3',
        '        cells; the item-list 2nd',
        '        divergence stands, pending',
        '        the PDF); phantom steed and',
        '        phantom wind, absent from',
        '        the item list, pinned as',
        '        the print adds them under',
        '        the Third Level Spells',
        '        header; dispel magic,',
        '        rainbow pattern, solid fog',
        '        and vacancy at 4th (the',
        '        vacancy Level: 4 cell',
        '        matches the item list; the',
        '        solid fog level cell lost,',
        '        pinned from the section',
        '        header); the advanced',
        '        illusion named from the',
        '        item list (the name header',
        '        garbles), dream, magic',
        '        mirror and tempus fugit at',
        '        5th; the bare-7 cells read',
        '        as holes pending the PDF;',
        '        the R342 IL table 3rd-6th',
        '        columns stay lost; the 6th',
        '        and 7th levels pin in the',
        '        next round.',
    ])
    clean(NOTE, 57)
    s = s.replace(TAIL_OLD, NL.join([
        '        levels stay open.',
        NOTE,
        '',
        '## Cantrips (a category of their own)',
    ]))
    wr(GP, s)
    applied.append('gap report: the note')
s = rd(GP)
assert s.count('R364: the 3rd, 4th and') == 1, 'c note'
assert s.count('R363: the cantrips and the') == 1, 'c r363 kept'
assert s.count(
    '- [ ] **The new illusionist spells**'
) == 1, 'c open header'
assert s.count(
    '- [ ] **The illusionist cantrips**'
) == 1, 'c cantrips header'
assert s.count(
    '- [ ] **The cantrip acquisition rules**'
) == 1, 'c cantrips rules kept'
assert s.count(
    '- [x] **The new magic-user spells**'
    ) == 1, 'c mu closed kept'
assert s.count(
    '## Cantrips (a category of their own)'
) == 1, 'c cantrips section'
assert len(applied) + len(already) == 5, 'c count'


# ---- (d) regtest.cpp: the includes, the
# audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R364 UA IL 3rd/4th/5th spells pin' in s:
    already.append('regtest.cpp: the R364 audit')
else:
    INC_ANCH = (
        '#include "rules/uailspells2.h"'
        '  // R363: the UA new illusionist'
        ' 2nd level')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uailspells3.h"'
        '  // R364: the UA new illusionist'
        ' 3rd level',
        '#include "rules/uailspells4.h"'
        '  // R364: the UA new illusionist'
        ' 4th level',
        '#include "rules/uailspells5.h"'
        '  // R364: the UA new illusionist'
        ' 5th level',
    ])
    AUD_ANCH = (
        '    // ---- R227: the wis mental save'
        ' wiring audit ----')
    AUDIT = r"""    // ---- R364: the UA new illusionist
    // 3rd/4th/5th level spells pin
    // audit ----
    // The UA NEW ILLUSIONIST SPELLS
    // (pp. 68-71) - the 3rd-level four
    // (delude with the aura exchange,
    // the phantom steed with the
    // level-power ladder, the phantom
    // wind and wraithform with the
    // casting-time decode); the 4th-
    // level four (dispel magic with the
    // two-levels-below read, rainbow
    // pattern with the follower cap,
    // solid fog, vacancy); the 5th-
    // level four (the advanced illusion
    // named from the item list, dream
    // with the once-per-week aging tail,
    // the magic mirror reprint, tempus
    // fugit reversible). The R342 IL
    // table 3rd-6th columns are wholly
    // lost - none of the new names
    // seam-checks. The item stays open -
    // the 6th and 7th levels pin in the
    // next round.
    {
        using namespace rules;
        int bad = 0;
        // ---- delude ----
        // ---- phantom steed ----
        // ---- phantom wind ----
        // ---- wraithform ----
            if (strcmp(uail3DeludeName(),
                "Delude (Alteration)") != 0) ++bad;
            if (!uail3DeludeVerbalComponent()) ++bad;
            if (!uail3DeludeComponentsTailLost()) ++bad;
            if (uail3DeludeLevel() != 3) ++bad;
            if (uail3DeludeRangeInches() != 0) ++bad;
            if (uail3DeludeCastingTimeSegments() != 3) ++bad;
            if (!uail3DeludeSaveNegates()) ++bad;
            if (uail3DeludeDurationTurnsPerLevel() != 1) ++bad;
            if (!uail3DeludeAoeTheIllusionist()) ++bad;
            if (uail3DeludeAuraRadiusInches() != 3) ++bad;
            if (!uail3DeludeTargetMustExceedAnimalInt()) ++bad;
            if (!uail3DeludeTargetRetainsAlignment()) ++bad;
            if (!uail3DeludeKnowAlignmentSeesAuraOnly()) ++bad;
            if (!uail3DeludeDetectSeesSubstitutedAura()) ++bad;
            if (!uail3DeludeCopiedCreatureRadiatesMagic()) ++bad;
            if (!uail3DeludeCasterRadiatesToSourceOnly()) ++bad;
            if (!uail3DeludeWithChangeOrAlterSelfHides()) ++bad;
            if (!uail3DeludeSaveOnlyOnAuraTransfer()) ++bad;
            if (strcmp(uail3SteedName(),
                "Phantom Steed (Conjuration/Phantasm)") != 0) ++bad;
            if (uail3SteedLevel() != 3) ++bad;
            if (!uail3SteedComponentsVerbalSomatic()) ++bad;
            if (!uail3SteedComponentsTailLost()) ++bad;
            if (!uail3SteedRangeTouch()) ++bad;
            if (!uail3SteedCastingTimeCellGarbled()) ++bad;
            if (uail3SteedDurationTurnsPerLevel() != 6) ++bad;
            if (!uail3SteedSaveCellEmpty()) ++bad;
            if (!uail3SteedAoeSpecial()) ++bad;
            if (!uail3SteedQuasiRealHorseLike()) ++bad;
            if (!uail3SteedRiddenOnlyByCasterOrNamed()) ++bad;
            if (!uail3SteedBlackHeadsAndBodies()) ++bad;
            if (!uail3SteedGrayManesAndTails()) ++bad;
            if (!uail3SteedSmokeColoredHooves()) ++bad;
            if (!uail3SteedHoovesMakeNoSound()) ++bad;
            if (!uail3SteedMilkyEyes()) ++bad;
            if (!uail3SteedDoesNotFight()) ++bad;
            if (!uail3SteedNormalAnimalsShun()) ++bad;
            if (!uail3SteedOnlyMonstrousAnimalsAttack()) ++bad;
            if (uail3SteedDamageToDispel() != 12) ++bad;
            if (uail3SteedMaxRateInchesPerLevel() != 4) ++bad;
            if (!uail3SteedSeemingSaddleAndBridle()) ++bad;
            if (!uail3SteedCannotCarrySaddlebags()) ++bad;
            if (!uail3SteedPower8thSoftGround()) ++bad;
            if (!uail3SteedPower10thOverWater()) ++bad;
            if (!uail3SteedPower12thAirTravel()) ++bad;
            if (!uail3SteedPower12thNoCasualFlight()) ++bad;
            if (!uail3SteedPower14thAsPegasus()) ++bad;
            if (strcmp(uail3PwindName(),
                "Phantom Wind (Alteration/Phantasm)") != 0) ++bad;
            if (uail3PwindLevel() != 3) ++bad;
            if (!uail3PwindComponentsVerbalSomatic()) ++bad;
            if (uail3PwindCastingTimeSegments() != 3) ++bad;
            if (!uail3PwindRangeCellEmpty()) ++bad;
            if (!uail3PwindSaveNone()) ++bad;
            if (!uail3PwindDurationCellSuspectGarble()) ++bad;
            if (uail3PwindAoeInchesBroadPath() != 1) ++bad;
            if (!uail3PwindCannotBeSeenOrFelt()) ++bad;
            if (!uail3PwindBlowsLightObjects()) ++bad;
            if (!uail3PwindFluttersCurtainsAndDrapes()) ++bad;
            if (!uail3PwindFlapsLooseClothing()) ++bad;
            if (!uail3PwindFansFires()) ++bad;
            if (!uail3PwindMovesGaseousClouds()) ++bad;
            if (!uail3PwindMovesInPointedDirection()) ++bad;
            if (uail3PwindPathGrowsInchesPerRound() != 1) ++bad;
            if (!uail3PwindEffectsLastWholePath()) ++bad;
            if (!uail3PwindVesselSentenceGarbled()) ++bad;
            if (strcmp(uail3WraithName(),
                "Wraithform (Alteration/Illusion)") != 0) ++bad;
            if (uail3WraithLevel() != 3) ++bad;
            if (uail3WraithRangeInches() != 0) ++bad;
            if (uail3WraithDurationRoundsPerLevel() != 2) ++bad;
            if (!uail3WraithAoeTheIllusionist()) ++bad;
            if (!uail3WraithComponentsSomaticMaterial()) ++bad;
            if (uail3WraithCastingTimeSegments() != 1) ++bad;
            if (!uail3WraithSaveNone()) ++bad;
            if (!uail3WraithInsubstantialWithGear()) ++bad;
            if (!uail3WraithHitOnlyByPlusOneOrBetter()) ++bad;
            if (!uail3WraithEtherealAbleCreaturesHit()) ++bad;
            if (!uail3WraithMostUndeadIgnore()) ++bad;
            if (!uail3WraithAppearsAsWraithOrSpectre()) ++bad;
            if (!uail3WraithLichMayRecognize()) ++bad;
            if (uail3WraithLichRecognizeSaveMod() != -4) ++bad;
            if (!uail3WraithPassesThroughCracksWithGear()) ++bad;
            if (!uail3WraithNoAttacksExceptVsEthereal()) ++bad;
            if (!uail3WraithEtherealCombatNormalBothWays()) ++bad;
            if (!uail3WraithDispelForcesNormalForm()) ++bad;
            if (!uail3WraithReturnAtWillEndsSpell()) ++bad;
            if (!uail3WraithComponentsGauzeAndSmoke()) ++bad;
        // ---- dispel magic ----
        // ---- rainbow pattern ----
        // ---- solid fog ----
        // ---- vacancy ----
            if (strcmp(uail4DispelName(),
                "Dispel Magic (Abjuration)") != 0) ++bad;
            if (uail4DispelLevel() != 4) ++bad;
            if (uail4DispelRangeInches() != 9) ++bad;
            if (!uail4DispelDurationPermanent()) ++bad;
            if (uail4DispelAoeInchesCube() != 3) ++bad;
            if (!uail4DispelAoeCellInterleaved()) ++bad;
            if (!uail4DispelComponentsVerbalSomatic()) ++bad;
            if (uail4DispelCastingTimeSegments() != 4) ++bad;
            if (!uail4DispelSaveNone()) ++bad;
            if (!uail4DispelSameAsClericalThirdLevel()) ++bad;
            if (!uail4DispelCastsTwoLevelsBelow()) ++bad;
            if (!uail4DispelExampleNinthCastsAsSeventh()) ++bad;
            if (strcmp(uail4RainbowName(),
                "Rainbow Pattern (Alteration/Phantasm)") != 0) ++bad;
            if (uail4RainbowLevel() != 4) ++bad;
            if (!uail4RainbowComponentsSomaticMaterial()) ++bad;
            if (!uail4RainbowCastingTimeCellLost()) ++bad;
            if (uail4RainbowRangeInches() != 1) ++bad;
            if (!uail4RainbowSaveNegates()) ++bad;
            if (!uail4RainbowDurationSpecial()) ++bad;
            if (uail4RainbowAoeInchesSquare() != 3) ++bad;
            if (!uail4RainbowPastelGlowingBand()) ++bad;
            if (!uail4RainbowSameEffectAsHypnoticPattern()) ++bad;
            if (!uail4RainbowMovesInGesturedDirection()) ++bad;
            if (uail4RainbowSpeedInchesPerRound() != 3) ++bad;
            if (uail4RainbowPersistsRoundsMin() != 1) ++bad;
            if (uail4RainbowPersistsRoundsMax() != 3) ++bad;
            if (uail4RainbowFollowerLevelsOrHdCap() != 24) ++bad;
            if (!uail4RainbowDangerAllowsSecondSave()) ++bad;
            if (!uail4RainbowBlockedViewNegates()) ++bad;
            if (!uail4RainbowObscurementExample()) ++bad;
            if (!uail4RainbowComponentsPrismPhosphor()) ++bad;
            if (strcmp(uail4FogName(),
                "Solid Fog (Alteration)") != 0) ++bad;
            if (uail4FogLevel() != 4) ++bad;
            if (!uail4FogLevelCellLost()) ++bad;
            if (uail4FogDurationRoundsBaseMin() != 2) ++bad;
            if (uail4FogDurationRoundsBaseMax() != 8) ++bad;
            if (uail4FogDurationPlusPerLevel() != 1) ++bad;
            if (uail4FogAoeCubicPerLevel() != 2) ++bad;
            if (!uail4FogAoeUnitCellLost()) ++bad;
            if (!uail4FogComponentsVSM()) ++bad;
            if (uail4FogCastingTimeSegments() != 4) ++bad;
            if (!uail4FogSaveNone()) ++bad;
            if (!uail4FogRollingBillowingWallOfFog()) ++bad;
            if (!uail4FogOnlyVeryStrongWindMoves()) ++bad;
            if (!uail4FogGustOfWindCannotAffect()) ++bad;
            if (uail4FogMoveInchesPerRound() != 1) ++bad;
            if (!uail4FogFireballBurnsAwayOneRound()) ++bad;
            if (!uail4FogFlameStrikeBurnsAway()) ++bad;
            if (!uail4FogWallOfFireBurnsAway()) ++bad;
            if (!uail4FogComponentCellGarbled()) ++bad;
            if (strcmp(uail4VacancyName(),
                "Vacancy (Alteration/Phantasm)") != 0) ++bad;
            if (uail4VacancyLevel() != 4) ++bad;
            if (!uail4VacancyComponentsVSM()) ++bad;
            if (uail4VacancyCastingTimeSegments() != 4) ++bad;
            if (uail4VacancyRangeInchesPerLevel() != 1) ++bad;
            if (!uail4VacancySaveNone()) ++bad;
            if (!uail4VacancyDurationCellSuspectGarble()) ++bad;
            if (uail4VacancyAoeRadiusInchesPerLevel() != 1) ++bad;
            if (!uail4VacancyAreaSeemsVacantNeglected()) ++bad;
            if (!uail4VacancyDustCobwebsDirtTypical()) ++bad;
            if (!uail4VacancyPassageSeemsToLeaveTracks()) ++bad;
            if (!uail4VacancyPassageTearsCobwebs()) ++bad;
            if (!uail4VacancyOnlyForcefulContactDisturbs()) ++bad;
            if (!uail4VacancyCloaksOnlyNonLivingThings()) ++bad;
            if (!uail4VacancyLivingThingsNotInvisible()) ++bad;
            if (!uail4VacancyForcefulContactGrantsSaves()) ++bad;
            if (!uail4VacancyFailedSaveBelievesInvisible()) ++bad;
            if (!uail4VacancyDispelRemovesDweomer()) ++bad;
            if (!uail4VacancyTrueSeeingPenetrates()) ++bad;
            if (!uail4VacancyGemOfSeeingPenetrates()) ++bad;
            if (!uail4VacancyDetectInvisibilityCannot()) ++bad;
            if (uail4VacancySilkMinGpValue() != 100) ++bad;
        // ---- advanced illusion ----
        // ---- dream ----
        // ---- magic mirror ----
        // ---- tempus fugit ----
            if (strcmp(uail5AdvilName(),
                "Advanced Illusion (Illusion/Phantasm)") != 0) ++bad;
            if (!uail5AdvilNameHeaderGarbled()) ++bad;
            if (uail5AdvilLevel() != 5) ++bad;
            if (!uail5AdvilComponentsVSM()) ++bad;
            if (uail5AdvilCastingTimeSegments() != 5) ++bad;
            if (uail5AdvilRangeInches() != 6) ++bad;
            if (uail5AdvilRangeInchesPerLevel() != 1) ++bad;
            if (!uail5AdvilSaveSpecial()) ++bad;
            if (!uail5AdvilDurationCellSuspectGarble()) ++bad;
            if (uail5AdvilAoeSquares() != 4) ++bad;
            if (uail5AdvilAoeSquaresPerLevel() != 1) ++bad;
            if (!uail5AdvilAoeCellInterleaved()) ++bad;
            if (!uail5AdvilProgramSpell()) ++bad;
            if (!uail5AdvilCrossRefCellGarbled()) ++bad;
            if (uail5AdvilConcentrationSegments() != 5) ++bad;
            if (!uail5AdvilProgramRunsAlone()) ++bad;
            if (!uail5AdvilVisualComponent()) ++bad;
            if (!uail5AdvilFullAudialComponent()) ++bad;
            if (!uail5AdvilOlfactoryComponent()) ++bad;
            if (!uail5AdvilThermalComponent()) ++bad;
            if (!uail5AdvilActiveDisbelieveGrantsSave()) ++bad;
            if (uail5AdvilCommunicatedDisbeliefBonus() != 4) ++bad;
            if (!uail5AdvilComponentsFleeceAndSand()) ++bad;
            if (strcmp(uail5DreamName(),
                "Dream (Alteration - Illusion/Phantasm)") != 0) ++bad;
            if (uail5DreamLevel() != 5) ++bad;
            if (!uail5DreamRangeSpecial()) ++bad;
            if (!uail5DreamDurationSpecial()) ++bad;
            if (!uail5DreamAoeSpecial()) ++bad;
            if (!uail5DreamComponentsSpecial()) ++bad;
            if (!uail5DreamCastingTimeCellSuspectGarble()) ++bad;
            if (!uail5DreamSaveNegates()) ++bad;
            if (!uail5DreamLimitedWishForm()) ++bad;
            if (!uail5DreamMoreLimitedScope()) ++bad;
            if (!uail5DreamMustLieProneAndSleep()) ++bad;
            if (uail5DreamUndisturbedSleepHours() != 8) ++bad;
            if (uail5DreamEffectuatedHoursMin() != 1) ++bad;
            if (uail5DreamEffectuatedHoursMax() != 12) ++bad;
            if (!uail5DreamResultRecoverLostHp()) ++bad;
            if (!uail5DreamResultRestoreBodyMember()) ++bad;
            if (!uail5DreamResultLocateUnguardedObject()) ++bad;
            if (!uail5DreamResultDiscoverIngressEgress()) ++bad;
            if (!uail5DreamResultSafeWildernessPath()) ++bad;
            if (!uail5DreamResultImproveTreasureChances()) ++bad;
            if (uail5DreamScriedSaveHdThreshold() != 7) ++bad;
            if (!uail5DreamScriedSaveHidesFromDream()) ++bad;
            if (!uail5DreamScriedMaySenseCaster()) ++bad;
            if (!uail5DreamResultsStrictlyLimited()) ++bad;
            if (!uail5DreamNeverExceedsOnPermanentBasis()) ++bad;
            if (uail5DreamCompanionTurnsPerLevel() != 1) ++bad;
            if (!uail5DreamUnaffectedByExtensionOrPermanency()) ++bad;
            if (!uail5DreamOncePerWeek()) ++bad;
            if (!uail5DreamSecondCastInWeekFails()) ++bad;
            if (uail5DreamSecondCastAgesYearsMin() != 1) ++bad;
            if (uail5DreamSecondCastAgesYearsMax() != 10) ++bad;
            if (strcmp(uail5MirrorName(),
                "Magic Mirror (Enchantment - Divination)") != 0) ++bad;
            if (uail5MirrorLevel() != 5) ++bad;
            if (!uail5MirrorComponentsVSM()) ++bad;
            if (uail5MirrorCastingTimeHours() != 1) ++bad;
            if (!uail5MirrorRangeTouch()) ++bad;
            if (!uail5MirrorSaveNone()) ++bad;
            if (!uail5MirrorDurationCellSuspectGarble()) ++bad;
            if (!uail5MirrorAoeSpecial()) ++bad;
            if (!uail5MirrorSameAsFourthLevelMuSpell()) ++bad;
            if (!uail5MirrorSameMaterialComponents()) ++bad;
            if (!uail5MirrorVisionSpellReplacesComponents()) ++bad;
            if (!uail5MirrorStillScrysWithVision()) ++bad;
            if (!uail5MirrorVisionDoesNotFunctionNormally()) ++bad;
            if (strcmp(uail5TempusName(),
                "Tempus Fugit (Illusion/Phantasm)") != 0) ++bad;
            if (!uail5TempusReversible()) ++bad;
            if (uail5TempusLevel() != 5) ++bad;
            if (!uail5TempusComponentsVerbalSomatic()) ++bad;
            if (uail5TempusCastingTimeSegments() != 5) ++bad;
            if (uail5TempusRangeInches() != 0) ++bad;
            if (!uail5TempusSaveNone()) ++bad;
            if (uail5TempusDurationTurnsPerLevel() != 5) ++bad;
            if (uail5TempusAoeRadiusInches() != 7) ++bad;
            if (!uail5TempusAffectsMindsAndBodies()) ++bad;
            if (!uail5TempusLatecomersAlsoAffected()) ++bad;
            if (!uail5TempusTurnSeemsLikeAnHour()) ++bad;
            if (!uail5TempusFunctionsSpedUp()) ++bad;
            if (!uail5TempusOtherSpellDurationsSped()) ++bad;
            if (!uail5TempusOneHourIsAsSix()) ++bad;
            if (!uail5TempusFourHoursAFullDay()) ++bad;
            if (!uail5TempusAllowsRestRenewalRecovery()) ++bad;
            if (!uail5TempusReversalSlowsTime()) ++bad;
            if (!uail5TempusReverseHourSeemsATurn()) ++bad;
            if (!uail5TempusReverseDayMereFourHours()) ++bad;
            if (!uail5TempusReversalNeedsNoPreparation()) ++bad;
            if (!uail5TempusCasterAlsoAffected()) ++bad;
            if (uail5TempusReverseLingersTurnsMin() != 1) ++bad;
            if (!uail5TempusReverseLingersBySlowReactions()) ++bad;
        // the R342 IL table seam: the 3rd
        // through 6th columns are wholly
        // lost; the readable columns still
        // print only PHB names, and the
        // lost-column Phantom Wind fragment
        // corroborates the wind pin
            if (uas2Il1stCount() != 5) ++bad;
            if (uas2Il2ndCount() != 4) ++bad;
            if (uas2Il7thCount() != 1) ++bad;
            if (strcmp(uas2Il7thName(0),
                        "Shadow Walk") != 0) ++bad;
            if (!uas2IlCantripListLost()) ++bad;
        // none of the new illusionist names
        // seam-checks in the readable
        // columns
            static const char* const nn[12] = {
                "Delude", "Phantom Steed",
                "Phantom Wind", "Wraithform",
                "Dispel Magic", "Rainbow Pattern",
                "Solid Fog", "Vacancy",
                "Advanced Illusion", "Dream",
                "Magic Mirror", "Tempus Fugit",
            };
            for (int n = 0; n < 12; ++n) {
                for (int i = 0; i < 5; ++i) {
                    if (strcmp(uas2Il1stName(i),
                        nn[n]) == 0) ++bad;
                }
                for (int i = 0; i < 4; ++i) {
                    if (strcmp(uas2Il2ndName(i),
                        nn[n]) == 0) ++bad;
                }
                if (strcmp(uas2Il7thName(0),
                    nn[n]) == 0) ++bad;
            }
        printf("R364 UA IL 3rd/4th/5th spells pin audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R364 audit')
s = rd(RT)
assert s.count(
    'R364 UA IL 3rd/4th/5th spells pin audit'
) == 1, 'd audit line'
assert s.count(
    'R363 UA IL cantrips/1st/2nd pin'
    ' audit: bad ') == 1, 'd r363 kept'
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
    'R359 UA MU 4th level spells pin'
    ' audit: bad ') == 1, 'd r359 kept'
assert s.count(
    'R358 UA MU 3rd level spells pin'
    ' audit: bad ') == 1, 'd r358 kept'
assert s.count(
    'R357 UA MU 2nd level spells pin'
    ' audit: bad ') == 1, 'd r357 kept'
assert s.count(
    'R356 UA MU 1st level spells pin'
    ' audit: bad ') == 1, 'd r356 kept'
assert s.count('audit: bad ') == 291, 'd census 291'
assert s.count(
    'R355 UA druid 7th level spells pin'
    ' audit: bad ') == 1, 'd r355 kept'
assert s.count(
    'R354 UA druid 6th level spells pin'
    ' audit: bad ') == 1, 'd r354 kept'
assert s.count(
    'R350 UA druid 1st level spells pin'
    ' audit: bad ') == 1, 'd r350 kept'
assert s.count(
    'R349 UA cleric 7th level spells pin'
    ' audit: bad ') == 1, 'd r349 kept'
assert s.count(
    'R227: the wis mental save'
    ) == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uailspells3.h"'
) == 1, 'd spells3 include'
assert s.count(
    '#include "rules/uailspells4.h"'
) == 1, 'd spells4 include'
assert s.count(
    '#include "rules/uailspells5.h"'
) == 1, 'd spells5 include'
assert s.count(
    '#include "rules/uailcantrips.h"'
) == 1, 'd cantrips include'
assert s.count(
    '#include "rules/uailspells1.h"'
) == 1, 'd r363-1 include'
assert s.count(
    '#include "rules/uailspells2.h"'
) == 1, 'd r363-2 include'
assert s.count(
    '#include "rules/uamuspells1.h"'
) == 1, 'd mu1 include'
assert s.count(
    '#include "rules/uamuspells2.h"'
) == 1, 'd mu2 include'
assert s.count(
    '#include "rules/uamuspells3.h"'
) == 1, 'd mu3 include'
assert s.count(
    '#include "rules/uamuspells4.h"'
) == 1, 'd mu4 include'
assert s.count(
    '#include "rules/uamuspells5.h"'
) == 1, 'd mu5 include'
assert s.count(
    '#include "rules/uamuspells6.h"'
) == 1, 'd mu6 include'
assert s.count(
    '#include "rules/uamuspells7.h"'
) == 1, 'd mu7 include'
assert s.count(
    '#include "rules/uamuspells8.h"'
) == 1, 'd mu8 include'
assert s.count(
    '#include "rules/uamuspells9.h"'
) == 1, 'd mu9 include'
assert len(applied) + len(already) == 6, 'd count'


# ---- the summary ----
print('R364 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R364 note: the UA new illusionist')
print('3rd/4th/5th level spells pin round -',)
print('delude and wraithform at the printed',)
print('3rd (the Level: 3 cells; the item-',)
print('list 2nd divergence stands); phantom',)
print('steed and phantom wind pinned as the',)
print('print adds them under the third-level',)
print('header; dispel magic, rainbow pattern,',)
print('solid fog and vacancy at 4th; the',)
print('advanced illusion named from the item',)
print('list, dream, the magic mirror reprint',)
print('and tempus fugit at 5th; the bare-7',)
print('cells read as holes pending the PDF;',)
print('the R342 IL table 3rd-6th columns stay',)
print('lost; the 6th and 7th levels stay open;',)
print('the census 290 -> 291',)
print('commit: R364: the UA new illusionist',)
print('3rd/4th/5th level spells pin round',)
print('(census 291)',)



