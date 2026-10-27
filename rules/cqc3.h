// =========================================================================================
// Adnd1 - rules/cqc3.h
// Appendix 3: the clerical quick-reference chart, batch three - the D&DG walk
// round twenty-three, print pp. 138-139: the 28 rows of the Egyptian and
// Finnish pantheons across the 13 printed columns.
// census 793 -> 794.
//
// primary ink: the ROTATED extract/ddg tesseract pass (pNNN_rot_full.txt +
// pNNN_rot_tsv.tsv, pdf pages 138-139; the second printing) - the Egyptian
// block sits below the R870 Cthulhu tail on pdf 138, the Finnish block spans
// the pdf 138 tail and the pdf 139 head; the collation voice: the 1eonline
// L&L per-deity chart rows. The adjudications: the Seker row (the L&L voice
// duplicates Shu - the print row pinned, eyeball flag), the empty L&L sphere
// cells (Geb earth, Set evil - the print pinned), the Isis magic spelling
// (the L&L magick <(The Occult)> gloss a 5th-print addition), the Ilmatar
// single-X geometry seated in the F column by the TSV (female-only, both
// voices agree), the Bes Ie;:nher garble restored to leather vest, kilt, the
// Ukko chain mail pinned over the L&L chian typo, and the Mielikki lowercase
// nature pinned. The batch order runs Egyptian, Finnish.
//
namespace rules {

// ---- the batch three census ----

// the clerical chart batch three round: the D&DG walk round twenty-three
inline int cqc3Round()
    { return 871; }

// the third chart batch (the App 3 box stays open until the last batch lands)
inline int cqc3Batch()
    { return 3; }

// the chart batch three print pages open at 138
inline int cqc3PrintStart()
    { return 138; }

// the chart batch three print pages close at 139
inline int cqc3PrintEnd()
    { return 139; }

// the batch rows (Egyptian 17, Finnish 11)
inline int cqc3Rows()
    { return 28; }

// the Egyptian pantheon rows
inline int cqc3EgyRows()
    { return 17; }

// the Finnish mythos rows
inline int cqc3FinRows()
    { return 11; }

// the rows reading a male-clerics X (Ilmatar the only row without)
inline int cqc3MaleRows()
    { return 27; }

// the rows reading a female-clerics X (Anhur the only row without)
inline int cqc3FemaleRows()
    { return 27; }

// the rows reading a non-human clerics X (all Egyptian; the Finnish rows read
// none)
inline int cqc3NonHumanRows()
    { return 6; }

// the printed columns of the chart (the 13 the batch grids encode)
inline int cqc3PrintedColumns()
    { return 13; }

// the sphere-of-control roster ordinals of the batch
inline int cqc3SphereCount()
    { return 26; }

// the animal roster ordinals of the batch
inline int cqc3AnimalCount()
    { return 27; }

// the raiment head roster ordinals of the batch (the Geb n/a rides the
// roster)
inline int cqc3HeadCount()
    { return 15; }

// the raiment body roster ordinals of the batch
inline int cqc3BodyCount()
    { return 26; }

// the color roster ordinals of the batch
inline int cqc3ColorCount()
    { return 24; }

// the holy-days roster ordinals of the batch (the n/a rows ride the roster)
inline int cqc3HolyDayCount()
    { return 11; }

// the sacrifice-frequency roster ordinals of the batch
inline int cqc3FreqCount()
    { return 6; }

// the sacrifice-form roster ordinals of the batch
inline int cqc3FormCount()
    { return 17; }

// the place-of-worship roster ordinals of the batch (the special hall and the
// n/a rows ride the roster)
inline int cqc3PlaceCount()
    { return 5; }

// the batch grid count (one grid per batch round)
inline int cqc3TableCount()
    { return 1; }

// the batch chain count (the chart grids carry no chains)
inline int cqc3ChainCount()
    { return 0; }

// ---- the clerical chart batch three grid ----

// The row ordinals (0-27, the batch walk order: Egyptian 0-16, Finnish 17-27)
inline int cqc3ChartOrd(int b)
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
        default:
            return 0;
        }
    }

// The sphere-of-control roster ordinals (the labels ride the data file)
inline int cqc3ChartSphere(int b)
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
            return 13;
        case 19:
            return 18;
        case 20:
            return 19;
        case 21:
            return 20;
        case 22:
            return 21;
        case 23:
            return 22;
        case 24:
            return 23;
        case 25:
            return 23;
        case 26:
            return 24;
        case 27:
            return 25;
        default:
            return 0;
        }
    }

// The animal roster ordinals
inline int cqc3ChartAnimal(int b)
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
            return 5;
        case 24:
            return 23;
        case 25:
            return 24;
        case 26:
            return 25;
        case 27:
            return 26;
        default:
            return 0;
        }
    }

// The male clerics flag (the printed X reads 1; Ilmatar the only row without)
inline int cqc3ChartM(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 0;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 1;
        default:
            return 0;
        }
    }

// The female clerics flag (the printed X reads 1; Anhur the only row without)
inline int cqc3ChartF(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 1;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 1;
        default:
            return 0;
        }
    }

// The non-human clerics flag (the printed X reads 1; the Finnish rows read
// none)
inline int cqc3ChartNh(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 1;
        case 12:
            return 0;
        case 13:
            return 1;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 1;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        default:
            return 0;
        }
    }

// The raiment head roster ordinals (the Geb n/a rides the roster)
inline int cqc3ChartHead(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 4;
        case 6:
            return 5;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 6;
        case 12:
            return 7;
        case 13:
            return 6;
        case 14:
            return 2;
        case 15:
            return 8;
        case 16:
            return 2;
        case 17:
            return 9;
        case 18:
            return 2;
        case 19:
            return 2;
        case 20:
            return 10;
        case 21:
            return 11;
        case 22:
            return 2;
        case 23:
            return 12;
        case 24:
            return 7;
        case 25:
            return 13;
        case 26:
            return 14;
        case 27:
            return 2;
        default:
            return 0;
        }
    }

// The raiment body roster ordinals
inline int cqc3ChartBody(int b)
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
            return 10;
        case 23:
            return 22;
        case 24:
            return 23;
        case 25:
            return 15;
        case 26:
            return 24;
        case 27:
            return 25;
        default:
            return 0;
        }
    }

// The color roster ordinals (the Seker white is the round divergence pin)
inline int cqc3ChartColor(int b)
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
            return 12;
        case 20:
            return 19;
        case 21:
            return 20;
        case 22:
            return 21;
        case 23:
            return 8;
        case 24:
            return 22;
        case 25:
            return 16;
        case 26:
            return 0;
        case 27:
            return 23;
        default:
            return 0;
        }
    }

// The holy-days roster ordinals (the n/a rows ride the roster)
inline int cqc3ChartHolyday(int b)
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
            return 2;
        case 5:
            return 4;
        case 6:
            return 5;
        case 7:
            return 6;
        case 8:
            return 2;
        case 9:
            return 4;
        case 10:
            return 1;
        case 11:
            return 4;
        case 12:
            return 7;
        case 13:
            return 2;
        case 14:
            return 1;
        case 15:
            return 3;
        case 16:
            return 1;
        case 17:
            return 3;
        case 18:
            return 8;
        case 19:
            return 2;
        case 20:
            return 9;
        case 21:
            return 10;
        case 22:
            return 3;
        case 23:
            return 8;
        case 24:
            return 8;
        case 25:
            return 8;
        case 26:
            return 2;
        case 27:
            return 4;
        default:
            return 0;
        }
    }

// The sacrifice-frequency roster ordinals (the n/a rows ride the roster)
inline int cqc3ChartFreq(int b)
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
            return 2;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 4;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 4;
        case 11:
            return 2;
        case 12:
            return 3;
        case 13:
            return 2;
        case 14:
            return 4;
        case 15:
            return 3;
        case 16:
            return 4;
        case 17:
            return 3;
        case 18:
            return 5;
        case 19:
            return 2;
        case 20:
            return 3;
        case 21:
            return 3;
        case 22:
            return 3;
        case 23:
            return 5;
        case 24:
            return 5;
        case 25:
            return 5;
        case 26:
            return 2;
        case 27:
            return 2;
        default:
            return 0;
        }
    }

// The sacrifice-form roster ordinals (the n/a rows ride the roster)
inline int cqc3ChartForm(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 0;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 0;
        case 6:
            return 4;
        case 7:
            return 5;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 6;
        case 11:
            return 4;
        case 12:
            return 7;
        case 13:
            return 0;
        case 14:
            return 8;
        case 15:
            return 2;
        case 16:
            return 6;
        case 17:
            return 9;
        case 18:
            return 10;
        case 19:
            return 11;
        case 20:
            return 12;
        case 21:
            return 13;
        case 22:
            return 14;
        case 23:
            return 10;
        case 24:
            return 10;
        case 25:
            return 10;
        case 26:
            return 15;
        case 27:
            return 16;
        default:
            return 0;
        }
    }

// The place-of-worship roster ordinals (the special hall and the n/a rows
// ride the roster)
inline int cqc3ChartPlace(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 1;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 1;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 2;
        case 18:
            return 3;
        case 19:
            return 2;
        case 20:
            return 2;
        case 21:
            return 2;
        case 22:
            return 4;
        case 23:
            return 3;
        case 24:
            return 3;
        case 25:
            return 3;
        case 26:
            return 2;
        case 27:
            return 2;
        default:
            return 0;
        }
    }

// ---- the parity pins ----

// the headline divergence: the L&L Seker row duplicates Shu (bare, blue vest,
// light blue, equinox, semiannually, gems) - the print reads the distinct
// Seker row (feathered helm, white tunic, white, summer solstice, annually,
// jewelry) - pinned by print, eyeball flag
inline bool cqc3SekerDistinctPrint()
    { return true; }

// the print reads earth for the Geb sphere where the L&L sphere cell is empty
// - pinned by print
inline bool cqc3GebSpherePrint()
    { return true; }

// the print reads evil for the Set sphere where the L&L sphere cell is empty
// - pinned by print
inline bool cqc3SetSpherePrint()
    { return true; }

// the print reads magic for the Isis sphere; the L&L magick <(The Occult)>
// gloss is a 5th-print addition - pinned by print, noted
inline bool cqc3IsisMagicPinned()
    { return true; }

// the Ilmatar row reads a single X - the TSV geometry seats it in the F
// column (x 1085 against the M 1030 / F 1086 column bars), the L&L voice
// agrees: female-only clerics
inline bool cqc3IlmatarFemaleOnly()
    { return true; }

// the rotated pass garbles the Bes raiment (the Ie;:nher glyph run) - the
// leather vest, kilt restored from the L&L voice
inline bool cqc3BesVestRestored()
    { return true; }

// the print reads chain mail for the Ukko raiment body - the L&L chian typo
// noted, the print pinned
inline bool cqc3UkkoChainMail()
    { return true; }

// the print reads the Mielikki sphere lowercase nature - the L&L capital
// noted, the print pinned
inline bool cqc3MielikkiLowercaseNature()
    { return true; }

// Ilmatar is the only batch three row reading a female-only cleric flag
inline bool cqc3IlmatarSoleFemaleOnly()
    { return true; }

// the Finnish mythos rows carry no non-human clerics X
inline bool cqc3FinnishNoNonHuman()
    { return true; }

}   // namespace rules
