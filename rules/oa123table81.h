// =========================================================================================
// Adnd1 - rules/oa123table81.h
// OA TREASURE - TABLE 81, BOW, CROSSBOW, AND SLING CLASS, printed capture p.
// 292 - the bow class grid round
// census 674 -> 675.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 205 closed, 30 open - the Table 81 box
// flips (census 674 -> 675); NEXT - R753: Table 82: Miscellaneous (capture p.
// 292), prefix dlo (verify free at the landing), audit "R753 OA Table 82 misc
// melee audit", include after rules/oa123table81.h
//
namespace rules {

// ---- the Table 81 grid ----

// the bow row count - the ten d100 bands of the Table 81 bow type grid (print
// capture p. 292)
inline int dlnBowRowCount()
    { return 10; }

// the d100 band minimum - the low roll of the row (print capture p. 292)
inline int dlnBowRollMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 16;
        case 2:
            return 31;
        case 3:
            return 32;
        case 4:
            return 46;
        case 5:
            return 61;
        case 6:
            return 81;
        case 7:
            return 91;
        case 8:
            return 92;
        case 9:
            return 97;
        default:
            return 0;
        }
    }

// the d100 band maximum - the high roll of the row (print capture p. 292)
inline int dlnBowRollMax(int b)
    {
        switch (b) {
        case 0:
            return 15;
        case 1:
            return 30;
        case 2:
            return 31;
        case 3:
            return 45;
        case 4:
            return 60;
        case 5:
            return 80;
        case 6:
            return 90;
        case 7:
            return 91;
        case 8:
            return 96;
        case 9:
            return 100;
        default:
            return 0;
        }
    }

// the bow type code - 1 the composite shortbow; 2 the short bow; 3 the
// chu-ko-nu; 4 the heavy crossbow; 5 the light crossbow; 6 the daikyu; 7 the
// hankyu; 8 the pellet bow; 9 the sling; 10 the staff sling (print capture p.
// 292)
inline int dlnBowCode(int b)
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
        default:
            return 0;
        }
    }

// ---- the band walk ----

// the composite shortbow band - the 01-15 (print capture p. 292)
inline int dlnCompositeShortbowBand()
    { return 1; }

// the short bow band - the 16-30 (print capture p. 292)
inline int dlnShortBowBand()
    { return 1; }

// the chu-ko-nu band - the 31, the single-roll repeating crossbow (print
// capture p. 292)
inline int dlnChuKoNuBand()
    { return 1; }

// the heavy crossbow band - the 32-45 (print capture p. 292)
inline int dlnHeavyCrossbowBand()
    { return 1; }

// the light crossbow band - the 46-60 (print capture p. 292)
inline int dlnLightCrossbowBand()
    { return 1; }

// the daikyu band - the 61-80, the Japanese great bow (print capture p. 292)
inline int dlnDaikyuBand()
    { return 1; }

// the hankyu band - the 81-90, the Japanese short bow (print capture p. 292)
inline int dlnHankyuBand()
    { return 1; }

// the pellet bow band - the 91 (print capture p. 292)
inline int dlnPelletBowBand()
    { return 1; }

// the sling band - the 92-96 (print capture p. 292)
inline int dlnSlingBand()
    { return 1; }

// the staff sling band - the 97-100 (print capture p. 292)
inline int dlnStaffSlingBand()
    { return 1; }

}   // namespace rules
