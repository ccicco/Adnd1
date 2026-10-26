// =========================================================================================
// Adnd1 - rules/tpl.h
// Appendix 2: temple trappings - the D&DG walk round twenty, print p. 134:
// the stocking doctrine and the 40-band trappings list (01-05 altar through
// 99-00 vestments), the representative-sample doctrine and the DM keying
// rules of the intro, the 40-label roster riding the round data file.
// census 790 -> 791.
//
// primary ink: the extract/ddg tesseract pass (pNNN_full.txt + pNNN_tsv.tsv,
// print = pdf - 1, page 135; the second printing) with the tsv x-y geometry
// as the label arbiter; the collation voice: the 1eonline L&L x2.htm appendix
// transcription. The adjudications: the choir area two-word print (the psm-4
// fold merged the words; the L&L voice keeps the space), the font/immersion
// chamber print (no space after the slash), the lectern/dais print (the L&L
// transcription trims to lectern), the books-and-tomes print (the L&L
// double-ampersand is a transcription artifact), and the L&L <cleric scrolls>
// and <+5 holy avenger, etc.> glosses noted as 5th-print additions absent
// from the 2nd print. The vestments 00 reads 100 (the R867 High convention).
//
namespace rules {

// ---- the temple trappings doctrine ----

// the temple trappings round: the D&DG walk round twenty
inline int tplRound()
    { return 868; }

// the print folio of Appendix 2 (pdf p. 135)
inline int tplPrintPage()
    { return 134; }

// the listing gives a representative sample of typical items that might be
// found in a temple of some of the deities listed in this work
inline bool tplRepresentativeSample()
    { return true; }

// any worshipers or servitors of the temple should be keyed by the DM
inline bool tplKeyedByDM()
    { return true; }

// the DM should choose from the list to stock the temple
inline bool tplChooseFromList()
    { return true; }

// random selection is used only to fill in details
inline bool tplRandomOnlyDetails()
    { return true; }

// random selection is used only in spur-of-the-moment situations
inline bool tplRandomOnlySpurOfMoment()
    { return true; }

// some of the items below will not be applicable to certain religions
inline bool tplSomeNotApplicable()
    { return true; }

// the printed example: no flame pits for living sacrifices in a lawful good
// temple
inline bool tplNoFlamePitsLawfulGood()
    { return true; }

// the list runs alphabetically (01-05 altar first, 99-00 vestments last)
inline bool tplAlphabeticalList()
    { return true; }

// ---- the trappings census ----

// the trappings list rows (01-05 altar through 99-00 vestments)
inline int tplRows()
    { return 40; }

// the percentile tiling of the list (01 through 00, the 00 reads 100)
inline int tplBandTotal()
    { return 100; }

// the first band low (the altar row)
inline int tplFirstBandLow()
    { return 1; }

// the first band high (the altar row)
inline int tplFirstBandHigh()
    { return 5; }

// the last band low (the vestments row)
inline int tplLastBandLow()
    { return 99; }

// the last band high (the vestments row, the printed 00)
inline int tplLastBandHigh()
    { return 100; }

// the widest band (six numbers wide: the books row 30-35)
inline int tplWidestBand()
    { return 6; }

// the widest band low (the holy/unholy books and tomes row)
inline int tplWidestBandLow()
    { return 30; }

// the single-number rows (chalice, chimes, choir area, flame pit, treasure,
// pedal organ, prayer wheels, sacrifice, scrolls, stained glass, throne)
inline int tplSingleRows()
    { return 11; }

// the two-number rows (the 17 pairs: bells through gong, the weapons through
// mosaics run, paintings, sanctuary, vestry, vestments)
inline int tplDoubleRows()
    { return 17; }

// the wide rows (three or more numbers: altar, columns, the
// books/inscriptions/symbols bands, offertory, pews, pulpit, robes, shrine,
// statue, tapestry)
inline int tplWideRows()
    { return 12; }

// the rows carrying the holy/unholy prefix (books and tomes, inscriptions,
// symbols, treasure, weapons)
inline int tplHolyUnholyRows()
    { return 5; }

// the trappings roster labels riding the data file
inline int tplRosterCount()
    { return 40; }

// the R868 grid count
inline int tplTableCount()
    { return 1; }

// the R868 chain count
inline int tplChainCount()
    { return 0; }

// ---- the temple trappings grid ----

// The trappings roster ordinals (40 labels, the row itself - the labels ride
// the data file)
inline int tplTrapOrd(int b)
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
        case 9:
            return 9;
        case 10:
            return 10;
        case 11:
            return 11;
        case 12:
            return 12;
        case 13:
            return 13;
        case 14:
            return 14;
        case 15:
            return 15;
        case 16:
            return 16;
        case 17:
            return 17;
        case 18:
            return 18;
        case 19:
            return 19;
        case 20:
            return 20;
        case 21:
            return 21;
        case 22:
            return 22;
        case 23:
            return 23;
        case 24:
            return 24;
        case 25:
            return 25;
        case 26:
            return 26;
        case 27:
            return 27;
        case 28:
            return 28;
        case 29:
            return 29;
        case 30:
            return 30;
        case 31:
            return 31;
        case 32:
            return 32;
        case 33:
            return 33;
        case 34:
            return 34;
        case 35:
            return 35;
        case 36:
            return 36;
        case 37:
            return 37;
        case 38:
            return 38;
        case 39:
            return 39;
        default:
            return 0;
        }
    }

// The percentile band lows (01-05 altar through 99-00 vestments)
inline int tplTrapLow(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 8;
        case 3:
            return 10;
        case 4:
            return 12;
        case 5:
            return 13;
        case 6:
            return 14;
        case 7:
            return 15;
        case 8:
            return 17;
        case 9:
            return 19;
        case 10:
            return 23;
        case 11:
            return 25;
        case 12:
            return 26;
        case 13:
            return 28;
        case 14:
            return 30;
        case 15:
            return 36;
        case 16:
            return 41;
        case 17:
            return 46;
        case 18:
            return 47;
        case 19:
            return 49;
        case 20:
            return 51;
        case 21:
            return 53;
        case 22:
            return 55;
        case 23:
            return 57;
        case 24:
            return 62;
        case 25:
            return 64;
        case 26:
            return 65;
        case 27:
            return 69;
        case 28:
            return 70;
        case 29:
            return 75;
        case 30:
            return 80;
        case 31:
            return 81;
        case 32:
            return 83;
        case 33:
            return 84;
        case 34:
            return 87;
        case 35:
            return 88;
        case 36:
            return 92;
        case 37:
            return 96;
        case 38:
            return 97;
        case 39:
            return 99;
        default:
            return 0;
        }
    }

// The percentile band highs (the printed 00 of the vestments row reads 100)
inline int tplTrapHigh(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 7;
        case 2:
            return 9;
        case 3:
            return 11;
        case 4:
            return 12;
        case 5:
            return 13;
        case 6:
            return 14;
        case 7:
            return 16;
        case 8:
            return 18;
        case 9:
            return 22;
        case 10:
            return 24;
        case 11:
            return 25;
        case 12:
            return 27;
        case 13:
            return 29;
        case 14:
            return 35;
        case 15:
            return 40;
        case 16:
            return 45;
        case 17:
            return 46;
        case 18:
            return 48;
        case 19:
            return 50;
        case 20:
            return 52;
        case 21:
            return 54;
        case 22:
            return 56;
        case 23:
            return 61;
        case 24:
            return 63;
        case 25:
            return 64;
        case 26:
            return 68;
        case 27:
            return 69;
        case 28:
            return 74;
        case 29:
            return 79;
        case 30:
            return 80;
        case 31:
            return 82;
        case 32:
            return 83;
        case 33:
            return 86;
        case 34:
            return 87;
        case 35:
            return 91;
        case 36:
            return 95;
        case 37:
            return 96;
        case 38:
            return 98;
        case 39:
            return 100;
        default:
            return 0;
        }
    }

// ---- the L&L parity pins ----

// the print reads choir area (two words; the psm-4 fold merged them)
inline bool tplChoirAreaTwoWords()
    { return true; }

// the print reads font/immersion chamber (no space after the slash)
inline bool tplFontImmersionPrint()
    { return true; }

// the print reads lectern/dais (the L&L transcription trims to lectern)
inline bool tplLecternDaisPrint()
    { return true; }

// the L&L <cleric scrolls> and <+5 holy avenger, etc.> glosses are 5th-print
// additions, absent from the 2nd print (noted divergences)
inline bool tplGlossesNotPrint()
    { return true; }

// the print reads holy/unholy books and tomes (the L&L voice carries a
// transcription double-ampersand)
inline bool tplAndTomesPrint()
    { return true; }

}   // namespace rules
