    // ---- R870 clerical chart batch two audit ----
    // APPENDIX 3: THE CLERICAL QUICK-REFERENCE CHARTS, BATCH TWO - the D&DG
    // walk round twenty-two, print pp. 136-137: the second batch of deity
    // rows - Central American (12), Chinese (15), Cthulhu (8) - riding the
    // roster data file, the Cthulhu tail on the next pdf page head; the App 3
    // gap box stays open until the last chart batch lands. The print voice is
    // the ROTATED tesseract pass, collated against the 1eonline L&L per-deity
    // chart rows. The headline divergence: the print reads sky blue for the
    // Hastur raiment color where the L&L voice reads yellow-orange - pinned
    // by print, eyeball flag.
    {
        using namespace rules;
        int bad = 0;
    if (cqc2Round() != 870
            || cqc2Batch() != 2
            || cqc2PrintStart() != 136
            || cqc2PrintEnd() != 137
            || cqc2Rows() != 35
            || cqc2CARows() != 12
            || cqc2ChineseRows() != 15
            || cqc2CthulhuRows() != 8
            || cqc2MaleRows() != 35
            || cqc2FemaleRows() != 22
            || cqc2NonHumanRows() != 12
            || cqc2PrintedColumns() != 13
            || cqc2SphereCount() != 30
            || cqc2AnimalCount() != 25
            || cqc2HeadCount() != 12
            || cqc2BodyCount() != 22
            || cqc2ColorCount() != 32
            || cqc2HolyDayCount() != 14
            || cqc2FreqCount() != 9
            || cqc2FormCount() != 22
            || cqc2PlaceCount() != 16
            || cqc2TableCount() != 1
            || cqc2ChainCount() != 0
            || !cqc2HasturSkyBluePrint()
            || !cqc2GraySpelledWithA()
            || !cqc2CthulhuPlaceNoGloss()
            || !cqc2ChartPrintsCthuga()
            || !cqc2TlGlyphGarbles()
            || !cqc2FeiLienSpaceRestored()
            || !cqc2SemicolonSpheres()
            || !cqc2ChineseNoNonHuman()
            || !cqc2EveryRowMale()
            || !cqc2CthulhuAllNonHuman()
        )
            ++bad;
        // the the clerical chart batch two grid grid
        int Ccqc2Chart[35][13] = {
            {0,0,0,1,1,0,0,0,0,0,0,0,0},
            {1,1,1,1,1,0,1,1,1,1,0,1,0},
            {2,2,2,1,1,1,2,2,2,2,1,2,1},
            {3,3,3,1,1,0,3,0,3,3,1,3,0},
            {4,4,4,1,1,1,2,2,4,3,2,4,2},
            {5,5,5,1,0,0,0,3,5,3,1,5,3},
            {6,6,6,1,1,0,0,0,6,4,3,6,4},
            {7,7,7,1,1,1,0,2,7,3,4,7,0},
            {8,8,8,1,1,0,1,1,8,5,5,7,0},
            {9,9,9,1,1,0,2,0,9,5,5,8,0},
            {10,10,10,1,1,1,0,4,8,3,1,9,0},
            {11,11,11,1,1,0,1,5,10,3,1,10,5},
            {12,12,12,1,1,0,4,6,1,6,5,9,0},
            {13,5,13,1,0,0,5,7,11,3,6,11,0},
            {14,13,14,1,0,0,6,8,12,5,5,12,0},
            {15,9,15,1,1,0,7,9,13,5,5,13,6},
            {16,14,16,1,1,0,4,10,14,0,0,14,0},
            {17,15,5,1,1,0,8,7,15,5,5,13,0},
            {18,5,17,1,0,0,7,11,16,1,0,15,0},
            {19,16,18,1,1,0,8,12,17,1,0,16,7},
            {20,17,19,1,0,0,8,13,18,7,5,0,0},
            {21,18,20,1,1,0,6,14,19,1,0,9,0},
            {22,19,21,1,1,0,9,15,20,0,0,17,0},
            {23,20,22,1,1,0,10,16,21,7,7,18,8},
            {24,21,23,1,0,0,11,17,22,8,5,19,0},
            {25,22,23,1,0,0,4,18,23,9,5,20,0},
            {26,23,24,1,1,0,4,19,24,4,8,19,0},
            {27,24,23,1,1,1,8,20,25,10,5,21,9},
            {28,25,23,1,0,1,8,20,26,8,5,21,10},
            {29,4,23,1,0,1,8,20,27,11,5,21,11},
            {30,0,23,1,0,1,8,20,28,11,5,21,12},
            {31,26,23,1,0,1,8,20,29,12,5,21,13},
            {32,27,23,1,0,1,8,21,24,13,1,21,14},
            {33,28,23,1,0,1,8,20,30,10,5,21,15},
            {34,29,23,1,1,1,8,20,31,8,5,21,15},
            };
        for (int b = 0;
             b < cqc2Rows();
             ++b) {
            int vals[13];
            vals[0] = cqc2ChartOrd(b);
            vals[1] = cqc2ChartSphere(b);
            vals[2] = cqc2ChartAnimal(b);
            vals[3] = cqc2ChartM(b);
            vals[4] = cqc2ChartF(b);
            vals[5] = cqc2ChartNh(b);
            vals[6] = cqc2ChartHead(b);
            vals[7] = cqc2ChartBody(b);
            vals[8] = cqc2ChartColor(b);
            vals[9] = cqc2ChartHolyday(b);
            vals[10] = cqc2ChartFreq(b);
            vals[11] = cqc2ChartForm(b);
            vals[12] = cqc2ChartPlace(b);
            for (int c = 0; c < 13;
                 ++c) {
                if (vals[c] != Ccqc2Chart[b][c])
                    ++bad;
            }
        }
        // the census walk (the batch rows, the pantheon counts, the roster
        // counts, the cleric flags)
    if (cqc2Round() != 870
            || cqc2Batch() != 2
            || cqc2PrintStart() != 136
            || cqc2PrintEnd() != 137
            || cqc2Rows() != 35
            || cqc2CARows() != 12
            || cqc2ChineseRows() != 15
            || cqc2CthulhuRows() != 8
            || cqc2MaleRows() != 35
            || cqc2FemaleRows() != 22
            || cqc2NonHumanRows() != 12
            || cqc2PrintedColumns() != 13
            || cqc2SphereCount() != 30
            || cqc2AnimalCount() != 25
            || cqc2HeadCount() != 12
            || cqc2BodyCount() != 22
            || cqc2ColorCount() != 32
            || cqc2HolyDayCount() != 14
            || cqc2FreqCount() != 9
            || cqc2FormCount() != 22
            || cqc2PlaceCount() != 16
            || cqc2TableCount() != 1
            || cqc2ChainCount() != 0
        )
            ++bad;
        // the parity pins (the headline Hastur divergence, the spelling pins,
        // the chart garbles)
    if (cqc2HasturSkyBluePrint() != 1
            || cqc2GraySpelledWithA() != 1
            || cqc2CthulhuPlaceNoGloss() != 1
            || cqc2ChartPrintsCthuga() != 1
            || cqc2TlGlyphGarbles() != 1
            || cqc2FeiLienSpaceRestored() != 1
            || cqc2SemicolonSpheres() != 1
            || cqc2ChineseNoNonHuman() != 1
            || cqc2EveryRowMale() != 1
            || cqc2CthulhuAllNonHuman() != 1
        )
            ++bad;
        // the head and tail rows (Quetzalcoatl 0, Yog-Sothoth 34, the
        // ordinals run)
    if (cqc2ChartOrd(0) != 0
            || cqc2ChartOrd(34) != 34
            || cqc2ChartSphere(0) != 0
            || cqc2ChartAnimal(0) != 0
            || cqc2ChartM(0) != 1
            || cqc2ChartF(0) != 1
            || cqc2ChartPlace(0) != 0
            || cqc2ChartSphere(34) != 29
            || cqc2ChartM(34) != 1
            || cqc2ChartF(34) != 1
            || cqc2ChartNh(34) != 1
            || cqc2ChartHolyday(34) != 8
            || cqc2ChartPlace(34) != 15
        )
            ++bad;
        // the Central American rows (the semicolon spheres, the waning-moon
        // frequency, the active volcanoes)
    if (cqc2ChartSphere(1) != 1
            || cqc2ChartHead(1) != 1
            || cqc2ChartSphere(2) != 2
            || cqc2ChartNh(2) != 1
            || cqc2ChartSphere(3) != 3
            || cqc2ChartBody(3) != 0
            || cqc2ChartColor(4) != 4
            || cqc2ChartFreq(4) != 2
            || cqc2ChartForm(4) != 4
            || cqc2ChartPlace(4) != 2
            || cqc2ChartF(5) != 0
            || cqc2ChartForm(5) != 5
            || cqc2ChartPlace(5) != 3
            || cqc2ChartFreq(6) != 3
            || cqc2ChartForm(6) != 6
            || cqc2ChartPlace(6) != 4
            || cqc2ChartColor(7) != 7
            || cqc2ChartSphere(8) != 8
            || cqc2ChartBody(8) != 1
            || cqc2ChartAnimal(9) != 9
            || cqc2ChartBody(10) != 4
            || cqc2ChartNh(10) != 1
            || cqc2ChartSphere(11) != 11
            || cqc2ChartBody(11) != 5
            || cqc2ChartPlace(11) != 5
        )
            ++bad;
        // the Chinese rows (the bald heads, the splint mail, the before-war
        // frequencies)
    if (cqc2ChartBody(12) != 6
            || cqc2ChartHolyday(12) != 6
            || cqc2ChartF(13) != 0
            || cqc2ChartFreq(13) != 6
            || cqc2ChartForm(13) != 11
            || cqc2ChartSphere(14) != 13
            || cqc2ChartHead(14) != 6
            || cqc2ChartForm(14) != 12
            || cqc2ChartPlace(15) != 6
            || cqc2ChartSphere(16) != 14
            || cqc2ChartBody(16) != 10
            || cqc2ChartSphere(17) != 15
            || cqc2ChartBody(17) != 7
            || cqc2ChartNh(18) != 0
            || cqc2ChartBody(18) != 11
            || cqc2ChartBody(19) != 12
            || cqc2ChartPlace(19) != 7
            || cqc2ChartSphere(20) != 17
            || cqc2ChartColor(20) != 18
            || cqc2ChartHead(22) != 9
            || cqc2ChartForm(22) != 17
            || cqc2ChartFreq(23) != 7
            || cqc2ChartPlace(23) != 8
            || cqc2ChartHead(24) != 11
            || cqc2ChartColor(24) != 22
            || cqc2ChartHolyday(25) != 9
            || cqc2ChartForm(25) != 20
            || cqc2ChartAnimal(26) != 24
            || cqc2ChartColor(26) != 24
        )
            ++bad;
        // the Cthulhu rows (the sky blue pin, the bare n/a raiment, the human
        // sacrifices)
    if (cqc2ChartColor(27) != 25
            || cqc2ChartPlace(27) != 9
            || cqc2ChartSphere(28) != 25
            || cqc2ChartNh(28) != 1
            || cqc2ChartColor(29) != 27
            || cqc2ChartFreq(29) != 5
            || cqc2ChartPlace(29) != 11
            || cqc2ChartColor(30) != 28
            || cqc2ChartHolyday(30) != 11
            || cqc2ChartPlace(30) != 12
            || cqc2ChartSphere(31) != 26
            || cqc2ChartColor(31) != 29
            || cqc2ChartPlace(31) != 13
            || cqc2ChartSphere(32) != 27
            || cqc2ChartBody(32) != 21
            || cqc2ChartHolyday(32) != 13
            || cqc2ChartFreq(32) != 1
            || cqc2ChartColor(33) != 30
            || cqc2ChartColor(34) != 31
        )
            ++bad;
        // the cleric flags (the female and non-human census cells)
    if (cqc2ChartF(1) != 1
            || cqc2ChartF(5) != 0
            || cqc2ChartF(13) != 0
            || cqc2ChartF(18) != 0
            || cqc2ChartF(24) != 0
            || cqc2ChartF(25) != 0
            || cqc2ChartF(27) != 1
            || cqc2ChartF(34) != 1
            || cqc2ChartNh(3) != 0
            || cqc2ChartNh(12) != 0
            || cqc2ChartNh(27) != 1
            || cqc2ChartNh(28) != 1
            || cqc2ChartNh(30) != 1
            || cqc2ChartNh(32) != 1
            || cqc2ChartNh(33) != 1
        )
            ++bad;
        printf("R870 clerical chart batch two audit: bad %d\n", bad);
        if (bad) return 1;
    }
