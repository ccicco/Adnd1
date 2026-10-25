    // ---- R343: the UA new cleric 1st level spells pin audit ----
    // The UA NEW CLERIC SPELLS (pp. 32-35), the
    // 1st level - ceremony (the ten varieties
    // and their levels, the special vows and
    // the clean cost pairs), combine (the
    // 3-5 cleric circle, the four-level gain
    // cap, the 3-turn duration), endure
    // cold/heat, penetrate disguise,
    // invisibility to undead, portent (the
    // 1d12/1d6 mechanics), magic stone and
    // precipitation. The digit-garble family
    // (four "Level: 7" cells print where the
    // level is position-certain 1) decodes 7
    // as 1; the R341 table hole at row 13
    // decodes as portent. The item stays open
    // (the 2nd-7th levels).
    {
        using namespace rules;
        int bad = 0;
        // U1: ceremony
        {
            if (strcmp(uac1CeremonyName(),
                "Ceremony (Invocation)") != 0) ++bad;
            if (strcmp(uac1CeremonyComponents(),
                "V, S, M") != 0) ++bad;
            // the casting time prints "7 hour"
            if (uac1CeremonyCastingTimeHours() != 1) ++bad;
            if (uac1CeremonyVarietyCount() != 10) ++bad;
            if (strcmp(uac1CeremonyVarietyName(0),
                "Coming of Age") != 0) ++bad;
            if (strcmp(uac1CeremonyVarietyName(5),
                "Consecrate Item") != 0) ++bad;
            if (strcmp(uac1CeremonyVarietyName(9),
                "Anathematize") != 0) ++bad;
            // the variety levels (the Sth cells
            // decode by list position)
            if (uac1CeremonyVarietyLevel(2) != 1) ++bad;
            if (uac1CeremonyVarietyLevel(3) != 3) ++bad;
            if (uac1CeremonyVarietyLevel(6) != 5) ++bad;
            if (uac1CeremonyVarietyLevel(9) != 7) ++bad;
            if (!uac1CeremonyNoSaveExceptAnathematize())
                ++bad;
            if (uac1ComingOfAgeSaveBonus() != 1) ++bad;
            if (uac1ComingOfAgeUsualAge() != 12) ++bad;
            if (uac1BurialProtectionWeeks() != 1) ++bad;
            if (uac1BurialDisintererFleeTurns() != 1) ++bad;
            if (uac1UnconsecratedCollapsePctPerYear()
                != 1) ++bad;
            if (uac1ConsecrateGroundEvilClericLevel()
                != 3) ++bad;
            if (!uac1SpecialVowsBestowCurseImmunity())
                ++bad;
            if (uac1SpecialVowsQuestSaveMod() != -4) ++bad;
            if (uac1CostComingOfAgeMinSp() != 5) ++bad;
            if (uac1CostComingOfAgeMaxSp() != 15) ++bad;
            if (uac1CostSpecialVowsMinGp() != 1) ++bad;
            if (uac1CostSpecialVowsMaxGp() != 100) ++bad;
            if (!uac1CostSpecialVowsSometimesFree())
                ++bad;
            if (uac1CostConsecrateGroundMinGp() != 100)
                ++bad;
            if (uac1CostConsecrateGroundMaxGp() != 600)
                ++bad;
            if (!uac1CostAnathematizeNoCharge()) ++bad;
        }
        // U2: combine
        {
            if (strcmp(uac1CombineName(),
                "Combine (Evocation)") != 0) ++bad;
            if (uac1CombineClericsMin() != 3) ++bad;
            if (uac1CombineClericsMax() != 5) ++bad;
            if (uac1CombineLevelGainPerEncircling() != 1)
                ++bad;
            // the "is four" fragment decode
            if (uac1CombineMaxGainLevels() != 4) ++bad;
            if (uac1CombineMaxDurationTurns() != 3) ++bad;
            if (!uac1CombineEncirclingNoShieldOrDexAc())
                ++bad;
            if (uac1CombineAttackerToHitBonus() != 4)
                ++bad;
            if (!uac1CentralClericNoExtraSpells()) ++bad;
            if (!uac1CombineComponentsLost()) ++bad;
        }
        // U3: endure cold / endure heat
        {
            if (strcmp(uac1EndureName(),
                "Endure Cold / Endure Heat") != 0) ++bad;
            if (!uac1EndureReversible()) ++bad;
            if (uac1EndureColdLowFLimit() != -30) ++bad;
            if (uac1EndureHeatHighFLimit() != 130) ++bad;
            if (uac1EndureExposureDamagePerHourPerDegree()
                != 1) ++bad;
            if (uac1UnprotectedExposureDamagePerTurnPerDegree()
                != 1) ++bad;
            // the duration prints "9 turns/level"
            // - verbatim with doubt
            if (uac1EndureDurationTurnsPerLevel() != 9)
                ++bad;
            if (!uac1EndureCancelledByMagicalColdOrHeat())
                ++bad;
            if (!uac1EndureNoDamageInBreakingRound()) ++bad;
            if (!uac1EndureResistFireOrColdCancels()) ++bad;
        }
        // U4: penetrate disguise
        {
            if (strcmp(uac1PenetrateName(),
                "Penetrate Disguise (Divination)")
                != 0) ++bad;
            if (uac1PenetrateCastingTimeRounds() != 2)
                ++bad;
            // the duration prints "7 round" -
            // the digit-garble family decode
            if (uac1PenetrateDurationRounds() != 1) ++bad;
            if (!uac1PenetrateSeesNonMagicalDisguise())
                ++bad;
            if (!uac1PenetrateCannotIdClassOrStatus())
                ++bad;
            if (!uac1PenetrateCannotRevealIllusion())
                ++bad;
            if (!uac1PenetrateDetectsFriendsSpellObject())
                ++bad;
            if (!uac1PenetrateCannotDetectAlignmentDeception())
                ++bad;
            if (!uac1PenetrateTargetSaveEnhancesDisguise())
                ++bad;
            if (!uac1PenetrateProtectionGrantsSaveBonus())
                ++bad;
            // the range prints "712" - a hole
            if (!uac1PenetrateRangeLost()) ++bad;
        }
        // U5: invisibility to undead
        {
            if (strcmp(uac1ItuName(),
                "Invisibility to Undead") != 0) ++bad;
            if (uac1ItuMaxHitDice() != 4) ++bad;
            if (uac1ItuRadiusFeet() != 30) ++bad;
            if (uac1ItuDurationRounds() != 6) ++bad;
            if (uac1ItuCastingTimeSegments() != 4) ++bad;
            if (!uac1ItuSavePerType()) ++bad;
            if (!uac1ItuNegatesOwnTurning()) ++bad;
            if (!uac1ItuEndsIfCasterActs()) ++bad;
            if (uac1ItuNeutralCasterSaveMod() != -2) ++bad;
            if (!uac1ItuMaterialHolySymbol()) ++bad;
        }
        // U6: portent
        {
            if (strcmp(uac1PortentName(),
                "Portent (Divination)") != 0) ++bad;
            if (uac1PortentTimingDieSides() != 12) ++bad;
            if (uac1PortentEffectDieSides() != 6) ++bad;
            // the modifier table (1 = -3 ... 6 = +3)
            if (uac1PortentEffectModifier(1) != -3) ++bad;
            if (uac1PortentEffectModifier(3) != -1) ++bad;
            if (uac1PortentEffectModifier(4) != 1) ++bad;
            if (uac1PortentEffectModifier(6) != 3) ++bad;
            if (!uac1PortentOnlyLifeOrDeathRolls()) ++bad;
            if (!uac1PortentContrivedRollsSuspended())
                ++bad;
            if (uac1PortentCastingTimeTurns() != 1) ++bad;
            if (!uac1PortentTableHoleDecoded()) ++bad;
            // the material fragments scramble - a
            // hole
            if (!uac1PortentMaterialLost()) ++bad;
        }
        // U7: magic stone
        {
            if (strcmp(uac1MagicStoneName(),
                "Magic Stone (Alteration)") != 0) ++bad;
            if (uac1MagicStoneToHitBonus() != 1) ++bad;
            // the damage prints "1 point of
            // damage" - verbatim with doubt
            if (uac1MagicStoneDamagePoints() != 1) ++bad;
            if (uac1MagicStoneThrowRangeInches() != 4)
                ++bad;
            // the orphan "2" range fragment -
            // verbatim with doubt
            if (uac1MagicStoneRangeInches() != 2) ++bad;
            if (uac1MagicStoneDweomerWindowRounds() != 6)
                ++bad;
            // the stones-per-level ladder
            if (uac1MagicStoneStonesForLevel(5) != 1)
                ++bad;
            if (uac1MagicStoneStonesForLevel(6) != 2)
                ++bad;
            if (uac1MagicStoneStonesForLevel(11) != 3)
                ++bad;
            if (uac1MagicStoneStonesForLevel(15) != 3)
                ++bad;
            if (uac1MagicStoneStonesForLevel(16) != 4)
                ++bad;
            if (uac1MagicStoneStonesForLevel(21) != 5)
                ++bad;
            if (!uac1MagicStoneInnateResistImmune()) ++bad;
            if (!uac1MagicStoneShieldBlocks()) ++bad;
            if (uac1MagicStoneDurationRounds() != 6) ++bad;
            if (!uac1MagicStoneGiveToAnother()) ++bad;
            if (!uac1MagicStoneSomeReligionsForbid())
                ++bad;
            if (!uac1MagicStoneComponentsLost()) ++bad;
        }
        // U8: precipitation
        {
            if (strcmp(uac1PrecipName(),
                "Precipitation (Alteration)") != 0) ++bad;
            if (uac1PrecipDurationSegmentsPerLevel() != 1)
                ++bad;
            if (uac1PrecipCylinderDiameterInches() != 3)
                ++bad;
            if (uac1PrecipCylinderHeightInches() != 12)
                ++bad;
            if (!uac1PrecipComponentsLost()) ++bad;
            if (uac1PrecipThinMaterialDampSegments() != 1)
                ++bad;
            if (uac1PrecipHeavyMaterialDampSegments() != 2)
                ++bad;
            if (uac1PrecipFlatSurfaceDampSegments() != 1)
                ++bad;
            if (uac1PrecipSemiPorousWetAfterSegments() != 5)
                ++bad;
            if (!uac1PrecipPorousAbsorbs()) ++bad;
            if (uac1PrecipCandleOutSegments() != 1) ++bad;
            if (uac1PrecipSmallFireSmokyRounds() != 1)
                ++bad;
            if (!uac1PrecipLargeFiresUnaffected()) ++bad;
            if (uac1PrecipHotTempDoublesAboveF() != 90)
                ++bad;
            if (uac1PrecipSleetHighF() != 33) ++bad;
            if (uac1PrecipSleetLowF() != 31) ++bad;
            if (uac1PrecipSnowAtOrBelowF() != 30) ++bad;
            if (uac1PrecipMagicalHeatFogAreaMultiplier()
                != 2) ++bad;
            if (!uac1PrecipMagicalColdFormsIce()) ++bad;
            if (!uac1PrecipMaterialSilverDust()) ++bad;
        }
        // U9: the R341 table seam
        {
            // the 1st-level column carries the
            // seven other names
            if (strcmp(uastClericName(1, 1), "Ceremony")
                != 0) ++bad;
            if (strcmp(uastClericName(1, 2), "Combine")
                != 0) ++bad;
            if (strcmp(uastClericName(1, 8),
                "Endure Cold/Heat") != 0) ++bad;
            if (strcmp(uastClericName(1, 9),
                "Invisibility to Undead") != 0) ++bad;
            if (strcmp(uastClericName(1, 11),
                "Magic Stone") != 0) ++bad;
            if (strcmp(uastClericName(1, 12),
                "Penetrate Disguise") != 0) ++bad;
            if (strcmp(uastClericName(1, 14),
                "Precipitation") != 0) ++bad;
            // the hole at row 13 decodes as
            // portent (alphabetically forced
            // between Penetrate Disguise and
            // Precipitation)
            if (uastClericName(1, 13)[0] != 0) ++bad;
            int n = 0;
            for (int r = 0; r < 20; ++r)
                if (uastClericName(1, r)[0]) ++n;
            if (n != 18) ++bad;
        }
        printf("R343 UA cleric 1st level spells pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
