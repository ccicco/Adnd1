// =========================================================================================
// Adnd1 - rules/oa112rods.h
// OA TREASURE - RODS, STAVES, AND WANDS, printed capture p. 288 - the
// resurrection rod round
// census 663 -> 664.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 194 closed, 41 open - the rods box flips
// (census 663 -> 664); NEXT - R742: Miscellaneous Magic (capture pp.
// 288-289), prefix dld (verify free at the landing), audit "R742 OA misc
// magic audit", include after rules/oa112rods.h
//
namespace rules {

// ---- the rod ----

// the rod of resurrection - the item expending a number of charges according
// to the table (print capture p. 288)
inline int dlcRodOfResurrection()
    { return 1; }

// the charge law - the class base plus the race plus of the two columns
// (print capture p. 288)
inline int dlcChargesClassPlusRace()
    { return 1; }

// ---- the class base table ----

// the class row count - the ten classes of the charge table (print capture p.
// 288)
inline int dlcClassCount()
    { return 10; }

// the class code - 1 the samurai; 2 the shukenja; 3 the bushi; 4 the ninja; 5
// the wu jen; 6 the kensai; 7 the sohei; 8 the yakuza; 9 the monk; 10 the
// barbarian (print capture p. 288)
inline int dlcClassCode(int b)
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

// the base charges - the 3 of the samurai, the 1 of the shukenja, the 2 of
// the bushi, the 4 of the ninja, the 3 of the wu jen, the 2 of the kensai,
// the 1 of the sohei, the 3 of the yakuza, the 3 of the monk, the 3 of the
// barbarian (print capture p. 288)
inline int dlcClassBase(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 4;
        case 4:
            return 3;
        case 5:
            return 2;
        case 6:
            return 1;
        case 7:
            return 3;
        case 8:
            return 3;
        case 9:
            return 3;
        default:
            return 0;
        }
    }

// ---- the race plus table ----

// the race row count - the four races of the plus column (print capture p.
// 288)
inline int dlcRaceCount()
    { return 4; }

// the race code - 1 the korobokuru; 2 the spirit folk; 3 the hengeyokai; 4
// the human (print capture p. 288)
inline int dlcRaceCode(int b)
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
        default:
            return 0;
        }
    }

// the race plus - the 3 of the korobokuru, the 4 of the spirit folk, the 3 of
// the hengeyokai, the 1 of the human (print capture p. 288)
inline int dlcRacePlus(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 4;
        case 2:
            return 3;
        case 3:
            return 1;
        default:
            return 0;
        }
    }

}   // namespace rules
