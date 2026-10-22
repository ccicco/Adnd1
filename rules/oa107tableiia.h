// =========================================================================================
// Adnd1 - rules/oa107tableiia.h
// OA TREASURE - TABLE II.A. (ORIENT), MONETARY TREASURE, printed capture pp.
// 286-287 - the rolled hoard round
// census 658 -> 659.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 189 closed, 46 open - the Table II.A. box
// flips (census 658 -> 659); NEXT - R737: Table III. (Orient): Magical Items
// (capture p. 287), prefix dky (verify free at the landing), audit "R737 OA
// Table III Orient magical items audit", include after rules/oa107tableiia.h
//
namespace rules {

// ---- the Table II.A. grid ----

// the Table II.A. row count - the nine d20 bands of the Oriental monetary
// treasure table (print capture p. 286)
inline int dkxRowCount()
    { return 9; }

// the d20 band minimum - the low roll of the row (print capture p. 286)
inline int dkxRollMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 6;
        case 3:
            return 11;
        case 4:
            return 13;
        case 5:
            return 16;
        case 6:
            return 18;
        case 7:
            return 19;
        case 8:
            return 20;
        default:
            return 0;
        }
    }

// the d20 band maximum - the high roll of the row (print capture p. 286)
inline int dkxRollMax(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 5;
        case 2:
            return 10;
        case 3:
            return 12;
        case 4:
            return 15;
        case 5:
            return 17;
        case 6:
            return 18;
        case 7:
            return 19;
        case 8:
            return 20;
        default:
            return 0;
        }
    }

// the fen minimum - the low of the 10,000-40,000, the 0 the nil (print
// capture p. 286)
inline int dkxFenMin(int b)
    {
        switch (b) {
        case 0:
            return 10000;
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
        default:
            return 0;
        }
    }

// the fen maximum - the high of the 10,000-40,000, the 0 the nil (print
// capture p. 286)
inline int dkxFenMax(int b)
    {
        switch (b) {
        case 0:
            return 40000;
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
        default:
            return 0;
        }
    }

// the yuan minimum - the low of the 10,000-60,000, the 0 the nil (print
// capture p. 286)
inline int dkxYuanMin(int b)
    {
        switch (b) {
        case 0:
            return 10000;
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
        default:
            return 0;
        }
    }

// the yuan maximum - the high of the 10,000-60,000, the 0 the nil (print
// capture p. 286)
inline int dkxYuanMax(int b)
    {
        switch (b) {
        case 0:
            return 60000;
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
        default:
            return 0;
        }
    }

// the tael minimum - the low of the 10,000-60,000, the 0 the nil (print
// capture p. 286)
inline int dkxTaelMin(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 10000;
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
        default:
            return 0;
        }
    }

// the tael maximum - the high of the 10,000-60,000, the 0 the nil (print
// capture p. 286)
inline int dkxTaelMax(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 60000;
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
        default:
            return 0;
        }
    }

// the ch'ien minimum - the low of the 500-1,000 and 500-2,000, the 0 the nil
// (print capture p. 287)
inline int dkxChienMin(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 500;
        case 3:
            return 500;
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
        default:
            return 0;
        }
    }

// the ch'ien maximum - the high of the 500-1,000 and the 500-2,000 of the
// capture misreading 500-200, the 0 the nil (print capture p. 287)
inline int dkxChienMax(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 1000;
        case 3:
            return 2000;
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
        default:
            return 0;
        }
    }

// the gems minimum - the low of the 10-100, the 0 the nil (print capture p.
// 287)
inline int dkxGemsMin(int b)
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
            return 10;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        default:
            return 0;
        }
    }

// the gems maximum - the high of the 10-100, the 0 the nil (print capture p.
// 287)
inline int dkxGemsMax(int b)
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
            return 100;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        default:
            return 0;
        }
    }

// the art minimum - the low of the 5-50 jewelry or art pieces, the 0 the nil
// (print capture p. 287)
inline int dkxArtMin(int b)
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
            return 5;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        default:
            return 0;
        }
    }

// the art maximum - the high of the 5-50, the 0 the nil (print capture p.
// 287)
inline int dkxArtMax(int b)
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
            return 50;
        case 6:
            return 0;
        case 7:
            return 0;
        case 8:
            return 0;
        default:
            return 0;
        }
    }

// the rolls count - the 2 of the roll twice, the 3 of the roll three times,
// the 1 elsewhere (print capture p. 287)
inline int dkxRollsCount(int b)
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
            return 2;
        case 7:
            return 3;
        case 8:
            return 1;
        default:
            return 0;
        }
    }

// the reroll limit column - the 17 rerolled-above of the twice and
// three-times rows, the 0 elsewhere (print capture p. 287)
inline int dkxRerollAbove(int b)
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
            return 17;
        case 7:
            return 17;
        case 8:
            return 0;
        default:
            return 0;
        }
    }

// the one-of-each flag - the 1 of the 20 row, the 0 elsewhere (print capture
// p. 287)
inline int dkxOneOfEach(int b)
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
            return 1;
        default:
            return 0;
        }
    }

// ---- the roll mechanics ----

// the reroll limit - the rolls above 17 rerolled by the twice and three-times
// rows, the capture misreading 97 for the 17 of the 18 row (print capture p.
// 286)
inline int dkxRerollLimit()
    { return 17; }

// the one-of-each row - the 20 roll yielding one of each treasure above
// (print capture p. 286)
inline int dkxOneOfEachRow()
    { return 20; }

// the 18 row - roll twice, rerolling the rolls above the limit (print capture
// p. 287)
inline int dkxRollTwice()
    { return 1; }

// the 19 row - roll three times, rerolling the rolls above the limit (print
// capture p. 287)
inline int dkxRollThreeTimes()
    { return 1; }

// the 20 row - one of each treasure above (print capture p. 287)
inline int dkxOneOfEachTreasure()
    { return 1; }

// ---- the rows ----

// the 1-2 row - the 10,000-40,000 fen riding with the 10,000-60,000 yuan
// (print capture p. 286)
inline int dkxRowOneFenYuan()
    { return 1; }

// the 3-5 row - the 10,000-60,000 tael (print capture p. 286)
inline int dkxRowTael()
    { return 1; }

// the 6-10 row - the 500-1,000 ch'ien of the 1d6 + 4 (print capture p. 287)
inline int dkxRowChienOneDieSix()
    { return 1; }

// the 11-12 row - the 500-2,000 ch'ien of the 5d4, the capture misreading
// 500-200 for the 500-2,000 (print capture p. 287)
inline int dkxRowChienFiveDieFour()
    { return 1; }

// the 13-15 row - the 10-100 gems (print capture p. 287)
inline int dkxRowGems()
    { return 1; }

// the 16-17 row - the 5-50 pieces of jewelry or art objects (print capture p.
// 287)
inline int dkxRowJewelryOrArt()
    { return 1; }

}   // namespace rules
