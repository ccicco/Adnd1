    // ---- R788 halfling deity prose audit ----
    // THE HALFLING DEITY PROSE - part 3 of the Appendix S
    // description-paragraph close. The archive.org full-text OCR of pp.
    // 116-118 reads the four halfling blocks scan-clean: the Sheela festivals
    // and the entangle craft, the Arvoreen unseen summons of halfling heroes,
    // the Cyrrollalee furniture animation and home trust, and the Brandobaris
    // dust sling, escape dagger, and reward risks. The stat-block numerics
    // stay R406/R783; the paragraph facts ride rules/uadeityprose3.h.
    {
        using namespace rules;
        int bad = 0;
    if (udp3ProseRound() != 788
            || udp3StatblockFeederRound() != 406
            || udp3HalflingDeityCount() != 4
            || udp3PantheonWorshipMin() != 4
            || udp3PantheonWorshipMax() != 5
            || udp3GreaterDeityCount() != 1
            || udp3SheMajorCelebrations() != 2
            || udp3SheFestivalAvgDays() != 10
            || udp3SheEntangleGrantPct() != 1
            || udp3SheEntangleLevel() != 6
            || udp3SheNeutralEntangleLevel() != 12
            || udp3SheStaffBonus() != 4
            || udp3SheStaffDamageMin() != 2
            || udp3SheStaffDamageMax() != 16
            || udp3SheStaffCraftSegments() != 1
            || udp3SheEntanglePerRound() != 1
            || udp3SheDoubleCastSpeedDiv() != 4
            || udp3SheSuccessiveDamageMin() != 1
            || udp3SheSuccessiveDamageMax() != 4
            || udp3ArvFirstAttackDamageDiv() != 2
            || udp3ArvUnseenRoundsMin() != 4
            || udp3ArvUnseenRoundsMax() != 16
            || udp3ArvSwordBonus() != 4
            || udp3ArvSummonPerDay() != 1
            || udp3ArvSummonMin() != 10
            || udp3ArvSummonMax() != 40
            || udp3ArvSummonHeroLevel() != 4
            || udp3ArvSummonAc() != 4
            || udp3ArvSummonHp() != 25
            || udp3CyrAnimateRadiusInches() != 6
            || udp3CyrAnimateClericLevel() != 20
            || udp3CyrAnimateVolumeMax() != 20
            || udp3CyrAnimateRounds() != 20
            || udp3CyrAnimatePerDay() != 3
            || udp3CyrFurnitureChancePct() != 2
            || udp3CyrFurnitureVolumeMax() != 5
            || udp3CyrFurnitureRounds() != 5
            || udp3CyrFurnitureAttacksPerRound() != 1
            || udp3CyrGiftLifetimeMax() != 2
            || udp3CyrServiceDayOfMonth() != 1
            || udp3BraDaggerBonus() != 3
            || udp3BraSlingBonus() != 4
            || udp3BraDustRangeMaxInches() != 48
            || udp3BraDustRangeShortInches() != 24
            || udp3BraDustRangeMediumInches() != 36
            || udp3BraDustSaveMod() != -6
            || udp3BraSleepTurnsMin() != 6
            || udp3BraSleepTurnsMax() != 36
            || udp3BraRewardChancePct() != 5
            || udp3BraRewardLevelMax() != 10
            || udp3BraRewardLifetimeMax() != 1
            || udp3BraMeetChancePctPerLevel() != 1
            || udp3BraMeetLevelMin() != 11
            || !udp3PantheonOnlyGoodPowers()
            || !udp3YondallaTopAuthority()
            || !udp3YondallaFuneralProtector()
            || !udp3FemaleDeitiesStronger()
            || !udp3GreenFieldsOnSevenHeavens()
            || !udp3PantheonSheelaConcordant()
            || !udp3PantheonBrandobarisRoams()
            || !udp3UrogalanNeutralEarthGod()
            || !udp3UrogalanJudgesDead()
            || !udp3UrogalanOnConcordant()
            || !udp3PantheonPledgedTogether()
            || !udp3SheFlowerDressed()
            || !udp3SheFieldsGrowWhenSings()
            || !udp3SheWeatherToFaithful()
            || !udp3SheDroughtFloodsToPoorly()
            || !udp3SheFollowersWearFlower()
            || !udp3SheFollowersWorkHarmony()
            || !udp3SheSeedingFestival()
            || !udp3SheHighHarvestFestival()
            || !udp3SheRevelryAtFestivals()
            || !udp3SheQuestsGrowHarder()
            || !udp3SheOneEntangleAtATime()
            || !udp3SheEntangleCumulative()
            || !udp3SheConstrictionNoSave()
            || !udp3ArvNeverAttacksFirst()
            || !udp3ArvFirstMagicReflected()
            || !udp3ArvInvisibleAtWill()
            || !udp3ArvOnlyFightsIfAttacked()
            || !udp3ArvFightsToFinish()
            || !udp3ArvThievingAgainstEnemies()
            || !udp3ArvNoStealingFromHalflings()
            || !udp3ArvHeroesObeyImplicitly()
            || !udp3ArvHeroesSwordAndBow()
            || !udp3ArvPatronOfFighters()
            || !udp3CyrDeityOfFriendship()
            || !udp3CyrHomeProtectorOpenDwelling()
            || !udp3CyrPeasantAppearance()
            || !udp3CyrEnemyOfTrustBreakers()
            || !udp3CyrAnimationPersists()
            || !udp3CyrGiftRequiresService()
            || !udp3CyrAnyFighterWeapon()
            || !udp3CyrFollowersPlainHomes()
            || !udp3BraSilenceUnhearable()
            || !udp3BraHidesExceptTrueSeeing()
            || !udp3BraDaggerPointsEscape()
            || !udp3BraMazeImmuneWithDagger()
            || !udp3BraDustBallHarmless()
            || !udp3BraTricksterRascal()
            || !udp3BraMeetsAsFellowThief()
            || !udp3BraIdentityOnlyAfter()
            || !udp3BraIdentityOnlyToFollowers()
            || !udp3BraNonWorshippersLoseItems()
        )
            ++bad;
        // the round consts (the prose round, the feeder round, the census)
    if (udp3ProseRound() != 788
            || udp3StatblockFeederRound() != 406
            || udp3HalflingDeityCount() != 4
            || udp3PantheonWorshipMin() != 4
            || udp3PantheonWorshipMax() != 5
            || udp3GreaterDeityCount() != 1
        )
            ++bad;
        // the halfling pantheon prose walk
    if (udp3PantheonOnlyGoodPowers() != 1
            || udp3YondallaTopAuthority() != 1
            || udp3YondallaFuneralProtector() != 1
            || udp3FemaleDeitiesStronger() != 1
            || udp3GreenFieldsOnSevenHeavens() != 1
            || udp3PantheonSheelaConcordant() != 1
            || udp3PantheonBrandobarisRoams() != 1
            || udp3UrogalanNeutralEarthGod() != 1
            || udp3UrogalanJudgesDead() != 1
            || udp3UrogalanOnConcordant() != 1
            || udp3PantheonPledgedTogether() != 1
        )
            ++bad;
        // the Sheela Peryroyl prose walk
    if (udp3SheMajorCelebrations() != 2
            || udp3SheFestivalAvgDays() != 10
            || udp3SheEntangleGrantPct() != 1
            || udp3SheEntangleLevel() != 6
            || udp3SheNeutralEntangleLevel() != 12
            || udp3SheStaffBonus() != 4
            || udp3SheStaffDamageMin() != 2
            || udp3SheStaffDamageMax() != 16
            || udp3SheStaffCraftSegments() != 1
            || udp3SheEntanglePerRound() != 1
            || udp3SheDoubleCastSpeedDiv() != 4
            || udp3SheSuccessiveDamageMin() != 1
            || udp3SheSuccessiveDamageMax() != 4
            || udp3SheFlowerDressed() != 1
            || udp3SheFieldsGrowWhenSings() != 1
            || udp3SheWeatherToFaithful() != 1
            || udp3SheDroughtFloodsToPoorly() != 1
            || udp3SheFollowersWearFlower() != 1
            || udp3SheFollowersWorkHarmony() != 1
            || udp3SheSeedingFestival() != 1
            || udp3SheHighHarvestFestival() != 1
            || udp3SheRevelryAtFestivals() != 1
            || udp3SheQuestsGrowHarder() != 1
            || udp3SheOneEntangleAtATime() != 1
            || udp3SheEntangleCumulative() != 1
            || udp3SheConstrictionNoSave() != 1
        )
            ++bad;
        // the Arvoreen prose walk
    if (udp3ArvFirstAttackDamageDiv() != 2
            || udp3ArvUnseenRoundsMin() != 4
            || udp3ArvUnseenRoundsMax() != 16
            || udp3ArvSwordBonus() != 4
            || udp3ArvSummonPerDay() != 1
            || udp3ArvSummonMin() != 10
            || udp3ArvSummonMax() != 40
            || udp3ArvSummonHeroLevel() != 4
            || udp3ArvSummonAc() != 4
            || udp3ArvSummonHp() != 25
            || udp3ArvNeverAttacksFirst() != 1
            || udp3ArvFirstMagicReflected() != 1
            || udp3ArvInvisibleAtWill() != 1
            || udp3ArvOnlyFightsIfAttacked() != 1
            || udp3ArvFightsToFinish() != 1
            || udp3ArvThievingAgainstEnemies() != 1
            || udp3ArvNoStealingFromHalflings() != 1
            || udp3ArvHeroesObeyImplicitly() != 1
            || udp3ArvHeroesSwordAndBow() != 1
            || udp3ArvPatronOfFighters() != 1
        )
            ++bad;
        // the Cyrrollalee prose walk
    if (udp3CyrAnimateRadiusInches() != 6
            || udp3CyrAnimateClericLevel() != 20
            || udp3CyrAnimateVolumeMax() != 20
            || udp3CyrAnimateRounds() != 20
            || udp3CyrAnimatePerDay() != 3
            || udp3CyrFurnitureChancePct() != 2
            || udp3CyrFurnitureVolumeMax() != 5
            || udp3CyrFurnitureRounds() != 5
            || udp3CyrFurnitureAttacksPerRound() != 1
            || udp3CyrGiftLifetimeMax() != 2
            || udp3CyrServiceDayOfMonth() != 1
            || udp3CyrDeityOfFriendship() != 1
            || udp3CyrHomeProtectorOpenDwelling() != 1
            || udp3CyrPeasantAppearance() != 1
            || udp3CyrEnemyOfTrustBreakers() != 1
            || udp3CyrAnimationPersists() != 1
            || udp3CyrGiftRequiresService() != 1
            || udp3CyrAnyFighterWeapon() != 1
            || udp3CyrFollowersPlainHomes() != 1
        )
            ++bad;
        // the Brandobaris prose walk
    if (udp3BraDaggerBonus() != 3
            || udp3BraSlingBonus() != 4
            || udp3BraDustRangeMaxInches() != 48
            || udp3BraDustRangeShortInches() != 24
            || udp3BraDustRangeMediumInches() != 36
            || udp3BraDustSaveMod() != -6
            || udp3BraSleepTurnsMin() != 6
            || udp3BraSleepTurnsMax() != 36
            || udp3BraRewardChancePct() != 5
            || udp3BraRewardLevelMax() != 10
            || udp3BraRewardLifetimeMax() != 1
            || udp3BraMeetChancePctPerLevel() != 1
            || udp3BraMeetLevelMin() != 11
            || udp3BraSilenceUnhearable() != 1
            || udp3BraHidesExceptTrueSeeing() != 1
            || udp3BraDaggerPointsEscape() != 1
            || udp3BraMazeImmuneWithDagger() != 1
            || udp3BraDustBallHarmless() != 1
            || udp3BraTricksterRascal() != 1
            || udp3BraMeetsAsFellowThief() != 1
            || udp3BraIdentityOnlyAfter() != 1
            || udp3BraIdentityOnlyToFollowers() != 1
            || udp3BraNonWorshippersLoseItems() != 1
        )
            ++bad;
        printf("R788 halfling deity prose audit: bad %d\n", bad);
        if (bad) return 1;
    }
