-- oa689: promoted from rules/oa68styles.h (the OA TABLE 68, printed capture pp. 224-225 - the common martial styles round);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 689,
  "prefix" = "oa689",
  "banner" = {
      "title" = "OA TABLE 68, printed capture pp. 224-225 - the common martial styles round",
      "provenance" = "census 611 -> 612.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift. THE GRID: the four common styles - Karate the 3/1 at the d6 and AC 8, Hand principal, six maneuver ranks (Strike 1,2,3, Kick 1, Movement 1, Mental 1); Kung-fu the 2/1 at the d6 and AC 6 - the most protective, Hand, eight ranks (Lock 1,2,3, Strike 1,2, Kick 2, Movement 4, Mental 5); Tae Kwon Do the 1/1 at the lone d8 and AC 8, the only Foot principal, six ranks (Kick 1,2,3, Strike 1, Throw 4, Movement 5); Jujutsu the 2/1 at the d6 and AC 7, Hand, the eleven ranks - the most maneuver-rich (Throw 1,2,3,4, Movement 1,3, Vital Area 1,2, Mental 1,2,3). THE PROSE: the attacks style-dependent and possibly different from weapons; the defensive styles low damage; the AC born of the training; the principal form free so long as the body part is - the Karate fist with legs held; the maneuvers the secrets of the art. The grid codifies per the R431 calculus  the gap census after this round: 142 closed, 93 open - the Table 68 box flips (census 611 -> 612); NEXT - R690: the Creating a Style doctrine (capture pp. 225-228), prefix djd (verify free at the landing), audit \"R690 OA creating a style audit\", include after rules/oa68styles.h",
    },
  "consts" = { {
      "name" = "djcOA68StyleCount",
      "value" = 4,
      "comment" = "the Table 68 style count - the four common martial styles (Karate, Kung-fu, Tae Kwon Do, Jujutsu), the loop bound of the emitted grid audit (print capture p. 224)",
    } },
  "bools" = { {
      "name" = "djcOA68AttacksStyleDependent",
      "value" = true,
      "comment" = "the attacks explanation - the number of attacks depends on the style used and may differ from the number of attacks with weapons, a character's ability to attack able to increase, decrease or remain the same when using martial arts (print capture p. 225)",
    }, {
      "name" = "djcOA68DamageDefensiveLow",
      "value" = true,
      "comment" = "the damage explanation - the damage die rolled to determine the effect of a hit, the defensive styles generally doing low damage, the offensive the opposite (print capture p. 225)",
    }, {
      "name" = "djcOA68ACFromTraining",
      "value" = true,
      "comment" = "the armor class explanation - a measure of the degree of protection the character gains when using the style, the protection coming from the training that allows him to avoid, deflect or withstand blows (print capture p. 225)",
    }, {
      "name" = "djcOA68PrincipalBodyPartFree",
      "value" = true,
      "comment" = "the principal attack form explanation - the part or parts of body most often used, the attacks continuing so long as the listed body part is free - Karate emphasizing the fist, the character attacking even though his legs may be held (print capture p. 225)",
    }, {
      "name" = "djcOA68ManeuversSecrets",
      "value" = true,
      "comment" = "the special maneuvers explanation - the secrets of the art allowing fantastic feats but difficult to learn: Backward Kick, Sticking Touch, Great Throw, Ironskin and other normally impossible abilities (print capture p. 225)",
    } },
  "switches" = { {
      "name" = "djcOA68AtkNum",
      "values" = { 3, 2, 1, 2 },
      "default" = 0,
      "comment" = "the Table 68 attacks numerators by style ordinal (print capture p. 224): the styles read 1 Karate, 2 Kung-fu, 3 Tae Kwon Do, 4 Jujutsu - the 3/1, 2/1, 1/1 and 2/1 rates of the four common styles",
    }, {
      "name" = "djcOA68AtkDen",
      "values" = { 1, 1, 1, 1 },
      "default" = 0,
      "comment" = "the Table 68 attacks denominators by style ordinal (print capture p. 224): every common style a per-round rate, all four denominators the 1",
    }, {
      "name" = "djcOA68DmgDie",
      "values" = { 6, 6, 8, 6 },
      "default" = 0,
      "comment" = "the Table 68 damage dice by style ordinal (print capture p. 224): Karate the d6, Kung-fu the d6, Tae Kwon Do the d8 - the only d8, Jujutsu the d6",
    }, {
      "name" = "djcOA68AC",
      "values" = { 8, 6, 8, 7 },
      "default" = 0,
      "comment" = "the Table 68 armor classes by style ordinal (print capture p. 224): Karate 8, Kung-fu 6 - the best, Tae Kwon Do 8, Jujutsu 7; the lower the better, Kung-fu the most protective style",
    }, {
      "name" = "djcOA68Principal",
      "values" = { 1, 1, 2, 1 },
      "default" = 0,
      "comment" = "the Table 68 principal attack forms by style ordinal (print capture p. 224): 1 Hand, 2 Foot - Karate the Hand, Kung-fu the Hand, Tae Kwon Do the Foot - the only Foot style, Jujutsu the Hand",
    }, {
      "name" = "djcOA68ManeuverRanks",
      "values" = { 6, 8, 6, 11 },
      "default" = 0,
      "comment" = "the Table 68 special maneuver rank counts by style ordinal (print capture p. 224) - the number of listed maneuver ranks: Karate Strike 1,2,3 + Kick 1 + Movement 1 + Mental 1 = 6; Kung-fu Lock 1,2,3 + Strike 1,2 + Kick 2 + Movement 4 + Mental 5 = 8; Tae Kwon Do Kick 1,2,3 + Strike 1 + Throw 4 + Movement 5 = 6; Jujutsu Throw 1,2,3,4 + Movement 1,3 + Vital Area 1,2 + Mental 1,2,3 = 11 - the most maneuver-rich style",
    } },
  "tables" = { {
      "name" = "djcOA68Grid",
      "tag" = "OA68Data",
      "count" = "djcOA68StyleCount",
      "col_default" = 0,
      "cols" = { "djcOA68AtkNum", "djcOA68AtkDen", "djcOA68DmgDie", "djcOA68AC", "djcOA68Principal", "djcOA68ManeuverRanks" },
      "col_comments" = { "the Table 68 attacks numerators by style ordinal (print capture p. 224): the styles read 1 Karate, 2 Kung-fu, 3 Tae Kwon Do, 4 Jujutsu - the 3/1, 2/1, 1/1 and 2/1 rates of the four common styles", "the Table 68 attacks denominators by style ordinal (print capture p. 224): every common style a per-round rate, all four denominators the 1", "the Table 68 damage dice by style ordinal (print capture p. 224): Karate the d6, Kung-fu the d6, Tae Kwon Do the d8 - the only d8, Jujutsu the d6", "the Table 68 armor classes by style ordinal (print capture p. 224): Karate 8, Kung-fu 6 - the best, Tae Kwon Do 8, Jujutsu 7; the lower the better, Kung-fu the most protective style", "the Table 68 principal attack forms by style ordinal (print capture p. 224): 1 Hand, 2 Foot - Karate the Hand, Kung-fu the Hand, Tae Kwon Do the Foot - the only Foot style, Jujutsu the Hand", "the Table 68 special maneuver rank counts by style ordinal (print capture p. 224) - the number of listed maneuver ranks: Karate Strike 1,2,3 + Kick 1 + Movement 1 + Mental 1 = 6; Kung-fu Lock 1,2,3 + Strike 1,2 + Kick 2 + Movement 4 + Mental 5 = 8; Tae Kwon Do Kick 1,2,3 + Strike 1 + Throw 4 + Movement 5 = 6; Jujutsu Throw 1,2,3,4 + Movement 1,3 + Vital Area 1,2 + Mental 1,2,3 = 11 - the most maneuver-rich style" },
      "data" = { { 3, 1, 6, 8, 1, 6 }, { 2, 1, 6, 6, 1, 8 }, { 1, 1, 8, 8, 2, 6 }, { 2, 1, 6, 7, 1, 11 } },
      "comment" = "Table 68: the common martial styles - the four styles with their attack rates, damage dice, armor classes, principal attack forms and special maneuver rank counts (print capture pp. 224-225)",
      "audit_comment" = "the Table 68 grid - the four common styles across six columns",
    } },
  "chains" = {},
  "examples" = { {
      "expr" = "m['djcOA68StyleCount']() != 4  or  m['djcOA68AttacksStyleDependent']() != 1  or  m['djcOA68DamageDefensiveLow']() != 1  or  m['djcOA68ACFromTraining']() != 1  or  m['djcOA68PrincipalBodyPartFree']() != 1  or  m['djcOA68ManeuversSecrets']() != 1",
      "note" = "",
    }, {
      "expr" = "m['djcOA68AtkNum'](0) != 3  or m['djcOA68AtkNum'](1) != 2  or m['djcOA68AtkNum'](2) != 1  or m['djcOA68AtkNum'](3) != 2",
      "note" = "the attack rates - the 3/1, 2/1, 1/1 and 2/1 of the four styles",
    }, {
      "expr" = "m['djcOA68DmgDie'](0) != 6  or m['djcOA68DmgDie'](1) != 6  or m['djcOA68DmgDie'](2) != 8  or m['djcOA68DmgDie'](3) != 6",
      "note" = "the damage column - the d6, d6, d8 and d6",
    }, {
      "expr" = "m['djcOA68AC'](0) != 8  or m['djcOA68AC'](1) != 6  or m['djcOA68AC'](2) != 8  or m['djcOA68AC'](3) != 7",
      "note" = "the armor classes - the 8, 6, 8 and 7 with Kung-fu the best",
    }, {
      "expr" = "m['djcOA68Principal'](0) != 1  or m['djcOA68Principal'](2) != 2  or m['djcOA68Principal'](3) != 1",
      "note" = "the principal forms - Hand, Hand, Foot, Hand with Tae Kwon Do the only Foot",
    }, {
      "expr" = "m['djcOA68ManeuverRanks'](0) != 6  or m['djcOA68ManeuverRanks'](1) != 8  or m['djcOA68ManeuverRanks'](2) != 6  or m['djcOA68ManeuverRanks'](3) != 11",
      "note" = "the maneuver rank counts - the 6, 8, 6 and 11 with Jujutsu the richest",
    }, {
      "expr" = "m['djcOA68AtkNum'](1) !=m['djcOA68AtkDen'](1) * 2  or m['djcOA68ManeuverRanks'](1) !=m['djcOA68ManeuverRanks'](0) + 2",
      "note" = "the Kung-fu shape - the 2/1 rate with the best AC 6 and the second-rank maneuver load",
    } },
  "audit" = {
      "label" = "R689 OA common martial styles audit",
      "comment" = "OA round seventy-six (capture pp. 224-225): Table 68 - the common martial styles grid, the four styles across six columns with the explanatory prose, single-pass pins per the Chapter 9 provenance shift",
    },
}
