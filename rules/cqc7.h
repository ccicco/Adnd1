// =========================================================================================
// Adnd1 - rules/cqc7.h
// Appendix 3: the clerical quick-reference chart, batch seven - the D&DG walk
// round twenty-seven, print p. 142: the 24 rows of the Nonhumans' Deities
// across the 13 printed columns.
// census 797 -> 798.
//
// primary ink: the ROTATED extract/ddg tesseract pass (pNNN_rot_full.txt +
// pNNN_rot_tsv.tsv, pdf page 142; the second printing); the collation voice:
// the 1eonline L&L per-deity chart rows (the Demogorgon and Yeenoghu MM pages
// carry no chart row - those two rows ride the print alone). The
// adjudications: the whole batch reads the N-H-only flag (the geometry seats
// all 24 X marks at the N-H column, no M or F mark anywhere; the L&L voice
// agrees on all 22 covered rows); the Sekolah, Semuanya, Skoraeus Stonebones,
// Surtur, Thrym and Yeenoghu name garbles restored per the R864 crossref pins
// (the stray 4 glyph before Surtur noted); the Deep Sashelas seqa green
// garble restored to sea green (the R872 Poseidon class); the Grolantor daork
// brown and na garbles restored; the Garl warhelm and Gruumsh waorhelm folds
// restored to war helm; the Gruumsh body wrap black plate mail with its
// underscore and dash-pair strays noted; the Lolth stray i glyph and
// wrap-line dot noted; the Yondalla colon glyph noted (both voices carry it);
// the Demogorgon color reptile green and the ixitxachitl sphere restore ride
// the print. The batch order runs the alphabetical Nonhumans walk
// (Blibdoolpoolp through Yondalla).
//
namespace rules {

// ---- the batch seven census ----

// the clerical chart batch seven round: the D&DG walk round twenty-seven
inline int cqc7Round()
    { return 875; }

// the seventh chart batch (the App 3 box stays open until the last batch
// lands)
inline int cqc7Batch()
    { return 7; }

// the chart batch seven print page opens at 142
inline int cqc7PrintStart()
    { return 142; }

// the chart batch seven print page closes at 142
inline int cqc7PrintEnd()
    { return 142; }

// the batch rows (the twenty-four Nonhumans' Deities rows)
inline int cqc7Rows()
    { return 24; }

// the Nonhumans' Deities rows (the twenty mythos beings plus Demogorgon,
// Surtur, Thrym and Yeenoghu)
inline int cqc7NonhumanRows()
    { return 24; }

// the rows reading a male-clerics X (none - the batch reads no human-cleric
// marks)
inline int cqc7MaleRows()
    { return 0; }

// the rows reading a female-clerics X (none)
inline int cqc7FemaleRows()
    { return 0; }

// the rows reading a non-human clerics X (every row of the batch)
inline int cqc7NonHumanFlagRows()
    { return 24; }

// the printed columns of the chart (the 13 the batch grids encode)
inline int cqc7PrintedColumns()
    { return 13; }

// the sphere-of-control roster ordinals of the batch (one sphere per row)
inline int cqc7SphereCount()
    { return 24; }

// the animal roster ordinals of the batch (the n/a rows ride the roster)
inline int cqc7AnimalCount()
    { return 16; }

// the raiment head roster ordinals of the batch
inline int cqc7HeadCount()
    { return 11; }

// the raiment body roster ordinals of the batch
inline int cqc7BodyCount()
    { return 21; }

// the color roster ordinals of the batch (one color per row)
inline int cqc7ColorCount()
    { return 24; }

// the holy-days roster ordinals of the batch (the n/a rows ride the roster)
inline int cqc7HolyDayCount()
    { return 10; }

// the sacrifice-frequency roster ordinals of the batch
inline int cqc7FreqCount()
    { return 6; }

// the sacrifice-form roster ordinals of the batch
inline int cqc7FormCount()
    { return 15; }

// the place-of-worship roster ordinals of the batch
inline int cqc7PlaceCount()
    { return 15; }

// the batch grid count (one grid per batch round)
inline int cqc7TableCount()
    { return 1; }

// the batch chain count (the chart grids carry no chains)
inline int cqc7ChainCount()
    { return 0; }

// ---- the clerical chart batch seven grid ----

// The row ordinals (0-23, the batch walk order: the twenty-four Nonhumans
// rows)
inline int cqc7ChartOrd(int b)
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
        default:
            return 0;
        }
    }

// The sphere-of-control roster ordinals (the labels ride the data file; one
// sphere per row)
inline int cqc7ChartSphere(int b)
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
        default:
            return 0;
        }
    }

// The animal roster ordinals (the n/a rows ride the roster)
inline int cqc7ChartAnimal(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 3;
        case 5:
            return 1;
        case 6:
            return 4;
        case 7:
            return 5;
        case 8:
            return 1;
        case 9:
            return 6;
        case 10:
            return 7;
        case 11:
            return 8;
        case 12:
            return 1;
        case 13:
            return 1;
        case 14:
            return 9;
        case 15:
            return 10;
        case 16:
            return 11;
        case 17:
            return 1;
        case 18:
            return 12;
        case 19:
            return 13;
        case 20:
            return 14;
        case 21:
            return 1;
        case 22:
            return 1;
        case 23:
            return 15;
        default:
            return 0;
        }
    }

// The male clerics flag (the printed X reads 1; the batch reads no M marks)
inline int cqc7ChartM(int b)
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
            return 0;
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
            return 0;
        case 23:
            return 0;
        default:
            return 0;
        }
    }

// The female clerics flag (the printed X reads 1; the batch reads no F marks)
inline int cqc7ChartF(int b)
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
            return 0;
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
            return 0;
        case 23:
            return 0;
        default:
            return 0;
        }
    }

// The non-human clerics flag (the printed X reads 1; every row of the batch)
inline int cqc7ChartNh(int b)
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
        default:
            return 0;
        }
    }

// The raiment head roster ordinals
inline int cqc7ChartHead(int b)
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
            return 2;
        case 5:
            return 3;
        case 6:
            return 4;
        case 7:
            return 3;
        case 8:
            return 4;
        case 9:
            return 5;
        case 10:
            return 2;
        case 11:
            return 6;
        case 12:
            return 7;
        case 13:
            return 8;
        case 14:
            return 9;
        case 15:
            return 2;
        case 16:
            return 2;
        case 17:
            return 2;
        case 18:
            return 2;
        case 19:
            return 3;
        case 20:
            return 10;
        case 21:
            return 3;
        case 22:
            return 4;
        case 23:
            return 2;
        default:
            return 0;
        }
    }

// The raiment body roster ordinals (the wraps ride the roster labels)
inline int cqc7ChartBody(int b)
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
            return 8;
        case 13:
            return 11;
        case 14:
            return 12;
        case 15:
            return 3;
        case 16:
            return 13;
        case 17:
            return 14;
        case 18:
            return 15;
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
        default:
            return 0;
        }
    }

// The color roster ordinals (one color per row)
inline int cqc7ChartColor(int b)
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
        default:
            return 0;
        }
    }

// The holy-days roster ordinals (the n/a rows ride the roster)
inline int cqc7ChartHolyday(int b)
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
            return 0;
        case 6:
            return 3;
        case 7:
            return 0;
        case 8:
            return 4;
        case 9:
            return 5;
        case 10:
            return 6;
        case 11:
            return 4;
        case 12:
            return 0;
        case 13:
            return 5;
        case 14:
            return 7;
        case 15:
            return 2;
        case 16:
            return 4;
        case 17:
            return 4;
        case 18:
            return 3;
        case 19:
            return 8;
        case 20:
            return 6;
        case 21:
            return 3;
        case 22:
            return 1;
        case 23:
            return 9;
        default:
            return 0;
        }
    }

// The sacrifice-frequency roster ordinals
inline int cqc7ChartFreq(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 0;
        case 6:
            return 2;
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
            return 4;
        case 15:
            return 1;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 2;
        case 19:
            return 2;
        case 20:
            return 2;
        case 21:
            return 2;
        case 22:
            return 0;
        case 23:
            return 5;
        default:
            return 0;
        }
    }

// The sacrifice-form roster ordinals (the n/a rows ride the roster)
inline int cqc7ChartForm(int b)
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
            return 4;
        case 6:
            return 3;
        case 7:
            return 5;
        case 8:
            return 5;
        case 9:
            return 6;
        case 10:
            return 7;
        case 11:
            return 8;
        case 12:
            return 9;
        case 13:
            return 10;
        case 14:
            return 11;
        case 15:
            return 6;
        case 16:
            return 12;
        case 17:
            return 13;
        case 18:
            return 3;
        case 19:
            return 3;
        case 20:
            return 3;
        case 21:
            return 3;
        case 22:
            return 5;
        case 23:
            return 14;
        default:
            return 0;
        }
    }

// The place-of-worship roster ordinals (the wraps ride the roster labels)
inline int cqc7ChartPlace(int b)
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
            return 3;
        case 7:
            return 6;
        case 8:
            return 5;
        case 9:
            return 7;
        case 10:
            return 8;
        case 11:
            return 9;
        case 12:
            return 7;
        case 13:
            return 10;
        case 14:
            return 11;
        case 15:
            return 8;
        case 16:
            return 12;
        case 17:
            return 13;
        case 18:
            return 3;
        case 19:
            return 3;
        case 20:
            return 3;
        case 21:
            return 4;
        case 22:
            return 7;
        case 23:
            return 14;
        default:
            return 0;
        }
    }

// ---- the parity pins ----

// every row of the batch reads the N-H-only flag - the geometry seats all 24
// X marks at the N-H column (no M or F X anywhere) - the L&L voice agrees on
// all 22 covered rows
inline bool cqc7AllNonHumanOnly()
    { return true; }

// the Sekolah, Semuanya, Skoraeus Stonebones, Surtur, Thrym and Yeenoghu name
// garbles restored (the R864 crossref pins); the stray 4 glyph before the
// Surtur name noted
inline bool cqc7NameGarblesRestored()
    { return true; }

// the Deep Sashelas seqa green garble restored to sea green (the R872
// Poseidon seqa class)
inline bool cqc7SeqaGreenRestored()
    { return true; }

// the Grolantor daork brown garble restored to dark brown; the na frequency
// garble restored to n/a
inline bool cqc7GrolantorGarblesRestored()
    { return true; }

// the Garl warhelm and Gruumsh waorhelm folds restored to war helm (the R874
// red studded class)
inline bool cqc7WarHelmFolds()
    { return true; }

// the Gruumsh body wraps to black plate mail; the underscore glyph at the
// name and the dash pair on the wrap line noted (print artifacts, not ink)
inline bool cqc7GruumshStrays()
    { return true; }

// the Lolth name stray i glyph and the stray dot on the red and black wrap
// line noted (print artifacts, not ink)
inline bool cqc7LolthStrays()
    { return true; }

// the colon glyph before the Yondalla dove noted - both voices carry it (a
// shared artifact, not a field)
inline bool cqc7YondallaColonGlyph()
    { return true; }

// the Demogorgon and Yeenoghu rows ride the print voice alone (the L&L MM
// pages carry no chart row); the Demogorgon color reptile green and the
// ixitxachitl sphere garble restored ride the print
inline bool cqc7DemogorgonPrintOnly()
    { return true; }

// the male and female cleric columns read zero X marks across the whole batch
// (the nonhuman deities take nonhuman clerics only)
inline bool cqc7NoHumanClerics()
    { return true; }

}   // namespace rules
