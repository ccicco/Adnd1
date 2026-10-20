// =========================================================================================
// Adnd1 - rules/oalearn.h
// OA LEARNING MARTIAL ARTS, printed capture pp. 233-235 - the masters, study
// and styles round
// census 617 -> 618.
//
// pinned from the 2018 print capture - the sole surviving pass per the R679
// provenance shift. THE MASTERS: the honorary title no character class - the
// brilliant, the skilled, the mediocre and the incompetent all called master;
// anyone anywhere - the peasant, the hermit, the traveling bushi, the
// professional teacher, the famous samurai, the temple priest; the scarcity -
// the select few, the unadvertised skill, the seclusion, the politics and the
// secret societies, the styles vanished with refusing masters; the schools of
// the towns and cities. THE ACCEPTANCE: the untrained character's 10% chance
// at the properly humble presentation; the courting - each gift-bearing visit
// +10%, until accepted or the master offended, the offense permanent; the
// skilled character's challenge, automatically accepted, the unknown
// challenger given a student; the subdue preferred over the death, the death
// no crime; the victor automatically accepted, the loser returning later or
// humbly begging. THE MASTER'S KNOWLEDGE: the basics automatic; the weapons
// and the maneuvers each rolled on the nearest die equal to or greater than
// their count; the maneuvers always from the lowest difficulty upward; the
// master fixed, never increasing without the DM's special circumstances. THE
// STUDY: the one-month minimum before the one slot buys the basics - the AC,
// the attacks, the damage, no maneuvers or weapons yet; then the travel and
// adventure with the one hour of daily practice and the six weekly master
// hours, the obligation unfulfilled blocking all additions; one slot per
// maneuver or weapon, no more than two slots per style per level, the strict
// difficulty order, the practice assumed; the outgrown master left for
// another. THE STYLES: more than one learned at a time - more than one
// master, the slots and the dedication; the fighting choice of a single
// style, its abilities alone, the constant maneuvers the exception; the
// change from round to round; the combining after all is learned - the unique
// style of mixed elements, the AC of one with the attacks and damage of
// another, every learned maneuver combined, the creator instructing others as
// a master. The grid mechanics codified per the R431 calculus
//
// the gap census after this round: 148 closed, 87 open - the Learning Martial
// Arts box flips (census 617 -> 618); NEXT - R696: the Chapter 10 Calendar
// prose (capture p. 236), prefix djj (verify free at the landing), audit
// "R696 OA calendar audit", include after rules/oalearn.h
//
namespace rules {

// ---- the masters and the acceptance ----

// the master title - an honorary title, not a character class; brilliant,
// skilled, mediocre and incompetent masters all exist, the title no measure
// of skill or level (print capture p. 233)
inline bool djiMasterHonoraryTitle()
    { return true; }

// the masters - anyone, anywhere: the peasant in the field, the hermit in the
// hills, the traveling bushi, the professional teacher, the famous samurai,
// the temple priest (print capture p. 233)
inline bool djiMasterAnywhere()
    { return true; }

// the master scarcity - the skills taught to a select few, often
// unadvertised, the seclusion preferred, the styles vanished with refusing
// masters, the politics and the secret societies (print capture p. 234)
inline bool djiMasterSecretive()
    { return true; }

// the acceptance chance - the untrained character presenting himself with the
// proper humble and respectful attitude has a 10% chance of being accepted
// outright (print capture p. 234)
inline int djiAcceptBasePct()
    { return 10; }

// the courting increment - each return visit bearing a small gift or offering
// that pleases the master increases the acceptance chance by 10% (print
// capture p. 234)
inline int djiAcceptGiftPct()
    { return 10; }

// the offended master - once offended he will never accept the character as
// his student, the courting ended (print capture p. 234)
inline bool djiOffendNeverAccepted()
    { return true; }

// the challenge route - the character with martial arts skill challenges the
// master, the challenge automatically accepted, a time and place arranged
// (print capture p. 234)
inline bool djiChallengeAutoAccepted()
    { return true; }

// the unknown challenger - a student automatically assigned when the
// character is not well-known for his skill, customary and no insult (print
// capture p. 234)
inline bool djiStudentIfUnknown()
    { return true; }

// the challenge forms - fought to subdue or to the death, the subdue
// preferred, the death no crime and the victor seldom punished (print capture
// p. 234)
inline bool djiChallengeSubduePreferred()
    { return true; }

// the won challenge - the master automatically accepts the victor as his
// student (print capture p. 234)
inline bool djiChallengeWinAccepted()
    { return true; }

// the lost challenge - leave and return later with more skill, or humbly beg
// acceptance, the entreaty effective after the humiliating ease (print
// capture p. 234)
inline bool djiChallengeLoseOptions()
    { return true; }

// ---- the master's knowledge ----

// the master's basics - he automatically knows the basics of the style, the
// Armor Class and the like (print capture p. 234)
inline bool djiMasterBasicsAuto()
    { return true; }

// the master's weapons - the number of weapons of the style counted, the
// nearest die equal to or greater rolled for his proficiencies (print capture
// p. 234)
inline bool djiMasterWeaponsDie()
    { return true; }

// the master's maneuvers - the special maneuvers totaled, the nearest die
// equal to or greater rolled, always known from the lowest difficulty upward
// (print capture p. 234)
inline bool djiMasterManeuversDie()
    { return true; }

// the master fixed - he never increases in knowledge unless the DM rules
// special circumstances (print capture p. 234)
inline bool djiMasterNeverIncreases()
    { return true; }

// ---- the study and the slot costs ----

// the study minimum - once accepted the character must remain and study under
// the master for at least one month (print capture p. 235)
inline int djiStudyMinMonths()
    { return 1; }

// the basics grant - one proficiency slot spent at the month's end gains the
// Armor Class, number of attacks and damage, no special maneuvers or weapons
// yet (print capture p. 235)
inline bool djiBasicsSlotGrant()
    { return true; }

// the daily practice - at least one hour a day of practicing the style once
// free to travel and adventure (print capture p. 235)
inline int djiPracticeHoursPerDay()
    { return 1; }

// the weekly master hours - six hours per week working with the master, the
// unfulfilled obligation blocking new special maneuvers and weapons (print
// capture p. 235)
inline int djiMasterHoursPerWeek()
    { return 6; }

// the obligation gate - characters not fulfilling the practice and master
// hours cannot add more special maneuvers and weapons (print capture p. 235)
inline bool djiObligationGate()
    { return true; }

// the maneuver slot cost - one proficiency slot expended per special maneuver
// or weapon added to the style (print capture p. 235)
inline int djiSlotsPerManeuver()
    { return 1; }

// the per-level cap - no more than two proficiency slots expended on a single
// martial arts style per level (print capture p. 235)
inline int djiMaxSlotsPerLevel()
    { return 2; }

// the added maneuver - assumes prior practice, no sudden knowledge; the
// maneuvers learned in strict difficulty order, all difficulty 1 before
// difficulty 2 (print capture p. 235)
inline bool djiManeuverPracticeAssumed()
    { return true; }

// the outgrown master - once the character has learned all the master knows,
// no point remains; off to another master of the same style or a different
// one (print capture p. 235)
inline bool djiLearnAllNewMaster()
    { return true; }

// ---- the multiple and combined styles ----

// the multiple styles - a player character can learn more than one style at a
// time, needing more than one master, available slots and dedication (print
// capture p. 235)
inline bool djiMultipleStylesAllowed()
    { return true; }

// the fighting choice - the character chooses which style he uses, gaining
// all abilities of that style and none of the others (print capture p. 235)
inline bool djiOneStylePerFight()
    { return true; }

// the constant exception - only the special maneuvers of the chosen style
// usable, unless constantly in effect (print capture p. 235)
inline bool djiConstantManeuversException()
    { return true; }

// the style switching - the character can change styles from melee round to
// melee round (print capture p. 235)
inline bool djiStyleChangePerRound()
    { return true; }

// the combining threshold - proficiency in two or more styles, all learned
// from those masters, before the unique style can be created (print capture
// p. 235)
inline int djiStylesKnownMin()
    { return 2; }

// the combined style - after learning all from two or more masters the
// character creates his own unique style, combining the elements as desired
// (print capture p. 235)
inline bool djiCombineUniqueStyle()
    { return true; }

// the element mixing - the Armor Class of one style with the number of
// attacks and damage of another, all learned maneuvers combined into the
// single new style (print capture p. 235)
inline bool djiCombineElements()
    { return true; }

// the new master - the creator of a unique style can instruct others as if he
// were a master (print capture p. 235)
inline bool djiCombineTeachAsMaster()
    { return true; }

}   // namespace rules
