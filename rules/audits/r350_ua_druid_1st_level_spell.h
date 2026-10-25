    // ---- R350: the UA new druid 1st level spells pin audit ----
    // The UA NEW DRUID SPELLS (pp. 42-43),
    // the 1st level - ceremony (the nine
    // varieties with the cast-out
    // permission ladder), detect balance,
    // detect poison (the yew leaf) and
    // precipitation (the name header lost -
    // identified via the R343 clerical
    // pin). The digit-garble family decodes
    // the three "Level: 7" cells, the
    // "7 segment" and the two
    // "7 round/level" cells as 1 (detect
    // balance prints the clean 1). The item
    // stays open (the 2nd-7th levels).
    {
        using namespace rules;
        int bad = 0;
        // U1: ceremony
        {
            if (strcmp(uad1CeremonyName(),
                "Ceremony (Invocation)") != 0) ++bad;
            // the "Level: 7" family decode
            if (uad1CeremonyLevel() != 1) ++bad;
            if (!uad1CeremonyRangeTouch()) ++bad;
            if (!uad1CeremonySaveSpecial()) ++bad;
            if (!uad1CeremonyDurationPermanent()) ++bad;
            if (!uad1CeremonyAoeOneCreatureItemOrArea())
                ++bad;
            if (!uad1CeremonyComponentsIncludeMistletoe())
                ++bad;
            // the empty components and casting
            // time cells - holes
            if (!uad1CeremonyComponentsCellLost()) ++bad;
            if (!uad1CeremonyCastingTimeCellLost()) ++bad;
            if (!uad1CeremonySimilarToClerical()) ++bad;
            if (!uad1CeremonyNoAuraOfMagic()) ++bad;
            if (!uad1CeremonyKnowAlignmentRevealsNeutrality())
                ++bad;
            // the nine varieties in list order
            if (uad1CeremonyVarietyCount() != 9) ++bad;
            if (strcmp(uad1CeremonyVarietyName(0),
                "Coming of Age") != 0) ++bad;
            if (strcmp(uad1CeremonyVarietyName(2),
                "Marriage") != 0) ++bad;
            if (strcmp(uad1CeremonyVarietyName(3),
                "Dedication") != 0) ++bad;
            if (strcmp(uad1CeremonyVarietyName(6),
                "Special Vows") != 0) ++bad;
            if (strcmp(uad1CeremonyVarietyName(8),
                "Cast Out") != 0) ++bad;
            // the clean 1st and 12th prefixes;
            // the middle prefixes lost (0)
            if (uad1CeremonyVarietyCasterLevel(0) != 1)
                ++bad;
            if (uad1CeremonyVarietyCasterLevel(2) != 1)
                ++bad;
            if (uad1CeremonyVarietyCasterLevel(4) != 0)
                ++bad;
            if (uad1CeremonyVarietyCasterLevel(8) != 12)
                ++bad;
            if (!uad1CeremonyIndicatedOrLowerLevel())
                ++bad;
            // coming of age
            if (uad1ComingOfAgeUsualAge() != 14) ++bad;
            if (uad1ComingOfAgeSaveBonus() != 1) ++bad;
            // rest eternal
            if (!uad1RestEternalBlocksRaiseDeadAndResurrection())
                ++bad;
            if (!uad1RestEternalWishWorks()) ++bad;
            if (!uad1MarriageIdenticalToClerical()) ++bad;
            // dedication
            if (!uad1DedicationRequiresTrueNeutral()) ++bad;
            if (!uad1DedicationChargesBalanceKeeping())
                ++bad;
            // investiture
            if (!uad1InvestitureBeforeAspirant()) ++bad;
            if (!uad1InvestitureNoOtherBenefit()) ++bad;
            // initiation
            if (!uad1InitiationGrantsShapechangeAndWoodlandImmunity())
                ++bad;
            if (!uad1InitiationMustFollowSeventhLevelStart())
                ++bad;
            if (!uad1InitiationUsuallyBySeventhPlusDruid())
                ++bad;
            if (!uad1InitiationSelfCastUnusual()) ++bad;
            // special vows
            if (!uad1SpecialVowsNotOnPaladins()) ++bad;
            if (!uad1SpecialVowsWorksOnCavaliersAnyAlignment())
                ++bad;
            // hallowed ground
            if (!uad1HallowedGroundOwnGrove()) ++bad;
            if (!uad1HallowedGroundTreesNeverDiseased()) ++bad;
            if (!uad1HallowedGroundLastsWhilePermanentBase())
                ++bad;
            // cast out
            if (!uad1CastOutExcommunicationForSacrilege())
                ++bad;
            if (!uad1CastOutLessenedByReversedVersion())
                ++bad;
            if (!uad1CastOutReverserAtLeastEqualLevel())
                ++bad;
            if (!uad1CastOutOnlyHierophantNeutralizes())
                ++bad;
            if (!uad1CastOutAuraAffectsNaturalCreatures())
                ++bad;
            // the react-adverb lost - a hole
            if (!uad1CastOutReactAdverbLost()) ++bad;
            if (!uad1CastOutAuraIncludesDomesticAndDruids())
                ++bad;
            // the permission ladder
            if (!uad1CastOutNeedsArchdruidPermission())
                ++bad;
            if (!uad1ArchdruidNeedsGreatDruidPermission())
                ++bad;
            if (!uad1GreatDruidNeedsGrandDruidPermission())
                ++bad;
            if (!uad1GrandDruidNeedsNoPermission()) ++bad;
            if (!uad1GrandDruidReversibleByHierophant())
                ++bad;
            if (!uad1CastOutDeniedOrOffsetPunishable())
                ++bad;
            // the unwilling save at -4
            if (uad1CastOutUnwillingSaveMod() != -4) ++bad;
            if (!uad1CeremonyRiteInGroveOrHealthyForest())
                ++bad;
            if (!uad1CeremonyAtDawnOrDusk()) ++bad;
        }
        // U2: detect balance
        {
            if (strcmp(uad1DetectBalanceName(),
                "Detect Balance (Divination)") != 0) ++bad;
            if (!uad1DetectBalanceComponentsVSM()) ++bad;
            // the clean "Level: 1" cell
            if (uad1DetectBalanceLevel() != 1) ++bad;
            // the "7 segment" family decode
            if (uad1DetectBalanceCastingTimeSegments() != 1)
                ++bad;
            // the empty range cell - a hole
            if (!uad1DetectBalanceRangeLost()) ++bad;
            if (!uad1DetectBalanceSaveNone()) ++bad;
            // the "7 round/level" family decode
            if (uad1DetectBalanceDurationRoundsPerLevel()
                != 1) ++bad;
            if (!uad1DetectBalanceAoeOnePerRound()) ++bad;
            if (!uad1DetectBalanceDetectsNonNeutralForces())
                ++bad;
            if (!uad1DetectBalancePartlyNeutralMildAura())
                ++bad;
            if (!uad1DetectBalanceNoNeutralPartStrongAura())
                ++bad;
            if (!uad1DetectBalanceNotExactAlignment()) ++bad;
            if (!uad1DetectBalanceSameStrengthForSameNeutrality())
                ++bad;
            if (!uad1DetectBalanceNoAuraOnPlainItems())
                ++bad;
            if (!uad1DetectBalanceWorksOnAlignedMagicItem())
                ++bad;
            if (!uad1DetectBalanceUnknowableAlignmentBlocks())
                ++bad;
            if (!uad1DetectBalanceTrueNeutralSmoothAura())
                ++bad;
        }
        // U3: detect poison
        {
            if (strcmp(uad1DetectPoisonName(),
                "Detect Poison (Divination)") != 0) ++bad;
            if (!uad1DetectPoisonComponentsVSM()) ++bad;
            // the "Level: 7" family decode
            if (uad1DetectPoisonLevel() != 1) ++bad;
            if (!uad1DetectPoisonRangeZero()) ++bad;
            if (uad1DetectPoisonCastingTimeRounds() != 1)
                ++bad;
            if (!uad1DetectPoisonSaveNone()) ++bad;
            // the "7 round/level" family decode
            if (uad1DetectPoisonDurationRoundsPerLevel()
                != 1) ++bad;
            if (!uad1DetectPoisonAoeSpecial()) ++bad;
            if (!uad1DetectPoisonOpenerScrambleDecoded())
                ++bad;
            if (uad1DetectPoisonScanVolumeCubicYards() != 1)
                ++bad;
            if (!uad1DetectPoisonPortionNotWholePond())
                ++bad;
            if (uad1DetectPoisonTypeChancePctPerLevel() != 5)
                ++bad;
            // the three poison types
            if (uad1DetectPoisonTypeCount() != 3) ++bad;
            if (strcmp(uad1DetectPoisonTypeName(0),
                "Contact (Insinuative)") != 0) ++bad;
            if (strcmp(uad1DetectPoisonTypeName(1),
                "Ingestive") != 0) ++bad;
            if (strcmp(uad1DetectPoisonTypeName(2),
                "Respirative (Gas)") != 0) ++bad;
            if (!uad1DetectPoisonOneFailureEndsTypeDetection())
                ++bad;
            if (!uad1DetectPoisonMaterialMistletoe()) ++bad;
            if (!uad1DetectPoisonMaterialYewLeaf()) ++bad;
            if (!uad1DetectPoisonYewLeafTurnsBrown()) ++bad;
            if (!uad1DetectPoisonSeveralLeavesNeeded())
                ++bad;
        }
        // U4: precipitation
        {
            if (strcmp(uad1PrecipName(),
                "Precipitation") != 0) ++bad;
            // the name header and school never
            // print - holes
            if (!uad1PrecipNameHeaderLost()) ++bad;
            if (!uad1PrecipSchoolLost()) ++bad;
            if (!uad1PrecipIdenticalToClerical()) ++bad;
            if (!uad1PrecipComponentsVSM()) ++bad;
            // the "Level: 7" family decode
            if (uad1PrecipLevel() != 1) ++bad;
            if (uad1PrecipCastingTimeSegments() != 3) ++bad;
            // the empty range cell - a hole
            if (!uad1PrecipRangeLost()) ++bad;
            if (!uad1PrecipSaveNoneAndSpecial()) ++bad;
            // the "1 segment/ievel" decode
            if (uad1PrecipDurationSegmentsPerLevel() != 1)
                ++bad;
            if (uad1PrecipCylinderDiameterInches() != 3)
                ++bad;
            if (uad1PrecipCylinderHeightInches() != 12)
                ++bad;
            if (!uad1PrecipAddsMistletoeToClerical()) ++bad;
            // the R343 clerical seam: the
            // cylinder dims match the clerical
            // precipitation pin
            if (uad1PrecipCylinderDiameterInches()
                != uac1PrecipCylinderDiameterInches()) ++bad;
            if (uad1PrecipCylinderHeightInches()
                != uac1PrecipCylinderHeightInches()) ++bad;
        }
        // U5: the R341 table seam
        {
            // the druid 1st-level table prints
            // the four PHB names - none of the
            // four new names seam-checks;
            // they pin from the prose alone
            if (uastDruid1stCount() != 4) ++bad;
            if (strcmp(uastDruid1stName(0),
                "Locate Animals") != 0) ++bad;
            if (strcmp(uastDruid1stName(1),
                "Invisibility to Animals") != 0) ++bad;
            if (strcmp(uastDruid1stName(2),
                "Shillelagh") != 0) ++bad;
            if (strcmp(uastDruid1stName(3),
                "Speak With Animals") != 0) ++bad;
        }
        printf("R350 UA druid 1st level spells pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
