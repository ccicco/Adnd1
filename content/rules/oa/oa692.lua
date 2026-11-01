-- oa692: promoted from rules/oa70maneuvers.h (the OA TABLE 70, printed capture p. 227 - the martial arts special maneuvers);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 692,
  "prefix" = "oa692",
  "banner" = {
      "title" = "OA TABLE 70, printed capture p. 227 - the martial arts special maneuvers",
      "provenance" = "round census 614 -> 615.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift. THE GRID: thirty-six maneuvers across the nine method columns - 1 Kick (Circle Kick 1, Flying Kick 2, Backward Kick 3), 2 Movement the seven-deep column (Feint 1, Prone Fighting 2, Immovability 3, Missile Deflection 4, Leap 5, Speed 6, Slow Resistance 7), 3 Strike (Iron Fist 1, Crushing Blow 2, Eagle Claw 3), 4 Weapon (Weapon Catch 1, Weapon Breaker 2, Steel Cloth 3), 5 Lock (Choke Hold 1, Locking Block 2, Incapacitator 3, Immobilizing 4), 6 Throw (Fall 1, Instant Stand 2, Hurl 3, Great Throw 4), 7 Mental and Physical Training (Meditation 1, All-Around Sight 2, Mental Resistance 3, Blind Fighting 4, Ironskin 5, Levitation 6), 8 Push (Concentrated Push 1, Sticking Touch 2, One Finger 3), 9 Vital Area (Pain Touch 1, Stunning Touch 2, Paralyzing Touch 3). THE FORM TAGS coded 0 hard, 1 soft, 2 hard/soft - the general classification of the fighting style, crossover allowed; the all-soft columns Push and Vital Area; the Strike column all hard; the Movement column all soft but Speed and Slow Resistance the hard/soft. THE RANKING: the lower number the easier to learn and execute, the progression from 1 on up, more than one maneuver allowed at the same difficulty - the printed Circle Kick 1, Flying Kick 2, All-Around Sight 2, Backward Kick 3 example; a higher maneuver learned only when those beneath it are learned. THE SELECTION: the 1d8 maneuvers of the principal method or the Training list, the second 1-3 roll from the other methods - the arsenal of tactics; the Training category learnable in any style; the maneuvers gained gradually per Learning Martial Arts. The grid codifies per the R431 calculus  the gap census after this round: 145 closed, 90 open - the Table 70 box flips (census 614 -> 615); NEXT - R693: the Principal Methods prose (capture pp. 228-232), prefix djg (verify free at the landing), audit \"R693 OA principal methods audit\", include after rules/oa70maneuvers.h",
    },
  "consts" = { {
      "name" = "djfOA70RowCount",
      "value" = 36,
      "comment" = "the Table 70 maneuver count - the thirty-six ranked special maneuvers across the nine method columns, the loop bound of the emitted grid audit (print capture p. 227)",
    }, {
      "name" = "djfOA70KickCount",
      "value" = 3,
      "comment" = "the Kick column maneuver count - Circle Kick, Flying Kick, Backward Kick (print capture p. 227)",
    }, {
      "name" = "djfOA70MoveCount",
      "value" = 7,
      "comment" = "the Movement column maneuver count - the deepest column of the table: Feint, Prone Fighting, Immovability, Missile Deflection, Leap, Speed, Slow Resistance (print capture p. 227)",
    }, {
      "name" = "djfOA70StrikeCount",
      "value" = 3,
      "comment" = "the Strike column maneuver count - Iron Fist, Crushing Blow, Eagle Claw, all hard (print capture p. 227)",
    }, {
      "name" = "djfOA70WeaponCount",
      "value" = 3,
      "comment" = "the Weapon column maneuver count - Weapon Catch, Weapon Breaker, Steel Cloth (print capture p. 227)",
    }, {
      "name" = "djfOA70LockCount",
      "value" = 4,
      "comment" = "the Lock column maneuver count - Choke Hold, Locking Block, Incapacitator, Immobilizing (print capture p. 227)",
    }, {
      "name" = "djfOA70ThrowCount",
      "value" = 4,
      "comment" = "the Throw column maneuver count - Fall, Instant Stand, Hurl, Great Throw (print capture p. 227)",
    }, {
      "name" = "djfOA70TrainCount",
      "value" = 6,
      "comment" = "the Mental and Physical Training column maneuver count - Meditation, All-Around Sight, Mental Resistance, Blind Fighting, Ironskin, Levitation, learnable in any style (print capture p. 227)",
    }, {
      "name" = "djfOA70PushCount",
      "value" = 3,
      "comment" = "the Push column maneuver count - Concentrated Push, Sticking Touch, One Finger, all soft (print capture p. 227)",
    }, {
      "name" = "djfOA70VitalCount",
      "value" = 3,
      "comment" = "the Vital Area column maneuver count - Pain Touch, Stunning Touch, Paralyzing Touch, all soft (print capture p. 227)",
    } },
  "bools" = {},
  "switches" = { {
      "name" = "djfOA70Method",
      "values" = { 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9 },
      "default" = 0,
      "comment" = "the Table 70 method codes by row ordinal (print capture p. 227): 1 Kick, 2 Movement, 3 Strike, 4 Weapon, 5 Lock, 6 Throw, 7 Mental and Physical Training, 8 Push, 9 Vital Area - the maneuvers grouped under the principal method of fighting used, the Training category learnable in any style",
    }, {
      "name" = "djfOA70Rank",
      "values" = { 1, 2, 3, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 5, 6, 1, 2, 3, 1, 2, 3 },
      "default" = 0,
      "comment" = "the Table 70 difficulty ranks by row ordinal (print capture p. 227): 1 the easiest, ranked per column with no gaps - Kick 1-3, Movement 1-7, Strike 1-3, Weapon 1-3, Lock 1-4, Throw 1-4, Training 1-6, Push 1-3, Vital Area 1-3; the progression from 1 on up, more than one maneuver at the same difficulty allowed, a higher maneuver learned only when those beneath it are learned",
    }, {
      "name" = "djfOA70Form",
      "values" = { 0, 0, 2, 2, 1, 1, 1, 1, 2, 2, 0, 0, 0, 2, 2, 1, 2, 1, 2, 2, 2, 2, 0, 1, 2, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
      "default" = 0,
      "comment" = "the Table 70 form tags by row ordinal, coded (print capture p. 227): 0 hard, 1 soft, 2 hard/soft - the general classification of the fighting style; Strike all hard, Push and Vital Area all soft, Movement soft but Speed and Slow Resistance hard/soft; the crossover between the styles allowed, the tag only the general type of maneuver each style uses",
    } },
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['djfOA70RowCount']() != 36  or m['djfOA70KickCount']() != 3  or m['djfOA70MoveCount']() != 7  or m['djfOA70StrikeCount']() != 3  or m['djfOA70WeaponCount']() != 3  or m['djfOA70LockCount']() != 4  or m['djfOA70ThrowCount']() != 4  or m['djfOA70TrainCount']() != 6  or m['djfOA70PushCount']() != 3  or m['djfOA70VitalCount']() != 3",
      "note" = "",
    }, {
      "expr" = "m['djfOA70Method'](0) != 1  or m['djfOA70Rank'](0) != 1  or m['djfOA70Form'](0) != 0  or m['djfOA70Rank'](1) != 2  or m['djfOA70Form'](1) != 0  or m['djfOA70Rank'](2) != 3  or m['djfOA70Form'](2) != 2",
      "note" = "the Kick column - Circle Kick 1 hard, Flying Kick 2 hard, Backward Kick 3 hard/soft",
    }, {
      "expr" = "m['djfOA70Method'](3) != 2  or m['djfOA70Method'](9) != 2  or m['djfOA70Rank'](3) != 1  or m['djfOA70Rank'](9) != 7  or m['djfOA70Form'](3) != 2  or m['djfOA70Form'](6) != 1  or m['djfOA70Form'](8) != 2  or m['djfOA70Form'](9) != 2",
      "note" = "the Movement column - seven deep, Feint 1 hard/soft through Slow Resistance 7 hard/soft, the Missile Deflection 4 soft",
    }, {
      "expr" = "m['djfOA70Method'](10) != 3  or m['djfOA70Form'](10) != 0  or m['djfOA70Form'](11) != 0  or m['djfOA70Form'](12) != 0  or m['djfOA70Rank'](12) != 3",
      "note" = "the Strike column - all three maneuvers hard",
    }, {
      "expr" = "m['djfOA70Method'](13) != 4  or m['djfOA70Form'](13) != 2  or m['djfOA70Form'](14) != 2  or m['djfOA70Rank'](14) != 2  or m['djfOA70Form'](15) != 1",
      "note" = "the Weapon column - Weapon Catch and Weapon Breaker hard/soft, Steel Cloth soft",
    }, {
      "expr" = "m['djfOA70Method'](16) != 5  or m['djfOA70Rank'](16) != 1  or m['djfOA70Rank'](19) != 4  or m['djfOA70Form'](17) != 1  or m['djfOA70Form'](19) != 2",
      "note" = "the Lock column - Choke Hold 1 through Immobilizing 4, Locking Block the soft",
    }, {
      "expr" = "m['djfOA70Method'](20) != 6  or m['djfOA70Rank'](21) != 2  or m['djfOA70Form'](22) != 0  or m['djfOA70Form'](23) != 1  or m['djfOA70Rank'](23) != 4",
      "note" = "the Throw column - Fall 1 and Instant Stand 2 hard/soft, Hurl 3 hard, Great Throw 4 soft",
    }, {
      "expr" = "m['djfOA70Method'](24) != 7  or m['djfOA70Rank'](24) != 1  or m['djfOA70Rank'](29) != 6  or m['djfOA70Form'](25) != 1  or m['djfOA70Form'](28) != 0  or m['djfOA70Form'](29) != 1",
      "note" = "the Mental and Physical Training column - Meditation 1 through Levitation 6, All-Around Sight 2 soft, Ironskin 5 the hard",
    }, {
      "expr" = "m['djfOA70Method'](30) != 8  or m['djfOA70Form'](30) != 1  or m['djfOA70Form'](31) != 1  or m['djfOA70Form'](32) != 1  or m['djfOA70Method'](33) != 9  or m['djfOA70Rank'](35) != 3  or m['djfOA70Form'](35) != 1",
      "note" = "the Push and Vital Area columns - all six maneuvers soft, the Vital ranks 1-3",
    }, {
      "expr" = "m['djfOA70KickCount']() != 3  or m['djfOA70MoveCount']() != 7  or m['djfOA70ThrowCount']() != 4  or m['djfOA70TrainCount']() != 6  or m['djfOA70VitalCount']() != 3  or m['djfOA70RowCount']() != 36",
      "note" = "the per-method counts - Kick 3, Movement 7, Throw 4, Training 6, Vital Area 3, the grid the 36",
    }, {
      "expr" = "m['djfOA70Rank'](0) != 1  or m['djfOA70Rank'](1) != 2  or m['djfOA70Rank'](25) != 2  or m['djfOA70Rank'](2) != 3",
      "note" = "the printed progression example - Circle Kick 1, Flying Kick 2, All-Around Sight 2, Backward Kick 3",
    } },
  "audit" = {
      "label" = "R692 OA special maneuvers audit",
      "comment" = "OA round seventy-nine (capture p. 227): Table 70 - the martial arts special maneuvers grid, the thirty-six ranked maneuvers across the nine method columns with the hard, soft and hard/soft form tags, single-pass pins per the Chapter 9 provenance shift",
    },
}
