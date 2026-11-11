-- oa695: promoted from rules/oa/oalearn.h (the OA LEARNING MARTIAL ARTS, printed capture pp. 233-235 - the masters, study);
-- DO NOT hand-edit; the pin header stays the adjudicated record.
return {
  "round" = 695,
  "prefix" = "oa695",
  "banner" = {
      "title" = "OA LEARNING MARTIAL ARTS, printed capture pp. 233-235 - the masters, study",
      "provenance" = "and styles round census 617 -> 618.  pinned from the 2018 print capture - the sole surviving pass per the R679 provenance shift. THE MASTERS: the honorary title no character class - the brilliant, the skilled, the mediocre and the incompetent all called master; anyone anywhere - the peasant, the hermit, the traveling bushi, the professional teacher, the famous samurai, the temple priest; the scarcity - the select few, the unadvertised skill, the seclusion, the politics and the secret societies, the styles vanished with refusing masters; the schools of the towns and cities. THE ACCEPTANCE: the untrained character's 10% chance at the properly humble presentation; the courting - each gift-bearing visit +10%, until accepted or the master offended, the offense permanent; the skilled character's challenge, automatically accepted, the unknown challenger given a student; the subdue preferred over the death, the death no crime; the victor automatically accepted, the loser returning later or humbly begging. THE MASTER'S KNOWLEDGE: the basics automatic; the weapons and the maneuvers each rolled on the nearest die equal to or greater than their count; the maneuvers always from the lowest difficulty upward; the master fixed, never increasing without the DM's special circumstances. THE STUDY: the one-month minimum before the one slot buys the basics - the AC, the attacks, the damage, no maneuvers or weapons yet; then the travel and adventure with the one hour of daily practice and the six weekly master hours, the obligation unfulfilled blocking all additions; one slot per maneuver or weapon, no more than two slots per style per level, the strict difficulty order, the practice assumed; the outgrown master left for another. THE STYLES: more than one learned at a time - more than one master, the slots and the dedication; the fighting choice of a single style, its abilities alone, the constant maneuvers the exception; the change from round to round; the combining after all is learned - the unique style of mixed elements, the AC of one with the attacks and damage of another, every learned maneuver combined, the creator instructing others as a master. The grid mechanics codified per the R431 calculus  the gap census after this round: 148 closed, 87 open - the Learning Martial Arts box flips (census 617 -> 618); NEXT - R696: the Chapter 10 Calendar prose (capture p. 236), prefix djj (verify free at the landing), audit \"R696 OA calendar audit\", include after rules/oa/oalearn.h",
    },
  "consts" = { {
      "name" = "djiAcceptBasePct",
      "value" = 10,
      "comment" = "the acceptance chance - the untrained character presenting himself with the proper humble and respectful attitude has a 10% chance of being accepted outright (print capture p. 234)",
    }, {
      "name" = "djiAcceptGiftPct",
      "value" = 10,
      "comment" = "the courting increment - each return visit bearing a small gift or offering that pleases the master increases the acceptance chance by 10% (print capture p. 234)",
    }, {
      "name" = "djiStudyMinMonths",
      "value" = 1,
      "comment" = "the study minimum - once accepted the character must remain and study under the master for at least one month (print capture p. 235)",
    }, {
      "name" = "djiPracticeHoursPerDay",
      "value" = 1,
      "comment" = "the daily practice - at least one hour a day of practicing the style once free to travel and adventure (print capture p. 235)",
    }, {
      "name" = "djiMasterHoursPerWeek",
      "value" = 6,
      "comment" = "the weekly master hours - six hours per week working with the master, the unfulfilled obligation blocking new special maneuvers and weapons (print capture p. 235)",
    }, {
      "name" = "djiSlotsPerManeuver",
      "value" = 1,
      "comment" = "the maneuver slot cost - one proficiency slot expended per special maneuver or weapon added to the style (print capture p. 235)",
    }, {
      "name" = "djiMaxSlotsPerLevel",
      "value" = 2,
      "comment" = "the per-level cap - no more than two proficiency slots expended on a single martial arts style per level (print capture p. 235)",
    }, {
      "name" = "djiStylesKnownMin",
      "value" = 2,
      "comment" = "the combining threshold - proficiency in two or more styles, all learned from those masters, before the unique style can be created (print capture p. 235)",
    } },
  "bools" = { {
      "name" = "djiMasterHonoraryTitle",
      "value" = true,
      "comment" = "the master title - an honorary title, not a character class; brilliant, skilled, mediocre and incompetent masters all exist, the title no measure of skill or level (print capture p. 233)",
    }, {
      "name" = "djiMasterAnywhere",
      "value" = true,
      "comment" = "the masters - anyone, anywhere: the peasant in the field, the hermit in the hills, the traveling bushi, the professional teacher, the famous samurai, the temple priest (print capture p. 233)",
    }, {
      "name" = "djiMasterSecretive",
      "value" = true,
      "comment" = "the master scarcity - the skills taught to a select few, often unadvertised, the seclusion preferred, the styles vanished with refusing masters, the politics and the secret societies (print capture p. 234)",
    }, {
      "name" = "djiOffendNeverAccepted",
      "value" = true,
      "comment" = "the offended master - once offended he will never accept the character as his student, the courting ended (print capture p. 234)",
    }, {
      "name" = "djiChallengeAutoAccepted",
      "value" = true,
      "comment" = "the challenge route - the character with martial arts skill challenges the master, the challenge automatically accepted, a time and place arranged (print capture p. 234)",
    }, {
      "name" = "djiStudentIfUnknown",
      "value" = true,
      "comment" = "the unknown challenger - a student automatically assigned when the character is not well-known for his skill, customary and no insult (print capture p. 234)",
    }, {
      "name" = "djiChallengeSubduePreferred",
      "value" = true,
      "comment" = "the challenge forms - fought to subdue or to the death, the subdue preferred, the death no crime and the victor seldom punished (print capture p. 234)",
    }, {
      "name" = "djiChallengeWinAccepted",
      "value" = true,
      "comment" = "the won challenge - the master automatically accepts the victor as his student (print capture p. 234)",
    }, {
      "name" = "djiChallengeLoseOptions",
      "value" = true,
      "comment" = "the lost challenge - leave and return later with more skill, or humbly beg acceptance, the entreaty effective after the humiliating ease (print capture p. 234)",
    }, {
      "name" = "djiMasterBasicsAuto",
      "value" = true,
      "comment" = "the master's basics - he automatically knows the basics of the style, the Armor Class and the like (print capture p. 234)",
    }, {
      "name" = "djiMasterWeaponsDie",
      "value" = true,
      "comment" = "the master's weapons - the number of weapons of the style counted, the nearest die equal to or greater rolled for his proficiencies (print capture p. 234)",
    }, {
      "name" = "djiMasterManeuversDie",
      "value" = true,
      "comment" = "the master's maneuvers - the special maneuvers totaled, the nearest die equal to or greater rolled, always known from the lowest difficulty upward (print capture p. 234)",
    }, {
      "name" = "djiMasterNeverIncreases",
      "value" = true,
      "comment" = "the master fixed - he never increases in knowledge unless the DM rules special circumstances (print capture p. 234)",
    }, {
      "name" = "djiBasicsSlotGrant",
      "value" = true,
      "comment" = "the basics grant - one proficiency slot spent at the month's end gains the Armor Class, number of attacks and damage, no special maneuvers or weapons yet (print capture p. 235)",
    }, {
      "name" = "djiObligationGate",
      "value" = true,
      "comment" = "the obligation gate - characters not fulfilling the practice and master hours cannot add more special maneuvers and weapons (print capture p. 235)",
    }, {
      "name" = "djiManeuverPracticeAssumed",
      "value" = true,
      "comment" = "the added maneuver - assumes prior practice, no sudden knowledge; the maneuvers learned in strict difficulty order, all difficulty 1 before difficulty 2 (print capture p. 235)",
    }, {
      "name" = "djiLearnAllNewMaster",
      "value" = true,
      "comment" = "the outgrown master - once the character has learned all the master knows, no point remains; off to another master of the same style or a different one (print capture p. 235)",
    }, {
      "name" = "djiMultipleStylesAllowed",
      "value" = true,
      "comment" = "the multiple styles - a player character can learn more than one style at a time, needing more than one master, available slots and dedication (print capture p. 235)",
    }, {
      "name" = "djiOneStylePerFight",
      "value" = true,
      "comment" = "the fighting choice - the character chooses which style he uses, gaining all abilities of that style and none of the others (print capture p. 235)",
    }, {
      "name" = "djiConstantManeuversException",
      "value" = true,
      "comment" = "the constant exception - only the special maneuvers of the chosen style usable, unless constantly in effect (print capture p. 235)",
    }, {
      "name" = "djiStyleChangePerRound",
      "value" = true,
      "comment" = "the style switching - the character can change styles from melee round to melee round (print capture p. 235)",
    }, {
      "name" = "djiCombineUniqueStyle",
      "value" = true,
      "comment" = "the combined style - after learning all from two or more masters the character creates his own unique style, combining the elements as desired (print capture p. 235)",
    }, {
      "name" = "djiCombineElements",
      "value" = true,
      "comment" = "the element mixing - the Armor Class of one style with the number of attacks and damage of another, all learned maneuvers combined into the single new style (print capture p. 235)",
    }, {
      "name" = "djiCombineTeachAsMaster",
      "value" = true,
      "comment" = "the new master - the creator of a unique style can instruct others as if he were a master (print capture p. 235)",
    } },
  "switches" = {},
  "tables" = {},
  "chains" = {},
  "examples" = { {
      "expr" = "m['djiAcceptBasePct']() != 10  or m['djiAcceptGiftPct']() != 10  or m['djiStudyMinMonths']() != 1  or m['djiPracticeHoursPerDay']() != 1  or m['djiMasterHoursPerWeek']() != 6  or m['djiSlotsPerManeuver']() != 1  or m['djiMaxSlotsPerLevel']() != 2  or m['djiStylesKnownMin']() != 2  or  m['djiMasterHonoraryTitle']() != 1  or  m['djiMasterAnywhere']() != 1  or  m['djiMasterSecretive']() != 1  or  m['djiOffendNeverAccepted']() != 1  or  m['djiChallengeAutoAccepted']() != 1  or  m['djiStudentIfUnknown']() != 1  or  m['djiChallengeSubduePreferred']() != 1  or  m['djiChallengeWinAccepted']() != 1  or  m['djiChallengeLoseOptions']() != 1  or  m['djiMasterBasicsAuto']() != 1  or  m['djiMasterWeaponsDie']() != 1  or  m['djiMasterManeuversDie']() != 1  or  m['djiMasterNeverIncreases']() != 1  or  m['djiBasicsSlotGrant']() != 1  or  m['djiObligationGate']() != 1  or  m['djiManeuverPracticeAssumed']() != 1  or  m['djiLearnAllNewMaster']() != 1  or  m['djiMultipleStylesAllowed']() != 1  or  m['djiOneStylePerFight']() != 1  or  m['djiConstantManeuversException']() != 1  or  m['djiStyleChangePerRound']() != 1  or  m['djiCombineUniqueStyle']() != 1  or  m['djiCombineElements']() != 1  or  m['djiCombineTeachAsMaster']() != 1",
      "note" = "",
    }, {
      "expr" = "m['djiAcceptBasePct']() != 10  or m['djiAcceptGiftPct']() != 10",
      "note" = "the acceptance percentages - the 10 base and the 10 per gift",
    }, {
      "expr" = "m['djiStudyMinMonths']() != 1  or m['djiPracticeHoursPerDay']() != 1  or m['djiMasterHoursPerWeek']() != 6",
      "note" = "the study obligations - one month, one hour a day, six hours a week",
    }, {
      "expr" = "m['djiSlotsPerManeuver']() != 1  or m['djiMaxSlotsPerLevel']() != 2",
      "note" = "the slot costs - one per maneuver, two per style per level the cap",
    }, {
      "expr" = "m['djiStylesKnownMin']() != 2",
      "note" = "the combining threshold - two or more styles",
    } },
  "audit" = {
      "label" = "R695 OA learning martial arts audit",
      "comment" = "OA round eighty-two (capture pp. 233-235): the Learning Martial Arts prose - the master search, the acceptance and challenge routes, the study obligations and proficiency slot costs - with the Multiple Styles and Combining Styles rules, single-pass pins per the Chapter 9 provenance shift",
    },
}
