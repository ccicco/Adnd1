    // ---- R553 DSG story elements tail audit ----
    // The story elements tail pins printed pp. 107-108: the foreshadowing
    // tail (the variety, the player-given invitations, dreams, the
    // fortune-teller, the anonymous message, the town rumors), Mystery (the
    // curiosity motivator, the who-done-it, the secret antagonist with its
    // clue trail - the vampire lair, the campaign mysteries of unknown
    // parentage and the vanished community, the background questions, the
    // dying messenger of Eric of Calrede, the speak-with-dead caveat),
    // Challenge (tailored to player types, the encounter role in game balance
    // - random and introductory light, climactic and milestone to the utmost
    // limits, the Hit Dice and damage rough balance, the tactics and position
    // and luck, the intelligent-play sufficiency, the changeable screen
    // dice), Reward (the accomplishment basis, the tracked count, the
    // during-adventure handouts), Magical items (the one-or-two per level
    // lid, the disposable generosity, the class-directed items, the
    // armed-to-the-teeth warning, the described and named items, the Sathas
    // Sundown sage, the item limitations, the story-part doctrine), Wealth
    // (the drains, the kept XP, the low-value bulks, the rare gemstones, the
    // spending sprees), Discoveries (the pieced-together clues), Gratitude
    // (the high king's debt, the case-by-case extent, the explicit promises,
    // the beggar and barmaid favors), Accomplishment (the intrinsic reward,
    // the good-deed cleric, the free implementation), Experience Points (the
    // adjustable DMG amounts, the landslide penalty, the tentative awards,
    // the restructured system, the optional magic-item XP), and Moral (the
    // consequences doctrine, the cooperation, the killer consequences, the
    // accomplishment-merits-reward, the story-for-a-moral).
    {
        using namespace rules;
        int bad = 0;
    if (dcfPermanentPerLevelMin() != 1
            || dcfPermanentPerLevelMax() != 2
            || dcfPirateShipXP() != 1000
            || !dcfForeshadowVariety()
            || !dcfForeshadowPlayerInvitation()
            || !dcfForeshadowDreams()
            || !dcfForeshadowFortuneteller()
            || !dcfForeshadowAnonymousMessage()
            || !dcfForeshadowRumors()
            || !dcfMysteryMotivates()
            || !dcfMysteryWhodunit()
            || !dcfMysteryUnknownFoe()
            || !dcfMysteryVampireLair()
            || !dcfMysteryCampaign()
            || !dcfMysteryBackground()
            || !dcfMysteryDyingMessenger()
            || !dcfMysterySpeakWithDead()
            || !dcfChallengeFit()
            || !dcfChallengeCombat()
            || !dcfChallengeNegotiation()
            || !dcfChallengeFeedback()
            || !dcfChallengeBalanceRole()
            || !dcfChallengeHDBalance()
            || !dcfChallengeIntelligentPlay()
            || !dcfChallengeScreenDice()
            || !dcfRewardAccomplishment()
            || !dcfRewardBalance()
            || !dcfRewardVariety()
            || !dcfRewardDuringAdventure()
            || !dcfMagicSparingly()
            || !dcfMagicClassDirected()
            || !dcfMagicLid()
            || !dcfMagicDescribed()
            || !dcfMagicSageExample()
            || !dcfMagicLimitations()
            || !dcfMagicStoryPart()
            || !dcfWealthStandard()
            || !dcfWealthDrains()
            || !dcfWealthXPKept()
            || !dcfWealthLowValueBulks()
            || !dcfWealthSpendingSprees()
            || !dcfDiscoveryInfo()
            || !dcfDiscoveryPieced()
            || !dcfDiscoveryDesign()
            || !dcfGratitudeDebt()
            || !dcfGratitudeCaseByCase()
            || !dcfGratitudePromise()
            || !dcfGratitudeHumble()
            || !dcfAccomplishmentIntrinsic()
            || !dcfAccomplishmentGoodDeeds()
            || !dcfAccomplishmentFree()
            || !dcfXPMechanic()
            || !dcfXPAdjustable()
            || !dcfXPLandslide()
            || !dcfXPTentative()
            || !dcfXPRestructure()
            || !dcfXPMagicOptional()
            || !dcfMoralStrengthens()
            || !dcfMoralConsequences()
            || !dcfMoralCooperation()
            || !dcfMoralKillers()
            || !dcfMoralAccomplishmentMerits()
            || !dcfMoralStoryForMoral()
        )
            ++bad;
        // the lid: one or two permanent magical items per level of
        // experience.
    if (dcfPermanentPerLevelMin() != 1
            || dcfPermanentPerLevelMax() != 2
        )
            ++bad;
        // the tentative award: 1,000 XP for each pirate ship burned.
    if (dcfPirateShipXP() != 1000
        )
            ++bad;
        // the foreshadowing tail: dreams and rumors.
    if (dcfForeshadowDreams() != 1
            || dcfForeshadowRumors() != 1
        )
            ++bad;
        // the mystery: the secret foe and the vampire-lair clues.
    if (dcfMysteryVampireLair() != 1
            || dcfMysteryUnknownFoe() != 1
        )
            ++bad;
        // the challenge: the encounter role and the changeable screen dice.
    if (dcfChallengeBalanceRole() != 1
            || dcfChallengeScreenDice() != 1
        )
            ++bad;
        // the magical items: the lid and the story part.
    if (dcfMagicLid() != 1
            || dcfMagicStoryPart() != 1
        )
            ++bad;
        // the wealth: the drains and the kept XP.
    if (dcfWealthDrains() != 1
            || dcfWealthXPKept() != 1
        )
            ++bad;
        // the moral: the killer consequences and the story-for-a-moral.
    if (dcfMoralKillers() != 1
            || dcfMoralStoryForMoral() != 1
        )
            ++bad;
        printf("R553 DSG story elements tail audit: bad %d\n", bad);
        if (bad) return 1;
    }
