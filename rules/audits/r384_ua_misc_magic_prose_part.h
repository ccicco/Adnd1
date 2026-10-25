    // ---- R384: the UA misc magic
    // prose part 4 pin audit ----
    // The R398 clean read fills
    // every flagged hole this
    // block names.
    // The I-P stretch: nine pins -
    // five fully clean (the iron
    // bands of Bilarro, the lens of
    // detection, the mantle of
    // Celestian, the pearl of the
    // sirines, the pouch of
    // accessibility) plus four
    // mechanics-clean with flagged
    // holes (the lens of
    // ultravision's diameter cell,
    // Murlynd's spoon's gruel tail,
    // the philosopher's stone's
    // transmutation cells, the
    // prison of Zagyg's attunement
    // seam); the R383 seam the
    // part-3 ledger, the R375 seam
    // the misc band.
    {
        using namespace rules;
        int bad = 0;
        // ---- the iron bands of
        // Bilarro ----
            if (uamm4IbaGlobeDiameterIn()
                    != 3) ++bad;
            if (!uamm4IbaAppearsRustySphere())
                ++bad;
            if (!uamm4IbaStrongIndeterminateDweomer())
                ++bad;
            if (!uamm4IbaNeedsCommandWord()) ++bad;
            if (!uamm4IbaHurlAtOpponent()) ++bad;
            if (!uamm4IbaUnadjustedToHitOnly())
                ++bad;
            if (!uamm4IbaSingleCreatureOnly())
                ++bad;
            if (!uamm4IbaHoldsGiantSize()) ++bad;
            if (!uamm4IbaImmobileUntilCommandAgain())
                ++bad;
            if (!uamm4IbaBreakEqualsBendBars())
                ++bad;
            if (!uamm4IbaBreakRuinsBands()) ++bad;
            if (uamm4IbaBreakAttempts() != 1)
                ++bad;
            if (!uamm4IbaInescapableAfterAttempt())
                ++bad;
            // the captive gets exactly
            // one break attempt
            if (uamm4IbaBreakAttempts()
                    != 1) ++bad;
        // ---- the lens of detection
        // ----
            if (!uamm4LdeDetectsMinuteThings())
                ++bad;
            if (uamm4LdeMinuteSeeingPct()
                    != 50) ++bad;
            if (!uamm4LdeTracksAsRanger()) ++bad;
            if (uamm4LdeTrackBaseSpeedIn() != 6)
                ++bad;
            if (uamm4LdeDiameterIn() != 6) ++bad;
            if (!uamm4LdeNeedsFrameAndHandle())
                ++bad;
            // the diameter matches the
            // track base speed, both 6
            if (uamm4LdeDiameterIn()
                    != uamm4LdeTrackBaseSpeedIn())
                ++bad;
        // ---- the lens of
        // ultravision ----
            if (!uamm4LulFacetedAquamarine())
                ++bad;
            if (!uamm4LulSensesUltraviolet()) ++bad;
            if (!uamm4LulDarknessAsMoonlight())
                ++bad;
            if (uamm4LulOutlineRangeFt() != 240)
                ++bad;
            if (uamm4LulDetailRangeFt() != 120)
                ++bad;
            if (!uamm4LulMustBeHeldBeforeEye())
                ++bad;
            if (uamm4LulDiameterTenthsIn() != 15) ++bad;
            if (uamm4LulDiameterCellGarbles())
                ++bad;
            // the detail range is
            // half the outline range
            if (2 * uamm4LulDetailRangeFt()
                    != uamm4LulOutlineRangeFt())
                ++bad;
        // ---- the mantle of
        // Celestian ----
            if (!uamm4MceBlackClothSeventhOrder())
                ++bad;
            if (!uamm4MceAlterationAura()) ++bad;
            if (!uamm4MceVoidOfSpaceSurvival())
                ++bad;
            if (!uamm4MceBreathesAsIfVentilated())
                ++bad;
            if (!uamm4MceProtectsAgainstPoisonGas())
                ++bad;
            if (uamm4MceSaveBonus() != 1) ++bad;
            if (!uamm4MceSaveVsElectricity()) ++bad;
            if (!uamm4MceSaveVsFire()) ++bad;
            if (!uamm4MceSaveVsNoise()) ++bad;
            if (!uamm4MceFoodOncePerDay()) ++bad;
            if (uamm4MceEwerGallons() != 7) ++bad;
            if (!uamm4MceEwerOncePerDay()) ++bad;
            if (!uamm4MceNoColdHotWetDamp()) ++bad;
            if (uamm4MceLargePockets() != 7) ++bad;
            if (uamm4MceSmallPockets() != 7) ++bad;
            if (uamm4McePocketsForFoodWater()
                    != 2) ++bad;
            if (uamm4MceRemainingPockets() != 12)
                ++bad;
            if (uamm4MceSmallPocketWeightGp()
                    != 70) ++bad;
            if (uamm4MceLargePocketWeightGp()
                    != 140) ++bad;
            if (!uamm4MceNoBulkOrAddedWeight())
                ++bad;
            if (!uamm4MceAuraPowerClericsOnly())
                ++bad;
            if (!uamm4MceAuraNeedsConcentration())
                ++bad;
            if (!uamm4MceAuraRevealsAlignmentIntent())
                ++bad;
            // the pocket counts: the
            // remaining twelve = the
            // seven large + the seven
            // small - the two food
            // and water pockets
            if (uamm4MceLargePockets()
                    != uamm4MceSmallPockets()) ++bad;
            if (uamm4MceLargePockets()
                    + uamm4MceSmallPockets()
                    - uamm4McePocketsForFoodWater()
                    != uamm4MceRemainingPockets())
                ++bad;
            // the large pocket holds
            // twice the small, 140
            // against 70
            if (2 * uamm4MceSmallPocketWeightGp()
                    != uamm4MceLargePocketWeightGp())
                ++bad;
        // ---- Murlynd's spoon ----
            if (!uamm4MslFashionedFromHorn())
                ++bad;
            if (!uamm4MslDimConjurationDweomer())
                ++bad;
            if (!uamm4MslFillsEmptyContainer())
                ++bad;
            if (!uamm4MslThickPastyGruel()) ++bad;
            if (!uamm4MslCardboardFlavor()) ++bad;
            if (!uamm4MslHighlyNourishing()) ++bad;
            if (uamm4MslFeedsHumansPerDay() != 4)
                ++bad;
            if (uamm4MslGruelTailGarbles()) ++bad;
        // ---- the pearl of the
        // sirines ----
            if (!uamm4PsiFaintEnchantmentAura())
                ++bad;
            if (uamm4PsiWorthGp() != 1000) ++bad;
            if (!uamm4PsiClaspedToActivate()) ++bad;
            if (!uamm4PsiWaterBreathing()) ++bad;
            if (uamm4PsiUnderwaterMoveIn() != 24)
                ++bad;
            if (!uamm4PsiImmuneToSirineTouch())
                ++bad;
            if (!uamm4PsiMustRemainNearby()) ++bad;
        // ---- the philosopher's
        // stone ----
            if (!uamm4PstSootyBlackishRock())
                ++bad;
            if (!uamm4PstFaintIndeterminateDweomer())
                ++bad;
            if (!uamm4PstGeodeCavity()) ++bad;
            if (!uamm4PstQuicksilverLined()) ++bad;
            if (!uamm4PstIronToSilver()) ++bad;
            if (!uamm4PstLeadToGold()) ++bad;
            if (uamm4PstIronLbsLo() != 50)
                ++bad;
            if (uamm4PstIronLbsHi() != 500)
                ++bad;
            if (uamm4PstLeadLbsLo() != 10)
                ++bad;
            if (uamm4PstLeadLbsHi() != 100)
                ++bad;
            if (!uamm4PstAlchemistOrMagicUser())
                ++bad;
            if (uamm4PstTransmutationCellsGarble())
                ++bad;
            if (!uamm4PstAllQuicksilverAtOnce())
                ++bad;
            if (!uamm4PstFirstAttemptOnly()) ++bad;
            if (uamm4PstLongevitySaltChancePct()
                    != 75) ++bad;
            if (uamm4PstLongevityPotionsLo() != 1)
                ++bad;
            if (uamm4PstLongevityPotionsHi() != 4)
                ++bad;
            if (uamm4PstWhitePowderChancePct()
                    != 25) ++bad;
            if (!uamm4PstPowderRestoresLife())
                ++bad;
            if (uamm4PstDemiseWeeks() != 1) ++bad;
            if (!uamm4PstCfRaiseDead()) ++bad;
            if (!uamm4PstValuesOnlyUnopened())
                ++bad;
            // the lead band is the
            // iron band divided by
            // five at both ends
            if (uamm4PstIronLbsLo()
                    / 5 != uamm4PstLeadLbsLo())
                ++bad;
            if (uamm4PstIronLbsHi()
                    / 5 != uamm4PstLeadLbsHi())
                ++bad;
            // the salt and powder
            // chances sum to a
            // certainty inside a
            // given stone, 75 + 25
            if (uamm4PstLongevitySaltChancePct()
                    + uamm4PstWhitePowderChancePct()
                    != 100) ++bad;
            // the longevity potions
            // ride the 1-4 range
            if (uamm4PstLongevityPotionsLo() >=
                    uamm4PstLongevityPotionsHi())
                ++bad;
        // ---- the pouch of
        // accessibility ----
            if (uamm4PacTotalWeightGp() != 3000)
                ++bad;
            if (uamm4PacPocketCount() != 30) ++bad;
            if (uamm4PacPocketWeightGp() != 100)
                ++bad;
            if (uamm4PacPocketCuFt() != 1) ++bad;
            if (!uamm4PacWhicheverFirst()) ++bad;
            if (!uamm4PacSpeakNameToSummon())
                ++bad;
            if (!uamm4PacAppearsAtTopReady()) ++bad;
            if (!uamm4PacLikeBagOfHolding()) ++bad;
            if (!uamm4PacPlacementStricturesApply())
                ++bad;
            if (uamm4PacWeightEmptyGp() != 10)
                ++bad;
            if (uamm4PacWeightFilledGp() != 40)
                ++bad;
            // the 3,000 gp total =
            // the 30 pockets x the
            // 100 gp per pocket
            if (uamm4PacPocketCount()
                    * uamm4PacPocketWeightGp()
                    != uamm4PacTotalWeightGp()) ++bad;
            // the filled-minus-empty
            // weight, 40 - 10,
            // matches the pocket
            // count, 30
            if (uamm4PacWeightFilledGp()
                    - uamm4PacWeightEmptyGp()
                    != uamm4PacPocketCount()) ++bad;
        // ---- the prison of
        // Zagyg ----
            if (uamm4PzaThoughtToExist() != 5)
                ++bad;
            if (!uamm4PzaAppearsAsBirdcage()) ++bad;
            if (!uamm4PzaNormalExamFails()) ++bad;
            if (uamm4PzaDetectVaguePct() != 50)
                ++bad;
            if (!uamm4PzaErroneousClassPossible())
                ++bad;
            if (uamm4PzaAttunementSeamGarbles())
                ++bad;
            if (!uamm4PzaActivationWord()) ++bad;
            if (!uamm4PzaDoorHeldByWizardLock())
                ++bad;
            if (!uamm4PzaOpensOnlyFromOutside())
                ++bad;
            if (!uamm4PzaOnlyMagicUserOpens())
                ++bad;
            if (!uamm4PzaTriggerWord()) ++bad;
            if (uamm4PzaEnchantCastingRounds() != 1)
                ++bad;
            if (!uamm4PzaNeedsTrueName()) ++bad;
            if (!uamm4PzaHistoryForNameless()) ++bad;
            if (!uamm4PzaSaveVsSpell()) ++bad;
            if (uamm4PzaShrinksToHeightIn() != 3)
                ++bad;
            if (!uamm4PzaTransportedIntoCage())
                ++bad;
            if (!uamm4PzaMagicFailsInside()) ++bad;
            if (!uamm4PzaPrisonerCannotEscape())
                ++bad;
            if (!uamm4PzaFreedByMagicUser()) ++bad;
            if (!uamm4PzaFreedByWishOrAlterReality())
                ++bad;
            if (!uamm4PzaImmuneToForceAndMagic())
                ++bad;
            if (!uamm4PzaHiddenFromLocation()) ++bad;
            if (!uamm4PzaFoundOnlyBySightHearing())
                ++bad;
            if (!uamm4PzaFreedomWord()) ++bad;
            if (!uamm4PzaFreedRestored()) ++bad;
            if (!uamm4PzaNoFoodOrDrinkNeeded())
                ++bad;
        // ---- the part ledger ----
            if (uamm4PartItemTotal() != 9) ++bad;
            if (uamm4PartCleanCount() != 9) ++bad;
            if (uamm4PartFlaggedCount() != 0)
                ++bad;
            if (uamm4PartGarbledCount() != 0)
                ++bad;
            if (uamm4PartCleanCount()
                    + uamm4PartFlaggedCount()
                    + uamm4PartGarbledCount()
                    != uamm4PartItemTotal()) ++bad;
        // ---- the R383 part-3 seam ----
            if (uamm3PartItemTotal() != 11) ++bad;
            if (uamm3PartCleanCount() != 11) ++bad;
            if (uamm3PartFlaggedCount() != 0)
                ++bad;
            if (uamm3PartGarbledCount() != 0)
                ++bad;
        // ---- the R375 skeleton seam ----
            // the misc magic rides the
            // 46-60 band with its
            // seven sub-bands
            if (uadsCategoryLo(4) != 46) ++bad;
            if (uadsCategoryHi(4) != 60) ++bad;
            if (uadsMiscSubCount() != 7) ++bad;
            if (uadsRowBodiesGarble()) ++bad;
        printf("R384 UA misc magic prose part 4 pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
