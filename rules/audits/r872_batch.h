    // ---- R872 clerical chart batch four audit ----
    // APPENDIX 3: THE CLERICAL QUICK-REFERENCE CHARTS, BATCH FOUR - the D&DG
    // walk round twenty-four, print pp. 139-140: the fourth batch of deity
    // rows - Greek (18), Indian (13) - riding the roster data file, the Greek
    // block below the R871 Finnish tail on pdf 139, the Indian block spanning
    // the pdf 139 tail / 140 head; the App 3 gap box stays open until the
    // last chart batch lands. The print voice is the ROTATED tesseract pass,
    // collated against the 1eonline L&L per-deity chart rows. The headline
    // divergence: the print reads two X marks for Aphrodite (M and F) where
    // the L&L voice reads female-only - pinned by print, eyeball flag.
    {
        using namespace rules;
        int bad = 0;
    if (cqc4Round() != 872
            || cqc4Batch() != 4
            || cqc4PrintStart() != 139
            || cqc4PrintEnd() != 140
            || cqc4Rows() != 31
            || cqc4GreekRows() != 18
            || cqc4IndianRows() != 13
            || cqc4MaleRows() != 29
            || cqc4FemaleRows() != 26
            || cqc4NonHumanRows() != 9
            || cqc4PrintedColumns() != 13
            || cqc4SphereCount() != 30
            || cqc4AnimalCount() != 29
            || cqc4HeadCount() != 9
            || cqc4BodyCount() != 18
            || cqc4ColorCount() != 24
            || cqc4HolyDayCount() != 13
            || cqc4FreqCount() != 15
            || cqc4FormCount() != 23
            || cqc4PlaceCount() != 17
            || cqc4TableCount() != 1
            || cqc4ChainCount() != 0
            || !cqc4AphroditeMaleClericsPrint()
            || !cqc4ZeusRedSunrise()
            || !cqc4PoseidonSphereRestored()
            || !cqc4ApolloLaurelRestored()
            || !cqc4IndraRainbowNoGlyph()
            || !cqc4YamaTalesNoArticle()
            || !cqc4YamaStrayColon()
            || !cqc4AtDawnFoldRestored()
            || !cqc4RudraRedBlackComma()
            || !cqc4TwoFemaleOnlyRows()
        )
            ++bad;
        // the the clerical chart batch four grid grid
        int Ccqc4Chart[31][13] = {
            {0,0,0,1,1,0,0,0,0,0,0,0,0},
            {1,1,1,1,1,0,0,0,1,1,1,1,1},
            {2,2,2,1,0,0,1,0,2,2,2,2,2},
            {3,3,3,1,1,0,2,1,3,3,3,3,3},
            {4,4,4,0,1,1,0,2,4,4,0,4,4},
            {5,5,5,1,1,0,2,3,5,5,2,0,1},
            {6,6,6,1,1,0,0,0,6,6,4,5,5},
            {7,7,7,1,1,0,0,0,7,6,4,6,6},
            {8,8,8,1,1,1,2,4,8,5,5,2,7},
            {9,9,9,1,1,0,0,0,9,7,6,3,8},
            {10,10,10,1,1,1,0,5,10,5,7,7,9},
            {11,11,11,1,1,0,0,0,11,8,8,8,1},
            {12,12,12,1,1,0,3,0,12,5,9,9,10},
            {13,13,13,1,1,0,4,0,13,9,10,3,1},
            {14,14,14,1,0,1,5,6,14,6,4,10,4},
            {15,15,15,1,1,1,0,0,15,5,7,11,1},
            {16,16,16,1,1,0,0,0,16,4,11,12,11},
            {17,17,17,1,1,0,0,0,17,5,7,6,6},
            {18,18,18,1,0,0,6,7,18,5,8,2,1},
            {19,19,19,1,1,0,6,8,19,5,8,13,1},
            {20,20,20,1,1,1,6,9,8,5,12,14,12},
            {21,3,11,1,0,0,6,10,17,10,13,15,13},
            {22,21,21,1,1,0,6,11,2,5,8,16,1},
            {23,22,22,1,1,1,6,12,20,11,8,17,1},
            {24,23,23,1,1,0,7,13,21,5,5,2,14},
            {25,24,13,1,1,0,6,13,13,12,4,18,1},
            {26,25,24,1,1,1,6,14,6,5,8,19,15},
            {27,26,25,0,1,0,8,11,22,5,14,20,1},
            {28,27,26,1,1,0,6,15,0,8,8,2,1},
            {29,28,27,1,1,1,6,16,12,11,8,21,1},
            {30,29,28,1,0,0,6,17,23,5,5,22,16},
            };
        for (int b = 0;
             b < cqc4Rows();
             ++b) {
            int vals[13];
            vals[0] = cqc4ChartOrd(b);
            vals[1] = cqc4ChartSphere(b);
            vals[2] = cqc4ChartAnimal(b);
            vals[3] = cqc4ChartM(b);
            vals[4] = cqc4ChartF(b);
            vals[5] = cqc4ChartNh(b);
            vals[6] = cqc4ChartHead(b);
            vals[7] = cqc4ChartBody(b);
            vals[8] = cqc4ChartColor(b);
            vals[9] = cqc4ChartHolyday(b);
            vals[10] = cqc4ChartFreq(b);
            vals[11] = cqc4ChartForm(b);
            vals[12] = cqc4ChartPlace(b);
            for (int c = 0; c < 13;
                 ++c) {
                if (vals[c] != Ccqc4Chart[b][c])
                    ++bad;
            }
        }
        // the census walk (the batch rows, the pantheon counts, the roster
        // counts, the cleric flags)
    if (cqc4Round() != 872
            || cqc4Batch() != 4
            || cqc4PrintStart() != 139
            || cqc4PrintEnd() != 140
            || cqc4Rows() != 31
            || cqc4GreekRows() != 18
            || cqc4IndianRows() != 13
            || cqc4MaleRows() != 29
            || cqc4FemaleRows() != 26
            || cqc4NonHumanRows() != 9
            || cqc4PrintedColumns() != 13
            || cqc4SphereCount() != 30
            || cqc4AnimalCount() != 29
            || cqc4HeadCount() != 9
            || cqc4BodyCount() != 18
            || cqc4ColorCount() != 24
            || cqc4HolyDayCount() != 13
            || cqc4FreqCount() != 15
            || cqc4FormCount() != 23
            || cqc4PlaceCount() != 17
            || cqc4TableCount() != 1
            || cqc4ChainCount() != 0
        )
            ++bad;
        // the parity pins (the headline Aphrodite divergence, the
        // restorations, the fold classes)
    if (cqc4AphroditeMaleClericsPrint() != 1
            || cqc4ZeusRedSunrise() != 1
            || cqc4PoseidonSphereRestored() != 1
            || cqc4ApolloLaurelRestored() != 1
            || cqc4IndraRainbowNoGlyph() != 1
            || cqc4YamaTalesNoArticle() != 1
            || cqc4YamaStrayColon() != 1
            || cqc4AtDawnFoldRestored() != 1
            || cqc4RudraRedBlackComma() != 1
            || cqc4TwoFemaleOnlyRows() != 1
        )
            ++bad;
        // the head and tail rows (Zeus 0, Yama 30, the ordinals run)
    if (cqc4ChartOrd(0) != 0
            || cqc4ChartOrd(30) != 30
            || cqc4ChartColor(0) != 0
            || cqc4ChartHolyday(0) != 0
            || cqc4ChartFreq(0) != 0
            || cqc4ChartM(0) != 1
            || cqc4ChartF(0) != 1
            || cqc4ChartPlace(0) != 0
            || cqc4ChartBody(30) != 17
            || cqc4ChartColor(30) != 23
            || cqc4ChartM(30) != 1
            || cqc4ChartF(30) != 0
            || cqc4ChartForm(30) != 22
            || cqc4ChartPlace(30) != 16
        )
            ++bad;
        // the Greek rows (the Aphrodite pin, the triple flags, the seldom and
        // never frequencies)
    if (cqc4ChartM(1) != 1
            || cqc4ChartF(1) != 1
            || cqc4ChartForm(1) != 1
            || cqc4ChartHead(2) != 1
            || cqc4ChartHolyday(2) != 2
            || cqc4ChartF(2) != 0
            || cqc4ChartBody(3) != 1
            || cqc4ChartFreq(3) != 3
            || cqc4ChartM(4) != 0
            || cqc4ChartNh(4) != 1
            || cqc4ChartBody(5) != 3
            || cqc4ChartFreq(8) != 5
            || cqc4ChartNh(8) != 1
            || cqc4ChartFreq(9) != 6
            || cqc4ChartForm(10) != 7
            || cqc4ChartNh(10) != 1
            || cqc4ChartColor(11) != 11
            || cqc4ChartSphere(12) != 12
            || cqc4ChartFreq(12) != 9
            || cqc4ChartHead(13) != 4
            || cqc4ChartF(14) != 0
            || cqc4ChartNh(14) != 1
            || cqc4ChartSphere(15) != 15
            || cqc4ChartNh(15) != 1
            || cqc4ChartFreq(16) != 11
            || cqc4ChartForm(17) != 6
        )
            ++bad;
        // the Indian rows (the rainbow, the before-battle pair, the copper
        // tracery)
    if (cqc4ChartBody(18) != 7
            || cqc4ChartColor(18) != 18
            || cqc4ChartM(18) != 1
            || cqc4ChartF(18) != 0
            || cqc4ChartColor(19) != 19
            || cqc4ChartNh(20) != 1
            || cqc4ChartPlace(20) != 12
            || cqc4ChartBody(21) != 10
            || cqc4ChartHolyday(21) != 10
            || cqc4ChartFreq(21) != 13
            || cqc4ChartF(21) != 0
            || cqc4ChartForm(22) != 16
            || cqc4ChartNh(23) != 1
            || cqc4ChartHead(24) != 7
            || cqc4ChartColor(24) != 21
            || cqc4ChartForm(25) != 18
            || cqc4ChartNh(26) != 1
            || cqc4ChartPlace(26) != 15
            || cqc4ChartM(27) != 0
            || cqc4ChartF(27) != 1
            || cqc4ChartFreq(27) != 14
            || cqc4ChartSphere(28) != 27
            || cqc4ChartBody(29) != 16
            || cqc4ChartNh(29) != 1
        )
            ++bad;
        // the cleric flags (the female and non-human census cells)
    if (cqc4ChartF(3) != 1
            || cqc4ChartF(6) != 1
            || cqc4ChartF(9) != 1
            || cqc4ChartF(12) != 1
            || cqc4ChartF(13) != 1
            || cqc4ChartF(16) != 1
            || cqc4ChartF(19) != 1
            || cqc4ChartF(22) != 1
            || cqc4ChartF(25) != 1
            || cqc4ChartF(28) != 1
            || cqc4ChartNh(4) != 1
            || cqc4ChartNh(14) != 1
            || cqc4ChartNh(15) != 1
            || cqc4ChartNh(20) != 1
            || cqc4ChartNh(23) != 1
            || cqc4ChartNh(29) != 1
        )
            ++bad;
        printf("R872 clerical chart batch four audit: bad %d\n", bad);
        if (bad) return 1;
    }
