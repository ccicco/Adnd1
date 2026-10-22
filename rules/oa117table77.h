// =========================================================================================
// Adnd1 - rules/oa117table77.h
// OA TREASURE - TABLE 77, SPECIAL PROPERTIES, printed capture p. 290 - the
// special property grid round
// census 668 -> 669.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 199 closed, 36 open - the Table 77 box
// flips (census 668 -> 669); NEXT - R747: Explanation of Armor Properties
// (capture p. 290), prefix dli (verify free at the landing), audit "R747 OA
// armor explanation audit", include after rules/oa117table77.h
//
namespace rules {

// ---- the Table 77 grid ----

// the special property row count - the eleven d100 bands of the Table 77
// special property grid (print capture p. 290)
inline int dlhSpecialRowCount()
    { return 11; }

// the d100 band minimum - the low roll of the row (print capture p. 290)
inline int dlhSpecialRollMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 31;
        case 3:
            return 41;
        case 4:
            return 51;
        case 5:
            return 66;
        case 6:
            return 76;
        case 7:
            return 81;
        case 8:
            return 86;
        case 9:
            return 91;
        case 10:
            return 96;
        default:
            return 0;
        }
    }

// the d100 band maximum - the high roll of the row (print capture p. 290)
inline int dlhSpecialRollMax(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 30;
        case 2:
            return 40;
        case 3:
            return 50;
        case 4:
            return 65;
        case 5:
            return 75;
        case 6:
            return 80;
        case 7:
            return 85;
        case 8:
            return 90;
        case 9:
            return 95;
        case 10:
            return 100;
        default:
            return 0;
        }
    }

// the special property code - 1 the etherealness; 2 the +3 versus missiles; 3
// the +4 versus missiles; 4 the +5 versus missiles; 5 the vulnerability; 6
// the missile attraction; 7 the presence; 8 the blending; 9 the fear; 10 the
// possession; 11 the healing (print capture p. 290)
inline int dlhSpecialCode(int b)
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
        default:
            return 0;
        }
    }

// ---- the band walk ----

// the etherealness band - the 01-05, its mechanics in the Explanation prose
// (print capture p. 290)
inline int dlhEtherealnessBand()
    { return 1; }

// the versus-missiles bands - the +3, +4, and +5 of the 06-50 stretch, three
// grades of the missile protection (print capture p. 290)
inline int dlhVersusMissilesBands()
    { return 1; }

// the vulnerability band - the 51-65, the pluses a penalty per the
// Explanation (print capture p. 290)
inline int dlhVulnerabilityBand()
    { return 1; }

// the missile attraction band - the 66-75, the cursed shield function of the
// Explanation (print capture p. 290)
inline int dlhMissileAttractionBand()
    { return 1; }

// the presence band - the 76-80, the commanding aura of the Explanation
// (print capture p. 290)
inline int dlhPresenceBand()
    { return 1; }

// the blending band - the 81-85, the normal-clothing disguise of the
// Explanation (print capture p. 290)
inline int dlhBlendingBand()
    { return 1; }

// the fear band - the 86-90, the fear charges of the Explanation (print
// capture p. 290)
inline int dlhFearBand()
    { return 1; }

// the possession band - the 91-95, the lifeforce possession of the
// Explanation prose (print capture p. 290)
inline int dlhPossessionBand()
    { return 1; }

// the healing band - the 96-100, the healing armor of the Explanation (print
// capture p. 290)
inline int dlhHealingBand()
    { return 1; }

}   // namespace rules
