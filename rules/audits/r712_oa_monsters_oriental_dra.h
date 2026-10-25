    // ---- R712 OA monsters Oriental Dragons audit ----
    // OA round ninety-nine (capture pp. 259-262): the Chapter 12 monster
    // roster - the oriental dragons opener, the bureau doctrine plus the two
    // FF Tome addition dragons riding one round, single-pass pins per the
    // Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (djzBureauPositionRows() != 7
            || djzAdditionDragons() != 2
            || djzChiangNoAppMin() != 1
            || djzChiangNoAppMax() != 2
            || djzChiangAC() != 2
            || djzChiangMoveWalk() != 12
            || djzChiangMoveSwim() != 18
            || djzChiangMoveFly() != 24
            || djzChiangHDMin() != 10
            || djzChiangHDMax() != 12
            || djzChiangLairPct() != 80
            || djzChiangAttacks() != 3
            || djzChiangClawDmgMin() != 1
            || djzChiangClawDmgMax() != 6
            || djzChiangBiteDmgMin() != 3
            || djzChiangBiteDmgMax() != 36
            || djzChiangMRPct() != 10
            || djzChiangSizeMinFt() != 50
            || djzChiangSizeMaxFt() != 60
            || djzChiangXP10HDBase() != 13750
            || djzChiangXP10HDPerHP() != 14
            || djzChiangXP1112HDLevel() != 8
            || djzChiangXP1112HDBase() != 5400
            || djzChiangXP1112HDPerHP() != 16
            || djzChiangAtWillSpellCount() != 7
            || djzChiangOncePerDaySpellCount() != 2
            || djzChiangLangCount() != 5
            || djzChiangLowerWaterSqMiPerAge() != 1
            || djzChiangHumanFormSwordPlus() != 5
            || djzChiangBodyguardShenMin() != 1
            || djzChiangBodyguardShenMax() != 6
            || djzChiangChildrenMin() != 2
            || djzChiangChildrenMax() != 4
            || djzChiangOutsideSpiritPct() != 75
            || djzChiangOutsideSpiritMin() != 1
            || djzChiangOutsideSpiritMax() != 4
            || djzChiangOutsideShenPct() != 40
            || djzChiangOutsideShenMin() != 1
            || djzChiangOutsideShenMax() != 2
            || djzTunMiNoApp() != 1
            || djzTunMiAC() != -1
            || djzTunMiMove() != 9
            || djzTunMiHDMin() != 10
            || djzTunMiHDMax() != 12
            || djzTunMiLairPct() != 20
            || djzTunMiAttacks() != 3
            || djzTunMiClawDmgMin() != 1
            || djzTunMiClawDmgMax() != 3
            || djzTunMiBiteDmgMin() != 2
            || djzTunMiBiteDmgMax() != 20
            || djzTunMiSizeMinFt() != 60
            || djzTunMiSizeMaxFt() != 80
            || djzTunMiXP1112HDBase() != 14400
            || djzTunMiXP1112HDPerHP() != 16
            || djzTunMiDivineWindMilesPerAge() != 5
            || djzTunMiDivineWindDurationDice() != 6
            || djzTunMiDivineWindDurationSides() != 4
            || djzTunMiLangCount() != 3
            || !djzDragonsCelestialOfficials()
            || !djzYearlyPalaceReport()
            || !djzCensorsRewardPunish()
            || !djzCorruptDragonsReplaced()
            || !djzChangesAnnouncedByDreams()
            || !djzHumansCurryFavorProcession()
            || !djzLiLungEarthEnergies()
            || !djzLungWangSeaGuardians()
            || !djzPanLungHiddenPlaces()
            || !djzShenLungAides()
            || !djzTienLungWeatherMasters()
            || !djzChiangLungPosition()
            || !djzTunMiLungPosition()
            || !djzYuLungNoPosition()
            || !djzChiangRare()
            || !djzChiangTreasureF()
            || !djzChiangIntHighToGenius()
            || !djzChiangLawfulNeutralGood()
            || !djzChiangPsionicNil()
            || !djzChiangRiverLakeLord()
            || !djzChiangEveryWaterPresent()
            || !djzChiangEmperorOrders()
            || !djzChiangPearlFlight()
            || !djzChiangPolymorphAny()
            || !djzChiangRainCloudBreath()
            || !djzChiangOfferingIntercession()
            || !djzChiangNoActionWithoutOrders()
            || !djzChiangUnderwaterEscort()
            || !djzChiangTsunamiOnOrders()
            || !djzChiangSwordBendBars()
            || !djzChiangPalaceUnderWaves()
            || !djzChiangStolenGoodsWorthless()
            || !djzChiangMansionHumanForm()
            || !djzChiangSpiritServants()
            || !djzChiangScholarBoatParties()
            || !djzChiangDaughterMarriages()
            || !djzTunMiVeryRare()
            || !djzTunMiTreasureF()
            || !djzTunMiMRStandard()
            || !djzTunMiIntAverage()
            || !djzTunMiNeutralEvil()
            || !djzTunMiSizeL()
            || !djzTunMiPsionicNil()
            || !djzTunMiSeaSkyHabitat()
            || !djzTunMiPearlFlight()
            || !djzTunMiTyphoonDuty()
            || !djzTunMiMaliciousRampages()
            || !djzTunMiDivineWindOncePerWeek()
            || !djzTunMiClawsAndBiteFallback()
            || !djzTunMiImmuneWaterAir()
            || !djzTunMiRemoteUnderseaLair()
        )
            ++bad;
        // the Celestial Bureaucracy
    if (djzBureauPositionRows() != 7
            || djzAdditionDragons() != 2
            || djzDragonsCelestialOfficials() != 1
            || djzYearlyPalaceReport() != 1
            || djzCensorsRewardPunish() != 1
            || djzCorruptDragonsReplaced() != 1
            || djzChangesAnnouncedByDreams() != 1
            || djzHumansCurryFavorProcession() != 1
            || djzLiLungEarthEnergies() != 1
            || djzLungWangSeaGuardians() != 1
            || djzPanLungHiddenPlaces() != 1
            || djzShenLungAides() != 1
            || djzTienLungWeatherMasters() != 1
            || djzChiangLungPosition() != 1
            || djzTunMiLungPosition() != 1
            || djzYuLungNoPosition() != 1
        )
            ++bad;
        // the chiang lung stat block
    if (djzChiangNoAppMin() != 1
            || djzChiangNoAppMax() != 2
            || djzChiangAC() != 2
            || djzChiangMoveWalk() != 12
            || djzChiangMoveSwim() != 18
            || djzChiangMoveFly() != 24
            || djzChiangHDMin() != 10
            || djzChiangHDMax() != 12
            || djzChiangLairPct() != 80
            || djzChiangAttacks() != 3
            || djzChiangClawDmgMin() != 1
            || djzChiangClawDmgMax() != 6
            || djzChiangBiteDmgMin() != 3
            || djzChiangBiteDmgMax() != 36
            || djzChiangMRPct() != 10
            || djzChiangSizeMinFt() != 50
            || djzChiangSizeMaxFt() != 60
            || djzChiangXP10HDBase() != 13750
            || djzChiangXP10HDPerHP() != 14
            || djzChiangXP1112HDLevel() != 8
            || djzChiangXP1112HDBase() != 5400
            || djzChiangXP1112HDPerHP() != 16
            || djzChiangRare() != 1
            || djzChiangTreasureF() != 1
            || djzChiangIntHighToGenius() != 1
            || djzChiangLawfulNeutralGood() != 1
            || djzChiangPsionicNil() != 1
        )
            ++bad;
        // the chiang lung nature
    if (djzChiangAtWillSpellCount() != 7
            || djzChiangOncePerDaySpellCount() != 2
            || djzChiangLangCount() != 5
            || djzChiangLowerWaterSqMiPerAge() != 1
            || djzChiangHumanFormSwordPlus() != 5
            || djzChiangBodyguardShenMin() != 1
            || djzChiangBodyguardShenMax() != 6
            || djzChiangChildrenMin() != 2
            || djzChiangChildrenMax() != 4
            || djzChiangOutsideSpiritPct() != 75
            || djzChiangOutsideSpiritMin() != 1
            || djzChiangOutsideSpiritMax() != 4
            || djzChiangOutsideShenPct() != 40
            || djzChiangOutsideShenMin() != 1
            || djzChiangOutsideShenMax() != 2
            || djzChiangRiverLakeLord() != 1
            || djzChiangEveryWaterPresent() != 1
            || djzChiangEmperorOrders() != 1
            || djzChiangPearlFlight() != 1
            || djzChiangPolymorphAny() != 1
            || djzChiangRainCloudBreath() != 1
            || djzChiangOfferingIntercession() != 1
            || djzChiangNoActionWithoutOrders() != 1
            || djzChiangUnderwaterEscort() != 1
            || djzChiangTsunamiOnOrders() != 1
            || djzChiangSwordBendBars() != 1
            || djzChiangPalaceUnderWaves() != 1
            || djzChiangStolenGoodsWorthless() != 1
            || djzChiangMansionHumanForm() != 1
            || djzChiangSpiritServants() != 1
            || djzChiangScholarBoatParties() != 1
            || djzChiangDaughterMarriages() != 1
        )
            ++bad;
        // the tun mi lung stat block
    if (djzTunMiNoApp() != 1
            || djzTunMiAC() != -1
            || djzTunMiMove() != 9
            || djzTunMiHDMin() != 10
            || djzTunMiHDMax() != 12
            || djzTunMiLairPct() != 20
            || djzTunMiAttacks() != 3
            || djzTunMiClawDmgMin() != 1
            || djzTunMiClawDmgMax() != 3
            || djzTunMiBiteDmgMin() != 2
            || djzTunMiBiteDmgMax() != 20
            || djzTunMiSizeMinFt() != 60
            || djzTunMiSizeMaxFt() != 80
            || djzTunMiXP1112HDBase() != 14400
            || djzTunMiXP1112HDPerHP() != 16
            || djzTunMiVeryRare() != 1
            || djzTunMiTreasureF() != 1
            || djzTunMiMRStandard() != 1
            || djzTunMiIntAverage() != 1
            || djzTunMiNeutralEvil() != 1
            || djzTunMiSizeL() != 1
            || djzTunMiPsionicNil() != 1
        )
            ++bad;
        // the tun mi lung nature
    if (djzTunMiDivineWindMilesPerAge() != 5
            || djzTunMiDivineWindDurationDice() != 6
            || djzTunMiDivineWindDurationSides() != 4
            || djzTunMiLangCount() != 3
            || djzTunMiSeaSkyHabitat() != 1
            || djzTunMiPearlFlight() != 1
            || djzTunMiTyphoonDuty() != 1
            || djzTunMiMaliciousRampages() != 1
            || djzTunMiDivineWindOncePerWeek() != 1
            || djzTunMiClawsAndBiteFallback() != 1
            || djzTunMiImmuneWaterAir() != 1
            || djzTunMiRemoteUnderseaLair() != 1
        )
            ++bad;
        printf("R712 OA monsters Oriental Dragons audit: bad %d\n", bad);
        if (bad) return 1;
    }
