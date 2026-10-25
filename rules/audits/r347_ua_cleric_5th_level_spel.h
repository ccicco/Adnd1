    // ---- R347: the UA new cleric 5th level spells pin audit ----
    // The UA NEW CLERIC SPELLS (pp. 40-41), the
    // 5th level - air walk (the ascent/descent
    // ladder and the gust interplay), animate
    // dead monsters (the per-two-levels ratio,
    // the type examples and the zombie and
    // skeleton treatments), golem (the four
    // material ladders), magic font (the vial
    // capacity rule), rainbow (the four
    // applications, the seven colors and the
    // seven draughts) and spike stones (the
    // spike stone damage and pit rules). The
    // digit-garble family decodes this round's
    // three stat-cell 7s as 1; the rainbow bow
    // 7-missiles and the golem 7-foot ceiling
    // stay genuine (corroborated); the R341
    // continued table prints seven 5th-level
    // fragments - magic font seam-checks, the
    // rest pin from the prose. The item stays
    // open (the 6th-7th levels).
    {
        using namespace rules;
        int bad = 0;
        // U1: air walk
        {
            if (strcmp(uac5AirwalkName(),
                "Air Walk (Alteration)") != 0) ++bad;
            if (!uac5AirwalkComponentsVSM()) ++bad;
            if (!uac5AirwalkRangeTouch()) ++bad;
            // the casting time prints "7 segment"
            if (uac5AirwalkCastingTimeSegments() != 1) ++bad;
            if (!uac5AirwalkSaveNone()) ++bad;
            if (uac5AirwalkDurationTurnsBase() != 6) ++bad;
            if (uac5AirwalkDurationTurnsPerLevel() != 1)
                ++bad;
            if (!uac5AirwalkAoeOneCreature()) ++bad;
            if (!uac5AirwalkTreadsOnAir()) ++bad;
            // the ascent/descent ladder
            if (uac5AirwalkAscent45Divisor() != 2) ++bad;
            if (uac5AirwalkAscent60Divisor() != 4) ++bad;
            if (uac5AirwalkAscentStraightDivisor() != 8) ++bad;
            if (uac5AirwalkDescentStraightMultiple() != 8)
                ++bad;
            if (!uac5AirwalkAlwaysInControl()) ++bad;
            if (!uac5AirwalkStopOnCopperPiece()) ++bad;
            // the gust of wind interplay
            if (!uac5AirwalkGustInterplay()) ++bad;
            if (uac5AirwalkGustIntoDivisor() != 2) ++bad;
            if (uac5AirwalkGustWithMultiple() != 2) ++bad;
            if (!uac5AirwalkTargetUpToGiantSize()) ++bad;
            if (!uac5AirwalkTrainedHorseExample()) ++bad;
            if (!uac5AirwalkBeastNeedsTraining()) ++bad;
            if (!uac5AirwalkMaterialSymbolThistledown())
                ++bad;
        }
        // U2: animate dead monsters
        {
            if (strcmp(uac5AnimateName(),
                "Animate Dead Monsters (Necromantic)") != 0)
                ++bad;
            if (!uac5AnimateComponentsVSM()) ++bad;
            // the Range cell prints blank - a hole
            if (!uac5AnimateRangeLost()) ++bad;
            // the casting time prints "7 segments"
            if (uac5AnimateCastingTimeSegments() != 1) ++bad;
            if (!uac5AnimateDurationPermanent()) ++bad;
            if (!uac5AnimateSaveNone()) ++bad;
            if (!uac5AnimateAoeSpecial()) ++bad;
            // 1 per 2 levels; commands to 12 words
            if (uac5AnimateAnimatedPerTwoLevels() != 1)
                ++bad;
            if (uac5AnimateCommandWordsMax() != 12) ++bad;
            if (!uac5AnimateCfAnimateDead()) ++bad;
            if (uac5AnimateExampleTypeCount() != 6) ++bad;
            for (int i = 0; i < 6; ++i) {
                if (uac5AnimateExampleTypeName(i) == 0)
                    ++bad;
            }
            if (!uac5AnimateListNotExclusive()) ++bad;
            if (!uac5AnimateBipedalManLike()) ++bad;
            if (!uac5AnimateSpecimenRuleFragmentLost())
                ++bad;
            // zombie vs living-form vs skeleton
            if (!uac5AnimateCorpseMonsterZombieMM2()) ++bad;
            if (uac5AnimateLowHDThreshold() != 6) ++bad;
            if (!uac5AnimateSkeletonHalfHDRoundedUp()) ++bad;
            if (!uac5AnimateNormalAttacksOnly()) ++bad;
            if (!uac5AnimateMaterialSymbolSpecimen())
                ++bad;
        }
        // U3: golem
        {
            if (strcmp(uac5GolemName(),
                "Golem (Enchantment/Charm)") != 0) ++bad;
            if (!uac5GolemComponentsVSM()) ++bad;
            if (uac5GolemRangeInches() != 1) ++bad;
            // the casting time prints "7 segments"
            if (uac5GolemCastingTimeSegments() != 1) ++bad;
            if (!uac5GolemDurationSpecial()) ++bad;
            if (!uac5GolemSaveNone()) ++bad;
            if (!uac5GolemAoeSpecial()) ++bad;
            if (!uac5GolemRequiresPersonalConstruction())
                ++bad;
            if (!uac5GolemRequiresPrayerSpell()) ++bad;
            if (!uac5GolemManShapedManSized()) ++bad;
            if (uac5GolemMinHeightFeet() != 3) ++bad;
            // the 7-foot ceiling stays genuine
            if (uac5GolemMaxHeightFeet() != 7) ++bad;
            // the four-material ladder
            if (uac5GolemMaterialCount() != 4) ++bad;
            static const int lvl[4] = { 9, 11, 13, 15 };
            static const int bh[4] = { 1, 3, 9, 27 };
            static const int dh[4] = { 1, 3, 6, 12 };
            static const int ac[4] = { 10, 8, 6, 4 };
            static const int mv[4] = { 12, 9, 6, 3 };
            static const int hb[4] = { 2, 3, 4, 5 };
            static const int hn[4] = { 4, 6, 8, 10 };
            static const int hp[4] = { 20, 30, 40, 50 };
            static const int at[4] = { 2, 1, 2, 1 };
            static const int cp[4] = { 30, 40, 50, 60 };
            for (int i = 0; i < 4; ++i) {
                if (uac5GolemMaterialName(i) == 0) ++bad;
                if (uac5GolemMinLevel(i) != lvl[i]) ++bad;
                if (uac5GolemBuildHours(i) != bh[i]) ++bad;
                if (uac5GolemDurationHoursPerLevel(i)
                    != dh[i]) ++bad;
                if (uac5GolemAC(i) != ac[i]) ++bad;
                if (uac5GolemMV(i) != mv[i]) ++bad;
                if (uac5GolemHDBase(i) != hb[i]) ++bad;
                if (uac5GolemHDBonus(i) != hn[i]) ++bad;
                if (uac5GolemHP(i) != hp[i]) ++bad;
                if (uac5GolemAT(i) != at[i]) ++bad;
                if (uac5GolemDamage(i) == 0) ++bad;
                if (uac5GolemSD(i) == 0) ++bad;
                if (uac5GolemCarryPounds(i) != cp[i]) ++bad;
            }
            // the straw golem SD decode
            if (!uac5GolemStrawSDDecoded()) ++bad;
            // the rope golem strangulation
            if (uac5GolemRopeStranglePerRound() != 6) ++bad;
            if (!uac5GolemRopeStrangleUntilRelease()) ++bad;
            if (!uac5GolemWoodImmuneBluntPiercing()) ++bad;
            if (!uac5GolemLeatherHalfFromBlunt()) ++bad;
            // the lesser golem dweomer
            if (!uac5GolemLesserGolemsName()) ++bad;
            if (!uac5GolemNoMinds()) ++bad;
            if (uac5GolemMindlessSpellExamples() != 4) ++bad;
            for (int i = 0; i < 4; ++i) {
                if (uac5GolemMindlessSpellName(i) == 0)
                    ++bad;
            }
            if (!uac5GolemSavesAsCreatorLevel()) ++bad;
            if (!uac5GolemCannotSpeak()) ++bad;
            if (uac5GolemInstructionWordsMax() != 12) ++bad;
        }
        // U4: magic font
        {
            if (strcmp(uac5FontName(),
                "Magic Font (Divination)") != 0) ++bad;
            if (!uac5FontComponentsVSM()) ++bad;
            // the "S$" cell garble decodes as plain S
            if (!uac5FontComponentsDecoded()) ++bad;
            if (!uac5FontRangeTouch()) ++bad;
            if (uac5FontCastingTimeTurns() != 5) ++bad;
            if (!uac5FontDurationSpecial()) ++bad;
            if (!uac5FontSaveNone()) ++bad;
            if (!uac5FontAoeSpecial()) ++bad;
            if (!uac5FontScryingDevice()) ++bad;
            if (!uac5FontRequiresGoodStanding()) ++bad;
            if (!uac5FontLikeCrystalBall()) ++bad;
            if (!uac5FontCapacityRuleFragmentLost()) ++bad;
            // each vial of capacity: 1 round of scrying
            if (uac5FontRoundsPerVial() != 1) ++bad;
            if (!uac5FontDurationTiedToCapacity()) ++bad;
            if (!uac5FontDetectionSeeMagicMirror()) ++bad;
            if (!uac5FontMaterialNotExhausted()) ++bad;
        }
        // U5: rainbow
        {
            if (strcmp(uac5RainbowName(),
                "Rainbow (Evocation/Alteration)") != 0) ++bad;
            if (!uac5RainbowComponentsVSM()) ++bad;
            // the Range cell never prints - a hole
            if (!uac5RainbowRangeLost()) ++bad;
            if (uac5RainbowCastingTimeSegments() != 8) ++bad;
            if (uac5RainbowDurationRoundsPerLevel() != 1)
                ++bad;
            if (!uac5RainbowSaveNone()) ++bad;
            if (!uac5RainbowAoeSpecial()) ++bad;
            if (!uac5RainbowNeedsRainbowSight()) ++bad;
            if (!uac5RainbowSpecialComponentFallback())
                ++bad;
            // the four applications
            if (uac5RainbowApplicationCount() != 4) ++bad;
            for (int i = 0; i < 4; ++i) {
                if (uac5RainbowApplicationName(i) == 0)
                    ++bad;
            }
            // the bow
            if (!uac5RainbowBowShimmering()) ++bad;
            if (uac5RainbowBowStrengthMin() != 6) ++bad;
            if (uac5RainbowBowMissilePlus() != 3) ++bad;
            if (!uac5RainbowBowNoNonproficiencyPenalty())
                ++bad;
            if (!uac5RainbowBowBowClassOnly()) ++bad;
            // 7 missiles stays genuine (corroborated)
            if (uac5RainbowBowMissiles() != 7) ++bad;
            if (uac5RainbowBowMaxShotsPerRound() != 2) ++bad;
            if (!uac5RainbowBowHueLeavesPerShot()) ++bad;
            if (uac5RainbowBowColorCount() != 7) ++bad;
            for (int i = 0; i < 7; ++i) {
                if (uac5RainbowBowColorName(i) == 0) ++bad;
                if (uac5RainbowBowColorTarget(i) == 0) ++bad;
            }
            if (!uac5RainbowBowArrowAppearsNocked()) ++bad;
            if (!uac5RainbowBowSpectrumFallback()) ++bad;
            // the bridge
            if (!uac5RainbowBridgeSevenHued()) ++bad;
            if (!uac5RainbowBridgeWidthFeetPerLevel()) ++bad;
            if (!uac5RainbowBridgeLoadHundredsPerLevel())
                ++bad;
            if (uac5RainbowBridgeMinLengthFeet() != 20)
                ++bad;
            if (uac5RainbowBridgeMaxLengthFeet() != 120)
                ++bad;
            if (!uac5RainbowBridgeLastsSpellLength()) ++bad;
            if (!uac5RainbowBridgeOrderedOutOfExistence())
                ++bad;
            if (!uac5RainbowBridgeTailFragmentLost()) ++bad;
            // the elevator
            if (uac5RainbowElevatorRadiusFeet() != 10) ++bad;
            if (!uac5RainbowElevatorArcPath()) ++bad;
            if (!uac5RainbowElevatorDangerOnExpiry()) ++bad;
            if (uac5RainbowElevatorRateInches() != 12) ++bad;
            if (uac5RainbowElevatorTrailInches() != 12) ++bad;
            // the flagon
            if (!uac5RainbowFlagonSevenColored()) ++bad;
            if (uac5RainbowFlagonMeasures() != 7) ++bad;
            if (!uac5RainbowFlagonUnusedDisappear()) ++bad;
            if (uac5RainbowFlagonDraughtCount() != 7) ++bad;
            for (int i = 0; i < 7; ++i) {
                if (uac5RainbowFlagonDraughtColor(i) == 0)
                    ++bad;
                if (uac5RainbowFlagonDraughtEffect(i) == 0)
                    ++bad;
            }
            // as if cast by a cleric of 12th level
            if (uac5RainbowFlagonCasterLevel() != 12) ++bad;
            if (!uac5RainbowFlagonEffectsPersist()) ++bad;
            // the material and the diamond fallback
            if (!uac5RainbowMaterialSymbolAndVial()) ++bad;
            if (uac5RainbowDiamondMinValueGP() != 1000) ++bad;
            if (!uac5RainbowDiamondNeedsBlessPrayer()) ++bad;
            if (!uac5RainbowOnlySymbolRemains()) ++bad;
        }
        // U6: spike stones
        {
            if (strcmp(uac5SpikeStonesName(),
                "Spike Stones (Alteration/Enchantment)")
                != 0) ++bad;
            if (!uac5SpikeStonesComponentsVSM()) ++bad;
            if (uac5SpikeStonesCastingTimeSegments() != 6)
                ++bad;
            if (uac5SpikeStonesRangeInches() != 3) ++bad;
            if (!uac5SpikeStonesSaveNone()) ++bad;
            if (uac5SpikeStonesDurationTurnsMin() != 3)
                ++bad;
            if (uac5SpikeStonesDurationTurnsMax() != 12)
                ++bad;
            if (uac5SpikeStonesDurationTurnsPerLevel() != 1)
                ++bad;
            if (uac5SpikeStonesAoeSquareInchesPerLevel() != 1)
                ++bad;
            if (uac5SpikeStonesSpikesPerSquareFoot() != 1)
                ++bad;
            if (!uac5SpikeStonesNaturalAndWorked()) ++bad;
            if (!uac5SpikeStonesImpedesOrDamages()) ++bad;
            if (uac5SpikeStonesNoticeChancePct() != 25) ++bad;
            if (uac5SpikeStonesDamageMin() != 1) ++bad;
            if (uac5SpikeStonesDamageMax() != 4) ++bad;
            if (!uac5SpikeStonesAttackAsCaster()) ++bad;
            if (!uac5SpikeStonesAttackOnEntryAndSteps()) ++bad;
            if (!uac5SpikeStonesInitialStepAlertsOnlyOnHit())
                ++bad;
            if (uac5SpikeStonesChargeAttacksPerInch() != 2)
                ++bad;
            if (uac5SpikeStonesOthersExtraChecks() != 1)
                ++bad;
            if (uac5SpikeStonesPitChecks() != 6) ++bad;
            if (uac5SpikeStonesPitToHitBonusPer10ft() != 2)
                ++bad;
            if (uac5SpikeStonesPitDamageBonusPer10ft() != 2)
                ++bad;
            if (!uac5SpikeStonesDamageInAdditionToFalling())
                ++bad;
            if (!uac5SpikeStonesMaterialStalactites()) ++bad;
            if (uac5SpikeStonesStalactiteCount() != 4) ++bad;
        }
        // U7: the seam
        {
            // the R341 continued table prints seven
            // 5th-level fragments
            if (uastClericFragCount(5) != 7) ++bad;
            static const char* const n[7] = {
                "Commune", "Cure Critical Wounds",
                "Dispel Evil", "Magic Font",
                "Plane Shift", "Spike Growth",
                "True Seeing" };
            for (int i = 0; i < 7; ++i) {
                if (strcmp(uastClericFragName(5, i), n[i])
                    != 0) ++bad;
            }
            // magic font seam-checks; the rest pin from
            // the prose alone
            if (!uac5MagicFontSeamChecks()) ++bad;
            if (!uac5SpellsPinFromProse()) ++bad;
        }
        printf("R347 UA cleric 5th level spells pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
