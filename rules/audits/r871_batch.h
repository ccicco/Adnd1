    // ---- R871 clerical chart batch three audit ----
    // APPENDIX 3: THE CLERICAL QUICK-REFERENCE CHARTS, BATCH THREE - the D&DG
    // walk round twenty-three, print pp. 138-139: the third batch of deity
    // rows - Egyptian (17), Finnish (11) - riding the roster data file, the
    // Egyptian block below the R870 Cthulhu tail on pdf 138; the App 3 gap
    // box stays open until the last chart batch lands. The print voice is the
    // ROTATED tesseract pass, collated against the 1eonline L&L per-deity
    // chart rows. The headline divergence: the L&L Seker row duplicates Shu -
    // the print reads the distinct Seker row (feathered helm, white tunic,
    // white, summer solstice, annually, jewelry) - pinned by print, eyeball
    // flag.
    {
        using namespace rules;
        int bad = 0;
    if (cqc3Round() != 871
            || cqc3Batch() != 3
            || cqc3PrintStart() != 138
            || cqc3PrintEnd() != 139
            || cqc3Rows() != 28
            || cqc3EgyRows() != 17
            || cqc3FinRows() != 11
            || cqc3MaleRows() != 27
            || cqc3FemaleRows() != 27
            || cqc3NonHumanRows() != 6
            || cqc3PrintedColumns() != 13
            || cqc3SphereCount() != 26
            || cqc3AnimalCount() != 27
            || cqc3HeadCount() != 15
            || cqc3BodyCount() != 26
            || cqc3ColorCount() != 24
            || cqc3HolyDayCount() != 11
            || cqc3FreqCount() != 6
            || cqc3FormCount() != 17
            || cqc3PlaceCount() != 5
            || cqc3TableCount() != 1
            || cqc3ChainCount() != 0
            || !cqc3SekerDistinctPrint()
            || !cqc3GebSpherePrint()
            || !cqc3SetSpherePrint()
            || !cqc3IsisMagicPinned()
            || !cqc3IlmatarFemaleOnly()
            || !cqc3BesVestRestored()
            || !cqc3UkkoChainMail()
            || !cqc3MielikkiLowercaseNature()
            || !cqc3IlmatarSoleFemaleOnly()
            || !cqc3FinnishNoNonHuman()
        )
            ++bad;
        // the the clerical chart batch three grid grid
        int Ccqc3Chart[28][13] = {
            {0,0,0,1,1,0,0,0,0,0,0,0,0},
            {1,1,1,1,0,0,1,1,1,1,1,1,0},
            {2,2,2,1,1,0,2,2,2,2,2,0,0},
            {3,3,3,1,1,1,2,3,3,3,3,2,0},
            {4,4,4,1,1,1,3,4,4,2,2,3,1},
            {5,5,5,1,1,0,4,5,5,4,2,0,0},
            {6,6,6,1,1,0,5,6,6,5,2,4,0},
            {7,7,7,1,1,0,1,7,7,6,4,5,1},
            {8,8,8,1,1,1,2,8,8,2,2,0,0},
            {9,9,9,1,1,0,2,9,9,4,2,0,0},
            {10,10,10,1,1,0,2,10,10,1,4,6,0},
            {11,11,11,1,1,1,6,11,11,4,2,4,0},
            {12,12,12,1,1,0,7,12,12,7,3,7,0},
            {13,13,13,1,1,1,6,13,13,2,2,0,0},
            {14,14,14,1,1,0,2,14,14,1,4,8,0},
            {15,15,15,1,1,0,8,15,15,3,3,2,0},
            {16,16,16,1,1,1,2,16,16,1,4,6,0},
            {17,17,17,1,1,0,9,17,17,3,3,9,2},
            {18,13,18,1,1,0,2,18,18,8,5,10,3},
            {19,18,19,0,1,0,2,19,12,2,2,11,2},
            {20,19,20,1,1,0,10,20,19,9,3,12,2},
            {21,20,21,1,1,0,11,21,20,10,3,13,2},
            {22,21,22,1,1,0,2,10,21,3,3,14,4},
            {23,22,5,1,1,0,12,22,8,8,5,10,3},
            {24,23,23,1,1,0,7,23,22,8,5,10,3},
            {25,23,24,1,1,0,13,15,16,8,5,10,3},
            {26,24,25,1,1,0,14,24,0,2,2,15,2},
            {27,25,26,1,1,0,2,25,23,4,2,16,2},
            };
        for (int b = 0;
             b < cqc3Rows();
             ++b) {
            int vals[13];
            vals[0] = cqc3ChartOrd(b);
            vals[1] = cqc3ChartSphere(b);
            vals[2] = cqc3ChartAnimal(b);
            vals[3] = cqc3ChartM(b);
            vals[4] = cqc3ChartF(b);
            vals[5] = cqc3ChartNh(b);
            vals[6] = cqc3ChartHead(b);
            vals[7] = cqc3ChartBody(b);
            vals[8] = cqc3ChartColor(b);
            vals[9] = cqc3ChartHolyday(b);
            vals[10] = cqc3ChartFreq(b);
            vals[11] = cqc3ChartForm(b);
            vals[12] = cqc3ChartPlace(b);
            for (int c = 0; c < 13;
                 ++c) {
                if (vals[c] != Ccqc3Chart[b][c])
                    ++bad;
            }
        }
        // the census walk (the batch rows, the pantheon counts, the roster
        // counts, the cleric flags)
    if (cqc3Round() != 871
            || cqc3Batch() != 3
            || cqc3PrintStart() != 138
            || cqc3PrintEnd() != 139
            || cqc3Rows() != 28
            || cqc3EgyRows() != 17
            || cqc3FinRows() != 11
            || cqc3MaleRows() != 27
            || cqc3FemaleRows() != 27
            || cqc3NonHumanRows() != 6
            || cqc3PrintedColumns() != 13
            || cqc3SphereCount() != 26
            || cqc3AnimalCount() != 27
            || cqc3HeadCount() != 15
            || cqc3BodyCount() != 26
            || cqc3ColorCount() != 24
            || cqc3HolyDayCount() != 11
            || cqc3FreqCount() != 6
            || cqc3FormCount() != 17
            || cqc3PlaceCount() != 5
            || cqc3TableCount() != 1
            || cqc3ChainCount() != 0
        )
            ++bad;
        // the parity pins (the headline Seker divergence, the empty-cell
        // spheres, the Ilmatar geometry pin)
    if (cqc3SekerDistinctPrint() != 1
            || cqc3GebSpherePrint() != 1
            || cqc3SetSpherePrint() != 1
            || cqc3IsisMagicPinned() != 1
            || cqc3IlmatarFemaleOnly() != 1
            || cqc3BesVestRestored() != 1
            || cqc3UkkoChainMail() != 1
            || cqc3MielikkiLowercaseNature() != 1
            || cqc3IlmatarSoleFemaleOnly() != 1
            || cqc3FinnishNoNonHuman() != 1
        )
            ++bad;
        // the head and tail rows (Ra 0, Untamo 27, the ordinals run)
    if (cqc3ChartOrd(0) != 0
            || cqc3ChartOrd(27) != 27
            || cqc3ChartSphere(0) != 0
            || cqc3ChartHead(0) != 0
            || cqc3ChartM(0) != 1
            || cqc3ChartF(0) != 1
            || cqc3ChartHolyday(0) != 0
            || cqc3ChartFreq(0) != 0
            || cqc3ChartPlace(0) != 0
            || cqc3ChartSphere(27) != 25
            || cqc3ChartBody(27) != 25
            || cqc3ChartM(27) != 1
            || cqc3ChartF(27) != 1
            || cqc3ChartPlace(27) != 2
        )
            ++bad;
        // the Egyptian rows (the Seker pin cells, the Ptah ornaments, the
        // Anhur frequency)
    if (cqc3ChartFreq(1) != 1
            || cqc3ChartForm(1) != 1
            || cqc3ChartF(1) != 0
            || cqc3ChartSphere(2) != 2
            || cqc3ChartBody(2) != 2
            || cqc3ChartForm(3) != 2
            || cqc3ChartNh(4) != 1
            || cqc3ChartPlace(4) != 1
            || cqc3ChartBody(5) != 5
            || cqc3ChartSphere(6) != 6
            || cqc3ChartHead(6) != 5
            || cqc3ChartBody(7) != 7
            || cqc3ChartPlace(7) != 1
            || cqc3ChartSphere(8) != 8
            || cqc3ChartNh(8) != 1
            || cqc3ChartSphere(9) != 9
            || cqc3ChartColor(9) != 9
            || cqc3ChartSphere(10) != 10
            || cqc3ChartForm(10) != 6
            || cqc3ChartBody(11) != 11
            || cqc3ChartColor(11) != 11
            || cqc3ChartNh(11) != 1
            || cqc3ChartHead(12) != 7
            || cqc3ChartBody(12) != 12
            || cqc3ChartColor(12) != 12
            || cqc3ChartHolyday(12) != 7
            || cqc3ChartFreq(12) != 3
            || cqc3ChartForm(12) != 7
            || cqc3ChartSphere(13) != 13
            || cqc3ChartColor(13) != 13
            || cqc3ChartBody(14) != 14
            || cqc3ChartColor(14) != 14
            || cqc3ChartSphere(15) != 15
            || cqc3ChartBody(16) != 16
            || cqc3ChartNh(16) != 1
        )
            ++bad;
        // the Finnish rows (the special hall, the n/a classes, the Ilmatar
        // flags)
    if (cqc3ChartPlace(17) != 2
            || cqc3ChartForm(17) != 9
            || cqc3ChartHolyday(18) != 8
            || cqc3ChartFreq(18) != 5
            || cqc3ChartForm(18) != 10
            || cqc3ChartPlace(18) != 3
            || cqc3ChartSphere(19) != 18
            || cqc3ChartM(19) != 0
            || cqc3ChartF(19) != 1
            || cqc3ChartNh(19) != 0
            || cqc3ChartPlace(19) != 2
            || cqc3ChartForm(20) != 12
            || cqc3ChartHead(21) != 11
            || cqc3ChartForm(21) != 13
            || cqc3ChartColor(22) != 21
            || cqc3ChartPlace(22) != 4
            || cqc3ChartBody(23) != 22
            || cqc3ChartColor(24) != 22
            || cqc3ChartSphere(25) != 23
            || cqc3ChartSphere(26) != 24
            || cqc3ChartBody(26) != 24
            || cqc3ChartForm(26) != 15
        )
            ++bad;
        // the cleric flags (the female and non-human census cells)
    if (cqc3ChartF(0) != 1
            || cqc3ChartF(2) != 1
            || cqc3ChartNh(3) != 1
            || cqc3ChartNh(4) != 1
            || cqc3ChartNh(8) != 1
            || cqc3ChartNh(13) != 1
            || cqc3ChartNh(16) != 1
            || cqc3ChartF(17) != 1
            || cqc3ChartF(18) != 1
            || cqc3ChartF(23) != 1
            || cqc3ChartF(25) != 1
            || cqc3ChartF(26) != 1
            || cqc3ChartNh(17) != 0
            || cqc3ChartNh(26) != 0
        )
            ++bad;
        printf("R871 clerical chart batch three audit: bad %d\n", bad);
        if (bad) return 1;
    }
