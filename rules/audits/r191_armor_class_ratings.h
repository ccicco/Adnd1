    // ---- R191: the armor class ratings audit ----
    // The engine armor rows against the printed ARMOR
    // CLASS TABLE, the effectiveAc composites, the
    // new ratings ladder.
    {
        int bad = 0;
        // the printed ladder rows (the shield
        // composites are base - 1)
        if (rules::armorRatingRowCount() != 11) ++bad;
        static const int kLad[11] = {
            10, 9, 8, 8, 7, 7, 6, 5, 4, 4, 3
        };
        for (int i = 0; i < 11; ++i) {
            if (rules::armorRatingAc(i) != kLad[i]) ++bad;
        }
        if (std::string(rules::armorRatingName(0))
            != "none") ++bad;
        if (std::string(rules::armorRatingName(10))
            != "plate mail") ++bad;
        if (rules::armorRatingShieldStep() != 1) ++bad;
        // the engine armor rows vs the print:
        // none 10, padded 8, leather 8, studded 7,
        // ring 7, scale 6, chain 5, splinted 4,
        // banded 4, plate 3 (the none row repinned
        // R191: was 9)
        static const int kBase[10] = {
            10, 8, 8, 7, 7, 6, 5, 4, 4, 3
        };
        for (int i = 0; i < 10; ++i) {
            if (items::armor((items::ArmorId)i).baseAc
                != kBase[i]) ++bad;
        }
        // the effectiveAc composites:
        items::ArmorInstance ar{};
        // unarmored, DEX 10: the printed 10
        ar.id = items::ARMOR_NONE_EQUIPPED;
        if (items::effectiveAc(ar, false, 0, 10) != 10) ++bad;
        // shield only: the printed 9
        if (items::effectiveAc(ar, true, 0, 10) != 9) ++bad;
        // leather: the printed 8; with shield 7
        ar.id = items::ARMOR_LEATHER;
        if (items::effectiveAc(ar, false, 0, 10) != 8) ++bad;
        if (items::effectiveAc(ar, true, 0, 10) != 7) ++bad;
        // plate mail + shield, DEX 10: the printed 2
        ar.id = items::ARMOR_PLATE;
        if (items::effectiveAc(ar, true, 0, 10) != 2) ++bad;
        // the DEX worked example (the ability text):
        // plate + shield normally AC 2; DEX 3 -> 6;
        // DEX 18 -> -2
        if (items::effectiveAc(ar, true, 0, 3) != 6) ++bad;
        if (items::effectiveAc(ar, true, 0, 18) != -2) ++bad;
        // the magic-shield example: unarmored with
        // a +1 shield is AC 8, +2 shield AC 7
        ar.id = items::ARMOR_NONE_EQUIPPED;
        if (items::effectiveAc(ar, true, 1, 10) != 8) ++bad;
        if (items::effectiveAc(ar, true, 2, 10) != 7) ++bad;
        // the magic plate example: plate +3 armor,
        // +5 shield -> AC -6 (3 - 3 - 1 - 5)
        ar.id = items::ARMOR_PLATE;
        ar.plus = 3;
        if (items::effectiveAc(ar, true, 5, 10) != -6) ++bad;
        ar.plus = 0;
        // the magic rule: each +1 lowers AC 1 and
        // converts to 5% hit likelihood
        if (rules::armorRatingMagicAc(1) != 1) ++bad;
        if (rules::armorRatingMagicAc(3) != 3) ++bad;
        if (rules::armorRatingMagicHitPct(1) != 5) ++bad;
        if (rules::armorRatingMagicHitPct(2) != 10) ++bad;
        if (rules::armorRatingMagicAc(-2) != 0) ++bad;
        // the printed notes
        if (!rules::armorRatingShieldNegatedFlankRear()) ++bad;
        if (!rules::armorRatingMagicWeightless()) ++bad;
        printf("R191 armor class ratings audit: bad %d\n", bad);
        if (bad) return 1;
    }
