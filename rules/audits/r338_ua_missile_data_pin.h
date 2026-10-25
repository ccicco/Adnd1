    // ---- R338: the UA missile data pin audit ----
    // The UA HURLED WEAPON AND MISSILE TYPES table
    // (p. 28) - the 24-row roster: the range column
    // (the long range in tens of feet, PHB-seam
    // verified), the AC-adjustment ladders minus-loss
    // decoded (the pattern seam-proven on the bow,
    // crossbow and sling rows against the R145
    // engine rows); the R392 clean PDF read fills
    // the rate column, the S/M/L range strings and
    // every lost AC cell, and adds the AC 7..10
    // columns - the item AMENDED, closes.
    {
        using namespace rules;
        int bad = 0;
        // U1: the counts and the roster
        {
            if (uamtRowCount() != 24) ++bad;
            if (uamtNewWeaponCount() != 8) ++bad;
            if (uamtStandardWeaponCount() != 16)
                ++bad;
            if (strcmp(uamtName(0),
                "Aklys (hurled)") != 0) ++bad;
            if (strcmp(uamtName(1),
                "Atlatl (javelin)") != 0) ++bad;
            if (strcmp(uamtName(6), "Bow, Long")
                != 0) ++bad;
            if (strcmp(uamtName(23),
                "Staff Sling (stone)") != 0) ++bad;
            if (!uamtIsNewWeapon(0)) ++bad;
            if (!uamtIsNewWeapon(18)) ++bad;
            if (uamtIsNewWeapon(2)) ++bad;
            if (uamtIsNewWeapon(11)) ++bad;
            int newc = 0;
            for (int i = 0; i < 24; ++i)
                if (uamtIsNewWeapon(i)) ++newc;
            if (newc != 8) ++bad;
        }
        // U2: the range column (the long range in
        // tens of feet; the PHB seams)
        {
            // short bow 150, long bow 210,
            // light crossbow 180, sling stone 160,
            // javelin 60, hand crossbow 60
            if (uamtRangePrinted(7) != 15) ++bad;
            if (uamtRangePrinted(6) != 21) ++bad;
            if (uamtRangePrinted(11) != 18) ++bad;
            if (uamtRangePrinted(20) != 16) ++bad;
            if (uamtRangePrinted(16) != 6) ++bad;
            if (uamtRangePrinted(9) != 6) ++bad;
            // the composites, the heavy crossbow
            if (uamtRangePrinted(4) != 21) ++bad;
            if (uamtRangePrinted(5) != 18) ++bad;
            if (uamtRangePrinted(10) != 24) ++bad;
            // the hurled threes, the staff slings
            if (uamtRangePrinted(2) != 3) ++bad;
            if (uamtRangePrinted(12) != 3) ++bad;
            if (uamtRangePrinted(22) != 9) ++bad;
            if (uamtRangePrinted(23) != 9) ++bad;
            if (uamtRangePrinted(19) != 20) ++bad;
            // the holes: the aklys, the dart
            if (uamtRangePrinted(0) != -1) ++bad;
            if (uamtRangePrinted(13) != -1) ++bad;
        }
        // U3: the AC ladders, the pinned cells
        {
            // the aklys: -8 through -2
            for (int ac = 0; ac < 7; ++ac)
                if (uamtAcAdjustment(0, ac)
                    != -8 + ac) ++bad;
            // the blowgun: the even ladder -14..-2
            for (int ac = 0; ac < 7; ++ac)
                if (uamtAcAdjustment(3, ac)
                    != -14 + 2 * ac) ++bad;
            // the dagger and the dart: -7..-1
            for (int ac = 0; ac < 7; ++ac) {
                if (uamtAcAdjustment(12, ac)
                    != -7 + ac) ++bad;
                if (uamtAcAdjustment(13, ac)
                    != -7 + ac) ++bad;
            }
            // the composites (the signed rows)
            if (uamtAcAdjustment(5, 0) != -4) ++bad;
            if (uamtAcAdjustment(5, 1) != -4) ++bad;
            if (uamtAcAdjustment(5, 2) != -3) ++bad;
            if (uamtAcAdjustment(5, 3) != -3) ++bad;
            if (uamtAcAdjustment(5, 4) != -1) ++bad;
            if (uamtAcAdjustment(5, 6) != 1) ++bad;
            if (uamtAcAdjustment(4, 2) != -2) ++bad;
            if (uamtAcAdjustment(4, 6) != 1) ++bad;
            // the lasso: +9, +8, +7
            if (uamtAcAdjustment(18, 0) != 9) ++bad;
            if (uamtAcAdjustment(18, 1) != 8) ++bad;
            if (uamtAcAdjustment(18, 2) != 7) ++bad;
            // the heavy crossbow: -2, hole, -1..+3
            if (uamtAcAdjustment(10, 0) != -2)
                ++bad;
            if (uamtAcAdjustment(10, 2) != -1) ++bad;
            if (uamtAcAdjustment(10, 6) != 3) ++bad;
            // the spear, the staff slings
            if (uamtAcAdjustment(21, 0) != -4) ++bad;
            if (uamtAcAdjustment(21, 1) != -4) ++bad;
            if (uamtAcAdjustment(21, 2) != -3) ++bad;
            if (uamtAcAdjustment(22, 0) != -5) ++bad;
            if (uamtAcAdjustment(23, 0) != -6) ++bad;
            // the hand crossbow, the club,
            // the hammer, the atlatl
            if (uamtAcAdjustment(9, 0) != -6) ++bad;
            if (uamtAcAdjustment(9, 2) != -2) ++bad;
            if (uamtAcAdjustment(8, 0) != -9) ++bad;
            if (uamtAcAdjustment(8, 6) != -1) ++bad;
            if (uamtAcAdjustment(14, 1) != -3) ++bad;
            if (uamtAcAdjustment(1, 0) != -6) ++bad;
            if (uamtAcAdjustment(1, 4) != -2) ++bad;
        }
        // U4: the recovered cells (the R392 clean
        // read; every 100 sentinel fills)
        {
            if (uamtAcAdjustment(0, 0) == 100) ++bad;
            if (uamtAcAdjustment(8, 2) != -7) ++bad;
            if (uamtAcAdjustment(14, 0) != -4) ++bad;
            if (uamtAcAdjustment(14, 5) != 0) ++bad;
            if (uamtAcAdjustment(1, 5) != -1) ++bad;
            if (uamtAcAdjustment(1, 6) != 0) ++bad;
            if (uamtAcAdjustment(9, 6) != 0) ++bad;
            if (uamtAcAdjustment(10, 1) != -1) ++bad;
            if (uamtAcAdjustment(11, 6) != 1) ++bad;
            if (uamtAcAdjustment(20, 0) != -7) ++bad;
            if (uamtAcAdjustment(6, 4) != 0) ++bad;
            if (uamtAcAdjustment(6, 5) != 1) ++bad;
            if (uamtAcAdjustment(6, 6) != 2) ++bad;
            // the recovered census: every one of the
            // 24 x 7 cells pins (no sentinel remains)
            int pinned = 0;
            for (int i = 0; i < 24; ++i)
                for (int ac = 0; ac < 7; ++ac)
                    if (uamtAcAdjustment(i, ac)
                        != 100) ++pinned;
            if (pinned != 168) ++bad;
            // the rate column and the S/M/L ranges
            // (the printed strings)
            if (strcmp(uamtRateOfFire(0), "1") != 0)
                ++bad;
            if (strcmp(uamtRateOfFire(10), "1/2")
                != 0) ++bad;
            if (strcmp(uamtRateOfFire(13), "3")
                != 0) ++bad;
            if (strcmp(uamtRangeShort(0), "1*")
                != 0) ++bad;
            if (uamtRangeShort(22)[0] != '-') ++bad;
            if (strcmp(uamtRangeMedium(22), "3-6")
                != 0) ++bad;
            if (strcmp(uamtRangeLong(1), "9") != 0)
                ++bad;
            if (strcmp(uamtRangeShort(13),
                "1 1/2") != 0) ++bad;
            if (strcmp(uamtRangeLong(13),
                "4 1/2") != 0) ++bad;
            if (!uamtAklysTenFootOnly()) ++bad;
            // the AC 7..10 columns (the R392
            // accessor)
            if (uamtAcAdjustmentHigh(18, 0) != 2)
                ++bad;
            if (uamtAcAdjustmentHigh(18, 3) != -1)
                ++bad;
            if (uamtAcAdjustmentHigh(0, 0) != -1)
                ++bad;
            if (uamtAcAdjustmentHigh(0, 3) != 0)
                ++bad;
            if (uamtAcAdjustmentHigh(3, 0) != -1)
                ++bad;
            if (uamtAcAdjustmentHigh(3, 1) != -1)
                ++bad;
            if (uamtAcAdjustmentHigh(3, 2) != 1) ++bad;
            if (uamtAcAdjustmentHigh(3, 3) != 2) ++bad;
        }
        // U5: the prose notes and the R116 seam
        {
            if (!uamtRateOfFireTurnOrRound()) ++bad;
            if (!uamtAcAdjustmentAtShortRange())
                ++bad;
            if (uamtMediumRangeAdjustment() != -2)
                ++bad;
            if (uamtLongRangeAdjustment() != -5)
                ++bad;
            // the R116 engine seam: -2 at medium,
            // -5 at long (the sling's 40' short)
            if (missileRangeMod(60, 40) != -2) ++bad;
            if (missileRangeMod(100, 40) != -5)
                ++bad;
        }
        // U6: the R145 engine seam - the minus-loss
        // decode proven on the standard rows
        {
            // the bow short: the PHB row, printed
            // <7,6,5,-4,-1,0,0 in the extract
            for (int ac = 0; ac < 7; ++ac)
                if (uamtAcAdjustment(7, ac)
                    != items::weapon(
                        items::WPN_SHORT_BOW)
                        .acAdj[ac]) ++bad;
            // the bow long: the first four cells
            for (int ac = 0; ac < 4; ++ac)
                if (uamtAcAdjustment(6, ac)
                    != items::weapon(
                        items::WPN_LONG_BOW)
                        .acAdj[ac]) ++bad;
            // the light crossbow: six of six
            // printed cells
            for (int ac = 0; ac < 6; ++ac)
                if (uamtAcAdjustment(11, ac)
                    != items::weapon(
                        items::WPN_CROSSBOW_LIGHT)
                        .acAdj[ac]) ++bad;
            // the sling bullet: three of three
            for (int ac = 0; ac < 3; ++ac)
                if (uamtAcAdjustment(19, ac)
                    != items::weapon(
                        items::WPN_SLING)
                        .acAdj[ac]) ++bad;
        }
        // U7: the R337 seam - the new-weapon
        // roster agreement
        {
            if (strcmp(uawtName(0), "Aklys")
                != 0) ++bad;
            if (!uawtIsNewWeapon(0)) ++bad;
            if (strcmp(uawtName(53),
                "Spiked Buckler") != 0) ++bad;
        }
        printf("R338 UA missile data pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
