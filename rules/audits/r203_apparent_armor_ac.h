    // ---- R203: the apparent armor AC audit ----
    // The p.38 column key repin: the row keys the armor
    // worn - base + shield - never the magic/DEX-shifted
    // effective AC. The book: the adjustments are for
    // weapons versus specific types of armor, not
    // necessarily against actual armor class.
    {
        int bad = 0;
        // the apparent armor AC cells: armor base + shield
        {
            items::ArmorInstance ar;
            ar.id = items::ARMOR_NONE_EQUIPPED;
            if (items::apparentArmorAc(ar, false) != 10) ++bad;
            // the shield column: the book prints shield
            // only as AC 9
            if (items::apparentArmorAc(ar, true) != 9) ++bad;
            ar.id = items::ARMOR_LEATHER;
            if (items::apparentArmorAc(ar, false) != 8) ++bad;
            if (items::apparentArmorAc(ar, true) != 7) ++bad;
            ar.id = items::ARMOR_PLATE;
            if (items::apparentArmorAc(ar, false) != 3) ++bad;
            if (items::apparentArmorAc(ar, true) != 2) ++bad;
        }
        // the enchantment plus does NOT shift the key
        {
            items::ArmorInstance ar;
            ar.id = items::ARMOR_PLATE;
            ar.plus = 5;
            if (items::apparentArmorAc(ar, false) != 3) ++bad;
        }
        // the contrast: DEX and plus shift the effective AC,
        // never the apparent - a plate +2, shield, DEX 18
        // defender reads effective -4, apparent 2
        {
            items::ArmorInstance ar;
            ar.id = items::ARMOR_PLATE;
            ar.plus = 2;
            rules::ExceptionalStrength noEx;
            int eff = items::effectiveAc(ar, true, 0, 18);
            int app = items::apparentArmorAc(ar, true);
            if (eff != -4) ++bad;   // the to-hit target
            if (app != 2) ++bad;    // the p.38 row key
            // the dagger row keyed each way: the old fold
            // read column 0 (-4); the repin reads column 2
            // (-3) - the fix, pinned as two exact values
            if (items::weaponAcAdjustment(
                    items::WPN_DAGGER, eff) != -4) ++bad;
            if (items::weaponAcAdjustment(
                    items::WPN_DAGGER, app) != -3) ++bad;
            // the composition chain: STR 10 neutral, no
            // enchant, dagger vs the plate-and-shield
            // defender - the row reads the armor, -3
            items::WeaponInstance w;
            w.id = items::WPN_DAGGER;
            if (items::attackAdjustment(w, noEx, 10, app) != -3)
                ++bad;
            // and keyed on the effective AC it would read
            // -4 - the retired approximation, pinned
            if (items::attackAdjustment(w, noEx, 10, eff) != -4)
                ++bad;
        }
        // the shield-only column: dagger vs AC 9 reads +1
        {
            items::ArmorInstance ar;
            ar.id = items::ARMOR_NONE_EQUIPPED;
            int app = items::apparentArmorAc(ar, true);
            if (app != 9) ++bad;
            if (items::weaponAcAdjustment(
                    items::WPN_DAGGER, app) != 1) ++bad;
        }
        printf("R203 apparent armor AC audit: bad %d\n", bad);
        if (bad) return 1;
    }
