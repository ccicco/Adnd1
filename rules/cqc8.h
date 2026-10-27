// =========================================================================================
// Adnd1 - rules/cqc8.h
// Appendix 3: the clerical quick-reference chart, batch eight - the D&DG walk
// round twenty-eight, print p. 143: the 21 Norse and 7 Sumerian rows across
// the 13 printed columns.
// census 798 -> 799.
//
// primary ink: the ROTATED extract/ddg tesseract pass (pNNN_rot_full.txt +
// pNNN_rot_tsv.tsv, pdf page 143; the second printing); the collation voice:
// the 1eonline L&L per-deity chart rows. The adjudications: the Frigga
// female-only and Hel male-only single-X flags (the TSV geometry seats them,
// both voices agree); the Thor form burnt animals pinned by print over the
// L&L crafted items (eyeball flag); the Frey ornate helm restored over the
// L&L orntate garble; the Loki strife; fire semicolon pinned by print; the
// Uty and idun garbles restored per the R865/R866 crossref pins; the
// Nin-Hursag chart capitalization pinned per the chart print; the Surtur and
// Thrym cross-reference rows pinned as grid rows with 0-sentinel fields
// (their chart data landed in R875). NO GAP FLIP: the App 3 box stays open -
// the flip held one more round per Curtiss. The batch order runs the
// alphabetical Norse walk then the alphabetical Sumerian walk.
//
namespace rules {

// ---- the batch eight census ----

// the clerical chart batch eight round: the D&DG walk round twenty-eight
inline int cqc8Round()
    { return 876; }

// the eighth chart batch (the LAST chart batch of the App 3 walk)
inline int cqc8Batch()
    { return 8; }

// the chart batch eight print page opens at 143
inline int cqc8PrintStart()
    { return 143; }

// the chart batch eight print page closes at 143
inline int cqc8PrintEnd()
    { return 143; }

// the batch rows (the twenty-one Norse and seven Sumerian rows)
inline int cqc8Rows()
    { return 28; }

// the Norse rows (the nineteen data rows plus the Surtur and Thrym
// cross-references)
inline int cqc8NorseRows()
    { return 21; }

// the Sumerian rows (the R866 mythos beings)
inline int cqc8SumerianRows()
    { return 7; }

// the cross-reference rows (Surtur and Thrym - see Nonhumans' Deities; their
// chart data landed R875)
inline int cqc8CrossrefRows()
    { return 2; }

// the rows reading a male-clerics X
inline int cqc8MaleRows()
    { return 25; }

// the rows reading a female-clerics X (twelve Norse, five Sumerian)
inline int cqc8FemaleRows()
    { return 17; }

// the rows reading a non-human clerics X (Frey, Enki and Ki)
inline int cqc8NonHumanFlagRows()
    { return 3; }

// the printed columns of the chart (the 13 the batch grids encode)
inline int cqc8PrintedColumns()
    { return 13; }

// the sphere-of-control roster ordinals of the batch
inline int cqc8SphereCount()
    { return 25; }

// the animal roster ordinals of the batch
inline int cqc8AnimalCount()
    { return 22; }

// the raiment head roster ordinals of the batch
inline int cqc8HeadCount()
    { return 10; }

// the raiment body roster ordinals of the batch
inline int cqc8BodyCount()
    { return 13; }

// the color roster ordinals of the batch (one color per data row)
inline int cqc8ColorCount()
    { return 24; }

// the holy-days roster ordinals of the batch (the n/a rows ride the roster)
inline int cqc8HolyDayCount()
    { return 12; }

// the sacrifice-frequency roster ordinals of the batch
inline int cqc8FreqCount()
    { return 5; }

// the sacrifice-form roster ordinals of the batch
inline int cqc8FormCount()
    { return 10; }

// the place-of-worship roster ordinals of the batch
inline int cqc8PlaceCount()
    { return 5; }

// the batch grid count (one grid per batch round)
inline int cqc8TableCount()
    { return 1; }

// the batch chain count (the chart grids carry no chains)
inline int cqc8ChainCount()
    { return 0; }

// ---- the clerical chart batch eight grid ----

// The row ordinals (0-27, the batch walk order: the Norse rows then the
// Sumerian rows; the Surtur and Thrym cross-reference rows read 0-sentinel
// fields)
inline int cqc8ChartOrd(int b)
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
inline int cqc8ChartSphere(int b)
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
            return 0;
        case 16:
            return 15;
        case 17:
            return 0;
        case 18:
            return 16;
        case 19:
            return 17;
        case 20:
            return 12;
        case 21:
            return 18;
        case 22:
            return 19;
        case 23:
            return 20;
        case 24:
            return 21;
        case 25:
            return 22;
        case 26:
            return 23;
        case 27:
            return 24;
        default:
            return 0;
        }
    }

// The animal roster ordinals
inline int cqc8ChartAnimal(int b)
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
            return 0;
        case 16:
            return 15;
        case 17:
            return 0;
        case 18:
            return 16;
        case 19:
            return 17;
        case 20:
            return 2;
        case 21:
            return 18;
        case 22:
            return 19;
        case 23:
            return 7;
        case 24:
            return 20;
        case 25:
            return 4;
        case 26:
            return 21;
        case 27:
            return 6;
        default:
            return 0;
        }
    }

// The male clerics flag (the printed X reads 1; Frigga the only row without)
inline int cqc8ChartM(int b)
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
            return 0;
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
            return 0;
        case 16:
            return 1;
        case 17:
            return 0;
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

// The female clerics flag (the printed X reads 1)
inline int cqc8ChartF(int b)
    {
        switch (b) {
        case 0:
            return 0;
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
            return 0;
        case 9:
            return 0;
        case 10:
            return 1;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 1;
        case 15:
            return 0;
        case 16:
            return 1;
        case 17:
            return 0;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 0;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 1;
        case 25:
            return 0;
        case 26:
            return 1;
        case 27:
            return 0;
        default:
            return 0;
        }
    }

// The non-human clerics flag (the printed X reads 1; Frey, Enki and Ki)
inline int cqc8ChartNh(int b)
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
            return 0;
        case 5:
            return 1;
        case 6:
            return 0;
        case 7:
            return 0;
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
            return 1;
        case 23:
            return 0;
        case 24:
            return 1;
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

// The raiment head roster ordinals
inline int cqc8ChartHead(int b)
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
            return 4;
        case 8:
            return 0;
        case 9:
            return 4;
        case 10:
            return 4;
        case 11:
            return 0;
        case 12:
            return 7;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 8;
        case 20:
            return 4;
        case 21:
            return 4;
        case 22:
            return 4;
        case 23:
            return 9;
        case 24:
            return 9;
        case 25:
            return 4;
        case 26:
            return 4;
        case 27:
            return 4;
        default:
            return 0;
        }
    }

// The raiment body roster ordinals
inline int cqc8ChartBody(int b)
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
            return 0;
        case 5:
            return 3;
        case 6:
            return 4;
        case 7:
            return 5;
        case 8:
            return 6;
        case 9:
            return 7;
        case 10:
            return 8;
        case 11:
            return 3;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 9;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 10;
        case 19:
            return 11;
        case 20:
            return 3;
        case 21:
            return 12;
        case 22:
            return 12;
        case 23:
            return 12;
        case 24:
            return 12;
        case 25:
            return 12;
        case 26:
            return 12;
        case 27:
            return 12;
        default:
            return 0;
        }
    }

// The color roster ordinals (one color per data row)
inline int cqc8ChartColor(int b)
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
            return 0;
        case 16:
            return 15;
        case 17:
            return 0;
        case 18:
            return 16;
        case 19:
            return 17;
        case 20:
            return 18;
        case 21:
            return 19;
        case 22:
            return 20;
        case 23:
            return 21;
        case 24:
            return 17;
        case 25:
            return 22;
        case 26:
            return 23;
        case 27:
            return 18;
        default:
            return 0;
        }
    }

// The holy-days roster ordinals (the n/a rows ride the roster)
inline int cqc8ChartHolyday(int b)
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
            return 3;
        case 5:
            return 3;
        case 6:
            return 2;
        case 7:
            return 4;
        case 8:
            return 5;
        case 9:
            return 6;
        case 10:
            return 7;
        case 11:
            return 6;
        case 12:
            return 2;
        case 13:
            return 8;
        case 14:
            return 2;
        case 15:
            return 0;
        case 16:
            return 4;
        case 17:
            return 0;
        case 18:
            return 4;
        case 19:
            return 0;
        case 20:
            return 9;
        case 21:
            return 2;
        case 22:
            return 10;
        case 23:
            return 2;
        case 24:
            return 0;
        case 25:
            return 2;
        case 26:
            return 7;
        case 27:
            return 11;
        default:
            return 0;
        }
    }

// The sacrifice-frequency roster ordinals
inline int cqc8ChartFreq(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 3;
        case 9:
            return 3;
        case 10:
            return 3;
        case 11:
            return 3;
        case 12:
            return 1;
        case 13:
            return 4;
        case 14:
            return 1;
        case 15:
            return 0;
        case 16:
            return 1;
        case 17:
            return 0;
        case 18:
            return 1;
        case 19:
            return 0;
        case 20:
            return 3;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 0;
        case 25:
            return 1;
        case 26:
            return 3;
        case 27:
            return 3;
        default:
            return 0;
        }
    }

// The sacrifice-form roster ordinals (the n/a rows ride the roster)
inline int cqc8ChartForm(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 1;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 3;
        case 10:
            return 1;
        case 11:
            return 0;
        case 12:
            return 4;
        case 13:
            return 0;
        case 14:
            return 5;
        case 15:
            return 0;
        case 16:
            return 6;
        case 17:
            return 0;
        case 18:
            return 1;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 7;
        case 22:
            return 4;
        case 23:
            return 8;
        case 24:
            return 9;
        case 25:
            return 7;
        case 26:
            return 5;
        case 27:
            return 5;
        default:
            return 0;
        }
    }

// The place-of-worship roster ordinals
inline int cqc8ChartPlace(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 3;
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
            return 0;
        case 18:
            return 0;
        case 19:
            return 3;
        case 20:
            return 0;
        case 21:
            return 4;
        case 22:
            return 4;
        case 23:
            return 4;
        case 24:
            return 4;
        case 25:
            return 4;
        case 26:
            return 4;
        case 27:
            return 4;
        default:
            return 0;
        }
    }

// ---- the parity pins ----

// the App 3 gap flip held one more round per Curtiss - the R869 no-flip
// precedent extends past the last chart batch; gap_flips reads empty and the
// census holds 20/4
inline bool cqc8NoGapFlip()
    { return true; }

// the Surtur and Thrym cross-reference rows print as see Nonhumans' Deities
// rows - pinned as grid rows with 0-sentinel fields (their chart data landed
// in the R875 batch seven)
inline bool cqc8CrossrefRowsPinned()
    { return true; }

// the Frigga single X seats at the F column (the geometry, no M mark) - the
// L&L voice agrees (the walk's first female-only Norse row)
inline bool cqc8FriggaFemaleOnly()
    { return true; }

// the Hel single X seats at the M column - the L&L voice agrees (X - -)
inline bool cqc8HelMaleOnly()
    { return true; }

// the Thor form reads burnt animals in the print where the L&L voice reads
// crafted items - pinned by print, eyeball flag (the R869 Druaga precedent)
inline bool cqc8ThorFormPrintPin()
    { return true; }

// the Frey head reads ornate helm in the print - the L&L voice garbles it
// orntate; the print pinned
inline bool cqc8OrnateHelmRestored()
    { return true; }

// the Loki sphere semicolon strife; fire pinned by print (the L&L
// transcription comma an artifact - the R869 sphere-semicolon class)
inline bool cqc8LokiSemicolonPinned()
    { return true; }

// the Uty garble restored to Utu and the lowercase idun cap restored to Idun
// (the R865/R866 crossref pins); the Nin-Hursag chart capitalization pinned
// per the chart print
inline bool cqc8NameGarblesRestored()
    { return true; }

// the fold wraps restored - Odin wolves, ravens; Heimdall white plate mail;
// Idun forest meadows (both voices agree on the joined field text)
inline bool cqc8WrapLinesRestored()
    { return true; }

}   // namespace rules
