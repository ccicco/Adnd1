    // ---- R873 clerical chart batch five audit ----
    // APPENDIX 3: THE CLERICAL QUICK-REFERENCE CHARTS, BATCH FIVE - the D&DG
    // walk round twenty-five, print pp. 140-141: the fifth batch of deity
    // rows - Japanese (10), Melnibonean (15) - riding the roster data file,
    // the Arioch row on the pdf 140 tail; the App 3 gap box stays open until
    // the last chart batch lands. The print voice is the ROTATED tesseract
    // pass, collated against the 1eonline L&L per-deity chart rows. The
    // headline divergence: the print reads the Ama-Tsu-Mara form metalwork
    // and place hearth where the L&L voice reads precious metalwork and
    // temple - pinned by print, eyeball flag.
    {
        using namespace rules;
        int bad = 0;
    if (cqc5Round() != 873
            || cqc5Batch() != 5
            || cqc5PrintStart() != 140
            || cqc5PrintEnd() != 141
            || cqc5Rows() != 25
            || cqc5JapaneseRows() != 10
            || cqc5MelniboneanRows() != 15
            || cqc5MaleRows() != 15
            || cqc5FemaleRows() != 13
            || cqc5NonHumanRows() != 15
            || cqc5PrintedColumns() != 13
            || cqc5SphereCount() != 24
            || cqc5AnimalCount() != 18
            || cqc5HeadCount() != 8
            || cqc5BodyCount() != 14
            || cqc5ColorCount() != 22
            || cqc5HolyDayCount() != 9
            || cqc5FreqCount() != 5
            || cqc5FormCount() != 14
            || cqc5PlaceCount() != 4
            || cqc5TableCount() != 1
            || cqc5ChainCount() != 0
            || !cqc5AmaTsuMaraHearthPrint()
            || !cqc5DaikokuLuckRestored()
            || !cqc5MelniboneanNonHumanOnly()
            || !cqc5HaaashastaakAnimalPrint()
            || !cqc5TsukiyomiAlternateHeader()
            || !cqc5BracketGlossesNoted()
            || !cqc5EquinoxFoldRestored()
            || !cqc5RoofdrakStrayGlyph()
            || !cqc5GromeStrayApostrophe()
            || !cqc5JapaneseNoNonHuman()
        )
            ++bad;
        // the the clerical chart batch five grid grid
        int Ccqc5Chart[25][13] = {
            {0,0,0,1,1,0,0,0,0,0,0,0,0},
            {1,1,1,1,1,0,1,1,1,1,0,1,1},
            {2,2,2,1,1,0,2,2,2,0,0,2,0},
            {3,3,3,1,1,0,0,3,3,2,1,3,0},
            {4,4,4,1,0,0,3,4,4,3,1,4,0},
            {5,5,5,1,1,0,0,5,5,0,0,5,0},
            {6,6,6,1,1,0,0,6,6,4,2,6,0},
            {7,7,7,1,1,0,4,7,7,0,0,7,0},
            {8,8,8,1,1,0,0,8,8,5,3,8,0},
            {9,9,9,1,1,0,0,9,9,6,3,9,0},
            {10,10,10,1,1,1,0,10,10,1,0,10,2},
            {11,11,10,1,0,1,5,11,1,7,3,11,3},
            {12,12,11,1,1,1,6,12,0,8,4,12,2},
            {13,13,12,0,0,1,7,13,11,4,4,13,2},
            {14,14,10,0,0,1,7,13,12,4,4,13,2},
            {15,15,13,0,0,1,7,13,13,4,4,13,2},
            {16,16,10,0,0,1,7,13,14,4,4,13,2},
            {17,17,6,0,0,1,7,13,15,4,4,13,2},
            {18,18,10,0,0,1,7,13,16,4,4,13,2},
            {19,19,14,0,0,1,7,13,6,4,4,13,2},
            {20,20,15,0,0,1,7,13,17,4,4,13,2},
            {21,21,16,1,1,1,7,13,18,4,4,10,2},
            {22,22,17,0,0,1,7,13,19,4,4,13,2},
            {23,23,10,0,0,1,7,13,20,4,4,13,2},
            {24,10,10,1,1,1,7,13,21,4,4,10,2},
            };
        for (int b = 0;
             b < cqc5Rows();
             ++b) {
            int vals[13];
            vals[0] = cqc5ChartOrd(b);
            vals[1] = cqc5ChartSphere(b);
            vals[2] = cqc5ChartAnimal(b);
            vals[3] = cqc5ChartM(b);
            vals[4] = cqc5ChartF(b);
            vals[5] = cqc5ChartNh(b);
            vals[6] = cqc5ChartHead(b);
            vals[7] = cqc5ChartBody(b);
            vals[8] = cqc5ChartColor(b);
            vals[9] = cqc5ChartHolyday(b);
            vals[10] = cqc5ChartFreq(b);
            vals[11] = cqc5ChartForm(b);
            vals[12] = cqc5ChartPlace(b);
            for (int c = 0; c < 13;
                 ++c) {
                if (vals[c] != Ccqc5Chart[b][c])
                    ++bad;
            }
        }
        // the census walk (the batch rows, the pantheon counts, the roster
        // counts, the cleric flags)
    if (cqc5Round() != 873
            || cqc5Batch() != 5
            || cqc5PrintStart() != 140
            || cqc5PrintEnd() != 141
            || cqc5Rows() != 25
            || cqc5JapaneseRows() != 10
            || cqc5MelniboneanRows() != 15
            || cqc5MaleRows() != 15
            || cqc5FemaleRows() != 13
            || cqc5NonHumanRows() != 15
            || cqc5PrintedColumns() != 13
            || cqc5SphereCount() != 24
            || cqc5AnimalCount() != 18
            || cqc5HeadCount() != 8
            || cqc5BodyCount() != 14
            || cqc5ColorCount() != 22
            || cqc5HolyDayCount() != 9
            || cqc5FreqCount() != 5
            || cqc5FormCount() != 14
            || cqc5PlaceCount() != 4
            || cqc5TableCount() != 1
            || cqc5ChainCount() != 0
        )
            ++bad;
        // the parity pins (the Ama-Tsu-Mara divergence, the N-H-only
        // geometry, the garble restorations)
    if (cqc5AmaTsuMaraHearthPrint() != 1
            || cqc5DaikokuLuckRestored() != 1
            || cqc5MelniboneanNonHumanOnly() != 1
            || cqc5HaaashastaakAnimalPrint() != 1
            || cqc5TsukiyomiAlternateHeader() != 1
            || cqc5BracketGlossesNoted() != 1
            || cqc5EquinoxFoldRestored() != 1
            || cqc5RoofdrakStrayGlyph() != 1
            || cqc5GromeStrayApostrophe() != 1
            || cqc5JapaneseNoNonHuman() != 1
        )
            ++bad;
        // the head and tail rows (Amaterasu Omikami 0, Xiombarg 24, the
        // ordinals run)
    if (cqc5ChartOrd(0) != 0
            || cqc5ChartOrd(24) != 24
            || cqc5ChartBody(0) != 0
            || cqc5ChartM(0) != 1
            || cqc5ChartF(0) != 1
            || cqc5ChartForm(0) != 0
            || cqc5ChartSphere(24) != 10
            || cqc5ChartNh(24) != 1
            || cqc5ChartColor(24) != 21
            || cqc5ChartForm(24) != 10
            || cqc5ChartPlace(24) != 2
        )
            ++bad;
        // the Japanese rows (the hearth pin, the vestments classes, the used
        // weapons)
    if (cqc5ChartForm(1) != 1
            || cqc5ChartPlace(1) != 1
            || cqc5ChartM(1) != 1
            || cqc5ChartSphere(2) != 2
            || cqc5ChartAnimal(2) != 2
            || cqc5ChartBody(3) != 3
            || cqc5ChartForm(3) != 3
            || cqc5ChartF(4) != 0
            || cqc5ChartHolyday(4) != 3
            || cqc5ChartBody(4) != 4
            || cqc5ChartForm(5) != 5
            || cqc5ChartBody(6) != 6
            || cqc5ChartForm(6) != 6
            || cqc5ChartHead(7) != 4
            || cqc5ChartBody(7) != 7
            || cqc5ChartSphere(8) != 8
            || cqc5ChartBody(8) != 8
            || cqc5ChartForm(8) != 8
            || cqc5ChartBody(9) != 9
            || cqc5ChartHolyday(9) != 6
            || cqc5ChartForm(9) != 9
        )
            ++bad;
        // the Melnibonean rows (the N-H-only classes, the triple flags, the
        // favors sacrifices)
    if (cqc5ChartM(10) != 1
            || cqc5ChartNh(10) != 1
            || cqc5ChartBody(10) != 10
            || cqc5ChartHead(11) != 5
            || cqc5ChartBody(11) != 11
            || cqc5ChartF(11) != 0
            || cqc5ChartNh(11) != 1
            || cqc5ChartSphere(12) != 12
            || cqc5ChartForm(12) != 12
            || cqc5ChartM(13) != 0
            || cqc5ChartNh(13) != 1
            || cqc5ChartAnimal(13) != 12
            || cqc5ChartSphere(14) != 14
            || cqc5ChartColor(14) != 12
            || cqc5ChartAnimal(15) != 13
            || cqc5ChartColor(16) != 14
            || cqc5ChartAnimal(17) != 6
            || cqc5ChartColor(18) != 16
            || cqc5ChartAnimal(19) != 14
            || cqc5ChartSphere(20) != 20
            || cqc5ChartSphere(21) != 21
            || cqc5ChartForm(21) != 10
            || cqc5ChartAnimal(22) != 17
            || cqc5ChartColor(23) != 20
        )
            ++bad;
        // the cleric flags (the female and non-human census cells)
    if (cqc5ChartF(2) != 1
            || cqc5ChartF(3) != 1
            || cqc5ChartF(5) != 1
            || cqc5ChartF(7) != 1
            || cqc5ChartF(8) != 1
            || cqc5ChartF(9) != 1
            || cqc5ChartF(10) != 1
            || cqc5ChartF(12) != 1
            || cqc5ChartF(21) != 1
            || cqc5ChartF(24) != 1
            || cqc5ChartNh(14) != 1
            || cqc5ChartNh(16) != 1
            || cqc5ChartNh(17) != 1
            || cqc5ChartNh(18) != 1
            || cqc5ChartNh(23) != 1
        )
            ++bad;
        printf("R873 clerical chart batch five audit: bad %d\n", bad);
        if (bad) return 1;
    }
