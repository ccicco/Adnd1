// =========================================================================================
// Adnd1 - rules/cqc6.h
// Appendix 3: the clerical quick-reference chart, batch six - the D&DG walk
// round twenty-six, print p. 141: the 13 rows of the Nehwon mythos across the
// 13 printed columns.
// census 796 -> 797.
//
// primary ink: the ROTATED extract/ddg tesseract pass (pNNN_rot_full.txt +
// pNNN_rot_tsv.tsv, pdf page 141; the second printing) - the batch rides the
// pdf 141 block below the R873 Melnibonean tail; the collation voice: the
// 1eonline L&L per-deity chart rows (the Nehwon slugs run flat). The
// adjudications: the Aarth male + female pin (print over the L&L third X,
// eyeball flag), the Red God sphere fire pinned (the L&L voice reads
// underground areas; the print glyph run reads the short word), the Hate
// place underground pinned (the garble restored; the L&L voice adds temple),
// the Earth God name pinned Nehwon Earth God (the pass reads Earth God; the
// row sorts after Kos and the R863 prose name carries the prefix), the Gods
// of Lankhmar year-s end and Spider God summer solstice garbles restored, the
// Red God red-tailed hawk garble and red studded leather fold restored, the
// Rat God M + N-H geometry (no F X; the L&L voice agrees), the Tyaa
// female-only flag (the single X at the F column), and the Gods of Trouble
// stray dot noted. The batch order runs the Nehwon walk (Aarth through
// Votishal).
//
namespace rules {

// ---- the batch six census ----

// the clerical chart batch six round: the D&DG walk round twenty-six
inline int cqc6Round()
    { return 874; }

// the sixth chart batch (the App 3 box stays open until the last batch lands)
inline int cqc6Batch()
    { return 6; }

// the chart batch six print page opens at 141
inline int cqc6PrintStart()
    { return 141; }

// the chart batch six print page closes at 141
inline int cqc6PrintEnd()
    { return 141; }

// the batch rows (the thirteen Nehwon rows)
inline int cqc6Rows()
    { return 13; }

// the Nehwon mythos rows (the block rides pdf 141 below the R873 Melnibonean
// tail)
inline int cqc6NehwonRows()
    { return 13; }

// the rows reading a male-clerics X (Tyaa the row without)
inline int cqc6MaleRows()
    { return 12; }

// the rows reading a female-clerics X (the Earth God and Rat God rows
// without, Tyaa the row with the flag alone)
inline int cqc6FemaleRows()
    { return 11; }

// the rows reading a non-human clerics X (Death and the Rat God)
inline int cqc6NonHumanRows()
    { return 2; }

// the printed columns of the chart (the 13 the batch grids encode)
inline int cqc6PrintedColumns()
    { return 13; }

// the sphere-of-control roster ordinals of the batch
inline int cqc6SphereCount()
    { return 13; }

// the animal roster ordinals of the batch (the n/a rows ride the roster)
inline int cqc6AnimalCount()
    { return 9; }

// the raiment head roster ordinals of the batch (the n/a rows ride the
// roster)
inline int cqc6HeadCount()
    { return 10; }

// the raiment body roster ordinals of the batch
inline int cqc6BodyCount()
    { return 13; }

// the color roster ordinals of the batch (the red with black web wrap rides
// the roster)
inline int cqc6ColorCount()
    { return 12; }

// the holy-days roster ordinals of the batch (the n/a rows ride the roster)
inline int cqc6HolyDayCount()
    { return 7; }

// the sacrifice-frequency roster ordinals of the batch
inline int cqc6FreqCount()
    { return 4; }

// the sacrifice-form roster ordinals of the batch (the n/a rows ride the
// roster)
inline int cqc6FormCount()
    { return 8; }

// the place-of-worship roster ordinals of the batch
inline int cqc6PlaceCount()
    { return 4; }

// the batch grid count (one grid per batch round)
inline int cqc6TableCount()
    { return 1; }

// the batch chain count (the chart grids carry no chains)
inline int cqc6ChainCount()
    { return 0; }

// ---- the clerical chart batch six grid ----

// The row ordinals (0-12, the batch walk order: the thirteen Nehwon rows)
inline int cqc6ChartOrd(int b)
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
        default:
            return 0;
        }
    }

// The sphere-of-control roster ordinals (the labels ride the data file)
inline int cqc6ChartSphere(int b)
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
        default:
            return 0;
        }
    }

// The animal roster ordinals (the n/a rows ride the roster)
inline int cqc6ChartAnimal(int b)
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
            return 2;
        case 6:
            return 3;
        case 7:
            return 2;
        case 8:
            return 4;
        case 9:
            return 5;
        case 10:
            return 6;
        case 11:
            return 7;
        case 12:
            return 8;
        default:
            return 0;
        }
    }

// The male clerics flag (the printed X reads 1)
inline int cqc6ChartM(int b)
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
            return 0;
        case 12:
            return 1;
        default:
            return 0;
        }
    }

// The female clerics flag (the printed X reads 1; Tyaa the row with the flag
// alone)
inline int cqc6ChartF(int b)
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
            return 0;
        case 9:
            return 1;
        case 10:
            return 1;
        case 11:
            return 1;
        case 12:
            return 1;
        default:
            return 0;
        }
    }

// The non-human clerics flag (the printed X reads 1; the Aarth divergence
// pins the print against the L&L third X)
inline int cqc6ChartNh(int b)
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
            return 1;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        default:
            return 0;
        }
    }

// The raiment head roster ordinals (the n/a rows ride the roster)
inline int cqc6ChartHead(int b)
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
            return 0;
        case 9:
            return 7;
        case 10:
            return 0;
        case 11:
            return 8;
        case 12:
            return 9;
        default:
            return 0;
        }
    }

// The raiment body roster ordinals
inline int cqc6ChartBody(int b)
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
        default:
            return 0;
        }
    }

// The color roster ordinals (the red with black web wrap rides the roster)
inline int cqc6ChartColor(int b)
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
            return 4;
        case 9:
            return 8;
        case 10:
            return 9;
        case 11:
            return 10;
        case 12:
            return 11;
        default:
            return 0;
        }
    }

// The holy-days roster ordinals (the n/a rows ride the roster)
inline int cqc6ChartHolyday(int b)
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
            return 0;
        case 6:
            return 4;
        case 7:
            return 5;
        case 8:
            return 4;
        case 9:
            return 6;
        case 10:
            return 6;
        case 11:
            return 4;
        case 12:
            return 0;
        default:
            return 0;
        }
    }

// The sacrifice-frequency roster ordinals
inline int cqc6ChartFreq(int b)
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
            return 0;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 2;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 3;
        case 11:
            return 2;
        case 12:
            return 2;
        default:
            return 0;
        }
    }

// The sacrifice-form roster ordinals (the n/a rows ride the roster)
inline int cqc6ChartForm(int b)
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
            return 2;
        case 5:
            return 3;
        case 6:
            return 4;
        case 7:
            return 5;
        case 8:
            return 5;
        case 9:
            return 6;
        case 10:
            return 5;
        case 11:
            return 7;
        case 12:
            return 7;
        default:
            return 0;
        }
    }

// The place-of-worship roster ordinals (the underground pin rides the roster)
inline int cqc6ChartPlace(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 1;
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
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        default:
            return 0;
        }
    }

// ---- the parity pins ----

// the headline divergence: the print reads the Aarth flags male + female only
// (no N-H mark) where the L&L voice reads a third X - pinned by print,
// eyeball flag
inline bool cqc6AarthMfOnlyPrint()
    { return true; }

// the print reads the Red God sphere fire where the L&L voice reads
// underground areas - the print glyph run reads the short word, pinned by
// print
inline bool cqc6RedGodSphereFire()
    { return true; }

// the Hate place garble restored to underground; the L&L voice adds temple -
// the print reads the single word, pinned by print
inline bool cqc6HatePlaceUnderground()
    { return true; }

// the rotated pass reads the chart label Earth God; the row sorts after Kos
// (the N of Nehwon) and the R863 prose name pins Nehwon Earth God
inline bool cqc6EarthGodNamePin()
    { return true; }

// the Gods of Lankhmar yeor-s end garble restored to year-s end (the L&L
// voice agrees)
inline bool cqc6YearsEndRestored()
    { return true; }

// the Red God red-failed hawk garble restored to red-tailed hawk; the
// redstudded fold restored to red studded leather
inline bool cqc6RedTailedRestored()
    { return true; }

// the Spider God summgr solstice garble restored to summer solstice
inline bool cqc6SummerRestored()
    { return true; }

// the Rat God flags read male + N-H only (the X pair at the M and N-H
// columns, none at F) - the L&L voice agrees
inline bool cqc6RatGodNhGeometry()
    { return true; }

// the stray dot before the Gods of Trouble form n/a noted - a print artifact,
// not ink
inline bool cqc6GodsOfTroubleStrayDot()
    { return true; }

// the Tyaa row reads a female-only flag (the single X at the F column) - the
// L&L voice agrees
inline bool cqc6TyaaFemaleOnly()
    { return true; }

}   // namespace rules
