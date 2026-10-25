    // ---- R391: the UA
    // pole-arm nomenclature
    // appendix T pin audit ----
    // The pp. 123-129 stretch:
    // seven items pin - two
    // fully clean (the spear
    // family, the axe family)
    // plus five mechanics-clean
    // with flagged holes (the
    // classification system
    // paragraph, the fauchard
    // description, the Lucern/
    // bec comparison tail, the
    // combination intro and
    // features list, the
    // confusion sentence) -
    // RESOLVED (R424): the
    // clean pp. 123-128 read
    // resolves all five; the
    // R340 seam the hook
    // fauchard roster.
    {
        using namespace rules;
        int bad = 0;
            if (!uapaDefWeaponOnStick()) ++bad;
            if (!uapaInfantryWeapons()) ++bad;
            if (!uapaReachAdvantage()) ++bad;
            if (uapaUltimatePikeMinFt() != 18) ++bad;
            if (uapaUltimatePikeMaxFt() != 21) ++bad;
            if (!uapaAxeOnFiveFtHaftStillPoleArm()) ++bad;
            if (uapaMinHaftLengthFt() != 5) ++bad;
            if (uapaScaleDrawingDivisor() != 20) ++bad;
            if (uapaScaleLanceFeet() != 15) ++bad;
            if (!uapaShaftThicknessNotScale()) ++bad;
            if (!uapaNamingConfusionCommon()) ++bad;
            if (!uapaSaxtorphMorningStarMisnamed()) ++bad;
            if (!uapaMaceShortShaftedFlanged()) ++bad;
            if (!uapaMorningStarLongerSpiked()) ++bad;
            if (!uapaSystemParagraphReadsClean()) ++bad;
            if (!uapaHuntingOrAgriculturalOrigin()) ++bad;
            if (!uapaSpecializedOrCombination()) ++bad;
            if (!uapaSpearDaggerAtopPole()) ++bad;
            if (!uapaSpearThrustingPrimary()) ++bad;
            if (!uapaOxTongueSecondaryCutting()) ++bad;
            if (uapaAshSpearTwelveFt() != 12) ++bad;
            if (!uapaSpearConfusedWithPikes()) ++bad;
            if (!uapaLanceMountedSpear()) ++bad;
            if (uapaNormanLanceFt() != 12) ++bad;
            if (uapaLaterLanceFt() != 14) ++bad;
            if (uapaLanceReachBeyondHorseHeadFt() != 10) ++bad;
            if (!uapaLanceNotFootmansWeapon()) ++bad;
            if (uapaPikeShaftMinFt() != 15) ++bad;
            if (!uapaPikeThrustingLongRange()) ++bad;
            if (!uapaPikeUsedInMass()) ++bad;
            if (!uapaAwlPikePiercingOnly()) ++bad;
            if (uapaPikeShaftGuardFt() != 2) ++bad;
            if (!uapaSpetumTwoForwardBlades()) ++bad;
            if (uapaSpetumBladeAngleDeg() != 45) ++bad;
            if (!uapaSpetumClassCorseque()) ++bad;
            if (!uapaRanseurBackwardHooks()) ++bad;
            if (!uapaRanseurTrapAndDisarm()) ++bad;
            if (!uapaRanseurPullsRidersDown()) ++bad;
            if (uapaRanseurSynonymCount() != 5) ++bad;
            if (!uapaPartisanSpearWithAxeHeads()) ++bad;
            if (!uapaBohemianEarspoonSpikes()) ++bad;
            if (uapaSpearFamilyCount() != 5) ++bad;
            if (!uapaSpearFamilyDaggersTrimmed()) ++bad;
            if (uapaAxeHeadFormCount() != 2) ++bad;
            if (!uapaNarrowHeadThicker()) ++bad;
            if (!uapaCleaverButcheringAdapted()) ++bad;
            if (!uapaAxePrimaryChopping()) ++bad;
            if (!uapaPoleAxeAxeHeadLongHaft()) ++bad;
            if (!uapaPoleAxeVariants()) ++bad;
            if (!uapaHalberdConvexBroadAxe()) ++bad;
            if (uapaHalberdTotalFt() != 8) ++bad;
            if (!uapaHalberdSpearPointTop()) ++bad;
            if (!uapaHalberdBackSpikeAngled()) ++bad;
            if (!uapaHalberdSpikePenetratesPlate()) ++bad;
            if (!uapaHalberdHookDismounts()) ++bad;
            if (uapaHalberdArbedoYear() != 1422) ++bad;
            if (!uapaHalberdPiercingAxeSmaller()) ++bad;
            if (!uapaParadeArmsExist()) ++bad;
            if (!uapaBardicheTransitionalForm()) ++bad;
            if (uapaBardicheHeadMinFt() != 2) ++bad;
            if (uapaBardicheHeadMaxFt() != 3) ++bad;
            if (!uapaBardicheRingsOrHammerBack()) ++bad;
            if (!uapaBardicheHeavierThanHalberd()) ++bad;
            if (!uapaBardicheEasternEurope()) ++bad;
            if (uapaAxeFamilyTrueMemberCount() != 3) ++bad;
            if (!uapaBrownBillHalberdSansSpike()) ++bad;
            if (!uapaPeasantCleaverOrigin()) ++bad;
            if (!uapaFauchardSickleDevelopment()) ++bad;
            if (!uapaFauchardDismountFunction()) ++bad;
            if (!uapaFauchardDescriptionReadsClean()) ++bad;
            if (!uapaFauchardPassedOutEarly()) ++bad;
            if (!uapaFauchardForkRemained()) ++bad;
            if (!uapaGlaiveKnifeBladedSpear()) ++bad;
            if (!uapaGlaiveThrustPlusCutting()) ++bad;
            if (!uapaGlaiveEnlargedForCleaving()) ++bad;
            if (!uapaGlaiveGuisarmeModification()) ++bad;
            if (!uapaGlaiveWeakAtHolding()) ++bad;
            if (!uapaGuisarmePruningHookOrigin()) ++bad;
            if (!uapaGuisarmeSharpConvexEdge()) ++bad;
            if (!uapaGuisarmeHookPullsHorsemen()) ++bad;
            if (!uapaGuisarmeNoSpearPoint()) ++bad;
            if (!uapaGuisarmeSecondGeneration()) ++bad;
            if (!uapaVoulgeHeftyCleaverShaft()) ++bad;
            if (!uapaVoulgeCleavesArmor()) ++bad;
            if (!uapaVoulgeGroundTipDagger()) ++bad;
            if (!uapaVoulgeBackedSpikeCrude()) ++bad;
            if (!uapaLochaberEarlyFormVoulge()) ++bad;
            if (!uapaLochaberHookAdded()) ++bad;
            if (!uapaLochaberEqualsGuisarmeVoulge()) ++bad;
            if (!uapaLochaberScotsVoulgeContinental()) ++bad;
            if (!uapaBillHookEnglishGuisarme()) ++bad;
            if (!uapaBillConcaveEdgeSharp()) ++bad;
            if (!uapaBillLTineForward()) ++bad;
            if (!uapaBillSlightlyMoreEffective()) ++bad;
            if (!uapaMilitaryForkHayForkOrigin()) ++bad;
            if (uapaMilitaryForkTwoPoints() != 2) ++bad;
            if (!uapaMilitaryForkThirdTine()) ++bad;
            if (!uapaMilitaryForkWeakVsArmor()) ++bad;
            if (!uapaFlailSwivelOrChain()) ++bad;
            if (!uapaHorsemanFlailIronBalls()) ++bad;
            if (uapaPeasantFlailShaftMinFt() != 3) ++bad;
            if (uapaPeasantFlailShaftMaxFt() != 4) ++bad;
            if (!uapaPeasantFlailOneOrTwoRods()) ++bad;
            if (!uapaPeasantFlailOverFiveFt()) ++bad;
            if (!uapaMorningStarHaftThreeFt()) ++bad;
            if (!uapaMorningStarSpikedHead()) ++bad;
            if (!uapaMorningStarHolyWaterSprinkler()) ++bad;
            if (!uapaMorningStarGodentag()) ++bad;
            if (!uapaMorningStarSwissThenHalberd()) ++bad;
            if (!uapaMorningStarSometimesPoleArm()) ++bad;
            if (!uapaMilitaryPicksPoleMounted()) ++bad;
            if (!uapaTwoPureWeaponForms()) ++bad;
            if (!uapaLucernLikeHalberd()) ++bad;
            if (!uapaLucernLongerSpike()) ++bad;
            if (!uapaLucernThreeProngHead()) ++bad;
            if (!uapaLucernReplacedByHalberd()) ++bad;
            if (uapaLucernAfterCentury() != 14) ++bad;
            if (!uapaBecDeCorbinKnightsWeapon()) ++bad;
            if (!uapaBecDeCorbinBeakPunctures()) ++bad;
            if (!uapaBecDeCorbinBeakMajor()) ++bad;
            if (!uapaBecMoreSpecializedThanLucern()) ++bad;
            if (!uapaLucernBecComparisonReadsClean()) ++bad;
            if (!uapaSecondarySpearTipCombination()) ++bad;
            if (!uapaPartisanNotCombination()) ++bad;
            if (!uapaCombinationIntroReadsClean()) ++bad;
            if (uapaFauchardForkFormCount() != 2) ++bad;
            if (!uapaFauchardForkFormOneBackSpike()) ++bad;
            if (!uapaFauchardForkFormTwoReversed()) ++bad;
            if (!uapaFauchardGuisarmeScytheHook()) ++bad;
            if (!uapaGlaiveGuisarmeHookJerks()) ++bad;
            if (!uapaGuisarmeVoulgeHookFromBlade()) ++bad;
            if (!uapaGuisarmeVoulgeAllPurpose()) ++bad;
            if (uapaBillGuisarmeFeatureCount() != 4) ++bad;
            if (!uapaBillGuisarmeFeaturesReadsClean()) ++bad;
            if (!uapaBillGuisarmeVoulgeLike()) ++bad;
            if (!uapaBillGuisarmePersistedLongest()) ++bad;
            if (!uapaScorpionBillGuisarmeForm()) ++bad;
            if (!uapaIdentifyByMajorWeapon()) ++bad;
            if (!uapaPartisanWithAxeNotPoleAxe()) ++bad;
            if (!uapaStoneForkMisidentified()) ++bad;
            if (!uapaHalberdWithIncidentalFork()) ++bad;
            if (!uapaConfusionSentenceReadsClean()) ++bad;
            if (!uapaCareShaftLengthHeadShape()) ++bad;
            if (!uapaInfantryVsCavalryPurpose()) ++bad;
            if (uapaSwissPikePct() != 40) ++bad;
            if (uapaSwissHalberdPct() != 40) ++bad;
            if (uapaSwissMorningStarPct() != 20) ++bad;
            if (!uapaPikeKeepsHorsemenDistant()) ++bad;
            if (!uapaPikemenRearHigher()) ++bad;
            if (!uapaMassiveHeadsTooCumbersome()) ++bad;
            if (!uapaSpearTypesLengthenedToPikes()) ++bad;
            if (!uapaPikeShaftTooLongForHeads()) ++bad;
            if (!uapaShortenedCleaversToHalberd()) ++bad;
            if (!uapaGuisarmeVoulgeTypically()) ++bad;
            if (!uapaEvolutionReflectsArmor()) ++bad;
            if (!uapaSystemDerivedBritannica()) ++bad;
            if (uapaBibliographySourceCount() != 5) ++bad;
            if (uapaPartItemTotal() != 7) ++bad;
            if (uapaPartCleanCount() != 7) ++bad;
            if (uapaPartFlaggedCount() != 0) ++bad;
            if (uapaPartGarbledCount() != 0) ++bad;
            if (uapaSwissPikePct()
                + uapaSwissHalberdPct()
                + uapaSwissMorningStarPct()
                != 100) ++bad;
            if (uapaUltimatePikeMaxFt()
                - uapaUltimatePikeMinFt() != 3)
                ++bad;
            if (uapaPikeShaftMinFt()
                - uapaAshSpearTwelveFt() != 3)
                ++bad;
            if (uapaBardicheHeadMaxFt()
                - uapaBardicheHeadMinFt() != 1)
                ++bad;
            if (uapaPeasantFlailShaftMaxFt()
                - uapaPeasantFlailShaftMinFt()
                != 1) ++bad;
            if (uapaScaleDrawingDivisor()
                != 20) ++bad;
            if (uapaFauchardForkFormCount()
                != 2) ++bad;
            if (uapaSpearFamilyCount()
                + uapaAxeFamilyTrueMemberCount()
                < uapaPartItemTotal()) ++bad;
            if (uanwHookFauchardDismountPct()
                != 20) ++bad;
            if (uanwHookFauchardSizeReqPct()
                != 50) ++bad;
        printf("R391 UA pole-arm nomenclature pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
