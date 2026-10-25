    // ---- R787 elven deity prose audit ----
    // THE ELVEN DEITY PROSE - part 2 of the Appendix S description-paragraph
    // close. The archive.org full-text OCR of pp. 113-116 reads the five
    // elven blocks scan-clean: the Aerdrie wind blasts and air summons, the
    // Erevan tricks and twenty small helpers, the Solonor never-empty quiver
    // and slaying arrows, the Hanali Evergold pool and charm aura, and the
    // Labelas time powers - temporal stasis, the 100-year touch, and the
    // 18-inch slow and haste radius. The stat-block numerics stay R406/R783;
    // the paragraph facts ride rules/uadeityprose2.h.
    {
        using namespace rules;
        int bad = 0;
    if (udp2ProseRound() != 787
            || udp2StatblockFeederRound() != 406
            || udp2ElvenDeityCount() != 5
            || udp2AerWindBlastsPerRound() != 2
            || udp2AerWindBlastDamageMin() != 5
            || udp2AerWindBlastDamageMax() != 20
            || udp2AerWindBlastRangeInches() != 96
            || udp2AerElementalsPerDay() != 1
            || udp2AerElementalsMin() != 2
            || udp2AerElementalsMax() != 12
            || udp2AerElementalHitDice() != 16
            || udp2AerEaglesPerDay() != 2
            || udp2AerEaglesMin() != 3
            || udp2AerEaglesMax() != 18
            || udp2AerRocsMin() != 1
            || udp2AerRocsMax() != 2
            || udp2AerAirSpellLevel() != 25
            || udp2AerNegateFlightRadiusInches() != 12
            || udp2AerFeatherFallChancePct() != 2
            || udp2AerQuestGeasDaysMin() != 2
            || udp2AerQuestGeasDaysMax() != 7
            || udp2EreHeightMinInches() != 1
            || udp2EreHeightMaxFeet() != 6
            || udp2EreSwordBonus() != 4
            || udp2EreSummonMax() != 20
            || udp2EreChaosCastsPerRound() != 1
            || udp2SolLongbowBonus() != 5
            || udp2SolSurpriseRadiusInches() != 48
            || udp2SolArrowCraftDays() != 1
            || udp2SolArrowBonus() != 3
            || udp2SolSlayingArrowChancePct() != 2
            || udp2HanBathEnhanceDays() != 1
            || udp2HanReactionBonusPct() != 75
            || udp2HanAweMaxLevel() != 14
            || udp2HanAuraRadiusInches() != 6
            || udp2HanAuraSaveMod() != -4
            || udp2HanAttackWeaponMin() != 2
            || udp2HanAttackChaMin() != -1
            || udp2HanAttackChaMax() != -7
            || udp2HanChaGift() != 2
            || udp2HanChaGiftChancePct() != 5
            || udp2LabRobeColorCount() != 4
            || udp2LabStasisPerRound() != 1
            || udp2LabStasisRadiusInches() != 12
            || udp2LabAgeYearsMax() != 100
            || udp2LabSlowHasteRadiusInches() != 18
            || udp2LabAgeUndoChancePct() != 1
            || !udp2AerFeatheredAppearance()
            || !udp2AerFeathersChangeColor()
            || !udp2AerNeverTouchesGround()
            || !udp2AerWandersWithWinged()
            || !udp2AerSummonsObeyUntoDeath()
            || !udp2AerAirSpellsAtWill()
            || !udp2AerWorshipAlignments()
            || !udp2AerWeatherCult()
            || !udp2AerGiftNeedsNoWorship()
            || !udp2AerGiftGeasesNoSave()
            || !udp2EreSmallFollowing()
            || !udp2EreFickleUnpredictable()
            || !udp2ErePranksRarelyHarmful()
            || !udp2EreAlwaysWearsGreen()
            || !udp2EreSwordOpensAll()
            || !udp2EreSummonsMaxHitPoints()
            || !udp2ErePrefersEscape()
            || !udp2EreCastsBeforeCombat()
            || !udp2EreFollowersIndependent()
            || !udp2EreAllowsOddCombos()
            || !udp2EreCombosAlwaysNpcs()
            || !udp2SolCloakOfLeaves()
            || !udp2SolHuntsEvil()
            || !udp2SolNeverCloses()
            || !udp2SolNeverEmptyQuiver()
            || !udp2SolTouchAndRetreat()
            || !udp2SolArrowKillsToDemigod()
            || !udp2SolArrowBeatsMagicRes()
            || !udp2SolForestInvisible()
            || !udp2SolTaughtHiding()
            || !udp2SolGiftOncePerLife()
            || !udp2HanMostlyFeminine()
            || !udp2HanSpheresLoveBeauty()
            || !udp2HanEvergoldPool()
            || !udp2HanBonusElvesOnly()
            || !udp2HanAphroditeShares()
            || !udp2HanCultsCoexist()
            || !udp2HanNoPhysicalAttack()
            || !udp2HanAuraCharms()
            || !udp2HanOthersAlwaysMiss()
            || !udp2HanChaGiftPermanent()
            || !udp2HanQuestShape()
            || !udp2LabBothGenders()
            || !udp2LabSilveryHair()
            || !udp2LabBlessedLongevity()
            || !udp2LabKnowsEveryElf()
            || !udp2LabMasterOfTime()
            || !udp2LabStasisNoSave()
            || !udp2LabAgeOncePerCreature()
            || !udp2LabSlowHasteNoSave()
            || !udp2LabTimeImmune()
            || !udp2LabUndoAgeRare()
            || !udp2LabQuestArtifacts()
            || !udp2LabFollowersHistorians()
        )
            ++bad;
        // the round consts (the prose round, the feeder round, the census)
    if (udp2ProseRound() != 787
            || udp2StatblockFeederRound() != 406
            || udp2ElvenDeityCount() != 5
        )
            ++bad;
        // the Aerdrie Faenya prose walk
    if (udp2AerWindBlastsPerRound() != 2
            || udp2AerWindBlastDamageMin() != 5
            || udp2AerWindBlastDamageMax() != 20
            || udp2AerWindBlastRangeInches() != 96
            || udp2AerElementalsPerDay() != 1
            || udp2AerElementalsMin() != 2
            || udp2AerElementalsMax() != 12
            || udp2AerElementalHitDice() != 16
            || udp2AerEaglesPerDay() != 2
            || udp2AerEaglesMin() != 3
            || udp2AerEaglesMax() != 18
            || udp2AerRocsMin() != 1
            || udp2AerRocsMax() != 2
            || udp2AerAirSpellLevel() != 25
            || udp2AerNegateFlightRadiusInches() != 12
            || udp2AerFeatherFallChancePct() != 2
            || udp2AerQuestGeasDaysMin() != 2
            || udp2AerQuestGeasDaysMax() != 7
            || udp2AerFeatheredAppearance() != 1
            || udp2AerFeathersChangeColor() != 1
            || udp2AerNeverTouchesGround() != 1
            || udp2AerWandersWithWinged() != 1
            || udp2AerSummonsObeyUntoDeath() != 1
            || udp2AerAirSpellsAtWill() != 1
            || udp2AerWorshipAlignments() != 1
            || udp2AerWeatherCult() != 1
            || udp2AerGiftNeedsNoWorship() != 1
            || udp2AerGiftGeasesNoSave() != 1
        )
            ++bad;
        // the Erevan Ilesere prose walk
    if (udp2EreHeightMinInches() != 1
            || udp2EreHeightMaxFeet() != 6
            || udp2EreSwordBonus() != 4
            || udp2EreSummonMax() != 20
            || udp2EreChaosCastsPerRound() != 1
            || udp2EreSmallFollowing() != 1
            || udp2EreFickleUnpredictable() != 1
            || udp2ErePranksRarelyHarmful() != 1
            || udp2EreAlwaysWearsGreen() != 1
            || udp2EreSwordOpensAll() != 1
            || udp2EreSummonsMaxHitPoints() != 1
            || udp2ErePrefersEscape() != 1
            || udp2EreCastsBeforeCombat() != 1
            || udp2EreFollowersIndependent() != 1
            || udp2EreAllowsOddCombos() != 1
            || udp2EreCombosAlwaysNpcs() != 1
        )
            ++bad;
        // the Solonor Thelandira prose walk
    if (udp2SolLongbowBonus() != 5
            || udp2SolSurpriseRadiusInches() != 48
            || udp2SolArrowCraftDays() != 1
            || udp2SolArrowBonus() != 3
            || udp2SolSlayingArrowChancePct() != 2
            || udp2SolCloakOfLeaves() != 1
            || udp2SolHuntsEvil() != 1
            || udp2SolNeverCloses() != 1
            || udp2SolNeverEmptyQuiver() != 1
            || udp2SolTouchAndRetreat() != 1
            || udp2SolArrowKillsToDemigod() != 1
            || udp2SolArrowBeatsMagicRes() != 1
            || udp2SolForestInvisible() != 1
            || udp2SolTaughtHiding() != 1
            || udp2SolGiftOncePerLife() != 1
        )
            ++bad;
        // the Hanali Celanil prose walk
    if (udp2HanBathEnhanceDays() != 1
            || udp2HanReactionBonusPct() != 75
            || udp2HanAweMaxLevel() != 14
            || udp2HanAuraRadiusInches() != 6
            || udp2HanAuraSaveMod() != -4
            || udp2HanAttackWeaponMin() != 2
            || udp2HanAttackChaMin() != -1
            || udp2HanAttackChaMax() != -7
            || udp2HanChaGift() != 2
            || udp2HanChaGiftChancePct() != 5
            || udp2HanMostlyFeminine() != 1
            || udp2HanSpheresLoveBeauty() != 1
            || udp2HanEvergoldPool() != 1
            || udp2HanBonusElvesOnly() != 1
            || udp2HanAphroditeShares() != 1
            || udp2HanCultsCoexist() != 1
            || udp2HanNoPhysicalAttack() != 1
            || udp2HanAuraCharms() != 1
            || udp2HanOthersAlwaysMiss() != 1
            || udp2HanChaGiftPermanent() != 1
            || udp2HanQuestShape() != 1
        )
            ++bad;
        // the Labelas Enoreth prose walk
    if (udp2LabRobeColorCount() != 4
            || udp2LabStasisPerRound() != 1
            || udp2LabStasisRadiusInches() != 12
            || udp2LabAgeYearsMax() != 100
            || udp2LabSlowHasteRadiusInches() != 18
            || udp2LabAgeUndoChancePct() != 1
            || udp2LabBothGenders() != 1
            || udp2LabSilveryHair() != 1
            || udp2LabBlessedLongevity() != 1
            || udp2LabKnowsEveryElf() != 1
            || udp2LabMasterOfTime() != 1
            || udp2LabStasisNoSave() != 1
            || udp2LabAgeOncePerCreature() != 1
            || udp2LabSlowHasteNoSave() != 1
            || udp2LabTimeImmune() != 1
            || udp2LabUndoAgeRare() != 1
            || udp2LabQuestArtifacts() != 1
            || udp2LabFollowersHistorians() != 1
        )
            ++bad;
        printf("R787 elven deity prose audit: bad %d\n", bad);
        if (bad) return 1;
    }
