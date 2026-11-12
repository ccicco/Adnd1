    // ---- R876 clerical chart batch eight audit ----
    // APPENDIX 3: THE CLERICAL QUICK-REFERENCE CHARTS, BATCH EIGHT - the D&DG
    // walk round twenty-eight, print p. 143: the eighth and LAST batch of
    // deity rows - the twenty-one Norse rows (the nineteen data rows plus the
    // Surtur and Thrym cross-references) and the seven Sumerian rows - riding
    // the roster data file. NO GAP FLIP - the App 3 box stays open: the flip
    // was held one more round per Curtiss (the R869 no-flip precedent extends
    // past the last chart batch; gap_flips reads empty, the census holds
    // 20/4). The print voice is the ROTATED tesseract pass, collated against
    // the 1eonline L&L per-deity chart rows. The headline adjudications: the
    // Frigga female-only flag (the geometry seats the single X at the F
    // column, the L&L voice agrees) and the Hel male-only flag (the same
    // class); the Thor form burnt animals pinned by print over the L&L
    // crafted items (eyeball flag, the R869 Druaga precedent); the Frey
    // ornate helm restored over the L&L orntate garble; the Loki strife; fire
    // semicolon pinned by print; the Uty and idun name garbles restored per
    // the R865/R866 pins; the Surtur and Thrym cross-reference rows pinned as
    // grid rows with 0-sentinel fields (their chart data landed in R875).
    {
        using namespace rules;
        int bad = 0;
    if (cqc8Round() != 876
            || cqc8Batch() != 8
            || cqc8PrintStart() != 143
            || cqc8PrintEnd() != 143
            || cqc8Rows() != 28
            || cqc8NorseRows() != 21
            || cqc8SumerianRows() != 7
            || cqc8CrossrefRows() != 2
            || cqc8MaleRows() != 25
            || cqc8FemaleRows() != 17
            || cqc8NonHumanFlagRows() != 3
            || cqc8PrintedColumns() != 13
            || cqc8SphereCount() != 25
            || cqc8AnimalCount() != 22
            || cqc8HeadCount() != 10
            || cqc8BodyCount() != 13
            || cqc8ColorCount() != 24
            || cqc8HolyDayCount() != 12
            || cqc8FreqCount() != 5
            || cqc8FormCount() != 10
            || cqc8PlaceCount() != 5
            || cqc8TableCount() != 1
            || cqc8ChainCount() != 0
            || !cqc8NoGapFlip()
            || !cqc8CrossrefRowsPinned()
            || !cqc8FriggaFemaleOnly()
            || !cqc8HelMaleOnly()
            || !cqc8ThorFormPrintPin()
            || !cqc8OrnateHelmRestored()
            || !cqc8LokiSemicolonPinned()
            || !cqc8NameGarblesRestored()
            || !cqc8WrapLinesRestored()
        )
            ++bad;
        // the the clerical chart batch eight grid grid
        int Ccqc8Chart[28][13] = {
            {0,0,0,1,0,0,0,0,0,0,0,0,0},
            {1,1,1,1,1,0,1,1,1,1,1,0,0},
            {2,2,2,1,1,0,2,0,2,2,1,1,1},
            {3,3,3,1,1,0,3,2,3,0,0,1,1},
            {4,4,4,1,1,0,4,0,4,3,2,2,2},
            {5,5,5,1,1,1,5,3,5,3,2,2,2},
            {6,6,6,1,1,0,6,4,6,2,1,1,0},
            {7,7,7,0,1,0,4,5,7,4,1,0,0},
            {8,8,8,1,0,0,0,6,8,5,3,0,0},
            {9,9,9,1,0,0,4,7,9,6,3,3,0},
            {10,10,10,1,1,0,4,8,10,7,3,1,3},
            {11,11,11,1,0,0,0,3,11,6,3,0,0},
            {12,12,12,1,0,0,7,0,12,2,1,4,0},
            {13,13,13,1,0,0,0,0,13,8,4,0,0},
            {14,14,14,1,1,0,0,9,14,2,1,5,0},
            {15,0,0,0,0,0,0,0,0,0,0,0,0},
            {16,15,15,1,1,0,0,0,15,4,1,6,0},
            {17,0,0,0,0,0,0,0,0,0,0,0,0},
            {18,16,16,1,1,0,0,10,16,4,1,1,0},
            {19,17,17,1,1,0,8,11,17,0,0,0,3},
            {20,12,2,1,0,0,4,3,18,9,3,0,0},
            {21,18,18,1,1,0,4,12,19,2,1,7,4},
            {22,19,19,1,1,1,4,12,20,10,1,4,4},
            {23,20,7,1,1,0,9,12,21,2,1,8,4},
            {24,21,20,1,1,1,9,12,17,0,0,9,4},
            {25,22,4,1,0,0,4,12,22,2,1,7,4},
            {26,23,21,1,1,0,4,12,23,7,3,5,4},
            {27,24,6,1,0,0,4,12,18,11,3,5,4},
            };
        for (int b = 0;
             b < cqc8Rows();
             ++b) {
            int vals[13];
            vals[0] = cqc8ChartOrd(b);
            vals[1] = cqc8ChartSphere(b);
            vals[2] = cqc8ChartAnimal(b);
            vals[3] = cqc8ChartM(b);
            vals[4] = cqc8ChartF(b);
            vals[5] = cqc8ChartNh(b);
            vals[6] = cqc8ChartHead(b);
            vals[7] = cqc8ChartBody(b);
            vals[8] = cqc8ChartColor(b);
            vals[9] = cqc8ChartHolyday(b);
            vals[10] = cqc8ChartFreq(b);
            vals[11] = cqc8ChartForm(b);
            vals[12] = cqc8ChartPlace(b);
            for (int c = 0; c < 13;
                 ++c) {
                if (vals[c] != Ccqc8Chart[b][c])
                    ++bad;
            }
        }
        // the census walk (the batch rows, the pantheon counts, the roster
        // counts)
    if (cqc8Round() != 876
            || cqc8Batch() != 8
            || cqc8PrintStart() != 143
            || cqc8PrintEnd() != 143
            || cqc8Rows() != 28
            || cqc8NorseRows() != 21
            || cqc8SumerianRows() != 7
            || cqc8CrossrefRows() != 2
            || cqc8MaleRows() != 25
            || cqc8FemaleRows() != 17
            || cqc8NonHumanFlagRows() != 3
            || cqc8PrintedColumns() != 13
            || cqc8SphereCount() != 25
            || cqc8AnimalCount() != 22
            || cqc8HeadCount() != 10
            || cqc8BodyCount() != 13
            || cqc8ColorCount() != 24
            || cqc8HolyDayCount() != 12
            || cqc8FreqCount() != 5
            || cqc8FormCount() != 10
            || cqc8PlaceCount() != 5
            || cqc8TableCount() != 1
            || cqc8ChainCount() != 0
        )
            ++bad;
        // the parity pins (the held flip, the cross-reference rows, the
        // geometry flags)
    if (cqc8NoGapFlip() != 1
            || cqc8CrossrefRowsPinned() != 1
            || cqc8FriggaFemaleOnly() != 1
            || cqc8HelMaleOnly() != 1
            || cqc8ThorFormPrintPin() != 1
            || cqc8OrnateHelmRestored() != 1
            || cqc8LokiSemicolonPinned() != 1
            || cqc8NameGarblesRestored() != 1
            || cqc8WrapLinesRestored() != 1
        )
            ++bad;
        // the head and tail rows (Odin 0, Utu 27, the ordinals run)
    if (cqc8ChartOrd(0) != 0
            || cqc8ChartOrd(27) != 27
            || cqc8ChartSphere(0) != 0
            || cqc8ChartSphere(27) != 24
            || cqc8ChartAnimal(0) != 0
            || cqc8ChartAnimal(27) != 6
            || cqc8ChartHead(0) != 0
            || cqc8ChartHead(27) != 4
            || cqc8ChartBody(0) != 0
            || cqc8ChartBody(27) != 12
            || cqc8ChartColor(0) != 0
            || cqc8ChartColor(27) != 18
            || cqc8ChartHolyday(0) != 0
            || cqc8ChartHolyday(27) != 11
            || cqc8ChartFreq(0) != 0
            || cqc8ChartFreq(27) != 3
            || cqc8ChartForm(0) != 0
            || cqc8ChartForm(27) != 5
            || cqc8ChartPlace(0) != 0
            || cqc8ChartPlace(27) != 4
            || cqc8ChartM(0) != 1
            || cqc8ChartF(0) != 0
            || cqc8ChartNh(0) != 0
            || cqc8ChartM(27) != 1
            || cqc8ChartF(27) != 0
            || cqc8ChartNh(27) != 0
        )
            ++bad;
        // the divergent rows (the Frigga female-only and Hel male-only flags,
        // the Frey ornate helm, the Thor burnt animals, the Loki semicolon)
    if (cqc8ChartM(7) != 0
            || cqc8ChartF(7) != 1
            || cqc8ChartNh(7) != 0
            || cqc8ChartM(9) != 1
            || cqc8ChartF(9) != 0
            || cqc8ChartNh(9) != 0
            || cqc8ChartHead(5) != 5
            || cqc8ChartForm(16) != 6
            || cqc8ChartSphere(11) != 11
            || cqc8ChartColor(9) != 9
            || cqc8ChartForm(9) != 3
            || cqc8ChartBody(8) != 6
            || cqc8ChartPlace(10) != 3
            || cqc8ChartColor(10) != 10
            || cqc8ChartPlace(2) != 1
        )
            ++bad;
        // the cross-reference rows (Surtur 15 and Thrym 17 - see Nonhumans'
        // Deities, the 0-sentinel fields)
    if (cqc8ChartOrd(15) != 15
            || cqc8ChartSphere(15) != 0
            || cqc8ChartAnimal(15) != 0
            || cqc8ChartHead(15) != 0
            || cqc8ChartBody(15) != 0
            || cqc8ChartColor(15) != 0
            || cqc8ChartHolyday(15) != 0
            || cqc8ChartFreq(15) != 0
            || cqc8ChartForm(15) != 0
            || cqc8ChartPlace(15) != 0
            || cqc8ChartM(15) != 0
            || cqc8ChartF(15) != 0
            || cqc8ChartNh(15) != 0
            || cqc8ChartOrd(17) != 17
            || cqc8ChartSphere(17) != 0
            || cqc8ChartAnimal(17) != 0
            || cqc8ChartHead(17) != 0
            || cqc8ChartBody(17) != 0
            || cqc8ChartColor(17) != 0
            || cqc8ChartHolyday(17) != 0
            || cqc8ChartFreq(17) != 0
            || cqc8ChartForm(17) != 0
            || cqc8ChartPlace(17) != 0
            || cqc8ChartM(17) != 0
            || cqc8ChartF(17) != 0
            || cqc8ChartNh(17) != 0
        )
            ++bad;
        // the cleric flags (every row's M/F/N-H marks: 25 male, 17 female, 3
        // non-human)
    if (cqc8ChartM(0) != 1
            || cqc8ChartF(0) != 0
            || cqc8ChartNh(0) != 0
            || cqc8ChartM(1) != 1
            || cqc8ChartF(1) != 1
            || cqc8ChartNh(1) != 0
            || cqc8ChartM(2) != 1
            || cqc8ChartF(2) != 1
            || cqc8ChartNh(2) != 0
            || cqc8ChartM(3) != 1
            || cqc8ChartF(3) != 1
            || cqc8ChartNh(3) != 0
            || cqc8ChartM(4) != 1
            || cqc8ChartF(4) != 1
            || cqc8ChartNh(4) != 0
            || cqc8ChartM(5) != 1
            || cqc8ChartF(5) != 1
            || cqc8ChartNh(5) != 1
            || cqc8ChartM(6) != 1
            || cqc8ChartF(6) != 1
            || cqc8ChartNh(6) != 0
            || cqc8ChartM(7) != 0
            || cqc8ChartF(7) != 1
            || cqc8ChartNh(7) != 0
            || cqc8ChartM(8) != 1
            || cqc8ChartF(8) != 0
            || cqc8ChartNh(8) != 0
            || cqc8ChartM(9) != 1
            || cqc8ChartF(9) != 0
            || cqc8ChartNh(9) != 0
            || cqc8ChartM(10) != 1
            || cqc8ChartF(10) != 1
            || cqc8ChartNh(10) != 0
            || cqc8ChartM(11) != 1
            || cqc8ChartF(11) != 0
            || cqc8ChartNh(11) != 0
            || cqc8ChartM(12) != 1
            || cqc8ChartF(12) != 0
            || cqc8ChartNh(12) != 0
            || cqc8ChartM(13) != 1
            || cqc8ChartF(13) != 0
            || cqc8ChartNh(13) != 0
            || cqc8ChartM(14) != 1
            || cqc8ChartF(14) != 1
            || cqc8ChartNh(14) != 0
            || cqc8ChartM(15) != 0
            || cqc8ChartF(15) != 0
            || cqc8ChartNh(15) != 0
            || cqc8ChartM(16) != 1
            || cqc8ChartF(16) != 1
            || cqc8ChartNh(16) != 0
            || cqc8ChartM(17) != 0
            || cqc8ChartF(17) != 0
            || cqc8ChartNh(17) != 0
            || cqc8ChartM(18) != 1
            || cqc8ChartF(18) != 1
            || cqc8ChartNh(18) != 0
            || cqc8ChartM(19) != 1
            || cqc8ChartF(19) != 1
            || cqc8ChartNh(19) != 0
            || cqc8ChartM(20) != 1
            || cqc8ChartF(20) != 0
            || cqc8ChartNh(20) != 0
            || cqc8ChartM(21) != 1
            || cqc8ChartF(21) != 1
            || cqc8ChartNh(21) != 0
            || cqc8ChartM(22) != 1
            || cqc8ChartF(22) != 1
            || cqc8ChartNh(22) != 1
            || cqc8ChartM(23) != 1
            || cqc8ChartF(23) != 1
            || cqc8ChartNh(23) != 0
            || cqc8ChartM(24) != 1
            || cqc8ChartF(24) != 1
            || cqc8ChartNh(24) != 1
            || cqc8ChartM(25) != 1
            || cqc8ChartF(25) != 0
            || cqc8ChartNh(25) != 0
            || cqc8ChartM(26) != 1
            || cqc8ChartF(26) != 1
            || cqc8ChartNh(26) != 0
            || cqc8ChartM(27) != 1
            || cqc8ChartF(27) != 0
            || cqc8ChartNh(27) != 0
        )
            ++bad;
        printf("R876 clerical chart batch eight audit: bad %d\n", bad);
        if (bad) return 1;
    }
