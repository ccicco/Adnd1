-- oa681: promoted from rules/oa/oainitmods.h (the OA INITIATIVE MODIFIERS, printed capture pp. 218-219 - the quickness);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 681,
  "prefix" = "oa681",
  "banner" = {
      "title" = "OA INITIATIVE MODIFIERS, printed capture pp. 218-219 - the quickness",
      "provenance" = "doctrine round census 603 -> 604.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift. The doctrine frame: Oriental Adventures characters live and rely on their quickness and speed, some developing improved chances of striking the crucial first blow. THE CHARACTER-ONLY CLAUSE: when modifiers apply to only some of the characters involved, the initiative roll is still made only once for each side; those with modifiers apply their modifier to the die roll for their side BUT for the actions of that character only - the round may thus divide into more than two phases of attacks. THE TIE RULES: a tie (modified or unmodified) is not rerolled - all act in the same instant, and damage or spell effects are not applied to a same-initiative character until he has completed his action, the normal results then landing. THE PRINTED EXAMPLE: the 1st-level kensai, samurai and shukenja party rolls the 3, the hostile samurai the 4 - the kensai (modified 4) strikes in the same instant as the NPCs, then the remaining player characters; a hypothetical NPC kensai (modified 5) would strike first, then the simultaneous remaining NPCs and the PC kensai, then the survivors. THE LANDSLIDE RULE: when one side beats even the highest modified initiative of the other, the winning side completes all attacks in whatever order desired before the other side begins. The prose codifies per the R431 calculus  the gap census after this round: 134 closed, 101 open - the Initiative Modifiers box flips (census 603 -> 604); NEXT - R682: the Combat Procedures with the missile fire from horseback doctrine (capture p. 219), prefix div (verify free at the landing - dis and dit are TAKEN, the disease and ditch call families), audit \"R682 OA combat procedures audit\", include after rules/oa/oainitmods.h",
    },
  "consts" = { {
      "name" = "diuOAInitiativeRollsPerRound",
      "value" = 2,
      "comment" = "the initiative roll is made only once for each side - the two rolls of the round, one per side, even when modifiers apply to only some of the characters involved (print capture pp. 218-219)",
    }, {
      "name" = "diuOAExamplePCSideRoll",
      "value" = 3,
      "comment" = "the printed example PC side roll - the kensai, samurai and shukenja party, all 1st level, rolling the 3 against the hostile samurai group (print capture pp. 218-219)",
    }, {
      "name" = "diuOAExampleNPCSideRoll",
      "value" = 4,
      "comment" = "the printed example NPC side roll - the hostile samurai group rolling the 4, winning the round against the PC 3 (print capture pp. 218-219)",
    }, {
      "name" = "diuOAExampleKensaiModified",
      "value" = 4,
      "comment" = "the printed example kensai modified initiative - the 4, carrying him into the same instant as the winning NPC side, the kensai and the NPCs striking first together (print capture pp. 218-219)",
    }, {
      "name" = "diuOAExampleNpcKensaiModified",
      "value" = 5,
      "comment" = "the printed example hypothetical NPC kensai modified initiative - the 5, striking first ahead of everyone, followed by the simultaneous remaining NPCs and the PC kensai, then the surviving player characters (print capture pp. 218-219)",
    } },
  "bools" = { {
      "name" = "diuOAQuicknessDoctrine",
      "value" = true,
      "comment" = "the doctrine frame - characters in the Oriental Adventures world live and rely on their quickness and speed, some having developed their speed to the point of improved chances of striking the crucial first blow (print capture pp. 218-219)",
    }, {
      "name" = "diuOAInitiativeOncePerSide",
      "value" = true,
      "comment" = "the once-per-side rule - when modifiers to the initiative apply to only some of the characters involved, the initiative roll is still made only once for each side (print capture pp. 218-219)",
    }, {
      "name" = "diuOAModifierCharacterOnly",
      "value" = true,
      "comment" = "the character-only clause - those characters with modifiers apply their modifier to the die roll for their side BUT for the actions of that character only (print capture pp. 218-219)",
    }, {
      "name" = "diuOAPhasesExceedTwo",
      "value" = true,
      "comment" = "the phase division - thus the actions of an initiative round may be divided into more than two phases of attacks (print capture pp. 218-219)",
    }, {
      "name" = "diuOATieNotRerolled",
      "value" = true,
      "comment" = "the tie rule - when the initiative (modified or unmodified) results in a tie, the die is not rerolled (print capture pp. 218-219)",
    }, {
      "name" = "diuOATieSimultaneous",
      "value" = true,
      "comment" = "the tie simultaneity - all characters or creatures are assumed to be acting in the same instant (print capture pp. 218-219)",
    }, {
      "name" = "diuOATieEffectsAfterAction",
      "value" = true,
      "comment" = "the tie resolution - damage done or the effects of spells are not applied to a character with the same initiative until he has completed his action; as soon as he has finished, he suffers the normal results of actions against him (print capture pp. 218-219)",
    }, {
      "name" = "diuOAWinnerOrderUnimportant",
      "value" = true,
      "comment" = "the landslide rule - when the initiative of one side is greater than even the highest modified initiative of the other side, all characters on the winning side complete their attacks in whatever order is desired, their actions completed before those of the other side begin (print capture pp. 218-219)",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['diuOAInitiativeRollsPerRound']() != 2  or m['diuOAExamplePCSideRoll']() != 3  or m['diuOAExampleNPCSideRoll']() != 4  or m['diuOAExampleKensaiModified']() != 4  or m['diuOAExampleNpcKensaiModified']() != 5  or  m['diuOAQuicknessDoctrine']() != 1  or  m['diuOAInitiativeOncePerSide']() != 1  or  m['diuOAModifierCharacterOnly']() != 1  or  m['diuOAPhasesExceedTwo']() != 1  or  m['diuOATieNotRerolled']() != 1  or  m['diuOATieSimultaneous']() != 1  or  m['diuOATieEffectsAfterAction']() != 1  or  m['diuOAWinnerOrderUnimportant']() != 1",
      "note" = "",
    }, {
      "expr" = "m['diuOAInitiativeRollsPerRound']() != 2",
      "note" = "the roll pins - the two side rolls of the round, once per side even with partial modifiers",
    }, {
      "expr" = "m['diuOAExamplePCSideRoll']() != 3  or m['diuOAExampleNPCSideRoll']() != 4",
      "note" = "the side rolls of the printed example - the PC 3, the NPC 4",
    }, {
      "expr" = "m['diuOAExampleKensaiModified']() != 4  or m['diuOAExampleNpcKensaiModified']() != 5",
      "note" = "the modified rolls of the printed example - the kensai 4, the NPC kensai 5",
    }, {
      "expr" = "m['diuOAExampleKensaiModified']() !=m['diuOAExampleNPCSideRoll']()",
      "note" = "the example shape - the kensai modified riding the same instant as the NPC side roll",
    }, {
      "expr" = "m['diuOAExampleNpcKensaiModified']() !=m['diuOAExampleNPCSideRoll']() + 1",
      "note" = "the example shape - the hypothetical NPC kensai one higher still",
    }, {
      "expr" = "m['diuOAInitiativeOncePerSide']() != 1  or m['diuOAModifierCharacterOnly']() != 1  or m['diuOAPhasesExceedTwo']() != 1  or m['diuOAQuicknessDoctrine']() != 1",
      "note" = "the modifier doctrine pins - once per side, the character-only application, the phase division beyond two",
    }, {
      "expr" = "m['diuOATieNotRerolled']() != 1  or m['diuOATieSimultaneous']() != 1  or m['diuOATieEffectsAfterAction']() != 1",
      "note" = "the tie doctrine pins - no reroll, the same instant, the effects landing only after the character completes his action",
    }, {
      "expr" = "m['diuOAWinnerOrderUnimportant']() != 1",
      "note" = "the landslide pin - the winning side above even the highest modified initiative acting in any order, all actions completing before the other side begins",
    } },
  "audit" = {
      "label" = "R681 OA initiative modifiers audit",
      "comment" = "OA round sixty-eight (capture pp. 218-219): the Initiative Modifiers doctrine - the quickness frame, the character-only modifier clause with the phase division, the tie rules and the printed kensai example, single-pass pins per the Chapter 9 provenance shift",
    },
}
