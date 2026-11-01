-- oa687: promoted from rules/oapsychicduel.h (the OA THE PSYCHIC DUEL, printed capture pp. 222-223 - the wills contest round);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 687,
  "prefix" = "oa687",
  "banner" = {
      "title" = "OA THE PSYCHIC DUEL, printed capture pp. 222-223 - the wills contest round",
      "provenance" = "census 609 -> 610.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift. THE FRAME: the psychic duel a type of mental combat practiced by any character race or class, requiring no psionic talent - the test of the wills, the invisible fight revealed by the grimace, the eyelid, the tic; the wise man admitting defeat before it occurs. THE CIRCUMSTANCES: only on or by intelligent human or humanoid creatures, strictly one-on-one - never between friends (3 points of honor), never with crossed weapons, never under outside attack: the pre-battle challenge or the swaggering bully. THE RESOLUTION: the round spent within 10 feet concentrating the will, each saving throw vs. death - the kensai +2 against non-kensai; one makes one wins, both fail inconclusive, both make locked for another round; the breaker the loser, his nerve broken. THE HONOR: 2 points beating a higher level, 1 the equal, none the lower. THE LOSER: retreat losing the equal honor, or attack at -1 on initiative, to hit and saves throughout, no surprise - both sides prepared. The prose codifies per the R431 calculus  the gap census after this round: 140 closed, 95 open - the Psychic Duel box flips (census 609 -> 610); NEXT - R688: the Martial Arts doctrine opener (capture pp. 223-224), prefix djb (verify free at the landing), audit \"R688 OA martial arts opener audit\", include after rules/oapsychicduel.h",
    },
  "consts" = { {
      "name" = "djaOAPsychicDuelRangeFeet",
      "value" = 10,
      "comment" = "the psychic duel range - the characters spend the round within 10 feet of each other, concentrating their will (print capture p. 222)",
    }, {
      "name" = "djaOAPsychicDuelKensaiBonus",
      "value" = 2,
      "comment" = "the kensai duel bonus - kensai characters have a bonus of +2 to the saving throw vs. death roll when facing non-kensai characters (print capture p. 222)",
    }, {
      "name" = "djaOAPsychicDuelFriendsHonor",
      "value" = 3,
      "comment" = "the friends dishonor - the duel never used between friends or companions, such an action being highly insulting and dishonorable for both, 3 points of honor (print capture p. 222)",
    }, {
      "name" = "djaOAPsychicDuelHigherLevelHonor",
      "value" = 2,
      "comment" = "the higher-level honor award - the winner of a psychic duel gains 2 points of honor if his opponent is of a higher experience level than himself (print capture p. 223)",
    }, {
      "name" = "djaOAPsychicDuelEqualLevelHonor",
      "value" = 1,
      "comment" = "the equal-level honor award - if the two are equal level, the winner gains 1 point of honor (print capture p. 223)",
    }, {
      "name" = "djaOAPsychicDuelLoserAttackPenalty",
      "value" = -1,
      "comment" = "the loser attack penalty - if the loser attacks regardless of the outcome, he is -1 on his initiative, to hit, and saving throw rolls throughout the ensuing battle (print capture p. 223)",
    } },
  "bools" = { {
      "name" = "djaOAPsychicDuelDoctrine",
      "value" = true,
      "comment" = "the doctrine frame - the psychic duel a type of mental combat practiced by any character race or class, requiring no psionic talent, a test of the wills of the duelists - their courage, skill and determination, the invisible fight revealed by a faint grimace, the flicker of an eyelid, or the tic of a muscle (print capture p. 222)",
    }, {
      "name" = "djaOAPsychicDuelAnyoneMayTry",
      "value" = true,
      "comment" = "the anyone clause - although the psychic duel can be attempted by anyone, it can only be done under special circumstances (print capture p. 222)",
    }, {
      "name" = "djaOAPsychicDuelHumanOnly",
      "value" = true,
      "comment" = "the human-or-humanoid gate - it can only be used on or by intelligent creatures of human or humanoid races (print capture p. 222)",
    }, {
      "name" = "djaOAPsychicDuelOneOnOne",
      "value" = true,
      "comment" = "the one-on-one rule - it is strictly a one-on-one duel, a single character facing off against another (print capture p. 222)",
    }, {
      "name" = "djaOAPsychicDuelNeverFriends",
      "value" = true,
      "comment" = "the friends exclusion - it is never used between friends or companions, such an action being highly insulting and dishonorable for both (print capture p. 222)",
    }, {
      "name" = "djaOAPsychicDuelNoCrossedWeapons",
      "value" = true,
      "comment" = "the crossed-weapons exclusion - the characters cannot have crossed weapons before during the encounter (print capture p. 222)",
    }, {
      "name" = "djaOAPsychicDuelNoOutsideAttacks",
      "value" = true,
      "comment" = "the outside-attack exclusion - neither can it be used if they are attacked by others during the course of the psychic duel, not in the heat of a furious battle but in a challenge before the battle, or on a swaggering bully in the street (print capture p. 222)",
    }, {
      "name" = "djaOAPsychicDuelSaveVersusDeath",
      "value" = true,
      "comment" = "the resolution roll - each character rolls a saving throw vs. death (print capture p. 222)",
    }, {
      "name" = "djaOAPsychicDuelOneMakesOneWins",
      "value" = true,
      "comment" = "the split outcome - if one character makes a successful saving throw and the other does not, the successful character has won the duel (print capture p. 222)",
    }, {
      "name" = "djaOAPsychicDuelBothFailInconclusive",
      "value" = true,
      "comment" = "the inconclusive outcome - if both characters fail the saving throw, the duel is inconclusive and neither wins (print capture p. 222)",
    }, {
      "name" = "djaOAPsychicDuelBothMakeContinue",
      "value" = true,
      "comment" = "the continuation outcome - if both characters make the saving throw, they are locked in the mental battle and the duel continues for another round (print capture p. 222)",
    }, {
      "name" = "djaOAPsychicDuelBreakerLoses",
      "value" = true,
      "comment" = "the nerve-break rule - should one player break off the duel and attack before it is resolved, he is the loser, his nerve has broken (print capture p. 222)",
    }, {
      "name" = "djaOAPsychicDuelLoserRetreat",
      "value" = true,
      "comment" = "the loser retreat option - the loser may retreat, losing points of honor equal to those gained by the victor (print capture p. 223)",
    }, {
      "name" = "djaOAPsychicDuelLoserMayAttack",
      "value" = true,
      "comment" = "the loser attack option - the loser can attack regardless of the outcome of the psychic duel (print capture p. 223)",
    }, {
      "name" = "djaOAPsychicDuelNoSurprise",
      "value" = true,
      "comment" = "the no-surprise rule - no surprise roll is made after the duel, since both sides are prepared (print capture p. 223)",
    }, {
      "name" = "djaOAPsychicDuelLowerLevelNoHonor",
      "value" = true,
      "comment" = "the lower-level rule - if the loser is of lower level, the winner gains no honor for the duel (print capture p. 223)",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['djaOAPsychicDuelRangeFeet']() != 10  or m['djaOAPsychicDuelKensaiBonus']() != 2  or m['djaOAPsychicDuelFriendsHonor']() != 3  or m['djaOAPsychicDuelHigherLevelHonor']() != 2  or m['djaOAPsychicDuelEqualLevelHonor']() != 1  or m['djaOAPsychicDuelLoserAttackPenalty']() != -1  or  m['djaOAPsychicDuelDoctrine']() != 1  or  m['djaOAPsychicDuelAnyoneMayTry']() != 1  or  m['djaOAPsychicDuelHumanOnly']() != 1  or  m['djaOAPsychicDuelOneOnOne']() != 1  or  m['djaOAPsychicDuelNeverFriends']() != 1  or  m['djaOAPsychicDuelNoCrossedWeapons']() != 1  or  m['djaOAPsychicDuelNoOutsideAttacks']() != 1  or  m['djaOAPsychicDuelSaveVersusDeath']() != 1  or  m['djaOAPsychicDuelOneMakesOneWins']() != 1  or  m['djaOAPsychicDuelBothFailInconclusive']() != 1  or  m['djaOAPsychicDuelBothMakeContinue']() != 1  or  m['djaOAPsychicDuelBreakerLoses']() != 1  or  m['djaOAPsychicDuelLoserRetreat']() != 1  or  m['djaOAPsychicDuelLoserMayAttack']() != 1  or  m['djaOAPsychicDuelNoSurprise']() != 1  or  m['djaOAPsychicDuelLowerLevelNoHonor']() != 1",
      "note" = "",
    }, {
      "expr" = "m['djaOAPsychicDuelRangeFeet']() != 10  or m['djaOAPsychicDuelKensaiBonus']() != 2",
      "note" = "the duel mechanics - the 10 feet and the kensai +2 against non-kensai",
    }, {
      "expr" = "m['djaOAPsychicDuelHigherLevelHonor']() != 2  or m['djaOAPsychicDuelEqualLevelHonor']() != 1",
      "note" = "the honor awards - the 2 for the higher, the 1 for the equal",
    }, {
      "expr" = "m['djaOAPsychicDuelFriendsHonor']() != 3",
      "note" = "the friends dishonor - the 3 points of honor",
    }, {
      "expr" = "m['djaOAPsychicDuelLoserAttackPenalty']() != -1",
      "note" = "the loser attack penalty - the -1 throughout the battle",
    } },
  "audit" = {
      "label" = "R687 OA psychic duel audit",
      "comment" = "OA round seventy-four (capture pp. 222-223): The Psychic Duel - the mental combat of the wills with the save-versus-death resolution, the kensai bonus, the three outcomes, the honor awards and the loser options, single-pass pins per the Chapter 9 provenance shift",
    },
}
