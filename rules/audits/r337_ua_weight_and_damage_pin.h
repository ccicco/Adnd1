    // ---- R337: the UA weight and damage pin audit ----
    // The UA WEIGHT AND DAMAGE BY WEAPON TYPE table (p. 26) -
    // the 68-row roster: all 50 PHB rows verified cell for
    // cell against the R189 chart seam (the hyphen-loss
    // pattern proven row by row), the 17 new-weapon rows
    // pinned where printed or pattern-decoded; the R392
    // clean PDF read fills every hole (the atlatl 30, the
    // harpoon 50-60, the falchion 60-80, the lasso dash)
    // and adds the 68th row (the hand-crossbow quarrels),
    // one misdecode reconciles (the garrot L 1-6) - the
    // item AMENDED, closes.
    {
        using namespace rules;
        int bad = 0;
        // U1: the counts and the roster anchors
        {
            if (uawtRowCount() != 68) ++bad;
            if (uawtSeamVerifiedCount() != 50) ++bad;
            if (uawtNewWeaponCount() != 18) ++bad;
            if (strcmp(uawtName(0), "Aklys") != 0)
                ++bad;
            if (strcmp(uawtName(66), "Whip") != 0)
                ++bad;
            if (strcmp(uawtName(67),
                "Quarrel (or Bolt), hand") != 0)
                ++bad;
            if (strcmp(uawtName(30), "Jo Stick")
                != 0) ++bad;
            if (strcmp(uawtName(47), "Sap") != 0)
                ++bad;
            if (strcmp(uawtName(53),
                "Spiked Buckler") != 0) ++bad;
        }
        // U2: the full 50-row R189 seam verification
        {
            for (int i = 0; i < uawtRowCount();
                 ++i) {
                int j = uawtPhbSeamIndex(i);
                if (j < 0) continue;
                if (uawtWeightMin(i)
                    != weaponChartWeight(j)) ++bad;
                if (uawtDamageSMMin(i)
                    != weaponChartDamageSMMin(j))
                    ++bad;
                if (uawtDamageSMMax(i)
                    != weaponChartDamageSMMax(j))
                    ++bad;
                if (uawtDamageLMin(i)
                    != weaponChartDamageLMin(j))
                    ++bad;
                if (uawtDamageLMax(i)
                    != weaponChartDamageLMax(j))
                    ++bad;
            }
        }
        // U3: the new-weapon rows, the pinned cells
        {
            // the blowgun: flat 1/1 as printed
            if (strcmp(uawtName(8),
                "Blowgun and needle") != 0) ++bad;
            if (uawtWeightMin(8) != 15) ++bad;
            if (uawtDamageSMMin(8) != 1) ++bad;
            if (uawtDamageSMMax(8) != 1) ++bad;
            if (uawtDamageLMin(8) != 1) ++bad;
            if (uawtDamageLMax(8) != 1) ++bad;
            // the garrot: 1 / 1-4 / 1-6 (the R392
            // clean read; the 1-8 was hyphen-loss)
            if (uawtWeightMin(19) != 1) ++bad;
            if (uawtDamageSMMin(19) != 1) ++bad;
            if (uawtDamageSMMax(19) != 4) ++bad;
            if (uawtDamageLMin(19) != 1) ++bad;
            if (uawtDamageLMax(19) != 6) ++bad;
            // the hook fauchard: 80 / 1-4 / 1-4
            if (uawtWeightMin(28) != 80) ++bad;
            if (uawtDamageSMMin(28) != 1) ++bad;
            if (uawtDamageSMMax(28) != 4) ++bad;
            if (uawtDamageLMin(28) != 1) ++bad;
            if (uawtDamageLMax(28) != 4) ++bad;
            // the knife: 6 / 1-3 / 1-2
            if (uawtWeightMin(31) != 6) ++bad;
            if (uawtDamageSMMax(31) != 3) ++bad;
            if (uawtDamageLMin(31) != 1) ++bad;
            if (uawtDamageLMax(31) != 2) ++bad;
            // the man catcher: 80 / 1-2 / 1-2
            if (uawtWeightMin(38) != 80) ++bad;
            if (uawtDamageSMMax(38) != 2) ++bad;
            if (uawtDamageLMax(38) != 2) ++bad;
            // the sap (attributed): 10 / 1-2 / 1-2
            if (uawtWeightMin(47) != 10) ++bad;
            if (uawtDamageSMMin(47) != 1) ++bad;
            if (uawtDamageSMMax(47) != 2) ++bad;
            if (uawtDamageLMin(47) != 1) ++bad;
            if (uawtDamageLMax(47) != 2) ++bad;
            // the spiked buckler: 35 / 1-4 / 1-3
            if (uawtWeightMin(53) != 35) ++bad;
            if (uawtDamageSMMax(53) != 4) ++bad;
            if (uawtDamageLMin(53) != 1) ++bad;
            if (uawtDamageLMax(53) != 3) ++bad;
            // the staff sling bullet: 5 / 2-8 / 3-9
            if (uawtWeightMin(55) != 5) ++bad;
            if (uawtDamageSMMin(55) != 2) ++bad;
            if (uawtDamageSMMax(55) != 8) ++bad;
            if (uawtDamageLMin(55) != 3) ++bad;
            if (uawtDamageLMax(55) != 9) ++bad;
            // the staff sling stone: 4 / 1-8 / 2-8
            if (uawtWeightMin(56) != 4) ++bad;
            if (uawtDamageSMMin(56) != 1) ++bad;
            if (uawtDamageSMMax(56) != 8) ++bad;
            if (uawtDamageLMin(56) != 2) ++bad;
            if (uawtDamageLMax(56) != 8) ++bad;
            // the khopesh: 75 / 2-8 / 1-6
            if (uawtWeightMin(60) != 75) ++bad;
            if (uawtDamageSMMin(60) != 2) ++bad;
            if (uawtDamageSMMax(60) != 8) ++bad;
            if (uawtDamageLMin(60) != 1) ++bad;
            if (uawtDamageLMax(60) != 6) ++bad;
            // the whip: 25-35 / 1-2 / flat 1
            if (uawtWeightMin(66) != 25) ++bad;
            if (uawtWeightMax(66) != 35) ++bad;
            if (uawtDamageSMMax(66) != 2) ++bad;
            if (uawtDamageLMin(66) != 1) ++bad;
            if (uawtDamageLMax(66) != 1) ++bad;
        }
        // U4: the aklys, the atlatl and the holes
        {
            // the aklys: 35 / 1-6 / 1-3 (the L
            // cell rides the continuation row)
            if (uawtWeightMin(0) != 35) ++bad;
            if (uawtDamageSMMin(0) != 1) ++bad;
            if (uawtDamageSMMax(0) != 6) ++bad;
            if (uawtDamageLMin(0) != 1) ++bad;
            if (uawtDamageLMax(0) != 3) ++bad;
            // the atlatl: weight 30,
            // damage 1-6 / 1-6
            if (uawtWeightMin(1) != 30) ++bad;
            if (uawtDamageSMMin(1) != 1) ++bad;
            if (uawtDamageSMMax(1) != 6) ++bad;
            if (uawtDamageLMin(1) != 1) ++bad;
            if (uawtDamageLMax(1) != 6) ++bad;
            // the harpoon weight 50-60, the
            // falchion weight 60-80 (the
            // R392 clean read)
            if (uawtWeightMin(25) != 50) ++bad;
            if (uawtWeightMin(59) != 60) ++bad;
            // the lasso: weight 20 pinned,
            // the damage cells print the dash
            // (0 damage, the R392 clean read)
            if (uawtWeightMin(35) != 20) ++bad;
            if (uawtDamageSMMin(35) != 0) ++bad;
            if (uawtDamageSMMax(35) != 0) ++bad;
            if (uawtDamageLMin(35) != 0) ++bad;
            if (uawtDamageLMax(35) != 0) ++bad;
        }
        // U5: the weight ranges and the
        // new-weapon flag agreement
        {
            // caltrop 2-4, spear 40-60,
            // whip 25-35; every other row
            // has max == min
            static const int rng[5][3] = {
                {10, 2, 4},
                {51, 40, 60},
                {66, 25, 35},
                {25, 50, 60},
                {59, 60, 80}
            };
            for (int r = 0; r < 5; ++r) {
                int i = rng[r][0];
                if (uawtWeightMin(i) != rng[r][1])
                    ++bad;
                if (uawtWeightMax(i) != rng[r][2])
                    ++bad;
            }
            for (int i = 0; i < 68; ++i) {
                if (uawtWeightMin(i) < 0) continue;
                bool ranged = i == 10 || i == 51
                    || i == 66 || i == 25
                    || i == 59;
                if (uawtWeightMax(i)
                    != uawtWeightMin(i) && !ranged)
                    ++bad;
            }
            int newc = 0;
            for (int i = 0; i < 68; ++i) {
                if (uawtIsNewWeapon(i)) ++newc;
                if (uawtIsNewWeapon(i)
                    != (uawtPhbSeamIndex(i) < 0))
                    ++bad;
            }
            if (newc != 18) ++bad;
        }
        // U6: the R189 seam census
        {
            if (weaponChartRowCount() != 50) ++bad;
        }
        printf("R337 UA weight and damage pin audit: bad %d\n", bad);
        if (bad) return 1;
    }
