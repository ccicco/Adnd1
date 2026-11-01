-- ua349: promoted from rules/uaclericspells7.h (the The UA NEW CLERIC SPELLS (p. 42) pins, R349: the 7th-level);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 349,
  "prefix" = "ua349",
  "banner" = {
      "title" = "The UA NEW CLERIC SPELLS (p. 42) pins, R349: the 7th-level",
      "provenance" = "spell descriptions - exaction and succor. With this round all seven levels are pinned (R343 through this round) and the gap item CLOSES. Pin-era pattern (R322): pinned data only - no engine site exists. The R341 continued table prints ZERO 7th-level fragments (the column is empty) - both names pin from the prose alone.  JUDGMENTs (the decode method): - the digit-garble family (established R343, corroborated each round since): the OCR prints 7 where 1 belongs in the stat cells. This round's two 7s decode as 1, both verbatim with doubt pending the PDF: exaction casting \"7 round\" = 1 round (the abjure precedent, R346, prints the same garble); succor casting \"7 day\" = 1 day (no corroboration found - the later editions' prints do not show the casting time in the reachable text). - the exaction stat cells interleave: the Range cell prints blank and the bare value \"1\" prints after the Casting Time line - position-decoded as Range 1 inch (the R346 cloak interleave precedent). - the exaction creature-example sentence garbles: \"including or devas dei- and powerful \"name\" demons ... but not ties of any sort\" - the hyphen fragment \"dei-\" and the tail \"ties\" are the split word DEITIES; decoded: including devas, deities and powerful \"name\" demons, for instance, but not deities of any sort. - the exaction opener prints \"When this spell is\" with the next word lost - decoded as \"When this spell is cast\" (the universal spell-opener formula); flagged. - the exaction mid-prose shatters: \"which is to / upon / perform the required service. / of the / service, the subject creature is transported\" - decoded: the spell acts as a quest upon the creature which is to perform the required service; upon completion of the service, the subject creature is transported to the vicinity of the cleric; the exact words of the shatter stay a hole. - the succor prose runs past a page-header interleave: the banner \"## DRUID SPELLS (1ST LEVEL)\" prints mid-sentence (\"...will be instantly transported to / [banner] / the sanctuary of the cleric...\") - the banner is not content; the sentence is read through it. - the succor reverse shatters: \"transported to the it / iate vicinity of the / of the / item when it is broken\" - decoded: transported to the immediate vicinity of the [bearer] of the item; the possessor word is lost - a hole; the sense (immediate vicinity of the item when broken and the command word said) is pinned. - the curly marks (established R343): the range prints 1 with the right double quote; the summons prints curly double quotes; the pins normalize to ASCII.  OCR holes (the item CLOSES this round; these stay pending the PDF): the exaction opener word; the creature-example garble region; the completion-transport shatter; the succor reverse vicinity shatter (the possessor word); the two family casting-time decodes.",
    },
  "consts" = { {
      "name" = "uac7ExactionName",
      "value" = "Exaction (Evocation - Alteration)",
      "comment" = "---- exaction (Evocation - Alteration), p. 42 ----",
    }, {
      "name" = "uac7ExactionLevel",
      "value" = 7,
      "comment" = "",
    }, {
      "name" = "uac7ExactionRangeInches",
      "value" = 1,
      "comment" = "The Range cell prints blank; the bare \"1\" prints after the Casting Time line - position-decoded as 1 inch.",
    }, {
      "name" = "uac7ExactionCastingTimeRounds",
      "value" = 1,
      "comment" = "The casting time prints \"7 round\" - the digit-garble family decodes 1 round (the abjure precedent); verbatim with doubt pending the PDF.",
    }, {
      "name" = "uac7SuccorName",
      "value" = "Succor (Alteration - Enchantment)\" \" Reversible",
      "comment" = "---- succor (Alteration - Enchantment) Reversible, p. 42 ----",
    }, {
      "name" = "uac7SuccorLevel",
      "value" = 7,
      "comment" = "",
    }, {
      "name" = "uac7SuccorCastingTimeDays",
      "value" = 1,
      "comment" = "The casting time prints \"7 day\" - the family decodes 1 day; no corroboration found - verbatim with doubt pending the PDF.",
    }, {
      "name" = "uac7SuccorObjectExampleCount",
      "value" = 3,
      "comment" = "",
    }, {
      "name" = "uac7SuccorPreparationCostMinGP",
      "value" = 2000,
      "comment" = "The cost of preparing the special item (for either version of the spell) varies from 2,000 to 5,000 gold pieces.",
    }, {
      "name" = "uac7SuccorPreparationCostMaxGP",
      "value" = 5000,
      "comment" = "",
    } },
  "bools" = { {
      "name" = "uac7ExactionComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac7ExactionSaveSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac7ExactionDurationSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac7ExactionAoeOneCreature",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac7ExactionWhenCastOpenerDecoded",
      "value" = true,
      "comment" = "The opener prints \"When this spell is\" with the next word lost - decoded as \"cast\" (the universal formula); flagged.",
    }, {
      "name" = "uac7ExactionOpenerFragmentLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac7ExactionConfrontsExtraplanar",
      "value" = true,
      "comment" = "Confronts some powerful creature from another plane and requires of it some duty or quest.",
    }, {
      "name" = "uac7ExactionRequiresDutyOrQuest",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac7ExactionExamplesIncludeDevasDemons",
      "value" = true,
      "comment" = "The garbled examples decoded: including devas, deities and powerful \"name\" demons, for instance - but not deities of any sort.",
    }, {
      "name" = "uac7ExactionNotOnDeities",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac7ExactionExampleFragmentLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac7ExactionNoEthicalMoralOpposition",
      "value" = true,
      "comment" = "The creature may not be one ethically or morally opposed to the cleric - not evil if the cleric is good, not chaotic if the cleric is lawful.",
    }, {
      "name" = "uac7ExactionTrueNeutralOpposed",
      "value" = true,
      "comment" = "An absolute (true) neutral creature is in effect greatly opposed to both good and evil, and both law and chaos.",
    }, {
      "name" = "uac7ExactionMustKnowOrFairTrade",
      "value" = true,
      "comment" = "The caster must know something about the creature to exact service from it, or else offer some fair trade in return.",
    }, {
      "name" = "uac7ExactionPastFavorAsCause",
      "value" = true,
      "comment" = "If the cleric knows the creature has received a favor from someone of the cleric's alignment, the exaction can name this as cause.",
    }, {
      "name" = "uac7ExactionPledgeIfNoReason",
      "value" = true,
      "comment" = "If no balancing reason for service is known, some valuable gift or service must be pledged in return.",
    }, {
      "name" = "uac7ExactionServiceMustBeReasonable",
      "value" = true,
      "comment" = "The service exacted must be reasonable with respect to the past or promised favor or reward.",
    }, {
      "name" = "uac7ExactionActsAsQuest",
      "value" = true,
      "comment" = "The spell then acts as a quest upon the creature which is to perform the required service.",
    }, {
      "name" = "uac7ExactionTransportedOnCompletion",
      "value" = true,
      "comment" = "The shattered completion clause decoded: upon completion of the service, the subject creature is transported to the vicinity of the cleric; the exact words stay a hole.",
    }, {
      "name" = "uac7ExactionCompletionFragmentLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac7ExactionRewardReturnRequired",
      "value" = true,
      "comment" = "The cleric must then and there return the promised reward - irrevocable cancellation of a past debt or the giving of some service or other material reward.",
    }, {
      "name" = "uac7ExactionCreatureFreedOnReward",
      "value" = true,
      "comment" = "Upon so doing, the creature is instantly freed to return to its own plane.",
    }, {
      "name" = "uac7ExactionFailureInvitesCounterExaction",
      "value" = true,
      "comment" = "Failure to fulfill the promise to the letter: at the very least, the cleric becomes subject to exaction by the subject creature or by its master, liege, etc.",
    }, {
      "name" = "uac7ExactionFailureGrantsSpellImmunity",
      "value" = true,
      "comment" = "At worst, the creature may attack the reneging cleric without fear of any of his or her spells affecting it - total immunity from the spell powers of the cleric so doing.",
    }, {
      "name" = "uac7ExactionMaterialSymbolPlaneMatterScroll",
      "value" = true,
      "comment" = "The material: the cleric's holy/unholy symbol, some matter or substance from the plane of the creature, and knowledge of the creature's nature and/or actions written out on a parchment leaf that is burned to seal the bargain.",
    }, {
      "name" = "uac7SuccorReversible",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac7SuccorComponentsVSM",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac7SuccorRangeTouch",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac7SuccorSaveNone",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac7SuccorDurationSpecial",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac7SuccorAoeOneIndividual",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac7SuccorDweomerInPreparedObject",
      "value" = true,
      "comment" = "Creates a powerful dweomer in some specially prepared object - a string of prayer beads, a small clay tablet, an ivory baton, etc.",
    }, {
      "name" = "uac7SuccorRadiatesMagic",
      "value" = true,
      "comment" = "The object radiates magic, for it contains the power to instantaneously transport its possessor to the sanctuary of the cleric who created its dweomer.",
    }, {
      "name" = "uac7SuccorTransportsPossessorToSanctuary",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac7SuccorGivenWillinglyWithCommandWord",
      "value" = true,
      "comment" = "Once the item is magicked, the cleric must give it willingly to an individual, at the same time informing him or her of a command word.",
    }, {
      "name" = "uac7SuccorBreakItemWithCommandWord",
      "value" = true,
      "comment" = "To use the item, the recipient must speak the command word at the same time that he or she rends or breaks the item.",
    }, {
      "name" = "uac7SuccorWordOfRecallEquivalent",
      "value" = true,
      "comment" = "The individual and all worn and carried gear is instantly transported to the sanctuary of the cleric - just as if capable of speaking a word of recall spell. No other creatures can be affected.",
    }, {
      "name" = "uac7SuccorNoOtherCreatures",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac7SuccorReverseSummons",
      "value" = true,
      "comment" = "The reversed application: enables the cleric to be transported to the immediate vicinity of the item when it is broken and the command word said - the possessor word is lost in the shatter; the sense is pinned.",
    }, {
      "name" = "uac7SuccorReverseVicinityFragmentLost",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac7SuccorClericMayDeclineSummons",
      "value" = true,
      "comment" = "The cleric can choose not to be affected by this summons, deciding at the instant when the transportation is to take place.",
    }, {
      "name" = "uac7SuccorDeclineWastesSpell",
      "value" = true,
      "comment" = "If the cleric declines, the opportunity is gone forever and the spell is wasted.",
    }, {
      "name" = "uac7SuccorEitherVersionCosts",
      "value" = true,
      "comment" = "",
    }, {
      "name" = "uac7ExactionSeamFragmentsOnly",
      "value" = true,
      "comment" = "The R341 continued table: the 7th-level column prints ZERO fragments (the column is empty) - both of this round's names pin from the prose alone.",
    }, {
      "name" = "uac7SpellsPinFromProse",
      "value" = true,
      "comment" = "",
    } },
  "switches" = {},
  "tables" = { {
      "name" = "uac7SuccorObjectExampleName",
      "comment" = "",
      "kind" = "string array",
      "count" = 3,
      "values" = { "a string of prayer beads", "a small clay tablet", "an ivory baton" },
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "strcmp(m['uac7ExactionName'](), \"Exaction (Evocation - Alteration)\") != 0  or  m['uac7ExactionComponentsVSM']() != 1  or m['uac7ExactionLevel']() != 7  or m['uac7ExactionRangeInches']() != 1  or m['uac7ExactionCastingTimeRounds']() != 1  or  m['uac7ExactionSaveSpecial']() != 1  or  m['uac7ExactionDurationSpecial']() != 1  or  m['uac7ExactionAoeOneCreature']() != 1  or  m['uac7ExactionWhenCastOpenerDecoded']() != 1  or  m['uac7ExactionOpenerFragmentLost']() != 1  or  m['uac7ExactionConfrontsExtraplanar']() != 1  or  m['uac7ExactionRequiresDutyOrQuest']() != 1  or  m['uac7ExactionExamplesIncludeDevasDemons']() != 1  or  m['uac7ExactionNotOnDeities']() != 1  or  m['uac7ExactionExampleFragmentLost']() != 1  or  m['uac7ExactionNoEthicalMoralOpposition']() != 1  or  m['uac7ExactionTrueNeutralOpposed']() != 1  or  m['uac7ExactionMustKnowOrFairTrade']() != 1  or  m['uac7ExactionPastFavorAsCause']() != 1  or  m['uac7ExactionPledgeIfNoReason']() != 1  or  m['uac7ExactionServiceMustBeReasonable']() != 1  or  m['uac7ExactionActsAsQuest']() != 1  or  m['uac7ExactionTransportedOnCompletion']() != 1  or  m['uac7ExactionCompletionFragmentLost']() != 1  or  m['uac7ExactionRewardReturnRequired']() != 1  or  m['uac7ExactionCreatureFreedOnReward']() != 1  or  m['uac7ExactionFailureInvitesCounterExaction']() != 1  or  m['uac7ExactionFailureGrantsSpellImmunity']() != 1  or  m['uac7ExactionMaterialSymbolPlaneMatterScroll']() != 1",
      "note" = "U1: exaction",
    }, {
      "expr" = "strcmp(m['uac7SuccorName'](), \"Succor (Alteration - Enchantment)\" \" Reversible\") != 0  or  m['uac7SuccorReversible']() != 1  or  m['uac7SuccorComponentsVSM']() != 1  or m['uac7SuccorLevel']() != 7  or m['uac7SuccorCastingTimeDays']() != 1  or  m['uac7SuccorRangeTouch']() != 1  or  m['uac7SuccorSaveNone']() != 1  or  m['uac7SuccorDurationSpecial']() != 1  or  m['uac7SuccorAoeOneIndividual']() != 1  or  m['uac7SuccorDweomerInPreparedObject']() != 1  or m['uac7SuccorObjectExampleCount']() != 3  or m['uac7SuccorObjectExampleName'](i) == 0  or  m['uac7SuccorRadiatesMagic']() != 1  or  m['uac7SuccorTransportsPossessorToSanctuary']() != 1  or  m['uac7SuccorGivenWillinglyWithCommandWord']() != 1  or  m['uac7SuccorBreakItemWithCommandWord']() != 1  or  m['uac7SuccorWordOfRecallEquivalent']() != 1  or  m['uac7SuccorNoOtherCreatures']() != 1  or  m['uac7SuccorReverseSummons']() != 1  or  m['uac7SuccorReverseVicinityFragmentLost']() != 1  or  m['uac7SuccorClericMayDeclineSummons']() != 1  or  m['uac7SuccorDeclineWastesSpell']() != 1  or m['uac7SuccorPreparationCostMinGP']() != 2000  or m['uac7SuccorPreparationCostMaxGP']() != 5000  or  m['uac7SuccorEitherVersionCosts']() != 1",
      "note" = "U2: succor",
    }, {
      "expr" = "m['uastClericFragCount'](7) != 0  or m['uastClericFragName'](7, 0)[0] != 0  or  m['uac7ExactionSeamFragmentsOnly']() != 1  or  m['uac7SpellsPinFromProse']() != 1",
      "note" = "U3: the seam",
    } },
  "audit" = {
      "label" = "R349: the UA new cleric 7th level spells pin audit",
      "comment" = "The UA NEW CLERIC SPELLS (p. 42), the 7th level - exaction (the duty or quest upon a powerful extraplanar creature, the alignment gates, the past-favor or pledge causality, the bargain consequences) and succor (the prepared-object dweomer, the command-word transport, the summons reverse, the 2,000-5,000 gp preparation cost). The digit-garble family decodes this round's two 7s as 1 (the exaction casting matches the abjure precedent; the succor day decode stays verbatim with doubt); the exaction range position-decodes from the interleave. The R341 continued table prints zero 7th-level fragments - both names pin from the prose. The item CLOSES this round - all seven levels pinned.",
    },
}
