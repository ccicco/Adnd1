// =========================================================================================
// Adnd1 - rules/oa106table74.h
// OA TREASURE - TABLE 74, MONETARY TREASURE AND MAGICAL ITEMS, printed
// capture p. 286 - the treasure type grid round
// census 657 -> 658.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 188 closed, 47 open - the Table 74 box
// flips (census 657 -> 658); NEXT - R736: Table II.A. (Orient): Monetary
// Treasure (capture p. 286), prefix dkx (verify free at the landing), audit
// "R736 OA Table II.A. Orient monetary treasure audit", include after
// rules/oa106table74.h
//
namespace rules {

// ---- the treasure type grid ----

// the treasure type row count - the A through Z of the Table 74 grid (print
// capture p. 286)
inline int dkwTypeCount()
    { return 26; }

// the fen minimum - the low die of the rolled range (the thousand fen - the
// copper penny column of the A through Z rows, the 0 the nil; print capture
// p. 286)
inline int dkwFenMin(int b)
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
            return 0;
        case 7:
            return 5;
        case 8:
            return 0;
        case 9:
            return 3;
        case 10:
            return 0;
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
            return 1;
        default:
            return 0;
        }
    }

// the fen maximum - the high die of the rolled range (the thousand fen - the
// copper penny column of the A through Z rows, the 0 the nil; print capture
// p. 286)
inline int dkwFenMax(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 8;
        case 2:
            return 12;
        case 3:
            return 8;
        case 4:
            return 10;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 30;
        case 8:
            return 0;
        case 9:
            return 24;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 4;
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
            return 3;
        default:
            return 0;
        }
    }

// the fen percent - the chance of the roll, the 100 the guaranteed pieces
// rows (the thousand fen - the copper penny column of the A through Z rows,
// the 0 the nil; print capture p. 286)
inline int dkwFenPct(int b)
    {
        switch (b) {
        case 0:
            return 25;
        case 1:
            return 50;
        case 2:
            return 20;
        case 3:
            return 10;
        case 4:
            return 5;
        case 5:
            return 0;
        case 6:
            return 0;
        case 7:
            return 25;
        case 8:
            return 0;
        case 9:
            return 100;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 25;
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
            return 20;
        default:
            return 0;
        }
    }

// the yuan minimum - the low die of the rolled range (the thousand yuan - the
// silver dime column, the 0 the nil; print capture p. 286)
inline int dkwYuanMin(int b)
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
            return 3;
        case 6:
            return 0;
        case 7:
            return 1;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 4;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 1;
        case 15:
            return 2;
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
            return 2;
        default:
            return 0;
        }
    }

// the yuan maximum - the high die of the rolled range (the thousand yuan -
// the silver dime column, the 0 the nil; print capture p. 286)
inline int dkwYuanMax(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 6;
        case 2:
            return 6;
        case 3:
            return 10;
        case 4:
            return 10;
        case 5:
            return 18;
        case 6:
            return 0;
        case 7:
            return 100;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 24;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 6;
        case 15:
            return 8;
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
            return 8;
        default:
            return 0;
        }
    }

// the yuan percent - the chance of the roll, the 100 the guaranteed pieces
// rows (the thousand yuan - the silver dime column, the 0 the nil; print
// capture p. 286)
inline int dkwYuanPct(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 25;
        case 2:
            return 30;
        case 3:
            return 15;
        case 4:
            return 25;
        case 5:
            return 10;
        case 6:
            return 0;
        case 7:
            return 40;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 100;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 0;
        case 14:
            return 20;
        case 15:
            return 30;
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
            return 25;
        default:
            return 0;
        }
    }

// the tael minimum - the low die of the rolled range (the hundred tael - the
// silver dollar column, the 0 the nil; print capture p. 286)
inline int dkwTaelMin(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 10;
        case 2:
            return 1;
        case 3:
            return 10;
        case 4:
            return 10;
        case 5:
            return 20;
        case 6:
            return 10;
        case 7:
            return 20;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 2;
        case 12:
            return 4;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 1;
        case 16:
            return 0;
        case 17:
            return 10;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 10;
        case 23:
            return 0;
        case 24:
            return 10;
        case 25:
            return 20;
        default:
            return 0;
        }
    }

// the tael maximum - the high die of the rolled range (the hundred tael - the
// silver dollar column, the 0 the nil; print capture p. 286)
inline int dkwTaelMax(int b)
    {
        switch (b) {
        case 0:
            return 20;
        case 1:
            return 40;
        case 2:
            return 10;
        case 3:
            return 60;
        case 4:
            return 60;
        case 5:
            return 80;
        case 6:
            return 40;
        case 7:
            return 80;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 12;
        case 12:
            return 24;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 10;
        case 16:
            return 0;
        case 17:
            return 40;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 100;
        case 23:
            return 0;
        case 24:
            return 60;
        case 25:
            return 60;
        default:
            return 0;
        }
    }

// the tael percent - the chance of the roll, the 100 the guaranteed pieces
// rows (the hundred tael - the silver dollar column, the 0 the nil; print
// capture p. 286)
inline int dkwTaelPct(int b)
    {
        switch (b) {
        case 0:
            return 35;
        case 1:
            return 25;
        case 2:
            return 10;
        case 3:
            return 35;
        case 4:
            return 25;
        case 5:
            return 30;
        case 6:
            return 50;
        case 7:
            return 45;
        case 8:
            return 0;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 100;
        case 12:
            return 100;
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 25;
        case 16:
            return 0;
        case 17:
            return 40;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 60;
        case 23:
            return 0;
        case 24:
            return 70;
        case 25:
            return 25;
        default:
            return 0;
        }
    }

// the chien minimum - the low die of the rolled range (the hundred ch'ien -
// the gold coin column, the 0 the nil; print capture p. 286)
inline int dkwChienMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
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
            return 2;
        case 7:
            return 4;
        case 8:
            return 2;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 1;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 10;
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
            return 0;
        case 25:
            return 1;
        default:
            return 0;
        }
    }

// the chien maximum - the high die of the rolled range (the hundred ch'ien -
// the gold coin column, the 0 the nil; print capture p. 286)
inline int dkwChienMax(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 8;
        case 6:
            return 16;
        case 7:
            return 40;
        case 8:
            return 12;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 6;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 30;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 8;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 3;
        default:
            return 0;
        }
    }

// the chien percent - the chance of the roll, the 100 the guaranteed pieces
// rows (the hundred ch'ien - the gold coin column, the 0 the nil; print
// capture p. 286)
inline int dkwChienPct(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 35;
        case 6:
            return 50;
        case 7:
            return 25;
        case 8:
            return 30;
        case 9:
            return 0;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 100;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 50;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 0;
        case 21:
            return 0;
        case 22:
            return 15;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 30;
        default:
            return 0;
        }
    }

// the gems minimum - the low die of the rolled range (the gems - the gem
// count column, the 0 the nil; print capture p. 286)
inline int dkwGemsMin(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 1;
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
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 1;
        case 17:
            return 3;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 10;
        case 21:
            return 0;
        case 22:
            return 10;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 5;
        default:
            return 0;
        }
    }

// the gems maximum - the high die of the rolled range (the gems - the gem
// count column, the 0 the nil; print capture p. 286)
inline int dkwGemsMax(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 8;
        case 2:
            return 6;
        case 3:
            return 6;
        case 4:
            return 8;
        case 5:
            return 20;
        case 6:
            return 12;
        case 7:
            return 100;
        case 8:
            return 10;
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
            return 4;
        case 17:
            return 24;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 40;
        case 21:
            return 0;
        case 22:
            return 40;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 30;
        default:
            return 0;
        }
    }

// the gems percent - the chance of the roll, the 100 the guaranteed pieces
// rows (the gems - the gem count column, the 0 the nil; print capture p. 286)
inline int dkwGemsPct(int b)
    {
        switch (b) {
        case 0:
            return 60;
        case 1:
            return 30;
        case 2:
            return 25;
        case 3:
            return 30;
        case 4:
            return 15;
        case 5:
            return 20;
        case 6:
            return 30;
        case 7:
            return 50;
        case 8:
            return 55;
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
            return 50;
        case 17:
            return 55;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 90;
        case 21:
            return 0;
        case 22:
            return 60;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 55;
        default:
            return 0;
        }
    }

// the art minimum - the low die of the rolled range (the art objects - the
// art count column, the 0 the nil; print capture p. 286)
inline int dkwArtMin(int b)
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
            return 10;
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
        case 13:
            return 0;
        case 14:
            return 0;
        case 15:
            return 0;
        case 16:
            return 0;
        case 17:
            return 1;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 2;
        case 21:
            return 0;
        case 22:
            return 3;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 3;
        default:
            return 0;
        }
    }

// the art maximum - the high die of the rolled range (the art objects - the
// art count column, the 0 the nil; print capture p. 286)
inline int dkwArtMax(int b)
    {
        switch (b) {
        case 0:
            return 6;
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 3;
        case 4:
            return 4;
        case 5:
            return 6;
        case 6:
            return 6;
        case 7:
            return 30;
        case 8:
            return 6;
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
            return 8;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 20;
        case 21:
            return 0;
        case 22:
            return 30;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 18;
        default:
            return 0;
        }
    }

// the art percent - the chance of the roll, the 100 the guaranteed pieces
// rows (the art objects - the art count column, the 0 the nil; print capture
// p. 286)
inline int dkwArtPct(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 20;
        case 2:
            return 20;
        case 3:
            return 25;
        case 4:
            return 10;
        case 5:
            return 10;
        case 6:
            return 25;
        case 7:
            return 50;
        case 8:
            return 50;
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
            return 45;
        case 18:
            return 0;
        case 19:
            return 0;
        case 20:
            return 80;
        case 21:
            return 0;
        case 22:
            return 50;
        case 23:
            return 0;
        case 24:
            return 0;
        case 25:
            return 50;
        default:
            return 0;
        }
    }

// the maps minimum - the low die of the rolled range (the maps and magic -
// the item count column of the any-N and range rows, the 0 the nil; print
// capture p. 286)
inline int dkwMapsMin(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 4;
        case 7:
            return 4;
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
            return 2;
        case 19:
            return 1;
        case 20:
            return 1;
        case 21:
            return 2;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 0;
        case 25:
            return 3;
        default:
            return 0;
        }
    }

// the maps maximum - the high die of the rolled range (the maps and magic -
// the item count column of the any-N and range rows, the 0 the nil; print
// capture p. 286)
inline int dkwMapsMax(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 3;
        case 6:
            return 4;
        case 7:
            return 4;
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
            return 8;
        case 19:
            return 4;
        case 20:
            return 1;
        case 21:
            return 2;
        case 22:
            return 1;
        case 23:
            return 1;
        case 24:
            return 0;
        case 25:
            return 3;
        default:
            return 0;
        }
    }

// the maps percent - the chance of the roll, the 100 the guaranteed pieces
// rows (the maps and magic - the item count column of the any-N and range
// rows, the 0 the nil; print capture p. 286)
inline int dkwMapsPct(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 10;
        case 2:
            return 10;
        case 3:
            return 15;
        case 4:
            return 25;
        case 5:
            return 30;
        case 6:
            return 35;
        case 7:
            return 15;
        case 8:
            return 15;
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
            return 40;
        case 19:
            return 50;
        case 20:
            return 70;
        case 21:
            return 85;
        case 22:
            return 55;
        case 23:
            return 60;
        case 24:
            return 0;
        case 25:
            return 50;
        default:
            return 0;
        }
    }

// ---- the maps and magic clauses ----

// the plus-potion clause - the D, H, and X rows of the maps and magic column
// (print capture p. 286)
inline int dkwMapsPlusPotion()
    { return 1; }

// the plus-scroll clause - the E, F, G, and H rows of the maps and magic
// column, the capture misreading 1- for the 1 scroll of H (print capture p.
// 286)
inline int dkwMapsPlusScroll()
    { return 1; }

// the except clause - the F row: any 3 except swords or misc. weapons plus
// potion and 1 scroll, the capture capitalizing Weapons (print capture p.
// 286)
inline int dkwMapsExceptSwordsMisc()
    { return 1; }

// the except clause - the U and V rows: 1 and 2 of each magic except potions
// and scrolls (print capture p. 286)
inline int dkwMapsExceptPotionsScrolls()
    { return 1; }

// the B row clause - the sword, armor, or misc. weapon of the maps and magic
// column (print capture p. 286)
inline int dkwMapsSwordArmorWeapon()
    { return 1; }

// the W row clause - the 1 map of the maps and magic column (print capture p.
// 286)
inline int dkwMapsOneMap()
    { return 1; }

// the X row clause - the 1 misc. magic and 1 potion, the capture misreading
// mist. for misc. (print capture p. 286)
inline int dkwMapsMiscMagicAndPotion()
    { return 1; }

// the pieces rows - the J, K, L, M, and N rows carry no percent chance, the
// fixed pieces pinned with the 100 percent (print capture p. 286)
inline int dkwPiecesGuaranteed()
    { return 1; }

}   // namespace rules
