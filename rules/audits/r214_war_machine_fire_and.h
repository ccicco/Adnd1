    // ---- R214: the war machine fire and siege values audit ----
    // DMG pp.108-110: the fire table, the hit
    // determination modifiers, the siege
    // attack matrix, and the defensive
    // values.
    {
        int bad = 0;
        // the fire table: every device cell
        if (rules::fireDeviceCount() != 6
            || rules::FD_COUNT != 6
            || rules::FD_BALLISTA != 0
            || rules::FD_TREBUCHET != 5
            || rules::SM_WOOD != 0
            || rules::SM_EARTH != 1
            || rules::SM_SOFT_STONE != 2
            || rules::SM_HARD_ROCK != 3) ++bad;
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
            if (rules::siegeFieldOfFireDegrees(d)
                    != kFof[d] ||
                rules::siegeRangeMinQuarterInches(d)
                    != kRMin[d] ||
                rules::siegeRangeMaxQuarterInches(d)
                    != kRMax[d] ||
                rules::siegeDamageSMMin(d) != kSmMin[d] ||
                rules::siegeDamageSMMax(d) != kSmMax[d] ||
                rules::siegeDamageLMin(d) != kLMin[d] ||
                rules::siegeDamageLMax(d) != kLMax[d] ||
                rules::siegeRateOfFireMinHundredths(d)
                    != kRoMin[d] ||
                rules::siegeRateOfFireMaxHundredths(d)
                    != kRoMax[d] ||
                rules::siegeCrewMin(d) != kCrMin[d] ||
                rules::siegeCrewMax(d) != kCrMax[d]) ++bad;
        if (rules::siegeFieldOfFireDegrees(
                rules::FD_BALLISTA) != 45 ||
            rules::siegeFieldOfFireDegrees(
                rules::FD_RAM) != 0 ||
            rules::siegeRangeMinQuarterInches(
                rules::FD_BALLISTA) != 1 ||
            rules::siegeRangeMaxQuarterInches(
                rules::FD_BALLISTA) != 128 ||
            rules::siegeRangeMaxQuarterInches(
                rules::FD_TREBUCHET) != 192) ++bad;
        if (rules::siegeFieldOfFireDegrees(-3) != 45 ||
            rules::siegeRangeMaxQuarterInches(9) != 192 ||
            rules::siegeCrewMin(-1) != 2 ||
            rules::siegeCrewMax(12) != 12) ++bad;
        // the crew rules
        if (rules::siegeBelowMinCrewRatePct() != 50 ||
            rules::siegeBallistaMaxCrewRateFactor() != 2 ||
            rules::siegeOtherMaxCrewRateFactor() != 1) ++bad;
        // the hit determination conventions
        if (rules::wmHitTargetAc() != 0 ||
            rules::wmBallistaTargetAc() != 10) ++bad;
        // the d20 modifiers
        if (rules::wmModTargetStationary() != 3 ||
            rules::wmModMoveUnder3() != 0 ||
            rules::wmModMove3to12() != -3 ||
            rules::wmModSizeMan() != -2 ||
            rules::wmModSizeHorse() != 0 ||
            rules::wmModSizeGiant() != 2 ||
            rules::wmModSizeMediumBuilding() != 4 ||
            rules::wmModSizeLargeBuilding() != 6 ||
            rules::wmModSubsequentStationary() != 4 ||
            rules::wmWeatherCalm() != 1 ||
            rules::wmWeatherBreeze() != 0 ||
            rules::wmWeatherStrong() != -2 ||
            rules::wmWeatherStorm() != -4 ||
            rules::wmDirectFireBonus() != 4) ++bad;
        // the trajectory and cover rules
        if (rules::wmBallistaInterveningBlocks() != 1 ||
            rules::wmCatapultInterveningBlocks() != 0 ||
            rules::wmBallistaUnseenFirePossible() != 0 ||
            rules::wmUnseenScatterGrenadeRule() != 1 ||
            rules::wmGrenadeDiameterSmallCatFeet() != 1 ||
            rules::wmGrenadeDiameterTrebuchetFeet() != 2) ++bad;
        // the siege attack matrix: every cell
        if (rules::siegeAttackKindCount() != 22
            || rules::SK_COUNT != 22
            || rules::SK_BIGBY_FIST != 0
            || rules::SK_TREBUCHET_MISSILE != 21
            || rules::SK_HORN_OF_BLASTING != 15
            || rules::SK_EARTHQUAKE != 6) ++bad;
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
                if (rules::siegeAttackQuarterPoints(k, m)
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
            if (rules::siegeAttackPerRound(k)
                    != kP[k] ||
                rules::siegeAttackPerCasterLevel(k)
                    != kLv[k]) ++bad;
        if (rules::siegeAttackPerCasterLevel(
                rules::SK_FIREBALL) != 1 ||
            rules::siegeAttackPerCasterLevel(
                rules::SK_LIGHTNING_BOLT) != 1 ||
            rules::siegeAttackPerRound(
                rules::SK_HORN_OF_BLASTING) != 0 ||
            rules::siegeAttackPerRound(
                rules::SK_TREANT) != 1 ||
            rules::siegeFireDamageWetReductionPct()
                != 50 ||
            rules::siegeSowScrewEarthOnly() != 1 ||
            rules::siegeSoftStoneIncludes() != 1) ++bad;
        // the spot cells
        if (rules::siegeAttackQuarterPoints(
                rules::SK_BIGBY_FIST, rules::SM_WOOD)
                != 4 ||
            rules::siegeAttackQuarterPoints(
                rules::SK_HORN_OF_BLASTING,
                rules::SM_HARD_ROCK) != 16 ||
            rules::siegeAttackQuarterPoints(
                rules::SK_DIG, rules::SM_EARTH) != 40 ||
            rules::siegeAttackQuarterPoints(
                rules::SK_MOVE_EARTH, rules::SM_EARTH)
                != 80 ||
            rules::siegeAttackQuarterPoints(
                rules::SK_RAM, rules::SM_SOFT_STONE)
                != 1 ||
            rules::siegeAttackQuarterPoints(
                rules::SK_TREBUCHET_MISSILE,
                rules::SM_SOFT_STONE) != 20) ++bad;
        if (rules::siegeAttackQuarterPoints(-9, 0)
                != rules::siegeAttackQuarterPoints(0, 0) ||
            rules::siegeAttackQuarterPoints(99, 3)
                != rules::siegeAttackQuarterPoints(21, 3)) ++bad;
        // the earthquake dice rows
        static const int kQkMin[4] = { 5, 5, 5, 5 };
        static const int kQkMax[4] = { 60, 30, 60, 30 };
        for (int m = 0; m < 4; ++m)
            if (rules::siegeAttackQuakeMin(m)
                    != kQkMin[m] ||
                rules::siegeAttackQuakeMax(m)
                    != kQkMax[m]) ++bad;
        if (rules::siegeAttackQuakeMin(-3) != 5 ||
            rules::siegeAttackQuakeMax(9) != 30) ++bad;
        // the construction defensive values
        if (rules::defensiveKindCount() != 26
            || rules::DK_COUNT != 26
            || rules::DK_BARBICAN != 0
            || rules::DK_WINDOW_BARRED != 25
            || rules::DK_TOWER_ROUND != 20
            || rules::DK_WALL_CURTAIN != 23) ++bad;
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
            if (rules::constructionDefensiveMin(k)
                    != kDMin[k] ||
                rules::constructionDefensiveMax(k)
                    != kDMax[k]) ++bad;
        if (rules::constructionDefensiveMin(
                rules::DK_BUILDING_WOOD) != 8 ||
            rules::constructionDefensiveMax(
                rules::DK_BUILDING_WOOD) != 16 ||
            rules::constructionDefensiveMax(
                rules::DK_TOWER_ROUND) != 80 ||
            rules::constructionDefensiveMax(
                rules::DK_TOWER_SQUARE) != 50 ||
            rules::constructionDefensiveMin(
                rules::DK_GATEHOUSE) != 120) ++bad;
        if (rules::constructionDefensiveMin(-3)
                != rules::constructionDefensiveMin(0) ||
            rules::constructionDefensiveMax(99)
                != rules::constructionDefensiveMax(25)) ++bad;
        // the defensive footnotes
        if (rules::dkBarbicanExcludesGates() != 1 ||
            rules::dkSupportsFallFirst() != 1 ||
            rules::dkRampartUnaffectedByMissiles() != 1 ||
            rules::dkCurtainWallThicknessFeet() != 10 ||
            rules::dkCurtainWallBreachAreaFeet() != 10) ++bad;
        // the device MHP (the R213 device enum)
        static const int kMhp[12] = {
            2, 6, 4, 2, 10, 4,
            3, 12, 0, 16, 12, 8,
        };
        for (int d = 0; d < 12; ++d)
            if (rules::siegeDeviceMhp(d) != kMhp[d]) ++bad;
        if (rules::siegeDeviceMhp(rules::SD_BALLISTA) != 2 ||
            rules::siegeDeviceMhp(rules::SD_SIEGE_TOWER)
                != 16 ||
            rules::siegeDeviceMhp(rules::SD_RAM_CATCHER)
                != 0 ||
            rules::siegeDeviceMhp(-1) != 2 ||
            rules::siegeDeviceMhp(12) != 8) ++bad;
        // the additional attack forms
        if (rules::miningBreachCurtainFeet() != 10 ||
            rules::miningBreachDamagePoints() != 10 ||
            rules::sappingDamagePerTurn() != 1) ++bad;
        printf("R214 war machine fire and siege values audit: bad %d\n", bad);
        if (bad) return 1;
    }
    #include "rules/audits/r215_conducting_game.h"  // R827: migrated
    #include "rules/audits/r216_magical_research.h"  // R827: migrated
