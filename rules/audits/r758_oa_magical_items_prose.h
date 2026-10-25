    // ---- R758 OA magical items prose audit ----
    // OA round one hundred forty-five (capture pp. 296-301): the Oriental
    // Magical Items prose - the thirty-four item descriptions, the banner and
    // bells through the wondrous writing set, the minyan powers and care,
    // single-pass pins per the Chapter 9 provenance shift
    {
        using namespace rules;
        int bad = 0;
    if (dltBannerSpellBlockLevel() != 5
            || dltBannerRadiusYd() != 100
            || dltBellProtRadiusYd() != 50
            || dltBellProtGreaterSavePenalty() != 4
            || dltBellProtCrossDamageDice() != 4
            || dltBellProtWithinDamageDice() != 3
            || dltBellWarnRadiusFt() != 30
            || dltBellWarnHoursDie() != 6
            || dltBellWarnChargesDie() != 10
            || dltBiwaDiscordRadiusFt() != 3
            || dltBiwaDiscordFrenzyMin() != 2
            || dltBiwaDiscordFrenzyMax() != 5
            || dltCharmFireCatchPct() != 50
            || dltCharmTheftSkillPenaltyPct() != 20
            || dltCharmTheftRemoveDamageDie() != 10
            || dltDiamondMaceBoltDice() != 12
            || dltDiamondMaceChargesDie() != 10
            || dltDiamondMaceValueChien() != 1000
            || dltDrumsFlyCharges() != 1
            || dltDrumsTrapezeCharges() != 3
            || dltDrumsPanicCharges() != 2
            || dltDrumsWeatherCharges() != 1
            || dltDrumsBoltDice() != 20
            || dltDrumsBoltCharges() != 5
            || dltDrumsChargesDie() != 10
            || dltEightCoinsCount() != 8
            || dltMortarCommonPct() != 80
            || dltMortarFoodPeopleDie() != 100
            || dltMortarWishesDie() != 4
            || dltGemWishesMin() != 1
            || dltGemWishesMax() != 4
            || dltGemValueMinChien() != 100
            || dltGemValueMaxChien() != 1000
            || dltGongCasterLevel() != 15
            || dltGongChargesDie() != 100
            || dltMalletLuckBonus() != 2
            || dltMalletLuckTurns() != 6
            || dltMalletLuckDamageDie() != 6
            || dltMinyanBearers() != 20
            || dltMinyanFearRadiusFt() != 3
            || dltMinyanRemoveCursesPerDay() != 3
            || dltMinyanCasterLevel() != 20
            || dltMinyanSoheiMoralePct() != 10
            || dltMirrorCuringChargesDie() != 4
            || dltMirrorFearFleeDie() != 6
            || dltNoisomeStringCount() != 100
            || dltNoisomeFleeMin() != 2
            || dltNoisomeFleeMax() != 5
            || dltPaperFormsIgnitePct() != 80
            || dltPaperFormsSheetsDie() != 4
            || dltPearlTideRadiusFt() != 60
            || dltPearlTideRateFt() != 5
            || dltScrollSpiritsCasterLevel() != 12
            || dltSealDeceptionStampErrorPct() != 5
            || dltSealDeceptionMemoryErrorPct() != 30
            || dltTabletSpellLevel() != 9
            || dltTabletCharsDie() != 6
            || dltTabletValueChien() != 10
            || dltWheelsFireRadiusFt() != 30
            || dltWheelsFireDamageDie() != 6
            || dltWritingSetCalligraphyBonus() != 2
            || dltWritingSetPagesMin() != 2
            || dltWritingSetPagesMax() != 5
            || !dltBannerOfProtection()
            || !dltBellOfProtection()
            || !dltBellOfWarning()
            || !dltBiwaOfCalm()
            || !dltBiwaOfCharm()
            || !dltBiwaOfDiscord()
            || !dltCharmOfProtectionFromDisease()
            || !dltCharmOfProtectionFromFire()
            || !dltCharmOfProtectionFromSpirits()
            || !dltCharmOfProtectionFromTheft()
            || !dltDiamondMace()
            || !dltDrumsOfThunder()
            || !dltEightDiagramCoins()
            || !dltEverproducingRiceMortar()
            || !dltGemOfWishes()
            || !dltGongOfDispelling()
            || !dltMalletOfLuck()
            || !dltMinyanPowers()
            || !dltMinyanCare()
            || !dltMirrorOfCuring()
            || !dltMirrorOfEnlightenment()
            || !dltMirrorOfFear()
            || !dltMirrorOfSpiritSeeing()
            || !dltNetOfSpiritSnaring()
            || !dltNoisomeSpiritChasers()
            || !dltPaperOfForms()
            || !dltPearlOfProtectionFromFire()
            || !dltPearlOfEbbingTide()
            || !dltPearlOfRisingTide()
            || !dltScrollOfProtectionFromSpirits()
            || !dltSealOfDeception()
            || !dltSealOfVigor()
            || !dltTabletOfSpiritSummoning()
            || !dltWheelsOfFire()
            || !dltWondrousWritingSet()
        )
            ++bad;
        // the banner, bells, and biwa, healthy values, each condition false
    if (dltBannerSpellBlockLevel() != 5
            || dltBannerRadiusYd() != 100
            || dltBellProtRadiusYd() != 50
            || dltBellProtGreaterSavePenalty() != 4
            || dltBellProtCrossDamageDice() != 4
            || dltBellWarnRadiusFt() != 30
            || dltBiwaDiscordFrenzyMin() != 2
            || dltBiwaDiscordFrenzyMax() != 5
            || dltBannerOfProtection() != 1
            || dltBellOfProtection() != 1
            || dltBiwaOfCalm() != 1
        )
            ++bad;
        // the charms, mace, drums, and mortar, healthy values, each condition
        // false
    if (dltCharmFireCatchPct() != 50
            || dltCharmTheftSkillPenaltyPct() != 20
            || dltCharmTheftRemoveDamageDie() != 10
            || dltDiamondMaceBoltDice() != 12
            || dltDiamondMaceValueChien() != 1000
            || dltDrumsBoltDice() != 20
            || dltDrumsBoltCharges() != 5
            || dltEightCoinsCount() != 8
            || dltMortarCommonPct() != 80
            || dltMortarWishesDie() != 4
        )
            ++bad;
        // the gem, gong, mallet, and minyan, healthy values, each condition
        // false
    if (dltGemWishesMin() != 1
            || dltGemWishesMax() != 4
            || dltGemValueMaxChien() != 1000
            || dltGongCasterLevel() != 15
            || dltGongChargesDie() != 100
            || dltMalletLuckBonus() != 2
            || dltMalletLuckTurns() != 6
            || dltMalletLuckDamageDie() != 6
            || dltMinyanBearers() != 20
            || dltMinyanSoheiMoralePct() != 10
        )
            ++bad;
        // the mirrors, chasers, paper, and pearls, healthy values, each
        // condition false
    if (dltMirrorCuringChargesDie() != 4
            || dltMirrorFearFleeDie() != 6
            || dltNoisomeStringCount() != 100
            || dltNoisomeFleeMax() != 5
            || dltPaperFormsIgnitePct() != 80
            || dltPaperFormsSheetsDie() != 4
            || dltPearlTideRadiusFt() != 60
            || dltPearlTideRateFt() != 5
            || dltScrollSpiritsCasterLevel() != 12
        )
            ++bad;
        // the seals, tablet, wheels, and writing set, healthy values, each
        // condition false
    if (dltSealDeceptionStampErrorPct() != 5
            || dltSealDeceptionMemoryErrorPct() != 30
            || dltTabletSpellLevel() != 9
            || dltTabletCharsDie() != 6
            || dltTabletValueChien() != 10
            || dltWheelsFireRadiusFt() != 30
            || dltWheelsFireDamageDie() != 6
            || dltWritingSetCalligraphyBonus() != 2
            || dltWritingSetPagesMin() != 2
            || dltWritingSetPagesMax() != 5
            || dltWondrousWritingSet() != 1
        )
            ++bad;
        printf("R758 OA magical items prose audit: bad %d\n", bad);
        if (bad) return 1;
    }
