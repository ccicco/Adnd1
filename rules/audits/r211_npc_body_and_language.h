    // ---- R211: the NPC body and language audit ----
    // DMG pp.115-116: the height and weight
    // tables and determination bands, and the
    // random language table.
    {
        int bad = 0;
        // the averages and dice, every cell
        if (rules::npcBodyRaceCount() != 7) ++bad;
        static const int kHAvg[14] = {
            48, 60, 42, 66, 36, 66, 72,
            46, 54, 39, 62, 33, 62, 66,
        };
        static const int kWAvg[14] = {
            150, 100, 80, 130, 60, 150, 175,
            120, 80, 75, 100, 50, 120, 130,
        };
        static const int kHDice[28] = {
            104, 104, 103, 106, 103, 104, 112,
            106, 106, 103, 106, 106, 104, 112,
            104, 104, 103, 106, 103, 103, 106,
            104, 106, 103, 106, 103, 103, 108,
        };
        static const int kWDice[28] = {
            208, 110, 204, 120, 204, 208, 312,
            212, 120, 206, 120, 206, 410, 512,
            208, 110, 108, 112, 204, 306, 310,
            210, 206, 108, 208, 204, 408, 412,
        };
        for (int f = 0; f <= 1; ++f)
            for (int r = 0; r < 7; ++r)
                if (rules::npcHeightAvgInches(f, r)
                        != kHAvg[f * 7 + r] ||
                    rules::npcWeightAvgPounds(f, r)
                        != kWAvg[f * 7 + r]) ++bad;
        for (int f = 0; f <= 1; ++f)
            for (int d = 0; d <= 1; ++d)
                for (int r = 0; r < 7; ++r)
                    if (rules::npcHeightDie(f, r, d)
                            != kHDice[f * 14 + d * 7 + r] ||
                        rules::npcWeightDie(f, r, d)
                            != kWDice[f * 14 + d * 7 + r]) ++bad;
        // the packing: count and sides
        if (rules::npcDieCount(212) != 2 ||
            rules::npcDieSides(212) != 12 ||
            rules::npcDieCount(410) != 4 ||
            rules::npcDieSides(410) != 10 ||
            rules::npcDieCount(512) != 5 ||
            rules::npcDieSides(512) != 12 ||
            rules::npcDieCount(120) != 1 ||
            rules::npcDieSides(120) != 20) ++bad;
        // the determination bands: the edges
        static const int kHUnder[7] = { 15, 10, 20, 35, 10, 45, 20 };
        static const int kHAvgE[7] = { 80, 80, 85, 90, 90, 75, 80 };
        static const int kWUnder[7] = { 20, 15, 20, 20, 10, 30, 25 };
        static const int kWAvgE[7] = { 65, 90, 75, 85, 50, 55, 75 };
        for (int r = 0; r < 7; ++r)
            if (rules::npcHeightBandUnderEdge(r)
                    != kHUnder[r] ||
                rules::npcHeightBandAvgEdge(r)
                    != kHAvgE[r] ||
                rules::npcWeightBandUnderEdge(r)
                    != kWUnder[r] ||
                rules::npcWeightBandAvgEdge(r)
                    != kWAvgE[r]) ++bad;
        // the class walk: edges and clamps
        if (rules::npcDetermineHeightClass(                rules::NBR_DWARF, 15) != 0 ||
            rules::npcDetermineHeightClass(                rules::NBR_DWARF, 16) != 1 ||
            rules::npcDetermineHeightClass(                rules::NBR_DWARF, 80) != 1 ||
            rules::npcDetermineHeightClass(                rules::NBR_DWARF, 81) != 2) ++bad;
        if (rules::npcDetermineHeightClass(                rules::NBR_HALFORC, 45) != 0 ||
            rules::npcDetermineHeightClass(                rules::NBR_HALFORC, 46) != 1 ||
            rules::npcDetermineHeightClass(                rules::NBR_HALFORC, 75) != 1 ||
            rules::npcDetermineHeightClass(                rules::NBR_HALFORC, 76) != 2) ++bad;
        if (rules::npcDetermineWeightClass(                rules::NBR_HUMAN, 25) != 0 ||
            rules::npcDetermineWeightClass(                rules::NBR_HUMAN, 26) != 1 ||
            rules::npcDetermineWeightClass(                rules::NBR_HUMAN, 75) != 1 ||
            rules::npcDetermineWeightClass(                rules::NBR_HUMAN, 76) != 2) ++bad;
        if (rules::npcDetermineHeightClass(                rules::NBR_ELF, 10) != 0 ||
            rules::npcDetermineHeightClass(                rules::NBR_ELF, 11) != 1 ||
            rules::npcDetermineWeightClass(                rules::NBR_ELF, 15) != 0 ||
            rules::npcDetermineWeightClass(                rules::NBR_ELF, 16) != 1 ||
            rules::npcDetermineWeightClass(                rules::NBR_ELF, 90) != 1 ||
            rules::npcDetermineWeightClass(                rules::NBR_ELF, 91) != 2) ++bad;
        if (rules::npcDetermineWeightClass(                rules::NBR_HALFLING, 10) != 0 ||
            rules::npcDetermineWeightClass(                rules::NBR_HALFLING, 11) != 1 ||
            rules::npcDetermineWeightClass(                rules::NBR_HALFLING, 50) != 1 ||
            rules::npcDetermineWeightClass(                rules::NBR_HALFLING, 51) != 2) ++bad;
        // the clamps: 0 reads under, 101 reads
        // over
        if (rules::npcDetermineHeightClass(                rules::NBR_DWARF, 0) != 0 ||
            rules::npcDetermineHeightClass(                rules::NBR_DWARF, 101) != 2) ++bad;
        // the language table: every face
        if (rules::npcLanguageKindCount() != 55) ++bad;
        static const int kLang[100] = {
            0, 1, 1, 2,
            3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
            13,
            14, 14, 14, 14, 14,
            15, 15, 15, 15, 15,
            16,
            17,
            18, 19, 20, 21, 22, 23, 24, 25,
            26, 26, 26, 26,
            27,
            28, 28, 28, 28,
            29, 29, 29, 29, 29,
            30, 30,
            31, 31, 31,
            32,
            33, 33, 33,
            34,
            35,
            36,
            37, 38, 39,
            40,
            41,
            42, 42, 42, 42,
            43,
            44, 44, 44, 44, 44,
            45,
            46,
            47,
            48,
            49,
            50,
            51,
            52,
            53,
            54, 54, 54, 54, 54, 54, 54, 54,
            54, 54, 54, 54, 54, 54, 54,
        };
        for (int d = 1; d <= 100; ++d)
            if (rules::npcLanguageFor(d) != kLang[d - 1]) ++bad;
        // the language boundaries: each band
        // start and the kind codes
        if (rules::npcLanguageFor(1)
                != rules::NPC_LG_BROWNIE ||
            rules::npcLanguageFor(2)
                != rules::NPC_LG_BUGBEAR ||
            rules::npcLanguageFor(4)
                != rules::NPC_LG_CENTAUR ||
            rules::npcLanguageFor(5)
                != rules::NPC_LG_DRAGON_BLACK ||
            rules::npcLanguageFor(14)
                != rules::NPC_LG_DRAGON_WHITE ||
            rules::npcLanguageFor(15)
                != rules::NPC_LG_DRYAD ||
            rules::npcLanguageFor(16)
                != rules::NPC_LG_DWARVISH ||
            rules::npcLanguageFor(21)
                != rules::NPC_LG_ELVISH ||
            rules::npcLanguageFor(26)
                != rules::NPC_LG_ETTIN ||
            rules::npcLanguageFor(28)
                != rules::NPC_LG_GIANT_CLOUD ||
            rules::npcLanguageFor(31)
                != rules::NPC_LG_GIANT_HILL_1 ||
            rules::npcLanguageFor(33)
                != rules::NPC_LG_GIANT_HILL_3 ||
            rules::npcLanguageFor(35)
                != rules::NPC_LG_GIANT_STORM ||
            rules::npcLanguageFor(36)
                != rules::NPC_LG_GOBLIN ||
            rules::npcLanguageFor(40)
                != rules::NPC_LG_GNOLL ||
            rules::npcLanguageFor(41)
                != rules::NPC_LG_GNOME ||
            rules::npcLanguageFor(45)
                != rules::NPC_LG_HALFLING ||
            rules::npcLanguageFor(50)
                != rules::NPC_LG_HOBGOBLIN ||
            rules::npcLanguageFor(52)
                != rules::NPC_LG_KOBOLD ||
            rules::npcLanguageFor(55)
                != rules::NPC_LG_LAMMASU ||
            rules::npcLanguageFor(56)
                != rules::NPC_LG_LIZARD_MAN ||
            rules::npcLanguageFor(59)
                != rules::NPC_LG_MANTICORE ||
            rules::npcLanguageFor(60)
                != rules::NPC_LG_MEDUSIAN ||
            rules::npcLanguageFor(61)
                != rules::NPC_LG_MINOTAUR ||
            rules::npcLanguageFor(62)
                != rules::NPC_LG_NAGA_GUARDIAN ||
            rules::npcLanguageFor(64)
                != rules::NPC_LG_NAGA_WATER ||
            rules::npcLanguageFor(65)
                != rules::NPC_LG_NIXIE ||
            rules::npcLanguageFor(66)
                != rules::NPC_LG_NYMPH ||
            rules::npcLanguageFor(67)
                != rules::NPC_LG_OGRISH ||
            rules::npcLanguageFor(71)
                != rules::NPC_LG_OGRE_MAGIAN ||
            rules::npcLanguageFor(72)
                != rules::NPC_LG_ORCISH ||
            rules::npcLanguageFor(77)
                != rules::NPC_LG_PIXIE ||
            rules::npcLanguageFor(78)
                != rules::NPC_LG_SALAMANDER ||
            rules::npcLanguageFor(79)
                != rules::NPC_LG_SATYR ||
            rules::npcLanguageFor(80)
                != rules::NPC_LG_SHEDU ||
            rules::npcLanguageFor(81)
                != rules::NPC_LG_SPRITE ||
            rules::npcLanguageFor(82)
                != rules::NPC_LG_SYLPH ||
            rules::npcLanguageFor(83)
                != rules::NPC_LG_TITAN ||
            rules::npcLanguageFor(84)
                != rules::NPC_LG_TROLL ||
            rules::npcLanguageFor(85)
                != rules::NPC_LG_XORN ||
            rules::npcLanguageFor(86)
                != rules::NPC_LG_HUMAN_FOREIGN ||
            rules::npcLanguageFor(100)
                != rules::NPC_LG_HUMAN_FOREIGN) ++bad;
        // the language clamps
        if (rules::npcLanguageFor(0)
                != rules::NPC_LG_BROWNIE ||
            rules::npcLanguageFor(101)
                != rules::NPC_LG_HUMAN_FOREIGN) ++bad;
        printf("R211 NPC body and language audit: bad %d\n", bad);
        if (bad) return 1;
    }
