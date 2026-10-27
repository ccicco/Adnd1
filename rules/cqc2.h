// =========================================================================================
// Adnd1 - rules/cqc2.h
// Appendix 3: the clerical quick-reference chart, batch two - the D&DG walk
// round twenty-two, print pp. 136-137: the 35 rows of the Central American,
// Chinese and Cthulhu pantheons across the 13 printed columns.
// census 792 -> 793.
//
// primary ink: the ROTATED extract/ddg tesseract pass (pNNN_rot_full.txt +
// pNNN_rot_tsv.tsv, pdf pages 136-138; the second printing) - the Cthulhu
// block spills onto pdf p138 head (Ithaqua, Nyarlathotep, Shub-Niggurath,
// Yog-Sothoth); the collation voice: the 1eonline L&L per-deity chart rows
// (the flafp.htm slug for Fei Lien and Feng Po, the nocha.htm slug for No
// Cha). The adjudications: the Hastur sky blue color (print over the L&L
// yellow-orange, eyeball flag), the gray spellings of the print pinned over
// the L&L grey, the L&L <sea caves> gloss on the Cthulhu place a 5th-print
// addition, the chart-print Cthuga garble (the R856 walk pins Cthugha), the !
// glyph name garbles (Huehueteotl, Tlazolteotl), the FeiLien space restored,
// and the semicolon spheres (both voices agree). The batch order runs Central
// American, Chinese, Cthulhu.
//
namespace rules {

// ---- the batch two census ----

// the clerical chart batch two round: the D&DG walk round twenty-two
inline int cqc2Round()
    { return 870; }

// the second chart batch (the App 3 box stays open until the last batch
// lands)
inline int cqc2Batch()
    { return 2; }

// the chart batch two print pages open at 136
inline int cqc2PrintStart()
    { return 136; }

// the chart batch two print pages close at 137 (the Cthulhu tail rides the
// next pdf head)
inline int cqc2PrintEnd()
    { return 137; }

// the batch rows (Central American 12, Chinese 15, Cthulhu 8)
inline int cqc2Rows()
    { return 35; }

// the Central American pantheon rows
inline int cqc2CARows()
    { return 12; }

// the Chinese pantheon rows
inline int cqc2ChineseRows()
    { return 15; }

// the Cthulhu mythos rows
inline int cqc2CthulhuRows()
    { return 8; }

// the rows reading a male-clerics X (every batch two row)
inline int cqc2MaleRows()
    { return 35; }

// the rows reading a female-clerics X
inline int cqc2FemaleRows()
    { return 22; }

// the rows reading a non-human clerics X (the Chinese pantheon reads none)
inline int cqc2NonHumanRows()
    { return 12; }

// the printed columns of the chart (the 13 the batch one grid encodes)
inline int cqc2PrintedColumns()
    { return 13; }

// the sphere-of-control roster ordinals of the batch
inline int cqc2SphereCount()
    { return 30; }

// the animal roster ordinals of the batch (the n/a rows ride the roster)
inline int cqc2AnimalCount()
    { return 25; }

// the raiment head roster ordinals of the batch
inline int cqc2HeadCount()
    { return 12; }

// the raiment body roster ordinals of the batch
inline int cqc2BodyCount()
    { return 22; }

// the color roster ordinals of the batch
inline int cqc2ColorCount()
    { return 32; }

// the holy-days roster ordinals of the batch
inline int cqc2HolyDayCount()
    { return 14; }

// the sacrifice-frequency roster ordinals of the batch
inline int cqc2FreqCount()
    { return 9; }

// the sacrifice-form roster ordinals of the batch
inline int cqc2FormCount()
    { return 22; }

// the place-of-worship roster ordinals of the batch
inline int cqc2PlaceCount()
    { return 16; }

// the batch grid count (one grid per batch round)
inline int cqc2TableCount()
    { return 1; }

// the batch chain count (the chart grids carry no chains)
inline int cqc2ChainCount()
    { return 0; }

// ---- the clerical chart batch two grid ----

// The row ordinals (0-34, the batch walk order: Central American 0-11,
// Chinese 12-26, Cthulhu 27-34)
inline int cqc2ChartOrd(int b)
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
        default:
            return 0;
        }
    }

// The sphere-of-control roster ordinals (the labels ride the data file)
inline int cqc2ChartSphere(int b)
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
            return 5;
        case 14:
            return 13;
        case 15:
            return 9;
        case 16:
            return 14;
        case 17:
            return 15;
        case 18:
            return 5;
        case 19:
            return 16;
        case 20:
            return 17;
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
        case 28:
            return 25;
        case 29:
            return 4;
        case 30:
            return 0;
        case 31:
            return 26;
        case 32:
            return 27;
        case 33:
            return 28;
        case 34:
            return 29;
        default:
            return 0;
        }
    }

// The animal roster ordinals (the n/a rows ride the roster)
inline int cqc2ChartAnimal(int b)
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
            return 5;
        case 18:
            return 17;
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
            return 23;
        case 28:
            return 23;
        case 29:
            return 23;
        case 30:
            return 23;
        case 31:
            return 23;
        case 32:
            return 23;
        case 33:
            return 23;
        case 34:
            return 23;
        default:
            return 0;
        }
    }

// The male clerics flag (the printed X reads 1)
inline int cqc2ChartM(int b)
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
        case 28:
            return 1;
        case 29:
            return 1;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 1;
        case 33:
            return 1;
        case 34:
            return 1;
        default:
            return 0;
        }
    }

// The female clerics flag (the printed X reads 1)
inline int cqc2ChartF(int b)
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
            return 0;
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
            return 0;
        case 14:
            return 0;
        case 15:
            return 1;
        case 16:
            return 1;
        case 17:
            return 1;
        case 18:
            return 0;
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
            return 0;
        case 25:
            return 0;
        case 26:
            return 1;
        case 27:
            return 1;
        case 28:
            return 0;
        case 29:
            return 0;
        case 30:
            return 0;
        case 31:
            return 0;
        case 32:
            return 0;
        case 33:
            return 0;
        case 34:
            return 1;
        default:
            return 0;
        }
    }

// The non-human clerics flag (the printed X reads 1; the Chinese pantheon
// reads none)
inline int cqc2ChartNh(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
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
            return 1;
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
            return 1;
        case 28:
            return 1;
        case 29:
            return 1;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 1;
        case 33:
            return 1;
        case 34:
            return 1;
        default:
            return 0;
        }
    }

// The raiment head roster ordinals
inline int cqc2ChartHead(int b)
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
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 1;
        case 9:
            return 2;
        case 10:
            return 0;
        case 11:
            return 1;
        case 12:
            return 4;
        case 13:
            return 5;
        case 14:
            return 6;
        case 15:
            return 7;
        case 16:
            return 4;
        case 17:
            return 8;
        case 18:
            return 7;
        case 19:
            return 8;
        case 20:
            return 8;
        case 21:
            return 6;
        case 22:
            return 9;
        case 23:
            return 10;
        case 24:
            return 11;
        case 25:
            return 4;
        case 26:
            return 4;
        case 27:
            return 8;
        case 28:
            return 8;
        case 29:
            return 8;
        case 30:
            return 8;
        case 31:
            return 8;
        case 32:
            return 8;
        case 33:
            return 8;
        case 34:
            return 8;
        default:
            return 0;
        }
    }

// The raiment body roster ordinals (the n/a rows ride the roster)
inline int cqc2ChartBody(int b)
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
            return 2;
        case 5:
            return 3;
        case 6:
            return 0;
        case 7:
            return 2;
        case 8:
            return 1;
        case 9:
            return 0;
        case 10:
            return 4;
        case 11:
            return 5;
        case 12:
            return 6;
        case 13:
            return 7;
        case 14:
            return 8;
        case 15:
            return 9;
        case 16:
            return 10;
        case 17:
            return 7;
        case 18:
            return 11;
        case 19:
            return 12;
        case 20:
            return 13;
        case 21:
            return 14;
        case 22:
            return 15;
        case 23:
            return 16;
        case 24:
            return 17;
        case 25:
            return 18;
        case 26:
            return 19;
        case 27:
            return 20;
        case 28:
            return 20;
        case 29:
            return 20;
        case 30:
            return 20;
        case 31:
            return 20;
        case 32:
            return 21;
        case 33:
            return 20;
        case 34:
            return 20;
        default:
            return 0;
        }
    }

// The color roster ordinals (the Hastur sky blue is the round divergence pin)
inline int cqc2ChartColor(int b)
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
            return 8;
        case 11:
            return 10;
        case 12:
            return 1;
        case 13:
            return 11;
        case 14:
            return 12;
        case 15:
            return 13;
        case 16:
            return 14;
        case 17:
            return 15;
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
            return 22;
        case 25:
            return 23;
        case 26:
            return 24;
        case 27:
            return 25;
        case 28:
            return 26;
        case 29:
            return 27;
        case 30:
            return 28;
        case 31:
            return 29;
        case 32:
            return 24;
        case 33:
            return 30;
        case 34:
            return 31;
        default:
            return 0;
        }
    }

// The holy-days roster ordinals (the n/a rows ride the roster)
inline int cqc2ChartHolyday(int b)
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
            return 3;
        case 5:
            return 3;
        case 6:
            return 4;
        case 7:
            return 3;
        case 8:
            return 5;
        case 9:
            return 5;
        case 10:
            return 3;
        case 11:
            return 3;
        case 12:
            return 6;
        case 13:
            return 3;
        case 14:
            return 5;
        case 15:
            return 5;
        case 16:
            return 0;
        case 17:
            return 5;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 7;
        case 21:
            return 1;
        case 22:
            return 0;
        case 23:
            return 7;
        case 24:
            return 8;
        case 25:
            return 9;
        case 26:
            return 4;
        case 27:
            return 10;
        case 28:
            return 8;
        case 29:
            return 11;
        case 30:
            return 11;
        case 31:
            return 12;
        case 32:
            return 13;
        case 33:
            return 10;
        case 34:
            return 8;
        default:
            return 0;
        }
    }

// The sacrifice-frequency roster ordinals
inline int cqc2ChartFreq(int b)
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
            return 1;
        case 6:
            return 3;
        case 7:
            return 4;
        case 8:
            return 5;
        case 9:
            return 5;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 5;
        case 13:
            return 6;
        case 14:
            return 5;
        case 15:
            return 5;
        case 16:
            return 0;
        case 17:
            return 5;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 5;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 7;
        case 24:
            return 5;
        case 25:
            return 5;
        case 26:
            return 8;
        case 27:
            return 5;
        case 28:
            return 5;
        case 29:
            return 5;
        case 30:
            return 5;
        case 31:
            return 5;
        case 32:
            return 1;
        case 33:
            return 5;
        case 34:
            return 5;
        default:
            return 0;
        }
    }

// The sacrifice-form roster ordinals
inline int cqc2ChartForm(int b)
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
            return 7;
        case 9:
            return 8;
        case 10:
            return 9;
        case 11:
            return 10;
        case 12:
            return 9;
        case 13:
            return 11;
        case 14:
            return 12;
        case 15:
            return 13;
        case 16:
            return 14;
        case 17:
            return 13;
        case 18:
            return 15;
        case 19:
            return 16;
        case 20:
            return 0;
        case 21:
            return 9;
        case 22:
            return 17;
        case 23:
            return 18;
        case 24:
            return 19;
        case 25:
            return 20;
        case 26:
            return 19;
        case 27:
            return 21;
        case 28:
            return 21;
        case 29:
            return 21;
        case 30:
            return 21;
        case 31:
            return 21;
        case 32:
            return 21;
        case 33:
            return 21;
        case 34:
            return 21;
        default:
            return 0;
        }
    }

// The place-of-worship roster ordinals
inline int cqc2ChartPlace(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 0;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 4;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 5;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 6;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 7;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 8;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 9;
        case 28:
            return 10;
        case 29:
            return 11;
        case 30:
            return 12;
        case 31:
            return 13;
        case 32:
            return 14;
        case 33:
            return 15;
        case 34:
            return 15;
        default:
            return 0;
        }
    }

// ---- the parity pins ----

// the headline divergence: the print reads sky blue for the Hastur raiment
// color where the L&L transcription reads yellow-orange - pinned by print,
// eyeball flag
inline bool cqc2HasturSkyBluePrint()
    { return true; }

// the print spells the Ithaqua and Shub-Niggurath colors gray - the L&L voice
// reads grey, the print pinned
inline bool cqc2GraySpelledWithA()
    { return true; }

// the L&L <sea caves> gloss on the Cthulhu place of worship is a 5th-print
// addition, absent from the 2nd print - a noted divergence, not pinned
inline bool cqc2CthulhuPlaceNoGloss()
    { return true; }

// the chart print reads Cthuga where the deity write-up and the R856 walk pin
// Cthugha - the chart garble noted, the write-up spelling rides the roster
// row
inline bool cqc2ChartPrintsCthuga()
    { return true; }

// the rotated pass garbles the Huehueteotl and Tlazolteotl names with the !
// glyph standing in for tl - the L&L voice restores the names
inline bool cqc2TlGlyphGarbles()
    { return true; }

// the rotated pass merges the Fei Lien name (FeiLien) - the space restored
// from the L&L voice
inline bool cqc2FeiLienSpaceRestored()
    { return true; }

// the multi-word spheres read semicolons in print (bats; evil, life; love;
// water, gambling; chance) - the L&L voice agrees here, both voices pinned
inline bool cqc2SemicolonSpheres()
    { return true; }

// the Chinese pantheon rows carry no non-human clerics X
inline bool cqc2ChineseNoNonHuman()
    { return true; }

// every batch two row reads a male-clerics X
inline bool cqc2EveryRowMale()
    { return true; }

// every Cthulhu mythos row reads a non-human clerics X
inline bool cqc2CthulhuAllNonHuman()
    { return true; }

}   // namespace rules
