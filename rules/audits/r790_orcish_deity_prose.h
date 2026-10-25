    // ---- R790 orcish deity prose audit ----
    // THE ORCISH DEITY PROSE - part 5, the finale of the Appendix S
    // description-paragraph close. The archive.org full-text OCR of pp.
    // 118-121 reads the shaman tale and the five orcish blocks scan-clean:
    // the Bahgtru grapple and cesti might, the Shargaas night caves below
    // Gehenna, the Ilneval slaying sword and red chainmail, the Yurtrus gas
    // envelope and death magic, and the Luthic cave-mother curse and claws.
    // The stat-block numerics stay R406/R783; the paragraph facts ride
    // rules/uadeityprose5.h. THE FLIP: dvpProseStaysOpen returns false at
    // last - the close is complete, and the R783 audit assertion rides with
    // it.
    {
        using namespace rules;
        int bad = 0;
    if (udp5ProseRound() != 790
            || udp5StatblockFeederRound() != 406
            || udp5OrcishDeityCount() != 5
            || udp5ProsePartsTotal() != 5
            || udp5ProsePartRoundMin() != 786
            || udp5ProsePartRoundMax() != 790
            || udp5BahGrappleMargin() != 4
            || udp5BahCrushDamageMin() != 10
            || udp5BahCrushDamageMax() != 120
            || udp5BahBluntWeaponDamage() != 1
            || udp5BahClericStrengthMin() != 16
            || udp5ShaDarkSightMiles() != 1
            || udp5ShaShadowSkillMin() != 5
            || udp5ShaShadowSkillMax() != 30
            || udp5IlnSwordSaveMod() != -6
            || udp5YurGasRadiusFeet() != 120
            || udp5YurGasLowBandHd() != 4
            || udp5YurGasMidBandHd() != 8
            || udp5YurGasHighHitMod() != -2
            || udp5YurDeathMagicLevel() != 18
            || udp5YurTouchDamageMin() != 3
            || udp5YurTouchDamageMax() != 12
            || udp5YurTouchDiseasesMin() != 1
            || udp5YurTouchDiseasesMax() != 4
            || udp5LutClawLengthFeet() != 4
            || udp5LutRegenPerRound() != 3
            || udp5LutCurseChancePct() != 10
            || udp5LutCurseFatalDaysMin() != 2
            || udp5LutCurseFatalDaysMax() != 7
            || udp5LutCurseUndoWishes() != 3
            || udp5LutGuardHitBonus() != 2
            || udp5LutGuardAcPenalty() != -2
            || !udp5TaleOfTheLots()
            || !udp5TaleMockedOrcs()
            || !udp5TaleIronSpear()
            || !udp5TaleOrcsInherit()
            || !udp5TaleWarForWrath()
            || !udp5TaleCorellonBattle()
            || !udp5TaleDwarfMountainWars()
            || !udp5TaleGoblinBattles()
            || !udp5TaleTribesAlongCults()
            || !udp5TaleHierarchyUnderGruumsh()
            || !udp5TaleTribalWarfareEncouraged()
            || !udp5BahSonOfGruumshAndLuthic()
            || !udp5BahScornedButMighty()
            || !udp5BahStrengthExceeds()
            || !udp5BahSlewReptileBarehanded()
            || !udp5BahFightsWithCesti()
            || !udp5BahTanSkinGreenEyes()
            || !udp5BahClericsNoArmor()
            || !udp5BahClericsLosePowers()
            || !udp5BahStrongHelpWeakOnward()
            || !udp5ShaCavesBelowGehenna()
            || !udp5ShaOnlySeerInCaves()
            || !udp5ShaClimbsAnySurface()
            || !udp5ShaPerfectAmbusher()
            || !udp5ShaBanditPatron()
            || !udp5ShaMultiClassedClerics()
            || !udp5ShaNewMoonHolidays()
            || !udp5IlnChiefLieutenant()
            || !udp5IlnCovetsGruumsh()
            || !udp5IlnCaptainsGod()
            || !udp5IlnRedIronChainmail()
            || !udp5IlnImmuneToMissiles()
            || !udp5IlnScarredAppeal()
            || !udp5IlnClericsRedArmor()
            || !udp5IlnHalfOrcBroadswords()
            || !udp5YurNoMouthNeverSpeaks()
            || !udp5YurRottingFlesh()
            || !udp5YurGasLastsInRange()
            || !udp5YurWishRecoveryOnly()
            || !udp5YurClericWhiteGloves()
            || !udp5YurMaceWhiteFist()
            || !udp5YurPlagueAppeals()
            || !udp5LutCaveMotherSpheres()
            || !udp5LutClosestToBahgtru()
            || !udp5LutClawsTunnelRock()
            || !udp5LutServicesUnderground()
            || !udp5LutWorshipedByMales()
            || !udp5LutUnarmoredBlackClaws()
            || !udp5LutDirtRituals()
            || !udp5LutBothSexesClerics()
            || !udp5LutVileRuneTribe()
        )
            ++bad;
        // the round consts (the prose round, the feeder round, the census,
        // the close complete)
    if (udp5ProseRound() != 790
            || udp5StatblockFeederRound() != 406
            || udp5OrcishDeityCount() != 5
            || udp5ProsePartsTotal() != 5
            || udp5ProsePartRoundMin() != 786
            || udp5ProsePartRoundMax() != 790
        )
            ++bad;
        // the shaman-tale prose walk
    if (udp5TaleOfTheLots() != 1
            || udp5TaleMockedOrcs() != 1
            || udp5TaleIronSpear() != 1
            || udp5TaleOrcsInherit() != 1
            || udp5TaleWarForWrath() != 1
            || udp5TaleCorellonBattle() != 1
            || udp5TaleDwarfMountainWars() != 1
            || udp5TaleGoblinBattles() != 1
            || udp5TaleTribesAlongCults() != 1
            || udp5TaleHierarchyUnderGruumsh() != 1
            || udp5TaleTribalWarfareEncouraged() != 1
        )
            ++bad;
        // the Bahgtru prose walk
    if (udp5BahGrappleMargin() != 4
            || udp5BahCrushDamageMin() != 10
            || udp5BahCrushDamageMax() != 120
            || udp5BahBluntWeaponDamage() != 1
            || udp5BahClericStrengthMin() != 16
            || udp5BahSonOfGruumshAndLuthic() != 1
            || udp5BahScornedButMighty() != 1
            || udp5BahStrengthExceeds() != 1
            || udp5BahSlewReptileBarehanded() != 1
            || udp5BahFightsWithCesti() != 1
            || udp5BahTanSkinGreenEyes() != 1
            || udp5BahClericsNoArmor() != 1
            || udp5BahClericsLosePowers() != 1
            || udp5BahStrongHelpWeakOnward() != 1
        )
            ++bad;
        // the Shargaas prose walk
    if (udp5ShaDarkSightMiles() != 1
            || udp5ShaShadowSkillMin() != 5
            || udp5ShaShadowSkillMax() != 30
            || udp5ShaCavesBelowGehenna() != 1
            || udp5ShaOnlySeerInCaves() != 1
            || udp5ShaClimbsAnySurface() != 1
            || udp5ShaPerfectAmbusher() != 1
            || udp5ShaBanditPatron() != 1
            || udp5ShaMultiClassedClerics() != 1
            || udp5ShaNewMoonHolidays() != 1
        )
            ++bad;
        // the Ilneval prose walk
    if (udp5IlnSwordSaveMod() != -6
            || udp5IlnChiefLieutenant() != 1
            || udp5IlnCovetsGruumsh() != 1
            || udp5IlnCaptainsGod() != 1
            || udp5IlnRedIronChainmail() != 1
            || udp5IlnImmuneToMissiles() != 1
            || udp5IlnScarredAppeal() != 1
            || udp5IlnClericsRedArmor() != 1
            || udp5IlnHalfOrcBroadswords() != 1
        )
            ++bad;
        // the Yurtrus prose walk
    if (udp5YurGasRadiusFeet() != 120
            || udp5YurGasLowBandHd() != 4
            || udp5YurGasMidBandHd() != 8
            || udp5YurGasHighHitMod() != -2
            || udp5YurDeathMagicLevel() != 18
            || udp5YurTouchDamageMin() != 3
            || udp5YurTouchDamageMax() != 12
            || udp5YurTouchDiseasesMin() != 1
            || udp5YurTouchDiseasesMax() != 4
            || udp5YurNoMouthNeverSpeaks() != 1
            || udp5YurRottingFlesh() != 1
            || udp5YurGasLastsInRange() != 1
            || udp5YurWishRecoveryOnly() != 1
            || udp5YurClericWhiteGloves() != 1
            || udp5YurMaceWhiteFist() != 1
            || udp5YurPlagueAppeals() != 1
        )
            ++bad;
        // the Luthic prose walk
    if (udp5LutClawLengthFeet() != 4
            || udp5LutRegenPerRound() != 3
            || udp5LutCurseChancePct() != 10
            || udp5LutCurseFatalDaysMin() != 2
            || udp5LutCurseFatalDaysMax() != 7
            || udp5LutCurseUndoWishes() != 3
            || udp5LutGuardHitBonus() != 2
            || udp5LutGuardAcPenalty() != -2
            || udp5LutCaveMotherSpheres() != 1
            || udp5LutClosestToBahgtru() != 1
            || udp5LutClawsTunnelRock() != 1
            || udp5LutServicesUnderground() != 1
            || udp5LutWorshipedByMales() != 1
            || udp5LutUnarmoredBlackClaws() != 1
            || udp5LutDirtRituals() != 1
            || udp5LutBothSexesClerics() != 1
            || udp5LutVileRuneTribe() != 1
        )
            ++bad;
        printf("R790 orcish deity prose audit: bad %d\n", bad);
        if (bad) return 1;
    }
