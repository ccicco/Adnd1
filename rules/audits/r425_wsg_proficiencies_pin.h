    // ---- R425: the WSG
    // proficiencies pin
    // audit ----
    // The wilderness arc
    // opener pins the WSG
    // proficiency system
    // (rules/wsgprof.h,
    // prefix wsg): the
    // Proficiency Check
    // system (1d20 vs the
    // Appropriate Ability,
    // the unmodified 19/20
    // auto-fail, the 18
    // cap, the 2-in-20
    // floor), the improving
    // rule (a cumulative -2
    // per extra slot, from
    // 3rd level; an improved
    // 19 succeeds, a
    // natural 20 always
    // fails), the slot rules
    // (a weapon slot may
    // hold a nonweapon
    // proficiency, never the
    // reverse) and the
    // expanding optional rule
    // (one extra nonweapon
    // slot at 1st level, all
    // slots filled right
    // away - a delayed slot
    // is lost); Table 1 (the
    // 14 class rows, the
    // bard "as other classes"
    // sentinel, the horseman
    // footnote) and Table 2
    // (the 25 rows) pin with
    // the censuses verified
    // and the denominator
    // arithmetic - the book
    // own cleric and
    // illusionist examples;
    // census 350 -> 351.
    {
        using namespace rules;
        int bad = 0;
        if (!wsgCheckRolls1d20()
                || wsgCheckDieSides() != 20
                || wsgCheckAutoFail() != 19
                || wsgAbilityCap()
                != 18
                || wsgCheckFloorIn20() != 2
                || !wsgImproved19Succeeds()
                || !wsgNatural20Fails()
                || wsgImprovingStep()
                != -2
                || wsgImprovingMinLevel() != 3)
            ++bad;
        if (!wsgWeaponSlotHoldsNonweapon()
                || wsgNonweaponSlotHoldsWeapon()
                || !wsgExpandingBonusSlots()
                || !wsgExpandingFirstLevelOnly()
                || !wsgExpandingDelayedIsLost()
                || wsgHorsemanZeroLevelSlots() != 1
                || wsgHorsemanSecondSlotLevel() != 1
                || !wsgBardAsOtherClasses()
                || wsgClassCount()
                != 14
                || wsgProfCount()
                != 25)
            ++bad;
        int d2 = 0, d3 = 0, d4 = 0,
            d5 = 0, d6 = 0;
        for (int c = 0;
             c < wsgClassCount();
             ++c) {
            int d =
                wsgAddEveryLevels(c);
            if (d == 2) ++d2;
            else if (d == 3) ++d3;
            else if (d == 4) ++d4;
            else if (d == 5) ++d5;
            else if (d == 6) ++d6;
            else ++bad;
            if (wsgAddWeaponSlots(c) != 1)
                ++bad;
        }
        if (d2 != 4 || d3 != 2
                || d4 != 5 || d5 != 1
                || d6 != 2)
            ++bad;
        if (wsgInitialWeaponSlots(0) != 3
                || wsgInitialNonweaponSlots(0)
                != 2
                || wsgInitialWeaponSlots(4) != 4
                || wsgInitialWeaponSlots(5) != 6
                || wsgInitialNonweaponSlots(5)
                != 3
                || wsgInitialWeaponSlots(7) != 1
                || wsgAddNonweaponSlots(7) != 2
                || wsgInitialWeaponSlots(12) != 1
                || wsgInitialNonweaponSlots(12)
                != 1
                || wsgInitialWeaponSlots(13) != -1
                || wsgInitialNonweaponSlots(13)
                != -1
                || wsgAddEveryLevels(13) != 4)
            ++bad;
        if (wsgAddEveryLevels(2)
                + 1 != 5
                || wsgAddEveryLevels(7) + 1 != 7
                || wsgAddEveryLevels(2) * 2 + 1
                != 9
                || wsgAddEveryLevels(7) * 2 + 1
                != 13)
            ++bad;
        int n1 = 0, n2 = 0, ssum = 0,
            aw = 0, ain = 0, adx = 0,
            acon = 0, astr = 0, ana = 0,
            p1 = 0, p2 = 0, z0 = 0,
            m1 = 0, m2 = 0, m3 = 0, na = 0;
        for (int p = 0;
             p < wsgProfCount();
             ++p) {
            if (wsgSlots(p) == 1)
                ++n1;
            else if (wsgSlots(p)
                     == 2)
                ++n2;
            else ++bad;
            ssum += wsgSlots(p);
            int a = wsgAbility(p);
            if (a == 1) ++aw;
            else if (a == 2) ++ain;
            else if (a == 3) ++adx;
            else if (a == 4) ++acon;
            else if (a == 5) ++astr;
            else if (a != 0)
                ++bad;
            else ++ana;
            int m = wsgModifier(p);
            if (m == 1) ++p1;
            else if (m == 2) ++p2;
            else if (m == 0) ++z0;
            else if (m == -1) ++m1;
            else if (m == -2) ++m2;
            else if (m == -3) ++m3;
            else if (m != 99)
                ++bad;
            else ++na;
            if (wsgProfNeverChecks(p)
                    != (wsgAbility(p)
                        == 0)
                    || wsgProfNeverChecks(p)
                    != (wsgModifier(p)
                        == 99))
                ++bad;
        }
        if (n1 != 20 || n2 != 5
                || ssum != 30
                || aw != 11
                || ain != 3
                || adx != 2
                || acon != 1
                || astr != 1
                || ana != 7
                || p1 != 5 || p2 != 2
                || z0 != 5
                || m1 != 3
                || m2 != 2
                || m3 != 1
                || na != 7)
            ++bad;
        if (wsgSingleSlotProfs()
                != n1
                || wsgDoubleSlotProfs() != n2
                || wsgWisdomProfs()
                != aw
                || wsgNeverCheckProfs() != na
                || wsgHardestModifier() != -3)
            ++bad;
        printf("R425 WSG proficiencies pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
