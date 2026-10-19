// =========================================================================================
// Adnd1 - rules/oacharprof.h
// TABLE 56 CHARACTER PROFICIENCIES, printed capture p. 99 - the OA character
// proficiencies round
// census 575 -> 576.
//
// pinned from the 2018 print capture (the settling authority), with the
// compressed-print capture giving a second independent read of the table -
// the Table 56 grid cross-checked cell-by-cell between the two passes (the
// table printing on capture p. 99 of the print pass; compressed p. 52); every
// printed cell agrees - zero contested cells. The grid pins as a table: the
// class rows 0 samurai, 1 shukenja, 2 sohei, 3 kensai, 4 o. barbarian, 5
// bushi, 6 wu jen and 7 ninja riding the first column comment, three data
// columns - the initial number of proficiencies at 1st level (5, 6, 4, 3, 9,
// 4, 6, 2), the levels per added proficiency as the denominator of the
// printed 1/N notation (1, 2, 3, 2, 3, 2, 2, 3) and the non-proficiency
// weapon penalty (2, 4, 2, 3, 2, 2, 5, 4). The column doctrines ride the
// comments: the initial-number reading (the number at 1st level), the 1/N
// reading (1/1 a proficiency each level, 1/4 four levels per proficiency, 1st
// level included when counting) and the penalty reading (the minus on to hit
// with a weapon not proficient in). The ninja rule pins as a bool - the ninja
// can only use his proficiencies for ninja weapons, the non-proficiency
// penalty applying only to ninja weapons, all other weapons taking the other
// class penalty. The table tag T56Data identifier-safe per the R639 lesson;
// the slot-system prose cross-references stay with R650
//
// the gap census after this round: 105 closed, 130 open - the Table 56 box
// flips (census 575 -> 576); NEXT - R654: Table 58 (Artisan Proficiencies),
// capture p. 103, prefix dho (verify free), audit "R654 OA artisan
// proficiencies audit", include after rules/oacharprof.h
//
namespace rules {

// ---- the Table 56 grid pins ----

// the eight character classes of the Table 56 grid (capture p. 99 of the
// print pass; compressed p. 52)
inline int dhnT56ClassCount()
    { return 8; }

// the initial number of proficiencies at 1st level (capture p. 99 of the
// print pass; compressed p. 52). The class rows ride this comment: 0 samurai,
// 1 shukenja, 2 sohei, 3 kensai, 4 o. barbarian, 5 bushi, 6 wu jen, 7 ninja -
// the printed header reads Initial # of Prof.
inline int dhnT56InitialProf(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 6;
        case 2:
            return 4;
        case 3:
            return 3;
        case 4:
            return 9;
        case 5:
            return 4;
        case 6:
            return 6;
        case 7:
            return 2;
        default:
            return -99;
        }
    }

// the levels that must be earned per additional proficiency - the denominator
// of the printed 1/N notation, 1/1 a proficiency each level (capture p. 99 of
// the print pass; compressed p. 52)
inline int dhnT56LevelsPerProf(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 3;
        default:
            return -99;
        }
    }

// the non-proficiency weapon penalty - the minus on to hit with a weapon not
// proficient in (capture p. 99 of the print pass; compressed p. 52)
inline int dhnT56NonprofPenalty(int b)
    {
        switch (b) {
        case 0:
            return 2;
        case 1:
            return 4;
        case 2:
            return 2;
        case 3:
            return 3;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 5;
        case 7:
            return 4;
        default:
            return -99;
        }
    }

// ---- the ninja proficiency pins ----

// the ninja can only use his proficiencies for ninja weapons - the
// non-proficiency penalty applies only when using ninja weapons, all other
// weapons take the other class penalty (capture p. 99 of the print pass;
// compressed p. 52)
inline bool dhnNinjaNinjaWeaponsOnly()
    { return true; }

}   // namespace rules
