    // ---- R376: the UA new potions
    // prose part 1 pin audit ----
    // The twelve clean
    // descriptions (pp. 90-92):
    // the four elixirs, fire
    // breath, the oils of fiery
    // burning, fumbling,
    // sharpness, timelessness,
    // rainbow hues,
    // ventriloquism, vitality. The
    // seven garbled descriptions
    // filled by the R396 clean
    // read. The R375
    // seam cross-checks the
    // skeleton; the census
    // 302 -> 303.
    {
        using namespace rules;
        int bad = 0;
        // ---- the elixir of health ----
            if (uappHealthCuresCount() != 9)
                ++bad;
            if (uappHealthHealsWounds()) ++bad;
            if (uappHealthHalfFlaskCuresMax() != 2)
                ++bad;
            if (!uappHealthWholeFlaskCuresAll())
                ++bad;
        // ---- the elixir of life ----
            if (uappLifeNegativeHpPct() != 20)
                ++bad;
            if (uappLifeMinus10NeedsFullHp() != 50)
                ++bad;
            if (uappLifeWindowRounds() != 5) ++bad;
            if (uappLifeAfterOneTurnHp() != 1) ++bad;
            if (uappLifeRestDaysPerNegHp() != 1)
                ++bad;
            if (uappLifeCureSeriousDays() != 2)
                ++bad;
            if (uappLifeCureCriticalDays() != 3)
                ++bad;
            if (uappLifeHealSpellDays() != 7) ++bad;
            if (!uappLifeDemihumansAffected())
                ++bad;
        // ---- the elixir of madness ----
            if (strcmp(uappMadnessEquivalentSpell(),
                    "symbol of insanity") != 0)
                ++bad;
            if (uappMadnessSipsToAffect() != 1)
                ++bad;
            if (!uappMadnessFlaskDweomerVanishes())
                ++bad;
        // ---- the elixir of youth ----
            if (uappYouthFullDoseYearsLo() != 2)
                ++bad;
            if (uappYouthFullDoseYearsHi() != 5)
                ++bad;
            if (uappYouthLowPotencyYearsLo() != 1)
                ++bad;
            if (uappYouthLowPotencyYearsHi() != 3)
                ++bad;
            if (!uappYouthSippingReducesPotency())
                ++bad;
        // ---- the potion of fire breath ----
            if (uappFireBreathRetainTurns() != 6)
                ++bad;
            if (uappFireBreathBackfirePct() != 10)
                ++bad;
            if (uappFireBreathBackfireDmgMult() != 2)
                ++bad;
            if (!uappFireBreathBackfireNoSave())
                ++bad;
            if (uappFireBreathDraughtsPerFlask() != 4)
                ++bad;
            if (uappFireBreathSmallWidthIn() != 1)
                ++bad;
            if (uappFireBreathSmallLenIn() != 2)
                ++bad;
            if (uappFireBreathSmallDmgLo() != 3)
                ++bad;
            if (uappFireBreathSmallDmgHi() != 12)
                ++bad;
            if (uappFireBreathFullWidthIn() != 2)
                ++bad;
            if (uappFireBreathFullLenIn() != 8)
                ++bad;
            if (uappFireBreathFullDmgLo() != 5)
                ++bad;
            if (uappFireBreathFullDmgHi() != 50)
                ++bad;
            if (!uappFireBreathSaveForHalf())
                ++bad;
        // ---- the oil of fiery burning ----
            if (uappFieryDmgDice() != 5) ++bad;
            if (uappFieryDmgSides() != 6) ++bad;
            if (!uappFierySaveForHalf()) ++bad;
            if (!uappFieryHurlAlwaysBreaks()) ++bad;
            if (uappFieryBlastRadiusIn() != 1)
                ++bad;
            if (uappFieryMaxCreatures() != 6) ++bad;
            if (uappFieryOpenDmgLo() != 1) ++bad;
            if (uappFieryOpenDmgHi() != 4) ++bad;
            if (uappFieryRestopperDice() != 2) ++bad;
            if (uappFieryRestopperSides() != 10)
                ++bad;
        // ---- the oil of fumbling ----
            if (uappFumblingPctPerRound() != 50)
                ++bad;
            if (!uappFumblingSolventBathRemoves())
                ++bad;
        // ---- the oil of sharpness ----
            static const int kBonus[20] = {
                1, 1, 2, 2, 2, 3, 3, 3, 3, 3,
                3, 4, 4, 4, 4, 4, 5, 5, 5, 6};
            if (uappSharpnessDurationLo() != 8)
                ++bad;
            if (uappSharpnessDurationHi() != 12)
                ++bad;
            if (uappSharpnessAppsLo() != 3) ++bad;
            if (uappSharpnessAppsHi() != 5) ++bad;
            if (uappSharpnessMaxBonus() != 6) ++bad;
            for (int i = 0; i < 20; ++i) {
                if (uappSharpnessBonusForRoll(i + 1)
                        != kBonus[i]) ++bad;
            }
            if (uappSharpnessBonusForRoll(0) != 0)
                ++bad;
            if (uappSharpnessBonusForRoll(21) != 0)
                ++bad;
        // ---- the oil of timelessness ----
            if (uappTimelessYearActsAsDays() != 1)
                ++bad;
            if (!uappTimelessNeverWearsOff()) ++bad;
            if (uappTimelessSaveBonus() != 1) ++bad;
            if (uappTimelessHorsesPerFlask() != 1)
                ++bad;
            if (uappTimelessHumansPerFlask() != 8)
                ++bad;
        // ---- rainbow hues ----
            if (!uappRainbowMetallicContainer())
                ++bad;
            if (uappRainbowHoursPerFlask() != 7)
                ++bad;
            if (uappRainbowSegmentMax() != 1)
                ++bad;
            if (uappRainbowSparingDraughts() != 7)
                ++bad;
            if (uappRainbowDraughtHours() != 1)
                ++bad;
        // ---- ventriloquism ----
            if (uappVentriloquismUses() != 6) ++bad;
            if (strcmp(uappVentriloquismAsClass(),
                    "magic-user") != 0)
                ++bad;
            if (!uappVentriloquismFadesOnTime())
                ++bad;
        // ---- vitality ----
            if (uappVitalityMaxDays() != 7) ++bad;
            if (!uappVitalityPoisonDiseaseProof())
                ++bad;
            if (uappVitalityHpPerRecovery() != 1)
                ++bad;
            if (uappVitalityRecoveryHours() != 4)
                ++bad;
            if (!uappVitalityRidesRemaining())
                ++bad;
        // ---- the part ledger ----
            if (uappPartCleanCount() != 19) ++bad;
            if (uappPartGarbledCount() != 0) ++bad;
        // ---- the R375 skeleton seam ----
            // the twelve ride the
            // potions low band of the
            // revised table
            if (uadsCategoryCount() != 8) ++bad;
            if (uadsPotionSplitLo() != 65) ++bad;
            if (!uadsPotionLowBandIsNewPotions())
                ++bad;
            if (uadsRowBodiesGarble()) ++bad;
        printf("R376 UA new potions prose part 1 pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
