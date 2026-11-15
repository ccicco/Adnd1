    // ==== R1051: disease registry ========================
    // The R1051 de-wire: the 12 tables of
    // rules/dmg/disease.h ride items::
    // MiscItemRegistry from content/tables/
    // dm_disease/ (2 defs: name rows + d100/
    // occurrence/severity columns + the terminal
    // duration units). Six sections: load,
    // counts, disease areas, parasite areas,
    // seam, edges. Census 1064 -> 1070. DO NOT
    // hand-edit: tools/r1051_splice.py is the
    // only writer.
    {
        int bad = 0;
        // -- 1. load ---------------------------------
        {
            items::MiscItemRegistry reg;
            int n = reg.loadDirectory(
                "content/tables/dm_disease");
            if (n != 2) ++bad;
            if (!reg.errors().empty()) ++bad;
            for (const auto& kv : reg.all())
                if ((int)kv.second.sources.size() != 1
                    || kv.second.sources[0].second != 1051)
                    ++bad;
            if (!reg.find("dm_disease_areas")) ++bad;
            if (!reg.find("dm_parasite_areas")) ++bad;
        }
        printf("R1051 disease registry load audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 2. counts --------------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/dm_disease");
            {
                const items::MiscItemDef* d =
                    reg.find("dm_disease_areas");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 16
                        || (int)d->pins.size() != 1
                        || d->pins[0].name != "dm_disease_areasRowCount"
                        || d->pins[0].value != 16
                        || (int)d->tables.size() != 6)
                        ++bad;
                    if (d->tables[0].name
                        != "d100"
                        || (int)d->tables[0]
                            .values.size() != 16)
                        ++bad;
                    if (d->tables[1].name
                        != "acute_hi"
                        || (int)d->tables[1]
                            .values.size() != 16)
                        ++bad;
                    if (d->tables[2].name
                        != "sev_mild_hi"
                        || (int)d->tables[2]
                            .values.size() != 16)
                        ++bad;
                    if (d->tables[3].name
                        != "sev_severe_hi"
                        || (int)d->tables[3]
                            .values.size() != 16)
                        ++bad;
                    if (d->tables[4].name
                        != "sev_terminal_hi"
                        || (int)d->tables[4]
                            .values.size() != 16)
                        ++bad;
                    if (d->tables[5].name
                        != "terminal_unit"
                        || (int)d->tables[5]
                            .values.size() != 16)
                        ++bad;
                    if (d->rows[0].set !=
                        "dm_disease_areas"
                        || d->rows[0].bandLo != 0
                        || d->rows[0].bandHi != 0)
                        ++bad;
                    if (d->rows[1].set !=
                        "dm_disease_areas"
                        || d->rows[1].bandLo != 1
                        || d->rows[1].bandHi != 1)
                        ++bad;
                    if (d->rows[2].set !=
                        "dm_disease_areas"
                        || d->rows[2].bandLo != 2
                        || d->rows[2].bandHi != 2)
                        ++bad;
                    if (d->rows[3].set !=
                        "dm_disease_areas"
                        || d->rows[3].bandLo != 3
                        || d->rows[3].bandHi != 3)
                        ++bad;
                    if (d->rows[4].set !=
                        "dm_disease_areas"
                        || d->rows[4].bandLo != 4
                        || d->rows[4].bandHi != 4)
                        ++bad;
                    if (d->rows[5].set !=
                        "dm_disease_areas"
                        || d->rows[5].bandLo != 5
                        || d->rows[5].bandHi != 5)
                        ++bad;
                    if (d->rows[6].set !=
                        "dm_disease_areas"
                        || d->rows[6].bandLo != 6
                        || d->rows[6].bandHi != 6)
                        ++bad;
                    if (d->rows[7].set !=
                        "dm_disease_areas"
                        || d->rows[7].bandLo != 7
                        || d->rows[7].bandHi != 7)
                        ++bad;
                    if (d->rows[8].set !=
                        "dm_disease_areas"
                        || d->rows[8].bandLo != 8
                        || d->rows[8].bandHi != 8)
                        ++bad;
                    if (d->rows[9].set !=
                        "dm_disease_areas"
                        || d->rows[9].bandLo != 9
                        || d->rows[9].bandHi != 9)
                        ++bad;
                    if (d->rows[10].set !=
                        "dm_disease_areas"
                        || d->rows[10].bandLo != 10
                        || d->rows[10].bandHi != 10)
                        ++bad;
                    if (d->rows[11].set !=
                        "dm_disease_areas"
                        || d->rows[11].bandLo != 11
                        || d->rows[11].bandHi != 11)
                        ++bad;
                    if (d->rows[12].set !=
                        "dm_disease_areas"
                        || d->rows[12].bandLo != 12
                        || d->rows[12].bandHi != 12)
                        ++bad;
                    if (d->rows[13].set !=
                        "dm_disease_areas"
                        || d->rows[13].bandLo != 13
                        || d->rows[13].bandHi != 13)
                        ++bad;
                    if (d->rows[14].set !=
                        "dm_disease_areas"
                        || d->rows[14].bandLo != 14
                        || d->rows[14].bandHi != 14)
                        ++bad;
                    if (d->rows[15].set !=
                        "dm_disease_areas"
                        || d->rows[15].bandLo != 15
                        || d->rows[15].bandHi != 15)
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("dm_parasite_areas");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 6
                        || (int)d->pins.size() != 1
                        || d->pins[0].name != "dm_parasite_areasRowCount"
                        || d->pins[0].value != 6
                        || (int)d->tables.size() != 4)
                        ++bad;
                    if (d->tables[0].name
                        != "d100"
                        || (int)d->tables[0]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[1].name
                        != "sev_mild_hi"
                        || (int)d->tables[1]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[2].name
                        != "sev_severe_hi"
                        || (int)d->tables[2]
                            .values.size() != 6)
                        ++bad;
                    if (d->tables[3].name
                        != "sev_terminal_hi"
                        || (int)d->tables[3]
                            .values.size() != 6)
                        ++bad;
                    if (d->rows[0].set !=
                        "dm_parasite_areas"
                        || d->rows[0].bandLo != 0
                        || d->rows[0].bandHi != 0)
                        ++bad;
                    if (d->rows[1].set !=
                        "dm_parasite_areas"
                        || d->rows[1].bandLo != 1
                        || d->rows[1].bandHi != 1)
                        ++bad;
                    if (d->rows[2].set !=
                        "dm_parasite_areas"
                        || d->rows[2].bandLo != 2
                        || d->rows[2].bandHi != 2)
                        ++bad;
                    if (d->rows[3].set !=
                        "dm_parasite_areas"
                        || d->rows[3].bandLo != 3
                        || d->rows[3].bandHi != 3)
                        ++bad;
                    if (d->rows[4].set !=
                        "dm_parasite_areas"
                        || d->rows[4].bandLo != 4
                        || d->rows[4].bandHi != 4)
                        ++bad;
                    if (d->rows[5].set !=
                        "dm_parasite_areas"
                        || d->rows[5].bandLo != 5
                        || d->rows[5].bandHi != 5)
                        ++bad;
                }
            }
        }
        printf("R1051 disease registry counts audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 3. the dm_disease_areas ----
        {
            if (rules::diseaseAreaCount() != 16) ++bad;
            if (std::string(rules::diseaseAreaName(0))
                != "blood/blood forming organs") ++bad;
            if (std::string(rules::diseaseAreaName(1))
                != "bones") ++bad;
            if (std::string(rules::diseaseAreaName(2))
                != "brain/nervous system") ++bad;
            if (std::string(rules::diseaseAreaName(3))
                != "cardiovascular-renal") ++bad;
            if (std::string(rules::diseaseAreaName(4))
                != "connective tissue") ++bad;
            if (std::string(rules::diseaseAreaName(5))
                != "ears") ++bad;
            if (std::string(rules::diseaseAreaName(6))
                != "eyes") ++bad;
            if (std::string(rules::diseaseAreaName(7))
                != "gastro-intestinal") ++bad;
            if (std::string(rules::diseaseAreaName(8))
                != "generative organs") ++bad;
            if (std::string(rules::diseaseAreaName(9))
                != "joints") ++bad;
            if (std::string(rules::diseaseAreaName(10))
                != "mucous membranes") ++bad;
            if (std::string(rules::diseaseAreaName(11))
                != "muscles") ++bad;
            if (std::string(rules::diseaseAreaName(12))
                != "nose-throat") ++bad;
            if (std::string(rules::diseaseAreaName(13))
                != "respiratory system") ++bad;
            if (std::string(rules::diseaseAreaName(14))
                != "skin") ++bad;
            if (std::string(rules::diseaseAreaName(15))
                != "urinary system") ++bad;
            const int wantDzLo[] = {
                1, 4, 5, 6, 8, 10, 13, 19, 41, 43,
                49, 51, 53, 66, 86, 97,
            };
            for (int i = 0; i < 16; ++i)
                if (rules::diseaseAreaForD100(
                    wantDzLo[i]) != i)
                    ++bad;
            for (int i = 1; i < 16; ++i)
                if (rules::diseaseAreaForD100(
                    wantDzLo[i] - 1) != i - 1)
                    ++bad;
            const int wantDzAcuteHi[] = {
                3, 1, 6, 3, 1, 7, 7, 6, 2, 4,
                7, 5, 6, 6, 5, 6,
            };
            for (int i = 0; i < 16; ++i)
                if (rules::diseaseAcuteHi(i)
                    != wantDzAcuteHi[i])
                    ++bad;
            const int wantDzSevMildHi[] = {
                2, 1, 2, 2, 1, 6, 5, 5, 3, 6,
                6, 5, 6, 5, 5, 5,
            };
            for (int i = 0; i < 16; ++i)
                if (rules::diseaseSeverityMildHi(i)
                    != wantDzSevMildHi[i])
                    ++bad;
            const int wantDzSevSevereHi[] = {
                5, 3, 5, 4, 3, 7, 7, 7, 7, 8,
                8, 7, 8, 7, 7, 7,
            };
            for (int i = 0; i < 16; ++i)
                if (rules::diseaseSeveritySevereHi(i)
                    != wantDzSevSevereHi[i])
                    ++bad;
            const int wantDzSevTerminalHi[] = {
                8, 8, 8, 8, 8, 8, 8, 8, 8, 0,
                0, 8, 0, 8, 8, 8,
            };
            for (int i = 0; i < 16; ++i)
                if (rules::diseaseSeverityTerminalHi(i)
                    != wantDzSevTerminalHi[i])
                    ++bad;
            const int wantDzTerminalUnit[] = {
                3, 3, 1, 2, 0, 0, 0, 3, 4, 0,
                0, 4, 0, 4, 3, 3,
            };
            for (int i = 0; i < 16; ++i)
                if ((int)rules::diseaseTerminalUnit(i)
                    != wantDzTerminalUnit[i])
                    ++bad;
        }
        printf("R1051 disease areas audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 4. the dm_parasite_areas ----
        {
            if (rules::parasiteAreaCount() != 6) ++bad;
            if (std::string(rules::parasiteAreaName(0))
                != "cardiovascular system") ++bad;
            if (std::string(rules::parasiteAreaName(1))
                != "intestines") ++bad;
            if (std::string(rules::parasiteAreaName(2))
                != "muscles") ++bad;
            if (std::string(rules::parasiteAreaName(3))
                != "respiratory system") ++bad;
            if (std::string(rules::parasiteAreaName(4))
                != "skin/hair") ++bad;
            if (std::string(rules::parasiteAreaName(5))
                != "stomach") ++bad;
            const int wantPaLo[] = {
                1, 11, 36, 41, 46, 76,
            };
            for (int i = 0; i < 6; ++i)
                if (rules::parasiteAreaForD100(
                    wantPaLo[i]) != i)
                    ++bad;
            for (int i = 1; i < 6; ++i)
                if (rules::parasiteAreaForD100(
                    wantPaLo[i] - 1) != i - 1)
                    ++bad;
            const int wantPaSevMildHi[] = {
                2, 2, 1, 1, 7, 2,
            };
            for (int i = 0; i < 6; ++i)
                if (rules::parasiteSeverityMildHi(i)
                    != wantPaSevMildHi[i])
                    ++bad;
            const int wantPaSevSevereHi[] = {
                5, 7, 3, 4, 8, 7,
            };
            for (int i = 0; i < 6; ++i)
                if (rules::parasiteSeveritySevereHi(i)
                    != wantPaSevSevereHi[i])
                    ++bad;
            const int wantPaSevTerminalHi[] = {
                8, 8, 8, 8, 0, 8,
            };
            for (int i = 0; i < 6; ++i)
                if (rules::parasiteSeverityTerminalHi(i)
                    != wantPaSevTerminalHi[i])
                    ++bad;
        }
        printf("R1051 parasite areas audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 5. seam ---------------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/dm_disease");
            {
                const items::MiscItemDef* d =
                    reg.find("dm_disease_areas");
                if (!d) ++bad;
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "acute_hi")
                            continue;
                        got = 1;
                        for (int i = 0; i < 16;
                             ++i)
                            if ((int)t.values[i] != rules::diseaseAcuteHi(i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "sev_mild_hi")
                            continue;
                        got = 1;
                        for (int i = 0; i < 16;
                             ++i)
                            if ((int)t.values[i] !=
                                rules::diseaseSeverityMildHi(i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "sev_severe_hi")
                            continue;
                        got = 1;
                        for (int i = 0; i < 16;
                             ++i)
                            if ((int)t.values[i] !=
                                rules::diseaseSeveritySevereHi(i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "sev_terminal_hi")
                            continue;
                        got = 1;
                        for (int i = 0; i < 16;
                             ++i)
                            if ((int)t.values[i] !=
                                rules::diseaseSeverityTerminalHi(i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "terminal_unit")
                            continue;
                        got = 1;
                        for (int i = 0; i < 16;
                             ++i)
                            if ((int)t.values[i] !=
                                rules::diseaseTerminalUnit(i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("dm_parasite_areas");
                if (!d) ++bad;
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "sev_mild_hi")
                            continue;
                        got = 1;
                        for (int i = 0; i < 6;
                             ++i)
                            if ((int)t.values[i] !=
                                rules::parasiteSeverityMildHi(i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "sev_severe_hi")
                            continue;
                        got = 1;
                        for (int i = 0; i < 6;
                             ++i)
                            if ((int)t.values[i] !=
                                rules::parasiteSeveritySevereHi(i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "sev_terminal_hi")
                            continue;
                        got = 1;
                        for (int i = 0; i < 6;
                             ++i)
                            if ((int)t.values[i] !=
                                rules::parasiteSeverityTerminalHi(i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
            }
        }
        printf("R1051 disease registry seam audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 6. edges --------------------------------
        {
            if (std::string(rules::diseaseAreaName(-1))
                != "blood/blood forming organs") ++bad;
            if (std::string(rules::diseaseAreaName(99))
                != "urinary system") ++bad;
            if (rules::diseaseAreaForD100(0) != 0) ++bad;
            if (rules::diseaseAreaForD100(101) != 15) ++bad;
            if (std::string(rules::parasiteAreaName(-1))
                != "cardiovascular system") ++bad;
            if (std::string(rules::parasiteAreaName(99))
                != "stomach") ++bad;
            if (rules::parasiteAreaForD100(0) != 0) ++bad;
            if (rules::parasiteAreaForD100(101) != 5) ++bad;
            if (!rules::diseaseIsAcute(0, rules::diseaseAcuteHi(0))) ++bad;
            if (rules::diseaseIsAcute(0, rules::diseaseAcuteHi(0) + 1)) ++bad;
            if (!rules::diseaseIsChronic(0, rules::diseaseAcuteHi(0) + 1))
                ++bad;
            if (rules::diseaseChronicLo(0) != rules::diseaseAcuteHi(0) + 1)
                ++bad;
            if (rules::diseaseHasTerminalColumn(9)) ++bad;
            if (rules::diseaseHasTerminalColumn(10)) ++bad;
            if (rules::diseaseHasTerminalColumn(12)) ++bad;
            if (!rules::diseaseHasTerminalColumn(0)) ++bad;
            if (!rules::diseaseHasTerminalColumn(15)) ++bad;
            if (rules::diseaseMildWeeksMin() != 1
                || rules::diseaseMildWeeksMax() != 3) ++bad;
        }
        printf("R1051 disease registry edges audit: bad %d\n", bad);
    }
