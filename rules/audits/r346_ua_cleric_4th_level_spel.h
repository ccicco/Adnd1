    // ---- R346: the UA new cleric 4th level spells pin audit ----
    // The UA NEW CLERIC SPELLS (pp. 38-39), the
    // 4th level - abjure (the dispel-magic-style
    // percentile check, the implore reverse),
    // cloak of fear (the 3-inch aura and the
    // bravery +3 reverse), giant insect (the
    // count and hit-dice ladders, the wasp
    // examples), imbue with spell ability (the
    // class gates and the level gates), spell
    // immunity and spike growth. The digit-garble
    // family decodes this round's five 7s as 1
    // (the cloak duration is corroborated by
    // its clean prose); the R341 continued table
    // prints only fragments for the 4th level -
    // none of the six names seam-check. The item
    // stays open (the 5th-7th levels).
    {
        using namespace rules;
        int bad = 0;
        // U1: abjure
        {
            if (strcmp(uac4AbjureName(),
                "Abjure (Abjuration)") != 0) ++bad;
            if (!uac4AbjureComponentsVSM()) ++bad;
            // the range cell prints a bare "7" -
            // unresolvable; a hole
            if (!uac4AbjureRangeLost()) ++bad;
            // the casting time prints "7 round"
            if (uac4AbjureCastingTimeRounds() != 1) ++bad;
            if (!uac4AbjureDurationPermanent()) ++bad;
            if (!uac4AbjureSaveNegSeeBelow()) ++bad;
            if (!uac4AbjureReturnsToHomePlane()) ++bad;
            if (!uac4AbjureRequiresExactTypeName()) ++bad;
            if (!uac4AbjureRequiresProperName()) ++bad;
            // the dispel-magic-style check
            if (uac4AbjureBaseChancePct() != 50) ++bad;
            if (!uac4AbjureComparedOnPercentileRoll()) ++bad;
            if (!uac4AbjureRollAtOrUnderSucceeds()) ++bad;
            if (!uac4AbjureCreatureMayBeAppreciative())
                ++bad;
            // the reverse: implore
            if (!uac4AbjureReverseIsImplore()) ++bad;
            if (!uac4AbjureReverseSameSuccessCheck()) ++bad;
            if (!uac4AbjureReverseNoDispositionGuarantee())
                ++bad;
            if (!uac4AbjureNotOnDeities()) ++bad;
            if (!uac4AbjureMayAffectServants()) ++bad;
            if (!uac4AbjureMaterialSymbolWaterBane())
                ++bad;
            if (!uac4AbjureReverseMaterialCraved()) ++bad;
        }
        // U2: cloak of fear
        {
            if (strcmp(uac4CloakName(),
                "Cloak of Fear (Illusion/Phantasm) Reversible")
                != 0) ++bad;
            if (!uac4CloakReversible()) ++bad;
            if (!uac4CloakComponentsVSM()) ++bad;
            if (uac4CloakRangeZero() != 0) ++bad;
            // the value "6 segments" prints after
            // the Range line - the casting time
            if (uac4CloakCastingTimeSegments() != 6) ++bad;
            // the duration prints "7 turn/level",
            // corroborated by the clean prose
            if (uac4CloakDurationTurnsPerLevel() != 1)
                ++bad;
            if (uac4CloakAuraRadiusInches() != 3) ++bad;
            if (!uac4CloakSaveVsSpell()) ++bad;
            if (uac4CloakFearDurationRounds() != 6) ++bad;
            if (!uac4CloakCfMuFearSpell()) ++bad;
            if (!uac4CloakDissipatesOnFailedSave()) ++bad;
            if (!uac4CloakNoEffectOnFearRadiators()) ++bad;
            if (!uac4CloakNoEffectOnUndead()) ++bad;
            if (!uac4CloakNotDissipatedByImmune()) ++bad;
            if (!uac4CloakSurvivesSuccessfulSaves()) ++bad;
            if (!uac4CloakPartyNotImmune()) ++bad;
            if (!uac4CloakCancellable()) ++bad;
            // the reverse: cloak of bravery
            if (!uac4CloakReverseIsBravery()) ++bad;
            if (!uac4CloakReverseRequiresWilling()) ++bad;
            if (uac4CloakReverseSaveBonus() != 3) ++bad;
            if (!uac4CloakReverseWorksOnce()) ++bad;
            if (!uac4CloakReverseSingleFigure()) ++bad;
            if (!uac4CloakReverseDispelsAfterSave()) ++bad;
            if (!uac4CloakReverseInnateFearUnaffected())
                ++bad;
            if (!uac4CloakMaterialQuiverFeather()) ++bad;
            if (!uac4CloakReverseMaterialAlcoholNewtBrain())
                ++bad;
        }
        // U3: giant insect
        {
            if (strcmp(uac4GiantInsectName(),
                "Giant Insect (Alteration) Reversible")
                != 0) ++bad;
            if (!uac4GiantInsectReversible()) ++bad;
            if (!uac4GiantInsectComponentsVSM()) ++bad;
            if (uac4GiantInsectRangeInches() != 2) ++bad;
            if (uac4GiantInsectDurationRoundsPerLevel() != 2)
                ++bad;
            if (!uac4GiantInsectCastingTimeSpecial()) ++bad;
            if (!uac4GiantInsectSaveNone()) ++bad;
            if (!uac4GiantInsectMakesGiantForms()) ++bad;
            // the count ladder
            if (uac4GiantInsectCountForLevel(7) != 1) ++bad;
            if (uac4GiantInsectCountForLevel(9) != 1) ++bad;
            if (uac4GiantInsectCountForLevel(10) != 2) ++bad;
            if (uac4GiantInsectCountForLevel(11) != 2) ++bad;
            if (uac4GiantInsectCountForLevel(12) != 3) ++bad;
            if (uac4GiantInsectCountForLevel(13) != 3) ++bad;
            if (uac4GiantInsectCountForLevel(14) != 4) ++bad;
            if (uac4GiantInsectCountForLevel(20) != 4) ++bad;
            // the hit-dice ladder
            if (uac4GiantInsectHdForLevel(7) != 3) ++bad;
            if (uac4GiantInsectHdForLevel(11) != 4) ++bad;
            if (uac4GiantInsectHdForLevel(13) != 5) ++bad;
            if (uac4GiantInsectHdForLevel(14) != 6) ++bad;
            if (!uac4GiantInsectOneTypeOnly()) ++bad;
            if (uac4GiantInsectCastingRoundsPerHd() != 1)
                ++bad;
            if (!uac4GiantInsectInterruptKillsSubjects())
                ++bad;
            if (!uac4GiantInsectAttacksAsNamesake()) ++bad;
            if (!uac4GiantInsectFullDamageOnlyAtFullHd())
                ++bad;
            if (!uac4GiantInsectDamageCappedAtBook()) ++bad;
            // the 14th-level wasp example
            if (uac4GiantInsectExampleHighClericLevel() != 14)
                ++bad;
            if (uac4GiantInsectExampleHighWaspHd() != 6)
                ++bad;
            if (uac4GiantInsectExampleGiantWaspHd() != 4)
                ++bad;
            if (uac4GiantInsectExampleHighBiteMin() != 2)
                ++bad;
            if (uac4GiantInsectExampleHighBiteMax() != 8)
                ++bad;
            if (uac4GiantInsectExampleHighStingMin() != 1)
                ++bad;
            if (uac4GiantInsectExampleHighStingMax() != 4)
                ++bad;
            // the 7th-level wasp example
            if (uac4GiantInsectExampleLowClericLevel() != 7)
                ++bad;
            if (uac4GiantInsectExampleLowWaspHd() != 3)
                ++bad;
            if (uac4GiantInsectExampleLowBiteMin() != 2)
                ++bad;
            if (uac4GiantInsectExampleLowBiteMax() != 6)
                ++bad;
            if (uac4GiantInsectExampleLowStingMin() != 1)
                ++bad;
            if (uac4GiantInsectExampleLowStingMax() != 3)
                ++bad;
            if (uac4GiantInsectLowHdDamageNumerator() != 3)
                ++bad;
            if (uac4GiantInsectLowHdDamageDenominator() != 4)
                ++bad;
            if (!uac4GiantInsectInsectsOnly()) ++bad;
            if (!uac4GiantInsectNoSpecialAttacks()) ++bad;
            if (!uac4GiantInsectPhysicalStatsAsBook()) ++bad;
            if (!uac4GiantInsectNeverHarmsCleric()) ++bad;
            if (!uac4GiantInsectSimpleCommandsOnly()) ++bad;
            if (!uac4GiantInsectUncommandedAttacksNearby())
                ++bad;
            // the reverse: shrink insect
            if (!uac4GiantInsectReverseIsShrink()) ++bad;
            if (uac4GiantInsectShrinkHdPerFourLevels() != 1)
                ++bad;
            if (uac4GiantInsectShrinkMaxHdReduction() != 6)
                ++bad;
            if (uac4GiantInsectShrinkMinHd() != 1) ++bad;
            if (!uac4GiantInsectShrinkKeepsSpecialsWeaker())
                ++bad;
            // the 9th-level shrink example
            if (uac4GiantInsectShrinkExampleClericLevel() != 9)
                ++bad;
            if (uac4GiantInsectShrinkExampleFromHd() != 4)
                ++bad;
            if (uac4GiantInsectShrinkExampleToHd() != 1)
                ++bad;
            if (uac4GiantInsectShrinkExampleSaveBonus() != 3)
                ++bad;
            if (uac4GiantInsectShrinkExampleBiteMin() != 1)
                ++bad;
            if (uac4GiantInsectShrinkExampleBiteMax() != 2)
                ++bad;
            if (uac4GiantInsectShrinkExampleStingDamage()
                != 1) ++bad;
            if (uac4GiantInsectShrinkDamageNumerator() != 1)
                ++bad;
            if (uac4GiantInsectShrinkDamageDenominator()
                != 4) ++bad;
            if (!uac4GiantInsectMaterialSymbol()) ++bad;
        }
        // U4: imbue with spell ability
        {
            if (strcmp(uac4ImbueName(),
                "Imbue With Spell Ability (Enchantment-Alteration)")
                != 0) ++bad;
            if (!uac4ImbueComponentsVSM()) ++bad;
            if (uac4ImbueRangeTouch() != 0) ++bad;
            // the casting time prints "7 turn"
            if (uac4ImbueCastingTimeTurns() != 1) ++bad;
            if (!uac4ImbueDurationSpecial()) ++bad;
            if (!uac4ImbueGrantsCasting()) ++bad;
            if (!uac4ImbueEligibleThieves()) ++bad;
            if (!uac4ImbueEligibleFighters()) ++bad;
            if (!uac4ImbueEligibleCavaliers()) ++bad;
            if (!uac4ImbueEligibleAssassins()) ++bad;
            if (!uac4ImbueEligibleMonks()) ++bad;
            // the ranger/paladin gates (the
            // "Sth" cell is the established
            // decode: under 8th, under 5th)
            if (uac4ImbueRangerMaxLevel() != 7) ++bad;
            if (uac4ImbuePaladinMaxLevel() != 4) ++bad;
            if (!uac4ImbueNotOnMonsters()) ++bad;
            if (!uac4ImbueRequiresOneFullHd()) ++bad;
            if (!uac4ImbueSpellsMustBeCarried()) ++bad;
            if (!uac4ImbueInfoOrDefensiveOrClw()) ++bad;
            if (!uac4ImbueWrongSpellFailsAll()) ++bad;
            if (uac4ImbueMaxSpells() != 3) ++bad;
            if (uac4ImbueMaxSecondLevelSpells() != 1) ++bad;
            if (uac4ImbueMaxFirstLevelSpells() != 2) ++bad;
            if (uac4ImbueMinWisdom() != 9) ++bad;
            if (uac4ImbueLevelGateOneFirst() != 1) ++bad;
            if (uac4ImbueLevelGateTwoFirst() != 3) ++bad;
            if (uac4ImbueLevelGateSecond() != 5) ++bad;
            if (!uac4ImbueVariablesAtRecipientLevel()) ++bad;
            if (!uac4ImbueOtherDetailsNormal()) ++bad;
            if (!uac4ImbueClericLosesSpell()) ++bad;
            if (!uac4ImbueBlocksMemorizeUntilUsed()) ++bad;
            if (!uac4ImbueMaterialSymbolAndProfessionItem())
                ++bad;
            if (!uac4ImbueItemConsumed()) ++bad;
        }
        // U5: spell immunity
        {
            if (strcmp(uac4SpellImmunityName(),
                "Spell Immunity (Abjuration)") != 0) ++bad;
            if (!uac4SpellImmunityComponentsVSM()) ++bad;
            if (uac4SpellImmunityRangeTouch() != 0) ++bad;
            // the casting time prints "7 round"
            if (uac4SpellImmunityCastingTimeRounds() != 1)
                ++bad;
            if (!uac4SpellImmunitySaveNone()) ++bad;
            if (uac4SpellImmunityDurationTurnsPerLevel() != 1)
                ++bad;
            if (!uac4SpellImmunitySpecifiedSpellOnly())
                ++bad;
            if (uac4SpellImmunityMaxSpellLevel() != 4) ++bad;
            if (!uac4SpellImmunityRequiresDirectExperience())
                ++bad;
            if (!uac4SpellImmunityBlockedByExistingProtection())
                ++bad;
            if (!uac4SpellImmunityCastSpellsOnly()) ++bad;
            if (!uac4SpellImmunityFullDuration()) ++bad;
            if (!uac4SpellImmunityOneAtATime()) ++bad;
            if (!uac4SpellImmunityItemsNotProtected()) ++bad;
            if (!uac4SpellImmunityNotSpellGroups()) ++bad;
            if (!uac4SpellImmunityMaterialMirrorsSpell())
                ++bad;
        }
        // U6: spike growth
        {
            if (strcmp(uac4SpikeGrowthName(),
                "Spike Growth (Alteration/Enchantment)")
                != 0) ++bad;
            if (!uac4SpikeGrowthComponentsVSM()) ++bad;
            // the stat block lacks a "Level:" cell -
            // the level is position-certain 4
            if (!uac4SpikeGrowthLevelCellLost()) ++bad;
            if (uac4SpikeGrowthLevel() != 4) ++bad;
            // the casting time prints "7 segments"
            // - the family decode, verbatim with
            // doubt pending the PDF
            if (uac4SpikeGrowthCastingTimeSegments() != 1)
                ++bad;
            if (!uac4SpikeGrowthCastingTimeFamilyDecode())
                ++bad;
            if (!uac4SpikeGrowthSaveNone()) ++bad;
            // the duration prints "7-6 turns +
            // 1/level" - the family decode
            if (uac4SpikeGrowthDurationMinTurns() != 1)
                ++bad;
            if (uac4SpikeGrowthDurationMaxTurns() != 6)
                ++bad;
            if (uac4SpikeGrowthDurationTurnsPerLevel() != 1)
                ++bad;
            if (!uac4SpikeGrowthDurationFamilyDecode()) ++bad;
            if (uac4SpikeGrowthAreaSquareInchesPerLevel()
                != 10) ++bad;
            if (!uac4SpikeGrowthRequiresPlantGrowth()) ++bad;
            if (!uac4SpikeGrowthGroundCoverAndRoots()) ++bad;
            if (!uac4SpikeGrowthBareGroundRoots()) ++bad;
            if (!uac4SpikeGrowthActsAsCaltrops()) ++bad;
            if (!uac4SpikeGrowthUndetectableUntilDamage())
                ++bad;
            if (!uac4SpikeGrowthExtentHiddenWithoutMagic())
                ++bad;
            if (uac4SpikeGrowthAttacksPerInchMoved() != 2)
                ++bad;
            if (!uac4SpikeGrowthHitsAsCaster()) ++bad;
            if (uac4SpikeGrowthDamageMin() != 1) ++bad;
            if (uac4SpikeGrowthDamageMax() != 4) ++bad;
            if (!uac4SpikeGrowthNegatedByPlantOrDispel())
                ++bad;
            if (!uac4SpikeGrowthMaterialSymbolThorns()) ++bad;
            if (uac4SpikeGrowthThornCount() != 7) ++bad;
        }
        // U7: the R341 continued-table seam
        {
            // the 4th-level column prints only two
            // fragments - none of this round's six
            // names seam-check
            if (uastClericFragCount(4) != 2) ++bad;
            if (strcmp(uastClericFragName(4, 0),
                "Sticks to Snakes") != 0) ++bad;
            if (strcmp(uastClericFragName(4, 1), "Tongues")
                != 0) ++bad;
            if (uastClericFragName(4, 2)[0] != 0) ++bad;
            if (!uac4SpikeGrowthSeamFragmentsOnly()) ++bad;
        }
        printf("R346 UA cleric 4th level spells pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
