    // ---- R211: the NPC body and language audit ----
    // DMG pp.115-116: the height and weight
    // tables and determination bands, and the
    // random language table.
    {
        Npcbody npcbody;
        int bad = 0;
        // the averages and dice, every cell
        if (npcbody.npcBodyRaceCount() != 7) ++bad;
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
                if (npcbody.npcHeightAvgInches(f, r)
                        != kHAvg[f * 7 + r] ||
                    npcbody.npcWeightAvgPounds(f, r)
                        != kWAvg[f * 7 + r]) ++bad;
        for (int f = 0; f <= 1; ++f)
            for (int d = 0; d <= 1; ++d)
                for (int r = 0; r < 7; ++r)
                    if (npcbody.npcHeightDie(f, r, d)
                            != kHDice[f * 14 + d * 7 + r] ||
                        npcbody.npcWeightDie(f, r, d)
                            != kWDice[f * 14 + d * 7 + r]) ++bad;
        // the packing: count and sides
        if (npcbody.npcDieCount(212) != 2 ||
            npcbody.npcDieSides(212) != 12 ||
            npcbody.npcDieCount(410) != 4 ||
            npcbody.npcDieSides(410) != 10 ||
            npcbody.npcDieCount(512) != 5 ||
            npcbody.npcDieSides(512) != 12 ||
            npcbody.npcDieCount(120) != 1 ||
            npcbody.npcDieSides(120) != 20) ++bad;
        // the determination bands: the edges
        static const int kHUnder[7] = { 15, 10, 20, 35, 10, 45, 20 };
        static const int kHAvgE[7] = { 80, 80, 85, 90, 90, 75, 80 };
        static const int kWUnder[7] = { 20, 15, 20, 20, 10, 30, 25 };
        static const int kWAvgE[7] = { 65, 90, 75, 85, 50, 55, 75 };
        for (int r = 0; r < 7; ++r)
            if (npcbody.npcHeightBandUnderEdge(r)
                    != kHUnder[r] ||
                npcbody.npcHeightBandAvgEdge(r)
                    != kHAvgE[r] ||
                npcbody.npcWeightBandUnderEdge(r)
                    != kWUnder[r] ||
                npcbody.npcWeightBandAvgEdge(r)
                    != kWAvgE[r]) ++bad;
        // the class walk: edges and clamps
        if (npcbody.npcDetermineHeightClass(                NBR_DWARF, 15) != 0 ||
            npcbody.npcDetermineHeightClass(                NBR_DWARF, 16) != 1 ||
            npcbody.npcDetermineHeightClass(                NBR_DWARF, 80) != 1 ||
            npcbody.npcDetermineHeightClass(                NBR_DWARF, 81) != 2) ++bad;
        if (npcbody.npcDetermineHeightClass(                NBR_HALFORC, 45) != 0 ||
            npcbody.npcDetermineHeightClass(                NBR_HALFORC, 46) != 1 ||
            npcbody.npcDetermineHeightClass(                NBR_HALFORC, 75) != 1 ||
            npcbody.npcDetermineHeightClass(                NBR_HALFORC, 76) != 2) ++bad;
        if (npcbody.npcDetermineWeightClass(                NBR_HUMAN, 25) != 0 ||
            npcbody.npcDetermineWeightClass(                NBR_HUMAN, 26) != 1 ||
            npcbody.npcDetermineWeightClass(                NBR_HUMAN, 75) != 1 ||
            npcbody.npcDetermineWeightClass(                NBR_HUMAN, 76) != 2) ++bad;
        if (npcbody.npcDetermineHeightClass(                NBR_ELF, 10) != 0 ||
            npcbody.npcDetermineHeightClass(                NBR_ELF, 11) != 1 ||
            npcbody.npcDetermineWeightClass(                NBR_ELF, 15) != 0 ||
            npcbody.npcDetermineWeightClass(                NBR_ELF, 16) != 1 ||
            npcbody.npcDetermineWeightClass(                NBR_ELF, 90) != 1 ||
            npcbody.npcDetermineWeightClass(                NBR_ELF, 91) != 2) ++bad;
        if (npcbody.npcDetermineWeightClass(                NBR_HALFLING, 10) != 0 ||
            npcbody.npcDetermineWeightClass(                NBR_HALFLING, 11) != 1 ||
            npcbody.npcDetermineWeightClass(                NBR_HALFLING, 50) != 1 ||
            npcbody.npcDetermineWeightClass(                NBR_HALFLING, 51) != 2) ++bad;
        // the clamps: 0 reads under, 101 reads
        // over
        if (npcbody.npcDetermineHeightClass(                NBR_DWARF, 0) != 0 ||
            npcbody.npcDetermineHeightClass(                NBR_DWARF, 101) != 2) ++bad;
        // the language table: every face
        if (npcbody.npcLanguageKindCount() != 55) ++bad;
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
            if (npcbody.npcLanguageFor(d) != kLang[d - 1]) ++bad;
        // the language boundaries: each band
        // start and the kind codes
        if (npcbody.npcLanguageFor(1)
                != NPC_LG_BROWNIE ||
            npcbody.npcLanguageFor(2)
                != NPC_LG_BUGBEAR ||
            npcbody.npcLanguageFor(4)
                != NPC_LG_CENTAUR ||
            npcbody.npcLanguageFor(5)
                != NPC_LG_DRAGON_BLACK ||
            npcbody.npcLanguageFor(14)
                != NPC_LG_DRAGON_WHITE ||
            npcbody.npcLanguageFor(15)
                != NPC_LG_DRYAD ||
            npcbody.npcLanguageFor(16)
                != NPC_LG_DWARVISH ||
            npcbody.npcLanguageFor(21)
                != NPC_LG_ELVISH ||
            npcbody.npcLanguageFor(26)
                != NPC_LG_ETTIN ||
            npcbody.npcLanguageFor(28)
                != NPC_LG_GIANT_CLOUD ||
            npcbody.npcLanguageFor(31)
                != NPC_LG_GIANT_HILL_1 ||
            npcbody.npcLanguageFor(33)
                != NPC_LG_GIANT_HILL_3 ||
            npcbody.npcLanguageFor(35)
                != NPC_LG_GIANT_STORM ||
            npcbody.npcLanguageFor(36)
                != NPC_LG_GOBLIN ||
            npcbody.npcLanguageFor(40)
                != NPC_LG_GNOLL ||
            npcbody.npcLanguageFor(41)
                != NPC_LG_GNOME ||
            npcbody.npcLanguageFor(45)
                != NPC_LG_HALFLING ||
            npcbody.npcLanguageFor(50)
                != NPC_LG_HOBGOBLIN ||
            npcbody.npcLanguageFor(52)
                != NPC_LG_KOBOLD ||
            npcbody.npcLanguageFor(55)
                != NPC_LG_LAMMASU ||
            npcbody.npcLanguageFor(56)
                != NPC_LG_LIZARD_MAN ||
            npcbody.npcLanguageFor(59)
                != NPC_LG_MANTICORE ||
            npcbody.npcLanguageFor(60)
                != NPC_LG_MEDUSIAN ||
            npcbody.npcLanguageFor(61)
                != NPC_LG_MINOTAUR ||
            npcbody.npcLanguageFor(62)
                != NPC_LG_NAGA_GUARDIAN ||
            npcbody.npcLanguageFor(64)
                != NPC_LG_NAGA_WATER ||
            npcbody.npcLanguageFor(65)
                != NPC_LG_NIXIE ||
            npcbody.npcLanguageFor(66)
                != NPC_LG_NYMPH ||
            npcbody.npcLanguageFor(67)
                != NPC_LG_OGRISH ||
            npcbody.npcLanguageFor(71)
                != NPC_LG_OGRE_MAGIAN ||
            npcbody.npcLanguageFor(72)
                != NPC_LG_ORCISH ||
            npcbody.npcLanguageFor(77)
                != NPC_LG_PIXIE ||
            npcbody.npcLanguageFor(78)
                != NPC_LG_SALAMANDER ||
            npcbody.npcLanguageFor(79)
                != NPC_LG_SATYR ||
            npcbody.npcLanguageFor(80)
                != NPC_LG_SHEDU ||
            npcbody.npcLanguageFor(81)
                != NPC_LG_SPRITE ||
            npcbody.npcLanguageFor(82)
                != NPC_LG_SYLPH ||
            npcbody.npcLanguageFor(83)
                != NPC_LG_TITAN ||
            npcbody.npcLanguageFor(84)
                != NPC_LG_TROLL ||
            npcbody.npcLanguageFor(85)
                != NPC_LG_XORN ||
            npcbody.npcLanguageFor(86)
                != NPC_LG_HUMAN_FOREIGN ||
            npcbody.npcLanguageFor(100)
                != NPC_LG_HUMAN_FOREIGN) ++bad;
        // the language clamps
        if (npcbody.npcLanguageFor(0)
                != NPC_LG_BROWNIE ||
            npcbody.npcLanguageFor(101)
                != NPC_LG_HUMAN_FOREIGN) ++bad;
        printf("R211 NPC body and language audit: bad %d\n", bad);
        if (bad) return 1;
    }
