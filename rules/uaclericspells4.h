// ===========================================================================
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

}   // namespace rules
