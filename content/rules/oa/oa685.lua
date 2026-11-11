-- oa685: promoted from rules/oa/oadisarming.h (the OA DISARMING, printed capture p. 221 - the disarm doctrine round);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 685,
  "prefix" = "oa685",
  "banner" = {
      "title" = "OA DISARMING, printed capture p. 221 - the disarm doctrine round",
      "provenance" = "census 607 -> 608.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift. THE DOCTRINE: at times characters must disarm an opponent - the charmed party member, the capture without harm. THE TWO METHODS: parrying the weapon out through superior weapon skill, or wresting it from the grasp with one's bare hands. THE WEAPON DISARM: a melee weapon of equal or greater size than the victim's, declared at the beginning of the round, a normal to hit roll doing no damage - the victim passing a saving throw versus petrification or losing the weapon, which falls 1d6 feet away, one round to recover. THE BARE HANDS: the UA weaponless combat system or the martial arts skills - which knock loose a weapon of any size, the victim at +2 on the save. THE TWO-HANDED RULE: one hand knocked loose per success, two successful attempts in the same round to disarm, otherwise the simple regrip at the end of the round. The prose codifies per the R431 calculus  the gap census after this round: 138 closed, 97 open - the Disarming box flips (census 607 -> 608); NEXT - R686: the Subduing Opponents doctrine (capture p. 221), prefix diz (verify free at the landing - diu, div, diw, dix and diy TAKEN by the R681-R685 call families), audit \"R686 OA subduing audit\", include after rules/oa/oadisarming.h",
    },
  "consts" = { {
      "name" = "diyOADisarmWeaponFallDice",
      "value" = 6,
      "comment" = "the disarm weapon fall - the disarmed weapon falling 1d6 feet away from the disarmed character (print capture p. 221)",
    }, {
      "name" = "diyOADisarmRecoverRounds",
      "value" = 1,
      "comment" = "the disarm recovery - one round needed to recover the fallen weapon (print capture p. 221)",
    }, {
      "name" = "diyOADisarmMartialArtsSaveBonus",
      "value" = 2,
      "comment" = "the martial-arts disarm save bonus - when using martial arts the character can attempt to knock loose a weapon of any size, the process the same as disarming with a weapon except the victim allowed a +2 to his saving throw (print capture p. 221)",
    }, {
      "name" = "diyOADisarmTwoHandedAttemptsNeeded",
      "value" = 2,
      "comment" = "the two-handed weapon disarm - a successful attempt against a two-handed weapon knocks loose only one hand, so two successful disarming attempts must be made in the same round to disarm; should only one succeed, the opponent simply regrips his weapon at the end of the round (print capture p. 221)",
    } },
  "bools" = { {
      "name" = "diyOADisarmDoctrine",
      "value" = true,
      "comment" = "the doctrine frame - at times characters find it necessary to disarm an opponent: a party member charmed into attacking his friends, or the wish to capture an opponent without being harmed greatly (print capture p. 221)",
    }, {
      "name" = "diyOADisarmTwoMethods",
      "value" = true,
      "comment" = "the two methods - disarming done by parrying the weapon out of the opponent's grasp through superior weapon skill or by wresting it from his grasp with one's bare hands (print capture p. 221)",
    }, {
      "name" = "diyOADisarmEqualOrGreaterSize",
      "value" = true,
      "comment" = "the size rule - to disarm with a weapon, the character must be using a melee weapon of equal or greater size than that of the victim (print capture p. 221)",
    }, {
      "name" = "diyOADisarmMustDeclare",
      "value" = true,
      "comment" = "the declaration rule - the character must declare at the beginning of the round that he is attempting to disarm (print capture p. 221)",
    }, {
      "name" = "diyOADisarmNoDamage",
      "value" = true,
      "comment" = "the no-damage attack - a normal to hit roll is made but the attack does no damage (print capture p. 221)",
    }, {
      "name" = "diyOADisarmSaveVersusPetrification",
      "value" = true,
      "comment" = "the disarm save - the victim must pass a saving throw versus petrification or have the weapon knocked from his grasp (print capture p. 221)",
    }, {
      "name" = "diyOADisarmBareHandsSystems",
      "value" = true,
      "comment" = "the bare-hands systems - to disarm with one's bare hands the character can use either the weaponless combat system explained in Unearthed Arcana or, if he has the proficiency, the martial arts skills explained later in these rules (print capture p. 221)",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['diyOADisarmWeaponFallDice']() != 6  or m['diyOADisarmRecoverRounds']() != 1  or m['diyOADisarmMartialArtsSaveBonus']() != 2  or m['diyOADisarmTwoHandedAttemptsNeeded']() != 2  or  m['diyOADisarmDoctrine']() != 1  or  m['diyOADisarmTwoMethods']() != 1  or  m['diyOADisarmEqualOrGreaterSize']() != 1  or  m['diyOADisarmMustDeclare']() != 1  or  m['diyOADisarmNoDamage']() != 1  or  m['diyOADisarmSaveVersusPetrification']() != 1  or  m['diyOADisarmBareHandsSystems']() != 1",
      "note" = "",
    }, {
      "expr" = "m['diyOADisarmWeaponFallDice']() != 6  or m['diyOADisarmRecoverRounds']() != 1",
      "note" = "the weapon-disarm pins - the 1d6 feet fall and the one-round recovery",
    }, {
      "expr" = "m['diyOADisarmMartialArtsSaveBonus']() != 2",
      "note" = "the martial-arts save bonus - the +2 on the victim save",
    }, {
      "expr" = "m['diyOADisarmTwoHandedAttemptsNeeded']() != 2",
      "note" = "the two-handed rule - the two same-round attempts needed",
    } },
  "audit" = {
      "label" = "R685 OA disarming audit",
      "comment" = "OA round seventy-two (capture p. 221): the Disarming doctrine - the two methods, the weapon disarm with the save versus petrification and the 1d6 fall, the bare-hands systems with the martial-arts any-size knock and the two-handed weapon rule, single-pass pins per the Chapter 9 provenance shift",
    },
}
