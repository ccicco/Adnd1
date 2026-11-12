    // ---- R219: the treasure random determination tables audit ----
    // DMG pp.120-123: map or magic, the map
    // table with its outdoor and containment
    // sub-tables, and the monetary and magic
    // treasure trove tables.
    {
        Treasure_determination treasure_determination;
        int bad = 0;
        // Table I: map or magic
        if (treasure_determination.mapOrMagicIsMap(5) != 1 ||
            treasure_determination.mapOrMagicIsMap(10) != 1 ||
            treasure_determination.mapOrMagicIsMap(11) != 0 ||
            treasure_determination.mapOrMagicIsMap(100) != 0 ||
            treasure_determination.mapOrMagicIsMap(-3) != 1 ||
            treasure_determination.mapOrMagicIsMap(150) != 0) ++bad;
        // Table II: the map table
        if (MT_COUNT != 4 ||
            MT_FALSE != 0 ||
            MT_MONETARY != 1 ||
            MT_MAGIC != 2 ||
            MT_COMBINED != 3) ++bad;
        for (int r = 1; r <= 100; ++r)
            if (treasure_determination.mapTableResult(r) !=
                ((r <= 5) ? 0 :
                 ((r <= 70) ? 1 :
                  ((r <= 90) ? 2 : 3)))) ++bad;
        if (treasure_determination.mapTableResult(0) != 0 ||
            treasure_determination.mapTableResult(999) != 3 ||
            treasure_determination.mapNeverListsTreasure() != 1) ++bad;
        // the outdoor destination sub-table
        for (int r = 1; r <= 100; ++r)
            if (treasure_determination.mapDestIsLairCaves(r) !=
                ((r <= 20) ? 1 : 0) ||
                treasure_determination.mapDestMilesMin(r) !=
                ((r <= 20) ? 0 :
                 ((r <= 60) ? 5 :
                  ((r <= 90) ? 10 : 50))) ||
                treasure_determination.mapDestMilesMax(r) !=
                ((r <= 20) ? 0 :
                 ((r <= 60) ? 8 :
                  ((r <= 90) ? 40 : 500)))) ++bad;
        if (treasure_determination.mapDirectionDie() != 8 ||
            treasure_determination.mapDirectionNorthIsOne() != 1) ++bad;
        // the containment sub-table
        if (MCON_COUNT != 6 ||
            MCON_BURIED_UNGUARDED != 0 ||
            MCON_IN_TOWN != 5) ++bad;
        for (int r = 1; r <= 100; ++r)
            if (treasure_determination.mapContainment(r) !=
                ((r <= 10) ? 0 :
                 ((r <= 20) ? 1 :
                  ((r <= 70) ? 2 :
                   ((r <= 80) ? 3 :
                    ((r <= 90) ? 4 : 5)))))) ++bad;
        if (treasure_determination.mapContainment(0) != 0 ||
            treasure_determination.mapContainment(300) != 5 ||
            treasure_determination.lowValueLessGuarded() != 1) ++bad;
        // Table II.A: monetary treasure
        if (treasure_determination.monetaryRowCount() != 9) ++bad;
        if (treasure_determination.monetaryBandLo(0) != 1 ||
            treasure_determination.monetaryBandHi(0) != 2 ||
            treasure_determination.monetaryBandLo(1) != 3 ||
            treasure_determination.monetaryBandHi(1) != 5 ||
            treasure_determination.monetaryBandLo(2) != 6 ||
            treasure_determination.monetaryBandHi(2) != 10 ||
            treasure_determination.monetaryBandLo(3) != 11 ||
            treasure_determination.monetaryBandHi(3) != 12 ||
            treasure_determination.monetaryBandLo(4) != 13 ||
            treasure_determination.monetaryBandHi(4) != 15 ||
            treasure_determination.monetaryBandLo(5) != 16 ||
            treasure_determination.monetaryBandHi(5) != 17 ||
            treasure_determination.monetaryBandLo(6) != 18 ||
            treasure_determination.monetaryBandHi(6) != 18 ||
            treasure_determination.monetaryBandLo(7) != 19 ||
            treasure_determination.monetaryBandHi(7) != 19 ||
            treasure_determination.monetaryBandLo(8) != 20 ||
            treasure_determination.monetaryBandHi(8) != 20) ++bad;
        if (treasure_determination.monetaryBandLo(-3) != 1 ||
            treasure_determination.monetaryBandHi(-3) != 2 ||
            treasure_determination.monetaryBandLo(9) != 20 ||
            treasure_determination.monetaryBandHi(9) != 20) ++bad;
        if (treasure_determination.monetaryPipMin(0) != 2 ||
            treasure_determination.monetaryPipMax(0) != 8 ||
            treasure_determination.monetaryMult(0) != 10000) ++bad;
        if (treasure_determination.monetaryQty(0, 2) != 20000 ||
            treasure_determination.monetaryQty(0, 8) != 80000 ||
            treasure_determination.monetaryQty(0, 99) != 80000) ++bad;
        if (treasure_determination.monetaryPipMin(1) != 2 ||
            treasure_determination.monetaryPipMax(1) != 5 ||
            treasure_determination.monetaryMult(1) != 10000) ++bad;
        if (treasure_determination.monetaryQty(1, 2) != 20000 ||
            treasure_determination.monetaryQty(1, 5) != 50000) ++bad;
        if (treasure_determination.monetaryPipMin(2) != 5 ||
            treasure_determination.monetaryPipMax(2) != 30 ||
            treasure_determination.monetaryMult(2) != 1000) ++bad;
        if (treasure_determination.monetaryQty(2, 5) != 5000 ||
            treasure_determination.monetaryQty(2, 30) != 30000) ++bad;
        if (treasure_determination.monetaryPipMin(3) != 3 ||
            treasure_determination.monetaryPipMax(3) != 18 ||
            treasure_determination.monetaryMult(3) != 1000) ++bad;
        if (treasure_determination.monetaryQty(3, 3) != 3000 ||
            treasure_determination.monetaryQty(3, 18) != 18000) ++bad;
        if (treasure_determination.monetaryPipMin(4) != 5 ||
            treasure_determination.monetaryPipMax(4) != 20 ||
            treasure_determination.monetaryMult(4) != 100) ++bad;
        if (treasure_determination.monetaryQty(4, 5) != 500 ||
            treasure_determination.monetaryQty(4, 20) != 2000) ++bad;
        if (treasure_determination.monetaryPipMin(5) != 1 ||
            treasure_determination.monetaryPipMax(5) != 10 ||
            treasure_determination.monetaryMult(5) != 10) ++bad;
        if (treasure_determination.monetaryQty(5, 1) != 10 ||
            treasure_determination.monetaryQty(5, 10) != 100) ++bad;
        if (treasure_determination.jewelryPipMin() != 5 ||
            treasure_determination.jewelryPipMax() != 50) ++bad;
        if (treasure_determination.monetaryReRollMax() != 17 ||
            treasure_determination.monetaryExtraRolls(18) != 2 ||
            treasure_determination.monetaryExtraRolls(19) != 3 ||
            treasure_determination.monetaryExtraRolls(5) != 1 ||
            treasure_determination.monetaryExtraRolls(20) != 1) ++bad;
        if (treasure_determination.monetaryEachItemRow() != 20 ||
            treasure_determination.monetaryEachItemCoversRows() != 17 ||
            treasure_determination.abandonedTheftChanceIsDmSet() != 1) ++bad;
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
        if (treasure_determination.magicBandCount() != 7) ++bad;
        for (int i = 0; i < 7; ++i)
            if (treasure_determination.magicBandLo(i) != kMagLo[i] ||
                treasure_determination.magicBandHi(i) != kMagHi[i] ||
                treasure_determination.magicBandItems(i) != kMagItems[i]) ++bad;
        if (treasure_determination.magicBandLo(-1) != 1 ||
            treasure_determination.magicBandHi(-1) != 5 ||
            treasure_determination.magicBandLo(8) != 20 ||
            treasure_determination.magicBandHi(8) != 20 ||
            treasure_determination.magicBandItems(8) != 5) ++bad;
        if (treasure_determination.magicBandExtraPotions(0) != 4 ||
            treasure_determination.magicBandExtraPotions(1) != 0) ++bad;
        if (treasure_determination.magicBandPotions(4) != 6 ||
            treasure_determination.magicBandScrolls(4) != 6 ||
            treasure_determination.magicBandPotions(0) != 0) ++bad;
        if (treasure_determination.magicBandSwords(2) != 1 ||
            treasure_determination.magicBandArmorOrShield(2) != 1 ||
            treasure_determination.magicBandMiscWeapons(2) != 1) ++bad;
        if (treasure_determination.magicBandNoSwordOrPotions(3) != 1 ||
            treasure_determination.magicBandNoSwordOrPotions(2) != 0) ++bad;
        if (treasure_determination.magicBandRings(5) != 1 ||
            treasure_determination.magicBandRings(6) != 0) ++bad;
        if (treasure_determination.magicBandRods(5) != 1 ||
            treasure_determination.magicBandRods(6) != 1 ||
            treasure_determination.magicBandRods(4) != 0) ++bad;
        if (treasure_determination.magicBandMiscMagic(6) != 1 ||
            treasure_determination.magicBandMiscMagic(5) != 0) ++bad;
        if (treasure_determination.magicTableWeightedByDesign() != 1) ++bad;
        printf("R219 treasure random determination tables audit: bad %d\n", bad);
        if (bad) return 1;
    }
    #include "r220_combined_hoard_table.h"  // R827: migrated
    #include "r221_iii_a_potions.h"  // R827: migrated
    #include "r222_iii_b_scrolls.h"  // R827: migrated
    #include "r223_iii_c_rings_footnote.h"  // R827: migrated
    #include "r224_iii_d_rods_staves_wands.h"  // R827: migrated
    #include "r225_iii_e_table_1.h"  // R827: migrated
    #include "r226_iii_e_table_2.h"  // R827: migrated
    #include "r237_iii_e_table_3.h"  // R827: migrated
    #include "r238_iii_e_table_4.h"  // R827: migrated
    #include "r239_iii_e_table_5.h"  // R827: migrated
    #include "r240_iii_e_special_artifacts.h"  // R827: migrated
    #include "r241_iii_f_armor_and_shield.h"  // R827: migrated
    #include "r242_iii_g_swords.h"  // R827: migrated
