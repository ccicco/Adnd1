    // ---- R161: attacks with two weapons audit --------
    // DMG p.70: the penalty ladder (primary -2, secondary
    // -4, eased above dex 15, never positive), the
    // dagger/hand-axe second-weapon gate, the no-parry
    // rule, the low-dex add-to-each rule, the discarded
    // shield.
    {
        int bad = 0;
        // the second-weapon gate
        if (!rules::twoWeaponSecondaryAllowed("dagger") ||
            !rules::twoWeaponSecondaryAllowed(
                "hand axe") ||
            rules::twoWeaponSecondaryAllowed("long sword")
            || rules::twoWeaponSecondaryAllowed("club") ||
            rules::twoWeaponSecondaryAllowed("spear") ||
            rules::twoWeaponSecondaryAllowed("")) ++bad;
        // the penalty ladder: dex 3 through 18
        static const int kDex[8] = { 3, 5, 6, 9, 15, 16, 17, 18 };
        static const int kPri[8] = { -2, -2, -2, -2, -2, -1, 0, 0 };
        static const int kSec[8] = { -4, -4, -4, -4, -4, -3, -2, -1 };
        for (int i = 0; i < 8; ++i) {
            if (rules::twoWeaponPrimaryPenalty(
                    kDex[i]) != kPri[i]) ++bad;
            if (rules::twoWeaponSecondaryPenalty(
                    kDex[i]) != kSec[i]) ++bad;
        }
        // never a positive rating, even at absurd dex
        if (rules::twoWeaponPrimaryPenalty(20) != 0 ||
            rules::twoWeaponPrimaryPenalty(25) != 0) ++bad;
        // the low-dex rule: dex below 6 adds to EACH
        if (!rules::twoWeaponLowDexAddsToEach(3) ||
            !rules::twoWeaponLowDexAddsToEach(5) ||
            rules::twoWeaponLowDexAddsToEach(6) ||
            rules::twoWeaponLowDexAddsToEach(9)) ++bad;
        // the secondary weapon never shields or parries
        if (rules::twoWeaponSecondaryParries()) ++bad;
        // fighting two-handed discards the shield
        if (rules::twoWeaponAllowsShield()) ++bad;
        printf("R161 two weapons audit: bad %d\n", bad);
        if (bad) return 1;
    }
