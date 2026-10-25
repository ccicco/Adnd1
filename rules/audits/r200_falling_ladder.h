    // ---- R200: the falling-while-climbing ladder audit ----
    // The print rungs: 4th = 20 feet within 1 of a wall,
    // 6th = 30 feet within 4, 13th = any distance within 8.
    {
        int bad = 0;
        // the fall distance ladder: 0 below 4th, 20 at 4th-5th,
        // 30 at 6th-12th (seven levels), -1 at 13th and up
        static const int kFall[17] = {
             0,  0,  0, 20, 20, 30, 30, 30, 30, 30,
            30, 30, -1, -1, -1, -1, -1
        };
        for (int lv = 1; lv <= 17; ++lv) {
            if (rules::monkWallAssistedFallFeet(lv)
                != kFall[lv - 1]) ++bad;
        }
        // the clamps
        if (rules::monkWallAssistedFallFeet(0) != 0) ++bad;
        if (rules::monkWallAssistedFallFeet(99) != -1) ++bad;
        // the proximity ladder: 0 below 4th, 1 at 4th-5th,
        // 4 at 6th-12th (seven levels), 8 at 13th and up
        static const int kProx[17] = {
             0,  0,  0,  1,  1,  4,  4,  4,  4,  4,
             4,  4,  8,  8,  8,  8,  8
        };
        for (int lv = 1; lv <= 17; ++lv) {
            if (rules::monkWallAssistedFallProximityFeet(lv)
                != kProx[lv - 1]) ++bad;
        }
        if (rules::monkWallAssistedFallProximityFeet(0) != 0) ++bad;
        if (rules::monkWallAssistedFallProximityFeet(99) != 8)
            ++bad;
        // the wall-contact rule
        if (!rules::monkWallAssistedFallRequiresContact()) ++bad;
        // the rung boundaries: the three print cells
        if (rules::monkWallAssistedFallFeet(4) != 20)
            ++bad;   // 4th: Disciple, 20 within 1
        if (rules::monkWallAssistedFallProximityFeet(4) != 1) ++bad;
        if (rules::monkWallAssistedFallFeet(6) != 30)
            ++bad;   // 6th: Master, 30 within 4
        if (rules::monkWallAssistedFallProximityFeet(6) != 4) ++bad;
        if (rules::monkWallAssistedFallFeet(13) != -1)
            ++bad;   // 13th: Master of Winter, any within 8
        if (rules::monkWallAssistedFallProximityFeet(13) != 8)
            ++bad;
        printf("R200 falling ladder audit: bad %d\n", bad);
        if (bad) return 1;
    }
    #include "rules/audits/r201_npc_monk_alignment_split.h"  // R827: migrated
    #include "rules/audits/r203_apparent_armor_ac.h"  // R827: migrated
    #include "rules/audits/r204_item_saving_throw_matrix.h"  // R827: migrated
    #include "rules/audits/r205_spying_tables.h"  // R827: migrated
    #include "rules/audits/r206_pursuit_and_evasion.h"  // R827: migrated
    #include "rules/audits/r207_town_taxation.h"  // R827: migrated
    #include "rules/audits/r208_social_class_and_rank.h"  // R827: migrated
