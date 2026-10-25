    // ---- R652 OA non-weapon proficiencies audit ----
    // OA round thirty-nine (capture pp. 101-103): the non-weapon
    // proficiencies prose - the category and learning doctrine, the
    // base-chance and slot-improvement rules with the Akimori example, the
    // optional peaceful bonuses, the success-and-failure doctrine and the
    // contests
    {
        using namespace rules;
        int bad = 0;
    if (dhmCategoryCount() != 4
            || dhmImproveFromLevel() != 2
            || dhmSlotBonusPerSlot() != 1
            || dhmSuccessFloor() != 3
            || dhmAkimoriCalligSlots() != 2
            || dhmAkimoriCalligBase() != 17
            || dhmAkimoriChanceAtThird() != 16
            || dhmAkimoriChanceAtFourth() != 14
            || dhmOptExampleBonus() != 1
            || dhmOptPerformBonus() != 2
            || dhmInformalContestXPBase() != 50
            || dhmFormalContestXPBase() != 100
            || !dhmOnlyBarbariansLearnBarbarian()
            || !dhmCategoriesSetLearningEnvironment()
            || !dhmNoRequiredStudyTimes()
            || !dhmLearningNeedsToolsAndGuidance()
            || !dhmContactAmountUndecided()
            || !dhmBaseLikeToHitRoll()
            || !dhmBaseNeverImprovesWithLevel()
            || !dhmNoLimitOnSlotsSpent()
            || !dhmMagicOnlyIfKnown()
            || !dhmOptPlayerNotCharacter()
            || !dhmOptStrictlyOptional()
            || !dhmMostNoClearCutCheck()
            || !dhmQualityRollAtBaseSuperior()
            || !dhmSomeAlwaysRoll()
            || !dhmContestsRegularFeature()
            || !dhmVictorsGainHonorAndXP()
            || !dhmFormalAnnouncedInAdvance()
            || !dhmNonattendanceLosesHonor()
            || !dhmImpromptuSmallerStakes()
            || !dhmFailureEliminatesContestant()
            || !dhmAllFailFirstIsInauspicious()
        )
            ++bad;
        // the category pins - four categories, only barbarians learn
        // barbarian, the categories set the learning environment
    if (dhmCategoryCount() != 4
            || dhmOnlyBarbariansLearnBarbarian() != 1
            || dhmCategoriesSetLearningEnvironment() != 1
        )
            ++bad;
        // the learning pins - no required study times, tools and guidance
        // needed, the contact amount purposely undecided
    if (dhmNoRequiredStudyTimes() != 1
            || dhmLearningNeedsToolsAndGuidance() != 1
            || dhmContactAmountUndecided() != 1
        )
            ++bad;
        // the base-chance pins - like the to-hit roll, never improving with
        // level, +1 per slot from 2nd level, no limit, floor 3
    if (dhmBaseLikeToHitRoll() != 1
            || dhmBaseNeverImprovesWithLevel() != 1
            || dhmImproveFromLevel() != 2
            || dhmSlotBonusPerSlot() != 1
            || dhmNoLimitOnSlotsSpent() != 1
            || dhmSuccessFloor() != 3
        )
            ++bad;
        // the magical-item pin - only useful if the proficiency is already
        // known
    if (dhmMagicOnlyIfKnown() != 1
        )
            ++bad;
        // the Akimori calligraphy example pins - two slots, base 17, 16 at
        // third level, 14 at fourth
    if (dhmAkimoriCalligSlots() != 2
            || dhmAkimoriCalligBase() != 17
            || dhmAkimoriCalligBase() - 1 != dhmAkimoriChanceAtThird()
            || dhmAkimoriChanceAtThird() - 2 != dhmAkimoriChanceAtFourth()
        )
            ++bad;
        // the optional bonus pins - +1 for an example, +2 for performing, the
        // player not the character, strictly optional
    if (dhmOptExampleBonus() != 1
            || dhmOptPerformBonus() != 2
            || dhmOptPlayerNotCharacter() != 1
            || dhmOptStrictlyOptional() != 1
        )
            ++bad;
        // the success-and-failure pins - most have no clear-cut check,
        // at-or-above base is superior, some always roll
    if (dhmMostNoClearCutCheck() != 1
            || dhmQualityRollAtBaseSuperior() != 1
            || dhmSomeAlwaysRoll() != 1
        )
            ++bad;
        // the contest doctrine pins - a regular feature, victors gain honor
        // and XP, formal announced in advance, non-attendance loss, impromptu
        // smaller stakes
    if (dhmContestsRegularFeature() != 1
            || dhmVictorsGainHonorAndXP() != 1
            || dhmFormalAnnouncedInAdvance() != 1
            || dhmNonattendanceLosesHonor() != 1
            || dhmImpromptuSmallerStakes() != 1
        )
            ++bad;
        // the contest resolution pins - failure eliminates, all-fail-first is
        // inauspicious, 50 per level informal, 100 per level formal
    if (dhmFailureEliminatesContestant() != 1
            || dhmAllFailFirstIsInauspicious() != 1
            || dhmInformalContestXPBase() != 50
            || dhmFormalContestXPBase() != 100
        )
            ++bad;
        printf("R652 OA non-weapon proficiencies audit: bad %d\n", bad);
        if (bad) return 1;
    }
