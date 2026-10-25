    // ---- R786 dwarven deity prose audit ----
    // THE DWARVEN DEITY PROSE - part 1 of the Appendix S
    // description-paragraph pins (the prose alone stays open no more, the
    // dwarves open it). The archive.org full-text OCR of pp. 110-113 reads
    // the five dwarven blocks scan-clean: the Clanggedin fortress and
    // anti-giant methods, the Vergadain con-games and treasure-sensing sword,
    // the Dumathoin veins and earth elementals, the Abbathor greed mechanics
    // and level-draining dagger, the Berronar braid-of-gold and the paladin
    // grant. The stat-block lines stay R406/R783; these paragraphs ride
    // rules/uadeityprose1.h.
    {
        using namespace rules;
        int bad = 0;
    if (udpProseRound() != 786
            || udpStatblockFeederRound() != 406
            || udpDwarvenDeityCount() != 5
            || udpClnGiantAttackToHitMod() != -4
            || udpClnAxeBonus() != 4
            || udpClnAxeThrowYards() != 100
            || udpClnChainMailBonus() != 5
            || udpVgdMailBonus() != 5
            || udpVgdHeightMinFeet() != 1
            || udpVgdHeightMaxFeet() != 15
            || udpVgdSwordBonus() != 4
            || udpVgdSwordDetectInches() != 2
            || udpDumVeinMetalCount() != 5
            || udpDumMinerGemGpValue() != 10
            || udpDumMattockBonus() != 5
            || udpDumElementalsPerDay() != 1
            || udpDumElementalsMin() != 3
            || udpDumElementalsMax() != 18
            || udpDumElementalHitDice() != 16
            || udpDumEarthSpellLevel() != 30
            || udpAbbStealTreasureGpLimit() != 1000
            || udpAbbStealOrSlayPct() != 50
            || udpAbbDaggerBonus() != 5
            || udpAbbDaggerDamageMin() != 2
            || udpAbbDaggerDamageMax() != 24
            || udpAbbDaggerDetectInches() != 2
            || udpAbbDaggerLevelLossOnGrasp() != 1
            || udpAbbDaggerLevelLossPerRound() != 1
            || udpAbbShieldBlindSaveMod() != -6
            || udpAbbShieldBlindRangeInches() != 3
            || udpBerChainMailBonus() != 5
            || udpBerBraidRowCount() != 4
            || udpBerBraidRegrowDays() != 1
            || udpBerLockGoldMinGp() != 10000
            || udpBerLockGoldMaxGp() != 40000
            || udpBerMaceBonus() != 4
            || udpBerMaceSaveMod() != -4
            || udpBerTruthRingRadiusInches() != 10
            || udpBerTheftRingSaveMod() != -2
            || udpBerPaladinChancePct() != 5
            || udpBerPaladinDaysMin() != 3
            || udpBerPaladinDaysMax() != 6
            || udpBerPaladinOncePerYears() != 10
            || !udpClnFortressSouls()
            || !udpClnTaughtGiantMethods()
            || !udpClnPassedSkillsToGnomes()
            || !udpClnHatesGrolantor()
            || !udpClnSingsInBattle()
            || !udpClnThrownAxesStrikeAsHand()
            || !udpClnSpellsIndirectOnly()
            || !udpClnAvoidsSpellsInMelee()
            || !udpVgdMerchantsPatron()
            || !udpVgdNonevilThievesPatron()
            || !udpVgdPoetClueVerses()
            || !udpVgdEvaluatesTreasure()
            || !udpVgdBrownAndYellow()
            || !udpVgdConGames()
            || !udpVgdSuspiciousFollowers()
            || !udpVgdDenialNotOffensive()
            || !udpDumHidesSecrets()
            || !udpDumProtectorOfMountainDwarves()
            || !udpDumKeeperOfMetals()
            || !udpDumNeverSpeaks()
            || !udpDumMoradinNamed()
            || !udpDumParadiseForDwarves()
            || !udpDumPleasedByCraftsmanship()
            || !udpDumHatesPlunderers()
            || !udpDumAllowsMining()
            || !udpDumGrayStoneHair()
            || !udpDumEarthBrownSkin()
            || !udpDumSilverFireEyes()
            || !udpDumElementalsFightToDeath()
            || !udpDumEarthSpellsOnly()
            || !udpDumFriendlyToNonDwarves()
            || !udpDumHephaestusAlly()
            || !udpAbbTreacherousAlly()
            || !udpAbbNeverHelpsNonDwarves()
            || !udpAbbOriginallyAppreciation()
            || !udpAbbEmbitteredByChoice()
            || !udpAbbGoldenCaverns()
            || !udpAbbSlayOrSteal()
            || !udpAbbWearsFurs()
            || !udpAbbDaggerDiamondBlade()
            || !udpAbbDaggerDetectsMetals()
            || !udpAbbDaggerDrainsGraspers()
            || !udpAbbShieldBlinds()
            || !udpAbbTruceWithVergadain()
            || !udpAbbDestroysIfFrustrated()
            || !udpBerGreatestGoddess()
            || !udpBerLivesAtSoulForge()
            || !udpBerPatronessOfMarriage()
            || !udpBerInvokedAgainstThieves()
            || !udpBerLockTurnsToGold()
            || !udpBerGivesLocksToPoor()
            || !udpBerLockNeedsTopCleric()
            || !udpBerGoldVanishesIfMisused()
            || !udpBerMaceSlaysEvilThieves()
            || !udpBerRingTruth()
            || !udpBerRingTheft()
            || !udpBerInspiredRingCustom()
            || !udpBerRingCustomLawfulGood()
            || !udpBerGrantsPaladinPowers()
            || !udpBerPureHeartOnly()
        )
            ++bad;
        // the round consts (the prose round, the feeder round, the census)
    if (udpProseRound() != 786
            || udpStatblockFeederRound() != 406
            || udpDwarvenDeityCount() != 5
        )
            ++bad;
        // the Clanggedin prose walk
    if (udpClnGiantAttackToHitMod() != -4
            || udpClnAxeBonus() != 4
            || udpClnAxeThrowYards() != 100
            || udpClnChainMailBonus() != 5
            || udpClnFortressSouls() != 1
            || udpClnTaughtGiantMethods() != 1
            || udpClnPassedSkillsToGnomes() != 1
            || udpClnHatesGrolantor() != 1
            || udpClnSingsInBattle() != 1
            || udpClnThrownAxesStrikeAsHand() != 1
            || udpClnSpellsIndirectOnly() != 1
            || udpClnAvoidsSpellsInMelee() != 1
        )
            ++bad;
        // the Vergadain prose walk
    if (udpVgdMailBonus() != 5
            || udpVgdHeightMinFeet() != 1
            || udpVgdHeightMaxFeet() != 15
            || udpVgdSwordBonus() != 4
            || udpVgdSwordDetectInches() != 2
            || udpVgdMerchantsPatron() != 1
            || udpVgdNonevilThievesPatron() != 1
            || udpVgdPoetClueVerses() != 1
            || udpVgdEvaluatesTreasure() != 1
            || udpVgdBrownAndYellow() != 1
            || udpVgdConGames() != 1
            || udpVgdSuspiciousFollowers() != 1
            || udpVgdDenialNotOffensive() != 1
        )
            ++bad;
        // the Dumathoin prose walk
    if (udpDumVeinMetalCount() != 5
            || udpDumMinerGemGpValue() != 10
            || udpDumMattockBonus() != 5
            || udpDumElementalsPerDay() != 1
            || udpDumElementalsMin() != 3
            || udpDumElementalsMax() != 18
            || udpDumElementalHitDice() != 16
            || udpDumEarthSpellLevel() != 30
            || udpDumHidesSecrets() != 1
            || udpDumProtectorOfMountainDwarves() != 1
            || udpDumKeeperOfMetals() != 1
            || udpDumNeverSpeaks() != 1
            || udpDumMoradinNamed() != 1
            || udpDumParadiseForDwarves() != 1
            || udpDumPleasedByCraftsmanship() != 1
            || udpDumHatesPlunderers() != 1
            || udpDumAllowsMining() != 1
            || udpDumGrayStoneHair() != 1
            || udpDumEarthBrownSkin() != 1
            || udpDumSilverFireEyes() != 1
            || udpDumElementalsFightToDeath() != 1
            || udpDumEarthSpellsOnly() != 1
            || udpDumFriendlyToNonDwarves() != 1
            || udpDumHephaestusAlly() != 1
        )
            ++bad;
        // the Abbathor prose walk
    if (udpAbbStealTreasureGpLimit() != 1000
            || udpAbbStealOrSlayPct() != 50
            || udpAbbDaggerBonus() != 5
            || udpAbbDaggerDamageMin() != 2
            || udpAbbDaggerDamageMax() != 24
            || udpAbbDaggerDetectInches() != 2
            || udpAbbDaggerLevelLossOnGrasp() != 1
            || udpAbbDaggerLevelLossPerRound() != 1
            || udpAbbShieldBlindSaveMod() != -6
            || udpAbbShieldBlindRangeInches() != 3
            || udpAbbTreacherousAlly() != 1
            || udpAbbNeverHelpsNonDwarves() != 1
            || udpAbbOriginallyAppreciation() != 1
            || udpAbbEmbitteredByChoice() != 1
            || udpAbbGoldenCaverns() != 1
            || udpAbbSlayOrSteal() != 1
            || udpAbbWearsFurs() != 1
            || udpAbbDaggerDiamondBlade() != 1
            || udpAbbDaggerDetectsMetals() != 1
            || udpAbbDaggerDrainsGraspers() != 1
            || udpAbbShieldBlinds() != 1
            || udpAbbTruceWithVergadain() != 1
            || udpAbbDestroysIfFrustrated() != 1
        )
            ++bad;
        // the Berronar prose walk
    if (udpBerChainMailBonus() != 5
            || udpBerBraidRowCount() != 4
            || udpBerBraidRegrowDays() != 1
            || udpBerLockGoldMinGp() != 10000
            || udpBerLockGoldMaxGp() != 40000
            || udpBerMaceBonus() != 4
            || udpBerMaceSaveMod() != -4
            || udpBerTruthRingRadiusInches() != 10
            || udpBerTheftRingSaveMod() != -2
            || udpBerPaladinChancePct() != 5
            || udpBerPaladinDaysMin() != 3
            || udpBerPaladinDaysMax() != 6
            || udpBerPaladinOncePerYears() != 10
            || udpBerGreatestGoddess() != 1
            || udpBerLivesAtSoulForge() != 1
            || udpBerPatronessOfMarriage() != 1
            || udpBerInvokedAgainstThieves() != 1
            || udpBerLockTurnsToGold() != 1
            || udpBerGivesLocksToPoor() != 1
            || udpBerLockNeedsTopCleric() != 1
            || udpBerGoldVanishesIfMisused() != 1
            || udpBerMaceSlaysEvilThieves() != 1
            || udpBerRingTruth() != 1
            || udpBerRingTheft() != 1
            || udpBerInspiredRingCustom() != 1
            || udpBerRingCustomLawfulGood() != 1
            || udpBerGrantsPaladinPowers() != 1
            || udpBerPureHeartOnly() != 1
        )
            ++bad;
        printf("R786 dwarven deity prose audit: bad %d\n", bad);
        if (bad) return 1;
    }
