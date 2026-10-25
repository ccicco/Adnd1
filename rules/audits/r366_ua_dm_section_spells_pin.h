    // ---- R366: the UA DM-section spells
    // pin audit ----
    // The UA DM-section spell block (pp.
    // 79-83): the MAGIC-USER SPELL BOOKS
    // (the capacities 36/24/16/8 with the
    // one-fourth travelling 9/6/4/2, the
    // costs, the physical aspects, the
    // values, the direct-casting and
    // learning reads), the SPELL
    // EXPLANATIONS commentary (the
    // permanency lists, the 5/100 percent
    // constitution-loss reads, the
    // Serten's immunity commentary with
    // the bonus band assignment flagged),
    // the UNDERWATER SPELL USE lists (the
    // cannot-use rosters with the
    // airy-water footnote, the altered
    // effects - the MU cantrip row and the
    // MU/IL list boundary garble, flagged)
    // and the EFFECTS OF DARKNESS ladder.
    // Four items flip CLOSED; the census
    // 292 -> 293.
    {
        using namespace rules;
        int bad = 0;
        // ---- uabk pins ----
            if (uabkStandardCantripsCapacity() != 36) ++bad;
            if (uabkStandardLowLevelSpells() != 24) ++bad;
            if (uabkStandardMidLevelSpells() != 16) ++bad;
            if (uabkStandardHighLevelSpells() != 8) ++bad;
            if (!uabkTravellingIsOneFourth()) ++bad;
            if (uabkTravellingCantripsCapacity() != 9) ++bad;
            if (uabkTravellingLowLevelSpells() != 6) ++bad;
            if (uabkTravellingMidLevelSpells() != 4) ++bad;
            if (uabkTravellingHighLevelSpells() != 2) ++bad;
            if (uabkStandardMaterialsCostGp() != 1000) ++bad;
            if (uabkPerSpellLevelCostGp() != 100) ++bad;
            if (!uabkCantripsCountAsFirstLevel()) ++bad;
            if (!uabkInitialBooksBorneByMaster()) ++bad;
            if (uabkInitialBookCountMax() != 2) ++bad;
            if (!uabkLaterBooksSelfComposed()) ++bad;
            if (uabkCompositionWeeksMin() != 4) ++bad;
            if (uabkCompositionWeeksMax() != 7) ++bad;
            if (!uabkCompositionRidesLevelTraining()) ++bad;
            if (uabkEnterFirstLevelCostGp() != 100) ++bad;
            if (uabkEnterSecondLevelCostGp() != 200) ++bad;
            if (uabkTravellingCostFragmentGp() != 500) ++bad;
            if (!uabkTravellingCostIsFragmentRead()) ++bad;
            if (uabkStandardHeightInches() != 16) ++bad;
            if (uabkStandardWidthInches() != 12) ++bad;
            if (uabkStandardThicknessInches() != 6) ++bad;
            if (!uabkDmMayResizeTheBook()) ++bad;
            if (uabkMinSizeHeightInches() != 12) ++bad;
            if (uabkMinSizeWidthInches() != 12) ++bad;
            if (uabkMinSizeThicknessInches() != 6) ++bad;
            if (uabkMaxSizeHeightInches() != 18) ++bad;
            if (uabkMaxSizeWidthInches() != 12) ++bad;
            if (uabkMaxSizeThicknessInches() != 9) ++bad;
            if (uabkMedianWeightGp() != 150) ++bad;
            if (!uabkWeightAdjustedForSize()) ++bad;
            if (!uabkEncumbranceCellLost()) ++bad;
            if (!uabkFitsBackpackOrLargeSack()) ++bad;
            if (!uabkCoverHeavyLeatherInlaidMetal()) ++bad;
            if (!uabkVellumPagesSewnToSpine()) ++bad;
            if (!uabkVellumStubsForAddedPages()) ++bad;
            if (!uabkStubsDoNotChangeCapacity()) ++bad;
            if (!uabkSaveAsLeatherOrBook()) ++bad;
            if (uabkSaveBonusVsAcidFireDisintLightning() != 2) ++bad;
            if (uabkTravellingTallInches() != 12) ++bad;
            if (uabkTravellingWideInches() != 6) ++bad;
            if (!uabkTravellingThickCellLost()) ++bad;
            if (!uabkTravellingWeightCellLost()) ++bad;
            if (!uabkTravellingEncumbranceCellLost()) ++bad;
            if (uabkTravellingFitPerLargeSack() != 5) ++bad;
            if (!uabkTravellingCoverGiantCobraLeather()) ++bad;
            if (!uabkTravellingPagesThinFragile()) ++bad;
            if (!uabkTravellingLockOrLeatherTies()) ++bad;
            if (!uabkTravellingSaveNoBonus()) ++bad;
            if (uabkXpValuePerSpellLevel() != 500) ++bad;
            if (uabkSaleValuePerSpellLevelGp() != 1000) ++bad;
            if (!uabkSellImmediatelyOrTakeXp()) ++bad;
            if (!uabkNoKeepTranscribeThenSell()) ++bad;
            if (!uabkInExtremisDmMayAllowDirectCast()) ++bad;
            if (!uabkBookMustMatchCasterProfession()) ++bad;
            if (!uabkCasterMustKnowAndUseSpell()) ++bad;
            if (!uabkDirectCastDiffersFromScrolls()) ++bad;
            if (!uabkDirectCastDestroysTheSpell()) ++bad;
            if (uabkNeighborDestroyPctPerLevel() != 1) ++bad;
            if (uabkWholeBookDestroyPct() != 1) ++bad;
            if (!uabkPermanencyDoesNotPreventLoss()) ++bad;
            if (!uabkWritingRemainsButNotMagical()) ++bad;
            if (!uabkStricturesApplyToAnyBook()) ++bad;
            if (!uabkReadMagicNeededForOthersBook()) ++bad;
            if (!uabkLearnSpellFromAnotherBook()) ++bad;
            if (uabkStudyHoursPerLevelMin() != 2) ++bad;
            if (uabkStudyHoursPerLevelMax() != 8) ++bad;
            if (!uabkLearnedSpellImmediatelyUsable()) ++bad;
        // ---- uapc pins ----
            if (uapcPermPersonalCount() != 6) ++bad;
            if (!uapcPermPersonalDetectEvil()) ++bad;
            if (!uapcPermPersonalDetectIllusion()) ++bad;
            if (!uapcPermPersonalDetectInvisibility()) ++bad;
            if (!uapcPermPersonalDetectMagic()) ++bad;
            if (!uapcPermPersonalInfravision()) ++bad;
            if (!uapcPermPersonalProtectionFromEvil()) ++bad;
            if (!uapcPersonalListFromNormalFragment()) ++bad;
            if (uapcPermObjectCount() != 22) ++bad;
            if (!uapcPermObjectAlarm()) ++bad;
            if (!uapcPermObjectDeeppockets()) ++bad;
            if (!uapcPermObjectDispelMagic()) ++bad;
            if (!uapcPermObjectEnlarge()) ++bad;
            if (!uapcPermObjectFear()) ++bad;
            if (!uapcPermObjectForcecage()) ++bad;
            if (!uapcPermObjectGustOfWind()) ++bad;
            if (!uapcPermObjectInvisibility()) ++bad;
            if (!uapcPermObjectMagicMouth()) ++bad;
            if (!uapcPermObjectMissiles()) ++bad;
            if (!uapcPermObjectPreserve()) ++bad;
            if (!uapcPermObjectPrismaticSphere()) ++bad;
            if (!uapcPermObjectReadMagic()) ++bad;
            if (!uapcPermObjectRun()) ++bad;
            if (!uapcPermObjectStinkingCloud()) ++bad;
            if (!uapcPermObjectTongues()) ++bad;
            if (!uapcPermObjectUltravision()) ++bad;
            if (!uapcPermObjectUnseenServant()) ++bad;
            if (!uapcPermObjectWallOfFire()) ++bad;
            if (!uapcPermObjectWallOfForce()) ++bad;
            if (!uapcPermObjectWeb()) ++bad;
            if (!uapcPermObjectWindWall()) ++bad;
            if (!uapcObjectListInterleavedWithNote()) ++bad;
            if (uapcConLossPctNonLiving() != 5) ++bad;
            if (uapcConLossPctDeviceCharge() != 100) ++bad;
            if (!uapcDeviceExampleRingOfSpellStoring()) ++bad;
            if (uapcSertenSpellCount() != 24) ++bad;
            if (uapcSertenBonusHigh() != 9) ++bad;
            if (uapcSertenBonusMid() != 7) ++bad;
            if (uapcSertenBonusLow() != 5) ++bad;
            if (!uapcSertenBandAssignmentGarbled()) ++bad;
            if (!uapcSertenSaveEvenIfNoneAllowed()) ++bad;
            if (!uapcSertenNotVsComelinessFascination()) ++bad;
        // ---- uauw pins ----
            if (uauwClericCannotUseCount() != 5) ++bad;
            if (!uauwClericPrecipitationFirst()) ++bad;
            if (!uauwClericDustDevilSecond()) ++bad;
            if (!uauwClericCloudburstThird()) ++bad;
            if (!uauwClericAirWalkFifth()) ++bad;
            if (!uauwClericRainbowFifth()) ++bad;
            if (!uauwClericAirWalkStarred()) ++bad;
            if (!uauwClericRainbowStarred()) ++bad;
            if (uauwDruidCannotUseCount() != 4) ++bad;
            if (!uauwDruidPrecipitationFirst()) ++bad;
            if (!uauwDruidFlameBladeSecond()) ++bad;
            if (!uauwDruidCloudburstThird()) ++bad;
            if (!uauwDruidLiveoakSixth()) ++bad;
            if (!uauwDruidFlameBladeStarred()) ++bad;
            if (!uauwMuDampenCantripListed()) ++bad;
            if (!uauwMuCantripSecondCellLost()) ++bad;
            if (!uauwMuMountFirst()) ++bad;
            if (!uauwMuPrecipitationFirst()) ++bad;
            if (!uauwMuFlamingSphereSecond()) ++bad;
            if (!uauwMuCloudburstThird()) ++bad;
            if (!uauwMuMinuteMeteorsThird()) ++bad;
            if (!uauwMuWindWallThird()) ++bad;
            if (!uauwMuShoutFourth()) ++bad;
            if (!uauwMuFlamingSphereStarred()) ++bad;
            if (!uauwMuWindWallStarred()) ++bad;
            if (!uauwMuShoutStarred()) ++bad;
            if (!uauwIlFragmentReadsAsIllusionist()) ++bad;
            if (!uauwIlHazeCantripListed()) ++bad;
            if (!uauwIlRainbowFirst()) ++bad;
            if (!uauwIlWhisperingWindSecond()) ++bad;
            if (!uauwIlPhantomWindThird()) ++bad;
            if (!uauwIlSolidFogFourth()) ++bad;
            if (!uauwIlDeathFogSixth()) ++bad;
            if (!uauwIlFragmentAllStarred()) ++bad;
            if (!uauwStarredCastableInAiryWater()) ++bad;
            if (!uauwWaterWalkBobsToSurface()) ++bad;
            if (!uauwMagicFontNeedsGlassGlobe()) ++bad;
            if (!uauwReflectingPoolAnyWaterySpace()) ++bad;
            if (uauwTransmuteHoleCubicFeetPerLevel() != 10) ++bad;
            if (uauwTransmuteRushInDamagePerLevelDice() != 4) ++bad;
            if (!uauwTransmuteNoSavingThrow()) ++bad;
            if (uauwSaltCantripPints() != 1) ++bad;
            if (!uauwSaltWaterDispersesUnlessContained()) ++bad;
            if (!uauwFirewaterFloatsToTop()) ++bad;
            if (!uauwFirewaterNotIgnitableUnderwater()) ++bad;
            if (uauwAcidArrowLastsRounds() != 1) ++bad;
            if (!uauwAcidArrowWashedAway()) ++bad;
            if (!uauwChainLightningDoubleRadius()) ++bad;
            if (uauwChainLightningDamageDicePerLevel() != 6) ++bad;
            if (!uauwChainLightningSaveForHalf()) ++bad;
            if (!uauwMuTransmuteAsDruid()) ++bad;
            if (!uauwMansionWaterFilledOrDryOption()) ++bad;
            if (!uauwSinkRadiatesToSurface()) ++bad;
            if (!uauwPhantomSteedBecomesHippocampus()) ++bad;
            if (!uauwPhantomSteedBlackForebodySilverScales()) ++bad;
            if (!uauwPhantomSteedNoTravelOrFlySpecials()) ++bad;
            if (uauwPhantomSteedMovementPerLevel() != 4) ++bad;
        // ---- uadk pins ----
            if (uadkUnseenTargetToHitPenalty() != 4) ++bad;
            if (!uadkUnseenIsAsInvisible()) ++bad;
            if (uadkVagueBlurToHitPenalty() != 2) ++bad;
            if (!uadkVagueMeansDarkerShapeOnBackground()) ++bad;
            if (!uadkDaylightAndDevicesUnaffected()) ++bad;
            if (!uadkIncludesTorchLanternLightSpells()) ++bad;
            if (!uadkIncludesContinualLight()) ++bad;
            if (!uadkConverseHoldsForDarkDwellers()) ++bad;
            if (!uadkInfravisionWorksInNoVisibleLight()) ++bad;
            if (!uadkDarkDwellerPenalizedInLight()) ++bad;
            if (!uadkGrayDwarfCrossRef()) ++bad;
            if (!uadkDarkElfDarkGnomeCrossRef()) ++bad;
            if (!uadkFaerieFireHelpsOnlyPoorLight()) ++bad;
            if (!uadkFaerieFireWorksInTotalDarkness()) ++bad;
            if (!uadkFaerieFireNoBenefitAtTorchLight()) ++bad;
            if (!uadkFaerieFireFunctionsNormallyAnyway()) ++bad;
            if (!uadkDmCommonSenseFinalDeterminant()) ++bad;
            if (!uadkDmMayWarrantException()) ++bad;
        // the Serten's name table ----
            static const char* const sn[24] = {
                "beguiling", "charm", "suggestion", "forget",
                "hypnotism", "ray of enfeeblement",
                "person-affecting cantrips", "command",
                "domination", "fear", "hold", "scare", "spook",
                "eyebite", "cloak of fear", "geas", "quest",
                "chaos", "feeblemind",
                "Otto's irresistible dance", "dolor", "demand",
                "torment", "Leomund's lamentable belabourment"
            };
            for (int i = 0; i < 24; ++i) {
                if (strcmp(
                        uapcSertenName(i),
                        sn[i]) != 0) ++bad;
            }
            if (uapcSertenName(-1)[0] != 0)
                ++bad;
            if (uapcSertenName(24)[0] != 0)
                ++bad;
        printf("R366 UA DM-section spells pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
