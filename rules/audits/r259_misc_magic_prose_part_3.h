    // ---- R259: the III.E misc magic explanation prose part 3 pins audit ----
    // part2 lines 67-108 - Book of Infinite Spells
    // through Boots of Striding and Springing,
    // global = 11065 + part2 line; the page headers
    // at 70 and 102 stripped (the R249 lesson),
    // the 102 seam splits the levitation paragraph
    // mid-sentence, pinned exactly.
    {
        Miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing;
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
        if (miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpInfiniteFirstReadHpMin() != 5 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpInfiniteFirstReadHpMax() != 20 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpInfiniteFirstReadStunTurnsMin() != 5 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpInfiniteFirstReadStunTurnsMax() != 20 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpInfinitePageMin() != 23 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpInfinitePageMax() != 30 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpInfinitePageBase() != 22 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpInfinitePageDieSides() != 8 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpInfinitePageRowCount() != 5 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpInfiniteLevelDieSides() != 10 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpInfiniteMuLevelDieSides() != 12 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpInfiniteLevelRerollLo() != 8 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpInfiniteLevelRerollHi() != 10 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpInfiniteMuLevelRerollLo() != 10 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpInfiniteMuLevelRerollHi() != 12 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpInfiniteRerollDieSides() != 6 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpInfiniteMuRerollDieSides() != 8 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpInfiniteVanishesAtLastPage() != 1 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpInfiniteCastPerDay() != 1 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpInfiniteCastPerDayIfKnown() != 4 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpInfiniteTurnPctUsable() != 10 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpInfiniteTurnPctForeign() != 20 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpInfiniteTurnPctNonCasterCleric() != 25 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpInfiniteTurnPctNonCasterMu() != 30) ++bad;
        static const int kInfLo[5] = {
            1, 31, 51, 61, 96,
        };
        static const int kInfHi[5] = {
            30, 50, 60, 95, 100,
        };
        for (int i = 0; i < 5; ++i)
            if (miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpInfinitePageLo(i) != kInfLo[i] ||
                miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpInfinitePageHi(i) != kInfHi[i]) ++bad;
        // the book of vile darkness
        if (miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpVileReadingWeeks() != 1 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpVileWisdomGain() != 1 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpVileHalfwayPct() != 50 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpVileNeutralXpLossMin() != 30000 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpVileNeutralXpLossMax() != 120000 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpVileNeutralSplitPct() != 50 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpVileGoodSaveCount() != 2 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpVileGoodXpLossBase() != 250000 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpVileGoodXpLossPerWis() != 10000 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpVileGoodHandlingHpMin() != 5 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpVileGoodHandlingHpMax() != 30 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpVileNightHagPct() != 80 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpVileNeutralHandlingHpMin() != 5 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpVileNeutralHandlingHpMax() != 20) ++bad;
        // the boots of dancing
        if (miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpDancingDisguisedBootTypeCount() != 4 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpDancingTriggerCaseCount() != 2 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpDancingAcPenalty() != 4 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpDancingRemovalSpellCount() != 1) ++bad;
        // the boots of elvenkind
        if (miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpElvenkindSilencePctWorst() != 95 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpElvenkindSilencePctBest() != 100) ++bad;
        // the boots of levitation (the 102 seam)
        if (miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpLevitationSpeedInchesPerRound() != 20 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpLevitationWeightIncrementPounds() != 14 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpLevitationWeightDieSides() != 20 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpLevitationWeightBasePounds() != 280 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpLevitationWeightMinPounds() != 294 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpLevitationWeightMaxPounds() != 560) ++bad;
        // the boots of speed
        if (miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpSpeedBaseMovementInches() != 24 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpSpeedSlowPoundsPerInch() != 10 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpSpeedFreeWeightPounds() != 200 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpSpeedExampleHumanPounds() != 180 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpSpeedExampleGearPounds() != 60 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpSpeedExampleRateInches() != 20 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpSpeedSackCoins() != 500 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpSpeedSackSlowInches() != 5 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpSpeedRestHoursPerMoveHour() != 1 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpSpeedMaxContinuousHours() != 8 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpSpeedAcBonus() != 2) ++bad;
        // the boots of striding and springing
        if (miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpStridingBaseMovementInches() != 12 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpStridingMaxHoursPerDay() != 12 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpStridingRechargeHours() != 12 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpStridingNormalPaceFeet() != 3 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpStridingForwardJumpFeet() != 30 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpStridingBackwardLeapFeet() != 9 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpStridingVerticalSpringFeet() != 15 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpStridingStumbleBasePct() != 20 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpStridingStumbleDexAdjPct() != 3 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpStridingStumbleDexThreshold() != 12 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpStridingStumbleRowCount() != 6 ||
            miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpStridingAcBonus() != 1) ++bad;
        static const int kStridingStumble[6] = {
            17, 14, 11, 8, 5, 2,
        };
        for (int i = 0; i < 6; ++i)
            if (miscmagic_book_of_infinite_spells_to_boots_of_striding_and_springing.mmpStridingStumblePctByDex(i) !=
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
