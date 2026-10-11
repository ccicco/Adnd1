#!/usr/bin/env python3
# R346: the UA NEW CLERIC SPELLS
# pin round, the 4th level (pp.
# 38-39) - abjure, cloak of fear,
# giant insect, imbue with spell
# ability, spell immunity and
# spike growth. The digit-garble
# family (established R343)
# decodes the five 7s as 1; the
# R341 continued table prints
# only fragments for the 4th
# level - the six names pin from
# the prose. The item stays open
# (the 5th-7th levels).
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

# ---- (a) the seed: the R345 record ----
SD = 'doc/vibe/adnd1_knowledge_seed_v2.md'
SEED_ENTRY = NL.join([
    '',
    '- R345 landed 2026-10-11: commit',
    '  9988376, census 272, the UA',
    '  new cleric spells pin round,',
    '  the 3rd level',
    '  (rules/uaclericspells3.h):',
    '  cloudburst, death\'s door,',
    '  flame walk, magical vestment,',
    '  meld into stone, negative',
    '  plane protection, remove',
    '  paralysis and water walk; the',
    '  digit-garble family decodes',
    '  the six 7s as 1 (two',
    '  corroborated in-round); the',
    '  R341 3rd-level column is',
    '  fully readable - no hole',
    '  decode. The paste survived a',
    '  nano wrap this round, but',
    '  cat > + Ctrl-D stays the',
    '  pinned save method; GREEN on',
    '  the first run.',
])
s = rd(SD)
if 'R345 landed 2026-10-11' in s:
    already.append('seed: the R345 record')
else:
    ANCH = NL + '## Knowledge maintenance'
    assert s.count(ANCH) == 1, 'a anchor'
    clean(SEED_ENTRY, 72)
    s = s.replace(ANCH, SEED_ENTRY + ANCH)
    wr(SD, s)
    applied.append('seed: the R345 record')
s = rd(SD)
assert s.count('R345 landed 2026-10-11') == 1,     'a entry'
assert s.count('R344 landed 2026-10-11') == 1,     'a r344 kept'
assert s.count('R343 landed 2026-10-11') == 1,     'a r343 kept'
assert s.count('R342 landed 2026-10-11') == 1,     'a r342 kept'
assert s.count('R341 landed 2026-10-11') == 1,     'a r341 kept'
assert s.count('R340 landed 2026-10-11') == 1,     'a r340 kept'
assert s.count('R339 landed 2026-10-11') == 1,     'a r339 kept'
assert s.count('## Knowledge maintenance') == 1,     'a maint'
assert len(applied) + len(already) == 1, 'a count'

# ---- (b) NEW rules/uaclericspells4.h ----
US = 'rules/uaclericspells4.h'
if os.path.exists(US) and 'R346' in rd(US):
    already.append('uaclericspells4.h: the pins')
else:
    HDR = r"""// ===========================================================================
// Adnd1 - rules/uaclericspells4.h
// The UA NEW CLERIC SPELLS (pp. 38-39) pins, R346: the 4th-level
// spell descriptions - abjure, cloak of fear, giant insect, imbue
// with spell ability, spell immunity, spike growth.
//
// Pin-era pattern (R322): pinned data only - no engine site exists.
// The R341 continued table (4th-7th) carries only fragments - the
// 4th-level column prints just Sticks to Snakes and Tongues, so
// none of this round's six names seam-check; they pin from the
// prose alone.
//
// JUDGMENTs (the decode method):
//   - the digit-garble family (established R343, corroborated
//     R344/R345): the OCR prints 7 where 1 belongs in the stat
//     cells. This round's five 7s decode as 1: abjure casting
//     "7 round" = 1 round; cloak of fear duration "7 turn/level"
//     = 1 turn/level (corroborated - the prose prints a clean
//     "expire after a duration of 1 turn per level of the
//     cleric"); imbue with spell ability casting "7 turn" =
//     1 turn; spell immunity casting "7 round" = 1 round; spike
//     growth casting "7 segments" = 1 segment and duration
//     "7-6 turns + 1/level" = 1-6 turns + 1/level - both family
//     decodes without independent corroboration this round,
//     verbatim with doubt pending the PDF.
//   - abjure's name line garbles: "Abjure (Abjurati ible (C" -
//     the school lost mid-word; decoded as Abjuration.
//   - abjure's range cell prints a bare "7" - the family would
//     read 1, but a bare numeral cannot be resolved between 1
//     and Touch; flagged an OCR hole, not pinned.
//   - cloak of fear's school prints "lllusion/Phantasm" - the
//     leading I lost; the established decode (R343).
//   - cloak of fear's stat cells interleave: the value "6
//     segments" prints after the "Range: 0" line - decoded as
//     the casting time.
//   - imbue with spell ability's "Sth level" = 5th - the
//     established decode (R343): the paladin gate is under 5th
//     level, matching the ranger under-8th gate.
//   - spike growth's stat block lacks a "Level:" cell entirely
//     - the level is position-certain 4 from the section; the
//     missing cell is noted as a hole.
//   - giant insect's damage example: the 14th-level 6 HD wasp
//     keeps the full 2-8/1-4; the 7th-level 3 HD wasp takes
//     2-6/1-3 - three-fourths damage for three-fourths hit dice;
//     the shrink example: 4 HD to 1 HD, poison sting save +3,
//     damage 1-2 bite / 1 sting - one-fourth at one-fourth size.
//
// OCR holes (the item stays open - the 5th-7th levels pin in
// later rounds; these stay pending the PDF): the abjure range
// cell; the spike growth Level cell and the two family decodes
// (casting time, duration); the giant insect special-attacks
// sentence fragments ("of the standard giant forms" region).
// ===========================================================================

#pragma once

namespace rules {

// ---- abjure (Abjuration), p. 38 ----
inline const char* uac4AbjureName()
    { return "Abjure (Abjuration)"; }

inline bool uac4AbjureComponentsVSM()
    { return true; }

// The range cell prints a bare "7" - unresolvable; a hole.
inline bool uac4AbjureRangeLost()
    { return true; }

// The casting time prints "7 round" - the digit-garble family
// decodes 1 round.
inline int uac4AbjureCastingTimeRounds()
    { return 1; }

inline bool uac4AbjureDurationPermanent()
    { return true; }

inline bool uac4AbjureSaveNegSeeBelow()
    { return true; }

// Attempts to return a creature from another plane of existence
// to its own plane.
inline bool uac4AbjureReturnsToHomePlane()
    { return true; }

// The exact name of the type of creature must be known; a
// specific (proper) name, if any, must also be known and used.
inline bool uac4AbjureRequiresExactTypeName()
    { return true; }

inline bool uac4AbjureRequiresProperName()
    { return true; }

// Success as dispel magic: base 50%, plus or minus the level/HD
// difference between caster and creature.
inline int uac4AbjureBaseChancePct()
    { return 50; }

inline bool uac4AbjureComparedOnPercentileRoll()
    { return true; }

// A roll equal to or less than the chance instantly sends the
// creature back to its own plane; otherwise the spell fails.
inline bool uac4AbjureRollAtOrUnderSucceeds()
    { return true; }

// The creature might be appreciative of the attempt if it did
// not wish to remain on the caster's plane.
inline bool uac4AbjureCreatureMayBeAppreciative()
    { return true; }

// The reverse, implore: entreats a like-aligned creature from
// another plane to come; success determined as abjure; the exact
// type and given names likewise required.
inline bool uac4AbjureReverseIsImplore()
    { return true; }

inline bool uac4AbjureReverseSameSuccessCheck()
    { return true; }

// If implore succeeds there is absolutely no guarantee the
// creature will be favorably disposed.
inline bool uac4AbjureReverseNoDispositionGuarantee()
    { return true; }

// Neither version functions upon deities, but might affect
// servants or minions thereof.
inline bool uac4AbjureNotOnDeities()
    { return true; }

inline bool uac4AbjureMayAffectServants()
    { return true; }

// The material: a holy/unholy symbol, holy or unholy water, and
// often some material inimical to the creature; reversed, the
// same except the last, which must be something the implored
// creature craves or respects.
inline bool uac4AbjureMaterialSymbolWaterBane()
    { return true; }

inline bool uac4AbjureReverseMaterialCraved()
    { return true; }

// ---- cloak of fear (Illusion/Phantasm) Reversible, p. 38-39 ----
inline const char* uac4CloakName()
    { return "Cloak of Fear (Illusion/Phantasm) Reversible"; }

inline bool uac4CloakReversible()
    { return true; }

inline bool uac4CloakComponentsVSM()
    { return true; }

inline int uac4CloakRangeZero()
    { return 0; }

// The stat cells interleave: the value "6 segments" prints after
// the Range line - the casting time.
inline int uac4CloakCastingTimeSegments()
    { return 6; }

// The duration prints "7 turn/level" - the family decodes
// 1 turn/level, corroborated by the clean prose.
inline int uac4CloakDurationTurnsPerLevel()
    { return 1; }

// Radiates a personal aura of fear out to a 3-inch radius.
inline int uac4CloakAuraRadiusInches()
    { return 3; }

// Any intruder must save versus spell or run away in fear for 6
// rounds (cf. the 3rd-level magic-user fear spell).
inline bool uac4CloakSaveVsSpell()
    { return true; }

inline int uac4CloakFearDurationRounds()
    { return 6; }

inline bool uac4CloakCfMuFearSpell()
    { return true; }

// The spell remains until one creature fails to save, whereupon
// the dweomer dissipates.
inline bool uac4CloakDissipatesOnFailedSave()
    { return true; }

// No effect upon creatures that themselves radiate fear, or upon
// undead of any sort; not dissipated by contact with such.
inline bool uac4CloakNoEffectOnFearRadiators()
    { return true; }

inline bool uac4CloakNoEffectOnUndead()
    { return true; }

inline bool uac4CloakNotDissipatedByImmune()
    { return true; }

// Remains in effect if an intruder saves successfully; expires
// after 1 turn per level if not brought down earlier.
inline bool uac4CloakSurvivesSuccessfulSaves()
    { return true; }

// Members of the cleric's party are not immune.
inline bool uac4CloakPartyNotImmune()
    { return true; }

// The cleric may cancel the aura at any time before the duration
// ends.
inline bool uac4CloakCancellable()
    { return true; }

// The reverse, cloak of bravery: cast upon the cleric or a
// willing creature; grants a +3 bonus to saves against any form
// of magical fear.
inline bool uac4CloakReverseIsBravery()
    { return true; }

inline bool uac4CloakReverseRequiresWilling()
    { return true; }

inline int uac4CloakReverseSaveBonus()
    { return 3; }

// Bravery works only once and only upon a single figure, and is
// dispelled whether or not the save succeeds.
inline bool uac4CloakReverseWorksOnce()
    { return true; }

inline bool uac4CloakReverseSingleFigure()
    { return true; }

inline bool uac4CloakReverseDispelsAfterSave()
    { return true; }

// Bravery does not negate a creature's innate fear radiation -
// the creature can still affect others nearby.
inline bool uac4CloakReverseInnateFearUnaffected()
    { return true; }

// The material: fear - a miniature quiver and a chicken feather;
// bravery - a drop of alcohol and the brain of a newt.
inline bool uac4CloakMaterialQuiverFeather()
    { return true; }

inline bool uac4CloakReverseMaterialAlcoholNewtBrain()
    { return true; }

// ---- giant insect (Alteration) Reversible, p. 39 ----
inline const char* uac4GiantInsectName()
    { return "Giant Insect (Alteration) Reversible"; }

inline bool uac4GiantInsectReversible()
    { return true; }

inline bool uac4GiantInsectComponentsVSM()
    { return true; }

inline int uac4GiantInsectRangeInches()
    { return 2; }

inline int uac4GiantInsectDurationRoundsPerLevel()
    { return 2; }

inline bool uac4GiantInsectCastingTimeSpecial()
    { return true; }

inline bool uac4GiantInsectSaveNone()
    { return true; }

// Turns one or more normal-sized insects into larger forms
// resembling the "giant" forms described in the Monster Manual
// books or the FIEND FOLIO Tome.
inline bool uac4GiantInsectMakesGiantForms()
    { return true; }

// The insect-count ladder by cleric level: one at 7th-9th, two at
// 10th-11th, three at 12th-13th, four at 14th or higher.
inline int uac4GiantInsectCountForLevel(int level) {
    if (level >= 14) return 4;
    if (level >= 12) return 3;
    if (level >= 10) return 2;
    if (level >= 7) return 1;
    return 0;
}

// The total-hit-dice ladder: 3 HD at 7th-9th, 4 HD at 10th-11th,
// 5 HD at 12th-13th, 6 HD at 14th or higher.
inline int uac4GiantInsectHdForLevel(int level) {
    if (level >= 14) return 6;
    if (level >= 12) return 5;
    if (level >= 10) return 4;
    if (level >= 7) return 3;
    return 0;
}

// Only one type of insect per casting - not an ant and a fly
// together.
inline bool uac4GiantInsectOneTypeOnly()
    { return true; }

// The casting time is one round per hit die of the resulting
// giant creature(s); interruption kills the subject insects and
// ruins the spell.
inline int uac4GiantInsectCastingRoundsPerHd()
    { return 1; }

inline bool uac4GiantInsectInterruptKillsSubjects()
    { return true; }

// As many attacks per round as its namesake, but not full damage
// unless the created form has the usual giant hit dice; even
// with more hit dice the damage never exceeds the book figures.
inline bool uac4GiantInsectAttacksAsNamesake()
    { return true; }

inline bool uac4GiantInsectFullDamageOnlyAtFullHd()
    { return true; }

inline bool uac4GiantInsectDamageCappedAtBook()
    { return true; }

// The 14th-level example: a normal wasp enlarged to 6 HD (the
// usual giant wasp is 4 HD) still does 2-8/1-4.
inline int uac4GiantInsectExampleHighClericLevel()
    { return 14; }

inline int uac4GiantInsectExampleHighWaspHd()
    { return 6; }

inline int uac4GiantInsectExampleGiantWaspHd()
    { return 4; }

inline int uac4GiantInsectExampleHighBiteMin()
    { return 2; }

inline int uac4GiantInsectExampleHighBiteMax()
    { return 8; }

inline int uac4GiantInsectExampleHighStingMin()
    { return 1; }

inline int uac4GiantInsectExampleHighStingMax()
    { return 4; }

// The 7th-level example: a giant wasp of 3 HD with reduced damage
// 2-6/1-3 - three-fourths of the damage potential for
// three-fourths of the usual hit dice.
inline int uac4GiantInsectExampleLowClericLevel()
    { return 7; }

inline int uac4GiantInsectExampleLowWaspHd()
    { return 3; }

inline int uac4GiantInsectExampleLowBiteMin()
    { return 2; }

inline int uac4GiantInsectExampleLowBiteMax()
    { return 6; }

inline int uac4GiantInsectExampleLowStingMin()
    { return 1; }

inline int uac4GiantInsectExampleLowStingMax()
    { return 3; }

inline int uac4GiantInsectLowHdDamageNumerator()
    { return 3; }

inline int uac4GiantInsectLowHdDamageDenominator()
    { return 4; }

// Only actual insects - arachnids, crustaceans and other small
// creatures are not affected.
inline bool uac4GiantInsectInsectsOnly()
    { return true; }

// No special attacks or defenses of the standard giant forms;
// armor class, movement and other physical characteristics are
// as described in the book listing.
inline bool uac4GiantInsectNoSpecialAttacks()
    { return true; }

inline bool uac4GiantInsectPhysicalStatsAsBook()
    { return true; }

// The giant insects will not attempt to harm the cleric; control
// is limited - simple commands only ("attack", "defend",
// "guard"), not specific targets or occurrences; uncommanded,
// they attack whatever is near.
inline bool uac4GiantInsectNeverHarmsCleric()
    { return true; }

inline bool uac4GiantInsectSimpleCommandsOnly()
    { return true; }

inline bool uac4GiantInsectUncommandedAttacksNearby()
    { return true; }

// The reverse, shrink insect: reduces standard giant insects as
// well as spell-created ones; 1 HD of reduction per 4 levels,
// maximum 6 HD, to a minimum of 1 HD (1 hp).
inline bool uac4GiantInsectReverseIsShrink()
    { return true; }

inline int uac4GiantInsectShrinkHdPerFourLevels()
    { return 1; }

inline int uac4GiantInsectShrinkMaxHdReduction()
    { return 6; }

inline int uac4GiantInsectShrinkMinHd()
    { return 1; }

// A shrunk insect retains special attacks but weaker - a bonus to
// the saving throw against the attack; the 9th-level example: a
// giant wasp shrunk 4 HD to 1 HD keeps its poison sting at a +3
// save bonus, with damage reduced to 1-2 bite / 1 sting -
// one-fourth at one-fourth size.
inline bool uac4GiantInsectShrinkKeepsSpecialsWeaker()
    { return true; }

inline int uac4GiantInsectShrinkExampleClericLevel()
    { return 9; }

inline int uac4GiantInsectShrinkExampleFromHd()
    { return 4; }

inline int uac4GiantInsectShrinkExampleToHd()
    { return 1; }

inline int uac4GiantInsectShrinkExampleSaveBonus()
    { return 3; }

inline int uac4GiantInsectShrinkExampleBiteMin()
    { return 1; }

inline int uac4GiantInsectShrinkExampleBiteMax()
    { return 2; }

inline int uac4GiantInsectShrinkExampleStingDamage()
    { return 1; }

inline int uac4GiantInsectShrinkDamageNumerator()
    { return 1; }

inline int uac4GiantInsectShrinkDamageDenominator()
    { return 4; }

// The material component for either version: the cleric's
// holy/unholy symbol.
inline bool uac4GiantInsectMaterialSymbol()
    { return true; }

// ---- imbue with spell ability (Enchantment/Alteration), p. 39 ----
inline const char* uac4ImbueName()
    { return "Imbue With Spell Ability (Enchantment-Alteration)"; }

inline bool uac4ImbueComponentsVSM()
    { return true; }

inline int uac4ImbueRangeTouch()
    { return 0; }

// The casting time prints "7 turn" - the family decodes 1 turn.
inline int uac4ImbueCastingTimeTurns()
    { return 1; }

inline bool uac4ImbueDurationSpecial()
    { return true; }

// Bestows the ability to cast a particular spell upon a
// character normally unable to cast spells.
inline bool uac4ImbueGrantsCasting()
    { return true; }

// Only effective on thieves, fighters, cavaliers, assassins,
// monks, rangers (under 8th level) and paladins (under 5th
// level - the "Sth" cell, the established decode); no other
// class or sub-class, no monsters, no one with less than one
// full hit die.
inline bool uac4ImbueEligibleThieves()
    { return true; }

inline bool uac4ImbueEligibleFighters()
    { return true; }

inline bool uac4ImbueEligibleCavaliers()
    { return true; }

inline bool uac4ImbueEligibleAssassins()
    { return true; }

inline bool uac4ImbueEligibleMonks()
    { return true; }

inline int uac4ImbueRangerMaxLevel()
    { return 7; }

inline int uac4ImbuePaladinMaxLevel()
    { return 4; }

inline bool uac4ImbueNotOnMonsters()
    { return true; }

inline bool uac4ImbueRequiresOneFullHd()
    { return true; }

// The spells must be ones the cleric presently carries (has
// prayed for), and only informational or defensive spells, or a
// cure light wounds; any other sort fails the whole transfer.
inline bool uac4ImbueSpellsMustBeCarried()
    { return true; }

inline bool uac4ImbueInfoOrDefensiveOrClw()
    { return true; }

inline bool uac4ImbueWrongSpellFailsAll()
    { return true; }

// As many as three separate spells: one 2nd-level and one or two
// 1st-level.
inline int uac4ImbueMaxSpells()
    { return 3; }

inline int uac4ImbueMaxSecondLevelSpells()
    { return 1; }

inline int uac4ImbueMaxFirstLevelSpells()
    { return 2; }

// The recipient must have wisdom 9 or higher.
inline int uac4ImbueMinWisdom()
    { return 9; }

// A single 1st-level spell in any eligible recipient; 3rd level
// for two 1st-level; 5th level for a 2nd-level spell.
inline int uac4ImbueLevelGateOneFirst()
    { return 1; }

inline int uac4ImbueLevelGateTwoFirst()
    { return 3; }

inline int uac4ImbueLevelGateSecond()
    { return 5; }

// Variable spell characteristics (range, duration, area of
// effect) are cast at the recipient's own level; other details
// (casting time, components) apply normally.
inline bool uac4ImbueVariablesAtRecipientLevel()
    { return true; }

inline bool uac4ImbueOtherDetailsNormal()
    { return true; }

// The cleric loses the transferred spell from repertoire and
// cannot memorize more spells until the recipient uses all
// transferred spells.
inline bool uac4ImbueClericLosesSpell()
    { return true; }

inline bool uac4ImbueBlocksMemorizeUntilUsed()
    { return true; }

// The material: the cleric's holy/unholy symbol plus a minor
// item from the intended recipient symbolic of the profession
// (a lockpick for a thief, a dagger for an assassin); the
// borrowed item is consumed.
inline bool uac4ImbueMaterialSymbolAndProfessionItem()
    { return true; }

inline bool uac4ImbueItemConsumed()
    { return true; }

// ---- spell immunity (Abjuration), p. 39 ----
inline const char* uac4SpellImmunityName()
    { return "Spell Immunity (Abjuration)"; }

inline bool uac4SpellImmunityComponentsVSM()
    { return true; }

inline int uac4SpellImmunityRangeTouch()
    { return 0; }

// The casting time prints "7 round" - the family decodes
// 1 round.
inline int uac4SpellImmunityCastingTimeRounds()
    { return 1; }

inline bool uac4SpellImmunitySaveNone()
    { return true; }

inline int uac4SpellImmunityDurationTurnsPerLevel()
    { return 1; }

// The cleric or any creature touched is made immune to the
// effects of a specified spell of 4th level or lower that the
// cleric has directly experienced (e.g. a fireball once
// suffered).
inline bool uac4SpellImmunitySpecifiedSpellOnly()
    { return true; }

inline int uac4SpellImmunityMaxSpellLevel()
    { return 4; }

inline bool uac4SpellImmunityRequiresDirectExperience()
    { return true; }

// Cannot affect a recipient already magically protected by a
// spell or other temporary effect.
inline bool uac4SpellImmunityBlockedByExistingProtection()
    { return true; }

// Protects only against actual cast spells - not magic item
// effects or innate spell-like abilities; immunity lasts the
// full duration.
inline bool uac4SpellImmunityCastSpellsOnly()
    { return true; }

inline bool uac4SpellImmunityFullDuration()
    { return true; }

// Only one spell immunity per creature at a time; later
// applications have no effect until the first duration ends.
inline bool uac4SpellImmunityOneAtATime()
    { return true; }

// Does not extend to items carried, which must still save.
inline bool uac4SpellImmunityItemsNotProtected()
    { return true; }

// Only a particular spell, not a class or group of similar
// spells - immunity to lightning bolt leaves shocking grasp
// effective.
inline bool uac4SpellImmunityNotSpellGroups()
    { return true; }

// The material component is the same (if any) as for the spell
// to be protected against.
inline bool uac4SpellImmunityMaterialMirrorsSpell()
    { return true; }

// ---- spike growth (Alteration/Enchantment), p. 39 ----
inline const char* uac4SpikeGrowthName()
    { return "Spike Growth (Alteration/Enchantment)"; }

inline bool uac4SpikeGrowthComponentsVSM()
    { return true; }

// The stat block lacks a "Level:" cell entirely - the level is
// position-certain 4 from the section; a hole, noted.
inline bool uac4SpikeGrowthLevelCellLost()
    { return true; }

inline int uac4SpikeGrowthLevel()
    { return 4; }

// The casting time prints "7 segments" - the family decodes
// 1 segment; no independent corroboration, verbatim with doubt
// pending the PDF.
inline int uac4SpikeGrowthCastingTimeSegments()
    { return 1; }

inline bool uac4SpikeGrowthCastingTimeFamilyDecode()
    { return true; }

inline bool uac4SpikeGrowthSaveNone()
    { return true; }

// The duration prints "7-6 turns + 1/level" - the family decodes
// 1-6 turns + 1/level; verbatim with doubt pending the PDF.
inline int uac4SpikeGrowthDurationMinTurns()
    { return 1; }

inline int uac4SpikeGrowthDurationMaxTurns()
    { return 6; }

inline int uac4SpikeGrowthDurationTurnsPerLevel()
    { return 1; }

inline bool uac4SpikeGrowthDurationFamilyDecode()
    { return true; }

inline int uac4SpikeGrowthAreaSquareInchesPerLevel()
    { return 10; }

// Works wherever plant growth of moderate size or density is
// found; ground-covering vegetation and/or roots become very
// hard and sharply pointed; bare ground and earthen pits
// likewise via roots and rootlets.
inline bool uac4SpikeGrowthRequiresPlantGrowth()
    { return true; }

inline bool uac4SpikeGrowthGroundCoverAndRoots()
    { return true; }

inline bool uac4SpikeGrowthBareGroundRoots()
    { return true; }

// Appears unchanged but acts as if strewn with caltrops.
inline bool uac4SpikeGrowthActsAsCaltrops()
    { return true; }

// Absolutely undetectable until a victim enters and takes
// damage, without true seeing, similar magical aids or special
// detection (detect traps); even then the extent stays unknown
// without magical detection.
inline bool uac4SpikeGrowthUndetectableUntilDamage()
    { return true; }

inline bool uac4SpikeGrowthExtentHiddenWithoutMagic()
    { return true; }

// For each 1 inch of movement through the area, 2 "attacks";
// hit probability as if the caster were attacking; each hit
// causes 1-4 points of damage.
inline int uac4SpikeGrowthAttacksPerInchMoved()
    { return 2; }

inline bool uac4SpikeGrowthHitsAsCaster()
    { return true; }

inline int uac4SpikeGrowthDamageMin()
    { return 1; }

inline int uac4SpikeGrowthDamageMax()
    { return 4; }

// Spells which control or harm vegetation, or a dispel magic,
// negate the area.
inline bool uac4SpikeGrowthNegatedByPlantOrDispel()
    { return true; }

// The material: the cleric's holy symbol plus seven sharp
// thorns or seven small twigs, each sharpened to a point.
inline bool uac4SpikeGrowthMaterialSymbolThorns()
    { return true; }

inline int uac4SpikeGrowthThornCount()
    { return 7; }

// The R341 continued table: the 4th-level column prints only
// two fragments (Sticks to Snakes, Tongues) - none of this
// round's six names seam-check; they pin from the prose alone.
inline bool uac4SpikeGrowthSeamFragmentsOnly()
    { return true; }

}   // namespace rules"""
    clean(HDR, 78)
    wr(US, HDR + NL)
    applied.append('uaclericspells4.h: the pins')
s = rd(US)
assert s.count('namespace rules {') == 1, 'b ns'
assert s.count('inline') == 171, 'b inline count'
assert s.count('R346') == 1, 'b round tag'
assert s.count('uac4GiantInsectCountForLevel(int level)') == 1,     'b gi ladder fn'
assert s.count('uac4GiantInsectHdForLevel(int level)') == 1,     'b gi hd fn'
assert s.count('uac4SpikeGrowthDurationFamilyDecode') == 1,     'b sg fn'
assert 'uastClericName' not in s,     'b no r341 ref'
assert 'uac1CeremonyName' not in s,     'b no r343 ref'
assert 'uac2AidName' not in s,     'b no r344 ref'
assert 'uac3CloudName' not in s,     'b no r345 ref'
assert len(applied) + len(already) == 2, 'b count'

# ---- (c) the gap report: the note (the
# item STAYS OPEN - the 5th-7th levels) ----
GP = 'tools/ua_gap_report.md'
s = rd(GP)
if 'R346: the 4th level pinned' in s:
    already.append('gap report: the note')
else:
    TAIL_OLD = NL.join([
        '        noted pending the PDF; the',
        '        4th-7th levels stay open.',
    ])
    assert s.count(TAIL_OLD) == 1, 'c tail'
    NOTE = NL.join([
        '      - R346: the 4th level pinned',
        '        (rules/uaclericspells4.h) -',
        '        abjure, cloak of fear,',
        '        giant insect (the count',
        '        and hit-dice ladders),',
        '        imbue with spell ability,',
        '        spell immunity and spike',
        '        growth; the digit-garble',
        '        family decodes the five',
        '        7s as 1 (the cloak',
        '        duration corroborated by',
        '        its clean prose; the spike',
        '        growth casting and',
        '        duration decodes stay',
        '        verbatim with doubt); the',
        '        R341 continued table',
        '        prints only fragments for',
        '        the 4th level - the six',
        '        names pin from the prose;',
        '        the abjure range cell and',
        '        the spike growth Level',
        '        cell are OCR holes -',
        '        noted pending the PDF; the',
        '        5th-7th levels stay open.',
    ])
    clean(NOTE, 57)
    s = s.replace(TAIL_OLD, TAIL_OLD + NL + NOTE)
    wr(GP, s)
    applied.append('gap report: the note')
s = rd(GP)
assert s.count('R346: the 4th level pinned') == 1,     'c note'
assert s.count('- [ ] **The new cleric spells**'
    ' (pp.') == 1, 'c stays open'
assert s.count('R345: the 3rd level pinned') == 1,     'c r345 kept'
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
if 'R346 UA cleric 4th level spells pin audit' in s:
    already.append('regtest.cpp: the R346 audit')
else:
    INC_ANCH = (
        '#include "rules/uaclericspells3.h"'
        '  // R345: the UA new cleric 3rd'
        ' level')
    INC_NEW = NL.join([
        INC_ANCH,
        '#include "rules/uaclericspells4.h"'
        '  // R346: the UA new cleric 4th'
        ' level',
    ])
    AUD_ANCH = ('    // ---- R227: the wis mental'
                ' save wiring audit ----')
    AUDIT = r"""    // ---- R346: the UA new cleric 4th level spells pin audit ----
    // The UA NEW CLERIC SPELLS (pp. 38-39), the
    // 4th level - abjure (the dispel-magic-style
    // percentile check, the implore reverse),
    // cloak of fear (the 3-inch aura and the
    // bravery +3 reverse), giant insect (the
    // count and hit-dice ladders, the wasp
    // examples), imbue with spell ability (the
    // class gates and the level gates), spell
    // immunity and spike growth. The digit-garble
    // family decodes this round's five 7s as 1
    // (the cloak duration is corroborated by
    // its clean prose); the R341 continued table
    // prints only fragments for the 4th level -
    // none of the six names seam-check. The item
    // stays open (the 5th-7th levels).
    {
        using namespace rules;
        int bad = 0;
        // U1: abjure
        {
            if (strcmp(uac4AbjureName(),
                "Abjure (Abjuration)") != 0) ++bad;
            if (!uac4AbjureComponentsVSM()) ++bad;
            // the range cell prints a bare "7" -
            // unresolvable; a hole
            if (!uac4AbjureRangeLost()) ++bad;
            // the casting time prints "7 round"
            if (uac4AbjureCastingTimeRounds() != 1) ++bad;
            if (!uac4AbjureDurationPermanent()) ++bad;
            if (!uac4AbjureSaveNegSeeBelow()) ++bad;
            if (!uac4AbjureReturnsToHomePlane()) ++bad;
            if (!uac4AbjureRequiresExactTypeName()) ++bad;
            if (!uac4AbjureRequiresProperName()) ++bad;
            // the dispel-magic-style check
            if (uac4AbjureBaseChancePct() != 50) ++bad;
            if (!uac4AbjureComparedOnPercentileRoll()) ++bad;
            if (!uac4AbjureRollAtOrUnderSucceeds()) ++bad;
            if (!uac4AbjureCreatureMayBeAppreciative())
                ++bad;
            // the reverse: implore
            if (!uac4AbjureReverseIsImplore()) ++bad;
            if (!uac4AbjureReverseSameSuccessCheck()) ++bad;
            if (!uac4AbjureReverseNoDispositionGuarantee())
                ++bad;
            if (!uac4AbjureNotOnDeities()) ++bad;
            if (!uac4AbjureMayAffectServants()) ++bad;
            if (!uac4AbjureMaterialSymbolWaterBane())
                ++bad;
            if (!uac4AbjureReverseMaterialCraved()) ++bad;
        }
        // U2: cloak of fear
        {
            if (strcmp(uac4CloakName(),
                "Cloak of Fear (Illusion/Phantasm) Reversible")
                != 0) ++bad;
            if (!uac4CloakReversible()) ++bad;
            if (!uac4CloakComponentsVSM()) ++bad;
            if (uac4CloakRangeZero() != 0) ++bad;
            // the value "6 segments" prints after
            // the Range line - the casting time
            if (uac4CloakCastingTimeSegments() != 6) ++bad;
            // the duration prints "7 turn/level",
            // corroborated by the clean prose
            if (uac4CloakDurationTurnsPerLevel() != 1)
                ++bad;
            if (uac4CloakAuraRadiusInches() != 3) ++bad;
            if (!uac4CloakSaveVsSpell()) ++bad;
            if (uac4CloakFearDurationRounds() != 6) ++bad;
            if (!uac4CloakCfMuFearSpell()) ++bad;
            if (!uac4CloakDissipatesOnFailedSave()) ++bad;
            if (!uac4CloakNoEffectOnFearRadiators()) ++bad;
            if (!uac4CloakNoEffectOnUndead()) ++bad;
            if (!uac4CloakNotDissipatedByImmune()) ++bad;
            if (!uac4CloakSurvivesSuccessfulSaves()) ++bad;
            if (!uac4CloakPartyNotImmune()) ++bad;
            if (!uac4CloakCancellable()) ++bad;
            // the reverse: cloak of bravery
            if (!uac4CloakReverseIsBravery()) ++bad;
            if (!uac4CloakReverseRequiresWilling()) ++bad;
            if (uac4CloakReverseSaveBonus() != 3) ++bad;
            if (!uac4CloakReverseWorksOnce()) ++bad;
            if (!uac4CloakReverseSingleFigure()) ++bad;
            if (!uac4CloakReverseDispelsAfterSave()) ++bad;
            if (!uac4CloakReverseInnateFearUnaffected())
                ++bad;
            if (!uac4CloakMaterialQuiverFeather()) ++bad;
            if (!uac4CloakReverseMaterialAlcoholNewtBrain())
                ++bad;
        }
        // U3: giant insect
        {
            if (strcmp(uac4GiantInsectName(),
                "Giant Insect (Alteration) Reversible")
                != 0) ++bad;
            if (!uac4GiantInsectReversible()) ++bad;
            if (!uac4GiantInsectComponentsVSM()) ++bad;
            if (uac4GiantInsectRangeInches() != 2) ++bad;
            if (uac4GiantInsectDurationRoundsPerLevel() != 2)
                ++bad;
            if (!uac4GiantInsectCastingTimeSpecial()) ++bad;
            if (!uac4GiantInsectSaveNone()) ++bad;
            if (!uac4GiantInsectMakesGiantForms()) ++bad;
            // the count ladder
            if (uac4GiantInsectCountForLevel(7) != 1) ++bad;
            if (uac4GiantInsectCountForLevel(9) != 1) ++bad;
            if (uac4GiantInsectCountForLevel(10) != 2) ++bad;
            if (uac4GiantInsectCountForLevel(11) != 2) ++bad;
            if (uac4GiantInsectCountForLevel(12) != 3) ++bad;
            if (uac4GiantInsectCountForLevel(13) != 3) ++bad;
            if (uac4GiantInsectCountForLevel(14) != 4) ++bad;
            if (uac4GiantInsectCountForLevel(20) != 4) ++bad;
            // the hit-dice ladder
            if (uac4GiantInsectHdForLevel(7) != 3) ++bad;
            if (uac4GiantInsectHdForLevel(11) != 4) ++bad;
            if (uac4GiantInsectHdForLevel(13) != 5) ++bad;
            if (uac4GiantInsectHdForLevel(14) != 6) ++bad;
            if (!uac4GiantInsectOneTypeOnly()) ++bad;
            if (uac4GiantInsectCastingRoundsPerHd() != 1)
                ++bad;
            if (!uac4GiantInsectInterruptKillsSubjects())
                ++bad;
            if (!uac4GiantInsectAttacksAsNamesake()) ++bad;
            if (!uac4GiantInsectFullDamageOnlyAtFullHd())
                ++bad;
            if (!uac4GiantInsectDamageCappedAtBook()) ++bad;
            // the 14th-level wasp example
            if (uac4GiantInsectExampleHighClericLevel() != 14)
                ++bad;
            if (uac4GiantInsectExampleHighWaspHd() != 6)
                ++bad;
            if (uac4GiantInsectExampleGiantWaspHd() != 4)
                ++bad;
            if (uac4GiantInsectExampleHighBiteMin() != 2)
                ++bad;
            if (uac4GiantInsectExampleHighBiteMax() != 8)
                ++bad;
            if (uac4GiantInsectExampleHighStingMin() != 1)
                ++bad;
            if (uac4GiantInsectExampleHighStingMax() != 4)
                ++bad;
            // the 7th-level wasp example
            if (uac4GiantInsectExampleLowClericLevel() != 7)
                ++bad;
            if (uac4GiantInsectExampleLowWaspHd() != 3)
                ++bad;
            if (uac4GiantInsectExampleLowBiteMin() != 2)
                ++bad;
            if (uac4GiantInsectExampleLowBiteMax() != 6)
                ++bad;
            if (uac4GiantInsectExampleLowStingMin() != 1)
                ++bad;
            if (uac4GiantInsectExampleLowStingMax() != 3)
                ++bad;
            if (uac4GiantInsectLowHdDamageNumerator() != 3)
                ++bad;
            if (uac4GiantInsectLowHdDamageDenominator() != 4)
                ++bad;
            if (!uac4GiantInsectInsectsOnly()) ++bad;
            if (!uac4GiantInsectNoSpecialAttacks()) ++bad;
            if (!uac4GiantInsectPhysicalStatsAsBook()) ++bad;
            if (!uac4GiantInsectNeverHarmsCleric()) ++bad;
            if (!uac4GiantInsectSimpleCommandsOnly()) ++bad;
            if (!uac4GiantInsectUncommandedAttacksNearby())
                ++bad;
            // the reverse: shrink insect
            if (!uac4GiantInsectReverseIsShrink()) ++bad;
            if (uac4GiantInsectShrinkHdPerFourLevels() != 1)
                ++bad;
            if (uac4GiantInsectShrinkMaxHdReduction() != 6)
                ++bad;
            if (uac4GiantInsectShrinkMinHd() != 1) ++bad;
            if (!uac4GiantInsectShrinkKeepsSpecialsWeaker())
                ++bad;
            // the 9th-level shrink example
            if (uac4GiantInsectShrinkExampleClericLevel() != 9)
                ++bad;
            if (uac4GiantInsectShrinkExampleFromHd() != 4)
                ++bad;
            if (uac4GiantInsectShrinkExampleToHd() != 1)
                ++bad;
            if (uac4GiantInsectShrinkExampleSaveBonus() != 3)
                ++bad;
            if (uac4GiantInsectShrinkExampleBiteMin() != 1)
                ++bad;
            if (uac4GiantInsectShrinkExampleBiteMax() != 2)
                ++bad;
            if (uac4GiantInsectShrinkExampleStingDamage()
                != 1) ++bad;
            if (uac4GiantInsectShrinkDamageNumerator() != 1)
                ++bad;
            if (uac4GiantInsectShrinkDamageDenominator()
                != 4) ++bad;
            if (!uac4GiantInsectMaterialSymbol()) ++bad;
        }
        // U4: imbue with spell ability
        {
            if (strcmp(uac4ImbueName(),
                "Imbue With Spell Ability (Enchantment-Alteration)")
                != 0) ++bad;
            if (!uac4ImbueComponentsVSM()) ++bad;
            if (uac4ImbueRangeTouch() != 0) ++bad;
            // the casting time prints "7 turn"
            if (uac4ImbueCastingTimeTurns() != 1) ++bad;
            if (!uac4ImbueDurationSpecial()) ++bad;
            if (!uac4ImbueGrantsCasting()) ++bad;
            if (!uac4ImbueEligibleThieves()) ++bad;
            if (!uac4ImbueEligibleFighters()) ++bad;
            if (!uac4ImbueEligibleCavaliers()) ++bad;
            if (!uac4ImbueEligibleAssassins()) ++bad;
            if (!uac4ImbueEligibleMonks()) ++bad;
            // the ranger/paladin gates (the
            // "Sth" cell is the established
            // decode: under 8th, under 5th)
            if (uac4ImbueRangerMaxLevel() != 7) ++bad;
            if (uac4ImbuePaladinMaxLevel() != 4) ++bad;
            if (!uac4ImbueNotOnMonsters()) ++bad;
            if (!uac4ImbueRequiresOneFullHd()) ++bad;
            if (!uac4ImbueSpellsMustBeCarried()) ++bad;
            if (!uac4ImbueInfoOrDefensiveOrClw()) ++bad;
            if (!uac4ImbueWrongSpellFailsAll()) ++bad;
            if (uac4ImbueMaxSpells() != 3) ++bad;
            if (uac4ImbueMaxSecondLevelSpells() != 1) ++bad;
            if (uac4ImbueMaxFirstLevelSpells() != 2) ++bad;
            if (uac4ImbueMinWisdom() != 9) ++bad;
            if (uac4ImbueLevelGateOneFirst() != 1) ++bad;
            if (uac4ImbueLevelGateTwoFirst() != 3) ++bad;
            if (uac4ImbueLevelGateSecond() != 5) ++bad;
            if (!uac4ImbueVariablesAtRecipientLevel()) ++bad;
            if (!uac4ImbueOtherDetailsNormal()) ++bad;
            if (!uac4ImbueClericLosesSpell()) ++bad;
            if (!uac4ImbueBlocksMemorizeUntilUsed()) ++bad;
            if (!uac4ImbueMaterialSymbolAndProfessionItem())
                ++bad;
            if (!uac4ImbueItemConsumed()) ++bad;
        }
        // U5: spell immunity
        {
            if (strcmp(uac4SpellImmunityName(),
                "Spell Immunity (Abjuration)") != 0) ++bad;
            if (!uac4SpellImmunityComponentsVSM()) ++bad;
            if (uac4SpellImmunityRangeTouch() != 0) ++bad;
            // the casting time prints "7 round"
            if (uac4SpellImmunityCastingTimeRounds() != 1)
                ++bad;
            if (!uac4SpellImmunitySaveNone()) ++bad;
            if (uac4SpellImmunityDurationTurnsPerLevel() != 1)
                ++bad;
            if (!uac4SpellImmunitySpecifiedSpellOnly())
                ++bad;
            if (uac4SpellImmunityMaxSpellLevel() != 4) ++bad;
            if (!uac4SpellImmunityRequiresDirectExperience())
                ++bad;
            if (!uac4SpellImmunityBlockedByExistingProtection())
                ++bad;
            if (!uac4SpellImmunityCastSpellsOnly()) ++bad;
            if (!uac4SpellImmunityFullDuration()) ++bad;
            if (!uac4SpellImmunityOneAtATime()) ++bad;
            if (!uac4SpellImmunityItemsNotProtected()) ++bad;
            if (!uac4SpellImmunityNotSpellGroups()) ++bad;
            if (!uac4SpellImmunityMaterialMirrorsSpell())
                ++bad;
        }
        // U6: spike growth
        {
            if (strcmp(uac4SpikeGrowthName(),
                "Spike Growth (Alteration/Enchantment)")
                != 0) ++bad;
            if (!uac4SpikeGrowthComponentsVSM()) ++bad;
            // the stat block lacks a "Level:" cell -
            // the level is position-certain 4
            if (!uac4SpikeGrowthLevelCellLost()) ++bad;
            if (uac4SpikeGrowthLevel() != 4) ++bad;
            // the casting time prints "7 segments"
            // - the family decode, verbatim with
            // doubt pending the PDF
            if (uac4SpikeGrowthCastingTimeSegments() != 1)
                ++bad;
            if (!uac4SpikeGrowthCastingTimeFamilyDecode())
                ++bad;
            if (!uac4SpikeGrowthSaveNone()) ++bad;
            // the duration prints "7-6 turns +
            // 1/level" - the family decode
            if (uac4SpikeGrowthDurationMinTurns() != 1)
                ++bad;
            if (uac4SpikeGrowthDurationMaxTurns() != 6)
                ++bad;
            if (uac4SpikeGrowthDurationTurnsPerLevel() != 1)
                ++bad;
            if (!uac4SpikeGrowthDurationFamilyDecode()) ++bad;
            if (uac4SpikeGrowthAreaSquareInchesPerLevel()
                != 10) ++bad;
            if (!uac4SpikeGrowthRequiresPlantGrowth()) ++bad;
            if (!uac4SpikeGrowthGroundCoverAndRoots()) ++bad;
            if (!uac4SpikeGrowthBareGroundRoots()) ++bad;
            if (!uac4SpikeGrowthActsAsCaltrops()) ++bad;
            if (!uac4SpikeGrowthUndetectableUntilDamage())
                ++bad;
            if (!uac4SpikeGrowthExtentHiddenWithoutMagic())
                ++bad;
            if (uac4SpikeGrowthAttacksPerInchMoved() != 2)
                ++bad;
            if (!uac4SpikeGrowthHitsAsCaster()) ++bad;
            if (uac4SpikeGrowthDamageMin() != 1) ++bad;
            if (uac4SpikeGrowthDamageMax() != 4) ++bad;
            if (!uac4SpikeGrowthNegatedByPlantOrDispel())
                ++bad;
            if (!uac4SpikeGrowthMaterialSymbolThorns()) ++bad;
            if (uac4SpikeGrowthThornCount() != 7) ++bad;
        }
        // U7: the R341 continued-table seam
        {
            // the 4th-level column prints only two
            // fragments - none of this round's six
            // names seam-check
            if (uastClericFragCount(4) != 2) ++bad;
            if (strcmp(uastClericFragName(4, 0),
                "Sticks to Snakes") != 0) ++bad;
            if (strcmp(uastClericFragName(4, 1), "Tongues")
                != 0) ++bad;
            if (uastClericFragName(4, 2)[0] != 0) ++bad;
            if (!uac4SpikeGrowthSeamFragmentsOnly()) ++bad;
        }
        printf("R346 UA cleric 4th level spells pin audit: bad %d\n", bad);
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
    applied.append('regtest.cpp: the R346 audit')
s = rd(RT)
assert s.count(
    'R346 UA cleric 4th level spells'
    ' pin audit: bad ') == 1, 'd audit line'
assert s.count('audit: bad ') == 273, 'd census 273'
assert s.count(
    'R345 UA cleric 3rd level spells pin audit: bad ')     == 1, 'd r345 kept'
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
    '#include "rules/uaclericspells4.h"') == 1,     'd include'
assert len(applied) + len(already) == 4, 'd count'

# ---- the summary ----
print('R346 splice: ALL OK (applied %d, already %d)'
      % (len(applied), len(already)))
print('R346 note: the UA new cleric spells')
print('pin round, the 4th level - the six')
print('spell descriptions (abjure with the')
print('implore reverse, cloak of fear with')
print('the bravery reverse, giant insect')
print('with the count and hit-dice ladders')
print('and the wasp examples, imbue with')
print('spell ability, spell immunity, spike')
print('growth); the digit-garble family')
print('decodes the five 7s as 1; the R341')
print('continued table prints only')
print('fragments - the six names pin from')
print('the prose; the abjure range and')
print('spike growth Level cells are holes')
print('- noted pending the PDF; the item')
print('stays open (the 5th-7th levels);')
print('the census 272 -> 273')
print('commit: R346: the UA new cleric 4th')
print('level spells pin round (census 273)')

