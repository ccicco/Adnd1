// =========================================================================================
// Adnd1 - rules/oa71yearly.h
// OA TABLE 71, printed capture p. 237 - the yearly events round
// census 619 -> 620.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift. THE GRID: the nineteen yearly events across the
// percentile die, the ranges contiguous and complete - Ambassador 1-10;
// Assassination of a Lord 11-15; Birth 16-30; Comet the lone 31; Death of a
// Lord 32-40; Earthquake Major 41-43; Famine 44-47; Fire Major 48-52; Flood
// 53-57; Incursion Major the lone 58; Marriage 59-68; New Religion the lone
// 69; Plague 70-74; Political Plot 75-78; Rebellion 79-85; Tsunami the lone
// 86; Visitation the lone 87; Volcano the lone 88; War the 89-100 - the
// widest range, war the likeliest of the year. THE USE: the yearly event
// determined FIRST, one only in a given year, remaining in effect for the
// entire year and often determining the type of the monthly events; the
// occurrence month the 1d12 roll; the scope the campaign area alone, or one
// event per land when the player characters travel or spread. The grid
// codifies per the R431 calculus
//
// the gap census after this round: 150 closed, 85 open - the Table 71 box
// flips (census 619 -> 620); NEXT - R698: the Yearly Events prose and
// explanations (capture pp. 237-243), prefix djl (verify free at the
// landing), audit "R698 OA yearly events prose audit", include after
// rules/oa71yearly.h
//
namespace rules {

// ---- the Table 71 yearly events grid ----

// the Table 71 minimum rolls by row ordinal (print capture p. 237):
// Ambassador 1, Assassination 11, Birth 16, Comet 31, Death of a Lord 32,
// Earthquake 41, Famine 44, Fire 48, Flood 53, Incursion 58, Marriage 59, New
// Religion 69, Plague 70, Political Plot 75, Rebellion 79, Tsunami 86,
// Visitation 87, Volcano 88, War 89 - the ranges contiguous, each event
// beginning where the last ended
inline int djkOA71MinRoll(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 11;
        case 2:
            return 16;
        case 3:
            return 31;
        case 4:
            return 32;
        case 5:
            return 41;
        case 6:
            return 44;
        case 7:
            return 48;
        case 8:
            return 53;
        case 9:
            return 58;
        case 10:
            return 59;
        case 11:
            return 69;
        case 12:
            return 70;
        case 13:
            return 75;
        case 14:
            return 79;
        case 15:
            return 86;
        case 16:
            return 87;
        case 17:
            return 88;
        case 18:
            return 89;
        default:
            return 0;
        }
    }

// the Table 71 maximum rolls by row ordinal (print capture p. 237):
// Ambassador 10, Assassination 15, Birth 30, Comet 31, Death of a Lord 40,
// Earthquake 43, Famine 47, Fire 52, Flood 57, Incursion 58, Marriage 68, New
// Religion 69, Plague 74, Political Plot 78, Rebellion 85, Tsunami 86,
// Visitation 87, Volcano 88, War 100 - the six single-roll events (Comet,
// Incursion, New Religion, Tsunami, Visitation, Volcano) and the War closing
// the table at 100
inline int djkOA71MaxRoll(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 15;
        case 2:
            return 30;
        case 3:
            return 31;
        case 4:
            return 40;
        case 5:
            return 43;
        case 6:
            return 47;
        case 7:
            return 52;
        case 8:
            return 57;
        case 9:
            return 58;
        case 10:
            return 68;
        case 11:
            return 69;
        case 12:
            return 74;
        case 13:
            return 78;
        case 14:
            return 85;
        case 15:
            return 86;
        case 16:
            return 87;
        case 17:
            return 88;
        case 18:
            return 100;
        default:
            return 0;
        }
    }

// the Table 71 event count - the nineteen yearly events across the percentile
// die, the loop bound of the emitted grid audit (print capture p. 237)
inline int djkOA71EventCount()
    { return 19; }

// the War range minimum - the 89 of the 89-100, the widest range of the
// table, war the likeliest yearly event (print capture p. 237)
inline int djkOA71WarMin()
    { return 89; }

// the War range maximum - the 100 of the 89-100 (print capture p. 237)
inline int djkOA71WarMax()
    { return 100; }

// the yearly event rule - only one yearly event in a given year, determined
// first and remaining in effect for the entire year, often determining the
// type of monthly events that occur (print capture p. 237)
inline bool djkOA71OnePerYear()
    { return true; }

// the occurrence month - once the yearly event is known, 1d12 rolled to find
// the month it occurs in or begins (print capture p. 237)
inline bool djkOA71Month1d12()
    { return true; }

// the scope - yearly events normally figured only for the campaign area, but
// a traveling group or several groups meaning one yearly event per land of
// involvement (the Kozakura and Shou Lung example) (print capture p. 237)
inline bool djkOA71CampaignAreaOnly()
    { return true; }

}   // namespace rules
