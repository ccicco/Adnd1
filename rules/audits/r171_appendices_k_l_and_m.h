    // ---- R171: appendices K L and M audit -------------
    // DMG pp.221-224: the substance word lists, the
    // conjured animals table and the summoned monsters
    // tables, cell by cell (the trusted-compilation
    // judgments recorded in the gap report).
    {
        int bad = 0;
        // Appendix K: the appearance list
        static const char* kApp[10] = {
            "bubbling", "cloudy", "effervescent",
            "fuming", "oily", "smoky", "syrupy",
            "vaporous", "viscous", "watery"
        };
        if (rules::klmAppearanceCount() != 10) ++bad;
        for (int i = 0; i < 10; ++i)
            if (std::string(rules::klmAppearance(i))
                    != kApp[i])
                ++bad;
        // the transparency list with parentheticals
        static const char* kTr[10] = {
            "clear (transparent)",
            "flecked (transparent and other)",
            "layered (color or transparency)",
            "luminous (determine transparency)",
            "opaline (glowing)",
            "phosphorescent (determine transparency)",
            "rainbowed (transparent)",
            "ribboned (determine transparency)",
            "translucent",
            "variegated (determine colors)"
        };
        static const bool kTrDet[10] = {
            false, false, false, true, false, true,
            false, true, false, true
        };
        if (rules::klmTransparencyCount() != 10) ++bad;
        for (int i = 0; i < 10; ++i) {
            if (std::string(rules::klmTransparency(i))
                    != kTr[i])
                ++bad;
            if (rules::klmTransparencyNeedsDetermination(i)
                    != kTrDet[i])
                ++bad;
        }
        // the color list: 11 groups, 74 words
        static const char* kGrp[11] = {
            "METALLIC", "WHITE", "GRAY", "BROWN",
            "BLACK", "VIOLET", "YELLOW", "RED",
            "GREEN", "BLUE", "ORANGE"
        };
        static const int kGrpN[11] = {
            6, 4, 3, 6, 5, 10, 10, 16, 3, 6, 5
        };
        static const char* kCol[74] = {
            "brassy", "bronze", "coppery", "gold",
            "silvery", "steely",
            "bone", "colorless", "ivory", "pearl",
            "dove", "dun", "neutral",
            "chocolate", "ecru", "fawn", "mahogany",
            "tan", "terra cotta",
            "ebony", "inky", "pitchy", "sable",
            "sooty",
            "fuchsia", "heliotrope", "lake", "lavender",
            "lilac", "magenta", "mauve", "plum", "puce",
            "purple",
            "amber", "buff", "citrine", "cream",
            "fallow", "flaxen", "ochre", "peach",
            "saffron", "straw",
            "carmine", "cerise", "cherry", "cinnabar",
            "coral", "crimson", "madder", "maroon",
            "pink", "rose", "ruby", "russet", "rust",
            "sanguine", "scarlet", "vermillion",
            "aquamarine", "emerald", "olive",
            "azure", "cerulean", "indigo", "sapphire",
            "turquoise", "ultramarine",
            "apricot", "flame", "golden", "salmon",
            "tawny"
        };
        static const int kColOff[11] = {
            0, 6, 10, 13, 19, 24, 34, 44, 60, 63, 69
        };
        if (rules::klmColorGroupCount() != 11) ++bad;
        int colTotal = 0;
        for (int g = 0; g < 11; ++g) {
            if (std::string(rules::klmColorGroupName(g))
                    != kGrp[g])
                ++bad;
            if (rules::klmColorGroupSize(g) != kGrpN[g])
                ++bad;
            colTotal += kGrpN[g];
            for (int j = 0; j < kGrpN[g]; ++j)
                if (std::string(
                        rules::klmColorWord(g, j))
                        != kCol[kColOff[g] + j])
                    ++bad;
        }
        if (colTotal != 74) ++bad;
        // the taste and/or odor list
        static const char* kTa[28] = {
            "acidic", "bilious", "bitter",
            "burning/biting", "buttery", "dusty",
            "earthy", "fiery", "fishy", "greasy",
            "herbal", "honeyed", "lemony", "meaty",
            "metallic", "milky", "musty", "oniony",
            "peppery", "perfumy", "salty",
            "soothing/sugary", "sour", "spicy",
            "sweet", "tart", "vinegary", "watery"
        };
        if (rules::klmTasteCount() != 28) ++bad;
        for (int i = 0; i < 28; ++i)
            if (std::string(rules::klmTaste(i)) != kTa[i])
                ++bad;
        if (!rules::klmUsedWithDungeonDressing()) ++bad;
        // Appendix L: the prose
        if (!rules::klmConjFractionalCostCharged() ||
            !rules::klmConjRandomSelectionWhereSeveral() ||
            !rules::klmConjCasterCannotSpecify() ||
            rules::klmConjWhaleMaxHitDiceCost() != 36 ||
            !rules::klmConjWaterSwimmersAndFlyersOnly())
            ++bad;
        // the conjured animals categories: bands,
        // names and quarter costs, cell by cell
        static const int kCjN[4] = { 5, 4, 15, 13 };
        static const int kCjLo[37] = {
            1, 16, 46, 56, 66,
            1, 26, 36, 61,
            1, 6, 11, 16, 21, 31, 41, 46, 56, 66,
            76, 81, 86, 91, 96,
            1, 6, 16, 21, 31, 41, 46, 51, 56, 61,
            66, 76, 86
        };
        static const int kCjHi[37] = {
            15, 45, 55, 65, 100,
            25, 35, 60, 100,
            5, 10, 15, 20, 30, 40, 45, 55, 65, 75,
            80, 85, 90, 95, 100,
            5, 15, 20, 30, 40, 45, 50, 55, 60, 65,
            75, 85, 100
        };
        static const int kCjQ[37] = {
            5, 5, 2, 2, 2,
            6, 8, 8, 8,
            12, 12, 12, 12, 10, 10, 12, 13, 12, 13,
            10, 12, 12, 10, 12,
            17, 15, 16, 15, 16, 16, 16, 17, 14, 16,
            16, 15, 15
        };
        static const char* kCjName[37] = {
            "baboon", "dog, wild", "flightless bird",
            "jackal", "rat, giant",
            "badger", "flightless bird", "herd animal",
            "horse, wild",
            "axe beak", "badger, giant", "boar/warthog",
            "camel", "cattle, wild", "dog, war",
            "flightless bird", "goat, giant", "hyena",
            "lion, mountain", "lynx, giant", "mule",
            "stag", "wolf", "wolverine",
            "ape", "bear, black", "beaver, giant",
            "boar, wild", "bull", "eagle, giant",
            "Irish deer", "jaguar", "leopard",
            "owl, giant", "ram, giant",
            "weasel, giant", "wolf, dire"
        };
        if (rules::klmConjCategoryCount() != 4) ++bad;
        int cjFlat = 0;
        for (int c = 0; c < 4; ++c) {
            if (rules::klmConjRowCount(c) != kCjN[c])
                ++bad;
            for (int r = 0; r < kCjN[c]; ++r) {
                const rules::ConjuredAnimalRow& row =
                    rules::klmConjRow(c, r);
                if (row.lo != kCjLo[cjFlat] ||
                    row.hi != kCjHi[cjFlat] ||
                    row.costQ != kCjQ[cjFlat] ||
                    std::string(row.name)
                        != kCjName[cjFlat])
                    ++bad;
                ++cjFlat;
            }
        }
        if (cjFlat != 37) ++bad;
        // the 5-and-up roster (band columns are OCR
        // debt, the open finding)
        // R175: the 20-name roster became the full
        // banded table (26 rows) - the count check
        // here keeps the R171 audit honest; the
        // cell-by-cell check lives in the R175
        // audit block below
        if (rules::klmConjHigherCount() != 26)
            ++bad;
        // Appendix M: the prose
        if (!rules::klmSummonEvilUsesParenthesis() ||
            !rules::klmSummonDMMaySelectAndAppoint())
            ++bad;
        // the 7 land tables: bands, names and evil
        // alternates, cell by cell
        static const int kLdN[7] = {
            6, 6, 12, 12, 12, 16, 34
        };
        static const int kLdLo[98] = {
            1, 11, 26, 41, 56, 71,
            1, 16, 26, 46, 61, 76,
            1, 8, 18, 26, 33, 41, 48, 58, 68, 76,
            86, 96,
            1, 8, 16, 26, 36, 43, 51, 59, 68, 77,
            87, 94,
            1, 8, 18, 27, 37, 46, 56, 64, 73, 79,
            86, 91,
            1, 7, 13, 20, 27, 32, 39, 44, 52, 57,
            64, 69, 79, 85, 89, 93,
            1, 4, 7, 10, 13, 16, 19, 22, 24, 27,
            30, 33, 36, 39, 42, 44, 47, 50, 53, 56,
            59, 62, 65, 68, 71, 74, 77, 80, 83, 86,
            89, 92, 95, 98
        };
        static const int kLdHi[98] = {
            10, 25, 40, 55, 70, 100,
            15, 25, 45, 60, 75, 100,
            7, 17, 25, 32, 40, 47, 57, 67, 75, 85,
            95, 100,
            7, 15, 25, 35, 42, 50, 58, 67, 76, 86,
            93, 100,
            7, 17, 26, 36, 45, 55, 63, 72, 78, 85,
            90, 100,
            6, 12, 19, 26, 31, 38, 43, 51, 56, 63,
            68, 78, 84, 88, 92, 100,
            3, 6, 9, 12, 15, 18, 21, 23, 26, 29,
            32, 35, 38, 41, 43, 46, 49, 52, 55, 58,
            61, 64, 67, 70, 73, 76, 79, 82, 85, 88,
            91, 94, 97, 100
        };
        static const char* kLdName[98] = {
            "demon, manes", "goblin", "hobgoblin",
            "kobold", "orc", "rat, giant",
            "centipede, giant", "devil, lemure",
            "gnoll", "stirge", "toad, giant",
            "troglodyte",
            "beetle, boring", "bugbear",
            "gelatinous cube", "ghoul",
            "lizard, giant", "lycanthrope, wererat",
            "ochre jelly", "ogre", "spider, huge",
            "spider, large", "tick, giant",
            "weasel, giant",
            "ape, carnivorous", "gargoyle", "ghast",
            "gray ooze", "hell hound",
            "hydra, 5 heads",
            "lycanthrope, werewolf", "owlbear",
            "shadow", "snake, giant, constrictor",
            "toad, ice", "toad, poisonous",
            "cockatrice", "displacer beast",
            "doppleganger", "hydra, 7 heads",
            "leucrotta", "lizard, subterranean",
            "lycanthrope, wereboar", "minotaur",
            "snake, giant, amphisbaena",
            "snake, giant, poisonous",
            "snake, giant, spitting", "spider, giant",
            "carrion crawler", "devil, erinyes",
            "hydra, 8 heads", "jackalwere",
            "lycanthrope, weretiger", "manticore",
            "ogre magi", "otyugh", "rakshasa",
            "salamander", "spider, phase", "troll",
            "wight", "wind walker", "wraith",
            "wyvern",
            "chimera", "demon, succubus",
            "demon, type I", "demon, type II",
            "demon, type III", "devil, barbed",
            "devil, bone", "devil, horned", "ettin",
            "giant, fire", "giant, frost",
            "giant, hill", "giant, stone", "gorgon",
            "groaning spirit", "hydra, 10 heads",
            "hydra, pyro-, 8 heads",
            "intellect devourer", "invisible stalker",
            "lamia", "lizard, fire", "mind flayer",
            "mummy", "naga, spirit", "neo-otyugh",
            "night hag", "roper", "shambling mound",
            "slug, giant", "spectre",
            "sphinx, hieraco- (andro-)", "umber hulk",
            "will-o-wisp", "xorn"
        };
        static const char* kLdEvil[98] = {
            "", "dwarf", "elf", "halfling",
            "gnome", "", "", "",
            "", "", "", "",
            "", "", "", "",
            "", "", "", "",
            "", "", "", "",
            "", "blink dog", "", "",
            "", "", "", "",
            "", "", "", "",
            "", "", "", "",
            "", "", "", "",
            "", "", "", "",
            "", "", "", "lammasu",
            "werebear", "", "", "",
            "", "", "", "",
            "", "", "", "",
            "couatl", "", "", "",
            "", "", "", "",
            "", "", "", "",
            "", "", "", "",
            "", "", "", "",
            "", "", "", "",
            "", "", "shedu", "",
            "", "", "", "",
            "", ""
        };
        if (rules::klmSummonLandTableCount() != 7)
            ++bad;
        int ldFlat = 0;
        for (int t = 0; t < 7; ++t) {
            if (rules::klmSummonLandRowCount(t)
                    != kLdN[t])
                ++bad;
            for (int r = 0; r < kLdN[t]; ++r) {
                const rules::SummonedMonsterRow& row =
                    rules::klmSummonLandRow(t, r);
                if (row.lo != kLdLo[ldFlat] ||
                    row.hi != kLdHi[ldFlat] ||
                    std::string(row.name)
                        != kLdName[ldFlat])
                    ++bad;
                // the evil alternate: empty string or null
                const char* alt = row.evilAlt;
                if (kLdEvil[ldFlat][0] == 0) {
                    if (alt != 0) ++bad;
                } else {
                    if (alt == 0 ||
                        std::string(alt) != kLdEvil[ldFlat])
                        ++bad;
                }
                ++ldFlat;
            }
        }
        if (ldFlat != 98) ++bad;
        // the 13 water tables, cell by cell
        static const int kWtN[13] = {
            2, 2, 1, 2, 2, 2, 4, 3, 2, 4, 2, 2, 3
        };
        static const int kWtLo[31] = {
            1, 68,   1, 51,   1,   1, 34,   1, 34,
            1, 51,   1, 34, 51, 68,   1, 41, 81,
            1, 81,   1, 51, 71, 91,   1, 34,
            1, 21,   1, 16, 71
        };
        static const int kWtHi[31] = {
            67, 100,   50, 100,   100,   33, 100,
            33, 100,   50, 100,   33, 50, 67, 100,
            40, 80, 100,   80, 100,   50, 70, 90,
            100,   33, 100,   20, 100,   15, 70,
            100
        };
        static const char* kWtName[31] = {
            "koalinth", "nixie",
            "koalinth", "merman",
            "lizard man",
            "ixitxachitl", "locathah",
            "crab, giant", "lacedon",
            "lacedon", "sahuagin",
            "beetle, water, giant", "crayfish, giant",
            "kopoacinth", "spider, water, giant",
            "kopoacinth", "lobster (crayfish), giant",
            "triton",
            "crocodile, giant", "water weird",
            "crocodile, giant", "sea hag", "sea lion",
            "water weird",
            "octopus, giant", "snake, sea, giant",
            "morkoth", "naga, water",
            "morkoth", "ray, manta", "squid, giant"
        };
        static const char* kWtEvil[31] = {
            "hobgoblin", "",
            "hobgoblin", "",
            "",
            "", "",
            "", "ghoul",
            "ghoul", "",
            "", "", "gargoyle", "",
            "gargoyle", "", "",
            "", "",
            "", "", "", "",
            "", "",
            "", "",
            "", "", ""
        };
        static const char* kWtTab[13] = {
            "Monster Summoning I, fresh water",
            "Monster Summoning I, salt water",
            "Monster Summoning II, fresh water",
            "Monster Summoning II, salt water",
            "Monster Summoning III, fresh water",
            "Monster Summoning III, salt water",
            "Monster Summoning IV, fresh water",
            "Monster Summoning IV, salt water",
            "Monster Summoning V, fresh water",
            "Monster Summoning V, salt water",
            "Monster Summoning VI, fresh or salt water",
            "Monster Summoning VII, fresh water",
            "Monster Summoning VII, salt water"
        };
        if (rules::klmSummonWaterTableCount() != 13)
            ++bad;
        int wtFlat = 0;
        for (int t = 0; t < 13; ++t) {
            if (rules::klmSummonWaterRowCount(t)
                    != kWtN[t])
                ++bad;
            if (std::string(
                    rules::klmSummonWaterTableName(t))
                    != kWtTab[t])
                ++bad;
            for (int r = 0; r < kWtN[t]; ++r) {
                const rules::SummonedMonsterRow& row =
                    rules::klmSummonWaterRow(t, r);
                if (row.lo != kWtLo[wtFlat] ||
                    row.hi != kWtHi[wtFlat] ||
                    std::string(row.name)
                        != kWtName[wtFlat])
                    ++bad;
                const char* alt = row.evilAlt;
                if (kWtEvil[wtFlat][0] == 0) {
                    if (alt != 0) ++bad;
                } else {
                    if (alt == 0 ||
                        std::string(alt) != kWtEvil[wtFlat])
                        ++bad;
                }
                ++wtFlat;
            }
        }
        if (wtFlat != 31) ++bad;
        printf("R171 appendices K L and M audit: bad %d\n", bad);
        if (bad) return 1;
    }
