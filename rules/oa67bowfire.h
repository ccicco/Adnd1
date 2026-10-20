// =========================================================================================
// Adnd1 - rules/oa67bowfire.h
// OA TABLE 67, printed capture p. 220 - the horseback bowfire modifiers round
// census 605 -> 606.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift. THE GRID: the animal's current movement read as eighths
// of its normal movement - less than 1/2 the -1, 1/2 to less than 3/4 the -3,
// 3/4 to maximum speed the -5 - the modifiers cumulative with those for
// range, weapon versus armor type, etc. THE TURN LIMIT: during the round in
// which he fires, the character cannot perform maneuvers with his mount
// except for slight turning - the most 30 degrees to either side of its
// current direction, sharper turns and maneuvers preventing the bowfire. THE
// HORSE-LIKE CLAUSE: the firing also performed mounted on any horse-like
// creature to which the horsemanship proficiency applies. The grid codifies
// per the R431 calculus
//
// the gap census after this round: 136 closed, 99 open - the Table 67 box
// flips (census 605 -> 606); NEXT - R684: the Unhorsing doctrine (capture p.
// 220), prefix dix (verify free at the landing - diu, div and diw TAKEN by
// the R681-R683 call families), audit "R684 OA unhorsing audit", include
// after rules/oa67bowfire.h
//
namespace rules {

// ---- the Table 67 horseback bowfire grid ----

// the Table 67 band floors in eighths of the animal's normal movement, by
// band ordinal (print capture p. 220): band 0 the less-than-half floor 0,
// band 1 the half floor 4, band 2 the three-quarters floor 6 - the printed
// bands read as eighths: less than 1/2, 1/2 to less than 3/4, 3/4 to maximum
// speed
inline int diwOA67MinEighths(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 4;
        case 2:
            return 6;
        default:
            return 0;
        }
    }

// the Table 67 band ceilings in eighths of the animal's normal movement, by
// band ordinal (print capture p. 220): band 0 the below-half ceiling 3, band
// 1 the below-three-quarters ceiling 5, band 2 the maximum-speed ceiling 8 -
// the full-speed band capping at the whole movement
inline int diwOA67MaxEighths(int b)
    {
        switch (b) {
        case 0:
            return 3;
        case 1:
            return 5;
        case 2:
            return 8;
        default:
            return 0;
        }
    }

// the Table 67 horseback bowfire to-hit modifiers by band ordinal (print
// capture p. 220): -1 below half speed, -3 from half to less than
// three-quarters, -5 from three-quarters to maximum speed - the modifiers
// deepening with the speed of the animal, cumulative with the range and
// weapon versus armor modifiers
inline int diwOA67Modifier(int b)
    {
        switch (b) {
        case 0:
            return -1;
        case 1:
            return -3;
        case 2:
            return -5;
        default:
            return 0;
        }
    }

// ---- the Table 67 prose pins ----

// the maneuver limit - during the round in which he fires, the character
// cannot perform maneuvers with his mount except for slight turning, the most
// the horse can be turned being 30 degrees to either side of its current
// direction (print capture p. 220)
inline int diwOA67TurnDegrees()
    { return 30; }

// the Table 67 band count - the three speed bands of the horseback bowfire
// grid, the loop bound of the emitted grid audit (print capture p. 220)
inline int diwOA67BandCount()
    { return 3; }

// the cumulative clause - the horseback bowfire modifiers are cumulative with
// those for range, weapon versus armor type, etc. (print capture p. 220)
inline bool diwOA67CumulativeModifiers()
    { return true; }

// the sharper-turns rule - sharper turns and maneuvers prevent the character
// from firing his bow (print capture p. 220)
inline bool diwOA67SharperTurnsPreventFire()
    { return true; }

// the horse-like clause - firing from horseback can also be performed while
// mounted on any horse-like creature to which the horsemanship proficiency
// also applies (print capture p. 220)
inline bool diwOA67HorseLikeCreaturesApply()
    { return true; }

}   // namespace rules
