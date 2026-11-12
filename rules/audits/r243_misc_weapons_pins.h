    // ---- R243: the III.H misc weapons pins audit ----
    // DMG p.131-132: the miscellaneous weapons
    // table - the 36 rows, the ammo quantity
    // ranges and the duplicate Hammer +2 rows.
    {
        Mweapons mweapons;
        int bad = 0;
        // the row identity: the 36 die bands
        if (mweapons.mwRowCount() != 36) ++bad;
        static const int kLo[36] = {
            1, 9, 13, 15, 16, 21, 23, 24, 25, 28, 33, 36,
            37, 38, 39, 47, 51, 52, 57, 61, 63, 64, 65, 68,
            73, 76, 77, 78, 81, 84, 89, 90, 95, 97, 98, 100,
        };
        static const int kHi[36] = {
            8, 12, 14, 15, 20, 22, 23, 24, 27, 32, 35, 36,
            37, 38, 46, 50, 51, 56, 60, 62, 63, 64, 67, 72,
            75, 76, 77, 80, 83, 88, 89, 94, 96, 97, 99, 100,
        };
        static const int kXp[36] = {
            20, 50, 75, 250, 300, 600, 750, 1000, 400, 50, 500, 2000,
            1500, 1500, 100, 250, 350, 450, 300, 650, 1500, 2500, 750, 350,
            700, 1750, 1500, 350, 400, 750, 700, 500, 1000, 1750, 0, 1500,
        };
        static const int kGp[36] = {
            120, 300, 450, 2500, 1750, 3750, 4500, 7000, 2500, 300, 3500, 12000,
            7500, 7500, 750, 2000, 3000, 4000, 2500, 6000, 15000, 25000, 5000, 3000,
            4500, 17500, 15000, 2500, 3000, 6000, 7000, 3000, 6500, 15000, 1000, 12500,
        };
        static const int kQlo[36] = {
            2, 2, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        };
        static const int kQhi[36] = {
            24, 16, 12, 0, 0, 0, 0, 0, 0, 20, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        };
        for (int i = 0; i < 36; ++i)
            if (mweapons.mwRowLo(i) != kLo[i] ||
                mweapons.mwRowHi(i) != kHi[i] ||
                mweapons.mwXpValue(i) != kXp[i] ||
                mweapons.mwSaleGp(i) != kGp[i] ||
                mweapons.mwQtyLo(i) != kQlo[i] ||
                mweapons.mwQtyHi(i) != kQhi[i])
                ++bad;
        for (int i = 1; i < 36; ++i)
            if (mweapons.mwRowLo(i) !=
                mweapons.mwRowHi(i - 1) + 1) ++bad;
        if (mweapons.mwRowLo(-5) != 1 ||
            mweapons.mwRowHi(99) != 100) ++bad;
        // the printed values: the Arrow of
        // Slaying, the Crossbow of Speed, the
        // Dagger of Venom, the Hammer of
        // Thunderbolts, the Mace of Disruption
        // and the Trident (Military Fork)
        if (mweapons.mwXpValue(3) != 250 ||
            mweapons.mwSaleGp(3) != 2500) ++bad;
        if (mweapons.mwXpValue(13) != 1500 ||
            mweapons.mwSaleGp(13) != 7500) ++bad;
        if (mweapons.mwXpValue(16) != 350 ||
            mweapons.mwSaleGp(16) != 3000) ++bad;
        if (mweapons.mwXpValue(21) != 2500 ||
            mweapons.mwSaleGp(21) != 25000) ++bad;
        if (mweapons.mwXpValue(25) != 1750 ||
            mweapons.mwSaleGp(25) != 17500) ++bad;
        if (mweapons.mwXpValue(35) != 1500 ||
            mweapons.mwSaleGp(35) != 12500) ++bad;
        // the FOUR ammo quantity ranges: the
        // three Arrows 2-24/2-16/2-12 and the
        // Bolt 2-20 (0/0 means a single item)
        if (mweapons.mwQtyLo(0) != 2 ||
            mweapons.mwQtyHi(0) != 24 ||
            mweapons.mwQtyLo(1) != 2 ||
            mweapons.mwQtyHi(1) != 16 ||
            mweapons.mwQtyLo(2) != 2 ||
            mweapons.mwQtyHi(2) != 12 ||
            mweapons.mwQtyLo(9) != 2 ||
            mweapons.mwQtyHi(9) != 20 ||
            mweapons.mwQtyRangeCount() != 4) ++bad;
        if (mweapons.mwQtyLo(5) != 0 ||
            mweapons.mwQtyHi(5) != 0 ||
            mweapons.mwQtyLo(35) != 0 ||
            mweapons.mwQtyHi(35) != 0) ++bad;
        // the TWO duplicate Hammer +2 rows: the
        // book prints the name twice with
        // different values (p.125)
        if (mweapons.mwXpValue(18) != 300 ||
            mweapons.mwSaleGp(18) != 2500 ||
            mweapons.mwXpValue(19) != 650 ||
            mweapons.mwSaleGp(19) != 6000 ||
            mweapons.mwDuplicateNameCount() != 2) ++bad;
        // the cursed Backbiter prints --- x.p.
        if (mweapons.mwXpValue(34) != 0 ||
            mweapons.mwSaleGp(34) != 1000 ||
            mweapons.mwNoXpCount() != 1) ++bad;
        // the Trident (Military Fork) rides the
        // 00 band - pinned as 100
        if (mweapons.mwRowLo(35) != 100 ||
            mweapons.mwRowHi(35) != 100) ++bad;
        // clamped reads land on the Arrow +1
        // below and the Trident above
        if (mweapons.mwSaleGp(-99) != 120 ||
            mweapons.mwSaleGp(99) != 12500 ||
            mweapons.mwQtyLo(-99) != 2 ||
            mweapons.mwQtyHi(99) != 0) ++bad;
        printf("R243 misc weapons pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
    #include "r244_iii_d_rods_explanation.h"  // R827: migrated
    #include "r245_iii_d_staves_explanation.h"  // R827: migrated
    #include "r246_wands_prose_pins.h"  // R828: migrated
    #include "r247_wands_prose_part_2_pins.h"  // R828: migrated
    #include "r248_wand_of_wonder_effect_ta.h"  // R828: migrated
    #include "r249_potions_prose_part_1_pin.h"  // R828: migrated
    #include "r250_potions_prose_part_2_pin.h"  // R828: migrated
    #include "r251_potions_prose_part_3_pin.h"  // R828: migrated
    #include "r252_scrolls_prose_pins.h"  // R828: migrated
    #include "r253_rings_prose_pins.h"  // R828: migrated
    #include "r254_rings_prose_part_2_pins.h"  // R828: migrated
    #include "r256_rings_prose_part_3_pins.h"  // R828: migrated
