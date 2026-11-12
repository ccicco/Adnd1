    // ---- R868 temple trappings audit ----
    // APPENDIX 2: TEMPLE TRAPPINGS - the D&DG walk round twenty, print p.
    // 134: the representative-sample doctrine, the DM stocking and keying
    // doctrine, and the 40-band trappings list (01-05 altar through 99-00
    // vestments) riding the roster data file; the L&L <cleric scrolls> and
    // <+5 holy avenger, etc.> glosses are 5th-print additions, absent from
    // the 2nd print.
    {
        using namespace rules;
        int bad = 0;
    if (tplRound() != 868
            || tplPrintPage() != 134
            || tplRows() != 40
            || tplBandTotal() != 100
            || tplFirstBandLow() != 1
            || tplFirstBandHigh() != 5
            || tplLastBandLow() != 99
            || tplLastBandHigh() != 100
            || tplWidestBand() != 6
            || tplWidestBandLow() != 30
            || tplSingleRows() != 11
            || tplDoubleRows() != 17
            || tplWideRows() != 12
            || tplHolyUnholyRows() != 5
            || tplRosterCount() != 40
            || tplTableCount() != 1
            || tplChainCount() != 0
            || !tplRepresentativeSample()
            || !tplKeyedByDM()
            || !tplChooseFromList()
            || !tplRandomOnlyDetails()
            || !tplRandomOnlySpurOfMoment()
            || !tplSomeNotApplicable()
            || !tplNoFlamePitsLawfulGood()
            || !tplAlphabeticalList()
            || !tplChoirAreaTwoWords()
            || !tplFontImmersionPrint()
            || !tplLecternDaisPrint()
            || !tplGlossesNotPrint()
            || !tplAndTomesPrint()
        )
            ++bad;
        // the the temple trappings grid grid
        int CtplTrap[40][3] = {
            {0,1,5},
            {1,6,7},
            {2,8,9},
            {3,10,11},
            {4,12,12},
            {5,13,13},
            {6,14,14},
            {7,15,16},
            {8,17,18},
            {9,19,22},
            {10,23,24},
            {11,25,25},
            {12,26,27},
            {13,28,29},
            {14,30,35},
            {15,36,40},
            {16,41,45},
            {17,46,46},
            {18,47,48},
            {19,49,50},
            {20,51,52},
            {21,53,54},
            {22,55,56},
            {23,57,61},
            {24,62,63},
            {25,64,64},
            {26,65,68},
            {27,69,69},
            {28,70,74},
            {29,75,79},
            {30,80,80},
            {31,81,82},
            {32,83,83},
            {33,84,86},
            {34,87,87},
            {35,88,91},
            {36,92,95},
            {37,96,96},
            {38,97,98},
            {39,99,100},
            };
        for (int b = 0;
             b < tplRows();
             ++b) {
            int vals[3];
            vals[0] = tplTrapOrd(b);
            vals[1] = tplTrapLow(b);
            vals[2] = tplTrapHigh(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CtplTrap[b][c])
                    ++bad;
            }
        }
        // the census walk (the one grid, the roster, the row-class counts,
        // the band widths)
    if (tplRound() != 868
            || tplPrintPage() != 134
            || tplTableCount() != 1
            || tplChainCount() != 0
            || tplRows() != 40
            || tplRosterCount() != 40
            || tplBandTotal() != 100
            || tplWidestBand() != 6
            || tplSingleRows() != 11
            || tplDoubleRows() != 17
            || tplWideRows() != 12
            || tplHolyUnholyRows() != 5
        )
            ++bad;
        // the temple trappings doctrine (the stocking and keying rules of the
        // intro)
    if (tplRepresentativeSample() != 1
            || tplKeyedByDM() != 1
            || tplChooseFromList() != 1
            || tplRandomOnlyDetails() != 1
            || tplRandomOnlySpurOfMoment() != 1
            || tplSomeNotApplicable() != 1
            || tplNoFlamePitsLawfulGood() != 1
            || tplAlphabeticalList() != 1
        )
            ++bad;
        // the band tiling head and tail (the altar row, the vestments row,
        // the 00 reads 100)
    if (tplFirstBandLow() != 1
            || tplFirstBandHigh() != 5
            || tplLastBandLow() != 99
            || tplLastBandHigh() != 100
            || tplTrapLow(0) != 1
            || tplTrapHigh(0) != 5
            || tplTrapLow(39) != 99
            || tplTrapHigh(39) != 100
            || tplTrapOrd(0) != 0
            || tplTrapOrd(39) != 39
        )
            ++bad;
        // the single-number rows (chalice, flame pit, sacrifice, scrolls,
        // throne)
    if (tplTrapLow(4) != 12
            || tplTrapHigh(4) != 12
            || tplTrapLow(11) != 25
            || tplTrapHigh(11) != 25
            || tplTrapLow(30) != 80
            || tplTrapHigh(30) != 80
            || tplTrapLow(32) != 83
            || tplTrapHigh(32) != 83
            || tplTrapLow(37) != 96
            || tplTrapHigh(37) != 96
        )
            ++bad;
        // the widest band and the holy/unholy rows (books 30-35, weapons
        // 47-48)
    if (tplTrapLow(14) != 30
            || tplTrapHigh(14) != 35
            || tplWidestBandLow() != 30
            || tplTrapLow(18) != 47
            || tplTrapHigh(18) != 48
            || tplTrapLow(15) != 36
            || tplTrapHigh(15) != 40
            || tplTrapLow(16) != 41
            || tplTrapHigh(16) != 45
            || tplTrapLow(17) != 46
            || tplTrapHigh(17) != 46
        )
            ++bad;
        // the mid-list bands (columns 19-22, crypts 23-24, offertory 57-61,
        // pews 65-68, pulpit 70-74, robes 75-79)
    if (tplTrapLow(9) != 19
            || tplTrapHigh(9) != 22
            || tplTrapLow(10) != 23
            || tplTrapHigh(10) != 24
            || tplTrapLow(23) != 57
            || tplTrapHigh(23) != 61
            || tplTrapLow(26) != 65
            || tplTrapHigh(26) != 68
            || tplTrapLow(28) != 70
            || tplTrapHigh(28) != 74
            || tplTrapLow(29) != 75
            || tplTrapHigh(29) != 79
        )
            ++bad;
        // the tail bands (shrine 84-86, stained glass 87, statue 88-91,
        // tapestry 92-95, vestry 97-98)
    if (tplTrapLow(33) != 84
            || tplTrapHigh(33) != 86
            || tplTrapLow(34) != 87
            || tplTrapHigh(34) != 87
            || tplTrapLow(35) != 88
            || tplTrapHigh(35) != 91
            || tplTrapLow(36) != 92
            || tplTrapHigh(36) != 95
            || tplTrapLow(38) != 97
            || tplTrapHigh(38) != 98
        )
            ++bad;
        // the early bands (bells 06-07, braziers 08-09, candlesticks 10-11,
        // choir area 14, cassocks 15-16, gong 28-29)
    if (tplTrapLow(1) != 6
            || tplTrapHigh(1) != 7
            || tplTrapLow(2) != 8
            || tplTrapHigh(2) != 9
            || tplTrapLow(3) != 10
            || tplTrapHigh(3) != 11
            || tplTrapLow(6) != 14
            || tplTrapHigh(6) != 14
            || tplTrapLow(7) != 15
            || tplTrapHigh(7) != 16
            || tplTrapLow(13) != 28
            || tplTrapHigh(13) != 29
        )
            ++bad;
        // the second half of the list (idol/icon 49-50, incense burners
        // 51-52, lectern/dais 53-54, mosaics 55-56, paintings 62-63, pedal
        // organ 64, prayer wheels 69, sanctuary 81-82)
    if (tplTrapLow(19) != 49
            || tplTrapHigh(19) != 50
            || tplTrapLow(20) != 51
            || tplTrapHigh(20) != 52
            || tplTrapLow(21) != 53
            || tplTrapHigh(21) != 54
            || tplTrapLow(22) != 55
            || tplTrapHigh(22) != 56
            || tplTrapLow(24) != 62
            || tplTrapHigh(24) != 63
            || tplTrapLow(25) != 64
            || tplTrapHigh(25) != 64
            || tplTrapLow(27) != 69
            || tplTrapHigh(27) != 69
            || tplTrapLow(31) != 81
            || tplTrapHigh(31) != 82
        )
            ++bad;
        // the print-form pins (the choir area and font/immersion chamber
        // reads, the lectern/dais print, the and-tomes print)
    if (tplChoirAreaTwoWords() != 1
            || tplFontImmersionPrint() != 1
            || tplLecternDaisPrint() != 1
            || tplAndTomesPrint() != 1
        )
            ++bad;
        // the L&L parity notes (the 5th-print glosses absent from the 2nd
        // print)
    if (tplGlossesNotPrint() != 1
        )
            ++bad;
        printf("R868 temple trappings audit: bad %d\n", bad);
        if (bad) return 1;
    }
