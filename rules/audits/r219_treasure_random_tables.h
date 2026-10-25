    // ---- R219: the treasure random determination tables audit ----
    // DMG pp.120-123: map or magic, the map
    // table with its outdoor and containment
    // sub-tables, and the monetary and magic
    // treasure trove tables.
    {
        int bad = 0;
        // Table I: map or magic
        if (rules::mapOrMagicIsMap(5) != 1 ||
            rules::mapOrMagicIsMap(10) != 1 ||
            rules::mapOrMagicIsMap(11) != 0 ||
            rules::mapOrMagicIsMap(100) != 0 ||
            rules::mapOrMagicIsMap(-3) != 1 ||
            rules::mapOrMagicIsMap(150) != 0) ++bad;
        // Table II: the map table
        if (rules::MT_COUNT != 4 ||
            rules::MT_FALSE != 0 ||
            rules::MT_MONETARY != 1 ||
            rules::MT_MAGIC != 2 ||
            rules::MT_COMBINED != 3) ++bad;
        for (int r = 1; r <= 100; ++r)
            if (rules::mapTableResult(r) !=
                ((r <= 5) ? 0 :
                 ((r <= 70) ? 1 :
                  ((r <= 90) ? 2 : 3)))) ++bad;
        if (rules::mapTableResult(0) != 0 ||
            rules::mapTableResult(999) != 3 ||
            rules::mapNeverListsTreasure() != 1) ++bad;
        // the outdoor destination sub-table
        for (int r = 1; r <= 100; ++r)
            if (rules::mapDestIsLairCaves(r) !=
                ((r <= 20) ? 1 : 0) ||
                rules::mapDestMilesMin(r) !=
                ((r <= 20) ? 0 :
                 ((r <= 60) ? 5 :
                  ((r <= 90) ? 10 : 50))) ||
                rules::mapDestMilesMax(r) !=
                ((r <= 20) ? 0 :
                 ((r <= 60) ? 8 :
                  ((r <= 90) ? 40 : 500)))) ++bad;
        if (rules::mapDirectionDie() != 8 ||
            rules::mapDirectionNorthIsOne() != 1) ++bad;
        // the containment sub-table
        if (rules::MCON_COUNT != 6 ||
            rules::MCON_BURIED_UNGUARDED != 0 ||
            rules::MCON_IN_TOWN != 5) ++bad;
        for (int r = 1; r <= 100; ++r)
            if (rules::mapContainment(r) !=
                ((r <= 10) ? 0 :
                 ((r <= 20) ? 1 :
                  ((r <= 70) ? 2 :
                   ((r <= 80) ? 3 :
                    ((r <= 90) ? 4 : 5)))))) ++bad;
        if (rules::mapContainment(0) != 0 ||
            rules::mapContainment(300) != 5 ||
            rules::lowValueLessGuarded() != 1) ++bad;
        // Table II.A: monetary treasure
        if (rules::monetaryRowCount() != 9) ++bad;
        if (rules::monetaryBandLo(0) != 1 ||
            rules::monetaryBandHi(0) != 2 ||
            rules::monetaryBandLo(1) != 3 ||
            rules::monetaryBandHi(1) != 5 ||
            rules::monetaryBandLo(2) != 6 ||
            rules::monetaryBandHi(2) != 10 ||
            rules::monetaryBandLo(3) != 11 ||
            rules::monetaryBandHi(3) != 12 ||
            rules::monetaryBandLo(4) != 13 ||
            rules::monetaryBandHi(4) != 15 ||
            rules::monetaryBandLo(5) != 16 ||
            rules::monetaryBandHi(5) != 17 ||
            rules::monetaryBandLo(6) != 18 ||
            rules::monetaryBandHi(6) != 18 ||
            rules::monetaryBandLo(7) != 19 ||
            rules::monetaryBandHi(7) != 19 ||
            rules::monetaryBandLo(8) != 20 ||
            rules::monetaryBandHi(8) != 20) ++bad;
        if (rules::monetaryBandLo(-3) != 1 ||
            rules::monetaryBandHi(-3) != 2 ||
            rules::monetaryBandLo(9) != 20 ||
            rules::monetaryBandHi(9) != 20) ++bad;
        if (rules::monetaryPipMin(0) != 2 ||
            rules::monetaryPipMax(0) != 8 ||
            rules::monetaryMult(0) != 10000) ++bad;
        if (rules::monetaryQty(0, 2) != 20000 ||
            rules::monetaryQty(0, 8) != 80000 ||
            rules::monetaryQty(0, 99) != 80000) ++bad;
        if (rules::monetaryPipMin(1) != 2 ||
            rules::monetaryPipMax(1) != 5 ||
            rules::monetaryMult(1) != 10000) ++bad;
        if (rules::monetaryQty(1, 2) != 20000 ||
            rules::monetaryQty(1, 5) != 50000) ++bad;
        if (rules::monetaryPipMin(2) != 5 ||
            rules::monetaryPipMax(2) != 30 ||
            rules::monetaryMult(2) != 1000) ++bad;
        if (rules::monetaryQty(2, 5) != 5000 ||
            rules::monetaryQty(2, 30) != 30000) ++bad;
        if (rules::monetaryPipMin(3) != 3 ||
            rules::monetaryPipMax(3) != 18 ||
            rules::monetaryMult(3) != 1000) ++bad;
        if (rules::monetaryQty(3, 3) != 3000 ||
            rules::monetaryQty(3, 18) != 18000) ++bad;
        if (rules::monetaryPipMin(4) != 5 ||
            rules::monetaryPipMax(4) != 20 ||
            rules::monetaryMult(4) != 100) ++bad;
        if (rules::monetaryQty(4, 5) != 500 ||
            rules::monetaryQty(4, 20) != 2000) ++bad;
        if (rules::monetaryPipMin(5) != 1 ||
            rules::monetaryPipMax(5) != 10 ||
            rules::monetaryMult(5) != 10) ++bad;
        if (rules::monetaryQty(5, 1) != 10 ||
            rules::monetaryQty(5, 10) != 100) ++bad;
        if (rules::jewelryPipMin() != 5 ||
            rules::jewelryPipMax() != 50) ++bad;
        if (rules::monetaryReRollMax() != 17 ||
            rules::monetaryExtraRolls(18) != 2 ||
            rules::monetaryExtraRolls(19) != 3 ||
            rules::monetaryExtraRolls(5) != 1 ||
            rules::monetaryExtraRolls(20) != 1) ++bad;
        if (rules::monetaryEachItemRow() != 20 ||
            rules::monetaryEachItemCoversRows() != 17 ||
            rules::abandonedTheftChanceIsDmSet() != 1) ++bad;
        // Table II.B: magic treasure
        static const int kMagLo[7] = {
            1, 6, 9, 13, 15, 19, 20,
        };
        static const int kMagHi[7] = {
            5, 8, 12, 14, 18, 19, 20,
        };
        static const int kMagItems[7] = {
            1, 2, 3, 3, 12, 4, 5,
        };
        if (rules::magicBandCount() != 7) ++bad;
        for (int i = 0; i < 7; ++i)
            if (rules::magicBandLo(i) != kMagLo[i] ||
                rules::magicBandHi(i) != kMagHi[i] ||
                rules::magicBandItems(i) != kMagItems[i]) ++bad;
        if (rules::magicBandLo(-1) != 1 ||
            rules::magicBandHi(-1) != 5 ||
            rules::magicBandLo(8) != 20 ||
            rules::magicBandHi(8) != 20 ||
            rules::magicBandItems(8) != 5) ++bad;
        if (rules::magicBandExtraPotions(0) != 4 ||
            rules::magicBandExtraPotions(1) != 0) ++bad;
        if (rules::magicBandPotions(4) != 6 ||
            rules::magicBandScrolls(4) != 6 ||
            rules::magicBandPotions(0) != 0) ++bad;
        if (rules::magicBandSwords(2) != 1 ||
            rules::magicBandArmorOrShield(2) != 1 ||
            rules::magicBandMiscWeapons(2) != 1) ++bad;
        if (rules::magicBandNoSwordOrPotions(3) != 1 ||
            rules::magicBandNoSwordOrPotions(2) != 0) ++bad;
        if (rules::magicBandRings(5) != 1 ||
            rules::magicBandRings(6) != 0) ++bad;
        if (rules::magicBandRods(5) != 1 ||
            rules::magicBandRods(6) != 1 ||
            rules::magicBandRods(4) != 0) ++bad;
        if (rules::magicBandMiscMagic(6) != 1 ||
            rules::magicBandMiscMagic(5) != 0) ++bad;
        if (rules::magicTableWeightedByDesign() != 1) ++bad;
        printf("R219 treasure random determination tables audit: bad %d\n", bad);
        if (bad) return 1;
    }
    #include "rules/audits/r220_combined_hoard_table.h"  // R827: migrated
    #include "rules/audits/r221_iii_a_potions.h"  // R827: migrated
    #include "rules/audits/r222_iii_b_scrolls.h"  // R827: migrated
    #include "rules/audits/r223_iii_c_rings_footnote.h"  // R827: migrated
    #include "rules/audits/r224_iii_d_rods_staves_wands.h"  // R827: migrated
    #include "rules/audits/r225_iii_e_table_1.h"  // R827: migrated
    #include "rules/audits/r226_iii_e_table_2.h"  // R827: migrated
    #include "rules/audits/r237_iii_e_table_3.h"  // R827: migrated
    #include "rules/audits/r238_iii_e_table_4.h"  // R827: migrated
    #include "rules/audits/r239_iii_e_table_5.h"  // R827: migrated
    #include "rules/audits/r240_iii_e_special_artifacts.h"  // R827: migrated
    #include "rules/audits/r241_iii_f_armor_and_shield.h"  // R827: migrated
    #include "rules/audits/r242_iii_g_swords.h"  // R827: migrated
