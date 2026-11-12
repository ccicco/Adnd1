    // ---- R259: the III.E misc magic explanation prose part 3 pins audit ----
    // part2 lines 67-108 - Book of Infinite Spells
    // through Boots of Striding and Springing,
    // global = 11065 + part2 line; the page headers
    // at 70 and 102 stripped (the R249 lesson),
    // the 102 seam splits the levitation paragraph
    // mid-sentence, pinned exactly.
    {
        Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing miscmagic;
        Miscmagic_table1_footnotes miscmagic_table1_footnotes;
        int bad = 0;
        // the seven items are the engine kMisc1 rows
        // 16-22 (the R225 m1 band pins); the Vile
        // (C) class mark is row 17, the Infinite
        // row 16 is the negative control
        if (miscmagic_table1_footnotes.m1RowCount() != 33) ++bad;
        static const int kM1Lo[7] = {
            34, 35, 36, 37, 43, 48, 52,
        };
        static const int kM1Hi[7] = {
            34, 35, 36, 42, 47, 51, 55,
        };
        for (int i = 0; i < 7; ++i)
            if (miscmagic_table1_footnotes.m1RowLo(16 + i) != kM1Lo[i] ||
                miscmagic_table1_footnotes.m1RowHi(16 + i) != kM1Hi[i]) ++bad;
        if (miscmagic_table1_footnotes.m1UsableByCleric(17) != 1 ||
            miscmagic_table1_footnotes.m1UsableByCleric(16) != 0) ++bad;
        // the book of infinite spells
        if (miscmagic.mmpInfiniteFirstReadHpMin() != 5 ||
            miscmagic.mmpInfiniteFirstReadHpMax() != 20 ||
            miscmagic.mmpInfiniteFirstReadStunTurnsMin() != 5 ||
            miscmagic.mmpInfiniteFirstReadStunTurnsMax() != 20 ||
            miscmagic.mmpInfinitePageMin() != 23 ||
            miscmagic.mmpInfinitePageMax() != 30 ||
            miscmagic.mmpInfinitePageBase() != 22 ||
            miscmagic.mmpInfinitePageDieSides() != 8 ||
            miscmagic.mmpInfinitePageRowCount() != 5 ||
            miscmagic.mmpInfiniteLevelDieSides() != 10 ||
            miscmagic.mmpInfiniteMuLevelDieSides() != 12 ||
            miscmagic.mmpInfiniteLevelRerollLo() != 8 ||
            miscmagic.mmpInfiniteLevelRerollHi() != 10 ||
            miscmagic.mmpInfiniteMuLevelRerollLo() != 10 ||
            miscmagic.mmpInfiniteMuLevelRerollHi() != 12 ||
            miscmagic.mmpInfiniteRerollDieSides() != 6 ||
            miscmagic.mmpInfiniteMuRerollDieSides() != 8 ||
            miscmagic.mmpInfiniteVanishesAtLastPage() != 1 ||
            miscmagic.mmpInfiniteCastPerDay() != 1 ||
            miscmagic.mmpInfiniteCastPerDayIfKnown() != 4 ||
            miscmagic.mmpInfiniteTurnPctUsable() != 10 ||
            miscmagic.mmpInfiniteTurnPctForeign() != 20 ||
            miscmagic.mmpInfiniteTurnPctNonCasterCleric() != 25 ||
            miscmagic.mmpInfiniteTurnPctNonCasterMu() != 30) ++bad;
        static const int kInfLo[5] = {
            1, 31, 51, 61, 96,
        };
        static const int kInfHi[5] = {
            30, 50, 60, 95, 100,
        };
        for (int i = 0; i < 5; ++i)
            if (miscmagic.mmpInfinitePageLo(i) != kInfLo[i] ||
                miscmagic.mmpInfinitePageHi(i) != kInfHi[i]) ++bad;
        // the book of vile darkness
        if (miscmagic.mmpVileReadingWeeks() != 1 ||
            miscmagic.mmpVileWisdomGain() != 1 ||
            miscmagic.mmpVileHalfwayPct() != 50 ||
            miscmagic.mmpVileNeutralXpLossMin() != 30000 ||
            miscmagic.mmpVileNeutralXpLossMax() != 120000 ||
            miscmagic.mmpVileNeutralSplitPct() != 50 ||
            miscmagic.mmpVileGoodSaveCount() != 2 ||
            miscmagic.mmpVileGoodXpLossBase() != 250000 ||
            miscmagic.mmpVileGoodXpLossPerWis() != 10000 ||
            miscmagic.mmpVileGoodHandlingHpMin() != 5 ||
            miscmagic.mmpVileGoodHandlingHpMax() != 30 ||
            miscmagic.mmpVileNightHagPct() != 80 ||
            miscmagic.mmpVileNeutralHandlingHpMin() != 5 ||
            miscmagic.mmpVileNeutralHandlingHpMax() != 20) ++bad;
        // the boots of dancing
        if (miscmagic.mmpDancingDisguisedBootTypeCount() != 4 ||
            miscmagic.mmpDancingTriggerCaseCount() != 2 ||
            miscmagic.mmpDancingAcPenalty() != 4 ||
            miscmagic.mmpDancingRemovalSpellCount() != 1) ++bad;
        // the boots of elvenkind
        if (miscmagic.mmpElvenkindSilencePctWorst() != 95 ||
            miscmagic.mmpElvenkindSilencePctBest() != 100) ++bad;
        // the boots of levitation (the 102 seam)
        if (miscmagic.mmpLevitationSpeedInchesPerRound() != 20 ||
            miscmagic.mmpLevitationWeightIncrementPounds() != 14 ||
            miscmagic.mmpLevitationWeightDieSides() != 20 ||
            miscmagic.mmpLevitationWeightBasePounds() != 280 ||
            miscmagic.mmpLevitationWeightMinPounds() != 294 ||
            miscmagic.mmpLevitationWeightMaxPounds() != 560) ++bad;
        // the boots of speed
        if (miscmagic.mmpSpeedBaseMovementInches() != 24 ||
            miscmagic.mmpSpeedSlowPoundsPerInch() != 10 ||
            miscmagic.mmpSpeedFreeWeightPounds() != 200 ||
            miscmagic.mmpSpeedExampleHumanPounds() != 180 ||
            miscmagic.mmpSpeedExampleGearPounds() != 60 ||
            miscmagic.mmpSpeedExampleRateInches() != 20 ||
            miscmagic.mmpSpeedSackCoins() != 500 ||
            miscmagic.mmpSpeedSackSlowInches() != 5 ||
            miscmagic.mmpSpeedRestHoursPerMoveHour() != 1 ||
            miscmagic.mmpSpeedMaxContinuousHours() != 8 ||
            miscmagic.mmpSpeedAcBonus() != 2) ++bad;
        // the boots of striding and springing
        if (miscmagic.mmpStridingBaseMovementInches() != 12 ||
            miscmagic.mmpStridingMaxHoursPerDay() != 12 ||
            miscmagic.mmpStridingRechargeHours() != 12 ||
            miscmagic.mmpStridingNormalPaceFeet() != 3 ||
            miscmagic.mmpStridingForwardJumpFeet() != 30 ||
            miscmagic.mmpStridingBackwardLeapFeet() != 9 ||
            miscmagic.mmpStridingVerticalSpringFeet() != 15 ||
            miscmagic.mmpStridingStumbleBasePct() != 20 ||
            miscmagic.mmpStridingStumbleDexAdjPct() != 3 ||
            miscmagic.mmpStridingStumbleDexThreshold() != 12 ||
            miscmagic.mmpStridingStumbleRowCount() != 6 ||
            miscmagic.mmpStridingAcBonus() != 1) ++bad;
        static const int kStridingStumble[6] = {
            17, 14, 11, 8, 5, 2,
        };
        for (int i = 0; i < 6; ++i)
            if (miscmagic.mmpStridingStumblePctByDex(i) !=
                    kStridingStumble[i]) ++bad;
        printf("R259 misc magic prose part 3 pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
    #include "r260_misc_magic_prose_part_4_.h"  // R828: migrated
    #include "r261_misc_magic_prose_part_5_.h"  // R828: migrated
    #include "r262_misc_magic_prose_part_6_.h"  // R828: migrated
    #include "r263_misc_magic_prose_part_7_.h"  // R828: migrated
    #include "r264_misc_magic_prose_part_8_.h"  // R828: migrated
    #include "r265_misc_magic_prose_part_9_.h"  // R828: migrated
    #include "r266_misc_magic_prose_part_10.h"  // R828: migrated
    #include "r267_misc_magic_prose_part_11.h"  // R828: migrated
    #include "r268_misc_magic_prose_part_12.h"  // R828: migrated
    #include "r269_misc_magic_prose_part_13.h"  // R828: migrated
    #include "r270_misc_magic_prose_part_14.h"  // R828: migrated
    #include "r271_misc_magic_prose_part_15.h"  // R828: migrated
    #include "r272_misc_magic_prose_part_16.h"  // R828: migrated
    #include "r273_misc_magic_prose_part_17.h"  // R828: migrated
    #include "r274_misc_magic_prose_part_18.h"  // R828: migrated
    #include "r275_misc_magic_prose_part_19.h"  // R828: migrated
    #include "r276_misc_magic_prose_part_20.h"  // R828: migrated
    #include "r277_misc_magic_prose_part_21.h"  // R828: migrated
    #include "r278_misc_magic_prose_part_22.h"  // R828: migrated
    #include "r279_misc_magic_prose_part_23.h"  // R828: migrated
