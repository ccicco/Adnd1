    // ---- R259: the III.E misc magic explanation prose part 3 pins audit ----
    // part2 lines 67-108 - Book of Infinite Spells
    // through Boots of Striding and Springing,
    // global = 11065 + part2 line; the page headers
    // at 70 and 102 stripped (the R249 lesson),
    // the 102 seam splits the levitation paragraph
    // mid-sentence, pinned exactly.
    {
        int bad = 0;
        // the seven items are the engine kMisc1 rows
        // 16-22 (the R225 m1 band pins); the Vile
        // (C) class mark is row 17, the Infinite
        // row 16 is the negative control
        if (rules::m1RowCount() != 33) ++bad;
        static const int kM1Lo[7] = {
            34, 35, 36, 37, 43, 48, 52,
        };
        static const int kM1Hi[7] = {
            34, 35, 36, 42, 47, 51, 55,
        };
        for (int i = 0; i < 7; ++i)
            if (rules::m1RowLo(16 + i) != kM1Lo[i] ||
                rules::m1RowHi(16 + i) != kM1Hi[i]) ++bad;
        if (rules::m1UsableByCleric(17) != 1 ||
            rules::m1UsableByCleric(16) != 0) ++bad;
        // the book of infinite spells
        if (rules::mmpInfiniteFirstReadHpMin() != 5 ||
            rules::mmpInfiniteFirstReadHpMax() != 20 ||
            rules::mmpInfiniteFirstReadStunTurnsMin() != 5 ||
            rules::mmpInfiniteFirstReadStunTurnsMax() != 20 ||
            rules::mmpInfinitePageMin() != 23 ||
            rules::mmpInfinitePageMax() != 30 ||
            rules::mmpInfinitePageBase() != 22 ||
            rules::mmpInfinitePageDieSides() != 8 ||
            rules::mmpInfinitePageRowCount() != 5 ||
            rules::mmpInfiniteLevelDieSides() != 10 ||
            rules::mmpInfiniteMuLevelDieSides() != 12 ||
            rules::mmpInfiniteLevelRerollLo() != 8 ||
            rules::mmpInfiniteLevelRerollHi() != 10 ||
            rules::mmpInfiniteMuLevelRerollLo() != 10 ||
            rules::mmpInfiniteMuLevelRerollHi() != 12 ||
            rules::mmpInfiniteRerollDieSides() != 6 ||
            rules::mmpInfiniteMuRerollDieSides() != 8 ||
            rules::mmpInfiniteVanishesAtLastPage() != 1 ||
            rules::mmpInfiniteCastPerDay() != 1 ||
            rules::mmpInfiniteCastPerDayIfKnown() != 4 ||
            rules::mmpInfiniteTurnPctUsable() != 10 ||
            rules::mmpInfiniteTurnPctForeign() != 20 ||
            rules::mmpInfiniteTurnPctNonCasterCleric() != 25 ||
            rules::mmpInfiniteTurnPctNonCasterMu() != 30) ++bad;
        static const int kInfLo[5] = {
            1, 31, 51, 61, 96,
        };
        static const int kInfHi[5] = {
            30, 50, 60, 95, 100,
        };
        for (int i = 0; i < 5; ++i)
            if (rules::mmpInfinitePageLo(i) != kInfLo[i] ||
                rules::mmpInfinitePageHi(i) != kInfHi[i]) ++bad;
        // the book of vile darkness
        if (rules::mmpVileReadingWeeks() != 1 ||
            rules::mmpVileWisdomGain() != 1 ||
            rules::mmpVileHalfwayPct() != 50 ||
            rules::mmpVileNeutralXpLossMin() != 30000 ||
            rules::mmpVileNeutralXpLossMax() != 120000 ||
            rules::mmpVileNeutralSplitPct() != 50 ||
            rules::mmpVileGoodSaveCount() != 2 ||
            rules::mmpVileGoodXpLossBase() != 250000 ||
            rules::mmpVileGoodXpLossPerWis() != 10000 ||
            rules::mmpVileGoodHandlingHpMin() != 5 ||
            rules::mmpVileGoodHandlingHpMax() != 30 ||
            rules::mmpVileNightHagPct() != 80 ||
            rules::mmpVileNeutralHandlingHpMin() != 5 ||
            rules::mmpVileNeutralHandlingHpMax() != 20) ++bad;
        // the boots of dancing
        if (rules::mmpDancingDisguisedBootTypeCount() != 4 ||
            rules::mmpDancingTriggerCaseCount() != 2 ||
            rules::mmpDancingAcPenalty() != 4 ||
            rules::mmpDancingRemovalSpellCount() != 1) ++bad;
        // the boots of elvenkind
        if (rules::mmpElvenkindSilencePctWorst() != 95 ||
            rules::mmpElvenkindSilencePctBest() != 100) ++bad;
        // the boots of levitation (the 102 seam)
        if (rules::mmpLevitationSpeedInchesPerRound() != 20 ||
            rules::mmpLevitationWeightIncrementPounds() != 14 ||
            rules::mmpLevitationWeightDieSides() != 20 ||
            rules::mmpLevitationWeightBasePounds() != 280 ||
            rules::mmpLevitationWeightMinPounds() != 294 ||
            rules::mmpLevitationWeightMaxPounds() != 560) ++bad;
        // the boots of speed
        if (rules::mmpSpeedBaseMovementInches() != 24 ||
            rules::mmpSpeedSlowPoundsPerInch() != 10 ||
            rules::mmpSpeedFreeWeightPounds() != 200 ||
            rules::mmpSpeedExampleHumanPounds() != 180 ||
            rules::mmpSpeedExampleGearPounds() != 60 ||
            rules::mmpSpeedExampleRateInches() != 20 ||
            rules::mmpSpeedSackCoins() != 500 ||
            rules::mmpSpeedSackSlowInches() != 5 ||
            rules::mmpSpeedRestHoursPerMoveHour() != 1 ||
            rules::mmpSpeedMaxContinuousHours() != 8 ||
            rules::mmpSpeedAcBonus() != 2) ++bad;
        // the boots of striding and springing
        if (rules::mmpStridingBaseMovementInches() != 12 ||
            rules::mmpStridingMaxHoursPerDay() != 12 ||
            rules::mmpStridingRechargeHours() != 12 ||
            rules::mmpStridingNormalPaceFeet() != 3 ||
            rules::mmpStridingForwardJumpFeet() != 30 ||
            rules::mmpStridingBackwardLeapFeet() != 9 ||
            rules::mmpStridingVerticalSpringFeet() != 15 ||
            rules::mmpStridingStumbleBasePct() != 20 ||
            rules::mmpStridingStumbleDexAdjPct() != 3 ||
            rules::mmpStridingStumbleDexThreshold() != 12 ||
            rules::mmpStridingStumbleRowCount() != 6 ||
            rules::mmpStridingAcBonus() != 1) ++bad;
        static const int kStridingStumble[6] = {
            17, 14, 11, 8, 5, 2,
        };
        for (int i = 0; i < 6; ++i)
            if (rules::mmpStridingStumblePctByDex(i) !=
                    kStridingStumble[i]) ++bad;
        printf("R259 misc magic prose part 3 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
    #include "rules/audits/r260_misc_magic_prose_part_4_.h"  // R828: migrated
    #include "rules/audits/r261_misc_magic_prose_part_5_.h"  // R828: migrated
    #include "rules/audits/r262_misc_magic_prose_part_6_.h"  // R828: migrated
    #include "rules/audits/r263_misc_magic_prose_part_7_.h"  // R828: migrated
    #include "rules/audits/r264_misc_magic_prose_part_8_.h"  // R828: migrated
    #include "rules/audits/r265_misc_magic_prose_part_9_.h"  // R828: migrated
    #include "rules/audits/r266_misc_magic_prose_part_10.h"  // R828: migrated
    #include "rules/audits/r267_misc_magic_prose_part_11.h"  // R828: migrated
    #include "rules/audits/r268_misc_magic_prose_part_12.h"  // R828: migrated
    #include "rules/audits/r269_misc_magic_prose_part_13.h"  // R828: migrated
    #include "rules/audits/r270_misc_magic_prose_part_14.h"  // R828: migrated
    #include "rules/audits/r271_misc_magic_prose_part_15.h"  // R828: migrated
    #include "rules/audits/r272_misc_magic_prose_part_16.h"  // R828: migrated
    #include "rules/audits/r273_misc_magic_prose_part_17.h"  // R828: migrated
    #include "rules/audits/r274_misc_magic_prose_part_18.h"  // R828: migrated
    #include "rules/audits/r275_misc_magic_prose_part_19.h"  // R828: migrated
    #include "rules/audits/r276_misc_magic_prose_part_20.h"  // R828: migrated
    #include "rules/audits/r277_misc_magic_prose_part_21.h"  // R828: migrated
    #include "rules/audits/r278_misc_magic_prose_part_22.h"  // R828: migrated
    #include "rules/audits/r279_misc_magic_prose_part_23.h"  // R828: migrated
