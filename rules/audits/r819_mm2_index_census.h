    // ---- R819 MM2 index census audit ----
    // THE MM2 INDEX WALK - the merged MM1/FF/MM2 index (print pp. 156-160,
    // the gap box label says p. 156, the printed page numbers in both scans
    // give the five-page span; the 4-column layout, the 26 letter sections).
    // THE OPENING DOCTRINE (p. 156, pinned as the consts and bools): the
    // index includes all official creatures (as of December, 1982) published
    // in this volume as well as the MONSTER MANUAL and FIEND FOLIO; the
    // left-hand column gives the book and page where each may be found, M for
    // MONSTER MANUAL I, F for FIEND FOLIO, no letter if the creature is
    // detailed in this book; a listing in parentheses to the right of the
    // entry indicates the name under which it is found. THE METHOD: a
    // two-voice adjudication - both archive.org djvu scans parsed
    // independently (the column reconstruction, the ref-token split, the
    // registry cross-resolve), junk-filtered, paired per letter by
    // global-best matching; the 206 single-voice slots adjudicated by hand,
    // the ref-fused M and F OCR lines re-lettered to their true sections, the
    // split fragments dropped. THE PIN: a line census, not a def census -
    // 1488 adjudicated index lines (577 MM1 references, 401 FF references,
    // 510 this-book lines, 470 parenthetical cross-references); the
    // within-letter double-listings retained as separate print lines (the
    // dragons double-listed, the inverted cross-refs). THE SETTLED RECLASS
    // READS: the Leprechaun, Salt Water Troll, Troll and Weasel lines carry M
    // references the OCR lost (4); the Sirme line (between the Singing Ape
    // and Skeleton rows) reclassified the MM2 sirine, the Stalker line
    // (between the Stag Beetle and Dark Stalker rows) the reference lost in
    // both scans - both flagged (2). THE B-ONLY REAL ENTRIES: the Caryatid
    // Column and Olhydra lines - no registry def, the OA/lammasu promotion
    // seam stays queued. NO defs promoted this round; the registry stays 809.
    // THE FLIPS: the Random Encounter Tables parent box closes riding the
    // landed R816/R817/R818 children, and the Index box closes - the MM2 arc
    // gap ends 37 closed, 0 open.
    {
        using namespace rules;
        int bad = 0;
    if (mm2enciRound() != 819
            || mm2enciPrintFolio() != 156
            || mm2enciFirstPage() != 156
            || mm2enciLastPage() != 160
            || mm2enciLetterCount() != 26
            || mm2enciColumnsPerPage() != 4
            || mm2enciTotalLines() != 1488
            || mm2enciMm1Lines() != 577
            || mm2enciFfLines() != 401
            || mm2enciThisBookLines() != 510
            || mm2enciCrossRefLines() != 470
            || mm2enciLargestLetterTotal() != 180
            || mm2enciSmallestLetterTotal() != 4
            || mm2enciMaxMm1Letter() != 64
            || mm2enciMaxFfLetter() != 52
            || mm2enciMaxThisBookLetter() != 64
            || mm2enciLargestCrossRefLetter() != 63
            || mm2enciVoiceASlots() != 1495
            || mm2enciVoiceBSlots() != 1501
            || mm2enciFragmentDrops() != 9
            || mm2enciRefLostLines() != 4
            || mm2enciFlaggedReads() != 2
            || mm2enciBOnlyRealEntries() != 2
            || mm2enciSingleVoiceSlots() != 206
            || mm2enciCoverageMonth() != 12
            || mm2enciCoverageYear() != 1982
            || mm2enciAbbrevCount() != 2
            || mm2enciRegistryFloor() != 809
            || mm2enciRegistryMm1Defs() != 408
            || mm2enciRegistryMm2Defs() != 331
            || mm2enciTotalA() != 70
            || mm2enciTotalB() != 114
            || mm2enciTotalC() != 96
            || mm2enciTotalD() != 84
            || mm2enciTotalE() != 48
            || mm2enciTotalF() != 72
            || mm2enciTotalG() != 91
            || mm2enciTotalH() != 64
            || mm2enciTotalI() != 30
            || mm2enciTotalJ() != 18
            || mm2enciTotalK() != 29
            || mm2enciTotalL() != 62
            || mm2enciTotalM() != 112
            || mm2enciTotalN() != 31
            || mm2enciTotalO() != 46
            || mm2enciTotalP() != 72
            || mm2enciTotalQ() != 11
            || mm2enciTotalR() != 41
            || mm2enciTotalS() != 180
            || mm2enciTotalT() != 76
            || mm2enciTotalU() != 15
            || mm2enciTotalV() != 26
            || mm2enciTotalW() != 75
            || mm2enciTotalX() != 6
            || mm2enciTotalY() != 15
            || mm2enciTotalZ() != 4
            || !mm2enciIncludesAllOfficialCreatures()
            || !mm2enciCoverageStopsDecember1982()
            || !mm2enciMm1AbbreviatedM()
            || !mm2enciFfAbbreviatedF()
            || !mm2enciThisBookCarriesNoLetter()
            || !mm2enciLeftColumnGivesBookAndPage()
            || !mm2enciParentheticalNamesTheRealEntry()
            || !mm2enciLayoutIsFourColumns()
            || !mm2enciCensusIsTwoVoiceAdjudicated()
            || !mm2enciLineCensusNotDefCensus()
            || !mm2enciNoDefsPromotedThisRound()
            || !mm2enciRefFusedLinesRelettered()
            || !mm2enciParentClosesWithIndex()
            || !mm2enciMm2ArcClosesThisRound()
        )
            ++bad;
        // THE MERGED INDEX LINE CENSUS GRID: the 26 letter rows, the cells
        // (ordinal, total, MM1, FF, this-book, cross-ref). Rows: A 70 (25
        // MM1, 15 FF, 30 this-book, 24 cross-refs); B 114 (49 MM1, 23 FF, 42
        // this-book, 34 cross-refs); C 96 (33 MM1, 25 FF, 38 this-book, 25
        // cross-refs); D 84 (21 MM1, 27 FF, 36 this-book, 21 cross-refs); E
        // 48 (21 MM1, 14 FF, 13 this-book, 18 cross-refs); F 72 (20 MM1, 26
        // FF, 26 this-book, 27 cross-refs); G 91 (35 MM1, 32 FF, 24
        // this-book, 22 cross-refs); H 64 (34 MM1, 12 FF, 18 this-book, 23
        // cross-refs); I 30 (15 MM1, 13 FF, 2 this-book, 13 cross-refs); J 18
        // (8 MM1, 5 FF, 5 this-book, 5 cross-refs); K 29 (7 MM1, 13 FF, 9
        // this-book, 8 cross-refs); L 62 (31 MM1, 19 FF, 12 this-book, 24
        // cross-refs); M 112 (47 MM1, 21 FF, 44 this-book, 36 cross-refs); N
        // 31 (11 MM1, 12 FF, 8 this-book, 8 cross-refs); O 46 (17 MM1, 9 FF,
        // 20 this-book, 11 cross-refs); P 72 (32 MM1, 18 FF, 22 this-book, 20
        // cross-refs); Q 11 (1 MM1, 4 FF, 6 this-book, 1 cross-refs); R 41
        // (19 MM1, 11 FF, 11 this-book, 16 cross-refs); S 180 (64 MM1, 52 FF,
        // 64 this-book, 63 cross-refs); T 76 (30 MM1, 16 FF, 30 this-book, 23
        // cross-refs); U 15 (3 MM1, 6 FF, 6 this-book, 7 cross-refs); V 26 (4
        // MM1, 6 FF, 16 this-book, 7 cross-refs); W 75 (45 MM1, 13 FF, 17
        // this-book, 33 cross-refs); X 6 (1 MM1, 2 FF, 3 this-book, 0
        // cross-refs); Y 15 (3 MM1, 7 FF, 5 this-book, 0 cross-refs); Z 4 (1
        // MM1, 0 FF, 3 this-book, 1 cross-refs)
        int CIDX[26][6] = {
            {1,70,25,15,30,24},
            {2,114,49,23,42,34},
            {3,96,33,25,38,25},
            {4,84,21,27,36,21},
            {5,48,21,14,13,18},
            {6,72,20,26,26,27},
            {7,91,35,32,24,22},
            {8,64,34,12,18,23},
            {9,30,15,13,2,13},
            {10,18,8,5,5,5},
            {11,29,7,13,9,8},
            {12,62,31,19,12,24},
            {13,112,47,21,44,36},
            {14,31,11,12,8,8},
            {15,46,17,9,20,11},
            {16,72,32,18,22,20},
            {17,11,1,4,6,1},
            {18,41,19,11,11,16},
            {19,180,64,52,64,63},
            {20,76,30,16,30,23},
            {21,15,3,6,6,7},
            {22,26,4,6,16,7},
            {23,75,45,13,17,33},
            {24,6,1,2,3,0},
            {25,15,3,7,5,0},
            {26,4,1,0,3,1},
            };
        for (int b = 0;
             b < mm2enciLetterCount();
             ++b) {
            int vals[6];
            vals[0] = mm2enciOrdinal(b);
            vals[1] = mm2enciTotal(b);
            vals[2] = mm2enciMm1(b);
            vals[3] = mm2enciFf(b);
            vals[4] = mm2enciThisBook(b);
            vals[5] = mm2enciCrossRef(b);
            for (int c = 0; c < 6;
                 ++c) {
                if (vals[c] != CIDX[b][c])
                    ++bad;
            }
        }
        // the census arithmetic (the three voice columns sum to the total
        // lines)
    if (mm2enciMm1Lines() + mm2enciFfLines() + mm2enciThisBookLines() !=
        mm2enciTotalLines()
        )
            ++bad;
        // the letter and page arithmetic
    if (mm2enciLetterCount() != 26
            || mm2enciFirstPage() != 156
            || mm2enciLastPage() != 160
            || mm2enciLastPage() - mm2enciFirstPage() != 4
        )
            ++bad;
        // the voice-slot arithmetic (voice A minus the fragment drops plus
        // the B-only real entries)
    if (mm2enciVoiceASlots() - mm2enciFragmentDrops() +
        mm2enciBOnlyRealEntries() != mm2enciTotalLines()
        )
            ++bad;
        // the single-voice slots
    if (mm2enciSingleVoiceSlots() != 206
            || mm2enciRefLostLines() != 4
            || mm2enciFlaggedReads() != 2
        )
            ++bad;
        // the section extremes
    if (mm2enciLargestLetterTotal() != 180
            || mm2enciSmallestLetterTotal() != 4
        )
            ++bad;
        // the per-voice section maxima (all S)
    if (mm2enciMaxMm1Letter() != 64
            || mm2enciMaxFfLetter() != 52
            || mm2enciMaxThisBookLetter() != 64
            || mm2enciLargestCrossRefLetter() != 63
        )
            ++bad;
        // the cross-reference arithmetic
    if (mm2enciCrossRefLines() != 470
            || mm2enciCrossRefLines() > mm2enciTotalLines()
        )
            ++bad;
        // the doctrine date
    if (mm2enciCoverageYear() != 1982
            || mm2enciCoverageMonth() != 12
            || mm2enciAbbrevCount() != 2
        )
            ++bad;
        // the registry floor (no defs promoted)
    if (mm2enciRegistryFloor() != 809
            || mm2enciRegistryMm1Defs() != 408
            || mm2enciRegistryMm2Defs() != 331
            || mm2enciRegistryMm1Defs() + mm2enciRegistryMm2Defs() != 739
        )
            ++bad;
        printf("R819 MM2 index census audit: bad %d\n", bad);
        if (bad) return 1;
    }
