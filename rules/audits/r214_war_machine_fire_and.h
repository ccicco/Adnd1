    // ---- R214: the war machine fire and siege values audit ----
    // DMG pp.108-110: the fire table, the hit
    // determination modifiers, the siege
    // attack matrix, and the defensive
    // values.
    {
        Siegefire siegefire;
        int bad = 0;
        // the fire table: every device cell
        if (siegefire.fireDeviceCount() != 6
            || FD_COUNT != 6
            || FD_BALLISTA != 0
            || FD_TREBUCHET != 5
            || SM_WOOD != 0
            || SM_EARTH != 1
            || SM_SOFT_STONE != 2
            || SM_HARD_ROCK != 3) ++bad;
        static const int kFof[6] = { 45, 15, 30, 0, 0, 10 };
        static const int kRMin[6] = { 1, 72, 60, 0, 0, 96 };
        static const int kRMax[6] = { 128, 144, 120, 1, 1, 192 };
        static const int kSmMin[6] = { 2, 2, 2, 9, 9, 3 };
        static const int kSmMax[6] = { 12, 24, 20, 16, 16, 30 };
        static const int kLMin[6] = { 3, 4, 3, 7, 13, 5 };
        static const int kLMax[6] = { 18, 16, 12, 12, 24, 20 };
        static const int kRoMin[6] = { 25, 25, 25, 50, 50, 25 };
        static const int kRoMax[6] = { 50, 25, 25, 50, 50, 25 };
        static const int kCrMin[6] = { 2, 6, 4, 10, 10, 8 };
        static const int kCrMax[6] = { 4, 10, 6, 20, 20, 12 };
        for (int d = 0; d < 6; ++d)
            if (siegefire.siegeFieldOfFireDegrees(d)
                    != kFof[d] ||
                siegefire.siegeRangeMinQuarterInches(d)
                    != kRMin[d] ||
                siegefire.siegeRangeMaxQuarterInches(d)
                    != kRMax[d] ||
                siegefire.siegeDamageSMMin(d) != kSmMin[d] ||
                siegefire.siegeDamageSMMax(d) != kSmMax[d] ||
                siegefire.siegeDamageLMin(d) != kLMin[d] ||
                siegefire.siegeDamageLMax(d) != kLMax[d] ||
                siegefire.siegeRateOfFireMinHundredths(d)
                    != kRoMin[d] ||
                siegefire.siegeRateOfFireMaxHundredths(d)
                    != kRoMax[d] ||
                siegefire.siegeCrewMin(d) != kCrMin[d] ||
                siegefire.siegeCrewMax(d) != kCrMax[d]) ++bad;
        if (siegefire.siegeFieldOfFireDegrees(
                FD_BALLISTA) != 45 ||
            siegefire.siegeFieldOfFireDegrees(
                FD_RAM) != 0 ||
            siegefire.siegeRangeMinQuarterInches(
                FD_BALLISTA) != 1 ||
            siegefire.siegeRangeMaxQuarterInches(
                FD_BALLISTA) != 128 ||
            siegefire.siegeRangeMaxQuarterInches(
                FD_TREBUCHET) != 192) ++bad;
        if (siegefire.siegeFieldOfFireDegrees(-3) != 45 ||
            siegefire.siegeRangeMaxQuarterInches(9) != 192 ||
            siegefire.siegeCrewMin(-1) != 2 ||
            siegefire.siegeCrewMax(12) != 12) ++bad;
        // the crew rules
        if (siegefire.siegeBelowMinCrewRatePct() != 50 ||
            siegefire.siegeBallistaMaxCrewRateFactor() != 2 ||
            siegefire.siegeOtherMaxCrewRateFactor() != 1) ++bad;
        // the hit determination conventions
        if (siegefire.wmHitTargetAc() != 0 ||
            siegefire.wmBallistaTargetAc() != 10) ++bad;
        // the d20 modifiers
        if (siegefire.wmModTargetStationary() != 3 ||
            siegefire.wmModMoveUnder3() != 0 ||
            siegefire.wmModMove3to12() != -3 ||
            siegefire.wmModSizeMan() != -2 ||
            siegefire.wmModSizeHorse() != 0 ||
            siegefire.wmModSizeGiant() != 2 ||
            siegefire.wmModSizeMediumBuilding() != 4 ||
            siegefire.wmModSizeLargeBuilding() != 6 ||
            siegefire.wmModSubsequentStationary() != 4 ||
            siegefire.wmWeatherCalm() != 1 ||
            siegefire.wmWeatherBreeze() != 0 ||
            siegefire.wmWeatherStrong() != -2 ||
            siegefire.wmWeatherStorm() != -4 ||
            siegefire.wmDirectFireBonus() != 4) ++bad;
        // the trajectory and cover rules
        if (siegefire.wmBallistaInterveningBlocks() != 1 ||
            siegefire.wmCatapultInterveningBlocks() != 0 ||
            siegefire.wmBallistaUnseenFirePossible() != 0 ||
            siegefire.wmUnseenScatterGrenadeRule() != 1 ||
            siegefire.wmGrenadeDiameterSmallCatFeet() != 1 ||
            siegefire.wmGrenadeDiameterTrebuchetFeet() != 2) ++bad;
        // the siege attack matrix: every cell
        if (siegefire.siegeAttackKindCount() != 22
            || SK_COUNT != 22
            || SK_BIGBY_FIST != 0
            || SK_TREBUCHET_MISSILE != 21
            || SK_HORN_OF_BLASTING != 15
            || SK_EARTHQUAKE != 6) ++bad;
        static const int kQ[88] = {
            4, 0, 2, 1,
            24, 0, 16, 8,
            16, 0, 8, 4,
            0, 40, 0, 0,
            8, 8, 8, 8,
            8, 40, 8, 4,
            0, 0, 0, 0,
            2, 0, 0, 0,
            12, 0, 4, 2,
            8, 0, 4, 2,
            4, 0, 2, 1,
            16, 0, 8, 4,
            24, 0, 16, 8,
            12, 4, 8, 4,
            12, 4, 4, 2,
            72, 24, 32, 16,
            2, 0, 0, 0,
            0, 80, 0, 0,
            4, 0, 1, 0,
            2, 2, 2, 1,
            32, 8, 8, 4,
            32, 0, 20, 12,
        };
        for (int k = 0; k < 22; ++k)
            for (int m = 0; m < 4; ++m)
                if (siegefire.siegeAttackQuarterPoints(k, m)
                        != kQ[k * 4 + m]) ++bad;
        // the per-round and per-level flags
        static const int kP[22] = {
            1, 0, 0, 0, 0, 1, 0, 0, 1, 1,
            1, 0, 0, 1, 1, 0, 0, 0, 1, 1,
            1, 0,
        };
        static const int kLv[22] = {
            0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
            0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
            0, 0,
        };
        for (int k = 0; k < 22; ++k)
            if (siegefire.siegeAttackPerRound(k)
                    != kP[k] ||
                siegefire.siegeAttackPerCasterLevel(k)
                    != kLv[k]) ++bad;
        if (siegefire.siegeAttackPerCasterLevel(
                SK_FIREBALL) != 1 ||
            siegefire.siegeAttackPerCasterLevel(
                SK_LIGHTNING_BOLT) != 1 ||
            siegefire.siegeAttackPerRound(
                SK_HORN_OF_BLASTING) != 0 ||
            siegefire.siegeAttackPerRound(
                SK_TREANT) != 1 ||
            siegefire.siegeFireDamageWetReductionPct()
                != 50 ||
            siegefire.siegeSowScrewEarthOnly() != 1 ||
            siegefire.siegeSoftStoneIncludes() != 1) ++bad;
        // the spot cells
        if (siegefire.siegeAttackQuarterPoints(
                SK_BIGBY_FIST, SM_WOOD)
                != 4 ||
            siegefire.siegeAttackQuarterPoints(
                SK_HORN_OF_BLASTING,
                SM_HARD_ROCK) != 16 ||
            siegefire.siegeAttackQuarterPoints(
                SK_DIG, SM_EARTH) != 40 ||
            siegefire.siegeAttackQuarterPoints(
                SK_MOVE_EARTH, SM_EARTH)
                != 80 ||
            siegefire.siegeAttackQuarterPoints(
                SK_RAM, SM_SOFT_STONE)
                != 1 ||
            siegefire.siegeAttackQuarterPoints(
                SK_TREBUCHET_MISSILE,
                SM_SOFT_STONE) != 20) ++bad;
        if (siegefire.siegeAttackQuarterPoints(-9, 0)
                != siegefire.siegeAttackQuarterPoints(0, 0) ||
            siegefire.siegeAttackQuarterPoints(99, 3)
                != siegefire.siegeAttackQuarterPoints(21, 3)) ++bad;
        // the earthquake dice rows
        static const int kQkMin[4] = { 5, 5, 5, 5 };
        static const int kQkMax[4] = { 60, 30, 60, 30 };
        for (int m = 0; m < 4; ++m)
            if (siegefire.siegeAttackQuakeMin(m)
                    != kQkMin[m] ||
                siegefire.siegeAttackQuakeMax(m)
                    != kQkMax[m]) ++bad;
        if (siegefire.siegeAttackQuakeMin(-3) != 5 ||
            siegefire.siegeAttackQuakeMax(9) != 30) ++bad;
        // the construction defensive values
        if (siegefire.defensiveKindCount() != 26
            || DK_COUNT != 26
            || DK_BARBICAN != 0
            || DK_WINDOW_BARRED != 25
            || DK_TOWER_ROUND != 20
            || DK_WALL_CURTAIN != 23) ++bad;
        static const int kDMin[26] = {
            150, 25, 20, 12, 10, 8, 20, 10,
            1, 3, 10, 8, 120, 2, 10, 6,
            20, 15, 12, 20, 40, 30, 40, 20,
            4, 12,
        };
        static const int kDMax[26] = {
            150, 25, 20, 12, 10, 16, 20, 10,
            1, 3, 15, 12, 120, 2, 10, 12,
            20, 15, 12, 20, 80, 50, 40, 20,
            4, 12,
        };
        for (int k = 0; k < 26; ++k)
            if (siegefire.constructionDefensiveMin(k)
                    != kDMin[k] ||
                siegefire.constructionDefensiveMax(k)
                    != kDMax[k]) ++bad;
        if (siegefire.constructionDefensiveMin(
                DK_BUILDING_WOOD) != 8 ||
            siegefire.constructionDefensiveMax(
                DK_BUILDING_WOOD) != 16 ||
            siegefire.constructionDefensiveMax(
                DK_TOWER_ROUND) != 80 ||
            siegefire.constructionDefensiveMax(
                DK_TOWER_SQUARE) != 50 ||
            siegefire.constructionDefensiveMin(
                DK_GATEHOUSE) != 120) ++bad;
        if (siegefire.constructionDefensiveMin(-3)
                != siegefire.constructionDefensiveMin(0) ||
            siegefire.constructionDefensiveMax(99)
                != siegefire.constructionDefensiveMax(25)) ++bad;
        // the defensive footnotes
        if (siegefire.dkBarbicanExcludesGates() != 1 ||
            siegefire.dkSupportsFallFirst() != 1 ||
            siegefire.dkRampartUnaffectedByMissiles() != 1 ||
            siegefire.dkCurtainWallThicknessFeet() != 10 ||
            siegefire.dkCurtainWallBreachAreaFeet() != 10) ++bad;
        // the device MHP (the R213 device enum)
        static const int kMhp[12] = {
            2, 6, 4, 2, 10, 4,
            3, 12, 0, 16, 12, 8,
        };
        for (int d = 0; d < 12; ++d)
            if (siegefire.siegeDeviceMhp(d) != kMhp[d]) ++bad;
        if (siegefire.siegeDeviceMhp(SD_BALLISTA) != 2 ||
            siegefire.siegeDeviceMhp(SD_SIEGE_TOWER)
                != 16 ||
            siegefire.siegeDeviceMhp(SD_RAM_CATCHER)
                != 0 ||
            siegefire.siegeDeviceMhp(-1) != 2 ||
            siegefire.siegeDeviceMhp(12) != 8) ++bad;
        // the additional attack forms
        if (siegefire.miningBreachCurtainFeet() != 10 ||
            siegefire.miningBreachDamagePoints() != 10 ||
            siegefire.sappingDamagePerTurn() != 1) ++bad;
        printf("R214 war machine fire and siege values audit: bad %d\n", bad);
        if (bad) return 1;
    }
    #include "r215_conducting_game.h"  // R827: migrated
    #include "r216_magical_research.h"  // R827: migrated
