    // ---- R869 clerical chart batch one audit ----
    // APPENDIX 3: THE CLERICAL QUICK-REFERENCE CHARTS, BATCH ONE - the D&DG
    // walk round twenty-one, print pp. 134-135: the legend and ordering
    // doctrine of the chart intro, and the first batch of deity rows -
    // American Indian (9), Babylonian (8), Celtic (12) - riding the roster
    // data file; the App 3 gap box stays open until the last chart batch
    // lands. The chart prints landscape: the print voice is the ROTATED
    // tesseract pass (pdfimages + PIL rotate -90, pNNN_rot_*), collated
    // against the 1eonline L&L per-deity chart rows. The headline divergence:
    // the print reads a female-clerics X for Druaga where the L&L voice reads
    // male-only - pinned by print, eyeball flag.
    {
        using namespace rules;
        int bad = 0;
    if (cqcRound() != 869
            || cqcBatch() != 1
            || cqcPrintStart() != 134
            || cqcPrintEnd() != 135
            || cqcRows() != 29
            || cqcAIRows() != 9
            || cqcBabRows() != 8
            || cqcCelRows() != 12
            || cqcMaleRows() != 29
            || cqcFemaleRows() != 27
            || cqcNonHumanRows() != 6
            || cqcNoAnimalRows() != 12
            || cqcPrintedColumns() != 13
            || cqcSphereCount() != 25
            || cqcAnimalCount() != 16
            || cqcHeadCount() != 9
            || cqcBodyCount() != 15
            || cqcColorCount() != 23
            || cqcHolyDayCount() != 8
            || cqcFreqCount() != 7
            || cqcFormCount() != 21
            || cqcPlaceCount() != 15
            || cqcTableCount() != 1
            || cqcChainCount() != 0
            || !cqcQuickReferencePurpose()
            || !cqcAlphabeticalWithinPantheon()
            || !cqcGuidelinesOnly()
            || !cqcRankByColor()
            || !cqcOrdainedAnytime()
            || !cqcSphereMeaning()
            || !cqcAnimalMeaning()
            || !cqcClericsMeaning()
            || !cqcRaimentMeaning()
            || !cqcColorsMeaning()
            || !cqcHolyDaysMeaning()
            || !cqcAcknowledgementNotGranting()
            || !cqcSacrificeMeaning()
            || !cqcPlaceMeaning()
            || !cqcDruagaFemaleClericsPrint()
            || !cqcSphereSemicolonsPrint()
            || !cqcHastseziniJadeGreen()
            || !cqcArawnAtDeath()
            || !cqcNoArthurianRows()
            || !cqcSilvanusStrayQuote()
        )
            ++bad;
        // the the clerical chart batch one grid grid
        int CcqcChart[29][13] = {
            {0,0,0,1,1,0,0,0,0,0,0,0,0},
            {1,1,1,1,1,0,1,1,1,0,0,0,0},
            {2,2,2,1,1,0,1,2,2,0,0,0,1},
            {3,3,3,1,1,0,0,3,3,0,0,1,2},
            {4,4,4,1,1,0,1,4,4,1,0,0,2},
            {5,5,5,1,1,0,2,5,5,2,0,2,0},
            {6,6,6,1,1,0,2,5,6,3,1,0,3},
            {7,7,3,1,1,1,0,0,7,0,0,3,0},
            {8,8,7,1,1,0,0,6,8,0,0,4,2},
            {9,9,8,1,1,0,3,7,9,4,2,5,4},
            {10,10,0,1,1,0,4,7,10,3,3,6,4},
            {11,11,9,1,1,0,4,8,11,4,2,7,4},
            {12,3,10,1,1,0,4,9,12,5,4,6,4},
            {13,12,11,1,1,0,5,10,13,6,2,8,5},
            {14,13,12,1,1,0,4,11,14,7,2,9,4},
            {15,14,13,1,1,1,4,12,0,6,2,10,4},
            {16,15,14,1,1,0,4,7,4,4,2,11,4},
            {17,16,15,1,0,0,6,7,15,6,2,12,6},
            {18,17,15,1,0,0,7,7,0,0,5,13,7},
            {19,18,15,1,1,0,7,7,16,0,6,14,8},
            {20,19,15,1,1,1,0,7,17,6,2,15,9},
            {21,20,15,1,1,0,8,13,18,0,0,6,10},
            {22,21,15,1,1,1,0,7,19,0,0,8,11},
            {23,22,15,1,1,1,0,7,20,0,0,12,12},
            {24,23,15,1,1,0,7,7,7,0,0,16,13},
            {25,8,15,1,1,0,7,14,21,0,6,17,8},
            {26,8,15,1,1,0,7,14,22,0,6,18,8},
            {27,1,15,1,1,0,0,7,5,0,0,19,12},
            {28,24,15,1,1,1,0,7,13,5,0,20,14},
            };
        for (int b = 0;
             b < cqcRows();
             ++b) {
            int vals[13];
            vals[0] = cqcChartOrd(b);
            vals[1] = cqcChartSphere(b);
            vals[2] = cqcChartAnimal(b);
            vals[3] = cqcChartM(b);
            vals[4] = cqcChartF(b);
            vals[5] = cqcChartNh(b);
            vals[6] = cqcChartHead(b);
            vals[7] = cqcChartBody(b);
            vals[8] = cqcChartColor(b);
            vals[9] = cqcChartHolyday(b);
            vals[10] = cqcChartFreq(b);
            vals[11] = cqcChartForm(b);
            vals[12] = cqcChartPlace(b);
            for (int c = 0; c < 13;
                 ++c) {
                if (vals[c] != CcqcChart[b][c])
                    ++bad;
            }
        }
        // the census walk (the batch rows, the pantheon counts, the roster
        // counts, the cleric flags)
    if (cqcRound() != 869
            || cqcBatch() != 1
            || cqcPrintStart() != 134
            || cqcPrintEnd() != 135
            || cqcRows() != 29
            || cqcAIRows() != 9
            || cqcBabRows() != 8
            || cqcCelRows() != 12
            || cqcMaleRows() != 29
            || cqcFemaleRows() != 27
            || cqcNonHumanRows() != 6
            || cqcNoAnimalRows() != 12
            || cqcSphereCount() != 25
            || cqcAnimalCount() != 16
            || cqcHeadCount() != 9
            || cqcBodyCount() != 15
            || cqcColorCount() != 23
            || cqcHolyDayCount() != 8
            || cqcFreqCount() != 7
            || cqcFormCount() != 21
            || cqcPlaceCount() != 15
            || cqcPrintedColumns() != 13
            || cqcTableCount() != 1
            || cqcChainCount() != 0
        )
            ++bad;
        // the chart doctrine (the ordering, the legend definitions, the
        // holy-days caveat)
    if (cqcQuickReferencePurpose() != 1
            || cqcAlphabeticalWithinPantheon() != 1
            || cqcGuidelinesOnly() != 1
            || cqcRankByColor() != 1
            || cqcOrdainedAnytime() != 1
            || cqcSphereMeaning() != 1
            || cqcAnimalMeaning() != 1
            || cqcClericsMeaning() != 1
            || cqcRaimentMeaning() != 1
            || cqcColorsMeaning() != 1
            || cqcHolyDaysMeaning() != 1
            || cqcAcknowledgementNotGranting() != 1
            || cqcSacrificeMeaning() != 1
            || cqcPlaceMeaning() != 1
        )
            ++bad;
        // the head and tail rows (Raven 0, Silvanus 28, the ordinals run)
    if (cqcChartOrd(0) != 0
            || cqcChartOrd(28) != 28
            || cqcChartSphere(0) != 0
            || cqcChartAnimal(0) != 0
            || cqcChartM(0) != 1
            || cqcChartF(0) != 1
            || cqcChartPlace(0) != 0
            || cqcChartSphere(28) != 24
            || cqcChartM(28) != 1
            || cqcChartF(28) != 1
            || cqcChartNh(28) != 1
            || cqcChartHolyday(28) != 5
            || cqcChartPlace(28) != 14
        )
            ++bad;
        // the American Indian rows (the spheres, the forms, the places of the
        // nine)
    if (cqcChartSphere(1) != 1
            || cqcChartForm(1) != 0
            || cqcChartPlace(1) != 0
            || cqcChartSphere(2) != 2
            || cqcChartAnimal(2) != 2
            || cqcChartPlace(2) != 1
            || cqcChartColor(3) != 3
            || cqcChartBody(3) != 3
            || cqcChartForm(3) != 1
            || cqcChartPlace(3) != 2
            || cqcChartSphere(4) != 4
            || cqcChartHolyday(4) != 1
            || cqcChartPlace(4) != 2
            || cqcChartSphere(5) != 5
            || cqcChartForm(5) != 2
            || cqcChartSphere(6) != 6
            || cqcChartHolyday(6) != 3
            || cqcChartFreq(6) != 1
            || cqcChartPlace(6) != 3
            || cqcChartNh(7) != 1
            || cqcChartFreq(7) != 0
            || cqcChartForm(7) != 3
            || cqcChartForm(8) != 4
            || cqcChartPlace(8) != 2
        )
            ++bad;
        // the Babylonian rows (Anu the brass skullcap, Anshar the annually,
        // the frequency classes)
    if (cqcChartHead(9) != 3
            || cqcChartBody(9) != 7
            || cqcChartColor(9) != 9
            || cqcChartHolyday(9) != 4
            || cqcChartFreq(9) != 2
            || cqcChartForm(9) != 5
            || cqcChartHolyday(10) != 3
            || cqcChartFreq(10) != 3
            || cqcChartForm(10) != 6
            || cqcChartColor(12) != 12
            || cqcChartFreq(12) != 4
            || cqcChartForm(12) != 6
            || cqcChartBody(13) != 10
            || cqcChartForm(13) != 8
            || cqcChartPlace(13) != 5
            || cqcChartSphere(14) != 13
            || cqcChartHolyday(15) != 6
            || cqcChartForm(15) != 10
            || cqcChartNh(15) != 1
            || cqcChartFreq(16) != 2
            || cqcChartForm(16) != 11
            || cqcChartPlace(16) != 4
        )
            ++bad;
        // the Druaga divergence row (the print reads the female-clerics X)
    if (cqcChartM(11) != 1
            || cqcChartF(11) != 1
            || cqcChartNh(11) != 0
            || cqcChartSphere(11) != 11
            || cqcChartAnimal(11) != 9
            || cqcChartColor(11) != 11
            || cqcChartForm(11) != 7
            || cqcChartHead(11) != 4
            || cqcChartBody(11) != 8
        )
            ++bad;
        // the Celtic rows (Dagda the grove, Arawn the at-death grave, Brigit
        // the verse)
    if (cqcChartSphere(17) != 16
            || cqcChartF(17) != 0
            || cqcChartNh(17) != 0
            || cqcChartHead(17) != 6
            || cqcChartColor(17) != 15
            || cqcChartPlace(17) != 6
            || cqcChartF(18) != 0
            || cqcChartFreq(18) != 5
            || cqcChartForm(18) != 13
            || cqcChartPlace(18) != 7
            || cqcChartFreq(19) != 6
            || cqcChartForm(19) != 14
            || cqcChartPlace(19) != 8
            || cqcChartFreq(20) != 2
            || cqcChartForm(20) != 15
            || cqcChartNh(20) != 1
            || cqcChartHead(21) != 8
            || cqcChartPlace(21) != 10
        )
            ++bad;
        // the Celtic raiment and places (the helm and armor pairs, the
        // anywhere rows)
    if (cqcChartHead(25) != 7
            || cqcChartBody(25) != 14
            || cqcChartForm(25) != 17
            || cqcChartPlace(25) != 8
            || cqcChartHead(26) != 7
            || cqcChartBody(26) != 14
            || cqcChartForm(26) != 18
            || cqcChartForm(27) != 19
            || cqcChartPlace(27) != 12
            || cqcChartColor(23) != 20
            || cqcChartForm(23) != 12
            || cqcChartPlace(23) != 12
            || cqcChartForm(22) != 8
            || cqcChartPlace(22) != 11
            || cqcChartForm(24) != 16
            || cqcChartHead(24) != 7
        )
            ++bad;
        // the non-human clerics rows (Snake-Man, Nergal, Diancecht, Goibhnie,
        // Lugh, Silvanus)
    if (cqcChartNh(7) != 1
            || cqcChartNh(15) != 1
            || cqcChartNh(20) != 1
            || cqcChartNh(22) != 1
            || cqcChartNh(23) != 1
            || cqcChartNh(28) != 1
            || cqcChartAnimal(20) != 15
            || cqcChartColor(22) != 19
            || cqcChartSphere(22) != 21
            || cqcChartFreq(22) != 0
            || cqcChartPlace(22) != 11
        )
            ++bad;
        // the parity and garble pins (the print-divergence doctrine of the
        // round)
    if (cqcDruagaFemaleClericsPrint() != 1
            || cqcSphereSemicolonsPrint() != 1
            || cqcHastseziniJadeGreen() != 1
            || cqcArawnAtDeath() != 1
            || cqcNoArthurianRows() != 1
            || cqcSilvanusStrayQuote() != 1
        )
            ++bad;
        printf("R869 clerical chart batch one audit: bad %d\n", bad);
        if (bad) return 1;
    }
