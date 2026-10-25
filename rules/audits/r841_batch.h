    // ---- R841 FF index line walk audit ----
    // THE FF INDEX LINE WALK - the F-referenced lines of the merged MM2 index
    // (print pp. 156-160): 414 walk lines (the R819 base 401 plus the 13
    // recovered rows), 214 keyed, 200 keyless, the letter pins A through Z (S
    // the largest at 52, Z none), the roster pages 8 through 97, every roster
    // def keyed; the registry 913, the ff def census 103, the dungeon
    // walk-key census 171 - all unchanged, the read-only round
    {
        using namespace rules;
        int bad = 0;
    if (ffikRound() != 841
            || ffikPrintFolio() != 156
            || ffikFirstPage() != 156
            || ffikLastPage() != 160
            || ffikColumnsPerPage() != 4
            || ffikLetterCount() != 26
            || ffikWalkLines() != 414
            || ffikKeyedLines() != 214
            || ffikKeylessLines() != 200
            || ffikKeyedDefs() != 103
            || ffikRosterDefs() != 103
            || ffikReconcileBase() != 401
            || ffikReconcileDelta() != 13
            || ffikMaxLetterLines() != 52
            || ffikMinLetterLines() != 0
            || ffikFirstFfPage() != 8
            || ffikLastFfPage() != 97
            || ffikLetterA() != 17
            || ffikLetterB() != 26
            || ffikLetterC() != 26
            || ffikLetterD() != 29
            || ffikLetterE() != 15
            || ffikLetterF() != 26
            || ffikLetterG() != 33
            || ffikLetterH() != 13
            || ffikLetterI() != 14
            || ffikLetterJ() != 5
            || ffikLetterK() != 13
            || ffikLetterL() != 19
            || ffikLetterM() != 21
            || ffikLetterN() != 12
            || ffikLetterO() != 10
            || ffikLetterP() != 18
            || ffikLetterQ() != 4
            || ffikLetterR() != 11
            || ffikLetterS() != 52
            || ffikLetterT() != 16
            || ffikLetterU() != 6
            || ffikLetterV() != 6
            || ffikLetterW() != 13
            || ffikLetterX() != 2
            || ffikLetterY() != 7
            || ffikLetterZ() != 0
            || ffikRegistryDefs() != 913
            || ffikDungeonKeyedCells() != 171
            || ffikDungeonFfRows() != 26
            || ffikVoiceCount() != 3
            || ffikGeoLineCensus() != 1595
            || !ffikNoDefsPromotedThisRound()
            || !ffikRegistryStaysAt913()
            || !ffikFfDefsStayAt103()
            || !ffikNameBasedResolution()
            || !ffikFamilyRowsKeyless()
            || !ffikSubrowsRelettered()
            || !ffikDoubleListingsCounted()
            || !ffikThreeVoiceCollatedRead()
            || !ffikNoGapBoxesFlip()
            || !ffikPagesFollowRosterOracle()
        )
            ++bad;
        // THE FF INDEX LINE WALK GRID: the 414 F-referenced lines, the cells
        // (ordinal, letter, page, def ordinal). The def column carries the
        // 214 keyed ordinals 1 through 103 and the 200 keyless zeros.
        int CWALK[414][4] = {
            {1,1,8,1},
            {2,1,9,2},
            {3,1,9,3},
            {4,1,33,0},
            {5,1,62,0},
            {6,1,11,5},
            {7,1,11,6},
            {8,1,11,6},
            {9,1,11,4},
            {10,1,84,82},
            {11,1,12,7},
            {12,1,17,0},
            {13,1,12,8},
            {14,1,13,9},
            {15,1,16,16},
            {16,1,75,65},
            {17,1,75,65},
            {18,2,13,10},
            {19,2,53,47},
            {20,4,27,0},
            {21,7,14,11},
            {22,2,35,0},
            {23,7,46,0},
            {24,2,46,0},
            {25,2,14,12},
            {26,2,8,1},
            {27,2,26,0},
            {28,2,41,0},
            {29,2,92,95},
            {30,2,80,75},
            {31,2,15,13},
            {32,2,15,14},
            {33,2,15,0},
            {34,2,96,103},
            {35,2,80,0},
            {36,2,15,15},
            {37,2,16,16},
            {38,2,46,41},
            {39,2,12,8},
            {40,2,46,0},
            {41,2,16,17},
            {42,2,17,18},
            {43,2,84,0},
            {44,3,17,0},
            {45,3,30,0},
            {46,3,18,0},
            {47,7,49,0},
            {48,8,50,0},
            {49,14,68,0},
            {50,3,86,85},
            {51,3,18,19},
            {52,3,29,0},
            {53,3,19,20},
            {54,3,19,21},
            {55,3,52,0},
            {56,3,19,22},
            {57,3,29,0},
            {58,3,46,0},
            {59,3,31,0},
            {60,3,18,0},
            {61,3,88,89},
            {62,3,26,0},
            {63,3,19,22},
            {64,3,21,23},
            {65,3,22,0},
            {66,3,97,0},
            {67,3,31,0},
            {68,3,21,24},
            {69,7,49,0},
            {70,13,66,56},
            {71,14,69,58},
            {72,4,22,25},
            {73,4,67,0},
            {74,4,22,0},
            {75,4,23,0},
            {76,4,33,34},
            {77,4,23,0},
            {78,4,23,0},
            {79,4,23,0},
            {80,4,81,76},
            {81,4,67,0},
            {82,4,84,83},
            {83,4,24,0},
            {84,6,40,0},
            {85,19,78,70},
            {86,4,25,26},
            {87,4,25,0},
            {88,4,26,27},
            {89,4,50,0},
            {90,4,77,69},
            {91,4,26,0},
            {92,4,27,28},
            {93,4,23,0},
            {94,4,26,27},
            {95,8,51,0},
            {96,4,27,0},
            {97,4,34,0},
            {98,3,30,0},
            {99,3,29,0},
            {100,3,29,0},
            {101,5,28,29},
            {102,13,36,36},
            {103,13,52,0},
            {104,15,27,0},
            {105,19,28,30},
            {106,19,29,31},
            {107,4,30,32},
            {108,4,33,34},
            {109,4,30,33},
            {110,5,32,0},
            {111,5,28,29},
            {112,5,56,50},
            {113,5,27,28},
            {114,5,92,0},
            {115,5,79,73},
            {116,5,31,0},
            {117,5,33,0},
            {118,5,82,0},
            {119,5,34,0},
            {120,5,35,35},
            {121,5,81,77},
            {122,5,35,0},
            {123,5,35,0},
            {124,6,50,0},
            {125,6,49,0},
            {126,6,31,0},
            {127,6,64,55},
            {128,6,38,0},
            {129,6,72,0},
            {130,6,87,88},
            {131,6,36,36},
            {132,6,36,37},
            {133,6,42,0},
            {134,6,38,0},
            {135,6,56,50},
            {136,6,57,0},
            {137,6,38,0},
            {138,6,39,0},
            {139,6,39,0},
            {140,6,88,91},
            {141,6,42,0},
            {142,6,39,38},
            {143,6,50,43},
            {144,6,15,13},
            {145,6,16,17},
            {146,6,40,0},
            {147,7,40,0},
            {148,7,41,39},
            {149,7,41,0},
            {150,7,78,71},
            {151,7,41,0},
            {152,7,42,0},
            {153,7,42,0},
            {154,7,43,0},
            {155,7,43,40},
            {156,7,45,0},
            {157,7,84,83},
            {158,7,96,103},
            {159,7,57,0},
            {160,7,46,0},
            {161,7,18,0},
            {162,7,46,0},
            {163,7,46,0},
            {164,7,57,51},
            {165,7,72,0},
            {166,7,93,99},
            {167,7,81,0},
            {168,7,92,96},
            {169,7,46,41},
            {170,7,40,0},
            {171,7,81,77},
            {172,7,47,42},
            {173,7,48,0},
            {174,7,49,0},
            {175,7,49,0},
            {176,8,15,14},
            {177,8,56,49},
            {178,8,50,0},
            {179,8,50,43},
            {180,8,51,44},
            {181,8,52,46},
            {182,8,51,44},
            {183,8,51,0},
            {184,8,51,45},
            {185,8,93,99},
            {186,8,93,99},
            {187,9,40,0},
            {188,9,26,27},
            {189,9,50,43},
            {190,9,52,0},
            {191,9,90,93},
            {192,9,51,0},
            {193,9,52,0},
            {194,9,31,0},
            {195,9,52,0},
            {196,9,82,0},
            {197,9,19,20},
            {198,9,91,0},
            {199,9,52,0},
            {200,10,53,0},
            {201,10,85,84},
            {202,10,53,47},
            {203,10,53,47},
            {204,11,55,0},
            {205,11,55,48},
            {206,11,56,49},
            {207,11,56,50},
            {208,11,35,0},
            {209,11,57,51},
            {210,11,61,0},
            {211,11,23,0},
            {212,11,96,103},
            {213,11,57,0},
            {214,11,83,80},
            {215,12,59,0},
            {216,12,61,52},
            {217,12,64,0},
            {218,12,88,90},
            {219,12,55,0},
            {220,12,81,76},
            {221,12,28,29},
            {222,12,15,13},
            {223,12,52,0},
            {224,12,61,0},
            {225,12,13,10},
            {226,12,61,0},
            {227,12,41,0},
            {228,12,24,0},
            {229,12,82,0},
            {230,12,82,0},
            {231,12,91,94},
            {232,12,28,30},
            {233,13,27,28},
            {234,13,62,0},
            {235,2,86,0},
            {236,2,48,0},
            {237,3,21,23},
            {238,6,40,0},
            {239,11,56,49},
            {240,11,57,0},
            {241,12,61,52},
            {242,19,77,67},
            {243,19,79,73},
            {244,13,62,0},
            {245,13,63,53},
            {246,13,63,54},
            {247,13,64,0},
            {248,13,77,69},
            {249,13,52,0},
            {250,13,66,56},
            {251,13,53,47},
            {252,13,66,0},
            {253,13,42,0},
            {254,13,9,3},
            {255,13,97,0},
            {256,13,97,0},
            {257,13,13,10},
            {258,13,19,21},
            {259,13,95,0},
            {260,14,67,0},
            {261,14,67,0},
            {262,14,36,37},
            {263,14,67,0},
            {264,14,68,0},
            {265,14,68,57},
            {266,14,69,58},
            {267,14,39,38},
            {268,15,32,0},
            {269,15,70,0},
            {270,15,70,59},
            {271,15,32,0},
            {272,15,51,0},
            {273,15,70,59},
            {274,15,70,60},
            {275,15,19,21},
            {276,15,76,0},
            {277,16,29,0},
            {278,16,68,0},
            {279,16,71,61},
            {280,16,72,0},
            {281,16,83,79},
            {282,16,78,72},
            {283,16,72,0},
            {284,16,18,0},
            {285,16,74,64},
            {286,16,73,62},
            {287,16,73,0},
            {288,16,33,0},
            {289,16,31,0},
            {290,16,32,0},
            {291,16,31,0},
            {292,16,32,0},
            {293,16,73,0},
            {294,17,74,63},
            {295,17,24,0},
            {296,17,74,64},
            {297,17,74,0},
            {298,18,11,4},
            {299,18,62,0},
            {300,18,36,36},
            {301,18,82,78},
            {302,18,92,97},
            {303,18,75,0},
            {304,18,75,65},
            {305,18,70,60},
            {306,18,87,88},
            {307,18,76,66},
            {308,18,17,0},
            {309,19,38,0},
            {310,19,77,67},
            {311,19,77,68},
            {312,19,77,69},
            {313,19,18,19},
            {314,19,28,30},
            {315,19,13,9},
            {316,19,55,48},
            {317,19,78,70},
            {318,19,78,71},
            {319,19,78,72},
            {320,19,78,72},
            {321,19,29,31},
            {322,19,79,73},
            {323,19,92,98},
            {324,19,84,82},
            {325,19,21,24},
            {326,19,79,74},
            {327,19,80,75},
            {328,19,95,0},
            {329,19,80,0},
            {330,19,64,55},
            {331,19,38,0},
            {332,6,38,0},
            {333,9,52,0},
            {334,10,53,0},
            {335,19,35,0},
            {336,19,55,0},
            {337,19,83,79},
            {338,19,83,80},
            {339,19,35,35},
            {340,19,75,0},
            {341,19,24,0},
            {342,19,29,31},
            {343,19,62,0},
            {344,19,91,0},
            {345,19,41,39},
            {346,2,16,16},
            {347,19,82,0},
            {348,4,23,0},
            {349,4,30,33},
            {350,16,72,0},
            {351,19,91,0},
            {352,19,65,0},
            {353,19,9,3},
            {354,19,88,89},
            {355,19,63,53},
            {356,19,42,0},
            {357,19,84,81},
            {358,19,25,0},
            {359,19,84,82},
            {360,19,84,83},
            {361,19,85,84},
            {362,20,86,85},
            {363,20,86,86},
            {364,20,87,87},
            {365,20,21,24},
            {366,20,87,88},
            {367,20,88,89},
            {368,20,88,90},
            {369,20,29,0},
            {370,20,88,91},
            {371,20,89,92},
            {372,20,38,0},
            {373,20,89,0},
            {374,20,91,94},
            {375,20,23,0},
            {376,20,90,0},
            {377,21,93,99},
            {378,21,92,0},
            {379,21,75,65},
            {380,21,79,74},
            {381,21,11,4},
            {382,21,92,0},
            {383,22,41,0},
            {384,22,93,0},
            {385,22,93,99},
            {386,22,61,52},
            {387,22,94,100},
            {388,22,94,101},
            {389,23,84,81},
            {390,23,84,83},
            {391,23,79,74},
            {392,23,32,0},
            {393,23,93,99},
            {394,23,94,0},
            {395,23,95,102},
            {396,23,94,0},
            {397,23,52,0},
            {398,23,95,0},
            {399,23,95,102},
            {400,14,67,0},
            {401,20,87,88},
            {402,23,83,80},
            {403,23,78,72},
            {404,24,96,0},
            {405,24,96,103},
            {406,25,33,0},
            {407,25,97,0},
            {408,25,97,0},
            {409,25,93,0},
            {410,25,82,0},
            {411,25,30,0},
            {412,14,67,0},
            {413,19,83,80},
            {414,25,97,0},
            };
        int nWALK[4] = {0,0,0,0};
        int eWALK[4] = {0,0,0,200};
        for (int b = 0;
             b < ffikWalkLines();
             ++b) {
            int vals[4];
            vals[0] = ffikOrdinal(b);
            vals[1] = ffikLetter(b);
            vals[2] = ffikPage(b);
            vals[3] = ffikDef(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CWALK[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nWALK[c];
            }
        }
        for (int c = 0; c < 4; ++c)
            if (nWALK[c] != eWALK[c])
                ++bad;
        // THE FF ROSTER PAGE GRID: the 103 registry FF defs in page order
        // (the R840 census, unchanged this round).
        int CROST[103][2] = {
            {1,8},
            {2,9},
            {3,9},
            {4,11},
            {5,11},
            {6,11},
            {7,12},
            {8,12},
            {9,13},
            {10,13},
            {11,14},
            {12,14},
            {13,15},
            {14,15},
            {15,15},
            {16,16},
            {17,16},
            {18,17},
            {19,18},
            {20,19},
            {21,19},
            {22,19},
            {23,21},
            {24,21},
            {25,22},
            {26,25},
            {27,26},
            {28,27},
            {29,28},
            {30,28},
            {31,29},
            {32,30},
            {33,30},
            {34,33},
            {35,35},
            {36,36},
            {37,36},
            {38,39},
            {39,41},
            {40,43},
            {41,46},
            {42,47},
            {43,50},
            {44,51},
            {45,51},
            {46,52},
            {47,53},
            {48,55},
            {49,56},
            {50,56},
            {51,57},
            {52,61},
            {53,63},
            {54,63},
            {55,64},
            {56,66},
            {57,68},
            {58,69},
            {59,70},
            {60,70},
            {61,71},
            {62,73},
            {63,74},
            {64,74},
            {65,75},
            {66,76},
            {67,77},
            {68,77},
            {69,77},
            {70,78},
            {71,78},
            {72,78},
            {73,79},
            {74,79},
            {75,80},
            {76,81},
            {77,81},
            {78,82},
            {79,83},
            {80,83},
            {81,84},
            {82,84},
            {83,84},
            {84,85},
            {85,86},
            {86,86},
            {87,87},
            {88,87},
            {89,88},
            {90,88},
            {91,88},
            {92,89},
            {93,90},
            {94,91},
            {95,92},
            {96,92},
            {97,92},
            {98,92},
            {99,93},
            {100,94},
            {101,94},
            {102,95},
            {103,96},
            };
        int nROST[2] = {0,0};
        int eROST[2] = {0,0};
        for (int b = 0;
             b < ffikRosterDefs();
             ++b) {
            int vals[2];
            vals[0] = ffikRosterOrdinal(b);
            vals[1] = ffikRosterPage(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CROST[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nROST[c];
            }
        }
        for (int c = 0; c < 2; ++c)
            if (nROST[c] != eROST[c])
                ++bad;
        // THE PER-LETTER WALK CENSUS GRID: the 26 letter rows, the cells
        // (ordinal, lines, keyed, keyless). S is the largest (52 lines, 37
        // keyed); Z carries none (the own-name read).
        int CWLET[26][4] = {
            {1,17,14,3},
            {2,26,16,10},
            {3,26,10,16},
            {4,29,13,16},
            {5,15,7,8},
            {6,26,10,16},
            {7,33,12,21},
            {8,13,9,4},
            {9,14,4,10},
            {10,5,3,2},
            {11,13,7,6},
            {12,19,9,10},
            {13,21,11,10},
            {14,12,5,7},
            {15,10,4,6},
            {16,18,5,13},
            {17,4,2,2},
            {18,11,8,3},
            {19,52,37,15},
            {20,16,11,5},
            {21,6,4,2},
            {22,6,4,2},
            {23,13,8,5},
            {24,2,1,1},
            {25,7,0,7},
            {26,0,0,0},
            };
        int nWLET[4] = {0,0,0,0};
        int eWLET[4] = {0,1,2,1};
        for (int b = 0;
             b < ffikLetterCount();
             ++b) {
            int vals[4];
            vals[0] = ffikLetOrdinal(b);
            vals[1] = ffikLetLines(b);
            vals[2] = ffikLetKeyed(b);
            vals[3] = ffikLetKeyless(b);
            for (int c = 0; c < 4;
                 ++c) {
                if (vals[c] != CWLET[b][c])
                    ++bad;
                if (vals[c] == 0)
                    ++nWLET[c];
            }
        }
        for (int c = 0; c < 4; ++c)
            if (nWLET[c] != eWLET[c])
                ++bad;
        // the walk closes over keyed and keyless
    if (ffikKeyedLines() + ffikKeylessLines() != ffikWalkLines()
        )
            ++bad;
        // the walk reconciles the R819 base plus the thirteen recovered rows
    if (ffikWalkLines() != ffikReconcileBase() + ffikReconcileDelta()
        )
            ++bad;
        // the per-letter pins sum to the walk
    if (ffikLetterA() + ffikLetterB() + ffikLetterC() + ffikLetterD() +
        ffikLetterE() + ffikLetterF() + ffikLetterG() + ffikLetterH() +
        ffikLetterI() + ffikLetterJ() + ffikLetterK() + ffikLetterL() +
        ffikLetterM() + ffikLetterN() + ffikLetterO() + ffikLetterP() +
        ffikLetterQ() + ffikLetterR() + ffikLetterS() + ffikLetterT() +
        ffikLetterU() + ffikLetterV() + ffikLetterW() + ffikLetterX() +
        ffikLetterY() + ffikLetterZ() != ffikWalkLines()
        )
            ++bad;
        // the per-letter grid sums to the walk
    if (ffikLetLines(0) + ffikLetLines(1) + ffikLetLines(2) + ffikLetLines(3)
        + ffikLetLines(4) + ffikLetLines(5) + ffikLetLines(6) +
        ffikLetLines(7) + ffikLetLines(8) + ffikLetLines(9) + ffikLetLines(10)
        + ffikLetLines(11) + ffikLetLines(12) + ffikLetLines(13) +
        ffikLetLines(14) + ffikLetLines(15) + ffikLetLines(16) +
        ffikLetLines(17) + ffikLetLines(18) + ffikLetLines(19) +
        ffikLetLines(20) + ffikLetLines(21) + ffikLetLines(22) +
        ffikLetLines(23) + ffikLetLines(24) + ffikLetLines(25) !=
        ffikWalkLines()
        )
            ++bad;
        // the letter rows close over keyed and keyless (the A and S rows)
    if (ffikLetKeyed(0) + ffikLetKeyless(0) != ffikLetLines(0)
            || ffikLetKeyed(18) + ffikLetKeyless(18) != ffikLetLines(18)
        )
            ++bad;
        // the S and Z grid rows carry the pinned censuses
    if (ffikLetLines(18) != ffikLetterS()
            || ffikLetLines(25) != ffikLetterZ()
        )
            ++bad;
        // the grid opens on the aarakocra line and closes on the yellow musk
        // zombie line
    if (ffikOrdinal(0) != 1
            || ffikOrdinal(413) != 414
            || ffikDef(0) != 1
            || ffikDef(413) != 0
        )
            ++bad;
        // the roster grid opens on the aarakocra def and closes on the xvart
        // def (page 96)
    if (ffikRosterOrdinal(0) != 1
            || ffikRosterOrdinal(102) != 103
            || ffikRosterPage(0) != 8
            || ffikRosterPage(102) != 96
        )
            ++bad;
        // every roster def carries a keyed line
    if (ffikKeyedDefs() != ffikRosterDefs()
            || ffikKeyedLines() < ffikKeyedDefs()
        )
            ++bad;
        // the extremes hold (S largest, Z none, the page span 8 through 97)
    if (ffikMaxLetterLines() != 52
            || ffikMinLetterLines() != 0
            || ffikFirstFfPage() != 8
            || ffikLastFfPage() != 97
        )
            ++bad;
        printf("R841 FF index line walk audit: bad %d\n", bad);
        if (bad) return 1;
    }
