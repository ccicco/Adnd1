// =========================================================================================
// Adnd1 - rules/afg.h
// The alignment figures - the D&DG walk round thirty, print p. 131: FIG. 4
// the character alignment graph (the nine alignments, the four descriptors)
// and FIG. 5 the planes of alignment (the seventeen-plane wheel); the LAST
// ddg gap box closes (24/0, the walk complete).
// census 800 -> 801.
//
// primary ink: the pixel reads - both text voices (the extract/ddg tesseract
// pass and the archive.org 1st-print djvu) read near-zero on the page (line
// art); the evidence is the pdftoppm renders at 300/600/1200 dpi (committed
// c8bf507 and 1028ebe) read by the vision passes, collated against the
// tesseract TSV label geometry. The adjudications: the four descriptors
// (Saintly LG, Beatific CG, Diabolic LE, Demoniac CE); the curved
// non-crossing dividers (the settled structure read); the NEUTRAL center
// circle; the FIG. 5 wheel (Elysium top, Hades bottom, Concordant Opposition
// center, the p. 129 list order clockwise); the TARTARUS figure spelling vs
// the Tarterus list (the eyeball confirmation, both pinned); the wheel
// matches the pln.h seventeen-planes pin. The FIG. 4 roster rides
// doc/data/ddg_fig4.txt; the FIG. 5 roster rides doc/data/ddg_fig5.txt.
//
namespace rules {

// ---- the round thirty census ----

// the alignment figures round: the D&DG walk round thirty
inline int afgRound()
    { return 878; }

// the round lands print p. 131 (pdf 132), the last D&DG tail page
inline int afgPrintPage()
    { return 131; }

// the pdf page (the folio offset PRINT = PDF - 1)
inline int afgPdfPage()
    { return 132; }

// the two figures: FIG. 4 the character alignment graph, FIG. 5 the planes of
// alignment
inline int afgFigures()
    { return 2; }

// the print figure number of the character alignment graph
inline int afgFigFour()
    { return 4; }

// the print figure number of the planes of alignment
inline int afgFigFive()
    { return 5; }

// the FIG. 4 alignment labels (the eight wedges plus the center circle)
inline int afgG4Alignments()
    { return 9; }

// the compass positions (the eight directions plus the center)
inline int afgG4Compass()
    { return 9; }

// the four curved descriptor words (Saintly, Beatific, Diabolic, Demoniac)
inline int afgG4Descriptors()
    { return 4; }

// the alignments carrying a descriptor (the four corners)
inline int afgG4Described()
    { return 4; }

// the top wedge ordinal (NEUTRAL GOOD)
inline int afgG4Top()
    { return 0; }

// the bottom wedge ordinal (NEUTRAL EVIL)
inline int afgG4Bottom()
    { return 6; }

// the center circle ordinal (NEUTRAL, the true neutral)
inline int afgG4Center()
    { return 8; }

// the FIG. 5 plane labels (the sixteen segments plus the center)
inline int afgG5Planes()
    { return 17; }

// the wheel segments around the center
inline int afgG5Segments()
    { return 16; }

// the top segment plane (Elysium, the p. 129 list ordinal 3)
inline int afgG5TopOrd()
    { return 3; }

// the bottom segment plane (Hades, the list ordinal 11)
inline int afgG5BottomOrd()
    { return 11; }

// the center plane (Concordant Opposition, the list ordinal 17)
inline int afgG5CenterOrd()
    { return 17; }

// the plane the figure spells TARTARUS (the p. 129 list reads Tarterus)
inline int afgG5TartarusOrd()
    { return 10; }

// ---- the pixel-round pins ----

// the round rides the pixel reads: both text voices (the tesseract pass and
// the IA djvu) read near-zero on the page - line art; the evidence is the
// pdftoppm renders read by the vision passes, committed c8bf507 and 1028ebe
inline bool afgPixelRound()
    { return true; }

// FIG. 4 divides by CURVED lines converging at the center - crescent regions,
// not crossing Venn lenses (the settled structure read)
inline bool afgG4CurvedDividers()
    { return true; }

// the FIG. 4 center circle reads NEUTRAL - the true neutral
inline bool afgG4CenterTrueNeutral()
    { return true; }

// the four descriptors ride the four corner alignments only; the axis wedges
// and the center carry none
inline bool afgG4DescriptorsCorners()
    { return true; }

// Saintly arcs the LAWFUL GOOD region
inline bool afgG4SaintlyLG()
    { return true; }

// Beatific arcs the CHAOTIC GOOD region
inline bool afgG4BeatificCG()
    { return true; }

// Diabolic arcs the LAWFUL EVIL region
inline bool afgG4DiabolicLE()
    { return true; }

// Demoniac arcs the CHAOTIC EVIL region
inline bool afgG4DemoniacCE()
    { return true; }

// neither figure prints arrows or connecting marks - both read as pure
// segment graphs
inline bool afgNoArrows()
    { return true; }

// FIG. 5 divides its sixteen segments by straight radial lines
inline bool afgG5RadialDividers()
    { return true; }

// each FIG. 5 segment carries only its plane name - no second line, no
// symbols
inline bool afgG5SegmentsNamesOnly()
    { return true; }

// ELYSIUM rides the top segment (the neutral good pole, the FIG. 4 compass
// shared)
inline bool afgG5ElysiumTop()
    { return true; }

// HADES rides the bottom segment
inline bool afgG5HadesBottom()
    { return true; }

// CONCORDANT OPPOSITION rides the wheel center
inline bool afgG5ConcordantCenter()
    { return true; }

// the wheel cycle reads the print p. 129 list order clockwise (Seven Heavens
// through Arcadia, the top segment Elysium)
inline bool afgG5ListOrderClockwise()
    { return true; }

// the figure spells TARTARUS where the p. 129 list reads Tarterus - the
// figure-vs-list delta, both pinned as printed (the eyeball confirmation)
inline bool afgG5TartarusSpelling()
    { return true; }

// the wheel matches the Appendix 1 seventeen-planes pin (the
// plnOutSeventeenCount doctrine, rules/pln.h)
inline bool afgG5SeventeenMatch()
    { return true; }

// this round closes the LAST ddg open box - the gap report reads 24/0, the
// walk complete
inline bool afgLastBox()
    { return true; }

// ---- the figure grids ----

// The alignment ordinals (0-8, the print reading order: the wedge labels
// top-to-bottom then left-to-right, the center circle last)
inline int afgG4Ord(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 6;
        case 7:
            return 7;
        case 8:
            return 8;
        default:
            return 0;
        }
    }

// The compass position ordinal (0 north .. 7 northwest, 8 the center circle)
inline int afgG4Pos(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 7;
        case 2:
            return 1;
        case 3:
            return 6;
        case 4:
            return 2;
        case 5:
            return 5;
        case 6:
            return 4;
        case 7:
            return 3;
        case 8:
            return 8;
        default:
            return 0;
        }
    }

// The curved descriptor ordinal (1 Saintly, 2 Beatific, 3 Diabolic, 4
// Demoniac; 0-sentinel for the five without)
inline int afgG4Desc(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 3;
        case 6:
            return 0;
        case 7:
            return 4;
        case 8:
            return 0;
        default:
            return 0;
        }
    }

// The plane ordinals (1-17, the print p. 129 list order, the figure
// spellings)
inline int afgG5Ord(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        case 8:
            return 9;
        case 9:
            return 10;
        case 10:
            return 11;
        case 11:
            return 12;
        case 12:
            return 13;
        case 13:
            return 14;
        case 14:
            return 15;
        case 15:
            return 16;
        case 16:
            return 17;
        default:
            return 0;
        }
    }

// The clockwise segment (1 the top segment .. 16; 0-sentinel the wheel
// center)
inline int afgG5Pos(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 16;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 4;
        case 6:
            return 5;
        case 7:
            return 6;
        case 8:
            return 7;
        case 9:
            return 8;
        case 10:
            return 9;
        case 11:
            return 10;
        case 12:
            return 11;
        case 13:
            return 12;
        case 14:
            return 13;
        case 15:
            return 14;
        case 16:
            return 0;
        default:
            return 0;
        }
    }

}   // namespace rules
