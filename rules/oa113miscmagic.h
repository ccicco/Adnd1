// =========================================================================================
// Adnd1 - rules/oa113miscmagic.h
// OA TREASURE - MISCELLANEOUS MAGIC, printed capture pp. 288-289 - the misc
// item notes round
// census 664 -> 665.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 195 closed, 40 open - the misc magic box
// flips (census 664 -> 665); NEXT - R743: Armor and Shield prose (capture pp.
// 289-291), prefix dle (verify free at the landing), audit "R743 OA armor
// shield audit", include after rules/oa113miscmagic.h
//
namespace rules {

// ---- the rerolled items ----

// the boots of elvenkind - not commonly available in Oriental lands, the
// result rerolled (print capture p. 288)
inline int dldBootsOfElvenkindRerolled()
    { return 1; }

// the broom of animated attack - not commonly available in Oriental lands,
// the result rerolled (print capture p. 288)
inline int dldBroomOfAnimatedAttackRerolled()
    { return 1; }

// the broom of flying - not commonly available in Oriental lands, the result
// rerolled (print capture p. 288)
inline int dldBroomOfFlyingRerolled()
    { return 1; }

// the cloak of elvenkind - not common to Oriental lands, the result rerolled
// (print capture p. 289)
inline int dldCloakOfElvenkindRerolled()
    { return 1; }

// the instruments of the bards - not found in Oriental lands, the result
// rerolled (print capture p. 289)
inline int dldInstrumentsOfTheBardsRerolled()
    { return 1; }

// the manual of golems - the magical book not found in Oriental lands, the
// result rerolled (print capture p. 289)
inline int dldManualOfGolemsRerolled()
    { return 1; }

// ---- the everful purse ----

// the everful purse - when opened, the purse will contain the table (print
// capture p. 288)
inline int dldEverfulPurseIntro()
    { return 1; }

// the purse row count - the three d100 bands of the everful purse contents
// (print capture p. 289)
inline int dldPurseRowCount()
    { return 3; }

// the d100 band minimum - the low roll of the row (print capture p. 289)
inline int dldPurseRollMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 51;
        case 2:
            return 91;
        default:
            return 0;
        }
    }

// the d100 band maximum - the high roll of the row (print capture p. 289)
inline int dldPurseRollMax(int b)
    {
        switch (b) {
        case 0:
            return 50;
        case 1:
            return 90;
        case 2:
            return 100;
        default:
            return 0;
        }
    }

// the fen count - the 20 of the 51-100 rows, the 0 the nil (print capture p.
// 289)
inline int dldPurseFen(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 20;
        case 2:
            return 20;
        default:
            return 0;
        }
    }

// the yuan count - the 10 of the 01-50 row, the 0 the nil (print capture p.
// 289)
inline int dldPurseYuan(int b)
    {
        switch (b) {
        case 0:
            return 10;
        case 1:
            return 0;
        case 2:
            return 0;
        default:
            return 0;
        }
    }

// the tael count - the 5 of every row (print capture p. 289)
inline int dldPurseTael(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 5;
        case 2:
            return 5;
        default:
            return 0;
        }
    }

// the ch'ien count - the 1 and 2 of the first two rows, the 0 the nil of the
// 91-100 (print capture p. 289)
inline int dldPurseChien(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 0;
        default:
            return 0;
        }
    }

// the gems count - the 10 of the 91-100 row, the 0 the nil (print capture p.
// 289)
inline int dldPurseGems(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 10;
        default:
            return 0;
        }
    }

}   // namespace rules
