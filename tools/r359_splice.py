#!/usr/bin/env python3
# R359: the UA NEW MAGIC-USER
# SPELLS pin round, the 4th level
# (pp. 51-66) - dispel illusion
# behind the lost name tail, the
# Evard black tentacles behind
# the lost level and range
# cells, the Leomund secure
# shelter, magic mirror, the
# Otiluke resilient sphere,
# shout, stoneskin behind the
# lost level and range cells,
# ultravision. The digit-garble
# family decodes the 7s as 1.
# The R342 table seam pins 7 of
# 8 names. The item stays open
# (the 5th-9th levels).
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

# ---- (a) the seed: the R357 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R358 landed 2026-10-11: commit',
    '  8db9ec7, census 285, the UA',
    '  new magic-user 3rd level spells',
    '  pin round (rules/uamuspells3.h):',
    '  the eight spell descriptions',
    '  (cloudburst seam-checking the',
    '  R352 druid pin minus the holy',
    '  symbol with the 3 diam. print',
    '  flagged against the druid 4,',
    '  detect illusion behind the lost',
    '  name tail, item, material',
    '  behind the degree range, the',
    '  Melf minute meteors, secret',
    '  page behind the 4th-heading',
    '  interleave, the sepia snake',
    '  sigil, wind wall); the family',
    '  decodes the 7s as 1; the R342',
    '  MU table seam prints four of',
    '  the eight names, the four',
    '  absent noted. GREEN on the',
    '  first run.',
])
s = rd(SD)
if 'R358 landed 2026-10-11' in s:
    already.append('seed: the R358 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R358 record')
s = rd(SD)
assert s.count('R358 landed 2026-10-11') == 1, 'a entry'
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

# ---- (b) NEW rules/uamuspells1.h ----
US = 'rules/uamuspells4.h'
if os.path.exists(US) and 'R359' in rd(US):
    already.append('uamuspells4.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uamuspells4.h
// The UA NEW MAGIC-USER SPELLS (pp. 51-66) pins, R359: the
// 4th-level spell descriptions - dispel illusion, the
// Evard black tentacles, the Leomund secure shelter,
// magic mirror, the Otiluke resilient sphere, shout,
// stoneskin and ultravision.
//
// Pin-era pattern (R322): pinned data only - no engine site
// exists.
//
// JUDGMENTs (the decode method):
//   - the digit-garble family (the R343 precedent): the
//     casting-time and duration 7s decode as 1 - the
//     magic mirror "7 hour" as 1 hour and "7 round/level"
//     as 1 round per level; the shout and stoneskin
//     "7 segment" casting times as 1 segment.
//   - the dispel illusion header loses its tail - only
//     "Dispel (Abjuration)" prints; the name pins from
//     the prose (dispel an illusion). Its stat block
//     interleaves with secret page (R358-pinned) - the
//     dispel cells pin as level 4, V S, 4 segments, half
//     inch per level (the fraction cell prints garbled),
//     permanent, none, special.
//   - the Evard tentacles stat block prints a stray "gf"
//     after the components and loses both the level and
//     the range cells - the level pins from the section
//     heading, the range is a hole pending the PDF.
//   - the Leomund secure shelter prose scrambles the
//     wind and strength sentences; the cells pin clean.
//   - the magic mirror prose scrambles the component
//     list (the hawk, eagle or roc eye; zinc, copper
//     and nitric acid) and the spell-through list; the
//     cells pin, the lists pin from the fragments.
//   - the Otiluke sphere prose head is scrambled - the
//     globe sentence is lost; the effect pins from the
//     surviving tail.
//   - the shout area cell prints 1 inch with the tail
//     scrambled ("x 3 cone"); the prose pins the cone
//     radiating from the mouth to a 3 inch terminus.
//   - the stoneskin stat block loses the level and range
//     cells (the level pins from the section heading; the
//     range is a hole pending the PDF) and prints its
//     components, casting time, save and area after the
//     prose - an interleave.
//   - the ultravision prose tail (the 3-foot radius
//     sentence and the amethyst) prints past the 5th
//     level heading; the cells pin clean.
//   - the region also carries the R358-pinned secret
//     page and sepia snake sigil bodies; their pins
//     live in rules/uamuspells3.h.
//
// ===========================================================================

namespace rules {

// ---- dispel illusion (Abjuration), the 4th level ----
// The header loses its tail - "Dispel (Abjuration)" only;
// the name pins from the prose.
inline const char* uam4DispelName()
    { return "Dispel Illusion (Abjuration)"; }

inline bool uam4DispelNameHeaderTailLost()
    { return true; }

inline int uam4DispelLevel()
    { return 4; }

// The stat block interleaves with secret page (R358).
inline bool uam4DispelStatInterleavedWithSecretPage()
    { return true; }

inline bool uam4DispelComponentsVS()
    { return true; }

inline int uam4DispelCastingTimeSegments()
    { return 4; }

// The range cell prints a garbled half fraction per
// level - decoded as half an inch per level.
inline int uam4DispelRangeHalfInchesPerLevel()
    { return 1; }

inline bool uam4DispelRangeFractionGarbled()
    { return true; }

inline bool uam4DispelDurationPermanent()
    { return true; }

inline bool uam4DispelSaveNone()
    { return true; }

inline bool uam4DispelAoeSpecial()
    { return true; }

// The spell is similar to the 3rd-level illusionist spell
// of the same name; no illusionist seam exists yet.
inline bool uam4DispelSameAsIllusionist3rd()
    { return true; }

// A magic-user attempting to dispel an illusion is
// considered at two levels below his actual level with
// respect to spells cast by an illusionist.
inline int uam4DispelLevelPenaltyVsIllusionist()
    { return 2; }

// ---- the Evard black tentacles (Conjuration/Summoning) ----
inline const char* uam4EvardName()
    { return "Evard's Black Tentacles (Conjuration/Summoning)"; }

inline int uam4EvardLevel()
    { return 4; }

// The level and range cells are lost; the level pins from
// the section heading, the range is a hole pending the
// PDF.
inline bool uam4EvardLevelCellLost()
    { return true; }

inline bool uam4EvardRangeCellLost()
    { return true; }

// A stray "gf" prints after the components line.
inline bool uam4EvardStrayGfLine()
    { return true; }

inline bool uam4EvardComponentsVSM()
    { return true; }

inline int uam4EvardCastingTimeSegments()
    { return 8; }

inline bool uam4EvardSaveNone()
    { return true; }

inline int uam4EvardDurationRoundsPerLevel()
    { return 1; }

inline int uam4EvardAoeSqFtPerLevel()
    { return 30; }

// Many rubbery, black tentacles spring forth from the
// earth, floor or whatever surface is underfoot -
// including water.
inline bool uam4EvardSpringsFromAnySurface()
    { return true; }

// Each tentacle is 10 feet long (the degree family),
// AC 4, and takes as many points of damage to destroy
// as the caster has levels of experience.
inline int uam4EvardTentacleFeet()
    { return 10; }

inline int uam4EvardTentacleAc()
    { return 4; }

inline bool uam4EvardTentacleHpPerCasterLevel()
    { return true; }

// One tentacle for each of the caster's levels.
inline bool uam4EvardOneTentaclePerLevel()
    { return true; }

// Any creature within range is subject to attack; with
// more than one target in range, the probability is
// determined by die roll.
inline bool uam4EvardMultiTargetDieRoll()
    { return true; }

// Save success: 1-4 damage from initial contact and the
// tentacle is destroyed. Failure: 2-8 damage, the member
// wraps its victim, and 3-12 points on the second and
// succeeding rounds.
inline int uam4EvardDamageOnSaveMin()
    { return 1; }

inline int uam4EvardDamageOnSaveMax()
    { return 4; }

inline int uam4EvardDamageOnFailMin()
    { return 2; }

inline int uam4EvardDamageOnFailMax()
    { return 8; }

inline int uam4EvardDamageWrappedMin()
    { return 3; }

inline int uam4EvardDamageWrappedMax()
    { return 12; }

// With no intelligence to guide them, the tentacles may
// entwine any object - a tree, post, pillar - or
// continue to squeeze a dead opponent.
inline bool uam4EvardMayEntwineObjects()
    { return true; }

inline bool uam4EvardContinuesSqueezingDead()
    { return true; }

// The component (printing in the sepia interleave): a
// piece of tentacle from a giant octopus or giant squid.
inline bool uam4EvardMaterialOctopusOrSquidTentacle()
    { return true; }

// ---- the Leomund secure shelter (Alteration/Enchantment) ----
inline const char* uam4ShelterName()
    { return "Leomund's Secure Shelter (Alteration - Enchantment)"; }

inline int uam4ShelterLevel()
    { return 4; }

inline bool uam4ShelterComponentsVSM()
    { return true; }

inline int uam4ShelterCastingTimeTurns()
    { return 4; }

inline int uam4ShelterRangeInches()
    { return 2; }

inline bool uam4ShelterSaveNone()
    { return true; }

inline int uam4ShelterDurationTurnsPerLevel()
    { return 6; }

inline int uam4ShelterAoeSqFtPerLevel()
    { return 30; }

// The spell magically calls into being a sturdy cottage
// or lodge of material common in the area - stone,
// timber, or (at worst) sod.
inline bool uam4ShelterCottageOfLocalMaterial()
    { return true; }

// The floor area is 30 square feet per level, level,
// clean and dry; a sturdy door, two or more shuttered
// windows, and a small fireplace.
inline bool uam4ShelterFloorLevelCleanDry()
    { return true; }

inline bool uam4ShelterDoorWindowsFireplace()
    { return true; }

// The scrambled prose: the lodging is secure against
// winds of up to natural 70 miles per hour.
inline int uam4ShelterWindResistanceMph()
    { return 70; }

inline bool uam4ShelterWindSentenceScrambled()
    { return true; }

// The lodging has no heating qualities - it must be
// heated as a normal dwelling, and extreme heat will
// affect it and its occupants adversely.
inline bool uam4ShelterNoHeatingQualities()
    { return true; }

// It is as strong as a normal stone building regardless
// of material, resists flames and fire as if stone, and
// is impervious to normal missiles (but not siege
// machinery or giants).
inline bool uam4ShelterStrongAsStone()
    { return true; }

inline bool uam4ShelterResistsFlamesAsStone()
    { return true; }

inline bool uam4ShelterImperviousToNormalMissiles()
    { return true; }

// The door and shutters are wizard locked; the chimney is
// secured by a top grate of iron and a narrow flue; the
// three areas are protected by an alarm spell.
inline bool uam4ShelterDoorShuttersWizardLocked()
    { return true; }

inline bool uam4ShelterChimneyGrateAndFlue()
    { return true; }

inline bool uam4ShelterAlarmProtected()
    { return true; }

// An unseen servant is called up to serve the caster.
inline bool uam4ShelterUnseenServant()
    { return true; }

// Crude furnishings as desired: up to 8 bunks, a trestle
// table and benches, as many as 4 chairs or 8 stools,
// and a writing desk.
inline int uam4ShelterBunksMax()
    { return 8; }

inline int uam4ShelterChairsMax()
    { return 4; }

inline int uam4ShelterStoolsMax()
    { return 8; }

inline bool uam4ShelterTrestleTableAndDesk()
    { return true; }

// The materials: a square chip of stone, crushed lime, a
// few grains of sand, a sprinkling of water, and several
// splinters of wood.
inline bool uam4ShelterMaterialStoneLimeSandWaterWood()
    { return true; }

// Augmented by the alarm and unseen servant components
// if included: string, silver wire, and a small bell.
inline bool uam4ShelterMaterialAugmentedByAlarmServant()
    { return true; }

// ---- magic mirror (Enchantment/Divination), the 4th ----
inline const char* uam4MirrorName()
    { return "Magic Mirror (Enchantment - Divination)"; }

inline int uam4MirrorLevel()
    { return 4; }

inline bool uam4MirrorComponentsVSM()
    { return true; }

// The casting time prints "7 hour" - the family decodes
// 1 hour.
inline int uam4MirrorCastingTimeHours()
    { return 1; }

inline bool uam4MirrorRangeTouch()
    { return true; }

inline bool uam4MirrorSaveNone()
    { return true; }

inline int uam4MirrorDurationRoundsPerLevel()
    { return 1; }

inline bool uam4MirrorAoeSpecial()
    { return true; }

// The spell changes a normal mirror into a scrying
// device similar to a crystal ball (the details on
// p. 141 of the DMG).
inline bool uam4MirrorMirrorBecomesScryingDevice()
    { return true; }

// The mirror must be finely wrought, highly polished
// silver of a minimum cost of 1,000 gp; the mirror is
// not harmed by the casting - the other components are.
inline int uam4MirrorSilverCostGpMin()
    { return 1000; }

inline bool uam4MirrorNotHarmedByCasting()
    { return true; }

// The component list scrambles: the eye of a hawk, an
// eagle, or even a roc; zinc, copper, and nitric acid.
inline bool uam4MirrorMaterialEyeOfHawkEagleRoc()
    { return true; }

inline bool uam4MirrorMaterialZincCopperNitricAcid()
    { return true; }

inline bool uam4MirrorComponentListScrambled()
    { return true; }

// 2nd-level spells can be cast through a magic mirror:
// comprehend languages, tongues, infravision, and
// ultravision.
inline bool uam4MirrorCastsThroughComprehend()
    { return true; }

inline bool uam4MirrorCastsThroughTonguesInfravisionUltravision()
    { return true; }

// The following have a 5% chance per level of the caster
// of operating correctly: detect magic, detect
// good/evil, message, and detect illusion.
inline int uam4MirrorPctPerLevel()
    { return 5; }

inline bool uam4MirrorDetectSpellsByChance()
    { return true; }

// There is a chance of the target realizing he or she is
// being watched - the base chance per the crystal ball
// item description; a cavalier has a base 5% chance of
// detecting scrying, a barbarian a base 1% chance.
inline bool uam4MirrorTargetMayDetectScrying()
    { return true; }

inline int uam4MirrorCavalierDetectPct()
    { return 5; }

inline int uam4MirrorBarbarianDetectPct()
    { return 1; }

// ---- the Otiluke resilient sphere (Alteration/Evocation) ----
inline const char* uam4OtilukeName()
    { return "Otiluke's Resilient Sphere (Alteration - Evocation)"; }

inline int uam4OtilukeLevel()
    { return 4; }

inline bool uam4OtilukeComponentsVSM()
    { return true; }

inline int uam4OtilukeCastingTimeSegments()
    { return 4; }

inline int uam4OtilukeRangeInches()
    { return 2; }

inline bool uam4OtilukeSaveNeg()
    { return true; }

// The duration prints "7 round/level" - the family
// decodes 1 round per level.
inline int uam4OtilukeDurationRoundsPerLevel()
    { return 1; }

inline int uam4OtilukeSphereFeetPerLevel()
    { return 1; }

// The prose head scrambles - the globe sentence is lost;
// the subject is small enough to fit within the diameter
// of the sphere.
inline bool uam4OtilukeProseHeadScrambled()
    { return true; }

inline bool uam4OtilukeSubjectFitsWithin()
    { return true; }

// The sphere persists as long as its dweomer persists;
// the subject is not subject to damage of any sort
// except from a rod of cancellation, a wand of
// negation, or a disintegrate or dispel magic spell -
// which destroy it without harm to the subject.
inline bool uam4OtilukeNotDamagedNormally()
    { return true; }

inline bool uam4OtilukeDestroyedByNegationOrDispel()
    { return true; }

inline bool uam4OtilukeDestroyedWithoutHarm()
    { return true; }

// Nothing can pass through the sphere, inside or out,
// and the target can breathe normally.
inline bool uam4OtilukeNothingPassesThrough()
    { return true; }

inline bool uam4OtilukeSubjectBreathes()
    { return true; }

// The subject may struggle, but all that occurs is
// movement of the sphere; it can be physically moved
// from outside or by the struggles of those within.
inline bool uam4OtilukeStruggleMovesSphereOnly()
    { return true; }

inline bool uam4OtilukeMovableFromOutsideOrWithin()
    { return true; }

// The components: a hemispherical piece of diamond (or
// similar hard, clear gem material) and a matching
// hemispherical piece of gum arabic.
inline bool uam4OtilukeMaterialDiamondHemisphere()
    { return true; }

inline bool uam4OtilukeMaterialGumArabicHemisphere()
    { return true; }

// ---- shout (Evocation), the 4th level ----
inline const char* uam4ShoutName()
    { return "Shout (Evocation)"; }

inline int uam4ShoutLevel()
    { return 4; }

// The range cell prints 0.
inline bool uam4ShoutRangeZero()
    { return true; }

inline bool uam4ShoutDurationInstantaneous()
    { return true; }

// The area cell prints 1 inch with the tail scrambled
// ("x 3 cone"); the prose pins the cone radiating from
// the mouth to a 3 inch terminus.
inline int uam4ShoutAoeTerminusInches()
    { return 3; }

inline bool uam4ShoutAoeCellScrambled()
    { return true; }

inline bool uam4ShoutConeFromTheMouth()
    { return true; }

// The components cell prints V, M after the prose - an
// interleave.
inline bool uam4ShoutComponentsVM()
    { return true; }

inline bool uam4ShoutStatTailInterleaved()
    { return true; }

// The casting time prints "7 segment" - the family
// decodes 1 segment.
inline int uam4ShoutCastingTimeSegments()
    { return 1; }

inline bool uam4ShoutSaveNeg()
    { return true; }

// The caster releases an ear-splitting noise; any
// creature in the cone is deafened for 2-12 rounds and
// takes a like 2-12 points of damage unless a save is
// made.
inline int uam4ShoutDeafenRoundsMin()
    { return 2; }

inline int uam4ShoutDeafenRoundsMax()
    { return 12; }

inline int uam4ShoutDamageMin()
    { return 2; }

inline int uam4ShoutDamageMax()
    { return 12; }

// Exposed brittle or similar substance subject to sonic
// vibrations shatters - e.g. a wall of ice.
inline bool uam4ShoutShattersBrittleSubstances()
    { return true; }

inline bool uam4ShoutWallOfIceExample()
    { return true; }

// Usable but once per day, else the caster might
// permanently deafen himself or herself.
inline bool uam4ShoutOncePerDay()
    { return true; }

// The materials: a drop of honey, a drop of citric
// acid, and a small cone made from a bull's or ram's
// horn.
inline bool uam4ShoutMaterialHoneyAcidHornCone()
    { return true; }

// ---- stoneskin (Alteration), the 4th level ----
inline const char* uam4StoneskinName()
    { return "Stoneskin (Alteration)"; }

// The stat block loses the level and range cells; the
// level pins from the section heading, the range is a
// hole pending the PDF.
inline int uam4StoneskinLevel()
    { return 4; }

inline bool uam4StoneskinLevelCellLost()
    { return true; }

inline bool uam4StoneskinRangeCellLost()
    { return true; }

// The components, casting time, save and area print
// after the prose - an interleave.
inline bool uam4StoneskinStatTailInterleaved()
    { return true; }

inline bool uam4StoneskinComponentsVSM()
    { return true; }

inline int uam4StoneskinCastingTimeSegments()
    { return 1; }

inline bool uam4StoneskinDurationSpecial()
    { return true; }

inline bool uam4StoneskinSaveNone()
    { return true; }

inline bool uam4StoneskinAoeOneCreature()
    { return true; }

// The affected creature gains virtual immunity to any
// attack by cut, blow, projectile or the like - even a
// sword of sharpness, a giant-hurled rock, a snake's
// strike.
inline bool uam4StoneskinImmuneToPhysicalAttacks()
    { return true; }

inline bool uam4StoneskinSwordOfSharpnessIneffective()
    { return true; }

// Magic attacks - fireball, magic missile, lightning
// bolt, and so forth - have normal effect.
inline bool uam4StoneskinMagicAttacksNormal()
    { return true; }

// Any attack or attack sequence from a single opponent
// dispels the dweomer, although it makes the creature
// immune to that single attack or sequence.
inline bool uam4StoneskinOneOpponentDispels()
    { return true; }

inline bool uam4StoneskinImmuneToThatAttack()
    { return true; }

// Relatively soft weapons - a monk's hands, an
// ogrillon's fist - inflict 1-2 points on the attacker
// per attack and do not dispel the dweomer.
inline int uam4StoneskinSoftWeaponDamageMin()
    { return 1; }

inline int uam4StoneskinSoftWeaponDamageMax()
    { return 2; }

inline bool uam4StoneskinSoftWeaponsDoNotDispels()
    { return true; }

// The materials: granite and diamond dust sprinkled on
// the recipient's skin.
inline bool uam4StoneskinMaterialGraniteDiamondDust()
    { return true; }

// ---- ultravision (Alteration), the 4th level ----
inline const char* uam4UltravisionName()
    { return "Ultravision (Alteration)"; }

inline int uam4UltravisionLevel()
    { return 4; }

inline bool uam4UltravisionComponentsVSM()
    { return true; }

inline bool uam4UltravisionRangeTouch()
    { return true; }

inline int uam4UltravisionCastingTimeSegments()
    { return 4; }

inline bool uam4UltravisionSaveNone()
    { return true; }

inline int uam4UltravisionDurationTurnsMin()
    { return 6; }

inline int uam4UltravisionDurationTurnsPerLevel()
    { return 6; }

inline bool uam4UltravisionAoeOneCreature()
    { return true; }

// The recipient sees radiation in the ultraviolet
// spectrum.
inline bool uam4UltravisionSeesUltraviolet()
    { return true; }

// In night conditions vision is clear, as if daylight,
// to 100 yards, and shadowy and indistinct from beyond
// 100 yards to about 300 yards.
inline int uam4UltravisionClearYards()
    { return 100; }

inline int uam4UltravisionShadowyYards()
    { return 300; }

// A very dark night with thick clouds overhead reduces
// ultravisual sight by 50%.
inline int uam4UltravisionDarkNightReductionPct()
    { return 50; }

// Where more than about 6 feet of earth or 3 feet of
// stone interpose between the sky and the individual -
// virtually any underground area - only vision of the
// dimmest sort in about a 3-foot radius, the rays
// screened out.
inline int uam4UltravisionEarthFeet()
    { return 6; }

inline int uam4UltravisionStoneFeet()
    { return 3; }

inline int uam4UltravisionUndergroundRadiusFeet()
    { return 3; }

inline bool uam4UltravisionUndergroundDimOnly()
    { return true; }

// An emission source nearby improves the visual
// capabilities accordingly.
inline bool uam4UltravisionEmissionSourceImproves()
    { return true; }

// Nearby light, including the radiance shed by magic
// items, spoils ultravision - the brightness blinding
// the eyes to dimmer, more distant areas.
inline bool uam4UltravisionNearbyLightSpoils()
    { return true; }

// The material: a crushed amethyst of at least 500 gp
// value.
inline int uam4UltravisionMaterialAmethystGp()
    { return 500; }

// The prose tail (the 3-foot radius sentence and the
// amethyst) prints past the 5th level heading.
inline bool uam4UltravisionTailPastFifthHeading()
    { return true; }

}   // namespace rules"""
    clean(HDR, 78)
    wr(US, HDR + NL)
    applied.append('uamuspells4.h: the pins')
s = rd(US)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 164, 'b inline count'
assert s.count('R359') == 1, 'b round tag'
assert s.count('uam4DispelName()') == 1, 'b dispel fn'
assert s.count(
    'uam4UltravisionMaterialAmethystGp()'
    ) == 1, 'b amethyst fn'
assert 'uastDruid' not in s, 'b no r341 ref'
assert 'uam3' not in s, 'b no r358 ref'
assert 'uam2' not in s, 'b no r357 ref'
assert 'uam1' not in s, 'b no r356 ref'
assert 'uac1' not in s, 'b no r343 ref'
assert 'uad3' not in s, 'b no druid ref'
assert 'uas2' not in s, 'b no r342 ref'
assert len(applied) + len(already) == 2, 'b count'

# ---- (c) the gap report: the note (the
# item STAYS OPEN - the 5th-9th levels) ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'R359: the 4th level pinned' in s:
    already.append('gap report: the note')
else:
    TAIL_OLD = NL.join([
        '        noted; the 4th through 9th',
        '        levels stay open.',
        '- [ ] **The new illusionist spells**',
    ])
    assert s.count(TAIL_OLD) == 1, 'c tail'
    NOTE = NL.join([
        '      - R359: the 4th level pinned',
        '        (rules/uamuspells4.h) - the',
        '        eight spell descriptions',
        '        (dispel illusion behind the',
        '        lost name tail and the',
        '        garbled half-inch range,',
        '        the Evard black tentacles',
        '        behind the lost level and',
        '        range cells with the stray',
        '        gf line, the Leomund',
        '        secure shelter with the',
        '        scrambled wind sentence,',
        '        magic mirror with the',
        '        scrambled component list,',
        '        the Otiluke resilient',
        '        sphere with the lost globe',
        '        sentence, shout with the',
        '        scrambled area tail,',
        '        stoneskin behind the lost',
        '        level and range cells,',
        '        ultravision with the tail',
        '        past the 5th heading); the',
        '        family decodes the 7s as 1;',
        '        the R342 MU table seam:',
        '        seven of the eight names',
        '        print there, the Dispel',
        '        fragment cell reads as a',
        '        hole; the 5th through 9th',
        '        levels stay open.',
    ])
    clean(NOTE, 57)
    s = s.replace(TAIL_OLD, NL.join([
        '        noted; the 4th through 9th',
        '        levels stay open.',
        NOTE,
        '- [ ] **The new illusionist spells**',
    ]))
    wr(GP, s)
    applied.append('gap report: the note')
s = rd(GP)
assert s.count('R359: the 4th level pinned') == 1, 'c note'
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
if 'R359 UA MU 4th level spells pin audit' in s:
    already.append('regtest.cpp: the R359 audit')
else:
    INC_ANCH = (
        '#include "rules/uamuspells3.h"'
        '  // R358: the UA new magic-user'
        ' 3rd level')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uamuspells4.h"'
        '  // R359: the UA new magic-user'
        ' 4th level',
    ])
    AUD_ANCH = ('    // ---- R227: the wis mental'
                ' save wiring audit ----')
    AUDIT = r"""    // ---- R359: the UA new magic-user 4th level spells pin audit ----
    // The UA NEW MAGIC-USER SPELLS (pp.
    // 51-66), the 4th level - dispel
    // illusion behind the lost name tail
    // and the garbled half-inch range, the
    // Evard black tentacles behind the lost
    // level and range cells, the Leomund
    // secure shelter, magic mirror, the
    // Otiluke resilient sphere, shout with
    // the scrambled area tail, stoneskin
    // behind the lost level and range cells,
    // ultravision. The family decodes the
    // 7s as 1. The R342 table seam pins
    // 7 of 8; the item stays open (the
    // 5th-9th levels).
    {
        using namespace rules;
        int bad = 0;
        // U1: dispel illusion
            if (strcmp(uam4DispelName(),
                "Dispel Illusion (Abjuration)") != 0) ++bad;
            if (!uam4DispelNameHeaderTailLost()) ++bad;
            if (uam4DispelLevel() != 4) ++bad;
            if (!uam4DispelStatInterleavedWithSecretPage()) ++bad;
            if (!uam4DispelComponentsVS()) ++bad;
            if (uam4DispelCastingTimeSegments() != 4) ++bad;
            if (uam4DispelRangeHalfInchesPerLevel() != 1) ++bad;
            if (!uam4DispelRangeFractionGarbled()) ++bad;
            if (!uam4DispelDurationPermanent()) ++bad;
            if (!uam4DispelSaveNone()) ++bad;
            if (!uam4DispelAoeSpecial()) ++bad;
            if (!uam4DispelSameAsIllusionist3rd()) ++bad;
            if (uam4DispelLevelPenaltyVsIllusionist() != 2) ++bad;
        // U2: the Evard black tentacles
            if (strcmp(uam4EvardName(),
                "Evard's Black Tentacles (Conjuration/Summoni"
                "ng)") != 0) ++bad;
            if (uam4EvardLevel() != 4) ++bad;
            if (!uam4EvardLevelCellLost()) ++bad;
            if (!uam4EvardRangeCellLost()) ++bad;
            if (!uam4EvardStrayGfLine()) ++bad;
            if (!uam4EvardComponentsVSM()) ++bad;
            if (uam4EvardCastingTimeSegments() != 8) ++bad;
            if (!uam4EvardSaveNone()) ++bad;
            if (uam4EvardDurationRoundsPerLevel() != 1) ++bad;
            if (uam4EvardAoeSqFtPerLevel() != 30) ++bad;
            if (!uam4EvardSpringsFromAnySurface()) ++bad;
            if (uam4EvardTentacleFeet() != 10) ++bad;
            if (uam4EvardTentacleAc() != 4) ++bad;
            if (!uam4EvardTentacleHpPerCasterLevel()) ++bad;
            if (!uam4EvardOneTentaclePerLevel()) ++bad;
            if (!uam4EvardMultiTargetDieRoll()) ++bad;
            if (uam4EvardDamageOnSaveMin() != 1) ++bad;
            if (uam4EvardDamageOnSaveMax() != 4) ++bad;
            if (uam4EvardDamageOnFailMin() != 2) ++bad;
            if (uam4EvardDamageOnFailMax() != 8) ++bad;
            if (uam4EvardDamageWrappedMin() != 3) ++bad;
            if (uam4EvardDamageWrappedMax() != 12) ++bad;
            if (!uam4EvardMayEntwineObjects()) ++bad;
            if (!uam4EvardContinuesSqueezingDead()) ++bad;
            if (!uam4EvardMaterialOctopusOrSquidTentacle()) ++bad;
        // U3: the Leomund secure shelter
            if (strcmp(uam4ShelterName(),
                "Leomund's Secure Shelter (Alteration - Encha"
                "ntment)") != 0) ++bad;
            if (uam4ShelterLevel() != 4) ++bad;
            if (!uam4ShelterComponentsVSM()) ++bad;
            if (uam4ShelterCastingTimeTurns() != 4) ++bad;
            if (uam4ShelterRangeInches() != 2) ++bad;
            if (!uam4ShelterSaveNone()) ++bad;
            if (uam4ShelterDurationTurnsPerLevel() != 6) ++bad;
            if (uam4ShelterAoeSqFtPerLevel() != 30) ++bad;
            if (!uam4ShelterCottageOfLocalMaterial()) ++bad;
            if (!uam4ShelterFloorLevelCleanDry()) ++bad;
            if (!uam4ShelterDoorWindowsFireplace()) ++bad;
            if (uam4ShelterWindResistanceMph() != 70) ++bad;
            if (!uam4ShelterWindSentenceScrambled()) ++bad;
            if (!uam4ShelterNoHeatingQualities()) ++bad;
            if (!uam4ShelterStrongAsStone()) ++bad;
            if (!uam4ShelterResistsFlamesAsStone()) ++bad;
            if (!uam4ShelterImperviousToNormalMissiles()) ++bad;
            if (!uam4ShelterDoorShuttersWizardLocked()) ++bad;
            if (!uam4ShelterChimneyGrateAndFlue()) ++bad;
            if (!uam4ShelterAlarmProtected()) ++bad;
            if (!uam4ShelterUnseenServant()) ++bad;
            if (uam4ShelterBunksMax() != 8) ++bad;
            if (uam4ShelterChairsMax() != 4) ++bad;
            if (uam4ShelterStoolsMax() != 8) ++bad;
            if (!uam4ShelterTrestleTableAndDesk()) ++bad;
            if (!uam4ShelterMaterialStoneLimeSandWaterWood()) ++bad;
            if (!uam4ShelterMaterialAugmentedByAlarmServant()) ++bad;
        // U4: magic mirror
            if (strcmp(uam4MirrorName(),
                "Magic Mirror (Enchantment - Divination)") != 0) ++bad;
            if (uam4MirrorLevel() != 4) ++bad;
            if (!uam4MirrorComponentsVSM()) ++bad;
            if (uam4MirrorCastingTimeHours() != 1) ++bad;
            if (!uam4MirrorRangeTouch()) ++bad;
            if (!uam4MirrorSaveNone()) ++bad;
            if (uam4MirrorDurationRoundsPerLevel() != 1) ++bad;
            if (!uam4MirrorAoeSpecial()) ++bad;
            if (!uam4MirrorMirrorBecomesScryingDevice()) ++bad;
            if (uam4MirrorSilverCostGpMin() != 1000) ++bad;
            if (!uam4MirrorNotHarmedByCasting()) ++bad;
            if (!uam4MirrorMaterialEyeOfHawkEagleRoc()) ++bad;
            if (!uam4MirrorMaterialZincCopperNitricAcid()) ++bad;
            if (!uam4MirrorComponentListScrambled()) ++bad;
            if (!uam4MirrorCastsThroughComprehend()) ++bad;
            if (!uam4MirrorCastsThroughTonguesInfravisionUltravision())
                ++bad;
            if (uam4MirrorPctPerLevel() != 5) ++bad;
            if (!uam4MirrorDetectSpellsByChance()) ++bad;
            if (!uam4MirrorTargetMayDetectScrying()) ++bad;
            if (uam4MirrorCavalierDetectPct() != 5) ++bad;
            if (uam4MirrorBarbarianDetectPct() != 1) ++bad;
        // U5: the Otiluke resilient sphere
            if (strcmp(uam4OtilukeName(),
                "Otiluke's Resilient Sphere (Alteration - Evo"
                "cation)") != 0) ++bad;
            if (uam4OtilukeLevel() != 4) ++bad;
            if (!uam4OtilukeComponentsVSM()) ++bad;
            if (uam4OtilukeCastingTimeSegments() != 4) ++bad;
            if (uam4OtilukeRangeInches() != 2) ++bad;
            if (!uam4OtilukeSaveNeg()) ++bad;
            if (uam4OtilukeDurationRoundsPerLevel() != 1) ++bad;
            if (uam4OtilukeSphereFeetPerLevel() != 1) ++bad;
            if (!uam4OtilukeProseHeadScrambled()) ++bad;
            if (!uam4OtilukeSubjectFitsWithin()) ++bad;
            if (!uam4OtilukeNotDamagedNormally()) ++bad;
            if (!uam4OtilukeDestroyedByNegationOrDispel()) ++bad;
            if (!uam4OtilukeDestroyedWithoutHarm()) ++bad;
            if (!uam4OtilukeNothingPassesThrough()) ++bad;
            if (!uam4OtilukeSubjectBreathes()) ++bad;
            if (!uam4OtilukeStruggleMovesSphereOnly()) ++bad;
            if (!uam4OtilukeMovableFromOutsideOrWithin()) ++bad;
            if (!uam4OtilukeMaterialDiamondHemisphere()) ++bad;
            if (!uam4OtilukeMaterialGumArabicHemisphere()) ++bad;
        // U6: shout
            if (strcmp(uam4ShoutName(), "Shout (Evocation)") != 0) ++bad;
            if (uam4ShoutLevel() != 4) ++bad;
            if (!uam4ShoutRangeZero()) ++bad;
            if (!uam4ShoutDurationInstantaneous()) ++bad;
            if (uam4ShoutAoeTerminusInches() != 3) ++bad;
            if (!uam4ShoutAoeCellScrambled()) ++bad;
            if (!uam4ShoutConeFromTheMouth()) ++bad;
            if (!uam4ShoutComponentsVM()) ++bad;
            if (!uam4ShoutStatTailInterleaved()) ++bad;
            if (uam4ShoutCastingTimeSegments() != 1) ++bad;
            if (!uam4ShoutSaveNeg()) ++bad;
            if (uam4ShoutDeafenRoundsMin() != 2) ++bad;
            if (uam4ShoutDeafenRoundsMax() != 12) ++bad;
            if (uam4ShoutDamageMin() != 2) ++bad;
            if (uam4ShoutDamageMax() != 12) ++bad;
            if (!uam4ShoutShattersBrittleSubstances()) ++bad;
            if (!uam4ShoutWallOfIceExample()) ++bad;
            if (!uam4ShoutOncePerDay()) ++bad;
            if (!uam4ShoutMaterialHoneyAcidHornCone()) ++bad;
        // U7: stoneskin
            if (strcmp(uam4StoneskinName(),
                "Stoneskin (Alteration)") != 0) ++bad;
            if (uam4StoneskinLevel() != 4) ++bad;
            if (!uam4StoneskinLevelCellLost()) ++bad;
            if (!uam4StoneskinRangeCellLost()) ++bad;
            if (!uam4StoneskinStatTailInterleaved()) ++bad;
            if (!uam4StoneskinComponentsVSM()) ++bad;
            if (uam4StoneskinCastingTimeSegments() != 1) ++bad;
            if (!uam4StoneskinDurationSpecial()) ++bad;
            if (!uam4StoneskinSaveNone()) ++bad;
            if (!uam4StoneskinAoeOneCreature()) ++bad;
            if (!uam4StoneskinImmuneToPhysicalAttacks()) ++bad;
            if (!uam4StoneskinSwordOfSharpnessIneffective()) ++bad;
            if (!uam4StoneskinMagicAttacksNormal()) ++bad;
            if (!uam4StoneskinOneOpponentDispels()) ++bad;
            if (!uam4StoneskinImmuneToThatAttack()) ++bad;
            if (uam4StoneskinSoftWeaponDamageMin() != 1) ++bad;
            if (uam4StoneskinSoftWeaponDamageMax() != 2) ++bad;
            if (!uam4StoneskinSoftWeaponsDoNotDispels()) ++bad;
            if (!uam4StoneskinMaterialGraniteDiamondDust()) ++bad;
        // U8: ultravision
            if (strcmp(uam4UltravisionName(),
                "Ultravision (Alteration)") != 0) ++bad;
            if (uam4UltravisionLevel() != 4) ++bad;
            if (!uam4UltravisionComponentsVSM()) ++bad;
            if (!uam4UltravisionRangeTouch()) ++bad;
            if (uam4UltravisionCastingTimeSegments() != 4) ++bad;
            if (!uam4UltravisionSaveNone()) ++bad;
            if (uam4UltravisionDurationTurnsMin() != 6) ++bad;
            if (uam4UltravisionDurationTurnsPerLevel() != 6) ++bad;
            if (!uam4UltravisionAoeOneCreature()) ++bad;
            if (!uam4UltravisionSeesUltraviolet()) ++bad;
            if (uam4UltravisionClearYards() != 100) ++bad;
            if (uam4UltravisionShadowyYards() != 300) ++bad;
            if (uam4UltravisionDarkNightReductionPct() != 50) ++bad;
            if (uam4UltravisionEarthFeet() != 6) ++bad;
            if (uam4UltravisionStoneFeet() != 3) ++bad;
            if (uam4UltravisionUndergroundRadiusFeet() != 3) ++bad;
            if (!uam4UltravisionUndergroundDimOnly()) ++bad;
            if (!uam4UltravisionEmissionSourceImproves()) ++bad;
            if (!uam4UltravisionNearbyLightSpoils()) ++bad;
            if (uam4UltravisionMaterialAmethystGp() != 500) ++bad;
            if (!uam4UltravisionTailPastFifthHeading()) ++bad;
        // the R342 table seam (7 of 8 names;
        // the Dispel fragment cell is a hole)
        if (uas2Mu4thCount() != 28) ++bad;
        if (strcmp(uas2Mu4thName(5),
                "Evard's Black Tentacles") != 0)
            ++bad;
        if (strcmp(uas2Mu4thName(12),
                "Leomund's Secure Shelter") != 0)
            ++bad;
        if (strcmp(uas2Mu4thName(13),
                "Magic Mirror") != 0) ++bad;
        if (strcmp(uas2Mu4thName(16),
                "Otiluke's Resilient Sphere") != 0)
            ++bad;
        if (strcmp(uas2Mu4thName(22),
                "Shout") != 0) ++bad;
        if (strcmp(uas2Mu4thName(23),
                "Stoneskin") != 0) ++bad;
        if (strcmp(uas2Mu4thName(24),
                "Ultravision") != 0) ++bad;
        // the absent name (the Dispel hole)
        for (int i = 0; i < 28; ++i) {
            const char* n = uas2Mu4thName(i);
            if (strcmp(n, "Dispel Illusion") == 0)
                ++bad;
        }
        printf("R359 UA MU 4th level spells pin audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R359 audit')
s = rd(RT)
assert s.count(
    'R359 UA MU 4th level spells pin audit'
    ': bad ') == 1, 'd audit line'
assert s.count(
    'R358 UA MU 3rd level spells'
    ' pin audit: bad ') == 1, 'd r358 kept'
assert s.count(
    'R357 UA MU 2nd level spells'
    ' pin audit: bad ') == 1, 'd r357 kept'
assert s.count(
    'R356 UA MU 1st level spells'
    ' pin audit: bad ') == 1, 'd r356 kept'
assert s.count('audit: bad ') == 286, 'd census 286'
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
    '#include "rules/uamuspells4.h"') == 1, 'd include'
assert s.count(
    '#include "rules/uamuspells3.h"') == 1, 'd r358 include'
assert s.count(
    '#include "rules/uamuspells2.h"') == 1, 'd r357 include'
assert s.count(
    '#include "rules/uamuspells1.h"') == 1, 'd r356 include'
assert len(applied) + len(already) == 4, 'd count'

# ---- the summary ----
print('R359 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R359 note: the UA new magic-user')
print('spells pin round, the 4th level -')
print('the eight spell descriptions')
print('(dispel illusion behind the lost')
print('name tail and the garbled')
print('half-inch range; the Evard black')
print('tentacles behind the lost level')
print('and range cells with the stray')
print('gf line; the Leomund secure')
print('shelter with the scrambled wind')
print('sentence; magic mirror with the')
print('scrambled component list; the')
print('Otiluke resilient sphere with')
print('the lost globe sentence; shout')
print('with the scrambled area tail;')
print('stoneskin behind the lost level')
print('and range cells; ultravision')
print('with the tail past the 5th')
print('heading); the family decodes')
print('the 7s as 1; the R342 MU table')
print('seam prints seven of the eight')
print('names, the Dispel fragment cell')
print('reads as a hole; the item stays')
print('open (the 5th-9th levels); the')
print('census 285 -> 286')
print('commit: R359: the UA new')
print('magic-user 4th level spells pin')
print('round (census 286)')

