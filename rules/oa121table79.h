// =========================================================================================
// Adnd1 - rules/oa121table79.h
// OA TREASURE - TABLE 79, WEAPON PROPERTIES, printed capture pp. 291-292 -
// the property grid round
// census 672 -> 673.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift
//
// the gap census after this round: 203 closed, 32 open - the Table 79 box
// flips (census 672 -> 673); NEXT - R751: Table 80: Sword Class (capture p.
// 292), prefix dlm (verify free at the landing), audit "R751 OA Table 80
// sword audit", include after rules/oa121table79.h
//
namespace rules {

// ---- the Table 79 grid ----

// the property row count - the twenty d100 bands of the Table 79 property
// grid (print capture p. 291)
inline int dllPropRowCount()
    { return 20; }

// the d100 band minimum - the low roll of the row (print capture p. 291)
inline int dllPropRollMin(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 6;
        case 2:
            return 11;
        case 3:
            return 16;
        case 4:
            return 21;
        case 5:
            return 26;
        case 6:
            return 31;
        case 7:
            return 36;
        case 8:
            return 41;
        case 9:
            return 46;
        case 10:
            return 51;
        case 11:
            return 56;
        case 12:
            return 61;
        case 13:
            return 66;
        case 14:
            return 71;
        case 15:
            return 76;
        case 16:
            return 81;
        case 17:
            return 86;
        case 18:
            return 91;
        case 19:
            return 96;
        default:
            return 0;
        }
    }

// the d100 band maximum - the high roll of the row (print capture p. 292)
inline int dllPropRollMax(int b)
    {
        switch (b) {
        case 0:
            return 5;
        case 1:
            return 10;
        case 2:
            return 15;
        case 3:
            return 20;
        case 4:
            return 25;
        case 5:
            return 30;
        case 6:
            return 35;
        case 7:
            return 40;
        case 8:
            return 45;
        case 9:
            return 50;
        case 10:
            return 55;
        case 11:
            return 60;
        case 12:
            return 65;
        case 13:
            return 70;
        case 14:
            return 75;
        case 15:
            return 80;
        case 16:
            return 85;
        case 17:
            return 90;
        case 18:
            return 95;
        case 19:
            return 100;
        default:
            return 0;
        }
    }

// the bow column code (1 the quality; 2 the +1; 3 the +2; 4 the +3; 5 the +1
// to hit; 6 the +2 to hit; 7 the +3 to hit; 8 the +1 damage; 9 the +2 damage;
// 10 the +3 damage; 11 the +1, +2 versus smaller than man-sized; 12 the +1,
// +2 versus larger than man-sized; 13 the -1, cursed; 14 the speed; 15 the
// detection; 16 the dancing; 17 the balance; 18 the distance +1; 19 the
// disruption; 20 the unbreakable; 21 the flame; 22 the accuracy +3; 23 the
// venom; 24 the slaying; 25 the intelligence; 26 the roll twice) (print
// capture p. 291)
inline int dllPropBow(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 5;
        case 7:
            return 5;
        case 8:
            return 5;
        case 9:
            return 5;
        case 10:
            return 5;
        case 11:
            return 6;
        case 12:
            return 6;
        case 13:
            return 7;
        case 14:
            return 2;
        case 15:
            return 3;
        case 16:
            return 13;
        case 17:
            return 18;
        case 18:
            return 22;
        case 19:
            return 14;
        default:
            return 0;
        }
    }

// the missile column code (1 the quality; 2 the +1; 3 the +2; 4 the +3; 5 the
// +1 to hit; 6 the +2 to hit; 7 the +3 to hit; 8 the +1 damage; 9 the +2
// damage; 10 the +3 damage; 11 the +1, +2 versus smaller than man-sized; 12
// the +1, +2 versus larger than man-sized; 13 the -1, cursed; 14 the speed;
// 15 the detection; 16 the dancing; 17 the balance; 18 the distance +1; 19
// the disruption; 20 the unbreakable; 21 the flame; 22 the accuracy +3; 23
// the venom; 24 the slaying; 25 the intelligence; 26 the roll twice) (print
// capture p. 291)
inline int dllPropMissile(int b)
    {
        switch (b) {
        case 0:
            return 8;
        case 1:
            return 8;
        case 2:
            return 8;
        case 3:
            return 8;
        case 4:
            return 8;
        case 5:
            return 8;
        case 6:
            return 8;
        case 7:
            return 8;
        case 8:
            return 8;
        case 9:
            return 9;
        case 10:
            return 9;
        case 11:
            return 9;
        case 12:
            return 9;
        case 13:
            return 9;
        case 14:
            return 10;
        case 15:
            return 2;
        case 16:
            return 2;
        case 17:
            return 3;
        case 18:
            return 4;
        case 19:
            return 24;
        default:
            return 0;
        }
    }

// the melee column code (1 the quality; 2 the +1; 3 the +2; 4 the +3; 5 the
// +1 to hit; 6 the +2 to hit; 7 the +3 to hit; 8 the +1 damage; 9 the +2
// damage; 10 the +3 damage; 11 the +1, +2 versus smaller than man-sized; 12
// the +1, +2 versus larger than man-sized; 13 the -1, cursed; 14 the speed;
// 15 the detection; 16 the dancing; 17 the balance; 18 the distance +1; 19
// the disruption; 20 the unbreakable; 21 the flame; 22 the accuracy +3; 23
// the venom; 24 the slaying; 25 the intelligence; 26 the roll twice) (print
// capture p. 291)
inline int dllPropMelee(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 3;
        case 11:
            return 3;
        case 12:
            return 3;
        case 13:
            return 4;
        case 14:
            return 4;
        case 15:
            return 11;
        case 16:
            return 12;
        case 17:
            return 19;
        case 18:
            return 13;
        case 19:
            return 25;
        default:
            return 0;
        }
    }

// the martial arts column code (1 the quality; 2 the +1; 3 the +2; 4 the +3;
// 5 the +1 to hit; 6 the +2 to hit; 7 the +3 to hit; 8 the +1 damage; 9 the
// +2 damage; 10 the +3 damage; 11 the +1, +2 versus smaller than man-sized;
// 12 the +1, +2 versus larger than man-sized; 13 the -1, cursed; 14 the
// speed; 15 the detection; 16 the dancing; 17 the balance; 18 the distance
// +1; 19 the disruption; 20 the unbreakable; 21 the flame; 22 the accuracy
// +3; 23 the venom; 24 the slaying; 25 the intelligence; 26 the roll twice)
// (print capture p. 292)
inline int dllPropMartialArts(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 1;
        case 4:
            return 1;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 2;
        case 11:
            return 3;
        case 12:
            return 3;
        case 13:
            return 3;
        case 14:
            return 4;
        case 15:
            return 14;
        case 16:
            return 16;
        case 17:
            return 20;
        case 18:
            return 20;
        case 19:
            return 26;
        default:
            return 0;
        }
    }

// the ninja column code (1 the quality; 2 the +1; 3 the +2; 4 the +3; 5 the
// +1 to hit; 6 the +2 to hit; 7 the +3 to hit; 8 the +1 damage; 9 the +2
// damage; 10 the +3 damage; 11 the +1, +2 versus smaller than man-sized; 12
// the +1, +2 versus larger than man-sized; 13 the -1, cursed; 14 the speed;
// 15 the detection; 16 the dancing; 17 the balance; 18 the distance +1; 19
// the disruption; 20 the unbreakable; 21 the flame; 22 the accuracy +3; 23
// the venom; 24 the slaying; 25 the intelligence; 26 the roll twice) (print
// capture p. 292)
inline int dllPropNinja(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 2;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 3;
        case 9:
            return 3;
        case 10:
            return 3;
        case 11:
            return 3;
        case 12:
            return 4;
        case 13:
            return 4;
        case 14:
            return 4;
        case 15:
            return 15;
        case 16:
            return 17;
        case 17:
            return 21;
        case 18:
            return 23;
        case 19:
            return 26;
        default:
            return 0;
        }
    }

// ---- the column walk ----

// the bow column - the weapon type of the first column, the quality through
// the speed (print capture p. 291)
inline int dllBowColumn()
    { return 1; }

// the missile column - the weapon type of the second column, the damage
// pluses through the slaying (print capture p. 291)
inline int dllMissileColumn()
    { return 1; }

// the melee column - the weapon type of the third column, the quality through
// the intelligence (print capture p. 291)
inline int dllMeleeColumn()
    { return 1; }

// the martial arts column - the weapon type of the fourth column, the quality
// through the roll twice (print capture p. 292)
inline int dllMartialArtsColumn()
    { return 1; }

// the ninja column - the weapon type of the fifth column, the quality through
// the roll twice (print capture p. 292)
inline int dllNinjaColumn()
    { return 1; }

// the roll twice tails - the 96-100 martial arts and ninja cells rolling
// twice on the same grid (print capture p. 292)
inline int dllRollTwiceTails()
    { return 1; }

}   // namespace rules
