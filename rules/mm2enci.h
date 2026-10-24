// =========================================================================================
// Adnd1 - rules/mm2enci.h
// THE MM2 INDEX WALK - THE MERGED MM1/FF/MM2 INDEX CENSUS (print pp. 156-160:
// the gap box label says p. 156, the true span runs 156-160 in both scans;
// the 26 letter rows, the 1488 adjudicated lines, the 470 parenthetical
// cross-references), the ARC-CLOSER round - the Random Encounter Tables
// parent box and the Index gap box both flip to closed, 37 closed 0 open
// census 741 -> 742.
//
// Round twenty-four of the MM2 arc, the index census round (Curtiss Go call
// on the landed R818 aquatic walk; the pin-time walk found 26 letter rows of
// 6 cells each, no defs promoted - the registry stays 809)
//
// The pin header stays the print-fidelity record; the grid carries the
// ordinal, total, MM1, FF, this-book and cross-reference cells, the two-voice
// method rides the audit comments, and the walk cross-checks the letter
// arithmetic and the registry keys live
//
namespace rules {

// ---- the R819 census ----

// The MM2 index walk round: the merged MM1/FF/MM2 index census, the arc
// closer (Curtiss Go call on the landed R818)
inline int mm2enciRound()
    { return 819; }

// The gap box label folio (p. 156); the true print span runs 156-160
inline int mm2enciPrintFolio()
    { return 156; }

// The first index page (the printed page numbers in both scans)
inline int mm2enciFirstPage()
    { return 156; }

// The last index page (the five-page span, both scans)
inline int mm2enciLastPage()
    { return 160; }

// The 26 letter sections A through Z, one grid row each
inline int mm2enciLetterCount()
    { return 26; }

// The index prints a 4-column layout on every page
inline int mm2enciColumnsPerPage()
    { return 4; }

// The adjudicated index line census (two voices collated)
inline int mm2enciTotalLines()
    { return 1488; }

// The lines carrying an M reference (MONSTER MANUAL I)
inline int mm2enciMm1Lines()
    { return 577; }

// The lines carrying an F reference (FIEND FOLIO)
inline int mm2enciFfLines()
    { return 401; }

// The lines with no letter reference (detailed in this book)
inline int mm2enciThisBookLines()
    { return 510; }

// The lines carrying a parenthetical cross-reference (the name under which it
// is found)
inline int mm2enciCrossRefLines()
    { return 470; }

// The S section carries the most lines
inline int mm2enciLargestLetterTotal()
    { return 180; }

// The Z section carries the fewest lines
inline int mm2enciSmallestLetterTotal()
    { return 4; }

// The S section carries the most M-referenced lines
inline int mm2enciMaxMm1Letter()
    { return 64; }

// The S section carries the most F-referenced lines
inline int mm2enciMaxFfLetter()
    { return 52; }

// The S section carries the most this-book lines
inline int mm2enciMaxThisBookLetter()
    { return 64; }

// The S section carries the most parenthetical cross-references
inline int mm2enciLargestCrossRefLetter()
    { return 63; }

// The voice A scan lines after the junk filter (the tsr02016 djvu)
inline int mm2enciVoiceASlots()
    { return 1495; }

// The voice B scan lines after the junk filter (the monstermanualii1sted
// djvu)
inline int mm2enciVoiceBSlots()
    { return 1501; }

// The dropped split fragments and doctrine-prose lines (2 doctrine + 7
// fragments)
inline int mm2enciFragmentDrops()
    { return 9; }

// The reclassified lines whose page reference the OCR lost (Leprechaun, Salt
// Water Troll, Troll, Weasel)
inline int mm2enciRefLostLines()
    { return 4; }

// The flagged reference-lost lines (the Sirme and Stalker rows, reclassified
// this-book)
inline int mm2enciFlaggedReads()
    { return 2; }

// The B-only lines adjudicated real (Caryatid Column, Olhydra - no registry
// def, the OA/lammasu seam stays queued)
inline int mm2enciBOnlyRealEntries()
    { return 2; }

// The single-voice slots at pairing (100 voice-A only + 106 voice-B only)
inline int mm2enciSingleVoiceSlots()
    { return 206; }

// The opening doctrine month: all official creatures as of December 1982
inline int mm2enciCoverageMonth()
    { return 12; }

// The opening doctrine year
inline int mm2enciCoverageYear()
    { return 1982; }

// The two book abbreviations (M for MONSTER MANUAL I, F for FIEND FOLIO)
inline int mm2enciAbbrevCount()
    { return 2; }

// The registry def floor (no defs promoted this round)
inline int mm2enciRegistryFloor()
    { return 809; }

// The MM1 defs in the registry
inline int mm2enciRegistryMm1Defs()
    { return 408; }

// The MM2 defs in the registry
inline int mm2enciRegistryMm2Defs()
    { return 331; }

// The A section total lines
inline int mm2enciTotalA()
    { return 70; }

// The B section total lines
inline int mm2enciTotalB()
    { return 114; }

// The C section total lines
inline int mm2enciTotalC()
    { return 96; }

// The D section total lines
inline int mm2enciTotalD()
    { return 84; }

// The E section total lines
inline int mm2enciTotalE()
    { return 48; }

// The F section total lines
inline int mm2enciTotalF()
    { return 72; }

// The G section total lines
inline int mm2enciTotalG()
    { return 91; }

// The H section total lines
inline int mm2enciTotalH()
    { return 64; }

// The I section total lines
inline int mm2enciTotalI()
    { return 30; }

// The J section total lines
inline int mm2enciTotalJ()
    { return 18; }

// The K section total lines
inline int mm2enciTotalK()
    { return 29; }

// The L section total lines
inline int mm2enciTotalL()
    { return 62; }

// The M section total lines
inline int mm2enciTotalM()
    { return 112; }

// The N section total lines
inline int mm2enciTotalN()
    { return 31; }

// The O section total lines
inline int mm2enciTotalO()
    { return 46; }

// The P section total lines
inline int mm2enciTotalP()
    { return 72; }

// The Q section total lines
inline int mm2enciTotalQ()
    { return 11; }

// The R section total lines
inline int mm2enciTotalR()
    { return 41; }

// The S section total lines
inline int mm2enciTotalS()
    { return 180; }

// The T section total lines
inline int mm2enciTotalT()
    { return 76; }

// The U section total lines
inline int mm2enciTotalU()
    { return 15; }

// The V section total lines
inline int mm2enciTotalV()
    { return 26; }

// The W section total lines
inline int mm2enciTotalW()
    { return 75; }

// The X section total lines
inline int mm2enciTotalX()
    { return 6; }

// The Y section total lines
inline int mm2enciTotalY()
    { return 15; }

// The Z section total lines
inline int mm2enciTotalZ()
    { return 4; }

// ---- the opening doctrine (the R819 census) ----

// The index includes all official creatures published in this volume, the
// MONSTER MANUAL and the FIEND FOLIO
inline bool mm2enciIncludesAllOfficialCreatures()
    { return true; }

// The official-creature coverage stops as of December 1982
inline bool mm2enciCoverageStopsDecember1982()
    { return true; }

// The MONSTER MANUAL I abbreviation is M
inline bool mm2enciMm1AbbreviatedM()
    { return true; }

// The FIEND FOLIO abbreviation is F
inline bool mm2enciFfAbbreviatedF()
    { return true; }

// No letter when the creature is detailed in this book
inline bool mm2enciThisBookCarriesNoLetter()
    { return true; }

// The left-hand column gives the book and page where each creature may be
// found
inline bool mm2enciLeftColumnGivesBookAndPage()
    { return true; }

// A listing in parentheses to the right of the entry indicates the name under
// which it is found
inline bool mm2enciParentheticalNamesTheRealEntry()
    { return true; }

// The index prints a 4-column layout
inline bool mm2enciLayoutIsFourColumns()
    { return true; }

// The line census is a two-voice adjudication (both djvu scans parsed
// independently, paired per letter, the single-voice slots adjudicated by
// hand)
inline bool mm2enciCensusIsTwoVoiceAdjudicated()
    { return true; }

// The census counts index lines, not registry defs (the within-letter
// double-listings retained as separate print lines)
inline bool mm2enciLineCensusNotDefCensus()
    { return true; }

// No defs promoted this round (the registry stays at the floor)
inline bool mm2enciNoDefsPromotedThisRound()
    { return true; }

// The ref-fused M and F OCR lines re-lettered to their true sections
inline bool mm2enciRefFusedLinesRelettered()
    { return true; }

// The Random Encounter Tables parent box closes riding this round (the
// R816/R817/R818 children all closed)
inline bool mm2enciParentClosesWithIndex()
    { return true; }

// The Index box is the last MM2 arc box - the gap flips to 37 closed, 0 open
inline bool mm2enciMm2ArcClosesThisRound()
    { return true; }

// ---- the merged index line census grid pins ----

// The letter ordinal cells (1-26 contiguous, one row per letter A-Z)
inline int mm2enciOrdinal(int b)
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
        case 17:
            return 18;
        case 18:
            return 19;
        case 19:
            return 20;
        case 20:
            return 21;
        case 21:
            return 22;
        case 22:
            return 23;
        case 23:
            return 24;
        case 24:
            return 25;
        case 25:
            return 26;
        default:
            return 0;
        }
    }

// The total adjudicated line cells per letter
inline int mm2enciTotal(int b)
    {
        switch (b) {
        case 0:
            return 70;
        case 1:
            return 114;
        case 2:
            return 96;
        case 3:
            return 84;
        case 4:
            return 48;
        case 5:
            return 72;
        case 6:
            return 91;
        case 7:
            return 64;
        case 8:
            return 30;
        case 9:
            return 18;
        case 10:
            return 29;
        case 11:
            return 62;
        case 12:
            return 112;
        case 13:
            return 31;
        case 14:
            return 46;
        case 15:
            return 72;
        case 16:
            return 11;
        case 17:
            return 41;
        case 18:
            return 180;
        case 19:
            return 76;
        case 20:
            return 15;
        case 21:
            return 26;
        case 22:
            return 75;
        case 23:
            return 6;
        case 24:
            return 15;
        case 25:
            return 4;
        default:
            return 0;
        }
    }

// The M-reference line cells per letter (the MONSTER MANUAL I abbreviation)
inline int mm2enciMm1(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 49;
        case 2:
            return 33;
        case 3:
            return 21;
        case 4:
            return 21;
        case 5:
            return 20;
        case 6:
            return 35;
        case 7:
            return 34;
        case 8:
            return 15;
        case 9:
            return 8;
        case 10:
            return 7;
        case 11:
            return 31;
        case 12:
            return 47;
        case 13:
            return 11;
        case 14:
            return 17;
        case 15:
            return 32;
        case 16:
            return 1;
        case 17:
            return 19;
        case 18:
            return 64;
        case 19:
            return 30;
        case 20:
            return 3;
        case 21:
            return 4;
        case 22:
            return 45;
        case 23:
            return 1;
        case 24:
            return 3;
        case 25:
            return 1;
        default:
            return 0;
        }
    }

// The F-reference line cells per letter (the FIEND FOLIO abbreviation)
inline int mm2enciFf(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 23;
        case 2:
            return 25;
        case 3:
            return 27;
        case 4:
            return 14;
        case 5:
            return 26;
        case 6:
            return 32;
        case 7:
            return 12;
        case 8:
            return 13;
        case 9:
            return 5;
        case 10:
            return 13;
        case 11:
            return 19;
        case 12:
            return 21;
        case 13:
            return 12;
        case 14:
            return 9;
        case 15:
            return 18;
        case 16:
            return 4;
        case 17:
            return 11;
        case 18:
            return 52;
        case 19:
            return 16;
        case 20:
            return 6;
        case 21:
            return 6;
        case 22:
            return 13;
        case 23:
            return 2;
        case 24:
            return 7;
        case 25:
            return 0;
        default:
            return 0;
        }
    }

// The no-letter line cells per letter (detailed in this book)
inline int mm2enciThisBook(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 42;
        case 2:
            return 38;
        case 3:
            return 36;
        case 4:
            return 13;
        case 5:
            return 26;
        case 6:
            return 24;
        case 7:
            return 18;
        case 8:
            return 2;
        case 9:
            return 5;
        case 10:
            return 9;
        case 11:
            return 12;
        case 12:
            return 44;
        case 13:
            return 8;
        case 14:
            return 20;
        case 15:
            return 22;
        case 16:
            return 6;
        case 17:
            return 11;
        case 18:
            return 64;
        case 19:
            return 30;
        case 20:
            return 6;
        case 21:
            return 16;
        case 22:
            return 17;
        case 23:
            return 3;
        case 24:
            return 5;
        case 25:
            return 3;
        default:
            return 0;
        }
    }

// The parenthetical cross-reference line cells per letter
inline int mm2enciCrossRef(int b)
    {
        switch (b) {
        case 0:
            return 24;
        case 1:
            return 34;
        case 2:
            return 25;
        case 3:
            return 21;
        case 4:
            return 18;
        case 5:
            return 27;
        case 6:
            return 22;
        case 7:
            return 23;
        case 8:
            return 13;
        case 9:
            return 5;
        case 10:
            return 8;
        case 11:
            return 24;
        case 12:
            return 36;
        case 13:
            return 8;
        case 14:
            return 11;
        case 15:
            return 20;
        case 16:
            return 1;
        case 17:
            return 16;
        case 18:
            return 63;
        case 19:
            return 23;
        case 20:
            return 7;
        case 21:
            return 7;
        case 22:
            return 33;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 1;
        default:
            return 0;
        }
    }

}   // namespace rules
