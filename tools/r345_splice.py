#!/usr/bin/env python3
# R345: the UA NEW CLERIC SPELLS
# pin round, the 3rd level (pp.
# 36-38) - cloudburst, death's
# door, flame walk, magical
# vestment, meld into stone,
# negative plane protection,
# remove paralysis and water
# walk. The digit-garble family
# (established R343) decodes the
# six 7s as 1; the R341
# 3rd-level column is fully
# readable - no hole decode this
# round. The item stays open (the
# 4th-7th levels).
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

# ---- (a) the seed: the R344 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R344 landed 2026-10-11: commit',
    '  7734ea9, census 271, the UA',
    '  new cleric spells pin round,',
    '  the 2nd level',
    '  (rules/uaclericspells2.h):',
    '  aid, detect life, dust devil,',
    '  enthrall, holy symbol,',
    '  messenger, withdraw and',
    '  wyvern watch; the digit-garble',
    '  family decodes the five 7s as',
    '  1; the R341 table hole at row',
    '  18 decodes as withdraw. A',
    '  nano-wrapped paste corrupted',
    '  the splice and a prompt-',
    '  prefixed runbook fed bash the',
    '  prompts - both cost a reset.',
    '  Lesson pinned: the save is',
    '  cat > + Ctrl-D and the runbook',
    '  carries bare commands; the',
    '  py_compile/awk/tail pre-check',
    '  gate runs before the first',
    '  splice. GREEN after the reset.',
])
s = rd(SD)
if 'R344 landed 2026-10-11' in s:
    already.append('seed: the R344 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R344 record')
s = rd(SD)
assert s.count('R344 landed 2026-10-11') == 1,     'a entry'
assert s.count('R343 landed 2026-10-11') == 1,     'a r343 kept'
assert s.count('R342 landed 2026-10-11') == 1,     'a r342 kept'
assert s.count('R341 landed 2026-10-11') == 1,     'a r341 kept'
assert s.count('R340 landed 2026-10-11') == 1,     'a r340 kept'
assert s.count('R339 landed 2026-10-11') == 1,     'a r339 kept'
assert s.count('## Knowledge maintenance') == 1,     'a maint'
assert len(applied) + len(already) == 1, 'a count'

# ---- (b) NEW rules/uaclericspells3.h ----
US = 'rules/uaclericspells3.h'
if os.path.exists(US) and 'R345' in rd(US):
    already.append('uaclericspells3.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uaclericspells3.h
// The UA NEW CLERIC SPELLS (pp. 36-38) pins, R345: the 3rd-level
// spell descriptions - cloudburst, death's door, flame walk,
// magical vestment, meld into stone, negative plane protection,
// remove paralysis, water walk.
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
// The R341 cleric table pin (rules/uaspelltables.h) is the name
// seam - the 3rd-level column is fully readable (20 of 20 rows),
// so this round has no hole decode.
//
// JUDGMENTs (the decode method):
//   - the digit-garble family (established R343, corroborated
//     R344): the OCR prints 7 where 1 belongs in the stat cells.
//     This round's six 7s all decode as 1: cloudburst duration
//     "7 round" = 1 round (corroborated - the hot-and-humid
//     extension "to 2 rounds" implies the base 1); death's door
//     duration "7 hour/level" = 1 hour/level; magical vestment
//     casting "7 round" = 1 round; negative plane protection
//     casting "7 round" = 1 round and duration "7 turn/level" =
//     1 turn/level (both corroborated - the prose prints a clean
//     "1 turn per level of the cleric"); meld into stone casting
//     "7 segments" = 1 segment - the family decode with no
//     independent corroboration this round, verbatim with doubt
//     pending the PDF. Every "Level: 3" cell prints clean.
//   - cloudburst's rain-rate cell prints "at the rate of inch per
//     segment, or 1 inch of rainfall in 1 round" - the clauses
//     conflict (a round is six segments); the clean per-round
//     clause is pinned (1 inch per round), the per-segment rate
//     fragment is an OCR hole.
//   - cloudburst's material cell scrambles two columns ("for
//     sion the spell holy are") - the material decodes as silver
//     and powdered iodine crystals plus the cleric's holy
//     symbol.
//   - flame walk's stat cells print inverted (the value
//     "5 segments" precedes its "Casting Time:" label) - decoded
//     as the casting time.
//   - flame walk's lead sentence is column-scrambled: the
//     readable fragments give the man-size/mass empowerment and
//     the magical fires up to 2,000 F; the verb phrase is an OCR
//     hole. The halfling fragment "Va hu-" = 1/2 human; the
//     "apiece, and pi" fragments stay unresolved.
//   - negative plane protection's lead paragraph interleaves two
//     columns ("partially Il protected enabl the caster from an
//     or undead any other mon-el-igible creature touched be") -
//     decoded as: the caster partially protects an otherwise
//     eligible creature touched from an undead or any other
//     monster with an existence on the Negative Material Plane.
//   - meld into stone's duration is corroborated in-round: the
//     stat cell "8 rounds + 1-8" matches the clean prose
//     "9-16 (1d8 + 8) rounds".
//   - the remove paralysis header prints " Reversible" on the
//     name line; pinned verbatim in the name string.
//
// OCR holes (the item stays open - the 4th-7th levels pin in later
// rounds; these stay pending the PDF): the cloudburst range cell
// and the per-segment rain rate; the flame walk lead verb phrase
// and the "apiece, and pi" fragments; the water walk casting-time
// numeral (the cell prints "Casting / segments"); the meld into
// stone casting-time family decode.
// ===========================================================================

#pragma once

namespace rules {

// ---- cloudburst (Alteration), p. 36-37 ----
inline const char* uac3CloudName()
    { return "Cloudburst (Alteration)"; }

inline bool uac3CloudComponentsVSM()
    { return true; }

inline int uac3CloudCastingTimeSegments()
    { return 5; }

// The duration prints "7 round" - the digit-garble family decodes
// 1 round (corroborated: the hot-and-humid extension to 2 rounds).
inline int uac3CloudDurationRounds()
    { return 1; }

inline int uac3CloudCylinderDiameterInches()
    { return 3; }

inline int uac3CloudCylinderHeightInches()
    { return 6; }

// The rain rate: the per-round clause prints clean; the
// per-segment rate fragment is an OCR hole.
inline int uac3CloudRainfallInchesPerRound()
    { return 1; }

// Everything in the area is drenched within 1 segment.
inline int uac3CloudDrenchWithinSegments()
    { return 1; }

// Normal fires: small ones out instantly, medium in 3-5 segments,
// large-sized in 8-10 segments.
inline bool uac3CloudSmallFiresOutInstantly()
    { return true; }

inline int uac3CloudMediumFiresOutMinSegments()
    { return 3; }

inline int uac3CloudMediumFiresOutMaxSegments()
    { return 5; }

inline int uac3CloudLargeFiresOutMinSegments()
    { return 8; }

inline int uac3CloudLargeFiresOutMaxSegments()
    { return 10; }

// Magical fires are also extinguished.
inline bool uac3CloudMagicalFiresExtinguished()
    { return true; }

// Permanent magical fires re-light in 1-2 rounds.
inline int uac3CloudPermanentRelightMinRounds()
    { return 1; }

inline int uac3CloudPermanentRelightMaxRounds()
    { return 2; }

// Rekindlable magical fires (a flame tongue sword) are affected
// only during the actual cloudburst.
inline bool uac3CloudRekindlableDuringOnly()
    { return true; }

// Produce fire and burning hands are negated.
inline bool uac3CloudNegatesProduceFireBurningHands()
    { return true; }

// Large-area spells (fireball, flame strike, wall of fire)
// vaporize the rain into steam of four times the area: a cylinder
// up to 12 inches in diameter and as much as 24 inches high.
inline bool uac3CloudLargeAreaSpellsMakeSteam()
    { return true; }

inline int uac3CloudSteamAreaMultiplier()
    { return 4; }

inline int uac3CloudSteamCylinderDiameterInches()
    { return 12; }

inline int uac3CloudSteamCylinderHeightInches()
    { return 24; }

// The steam inflicts 1-3 points per round on normal creatures,
// twice that to cold-dwelling or cold-using creatures.
inline int uac3CloudSteamDamageMin()
    { return 1; }

inline int uac3CloudSteamDamageMax()
    { return 3; }

inline int uac3CloudSteamColdCreatureMultiplier()
    { return 2; }

// The steam persists 2-5 rounds, half that in a breeze, only 1
// round in a strong wind.
inline int uac3CloudSteamMinRounds()
    { return 2; }

inline int uac3CloudSteamMaxRounds()
    { return 5; }

inline bool uac3CloudSteamBreezeHalves()
    { return true; }

inline bool uac3CloudSteamStrongWindOneRound()
    { return true; }

// In arid regions the cloudburst acts only as a double-strength
// precipitation spell.
inline bool uac3CloudAridDoubleStrengthPrecipitation()
    { return true; }

// In hot and humid areas the duration extends to 2 rounds.
inline int uac3CloudHotHumidDurationRounds()
    { return 2; }

// 33-31 F inclusive: sleet rather than rain, with ice and slush
// formed when it accumulates. 30 F and lower: a snowburst, one
// inch of snow per segment.
inline int uac3CloudSleetHighF()
    { return 33; }

inline int uac3CloudSleetLowF()
    { return 31; }

inline int uac3CloudSnowAtOrBelowF()
    { return 30; }

inline int uac3CloudSnowInchesPerSegment()
    { return 1; }

// The material cell scrambles - the material decodes as silver
// and powdered iodine crystals plus the cleric's holy symbol.
inline bool uac3CloudMaterialSilverIodineSymbol()
    { return true; }

// The range cell prints empty - a hole.
inline bool uac3CloudRangeLost()
    { return true; }

inline bool uac3CloudSegmentRateHole()
    { return true; }

// ---- death's door (Necromantic), p. 37 ----
inline const char* uac3DeathsDoorName()
    { return "Death's Door (Necromantic)"; }

inline bool uac3DeathsDoorComponentsVSM()
    { return true; }

inline int uac3DeathsDoorRangeTouch()
    { return 0; }

// The duration prints "7 hour/level" - the family decodes
// 1 hour/level.
inline int uac3DeathsDoorDurationHoursPerLevel()
    { return 1; }

inline int uac3DeathsDoorCastingTimeSegments()
    { return 5; }

// Touches a human or demi-human unconscious and "at death's door"
// (-1 to -9 hit points); the spell immediately brings the
// individual to 0 hit points.
inline int uac3DeathsDoorDoorLowestHp()
    { return -9; }

inline int uac3DeathsDoorDoorHighestHp()
    { return -1; }

inline bool uac3DeathsDoorBringsToZeroHp()
    { return true; }

// While unconscious, bleeding and deterioration are stopped for
// the duration.
inline bool uac3DeathsDoorBleedingStopped()
    { return true; }

inline bool uac3DeathsDoorDeteriorationStopped()
    { return true; }

// The subject at 0 hit points can be brought to consciousness
// and have hit points restored by cure light wounds, cure serious
// wounds, healing, etc., or clerical or other items which
// magically restore lost hit points.
inline bool uac3DeathsDoorRestorableByCureMagic()
    { return true; }

inline bool uac3DeathsDoorMaterialSymbolLinenUnguent()
    { return true; }

// ---- flame walk (Alteration), p. 37 ----
inline const char* uac3FlameWalkName()
    { return "Flame Walk (Alteration)"; }

inline bool uac3FlameWalkComponentsVSM()
    { return true; }

inline int uac3FlameWalkRangeTouch()
    { return 0; }

inline int uac3FlameWalkDurationBaseTurns()
    { return 1; }

inline int uac3FlameWalkDurationTurnsPerLevel()
    { return 1; }

// The stat cells print inverted - the value precedes its label.
inline int uac3FlameWalkCastingTimeSegments()
    { return 5; }

// The readable fragments: magical fires up to 2,000 F, and a +2
// bonus to saving throws against magical fires.
inline int uac3FlameWalkMaxTempF()
    { return 2000; }

inline int uac3FlameWalkSaveBonusVsMagicalFire()
    { return 2; }

inline bool uac3FlameWalkEmpowersManSizeCreature()
    { return true; }

// For every level above the minimum (5th) the caster affects an
// additional man-sized creature.
inline int uac3FlameWalkMinCasterLevel()
    { return 5; }

inline int uac3FlameWalkExtraCreaturesPerLevelAbove()
    { return 1; }

// The 11th-level example: the caster and a steed such as a horse
// moving in molten lava.
inline int uac3FlameWalkExampleCasterLevel()
    { return 11; }

// A horse counts as 6 humans for purposes of this spell; the
// halfling fragment "Va hu-" decodes as 1/2 human each.
inline int uac3FlameWalkHorseEqualsHumans()
    { return 6; }

inline bool uac3FlameWalkHalflingHalfHuman()
    { return true; }

// The material: powdered ruby and the cleric's holy/unholy
// symbol; the fragments give the ruby at least 500 gp.
inline bool uac3FlameWalkMaterialRubyAndSymbol()
    { return true; }

inline int uac3FlameWalkRubyMinValueGp()
    { return 500; }

// The lead sentence's verb phrase is column-scrambled - a hole.
inline bool uac3FlameWalkLeadSentenceLost()
    { return true; }

// ---- magical vestment (Conjuration/Alteration), p. 37 ----
inline const char* uac3VestmentName()
    { return "Magical Vestment (Conjuration/Alteration)"; }

inline bool uac3VestmentComponentsVSM()
    { return true; }

inline int uac3VestmentRangeTouch()
    { return 0; }

// The casting time prints "7 round" - the family decodes 1 round.
inline int uac3VestmentCastingTimeRounds()
    { return 1; }

inline int uac3VestmentDurationRoundsPerLevel()
    { return 6; }

// Enchants the caster's vestment, providing protection
// equivalent to armor; functions only on ground consecrated to
// the cleric's deity (cf. the 1st-level ceremony spell).
inline bool uac3VestmentProtectsAsArmor()
    { return true; }

inline bool uac3VestmentRequiresConsecratedGround()
    { return true; }

inline bool uac3VestmentCfCeremonySpell()
    { return true; }

// If any armor or protective device is worn, the vestment
// protects as normal chain mail only.
inline bool uac3VestmentArmorWornMeansPlainChain()
    { return true; }

// With no other protection worn: +1 enchantment per four levels,
// to a maximum of chain mail +4 (base AC 1).
inline int uac3VestmentEnchantmentPerFourLevels()
    { return 1; }

inline int uac3VestmentMaxEnchantment()
    { return 4; }

inline int uac3VestmentBaseAcAtMax()
    { return 1; }

// Lasts 6 rounds per level, or until the caster loses
// consciousness or leaves the consecrated area.
inline bool uac3VestmentEndsIfUnconscious()
    { return true; }

inline bool uac3VestmentEndsIfLeavesArea()
    { return true; }

inline bool uac3VestmentMaterialVestmentAndSymbol()
    { return true; }

// ---- meld into stone (Alteration), p. 37-38 ----
inline const char* uac3MeldName()
    { return "Meld Into Stone (Alteration)"; }

inline bool uac3MeldComponentsVSM()
    { return true; }

inline int uac3MeldRangeTouch()
    { return 0; }

// The casting time prints "7 segments" - the family decodes
// 1 segment; no independent corroboration this round, verbatim
// with doubt pending the PDF.
inline int uac3MeldCastingTimeSegments()
    { return 1; }

inline bool uac3MeldCastingTimeFamilyDecode()
    { return true; }

// The duration: stat cell "8 rounds + 1-8" = the prose
// "9-16 (1d8 + 8) rounds", the variable part rolled secretly by
// the DM.
inline int uac3MeldDurationBaseRounds()
    { return 8; }

inline int uac3MeldDurationMinRounds()
    { return 9; }

inline int uac3MeldDurationMaxRounds()
    { return 16; }

inline bool uac3MeldDurationRolledSecretly()
    { return true; }

// The stone must be large enough to accommodate the cleric's
// body in all three dimensions, and the cleric holds a small
// sample of the same type of stone while casting.
inline bool uac3MeldStoneMustFitBody3D()
    { return true; }

inline bool uac3MeldRequiresStoneSample()
    { return true; }

// The cleric and up to 100 pounds of non-living gear blend into
// the stone; magical artifacts and relics are not affected.
inline int uac3MeldGearMaxPounds()
    { return 100; }

inline bool uac3MeldArtifactsNotAffected()
    { return true; }

// Insufficient stone dimensions or more than 100 pounds of gear:
// the spell fails and is wasted.
inline bool uac3MeldFailsIfStoneTooSmall()
    { return true; }

inline bool uac3MeldFailsIfGearTooHeavy()
    { return true; }

// The cleric steps out along the same surface used to enter -
// no movement through the stone (cf. passwall or phase door).
inline bool uac3MeldExitSameSurfaceOnly()
    { return true; }

inline bool uac3MeldNoMovementThroughStone()
    { return true; }

// Duration expiry: expelled, 4-32 (4d8) points of damage, and
// each piece of gear must save versus petrification or turn to
// stone.
inline int uac3MeldExpelDamageMin()
    { return 4; }

inline int uac3MeldExpelDamageMax()
    { return 32; }

inline bool uac3MeldGearSavesVsPetrification()
    { return true; }

// While in the stone: aware of the passage of time, but cannot
// see or hear anything around the stone.
inline bool uac3MeldAwareOfTimePassage()
    { return true; }

inline bool uac3MeldCannotSeeOrHear()
    { return true; }

// Stone to flesh: expels the cleric, 4-32 points of damage, but
// items carried need not save.
inline bool uac3MeldStoneToFleshExpels()
    { return true; }

inline bool uac3MeldStoneToFleshItemsExempt()
    { return true; }

// Stone shape: 4-16 (4d4) points of damage, but no expulsion.
inline int uac3MeldStoneShapeDamageMin()
    { return 4; }

inline int uac3MeldStoneShapeDamageMax()
    { return 16; }

inline bool uac3MeldStoneShapeDoesNotExpel()
    { return true; }

// Transmute rock to mud: expels the cleric and slays instantly
// unless the saving throw versus spell succeeds.
inline bool uac3MeldTransmuteExpels()
    { return true; }

inline bool uac3MeldTransmuteSlaysUnlessSave()
    { return true; }

// ---- negative plane protection (Abjuration), p. 38 ----
inline const char* uac3NppName()
    { return "Negative Plane Protection (Abjuration)"; }

inline bool uac3NppComponentsVSM()
    { return true; }

inline int uac3NppRangeTouch()
    { return 0; }

// The casting time prints "7 round" - the family decodes 1 round.
inline int uac3NppCastingTimeRounds()
    { return 1; }

// The duration prints "7 turn/level" - the family decodes
// 1 turn/level, corroborated by the clean prose ("will last for
// 1 turn per level of the cleric casting the spell").
inline int uac3NppDurationTurnsPerLevel()
    { return 1; }

// One Prime Material Plane creature touched.
inline bool uac3NppTargetPrimeMaterialOnly()
    { return true; }

// The scrambled lead decodes: the caster partially protects an
// otherwise eligible creature touched from an undead or any
// other monster with an existence on the Negative Material
// Plane - such as a shadow, wight, wraith, spectre or vampire.
inline bool uac3NppProtectsVsNegativePlaneMonsters()
    { return true; }

inline const char* uac3NppNmpMonsterExamples()
    { return "shadow, wight, wraith, spectre, vampire"; }

// The dweomer opens a channel to the Positive Material Plane,
// whose energy helps offset the undead attack.
inline bool uac3NppOpensPositiveChannel()
    { return true; }

// Touched (attacked) by an undead creature: a saving throw
// versus death magic. Success: normal damage from the attack but
// no loss of experience; additionally the undead creature takes
// 2-12 (2d6) points of damage from the Positive Plane energy.
inline bool uac3NppSaveVsDeathMagic()
    { return true; }

inline bool uac3NppSuccessNoLevelDrain()
    { return true; }

inline bool uac3NppSuccessNormalDamage()
    { return true; }

inline int uac3NppUndeadTakesDamageMin()
    { return 2; }

inline int uac3NppUndeadTakesDamageMax()
    { return 12; }

// The magic is proof against only one such attack and
// dissipates after it, whether or not the save succeeds.
inline bool uac3NppOneAttackOnly()
    { return true; }

inline bool uac3NppDissipatesAfterAttack()
    { return true; }

// A failed save: double the usual physical damage plus the
// normal loss of experience.
inline bool uac3NppFailedSaveDoublePhysicalDamage()
    { return true; }

inline bool uac3NppFailedSaveNormalEnergyDrain()
    { return true; }

// Also protects from a magic-user's energy drain spell, but the
// magic-user is then not affected.
inline bool uac3NppBlocksEnergyDrainSpell()
    { return true; }

inline bool uac3NppEnergyDrainCasterUnaffected()
    { return true; }

// The planar contact causes a bright flash and a thunderclap
// sound; these phenomena cause no damage.
inline bool uac3NppFlashAndThunderclap()
    { return true; }

inline bool uac3NppPhenomenaCauseNoDamage()
    { return true; }

// Lasts 1 turn per level or until the recipient is successfully
// attacked; cannot be cast on the Negative Material Plane.
inline bool uac3NppEndsOnSuccessfulAttack()
    { return true; }

inline bool uac3NppNotCastableOnNegativePlane()
    { return true; }

// ---- remove paralysis (Abjuration) Reversible, p. 38 ----
inline const char* uac3RemParName()
    { return "Remove Paralysis (Abjuration) Reversible"; }

inline bool uac3RemParReversible()
    { return true; }

inline bool uac3RemParComponentsVS()
    { return true; }

inline int uac3RemParRangeInchesPerLevel()
    { return 1; }

inline int uac3RemParCastingTimeSegments()
    { return 6; }

inline bool uac3RemParDurationPermanent()
    { return true; }

// Frees subjects from paralysis or similar forces (such as a
// hold spell); as many as 4 creatures within range and within a
// 2-inch by 2-inch area of effect.
inline bool uac3RemParRemovesHoldSpell()
    { return true; }

inline int uac3RemParMaxTargets()
    { return 4; }

inline int uac3RemParAreaSquareInches()
    { return 2; }

// No physical or magical barrier may stand between caster and
// target, or the spell fails and is wasted.
inline bool uac3RemParRequiresLineOfEffect()
    { return true; }

inline bool uac3RemParBarrierWastesSpell()
    { return true; }

// Each target obtains a new saving throw versus paralyzation:
// +3 if one creature, +2 if two, +1 if three or four.
inline int uac3RemParSaveBonusOneTarget()
    { return 3; }

inline int uac3RemParSaveBonusTwoTargets()
    { return 2; }

inline int uac3RemParSaveBonusThreeOrFour()
    { return 1; }

// The reverse, cause paralysis: only one target, touched by the
// cleric (a successful "to hit" roll) using the holy/unholy
// symbol; a failed save versus spell paralyzes for 1-6 rounds
// plus 1 round per level of the caster.
inline bool uac3RemParReverseSingleTarget()
    { return true; }

inline bool uac3RemParReverseRequiresTouchHit()
    { return true; }

inline bool uac3RemParReverseUsesHolySymbol()
    { return true; }

inline bool uac3RemParReverseSaveVsSpell()
    { return true; }

inline int uac3RemParReverseDurationMinRounds()
    { return 1; }

inline int uac3RemParReverseDurationMaxRounds()
    { return 6; }

inline int uac3RemParReverseExtraRoundsPerLevel()
    { return 1; }

// Good-aligned clerics should be discerning; the spell might be
// prohibited in certain good-aligned orders.
inline bool uac3RemParGoodClericsDiscerning()
    { return true; }

inline bool uac3RemParProhibitedInSomeGoodOrders()
    { return true; }

// ---- water walk (Alteration), p. 38 ----
inline const char* uac3WaterWalkName()
    { return "Water Walk (Alteration)"; }

inline bool uac3WaterWalkComponentsVSM()
    { return true; }

inline int uac3WaterWalkRangeTouch()
    { return 0; }

inline int uac3WaterWalkDurationBaseTurns()
    { return 1; }

inline int uac3WaterWalkDurationTurnsPerLevel()
    { return 1; }

// Tread upon water as if it were firm, grassy ground (cf. the
// ring of water walking).
inline bool uac3WaterWalkTreadsOnWaterAsGround()
    { return true; }

inline bool uac3WaterWalkCfRingOfWaterWalking()
    { return true; }

// For every level above the minimum (5th) the caster affects an
// additional man-sized creature; the 11th-level example adds a
// horse (6 humans) so the caster moves atop the waves mounted.
inline int uac3WaterWalkMinCasterLevel()
    { return 5; }

inline int uac3WaterWalkExtraCreaturesPerLevelAbove()
    { return 1; }

inline int uac3WaterWalkExampleCasterLevel()
    { return 11; }

inline int uac3WaterWalkHorseEqualsHumans()
    { return 6; }

inline bool uac3WaterWalkMaterialCorkAndSymbol()
    { return true; }

// The casting-time numeral is lost (the cell prints "Casting /
// segments") - a hole.
inline bool uac3WaterWalkCastingTimeLost()
    { return true; }

// The R341 seam: the 3rd-level column is fully readable (20 of
// 20) - this round has no hole decode.
inline bool uac3R341SeamNoHoles()
    { return true; }

}   // namespace rules"""
    clean(HDR, 78)
    wr(US, HDR + NL)
    applied.append('uaclericspells3.h: the pins')
s = rd(US)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 172, 'b inline count'
assert s.count('R345') == 1, 'b round tag'
assert s.count('uac3MeldCastingTimeFamilyDecode') == 1,     'b meld fn'
assert s.count('uac3NppNmpMonsterExamples') == 1,     'b npp fn'
assert s.count('uac3CloudSteamCylinderHeightInches') == 1,     'b cloud fn'
assert 'uastClericName' not in s,     'b no r341 ref'
assert 'uas2Mu1stName' not in s,     'b no r342 ref'
assert 'uac1CeremonyName' not in s,     'b no r343 ref'
assert 'uac2AidName' not in s,     'b no r344 ref'
assert len(applied) + len(already) == 2, 'b count'

# ---- (c) the gap report: the note (the
# item STAYS OPEN - the 4th-7th levels) ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'R345: the 3rd level pinned' in s:
    already.append('gap report: the note')
else:
    TAIL_OLD = NL.join([
        '        the PDF; the 3rd-7th levels',
        '        stay open.',
    ])
    assert s.count(TAIL_OLD) == 1, 'c tail'
    NOTE = NL.join([
        '      - R345: the 3rd level pinned',
        '        (rules/uaclericspells3.h) -',
        '        cloudburst, death\'s door,',
        '        flame walk, magical',
        '        vestment, meld into stone,',
        '        negative plane',
        '        protection, remove',
        '        paralysis and water walk;',
        '        the digit-garble family',
        '        decodes the six 7s as 1',
        '        (the negative plane',
        '        protection duration is',
        '        corroborated by its clean',
        '        prose); the R341',
        '        3rd-level column is fully',
        '        readable - no hole decode',
        '        this round; the cloudburst',
        '        range cell, the flame walk',
        '        lead sentence and the',
        '        water walk casting-time',
        '        numeral are OCR holes -',
        '        noted pending the PDF; the',
        '        4th-7th levels stay open.',
    ])
    clean(NOTE, 57)
    s = s.replace(TAIL_OLD, TAIL_OLD + NL + NOTE)
    wr(GP, s)
    applied.append('gap report: the note')
s = rd(GP)
assert s.count('R345: the 3rd level pinned') == 1,     'c note'
assert s.count('- [ ] **The new cleric spells**'
    ' (pp.') == 1, 'c stays open'
assert s.count('R344: the 2nd level pinned') == 1,     'c r344 kept'
assert s.count('R343: the 1st level pinned') == 1,     'c r343 kept'
assert s.count('CLOSED R342') == 1, 'c r342 kept'
assert s.count('R341: the readable tables') == 1,     'c r341 kept'
assert s.count('R340: the fragment-verified') == 1,     'c r340 kept'
assert len(applied) + len(already) == 3, 'c count'

# ---- (d) regtest.cpp: the include, the
# audit, the census ----
RT = 'regtest.cpp'
s = rd(RT)
if 'R345 UA cleric 3rd level spells pin audit' in s:
    already.append('regtest.cpp: the R345 audit')
else:
    INC_ANCH = (
        '#include "rules/uaclericspells2.h"'
        '  // R344: the UA new cleric 2nd'
        ' level')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uaclericspells3.h"'
        '  // R345: the UA new cleric 3rd'
        ' level',
    ])
    AUD_ANCH = ('    // ---- R227: the wis mental'
                ' save wiring audit ----')
    AUDIT = r"""    // ---- R345: the UA new cleric 3rd level spells pin audit ----
    // The UA NEW CLERIC SPELLS (pp. 36-38), the
    // 3rd level - cloudburst (the fire ladder
    // and the steam mechanics), death's door,
    // flame walk (the 2,000 F and the 500 gp
    // ruby), magical vestment (the chain mail
    // +4 ladder), meld into stone (the 9-16
    // rounds and the expulsion damage),
    // negative plane protection (the 2d6
    // Positive energy counterstrike), remove
    // paralysis (the +3/+2/+1 save ladder)
    // and water walk. The digit-garble family
    // decodes this round's six 7s as 1; the
    // R341 3rd-level column is fully readable
    // - no hole decode this round. The item
    // stays open (the 4th-7th levels).
    {
        using namespace rules;
        int bad = 0;
        // U1: cloudburst
        {
            if (strcmp(uac3CloudName(),
                "Cloudburst (Alteration)") != 0) ++bad;
            if (!uac3CloudComponentsVSM()) ++bad;
            if (uac3CloudCastingTimeSegments() != 5) ++bad;
            // the duration prints "7 round" -
            // the family decode, corroborated by
            // the 2-round hot-humid extension
            if (uac3CloudDurationRounds() != 1) ++bad;
            if (uac3CloudCylinderDiameterInches() != 3) ++bad;
            if (uac3CloudCylinderHeightInches() != 6) ++bad;
            // the per-round clause prints clean;
            // the per-segment rate is a hole
            if (uac3CloudRainfallInchesPerRound() != 1) ++bad;
            if (uac3CloudDrenchWithinSegments() != 1) ++bad;
            if (!uac3CloudSmallFiresOutInstantly()) ++bad;
            if (uac3CloudMediumFiresOutMinSegments() != 3)
                ++bad;
            if (uac3CloudMediumFiresOutMaxSegments() != 5)
                ++bad;
            if (uac3CloudLargeFiresOutMinSegments() != 8)
                ++bad;
            if (uac3CloudLargeFiresOutMaxSegments() != 10)
                ++bad;
            if (!uac3CloudMagicalFiresExtinguished()) ++bad;
            if (uac3CloudPermanentRelightMinRounds() != 1)
                ++bad;
            if (uac3CloudPermanentRelightMaxRounds() != 2)
                ++bad;
            if (!uac3CloudRekindlableDuringOnly()) ++bad;
            if (!uac3CloudNegatesProduceFireBurningHands())
                ++bad;
            if (!uac3CloudLargeAreaSpellsMakeSteam()) ++bad;
            if (uac3CloudSteamAreaMultiplier() != 4) ++bad;
            if (uac3CloudSteamCylinderDiameterInches() != 12)
                ++bad;
            if (uac3CloudSteamCylinderHeightInches() != 24)
                ++bad;
            if (uac3CloudSteamDamageMin() != 1) ++bad;
            if (uac3CloudSteamDamageMax() != 3) ++bad;
            if (uac3CloudSteamColdCreatureMultiplier() != 2)
                ++bad;
            if (uac3CloudSteamMinRounds() != 2) ++bad;
            if (uac3CloudSteamMaxRounds() != 5) ++bad;
            if (!uac3CloudSteamBreezeHalves()) ++bad;
            if (!uac3CloudSteamStrongWindOneRound()) ++bad;
            if (!uac3CloudAridDoubleStrengthPrecipitation())
                ++bad;
            if (uac3CloudHotHumidDurationRounds() != 2) ++bad;
            if (uac3CloudSleetHighF() != 33) ++bad;
            if (uac3CloudSleetLowF() != 31) ++bad;
            if (uac3CloudSnowAtOrBelowF() != 30) ++bad;
            if (uac3CloudSnowInchesPerSegment() != 1) ++bad;
            if (!uac3CloudMaterialSilverIodineSymbol())
                ++bad;
            // the range cell prints empty - a hole
            if (!uac3CloudRangeLost()) ++bad;
            if (!uac3CloudSegmentRateHole()) ++bad;
        }
        // U2: death's door
        {
            if (strcmp(uac3DeathsDoorName(),
                "Death's Door (Necromantic)") != 0) ++bad;
            if (!uac3DeathsDoorComponentsVSM()) ++bad;
            if (uac3DeathsDoorRangeTouch() != 0) ++bad;
            // the duration prints "7 hour/level"
            if (uac3DeathsDoorDurationHoursPerLevel() != 1)
                ++bad;
            if (uac3DeathsDoorCastingTimeSegments() != 5)
                ++bad;
            if (uac3DeathsDoorDoorLowestHp() != -9) ++bad;
            if (uac3DeathsDoorDoorHighestHp() != -1) ++bad;
            if (!uac3DeathsDoorBringsToZeroHp()) ++bad;
            if (!uac3DeathsDoorBleedingStopped()) ++bad;
            if (!uac3DeathsDoorDeteriorationStopped()) ++bad;
            if (!uac3DeathsDoorRestorableByCureMagic()) ++bad;
            if (!uac3DeathsDoorMaterialSymbolLinenUnguent())
                ++bad;
        }
        // U3: flame walk
        {
            if (strcmp(uac3FlameWalkName(),
                "Flame Walk (Alteration)") != 0) ++bad;
            if (!uac3FlameWalkComponentsVSM()) ++bad;
            if (uac3FlameWalkRangeTouch() != 0) ++bad;
            if (uac3FlameWalkDurationBaseTurns() != 1) ++bad;
            if (uac3FlameWalkDurationTurnsPerLevel() != 1)
                ++bad;
            // the stat cells print inverted - the
            // value precedes its label
            if (uac3FlameWalkCastingTimeSegments() != 5)
                ++bad;
            if (uac3FlameWalkMaxTempF() != 2000) ++bad;
            if (uac3FlameWalkSaveBonusVsMagicalFire() != 2)
                ++bad;
            if (!uac3FlameWalkEmpowersManSizeCreature())
                ++bad;
            if (uac3FlameWalkMinCasterLevel() != 5) ++bad;
            if (uac3FlameWalkExtraCreaturesPerLevelAbove() != 1)
                ++bad;
            if (uac3FlameWalkExampleCasterLevel() != 11) ++bad;
            if (uac3FlameWalkHorseEqualsHumans() != 6) ++bad;
            if (!uac3FlameWalkHalflingHalfHuman()) ++bad;
            if (!uac3FlameWalkMaterialRubyAndSymbol()) ++bad;
            if (uac3FlameWalkRubyMinValueGp() != 500) ++bad;
            // the lead sentence is scrambled - a
            // hole
            if (!uac3FlameWalkLeadSentenceLost()) ++bad;
        }
        // U4: magical vestment
        {
            if (strcmp(uac3VestmentName(),
                "Magical Vestment (Conjuration/Alteration)")
                != 0) ++bad;
            if (!uac3VestmentComponentsVSM()) ++bad;
            if (uac3VestmentRangeTouch() != 0) ++bad;
            // the casting time prints "7 round"
            if (uac3VestmentCastingTimeRounds() != 1) ++bad;
            if (uac3VestmentDurationRoundsPerLevel() != 6)
                ++bad;
            if (!uac3VestmentProtectsAsArmor()) ++bad;
            if (!uac3VestmentRequiresConsecratedGround())
                ++bad;
            if (!uac3VestmentCfCeremonySpell()) ++bad;
            if (!uac3VestmentArmorWornMeansPlainChain())
                ++bad;
            if (uac3VestmentEnchantmentPerFourLevels() != 1)
                ++bad;
            if (uac3VestmentMaxEnchantment() != 4) ++bad;
            if (uac3VestmentBaseAcAtMax() != 1) ++bad;
            if (!uac3VestmentEndsIfUnconscious()) ++bad;
            if (!uac3VestmentEndsIfLeavesArea()) ++bad;
            if (!uac3VestmentMaterialVestmentAndSymbol())
                ++bad;
        }
        // U5: meld into stone
        {
            if (strcmp(uac3MeldName(),
                "Meld Into Stone (Alteration)") != 0) ++bad;
            if (!uac3MeldComponentsVSM()) ++bad;
            if (uac3MeldRangeTouch() != 0) ++bad;
            // the casting time prints "7 segments"
            // - the family decode, verbatim with
            // doubt pending the PDF
            if (uac3MeldCastingTimeSegments() != 1) ++bad;
            if (!uac3MeldCastingTimeFamilyDecode()) ++bad;
            if (uac3MeldDurationBaseRounds() != 8) ++bad;
            if (uac3MeldDurationMinRounds() != 9) ++bad;
            if (uac3MeldDurationMaxRounds() != 16) ++bad;
            if (!uac3MeldDurationRolledSecretly()) ++bad;
            if (!uac3MeldStoneMustFitBody3D()) ++bad;
            if (!uac3MeldRequiresStoneSample()) ++bad;
            if (uac3MeldGearMaxPounds() != 100) ++bad;
            if (!uac3MeldArtifactsNotAffected()) ++bad;
            if (!uac3MeldFailsIfStoneTooSmall()) ++bad;
            if (!uac3MeldFailsIfGearTooHeavy()) ++bad;
            if (!uac3MeldExitSameSurfaceOnly()) ++bad;
            if (!uac3MeldNoMovementThroughStone()) ++bad;
            if (uac3MeldExpelDamageMin() != 4) ++bad;
            if (uac3MeldExpelDamageMax() != 32) ++bad;
            if (!uac3MeldGearSavesVsPetrification()) ++bad;
            if (!uac3MeldAwareOfTimePassage()) ++bad;
            if (!uac3MeldCannotSeeOrHear()) ++bad;
            if (!uac3MeldStoneToFleshExpels()) ++bad;
            if (!uac3MeldStoneToFleshItemsExempt()) ++bad;
            if (uac3MeldStoneShapeDamageMin() != 4) ++bad;
            if (uac3MeldStoneShapeDamageMax() != 16) ++bad;
            if (!uac3MeldStoneShapeDoesNotExpel()) ++bad;
            if (!uac3MeldTransmuteExpels()) ++bad;
            if (!uac3MeldTransmuteSlaysUnlessSave()) ++bad;
        }
        // U6: negative plane protection
        {
            if (strcmp(uac3NppName(),
                "Negative Plane Protection (Abjuration)")
                != 0) ++bad;
            if (!uac3NppComponentsVSM()) ++bad;
            if (uac3NppRangeTouch() != 0) ++bad;
            // the casting time prints "7 round"
            if (uac3NppCastingTimeRounds() != 1) ++bad;
            // the duration prints "7 turn/level",
            // corroborated by the clean prose
            if (uac3NppDurationTurnsPerLevel() != 1) ++bad;
            if (!uac3NppTargetPrimeMaterialOnly()) ++bad;
            if (!uac3NppProtectsVsNegativePlaneMonsters())
                ++bad;
            if (strcmp(uac3NppNmpMonsterExamples(),
                "shadow, wight, wraith, spectre, vampire")
                != 0) ++bad;
            if (!uac3NppOpensPositiveChannel()) ++bad;
            if (!uac3NppSaveVsDeathMagic()) ++bad;
            if (!uac3NppSuccessNoLevelDrain()) ++bad;
            if (!uac3NppSuccessNormalDamage()) ++bad;
            if (uac3NppUndeadTakesDamageMin() != 2) ++bad;
            if (uac3NppUndeadTakesDamageMax() != 12) ++bad;
            if (!uac3NppOneAttackOnly()) ++bad;
            if (!uac3NppDissipatesAfterAttack()) ++bad;
            if (!uac3NppFailedSaveDoublePhysicalDamage())
                ++bad;
            if (!uac3NppFailedSaveNormalEnergyDrain()) ++bad;
            if (!uac3NppBlocksEnergyDrainSpell()) ++bad;
            if (!uac3NppEnergyDrainCasterUnaffected()) ++bad;
            if (!uac3NppFlashAndThunderclap()) ++bad;
            if (!uac3NppPhenomenaCauseNoDamage()) ++bad;
            if (!uac3NppEndsOnSuccessfulAttack()) ++bad;
            if (!uac3NppNotCastableOnNegativePlane()) ++bad;
        }
        // U7: remove paralysis
        {
            if (strcmp(uac3RemParName(),
                "Remove Paralysis (Abjuration) Reversible")
                != 0) ++bad;
            if (!uac3RemParReversible()) ++bad;
            if (!uac3RemParComponentsVS()) ++bad;
            if (uac3RemParRangeInchesPerLevel() != 1) ++bad;
            if (uac3RemParCastingTimeSegments() != 6) ++bad;
            if (!uac3RemParDurationPermanent()) ++bad;
            if (!uac3RemParRemovesHoldSpell()) ++bad;
            if (uac3RemParMaxTargets() != 4) ++bad;
            if (uac3RemParAreaSquareInches() != 2) ++bad;
            if (!uac3RemParRequiresLineOfEffect()) ++bad;
            if (!uac3RemParBarrierWastesSpell()) ++bad;
            // the save bonus ladder
            if (uac3RemParSaveBonusOneTarget() != 3) ++bad;
            if (uac3RemParSaveBonusTwoTargets() != 2) ++bad;
            if (uac3RemParSaveBonusThreeOrFour() != 1) ++bad;
            // the reverse: cause paralysis
            if (!uac3RemParReverseSingleTarget()) ++bad;
            if (!uac3RemParReverseRequiresTouchHit()) ++bad;
            if (!uac3RemParReverseUsesHolySymbol()) ++bad;
            if (!uac3RemParReverseSaveVsSpell()) ++bad;
            if (uac3RemParReverseDurationMinRounds() != 1)
                ++bad;
            if (uac3RemParReverseDurationMaxRounds() != 6)
                ++bad;
            if (uac3RemParReverseExtraRoundsPerLevel() != 1)
                ++bad;
            if (!uac3RemParGoodClericsDiscerning()) ++bad;
            if (!uac3RemParProhibitedInSomeGoodOrders())
                ++bad;
        }
        // U8: water walk
        {
            if (strcmp(uac3WaterWalkName(),
                "Water Walk (Alteration)") != 0) ++bad;
            if (!uac3WaterWalkComponentsVSM()) ++bad;
            if (uac3WaterWalkRangeTouch() != 0) ++bad;
            if (uac3WaterWalkDurationBaseTurns() != 1) ++bad;
            if (uac3WaterWalkDurationTurnsPerLevel() != 1)
                ++bad;
            if (!uac3WaterWalkTreadsOnWaterAsGround()) ++bad;
            if (!uac3WaterWalkCfRingOfWaterWalking()) ++bad;
            if (uac3WaterWalkMinCasterLevel() != 5) ++bad;
            if (uac3WaterWalkExtraCreaturesPerLevelAbove() != 1)
                ++bad;
            if (uac3WaterWalkExampleCasterLevel() != 11)
                ++bad;
            if (uac3WaterWalkHorseEqualsHumans() != 6) ++bad;
            if (!uac3WaterWalkMaterialCorkAndSymbol()) ++bad;
            // the casting-time numeral is lost -
            // a hole
            if (!uac3WaterWalkCastingTimeLost()) ++bad;
        }
        // U9: the R341 table seam
        {
            // the 3rd-level column is fully
            // readable - all 20 rows carry names
            if (strcmp(uastClericName(3, 1), "Cloudburst")
                != 0) ++bad;
            if (strcmp(uastClericName(3, 6), "Death's Door")
                != 0) ++bad;
            if (strcmp(uastClericName(3, 9), "Flame Walk")
                != 0) ++bad;
            if (strcmp(uastClericName(3, 12),
                "Magical Vestment") != 0) ++bad;
            if (strcmp(uastClericName(3, 13),
                "Meld Into Stone") != 0) ++bad;
            if (strcmp(uastClericName(3, 14),
                "Negative Plane Protection") != 0) ++bad;
            if (strcmp(uastClericName(3, 17),
                "Remove Paralysis") != 0) ++bad;
            if (strcmp(uastClericName(3, 19), "Water Walk")
                != 0) ++bad;
            if (uastClericReadableCount(3) != 20) ++bad;
            if (!uac3R341SeamNoHoles()) ++bad;
        }
        printf("R345 UA cleric 3rd level spells pin audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R345 audit')
s = rd(RT)
assert s.count(
    'R345 UA cleric 3rd level spells'
    ' pin audit: bad ') == 1, 'd audit line'
assert s.count('audit: bad ') == 272, 'd census 272'
assert s.count(
    'R344 UA cleric 2nd level spells pin audit: bad ')     == 1, 'd r344 kept'
assert s.count(
    'R343 UA cleric 1st level spells pin audit: bad ')     == 1, 'd r343 kept'
assert s.count(
    'R342 UA MU and IL tables pin audit: bad ')     == 1, 'd r342 kept'
assert s.count(
    'R341 UA spell tables pin audit: bad ')     == 1, 'd r341 kept'
assert s.count(
    'R340 UA new weapons prose pin audit: bad ')     == 1, 'd r340 kept'
assert s.count(
    'R339 UA proficiency pin audit: bad ')     == 1, 'd r339 kept'
assert s.count('R227: the wis mental save') == 1,     'd r227 kept'
assert s.count(
    '#include "rules/uaclericspells3.h"') == 1,     'd include'
assert len(applied) + len(already) == 4, 'd count'

# ---- the summary ----
print('R345 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R345 note: the UA new cleric spells')
print('pin round, the 3rd level - the eight')
print('spell descriptions (cloudburst with')
print("the fire and steam ladders, death's")
print('door, flame walk, magical vestment')
print('with the chain mail +4 ladder, meld')
print('into stone, negative plane')
print('protection, remove paralysis, water')
print('walk); the digit-garble family')
print('decodes the six 7s as 1; the R341')
print('3rd-level column is fully readable')
print('- no hole decode; the cloudburst')
print('range, the flame walk lead and the')
print('water walk casting numeral are holes')
print('- noted pending the PDF; the item')
print('stays open (the 4th-7th levels); the')
print('census 271 -> 272')
print('commit: R345: the UA new cleric 3rd')
print('level spells pin round (census 272)')

