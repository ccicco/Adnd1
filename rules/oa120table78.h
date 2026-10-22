// =========================================================================================
// Adnd1 - rules/oa120table78.h
// OA TREASURE - TABLE 78, MAGICAL WEAPONS, printed capture p. 291 - the
// weapon class grid round
// census 671 -> 672.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 202 closed, 33 open - the Table 78 box
// flips (census 671 -> 672); NEXT - R750: Table 79: Weapon Properties
// (capture p. 291, the grid runs onto p. 292), prefix dll (verify free at the
// landing), audit "R750 OA Table 79 properties audit", include after
// rules/oa120table78.h
//
namespace rules {

// ---- the Table 78 grid ----

// the class row count - the six d100 bands of the Table 78 weapon class grid
// (print capture p. 291)
inline int dlkClassRowCount()
    { return 6; }

// the d100 band minimum - the low roll of the row (print capture p. 291)
inline int dlkClassRollMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 41;
        case 2:
            return 53;
        case 3:
            return 69;
        case 4:
            return 81;
        case 5:
            return 91;
        default:
            return 0;
        }
    }

// the d100 band maximum - the high roll of the row (print capture p. 291)
inline int dlkClassRollMax(int b)
    {
        switch (b) {
        case 0:
            return 40;
        case 1:
            return 52;
        case 2:
            return 68;
        case 3:
            return 80;
        case 4:
            return 90;
        case 5:
            return 100;
        default:
            return 0;
        }
    }

// the weapon class code - 1 the sword; 2 the bow, crossbow, or sling; 3 the
// miscellaneous melee weapon; 4 the missile weapon; 5 the martial arts
// weapon; 6 the ninja weapon (print capture p. 291)
inline int dlkClassCode(int b)
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
        default:
            return 0;
        }
    }

// ---- the class walk ----

// the sword class - the 01-40 band rolling on the Table 80 Sword Class (print
// capture p. 291)
inline int dlkSwordClass()
    { return 1; }

// the bow class - the 41-52 band of the bow, crossbow, or sling, rolling on
// the Table 81 (print capture p. 291)
inline int dlkBowCrossbowSlingClass()
    { return 1; }

// the miscellaneous melee class - the 53-68 band rolling on the Table 82
// (print capture p. 291)
inline int dlkMiscMeleeClass()
    { return 1; }

// the missile class - the 69-80 band rolling on the Table 83 (print capture
// p. 291)
inline int dlkMissileClass()
    { return 1; }

// the martial arts class - the 81-90 band rolling on the Table 84 (print
// capture p. 291)
inline int dlkMartialArtsClass()
    { return 1; }

// the ninja class - the 91-100 band rolling on the Table 85 (print capture p.
// 291)
inline int dlkNinjaClass()
    { return 1; }

}   // namespace rules
