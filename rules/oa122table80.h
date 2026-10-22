// =========================================================================================
// Adnd1 - rules/oa122table80.h
// OA TREASURE - TABLE 80, SWORD CLASS, printed capture p. 292 - the sword
// type grid round
// census 673 -> 674.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 204 closed, 31 open - the Table 80 box
// flips (census 673 -> 674); NEXT - R752: Table 81: Bow, Crossbow, And Sling
// Class (capture p. 292), prefix dln (verify free at the landing), audit
// "R752 OA Table 81 bow class audit", include after rules/oa122table80.h
//
namespace rules {

// ---- the Table 80 grid ----

// the sword row count - the seven d100 bands of the Table 80 sword type grid
// (print capture p. 292)
inline int dlmSwordRowCount()
    { return 7; }

// the d100 band minimum - the low roll of the row (print capture p. 292)
inline int dlmSwordRollMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 31;
        case 2:
            return 36;
        case 3:
            return 51;
        case 4:
            return 66;
        case 5:
            return 81;
        case 6:
            return 86;
        default:
            return 0;
        }
    }

// the d100 band maximum - the high roll of the row (print capture p. 292)
inline int dlmSwordRollMax(int b)
    {
        switch (b) {
        case 0:
            return 30;
        case 1:
            return 35;
        case 2:
            return 50;
        case 3:
            return 65;
        case 4:
            return 80;
        case 5:
            return 85;
        case 6:
            return 100;
        default:
            return 0;
        }
    }

// the sword type code - 1 the katana; 2 the parang; 3 the broad sword; 4 the
// long sword; 5 the short sword; 6 the two-handed sword; 7 the wakizashi
// (print capture p. 292)
inline int dlmSwordCode(int b)
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
        default:
            return 0;
        }
    }

// ---- the band walk ----

// the katana band - the 01-30, the heaviest weight of the grid (print capture
// p. 292)
inline int dlmKatanaBand()
    { return 1; }

// the parang band - the 31-35 (print capture p. 292)
inline int dlmParangBand()
    { return 1; }

// the broad sword band - the 36-50 (print capture p. 292)
inline int dlmBroadSwordBand()
    { return 1; }

// the long sword band - the 51-65 (print capture p. 292)
inline int dlmLongSwordBand()
    { return 1; }

// the short sword band - the 66-80 (print capture p. 292)
inline int dlmShortSwordBand()
    { return 1; }

// the two-handed sword band - the 81-85 (print capture p. 292)
inline int dlmTwoHandedSwordBand()
    { return 1; }

// the wakizashi band - the 86-100, the companion blade of the katana (print
// capture p. 292)
inline int dlmWakizashiBand()
    { return 1; }

}   // namespace rules
