// =========================================================================================
// Adnd1 - rules/oa69combos.h
// OA TABLE 69, printed capture p. 226 - the martial style combinations round
// census 613 -> 614.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift. THE FORM ROWS: Hard the AC 1, attack 1, damage 4 - the
// muscles and bones for power; Soft the AC 3, attack 0 - the only zero of the
// grid, damage 2 - the inner power; Hard/Soft the 2/1/3 of the best practices
// from each. THE METHOD ROWS: Kick the 1/1/4 of the Foot; Lock the 1/1/2 of
// the Body; Movement the 2/1/2 of the Legs; Push the 2/1/1 of the Hand;
// Strike the 1/1/1 of the Hand; Throw the 1/1/2 of the whole Body; Vital Area
// the 2/1/1 of the Hand and Foot; Weapon the 1/1 of the Hand and Arm, the
// damage BY WEAPON - pinned 0, not a mod, the R662 convention. THE USE: the
// mods totaled per the R690 mechanics - the AC from the 10, the attacks
// style-specific, the damage rounded up to the die, the body part free; the
// derived examples prove it within the round - Hard plus Kick the AC 8,
// attacks 2, damage 8; Soft plus Movement the damage 4. The grid codifies per
// the R431 calculus
//
// the gap census after this round: 144 closed, 91 open - the Table 69 box
// flips (census 613 -> 614); NEXT - R692: Table 70 the martial arts special
// maneuvers grid (capture p. 227), prefix djf (verify free at the landing),
// audit "R692 OA special maneuvers audit", include after rules/oa69combos.h
//
namespace rules {

// ---- the Table 69 combinations grid ----

// the Table 69 armor class mods by row ordinal (print capture p. 226): rows
// 0-2 the forms - Hard 1, Soft 3, Hard/Soft 2; rows 3-10 the methods - Kick
// 1, Lock 1, Movement 2, Push 2, Strike 1, Throw 1, Vital Area 2, Weapon 1;
// the AC of a style 10 minus the totaled form and method mods
inline int djeOA69ACMod(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 3;
        case 2:
            return 2;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 2;
        case 10:
            return 1;
        default:
            return 0;
        }
    }

// the Table 69 attack mods by row ordinal (print capture p. 226): the forms -
// Hard 1, Soft 0 - the only zero of the grid, Hard/Soft 1; every method a 1;
// the number of attacks the totaled form and method mods
inline int djeOA69AtMod(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 1;
        case 9:
            return 1;
        case 10:
            return 1;
        default:
            return 0;
        }
    }

// the Table 69 damage mods by row ordinal (print capture p. 226): the forms -
// Hard 4, Soft 2, Hard/Soft 3; the methods - Kick 4, Lock 2, Movement 2, Push
// 1, Strike 1, Throw 2, Vital Area 1; the Weapon row a 0 - the printed damage
// BY WEAPON, not a mod, the R662 convention; the damage the totaled mods
// rounded up to the nearest die - 6 the 1d6, 4 the 1d4, 5 the 1d6
inline int djeOA69DamageMod(int b)
    {
        switch (b) {
        case 0:
            return 4;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 4;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 1;
        case 10:
            return 0;
        default:
            return 0;
        }
    }

// the Table 69 body parts by row ordinal, coded (print capture p. 226): 0
// none - the form rows printed a dash; 1 Foot (Kick), 2 Body (Lock and
// Throw), 3 Legs (Movement), 4 Hand (Push and Strike), 5 Hand and Foot (Vital
// Area), 6 Hand and Arm (Weapon); kicking the feet, throwing the whole body,
// the attacks effective so long as the part is unbound or free to move
inline int djeOA69BodyPart(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 4;
        case 7:
            return 4;
        case 8:
            return 2;
        case 9:
            return 5;
        case 10:
            return 6;
        default:
            return 0;
        }
    }

// the Table 69 row count - the three form rows and the eight principal method
// rows, the loop bound of the emitted grid audit (print capture p. 226)
inline int djeOA69RowCount()
    { return 11; }

}   // namespace rules
