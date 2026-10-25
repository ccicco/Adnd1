    // ---- R243: the III.H misc weapons pins audit ----
    // DMG p.131-132: the miscellaneous weapons
    // table - the 36 rows, the ammo quantity
    // ranges and the duplicate Hammer +2 rows.
    {
        int bad = 0;
        // the row identity: the 36 die bands
        if (rules::mwRowCount() != 36) ++bad;
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
            if (rules::mwRowLo(i) != kLo[i] ||
                rules::mwRowHi(i) != kHi[i] ||
                rules::mwXpValue(i) != kXp[i] ||
                rules::mwSaleGp(i) != kGp[i] ||
                rules::mwQtyLo(i) != kQlo[i] ||
                rules::mwQtyHi(i) != kQhi[i])
                ++bad;
        for (int i = 1; i < 36; ++i)
            if (rules::mwRowLo(i) !=
                rules::mwRowHi(i - 1) + 1) ++bad;
        if (rules::mwRowLo(-5) != 1 ||
            rules::mwRowHi(99) != 100) ++bad;
        // the printed values: the Arrow of
        // Slaying, the Crossbow of Speed, the
        // Dagger of Venom, the Hammer of
        // Thunderbolts, the Mace of Disruption
        // and the Trident (Military Fork)
        if (rules::mwXpValue(3) != 250 ||
            rules::mwSaleGp(3) != 2500) ++bad;
        if (rules::mwXpValue(13) != 1500 ||
            rules::mwSaleGp(13) != 7500) ++bad;
        if (rules::mwXpValue(16) != 350 ||
            rules::mwSaleGp(16) != 3000) ++bad;
        if (rules::mwXpValue(21) != 2500 ||
            rules::mwSaleGp(21) != 25000) ++bad;
        if (rules::mwXpValue(25) != 1750 ||
            rules::mwSaleGp(25) != 17500) ++bad;
        if (rules::mwXpValue(35) != 1500 ||
            rules::mwSaleGp(35) != 12500) ++bad;
        // the FOUR ammo quantity ranges: the
        // three Arrows 2-24/2-16/2-12 and the
        // Bolt 2-20 (0/0 means a single item)
        if (rules::mwQtyLo(0) != 2 ||
            rules::mwQtyHi(0) != 24 ||
            rules::mwQtyLo(1) != 2 ||
            rules::mwQtyHi(1) != 16 ||
            rules::mwQtyLo(2) != 2 ||
            rules::mwQtyHi(2) != 12 ||
            rules::mwQtyLo(9) != 2 ||
            rules::mwQtyHi(9) != 20 ||
            rules::mwQtyRangeCount() != 4) ++bad;
        if (rules::mwQtyLo(5) != 0 ||
            rules::mwQtyHi(5) != 0 ||
            rules::mwQtyLo(35) != 0 ||
            rules::mwQtyHi(35) != 0) ++bad;
        // the TWO duplicate Hammer +2 rows: the
        // book prints the name twice with
        // different values (p.125)
        if (rules::mwXpValue(18) != 300 ||
            rules::mwSaleGp(18) != 2500 ||
            rules::mwXpValue(19) != 650 ||
            rules::mwSaleGp(19) != 6000 ||
            rules::mwDuplicateNameCount() != 2) ++bad;
        // the cursed Backbiter prints --- x.p.
        if (rules::mwXpValue(34) != 0 ||
            rules::mwSaleGp(34) != 1000 ||
            rules::mwNoXpCount() != 1) ++bad;
        // the Trident (Military Fork) rides the
        // 00 band - pinned as 100
        if (rules::mwRowLo(35) != 100 ||
            rules::mwRowHi(35) != 100) ++bad;
        // clamped reads land on the Arrow +1
        // below and the Trident above
        if (rules::mwSaleGp(-99) != 120 ||
            rules::mwSaleGp(99) != 12500 ||
            rules::mwQtyLo(-99) != 2 ||
            rules::mwQtyHi(99) != 0) ++bad;
        printf("R243 misc weapons pins audit: bad %d\n", bad);
        if (bad) return 1;
    }
    #include "rules/audits/r244_iii_d_rods_explanation.h"  // R827: migrated
    #include "rules/audits/r245_iii_d_staves_explanation.h"  // R827: migrated
    #include "rules/audits/r246_wands_prose_pins.h"  // R828: migrated
    #include "rules/audits/r247_wands_prose_part_2_pins.h"  // R828: migrated
    #include "rules/audits/r248_wand_of_wonder_effect_ta.h"  // R828: migrated
    #include "rules/audits/r249_potions_prose_part_1_pin.h"  // R828: migrated
    #include "rules/audits/r250_potions_prose_part_2_pin.h"  // R828: migrated
    #include "rules/audits/r251_potions_prose_part_3_pin.h"  // R828: migrated
    #include "rules/audits/r252_scrolls_prose_pins.h"  // R828: migrated
    #include "rules/audits/r253_rings_prose_pins.h"  // R828: migrated
    #include "rules/audits/r254_rings_prose_part_2_pins.h"  // R828: migrated
    #include "rules/audits/r256_rings_prose_part_3_pins.h"  // R828: migrated
