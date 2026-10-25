    // ---- R365: the UA new illusionist
    // 6th/7th spells, acquisition and
    // cost pin audit ----
    // The UA NEW ILLUSIONIST SPELLS
    // (pp. 71-73) - the 6th-level four
    // (death fog with the acid ladder,
    // mislead with the improved-
    // invisibility cloak, phantasmagoria
    // with the lost level cell, the mirage
    // arcane at the printed 6th cell - the
    // item-list 7th divergence flagged)
    // and the 7th-level pair (shadow walk
    // with the plane reads, weird with the
    // lost prose); the UA ILLUSIONIST
    // SPELL ACQUISITION fragments and the
    // UA COST OF SPELL CASTING pins.
    // The R342 IL table seam prints only
    // Shadow Walk at the readable 7th; the
    // 6th column is wholly lost. The item
    // closes this round - all printed
    // levels pinned R363-R365.
    {
        using namespace rules;
        int bad = 0;
        // ---- death fog ----
        // ---- mislead ----
        // ---- phantasmagoria ----
        // ---- mirage arcane ----
            if (strcmp(uail6DfogName(),
                "Death Fog (Alteration - Evocation)") != 0) ++bad;
            if (uail6DfogLevel() != 6) ++bad;
            if (!uail6DfogComponentsVSM()) ++bad;
            if (uail6DfogCastingTimeSegments() != 6) ++bad;
            if (uail6DfogRangeInches() != 3) ++bad;
            if (!uail6DfogSaveNone()) ++bad;
            if (!uail6DfogDurationCellSuspectGarble()) ++bad;
            if (uail6DfogAoeCubicPerLevel() != 2) ++bad;
            if (!uail6DfogAoeUnitCellLost()) ++bad;
            if (!uail6DfogCreatesSolidFogArea()) ++bad;
            if (!uail6DfogHighlyAcidic()) ++bad;
            if (!uail6DfogVaporsDeadlyToVegetation()) ++bad;
            if (uail6DfogPlantsDieInRounds() != 2) ++bad;
            if (uail6DfogBushesShrubsDieInRounds() != 4) ++bad;
            if (uail6DfogSmallTreesDieInRounds() != 8) ++bad;
            if (uail6DfogLargeTreesDieInRounds() != 16) ++bad;
            if (!uail6DfogAnimalsNotImmuneSuffer()) ++bad;
            if (uail6DfogDamageRound1() != 1) ++bad;
            if (uail6DfogDamageRound2() != 2) ++bad;
            if (uail6DfogDamageRound3() != 4) ++bad;
            if (uail6DfogDamageRound4On() != 8) ++bad;
            if (!uail6DfogOtherwiseSameAsSolidFog()) ++bad;
            if (!uail6DfogComponentsPeasHoofAcid()) ++bad;
            if (!uail6DfogAcidIncludesVinegarCrystals()) ++bad;
            if (strcmp(uail6MisleadName(),
                "Mislead (Illusion/Phantasm)") != 0) ++bad;
            if (uail6MisleadLevel() != 6) ++bad;
            if (!uail6MisleadSomaticOnly()) ++bad;
            if (uail6MisleadCastingTimeSegments() != 1) ++bad;
            if (!uail6MisleadRangeCellSuspectGarble()) ++bad;
            if (!uail6MisleadSaveNone()) ++bad;
            if (uail6MisleadDurationRoundsPerLevel() != 1) ++bad;
            if (!uail6MisleadAoeSpecial()) ++bad;
            if (!uail6MisleadCreatesPhantasmalDouble()) ++bad;
            if (!uail6MisleadCloakedByImprovedInvis()) ++bad;
            if (!uail6MisleadCasterFreeToGoElsewhere()) ++bad;
            if (!uail6MisleadPhantasmSeeminglyMovesAway()) ++bad;
            if (!uail6MisleadPhantasmSpeaksAndGestures()) ++bad;
            if (!uail6MisleadSensorySentenceGarbled()) ++bad;
            if (!uail6MisleadTrueSightRevealsIllusion()) ++bad;
            if (!uail6MisleadGemOfSeeingRevealsIllusion()) ++bad;
            if (!uail6MisleadDetectInvisDetectsCaster()) ++bad;
            if (!uail6MisleadTrueSightDetectsCaster()) ++bad;
            if (!uail6MisleadTrueSeeingDetectsCaster()) ++bad;
            if (!uail6MisleadRobeOfEyesDetectsCaster()) ++bad;
            if (!uail6MisleadShadowDoorCrossRef()) ++bad;
            if (strcmp(uail6PhantName(),
                "Phantasmagoria (Illusion/Phantasm)") != 0) ++bad;
            if (uail6PhantLevel() != 6) ++bad;
            if (!uail6PhantLevelCellLost()) ++bad;
            if (!uail6PhantComponentsVerbalSomatic()) ++bad;
            if (uail6PhantCastingTimeSegments() != 6) ++bad;
            if (!uail6PhantSaveNegates()) ++bad;
            if (!uail6PhantDurationCellSuspectGarble()) ++bad;
            if (!uail6PhantAoeCellGarbled()) ++bad;
            if (!uail6PhantSpecialFormOfSpectralForces()) ++bad;
            if (!uail6PhantTriggeredBySpecialAction()) ++bad;
            if (!uail6PhantFullVisualAudialOlfactoryTouch()) ++bad;
            if (!uail6PhantFallingSlidingMovingRapidly()) ++bad;
            if (!uail6PhantTriggerOnPitFallOrDoorOpen()) ++bad;
            if (!uail6PhantMustInvolveFallingRushing()) ++bad;
            if (!uail6PhantDwindlingPerspectiveRead()) ++bad;
            if (!uail6PhantUnlikeProgrammedIllusion()) ++bad;
            if (strcmp(uail6MirageName(),
                "Mirage Arcane (Illusion/Phantasm - "
                "Alteration)") != 0) ++bad;
            if (uail6MirageLevel() != 6) ++bad;
            if (!uail6MirageLevelDivergenceFlagged()) ++bad;
            if (!uail6MirageComponentsVSOptionalM()) ++bad;
            if (uail6MirageRangeInchesPerLevel() != 1) ++bad;
            if (uail6MirageCastingTimeBasicSegments() != 3) ++bad;
            if (uail6MirageCastingTimeComplexSegments() != 6) ++bad;
            if (!uail6MirageSaveNone()) ++bad;
            if (!uail6MirageDurationSpecial()) ++bad;
            if (uail6MirageAoeRadiusInchesPerLevel() != 1) ++bad;
            if (!uail6MirageSimilarToVacancyButStronger()) ++bad;
            if (!uail6MirageSimilarToMirageCantrip()) ++bad;
            if (!uail6MirageAreaAppearsOtherThanItIs()) ++bad;
            if (!uail6MirageEnvisionedByCaster()) ++bad;
            if (!uail6MirageHeldByFaintConcentration()) ++bad;
            if (uail6MiragePersistsBaseTurns() != 6) ++bad;
            if (uail6MiragePersistsTurnsPerLevel() != 1) ++bad;
            if (!uail6MirageConcentrationOkInConversation()) ++bad;
            if (!uail6MirageConcentrationNotInCombat()) ++bad;
            if (!uail6MirageMustBePersonallySeen()) ++bad;
            if (!uail6MirageMaterialBitGrantsReality()) ++bad;
            if (!uail6MirageBasicForcefulContactNeeded()) ++bad;
            if (!uail6MirageComplexDetectionOnlyMagical()) ++bad;
            if (!uail6MirageSubjectToDispelIllusionOrMagic()) ++bad;
            if (!uail6MirageMindCausesBodyEffects()) ++bad;
            if (!uail6MirageBeliefCannotAffectLawsOfNature()) ++bad;
            if (!uail6MirageHotCoalsExample()) ++bad;
            if (!uail6MirageImaginaryFoodNourishes()) ++bad;
            if (!uail6MirageFeatherbedExample()) ++bad;
            if (!uail6MirageGravityUnaffected()) ++bad;
            if (!uail6MirageEnvisionedBridgeWillNotHold()) ++bad;
            if (!uail6MirageWitnessesSeeDisappearance()) ++bad;
            if (!uail6MirageDisappearanceNotLinkedToIllusion()) ++bad;
        // ---- shadow walk ----
        // ---- weird ----
            if (strcmp(uail7ShadowName(),
                "Shadow Walk (Illusion - Enchantment)") != 0) ++bad;
            if (uail7ShadowLevel() != 7) ++bad;
            if (!uail7ShadowComponentsCellGarbled()) ++bad;
            if (!uail7ShadowRangeTouch()) ++bad;
            if (uail7ShadowCastingTimeSegments() != 1) ++bad;
            if (!uail7ShadowSaveNone()) ++bad;
            if (uail7ShadowDurationTurnsPerLevel() != 6) ++bad;
            if (!uail7ShadowAoeSpecial()) ++bad;
            if (!uail7ShadowRequiresHeavyShadows()) ++bad;
            if (!uail7ShadowEdgeOfPrimeMaterial()) ++bad;
            if (!uail7ShadowAwareOfPrimePosition()) ++bad;
            if (uail7ShadowLeaguesPerTurn() != 7) ++bad;
            if (!uail7ShadowRapidTravelByStepping()) ++bad;
            if (!uail7ShadowDestinationControlled()) ++bad;
            if (!uail7ShadowOtherPlanesPerilousTransit()) ++bad;
            if (!uail7ShadowTouchedAlsoTransition()) ++bad;
            if (!uail7ShadowMayFollowWanderOrStumble()) ++bad;
            if (!uail7ShadowLostOrAbandonedFiftyFifty()) ++bad;
            if (!uail7ShadowUnwillingSaveNegates()) ++bad;
            if (strcmp(uail7WeirdName(),
                "Weird (Evocation - Illusion/Phantasm)") != 0) ++bad;
            if (uail7WeirdLevel() != 7) ++bad;
            if (!uail7WeirdComponentsVerbalSomatic()) ++bad;
            if (uail7WeirdCastingTimeSegments() != 7) ++bad;
            if (uail7WeirdRangeInches() != 3) ++bad;
            if (!uail7WeirdSaveSpecial()) ++bad;
            if (!uail7WeirdDurationSpecial()) ++bad;
            if (uail7WeirdAoeRadiusInches() != 2) ++bad;
            if (!uail7WeirdProseLargelyLost()) ++bad;
            if (!uail7WeirdCasterMustFragmentPrints()) ++bad;
        // ---- the starting list ----
        // ---- the illusionist spell book differences ----
        // ---- the illusionist cantrip counts ----
            if (!uailaThreeGroupsOneEach()) ++bad;
            if (!uailaAlwaysKnowsReadIllusionistMagic()) ++bad;
            if (uailaOffensiveRowCount() != 6)
                ++bad;
            if (uailaDefensiveRowCount() != 6)
                ++bad;
            if (uailaMiscRowCount() != 6) ++bad;
            if (!uailaOffRow1ColorSpray()) ++bad;
            if (!uailaOffRow2Hypnotism()) ++bad;
            if (!uailaOffRow3Light()) ++bad;
            if (!uailaOffRow4PhantasmalForce())
                ++bad;
            if (!uailaOffRow5ChromaticOrb())
                ++bad;
            if (!uailaChromaticOrbPrintsPlain())
                ++bad;
            if (!uailaOffRow6Spook()) ++bad;
            if (!uailaDefRow1AudibleGlamer())
                ++bad;
            if (!uailaDefRow2Darkness()) ++bad;
            if (!uailaDefRow3GazeReflection())
                ++bad;
            if (!uailaDefRow4WallOfFog()) ++bad;
            if (!uailaDefRow5PhantomArmor())
                ++bad;
            if (!uailaDefRow6IsChoose()) ++bad;
            if (!uailaMiscRow1ChangeSelf())
                ++bad;
            if (!uailaMiscRow2DancingLights())
                ++bad;
            if (!uailaMiscRow3DetectIllusion())
                ++bad;
            if (!uailaMiscRow4DetectInvisibility())
                ++bad;
            if (!uailaMiscRow5IsChoose()) ++bad;
            if (!uailaMiscRow6IsChooseAsterisk())
                ++bad;
            if (!uailaColumnsDecodeColumnWise())
                ++bad;
            if (uailaDmOptionCount() != 3) ++bad;
            if (!uailaUaSpellsAddedForIllusionistsOnly()) ++bad;
            if (!uailaNotDoneForMagicUsers()) ++bad;
            if (!uailaBooksSameAsMuWithExceptions()) ++bad;
            if (uailaStandardBookLowLevelSpells() != 24) ++bad;
            if (uailaStandardBookMidLevelSpells() != 16) ++bad;
            if (uailaStandardBookHighLevelSpells() != 8) ++bad;
            if (!uailaMuFirstLevelNeedsNewBook()) ++bad;
            if (uailaMuFirstLevelBookCapacity() != 24) ++bad;
            if (uailaTravellingBookLowLevelSpells() != 6) ++bad;
            if (uailaTravellingBookMidLevelSpells() != 4) ++bad;
            if (uailaTravellingBookHighLevelSpells() != 2) ++bad;
            if (!uailaScriptReadableByIllusionistsOnly()) ++bad;
            if (!uailaCrossClassBookBan()) ++bad;
            if (!uailaNamesakeSpellsTriggerDifferently()) ++bad;
            if (!uailaHasAllMuCantrips()) ++bad;
            if (uailaMinorIllusionCantripsMin() != 5) ++bad;
            if (uailaMinorIllusionCantripsMax() != 8) ++bad;
            if (!uailaMinorIllusionNotAvailableToMu()) ++bad;
            if (uailaUsefulCapIntMinus() != 3) ++bad;
            if (uailaUsefulCapAtInt18() != 15) ++bad;
            if (uailaReversedKnownMin() != 2) ++bad;
            if (uailaReversedKnownMax() != 5) ++bad;
            if (uailaLegerdemainKnownMin() != 3) ++bad;
            if (uailaLegerdemainKnownMax() != 6) ++bad;
            if (uailaPersonAffectingKnownMin() != 2) ++bad;
            if (uailaPersonAffectingKnownMax() != 5) ++bad;
            if (uailaPersonalKnownMin() != 2) ++bad;
            if (uailaPersonalKnownMax() != 5) ++bad;
            if (uailaHauntingSoundKnownMin() != 5) ++bad;
            if (uailaHauntingSoundKnownMax() != 8) ++bad;
            if (!uailaMuCantripPropertiesOtherwiseApply()) ++bad;
        // ---- the basic fee ----
        // ---- the surcharges ----
        // ---- the danger and aging clauses ----
        // ---- the payment reads ----
        // ---- the hostile caster reads ----
            if (uascFeePerSpellLevelGp() != 200) ++bad;
            if (!uascWillingCasterWorksForFee()) ++bad;
            if (!uascMaterialComponentsDoubled()) ++bad;
            if (!uascComponentSubstitutionsAllowed()) ++bad;
            if (uascOrdinarySurchargePercent() != 10) ++bad;
            if (uascOrdinarySurchargeValueMultiple() != 3) ++bad;
            if (uascExtraordinarySurchargePercent() != 100) ++bad;
            if (uascExtraordinaryValueMultiple() != 3) ++bad;
            if (!uascSurchargeWhicheverIsGreater()) ++bad;
            if (!uascDangerSpellsAtLeastDoubleFee()) ++bad;
            if (!uascDangerGuaranteesRequired()) ++bad;
            if (!uascDangerClauseInterleaved()) ++bad;
            if (!uascAgingSpellsNeedCounterFirst()) ++bad;
            if (!uascInsignificantAgingException()) ++bad;
            if (uascElfExampleAgingYears() != 5) ++bad;
            if (uascElfExampleFeeMultiple() != 10) ++bad;
            if (!uascMagicItemAcceptedInLieuOfCash()) ++bad;
            if (!uascItemValueAdjustedByReaction()) ++bad;
            if (!uascNpcCharacterAffectsCosts()) ++bad;
            if (!uascHostileAtLeastDoubleFee()) ++bad;
            if (!uascHostileMayRefuseEntirely()) ++bad;
            if (!uascHostileMayBeBribedWithItem()) ++bad;
            if (!uascGoodUnlikelyToCastForEvil()) ++bad;
            if (!uascDuressUsesDmgRules()) ++bad;
        // the R342 IL table seam: the
        // readable columns print only PHB
        // names except Shadow Walk at the
        // 7th; none of the new 6th/7th
        // names seam-checks
            if (uas2Il1stCount() != 5) ++bad;
            if (uas2Il2ndCount() != 4) ++bad;
            if (uas2Il7thCount() != 1) ++bad;
            if (strcmp(uas2Il7thName(0),
                        "Shadow Walk") != 0) ++bad;
            if (uas2IlCantripCount() != 8) ++bad;
            static const char* const nn[5] = {
                "Death Fog", "Mislead",
                "Phantasmagoria",
                "Mirage Arcane", "Weird",
            };
            for (int n = 0; n < 5; ++n) {
                for (int i = 0; i < 5; ++i) {
                    if (strcmp(uas2Il1stName(i),
                        nn[n]) == 0) ++bad;
                }
                for (int i = 0; i < 4; ++i) {
                    if (strcmp(uas2Il2ndName(i),
                        nn[n]) == 0) ++bad;
                }
                if (strcmp(uas2Il7thName(0),
                    nn[n]) == 0) ++bad;
            }
        printf("R365 UA IL 6th/7th and DM pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
