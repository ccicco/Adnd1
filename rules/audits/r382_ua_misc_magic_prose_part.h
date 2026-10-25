    // ---- R382: the UA misc magic
    // prose part 2 pin audit ----
    // The R398 clean read fills
    // every flagged hole this
    // block names.
    // The D-E stretch: eight pins -
    // one fully clean (the dust of
    // tracelessness) plus seven
    // mechanics-clean with flagged
    // holes (the deck of illusions'
    // card list, the dicerion's
    // description seam, the dust of
    // dryness' elemental-save cell,
    // the dust of illusion's intro,
    // the egg of desire's int seam,
    // the egg of reason's 18+ cell,
    // the egg of shattering's attack
    // seam); the R381 seam the
    // part-1 ledger, the R375 seam
    // the misc band.
    {
        using namespace rules;
        int bad = 0;
        // ---- the deck of illusions ----
            if (uamm2DekCardCount() != 34) ++bad;
            if (!uamm2DekAudialVisual()) ++bad;
            if (!uamm2DekLastsUntilDispelled())
                ++bad;
            if (uamm2DekLeashFt() != 30) ++bad;
            if (!uamm2DekCardBlanksAfterUse())
                ++bad;
            if (!uamm2DekPickupDispelsInstantly())
                ++bad;
            if (uamm2DekJokers() != 2) ++bad;
            if (uamm2DekCardListGarbles())
                ++bad;
        // ---- the dicerion ----
            if (!uamm2DicTwoBranches()) ++bad;
            if (uamm2DicHeightIn() != 1) ++bad;
            if (uamm2DicWeightGpLo() != 30
                    || uamm2DicWeightGpHi()
                    != 40) ++bad;
            if (!uamm2DicNeedsSpecialCandles())
                ++bad;
            if (!uamm2DicCandlesBlessedConsecrated())
                ++bad;
            if (!uamm2DicBothAlightSeeAll())
                ++bad;
            if (uamm2DicShadowDispelRadiusFt()
                    != 30) ++bad;
            if (!uamm2DicDispelNaturalShadowsOnly())
                ++bad;
            if (!uamm2DicDispelEndsVisionBoon())
                ++bad;
            if (uamm2DicBurnGentleLo() != 5
                    || uamm2DicBurnGentleHi()
                    != 8) ++bad;
            if (uamm2DicBurnStrongCutLo() != 1
                    || uamm2DicBurnStrongCutHi()
                    != 2) ++bad;
            if (uamm2DicBurnStillLo() != 9
                    || uamm2DicBurnStillHi()
                    != 16) ++bad;
            if (uamm2DicDarkSphereFt() != 15)
                ++bad;
            if (!uamm2DicDarkSphereWearerFree())
                ++bad;
            if (uamm2DicBrightLightBlindLo() != 1
                    || uamm2DicBrightLightBlindHi()
                    != 4) ++bad;
            if (!uamm2DicLightSphereWearerOk())
                ++bad;
            if (uamm2DicEvilBlindLo() != 2
                    || uamm2DicEvilBlindHi()
                    != 8) ++bad;
            if (uamm2DicGoodBlindLo() != 1
                    || uamm2DicGoodBlindHi()
                    != 4) ++bad;
            if (uamm2DicMagDarkBlindLo() != 1
                    || uamm2DicMagDarkBlindHi()
                    != 4) ++bad;
            if (!uamm2DicBothBranchesNeedTapers())
                ++bad;
            if (uamm2DicDescSeamGarbles())
                ++bad;
            // the still-air burn is
            // twice the gentle-draft
            // burn; the dark sphere
            // halves the shadow
            // dispel radius
            if (2 * uamm2DicBurnGentleHi()
                    != uamm2DicBurnStillHi()) ++bad;
            if (uamm2DicDarkSphereFt() * 2
                    != uamm2DicShadowDispelRadiusFt())
                ++bad;
        // ---- the dust of dryness ----
            if (uamm2DdrCuYardsPerPinch() != 1)
                ++bad;
            if (!uamm2DdrPelletReleasesSame())
                ++bad;
            if (!uamm2DdrSprinkleNegatesPrecip())
                ++bad;
            if (uamm2DdrSprinkleCuRods() != 1)
                ++bad;
            if (!uamm2DdrWaterFormsOnly()) ++bad;
            if (!uamm2DdrElementalSaveVsSpell())
                ++bad;
            if (uamm2DdrElementalDmgLo() != 6
                    || uamm2DdrElementalDmgHi()
                    != 30) ++bad;
            if (uamm2DdrElementalSeamGarbles())
                ++bad;
            if (uamm2DdrPouchLo() != 11
                    || uamm2DdrPouchHi() != 20)
                ++bad;
            if (!uamm2DdrWorksWhileHalfRemains())
                ++bad;
            // the elemental damage
            // ceiling is five times
            // its floor
            if (5 * uamm2DdrElementalDmgLo()
                    != uamm2DdrElementalDmgHi())
                ++bad;
        // ---- the dust of illusion ----
            if (!uamm2DilSimilarShapeOnly())
                ++bad;
            if (uamm2DilSizeVariancePct() != 50)
                ++bad;
            if (!uamm2DilUnwillingSaveEscapes())
                ++bad;
            if (!uamm2DilSprinklerEnvisions())
                ++bad;
            if (uamm2DilDurationLo() != 7
                    || uamm2DilDurationHi() != 12)
                ++bad;
            if (uamm2DilPouchLo() != 11
                    || uamm2DilPouchHi() != 20)
                ++bad;
            if (uamm2DilIntroGarbles()) ++bad;
        // ---- the dust of
        // tracelessness ----
            if (uamm2DtrChamberSqFt() != 1000)
                ++bad;
            if (!uamm2DtrDecadeLook()) ++bad;
            if (uamm2DtrTrailMenHorses() != 12)
                ++bad;
            if (uamm2DtrTrailMiles() != 1) ++bad;
            if (!uamm2DtrNoRadiation()) ++bad;
            if (uamm2DtrPouchLo() != 13
                    || uamm2DtrPouchHi() != 24)
                ++bad;
        // ---- the egg of desire ----
            if (uamm2EgdSortCount() != 5) ++bad;
            if (!uamm2EgdRocksAndChimes()) ++bad;
            if (!uamm2EgdViewerSaveVsSpell())
                ++bad;
            if (uamm2EgdViewingRangeFt() != 20)
                ++bad;
            if (!uamm2EgdBlackHoldsPermanent())
                ++bad;
            if (!uamm2EgdBonePrizedMagicItem())
                ++bad;
            if (!uamm2EgdCrystalAllGems()) ++bad;
            if (!uamm2EgdGoldenAllMetals()) ++bad;
            if (uamm2EgdScarletHoldMinutes()
                    != 1) ++bad;
            if (!uamm2EgdScarletRageAttacksFirst())
                ++bad;
            if (!uamm2EgdRemovalRemoveCurse()) ++bad;
            if (!uamm2EgdLowIntGrabsDropped())
                ++bad;
            if (uamm2EgdXpForSort(0) != 500
                    || uamm2EgdXpForSort(1) != 900
                    || uamm2EgdXpForSort(2) != 800
                    || uamm2EgdXpForSort(3) != 600
                    || uamm2EgdXpForSort(4) != 700)
                ++bad;
            if (uamm2EgdGpForSort(0) != 5000
                    || uamm2EgdGpForSort(1) != 10000
                    || uamm2EgdGpForSort(2) != 9000
                    || uamm2EgdGpForSort(3) != 4000
                    || uamm2EgdGpForSort(4) != 3500)
                ++bad;
            if (uamm2EgdIntSeamGarbles()) ++bad;
            // the bounds clamp holds;
            // the five XP values sum
            // to 3500
            if (uamm2EgdXpForSort(-3)
                    != uamm2EgdXpForSort(0)
                    || uamm2EgdGpForSort(9)
                    != uamm2EgdGpForSort(4)) ++bad;
            if (uamm2EgdXpForSort(0)
                    + uamm2EgdXpForSort(1)
                    + uamm2EgdXpForSort(2)
                    + uamm2EgdXpForSort(3)
                    + uamm2EgdXpForSort(4)
                    != 3500) ++bad;
        // ---- the egg of reason ----
            if (!uamm2EgrCoatedOilTimelessness())
                ++bad;
            if (!uamm2EgrSaveVsPoisonNoBonus())
                ++bad;
            if (!uamm2EgrPoisonNotNeutralizable())
                ++bad;
            if (uamm2EgrIntChancePct() != 60
                    || uamm2EgrWisChancePct()
                    != 40) ++bad;
            if (uamm2EgrGainPoints() != 1) ++bad;
            if (uamm2EgrSuccessChanceForScore(17)
                    != 66) ++bad;
            if (uamm2EgrSuccessChanceForScore(15)
                    != 70) ++bad;
            if (uamm2EgrHighScoreCellGarbles())
                ++bad;
            if (!uamm2EgrRacialLimitsApply())
                ++bad;
            if (!uamm2EgrOilRemovedStillPoison())
                ++bad;
            if (!uamm2EgrOilRemovedNoEnhance())
                ++bad;
            // the bounds clamp holds;
            // the printed example
            // reads 68%, a book
            // arithmetic slip - the
            // formula gives 100 -
            // (17 x 2) = 66;
            // the chances partition
            // 100
            if (uamm2EgrSuccessChanceForScore(0)
                    != uamm2EgrSuccessChanceForScore(
                        3)
                    || uamm2EgrSuccessChanceForScore(
                        25)
                    != uamm2EgrSuccessChanceForScore(
                        18)) ++bad;
            if (uamm2EgrIntChancePct()
                    + uamm2EgrWisChancePct()
                    != 100) ++bad;
        // ---- the egg of shattering ----
            if (!uamm2EgsShattersOnHandleOrDetect())
                ++bad;
            if (uamm2EgsFragRadiusIn() != 1) ++bad;
            if (!uamm2EgsActualAcOnly()) ++bad;
            if (!uamm2EgsNoDexBonus()) ++bad;
            if (uamm2EgsFragHitsLo() != 1
                    || uamm2EgsFragHitsHi() != 4)
                ++bad;
            if (uamm2EgsFragDmgLo() != 2
                    || uamm2EgsFragDmgHi() != 7)
                ++bad;
            if (uamm2EgsFragileAutoFt() != 1
                    || uamm2EgsFragileSaveFt()
                    != 2) ++bad;
            if (!uamm2EgsSaveVsCrushingBlow())
                ++bad;
            if (uamm2EgsAttackSeamGarbles())
                ++bad;
            // the save radius is
            // twice the automatic
            // radius
            if (2 * uamm2EgsFragileAutoFt()
                    != uamm2EgsFragileSaveFt())
                ++bad;
        // ---- the part ledger ----
            if (uamm2PartItemTotal() != 8) ++bad;
            if (uamm2PartCleanCount() != 8) ++bad;
            if (uamm2PartFlaggedCount() != 0)
                ++bad;
            if (uamm2PartGarbledCount() != 0)
                ++bad;
            if (uamm2PartCleanCount()
                    + uamm2PartFlaggedCount()
                    + uamm2PartGarbledCount()
                    != uamm2PartItemTotal()) ++bad;
        // ---- the R381 part-1 seam ----
            if (uammPartItemTotal() != 13) ++bad;
            if (uammPartCleanCount() != 13) ++bad;
            if (uammPartFlaggedCount() != 0)
                ++bad;
            if (uammPartGarbledCount() != 0)
                ++bad;
        // ---- the R375 skeleton seam ----
            // the misc magic rides the
            // 46-60 band with its
            // seven sub-bands
            if (uadsCategoryLo(4) != 46) ++bad;
            if (uadsCategoryHi(4) != 60) ++bad;
            if (uadsMiscSubCount() != 7) ++bad;
            if (uadsRowBodiesGarble()) ++bad;
        printf("R382 UA misc magic prose part 2 pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
