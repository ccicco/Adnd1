    // ---- R345: the UA new cleric 3rd level spells pin audit ----
    // The UA NEW CLERIC SPELLS (pp. 36-38), the
    // 3rd level - cloudburst (the fire ladder
    // and the steam mechanics), death's door,
    // flame walk (the 2,000 F and the 500 gp
    // ruby), magical vestment (the chain mail
    // +4 ladder), meld into stone (the 9-16
    // rounds and the expulsion damage),
    // negative plane protection (the 2d6
    // Positive energy counterstrike), remove
    // paralysis (the +3/+2/+1 save ladder)
    // and water walk. The digit-garble family
    // decodes this round's six 7s as 1; the
    // R341 3rd-level column is fully readable
    // - no hole decode this round. The item
    // stays open (the 4th-7th levels).
    {
        using namespace rules;
        int bad = 0;
        // U1: cloudburst
        {
            if (strcmp(uac3CloudName(),
                "Cloudburst (Alteration)") != 0) ++bad;
            if (!uac3CloudComponentsVSM()) ++bad;
            if (uac3CloudCastingTimeSegments() != 5) ++bad;
            // the duration prints "7 round" -
            // the family decode, corroborated by
            // the 2-round hot-humid extension
            if (uac3CloudDurationRounds() != 1) ++bad;
            if (uac3CloudCylinderDiameterInches() != 3) ++bad;
            if (uac3CloudCylinderHeightInches() != 6) ++bad;
            // the per-round clause prints clean;
            // the per-segment rate is a hole
            if (uac3CloudRainfallInchesPerRound() != 1) ++bad;
            if (uac3CloudDrenchWithinSegments() != 1) ++bad;
            if (!uac3CloudSmallFiresOutInstantly()) ++bad;
            if (uac3CloudMediumFiresOutMinSegments() != 3)
                ++bad;
            if (uac3CloudMediumFiresOutMaxSegments() != 5)
                ++bad;
            if (uac3CloudLargeFiresOutMinSegments() != 8)
                ++bad;
            if (uac3CloudLargeFiresOutMaxSegments() != 10)
                ++bad;
            if (!uac3CloudMagicalFiresExtinguished()) ++bad;
            if (uac3CloudPermanentRelightMinRounds() != 1)
                ++bad;
            if (uac3CloudPermanentRelightMaxRounds() != 2)
                ++bad;
            if (!uac3CloudRekindlableDuringOnly()) ++bad;
            if (!uac3CloudNegatesProduceFireBurningHands())
                ++bad;
            if (!uac3CloudLargeAreaSpellsMakeSteam()) ++bad;
            if (uac3CloudSteamAreaMultiplier() != 4) ++bad;
            if (uac3CloudSteamCylinderDiameterInches() != 12)
                ++bad;
            if (uac3CloudSteamCylinderHeightInches() != 24)
                ++bad;
            if (uac3CloudSteamDamageMin() != 1) ++bad;
            if (uac3CloudSteamDamageMax() != 3) ++bad;
            if (uac3CloudSteamColdCreatureMultiplier() != 2)
                ++bad;
            if (uac3CloudSteamMinRounds() != 2) ++bad;
            if (uac3CloudSteamMaxRounds() != 5) ++bad;
            if (!uac3CloudSteamBreezeHalves()) ++bad;
            if (!uac3CloudSteamStrongWindOneRound()) ++bad;
            if (!uac3CloudAridDoubleStrengthPrecipitation())
                ++bad;
            if (uac3CloudHotHumidDurationRounds() != 2) ++bad;
            if (uac3CloudSleetHighF() != 33) ++bad;
            if (uac3CloudSleetLowF() != 31) ++bad;
            if (uac3CloudSnowAtOrBelowF() != 30) ++bad;
            if (uac3CloudSnowInchesPerSegment() != 1) ++bad;
            if (!uac3CloudMaterialSilverIodineSymbol())
                ++bad;
            // the range cell prints empty - a hole
            if (!uac3CloudRangeLost()) ++bad;
            if (!uac3CloudSegmentRateHole()) ++bad;
        }
        // U2: death's door
        {
            if (strcmp(uac3DeathsDoorName(),
                "Death's Door (Necromantic)") != 0) ++bad;
            if (!uac3DeathsDoorComponentsVSM()) ++bad;
            if (uac3DeathsDoorRangeTouch() != 0) ++bad;
            // the duration prints "7 hour/level"
            if (uac3DeathsDoorDurationHoursPerLevel() != 1)
                ++bad;
            if (uac3DeathsDoorCastingTimeSegments() != 5)
                ++bad;
            if (uac3DeathsDoorDoorLowestHp() != -9) ++bad;
            if (uac3DeathsDoorDoorHighestHp() != -1) ++bad;
            if (!uac3DeathsDoorBringsToZeroHp()) ++bad;
            if (!uac3DeathsDoorBleedingStopped()) ++bad;
            if (!uac3DeathsDoorDeteriorationStopped()) ++bad;
            if (!uac3DeathsDoorRestorableByCureMagic()) ++bad;
            if (!uac3DeathsDoorMaterialSymbolLinenUnguent())
                ++bad;
        }
        // U3: flame walk
        {
            if (strcmp(uac3FlameWalkName(),
                "Flame Walk (Alteration)") != 0) ++bad;
            if (!uac3FlameWalkComponentsVSM()) ++bad;
            if (uac3FlameWalkRangeTouch() != 0) ++bad;
            if (uac3FlameWalkDurationBaseTurns() != 1) ++bad;
            if (uac3FlameWalkDurationTurnsPerLevel() != 1)
                ++bad;
            // the stat cells print inverted - the
            // value precedes its label
            if (uac3FlameWalkCastingTimeSegments() != 5)
                ++bad;
            if (uac3FlameWalkMaxTempF() != 2000) ++bad;
            if (uac3FlameWalkSaveBonusVsMagicalFire() != 2)
                ++bad;
            if (!uac3FlameWalkEmpowersManSizeCreature())
                ++bad;
            if (uac3FlameWalkMinCasterLevel() != 5) ++bad;
            if (uac3FlameWalkExtraCreaturesPerLevelAbove() != 1)
                ++bad;
            if (uac3FlameWalkExampleCasterLevel() != 11) ++bad;
            if (uac3FlameWalkHorseEqualsHumans() != 6) ++bad;
            if (!uac3FlameWalkHalflingHalfHuman()) ++bad;
            if (!uac3FlameWalkMaterialRubyAndSymbol()) ++bad;
            if (uac3FlameWalkRubyMinValueGp() != 500) ++bad;
            // the lead sentence is scrambled - a
            // hole
            if (!uac3FlameWalkLeadSentenceLost()) ++bad;
        }
        // U4: magical vestment
        {
            if (strcmp(uac3VestmentName(),
                "Magical Vestment (Conjuration/Alteration)")
                != 0) ++bad;
            if (!uac3VestmentComponentsVSM()) ++bad;
            if (uac3VestmentRangeTouch() != 0) ++bad;
            // the casting time prints "7 round"
            if (uac3VestmentCastingTimeRounds() != 1) ++bad;
            if (uac3VestmentDurationRoundsPerLevel() != 6)
                ++bad;
            if (!uac3VestmentProtectsAsArmor()) ++bad;
            if (!uac3VestmentRequiresConsecratedGround())
                ++bad;
            if (!uac3VestmentCfCeremonySpell()) ++bad;
            if (!uac3VestmentArmorWornMeansPlainChain())
                ++bad;
            if (uac3VestmentEnchantmentPerFourLevels() != 1)
                ++bad;
            if (uac3VestmentMaxEnchantment() != 4) ++bad;
            if (uac3VestmentBaseAcAtMax() != 1) ++bad;
            if (!uac3VestmentEndsIfUnconscious()) ++bad;
            if (!uac3VestmentEndsIfLeavesArea()) ++bad;
            if (!uac3VestmentMaterialVestmentAndSymbol())
                ++bad;
        }
        // U5: meld into stone
        {
            if (strcmp(uac3MeldName(),
                "Meld Into Stone (Alteration)") != 0) ++bad;
            if (!uac3MeldComponentsVSM()) ++bad;
            if (uac3MeldRangeTouch() != 0) ++bad;
            // the casting time prints "7 segments"
            // - the family decode, verbatim with
            // doubt pending the PDF
            if (uac3MeldCastingTimeSegments() != 1) ++bad;
            if (!uac3MeldCastingTimeFamilyDecode()) ++bad;
            if (uac3MeldDurationBaseRounds() != 8) ++bad;
            if (uac3MeldDurationMinRounds() != 9) ++bad;
            if (uac3MeldDurationMaxRounds() != 16) ++bad;
            if (!uac3MeldDurationRolledSecretly()) ++bad;
            if (!uac3MeldStoneMustFitBody3D()) ++bad;
            if (!uac3MeldRequiresStoneSample()) ++bad;
            if (uac3MeldGearMaxPounds() != 100) ++bad;
            if (!uac3MeldArtifactsNotAffected()) ++bad;
            if (!uac3MeldFailsIfStoneTooSmall()) ++bad;
            if (!uac3MeldFailsIfGearTooHeavy()) ++bad;
            if (!uac3MeldExitSameSurfaceOnly()) ++bad;
            if (!uac3MeldNoMovementThroughStone()) ++bad;
            if (uac3MeldExpelDamageMin() != 4) ++bad;
            if (uac3MeldExpelDamageMax() != 32) ++bad;
            if (!uac3MeldGearSavesVsPetrification()) ++bad;
            if (!uac3MeldAwareOfTimePassage()) ++bad;
            if (!uac3MeldCannotSeeOrHear()) ++bad;
            if (!uac3MeldStoneToFleshExpels()) ++bad;
            if (!uac3MeldStoneToFleshItemsExempt()) ++bad;
            if (uac3MeldStoneShapeDamageMin() != 4) ++bad;
            if (uac3MeldStoneShapeDamageMax() != 16) ++bad;
            if (!uac3MeldStoneShapeDoesNotExpel()) ++bad;
            if (!uac3MeldTransmuteExpels()) ++bad;
            if (!uac3MeldTransmuteSlaysUnlessSave()) ++bad;
        }
        // U6: negative plane protection
        {
            if (strcmp(uac3NppName(),
                "Negative Plane Protection (Abjuration)")
                != 0) ++bad;
            if (!uac3NppComponentsVSM()) ++bad;
            if (uac3NppRangeTouch() != 0) ++bad;
            // the casting time prints "7 round"
            if (uac3NppCastingTimeRounds() != 1) ++bad;
            // the duration prints "7 turn/level",
            // corroborated by the clean prose
            if (uac3NppDurationTurnsPerLevel() != 1) ++bad;
            if (!uac3NppTargetPrimeMaterialOnly()) ++bad;
            if (!uac3NppProtectsVsNegativePlaneMonsters())
                ++bad;
            if (strcmp(uac3NppNmpMonsterExamples(),
                "shadow, wight, wraith, spectre, vampire")
                != 0) ++bad;
            if (!uac3NppOpensPositiveChannel()) ++bad;
            if (!uac3NppSaveVsDeathMagic()) ++bad;
            if (!uac3NppSuccessNoLevelDrain()) ++bad;
            if (!uac3NppSuccessNormalDamage()) ++bad;
            if (uac3NppUndeadTakesDamageMin() != 2) ++bad;
            if (uac3NppUndeadTakesDamageMax() != 12) ++bad;
            if (!uac3NppOneAttackOnly()) ++bad;
            if (!uac3NppDissipatesAfterAttack()) ++bad;
            if (!uac3NppFailedSaveDoublePhysicalDamage())
                ++bad;
            if (!uac3NppFailedSaveNormalEnergyDrain()) ++bad;
            if (!uac3NppBlocksEnergyDrainSpell()) ++bad;
            if (!uac3NppEnergyDrainCasterUnaffected()) ++bad;
            if (!uac3NppFlashAndThunderclap()) ++bad;
            if (!uac3NppPhenomenaCauseNoDamage()) ++bad;
            if (!uac3NppEndsOnSuccessfulAttack()) ++bad;
            if (!uac3NppNotCastableOnNegativePlane()) ++bad;
        }
        // U7: remove paralysis
        {
            if (strcmp(uac3RemParName(),
                "Remove Paralysis (Abjuration) Reversible")
                != 0) ++bad;
            if (!uac3RemParReversible()) ++bad;
            if (!uac3RemParComponentsVS()) ++bad;
            if (uac3RemParRangeInchesPerLevel() != 1) ++bad;
            if (uac3RemParCastingTimeSegments() != 6) ++bad;
            if (!uac3RemParDurationPermanent()) ++bad;
            if (!uac3RemParRemovesHoldSpell()) ++bad;
            if (uac3RemParMaxTargets() != 4) ++bad;
            if (uac3RemParAreaSquareInches() != 2) ++bad;
            if (!uac3RemParRequiresLineOfEffect()) ++bad;
            if (!uac3RemParBarrierWastesSpell()) ++bad;
            // the save bonus ladder
            if (uac3RemParSaveBonusOneTarget() != 3) ++bad;
            if (uac3RemParSaveBonusTwoTargets() != 2) ++bad;
            if (uac3RemParSaveBonusThreeOrFour() != 1) ++bad;
            // the reverse: cause paralysis
            if (!uac3RemParReverseSingleTarget()) ++bad;
            if (!uac3RemParReverseRequiresTouchHit()) ++bad;
            if (!uac3RemParReverseUsesHolySymbol()) ++bad;
            if (!uac3RemParReverseSaveVsSpell()) ++bad;
            if (uac3RemParReverseDurationMinRounds() != 1)
                ++bad;
            if (uac3RemParReverseDurationMaxRounds() != 6)
                ++bad;
            if (uac3RemParReverseExtraRoundsPerLevel() != 1)
                ++bad;
            if (!uac3RemParGoodClericsDiscerning()) ++bad;
            if (!uac3RemParProhibitedInSomeGoodOrders())
                ++bad;
        }
        // U8: water walk
        {
            if (strcmp(uac3WaterWalkName(),
                "Water Walk (Alteration)") != 0) ++bad;
            if (!uac3WaterWalkComponentsVSM()) ++bad;
            if (uac3WaterWalkRangeTouch() != 0) ++bad;
            if (uac3WaterWalkDurationBaseTurns() != 1) ++bad;
            if (uac3WaterWalkDurationTurnsPerLevel() != 1)
                ++bad;
            if (!uac3WaterWalkTreadsOnWaterAsGround()) ++bad;
            if (!uac3WaterWalkCfRingOfWaterWalking()) ++bad;
            if (uac3WaterWalkMinCasterLevel() != 5) ++bad;
            if (uac3WaterWalkExtraCreaturesPerLevelAbove() != 1)
                ++bad;
            if (uac3WaterWalkExampleCasterLevel() != 11)
                ++bad;
            if (uac3WaterWalkHorseEqualsHumans() != 6) ++bad;
            if (!uac3WaterWalkMaterialCorkAndSymbol()) ++bad;
            // the casting-time numeral is lost -
            // a hole
            if (!uac3WaterWalkCastingTimeLost()) ++bad;
        }
        // U9: the R341 table seam
        {
            // the 3rd-level column is fully
            // readable - all 20 rows carry names
            if (strcmp(uastClericName(3, 1), "Cloudburst")
                != 0) ++bad;
            if (strcmp(uastClericName(3, 6), "Death's Door")
                != 0) ++bad;
            if (strcmp(uastClericName(3, 9), "Flame Walk")
                != 0) ++bad;
            if (strcmp(uastClericName(3, 12),
                "Magical Vestment") != 0) ++bad;
            if (strcmp(uastClericName(3, 13),
                "Meld Into Stone") != 0) ++bad;
            if (strcmp(uastClericName(3, 14),
                "Negative Plane Protection") != 0) ++bad;
            if (strcmp(uastClericName(3, 17),
                "Remove Paralysis") != 0) ++bad;
            if (strcmp(uastClericName(3, 19), "Water Walk")
                != 0) ++bad;
            if (uastClericReadableCount(3) != 20) ++bad;
            if (!uac3R341SeamNoHoles()) ++bad;
        }
        printf("R345 UA cleric 3rd level spells pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
