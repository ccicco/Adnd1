    // ---- R194: the wisdom magical defense repin audit ----
    // The printed Wisdom Table I ladder, cell for cell, and
    // the delegation agreement with the R192 header pin.
    {
        int bad = 0;
        // the printed ladder (3 through 18):
        // -3, -2, -1, -1, -1, then none through 14,
        // then +1 +2 +3 +4
        static const int kAdj[16] = {
            -3, -2, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0,
             1,  2,  3,  4
        };
        for (int w = 3; w <= 18; ++w) {
            if (rules::wisMagDefAdj((uint8_t)w)
                != kAdj[w - 3]) ++bad;
        }
        // the delegation: wisMagDefAdj and the R192 header
        // accessor read the same ladder at every score
        for (int w = 0; w <= 25; ++w) {
            if (rules::wisMagDefAdj((uint8_t)w)
                != rules::wisMagicalAttackAdj((uint8_t)w)) ++bad;
        }
        // the clamps read the edge rows
        if (rules::wisMagDefAdj(0) != -3) ++bad;
        if (rules::wisMagDefAdj(99) != 4) ++bad;
        // the historically divergent cells (the R177 read:
        // the engine convention capped at -2/+2)
        if (rules::wisMagDefAdj(3) != -3) ++bad;
        if (rules::wisMagDefAdj(17) != 3) ++bad;
        if (rules::wisMagDefAdj(18) != 4) ++bad;
        printf("R194 wisdom defense repin audit: bad %d\n", bad);
        if (bad) return 1;
    }
    #include "rules/audits/r195_int_languages_repin.h"  // R827: migrated
    #include "rules/audits/r196_int_table_ii.h"  // R827: migrated
    #include "rules/audits/r197_mental_form_flag.h"  // R827: migrated
    #include "rules/audits/r198_class_weapon_allowlists.h"  // R827: migrated
    #include "rules/audits/r199_oil_and_poison_columns.h"  // R827: migrated
