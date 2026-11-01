-- ua348: promoted from rules/uaclericspells6.h (the The UA NEW CLERIC SPELLS (p. 41) pins, R348: the 6th-level);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 348,
  "prefix" = "ua348",
  "banner" = {
      "title" = "The UA NEW CLERIC SPELLS (p. 41) pins, R348: the 6th-level",
      "provenance" = "spell descriptions - forbiddance and heroes feast. Only two spells print at this level; the 7th (p. 42) pins next round. Pin-era pattern (R322): pinned data only - no engine site exists. The R341 continued table prints four 6th-level fragments (Conjure Animals, Find The Path, Speak With Monsters, Stone Tell) - neither of this round's two names seam-checks; they pin from the prose alone.  JUDGMENTs (the decode method): - the forbiddance name header never prints: the section runs straight from \"## Sixth Level Spells:\" into \"Components: V, S, M\". The spell is identified by its near-verbatim 2e descendant (\"This spell can be used to secure a consecrated area... locked by a password\", good/evil weighing heavier than law/chaos) as FORBIDDANCE, school Abjuration per the same source - an external decode, flagged *Lost, pending the PDF. - the digit-garble family (established R343, corroborated each round since): the OCR prints 7 where 1 belongs in the stat cells. This round's two 7s decode as 1, BOTH corroborated: heroes feast casting \"7 turn\" = 1 turn (the later editions print a 10-minute = 1-turn casting time), and heroes feast duration \"7 hour\" = 1 hour (the prose: \"The feast takes one full hour to consume\" - the dweomer lasts the hour of the feast). - the forbiddance stat cells carry genuine 6s (not the family): Level 6, Range 3 inches, Casting Time 6 rounds, Area of Effect 6 cubic inches per level - the level-matching pattern holds; pinned verbatim. - the forbiddance AoE prints \"6 cubic \"/level\" - the stray straight quote is OCR noise for the inch mark; decoded as 6 cubic inches per level (the game-scale inch, as the range cells). - the curly marks (established R343): the range cells print 3 and 1 with the right double quote; the names print the curly apostrophe (Heroes feast, the caster spell's effect); the pins normalize to ASCII. - the forbiddance prose carries two shattered regions: (1) \"Intruders who enter by making saving throws will [?] uneasy and tense\" - the verb lost; (2) the material sentence: \"In addition to the cler- / include / water, / symbol, / and iron/sulfur\" - decoded: in addition to the cleric's [holy/unholy symbol], the components include [holy/unholy] water, the symbol, and iron/sulfur; both regions flagged, sense pinned.  OCR holes (the item stays open - the 7th level pins next round; these stay pending the PDF): the forbiddance name and school header (externally decoded); the uneasy-verb fragment; the material-sentence fragment region.",
    },
  "consts" = { {
      "name" = "uac6ForbidName",
      "value" = "Forbiddance (Abjuration)",
      "comment" = "---- forbiddance (Abjuration, decoded), p. 41 ---- The name header never prints - identified by the near-verbatim 2e descendant text; school per the same.",
    }, {
      "name" = "uac6ForbidLevel",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uac6ForbidRangeInches",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uac6ForbidCastingTimeRounds",
      "value" = 6,
      "comment" = "A genuine 6, not the digit-garble family - the level pattern holds; pinned verbatim.",
    }, {
      "name" = "uac6ForbidAoeCubicInchesPerLevel",
      "value" = 6,
      "comment" = "The AoE prints \"6 cubic \"/level\" - the stray quote is noise for the inch mark.",
    }, {
      "name" = "uac6ForbidDiffEthicsDamageMin",
      "value" = 2,
      "comment" = "",
    }, {
      "name" = "uac6ForbidDiffEthicsDamageMax",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uac6ForbidDiffMoralsDamageMin",
      "value" = 4,
      "comment" = "",
    }, {
      "name" = "uac6ForbidDiffMoralsDamageMax",
      "value" = 24,
      "comment" = "",
    }, {
      "name" = "uac6FeastName",
      "value" = "Heroes' Feast (Evocation)",
      "comment" = "---- heroes feast (Evocation), p. 41 ---- The name prints the curly apostrophe; the pin normalizes to ASCII (the established decode).",
    }, {
      "name" = "uac6FeastLevel",
      "value" = 6,
      "comment" = "",
    }, {
      "name" = "uac6FeastRangeInches",
      "value" = 1,
      "comment" = "",
    }, {
      "name" = "uac6FeastCastingTimeTurns",
      "value" = 1,
      "comment" = "The casting time prints \"7 turn\" - the family decodes 1 turn, corroborated by the later editions' 10-minute (1-turn) casting time.",
    }, {
      "name" = "uac6FeastDurationHours",
      "value" = 1,
      "comment" = "The duration prints \"7 hour\" - the family decodes 1 hour, corroborated by the one-full-hour prose: the dweomer lasts the hour of the feast.",
    }, {
      "name" = "uac6FeastPoisonImmunityHours",
      "value" = 12,
      "comment" = "Immune to poison for 12 hours.",
    }, {
      "name" = "uac6FeastHealDamageMin",
      "value" = 5,
      "comment" = "Healed of 5-8 points of damage after imbibing the nectar-like beverage.",
    }, {
      "name" = "uac6FeastHealDamageMax",
      "value" = 8,
      "comment" = "",
    }, {
      "name" = "uac6FeastBlessHours",
      "value" = 12,
      "comment" = "",
    }, {
      "name" = "uac6FeastConsumeHours",
      "value" = 1,
      "comment" = "The feast takes one full hour to consume; the beneficial effects do not set in until after this hour is over.",
    } },
  "bools" = { {
      "name" = "uac6ForbidNameHeaderLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac6ForbidComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac6ForbidDurationPermanent",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac6ForbidSaveSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac6ForbidRequiresConsecratedArea",
      "value" = true,
      "comment" = "Usable only to secure a consecrated area (cf. the ceremony spell).",
    }, {
      "name" = "uac6ForbidCfCeremonySpell",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac6ForbidBasedOnEthicsAndMorals",
      "value" = true,
      "comment" = "The effect on the enchanted area is based on the ethics (law/chaos) and morals (good/evil) of those trying to enter it, relative to the caster's.",
    }, {
      "name" = "uac6ForbidIdenticalNeedsPassword",
      "value" = true,
      "comment" = "Identical morals and ethics: cannot enter the area unless the password is known (no saving throw).",
    }, {
      "name" = "uac6ForbidIdenticalNoSave",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac6ForbidDiffEthicsSaveVsSpell",
      "value" = true,
      "comment" = "Different ethics: save versus spell to enter the area; if failed, take 2-12 points of damage.",
    }, {
      "name" = "uac6ForbidDiffMoralsSaveVsSpell",
      "value" = true,
      "comment" = "Different morals: save versus spell to enter the area; if failed, take 4-24 points of damage.",
    }, {
      "name" = "uac6ForbidFailedSaveBarsEntry",
      "value" = true,
      "comment" = "Once a saving throw is failed, an intruder can never enter the forbidden area until the dweomer ceases.",
    }, {
      "name" = "uac6ForbidEffectsCumulative",
      "value" = true,
      "comment" = "Effects are cumulative, and multiple required saving throws are certainly possible.",
    }, {
      "name" = "uac6ForbidMultipleSavesPossible",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac6ForbidCasterImmune",
      "value" = true,
      "comment" = "The caster is immune to the spell's effect.",
    }, {
      "name" = "uac6ForbidIntrudersUneasyTense",
      "value" = true,
      "comment" = "Intruders who enter by making saving throws will [verb lost] be uneasy and tense, despite their success - the fragment region stays a hole.",
    }, {
      "name" = "uac6ForbidUneasyVerbFragmentLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac6ForbidMaterialWaterSymbolIronSulfur",
      "value" = true,
      "comment" = "The shattered material sentence decoded: in addition to the cleric's symbol, the components include holy/unholy water, the symbol, and iron/sulfur.",
    }, {
      "name" = "uac6ForbidMaterialFragmentLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac6ForbidSeamFragmentsOnly",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac6FeastComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac6FeastSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac6FeastAoeOnePerLevel",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac6FeastServesOnePerLevel",
      "value" = true,
      "comment" = "Enables the cleric to bring forth a great feast serving as many creatures as the cleric has levels of experience.",
    }, {
      "name" = "uac6FeastCreatesTableService",
      "value" = true,
      "comment" = "The spell creates a magnificent table, chairs, service, and all the necessary food and drink.",
    }, {
      "name" = "uac6FeastCuresAllDiseases",
      "value" = true,
      "comment" = "Those partaking are cured of all diseases.",
    }, {
      "name" = "uac6FeastAmbrosiaEqualsBless",
      "value" = true,
      "comment" = "The ambrosia-like food equals a bless spell that lasts for 12 hours.",
    }, {
      "name" = "uac6FeastImmuneFearHopePanic",
      "value" = true,
      "comment" = "During this period, the consumers are immune to fear, hopelessness, and panic.",
    }, {
      "name" = "uac6FeastEffectsAfterTheHour",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac6FeastInterruptRuinsAll",
      "value" = true,
      "comment" = "If the feast is interrupted for any reason, the spell is ruined and all effects of the dweomer are negated.",
    }, {
      "name" = "uac6FeastMaterialSymbolHoney",
      "value" = true,
      "comment" = "The material: the holy/unholy symbol and specially fermented honey taken from the cells of bee larvae destined for royal status.",
    }, {
      "name" = "uac6FeastHoneyRoyalLarvae",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac6SpellsPinFromProse",
      "value" = true,
      "comment" = "The R341 continued table: the 6th-level column prints four fragments (Conjure Animals, Find The Path, Speak With Monsters, Stone Tell) - neither of this round's two names seam-checks; they pin from the prose alone.",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "strcmp(m['uac6ForbidName'](), \"Forbiddance (Abjuration)\") != 0  or  m['uac6ForbidNameHeaderLost']() != 1  or  m['uac6ForbidComponentsVSM']() != 1  or m['uac6ForbidLevel']() != 6  or m['uac6ForbidRangeInches']() != 3  or m['uac6ForbidCastingTimeRounds']() != 6  or  m['uac6ForbidDurationPermanent']() != 1  or  m['uac6ForbidSaveSpecial']() != 1  or m['uac6ForbidAoeCubicInchesPerLevel']() != 6  or  m['uac6ForbidRequiresConsecratedArea']() != 1  or  m['uac6ForbidCfCeremonySpell']() != 1  or  m['uac6ForbidBasedOnEthicsAndMorals']() != 1  or  m['uac6ForbidIdenticalNeedsPassword']() != 1  or  m['uac6ForbidIdenticalNoSave']() != 1  or  m['uac6ForbidDiffEthicsSaveVsSpell']() != 1  or m['uac6ForbidDiffEthicsDamageMin']() != 2  or m['uac6ForbidDiffEthicsDamageMax']() != 12  or  m['uac6ForbidDiffMoralsSaveVsSpell']() != 1  or m['uac6ForbidDiffMoralsDamageMin']() != 4  or m['uac6ForbidDiffMoralsDamageMax']() != 24  or  m['uac6ForbidFailedSaveBarsEntry']() != 1  or  m['uac6ForbidEffectsCumulative']() != 1  or  m['uac6ForbidMultipleSavesPossible']() != 1  or  m['uac6ForbidCasterImmune']() != 1  or  m['uac6ForbidIntrudersUneasyTense']() != 1  or  m['uac6ForbidUneasyVerbFragmentLost']() != 1  or  m['uac6ForbidMaterialWaterSymbolIronSulfur']() != 1  or  m['uac6ForbidMaterialFragmentLost']() != 1  or  m['uac6ForbidSeamFragmentsOnly']() != 1",
      "note" = "U1: forbiddance",
    }, {
      "expr" = "strcmp(m['uac6FeastName'](), \"Heroes' Feast (Evocation)\") != 0  or  m['uac6FeastComponentsVSM']() != 1  or m['uac6FeastLevel']() != 6  or m['uac6FeastRangeInches']() != 1  or m['uac6FeastCastingTimeTurns']() != 1  or m['uac6FeastDurationHours']() != 1  or  m['uac6FeastSaveNone']() != 1  or  m['uac6FeastAoeOnePerLevel']() != 1  or  m['uac6FeastServesOnePerLevel']() != 1  or  m['uac6FeastCreatesTableService']() != 1  or  m['uac6FeastCuresAllDiseases']() != 1  or m['uac6FeastPoisonImmunityHours']() != 12  or m['uac6FeastHealDamageMin']() != 5  or m['uac6FeastHealDamageMax']() != 8  or  m['uac6FeastAmbrosiaEqualsBless']() != 1  or m['uac6FeastBlessHours']() != 12  or  m['uac6FeastImmuneFearHopePanic']() != 1  or m['uac6FeastConsumeHours']() != 1  or  m['uac6FeastEffectsAfterTheHour']() != 1  or  m['uac6FeastInterruptRuinsAll']() != 1  or  m['uac6FeastMaterialSymbolHoney']() != 1  or  m['uac6FeastHoneyRoyalLarvae']() != 1",
      "note" = "U2: heroes feast",
    }, {
      "expr" = "m['uastClericFragCount'](6) != 4  or strcmp(m['uastClericFragName'](6, i), n[i]) != 0  or  m['uac6ForbidSeamFragmentsOnly']() != 1  or  m['uac6SpellsPinFromProse']() != 1",
      "note" = "U3: the seam",
    } },
  "audit" = {
      "label" = "R348: the UA new cleric 6th level spells pin audit",
      "comment" = "The UA NEW CLERIC SPELLS (p. 41), the 6th level - only two spells print at this level: forbiddance (the name header never prints - identified by the near-verbatim 2e descendant; the ethics/morals entry ladder with the password gate) and heroes feast (the twelve-hour benefits and the one-hour consume rule). The digit-garble family decodes this round's two 7s as 1 - both corroborated (the later editions' 1-turn casting time; the one-full-hour prose); the forbiddance 6s stay genuine. The R341 continued table prints four 6th-level fragments - neither name seam-checks. The item stays open (the 7th level).",
    },
}
