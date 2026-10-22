// =========================================================================================
// Adnd1 - rules/oa127table85.h
// OA TREASURE - TABLE 85, NINJA CLASS, printed capture pp. 293-294 - the
// ninja grid round
// census 678 -> 679.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 209 closed, 26 open - the Table 85 box
// flips (census 678 -> 679); NEXT - R757: Explanation of Weapon Properties
// (capture p. 294), prefix dls (verify free at the landing), audit "R757 OA
// weapon explanation audit", include after rules/oa127table85.h
//
namespace rules {

// ---- the Table 85 grid ----

// the ninja row count - the twelve d100 bands of the Table 85 ninja type grid
// (print capture p. 293)
inline int dlrNinjaRowCount()
    { return 12; }

// the d100 band minimum - the low roll of the row (print capture p. 293)
inline int dlrNinjaRollMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 11;
        case 3:
            return 16;
        case 4:
            return 21;
        case 5:
            return 26;
        case 6:
            return 31;
        case 7:
            return 41;
        case 8:
            return 46;
        case 9:
            return 61;
        case 10:
            return 71;
        case 11:
            return 86;
        default:
            return 0;
        }
    }

// the d100 band maximum - the high roll of the row (print capture p. 294)
inline int dlrNinjaRollMax(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 15;
        case 3:
            return 20;
        case 4:
            return 25;
        case 5:
            return 30;
        case 6:
            return 40;
        case 7:
            return 45;
        case 8:
            return 60;
        case 9:
            return 70;
        case 10:
            return 85;
        case 11:
            return 100;
        default:
            return 0;
        }
    }

// the ninja type code - 1 the kawanaga; 2 the kumade; 3 the kusari-gama; 4
// the kyoketsu-shogi; 5 the needle, 10-60; 6 the nekode; 7 the ninja-to; 8
// the shaken, 2-12; 9 the shikomi-zue; 10 the spike shuriken, 2-12; 11 the
// large star shuriken, 3-18; 12 the small star shuriken, 3-18 (print capture
// p. 294)
inline int dlrNinjaCode(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 5;
        case 5:
            return 6;
        case 6:
            return 7;
        case 7:
            return 8;
        case 8:
            return 9;
        case 9:
            return 10;
        case 10:
            return 11;
        case 11:
            return 12;
        default:
            return 0;
        }
    }

// ---- the quirks ----

// the page break - the caption and the 01-05 kawanaga row on the one page,
// the remaining rows on the next (print capture p. 294)
inline int dlrPageBreakGrid()
    { return 1; }

// the shuriken bands - the three shuriken rows of the 61-100 tail, the spike
// and the large and small star (print capture p. 294)
inline int dlrShurikenBands()
    { return 1; }

// the ninja-to band - the 31-40, the ninja sword (print capture p. 294)
inline int dlrNinjaToBand()
    { return 1; }

// the concealed weapons - the shikomi-zue of the 46-60, the sword-in-cane,
// and the needle of the 21-25, the blowgun darts (print capture p. 294)
inline int dlrConcealedWeapons()
    { return 1; }

}   // namespace rules
