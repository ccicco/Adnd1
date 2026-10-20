// =========================================================================================
// Adnd1 - rules/oa70maneuvers.h
// OA TABLE 70, printed capture p. 227 - the martial arts special maneuvers
// round
// census 614 -> 615.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift. THE GRID: thirty-six maneuvers across the nine method
// columns - 1 Kick (Circle Kick 1, Flying Kick 2, Backward Kick 3), 2
// Movement the seven-deep column (Feint 1, Prone Fighting 2, Immovability 3,
// Missile Deflection 4, Leap 5, Speed 6, Slow Resistance 7), 3 Strike (Iron
// Fist 1, Crushing Blow 2, Eagle Claw 3), 4 Weapon (Weapon Catch 1, Weapon
// Breaker 2, Steel Cloth 3), 5 Lock (Choke Hold 1, Locking Block 2,
// Incapacitator 3, Immobilizing 4), 6 Throw (Fall 1, Instant Stand 2, Hurl 3,
// Great Throw 4), 7 Mental and Physical Training (Meditation 1, All-Around
// Sight 2, Mental Resistance 3, Blind Fighting 4, Ironskin 5, Levitation 6),
// 8 Push (Concentrated Push 1, Sticking Touch 2, One Finger 3), 9 Vital Area
// (Pain Touch 1, Stunning Touch 2, Paralyzing Touch 3). THE FORM TAGS coded 0
// hard, 1 soft, 2 hard/soft - the general classification of the fighting
// style, crossover allowed; the all-soft columns Push and Vital Area; the
// Strike column all hard; the Movement column all soft but Speed and Slow
// Resistance the hard/soft. THE RANKING: the lower number the easier to learn
// and execute, the progression from 1 on up, more than one maneuver allowed
// at the same difficulty - the printed Circle Kick 1, Flying Kick 2,
// All-Around Sight 2, Backward Kick 3 example; a higher maneuver learned only
// when those beneath it are learned. THE SELECTION: the 1d8 maneuvers of the
// principal method or the Training list, the second 1-3 roll from the other
// methods - the arsenal of tactics; the Training category learnable in any
// style; the maneuvers gained gradually per Learning Martial Arts. The grid
// codifies per the R431 calculus
//
// the gap census after this round: 145 closed, 90 open - the Table 70 box
// flips (census 614 -> 615); NEXT - R693: the Principal Methods prose
// (capture pp. 228-232), prefix djg (verify free at the landing), audit "R693
// OA principal methods audit", include after rules/oa70maneuvers.h
//
namespace rules {

// ---- the Table 70 special maneuvers grid ----

// the Table 70 method codes by row ordinal (print capture p. 227): 1 Kick, 2
// Movement, 3 Strike, 4 Weapon, 5 Lock, 6 Throw, 7 Mental and Physical
// Training, 8 Push, 9 Vital Area - the maneuvers grouped under the principal
// method of fighting used, the Training category learnable in any style
inline int djfOA70Method(int b)
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
            return 4;
        case 16:
            return 5;
        case 17:
            return 5;
        case 18:
            return 5;
        case 19:
            return 5;
        case 20:
            return 6;
        case 21:
            return 6;
        case 22:
            return 6;
        case 23:
            return 6;
        case 24:
            return 7;
        case 25:
            return 7;
        case 26:
            return 7;
        case 27:
            return 7;
        case 28:
            return 7;
        case 29:
            return 7;
        case 30:
            return 8;
        case 31:
            return 8;
        case 32:
            return 8;
        case 33:
            return 9;
        case 34:
            return 9;
        case 35:
            return 9;
        default:
            return 0;
        }
    }

// the Table 70 difficulty ranks by row ordinal (print capture p. 227): 1 the
// easiest, ranked per column with no gaps - Kick 1-3, Movement 1-7, Strike
// 1-3, Weapon 1-3, Lock 1-4, Throw 1-4, Training 1-6, Push 1-3, Vital Area
// 1-3; the progression from 1 on up, more than one maneuver at the same
// difficulty allowed, a higher maneuver learned only when those beneath it
// are learned
inline int djfOA70Rank(int b)
    {
        switch (b) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        case 3:
            return 1;
        case 4:
            return 2;
        case 5:
            return 3;
        case 6:
            return 4;
        case 7:
            return 5;
        case 8:
            return 6;
        case 9:
            return 7;
        case 10:
            return 1;
        case 11:
            return 2;
        case 12:
            return 3;
        case 13:
            return 1;
        case 14:
            return 2;
        case 15:
            return 3;
        case 16:
            return 1;
        case 17:
            return 2;
        case 18:
            return 3;
        case 19:
            return 4;
        case 20:
            return 1;
        case 21:
            return 2;
        case 22:
            return 3;
        case 23:
            return 4;
        case 24:
            return 1;
        case 25:
            return 2;
        case 26:
            return 3;
        case 27:
            return 4;
        case 28:
            return 5;
        case 29:
            return 6;
        case 30:
            return 1;
        case 31:
            return 2;
        case 32:
            return 3;
        case 33:
            return 1;
        case 34:
            return 2;
        case 35:
            return 3;
        default:
            return 0;
        }
    }

// the Table 70 form tags by row ordinal, coded (print capture p. 227): 0
// hard, 1 soft, 2 hard/soft - the general classification of the fighting
// style; Strike all hard, Push and Vital Area all soft, Movement soft but
// Speed and Slow Resistance hard/soft; the crossover between the styles
// allowed, the tag only the general type of maneuver each style uses
inline int djfOA70Form(int b)
    {
        switch (b) {
        case 0:
            return 0;
        case 1:
            return 0;
        case 2:
            return 2;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 1;
        case 8:
            return 2;
        case 9:
            return 2;
        case 10:
            return 0;
        case 11:
            return 0;
        case 12:
            return 0;
        case 13:
            return 2;
        case 14:
            return 2;
        case 15:
            return 1;
        case 16:
            return 2;
        case 17:
            return 1;
        case 18:
            return 2;
        case 19:
            return 2;
        case 20:
            return 2;
        case 21:
            return 2;
        case 22:
            return 0;
        case 23:
            return 1;
        case 24:
            return 2;
        case 25:
            return 1;
        case 26:
            return 1;
        case 27:
            return 1;
        case 28:
            return 0;
        case 29:
            return 1;
        case 30:
            return 1;
        case 31:
            return 1;
        case 32:
            return 1;
        case 33:
            return 1;
        case 34:
            return 1;
        case 35:
            return 1;
        default:
            return 0;
        }
    }

// the Table 70 maneuver count - the thirty-six ranked special maneuvers
// across the nine method columns, the loop bound of the emitted grid audit
// (print capture p. 227)
inline int djfOA70RowCount()
    { return 36; }

// the Kick column maneuver count - Circle Kick, Flying Kick, Backward Kick
// (print capture p. 227)
inline int djfOA70KickCount()
    { return 3; }

// the Movement column maneuver count - the deepest column of the table:
// Feint, Prone Fighting, Immovability, Missile Deflection, Leap, Speed, Slow
// Resistance (print capture p. 227)
inline int djfOA70MoveCount()
    { return 7; }

// the Strike column maneuver count - Iron Fist, Crushing Blow, Eagle Claw,
// all hard (print capture p. 227)
inline int djfOA70StrikeCount()
    { return 3; }

// the Weapon column maneuver count - Weapon Catch, Weapon Breaker, Steel
// Cloth (print capture p. 227)
inline int djfOA70WeaponCount()
    { return 3; }

// the Lock column maneuver count - Choke Hold, Locking Block, Incapacitator,
// Immobilizing (print capture p. 227)
inline int djfOA70LockCount()
    { return 4; }

// the Throw column maneuver count - Fall, Instant Stand, Hurl, Great Throw
// (print capture p. 227)
inline int djfOA70ThrowCount()
    { return 4; }

// the Mental and Physical Training column maneuver count - Meditation,
// All-Around Sight, Mental Resistance, Blind Fighting, Ironskin, Levitation,
// learnable in any style (print capture p. 227)
inline int djfOA70TrainCount()
    { return 6; }

// the Push column maneuver count - Concentrated Push, Sticking Touch, One
// Finger, all soft (print capture p. 227)
inline int djfOA70PushCount()
    { return 3; }

// the Vital Area column maneuver count - Pain Touch, Stunning Touch,
// Paralyzing Touch, all soft (print capture p. 227)
inline int djfOA70VitalCount()
    { return 3; }

}   // namespace rules
