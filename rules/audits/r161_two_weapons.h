    // ---- R161: attacks with two weapons audit --------
    // DMG p.70: the penalty ladder (primary -2, secondary
    // -4, eased above dex 15, never positive), the
    // dagger/hand-axe second-weapon gate, the no-parry
    // rule, the low-dex add-to-each rule, the discarded
    // shield.
    {
        Twoweapon twoweapon;
        int bad = 0;
        // the second-weapon gate
        if (!twoweapon.twoWeaponSecondaryAllowed("dagger") ||
            !twoweapon.twoWeaponSecondaryAllowed(
                "hand axe") ||
            twoweapon.twoWeaponSecondaryAllowed("long sword")
            || twoweapon.twoWeaponSecondaryAllowed("club") ||
            twoweapon.twoWeaponSecondaryAllowed("spear") ||
            twoweapon.twoWeaponSecondaryAllowed("")) ++bad;
        // the penalty ladder: dex 3 through 18
        static const int kDex[8] = { 3, 5, 6, 9, 15, 16, 17, 18 };
        static const int kPri[8] = { -2, -2, -2, -2, -2, -1, 0, 0 };
        static const int kSec[8] = { -4, -4, -4, -4, -4, -3, -2, -1 };
        for (int i = 0; i < 8; ++i) {
            Twoweapon twoweapon;
            if (twoweapon.twoWeaponPrimaryPenalty(
                    kDex[i]) != kPri[i]) ++bad;
            if (twoweapon.twoWeaponSecondaryPenalty(
                    kDex[i]) != kSec[i]) ++bad;
        }
        // never a positive rating, even at absurd dex
        if (twoweapon.twoWeaponPrimaryPenalty(20) != 0 ||
            twoweapon.twoWeaponPrimaryPenalty(25) != 0) ++bad;
        // the low-dex rule: dex below 6 adds to EACH
        if (!twoweapon.twoWeaponLowDexAddsToEach(3) ||
            !twoweapon.twoWeaponLowDexAddsToEach(5) ||
            twoweapon.twoWeaponLowDexAddsToEach(6) ||
            twoweapon.twoWeaponLowDexAddsToEach(9)) ++bad;
        // the secondary weapon never shields or parries
        if (twoweapon.twoWeaponSecondaryParries()) ++bad;
        // fighting two-handed discards the shield
        if (twoweapon.twoWeaponAllowsShield()) ++bad;
        printf("R161 two weapons audit: bad %d\n", bad);
        if (bad) return 1;
    }
