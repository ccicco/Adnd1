// =========================================================================================
// Adnd1 - rules/cqc.h
// Appendix 3: the clerical quick-reference chart, batch one - the D&DG walk
// round twenty-one, print pp. 134-135: the chart doctrine (alphabetical
// within pantheon, most important first, guidelines only), the legend
// definitions, and the 29 rows of the American Indian, Babylonian and Celtic
// pantheons across the 13 printed columns.
// census 791 -> 792.
//
// primary ink: the ROTATED extract/ddg tesseract pass (pNNN_rot_full.txt +
// pNNN_rot_tsv.tsv, pages 135-136; the second printing) - the chart prints
// landscape, the pass rides a PIL rotate(-90) over the pg renders (pdftoppm
// -r 300), committed c7ced34/97fcaac/06c35eb after two zero-byte strays (the
// tesseract .txt-append trap - stdout redirect is the fix); the collation
// voice: the 1eonline L&L per-deity chart rows (the mml.htm slug for Manannan
// Mac Lir). The adjudications: the Druaga female-clerics X (print over L&L
// male-only, eyeball flag), the sphere semicolons pinned by print (Heng,
// Hotoru, Ishtar, Marduk, Brigit), the Hastsezini jade green (the jode
// garble, L&L), the Arawn at death frequency (the fold), the Lugh Ltugh
// garble, and the Silvanus stray quote glyph noted. The chart carries no
// Arthurian block (heroes only).
//
namespace rules {

// ---- the chart doctrine ----

// the clerical chart batch one round: the D&DG walk round twenty-one
inline int cqcRound()
    { return 869; }

// the first chart batch (the App 3 box stays open until the last batch lands)
inline int cqcBatch()
    { return 1; }

// the print folio where the chart begins (pdf p. 135)
inline int cqcPrintStart()
    { return 134; }

// the print folio where batch one ends (pdf p. 136)
inline int cqcPrintEnd()
    { return 135; }

// the listing is provided for quick reference when specific information about
// a cleric religion is needed
inline bool cqcQuickReferencePurpose()
    { return true; }

// deities are arranged alphabetically within their pantheon, except that the
// most important deity is listed first
inline bool cqcAlphabeticalWithinPantheon()
    { return true; }

// the information presented is to be used as guidelines only - all clerics of
// one deity will not necessarily dress identically
inline bool cqcGuidelinesOnly()
    { return true; }

// rank within the temple is often differentiated by variations in color,
// lining or stripes
inline bool cqcRankByColor()
    { return true; }

// special sacrifices and holy days may be ordained at any time, at the
// pleasure of the temple or its deity
inline bool cqcOrdainedAnytime()
    { return true; }

// the sphere of control is the item, condition or element over which the
// deity exerts some measure of control (e.g. Air, Rain, The Hunt, Affairs of
// the Heart)
inline bool cqcSphereMeaning()
    { return true; }

// the animal is the one most commonly associated with or sacred to that
// deity; clerics of the deity will often protect this type of animal; some
// deities are not associated with an animal
inline bool cqcAnimalMeaning()
    { return true; }

// the clerics column describes whether the clerics of this deity can be male
// (M), female (F), or non-human (N-H)
inline bool cqcClericsMeaning()
    { return true; }

// raiment is the prescribed form of adornment for a cleric of the deity
// (robes, headdresses, hairstyles, tattoos, makeup, physical disfigurations,
// ornaments, jewelry, footwear)
inline bool cqcRaimentMeaning()
    { return true; }

// the colors column lists the colors, if any, associated with the deity or
// its clerics (ceremonial robes, altar drapings, candles, holy banners)
inline bool cqcColorsMeaning()
    { return true; }

// the holy days listing gives the highest holy days associated with the deity
// and its worshipers; sacrifices, rituals and prayers on these days are more
// likely to be heard and acknowledged
inline bool cqcHolyDaysMeaning()
    { return true; }

// acknowledgement is not the same thing as granting a prayer or request
inline bool cqcAcknowledgementNotGranting()
    { return true; }

// the sacrifice column lists both the frequency and the form of sacrifices
// expected of the worshipers of this deity, plus the grateful, repentant and
// begging-a-favor offerings
inline bool cqcSacrificeMeaning()
    { return true; }

// the place of worship gives the most common locale or construction, whether
// natural or man-made, in which clerics of the deity gather to worship that
// deity
inline bool cqcPlaceMeaning()
    { return true; }

// ---- the batch one census ----

// the batch one deity rows (American Indian 9, Babylonian 8, Celtic 12)
inline int cqcRows()
    { return 29; }

// the American Indian rows (Raven, Coyote, Hastseltsi, Hastsezini, Heng,
// Hotoru, Shakak, Snake-Man, Tobadzistsini)
inline int cqcAIRows()
    { return 9; }

// the Babylonian rows (Anu, Anshar, Druaga, Girru, Ishtar, Marduk, Nergal,
// Ramman)
inline int cqcBabRows()
    { return 8; }

// the Celtic rows (Dagda, Arawn, Brigit, Diancecht, Dunatis, Goibhnie, Lugh,
// Manannan Mac Lir, Morrigan, Nuada, Oghma, Silvanus)
inline int cqcCelRows()
    { return 12; }

// the rows printing a male-clerics X (every row of the batch)
inline int cqcMaleRows()
    { return 29; }

// the rows printing a female-clerics X (all but Dagda and Arawn)
inline int cqcFemaleRows()
    { return 27; }

// the rows printing a non-human-clerics X (Snake-Man, Nergal, Diancecht,
// Goibhnie, Lugh, Silvanus)
inline int cqcNonHumanRows()
    { return 6; }

// the rows printing n/a for the animal (every Celtic row)
inline int cqcNoAnimalRows()
    { return 12; }

// the printed chart columns (deity, sphere of control, animal, M, F, N-H,
// head, body, colors, holy days, frequency, form, place of worship)
inline int cqcPrintedColumns()
    { return 13; }

// the sphere-of-control roster labels
inline int cqcSphereCount()
    { return 25; }

// the animal roster labels
inline int cqcAnimalCount()
    { return 16; }

// the raiment head roster labels
inline int cqcHeadCount()
    { return 9; }

// the raiment body roster labels
inline int cqcBodyCount()
    { return 15; }

// the color roster labels
inline int cqcColorCount()
    { return 23; }

// the holy-days roster labels
inline int cqcHolyDayCount()
    { return 8; }

// the sacrifice-frequency roster labels
inline int cqcFreqCount()
    { return 7; }

// the sacrifice-form roster labels
inline int cqcFormCount()
    { return 21; }

// the place-of-worship roster labels
inline int cqcPlaceCount()
    { return 15; }

// the R869 grid count
inline int cqcTableCount()
    { return 1; }

// the R869 chain count
inline int cqcChainCount()
    { return 0; }

// ---- the clerical chart batch one grid ----

// The row ordinals (0-28, the batch walk order: American Indian 0-8,
// Babylonian 9-16, Celtic 17-28)
inline int cqcChartOrd(int b)
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
        default:
            return 0;
        }
    }

// The sphere-of-control roster ordinals (the labels ride the data file)
inline int cqcChartSphere(int b)
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
            return 3;
        case 13:
            return 12;
        case 14:
            return 13;
        case 15:
            return 14;
        case 16:
            return 15;
        case 17:
            return 16;
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
            return 8;
        case 26:
            return 8;
        case 27:
            return 1;
        case 28:
            return 24;
        default:
            return 0;
        }
    }

// The animal roster ordinals (the n/a rows read 12)
inline int cqcChartAnimal(int b)
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
            return 3;
        case 8:
            return 7;
        case 9:
            return 8;
        case 10:
            return 0;
        case 11:
            return 9;
        case 12:
            return 10;
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
            return 15;
        case 19:
            return 15;
        case 20:
            return 15;
        case 21:
            return 15;
        case 22:
            return 15;
        case 23:
            return 15;
        case 24:
            return 15;
        case 25:
            return 15;
        case 26:
            return 15;
        case 27:
            return 15;
        case 28:
            return 15;
        default:
            return 0;
        }
    }

// The male clerics flag (the printed X reads 1)
inline int cqcChartM(int b)
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
        default:
            return 0;
        }
    }

// The female clerics flag (the printed X reads 1; the Druaga X is the round
// divergence pin)
inline int cqcChartF(int b)
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
            return 0;
        case 18:
            return 0;
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
        default:
            return 0;
        }
    }

// The non-human clerics flag (the printed X reads 1)
inline int cqcChartNh(int b)
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
            return 1;
        case 23:
            return 1;
        case 24:
            return 0;
        case 25:
            return 0;
        case 26:
            return 0;
        case 27:
            return 0;
        case 28:
            return 1;
        default:
            return 0;
        }
    }

// The raiment head roster ordinals
inline int cqcChartHead(int b)
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
            return 1;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 3;
        case 10:
            return 4;
        case 11:
            return 4;
        case 12:
            return 4;
        case 13:
            return 5;
        case 14:
            return 4;
        case 15:
            return 4;
        case 16:
            return 4;
        case 17:
            return 6;
        case 18:
            return 7;
        case 19:
            return 7;
        case 20:
            return 0;
        case 21:
            return 8;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 7;
        case 25:
            return 7;
        case 26:
            return 7;
        case 27:
            return 0;
        case 28:
            return 0;
        default:
            return 0;
        }
    }

// The raiment body roster ordinals
inline int cqcChartBody(int b)
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
            return 5;
        case 7:
            return 0;
        case 8:
            return 6;
        case 9:
            return 7;
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
            return 12;
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
            return 13;
        case 22:
            return 7;
        case 23:
            return 7;
        case 24:
            return 7;
        case 25:
            return 14;
        case 26:
            return 14;
        case 27:
            return 7;
        case 28:
            return 7;
        default:
            return 0;
        }
    }

// The color roster ordinals
inline int cqcChartColor(int b)
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
            return 4;
        case 17:
            return 15;
        case 18:
            return 0;
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
            return 7;
        case 25:
            return 21;
        case 26:
            return 22;
        case 27:
            return 5;
        case 28:
            return 13;
        default:
            return 0;
        }
    }

// The holy-days roster ordinals
inline int cqcChartHolyday(int b)
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
            return 2;
        case 6:
            return 3;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 4;
        case 10:
            return 3;
        case 11:
            return 4;
        case 12:
            return 5;
        case 13:
            return 6;
        case 14:
            return 7;
        case 15:
            return 6;
        case 16:
            return 4;
        case 17:
            return 6;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 6;
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
        case 28:
            return 5;
        default:
            return 0;
        }
    }

// The sacrifice-frequency roster ordinals
inline int cqcChartFreq(int b)
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
            return 1;
        case 7:
            return 0;
        case 8:
            return 0;
        case 9:
            return 2;
        case 10:
            return 3;
        case 11:
            return 2;
        case 12:
            return 4;
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
            return 5;
        case 19:
            return 6;
        case 20:
            return 2;
        case 21:
            return 0;
        case 22:
            return 0;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 6;
        case 26:
            return 6;
        case 27:
            return 0;
        case 28:
            return 0;
        default:
            return 0;
        }
    }

// The sacrifice-form roster ordinals
inline int cqcChartForm(int b)
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
            return 0;
        case 5:
            return 2;
        case 6:
            return 0;
        case 7:
            return 3;
        case 8:
            return 4;
        case 9:
            return 5;
        case 10:
            return 6;
        case 11:
            return 7;
        case 12:
            return 6;
        case 13:
            return 8;
        case 14:
            return 9;
        case 15:
            return 10;
        case 16:
            return 11;
        case 17:
            return 12;
        case 18:
            return 13;
        case 19:
            return 14;
        case 20:
            return 15;
        case 21:
            return 6;
        case 22:
            return 8;
        case 23:
            return 12;
        case 24:
            return 16;
        case 25:
            return 17;
        case 26:
            return 18;
        case 27:
            return 19;
        case 28:
            return 20;
        default:
            return 0;
        }
    }

// The place-of-worship roster ordinals
inline int cqcChartPlace(int b)
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
            return 3;
        case 7:
            return 0;
        case 8:
            return 2;
        case 9:
            return 4;
        case 10:
            return 4;
        case 11:
            return 4;
        case 12:
            return 4;
        case 13:
            return 5;
        case 14:
            return 4;
        case 15:
            return 4;
        case 16:
            return 4;
        case 17:
            return 6;
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
            return 8;
        case 26:
            return 8;
        case 27:
            return 12;
        case 28:
            return 14;
        default:
            return 0;
        }
    }

// ---- the parity pins ----

// the print reads two X marks for Druaga (male and female clerics); the L&L
// transcription reads male-only - pinned by print, eyeball flag (the Gawaine
// 112 precedent)
inline bool cqcDruagaFemaleClericsPrint()
    { return true; }

// the print uses semicolons in the multi-word spheres (Heng thunder; weather,
// Hotoru wind; weather, Ishtar love; war, Marduk cities; weather, Brigit
// fire; poetry) where the L&L transcription normalizes to commas
inline bool cqcSphereSemicolonsPrint()
    { return true; }

// the Hastsezini jode green print garble reads jade green (the L&L voice)
inline bool cqcHastseziniJadeGreen()
    { return true; }

// the Arawn frequency reads at death (the psm-4 fold merged the two words)
inline bool cqcArawnAtDeath()
    { return true; }

// the chart carries no Arthurian block - the Arthurian section is
// heroes-only, no deities (the batch order runs American Indian, Babylonian,
// Celtic)
inline bool cqcNoArthurianRows()
    { return true; }

// the Silvanus tree planting cell carries a stray quote glyph on the print
// (noted, not pinned)
inline bool cqcSilvanusStrayQuote()
    { return true; }

}   // namespace rules
