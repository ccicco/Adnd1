    // ---- R355: the UA new druid 7th level spells pin audit ----
    // The UA NEW DRUID SPELLS (p. 45), the
    // 7th level - changestaff (the lost
    // name header, the hit-die ladder
    // with the wish-only recovery) and
    // sunray (the blindness tiers and the
    // undead damage split). The family
    // decodes the "7 round" as 1. The
    // item CLOSES this round.
    {
        using namespace rules;
        int bad = 0;
        // U1: changestaff
        {
            if (strcmp(uad7ChangestaffName(),
                "Changestaff") != 0) ++bad;
            // the lost "-" name header
            if (!uad7ChangestaffNameHeaderLost()) ++bad;
            if (!uad7ChangestaffSchoolLost()) ++bad;
            // the lost level cell
            if (uad7ChangestaffLevel() != 7) ++bad;
            if (!uad7ChangestaffLevelCellLost()) ++bad;
            if (!uad7ChangestaffComponentsVSM()) ++bad;
            if (!uad7ChangestaffRangeTouch()) ++bad;
            if (uad7ChangestaffCastingTimeSegments() != 3)
                ++bad;
            if (!uad7ChangestaffDurationSpecial()) ++bad;
            if (!uad7ChangestaffSaveNone()) ++bad;
            if (!uad7ChangestaffAoeTheDruidsStaff()) ++bad;
            // the largest-size treant
            if (!uad7ChangestaffStaffToLargestTreant())
                ++bad;
            // the lightning-struck tree gate
            if (uad7ChangestaffLightningTreeHours() != 24)
                ++bad;
            if (uad7ChangestaffLightningChanceMinPct() != 1)
                ++bad;
            if (uad7ChangestaffLightningChanceMaxPct() != 5)
                ++bad;
            if (!uad7ChangestaffSeverityWordsLost()) ++bad;
            if (!uad7ChangestaffStaffAshOakYew()) ++bad;
            // the two 28-day periods
            if (uad7ChangestaffCuringDays() != 28) ++bad;
            if (uad7ChangestaffShapingDays() != 28) ++bad;
            if (!uad7ChangestaffNoOtherActivityDuringPrep())
                ++bad;
            // the holly berries and the grove
            if (!uad7ChangestaffHollyBerryJuiceRub()) ++bad;
            if (!uad7ChangestaffGroveEarthAndSpeakWithPlants())
                ++bad;
            if (!uad7ChangestaffDweomerLastsManyChanges())
                ++bad;
            // the hit-die ladder
            if (uad7ChangestaffStartHitDice() != 12) ++bad;
            if (uad7ChangestaffStartHitPoints() != 96) ++bad;
            if (uad7ChangestaffDamagePerHitDieLost() != 8)
                ++bad;
            if (!uad7ChangestaffMyGarbleDecoded()) ++bad;
            if (uad7ChangestaffCrumbleBelowHitDice() != 7)
                ++bad;
            if (!uad7ChangestaffJustiKePowderGarbled())
                ++bad;
            // the wish-only recovery
            if (!uad7ChangestaffNeverRegainedExceptWish())
                ++bad;
            if (!uad7ChangestaffWishRestoresCompletely())
                ++bad;
            // the transformation
            if (!uad7ChangestaffPlantsAndSpeaksInvocation())
                ++bad;
            if (!uad7ChangestaffNotATrueTreant()) ++bad;
            if (!uad7ChangestaffCannotConverseWithTreants())
                ++bad;
            if (uad7ChangestaffDurationTurnsPerLevel() != 1)
                ++bad;
            if (!uad7ChangestaffEndsOnCommandOrDestruction())
                ++bad;
            if (!uad7ChangestaffMaterialMistletoeOrMatchingLeaves())
                ++bad;
        }
        // U2: sunray
        {
            if (strcmp(uad7SunrayName(),
                "Sunray (Evocation - Alteration)")
                != 0) ++bad;
            if (!uad7SunrayComponentsVSM()) ++bad;
            if (uad7SunrayLevel() != 7) ++bad;
            if (uad7SunrayRangeInchesPerLevel() != 1) ++bad;
            // the "7 round" family decode
            if (uad7SunrayDurationRounds() != 1) ++bad;
            if (!uad7SunrayDurationGarbleDecoded()) ++bad;
            if (!uad7SunrayAoeOneInchDiameterSpherePlusSpecial())
                ++bad;
            if (uad7SunrayCastingTimeSegments() != 3) ++bad;
            if (!uad7SunraySaveSpecial()) ++bad;
            if (!uad7SunrayBeamLikeActualSunlight()) ++bad;
            // the blindness tiers
            if (uad7SunrayBlindnessMinRounds() != 1) ++bad;
            if (uad7SunrayBlindnessMaxRounds() != 3) ++bad;
            if (!uad7SunraySaveNegatesBlindness()) ++bad;
            if (uad7SunrayUltravisionBlindnessMinRounds()
                != 2) ++bad;
            if (uad7SunrayUltravisionBlindnessMaxRounds()
                != 8) ++bad;
            if (!uad7SunraySunlightHarmfulPermanentUnlessSave())
                ++bad;
            if (uad7SunraySunlightHarmfulMaxRoundsOnSave()
                != 12) ++bad;
            if (uad7SunrayInfravisionLossMinRounds() != 2)
                ++bad;
            if (uad7SunrayInfravisionLossMaxRounds() != 5)
                ++bad;
            if (uad7SunrayInfravisionLossRadiusInches() != 2)
                ++bad;
            // the undead damage split
            if (uad7SunrayUndeadDamageDiceCount() != 8) ++bad;
            if (uad7SunrayUndeadDamageDiceSides() != 6) ++bad;
            if (!uad7SunrayUndeadHalfDamageOnSave()) ++bad;
            if (uad7SunraySecondaryDamageDiceCount() != 3)
                ++bad;
            if (uad7SunraySecondaryDamageDiceSides() != 6)
                ++bad;
            if (!uad7SunraySecondaryNoDamageOnSave()) ++bad;
            // the fungoid gate
            if (!uad7SunrayFungoidDamagedAsUndead()) ++bad;
            if (!uad7SunrayFungoidNoSavePossible()) ++bad;
            // the aster seed and sunstone
            if (!uad7SunrayMaterialAsterSeed()) ++bad;
            if (!uad7SunrayMaterialSunstoneFeldspar()) ++bad;
        }
        // U3: the treant seam and the closure
        {
            // The changestaff staff/treant is
            // by no means a true treant - it
            // cannot converse with actual
            // treants; the R354 liveoak pin
            // matches the Monster Manual
            // treant specification - the two
            // treant pins differ.
            if (!uad7ChangestaffNotATrueTreant()) ++bad;
            if (!uad6LiveoakBecomesTreantMmSpec()) ++bad;
            // The R341 druid table pins stop
            // at the 6th level - no 7th
            // table seam exists; both names
            // pin from the prose.
            if (uastDruid6thCount() != 5) ++bad;
        }
        printf("R355 UA druid 7th level spells pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
