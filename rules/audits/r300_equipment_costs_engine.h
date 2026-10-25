    // ---- R300: the equipment costs engine audit ----
    // The items costGp column repinned to the printed tables
    // (rules/equipcosts.h): every engine weapon and armor id
    // maps to its printed row - the printed-table-wins debt
    // paid. The recorded conventions: the quarterstaff and
    // club are not in the print (0 stays the engine
    // convention), the sling keeps the 2 g.p. engine price
    // (the print prices the dozen sling and bullets bundle,
    // 15 s.p.), the generic mace and flail read the footman
    // rows and the unsold armor None reads 0. The shield
    // file-static 10 g.p. equals the print Shield, small row
    // (no accessor - recorded, not audited).
    {
        int bad = 0;
        // the printed arms row each engine weapon reads
        // (-1 = not in the print, 0 stays; -2 = the sling
        // bundle convention, the engine keeps 2 g.p.)
        static const int kRow[15] = {
            14, 4, 48, 47, 3, 30, 18, 32, 43, -1,
            -1, 11, 10, 13, -2,
        };
        for (int i = 0; i < 15; ++i) {
            int want = 0;
            if (kRow[i] >= 0)
                want = rules::eqcArmsGold(kRow[i]);
            if (kRow[i] == -2)
                want = 2;
            if (items::weapon((items::WeaponId)i).costGp != want)
                ++bad;
        }
        // the printed armor row each engine armor id reads
        // (-1 = the unsold None row, 0)
        static const int kArow[10] = {
            -1, 5, 4, 13, 7, 8, 1, 12, 0, 6,
        };
        for (int i = 0; i < 10; ++i) {
            int want = 0;
            if (kArow[i] >= 0)
                want = rules::eqcArmorGold(kArow[i]);
            if (items::armor((items::ArmorId)i).costGp != want)
                ++bad;
        }
        // the repinned rows, spot-checked against the print
        if (items::weapon(items::WPN_HAND_AXE).costGp != 1 ||
            items::weapon(items::WPN_BATTLE_AXE).costGp != 5 ||
            items::weapon(items::WPN_FLAIL).costGp != 3 ||
            items::weapon(items::WPN_MORNING_STAR).costGp != 5 ||
            items::weapon(items::WPN_SPEAR).costGp != 1 ||
            items::weapon(items::WPN_SHORT_BOW).costGp != 15 ||
            items::weapon(items::WPN_LONG_BOW).costGp != 60 ||
            items::weapon(items::WPN_CROSSBOW_LIGHT).costGp != 12 ||
            items::armor(items::ARMOR_SCALE_MAIL).costGp != 45)
            ++bad;
        // the kept rows: the print already agreed (dagger 2,
        // short sword 8, long sword 15, mace 8, padded 4,
        // leather 5, studded 15, ring 30, chain 75, splinted
        // 80, banded 90, plate 400)
        if (items::weapon(items::WPN_DAGGER).costGp != 2 ||
            items::weapon(items::WPN_SHORT_SWORD).costGp != 8 ||
            items::weapon(items::WPN_LONG_SWORD).costGp != 15 ||
            items::weapon(items::WPN_MACE).costGp != 8 ||
            items::armor(items::ARMOR_PADDED).costGp != 4 ||
            items::armor(items::ARMOR_LEATHER).costGp != 5 ||
            items::armor(items::ARMOR_STUDDED_LEATHER).costGp != 15 ||
            items::armor(items::ARMOR_RING_MAIL).costGp != 30 ||
            items::armor(items::ARMOR_CHAIN_MAIL).costGp != 75 ||
            items::armor(items::ARMOR_SPLINTED).costGp != 80 ||
            items::armor(items::ARMOR_BANDED).costGp != 90 ||
            items::armor(items::ARMOR_PLATE).costGp != 400)
            ++bad;
        // the recorded conventions: the quarterstaff and
        // club (not in the print), the sling (the bundle
        // print, the 2 g.p. engine price) and the unsold
        // armor None
        if (items::weapon(items::WPN_QUARTERSTAFF).costGp != 0 ||
            items::weapon(items::WPN_CLUB).costGp != 0 ||
            items::weapon(items::WPN_SLING).costGp != 2 ||
            items::armor(items::ARMOR_NONE_EQUIPPED).costGp != 0)
            ++bad;
        printf("R300 equipment costs engine audit: bad %d\n", bad);
        if (bad) return 1;
    }
