    // ==== R1055: subgates registry ===========
    // The R1055 de-wire: the 14
    // static arrays of rules/phb/
    // subclassgates.h ride
    // items::MiscItemRegistry from
    // content/tables/ph_subgates/ - 3
    // defs, 12 named tables; the R230
    // flat copies kAllow/kCap retire
    // ONTO the race tables - the
    // dedupe. Seven sections: load,
    // counts, qualify, race,
    // leveling, seam, edges. Census
    // 1089 -> 1096. DO NOT hand-edit:
    // tools/r1055_splice.py is the only
    // writer.
    {
        int bad = 0;
        // -- 1. load ---------------------------------
        {
            items::MiscItemRegistry reg;
            int n = reg.loadDirectory(
                "content/tables/ph_subgates");
            if (n != 3) ++bad;
            if (!reg.errors().empty()) ++bad;
            for (const auto& kv : reg.all())
                if ((int)kv.second.sources.size() != 1
                    || kv.second.sources[0].second != 1055)
                    ++bad;
            if (!reg.find("ph_subgates_qualify")) ++bad;
            if (!reg.find("ph_subgates_race")) ++bad;
            if (!reg.find("ph_subgates_leveling")) ++bad;
        }
        printf("R1055 subgates registry load audit: bad %d\\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 2. counts --------------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/ph_subgates");
            {
                const items::MiscItemDef* d =
                    reg.find("ph_subgates_qualify");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 6
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ph_subgates_qualifyRowCount"
                        || d->pins[0].value != 6
                        || (int)d->tables.size() != 3)
                        ++bad;
                    if (d->tables[0].name
                        != "ability_min"
                        || (int)d->tables[0]
                            .values.size() != 36)
                        ++bad;
                    if (d->tables[1].name
                        != "align_req"
                        || (int)d->tables[1]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[2].name
                        != "xp_bonus"
                        || (int)d->tables[2]
                            .values.size() != 6)
                        ++bad;
                    if (d->rows[0].set
                        != "ph_subgates_qualify"
                        || d->rows[0].bandLo != 0
                        || d->rows[0].bandHi != 0)
                        ++bad;
                    if (d->rows[1].set
                        != "ph_subgates_qualify"
                        || d->rows[1].bandLo != 1
                        || d->rows[1].bandHi != 1)
                        ++bad;
                    if (d->rows[2].set
                        != "ph_subgates_qualify"
                        || d->rows[2].bandLo != 2
                        || d->rows[2].bandHi != 2)
                        ++bad;
                    if (d->rows[3].set
                        != "ph_subgates_qualify"
                        || d->rows[3].bandLo != 3
                        || d->rows[3].bandHi != 3)
                        ++bad;
                    if (d->rows[4].set
                        != "ph_subgates_qualify"
                        || d->rows[4].bandLo != 4
                        || d->rows[4].bandHi != 4)
                        ++bad;
                    if (d->rows[5].set
                        != "ph_subgates_qualify"
                        || d->rows[5].bandLo != 5
                        || d->rows[5].bandHi != 5)
                        ++bad;
                if (std::string(
                    d->rows[0].name)
                    != "paladin")
                    ++bad;
                if (std::string(
                    d->rows[1].name)
                    != "ranger")
                    ++bad;
                if (std::string(
                    d->rows[2].name)
                    != "druid")
                    ++bad;
                if (std::string(
                    d->rows[3].name)
                    != "illusionist")
                    ++bad;
                if (std::string(
                    d->rows[4].name)
                    != "assassin")
                    ++bad;
                if (std::string(
                    d->rows[5].name)
                    != "monk")
                    ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ph_subgates_race");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 6
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ph_subgates_raceRowCount"
                        || d->pins[0].value != 6
                        || (int)d->tables.size() != 2)
                        ++bad;
                    if (d->tables[0].name
                        != "race_allowed"
                        || (int)d->tables[0]
                            .values.size() != 42)
                        ++bad;
                    if (d->tables[1].name
                        != "race_cap"
                        || (int)d->tables[1]
                            .values.size() != 42)
                        ++bad;
                    if (d->rows[0].set
                        != "ph_subgates_race"
                        || d->rows[0].bandLo != 0
                        || d->rows[0].bandHi != 0)
                        ++bad;
                    if (d->rows[1].set
                        != "ph_subgates_race"
                        || d->rows[1].bandLo != 1
                        || d->rows[1].bandHi != 1)
                        ++bad;
                    if (d->rows[2].set
                        != "ph_subgates_race"
                        || d->rows[2].bandLo != 2
                        || d->rows[2].bandHi != 2)
                        ++bad;
                    if (d->rows[3].set
                        != "ph_subgates_race"
                        || d->rows[3].bandLo != 3
                        || d->rows[3].bandHi != 3)
                        ++bad;
                    if (d->rows[4].set
                        != "ph_subgates_race"
                        || d->rows[4].bandLo != 4
                        || d->rows[4].bandHi != 4)
                        ++bad;
                    if (d->rows[5].set
                        != "ph_subgates_race"
                        || d->rows[5].bandLo != 5
                        || d->rows[5].bandHi != 5)
                        ++bad;
                if (std::string(
                    d->rows[0].name)
                    != "paladin")
                    ++bad;
                if (std::string(
                    d->rows[1].name)
                    != "ranger")
                    ++bad;
                if (std::string(
                    d->rows[2].name)
                    != "druid")
                    ++bad;
                if (std::string(
                    d->rows[3].name)
                    != "illusionist")
                    ++bad;
                if (std::string(
                    d->rows[4].name)
                    != "assassin")
                    ++bad;
                if (std::string(
                    d->rows[5].name)
                    != "monk")
                    ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ph_subgates_leveling");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 6
                        || (int)d->pins.size() != 1
                        || d->pins[0].name
                            != "ph_subgates_levelingRowCount"
                        || d->pins[0].value != 6
                        || (int)d->tables.size() != 7)
                        ++bad;
                    if (d->tables[0].name
                        != "hit_die"
                        || (int)d->tables[0]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[1].name
                        != "xp_len"
                        || (int)d->tables[1]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[2].name
                        != "xp_attain"
                        || (int)d->tables[2]
                            .values.size() != 102)
                        ++bad;
                    if (d->tables[3].name
                        != "xp_add"
                        || (int)d->tables[3]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[4].name
                        != "fixed_hp_level"
                        || (int)d->tables[4]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[5].name
                        != "hp_beyond_fixed"
                        || (int)d->tables[5]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[6].name
                        != "level_stop"
                        || (int)d->tables[6]
                            .values.size() != 6)
                        ++bad;
                    if (d->rows[0].set
                        != "ph_subgates_leveling"
                        || d->rows[0].bandLo != 0
                        || d->rows[0].bandHi != 0)
                        ++bad;
                    if (d->rows[1].set
                        != "ph_subgates_leveling"
                        || d->rows[1].bandLo != 1
                        || d->rows[1].bandHi != 1)
                        ++bad;
                    if (d->rows[2].set
                        != "ph_subgates_leveling"
                        || d->rows[2].bandLo != 2
                        || d->rows[2].bandHi != 2)
                        ++bad;
                    if (d->rows[3].set
                        != "ph_subgates_leveling"
                        || d->rows[3].bandLo != 3
                        || d->rows[3].bandHi != 3)
                        ++bad;
                    if (d->rows[4].set
                        != "ph_subgates_leveling"
                        || d->rows[4].bandLo != 4
                        || d->rows[4].bandHi != 4)
                        ++bad;
                    if (d->rows[5].set
                        != "ph_subgates_leveling"
                        || d->rows[5].bandLo != 5
                        || d->rows[5].bandHi != 5)
                        ++bad;
                if (std::string(
                    d->rows[0].name)
                    != "paladin")
                    ++bad;
                if (std::string(
                    d->rows[1].name)
                    != "ranger")
                    ++bad;
                if (std::string(
                    d->rows[2].name)
                    != "druid")
                    ++bad;
                if (std::string(
                    d->rows[3].name)
                    != "illusionist")
                    ++bad;
                if (std::string(
                    d->rows[4].name)
                    != "assassin")
                    ++bad;
                if (std::string(
                    d->rows[5].name)
                    != "monk")
                    ++bad;
                }
            }
        }
        printf("R1055 subgates registry counts audit: bad %d\\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 3. qualify ---------------------------
        {
            const int wantGtAbilityMin[] = {
                12, 9, 13, 0, 9, 17, 13, 13, 14, 0,
                14, 0, 0, 0, 12, 0, 0, 15, 0, 15,
                0, 16, 0, 0, 12, 11, 0, 12, 0, 0,
                15, 0, 15, 15, 11, 0,
            };
            for (int s = 0; s < 6; ++s)
                for (int a = 0; a < 6;
                     ++a)
                    if (rules::subclassAbilityMin(
                            s, (rules::Ability)a)
                        != wantGtAbilityMin
                            [s * 6 + a])
                        ++bad;
            const int wantGtAlignReq[] = {
                1, 2, 3, 0, 4, 5,
            };
            for (int s = 0; s < 6; ++s)
                if (rules::subclassAlignmentReq(s)
                    != wantGtAlignReq[s])
                    ++bad;
            const int wantGtXpBonus[] = {
                1, 2, 3, 0, 0, 0,
            };
            for (int s = 0; s < 6; ++s)
                if (rules::subclassXpBonusRule(s)
                    != wantGtXpBonus[s])
                    ++bad;
            {
                rules::AbilityScores s;
                s.set((rules::Ability)0, 13);
                s.set((rules::Ability)1, 11);
                s.set((rules::Ability)2, 14);
                s.set((rules::Ability)3, 11);
                s.set((rules::Ability)4, 11);
                s.set((rules::Ability)5, 18);
                if (!rules::subclassMeetsAbilityMin(
                        0, s))
                    ++bad;
                s.set((rules::Ability)0, 11);
                if (rules::subclassMeetsAbilityMin(
                        0, s))
                    ++bad;
            }
            {
                rules::AbilityScores s;
                s.set((rules::Ability)0, 14);
                s.set((rules::Ability)1, 14);
                s.set((rules::Ability)2, 15);
                s.set((rules::Ability)3, 11);
                s.set((rules::Ability)4, 15);
                s.set((rules::Ability)5, 11);
                if (!rules::subclassMeetsAbilityMin(
                        1, s))
                    ++bad;
                s.set((rules::Ability)0, 12);
                if (rules::subclassMeetsAbilityMin(
                        1, s))
                    ++bad;
            }
            {
                rules::AbilityScores s;
                s.set((rules::Ability)0, 11);
                s.set((rules::Ability)1, 11);
                s.set((rules::Ability)2, 13);
                s.set((rules::Ability)3, 11);
                s.set((rules::Ability)4, 11);
                s.set((rules::Ability)5, 16);
                if (!rules::subclassMeetsAbilityMin(
                        2, s))
                    ++bad;
                s.set((rules::Ability)2, 11);
                if (rules::subclassMeetsAbilityMin(
                        2, s))
                    ++bad;
            }
            {
                rules::AbilityScores s;
                s.set((rules::Ability)0, 11);
                s.set((rules::Ability)1, 16);
                s.set((rules::Ability)2, 11);
                s.set((rules::Ability)3, 17);
                s.set((rules::Ability)4, 11);
                s.set((rules::Ability)5, 11);
                if (!rules::subclassMeetsAbilityMin(
                        3, s))
                    ++bad;
                s.set((rules::Ability)1, 14);
                if (rules::subclassMeetsAbilityMin(
                        3, s))
                    ++bad;
            }
            {
                rules::AbilityScores s;
                s.set((rules::Ability)0, 13);
                s.set((rules::Ability)1, 12);
                s.set((rules::Ability)2, 11);
                s.set((rules::Ability)3, 13);
                s.set((rules::Ability)4, 11);
                s.set((rules::Ability)5, 11);
                if (!rules::subclassMeetsAbilityMin(
                        4, s))
                    ++bad;
                s.set((rules::Ability)0, 11);
                if (rules::subclassMeetsAbilityMin(
                        4, s))
                    ++bad;
            }
            {
                rules::AbilityScores s;
                s.set((rules::Ability)0, 16);
                s.set((rules::Ability)1, 11);
                s.set((rules::Ability)2, 16);
                s.set((rules::Ability)3, 16);
                s.set((rules::Ability)4, 12);
                s.set((rules::Ability)5, 11);
                if (!rules::subclassMeetsAbilityMin(
                        5, s))
                    ++bad;
                s.set((rules::Ability)0, 14);
                if (rules::subclassMeetsAbilityMin(
                        5, s))
                    ++bad;
            }
            {
                rules::AbilityScores s;
                s.set((rules::Ability)0, 16);
                s.set((rules::Ability)1, 10);
                s.set((rules::Ability)2, 16);
                s.set((rules::Ability)3, 10);
                s.set((rules::Ability)4, 10);
                s.set((rules::Ability)5, 10);
                if (!rules::subclassXpBonusEarned(
                        0, s))
                    ++bad;
                s.set((rules::Ability)0, 15);
                if (rules::subclassXpBonusEarned(
                        0, s))
                    ++bad;
            }
            {
                rules::AbilityScores s;
                s.set((rules::Ability)0, 16);
                s.set((rules::Ability)1, 16);
                s.set((rules::Ability)2, 16);
                s.set((rules::Ability)3, 10);
                s.set((rules::Ability)4, 10);
                s.set((rules::Ability)5, 10);
                if (!rules::subclassXpBonusEarned(
                        1, s))
                    ++bad;
                s.set((rules::Ability)0, 15);
                if (rules::subclassXpBonusEarned(
                        1, s))
                    ++bad;
            }
            {
                rules::AbilityScores s;
                s.set((rules::Ability)0, 10);
                s.set((rules::Ability)1, 10);
                s.set((rules::Ability)2, 16);
                s.set((rules::Ability)3, 10);
                s.set((rules::Ability)4, 10);
                s.set((rules::Ability)5, 16);
                if (!rules::subclassXpBonusEarned(
                        2, s))
                    ++bad;
                s.set((rules::Ability)2, 15);
                if (rules::subclassXpBonusEarned(
                        2, s))
                    ++bad;
            }
            {
                rules::AbilityScores s;
                s.set((rules::Ability)0, 10);
                s.set((rules::Ability)1, 10);
                s.set((rules::Ability)2, 10);
                s.set((rules::Ability)3, 10);
                s.set((rules::Ability)4, 10);
                s.set((rules::Ability)5, 10);
                if (rules::subclassXpBonusEarned(
                        3, s))
                    ++bad;
            }
            {
                rules::AbilityScores s;
                s.set((rules::Ability)0, 10);
                s.set((rules::Ability)1, 10);
                s.set((rules::Ability)2, 10);
                s.set((rules::Ability)3, 10);
                s.set((rules::Ability)4, 10);
                s.set((rules::Ability)5, 10);
                if (rules::subclassXpBonusEarned(
                        4, s))
                    ++bad;
            }
            {
                rules::AbilityScores s;
                s.set((rules::Ability)0, 10);
                s.set((rules::Ability)1, 10);
                s.set((rules::Ability)2, 10);
                s.set((rules::Ability)3, 10);
                s.set((rules::Ability)4, 10);
                s.set((rules::Ability)5, 10);
                if (rules::subclassXpBonusEarned(
                        5, s))
                    ++bad;
            }
        }
        printf("R1055 subgates qualify audit: bad %d\\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 4. race -------------------------------
        {
            const int wantGtRaceAllowed[] = {
                1, 0, 0, 0, 0, 0, 0, 1, 0, 0,
                0, 1, 0, 0, 1, 0, 0, 0, 1, 0,
                0, 1, 0, 0, 1, 0, 0, 0, 1, 1,
                1, 1, 1, 0, 1, 1, 0, 0, 0, 0,
                0, 0,
            };
            const int wantGtRaceCap[] = {
                -1, 0, 0, 0, 0, 0, 0, -1, 0, 0,
                0, 8, 0, 0, -1, 0, 0, 0, -1, -6,
                0, -1, 0, 0, 7, 0, 0, 0, -1, 9,
                10, 8, 11, 0, -1, -1, 0, 0, 0, 0,
                0, 0,
            };
            for (int s = 0; s < 6; ++s)
                for (int r = 0; r < 7;
                     ++r) {
                    if (rules::subclassRaceAllowed(
                            s, (rules::CharRace)r)
                        != wantGtRaceAllowed
                            [s * 7 + r])
                        ++bad;
                    if (rules::subclassPlayerAllowed(
                            s, (rules::CharRace)r)
                        != wantGtRaceAllowed
                            [s * 7 + r])
                        ++bad;
                    if (rules::subclassRaceCap(
                            s, (rules::CharRace)r)
                        != wantGtRaceCap
                            [s * 7 + r])
                        ++bad;
                    if (!(s == 3 && r == 3) && (rules::subclassLevelCapFor(
                            s, (rules::CharRace)r,
                            18, 18)
                        != wantGtRaceCap
                            [s * 7 + r]))
                        ++bad;
                }
            if (rules::illusionistGnomeCap(16, 10) != 5)
                ++bad;
            if (rules::illusionistGnomeCap(17, 17) != 6)
                ++bad;
            if (rules::subclassRaceCap(3, (rules::CharRace)3) != 7)
                ++bad;
            if (rules::subclassLevelCapFor(3, (rules::CharRace)3, 16, 10)
                != 5)
                ++bad;
            if (rules::subclassLevelCapFor(3, (rules::CharRace)3, 17, 17)
                != 6)
                ++bad;
            if (!rules::subclassCapIsNpcOnly(2, (rules::CharRace)5))
                ++bad;
            if (rules::subclassCapIsNpcOnly(0, (rules::CharRace)1))
                ++bad;
            if (rules::subclassLevelCapTotal(1, (rules::CharRace)4, 18, 18)
                != 8)
                ++bad;
            if (rules::subclassLevelCapTotal(4, (rules::CharRace)1, 18, 18)
                != 9)
                ++bad;
            if (rules::subclassLevelCapTotal(0, (rules::CharRace)0, 18, 18)
                != 9)
                ++bad;
            if (rules::subclassLevelCapTotal(2, (rules::CharRace)0, 18, 18)
                != 14)
                ++bad;
            if (rules::subclassLevelCapTotal(3, (rules::CharRace)3, 16, 10)
                != 5)
                ++bad;
            if (rules::subclassLevelCapTotal(3, (rules::CharRace)3, 17, 17)
                != 6)
                ++bad;
        }
        printf("R1055 subgates race audit: bad %d\\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 5. leveling ---------------------------
        {
            const int wantGtHitDie[] = {
                10, 8, 8, 4, 6, 4,
            };
            const int wantGtXpAttain[] = {
                0, 2750, 5500, 12000, 24000, 45000, 95000, 175000, 350000,
                    700000,
                1050000, 0, 0, 0, 0, 0, 0, 0, 2250, 4500,
                10000, 20000, 40000, 90000, 150000, 225000, 325000, 650000,
                    975000, 0,
                0, 0, 0, 0, 0, 2000, 4000, 7500, 12500, 20000,
                35000, 60000, 90000, 125000, 200000, 300000, 750000, 1500000,
                    0, 0,
                0, 0, 2250, 4500, 9000, 18000, 35000, 60000, 95000, 145000,
                220000, 440000, 660000, 0, 0, 0, 0, 0, 0, 1500,
                3000, 6000, 12000, 25000, 50000, 100000, 200000, 300000,
                    425000, 575000,
                750000, 1000000, 1500000, 0, 0, 0, 2250, 4750, 10000, 22500,
                47500, 98000, 200000, 350000, 500000, 700000, 950000, 1250000,
                    1750000, 2250000,
                2750000, 3250000,
            };
            for (int s = 0; s < 6; ++s)
                if (rules::subclassHitDie(s)
                    != wantGtHitDie[s])
                    ++bad;
            {
                for (int lvl = 2; lvl <= 11;
                     ++lvl)
                    if (rules::subclassXpToAttain(
                            0, lvl)
                        != wantGtXpAttain
                            [0 + lvl - 1])
                        ++bad;
            if (rules::subclassXpToAttain(0, 12) != 1400000)
                ++bad;
            if (rules::subclassXpToAttain(0, 13) != 1750000)
                ++bad;
            }
            {
                for (int lvl = 2; lvl <= 12;
                     ++lvl)
                    if (rules::subclassXpToAttain(
                            1, lvl)
                        != wantGtXpAttain
                            [17 + lvl - 1])
                        ++bad;
            if (rules::subclassXpToAttain(1, 13) != 1300000)
                ++bad;
            if (rules::subclassXpToAttain(1, 14) != 1625000)
                ++bad;
            }
            {
                for (int lvl = 2; lvl <= 14;
                     ++lvl)
                    if (rules::subclassXpToAttain(
                            2, lvl)
                        != wantGtXpAttain
                            [34 + lvl - 1])
                        ++bad;
            if (rules::subclassXpToAttain(2, 15) != 1500000)
                ++bad;
            if (rules::subclassXpToAttain(2, 16) != 1500000)
                ++bad;
            }
            {
                for (int lvl = 2; lvl <= 12;
                     ++lvl)
                    if (rules::subclassXpToAttain(
                            3, lvl)
                        != wantGtXpAttain
                            [51 + lvl - 1])
                        ++bad;
            if (rules::subclassXpToAttain(3, 13) != 880000)
                ++bad;
            if (rules::subclassXpToAttain(3, 14) != 1100000)
                ++bad;
            }
            {
                for (int lvl = 2; lvl <= 15;
                     ++lvl)
                    if (rules::subclassXpToAttain(
                            4, lvl)
                        != wantGtXpAttain
                            [68 + lvl - 1])
                        ++bad;
            if (rules::subclassXpToAttain(4, 16) != 1500000)
                ++bad;
            if (rules::subclassXpToAttain(4, 17) != 1500000)
                ++bad;
            }
            {
                for (int lvl = 2; lvl <= 17;
                     ++lvl)
                    if (rules::subclassXpToAttain(
                            5, lvl)
                        != wantGtXpAttain
                            [85 + lvl - 1])
                        ++bad;
            if (rules::subclassXpToAttain(5, 18) != 3250000)
                ++bad;
            if (rules::subclassXpToAttain(5, 19) != 3250000)
                ++bad;
            }
            const int wantGtFixedHpLevel[] = {
                9, 10, 9, 10, 10, 17,
            };
            for (int s = 0; s < 6; ++s)
                if (rules::subclassFixedHpLevel(s)
                    != wantGtFixedHpLevel[s])
                    ++bad;
            const int wantGtHpBeyondFixed[] = {
                3, 2, 2, 1, 2, 0,
            };
            for (int s = 0; s < 6; ++s)
                if (rules::subclassHpBeyondFixed(s)
                    != wantGtHpBeyondFixed[s])
                    ++bad;
            const int wantGtLevelStop[] = {
                9, 10, 14, 10, 10, 17,
            };
            for (int s = 0; s < 6; ++s)
                if (rules::subclassLevelStop(s)
                    != wantGtLevelStop[s])
                    ++bad;
        }
        printf("R1055 subgates leveling audit: bad %d\\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 6. seam ---------------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/ph_subgates");
            {
                const items::MiscItemDef* d =
                    reg.find("ph_subgates_qualify");
                if (!d) ++bad;
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "ability_min")
                            continue;
                        got = 1;
                        for (int s = 0; s < 6;
                             ++s)
                            for (int a = 0;
                                 a < 6;
                                 ++a)
                                if ((int)t
                                    .values[
                                    s * 6 + a]
                                    !=
                                    rules::subclassAbilityMin(
                                        s,
                                        (rules::Ability)a))
                                    ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "align_req")
                            continue;
                        got = 1;
                        for (int s = 0; s < 6;
                             ++s)
                            if ((int)t
                                .values[s]
                                !=
                                rules::subclassAlignmentReq(
                                    s))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "xp_bonus")
                            continue;
                        got = 1;
                        for (int s = 0; s < 6;
                             ++s)
                            if ((int)t
                                .values[s]
                                !=
                                rules::subclassXpBonusRule(
                                    s))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ph_subgates_race");
                if (!d) ++bad;
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "race_allowed")
                            continue;
                        got = 1;
                        for (int s = 0; s < 6;
                             ++s)
                            for (int r = 0;
                                 r < 7;
                                 ++r) {
                                if ((int)t
                                    .values[
                                    s * 7 + r]
                                    !=
                                    rules::subclassRaceAllowed(
                                        s,
                                        (rules::CharRace)r))
                                    ++bad;
                                if ((int)t
                                    .values[
                                    s * 7 + r]
                                    !=
                                    rules::subclassPlayerAllowed(
                                        s,
                                        (rules::CharRace)r))
                                    ++bad;
                            }
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "race_cap")
                            continue;
                        got = 1;
                        for (int s = 0; s < 6;
                             ++s)
                            for (int r = 0;
                                 r < 7;
                                 ++r)
                                if (!(s == 3 && r == 3)
                                    && ((int)t
                                        .values[
                                        s * 7 + r]
                                        !=
                                        rules::subclassLevelCapFor(
                                            s,
                                            (rules::CharRace)r,
                                            18, 18)))
                                    ++bad;
                    }
                    if (!got) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("ph_subgates_leveling");
                if (!d) ++bad;
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "hit_die")
                            continue;
                        got = 1;
                        for (int s = 0; s < 6;
                             ++s)
                            if ((int)t
                                .values[s]
                                !=
                                rules::subclassHitDie(
                                    s))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    int lens[6] = { 11, 12, 14, 12, 15, 17 };
                    for (const auto& t2 : d->tables)
                        if (t2.name == "xp_len")
                            for (int s = 0; s < 6;
                                 ++s)
                                lens[s] = (int)t2.values[s];
                    for (const auto& t : d->tables) {
                        if (t.name != "xp_attain")
                            continue;
                        got = 1;
                        for (int s = 0; s < 6;
                             ++s)
                            for (int lvl = 2;
                                 lvl <= lens[s];
                                 ++lvl)
                                if ((int)t
                                    .values[
                                    s * 17 + lvl
                                     - 1]
                                    !=
                                    rules::subclassXpToAttain(
                                        s, lvl))
                                    ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "fixed_hp_level")
                            continue;
                        got = 1;
                        for (int s = 0; s < 6;
                             ++s)
                            if ((int)t
                                .values[s]
                                !=
                                rules::subclassFixedHpLevel(
                                    s))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "hp_beyond_fixed")
                            continue;
                        got = 1;
                        for (int s = 0; s < 6;
                             ++s)
                            if ((int)t
                                .values[s]
                                !=
                                rules::subclassHpBeyondFixed(
                                    s))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "level_stop")
                            continue;
                        got = 1;
                        for (int s = 0; s < 6;
                             ++s)
                            if ((int)t
                                .values[s]
                                !=
                                rules::subclassLevelStop(
                                    s))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
            }
        }
        printf("R1055 subgates registry seam audit: bad %d\\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 7. edges --------------------------------
        {
            if (rules::subclassAbilityMin(-1, (rules::Ability)0) != 12)
                ++bad;
            if (rules::subclassAbilityMin(6, (rules::Ability)5) != 0)
                ++bad;
            if (rules::subclassAlignmentReq(-1) != 1)
                ++bad;
            if (rules::subclassAlignmentReq(6) != 5)
                ++bad;
            if (rules::subclassXpBonusRule(-1) != 1)
                ++bad;
            if (rules::subclassXpBonusRule(6) != 0)
                ++bad;
            if (rules::subclassHitDie(-1) != 10)
                ++bad;
            if (rules::subclassHitDie(6) != 4)
                ++bad;
            if (rules::subclassFixedHpLevel(-1) != 9)
                ++bad;
            if (rules::subclassFixedHpLevel(6) != 17)
                ++bad;
            if (rules::subclassHpBeyondFixed(-1) != 3)
                ++bad;
            if (rules::subclassHpBeyondFixed(6) != 0)
                ++bad;
            if (rules::subclassLevelStop(-1) != 9)
                ++bad;
            if (rules::subclassLevelStop(6) != 17)
                ++bad;
            if (rules::subclassRaceAllowed(0, (rules::CharRace)7) != 0)
                ++bad;
            if (rules::subclassRaceAllowed(0, (rules::CharRace)-1) != 0)
                ++bad;
            if (rules::subclassRaceCap(0, (rules::CharRace)7) != 0)
                ++bad;
            if (rules::subclassPlayerAllowed(-1, (rules::CharRace)-1) != 1)
                ++bad;
            if (rules::subclassPlayerAllowed(6, (rules::CharRace)7) != 0)
                ++bad;
            if (rules::subclassLevelCapFor(-1, (rules::CharRace)-1, 18, 18)
                != -1)
                ++bad;
            if (rules::subclassLevelCapFor(6, (rules::CharRace)7, 18, 18)
                != 0)
                ++bad;
            if (rules::subclassAbilityMin(0, (rules::Ability)6) != 0)
                ++bad;
            if (rules::subclassAbilityMin(0, (rules::Ability)-1) != 0)
                ++bad;
            if (rules::subclassXpToAttain(0, 0) != 0)
                ++bad;
            if (rules::subclassXpToAttain(0, 1) != 0)
                ++bad;
            if (rules::subclassXpToAttain(1, 0) != 0)
                ++bad;
            if (rules::subclassXpToAttain(1, 1) != 0)
                ++bad;
            if (rules::subclassXpToAttain(2, 0) != 0)
                ++bad;
            if (rules::subclassXpToAttain(2, 1) != 0)
                ++bad;
            if (rules::subclassXpToAttain(3, 0) != 0)
                ++bad;
            if (rules::subclassXpToAttain(3, 1) != 0)
                ++bad;
            if (rules::subclassXpToAttain(4, 0) != 0)
                ++bad;
            if (rules::subclassXpToAttain(4, 1) != 0)
                ++bad;
            if (rules::subclassXpToAttain(5, 0) != 0)
                ++bad;
            if (rules::subclassXpToAttain(5, 1) != 0)
                ++bad;
            if (rules::subclassRuntimeBase(0) != 0)
                ++bad;
            if (rules::subclassRuntimeBase(1) != 0)
                ++bad;
            if (rules::subclassRuntimeBase(2) != 2)
                ++bad;
            if (rules::subclassRuntimeBase(3) != 1)
                ++bad;
            if (rules::subclassRuntimeBase(4) != 3)
                ++bad;
            if (rules::subclassRuntimeBase(5) != 0)
                ++bad;
            if (rules::subclassRuntimeBase(6) != 0)
                ++bad;
            if (rules::subclassConClass(0) != 0)
                ++bad;
            if (rules::subclassConClass(1) != 0)
                ++bad;
            if (rules::subclassConClass(2) != 2)
                ++bad;
            if (rules::subclassConClass(3) != 1)
                ++bad;
            if (rules::subclassConClass(4) != 3)
                ++bad;
            if (rules::subclassConClass(5) != 3)
                ++bad;
            if (rules::subclassConClass(6) != 0)
                ++bad;
            if (rules::subclassStartAgeBase(0) != 15)
                ++bad;
            if (rules::subclassStartAgeBase(1) != 15)
                ++bad;
            if (rules::subclassStartAgeBase(2) != 18)
                ++bad;
            if (rules::subclassStartAgeBase(3) != 24)
                ++bad;
            if (rules::subclassStartAgeBase(4) != 18)
                ++bad;
            if (rules::subclassStartAgeBase(5) != 15)
                ++bad;
            if (rules::subclassStartAgeBase(6) != 15)
                ++bad;
            if (rules::subclassTwoDiceFirstLevel(0) != 0)
                ++bad;
            if (rules::subclassTwoDiceFirstLevel(1) != 1)
                ++bad;
            if (rules::subclassTwoDiceFirstLevel(2) != 0)
                ++bad;
            if (rules::subclassTwoDiceFirstLevel(3) != 0)
                ++bad;
            if (rules::subclassTwoDiceFirstLevel(4) != 0)
                ++bad;
            if (rules::subclassTwoDiceFirstLevel(5) != 1)
                ++bad;
            if (rules::subclassTwoDiceFirstLevel(6) != 0)
                ++bad;
        }
        printf("R1055 subgates registry edges audit: bad %d\\n", bad);
    }
