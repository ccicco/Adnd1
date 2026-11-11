-- oa652: promoted from rules/oa/oanwprof.h (the NON-WEAPON PROFICIENCIES, printed capture pp. 101-103 - the OA non-weapon);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 652,
  "prefix" = "oa652",
  "banner" = {
      "title" = "NON-WEAPON PROFICIENCIES, printed capture pp. 101-103 - the OA non-weapon",
      "provenance" = "proficiencies round census 574 -> 575.  pinned from the 2018 print capture (the settling authority), with the compressed-print capture giving a second independent read of the section - the prose cross-checked doctrine by doctrine between the two passes (the categories, the learning requirements and the base-chance rules opening on capture p. 101 of the print pass, the slot-improvement floor, the magical-item rule, the Akimori example, the optional bonuses and the success-and-failure doctrine printing on p. 102, the contests closing on p. 103; compressed p. 53 carries the full pass). Every doctrine agrees between the passes save one OCR artifact class: the compressed pass renders the slot bonus and the optional bonuses as minus signs (adds - 1 to the die roll, a bonus of - 1, - 2, he is now - 3 on the die roll) where the print pass prints the pluses (+1 per slot, +1 and +2 bonuses, +1 and +3 on the die roll) - the Akimori arithmetic (17 to 16 to 14, the chance FALLS as the bonus rises) would read nonsense with genuine minuses on the die-roll modifiers, so the print signs settle genuine pluses per the R650 plus-as-minus artifact precedent, and the pins carry the print reading. The numbers pin as consts - the four categories, the second-level improvement opening, the +1 slot bonus, the never-below-3 floor, the Akimori example pair (base 17, chances 16 and 14 at third and fourth), the optional +1/+2 bonuses and the informal/formal contest experience at 50 and 100 times the host's level; the categorical rules pin as bools - the only-barbarians rule, the category learning environments, the no-study-times doctrine, the tools-and-guidance requirement, the base-like-to-hit doctrine, the never-improves rule, the magical-only-if-known rule, the strictly-optional rule, the success-and-failure doctrines and the contest rules (formal vs impromptu, the elimination resolution, the inauspicious all-fail rule). Names and text ride comments - Torimatsu Akimori, the calligraphy example, weapon-smith and armorer as the always-roll proficiencies. The Proficiency Tables cross-references (Tables 56 and 58-61) close in their own rounds  the gap census after this round: 104 closed, 131 open - the Non-Weapon Proficiencies box flips (census 574 -> 575); NEXT - R653: Table 56 (Character Proficiencies), capture p. 99, prefix dhn (verify free), audit \"R653 OA character proficiencies audit\", include after rules/oa/oanwprof.h",
    },
  "consts" = { {
      "name" = "dhmCategoryCount",
      "value" = 4,
      "comment" = "the four peaceful-skill categories - Common, Artisan, Court and Barbarian (capture p. 101 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmImproveFromLevel",
      "value" = 2,
      "comment" = "the slot improvement opens at second level or beyond (capture p. 101 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmSlotBonusPerSlot",
      "value" = 1,
      "comment" = "each additional slot spent adds +1 to the die roll - the print pass prints the plus, the compressed renders it as a minus (the R650 artifact class; capture p. 101 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmSuccessFloor",
      "value" = 3,
      "comment" = "the chance of success after all modifiers never less than 3 on 1d20 (capture p. 102 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmAkimoriCalligSlots",
      "value" = 2,
      "comment" = "the Akimori example - two slots to gain calligraphy at first level (capture p. 102 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmAkimoriCalligBase",
      "value" = 17,
      "comment" = "the calligraphy base chance of success 17 (capture p. 102 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmAkimoriChanceAtThird",
      "value" = 16,
      "comment" = "the chance at third level 16 - one additional slot, +1 on the die roll (capture p. 102 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmAkimoriChanceAtFourth",
      "value" = 14,
      "comment" = "the chance at fourth level 14 - two more slots, +3 on the die roll (capture p. 102 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmOptExampleBonus",
      "value" = 1,
      "comment" = "the optional bonus for providing an example of the skill - +1 (capture p. 102 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmOptPerformBonus",
      "value" = 2,
      "comment" = "the optional bonus for actually performing the skill - +2 (capture p. 102 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmInformalContestXPBase",
      "value" = 50,
      "comment" = "the informal contest win - experience 50 times the host's level (capture p. 103 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmFormalContestXPBase",
      "value" = 100,
      "comment" = "the formal contest win - experience 100 times the host's level (capture p. 103 of the print pass; compressed p. 53)",
    } },
  "bools" = { {
      "name" = "dhmOnlyBarbariansLearnBarbarian",
      "value" = true,
      "comment" = "only barbarian characters can learn barbarian proficiencies (capture p. 101 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmCategoriesSetLearningEnvironment",
      "value" = true,
      "comment" = "the categories set the learning environment and assist the DM with NPC proficiencies - the peasant the Common list, the noble the Court list (capture p. 101 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmNoRequiredStudyTimes",
      "value" = true,
      "comment" = "no required times of study for the peaceful proficiencies (capture p. 101 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmLearningNeedsToolsAndGuidance",
      "value" = true,
      "comment" = "learning needs the tools at hand plus an environment with training and guidance from those skilled in the art (capture p. 101 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmContactAmountUndecided",
      "value" = true,
      "comment" = "the amount of contact with the masters purposely left undecided (capture p. 101 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmBaseLikeToHitRoll",
      "value" = true,
      "comment" = "the base number is identical to the to-hit roll - this number or greater on 1d20 succeeds (capture p. 101 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmBaseNeverImprovesWithLevel",
      "value" = true,
      "comment" = "the base number never improves with level, unlike weapon proficiencies (capture p. 101 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmNoLimitOnSlotsSpent",
      "value" = true,
      "comment" = "no limit to the slots spent on a single peaceful proficiency (capture p. 102 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmMagicOnlyIfKnown",
      "value" = true,
      "comment" = "magical proficiency items only help if the proficiency is already known (capture p. 102 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmOptPlayerNotCharacter",
      "value" = true,
      "comment" = "the optional bonuses rest on the actions of the player, not the character (capture p. 102 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmOptStrictlyOptional",
      "value" = true,
      "comment" = "the peaceful proficiency bonus rule is strictly optional (capture p. 102 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmMostNoClearCutCheck",
      "value" = true,
      "comment" = "most peaceful proficiencies have no clear-cut success or failure - no die roll required in normal cases (capture p. 102 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmQualityRollAtBaseSuperior",
      "value" = true,
      "comment" = "the quality roll - at or above the base chance is superior work, below is average or worse (capture p. 102 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmSomeAlwaysRoll",
      "value" = true,
      "comment" = "some proficiencies - weapon-smith, armorer - always roll, noted on the Proficiency Tables (capture p. 102 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmContestsRegularFeature",
      "value" = true,
      "comment" = "contests in the peaceful arts are a regular feature of life in the OA world (capture p. 102 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmVictorsGainHonorAndXP",
      "value" = true,
      "comment" = "the victors gain honor and experience, the defeated lose honor - the outcome moves the social position (capture p. 102 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmFormalAnnouncedInAdvance",
      "value" = true,
      "comment" = "formal contests at court or noble households are announced in advance, with a chosen subject or improvisation (capture p. 102 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmNonattendanceLosesHonor",
      "value" = true,
      "comment" = "non-attendance at a formal contest costs a small loss of honor unless circumstances prevent it (capture p. 103 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmImpromptuSmallerStakes",
      "value" = true,
      "comment" = "impromptu contests carry smaller honor gains and losses than formal affairs (capture p. 103 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmFailureEliminatesContestant",
      "value" = true,
      "comment" = "the contest resolution - a failed die roll eliminates the contestant, repeats until one remains the winner (capture p. 103 of the print pass; compressed p. 53)",
    }, {
      "name" = "dhmAllFailFirstIsInauspicious",
      "value" = true,
      "comment" = "if all entrants fail the first die roll the contest is inauspicious - no winner, no honor changes (capture p. 103 of the print pass; compressed p. 53)",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dhmCategoryCount']() != 4  or m['dhmImproveFromLevel']() != 2  or m['dhmSlotBonusPerSlot']() != 1  or m['dhmSuccessFloor']() != 3  or m['dhmAkimoriCalligSlots']() != 2  or m['dhmAkimoriCalligBase']() != 17  or m['dhmAkimoriChanceAtThird']() != 16  or m['dhmAkimoriChanceAtFourth']() != 14  or m['dhmOptExampleBonus']() != 1  or m['dhmOptPerformBonus']() != 2  or m['dhmInformalContestXPBase']() != 50  or m['dhmFormalContestXPBase']() != 100  or  m['dhmOnlyBarbariansLearnBarbarian']() != 1  or  m['dhmCategoriesSetLearningEnvironment']() != 1  or  m['dhmNoRequiredStudyTimes']() != 1  or  m['dhmLearningNeedsToolsAndGuidance']() != 1  or  m['dhmContactAmountUndecided']() != 1  or  m['dhmBaseLikeToHitRoll']() != 1  or  m['dhmBaseNeverImprovesWithLevel']() != 1  or  m['dhmNoLimitOnSlotsSpent']() != 1  or  m['dhmMagicOnlyIfKnown']() != 1  or  m['dhmOptPlayerNotCharacter']() != 1  or  m['dhmOptStrictlyOptional']() != 1  or  m['dhmMostNoClearCutCheck']() != 1  or  m['dhmQualityRollAtBaseSuperior']() != 1  or  m['dhmSomeAlwaysRoll']() != 1  or  m['dhmContestsRegularFeature']() != 1  or  m['dhmVictorsGainHonorAndXP']() != 1  or  m['dhmFormalAnnouncedInAdvance']() != 1  or  m['dhmNonattendanceLosesHonor']() != 1  or  m['dhmImpromptuSmallerStakes']() != 1  or  m['dhmFailureEliminatesContestant']() != 1  or  m['dhmAllFailFirstIsInauspicious']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dhmCategoryCount']() != 4  or m['dhmOnlyBarbariansLearnBarbarian']() != 1  or m['dhmCategoriesSetLearningEnvironment']() != 1",
      "note" = "the category pins - four categories, only barbarians learn barbarian, the categories set the learning environment",
    }, {
      "expr" = "m['dhmNoRequiredStudyTimes']() != 1  or m['dhmLearningNeedsToolsAndGuidance']() != 1  or m['dhmContactAmountUndecided']() != 1",
      "note" = "the learning pins - no required study times, tools and guidance needed, the contact amount purposely undecided",
    }, {
      "expr" = "m['dhmBaseLikeToHitRoll']() != 1  or m['dhmBaseNeverImprovesWithLevel']() != 1  or m['dhmImproveFromLevel']() != 2  or m['dhmSlotBonusPerSlot']() != 1  or m['dhmNoLimitOnSlotsSpent']() != 1  or m['dhmSuccessFloor']() != 3",
      "note" = "the base-chance pins - like the to-hit roll, never improving with level, +1 per slot from 2nd level, no limit, floor 3",
    }, {
      "expr" = "m['dhmMagicOnlyIfKnown']() != 1",
      "note" = "the magical-item pin - only useful if the proficiency is already known",
    }, {
      "expr" = "m['dhmAkimoriCalligSlots']() != 2  or m['dhmAkimoriCalligBase']() != 17  or m['dhmAkimoriCalligBase']() - 1 !=m['dhmAkimoriChanceAtThird']()  or m['dhmAkimoriChanceAtThird']() - 2 !=m['dhmAkimoriChanceAtFourth']()",
      "note" = "the Akimori calligraphy example pins - two slots, base 17, 16 at third level, 14 at fourth",
    }, {
      "expr" = "m['dhmOptExampleBonus']() != 1  or m['dhmOptPerformBonus']() != 2  or m['dhmOptPlayerNotCharacter']() != 1  or m['dhmOptStrictlyOptional']() != 1",
      "note" = "the optional bonus pins - +1 for an example, +2 for performing, the player not the character, strictly optional",
    }, {
      "expr" = "m['dhmMostNoClearCutCheck']() != 1  or m['dhmQualityRollAtBaseSuperior']() != 1  or m['dhmSomeAlwaysRoll']() != 1",
      "note" = "the success-and-failure pins - most have no clear-cut check, at-or-above base is superior, some always roll",
    }, {
      "expr" = "m['dhmContestsRegularFeature']() != 1  or m['dhmVictorsGainHonorAndXP']() != 1  or m['dhmFormalAnnouncedInAdvance']() != 1  or m['dhmNonattendanceLosesHonor']() != 1  or m['dhmImpromptuSmallerStakes']() != 1",
      "note" = "the contest doctrine pins - a regular feature, victors gain honor and XP, formal announced in advance, non-attendance loss, impromptu smaller stakes",
    }, {
      "expr" = "m['dhmFailureEliminatesContestant']() != 1  or m['dhmAllFailFirstIsInauspicious']() != 1  or m['dhmInformalContestXPBase']() != 50  or m['dhmFormalContestXPBase']() != 100",
      "note" = "the contest resolution pins - failure eliminates, all-fail-first is inauspicious, 50 per level informal, 100 per level formal",
    } },
  "audit" = {
      "label" = "R652 OA non-weapon proficiencies audit",
      "comment" = "OA round thirty-nine (capture pp. 101-103): the non-weapon proficiencies prose - the category and learning doctrine, the base-chance and slot-improvement rules with the Akimori example, the optional peaceful bonuses, the success-and-failure doctrine and the contests",
    },
}
