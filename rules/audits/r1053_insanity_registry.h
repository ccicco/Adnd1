    // ==== R1053: insanity registry ==========
    // The R1053 de-wire: the 14 int arrays
    // and the 21-string name array of
    // rules/dmg/insanity.h ride items::
    // MiscItemRegistry from content/tables/
    // dm_insanity/ (2 defs: state + form
    // rows, named tables; the mania grid
    // keeps its dead index 0, the name
    // array retires onto the rows). Six
    // sections: load, counts, the two
    // defs, seam, edges. Census 1076 ->
    // 1082. DO NOT hand-edit:
    // tools/r1053_splice.py is the only
    // writer.
    {
        int bad = 0;
        // -- 1. load ---------------------------------
        {
            items::MiscItemRegistry reg;
            int n = reg.loadDirectory(
                "content/tables/dm_insanity");
            if (n != 2) ++bad;
            if (!reg.errors().empty()) ++bad;
            for (const auto& kv : reg.all())
                if ((int)kv.second.sources.size() != 1
                    || kv.second.sources[0].second != 1053)
                    ++bad;
            if (!reg.find("dm_intoxication")) ++bad;
            if (!reg.find("dm_insanity")) ++bad;
        }
        printf("R1053 insanity registry load audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 2. counts --------------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/dm_insanity");
            {
                const items::MiscItemDef* d =
                    reg.find("dm_intoxication");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 5
                        || (int)d->pins.size() != 1
                        || d->pins[0].name != "dm_intoxicationRowCount"
                        || d->pins[0].value != 5
                        || (int)d->tables.size() != 13)
                        ++bad;
                    if (d->tables[0].name
                        != "bravery_adjust"
                        || (int)d->tables[0]
                            .values.size() != 5)
                        ++bad;
                    if (d->tables[1].name
                        != "morale_adjust"
                        || (int)d->tables[1]
                            .values.size() != 5)
                        ++bad;
                    if (d->tables[2].name
                        != "intelligence_adjust"
                        || (int)d->tables[2]
                            .values.size() != 5)
                        ++bad;
                    if (d->tables[3].name
                        != "wisdom_adjust"
                        || (int)d->tables[3]
                            .values.size() != 5)
                        ++bad;
                    if (d->tables[4].name
                        != "dexterity_adjust"
                        || (int)d->tables[4]
                            .values.size() != 5)
                        ++bad;
                    if (d->tables[5].name
                        != "charisma_adjust"
                        || (int)d->tables[5]
                            .values.size() != 5)
                        ++bad;
                    if (d->tables[6].name
                        != "attack_dice_adjust"
                        || (int)d->tables[6]
                            .values.size() != 5)
                        ++bad;
                    if (d->tables[7].name
                        != "hit_point_adjust"
                        || (int)d->tables[7]
                            .values.size() != 5)
                        ++bad;
                    if (d->tables[8].name
                        != "magic_save_raise_percent"
                        || (int)d->tables[8]
                            .values.size() != 5)
                        ++bad;
                    if (d->tables[9].name
                        != "recovery_min_hours"
                        || (int)d->tables[9]
                            .values.size() != 5)
                        ++bad;
                    if (d->tables[10].name
                        != "recovery_max_hours"
                        || (int)d->tables[10]
                            .values.size() != 5)
                        ++bad;
                    if (d->tables[11].name
                        != "stimulant_mild_percent"
                        || (int)d->tables[11]
                            .values.size() != 5)
                        ++bad;
                    if (d->tables[12].name
                        != "stimulant_strong_percent"
                        || (int)d->tables[12]
                            .values.size() != 5)
                        ++bad;
                    if (d->rows[0].set
                        != "dm_intoxication"
                        || d->rows[0].bandLo != 0
                        || d->rows[0].bandHi != 0)
                        ++bad;
                    if (d->rows[1].set
                        != "dm_intoxication"
                        || d->rows[1].bandLo != 1
                        || d->rows[1].bandHi != 1)
                        ++bad;
                    if (d->rows[2].set
                        != "dm_intoxication"
                        || d->rows[2].bandLo != 2
                        || d->rows[2].bandHi != 2)
                        ++bad;
                    if (d->rows[3].set
                        != "dm_intoxication"
                        || d->rows[3].bandLo != 3
                        || d->rows[3].bandHi != 3)
                        ++bad;
                    if (d->rows[4].set
                        != "dm_intoxication"
                        || d->rows[4].bandLo != 4
                        || d->rows[4].bandHi != 4)
                        ++bad;
                    if (std::string(
                        d->rows[0].name)
                        != "sober")
                        ++bad;
                    if (std::string(
                        d->rows[1].name)
                        != "slight")
                        ++bad;
                    if (std::string(
                        d->rows[2].name)
                        != "moderate")
                        ++bad;
                    if (std::string(
                        d->rows[3].name)
                        != "great")
                        ++bad;
                    if (std::string(
                        d->rows[4].name)
                        != "comatose")
                        ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("dm_insanity");
                if (!d) { ++bad; } else {
                    if ((int)d->rows.size() != 20
                        || (int)d->pins.size() != 1
                        || d->pins[0].name != "dm_insanityRowCount"
                        || d->pins[0].value != 20
                        || (int)d->tables.size() != 1)
                        ++bad;
                    if (d->tables[0].name
                        != "mania_strength_state"
                        || (int)d->tables[0]
                            .values.size() != 7)
                        ++bad;
                    if (d->rows[0].set
                        != "dm_insanity"
                        || d->rows[0].bandLo != 0
                        || d->rows[0].bandHi != 0)
                        ++bad;
                    if (d->rows[1].set
                        != "dm_insanity"
                        || d->rows[1].bandLo != 1
                        || d->rows[1].bandHi != 1)
                        ++bad;
                    if (d->rows[2].set
                        != "dm_insanity"
                        || d->rows[2].bandLo != 2
                        || d->rows[2].bandHi != 2)
                        ++bad;
                    if (d->rows[3].set
                        != "dm_insanity"
                        || d->rows[3].bandLo != 3
                        || d->rows[3].bandHi != 3)
                        ++bad;
                    if (d->rows[4].set
                        != "dm_insanity"
                        || d->rows[4].bandLo != 4
                        || d->rows[4].bandHi != 4)
                        ++bad;
                    if (d->rows[5].set
                        != "dm_insanity"
                        || d->rows[5].bandLo != 5
                        || d->rows[5].bandHi != 5)
                        ++bad;
                    if (d->rows[6].set
                        != "dm_insanity"
                        || d->rows[6].bandLo != 6
                        || d->rows[6].bandHi != 6)
                        ++bad;
                    if (d->rows[7].set
                        != "dm_insanity"
                        || d->rows[7].bandLo != 7
                        || d->rows[7].bandHi != 7)
                        ++bad;
                    if (d->rows[8].set
                        != "dm_insanity"
                        || d->rows[8].bandLo != 8
                        || d->rows[8].bandHi != 8)
                        ++bad;
                    if (d->rows[9].set
                        != "dm_insanity"
                        || d->rows[9].bandLo != 9
                        || d->rows[9].bandHi != 9)
                        ++bad;
                    if (d->rows[10].set
                        != "dm_insanity"
                        || d->rows[10].bandLo != 10
                        || d->rows[10].bandHi != 10)
                        ++bad;
                    if (d->rows[11].set
                        != "dm_insanity"
                        || d->rows[11].bandLo != 11
                        || d->rows[11].bandHi != 11)
                        ++bad;
                    if (d->rows[12].set
                        != "dm_insanity"
                        || d->rows[12].bandLo != 12
                        || d->rows[12].bandHi != 12)
                        ++bad;
                    if (d->rows[13].set
                        != "dm_insanity"
                        || d->rows[13].bandLo != 13
                        || d->rows[13].bandHi != 13)
                        ++bad;
                    if (d->rows[14].set
                        != "dm_insanity"
                        || d->rows[14].bandLo != 14
                        || d->rows[14].bandHi != 14)
                        ++bad;
                    if (d->rows[15].set
                        != "dm_insanity"
                        || d->rows[15].bandLo != 15
                        || d->rows[15].bandHi != 15)
                        ++bad;
                    if (d->rows[16].set
                        != "dm_insanity"
                        || d->rows[16].bandLo != 16
                        || d->rows[16].bandHi != 16)
                        ++bad;
                    if (d->rows[17].set
                        != "dm_insanity"
                        || d->rows[17].bandLo != 17
                        || d->rows[17].bandHi != 17)
                        ++bad;
                    if (d->rows[18].set
                        != "dm_insanity"
                        || d->rows[18].bandLo != 18
                        || d->rows[18].bandHi != 18)
                        ++bad;
                    if (d->rows[19].set
                        != "dm_insanity"
                        || d->rows[19].bandLo != 19
                        || d->rows[19].bandHi != 19)
                        ++bad;
                    if (std::string(
                        d->rows[0].name)
                        != "dipsomania")
                        ++bad;
                    if (std::string(
                        d->rows[1].name)
                        != "kleptomania")
                        ++bad;
                    if (std::string(
                        d->rows[2].name)
                        != "schizoid")
                        ++bad;
                    if (std::string(
                        d->rows[3].name)
                        != "pathological liar")
                        ++bad;
                    if (std::string(
                        d->rows[4].name)
                        != "monomania")
                        ++bad;
                    if (std::string(
                        d->rows[5].name)
                        != "dementia praecox")
                        ++bad;
                    if (std::string(
                        d->rows[6].name)
                        != "melancholia")
                        ++bad;
                    if (std::string(
                        d->rows[7].name)
                        != "megalomania")
                        ++bad;
                    if (std::string(
                        d->rows[8].name)
                        != "delusional insanity")
                        ++bad;
                    if (std::string(
                        d->rows[9].name)
                        != "schizophrenia")
                        ++bad;
                    if (std::string(
                        d->rows[10].name)
                        != "mania")
                        ++bad;
                    if (std::string(
                        d->rows[11].name)
                        != "lunacy")
                        ++bad;
                    if (std::string(
                        d->rows[12].name)
                        != "paranoia")
                        ++bad;
                    if (std::string(
                        d->rows[13].name)
                        != "manic-depressive")
                        ++bad;
                    if (std::string(
                        d->rows[14].name)
                        != "hallucinatory insanity")
                        ++bad;
                    if (std::string(
                        d->rows[15].name)
                        != "sado-masochism")
                        ++bad;
                    if (std::string(
                        d->rows[16].name)
                        != "homicidal mania")
                        ++bad;
                    if (std::string(
                        d->rows[17].name)
                        != "hebephrenia")
                        ++bad;
                    if (std::string(
                        d->rows[18].name)
                        != "suicidal mania")
                        ++bad;
                    if (std::string(
                        d->rows[19].name)
                        != "catatonia")
                        ++bad;
                }
            }
        }
        printf("R1053 insanity registry counts audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 3. dm_intoxication ----
        {
            const int wantTiBraveryAdjust[] = {
                0, 1, 2, 4, 0,
            };
            for (int i = 0; i < 5; ++i)
                if (rules::intoxicationBraveryAdjust(
                    (rules::IntoxState)i)
                    != wantTiBraveryAdjust[i])
                    ++bad;
            const int wantTiMoraleAdjust[] = {
                0, 5, 10, 15, 0,
            };
            for (int i = 0; i < 5; ++i)
                if (rules::intoxicationMoraleAdjust(
                    (rules::IntoxState)i)
                    != wantTiMoraleAdjust[i])
                    ++bad;
            const int wantTiIntelligenceAdjust[] = {
                0, -1, -3, -6, 0,
            };
            for (int i = 0; i < 5; ++i)
                if (rules::intoxicationIntelligenceAdjust(
                    (rules::IntoxState)i)
                    != wantTiIntelligenceAdjust[i])
                    ++bad;
            const int wantTiWisdomAdjust[] = {
                0, -1, -4, -7, 0,
            };
            for (int i = 0; i < 5; ++i)
                if (rules::intoxicationWisdomAdjust(
                    (rules::IntoxState)i)
                    != wantTiWisdomAdjust[i])
                    ++bad;
            const int wantTiDexterityAdjust[] = {
                0, 0, -2, -5, 0,
            };
            for (int i = 0; i < 5; ++i)
                if (rules::intoxicationDexterityAdjust(
                    (rules::IntoxState)i)
                    != wantTiDexterityAdjust[i])
                    ++bad;
            const int wantTiCharismaAdjust[] = {
                0, 0, -1, -4, 0,
            };
            for (int i = 0; i < 5; ++i)
                if (rules::intoxicationCharismaAdjust(
                    (rules::IntoxState)i)
                    != wantTiCharismaAdjust[i])
                    ++bad;
            const int wantTiAttackDiceAdjust[] = {
                0, 0, -1, -5, 0,
            };
            for (int i = 0; i < 5; ++i)
                if (rules::intoxicationAttackDiceAdjust(
                    (rules::IntoxState)i)
                    != wantTiAttackDiceAdjust[i])
                    ++bad;
            const int wantTiHitPointAdjust[] = {
                0, 0, 1, 3, 0,
            };
            for (int i = 0; i < 5; ++i)
                if (rules::intoxicationHitPointAdjust(
                    (rules::IntoxState)i)
                    != wantTiHitPointAdjust[i])
                    ++bad;
            const int wantTiMagicSaveRaisePercent[] = {
                0, 0, 5, 25, 0,
            };
            for (int i = 0; i < 5; ++i)
                if (rules::intoxicationMagicSaveRaisePercent(
                    (rules::IntoxState)i)
                    != wantTiMagicSaveRaisePercent[i])
                    ++bad;
            const int wantTiRecoveryMinHours[] = {
                0, 1, 2, 4, 7,
            };
            for (int i = 0; i < 5; ++i)
                if (rules::intoxicationRecoveryMin(
                    (rules::IntoxState)i)
                    != wantTiRecoveryMinHours[i])
                    ++bad;
            const int wantTiRecoveryMaxHours[] = {
                0, 2, 4, 6, 10,
            };
            for (int i = 0; i < 5; ++i)
                if (rules::intoxicationRecoveryMax(
                    (rules::IntoxState)i)
                    != wantTiRecoveryMaxHours[i])
                    ++bad;
            const int wantTiStimulantMildPercent[] = {
                100, 80, 85, 90, 95,
            };
            for (int i = 0; i < 5; ++i)
                if (rules::intoxicationStimulantPercent(
                    (rules::IntoxState)i, false)
                    != wantTiStimulantMildPercent[i])
                    ++bad;
            const int wantTiStimulantStrongPercent[] = {
                100, 50, 55, 55, 60,
            };
            for (int i = 0; i < 5; ++i)
                if (rules::intoxicationStimulantPercent(
                    (rules::IntoxState)i, true)
                    != wantTiStimulantStrongPercent[i])
                    ++bad;
        }
        printf("R1053 intoxication states audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 4. dm_insanity ----
        {
            if (std::string(
                rules::insanityName(1))
                != "dipsomania")
                ++bad;
            if (std::string(
                rules::insanityName(2))
                != "kleptomania")
                ++bad;
            if (std::string(
                rules::insanityName(3))
                != "schizoid")
                ++bad;
            if (std::string(
                rules::insanityName(4))
                != "pathological liar")
                ++bad;
            if (std::string(
                rules::insanityName(5))
                != "monomania")
                ++bad;
            if (std::string(
                rules::insanityName(6))
                != "dementia praecox")
                ++bad;
            if (std::string(
                rules::insanityName(7))
                != "melancholia")
                ++bad;
            if (std::string(
                rules::insanityName(8))
                != "megalomania")
                ++bad;
            if (std::string(
                rules::insanityName(9))
                != "delusional insanity")
                ++bad;
            if (std::string(
                rules::insanityName(10))
                != "schizophrenia")
                ++bad;
            if (std::string(
                rules::insanityName(11))
                != "mania")
                ++bad;
            if (std::string(
                rules::insanityName(12))
                != "lunacy")
                ++bad;
            if (std::string(
                rules::insanityName(13))
                != "paranoia")
                ++bad;
            if (std::string(
                rules::insanityName(14))
                != "manic-depressive")
                ++bad;
            if (std::string(
                rules::insanityName(15))
                != "hallucinatory insanity")
                ++bad;
            if (std::string(
                rules::insanityName(16))
                != "sado-masochism")
                ++bad;
            if (std::string(
                rules::insanityName(17))
                != "homicidal mania")
                ++bad;
            if (std::string(
                rules::insanityName(18))
                != "hebephrenia")
                ++bad;
            if (std::string(
                rules::insanityName(19))
                != "suicidal mania")
                ++bad;
            if (std::string(
                rules::insanityName(20))
                != "catatonia")
                ++bad;
            const int wantTaManiaStrength[] = {
                50, 75, 100, 100, 100, 100,
            };
            for (int i = 1; i <= 6; ++i)
                if (rules::insanityManiaStrengthState(i)
                    != wantTaManiaStrength[i - 1])
                    ++bad;
        }
        printf("R1053 insanity types audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 5. seam ---------------------------------
        {
            items::MiscItemRegistry reg;
            reg.loadDirectory(
                "content/tables/dm_insanity");
            {
                const items::MiscItemDef* d =
                    reg.find("dm_intoxication");
                if (!d) ++bad;
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "bravery_adjust")
                            continue;
                        got = 1;
                        for (int i = 0; i < 5;
                             ++i)
                            if ((int)t.values[i] !=
                                rules::intoxicationBraveryAdjust(
                                    (rules::IntoxState)i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "morale_adjust")
                            continue;
                        got = 1;
                        for (int i = 0; i < 5;
                             ++i)
                            if ((int)t.values[i] !=
                                rules::intoxicationMoraleAdjust(
                                    (rules::IntoxState)i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "intelligence_adjust")
                            continue;
                        got = 1;
                        for (int i = 0; i < 5;
                             ++i)
                            if ((int)t.values[i] !=
                                rules::intoxicationIntelligenceAdjust(
                                    (rules::IntoxState)i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "wisdom_adjust")
                            continue;
                        got = 1;
                        for (int i = 0; i < 5;
                             ++i)
                            if ((int)t.values[i] !=
                                rules::intoxicationWisdomAdjust(
                                    (rules::IntoxState)i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "dexterity_adjust")
                            continue;
                        got = 1;
                        for (int i = 0; i < 5;
                             ++i)
                            if ((int)t.values[i] !=
                                rules::intoxicationDexterityAdjust(
                                    (rules::IntoxState)i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "charisma_adjust")
                            continue;
                        got = 1;
                        for (int i = 0; i < 5;
                             ++i)
                            if ((int)t.values[i] !=
                                rules::intoxicationCharismaAdjust(
                                    (rules::IntoxState)i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "attack_dice_adjust")
                            continue;
                        got = 1;
                        for (int i = 0; i < 5;
                             ++i)
                            if ((int)t.values[i] !=
                                rules::intoxicationAttackDiceAdjust(
                                    (rules::IntoxState)i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "hit_point_adjust")
                            continue;
                        got = 1;
                        for (int i = 0; i < 5;
                             ++i)
                            if ((int)t.values[i] !=
                                rules::intoxicationHitPointAdjust(
                                    (rules::IntoxState)i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "magic_save_raise_percent")
                            continue;
                        got = 1;
                        for (int i = 0; i < 5;
                             ++i)
                            if ((int)t.values[i] !=
                                rules::intoxicationMagicSaveRaisePercent(
                                    (rules::IntoxState)i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "recovery_min_hours")
                            continue;
                        got = 1;
                        for (int i = 0; i < 5;
                             ++i)
                            if ((int)t.values[i] !=
                                rules::intoxicationRecoveryMin(
                                    (rules::IntoxState)i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "recovery_max_hours")
                            continue;
                        got = 1;
                        for (int i = 0; i < 5;
                             ++i)
                            if ((int)t.values[i] !=
                                rules::intoxicationRecoveryMax(
                                    (rules::IntoxState)i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "stimulant_mild_percent")
                            continue;
                        got = 1;
                        for (int i = 0; i < 5;
                             ++i)
                            if ((int)t.values[i] !=
                                rules::intoxicationStimulantPercent(
                                    (rules::IntoxState)i,
                                false))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "stimulant_strong_percent")
                            continue;
                        got = 1;
                        for (int i = 0; i < 5;
                             ++i)
                            if ((int)t.values[i] !=
                                rules::intoxicationStimulantPercent(
                                    (rules::IntoxState)i,
                                true))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
            }
            {
                const items::MiscItemDef* d =
                    reg.find("dm_insanity");
                if (!d) ++bad;
                {
                    int got = 0;
                    for (const auto& t : d->tables) {
                        if (t.name != "mania_strength_state")
                            continue;
                        got = 1;
                        if ((int)t.values.size() != 7)
                            ++bad;
                        if ((int)t.values.size() > 0
                            && (int)t.values[0] != 0)
                            ++bad;
                        for (int i = 1; i <= 6; ++i)
                            if ((int)t.values[i] !=
                                rules::insanityManiaStrengthState(i))
                                ++bad;
                    }
                    if (!got) ++bad;
                }
                for (int i = 0; i < 20;
                     ++i)
                    if (d->rows[i].name !=
                        rules::insanityName(i + 1))
                        ++bad;
            }
        }
        printf("R1053 insanity registry seam audit: bad %d\n", bad);
        if (bad) return 1;
        bad = 0;
        // -- 6. edges --------------------------------
        {
            if (rules::intoxicationClamp(
                (rules::IntoxState)-1)
                != rules::INTOX_SOBER)
                ++bad;
            if (rules::intoxicationClamp(
                (rules::IntoxState)9)
                != rules::INTOX_COMATOSE)
                ++bad;
            if (rules::intoxicationBraveryAdjust(
                (rules::IntoxState)-1)
                != 0)
                ++bad;
            if (rules::intoxicationBraveryAdjust(
                (rules::IntoxState)9)
                != 0)
                ++bad;
            if (rules::intoxicationMoraleAdjust(
                (rules::IntoxState)-1)
                != 0)
                ++bad;
            if (rules::intoxicationMoraleAdjust(
                (rules::IntoxState)9)
                != 0)
                ++bad;
            if (rules::intoxicationIntelligenceAdjust(
                (rules::IntoxState)-1)
                != 0)
                ++bad;
            if (rules::intoxicationIntelligenceAdjust(
                (rules::IntoxState)9)
                != 0)
                ++bad;
            if (rules::intoxicationWisdomAdjust(
                (rules::IntoxState)-1)
                != 0)
                ++bad;
            if (rules::intoxicationWisdomAdjust(
                (rules::IntoxState)9)
                != 0)
                ++bad;
            if (rules::intoxicationDexterityAdjust(
                (rules::IntoxState)-1)
                != 0)
                ++bad;
            if (rules::intoxicationDexterityAdjust(
                (rules::IntoxState)9)
                != 0)
                ++bad;
            if (rules::intoxicationCharismaAdjust(
                (rules::IntoxState)-1)
                != 0)
                ++bad;
            if (rules::intoxicationCharismaAdjust(
                (rules::IntoxState)9)
                != 0)
                ++bad;
            if (rules::intoxicationAttackDiceAdjust(
                (rules::IntoxState)-1)
                != 0)
                ++bad;
            if (rules::intoxicationAttackDiceAdjust(
                (rules::IntoxState)9)
                != 0)
                ++bad;
            if (rules::intoxicationHitPointAdjust(
                (rules::IntoxState)-1)
                != 0)
                ++bad;
            if (rules::intoxicationHitPointAdjust(
                (rules::IntoxState)9)
                != 0)
                ++bad;
            if (rules::intoxicationMagicSaveRaisePercent(
                (rules::IntoxState)-1)
                != 0)
                ++bad;
            if (rules::intoxicationMagicSaveRaisePercent(
                (rules::IntoxState)9)
                != 0)
                ++bad;
            if (rules::intoxicationRecoveryMin(
                (rules::IntoxState)-1)
                != 0)
                ++bad;
            if (rules::intoxicationRecoveryMin(
                (rules::IntoxState)9)
                != 7)
                ++bad;
            if (rules::intoxicationRecoveryMax(
                (rules::IntoxState)-1)
                != 0)
                ++bad;
            if (rules::intoxicationRecoveryMax(
                (rules::IntoxState)9)
                != 10)
                ++bad;
            if (rules::intoxicationStimulantPercent(
                (rules::IntoxState)-1,
                false) != 100)
                ++bad;
            if (rules::intoxicationStimulantPercent(
                (rules::IntoxState)9,
                false) != 95)
                ++bad;
            if (rules::intoxicationStimulantPercent(
                (rules::IntoxState)-1,
                true) != 100)
                ++bad;
            if (rules::intoxicationStimulantPercent(
                (rules::IntoxState)9,
                true) != 60)
                ++bad;
            if (rules::insanityManiaStrengthState(0) != 50) ++bad;
            if (rules::insanityManiaStrengthState(1) != 50) ++bad;
            if (rules::insanityManiaStrengthState(6) != 100) ++bad;
            if (rules::insanityManiaStrengthState(7) != 100) ++bad;
            if (std::string(
                rules::insanityName(0))
                != "dipsomania")
                ++bad;
            if (std::string(
                rules::insanityName(21))
                != "catatonia")
                ++bad;
            if (rules::insanityIsMild(0))
                ++bad;
            if (!rules::insanityIsMild(1))
                ++bad;
            if (!rules::insanityIsMild(4))
                ++bad;
            if (rules::insanityIsMild(5))
                ++bad;
            if (rules::insanityIsMild(21))
                ++bad;
            if (rules::intoxicationMagicSaveRaise(
                (rules::IntoxState)0) != 0)
                ++bad;
            if (rules::intoxicationMagicSaveRaise(
                (rules::IntoxState)1) != 0)
                ++bad;
            if (rules::intoxicationMagicSaveRaise(
                (rules::IntoxState)2) != 1)
                ++bad;
            if (rules::intoxicationMagicSaveRaise(
                (rules::IntoxState)3) != 5)
                ++bad;
            if (rules::intoxicationMagicSaveRaise(
                (rules::IntoxState)4) != 0)
                ++bad;
            if (rules::intoxicationComatoseSleepMin() != 7)
                ++bad;
            if (rules::intoxicationComatoseSleepMax() != 10)
                ++bad;
            if (rules::intoxicationStrongStimulantConChance() != 5)
                ++bad;
            if (rules::intoxicationStrongStimulantConLoss() != 1)
                ++bad;
            if (rules::insanityTemporaryWeeksMin() != 2)
                ++bad;
            if (rules::insanityTemporaryWeeksMax() != 12)
                ++bad;
            if (rules::insanityMildWeeksMin() != 1)
                ++bad;
            if (rules::insanityMildWeeksMax() != 4)
                ++bad;
            if (rules::insanityDipsomaniaContinueNearAlcohol() != 50)
                ++bad;
            if (rules::insanityDipsomaniaContinueOtherwise() != 10)
                ++bad;
            if (rules::insanityKleptomaniaSeenChance() != 90)
                ++bad;
            if (rules::insanityKleptomaniaThiefPenalty() != -10)
                ++bad;
            if (rules::insanityDementiaPraecoxIgnoreChance() != 25)
                ++bad;
            if (rules::insanityMelancholiaIgnoreChance() != 50)
                ++bad;
            if (rules::insanitySchizophreniaPersonalitiesMin() != 1)
                ++bad;
            if (rules::insanitySchizophreniaPersonalitiesMax() != 4)
                ++bad;
            if (rules::insanityOnsetChanceIn6() != 1)
                ++bad;
            if (rules::insanityManiaDurationMinTurns() != 2)
                ++bad;
            if (rules::insanityManiaDurationMaxTurns() != 12)
                ++bad;
            if (rules::insanityManicDepressiveCycleMinDays() != 1)
                ++bad;
            if (rules::insanityManicDepressiveCycleMaxDays() != 4)
                ++bad;
            if (rules::insanityManicDepressiveFlipChance() != 90)
                ++bad;
            if (rules::insanityHallucinatoryNormalChance() != 50)
                ++bad;
            if (rules::insanityHallucinatoryDurationMinTurns() != 1)
                ++bad;
            if (rules::insanityHallucinatoryDurationMaxTurns() != 20)
                ++bad;
            if (rules::insanitySadoMasoNormalMinDays() != 1)
                ++bad;
            if (rules::insanitySadoMasoNormalMaxDays() != 3)
                ++bad;
            if (rules::insanityHomicidalIntervalMinDays() != 1)
                ++bad;
            if (rules::insanityHomicidalIntervalMaxDays() != 4)
                ++bad;
            if (rules::insanityHomicidalMelancholiaMinDays() != 1)
                ++bad;
            if (rules::insanityHomicidalMelancholiaMaxDays() != 6)
                ++bad;
            if (rules::insanityHebephreniaEnrageChance() != 75)
                ++bad;
            if (rules::insanityHebephreniaCatatonicMinHours() != 1)
                ++bad;
            if (rules::insanityHebephreniaCatatonicMaxHours() != 6)
                ++bad;
            if (rules::insanitySuicidalScaleMin() != 10)
                ++bad;
            if (rules::insanitySuicidalScaleMax() != 80)
                ++bad;
            if (rules::insanitySuicidalManiaMinTurns() != 2)
                ++bad;
            if (rules::insanitySuicidalManiaMaxTurns() != 8)
                ++bad;
            if (rules::insanitySuicidalMelancholyMinDays() != 2)
                ++bad;
            if (rules::insanitySuicidalMelancholyMaxDays() != 12)
                ++bad;
            if (rules::insanityCatatoniaReactionChance() != 1)
                ++bad;
        }
        printf("R1053 insanity registry edges audit: bad %d\n", bad);
    }
