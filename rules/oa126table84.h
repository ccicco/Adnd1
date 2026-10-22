// =========================================================================================
// Adnd1 - rules/oa126table84.h
// OA TREASURE - TABLE 84, MARTIAL ARTS CLASS, printed capture p. 293 - the
// martial arts grid round
// census 677 -> 678.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 208 closed, 27 open - the Table 84 box
// flips (census 677 -> 678); NEXT - R756: Table 85: Ninja Class (capture p.
// 293), prefix dlr (verify free at the landing), audit "R756 OA Table 85
// ninja audit", include after rules/oa126table84.h
//
namespace rules {

// ---- the Table 84 grid ----

// the martial arts row count - the twelve d100 bands of the Table 84 martial
// arts type grid (print capture p. 293)
inline int dlqMartialArtsRowCount()
    { return 12; }

// the d100 band minimum - the low roll of the row (print capture p. 293)
inline int dlqMartialArtsRollMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 11;
        case 3:
            return 21;
        case 4:
            return 31;
        case 5:
            return 36;
        case 6:
            return 41;
        case 7:
            return 56;
        case 8:
            return 71;
        case 9:
            return 76;
        case 10:
            return 81;
        case 11:
            return 91;
        default:
            return 0;
        }
    }

// the d100 band maximum - the high roll of the row (print capture p. 293)
inline int dlqMartialArtsRollMax(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 20;
        case 3:
            return 30;
        case 4:
            return 35;
        case 5:
            return 40;
        case 6:
            return 55;
        case 7:
            return 70;
        case 8:
            return 75;
        case 9:
            return 80;
        case 10:
            return 90;
        case 11:
            return 100;
        default:
            return 0;
        }
    }

// the martial arts type code - 1 the chain; 2 the fang; 3 the gunsen; 4 the
// jitte; 5 the kau sin ke; 6 the kiseru; 7 the nunchaku; 8 the sai; 9 the
// sang kauw; 10 the siangkam; 11 the three-piece-rod; 12 the tui-fa (print
// capture p. 293)
inline int dlqMartialArtsCode(int b)
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

// ---- the band walk ----

// the chain and fang head bands - the 01-10 opening stretch, the chain 01-05
// and the fang 06-10 (print capture p. 293)
inline int dlqChainToFangHead()
    { return 1; }

// the nunchaku band - the 41-55, the widest mid-grid band (print capture p.
// 293)
inline int dlqNunchakuBand()
    { return 1; }

// the sai band - the 56-70 (print capture p. 293)
inline int dlqSaiBand()
    { return 1; }

// the three-piece-rod band - the 81-90, the hyphenated name of the print
// (print capture p. 293)
inline int dlqThreePieceRodBand()
    { return 1; }

// the tui-fa tail - the 91-100 closing band (print capture p. 293)
inline int dlqTuiFaTail()
    { return 1; }

}   // namespace rules
