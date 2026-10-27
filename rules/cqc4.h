// =========================================================================================
// Adnd1 - rules/cqc4.h
// Appendix 3: the clerical quick-reference chart, batch four - the D&DG walk
// round twenty-four, print pp. 139-140: the 31 rows of the Greek and Indian
// pantheons across the 13 printed columns.
// census 794 -> 795.
//
// primary ink: the ROTATED extract/ddg tesseract pass (pNNN_rot_full.txt +
// pNNN_rot_tsv.tsv, pdf pages 139-140; the second printing) - the Greek block
// sits below the R871 Finnish tail on pdf 139, the Indian block spans the pdf
// 139 tail and the pdf 140 head; the collation voice: the 1eonline L&L
// per-deity chart rows (the zeus and aphrodite slugs plain). The
// adjudications: the Aphrodite X pair (print over the L&L female-only read,
// eyeball flag, the Druaga precedent), the Zeus white / red sunrise column
// split (both voices agree - an eyeball oddity), the Poseidon seqa garble
// restored to sea; earthquakes from L&L, the Apollo laure! garble restored to
// laurel wreath, the Indra rainbow pinned plain (the L&L <> glyph an
// artifact), the Yama no-article form pinned (the L&L a noted) with the stray
// colon glyph noted, the Ushas at-dawn fold restored (the Arawn class), and
// the Rudra red, black comma pinned. The batch order runs Greek, Indian.
//
namespace rules {

// ---- the batch four census ----

// the clerical chart batch four round: the D&DG walk round twenty-four
inline int cqc4Round()
    { return 872; }

// the fourth chart batch (the App 3 box stays open until the last batch
// lands)
inline int cqc4Batch()
    { return 4; }

// the chart batch four print pages open at 139
inline int cqc4PrintStart()
    { return 139; }

// the chart batch four print pages close at 140
inline int cqc4PrintEnd()
    { return 140; }

// the batch rows (Greek 18, Indian 13)
inline int cqc4Rows()
    { return 31; }

// the Greek pantheon rows
inline int cqc4GreekRows()
    { return 18; }

// the Indian pantheon rows
inline int cqc4IndianRows()
    { return 13; }

// the rows reading a male-clerics X (Artemis and Ushas the rows without)
inline int cqc4MaleRows()
    { return 29; }

// the rows reading a female-clerics X (Apollo, Pan, Indra, Karttikeya and
// Yama the rows without)
inline int cqc4FemaleRows()
    { return 26; }

// the rows reading a non-human clerics X (5 Greek, 4 Indian)
inline int cqc4NonHumanRows()
    { return 9; }

// the printed columns of the chart (the 13 the batch grids encode)
inline int cqc4PrintedColumns()
    { return 13; }

// the sphere-of-control roster ordinals of the batch
inline int cqc4SphereCount()
    { return 30; }

// the animal roster ordinals of the batch
inline int cqc4AnimalCount()
    { return 29; }

// the raiment head roster ordinals of the batch
inline int cqc4HeadCount()
    { return 9; }

// the raiment body roster ordinals of the batch
inline int cqc4BodyCount()
    { return 18; }

// the color roster ordinals of the batch
inline int cqc4ColorCount()
    { return 24; }

// the holy-days roster ordinals of the batch
inline int cqc4HolyDayCount()
    { return 13; }

// the sacrifice-frequency roster ordinals of the batch
inline int cqc4FreqCount()
    { return 15; }

// the sacrifice-form roster ordinals of the batch
inline int cqc4FormCount()
    { return 23; }

// the place-of-worship roster ordinals of the batch
inline int cqc4PlaceCount()
    { return 17; }

// the batch grid count (one grid per batch round)
inline int cqc4TableCount()
    { return 1; }

// the batch chain count (the chart grids carry no chains)
inline int cqc4ChainCount()
    { return 0; }

// ---- the clerical chart batch four grid ----

// The row ordinals (0-30, the batch walk order: Greek 0-17, Indian 18-30)
inline int cqc4ChartOrd(int b)
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
        default:
            return 0;
        }
    }

// The sphere-of-control roster ordinals (the labels ride the data file)
inline int cqc4ChartSphere(int b)
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
            return 3;
        case 22:
            return 21;
        case 23:
            return 22;
        case 24:
            return 23;
        case 25:
            return 24;
        case 26:
            return 25;
        case 27:
            return 26;
        case 28:
            return 27;
        case 29:
            return 28;
        case 30:
            return 29;
        default:
            return 0;
        }
    }

// The animal roster ordinals
inline int cqc4ChartAnimal(int b)
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
            return 11;
        case 22:
            return 21;
        case 23:
            return 22;
        case 24:
            return 23;
        case 25:
            return 13;
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
        default:
            return 0;
        }
    }

// The male clerics flag (the printed X reads 1; Artemis and Ushas the rows
// without)
inline int cqc4ChartM(int b)
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
            return 0;
        case 28:
            return 1;
        case 29:
            return 1;
        case 30:
            return 1;
        default:
            return 0;
        }
    }

// The female clerics flag (the printed X reads 1; the Aphrodite X pair is the
// round divergence pin)
inline int cqc4ChartF(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 0;
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
            return 1;
        case 21:
            return 0;
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
            return 0;
        default:
            return 0;
        }
    }

// The non-human clerics flag (the printed X reads 1)
inline int cqc4ChartNh(int b)
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
            return 0;
        case 8:
            return 1;
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
            return 1;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 1;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 1;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 1;
        case 27:
            return 0;
        case 28:
            return 0;
        case 29:
            return 1;
        case 30:
            return 0;
        default:
            return 0;
        }
    }

// The raiment head roster ordinals
inline int cqc4ChartHead(int b)
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
            return 0;
        case 5:
            return 2;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 2;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 3;
        case 13:
            return 4;
        case 14:
            return 5;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 6;
        case 19:
            return 6;
        case 20:
            return 6;
        case 21:
            return 6;
        case 22:
            return 6;
        case 23:
            return 6;
        case 24:
            return 7;
        case 25:
            return 6;
        case 26:
            return 6;
        case 27:
            return 8;
        case 28:
            return 6;
        case 29:
            return 6;
        case 30:
            return 6;
        default:
            return 0;
        }
    }

// The raiment body roster ordinals
inline int cqc4ChartBody(int b)
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
            return 2;
        case 5:
            return 3;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 4;
        case 9:
            return 0;
        case 10:
            return 5;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 6;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 0;
        case 18:
            return 7;
        case 19:
            return 8;
        case 20:
            return 9;
        case 21:
            return 10;
        case 22:
            return 11;
        case 23:
            return 12;
        case 24:
            return 13;
        case 25:
            return 13;
        case 26:
            return 14;
        case 27:
            return 11;
        case 28:
            return 15;
        case 29:
            return 16;
        case 30:
            return 17;
        default:
            return 0;
        }
    }

// The color roster ordinals (the Zeus white / red sunrise split is the
// eyeball oddity pin)
inline int cqc4ChartColor(int b)
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
            return 8;
        case 21:
            return 17;
        case 22:
            return 2;
        case 23:
            return 20;
        case 24:
            return 21;
        case 25:
            return 13;
        case 26:
            return 6;
        case 27:
            return 22;
        case 28:
            return 0;
        case 29:
            return 12;
        case 30:
            return 23;
        default:
            return 0;
        }
    }

// The holy-days roster ordinals
inline int cqc4ChartHolyday(int b)
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
            return 6;
        case 8:
            return 5;
        case 9:
            return 7;
        case 10:
            return 5;
        case 11:
            return 8;
        case 12:
            return 5;
        case 13:
            return 9;
        case 14:
            return 6;
        case 15:
            return 5;
        case 16:
            return 4;
        case 17:
            return 5;
        case 18:
            return 5;
        case 19:
            return 5;
        case 20:
            return 5;
        case 21:
            return 10;
        case 22:
            return 5;
        case 23:
            return 11;
        case 24:
            return 5;
        case 25:
            return 12;
        case 26:
            return 5;
        case 27:
            return 5;
        case 28:
            return 8;
        case 29:
            return 11;
        case 30:
            return 5;
        default:
            return 0;
        }
    }

// The sacrifice-frequency roster ordinals (the Ushas at-dawn fold restored)
inline int cqc4ChartFreq(int b)
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
            return 0;
        case 5:
            return 2;
        case 6:
            return 4;
        case 7:
            return 4;
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
            return 4;
        case 15:
            return 7;
        case 16:
            return 11;
        case 17:
            return 7;
        case 18:
            return 8;
        case 19:
            return 8;
        case 20:
            return 12;
        case 21:
            return 13;
        case 22:
            return 8;
        case 23:
            return 8;
        case 24:
            return 5;
        case 25:
            return 4;
        case 26:
            return 8;
        case 27:
            return 14;
        case 28:
            return 8;
        case 29:
            return 8;
        case 30:
            return 5;
        default:
            return 0;
        }
    }

// The sacrifice-form roster ordinals
inline int cqc4ChartForm(int b)
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
            return 0;
        case 6:
            return 5;
        case 7:
            return 6;
        case 8:
            return 2;
        case 9:
            return 3;
        case 10:
            return 7;
        case 11:
            return 8;
        case 12:
            return 9;
        case 13:
            return 3;
        case 14:
            return 10;
        case 15:
            return 11;
        case 16:
            return 12;
        case 17:
            return 6;
        case 18:
            return 2;
        case 19:
            return 13;
        case 20:
            return 14;
        case 21:
            return 15;
        case 22:
            return 16;
        case 23:
            return 17;
        case 24:
            return 2;
        case 25:
            return 18;
        case 26:
            return 19;
        case 27:
            return 20;
        case 28:
            return 2;
        case 29:
            return 21;
        case 30:
            return 22;
        default:
            return 0;
        }
    }

// The place-of-worship roster ordinals
inline int cqc4ChartPlace(int b)
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
            return 1;
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
            return 1;
        case 12:
            return 10;
        case 13:
            return 1;
        case 14:
            return 4;
        case 15:
            return 1;
        case 16:
            return 11;
        case 17:
            return 6;
        case 18:
            return 1;
        case 19:
            return 1;
        case 20:
            return 12;
        case 21:
            return 13;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 14;
        case 25:
            return 1;
        case 26:
            return 15;
        case 27:
            return 1;
        case 28:
            return 1;
        case 29:
            return 1;
        case 30:
            return 16;
        default:
            return 0;
        }
    }

// ---- the parity pins ----

// the headline divergence: the print reads two X marks for Aphrodite (M and
// F, the geometry at x 1049/1104) where the L&L voice reads female-only -
// pinned by print, eyeball flag (the Druaga precedent)
inline bool cqc4AphroditeMaleClericsPrint()
    { return true; }

// the print reads the Zeus color white and the holy days red sunrise (the odd
// column split both voices carry) - pinned, eyeball oddity
inline bool cqc4ZeusRedSunrise()
    { return true; }

// the print garbles the Poseidon sphere (seqa;) - restored to sea;
// earthquakes from the L&L voice (the sea/seas ambiguity rides the
// restoration)
inline bool cqc4PoseidonSphereRestored()
    { return true; }

// the print garbles the Apollo head (the laure! glyph run) - the laurel
// wreath restored from the L&L voice
inline bool cqc4ApolloLaurelRestored()
    { return true; }

// the L&L rainbow <> gloss glyph on the Indra color is an artifact - the
// print reads the plain rainbow, pinned
inline bool cqc4IndraRainbowNoGlyph()
    { return true; }

// the print reads the Yama form tales of dead one's deeds, valuables (no
// article) where the L&L voice inserts a - pinned by print
inline bool cqc4YamaTalesNoArticle()
    { return true; }

// the stray : glyph in the Yama raiment fold is a print artifact, not ink -
// noted, the red robes with copper tracery restored
inline bool cqc4YamaStrayColon()
    { return true; }

// the Ushas atdawn fold merged (the Arawn at death and Hades atdeath fold
// class) - the monthly, at dawn frequency restored
inline bool cqc4AtDawnFoldRestored()
    { return true; }

// the print reads the Rudra color red, black (with the comma) - the L&L red
// black noted, the print pinned
inline bool cqc4RudraRedBlackComma()
    { return true; }

// the batch four female-only rows run Artemis and Ushas
inline bool cqc4TwoFemaleOnlyRows()
    { return true; }

}   // namespace rules
