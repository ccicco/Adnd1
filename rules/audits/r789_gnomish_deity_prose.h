    // ---- R789 gnomish deity prose audit ----
    // THE GNOMISH DEITY PROSE - part 4 of the Appendix S
    // description-paragraph close. The archive.org full-text OCR of pp.
    // 116-118 reads the four gnomish blocks scan-clean: the Baervan
    // Whisperleaf spear and the raccoon Chiktikka, the Urdlen blur and the
    // soul-eating evil, the Segojan rock speech and the quartz rod, and the
    // Flandal fire apron and the hammer Rhondang. The stat-block numerics
    // stay R406/R783; the paragraph facts ride rules/uadeityprose4.h.
    {
        using namespace rules;
        int bad = 0;
    if (udp4ProseRound() != 789
            || udp4StatblockFeederRound() != 406
            || udp4GnomishDeityCount() != 4
            || udp4PantheonCountMin() != 6
            || udp4PantheonCountMax() != 7
            || udp4BaeSpearBonus() != 3
            || udp4BaeSpearRemakeDays() != 1
            || udp4BaeWhisperleafRegenHours() != 1
            || udp4BaeTreeAnimTurnsMin() != 5
            || udp4BaeTreeAnimTurnsMax() != 20
            || udp4BaeTreeTreantHitDice() != 12
            || udp4BaeTreesPerRound() != 1
            || udp4BaeChikAc() != 3
            || udp4BaeChikMoveInches() != 15
            || udp4BaeChikHp() != 70
            || udp4BaeChikThiefLevel() != 12
            || udp4BaeChikDex() != 18
            || udp4BaeChikClawDamageMin() != 2
            || udp4BaeChikClawDamageMax() != 8
            || udp4BaeChikBiteDamageMin() != 2
            || udp4BaeChikBiteDamageMax() != 12
            || udp4BaeGiftMeetChancePct() != 1
            || udp4UrdBlurClericChancePct() != 5
            || udp4SegArmorBonus() != 4
            || udp4SegRodBonus() != 4
            || udp4SegRodDamageMin() != 3
            || udp4SegRodDamageMax() != 30
            || udp4SegGolemPerDay() != 1
            || udp4SegElementalsPerDay() != 1
            || udp4SegElementalsMin() != 2
            || udp4SegElementalsMax() != 8
            || udp4SegElementalHitDice() != 16
            || udp4FlaHammerBonus() != 5
            || udp4FlaFireballDice() != 6
            || udp4FlaFireballPerRound() != 1
            || udp4FlaFireballPerDay() != 10
            || udp4FlaElementalChancePct() != 65
            || udp4FlaElementalsMin() != 1
            || udp4FlaElementalsMax() != 4
            || udp4FlaElementalHitDice() != 16
            || !udp4PanFewestMembers()
            || !udp4PanGarlRulesAll()
            || !udp4PanGoldenHills()
            || !udp4PanUrdlenInAbyss()
            || !udp4PanAllMasculine()
            || !udp4PanCleverSensible()
            || !udp4PanUrdlenSexless()
            || !udp4PanCompanionsCommon()
            || !udp4PanGarlHasArumdina()
            || !udp4PanSegojanGolemFriend()
            || !udp4PanUrdlenFriendless()
            || !udp4PanPranksAgainstEnemies()
            || !udp4PanLooseDwarvenContact()
            || !udp4PanMostActive()
            || !udp4BaeRivalOfGarl()
            || !udp4BaeWoodBrownClothes()
            || !udp4BaeOnlyHeApproachesTree()
            || !udp4BaeTreeObeysOnlyHim()
            || !udp4BaeChikHasty()
            || !udp4BaeChikBorrower()
            || !udp4BaeNutBrownSkin()
            || !udp4BaeKeepsToHimself()
            || !udp4BaeGiftOncePerLifetime()
            || !udp4BaeHardToDislike()
            || !udp4BaeFollowersOutdoorsmen()
            || !udp4UrdEvilImpulse()
            || !udp4UrdFurlessWhiteMole()
            || !udp4UrdLustsForMetals()
            || !udp4UrdUnpredictable()
            || !udp4UrdPermanentBlur()
            || !udp4UrdEatsSlainClericSoul()
            || !udp4UrdAppeasedByBlood()
            || !udp4UrdSacrificeByRuining()
            || !udp4UrdAtWarWithPantheon()
            || !udp4UrdFollowersUnderground()
            || !udp4SegSpeaksToRock()
            || !udp4SegGraySkinned()
            || !udp4SegGolemAverageIntelligence()
            || !udp4SegGolemNeedsRockMass()
            || !udp4SegLesserGodOfMagic()
            || !udp4SegIllusionistFollowers()
            || !udp4SegMinersAndJewelers()
            || !udp4SegGlowingGemSymbols()
            || !udp4FlaApronOnlyArmor()
            || !udp4FlaMithrilSkin()
            || !udp4FlaStrongestGnomishGod()
            || !udp4FlaForgedArumdina()
            || !udp4FlaTravelsSeekingOres()
            || !udp4FlaRhondangSpeaksFire()
            || !udp4FlaTalksBeforeAttacking()
            || !udp4FlaRhondangDoubleVsCold()
            || !udp4FlaElementalsObedient()
            || !udp4FlaWorkshopOnTwinParadises()
            || !udp4FlaSmithsFollowHim()
            || !udp4FlaFlamingHammerSpell()
        )
            ++bad;
        // the round consts (the prose round, the feeder round, the census)
    if (udp4ProseRound() != 789
            || udp4StatblockFeederRound() != 406
            || udp4GnomishDeityCount() != 4
            || udp4PantheonCountMin() != 6
            || udp4PantheonCountMax() != 7
        )
            ++bad;
        // the gnomish pantheon prose walk
    if (udp4PanFewestMembers() != 1
            || udp4PanGarlRulesAll() != 1
            || udp4PanGoldenHills() != 1
            || udp4PanUrdlenInAbyss() != 1
            || udp4PanAllMasculine() != 1
            || udp4PanCleverSensible() != 1
            || udp4PanUrdlenSexless() != 1
            || udp4PanCompanionsCommon() != 1
            || udp4PanGarlHasArumdina() != 1
            || udp4PanSegojanGolemFriend() != 1
            || udp4PanUrdlenFriendless() != 1
            || udp4PanPranksAgainstEnemies() != 1
            || udp4PanLooseDwarvenContact() != 1
            || udp4PanMostActive() != 1
        )
            ++bad;
        // the Baervan Wildwanderer prose walk
    if (udp4BaeSpearBonus() != 3
            || udp4BaeSpearRemakeDays() != 1
            || udp4BaeWhisperleafRegenHours() != 1
            || udp4BaeTreeAnimTurnsMin() != 5
            || udp4BaeTreeAnimTurnsMax() != 20
            || udp4BaeTreeTreantHitDice() != 12
            || udp4BaeTreesPerRound() != 1
            || udp4BaeChikAc() != 3
            || udp4BaeChikMoveInches() != 15
            || udp4BaeChikHp() != 70
            || udp4BaeChikThiefLevel() != 12
            || udp4BaeChikDex() != 18
            || udp4BaeChikClawDamageMin() != 2
            || udp4BaeChikClawDamageMax() != 8
            || udp4BaeChikBiteDamageMin() != 2
            || udp4BaeChikBiteDamageMax() != 12
            || udp4BaeGiftMeetChancePct() != 1
            || udp4BaeRivalOfGarl() != 1
            || udp4BaeWoodBrownClothes() != 1
            || udp4BaeOnlyHeApproachesTree() != 1
            || udp4BaeTreeObeysOnlyHim() != 1
            || udp4BaeChikHasty() != 1
            || udp4BaeChikBorrower() != 1
            || udp4BaeNutBrownSkin() != 1
            || udp4BaeKeepsToHimself() != 1
            || udp4BaeGiftOncePerLifetime() != 1
            || udp4BaeHardToDislike() != 1
            || udp4BaeFollowersOutdoorsmen() != 1
        )
            ++bad;
        // the Urdlen prose walk
    if (udp4UrdBlurClericChancePct() != 5
            || udp4UrdEvilImpulse() != 1
            || udp4UrdFurlessWhiteMole() != 1
            || udp4UrdLustsForMetals() != 1
            || udp4UrdUnpredictable() != 1
            || udp4UrdPermanentBlur() != 1
            || udp4UrdEatsSlainClericSoul() != 1
            || udp4UrdAppeasedByBlood() != 1
            || udp4UrdSacrificeByRuining() != 1
            || udp4UrdAtWarWithPantheon() != 1
            || udp4UrdFollowersUnderground() != 1
        )
            ++bad;
        // the Segojan Earthcaller prose walk
    if (udp4SegArmorBonus() != 4
            || udp4SegRodBonus() != 4
            || udp4SegRodDamageMin() != 3
            || udp4SegRodDamageMax() != 30
            || udp4SegGolemPerDay() != 1
            || udp4SegElementalsPerDay() != 1
            || udp4SegElementalsMin() != 2
            || udp4SegElementalsMax() != 8
            || udp4SegElementalHitDice() != 16
            || udp4SegSpeaksToRock() != 1
            || udp4SegGraySkinned() != 1
            || udp4SegGolemAverageIntelligence() != 1
            || udp4SegGolemNeedsRockMass() != 1
            || udp4SegLesserGodOfMagic() != 1
            || udp4SegIllusionistFollowers() != 1
            || udp4SegMinersAndJewelers() != 1
            || udp4SegGlowingGemSymbols() != 1
        )
            ++bad;
        // the Flandal Steelskin prose walk
    if (udp4FlaHammerBonus() != 5
            || udp4FlaFireballDice() != 6
            || udp4FlaFireballPerRound() != 1
            || udp4FlaFireballPerDay() != 10
            || udp4FlaElementalChancePct() != 65
            || udp4FlaElementalsMin() != 1
            || udp4FlaElementalsMax() != 4
            || udp4FlaElementalHitDice() != 16
            || udp4FlaApronOnlyArmor() != 1
            || udp4FlaMithrilSkin() != 1
            || udp4FlaStrongestGnomishGod() != 1
            || udp4FlaForgedArumdina() != 1
            || udp4FlaTravelsSeekingOres() != 1
            || udp4FlaRhondangSpeaksFire() != 1
            || udp4FlaTalksBeforeAttacking() != 1
            || udp4FlaRhondangDoubleVsCold() != 1
            || udp4FlaElementalsObedient() != 1
            || udp4FlaWorkshopOnTwinParadises() != 1
            || udp4FlaSmithsFollowHim() != 1
            || udp4FlaFlamingHammerSpell() != 1
        )
            ++bad;
        printf("R789 gnomish deity prose audit: bad %d\n", bad);
        if (bad) return 1;
    }
