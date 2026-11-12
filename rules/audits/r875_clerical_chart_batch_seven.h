    // ---- R875 clerical chart batch seven audit ----
    // APPENDIX 3: THE CLERICAL QUICK-REFERENCE CHARTS, BATCH SEVEN - the D&DG
    // walk round twenty-seven, print p. 142: the seventh batch of deity rows
    // - the twenty-four Nonhumans' Deities rows (the twenty R864 mythos
    // beings plus Demogorgon, Surtur, Thrym and Yeenoghu) - riding the roster
    // data file; the App 3 gap box stays open until the last chart batch
    // lands. The print voice is the ROTATED tesseract pass, collated against
    // the 1eonline L&L per-deity chart rows. The headline geometry: every row
    // reads the N-H-only flag (all 24 X marks at the N-H column, no M or F
    // mark in the batch).
    {
        using namespace rules;
        int bad = 0;
    if (cqc7Round() != 875
            || cqc7Batch() != 7
            || cqc7PrintStart() != 142
            || cqc7PrintEnd() != 142
            || cqc7Rows() != 24
            || cqc7NonhumanRows() != 24
            || cqc7MaleRows() != 0
            || cqc7FemaleRows() != 0
            || cqc7NonHumanFlagRows() != 24
            || cqc7PrintedColumns() != 13
            || cqc7SphereCount() != 24
            || cqc7AnimalCount() != 16
            || cqc7HeadCount() != 11
            || cqc7BodyCount() != 21
            || cqc7ColorCount() != 24
            || cqc7HolyDayCount() != 10
            || cqc7FreqCount() != 6
            || cqc7FormCount() != 15
            || cqc7PlaceCount() != 15
            || cqc7TableCount() != 1
            || cqc7ChainCount() != 0
            || !cqc7AllNonHumanOnly()
            || !cqc7NameGarblesRestored()
            || !cqc7SeqaGreenRestored()
            || !cqc7GrolantorGarblesRestored()
            || !cqc7WarHelmFolds()
            || !cqc7GruumshStrays()
            || !cqc7LolthStrays()
            || !cqc7YondallaColonGlyph()
            || !cqc7DemogorgonPrintOnly()
            || !cqc7NoHumanClerics()
        )
            ++bad;
        // the the clerical chart batch seven grid grid
        int Ccqc7Chart[24][13] = {
            {0,0,0,0,0,1,0,0,0,0,0,0,0},
            {1,1,1,0,0,1,1,1,1,1,0,1,1},
            {2,2,2,0,0,1,2,2,2,2,1,2,2},
            {3,3,1,0,0,1,2,3,3,3,2,3,3},
            {4,4,3,0,0,1,2,3,4,3,2,3,4},
            {5,5,1,0,0,1,3,4,5,0,0,4,5},
            {6,6,4,0,0,1,4,5,6,3,2,3,3},
            {7,7,5,0,0,1,3,6,7,0,0,5,6},
            {8,8,1,0,0,1,4,7,8,4,0,5,5},
            {9,9,6,0,0,1,5,8,9,5,0,6,7},
            {10,10,7,0,0,1,2,9,10,6,3,7,8},
            {11,11,8,0,0,1,6,10,11,4,0,8,9},
            {12,12,1,0,0,1,7,8,12,0,0,9,7},
            {13,13,1,0,0,1,8,11,13,5,0,10,10},
            {14,14,9,0,0,1,9,12,14,7,4,11,11},
            {15,15,10,0,0,1,2,3,15,2,1,6,8},
            {16,16,11,0,0,1,2,13,16,4,0,12,12},
            {17,17,1,0,0,1,2,14,17,4,0,13,13},
            {18,18,12,0,0,1,2,15,18,3,2,3,3},
            {19,19,13,0,0,1,3,16,19,8,2,3,3},
            {20,20,14,0,0,1,10,17,20,6,2,3,3},
            {21,21,1,0,0,1,3,18,21,3,2,3,4},
            {22,22,1,0,0,1,4,19,22,1,0,5,7},
            {23,23,15,0,0,1,2,20,23,9,5,14,14},
            };
        for (int b = 0;
             b < cqc7Rows();
             ++b) {
            int vals[13];
            vals[0] = cqc7ChartOrd(b);
            vals[1] = cqc7ChartSphere(b);
            vals[2] = cqc7ChartAnimal(b);
            vals[3] = cqc7ChartM(b);
            vals[4] = cqc7ChartF(b);
            vals[5] = cqc7ChartNh(b);
            vals[6] = cqc7ChartHead(b);
            vals[7] = cqc7ChartBody(b);
            vals[8] = cqc7ChartColor(b);
            vals[9] = cqc7ChartHolyday(b);
            vals[10] = cqc7ChartFreq(b);
            vals[11] = cqc7ChartForm(b);
            vals[12] = cqc7ChartPlace(b);
            for (int c = 0; c < 13;
                 ++c) {
                if (vals[c] != Ccqc7Chart[b][c])
                    ++bad;
            }
        }
        // the census walk (the batch rows, the nonhuman counts, the roster
        // counts, the zero M/F flags)
    if (cqc7Round() != 875
            || cqc7Batch() != 7
            || cqc7PrintStart() != 142
            || cqc7PrintEnd() != 142
            || cqc7Rows() != 24
            || cqc7NonhumanRows() != 24
            || cqc7MaleRows() != 0
            || cqc7FemaleRows() != 0
            || cqc7NonHumanFlagRows() != 24
            || cqc7PrintedColumns() != 13
            || cqc7SphereCount() != 24
            || cqc7AnimalCount() != 16
            || cqc7HeadCount() != 11
            || cqc7BodyCount() != 21
            || cqc7ColorCount() != 24
            || cqc7HolyDayCount() != 10
            || cqc7FreqCount() != 6
            || cqc7FormCount() != 15
            || cqc7PlaceCount() != 15
            || cqc7TableCount() != 1
            || cqc7ChainCount() != 0
        )
            ++bad;
        // the parity pins (the N-H-only geometry, the name garbles, the folds
        // and strays)
    if (cqc7AllNonHumanOnly() != 1
            || cqc7NameGarblesRestored() != 1
            || cqc7SeqaGreenRestored() != 1
            || cqc7GrolantorGarblesRestored() != 1
            || cqc7WarHelmFolds() != 1
            || cqc7GruumshStrays() != 1
            || cqc7LolthStrays() != 1
            || cqc7YondallaColonGlyph() != 1
            || cqc7DemogorgonPrintOnly() != 1
            || cqc7NoHumanClerics() != 1
        )
            ++bad;
        // the head and tail rows (Blibdoolpoolp 0, Yondalla 23, the ordinals
        // run)
    if (cqc7ChartOrd(0) != 0
            || cqc7ChartNh(0) != 1
            || cqc7ChartM(0) != 0
            || cqc7ChartF(0) != 0
            || cqc7ChartHead(0) != 0
            || cqc7ChartBody(0) != 0
            || cqc7ChartColor(0) != 0
            || cqc7ChartHolyday(0) != 0
            || cqc7ChartFreq(0) != 0
            || cqc7ChartForm(0) != 0
            || cqc7ChartPlace(0) != 0
            || cqc7ChartOrd(23) != 23
            || cqc7ChartSphere(23) != 23
            || cqc7ChartAnimal(23) != 15
            || cqc7ChartHead(23) != 2
            || cqc7ChartBody(23) != 20
            || cqc7ChartColor(23) != 23
            || cqc7ChartHolyday(23) != 9
            || cqc7ChartFreq(23) != 5
            || cqc7ChartForm(23) != 14
            || cqc7ChartPlace(23) != 14
        )
            ++bad;
        // the elf and goblin rows (the wraps, the sea green pin, the
        // gray-green class)
    if (cqc7ChartHead(1) != 1
            || cqc7ChartBody(1) != 1
            || cqc7ChartColor(1) != 1
            || cqc7ChartHolyday(1) != 1
            || cqc7ChartBody(2) != 2
            || cqc7ChartColor(2) != 2
            || cqc7ChartHolyday(2) != 2
            || cqc7ChartFreq(2) != 1
            || cqc7ChartForm(2) != 2
            || cqc7ChartPlace(2) != 2
            || cqc7ChartSphere(3) != 3
            || cqc7ChartColor(3) != 3
            || cqc7ChartHead(8) != 4
            || cqc7ChartColor(8) != 8
            || cqc7ChartForm(8) != 5
            || cqc7ChartHead(12) != 7
            || cqc7ChartColor(12) != 12
            || cqc7ChartFreq(12) != 0
            || cqc7ChartForm(12) != 9
            || cqc7ChartHead(13) != 8
            || cqc7ChartBody(13) != 11
            || cqc7ChartColor(13) != 13
            || cqc7ChartFreq(13) != 0
            || cqc7ChartForm(13) != 10
            || cqc7ChartPlace(13) != 10
        )
            ++bad;
        // the giant and monster rows (the name-restored rows, the print-only
        // rows)
    if (cqc7ChartAnimal(6) != 4
            || cqc7ChartHead(6) != 4
            || cqc7ChartBody(6) != 5
            || cqc7ChartColor(6) != 6
            || cqc7ChartBody(7) != 6
            || cqc7ChartColor(7) != 7
            || cqc7ChartForm(7) != 5
            || cqc7ChartPlace(7) != 6
            || cqc7ChartBody(14) != 12
            || cqc7ChartColor(14) != 14
            || cqc7ChartFreq(14) != 4
            || cqc7ChartPlace(14) != 11
            || cqc7ChartColor(15) != 15
            || cqc7ChartHolyday(15) != 2
            || cqc7ChartFreq(15) != 1
            || cqc7ChartPlace(15) != 8
            || cqc7ChartSphere(18) != 18
            || cqc7ChartAnimal(18) != 12
            || cqc7ChartColor(18) != 18
            || cqc7ChartAnimal(19) != 13
            || cqc7ChartBody(19) != 16
            || cqc7ChartColor(19) != 19
            || cqc7ChartHolyday(19) != 8
            || cqc7ChartAnimal(20) != 14
            || cqc7ChartHead(20) != 10
            || cqc7ChartColor(20) != 20
            || cqc7ChartHolyday(20) != 6
            || cqc7ChartBody(22) != 19
            || cqc7ChartColor(22) != 22
            || cqc7ChartForm(22) != 5
        )
            ++bad;
        // the cleric flags (every row reads the N-H mark, none the M or F)
    if (cqc7ChartNh(0) != 1
            || cqc7ChartNh(1) != 1
            || cqc7ChartNh(2) != 1
            || cqc7ChartNh(3) != 1
            || cqc7ChartNh(4) != 1
            || cqc7ChartNh(5) != 1
            || cqc7ChartNh(6) != 1
            || cqc7ChartNh(7) != 1
            || cqc7ChartNh(8) != 1
            || cqc7ChartNh(9) != 1
            || cqc7ChartNh(10) != 1
            || cqc7ChartNh(11) != 1
            || cqc7ChartNh(12) != 1
            || cqc7ChartNh(13) != 1
            || cqc7ChartNh(14) != 1
            || cqc7ChartNh(15) != 1
            || cqc7ChartNh(16) != 1
            || cqc7ChartNh(17) != 1
            || cqc7ChartNh(18) != 1
            || cqc7ChartNh(19) != 1
            || cqc7ChartNh(20) != 1
            || cqc7ChartNh(21) != 1
            || cqc7ChartNh(22) != 1
            || cqc7ChartNh(23) != 1
            || cqc7ChartM(0) != 0
            || cqc7ChartM(11) != 0
            || cqc7ChartM(23) != 0
            || cqc7ChartF(0) != 0
            || cqc7ChartF(11) != 0
            || cqc7ChartF(23) != 0
        )
            ++bad;
        printf("R875 clerical chart batch seven audit: bad %d\n", bad);
        if (bad) return 1;
    }
