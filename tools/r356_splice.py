#!/usr/bin/env python3
# R356: the UA NEW MAGIC-USER
# SPELLS pin round, the 1st level
# (p. 51) - alarm (the lost range
# cell and the door-value hole),
# armor, firewater, grease, melt
# (the run interleave), mount (the
# level ladder), precipitation (the
# clerical seam minus the holy
# symbol), run, taunt (the scrambled
# opener) and wizard mark. The
# digit-garble family decodes the
# seven level-cell and casting-time
# 7s as 1. The item stays open (the
# 2nd-9th levels).
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
    '- R355 landed 2026-10-11: commit',
    '  a70626d, census 282, the UA',
    '  new druid 7th level spells pin',
    '  round (rules/uadruidspells7.h):',
    '  changestaff (the lost name',
    '  header, the hit-die ladder with',
    '  the wish-only recovery) and',
    '  sunray (the blindness tiers and',
    '  the undead damage split); the',
    '  family decodes the 7 round as',
    '  1; the druid spells item',
    '  CLOSED; the R354 seed merge',
    '  repaired (the entry list must',
    '  open with a blank element).',
    '  GREEN on the first run.',
])
s = rd(SD)
if 'R355 landed 2026-10-11' in s:
    already.append('seed: the R355 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R355 record')
s = rd(SD)
assert s.count('R355 landed 2026-10-11') == 1, 'a entry'
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
US = 'rules/uamuspells1.h'
if os.path.exists(US) and 'R356' in rd(US):
    already.append('uamuspells1.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uamuspells1.h
// The UA NEW MAGIC-USER SPELLS (p. 51) pins, R356: the
// 1st-level spell descriptions - alarm, armor, firewater,
// grease, melt, mount, precipitation, run, taunt and
// wizard mark.
//
// Pin-era pattern (R322): pinned data only - no engine site
// exists.
//
// JUDGMENTs (the decode method):
//   - the digit-garble family (the R343 precedent): the
//     level cells print 7 for alarm, armor, firewater,
//     grease, precipitation, melt and wizard mark - the
//     family decodes 1 (mount, run and taunt print the
//     clean 1; the family corroborates). The casting time
//     cells print "7 turn"/"7 round"/"7 segment" - the
//     family decodes 1 of the printed unit; the firewater
//     and wizard mark blocks print the clean 1 segment.
//   - the stat blocks interleave both columns across the
//     whole level (mount/firewater, melt/run, melt/taunt):
//     the melt range cell position-decodes as 3" from the
//     run block (the run prose pins touch), flagged with
//     doubt pending the PDF.
//   - the alarm radius sentence loses the door value:
//     "Reduce the radius by for interposing doors" [sic] -
//     the wall value 20 degrees pins clean; the door value
//     is a hole.
//   - the alarm components cell scrambles: "V," + "M"
//     fragments; the prose pins the materials.
//   - the run/melt block prints "V. S, M" - the period
//     decodes as a comma [sic].
//   - the taunt opener interleaves: "an i caster to jape
//     god ol" [sic] - the prose reassembles as "enables
//     the caster to jape and jeer at any creature".
//   - the precipitation prose: identical to the 1st-level
//     clerical spell of the same name, except that a holy
//     symbol is not part of the material component - the
//     seam-check runs against the R343 clerical pin; the
//     MU stat block prints the components cell the
//     clerical block lost.
//   - the armor note loses words before "devices other
//     than a ring of protection" - a hole pending the PDF.
//
// OCR holes (the item stays open - the 2nd through 9th
// levels pin in later rounds; these stay pending the PDF):
// the alarm range and door-value cells; the melt range
// doubt; the armor note words; the firewater range cell.
// ===========================================================================

#pragma once

namespace rules {

// ---- alarm (Evocation), p. 51 ----
inline const char* uam1AlarmName()
    { return "Alarm (Evocation)"; }

// The level cell prints 7 - the digit-garble family
// decodes 1.
inline int uam1AlarmLevel()
    { return 1; }

inline bool uam1AlarmLevelGarbleDecoded()
    { return true; }

// The range cell prints empty - a hole.
inline bool uam1AlarmRangeCellLost()
    { return true; }

inline int uam1AlarmDurationTurnsMin()
    { return 2; }

inline int uam1AlarmDurationTurnsMax()
    { return 8; }

inline int uam1AlarmDurationTurnsPerLevel()
    { return 1; }

inline int uam1AlarmAoeSqFtPerLevel()
    { return 20; }

// The components cell scrambles: only "V," and "M"
// fragments print.
inline bool uam1AlarmComponentsCellScrambled()
    { return true; }

// The casting time prints "7 round" - the family decodes
// 1 round.
inline int uam1AlarmCastingTimeRounds()
    { return 1; }

inline bool uam1AlarmSaveNone()
    { return true; }

// The area reacts to any living creature larger than a
// normal rat - about one-half cubic foot or 3 pounds.
inline bool uam1AlarmTriggerLargerThanRat()
    { return true; }

inline int uam1AlarmTriggerVolumeHalfCuFt()
    { return 1; }

inline int uam1AlarmTriggerWeightPounds()
    { return 3; }

// The area can be a portal, a section of floor, stairs,
// and the like; contact triggers the evocation.
inline bool uam1AlarmPortalFloorStairsArea()
    { return true; }

// The loud ringing is clearly heard within a 60" radius.
inline int uam1AlarmRadiusInches()
    { return 60; }

// "Reduce the radius by for interposing doors" [sic] - the
// door value is lost; the wall value pins at 20 degrees.
inline bool uam1AlarmDoorValueLost()
    { return true; }

inline int uam1AlarmWallReductionDegrees()
    { return 20; }

// The sound lasts 1 segment and then ceases.
inline int uam1AlarmSoundSegments()
    { return 1; }

// Undead creatures never cause the spell to function.
inline bool uam1AlarmUndeadNeverTrigger()
    { return true; }

// Invisible creatures and living creatures from other
// planes do trigger it.
inline bool uam1AlarmInvisibleAndPlanarTrigger()
    { return true; }

// Flying and levitating creatures trigger it.
inline bool uam1AlarmFlyingLevitatingTrigger()
    { return true; }

// The material: a tiny bell and a piece of very fine
// silver wire.
inline bool uam1AlarmMaterialTinyBell()
    { return true; }

inline bool uam1AlarmMaterialFineSilverWire()
    { return true; }

// ---- armor (Conjuration), p. 51 ----
inline const char* uam1ArmorName()
    { return "Armor (Conjuration)"; }

inline int uam1ArmorLevel()
    { return 1; }

inline bool uam1ArmorRangeTouch()
    { return true; }

inline bool uam1ArmorDurationSpecial()
    { return true; }

inline bool uam1ArmorAoeOneCreature()
    { return true; }

inline bool uam1ArmorSaveNone()
    { return true; }

// The caster creates an invisible field of force serving
// as leather armor, AC 8.
inline bool uam1ArmorCreatesForceFieldAc8()
    { return true; }

// Cast on a person already armored, it has no effect.
inline bool uam1ArmorNoEffectIfAlreadyArmored()
    { return true; }

// A creature with armor class normally better than 9
// benefits by one step: AC 8 becomes 7, 7 becomes 6, and
// so on.
inline bool uam1ArmorBetterThanNineGainsOneStep()
    { return true; }

// The spell does not slow or hinder movement, adds no
// weight or encumbrance, and does not prevent spell
// casting.
inline bool uam1ArmorNoWeightOrEncumbrance()
    { return true; }

inline bool uam1ArmorDoesNotPreventCasting()
    { return true; }

// It lasts until dispelled or until cumulative damage
// exceeds 8 points plus 1 per level of the caster.
inline int uam1ArmorDamageThresholdBase()
    { return 8; }

inline int uam1ArmorDamageThresholdPerLevel()
    { return 1; }

// Unless cast by a magic-user of 2nd level or higher, the
// 8-then-1 example would dispel it at that point.
inline int uam1ArmorExampleCasterLevelForExceed()
    { return 2; }

// The note loses words before "devices other than a ring
// of protection" - a hole.
inline bool uam1ArmorNoteWordsLost()
    { return true; }

// The material: a piece of finely cured leather blessed
// by a cleric.
inline bool uam1ArmorMaterialBlessedLeather()
    { return true; }

// ---- mount (Conjuration/Summoning), p. 51 ----
inline const char* uam1MountName()
    { return "Mount (Conjuration/Summoning)"; }

// The level cell prints the clean 1.
inline int uam1MountLevel()
    { return 1; }

// The casting time prints "7 round" - the family decodes
// 1 round.
inline int uam1MountCastingTimeRounds()
    { return 1; }

inline int uam1MountDurationTurnsBase()
    { return 12; }

inline int uam1MountDurationTurnsPerLevel()
    { return 6; }

inline bool uam1MountAoeOneCreature()
    { return true; }

inline bool uam1MountSaveNone()
    { return true; }

// The caster calls a normal animal to serve as a mount;
// at expiration it disappears, returning to its own
// place.
inline bool uam1MountServesThenReturns()
    { return true; }

// The mount ladder: 1st-3rd level, mule or light horse.
inline int uam1MountMuleLightHorseMaxLevel()
    { return 3; }

// 4th-7th level: draft horse or warhorse.
inline int uam1MountDraftWarhorseMinLevel()
    { return 4; }

inline int uam1MountDraftWarhorseMaxLevel()
    { return 7; }

// 8th-12th level: camel.
inline int uam1MountCamelMinLevel()
    { return 8; }

inline int uam1MountCamelMaxLevel()
    { return 12; }

// 13th level and up: elephant, with a houda at 18th.
inline int uam1MountElephantMinLevel()
    { return 13; }

inline int uam1MountHoudaAtLevel()
    { return 18; }

// A caster may always choose a lower-level mount.
inline bool uam1MountLowerLevelChoiceAllowed()
    { return true; }

// The mount comes with no riding gear unless it is of a
// class lower than the caster would normally gain.
inline bool uam1MountNoRidingGearUnlessLowerClass()
    { return true; }

// The statistics of the animal are typical of all
// creatures of the same class.
inline bool uam1MountStatsTypicalOfClass()
    { return true; }

// The material: a bit of hair or dung from the type of
// animal to be conjured.
inline bool uam1MountMaterialHairOrDung()
    { return true; }

// ---- firewater (Alteration), p. 51 ----
inline const char* uam1FirewaterName()
    { return "Firewater (Alteration)"; }

inline int uam1FirewaterLevel()
    { return 1; }

// The casting time prints the clean 1 segment.
inline int uam1FirewaterCastingTimeSegments()
    { return 1; }

// The range cell is lost in the interleave - a hole.
inline bool uam1FirewaterRangeCellLost()
    { return true; }

inline bool uam1FirewaterSaveNone()
    { return true; }

// The magic-user changes a volume of water to a
// volatile, flammable substance similar to alcohol and
// lighter than water.
inline bool uam1FirewaterVolatileAlcoholLike()
    { return true; }

inline bool uam1FirewaterLighterThanWater()
    { return true; }

// Exposed to flame, fire or even a spark, it bursts into
// flames and burns with a hot fire.
inline bool uam1FirewaterIgnitesOnSpark()
    { return true; }

// Each creature subject to firewater flame suffers 2-12
// hit points of damage.
inline int uam1FirewaterDamageMin()
    { return 2; }

inline int uam1FirewaterDamageMax()
    { return 12; }

// The firewater evaporates and is useless within 1
// round; it must be ignited within 10 segments of its
// creation, even if sealed.
inline int uam1FirewaterEvaporatesInRounds()
    { return 1; }

inline int uam1FirewaterIgniteWithinSegments()
    { return 10; }

// The material: a few grains of sugar and a raisin.
inline bool uam1FirewaterMaterialSugarGrains()
    { return true; }

inline bool uam1FirewaterMaterialRaisin()
    { return true; }

// ---- grease (Evocation), p. 51 ----
inline const char* uam1GreaseName()
    { return "Grease (Evocation)"; }

inline int uam1GreaseLevel()
    { return 1; }

// The casting time prints the clean 1 segment.
inline int uam1GreaseCastingTimeSegments()
    { return 1; }

// The range prints "7\"" - the family decodes 1 inch.
inline int uam1GreaseRangeInches()
    { return 1; }

inline bool uam1GreaseDurationPermanent()
    { return true; }

inline int uam1GreaseAoeSqFtPerLevel()
    { return 1; }

inline bool uam1GreaseSaveSpecial()
    { return true; }

// A creature stepping on the area must save versus
// petrification or slip, skid and fall; an aware creature
// can possibly avoid it.
inline bool uam1GreaseSaveVsPetrificationOrFall()
    { return true; }

inline bool uam1GreaseAwareCreatureCanAvoid()
    { return true; }

// The spell can coat a surface other than underfoot - a
// rope, ladder rungs, weapon handle.
inline bool uam1GreaseCoatsOtherSurfaces()
    { return true; }

// Lone material objects are always subject; an object
// wielded by a creature needs its failed save versus
// spell; a single save negates.
inline bool uam1GreaseLoneObjectsAlwaysSubject()
    { return true; }

inline bool uam1GreaseWieldedNeedsFailedSave()
    { return true; }

inline bool uam1GreaseSingleSaveNegates()
    { return true; }

// The material: a bit of pork rind, butter, or other
// greasy material.
inline bool uam1GreaseMaterialPorkRindEtc()
    { return true; }

// ---- precipitation (Alteration), p. 51 ----
inline const char* uam1PrecipName()
    { return "Precipitation (Alteration)"; }

inline int uam1PrecipLevel()
    { return 1; }

// The casting time prints "7 segment" - the family
// decodes 1 segment.
inline int uam1PrecipCastingTimeSegments()
    { return 1; }

inline int uam1PrecipDurationSegmentsPerLevel()
    { return 1; }

inline int uam1PrecipCylinderDiameterInches()
    { return 3; }

inline int uam1PrecipCylinderHeightInches()
    { return 12; }

inline bool uam1PrecipSaveNoneAndSpecial()
    { return true; }

// The MU stat block prints the components cell the
// clerical block lost: V, S, M.
inline bool uam1PrecipComponentsVSM()
    { return true; }

// The spell is identical to the 1st-level clerical spell
// of the same name, except that a holy symbol is not
// part of the material component.
inline bool uam1PrecipIdenticalToClericalMinusHolySymbol()
    { return true; }

inline bool uam1PrecipNoHolySymbolComponent()
    { return true; }

// ---- melt (Alteration), p. 51 ----
inline const char* uam1MeltName()
    { return "Melt (Alteration)"; }

inline int uam1MeltLevel()
    { return 1; }

// The melt/run blocks interleave; the melt range
// position-decodes as 3 inches from the run block (the
// run prose pins touch), with doubt pending the PDF.
inline int uam1MeltRangeInches()
    { return 3; }

inline bool uam1MeltRangeDecodedWithDoubt()
    { return true; }

// The components print "V. S, M" - the period decodes as
// a comma [sic].
inline bool uam1MeltComponentsPeriodGarble()
    { return true; }

// The area of effect prints "7 cu. yd. of ice or 2 cu.
// yds. of snow per level" - the family decodes 1 cubic
// yard of ice per level.
inline int uam1MeltAoeIceCuYdPerLevel()
    { return 1; }

inline int uam1MeltAoeSnowCuYdPerLevel()
    { return 2; }

// The warmth melts ice in 1 round - a 1st-level caster
// melts a 1-yard cube of ice to water.
inline int uam1MeltIceInRounds()
    { return 1; }

// Two cubic yards of snow turn to water in 1 round.
inline bool uam1MeltSnowToWaterOneRound()
    { return true; }

// Against cold-based creatures - white dragons, winter
// wolves, yeti, woolly rhinos, para-elemental and the
// like - the spell inflicts 2 points of damage per level,
// or 1 per level on a successful save versus spell.
inline bool uam1MeltAffectsColdCreatures()
    { return true; }

inline int uam1MeltDamagePerLevel()
    { return 2; }

inline int uam1MeltDamagePerLevelOnSave()
    { return 1; }

// The spell is generally ineffective against other types
// of creatures.
inline bool uam1MeltIneffectiveAgainstOthers()
    { return true; }

// The material: a few crystals or rock salt and a pinch
// of soot.
inline bool uam1MeltMaterialRockSalt()
    { return true; }

inline bool uam1MeltMaterialSootPinch()
    { return true; }

// ---- run (Enchantment), p. 51 ----
inline const char* uam1RunName()
    { return "Run (Enchantment)"; }

// The level cell prints the clean 1.
inline int uam1RunLevel()
    { return 1; }

// The range cell position-decodes as touch - the prose
// pins touched recipients.
inline bool uam1RunRangeTouch()
    { return true; }

inline int uam1RunDurationHoursMin()
    { return 5; }

inline int uam1RunDurationHoursMax()
    { return 8; }

inline bool uam1RunSaveNone()
    { return true; }

// The area of effect: special, humans and demi-humans
// only.
inline bool uam1RunAoeHumansDemiHumansOnly()
    { return true; }

// The recipient runs at full speed - twice normal - for
// the duration without tiring.
inline bool uam1RunTwiceNormalSpeed()
    { return true; }

// After running, the individual must rest a like number
// of hours, drinking plenty of liquids and eating
// heartily.
inline bool uam1RunLikeRestHours()
    { return true; }

// For every 2 levels of the caster, another individual
// can be affected.
inline int uam1RunExtraRecipientPer2Levels()
    { return 1; }

// Only humans and demi-humans in their natural forms
// are affected; barbarians with the running ability are
// immune.
inline bool uam1RunNaturalFormsOnly()
    { return true; }

inline bool uam1RunBarbariansImmune()
    { return true; }

// The material: an elixir of dried-plum juice boiled in
// spring water and the oil of 5-8 spurge [castor] beans.
inline bool uam1RunMaterialPlumElixir()
    { return true; }

inline int uam1RunMaterialCastorBeansMin()
    { return 5; }

inline int uam1RunMaterialCastorBeansMax()
    { return 8; }

// ---- taunt (Enchantment), p. 52 ----
inline const char* uam1TauntName()
    { return "Taunt (Enchantment)"; }

// The level cell prints the clean 1.
inline int uam1TauntLevel()
    { return 1; }

inline int uam1TauntRangeInches()
    { return 3; }

// The casting time prints "7 round" - the family decodes
// 1 round.
inline int uam1TauntCastingTimeRounds()
    { return 1; }

inline bool uam1TauntDurationInstantaneous()
    { return true; }

inline bool uam1TauntSaveNegates()
    { return true; }

// The area of effect: 2 levels or hit dice of creatures
// per level of the caster.
inline int uam1TauntAoeLevelsPerLevel()
    { return 2; }

// The opener interleaves: "an i caster to jape god ol"
// [sic] - the prose reassembles as enables the caster to
// jape and jeer at any creature.
inline bool uam1TauntOpenerGarbleDecoded()
    { return true; }

// The dweomer gives the words and sounds real meaning:
// challenging, insulting, causing irritation and anger.
inline bool uam1TauntChallengesAndInsults()
    { return true; }

// On a failed save the subjects rush forth in fury to do
// battle with the caster, attacking with body and
// hand-held weapons rather than from a distance.
inline bool uam1TauntRushForthInFury()
    { return true; }

inline bool uam1TauntAttackMeleePreferred()
    { return true; }

// Separation by an impenetrable or uncrossable boundary
// - a wall of flame, a deep chasm - breaks the spell.
inline bool uam1TauntBoundaryBreaksSpell()
    { return true; }

// Only one sort of creature is affected per casting -
// orcs or goblins, not both.
inline bool uam1TauntOneSortPerCasting()
    { return true; }

// The magic affects creatures closest to the caster
// first, regardless of maximum range.
inline bool uam1TauntNearestFirst()
    { return true; }

// Troops under a strong leader gain a save bonus of +1
// to +4 at the DM discretion.
inline int uam1TauntLeaderBonusMin()
    { return 1; }

inline int uam1TauntLeaderBonusMax()
    { return 4; }

// ---- wizard mark (Alteration), p. 52 ----
inline const char* uam1WizardMarkName()
    { return "Wizard Mark (Alteration)"; }

inline int uam1WizardMarkLevel()
    { return 1; }

// The casting time prints the clean 1 segment.
inline int uam1WizardMarkCastingTimeSegments()
    { return 1; }

inline bool uam1WizardMarkRangeTouch()
    { return true; }

inline bool uam1WizardMarkDurationPermanent()
    { return true; }

inline int uam1WizardMarkAoeSqFt()
    { return 1; }

inline bool uam1WizardMarkSaveNone()
    { return true; }

// The caster inscribes a personal rune or mark, visibly
// or invisibly, plus up to six smaller characters.
inline int uam1WizardMarkExtraCharacters()
    { return 6; }

// The rune etches upon stone, metal or any softer
// substance without harm to the material.
inline bool uam1WizardMarkEtchesStoneMetalSofter()
    { return true; }

// Detect magic causes an invisible mark to glow and be
// readable - not necessarily understandable.
inline bool uam1WizardMarkDetectMagicGlows()
    { return true; }

// Detect invisibility, true seeing, true sight, a gem
// of seeing, or a robe of eyes also notes it.
inline bool uam1WizardMarkDetectionSuiteReveals()
    { return true; }

// Read magic reveals the maker intent; erase wipes the
// surface clean.
inline bool uam1WizardMarkReadMagicRevealsIntent()
    { return true; }

inline bool uam1WizardMarkEraseWipes()
    { return true; }

// The material: a pinch of diamond dust, about 50 gp
// worth, and pigment or pigments; an invisible mark uses
// a stylus rather than the digit.
inline int uam1WizardMarkDiamondDustGp()
    { return 50; }

inline bool uam1WizardMarkMaterialPigments()
    { return true; }

inline bool uam1WizardMarkInvisibleUsesStylus()
    { return true; }

}   // namespace rules"""
    clean(HDR, 78)
    wr(US, HDR + NL)
    applied.append('uamuspells1.h: the pins')
s = rd(US)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 159, 'b inline count'
assert s.count('R356') == 1, 'b round tag'
assert s.count('uam1AlarmName()') == 1, 'b alarm fn'
assert s.count(
    'uam1WizardMarkInvisibleUsesStylus()'
    ) == 1, 'b stylus fn'
assert 'uastDruid' not in s, 'b no r341 ref'
assert 'uac1' not in s, 'b no r343 ref'
assert 'uad' not in s, 'b no druid ref'
assert len(applied) + len(already) == 2, 'b count'

# ---- (c) the gap report: the note (the
# item STAYS OPEN - the 2nd-9th levels) ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'R356: the 1st level pinned' in s:
    already.append('gap report: the note')
else:
    TAIL_OLD = NL.join([
        '      Mordenkainen disjunction, succor).',
        '- [ ] **The new illusionist spells**',
    ])
    assert s.count(TAIL_OLD) == 1, 'c tail'
    NOTE = NL.join([
        '      - R356: the 1st level pinned',
        '        (rules/uamuspells1.h) - the',
        '        ten spell descriptions',
        '        (alarm with the lost range',
        '        and door-value cells, armor,',
        '        firewater, grease, melt',
        '        behind the run interleave,',
        '        mount with the level ladder,',
        '        precipitation seam-checking',
        '        the R343 clerical pin minus',
        '        the holy symbol, run, taunt',
        '        behind the scrambled opener,',
        '        wizard mark); the family',
        '        decodes the seven level-cell',
        '        and casting-time 7s as 1',
        '        (mount, run and taunt print',
        '        the clean 1); the R341',
        '        tables pin only cantrip',
        '        ranges - no 1st-level MU',
        '        table seam exists; the 2nd',
        '        through 9th levels stay',
        '        open.',
    ])
    clean(NOTE, 57)
    s = s.replace(TAIL_OLD, NL.join([
        '      Mordenkainen disjunction, succor).',
        NOTE,
        '- [ ] **The new illusionist spells**',
    ]))
    wr(GP, s)
    applied.append('gap report: the note')
s = rd(GP)
assert s.count('R356: the 1st level pinned') == 1, 'c note'
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
if 'R356 UA MU 1st level spells pin audit' in s:
    already.append('regtest.cpp: the R356 audit')
else:
    INC_ANCH = (
        '#include "rules/uadruidspells7.h"'
        '  // R355: the UA new druid 7th'
        ' level')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uamuspells1.h"'
        '  // R356: the UA new magic-user'
        ' 1st level',
    ])
    AUD_ANCH = ('    // ---- R227: the wis mental'
                ' save wiring audit ----')
    AUDIT = r"""    // ---- R356: the UA new magic-user 1st level spells pin audit ----
    // The UA NEW MAGIC-USER SPELLS (p. 51),
    // the 1st level - alarm (the lost
    // range cell and the door-value
    // hole), armor, firewater, grease,
    // melt (the run interleave), mount
    // (the level ladder), precipitation
    // (the clerical seam minus the holy
    // symbol), run, taunt (the scrambled
    // opener) and wizard mark. The
    // family decodes the 7s as 1. The
    // item stays open (the 2nd-9th
    // levels).
    {
        using namespace rules;
        int bad = 0;
        // U1: alarm
        {
            if (strcmp(uam1AlarmName(),
                "Alarm (Evocation)") != 0) ++bad;
            // the 7 level-cell family decode
            if (uam1AlarmLevel() != 1) ++bad;
            if (!uam1AlarmLevelGarbleDecoded()) ++bad;
            // the lost range cell
            if (!uam1AlarmRangeCellLost()) ++bad;
            if (uam1AlarmDurationTurnsMin() != 2) ++bad;
            if (uam1AlarmDurationTurnsMax() != 8) ++bad;
            if (uam1AlarmDurationTurnsPerLevel() != 1)
                ++bad;
            if (uam1AlarmAoeSqFtPerLevel() != 20) ++bad;
            if (!uam1AlarmComponentsCellScrambled())
                ++bad;
            if (uam1AlarmCastingTimeRounds() != 1) ++bad;
            if (!uam1AlarmSaveNone()) ++bad;
            // the rat-size trigger gate
            if (!uam1AlarmTriggerLargerThanRat()) ++bad;
            if (uam1AlarmTriggerVolumeHalfCuFt() != 1)
                ++bad;
            if (uam1AlarmTriggerWeightPounds() != 3)
                ++bad;
            if (!uam1AlarmPortalFloorStairsArea()) ++bad;
            // the 60 inch radius
            if (uam1AlarmRadiusInches() != 60) ++bad;
            if (!uam1AlarmDoorValueLost()) ++bad;
            if (uam1AlarmWallReductionDegrees() != 20)
                ++bad;
            if (uam1AlarmSoundSegments() != 1) ++bad;
            // the trigger matrix
            if (!uam1AlarmUndeadNeverTrigger()) ++bad;
            if (!uam1AlarmInvisibleAndPlanarTrigger())
                ++bad;
            if (!uam1AlarmFlyingLevitatingTrigger())
                ++bad;
            // the bell and the silver wire
            if (!uam1AlarmMaterialTinyBell()) ++bad;
            if (!uam1AlarmMaterialFineSilverWire()) ++bad;
        }
        // U2: armor
        {
            if (strcmp(uam1ArmorName(),
                "Armor (Conjuration)") != 0) ++bad;
            if (uam1ArmorLevel() != 1) ++bad;
            if (!uam1ArmorRangeTouch()) ++bad;
            if (!uam1ArmorDurationSpecial()) ++bad;
            if (!uam1ArmorAoeOneCreature()) ++bad;
            if (!uam1ArmorSaveNone()) ++bad;
            // the AC 8 force field
            if (!uam1ArmorCreatesForceFieldAc8()) ++bad;
            if (!uam1ArmorNoEffectIfAlreadyArmored())
                ++bad;
            if (!uam1ArmorBetterThanNineGainsOneStep())
                ++bad;
            if (!uam1ArmorNoWeightOrEncumbrance()) ++bad;
            if (!uam1ArmorDoesNotPreventCasting()) ++bad;
            // the cumulative-damage gate
            if (uam1ArmorDamageThresholdBase() != 8)
                ++bad;
            if (uam1ArmorDamageThresholdPerLevel() != 1)
                ++bad;
            if (uam1ArmorExampleCasterLevelForExceed()
                != 2) ++bad;
            if (!uam1ArmorNoteWordsLost()) ++bad;
            if (!uam1ArmorMaterialBlessedLeather())
                ++bad;
        }
        // U3: mount
        {
            if (strcmp(uam1MountName(),
                "Mount (Conjuration/Summoning)")
                != 0) ++bad;
            // the clean 1 level cell
            if (uam1MountLevel() != 1) ++bad;
            if (uam1MountCastingTimeRounds() != 1) ++bad;
            if (uam1MountDurationTurnsBase() != 12)
                ++bad;
            if (uam1MountDurationTurnsPerLevel() != 6)
                ++bad;
            if (!uam1MountAoeOneCreature()) ++bad;
            if (!uam1MountSaveNone()) ++bad;
            if (!uam1MountServesThenReturns()) ++bad;
            // the mount ladder
            if (uam1MountMuleLightHorseMaxLevel() != 3)
                ++bad;
            if (uam1MountDraftWarhorseMinLevel() != 4)
                ++bad;
            if (uam1MountDraftWarhorseMaxLevel() != 7)
                ++bad;
            if (uam1MountCamelMinLevel() != 8) ++bad;
            if (uam1MountCamelMaxLevel() != 12) ++bad;
            if (uam1MountElephantMinLevel() != 13)
                ++bad;
            if (uam1MountHoudaAtLevel() != 18) ++bad;
            if (!uam1MountLowerLevelChoiceAllowed())
                ++bad;
            if (!uam1MountNoRidingGearUnlessLowerClass())
                ++bad;
            if (!uam1MountStatsTypicalOfClass()) ++bad;
            if (!uam1MountMaterialHairOrDung()) ++bad;
        }
        // U4: firewater
        {
            if (strcmp(uam1FirewaterName(),
                "Firewater (Alteration)") != 0) ++bad;
            if (uam1FirewaterLevel() != 1) ++bad;
            // the clean 1 segment
            if (uam1FirewaterCastingTimeSegments() != 1)
                ++bad;
            if (!uam1FirewaterRangeCellLost()) ++bad;
            if (!uam1FirewaterSaveNone()) ++bad;
            if (!uam1FirewaterVolatileAlcoholLike())
                ++bad;
            if (!uam1FirewaterLighterThanWater()) ++bad;
            if (!uam1FirewaterIgnitesOnSpark()) ++bad;
            if (uam1FirewaterDamageMin() != 2) ++bad;
            if (uam1FirewaterDamageMax() != 12) ++bad;
            // the evaporation clock
            if (uam1FirewaterEvaporatesInRounds() != 1)
                ++bad;
            if (uam1FirewaterIgniteWithinSegments()
                != 10) ++bad;
            if (!uam1FirewaterMaterialSugarGrains())
                ++bad;
            if (!uam1FirewaterMaterialRaisin()) ++bad;
        }
        // U5: grease
        {
            if (strcmp(uam1GreaseName(),
                "Grease (Evocation)") != 0) ++bad;
            if (uam1GreaseLevel() != 1) ++bad;
            if (uam1GreaseCastingTimeSegments() != 1)
                ++bad;
            // the "7"" range family decode
            if (uam1GreaseRangeInches() != 1) ++bad;
            if (!uam1GreaseDurationPermanent()) ++bad;
            if (uam1GreaseAoeSqFtPerLevel() != 1) ++bad;
            if (!uam1GreaseSaveSpecial()) ++bad;
            if (!uam1GreaseSaveVsPetrificationOrFall())
                ++bad;
            if (!uam1GreaseAwareCreatureCanAvoid()) ++bad;
            if (!uam1GreaseCoatsOtherSurfaces()) ++bad;
            if (!uam1GreaseLoneObjectsAlwaysSubject())
                ++bad;
            if (!uam1GreaseWieldedNeedsFailedSave())
                ++bad;
            if (!uam1GreaseSingleSaveNegates()) ++bad;
            if (!uam1GreaseMaterialPorkRindEtc()) ++bad;
        }
        // U6: precipitation - the clerical seam
        {
            if (strcmp(uam1PrecipName(),
                "Precipitation (Alteration)") != 0)
                ++bad;
            if (uam1PrecipLevel() != 1) ++bad;
            if (uam1PrecipCastingTimeSegments() != 1)
                ++bad;
            if (uam1PrecipDurationSegmentsPerLevel()
                != 1) ++bad;
            if (uam1PrecipCylinderDiameterInches() != 3)
                ++bad;
            if (uam1PrecipCylinderHeightInches() != 12)
                ++bad;
            if (!uam1PrecipSaveNoneAndSpecial()) ++bad;
            // the components cell the clerical
            // block lost
            if (!uam1PrecipComponentsVSM()) ++bad;
            if (!uam1PrecipIdenticalToClericalMinusHolySymbol())
                ++bad;
            if (!uam1PrecipNoHolySymbolComponent()) ++bad;
            // the R343 clerical seam, cell by cell
            if (uam1PrecipDurationSegmentsPerLevel()
                != uac1PrecipDurationSegmentsPerLevel())
                ++bad;
            if (uam1PrecipCylinderDiameterInches()
                != uac1PrecipCylinderDiameterInches())
                ++bad;
            if (uam1PrecipCylinderHeightInches()
                != uac1PrecipCylinderHeightInches())
                ++bad;
        }
        // U7: melt
        {
            if (strcmp(uam1MeltName(),
                "Melt (Alteration)") != 0) ++bad;
            if (uam1MeltLevel() != 1) ++bad;
            // the run-interleave range doubt
            if (uam1MeltRangeInches() != 3) ++bad;
            if (!uam1MeltRangeDecodedWithDoubt()) ++bad;
            if (!uam1MeltComponentsPeriodGarble()) ++bad;
            // the 7 cu yd family decode
            if (uam1MeltAoeIceCuYdPerLevel() != 1) ++bad;
            if (uam1MeltAoeSnowCuYdPerLevel() != 2)
                ++bad;
            if (uam1MeltIceInRounds() != 1) ++bad;
            if (!uam1MeltSnowToWaterOneRound()) ++bad;
            if (!uam1MeltAffectsColdCreatures()) ++bad;
            if (uam1MeltDamagePerLevel() != 2) ++bad;
            if (uam1MeltDamagePerLevelOnSave() != 1)
                ++bad;
            if (!uam1MeltIneffectiveAgainstOthers()) ++bad;
            if (!uam1MeltMaterialRockSalt()) ++bad;
            if (!uam1MeltMaterialSootPinch()) ++bad;
        }
        // U8: run
        {
            if (strcmp(uam1RunName(),
                "Run (Enchantment)") != 0) ++bad;
            // the clean 1 level cell
            if (uam1RunLevel() != 1) ++bad;
            if (!uam1RunRangeTouch()) ++bad;
            if (uam1RunDurationHoursMin() != 5) ++bad;
            if (uam1RunDurationHoursMax() != 8) ++bad;
            if (!uam1RunSaveNone()) ++bad;
            if (!uam1RunAoeHumansDemiHumansOnly()) ++bad;
            if (!uam1RunTwiceNormalSpeed()) ++bad;
            if (!uam1RunLikeRestHours()) ++bad;
            if (uam1RunExtraRecipientPer2Levels() != 1)
                ++bad;
            if (!uam1RunNaturalFormsOnly()) ++bad;
            if (!uam1RunBarbariansImmune()) ++bad;
            // the elixir
            if (!uam1RunMaterialPlumElixir()) ++bad;
            if (uam1RunMaterialCastorBeansMin() != 5)
                ++bad;
            if (uam1RunMaterialCastorBeansMax() != 8)
                ++bad;
        }
        // U9: taunt
        {
            if (strcmp(uam1TauntName(),
                "Taunt (Enchantment)") != 0) ++bad;
            // the clean 1 level cell
            if (uam1TauntLevel() != 1) ++bad;
            if (uam1TauntRangeInches() != 3) ++bad;
            if (uam1TauntCastingTimeRounds() != 1) ++bad;
            if (!uam1TauntDurationInstantaneous()) ++bad;
            if (!uam1TauntSaveNegates()) ++bad;
            if (uam1TauntAoeLevelsPerLevel() != 2) ++bad;
            // the scrambled opener
            if (!uam1TauntOpenerGarbleDecoded()) ++bad;
            if (!uam1TauntChallengesAndInsults()) ++bad;
            if (!uam1TauntRushForthInFury()) ++bad;
            if (!uam1TauntAttackMeleePreferred()) ++bad;
            if (!uam1TauntBoundaryBreaksSpell()) ++bad;
            if (!uam1TauntOneSortPerCasting()) ++bad;
            if (!uam1TauntNearestFirst()) ++bad;
            if (uam1TauntLeaderBonusMin() != 1) ++bad;
            if (uam1TauntLeaderBonusMax() != 4) ++bad;
        }
        // U10: wizard mark
        {
            if (strcmp(uam1WizardMarkName(),
                "Wizard Mark (Alteration)") != 0) ++bad;
            if (uam1WizardMarkLevel() != 1) ++bad;
            // the clean 1 segment
            if (uam1WizardMarkCastingTimeSegments() != 1)
                ++bad;
            if (!uam1WizardMarkRangeTouch()) ++bad;
            if (!uam1WizardMarkDurationPermanent()) ++bad;
            if (uam1WizardMarkAoeSqFt() != 1) ++bad;
            if (!uam1WizardMarkSaveNone()) ++bad;
            if (uam1WizardMarkExtraCharacters() != 6)
                ++bad;
            if (!uam1WizardMarkEtchesStoneMetalSofter())
                ++bad;
            if (!uam1WizardMarkDetectMagicGlows()) ++bad;
            if (!uam1WizardMarkDetectionSuiteReveals())
                ++bad;
            if (!uam1WizardMarkReadMagicRevealsIntent())
                ++bad;
            if (!uam1WizardMarkEraseWipes()) ++bad;
            // the diamond dust and pigments
            if (uam1WizardMarkDiamondDustGp() != 50)
                ++bad;
            if (!uam1WizardMarkMaterialPigments()) ++bad;
            if (!uam1WizardMarkInvisibleUsesStylus())
                ++bad;
        }
        printf("R356 UA MU 1st level spells pin audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R356 audit')
s = rd(RT)
assert s.count(
    'R356 UA MU 1st level spells pin audit'
    ': bad ') == 1, 'd audit line'
assert s.count('audit: bad ') == 283, 'd census 283'
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
    '#include "rules/uamuspells1.h"') == 1, 'd include'
assert len(applied) + len(already) == 4, 'd count'

# ---- the summary ----
print('R356 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R356 note: the UA new magic-user')
print('spells pin round, the 1st level -')
print('the ten spell descriptions (alarm')
print('with the lost range and door-value')
print('cells, armor, firewater, grease,')
print('melt behind the run interleave,')
print('mount with the level ladder,')
print('precipitation seam-checking the')
print('R343 clerical pin minus the holy')
print('symbol, run, taunt behind the')
print('scrambled opener, wizard mark);')
print('the family decodes the seven 7s')
print('as 1; no 1st-level MU table seam')
print('exists; the item stays open (the')
print('2nd-9th levels); the census')
print('282 -> 283')
print('commit: R356: the UA new magic-user')
print('1st level spells pin round')
print('(census 283)')

