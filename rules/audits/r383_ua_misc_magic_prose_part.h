    // ---- R383: the UA misc magic
    // prose part 3 pin audit ----
    // The R398 clean read fills
    // every flagged hole this
    // block names.
    // The G-H stretch: eleven pins -
    // two fully clean (the gloves of
    // missile snaring, the hat of
    // stupidity) plus nine
    // mechanics-clean with flagged
    // holes (the gem of insight's
    // recall seam, the girdle of
    // dwarvenkind's racial block, the
    // girdle of many pouches' tail,
    // the gloves of thievery's level
    // cells, the hat of difference's
    // loss seam, the hat of disguise's
    // removal seam, the haversack's
    // quart merge, the horn of fog's
    // rounds/minutes seam, the horn of
    // goodness' eaten header); the
    // R382 seam the part-2 ledger,
    // the R375 seam the misc band.
    {
        using namespace rules;
        int bad = 0;
        // ---- the gem of insight ----
            if (uamm3GemMinValueGp() != 5000) ++bad;
            if (!uamm3GemFaintEnchantmentAura()) ++bad;
            if (uamm3GemFeelPowerWeeks() != 1) ++bad;
            if (uamm3GemUnderstandAfterWeeks()
                    != 2) ++bad;
            if (uamm3GemIntGain() != 1) ++bad;
            if (uamm3GemWisGain() != 1) ++bad;
            if (uamm3GemKeepMonths() != 3) ++bad;
            if (!uamm3GemIntStaysBeyondPeriod())
                ++bad;
            if (!uamm3GemWisLostBeyondPeriod())
                ++bad;
            if (!uamm3GemSecondGemInert()) ++bad;
            if (uamm3GemRecallSeamGarbles())
                ++bad;
            // the understanding arrives
            // at twice the feel-power week
            if (2 * uamm3GemFeelPowerWeeks()
                    != uamm3GemUnderstandAfterWeeks())
                ++bad;
        // ---- the girdle of
        // dwarvenkind ----
            if (uamm3GdkChaNonDwarvesAdj()
                    != -1) ++bad;
            if (uamm3GdkChaStoutHalflingsAdj()
                    != 1) ++bad;
            if (uamm3GdkChaGnomesAdj() != 1)
                ++bad;
            if (uamm3GdkChaDwarvesAdj() != 2)
                ++bad;
            if (!uamm3GdkSpeaksDwarvish()) ++bad;
            if (!uamm3GdkUndergroundSaveBonusesApply())
                ++bad;
            if (!uamm3GdkBenefitsOnlyWhileWorn())
                ++bad;
            if (!uamm3GdkNoGiantTypeAcBenefit())
                ++bad;
            if (!uamm3GdkNoExtraLanguages()) ++bad;
            if (uamm3GdkRacialBlockGarbles())
                ++bad;
            // dwarves regard at twice
            // the stout-halfling gain
            if (2 * uamm3GdkChaStoutHalflingsAdj()
                    != uamm3GdkChaDwarvesAdj())
                ++bad;
        // ---- the girdle of many
        // pouches ----
            if (!uamm3GmpStrongEnchantmentAura())
                ++bad;
            if (!uamm3GmpFainterAlterationAura())
                ++bad;
            if (uamm3GmpApparentPouches() != 8)
                ++bad;
            if (uamm3GmpTotalPouches() != 64)
                ++bad;
            if (uamm3GmpBehindEach() != 7) ++bad;
            if (uamm3GmpPouchCuFt() != 1) ++bad;
            if (uamm3GmpPouchLbs() != 10) ++bad;
            if (!uamm3GmpRespondsToThoughts())
                ++bad;
            if (!uamm3GmpFullOrEmptyAsDesired())
                ++bad;
            if (!uamm3GmpPrizedBySpellcasters())
                ++bad;
            if (uamm3GmpTailSeamGarbles()) ++bad;
            // the 64 total = the eight
            // apparent x (the seven
            // behind + the one seen)
            if (uamm3GmpApparentPouches()
                    * (uamm3GmpBehindEach() + 1)
                    != uamm3GmpTotalPouches()) ++bad;
        // ---- the gloves of
        // missile snaring ----
            if (!uamm3GmsSlightEnchantmentAura())
                ++bad;
            if (!uamm3GmsMeldWithHands()) ++bad;
            if (uamm3GmsUndetectableBeyondFt()
                    != 5) ++bad;
            if (!uamm3GmsNeedEmptyHands()) ++bad;
            if (!uamm3GmsCatchHandHurled()) ++bad;
            if (!uamm3GmsCatchWeaponPropelled())
                ++bad;
            if (!uamm3GmsCanReturnMissile()) ++bad;
            if (!uamm3GmsMagicReturnPreventsOnly())
                ++bad;
            if (!uamm3GmsMagicReturnNoAttack())
                ++bad;
        // ---- the gloves of
        // thievery ----
            if (!uamm3GthFaintEnchantmentAura())
                ++bad;
            if (!uamm3GthInvisibleExceptMagic())
                ++bad;
            if (uamm3GthLevelCellsGarble()) ++bad;
            if (uamm3GthBonusPctIfAdvanced() != 5)
                ++bad;
            if (!uamm3GthBonusNeedsStatedLevels())
                ++bad;
        // ---- the hat of
        // difference ----
            if (!uamm3HdfAssumesOtherProfession())
                ++bad;
            if (!uamm3HdfFirstLevelAbilityOnly())
                ++bad;
            if (!uamm3HdfXpInAssumedRole()) ++bad;
            if (!uamm3HdfXpCumulative()) ++bad;
            if (!uamm3HdfLevelRetainedOnRewearing())
                ++bad;
            if (!uamm3HdfProgressIndefinite())
                ++bad;
            if (!uamm3HdfLostIfDiscarded()) ++bad;
            if (uamm3HdfLossSeamGarbles()) ++bad;
            if (!uamm3HdfHitPointsStayActual())
                ++bad;
            if (!uamm3HdfAbilityScoresStayActual())
                ++bad;
        // ---- the hat of disguise ----
            if (!uamm3HdgHairAnyColor()) ++bad;
            if (!uamm3HdgEyesAnyColor()) ++bad;
            if (!uamm3HdgComplexionAnyColor())
                ++bad;
            if (!uamm3HdgSexChange()) ++bad;
            if (!uamm3HdgFacialMutable()) ++bad;
            if (uamm3HdgHeightPct() != 25) ++bad;
            if (uamm3HdgWeightPct() != 50) ++bad;
            if (!uamm3HdgRemovalDispelsInstantly())
                ++bad;
            if (!uamm3HdgReusableOverAndOver())
                ++bad;
            if (uamm3HdgRemovalSeamGarbles())
                ++bad;
            if (!uamm3HdgAppearsAsAccessories())
                ++bad;
            // the weight swing is
            // twice the height swing
            if (2 * uamm3HdgHeightPct()
                    != uamm3HdgWeightPct()) ++bad;
        // ---- the hat of
        // stupidity ----
            if (!uamm3HdsIndistinguishableByDetection())
                ++bad;
            if (!uamm3HdsOnlyWearingReveals())
                ++bad;
            if (!uamm3HdsWearerBelievesBeneficial())
                ++bad;
            if (!uamm3HdsWearerWantsHatOn()) ++bad;
            if (uamm3HdsIntLoweredTo() != 7) ++bad;
            if (uamm3HdsIntLoweredByIfAlreadyLow()
                    != 1) ++bad;
            if (!uamm3HdsOnlyRemoveCurseFrees())
                ++bad;
        // ---- the haversack ----
            if (!uamm3HavOrdinaryAppearance())
                ++bad;
            if (uamm3HavSidePouches() != 2) ++bad;
            if (uamm3HavSidePouchCuFt() != 2) ++bad;
            if (uamm3HavSidePouchLbs() != 20)
                ++bad;
            if (uamm3HavQuartMergeGarbles())
                ++bad;
            if (uamm3HavCentralCuFt() != 8) ++bad;
            if (uamm3HavCentralLbs() != 80) ++bad;
            if (!uamm3HavSoughtItemOnTop()) ++bad;
            if (uamm3HavSaveBonus() != 2) ++bad;
            // the central portion is
            // four times a side pouch,
            // in both volume and
            // weight; the save bonus
            // matches the side-pouch
            // count
            if (4 * uamm3HavSidePouchCuFt()
                    != uamm3HavCentralCuFt()) ++bad;
            if (4 * uamm3HavSidePouchLbs()
                    != uamm3HavCentralLbs()) ++bad;
            if (uamm3HavSaveBonus()
                    != uamm3HavSidePouches()) ++bad;
        // ---- the horn of fog ----
            if (!uamm3HfgSmallBuglelike()) ++bad;
            if (!uamm3HfgFogCloudEquivalent())
                ++bad;
            if (uamm3HfgCubePerRoundFt() != 10)
                ++bad;
            if (uamm3HfgCloudLastsLoRounds()
                    != 2) ++bad;
            if (uamm3HfgCloudLastsHiRounds()
                    != 8) ++bad;
            if (!uamm3HfgPauseStartsNewCloud())
                ++bad;
            if (uamm3HfgRoundsMinutesSeamGarbles())
                ++bad;
        // ---- the horn of
        // goodness ----
            if (!uamm3HgdAdaptsToEthicalDisposition())
                ++bad;
            if (uamm3HgdHeaderSeamGarbles()) ++bad;
            if (!uamm3HgdNeutralNoPower()) ++bad;
            if (!uamm3HgdGoodProtectionFromEvil())
                ++bad;
            if (uamm3HgdRadiusFt() != 10) ++bad;
            if (uamm3HgdDurationRounds() != 10)
                ++bad;
            if (!uamm3HgdAlliesAffectedToo())
                ++bad;
            if (!uamm3HgdEvilReversesSpell()) ++bad;
            if (!uamm3HgdOncePerDay()) ++bad;
            // the protection radius
            // matches the duration,
            // both 10
            if (uamm3HgdRadiusFt()
                    != uamm3HgdDurationRounds()) ++bad;
        // ---- the part ledger ----
            if (uamm3PartItemTotal() != 11) ++bad;
            if (uamm3PartCleanCount() != 11) ++bad;
            if (uamm3PartFlaggedCount() != 0)
                ++bad;
            if (uamm3PartGarbledCount() != 0)
                ++bad;
            if (uamm3PartCleanCount()
                    + uamm3PartFlaggedCount()
                    + uamm3PartGarbledCount()
                    != uamm3PartItemTotal()) ++bad;
        // ---- the R382 part-2 seam ----
            if (uamm2PartItemTotal() != 8) ++bad;
            if (uamm2PartCleanCount() != 8) ++bad;
            if (uamm2PartFlaggedCount() != 0)
                ++bad;
            if (uamm2PartGarbledCount() != 0)
                ++bad;
        // ---- the R375 skeleton seam ----
            // the misc magic rides the
            // 46-60 band with its
            // seven sub-bands
            if (uadsCategoryLo(4) != 46) ++bad;
            if (uadsCategoryHi(4) != 60) ++bad;
            if (uadsMiscSubCount() != 7) ++bad;
            if (uadsRowBodiesGarble()) ++bad;
        printf("R383 UA misc magic prose part 3 pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
