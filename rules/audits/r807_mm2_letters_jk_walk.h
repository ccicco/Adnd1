    // ---- R807 MM2 letters JK walk audit ----
    // THE MM2 LETTERS JK WALK - the jann, the mustard jelly p. 77, the
    // kampfult, the kech and the korred p. 78 and the kraken p. 79 promoted
    // to the live registry; the contested cells settled: the kech treasure
    // type reads the letter B (the capture "8" the OCR misread; the djvu, the
    // 1eonline compilation and the 2e compendium the agreeing voices); the
    // korred hit dice read 6+1 (the capture "8+1" the misread; the same three
    // voices agree); the kampfult xp level reads II (the djvu "11" the
    // misread); the kraken move cell "//3" (21")" pins capture verbatim (the
    // R804 electric eel "//9"" precedent - the moveRate reads the swimming
    // 3); the kraken armor class "5/0" composite reads the head 5 (the
    // hordling and hangman tree first-read precedent); the kraken "2 and 4-6
    // and 1" attack load reads the and-sum 13 clamped at the 10 sanity
    // ceiling (the R805 purple worm "1 and 1" sum convention meets the
    // clamp); the mustard jelly "1 or 2" attack load reads the max 2 (the
    // R798 duergar convention); the korred "1 or by weapon" loads the 1
    // floor; every Standard magic resistance reads 0; the kraken "them them
    // sacrifices" print typo kept verbatim
    {
        using namespace rules;
        int bad = 0;
    if (mm2jkRound() != 807
            || mm2jkRegistryBefore() != 655
            || mm2jkRegistryAfter() != 661
            || mm2jkDefCount() != 6
            || mm2jkEntryCount() != 6
            || mm2jkStatBlockHeadings() != 6
            || mm2jkDoctrineHeads() != 0
            || mm2jkLetterJHeadings() != 2
            || mm2jkLetterKHeadings() != 4
            || mm2jkJkStatRows() != 6
            || mm2jkGapClosed() != 16
            || mm2jkGapOpen() != 21
            || mm2jkPriorOwnedEntries() != 0
            || mm2jkGenieKinCount() != 5
            || mm2jkJannXpValue() != 1159
            || mm2jkJannXpLevel() != 6
            || mm2jkJannChainmailPct() != 60
            || mm2jkJannChainmailAc() != 2
            || mm2jkJannFemaleStrengthMin() != 17
            || mm2jkJannMoveRate() != 12
            || mm2jkJannFlyRate() != 30
            || mm2jkJannSpellCasterLevel() != 12
            || mm2jkJannElementalDwellHours() != 48
            || mm2jkJannPlaneTravelCompanions() != 6
            || mm2jkJannPrimeDamagePerHour() != 1
            || mm2jkJannTravelPrimeRestDays() != 2
            || mm2jkJannGrowthReductionPerDay() != 2
            || mm2jkJannInvisibilityPerDay() != 3
            || mm2jkJannEtherealnessPerDay() != 1
            || mm2jkJannEtherealnessHours() != 1
            || mm2jkJannCreateFoodWaterLevel() != 7
            || mm2jkJannTribeSizeMin() != 11
            || mm2jkJannTribeSizeMax() != 30
            || mm2jkJannVizierCount() != 2
            || mm2jkJannSheikHpMax() != 84
            || mm2jkJannAmirHpMax() != 95
            || mm2jkJannLeaderStrength() != 19
            || mm2jkJannVizierPowersPerDay() != 3
            || mm2jkMustardJellyXpValue() != 1509
            || mm2jkMustardJellyXpLevel() != 6
            || mm2jkMustardJellyVaporRadiusFeet() != 10
            || mm2jkMustardJellyToxicRounds() != 2
            || mm2jkMustardJellyHalvesCount() != 2
            || mm2jkMustardJellyDivideMoveMin() != 12
            || mm2jkMustardJellyDivideMoveMax() != 18
            || mm2jkMustardJellyAttacksMax() != 2
            || mm2jkMustardJellyWeaponPlusMin() != 1
            || mm2jkMustardJellyDiameterMinFeet() != 9
            || mm2jkMustardJellyDiameterMaxFeet() != 12
            || mm2jkKampfultXpValue() != 50
            || mm2jkKampfultXpLevel() != 2
            || mm2jkKampfultAttackAppendages() != 6
            || mm2jkKampfultMoveAppendages() != 6
            || mm2jkKampfultAppendageLengthFeet() != 6
            || mm2jkKampfultMoveAppendageLengthFeet() != 1
            || mm2jkKampfultTrunkLengthFeet() != 4
            || mm2jkKampfultSurpriseMin() != 1
            || mm2jkKampfultSurpriseMax() != 3
            || mm2jkKampfultDamagePerAppendage() != 1
            || mm2jkKechXpValue() != 290
            || mm2jkKechXpLevel() != 4
            || mm2jkKechSurpriseInSix() != 5
            || mm2jkKechTracksUnfollowablePct() != 50
            || mm2jkKechSilencePct() != 50
            || mm2jkKechClimbFeetPerRound() != 60
            || mm2jkKechNoAppearingMin() != 2
            || mm2jkKechNoAppearingMax() != 8
            || mm2jkKorredXpValue() != 1076
            || mm2jkKorredXpLevel() != 6
            || mm2jkKorredHairSnareRoundsMin() != 1
            || mm2jkKorredHairSnareRoundsMax() != 4
            || mm2jkKorredRopeArmorClass() != 1
            || mm2jkKorredRopeHp() != 5
            || mm2jkKorredBoulderRangeInches() != 10
            || mm2jkKorredBoulderDamageDice() != 2
            || mm2jkKorredBoulderDamageSides() != 8
            || mm2jkKorredShearDamageMin() != 5
            || mm2jkKorredShearDamageMax() != 8
            || mm2jkKorredCudgelDamageMin() != 5
            || mm2jkKorredCudgelDamageMax() != 10
            || mm2jkKorredUnarmedDamageMin() != 5
            || mm2jkKorredUnarmedDamageMax() != 6
            || mm2jkKorredLaughsPerDay() != 3
            || mm2jkKorredLaughRadiusInches() != 6
            || mm2jkKorredLaughStunRoundsMin() != 1
            || mm2jkKorredLaughStunRoundsMax() != 4
            || mm2jkKorredPouchGoldMin() != 50
            || mm2jkKorredPouchGoldMax() != 200
            || mm2jkKorredDanceDamageMin() != 1
            || mm2jkKorredDanceDamageMax() != 4
            || mm2jkKorredStonePowersCount() != 6
            || mm2jkKrakenXpValue() != 19000
            || mm2jkKrakenXpLevel() != 10
            || mm2jkKrakenTentacleAc() != 6
            || mm2jkKrakenHeadAc() != 6
            || mm2jkKrakenBodyAc() != 0
            || mm2jkKrakenTentaclesTotal() != 10
            || mm2jkKrakenTentaclesAnchoring() != 2
            || mm2jkKrakenJetRate() != 21
            || mm2jkKrakenSwimRate() != 3
            || mm2jkKrakenConstrictDamageMin() != 3
            || mm2jkKrakenConstrictDamageMax() != 12
            || mm2jkKrakenTentacleSeverDamage() != 16
            || mm2jkKrakenInkWidthInches() != 8
            || mm2jkKrakenInkHeightInches() != 8
            || mm2jkKrakenInkLengthInches() != 12
            || mm2jkKrakenInkPoisonRoundsMin() != 2
            || mm2jkKrakenInkPoisonRoundsMax() != 5
            || mm2jkKrakenInkDamageMin() != 1
            || mm2jkKrakenInkDamageMax() != 4
            || mm2jkKrakenDraggableShipFeet() != 60
            || mm2jkKrakenLargerThanSquidPct() != 10
            || mm2jkKrakenDragHaltRounds() != 10
            || mm2jkKrakenGraspTentacles() != 6
            || mm2jkKrakenGraspRounds() != 3
            || mm2jkKrakenSinkRoundsMin() != 2
            || mm2jkKrakenSinkRoundsMax() != 8
            || mm2jkKrakenRetreatSeveredTentacles() != 3
            || mm2jkKrakenAiryWaterPerDay() != 6
            || mm2jkKrakenAiryWaterSphereFeet() != 128
            || mm2jkKrakenAiryWaterHemisphereFeet() != 240
            || mm2jkKrakenFaerieFireHours() != 8
            || mm2jkKrakenTemperatureRadiusFeet() != 40
            || mm2jkKrakenLairExtraTreasurePct() != 50
            || mm2jkKrakenAttacksLoadedMax() != 10
            || !mm2jkJannWeakestOfTheGenies()
            || !mm2jkJannAcceptDjinnShunDaoEfreetMarid()
            || !mm2jkJannSpeakWithAnimals()
            || !mm2jkMustardJellyRelativeOfOchreJelly()
            || !mm2jkMustardJellyCannotClimbCeilings()
            || !mm2jkMustardJellyGrowsOnElectricityAndMagicMissiles()
            || !mm2jkMustardJellyHalfXpWhenHalfSlain()
            || !mm2jkKampfultOnlyCentralSectionHarmed()
            || !mm2jkKampfultVictimHeldUntilSlain()
            || !mm2jkKechImitateDistressCalls()
            || !mm2jkKechCamouflageColoration()
            || !mm2jkKechTreasureReadsLetterB()
            || !mm2jkKorredHdReadsSixPlusOne()
            || !mm2jkKorredBuiltStoneCirclesRumor()
            || !mm2jkKorredPouchGoldOnHolyWater()
            || !mm2jkKorredWeeklyHolidayDance()
            || !mm2jkKrakenAirAndWaterBreathing()
            || !mm2jkKrakenBattlesSpermWhales()
            || !mm2jkKrakenBreedHumanSlavesRumor()
            || !mm2jkKrakenMovePrintsDoubleSlashVerbatim()
        )
            ++bad;
        // THE JK-GRID: the 6-row JkStats stat grid (every armor class,
        // hit-dice, bonus, avgHp, attack, xp, xp/hp, lair, move and
        // magic-resistance cell of the six letters-JK stat blocks, in print
        // order - the jann, the mustard jelly, the kampfult, the kech, the
        // korred and the kraken)
        int CJkStats[6][10] = {
            {5,6,2,23,1,975,8,0,12,20},
            {4,7,14,38,2,825,18,35,9,10},
            {4,2,0,7,6,36,2,35,3,0},
            {4,5,0,17,3,205,5,30,15,0},
            {5,6,1,22,1,900,8,1,9,25},
            {5,20,0,70,10,16900,30,75,3,0},
            };
        for (int b = 0;
             b < mm2jkJkStatRows();
             ++b) {
            int vals[10];
            vals[0] = mm2jkJkStatAC(b);
            vals[1] = mm2jkJkStatHd(b);
            vals[2] = mm2jkJkStatHdBonus(b);
            vals[3] = mm2jkJkStatAvgHp(b);
            vals[4] = mm2jkJkStatAttacks(b);
            vals[5] = mm2jkJkStatXp(b);
            vals[6] = mm2jkJkStatXpHp(b);
            vals[7] = mm2jkJkStatLairPct(b);
            vals[8] = mm2jkJkStatMove(b);
            vals[9] = mm2jkJkStatMr(b);
            for (int c = 0; c < 10;
                 ++c) {
                if (vals[c] != CJkStats[b][c])
                    ++bad;
            }
        }
        // the registry grows by exactly the def count and the two gap boxes
        // flip (the census walk)
    if (mm2jkRegistryAfter() - mm2jkRegistryBefore() != mm2jkDefCount()
            || mm2jkDefCount() != 6
            || mm2jkEntryCount() != 6
            || mm2jkJkStatRows() != 6
            || mm2jkGapClosed() != 16
            || mm2jkGapOpen() != 21
            || mm2jkPriorOwnedEntries() != 0
        )
            ++bad;
        // the pin-time entry census composition (6 stat-block headings, no
        // doctrine-only family heads, 2 letter-J and 4 letter-K)
    if (mm2jkStatBlockHeadings() != 6
            || mm2jkDoctrineHeads() != 0
            || mm2jkLetterJHeadings() != 2
            || mm2jkLetterKHeadings() != 4
            || mm2jkGenieKinCount() != 5
        )
            ++bad;
        // the jann composite stat reads (the 5 armor class with the
        // possible-armor parenthetical, the 6+2 dice, the 12/30 composite
        // move head, the 20% magic resistance, the Nil lair reading 0)
    if (mm2jkJkStatAC(0) != 5
            || mm2jkJkStatHd(0) != 6
            || mm2jkJkStatHdBonus(0) != 2
            || mm2jkJkStatAvgHp(0) != 23
            || mm2jkJkStatAttacks(0) != 1
            || mm2jkJkStatXp(0) != 975
            || mm2jkJkStatXpHp(0) != 8
            || mm2jkJkStatLairPct(0) != 0
            || mm2jkJkStatMove(0) != 12
            || mm2jkJkStatMr(0) != 20
        )
            ++bad;
        // the mustard jelly composite stat reads (the 7+14 dice, the "1 or 2"
        // attack max 2, the 35% lair, the 10% magic resistance)
    if (mm2jkJkStatAC(1) != 4
            || mm2jkJkStatHd(1) != 7
            || mm2jkJkStatHdBonus(1) != 14
            || mm2jkJkStatAvgHp(1) != 38
            || mm2jkJkStatAttacks(1) != 2
            || mm2jkJkStatXp(1) != 825
            || mm2jkJkStatXpHp(1) != 18
            || mm2jkJkStatLairPct(1) != 35
            || mm2jkJkStatMove(1) != 9
            || mm2jkJkStatMr(1) != 10
        )
            ++bad;
        // the kampfult stat reads (the 2 dice, the six appendage attacks, the
        // surprise on 1-3, the 3 move)
    if (mm2jkJkStatAC(2) != 4
            || mm2jkJkStatHd(2) != 2
            || mm2jkJkStatHdBonus(2) != 0
            || mm2jkJkStatAvgHp(2) != 7
            || mm2jkJkStatAttacks(2) != 6
            || mm2jkJkStatXp(2) != 36
            || mm2jkJkStatXpHp(2) != 2
            || mm2jkJkStatLairPct(2) != 35
            || mm2jkJkStatMove(2) != 3
            || mm2jkJkStatMr(2) != 0
        )
            ++bad;
        // the kech stat reads (the 5 dice, the 3 attacks, the 30% lair, the
        // 15 move, the Standard magic resistance reading 0)
    if (mm2jkJkStatAC(3) != 4
            || mm2jkJkStatHd(3) != 5
            || mm2jkJkStatHdBonus(3) != 0
            || mm2jkJkStatAvgHp(3) != 17
            || mm2jkJkStatAttacks(3) != 3
            || mm2jkJkStatXp(3) != 205
            || mm2jkJkStatXpHp(3) != 5
            || mm2jkJkStatLairPct(3) != 30
            || mm2jkJkStatMove(3) != 15
            || mm2jkJkStatMr(3) != 0
        )
            ++bad;
        // the korred composite stat reads (the settled 6+1 dice, the "1 or by
        // weapon" attack load 1, the 1% lair, the 25% magic resistance)
    if (mm2jkJkStatAC(4) != 5
            || mm2jkJkStatHd(4) != 6
            || mm2jkJkStatHdBonus(4) != 1
            || mm2jkJkStatAvgHp(4) != 22
            || mm2jkJkStatAttacks(4) != 1
            || mm2jkJkStatXp(4) != 900
            || mm2jkJkStatXpHp(4) != 8
            || mm2jkJkStatLairPct(4) != 1
            || mm2jkJkStatMove(4) != 9
            || mm2jkJkStatMr(4) != 25
        )
            ++bad;
        // the kraken composite stat reads (the 5/0 armor class head 5, the 20
        // dice, the and-sum attack load clamped at 10, the 75% lair, the
        // "//3" move head, the X/16,900 + 30/hp xp)
    if (mm2jkJkStatAC(5) != 5
            || mm2jkJkStatHd(5) != 20
            || mm2jkJkStatHdBonus(5) != 0
            || mm2jkJkStatAvgHp(5) != 70
            || mm2jkJkStatAttacks(5) != 10
            || mm2jkJkStatXp(5) != 16900
            || mm2jkJkStatXpHp(5) != 30
            || mm2jkJkStatLairPct(5) != 75
            || mm2jkJkStatMove(5) != 3
            || mm2jkJkStatMr(5) != 0
        )
            ++bad;
        // the full kill xp values (the base + xp-per-hp x avgHp formula,
        // every letters-JK def)
    if (mm2jkJannXpValue() != 1159
            || mm2jkMustardJellyXpValue() != 1509
            || mm2jkKampfultXpValue() != 50
            || mm2jkKechXpValue() != 290
            || mm2jkKorredXpValue() != 1076
            || mm2jkKrakenXpValue() != 19000
        )
            ++bad;
        // the jann arithmetic (the chainmail percent and armor class, the
        // 12th-level spell ability, the elemental dwell hours, the tribe
        // ladder, the sheik and amir hit points, the vizier powers)
    if (mm2jkJannChainmailPct() != 60
            || mm2jkJannChainmailAc() != 2
            || mm2jkJannSpellCasterLevel() != 12
            || mm2jkJannElementalDwellHours() != 48
            || mm2jkJannPlaneTravelCompanions() != 6
            || mm2jkJannPrimeDamagePerHour() != 1
            || mm2jkJannTravelPrimeRestDays() != 2
            || mm2jkJannTribeSizeMin() != 11
            || mm2jkJannTribeSizeMax() != 30
            || mm2jkJannSheikHpMax() != 84
            || mm2jkJannAmirHpMax() != 95
            || mm2jkJannLeaderStrength() != 19
            || mm2jkJannVizierPowersPerDay() != 3
            || mm2jkJannFlyRate() != 30
            || mm2jkJannMoveRate() != 12
            || mm2jkJannInvisibilityPerDay() != 3
            || mm2jkJannGrowthReductionPerDay() != 2
            || mm2jkJannEtherealnessPerDay() != 1
            || mm2jkJannEtherealnessHours() != 1
            || mm2jkJannCreateFoodWaterLevel() != 7
            || mm2jkJannFemaleStrengthMin() != 17
        )
            ++bad;
        // the mustard jelly arithmetic (the vapor radius, the toxic rounds,
        // the divide move ladder, the weapon floor, the size ladder)
    if (mm2jkMustardJellyVaporRadiusFeet() != 10
            || mm2jkMustardJellyToxicRounds() != 2
            || mm2jkMustardJellyHalvesCount() != 2
            || mm2jkMustardJellyDivideMoveMin() != 12
            || mm2jkMustardJellyDivideMoveMax() != 18
            || mm2jkMustardJellyAttacksMax() != 2
            || mm2jkMustardJellyWeaponPlusMin() != 1
            || mm2jkMustardJellyDiameterMinFeet() != 9
            || mm2jkMustardJellyDiameterMaxFeet() != 12
        )
            ++bad;
        // the kampfult arithmetic (the six-and-six appendages, the length
        // ladder, the surprise band, the II xp level)
    if (mm2jkKampfultAttackAppendages() != 6
            || mm2jkKampfultMoveAppendages() != 6
            || mm2jkKampfultAppendageLengthFeet() != 6
            || mm2jkKampfultMoveAppendageLengthFeet() != 1
            || mm2jkKampfultTrunkLengthFeet() != 4
            || mm2jkKampfultSurpriseMin() != 1
            || mm2jkKampfultSurpriseMax() != 3
            || mm2jkKampfultDamagePerAppendage() != 1
            || mm2jkKampfultXpLevel() != 2
        )
            ++bad;
        // the kech arithmetic (the 5-in-6 surprise, the unfollowable tracks,
        // the silence chance, the climb rate, the appearing band)
    if (mm2jkKechSurpriseInSix() != 5
            || mm2jkKechTracksUnfollowablePct() != 50
            || mm2jkKechSilencePct() != 50
            || mm2jkKechClimbFeetPerRound() != 60
            || mm2jkKechNoAppearingMin() != 2
            || mm2jkKechNoAppearingMax() != 8
            || mm2jkKechXpLevel() != 4
        )
            ++bad;
        // the korred arithmetic (the weapon damage ladders, the laugh band,
        // the pouch gold, the dance damage, the boulder 2d8, the stone
        // powers)
    if (mm2jkKorredShearDamageMin() != 5
            || mm2jkKorredShearDamageMax() != 8
            || mm2jkKorredCudgelDamageMin() != 5
            || mm2jkKorredCudgelDamageMax() != 10
            || mm2jkKorredUnarmedDamageMin() != 5
            || mm2jkKorredUnarmedDamageMax() != 6
            || mm2jkKorredLaughsPerDay() != 3
            || mm2jkKorredLaughRadiusInches() != 6
            || mm2jkKorredLaughStunRoundsMin() != 1
            || mm2jkKorredLaughStunRoundsMax() != 4
            || mm2jkKorredPouchGoldMin() != 50
            || mm2jkKorredPouchGoldMax() != 200
            || mm2jkKorredDanceDamageMin() != 1
            || mm2jkKorredDanceDamageMax() != 4
            || mm2jkKorredBoulderRangeInches() != 10
            || mm2jkKorredBoulderDamageDice() != 2
            || mm2jkKorredBoulderDamageSides() != 8
            || mm2jkKorredStonePowersCount() != 6
            || mm2jkKorredHairSnareRoundsMin() != 1
            || mm2jkKorredHairSnareRoundsMax() != 4
            || mm2jkKorredRopeArmorClass() != 1
            || mm2jkKorredRopeHp() != 5
        )
            ++bad;
        // the kraken arithmetic (the armor class triple, the constriction
        // ladder, the sever damage, the ink cuboid, the ship ladder, the airy
        // water pair, the retreat tentacles)
    if (mm2jkKrakenTentacleAc() != 6
            || mm2jkKrakenHeadAc() != 6
            || mm2jkKrakenBodyAc() != 0
            || mm2jkKrakenTentaclesTotal() != 10
            || mm2jkKrakenTentaclesAnchoring() != 2
            || mm2jkKrakenJetRate() != 21
            || mm2jkKrakenSwimRate() != 3
            || mm2jkKrakenConstrictDamageMin() != 3
            || mm2jkKrakenConstrictDamageMax() != 12
            || mm2jkKrakenTentacleSeverDamage() != 16
            || mm2jkKrakenInkWidthInches() != 8
            || mm2jkKrakenInkHeightInches() != 8
            || mm2jkKrakenInkLengthInches() != 12
            || mm2jkKrakenInkPoisonRoundsMin() != 2
            || mm2jkKrakenInkPoisonRoundsMax() != 5
            || mm2jkKrakenInkDamageMin() != 1
            || mm2jkKrakenInkDamageMax() != 4
            || mm2jkKrakenDraggableShipFeet() != 60
            || mm2jkKrakenLargerThanSquidPct() != 10
            || mm2jkKrakenDragHaltRounds() != 10
            || mm2jkKrakenGraspTentacles() != 6
            || mm2jkKrakenGraspRounds() != 3
            || mm2jkKrakenSinkRoundsMin() != 2
            || mm2jkKrakenSinkRoundsMax() != 8
            || mm2jkKrakenRetreatSeveredTentacles() != 3
            || mm2jkKrakenAiryWaterPerDay() != 6
            || mm2jkKrakenAiryWaterSphereFeet() != 128
            || mm2jkKrakenAiryWaterHemisphereFeet() != 240
            || mm2jkKrakenFaerieFireHours() != 8
            || mm2jkKrakenTemperatureRadiusFeet() != 40
            || mm2jkKrakenLairExtraTreasurePct() != 50
            || mm2jkKrakenAttacksLoadedMax() != 10
        )
            ++bad;
        printf("R807 MM2 letters JK walk audit: bad %d\n", bad);
        if (bad) return 1;
    }
