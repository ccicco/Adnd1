// =========================================================================================
// Adnd1 - rules/cqc5.h
// Appendix 3: the clerical quick-reference chart, batch five - the D&DG walk
// round twenty-five, print pp. 140-141: the 25 rows of the Japanese and
// Melnibonean pantheons across the 13 printed columns.
// census 795 -> 796.
//
// primary ink: the ROTATED extract/ddg tesseract pass (pNNN_rot_full.txt +
// pNNN_rot_tsv.tsv, pdf pages 140-141; the second printing) - the Arioch row
// rides the pdf 140 tail, the rest of the Melnibonean block rides pdf 141;
// the collation voice: the 1eonline L&L per-deity chart rows (the
// nnkuuurrrrcc and nuruah slugs run flat; the Tsukiyomi page header reads
// Sphere of Worship, the odd one). The adjudications: the Ama-Tsu-Mara
// metalwork + hearth pin (print over the L&L precious metalwork + temple,
// eyeball flag), the Daikoku wealth; luck sphere restored (the raunchiest
// garble of the rotated pass) with the name restored to the R861 Daikoku pin,
// the ten N-H-only Melnibonean rows (the geometry seats every single X at the
// N-H column; the L&L voice agrees), the Haaashastaak animal lizard, dinosaur
// pinned (the L&L shifts the columns), the L&L [swan]/[tiger]/[whale]
// brackets noted as gloss markers, the Hachiman equinox and Ebisu brown robes
// folds restored, and the Roofdrak and Grome stray glyphs noted. The batch
// order runs Japanese, Melnibonean.
//
namespace rules {

// ---- the batch five census ----

// the clerical chart batch five round: the D&DG walk round twenty-five
inline int cqc5Round()
    { return 873; }

// the fifth chart batch (the App 3 box stays open until the last batch lands)
inline int cqc5Batch()
    { return 5; }

// the chart batch five print pages open at 140
inline int cqc5PrintStart()
    { return 140; }

// the chart batch five print pages close at 141
inline int cqc5PrintEnd()
    { return 141; }

// the batch rows (Japanese 10, Melnibonean 15)
inline int cqc5Rows()
    { return 25; }

// the Japanese pantheon rows
inline int cqc5JapaneseRows()
    { return 10; }

// the Melnibonean mythos rows
inline int cqc5MelniboneanRows()
    { return 15; }

// the rows reading a male-clerics X (the ten Japanese rows and five
// Melnibonean)
inline int cqc5MaleRows()
    { return 15; }

// the rows reading a female-clerics X (Hachiman and the ten N-H-only
// Melnibonean rows without)
inline int cqc5FemaleRows()
    { return 13; }

// the rows reading a non-human clerics X (every Melnibonean row; the Japanese
// rows read none)
inline int cqc5NonHumanRows()
    { return 15; }

// the printed columns of the chart (the 13 the batch grids encode)
inline int cqc5PrintedColumns()
    { return 13; }

// the sphere-of-control roster ordinals of the batch
inline int cqc5SphereCount()
    { return 24; }

// the animal roster ordinals of the batch (the n/a rows ride the roster)
inline int cqc5AnimalCount()
    { return 18; }

// the raiment head roster ordinals of the batch (the n/a rows ride the
// roster)
inline int cqc5HeadCount()
    { return 8; }

// the raiment body roster ordinals of the batch (the n/a rows ride the
// roster)
inline int cqc5BodyCount()
    { return 14; }

// the color roster ordinals of the batch
inline int cqc5ColorCount()
    { return 22; }

// the holy-days roster ordinals of the batch (the n/a rows ride the roster)
inline int cqc5HolyDayCount()
    { return 9; }

// the sacrifice-frequency roster ordinals of the batch
inline int cqc5FreqCount()
    { return 5; }

// the sacrifice-form roster ordinals of the batch
inline int cqc5FormCount()
    { return 14; }

// the place-of-worship roster ordinals of the batch
inline int cqc5PlaceCount()
    { return 4; }

// the batch grid count (one grid per batch round)
inline int cqc5TableCount()
    { return 1; }

// the batch chain count (the chart grids carry no chains)
inline int cqc5ChainCount()
    { return 0; }

// ---- the clerical chart batch five grid ----

// The row ordinals (0-24, the batch walk order: Japanese 0-9, Melnibonean
// 10-24)
inline int cqc5ChartOrd(int b)
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
        default:
            return 0;
        }
    }

// The sphere-of-control roster ordinals (the labels ride the data file)
inline int cqc5ChartSphere(int b)
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
            return 10;
        default:
            return 0;
        }
    }

// The animal roster ordinals (the n/a rows ride the roster)
inline int cqc5ChartAnimal(int b)
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
            return 10;
        case 12:
            return 11;
        case 13:
            return 12;
        case 14:
            return 10;
        case 15:
            return 13;
        case 16:
            return 10;
        case 17:
            return 6;
        case 18:
            return 10;
        case 19:
            return 14;
        case 20:
            return 15;
        case 21:
            return 16;
        case 22:
            return 17;
        case 23:
            return 10;
        case 24:
            return 10;
        default:
            return 0;
        }
    }

// The male clerics flag (the printed X reads 1)
inline int cqc5ChartM(int b)
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
            return 1;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 1;
        default:
            return 0;
        }
    }

// The female clerics flag (the printed X reads 1; Hachiman the only Japanese
// row without)
inline int cqc5ChartF(int b)
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
            return 0;
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
            return 0;
        case 12:
            return 1;
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
            return 1;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 1;
        default:
            return 0;
        }
    }

// The non-human clerics flag (the printed X reads 1; the Ama-Tsu-Mara hearth
// is the round divergence pin)
inline int cqc5ChartNh(int b)
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
        default:
            return 0;
        }
    }

// The raiment head roster ordinals (the n/a rows ride the roster)
inline int cqc5ChartHead(int b)
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
            return 0;
        case 6:
            return 0;
        case 7:
            return 4;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 5;
        case 12:
            return 6;
        case 13:
            return 7;
        case 14:
            return 7;
        case 15:
            return 7;
        case 16:
            return 7;
        case 17:
            return 7;
        case 18:
            return 7;
        case 19:
            return 7;
        case 20:
            return 7;
        case 21:
            return 7;
        case 22:
            return 7;
        case 23:
            return 7;
        case 24:
            return 7;
        default:
            return 0;
        }
    }

// The raiment body roster ordinals (the n/a rows ride the roster)
inline int cqc5ChartBody(int b)
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
            return 13;
        case 15:
            return 13;
        case 16:
            return 13;
        case 17:
            return 13;
        case 18:
            return 13;
        case 19:
            return 13;
        case 20:
            return 13;
        case 21:
            return 13;
        case 22:
            return 13;
        case 23:
            return 13;
        case 24:
            return 13;
        default:
            return 0;
        }
    }

// The color roster ordinals
inline int cqc5ChartColor(int b)
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
            return 1;
        case 12:
            return 0;
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
            return 6;
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
        default:
            return 0;
        }
    }

// The holy-days roster ordinals (the n/a rows ride the roster)
inline int cqc5ChartHolyday(int b)
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
            return 0;
        case 8:
            return 5;
        case 9:
            return 6;
        case 10:
            return 1;
        case 11:
            return 7;
        case 12:
            return 8;
        case 13:
            return 4;
        case 14:
            return 4;
        case 15:
            return 4;
        case 16:
            return 4;
        case 17:
            return 4;
        case 18:
            return 4;
        case 19:
            return 4;
        case 20:
            return 4;
        case 21:
            return 4;
        case 22:
            return 4;
        case 23:
            return 4;
        case 24:
            return 4;
        default:
            return 0;
        }
    }

// The sacrifice-frequency roster ordinals
inline int cqc5ChartFreq(int b)
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
            return 2;
        case 7:
            return 0;
        case 8:
            return 3;
        case 9:
            return 3;
        case 10:
            return 0;
        case 11:
            return 3;
        case 12:
            return 4;
        case 13:
            return 4;
        case 14:
            return 4;
        case 15:
            return 4;
        case 16:
            return 4;
        case 17:
            return 4;
        case 18:
            return 4;
        case 19:
            return 4;
        case 20:
            return 4;
        case 21:
            return 4;
        case 22:
            return 4;
        case 23:
            return 4;
        case 24:
            return 4;
        default:
            return 0;
        }
    }

// The sacrifice-form roster ordinals
inline int cqc5ChartForm(int b)
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
            return 13;
        case 15:
            return 13;
        case 16:
            return 13;
        case 17:
            return 13;
        case 18:
            return 13;
        case 19:
            return 13;
        case 20:
            return 13;
        case 21:
            return 10;
        case 22:
            return 13;
        case 23:
            return 13;
        case 24:
            return 10;
        default:
            return 0;
        }
    }

// The place-of-worship roster ordinals
inline int cqc5ChartPlace(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
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
            return 2;
        case 11:
            return 3;
        case 12:
            return 2;
        case 13:
            return 2;
        case 14:
            return 2;
        case 15:
            return 2;
        case 16:
            return 2;
        case 17:
            return 2;
        case 18:
            return 2;
        case 19:
            return 2;
        case 20:
            return 2;
        case 21:
            return 2;
        case 22:
            return 2;
        case 23:
            return 2;
        case 24:
            return 2;
        default:
            return 0;
        }
    }

// ---- the parity pins ----

// the headline divergence: the print reads the Ama-Tsu-Mara form metalwork
// and place hearth where the L&L voice reads precious metalwork and temple -
// pinned by print, eyeball flag
inline bool cqc5AmaTsuMaraHearthPrint()
    { return true; }

// the print garbles the Daikoku sphere (the wealth; fuck glyph run) -
// restored to wealth; luck from the L&L voice; the Daikoky name garble
// restored to the R861 Daikoku pin
inline bool cqc5DaikokuLuckRestored()
    { return true; }

// ten of the fifteen Melnibonean rows read an N-H-only flag - the TSV
// geometry seats every single X at x 1144-1152, the N-H column, and the L&L
// voice agrees
inline bool cqc5MelniboneanNonHumanOnly()
    { return true; }

// the print reads the Haaashastaak sphere reptiles and animal lizard,
// dinosaur - the L&L voice shifts (sphere reptiles, dinosaurs, animal n/a) -
// the print pinned
inline bool cqc5HaaashastaakAnimalPrint()
    { return true; }

// the L&L Tsukiyomi page header reads Sphere of Worship (the odd one of the
// chart pages) - the row itself agrees with the print
inline bool cqc5TsukiyomiAlternateHeader()
    { return true; }

// the L&L [swan], [tiger] and [whale] brackets are gloss markers, not print
// ink - the plain print animals pinned
inline bool cqc5BracketGlossesNoted()
    { return true; }

// the Hachiman equirox garble restored to fall equinox; the Ebisu brownrobes
// fold restored to brown robes
inline bool cqc5EquinoxFoldRestored()
    { return true; }

// the stray glyph on the Roofdrak row (the double-arrow after the dog) noted
// - a print artifact, not ink
inline bool cqc5RoofdrakStrayGlyph()
    { return true; }

// the stray apostrophe before the Grome n/a noted - a print artifact, not ink
inline bool cqc5GromeStrayApostrophe()
    { return true; }

// the Japanese rows carry no non-human clerics X
inline bool cqc5JapaneseNoNonHuman()
    { return true; }

}   // namespace rules
