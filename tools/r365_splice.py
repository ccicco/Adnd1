# R365: the UA NEW ILLUSIONIST
# SPELLS closing pin round - the 6th
# and 7th levels (pp. 71-73): death fog,
# mislead, phantasmagoria and the mirage
# arcane (printed at the 6th cell, the
# item-list 7th divergence flagged);
# shadow walk and weird at 7th. Combined:
# the illusionist spell acquisition
# fragment pin (the item stays open, the
# table cells garble) and the cost of
# spell casting pin (the item CLOSED).
# The IL spells item flips CLOSED - all
# printed levels pinned R363 through
# R365.
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


# ---- (a) the seed: the R364 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R364 landed 2026-10-11: commit',
    '  141fbcb, census 291, the UA new',
    '  illusionist 3rd/4th/5th level',
    '  spells pin round',
    '  (rules/uailspells3.h,',
    '  rules/uailspells4.h and',
    '  rules/uailspells5.h): delude',
    '  and wraithform at the printed',
    '  3rd, phantom steed and phantom',
    '  wind pinned as the print adds',
    '  them, dispel magic, rainbow',
    '  pattern, solid fog and vacancy',
    '  at 4th, the advanced illusion,',
    '  dream, the magic mirror reprint',
    '  and tempus fugit at 5th; the',
    '  R342 IL table 3rd-6th columns',
    '  stay lost; the item stays open',
    '  - the 6th and 7th levels pin in',
    '  the next round; GREEN on the',
    '  first run.',
])
s = rd(SD)
if 'R364 landed 2026-10-11' in s:
    already.append('seed: the R364 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R364 record')
s = rd(SD)
assert s.count(
    'R364 landed 2026-10-11'
) == 1, 'a entry'
assert s.count(
    'R363 landed 2026-10-11'
) == 1, 'a R363 kept'
assert s.count(
    'R362 landed 2026-10-11'
) == 1, 'a R362 kept'
assert s.count(
    'R361 landed 2026-10-11'
) == 1, 'a R361 kept'
assert s.count(
    'R360 landed 2026-10-11'
) == 1, 'a R360 kept'
assert s.count(
    'R359 landed 2026-10-11'
) == 1, 'a R359 kept'
assert s.count(
    'R358 landed 2026-10-11'
) == 1, 'a R358 kept'
assert s.count(
    'R357 landed 2026-10-11'
) == 1, 'a R357 kept'
assert s.count(
    'R356 landed 2026-10-11'
) == 1, 'a R356 kept'
assert s.count(
    'R355 landed 2026-10-11'
) == 1, 'a R355 kept'
assert s.count(
    'R354 landed 2026-10-11'
) == 1, 'a R354 kept'
assert s.count(
    'R353 landed 2026-10-11'
) == 1, 'a R353 kept'
assert s.count(
    'R352 landed 2026-10-11'
) == 1, 'a R352 kept'
assert s.count(
    'R351 landed 2026-10-11'
) == 1, 'a R351 kept'
assert s.count(
    'R350 landed 2026-10-11'
) == 1, 'a R350 kept'
assert s.count(
    'R349 landed 2026-10-11'
) == 1, 'a R349 kept'
assert s.count(
    'R347 landed 2026-10-11'
) == 1, 'a R347 kept'
assert s.count(
    'R343 landed 2026-10-11'
) == 1, 'a R343 kept'
assert s.count(
    '## Knowledge maintenance'
) == 1, 'a maint'
assert len(applied) + len(already) == 1, 'a count'


# ---- (b) NEW rules/uailspells6.h ----
US6 = 'rules/uailspells6.h'
if os.path.exists(US6) and 'R365' in rd(US6):
    already.append('uailspells6.h: the pins')
else:
    HDR6 = r"""// ===========================================================================
// Adnd1 - rules/uailspells6.h
// The UA NEW ILLUSIONIST SPELLS (pp. 71-72) pins,
// R365: the 6th-level spell descriptions - death
// fog, mislead, phantasmagoria and the mirage
// arcane (printed at the 6th cell).
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists.
//
// JUDGMENTs (the decode method):
//   - the mirage arcane level cell prints the
//     clean 6 under the ILLUSIONIST SPELLS (7TH
//     LEVEL) header - the item list (the R322
//     index) names it at 7th; the print wins (the
//     R363 phantom-armor precedent), the
//     divergence flagged in the round note
//     pending the PDF; the R342 IL table seam
//     corroborates the print - the readable 7th
//     column carries only Shadow Walk.
//   - the phantasmagoria level cell does not
//     print - the level pins from the Sixth
//     Level Spells section header (the R364
//     solid-fog precedent).
//   - the suspect cells read as holes pending
//     the PDF, no numeric pin: the death fog
//     duration (7-4 rounds + 1/level - the
//     solid-fog parallel prints 2-8, no decode
//     exists), the mislead range (a bare 7),
//     the phantasmagoria duration (a bare 7)
//     and its area cell (4 square + 1 square
//     with the units lost).
//   - the mirage arcane casting time prints the
//     clean 3 or 6 segments - both forms pin,
//     corroborated by the prose (the basic form
//     3, the complex material-component form 6).
//   - the R342 IL table seam: the 6th-level
//     column is wholly lost - none of the new
//     names seam-checks, asserted in the audit.
// ===========================================================================

#pragma once

namespace rules {

// ---- death fog ----
inline const char* uail6DfogName()
    { return "Death Fog (Alteration - Evocation)"; }

inline int uail6DfogLevel()
    { return 6; }

inline bool uail6DfogComponentsVSM()
    { return true; }

inline int uail6DfogCastingTimeSegments()
    { return 6; }

inline int uail6DfogRangeInches()
    { return 3; }

inline bool uail6DfogSaveNone()
    { return true; }

inline bool uail6DfogDurationCellSuspectGarble()
    { return true; }

inline int uail6DfogAoeCubicPerLevel()
    { return 2; }

inline bool uail6DfogAoeUnitCellLost()
    { return true; }

inline bool uail6DfogCreatesSolidFogArea()
    { return true; }

inline bool uail6DfogHighlyAcidic()
    { return true; }

inline bool uail6DfogVaporsDeadlyToVegetation()
    { return true; }

// Plants exposed to the vapors die in 2 rounds.
inline int uail6DfogPlantsDieInRounds()
    { return 2; }

inline int uail6DfogBushesShrubsDieInRounds()
    { return 4; }

inline int uail6DfogSmallTreesDieInRounds()
    { return 8; }

inline int uail6DfogLargeTreesDieInRounds()
    { return 16; }

inline bool uail6DfogAnimalsNotImmuneSuffer()
    { return true; }

// The acid damage ladder by exposure round: 1,
// 2, 4, then 8 points every succeeding round.
inline int uail6DfogDamageRound1()
    { return 1; }

inline int uail6DfogDamageRound2()
    { return 2; }

inline int uail6DfogDamageRound3()
    { return 4; }

inline int uail6DfogDamageRound4On()
    { return 8; }

inline bool uail6DfogOtherwiseSameAsSolidFog()
    { return true; }

inline bool uail6DfogComponentsPeasHoofAcid()
    { return true; }

inline bool uail6DfogAcidIncludesVinegarCrystals()
    { return true; }

// ---- mislead ----
// The range cell prints a bare 7 - a hole
// pending the PDF (no corroborating print exists
// to decode it).
inline const char* uail6MisleadName()
    { return "Mislead (Illusion/Phantasm)"; }

inline int uail6MisleadLevel()
    { return 6; }

inline bool uail6MisleadSomaticOnly()
    { return true; }

inline int uail6MisleadCastingTimeSegments()
    { return 1; }

inline bool uail6MisleadRangeCellSuspectGarble()
    { return true; }

inline bool uail6MisleadSaveNone()
    { return true; }

inline int uail6MisleadDurationRoundsPerLevel()
    { return 1; }

inline bool uail6MisleadAoeSpecial()
    { return true; }

inline bool uail6MisleadCreatesPhantasmalDouble()
    { return true; }

inline bool uail6MisleadCloakedByImprovedInvis()
    { return true; }

inline bool uail6MisleadCasterFreeToGoElsewhere()
    { return true; }

inline bool uail6MisleadPhantasmSeeminglyMovesAway()
    { return true; }

inline bool uail6MisleadPhantasmSpeaksAndGestures()
    { return true; }

inline bool uail6MisleadSensorySentenceGarbled()
    { return true; }

inline bool uail6MisleadTrueSightRevealsIllusion()
    { return true; }

inline bool uail6MisleadGemOfSeeingRevealsIllusion()
    { return true; }

inline bool uail6MisleadDetectInvisDetectsCaster()
    { return true; }

inline bool uail6MisleadTrueSightDetectsCaster()
    { return true; }

inline bool uail6MisleadTrueSeeingDetectsCaster()
    { return true; }

inline bool uail6MisleadRobeOfEyesDetectsCaster()
    { return true; }

inline bool uail6MisleadShadowDoorCrossRef()
    { return true; }

// ---- phantasmagoria ----
// The level cell does not print - the level pins
// from the Sixth Level Spells section header (the
// R364 solid-fog precedent); the duration prints
// a bare 7 round/level and the area cell garbles
// (4 square + 1 square with the units lost) -
// holes pending the PDF.
inline const char* uail6PhantName()
    { return "Phantasmagoria (Illusion/Phantasm)"; }

inline int uail6PhantLevel()
    { return 6; }

inline bool uail6PhantLevelCellLost()
    { return true; }

inline bool uail6PhantComponentsVerbalSomatic()
    { return true; }

inline int uail6PhantCastingTimeSegments()
    { return 6; }

inline bool uail6PhantSaveNegates()
    { return true; }

inline bool uail6PhantDurationCellSuspectGarble()
    { return true; }

inline bool uail6PhantAoeCellGarbled()
    { return true; }

inline bool uail6PhantSpecialFormOfSpectralForces()
    { return true; }

inline bool uail6PhantTriggeredBySpecialAction()
    { return true; }

inline bool uail6PhantFullVisualAudialOlfactoryTouch()
    { return true; }

inline bool uail6PhantFallingSlidingMovingRapidly()
    { return true; }

inline bool uail6PhantTriggerOnPitFallOrDoorOpen()
    { return true; }

inline bool uail6PhantMustInvolveFallingRushing()
    { return true; }

inline bool uail6PhantDwindlingPerspectiveRead()
    { return true; }

inline bool uail6PhantUnlikeProgrammedIllusion()
    { return true; }

// ---- mirage arcane ----
// The level cell prints the clean 6 under the
// 7TH LEVEL header - the item list names it at
// 7th; the print wins, the divergence flagged in
// the round note pending the PDF.
inline const char* uail6MirageName()
    { return "Mirage Arcane (Illusion/Phantasm - Alteration)"; }

inline int uail6MirageLevel()
    { return 6; }

inline bool uail6MirageLevelDivergenceFlagged()
    { return true; }

inline bool uail6MirageComponentsVSOptionalM()
    { return true; }

inline int uail6MirageRangeInchesPerLevel()
    { return 1; }

inline int uail6MirageCastingTimeBasicSegments()
    { return 3; }

inline int uail6MirageCastingTimeComplexSegments()
    { return 6; }

inline bool uail6MirageSaveNone()
    { return true; }

inline bool uail6MirageDurationSpecial()
    { return true; }

inline int uail6MirageAoeRadiusInchesPerLevel()
    { return 1; }

inline bool uail6MirageSimilarToVacancyButStronger()
    { return true; }

inline bool uail6MirageSimilarToMirageCantrip()
    { return true; }

inline bool uail6MirageAreaAppearsOtherThanItIs()
    { return true; }

inline bool uail6MirageEnvisionedByCaster()
    { return true; }

inline bool uail6MirageHeldByFaintConcentration()
    { return true; }

inline int uail6MiragePersistsBaseTurns()
    { return 6; }

inline int uail6MiragePersistsTurnsPerLevel()
    { return 1; }

inline bool uail6MirageConcentrationOkInConversation()
    { return true; }

inline bool uail6MirageConcentrationNotInCombat()
    { return true; }

inline bool uail6MirageMustBePersonallySeen()
    { return true; }

inline bool uail6MirageMaterialBitGrantsReality()
    { return true; }

inline bool uail6MirageBasicForcefulContactNeeded()
    { return true; }

inline bool uail6MirageComplexDetectionOnlyMagical()
    { return true; }

inline bool uail6MirageSubjectToDispelIllusionOrMagic()
    { return true; }

inline bool uail6MirageMindCausesBodyEffects()
    { return true; }

inline bool uail6MirageBeliefCannotAffectLawsOfNature()
    { return true; }

inline bool uail6MirageHotCoalsExample()
    { return true; }

inline bool uail6MirageImaginaryFoodNourishes()
    { return true; }

inline bool uail6MirageFeatherbedExample()
    { return true; }

inline bool uail6MirageGravityUnaffected()
    { return true; }

inline bool uail6MirageEnvisionedBridgeWillNotHold()
    { return true; }

inline bool uail6MirageWitnessesSeeDisappearance()
    { return true; }

inline bool uail6MirageDisappearanceNotLinkedToIllusion()
    { return true; }

}   // namespace rules
"""
    clean(HDR6, 78)
    wr(US6, HDR6 + NL)
    applied.append('uailspells6.h: the pins')
s = rd(US6)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 94, 'b inline count'
assert s.count('R365') == 1, 'b round tag'
assert s.count('uail6DfogName()') == 1, 'b dfog fn'
assert s.count('uail6MirageName()') == 1, 'b mirage fn'
assert 'uam' not in s, 'b no mu ref'
assert 'uadruid' not in s, 'b no druid ref'
assert 'uailc' not in s, 'b no cantrip ref'
assert 'uail1' not in s, 'b no 1st ref'
assert 'uail2' not in s, 'b no 2nd ref'
assert 'uail3' not in s, 'b no 3rd ref'
assert 'uail4' not in s, 'b no 4th ref'
assert 'uail5' not in s, 'b no 5th ref'
assert 'uail7' not in s, 'b no 7th ref'
assert 'uaila' not in s, 'b no acq ref'
assert 'uasc' not in s, 'b no cost ref'
assert len(applied) + len(already) == 2, 'b count'


# ---- (b2) NEW rules/uailspells7.h ----
US7 = 'rules/uailspells7.h'
if os.path.exists(US7) and 'R365' in rd(US7):
    already.append('uailspells7.h: the pins')
else:
    HDR7 = r"""// ===========================================================================
// Adnd1 - rules/uailspells7.h
// The UA NEW ILLUSIONIST SPELLS (pp. 72-73) pins,
// R365: the 7th-level spell descriptions - shadow
// walk and weird.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists.
//
// JUDGMENTs (the decode method):
//   - the shadow walk components cell garbles (a
//     dollar sign) - the symbol does not decode
//     (the R364 magic-mirror S$ cell carried its
//     S; a bare $ is ambiguous), a hole pending
//     the PDF; the school tail garbles (lllusion)
//     and decodes per the R363 convention.
//   - the shadow walk casting cell prints 7
//     segment - the digit-garble family (the R343
//     precedent) decodes the 1 segment; the weird
//     casting cell prints 7 segments (the plural)
//     and pins clean at 7.
//   - the weird description is largely OCR-lost -
//     the interleaved mirage arcane tail (the mind
//     of the beholder sentence) belongs to the
//     mirage arcane pin, not the weird; only the
//     stat block and a caster-must fragment pin,
//     the prose hole documented.
//   - the R342 IL table seam: the readable 7th
//     column prints only Shadow Walk (asserted);
//     the 7th names beyond it are lost-column.
// ===========================================================================

#pragma once

namespace rules {

// ---- shadow walk ----
inline const char* uail7ShadowName()
    { return "Shadow Walk (Illusion - Enchantment)"; }

inline int uail7ShadowLevel()
    { return 7; }

inline bool uail7ShadowComponentsCellGarbled()
    { return true; }

inline bool uail7ShadowRangeTouch()
    { return true; }

inline int uail7ShadowCastingTimeSegments()
    { return 1; }

inline bool uail7ShadowSaveNone()
    { return true; }

inline int uail7ShadowDurationTurnsPerLevel()
    { return 6; }

inline bool uail7ShadowAoeSpecial()
    { return true; }

inline bool uail7ShadowRequiresHeavyShadows()
    { return true; }

inline bool uail7ShadowEdgeOfPrimeMaterial()
    { return true; }

inline bool uail7ShadowAwareOfPrimePosition()
    { return true; }

inline int uail7ShadowLeaguesPerTurn()
    { return 7; }

inline bool uail7ShadowRapidTravelByStepping()
    { return true; }

inline bool uail7ShadowDestinationControlled()
    { return true; }

inline bool uail7ShadowOtherPlanesPerilousTransit()
    { return true; }

inline bool uail7ShadowTouchedAlsoTransition()
    { return true; }

inline bool uail7ShadowMayFollowWanderOrStumble()
    { return true; }

inline bool uail7ShadowLostOrAbandonedFiftyFifty()
    { return true; }

inline bool uail7ShadowUnwillingSaveNegates()
    { return true; }

// ---- weird ----
// The description is largely OCR-lost - the
// interleaved belief-effect prose belongs to the
// mirage arcane pin; only the stat block and a
// caster-must fragment print for the weird.
inline const char* uail7WeirdName()
    { return "Weird (Evocation - Illusion/Phantasm)"; }

inline int uail7WeirdLevel()
    { return 7; }

inline bool uail7WeirdComponentsVerbalSomatic()
    { return true; }

inline int uail7WeirdCastingTimeSegments()
    { return 7; }

inline int uail7WeirdRangeInches()
    { return 3; }

inline bool uail7WeirdSaveSpecial()
    { return true; }

inline bool uail7WeirdDurationSpecial()
    { return true; }

inline int uail7WeirdAoeRadiusInches()
    { return 2; }

inline bool uail7WeirdProseLargelyLost()
    { return true; }

inline bool uail7WeirdCasterMustFragmentPrints()
    { return true; }

}   // namespace rules
"""
    clean(HDR7, 78)
    wr(US7, HDR7 + NL)
    applied.append('uailspells7.h: the pins')
s = rd(US7)
assert s.count('namespace rules {') == 1, 'b2 ns'
assert s.count('inline') == 29, 'b2 inline count'
assert s.count('R365') == 1, 'b2 round tag'
assert s.count('uail7ShadowName()') == 1, 'b2 shadow fn'
assert s.count('uail7WeirdName()') == 1, 'b2 weird fn'
assert 'uam' not in s, 'b2 no mu ref'
assert 'uadruid' not in s, 'b2 no druid ref'
assert 'uailc' not in s, 'b2 no cantrip ref'
assert 'uail1' not in s, 'b2 no 1st ref'
assert 'uail2' not in s, 'b2 no 2nd ref'
assert 'uail3' not in s, 'b2 no 3rd ref'
assert 'uail4' not in s, 'b2 no 4th ref'
assert 'uail5' not in s, 'b2 no 5th ref'
assert 'uail6' not in s, 'b2 no 6th ref'
assert 'uaila' not in s, 'b2 no acq ref'
assert 'uasc' not in s, 'b2 no cost ref'
assert len(applied) + len(already) == 3, 'b2 count'


# ---- (b3) NEW rules/uailacquisition.h ----
USA = 'rules/uailacquisition.h'
if os.path.exists(USA) and 'R365' in rd(USA):
    already.append('uailacquisition.h: pins')
else:
    HDRA = r"""// ===========================================================================
// Adnd1 - rules/uailacquisition.h
// The UA ILLUSIONIST SPELL ACQUISITION (pp. 33-34
// players extract, p. 80 print) pins, R365: the
// starting-list table, the illusionist spell book
// differences and the illusionist cantrip counts.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists.
//
// JUDGMENTs (the decode method):
//   - the starting-list table interleaves: the
//     defensive rows print legibly (the five
//     numbered rows with the multi-name cells);
//     the offensive and misc columns merge into
//     one garbled block (Change Self through
//     Phantom Armor with two choose markers) -
//     the row boundaries are lost, holes pending
//     the PDF; the fragment names pin.
//   - the chromatic orb row prints with the
//     (choose) marker and the UA-addition note
//     prints clean (spells from this work were
//     added to the initial lists for illusionists
//     only, not for magic-users).
//   - the book-difference list prints clean (the
//     24/16/8 standard capacities, the 6/4/2
//     travelling capacities, the separate book
//     for magic-user 1st-level spells).
//   - the illusionist cantrip counts print with
//     one category tail garbled (the personal
//     2-5 cell) - pinned per the fragments.
// ===========================================================================

#pragma once

namespace rules {

// ---- the starting list ----
inline bool uailaThreeGroupsOneEach()
    { return true; }

inline bool uailaAlwaysKnowsReadIllusionistMagic()
    { return true; }

// The defensive rows: 1 - color spray, audible
// glamer, darkness; 2 - hypnotism; 3 - light,
// gaze reflection; 4 - phantasmal force, wall of
// fog; 5 - chromatic orb (choose).
inline int uailaDefensiveRowCount()
    { return 5; }

inline bool uailaRow1ColorSpray()
    { return true; }

inline bool uailaRow1AudibleGlamer()
    { return true; }

inline bool uailaRow1Darkness()
    { return true; }

inline bool uailaRow2Hypnotism()
    { return true; }

inline bool uailaRow3Light()
    { return true; }

inline bool uailaRow3GazeReflection()
    { return true; }

inline bool uailaRow4PhantasmalForce()
    { return true; }

inline bool uailaRow4WallOfFog()
    { return true; }

inline bool uailaRow5ChromaticOrb()
    { return true; }

inline bool uailaRow5ChromaticOrbIsChoose()
    { return true; }

inline bool uailaOffensiveMiscColumnsMerged()
    { return true; }

inline bool uailaMiscChangeSelf()
    { return true; }

inline bool uailaMiscDancingLights()
    { return true; }

inline bool uailaMiscDetect()
    { return true; }

inline bool uailaMiscDetectInvisibility()
    { return true; }

inline bool uailaMiscPhantomArmor()
    { return true; }

inline bool uailaRowBoundariesLost()
    { return true; }

// The DM three-options note for the asterisked
// choose: a 5th miscellaneous spell, a player
// re-selection of an offensive spell, or the
// roll read as a miscellaneous choice.
inline int uailaDmOptionCount()
    { return 3; }

inline bool uailaUaSpellsAddedForIllusionistsOnly()
    { return true; }

inline bool uailaNotDoneForMagicUsers()
    { return true; }

// ---- the illusionist spell book differences ----
inline bool uailaBooksSameAsMuWithExceptions()
    { return true; }

inline int uailaStandardBookLowLevelSpells()
    { return 24; }

inline int uailaStandardBookMidLevelSpells()
    { return 16; }

inline int uailaStandardBookHighLevelSpells()
    { return 8; }

inline bool uailaMuFirstLevelNeedsNewBook()
    { return true; }

inline int uailaMuFirstLevelBookCapacity()
    { return 24; }

inline int uailaTravellingBookLowLevelSpells()
    { return 6; }

inline int uailaTravellingBookMidLevelSpells()
    { return 4; }

inline int uailaTravellingBookHighLevelSpells()
    { return 2; }

inline bool uailaScriptReadableByIllusionistsOnly()
    { return true; }

inline bool uailaCrossClassBookBan()
    { return true; }

inline bool uailaNamesakeSpellsTriggerDifferently()
    { return true; }

// ---- the illusionist cantrip counts ----
inline bool uailaHasAllMuCantrips()
    { return true; }

inline int uailaMinorIllusionCantripsMin()
    { return 5; }

inline int uailaMinorIllusionCantripsMax()
    { return 8; }

inline bool uailaMinorIllusionNotAvailableToMu()
    { return true; }

// The useful-category cap: one per point of
// intelligence minus 3 - an 18-intelligence
// illusionist chooses 15.
inline int uailaUsefulCapIntMinus()
    { return 3; }

inline int uailaUsefulCapAtInt18()
    { return 15; }

inline int uailaReversedKnownMin()
    { return 2; }

inline int uailaReversedKnownMax()
    { return 5; }

inline int uailaLegerdemainKnownMin()
    { return 3; }

inline int uailaLegerdemainKnownMax()
    { return 6; }

inline int uailaPersonAffectingKnownMin()
    { return 2; }

inline int uailaPersonAffectingKnownMax()
    { return 5; }

inline int uailaPersonalKnownMin()
    { return 2; }

inline int uailaPersonalKnownMax()
    { return 5; }

inline int uailaHauntingSoundKnownMin()
    { return 5; }

inline int uailaHauntingSoundKnownMax()
    { return 8; }

inline bool uailaMuCantripPropertiesOtherwiseApply()
    { return true; }

}   // namespace rules
"""
    clean(HDRA, 78)
    wr(USA, HDRA + NL)
    applied.append('uailacquisition.h: pins')
s = rd(USA)
assert s.count('namespace rules {') == 1, 'b3 ns'
assert s.count('inline') == 52, 'b3 inline count'
assert s.count('R365') == 1, 'b3 round tag'
assert s.count('uailaThreeGroupsOneEach()') == 1, 'b3 groups fn'
assert s.count(
    'uailaAlwaysKnowsReadIllusionistMagic()'
) == 1, 'b3 read fn'
assert 'uam' not in s, 'b3 no mu ref'
assert 'uadruid' not in s, 'b3 no druid ref'
assert 'uailc' not in s, 'b3 no cantrip ref'
assert 'uail1' not in s, 'b3 no 1st ref'
assert 'uail6' not in s, 'b3 no 6th ref'
assert 'uail7' not in s, 'b3 no 7th ref'
assert 'uasc' not in s, 'b3 no cost ref'
assert len(applied) + len(already) == 4, 'b3 count'


# ---- (b4) NEW rules/uaspellcost.h ----
USC = 'rules/uaspellcost.h'
if os.path.exists(USC) and 'R365' in rd(USC):
    already.append('uaspellcost.h: the pins')
else:
    HDRC = r"""// ===========================================================================
// Adnd1 - rules/uaspellcost.h
// The UA COST OF MAGIC-USER/ILLUSIONIST SPELL
// CASTING (p. 81 print) pins, R365.
//
// Pin-era pattern (R322): pinned data only - no engine
// site exists. The section prose prints clean; the
// one interleaved fragment (the danger clause) is
// noted in-header.
// ===========================================================================

#pragma once

namespace rules {

// ---- the basic fee ----
inline int uascFeePerSpellLevelGp()
    { return 200; }

inline bool uascWillingCasterWorksForFee()
    { return true; }

inline bool uascMaterialComponentsDoubled()
    { return true; }

inline bool uascComponentSubstitutionsAllowed()
    { return true; }

// ---- the surcharges ----
// Failing to furnish ordinary material components
// brings a surcharge of 10 percent or three times
// the component value, whichever is greater.
inline int uascOrdinarySurchargePercent()
    { return 10; }

inline int uascOrdinarySurchargeValueMultiple()
    { return 3; }

inline int uascExtraordinarySurchargePercent()
    { return 100; }

inline int uascExtraordinaryValueMultiple()
    { return 3; }

inline bool uascSurchargeWhicheverIsGreater()
    { return true; }

// ---- the danger and aging clauses ----
inline bool uascDangerSpellsAtLeastDoubleFee()
    { return true; }

inline bool uascDangerGuaranteesRequired()
    { return true; }

inline bool uascDangerClauseInterleaved()
    { return true; }

inline bool uascAgingSpellsNeedCounterFirst()
    { return true; }

inline bool uascInsignificantAgingException()
    { return true; }

// The printed example: a young elf unconcerned
// about aging 5 years, though a fee of ten times
// normal might be charged.
inline int uascElfExampleAgingYears()
    { return 5; }

inline int uascElfExampleFeeMultiple()
    { return 10; }

// ---- the payment reads ----
inline bool uascMagicItemAcceptedInLieuOfCash()
    { return true; }

inline bool uascItemValueAdjustedByReaction()
    { return true; }

inline bool uascNpcCharacterAffectsCosts()
    { return true; }

// ---- the hostile caster reads ----
inline bool uascHostileAtLeastDoubleFee()
    { return true; }

inline bool uascHostileMayRefuseEntirely()
    { return true; }

inline bool uascHostileMayBeBribedWithItem()
    { return true; }

inline bool uascGoodUnlikelyToCastForEvil()
    { return true; }

inline bool uascDuressUsesDmgRules()
    { return true; }

}   // namespace rules
"""
    clean(HDRC, 78)
    wr(USC, HDRC + NL)
    applied.append('uaspellcost.h: the pins')
s = rd(USC)
assert s.count('namespace rules {') == 1, 'b4 ns'
assert s.count('inline') == 24, 'b4 inline count'
assert s.count('R365') == 1, 'b4 round tag'
assert s.count('uascFeePerSpellLevelGp()') == 1, 'b4 fee fn'
assert s.count('uascDuressUsesDmgRules()') == 1, 'b4 duress fn'
assert 'uam' not in s, 'b4 no mu ref'
assert 'uadruid' not in s, 'b4 no druid ref'
assert 'uailc' not in s, 'b4 no cantrip ref'
assert 'uail1' not in s, 'b4 no 1st ref'
assert 'uail6' not in s, 'b4 no 6th ref'
assert 'uail7' not in s, 'b4 no 7th ref'
assert 'uaila' not in s, 'b4 no acq ref'
assert len(applied) + len(already) == 5, 'b4 count'


# ---- (c1) the gap: the IL spells close ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'CLOSED R365: the 6th and' in s:
    already.append('gap report: the close')
else:
    OLD = "- [ ] **The new illusionist spells**"
    assert s.count(OLD) == 1, 'c1 open hdr'
    s = s.replace(OLD,
        "- [x] **The new illusionist spells**")
    TAIL_OLD = NL.join([
        '        next round.',
        '',
        '## Cantrips (a category of their own)',
    ])
    assert s.count(TAIL_OLD) == 1, 'c1 tail'
    NOTE = NL.join([
        '      - CLOSED R365: the 6th and',
        '        7th levels pinned',
        '        (rules/uailspells6.h and',
        '        rules/uailspells7.h) - death',
        '        fog with the acid ladder,',
        '        mislead with the invisibility',
        '        cloak, phantasmagoria (the',
        '        level cell lost, pinned from',
        '        the section header), the',
        '        mirage arcane at the printed',
        '        6th (the item-list 7th',
        '        divergence flagged pending',
        '        the PDF), shadow walk with',
        '        the plane reads and weird',
        '        with the lost prose; all',
        '        printed levels now pinned',
        '        (R363-R365) - the item',
        '        CLOSED; the acquisition',
        '        rules and the cantrip tier',
        '        seam ride their own items.',
    ])
    clean(NOTE, 57)
    s = s.replace(TAIL_OLD, NL.join([
        '        next round.',
        NOTE,
        '',
        '## Cantrips (a category of their own)',
    ]))
    wr(GP, s)
    applied.append('gap report: the close')
# ---- (c2) the gap: the acquisition note ----
s = rd(GP)
if 'R365: the fragment-verified' in s:
    already.append('gap report: the acq note')
else:
    TAIL2_OLD = NL.join([
        '- [ ] **Illusionist spell acquisition**',
        '      (p. 80) - the starting list table;',
        '      the illusionist book differences.',
    ])
    assert s.count(TAIL2_OLD) == 1, 'c2 tail'
    NOTE2 = NL.join([
        '- [ ] **Illusionist spell acquisition**',
        '      (p. 80) - the starting list table;',
        '      the illusionist book differences.',
        '      - R365: the fragment-verified',
        '        cells pinned',
        '        (rules/uailacquisition.h) -',
        '        the three-group start, the',
        '        five defensive rows, the',
        '        misc fragments, the DM',
        '        three-option note, the book',
        '        differences (24/16/8 and 6/4/2',
        '        with the MU first-level',
        '        book), the illusionist cantrip',
        '        counts; the offensive/misc row',
        '        boundaries garble - stays',
        '        open pending the PDF read.',
    ])
    clean(NOTE2, 57)
    s = s.replace(TAIL2_OLD, NOTE2)
    wr(GP, s)
    applied.append('gap report: the acq note')
# ---- (c3) the gap: the cost item close ----
s = rd(GP)
if 'CLOSED R365: the pin round' in s:
    already.append('gap report: the cost close')
else:
    OLD3 = NL.join([
        '- [ ] **The cost of spell casting** (pp.',
        '      80-81).',
    ])
    assert s.count(OLD3) == 1, 'c3 item'
    NEW3 = NL.join([
        '- [x] **The cost of spell casting** (pp.',
        '      80-81).',
        '      - CLOSED R365: the pin round',
        '        (rules/uaspellcost.h) - the',
        '        200 gp per level basic fee with',
        '        the doubled components, the',
        '        10 percent/3x and 100',
        '        percent/3x surcharges, the',
        '        danger and aging clauses, the',
        '        item-payment and hostile-caster',
        '        reads; the section prints',
        '        clean - CLOSED.',
    ])
    clean(NEW3, 57)
    s = s.replace(OLD3, NEW3)
    wr(GP, s)
    applied.append('gap report: the cost close')
s = rd(GP)
assert s.count(
    'CLOSED R365: the 6th and'
) == 1, 'c1 note'
assert s.count(
    'R365: the fragment-verified'
) == 1, 'c2 note'
assert s.count(
    'CLOSED R365: the pin round'
) == 1, 'c3 note'
assert s.count(
    '- [x] **The new illusionist spells**'
) == 1, 'c1 flip'
assert s.count(
    '- [ ] **The illusionist cantrips**'
) == 1, 'c cantrips kept open'
assert s.count(
    '- [ ] **The cantrip acquisition rules**'
) == 1, 'c cantrip rules kept'
assert s.count(
    '- [ ] **Illusionist spell acquisition**'
) == 1, 'c acq kept open'
assert s.count(
    '- [x] **The cost of spell casting**'
) == 1, 'c3 flip'
assert s.count(
    '- [x] **The new magic-user spells**'
) == 1, 'c mu closed kept'
assert s.count(
    'R364: the 3rd, 4th and'
) == 1, 'c r364 kept'
assert s.count(
    'R363: the cantrips and the'
) == 1, 'c r363 kept'
assert s.count(
    '## Cantrips (a category of their own)'
) == 1, 'c cantrips section'
assert len(applied) + len(already) == 8, 'c count'


# ---- (d) regtest.cpp: the includes, the
# audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R365 UA IL 6th/7th and DM pin audit' in s:
    already.append('regtest.cpp: the R365 audit')
else:
    INC_ANCH = (
        '#include "rules/uailspells5.h"'
        '  // R364: the UA new illusionist'
        ' 5th level')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uailspells6.h"'
        '  // R365: the UA new illusionist'
        ' 6th level',
        '#include "rules/uailspells7.h"'
        '  // R365: the UA new illusionist'
        ' 7th level',
        '#include "rules/uailacquisition.h"'
        '  // R365: the UA illusionist'
        ' acquisition',
        '#include "rules/uaspellcost.h"'
        '  // R365: the UA spell casting cost',
    ])
    AUD_ANCH = (
        '    // ---- R227: the wis mental save'
        ' wiring audit ----')
    AUDIT = r"""    // ---- R365: the UA new illusionist
    // 6th/7th spells, acquisition and
    // cost pin audit ----
    // The UA NEW ILLUSIONIST SPELLS
    // (pp. 71-73) - the 6th-level four
    // (death fog with the acid ladder,
    // mislead with the improved-
    // invisibility cloak, phantasmagoria
    // with the lost level cell, the mirage
    // arcane at the printed 6th cell - the
    // item-list 7th divergence flagged)
    // and the 7th-level pair (shadow walk
    // with the plane reads, weird with the
    // lost prose); the UA ILLUSIONIST
    // SPELL ACQUISITION fragments and the
    // UA COST OF SPELL CASTING pins.
    // The R342 IL table seam prints only
    // Shadow Walk at the readable 7th; the
    // 6th column is wholly lost. The item
    // closes this round - all printed
    // levels pinned R363-R365.
    {
        using namespace rules;
        int bad = 0;
        // ---- death fog ----
        // ---- mislead ----
        // ---- phantasmagoria ----
        // ---- mirage arcane ----
            if (strcmp(uail6DfogName(),
                "Death Fog (Alteration - Evocation)") != 0) ++bad;
            if (uail6DfogLevel() != 6) ++bad;
            if (!uail6DfogComponentsVSM()) ++bad;
            if (uail6DfogCastingTimeSegments() != 6) ++bad;
            if (uail6DfogRangeInches() != 3) ++bad;
            if (!uail6DfogSaveNone()) ++bad;
            if (!uail6DfogDurationCellSuspectGarble()) ++bad;
            if (uail6DfogAoeCubicPerLevel() != 2) ++bad;
            if (!uail6DfogAoeUnitCellLost()) ++bad;
            if (!uail6DfogCreatesSolidFogArea()) ++bad;
            if (!uail6DfogHighlyAcidic()) ++bad;
            if (!uail6DfogVaporsDeadlyToVegetation()) ++bad;
            if (uail6DfogPlantsDieInRounds() != 2) ++bad;
            if (uail6DfogBushesShrubsDieInRounds() != 4) ++bad;
            if (uail6DfogSmallTreesDieInRounds() != 8) ++bad;
            if (uail6DfogLargeTreesDieInRounds() != 16) ++bad;
            if (!uail6DfogAnimalsNotImmuneSuffer()) ++bad;
            if (uail6DfogDamageRound1() != 1) ++bad;
            if (uail6DfogDamageRound2() != 2) ++bad;
            if (uail6DfogDamageRound3() != 4) ++bad;
            if (uail6DfogDamageRound4On() != 8) ++bad;
            if (!uail6DfogOtherwiseSameAsSolidFog()) ++bad;
            if (!uail6DfogComponentsPeasHoofAcid()) ++bad;
            if (!uail6DfogAcidIncludesVinegarCrystals()) ++bad;
            if (strcmp(uail6MisleadName(),
                "Mislead (Illusion/Phantasm)") != 0) ++bad;
            if (uail6MisleadLevel() != 6) ++bad;
            if (!uail6MisleadSomaticOnly()) ++bad;
            if (uail6MisleadCastingTimeSegments() != 1) ++bad;
            if (!uail6MisleadRangeCellSuspectGarble()) ++bad;
            if (!uail6MisleadSaveNone()) ++bad;
            if (uail6MisleadDurationRoundsPerLevel() != 1) ++bad;
            if (!uail6MisleadAoeSpecial()) ++bad;
            if (!uail6MisleadCreatesPhantasmalDouble()) ++bad;
            if (!uail6MisleadCloakedByImprovedInvis()) ++bad;
            if (!uail6MisleadCasterFreeToGoElsewhere()) ++bad;
            if (!uail6MisleadPhantasmSeeminglyMovesAway()) ++bad;
            if (!uail6MisleadPhantasmSpeaksAndGestures()) ++bad;
            if (!uail6MisleadSensorySentenceGarbled()) ++bad;
            if (!uail6MisleadTrueSightRevealsIllusion()) ++bad;
            if (!uail6MisleadGemOfSeeingRevealsIllusion()) ++bad;
            if (!uail6MisleadDetectInvisDetectsCaster()) ++bad;
            if (!uail6MisleadTrueSightDetectsCaster()) ++bad;
            if (!uail6MisleadTrueSeeingDetectsCaster()) ++bad;
            if (!uail6MisleadRobeOfEyesDetectsCaster()) ++bad;
            if (!uail6MisleadShadowDoorCrossRef()) ++bad;
            if (strcmp(uail6PhantName(),
                "Phantasmagoria (Illusion/Phantasm)") != 0) ++bad;
            if (uail6PhantLevel() != 6) ++bad;
            if (!uail6PhantLevelCellLost()) ++bad;
            if (!uail6PhantComponentsVerbalSomatic()) ++bad;
            if (uail6PhantCastingTimeSegments() != 6) ++bad;
            if (!uail6PhantSaveNegates()) ++bad;
            if (!uail6PhantDurationCellSuspectGarble()) ++bad;
            if (!uail6PhantAoeCellGarbled()) ++bad;
            if (!uail6PhantSpecialFormOfSpectralForces()) ++bad;
            if (!uail6PhantTriggeredBySpecialAction()) ++bad;
            if (!uail6PhantFullVisualAudialOlfactoryTouch()) ++bad;
            if (!uail6PhantFallingSlidingMovingRapidly()) ++bad;
            if (!uail6PhantTriggerOnPitFallOrDoorOpen()) ++bad;
            if (!uail6PhantMustInvolveFallingRushing()) ++bad;
            if (!uail6PhantDwindlingPerspectiveRead()) ++bad;
            if (!uail6PhantUnlikeProgrammedIllusion()) ++bad;
            if (strcmp(uail6MirageName(),
                "Mirage Arcane (Illusion/Phantasm - "
                "Alteration)") != 0) ++bad;
            if (uail6MirageLevel() != 6) ++bad;
            if (!uail6MirageLevelDivergenceFlagged()) ++bad;
            if (!uail6MirageComponentsVSOptionalM()) ++bad;
            if (uail6MirageRangeInchesPerLevel() != 1) ++bad;
            if (uail6MirageCastingTimeBasicSegments() != 3) ++bad;
            if (uail6MirageCastingTimeComplexSegments() != 6) ++bad;
            if (!uail6MirageSaveNone()) ++bad;
            if (!uail6MirageDurationSpecial()) ++bad;
            if (uail6MirageAoeRadiusInchesPerLevel() != 1) ++bad;
            if (!uail6MirageSimilarToVacancyButStronger()) ++bad;
            if (!uail6MirageSimilarToMirageCantrip()) ++bad;
            if (!uail6MirageAreaAppearsOtherThanItIs()) ++bad;
            if (!uail6MirageEnvisionedByCaster()) ++bad;
            if (!uail6MirageHeldByFaintConcentration()) ++bad;
            if (uail6MiragePersistsBaseTurns() != 6) ++bad;
            if (uail6MiragePersistsTurnsPerLevel() != 1) ++bad;
            if (!uail6MirageConcentrationOkInConversation()) ++bad;
            if (!uail6MirageConcentrationNotInCombat()) ++bad;
            if (!uail6MirageMustBePersonallySeen()) ++bad;
            if (!uail6MirageMaterialBitGrantsReality()) ++bad;
            if (!uail6MirageBasicForcefulContactNeeded()) ++bad;
            if (!uail6MirageComplexDetectionOnlyMagical()) ++bad;
            if (!uail6MirageSubjectToDispelIllusionOrMagic()) ++bad;
            if (!uail6MirageMindCausesBodyEffects()) ++bad;
            if (!uail6MirageBeliefCannotAffectLawsOfNature()) ++bad;
            if (!uail6MirageHotCoalsExample()) ++bad;
            if (!uail6MirageImaginaryFoodNourishes()) ++bad;
            if (!uail6MirageFeatherbedExample()) ++bad;
            if (!uail6MirageGravityUnaffected()) ++bad;
            if (!uail6MirageEnvisionedBridgeWillNotHold()) ++bad;
            if (!uail6MirageWitnessesSeeDisappearance()) ++bad;
            if (!uail6MirageDisappearanceNotLinkedToIllusion()) ++bad;
        // ---- shadow walk ----
        // ---- weird ----
            if (strcmp(uail7ShadowName(),
                "Shadow Walk (Illusion - Enchantment)") != 0) ++bad;
            if (uail7ShadowLevel() != 7) ++bad;
            if (!uail7ShadowComponentsCellGarbled()) ++bad;
            if (!uail7ShadowRangeTouch()) ++bad;
            if (uail7ShadowCastingTimeSegments() != 1) ++bad;
            if (!uail7ShadowSaveNone()) ++bad;
            if (uail7ShadowDurationTurnsPerLevel() != 6) ++bad;
            if (!uail7ShadowAoeSpecial()) ++bad;
            if (!uail7ShadowRequiresHeavyShadows()) ++bad;
            if (!uail7ShadowEdgeOfPrimeMaterial()) ++bad;
            if (!uail7ShadowAwareOfPrimePosition()) ++bad;
            if (uail7ShadowLeaguesPerTurn() != 7) ++bad;
            if (!uail7ShadowRapidTravelByStepping()) ++bad;
            if (!uail7ShadowDestinationControlled()) ++bad;
            if (!uail7ShadowOtherPlanesPerilousTransit()) ++bad;
            if (!uail7ShadowTouchedAlsoTransition()) ++bad;
            if (!uail7ShadowMayFollowWanderOrStumble()) ++bad;
            if (!uail7ShadowLostOrAbandonedFiftyFifty()) ++bad;
            if (!uail7ShadowUnwillingSaveNegates()) ++bad;
            if (strcmp(uail7WeirdName(),
                "Weird (Evocation - Illusion/Phantasm)") != 0) ++bad;
            if (uail7WeirdLevel() != 7) ++bad;
            if (!uail7WeirdComponentsVerbalSomatic()) ++bad;
            if (uail7WeirdCastingTimeSegments() != 7) ++bad;
            if (uail7WeirdRangeInches() != 3) ++bad;
            if (!uail7WeirdSaveSpecial()) ++bad;
            if (!uail7WeirdDurationSpecial()) ++bad;
            if (uail7WeirdAoeRadiusInches() != 2) ++bad;
            if (!uail7WeirdProseLargelyLost()) ++bad;
            if (!uail7WeirdCasterMustFragmentPrints()) ++bad;
        // ---- the starting list ----
        // ---- the illusionist spell book differences ----
        // ---- the illusionist cantrip counts ----
            if (!uailaThreeGroupsOneEach()) ++bad;
            if (!uailaAlwaysKnowsReadIllusionistMagic()) ++bad;
            if (uailaDefensiveRowCount() != 5) ++bad;
            if (!uailaRow1ColorSpray()) ++bad;
            if (!uailaRow1AudibleGlamer()) ++bad;
            if (!uailaRow1Darkness()) ++bad;
            if (!uailaRow2Hypnotism()) ++bad;
            if (!uailaRow3Light()) ++bad;
            if (!uailaRow3GazeReflection()) ++bad;
            if (!uailaRow4PhantasmalForce()) ++bad;
            if (!uailaRow4WallOfFog()) ++bad;
            if (!uailaRow5ChromaticOrb()) ++bad;
            if (!uailaRow5ChromaticOrbIsChoose()) ++bad;
            if (!uailaOffensiveMiscColumnsMerged()) ++bad;
            if (!uailaMiscChangeSelf()) ++bad;
            if (!uailaMiscDancingLights()) ++bad;
            if (!uailaMiscDetect()) ++bad;
            if (!uailaMiscDetectInvisibility()) ++bad;
            if (!uailaMiscPhantomArmor()) ++bad;
            if (!uailaRowBoundariesLost()) ++bad;
            if (uailaDmOptionCount() != 3) ++bad;
            if (!uailaUaSpellsAddedForIllusionistsOnly()) ++bad;
            if (!uailaNotDoneForMagicUsers()) ++bad;
            if (!uailaBooksSameAsMuWithExceptions()) ++bad;
            if (uailaStandardBookLowLevelSpells() != 24) ++bad;
            if (uailaStandardBookMidLevelSpells() != 16) ++bad;
            if (uailaStandardBookHighLevelSpells() != 8) ++bad;
            if (!uailaMuFirstLevelNeedsNewBook()) ++bad;
            if (uailaMuFirstLevelBookCapacity() != 24) ++bad;
            if (uailaTravellingBookLowLevelSpells() != 6) ++bad;
            if (uailaTravellingBookMidLevelSpells() != 4) ++bad;
            if (uailaTravellingBookHighLevelSpells() != 2) ++bad;
            if (!uailaScriptReadableByIllusionistsOnly()) ++bad;
            if (!uailaCrossClassBookBan()) ++bad;
            if (!uailaNamesakeSpellsTriggerDifferently()) ++bad;
            if (!uailaHasAllMuCantrips()) ++bad;
            if (uailaMinorIllusionCantripsMin() != 5) ++bad;
            if (uailaMinorIllusionCantripsMax() != 8) ++bad;
            if (!uailaMinorIllusionNotAvailableToMu()) ++bad;
            if (uailaUsefulCapIntMinus() != 3) ++bad;
            if (uailaUsefulCapAtInt18() != 15) ++bad;
            if (uailaReversedKnownMin() != 2) ++bad;
            if (uailaReversedKnownMax() != 5) ++bad;
            if (uailaLegerdemainKnownMin() != 3) ++bad;
            if (uailaLegerdemainKnownMax() != 6) ++bad;
            if (uailaPersonAffectingKnownMin() != 2) ++bad;
            if (uailaPersonAffectingKnownMax() != 5) ++bad;
            if (uailaPersonalKnownMin() != 2) ++bad;
            if (uailaPersonalKnownMax() != 5) ++bad;
            if (uailaHauntingSoundKnownMin() != 5) ++bad;
            if (uailaHauntingSoundKnownMax() != 8) ++bad;
            if (!uailaMuCantripPropertiesOtherwiseApply()) ++bad;
        // ---- the basic fee ----
        // ---- the surcharges ----
        // ---- the danger and aging clauses ----
        // ---- the payment reads ----
        // ---- the hostile caster reads ----
            if (uascFeePerSpellLevelGp() != 200) ++bad;
            if (!uascWillingCasterWorksForFee()) ++bad;
            if (!uascMaterialComponentsDoubled()) ++bad;
            if (!uascComponentSubstitutionsAllowed()) ++bad;
            if (uascOrdinarySurchargePercent() != 10) ++bad;
            if (uascOrdinarySurchargeValueMultiple() != 3) ++bad;
            if (uascExtraordinarySurchargePercent() != 100) ++bad;
            if (uascExtraordinaryValueMultiple() != 3) ++bad;
            if (!uascSurchargeWhicheverIsGreater()) ++bad;
            if (!uascDangerSpellsAtLeastDoubleFee()) ++bad;
            if (!uascDangerGuaranteesRequired()) ++bad;
            if (!uascDangerClauseInterleaved()) ++bad;
            if (!uascAgingSpellsNeedCounterFirst()) ++bad;
            if (!uascInsignificantAgingException()) ++bad;
            if (uascElfExampleAgingYears() != 5) ++bad;
            if (uascElfExampleFeeMultiple() != 10) ++bad;
            if (!uascMagicItemAcceptedInLieuOfCash()) ++bad;
            if (!uascItemValueAdjustedByReaction()) ++bad;
            if (!uascNpcCharacterAffectsCosts()) ++bad;
            if (!uascHostileAtLeastDoubleFee()) ++bad;
            if (!uascHostileMayRefuseEntirely()) ++bad;
            if (!uascHostileMayBeBribedWithItem()) ++bad;
            if (!uascGoodUnlikelyToCastForEvil()) ++bad;
            if (!uascDuressUsesDmgRules()) ++bad;
        // the R342 IL table seam: the
        // readable columns print only PHB
        // names except Shadow Walk at the
        // 7th; none of the new 6th/7th
        // names seam-checks
            if (uas2Il1stCount() != 5) ++bad;
            if (uas2Il2ndCount() != 4) ++bad;
            if (uas2Il7thCount() != 1) ++bad;
            if (strcmp(uas2Il7thName(0),
                        "Shadow Walk") != 0) ++bad;
            if (!uas2IlCantripListLost()) ++bad;
            static const char* const nn[5] = {
                "Death Fog", "Mislead",
                "Phantasmagoria",
                "Mirage Arcane", "Weird",
            };
            for (int n = 0; n < 5; ++n) {
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
        printf("R365 UA IL 6th/7th and DM pin audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R365 audit')
s = rd(RT)
assert s.count(
    'R365 UA IL 6th/7th and DM pin audit: bad '
) == 1, 'd audit line'
assert s.count(
    'R364 UA IL 3rd/4th/5th spells pin audit: bad ') == 1, 'd kept'
assert s.count(
    'R363 UA IL cantrips/1st/2nd pin audit: bad ') == 1, 'd kept'
assert s.count(
    'R362 UA MU 8th/9th level spells pin audit: bad ') == 1, 'd kept'
assert s.count(
    'R361 UA MU 7th level spells pin audit: bad ') == 1, 'd kept'
assert s.count(
    'R360 UA MU 5th/6th level spells pin audit: bad ') == 1, 'd kept'
assert s.count(
    'R359 UA MU 4th level spells pin audit: bad ') == 1, 'd kept'
assert s.count(
    'R358 UA MU 3rd level spells pin audit: bad ') == 1, 'd kept'
assert s.count(
    'R357 UA MU 2nd level spells pin audit: bad ') == 1, 'd kept'
assert s.count(
    'R356 UA MU 1st level spells pin audit: bad ') == 1, 'd kept'
assert s.count(
    'R355 UA druid 7th level spells pin audit: bad ') == 1, 'd kept'
assert s.count(
    'R354 UA druid 6th level spells pin audit: bad ') == 1, 'd kept'
assert s.count(
    'R350 UA druid 1st level spells pin audit: bad ') == 1, 'd kept'
assert s.count(
    'R349 UA cleric 7th level spells pin audit: bad ') == 1, 'd kept'
assert s.count('audit: bad ') == 292, 'd census 292'
assert s.count(
    'R227: the wis mental save'
) == 1, 'd r227 kept'
assert s.count(
    '#include "rules/uailspells6.h"'
) == 1, 'd new include'
assert s.count(
    '#include "rules/uailspells7.h"'
) == 1, 'd new include'
assert s.count(
    '#include "rules/uailacquisition.h"'
) == 1, 'd new include'
assert s.count(
    '#include "rules/uaspellcost.h"'
) == 1, 'd new include'
assert s.count(
    '#include "rules/uailcantrips.h"'
) == 1, 'd il include'
assert s.count(
    '#include "rules/uailspells1.h"'
) == 1, 'd il include'
assert s.count(
    '#include "rules/uailspells2.h"'
) == 1, 'd il include'
assert s.count(
    '#include "rules/uailspells3.h"'
) == 1, 'd il include'
assert s.count(
    '#include "rules/uailspells4.h"'
) == 1, 'd il include'
assert s.count(
    '#include "rules/uailspells5.h"'
) == 1, 'd il include'
for i in range(1, 10):
    assert s.count(
        '#include "rules/uamuspells%d.h"'
        % i) == 1, 'd mu include'
assert len(applied) + len(already) == 9, 'd count'


# ---- the summary ----
print('R365 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R365 note: the UA new illusionist')
print('6th/7th closing pin round - death',)
print('fog, mislead, phantasmagoria and',)
print('the mirage arcane at the printed 6th',)
print('(the item-list 7th divergence flagged',)
print('pending the PDF); shadow walk and weird',)
print('at 7th; combined: the illusionist spell',)
print('acquisition fragments (the item stays',)
print('open, the table cells garble) and the',)
print('cost of spell casting (the item',)
print('CLOSED); the IL spells item flips',)
print('CLOSED - all printed levels pinned',)
print('R363-R365; the census 291 -> 292',)
print('commit: R365: the UA new illusionist',)
print('6th/7th levels, acquisition and cost',)
print('pin round (census 292)',)

