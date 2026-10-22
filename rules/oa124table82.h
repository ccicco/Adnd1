// =========================================================================================
// Adnd1 - rules/oa124table82.h
// OA TREASURE - TABLE 82, MISCELLANEOUS, printed capture pp. 292-293 - the
// misc melee grid round
// census 675 -> 676.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 206 closed, 29 open - the Table 82 box
// flips (census 675 -> 676); NEXT - R754: Table 83: Missile Class (capture p.
// 293), prefix dlp (verify free at the landing), audit "R754 OA Table 83
// missile audit", include after rules/oa124table82.h
//
namespace rules {

// ---- the Table 82 grid ----

// the misc row count - the thirteen d100 bands of the Table 82 misc melee
// grid (print capture p. 292)
inline int dloMiscRowCount()
    { return 13; }

// the d100 band minimum - the low roll of the row (print capture p. 292)
inline int dloMiscRollMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 16;
        case 3:
            return 31;
        case 4:
            return 46;
        case 5:
            return 49;
        case 6:
            return 55;
        case 7:
            return 56;
        case 8:
            return 61;
        case 9:
            return 66;
        case 10:
            return 76;
        case 11:
            return 91;
        case 12:
            return 96;
        default:
            return 0;
        }
    }

// the d100 band maximum - the high roll of the row (print capture p. 293)
inline int dloMiscRollMax(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 15;
        case 2:
            return 30;
        case 3:
            return 45;
        case 4:
            return 48;
        case 5:
            return 54;
        case 6:
            return 55;
        case 7:
            return 60;
        case 8:
            return 65;
        case 9:
            return 75;
        case 10:
            return 90;
        case 11:
            return 95;
        case 12:
            return 100;
        default:
            return 0;
        }
    }

// the misc melee type code - 1 the battle axe; 2 the bo stick; 3 the dagger;
// 4 the halberd; 5 the jo stick; 6 the kama; 7 the lajatang; 8 the lance; 9
// the nagamaki - the capture printing the Nagasaki, the misprint pinned as
// printed; 10 the naginata; 11 the spear; 12 the tetsubo; 13 the trident
// (print capture p. 293)
inline int dloMiscCode(int b)
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
        case 12:
            return 13;
        default:
            return 0;
        }
    }

// ---- the quirks ----

// the melee class banner - the grid captioned the MELEE CLASS above the d100
// roll header (print capture p. 292)
inline int dloMeleeClassBanner()
    { return 1; }

// the nagamaki misprint - the capture printing the Nagasaki for the 61-65
// band, almost certainly the nagamaki intended, pinned as printed (print
// capture p. 293)
inline int dloNagasakiMisprint()
    { return 1; }

// the single-roll bands - the 55 lajatang and the 61-65 of the misprint row,
// the narrow one-number or five-number bands of the grid (print capture p.
// 293)
inline int dloSingleRollBands()
    { return 1; }

}   // namespace rules
