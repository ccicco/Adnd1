    // ---- R878 alignment figures audit ----
    // THE ALIGNMENT FIGURES - the D&DG walk round thirty, print p. 131 (pdf
    // 132): FIG. 4 the character alignment graph and FIG. 5 the planes of
    // alignment - the LAST D&DG tail page, and the pixel round: both text
    // voices read near-zero here (the tesseract pass and the IA djvu - line
    // art), so the evidence is the pdftoppm renders (committed c8bf507 and
    // 1028ebe) read by the vision passes, collated against the TSV label
    // geometry, with the TARTARUS eyeball by Curtiss. THE GAP FLIP: the
    // alignment figures box closes - the ddg report reads 24/0, the walk
    // COMPLETE. THE HEADLINE ADJUDICATIONS: the four curved descriptors ride
    // the four corner alignments (Saintly LG, Beatific CG, Diabolic LE,
    // Demoniac CE - the crescent regions); the settled structure read -
    // CURVED dividers converging at the center, not crossing Venn lenses; the
    // center circle NEUTRAL (the true neutral); the NEUTRAL EVIL label and
    // the center circle vision-only (the TSV misses them); the FIG. 5 wheel -
    // sixteen segments, straight radial dividers, plane names only, no
    // arrows; ELYSIUM the top segment, HADES the bottom, CONCORDANT
    // OPPOSITION the center; the cycle reads the p. 129 list order clockwise;
    // the figure spells TARTARUS where the list reads Tarterus - the
    // figure-vs-list delta, both pinned as printed. The wheel matches the
    // Appendix 1 seventeen-planes pin. ZERO registry defs touched - the floor
    // holds at 995.
    {
        using namespace rules;
        int bad = 0;
    if (afgRound() != 878
            || afgPrintPage() != 131
            || afgPdfPage() != 132
            || afgFigures() != 2
            || afgFigFour() != 4
            || afgFigFive() != 5
            || afgG4Alignments() != 9
            || afgG4Compass() != 9
            || afgG4Descriptors() != 4
            || afgG4Described() != 4
            || afgG4Top() != 0
            || afgG4Bottom() != 6
            || afgG4Center() != 8
            || afgG5Planes() != 17
            || afgG5Segments() != 16
            || afgG5TopOrd() != 3
            || afgG5BottomOrd() != 11
            || afgG5CenterOrd() != 17
            || afgG5TartarusOrd() != 10
            || !afgPixelRound()
            || !afgG4CurvedDividers()
            || !afgG4CenterTrueNeutral()
            || !afgG4DescriptorsCorners()
            || !afgG4SaintlyLG()
            || !afgG4BeatificCG()
            || !afgG4DiabolicLE()
            || !afgG4DemoniacCE()
            || !afgNoArrows()
            || !afgG5RadialDividers()
            || !afgG5SegmentsNamesOnly()
            || !afgG5ElysiumTop()
            || !afgG5HadesBottom()
            || !afgG5ConcordantCenter()
            || !afgG5ListOrderClockwise()
            || !afgG5TartarusSpelling()
            || !afgG5SeventeenMatch()
            || !afgLastBox()
        )
            ++bad;
        // the the character alignment graph grid grid
        int CafgG4[9][3] = {
            {0,0,0},
            {1,7,1},
            {2,1,2},
            {3,6,0},
            {4,2,0},
            {5,5,3},
            {6,4,0},
            {7,3,4},
            {8,8,0},
            };
        for (int b = 0;
             b < afgG4Alignments();
             ++b) {
            int vals[3];
            vals[0] = afgG4Ord(b);
            vals[1] = afgG4Pos(b);
            vals[2] = afgG4Desc(b);
            for (int c = 0; c < 3;
                 ++c) {
                if (vals[c] != CafgG4[b][c])
                    ++bad;
            }
        }
        // the the planes of alignment wheel grid grid
        int CafgG5[17][2] = {
            {1,15},
            {2,16},
            {3,1},
            {4,2},
            {5,3},
            {6,4},
            {7,5},
            {8,6},
            {9,7},
            {10,8},
            {11,9},
            {12,10},
            {13,11},
            {14,12},
            {15,13},
            {16,14},
            {17,0},
            };
        for (int b = 0;
             b < afgG5Planes();
             ++b) {
            int vals[2];
            vals[0] = afgG5Ord(b);
            vals[1] = afgG5Pos(b);
            for (int c = 0; c < 2;
                 ++c) {
                if (vals[c] != CafgG5[b][c])
                    ++bad;
            }
        }
        // the census walk (the round, the page, both figures)
    if (afgRound() != 878
            || afgPrintPage() != 131
            || afgPdfPage() != 132
            || afgFigures() != 2
            || afgFigFour() != 4
            || afgFigFive() != 5
            || afgG4Alignments() != 9
            || afgG4Descriptors() != 4
            || afgG4Described() != 4
            || afgG5Planes() != 17
            || afgG5Segments() != 16
        )
            ++bad;
        // the FIG. 4 wedge rows (the reading order, the compass, the
        // descriptors)
    if (afgG4Ord(0) != 0
            || afgG4Pos(0) != 0
            || afgG4Desc(0) != 0
            || afgG4Ord(1) != 1
            || afgG4Pos(1) != 7
            || afgG4Desc(1) != 1
            || afgG4Ord(2) != 2
            || afgG4Pos(2) != 1
            || afgG4Desc(2) != 2
            || afgG4Ord(3) != 3
            || afgG4Pos(3) != 6
            || afgG4Ord(4) != 4
            || afgG4Pos(4) != 2
            || afgG4Desc(4) != 0
            || afgG4Ord(5) != 5
            || afgG4Pos(5) != 5
            || afgG4Desc(5) != 3
            || afgG4Ord(6) != 6
            || afgG4Pos(6) != 4
            || afgG4Desc(6) != 0
            || afgG4Ord(7) != 7
            || afgG4Pos(7) != 3
            || afgG4Desc(7) != 4
            || afgG4Ord(8) != 8
            || afgG4Pos(8) != 8
            || afgG4Desc(8) != 0
        )
            ++bad;
        // the FIG. 5 wheel rows (the list order, the clockwise segments, the
        // center)
    if (afgG5Ord(0) != 1
            || afgG5Pos(0) != 15
            || afgG5Ord(2) != 3
            || afgG5Pos(2) != 1
            || afgG5Ord(10) != 11
            || afgG5Pos(10) != 9
            || afgG5Ord(16) != 17
            || afgG5Pos(16) != 0
            || afgG5Ord(9) != 10
            || afgG5Pos(9) != 8
            || afgG5Ord(1) != 2
            || afgG5Pos(1) != 16
            || afgG5Ord(15) != 16
            || afgG5Pos(15) != 14
        )
            ++bad;
        // the descriptor census (the four corners carry the four curved
        // words)
    if (afgG4Desc(0) != 0
            || afgG4Desc(3) != 0
            || afgG4Desc(4) != 0
            || afgG4Desc(6) != 0
            || afgG4Desc(8) != 0
            || afgG4Desc(1) != 1
            || afgG4Desc(2) != 2
            || afgG4Desc(5) != 3
            || afgG4Desc(7) != 4
        )
            ++bad;
        // the structure and doctrine pins (the bool-operator form per the
        // R865 rule)
    if (afgPixelRound() != 1
            || afgG4CurvedDividers() != 1
            || afgG4CenterTrueNeutral() != 1
            || afgG4DescriptorsCorners() != 1
            || afgNoArrows() != 1
            || afgG5RadialDividers() != 1
            || afgG5SegmentsNamesOnly() != 1
            || afgLastBox() != 1
        )
            ++bad;
        // the wheel poles, the list-order cycle and the TARTARUS delta
    if (afgG5ElysiumTop() != 1
            || afgG5HadesBottom() != 1
            || afgG5ConcordantCenter() != 1
            || afgG5ListOrderClockwise() != 1
            || afgG5TartarusSpelling() != 1
            || afgG5SeventeenMatch() != 1
            || afgG5TopOrd() != 3
            || afgG5BottomOrd() != 11
            || afgG5CenterOrd() != 17
            || afgG5TartarusOrd() != 10
        )
            ++bad;
        printf("R878 alignment figures audit: bad %d\n", bad);
        if (bad) return 1;
    }
