-- ua346: promoted from rules/uaclericspells4.h (the The UA NEW CLERIC SPELLS (pp. 38-39) pins, R346: the 4th-level);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 346,
  "prefix" = "ua346",
  "banner" = {
      "title" = "The UA NEW CLERIC SPELLS (pp. 38-39) pins, R346: the 4th-level",
      "provenance" = "spell descriptions - abjure, cloak of fear, giant insect, imbue with spell ability, spell immunity, spike growth.  Pin-era pattern (R322): pinned data only - no engine site exists. The R341 continued table (4th-7th) carries only fragments - the 4th-level column prints just Sticks to Snakes and Tongues, so none of this round's six names seam-check; they pin from the prose alone.  JUDGMENTs (the decode method): - the digit-garble family (established R343, corroborated R344/R345): the OCR prints 7 where 1 belongs in the stat cells. This round's five 7s decode as 1: abjure casting \"7 round\" = 1 round; cloak of fear duration \"7 turn/level\" = 1 turn/level (corroborated - the prose prints a clean \"expire after a duration of 1 turn per level of the cleric\"); imbue with spell ability casting \"7 turn\" = 1 turn; spell immunity casting \"7 round\" = 1 round; spike growth casting \"7 segments\" = 1 segment and duration \"7-6 turns + 1/level\" = 1-6 turns + 1/level - both family decodes without independent corroboration this round, verbatim with doubt pending the PDF. - abjure's name line garbles: \"Abjure (Abjurati ible (C\" - the school lost mid-word; decoded as Abjuration. - abjure's range cell prints a bare \"7\" - the family would read 1, but a bare numeral cannot be resolved between 1 and Touch; flagged an OCR hole, not pinned. - cloak of fear's school prints \"lllusion/Phantasm\" - the leading I lost; the established decode (R343). - cloak of fear's stat cells interleave: the value \"6 segments\" prints after the \"Range: 0\" line - decoded as the casting time. - imbue with spell ability's \"Sth level\" = 5th - the established decode (R343): the paladin gate is under 5th level, matching the ranger under-8th gate. - spike growth's stat block lacks a \"Level:\" cell entirely - the level is position-certain 4 from the section; the missing cell is noted as a hole. - giant insect's damage example: the 14th-level 6 HD wasp keeps the full 2-8/1-4; the 7th-level 3 HD wasp takes 2-6/1-3 - three-fourths damage for three-fourths hit dice; the shrink example: 4 HD to 1 HD, poison sting save +3, damage 1-2 bite / 1 sting - one-fourth at one-fourth size.  OCR holes (the item stays open - the 5th-7th levels pin in later rounds; these stay pending the PDF): the abjure range cell; the spike growth Level cell and the two family decodes (casting time, duration); the giant insect special-attacks sentence fragments (\"of the standard giant forms\" region).",
    },
  "consts" = { {
      "name" = "uac4AbjureName",
      "value" = "Abjure (Abjuration)",
      "comment" = "---- abjure (Abjuration), p. 38 ----",
    }, {
      "name" = "uac4AbjureCastingTimeRounds",
      "value" = 1,
      "comment" = "The casting time prints \"7 round\" - the digit-garble family decodes 1 round.",
    }, {
      "name" = "uac4AbjureBaseChancePct",
      "value" = 50,
      "comment" = "Success as dispel magic: base 50%, plus or minus the level/HD difference between caster and creature.",
    }, {
      "name" = "uac4CloakName",
      "value" = "Cloak of Fear (Illusion/Phantasm) Reversible",
      "comment" = "---- cloak of fear (Illusion/Phantasm) Reversible, p. 38-39 ----",
    }, {
      "name" = "uac4CloakRangeZero",
      "value" = 0,
      "comment" = "",
    }, {
      "name" = "uac4CloakCastingTimeSegments",
      "value" = 6,
      "comment" = "The stat cells interleave: the value \"6 segments\" prints after the Range line - the casting time.",
    }, {
      "name" = "uac4CloakDurationTurnsPerLevel",
      "value" = 1,
      "comment" = "The duration prints \"7 turn/level\" - the family decodes 1 turn/level, corroborated by the clean prose.",
    }, {
      "name" = "uac4CloakAuraRadiusInches",
      "value" = 3,
      "comment" = "Radiates a personal aura of fear out to a 3-inch radius.",
    }, {
      "name" = "uac4CloakFearDurationRounds",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uac4CloakReverseSaveBonus",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectName",
      "value" = "Giant Insect (Alteration) Reversible",
      "comment" = "---- giant insect (Alteration) Reversible, p. 39 ----",
    }, {
      "name" = "uac4GiantInsectRangeInches",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectDurationRoundsPerLevel",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectCastingRoundsPerHd",
      "value" = 1,
      "comment" = "The casting time is one round per hit die of the resulting giant creature(s); interruption kills the subject insects and ruins the spell.",
    }, {
      "name" = "uac4GiantInsectExampleHighClericLevel",
      "value" = 14,
      "comment" = "The 14th-level example: a normal wasp enlarged to 6 HD (the usual giant wasp is 4 HD) still does 2-8/1-4.",
    }, {
      "name" = "uac4GiantInsectExampleHighWaspHd",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectExampleGiantWaspHd",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectExampleHighBiteMin",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectExampleHighBiteMax",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectExampleHighStingMin",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectExampleHighStingMax",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectExampleLowClericLevel",
      "value" = 7,
      "comment" = "The 7th-level example: a giant wasp of 3 HD with reduced damage 2-6/1-3 - three-fourths of the damage potential for three-fourths of the usual hit dice.",
    }, {
      "name" = "uac4GiantInsectExampleLowWaspHd",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectExampleLowBiteMin",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectExampleLowBiteMax",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectExampleLowStingMin",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectExampleLowStingMax",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectLowHdDamageNumerator",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectLowHdDamageDenominator",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectShrinkHdPerFourLevels",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectShrinkMaxHdReduction",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectShrinkMinHd",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectShrinkExampleClericLevel",
      "value" = 9,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectShrinkExampleFromHd",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectShrinkExampleToHd",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectShrinkExampleSaveBonus",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectShrinkExampleBiteMin",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectShrinkExampleBiteMax",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectShrinkExampleStingDamage",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectShrinkDamageNumerator",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectShrinkDamageDenominator",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uac4ImbueName",
      "value" = "Imbue With Spell Ability (Enchantment-Alteration)",
      "comment" = "---- imbue with spell ability (Enchantment/Alteration), p. 39 ----",
    }, {
      "name" = "uac4ImbueRangeTouch",
      "value" = 0,
      "comment" = "",
    }, {
      "name" = "uac4ImbueCastingTimeTurns",
      "value" = 1,
      "comment" = "The casting time prints \"7 turn\" - the family decodes 1 turn.",
    }, {
      "name" = "uac4ImbueRangerMaxLevel",
      "value" = 7,
      "comment" = "",
    }, {
      "name" = "uac4ImbuePaladinMaxLevel",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uac4ImbueMaxSpells",
      "value" = 3,
      "comment" = "As many as three separate spells: one 2nd-level and one or two 1st-level.",
    }, {
      "name" = "uac4ImbueMaxSecondLevelSpells",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac4ImbueMaxFirstLevelSpells",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uac4ImbueMinWisdom",
      "value" = 9,
      "comment" = "The recipient must have wisdom 9 or higher.",
    }, {
      "name" = "uac4ImbueLevelGateOneFirst",
      "value" = 1,
      "comment" = "A single 1st-level spell in any eligible recipient; 3rd level for two 1st-level; 5th level for a 2nd-level spell.",
    }, {
      "name" = "uac4ImbueLevelGateTwoFirst",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uac4ImbueLevelGateSecond",
      "value" = 5,
      "comment" = "",
    }, {
      "name" = "uac4SpellImmunityName",
      "value" = "Spell Immunity (Abjuration)",
      "comment" = "---- spell immunity (Abjuration), p. 39 ----",
    }, {
      "name" = "uac4SpellImmunityRangeTouch",
      "value" = 0,
      "comment" = "",
    }, {
      "name" = "uac4SpellImmunityCastingTimeRounds",
      "value" = 1,
      "comment" = "The casting time prints \"7 round\" - the family decodes 1 round.",
    }, {
      "name" = "uac4SpellImmunityDurationTurnsPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac4SpellImmunityMaxSpellLevel",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uac4SpikeGrowthName",
      "value" = "Spike Growth (Alteration/Enchantment)",
      "comment" = "---- spike growth (Alteration/Enchantment), p. 39 ----",
    }, {
      "name" = "uac4SpikeGrowthLevel",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uac4SpikeGrowthCastingTimeSegments",
      "value" = 1,
      "comment" = "The casting time prints \"7 segments\" - the family decodes 1 segment; no independent corroboration, verbatim with doubt pending the PDF.",
    }, {
      "name" = "uac4SpikeGrowthDurationMinTurns",
      "value" = 1,
      "comment" = "The duration prints \"7-6 turns + 1/level\" - the family decodes 1-6 turns + 1/level; verbatim with doubt pending the PDF.",
    }, {
      "name" = "uac4SpikeGrowthDurationMaxTurns",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uac4SpikeGrowthDurationTurnsPerLevel",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac4SpikeGrowthAreaSquareInchesPerLevel",
      "value" = 10,
      "comment" = "",
    }, {
      "name" = "uac4SpikeGrowthAttacksPerInchMoved",
      "value" = 2,
      "comment" = "For each 1 inch of movement through the area, 2 \"attacks\"; hit probability as if the caster were attacking; each hit causes 1-4 points of damage.",
    }, {
      "name" = "uac4SpikeGrowthDamageMin",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac4SpikeGrowthDamageMax",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uac4SpikeGrowthThornCount",
      "value" = 7,
      "comment" = "",
    } },
  "bools" = { {
      "name" = "uac4AbjureComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4AbjureRangeLost",
      "value" = true,
      "comment" = "The range cell prints a bare \"7\" - unresolvable; a hole.",
    }, {
      "name" = "uac4AbjureDurationPermanent",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4AbjureSaveNegSeeBelow",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4AbjureReturnsToHomePlane",
      "value" = true,
      "comment" = "Attempts to return a creature from another plane of existence to its own plane.",
    }, {
      "name" = "uac4AbjureRequiresExactTypeName",
      "value" = true,
      "comment" = "The exact name of the type of creature must be known; a specific (proper) name, if any, must also be known and used.",
    }, {
      "name" = "uac4AbjureRequiresProperName",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4AbjureComparedOnPercentileRoll",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4AbjureRollAtOrUnderSucceeds",
      "value" = true,
      "comment" = "A roll equal to or less than the chance instantly sends the creature back to its own plane; otherwise the spell fails.",
    }, {
      "name" = "uac4AbjureCreatureMayBeAppreciative",
      "value" = true,
      "comment" = "The creature might be appreciative of the attempt if it did not wish to remain on the caster's plane.",
    }, {
      "name" = "uac4AbjureReverseIsImplore",
      "value" = true,
      "comment" = "The reverse, implore: entreats a like-aligned creature from another plane to come; success determined as abjure; the exact type and given names likewise required.",
    }, {
      "name" = "uac4AbjureReverseSameSuccessCheck",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4AbjureReverseNoDispositionGuarantee",
      "value" = true,
      "comment" = "If implore succeeds there is absolutely no guarantee the creature will be favorably disposed.",
    }, {
      "name" = "uac4AbjureNotOnDeities",
      "value" = true,
      "comment" = "Neither version functions upon deities, but might affect servants or minions thereof.",
    }, {
      "name" = "uac4AbjureMayAffectServants",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4AbjureMaterialSymbolWaterBane",
      "value" = true,
      "comment" = "The material: a holy/unholy symbol, holy or unholy water, and often some material inimical to the creature; reversed, the same except the last, which must be something the implored creature craves or respects.",
    }, {
      "name" = "uac4AbjureReverseMaterialCraved",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4CloakReversible",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4CloakComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4CloakSaveVsSpell",
      "value" = true,
      "comment" = "Any intruder must save versus spell or run away in fear for 6 rounds (cf. the 3rd-level magic-user fear spell).",
    }, {
      "name" = "uac4CloakCfMuFearSpell",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4CloakDissipatesOnFailedSave",
      "value" = true,
      "comment" = "The spell remains until one creature fails to save, whereupon the dweomer dissipates.",
    }, {
      "name" = "uac4CloakNoEffectOnFearRadiators",
      "value" = true,
      "comment" = "No effect upon creatures that themselves radiate fear, or upon undead of any sort; not dissipated by contact with such.",
    }, {
      "name" = "uac4CloakNoEffectOnUndead",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4CloakNotDissipatedByImmune",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4CloakSurvivesSuccessfulSaves",
      "value" = true,
      "comment" = "Remains in effect if an intruder saves successfully; expires after 1 turn per level if not brought down earlier.",
    }, {
      "name" = "uac4CloakPartyNotImmune",
      "value" = true,
      "comment" = "Members of the cleric's party are not immune.",
    }, {
      "name" = "uac4CloakCancellable",
      "value" = true,
      "comment" = "The cleric may cancel the aura at any time before the duration ends.",
    }, {
      "name" = "uac4CloakReverseIsBravery",
      "value" = true,
      "comment" = "The reverse, cloak of bravery: cast upon the cleric or a willing creature; grants a +3 bonus to saves against any form of magical fear.",
    }, {
      "name" = "uac4CloakReverseRequiresWilling",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4CloakReverseWorksOnce",
      "value" = true,
      "comment" = "Bravery works only once and only upon a single figure, and is dispelled whether or not the save succeeds.",
    }, {
      "name" = "uac4CloakReverseSingleFigure",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4CloakReverseDispelsAfterSave",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4CloakReverseInnateFearUnaffected",
      "value" = true,
      "comment" = "Bravery does not negate a creature's innate fear radiation - the creature can still affect others nearby.",
    }, {
      "name" = "uac4CloakMaterialQuiverFeather",
      "value" = true,
      "comment" = "The material: fear - a miniature quiver and a chicken feather; bravery - a drop of alcohol and the brain of a newt.",
    }, {
      "name" = "uac4CloakReverseMaterialAlcoholNewtBrain",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectReversible",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectCastingTimeSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectMakesGiantForms",
      "value" = true,
      "comment" = "Turns one or more normal-sized insects into larger forms resembling the \"giant\" forms described in the Monster Manual books or the FIEND FOLIO Tome.",
    }, {
      "name" = "uac4GiantInsectOneTypeOnly",
      "value" = true,
      "comment" = "Only one type of insect per casting - not an ant and a fly together.",
    }, {
      "name" = "uac4GiantInsectInterruptKillsSubjects",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectAttacksAsNamesake",
      "value" = true,
      "comment" = "As many attacks per round as its namesake, but not full damage unless the created form has the usual giant hit dice; even with more hit dice the damage never exceeds the book figures.",
    }, {
      "name" = "uac4GiantInsectFullDamageOnlyAtFullHd",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectDamageCappedAtBook",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectInsectsOnly",
      "value" = true,
      "comment" = "Only actual insects - arachnids, crustaceans and other small creatures are not affected.",
    }, {
      "name" = "uac4GiantInsectNoSpecialAttacks",
      "value" = true,
      "comment" = "No special attacks or defenses of the standard giant forms; armor class, movement and other physical characteristics are as described in the book listing.",
    }, {
      "name" = "uac4GiantInsectPhysicalStatsAsBook",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectNeverHarmsCleric",
      "value" = true,
      "comment" = "The giant insects will not attempt to harm the cleric; control is limited - simple commands only (\"attack\", \"defend\", \"guard\"), not specific targets or occurrences; uncommanded, they attack whatever is near.",
    }, {
      "name" = "uac4GiantInsectSimpleCommandsOnly",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectUncommandedAttacksNearby",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4GiantInsectReverseIsShrink",
      "value" = true,
      "comment" = "The reverse, shrink insect: reduces standard giant insects as well as spell-created ones; 1 HD of reduction per 4 levels, maximum 6 HD, to a minimum of 1 HD (1 hp).",
    }, {
      "name" = "uac4GiantInsectShrinkKeepsSpecialsWeaker",
      "value" = true,
      "comment" = "A shrunk insect retains special attacks but weaker - a bonus to the saving throw against the attack; the 9th-level example: a giant wasp shrunk 4 HD to 1 HD keeps its poison sting at a +3 save bonus, with damage reduced to 1-2 bite / 1 sting - one-fourth at one-fourth size.",
    }, {
      "name" = "uac4GiantInsectMaterialSymbol",
      "value" = true,
      "comment" = "The material component for either version: the cleric's holy/unholy symbol.",
    }, {
      "name" = "uac4ImbueComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4ImbueDurationSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4ImbueGrantsCasting",
      "value" = true,
      "comment" = "Bestows the ability to cast a particular spell upon a character normally unable to cast spells.",
    }, {
      "name" = "uac4ImbueEligibleThieves",
      "value" = true,
      "comment" = "Only effective on thieves, fighters, cavaliers, assassins, monks, rangers (under 8th level) and paladins (under 5th level - the \"Sth\" cell, the established decode); no other class or sub-class, no monsters, no one with less than one full hit die.",
    }, {
      "name" = "uac4ImbueEligibleFighters",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4ImbueEligibleCavaliers",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4ImbueEligibleAssassins",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4ImbueEligibleMonks",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4ImbueNotOnMonsters",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4ImbueRequiresOneFullHd",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4ImbueSpellsMustBeCarried",
      "value" = true,
      "comment" = "The spells must be ones the cleric presently carries (has prayed for), and only informational or defensive spells, or a cure light wounds; any other sort fails the whole transfer.",
    }, {
      "name" = "uac4ImbueInfoOrDefensiveOrClw",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4ImbueWrongSpellFailsAll",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4ImbueVariablesAtRecipientLevel",
      "value" = true,
      "comment" = "Variable spell characteristics (range, duration, area of effect) are cast at the recipient's own level; other details (casting time, components) apply normally.",
    }, {
      "name" = "uac4ImbueOtherDetailsNormal",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4ImbueClericLosesSpell",
      "value" = true,
      "comment" = "The cleric loses the transferred spell from repertoire and cannot memorize more spells until the recipient uses all transferred spells.",
    }, {
      "name" = "uac4ImbueBlocksMemorizeUntilUsed",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4ImbueMaterialSymbolAndProfessionItem",
      "value" = true,
      "comment" = "The material: the cleric's holy/unholy symbol plus a minor item from the intended recipient symbolic of the profession (a lockpick for a thief, a dagger for an assassin); the borrowed item is consumed.",
    }, {
      "name" = "uac4ImbueItemConsumed",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4SpellImmunityComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4SpellImmunitySaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4SpellImmunitySpecifiedSpellOnly",
      "value" = true,
      "comment" = "The cleric or any creature touched is made immune to the effects of a specified spell of 4th level or lower that the cleric has directly experienced (e.g. a fireball once suffered).",
    }, {
      "name" = "uac4SpellImmunityRequiresDirectExperience",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4SpellImmunityBlockedByExistingProtection",
      "value" = true,
      "comment" = "Cannot affect a recipient already magically protected by a spell or other temporary effect.",
    }, {
      "name" = "uac4SpellImmunityCastSpellsOnly",
      "value" = true,
      "comment" = "Protects only against actual cast spells - not magic item effects or innate spell-like abilities; immunity lasts the full duration.",
    }, {
      "name" = "uac4SpellImmunityFullDuration",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4SpellImmunityOneAtATime",
      "value" = true,
      "comment" = "Only one spell immunity per creature at a time; later applications have no effect until the first duration ends.",
    }, {
      "name" = "uac4SpellImmunityItemsNotProtected",
      "value" = true,
      "comment" = "Does not extend to items carried, which must still save.",
    }, {
      "name" = "uac4SpellImmunityNotSpellGroups",
      "value" = true,
      "comment" = "Only a particular spell, not a class or group of similar spells - immunity to lightning bolt leaves shocking grasp effective.",
    }, {
      "name" = "uac4SpellImmunityMaterialMirrorsSpell",
      "value" = true,
      "comment" = "The material component is the same (if any) as for the spell to be protected against.",
    }, {
      "name" = "uac4SpikeGrowthComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4SpikeGrowthLevelCellLost",
      "value" = true,
      "comment" = "The stat block lacks a \"Level:\" cell entirely - the level is position-certain 4 from the section; a hole, noted.",
    }, {
      "name" = "uac4SpikeGrowthCastingTimeFamilyDecode",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4SpikeGrowthSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4SpikeGrowthDurationFamilyDecode",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4SpikeGrowthRequiresPlantGrowth",
      "value" = true,
      "comment" = "Works wherever plant growth of moderate size or density is found; ground-covering vegetation and/or roots become very hard and sharply pointed; bare ground and earthen pits likewise via roots and rootlets.",
    }, {
      "name" = "uac4SpikeGrowthGroundCoverAndRoots",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4SpikeGrowthBareGroundRoots",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4SpikeGrowthActsAsCaltrops",
      "value" = true,
      "comment" = "Appears unchanged but acts as if strewn with caltrops.",
    }, {
      "name" = "uac4SpikeGrowthUndetectableUntilDamage",
      "value" = true,
      "comment" = "Absolutely undetectable until a victim enters and takes damage, without true seeing, similar magical aids or special detection (detect traps); even then the extent stays unknown without magical detection.",
    }, {
      "name" = "uac4SpikeGrowthExtentHiddenWithoutMagic",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4SpikeGrowthHitsAsCaster",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac4SpikeGrowthNegatedByPlantOrDispel",
      "value" = true,
      "comment" = "Spells which control or harm vegetation, or a dispel magic, negate the area.",
    }, {
      "name" = "uac4SpikeGrowthMaterialSymbolThorns",
      "value" = true,
      "comment" = "The material: the cleric's holy symbol plus seven sharp thorns or seven small twigs, each sharpened to a point.",
    }, {
      "name" = "uac4SpikeGrowthSeamFragmentsOnly",
      "value" = true,
      "comment" = "The R341 continued table: the 4th-level column prints only two fragments (Sticks to Snakes, Tongues) - none of this round's six names seam-check; they pin from the prose alone.",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "uac4GiantInsectCountForLevel",
      "comment" = "The insect-count ladder by cleric level: one at 7th-9th, two at 10th-11th, three at 12th-13th, four at 14th or higher.",
      "kind" = "header pin",
      "body" = "if (level >= 14) return 4; if (level >= 12) return 3; if (level >= 10) return 2; if (level >= 7) return 1; return 0;",
    }, {
      "name" = "uac4GiantInsectHdForLevel",
      "comment" = "The total-hit-dice ladder: 3 HD at 7th-9th, 4 HD at 10th-11th, 5 HD at 12th-13th, 6 HD at 14th or higher.",
      "kind" = "header pin",
      "body" = "if (level >= 14) return 6; if (level >= 12) return 5; if (level >= 10) return 4; if (level >= 7) return 3; return 0;",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "strcmp(m['uac4AbjureName'](), \"Abjure (Abjuration)\") != 0  or  m['uac4AbjureComponentsVSM']() != 1  or  m['uac4AbjureRangeLost']() != 1  or m['uac4AbjureCastingTimeRounds']() != 1  or  m['uac4AbjureDurationPermanent']() != 1  or  m['uac4AbjureSaveNegSeeBelow']() != 1  or  m['uac4AbjureReturnsToHomePlane']() != 1  or  m['uac4AbjureRequiresExactTypeName']() != 1  or  m['uac4AbjureRequiresProperName']() != 1  or m['uac4AbjureBaseChancePct']() != 50  or  m['uac4AbjureComparedOnPercentileRoll']() != 1  or  m['uac4AbjureRollAtOrUnderSucceeds']() != 1  or  m['uac4AbjureCreatureMayBeAppreciative']() != 1  or  m['uac4AbjureReverseIsImplore']() != 1  or  m['uac4AbjureReverseSameSuccessCheck']() != 1  or  m['uac4AbjureReverseNoDispositionGuarantee']() != 1  or  m['uac4AbjureNotOnDeities']() != 1  or  m['uac4AbjureMayAffectServants']() != 1  or  m['uac4AbjureMaterialSymbolWaterBane']() != 1  or  m['uac4AbjureReverseMaterialCraved']() != 1",
      "note" = "U1: abjure",
    }, {
      "expr" = "strcmp(m['uac4CloakName'](), \"Cloak of Fear (Illusion/Phantasm) Reversible\") != 0  or  m['uac4CloakReversible']() != 1  or  m['uac4CloakComponentsVSM']() != 1  or m['uac4CloakRangeZero']() != 0  or m['uac4CloakCastingTimeSegments']() != 6  or m['uac4CloakDurationTurnsPerLevel']() != 1  or m['uac4CloakAuraRadiusInches']() != 3  or  m['uac4CloakSaveVsSpell']() != 1  or m['uac4CloakFearDurationRounds']() != 6  or  m['uac4CloakCfMuFearSpell']() != 1  or  m['uac4CloakDissipatesOnFailedSave']() != 1  or  m['uac4CloakNoEffectOnFearRadiators']() != 1  or  m['uac4CloakNoEffectOnUndead']() != 1  or  m['uac4CloakNotDissipatedByImmune']() != 1  or  m['uac4CloakSurvivesSuccessfulSaves']() != 1  or  m['uac4CloakPartyNotImmune']() != 1  or  m['uac4CloakCancellable']() != 1  or  m['uac4CloakReverseIsBravery']() != 1  or  m['uac4CloakReverseRequiresWilling']() != 1  or m['uac4CloakReverseSaveBonus']() != 3  or  m['uac4CloakReverseWorksOnce']() != 1  or  m['uac4CloakReverseSingleFigure']() != 1  or  m['uac4CloakReverseDispelsAfterSave']() != 1  or  m['uac4CloakReverseInnateFearUnaffected']() != 1  or  m['uac4CloakMaterialQuiverFeather']() != 1  or  m['uac4CloakReverseMaterialAlcoholNewtBrain']() != 1",
      "note" = "U2: cloak of fear",
    }, {
      "expr" = "strcmp(m['uac4GiantInsectName'](), \"Giant Insect (Alteration) Reversible\") != 0  or  m['uac4GiantInsectReversible']() != 1  or  m['uac4GiantInsectComponentsVSM']() != 1  or m['uac4GiantInsectRangeInches']() != 2  or m['uac4GiantInsectDurationRoundsPerLevel']() != 2  or  m['uac4GiantInsectCastingTimeSpecial']() != 1  or  m['uac4GiantInsectSaveNone']() != 1  or  m['uac4GiantInsectMakesGiantForms']() != 1  or m['uac4GiantInsectCountForLevel'](7) != 1  or m['uac4GiantInsectCountForLevel'](9) != 1  or m['uac4GiantInsectCountForLevel'](10) != 2  or m['uac4GiantInsectCountForLevel'](11) != 2  or m['uac4GiantInsectCountForLevel'](12) != 3  or m['uac4GiantInsectCountForLevel'](13) != 3  or m['uac4GiantInsectCountForLevel'](14) != 4  or m['uac4GiantInsectCountForLevel'](20) != 4  or m['uac4GiantInsectHdForLevel'](7) != 3  or m['uac4GiantInsectHdForLevel'](11) != 4  or m['uac4GiantInsectHdForLevel'](13) != 5  or m['uac4GiantInsectHdForLevel'](14) != 6  or  m['uac4GiantInsectOneTypeOnly']() != 1  or m['uac4GiantInsectCastingRoundsPerHd']() != 1  or  m['uac4GiantInsectInterruptKillsSubjects']() != 1  or  m['uac4GiantInsectAttacksAsNamesake']() != 1  or  m['uac4GiantInsectFullDamageOnlyAtFullHd']() != 1  or  m['uac4GiantInsectDamageCappedAtBook']() != 1  or m['uac4GiantInsectExampleHighClericLevel']() != 14  or m['uac4GiantInsectExampleHighWaspHd']() != 6  or m['uac4GiantInsectExampleGiantWaspHd']() != 4  or m['uac4GiantInsectExampleHighBiteMin']() != 2  or m['uac4GiantInsectExampleHighBiteMax']() != 8  or m['uac4GiantInsectExampleHighStingMin']() != 1  or m['uac4GiantInsectExampleHighStingMax']() != 4  or m['uac4GiantInsectExampleLowClericLevel']() != 7  or m['uac4GiantInsectExampleLowWaspHd']() != 3  or m['uac4GiantInsectExampleLowBiteMin']() != 2  or m['uac4GiantInsectExampleLowBiteMax']() != 6  or m['uac4GiantInsectExampleLowStingMin']() != 1  or m['uac4GiantInsectExampleLowStingMax']() != 3  or m['uac4GiantInsectLowHdDamageNumerator']() != 3  or m['uac4GiantInsectLowHdDamageDenominator']() != 4  or  m['uac4GiantInsectInsectsOnly']() != 1  or  m['uac4GiantInsectNoSpecialAttacks']() != 1  or  m['uac4GiantInsectPhysicalStatsAsBook']() != 1  or  m['uac4GiantInsectNeverHarmsCleric']() != 1  or  m['uac4GiantInsectSimpleCommandsOnly']() != 1  or  m['uac4GiantInsectUncommandedAttacksNearby']() != 1  or  m['uac4GiantInsectReverseIsShrink']() != 1  or m['uac4GiantInsectShrinkHdPerFourLevels']() != 1  or m['uac4GiantInsectShrinkMaxHdReduction']() != 6  or m['uac4GiantInsectShrinkMinHd']() != 1  or  m['uac4GiantInsectShrinkKeepsSpecialsWeaker']() != 1  or m['uac4GiantInsectShrinkExampleClericLevel']() != 9  or m['uac4GiantInsectShrinkExampleFromHd']() != 4  or m['uac4GiantInsectShrinkExampleToHd']() != 1  or m['uac4GiantInsectShrinkExampleSaveBonus']() != 3  or m['uac4GiantInsectShrinkExampleBiteMin']() != 1  or m['uac4GiantInsectShrinkExampleBiteMax']() != 2  or m['uac4GiantInsectShrinkExampleStingDamage']() != 1  or m['uac4GiantInsectShrinkDamageNumerator']() != 1  or m['uac4GiantInsectShrinkDamageDenominator']() != 4  or  m['uac4GiantInsectMaterialSymbol']() != 1",
      "note" = "U3: giant insect",
    }, {
      "expr" = "strcmp(m['uac4ImbueName'](), \"Imbue With Spell Ability (Enchantment-Alteration)\") != 0  or  m['uac4ImbueComponentsVSM']() != 1  or m['uac4ImbueRangeTouch']() != 0  or m['uac4ImbueCastingTimeTurns']() != 1  or  m['uac4ImbueDurationSpecial']() != 1  or  m['uac4ImbueGrantsCasting']() != 1  or  m['uac4ImbueEligibleThieves']() != 1  or  m['uac4ImbueEligibleFighters']() != 1  or  m['uac4ImbueEligibleCavaliers']() != 1  or  m['uac4ImbueEligibleAssassins']() != 1  or  m['uac4ImbueEligibleMonks']() != 1  or m['uac4ImbueRangerMaxLevel']() != 7  or m['uac4ImbuePaladinMaxLevel']() != 4  or  m['uac4ImbueNotOnMonsters']() != 1  or  m['uac4ImbueRequiresOneFullHd']() != 1  or  m['uac4ImbueSpellsMustBeCarried']() != 1  or  m['uac4ImbueInfoOrDefensiveOrClw']() != 1  or  m['uac4ImbueWrongSpellFailsAll']() != 1  or m['uac4ImbueMaxSpells']() != 3  or m['uac4ImbueMaxSecondLevelSpells']() != 1  or m['uac4ImbueMaxFirstLevelSpells']() != 2  or m['uac4ImbueMinWisdom']() != 9  or m['uac4ImbueLevelGateOneFirst']() != 1  or m['uac4ImbueLevelGateTwoFirst']() != 3  or m['uac4ImbueLevelGateSecond']() != 5  or  m['uac4ImbueVariablesAtRecipientLevel']() != 1  or  m['uac4ImbueOtherDetailsNormal']() != 1  or  m['uac4ImbueClericLosesSpell']() != 1  or  m['uac4ImbueBlocksMemorizeUntilUsed']() != 1  or  m['uac4ImbueMaterialSymbolAndProfessionItem']() != 1  or  m['uac4ImbueItemConsumed']() != 1",
      "note" = "U4: imbue with spell ability",
    }, {
      "expr" = "strcmp(m['uac4SpellImmunityName'](), \"Spell Immunity (Abjuration)\") != 0  or  m['uac4SpellImmunityComponentsVSM']() != 1  or m['uac4SpellImmunityRangeTouch']() != 0  or m['uac4SpellImmunityCastingTimeRounds']() != 1  or  m['uac4SpellImmunitySaveNone']() != 1  or m['uac4SpellImmunityDurationTurnsPerLevel']() != 1  or  m['uac4SpellImmunitySpecifiedSpellOnly']() != 1  or m['uac4SpellImmunityMaxSpellLevel']() != 4  or  m['uac4SpellImmunityRequiresDirectExperience']() != 1  or  m['uac4SpellImmunityBlockedByExistingProtection']() != 1  or  m['uac4SpellImmunityCastSpellsOnly']() != 1  or  m['uac4SpellImmunityFullDuration']() != 1  or  m['uac4SpellImmunityOneAtATime']() != 1  or  m['uac4SpellImmunityItemsNotProtected']() != 1  or  m['uac4SpellImmunityNotSpellGroups']() != 1  or  m['uac4SpellImmunityMaterialMirrorsSpell']() != 1",
      "note" = "U5: spell immunity",
    }, {
      "expr" = "strcmp(m['uac4SpikeGrowthName'](), \"Spike Growth (Alteration/Enchantment)\") != 0  or  m['uac4SpikeGrowthComponentsVSM']() != 1  or  m['uac4SpikeGrowthLevelCellLost']() != 1  or m['uac4SpikeGrowthLevel']() != 4  or m['uac4SpikeGrowthCastingTimeSegments']() != 1  or  m['uac4SpikeGrowthCastingTimeFamilyDecode']() != 1  or  m['uac4SpikeGrowthSaveNone']() != 1  or m['uac4SpikeGrowthDurationMinTurns']() != 1  or m['uac4SpikeGrowthDurationMaxTurns']() != 6  or m['uac4SpikeGrowthDurationTurnsPerLevel']() != 1  or  m['uac4SpikeGrowthDurationFamilyDecode']() != 1  or m['uac4SpikeGrowthAreaSquareInchesPerLevel']() != 10  or  m['uac4SpikeGrowthRequiresPlantGrowth']() != 1  or  m['uac4SpikeGrowthGroundCoverAndRoots']() != 1  or  m['uac4SpikeGrowthBareGroundRoots']() != 1  or  m['uac4SpikeGrowthActsAsCaltrops']() != 1  or  m['uac4SpikeGrowthUndetectableUntilDamage']() != 1  or  m['uac4SpikeGrowthExtentHiddenWithoutMagic']() != 1  or m['uac4SpikeGrowthAttacksPerInchMoved']() != 2  or  m['uac4SpikeGrowthHitsAsCaster']() != 1  or m['uac4SpikeGrowthDamageMin']() != 1  or m['uac4SpikeGrowthDamageMax']() != 4  or  m['uac4SpikeGrowthNegatedByPlantOrDispel']() != 1  or  m['uac4SpikeGrowthMaterialSymbolThorns']() != 1  or m['uac4SpikeGrowthThornCount']() != 7",
      "note" = "U6: spike growth",
    }, {
      "expr" = "m['uastClericFragCount'](4) != 2  or strcmp(m['uastClericFragName'](4, 0), \"Sticks to Snakes\") != 0  or strcmp(m['uastClericFragName'](4, 1), \"Tongues\") != 0  or m['uastClericFragName'](4, 2)[0] != 0  or  m['uac4SpikeGrowthSeamFragmentsOnly']() != 1",
      "note" = "U7: the R341 continued-table seam",
    } },
  "audit" = {
      "label" = "R346: the UA new cleric 4th level spells pin audit",
      "comment" = "The UA NEW CLERIC SPELLS (pp. 38-39), the 4th level - abjure (the dispel-magic-style percentile check, the implore reverse), cloak of fear (the 3-inch aura and the bravery +3 reverse), giant insect (the count and hit-dice ladders, the wasp examples), imbue with spell ability (the class gates and the level gates), spell immunity and spike growth. The digit-garble family decodes this round's five 7s as 1 (the cloak duration is corroborated by its clean prose); the R341 continued table prints only fragments for the 4th level - none of the six names seam-check. The item stays open (the 5th-7th levels).",
    },
}
