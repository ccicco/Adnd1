    // ---- R344: the UA new cleric 2nd level spells pin audit ----
    // The UA NEW CLERIC SPELLS (pp. 35-36), the
    // 2nd level - aid (the bless-plus-1-8 hit
    // points mechanics and the worked example),
    // detect life, dust devil (the AC 4 / 2 HD
    // whirlwind ladder), enthrall (the 90-foot
    // radius, the charisma 21/3 split), holy
    // symbol, messenger, withdraw (the
    // segments = level + 1 formula) and wyvern
    // watch (the detection percentages). The
    // digit-garble family (established R343)
    // decodes this round's five 7s as 1; the
    // R341 table hole at row 18 (the "draw"
    // fragment) decodes as withdraw. The item
    // stays open (the 3rd-7th levels).
    {
        using namespace rules;
        int bad = 0;
        // U1: aid
        {
            if (strcmp(uac2AidName(),
                "Aid (Necromantic - Conjuration)") != 0) ++bad;
            if (uac2AidBonusHpMin() != 1) ++bad;
            if (uac2AidBonusHpMax() != 8) ++bad;
            if (!uac2AidGrantsBless()) ++bad;
            if (!uac2AidMayExceedNormalTotal()) ++bad;
            if (!uac2AidTempHpLostFirst()) ++bad;
            if (!uac2AidLostTempHpNotCurable()) ++bad;
            // the worked example
            if (uac2AidExampleStartHp() != 8) ++bad;
            if (uac2AidExampleFirstDamage() != 2) ++bad;
            if (uac2AidExampleBonusHp() != 6) ++bad;
            if (uac2AidExampleTotalHp() != 12) ++bad;
            if (uac2AidExampleSecondDamage() != 7) ++bad;
            if (uac2AidExampleRegularLost() != 1) ++bad;
            // the duration prints "7 round + 1/level"
            // - the digit-garble family decode
            if (uac2AidDurationBaseRounds() != 1) ++bad;
            if (uac2AidDurationRoundsPerLevel() != 1) ++bad;
            if (uac2AidRangeTouch() != 0) ++bad;
            if (!uac2AidMaterialClothAndSap()) ++bad;
            // the stat cells print empty - holes
            if (!uac2AidComponentsStatCellLost()) ++bad;
            if (!uac2AidCastingTimeLost()) ++bad;
            if (!uac2AidLeadingEmptyNoted()) ++bad;
        }
        // U2: detect life
        {
            if (strcmp(uac2DetectLifeName(),
                "Detect Life (Divination)") != 0) ++bad;
            if (uac2DetectLifeRangeFeet() != 10) ++bad;
            if (uac2DetectLifeDurationRounds() != 5) ++bad;
            // the casting time prints "7 round"
            if (uac2DetectLifeCastingTimeRounds() != 1) ++bad;
            if (!uac2DetectLifeComponentsVSM()) ++bad;
            if (!uac2DetectLifeSeesFeignDeath()) ++bad;
            if (!uac2DetectLifeSeesAstralTraveler()) ++bad;
            if (!uac2DetectLifeWorksOnPlants()) ++bad;
            if (uac2DetectLifeInchBarrierFeet() != 10) ++bad;
            if (!uac2DetectLifeMetalBarrierRuins()) ++bad;
            if (!uac2DetectLifeMentalProtectionRuins()) ++bad;
            if (!uac2DetectLifeFirstAlongLineOfSight()) ++bad;
        }
        // U3: dust devil
        {
            if (strcmp(uac2DustDevilName(),
                "Dust Devil (Conjuration/Summoning)") != 0) ++bad;
            if (uac2DustDevilAc() != 4) ++bad;
            if (uac2DustDevilHitDice() != 2) ++bad;
            if (uac2DustDevilMvInches() != 18) ++bad;
            if (uac2DustDevilDamageMin() != 1) ++bad;
            if (uac2DustDevilDamageMax() != 4) ++bad;
            if (!uac2DustDevilHitByNormalWeapons()) ++bad;
            if (!uac2DustDevilMagicWeaponDoubleDamage()) ++bad;
            if (uac2DustDevilBaseDiameterFeet() != 5) ++bad;
            if (uac2DustDevilHeightFeet() != 15) ++bad;
            if (uac2DustDevilTopDiameterFeet() != 10) ++bad;
            if (uac2DustDevilRangeInches() != 3) ++bad;
            if (uac2DustDevilCastingTimeRounds() != 3) ++bad;
            if (uac2DustDevilDurationRoundsPerLevel() != 1) ++bad;
            if (!uac2DustDevilComponentsVS()) ++bad;
            if (!uac2DustDevilDispelBeyondRange()) ++bad;
            if (!uac2DustDevilWindsHoldGas()) ++bad;
            if (!uac2DustDevilWindsExtinguishSmallFlames()) ++bad;
            if (uac2DustDevilCloudDiameterFeet() != 30) ++bad;
            if (!uac2DustDevilCloudBlinds()) ++bad;
            if (uac2DustDevilBlindLingersRounds() != 1) ++bad;
            if (!uac2DustDevilCastingRequiresSave()) ++bad;
            if (!uac2DustDevilAirNativeCanDismiss()) ++bad;
            if (!uac2DustDevilNonNativeUnaffected()) ++bad;
            if (!uac2DustDevilResistContactDispels()) ++bad;
            if (!uac2DustDevilResistDispelsAfterItsAttack())
                ++bad;
        }
        // U4: enthrall
        {
            if (strcmp(uac2EnthrallName(),
                "Enthrall (Enchantment/Charm)") != 0) ++bad;
            if (!uac2EnthrallComponentsVS()) ++bad;
            if (uac2EnthrallCastingTimeRounds() != 1) ++bad;
            if (uac2EnthrallRangeInches() != 3) ++bad;
            // the area prints "90 degree radius" -
            // the degree sign is the foot mark
            if (uac2EnthrallRadiusFeet() != 90) ++bad;
            if (!uac2EnthrallRequiresUnderstanding()) ++bad;
            if (!uac2EnthrallSameRaceSaves()) ++bad;
            if (uac2EnthrallUnfriendlyRaceSaveMod() != 4) ++bad;
            if (uac2EnthrallMaxLevelsOrHd() != 4) ++bad;
            if (uac2EnthrallMaxWisdom() != 15) ++bad;
            if (!uac2EnthrallRequiresFullRoundSpeech()) ++bad;
            if (uac2EnthrallMaxDurationTurns() != 6) ++bad;
            if (uac2EnthrallFailedSaveCharisma() != 21) ++bad;
            if (uac2EnthrallLoyaltyBasePct() != 70) ++bad;
            if (uac2EnthrallReactionAdjPct() != 50) ++bad;
            if (!uac2EnthrallNotASuggestion()) ++bad;
            if (!uac2EnthrallEndsIfCasterStopsOrActs()) ++bad;
            if (!uac2EnthrallAttackOnClericCancels()) ++bad;
            if (uac2EnthrallMadeSaveCharisma() != 3) ++bad;
            if (uac2EnthrallJeerChancePct() != 50) ++bad;
            if (!uac2EnthrallJeerAllowsNewSaves()) ++bad;
            if (uac2EnthrallOffendedSaveMod() != 5) ++bad;
        }
        // U5: holy symbol
        {
            if (strcmp(uac2HolySymbolName(),
                "Holy Symbol (Conjuration/Summoning)")
                != 0) ++bad;
            if (!uac2HolySymbolComponentsVSM()) ++bad;
            // the casting time prints "7 turn"
            if (uac2HolySymbolCastingTimeTurns() != 1) ++bad;
            if (!uac2HolySymbolCreatesOrReplaces()) ++bad;
            if (!uac2HolySymbolMaterialIsTheSymbol()) ++bad;
            if (!uac2HolySymbolMustBeCrafted()) ++bad;
            if (uac2HolySymbolMaxPossessed() != 2) ++bad;
            if (!uac2HolySymbolOnlyOwnReligion()) ++bad;
            if (!uac2HolySymbolRadiatesAlignmentAura()) ++bad;
            if (!uac2HolySymbolNeutralNoAura()) ++bad;
        }
        // U6: messenger
        {
            if (strcmp(uac2MessengerName(),
                "Messenger (Enchantment/Charm)") != 0) ++bad;
            if (!uac2MessengerComponentsVSM()) ++bad;
            if (!uac2MessengerRequiresSizeS()) ++bad;
            if (!uac2MessengerExcludesGiantTypes()) ++bad;
            if (uac2MessengerMaxIntelligence() != 3) ++bad;
            if (!uac2MessengerLureIsFood()) ++bad;
            if (!uac2MessengerSaveNegates()) ++bad;
            if (!uac2MessengerSimpleDirectionsOnly()) ++bad;
            if (!uac2MessengerCanCarryNote()) ++bad;
            if (!uac2MessengerWaitsUntilDurationEnds()) ++bad;
            if (!uac2MessengerRecipientMayIgnore()) ++bad;
            if (!uac2MessengerReceiverGainsNothing()) ++bad;
            // the duration prints "7 hour/level"
            // and the casting time "7 round"
            if (uac2MessengerDurationHoursPerLevel() != 1) ++bad;
            if (uac2MessengerCastingTimeRounds() != 1) ++bad;
            // the range cell prints empty - a hole
            if (!uac2MessengerRangeLost()) ++bad;
        }
        // U7: withdraw
        {
            if (strcmp(uac2WithdrawName(),
                "Withdraw (Alteration)") != 0) ++bad;
            if (!uac2WithdrawComponentsVSM()) ++bad;
            if (uac2WithdrawCastingTimeSegments() != 3) ++bad;
            if (uac2WithdrawRangeZero() != 0) ++bad;
            if (!uac2WithdrawTimeRatioSegmentToRound()) ++bad;
            if (uac2WithdrawBaseSegments() != 2) ++bad;
            if (uac2WithdrawSegmentsPerLevel() != 1) ++bad;
            // the formula: segments = level + 1
            if (uac2WithdrawSegmentsForLevel(1) != 2) ++bad;
            if (uac2WithdrawSegmentsForLevel(5) != 6) ++bad;
            if (uac2WithdrawSegmentsForLevel(9) != 10) ++bad;
            if (uac2WithdrawRealMinutesPerSegment() != 1) ++bad;
            if (!uac2WithdrawPermitsAuguryCuringInfo()) ++bad;
            if (!uac2WithdrawSpellsOnlyOnSelf()) ++bad;
            if (!uac2WithdrawOtherCastingEndsIt()) ++bad;
            if (!uac2WithdrawNoPhysicalActions()) ++bad;
            if (!uac2WithdrawAttackBreaksIt()) ++bad;
        }
        // U8: wyvern watch
        {
            // the header prints a stray curly
            // apostrophe before the name
            if (strcmp(uac2WyvernWatchName(),
                "Wyvern Watch (Evocation)") != 0) ++bad;
            if (!uac2WyvernWatchComponentsVSM()) ++bad;
            if (uac2WyvernWatchRangeInches() != 3) ++bad;
            if (uac2WyvernWatchCastingTimeSegments() != 5) ++bad;
            if (uac2WyvernWatchDurationHours() != 8) ++bad;
            if (uac2WyvernWatchSphereDiameterInches() != 1) ++bad;
            if (!uac2WyvernWatchGuardsArea()) ++bad;
            if (uac2WyvernWatchTriggerRangeInches() != 1) ++bad;
            if (uac2WyvernWatchParalysisRoundsPerLevel() != 1)
                ++bad;
            if (!uac2WyvernWatchFreeDispelOrRemoveParalysis())
                ++bad;
            if (!uac2WyvernWatchSaveMeansMissed()) ++bad;
            if (!uac2WyvernWatchStrikeDissipates()) ++bad;
            if (!uac2WyvernWatchDissipatesAfterDuration()) ++bad;
            if (uac2WyvernWatchDetectBrightPct() != 90) ++bad;
            if (uac2WyvernWatchDetectTwilightPct() != 30) ++bad;
            if (uac2WyvernWatchDetectDarknessPct() != 0) ++bad;
            if (!uac2WyvernWatchMaterialHolySymbol()) ++bad;
        }
        // U9: the R341 table seam
        {
            // the 2nd-level column carries the
            // seven other names
            if (strcmp(uastClericName(2, 4), "Detect Life")
                != 0) ++bad;
            if (strcmp(uastClericName(2, 5), "Dust Devil")
                != 0) ++bad;
            if (strcmp(uastClericName(2, 6), "Enthrall")
                != 0) ++bad;
            if (strcmp(uastClericName(2, 9), "Holy Symbol")
                != 0) ++bad;
            if (strcmp(uastClericName(2, 11), "Messenger")
                != 0) ++bad;
            if (strcmp(uastClericName(2, 19), "Wyvern Watch")
                != 0) ++bad;
            // the hole at row 18 decodes as
            // withdraw (alphabetically forced
            // between Spiritual Hammer and Wyvern
            // Watch)
            if (uastClericName(2, 18)[0] != 0) ++bad;
            if (!uac2WithdrawDrawHoleDecoded()) ++bad;
            int n = 0;
            for (int r = 0; r < 20; ++r)
                if (uastClericName(2, r)[0]) ++n;
            if (n != 16) ++bad;
        }
        printf("R344 UA cleric 2nd level spells pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
