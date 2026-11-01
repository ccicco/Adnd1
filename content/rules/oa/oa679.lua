-- oa679: promoted from rules/oacombatseq.h (the OA COMBAT SEQUENCE, printed capture p. 218 - the OA Chapter 9 Combat arc);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 679,
  "prefix" = "oa679",
  "banner" = {
      "title" = "OA COMBAT SEQUENCE, printed capture p. 218 - the OA Chapter 9 Combat arc",
      "provenance" = "opener, the Summary of the Combat Sequence round census 601 -> 602.  pinned from the 2018 print capture - THE SOLE SURVIVING PASS from Chapter 9 onward: the compressed-print capture ends mid ninth level spells, so the dual-capture cross-check of the wu jen spell rounds gives way here to single-pass pins, contested reads settling book-internal first, then against the physical copy (the gap report opener rule). The Summary of the Combat Sequence walks the five resolution steps: (1) surprise, normally 1-2 on 1d6, often impossible from visibility, surroundings or noise; (2) the players state their actions, announcing any subdue, disarm or unhorse attempt; (3) initiative on 1d6 only when there is no surprise, the higher roll gaining the round, kensai and wu jen able to modify their die roll; (4) kensai and wu jen with a higher modified roll than either side strike first, then the initiative side rolls 1d20 to hit against the combat table - equal or greater hits, certain characters stating ki power before the die is rolled - the spell targets then make their saving throws with shukenja stating ki before any save, and the damage dice add the four modifiers (strength, magical weapons, weapons of quality, ki powers), subdual damage recorded separately rather than subtracted; (5) the side that lost initiative now performs step 4. The prose codifies: the summary maps onto consts and bools per the R431 prose-to-code calculus, no printed grid needed  the gap census after this round: 132 closed, 103 open - the Summary of the Combat Sequence box flips (census 601 -> 602), the Chapter 9 Combat arc begun; NEXT - R680: the Surprise and Iaijutsu dueling draw doctrine (capture p. 218), prefix diq (verify free at the landing), audit \"R680 OA iaijutsu surprise audit\", include after rules/oacombatseq.h",
    },
  "consts" = { {
      "name" = "dipOACombatSequenceSteps",
      "value" = 5,
      "comment" = "the five steps of resolving a combat: (1) determine surprise, (2) players state the actions their characters attempt, (3) roll for initiative if there is no surprise, (4) the attacks and damage of the initiative side, (5) the side that lost the initiative performs step 4 (print capture p. 218)",
    }, {
      "name" = "dipOASurpriseDieSides",
      "value" = 6,
      "comment" = "the surprise die - characters are normally surprised on a roll of 1-2 on 1d6, the six-sided surprise die of the sequence step 1 (print capture p. 218)",
    }, {
      "name" = "dipOASurpriseRollMax",
      "value" = 2,
      "comment" = "the surprise roll ceiling - the 2 of the 1-2 on 1d6 surprise read, the top of the surprised band (print capture p. 218)",
    }, {
      "name" = "dipOAInitiativeDieSides",
      "value" = 6,
      "comment" = "the initiative die - 1d6 rolled per side when there is no surprise, the higher die roll gaining the initiative for the round, the sequence step 3 (print capture p. 218)",
    }, {
      "name" = "dipOAHitDieSides",
      "value" = 20,
      "comment" = "the to hit die - 1d20 rolled for each character on the initiative side attempting to hit, compared to the Armor Class of the target on the combat table, equal or greater hits, the sequence step 4 (print capture p. 218)",
    }, {
      "name" = "dipOADamageModifierCount",
      "value" = 4,
      "comment" = "the four damage modifiers of the sequence step 4 - strength, magical weapons, weapons of quality, and ki powers, added to the damage dice for each hit (print capture p. 218)",
    } },
  "bools" = { {
      "name" = "dipOASurpriseSometimesNil",
      "value" = true,
      "comment" = "the surprise impossibility clause - there are often cases where surprise is not possible due to visibility, surroundings, noise, etc., the sequence step 1 (print capture p. 218)",
    }, {
      "name" = "dipOAActionsStatedFirst",
      "value" = true,
      "comment" = "the declared-action rule of the sequence step 2 - players state the actions their characters are attempting before the round resolves (print capture p. 218)",
    }, {
      "name" = "dipOASubdueDisarmUnhorseAnnounced",
      "value" = true,
      "comment" = "the announcement requirement of the sequence step 2 - players must also announce if their characters are attempting to subdue, disarm, or unhorse an opponent (print capture p. 218)",
    }, {
      "name" = "dipOAInitiativeOnlyWithoutSurprise",
      "value" = true,
      "comment" = "the initiative gate of the sequence step 3 - the initiative die is rolled only if there is no surprise (print capture p. 218)",
    }, {
      "name" = "dipOAKensaiWuJenInitMods",
      "value" = true,
      "comment" = "the initiative modifiers of the sequence step 3 - kensai and wu jen characters are able to modify their initiative die roll (print capture p. 218)",
    }, {
      "name" = "dipOAKensaiWuJenFirstAttack",
      "value" = true,
      "comment" = "the first-strike rule of the sequence step 4 - kensai and wu jen characters with a higher modified initiative roll than either side make their attacks before the initiative side resolves (print capture p. 218)",
    }, {
      "name" = "dipOAKiStatedBeforeHitDie",
      "value" = true,
      "comment" = "the ki declaration rule of the sequence step 4 - certain characters must state whether they are using ki power before the die is rolled (print capture p. 218)",
    }, {
      "name" = "dipOAShukKiStatedBeforeSave",
      "value" = true,
      "comment" = "the shukenja ki rule of the sequence step 4 - shukenja must state whether they are using ki power before any saving throw is made, the save step following the to hit resolution for the targets of spells (print capture p. 218)",
    }, {
      "name" = "dipOASubdualRecordedSeparately",
      "value" = true,
      "comment" = "the subdual damage rule of the sequence step 4 - subdual damage is not subtracted from the opponent current hit points, but recorded separately (print capture p. 218)",
    }, {
      "name" = "dipOALoserSideRepeatsStepFour",
      "value" = true,
      "comment" = "the sequence step 5 - the side that lost the initiative now performs step 4, closing the five-step round (print capture p. 218)",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['dipOACombatSequenceSteps']() != 5  or m['dipOASurpriseDieSides']() != 6  or m['dipOASurpriseRollMax']() != 2  or m['dipOAInitiativeDieSides']() != 6  or m['dipOAHitDieSides']() != 20  or m['dipOADamageModifierCount']() != 4  or  m['dipOASurpriseSometimesNil']() != 1  or  m['dipOAActionsStatedFirst']() != 1  or  m['dipOASubdueDisarmUnhorseAnnounced']() != 1  or  m['dipOAInitiativeOnlyWithoutSurprise']() != 1  or  m['dipOAKensaiWuJenInitMods']() != 1  or  m['dipOAKensaiWuJenFirstAttack']() != 1  or  m['dipOAKiStatedBeforeHitDie']() != 1  or  m['dipOAShukKiStatedBeforeSave']() != 1  or  m['dipOASubdualRecordedSeparately']() != 1  or  m['dipOALoserSideRepeatsStepFour']() != 1",
      "note" = "",
    }, {
      "expr" = "m['dipOACombatSequenceSteps']() != 5  or m['dipOASurpriseDieSides']() != 6  or m['dipOASurpriseRollMax']() != 2  or m['dipOAInitiativeDieSides']() != 6  or m['dipOAHitDieSides']() != 20",
      "note" = "the sequence shape pins - five steps, the six-sided surprise and initiative dice, the 1-2 surprise band, the twenty-sided to hit die",
    }, {
      "expr" = "m['dipOADamageModifierCount']() != 4",
      "note" = "the damage modifier pins - the four damage modifiers added to the damage dice for each hit",
    }, {
      "expr" = "m['dipOASurpriseSometimesNil']() != 1  or m['dipOAActionsStatedFirst']() != 1  or m['dipOASubdueDisarmUnhorseAnnounced']() != 1",
      "note" = "the step 1 and 2 doctrine pins - surprise often impossible, actions stated first, the subdue/disarm/unhorse announcement",
    }, {
      "expr" = "m['dipOAInitiativeOnlyWithoutSurprise']() != 1  or m['dipOAKensaiWuJenInitMods']() != 1",
      "note" = "the step 3 doctrine pins - initiative only without surprise, the kensai and wu jen initiative modifiers",
    }, {
      "expr" = "m['dipOAKensaiWuJenFirstAttack']() != 1  or m['dipOAKiStatedBeforeHitDie']() != 1  or m['dipOAShukKiStatedBeforeSave']() != 1  or m['dipOASubdualRecordedSeparately']() != 1",
      "note" = "the step 4 doctrine pins - the kensai/wu jen first-strike, the ki declarations before the hit die and before the saves, the separate subdual record",
    }, {
      "expr" = "m['dipOALoserSideRepeatsStepFour']() != 1",
      "note" = "the step 5 pin - the initiative loser then performs step 4, closing the five-step round",
    }, {
      "expr" = "m['dipOASurpriseDieSides']() !=m['dipOAInitiativeDieSides']()  or m['dipOAHitDieSides']() != 20  or m['dipOASurpriseRollMax']() >m['dipOASurpriseDieSides']()",
      "note" = "the die pins read together - the 1d6 surprise read of the 1-2 band, the 1d6 initiative, the 1d20 to hit",
    } },
  "audit" = {
      "label" = "R679 OA combat sequence audit",
      "comment" = "OA round sixty-six (capture p. 218): the Summary of the Combat Sequence - the five resolution steps with the surprise, initiative, to hit and damage doctrine pins, the first round of the Chapter 9 Combat arc and the first single-pass round - the compressed capture ends mid ninth level spells",
    },
}
